package com.ssb.droidsound.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

/**
 * This class is a slow hack for the time being, because ZipFile's directory reading
 * has a bug for zips with >= 32768 entries. (No entries can be found.)
 *
 * @author alankila
 */
public class ZipReader {
	private final File file;

	private ZipInputStream zis;

	public ZipReader(File file) throws IOException {
		this.file = file;
		reset();
	}

	public ZipEntry seekTo(String entry) throws IOException {
		ZipEntry ze = null;
		while (null != (ze = zis.getNextEntry())) {
			if (ze.getName().equals(entry)) {
				break;
			}
		}
		return ze;
	}

	public InputStream getInputStream() {
		return zis;
	}

	public void closeEntry() throws IOException {
		zis.closeEntry();
	}

	public void reset() throws IOException {
		zis = new ZipInputStream(new FileInputStream(file));
	}

	public void close() throws IOException {
		zis.close();
	}
}
