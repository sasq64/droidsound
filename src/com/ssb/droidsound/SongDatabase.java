package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import android.content.ContentValues;
import android.content.Context;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.provider.BaseColumns;
import android.util.Log;

/**
 * 
 * SCANNING:
 * 
 * Enter only directories that have changed since last time Check all files and
 * dirs in directory against database entry. Remove missing, add new Enter new
 * directories regardless of modified.
 * 
 */

public class SongDatabase {
	private static final String TAG = SongDatabase.class.getSimpleName();

	private static class DbHelper extends SQLiteOpenHelper {

		public DbHelper(Context context) {
			super(context, "songs", null, 1);
		}

		@Override
		public void onCreate(SQLiteDatabase db) {
			db.execSQL("CREATE TABLE " + "SONGS" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," + "TITLE"
					+ " TEXT," + "COMPOSER" + " TEXT," + "COPYRIGHT" + " TEXT," + "PRODUCT" + " TEXT," + "FORMAT"
					+ " TEXT," + "LENGTH" + " INTEGER," + "PATH" + " TEXT," + "FILENAME" + " TEXT" + ");");
		}

		@Override
		public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
			// TODO Auto-generated method stub

		}
	}

	private DbHelper mOpenHelper;
	private SQLiteDatabase db;
	private SQLiteDatabase rdb;
	private long lastScan;
	private Context mContext;
	private DroidSoundPlugin[] plugins;

	SongDatabase(Context context) {
		mOpenHelper = new DbHelper(context);
		mContext = context;
	}

	private boolean checkModule(File file, ContentValues values) throws IOException {
		List<DroidSoundPlugin> list = new ArrayList<DroidSoundPlugin>();
		for(int i = 0; i < plugins.length; i++) {
			if(plugins[i].canHandle(file.getName())) {
				list.add(plugins[i]);
				Log.v(TAG, String.format("%s handled by %d", file.getName(), i));
			}
		}
		if(file.length() > 2 * 1024 * 1024) {
			System.gc();
		}

		for(DroidSoundPlugin plugin : list) {
			Log.v(TAG, "Trying " + plugin.getClass().getName());
			if(plugin.loadInfo(file)) {
				String title = plugin.getStringInfo(DroidSoundPlugin.INFO_TITLE);
				String author = plugin.getStringInfo(DroidSoundPlugin.INFO_AUTHOR);
				String copyright = plugin.getStringInfo(DroidSoundPlugin.INFO_COPYRIGHT);
				String game = plugin.getStringInfo(DroidSoundPlugin.INFO_GAME);
				String type = plugin.getStringInfo(DroidSoundPlugin.INFO_TYPE);
				int length = plugin.getIntInfo(DroidSoundPlugin.INFO_LENGTH);

				Log.v(TAG, String.format("Got Info T:%s, A:%s, C:%s, (%d)", title, author, copyright, length));

				values.put("TITLE", title);
				values.put("COMPOSER", author);
				values.put("COPYRIGHT", copyright);
				values.put("PRODUCT", game);
				values.put("FORMAT", type);
				values.put("LENGTH", length);
				values.put("PATH", file.getParentFile().getPath());
				values.put("FILENAME", file.getName());

				return true;
			}
		}
		
		values.put("FORMAT", "Unknown");
		values.put("PATH", file.getParentFile().getPath());
		values.put("FILENAME", file.getName());
		
		return true;
	}

	private void updateFile(File f) {
		ContentValues values = new ContentValues();
		try {
			if(checkModule(f, values)) {
				Log.v(TAG, "Inserting...");
				db.insert("SONGS", "NAME", values);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private void scanFiles(File parentDir) {
				
		String parent = parentDir.getPath();
		
		Log.v(TAG, String.format("Entering '%s'", parent));

		Set<String> files = new HashSet<String>();

		// Get all files from in this Path from the database
		Cursor x = rdb.query("SONGS", new String[] { "FILENAME" }, "PATH=?", new String[] { parent },
				null, null, null);

		// Add all existing files to a hash set
		for(File f : parentDir.listFiles()) {
			if(!f.isDirectory()) {
				files.add(f.getName());
			}
		}
		
		Log.v(TAG, String.format("Datbase has %d entries, found %d files", x.getCount(), files.size()));

		
		Set<String> deletes = new HashSet<String>();
		
		int index = x.getColumnIndex("FILENAME");
		// Iterate over database result and compare to hash set
		while(x.moveToNext()) {
			String fileName = x.getString(index);
			//Log.v(TAG, String.format("fileName '%s'", fileName));
			if(files.contains(fileName)) {
				// File is in both - all is OK
				files.remove(fileName);
			} else {
				Log.v(TAG, String.format("'%s' found in DB but not on disk, DELETING", fileName));
				// File has been removed on disk, schedule for DELETE
				deletes.add(fileName);
			}

			//x.moveToNext();
		}
		
		for(String s : files) {
			Log.v(TAG, String.format("!! File '%s' not in database", s));
		}

		// Close cursor (important since we call ourselves recursively below)
		x.close();
		x = null;

		if(files.size() > 0 || deletes.size() > 0) {
			// We have database operations to perform
			db.beginTransaction();
			try {
				
				for(String d : deletes) {
					Log.v(TAG, "Deleting...");
					db.delete("SONGS", "PATH=? AND FILENAME=?", new String [] { parent, d} );
				}

				// Iterate over added files
				for(String s : files) {
					File f = new File(parentDir, s);
					ContentValues values = new ContentValues();
					try {
						if(checkModule(f, values)) {
							Log.v(TAG, "Inserting...");
							db.insert("SONGS", "NAME", values);
						}
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
				Log.v(TAG, "TRANSATION SUCCESSFUL");
				db.setTransactionSuccessful();
				
			} finally {
				db.endTransaction();
			}
		}

		files = null;

		for(File f : parentDir.listFiles()) {
			if(f.isDirectory()) {
				//if(f.lastModified() > lastScan) {
					scanFiles(f);
				//} else {
				//	Log.v(TAG, String.format("Will not enter unchanged directory '%s'", f.getPath())); 
				//}
			}
		}
	}

	public void scan() {
		File f = new File("/sdcard/MODS");

		//SharedPreferences prefs = mContext.getSharedPreferences("songdb", Context.MODE_PRIVATE);
		//lastScan = prefs.getLong("lastScan", 0);

		//Log.v(TAG, String.format("lastScan %d vs %d", lastScan, System.currentTimeMillis()));
		//lastScan = 0;
		//if(f.lastModified() > lastScan) {

			plugins = new DroidSoundPlugin[3];
			plugins[0] = new TinySidPlugin();
			plugins[1] = new ModPlugin();
			plugins[2] = new GMEPlugin();

			rdb = mOpenHelper.getReadableDatabase();
			db = mOpenHelper.getWritableDatabase();
			long startTime = System.currentTimeMillis();
			scanFiles(f);
			//SharedPreferences.Editor editor = prefs.edit();
			//editor.putLong("lastScan", startTime);
			//editor.commit();
			//lastScan = startTime;

			db.close();
			rdb.close();
		//} else {
		//	Log.v(TAG, "No need to scan files");
		//}

	}

}
