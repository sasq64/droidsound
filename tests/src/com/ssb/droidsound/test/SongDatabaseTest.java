package com.ssb.droidsound.test;

import java.io.File;
import java.io.IOException;

import android.content.Context;
import android.content.res.AssetManager;
import android.database.Cursor;
import android.os.Environment;
import android.test.InstrumentationTestCase;

import com.ssb.droidsound.database.CSDBParser;
import com.ssb.droidsound.database.MediaSource;
import com.ssb.droidsound.database.ScanCallback;
import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.plugins.DroidSoundPlugin;

public class SongDatabaseTest extends InstrumentationTestCase {

	private SongDatabase songDatabase;
	private Thread dbThread;
	private File dbFile;
	private File modsDir;
	private AssetManager assets;
	private File tempDir;
	private volatile boolean scanDone;

	@Override
	protected void setUp() throws Exception {
		super.setUp();
		
		Context ctx = getInstrumentation().getContext();
		
		DroidSoundPlugin.setContext(ctx);
		
		assets = ctx.getAssets();
		
		File f = Environment.getExternalStorageDirectory();
		tempDir = new File(f, "testdb" + System.nanoTime());
		if(!tempDir.mkdir())
			throw new RuntimeException();
		dbFile = new File(tempDir, "testsongs.db");
		modsDir = new File(tempDir, "TESTMODS");
		if(!modsDir.mkdir())
			throw new RuntimeException();
		
		songDatabase = new SongDatabase(ctx, dbFile);

		CSDBParser csdb = new CSDBParser();
		songDatabase.registerDataSource(CSDBParser.DUMP_NAME, csdb);
		songDatabase.registerDataSource(CSDBParser.DUMP_NAME + ".ZIP", csdb);

		MediaSource ms = new MediaSource(ctx);
		songDatabase.registerDataSource(MediaSource.NAME, ms);

		dbThread = new Thread(songDatabase);
		dbThread.start();

		while(!songDatabase.isReady()) {
			try {
				Thread.sleep(100);
			} catch (InterruptedException e1) {
				e1.printStackTrace();
			}
		}		
	}
	
	@Override
	protected void tearDown() throws Exception {
		super.tearDown();		
		
		songDatabase.closeDB();
		
		Utils.removeDir(tempDir);		
	}
	
	public void testScan() throws IOException, InterruptedException {
		
		String [] mods = assets.list("music");
		
		for(String m : mods) {
			Utils.dumpFile(new File(modsDir, m), assets.open("music/" + m));
		}
		
		scanDone = false;
		
		songDatabase.setScanCallback(new ScanCallback() {
			@Override
			public void notifyScan(String path, int percent) {
				if(percent == -1)
					scanDone = true;
			}
		});
		
		songDatabase.scan(false, modsDir.getPath());
		while(!scanDone) {
			Thread.sleep(100);
		}
		
		Cursor cursor;
		int count;
		
		cursor = songDatabase.getFilesInPath(modsDir.getPath(), 0);
		count = cursor.getCount();
		
		cursor = songDatabase.search("music", "", 0);
		count = cursor.getCount();
	}
	
}
