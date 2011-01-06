package com.ssb.droidsound.utils;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Enumeration;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import android.content.Context;
import android.util.Log;

public class Unzipper {

	private static final String TAG = Unzipper.class.getSimpleName();
	
	//private static Object lock = new Object();

	//
	synchronized public static boolean unzipAsset(Context context, String asset, File targetDir) {
		
		File tempFile = null;
		try {			
			tempFile = new File(targetDir, asset);
			
			FileOutputStream os;
			os = new FileOutputStream(tempFile);

			InputStream is = context.getAssets().open(asset);
			
			byte [] buffer = new byte [128*1024];
			while(true) {
				int rc = is.read(buffer);
				if(rc <= 0) {
					break;
				}
				os.write(buffer, 0, rc);
			}
			is.close();
			os.close();
			
			ZipFile zf = new ZipFile(tempFile);
			Enumeration<? extends ZipEntry> entries = zf.entries();
			while(entries.hasMoreElements()) {
				ZipEntry entry = entries.nextElement();
				is = zf.getInputStream(entry);
				String name = entry.getName();	
				File efile = new File(targetDir, name);
				
				Log.v(TAG, String.format("Extracting %s / %s", name, efile.getPath()));
				
				if(name.endsWith("/")) {
					continue;
				}
				
				efile.getParentFile().mkdirs();
				
				os = new FileOutputStream(efile);

				while(true) {
					int rc = is.read(buffer);
					if(rc <= 0) {
						break;
					}
					os.write(buffer, 0, rc);
				}
				is.close();
				os.close();
			}			
			tempFile.delete();
			return true;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		if(tempFile != null)
			tempFile.delete();
		return false;		
	}

	public void unzipAssetAsync(Context context, String asset, File targetDir) {
/*		
		thread = new Runnable() {
			@Override
			public void run() {
				unzipAsset(context, asset, targetDir);
			}
		}; */
		
		
	}

	
	
}
