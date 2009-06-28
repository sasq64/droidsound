package com.ssb.droidsound;

import java.io.File;

import android.app.Service;
import android.content.Intent;
import android.content.ServiceConnection;
import android.media.AudioManager;
import android.os.Environment;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.os.RemoteException;
import android.util.Log;
import android.widget.MediaController;

public class PlayerService extends Service {

	private static final String TAG = "Test";
	private Player player;
	private Thread playerThread;
	private IPlayerServiceCallback callback; 	
	private String currentMod;
    private int currentPos;
	private int songLength;
	
	public static final int SONG_POS = 5;
	public static final int SONG_FILENAME = 6;
	public static final int SONG_LENGTH = 7;

	
    private Handler mHandler = new Handler() {
		@Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                	Log.v(TAG, String.format("Got msg %d with arg %s", msg.what, (String)msg.obj));
                	if(callback != null) {
                		try {
							callback.stringChanged(DroidSoundPlugin.INFO_TITLE, (String)msg.obj);
							callback.intChanged(DroidSoundPlugin.INFO_LENGTH, msg.arg1);
							songLength = msg.arg1;
						} catch (RemoteException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
                	}
                	break;
                case 1:
                	Log.v(TAG, "Music done");
                	String next = playNext();
                	if(next != null) {
                		currentMod = next;
                		player.playMod(next);
                	}
                    break;
                case SONG_POS:
    		        try {
    					callback.intChanged(SONG_POS, msg.arg1);
    					currentPos = msg.arg1;
    					Log.v(TAG, "Music at " + msg.arg1);
    				} catch (RemoteException e) {
    					// TODO Auto-generated catch block
    					e.printStackTrace();
    				}
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

    String playNext() {
    	
    	File modDir = new File(currentMod).getParentFile();    	
    	File [] files = modDir.listFiles();
    	
    	if(files.length <= 0)
    		return null;

    	boolean getNext = false;
    	for(File f : files) {
    		if(getNext) {
    			return f.getPath();
    		}
        	Log.v(TAG, String.format("Comparing %s to %s", f.getPath(), currentMod));
    		if(f.getPath().compareToIgnoreCase(currentMod) == 0) {
    			getNext = true;
    		}
    	}
    	
    	if(getNext)
    		return null;
    	else
    		return files[0].getPath();
    }

	
	@Override
	public void onCreate() {
		super.onCreate();
		
		Log.v(TAG, "Creating player from thread " + Thread.currentThread().getId());
        AudioManager audioManager = (AudioManager) getSystemService(AUDIO_SERVICE);
		player = new Player(audioManager, mHandler);
	}
	
	@Override
	public void onDestroy() {
		
		super.onDestroy();
		player.stop();
		player = null;
		playerThread = null;
	}
	
	public Player getPlayer() {
		return player;
	}

	private final IPlayerService.Stub mBinder = new IPlayerService.Stub() {

		@Override
		public void playMod(String name) throws RemoteException {
			Log.v(TAG, "Playmod called " + name);
			createThread();
			currentMod = name;
			player.playMod(name);
			
			if(callback != null) {
		        try {
					callback.stringChanged(99, "hello");
				} catch (RemoteException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}

		}

		@Override
		public void registerCallback(IPlayerServiceCallback cb, int flags)
				throws RemoteException {
			callback = cb;
			// TODO Auto-generated method stub
			
		}

		@Override
		public int getIntValue(int what) throws RemoteException {
			switch(what) {
			case SONG_LENGTH:
				return songLength;
			case SONG_POS:
				return currentPos;
			}
			return -1;
		}

		@Override
		public String getStringValue(int what) throws RemoteException {
			switch(what) {
			case SONG_FILENAME:
				return currentMod;
			}
			return null;
		}

		@Override
		public void playPause(boolean play) throws RemoteException {
			// TODO Auto-generated method stub
			player.paused(!play);
		}

		@Override
		public void stop() throws RemoteException {
			// TODO Auto-generated method stub
			player.stop();			
		}

		@Override
		public void playList(String fileName) throws RemoteException {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void seekTo(int msec) throws RemoteException {
			// TODO Auto-generated method stub
			player.seekTo(msec);
			
		}
	};
	
    @Override
    public IBinder onBind(Intent intent) {
    	return mBinder;
    }
}
