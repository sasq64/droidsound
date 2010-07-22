package com.ssb.droidsound;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.PreparedStatement;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.zip.ZipEntry;
import java.util.zip.ZipException;
import java.util.zip.ZipFile;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.provider.BaseColumns;
import android.util.Log;

import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.plugins.GMEPlugin;
import com.ssb.droidsound.plugins.ModPlugin;
import com.ssb.droidsound.plugins.TinySidPlugin;
import com.ssb.droidsound.utils.NativeZipFile;

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
	private static final String[] FILENAME_array = new String[] { "FILENAME", "FLAGS" };
/*
	private static class DbHelper extends SQLiteOpenHelper {
		
		Context mContext;

		public DbHelper(Context context) {
			super(context, "songs", null, 1);
			mContext = context;
		}

		@Override
		public void onCreate(SQLiteDatabase db) {
			
			try {
				db.execSQL("CREATE TABLE " + "SONGS" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
						"TITLE" + " TEXT," +
						"COMPOSER" + " TEXT," +
						"COPYRIGHT" + " TEXT," +
						"FORMAT" + " TEXT," +
						"LENGTH" + " INTEGER," +
						"PATH" + " TEXT," +
						"FILENAME" + " TEXT" + ");");
			} catch (SQLException e) {
			}
			try {
				db.execSQL("CREATE TABLE " + "DIRS" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
						"FILENAME" + " TEXT," +
						"PATH" + " TEXT," +
						"FLAGS" + " INTEGER" + ");");
			} catch (SQLException e) {
			}
			try {
				db.execSQL("CREATE TABLE " + "SEARCHDIRS" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
						"PATH" + " TEXT," +
						"FLAGS" + " INTEGER," +
						"LASTSCAN" + " INTEGER" + ");");
			} catch (SQLException e) {
			}

			Log.v(TAG, "Creating database");
			
			
			
			
			//SharedPreferences prefs = mContext.getSharedPreferences("songdb", Context.MODE_PRIVATE);
			//SharedPreferences.Editor editor = prefs.edit();
			//editor.putLong("lastScan", 0);
			//editor.commit();
		}

		@Override
		public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
			// TODO Auto-generated method stub
			db.execSQL("DROP TABLE SONGS;");
			db.execSQL("DROP TABLE DIRS;");
			db.execSQL("DROP TABLE SEARCHDIRS;");
			onCreate(db);
		}
	}

	private DbHelper mOpenHelper;
*/
	
	
	private SQLiteDatabase db;
	private SQLiteDatabase rdb;
	//private long lastScan;
	private Context mContext;
	private DroidSoundPlugin[] plugins;
	
	private String dbName;
	
	SQLiteDatabase getReadableDatabase() {
		return SQLiteDatabase.openDatabase(dbName, null, SQLiteDatabase.OPEN_READONLY);
	}

	SQLiteDatabase getWritableDatabase() {
		return SQLiteDatabase.openDatabase(dbName, null, SQLiteDatabase.CREATE_IF_NECESSARY);
	}

	SongDatabase(Context context) {
		//mOpenHelper = new DbHelper(context);
		//dbName = "songs.db";
		mContext = context;
		
		File myDir = context.getFilesDir();
		
		dbName = new File(myDir, "songs.db").getAbsolutePath();
		Log.v(TAG, String.format("Database path %s", dbName));
		
		SQLiteDatabase db = getWritableDatabase();
		
		//db.execSQL("DROP TABLE IF EXISTS FILES ;");
		//db.execSQL("DROP TABLE IF EXISTS VARIABLES ;");

		db.execSQL("CREATE TABLE IF NOT EXISTS " + "FILES" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
				"PATH" + " TEXT," +
				"FILENAME" + " TEXT," +
				"FLAGS" + " INTEGER," +

				"TITLE" + " TEXT," +
				"COMPOSER" + " TEXT," +
				"COPYRIGHT" + " TEXT," +
				"FORMAT" + " TEXT," +
				"LENGTH" + " INTEGER" + ");");
		
		db.execSQL("CREATE INDEX IF NOT EXISTS fileindex ON FILES (PATH) ;");

		/*db.execSQL("CREATE TABLE IF NOT EXISTS " + "DIRS" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
				"FILENAME" + " TEXT," +
				"PATH" + " TEXT," +
				"FLAGS" + " INTEGER" + ");");

		db.execSQL("CREATE TABLE IF NOT EXISTS " + "SEARCHDIRS" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
				"PATH" + " TEXT," +
				"FLAGS" + " INTEGER," +
				"LASTSCAN" + " INTEGER" + ");");*/

		db.execSQL("CREATE TABLE IF NOT EXISTS " + "VARIABLES" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
				"VAR" + " TEXT," +
				"VALUE" + " TEXT" + ");");
		db.close();
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
			Object songRef = plugin.loadInfo(file);
			if(songRef != null) {
				String title = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_TITLE);
				String author = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_AUTHOR);
				String copyright = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_COPYRIGHT);
				String game = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_GAME);
				String type = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_TYPE);
				int length = plugin.getIntInfo(songRef, DroidSoundPlugin.INFO_LENGTH);
				
				if(type != null && type.equals("MOD")) {
					author = file.getParentFile().getName();
				}
				
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
				
				plugin.unload(songRef);

				return true;
			}
		}
		
		values.put("FORMAT", "Unknown");
		values.put("PATH", file.getParentFile().getPath());
		values.put("FILENAME", file.getName());
		
		return true;
	}
	
	
	private void scanZip(File zipFile) throws ZipException, IOException {
		
		byte [] data;
		
		Log.v(TAG, String.format("Scanning %s", zipFile.getPath()));
		
		// Erase any previous entries
		db.delete("FILES", "PATH LIKE ?", new String [] { zipFile.getPath() + "/%" });		
		
		Log.v(TAG, "OPEN");
		//ZipFile zfile = new ZipFile(zipFile);		
		NativeZipFile zfile = new NativeZipFile(zipFile);
		Log.v(TAG, "ENTRY");
		/*
		ZipEntry le = zfile.getEntry("C64Music/DOCUMENTS/Songlengths.txt");
		if(le != null) {
			data = new byte [(int) le.getSize()] ;
			
			InputStreamReader reader = new InputStreamReader(zfile.getInputStream(le));
			BufferedReader breader = new BufferedReader(reader);
			String line0, line1;

			HashMap<String, String> hmap = new HashMap<String, String>();
			
			line0 = breader.readLine();
			if(line0.equals("[Database]")) {
				
				while(true) {
					line0 = breader.readLine();
					if(line0 == null)
						break;
					line1 = breader.readLine();
					if(line1 == null)
						break;
					String name = line0.substring(2);
					int eq = line1.indexOf('=');
					if(eq > 0) {
						String length = line1.substring(eq+1);
						//System.out.printf("%s = %s\n", name, length);
						//int len = Integer.parseInt(arg0);
						hmap.put(name, length);
					}
				}
			}
		}*/
		
		String baseName = zipFile.getPath();
		int baseCount = baseName.length();
		// Basename = /sdcard/MODS/C64Music.zip

		Log.v(TAG, "ENUM");
		Enumeration<? extends ZipEntry> entries = zfile.entries();
		
		data = new byte [0x78];
		
		Set<String> pathSet = new HashSet<String>();
		
		Log.v(TAG, String.format("Scanning %d zip entries", zfile.size()));
		int count = 0;
		String lastPath = "";
		while(entries.hasMoreElements()) {
			ZipEntry ze = entries.nextElement();
			
			String n = ze.getName();
			// n = C64Music/xxx ...
			
			if(n.endsWith(".sid")) {
				
				int slash = n.lastIndexOf('/');				
				//int firstSlash =  n.indexOf('/');
				
				String fileName = n.substring(slash+1);
				String path = baseName + "/" + n.substring(0, slash);
				
				
				
				if(!path.equals(lastPath)) {
					// /sdcard/MODS/C64Music.zip/MUSICIANS/A-Z/Agemixer					
					Log.v(TAG, String.format("Adding DIR %s", path));
					pathSet.add(path);
					slash = path.lastIndexOf('/');
					while(slash > baseCount) {
						Log.v(TAG, String.format("Adding DIR %s", path.substring(0, slash)));
						pathSet.add(path.substring(0, slash));
						slash = path.lastIndexOf('/', slash-1);
					}					
					lastPath = path;
				}
							
				DataInputStream dis = new DataInputStream(zfile.getInputStream(ze));
				dis.read(data);
				
				//int songs = (int)data[0x0f];
				//int startSong = (int)data[0x11];
				
				//if(startSong == 0)
				//	startSong = 1;
				
				int o = 0x35;
				while(o >= 0x16 && data[o] == 0) {
					o -= 1;
				}
				String name = new String(data, 0x16, o-0x15, "ISO-8859-1");
	
				o = 0x55;
				while(o >= 0x36 && data[o] == 0) {
					o -= 1;
				}
				String author = new String(data, 0x36, o-0x35, "ISO-8859-1");
	
				o = 0x75;
				while(o >= 0x56 && data[o] == 0) {
					o -= 1;
				}
				String copyright = new String(data, 0x56, o-0x55, "ISO-8859-1");

				//String n = ze.getName().substring(8);
				/*
				System.out.printf("%s %s %s (%02d/%02d)\n", name, author, copyright, startSong, songs);
				String length = hmap.get(n.substring(8));
				int iLength = 0;
				if(length != null) {					
					String lens [] = length.split(" ");
					System.out.printf("%s --- %d\n", length, lens.length);
					if(lens.length > 1)
						length = lens[startSong-1];
					int colon = length.indexOf(':');
					int min = Integer.parseInt(length.substring(0, colon));
					int sec = Integer.parseInt(length.substring(colon+1, colon+3));
					iLength = min*60+sec;
					System.out.printf("%s %s ==> %d seconds\n", n, length, iLength);
				} */
				
				//int year = 0;
				//try {
				//	year = Integer.parseInt(copyright.substring(0,4));
				//} catch (NumberFormatException e) {
				//}
				

				ContentValues values = new ContentValues();
				values.put("PATH", path);
				values.put("FILENAME", fileName);
				values.put("TITLE", name);
				values.put("COMPOSER", author);
				values.put("COPYRIGHT", copyright);
				values.put("FORMAT", "SID");
				values.put("LENGTH", 0);
				values.put("FLAGS", 1);

				db.insert("FILES", "PATH", values);
				
				if((count % 200) == 0) {
					Log.v(TAG, String.format("(%d) Added %s %s", count, name, author));
				}
				count++;
				
				//if(count == 1000)
				//	break;
			}
			
		}
		
		zfile.close();

		Log.v(TAG, String.format("Adding %d paths", pathSet.size()));
		
		for(String s : pathSet) {
			ContentValues values = new ContentValues();
			
			int slash = s.lastIndexOf('/');
			String fileName = s.substring(slash+1);
			String path = s.substring(0, slash);
			
			values.put("PATH", path);
			values.put("FILENAME", fileName);
			values.put("FLAGS", 0);
			db.insert("FILES", "PATH", values);
		}
		
	}
	
	private void scanFiles(File parentDir, boolean alwaysScan, long lastScan) {
		
		String parent = parentDir.getPath();
		String[] parentArray = new String[] { parent };
		
		boolean hasChanged = (lastScan < parentDir.lastModified());
		if(alwaysScan)
			hasChanged = true;
		
		Log.v(TAG, String.format("Entering '%s', lastScan %d", parent, lastScan));
		if(hasChanged) {
			Log.v(TAG, ">> Doing FULL scan");
		}

		Cursor fileCursor = db.query("FILES", FILENAME_array, "PATH=?", parentArray, null, null, null);

		// All files and directories
		Set<String> files = new HashSet<String>();
		
		// Directories to scan later
		Set<String> foundDirs = new HashSet<String>();
		Set<String> foundDirsNew = new HashSet<String>();
		Set<File> zipFiles = new HashSet<File>();
		
		File [] fileList = parentDir.listFiles();
		
		if(fileList != null) {
			// Add all existing files to a hash set
			for(File f : fileList) {
				files.add(f.getName());
			}
		}

		Log.v(TAG, String.format("Datbase has %d entries, found %d files/dirs", fileCursor.getCount(), files.size()));

		if(hasChanged) {
			
			Set<String> deletes = new HashSet<String>();
			
			Log.v(TAG, "Comparing DB to FS");
			
			int index = fileCursor.getColumnIndex("FILENAME");
			int flindex = fileCursor.getColumnIndex("FLAGS");
			// Iterate over database result and compare to hash set
			while(fileCursor.moveToNext()) {
				String fileName = fileCursor.getString(index);
				int flags = fileCursor.getInt(flindex);
				if(files.contains(fileName)) {
					// File/dir is in both
					
					// Add directories to scanlist
					if(new File(parentDir, fileName).isDirectory()) {
						foundDirs.add(fileName);
					}
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
			fileCursor.close();
			fileCursor = null;
	
			if(files.size() > 0 || deletes.size() > 0) {
				// We have database operations to perform
				db.beginTransaction();
				try {
					
					for(String d : deletes) {
						Log.v(TAG, "Deleting...");
						db.delete("FILES", "PATH=? AND FILENAME=?", new String [] { parent, d} );
					}
	
					// Iterate over added files
					for(String s : files) {
						File f = new File(parentDir, s);
						ContentValues values = new ContentValues();
						values.put("PATH", f.getParentFile().getPath());
						values.put("FILENAME", f.getName());
	
						if(f.isFile()) {
							
							if(f.getName().toUpperCase().endsWith(".ZIP")) {
								Log.v(TAG, String.format("Found zipfile (%s)", f.getPath()));
								zipFiles.add(f);
								values.put("FLAGS", 2);
							}
							else {
								values.put("FLAGS", 1);
								try {
									if(checkModule(f, values)) {
									} else {
										values = null;
									}
								} catch (IOException e) {
									e.printStackTrace();
									values = null;
								}
							}
						} else {
							foundDirsNew.add(s);
							values.put("FLAGS", 0);
						}
						if(values != null) {
							Log.v(TAG, String.format("Inserting FILE... (%s)", s));
							db.insert("FILES", "PATH", values);
						}
					}
					Log.v(TAG, "TRANSATION SUCCESSFUL");
					db.setTransactionSuccessful();
					
				} finally {
					db.endTransaction();
				}
			}
			
			Log.v(TAG, String.format("zipfiles (%d)", zipFiles.size()));
			if(zipFiles.size() > 0) {
				db.beginTransaction();
				for(File f : zipFiles) {
					try {
						scanZip(f);
					} catch (ZipException e) {
						Log.v(TAG, "Broken zip");
					} catch (IOException e) {
						Log.v(TAG, "IO Error");
					}
				}
				Log.v(TAG, "ZIP TRANSATION SUCCESSFUL");
				db.setTransactionSuccessful();
				db.endTransaction();
			}

			// Time to recursively scan sub-directories
			// scanDirs contains found dirs that exists in database

			for(String s : foundDirs) {
				scanFiles(new File(parentDir, s), alwaysScan, lastScan);
			}			
			
			for(String s : foundDirsNew) {
				scanFiles(new File(parentDir, s), true, lastScan);
			}
	
		} else if(fileList != null) {

			fileCursor.close();
			fileCursor = null;

			for(File f : fileList) {
				if(f.isDirectory()) {
					scanFiles(f, alwaysScan, lastScan);
				}
			}

		}
		
	}

	public void scan(boolean full) {


		plugins = new DroidSoundPlugin[3];
		plugins[0] = new TinySidPlugin();
		plugins[1] = new ModPlugin();
		plugins[2] = new GMEPlugin();

		//rdb = getReadableDatabase();
		db = getWritableDatabase();

		long startTime = System.currentTimeMillis();
		long lastScan = -1;
		Cursor cursor = db.query("VARIABLES", new String[] { "VAR", "VALUE" }, "VAR='lastscan'", null, null, null, null);
		if(cursor.getCount() == 0) {
			ContentValues values = new ContentValues();
			values.put("VAR", "lastscan");
			values.put("VALUE", "0");
			db.insert("VARIABLES", "VAR", values);
		} else {		
			cursor.moveToFirst();
			lastScan = Long.parseLong(cursor.getString(1));
		}
		
		cursor.close();
		
		Log.v(TAG, String.format("Last scan %d\n", lastScan));

		File parentDir = new File("/sdcard/MODS");
		
		scanFiles(parentDir, full, lastScan);
		
		ContentValues values = new ContentValues();
		values.put("VAR", "lastscan");
		values.put("VALUE", Long.toString(startTime));
		db.update("VARIABLES", values, "VAR='lastscan'", null);		
		
		db.close();
		//rdb.close();
	}

	public Cursor search(String query) {
		if(rdb == null) {
			rdb = getReadableDatabase();
		}
	
		String q = "%" + query + "%" ;
		//Cursor c = rdb.query("SONGS", new String[] { "_id", "TITLE", "FILENAME" }, "TITLE LIKE ? OR FILENAME LIKE ? OR COMPOSER LIKE ?", new String[] { q, q, q }, null, null, null);
		Cursor c = rdb.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "PATH", "FILENAME", "FLAGS" }, "TITLE LIKE ?", new String[] { q }, null, null, "COMPOSER, TITLE");
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

	public Cursor getFilesInPath(String pathName) {
		if(rdb == null) {
			rdb = getReadableDatabase();
		}
		
		int colon = pathName.indexOf(':');
		if(colon > 0) {
			PathCallback cb = pathCallbacks.get(pathName.substring(0, colon));
			if(cb != null) {
				return cb.getCursorFromPath(pathName.substring(colon+1));
			}
		}		
		return rdb.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "FILENAME", "FLAGS" }, "PATH=?", new String[] { pathName }, null, null, "FLAGS, FILENAME");	
	}
	
	private Map<String, PathCallback> pathCallbacks = new HashMap<String, PathCallback>();
	
	public static interface PathCallback {
		Cursor getCursorFromPath(String path);
	}

	public void registerPath(String name, PathCallback cb) {
		pathCallbacks.put(name, cb);		
	}

}
