package com.ssb.droidsound.utils;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import com.ssb.droidsound.utils.Log;

public class M3UParser implements PlaylistParser {
	private static final String TAG = M3UParser.class.getSimpleName();
	private List<String> songs;
	private List<String> descs;

	private Map<String, String> defines = new HashMap<String, String>();

	public M3UParser(File file) {
		BufferedReader reader;
		
		songs = new ArrayList<String>();
		descs = new ArrayList<String>();
		
		try {
			reader = new BufferedReader(new FileReader(file));
			String line = reader.readLine();
			String desc = "";
			while(line != null) {				
				Log.d(TAG, line);
				line = line.trim();
								
				if(line.length() > 0) {
					if(line.charAt(0) == '#') {
						if(line.startsWith("#EXTINF:")) {
							String args[] = line.substring(8).split(",");
							if(args.length >= 2)
								desc = args[1];
						} else
						if(line.startsWith("#WEBPAGE:")) {
							defines.put("webpage", line.substring(9).trim());							
								
						} else
						if(line.startsWith("#DEFINE:")) {
							String def = line.substring(8).trim();
							String parts [] = def.split("=");
							if(parts != null && parts.length == 2) {
								defines.put(parts[0].toLowerCase(Locale.ENGLISH), parts[1]);
							}
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
	
	@Override
	public String getVariable(String var) { return defines.get(var); }

	@Override
	public String getMedia(int i) { return songs.get(i); }
	@Override
	public String getDescription(int i) { return descs.get(i); }
	public int getMediaCount() { return songs.size(); }
	public List<String> getMediaList() { return songs; }
}
