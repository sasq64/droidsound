package com.ssb.droidsound.service;

import java.io.File;
import java.util.HashSet;
import java.util.Set;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.media.AudioManager;
import android.net.Uri;
import android.os.Binder;
import android.os.Bundle;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.telephony.PhoneStateListener;
import android.telephony.TelephonyManager;

import com.ssb.droidsound.PlayerActivity;
import com.ssb.droidsound.Playlist;
import com.ssb.droidsound.R;
import com.ssb.droidsound.SongFile;
import com.ssb.droidsound.service.Player.SongInfo;
import com.ssb.droidsound.utils.Log;

public class PlayerService extends Service {
	private static final String TAG = PlayerService.class.getSimpleName();

	public interface IPlayerServiceCallback {
		void setInitialConfig();
		void stringChanged(int what, String string);
		void intChanged(int what, int value);
	}

	public static final int SONG_TITLE = 1;
	public static final int SONG_AUTHOR = 2;
	public static final int SONG_COPYRIGHT = 3;
	public static final int SONG_FORMAT = 5;

	public static final int SONG_POS = 6;
	public static final int SONG_FILENAME = 7;
	public static final int SONG_LENGTH = 8;
	public static final int SONG_SUBSONG = 9;
	public static final int SONG_TOTALSONGS = 10;

	public static final int SONG_STATE = 11;

	public static final int SONG_DETAILS = 12;
	public static final int SONG_REPEAT = 13;

	public static final int SONG_SUBTUNE_TITLE = 14;
	public static final int SONG_SUBTUNE_AUTHOR = 15;
	public static final int SONG_PLAYLIST = 16;
	public static final int SONG_FLAGS = 17;
	public static final int SONG_SOURCE = 18;
	public static final int SONG_BUFFERING = 19;
	public static final int SONG_SIZEOF = 20;

	public static final int OPTION_SILENCE_DETECT = 1;
	public static final int OPTION_RESPECT_LENGTH = 2;
	public static final int OPTION_PLAYBACK_ORDER = 3;
	public static final int OPTION_REPEATMODE = 4;
	public static final int OPTION_BUFFERSIZE = 5;
	public static final int OPTION_DEFAULT_LENGTH = 6;

	public static final int RM_CONTINUE = 0;
	public static final int RM_KEEP_PLAYING = 1;
	public static final int RM_REPEAT = 2;
	public static final int RM_CONTINUE_SUBSONGS = 3;
	public static final int RM_REPEAT_SUBSONG = 4;

	private Object info[];

	private Player player;
	private Thread playerThread;

	private final SongInfo currentSongInfo = new SongInfo();

	//private boolean silenceDetect;
	private boolean respectLength = true;
	private boolean shuffleSongs;

	private PhoneStateListener phoneStateListener;

	private final int defaultRepeatMode = RM_CONTINUE;

	PlayQueue playQueue;

	final static String stripChars = "[]!<>?#${}";
	final static String blankChars = ".-^,";

