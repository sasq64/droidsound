package com.ssb.droidsound;

import java.io.File;

public class SongFile {

	private File file;
	private int subtune;
	private String tuneString;
	private String title;
	private String composer;
	
	SongFile(File f) {
		file = f;
		subtune = -1;
		String n = f.getPath();
		int sc = n.lastIndexOf(';');
		if(sc >= 0) {
			try {
				subtune = Integer.parseInt(n.substring(sc+1));
				file = new File(n.substring(0, sc));
			} catch (NumberFormatException e) {
			}					
		}

		if(subtune >= 0) {
			tuneString = ";" + subtune;
		} else {
			tuneString = "";
		}
	}
	
	File getFile() {
		return file;
	}
	
	int getSubtune() {
		return subtune;
	}

	public SongFile(File f, int t, String title) {
		file = f ;
		subtune = t;
		
		String name = f.getName();
		int sc = name.indexOf(';');
		
		if(sc > 0) {
			try {
				t = Integer.parseInt(name.substring(sc+1));
			} catch (NumberFormatException e) {
			}
			
			file = new File(f.getParent(), name.substring(0, sc));
			
			if(subtune == -1) {
				subtune = t;
			}
		}
		
		
		if(subtune >= 0) {
			tuneString = ";" + subtune;
		} else {
			tuneString = "";
		}
		this.title = title;
	}

	public String getPath() {
		return file.getPath() + tuneString;
	}

	public String getName() {
		return file.getName();
	}

	public boolean exists() {
		return file.exists();
	}
	

	public String getParent() {
		return file.getParent();
	}

	public boolean isDirectory() {
		return file.isDirectory();
	}

	public File[] listFiles() {
		return file.listFiles();
	}

	public SongFile[] listSongFiles() {
		File [] files = file.listFiles();
		SongFile [] sfiles = new SongFile [files.length];
		for(int i=0; i<files.length; i++) {
			sfiles[i] = new SongFile(files[i]);
		}
		return sfiles;
	}
}
