package com.ssb.droidsound.utils;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.util.Enumeration;
import java.util.zip.ZipEntry;

public class NativeZipFile {
	private static final String TAG = NativeZipFile.class.getSimpleName();
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

		protected void setIndex(int i) { index = i; }
		protected int getIndex() { return index; }
	};
	
	private long zipRef;	
	
	private native void openZipFile(String fileName);
	
	native void closeZipFile();
	native int getCount();
	native String getEntry(int i);
	native int getSize(int i);
	native int findEntry(String name);
	native int readData(int i, byte [] target);

	native long open(int index);
	native int read(long fd, byte [] target, int offs, int len);
	native void close(long fd);
	
	
	public NativeZipFile(String fileName) throws IOException {
		openZipFile(fileName);
		if(zipRef == 0) {
			throw new IOException();
		}
	}
	
	public NativeZipFile(File file) throws IOException {
		openZipFile(file.getPath());
		if(zipRef == 0) {
			throw new IOException();
		}
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
	}
	
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
}
