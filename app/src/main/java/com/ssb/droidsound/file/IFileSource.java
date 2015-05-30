package com.ssb.droidsound.file;

import java.io.File;
import java.io.IOException;


public interface IFileSource {

	
	public byte [] getContents();
	public int getLength();
	public File getFile();
	public boolean isStream();
	public String getName();

	public FileSource getRelative(String name);
	public String getExt();
	public boolean isFile();
	public void read(byte[] data) throws IOException;
	public void close();
	public String getStreamName();
	
}
