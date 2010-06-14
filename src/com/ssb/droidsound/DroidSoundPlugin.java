package com.ssb.droidsound;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

public interface DroidSoundPlugin {

	public static final int INFO_TITLE = 1;
	public static final int INFO_AUTHOR = 2;
	public static final int INFO_LENGTH = 3;
	public static final int INFO_TYPE = 4;
	public static final int INFO_COPYRIGHT = 5;
	public static final int INFO_SUBSONGS = 6;
	public static final int INFO_STARTSONG = 7;
	public static final int INFO_GAME = 8;

	
	boolean canHandle(String name);
	boolean loadInfo(File file) throws IOException;
	boolean load(byte [] module, int size);
	boolean load(File file) throws IOException;

	void unload();
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	int getSoundData(short [] dest, int size);	
	boolean seekTo(int seconds);
	boolean setSong(int song);
	String getStringInfo(int what);
	int getIntInfo(int what);
}
