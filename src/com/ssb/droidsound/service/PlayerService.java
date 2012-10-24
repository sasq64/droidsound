package com.ssb.droidsound.service;

import java.io.File;
import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Map.Entry;

import android.annotation.TargetApi;
import android.app.Notification;
import android.app.PendingIntent;
import android.app.Service;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
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

import com.ssb.droidsound.PlayerActivity;
import com.ssb.droidsound.Playlist;
import com.ssb.droidsound.R;
import com.ssb.droidsound.SongFile;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.utils.Log;

public class PlayerService extends Service implements PlayerInterface {
	private static final String TAG = PlayerService.class.getSimpleName();
	
	// Information
	
		
	public static final int ERR_SONG_COULD_NOT_PLAY = 1;

	public static final int OPTION_SPEECH = 0;
	public static final int OPTION_SILENCE_DETECT = 1;
	//public static final int OPTION_RESPECT_LENGTH = 2;
	public static final int OPTION_PLAYBACK_ORDER = 3;
	public static final int OPTION_REPEATMODE = 4;
	public static final int OPTION_BUFFERSIZE = 5;
	public static final int OPTION_DEFAULT_LENGTH = 6;
	public static final int OPTION_CYCLE_SUBTUNES = 7;



	public static final int RM_CONTINUE = 0;
	public static final int RM_KEEP_PLAYING = 1;
	public static final int RM_REPEAT = 2;	
	public static final int RM_CONTINUE_SUBSONGS = 3;
	public static final int RM_REPEAT_SUBSONG = 4;
	//private short[] shuffleArray;
	
	//private Object info[];
	private Map<String, Object> info = new HashMap<String, Object>();
    	
	private static PlayerInterface playerInterface;
	private Player player;
	private Thread playerThread;
	private List<IPlayerServiceCallback> callbacks; 	

	//private SongInfo currentSongInfo = new SongInfo();
	//private Map<String, Object> songDetails;
	
	//private boolean silenceDetect;
	//private boolean respectLength = true;
	private boolean shuffleSongs;
	
	private PhoneStateListener phoneStateListener;
	private BroadcastReceiver mediaReceiver;
	
	private static boolean hasRemoteControl;
	private static boolean hasAudioFocus;
	static {
		try {
			RemoteControlWrapper.checkAvailable();
			hasRemoteControl = true;
		} catch (Throwable t) {
			hasRemoteControl = false;
		}
		try {
			AudioFocusWrapper.checkAvailable();
			hasAudioFocus = true;
		} catch (Throwable t) {
			hasAudioFocus = false;
		}
	}
	
	private RemoteControlWrapper remoteControl;
	private AudioFocusWrapper afWrapper;

	//private int defaultRepeatMode = RM_CONTINUE;
	private int repeatMode = RM_CONTINUE;

	protected String saySomething;

	
	PlayQueue playQueue;
	
	private TextToSpeech textToSpeech;
	private int ttsStatus = -1;
	
	private boolean cycleSubTunes = false;

	
	public static PlayerInterface getPlayerInterface() {
		return playerInterface;
	}
	
	private void updateInfo(boolean newsong) {
		
		HashMap<String, Object> changed = new HashMap<String, Object>();
		
		if(newsong)
			info.clear();
		
		Map<String, Object> newInfo = new HashMap<String, Object>();
		player.getSongDetails(newInfo);
		for(Entry<String, Object> e : newInfo.entrySet()) {
			Object oldVal = info.get(e.getKey());
			Object newVal = e.getValue();
			if(oldVal == null && newVal == null)
				continue;
			if((oldVal == null && newVal != null) || !oldVal.equals(newVal)) {
				changed.put(e.getKey(), e.getValue());
			}
			
			info.put(e.getKey(), e.getValue());
			
		}
		
		if(changed.containsKey(SongMeta.TITLE)) { 
			if(hasRemoteControl) {
				remoteControl.setMetaData((String) info.get(SongMeta.COMPOSER), (String) info.get(SongMeta.TITLE));
			}
			speakTitle();
		}

		String [] updates;
		
		if(newsong)
			updates = mapToArray(info);
		else
			updates = mapToArray(changed);

		Iterator<IPlayerServiceCallback> it = callbacks.iterator();
		while(it.hasNext()) {
			IPlayerServiceCallback cb = it.next();
			try {
				cb.update(updates, newsong);
			} catch (RemoteException e1) {
				//e1.printStackTrace();
				it.remove();
			}
		}
	}