    private final Handler mHandler = new Handler() {
		@Override
        public void handleMessage(Message msg) {
        	//Log.d(TAG, "Got msg %d with arg %s", msg.what, (String)msg.obj);
			String [] sa;
            switch (msg.what) {
            	case Player.MSG_WAVDUMPED:
            		info[SONG_FILENAME] = msg.obj;
            		performCallback(SONG_FILENAME);
            		info[SONG_FILENAME] = null;
            		break;
            	case Player.MSG_DETAILS:
            		sa = (String [])msg.obj;
            		info[SONG_DETAILS] = "DETAILS";
            		currentSongInfo.details = sa;
            		performCallback(SONG_DETAILS);
            		Log.d(TAG, "%%%%%%%% Sending %d details", sa.length);
            		break;
            	case Player.MSG_INFO:
        			sa = (String [])msg.obj;
        			info[SONG_TITLE] = sa[0];
        			info[SONG_AUTHOR] = sa[1];
        			performCallback(SONG_TITLE, SONG_AUTHOR);
        			break;
            	case Player.MSG_SUBTUNE:
            		Log.d(TAG, "SUBTUNE %d, Length %d", msg.arg1, msg.arg2);
            		info[SONG_SUBSONG] = msg.arg1;
            		info[SONG_LENGTH] = msg.arg2;

            		if(msg.arg2 == -1)
            			info[SONG_LENGTH] = defaultLength;

            		info[SONG_STATE] = 1;
            		if(msg.obj != null) {
            			sa = (String [])msg.obj;
            			info[SONG_SUBTUNE_TITLE] = sa[0];
            			info[SONG_SUBTUNE_AUTHOR] = sa[1];

                		performCallback(SONG_SUBSONG, SONG_LENGTH, SONG_SUBTUNE_TITLE, SONG_SUBTUNE_AUTHOR, SONG_STATE);
                		break;
            		}
            		performCallback(SONG_SUBSONG, SONG_LENGTH, SONG_STATE);
            		break;
                case Player.MSG_NEWSONG:
                	player.getSongInfo(currentSongInfo);
                	info[SONG_TITLE] = currentSongInfo.title;
					info[SONG_AUTHOR] = currentSongInfo.author;
					info[SONG_COPYRIGHT] = currentSongInfo.copyright;
					info[SONG_FORMAT] = currentSongInfo.type;
					info[SONG_LENGTH] = currentSongInfo.length;
					info[SONG_TOTALSONGS] = currentSongInfo.subTunes;
					info[SONG_SUBSONG] = currentSongInfo.startTune;
					info[SONG_REPEAT] = defaultRepeatMode;
					info[SONG_SUBTUNE_TITLE] = currentSongInfo.subtuneTitle;
					info[SONG_SUBTUNE_AUTHOR] = currentSongInfo.subtuneAuthor;
					info[SONG_FLAGS] = currentSongInfo.canSeek ? 1 : 0;
					info[SONG_STATE] = 1;
					info[SONG_SOURCE] = "";
					info[SONG_BUFFERING] = -1;

            		if(currentSongInfo.length == -1)
            			info[SONG_LENGTH] = defaultLength;


					if(currentSongInfo.source != null && currentSongInfo.source.length() > 0)
						info[SONG_SOURCE] = currentSongInfo.source;
					else if(playListName != null) {
						info[SONG_SOURCE] = playListName;
					}

					Log.d(TAG, "SOURCE IS " + currentSongInfo.source);

					performCallback(SONG_FILENAME, SONG_TITLE, SONG_SUBTUNE_TITLE, SONG_SUBTUNE_AUTHOR, SONG_AUTHOR, SONG_COPYRIGHT, SONG_LENGTH, SONG_FLAGS, SONG_SUBSONG, SONG_TOTALSONGS, SONG_SOURCE, SONG_REPEAT, SONG_STATE);
                	break;
                case Player.MSG_DONE:
                	Log.d(TAG, "Music done");
                	if((Integer)info[SONG_REPEAT] == RM_CONTINUE) {
                		playNextSong();
                	} else {
                		info[SONG_STATE] = 0;
                		performCallback(SONG_STATE);
                	}
                    break;
                case Player.MSG_PROGRESS:
                	int l = (Integer)info[SONG_LENGTH];
                	if(l < 0) {
                		l = defaultLength;
                	}
                	//Log.d(TAG, "%d vs %d", msg.arg1, l);
                	if(l > 0 && (msg.arg1 >= l) && respectLength && ((Integer)info[SONG_REPEAT] == RM_CONTINUE)) {
                		playNextSong();
                	} else {
                    	int pos = msg.arg1;
                    	int buffering = msg.arg2;
                    	if(pos >= 0 && buffering >= 0) {
	                    	info[SONG_BUFFERING] = buffering;
	                    	info[SONG_POS] = pos;
	                		performCallback(SONG_BUFFERING, SONG_POS);
                    	} else if(pos >= 0) {
	                    	info[SONG_POS] = pos;
	                		performCallback(SONG_POS);
                    	} else {
	                    	info[SONG_BUFFERING] = buffering;
	                		performCallback(SONG_BUFFERING);
                    	}
                	}
    				break;
                case Player.MSG_STATE:
                	info[SONG_STATE] = msg.arg1;

                	if(msg.arg1 == 0) {
                		info[SONG_POS] = info[SONG_SUBSONG] = info[SONG_TOTALSONGS] = info[SONG_LENGTH] = 0;
                		currentSongInfo.fileName = null;
                		performCallback(SONG_POS, SONG_SUBSONG, SONG_TOTALSONGS, SONG_LENGTH, SONG_STATE);
                	} else {
                		performCallback(SONG_STATE);
                	}
                	break;
                default:
                    super.handleMessage(msg);
            }
        }
    };

