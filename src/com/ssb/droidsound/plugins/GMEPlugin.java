package com.ssb.droidsound.plugins;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import android.content.Context;
import android.util.Log;



public class GMEPlugin extends DroidSoundPlugin {
	
	static {
		System.loadLibrary("gme");
	}

	private Set<String> extensions;

	public GMEPlugin(Context ctx) {
		super(ctx);
		extensions = new HashSet<String>();
		extensions.add("SPC");
		extensions.add("GYM");
		extensions.add("NSF");
		extensions.add("GBS");
		extensions.add("AY");
		extensions.add("VGM");
	}
	
	@Override
	public boolean canHandle(String name) {
		int x = name.lastIndexOf('.');
		if(x < 0) return false;
		String ext = name.substring(x+1).toUpperCase();
		return extensions.contains(ext);
	}

	
	@Override
	public String[] getDetailedInfo(Object song) {
		
		List<String> list = new ArrayList<String>();
		//String instruments = N_getStringInfo((Long)song, 100);
		
		String s = getStringInfo(song, INFO_TYPE);
		if(s != null & s.length() > 0) {
			list.add("Format");
			list.add(s);
		}
		s = getStringInfo(song, INFO_COPYRIGHT);
		if(s != null & s.length() > 0) {
			list.add("Copyright");
			list.add(s);
		}
		s = getStringInfo(song, INFO_GAME);
		if(s != null & s.length() > 0) {
			list.add("Game");
			list.add(s);
		}
		
		String [] info = new String [list.size()];
		for(int i=0; i<info.length; i++) {
			info[i] = list.get(i);
		}
		
		return info;
	}

	
	
	@Override
	public void unload(Object song) { N_unload((Long)song); }
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	@Override
	public int getSoundData(Object song, short [] dest, int size) { return N_getSoundData((Long)song, dest, size); }	
	@Override
	public boolean seekTo(Object song, int seconds) { return N_seekTo((Long)song, seconds); }
	@Override
	public boolean setTune(Object song, int tune) { return N_setTune((Long)song, tune); }
	@Override
	public String getStringInfo(Object song, int what) { return N_getStringInfo((Long)song, what); }
	@Override
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

	public Object load(byte [] module, int size) {
		long rc = N_load(module, size);
		if(rc == 0)
			return null;
		else
			return rc;		
	}
}
