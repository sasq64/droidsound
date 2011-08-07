package com.ssb.droidsound.utils;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import com.ssb.droidsound.utils.Log;

public final class M3UParser implements PlaylistParser {
	private static final String TAG = M3UParser.class.getSimpleName();
	private final List<String> songs;
	private final List<String> descs;

	public M3UParser(File file) {

        songs = new ArrayList<String>();
		descs = new ArrayList<String>();
		
		try {
            BufferedReader reader = new BufferedReader(new FileReader(file));
            String line = reader.readLine();
			String desc = "";
			while(line != null) {				
				Log.d(TAG, line);
				line = line.trim();
				
				if(line.length() > 0) {
					if(line.charAt(0) == '#') {
						if(line.startsWith("#EXTINF:")) {
							String[] args = line.substring(8).split(",");
							if(args.length >= 2)
								desc = args[1];
						}
					} else {
						songs.add(line);
						descs.add(desc);
						desc = "";
						Log.d(TAG, "Line:%s", line);
					}
				}
				line = reader.readLine();
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public String getMedia(int i) { return songs.get(i); }
	public String getDescription(int i) { return descs.get(i); }
	public int getMediaCount() { return songs.size(); }
	public List<String> getMediaList() { return songs; }
}