    private void createThread() {
    	if (playerThread != null) {
    		if (! playerThread.isAlive()) {
    			playerThread = null;
    		}
    	}

    	if (playerThread == null) {
			Log.d(TAG, "Creating thread");
			player.setBufSize(bufSize);
		    playerThread = new Thread(player);
		    playerThread.setPriority(Thread.MAX_PRIORITY);
		    playerThread.start();
    	}
    }

    private boolean playNextSong() {
    	if(playQueue == null) {
    		return false;
    	}
    	SongFile song = playQueue.next();

		if(song != null) {
       		song = playQueue.current();
       		info[SONG_FILENAME] = song.getPath();
       		createThread();

       		beforePlay(song.getName());
       		player.playMod(song);
       		return true;
    	}
		return false;
    }

    private boolean playPrevSong() {
    	if(playQueue == null) {
    		return false;
    	}
    	SongFile song = playQueue.prev();
		if(song != null) {
       		song = playQueue.current();
       		info[SONG_FILENAME] = song.getPath();
       		createThread();
       		beforePlay(song.getName());
       		player.playMod(song);
       		return true;
    	}
		return false;
    }

	private Notification notification;

	private PendingIntent contentIntent;

	protected int bufSize = 0x40000;

	protected int defaultLength = 60*15*1000;

	protected String playListName;

	protected int callState = TelephonyManager.CALL_STATE_IDLE;

	@Override
	public void onCreate() {
		super.onCreate();

        AudioManager audioManager = (AudioManager) getSystemService(AUDIO_SERVICE);
		player = new Player(audioManager, mHandler, getApplicationContext());
		info = new Object[20];

		phoneStateListener = new PhoneStateListener() {
			boolean didPause = false;

			@Override
			public void onCallStateChanged(int state, String incomingNumber) {
				callState  = state;
				switch(state) {
				case TelephonyManager.CALL_STATE_RINGING:
				case TelephonyManager.CALL_STATE_OFFHOOK:
					if(player != null && player.isPlaying()) {
						player.paused(true);
						didPause = true;
					}
					break;
				case TelephonyManager.CALL_STATE_IDLE:
					if (didPause && player != null && !player.isPlaying()) {
						player.paused(false);
					}
					didPause = false;
					break;
				}

				Log.d(TAG, "CALL STATE %d %s", state, incomingNumber);
			}
		};

		TelephonyManager tm = (TelephonyManager)getSystemService(TELEPHONY_SERVICE);
		tm.listen(phoneStateListener, PhoneStateListener.LISTEN_CALL_STATE);

		notification = new Notification(R.drawable.droidsound64x64, "Droidsound", System.currentTimeMillis());
		Intent notificationIntent = new Intent(this, PlayerActivity.class);
		notification.flags |= Notification.FLAG_ONGOING_EVENT | Notification.FLAG_FOREGROUND_SERVICE;
		contentIntent = PendingIntent.getActivity(getApplicationContext(), 0, notificationIntent, 0);
	    notification.setLatestEventInfo(this, "Droidsound", "Playing", contentIntent);
	}

