package com.ssb.droidsound.service;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Random;

import com.ssb.droidsound.service.Player.SongInfo;

import android.app.Service;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.media.AudioManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.os.RemoteException;
import android.speech.tts.TextToSpeech;
import android.telephony.PhoneStateListener;
import android.telephony.TelephonyManager;
import android.util.Log;

public class PlayerService extends Service {
	private static final String TAG = "PlayerService";
	
	// Flags
	
	// public static final int FLAG_CONTINUOUS = 1;
	// public static final int FLAG_SHUFFLE = 2;
	// public static final int FLAG_REPEAT = 4;
	
	// Information
	
	public static final int SONG_TITLE = 1;
	public static final int SONG_AUTHOR = 2;
	public static final int SONG_COPYRIGHT = 3;
	public static final int SONG_GAMENAME = 4;	
	public static final int SONG_FORMAT = 5;
	
	public static final int SONG_POS = 6;
	public static final int SONG_FILENAME = 7;
	public static final int SONG_LENGTH = 8;
	public static final int SONG_SUBSONG = 9;
	public static final int SONG_TOTALSONGS = 10;
	
	public static final int SONG_STATE = 11;
	
	public static final int SONG_DETAILS = 12;
	public static final int SONG_MD5 = 13;
	
	public static final int SONG_SIZEOF = 14;

	public static final int OPTION_SPEECH = 0;
	public static final int OPTION_SILENCE_DETECT = 1;
	public static final int OPTION_RESPECT_LENGTH = 2;
	public static final int OPTION_PLAYBACK_ORDER = 3;

	private static Random rgen = new Random(System.currentTimeMillis());
	private short[] shuffleArray;
	
	private Object info[];

	protected String[] musicList;
	protected int musicListPos;
    	
	private Player player;
	private Thread playerThread;
	private List<IPlayerServiceCallback> callbacks; 	

	private SongInfo currentSongInfo = new SongInfo();
	
	private boolean userInterferred;
	private boolean silenceDetect;
	private boolean respectLength = true;
	private boolean shuffleSongs;
	
	private TextToSpeech textToSpeech;
	private int ttsStatus = -1;
	
	private void performCallback(int...what) {
		Iterator<IPlayerServiceCallback> it = callbacks.iterator();
		while(it.hasNext()) {
			IPlayerServiceCallback cb = it.next();
			for(int i : what) {
				try {
					if(info[i] instanceof String) {
						cb.stringChanged(i, (String)info[i]);
					} else if(info[i] == null) {
						cb.stringChanged(i, null);
					} else {
						cb.intChanged(i, (Integer)info[i]);
					}
				} catch (RemoteException e) {
					Log.v(TAG, "Removing callback because peer is gone");
					it.remove();
				}
			}
		}
	}

	final static String stripChars = "[]!<>?#${}"; 
	final static String blankChars = ".-^";
	
	final static Map<String, String> composerTranslation = new HashMap<String, String>();
	
	static {
		
		Map<String, String> ct = composerTranslation;
		
		ct.put("GOTO80", "Go to 80");
		ct.put("RAVEGURU", "Rave guru");
		ct.put("A MAN", "A.Man");
		ct.put("SMALLTOWN BOY", "Small town boy");
		ct.put("PVCF", "P V C F");
		ct.put("AGEMIXER", "Age mixer");
		ct.put("RADIANTX", "Radiant X");
		ct.put("TWOFLOWER", "Two flower");
		ct.put("NECROPOLO", "Necro Polo");
		ct.put("MINDFLOW", "Mind Flow");
		ct.put("MAKTONE", "Mac toane");
		ct.put("NE7", "N.E 7");
		ct.put("GLENN RUNE GALLEFOSS", "Glen Rooneh Galleh foss");
	}
	

