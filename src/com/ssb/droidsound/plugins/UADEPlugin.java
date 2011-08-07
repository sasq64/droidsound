package com.ssb.droidsound.plugins;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.net.URLDecoder;
import java.util.Collection;
import java.util.HashSet;
//import java.util.Set; not used yet.

import android.content.Context;
import android.os.Environment;
import com.ssb.droidsound.utils.Log;

import com.ssb.droidsound.utils.Unzipper;

public final class UADEPlugin extends DroidSoundPlugin {
	private static final String TAG = UADEPlugin.class.getSimpleName();

	static {
		//System.loadLibrary("uade");
    }

    //private static Set<String> extensions = new HashSet();  below is weakened type of this
	private static final Collection<String> extensions = new HashSet<String>();

	private static boolean inited;
	private static boolean libLoaded;

	private long currentSong = 0;

	private Unzipper unzipper;

	private static final String [] options = { "filter", "speedhack", "ntsc", "panning" };
	private static final int [] optvals = { OPT_FILTER, OPT_SPEED_HACK, OPT_NTSC, OPT_PANNING };



	public UADEPlugin() {

		//Context ctx = getContext();

		File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
		//File filesDir = ctx.getFilesDir();
		File eagleDir = new File(droidDir, "players");

		File confFile = new File(droidDir, "eagleplayer.conf");

        synchronized (extensions) {

            boolean extract = true;
            if(eagleDir.exists()) {

				if(confFile.exists()) {
					extract = false;
				}
			}

			if(extract) {
				droidDir.mkdir();
				unzipper = Unzipper.getInstance();
				unzipper.unzipAssetAsync(getContext(), "eagleplayers.zip", droidDir);

			}

		}
		//for(String s : ex) {
		//	extensions.add(s);
		//}
	}

