package com.ssb.droidsound.test;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;

import com.ssb.droidsound.file.FileSource;
import com.ssb.droidsound.file.ZipFileSource;
import com.ssb.droidsound.plugins.SidPlugin;
import com.ssb.droidsound.utils.Unzipper;

import android.os.Environment;
import android.test.InstrumentationTestCase;

public class PackTest extends InstrumentationTestCase {

	private File tempDir;

	@Override
	protected void setUp() throws Exception {
		super.setUp();
		File f = Environment.getExternalStorageDirectory();
		tempDir = new File(f, "packtest" + System.nanoTime());
		if(!tempDir.mkdir())
			throw new RuntimeException();
	}
	
	public void testUnzip() throws InterruptedException, IOException {

		
		InputStream is = getInstrumentation().getContext().getAssets().open("Examples.zip");		
		File outFile = new File(tempDir, "Examples.zip");		
		Utils.dumpFile(outFile, is);

		FileSource fs = new ZipFileSource(outFile.getPath(), "C64/Mutants.sid");

		Unzipper unzipper = Unzipper.getInstance();
		unzipper.unzipAssetAsync(getInstrumentation().getContext(), "vice.zip", tempDir);
		unzipper.unzipAssetAsync(getInstrumentation().getContext(), "Examples.zip", tempDir);

		SidPlugin plugin = new SidPlugin();

		if(!plugin.load(fs))
			throw new RuntimeException();
		
		while(!unzipper.checkJob("Examples.zip")) {
			Thread.sleep(500);
		}
		
		while(!unzipper.checkJob("vice.zip")) {
			Thread.sleep(500);
		}
		
		short [] samples = new short [1024];
		plugin.getSoundData(samples, samples.length);

	}
	
}
