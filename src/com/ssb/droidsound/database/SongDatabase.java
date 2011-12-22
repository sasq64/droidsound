package com.ssb.droidsound.database;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.zip.ZipEntry;
import java.util.zip.ZipException;
import java.util.zip.ZipInputStream;

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

import com.ssb.droidsound.FileIdentifier;
import com.ssb.droidsound.Playlist;
import com.ssb.droidsound.SongFile;
import com.ssb.droidsound.utils.Log;

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
	private static final String SEARCH_ORDER[] = new String[] { "TITLE", "COMPOSER", "DATE" };
	public static final int DB_VERSION = 6;

	private final Context context;

	private volatile Handler mHandler;

	private volatile boolean scanning;

	public static final int TYPE_ARCHIVE = 0x100;
	public static final int TYPE_DIR = 0x200;
	public static final int TYPE_PLIST = 0x300;
	public static final int TYPE_FILE = 0x400;

	public static final int SORT_TITLE = 0;
	public static final int SORT_AUHTOR = 1;
	public static final int SORT_DATE = 2;

	protected static final int MSG_SCAN = 0;
	protected static final int MSG_DOWNLOAD = 3;
	protected static final int MSG_QUIT = 4;
	protected static final int MSG_INDEXMODE = 5;

	public boolean isReadyToServe() {
		return mHandler != null;
	}

	public SongDatabase(Context ctx) {
		context = ctx;
		checkVersion();
	}

	private SQLiteDatabase getDatabase() {
		try {
			File dbName = context.getDatabasePath("songs.db");
			return SQLiteDatabase.openOrCreateDatabase(dbName, null);
		} catch (SQLException e) {
			throw new RuntimeException(e);
		}
	}

	@Override
	public void run() {
		Looper.prepare();

		mHandler = new Handler() {
			@Override
	        public void handleMessage(Message msg) {
	        	Log.d(TAG, "Got msg %d with arg %d", msg.what, msg.arg1);
	            switch (msg.what) {
	            case MSG_SCAN:
	            	try {
	            		doScan((String) msg.obj, msg.arg1 != 0);
	            	}
	            	catch (IOException ioe) {
	            		throw new RuntimeException(ioe);
	            	}
	            	break;
	            case MSG_QUIT:
	            	Looper.myLooper().quit();
	            	break;
	            }
			}
		};

		Intent intent = new Intent("com.sddb.droidsound.OPEN_DONE");
		context.sendBroadcast(intent);

		Looper.loop();

		Log.d(TAG, "Exiting songdatabase");
	}

	private void notifyScan(String path, int percent) {
		Intent intent = new Intent("com.sddb.droidsound.SCAN_UPDATE");
		intent.putExtra("PATH", path);
		intent.putExtra("PERCENT", percent);
		context.sendBroadcast(intent);
	}

	private void notifyScanComplete() {
		Intent intent = new Intent("com.sddb.droidsound.SCAN_DONE");
		context.sendBroadcast(intent);
	}

	private void checkVersion() {
		SQLiteDatabase db = getDatabase();
		try {
			if (db.needUpgrade(DB_VERSION)) {
				Log.i(TAG, "Database will be dropped and recreated...");
				notifyScan("Clearing tables", 0);
				Log.d(TAG, "Deleting file tables!");
				db.execSQL("DROP TABLE IF EXISTS FILES ;");
				db.execSQL("DROP TABLE IF EXISTS VARIABLES ;");
				db.execSQL("DROP TABLE IF EXISTS LINKS ;");

				notifyScan("Creating tables", 0);
				db.execSQL("CREATE TABLE IF NOT EXISTS " + "FILES" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
						"PATH" + " TEXT," +
						"FILENAME" + " TEXT," +
						"TYPE" + " INTEGER," +

						"TITLE" + " TEXT," +
						"COMPOSER" + " TEXT," +
						"DATE" + " INTEGER," +
						"FORMAT" + " TEXT" + ");");

				db.execSQL("CREATE TABLE IF NOT EXISTS " + "VARIABLES" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
						"VAR" + " TEXT," +
						"VALUE" + " TEXT" + ");");

				db.execSQL("CREATE INDEX I_FILES_PATH ON FILES (PATH);");
				db.setVersion(DB_VERSION);
				Log.i(TAG, "Database reconstruction complete");
			}
		} finally {
			db.close();
		}
	}

	/**
	 * Zips are scanned in one atomic unit. So db will be placed in transaction for this.
	 *
	 * @param zipFile
	 * @return
	 * @throws ZipException
	 * @throws IOException
	 */
	private void scanZip(File zipFile) throws ZipException, IOException {
		SQLiteDatabase db = getDatabase();
		Log.i(TAG, "Scanning ZIP %s for files...", zipFile.getPath());
		db.delete("FILES", "PATH = ? OR PATH LIKE ?", new String [] { zipFile.getPath(), zipFile.getPath() + "/%" });

		FileInputStream fis = new FileInputStream(zipFile);
		ZipInputStream zis = new ZipInputStream(fis);
		Set<String> pathSet = new HashSet<String>();

		ContentValues values = new ContentValues();
		values.put("TYPE", TYPE_FILE);

		ZipEntry ze;
		int count = 0;
		while (null != (ze = zis.getNextEntry())) {
			int slash = ze.getName().lastIndexOf('/');
			final String path;
			final String fileName;
			if (slash == -1) {
				path = zipFile.getPath();
				fileName = ze.getName();
			} else {
				path = zipFile.getPath() + "/" + ze.getName().substring(0, slash);
				fileName = ze.getName().substring(slash  + 1);
			}

			Log.i(TAG, "Parsed %s to path='%s' and name='%s'", ze.getName(), path, fileName);
			if (fileName.equals("")) {
				pathSet.add(path);
			} else {
				FileIdentifier.MusicInfo info = FileIdentifier.identify(ze.getName(), readFully(zis, ze.getSize()));
				if (info != null) {
					values.put("TITLE", info.title);
					values.put("COMPOSER", info.composer);
					values.put("DATE", info.date);
					values.put("FORMAT", info.format);
					values.put("PATH", path);
					values.put("FILENAME", fileName);
					db.insert("FILES", "PATH", values);
				} else {
					Log.w(TAG, "Could not identify '%s'", ze.getName());
				}
			}

			if (count ++ % 100 == 0) {
				notifyScan(zipFile.getName(), (int) (fis.getChannel().position() / (fis.getChannel().size() / 100)));
				zis.closeEntry();
			}
		}

		zis.close();

		Log.i(TAG, "Adding %d paths", pathSet.size());

		values.clear();
		values.put("TYPE", TYPE_DIR);
		for (String s : pathSet) {
			int slash = s.lastIndexOf('/');
			String fileName = s.substring(slash+1);
			String path = s.substring(0, slash);

			values.put("PATH", path);
			values.put("FILENAME", fileName);
			db.insert("FILES", "PATH", values);
		}

		db.close();
	}

	private void scanFiles(File dir, long lastScan) throws IOException {
		boolean hasChanged = lastScan < dir.lastModified();
		Log.d(TAG, "Entering '%s', lastScan %d, going to scan: %s", dir.getPath(), lastScan, String.valueOf(hasChanged));

		SQLiteDatabase db = getDatabase();
		Cursor fileCursor = db.query("FILES", new String[] { BaseColumns._ID, "FILENAME", "TYPE" }, "PATH=?", new String[] { dir.getPath() }, null, null, null);

		/* If there is no change in this directory, we'll just pick the directories to
		 * recurse into from db. */
		Set<String> files = new HashSet<String>();
		if (! hasChanged) {
			while (fileCursor.moveToNext()) {
				String fileName = fileCursor.getString(1);
				int type = fileCursor.getInt(2);
				if (type == TYPE_DIR) {
					files.add(fileName);
				}
			}

			Log.d(TAG, "No change, scanning %d Datbase entries with %d dirs", fileCursor.getCount(), files.size());

			fileCursor.close();
			db.close();

			for (String f : files) {
				scanFiles(new File(dir, f), lastScan);
			}
			return;
		}

		notifyScan(dir.getPath(), 0);

		/** Going to recurse into these */
		Set<String> foundDirs = new HashSet<String>();
		/** Going to add directory entry, then recurse into these */
		Set<String> foundDirsNew = new HashSet<String>();

		for (File f : dir.listFiles()) {
			if (f.getName().charAt(0) != '.') {
				files.add(f.getName());
			}
		}

		Log.d(TAG, "Datbase has %d entries, found %d files/dirs", fileCursor.getCount(), files.size());

		Set<String> delDirs = new HashSet<String>();
		Set<Long> delFiles = new HashSet<Long>();

		Log.d(TAG, "Comparing DB to FS");

		// Iterate over database result and compare to hash set
		while (fileCursor.moveToNext()) {
			long id = fileCursor.getLong(0);
			String fileName = fileCursor.getString(1);
			int type = fileCursor.getInt(2);

			if (files.contains(fileName)) {
				File f = new File(dir, fileName);

				if (f.isDirectory()) {
					foundDirs.add(fileName);
					files.remove(fileName);
				} else {
					if (lastScan < f.lastModified()) {
						Log.i(TAG, "Change in file detected: %s", fileName);
						delFiles.add(id);
					} else {
						files.remove(fileName);
					}
				}
			} else {
				Log.d(TAG, "!! '%s' found in DB but not on disk, DELETING", fileName);
				// File has been removed on disk, schedule for DELETE
				if (type == TYPE_FILE) {
					delFiles.add(id);
				} else {
					delDirs.add(fileName);
				}
			}
		}

		// Close cursor (important since we call ourselves recursively below)
		fileCursor.close();
		fileCursor = null;

		for (String d : delDirs) {
			String path = new File(dir, d).getPath();
			Log.i(TAG, "Deleting PATH %s and subdirs", path);
			db.delete("FILES", "(PATH=? AND FILENAME=?) OR PATH LIKE ? OR PATH=?", new String [] { dir.getPath(), d, path+"/%", path} );
		}

		for (long id : delFiles) {
			Log.i(TAG, "Deleting FILE %d in %s", id, dir.getPath());
			db.delete("FILES", "_id=?", new String [] { String.valueOf(id) } );
		}

		for (String fn : files) {
			ContentValues values = new ContentValues();
			values.put("PATH", dir.getPath());
			values.put("FILENAME", fn);

			File f = new File(dir, fn);
			if (f.isFile()) {
				if (fn.toUpperCase().endsWith(".ZIP")) {
					notifyScan(f.getPath(), 0);
					scanZip(f);
					values.put("TYPE", TYPE_ARCHIVE);
					values.put("TITLE", f.getName().substring(0, fn.length() - 4));
				} else if (fn.toUpperCase().endsWith(".PLIST")) {
					values.put("TYPE", TYPE_PLIST);
					values.put("TITLE", fn.substring(0, fn.length() - 6));
				} else {
					values.put("TYPE", TYPE_FILE);
					FileIdentifier.MusicInfo info = FileIdentifier.identify(f.getName(), readFully(new FileInputStream(f), f.length()));
					if (info != null) {
						values.put("TITLE", info.title);
						values.put("COMPOSER", info.composer);
						values.put("DATE", info.date);
						values.put("FORMAT", info.format);
					} else {
						values = null;
					}
				}
			} else if (f.isDirectory()) {
				foundDirsNew.add(fn);
				values.put("TYPE", TYPE_DIR);
			} else {
				Log.i(TAG, "Not adding file %s (not file or directory)", f.getName());
			}

			if (values != null) {
				Log.d(TAG, "Inserting FILE... (%s)", f.getName());
				db.insert("FILES", "PATH", values);
			}
		}
		db.close();

		for (String s : foundDirs) {
			File f = new File(dir, s);
			notifyScan(f.getPath(), 0);
			scanFiles(f, lastScan);
		}

		for (String s : foundDirsNew) {
			File f = new File(dir, s);
			notifyScan(f.getPath(), 0);
			scanFiles(f, lastScan);
		}
	}

	private byte[] readFully(InputStream is, long length) throws IOException {
		byte[] data = new byte[(int) length];
		new DataInputStream(is).readFully(data);
		return data;
	}

	public void scan(boolean full, String mdir) {
		Message msg = mHandler.obtainMessage(MSG_SCAN, full ? 1 : 0, 0, mdir);
		mHandler.sendMessage(msg);
	}

	private void doScan(String modsDir, boolean full) throws IOException {
		SQLiteDatabase db = getDatabase();
		scanning = true;

		long startTime = System.currentTimeMillis();
		long lastScan = -1;
		Cursor cursor = db.query("VARIABLES", new String[] { "VAR", "VALUE" }, "VAR='lastscan'", null, null, null, null);
		if (cursor.getCount() == 0) {
			ContentValues values = new ContentValues();
			values.put("VAR", "lastscan");
			values.put("VALUE", Long.toString(startTime));
			db.insert("VARIABLES", "VAR", values);
		} else {
			cursor.moveToFirst();
			lastScan = Long.parseLong(cursor.getString(1));
			ContentValues values = new ContentValues();
			values.put("VAR", "lastscan");
			values.put("VALUE", Long.toString(startTime));
			db.update("VARIABLES", values, "VAR='lastscan'", null);
		}
		cursor.close();

		Log.d(TAG, "Last scan %d\n", lastScan);

		File parentDir = new File(modsDir);
		if (full) {
			db.execSQL("DELETE FROM FILES;");
			lastScan = 0;
		}

		scanFiles(parentDir, lastScan);

		db.close();
		scanning = false;

		notifyScanComplete();
	}

	public Cursor search(String query, String fromPath, int sorting) {
		SQLiteDatabase db = getDatabase();

		final Cursor c;
		String [] columns = new String[] { "_id", "TITLE", "COMPOSER", "PATH", "FILENAME", "TYPE", "DATE" };
		String q = "%" + query + "%" ;
		c = db.query("FILES", columns, "TITLE LIKE ? OR COMPOSER LIKE ?", new String[] { q, q }, null, null, SEARCH_ORDER[sorting], "500");
		Log.d(TAG, "Got %d hits", c.getCount());

		db.close();
		return c;
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

	private static String sortOrder [] = new String[] { "TYPE, TITLE, FILENAME", "TYPE, DATE, FILENAME", "TYPE, COMPOSER, FILENAME" };

	private final Map<String, String> linkMap = new HashMap<String, String>();

	public Cursor getFilesInPath(String pathName, int sorting) {
		pathTitle = null;

		String upath = pathName.toUpperCase();
		int dot = pathName.lastIndexOf('.');
		String ext = "";
		if(dot > 0) {
			ext = upath.substring(dot);
		}

		Log.d(TAG, "files in path '%s'", pathName);
		//String name = new File(pathName).getName().toUpperCase();

		int lIndex = upath.indexOf(".LNK");
		if(lIndex > 0) {
			String linkPath = pathName.substring(0, lIndex+4);
			Log.d(TAG, "linkPath '%s'", linkPath);
			String linkTarget = linkMap.get(linkPath);
			if(linkTarget == null) {
				try {
					File f = new File(linkPath);
					BufferedReader reader = new BufferedReader(new FileReader(f));
					String p = reader.readLine();
					reader.close();
					if(p != null && p.length() > 0) {
						linkTarget = p;
						linkMap.put(linkPath, linkTarget);
					}
				} catch (FileNotFoundException e) {
					e.printStackTrace();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}

			pathName = linkTarget + pathName.substring(lIndex+4);

			Log.d(TAG, "Translated to '%s'", pathName);
		}

		currentPlaylist = null;

		File file = new File(pathName);
		if (ext.equals(".PLIST")) {
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

		SQLiteDatabase db = getDatabase();
		String path = file.getParent();
		String fname = file.getName();

		if(path == null || fname == null) {
			return null;
		}

		Log.d(TAG, "BEGIN");
		Cursor c = db.query("FILES", new String[] { "TITLE", "TYPE" }, "PATH=? AND FILENAME=?", new String[] { path, fname }, null, null, sortOrder[sorting], "5000");
		if (c != null) {
			if (c.moveToFirst()) {
				pathTitle = c.getString(0);
			}
			c.close();
		}

		c = db.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "FILENAME", "TYPE", "DATE" }, "PATH=?", new String[] { pathName }, null, null, sortOrder[sorting], "5000");
		c.getCount(); // force to memory
		db.close();
		return c;
	}

	public boolean isScanning() {
		return scanning;
	}

	public void addToPlaylist(Playlist pl, SongFile songFile) throws IOException {
		if (pl.contains(songFile)) {
			Log.d(TAG, "Song exists, ignoring");
			return;
		}

		if (songFile.getName().toUpperCase().endsWith(".ZIP")) {
			Log.d(TAG, "WONT add zip files");
			return;
		}

		if (songFile.exists()) {
			if (songFile.getName().toUpperCase().endsWith(".PLIST")) {
				Playlist newpl = Playlist.getPlaylist(songFile.getFile());
				List<SongFile> files = newpl.getSongs();
				Log.d(TAG, "Adding %d files from playlist", files.size());
				for (SongFile f2 : files) {
					addToPlaylist(pl, f2);
				}

			} else {
				pl.add(songFile);
			}
		} else {
			SQLiteDatabase db = getDatabase();
			Cursor cursor = db.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "FILENAME", "PATH", "TYPE" }, "PATH=? AND FILENAME=?", new String[] { songFile.getParent(), songFile.getName() }, null, null, null);

			if(cursor != null && cursor.moveToFirst()) {
				int type = cursor.getInt(cursor.getColumnIndex("TYPE"));
				if(type == SongDatabase.TYPE_DIR) {
					cursor.close();
					cursor = db.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "FILENAME", "PATH", "TYPE" }, "PATH=?", new String[] { songFile.getPath() }, null, null, "TITLE");
					if(cursor.moveToFirst()) {
						pl.add(cursor, -1, null);
					}

				} else if(type == SongDatabase.TYPE_FILE) {
					pl.add(cursor, songFile.getSubtune(), songFile.getTitle());
				}
			}
			cursor.close();
		}
	}

	public boolean deleteFile(SongFile song) {
		return deleteFile(song.getFile());
	}

	public boolean deleteFile(File f) {
		SQLiteDatabase db = getDatabase();
		if(db == null) {
			return false;
		}

		db.delete("FILES", "PATH=? AND FILENAME=?", new String [] { f.getParent(), f.getName() });
		db.close();
		return true;

	}

	public boolean deleteDir(File f) {
		SQLiteDatabase db = getDatabase();
		String path = f.getPath();
		db.delete("FILES", "(PATH=? AND FILENAME=?) OR PATH LIKE ? OR PATH = ?", new String [] { f.getParent(), f.getName(), path + "/%", path });
		db.close();
		return true;

	}

	public void createPlaylist(File file) throws IOException {
		FileWriter writer = new FileWriter(file);
		writer.close();
		ContentValues values = new ContentValues();
		values.put("PATH", file.getParent());
		values.put("FILENAME", file.getName());
		values.put("TYPE", TYPE_PLIST);
		int dot = file.getName().indexOf('.');
		if(dot > 0) {
			values.put("TITLE", file.getName().substring(0, dot));
		} else {
			values.put("TITLE", file.getName());
		}

		SQLiteDatabase db = getDatabase();
		db.insert("FILES", "PATH", values);
		db.close();
	}

	public void createFolder(File file) {
		if(file.mkdir()) {
			String n = file.getName();
			ContentValues values = new ContentValues();
			values.put("PATH", file.getParent());
			values.put("FILENAME", n);
			values.put("TYPE", TYPE_DIR);
			SQLiteDatabase db = getDatabase();
			if(db != null) {
				db.insert("FILES", "PATH", values);
				db.close();
			} else {
				file.delete();
			}
		}
	}

	public void quit() {
		Message msg = mHandler.obtainMessage(MSG_QUIT);
		mHandler.sendMessage(msg);
	}
}
