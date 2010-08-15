package com.ssb.droidsound;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;

import com.ssb.droidsound.plugins.DroidSoundPlugin;

import android.content.ContentValues;
import android.util.Log;

public class FileIdentifier {
	private static final String TAG = FileIdentifier.class.getSimpleName();
	
	private static Map<String, Integer> extensions;

	private static HashSet<String> modMagic;

	private static DroidSoundPlugin[] plugins;

	private static boolean indexUnknown;
	
	public static final int TYPE_MOD = 1;
	public static final int TYPE_SID = 2;
	public static final int TYPE_XM = 3;
	public static final int TYPE_S3M = 4;
	public static final int TYPE_IT = 5;
	public static final int TYPE_NSF = 6;
	public static final int TYPE_SPC = 7;
	
	public static class MusicInfo {
		String title;
		String composer;
		String copyright;
		String game;
		String format;
		int channels;
		int type;
		int date;
	};


	static {
		extensions = new HashMap<String, Integer>();
		extensions.put("MOD", TYPE_MOD);
		extensions.put("SID", TYPE_SID);
		extensions.put("XM", TYPE_XM);
		extensions.put("S3M", TYPE_S3M);
		extensions.put("IT", TYPE_IT);
		extensions.put("NSF", TYPE_NSF);
		extensions.put("SPC", TYPE_SPC);
			
		
		modMagic = new HashSet<String>();
		modMagic.add("M.K.");
		modMagic.add("M!K!");
		modMagic.add("M&K!");
		modMagic.add("N.T.");
		modMagic.add("M!K!");
		modMagic.add("4CHN");
		modMagic.add("6CHN");
		modMagic.add("8CHN");
		modMagic.add("FLT4");
		modMagic.add("FLT8");
	}
	
	/**
	 * NAME RULES:
	 * 
	 * If composer could not be found, try to parse title & composer from filename.
	 * 
	 * If game was set but not title, use game as title
	 *
	 * If title still not found, use filename (without extension) as title 
	 * 
	 */
	private static void fixName(String fname, MusicInfo info) {
		//String ext = "";
		int slash = fname.lastIndexOf('/');
		if(slash >= 0) {
			fname = fname.substring(slash+1);
		}
		int dot = fname.lastIndexOf('.');
		if(dot > 0) {
			//ext = fname.substring(dot+1).toUpperCase();
			fname = fname.substring(0, dot);
		}
		
		if(info.composer == null || info.composer.length() == 0) {
			int sep = fname.indexOf(" - ");
			if(sep > 0) {
				info.composer = fname.substring(0, sep);
				info.title = fname.substring(sep+3);
			}
		}

		if(info.composer != null && info.composer.length() == 0) {
			info.composer = null;
		}
					
		if(info.title == null || info.title.length() == 0) {
			info.title = info.game;
		}

		if(info.title == null || info.title.length() == 0) {
			info.title = fname;
		}
		
		if(info.date < 0 && info.copyright != null && info.copyright.length() >= 4) {
			int year = -1;
			try {
				year = Integer.parseInt(info.copyright.substring(0,4));
			} catch (NumberFormatException e) {
			}
			if(year > 1000 && year < 2100) {
				info.date = year * 10000;
			}
		}		
	}
	
