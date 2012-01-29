package com.ssb.droidsound.async;

import java.util.Queue;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicReference;

import android.content.Intent;
import android.content.SharedPreferences;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.media.audiofx.AudioEffect;
import android.os.AsyncTask;

import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.bo.FilesEntry;
import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.OverlappingFFT;

public class Player extends AsyncTask<Void, Intent, Void> {
	/**
	 * These represent the desired UI-related state of the player thread.
	 * PLAY means that music playback is desired and should begin as soon as possible.
	 * PAUSE means that temporary pause has been requested.
	 * STOP means that playback is no longer desired and should terminate as soon as possible.
	 *
	 * @author alankila
	 */
	public enum State { PLAY, PAUSE, STOP; }

	public static final String ACTION_LOADING_SONG = "com.ssb.droidsound.LOADING_SONG";
	public static final String ACTION_ADVANCING = "com.ssb.droidsound.ADVANCING";
	public static final String ACTION_UNLOADING_SONG = "com.ssb.droidsound.UNLOADING_SONG";

	private static final String TAG = Player.class.getSimpleName();
	private static final int FREQUENCY_HZ = 44100;
	private static final int BUFSIZE_BYTES = FREQUENCY_HZ * 4;

	private final SongDatabase db; /* fixme: get rid of this! */
	private final DroidSoundPlugin plugin;
	private final FilesEntry song;
	private final String f1;
	private final byte[] data1;
	private final String f2;
	private final byte[] data2;
	private final AtomicReference<OverlappingFFT> fft = new AtomicReference<OverlappingFFT>();

	private final AtomicInteger subsongLengthMs = new AtomicInteger();
	private final AtomicInteger defaultSubsong = new AtomicInteger();
	private final AtomicInteger subsongs = new AtomicInteger();
	private final AtomicReference<State> syncStateRequest = new AtomicReference<State>(State.PLAY);
	private final AtomicInteger syncSeekRequest = new AtomicInteger(-1);
	private final AtomicInteger syncSubsongRequest = new AtomicInteger(-1);
	private final AtomicInteger currentSubsong = new AtomicInteger();

	/**
	 * Construct a player that tries to load the file called f1 with content data1,
	 * and also offers optional f2 and content data2 if the native code needs it.
	 * <p>
	 * Generalization to more than 2 files has not been done because no known
	 * formats need such a capability, but if it ever happens, Map<String, byte[]> is probably good idea.
	 *
	 * @param plugin plugin to play file with
	 * @param song
	 * @param name1 name of file 1
	 * @param data1 data of file 1
	 * @param name2 name of file 2
	 * @param data2 data of file 2
	 */
	public Player(SongDatabase db, DroidSoundPlugin plugin, FilesEntry song, String name1, byte[] data1, String name2, byte[] data2) {
		this.db = db;
		this.plugin = plugin;
		this.song = song;
		this.f1 = name1;
		this.data1 = data1;
		this.f2 = name2;
		this.data2 = data2;
	}

	public Long getFileId() {
		return song.getId();
	}

	/**
	 * Return FFT data accumulated by player.
	 *
	 * @return data array
	 */
	public Queue<OverlappingFFT.Data> enableFftQueue() {
		if (fft.get() == null) {
			fft.set(new OverlappingFFT(BUFSIZE_BYTES / 4, FREQUENCY_HZ));
		}
		return fft.get().getQueue();
	}

	/** Remove FFT queue. */
	public void disableFftQueue() {
		fft.set(null);
	}

	/**
	 * Tell native player to seek to the given msec point if it can.
	 * (It may ignore the request.)
	 *
	 * @param msec
	 */
	public void setSeekRequest(int msec) {
		Log.i(TAG, "Requesting new seek position %d ms", msec);
		syncSeekRequest.set(msec);
	}

	/**
	 * Get current playback state.
	 *
	 * @return current player thread state
	 */
	public State getStateRequest() {
		return syncStateRequest.get();
	}
	/**
	 * Change playback state of a running thread.
	 * Once STOP has been processed, thread no longer runs.
	 *
	 * @param newState
	 */
	public void setStateRequest(State newState) {
		syncStateRequest.set(newState);
	}

	public int getCurrentSubsong() {
		return currentSubsong.get();
	}

	public int getMaxSubsong() {
		return subsongs.get();
	}

	public int getDefaultSubsong() {
		return defaultSubsong.get();
	}

	/**
	 * Tell native code to switch to a different subsong. The
	 * subsong range is player and tune specific, but the value
	 * -1 is reserved for internal use.
	 *
	 * @param song
	 */
	public void setSubSongRequest(int song) {
		syncSubsongRequest.set(song);
	}

	private void sendAdvancing(int time) {
		Intent intent = new Intent(ACTION_ADVANCING);
		intent.putExtra("time", time);
		publishProgress(intent);
	}

	private void sendUnloading() {
		Intent unloading = new Intent(ACTION_UNLOADING_SONG);
		unloading.putExtra("state", syncStateRequest.get());
		Application.broadcast(unloading);
	}

