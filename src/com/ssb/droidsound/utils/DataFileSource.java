package com.ssb.droidsound.utils;

import com.ssb.droidsound.file.FileSource;

public class DataFileSource extends FileSource {

	private byte[] contents;

	public DataFileSource(String name, byte[] bs) {
		super(name);
		contents = bs;
	}
	
	@Override
	protected byte[] intGetContents() {
		return contents;
	}

}
