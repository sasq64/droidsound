package com.ssb.droidsound.file;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import android.os.Environment;

import com.ssb.droidsound.utils.Log;


public class FileCache {
	private static final String TAG = FileCache.class.getSimpleName();	
	private static FileCache _instance = null;
	
	private static class CacheEntry {
		public CacheEntry(File f) {
			file = f;
			File dotFile = FileCache.getDotFile(f);
			if(dotFile.exists()) {
				time = dotFile.lastModified();
			} else {
				time = f.lastModified();
			}
				
		}
		public File file;
		public long time;
	}
	
	private List<CacheEntry> fileList;
	private List<File> newFiles;

	private File cacheDir;

	private String exDir;
	private int totalSize;
	private long limitSize;
	
	public static synchronized FileCache getInstance() {
		if(_instance == null) {
			_instance = new FileCache();
		}
		return _instance;
	}
	
	public FileCache() {
		fileList = new ArrayList<CacheEntry>();
		newFiles = new ArrayList<File>();
		exDir = Environment.getExternalStorageDirectory().getPath();
		cacheDir = new File(exDir + "/droidsound/fileCache");
		Log.d(TAG, "Created dir '%s'", cacheDir.getPath());
		cacheDir.mkdirs();
		
		limitSize = 16*1024*1024;
		
		indexFiles(cacheDir);
		Collections.sort(fileList, new Comparator<CacheEntry>() {
			@Override
			public int compare(CacheEntry lhs, CacheEntry rhs) {
				return (int) (lhs.time - rhs.time);
			}
		});
		
		for(CacheEntry f : fileList) {
			Log.d(TAG, "FILE: %s (%d)", f.file.getPath(), f.time);
		}
		
	}
	
	public void setLimitSize(long ls) {
		limitSize = ls;
		limit(limitSize);		
	}

	private void indexFiles(File dir) {
		
		totalSize = 0;
		File [] files = dir.listFiles();
		for(File f : files) {
			if(f.isFile()) {
				if(f.getName().charAt(0) != '.') {
					fileList.add(new CacheEntry(f));
					totalSize += f.length();
				}
			} else {
				indexFiles(f);
			}
		}
		dir.delete();
	}
	
	private void limit(long limitSize) {
		Log.d(TAG, "TOTAL SIZE IS %d", totalSize);
		if(totalSize <= limitSize)
			return;
		for(CacheEntry f : fileList) {
			totalSize -= f.file.length();
			Log.d(TAG, "Removing FILE: %s", f.file.getPath());

			f.file.delete();
			if(totalSize <= limitSize)
				break;
		}
		indexFiles(cacheDir);
	}
	
	private void addNewFiles() {
		
		Iterator<File> i = newFiles.iterator();		
		while(i.hasNext()) {
			File f = i.next();
			if(f != null && f.exists()) {
				fileList.remove(f);
				Log.d(TAG, "Adding FILE: %s", f.getPath());
				totalSize += f.length();
				fileList.add(new CacheEntry(f));
				i.remove();
			}
		}
	}
	
	private static File getDotFile(File f) {
		return new File(f.getParentFile(), "." + f.getName());
	}
	
	public File getFile(String reference) {
		
		addNewFiles();
		
		if(limitSize >= 0)
			limit(limitSize);
		
		
		String path = reference;
		if(path.indexOf("http://") == 0) {
			path = "http/" + path.substring(7);
		}
		if(path.indexOf(exDir) == 0) {
			path = path.substring(exDir.length());
		}
		if(path.indexOf("/") == 0) {
			path = path.substring(1);
		}
				
		File file = new File(cacheDir, path);
		
		Log.d(TAG, "Creating file '%s'", file.getPath());
		
		file.getParentFile().mkdirs();
		
		if(file.exists()) {
			Log.d(TAG, "Exists, move to end", file.getPath());
			
			File dotFile = getDotFile(file);
			dotFile.delete();
			try {
				dotFile.createNewFile();
			} catch (IOException e) {
			}
			Log.d(TAG, "Touched file, %d %d %d", System.currentTimeMillis(), dotFile.lastModified(), file.lastModified());
			fileList.remove(file);
			fileList.add(new CacheEntry(file));
		} else {
			newFiles.add(file);			
		}
		
		return file;
	}

	public void purge() {
		limit(-1);
	}

	
	
}
