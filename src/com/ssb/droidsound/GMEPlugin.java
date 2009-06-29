package com.ssb.droidsound;

public class GMEPlugin implements DroidSoundPlugin {
	
	static {
		System.loadLibrary("gme");
	}

	GMEPlugin() {
	}
	
	public boolean canHandle(String name) { return N_canHandle(name); }
	public boolean load(byte [] module, int size) { return N_load(module, size); }
	public void unload() { N_unload(); }
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	public int getSoundData(short [] dest, int size) { return N_getSoundData(dest, size); }	
	public boolean seekTo(int seconds) { return N_seekTo(seconds); }
	public boolean setSong(int song) { return N_setSong(song); }
	public String getStringInfo(int what) { return N_getStringInfo(what); }
	public int getIntInfo(int what) { return N_getIntInfo(what); }

	native public boolean N_canHandle(String name);
	native public boolean N_load(byte [] module, int size);
	native public void N_unload();
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native public int N_getSoundData(short [] dest, int size);	
	native public boolean N_seekTo(int seconds);
	native public boolean N_setSong(int song);
	native public String N_getStringInfo(int what);
	native public int N_getIntInfo(int what);

}
