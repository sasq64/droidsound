package com.ssb.droidsound.service;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.util.zip.ZipEntry;

import android.os.Environment;

import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.NativeZipFile;

public class FileSource {

	
	private static final String TAG = FileSource.class.getSimpleName();
	
	private File file;
	private NativeZipFile zipFile;
	private InputStream inputStream;
	private byte[] buffer;
	int bufferPos;
	long size;
	private String streamName;

	private File parentDir;

	private ZipEntry zipEntry;

	private boolean isFile;

	private String baseName;

	private String zipDir;

	private String zipPath;

	private boolean leaveParentDir;
	
	//private static NativeZipFile cachedZipFile;
	//private static String cachedFileName;

	public FileSource(File file) {
		this.file = file;
		this.size = file.length();
		this.isFile = true;
		this.baseName = file.getName();
		this.zipDir = null;
		this.zipFile = null;
	}
	
	public FileSource(String fileRef) {
		
		int slash = fileRef.lastIndexOf('/');
		this.baseName = fileRef.substring(slash + 1);
		
		if(fileRef.startsWith("http:")) {
			streamName = fileRef;
		}
		
	}
	
	public FileSource(String zipPath, String entryName) {
	
		this.zipPath = zipPath;
		
		try {
			//if(cachedZipFile != null && cachedFileName.equals(zipPath)) {
			//	zipFile = cachedZipFile;
			//} else {
				zipFile = new NativeZipFile(zipPath);
				//cachedZipFile = zipFile;
				//cachedFileName = zipPath;
			//}
			zipEntry = zipFile.getEntry(entryName);
		} catch (IOException e) {
			e.printStackTrace();
		}
		initZip();
		
	}

	public FileSource(NativeZipFile zip, String entryName) {
		this.zipFile = zip;
		this.zipPath = null;
		zipEntry = zipFile.getEntry(entryName);
		initZip();
	}
	

	public FileSource(NativeZipFile zip, ZipEntry ze) {
		this.zipFile = zip;
		this.zipEntry = ze;
		this.zipPath = null;
		initZip();
			
	}

	void initZip() {
		this.isFile = false;
		if(zipFile != null && zipEntry != null) {
			//Log.d(TAG, "Entry  '%s' %d\n", zipEntry.getName(), zipEntry.getSize());
			size = zipEntry.getSize();
			String zname = zipEntry.getName();				
			int slash = zname.lastIndexOf('/');
			this.baseName = zname.substring(slash + 1);
			if(slash >= 0)
				this.zipDir = zname.substring(0,slash) + "/";
			else
				this.zipDir = "";
		}
	}	


	public FileSource(String name, byte[] bs) {
		buffer = bs;
		this.baseName = name;
		this.file = null;
		this.size = bs.length;
		this.isFile = false;		
	}


