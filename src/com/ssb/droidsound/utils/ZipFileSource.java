package com.ssb.droidsound.utils;

import java.io.IOException;
import java.io.InputStream;
import java.util.zip.ZipEntry;


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
		this.zipFile = zip;
		this.zipPath = null;
		zipEntry = (ZipEntry) zipFile.getEntry(entryName);
		size = zipEntry.getSize();
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
		return new ZipFileSource(zipFile, zipDir + name);
		
	}
	
	
	public ZipFileSource(String fileRef) {
		super(fileRef);
		
		int ext = fileRef.toLowerCase().indexOf(".zip/");
		if(ext < 0) return;
		zipPath = fileRef.substring(0, ext+4);
		String entryName = fileRef.substring(ext+5);
		try {
			zipFile = new NativeZipFile(zipPath);
			zipEntry = (ZipEntry) zipFile.getEntry(entryName);
		} catch (IOException e) {
			e.printStackTrace();
		}
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
}
