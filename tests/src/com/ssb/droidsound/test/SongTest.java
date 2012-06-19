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
import com.ssb.droidsound.plugins.GMEPlugin;
import com.ssb.droidsound.plugins.ModPlugin;
import com.ssb.droidsound.plugins.RSNPlugin;
import com.ssb.droidsound.plugins.SC68Plugin;
import com.ssb.droidsound.plugins.SexyPSFPlugin;
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

	public void testPSF() throws IOException {		
		SexyPSFPlugin plugin = new SexyPSFPlugin();		
		InputStream is = getInstrumentation().getContext().getAssets().open("music/music.psf");
		playSong(plugin, FileSource.fromStream("music.psf", is));
	}

	public void testSNDH() throws IOException {		
		SC68Plugin plugin = new SC68Plugin();		
		InputStream is = getInstrumentation().getContext().getAssets().open("music/music.sndh");
		playSong(plugin, FileSource.fromStream("music.sndh", is));
	}
	
	public void testNSFE() throws IOException {		
		GMEPlugin plugin = new GMEPlugin();		
		InputStream is = getInstrumentation().getContext().getAssets().open("music/music.nsfe");
		playSong(plugin, FileSource.fromStream("music.nsfe", is));
	}

	public void testCUST() throws IOException {		
		UADEPlugin plugin = new UADEPlugin();		
		InputStream is = getInstrumentation().getContext().getAssets().open("music/cust.music");
		playSong(plugin, FileSource.fromStream("cust.music", is));
	}

	
	public void testTFMX() throws IOException {	
		File m0 = Utils.dumpFile(new File(tempDir, "MDAT.music"), assets.open("music/MDAT.music")); 
		Utils.dumpFile(new File(tempDir, "SMPL.music"), assets.open("music/SMPL.music"));
		UADEPlugin plugin = new UADEPlugin();
		playSong(plugin, FileSource.fromFile(m0));
	}

	public void testRMU() throws IOException {	
		RSNPlugin plugin = new RSNPlugin();		
		InputStream is = getInstrumentation().getContext().getAssets().open("music/music.rmu");
		playSong(plugin, FileSource.fromStream("music.rmu", is), 3);
	}

	private void playSong(DroidSoundPlugin plugin, FileSource fs) {
		playSong(plugin, fs, 1);
	}

	private void playSong(DroidSoundPlugin plugin, FileSource fs, int subtunes) {

		assertTrue(plugin.canHandle(fs));
		
		assertTrue(plugin.load(fs));
		
		short [] samples = new short [8820]; // 0.1s
		int size;
		
		for(int k=0; k<subtunes; k++) {
			long check = 0;
	
			for(int j=0; j<20; j++) { // Run for 2 seconds
				size = plugin.getSoundData(samples, samples.length);
				assertTrue(size > 0); // All songs should be at least 2 seconds long
				for(int i=0; i<size; i++) {
					check += samples[i];
				}
			}
			assertTrue(check != 0);
			
			if(k<subtunes) {
				plugin.setTune(k+1);
			}			
		}
		
		plugin.unload();
	}

}
