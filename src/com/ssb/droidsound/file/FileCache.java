package com.ssb.droidsound.file;

import java.util.HashMap;
import java.util.Map;


public class FileCache {
	@SuppressWarnings("unused") private static final String TAG = FileCache.class.getSimpleName();
	
	private static FileCache _instance = null;
	
	private Map<String, FileSource> cache;
	
	public static synchronized FileCache getInstance() {
		if(_instance == null) {
			_instance = new FileCache();
		}
		return _instance;
	}
		
	public FileCache() {
		cache = new HashMap<String, FileSource>();
	}

	public void add(FileSource fs) {
		add(fs.getName(), fs);
	}
	
	public void add(String name, FileSource fs) {
		cache.put(name, fs);
	}
	
	
}
