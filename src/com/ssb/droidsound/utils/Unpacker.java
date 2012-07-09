package com.ssb.droidsound.utils;

import java.io.File;
import java.io.IOException;

public class Unpacker {
	@SuppressWarnings("unused")
	private static final String TAG = Unpacker.class.getSimpleName();
	
	public static Archive openArchive(File path) throws IOException {		
		return new NativeZipFile(path);
	}
	

}
