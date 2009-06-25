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

public class Player implements Runnable, OnClickListener, OnPlaybackPositionUpdateListener{

	private static final String TAG = "Player";
	private short [] samples;
	private ModPlugin modPlugin;
	
	private String modToPlay;
	private AudioManager audioManager;
	private String modName;
	private AudioTrack audioTrack;
	private int bufSize;
	private boolean doStop;
	
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
         
        Log.v(TAG, "Instanciating ModPlugin");
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
				Log.w(TAG, "Could not load music");
				// TODO Auto-generated catch block
				//e.printStackTrace();
			}
			
			if(songBuffer != null) {
				modPlugin.load(songBuffer, (int) fileSize);
			}
			
			samples = new short [bufSize/2];
	
			for(int i=0; i<bufSize/2; i++) {
				samples[i] = (short)(Math.sin(i*2*Math.PI / 327.68) * 32767);
			}
			
			//songBuffer = null;

			if(songBuffer != null) {
				
				Log.w(TAG, "Modname is " + modPlugin.getSongName());
				
				int rc = 1;
				audioTrack.play();				
				//while(rc > 0) {
				rc = modPlugin.getSoundData(samples, bufSize/2);
				audioTrack.write(samples, 0, rc);
				//}
				return;
			}	
			audioTrack.play();			
			int rc = audioTrack.write(samples, 0, bufSize/2);
			audioTrack.flush();
			
			state = audioTrack.getPlayState();
        }
    }

	@Override
	public void onPeriodicNotification(AudioTrack track) {
		
		int frames = track.getPositionNotificationPeriod();
		Log.v(TAG, "Writing data in thread " + Thread.currentThread().getId());
		int rc = modPlugin.getSoundData(samples, frames*2);
		if(rc <= 0) {
			track.stop();
		} else {
			track.write(samples, 0, rc);
		}
	}

	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub		
	}


	@Override
	public void run() {

		modPlugin = new ModPlugin();
		doStop = false;
		
		
		bufSize = AudioTrack.getMinBufferSize(44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT);
		if(bufSize < 32768*4) {
			bufSize = 32768*8;
		}
		audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, 44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);

		Log.v(TAG, "AudioTrack created in thread " + Thread.currentThread().getId());
		
		
		audioTrack.setPositionNotificationPeriod(32768);
		audioTrack.setPlaybackPositionUpdateListener(this);

		
		// TODO Auto-generated method stub
		while(true) {
			try {
				boolean doPlay = false;
				synchronized (this) {
					if(modToPlay != null)
						doPlay = true;
				}
				if(doPlay)
					startMod();
				
				if(doStop) {
					audioTrack.stop();
					doStop = false;
				}
				//Thread.yield();
				Thread.sleep(100);				
				
			} catch (InterruptedException e) {
				return;
			}
		}
		
	}


	@Override
	public void onMarkerReached(AudioTrack track) {
		// TODO Auto-generated method stub
		Log.v(TAG, "Marker reached");
	}

	public void stop() {
		
		doStop = true;
		
		// TODO Auto-generated method stub
		
	}

}
