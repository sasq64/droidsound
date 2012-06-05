package com.ssb.droidsound.service;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.zip.ZipEntry;

import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.NativeZipFile;

public class FileSource {

	
	private static final String TAG = "";
	
	private File file;
	private NativeZipFile zipFile;
	private String name;

	private byte[] buffer;
	long size;

	private File parentDir;

	public FileSource(File file) {
		this.file = file;
		this.size = file.length();
	}
	
	public FileSource(NativeZipFile zip, String name) {
		this.zipFile = zip;
		this.name = name;
		this.size = -1;
	}
	
	
	public byte [] getContents() {
		
		if(buffer == null) {
			if(zipFile != null) {
				ZipEntry entry = zipFile.getEntry(name);
				if(entry != null) {
					Log.d(TAG, "Entry  '%s' %d\n", entry.getName(), entry.getSize());
					InputStream fs = zipFile.getInputStream(entry);
					size = entry.getSize();
					buffer = new byte[(int) size];
					try {
						fs.read(buffer);
						fs.close();
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			} else {
				size = (int) file.length();
				buffer = new byte[(int) size];
				try {
					FileInputStream fs = new FileInputStream(file);
					fs.read(buffer);
					fs.close();
				} catch (IOException e) {
					e.printStackTrace();
				}

			}
		}
		return buffer;
		
	}
	
	public long getLength() {
		if(size == -1)
			getContents();
		return size;
	}
	
	public File getFile() {
		
		if(file == null) {
			
			getContents();
			try {
				parentDir = File.createTempFile("music", Long.toString(System.nanoTime()));
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			parentDir.delete();
			parentDir.mkdir();
			
			FileOutputStream fos;
			try {
				file = new File(parentDir, name);
				fos = new FileOutputStream(file);
				fos.write(buffer);
				fos.flush();
				fos.close();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
		
		return file;
	}
	
	public String getName() {
		return name;
	}
	
	public FileSource getRelative(String name) {
		if(file != null) {
			File file2 = new File(file.getParentFile(), name);
			
		}
		return null;
	}
	
}
