package com.ssb.droidsound;

import java.io.File;
import java.io.InputStream;
import java.util.Enumeration;
import java.util.zip.ZipEntry;

public class NativeZipFile {

	InputStream is;
	
	private native void openZipFile(String fileName);
		
	native int getCount();
	native String getEntry(int i);
	native int getSize(int i);
	native int findEntry(String name);	
	native int readData(int i, byte [] target);

	NativeZipFile(String fileName) {
		openZipFile(fileName);
	}
	
	NativeZipFile(File file) {
		openZipFile(file.getPath());
	}
	
	public NativeZipEntry getEntry(String entryName) {
		
		int e = findEntry(entryName);
		if(e >= 0) {
			String name = getEntry(e);
			ZipEntry entry = new ZipEntry(name);
			entry.setExtra(data)
			return entry;
		}
		return null;
	}
	
	public InputStream getInputStream(ZipEntry entry) {
	}

	
	
	
}
