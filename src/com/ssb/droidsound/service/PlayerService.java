package com.ssb.droidsound.service;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.List;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import android.app.Notification;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Intent;
import android.content.SharedPreferences;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.media.audiofx.AudioEffect;
import android.os.AsyncTask;
import android.os.Binder;
import android.os.IBinder;
import android.telephony.PhoneStateListener;
import android.telephony.TelephonyManager;

import com.ssb.droidsound.R;
import com.ssb.droidsound.activity.PlayerActivity;
import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.bo.PlayQueue;
import com.ssb.droidsound.bo.SongFile;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.StreamUtil;
import com.ssb.droidsound.utils.ZipReader;

/**
 * This service handles the background playback. It works by playlist and file-by-file basis.
 *
 * @author alankila
 */
public class PlayerService extends Service {
	enum State { PLAY, PAUSE, STOP; }

	public static final String LOADING_SONG = "com.ssb.droidsound.LOADING_SONG";
	public static final String ADVANCING = "com.ssb.droidsound.ADVANCING";
	public static final String UNLOADING_SONG = "com.ssb.droidsound.UNLOADING_SONG";

	private static final String TAG = PlayerService.class.getSimpleName();
	private static final int NOTIFY_ONGOING_ID = 1;

	/**
	 * This runnable is constructed for playback of one complete song.
	 * It is expected to start from "blank" native state.
	 *
	 * @author alankila
	 */
	private class PlayerRunnable extends AsyncTask<Void, Intent, Void> {
		private static final int FREQUENCY = 44100;
		private static final int BUFSIZE = FREQUENCY * 2;

		private int songLengthMs;
		private int defaultSubsong;
		private int subsongs;
		private int currentSubsong;

		private final DroidSoundPlugin plugin;
		private final SongFile song;
		private final String f1;
		private final byte[] data1;
		private final String f2;
		private final byte[] data2;

		private State stateRequest = State.PAUSE;
		private int seekRequest = -1;
		private int subsongRequest = -1;

		/**
		 * Cosntruct a player that tries to load the file called f1 with content data1,
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
		protected PlayerRunnable(DroidSoundPlugin plugin, SongFile song, String name1, byte[] data1, String name2, byte[] data2) {
			this.plugin = plugin;
			this.song = song;
			this.f1 = name1;
			this.data1 = data1;
			this.f2 = name2;
			this.data2 = data2;
		}

		/**
		 * Get the name of file being played.
		 *
		 * @return file name
		 */
		public String getName() {
			return f1;
		}

		/**
		 * Tell native player to seek to the given msec point if it can.
		 * (It may ignore the request.)
		 *
		 * @param msec
		 */
		public void setSeekRequest(int msec) {
			synchronized (this) {
				Log.i(TAG, "Requesting new seek position %d ms", msec);
				seekRequest = msec;
			}
		}

		/**
		 * Get current playback state. Default state is PAUSE.
		 *
		 * @return current player thread state
		 */
		public State getStateRequest() {
			synchronized (this) {
				return stateRequest;
			}
		}
		/**
		 * Set change in playback state. STOP results in thread's exit,
		 * PAUSE temporarily suspends playback. Default state is PAUSE.
		 *
		 * @param newState
		 */
		public void setStateRequest(State newState) {
			synchronized (this) {
				Log.i(TAG, "Requesting new state: %s", newState);
				stateRequest = newState;
			}
		}

		/**
		 * Tell native code to switch to a different subsong. The
		 * subsong range is player and tune specific, but the value
		 * -1 is reserved for internal use.
		 *
		 * @param song
		 */
		public void setSubSongRequest(int song) {
			synchronized (this) {
				Log.i(TAG, "Requesting subsong: %d", song);
				subsongRequest = song;
			}
		}

		private void sendSongInfo() {
			Intent intent = new Intent(LOADING_SONG);
			intent.putExtra("sticky", true);
			intent.putExtra("plugin.name", plugin.getVersion());
			intent.putExtra("plugin.seekable", plugin.canSeek());
			intent.putExtra("plugin.detailedInfo", plugin.getDetailedInfo());
			intent.putExtra("subsong.length", songLengthMs / 1000);
			intent.putExtra("file.id", song.getId());
			intent.putExtra("file.subsongs", subsongs);
			intent.putExtra("file.defaultSubsong", defaultSubsong);
			intent.putExtra("file.currentSubsong", currentSubsong);
			intent.putExtra("file.title", song.getTitle());
			intent.putExtra("file.composer", song.getComposer());
			intent.putExtra("file.date", song.getDate());
			publishProgress(intent);

			sendAdvancing(0);
		}

