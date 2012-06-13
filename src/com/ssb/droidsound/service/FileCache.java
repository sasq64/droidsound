package com.ssb.droidsound.service;

import java.io.File;

import android.os.Environment;

public class FileCache {
	
	public static File getTempDir() {
		File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
		File tempDir = new File(droidDir, "tempmusic");
		File dir = new File(tempDir, "music" + Long.toString(System.nanoTime()));
		dir.mkdirs();
		return dir;
	}

	public static void removeDir(File dir) {
		
		File [] files = dir.listFiles();
		for(File f : files) {
			if(f.isFile())
				f.delete();
			else
				removeDir(f);
		}
		dir.delete();
	}
	
	public static String getBaseName(String fname) {
		int slash = fname.lastIndexOf('/');
		if(slash >= 0) {
			fname = fname.substring(slash+1);
		}
		int dot = fname.lastIndexOf('.');
		if(dot > 0) {
			fname = fname.substring(0, dot);
		}
		return fname;
	}
	

}
