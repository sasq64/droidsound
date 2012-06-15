package com.ssb.droidsound.plugins;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

import com.ssb.droidsound.service.FileSource;



public class GMEPlugin extends DroidSoundPlugin {
	private static final String TAG = GMEPlugin.class.getSimpleName();
	
	static {
		System.loadLibrary("gme");
	}

	private Set<String> extensions;
	
	static String [] ex = { "SPC", "GYM", "NSF", "NSFE", "GBS", "AY", "SAP", "VGM", "VGZ", "HES", "KSS" };
	
	long currentSong = 0;

	public GMEPlugin() {
		extensions = new HashSet<String>();
		for(String s : ex) {			
			extensions.add(s);
		}
	}
	
	@Override
	public boolean canHandle(FileSource fs) {
		return extensions.contains(fs.getExt());
	}

	
	@Override
	public void getDetailedInfo(List<String> list) {
		
		String s = N_getStringInfo(currentSong, INFO_TYPE);
		if(s != null & s.length() > 0) {
			list.add("Format");
			list.add("GME: " + s);
		}
		s = N_getStringInfo(currentSong, INFO_COPYRIGHT);
		if(s != null & s.length() > 0) {
			list.add("Copyright");
			list.add(s);
		}
		s = N_getStringInfo(currentSong, INFO_GAME);
		if(s != null & s.length() > 0) {
			list.add("Game");
			list.add(s);
		}		
	}
	
	@Override
	public boolean load(FileSource fs) {
		if(fs.isFile()) 		
			currentSong = N_loadFile(fs.getFile().getPath());
		else
			currentSong = N_load(fs.getContents(), (int) fs.getLength());
		return (currentSong != 0);
	}
	
	@Override
	public boolean loadInfo(FileSource fs)  {
		if(fs.isFile()) 		
			currentSong = N_loadFile(fs.getFile().getPath());
		else
			currentSong = N_load(fs.getContents(), (int) fs.getLength());
		return (currentSong != 0);
	}

	@Override
	public void unload() {
		if(currentSong > 0)
			N_unload(currentSong);
		currentSong = 0;
	}
	
	@Override
	public String getVersion() {
		return "Game Music Emu v0.5.5\nCopyright (C) 2003-2007 Shay Green";
	}
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	@Override
	public int getSoundData(short [] dest, int size) { return N_getSoundData(currentSong, dest, size); }	
	@Override
	public boolean seekTo(int seconds) { return N_seekTo(currentSong, seconds); }
	@Override
	public boolean setTune(int tune) {
		return N_setTune(currentSong, tune);
	}
	@Override
	public String getStringInfo(int what) {
		if(currentSong <= 0) {
			return null;
		}
		return N_getStringInfo(currentSong, what);
	}
	@Override
	public int getIntInfo(int what) {
		
		if(currentSong <= 0) {
			return 0;
		}
		return N_getIntInfo(currentSong, what);
	}

	native public boolean N_canHandle(String name);
	native public long N_load(byte [] module, int size);
	native public long N_loadFile(String name);
	native public void N_unload(long song);
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native public int N_getSoundData(long song, short [] dest, int size);	
	native public boolean N_seekTo(long song, int seconds);
	native public boolean N_setTune(long song, int tune);
	native public String N_getStringInfo(long song, int what);
	native public int N_getIntInfo(long song, int what);

}