		private void sendAdvancing(int time) {
			Intent intent = new Intent(ADVANCING);
			intent.putExtra("sticky", true);
			intent.putExtra("time", time);
			intent.putExtra("length", songLengthMs / 1000);
			publishProgress(intent);
		}

		private void sendUnloading() {
			Intent loading = new Intent(LOADING_SONG);
			removeStickyBroadcast(loading);
			Intent unloading = new Intent(UNLOADING_SONG);
			sendBroadcast(unloading);
		}

		private void sendLoadingWithSubsong(int newSubsong) {
			currentSubsong = newSubsong;
			songLengthMs = plugin.getIntInfo(DroidSoundPlugin.INFO_LENGTH);
			if (songLengthMs <= 0) {
				SharedPreferences prefs = Application.getAppPreferences();
				songLengthMs = Integer.valueOf(prefs.getString("default_length", "0")) * 1000;
			}
			sendSongInfo();
		}

		/**
		 * Send notification about subsong advancement.
		 *
		 * @param position
		 */
		@Override
		protected void onProgressUpdate(Intent... values) {
			for (Intent i : values) {
				boolean asSticky = i.getBooleanExtra("sticky", false);
				i.removeExtra("sticky");
				if (asSticky) {
					sendStickyBroadcast(i);
				} else {
					sendBroadcast(i);
				}
			}
		}

		@Override
		protected Void doInBackground(Void... ignored) {
			/* In theory we could ask plugin about desired frequency and other information. */
			AudioTrack audioTrack = new AudioTrack(
					AudioManager.STREAM_MUSIC,
					FREQUENCY,
					AudioFormat.CHANNEL_CONFIGURATION_STEREO,
					AudioFormat.ENCODING_PCM_16BIT,
					BUFSIZE,
					AudioTrack.MODE_STREAM);
	        Intent sessionOpen = new Intent(AudioEffect.ACTION_OPEN_AUDIO_EFFECT_CONTROL_SESSION);
	        sessionOpen.putExtra(AudioEffect.EXTRA_AUDIO_SESSION, audioTrack.getAudioSessionId());
	        sessionOpen.putExtra(AudioEffect.EXTRA_PACKAGE_NAME, getPackageName());
	        publishProgress(sessionOpen);

			/* Note, this should not fail because it has already been executed once. */
			if (plugin.load(f1, data1, f2, data2)) {
				Log.i(TAG, "Entering audio playback loop.");
				try {
					subsongs = plugin.getIntInfo(DroidSoundPlugin.INFO_SUBTUNE_COUNT);
					defaultSubsong = plugin.getIntInfo(DroidSoundPlugin.INFO_SUBTUNE_NO);
					sendLoadingWithSubsong(defaultSubsong);
					doInBackgroundPlayloop(audioTrack);
					sendUnloading();
				}
				catch (Exception e) {
					Log.w(TAG, "Exiting playloop via exception", e);
				}
				plugin.unload();
				Log.i(TAG, "Audio playback is terminating.");
			} else {
				Log.w(TAG, "Plugin could not load song.");
			}

	        Intent sessionClose = new Intent(AudioEffect.ACTION_CLOSE_AUDIO_EFFECT_CONTROL_SESSION);
	        sessionClose.putExtra(AudioEffect.EXTRA_AUDIO_SESSION, audioTrack.getAudioSessionId());
	        sessionClose.putExtra(AudioEffect.EXTRA_PACKAGE_NAME, getPackageName());
	        publishProgress(sessionClose);
			audioTrack.release();

			return null;
		}

