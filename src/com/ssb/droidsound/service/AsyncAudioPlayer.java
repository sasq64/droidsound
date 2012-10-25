package com.ssb.droidsound.service;

import java.nio.ShortBuffer;

import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.media.AudioTrack.OnPlaybackPositionUpdateListener;
import android.media.MediaPlayer;

import com.ssb.droidsound.utils.Log;

public class AsyncAudioPlayer  implements Runnable, OnPlaybackPositionUpdateListener {	
	private static final String TAG = AudioPlayer.class.getSimpleName();

	private MediaPlayer mediaPlayer;
	private AudioTrack audioTrack;
	private boolean reinitAudio;
	private int bufSize = 0x40000;
	private int FREQ = 44100;
	private int startPlaybackHead;
	private int playPosOffset;
	private int silence;
		
	private ShortBuffer buffer;

	private boolean doStart;
	
	public AsyncAudioPlayer(int bs) {
		bufSize = bs;
		silence = 0;
	}
	
	@Override
	public void run() {
		init();		
		while(true) {		
			try {
				Thread.sleep(200);
			} catch (InterruptedException e) {
				return;
			}
		}
	}
	
	
	// One frame in stereo == 2 Samples == 4 bytes
	
	private void init() {
		audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ, AudioFormat.CHANNEL_OUT_STEREO,
				AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);
		buffer = ShortBuffer.allocate(88200*8); // 8 seconds
		audioTrack.setPositionNotificationPeriod(bufSize/16); // Notify after 1/4 buffer size 
		audioTrack.setPlaybackPositionUpdateListener(this);
	}
	
	@Override
	public void onMarkerReached(AudioTrack track) {
	}

	@Override
	public void onPeriodicNotification(AudioTrack track) {
		synchronized (this) {
			int count = bufSize/4;
			if(buffer.position() > count) {			
				audioTrack.write(buffer.array(), 0, count);
				buffer.limit(buffer.position());
				buffer.position(count);			
				buffer.compact();
			}			
		}
		
	}


	public void update(short [] samples, int len) {
		
		synchronized (this) {
					
		if(doStart) {
			audioTrack.play();
			//Log.d(TAG, "STATE " + audioTrack.getState());
			//try {
			//	Thread.sleep(10);
			//} catch (InterruptedException e) {
				// TODO Auto-generated catch block
			//	e.printStackTrace();
			//}
			startPlaybackHead = audioTrack.getPlaybackHeadPosition();
			playPosOffset = 0;
			//Log.d(TAG, "START PLAYBACK " + startPlaybackHead);
			//Log.d(TAG, "STATE " + audioTrack.getState());
			doStart = false;
		}
		
		int i = len-1;
		for(; i>=0; i-=3) {
			if(samples[i] > 128 || samples[i] < -128) {				
				break;			
			}
		}
		
		buffer.put(samples,0, len);
		
		if(i >= 0)
			silence = len+1-i;
		else
			silence += len;

		
		/*
		int count = bufSize / 4;
		if(count > buffer.position()/2)
			count = buffer.position()/2;
				
		audioTrack.write(buffer.array(), 0, count);
		buffer.limit(buffer.position());
		buffer.position(count);			
		buffer.compact();
		*/

		//Log.d(TAG, "STATE " + audioTrack.getState());
		//Log.d(TAG, "PLAYBACK NOW " + audioTrack.getPlaybackHeadPosition());
		}

	}
	
	public int getSilence() {
		
		int msec = bufSize*1000/(44100*4);
		return (silence * 10 / 882) - msec;
	}
	
	// Get number of seconds played since start
	public int getPlaybackPosition() {
		
		if(mediaPlayer != null) {
			return  mediaPlayer.getCurrentPosition();
		}
		int pos = audioTrack.getPlaybackHeadPosition() - startPlaybackHead;
		int playPos = pos * 10 / (FREQ / 100);
		//Log.d(TAG, "POS %d => %d (%d)", pos, playPos, playPosOffset);

		return playPos + playPosOffset;
	}
	
	// Inform player that playback has seeked to a new position. Affects playback position
	public void seekTo(int msec) {
		if(mediaPlayer != null) {
			mediaPlayer.seekTo(msec);
			return;
		}
		
		audioTrack.flush();
		buffer.clear();
		
		int playPos = (audioTrack.getPlaybackHeadPosition()  - startPlaybackHead) * 10 / (FREQ / 100);
		Log.d(TAG, "Offset %d/1000 - %d", msec, playPos);
		playPosOffset = msec - playPos;
	}

	// Stop playback
	public void stop() {
		
		buffer.clear();
		
		if(mediaPlayer != null) {
			mediaPlayer.stop();
		} else {

			audioTrack.stop();
			audioTrack.flush();

			if(reinitAudio) {
				audioTrack.release();
				audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ,
						AudioFormat.CHANNEL_OUT_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize,
						AudioTrack.MODE_STREAM);
				reinitAudio = false;
			}
			
			//startPlaybackHead = 0;//audioTrack.getPlaybackHeadPosition();
			//playPosOffset = 0;
		}
	}


	public void start() {
		//MediaPlayer mp = currentPlugin.getMediaPlayer();
		if(mediaPlayer != null) {
			mediaPlayer.start();
			return;
		}

		if(reinitAudio) {
			audioTrack.release();
			audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ, AudioFormat.CHANNEL_OUT_STEREO,
					AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);
			reinitAudio = false;
		}
		buffer.clear();
		doStart = true;
		//Log.d(TAG, "STATE " + audioTrack.getState());

		//audioTrack.play();
		//startPlaybackHead = audioTrack.getPlaybackHeadPosition();
		//Log.d(TAG, "START PLAYBACK " + startPlaybackHead);
		//playPosOffset = 0;		
	}

	public void pause() {
		audioTrack.pause();
		
	}

	public void flush() {
		
		buffer.clear();
		
		audioTrack.flush();
		startPlaybackHead = audioTrack.getPlaybackHeadPosition();
		playPosOffset = 0;
		Log.d(TAG, "PLAYBACK AFTER FLUSH " + startPlaybackHead);
		
	}

	public void release() {
		audioTrack.release();
		
	}

	public void play() {
		audioTrack.play();
		// TODO Auto-generated method stub
		
	}

	public void setBufferSize(int bs) {
		bufSize = bs;
		reinitAudio = true;
	}

	
}
