package com.ssb.droidsound.utils;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
//import java.util.Enumeration;
import java.util.Iterator;
import java.util.zip.ZipEntry;

import com.ssb.droidsound.file.FileSource;
import com.ssb.droidsound.file.ZipFileSource;

public class NativeZipFile implements Archive {
	private static final String TAG = NativeZipFile.class.getSimpleName();
	static {
		System.loadLibrary("nativezipfile");
	}
	
	static class MyZipEntry extends ZipEntry implements Archive.Entry {

		public MyZipEntry(String name) {
			super(name);
		}
		public MyZipEntry(ZipEntry ze) {
			super(ze);
		}
		
		private int index;

		protected void setIndex(int i) { index = i; }
		protected int getIndex() { return index; }

		@Override
		public String getPath() {
			return this.getName();
		}
	};
	
	private long zipRef;
	private String zipName;	
	
	private native void openZipFile(String fileName);
	
	private native void closeZipFile();
	private native int getCount();
	private native String getEntry(int i);
	private native int getSize(int i);
	private native int findEntry(String name);
	private native int readData(int i, byte [] target);

	private native long open(int index);
	private native int read(long fd, byte [] target, int offs, int len);
	private native void close(long fd);
	
	
	public NativeZipFile(String fileName) throws IOException {
		zipName = fileName;
		openZipFile(fileName);
		if(zipRef == 0) {
			throw new IOException();
		}
	}
	
	public NativeZipFile(File file) throws IOException {
		zipName = file.getPath();
		openZipFile(file.getPath());
		if(zipRef == 0) {
			throw new IOException();
		}
	}
	
	public String getZipName() {
		return zipName;
	}
	
	public Archive.Entry getEntry(String entryName) {
		
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
	/*
	class MyEnumeration implements Enumeration<MyZipEntry> {

		@SuppressWarnings("unused")
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
			Log.d(TAG, "Next element:'%s'\n", name);
			MyZipEntry entry = new MyZipEntry(name);
			entry.setIndex(currentIndex);
			entry.setSize(getSize(currentIndex));
			currentIndex++;

			return entry;
		}
	};
	
	public Enumeration<? extends ZipEntry> entries() {
		return new MyEnumeration(this);
	}*/
	
	static class NZInputStream extends InputStream {
		@SuppressWarnings("unused")
		private static final String TAG = NZInputStream.class.getSimpleName();

		private NativeZipFile zipFile;
		//private byte buffer [];
		private long fd;
		private int total;
		
		private NZInputStream(long fd, NativeZipFile zf, int len) {
			zipFile = zf;
			this.fd = fd;
			total = len;
//			buffer = new byte [];
		}
		
		
		
		@Override
		public int read() throws IOException {
			byte [] b = new byte [1];
			int rc = read(b, 0, 1);
			if(rc > 0) {
				return b[0];
			} else {
				return -1;
			}
		}

		@Override
		public void close() {
			zipFile.close(fd);
		}

		@Override
		public int available() throws IOException {
			//Log.d(TAG, "Available: %d bytes", total);
			return total;
		}
		
		@Override
		public int read(byte[] b, int offset, int length) throws IOException {
						
			//Log.d(TAG, "Reading %d bytes", length);
			int rc = zipFile.read(fd, b, offset, length);
			if(rc > 0) {
				total -= rc;
			}
			return rc;
		}
		
		@Override
		public int read(byte[] b) throws IOException {
			return read(b, 0, b.length);
		}
	}
	
	
	public InputStream getInputStream(ZipEntry entry) {		
		int index = ((MyZipEntry)entry).getIndex();
		
		
		long fd = open(index);
		if(fd > 0) {
			return new NZInputStream(fd, this, getSize(index));
		} else {
			return null;
		}
		
		/*byte [] data = new byte [ getSize(index) ];		
		readData(index, data);		
		return new ByteArrayInputStream(data); */
	}
	
	public int size() {
		return getCount();
	}
	
	public void close() {
		closeZipFile();
	}
	
	private static class MyIterator implements Iterator<Archive.Entry> {

		
		private NativeZipFile zipFile;
		private int currentIndex;
		private int total;

		public MyIterator(NativeZipFile zf){
			zipFile = zf;
			currentIndex = 0;
			total = zf.getCount();
		}
		
		@Override
		public boolean hasNext() {
			return (currentIndex < total);
		}

		@Override
		public Entry next() {
			
			String name = zipFile.getEntry(currentIndex);
			Log.d(TAG, "Next element:'%s'\n", name);
			MyZipEntry entry = new MyZipEntry(name);
			entry.setIndex(currentIndex);
			entry.setSize(zipFile.getSize(currentIndex));
			currentIndex++;
			return entry;
		}

		@Override
		public void remove() {
		}
	}
	

	@Override
	public Iterator<Archive.Entry> getIerator() {
		return new MyIterator(this);
	}

	@Override
	public FileSource getFileSource(Entry entry) {
		FileSource fs = new ZipFileSource(this, (MyZipEntry) entry);
		return fs;
	}

	@Override
	public int getFileCount() {
		return getCount();
	}	
}