	private void sendLoadingWithSubsong(int newSubsong) {
		currentSubsong.set(newSubsong);
		subsongLengthMs.set(db.getSongLength(plugin.md5(data1), newSubsong + 1));
		if (subsongLengthMs.get() <= 0) {
			subsongLengthMs.set(plugin.getIntInfo(DroidSoundPlugin.INFO_LENGTH));
		}
		if (subsongLengthMs.get() <= 0) {
			SharedPreferences prefs = Application.getAppPreferences();
			subsongLengthMs.set(Integer.valueOf(prefs.getString("default_length", "0")) * 1000);
		}

		Intent intent = new Intent(ACTION_LOADING_SONG);
		intent.putExtra("plugin.name", plugin.getVersion());
		intent.putExtra("plugin.currentSubsong", currentSubsong);
		intent.putExtra("plugin.seekable", plugin.canSeek());
		intent.putExtra("plugin.detailedInfo", plugin.getDetailedInfo());
		intent.putExtra("subsong.length", subsongLengthMs.get() / 1000);
		intent.putExtra("file.id", song.getId());
		intent.putExtra("file.subsongs", subsongs);
		intent.putExtra("file.defaultSubsong", defaultSubsong);
		intent.putExtra("file.title", song.getTitle());
		intent.putExtra("file.composer", song.getComposer());
		intent.putExtra("file.date", song.getDate());
		publishProgress(intent);

		sendAdvancing(0);
	}

	/**
	 * Send notification about subsong advancement.
	 *
	 * @param position
	 */
	@Override
	protected void onProgressUpdate(Intent... values) {
		for (Intent i : values) {
			Application.broadcast(i);
		}
	}

	@Override
	protected Void doInBackground(Void... ignored) {
		/* In theory we could ask plugin about desired frequency and other information. */
		AudioTrack audioTrack = new AudioTrack(
				AudioManager.STREAM_MUSIC,
				FREQUENCY_HZ,
				AudioFormat.CHANNEL_CONFIGURATION_STEREO,
				AudioFormat.ENCODING_PCM_16BIT,
				BUFSIZE_BYTES,
				AudioTrack.MODE_STREAM);
        Intent sessionOpen = new Intent(AudioEffect.ACTION_OPEN_AUDIO_EFFECT_CONTROL_SESSION);
        sessionOpen.putExtra(AudioEffect.EXTRA_AUDIO_SESSION, audioTrack.getAudioSessionId());
        sessionOpen.putExtra(AudioEffect.EXTRA_PACKAGE_NAME, Application.packageName());
        publishProgress(sessionOpen);

		/* Note, this should not fail because it has already been executed once. */
		if (plugin.load(f1, data1, f2, data2)) {
			Log.i(TAG, "Entering audio playback loop.");
			try {
				subsongs.set(plugin.getIntInfo(DroidSoundPlugin.INFO_SUBTUNE_COUNT));
				defaultSubsong.set(plugin.getIntInfo(DroidSoundPlugin.INFO_STARTTUNE));
				sendLoadingWithSubsong(defaultSubsong.get());
				doInBackgroundPlayloop(audioTrack);
				sendUnloading();
			}
			catch (Exception e) {
				Log.w(TAG, "Exiting playloop via exception", e);
			}
			plugin.unload();
			Log.i(TAG, "Exiting audio playback loop.");
		} else {
			Log.w(TAG, "Plugin could not load song.");
		}

        Intent sessionClose = new Intent(AudioEffect.ACTION_CLOSE_AUDIO_EFFECT_CONTROL_SESSION);
        sessionClose.putExtra(AudioEffect.EXTRA_AUDIO_SESSION, audioTrack.getAudioSessionId());
        sessionClose.putExtra(AudioEffect.EXTRA_PACKAGE_NAME, Application.packageName());
        publishProgress(sessionClose);
		audioTrack.release();

		return null;
	}

	private void doInBackgroundPlayloop(AudioTrack audioTrack) throws InterruptedException {
		/* I've selected a size which is convenient for FFT. */
		short[] samples = new short[4096 * 2];

		int playbackFrame = 0;
		PLAYLOOP: while (true) {
			switch (syncStateRequest.get()) {
			case PLAY: {
				final int loopSubsongRequest = syncSubsongRequest.getAndSet(-1);
				if (loopSubsongRequest != -1) {
					if (plugin.setTune(loopSubsongRequest)) {
						playbackFrame = 0;
						sendLoadingWithSubsong(loopSubsongRequest);
					}
				}

				final int loopSeekRequest = syncSeekRequest.getAndSet(-1);
				if (loopSeekRequest != -1) {
					if (plugin.canSeek()) {
						plugin.seekTo(loopSeekRequest);
						float pos = loopSeekRequest / 1000f * audioTrack.getPlaybackRate();
						playbackFrame = (int) pos;
					}
				}

				int lengthInSamples = plugin.getSoundData(samples);
				/* If the length is not positive, it implies errors or song end. We terminate. */
				if (lengthInSamples <= 0) {
					break PLAYLOOP;
				}

				if (audioTrack.getPlayState() != AudioTrack.PLAYSTATE_PLAYING) {
					audioTrack.play();
				}

				audioTrack.write(samples, 0, lengthInSamples);

				/* Update our FFT */
				OverlappingFFT _fft = fft.get();
				if (_fft != null) {
					_fft.feed(samples, 0, lengthInSamples);
				}

				int sec1 = playbackFrame / audioTrack.getPlaybackRate();
				playbackFrame += lengthInSamples / 2;
				int sec2 = playbackFrame / audioTrack.getPlaybackRate();
				if (sec1 != sec2) {
					sendAdvancing(sec2);
				}

				/* Terminate playback when complete song played. */
				if (sec2 > subsongLengthMs.get() / 1000) {
					break PLAYLOOP;
				}

				break;
			}
			case PAUSE:
				if (audioTrack.getPlayState() != AudioTrack.PLAYSTATE_PAUSED) {
					audioTrack.pause();
				}
				Thread.sleep(500);
				break;

			case STOP:
				audioTrack.stop();
				break PLAYLOOP;
			}
		}
	}
}
