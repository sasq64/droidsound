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

	public abstract boolean canHandle(String name);

	protected abstract boolean load(String name, byte[] module);

	public boolean load(String f1, byte[] data1, String f2, byte[] data2) {
		if (f2 != null) {
			throw new RuntimeException("This plugin is not handling a 2nd file.");
		}
		return load(f1, data1);
	}

	public abstract int getSoundData(short[] dest);

	public abstract void unload();

	public int getIntInfo(int what) {
		return 0;
	}

	public boolean seekTo(int msec) {
		return false;
	}

	public boolean setTune(int tune) {
		return false;
	}

	public String[] getDetailedInfo() {
		return null;
	}

	public abstract String getStringInfo(int what);

	public boolean isSilent() {
		return false;
	}

	public abstract void setOption(String string, Object val);

	public boolean canSeek() {
		return false;
	}

	public abstract String getVersion();
}
