package com.ssb.droidsound.service;

import java.io.File;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

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
import android.telephony.PhoneStateListener;
import android.telephony.TelephonyManager;
import android.util.Log;

public class PlayerService extends Service {
	private static final String TAG = "PlayerService";
	
	// Flags
	
	public static final int FLAG_CONTINUOUS = 1;
	public static final int FLAG_SHUFFLE = 2;
	public static final int FLAG_REPEAT = 4;
	
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
	
	private Object info[];

	protected String[] musicList;
	protected int musicListPos;
    	
	private Player player;
	private Thread playerThread;
	private List<IPlayerServiceCallback> callbacks; 	

	private SongInfo currentSongInfo = new SongInfo();
	
	private boolean userInterferred;
	
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

	
    private Handler mHandler = new Handler() {

		@Override
        public void handleMessage(Message msg) {
        	//Log.v(TAG, String.format("Got msg %d with arg %s", msg.what, (String)msg.obj));
            switch (msg.what) {
                case Player.MSG_NEWSONG:
                	
                	player.getSongInfo(currentSongInfo);
                	if(currentSongInfo.title == null || currentSongInfo.title.length() == 0) {
                		File f = new File((String)info[SONG_FILENAME]);                	
                		info[SONG_TITLE] = f.getName();
                	}

                	info[SONG_TITLE] = currentSongInfo.title;
					info[SONG_AUTHOR] = currentSongInfo.author;
					info[SONG_COPYRIGHT] = currentSongInfo.copyright;
					info[SONG_FORMAT] = currentSongInfo.type;
					info[SONG_LENGTH] = currentSongInfo.length;
					info[SONG_TOTALSONGS] = currentSongInfo.subTunes;
					info[SONG_SUBSONG] = currentSongInfo.startTune;
					info[SONG_GAMENAME] = currentSongInfo.game;
					info[SONG_STATE] = 1;
					performCallback(SONG_FILENAME, SONG_AUTHOR, SONG_TITLE, SONG_COPYRIGHT, SONG_GAMENAME, SONG_LENGTH, SONG_SUBSONG, SONG_TOTALSONGS, SONG_STATE);
                	break;
                case Player.MSG_DONE:
                	Log.v(TAG, "Music done");
                	playNextSong();
                    break;
                case Player.MSG_PROGRESS:
                	info[SONG_POS] = (Integer)msg.arg1;
                	performCallback(SONG_POS);
    				break;
                case Player.MSG_STATE:
                	info[SONG_STATE] = (Integer)msg.arg1;
                	performCallback(SONG_STATE);
                	break;
                case Player.MSG_SILENT:
                	if(!userInterferred)
                		playNextSong();
                	else
                		Log.v(TAG, "User has interferred, not switching");
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
           		info[SONG_FILENAME] = musicList[musicListPos];
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
           		info[SONG_FILENAME] = musicList[musicListPos];
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
		player = new Player(audioManager, mHandler);
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
				if(f == null) {
					if(musicListPos >= 0) {
						f = musicList[musicListPos];
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
				musicList[musicListPos] = name;
			}
			
			createThread();
			info[SONG_FILENAME] = name;
			player.playMod(name);
			
			return true;
		}

		@Override
		public void registerCallback(IPlayerServiceCallback cb, int flags) throws RemoteException {
			
			if(cb != null) {
				for(int i=0; i<10; i++) {
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
			if(player.isActive()) {
				player.paused(!play);
				return true;
			}
			return false;
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
			performCallback(SONG_SUBSONG);
			userInterferred = true;
			return true;
			
		}

		@Override
		public void setFlags(int flags) throws RemoteException {
			// TODO Auto-generated method stub			
		}

		@Override
		public boolean playList(String[] names, int startIndex) throws RemoteException {
			musicList = names;
			musicListPos = startIndex;
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
