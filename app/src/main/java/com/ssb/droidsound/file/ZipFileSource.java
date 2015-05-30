package com.ssb.droidsound.file;

import java.io.IOException;
import java.io.InputStream;
import java.util.Locale;
import java.util.zip.ZipEntry;

import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.NativeZipFile;


public class ZipFileSource extends FileSource {	
	private static final String TAG = ZipFileSource.class.getSimpleName();
	
	private NativeZipFile zipFile;
	int bufferPos;
	long size;

	private ZipEntry zipEntry;

	private String zipPath;
	
	public ZipFileSource(String zipPath, String entryName) {		
		super(zipPath + "/" + entryName);
	
		this.zipPath = zipPath;			
		try {
			zipFile = new NativeZipFile(zipPath);
			zipEntry = (ZipEntry) zipFile.getEntry(entryName);
		} catch (IOException e) {
			e.printStackTrace();
		}
		size = zipEntry.getSize();		
	}
	


	public ZipFileSource(NativeZipFile zip, String entryName) {
		super(zip.getZipName() + "/" + entryName);
		isValid = false;
		this.zipFile = zip;
		this.zipPath = null;
		zipEntry = (ZipEntry) zipFile.getEntry(entryName);
		if(zipEntry != null) {
			size = zipEntry.getSize();
			isValid = true;
		} else {
			Log.d(TAG, "ZIP %s does not contain '%s'", zip.getZipName(), entryName);
		}
	}
	

	public ZipFileSource(NativeZipFile zip, ZipEntry ze) {
		super(zip.getZipName() + "/" + ze.getName());
		this.zipFile = zip;
		this.zipEntry = ze;
		this.zipPath = null;
		size = zipEntry.getSize();
	}
	
	@Override
	protected FileSource intGetRelative(String name) {
		
		String entryName = zipEntry.getName();
		int slash = entryName.lastIndexOf('/');
		String zipDir = "";
		if(slash > 0)
			zipDir = entryName.substring(0, slash+1);		
		ZipFileSource zfs = new ZipFileSource(zipFile, zipDir + name);
		if(zfs != null && zfs.isValid)
			return zfs;
		return null;
	}

	public ZipFileSource(String fileRef) {
		super(fileRef);
		isValid = false;
		int ext = fileRef.toLowerCase(Locale.ENGLISH).indexOf(".zip/");
		if(ext < 0) return;
		zipPath = fileRef.substring(0, ext+4);
		String entryName = fileRef.substring(ext+5);
		try {
			zipFile = new NativeZipFile(zipPath);
			zipEntry = (ZipEntry) zipFile.getEntry(entryName);
			if(zipEntry == null)
				return;
		} catch (IOException e) {
			e.printStackTrace();
		}
		isValid = true;
		size = zipEntry.getSize();
	}

	@Override
	public InputStream intGetStream() {
		return zipFile.getInputStream(zipEntry);
	}
	
	@Override
	public long getLength() {
		return size;
	}
	
	@Override
	public void close() {
		super.close();
		if(zipFile != null)
			zipFile.close();
		zipFile = null;
	}
	
}
