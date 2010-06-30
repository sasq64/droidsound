package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class SidPlugin implements DroidSoundPlugin {

	static {
		System.loadLibrary("sidplay");
	}

	SidPlugin() {
	}
	
	public boolean canHandle(String name) { return N_canHandle(name); }
	public Object load(byte [] module, int size) { return N_load(module, size); }
	public void unload(Object song) { N_unload(); }
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	public int getSoundData(Object song, short [] dest, int size) { return N_getSoundData(dest, size); }	
	public boolean seekTo(Object song, int seconds) { return N_seekTo(seconds); }
	public boolean setTune(Object song, int tune) { return N_setSong(tune); }
	public String getStringInfo(Object song, int what) { return N_getStringInfo(what); }
	public int getIntInfo(Object song, int what) { return N_getIntInfo(what); }

	native public boolean N_canHandle(String name);
	native public boolean N_load(byte [] module, int size);
	native public void N_unload();
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native public int N_getSoundData(short [] dest, int size);	
	native public boolean N_seekTo(int seconds);
	native public boolean N_setSong(int song);
	native public String N_getStringInfo(int what);
	native public int N_getIntInfo(int what);

	@Override
	public Object loadInfo(File file) throws IOException {
		Object ref = load(file);
		N_unload();
		return ref;
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