	private static String fromData(byte [] data, int start, int len) throws UnsupportedEncodingException {
		int i = start;
		for(; i<start+len; i++) {
			if(data[i] == 0) {
				i++;
				break;
			}
		}
		
		//int o = start + len - 1;
		//while(o >= start && data[o] == 0) {
		//	o -= 1;
		//}
		return new String(data, start, i-start, "ISO-8859-1").trim();
	}
	
	
	public static void setPlugins(DroidSoundPlugin[] pl) {
		plugins = pl;
	}
	
	
	private static MusicInfo tryLoad(DroidSoundPlugin plugin, InputStream is) throws IOException {
		Object songRef = plugin.loadInfo(is, is.available());
		if(songRef != null) {
			MusicInfo info = new MusicInfo();
			info.title = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_TITLE);
			info.composer = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_AUTHOR);
			info.copyright = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_COPYRIGHT);
			info.game = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_GAME);
			info.format = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_TYPE);
			//info. = plugin.getIntInfo(songRef, DroidSoundPlugin.INFO_LENGTH);
			info.date = -1;
			plugin.unload(songRef);
			
			Log.v(TAG, String.format("TITLE: %s -- COMPOSER: %s", info.title, info.composer));
			
			return info;
		}		
		return null;
	}

	
	public static MusicInfo identify(String name, InputStream is) {

		byte data [];
		String magic;

		int dot = name.lastIndexOf('.');
		
		String ext = name.substring(dot+1).toUpperCase();
		//Log.v(TAG, String.format("hash %s %d", extensions.toString(), extensions.size()));
		Integer i = extensions.get(ext);
		if(i == null) {
			
			
			List<DroidSoundPlugin> list = new ArrayList<DroidSoundPlugin>();
			for(int j = 0; j < plugins.length; j++) {
				if(plugins[j].canHandle(name)) {
					list.add(plugins[j]);
					Log.v(TAG, String.format("%s handled by %d", name, j));
				}
			}
			
			
			//Log.v(TAG, "MarkSupported " + is.markSupported());
			
			for(DroidSoundPlugin plugin : list) {
				Log.v(TAG, "Trying " + plugin.getClass().getName());
				MusicInfo info = null;
				try {
					is.mark(is.available());
					info = tryLoad(plugin, is);
					is.reset();
				} catch (IOException e) {
				}
				if(info != null) {
					fixName(name, info);
					return info;
				}
			}
			
			if(indexUnknown) {
				Log.v(TAG, "Trying non-handling plugins");
				for(int j = 0; j < plugins.length; j++) {
					if(!plugins[j].canHandle(name)) {
						Log.v(TAG, "Trying " + plugins[j].getClass().getName());
						MusicInfo info = null;
						try {
							is.mark(is.available());
							info = tryLoad(plugins[j], is);
							is.reset();
						} catch (IOException e) {
						}
						if(info != null) {
							fixName(name, info);
							return info;
						}
					}
				}
			}
			
			return null;
		}
		int extno = i;		
		//Log.v(TAG, String.format("Ext %s -> Format %02x", ext, extno));

		MusicInfo info = new MusicInfo();
		info.type = extno;
		info.date = -1;

		try {
			switch(extno) {
			case TYPE_SID:
				data = new byte [0x80];
				is.read(data);
				magic = new String(data, 0,4);
				if(magic.equals("PSID") || magic.equals("RSID")) {
					info.title = fromData(data, 0x16, 32); //new String(data, 0x16, o-0x15, "ISO-8859-1");
					info.composer = fromData(data, 0x36, 32); //new String(data, 0x36, o-0x35, "ISO-8859-1");
					info.copyright = fromData(data, 0x56, 32); //new String(data, 0x56, o-0x55, "ISO-8859-1");
				} else {
					return null;
				}
				break;
			case TYPE_MOD:
				data = new byte [0x480];
				is.read(data);
				magic = new String(data, 0x438,4);
				Log.v(TAG, String.format("MOD MAGIC %s", magic));

				if(!modMagic.contains(magic)) {
					return null;
				}
				info.title = fromData(data, 0, 20); //new String(data, 0, 22, "ISO-8859-1");
				info.format = "MOD";
				break;
			case TYPE_S3M:
				data = new byte [50];
				is.read(data);
				magic = new String(data, 44, 4);
				if(!magic.equals("SCRM")) {
					return null;
				}
				info.title = fromData(data, 0, 28); //new String(data, 0, 28, "ISO-8859-1");
				info.format = "S3M";
				break;
			case TYPE_XM:
				data = new byte [0x70];
				is.read(data);
				magic = new String(data, 0, 15);
				if(!magic.equals("Extended Module")) {
					return null;
				}
				info.title = fromData(data, 17, 20); //new String(data, 17, 20, "ISO-8859-1");
				info.channels = data[0x68];
				info.format = "XM";
				break;
			case TYPE_IT:
				data = new byte [32];
				is.read(data);
				magic = new String(data, 0, 4);
				if(!magic.equals("IMPM")) {
					return null;
				}
				info.title = fromData(data, 4, 26); //new String(data, 4, 26, "ISO-8859-1");
				info.format = "IT";
				break;
			case TYPE_NSF:
				data = new byte [128];
				is.read(data);
				magic = new String(data, 0, 4);
				if(!magic.equals("NESM")) {
					return null;
				}
				info.title = fromData(data, 0xe, 32); //new String(data, 0xe, 32, "ISO-8859-1");
				info.composer = fromData(data, 0x2e, 32); //new String(data, 0x2e, 32, "ISO-8859-1");
				info.copyright = fromData(data, 0x4e, 32); //new String(data, 0x4e, 32, "ISO-8859-1");
				info.format = "NES";
				break;
			case TYPE_SPC:				
				data = new byte [0xd8];
				is.read(data);
				magic = new String(data, 0, 27);
				if(!magic.equals("SNES-SPC700 Sound File Data")) {
					return null;
				}
				
				if(data[0x23] == 0x1a) {
					info.title = fromData(data, 0x2e, 32);
					info.game = fromData(data, 0x4e, 32);
					info.composer = fromData(data, 0xb1, 32);
				}
				break;
			default:
				return null;
			}
		} catch (IOException e) {
			return null;
		}
		
		fixName(name, info);
		return info;
	}

	public static void setIndexUnknown(boolean idx) {		
		indexUnknown = idx;
	}
}
