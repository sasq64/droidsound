package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import com.ssb.droidsound.SongDatabase;

import android.content.Context;
import android.util.Log;


public class ModPlugin extends DroidSoundPlugin {
	private static final String TAG = ModPlugin.class.getSimpleName();
	
	static {
		System.loadLibrary("modplug");
	}
	private Set<String> extensions;
	private Map<Object, String> authors = new HashMap<Object, String>();

	public ModPlugin(Context ctx) {
		super(ctx);
		extensions = new HashSet<String>();
		extensions.add("MOD");
		extensions.add("XM");
		extensions.add("S3M");
		extensions.add("IT");
	}

	@Override
	public boolean canHandle(String name) {
		int x = name.lastIndexOf('.');
		if(x < 0) return false;
		String ext = name.substring(x+1).toUpperCase();
		return extensions.contains(ext);
	}
	
	@Override
	public Object load(byte [] module, int size) {
		long rc = N_load(module, size);
		if(rc != 0) {
			String a = guessAuthor(N_getStringInfo(rc, 100));
			authors.put((Long)rc, a);
		}
		return rc != 0 ? rc : null; 
	}
	
	static String t [] = new String [256];

	
	private String guessAuthor(String instr) {
		
		String s [] = instr.split("\\n");
		
		int n = 0;
		
		for(int k=0; k<s.length; k++) {
			String d [] = s[k].split("\\s+");
			
			for(int i=0; i<d.length; i++) {
				Log.v(TAG, d[i]);
				String x = "";
				if(d[i].equals("/")) {
					//Log.v(TAG, "/BY/");
					x = "/";
				} else
				if(d[i].equals("&") || d[i].equals("&")) {
					x = "and";
				} else
				if(d[i].length() > 1) {
					
					if(d[i].endsWith("/")) {
						x = d[i].replaceAll("^[^\\w]*", "");
					} else if(d[i].startsWith("/")) {
						x = d[i].replaceAll("[^\\w]*$", "");
					} else {				
						x = d[i].replaceAll("^[^\\w]*", "").replaceAll("[^\\w]*$", "");
					}
					//Log.v(TAG, String.format("'%s' '%s'", t[i], x));
				}
				
				if(x.length() > 0) {
					
					int plus = x.indexOf('&');
					if(plus == -1) {
						plus = x.indexOf('+');
					}
					
					if(plus > 0) {
						t[n++] = x.substring(0, plus);
						t[n++] = "and";
						x = x.substring(plus+1);
					}

					int slash = x.indexOf('/');
					
					if(slash >= 0) {
						t[n++] = x.substring(0, slash);
						t[n++] = "/";
						x = x.substring(slash+1);
					}

					t[n++] = x;
				}				
			}	
			
			t[n++] = "EOL";
		}
				
		
		String author [] = new String [4];
		
		String lastWord = "";
		String lastLastWord = "";
		for(int i=0; i<n; i++) {
			
			if(t[i].length() > 0 && !t[i].equals("EOL")) {
				// Log.v(TAG, String.format("'%s'", t[i]));
				
				if(t[i].toUpperCase().equals("PRO-WIZARD")) {
					break;
				}
				
				String nextWord = "EOL";
				int ii = i+1;
				while(ii < n && (nextWord.equals("EOL") || nextWord.length() == 0)) {
					nextWord = t[ii++].toUpperCase();					
				}
				
				// Log.v(TAG, String.format("NW:%s", nextWord));
				
				String a = t[i];			
				if(lastWord.equals("BY")) {
					
					//if(nextWord.equals("AND") && i<n-2) {
					//	a += ("and" + t[i+2]);
					//}
					
					if(a.toUpperCase().equals("ME")) {
						break;
					}
					
					ii = i+1;
					while(!t[ii].equals("EOL")) {
						if(t[ii].toUpperCase().equals("OF") || t[ii].equals("/")) {
							break;
						}
						a += (" " + t[ii]);
						ii++;
					}
					
					/*
					if(nextWord.equals("OF") && i<n-2) {
						a += (" of " + t[i+2]);
						if(i<n-3 && t[i+2].toUpperCase().equals("THE")) {
							a += (" " + t[i+2]);
						}
					} */
	
					if(lastLastWord.equals("COMPOSED") || lastLastWord.equals("MADE")) {
						author[0] = a;
						break;
					}
					else
					if(lastLastWord.equals("RIPPED") || lastLastWord.equals("ORIGINAL")) {
					} else {
						if(author[1] == null) {
							author[1] = a;
						}
					}
				} else if(nextWord.equals("/") || nextWord.equals("OF")) {
					
					//int x = 2;
					//if(nextWord.equals("of")) {
					//	x = 3;
					//}
					//Log.v(TAG, String.format("OF AUTHOR '%s'", a));
					
					if(author[2] == null) {
						
						if(lastWord.equals("AND")) {
							if(t[i-2].length() > 0) {
								a = t[i-2] + " and " + a;
							}
						}
						
						author[2] = a;
					}
				} 
					
				lastLastWord = lastWord;
				lastWord = t[i].toUpperCase();
			} else {
				// Log.v(TAG, String.format("(%s)", t[i]));
			}
		}
		String a = null;
		for(int i=0; i<4; i++) {
			if(author[i] != null) {
				//a = author[i].replace("/", " of ");
				a = author[i];
				Log.v(TAG, String.format("AUTHOR '%s', %d", author[i], i));
				break;
			}
		}
		return a;		
		
	}

