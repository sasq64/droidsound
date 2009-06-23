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
        
		int bufSize = AudioTrack.getMinBufferSize(44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT);
		if(bufSize < 32768*4) {
			bufSize = 32768*4;
		}
		AudioTrack audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, 44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);
		
		short [] samples = new short [bufSize/2];
		
		for(int i=0; i<bufSize/2; i++) {
			samples[i] = (short)(Math.sin(i*2*Math.PI / 327.68) * 32767);
		}
		
		audioTrack.write(samples, 0, bufSize);
		audioTrack.play();
		audioTrack.flush();
        
    }
}