	final static String stripChars = "[]!<>?#${}"; 
	final static String blankChars = ".-^,";
	
	final static Map<String, String> composerTranslation = new HashMap<String, String>();

	static {
		
		Map<String, String> ct = composerTranslation;
		
		ct.put("GOTO80", "Go to 80");
		ct.put("RAVEGURU", "Rave guru");
		ct.put("A MAN", "A.Man");
		ct.put("LMAN", "L.Man");
		ct.put("LFT", "LFT");
		ct.put("GREGFEEL", "Greg feel");
		ct.put("CUBEHEAD", "Cube head");
		ct.put("LFT", "LFT");
		ct.put("XINY6581", "Xiny 6 5 8 1");
		ct.put("V0YAGER", "Voyager");
		ct.put("SOUNDEMON", "Sound demon");
		ct.put("SILVERFOX", "Silver fox");
		ct.put("PUTERMAN", "Puter man");
		ct.put("SANDMAN", "Sand man");
		ct.put("LITTLE SID", "Little Sid");
		ct.put("LORD SID", "Lord Sid");
		ct.put("NOISE OF SID", "Noise of Sid");
		ct.put("SMALLTOWN BOY", "Small town boy");
		ct.put("PVCF", "P V C F");
		ct.put("AGEMIXER", "Age mixer");
		ct.put("RADIANTX", "Radiant X");
		ct.put("TWOFLOWER", "Two flower");
		ct.put("NECROPOLO", "Necro Polo");
		ct.put("MINDFLOW", "Mind flow");
		ct.put("MAKTONE", "Mact1");
		ct.put("NE7", "N E 7");
		ct.put("DRAX", "Drax");
		ct.put("CYCLEBURNER", "Cycle burner");
		ct.put("GLENN RUNE GALLEFOSS", "Glen Runay Gallefoss");
	}
	

	private String fixSpeech(String s, boolean composer) {
		
		if(s == null) return s;
		
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
			Log.d(TAG, "Checked %s became %s", a, x == null ? "NULL" : x);
			if(x != null) {
				return x;
			}
		}
		