	@Override
	public void unload(Object song) {
		
			authors.remove(song);	
			N_unload((Long)song);
	}
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	@Override
	public int getSoundData(Object song, short [] dest, int size) { return N_getSoundData((Long)song, dest, size); }	
	@Override
	public boolean seekTo(Object song, int seconds) { return N_seekTo((Long)song, seconds); }
	@Override
	public boolean setTune(Object song, int tune) { return false; }
	@Override
	public String getStringInfo(Object song, int what) {
		
		if(what == INFO_AUTHOR) {
			String a = authors.get(song);
			//if(a != null) {
				return a;
			//}
		}		
		return N_getStringInfo((Long)song, what);
	}
	@Override
	public int getIntInfo(Object song, int what) { return N_getIntInfo((Long)song, what); }

	@Override
	public Object loadInfo(File file) throws IOException {
		int l = (int)file.length();
		byte [] songBuffer = new byte [l];
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);

		long song = N_load(songBuffer, l);
		if(song == 0)
			return null;
		else {
			String a = guessAuthor(N_getStringInfo(song, 100));
			authors.put((Long)song, a);
			return song;
		}
	}
	
	@Override
	public String[] getDetailedInfo(Object song) {
		
		String instruments = N_getStringInfo((Long)song, 100);
		String fmt = getStringInfo(song, INFO_TYPE);
		Log.v(TAG, "INSTRUMENTS: " + instruments);
		int channels = N_getIntInfo((Long)song, 101);

		String[] info;
		if(instruments != null && instruments.length() > 0) {
			info = new String [6];
			info[4] = "Instruments";
			info[5] = instruments;
		} else {
			info = new String [4];
		}
		info[0] = "Channels";
		info[1] = Integer.toString(channels);
		info[2] = "Format";
		info[3] = fmt;
		return info;
	}
	
	// --- Native functions
	
	native public boolean N_canHandle(String name);
	native public long N_load(byte [] module, int size);
	native public long N_loadInfo(byte [] module, int size);
	native public void N_unload(long song);
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native public int N_getSoundData(long song, short [] dest, int size);	
	native public boolean N_seekTo(long song, int seconds);
	native public boolean N_setTune(long song, int tune);
	native public String N_getStringInfo(long song, int what);
	native public int N_getIntInfo(long song, int what);

}
