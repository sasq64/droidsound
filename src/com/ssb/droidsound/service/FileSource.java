package com.ssb.droidsound.service;

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
	//private String zipPath;

	private byte[] buffer;
	long size;

	private File parentDir;

	private ZipEntry zipEntry;

	private boolean isFile;

	private String baseName;

	private String zipDir;

	public FileSource(File file) {
		this.file = file;
		this.size = file.length();
		this.isFile = true;
		this.baseName = file.getName();
		this.zipDir = null;
		this.zipFile = null;
	}
	
	public FileSource(NativeZipFile zip, String zipPath) {
		this.zipFile = zip;
		//this.zipPath = zipPath;
		this.isFile = false;
		if(zipFile != null) {
			zipEntry = zipFile.getEntry(zipPath);
			if(zipEntry != null) {
				Log.d(TAG, "Entry  '%s' %d\n", zipEntry.getName(), zipEntry.getSize());
				size = zipEntry.getSize();
			}
			
			int slash = zipPath.lastIndexOf('/');
			this.baseName = zipPath.substring(slash + 1);
			if(slash >= 0)
				this.zipDir = zipPath.substring(0,slash);
			else
				this.zipDir = "";
			
		}	
	}
	
	
	public byte [] getContents() {

		if(buffer == null) {
			if(zipEntry != null) {
				Log.d(TAG, "Entry  '%s' %d\n", zipEntry.getName(), zipEntry.getSize());
				InputStream fs = zipFile.getInputStream(zipEntry);
				buffer = new byte[(int) size];
				try {
					fs.read(buffer);
					fs.close();
				} catch (IOException e) {
					e.printStackTrace();
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
			
			if(parentDir != null) {			
				try {
					parentDir = File.createTempFile("music", Long.toString(System.nanoTime()));
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				parentDir.delete();
				parentDir.mkdir();
			}
			
			FileOutputStream fos;
			try {
				file = new File(parentDir, baseName);
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
	
	public void cleanUp() {
		if(parentDir != null) {			
			File [] files = parentDir.listFiles();
			for(File f : files) {
				f.delete();
			}
			parentDir.delete();			
		}
		parentDir = null;
	}
	
	public String getName() {
		return baseName;
	}
	
	public FileSource getRelative(String name) {
		if(isFile) {
			File file2 = new File(file.getParentFile(), name);
			return new FileSource(file2);			
		} else if(zipFile != null) {			
			return new FileSource(zipFile, zipDir + "/" + name);
		}
		return null;
	}

	public String getExt() {
		String ext = "";
		int dot = baseName.lastIndexOf('.');
		if(dot > 0) {
			ext = baseName.substring(dot+1);
			Log.d(TAG, "EXT: " + ext);
			char c = 'X';
			int e = 0;
			while(e < ext.length() && Character.isLetterOrDigit(c)) {
				e++;
				if(e == ext.length())
						break;
				c = ext.charAt(e);
			}
			ext = ext.substring(0,e);
			Log.d(TAG, "EXT NOW: " + ext);
		}
		return ext.toUpperCase();
	}

	public boolean isFile() {
		return isFile;
	}

	/* private boolean loadStream(String songName) throws IOException {
		
		try {
			URL url = new URL(songName);
	
			Log.d(TAG, "Opening URL " + songName);
	
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
				int size;
				byte[] buffer = new byte[16384];
				Log.d(TAG, "HTTP connected");
				InputStream in = httpConn.getInputStream();
	
				// URLUtil.guessFileName(songName, );
	
				//int dot = songName.lastIndexOf('.');
				String ext = DroidSoundPlugin.getExt(songName);
				File f = File.createTempFile("music", ext);
				FileOutputStream fos = new FileOutputStream(f);
				BufferedOutputStream bos = new BufferedOutputStream(fos, buffer.length);
				while((size = in.read(buffer)) != -1) {
					bos.write(buffer, 0, size);
				}
				bos.flush();
				bos.close();
	
				streamSize = (int) f.length();
	
				Log.d(TAG, "Bytes written: " + streamSize);
	
				byte [] songBuffer = new byte[(int) streamSize];
				FileInputStream fs = new FileInputStream(f);
				fs.read(songBuffer);
				fs.close();
				// f.delete();
				
				//songName = new File(songName).getName();
				
				//boolean rc = load(songName, songBuffer, streamSize);
				boolean rc = load(f);
				f.delete();
				return rc;
			}
			
		} catch (MalformedURLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
		public void calcMD5(byte[] songBuffer, int size) {
		
		MessageDigest md = null;
		Log.d(TAG, "MD5 CALCING TIME");
		try {
			md = MessageDigest.getInstance("MD5");
		} catch (NoSuchAlgorithmException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return;
		}		
		
		md.update(songBuffer, 0, size);
		md5 = md.digest();
	}
	public void calcMD5(byte[] songBuffer) {
		calcMD5(songBuffer, songBuffer.length);
	}

	*
	*/
	
}