	public byte [] getContents() {

		if(buffer == null) {
			if(streamName != null) {
				try {
					loadStream();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			if(zipEntry != null) {
				//Log.d(TAG, "Entry  '%s' %d\n", zipEntry.getName(), zipEntry.getSize());
				InputStream is = zipFile.getInputStream(zipEntry);
				buffer = new byte[(int) size];
				try {
					is.read(buffer);
					is.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			} else {
				size = (int) file.length();
				buffer = new byte[(int) size];
				try {
					FileInputStream fis = new FileInputStream(file);
					fis.read(buffer);
					fis.close();
				} catch (IOException e) {
					e.printStackTrace();
				}

			}
		}
		return buffer;
		
	}
	
	public int getLength() {
		if(size == -1)
			getContents();
		return (int) size;
	}
	
	public File getFile() {
		
		if(file == null) {
			
			if(streamName != null) {
				try {
					loadStream();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				return file;
			}
			
			getContents();			
			createParentDir();
			FileOutputStream fos;
			try {
				file = new File(parentDir, baseName);
				fos = new FileOutputStream(file);
				fos.write(buffer);
				fos.flush();
				fos.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
			
		}
		
		return file;
	}
	
	public boolean isStream() {
		return (streamName != null);
	}
		
	private void createParentDir() {
		if(parentDir == null) {			
			File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
			File tempDir = new File(droidDir, "tempmusic");
			//if(!tempDir.exists())
			//	tempDir.mkdir();
			parentDir = new File(tempDir, "music" + Long.toString(System.nanoTime()));
			parentDir.mkdirs();
		}
	}

	public String getName() {
		return baseName;
	}
	
	public FileSource getRelative(String name) {
		FileSource fs = null;
		
		createParentDir();
		if(isFile) {
			File file2 = new File(file.getParentFile(), name);
			fs = new FileSource(file2);			
		} else if(zipFile != null) {			
			fs = new FileSource(zipFile, zipDir + name);
		}
		if(fs != null) {
			fs.setParentDir(parentDir);
		}
		return fs;
	}

	private void setParentDir(File pd) {
		parentDir = pd;
		leaveParentDir = true;
	}

	public String getExt() {
		String ext = "";
		int dot = baseName.lastIndexOf('.');
		if(dot > 0) {
			ext = baseName.substring(dot+1);
			//Log.d(TAG, "EXT: " + ext);
			char c = 'X';
			int e = 0;
			while(e < ext.length() && Character.isLetterOrDigit(c)) {
				e++;
				if(e == ext.length())
						break;
				c = ext.charAt(e);
			}
			ext = ext.substring(0,e);
			//Log.d(TAG, "EXT NOW: " + ext);
		}
		return ext.toUpperCase();
	}

	public boolean isFile() {
		return isFile;
	}

	public void read(byte[] data) throws IOException {
		if(buffer != null) {
			System.arraycopy(buffer, bufferPos, data, 0, data.length);
			bufferPos += data.length;
		} else if(inputStream != null) {
			inputStream.read(data);
		} else if(file !=null) {
			inputStream = new FileInputStream(file);
			inputStream.read(data);
		} else if(zipEntry != null) {
			//Log.d(TAG, "Entry  '%s' %d\n", zipEntry.getName(), zipEntry.getSize());
			inputStream = zipFile.getInputStream(zipEntry);
			inputStream.read(data);
		}
	}

	public void close() {
		if(inputStream != null)
			try {
				inputStream.close();
			} catch (IOException e) {
			}
		inputStream = null;
		if(parentDir != null && !leaveParentDir) {			
			File [] files = parentDir.listFiles();
			for(File f : files) {
				f.delete();
			}
			parentDir.delete();			
		}
		parentDir = null;
		
		if(zipFile != null && zipPath != null)  {			
			//if(zipFile != cachedZipFile)
			zipFile.close();			
		}

	}

	private boolean loadStream() throws IOException {
		
		try {
			URL url = new URL(streamName);
	
			//Log.d(TAG, "Opening URL " + songName);
	
			URLConnection conn = url.openConnection();
			if(!(conn instanceof HttpURLConnection))
				throw new IOException("Not a HTTP connection");
	
			HttpURLConnection httpConn = (HttpURLConnection) conn;
			httpConn.setAllowUserInteraction(false);
			httpConn.setInstanceFollowRedirects(true);
			httpConn.setRequestMethod("GET");
	
			Log.d(TAG, "Connecting");
	
			httpConn.connect();
	
			int response = httpConn.getResponseCode();
			if(response == HttpURLConnection.HTTP_OK) {
				int rc;
				byte[] temp = new byte[16384];
				Log.d(TAG, "HTTP connected");
				InputStream in = httpConn.getInputStream();
	
				// URLUtil.guessFileName(songName, );
				
				createParentDir();
	
				file = new File(parentDir, baseName);
								
				FileOutputStream fos = new FileOutputStream(file);
				BufferedOutputStream bos = new BufferedOutputStream(fos, temp.length);
				while((rc = in.read(temp)) != -1) {
					bos.write(temp, 0, rc);
				}
				bos.flush();
				bos.close();
	
				size = (int) file.length();
	
				Log.d(TAG, "Bytes written: " + size);
	
				buffer = new byte[(int) size];
				FileInputStream fs = new FileInputStream(file);
				fs.read(buffer);
				fs.close();
				
				return true;
			}
			
		} catch (MalformedURLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}

	public String getStreamName() {
		return streamName;
	}


	
}
