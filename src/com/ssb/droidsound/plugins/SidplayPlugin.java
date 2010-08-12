package com.ssb.droidsound.plugins;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import android.content.Context;
import android.util.Log;

public class SidplayPlugin extends DroidSoundPlugin {

	private static final String TAG = SidplayPlugin.class.getSimpleName();


	static {
		System.loadLibrary("sidplay2");
	}
	
	private static class Info {
		String name;
		String composer;
		String copyright;
	};
	
	final byte [] header = new byte [128];
	private Context context;
	private byte[] lenData;

	public SidplayPlugin() {
	}
	
	public SidplayPlugin(Context ctx) {
		context = ctx;
	}

	@Override
	public boolean canHandle(String name) { 
		//return N_canHandle(name);
		return name.toLowerCase().endsWith(".sid");
	}

	@Override
	public void unload(Object song) {
		if(song instanceof Info) {
			return;
		}
		N_unload((Long)song);
	}
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	@Override
	public int getSoundData(Object song, short [] dest, int size) { return N_getSoundData((Long)song, dest, size); }	
	@Override
	public boolean seekTo(Object song, int seconds) { return N_seekTo((Long)song, seconds); }
	@Override
	public boolean setTune(Object song, int tune) { return N_setTune((Long)song, tune); }
	@Override
	public int getIntInfo(Object song, int what) {
		if(song instanceof Info) {
			return 0;
		}
		return N_getIntInfo((Long)song, what);
	}

	native public long N_load(byte [] module, int size);
	native public void N_unload(long song);
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native public int N_getSoundData(long song, short [] dest, int size);
	native public boolean N_seekTo(long song, int seconds);
	native public boolean N_setTune(long song, int tune);
	native public String N_getStringInfo(long song, int what);
	native public int N_getIntInfo(long song, int what);

	
	
	@Override
	public Object load(byte [] module, int size) {
		long rc = N_load(module, size);
		
		
		if(context != null) {		
			if(lenData == null) {
				try {
					InputStream is = context.getAssets().open("songlengths.dat");
					if(is != null) {
						
						DataInputStream dis = new DataInputStream(is);
						int count = dis.readInt();
						
						
						
						lenData = new byte [is.available()];		
						is.read(lenData);
					}
				} catch (IOException e) {
				}
			}
		}
		
		findMD5(module, size);
		
		return rc != 0 ? rc : null; 
	}

	@Override
	public String getStringInfo(Object song, int what) {
		if(song instanceof Info) {
			Info info = (Info)song;
			switch(what) {
			case INFO_AUTHOR:
				return info.composer;
			case INFO_COPYRIGHT:
				return info.copyright;
			case INFO_TITLE:
				return info.name;
			}
			return null;
		}
		return N_getStringInfo((Long)song, what);
	}
	
	@Override
	public String[] getDetailedInfo(Object song) {

		final String sids [] = { "UNKNOWN", "6581", "8580", "6581 & 8580" };
		
		String[] info = new String [4];
		info[0] = "Copyright";
		info[1] = N_getStringInfo((Long)song, INFO_COPYRIGHT);
		int m = N_getIntInfo((Long)song, 101);
		Log.v(TAG, "Sid model " + m);
		if(m <= 3 && m >= 0) {
			info[2] = "SID Model";
			info[3] = sids[m];
		}
		return info;
	}
	
	/* 					if(currentSongInfo.md5 != null) {					
						final String HEX = "0123456789abcdef";
						
						StringBuilder sb = new StringBuilder(16);
						for(int i=0; i<16; i++) {
							byte x = currentSongInfo.md5[i];
							sb.append(HEX.charAt((x>>4)&0xf)).append(HEX.charAt(x&0xf));
						}
						
						info[SONG_MD5] = sb.toString();
						Log.v(TAG, "MD5: " + info[SONG_MD5]);

					} else {
						Log.v(TAG, "No MD5!");
					}

	 */
	private void findMD5(byte[] module, int size) {

		ByteBuffer src = ByteBuffer.wrap(module, 0, size);		
		src.order(ByteOrder.BIG_ENDIAN);
		
		src.position(4);
		int version = src.getShort();
		src.position(8);
		short loadAdress = src.getShort();
		short initAdress = src.getShort();
		short playAdress = src.getShort();
		short songs = src.getShort();
		short startSong = src.getShort();
		int speed = src.getInt();
		
		int offset = 120;
		if(version == 2) {
			offset = 126;
		}
		
		Log.v(TAG, String.format("speed %08x, left %d songs %d init %x", speed, size - offset, songs, initAdress));
		
		byte[] md5 = null;
		
		try {
			MessageDigest md = MessageDigest.getInstance("MD5");
			
			md.update(module, offset, size - offset);
			
			ByteBuffer dest = ByteBuffer.allocate(6 + songs);
			dest.order(ByteOrder.LITTLE_ENDIAN);
			
			dest.putShort(initAdress);
			dest.putShort(playAdress);
			dest.putShort(songs);
			
			for(int i=0; i<songs; i++) {
				if((speed & (1<<i)) != 0) {
					dest.put((byte)0);
				} else {
					dest.put((byte)60);
				}
			}
			byte [] d = dest.array();
			md.update(d);
			
			md5 = md.digest();
			Log.v(TAG, String.format("%d %02x %02x DIGEST %02x %02x %02x %02x", d.length, d[0], d[1], md5[0], md5[1], md5[2], md5[3])); 
			
		} catch (NoSuchAlgorithmException e) {
			e.printStackTrace();
		}

	}


	@Override
	public Object loadInfo(InputStream is, int size) throws IOException {
		
		Info info = new Info();
		
		is.read(header);
		
		String s = new String(header, 0, 4);
		if(!(s.equals("PSID") || s.equals("RSID"))) {
			return null;
		}

		int o = 0x35;
		while(o >= 0x16 && header[o] == 0) {
			o -= 1;
		}
		info.name = new String(header, 0x16, o-0x15, "ISO-8859-1");

		o = 0x55;
		while(o >= 0x36 && header[o] == 0) {
			o -= 1;
		}
		info.composer = new String(header, 0x36, o-0x35, "ISO-8859-1");

		o = 0x75;
		while(o >= 0x56 && header[o] == 0) {
			o -= 1;
		}
		info.copyright = new String(header, 0x56, o-0x55, "ISO-8859-1");

		return info;	
	}
	
	@Override
	public boolean isSilent(Object song) {
		
		return (N_getIntInfo((Long)song, 100) != 0);
	}
	

	@Override
	public Object load(File file) throws IOException {
		
		//if(loadInfo(file) == null) {
		//	return null;
		//}
		
		int l = (int)file.length();
		byte [] songBuffer = new byte [l];
		FileInputStream fs = new FileInputStream(file);
		fs.read(songBuffer);
		fs.close();

		long rc = N_load(songBuffer, l);		
		return rc != 0 ? rc : null; 
	}
}
