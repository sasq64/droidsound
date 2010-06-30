package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class GMEPlugin implements DroidSoundPlugin {
	
	static {
		System.loadLibrary("gme");
	}
	
	static Object staticLock = new Object();

	GMEPlugin() {
	}
	
	public boolean canHandle(String name) { return N_canHandle(name); }
	public void unload(Object song) { N_unload((Long)song); }
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	public int getSoundData(Object song, short [] dest, int size) { return N_getSoundData((Long)song, dest, size); }	
	public boolean seekTo(Object song, int seconds) { return N_seekTo((Long)song, seconds); }
	public boolean setTune(Object song, int tune) { return N_setTune((Long)song, tune); }
	public String getStringInfo(Object song, int what) { return N_getStringInfo((Long)song, what); }
	public int getIntInfo(Object song, int what) { return N_getIntInfo((Long)song, what); }

	native public boolean N_canHandle(String name);
	native public long N_load(byte [] module, int size);
	native public void N_unload(long song);
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native public int N_getSoundData(long song, short [] dest, int size);	
	native public boolean N_seekTo(long song, int seconds);
	native public boolean N_setTune(long song, int tune);
	native public String N_getStringInfo(long song, int what);
	native public int N_getIntInfo(long song, int what);

	public Object load(byte [] module, int size) { return N_load(module, size); }
	
	@Override
	public Object[] loadInfo(File file) throws IOException {
		Object [] info = new Object [SIZEOF_INFO];		
		synchronized (staticLock) {			
			Object song = load(file);		
			info[INFO_TITLE] = getStringInfo(song, INFO_TITLE); 
			info[INFO_AUTHOR] = getStringInfo(song, INFO_AUTHOR); 
			info[INFO_COPYRIGHT] = getStringInfo(song, INFO_COPYRIGHT); 
			info[INFO_TYPE] = getStringInfo(song, INFO_TYPE); 
			info[INFO_GAME] = getStringInfo(song, INFO_GAME);
			info[INFO_LENGTH] = getIntInfo(song, INFO_LENGTH);
			info[INFO_STARTTUNE] = getIntInfo(song, INFO_STARTTUNE);
			info[INFO_SUBTUNES] = getIntInfo(song, INFO_SUBTUNES);		
			N_unload((Long)song);
		}

		return info;
	}

	@Override
	public Object load(File file) throws IOException {
		int l = (int)file.length();
		byte [] songBuffer = new byte [l];
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		return N_load(songBuffer, l); 
	}

	

}
