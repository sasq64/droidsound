package com.ssb.droidsound.plugins;

import android.util.Log;

public class SC68Plugin extends DroidSoundPlugin {
	private static final String TAG = SC68Plugin.class.getSimpleName();
	static {
		System.loadLibrary("sc68");
	}
	private long currentSong;
	@Override
	public boolean canHandle(String name) {
		String ext = name.substring(name.indexOf('.')+1).toLowerCase();
		return(ext.equals("sndh") || ext.equals("sc68"));
	}
	
	@Override
	public void unload() {
		N_unload(currentSong);		
	}

	@Override
	public boolean load(String name, byte[] module, int size) {
		Log.v(TAG, String.format("Trying to load '%s'", name));
		currentSong = N_load(module, size);
		Log.v(TAG, String.format("Trying to load '%s' -> %d", name, currentSong));
		return (currentSong != 0); 	}

	@Override
	public int getSoundData(short[] dest, int size) {
		return N_getSoundData(currentSong, dest, size);
	}

	@Override
	public String getStringInfo(int what) {
		return N_getStringInfo(currentSong, what);
	}

	@Override
	public int getIntInfo(int what) {
		return N_getIntInfo(currentSong, what);
	}
	
	@Override
	public boolean setTune(int tune) {
		
		Log.v(TAG, String.format("Set tune %d", tune));
		
		return N_setTune(currentSong, tune);
	}

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
