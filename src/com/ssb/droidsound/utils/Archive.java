package com.ssb.droidsound.utils;

import java.util.Iterator;

import com.ssb.droidsound.file.FileSource;

public interface Archive {

	public interface Entry {
		public String getPath();
		public long getSize();
	}
	
	Iterator<Entry> getIterator();	
	Entry getEntry(String path);	
	FileSource getFileSource(Entry entry);
	void close();
	int getFileCount();
	
}
