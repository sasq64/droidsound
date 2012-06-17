package com.ssb.droidsound.file;

import java.io.File;

public class RealFileSource extends FileSource {

	private File file;

	public RealFileSource(File file) {
		super(file.getName());
		this.file = file;
	}
	
	@Override
	protected File intGetFile() {
		return file;
	}
	
	@Override
	public FileSource getRelative(String name) {
		return new RealFileSource(new File(file.getParentFile(), name));
	}
	
	@Override
	public long getLength() {
		return file.length();
	}
	
}
