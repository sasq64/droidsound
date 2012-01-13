package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.charset.Charset;

import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.utils.HashUtil;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.Unzipper;

public class VICEPlugin extends DroidSoundPlugin {
	private static final String TAG = VICEPlugin.class.getSimpleName();
	private static final Charset ISO88591 = Charset.forName("ISO-8859-1");

	static {
		System.loadLibrary("vice");

		/* Store basic, kernal & chargen for C++ code to find. */
		File pluginDir = Application.getPluginDataDirectory(VICEPlugin.class);
		File viceDir = new File(pluginDir, "VICE");
		if (! viceDir.exists()) {
			Unzipper.unzipAsset("vice.zip", pluginDir);
		}

		N_setDataDir(viceDir.getPath());
	}

	private static String fromData(byte[] module, int start, int len) {
		return new String(module, start, len, ISO88591).replaceFirst("\u0000.*", "");
	}

	protected static class Info {
		protected String name = "Unknown";
		protected String composer = "Unknown";
		protected String copyright = "Unknown";
		protected int videoMode = 0;
		protected int sidModel = 0;
		protected int startSong = 1;
		protected int songs = 1;
		protected String format;
	}

	private byte[] mainHash;
	private short[] extraLengths;
	private int hashLen;

	private final int songLengths[] = new int[256];
	private int currentTune;

	private Info songInfo;

	/**
	 * Load a song into memory.
	 *
	 * @param name Name of file to load
	 *
	 * @return an error string, or null if successful.
	 */
	native private static String N_loadFile(String name);

	/**
	 * Unload song from memory.
	 */
	native private static void N_unload();

	/**
	 * Generates audio.
	 * Produces stereo, 44.1Khz, signed, native-encoding shorts.
	 *
	 * @param dest the buffer to fill
	 */
	native private static int N_getSoundData(short[] dest, int size);

	/**
	 * Select a subsong.
	 */
	native private static boolean N_setTune(int tune);

	/**
	 * Set an option from the known #defines.
	 */
	native private static void N_setOption(int what, int val);

	/**
	 * Set the directory of VICE's basic, kernal and chargen files.
	 *
	 * @param path Where kernal, basic and chargen can be found.
	 */
	native private static void N_setDataDir(String path);

	@Override
	public void setOption(String opt, Object val) {
		/* These X.valueOf(String.valueOf(...)) are kinda fucked up.
		 * These are caused by android preferences giving us logically X-valued data in String form. */
		final int k, v;
		if (opt.equals("filter")) {
			k = OPT_FILTER;
			v = (Boolean) val ? 1 : 0;
		} else if (opt.equals("ntsc")) {
			k = OPT_NTSC;
			v = Boolean.valueOf(String.valueOf(val)) ? 1 : 0;
		} else if (opt.equals("resampling")) {
			k = OPT_RESAMPLING;
			v = Integer.valueOf(String.valueOf(val));
		} else if (opt.equals("filter_bias")) {
			k = OPT_FILTER_BIAS;
			v = Integer.valueOf(String.valueOf(val));
		} else if (opt.equals("sid_model")) {
			k = OPT_SID_MODEL;
			v = Integer.valueOf(String.valueOf(val));
		} else {
			throw new RuntimeException("Unknown option: " + opt);
		}

		N_setOption(k, v);
	}

	@Override
	public int getSoundData(short[] dest) {
		return N_getSoundData(dest, dest.length);
	}

	@Override
	public boolean seekTo(int seconds) {
		return false;
	}

	@Override
	public byte[] md5(byte[] module) {
		ByteBuffer src = ByteBuffer.wrap(module);
		src.order(ByteOrder.BIG_ENDIAN);

		final byte[] id = new byte[4];
		src.get(id);
		if (id[1] != 'S' && id[2] != 'I' && id[3] != 'D') {
			return null;
		}

		final int version = src.getShort() & 0xffff;
		src.position(0x8);
		final int loadAddress = src.getShort() & 0xffff;
		final int initAddress = src.getShort() & 0xffff;
		final int playAddress = src.getShort() & 0xffff;
		final int songs = src.getShort() & 0xffff;
		src.position(0x12);
		final int speedBits = src.getInt();
		final int flags;

		int moduleDataOffset;
		if (version == 1) {
			flags = 0;
			moduleDataOffset = 0x76;
		} else {
			src.position(0x76);
			flags = src.getShort() & 0xffff;
			moduleDataOffset = 0x7c;
		}
		if (loadAddress == 0) {
			moduleDataOffset += 2;
		}

		/* header is only partially included, maximum data length is < 64k, 256 for subsong speeds */
		ByteBuffer dest = ByteBuffer.allocate(65536 + 256);
		dest.order(ByteOrder.LITTLE_ENDIAN);

		Log.i(TAG, "md5 signature pieces: %x %04x %04x %d %d %d", moduleDataOffset, initAddress, playAddress, songs, version, (flags >> 2) & 0x3);
		dest.put(module, moduleDataOffset, module.length - moduleDataOffset);
		dest.putShort((short) initAddress);
		dest.putShort((short) playAddress);
		dest.putShort((short) songs);

		for (int i = 0; i < songs && i < 256; i ++) {
			int ibit = i < 32 ? i : 31;
			if (id[0] == 'R' || (speedBits & (1 << ibit)) != 0) {
				dest.put((byte) 60);
			} else {
				dest.put((byte) 0);
			}
		}

		/* sid clock flags == 2 -> write 2 */
		if (version != 1 && ((flags >> 2) & 0x3) == 2) {
			dest.put((byte) 2);
		}

		return HashUtil.md5(dest.array(), 0, dest.position());
	}

