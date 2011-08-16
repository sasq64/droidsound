package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.IOException;
import java.util.*;

import android.R;


public final class GMEPlugin extends DroidSoundPlugin {

	static {
		System.loadLibrary("gme"); //$NON-NLS-1$
	}
	private final Set<String> extensions;
	private static final String [] ex = { "SPC", "GYM", "NSF", "NSFE", "GBS", "AY", "SAP", "VGM", "VGZ", "HES", "KSS" }; //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$ //$NON-NLS-5$ //$NON-NLS-6$ //$NON-NLS-7$ //$NON-NLS-8$ //$NON-NLS-9$ //$NON-NLS-10$ //$NON-NLS-11$
	private long currentSong = 0;
	public GMEPlugin() {
		extensions = new HashSet<String>();
		/*for(String s : ex) {
			extensions.add(s);
		}*/
        Collections.addAll(extensions, ex); //Removes manual array-collection copy
	}

	@Override
	public boolean canHandle(String name) {
		int x = name.lastIndexOf('.');
		if(x < 0) {
			return false;
		}
		String ext = name.substring(x+1).toUpperCase();
		return extensions.contains(ext);
	}


	@Override
	public String[] getDetailedInfo() {
		List<String> list = new ArrayList<String>();
		//String instruments = N_getStringInfo((Long)song, 100);
		String s = N_getStringInfo(currentSong, INFO_TYPE);
		if(s != null && s.length() > 0) {
			list.add("Format");
			list.add("GME: " + s); //$NON-NLS-1$
		}
		s = N_getStringInfo(currentSong, INFO_COPYRIGHT);
		if(s != null && s.length() > 0) {
			list.add("Copyright");
			list.add(s);
		}
		s = N_getStringInfo(currentSong, INFO_GAME);
		if(s != null && s.length() > 0) {
			list.add("Game");
			list.add(s);
		}

		String [] info = new String [list.size()];
		for(int i=0; i<info.length; i++) {
			info[i] = list.get(i);
		}
		return info;
	}

	@Override
	public boolean load(File file) {
		currentSong = N_loadFile(file.getPath());
		return (currentSong != 0);
	}

	public boolean loadInfo(File file) {
		currentSong = N_loadFile(file.getPath());
		return (currentSong != 0);
	}

	@Override
	public boolean load(String name, byte [] module, int size) {
		currentSong = N_load(module, size);
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
	public int getSoundData(short [] dest, int size) { return N_getSoundData(currentSong, dest, size); }
	@Override
	public boolean seekTo(int seconds) { return N_seekTo(currentSong, seconds); }
	@Override
	public boolean setTune(int tune) { return N_setTune(currentSong, tune); }
	@Override
	public String getStringInfo(int what) { return N_getStringInfo(currentSong, what); }
	@Override
	public int getIntInfo(int what) { return N_getIntInfo(currentSong, what); }

	public native boolean N_canHandle(String name);
	public native long N_load(byte [] module, int size);
	public native long N_loadFile(String name);
	public native void N_unload(long song);

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	public native int N_getSoundData(long song, short [] dest, int size);
	public native boolean N_seekTo(long song, int seconds);
	public native boolean N_setTune(long song, int tune);
	public native String N_getStringInfo(long song, int what);
	public native int N_getIntInfo(long song, int what);

}
