package com.ssb.droidsound.plugins;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.net.URLDecoder;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import android.content.Context;
import android.content.SharedPreferences;
import android.media.MediaPlayer;

import com.ssb.droidsound.utils.Log;

public abstract class DroidSoundPlugin {
	private static final String TAG = DroidSoundPlugin.class.getSimpleName();
	
	public static final int INFO_TITLE = 0;
	public static final int INFO_AUTHOR = 1;
	public static final int INFO_LENGTH = 2;
	public static final int INFO_TYPE = 3;
	public static final int INFO_COPYRIGHT = 4;
	public static final int INFO_GAME = 5;
	public static final int INFO_SUBTUNE_COUNT = 6;
	public static final int INFO_STARTTUNE = 7;
	public static final int INFO_SUBTUNE_TITLE = 8;
	public static final int INFO_SUBTUNE_AUTHOR = 9;
	public static final int INFO_SUBTUNE_NO = 10;
	
	//public static final int SIZEOF_INFO = 11;

	public static final int INFO_DETAILS_CHANGED = 15;
	
	
	public static final int OPT_FILTER = 1;
	public static final int OPT_RESAMPLING = 2;
	public static final int OPT_NTSC = 3;
	public static final int OPT_SPEED_HACK = 4;
	public static final int OPT_PANNING = 5;
	public static final int OPT_FILTER_BIAS = 6;
	public static final int OPT_SID_MODEL = 7;

	
	
	private static Context context;
	
	static Object lock = new Object();
	
	public static void setContext(Context ctx) {
		context = ctx;
	}
	
	public static Context getContext() { return context; }

	private byte[] md5;

	private int streamSize;

	
	
	// Called when player thread exits due to inactivty
	public void exit() {		
	};

	
	public static List<DroidSoundPlugin> createPluginList() {
		
		List<DroidSoundPlugin> pluginList;
		synchronized (lock) {				
			pluginList = new ArrayList<DroidSoundPlugin>();
			//pluginList.add(new VICEPlugin());
			//pluginList.add(new SidplayPlugin());
			pluginList.add(new SidPlugin());
			pluginList.add(new ModPlugin());
			pluginList.add(new GMEPlugin());
			pluginList.add(new HivelyPlugin());
			pluginList.add(new SC68Plugin());
			pluginList.add(new MP3Plugin());

			// Keep last
			pluginList.add(new UADEPlugin());
		}
		return pluginList;				
	}
	
	

	public boolean loadInfo(String name, byte [] module, int size) {
		return load(name, module, size);
	}
	
