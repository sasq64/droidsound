package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class SexyPSFPlugin extends DroidSoundPlugin {

	static {
		System.loadLibrary("sexypsf");
	}

	
	private long songFile = 0;
	
	private String [] info = null;
	

	@Override
	public boolean canHandleExt(String ext) {
		return ext.equals(".PSF") || ext.equals(".MINIPSF");
	}
	
	@Override
	public String[] getDetailedInfo() {
		String[] info = new String[6];
		info[0] = "Format";
		info[1] = "PSF (Playstation1)";
		info[2] = "Game";
		info[3] = getStringInfo(INFO_GAME);
		info[4] = "Copyright";
		info[5] = getStringInfo(INFO_COPYRIGHT);
		return info;
	}
	
	@Override
	public void unload() {
		if(songFile != 0)
			N_unload(songFile);
		else if(info != null)
			info = null;
	}

	@Override
	public boolean load(String name, byte[] module, int size) {
		return false;//loadTempFile(name, module, size);
	}
	
	@Override
	public boolean load(File file) throws IOException {		
		songFile = N_load(file.getPath());
		return true;
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

	
	@Override
	public boolean loadInfo(String name, byte [] module, int size) {
		
		ByteBuffer src = ByteBuffer.wrap(module, 0, size);		
		src.order(ByteOrder.LITTLE_ENDIAN);		
		byte[] id = new byte[4];
		src.get(id);
		
		//for(int i=0; i<128; i++)
		//	info[i] = null;
		
		 info = new String [128];
		
		if(id[0] == 'P' && id[1] == 'S' && id[2] == 'F' && id[3] == 1) {
			
			
			int resLen = src.getInt();
			int comprLen = src.getInt();
			int crc = src.getInt();
			src.position(resLen + comprLen + 16);
			
			if(src.remaining() >= 5) {
				
				byte [] tagHeader = new byte[5];		
				src.get(tagHeader);
				
				if(new String(tagHeader).equals("[TAG]")) {
					
					byte [] tagData = new byte [ size - comprLen - resLen - 21];
					src.get(tagData);
					
					try {
						String tags = new String(tagData, "ISO-8859-1").trim();
						
						String [] lines = tags.split("\n");
						
						for(String line : lines) {
							String parts [] = line.split("=");
							if(parts[0].equals("copyright")) {
								info[INFO_COPYRIGHT] = parts[1];
							} else
							if(parts[0].equals("artist")) {
								info[INFO_AUTHOR] = parts[1];
							} else
							if(parts[0].equals("title")) {
								info[INFO_TITLE] = parts[1];
							} else
							if(parts[0].equals("game")) {
								info[INFO_GAME] = parts[1];
							} else
							if(parts[0].equals("length")) {
								info[INFO_LENGTH] = parts[1];
							}
						}
						
						
						
					} catch (UnsupportedEncodingException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}					
			}
			return true;
		}
		return false;
	}
	
	//@Override
	//public boolean loadInfo(File file) throws IOException {
//		return load(file);
	//}

	@Override
	public int getSoundData(short[] dest, int size) {
		return N_getSoundData(songFile, dest, size);
	}

	@Override
	public String getStringInfo(int what) {
		
		if(info != null) {
			return info[what];
		}
		
		
		return N_getStringInfo(songFile, what);
	}

	@Override
	public int getIntInfo(int what) {
		if(info != null) {
			
			if(what == INFO_LENGTH) {
				String [] parts = info[what].split("=");
				int secs = 0;
				if(parts != null && parts.length == 2)
					secs = Integer.parseInt(parts[0]) * 60 + Integer.parseInt(parts[1]);
				return secs;
			}
			return 0;
		}
		return N_getIntInfo(songFile, what);
	}

	native public long N_load(String fileName);	
	native public void N_unload(long song);
	native public int N_getSoundData(long song, short [] dest, int size);
	native public String N_getStringInfo(long song, int what);
	native public int N_getIntInfo(long song, int what);

}
