package com.ssb.droidsound.plugins;

import java.io.File;
import java.nio.charset.Charset;

import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.utils.Unzipper;

public class SC68Plugin extends DroidSoundPlugin {
	private static final String TAG = SC68Plugin.class.getSimpleName();
	private static final Charset ISO88591 = Charset.forName("ISO-8859-1");
	private static final String[] HWS = { "?", "YM", "STE", "YM+STE", "Amiga", "Amiga+YM", "Amiga+STE", "Amiga++" };

	static {
		System.loadLibrary("sc68");
		File pluginDir = Application.getPluginDataDirectory(SC68Plugin.class);
		File sc68Dir = new File(pluginDir, "sc68data");
		if (! sc68Dir.exists()) {
			Unzipper.unzipAsset("sc68data.zip", pluginDir);
		}
		N_setDataDir(sc68Dir.getPath());
	}

	private long currentSong;

	private long pluginRef;

	private String title = null;
	private String composer = null;
	private String year = null;
	private String type = null;

	@Override
	public boolean canHandle(String name) {
		String ext = name.substring(name.indexOf('.') + 1).toLowerCase();
		return ext.equals("sndh") || ext.equals("sc68") || ext.equals("snd");
	}

	@Override
	public void unload() {
		if (currentSong != 0)
			N_unload(currentSong);
	}

	@Override
	public boolean load(String name, byte[] module) {
		currentSong = N_load(module, module.length);
		return currentSong != 0;
	}

	@Override
	public String[] getDetailedInfo() {
		String replay = getStringInfo(52);
		String hwname = getStringInfo(51);
		int hwbits = getIntInfo(50);
		return new String[] {
				"Format", String.format("SC68: %s", replay != null ? replay : "?"),
				"Hardware", String.format("%s (%s)", hwname != null ? hwname : "?", HWS[hwbits])
		};
	}

	@Override
	public boolean loadInfo(String name, byte[] data) {
		currentSong = 0;
		title = null;
		composer = null;
		year = null;
		type = null;

		String head = new String(data, 0, 4, ISO88591);
		if (head.equals("ICE!")) {
			data = N_unice(data);
			if (data == null)
				return false;
		}
		int size = data.length;

		String header = new String(data, 12, 4, ISO88591);
		String header2 = new String(data, 0, 16, ISO88591);
		if (header.equals("SNDH")) {
			type = "SNDH";

			int offset = 16;
			while (offset < 1024) {
				String tag = new String(data, offset, 4, ISO88591);
				if (tag.equals("TITL")) {
					title = readNullTerminated(data, offset + 4);
					offset += 4 + title.length();
				} else if (tag.equals("COMM")) {
					composer = readNullTerminated(data, offset + 4);
					offset += 4 + composer.length();
				} else if (tag.equals("YEAR")) {
					year = readNullTerminated(data, offset + 4);
					offset += 4 + year.length();
				} else if (tag.equals("HDNS")) {
					break;
				}

				offset ++;
			}

			return true;
		}
		if (header2.equals("SC68 Music-file ")) {
			int offset = 56;
			type = "SC68";
			while (offset < 1024) {
				String tag = new String(data, offset, 4, ISO88591);
				int tsize = (data[offset+4] & 0xff)
						| ((data[offset+5] & 0xff) << 8)
						| ((data[offset+6] & 0xff) << 16)
						| ((data[offset+7] & 0xff) << 24);
				offset += 8;
				if (tsize < 0 || tsize > size) {
					break;
				}

				if (tag.equals("SCMN")) {
					title = new String(data, offset, tsize, ISO88591);
				} else if (tag.equals("SCFN")) {
					if (title != null) {
						title = new String(data, offset, tsize, ISO88591);
					}
				} else if (tag.equals("SCAN")) {
					composer = new String(data, offset, tsize, ISO88591);
				} else if (tag.equals("SC68")) {
					tsize = 0;
				} else if (tag.equals("SCEF") || tag.equals("SCDA")) {
					break;
				}

				offset += tsize;
			}

			return true;
		}

		return false;
	}

	private String readNullTerminated(byte[] data, int i) {
		int len = 0;
		while (i + len < data.length && data[i + len] != 0) {
			len ++;
		}
		return new String(data, i, len, ISO88591);
	}

	@Override
	public int getSoundData(short[] dest) {
		return N_getSoundData(currentSong, dest, dest.length);
	}

	@Override
	public String getStringInfo(int what) {
		if (currentSong == 0) {
			switch (what) {
			case INFO_TITLE:
				return title;
			case INFO_AUTHOR:
				return composer;
			case INFO_COPYRIGHT:
				return year;
			case INFO_TYPE:
				return type;
			}
			return null;
		}
		return N_getStringInfo(currentSong, what);
	}

	@Override
	public int getIntInfo(int what) {
		if (currentSong == 0) {
			return -1;
		}

		int rc = N_getIntInfo(currentSong, what);
		if(what == INFO_LENGTH && rc == 0)
			rc = -1;
		return rc;
	}

	@Override
	public boolean setTune(int tune) {
		return N_setTune(currentSong, tune);
	}

	@Override
	public boolean seekTo(int msec) {
		return N_seekTo(currentSong, msec);
	}

	@Override
	public void setOption(String string, Object val) {
		/* No options */
	}

	@Override
	public String getVersion() {
		return "Version 3.0.0\nCopyright (C) 2009 Benjamin Gerard";
	}

	native private static void N_setDataDir(String dataDir);

	native private long N_load(byte[] module, int size);
	native private long N_loadInfo(byte[] module, int size);
	native private void N_unload(long song);

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native private int N_getSoundData(long song, short [] dest, int size);
	native private boolean N_seekTo(long song, int seconds);
	native private boolean N_setTune(long song, int tune);
	native private String N_getStringInfo(long song, int what);
	native private int N_getIntInfo(long song, int what);

	native private byte[] N_unice(byte[] data);
}
