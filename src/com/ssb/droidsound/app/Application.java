package com.ssb.droidsound.app;

import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Queue;
import java.util.concurrent.ExecutionException;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.content.SharedPreferences;
import android.content.res.AssetManager;
import android.os.AsyncTask;
import android.os.Environment;
import android.os.IBinder;
import android.preference.PreferenceManager;
import android.widget.Toast;

import com.ssb.droidsound.R;
import com.ssb.droidsound.async.Player;
import com.ssb.droidsound.async.Player.State;
import com.ssb.droidsound.bo.FilesEntry;
import com.ssb.droidsound.bo.PlayQueue;
import com.ssb.droidsound.bo.SongFileData;
import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.service.ProtectionMoneyService;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.OverlappingFFT.Data;
import com.ssb.droidsound.utils.StreamUtil;

/**
 * This class is a miscellaneous garbage dump for operations that are simultaneously
 * necessary from multiple application contexts. Also some singleton utility objects
 * are maintained here.
 * 
 * @author alankila
 */
public class Application extends android.app.Application {
	protected static Application app;
	private static final String TAG = Application.class.getSimpleName();
	private static int protectionMoneyPaid;

	private static SongDatabase songDatabase;
	private static Player player;

	public static File getPluginDataDirectory(Class<? extends DroidSoundPlugin> pluginClass) {
		return app.getDir(pluginClass.getSimpleName(), Context.MODE_PRIVATE);
	}

	public static AssetManager getAssetManager() {
		return app.getAssets();
	}

	public static File getModsDirectory() {
		return new File(Environment.getExternalStorageDirectory(), "MODS");
	}

	public static File getTmpDirectory() {
		return app.getDir("tmp", Context.MODE_PRIVATE);
	}

	public static SharedPreferences getAppPreferences() {
		return PreferenceManager.getDefaultSharedPreferences(app);
	}

	public static String packageName() {
		return app.getPackageName();
	}

	public static SongDatabase getSongDatabase() {
		return songDatabase;
	}

	@Override
	public void onCreate() {
		super.onCreate();
		app = this;
		songDatabase = new SongDatabase(this);

		setupModsDir();

		PreferenceManager.setDefaultValues(this, R.layout.preferences, false);
		SharedPreferences prefs = getAppPreferences();
		Map<String, ?> prefsMap = prefs.getAll();

		for (DroidSoundPlugin plugin : DroidSoundPlugin.getPluginList()) {
			String pluginClass = plugin.getClass().getSimpleName();
			for (Entry<String, ?> entry : prefsMap.entrySet()) {
				String k = entry.getKey();
				int dot = k.indexOf('.');
				if (dot == -1) {
					continue;
				}

				if (k.substring(0, dot).equals(pluginClass)) {
					Object val = entry.getValue();
					plugin.setOption(k.substring(dot+1), val);
				}
			}
		}
	}

	private void setupModsDir() {
		File modsDir = getModsDirectory();
		if (! modsDir.exists()) {
			if (! modsDir.mkdirs()) {
				Toast.makeText(this, "Directory " + modsDir.getPath() + " could not be accessed nor created.", Toast.LENGTH_LONG).show();
				return;
			}

			File tempFile = new File(modsDir, "Examples.zip");
			if (! tempFile.exists()) {
				try {
					InputStream is = getAssets().open("Examples.zip");
					FileOutputStream os = new FileOutputStream(tempFile);
					StreamUtil.copy(is, os);
					os.close();
					is.close();

					FileWriter fw = new FileWriter(new File(modsDir, ".nomedia"));
					fw.close();

					Toast.makeText(this, getString(R.string.mods_setup), Toast.LENGTH_LONG).show();
				} catch (IOException e) {
					Toast.makeText(this, e.toString(), Toast.LENGTH_LONG).show();
				}
			}
		}
	}

	public static void payProtectionMoney(int amount) {
		if (protectionMoneyPaid == 0) {
			app.startService(new Intent(app, ProtectionMoneyService.class));
		}

		protectionMoneyPaid += amount;

		if (protectionMoneyPaid == 0) {
			app.stopService(new Intent(app, ProtectionMoneyService.class));
		}
	}

	public static void broadcast(Intent intent) {
		app.sendBroadcast(intent);
	}

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
	private static void startPlayerThread(DroidSoundPlugin p1, final FilesEntry song, String n1, byte[] d1, String n2, byte[] d2) {
		Log.i(TAG, "Requesting player thread to start");
		if (player != null) {
			throw new RuntimeException("Playerthread was still running. Someone must call stopPlayerThread() first.");
		}
		payProtectionMoney(1);

		ServiceConnection sc = new ServiceConnection() {
			@Override
			public void onServiceConnected(ComponentName arg0, IBinder b) {
				((ProtectionMoneyService.LocalBinder) b).setOngoingNotification(song.getTitle());
				app.unbindService(this);
			}
			@Override
			public void onServiceDisconnected(ComponentName arg0) {
			}
		};
		app.bindService(new Intent(app, ProtectionMoneyService.class), sc, Context.BIND_AUTO_CREATE);

		player = new Player(songDatabase, p1, song, n1, d1, n2, d2);
		player.executeOnExecutor(AsyncTask.THREAD_POOL_EXECUTOR);
	}

