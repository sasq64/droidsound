package com.ssb.droidsound.service;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
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

	private static final String TAG = SongDatabaseService.class.getSimpleName();

	private static final String[] COLUMNS = new String[] { "_id", "parent_id", "filename", "type", "title", "composer", "date" };
	public static final int COL_ID = 0;
	public static final int COL_PARENT_ID = 1;
	public static final int COL_FILENAME = 2;
	public static final int COL_TYPE = 3;
	public static final int COL_TITLE = 4;
	public static final int COL_COMPOSER = 5;
	public static final int COL_DATE = 6;

	public static final String SCAN_NOTIFY_BEGIN = "com.sddb.droidsound.SCAN_NOTIFY_BEGIN";
	public static final String SCAN_NOTIFY_UPDATE = "com.sddb.droidsound.SCAN_NOTIFY_UPDATE";
	public static final String SCAN_NOTIFY_DONE = "com.sddb.droidsound.SCAN_NOTIFY_DONE";

	public static final int DB_VERSION = 9;

	public static final int TYPE_ARCHIVE = 0x100;
	public static final int TYPE_DIR = 0x200;
	public static final int TYPE_PLIST = 0x300;
	public static final int TYPE_FILE = 0x400;
	public static final int TYPE_MUS_FOLDER = 0x500;

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
				doScan(Application.getModsDirectory(), full);
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
		private void scanZip(File zipFile, Long parentId) throws ZipException, IOException {
			Log.i(TAG, "Scanning ZIP %s for files...", zipFile.getPath());
			db.delete("files", "parent_id = ?", new String [] { String.valueOf(parentId) });

			FileInputStream fis = new FileInputStream(zipFile);
			ZipInputStream zis = new ZipInputStream(fis);
			Map<String, Long> pathMap = new HashMap<String, Long>();
			pathMap.put("", parentId);

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
					path = ze.getName().substring(0, slash);
					fileName = ze.getName().substring(slash  + 1);
				}

				final long pathParentId;
				if ("".equals(fileName)) {
					int slash2 = path.lastIndexOf('/');
					final String pathFilename;
					if (slash2 == -1) {
						/* top level in zip: parent to given directory */
						Log.i(TAG, "Zip: directory %s is in top level", path);
						pathParentId = parentId;
						pathFilename = path;
					} else {
						String pathParent = path.substring(0, slash2);
						pathFilename = path.substring(slash2 + 1);
						Log.i(TAG, "Zip: looking up parent %s for directory: %s", pathParent, pathFilename);
						pathParentId = pathMap.get(pathParent);
					}

					/* Is directory. Pick the part before the last filename */
					ContentValues values = new ContentValues();
					values.put("type", TYPE_DIR);
					values.put("parent_id", pathParentId);
					values.put("filename", pathFilename);
					long rowId = db.insert("files", null, values);
					pathMap.put(path, rowId);
				} else {
					pathParentId = pathMap.get(path);
					DroidSoundPlugin.MusicInfo info = DroidSoundPlugin.identify(ze.getName(), StreamUtil.readFully(zis, ze.getSize()));
					ContentValues values = new ContentValues();
					values.put("parent_id", pathParentId);
					values.put("type", TYPE_FILE);
					values.put("filename", fileName);
					if (info != null) {
						values.put("title", info.title);
						values.put("composer", info.composer);
						values.put("date", info.date);
						values.put("format", info.format);
					}
					db.insert("files", null, values);
					Log.i(TAG, "Zip: added file %s", fileName);
				}

				if (count ++ % 100 == 0) {
					publishProgress(zipFile.getName(), (int) (fis.getChannel().position() / (fis.getChannel().size() / 100)));
					zis.closeEntry();
				}
			}

			zis.close();
		}

		/**
		 * Dir scan. Roots of the tree are those with parentId = null.
		 */
		private void scanFiles(File dir, Long parentId, long lastScan) throws IOException {
			boolean hasChanged = lastScan < dir.lastModified();
			Log.d(TAG, "Entering '%s', lastScan %d, going to scan: %s", dir.getPath(), lastScan, String.valueOf(hasChanged));

			final Cursor fileCursor;
			if (parentId == null) {
				fileCursor = db.query(
					"files",
					new String[] { BaseColumns._ID, "filename", "type" },
					"parent_id IS NULL", null,
					null, null, null
				);
			} else {
				fileCursor = db.query(
						"files",
						new String[] { BaseColumns._ID, "filename", "type" },
						"parent_id = ?", new String[] { String.valueOf(parentId) },
						null, null, null
				);
			}

			/** Going to recurse into these */
			Map<Long, String> dirsInDatabase = new HashMap<Long, String>();
			publishProgress(dir.getName(), 0);

			/* If there is no change in this directory, we'll just pick the directories to
			 * recurse into from db. */
			if (! hasChanged) {
				while (fileCursor.moveToNext()) {
					long id = fileCursor.getLong(0);
					String fileName = fileCursor.getString(1);
					int type = fileCursor.getInt(2);
					if (type == TYPE_DIR) {
						dirsInDatabase.put(id, fileName);
					}
				}
			} else {
				/**
				 * Set of files in examined directory. Entries are removed from this set
				 * if they are also found on the database.
				 */
				Set<String> files = new HashSet<String>();
				for (File f : dir.listFiles()) {
					String n = f.getName();
					if (! n.startsWith(".")) {
						files.add(n);
					}
				}

				Log.d(TAG, "Datbase has %d entries, found %d files/dirs", fileCursor.getCount(), files.size());
				Set<Long> delFiles = new HashSet<Long>();

				Log.d(TAG, "Comparing DB to FS");

				// Iterate over database result and compare to hash set
				while (fileCursor.moveToNext()) {
					Long id = fileCursor.getLong(0);
					String fileName = fileCursor.getString(1);

					if (files.contains(fileName)) {
						File f = new File(dir, fileName);

						/* FIXME: there's no test to make sure the type is right */
						if (f.isDirectory()) {
							dirsInDatabase.put(id, fileName);
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
						delFiles.add(id);
					}
				}

				for (long id : delFiles) {
					db.delete("files", "_id = ?", new String[] { String.valueOf(id) } );
				}

				for (String fn : files) {
					ContentValues values = new ContentValues();
					values.put("parent_id", parentId);
					values.put("filename", fn);

					File f = new File(dir, fn);
					if (f.isFile()) {
						if (fn.toUpperCase().endsWith(".ZIP")) {
							values.put("type", TYPE_ARCHIVE);
							values.put("title", f.getName().substring(0, fn.length() - 4));
							long rowId = db.insert("files", null, values);
							scanZip(f, rowId);
							continue;

						}
						if (fn.toUpperCase().endsWith(".PLIST")) {
							values.put("type", TYPE_PLIST);
							values.put("title", fn.substring(0, fn.length() - 6));
							db.insert("files", null, values);
							continue;
						}

						values.put("type", TYPE_FILE);
						DroidSoundPlugin.MusicInfo info = DroidSoundPlugin.identify(f.getName(), StreamUtil.readFully(new FileInputStream(f), f.length()));
						if (info != null) {
							values.put("title", info.title);
							values.put("composer", info.composer);
							values.put("date", info.date);
							values.put("format", info.format);
							db.insert("files", null, values);
						}
						continue;

					} else if (f.isDirectory()) {
						values.put("type", TYPE_DIR);
						long rowId = db.insert("files", null, values);
						scanFiles(f, rowId, lastScan);
					} else {
						Log.i(TAG, "Not adding file %s (not file or directory)", f.getName());
					}
				}
			}

			// Close cursor (important since we call ourselves recursively below)
			fileCursor.close();

			/* Continue scanning down */
			for (Entry<Long, String> e : dirsInDatabase.entrySet()) {
				scanFiles(new File(dir, e.getValue()), e.getKey(), lastScan);
			}
		}

		private void doScan(File modsDir, boolean full) throws IOException {
			long lastScan = 0;
			Cursor cursor = db.query("variables", new String[] { "value" }, "var = ?", new String[] { "lastscan" }, null, null, null);
			ContentValues values = new ContentValues();
			values.put("value", Long.toString(System.currentTimeMillis()));
			if (cursor.getCount() == 0) {
				values.put("var", "lastscan");
				db.insert("variables", null, values);
			} else {
				cursor.moveToFirst();
				lastScan = Long.parseLong(cursor.getString(0));
				db.update("variables", values, "var = ?", new String[] { "lastscan" });
			}
			cursor.close();

			Log.d(TAG, "Last scan %d\n", lastScan);

			if (full) {
				publishProgress(modsDir.getPath(), 0);
				db.delete("files", null, null);
				lastScan = 0;
			}

			scanFiles(modsDir, null, lastScan);
		}

		@Override
		protected void onPostExecute(Void result) {
			Intent intent = new Intent(SCAN_NOTIFY_DONE);
			sendBroadcast(intent);
		}
	}

	public class LocalBinder extends Binder {
		public void scan(boolean full) {
			new Scanner(full).execute();
		}

		public Cursor search(String query, int sorting) {
			String q = "%" + query + "%" ;
			return db.query("files",
					COLUMNS,
					"title LIKE ? OR composer LIKE ? OR filename LIKE ?", new String[] { q, q, q },
					null, null, String.valueOf(Sort.values()[sorting]) + " ASC");
		}

		/**
		 * Return files in collection.
		 *
		 * @param file
		 * @param sorting
		 * @return Cursor to read from
		 */
		public Cursor getFilesInPath(Long parentId, Sort sorting) {
			if (parentId == null) {
				return db.query(
						"files",
						COLUMNS,
						"parent_id IS NULL", null,
						null, null, String.valueOf(sorting) + ", FILENAME"
				);
			} else {
				return db.query(
						"files",
						COLUMNS,
						"parent_id = ?", new String[] { String.valueOf(parentId) },
						null, null, String.valueOf(sorting) + ", FILENAME"
				);
			}
		}

		public Cursor getFileById(long id) {
			return db.query(
					"files",
					COLUMNS,
					"_id = ?", new String[] { String.valueOf(id) },
					null, null, null
			);
		}

		public File getFilePath(long childId) {
			List<String> list = new ArrayList<String>();
			long currentId = childId;
			while (true) {
				Cursor c = null;
				try {
					c = getFileById(currentId);
					c.moveToFirst();
					list.add(c.getString(COL_FILENAME));
					if (c.isNull(COL_PARENT_ID)) {
						break;
					}
					currentId = c.getLong(COL_PARENT_ID);
				}
				finally {
					c.close();
				}
			}
			File path = Application.getModsDirectory();
			Collections.reverse(list);
			for (String component : list) {
				path = new File(path, component);
			}
			Log.i(TAG, "Determined file path: %s", path);

			return path;
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
			Log.i(TAG, "Deleting old schema (if any)...");
			db.execSQL("DROP TABLE IF EXISTS files;");
			db.execSQL("DROP TABLE IF EXISTS variables;");

			Log.i(TAG, "Creating new schema...");
			db.execSQL("CREATE TABLE IF NOT EXISTS files ("
					+ BaseColumns._ID + " INTEGER PRIMARY KEY,"
					+ "parent_id INTEGER REFERENCES files ON DELETE CASCADE,"
					+ "filename TEXT,"
					+ "type INTEGER,"
					+ "title TEXT,"
					+ "composer TEXT,"
					+ "date INTEGER,"
					+ "format TEXT"
					+ ");");

			db.execSQL("CREATE TABLE IF NOT EXISTS variables ("
					+ BaseColumns._ID + " INTEGER PRIMARY KEY,"
					+ "var TEXT,"
					+ "value TEXT"
					+ ");");

			db.execSQL("CREATE INDEX ui_files_parent_filename ON files (parent_id, filename);");
			db.setVersion(DB_VERSION);
			Log.i(TAG, "Schema complete.");
		}

		return db;
	}
}
