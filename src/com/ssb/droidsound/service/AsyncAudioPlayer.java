package com.ssb.droidsound.service;

import java.nio.ShortBuffer;
import java.util.LinkedList;

import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;

import com.ssb.droidsound.utils.Log;

public class AsyncAudioPlayer implements Runnable {	
	private static final String TAG = AudioPlayer.class.getSimpleName();

	public static int SEC = 88200;
	
	private AudioTrack audioTrack;
	//private boolean reinitAudio;
	private int bufSize = SEC;
	private int FREQ = 44100;
	private int silence;
		
	private ShortBuffer buffer;

	private boolean doStart;

	public static enum Command {
		START,
		STOP,
		PAUSE,
		RELEASE,
		PLAY,
		FLUSH
	};
	
	private LinkedList<Command> commands = new LinkedList<Command>();

	private volatile int playbackPosition;
	private volatile int startPlaybackHead;
	private volatile int playPosOffset;


	private int framesWritten;

	private volatile int framesRead;

	private volatile boolean stopped;
	private volatile boolean isPaused;
	private volatile boolean doExit;
	//private volatile boolean stopRequested;

	private volatile boolean holdData;

	private int markPosition;

	public AsyncAudioPlayer(int bs) {
		bufSize = bs;
		silence = 0;
	}
	
	@Override
	public void run() {
		init();		
		while(true) {		
			try {
				int count = SEC/10; // 100ms
				int bytesAvailable = 0;
				synchronized (buffer) {
					bytesAvailable = buffer.position();
					//Log.d(TAG, "Position at %d", bytesAvailable);
				}
				
				if(doStart) {
					isPaused = false;
					Log.d(TAG, "Starting playback");
					audioTrack.play();
					startPlaybackHead = audioTrack.getPlaybackHeadPosition();
					playPosOffset = 0;
					doStart = false;
					stopped = false;
					holdData = false;
				}				
				
				if(!isPaused && bytesAvailable > count) {

					
					while(bytesAvailable > count) {
						playbackPosition = audioTrack.getPlaybackHeadPosition();
						synchronized (buffer) {
							//Log.d(TAG, "Reading %d shorts", count);
							if(buffer.position() >= count) {
								buffer.flip();
								audioTrack.write(buffer.array(), 0, count);
								framesRead += count/2;
								buffer.position(count);
								buffer.compact();
							}
						}
						runCommands();
						if(doExit) {
							return;
						}
						if(stopped || isPaused)
							break;
						synchronized (buffer) {
							bytesAvailable = buffer.position();
						}
						Log.d(TAG, "WRITE/READ/PLAY %d %d %d", toMSec(framesWritten), toMSec(framesRead), toMSec(playbackPosition));
					}
				} else {
					runCommands();
					if(doExit) {
						return;
					}
					Thread.sleep(100);
				}
				playbackPosition = audioTrack.getPlaybackHeadPosition();
			} catch (InterruptedException e) {
				return;
			}
		}
	}
	
	private void runCommands() {
	
			Command cmd;//
									
			while(true) {
				synchronized (commands) {					
					if(!commands.isEmpty())
						cmd = commands.removeFirst();
					else
						break;
				}
				Log.d(TAG, "Reveived %s", cmd.name());
				switch(cmd) {
				case START:
					_start();
					break;
				case STOP:
					_stop();
					break;
				case PAUSE:
					audioTrack.pause();
					isPaused = true;
					break;
				case PLAY:
					audioTrack.play();
					isPaused = false;
					break;
				case RELEASE:
					audioTrack.release();
					doExit = true;
					break;
				case FLUSH:
					_flush();
					break;
				}
			}
	}
	
	
	// One frame in stereo == 2 Samples == 4 bytes
	
