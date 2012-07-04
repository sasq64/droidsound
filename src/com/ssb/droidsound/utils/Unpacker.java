package com.ssb.droidsound.utils;

import java.io.File;
import java.io.IOException;

public class Unpacker {
	@SuppressWarnings("unused")
	private static final String TAG = Unpacker.class.getSimpleName();
	
	public static Archive openArchive(File path) {
		
		NativeZipFile lastZip = null;
		try {
			//if(lastZip != null && lastZip.getZipName().equals(path.getPath())) {
			//	Log.d(TAG, "Reusing last zip");
			//} else {			
				lastZip = new NativeZipFile(path);
			//}
		} catch (IOException e) {
			e.printStackTrace();
		}
		return lastZip;
	}
	

}
