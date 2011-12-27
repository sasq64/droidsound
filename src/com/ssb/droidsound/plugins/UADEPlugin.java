package com.ssb.droidsound.plugins;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.Charset;
import java.util.HashSet;
import java.util.Set;

import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.utils.Unzipper;

public class UADEPlugin extends DroidSoundPlugin {
	private static final String TAG = UADEPlugin.class.getSimpleName();
	private static final Charset ISO88591 = Charset.forName("ISO-8859-1");
	private static final Set<String> extensions = new HashSet<String>();
	static {
		System.loadLibrary("uade");
		File pluginDir = Application.getPluginDataDirectory(UADEPlugin.class);
		File confFile = new File(pluginDir, "eagleplayer.conf");

		if (! confFile.exists()) {
			Unzipper.unzipAsset("eagleplayers.zip", pluginDir);
		}

		N_init(pluginDir.getPath());

		if (extensions.size() == 0) {
			extensions.add("CUST");
			extensions.add("CUS");
			extensions.add("CUSTOM");
			extensions.add("DM");
			extensions.add("TFX");

			try {
				BufferedReader reader = new BufferedReader(new FileReader(confFile));
				String line;
				while (null != (line = reader.readLine())) {
					int x = line.indexOf("prefixes=");
					if (x == -1) {
						continue;
					}

					String[] exts = line.substring(x+9).split(",");
					for (String ex : exts) {
						int sp = ex.indexOf('\t');
						if (sp >= 0) {
							ex = ex.substring(0, sp);
						}
						extensions.add(ex.toUpperCase());
					}
				}
				reader.close();
			} catch (IOException e) {
				throw new ExceptionInInitializerError(e);
			}
		}

		N_setOption(OPT_RESAMPLING, 2);
	}

	private long currentSong = 0;

	@Override
	public boolean canHandle(String name) {
		int dot = name.lastIndexOf('.');
		if (dot < 0) {
			return false;
		}

		String extEnd = name.substring(dot+1).toUpperCase();
		if (extensions.contains(extEnd)) {
			return true;
		}

		int slash = name.lastIndexOf('/');
		dot = name.indexOf('.', slash+1);
		if (dot > slash) {
			String extStart = name.substring(slash+1, dot).toUpperCase();
			if (extensions.contains(extStart)) {
				return true;
			}
		}

		return false;
	}

	@Override
	protected boolean load(String name, byte[] module) {
		throw new RuntimeException("This method should not be called. (See overridden load())");
	}

	@Override
	public boolean load(String f1, byte[] data1, String f2, byte[] data2) {
		File tmpDir = Application.getTmpDirectory();
		for (File f : tmpDir.listFiles()) {
			if (! f.getName().startsWith(".")) {
				f.delete();
			}
		}

		try {
			FileOutputStream fo1 = new FileOutputStream(new File(tmpDir, f1));
			fo1.write(data1);
			fo1.close();
			if (f2 != null) {
				FileOutputStream fo2 = new FileOutputStream(new File(tmpDir, f2));
				fo2.write(data1);
				fo2.close();
			}
		}
		catch (IOException ioe) {
			throw new RuntimeException(ioe);
		}

		currentSong = N_loadFile(new File(tmpDir, f1).getPath());
		return currentSong != 0;
	}

	@Override
	public void unload() {
		if (currentSong == 0) {
			return;
		}
		N_unload(currentSong);
		currentSong = 0;
	}

	@Override
	public int getSoundData(short[] dest) {
		return N_getSoundData(currentSong, dest, dest.length);
	}

	@Override
	public String[] getDetailedInfo() {
		if (currentSong == 0) {
			return null;
		}

		String [] details = new String [2];
		details[0] = "Format";
		details[1] = "UADE: " + N_getStringInfo(currentSong, INFO_TYPE);
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
	public boolean setTune(int tune) {
		if (currentSong == 0) {
			return false;
		}
		return N_setTune(currentSong, tune);
	}

	@Override
	public boolean seekTo( int msec) {
		if (currentSong == 0) {
			return false;
		}
		return N_seekTo(currentSong, msec);
	}

	@Override
	public void setOption(String o, Object val) {
		final int k;
		final int v;
		if (o.equals("filter")) {
			k = OPT_FILTER;
			v = (Boolean) val ? 1 : 0;
		} else if (o.equals("panning")) {
			k = OPT_PANNING;
			v = Integer.valueOf(((String) val).split(" ")[0]) / 25;
		} else if (o.equals("ntsc")) {
			k = OPT_NTSC;
			v = (Boolean) val ? 1 : 0;
		} else if (o.equals("resampling")) {
			k = OPT_RESAMPLING;
			v = (Integer) val;
		} else {
			throw new RuntimeException("Unknown option: " + o);
		}

		N_setOption(k, v);
	}

	@Override
	public String getVersion() {
		return "UADE 2.13";
	}

	/**
	 * Currently extracting info from AHX.
	 */
	@Override
	protected MusicInfo getMusicInfo(String name, byte[] module) {
		if (module.length < 3) {
			return null;
		}

		String header = new String(module, 0, 3, ISO88591);
		if (header.equals("AHX")) {
			MusicInfo info = new MusicInfo();
			int namePtr = ((module[4] & 0xff) << 8) | (module[5] & 0xff);
			if (namePtr <= module.length - 128) {
				info.title = new String(module, namePtr, 128, ISO88591);
				info.title = info.title.replaceFirst("\u0000.*", "");
				info.format = "AHX";
				return info;
			}

			return null;
		}

		return null;
	}

	native private static void N_init(String baseDir);
	native private static void N_exit();
	native private static void N_setOption(int what, int val);

	native private long N_load(byte [] module, int size);
	native private long N_loadFile(String name);
	native private void N_unload(long song);

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native private int N_getSoundData(long song, short [] dest, int size);
	native private boolean N_seekTo(long song, int seconds);
	native private boolean N_setTune(long song, int tune);
	native private String N_getStringInfo(long song, int what);
	native private int N_getIntInfo(long song, int what);
}
