package com.ssb.droidsound.plugins;

import java.nio.charset.Charset;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;


public class ModPlugin extends DroidSoundPlugin {
	private static final Charset ISO88591 = Charset.forName("ISO-8859-1");
	private static final String TAG = ModPlugin.class.getSimpleName();
	static {
		System.loadLibrary("modplug");
	}
	private static final Set<String> extensions = new HashSet<String>(Arrays.asList(
			"XM", "S3M", "IT", "UMX", "ULT", "669", "STM"
	));

	private static String fromData(byte[] module, int start, int len) {
		return new String(module, start, len, ISO88591).replaceAll("\u0000", "").trim();
	}

	private long currentSong = 0;

	@Override
	public boolean canHandle(String name) {
		int x = name.lastIndexOf('.');
		if(x < 0) return false;
		String ext = name.substring(x+1).toUpperCase();
		return extensions.contains(ext);
	}

	@Override
	protected boolean load(String name, byte[] module) {
		currentSong = N_load(module, module.length);
		return currentSong != 0;
	}

	@Override
	public int getSoundData(short[] dest) {
		return N_getSoundData(currentSong, dest, dest.length);
	}

	@Override
	public void unload() {
		N_unload(currentSong);
		currentSong = 0;
	}

	@Override
	public boolean seekTo(int seconds) {
		return N_seekTo(currentSong, seconds);
	}

	@Override
	public boolean setTune(int tune) {
		return false;
	}

	@Override
	public String getStringInfo(int what) {
		return N_getStringInfo(currentSong, what);
	}

	@Override
	public int getIntInfo(int what) {
		return N_getIntInfo(currentSong, what);
	}

	@Override
	public boolean canSeek() {
		return true;
	}

	@Override
	public String[] getDetailedInfo() {
		String instruments = N_getStringInfo(currentSong, 100);
		String fmt = N_getStringInfo(currentSong, INFO_TYPE);
		//Log.d(TAG, "INSTRUMENTS: " + instruments);
		int channels = N_getIntInfo(currentSong, 101);

		String[] info;
		if(instruments != null && instruments.length() > 0) {
			info = new String [6];
			info[4] = "Instruments";
			info[5] = instruments;
		} else {
			info = new String [4];
		}
		info[0] = "Format";
		info[1] = "MODPlug: " + fmt;
		info[2] = "Channels";
		info[3] = Integer.toString(channels);
		return info;
	}

	@Override
	public void setOption(String string, Object val) {
		/* No options */
	}

	@Override
	public String getVersion() {
		return "libmodplug v0.8.?";
	}

	@Override
	protected MusicInfo getMusicInfo(String name, byte[] module) {
		String magic;

		magic = new String(module, 44, 4, ISO88591);
		if (magic.equals("SCRM")) {
			MusicInfo info = new MusicInfo();
			info.title = fromData(module, 0, 28);
			info.format = "S3M";
			return info;
		}

		magic = new String(module, 0, 15, ISO88591);
		if (magic.equals("Extended Module")) {
			MusicInfo info = new MusicInfo();
			info.title = fromData(module, 17, 20);
			info.channels = module[0x68];
			info.format = "XM";
			return info;
		}

		magic = new String(module, 0, 4, ISO88591);
		if (magic.equals("IMPM")) {
			MusicInfo info = new MusicInfo();
			info.title = fromData(module, 4, 26);
			info.format = "IT";
			return info;
		}

		return null;
	}

	native private long N_load(byte [] module, int size);
	native private long N_loadInfo(byte [] module, int size);
	native private void N_unload(long song);

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native private int N_getSoundData(long song, short [] dest, int size);
	native private boolean N_seekTo(long song, int seconds);
	native private boolean N_setTune(long song, int tune);
	native private String N_getStringInfo(long song, int what);
	native private int N_getIntInfo(long song, int what);
}
