package com.ssb.droidsound.utils;

import java.io.File;


import android.util.Log;

public class ID3Tag {
	private static final String TAG = ID3Tag.class.getSimpleName();
	
	static {
		System.loadLibrary("id3tag");
	}
	
	private long id3Ref;

	public ID3Tag(File path) {
		Log.v(TAG, String.format("ID3Tag on %s", path.getPath()));
		openID3Tag(path.getPath());		
	}
	
	@Override
	protected void finalize() throws Throwable {
		closeID3Tag();
		super.finalize();
	}
	
	
	//public String getStringInfo(int what) {
	//}
	//public int getIntInfo(int what) {		
	//	return getI
	//}
	
	
	native boolean openID3Tag(String fileName);
	native void closeID3Tag();
	native public String getStringInfo(int what);
	native public int getIntInfo(int what);
	
	
}
