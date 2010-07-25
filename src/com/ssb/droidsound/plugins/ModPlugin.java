package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

import com.ssb.droidsound.SongDatabase;

import android.util.Log;


public class ModPlugin extends DroidSoundPlugin {
	private static final String TAG = ModPlugin.class.getSimpleName();
	
	static {
		System.loadLibrary("modplug");
	}
	private Set<String> extensions;

	public ModPlugin() {		
		extensions = new HashSet<String>();
		extensions.add("MOD");
		extensions.add("XM");
		extensions.add("S3M");
		extensions.add("IT");
	}

	@Override
	public boolean canHandle(String name) {
		int x = name.lastIndexOf('.');
		if(x < 0) return false;
		String ext = name.substring(x+1).toUpperCase();
		return extensions.contains(ext);
	}
	
	@Override
	public Object load(byte [] module, int size) {
		long rc = N_load(module, size);		
		return rc != 0 ? rc : null; 
	}
	@Override
	public void unload(Object song) { N_unload((Long)song); }
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	@Override
	public int getSoundData(Object song, short [] dest, int size) { return N_getSoundData((Long)song, dest, size); }	
	@Override
	public boolean seekTo(Object song, int seconds) { return N_seekTo((Long)song, seconds); }
	@Override
	public boolean setTune(Object song, int tune) { return false; }
	@Override
	public String getStringInfo(Object song, int what) { return N_getStringInfo((Long)song, what); }
	@Override
	public int getIntInfo(Object song, int what) { return N_getIntInfo((Long)song, what); }

	@Override
	public Object loadInfo(File file) throws IOException {
		int l = (int)file.length();
		byte [] songBuffer = new byte [l];
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		
		//String magic = new String(songBuffer, 0x438,4);	
		//Log.v(TAG, String.format(">> Magic '%s'", magic));
		
		long song = N_load(songBuffer, l);
		if(song == 0)
			return null;
		else
			return song;
	}

	/*
	void data() {
		if(type != null && type.equals("MOD")) {
			String fname = file.getName();
			int sep = fname.indexOf(" - ");
			if(sep > 0) {
				author = fname.substring(0, sep);
				Log.v(TAG, String.format("######## FILENAME %s", fname));
				int dot = fname.lastIndexOf('.');
				if(dot > 0) {
					String ext = fname.substring(dot+1).toUpperCase();
					Log.v(TAG, String.format("Extention %s", ext));
					if(ext.equals("MOD") || ext.equals("IT") || ext.equals("XM") || ext.equals("S3M")) {
						title = fname.substring(sep+3, dot);
					} else {
						title = fname.substring(sep+3);
					}
				} else {						
					title = fname.substring(sep+3);
				}
			} else {
				author = file.getParentFile().getName();
			}
		}*/

	
	// --- Native functions
	
	native public boolean N_canHandle(String name);
	native public long N_load(byte [] module, int size);
	native public long N_loadInfo(byte [] module, int size);
	native public void N_unload(long song);
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native public int N_getSoundData(long song, short [] dest, int size);	
	native public boolean N_seekTo(long song, int seconds);
	native public boolean N_setTune(long song, int tune);
	native public String N_getStringInfo(long song, int what);
	native public int N_getIntInfo(long song, int what);

}
