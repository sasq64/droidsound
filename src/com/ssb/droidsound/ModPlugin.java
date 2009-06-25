package com.ssb.droidsound;

import java.nio.ByteBuffer;

public class ModPlugin implements DroidSoundPlugin {
	
	static {
		System.loadLibrary("modplug");
	}

	ModPlugin() {
	}
	
	native public boolean canHandle(String name);
	native public boolean load(byte [] module, int size);
	native public void unload();
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native public int getSoundData(short [] dest, int size);	
	native public boolean seekTo(int seconds);
	native public boolean setSong(int song);
	native public String getStringInfo(int what);
	native public int getIntInfo(int what);
	native public int getSongLength();
}
