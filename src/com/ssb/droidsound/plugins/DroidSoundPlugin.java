package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

public interface DroidSoundPlugin {

	public static final int INFO_TITLE = 0;
	public static final int INFO_AUTHOR = 1;
	public static final int INFO_LENGTH = 2;
	public static final int INFO_TYPE = 3;
	public static final int INFO_COPYRIGHT = 4;
	public static final int INFO_GAME = 5;
	public static final int INFO_SUBTUNES = 6;
	public static final int INFO_STARTTUNE = 7;
	
	public static final int SIZEOF_INFO = 8;

	
	boolean canHandle(String name);

	Object loadInfo(File file) throws IOException;
	Object load(byte [] module, int size);
	Object load(File file) throws IOException;

	void unload(Object song);

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	int getSoundData(Object song, short [] dest, int size);	
	boolean seekTo(Object song, int msec);
	boolean setTune(Object song, int tune);
	String getStringInfo(Object song, int what);
	int getIntInfo(Object song, int what);
}
