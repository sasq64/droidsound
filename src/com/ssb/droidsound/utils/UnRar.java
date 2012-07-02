package com.ssb.droidsound.utils;

import java.util.Iterator;

import com.ssb.droidsound.file.FileSource;

public class UnRar implements Archive {
	private static final String TAG = UnRar.class.getSimpleName();
	static {
		System.loadLibrary("unrar");
	}

	private String archive;


	public UnRar(String fileName) {
		archive = fileName;
	}
	
	public boolean extractTo(String target) {
		int rc = N_extractAll(archive, target);
		return rc == 0;
	}
	
	private static class RarEntry implements Archive.Entry {
		
		private UnRar rarFile;
		
		@Override
		public String getPath() {
			return rarFile.N_getFileName();
		}

		@Override
		public long getSize() {
			return rarFile.N_getFileSize();
		}
	}
	
	/*
	private static class MyIterator implements Iterator<RarEntry> {
		
		@Override
		public boolean hasNext() {
		}

		@Override
		public RarEntry next() {
			rarFile
		}

		@Override
		public void remove() {
		}
	}*/

	@Override
	public Iterator<Entry> getIterator() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Entry getEntry(String path) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public FileSource getFileSource(Entry entry) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void close() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public int getFileCount() {
		// TODO Auto-generated method stub
		return 0;
	}

	native int N_extractAll(String archive, String target);	
	native int N_open(String archive);
	native int N_skip();
	native int N_extract(String targetDir);
	native String N_getFileName();
	native int N_getFileSize();

}
