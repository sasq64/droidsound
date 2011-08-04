package com.ssb.droidsound.plugins;

import java.util.HashMap;
import java.util.Map;

public class SidplayPlugin extends DroidSoundPlugin {
	private static final String TAG = SidplayPlugin.class.getSimpleName();


	private static boolean libraryLoaded = false;
    //private HashMap<Integer,Integer> optMap = new Hashmap(); reduced type version below.
	private final Map<Integer,Integer> optMap = new HashMap<Integer, Integer>();


	private long currentSong = 0;

	public static class Option {
		String name;
		String description;
		Object defaultValue;
	}


	private static final String [] options = { "filter", "ntsc", "panning" };
	private static final int [] optvals = { OPT_FILTER, OPT_NTSC, OPT_PANNING };

	@Override
	public void setOption(String opt, Object val) {
		int v  = -1;
		if(val instanceof Boolean) {
			v = (Boolean)val ? 1 : 0;
		} else
		if(val instanceof Integer) {
			v = (Integer)val;
		}

		for(int i=0; i<options.length; i++) {
			if(options[i].equals(opt)) {
				if(!libraryLoaded) {
					optMap.put(optvals[i], v);
				} else {
					N_setOption(optvals[i], v);
				}
				break;
			}
		}
	}

	@Override
	public void unload() {
		if(currentSong <= 0) {
			return;
		}
		N_unload(currentSong);
		currentSong = 0;
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
	public int getIntInfo(int what) {
		return -1;
	}

	public final native long N_load(byte [] module, int size);
	public final native void N_unload(long song);

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	public final native int N_getSoundData(long song, short [] dest, int size);
	public final native boolean N_seekTo(long song, int seconds);
	public final native boolean N_setTune(long song, int tune);
	public final native String N_getStringInfo(long song, int what);
	public final native int N_getIntInfo(long song, int what);

	public static native void N_setOption(int what, int val);

	@Override
	public boolean load(String name, byte [] module, int size) {

		if(!libraryLoaded) {
			System.loadLibrary("sidplay2");
			for(Map.Entry<Integer, Integer> e : optMap.entrySet()) {
				N_setOption(e.getKey(), e.getValue());
			}
			optMap.clear();
			libraryLoaded = true;
		}
		currentSong = N_load(module, size);

		/*if(currentSong == 0) {
			return false;
		}*/
        return currentSong != 0;//Simplified above code

    }

	@Override
	public String getStringInfo(int what) {
		return null;
	}

	@Override
	public boolean isSilent() {

		return (N_getIntInfo(currentSong, 100) != 0);
	}

	@Override
	public String getVersion() {
		return "libsidplay 2.1.1+20060528.ccr";
	}

}
