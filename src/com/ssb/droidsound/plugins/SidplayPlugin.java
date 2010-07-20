package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import com.ssb.droidsound.DroidSoundPlugin;

public class SidplayPlugin implements DroidSoundPlugin {

	static {
		System.loadLibrary("sidplay2");
	}
	
	private static class Info {
		String name;
		String composer;
		String copyright;
	};

	public SidplayPlugin() {
	}
	
	@Override
	public boolean canHandle(String name) { 
		//return N_canHandle(name);
		return name.toLowerCase().endsWith(".sid");
	}

	@Override
	public void unload(Object song) {
		if(song instanceof Info) {
			return;
		}
		N_unload((Long)song);
	}
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	@Override
	public int getSoundData(Object song, short [] dest, int size) { return N_getSoundData((Long)song, dest, size); }	
	@Override
	public boolean seekTo(Object song, int seconds) { return N_seekTo((Long)song, seconds); }
	@Override
	public boolean setTune(Object song, int tune) { return N_setTune((Long)song, tune); }
	@Override
	public int getIntInfo(Object song, int what) {
		if(song instanceof Info) {
			return 0;
		}
		return N_getIntInfo((Long)song, what);
	}

	native public long N_load(byte [] module, int size);
	native public void N_unload(long song);
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native public int N_getSoundData(long song, short [] dest, int size);
	native public boolean N_seekTo(long song, int seconds);
	native public boolean N_setTune(long song, int tune);
	native public String N_getStringInfo(long song, int what);
	native public int N_getIntInfo(long song, int what);

	@Override
	public Object load(byte [] module, int size) { return N_load(module, size); }

	@Override
	public String getStringInfo(Object song, int what) {
		if(song instanceof Info) {
			Info info = (Info)song;
			switch(what) {
			case INFO_AUTHOR:
				return info.composer;
			case INFO_COPYRIGHT:
				return info.copyright;
			case INFO_TITLE:
				return info.name;
			}
			return null;
		}
		return N_getStringInfo((Long)song, what);
	}

	@Override
	public Object loadInfo(File file) throws IOException {

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
		int o = 31;
		while(o >= 0 && name[o] == 0) {
			o -= 1;
		}
		
		Info info = new Info();
		
		info.name = new String(name, 0, o+1, "ISO-8859-1");

		o = 31;
		while(o >= 0 && composer[o] == 0) {
			o -= 1;
		}
		info.composer = new String(composer, 0, o+1, "ISO-8859-1");
		
		o = 31;
		while(o >= 0 && copyright[o] == 0) {
			o -= 1;
		}
		info.copyright = new String(copyright, 0, o+1, "ISO-8859-1");
		
		return info;
		
	}

	@Override
	public Object load(File file) throws IOException {
		
		loadInfo(file);
		
		int l = (int)file.length();
		byte [] songBuffer = new byte [l];
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		fs.close();
		
		return N_load(songBuffer, l); 
	}
}
