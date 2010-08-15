package com.ssb.droidsound;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Map.Entry;
import java.util.zip.ZipEntry;
import java.util.zip.ZipException;
import java.util.zip.ZipFile;

import android.content.ContentValues;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.provider.BaseColumns;
import android.util.Log;

import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.plugins.GMEPlugin;
import com.ssb.droidsound.plugins.ModPlugin;
import com.ssb.droidsound.plugins.SidplayPlugin;
import com.ssb.droidsound.plugins.TFMXPlugin;
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

public class SongDatabase implements Runnable {
	private static final String TAG = SongDatabase.class.getSimpleName();
	
	public static final int DB_VERSION = 4;
	
	private static final String[] FILENAME_array = new String[] { "_id", "FILENAME", "TYPE" };

	private ScanCallback scanCallback;

	public static interface ScanCallback {
		void notifyScan(String path, int percent);
	}
	
	public static class SongInfo {
		String comment;
		String length;
	};
	
	public static interface DataSource {

		boolean parseDump(InputStream is, int size, SQLiteDatabase scanDb, ScanCallback scanCallback);
		String getTitle();
		Cursor getCursorFromPath(File file, SQLiteDatabase db);
		String getPathTitle(File file);
		void createIndex(int mode, SQLiteDatabase db);
		Cursor search(String query, String fromPath, SQLiteDatabase db);
	}
	
	private Map<String, DataSource> dbsources = new HashMap<String, DataSource>();
	
	
	private SQLiteDatabase scanDb;
	private SQLiteDatabase rdb;
	private DroidSoundPlugin[] plugins;
	
	private String dbName;
	private volatile boolean stopScanning;


	private Context context;

	private boolean doQuit;

	private Handler mHandler;

	private volatile boolean scanning;

	private volatile boolean isReady;
	
	public static final int TYPE_ARCHIVE = 0x100;
	public static final int TYPE_DIR = 0x200;
	public static final int TYPE_PLIST = 0x300;
	public static final int TYPE_FILE = 0x400;
	

	protected static final int MSG_SCAN = 0;
	protected static final int MSG_BACKUP = 1;
	protected static final int MSG_RESTORE = 2;

	public static final int INDEX_NONE = 0;
	public static final int INDEX_BASIC = 1;
	public static final int INDEX_FULL = 2;
	
	public SongDatabase(Context ctx) {		
		context = ctx;		
	}
	
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

	public void registerDataSource(String dumpname, DataSource ds) {
		String s = dumpname.toUpperCase();
		dbsources.put(s, ds);
		dbsources.put(s + ".ZIP", ds);
	}
	
	@Override
	public void run() {
				
		Looper.prepare();
		
		mHandler = new Handler() {
			@Override
	        public void handleMessage(Message msg) {
	        	Log.v(TAG, String.format("Got msg %d with arg %s", msg.what, (String)msg.obj));
	            switch (msg.what) {
	            case MSG_SCAN:
	            	if(msg.arg1 == 2) {
	            		open(true);
	            		doScan((String)msg.obj, false);
	            	} else {
	            		doScan((String)msg.obj, msg.arg1 != 0);
	            	}
	            	break;
	            }
			}
		};
		
		setScanCallback(new ScanCallback() {
			String oldPath;
			@Override
			public void notifyScan(String path, int percent) {
				Intent intent;
				
				if(path == null) {
					path = oldPath;
				} else {
					oldPath = path;
				}
				
				Log.v(TAG, String.format("PATH %s %d\n", path, percent));
				
				if(percent >= 0) {
					intent = new Intent("com.sddb.droidsound.SCAN_UPDATE");
					intent.putExtra("PATH", path);
					intent.putExtra("PERCENT", percent);
				} else {
					intent = new Intent("com.sddb.droidsound.SCAN_DONE");
				}
				context.sendBroadcast(intent);				
			}
		});

		open(false);
		Intent intent = new Intent("com.sddb.droidsound.OPEN_DONE");
		context.sendBroadcast(intent);
		Looper.loop();
	}