	protected void beforePlay(String name) {
		notification.setLatestEventInfo(this, "Droidsound", name, contentIntent);
		NotificationManager nm = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
		nm.notify(0x123456, notification);
	}

	protected void afterPlay() {
		NotificationManager nm = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
		nm.cancel(0x123456);
	}

	@Override
	public void onStart(Intent intent, int startId) {
		super.onStart(intent, startId);
		Log.d(TAG, "Service started");
		if (intent == null) {
			return;
		}
		Log.d(TAG, "Intent %s / %s", intent.getAction(), intent.getDataString());
        if(intent.getAction() != null && intent.getAction().contentEquals(Intent.ACTION_VIEW)) {
			Uri uri = intent.getData();
			if(uri == null) {
				Bundle b = intent.getExtras();
				SongFile song = null;
				String ff =  b.getString("musicFile");
				if(ff != null) {
					song = new SongFile(ff);
				}
				int index = b.getInt("musicPos");
				String [] names = (String []) b.getSerializable("musicList");

				playQueue = new PlayQueue(names, index, shuffleSongs);

				if(song == null) {
					song = playQueue.current();
				}

				createThread();
				if(song == null) {
					String modname = (String) info[SONG_FILENAME];
					if(names != null && modname != null) {
						Log.d(TAG, "Got playlist without song");
					}
				} else {
					Log.d(TAG, "Want to play list with " + song.getPath());
					info[SONG_FILENAME] = song.getPath();
					playListName = "";
					beforePlay(song.getName());
					player.playMod(song);
				}
			} else {
				Log.d(TAG, "Want to play " + intent.getDataString());
				createThread();
				playListName = "";
				info[SONG_FILENAME] = uri.getLastPathSegment();
				SongFile song = new SongFile(intent.getDataString());
				beforePlay(song.getName());
				player.playMod(song);
			}
		}

	}

	@Override
	public void onDestroy() {

		super.onDestroy();

		TelephonyManager tm = (TelephonyManager)getSystemService(TELEPHONY_SERVICE);
		tm.listen(phoneStateListener, 0);

		player.stop();
		player = null;
		playerThread = null;
	}

	protected Set<IPlayerServiceCallback> callbacks = new HashSet<IPlayerServiceCallback>();

	private void performCallback(int...what) {
		for (IPlayerServiceCallback cb : callbacks) {
			for (int i : what) {
				Object v = info[i];
				if (v == null || (v instanceof String)) {
					cb.stringChanged(i, (String) v);
				} else {
					cb.intChanged(i, (Integer) v);
				}
			}
		}
	}

	public class LocalBinder extends Binder {
		public boolean playMod(String name) {
			createThread();
			info[SONG_FILENAME] = name;
			SongFile song = new SongFile(name);
			beforePlay(song.getName());
			player.playMod(song);
			return true;
		}

		public void registerCallback(IPlayerServiceCallback cb, int flags) {
			for (int i = 1; i < SONG_SIZEOF; i++) {
				if(info[i] != null) {
					if(info[i] instanceof String) {
						cb.stringChanged(i, (String)info[i]);
					} else {
						cb.intChanged(i, (Integer)info[i]);
					}
				}
			}
			callbacks.add(cb);
		}

		public void unRegisterCallback(IPlayerServiceCallback cb) {
			callbacks.remove(cb);
		}

		public boolean playPause(boolean play) {
			if((!player.isActive() || player.isSwitching()) && play && playQueue != null) {
				SongFile s = playQueue.current();
				if(s != null) {
	           		info[SONG_FILENAME] = s.getPath();
	           		createThread();
	    			beforePlay(s.getName());
	           		player.playMod(s);
	           		return true;
	    		}
			}
			player.paused(!play);
			return true;
		}

		public void stop()  {
			player.stop();
			afterPlay();
			info[SONG_REPEAT] = defaultRepeatMode;
			performCallback(SONG_REPEAT);
		}

