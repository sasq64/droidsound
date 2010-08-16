package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

import android.content.Context;

public abstract class DroidSoundPlugin {

	public static final int INFO_TITLE = 0;
	public static final int INFO_AUTHOR = 1;
	public static final int INFO_LENGTH = 2;
	public static final int INFO_TYPE = 3;
	public static final int INFO_COPYRIGHT = 4;
	public static final int INFO_GAME = 5;
	public static final int INFO_SUBTUNES = 6;
	public static final int INFO_STARTTUNE = 7;
	public static final int INFO_SUBTUNE_TITLE = 8;
	
	public static final int SIZEOF_INFO = 9;
	private Context context;

	public boolean canHandle(String name) { return false; }
	
	public DroidSoundPlugin(Context ctx) { context = ctx; }
	
	public Context getContext() { return context; }

	public abstract Object load(byte [] module, int size);

	public Object loadInfo(byte [] module, int size) {
		return load(module, size);
	}
	
	public Object load(InputStream is, int size) throws IOException {
		byte [] songBuffer = new byte [size];
		is.read(songBuffer);
		return load(songBuffer, songBuffer.length);
	}
	
	public Object loadInfo(InputStream is, int size) throws IOException {
		byte [] songBuffer = new byte [size];
		is.read(songBuffer);
		return loadInfo(songBuffer, songBuffer.length);
	}
	
	public Object load(File file) throws IOException {		
		int l = (int)file.length();
		byte [] songBuffer = new byte [l];
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		return load(songBuffer, songBuffer.length);
	}

	public Object loadInfo(File file) throws IOException {
		int l = (int)file.length();
		byte [] songBuffer = new byte [l];
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		return loadInfo(songBuffer, songBuffer.length);
	}

	public abstract void unload(Object song);

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	public abstract int getSoundData(Object song, short [] dest, int size);	

	public boolean seekTo(Object song, int msec) {
		return false;
	}

	public boolean setTune(Object song, int tune) {
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
	public String [] getDetailedInfo(Object song) {
		return null;
	}
	
	public abstract String getStringInfo(Object song, int what);
	public abstract int getIntInfo(Object song, int what);
	
	public boolean isSilent(Object song) {
		return false;
	}
}
