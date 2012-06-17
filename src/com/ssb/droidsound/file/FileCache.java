package com.ssb.droidsound.file;

import java.io.File;
import java.util.HashMap;
import java.util.Map;


public class FileCache {
	@SuppressWarnings("unused") private static final String TAG = FileCache.class.getSimpleName();
	
	private static FileCache _instance = null;
	
	private Map<String, File> cache;
	
	public static synchronized FileCache getInstance() {
		if(_instance == null) {
			_instance = new FileCache();
		}
		return _instance;
	}
		
	public FileCache() {
		cache = new HashMap<String, File>();
	}


	public void putFile(String reference, File file) {
		cache.put(reference, file);
	}

	public File getFile(String reference) {
		return cache.get(reference);
	}
	
	
}
