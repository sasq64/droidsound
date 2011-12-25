package com.ssb.droidsound.utils;

import java.io.IOException;
import java.nio.charset.Charset;
import java.util.List;

import com.ssb.droidsound.plugins.DroidSoundPlugin;

public class FileIdentifier {
	private static enum Extension { MOD, SID, XM, S3M, IT, NSF, SPC, PRG }

	private static final Charset ISO88591 = Charset.forName("ISO-8859-1");
	private static final List<DroidSoundPlugin> plugins = DroidSoundPlugin.getPluginList();

	public static class MusicInfo {
		public String title;
		public String composer;
		public String copyright;
		public String format;

		public int channels;
		public Extension type;
		public int date;
	};

	/**
	 * NAME RULES:
	 *
	 * If composer could not be found, try to parse title & composer from filename.
	 *
	 * If title still not found, use filename (without extension) as title
	 */
	private static void fixName(String basename, MusicInfo info) {
		if (info.composer == null || info.composer.length() == 0) {
			int sep = basename.indexOf(" - ");
			if (sep > 0) {
				info.composer = basename.substring(0, sep);
				info.title = basename.substring(sep+3);
			}
		}

		if (info.composer != null && info.composer.length() == 0) {
			info.composer = null;
		}

		if (info.title == null || info.title.length() == 0) {
			info.title = basename;
		}

		if (info.date < 0 && info.copyright != null && info.copyright.length() >= 4) {
			int year = -1;
			try {
				year = Integer.parseInt(info.copyright.substring(0,4));
			} catch (NumberFormatException e) {
			}
			if (year > 1000 && year < 2100) {
				info.date = year * 10000;
			}
		}
	}

	private static String fromData(byte[] module, int start, int len) {
		return new String(module, start, len, ISO88591).replaceAll("\u0000", "").trim();
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
		for (DroidSoundPlugin plugin : plugins) {
			if(plugin.canHandle(name)) {
				return plugin.getClass().getSimpleName();
			}
		}
		return null;
	}


	public static MusicInfo identify(String name1, byte[] module1, String name2, byte[] module2) throws IOException {
		int dot = name1.lastIndexOf('.');
		final Extension nameExt;
		try {
			String ext = name1.substring(dot + 1).toUpperCase();
			nameExt = Extension.valueOf(ext);
		}
		catch (IllegalArgumentException iae) {
			for (DroidSoundPlugin plugin : plugins) {
				if (plugin.canHandle(name1) && plugin.load(name1, module1, name2, module2)) {
					MusicInfo info = new MusicInfo();
					info.title = plugin.getStringInfo(DroidSoundPlugin.INFO_TITLE);
					info.composer = plugin.getStringInfo(DroidSoundPlugin.INFO_AUTHOR);
					info.copyright = plugin.getStringInfo(DroidSoundPlugin.INFO_COPYRIGHT);
					info.format = plugin.getStringInfo(DroidSoundPlugin.INFO_TYPE);
					info.date = -1;
					plugin.unload();
					return info;
				}
			}
			return null;
		}

		MusicInfo info = new MusicInfo();
		info.type = nameExt;
		info.date = -1;

		switch (nameExt) {
		case PRG: {
			name1 = getBaseName(name1);
			info.format = "SID";
			fixName(name1, info);
			return info;
		}

		case SID: {
			String magic = new String(module1, 1, 3, ISO88591);
			if (magic.equals("SID")) {
				info.title = fromData(module1, 0x16, 32);
				info.composer = fromData(module1, 0x36, 32);
				info.copyright = fromData(module1, 0x56, 32);
				info.format = "SID";
				if (info.copyright.length() >= 4) {
					try {
						int year = Integer.valueOf(info.copyright.substring(0,4));
						if (year > 1900 && year < 2100) {
							info.date = year * 10000;
						}
					} catch (NumberFormatException e) {
					}
				}
				return info;

			} else {
				return null;
			}
		}

		case MOD: {
			info.title = null;
			info.format = "MOD";
			break;
		}

		case S3M: {
			String magic = new String(module1, 44, 4, ISO88591);
			if (! magic.equals("SCRM")) {
				return null;
			}
			info.title = fromData(module1, 0, 28);
			info.format = "S3M";
			break;
		}

		case XM: {
			String magic = new String(module1, 0, 15, ISO88591);
			if (! magic.equals("Extended Module")) {
				return null;
			}
			info.title = fromData(module1, 17, 20);
			info.channels = module1[0x68];
			info.format = "XM";
			break;
		}

		case IT: {
			String magic = new String(module1, 0, 4, ISO88591);
			if (! magic.equals("IMPM")) {
					return null;
			}
			info.title = fromData(module1, 4, 26);
			info.format = "IT";
			break;
		}

		case NSF: {
			String magic = new String(module1, 0, 4, ISO88591);
			if (! magic.equals("NESM")) {
				return null;
			}
			info.title = fromData(module1, 0xe, 32);
			info.composer = fromData(module1, 0x2e, 32);
			info.copyright = fromData(module1, 0x4e, 32);
			info.format = "NES";
			break;
		}

		case SPC: {
			info.format = "SNES";
			String magic = new String(module1, 0, 27, ISO88591);
			if (! magic.equals("SNES-SPC700 Sound File Data")) {
				return null;
			}

			if (module1[0x23] == 0x1a) {
				info.title = fromData(module1, 0x2e, 32);
				String game = fromData(module1, 0x4e, 32);

				if (game.length() > 0) {
					info.title = game + " - " + info.title;
				}

				info.composer = fromData(module1, 0xb1, 32);
			}
			break;
		}

		default:
			return null;
		}

		if (dot > 0) {
			name1 = name1.substring(0, dot);
		}
		int slash = name1.lastIndexOf('/');
		if (slash >= 0) {
			name1 = name1.substring(slash+1);
		}

		fixName(name1, info);
		return info;
	}
}
