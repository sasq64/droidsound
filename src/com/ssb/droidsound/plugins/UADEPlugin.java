package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Enumeration;
import java.util.HashSet;
import java.util.Set;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import android.content.Context;
import android.util.Log;

public class UADEPlugin extends DroidSoundPlugin {
	private static final String TAG = UADEPlugin.class.getSimpleName();

	static {
		System.loadLibrary("uade");
	}

	private Set<String> extensions;

	private boolean inited;
	
	static String [] ex = { "FC", "MDAT", "ML", "CUST", "CUS", "RK", "MC", "DW", "MA", "FRED", "BD", "SNG", "RH", "JAM", "DM", "DM2" };   

	public UADEPlugin(Context ctx) {
		super(ctx);
		extensions = new HashSet<String>();
		for(String s : ex) {			
			extensions.add(s);
		}
	}
	
	@Override
	public boolean canHandle(String name) {
		/*
		File f = new File(name);
		
		String n = f.getName().toUpperCase();
		Log.v(TAG, "CAN HANDLE : " + n);
		
		if(n.startsWith("MDAT.")) {
			return true;
		} */
		
		int x = name.lastIndexOf('.');
		if(x < 0) return false;
		String ext = name.substring(x+1).toUpperCase();
		return extensions.contains(ext);
	}

	@Override
	public int getIntInfo(Object song, int what) {
		if(song instanceof String) {
			return -1;
		}
		return N_getIntInfo((Long)song, what);
	}

	@Override
	public int getSoundData(Object song, short [] dest, int size) {
		//Log.v(TAG, "getSoundData()");
		return N_getSoundData((Long)song, dest, size);
	}	

	@Override
	public String getStringInfo(Object song, int what) {
		if(song instanceof String) {
			return "";
		}
		return N_getStringInfo((Long)song, what);
	}

	@Override
	public Object load(byte[] module, int size) {
		
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object load(File file) throws IOException {
		
		Context context = getContext();
		
		File filesDir = context.getFilesDir();
		File eagleDir = new File(filesDir, "players");
		
		boolean extract = true;
		
		if(eagleDir.exists()) {
			
			if(new File(filesDir, "eagleplayer.conf").exists()) {			
				extract = false;
			}			
		}
		
		if(extract) {

			File tempFile = new File(filesDir, "ep.zip");
			
			FileOutputStream os = new FileOutputStream(tempFile);
			
			InputStream is = context.getAssets().open("eagleplayers.zip");
			
			byte [] buffer = new byte [128*1024];
			while(true) {
				int rc = is.read(buffer);
				if(rc <= 0) {
					break;
				}
				os.write(buffer, 0, rc);
			}
			is.close();
			os.close();
			
			ZipFile zf = new ZipFile(tempFile);
			Enumeration<? extends ZipEntry> entries = zf.entries();
			while(entries.hasMoreElements()) {
				ZipEntry entry = entries.nextElement();
				is = zf.getInputStream(entry);
				String name = entry.getName();	
				File efile = new File(filesDir, name);
				
				Log.v(TAG, String.format("Extracting %s / %s", name, efile.getPath()));
				
				if(name.endsWith("/")) {
					continue;
				}
				
				efile.getParentFile().mkdirs();
				
				os = new FileOutputStream(efile);

				while(true) {
					int rc = is.read(buffer);
					if(rc <= 0) {
						break;
					}
					os.write(buffer, 0, rc);
				}
				is.close();
				os.close();
			}
			
			tempFile.delete();
			
		}

		if(!inited) {
			N_init(filesDir.getPath());
			/*try {
				Thread.sleep(2000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} */
			inited = true;
		}

		
		long rc = N_loadFile(file.getPath());
		return (rc == 0 ? null : (Long)rc);
	}
	
	@Override
	public Object loadInfo(File file) throws IOException {
		return file.getName();
		//return load(file);
	}
	
	

	@Override
	public void unload(Object song) {
		if(song instanceof String) {
			return;
		}
		N_unload((Long)song);
	}
	
	@Override
	public boolean setTune(Object song, int tune) {
		if(song instanceof String) {
			return false;
		}
		return N_setTune((Long)song, tune);
	}
	
	@Override
	public boolean seekTo(Object song, int msec) {
		if(song instanceof String) {
			return false;
		}
		return N_seekTo((Long)song, msec);
	}
	
	native public void N_init(String baseDir);
	
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
