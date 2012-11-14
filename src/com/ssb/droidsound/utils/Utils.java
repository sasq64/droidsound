package com.ssb.droidsound.utils;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

import android.content.Context;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

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

	public static void dumpFile(File outFile, byte[] bindata) {
		FileOutputStream os;
		try {
			os = new FileOutputStream(outFile);
			os.write(bindata);
			os.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}


	public static String readAsset(Context ctx, String name) {
		InputStream is;
		String s = null;
		try {
			is = ctx.getAssets().open(name);
			byte [] data = new byte [is.available()];        
	        is.read(data);
	        is.close();
	        s = new String(data, "ISO8859_1");
		} catch (IOException e) {
			e.printStackTrace();
		}
		return s;
	}

	public static String readFile(File f) {
		FileInputStream is;
		String contents = null;
		try {
			is = new FileInputStream(f);
			byte [] data = new byte [is.available()];        
	        is.read(data);
	        is.close();
	        contents = new String(data, "ISO8859_1");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return contents;
	}

	public static Bitmap getBitmapFromAsset(Context context, String strName) {
	    AssetManager assetManager = context.getAssets();

	    InputStream istr;
	    Bitmap bitmap = null;
	    try {
	        istr = assetManager.open(strName);
	        bitmap = BitmapFactory.decodeStream(istr);
	    } catch (IOException e) {
	        return null;
	    }

	    return bitmap;
	}			
	
	

}
