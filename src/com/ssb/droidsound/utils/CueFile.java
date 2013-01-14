package com.ssb.droidsound.utils;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

public class CueFile {
	private static final String TAG = CueFile.class.getSimpleName();

	public static class Track {
		public String performer;
		public String title;
		public int offset;
	};
	
	private List<Track> tracks;
	private Track currentTrack;

	public CueFile(File file) {

		tracks = new ArrayList<Track>();

		BufferedReader reader;
		try {
			reader = new BufferedReader(new FileReader(file));
			String line = reader.readLine();
			while(line != null) {				
				Log.d(TAG, line);
				String[] ll = line.trim().split(" ");
				if(ll.length > 0) {
					String arg;
					String cmd = ll[0].toUpperCase(Locale.ENGLISH);
					arg = getQuotedString(line);
					
					Log.d(TAG, "%s '%s'", cmd, arg);
					
					if(cmd.equals("TRACK")) {
						currentTrack = new Track();
						tracks.add(currentTrack);
						Log.d(TAG, "New track %02d", tracks.size());
					} else if(cmd.equals("TITLE")) {
						if(currentTrack != null)
							currentTrack.title = arg;						
					} else if(cmd.equals("PERFORMER")) {
						if(currentTrack != null)
							currentTrack.performer = arg;
					} else if(cmd.equals("INDEX")) {
						if(currentTrack != null) {
							String index[] = ll[2].split(":");
							int secs = Integer.parseInt(index[1]) + Integer.parseInt(index[0])*60;
							int frames = Integer.parseInt(index[2]);
							
							currentTrack.offset = secs * 1000 + frames * 1000 / 74;
						}						
					}
				}
				line = reader.readLine();
			}
			Log.d(TAG, "DONE");
			reader.close();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			//e.printStackTrace();
		}
	}
	
	public int getTrackCount() {
		return tracks.size();
	}
	
	public Track getTrack(int i) {
		return tracks.get(i);
	}
	
	public int trackFromPos(int pos) {
		for(int i=1; i<tracks.size(); i++) {
			if(pos < tracks.get(i).offset) 
				return i-1;
		}
		return tracks.size()-1;
	}

	private String getQuotedString(String line) {
		
		int q0 = line.indexOf('\"');
		int q1 = line.lastIndexOf('\"');
		if(q0 >= 0 && q1 >= 0 && q0 != q1) {
			return line.substring(q0+1, q1);
		}
		return null;
	}
}
