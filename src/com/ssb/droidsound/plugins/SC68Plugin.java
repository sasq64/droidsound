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

	@Override
	public boolean canHandle(String name) {
		String ext = name.substring(name.indexOf('.') + 1).toUpperCase();
		return ext.equals("SNDH") || ext.equals("SC68") || ext.equals("SND");
	}

	@Override
	protected boolean load(String name, byte[] data) {
		currentSong = N_load(data, data.length);
		if (currentSong == 0) {
			return false;
		}

		return true;
	}

	@Override
	public void unload() {
		if (currentSong != 0)
			N_unload(currentSong);
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
		return N_getStringInfo(currentSong, what);
	}

	@Override
	public int getIntInfo(int what) {
		if (currentSong == 0) {
			return -1;
		}

		int rc = N_getIntInfo(currentSong, what);
		if (what == INFO_LENGTH && rc == 0)
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
		return "SC68 3.0.0";
	}

	@Override
	protected MusicInfo getMusicInfo(String name, byte[] module) {
		if (module.length < 20) {
			return null;
		}
		String head = new String(module, 0, 4, ISO88591);
		if (head.equals("ICE!")) {
			module = N_unice(module);
			if (module == null) {
				return null;
			}
		}
		int size = module.length;

		String header = new String(module, 12, 4, ISO88591);
		String header2 = new String(module, 0, 16, ISO88591);
		if (header.equals("SNDH")) {
			MusicInfo info = new MusicInfo();
			info.format = "SNDH";

			int offset = 16;
			while (offset < 1024) {
				String tag = new String(module, offset, 4, ISO88591);
				if (tag.equals("TITL")) {
					info.title = readNullTerminated(module, offset + 4);
					offset += 4 + info.title.length();
				} else if (tag.equals("COMM")) {
					info.composer = readNullTerminated(module, offset + 4);
					offset += 4 + info.composer.length();
				} else if (tag.equals("YEAR")) {
					String year = readNullTerminated(module, offset + 4);
					try {
						info.date = Integer.valueOf(year) * 10000;
					}
					catch (NumberFormatException nfe) {
					}
					offset += 4 + year.length();
				} else if (tag.equals("HDNS")) {
					break;
				}

				offset ++;
			}

			return info;
		}
		if (header2.equals("SC68 Music-file ")) {
			MusicInfo info = new MusicInfo();
			info.format = "SC68";

			int offset = 56;
			while (offset < 1024) {
				String tag = new String(module, offset, 4, ISO88591);
				int tsize = (module[offset+4] & 0xff)
						| ((module[offset+5] & 0xff) << 8)
						| ((module[offset+6] & 0xff) << 16)
						| ((module[offset+7] & 0xff) << 24);
				offset += 8;
				if (tsize < 0 || tsize > size) {
					break;
				}

				if (tag.equals("SCMN")) {
					info.title = new String(module, offset, tsize, ISO88591);
				} else if (tag.equals("SCFN")) {
					if (info.title != null) {
						info.title = new String(module, offset, tsize, ISO88591);
					}
				} else if (tag.equals("SCAN")) {
					info.composer = new String(module, offset, tsize, ISO88591);
				} else if (tag.equals("SC68")) {
					tsize = 0;
				} else if (tag.equals("SCEF") || tag.equals("SCDA")) {
					break;
				}

				offset += tsize;
			}

			return info;
		}

		return null;
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
