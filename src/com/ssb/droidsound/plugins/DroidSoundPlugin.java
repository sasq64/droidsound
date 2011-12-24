package com.ssb.droidsound.plugins;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;
import java.util.List;

public abstract class DroidSoundPlugin {
	private static final MessageDigest MD5;
	static {
		try {
			MD5 = MessageDigest.getInstance("MD5");
		} catch (NoSuchAlgorithmException e) {
			throw new ExceptionInInitializerError(e);
		}
	}

	private static final List<DroidSoundPlugin> PLUGINS = Arrays.asList(
			new VICEPlugin(),
			new ModPlugin(),
			new GMEPlugin(),
			new SC68Plugin(),
			new UADEPlugin(),
			new HivelyPlugin()
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

	public abstract void unload();

	public abstract boolean canHandle(String name);

	public abstract boolean load(String name, byte[] module);

	public void load(String f1, byte[] data1, String f2, byte[] data2) {
		/* Currently ignoring the secondary file. Some plugins are expected to use it.
		 * Some plugins (UADE, VICE) may be able to use it. */
		load(f1, data1);
	}

	public abstract int getSoundData(short[] dest);

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
	public String[] getDetailedInfo() {
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

	public boolean canSeek() {
		return false;
	}

	public abstract String getVersion();
}
