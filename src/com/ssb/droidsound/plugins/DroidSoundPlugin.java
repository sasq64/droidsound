package com.ssb.droidsound.plugins;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import android.content.SharedPreferences;

public abstract class DroidSoundPlugin {
	private static final MessageDigest MD5;
	private static final Map<String, String> MAIN_TO_AUX = new HashMap<String, String>();
	static {
		try {
			MD5 = MessageDigest.getInstance("MD5");
		} catch (NoSuchAlgorithmException e) {
			throw new ExceptionInInitializerError(e);
		}

		MAIN_TO_AUX.put("MDAT", "SMPL");
		MAIN_TO_AUX.put("TFX", "SAM");
		MAIN_TO_AUX.put("SNG", "INS");
		MAIN_TO_AUX.put("RJP", "SMP");
		MAIN_TO_AUX.put("JPN", "SMP");
		MAIN_TO_AUX.put("DUM", "INS");
	}

	private static final List<DroidSoundPlugin> PLUGINS = Arrays.asList(
			new VICEPlugin(),
			new ModPlugin(),
			new GMEPlugin(),
			new HivelyPlugin(),
			new SC68Plugin(),
			// Keep last
			new UADEPlugin()
	);

	public static final int INFO_TITLE = 0;
	public static final int INFO_AUTHOR = 1;
	public static final int INFO_LENGTH = 2;
	public static final int INFO_TYPE = 3;
	public static final int INFO_COPYRIGHT = 4;
	public static final int INFO_GAME = 5;
	public static final int INFO_SUBTUNE_COUNT = 6;
	public static final int INFO_STARTTUNE = 7;
	public static final int INFO_SUBTUNE_TITLE = 8;
	public static final int INFO_SUBTUNE_AUTHOR = 9;
	public static final int INFO_SUBTUNE_NO = 10;
	public static final int INFO_DETAILS_CHANGED = 15;

	public static final int OPT_FILTER = 1;
	public static final int OPT_RESAMPLING = 2;
	public static final int OPT_NTSC = 3;
	public static final int OPT_SPEED_HACK = 4;
	public static final int OPT_PANNING = 5;
	public static final int OPT_FILTER_BIAS = 6;
	public static final int OPT_SID_MODEL = 7;

	public synchronized static byte[] calcMD5(byte[] songBuffer) {
		return MD5.digest(songBuffer);
	}

	public static List<DroidSoundPlugin> getPluginList() {
		return PLUGINS;
	}

	public boolean loadInfo(String name, byte[] module) {
		return load(name, module);
	}

	public boolean load(File file) throws IOException {
		byte[] songBuffer = new byte[(int) file.length()];
		DataInputStream fs = new DataInputStream(new FileInputStream(file));
		fs.readFully(songBuffer);
		fs.close();
		calcMD5(songBuffer);
		return load(file.getName(), songBuffer);
	}

	public abstract void unload();

	public abstract boolean canHandle(String name);

	protected abstract boolean load(String name, byte[] module);

	public abstract int getSoundData(short[] dest, int size);

	public boolean seekTo(int msec) {
		return false;
	}

	public boolean setTune(int tune) {
		return false;
	}

	// Should return information in string pairs, as TITLE0, TEXT0, TITLE1, TEXT1 etc
	// Some titles are predfined and excpect certain data
	// Unknown titles are presented as-is in detailed song info
	// Known TITLES:
	// "Instruments" - Instrument names, one instrument per line
	// "Info" - STIL info for C64, otherwise presented normally
	// "Channels" - Number of channels
	// "Copyright" - Same as INFO_COPYRIGHT
	// "Game" - Same as INFO_GAME
	public String [] getDetailedInfo() {
		return null;
	}

	public abstract String getStringInfo(int what);
	public abstract int getIntInfo( int what);

	public boolean isSilent() {
		return false;
	}

	public String getBaseName(String fname) {
		int slash = fname.lastIndexOf('/');
		if(slash >= 0) {
			fname = fname.substring(slash+1);
		}
		int dot = fname.lastIndexOf('.');
		if(dot > 0) {
			fname = fname.substring(0, dot);
		}
		return fname;
	}

	public abstract void setOption(String string, Object val);

	public static void setOptions(SharedPreferences prefs) {
		List<DroidSoundPlugin> list = DroidSoundPlugin.getPluginList();
		Map<String, ?> prefsMap = prefs.getAll();

		for (DroidSoundPlugin plugin : list) {
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

	public static String getSecondaryFile(String path) {
		int dot = path.lastIndexOf('.');
		int slash = path.lastIndexOf('/');
		if (dot <= slash) {
			return null;
		}

		int firstDot = path.indexOf('.', slash+1);
		String ext = path.substring(dot+1).toUpperCase();
		String pref = path.substring(slash+1, firstDot).toUpperCase();

		if (MAIN_TO_AUX.containsKey(pref)) {
			return path.substring(0, slash+1) + MAIN_TO_AUX.get(pref) + path.substring(firstDot);
		} else if (MAIN_TO_AUX.containsKey(ext)) {
			return path.substring(0, dot+1) + MAIN_TO_AUX.get(ext);
		}

		return null;
	}

	public boolean canSeek() {
		return false;
	}

	public abstract String getVersion();
}
