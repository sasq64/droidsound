package com.ssb.droidsound.plugins;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.charset.Charset;

import android.content.Context;
import android.os.Environment;

import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.Unzipper;

public class VICEPlugin extends DroidSoundPlugin {
	private static final String TAG = VICEPlugin.class.getSimpleName();
	private static final Charset ISO88591 = Charset.forName("ISO-8859-1");

	private static class Info {
		protected String name = "Unknown";
		protected String composer = "Unknown";
		protected String copyright = "Unknown";
		protected int videoMode = 0;
		protected int sidModel = 0;
		protected int startSong = 1;
		protected int songs = 1;
		protected String format;
	};

	private static final Object LOCK = new Object();
	private final byte[] header = new byte[128];
	private byte[] mainHash;
	private short[] extraLengths;
	private int hashLen;

	private final int songLengths[] = new int[256];
	private int currentTune;

	protected static class Option {
		protected String name;
		protected String description;
		protected Object defaultValue;
	}

	private Info songInfo;

	private static boolean libraryLoaded = false;


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

	private static boolean isActive = false;

	private static boolean initialized = false;

	public VICEPlugin() {
		synchronized (LOCK) {
			if (! initialized) {
				/* Store basic, kernal & chargen for C++ code to find. */
				File dataDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
				if (!dataDir.exists()) {
					dataDir.mkdir();
				}

				File viceDir = new File(dataDir, "VICE");
				if (! viceDir.exists()) {
					Unzipper.unzipAsset(getContext(), "vice.zip", dataDir);
				}

				System.loadLibrary("vice");
				N_setDataDir(new File(dataDir, "VICE").getAbsolutePath());

				initialized = true;
			}
		}
	}

	@Override
	public void setOption(String opt, String val) {
		final int k, v;
		if (opt.equals("filter")) {
			k = OPT_FILTER;
			v = Boolean.valueOf(val) ? 1 : 0;
		} else if (opt.equals("ntsc")) {
			k = OPT_NTSC;
			v = Integer.valueOf(val);
		} else if (opt.equals("resampling")) {
			k = OPT_RESAMPLING;
			v = Integer.valueOf(val);
		} else if (opt.equals("filter_bias")) {
			k = OPT_FILTER_BIAS;
			v = Integer.valueOf(val);
		} else if (opt.equals("sid_model")) {
			k = OPT_SID_MODEL;
			v = Integer.valueOf(val);
		} else {
			throw new RuntimeException("Unknown option: " + opt);
		}

		N_setOption(k, v);
	}

	@Override
	public int getSoundData(short[] dest, int size) {
		return N_getSoundData(dest, size);
	}

	@Override
	public boolean seekTo(int seconds) {
		return false;
	}

	private boolean nativeLoad(String name, byte [] module, int size) {
		final String error;
		try {
			File file = File.createTempFile("tmp-XXXXX", "sid");
			FileOutputStream fo = new FileOutputStream(file);
			fo.write(module);
			fo.close();
			error = N_loadFile(file.getAbsolutePath());
			file.delete();
		}
		catch (IOException ie) {
			throw new RuntimeException(ie);
		}

		if (error != null) {
			Log.i(TAG, "Native code error: " + error);
			return false;
		}

		return true;
	}

	private byte[] calculateMD5(byte[] module) {
		ByteBuffer src = ByteBuffer.wrap(module);
		src.order(ByteOrder.BIG_ENDIAN);

		byte[] id = new byte[4];
		src.get(id);
		int version = src.getShort();
		src.position(8);
		short initAdress = src.getShort();
		short playAdress = src.getShort();
		short songs = src.getShort();
		int speedBits = src.getInt();
		src.position(0x76);
		int flags = src.getShort();

		int offset = 120;
		if (version == 2) {
			offset = 126;
		}

		int speed = 0;
		if (id[0] == 'R') {
			speed = 60;
		}

		ByteBuffer dest = ByteBuffer.allocate(65536 + 128);
		dest.order(ByteOrder.LITTLE_ENDIAN);

		dest.put(module, offset, module.length - offset);
		dest.putShort(initAdress);
		dest.putShort(playAdress);
		dest.putShort(songs);

		for (int i = 0; i < songs; i ++) {
			if ((speedBits & (1 << i)) != 0) {
				dest.put((byte) 60);
			} else {
				dest.put((byte) speed);
			}
		}

		if ((flags & 0x8) != 0) {
			dest.put((byte) 2);
		}

		return calcMD5(ByteBuffer.wrap(dest.array(), 0, dest.position()).array());
	}

