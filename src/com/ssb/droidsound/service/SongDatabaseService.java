package com.ssb.droidsound.service;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;
import java.util.zip.ZipEntry;
import java.util.zip.ZipException;
import java.util.zip.ZipInputStream;

import android.app.Service;
import android.content.ContentValues;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.AsyncTask;
import android.os.Binder;
import android.os.IBinder;
import android.provider.BaseColumns;

import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.StreamUtil;

public class SongDatabaseService extends Service {
	public enum Sort { TITLE, COMPOSER, FILENAME }

	public static final int COL_ID = 0;
	public static final int COL_TITLE = 1;
	public static final int COL_COMPOSER = 2;
	public static final int COL_PATH = 3;
	public static final int COL_FILENAME = 4;
	public static final int COL_TYPE = 5;
	public static final int COL_DATE = 6;

	public static final String SCAN_NOTIFY_BEGIN = "com.sddb.droidsound.SCAN_NOTIFY_BEGIN";
	public static final String SCAN_NOTIFY_UPDATE = "com.sddb.droidsound.SCAN_NOTIFY_UPDATE";
	public static final String SCAN_NOTIFY_DONE = "com.sddb.droidsound.SCAN_NOTIFY_DONE";

	private static final String TAG = SongDatabaseService.class.getSimpleName();
	public static final int DB_VERSION = 6;

	public static final int TYPE_ARCHIVE = 0x100;
	public static final int TYPE_DIR = 0x200;
	public static final int TYPE_PLIST = 0x300;
	public static final int TYPE_FILE = 0x400;

	private SQLiteDatabase db;

	protected class Scanner extends AsyncTask<Void, Object, Void> {
		private final boolean full;

		protected Scanner(boolean full) {
			this.full = full;
		}

		@Override
		protected void onPreExecute() {
			Intent intent = new Intent(SCAN_NOTIFY_BEGIN);
			sendBroadcast(intent);
		}

		@Override
		protected void onProgressUpdate(Object... values) {
			Intent intent = new Intent(SCAN_NOTIFY_UPDATE);
			intent.putExtra("path", (String) values[0]);
			intent.putExtra("progress", (Integer) values[1]);
			sendBroadcast(intent);
		}

		@Override
		protected Void doInBackground(Void... ignored) {
			try {
				doScan(Application.getModsDirectory().getPath(), full);
			} catch (IOException e) {
				Log.w(TAG, "Unable to finish scan", e);
			}
			return null;
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
					DroidSoundPlugin.MusicInfo info = DroidSoundPlugin.identify(ze.getName(), StreamUtil.readFully(zis, ze.getSize()));
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
					publishProgress(zipFile.getName(), (int) (fis.getChannel().position() / (fis.getChannel().size() / 100)));
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
		}

		private void scanFiles(File dir, long lastScan) throws IOException {
			boolean hasChanged = lastScan < dir.lastModified();
			Log.d(TAG, "Entering '%s', lastScan %d, going to scan: %s", dir.getPath(), lastScan, String.valueOf(hasChanged));

			Cursor fileCursor = db.query(
					"FILES",
					new String[] { BaseColumns._ID, "FILENAME", "TYPE" },
					"PATH=?", new String[] { dir.getPath() },
					null, null, null
			);

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

				Log.d(TAG, "No change, scanned %d database entries with %d dirs", fileCursor.getCount(), files.size());

				fileCursor.close();

				for (String f : files) {
					scanFiles(new File(dir, f), lastScan);
				}
				return;
			}

			publishProgress(dir.getPath(), 0);

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
						scanZip(f);
						values.put("TYPE", TYPE_ARCHIVE);
						values.put("TITLE", f.getName().substring(0, fn.length() - 4));
					} else if (fn.toUpperCase().endsWith(".PLIST")) {
						values.put("TYPE", TYPE_PLIST);
						values.put("TITLE", fn.substring(0, fn.length() - 6));
					} else {
						values.put("TYPE", TYPE_FILE);
						DroidSoundPlugin.MusicInfo info = DroidSoundPlugin.identify(f.getName(), StreamUtil.readFully(new FileInputStream(f), f.length()));
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

			for (String s : foundDirs) {
				File f = new File(dir, s);
				scanFiles(f, lastScan);
			}

			for (String s : foundDirsNew) {
				File f = new File(dir, s);
				scanFiles(f, lastScan);
			}
		}

