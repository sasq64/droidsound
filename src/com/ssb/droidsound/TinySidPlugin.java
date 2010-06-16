package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;

public class TinySidPlugin implements DroidSoundPlugin {

	static {
		System.loadLibrary("tinysid");
	}

	private String nameInfo;
	private String composerInfo;
	private String copyrightInfo;

	TinySidPlugin() {
	}
	
	public boolean canHandle(String name) { 
		//return N_canHandle(name);
		return name.toLowerCase().endsWith(".sid");
	}

	public boolean load(byte [] module, int size) { return N_load(module, size); }
	public void unload() { N_unload(); }
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	public int getSoundData(short [] dest, int size) { return N_getSoundData(dest, size); }	
	public boolean seekTo(int seconds) { return N_seekTo(seconds); }
	public boolean setSong(int song) { return N_setSong(song); }
	public String getStringInfo(int what) {
		switch(what) {
		case INFO_AUTHOR:
			return composerInfo;
		case INFO_COPYRIGHT:
			return copyrightInfo;
		case INFO_TITLE:
			return nameInfo;
		}
		return null; //N_getStringInfo(what);
	}
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

	@Override
	public boolean loadInfo(File file) throws IOException {

		byte [] tag = new byte [4];
		byte [] name = new byte [32];
		byte [] composer = new byte [32];
		byte [] copyright = new byte [32];
		FileInputStream fs = new FileInputStream(file);
		fs.read(tag);
		fs.skip(18);
		fs.read(name);
		fs.read(composer);
		fs.read(copyright);
		fs.close();
		
		nameInfo = new String(name);
		composerInfo = new String(composer);
		copyrightInfo = new String(copyright);
		
		return true;
		
	}

	@Override
	public boolean load(File file) throws IOException {
		
		loadInfo(file);
		
		int l = (int)file.length();
		byte [] songBuffer = new byte [l];
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		fs.close();
		
		return N_load(songBuffer, l); 
	}

}