	private void findLength(byte[] module) {
		for (int i = 0; i < 256; i++) {
			songLengths[i] = 60*60*1000;
		}

		Context context = getContext();
		if (mainHash == null) {
			try {
				InputStream is = context.getAssets().open("songlengths.dat");
				if(is != null) {
					DataInputStream dis = new DataInputStream(is);
					hashLen = dis.readInt();
					mainHash = new byte [hashLen * 6];
					dis.read(mainHash);
					int l = is.available()/2;
					Log.d(TAG, "We have %d lengths and %d hashes", l, hashLen);
					extraLengths = new short [l];
					for(int i=0; i<l; i++) {
						extraLengths[i] = dis.readShort();
					}
					is.close();

				}
			} catch (IOException e) {
			}
		}

		if (mainHash != null) {
			byte[] md5 = calculateMD5(module);
			int first = 0;
			int upto = hashLen;

			int found = -1;

			long key = ((md5[0]&0xff) << 24) | ((md5[1]&0xff) << 16) | ((md5[2]&0xff) << 8) | (md5[3] & 0xff);
			key &= 0xffffffffL;

			//short lens [] = new short [128];

	    	Log.d(TAG, "MD5 %08x", key);
			while (first < upto) {
		        int mid = (first + upto) / 2;  // Compute mid point.
	    		long hash = ((mainHash[mid*6]&0xff) << 24) | ((mainHash[mid*6+1]&0xff) << 16) | ((mainHash[mid*6+2]&0xff) << 8) | (mainHash[mid*6+3] & 0xff);
	    		hash &= 0xffffffffL;

	        	//Log.d(TAG, "offs %x, hash %08x", mid, hash);
		        if (key < hash) {
		            upto = mid;     // repeat search in bottom half.
		        } else if (key > hash) {
		            first = mid + 1;  // Repeat search in top half.
		        } else {
		        	found = mid;
		        	int len = ((mainHash[mid*6+4]&0xff)<<8) | (mainHash[mid*6+5]&0xff);
	    			Log.d(TAG, "LEN: %x", len);
		        	if((len & 0x8000) != 0) {
		        		len &= 0x7fff;
		        		int xl = 0;
		        		int n = 0;
		        		while((xl & 0x8000) == 0) {
		        			xl = extraLengths[len++] & 0xffff;
		        			songLengths[n++] = (xl & 0x7fff) * 1000;
		        		}

		        		//for(int i=0; i<n; i++) {
		        		//	Log.d(TAG, "LEN: %02d:%02d", songLengths[i]/60, songLengths[i]%60);
		        		//}
		        	} else {
		        		Log.d(TAG, "SINGLE LEN: %02d:%02d", len/60, len%60);
		        		songLengths[0] = (len * 1000);
		        	}
		        	break;
		        }
		    }

			Log.d(TAG, "Found md5 at offset %d", found);
		}
	}

	@Override
	public boolean loadInfo(String name, byte[] header) {
		songInfo = new Info();
		if (name.toLowerCase().endsWith(".prg")) {
			songInfo.name = name;
			songInfo.format = "PRG";
			return true;
		}

		String s = new String(header, 0, 4, ISO88591);
		if (! (s.equals("PSID") || s.equals("RSID"))) {
			return false;
		}

		songInfo.format = s;

		songInfo.name = new String(header, 0x16, 0x20, ISO88591).replaceAll("\0", "");
		songInfo.composer = new String(header, 0x36, 0x20, ISO88591).replaceAll("\0", "");
		songInfo.copyright = new String(header, 0x56, 0x20, ISO88591).replaceAll("\0", "");

		songInfo.videoMode = (header[0x77] >> 2) & 3;
		songInfo.sidModel = (header[0x77] >> 4) & 3;
		songInfo.songs = ((header[0xe] << 8) & 0xff00) | (header[0xf] & 0xff);
		songInfo.startSong = ((header[0x10] << 8) & 0xff00) | (header[0x11] & 0xff) - 1;

		Log.i(TAG, "startSong=" + songInfo.startSong + ", songs=" + songInfo.songs);

		return true;
	}

	@Override
	public boolean canHandleExt(String ext) {
		return ext.equals(".SID") || ext.equals(".PRG") || ext.equals(".PSID");
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
	public boolean load(String name, byte[] module) {
		currentTune = 0;
		songInfo = null;
		int type = -1;

		String s = new String(module, 0, 4, ISO88591);
		if ((s.equals("PSID") || s.equals("RSID"))) {
			type = 0;
		} else
		if (name.toLowerCase().endsWith(".prg")) {
			type = 1;
		} else if (module[0] == 0x01 && module[1] == 0x08) {
			type = 1;
		}

		if (type < 0) {
			return false;
		}
		if (type == 1) {
			byte rsid[] = new byte [] {
					0x52, 0x53, 0x49, 0x44, 0x00, 0x02, 0x00, 0x7c,
					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
					0x00, 0x01, 0x00, 0x00, 0x00, 0x00
			};

			byte[] oldm = module;
			module = new byte [oldm.length + 0x7c];
			System.arraycopy(rsid, 0, module, 0, rsid.length);

			module[0x77] = 2;

			System.arraycopy(oldm, 0, module, 0x7c, oldm.length);
		}

		loadInfo(name, module);
		currentTune = songInfo.startSong;

		boolean rc =  nativeLoad(name, module, module.length);
		if (rc) {
			findLength(module);
		}

		return rc;

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
	public String getVersion() {
		return "VICEPlugin\n";
	}
}
