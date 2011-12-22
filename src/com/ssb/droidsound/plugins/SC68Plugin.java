package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.UnsupportedEncodingException;

import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.Unzipper;

public class SC68Plugin extends DroidSoundPlugin {
	private static final String TAG = SC68Plugin.class.getSimpleName();
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
	private final Unzipper unzipper = null;

	@Override
	public boolean canHandle(String name) {
		String ext = name.substring(name.indexOf('.')+1).toLowerCase();
		return(ext.equals("sndh") || ext.equals("sc68") || ext.equals("snd"));
	}

	@Override
	public void unload() {
		Log.d(TAG, "Unloading");
		if(currentSong != 0)
			N_unload(currentSong);
	}

	@Override
	public boolean load(String name, byte[] module) {
		currentSong = N_load(module, module.length);
		return currentSong != 0;
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

	private static final String [] hws = { "?", "YM", "STE", "YM+STE", "Amiga", "Amiga+YM", "Amiga+STE", "Amiga++" };

	@Override
	public String[] getDetailedInfo() {

		String [] info = new String [4];

		String replay = getStringInfo(52);
		String hwname = getStringInfo(51);
		int hwbits = getIntInfo(50);
		if(replay == null) replay = "?";
		if(hwname == null) hwname = "?";

		info[0] = "Format";
		info[1] = String.format("SC68: %s", replay);
		info[2] = "Hardware";
		info[3] = String.format("%s (%s)", hwname, hws[hwbits]);
		return info;
	}

	@Override
	public boolean loadInfo(String name, byte[] data) {
		currentSong = 0;
		title = null;
		composer = null;
		year = null;
		type = null;

		int size = data.length;
		String head = new String(data, 0, 4);
		if (head.equals("ICE!")) {
			/* FIXME: Now this is utter crap... 1M is enough for everybody??? */
			byte[] targetBuffer = new byte[1024*1024];
			int rc = N_unice(data, targetBuffer);
			if (rc < 0)
				return false;
			size = rc;
			data = targetBuffer;
		}

		String header = new String(data, 12, 4);
		String header2 = new String(data, 0, 16);
		if(header.equals("SNDH")) {
			Log.d(TAG, "Found SNDH");
			type = "SNDH";
			int offset = 16;

			while (offset < 1024) {
				String tag = new String(data, offset, 4);
				//Log.d(TAG, "TAG: %s", tag);
				try {
					if(tag.equals("TITL")) {
						title = fromData(data, offset+4, 64);
						Log.d(TAG, "TITLE: %s", title);
						offset += (4+title.length());
					} else if(tag.equals("COMM")) {
						composer = fromData(data, offset+4, 64);
						offset += (4+composer.length());
					} else if(tag.equals("YEAR")) {
						year = fromData(data, offset+4, 32);
						offset += (4+year.length());
					} else if(tag.equals("HDNS")) {
						Log.d(TAG, "END");
						break;
					} else {
						while(data[offset] != 0) offset++;
					}
				} catch (UnsupportedEncodingException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				while(data[offset] == 0) offset++;
			}

			return true;
		} else if(header2.equals("SC68 Music-file ")) {
			int offset = 56;
			type = "SC68";
			while(offset < 1024) {
				String tag = new String(data, offset, 4);
				int tsize = data[offset+4] | (data[offset+5]<<8) | (data[offset+6]<<16) | (data[offset+7]<<24);
				offset += 8;
				Log.d(TAG, "TAG: %s, size %d", tag, tsize);
				if(tsize < 0 || tsize > size) {
					break;
				}
				try {
					if(tag.equals("SCMN")) {
						title = fromData(data, offset, tsize);
						Log.d(TAG, "TITLE: %s", title);
					} else if(tag.equals("SCFN")) {
						if(title != null) {
							title = fromData(data, offset, tsize);
							Log.d(TAG, "TITLE: %s", title);
						}
					} else if(tag.equals("SCAN")) {
						composer = fromData(data, offset, tsize);
					} else if(tag.equals("SC68")) {
						tsize = 0;
					} else if(tag.equals("SCEF") || tag.equals("SCDA")) {
						Log.d(TAG, "END");
						break;
					} else {
					}
				} catch (UnsupportedEncodingException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				offset += tsize;
			}

			return true;


		}

		return false;
	}


	@Override
	public int getSoundData(short[] dest, int size) {
		return N_getSoundData(currentSong, dest, size);
	}

	@Override
	public String getStringInfo(int what) {
		if(currentSong == 0) {
			switch(what) {
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
		if(currentSong == 0) {
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

	native private long N_load(byte [] module, int size);
	native private long N_loadInfo(byte [] module, int size);
	native private void N_unload(long song);

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native private int N_getSoundData(long song, short [] dest, int size);
	native private boolean N_seekTo(long song, int seconds);
	native private boolean N_setTune(long song, int tune);
	native private String N_getStringInfo(long song, int what);
	native private int N_getIntInfo(long song, int what);

	native private int N_unice(byte [] data, byte [] target);
}
