package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URLDecoder;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import android.content.Context;
import android.content.SharedPreferences;

import com.ssb.droidsound.utils.Log;

public abstract class DroidSoundPlugin {
	private static final String TAG = DroidSoundPlugin.class.getSimpleName();
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

	private static Object lock = new Object();

	private static Context context;

	public static Context getContext() {
		return context;
	}
	public static void setContext(Context ctx) {
		context = ctx;
	}

	public static List<DroidSoundPlugin> createPluginList() {
		List<DroidSoundPlugin> pluginList;
		synchronized (lock) {
			pluginList = new ArrayList<DroidSoundPlugin>();
			pluginList.add(new VICEPlugin());
			pluginList.add(new ModPlugin());
			pluginList.add(new GMEPlugin());
			pluginList.add(new HivelyPlugin());
			pluginList.add(new SC68Plugin());
			// Keep last
			pluginList.add(new UADEPlugin());
		}
		return pluginList;
	}

	public boolean loadInfo(String name, byte[] module) {
		return load(name, module);
	}

	public boolean load(String name, InputStream is, int size) throws IOException {
		byte[] songBuffer = new byte[size];
		is.read(songBuffer);
		return load(name, songBuffer);
	}

	public synchronized static byte[] calcMD5(byte[] songBuffer) {
		return MD5.digest(songBuffer);
	}

	public boolean load(File file) throws IOException {
		Log.d(TAG, "PLUGIN LOAD FILE");
		int l = (int)file.length();
		byte[] songBuffer = new byte[l];
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		calcMD5(songBuffer);
		return load(file.getName(), songBuffer);
	}

	public abstract void unload();

	public static String getExt(String name) {
		String ext = "";
		int dot = name.lastIndexOf('.');
		if(dot > 0) {
			ext = name.substring(dot);
			char c = 'X';
			int e = 0;
			while(e < ext.length() && Character.isLetterOrDigit(c)) {
				e++;
				if(e == ext.length())
						break;
				c = ext.charAt(e);
			}
			ext = ext.substring(0,e);
		}
		return ext;
	}


	public boolean canHandle(String name) {
		return canHandleExt(getExt(name));
	}

	public boolean canHandleExt(String ext) { return false; }

	public abstract boolean load(String name, byte[] module);

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	public abstract int getSoundData(short [] dest, int size);

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

		if(fname.startsWith("http:/")) {
			fname = URLDecoder.decode(fname);
		}


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

	public abstract void setOption(String string, String val);

	public static void setOptions(SharedPreferences prefs) {
		List<DroidSoundPlugin> list = DroidSoundPlugin.createPluginList();
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
					plugin.setOption(k.substring(dot+1), String.valueOf(val));
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

	public String getVersion() {
		return "Unknown";
	}

	public boolean delayedInfo() {
		return false;
	}

	public void close() {
	}
}
