package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

import android.util.Log;


public class TFMXPlugin extends DroidSoundPlugin {
	private static final String TAG = TFMXPlugin.class.getSimpleName();
	static {
		System.loadLibrary("tfmx");
	}

	private byte[] songBuffer;
	private byte[] sampleBuffer;

	public TFMXPlugin() {
	}
	
	@Override
	public boolean canHandle(String name) {
		//int x = name.lastIndexOf('.');
		//if(x < 0) return false;
		//String ext = name.substring(x+1).toUpperCase();
		//return extensions.contains(ext);
		return name.toUpperCase().endsWith(".MDAT");
	}

	@Override
	public void unload(Object song) { N_unload((Long)song); }
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	@Override
	public int getSoundData(Object song, short [] dest, int size) { return N_getSoundData((Long)song, dest, size); }	
	@Override
	public boolean seekTo(Object song, int seconds) { return N_seekTo((Long)song, seconds); }
	@Override
	public boolean setTune(Object song, int tune) { return N_setTune((Long)song, tune); }
	@Override
	public String getStringInfo(Object song, int what) { return N_getStringInfo((Long)song, what); }
	@Override
	public int getIntInfo(Object song, int what) { return N_getIntInfo((Long)song, what); }

	native public boolean N_canHandle(String name);
	native public long N_load(byte [] module, byte [] samples);
	native public void N_unload(long song);
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native public int N_getSoundData(long song, short [] dest, int size);	
	native public boolean N_seekTo(long song, int seconds);
	native public boolean N_setTune(long song, int tune);
	native public String N_getStringInfo(long song, int what);
	native public int N_getIntInfo(long song, int what);

	public Object load(byte [] module, int size) {
		throw new RuntimeException("Cant load TFMX from memory");
	}
	
	public Object loadInfo(File mFile) throws IOException {
		return load(mFile);
	}
	
	public Object load(File mFile) throws IOException {
		
		String name = mFile.getPath();
		int ext = name.lastIndexOf('.');
		File sFile = new File(name.substring(0, ext) + ".smpl");
		
		int l = (int)mFile.length();
		songBuffer = new byte [l];
		FileInputStream fs = new FileInputStream(mFile);
		fs.read(songBuffer);
		fs.close();
		
		l = (int)sFile.length();
		sampleBuffer = new byte [l];
		fs = new FileInputStream(sFile);
		fs.read(sampleBuffer);
		fs.close();
		
		Log.v(TAG, String.format("HEADER %s", new String(songBuffer,0,8)));
		
		long rc = N_load(songBuffer, sampleBuffer);
		return rc != 0 ? rc : null; 
	}

	public Object loadInfo(InputStream is, int size) throws IOException {
		throw new RuntimeException("Cant load TFMX from stream");
	}
}
