package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class ModPlugin implements DroidSoundPlugin {
	
	static {
		System.loadLibrary("modplug");
	}

	ModPlugin() {
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
	native public boolean N_loadInfo(byte [] module, int size);
	native public void N_unload();
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native public int N_getSoundData(short [] dest, int size);	
	native public boolean N_seekTo(int seconds);
	native public boolean N_setSong(int song);
	native public String N_getStringInfo(int what);
	native public int N_getIntInfo(int what);

	@Override
	public boolean loadInfo(File file) throws IOException {
		int l = (int)file.length();
		byte [] songBuffer = new byte [l];
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		boolean ok =  N_load(songBuffer, l);
		N_unload();
		return ok;
	}

	@Override
	public boolean load(File file) throws IOException {
		int l = (int)file.length();
		byte [] songBuffer = new byte [l];
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		return N_load(songBuffer, l); 
	}
}
