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

}