	private String fixSpeech(String s, boolean composer) {
		StringBuilder sb = new StringBuilder();
		
		if(s.equals("<?>")) {
			return "Unnamed";
		}
		
		for(int i=0; i<s.length(); i++) {
			char c = s.charAt(i);
			if(stripChars.indexOf(c) == -1) {
				if(blankChars.indexOf(c) != -1) {
					c = ' ';
				}
				
				switch(c) {
				case '&':
					sb.append(" and ");
					break;
				case '/':
					if(composer) {
						sb.append(" of ");
					} else {
						sb.append(' ');
					}
					break;
				default:
					sb.append(c);
					break;
				}
			}
		}
		
		if(composer) {
			String a = sb.toString().toUpperCase();
			String x = composerTranslation.get(a);
			Log.v(TAG, String.format("Checked %s became %s", a, x == null ? "NULL" : x));
			if(x != null) {
				return x;
			}
		}
		
		return sb.toString();
	}
	
    private Handler mHandler = new Handler() {

		@Override
        public void handleMessage(Message msg) {
        	//Log.v(TAG, String.format("Got msg %d with arg %s", msg.what, (String)msg.obj));
            switch (msg.what) {
            	case Player.MSG_SUBTUNE:
            		Log.v(TAG, String.format("SUBTUNE %d, Length %d", msg.arg1, msg.arg2));
            		info[SONG_SUBSONG] = msg.arg1;
            		info[SONG_LENGTH] = msg.arg2;
        			performCallback(SONG_SUBSONG, SONG_LENGTH);
            		break;
                case Player.MSG_NEWSONG:
                	
                	player.getSongInfo(currentSongInfo);
                	info[SONG_TITLE] = currentSongInfo.title;
                	if(currentSongInfo.title == null || currentSongInfo.title.length() == 0) {
                		File f = new File((String)info[SONG_FILENAME]);                	
                		info[SONG_TITLE] = f.getName();
                	}
					info[SONG_AUTHOR] = currentSongInfo.author;
					info[SONG_COPYRIGHT] = currentSongInfo.copyright;
					info[SONG_FORMAT] = currentSongInfo.type;
					info[SONG_LENGTH] = currentSongInfo.length;
					info[SONG_TOTALSONGS] = currentSongInfo.subTunes;
					info[SONG_SUBSONG] = currentSongInfo.startTune;
					info[SONG_GAMENAME] = currentSongInfo.game;
					
					info[SONG_STATE] = 1;

        			String text = "Unnamed song.";

        			if(ttsStatus >= 0) {
            			
        				String songComposer = (String) info[SONG_AUTHOR];
        				
        				if(songComposer.endsWith(")")) {
    						int lpara = songComposer.lastIndexOf("(");
    						int rpara = songComposer.lastIndexOf(")");
    						if(lpara > 0) {
    							songComposer = songComposer.substring(lpara+1, rpara);
    						}
    					}
        				
            			String songTitle = fixSpeech((String) info[SONG_TITLE], false);            			
            			songComposer = fixSpeech(songComposer, true);
            			

        				if(songComposer != null & songComposer.length() > 1) {        					        					
        					text = songTitle + ". By " + songComposer + ".";        					
        				} else {
        					text = songTitle + ".";
        				}
        				Log.v(TAG, String.format("Saying '%s'", text));
        				textToSpeech.speak(text, TextToSpeech.QUEUE_FLUSH, null);
        			}

                	

					performCallback(SONG_FILENAME, SONG_MD5, SONG_TITLE, SONG_AUTHOR, SONG_COPYRIGHT, SONG_GAMENAME, SONG_LENGTH, SONG_SUBSONG, SONG_TOTALSONGS, SONG_STATE);
                	break;
                case Player.MSG_DONE:
                	Log.v(TAG, "Music done");
                	playNextSong();
                    break;
                case Player.MSG_PROGRESS:
                	int l = (Integer)info[SONG_LENGTH];
                	if(l > 0 && (msg.arg1 >= l) && respectLength && !userInterferred) {
                		playNextSong();
                	} else {                	
                    	info[SONG_POS] = (Integer)msg.arg1;
                		performCallback(SONG_POS);
                	}
    				break;
                case Player.MSG_STATE:
                	info[SONG_STATE] = (Integer)msg.arg1;
                	
                	if(msg.arg1 == 0) {
                		info[SONG_POS] = info[SONG_SUBSONG] = info[SONG_TOTALSONGS] = info[SONG_LENGTH] = 0;
                		performCallback(SONG_POS, SONG_SUBSONG, SONG_TOTALSONGS, SONG_LENGTH, SONG_STATE);
                	} else {                	
                		performCallback(SONG_STATE);
                	}
                	break;
                case Player.MSG_SILENT:
                	if(silenceDetect) {
	                	if(!userInterferred)
	                		playNextSong();
	                	else
	                		Log.v(TAG, "User has interferred, not switching");
                	}
                	break;
                default:
                    super.handleMessage(msg);
            }
        }

    };

