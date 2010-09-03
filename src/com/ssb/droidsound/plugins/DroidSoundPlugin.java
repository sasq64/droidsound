package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import android.content.Context;
import android.content.SharedPreferences;

public abstract class DroidSoundPlugin {

	
	public static final int INFO_TITLE = 0;
	public static final int INFO_AUTHOR = 1;
	public static final int INFO_LENGTH = 2;
	public static final int INFO_TYPE = 3;
	public static final int INFO_COPYRIGHT = 4;
	public static final int INFO_GAME = 5;
	public static final int INFO_SUBTUNES = 6;
	public static final int INFO_STARTTUNE = 7;
	public static final int INFO_SUBTUNE_TITLE = 8;
	
	public static final int SIZEOF_INFO = 9;

	
	
	public static final int OPT_FILTER = 1;
	public static final int OPT_RESAMPLING = 2;
	public static final int OPT_NTSC = 3;
	public static final int OPT_SPEED_HACK = 4;
	public static final int OPT_PANNING = 5;
	

	
	
	private static Context context;
	
	static Object lock = new Object();

	public static void setContext(Context ctx) {
		context = ctx;
	}
	
	public static Context getContext() { return context; }

	
	
	// Called when player thread exits due to inactivty
	public void exit() {		
	};

	
	public static List<DroidSoundPlugin> createPluginList() {
		
		List<DroidSoundPlugin> pluginList;
		synchronized (lock) {				
			pluginList = new ArrayList<DroidSoundPlugin>();
			pluginList.add(new SidplayPlugin());
			pluginList.add(new ModPlugin());
			pluginList.add(new GMEPlugin());
			pluginList.add(new HivelyPlugin());
			pluginList.add(new UADEPlugin());
		}
		return pluginList;				
	}
	
	

	public boolean loadInfo(String name, byte [] module, int size) {
		return load(name, module, size);
	}
	
	public boolean load(String name, InputStream is, int size) throws IOException {
		boolean rc = false;
		try {
			byte [] songBuffer = new byte [size];
			is.read(songBuffer);
			rc = load(name, songBuffer, songBuffer.length);
		} catch (OutOfMemoryError e) {
			e.printStackTrace();
		}
		return rc;
	}
	
	public boolean loadInfo(String name, InputStream is, int size) throws IOException {
		boolean rc = false;
		try {
			byte [] songBuffer = new byte [size];
			is.read(songBuffer);
			rc = loadInfo(name, songBuffer, songBuffer.length);
		} catch (OutOfMemoryError e) {
			e.printStackTrace();
		}
		return rc;
	}
	
	public boolean load(File file) throws IOException {		
		int l = (int)file.length();
		byte [] songBuffer = null;
		try {
			songBuffer = new byte [l];
		} catch (OutOfMemoryError e) {
			e.printStackTrace();
		}		
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		return load(file.getName(), songBuffer, songBuffer.length);
	}

	public boolean loadInfo(File file) throws IOException {
		int l = (int)file.length();
		byte [] songBuffer = null;
		try {
			songBuffer = new byte [l];
		} catch (OutOfMemoryError e) {
			e.printStackTrace();
		}
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		return loadInfo(file.getName(), songBuffer, songBuffer.length);
	}

	public abstract void unload();
	
	public boolean canHandle(String name) { return false; }
	
	public abstract boolean load(String name, byte [] module, int size);

	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	public abstract int getSoundData(short [] dest, int size);	

	public boolean seekTo(int msec) {
		return false;
	}

	public boolean setTune(int tune) {
		return false;
	}

	// Should return information in string pairs, as TITLE0, TEXT0, TITLE1, TEXT1 etc
	// Some titles are predfined and excpect certain data
	// Unknown titles are presented as-is in detailed song info
	// Known TITLES:
	// "Instruments" - Instrument names, one instrument per line
	// "Info" - STIL info for C64, otherwise presented normally
	// "Channels" - Number of channels
	// "Copyright" - Same as INFO_COPYRIGHT
	// "Game" - Same as INFO_GAME
	public String [] getDetailedInfo() {
		return null;
	}
	
	public abstract String getStringInfo(int what);
	public abstract int getIntInfo( int what);
	
	public boolean isSilent() {
		return false;
	}

	public String getBaseName(String fname) {
		int slash = fname.lastIndexOf('/');
		if(slash >= 0) {
			fname = fname.substring(slash+1);
		}
		int dot = fname.lastIndexOf('.');
		if(dot > 0) {
			fname = fname.substring(0, dot);
		}
		return fname;
	}

	//public String[] getOptions() {
	//	return null;
	//}

	public void setOption(String string, Object val) {
	}
	
	

	public static void setOptions(SharedPreferences prefs) {
		List<DroidSoundPlugin> list = DroidSoundPlugin.createPluginList(); 
		Map<String, ?> prefsMap = prefs.getAll();
		
		for(DroidSoundPlugin plugin : list) {

			String plname = plugin.getClass().getSimpleName();

			for(Entry<String, ?> entry  : prefsMap.entrySet()) {
				String k = entry.getKey();
				int dot = k.indexOf('.');
				if(dot >= 0) {
					if(k.substring(0, dot).equals(plname)) {
						plugin.setOption(k.substring(dot+1), entry.getValue());
					}
				}
			}
		}
		
	}

	public static String getSecondaryFile(String path) {
		int dot = path.lastIndexOf('.');
		int slash = path.lastIndexOf('/');
		
		if(path.substring(dot).toUpperCase().equals(".TFX")) {
			return path.substring(0, dot) + ".SAM";
		}
		
		
		
		return null;
	}
}