		public boolean seekTo(int msec) {
			player.seekTo(msec);
			info[SONG_POS] = msec;
			performCallback(SONG_POS);
			return true;
		}

		public boolean setSubSong(int song) {
	    	if (playQueue == null) {
	    		return false;
	    	}

 			player.setSubSong(song);
			info[SONG_SUBSONG] = song;
			if((Integer)info[SONG_REPEAT] == RM_CONTINUE) {
				info[SONG_REPEAT] = RM_KEEP_PLAYING;
				performCallback(SONG_REPEAT);
			}

			return true;
		}

		public void setOption(int opt, String arg) {
			switch(opt) {
			case OPTION_DEFAULT_LENGTH:
				defaultLength  = Integer.parseInt(arg) * 1000;
				Log.d(TAG, "Default length set to " + defaultLength);
				break;
			case OPTION_REPEATMODE:
				info[SONG_REPEAT] = Integer.parseInt(arg);
				performCallback(SONG_REPEAT);
				break;
			case OPTION_PLAYBACK_ORDER:
				if(arg.charAt(0) == 'R') {
					shuffleSongs = true;
				} else if(arg.charAt(0) == 'S') {
					shuffleSongs = false;
				}
				if(playQueue != null) {
					playQueue.setShuffle(shuffleSongs);
				}
				break;
			case OPTION_RESPECT_LENGTH:
				Log.d(TAG, "Respect length " + arg);
				respectLength = arg.equals("on");
				break;
			case OPTION_BUFFERSIZE:
				bufSize = 176384; // 2s
				if(arg.equals("Short")) {
					bufSize = 66144; // 0.75s
				} else if(arg.equals("Medium")) {
						bufSize = 132288; // 1.5s
				} else if(arg.equals("Very Long")) {
					bufSize = 352768; // 4s
				}
				player.setBufSize(bufSize);
				break;
			}
		}

		public boolean playPlaylist(String name, int startIndex) {
			File pf = new File(name);
			Playlist pl = Playlist.getPlaylist(pf);
			playQueue = new PlayQueue(pl, startIndex, shuffleSongs);

			SongFile mod = playQueue.current();

			createThread();
			info[SONG_FILENAME] = mod.getPath();

			int dot = name.lastIndexOf('.');
			if(dot > 0) {
				name = name.substring(0, dot);
			}
			playListName = name;


			beforePlay(mod.getName());
			player.playMod(mod, playQueue.getNextSong());
	    	info[SONG_REPEAT] = defaultRepeatMode;
	    	return true;
		}

		public boolean playList(String[] names, int startIndex) {
			playQueue = new PlayQueue(names, startIndex, shuffleSongs);
			SongFile song = playQueue.current();
			Log.d(TAG, "PlayList called " + song.getPath());
			createThread();
			info[SONG_FILENAME] = song.getPath();
			playListName = "";
			beforePlay(song.getName());
			player.playMod(song);
	    	info[SONG_REPEAT] = defaultRepeatMode;
			performCallback(SONG_REPEAT);
			return false;
		}

		public void playNext() {
	    	info[SONG_REPEAT] = defaultRepeatMode;
			performCallback(SONG_REPEAT);
			playNextSong();
		}

		public void playPrev() {
	    	info[SONG_REPEAT] = defaultRepeatMode;
			performCallback(SONG_REPEAT);
			playPrevSong();
		}

		public String[] getSongInfo() {
			return currentSongInfo.details;
		}

		public boolean dumpWav(String modName, String destFile, int length, int flags) {
			createThread();
			info[SONG_FILENAME] = modName;
			SongFile song = new SongFile(modName);
			//beforePlay(song.getName());
			player.dumpWav(song, destFile, length, flags);

			return false;
		}
	}

	private final LocalBinder mBinder = new LocalBinder();

    @Override
    public IBinder onBind(Intent intent) {
    	return mBinder;
    }
}
