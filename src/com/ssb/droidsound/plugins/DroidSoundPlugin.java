package com.ssb.droidsound.plugins;

import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import android.content.Context;
import android.content.SharedPreferences;
import android.media.MediaPlayer;

import com.ssb.droidsound.file.FileSource;

public abstract class DroidSoundPlugin {
	@SuppressWarnings("unused")
	private static final String TAG = DroidSoundPlugin.class.getSimpleName();
	
	static {
		System.loadLibrary("stlport_shared");
	}
	
	public static final int INFO_TITLE = 0;
	public static final int INFO_AUTHOR = 1;
	public static final int INFO_LENGTH = 2;
	public static final int INFO_TYPE = 3;
	public static final int INFO_COPYRIGHT = 4;
	public static final int INFO_GAME = 5;
	public static final int INFO_SUBTUNE_COUNT = 6;
	public static final int INFO_STARTTUNE = 7;
	public static final int INFO_SUBTUNE_TITLE = 8;
	public static final int INFO_SUBTUNE_AUTHOR = 9;
	public static final int INFO_SUBTUNE_NO = 10;
	
	//public static final int SIZEOF_INFO = 11;

	public static final int INFO_DETAILS_CHANGED = 15;
	
	
	public static final int OPT_FILTER = 1;
	public static final int OPT_RESAMPLING = 2;
	public static final int OPT_NTSC = 3;
	public static final int OPT_SPEED_HACK = 4;
	public static final int OPT_PANNING = 5;
	public static final int OPT_FILTER_BIAS = 6;
	public static final int OPT_SID_MODEL = 7;

	
	
	private static Context context;
	
	static Object lock = new Object();
	
	public static void setContext(Context ctx) {
		context = ctx;
	}
	
	public static Context getContext() { return context; }

	private byte[] md5;

	//private int streamSize;

	
	
	// Called when player thread exits due to inactivty
	public void exit() {		
	};

	
	public static List<DroidSoundPlugin> createPluginList() {
		
		List<DroidSoundPlugin> pluginList;
		synchronized (lock) {				
			pluginList = new ArrayList<DroidSoundPlugin>();
			//pluginList.add(new VICEPlugin());
			//pluginList.add(new SidplayPlugin());
			pluginList.add(new SidPlugin());
			pluginList.add(new ModPlugin());
			pluginList.add(new GMEPlugin());
			pluginList.add(new HivelyPlugin());
			pluginList.add(new SC68Plugin());
			pluginList.add(new SexyPSFPlugin());
			pluginList.add(new RSNPlugin());
			pluginList.add(new GSFPlugin());
			pluginList.add(new MP3Plugin());

			// Keep last
			pluginList.add(new UADEPlugin());
		}
		return pluginList;				
	}
	
	
	public boolean loadInfo(FileSource fs) {
		return load(fs);
	}
	public abstract boolean load(FileSource fs);
	public abstract void unload();	
	public boolean canHandle(FileSource fs) { return false; }

	public boolean restart() {
		return false;
	}
	
	
	
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
	public void getDetailedInfo(Map<String, Object> details) {
	}
	
	public Map<String, Object> getDetailedInfo() {
		Map<String, Object> details = new HashMap<String, Object>();
		getDetailedInfo(details);
		return details;
	}
	
	public Object [] getDetailedArray() {
		Map<String, Object> info = getDetailedInfo();
		Object[] array = new Object [ info.size() * 2];//(String[]) info.toArray(new String[info.size()]);
		int i = 0;
		for(Entry<String, Object> e: info.entrySet()) {
			array[i++] = e.getKey();
			array[i++] = e.getValue();
		}
		return array;
	}

	public abstract String getStringInfo(int what);
	public abstract int getIntInfo( int what);
	
	public boolean isSilent() {
		return false;
	}

	public String getBaseName(String fname) {
		
		if(fname.startsWith("http:/")) {
			try {
				fname = URLDecoder.decode(fname, "UTF-8");
			} catch (UnsupportedEncodingException e) {
				throw new RuntimeException(e);
			}
		}
		
		
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
						Object val = entry.getValue();						
						if(val instanceof String) {
							try {
								int i = Integer.parseInt((String) val);
								val = Integer.valueOf(i);
							} catch (NumberFormatException e) {
							}
						}
						plugin.setOption(k.substring(dot+1), val);
					}
				}
			}
		}
		
	}
	
	public MediaPlayer getMediaPlayer() { return null; }

	public boolean canSeek() {
		return false;
	}

	public byte[] getMD5() {
		
		return md5;
	}

	public String getVersion() {
		return null;
	}

	public boolean delayedInfo() {
		return false;
	}

	public void close() {
	}

	public boolean isEndless() {
		return false;
	}
}
