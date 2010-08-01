package com.ssb.droidsound;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.zip.ZipEntry;
import java.util.zip.ZipException;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.provider.BaseColumns;
import android.util.Log;
import android.widget.Toast;

import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.plugins.GMEPlugin;
import com.ssb.droidsound.plugins.ModPlugin;
import com.ssb.droidsound.plugins.TFMXPlugin;
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
	
	public static final int DB_VERSION = 2;
	
	private static final String[] FILENAME_array = new String[] { "_id", "FILENAME", "TYPE" };

	private Map<String, PathCallback> pathCallbacks = new HashMap<String, PathCallback>();
	private ScanCallback scanCallback;
	
	public static interface PathCallback {
		Cursor getCursorFromPath(String path, SQLiteDatabase db);
	}

	public static interface ScanCallback {
		void notifyScan(String path, int percent);
	}
	
	private SQLiteDatabase scanDb;
	private SQLiteDatabase rdb;
	private DroidSoundPlugin[] plugins;
	
	private String dbName;
	private volatile boolean stopScanning;

	private String modsDir;
	
	private SQLiteDatabase getReadableDatabase() {
		return SQLiteDatabase.openDatabase(dbName, null, SQLiteDatabase.OPEN_READONLY | SQLiteDatabase.NO_LOCALIZED_COLLATORS);
	}

	private SQLiteDatabase getWritableDatabase() {
		SQLiteDatabase dbrc = null;
		try {
			dbrc =  SQLiteDatabase.openDatabase(dbName, null, SQLiteDatabase.CREATE_IF_NECESSARY | SQLiteDatabase.NO_LOCALIZED_COLLATORS);
		} catch (SQLException e) {
		}
		return dbrc;
	}

	public static final int TYPE_ARCHIVE = 0;
	public static final int TYPE_DIR = 1;
	public static final int TYPE_FILE = 2;
	
	public SongDatabase(Context context, String mdir, boolean drop) {
		
		File myDir = context.getFilesDir();
		
		modsDir = mdir;
		
		dbName = new File(myDir, "songs.db").getAbsolutePath();
		Log.v(TAG, String.format("Database path %s", dbName));
		
		SQLiteDatabase db = getWritableDatabase();
		
		if(db == null) {
			return;
		}
		
		if(db.isDbLockedByOtherThreads()) {
			db.close();
			return;
		}
		
		
		if(db.needUpgrade(DB_VERSION)) {
			drop = true;
		}
		
		try {
			if(drop) {
				Log.v(TAG, "Dropping file tables!");
				db.execSQL("DROP TABLE IF EXISTS FILES ;");
				db.execSQL("DROP TABLE IF EXISTS VARIABLES ;");
				db.setVersion(DB_VERSION);
			}
	
			db.execSQL("CREATE TABLE IF NOT EXISTS " + "FILES" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
					"PATH" + " TEXT," +
					"FILENAME" + " TEXT," +
					"TYPE" + " INTEGER," +
	
					"TITLE" + " TEXT," +
					"COMPOSER" + " TEXT," +
					"COPYRIGHT" + " TEXT," +
					"FORMAT" + " TEXT," +
					"LENGTH" + " INTEGER" + ");");
			
			db.execSQL("CREATE TABLE IF NOT EXISTS " + "LINKS" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
					"LIST" + " INTEGER," +
					"PATH" + " TEXT," +
					"FILENAME" + " TEXT," +
					"TITLE" + " TEXT," +
					"COMPOSER" + " TEXT," +
					"COPYRIGHT" + " TEXT," +
					"FORMAT" + " TEXT" + ");");
	
			db.execSQL("CREATE INDEX IF NOT EXISTS fileindex ON FILES (PATH) ;");
	
			db.execSQL("CREATE INDEX IF NOT EXISTS fileindex ON FILES (TITLE) ;");
			
			db.execSQL("CREATE TABLE IF NOT EXISTS " + "VARIABLES" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
					"VAR" + " TEXT," +
					"VALUE" + " TEXT" + ");");
		} finally {		
			db.close();
		}
	}

	
	private boolean tryLoad(DroidSoundPlugin plugin, File file, ContentValues values) throws IOException {
		Object songRef = plugin.loadInfo(file);
		if(songRef != null) {
			String title = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_TITLE);
			String author = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_AUTHOR);
			String copyright = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_COPYRIGHT);
			String game = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_GAME);
			String type = plugin.getStringInfo(songRef, DroidSoundPlugin.INFO_TYPE);
			int length = plugin.getIntInfo(songRef, DroidSoundPlugin.INFO_LENGTH);

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
		return false;
	}
	
	private boolean checkModule(File file, ContentValues values) throws IOException {
		List<DroidSoundPlugin> list = new ArrayList<DroidSoundPlugin>();
		for(int i = 0; i < plugins.length; i++) {
			if(plugins[i].canHandle(file.getName())) {
				list.add(plugins[i]);
				Log.v(TAG, String.format("%s handled by %d", file.getName(), i));
			}
		}

		for(DroidSoundPlugin plugin : list) {
			Log.v(TAG, "Trying " + plugin.getClass().getName());
				if(tryLoad(plugin, file, values)) {
					return true;
				}
		}
		/*
		Log.v(TAG, "Failed, trying the rest");
	
		for(int i = 0; i < plugins.length; i++) {
			if(!plugins[i].canHandle(file.getName())) {
				Log.v(TAG, "Trying " + plugins[i].getClass().getName());
				if(tryLoad(plugins[i], file, values)) {
					return true;
				}
			}
		} */		
		
		return false;
	}
	
	
	private boolean scanZip(File zipFile) throws ZipException, IOException {
		
		Log.v(TAG, String.format("Scanning %s", zipFile.getPath()));
		
		// Erase any previous entries
		scanDb.delete("FILES", "PATH=?", new String [] { zipFile.getPath() });		
		scanDb.delete("FILES", "PATH LIKE ?", new String [] { zipFile.getPath() + "/%" });		
		
		Log.v(TAG, "OPEN");
		//ZipFile zfile = new ZipFile(zipFile);		
		NativeZipFile zfile = new NativeZipFile(zipFile);
		Log.v(TAG, "ENTRY");
		
		String baseName = zipFile.getPath();
		// Basename = /sdcard/MODS/C64Music.zip

		Log.v(TAG, "ENUM");
		Enumeration<? extends ZipEntry> entries = zfile.entries();
		
		Set<String> pathSet = new HashSet<String>();
		
		Log.v(TAG, String.format("Scanning %d zip entries", zfile.size()));
		int count = 0;
		int total = zfile.size();
		
		int reportPeriod = total / 100;
		if(reportPeriod < 100) {
			reportPeriod = 100;
		}

		while(entries.hasMoreElements()) {
			
			if(stopScanning) {
				zfile.close();
				return false;
			}
			
			ZipEntry ze = entries.nextElement();
			
			String n = ze.getName();			
			int slash = n.lastIndexOf('/');				
			String fileName = n.substring(slash+1);
			String path = baseName + "/" + n.substring(0, slash);

			if(fileName.equals("")) {
				pathSet.add(path);
			} else {
					
				ContentValues values = new ContentValues();
				
				InputStream is = zfile.getInputStream(ze);
				FileIdentifier.MusicInfo info = FileIdentifier.identify(n, is);
				is.close();
	
				if(info != null) {
					values.put("TITLE", info.title);
					values.put("COMPOSER", info.composer);
					values.put("COPYRIGHT", info.copyright);
					values.put("FORMAT", info.format);
					values.put("LENGTH", 0);
					values.put("PATH", path);
					values.put("FILENAME", fileName);
					values.put("TYPE", TYPE_FILE);
					scanDb.insert("FILES", "PATH", values);
				}

				count++;
				if((count % reportPeriod) == 0) {
					if(scanCallback != null) {
						scanCallback.notifyScan(null, count * 100 / total);
					}					
				}
					
				//if(count == 4000)
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
			values.put("TYPE", TYPE_DIR);
			scanDb.insert("FILES", "PATH", values);
		}
		
		return true;
		
	}
	
	private void scanFiles(File parentDir, boolean alwaysScan, long lastScan) {
		
		String parent = parentDir.getPath();
		String[] parentArray = new String[] { parent };
		
		if(stopScanning) {
			return;
		}
		
		boolean hasChanged = (lastScan < parentDir.lastModified());
		if(alwaysScan)
			hasChanged = true;
		
		Log.v(TAG, String.format("Entering '%s', lastScan %d", parent, lastScan));
		if(hasChanged) {
			Log.v(TAG, ">> Doing FULL scan");
		}

		Cursor fileCursor = scanDb.query("FILES", FILENAME_array, "PATH=?", parentArray, null, null, null);
		int index = fileCursor.getColumnIndex("FILENAME");
		int flindex = fileCursor.getColumnIndex("TYPE");
		int idindex = fileCursor.getColumnIndex("_id");

		if(hasChanged) {
			
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

			Set<String> delDirs = new HashSet<String>();
			Set<Long> delFiles = new HashSet<Long>();
			

			Set<String> removes = new HashSet<String>();

			Log.v(TAG, "Comparing DB to FS");
			
			// Iterate over database result and compare to hash set
			while(fileCursor.moveToNext()) {
				String fileName = fileCursor.getString(index);
				int type = fileCursor.getInt(flindex);
				long id = fileCursor.getLong(idindex);
				
				if(removes.contains(fileName)) {
					// Found duplicate in database
					Log.v(TAG, String.format("!! Found duplicate in database '%s', REMOVING !!", fileName));
					delFiles.add(id);
				}
				
				if(files.contains(fileName)) {
					// File/dir is in both
					
					File f = new File(parentDir, fileName);
					
					// Add directories to scanlist
					if(f.isDirectory()) {
						foundDirs.add(fileName);
						/// files.remove(fileName);
						removes.add(fileName);
					} else {
						if(lastScan < f.lastModified()) {
							// File has been modified - del and readd
							Log.v(TAG, String.format("!! FILE %s was modified", fileName));
							delFiles.add(id);
						} else {
							/// files.remove(fileName);
							removes.add(fileName);
						}
					}
				} else {
					Log.v(TAG, String.format("!! '%s' found in DB but not on disk, DELETING", fileName));
					// File has been removed on disk, schedule for DELETE
					if(type == TYPE_FILE) {
						delFiles.add(id);
					} else {
						delDirs.add(fileName);
					}
				}
			}
			
			files.removeAll(removes);
			
			for(String s : files) {
				Log.v(TAG, String.format("!! '%s' not in database, ADDING", s));
			}
				
			// Close cursor (important since we call ourselves recursively below)
			fileCursor.close();
			fileCursor = null;
			File csdb = null;
	
			if(files.size() > 0 || delDirs.size() > 0 || delFiles.size() > 0) {

				// We have database operations to perform
				scanDb.beginTransaction();
				try {
					
					for(String d : delDirs) {
						String path = new File(parent, d).getPath();
						Log.v(TAG, String.format("Deleting PATH %s and subdirs", path));
						scanDb.delete("FILES", "PATH=? AND FILENAME=?", new String [] { parent, d} );
						scanDb.delete("FILES", "PATH LIKE ?", new String [] { path + "/%" } );
						scanDb.delete("FILES", "PATH=?", new String [] { path } );
					}
	
					for(long id : delFiles) {
						Log.v(TAG, String.format("Deleting FILE %d in %s", id, parent));
						scanDb.delete("FILES", "_id=?", new String [] { Long.toString(id) } );
					}

					// Iterate over added files					
					int count = 0;
					int total = files.size();
					int reportPeriod = total / 100;
					if(reportPeriod < 10) {
						reportPeriod = 10;
					}
					for(String s : files) {
						File f = new File(parentDir, s);
						ContentValues values = new ContentValues();
						values.put("PATH", f.getParentFile().getPath());
						values.put("FILENAME", f.getName());
						
						Log.v(TAG, String.format("%s isfile %s", f.getPath(), String.valueOf(f.isFile())));
	
						if(f.isFile()) {
							
							String fn = f.getName();
							int end = fn.length();
							
							if(fn.toUpperCase().equals("CSDB.DUMP")) {
								csdb = f;
								values = null;
							} else
							if(fn.toUpperCase().endsWith(".ZIP")) {
								Log.v(TAG, String.format("Found zipfile (%s)", f.getPath()));
								zipFiles.add(f);
								/*
								if(fn.toUpperCase().equals("C64MUSIC.ZIP")) {
									Log.v(TAG, "Found HVSC at " + f.getPath());
									values = new ContentValues();
									values.put("VALUE", f.getPath());
									db.update("VARIABLES", values, "VAL='hvsc'", null);
								} */
								
								values = null;
							}
							else 
							if(fn.toUpperCase().endsWith(".LNK")) {
								Log.v(TAG, String.format("Found link (%s)", fn));
								values.put("TYPE", TYPE_ARCHIVE);
								values.put("TITLE", fn.substring(0, end - 4));								
							} else {
								values.put("TYPE", TYPE_FILE);
								try {
									Log.v(TAG, String.format("Checking %s", f.getPath()));
																		
									InputStream is = new FileInputStream(f);
									FileIdentifier.MusicInfo info = FileIdentifier.identify(f.getName(), is);
									is.close();
									boolean ok = false;
									if(info != null) {
										values.put("TITLE", info.title);
										values.put("COMPOSER", info.composer);
										values.put("COPYRIGHT", info.copyright);
										values.put("FORMAT", info.format);
										values.put("LENGTH", 0);
										ok = true;				
									} else {
										if(checkModule(f, values)) {
											ok = true;
										}
									}
									
									if(!ok) {
										values = null;
									}
								} catch (IOException e) {
									e.printStackTrace();
									values = null;
								}
							}
						} else {
							foundDirsNew.add(s);
							values.put("TYPE", TYPE_DIR);
						}
						if(values != null) {
							Log.v(TAG, String.format("Inserting FILE... (%s)", s));
							scanDb.insert("FILES", "PATH", values);
						}
						
						count++;
						if(count % reportPeriod == 0) {
							if(scanCallback != null) {
								scanCallback.notifyScan(null, count * 100 / total);
							}
						}
					}
					Log.v(TAG, "TRANSATION SUCCESSFUL");
					scanDb.setTransactionSuccessful();
					
				} finally {
					scanDb.endTransaction();
				}
			}
			
			Log.v(TAG, String.format("zipfiles (%d)", zipFiles.size()));
			if(zipFiles.size() > 0) {				
				for(File f : zipFiles) {
					try {
						if(scanCallback != null) {
							scanCallback.notifyScan(f.getPath(), 0);
						}
						scanDb.beginTransaction();
						if(scanZip(f)) {
							ContentValues values = new ContentValues();
							values.put("PATH", f.getParentFile().getPath());
							values.put("FILENAME", f.getName());
							values.put("TYPE", TYPE_ARCHIVE);
							int end = f.getName().length();
							values.put("TITLE", f.getName().substring(0, end - 4));				
							Log.v(TAG, String.format("Inserting FILE... (%s)", f.getName()));
							scanDb.insert("FILES", "PATH", values);
							scanDb.setTransactionSuccessful();
							Log.v(TAG, "ZIP TRANSATION SUCCESSFUL");
						}
					} catch (ZipException e) {
						Log.v(TAG, "Broken zip");
					} catch (IOException e) {
						Log.v(TAG, "IO Error");
					}
					scanDb.endTransaction();
				}
			}
			
			if(csdb != null) {
				
				if(scanCallback != null) {
					scanCallback.notifyScan(csdb.getPath(), 0);
				}
				
				if(CSDBParser.parseCSDB(csdb, scanDb, scanCallback)) {
					ContentValues values = new ContentValues();
					values.put("PATH", csdb.getParentFile().getPath());
					values.put("FILENAME", csdb.getName());
					values.put("TYPE", TYPE_ARCHIVE);
					values.put("TITLE", "CSDB");
					Log.v(TAG, String.format("Inserting CSDB from dump (%s)", csdb.getPath()));
					scanDb.insert("FILES", "PATH", values);
					//db.setTransactionSuccessful();
					//Log.v(TAG, "ZIP TRANSATION SUCCESSFUL");
				}
				csdb = null;
			}
			
			if(stopScanning) {
				return;
			}

			// Time to recursively scan sub-directories
			// scanDirs contains found dirs that exists in database

			for(String s : foundDirs) {
				File f = new File(parentDir, s);
				if(scanCallback != null) {
					scanCallback.notifyScan(f.getPath(), 0);
				}
				scanFiles(f, alwaysScan, lastScan);
			}			
			
			for(String s : foundDirsNew) {
				File f = new File(parentDir, s);
				if(scanCallback != null) {
					scanCallback.notifyScan(f.getPath(), 0);
				}
				scanFiles(f, true, lastScan);
			}
	
		} else {
			
			// This directory is not modified - we can rely on the database entries
			
			Set<File> files = new HashSet<File>();
			while(fileCursor.moveToNext()) {
				String fileName = fileCursor.getString(index);
				int type = fileCursor.getInt(flindex);
				if(type == TYPE_DIR) {
					files.add(new File(parentDir, fileName));
				}
			}
			
			Log.v(TAG, String.format("No change, scanning %d Datbase entries with %d dirs", fileCursor.getCount(), files.size()));

			fileCursor.close();
			fileCursor = null;

			for(File f : files) {
				scanFiles(f, alwaysScan, lastScan);
			}
		}
	}

	public void scan(boolean full) {

		stopScanning = false;

		plugins = new DroidSoundPlugin[4];
		plugins[0] = new TinySidPlugin();
		plugins[1] = new ModPlugin();
		plugins[2] = new GMEPlugin();
		plugins[3] = new TFMXPlugin();


		//rdb = getReadableDatabase();
		scanDb = getWritableDatabase();
		

		long startTime = System.currentTimeMillis();
		long lastScan = -1;
		Cursor cursor = scanDb.query("VARIABLES", new String[] { "VAR", "VALUE" }, "VAR='lastscan'", null, null, null, null);
		if(cursor.getCount() == 0) {
			ContentValues values = new ContentValues();
			values.put("VAR", "lastscan");
			values.put("VALUE", "0");
			scanDb.insert("VARIABLES", "VAR", values);
		} else {		
			cursor.moveToFirst();
			lastScan = Long.parseLong(cursor.getString(1));
		}
		
		cursor.close();
		
		Log.v(TAG, String.format("Last scan %d\n", lastScan));

		File parentDir = new File(modsDir);
		
		if(full) {
			
			Set<File> deletes = new HashSet<File>();
			int limit, offset;
			limit = 5000;
			offset = 1;
						
			if(scanCallback != null) {
				scanCallback.notifyScan("Checking orphans", 0);
			}					
			
			while(true) {
				
				// Remove orphaned directories
				Cursor oc = scanDb.query("FILES", new String[] { "PATH", "FILENAME" }, "PATH NOT LIKE '%.zip%'", null, null, null, null, String.format("%d,%d", offset, limit));

				Log.v(TAG, String.format("Orphan check on %d files\n", oc.getCount()));

				if(oc.getCount() <= 0) {
					oc.close();
					break;
				}
				
				offset += limit;
				
				int pindex = oc.getColumnIndex("PATH");
				int findex = oc.getColumnIndex("FILENAME");
		

				deletes.clear();
				while(oc.moveToNext()) {
					if(stopScanning) {
						break;
					}
					String pathName = oc.getString(pindex);
					if(!pathName.toUpperCase().contains(".zip")) {
						String fileName = oc.getString(findex);
						File f = new File(pathName, fileName);
						if(!f.exists()) {
							deletes.add(f);
						}
					}
				}
				
				oc.close();
				
				if(stopScanning) {
					break;
				}
				
				if(deletes.size() > 0) {
					scanDb.beginTransaction();
					for(File f : deletes) {
						Log.v(TAG, String.format("Removing %s from DB\n", f.getPath()));
						scanDb.delete("FILES", "PATH=? AND FILENAME=?", new String[] { f.getParent(), f.getName() });
						if(f.getName().toUpperCase().endsWith(".ZIP")) {
							Log.v(TAG, "Removing zip contents");
							scanDb.delete("FILES", "PATH LIKE ?", new String[] { f.getPath() + "/%" });
						}
					}
					scanDb.setTransactionSuccessful();
					scanDb.endTransaction();
				}
			}
		}

		
		
		scanFiles(parentDir, full, lastScan);
		//if(scanCallback != null) {
		//	scanCallback.notifyScan(null, -1);
		//}
		
		
		
		if(!stopScanning) {
			ContentValues values = new ContentValues();
			values.put("VAR", "lastscan");
			values.put("VALUE", Long.toString(startTime));
			scanDb.update("VARIABLES", values, "VAR='lastscan'", null);
		}
		
		stopScanning = false;

		
		scanDb.close();
		//rdb.close();
	}

	public Cursor search(String query, boolean csdb) {
		if(rdb == null) {
			rdb = getReadableDatabase();
		}
		
		if(csdb) {
			return CSDBParser.search(rdb, query);
		}
	
		String q = "%" + query + "%" ;
		//Cursor c = rdb.query("SONGS", new String[] { "_id", "TITLE", "FILENAME" }, "TITLE LIKE ? OR FILENAME LIKE ? OR COMPOSER LIKE ?", new String[] { q, q, q }, null, null, null);
		Cursor c = rdb.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "PATH", "FILENAME", "TYPE" }, "TITLE LIKE ?", new String[] { q }, null, null, "COMPOSER, TITLE", "500");
		Log.v(TAG, String.format("Got %d hits", c.getCount()));
		return c;
	}
	
	public void closeDB() {
		if(rdb != null) {
			rdb.close();
			rdb = null;
		}
	}

	public Cursor getFilesInPath(String pathName) {
		if(rdb == null) {
			rdb = getReadableDatabase();
		}
		
		
		if(rdb.isDbLockedByOtherThreads()) {
			return null;
		}
		
		
		int csdb = pathName.toUpperCase().indexOf("/CSDB.DUMP");
		if(csdb >= 0) {
			//pathName.replaceFirst("/CSDB.DUMP", "CSDB:");
			pathName = pathName.substring(0, csdb) + "/CSDB:" + pathName.substring(csdb+10);
		}
		
		//File f = new File(pathName);
		
		Log.v(TAG, String.format("files in path '%s'", pathName));
		String name = new File(pathName).getName().toUpperCase();
		
		if(name.endsWith(".LNK")) {
			try {
				File f = new File(pathName);
				BufferedReader reader = new BufferedReader(new FileReader(f));
				String p = reader.readLine();
				reader.close();
				if(p != null && p.length() > 0) {
					pathName = p;
				}
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			}
		} /*else if(name.equals("CSDB.DUMP")) {
			//return CSDBParser.getPath("", rdb);
			pathName = new File(new File(pathName).getParent(), "CSDB:").getPath();
		} */

		Log.v(TAG, String.format("Path now '%s'", pathName));

		int colon = pathName.indexOf(':');
		if(colon > 0) {
			int start = pathName.lastIndexOf('/', colon) + 1;
			PathCallback cb = pathCallbacks.get(pathName.substring(start, colon));
			if(cb != null) {
				return cb.getCursorFromPath(pathName.substring(colon+1), rdb);
			}
		}

		return rdb.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "FILENAME", "TYPE" }, "PATH=?", new String[] { pathName }, null, null, "TYPE, FILENAME", "1000");	
	}
	
	public void setScanCallback(ScanCallback cb) {
		scanCallback = cb;
	}

	public void registerPath(String name, PathCallback cb) {
		pathCallbacks.put(name, cb);
	}
	
	public void unregisterAll() {
		pathCallbacks.clear();		
	}


	public void stopScan() {
		stopScanning = true;
		
	}

	public void addFavorite(File file) {
		SQLiteDatabase db = getWritableDatabase();
		if(db != null) {
			ContentValues values = new ContentValues();
			values.put("LIST", 0);			
			int idx =-1;
			values.put("PATH", file.getParent());
			values.put("FILENAME", file.getName());			
			//File f = new File(path, cursor.getString(cursor.getColumnIndex("FILENAME")));
			Cursor cursor = db.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "FILENAME", "TYPE" }, "PATH=? AND FILENAME=?", new String[] { file.getParent(), file.getName() }, null, null, null);
			Log.v(TAG, String.format("File '%s' Count %d", file.getPath(), cursor.getCount()));
			cursor.moveToFirst();
			
			idx = cursor.getColumnIndex("TITLE");
			if(idx >= 0)
				values.put("TITLE", cursor.getString(idx));
			idx = cursor.getColumnIndex("COMPOSER");
			if(idx >= 0)
				values.put("COMPOSER", cursor.getString(idx));
			idx = cursor.getColumnIndex("COPYRIGHT");
			if(idx >= 0)
				values.put("COPYRIGHT", cursor.getString(idx));
			idx = cursor.getColumnIndex("FORMAT");
			if(idx >= 0)
				values.put("FORMAT", cursor.getString(idx));
			db.insert("LINKS","PATH", values);
			db.close();
		}
	}
	
	public void removeFavorite(File file) {
		SQLiteDatabase db = getWritableDatabase();
		Log.v(TAG, String.format("Removing '%s'", file.getPath()));
		if(db != null) {
			db.delete("LINKS", "LIST=? AND PATH=? AND FILENAME=?", new String [] { "0", file.getParent(), file.getName() } );
			db.close();
		}
	}
	
	public void clearFavorites() {
		SQLiteDatabase db = getWritableDatabase();
		if(db != null) {
			db.delete("LINKS", "LIST=?", new String [] { "0" } );
			db.close();
		}
	}
	
	
	
	
}
