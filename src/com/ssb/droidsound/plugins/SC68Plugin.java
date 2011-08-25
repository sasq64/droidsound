package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.UnsupportedEncodingException;

import android.os.Environment;
import com.ssb.droidsound.utils.Log;

import com.ssb.droidsound.utils.Unzipper;

public final class SC68Plugin extends DroidSoundPlugin {
	private static final String TAG = SC68Plugin.class.getSimpleName();
	static {
		System.loadLibrary("sc68");
	}
	private long currentSong;
	private static final Object lock = new Object();
	private static boolean inited = false;

    private long pluginRef;

	private String title = null;
	private String composer = null;
	private String year = null;
	private String type = null;
	private Unzipper unzipper = null;

	public SC68Plugin() {

		File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
        File sc68Dir = new File(droidDir, "sc68data");
		synchronized (lock) {					
			if(!sc68Dir.exists()) {
				droidDir.mkdir();
				unzipper = Unzipper.getInstance();
				unzipper.unzipAssetAsync(getContext(), "sc68data.zip", droidDir);
			}
			if(!inited) {
				N_setDataDir(sc68Dir.getPath());
				inited = true;
			}
		}
	}
	
	@Override
	public boolean canHandle(String name) {
		String ext = name.substring(name.indexOf('.')+1).toLowerCase();
		return("sndh".equals(ext) || "sc68".equals(ext) || "snd".equals(ext));
	}
	
	@Override
	public void unload() {
		Log.d(TAG, "Unloading");
		if(currentSong != 0){
			N_unload(currentSong);	
		}
	}

	@Override
	public boolean load(String name, byte[] module, int size) {
		
		
		if(unzipper != null) {
			while(!unzipper.checkJob("sc68data.zip")) {
				try {
					Thread.sleep(500);
				} catch (InterruptedException e) {
					e.printStackTrace();
					return false;
				}
			}
			unzipper = null;
		}
		
		Log.d(TAG, "Trying to load '%s'", name);
		currentSong = N_load(module, size);
		Log.d(TAG, "Trying to load '%s' -> %d", name, currentSong);
		return (currentSong != 0);
	}
	
	private static byte[] targetBuffer;
	
	
	private static String fromData(byte [] data, int start, int len) throws UnsupportedEncodingException {
		int i = start;
		for(; i<start+len; i++) {
			if(data[i] == 0) {
				i++;
				break;
			}
		}
		return new String(data, start, i-start, "ISO-8859-1").trim();
	}
	
	private static final String [] hws = { "?", "YM", "STE", "YM+STE", "Amiga", "Amiga+YM", "Amiga+STE", "Amiga++" }; 
	
	@Override
	public String[] getDetailedInfo() {

        String replay = getStringInfo(52);
		String hwname = getStringInfo(51);
		int hwbits = getIntInfo(50);
		if(replay == null) replay = "?";
		if(hwname == null) hwname = "?";

        String[] info = new String[4];
        info[0] = "Format";
		info[1] = String.format("SC68: %s", replay);
		info[2] = "Hardware";
		info[3] = String.format("%s (%s)", hwname, hws[hwbits]);
		return info;
	}

