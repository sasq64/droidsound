package com.ssb.droidsound.plugins;

import java.io.DataInputStream;
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
	//private byte[] lenData;
	private byte[] mainHash;
	private short[] extraLengths;
	private int hashLen;
	
	
	private int songLengths[] = new int [256];
	private int currentTune;

	private long currentSong = 0;
	
	static class Option {
		String name;
		String description;
		Object defaultValue;
	}
	
	private Info songInfo;
	private static boolean isActive = true;	
	
	static String [] options = new String [] { "filter", "ntsc", "panning" };
	static int [] optvals = new int [] { OPT_FILTER, OPT_NTSC, OPT_PANNING };

	@Override
	public void setOption(String opt, Object val) {
		int v  = -1;
		if (opt.equals("active")) {
			Log.v(TAG, ">>>>>>>>>> SIDPLAYPLUGIN IS " + (isActive ? "ACTIVE" : "NOT ACTIVE"));
			isActive = (Boolean)val;
			return;
		} else
		if(val instanceof Boolean) {
			v = (Boolean)val ? 1 : 0;
		} else
		if(val instanceof Integer) {
			v = (Integer)val;
		}
		
		for(int i=0; i<options.length; i++) {
			if(options[i].equals(opt)) {
				N_setOption(optvals[i], v);
				break;
			}
		}
		
	}
	
	
	@Override
	public boolean canHandle(String name) { 
		//return N_canHandle(name);
		if(!isActive) return false;
		return name.toLowerCase().endsWith(".sid") || name.toLowerCase().endsWith(".prg");
	}

	@Override
	public void unload() {
		songInfo = null;
		if(currentSong <= 0) {
			return;
		}
		N_unload(currentSong);
		currentSong = 0;
	}
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	@Override
	public int getSoundData(short [] dest, int size) { return N_getSoundData(currentSong, dest, size); }	
	@Override
	public boolean seekTo(int seconds) { return N_seekTo(currentSong, seconds); }
	@Override
	public boolean setTune(int tune) {
		boolean ok = N_setTune(currentSong, tune);
		if(ok) {
			currentTune = tune;
		}
		return ok;
	}
	@Override
	public int getIntInfo(int what) {
		if(currentSong <= 0) {
			return 0;
		}
		
		if(what == INFO_LENGTH) {
			return songLengths[currentTune];
		}
		
		return N_getIntInfo(currentSong, what);
	}

	native public long N_load(byte [] module, int size);
	native public void N_unload(long song);
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native public int N_getSoundData(long song, short [] dest, int size);
	native public boolean N_seekTo(long song, int seconds);
	native public boolean N_setTune(long song, int tune);
	native public String N_getStringInfo(long song, int what);
	native public int N_getIntInfo(long song, int what);

	native public static void N_setOption(int what, int val);
	
	
	/*

00000000  52 53 49 44 00 02 00 7c  00 00 76 00 00 00 00 01  |RSID...|..v.....|
00000010  00 01 00 00 00 00 


53 61  76 61 67 65 00 00 00 00  |......Savage....|
00000020  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00000030  00 00 00 00 00 00 4a 65  72 6f 65 6e 20 54 65 6c  |......Jeroen Tel|
00000040  20 2f 20 4d 61 6e 69 61  63 73 20 6f 66 20 4e 6f  | / Maniacs of No|
00000050  69 73 65 00 00 00 31 39  38 38 20 46 69 72 65 62  |ise...1988 Fireb|
00000060  69 72 64 00 00 00 00 00  00 00 00 00 00 00 00 00  |ird.............|
00000070  00 00 00 00 00 00 
00000076  00 01 <- Unknown, Basic
00000078  8e 12 00 00 
9c 0f 78 a9  |..............x.|

	 */
	
	byte rsid[] = new byte [] {
	0x52, 0x53, 0x49, 0x44, 0x00, 0x02, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
	0x00, 0x01, 0x00, 0x00, 0x00, 0x00 }; 

	public static void hexdump(byte [] data) {
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<data.length; i++) {
			if(i % 8 == 0) {
				sb.append(String.format("\n%04x:  ", i));
			}
			sb.append(String.format("%02x ", data[i]));
		}
		Log.v(TAG, sb.toString());
	}
	
	@Override
	public boolean load(String name, byte [] module, int size) {
		if(!isActive) return false;
	
		currentTune = 0;
		songInfo = null;
		int type = -1;
		
		String s = new String(module, 0, 4);
		if((s.equals("PSID") || s.equals("RSID"))) {
			type = 0;
		} else
		if(name.toLowerCase().endsWith(".prg")) {
			type = 1;
		} else if(module[0] == 0x01 && module[1] == 0x08) {
			type = 1;
		}
		
		if(type < 0)
			return false;

		if(type == 1) {
			byte [] oldm = module;
			module = new byte [oldm.length + 0x7c];
			System.arraycopy(rsid, 0, module, 0, rsid.length);
			
			//module[0x16] = 'A';
			//module[0x36] = 'B';
			//module[0x56] = 'C';

			//module[0x76] = 0;
			module[0x77] = 2;
			//module[0x78] = 0;
			//module[0x79] = 0;
			//module[0x7a] = 0;
			//module[0x7b] = 0;
			System.arraycopy(oldm, 0, module, 0x7c, oldm.length);
			size += 0x7c;
			
			songInfo = new Info();
			songInfo.name = getBaseName(name);
			
			//hexdump(module);
		}
		
		currentSong = N_load(module, size);
		
		if(currentSong == 0) {
			return false;
		}

		currentTune = N_getIntInfo(currentSong, DroidSoundPlugin.INFO_STARTTUNE);
		
		for(int i=0; i<256; i++) {
			songLengths[i] = 60*60*1000;
		}
		
		Context context = getContext();
		if(context != null) {		
			if(mainHash == null) {
				try {
					InputStream is = context.getAssets().open("songlengths.dat");
					if(is != null) {						
						DataInputStream dis = new DataInputStream(is);
						hashLen = dis.readInt();
						mainHash = new byte [hashLen * 6];
						dis.read(mainHash);
						int l = is.available()/2;
						Log.v(TAG, String.format("We have %d lengths and %d hashes", l, hashLen));
						extraLengths = new short [l];
						for(int i=0; i<l; i++) {
							extraLengths[i] = dis.readShort();
						}
						is.close();
						
					}
				} catch (IOException e) {
				}
			}
		}
		
		if(mainHash != null) {		
			byte [] md5 = findMD5(module, size);
			int first = 0;
			int upto = hashLen;
			
			int found = -1;
			
			long key = ((md5[0]&0xff) << 24) | ((md5[1]&0xff) << 16) | ((md5[2]&0xff) << 8) | (md5[3] & 0xff);
			key &= 0xffffffffL;
			
			//short lens [] = new short [128];
			
	    	Log.v(TAG, String.format("MD5 %08x", key));
			while (first < upto) {
		        int mid = (first + upto) / 2;  // Compute mid point.
	    		long hash = ((mainHash[mid*6]&0xff) << 24) | ((mainHash[mid*6+1]&0xff) << 16) | ((mainHash[mid*6+2]&0xff) << 8) | (mainHash[mid*6+3] & 0xff);
	    		hash &= 0xffffffffL;
	
	        	//Log.v(TAG, String.format("offs %x, hash %08x", mid, hash));
		        if (key < hash) {
		            upto = mid;     // repeat search in bottom half.
		        } else if (key > hash) {
		            first = mid + 1;  // Repeat search in top half.
		        } else {
		        	found = mid;
		        	int len = ((mainHash[mid*6+4]&0xff)<<8) | (mainHash[mid*6+5]&0xff);
	    			Log.v(TAG, String.format("LEN: %x", len));
		        	if((len & 0x8000) != 0) {
		        		len &= 0x7fff;
		        		int xl = 0;
		        		int n = 0;
		        		while((xl & 0x8000) == 0) {
		        			xl = extraLengths[len++] & 0xffff;
		        			songLengths[n++] = (xl & 0x7fff) * 1000;
		        		}
		        		
		        		//for(int i=0; i<n; i++) {
		        		//	Log.v(TAG, String.format("LEN: %02d:%02d", songLengths[i]/60, songLengths[i]%60));
		        		//}
		        	} else {
		        		Log.v(TAG, String.format("SINGLE LEN: %02d:%02d", len/60, len%60));
		        		songLengths[0] = (len * 1000);
		        	}
		        	break;
		        }
		    }
			
			Log.v(TAG, String.format("Found md5 at offset %d", found));
		}		
		return true; 
	}

	@Override
	public String getStringInfo(int what) {
		if(songInfo != null) {
			switch(what) {
			case INFO_AUTHOR:
				return songInfo.composer;
			case INFO_COPYRIGHT:
				return songInfo.copyright;
			case INFO_TITLE:
				return songInfo.name;
			}
			return null;
		}
		return N_getStringInfo(currentSong, what);
	}
	
	@Override
	public String[] getDetailedInfo() {

		final String sids [] = { "UNKNOWN", "6581", "8580", "6581 & 8580" };
		
		String[] info = new String [4];
		info[0] = "Copyright";
		info[1] = N_getStringInfo(currentSong, INFO_COPYRIGHT);
		int m = N_getIntInfo(currentSong, 101);
		Log.v(TAG, "Sid model " + m);
		if(m <= 3 && m >= 0) {
			info[2] = "SID Model";
			info[3] = sids[m];
		}
		return info;
	}

	private byte [] findMD5(byte[] module, int size) {

		ByteBuffer src = ByteBuffer.wrap(module, 0, size);		
		src.order(ByteOrder.BIG_ENDIAN);
		
		byte [] id = new byte [4];
		src.get(id);
		int version = src.getShort();
		src.position(8);
		short loadAdress = src.getShort();
		short initAdress = src.getShort();
		short playAdress = src.getShort();
		short songs = src.getShort();
		short startSong = src.getShort();
		int speedBits = src.getInt();
		src.position(0x76);
		int flags = src.getShort();
		
		int offset = 120;
		if(version == 2) {
			offset = 126;
		}
		
		int speed = 0;
		if(id[0] == 'R') {
			speed = 60;
		}
		
		Log.v(TAG, String.format("speed %08x, flags %04x left %d songs %d init %x", speed, flags, size - offset, songs, initAdress));
		
		byte[] md5 = null;
		
		try {
			MessageDigest md = MessageDigest.getInstance("MD5");
			
			md.update(module, offset, size - offset);
			
			ByteBuffer dest = ByteBuffer.allocate(128);
			dest.order(ByteOrder.LITTLE_ENDIAN);
			
			dest.putShort(initAdress);
			dest.putShort(playAdress);
			dest.putShort(songs);
			
			for(int i=0; i<songs; i++) {
				if((speedBits & (1<<i)) != 0) {
					dest.put((byte)60);
				} else {
					dest.put((byte)speed);
				}
			}
			
			if((flags & 0x8) != 0) {
				dest.put((byte)2);
			}

			byte [] d = dest.array();
			md.update(d, 0, dest.position());
			
			md5 = md.digest();
			Log.v(TAG, String.format("%d %02x %02x DIGEST %02x %02x %02x %02x", d.length, d[0], d[1], md5[0], md5[1], md5[2], md5[3]));
			return md5;
			
		} catch (NoSuchAlgorithmException e) {
			e.printStackTrace();
		}
		return null;
	}


	@Override
	public boolean loadInfo(String name, InputStream is, int size) throws IOException {
		
		songInfo = new Info();
		Info info = songInfo;
		
		if(name.toLowerCase().endsWith(".prg")) {
			info.name = name;
			info.composer = "Unknown";
			Log.v(TAG, "######################## PRG LOAD OK");
			return true;
		}
		
		
		is.read(header);
		
		String s = new String(header, 0, 4);
		if(!(s.equals("PSID") || s.equals("RSID"))) {
			return false;
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

		return true;	
	}
	
	@Override
	public boolean isSilent() {
		
		return (N_getIntInfo(currentSong, 100) != 0);
	}
	
	@Override
	public String getVersion() {
		return "libsidplay 2.1.1+20060528.ccr";
	}
	
/*
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
	} */
}
