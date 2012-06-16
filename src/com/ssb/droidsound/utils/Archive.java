package com.ssb.droidsound.utils;

import java.util.Iterator;

public interface Archive {

	public interface Entry {
		public String getPath();
		public long getSize();
	}
	
	Iterator<Entry> getIerator();	
	Entry getEntry(String path);	
	FileSource getFileSource(Entry entry);
	void close();
	int getFileCount();
	
}
