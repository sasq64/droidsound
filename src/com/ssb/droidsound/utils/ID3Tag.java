package com.ssb.droidsound.utils;

import java.io.File;


import com.ssb.droidsound.utils.Log;

public class ID3Tag {
	
	private static final String TAG = ID3Tag.class.getSimpleName();
	
	static {
		System.loadLibrary("id3tag");
	}
	
	
	public static final int ID3INFO_GENRE = 100;
	public static final int ID3INFO_COMMENT = 101;
	public static final int ID3INFO_ALBUM = 102;
	public static final int ID3INFO_TRACK = 103;

	
	private long id3Ref;
	private long tagRef;

	public ID3Tag(File path) {
		Log.d(TAG, "ID3Tag on %s", path.getPath());
		openID3Tag(path.getPath());		
	}
	
	public ID3Tag() {
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

	public native int checkForTag(byte [] data, int offset, int len);	
	public native boolean parseTag(byte [] data, int offset, int len);
	
	
	native boolean openID3Tag(String fileName);
	native void closeID3Tag();
	native public String getStringInfo(int what);
	native public int getIntInfo(int what);
	native public byte [] getBinaryInfo(int what);
	
	
}
