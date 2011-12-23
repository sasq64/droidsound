package com.ssb.droidsound;

import java.io.File;

public class SongFile {
	private int subtune;
	private int playtime;
	private String fileName;

	private File file;
	private String path;
	private String zipPath;
	private String zipName;

	private String title;
	private String composer;

	public SongFile(SongFile s) {
		subtune = s.subtune;
		playtime = s.playtime;
		fileName = s.fileName;
		file = s.file;
		path = s.path;
		zipPath = s.zipPath;
		zipName = s.zipName;
		title = s.title;
		composer = s.composer;
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
		title = composer = null;

		if(fname.indexOf('\t') >= 0) {
			String t[] = fname.split("\t");
			fname = t[0];
			title = t[1];
			if(t.length > 2) {
				composer = t[2];
			}
		}

		String s[] = fname.split(";");

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

		int zip = s[0].toUpperCase().indexOf(".ZIP/");
		if(zip > 0) {
			zipPath = s[0].substring(0, zip+4);
			zipName = s[0].substring(zip+5);
		}

		file = new File(path, fileName);

		//Log.d(TAG, "SONGFILE -%s-%s-%s-%s- %d,%d", path, prefix, midfix, suffix, subtune, playtime);
	}

	public String getTitle() {
		return title;
	}

	public String getComposer() {
		return composer;
	}

	public File getFile() {
		return file;
	}

	public int getSubtune() {
		return subtune;
	}

	public int getPlaytime() {
		return playtime;
	}

	public SongFile(File f, int t, String title) {
		init(f.getPath());
		if (subtune < 0) {
			subtune = t;
		}
		this.title = title;
	}

	public SongFile(String song, int t) {
		init(song);
		if (t < 0) {
			subtune = t;
		}
	}

	public String getZipPath() {
		return zipPath;
	}

	public String getZipName() {
		return zipName;
	}

	public String getPath() {
		if (subtune >= 0) {
			if (playtime >= 0) {
				return path + "/" + fileName + ";" + subtune + ";" + playtime;
			}
			return path + "/" + fileName + ";" + subtune;
		} else {
			return path + "/" + fileName;
		}
	}

	public void setSubTune(int t) {
		subtune = t;
	}

	public void setPlayTime(int t) {
		playtime = t;
	}

	public void setTitle(String t) {
		title = t;
	}

	public String getName() {
		return fileName;
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
		File[] files = file.listFiles();
		SongFile[] sfiles = new SongFile[files.length];
		for (int i = 0; i < files.length; i ++) {
			sfiles[i] = new SongFile(files[i]);
		}
		return sfiles;
	}

	public boolean delete() {
		return file.delete();
	}
}