	@Override
	public boolean canHandle(String name) {
		String ext = name.substring(name.indexOf('.') + 1).toUpperCase();
		return ext.equals("SID") || ext.equals("PRG");
	}

	@Override
	public String[] getDetailedInfo() {
		final String sids[] = { "UNKNOWN", "6581", "8580", "6581 & 8580" };
		final String videoModes[] = { "UNKNOWN", "PAL", "NTSC", "PAL & NTSC" };
		return new String[] {
			"Format",
			songInfo.format,
			"Copyright",
			songInfo.copyright,
			"SID Model",
			sids[songInfo.sidModel],
			"Video Mode",
			videoModes[songInfo.videoMode],
		};
	}

	@Override
	public int getIntInfo(int what) {
		if (songInfo == null) {
			return 0;
		}

		if (what == INFO_LENGTH) {
			return songLengths[currentTune];
		}
		if (what == INFO_SUBTUNE_COUNT) {
			return songInfo.songs;
		}
		if (what == INFO_SUBTUNE_NO) {
			return currentTune;
		}
		if (what == INFO_STARTTUNE) {
			return songInfo.startSong;
		}

		return 0;
	}

	@Override
	public String getStringInfo(int what) {
		if (songInfo == null) {
			return null;
		}

		switch(what) {
		case INFO_AUTHOR:
			return songInfo.composer;
		case INFO_COPYRIGHT:
			return songInfo.copyright;
		case INFO_TITLE:
			return songInfo.name;
		default:
			return null;
		}
	}

	@Override
	protected boolean load(String name, byte[] module) {
		throw new RuntimeException("This method should not be called.");
	}

	@Override
	public boolean load(String f1, byte[] data1, String f2, byte[] data2) {
		if (data1.length < 128) {
			return false;
		}

		currentTune = 0;
		songInfo = null;

		boolean isPrg = false;
		String s = new String(data1, 0, 4, ISO88591);
		if ((s.equals("PSID") || s.equals("RSID"))) {
		} else if (f1.toLowerCase().endsWith(".prg") || (data1[0] == 0x01 && data1[1] == 0x08)) {
			isPrg = true;
			byte rsid[] = new byte[] {
					0x52, 0x53, 0x49, 0x44, 0x00, 0x02, 0x00, 0x7c,
					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
					0x00, 0x01, 0x00, 0x00, 0x00, 0x00
			};

			byte[] oldm = data1;
			data1 = new byte[oldm.length + 0x7c];
			System.arraycopy(rsid, 0, data1, 0, rsid.length);
			data1[0x77] = 2;
			System.arraycopy(oldm, 0, data1, 0x7c, oldm.length);
		} else {
			return false;
		}

		songInfo = new Info();
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

		String error = N_loadFile(new File(tmpDir, f1).getPath());
		if (error != null) {
			Log.w(TAG, "Unable to load file: %s", error);
			return false;
		}

		if (isPrg) {
			songInfo.name = f1;
			songInfo.format = "PRG";
			return true;
		}

		songInfo.format = s;

		songInfo.name = new String(data1, 0x16, 0x20, ISO88591).replaceFirst("\0.*", "");
		songInfo.composer = new String(data1, 0x36, 0x20, ISO88591).replaceFirst("\0.*", "");
		songInfo.copyright = new String(data1, 0x56, 0x20, ISO88591).replaceFirst("\0.*", "");

		songInfo.videoMode = (data1[0x77] >> 2) & 3;
		songInfo.sidModel = (data1[0x77] >> 4) & 3;
		songInfo.songs = ((data1[0xe] << 8) & 0xff00) | (data1[0xf] & 0xff);
		songInfo.startSong = ((data1[0x10] << 8) & 0xff00) | (data1[0x11] & 0xff) - 1;

		currentTune = songInfo.startSong;
		return true;
	}

	@Override
	public boolean setTune(int tune) {
		boolean rc = N_setTune(tune + 1);
		if (rc) {
			currentTune = tune;
		}

		return rc;
	}

	@Override
	public void unload() {
		songInfo = null;
		N_unload();
	}

	@Override
	protected MusicInfo getMusicInfo(String name, byte[] module) {
		String magic = new String(module, 1, 3, ISO88591);
		if (magic.equals("SID")) {
			MusicInfo info = new MusicInfo();
			info.title = fromData(module, 0x16, 32);
			info.composer = fromData(module, 0x36, 32);
			info.copyright = fromData(module, 0x56, 32);
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
		}

		return null;
	}

	@Override
	public String getVersion() {
		return "VICEPlugin (vsid r25078)";
	}
}
