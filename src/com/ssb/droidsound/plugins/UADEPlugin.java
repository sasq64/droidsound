package com.ssb.droidsound.plugins;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

import android.os.Environment;

import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.Unzipper;

public class UADEPlugin extends DroidSoundPlugin {
	private static final String TAG = UADEPlugin.class.getSimpleName();
	private static final Set<String> extensions = new HashSet<String>();

	private static boolean inited;
	private static boolean libLoaded;

	private long currentSong = 0;

	private Unzipper unzipper;

	public UADEPlugin() {
		synchronized (extensions) {
			File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
			File eagleDir = new File(droidDir, "players");
			File confFile = new File(droidDir, "eagleplayer.conf");

			if (! (eagleDir.exists() && confFile.exists())) {
				droidDir.mkdir();
				unzipper = Unzipper.getInstance();
				unzipper.unzipAssetAsync(getContext(), "eagleplayers.zip", droidDir);
			}
		}
	}

	private void indexExtensions() {
		if (unzipper != null) {
			while (!unzipper.checkJob("eagleplayers.zip")) {
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
			if (extensions.size() == 0) {
				extensions.add("CUST");
				extensions.add("CUS");
				extensions.add("CUSTOM");
				extensions.add("DM");
				extensions.add("TFX");
				File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
				File confFile = new File(droidDir, "eagleplayer.conf");

				BufferedReader reader;
				try {
					reader = new BufferedReader(new FileReader(confFile));
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
	public boolean canHandle(String name) {
		int x = name.lastIndexOf('.');

		if(x < 0) return false;
		String ext = name.substring(x+1).toUpperCase();
		if(!extensions.contains(ext)) {
			int slash = name.lastIndexOf('/');
			x = name.indexOf('.', slash+1);
			if(x < 0) return false;
			ext = name.substring(slash+1, x).toUpperCase();
			return extensions.contains(ext);
		}
		return true;

	}


	@Override
	public String getBaseName(String name) {
		name = name.substring(name.lastIndexOf('/')+1);

		int x = name.lastIndexOf('.');
		if (x >= 0) {
			String ext = name.substring(x+1).toUpperCase();
			if (! extensions.contains(ext)) {
				x = name.indexOf('.');
				ext = name.substring(0, x).toUpperCase();

				if (extensions.contains(ext)) {
					return name.substring(x+1);
				}
			}
			return name.substring(0, x);
		}
		return name;
	}

	@Override
	public int getIntInfo(int what) {
		if (currentSong == 0) {
			return -1;
		}
		return N_getIntInfo(currentSong, what);
	}

	@Override
	public int getSoundData(short [] dest, int size) {
		return N_getSoundData(currentSong, dest, size);
	}

	@Override
	public String[] getDetailedInfo() {
		if (currentSong == 0) {
			return null;
		}

		String [] details = new String [2];
		details[0] = "Format";
		details[1] = "UADE: " + N_getStringInfo(currentSong, INFO_TYPE);
		return details;
	}

	@Override
	public String getStringInfo(int what) {
		if(currentSong == 0) {
			return "";
		}
		return N_getStringInfo(currentSong, what);
	}

	@Override
	public boolean load(String name, byte[] module) {
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

			FileOutputStream fo = new FileOutputStream(file);
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
	public boolean load(File file) throws IOException {
		init();
		currentSong = N_loadFile(file.getPath());
		return (currentSong != 0);
	}

	private void init() {
		if(!inited) {
			File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");

			if(! libLoaded) {
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
	public boolean loadInfo(String name, byte[] module) {
		currentSong = 0;
		return true;
	}

	@Override
	public void unload() {
		if (currentSong == 0) {
			return;
		}
		N_unload(currentSong);
		currentSong = 0;
	}

	@Override
	public boolean setTune(int tune) {
		if (currentSong == 0) {
			return false;
		}
		return N_setTune(currentSong, tune);
	}

	@Override
	public boolean seekTo( int msec) {
		if (currentSong == 0) {
			return false;
		}
		return N_seekTo(currentSong, msec);
	}

	@Override
	public void exit() {
		if (inited) {
			N_exit();
		}
		inited = false;
	}

	@Override
	public void setOption(String o, Object val) {
		init();

		final int k;
		final int v;
		if (o.equals("filter")) {
			k = OPT_FILTER;
			v = (Boolean) val ? 1 : 0;
		} else if (o.equals("panning")) {
			k = OPT_PANNING;
			v = Integer.valueOf(((String) val).split(" ")[0]) / 25;
		} else if (o.equals("ntsc")) {
			k = OPT_NTSC;
			v = (Boolean) val ? 1 : 0;
		} else {
			throw new RuntimeException("Unknown option: " + o);
		}

		N_setOption(k, v);
	}

	@Override
	public String getVersion() {
		return "UADE - Unix Amiga Delitracker Emulator\nversion 2.13\nCopyright 2000-2006, Heikki Orsila";
	}

	native public void N_init(String baseDir);

	native public void N_exit();

	native public static void N_setOption(int what, int val);

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