		private void doScan(String modsDir, boolean full) throws IOException {
			long lastScan = 0;
			Cursor cursor = db.query("VARIABLES", new String[] { "VALUE" }, "VAR=?", new String[] { "lastscan" }, null, null, null);
			ContentValues values = new ContentValues();
			values.put("VAR", "lastscan");
			values.put("VALUE", Long.toString(System.currentTimeMillis()));
			if (cursor.getCount() == 0) {
				db.insert("VARIABLES", "VAR", values);
			} else {
				cursor.moveToFirst();
				lastScan = Long.parseLong(cursor.getString(0));
				db.update("VARIABLES", values, "VAR=?", new String[] { "lastscan" });
			}
			cursor.close();

			Log.d(TAG, "Last scan %d\n", lastScan);

			File parentDir = new File(modsDir);
			if (full) {
				publishProgress(modsDir, 0);
				db.execSQL("DELETE FROM FILES;");
				lastScan = 0;
			}

			scanFiles(parentDir, lastScan);
		}

		@Override
		protected void onPostExecute(Void result) {
			Intent intent = new Intent(SCAN_NOTIFY_DONE);
			sendBroadcast(intent);
		}
	}

	public class LocalBinder extends Binder {
		private final String[] COLUMNS = new String[] { "_id", "TITLE", "COMPOSER", "PATH", "FILENAME", "TYPE", "DATE" };

		public void scan(boolean full) {
			new Scanner(full).execute();
		}

		public Cursor search(String query, String fromPath, int sorting) {
			String q = "%" + query + "%" ;
			return db.query("FILES",
					COLUMNS,
					"TITLE LIKE ? OR COMPOSER LIKE ? OR PATH LIKE ? OR FILENAME LIKE ?", new String[] { q, q, q, q },
					null, null, String.valueOf(Sort.values()[sorting]) + " ASC");
		}

		public Cursor getFilesInPath(File file, Sort sorting) {
			return db.query(
					"FILES",
					COLUMNS,
					"PATH=?", new String[] { file.getPath() },
					null, null, String.valueOf(sorting) + ", FILENAME"
			);
		}
	};

	private final IBinder localBinder = new LocalBinder();

	@Override
	public IBinder onBind(Intent arg0) {
		return localBinder;
	}

	@Override
	public void onCreate() {
		super.onCreate();
		db = checkVersion();
	}

	@Override
	public void onDestroy() {
		super.onDestroy();
		db.close();
	}

	private SQLiteDatabase checkVersion() {
		File dbName = getDatabasePath("songs.db");
		SQLiteDatabase db = SQLiteDatabase.openOrCreateDatabase(dbName, null);
		if (db.needUpgrade(DB_VERSION)) {
			Log.i(TAG, "Deleting schema...");
			db.execSQL("DROP TABLE IF EXISTS FILES ;");
			db.execSQL("DROP TABLE IF EXISTS VARIABLES ;");
			db.execSQL("DROP TABLE IF EXISTS LINKS ;");

			Log.i(TAG, "Creating schema...");
			db.execSQL("CREATE TABLE IF NOT EXISTS " + "FILES" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
					"PATH" + " TEXT," +
					"FILENAME" + " TEXT," +
					"TYPE" + " INTEGER," +

					"TITLE" + " TEXT," +
					"COMPOSER" + " TEXT," +
					"DAT	E" + " INTEGER," +
					"FORMAT" + " TEXT" + ");");

			db.execSQL("CREATE TABLE IF NOT EXISTS " + "VARIABLES" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
					"VAR" + " TEXT," +
					"VALUE" + " TEXT" + ");");

			db.execSQL("CREATE INDEX I_FILES_PATH ON FILES (PATH);");
			db.setVersion(DB_VERSION);
			Log.i(TAG, "Schema complete.");
		}

		return db;
	}
}
