package com.ssb.droidsound.utils;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.InputStream;
import java.util.Enumeration;
import java.util.zip.ZipEntry;

public class NativeZipFile {

	static {
		System.loadLibrary("nativezipfile");
	}
	
	static class MyZipEntry extends ZipEntry {

		public MyZipEntry(String name) {
			super(name);
		}
		public MyZipEntry(ZipEntry ze) {
			super(ze);
		}
		
		private int index;

		public void setIndex(int i) { index = i; }
		public int getIndex() { return index; }
	};
	
	private native void openZipFile(String fileName);
	
	native void closeZipFile();
	native int getCount();
	native String getEntry(int i);
	native int getSize(int i);
	native int findEntry(String name);
	native int readData(int i, byte [] target);

	public NativeZipFile(String fileName) {
		openZipFile(fileName);
	}
	
	public NativeZipFile(File file) {
		openZipFile(file.getPath());
	}
	
	public ZipEntry getEntry(String entryName) {
		
		int e = findEntry(entryName);
		if(e >= 0) {
			String name = getEntry(e);
			MyZipEntry entry = new MyZipEntry(name);
			entry.setIndex(e);
			entry.setSize(getSize(e));
			return entry;
		}
		return null;
	}
	
	class MyEnumeration implements Enumeration<MyZipEntry> {

		private NativeZipFile zipFile;
		private int currentIndex;
		private int total;

		MyEnumeration(NativeZipFile zf){
			zipFile = zf;
			currentIndex = 0;
			total = zf.getCount();
		}
		
		@Override
		public boolean hasMoreElements() {
			return (currentIndex < total);
		}		

		@Override
		public MyZipEntry nextElement() {
			String name = getEntry(currentIndex);
			MyZipEntry entry = new MyZipEntry(name);
			entry.setIndex(currentIndex);
			entry.setSize(getSize(currentIndex));
			currentIndex++;
			return entry;
		}
	};
	
	public Enumeration<? extends ZipEntry> entries() {
		return new MyEnumeration(this);
	}
	
	public InputStream getInputStream(ZipEntry entry) {		
		int index = ((MyZipEntry)entry).getIndex();		
		byte [] data = new byte [ getSize(index) ];
		
		readData(index, data);
		
		return new ByteArrayInputStream(data);
	}
	
	public int size() {
		return getCount();
	}
	
	public void close() {
		closeZipFile();
	}	
}
