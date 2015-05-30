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
import android.support.v4.app.NotificationCompat;
import android.support.v4.app.NotificationCompat.Builder;
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
	public static final int OPTION_REPEATSONG = 4;
	public static final int OPTION_DEFAULT_LENGTH = 6;
	public static final int OPTION_CYCLE_SUBTUNES = 7;

	private Map<String, Object> info = new HashMap<String, Object>();
    	
	private static PlayerInterface playerInterface;
	private Player player;
	private Thread playerThread;
	private List<IPlayerServiceCallback> callbacks; 	

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
	//private int repeatMode = RM_CONTINUE;
	private boolean repeatSong = false;
	//private boolean holdSong = false;

	protected String saySomething;

	
	PlayQueue playQueue;
	
	private TextToSpeech textToSpeech;
	private int ttsStatus = -1;
	
	private boolean cycleSubTunes = false;
	
	private PendingIntent contentIntent;
	protected int bufSize = 0x40000;
	protected int defaultLength = 60*15*1000;
	protected String playListName;
	protected int callState = TelephonyManager.CALL_STATE_IDLE;
	private Builder notificationBuilder;


	
	public static PlayerInterface getPlayerInterface() {
		return playerInterface;
	}
	
	private void updateInfo(boolean newsong) {
		
		HashMap<String, Object> changed = new HashMap<String, Object>();
		
		if(newsong)
			info.clear();
		
		
		
		Map<String, Object> newInfo = new HashMap<String, Object>();
		player.getSongDetails(newInfo);
		
		newInfo.put(SongMeta.SHUFFLE, (Boolean)shuffleSongs);
		newInfo.put(SongMeta.REPEAT, (Boolean)repeatSong);
		
		for(Entry<String, Object> e : newInfo.entrySet()) {
			String key = e.getKey();
			Object oldVal = info.get(key);			
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
		
		if(newsong)
			sendUpdates(info, newsong);
		else
			sendUpdates(changed, newsong);
		
	}
		
	
	private void sendUpdates(Map<String, Object> info, boolean newsong) {

		String [] updates = mapToArray(info);

		if(updates.length == 0)
			return;

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

	final static String stripChars = "[]!<>?#${}'"; 
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
		ct.put("GLENN RUNE GALLEFOSS", "Glen Runey Gallefoss");
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
			String a = sb.toString().toUpperCase(Locale.ENGLISH);
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
		if(songTitle == null) songTitle = "Unknown song";
		
		
		songComposer = fixSpeech(songComposer, true);

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
		private boolean musicEnded;

		public MyHandler(PlayerService ps) {
			psRef = new WeakReference<PlayerService>(ps);
			musicEnded = false;
		}
		
		@Override
		public void handleMessage(Message msg) {
			PlayerService ps = psRef.get();
			switch (msg.what) {
			case Player.MSG_WAVDUMPED:
				ps.info.put(SongMeta.FILENAME, msg.obj);
				//ps.updateInfo(false);
				ps.sendUpdates(ps.info, false);
				ps.info.put(SongMeta.FILENAME, null);
				break;
			case Player.MSG_RESTART:
				musicEnded = false;
				break;
			case Player.MSG_SUBTUNE:
				musicEnded = false;
			case Player.MSG_DETAILS:
				ps.updateInfo(false);
				break;
			case Player.MSG_FAILED:
				// ps.info[SongMeta.STATE] = 0;
				// ps.info[SongMeta.ERROR] = ERR_SONG.COULD_NOT_PLAY;
				// ps.performCallback(SongMeta.FILENAME, SongMeta.TITLE,
				// SongMeta.ERROR);
				// ps.info[SongMeta.ERROR] = 0;
				break;
			case Player.MSG_NEWSONG:
				musicEnded = false;
				ps.updateInfo(true);
				break;
			case Player.MSG_SILENT:
				if(musicEnded)
					break;
				if(msg.arg1 > 4000) {
					musicEnded = true;
					if(ps.repeatSong) {
						ps.repeatSong();
					} else {
						ps.playNextSong();
					}
				}
				break;
			case Player.MSG_DONE:
				if(musicEnded)
					break;
				Log.d(TAG, "Music done");
				musicEnded = true;
				if(ps.repeatSong) {
					ps.repeatSong();
				} else {
					ps.playNextSong();
				}
				break;

			case Player.MSG_PROGRESS:
				ps.updateInfo(false);
				break;

			case Player.MSG_STATE:

				int state = (Integer) msg.arg1;
				if (state == 0) {
					ps.updateInfo(true);
				} else
					ps.updateInfo(false);
				break;
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
		    playerThread = new Thread(player, "Player");
		    playerThread.setPriority(Thread.NORM_PRIORITY+1);
		    playerThread.start();
    	}
    }
        
    public void repeatSong() {
    	player.repeatSong();
    }

    public boolean playNextSong(int skips) {
    	
    	if(cycleSubTunes) {
	    	int next = (Integer) info.get(SongMeta.SUBTUNE) + skips;
	    	if(next < (Integer) info.get(SongMeta.TOTAL_SUBTUNES)) {
	        	player.setSubSong(next);
	    		return true;
	    	}
    	}
    	
    	boolean rc = true;
    	while(rc && skips > 0) {
    		rc = playNextFile();
    		skips--;
    	}
    	return rc;
    }
    
    public boolean playNextSong() {
    	return playNextSong(1);
    }
    
    public boolean playPrevSong(int skips) {
    	
    	if(cycleSubTunes) {
    		int next = (Integer)info.get(SongMeta.SUBTUNE) - skips;
	    	if(next >= 0) {
	        	player.setSubSong(next);
	    		return true;
	    	}
    	}
    	boolean rc = true;
    	while(rc && skips > 0) {
    		rc = playPrevFile();
    		skips--;
    	}
    	return rc;
    }

    public boolean playPrevSong() {
    	return playPrevSong(1);
    }
    
    public boolean playNextFile() {
    	
    	if(playQueue == null) {
    		return false;
    	}
    	SongFile song = playQueue.next();
    	
		if(song != null) {    			
       		song = playQueue.current();       		
       		createThread();

       		beforePlay(song.getFullTitle());
       		player.playMod(song);
       		return true;
    	}
		return false;
    }

   
   public boolean playPrevFile() {
	   
    	if(playQueue == null) {
    		return false;
    	}
    	SongFile song = playQueue.prev();    	
		if(song != null) {    			
       		song = playQueue.current();
       		//info.put(SongMeta.FILENAME, song.getPath());
       		createThread();
       		beforePlay(song.getFullTitle());
       		player.playMod(song);
       		return true;
    	}
		return false;
    }
    
	@TargetApi(8)
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
								player.paused(true, this);
							}
						} else if(state == 1) {
							if(unpluggedTime > 0 && (System.currentTimeMillis() - unpluggedTime) < 5000) {
								if(player.pausedBy(this)) {
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

		notificationBuilder = new NotificationCompat.Builder(this).setSmallIcon(R.drawable.note36).setContentTitle("Droidsound").setContentText("");

		Intent notificationIntent = new Intent(this, PlayerActivity.class);		
		contentIntent = PendingIntent.getActivity(getApplicationContext(), 0, notificationIntent, 0);
		notificationBuilder.setContentIntent(contentIntent);		

	    playerInterface = this;
	    
	}

	void beforePlay(String name) {

		notificationBuilder.setContentText(name);
		Notification notification = notificationBuilder.build();		
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
						//info.put(SongMeta.FILENAME, song.getPath());
						playListName = "";
						beforePlay(song.getFullTitle());
						player.playMod(song);
					}
				} else {
					Log.d(TAG, "Want to play " + intent.getDataString());
					createThread();
					playListName = "";
					//info[SongMeta.FILENAME] = uri.getLastPathSegment();
					//info.put(SongMeta.FILENAME, uri.getLastPathSegment());
					SongFile song = new SongFile(intent.getDataString());
					beforePlay(song.getFullTitle());
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
			//info.put(SongMeta.FILENAME, name);
			SongFile song = new SongFile(name);
			beforePlay(song.getFullTitle());			
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
	           		//info.put(SongMeta.FILENAME, s.getPath());
	           		createThread();
	    			beforePlay(s.getFullTitle());			
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
		}


		@Override
		public boolean seekTo(int msec) throws RemoteException {
			player.seekTo(msec);
			return true;
		}

		@Override
		public boolean setSubSong(int song) throws RemoteException {

	    	if(playQueue == null) {
	    		return false;
	    	}
 			player.setSubSong(song);
			return true;
			
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
				case OPTION_REPEATSONG:
					repeatSong = Boolean.parseBoolean(arg);
					player.setLoopMode(repeatSong ? 1 : 0);
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
			
			int dot = name.lastIndexOf('.');
			if(dot > 0) {
				name = name.substring(0, dot);
			}
			playListName = name;
						

			beforePlay(mod.getFullTitle());
			player.playMod(mod);

	    	return true;
		}

		@Override
		public boolean playList(String[] names, int startIndex) throws RemoteException {
			
			
			playQueue = new PlayQueue(names, startIndex, shuffleSongs);
			SongFile song = playQueue.current();       		
			Log.d(TAG, "PlayList called " + song.getPath());
			createThread();
			playListName = "";
			beforePlay(song.getFullTitle());
			player.playMod(song);
			return false;
		}

		@Override
		public void playNext() throws RemoteException {
			Log.d(TAG, "### PLAY NEXT");
			playNextFile();
		}

		@Override
		public void playPrev() throws RemoteException {
			playPrevFile();
		}

		@Override
		public String[] getSongInfo() throws RemoteException {

			return mapToArray(info);//currentSongInfo.details;
		}

		@Override
		public byte[] getBinaryData(int what) throws RemoteException {			
			return player.getBinaryInfo(what);
		}

		@Override
		public boolean dumpWav(String modName, String destFile, int length, int flags) throws RemoteException {
			// TODO Auto-generated method stub
			
			createThread();
			info.put(SongMeta.FILENAME, modName);
			SongFile song = new SongFile(modName);
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