		private void doInBackgroundPlayloop(AudioTrack audioTrack) throws InterruptedException {
			/* The plugin audio buffer is smaller to not underrun (we try to keep 75+ % full). */
			short[] samples = new short[BUFSIZE / 4];

			int playbackFrame = 0;
			PLAYLOOP: while (true) {
				final State loopState;
				synchronized (this) {
					loopState = stateRequest;
				}
				switch (loopState) {
				case PLAY: {
					if (subsongRequest != -1) {
						if (plugin.setTune(subsongRequest)) {
							playbackFrame = 0;
							sendLoadingWithSubsong(subsongRequest);
						}
						subsongRequest = -1;
					}

					if (seekRequest != -1) {
						if (plugin.canSeek()) {
							plugin.seekTo(seekRequest);
							float pos = seekRequest / 1000f * audioTrack.getPlaybackRate();
							playbackFrame = (int) pos;
						}
						seekRequest = -1;
					}

					int sec1 = playbackFrame / audioTrack.getPlaybackRate();
					int len = plugin.getSoundData(samples);
					/* If the length is not positive, it implies errors or song end. We terminate. */
					if (len <= 0) {
						break PLAYLOOP;
					}

					if (audioTrack.getPlayState() == AudioTrack.PLAYSTATE_STOPPED) {
						audioTrack.play();
					}
					audioTrack.write(samples, 0, len);
					playbackFrame += len / audioTrack.getChannelCount();

					int sec2 = playbackFrame / audioTrack.getPlaybackRate();
					if (sec1 != sec2) {
						sendAdvancing(sec2);
					}

					/* Terminate playback when complete song played. */
					if (sec2 > songLengthMs) {
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
					if (audioTrack.getPlayState() != AudioTrack.PLAYSTATE_STOPPED) {
						audioTrack.stop();
					}
					break PLAYLOOP;
				}
			}
		}
	}

	/**
	 * This executor is constructed to run a single runnable and then terminated.
	 * This is a bit antipatternish, but I need a reliable way to wait for the player thread to shutdown.
	 */
	private ThreadPoolExecutor playerExecutor;
	/**
	 * This runnable represents one song being played back currently.
	 */
	private PlayerRunnable player;

	/**
	 * PhoneStateListener is used to shut down playback on incoming call and automatically resume afterwards.
	 */
	private PhoneStateListener phoneStateListener;

	/**
	 * This method starts a new playback thread capable of handling one file.
	 * The default audio state is "PAUSE", so no playback happens until you
	 * tell it to start playing.
	 *
	 * @param p1
	 * @param song
	 * @param n1
	 * @param d1
	 * @param n2
	 * @param d2
	 */
	private void startPlayerThread(DroidSoundPlugin p1, SongFile song, String n1, byte[] d1, String n2, byte[] d2) {
		Log.i(TAG, "Requesting player thread to start");
		if (player != null) {
			throw new RuntimeException("Playerthread was still running. Someone must call stopPlayerThread() first.");
		}

		player = new PlayerRunnable(p1, song, n1, d1, n2, d2);
		player.setStateRequest(State.PLAY);
		player.executeOnExecutor(playerExecutor);

		/* We may be running by bind. It is necessary that we become started for playback. */
		Log.i(TAG, "Adding notification");
		Notification notification = new Notification(R.drawable.droidsound64x64, "DroidSound", System.currentTimeMillis());
		notification.flags |= Notification.FLAG_ONGOING_EVENT | Notification.FLAG_FOREGROUND_SERVICE;
		Intent notificationIntent = new Intent(PlayerService.this, PlayerActivity.class);
		PendingIntent contentIntent = PendingIntent.getActivity(PlayerService.this, 0, notificationIntent, 0);
		notification.setLatestEventInfo(PlayerService.this, "DroidSound", player.getName(), contentIntent);
		startForeground(NOTIFY_ONGOING_ID, notification);
		startService(new Intent(this, PlayerService.class));
	}

	/**
	 * This method returns only after it has guaranteed that the playerthread has exited,
	 * or it gets interrupted.
	 *
	 * @throws InterruptedException
	 */
	private void stopPlayerThread() throws InterruptedException {
		Log.i(TAG, "Requesting player thread to stop");
		if (player == null) {
			throw new RuntimeException("Playerthread was not running. Someone must call startPlayerThread() first.");
		}

		Log.i(TAG, "Removing notification");
		stopService(new Intent(this, PlayerService.class));
		stopForeground(true);

		player.setStateRequest(State.STOP);
		while (playerExecutor.getActiveCount() != 0) {
			playerExecutor.awaitTermination(100, TimeUnit.MILLISECONDS);
		}

		player = null;
	}

	@Override
	public void onCreate() {
		super.onCreate();

		phoneStateListener = new PhoneStateListener() {
			boolean didPause = false;

			@Override
			public void onCallStateChanged(int state, String incomingNumber) {
				switch(state) {
				case TelephonyManager.CALL_STATE_RINGING:
				case TelephonyManager.CALL_STATE_OFFHOOK:
					if (player != null && player.getStateRequest() == State.PLAY) {
						player.setStateRequest(State.PAUSE);
						didPause = true;
					}
					break;
				case TelephonyManager.CALL_STATE_IDLE:
					if (player != null && didPause) {
						player.setStateRequest(State.PLAY);
					}
					didPause = false;
					break;
				}
			}
		};

		TelephonyManager tm = (TelephonyManager)getSystemService(TELEPHONY_SERVICE);
		tm.listen(phoneStateListener, PhoneStateListener.LISTEN_CALL_STATE);

		playerExecutor = new ThreadPoolExecutor(0, 1, 5, TimeUnit.SECONDS, new ArrayBlockingQueue<Runnable>(1), new ThreadFactory() {
			@Override
			public Thread newThread(Runnable runnable) {
				Thread t = new Thread(runnable);
				t.setPriority(Thread.MAX_PRIORITY);
				return t;
			}
		});
	}

	@Override
	public void onDestroy() {
		super.onDestroy();

		TelephonyManager tm = (TelephonyManager)getSystemService(TELEPHONY_SERVICE);
		tm.listen(phoneStateListener, 0);

		if (player != null) {
			try {
				stopPlayerThread();
			} catch (InterruptedException e) {
			}
		}

		playerExecutor.shutdown();
	}

	/**
	 * Start playing a song identified by SongFile parameter.
	 *
	 * @param song
	 * @return
	 * @throws IOException
	 * @throws InterruptedException
	 */
	private boolean startSong(SongFile song) throws IOException, InterruptedException {
		final String name1 = song.getFilePath();
		final byte[] data1;

		final String name2 = song.getSecondaryFileName();
		byte[] data2 = null;

		if (song.getZipFilePath() != null) {
			ZipFile zr = ZipReader.openZip(new File(song.getZipFilePath()));
			ZipEntry ze = zr.getEntry(name1);
			InputStream is1 = zr.getInputStream(ze);
			data1 = StreamUtil.readFully(is1, ze.getSize());
			is1.close();

			/* If the name looks like there might be a secondary file, we extract that from zip also */
			if (name2 != null) {
				ZipEntry ze2 = zr.getEntry(name2);
				if (ze2 != null) {
					InputStream is2 = zr.getInputStream(ze2);
					data2 = StreamUtil.readFully(is1, ze2.getSize());
					is2.close();
				}
			}

			zr.close();
		} else {
			File f1 = new File(name1);
			InputStream is1 = new FileInputStream(f1);
			data1 = StreamUtil.readFully(is1, f1.length());
			is1.close();
			if (name2 != null) {
				File f2 = new File(song.getSecondaryFileName());
				InputStream is2 = new FileInputStream(f2);
				data2 = StreamUtil.readFully(is2, f2.length());
				is2.close();
			}
		}

		/* Plugins will be used to try load the file now, so stop player thread if it is running. */
		if (player != null) {
			stopPlayerThread();
		}

		String basename1 = new File(name1).getName();
		String basename2 = name2 != null ? new File(name2).getName() : null;

		/* Scan plugin list looking for the one that can handle the file and agrees to load it. */
		DroidSoundPlugin currentPlugin = null;
		for (DroidSoundPlugin plugin : DroidSoundPlugin.getPluginList()) {
			if (plugin.canHandle(name1) && plugin.load(basename1, data1, basename2, data2)) {
				currentPlugin = plugin;
				break;
			}
		}
		if (currentPlugin == null) {
			return false;
		}

		/* Loaded. It will be loaded once more by startPlayerThread, so we unload now... */
		currentPlugin.unload();

		startPlayerThread(currentPlugin, song, basename1, data1, basename2, data2);
		return true;
	}

	/**
	 * This class represents a connection to this server.
	 * Only local process usage is expected.
	 *
	 * @author alankila
	 */
	public class LocalBinder extends Binder {
		private PlayQueue playQueue;

		public boolean playMod(SongFile song) {
			try {
				return startSong(song);
			}
			catch (Exception e) {
				Log.w(TAG, "Unable to start playing", e);
				return false;
			}
		}

		public boolean playPause(boolean play) {
			if (player != null) {
				player.setStateRequest(play ? State.PLAY : State.PAUSE);
				return true;
			}
			return false;
		}

		public boolean stop() {
			if (player != null) {
				try {
					stopPlayerThread();
					return true;
				}
				catch (InterruptedException e) {
				}
			}
			return false;
		}

		public boolean seekTo(int msec) {
			if (player != null) {
				player.setSeekRequest(msec);
				return true;
			}
			return false;
		}

		public boolean setSubSong(int song) {
	    	if (playQueue == null) {
	    		return false;
	    	}

	    	if (player != null) {
	    		player.setSubSongRequest(song);
	    		return true;
	    	}

	    	return false;
		}

		public boolean playPlaylist(List<SongFile> names, int startIndex, boolean shuffle) throws IOException, InterruptedException {
			playQueue = new PlayQueue(names, startIndex, shuffle);
			return startSong(playQueue.getCurrent());
		}

		public boolean playNext() throws IOException, InterruptedException {
			if (playQueue == null) {
				return false;
			}
			SongFile song = playQueue.next();
			return startSong(song);
		}

		public boolean playPrev() throws IOException, InterruptedException {
	    	if (playQueue == null) {
	    		return false;
	    	}
	    	SongFile song = playQueue.prev();
	    	return startSong(song);
		}
	}

	private final LocalBinder mBinder = new LocalBinder();

    @Override
    public IBinder onBind(Intent intent) {
    	return mBinder;
    }
}
