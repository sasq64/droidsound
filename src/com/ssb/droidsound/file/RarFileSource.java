package com.ssb.droidsound.file;

import java.util.Locale;

import com.ssb.droidsound.utils.UnRar;

public class RarFileSource extends FileSource {

	private String rarPath;
	@SuppressWarnings("unused")
	private UnRar rarFile;

	public RarFileSource(String ref) {
		super(ref);
		
		int ext = ref.toLowerCase(Locale.ENGLISH).indexOf(".rar/");
		if(ext < 0) return;
		rarPath = ref.substring(0, ext+4);
		//String entryName = ref.substring(ext+5);
		
		rarFile = new UnRar(rarPath);
		
		
	}
	
	

}
