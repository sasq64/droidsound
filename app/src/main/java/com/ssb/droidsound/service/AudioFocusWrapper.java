package com.ssb.droidsound.service;

import android.annotation.TargetApi;
import android.content.Context;
import android.media.AudioManager.OnAudioFocusChangeListener;
import android.media.AudioManager;

@TargetApi(8)
public class AudioFocusWrapper {
	
	private OnAudioFocusChangeListener listener;

	static {
		try {
			new OnAudioFocusChangeListener() {
				@Override
				public void onAudioFocusChange(int focusChange) {}
			};
		} catch (Exception ex) {
			//ex.printStackTrace();
			throw new RuntimeException(ex);
		}
	}
	
	public static void checkAvailable() {}


	private Player player;
	private AudioManager audioManager;
	
	public AudioFocusWrapper(Context ctx, Player pl) {
		player = pl;
		audioManager = (AudioManager) ctx.getSystemService(Context.AUDIO_SERVICE);
		
		listener = new OnAudioFocusChangeListener() {

			@Override
			public void onAudioFocusChange(int focusChange) {
				if (focusChange == AudioManager.AUDIOFOCUS_LOSS_TRANSIENT) {
		            // Pause playback
					if(player.isPlaying()) {
						player.paused(true, this);
					}
				} else if (focusChange == AudioManager.AUDIOFOCUS_GAIN) {
		            // Resume playback
					if(player.pausedBy(this))
						player.paused(false);
				} else if (focusChange == AudioManager.AUDIOFOCUS_LOSS) {
					//AudioManager am = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
		            //am.abandonAudioFocus(this);
					player.stop();
		        }
			}
		};		
	}

	public void requestFocus() {
		audioManager.requestAudioFocus(listener, AudioManager.STREAM_MUSIC,  AudioManager.AUDIOFOCUS_GAIN);
	}

	public void abandonFocus() {
		audioManager.abandonAudioFocus(listener);
	}



}
