package com.ssb.droidsound.bo;

import java.io.File;

public class SongFileData {
	public final File file;
	public final byte[] data;

	public SongFileData(File file, byte[] data) {
		this.file = file;
		this.data = data;
	}

	public File getFile() {
		return file;
	}
	public byte[] getData() {
		return data;
	}
}
