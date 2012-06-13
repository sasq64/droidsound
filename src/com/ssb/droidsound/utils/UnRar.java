package com.ssb.droidsound.utils;

public class UnRar {
	private static final String TAG = UnRar.class.getSimpleName();
	static {
		System.loadLibrary("unrar");
	}

	private String archive;


	public UnRar(String fileName) {
		archive = fileName;
	}
	
	public boolean extractTo(String target) {
		int rc = N_extractAll(archive, target);
		return rc == 0;
	}
	
	
	native int N_extractAll(String archive, String target);
}