	private PhoneStateListener phoneStateListener;
	
    void createThread() {
    	
    	if(playerThread != null) {
			if(!playerThread.isAlive()) {
				playerThread = null;
			}
    	}
    	
    	if(playerThread == null) {
			Log.v(TAG, "Creating thread");
		    playerThread = new Thread(player);
		    playerThread.setPriority(Thread.MAX_PRIORITY);
		    playerThread.start();
    	}
    }

    void playNextSong() {
    	if(musicList != null) {
    		musicListPos++;
    		if(musicListPos < musicList.length) {    			
           		info[SONG_FILENAME] = musicList[shuffleArray[musicListPos]];
           		createThread();
           		player.playMod((String)info[SONG_FILENAME]);
           		return;
    		}
    		musicListPos--;;
    	}
    }

    void playPrevSong() {    	
    	if(musicList != null) {
    		musicListPos--;
    		if(musicListPos >= 0) {
           		info[SONG_FILENAME] = musicList[shuffleArray[musicListPos]];
           		createThread();
           		player.playMod((String)info[SONG_FILENAME]);
           		return;
    		}
    		musicListPos++;
    	}
    }
    

	@Override
	public void onCreate() {
		super.onCreate();		
        AudioManager audioManager = (AudioManager) getSystemService(AUDIO_SERVICE);
		player = new Player(audioManager, mHandler, getApplicationContext());
		callbacks = new ArrayList<IPlayerServiceCallback>();
		info = new Object [20];
		for(int i=0; i<20; i++)
			info[i] = null;
		
		
		phoneStateListener = new PhoneStateListener() {
			
			boolean didPause = false;
			
			@Override
			public void onCallStateChanged(int state, String incomingNumber) {
				
				switch(state) {
				case TelephonyManager.CALL_STATE_RINGING:
					if(player != null && player.isPlaying()) {
						player.paused(true);
						didPause = true;
					}
					break;
				case TelephonyManager.CALL_STATE_IDLE:
					if(didPause && player != null && !player.isPlaying()) {
						player.paused(false);
					}
					didPause = false;
					break;
				case TelephonyManager.CALL_STATE_OFFHOOK:
					break;
				}
				
				Log.v(TAG, String.format("CALL STATE %d %s", state, incomingNumber));
				//super.onCallStateChanged(state, incomingNumber);
			}
		};
		
		TelephonyManager tm = (TelephonyManager)getSystemService(TELEPHONY_SERVICE);
		tm.listen(phoneStateListener, PhoneStateListener.LISTEN_CALL_STATE);

		
		Log.v(TAG, "PlayerService created");
	}
	