	private void indexExtensions() {
		if(unzipper != null) {
			while(!unzipper.checkJob("eagleplayers.zip")) {
				try {
					Thread.sleep(500);
				} catch (InterruptedException e) {
					e.printStackTrace();
					return;
				}
			}
			unzipper = null;
		}
		synchronized (extensions) {
			if(extensions.size() == 0) {
				extensions.add("CUST");
				extensions.add("CUS");
				extensions.add("CUSTOM");
				extensions.add("DM");
				extensions.add("TFX");
				File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
				File confFile = new File(droidDir, "eagleplayer.conf");

                try {
                    BufferedReader reader = new BufferedReader(new FileReader(confFile));
                    String line = reader.readLine();
					while(line != null) {
						int x = line.indexOf("prefixes=");
						if(x >= 0) {
							String[] exts = line.substring(x+9).split(",");
							for(String ex : exts) {
								int sp = ex.indexOf('\t');
								if(sp >= 0) {
									ex = ex.substring(0, sp);
								}
								//Log.d(TAG, "Ext " + ex);
								extensions.add(ex.toUpperCase());
							}
						}
						line = reader.readLine();
					}
					reader.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}

	@Override
	public final boolean canHandle(String name) {

		int x = name.lastIndexOf('.');
		if(x < 0) {
			return false;
		}
		String ext = name.substring(x+1).toUpperCase();
		if(!extensions.contains(ext)) {
			int slash = name.lastIndexOf('/');
			x = name.indexOf('.', slash+1);
			if(x < 0) {
				return false;
			}
			ext = name.substring(slash+1, x).toUpperCase();
			Log.d(TAG, "Checking prefix " + ext);
			return extensions.contains(ext);
		}
		return true;
	}


	@Override
	public final String getBaseName(String name) {

		if(name.startsWith("http:/")) {
			name = URLDecoder.decode(name);
		}
		name = name.substring(name.lastIndexOf('/')+1);

		int x = name.lastIndexOf('.');
		if(x >= 0) {
			String ext = name.substring(x+1).toUpperCase();
			if(!extensions.contains(ext)) {
				x = name.indexOf('.');
				ext = name.substring(0, x).toUpperCase();

				if(extensions.contains(ext)) {
					return name.substring(x+1);
				}
			}
			return name.substring(0, x);
		}
		return name;
	}
	@Override
	public final int getIntInfo(int what) {
		if(currentSong == 0) {
			return -1;
		}
		return N_getIntInfo(currentSong, what);
	}

	@Override
	public final int getSoundData(short [] dest, int size) {
		//Log.d(TAG, "getSoundData()");
		return N_getSoundData(currentSong, dest, size);
	}
	@Override
	public final String[] getDetailedInfo() {

		if(currentSong == 0) {
			return null;
		}

		String [] details = new String [2];
		details[0] = "Format";
		details[1] = "UADE: " + N_getStringInfo(currentSong, INFO_TYPE);
		return details;
	}

	@Override
	public final String getStringInfo(int what) {
		if(currentSong == 0) {
			return "";
		}
		return N_getStringInfo(currentSong, what);
	}

	@Override
	public final boolean load(String name, byte[] module, int size) {
		try {
			File file;
			int dot = name.indexOf('.');
			int lastDot = name.lastIndexOf('.');
			if(dot == -1) {
				file = File.createTempFile(name, "");
			}
			else {
				file = File.createTempFile(name.substring(0,dot+1), name.substring(lastDot));
			}
			//FileOutputStream fo = new FileOutputStream(file); //Here in case the Buffered I/O causes problems.
			BufferedOutputStream fo = new BufferedOutputStream(new FileOutputStream(file));
			fo.write(module);
			fo.close();
			boolean rc = load(file);
			file.delete();
			return rc;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}

	@Override
	public final boolean load(File file) {

		init();

		currentSong = N_loadFile(file.getPath());
		return (currentSong != 0);
	}

	private void init() {
		if(!inited) {
			Context context = getContext();
			File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");

			if(!libLoaded) {
				Log.d(TAG, "Loading library");
				System.loadLibrary("uade");
				libLoaded = true;
			}
			indexExtensions();
			N_init(droidDir.getPath());
			try {
				Thread.sleep(800);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			inited = true;
		}
	}

	@Override
	public final boolean loadInfo(File file) {
		currentSong = 0;
		return true;
		//return load(file);
	}

	@Override
	public final boolean loadInfo(String name, InputStream is, int size) {
		currentSong = 0;
		return true;
	}

	@Override
	public final boolean loadInfo(String name, byte[] module, int size) {
		currentSong = 0;
		return true;
	}

	@Override
	public final void unload() {
		if(currentSong == 0) {
			return;
		}
		N_unload(currentSong);
		currentSong = 0;
	}

	@Override
	public final boolean setTune(int tune) {
		/*if(currentSong == 0) {
			return false;
		}
		return N_setTune(currentSong, tune);*/

        return currentSong != 0 && N_setTune(currentSong, tune);
    }

	@Override
	public final boolean seekTo( int msec) {
		/*if(currentSong == 0) {
			return false;
		}*/

        return currentSong != 0 && N_seekTo(currentSong, msec);
    }

	@Override
	public final void exit() {
		if(inited) {
			N_exit();
		}
		inited = false;
	}
/*
	public static void setFilter(boolean on) {
		Log.d(TAG, "Setting filter to " + (on ? "ON" : "OFF"));
		N_setOption(OPT_FILTER, on ? 1 : 0);
	}

	public static void setSpeedHack(boolean on) {
		Log.d(TAG, "Setting speed hack to " + (on ? "ON" : "OFF"));
		N_setOption(OPT_SPEED_HACK, on ? 1 : 0);
	}
	public static void setNtsc(boolean on) {
	Log.d(TAG, "Setting ntsc to " + (on ? "ON" : "OFF"));
		N_setOption(OPT_NTSC, on ? 1 : 0);
	}
*/
	@Override
	public final void setOption(String o, Object val) {
		Log.d(TAG, "UADE opt %s argtype %s", o, val.getClass().getSimpleName());
		int v  = -1;
		if(val instanceof Boolean) {
			v = (Boolean)val ? 1 : 0;
		} else
		if(val instanceof Integer) {
			v = (Integer)val;
		}

		for(int i=0; i<options.length; i++) {
			if(options[i].equals(o)) {
				init();
				N_setOption(optvals[i], v);
				break;
			}
		}
	}

	@Override
	public final String getVersion() {
		return "UADE - Unix Amiga Delitracker Emulator\nversion 2.13\nCopyright 2000-2006, Heikki Orsila";
	}
	public final native void N_init(String baseDir);
	public final native void N_exit();
	public static native void N_setOption(int what, int val);
	public final native boolean N_canHandle(String name);
	public final native long N_load(byte [] module, int size);
	public final native long N_loadFile(String name);
	public final native void N_unload(long song);

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	public final native int N_getSoundData(long song, short [] dest, int size);
	public final native boolean N_seekTo(long song, int seconds);
	public final native boolean N_setTune(long song, int tune);
	public final native String N_getStringInfo(long song, int what);
	public final native int N_getIntInfo(long song, int what);


}