	/*
	 * Loads the generic info from the track such as:
	 * year, date, composer, filetype, title, etc.
	 */
	@Override
	public boolean loadInfo(String name, byte[] module, int size) {

		currentSong = 0;
		title = null;
		composer = null;
		year = null;
		type = null;

		byte[] data = module;
		String head = new String(module, 0, 4);
		if("ICE!".equals(head)) {
			
			Log.d(TAG, "Unicing");
			
			if(targetBuffer == null) {
                //targetBuffer = new byte[1024*1024]; Simplified using a shift
				targetBuffer = new byte [(1024 << 10)];
			}
			int rc = N_unice(module, targetBuffer);
			if(rc < 0){
				return false;
			}
			size = rc;
			data = targetBuffer;
		}
		
		String header = new String(data, 12, 4);
		String header2 = new String(data, 0, 16);
		if("SNDH".equals(header)) {
			Log.d(TAG, "Found SNDH");
			type = "SNDH";
			int offset = 16;
			boolean done = false;
			
			while(offset < 1024) {
				String tag = new String(data, offset, 4);
				//Log.d(TAG, "TAG: %s", tag);
				try {
					if("TITL".equals(tag)) {
						title = fromData(data, offset+4, 64);
						Log.d(TAG, "TITLE: %s", title);
						offset += (4+title.length());
					} else if("COMM".equals(tag)) {
						composer = fromData(data, offset+4, 64);
						offset += (4+composer.length());
					} else if("YEAR".equals(tag)) {
						year = fromData(data, offset+4, 32);
						offset += (4+year.length());
					} else if("HDNS".equals(tag)) {
						Log.d(TAG, "END");
						break;
					} else {
						while(data[offset] != 0) offset++;
					}
				} catch (UnsupportedEncodingException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				while(data[offset] == 0) offset++;
			}			
			
			return true;
		} else if("SC68 Music-file ".equals(header2)) {
            type = "SC68";
            int offset = 56;
            while(offset < 1024) {
				String tag = new String(data, offset, 4);
				int tsize = data[offset+4] | (data[offset+5]<<8) | (data[offset+6]<<16) | (data[offset+7]<<24);
				offset += 8;
				Log.d(TAG, "TAG: %s, size %d", tag, tsize);
				if(tsize < 0 || tsize > size) {
					break;
				}
				try {
					if("SCMN".equals(tag)) {
						title = fromData(data, offset, tsize);
						Log.d(TAG, "TITLE: %s", title);
					} else if("SCFN".equals(tag)) {
						if(title != null) {
							title = fromData(data, offset, tsize);
							Log.d(TAG, "TITLE: %s", title);
						}
					} else if("SCAN".equals(tag)) {
						composer = fromData(data, offset, tsize);
					} else if("SC68".equals(tag)) {
						tsize = 0;
					} else if("SCEF".equals(tag) || "SCDA".equals(tag)) {
						Log.d(TAG, "END");
						break;
					} else {			
					}
				} catch (UnsupportedEncodingException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				offset += tsize;
			}			
			
			return true;
			
			
		}

		return false;
	}
	

	@Override
	public int getSoundData(short[] dest, int size) {
		return N_getSoundData(currentSong, dest, size);
	}

	@Override
	public String getStringInfo(int what) {
		if(currentSong == 0) {
			switch(what) {
			case INFO_TITLE:
				return title;
			case INFO_AUTHOR:
				return composer;
			case INFO_COPYRIGHT:
				return year;
			case INFO_TYPE:
				return type;
			}			
			return null;
		}
		return N_getStringInfo(currentSong, what);
	}

	@Override
	public int getIntInfo(int what) {
		if(currentSong == 0) {
			return -1;
		}
		
		int rc = N_getIntInfo(currentSong, what);
		if(what == INFO_LENGTH && rc == 0){
			rc = -1;
		}
		return rc;
	}
	
	@Override
	public boolean setTune(int tune) {
		
		Log.d(TAG, "Set tune %d", tune);
		
		return N_setTune(currentSong, tune);
	}
	
	@Override
	public boolean seekTo(int msec) {
		return N_seekTo(currentSong, msec);
	}
	
	@Override
	public String getVersion() {
		return "Version 3.0.0 \nCopyright (C) 2010 Benjamin Gerard";
	}

	public native long N_load(byte [] module, int size);
	public native long N_loadInfo(byte [] module, int size);
	public native void N_unload(long song);
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	public native int N_getSoundData(long song, short [] dest, int size);	
	public native boolean N_seekTo(long song, int seconds);
	public native boolean N_setTune(long song, int tune);
	public native String N_getStringInfo(long song, int what);
	public native int N_getIntInfo(long song, int what);
	
	public native void N_setDataDir(String dataDir);
	public native int N_unice(byte [] data, byte... target);
}
