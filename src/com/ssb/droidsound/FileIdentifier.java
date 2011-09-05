package com.ssb.droidsound;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.util.*;

import com.ssb.droidsound.utils.Log;

import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsoundedit.R;

public final class FileIdentifier {
	private static final String TAG = FileIdentifier.class.getSimpleName();

	private static final Map<String, Integer> extensions;

    private static List<DroidSoundPlugin> plugins;

	private static boolean indexUnknown;

	private static final int TYPE_MOD = 1;
	private static final int TYPE_SID = 2;
	private static final int TYPE_XM = 3;
	private static final int TYPE_S3M = 4;
	private static final int TYPE_IT = 5;
	private static final int TYPE_NSF = 6;
	private static final int TYPE_SPC = 7;
	private static final int TYPE_PRG = 8;
	//public static final int TYPE_VGM = 8;

	public static final class MusicInfo {
		public String title;
		public String composer;
		private String copyright;
		//String game;
		public String format;

		public int channels;
		public int type;
		public int date;
	}


	//File extensions
	static {
		extensions = new HashMap<String, Integer>();
		extensions.put("MOD", TYPE_MOD);
		extensions.put("SID", TYPE_SID);
		extensions.put("XM", TYPE_XM);
		extensions.put("S3M", TYPE_S3M);
		extensions.put("IT", TYPE_IT);
		extensions.put("NSF", TYPE_NSF);
		extensions.put("SPC", TYPE_SPC);
		extensions.put("PRG", TYPE_PRG);
		//extensions.put("VGM", TYPE_VGM);

        //HashSet<String> modMagic = new HashSet(); Weaker type is below
        Collection<String> modMagic = new HashSet<String>();
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
     * @param basename
     * @param info
     */
	private static void fixName(String basename, MusicInfo info) {


		if(info.composer == null || info.composer.length() == 0) {
			int sep = basename.indexOf(" - ");
			if(sep > 0) {
				info.composer = basename.substring(0, sep);
				info.title = basename.substring(sep+3);
			}
		}

		if(info.composer != null && info.composer.length() == 0) {
			info.composer = null;
		}



		if(info.title == null || info.title.length() == 0) {
			info.title = basename;
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
		return new String(data, start, i-start, "ISO-8859-1").trim();
	}


	private static MusicInfo tryLoad(DroidSoundPlugin plugin, InputStream is, String name) throws IOException {

		if(plugin.loadInfo(name, is, is.available())) {
			MusicInfo info = new MusicInfo();
			info.title = plugin.getStringInfo(DroidSoundPlugin.INFO_TITLE);
			info.composer = plugin.getStringInfo(DroidSoundPlugin.INFO_AUTHOR);
			info.copyright = plugin.getStringInfo(DroidSoundPlugin.INFO_COPYRIGHT);
			//info.game = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_GAME);
			info.format = plugin.getStringInfo(DroidSoundPlugin.INFO_TYPE);
			//info. = plugin.getIntInfo(songRef, DroidSoundPlugin.INFO_LENGTH);
			info.date = -1;
			plugin.unload();

			Log.d(TAG, "TITLE: %s -- COMPOSER: %s", info.title, info.composer);

			return info;
		}
		return null;
	}

	private static MusicInfo tryLoad(DroidSoundPlugin plugin, File file) throws IOException {

		if(plugin.loadInfo(file)) {
			MusicInfo info = new MusicInfo();
			info.title = plugin.getStringInfo(DroidSoundPlugin.INFO_TITLE);
			info.composer = plugin.getStringInfo(DroidSoundPlugin.INFO_AUTHOR);
			info.copyright = plugin.getStringInfo(DroidSoundPlugin.INFO_COPYRIGHT);
			//info.game = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_GAME);
			info.format = plugin.getStringInfo(DroidSoundPlugin.INFO_TYPE);
			//info. = plugin.getIntInfo(songRef, DroidSoundPlugin.INFO_LENGTH);
			info.date = -1;
			plugin.unload();

			Log.d(TAG, "TITLE: %s -- COMPOSER: %s", info.title, info.composer);

			return info;
		}
		return null;
	}


	public static MusicInfo identify(File f) {
		try {
			return identify(f.getName(), null, f);
		} catch (Exception e) {
			return null;
		}
	}

	public static MusicInfo identify(String name, InputStream is) {

		try {
			return identify(name, is, null);
		} catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}

	private static String getBaseName(String fname) {
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

	public static String canHandle(String name) {
		if(plugins == null) {
			plugins = DroidSoundPlugin.createPluginList();
		}
		List<DroidSoundPlugin> list = new ArrayList<DroidSoundPlugin>();
		for(DroidSoundPlugin plugin : plugins) {
			if(plugin.canHandle(name)) {
				return plugin.getClass().getSimpleName();
			}
		}
		return null;
	}


	private static MusicInfo identify(String name, InputStream is, File file) {

        if(plugins == null) {
			plugins = DroidSoundPlugin.createPluginList();
		}

		int dot = name.lastIndexOf('.');

		String ext = name.substring(dot+1).toUpperCase();
		//Log.d(TAG, "hash %s %d", extensions.toString(), extensions.size());
		Integer i = extensions.get(ext);
		if(i == null) {

            //List<DroidSoundPlugin> list = new ArrayList();
			Collection<DroidSoundPlugin> list = new ArrayList<DroidSoundPlugin>();
			for(DroidSoundPlugin plugin : plugins) {
				if(plugin.canHandle(name)) {
					list.add(plugin);
					Log.d(TAG, "%s handled by %s", name, plugin.getClass().getSimpleName());
				}
			}

            if(is != null) {
                int available = 0;
                try {
					available = is.available();
				} catch (IOException e1) {
					return null;
				}

				if(!is.markSupported() && (indexUnknown || list.size() > 1)) {
					is = new BufferedInputStream(is, available);
				}
			}

			//Log.d(TAG, "MarkSupported " + is.markSupported());

			for(DroidSoundPlugin plugin : list) {
				Log.d(TAG, "Trying " + plugin.getClass().getName());
				MusicInfo info = null;

				try {
					if(file != null) {
						info = tryLoad(plugin, file);
					} else {
							is.mark(is.available());
							info = tryLoad(plugin, is, name);
							is.reset();
					}
				} catch (IOException e) {
					//e.printStackTrace();
				} catch (Exception e2) {
					e2.printStackTrace();
				}
				if(info != null) {
					Log.d(TAG, "Got info");
					name = plugin.getBaseName(name);
					fixName(name, info);
					return info;
				}
			}

			if(indexUnknown) {
				Log.d(TAG, "Trying non-handling plugins");
				for(DroidSoundPlugin plugin : plugins) {
					if(!plugin.canHandle(name)) {
						Log.d(TAG, "Trying " + plugin.getClass().getSimpleName());
						MusicInfo info = null;
						try {
							if(file != null) {
								info = tryLoad(plugin, file);
							} else {
									is.mark(is.available());
									info = tryLoad(plugin, is, name);
									is.reset();
							}
						} catch (IOException e) {
							e.printStackTrace();
						} catch (Exception e2) {
							e2.printStackTrace();
						}
						if(info != null) {
							name = plugin.getBaseName(name);
							fixName(name, info);
							return info;
						}
					}
				}
			}

			return null;
		}
        //Log.d(TAG, "Ext %s -> Format %02x", ext, extno);

		MusicInfo info = new MusicInfo();
		info.type = i;
		info.date = -1;

		if(is == null) {
			try {
				is = new FileInputStream(file);
			} catch (FileNotFoundException e) {
				Log.d(TAG, "Unexpected FileNotFoundException");
				return null;
			}
		}

		try {
            byte[] data;
            String magic;
            switch(i) {
			case TYPE_PRG:
				name = getBaseName(name);
				info.format = "SID";
				fixName(name, info);
				return info;
			case TYPE_SID:
				data = new byte [0x80];
				is.read(data);
				magic = new String(data, 1, 3);
				if("SID".equals(magic)) {
					info.title = fromData(data, 0x16, 32); //new String(data, 0x16, o-0x15, "ISO-8859-1");
					info.composer = fromData(data, 0x36, 32); //new String(data, 0x36, o-0x35, "ISO-8859-1");
					info.copyright = fromData(data, 0x56, 32); //new String(data, 0x56, o-0x55, "ISO-8859-1");
					info.format = "SID";
                    if(info.copyright.length() >= 4) {
                        int year = -1;
                        try {
							year = Integer.parseInt(info.copyright.substring(0,4));
						} catch (NumberFormatException e) {
						}
						if(year > 1000 && year < 2100) {
							info.date = year * 10000;
						}
					}
					return info;
				} else {
					return null;
				}
				
			case TYPE_MOD:
				data = new byte [0x480];
				is.read(data);
				//magic = new String(data, 0x438,4);
				//Log.d(TAG, "MOD MAGIC %s", magic);
				//if(!modMagic.contains(magic)) {
				//	return null;
				//}
				info.title = null; //fromData(data, 0, 20); //new String(data, 0, 22, "ISO-8859-1");
				info.format = "MOD";
				break;
			case TYPE_S3M:
				data = new byte [50];
				is.read(data);
				magic = new String(data, 44, 4);
				if(!"SCRM".equals(magic)) {
					return null;
				}
				info.title = fromData(data, 0, 28); //new String(data, 0, 28, "ISO-8859-1");
				info.format = "S3M";
				break;
			case TYPE_XM:
				data = new byte [0x70];
				is.read(data);
				magic = new String(data, 0, 15);
				if(!"Extended Module".equals(magic)) {
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
				if(!"IMPM".equals(magic)) {
					return null;
				}
				info.title = fromData(data, 4, 26); //new String(data, 4, 26, "ISO-8859-1");
				info.format = "IT";
				break;
			case TYPE_NSF:
				data = new byte [128];
				is.read(data);
				magic = new String(data, 0, 4);
				if(!"NESM".equals(magic)) {
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
				info.format = "SNES";
				magic = new String(data, 0, 27);
				if(!"SNES-SPC700 Sound File Data".equals(magic)) {
					return null;
				}

				if(data[0x23] == 0x1a) {
					info.title = fromData(data, 0x2e, 32);
					String game = fromData(data, 0x4e, 32);

					if(game.length() > 0) {
						info.title = game + " - " + info.title;
					}

					info.composer = fromData(data, 0xb1, 32);
				}
				break;
			/* case TYPE_VGM:
				data = new byte [0x18];
				is.read(data);
				magic = new String(data, 0, 3);
				if(!magic.equals("Vgm")) {
					return null;
				}

				magic = new String(data, 0, 3);

				int gd3offs = getInt(data, 0x14);

				is.skip(gd3offs - 18);

				break; */
			default:
				return null;
			}
		} catch (IOException e) {
			return null;
		}

		if(file != null) {
			try {
				is.close();
			} catch (IOException e) {
			}
		}

		if(dot > 0) {
			name = name.substring(0, dot);
		}
		int slash = name.lastIndexOf('/');
		if(slash >= 0) {
			name = name.substring(slash+1);
		}

		fixName(name, info);
		return info;
	}

	static int getInt(byte [] data, int o) {
		return (data[o] & 0xff) | ((data[o+1] & 0xff)<<8) | ((data[o+2] & 0xff)<<16) | ((data[o+3] & 0xff)<<24);
	}

	public static void setIndexUnknown(boolean idx) {
		indexUnknown = idx;
	}

}