	@Override
	public void onStart(Intent intent, int startId) {
		super.onStart(intent, startId);
		Log.v(TAG, "Service started");
		Log.v(TAG, String.format("Intent %s / %s", intent.getAction(), intent.getDataString()));		
        if(intent.getAction() != null && intent.getAction().contentEquals(Intent.ACTION_VIEW)) {
			Uri uri = intent.getData();
			if(uri == null) {
				Bundle b = intent.getExtras();							
				String f =  b.getString("musicFile");
				musicListPos = b.getInt("musicPos");
				musicList = (String []) b.getSerializable("musicList");
				if(musicList != null) {
					shuffleArray = new short [musicList.length];
					//unshuffle();
				}
				if(f == null) {
					if(musicListPos >= 0) {
						f = musicList[shuffleArray[musicListPos]];
					}
				}
				createThread();
				if(f == null) {
					String modname = (String) info[SONG_FILENAME];
					if(musicList != null && modname != null) {
						Log.v(TAG, "Got playlist without song");
						for(int i=0; i<musicList.length; i++) {
							if(musicList[i].compareTo(modname) == 0) {
								musicListPos = i;
								Log.v(TAG, String.format("Changing pos ftrom %d to %d", musicListPos, i));
								break;
							}
						}
					}
				} else {
					Log.v(TAG, "Want to play list with " + f);
					info[SONG_FILENAME] = f;
					player.playMod(f);
				}
			} else {
				Log.v(TAG, "Want to play " + intent.getDataString());
				createThread();
				info[SONG_FILENAME] = uri.getLastPathSegment();
				player.playMod(intent.getDataString());
			}
		}
        /*
		BroadcastReceiver receiver = new BroadcastReceiver() {
			@Override
			public void onReceive(Context context, Intent intent) {
				// TODO Auto-generated method stub
				
				if(player.isPlaying()) {
					player.paused(true);
					abortBroadcast();
				}
			}
		};
		
		IntentFilter filter = new IntentFilter();
		filter.addAction(Intent.ACTION_MEDIA_BUTTON);
		filter.setPriority(1001);		
		registerReceiver(receiver, filter);
        */
        
		
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
	
	private final IPlayerService.Stub mBinder = new IPlayerService.Stub() {




		@Override
		public boolean playMod(String name) throws RemoteException {
			Log.v(TAG, "Playmod called " + name);
			
			if(musicList != null && musicListPos >= 0) {
				musicList[shuffleArray[musicListPos]] = name;
			}
			
			createThread();
			info[SONG_FILENAME] = name;
			player.playMod(name);
			
			return true;
		}

		@Override
		public void registerCallback(IPlayerServiceCallback cb, int flags) throws RemoteException {
			
			if(cb != null) {
				for(int i=1; i<SONG_SIZEOF; i++) {
					try {
						if(info[i] != null) {
							if(info[i] instanceof String) {
								cb.stringChanged(i, (String)info[i]);
							} else {
								cb.intChanged(i, (Integer)info[i]);
							}
						}
					} catch (RemoteException e) {
						Log.v(TAG, "Ignoring callback because peer is gone");
						return;
					}				
				}
			}
			Log.v(TAG, String.format("Adding %s", cb.toString()));
			callbacks.add(cb);			
		}

		@Override
		public void unRegisterCallback(IPlayerServiceCallback cb)
				throws RemoteException {
			
			Log.v(TAG, String.format("Removing %s", cb.toString()));
			callbacks.remove(cb);
		}

		
		@Override
		public boolean playPause(boolean play) throws RemoteException {
			if(!player.isActive() && play) {
				if(musicList != null) {
		    		if(musicListPos >= 0) {
		           		info[SONG_FILENAME] = musicList[shuffleArray[musicListPos]];
		           		createThread();
		           		player.playMod((String)info[SONG_FILENAME]);
		           		return true;
		    		}
				}
			}
			player.paused(!play);
			return true;
			//}
			//return false;
		}

		@Override
		public void stop() throws RemoteException {
			player.stop();
	    	userInterferred = false;
		}


		@Override
		public boolean seekTo(int msec) throws RemoteException {
			player.seekTo(msec);
			info[SONG_POS] = msec;
			performCallback(SONG_POS);
			userInterferred = true;
			return true;
		}

		@Override
		public boolean setSubSong(int song) throws RemoteException {
			player.setSubSong(song);
			info[SONG_SUBSONG] = (Integer)song;			
			userInterferred = true;
			return true;
			
		}

		
		@Override
		public void setOption(int opt, String arg) throws RemoteException {

			boolean on = arg.equals("on");
			
			switch(opt) {
			case OPTION_SILENCE_DETECT:
				Log.v(TAG, "Silence detection " + arg);
				silenceDetect = on;
				break;
			case OPTION_PLAYBACK_ORDER:
				unshuffle();
				if(arg.charAt(0) == 'R') {
					shuffleSongs = true;
					shuffle();
				} else {
					shuffleSongs = false;
				}
				break;
			case OPTION_RESPECT_LENGTH:
				Log.v(TAG, "Respect length " + arg);
				respectLength = on;
				break;
			case OPTION_SPEECH:
				if(on) {
					if(textToSpeech == null) {
						Log.v(TAG, "Turning on speech");
						textToSpeech = new TextToSpeech(getApplicationContext(), new TextToSpeech.OnInitListener() {
							@Override
							public void onInit(int status) {					
								ttsStatus = status;
								textToSpeech.setLanguage(Locale.US);
							}
						});
					}
				} else {
					if(textToSpeech != null) {
						textToSpeech.shutdown();
						textToSpeech = null;
						ttsStatus = -1;
						Log.v(TAG, "Turning off speech");
					}
				}
				break;
			}
		}
		

		private void shuffle() {
			if(shuffleArray != null) {
				short t;
				for (int i=musicListPos+1; i<shuffleArray.length; i++) {					
				    int randomPosition = rgen.nextInt(shuffleArray.length-1) + 1;
				    t = shuffleArray[i];
				    shuffleArray[i] = shuffleArray[randomPosition];
				    shuffleArray[randomPosition] = t;
				}
			}
		}
		
		private void unshuffle() {
			if(shuffleArray != null) {
				musicListPos = shuffleArray[musicListPos];
				for (int i=0; i<shuffleArray.length; i++) {
					shuffleArray[i] = (short)i;
				}
			}
		}

		@Override
		public boolean playList(String[] names, int startIndex) throws RemoteException {
			musicList = names;
			
			shuffleArray = new short [musicList.length];
			musicListPos = 0;
			unshuffle();
			musicListPos = startIndex;

			if(shuffleSongs) {
				musicListPos = 0;
				shuffle();
				for(int i=0; i<shuffleArray.length; i++) {
					if(shuffleArray[i] == startIndex) {
						shuffleArray[i] = 0;
						shuffleArray[0] = (short) startIndex;
						break;
					}
				}
				
			}		
			
			for(int i=0; i<shuffleArray.length; i++) {
				Log.v(TAG, String.format("%02d: %02d", i, shuffleArray[i]));
			}
			/*
				temp = musicList[0];
				musicList[0] = musicList[startIndex];
				musicList[startIndex] = temp;
				startIndex = 0;
				
				for (int i=1; i<musicList.length; i++) {					
				    int randomPosition = rgen.nextInt(musicList.length-1) + 1;
				    temp = musicList[i];
				    musicList[i] = musicList[randomPosition];
				    musicList[randomPosition] = temp;
				}
			} */
			
			String name = names[startIndex];			
			Log.v(TAG, "PlayList called " + name);
			createThread();
			info[SONG_FILENAME] = name;
			player.playMod(name);
	    	userInterferred = false;

			return false;
		}

		@Override
		public void playNext() throws RemoteException {
	    	userInterferred = false;
			playNextSong();
		}

		@Override
		public void playPrev() throws RemoteException {
	    	userInterferred = false;
			playPrevSong();
		}

		@Override
		public String[] getSongInfo() throws RemoteException {
			// TODO Auto-generated method stub
			return currentSongInfo.details;
		}

		};
	
    @Override
    public IBinder onBind(Intent intent) {
    	Log.v(TAG, "BOUND");
    	return mBinder;
    }
    
    @Override
    public boolean onUnbind(Intent intent) {
    	Log.v(TAG, "UNBOUND");
    	return super.onUnbind(intent);
    }
}
