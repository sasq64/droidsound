package com.ssb.droidsound;

import android.app.Activity;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.os.Bundle;

public class DroidSound extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        AudioManager audioManager = (AudioManager) getSystemService(AUDIO_SERVICE);
        
        ModPlugin mp = new ModPlugin();
        boolean ok = mp.canHandle("test");
        
        if(ok)
        {
	        
	        int volume = audioManager.getStreamVolume(AudioManager.STREAM_MUSIC);
	        
	        audioManager.setStreamVolume(AudioManager.STREAM_MUSIC, audioManager.getStreamMaxVolume(AudioManager.STREAM_MUSIC), 0);
	        
			int bufSize = AudioTrack.getMinBufferSize(44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT);
			if(bufSize < 32768*4) {
				bufSize = 32768*4;
			}
			AudioTrack audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, 44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);
			 
			int state = audioTrack.getState();
			
			short [] samples = new short [bufSize/2];
			
			for(int i=0; i<bufSize/2; i++) {
				samples[i] = (short)(Math.sin(i*2*Math.PI / 327.67) * 32767);
			}
			
			int rc = audioTrack.write(samples, 0, bufSize/2);
			audioTrack.play();
			audioTrack.flush();
			
			state = audioTrack.getPlayState();
        }
        
    }
}