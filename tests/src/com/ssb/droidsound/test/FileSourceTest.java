package com.ssb.droidsound.test;

import com.ssb.droidsound.file.FileSource;

import junit.framework.TestCase;

public class FileSourceTest extends TestCase {
	
	public FileSourceTest() {
		super("com.ssb.droidsound");
	}
	
	
	public void testBasic() {
		
		byte[] bytes = new byte [1204];		
		FileSource fs = FileSource.fromData("test", bytes);
		assertNotNull(fs);
		fs.close();		
	}

}
