package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

import com.ssb.droidsound.SongDatabase;

import android.content.Context;
import android.util.Log;


public class ModPlugin extends DroidSoundPlugin {
	private static final String TAG = ModPlugin.class.getSimpleName();
	
	static {
		System.loadLibrary("modplug");
	}
	private Set<String> extensions;

	public ModPlugin(Context ctx) {
		super(ctx);
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

		long song = N_load(songBuffer, l);
		if(song == 0)
			return null;
		else
			return song;
	}
	
	@Override
	public String[] getDetailedInfo(Object song) {
		
		String instruments = N_getStringInfo((Long)song, 100);
		Log.v(TAG, "INSTRUMENTS: " + instruments);
		int channels = N_getIntInfo((Long)song, 101);

		String[] info;
		if(instruments != null && instruments.length() > 0) {
			info = new String [4];
			info[2] = "Instruments";
			info[3] = instruments;
		} else {
			info = new String [2];
		}
		info[0] = "Channels";
		info[1] = Integer.toString(channels);
		return info;
	}
	
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
