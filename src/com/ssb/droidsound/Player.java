package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

import android.content.Context;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.media.AudioTrack.OnPlaybackPositionUpdateListener;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;

public class Player implements Runnable {

	private static final String TAG = "Player";
	private short [] samples;
	private ModPlugin modPlugin;
	
	private String modToPlay;
	private AudioManager audioManager;
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
	private boolean setPaused;
	
	synchronized void playMod(String mod) {
		modToPlay = mod;
	}
	
	public Player(AudioManager am) {
		audioManager = am;
	}

    public void startMod() {
    	
    	synchronized (this) {
    		modName = modToPlay;
    		modToPlay = null;
		}

        boolean ok = modPlugin.canHandle("test");
        
        
        if(ok)
        {
            Log.v(TAG, "CanHandle OK");
	        
	        int volume = audioManager.getStreamVolume(AudioManager.STREAM_MUSIC);
	        volume = audioManager.getStreamMaxVolume(AudioManager.STREAM_MUSIC);
	        
	        audioManager.setStreamVolume(AudioManager.STREAM_MUSIC, 6, 0);
	  
			int state = audioTrack.getState();
			
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
				modPlugin.load(songBuffer, (int) fileSize);
			}
			
			samples = new short [bufSize/2];

			if(songBuffer != null) {
				Log.w(TAG, "HERE WE GO");
				synchronized (this) {
					Log.w(TAG, "HERE WE GO");
					moduleLength = modPlugin.getIntInfo(modPlugin.INFO_LENGTH);
					Log.w(TAG, "LENGTH IS " + moduleLength);
					moduleTitle = modPlugin.getStringInfo(modPlugin.INFO_TITLE);
					Log.w(TAG, "HERE WE GO");
					//moduleAuthor = modPlugin.getStringInfo(modPlugin.INFO_AUTHOR);
				}
				Log.w(TAG, "Modname is " + moduleTitle);
				audioTrack.play();				
				playing = true;

			}	
        }
    }

	@Override
	public void run() {

		modPlugin = new ModPlugin();
		doStop = false;
		playing = false;
		seekTo = -1;
		
		bufSize = AudioTrack.getMinBufferSize(44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT);
		if(bufSize < 32768*4) {
			bufSize = 32768*4;
		}
		audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, 44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);

		Log.v(TAG, "AudioTrack created in thread " + Thread.currentThread().getId());
		

		while(true) {
			try {
				boolean doPlay = false;
				synchronized (this) {
					if(modToPlay != null)
						doPlay = true;
				}
				if(doPlay) {
					if(playing) {
						audioTrack.stop();
						modPlugin.unload();
					}
					playing = false;
					startMod();
				}
				
				if(doStop) {
					if(playing) {
						audioTrack.stop();
						modPlugin.unload();
					}
					audioTrack.stop();
					doStop = false;
					playing = false;
				}
				
				if(seekTo >= 0) {
					if(modPlugin.seekTo(seekTo)) {
						currentPosition = seekTo;
					}
					seekTo = -1;
				}

				if(playing) {
					int rc = modPlugin.getSoundData(samples, bufSize/2);
					//synchronized (this) {
						currentPosition += ((rc * 1000) / 88200);
					//}
					audioTrack.write(samples, 0, rc);
				}

				Thread.sleep(100);				
				
			} catch (InterruptedException e) {
				return;
			}
		}
		
	}
	
	synchronized int getPosition() {
		return currentPosition;
	}
	
	synchronized int getLength() {
		return moduleLength;
	}


	public void stop() {		
		doStop = true;
	}
	
	public void paused(boolean pause) {
		setPaused = pause;
	}

	public void seekTo(int pos) {
		// TODO Auto-generated method stub
		seekTo = pos;		
	}

}
