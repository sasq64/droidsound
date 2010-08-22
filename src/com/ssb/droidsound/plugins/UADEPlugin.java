package com.ssb.droidsound.plugins;

import android.content.Context;

public class UADEPlugin extends DroidSoundPlugin {

	public UADEPlugin(Context ctx) {
		super(ctx);
	}

	@Override
	public int getIntInfo(Object song, int what) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int getSoundData(Object song, short[] dest, int size) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public String getStringInfo(Object song, int what) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object load(byte[] module, int size) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void unload(Object song) {
		// TODO Auto-generated method stub

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
