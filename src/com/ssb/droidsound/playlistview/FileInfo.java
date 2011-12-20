package com.ssb.droidsound.playlistview;

import java.io.File;

import com.ssb.droidsound.database.SongDatabase;

/** Class used for returning information about songs in list */
public class FileInfo {
	private final int type;
	private final String path;
	private final String name;

	public FileInfo(String p, String fn, int fl) {
		if (p.endsWith("/")) {
			path = p.substring(0, p.length() - 1);
		} else {
			path = p;
		}
		name = fn;
		type = fl;
	}

	public FileInfo(String p, String fn) {
		this(p, fn, SongDatabase.TYPE_FILE);
	}

	public int getType() {
		return type;
	}

	public String getPath() {
		return path + "/" + name;
	}

	public String getName() {
		return name;
	}

	public File getFile() {
		return new File(path, name);
	}

	@Override
	public int hashCode() {
		return path.hashCode() ^ name.hashCode();
	}

	@Override
	public boolean equals(Object o) {
		if(o instanceof FileInfo) {
			FileInfo fi = (FileInfo)o;
			return (fi.path.equals(path) && fi.name.equals(name));
		}
		return super.equals(o);
	}
}
