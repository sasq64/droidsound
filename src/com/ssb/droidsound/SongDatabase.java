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
			db.execSQL("CREATE TABLE " + "SONGS" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
					"TITLE" + " TEXT," +
					"COMPOSER" + " TEXT," +
					"COPYRIGHT" + " TEXT," +
					"FORMAT" + " TEXT," +
					"LENGTH" + " INTEGER," +
					"PATH" + " TEXT," +
					"FILENAME" + " TEXT" + ");");
			db.execSQL("CREATE TABLE " + "DIRS" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
					"FILENAME" + " TEXT," +
					"PATH" + " TEXT," +
					"FLAGS" + " INTEGER" + ");");
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
		
		if(file.getName().startsWith("I_Wanna_Dance")) {
			Log.v(TAG, "YO");
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
				
				if(title == null || title.equals("")) {
					title = game;
					Log.v(TAG, String.format("G Title '%s'", title));
					if(title == null || title.equals("")) {
						title = file.getName();
						if(title.contains(".")) {
							title = title.substring(0, title.lastIndexOf('.'));
						}
						Log.v(TAG, String.format("FN Title '%s'", title));
					}
				}

				Log.v(TAG, String.format("Got Info T:%s, A:%s, C:%s, (%d)", title, author, copyright, length));

				values.put("TITLE", title);
				values.put("COMPOSER", author);
				values.put("COPYRIGHT", copyright);
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
				db.insert("SONGS", "TITLE", values);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private boolean hasChanged(File f) {
		return (lastScan < f.lastModified());
	}

	private int scanFiles(File parentDir) {

		int dirCount = -1;
		String parent = parentDir.getPath();
		
		Log.v(TAG, String.format("Entering '%s'", parent));

		// We always need the directory from the database
		Cursor dirCursor = rdb.query("DIRS", new String[] { "FILENAME", "FLAGS" }, "PATH=?", new String[] { parent }, 
				null, null, null);
		

		if(hasChanged(parentDir)) {
			
			// This directory has changed so we need to list all files and compare them to the database

			Set<String> files = new HashSet<String>();
			// Add all existing files to a hash set
			for(File f : parentDir.listFiles()) {
				if(!f.isDirectory()) {
					files.add(f.getName());
				}
			}

			// Get all files from in this Path from the database
			Cursor songCursor = rdb.query("SONGS", new String[] { "FILENAME" }, "PATH=?", new String[] { parent },
					null, null, null);
	
			Log.v(TAG, String.format("Datbase has %d entries, found %d files", songCursor.getCount(), files.size()));
	
			Set<String> deletes = new HashSet<String>();
			
			int index = songCursor.getColumnIndex("FILENAME");
			// Iterate over database result and compare to hash set
			while(songCursor.moveToNext()) {
				String fileName = songCursor.getString(index);
				if(files.contains(fileName)) {
					// File is in both - all is OK
					files.remove(fileName);
				} else {
					Log.v(TAG, String.format("'%s' found in DB but not on disk, DELETING", fileName));
					// File has been removed on disk, schedule for DELETE
					deletes.add(fileName);
				}
			}
			
			for(String s : files) {
				Log.v(TAG, String.format("!! File '%s' not in database", s));
			}
	
			// Close cursor (important since we call ourselves recursively below)
			songCursor.close();
			songCursor = null;

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
								Log.v(TAG, String.format("Inserting FILE... (%s)", s));
								db.insert("SONGS", "TITLE", values);
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
		} else {
			Log.v(TAG, "!! Not scanning files");
		}

		/// Time to deal with directories				
		
		if(!hasChanged(parentDir)) {
			
			// This directory has not been changed - only enter non-leaf or modified directories	
			// Also we can safely iterate over the query instead of files since they should be in sync
			
			dirCount = dirCursor.getCount();
	
			int index = dirCursor.getColumnIndex("FILENAME");
			int flindex = dirCursor.getColumnIndex("FLAGS");
			// Iterate over database result and compare to hash set
			while(dirCursor.moveToNext()) {
				String fileName = dirCursor.getString(index);
				int flags = dirCursor.getInt(flindex);
				File f = new File(parentDir, fileName);
				if((flags == 0) || hasChanged(f)) {
					int c = scanFiles(f);
					Log.v(TAG, String.format("Found %d dirs", c));
					if(c == 0 && flags == 0) {
						Log.v(TAG, String.format("Tagging Directory '%s/%s' as LEAF", parent, fileName));
						ContentValues values = new ContentValues();
						values.put("FLAGS", 1);
						db.update("DIRS", values, "PATH=? AND FILENAME=?", new String[] { parent, fileName} );
					}
				} else {
					Log.v(TAG, String.format("Skipping unchanged leaf directory '%s/%s' as LEAF", parent, fileName));
				}
			}
						
			dirCursor.close();
			dirCursor = null;
			
		} else {

			// This directory has changed so we need to list all directories and compare them to the database
			
			Set<String> dirs = new HashSet<String>();

			// Add all existing dirs to a hash set
			for(File f : parentDir.listFiles()) {
				if(f.isDirectory()) {
					dirs.add(f.getName());
				}
			}
			
			dirCount = dirs.size();
			
			// TODO: We should not enter unchanged leaf directories here, and also found LEAF -> NON-LEAF change
			for(String s : dirs) {
				scanFiles(new File(parentDir, s));
			}			
			
			Set<String> deletes = new HashSet<String>();
			
			int index = dirCursor.getColumnIndex("FILENAME");
			// Iterate over database result and compare to hash set
			while(dirCursor.moveToNext()) {
				String fileName = dirCursor.getString(index);
				if(dirs.contains(fileName)) {
					// Directory is in both - all is OK
					dirs.remove(fileName);
				} else {
					Log.v(TAG, String.format("Directory '%s' found in DB but not on disk, DELETING", fileName));
					// Directory has been removed on disk, schedule for DELETE
					deletes.add(fileName);
				}

			}
			
			dirCursor.close();
			dirCursor = null;
			
			if(deletes.size() > 0 || dirs.size() > 0) {
				// We have database operations to perform
				db.beginTransaction();
				try {
					for(String d : deletes) {
						Log.v(TAG, "Deleting DIR...");
						db.delete("DIRS", "PATH=? AND FILENAME=?", new String [] { parent, d} );
					}
					
					for(String s : dirs) {
						ContentValues values = new ContentValues();
						values.put("PATH", parent);
						values.put("FILENAME", s);
						values.put("FLAGS", 0);
						Log.v(TAG, String.format("Inserting DIR... (%s,%s)", parent, s));
						db.insert("DIRS", "FILENAME", values);
					}
					
					Log.v(TAG, "TRANSATION SUCCESSFUL");
					db.setTransactionSuccessful();
				} finally {
					db.endTransaction();
				}
			}
			
			dirs = null;
		}
		
		return dirCount;
	}

	public void scan() {
		File f = new File("/sdcard/MODS");

		SharedPreferences prefs = mContext.getSharedPreferences("songdb", Context.MODE_PRIVATE);
		lastScan = prefs.getLong("lastScan", 0);

		Log.v(TAG, String.format("lastScan %d vs %d", lastScan, System.currentTimeMillis()));
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
			SharedPreferences.Editor editor = prefs.edit();
			editor.putLong("lastScan", startTime);
			editor.commit();
			lastScan = startTime;

			db.close();
			rdb.close();
		//} else {
		//	Log.v(TAG, "No need to scan files");
		//}

	}

	public Cursor search(String query) {
		if(rdb == null) {
			rdb = mOpenHelper.getReadableDatabase();
		}
	
		String q = "%" + query + "%" ;
		//Cursor c = rdb.query("SONGS", new String[] { "_id", "TITLE", "FILENAME" }, "TITLE LIKE ? OR FILENAME LIKE ? OR COMPOSER LIKE ?", new String[] { q, q, q }, null, null, null);
		Cursor c = rdb.query("SONGS", new String[] { "_id", "TITLE", "COMPOSER", "PATH", "FILENAME" }, "TITLE LIKE ?", new String[] { q }, null, null, "COMPOSER, TITLE");
		Log.v(TAG, String.format("Got %d hits", c.getCount()));
		return c;
	}
	
	public void closeDB() {
		if(rdb != null) {
			rdb.close();
			rdb = null;
		}
		if(db != null) {
			db.close();
			db = null;
		}
	}

	public Cursor getSongsInPath(String pathName) {
		if(rdb == null) {
			rdb = mOpenHelper.getReadableDatabase();
		}
		return rdb.query("SONGS", new String[] { "_id", "TITLE", "COMPOSER", "PATH", "FILENAME" }, "PATH=?", new String[] { pathName }, null, null, "TITLE");	
	}

	public Cursor getDirsInPath(String pathName) {
		if(rdb == null) {
			rdb = mOpenHelper.getReadableDatabase();
		}
		return rdb.query("DIRS", new String[] { "_id", "FILENAME", "PATH", "FLAGS" }, "PATH=?", new String[] { pathName }, null, null, "FILENAME");			
	}

}
