package com.ssb.droidsound.test;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class Utils {
	public static void removeDir(File dir) {		
		File [] files = dir.listFiles();
		if(files != null) {
			for(File f : files) {
				if(f.isFile())
					f.delete();
				else
					removeDir(f);
			}
			dir.delete();
		}		
	}
	
	public static File dumpFile(File outFile, InputStream is) throws IOException {
				
		FileOutputStream os = new FileOutputStream(outFile);
		byte[] buffer = new byte[1024 * 64];

		int rc = 0;
		while(rc >= 0) {
			rc = is.read(buffer);
			if(rc > 0) {
				os.write(buffer, 0, rc);
			}
		}
		os.close();
		is.close();
		
		return outFile;
	}

	public static String readAsset(String name) {
		InputStream is;
		String s = null;
		try {
			is = activity.getAssets().open(name);
			byte [] data = new byte [is.available()];        
	        is.read(data);
	        is.close();
	        s = new String(data, "ISO8859_1");
		} catch (IOException e) {
			e.printStackTrace();
		}
		return s;
	}
	
	

}