	public boolean loadStream(String songName) throws IOException {
		
		try {
			URL url = new URL(songName);
	
			Log.d(TAG, "Opening URL " + songName);
	
			URLConnection conn = url.openConnection();
			if(!(conn instanceof HttpURLConnection))
				throw new IOException("Not a HTTP connection");
	
			HttpURLConnection httpConn = (HttpURLConnection) conn;
			httpConn.setAllowUserInteraction(false);
			httpConn.setInstanceFollowRedirects(true);
			httpConn.setRequestMethod("GET");
	
			Log.d(TAG, "Connecting");
	
			httpConn.connect();
	
			int response = httpConn.getResponseCode();
			if(response == HttpURLConnection.HTTP_OK) {
				int size;
				byte[] buffer = new byte[16384];
				Log.d(TAG, "HTTP connected");
				InputStream in = httpConn.getInputStream();
	
				// URLUtil.guessFileName(songName, );
	
				int dot = songName.lastIndexOf('.');
				String ext = DroidSoundPlugin.getExt(songName);
				File f = File.createTempFile("music", ext);
				FileOutputStream fos = new FileOutputStream(f);
				BufferedOutputStream bos = new BufferedOutputStream(fos, buffer.length);
				while((size = in.read(buffer)) != -1) {
					bos.write(buffer, 0, size);
				}
				bos.flush();
				bos.close();
	
				streamSize = (int) f.length();
	
				Log.d(TAG, "Bytes written: " + streamSize);
	
				byte [] songBuffer = new byte[(int) streamSize];
				FileInputStream fs = new FileInputStream(f);
				fs.read(songBuffer);
				fs.close();
				// f.delete();
				
				//songName = new File(songName).getName();
				
				//boolean rc = load(songName, songBuffer, streamSize);
				boolean rc = load(f);
				f.delete();
				return rc;
			}
			
		} catch (MalformedURLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
	
	public int getStreamSize() { return streamSize; }
	
	public boolean load(String name, InputStream is, int size) throws IOException {
		Log.d(TAG, "PLUGIN LOAD STREAM");
		boolean rc = false;
		try {
			byte [] songBuffer = new byte [size];
			is.read(songBuffer);			
			calcMD5(songBuffer);
			
			rc = load(name, songBuffer, songBuffer.length);
		} catch (OutOfMemoryError e) {
			e.printStackTrace();
		}
		return rc;
	}
	
	public void calcMD5(byte[] songBuffer, int size) {
		
		MessageDigest md = null;
		Log.d(TAG, "MD5 CALCING TIME");
		try {
			md = MessageDigest.getInstance("MD5");
		} catch (NoSuchAlgorithmException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return;
		}		
		
		md.update(songBuffer, 0, size);
		md5 = md.digest();
	}
	public void calcMD5(byte[] songBuffer) {
		calcMD5(songBuffer, songBuffer.length);
	}

	public boolean loadInfo(String name, InputStream is, int size) throws IOException {
		boolean rc = false;
		try {
			byte [] songBuffer = new byte [size];
			is.read(songBuffer);
			rc = loadInfo(name, songBuffer, songBuffer.length);
		} catch (OutOfMemoryError e) {
			e.printStackTrace();
		}
		return rc;
	}
	
	public boolean load(File file) throws IOException {
		Log.d(TAG, "PLUGIN LOAD FILE");
		int l = (int)file.length();
		byte [] songBuffer = null;
		try {
			songBuffer = new byte [l];			
		} catch (OutOfMemoryError e) {
			e.printStackTrace();
		}		
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		calcMD5(songBuffer);
		return load(file.getName(), songBuffer, songBuffer.length);
	}

	public boolean loadInfo(File file) throws IOException {
		int l = (int)file.length();
		byte [] songBuffer = null;
		try {
			songBuffer = new byte [l];
		} catch (OutOfMemoryError e) {
			e.printStackTrace();
		}
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		return loadInfo(file.getName(), songBuffer, songBuffer.length);
	}

	public abstract void unload();
	
	
	public static String getExt(String name) {
		String ext = "";
		int dot = name.lastIndexOf('.');
		if(dot > 0) {
			ext = name.substring(dot);
			Log.d(TAG, "EXT: " + ext);
			char c = 'X';
			int e = 0;
			while(e < ext.length() && Character.isLetterOrDigit(c)) {
				e++;
				if(e == ext.length())
						break;
				c = ext.charAt(e);
			}
			ext = ext.substring(0,e);
			Log.d(TAG, "EXT NOW: " + ext);
		}
		return ext;
	}
	
	
	public boolean canHandle(String name) { 
		return canHandleExt(getExt(name));
	}
	
	public boolean canHandleExt(String ext) { return false; }
	
	
	public abstract boolean load(String name, byte [] module, int size);

	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	public abstract int getSoundData(short [] dest, int size);	

	public boolean seekTo(int msec) {
		return false;
	}

	public boolean setTune(int tune) {
		return false;
	}

	// Should return information in string pairs, as TITLE0, TEXT0, TITLE1, TEXT1 etc
	// Some titles are predfined and excpect certain data
	// Unknown titles are presented as-is in detailed song info
	// Known TITLES:
	// "Instruments" - Instrument names, one instrument per line
	// "Info" - STIL info for C64, otherwise presented normally
	// "Channels" - Number of channels
	// "Copyright" - Same as INFO_COPYRIGHT
	// "Game" - Same as INFO_GAME
	public String [] getDetailedInfo() {
		return null;
	}
	
	public abstract String getStringInfo(int what);
	public abstract int getIntInfo( int what);
	
	public boolean isSilent() {
		return false;
	}

	public String getBaseName(String fname) {
		
		if(fname.startsWith("http:/")) {
			fname = URLDecoder.decode(fname);
		}
		
		
		int slash = fname.lastIndexOf('/');
		if(slash >= 0) {
			fname = fname.substring(slash+1);
		}
		int dot = fname.lastIndexOf('.');
		if(dot > 0) {
			fname = fname.substring(0, dot);
		}
		return fname;
	}

	//public String[] getOptions() {
	//	return null;
	//}

	public void setOption(String string, Object val) {
	}
	
	

	public static void setOptions(SharedPreferences prefs) {
		List<DroidSoundPlugin> list = DroidSoundPlugin.createPluginList(); 
		Map<String, ?> prefsMap = prefs.getAll();
		
		for(DroidSoundPlugin plugin : list) {

			String plname = plugin.getClass().getSimpleName();

			for(Entry<String, ?> entry  : prefsMap.entrySet()) {
				String k = entry.getKey();
				int dot = k.indexOf('.');
				if(dot >= 0) {
					if(k.substring(0, dot).equals(plname)) {						
						Object val = entry.getValue();						
						if(val instanceof String) {
							try {
								int i = Integer.parseInt((String) val);
								val = new Integer(i);
							} catch (NumberFormatException e) {
							}
						}
						plugin.setOption(k.substring(dot+1), val);
					}
				}
			}
		}
		
	}
	
	static String [] pref0 = new String [] { "MDAT", "TFX", "SNG", "RJP", "JPN", "DUM" };
	static String [] pref1 = new String [] { "SMPL", "SAM", "INS", "SMP", "SMP", "INS" };

	public static String getSecondaryFile(String path) {
				
		int dot = path.lastIndexOf('.');
		int slash = path.lastIndexOf('/');
		
		if(dot <= slash) {
			return null;
		}

		int firstDot = path.indexOf('.', slash+1);				
		String ext = path.substring(dot+1).toUpperCase();		
		String pref = path.substring(slash+1, firstDot).toUpperCase();

		for(int i=0; i<pref0.length; i++) {
			if(pref.equals(pref0[i])) {
				return path.substring(0, slash+1) + pref1[i] + path.substring(firstDot); 
			} else
			if(ext.equals(pref0[i])) {
				return path.substring(0, dot+1) + pref1[i];
			}
		}
		
		return null;
	}
	
	public MediaPlayer getMediaPlayer() { return null; }

	public boolean canSeek() {
		return false;
	}

	public byte[] getMD5() {
		
		return md5;
	}

	public String getVersion() {
		return "Unknown";
	}

	public boolean delayedInfo() {
		return false;
	}

	public void close() {
	}
}