		return sb.toString();
	}
	
	private void speakTitle() {
		String text = "Unnamed song.";
			
		if(info.get(SongMeta.TITLE) == null) return;
		
		String songComposer = (String) info.get(SongMeta.COMPOSER);
		
		String s = (String) info.get(SongMeta.SUBTUNE_COMPOSER);
		if(s != null && s.length()> 0) {
			songComposer = s;
		}
		
		
				
		
		if(songComposer != null && songComposer.endsWith(")")) {
			int lpara = songComposer.lastIndexOf("(");
			int rpara = songComposer.lastIndexOf(")");
			if(lpara > 0) {
				songComposer = songComposer.substring(lpara+1, rpara);
			}
		}
		
		String songTitle = (String) info.get(SongMeta.TITLE);		
		s = (String) info.get(SongMeta.SUBTUNE_TITLE);
		if(s != null && s.length()> 0) {
			songTitle = s;
		}
		
		songTitle = fixSpeech(songTitle, false);
		
		
		songComposer = fixSpeech(songComposer, true);
		/*
		String subtuneTitle = (String) info[SongMeta.SUBTUNE_TITLE];
		
		if(subtuneTitle != null) {
			subtuneTitle = fixSpeech(subtuneTitle, false);
			songTitle += (" " + subtuneTitle);
		} */

		if(songComposer != null & songComposer.length() > 1) {        					        					
			text = songTitle + ". By " + songComposer + ".";        					
		} else {
			text = songTitle + ".";
		}
		Log.d(TAG, "Saying '%s'", text);
		if(ttsStatus >=0 && textToSpeech != null) {
			textToSpeech.speak(text, TextToSpeech.QUEUE_FLUSH, null);
		} else {
			saySomething = text;
		}	

	}
	
	private static class MyHandler extends Handler {
		
		private WeakReference<PlayerService> psRef;

		public MyHandler(PlayerService ps) {
			psRef = new WeakReference<PlayerService>(ps);
		}
		
		@Override
		public void handleMessage(Message msg) {
			PlayerService ps = psRef.get();
            switch (msg.what) {
            	case Player.MSG_WAVDUMPED:
            		ps.info.put(SongMeta.FILENAME, msg.obj);
            		ps.updateInfo(false);
            		ps.info.put(SongMeta.FILENAME, null);
            		break;
            	case Player.MSG_DETAILS:
            	case Player.MSG_SUBTUNE:
            		//sa = (String [])msg.obj;
            		//ps.info[SongMeta.DETAILS] = "DETAILS";
            		//ps.currentSongInfo.details = (String[]) msg.obj;            		
            		//ps.info = ps.player.getSongDetails();
            		ps.updateInfo(false);
            		break;
            	case Player.MSG_FAILED:
            		//ps.info[SongMeta.STATE] = 0;
            		//ps.info[SongMeta.ERROR] = ERR_SONG.COULD_NOT_PLAY;
            		//ps.performCallback(SongMeta.FILENAME, SongMeta.TITLE, SongMeta.ERROR);
            		//ps.info[SongMeta.ERROR] = 0;
            		break;
                case Player.MSG_NEWSONG:
            		ps.updateInfo(true);
                	break;
                case Player.MSG_DONE:
                	Log.d(TAG, "Music done");
                	if(ps.repeatMode == RM_CONTINUE) {
                		ps.playNextSong();
                	}// else {
                	//	ps.info[SongMeta.STATE] = 0;
                	//	performCallback(SongMeta.STATE);
                	//}
                    break;
                case Player.MSG_PROGRESS:
                	int l = (Integer)ps.info.get(SongMeta.LENGTH);
                	if(l < 0) {
                		l = ps.defaultLength;
                	}
                	//Log.d(TAG, "%d vs %d", msg.arg1, l);
                	if(l > 0 && (msg.arg1 >= l) && (ps.repeatMode == RM_CONTINUE)) {
                		ps.playNextSong();
                	} else {                		
                		ps.updateInfo(false);
                	}
    				break;
                case Player.MSG_STATE:
                	
                	int state = (Integer)msg.arg1;
                	if(state == 0) {
                		ps.updateInfo(true);
                	} else 
                		ps.updateInfo(false);
                	
                	/*ps.info[SongMeta.STATE] = (Integer)msg.arg1;
                	
                	if(msg.arg1 == 0) {
                		ps.info[SongMeta.POS] = ps.info[SongMeta.SUBSONG] = ps.info[SongMeta.TOTALSONGS] = ps.info[SongMeta.LENGTH] = 0;
                		ps.currentSongInfo.fileName = null;
                		ps.performCallback(SongMeta.POS, SongMeta.SUBSONG, SongMeta.TOTALSONGS, SongMeta.LENGTH, SongMeta.STATE);
                	} else {                	
                		ps.performCallback(SongMeta.STATE);
                	}*/
                	break;
                /*case Player.MSG_SILENT:
                	if(silenceDetect) {
	                	if((Integer)ps.info[SongMeta.REPEAT] == RM_CONTINUE) {
	                		playNextSong();
	                	} else {
	                		Log.d(TAG, "User has interferred, not switching");
	                	}
                	}
                	break;*/
                default:
                    super.handleMessage(msg);
            }
        }
	};
		
    private Handler mHandler = null;

	
    void createThread() {
    	
    	if(playerThread != null) {
			if(!playerThread.isAlive()) {
				playerThread = null;
			}
    	}
    	
    	if(playerThread == null) {
			Log.d(TAG, "Creating thread");
			player.setBufSize(bufSize);
		    playerThread = new Thread(player);
		    playerThread.setPriority(Thread.MAX_PRIORITY);
		    playerThread.start();
    	}
    }
    
    
    void updatePlaylist() {
    /*	if(currentPlaylist != null) {
    		int hash = currentPlaylist.hashCode();
    		if(hash != oldPlaylistHash) {
    			Log.d(TAG, "Current playlist has changed!");    			
    			List<File> files = currentPlaylist.getFiles();
    			
    			String current =  musicList[shuffleArray[musicListPos]];
    			
    			for(int i=0; i<files.size(); i++) {
    				if(files.get(i).getPath().equals(current)) {
    					break;
    				}
    			}
    			
    			
    			musicList = new String [files.size()];
    			int i = 0;
    			for(File f : files) {
    				musicList[i++] = f.getPath();				
    			}
    			
    			
    		}
    		oldPlaylistHash = hash;
    	} */
    }

    public boolean playNextSong() {
    	
    	if(cycleSubTunes) {
	    	int next = (Integer)info.get(SongMeta.SUBTUNE) + 1;
	    	if(next < (Integer)info.get(SongMeta.TOTAL_SUBTUNES)) {
	        	player.setSubSong(next);
	    		info.put(SongMeta.SUBTUNE, next);			
	    		return true;
	    	}
    	}
    	return playNextFile();
    }
    
    public boolean playNextFile() {
    	
    	if(playQueue == null) {
    		return false;
    	}
    	SongFile song = playQueue.next();
    	
		if(song != null) {    			
       		song = playQueue.current();       		
       		info.put(SongMeta.FILENAME, song.getPath());
       		createThread();

       		beforePlay(song.getName());
       		player.playMod(song);
       		return true;
    	}
		return false;
    }

    public boolean playPrevSong() {
    	
    	if(cycleSubTunes) {
    		int next = (Integer)info.get(SongMeta.SUBTUNE) - 1;
	    	if(next >= 0) {
	        	player.setSubSong(next);
	    		info.put(SongMeta.SUBTUNE, next);
	    		return true;
	    	}
    	}
    	return playPrevFile();
    }

   public boolean playPrevFile() {
	   
    	if(playQueue == null) {
    		return false;
    	}
    	SongFile song = playQueue.prev();    	
		if(song != null) {    			
       		song = playQueue.current();
       		info.put(SongMeta.FILENAME, song.getPath());
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

    
	@TargetApi(8)
	@SuppressWarnings("deprecation") // Notifications needs to be backward compatible
	@Override
	public void onCreate() {
		super.onCreate();
		
		DroidSoundPlugin.setContext(getApplicationContext());
		
		mHandler = new MyHandler(this);
		
        AudioManager audioManager = (AudioManager) getSystemService(AUDIO_SERVICE);
		player = new Player(audioManager, mHandler, getApplicationContext());
		callbacks = new ArrayList<IPlayerServiceCallback>();
		
		phoneStateListener = new PhoneStateListener() {
			
			//boolean didPause = false;
			
			@Override
			public void onCallStateChanged(int state, String incomingNumber) {
				
				callState  = state;
				switch(state) {
				case TelephonyManager.CALL_STATE_RINGING:
				case TelephonyManager.CALL_STATE_OFFHOOK:
					if(player != null && player.isPlaying()) {
						player.paused(true);
						//didPause = true;
					}
					break;
				/*case TelephonyManager.CALL_STATE_IDLE:
					if(didPause && player != null && !player.isPlaying()) {
						player.paused(false);
					}
					didPause = false;
					break; */
				}
				
				Log.d(TAG, "CALL STATE %d %s", state, incomingNumber);
				//super.onCallStateChanged(state, incomingNumber);
			}
		};
		
		TelephonyManager tm = (TelephonyManager)getSystemService(TELEPHONY_SERVICE);
		tm.listen(phoneStateListener, PhoneStateListener.LISTEN_CALL_STATE);

        mediaReceiver = new BroadcastReceiver() {        	
			private long unpluggedTime = -1;
			private int lastState = -1;

			@Override
			public void onReceive(Context context, Intent intent) {
				Log.d(TAG, "##### GOT INTENT %s", intent.getAction());
				
				if(intent.getAction().equals(Intent.ACTION_HEADSET_PLUG)) {
					int state = intent.getIntExtra("state", -1);
					
					if(lastState  != -1 && lastState != state) {					
						Log.d(TAG, "HEADSET PLUG " + state);
						if(state == 0) {						
							if(player.isPlaying()) {
								unpluggedTime = System.currentTimeMillis();
								player.paused(true);						
							}
						} else if(state == 1) {
							if(unpluggedTime > 0 && (System.currentTimeMillis() - unpluggedTime) < 5000) {
								if(!player.isPlaying()) {
									player.paused(false);						
								}							
							}
							unpluggedTime = -1;
						}
					}
					lastState = state;
				}
			}
		};
				
		IntentFilter filter = new IntentFilter();
		filter.addAction(Intent.ACTION_HEADSET_PLUG);
		registerReceiver(mediaReceiver, filter);

		ComponentName myEventReceiver = new ComponentName(getPackageName(), RemoteControlReceiver.class.getName());
		getPackageManager().setComponentEnabledSetting(myEventReceiver, PackageManager.COMPONENT_ENABLED_STATE_ENABLED, PackageManager.DONT_KILL_APP); 		

		AudioManager myAudioManager = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
		try {
			myAudioManager.registerMediaButtonEventReceiver(myEventReceiver);
		} catch (Throwable t) {
		}

		if(hasRemoteControl)
			remoteControl = new RemoteControlWrapper(this, myEventReceiver); 
		if(hasAudioFocus)
			afWrapper = new AudioFocusWrapper(this, player);
		
		notification = new Notification(R.drawable.note36, "Droidsound", System.currentTimeMillis());		
		Intent notificationIntent = new Intent(this, PlayerActivity.class);
		contentIntent = PendingIntent.getActivity(getApplicationContext(), 0, notificationIntent, 0);
	    notification.setLatestEventInfo(this, "Droidsound", "Playing", contentIntent);
	    
	    playerInterface = this;
	    
	}
	
	@SuppressWarnings("deprecation")
	void beforePlay(String name) {
		notification.setLatestEventInfo(this, "Droidsound", name, contentIntent);
		startForeground(R.string.notification, notification);
		//AudioManager am = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
		//am.requestAudioFocus(this, AudioManager.STREAM_MUSIC,  AudioManager.AUDIOFOCUS_GAIN);
		if(hasAudioFocus)
			afWrapper.requestFocus();
		
		if(hasRemoteControl)
			remoteControl.setState(RemoteControlWrapper.PLAYING);
	}
	
	void whenStopped() {
		if(hasRemoteControl)
			remoteControl.setState(RemoteControlWrapper.STOPPED);
		stopForeground(true);
		//AudioManager am = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
		//am.abandonAudioFocus(this);
		if(hasAudioFocus)
			afWrapper.abandonFocus();
	}
	
	@Override
	public int onStartCommand(Intent intent, int flags, int startId) {
		super.onStartCommand(intent, flags, startId);
		Log.d(TAG, "Service started: %x %d", flags, startId);
		if(intent != null) {
			Log.d(TAG, "Intent: %s", intent.toString());
			String action = intent.getAction();
			if(action != null)
				Log.d(TAG, "Intent %s / %s", action, intent.getDataString());
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
						String modname = (String) info.get(SongMeta.FILENAME);
						if(names != null && modname != null) {
							Log.d(TAG, "Got playlist without song");
						}
					} else {
						Log.d(TAG, "Want to play list with " + song.getPath());
						info.put(SongMeta.FILENAME, song.getPath());
						playListName = "";
						beforePlay(song.getName());
						player.playMod(song);
					}
				} else {
					Log.d(TAG, "Want to play " + intent.getDataString());
					createThread();
					playListName = "";
					//info[SongMeta.FILENAME] = uri.getLastPathSegment();
					info.put(SongMeta.FILENAME, uri.getLastPathSegment());
					SongFile song = new SongFile(intent.getDataString());
					beforePlay(song.getName());
					player.playMod(song);
				}
			}
		}
        return Service.START_STICKY_COMPATIBILITY;
	}
	
	@Override
	public void onDestroy() {
		
		super.onDestroy();
		
		//wakeLock.release();
		
		TelephonyManager tm = (TelephonyManager)getSystemService(TELEPHONY_SERVICE);
		tm.listen(phoneStateListener, 0);
		
		unregisterReceiver(mediaReceiver);
		
		player.stop();
		whenStopped();
		player = null;
		playerThread = null;
	}
	
	private final IPlayerService.Stub mBinder = new IPlayerService.Stub() {

		@Override
		public boolean playMod(String name) throws RemoteException {
			Log.d(TAG, "Playmod called " + name);
			
			createThread();
			//info[SongMeta.FILENAME] = name;
			info.put(SongMeta.FILENAME, name);
			SongFile song = new SongFile(name);
			beforePlay(song.getName());			
			player.playMod(song);
			return true;
		}

		@Override
		public void registerCallback(IPlayerServiceCallback cb, int flags) throws RemoteException {
			
			if(cb != null) {
				
				try {
					cb.update(mapToArray(info), false);
				} catch (RemoteException e1) {
					//e1.printStackTrace();
				}

				
				/*for(int i=1; i<SongMeta.SIZEOF; i++) {
					try {
						if(info[i] != null) {
							if(info[i] instanceof String) {
								cb.stringChanged(i, (String)info[i]);
							} else {
								cb.intChanged(i, (Integer)info[i]);
							}
						}
					} catch (RemoteException e) {
						Log.d(TAG, "Ignoring callback because peer is gone");
						return;
					}				
				}*/
			}
			Log.d(TAG, "Adding %s", cb.toString());
			callbacks.add(cb);			
		}

		@Override
		public void unRegisterCallback(IPlayerServiceCallback cb)
				throws RemoteException {
			
			Log.d(TAG, "Removing %s", cb.toString());
			callbacks.remove(cb);
		}

		
		@Override
		public boolean playPause(boolean play) throws RemoteException {
			if((!player.isActive() || player.isSwitching()) && play && playQueue != null) {
				SongFile s = playQueue.current();
				if(s != null) {
	           		//info[SongMeta.FILENAME] = s.getPath();
	           		info.put(SongMeta.FILENAME, s.getPath());
	           		createThread();
	    			beforePlay(s.getName());			
	           		player.playMod(s);
	           		return true;
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
			whenStopped();
	    	//userInterferred = false;
			//repeatMode = defaultRepeatMode;
			player.setLoopMode(repeatMode != RM_CONTINUE ? 1 : 0);
			// TODO: performCallback(SongMeta.REPEAT);
		}


		@Override
		public boolean seekTo(int msec) throws RemoteException {
			player.seekTo(msec);
			info.put(SongMeta.POSITION, msec);
			//performCallback(SongMeta.POS);
			
			/*if((Integer)info[SongMeta.REPEAT] == RM_CONTINUE) {
				info[SongMeta.REPEAT] = RM_KEEP_PLAYING;
				performCallback(SongMeta.REPEAT);
			} */
			return true;
		}

		@Override
		public boolean setSubSong(int song) throws RemoteException {

	    	if(playQueue == null) {
	    		return false;
	    	}
			
			// TODO : Check if next song is the same file and the same sub song
			/* boolean ok = false;
			Log.d(TAG, "Current song is " + currentSongInfo.fileName);
			SongFile nextSong = playQueue.getNextSong();			
			if(nextSong != null) {
				Log.d(TAG, "Next song is " + nextSong.getName());
				if(song == nextSong.startSong && currentSongInfo.fileName.equals(nextSong.filename)) {
					playQueue.next();
					ok = true;
				}
			}
			if(!ok) {
				nextSong = playQueue.getPrevSong();				
				if(nextSong != null) {
					Log.d(TAG, "Prev song is " + nextSong.filename);
					if(song == nextSong.startSong && currentSongInfo.fileName.equals(nextSong.filename)) {
						playQueue.prev();
						ok = true;						
					}
				}
			} */
			
			
 			player.setSubSong(song);
 			info.put(SongMeta.SUBTUNE, song);
			//info[SongMeta.SUBSONG] = (Integer)song;			
			//if((Integer)info[SongMeta.REPEAT] == RM_CONTINUE) {
			//	info[SongMeta.REPEAT] = RM_KEEP_PLAYING;
			//	performCallback(SongMeta.REPEAT);
			//}
			
			//if(ok) {
			//	info[SongMeta.FILENAME] = nextSong.filename + ";" + song;
			//	performCallback(SongMeta.FILENAME);
			//}
			
			return true;
			
		}
		
		private int BUFSIZE(double sec) {			
			return (int)(sec*44100*2) & 0xffffffe0;			
		}
		
		@Override
		public void setOption(int opt, String arg) throws RemoteException {

			boolean on = arg.equals("on");
			
			try {
				switch(opt) {
				case OPTION_CYCLE_SUBTUNES:
					cycleSubTunes  = on;
					break;
				case OPTION_DEFAULT_LENGTH:
					defaultLength  = Integer.parseInt(arg) * 1000;
					Log.d(TAG, "Default length set to " + defaultLength);
					break;
				case OPTION_REPEATMODE:
					repeatMode = Integer.parseInt(arg);
					player.setLoopMode(repeatMode != RM_CONTINUE ? 1 : 0);
					//performCallback(SongMeta.REPEAT);
					break;
				//case OPTION_SILENCE_DETECT:
				//	Log.d(TAG, "Silence detection " + arg);
				//	silenceDetect = on;
				//	break;
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
				//case OPTION_RESPECT_LENGTH:
				//	Log.d(TAG, "Respect length " + arg);
				//	respectLength = on;
				//	break;
				case OPTION_SPEECH:
					activateSpeech(on);
					break;
				case OPTION_BUFFERSIZE:
			 		bufSize = BUFSIZE(2.0);
			 		if(arg.equals("Short")) {
			 			bufSize = BUFSIZE(0.5);
			 		} else
			 		if(arg.equals("Medium")) {
			 			bufSize = BUFSIZE(1.0);
			 		} else
			 		if(arg.equals("Very Long")) {
			 			bufSize = BUFSIZE(4.0);
			 		}
			 		if(player != null)
			 			player.setBufSize(bufSize);
					break;
				}
			} catch (NumberFormatException e) {
			}
		}
		
/*
		private void shuffle() {
			String t;
			int sz = musicList.size();
			for (int i=musicListPos+1; i<sz; i++) {					
			    int randomPosition = rgen.nextInt(sz-1) + 1;
			    t = musicList.get(i);
			    musicList.set(i, musicList.get(randomPosition));
			    musicList.set(randomPosition, t);
			}
		}
		
		private void unshuffle() {
			
			musicList.clear();
			for(int i=0; i<musicNames.length; i++) {
				musicList.add(musicNames[i]);
			}
		}
*/
		@Override
		public boolean playPlaylist(String name, int startIndex) throws RemoteException {
			
			File pf = new File(name);
			Playlist pl = Playlist.getPlaylist(pf);
			playQueue = new PlayQueue(pl, startIndex, shuffleSongs);

			SongFile mod = playQueue.current();       		

			createThread();
			//info[SongMeta.FILENAME] = mod.getPath();
			info.put(SongMeta.FILENAME, mod.getPath());
			
			int dot = name.lastIndexOf('.');
			if(dot > 0) {
				name = name.substring(0, dot);
			}
			playListName = name;
						

			beforePlay(mod.getName());
			player.playMod(mod);
	    	//info[SongMeta.REPEAT] = defaultRepeatMode;
	    	//player.setLoopMode(repeatMode != RM_CONTINUE ? 1 : 0);
			//performCallback(SongMeta.SOURCE, SongMeta.REPEAT);

	    	return true;
	    	
			/*
			File pf = new File(name);
			currentPlaylist = Playlist.getPlaylist(pf);
			Log.d(TAG, "File %s is playlist %s", name, currentPlaylist.toString());
			List<File> files = currentPlaylist.getFiles();
			int i = 0;			
			for(File f : files) {
				musicNames[i] = f.getPath();
			}
			
			return playList(null, startIndex); */
		}

		@Override
		public boolean playList(String[] names, int startIndex) throws RemoteException {
			
			
			playQueue = new PlayQueue(names, startIndex, shuffleSongs);
			/*
			if(names != null) {
				musicNames = names;
			}
			musicList = new ArrayList<String>();
			
			for(int i=0; i<names.length; i++) {
				musicList.add(names[i]);
			}			
			musicListPos = startIndex;
			String name = musicList.get(startIndex);
			if(shuffleSongs) {
				shuffle();								
			} */
			SongFile song = playQueue.current();       		
			Log.d(TAG, "PlayList called " + song.getPath());
			createThread();
//			/info[SongMeta.FILENAME] = song.getPath();
			info.put(SongMeta.FILENAME, song.getPath());
			playListName = "";
			beforePlay(song.getName());
			player.playMod(song);
	    	//info[SongMeta.REPEAT] = defaultRepeatMode;
	    	//player.setLoopMode(repeatMode != RM_CONTINUE ? 1 : 0);
			//performCallback(SongMeta.REPEAT);


			return false;
		}

		@Override
		public void playNext() throws RemoteException {
			Log.d(TAG, "### PLAY NEXT");
	    	//info[SongMeta.REPEAT] = defaultRepeatMode;
	    	//player.setLoopMode(repeatMode != RM_CONTINUE ? 1 : 0);
			//performCallback(SongMeta.REPEAT);
			playNextFile();
		}

		@Override
		public void playPrev() throws RemoteException {
	    	//info[SongMeta.REPEAT] = defaultRepeatMode;
	    	//player.setLoopMode(repeatMode != RM_CONTINUE ? 1 : 0);
			//performCallback(SongMeta.REPEAT);
			playPrevFile();
		}

		@Override
		public String[] getSongInfo() throws RemoteException {

			return mapToArray(info);//currentSongInfo.details;
		}

		@Override
		public byte[] getSongMD5() throws RemoteException {

			return null;//currentmd5;
		}

		@Override
		public boolean dumpWav(String modName, String destFile, int length, int flags) throws RemoteException {
			// TODO Auto-generated method stub
			
			createThread();
			//info[SongMeta.FILENAME] = modName;
			info.put(SongMeta.FILENAME, modName);
			SongFile song = new SongFile(modName);
			//beforePlay(song.getName());			
			player.dumpWav(song, destFile, length, flags);
			
			return false;
		}

		};

	
    @Override
    public IBinder onBind(Intent intent) {
    	Log.d(TAG, "BOUND");
    	return mBinder;
    }
    
    protected void activateSpeech(boolean on) {
    	if(on) {
			if(textToSpeech == null) {
				Log.d(TAG, "Turning on speech");
				textToSpeech = new TextToSpeech(getApplicationContext(), new TextToSpeech.OnInitListener() {
					@Override
					public void onInit(int status) {					
						ttsStatus = status;
						if(saySomething != null && textToSpeech != null) {
							textToSpeech.speak(saySomething, TextToSpeech.QUEUE_FLUSH, null);
							saySomething = null;
						}
							
					}
				});
				textToSpeech.setLanguage(Locale.US);
			}
		} else {
			if(textToSpeech != null) {
				textToSpeech.shutdown();
				textToSpeech = null;
				ttsStatus = -1;
				Log.d(TAG, "Turning off speech");
			}
		}
    }
   
	@Override
    public boolean onUnbind(Intent intent) {
    	Log.d(TAG, "UNBOUND");
    	return super.onUnbind(intent);
    }

	@Override
	public boolean isActive() {
		return player.isActive();
	}

	@Override
	public void stop() {
		player.stop();
		whenStopped();
		
	}

	@Override
	public boolean isPlaying() {
		return player.isPlaying();
	}

	@Override
	public void paused(boolean b) {
		
		if(hasRemoteControl)
			remoteControl.setState(b ? RemoteControlWrapper.PAUSED : RemoteControlWrapper.PLAYING);		
		player.paused(b);		
	}

	@Override
	public void speechOnOff() {
		if(textToSpeech == null) {
			speakTitle();
			activateSpeech(true);									
		} else {
			textToSpeech.speak("Speech off.", TextToSpeech.QUEUE_FLUSH, null);
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			activateSpeech(false);
		} 
	}

	@Override
	public int getCallState() {
		return callState;
	}
	
	
	private String [] mapToArray(Map<String, Object> m) {
		
		String [] s = new String [m.size() * 3];
		
		int i = 0;
		for(Entry<String, Object> e: m.entrySet()) {
			String t = "";
			String v = "";
			Object val = e.getValue();
			if(val instanceof String []) {
				t = "A";
				StringBuilder sb = new StringBuilder();
				for(String si : (String [])e.getValue()) {
					sb.append(si).append("\n");
				}
				v = sb.toString();
			} else if(val instanceof Integer || val instanceof Long) {
				t = "I";
				v = String.valueOf(e.getValue());
			} else if(val instanceof Boolean) {
				t = "B";
				v = String.valueOf(e.getValue());
			} else {
				t = "S";
				v = (String) e.getValue();
			}
			s[i++] = t;
			s[i++] = e.getKey();
			s[i++] = v;
		}
		return s;
	}
}
