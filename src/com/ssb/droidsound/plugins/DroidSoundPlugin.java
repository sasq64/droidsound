package com.ssb.droidsound.plugins;

import java.io.IOException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;
import java.util.List;

public abstract class DroidSoundPlugin {
	public static class MusicInfo {
		public String title;
		public String composer;
		public String copyright;
		public String format;

		public int channels;
		public int date = -1;
	};

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

	public abstract void setOption(String string, Object val);

	public boolean canSeek() {
		return false;
	}

	public abstract String getVersion();

	protected abstract MusicInfo getMusicInfo(String name, byte[] module);

	private static void fixInfo(String basename, MusicInfo info) {
		if (info.composer == null || info.composer.length() == 0) {
			int sep = basename.indexOf(" - ");
			if (sep > 0) {
				info.composer = basename.substring(0, sep);
				info.title = basename.substring(sep+3);
			}
		}

		if (info.composer != null && info.composer.length() == 0) {
			info.composer = null;
		}

		if (info.title == null || info.title.length() == 0) {
			info.title = basename;
		}

		if (info.date != -1 && info.copyright != null && info.copyright.length() >= 4) {
			info.date = 0;
			try {
				int year = Integer.parseInt(info.copyright.substring(0,4));
				if (year > 1000 && year < 2100) {
					info.date = year * 10000;
				}
			} catch (NumberFormatException e) {
			}
		}
	}

	public static MusicInfo identify(String name1, byte[] module1) throws IOException {
		for (DroidSoundPlugin plugin : DroidSoundPlugin.getPluginList()) {
			if (plugin.canHandle(name1)) {
				MusicInfo info = plugin.getMusicInfo(name1, module1);
				if (info != null) {
					fixInfo(name1, info);
					return info;
				}
			}
		}
		return null;
	}
}