	private void open(boolean drop) {	
		File myDir = context.getFilesDir();
		
		isReady = false;
		
		if(rdb != null) {
			rdb.close();
			rdb = null;
		}
		
		dbName = new File(myDir, "songs.db").getAbsolutePath();
		Log.v(TAG, String.format("Database path %s", dbName));
		
		SQLiteDatabase db = getWritableDatabase();

		if(db.needUpgrade(DB_VERSION)) {
			drop = true;
		}
		
		try {
			if(drop) {
				if(scanCallback != null) {
					scanCallback.notifyScan("Dropping database", 0);
					try {
						Thread.sleep(500);
					} catch (InterruptedException e) {
					}
				}
				Log.v(TAG, "Dropping file tables!");
				db.execSQL("DROP TABLE IF EXISTS FILES ;");
				db.execSQL("DROP TABLE IF EXISTS VARIABLES ;");
				db.execSQL("DROP TABLE IF EXISTS LINKS ;");
				//db.execSQL("DROP TABLE IF EXISTS SONGINFO");
				db.setVersion(DB_VERSION);
			}
	
			if(drop) {
				if(scanCallback != null) {
					scanCallback.notifyScan("Creating database", 0);
				}
			}
			
			/*
			db.execSQL("CREATE TABLE IF NOT EXISTS SONGINFO (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
					"HASH INTEGER," +
					"MD5 TEXT," +
					"COMMENT TEXT," +
					"SONGLENGTH TEXT" + ");"); */


			db.execSQL("CREATE TABLE IF NOT EXISTS " + "FILES" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
					"PATH" + " TEXT," +
					"FILENAME" + " TEXT," +
					"TYPE" + " INTEGER," +
	
					"TITLE" + " TEXT," +
					"COMPOSER" + " TEXT," +
					"DATE" + " INTEGER," +
					"FORMAT" + " TEXT" + ");");
					// "LENGTH" + " INTEGER" + 

			db.execSQL("CREATE INDEX IF NOT EXISTS fileindex ON FILES (PATH) ;");
	
			db.execSQL("CREATE INDEX IF NOT EXISTS fileindex ON FILES (TITLE) ;");
			
			db.execSQL("CREATE TABLE IF NOT EXISTS " + "VARIABLES" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
					"VAR" + " TEXT," +
					"VALUE" + " TEXT" + ");");
		} finally {		
			db.close();
		}
		isReady = true;
	}
	
