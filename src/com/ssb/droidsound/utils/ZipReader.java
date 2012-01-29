package com.ssb.droidsound.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Enumeration;
import java.util.zip.ZipEntry;
import java.util.zip.ZipException;
import java.util.zip.ZipFile;
import java.util.zip.ZipInputStream;

/**
 * Return a compatible ZipFile reader that workarounds a potential bug in
 * Android's ZipFile for zips with more than 32768 entries.
 *
 * @author alankila@gmail.com
 */
public class ZipReader extends ZipFile {
	public static ZipFile openZip(File f) throws ZipException, IOException {
		/* Check if ZipFile works */
		ZipFile zf = new ZipFile(f);
		if (zf.size() != 0) {
			return zf;
		}
		zf.close();

		/* Uh oh, we must do our own hack... */
		return new ZipReader(f);
	}

	private final File file;

	private ZipInputStream zis;

	private ZipEntry ze;

	protected ZipReader(File file) throws IOException {
		super(file);
		this.file = file;
	}

	@Override
	public Enumeration<? extends ZipEntry> entries() {
		/* We could actually implement entries(), but nobody would be using it. */
		throw new IllegalStateException("Sorry, this is not the real ZipFile. Iterate with ZipInputStream.");
	}

	@Override
	public int size() {
		/* We don't want to implement this. */
		throw new IllegalStateException("Sorry, this is not the real ZipFile. This method will never be implemented.");
	}

	@Override
	public ZipEntry getEntry(String entryName) {
		try {
			ze = null;
			zis = new ZipInputStream(new FileInputStream(file));
			while (null != (ze = zis.getNextEntry())) {
				if (ze.getName().equals(entryName)) {
					break;
				}
			}
			return ze;
		}
		catch (IOException ioe) {
			throw new IllegalStateException(ioe);
		}
	}

	@Override
	public InputStream getInputStream(ZipEntry entry) throws IOException {
		if (entry == ze) {
			return zis;
		}
		throw new IllegalStateException("Sorry, this is not the real ZipFile. ZipEntry must be the same as last returned by getEntry().");
	}

	@Override
	public void close() throws IOException {
		super.close();
		if (zis != null) {
			zis.close();
			zis = null;
		}
	}
}
