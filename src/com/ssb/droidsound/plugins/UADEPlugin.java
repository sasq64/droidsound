package com.ssb.droidsound.plugins;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.net.URLDecoder;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import android.os.Environment;

import com.ssb.droidsound.file.FileSource;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.Unzipper;

public class UADEPlugin extends DroidSoundPlugin {
	private static final String TAG = UADEPlugin.class.getSimpleName();

	static {
		//System.loadLibrary("uade");
	}

	private static Set<String> extensions = new HashSet<String>();

	private static boolean inited;
	private static boolean libLoaded;

	private long currentSong = 0;

	private Unzipper unzipper;
	
	static String [] options = new String [] { "filter", "speedhack", "ntsc", "panning" };
	static int [] optvals = new int [] { OPT_FILTER, OPT_SPEED_HACK, OPT_NTSC, OPT_PANNING };

	
	
	public UADEPlugin() {
		extractFiles();
	}
	
	public static void extractFiles() {
		
		File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
		File eagleDir = new File(droidDir, "players");
		File confFile = new File(droidDir, "eagleplayer.conf");
		
		boolean extract = true;
		
		synchronized (extensions) {
					
			if(eagleDir.exists()) {
				
				if(confFile.exists()) {			
					extract = false;
				}			
			}
			
			if(extract) {				
				droidDir.mkdir();				
				Unzipper unzipper = Unzipper.getInstance();				
				unzipper.unzipAssetAsync(getContext(), "eagleplayers.zip", droidDir);

			}		

		}
		
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
				
				Log.d(TAG, "Added %d extensions to UADE", extensions.size());
				
			}
		}
	}
	
	@Override
	public boolean canHandle(FileSource fs) {

		init();
		
		String name = fs.getName();
		int x = name.lastIndexOf('.');
		
		if(x < 0) return false;
		String ext = name.substring(x+1).toUpperCase();
		if(!extensions.contains(ext)) {
			int slash = name.lastIndexOf('/');
			x = name.indexOf('.', slash+1);
			if(x < 0) return false;
			ext = name.substring(slash+1, x).toUpperCase();
			Log.d(TAG, "Checking prefix " + ext);
			return extensions.contains(ext);
		}
		return true;
		
	}

	
	@Override
	public String getBaseName(String name) {

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
	public int getIntInfo(int what) {
		if(currentSong == 0) {
			return -1;
		}
		return N_getIntInfo(currentSong, what);
	}

	@Override
	public int getSoundData(short [] dest, int size) {
		//Log.d(TAG, "getSoundData()");
		return N_getSoundData(currentSong, dest, size);
	}
	
	@Override
	public void getDetailedInfo(List<String> list) {

		if(currentSong == 0) {
			return;
		}
		list.add("Format");
		list.add("UADE: " + N_getStringInfo(currentSong, INFO_TYPE));
	}

	@Override
	public String getStringInfo(int what) {
		if(currentSong == 0) {
			return "";
		}
		return N_getStringInfo(currentSong, what);
	}


	private static String [] pref0 = new String [] { "MDAT", "TFX", "SNG", "RJP", "JPN", "DUM", "mdat", "tfx", "sng", "rjp", "jpn", "dum" };
	private static String [] pref1 = new String [] { "SMPL", "SAM", "INS", "SMP", "SMP", "INS", "smpl", "sam", "ins", "smp", "smp", "ins" };

	private static String getSecondaryFile(String name) {
				
		int dot = name.lastIndexOf('.');		
		int firstDot = name.indexOf('.');
		
		String ext = name.substring(dot+1);		
		String pref = name.substring(0, firstDot);

		for(int i=0; i<pref0.length; i++) {
			if(pref.equals(pref0[i])) {
				return pref1[i] + name.substring(firstDot); 
			} else
			if(ext.equals(pref0[i])) {
				return name.substring(0, dot+1) + pref1[i];
			}
		}
		
		return null;
	}
	
	@Override
	public boolean load(FileSource fs) {
		
		init();
		
		FileSource fs2 = null;
		
		String name2 = getSecondaryFile(fs.getName());
		if(name2 != null) {
			Log.d(TAG, "File '%s' needs '%s'", fs.getName(), name2);
			fs2 = fs.getRelative(name2);
			String path = fs2.getFile().getPath();
			Log.d(TAG, "Secondary file became '%s'", path);
		}
		
		currentSong = N_loadFile(fs.getFile().getPath());	
		fs.close();
		if(fs2 != null)
			fs2.close();
		return (currentSong != 0);
	}
	
	private void init() {
		if(!inited) {			
			//Context context = getContext();
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
	public boolean loadInfo(FileSource fs) {
		currentSong = 0;
		return true;
		//return load(file);
	}

	@Override
	public void unload() {
		if(currentSong == 0) {
			return;
		}
		N_unload(currentSong);
		currentSong = 0;
	}
	
	@Override
	public boolean setTune(int tune) {
		if(currentSong == 0) {
			return false;
		}
		return N_setTune(currentSong, tune);
	}
	
	@Override
	public boolean seekTo( int msec) {
		if(currentSong == 0) {
			return false;
		}
		return N_seekTo(currentSong, msec);
	}
	
	@Override
	public void exit() {
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
	public void setOption(String o, Object val) {
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