	private void init() {
		bufSize = 44100*2; // 1s
		audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ, AudioFormat.CHANNEL_OUT_STEREO,
			AudioFormat.ENCODING_PCM_16BIT, bufSize*2, AudioTrack.MODE_STREAM);
		buffer = ShortBuffer.allocate(SEC*8); // 8 seconds
		framesWritten = 0;
		framesRead = 0;
	}
	

	public boolean update(short [] samples, int len) {
									
		synchronized (buffer) {
			//Log.d(TAG, "Writing %d shorts", len);
			if(buffer.remaining() >= len) {
				buffer.put(samples,0, len);	
				framesWritten += (len/2);
			} else
				return false;
		}

		int i = len-1;
		for(; i>=0; i-=3) {
			if(samples[i] > 128 || samples[i] < -128) {				
				break;			
			}
		}
		
					
		if(i >= 0) {
			/*if(silence > something) {
				lastSilenceStart = framesWritten - silence;
				lastSilenceEnd = framesWritten;
			}*/
			
			silence = (len+1-i)/2;
		} else
			silence += (len/2);
		
		return true;

	}
	
	public int getLeft() {
		synchronized (buffer) {
			if(stopped || holdData) // Dont queue anything when stopped
				return 0;
			return buffer.remaining();	
		}		
	}
	
	public int getSilence() {
		
		// framesWritten > framesRead
		// framesWritten - silence = startOfSilence
		int bufferFrames = 44100*2;
		int startOfSilence = framesWritten - silence;
		//Log.d(TAG, "SILENCE %d %d %d", framesWritten, startOfSilence, framesRead);
		if((framesRead - bufferFrames) >= startOfSilence) {
			return (silence * 2 * 1000 / SEC);	
		}
		return 0;
		
	}
	
	// Get number of seconds played since start
	public int getPlaybackPosition() {
		
		int pos = playbackPosition - startPlaybackHead;
		int playPos = pos * 10 / (FREQ / 100);
		//Log.d(TAG, "POS %d => %d (%d)", pos, playPos, playPosOffset);

		return playPos + playPosOffset;
	}
	
	// Inform player that playback has seeked to a new position. Affects playback position
	public void seekTo(int msec) {
		
		//audioTrack.flush();
		
		synchronized (buffer) {
			
			framesWritten -= (buffer.position()/2);			
			buffer.clear();
			
			//holdData = true;
		}
				
		int playPos = (playbackPosition  - startPlaybackHead) * 10 / (FREQ / 100);
		playPosOffset = msec - playPos;
		Log.d(TAG, "Offset %d - %d = %d", msec, playPos, playPosOffset);
		
		_flush();

	}

	// Stop playback
	public void stop() {
		synchronized (this) {
			holdData = true;
			commands.add(Command.STOP);			
		}
	}
	
	private void _stop() {
		
		/*
		try {
			Thread.sleep(10);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
		
		
		Log.d(TAG, "Flush & stop");
		audioTrack.pause();
		try {
			Thread.sleep(100);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		audioTrack.flush();
		try {
			Thread.sleep(100);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		audioTrack.stop();

		buffer.clear();
		framesWritten = framesRead = silence = 0;
		
		stopped = true;
		holdData = false;

		/*if(reinitAudio) {
			audioTrack.release();
			audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ,
					AudioFormat.CHANNEL_OUT_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize,
					AudioTrack.MODE_STREAM);
			reinitAudio = false;
		}*/
	}


	public void start() {
		synchronized (this) {
			commands.add(Command.START);			
		}
	}
	
	private void _start() {
		
		Log.d(TAG, "Order start");
		/*if(reinitAudio) {
			audioTrack.release();
			audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ, AudioFormat.CHANNEL_OUT_STEREO,
					AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);
			reinitAudio = false;
		}*/
		buffer.clear();
		framesWritten = framesRead = silence = 0;
		holdData = false;
		stopped = false;
		doStart = true;
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
		
		
		audioTrack.flush();		
		//startPlaybackHead = audioTrack.getPlaybackHeadPosition();
		//playPosOffset = 0;
		//Log.d(TAG, "PLAYBACK AFTER FLUSH " + startPlaybackHead);
		
	}

	public void exit() {
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
		//synchronized (this) {
		//	bufSize = bs;
		//	reinitAudio = true;		
		//}
	}
	
	private int toMSec(int frames) {
		
		return frames * 10 / 441;
		
	}

	public void mark() {
		markPosition = framesWritten;//playbackPosition;
		Log.d(TAG, "Mark %d (play at %d)", toMSec(markPosition),  toMSec(playbackPosition - startPlaybackHead));
	}
	
	public boolean markReached() {
		return (playbackPosition - startPlaybackHead) >= markPosition;
	}
	
}
