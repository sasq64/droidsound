package com.ssb.droidsound.test;

import java.io.File;
import java.io.IOException;

import android.content.res.AssetManager;
import android.test.InstrumentationTestCase;

import com.ssb.droidsound.file.FileCache;
import com.ssb.droidsound.file.FileSource;

import junit.framework.TestCase;

public class FileSourceTest extends InstrumentationTestCase {
	
	private AssetManager assets;

	@Override
	protected void setUp() throws Exception {
		super.setUp();
        assets = getInstrumentation().getContext().getAssets();
	}
	
	@Override
	protected void tearDown() throws Exception {
		super.tearDown();
		FileCache.getInstance().purge();
	}
	
	
	public void testBasic() {
		
		byte[] bytes = new byte [1204];		
		FileSource fs = FileSource.fromData("test", bytes);
		assertNotNull(fs);
		fs.close();		
	}
	
	public void testFileCache() throws IOException {
		
		FileCache fc = FileCache.getInstance();
		
		fc.setLimitSize(1024*1024);
		
		File file0 = fc.getFile("music/SMPL.music");
		Utils.dumpFile(file0, assets.open("music/SMPL.music"));
		File file1 = fc.getFile("music.xm");
		Utils.dumpFile(file1, assets.open("music/music.xm"));
		File file2 = fc.getFile("dummy/test3");
		
		fc.setLimitSize(1024*5);
		
		
		
	}

}
