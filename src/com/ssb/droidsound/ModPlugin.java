package com.ssb.droidsound;

import java.nio.ByteBuffer;

public class ModPlugin {

	static {
		System.loadLibrary("modplug");
	}

	ModPlugin() {
	}
	
	native boolean canHandle(String name);
	native boolean load(String name);
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native int getSoundData(byte [] dest, int size);	
	native boolean seekTo(float seconds);
	native String getSongName();
	native String getSongAuthor();
	native int getSongLength();

}
