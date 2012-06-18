package com.ssb.droidsound.test;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

import android.content.res.AssetManager;
import android.os.Environment;
import android.test.InstrumentationTestCase;

import com.ssb.droidsound.file.FileSource;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.plugins.ModPlugin;
import com.ssb.droidsound.plugins.SidPlugin;
import com.ssb.droidsound.plugins.UADEPlugin;

public class SongTest extends InstrumentationTestCase {
	
	private File tempDir;
	private AssetManager assets; 
	
	@Override
    protected void setUp() throws Exception {
        super.setUp();
        
        File f = Environment.getExternalStorageDirectory();
        tempDir = new File(f, "testmusic" + System.nanoTime());
        tempDir.mkdir();
        assets = getInstrumentation().getContext().getAssets();
	}
	 
	 
	@Override
	protected void tearDown() throws Exception {
		super.tearDown();
		Utils.removeDir(tempDir);
	}
	 
	
	private File dumpFile(String name, InputStream is) throws IOException {
		
		File tempFile = new File(tempDir, name);		
		FileOutputStream os = new FileOutputStream(tempFile);
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
		
		return tempFile;
	}
	
	
	public void testMOD() throws IOException {		
		ModPlugin plugin = new ModPlugin();		
		InputStream is = getInstrumentation().getContext().getAssets().open("music/music.mod");
		playSong(plugin, FileSource.fromStream("music.mod", is));
	}
	
	public void testXM() throws IOException {		
		ModPlugin plugin = new ModPlugin();		
		InputStream is = getInstrumentation().getContext().getAssets().open("music/music.xm");
		playSong(plugin, FileSource.fromStream("music.xm", is));
	}

	public void testSID() throws IOException {		
		SidPlugin plugin = new SidPlugin();		
		InputStream is = getInstrumentation().getContext().getAssets().open("music/music.sid");
		playSong(plugin, FileSource.fromStream("music.sid", is));
	}

	public void testTFMX() throws IOException {	
		File m0 = dumpFile("MDAT.music", assets.open("music/MDAT.music")); 
		dumpFile("SMPL.music", assets.open("music/SMPL.music"));
		UADEPlugin plugin = new UADEPlugin();
		playSong(plugin, FileSource.fromFile(m0));
	}



	private void playSong(DroidSoundPlugin plugin, FileSource fs) {

		assertTrue(plugin.canHandle(fs));
		
		assertTrue(plugin.load(fs));
		
		short [] samples = new short [8820]; // 0.1s
		int size;
		long check = 0;

		for(int j=0; j<20; j++) { // Run for 2 seconds
			size = plugin.getSoundData(samples, samples.length);
			assertTrue(size > 0); // All songs should be at least 2 seconds long
			for(int i=0; i<size; i++) {
				check += samples[i];
			}
		}		
		assertTrue(check != 0);
	}

}
