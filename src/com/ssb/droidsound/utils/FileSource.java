package com.ssb.droidsound.utils;

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

import android.os.Environment;

public abstract class FileSource {

	
	private static final String TAG = FileSource.class.getSimpleName();
	
	private File file;
	private InputStream inputStream;
	private byte[] buffer;
	int bufferPos;
	long size;

	private File parentDir;


	private boolean isFile;

	private String baseName;

	private boolean leaveParentDir;

	private String reference;
	

	public FileSource(String ref) {
		reference = ref;
		int slash = ref.lastIndexOf('/');
		baseName = ref.substring(slash + 1);		
	}

	public static FileSource create(String ref) {

		FileSource fs;
		

		if(ref.toLowerCase().contains(".zip/")) {
			fs = new ZipFileSource(ref);
		} else if(ref.toLowerCase().startsWith("http")) {
			fs = new StreamSource(ref);
		} else {
			fs = new RealFileSource(new File(ref));
		}

		return fs;		
	}
	
	public static FileSource fromFile(File f) {
		return new RealFileSource(f);
	}
	
	public static FileSource fromData(String name, byte[] bs) {
		return new DataFileSource(name, bs);
	}

	
	//protected boolean init(String fileRef) { return false; }	
	protected File intGetFile() { return null; }
	protected byte [] intGetContents() { return null; }
	protected InputStream intGetStream() { return null; }
	protected FileSource intGetRelative(String name) { return null; }

	



	public FileSource(String name, byte[] bs) {
		buffer = bs;
		this.baseName = name;
		this.file = null;
		this.size = bs.length;
		this.isFile = false;		
	}


	public byte [] getContents() {

		if(buffer == null) {
			
			buffer = intGetContents();
			long size = getLength();
			if(buffer == null) {
				InputStream is = intGetStream();
				if(is != null) {
					buffer = new byte[(int) size];
					try {
						is.read(buffer);
						is.close();
					} catch (IOException e) {
						e.printStackTrace();
					}
				} else {
					File f = intGetFile();
					if(f != null) {
						buffer = new byte[(int) size];
						try {
							FileInputStream fis = new FileInputStream(f);
							fis.read(buffer);
							fis.close();
						} catch (IOException e) {
							e.printStackTrace();
						}
					}
				}
			}	

		}
		return buffer;
		
	}
	
	public long getLength() {
		return -1;
	}
	
	public File getFile() {
		
		if(file == null) {
			
			// First see if we can get the file directly
			file = intGetFile();
			if(file != null) {
				return file;
			}

			createParentDir();

			file = new File(parentDir, baseName);
			
			if(buffer == null)
				buffer = intGetContents();
			
			if(buffer == null)
				getContents();
				
			FileOutputStream fos;
			try {
				
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
		
		// First try the internal function
		fs = intGetRelative(name);
		
		createParentDir();
		
		if(fs == null) {
			// Otherwise, try creating a relative file manually
			if(file == null)
				file = intGetFile();
			if(file != null) {
				fs = fromFile(new File(file.getParentFile(), name));
			}
		}

		if(fs != null)
			fs.setParentDir(parentDir);
		
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

	public int read(byte[] data) throws IOException {
		if(buffer != null) {
			System.arraycopy(buffer, bufferPos, data, 0, data.length);
			bufferPos += data.length;
			return data.length;
		} 
		
		inputStream = intGetStream();		
		if(inputStream != null) {
			return inputStream.read(data);
		}
			
		file = intGetFile();
		if(file !=null) {
			inputStream = new FileInputStream(file);
			return inputStream.read(data);
		}
		return -1;
	}

	public void close() {
		if(inputStream != null)
			try {
				inputStream.close();
			} catch (IOException e) {
			}
		inputStream = null;
		/*
		if(parentDir != null && !leaveParentDir) {			
			File [] files = parentDir.listFiles();
			for(File f : files) {
				f.delete();
			}
			parentDir.delete();			
		}*/
		
		parentDir = null;

	}

	private boolean loadStream() throws IOException {
		
		try {
			URL url = new URL("");
	
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


	public String getReference() {
		return reference;
	}


}
