package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

public class Player implements Runnable {

	private static final String TAG = "Player";
	private short [] samples;
	private DroidSoundPlugin currentPlugin;
	
	private DroidSoundPlugin [] plugins;
	
	private String modToPlay;
	private String modName;
	private AudioTrack audioTrack;
	private int bufSize;
	private boolean doStop;
	private boolean playing;
	private int currentPosition;
	private int moduleLength;
	private String moduleTitle;
	private String moduleAuthor;
	private int seekTo;
	private Handler mHandler;
	private int noPlayWait;
	private int lastPos;
	private boolean setPaused;
		
	public Player(AudioManager am, Handler handler) {
		mHandler = handler;
		plugins = new DroidSoundPlugin [1];
		plugins[0] = new ModPlugin();

		bufSize = AudioTrack.getMinBufferSize(44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT);
		if(bufSize < 32768*4) {
			bufSize = 32768*4;
		}
		
		samples = new short [bufSize/2];
	}

    public void startMod() {
    	
    	synchronized (this) {
    		modName = modToPlay;
    		modToPlay = null;
		}
    	
    	currentPlugin = null;
    	for(int i=0; i< plugins.length; i++) {
    		if(plugins[i].canHandle(modName)) {    			
    			currentPlugin = plugins[i];
    			break;
    		}
    	}
                
        if(currentPlugin != null)
        {
            Log.v(TAG, "CanHandle OK");
	        
	        //int volume = audioManager.getStreamVolume(AudioManager.STREAM_MUSIC);
	        //volume = audioManager.getStreamMaxVolume(AudioManager.STREAM_MUSIC);
	        //audioManager.setStreamVolume(AudioManager.STREAM_MUSIC, 6, 0);
	  
			//int state = audioTrack.getState();
			
			byte [] songBuffer = null;
			long fileSize = 0;
			
			try {
				//File f = new File(Environment.getExternalStorageDirectory()+"/" + modName);
				File f = new File(modName);
				fileSize = f.length();
				songBuffer = new byte [(int) fileSize];
				FileInputStream fs = new FileInputStream(f);
				fs.read(songBuffer);
			} catch (IOException e) {
				Log.w(TAG, "Could not load music!");
				// TODO Auto-generated catch block
				//e.printStackTrace();
			}
			
			if(songBuffer != null) {
				currentPlugin.load(songBuffer, (int) fileSize);
			}

			if(songBuffer != null) {
				Log.w(TAG, "HERE WE GO");
				synchronized (this) {
					moduleLength = currentPlugin.getIntInfo(DroidSoundPlugin.INFO_LENGTH);
					moduleTitle = currentPlugin.getStringInfo(DroidSoundPlugin.INFO_TITLE);
					if(moduleTitle == null)
						moduleTitle = "Unknown";
					moduleAuthor = currentPlugin.getStringInfo(DroidSoundPlugin.INFO_AUTHOR);
					if(moduleAuthor == null)
						moduleAuthor = "Unknown";
					
					Message msg = mHandler.obtainMessage();
					msg.what = 0;
					msg.arg1 = moduleLength;
					msg.obj = moduleTitle;
					mHandler.sendMessage(msg);
				}
				Log.w(TAG, "Modname is " + moduleTitle);
				audioTrack.play();				
				playing = true;

			}	
        }
    }

	@Override
	public void run() {

		currentPlugin = null;

		doStop = false;
		playing = false;
		seekTo = -1;

		audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, 44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);

		Log.v(TAG, "AudioTrack created in thread " + Thread.currentThread().getId());
		noPlayWait = 0;

		while(noPlayWait < 50) {
			try {
				boolean doPlay = false;

				synchronized (this) {
					if(modToPlay != null)
						doPlay = true;
				}

				if(doPlay) {
					if(playing) {
						audioTrack.stop();
						currentPlugin.unload();
					}
					playing = false;
					startMod();
					currentPosition = lastPos = 0;
				}
				
				if(doStop) {
					if(playing) {
						audioTrack.stop();
						currentPlugin.unload();
					}
					audioTrack.stop();
					doStop = false;
					playing = false;
					currentPosition = lastPos = 0;
				}
				

				if(playing) {
					
					if(!setPaused) {
						noPlayWait = 0;
						if(seekTo >= 0) {
							if(currentPlugin.seekTo(seekTo)) {
								currentPosition = lastPos = seekTo;
							}
							seekTo = -1;
						}
	
						int rc = currentPlugin.getSoundData(samples, bufSize/8);
						//synchronized (this) {
							currentPosition += ((rc * 1000) / 88200);
							
							if(currentPosition >= lastPos + 1000) {
								Message msg = mHandler.obtainMessage();
								msg.what = PlayerService.SONG_POS;
								msg.arg1 = currentPosition;
								mHandler.sendMessage(msg);
								lastPos = currentPosition;
							}
							
						//}
						if(rc > 0) {
							audioTrack.write(samples, 0, rc);
						} else {
							playing = false;
							Message msg = mHandler.obtainMessage();
							msg.what = 1;
							mHandler.sendMessage(msg);
						}
					}
				} else {
					noPlayWait++;
				}

				Thread.sleep(100);				
				
			} catch (InterruptedException e) {
				break;
			}
		}
		
		audioTrack.release();
		audioTrack = null;
		Log.v(TAG, "Player Thread exiting due to inactivity");
		
	}
	
	synchronized int getPosition() {
		return currentPosition;
	}
	
	synchronized int getLength() {
		return moduleLength;
	}
	
	synchronized String getTitle() {
		return moduleTitle;
	}

	synchronized String getAuthor() {
		return moduleAuthor;
	}

	synchronized public void stop() {		
		doStop = true;
	}
	
	synchronized public void paused(boolean pause) {
		setPaused = pause;
	}

	synchronized public void seekTo(int pos) {
		seekTo = pos;		
	}

	synchronized void playMod(String mod) {
		modToPlay = mod;
	}

}
