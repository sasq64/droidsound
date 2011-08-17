package com.ssb.droidsound;

import java.io.File;

//import com.ssb.droidsound.utils.Log; Log is not used as of now.
import com.ssb.droidsoundedit.R;

public final class SongFile {

	public static final String TAG = SongFile.class.getSimpleName();
	
	private int subtune;
	private int playtime;		//Duration track plays for
	private String fileName;	//Name of file.
	private File file;			//Actual file itself.
	private String path;		//Path on the system to that file.
	private String prefix;
	private String suffix;
	private String midfix;
	private String zipPath;		//Path on the system to the zip file 
	private String zipName;		//Name of the zip file.

	//private String tuneString;
	private String title;
	private String composer;
	private String protocol;

	public SongFile(SongFile s) {
		subtune = s.subtune;
		playtime = s.playtime;
		fileName = s.fileName;
		file = s.file;
		path = s.path;
		prefix = s.prefix;
		suffix = s.suffix;
		midfix = s.midfix;
		zipPath = s.zipPath;
		zipName = s.zipName;
		title = s.title;
		composer = s.composer;
		protocol = s.protocol;
	}

	public SongFile(File f) {
		init(f.getPath());
	}

	public SongFile(String fname) {
		init(fname);
	}

	private void init(String fname) {
		subtune = -1;
		playtime = -1;
		protocol = "";
		if(fname.startsWith("file://")) {
			fname = fname.substring(7);
		} else if(fname.startsWith("http://")) {
			fname = fname.substring(7);
			protocol = "http://";
		}

		title = composer = null;

		if(fname.indexOf('\t') >= 0) {
			String[] t = fname.split("\t");
			fname = t[0];
			title = t[1];
			if(t.length > 2) {
				composer = t[2];
			}
		}

		String[] s = fname.split(";");

		fileName = s[0];

		//int sc = fileName.lastIndexOf(';');
		if(s.length > 1) {
			if(s.length > 2) {
				try {
					playtime = Integer.parseInt(s[2]);
				} catch (NumberFormatException e) {}
			}
			try {
				subtune = Integer.parseInt(s[1]);
			} catch (NumberFormatException e) {}
			fileName = s[0];
		}


		int slash = fileName.lastIndexOf('/');
		if(slash > 0) {
			path = fileName.substring(0, slash);
			fileName = fileName.substring(slash+1);
		} else {
			path = "";
		}

		midfix = fileName;
		prefix = suffix = "";
		int firstDot = fileName.indexOf('.');
		int lastDot = fileName.lastIndexOf('.');
		if(firstDot > 0) {
			prefix = fileName.substring(0, firstDot);
			suffix = fileName.substring(lastDot+1);
			midfix = fileName.substring(firstDot, lastDot+1);
		}

		int zip = s[0].toUpperCase().indexOf(".ZIP/");
		if(zip > 0) {
			zipPath = s[0].substring(0, zip+4);
			zipName = s[0].substring(zip+5);
		}

		file = new File(path, fileName);

		//Log.d(TAG, "SONGFILE -%s-%s-%s-%s- %d,%d", path, prefix, midfix, suffix, subtune, playtime);
	}

	public final String getTitle() {
		return title;
	}

	public final String getComposer() {
		return composer;
	}

	public final String getPrefix() {
		return prefix;
	}

	public final String getSuffix() {
		return suffix;
	}

	public final File getFile() {
		return file;
	}

	public final int getSubtune() {
		return subtune;
	}

	public final int getPlaytime() {
		return playtime;
	}

	public final void changePrefix(String p) {
		prefix = p;
		fileName = prefix + midfix + "suffix";
	}
	
	public final void changeSuffix(String s) {
		suffix = s;
		fileName = prefix + midfix + "suffix";
	}

	public SongFile(File f, int t, String title) {
		init(f.getPath());
		if(subtune < 0) {
			subtune = t;
		}
		this.title = title;
	}

	public SongFile(String song, int t) {
		init(song);
		if(t < 0) {
			subtune = t;
		}
	}

	//Returns zip file's file path.
	public final String getZipPath() {
		return zipPath;
	}

	//Returns filename of a zip file.
	public final String getZipName() {
		return zipName;
	}

	public final String getPath() {
		if(subtune >= 0) {
			if(playtime >= 0) {
				return protocol + path + "/" + fileName + ";" + subtune + ";" + playtime;
			}
			return protocol + path + "/" + fileName + ";" + subtune;
		} else {
			return protocol + path + "/" + fileName;
		}
	}

	//Detects any subtunes within the file  (such as the SID, NSF, etc).
	public final void setSubTune(int t) {
		subtune = t;
	}

	//Sets the total time the track will play for.
	public final void setPlayTime(int t) {
		playtime = t;
	}

	//Sets title to display in the player.
	public final void setTitle(String t) {
		title = t;
	}

	//Gets filename of file.
	public final String getName() {
		//return file.getName();
		return fileName;
	}

	//Checks if file exists.
	public final boolean exists() {
		return file.exists();
	}


	public final String getParent() {
		return protocol + file.getParent();
	}

	public final boolean isDirectory() {
		return file.isDirectory();
	}

	public final File[] listFiles() {
		return file.listFiles();
	}

	public final SongFile[] listSongFiles() {
		File [] files = file.listFiles();
		SongFile [] sfiles = new SongFile [files.length];
		for(int i=0; i<files.length; i++) {
			sfiles[i] = new SongFile(files[i]);
		}
		return sfiles;
	}

	public final void delete() {
		 file.delete();
	}
}
