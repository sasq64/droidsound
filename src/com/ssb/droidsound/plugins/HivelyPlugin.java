package com.ssb.droidsound.plugins;

import java.util.Map;

import com.ssb.droidsound.file.FileSource;

public class HivelyPlugin extends DroidSoundPlugin {

	static {
		System.loadLibrary("hively");
	}

	@Override
	public String getVersion() {
		return "HVL Replay v1.6";
	}
	
	private long songRef;
	@Override
	public boolean canHandle(FileSource fs) {
		return fs.getExt().equals("HVL") || fs.getExt().equals("AHX");
	}
	
	
	@Override
	public void getDetailedInfo(Map<String, Object> list) {
		
		list.put("plugin", "HIVELY");
		list.put("format", "Hively/AHX");
	}
	
	@Override
	public int getIntInfo(int what) {
		return 0;
	}

	@Override
	public int getSoundData(short[] dest, int size) {
		return N_getSoundData(songRef, dest, size);
	}

	@Override
	public String getStringInfo(int what) {
		return null;
	}

	@Override
	public boolean load(FileSource fs) {
		songRef = N_load(fs.getContents(), (int) fs.getLength());
		return songRef != 0;
	}

	@Override
	public void unload() {
		N_unload(songRef);
	}

	native public long N_load(byte [] module, int size);
	native public void N_unload(long song);
	native public int N_getSoundData(long song, short [] dest, int size);	
}
