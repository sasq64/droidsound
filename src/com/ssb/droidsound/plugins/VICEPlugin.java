package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map.Entry;

import android.os.Environment;
import android.util.Log;

import com.ssb.droidsound.utils.Unzipper;

public class VICEPlugin extends DroidSoundPlugin {
	private static final String TAG = VICEPlugin.class.getSimpleName();

	private static boolean libraryLoaded = false;
	

	/**
	 * Load a song into memory.
	 * 
	 * @param name Name of file to load
	 * 
	 * @return an error string, or null if successful.
	 */
	native private static String N_loadFile(String name);
	
	/**
	 * Unload song from memory.
	 */
	native private static void N_unload();

	/** 
	 * Generates audio.
	 * Produces stereo, 44.1Khz, signed, native-encoding shorts.
	 * 
	 * @param dest the buffer to fill
	 */
	native private static int N_getSoundData(short[] dest, int size);
	
	/**
	 * Select a subsong.
	 */
	native private static boolean N_setTune(int tune);
	
	/**
	 * Set an option from the known #defines.
	 */
	native private static void N_setOption(int what, int val);
	
	/**
	 * Set the directory of VICE's basic, kernal and chargen files.
	 * 
	 * @param path Where kernal, basic and chargen can be found.
	 */
	native private static void N_setDataDir(String path);


	//private int currentTune;

	private HashMap<Integer, Integer> optMap = new HashMap<Integer, Integer>();

	private Unzipper unzipper = null;

	private static File dataDir;

	private static boolean isActive = false;

	private static boolean initialized = false;
	
	public VICEPlugin() {
		if (! initialized) {
			/* Store basic, kernal & chargen for C++ code to find. */
			dataDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
			if (!dataDir.exists()) {
				dataDir.mkdir();
			}
			
			File viceDir = new File(dataDir, "VICE");
			synchronized (lock) {					
				if(!viceDir.exists()) {
					unzipper = Unzipper.getInstance();
					unzipper.unzipAssetAsync(getContext(), "vice.zip", dataDir);
				}
			}
			initialized = true;
		}
	}

	@Override
	public void setOption(String opt, Object val) {
		final int k, v;
		if (opt.equals("active")) {
			isActive = (Boolean)val;
			Log.v(TAG, ">>>>>>>>>> VICEPLUGIN IS " + (isActive ? "ACTIVE" : "NOT ACTIVE"));
			return;
		} else if (opt.equals("filter")) {
			k = OPT_FILTER;
			v = (Boolean) val ? 1 : 0;
		} else if (opt.equals("ntsc")) {
			k = OPT_NTSC;
			v = (Integer) val;
		} else if (opt.equals("resampling")) {
			k = OPT_RESAMPLING;
			v = (Integer) val;
		} else {
			return;
		}
		
		if(!libraryLoaded) {
			optMap.put(k, v);
		} else {		
			N_setOption(k, v);
		}
	}
	
	@Override
	public void unload() {
		N_unload();
	}
	
	@Override
	public int getSoundData(short[] dest, int size) {
		return N_getSoundData(dest, size);
	}
	
	@Override
	public boolean seekTo(int seconds) {
		return false;
	}

	@Override
	public boolean setTune(int tune) {
		boolean ok = N_setTune(tune + 1);
		//if (ok) {
		//	currentTune = tune;
		//}
		return ok;
	}

	@Override
	public boolean load(String name, byte [] module, int size) {
		
		//currentTune = 0;
		
		if(!libraryLoaded) {
			System.loadLibrary("vice");
			
			if(unzipper != null) {
				while(!unzipper.checkJob("vice.zip")) {
					try {
						Thread.sleep(500);
					} catch (InterruptedException e) {
						e.printStackTrace();
						return false;
					}
				}
				unzipper = null;
			}
			
			N_setDataDir(new File(dataDir, "VICE").getAbsolutePath());
			
			for(Entry<Integer, Integer> e : optMap.entrySet()) {
				N_setOption(e.getKey(), e.getValue());
			}
			optMap.clear();						
			libraryLoaded = true;
		}

		final String error;
		try {
			File file = File.createTempFile("tmp-XXXXX", "sid");
			FileOutputStream fo = new FileOutputStream(file);
			fo.write(module);
			fo.close();
			error = N_loadFile(file.getAbsolutePath());
			file.delete();
		}
		catch (IOException ie) {
			throw new RuntimeException(ie);
		}
		
		if (error != null) {
			Log.i(TAG, "Native code error: " + error);
			return false;
		}

		return true; 
	}

	@Override
	public int getIntInfo(int what) {
		throw new RuntimeException();
	}

	@Override
	public String getStringInfo(int what) {
		throw new RuntimeException();
	}
	
	@Override
	public String getVersion() {
		return "VICE 2.2.10-r23402, reSID 1.0-pre1";
	}
}
