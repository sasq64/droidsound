package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

import android.util.Log;

public class SidplayPlugin extends DroidSoundPlugin {

	private static final String TAG = SidplayPlugin.class.getSimpleName();


	static {
		System.loadLibrary("sidplay2");
	}
	
	private static class Info {
		String name;
		String composer;
		String copyright;
	};
	
	final byte [] header = new byte [128];

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
	public Object load(byte [] module, int size) {
		long rc = N_load(module, size);		
		return rc != 0 ? rc : null; 
	}

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
	public String[] getDetailedInfo(Object song) {

		final String sids [] = { "UNKNOWN", "6581", "8580", "6581 & 8580" };
		
		String[] info = new String [4];
		info[0] = "Copyright";
		info[1] = N_getStringInfo((Long)song, INFO_COPYRIGHT);
		int m = N_getIntInfo((Long)song, 101);
		Log.v(TAG, "Sid model " + m);
		if(m <= 3 && m >= 0) {
			info[2] = "SID Model";
			info[3] = sids[m];
		}
		return info;
	}


	@Override
	public Object loadInfo(InputStream is, int size) throws IOException {
		
		Info info = new Info();
		
		is.read(header);
		
		String s = new String(header, 0, 4);
		if(!(s.equals("PSID") || s.equals("RSID"))) {
			return null;
		}

		int o = 0x35;
		while(o >= 0x16 && header[o] == 0) {
			o -= 1;
		}
		info.name = new String(header, 0x16, o-0x15, "ISO-8859-1");

		o = 0x55;
		while(o >= 0x36 && header[o] == 0) {
			o -= 1;
		}
		info.composer = new String(header, 0x36, o-0x35, "ISO-8859-1");

		o = 0x75;
		while(o >= 0x56 && header[o] == 0) {
			o -= 1;
		}
		info.copyright = new String(header, 0x56, o-0x55, "ISO-8859-1");

		return info;	
	}
	
	@Override
	public boolean isSilent(Object song) {
		
		return (N_getIntInfo((Long)song, 100) != 0);
	}
	

	@Override
	public Object load(File file) throws IOException {
		
		//if(loadInfo(file) == null) {
		//	return null;
		//}
		
		int l = (int)file.length();
		byte [] songBuffer = new byte [l];
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		fs.close();

		long rc = N_load(songBuffer, l);		
		return rc != 0 ? rc : null; 
	}
}
