package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class GMEPlugin extends DroidSoundPlugin {
	static {
		System.loadLibrary("gme");
	}

	private static final Set<String> EXTENSIONS = new HashSet<String>(Arrays.asList(
			"SPC", "GYM", "NSF", "NSFE", "GBS", "AY", "SAP", "VGM", "VGZ",
			"HES", "KSS"));

	long currentSong = 0;

	@Override
	public boolean canHandle(String name) {
		int x = name.lastIndexOf('.');
		if (x < 0)
			return false;
		String ext = name.substring(x + 1).toUpperCase();
		return EXTENSIONS.contains(ext);
	}

	@Override
	public void setOption(String string, Object val) {
		/* No options */
	}

	@Override
	public String[] getDetailedInfo() {
		List<String> list = new ArrayList<String>();

		String s = N_getStringInfo(currentSong, INFO_TYPE);
		if (s != null & s.length() > 0) {
			list.add("Format");
			list.add("GME: " + s);
		}
		s = N_getStringInfo(currentSong, INFO_COPYRIGHT);
		if (s != null & s.length() > 0) {
			list.add("Copyright");
			list.add(s);
		}
		s = N_getStringInfo(currentSong, INFO_GAME);
		if (s != null & s.length() > 0) {
			list.add("Game");
			list.add(s);
		}

		String[] info = new String[list.size()];
		for (int i = 0; i < info.length; i++) {
			info[i] = list.get(i);
		}

		return info;
	}

	@Override
	public boolean load(File file) throws IOException {
		currentSong = N_loadFile(file.getPath());
		return (currentSong != 0);
	}

	public boolean loadInfo(File file) throws IOException {
		currentSong = N_loadFile(file.getPath());
		return (currentSong != 0);
	}

	@Override
	public boolean load(String name, byte[] module) {
		currentSong = N_load(module, module.length);
		return (currentSong != 0);
	}

	@Override
	public void unload() {
		N_unload(currentSong);
		currentSong = 0;
	}

	@Override
	public String getVersion() {
		return "Game Music Emu v0.5.2\nCopyright (C) 2003-2006 Shay Green";
	}

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	@Override
	public int getSoundData(short[] dest, int size) {
		return N_getSoundData(currentSong, dest, size);
	}

	@Override
	public boolean seekTo(int seconds) {
		return N_seekTo(currentSong, seconds);
	}

	@Override
	public boolean setTune(int tune) {
		return N_setTune(currentSong, tune);
	}

	@Override
	public String getStringInfo(int what) {
		return N_getStringInfo(currentSong, what);
	}

	@Override
	public int getIntInfo(int what) {
		return N_getIntInfo(currentSong, what);
	}

	native private boolean N_canHandle(String name);

	native private long N_load(byte[] module, int size);

	native private long N_loadFile(String name);

	native private void N_unload(long song);

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native private int N_getSoundData(long song, short[] dest, int size);

	native private boolean N_seekTo(long song, int seconds);

	native private boolean N_setTune(long song, int tune);

	native private String N_getStringInfo(long song, int what);

	native private int N_getIntInfo(long song, int what);

}