	private void createIndex(int mode) {

		SQLiteDatabase db = getWritableDatabase();
		
		if(scanCallback != null) {
			scanCallback.notifyScan("Updating indexes", 0);
		}
		
		switch(mode) {
		case INDEX_NONE:
			db.execSQL("DROP INDEX IF EXISTS fileindex ;");		
			db.execSQL("DROP INDEX IF EXISTS titleindex ;");
			db.execSQL("DROP INDEX IF EXISTS filenameindex ;");
			break;
		case INDEX_BASIC:
			db.execSQL("CREATE INDEX IF NOT EXISTS fileindex ON FILES (PATH) ;");		
			db.execSQL("CREATE INDEX IF NOT EXISTS titleindex ON FILES (TITLE) ;");
			db.execSQL("DROP INDEX IF EXISTS filenameindex ;");
			break;
		case INDEX_FULL:
			db.execSQL("CREATE INDEX IF NOT EXISTS fileindex ON FILES (PATH) ;");		
			db.execSQL("CREATE INDEX IF NOT EXISTS titleindex ON FILES (TITLE) ;");
			db.execSQL("CREATE INDEX IF NOT EXISTS filenameindex ON FILES (FILENAME) ;");
			break;
		}
		
		for(Entry<String, DataSource> ds : dbsources.entrySet()) {			
			ds.getValue().createIndex(mode, db);			
		}
		
		if(scanCallback != null) {
			scanCallback.notifyScan(null, -1);
		}
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
		
		String baseNameNoSlash = zipFile.getPath();
		String baseName = zipFile.getPath() + "/";
		// Basename = /sdcard/MODS/C64Music.zip/

		//ZipEntry infoe = zfile.getEntry("C64Music/DOCUMENTS/Songlengths.txt");
		//if(infoe != null) {
		//	HVSCParser.parseSongLengths(zfile.getInputStream(infoe), scanDb);
		//}		
		
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

		ContentValues values = new ContentValues();
		//values.put("LENGTH", 0);
		values.put("TYPE", TYPE_FILE);
				
		while(entries.hasMoreElements()) {
			
			if(stopScanning) {
				zfile.close();
				return false;
			}
			
			ZipEntry ze = entries.nextElement();
			
			String n = ze.getName();			
			int slash = n.lastIndexOf('/');				
			String fileName = n.substring(slash+1);
			String path;
			if(slash >= 0) {
				path = baseName + n.substring(0, slash);
			} else {
				path = baseNameNoSlash;
			}

			if(fileName.equals("")) {
				pathSet.add(path);
			} else {
									
				InputStream is = zfile.getInputStream(ze);
				FileIdentifier.MusicInfo info = FileIdentifier.identify(n, is);
				is.close();
	
				if(info != null) {

					values.put("TITLE", info.title);
					values.put("COMPOSER", info.composer);
					//values.put("COPYRIGHT", info.copyright);
					values.put("DATE", info.date);
					values.put("FORMAT", info.format);
					values.put("PATH", path);
					values.put("FILENAME", fileName);
					scanDb.insert("FILES", "PATH", values);
				}

				count++;
				if((count % reportPeriod) == 0) {
					isReady = false;
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
		
		values.clear();
		values.put("TYPE", TYPE_DIR);
		for(String s : pathSet) {
			//ContentValues values = new ContentValues();
			
			int slash = s.lastIndexOf('/');
			String fileName = s.substring(slash+1);
			String path = s.substring(0, slash);
			
			values.put("PATH", path);
			values.put("FILENAME", fileName);
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
						//Log.v(TAG, String.format("!! Lastscan %d, file %s modified %d", lastScan, fileName, f.lastModified()));
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
			//File csdb = null;
			List<File> foundDumps = new ArrayList<File>();
	
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
														
							if(dbsources.containsKey(fn.toUpperCase())) {								
								foundDumps.add(f);
								values = null;
							}							
							else
							if(fn.toUpperCase().endsWith(".ZIP")) {
								Log.v(TAG, String.format("Found zipfile (%s)", f.getPath()));
								zipFiles.add(f);
								
								values = null;
							}
							else 
							if(fn.toUpperCase().endsWith(".PLIST")) {
								Log.v(TAG, String.format("Found playlist (%s)", fn));
								values.put("TYPE", TYPE_PLIST);
								values.put("TITLE", fn.substring(0, end - 6));								
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
																		
									InputStream is = new BufferedInputStream(new FileInputStream(f), 256);
									FileIdentifier.MusicInfo info = FileIdentifier.identify(f.getName(), is);
									is.close();
									boolean ok = false;
									if(info != null) {
										values.put("TITLE", info.title);
										values.put("COMPOSER", info.composer);
										//values.put("COPYRIGHT", info.copyright);
										values.put("DATE", info.date);
										values.put("FORMAT", info.format);
										//values.put("LENGTH", 0);
										ok = true;				
									}/* else {
										if(checkModule(f, values)) {
											ok = true;
										}
									} */
									
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
							isReady = false;
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
						isReady = false;
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
			
			for(File dump : foundDumps) {
				DataSource ds = dbsources.get(dump.getName().toUpperCase());
				isReady = false;
				if(scanCallback != null) {
					scanCallback.notifyScan(dump.getPath(), 0);
				}
				
				InputStream is = null;
				int size = -1;
				ZipFile zf = null;
				if(dump.getName().toUpperCase().endsWith(".ZIP")) {
					try {
						zf = new ZipFile(dump);
						Enumeration<? extends ZipEntry> entries = zf.entries();
						while(entries.hasMoreElements()) {
							ZipEntry ze = entries.nextElement();
							if(!ze.isDirectory()) {
								is = zf.getInputStream(ze);
								size = (int) ze.getSize();
								break;
							}
						}	
					} catch (ZipException e) {
					} catch (IOException e) {
					}
				} else {
					try {
						is = new FileInputStream(dump);
						size = (int) dump.length();					
					} catch (FileNotFoundException e) {
					}
				}
				
				try {
					if(is != null) {
						if(ds.parseDump(is, size, scanDb, scanCallback)) {
							ContentValues values = new ContentValues();
							values.put("PATH", dump.getParentFile().getPath());
							values.put("FILENAME", dump.getName());
							values.put("TYPE", TYPE_ARCHIVE);
							values.put("TITLE", ds.getTitle());
							Log.v(TAG, String.format("Inserting %s from dump (%s)", ds.getTitle(), dump.getPath()));
							scanDb.insert("FILES", "PATH", values);
							//db.setTransactionSuccessful();
							//Log.v(TAG, "ZIP TRANSATION SUCCESSFUL");
						}
						is.close();
					}
					if(zf != null) {
						zf.close();
					}
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			
			if(stopScanning) {
				return;
			}

			// Time to recursively scan sub-directories
			// scanDirs contains found dirs that exists in database

			for(String s : foundDirs) {
				File f = new File(parentDir, s);
				isReady = false;
				if(scanCallback != null) {
					scanCallback.notifyScan(f.getPath(), 0);
				}
				scanFiles(f, alwaysScan, lastScan);
			}			
			
			for(String s : foundDirsNew) {
				File f = new File(parentDir, s);
				isReady = false;
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

	public void scan(boolean full, String mdir) {
		Message msg = mHandler.obtainMessage(MSG_SCAN, full ? 1 : 0, 0, mdir);
		mHandler.sendMessage(msg);
	}

	public void rescan(String mdir) {
		Message msg = mHandler.obtainMessage(MSG_SCAN, 2, 0, mdir);
		mHandler.sendMessage(msg);
	}

	
	private void doScan(String modsDir, boolean full) {

		stopScanning = false;
		scanning = true;

		plugins = new DroidSoundPlugin[4];
		plugins[0] = new SidplayPlugin(context);
		plugins[1] = new ModPlugin(context);
		plugins[2] = new GMEPlugin(context);
		plugins[3] = new TFMXPlugin(context);
		
		FileIdentifier.setPlugins(plugins);


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
					isReady = false;
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
		
		if(!stopScanning) {
			ContentValues values = new ContentValues();
			values.put("VAR", "lastscan");
			values.put("VALUE", Long.toString(startTime));
			scanDb.update("VARIABLES", values, "VAR='lastscan'", null);
		}
		
		stopScanning = false;
		isReady = true;
		
		scanDb.close();
		scanDb = null;
		scanning = false;

		if(scanCallback != null) {
			scanCallback.notifyScan(null, -1);
		}

		//rdb.close();
	}

	public Cursor search(String query, String fromPath) {
		
		if(!isReady) {
			return null;
		}
		
		if(rdb == null) {
			rdb = getReadableDatabase();
		}
		
		
		for(Entry<String, DataSource> ds : dbsources.entrySet()) {
			if(fromPath.toUpperCase().contains("/" + ds.getKey())) {
				Cursor cursor = ds.getValue().search(query, fromPath, rdb);
				if(cursor != null) {
					return cursor;
				}
			}
		}

		String q = "%" + query + "%" ;
		
		Cursor c = rdb.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "PATH", "FILENAME", "TYPE", "DATE" }, "TITLE LIKE ?", new String[] { q }, null, null, "TITLE", "500");
		Log.v(TAG, String.format("Got %d hits", c.getCount()));
		return c;
	}
	
	public void closeDB() {
		if(rdb != null) {
			rdb.close();
			rdb = null;
		}
	}

	private Playlist currentPlaylist;
	private Playlist activePlaylist;

	private String pathTitle;

	public Playlist getCurrentPlaylist() {
		return currentPlaylist;
	}

	public Playlist getActivePlaylist() {
		return activePlaylist;
	}
	
	public void setActivePlaylist(File file) {		
		activePlaylist = Playlist.getPlaylist(file);
	}
	
	public String getPathTitle() {
		return pathTitle;
	}

	public Cursor getFilesInPath(String pathName) {
		
		if(pathName == null || !isReady) {
			return null;
		}

		pathTitle = null;
		
		String upath = pathName.toUpperCase();
		int dot = pathName.lastIndexOf('.');
		String ext = "";
		if(dot > 0) {
			ext = upath.substring(dot);
		}

		Log.v(TAG, String.format("files in path '%s'", pathName));
		//String name = new File(pathName).getName().toUpperCase();
		
		if(ext.equals(".LNK")) {
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
		}
		
		File file = new File(pathName);
		
		currentPlaylist = null;
		if(ext.equals(".PLIST")) {
			
			String name = file.getName();
			dot = name.lastIndexOf('.');
			if(dot > 0) {
				pathTitle = name.substring(0, dot);
			} else {
				pathTitle = name;
			}

			currentPlaylist = Playlist.getPlaylist(file);
			if(activePlaylist == null) {
				activePlaylist = currentPlaylist;
			}
			return currentPlaylist.getCursor();
		}

		if(rdb == null) {
			rdb = getReadableDatabase();
		}

		if(rdb.isDbLockedByOtherThreads()) {
			return null;
		}
		
		for(Entry<String, DataSource> db : dbsources.entrySet()) {
			if(upath.contains("/" + db.getKey())) {
				Cursor cursor = db.getValue().getCursorFromPath(file, rdb);
				if(cursor != null) {
					 pathTitle = db.getValue().getPathTitle(file);
					return cursor;
				}
			}
		}

		Log.v(TAG, String.format("Path now '%s'", pathName));

		String path = file.getParent();
		String fname = file.getName();
		
		if(path == null || fname == null) {
			return null;
		}
	
		Log.v(TAG, "BEGIN");
		Cursor c = rdb.query("FILES", new String[] { "TITLE", "TYPE" }, "PATH=? AND FILENAME=?", new String[] { path, fname }, null, null, "TYPE, FILENAME", "1000");
		if(c != null) {
			if(c.moveToFirst()) {
				pathTitle = c.getString(0);
			}
			c.close();
		}
		c = rdb.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "FILENAME", "TYPE", "DATE" }, "PATH=?", new String[] { pathName }, null, null, "TYPE, FILENAME", "1000");	
		Log.v(TAG, "END");
		return c;
	}
	
	public void backup() {
		Message msg = mHandler.obtainMessage(MSG_BACKUP);
		mHandler.sendMessage(msg);
	}
	
	public void setScanCallback(ScanCallback cb) {
		scanCallback = cb;
	}

	public void stopScan() {
		stopScanning = true;
		
	}

	public boolean isScanning() {
		// TODO Auto-generated method stub
		return scanning;
	}
	
	public void addToPlaylist(Playlist pl, SongFile songFile) {
		Log.v(TAG, String.format("Adding %s / %s to playlist %s", songFile.getPath(), songFile.getName(), pl.getFile().getName()));
		if(songFile.exists()) {
			if(songFile.getName().toUpperCase().endsWith(".PLIST")) {
				Playlist newpl = Playlist.getPlaylist(songFile.getFile());
				List<File> files = newpl.getFiles();
				Log.v(TAG, String.format("Adding %d files from playlist", files.size()));
				for(File f2 : files) {
					addToPlaylist(pl, new SongFile(f2));
				}
				
			} else {
				pl.add(songFile);
			}
		} else {
			if(rdb == null) {
				rdb = getReadableDatabase();
			}
			Cursor cursor = rdb.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "FILENAME", "PATH", "TYPE" }, "PATH=? AND FILENAME=?", new String[] { songFile.getParent(), songFile.getName() }, null, null, null);
			
			
			//Log.v(TAG, String.format("Got %d results from query", cursor.getCount()));
			
			if(cursor != null && cursor.moveToFirst()) {
				int type = cursor.getInt(cursor.getColumnIndex("TYPE"));
				if(type == SongDatabase.TYPE_DIR) {
					cursor.close();
					cursor = rdb.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "FILENAME", "PATH", "TYPE" }, "PATH=?", new String[] { songFile.getPath() }, null, null, "TITLE");
					if(cursor.moveToFirst()) {
						pl.add(cursor, -1);
					}
					
				} else if(type == SongDatabase.TYPE_FILE) {
					pl.add(cursor, songFile.getSubtune());
				}
			}
			cursor.close();
		}
	}
	
	public boolean deleteFile(File f) {
		SQLiteDatabase db = getWritableDatabase();
		if(db == null) {
			return false;
		}

		db.delete("FILES", "PATH=? AND FILENAME=?", new String [] { f.getParent(), f.getName() });		
		db.close();
		return true;

	}

	public boolean deleteDir(File f) {
		SQLiteDatabase db = getWritableDatabase();
		if(db == null) {
			return false;
		}

		// /sdcard/MODS/Dummy
		// /sdcard/MODS/Dummy  Dummy2
		// /sdcard/MODS/Dummy/Dummy2 
		
		String path = f.getPath();
		db.delete("FILES", "PATH=? AND FILENAME=?", new String [] { f.getParent(), f.getName()} );
		db.delete("FILES", "PATH LIKE ?", new String [] { path + "/%" } );
		db.delete("FILES", "PATH=?", new String [] { path } );
		db.close();
		return true;

	}

	public void createPlaylist(File file) {
		
		FileWriter writer;
		String n = file.getName();
		try {			
			writer = new FileWriter(file);
			writer.close();
			ContentValues values = new ContentValues();
			values.put("PATH", file.getParent());
			values.put("FILENAME", n);
			values.put("TYPE", TYPE_PLIST);
			int dot = n.indexOf('.');
			if(dot > 0) {
				values.put("TITLE", n.substring(0, dot));
			} else {
				values.put("TITLE", n);
			}
			
			SQLiteDatabase db = getWritableDatabase();
			db.insert("FILES", "PATH", values);
			db.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		}					
	}

	public void createFolder(File file) {
		
		if(file.mkdir()) {
			String n = file.getName();
			ContentValues values = new ContentValues();
			values.put("PATH", file.getParent());
			values.put("FILENAME", n);
			values.put("TYPE", TYPE_DIR);			
			SQLiteDatabase db = getWritableDatabase();
			if(db != null) {
				db.insert("FILES", "PATH", values);
				db.close();
			} else {
				file.delete();
			}
		}
	}
	/*
	public SongInfo getInfo(String md5) {
		
		int hash = (int)(Long.parseLong(md5.substring(24), 16) & 0xffffffff);
		String hashStr = Integer.toString(hash);
		
		if(rdb == null) {
			rdb = getReadableDatabase();
		}

		if(rdb.isDbLockedByOtherThreads()) {
			return null;
		}
		
		Cursor c = rdb.query("SONGINFO", new String [] { "MD5", "COMMENT", "SONGLENGTH" }, "HASH=?", new String[] { hashStr } ,null, null, null);

		SongInfo info = new SongInfo();
		
		if(c.getCount() == 1) {
			info.comment = c.getString(1);
			info.length = c.getString(2);
			return info;
		}
		
		while(c.moveToNext()) {
			String dbmd5 = c.getString(0);
			Log.v(TAG, String.format("Comparing %s to %s", dbmd5, md5));
			if(dbmd5.equals(md5)) {
				info.comment = c.getString(1);
				info.length = c.getString(2);
				return info;
			}			
		}
		
		return null;
	}
	*/
}
