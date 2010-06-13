package com.ssb.droidsound;

import java.io.File;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import android.app.Service;
import android.content.Intent;
import android.media.AudioManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.os.RemoteException;
import android.util.Log;

public class PlayerService extends Service {
	
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
	
	private Object info[];

	protected String[] musicList;
	protected int musicListPos;
    	
	private static final String TAG = "Test";
	private Player player;
	private Thread playerThread;
	private List<IPlayerServiceCallback> callbacks; 	
	
	private void performCallback(int...what) {
		Iterator<IPlayerServiceCallback> it = callbacks.iterator();
		while(it.hasNext()) {
			IPlayerServiceCallback cb = it.next();
			for(int i : what) {
				//if(info[i] != null) {
					try {
						if(info[i] instanceof String) {
							cb.stringChanged(i, (String)info[i]);
						} else if(info[i] == null) {
							cb.stringChanged(i, (String)info[i]);
						} else {
							cb.intChanged(i, (Integer)info[i]);
						}
					} catch (RemoteException e) {
						Log.v(TAG, "Removing callback becuase peer is gone");
						it.remove();
					}
				//}
			}
		}
	}

	
    private Handler mHandler = new Handler() {
		@Override
        public void handleMessage(Message msg) {
        	//Log.v(TAG, String.format("Got msg %d with arg %s", msg.what, (String)msg.obj));
            switch (msg.what) {
                case 0:
                	String text [] = (String [])msg.obj;
                	if(text[0] == null || text[0].length() == 0) {
                		File f = new File((String)info[SONG_FILENAME]);                	
                		info[SONG_TITLE] = f.getName();
                	} else {
                		info[SONG_TITLE] = text[0];
                	}
					info[SONG_AUTHOR] = text[1];
					info[SONG_COPYRIGHT] = text[2];
					info[SONG_FORMAT] = text[3];
					info[SONG_LENGTH] = (Integer)msg.arg1;
					info[SONG_TOTALSONGS] = (Integer)(msg.arg2 & 0xffff);
					info[SONG_SUBSONG] = (Integer)(msg.arg2>>16);
					performCallback(SONG_FILENAME, SONG_AUTHOR, SONG_TITLE, SONG_LENGTH, SONG_SUBSONG, SONG_TOTALSONGS);
                	break;
                case 1:
                	Log.v(TAG, "Music done");
                	playNextSong();
                    break;
                case 3:
                	info[SONG_POS] = (Integer)msg.arg1;
                	performCallback(SONG_POS);
    				break;
                default:
                    super.handleMessage(msg);
            }
        }

    };
	
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
		
		Log.v(TAG, "PlayerService created");
	}
	
	@Override
	public void onStart(Intent intent, int startId) {
		super.onStart(intent, startId);
		Log.v(TAG, "Service started");
		
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
		
	}
	
	@Override
	public void onDestroy() {
		
		super.onDestroy();
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
			callbacks.add(cb);
			// TODO Auto-generated method stub			
		}

		@Override
		public boolean playPause(boolean play) throws RemoteException {
			// TODO Auto-generated method stub
			if(player.isActive()) {
				player.paused(!play);
				return true;
			}
			return false;
		}

		@Override
		public void stop() throws RemoteException {
			// TODO Auto-generated method stub
			player.stop();			
		}


		@Override
		public boolean seekTo(int msec) throws RemoteException {
			// TODO Auto-generated method stub
			player.seekTo(msec);
			info[SONG_POS] = msec;
			performCallback(SONG_POS);
			return true;
		}

		@Override
		public boolean setSubSong(int song) throws RemoteException {
			// TODO Auto-generated method stub
			player.setSubSong(song);
			info[SONG_SUBSONG] = (Integer)song;
			performCallback(SONG_SUBSONG);
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
			return false;
		}

		@Override
		public void playNext() throws RemoteException {
			playNextSong();
		}

		@Override
		public void playPrev() throws RemoteException {
			playPrevSong();
		}
	};
	
    @Override
    public IBinder onBind(Intent intent) {
    	return mBinder;
    }
}