	/**
	 * This method returns only after it has guaranteed that the playerthread has exited,
	 * or it gets interrupted.
	 *
	 * @throws InterruptedException
	 */
	private static void stopPlayerThread() throws InterruptedException {
		Log.i(TAG, "Requesting player thread to stop");
		if (player == null) {
			throw new RuntimeException("Playerthread was not running. Someone must call startPlayerThread() first.");
		}

		player.setStateRequest(State.STOP);
		try {
			player.get();
		}
		catch (ExecutionException ee) {
			Log.w(TAG, "Playerthread terminated in exception.", ee);
		}
		player = null;
		payProtectionMoney(-1);
	}

	private static PlayQueue playQueue;

	/**
	 * Start playing a song identified by SongFile parameter.
	 *
	 * @param song
	 * @return
	 * @throws IOException
	 * @throws InterruptedException
	 */
	public static boolean playMod(FilesEntry song) throws IOException, InterruptedException {
		payProtectionMoney(1);

		/* Plugins will be used to try load the file now, so stop player thread if it is running. */
		if (player != null) {
			stopPlayerThread();
		}

		List<SongFileData> files = songDatabase.getSongFileData(song);
		String basename1 = files.get(0).getFile().getName();
		byte[] data1 = files.get(0).getData();
		String basename2 = files.size() == 2 ? files.get(1).getFile().getName() : null;
		byte[] data2 = files.size() == 2 ? files.get(1).getData() : null;

		/* Scan plugin list looking for the one that can handle the file and agrees to load it. */
		DroidSoundPlugin currentPlugin = null;
		for (DroidSoundPlugin plugin : DroidSoundPlugin.getPluginList()) {
			if (plugin.canHandle(basename1) && plugin.load(basename1, data1, basename2, data2)) {
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

		payProtectionMoney(-1);
		return true;
	}

	public static boolean playPause(boolean play) throws IOException, InterruptedException {
		if (player != null && player.getStateRequest() != State.STOP) {
			player.setStateRequest(play ? State.PLAY : State.PAUSE);
			return true;
		} else if (play && playQueue != null) {
			playMod(playQueue.getCurrent());
		}
		return false;
	}

	public static boolean stop() {
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

	public static boolean seekTo(int msec) {
		if (player != null) {
			player.setSeekRequest(msec);
			return true;
		}
		return false;
	}

	public static boolean setSubSong(int song) {
    	if (playQueue == null) {
    		return false;
    	}

    	if (player != null) {
    		player.setSubSongRequest(song);
    		return true;
    	}

    	return false;
	}

	public static boolean playPlaylist(List<FilesEntry> names, int startIndex, boolean shuffle) throws IOException, InterruptedException {
		playQueue = new PlayQueue(names, startIndex, shuffle);
		return playMod(playQueue.getCurrent());
	}

	public static boolean playNext() throws IOException, InterruptedException {
		if (player != null && player.getStateRequest() != State.STOP) {
			int cs = player.getCurrentSubsong();
			int ms = player.getMaxSubsong();
			int def = player.getDefaultSubsong();

			cs ++;
			if (cs >= ms) {
				cs = 0;
			}
			if (cs != def) {
				player.setSubSongRequest(cs);
				return true;
			}
		}
		if (playQueue == null) {
			return false;
		}

		FilesEntry song = playQueue.next();
		return playMod(song);
	}

	public static boolean playPrev() throws IOException, InterruptedException {
		if (player != null && player.getStateRequest() != State.STOP) {
			int cs = player.getCurrentSubsong();
			int ms = player.getMaxSubsong();
			int def = player.getDefaultSubsong();

			if (cs != def) {
				cs --;
				if (cs < 0) {
					cs = ms - 1;
				}
				player.setSubSongRequest(cs);
				return true;
			}
		}
    	if (playQueue == null) {
    		return false;
    	}
    	FilesEntry song = playQueue.prev();
    	return playMod(song);
	}

	public static Queue<Data> enableFftQueue() {
		if (player == null) {
			return null;
		}

		return player.enableFftQueue();
	}

	public static void disableFftQueue() {
		if (player == null) {
			return;
		}

		player.disableFftQueue();
	}
}
