package com.ssb.droidsound.service;

import java.nio.ShortBuffer;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.media.AudioTrack.OnPlaybackPositionUpdateListener;
import android.media.MediaPlayer;

import com.ssb.droidsound.utils.Log;

public class AsyncAudioPlayer implements Runnable {	
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

	public static enum Command {
		NO_OP,
		START,
		STOP,
		PAUSE,
		RELEASE,
		PLAY,
		FLUSH,
		NO_CMD
	};
	
	private LinkedList<Command> commands = new LinkedList<Command>();

	public AsyncAudioPlayer(int bs) {
		bufSize = bs;
		silence = 0;
	}
	
	@Override
	public void run() {
		init();		
		while(true) {		
			try {
				int count = 88200/5; // 200ms
				int bytesAvailable = 0;
				synchronized (buffer) {
					bytesAvailable = buffer.position();					
				}
				if(bytesAvailable > count) {

					if(doStart) {
						audioTrack.play();
						startPlaybackHead = audioTrack.getPlaybackHeadPosition();
						playPosOffset = 0;
						doStart = false;
					}
					
					while(bytesAvailable > count) {						
						synchronized (buffer) {
							buffer.flip();
							audioTrack.write(buffer.array(), 0, count);
							buffer.position(count);
							buffer.compact();
						}
						bytesAvailable -= count;
						runCommands();
					}					
				} else					
					Thread.sleep(200);
			} catch (InterruptedException e) {
				return;
			}
		}
	}
	
	private void runCommands() {
	
			Command cmd = Command.NO_OP;
									
			while(cmd != Command.NO_CMD) {
				synchronized (commands) {					
					if(!commands.isEmpty())
						cmd = commands.removeFirst();
				}
				switch(cmd) {
				case START:
					_start();
					break;
				case STOP:
					_stop();
					break;
				case PAUSE:
					audioTrack.pause();
					break;
				case PLAY:
					audioTrack.play();
					break;
				case RELEASE:
					audioTrack.release();
					break;
				case FLUSH:
					_flush();
					break;
				case NO_OP:
				case NO_CMD:
					break;
				}
			}
	}
	
	
	// One frame in stereo == 2 Samples == 4 bytes
	
	private void init() {
		audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ, AudioFormat.CHANNEL_OUT_STEREO,
			AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);
		buffer = ShortBuffer.allocate(88200*8); // 8 seconds
	}
	

	public void update(short [] samples, int len) {
		
		synchronized (this) {
							
			int i = len-1;
			for(; i>=0; i-=3) {
				if(samples[i] > 128 || samples[i] < -128) {				
					break;			
				}
			}

			synchronized (buffer) {
				buffer.put(samples,0, len);	
			}
						
			if(i >= 0)
				silence = len+1-i;
			else
				silence += len;
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
		synchronized (this) {
			commands.add(Command.STOP);			
		}
	}
	
	private void _stop() {
		
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
		synchronized (this) {
			commands.add(Command.START);			
		}
	}
	
	private void _start() {
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
		synchronized (this) {
			commands.add(Command.PAUSE);			
		}
	}

	public void flush() {
		synchronized (this) {
			commands.add(Command.FLUSH);			
		}
	}

	public void _flush() {
		
		buffer.clear();		
		audioTrack.flush();
		startPlaybackHead = audioTrack.getPlaybackHeadPosition();
		playPosOffset = 0;
		Log.d(TAG, "PLAYBACK AFTER FLUSH " + startPlaybackHead);
		
	}

	public void release() {
		synchronized (this) {
			commands.add(Command.RELEASE);			
		}
	}

	public void play() {
		synchronized (this) {
			commands.add(Command.PLAY);			
		}
	}

	public void setBufferSize(int bs) {
		synchronized (this) {
			bufSize = bs;
			reinitAudio = true;		
		}
	}

	
}
