package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.IOException;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import com.ssb.droidsound.service.FileSource;



public class GSFPlugin extends DroidSoundPlugin {
	
	static {
		System.loadLibrary("playgsf");
	}

	private Set<String> extensions;
	
	static String [] ex = { "GSF", "MINIGSF" };
	
	long currentSong = 0;

	private String[] info;
	
	private FileSource libFile;

	public GSFPlugin() {
		extensions = new HashSet<String>();
		for(String s : ex) {			
			extensions.add(s);
		}
	}
	
	@Override
	public boolean canHandle(FileSource fs) {
		return extensions.contains(fs.getExt());
	}

	
	@Override
	public void getDetailedInfo(List<String> list) {
		
		//String s = N_getStringInfo(currentSong, INFO_TYPE);
		//if(s != null & s.length() > 0) {
			list.add("Format");
			list.add("GSF/Gameboy Advance");
		//}
		//s = N_getStringInfo(currentSong, INFO_COPYRIGHT);
		if(info[INFO_COPYRIGHT] != null) {
			list.add("Copyright");
			list.add(info[INFO_COPYRIGHT]);
		}
		//s = N_getStringInfo(currentSong, INFO_GAME);
		if(info[INFO_GAME] != null) {
			list.add("Game");
			list.add(info[INFO_GAME]);
		}
	}
	
	@Override
	public boolean load(FileSource fs) {
		
		
		Map<String, String> tagMap = PSFFile.getTags(fs.getContents(), fs.getLength());
		info = new String [128];
		if(tagMap != null) {			
			info[INFO_TITLE] = tagMap.get("title");
			info[INFO_AUTHOR] = tagMap.get("artist");
			info[INFO_GAME] = tagMap.get("game");
			info[INFO_COPYRIGHT] = tagMap.get("copyright");
			info[INFO_LENGTH] = tagMap.get("length");
		}
		
		String libName = tagMap.get("_lib");

		if(libName != null) {
			libFile = fs.getRelative(libName);
			libFile.getFile();
		}
		
		//if(fs.isFile()) 		
			currentSong = N_loadFile(fs.getFile().getPath());
		//else
		//	currentSong = N_load(fs.getContents(), (int) fs.getLength());
		//fs.close();
		//if(fs2 != null)
		//	fs2.close();
			
			
		return (currentSong != 0);
	}
	
	@Override
	public boolean loadInfo(FileSource fs) {
		
		byte [] module = fs.getContents();
		int size = fs.getLength();
		
		//ByteBuffer src = ByteBuffer.wrap(module, 0, size);		
		//src.order(ByteOrder.LITTLE_ENDIAN);		
		//byte[] id = new byte[4];
		//src.get(id);
		
		//for(int i=0; i<128; i++)
		//	info[i] = null;
		
		info = new String [128];
		 
		Map<String, String> tagMap = PSFFile.getTags(module, size);
		if(tagMap != null) {
			info[INFO_TITLE] = tagMap.get("title");
			info[INFO_AUTHOR] = tagMap.get("artist");
			info[INFO_GAME] = tagMap.get("game");
			info[INFO_COPYRIGHT] = tagMap.get("copyright");
			info[INFO_LENGTH] = tagMap.get("length");
			return true;
		}
		return false;
	}
	
	@Override
	public String getStringInfo(int what) {
		
		if(info != null) {
			return info[what];
		}
		return null;
				
	}

	@Override
	public int getIntInfo(int what) {
		if(info != null) {
			if(what == INFO_LENGTH) {				
				return PSFFile.parseLength(info[what]);
			}
		}
		return 0;

	}

	@Override
	public void unload() {
		N_unload(currentSong);
		currentSong = 0;
	}
	
	@Override
	public String getVersion() {
		return "playgsf 0.7.1";
	}
	
	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	@Override
	public int getSoundData(short [] dest, int size) { return N_getSoundData(currentSong, dest, size); }	

	// NATIVE
	
	native public long N_loadFile(String name);
	native public void N_unload(long song);
	native public int N_getSoundData(long song, short [] dest, int size);	
}
