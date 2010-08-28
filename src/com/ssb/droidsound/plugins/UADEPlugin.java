package com.ssb.droidsound.plugins;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.util.Enumeration;
import java.util.HashSet;
import java.util.Set;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import android.content.Context;
import android.os.Environment;
import android.util.Log;

public class UADEPlugin extends DroidSoundPlugin {
	private static final String TAG = UADEPlugin.class.getSimpleName();

	static {
		//System.loadLibrary("uade");
	}

	private static Set<String> extensions = new HashSet<String>();

	private static boolean inited;

	private long currentSong = 0;
	
	public UADEPlugin() {

		Context ctx = getContext();

		File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
		//File filesDir = ctx.getFilesDir();
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
				try {			
					File tempFile = new File(droidDir, "ep.zip");
					
					FileOutputStream os;
					os = new FileOutputStream(tempFile);
					
					InputStream is = ctx.getAssets().open("eagleplayers.zip");
					
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
						File efile = new File(droidDir, name);
						
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
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
			}		

			if(extensions.size() == 0) {
		
				extensions.add("CUST");		
				extensions.add("CUS");
				extensions.add("CUSTOM");
				extensions.add("DM");
				
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
								//Log.v(TAG, "Ext " + ex);
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
		//for(String s : ex) {			
		//	extensions.add(s);
		//}
	}
	
	@Override
	public boolean canHandle(String name) {

		int x = name.lastIndexOf('.');
		
		if(x < 0) return false;
		String ext = name.substring(x+1).toUpperCase();
		if(!extensions.contains(ext)) {
			int slash = name.lastIndexOf('/');
			x = name.indexOf('.', slash+1);
			ext = name.substring(slash+1, x).toUpperCase();
			Log.v(TAG, "Checking prefix " + ext);
			return extensions.contains(ext);
		}
		return true;
		
	}

	
	@Override
	public String getBaseName(String name) {
				
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
		//Log.v(TAG, "getSoundData()");
		return N_getSoundData(currentSong, dest, size);
	}
	
	@Override
	public String[] getDetailedInfo() {

		if(currentSong == 0) {
			return null;
		}

		String [] details = new String [2];
		details[0] = "Format";
		details[1] = N_getStringInfo(currentSong, INFO_TYPE);
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
	public boolean load(String name, byte[] module, int size) {
	
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
		
		Context context = getContext();

		//File filesDir = context.getFilesDir();
		File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");

		if(!inited) {
			
			Log.v(TAG, "Loading library");
			System.loadLibrary("uade");
			
			N_init(droidDir.getPath());
			/*try {
				Thread.sleep(2000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} */
			inited = true;
		}

		
		currentSong = N_loadFile(file.getPath());
		return (currentSong != 0);
	}
	
	@Override
	public boolean loadInfo(File file) throws IOException {
		currentSong = 0;
		return true;
		//return load(file);
	}

	@Override
	public boolean loadInfo(String name, InputStream is, int size) throws IOException {
		currentSong = 0;
		return true;
	}
	
	@Override
	public boolean loadInfo(String name, byte[] module, int size) {
		currentSong = 0;
		return true;
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
