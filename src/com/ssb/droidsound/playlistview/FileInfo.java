package com.ssb.droidsound.playlistview;

import java.io.File;

import com.ssb.droidsound.database.SongDatabase;

/** Class used for returning information about songs in list */
public class FileInfo {

	public int type;
	public String path;
	public String name;

	FileInfo(String p, String fn, int fl) {
		path = p;
		if(path.endsWith("/")) {
			path = path.substring(0,path.length()-1);
		}
		name = fn;
		type = fl;
	}

	FileInfo(String p, String fn) {
		path = p;
		if(path.endsWith("/")) {
			path = path.substring(0,path.length()-1);
		}
		name = fn;
		type = SongDatabase.TYPE_FILE;
	}

	final File getFile() {
		return new File(path, name);
	}

	public final String getPath() {
		return path + "/" + name;
	}

	public final String getName() {
		return name;
	}

	@Override
	public final int hashCode() {
		return path.hashCode() ^ name.hashCode();
	}

	@Override
	public final boolean equals(Object o) {
		if(o instanceof FileInfo) {
			FileInfo fi = (FileInfo)o;
			return (fi.path.equals(path) && fi.name.equals(name));
		}
		return super.equals(o);
	}
}
