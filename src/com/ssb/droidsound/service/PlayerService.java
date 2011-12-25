package com.ssb.droidsound.service;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.os.AsyncTask;
import android.os.Binder;
import android.os.IBinder;
import android.telephony.PhoneStateListener;
import android.telephony.TelephonyManager;

import com.ssb.droidsound.R;
import com.ssb.droidsound.activity.PlayerActivity;
import com.ssb.droidsound.bo.PlayQueue;
import com.ssb.droidsound.bo.Playlist;
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

	public static final String PLAYBACK_ADVANCING = "com.ssb.droidsound.PLAYING";
	private static final String TAG = PlayerService.class.getSimpleName();

	/**
	 * This runnable is constructed for playback of one complete song.
	 * It is expected to start from "blank" native state.
	 *
	 * @author alankila
	 */
	private class PlayerRunnable extends AsyncTask<Void, Float, Void> {
		private static final int FREQUENCY = 44100;
		private static final int BUFSIZE = FREQUENCY * 2;

		private final DroidSoundPlugin plugin;
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
		 * @param name1 name of file 1
		 * @param data1 data of file 1
		 * @param name2 name of file 2
		 * @param data2 data of file 2
		 */
		protected PlayerRunnable(DroidSoundPlugin plugin, String name1, byte[] data1, String name2, byte[] data2) {
			this.plugin = plugin;
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
				Log.i(TAG, "Requesting new seek position", msec);
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

		/**
		 * Send notification about subsong advancement.
		 *
		 * @param position
		 */
		@Override
		protected void onProgressUpdate(Float... values) {
			Intent i = new Intent(PLAYBACK_ADVANCING);
			i.putExtra("name", f1);
			i.putExtra("position", values[0]);
			sendBroadcast(i);
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
			/* The plugin audio buffer is smaller to not underrun (we try to keep 75+ % full). */
			short[] samples = new short[BUFSIZE / 4];

			/* Note, this should not fail because it has already been executed once. */
			plugin.load(f1, data1, f2, data2);

			publishProgress(0f);
			Log.i(TAG, "Entering audio playback loop.");
			try { OUTER: while (true) {
				final State loopState;
				synchronized (this) {
					loopState = stateRequest;
				}
				switch (loopState) {
				case PLAY: {
					if (subsongRequest != -1) {
						plugin.setTune(subsongRequest);
						subsongRequest = -1;
					}

					if (seekRequest != -1) {
						if (plugin.canSeek()) {
							plugin.seekTo(seekRequest);
						}
						seekRequest = -1;
					}

					int sec1 = audioTrack.getPlaybackHeadPosition() / audioTrack.getPlaybackRate();
					int len = plugin.getSoundData(samples);
					/* If the length is not positive, it implies errors or song end. We terminate. */
					if (len <= 0) {
						break;
					}

					if (audioTrack.getPlayState() == AudioTrack.PLAYSTATE_STOPPED) {
						audioTrack.play();
					}
					audioTrack.write(samples, 0, len);

					float sec2 = audioTrack.getPlaybackHeadPosition() / audioTrack.getPlaybackRate();
					if (sec1 != (int) sec2) {
						publishProgress(sec2);
					}

					break;
				}
				case PAUSE:
					if (audioTrack.getPlayState() != AudioTrack.PLAYSTATE_PAUSED) {
						audioTrack.pause();
					}
					Thread.sleep(100);

				case STOP:
					if (audioTrack.getPlayState() != AudioTrack.PLAYSTATE_STOPPED) {
						audioTrack.stop();
					}
					break OUTER;
				}
			} }
			catch (Exception ise) {
				Log.w(TAG, "Audio playback error: %s", ise);
			}
			Log.i(TAG, "Audio playback is terminating.");
			publishProgress(-1f);

			plugin.unload();

			audioTrack.release();
			return null;
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
	 * This notification holds the ongoing-notification in status bar.
	 */
	private Notification notification;

	/**
	 * This pending intent shows the UI when clicked.
	 */
	private PendingIntent contentIntent;

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
	 * @param n1
	 * @param d1
	 * @param n2
	 * @param d2
	 */
	private void startPlayerThread(DroidSoundPlugin p1, String n1, byte[] d1, String n2, byte[] d2) {
		Log.i(TAG, "Requesting player thread to start");
		if (player != null) {
			throw new RuntimeException("Playerthread was still running. Someone must call stopPlayerThread() first.");
		}

		player = new PlayerRunnable(p1, n1, d1, n2, d2);
		player.setStateRequest(State.PLAY);
		playerExecutor = new ThreadPoolExecutor(1, 1, 0, TimeUnit.SECONDS, new LinkedBlockingQueue<Runnable>(1));
		player.executeOnExecutor(playerExecutor);
		notification.setLatestEventInfo(this, "Droidsound", player.getName(), contentIntent);
		NotificationManager nm = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
		nm.notify(0x123456, notification);
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

		player.setStateRequest(State.STOP);
		/* Android ExecutorService#shutdown() does not wait.
		 * Also #awaitTermination does not wake when last task is gone.
		 * So we poll. Hopefully this shit works.
		 */
		while (playerExecutor.getActiveCount() != 0) {
			playerExecutor.awaitTermination(100, TimeUnit.MILLISECONDS);
		}
		playerExecutor.shutdown();
		NotificationManager nm = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
		nm.cancel(0x123456);

		player = null;
		playerExecutor = null;
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

		notification = new Notification(R.drawable.droidsound64x64, "Droidsound", System.currentTimeMillis());
		Intent notificationIntent = new Intent(this, PlayerActivity.class);
		notification.flags |= Notification.FLAG_ONGOING_EVENT | Notification.FLAG_FOREGROUND_SERVICE;
		contentIntent = PendingIntent.getActivity(getApplicationContext(), 0, notificationIntent, 0);
	    notification.setLatestEventInfo(this, "Droidsound", "Playing", contentIntent);
	}

	@Override
	public void onStart(Intent intent, int startId) {
		super.onStart(intent, startId);
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
		final String name1;
		final byte[] data1;

		final String name2 = song.getSecondaryFileName();
		byte[] data2 = null;

		/* FIXME:
		 *
		 * Currently, UADE is the only plugin that needs the data as file.
		 * Maybe we could use an API that allowed providing data via byte[]
		 * for UADE also.
		 *
		 * If that is the case, we could get rid of writeTempFile, and
		 * DroidSoundPlugin#load(File).
		 */
		if (song.getZipPath() != null) {
			name1 = song.getZipName();

			ZipFile zr = ZipReader.openZip(new File(song.getZipPath()));
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
			name1 = song.getFileName();

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

		startPlayerThread(currentPlugin, basename1, data1, basename2, data2);
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
			player.setSeekRequest(msec);
			return true;
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

		public boolean playPlaylist(Playlist name, int startIndex, boolean shuffle) throws IOException, InterruptedException {
			playQueue = new PlayQueue(name, startIndex, shuffle);
			return startSong(playQueue.getCurrent());
		}

		public boolean playPlaylist(String[] names, int startIndex, boolean shuffle) throws IOException, InterruptedException {
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
