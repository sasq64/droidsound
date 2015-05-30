package com.ssb.droidsound.file;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Locale;

import com.ssb.droidsound.utils.DataFileSource;
import com.ssb.droidsound.utils.Log;

public abstract class FileSource {
	private static final String TAG = FileSource.class.getSimpleName();
	
	private File file;
	private InputStream inputStream;
	private byte[] buffer;
	int bufferPos;
	long size;
	protected boolean isValid;

	//private File parentDir;


	private boolean isFile;

	private String baseName;

	//private boolean leaveParentDir;

	private String reference;

	private CharSequence refPath;
	

	public FileSource(String ref) {
		reference = ref;
		int slash = ref.lastIndexOf('/');
		baseName = ref.substring(slash + 1);
		refPath = slash > 0 ? ref.subSequence(0, slash+1) : "";
		isValid = true;
	}

	public static FileSource create(String ref) {

		FileSource fs;
		

		if(ref.toLowerCase().startsWith("http")) {
			fs = new StreamSource(ref);
		} else if(ref.toLowerCase(Locale.ENGLISH).contains(".zip/")) {
			fs = new ZipFileSource(ref);
		} else {
			fs = new RealFileSource(new File(ref));
		}
		if(fs.isValid)
			return fs;
		return null;
	}

	public static FileSource fromFile(File f) {
		return new RealFileSource(f);
	}
	
	public static FileSource fromData(String name, byte[] bs) {
		return new DataFileSource(name, bs);
	}
	
	public static FileSource fromStream(String name, InputStream is) {
		return new StreamFileSource(name, is);
	}


	
	//protected boolean init(String fileRef) { return false; }	
	protected File intGetFile() { return null; }
	protected byte [] intGetContents() { return null; }
	protected InputStream intGetStream() throws IOException { return null; }
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
			size = getLength();
			if(buffer == null) {
				InputStream is = null;
				try {
					is = intGetStream();
				} catch (IOException e1) {
				}
				if(is != null) {
					
					
					ByteArrayOutputStream bs = new ByteArrayOutputStream();
					byte [] data = new byte [16384];
					int n;
					try {
						while ((n = is.read(data, 0, data.length)) > 0) {
							bs.write(data, 0, n);
						}
						bs.flush();
						is.close();
						buffer = bs.toByteArray();
						size = buffer.length;
					} catch (IOException e) {
						e.printStackTrace();
					}
				} else {
					getFile();
					if(buffer == null) {
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
			}	

		}
		return buffer;
		
	}
	
	public long getLength() {
		return size;
	}
	
	public File getFile() {
		
		if(file == null) {
			
			/*file = FileCache.getInstance().getFile(reference);
			if(file != null) {
				size = file.length();
				Log.d(TAG, "Found %s in cache: %s (%d)", reference, file.getPath(), file.length());
				return file;
			}*/
			
			// First see if we can get the file directly
			file = intGetFile();
			if(file != null) {
				size = file.length();
				return file;
			}

			
			//file = FileCache.getInstance().createFile(baseName);
			
			//createParentDir();
			//file = new File(parentDir, baseName);
			file = FileCache.getInstance().getFile(reference);			
			
			if(file.exists()) {
				Log.d(TAG, "LUCKY! File '%s' exists already\n", file.getPath());
				return file;
			}
			
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
			
			//FileCache.getInstance().putFile(reference, file);
			
		}
		
		return file;
	}
	
	/*
	private void createParentDir() {

		String exDir = Environment.getExternalStorageDirectory().getPath();
		
		String path = reference;
		if(path.indexOf("http://") == 0) {
			path = path.substring(7);
		}
		if(path.indexOf(exDir) == 0) {
			path = path.substring(exDir.length());
		}
		if(path.indexOf("/") == 0) {
			path = path.substring(1);
		}
		
		int slash = path.lastIndexOf('/');
		if(slash >= 0)
			path = path.substring(0, slash);
		
		if(parentDir == null) {			
			//File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
			//File tempDir = new File(droidDir, "tempmusic");
			//if(!tempDir.exists())
			//	tempDir.mkdir();
			//parentDir = new File(tempDir, "music" + Long.toString(System.nanoTime()));
			parentDir = new File(exDir + "/droidsound/tempmusic/" + path);
			Log.d(TAG, "Created dir '%s'", parentDir.getPath());
			parentDir.mkdirs();
		}
	}*/

	public String getName() {
		return baseName;
	}
	
	public FileSource getRelative(String name) {
		FileSource fs = null;
		
		// First try the internal function
		fs = intGetRelative(name);
		
		//createParentDir();
		
		if(fs == null) {
			// Otherwise, try creating a relative file manually
			if(file == null) {
				fs = FileSource.create(refPath + name);				
				//file = intGetFile();
			} else {
				fs = fromFile(new File(file.getParentFile(), name));
			}
		}

		//if(fs != null)
		//	fs.setParentDir(parentDir);
		
		return fs;
	}

	//private void setParentDir(File pd) {
	//	parentDir = pd;
	//	leaveParentDir = true;
	//}

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
		return ext.toUpperCase(Locale.ENGLISH);
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
		
		/*if(parentDir != null && !leaveParentDir) {			
			File [] files = parentDir.listFiles();
			for(File f : files) {
				f.delete();
			}
			parentDir.delete();			
		}*/
		
		//parentDir = null;

	}

	public String getReference() {
		return reference;
	}



}
