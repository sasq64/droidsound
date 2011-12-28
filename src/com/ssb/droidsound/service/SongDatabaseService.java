package com.ssb.droidsound.service;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
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
import com.ssb.droidsound.bo.SongFile;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.StreamUtil;

public class SongDatabaseService extends Service {
	public enum Sort {
		TITLE, COMPOSER, FILENAME;

		protected String toSQL() {
			return "type, lower(" + String.valueOf(this).toLowerCase() + "), lower(filename)";
		}
	}

	private static final String TAG = SongDatabaseService.class.getSimpleName();
	public static final Charset ISO88591 = Charset.forName("ISO-8859-1");

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

	public static final int TYPE_ZIP = 0x100;
	public static final int TYPE_DIR = 0x200;
	public static final int TYPE_PLIST = 0x300;
	public static final int TYPE_FILE = 0x400;
	public static final int TYPE_MUS_FOLDER = 0x500;

	private static final int DB_VERSION = 11;

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

		private long insertDirectory(String name, Long parentId) {
			ContentValues values = new ContentValues();
			values.put("type", TYPE_DIR);
			values.put("parent_id", parentId);
			values.put("filename", name);
			return db.insert("files", null, values);
		}

		private void insertFile(File name, byte[] data, long modifyTime, Long parentId) {
			DroidSoundPlugin.MusicInfo info = DroidSoundPlugin.identify(name.getName(), data);
			ContentValues values = new ContentValues();
			values.put("parent_id", parentId);
			values.put("filename", name.getName());
			values.put("modify_time", modifyTime);
			values.put("type", TYPE_FILE);
			values.put("title", name.getName());
			values.put("composer", name.getParentFile().getName());
			if (info != null) {
				if (info.title != null) {
					values.put("title", info.title);
				}
				if (info.composer != null) {
					values.put("composer", info.composer);
				}
				values.put("date", info.date);
				values.put("format", info.format);
				db.insert("files", null, values);
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
		private void scanZip(File zipFile, Long parentId) throws ZipException, IOException {
			Log.i(TAG, "Scanning ZIP %s for files...", zipFile.getPath());
			db.delete("files", "parent_id = ?", new String [] { String.valueOf(parentId) });

			FileInputStream fis = new FileInputStream(zipFile);
			ZipInputStream zis = new ZipInputStream(fis);
			Map<String, Long> pathMap = new HashMap<String, Long>();
			pathMap.put("", parentId);

			ZipEntry ze;
			int shownPct = -1;
			while (null != (ze = zis.getNextEntry())) {
				int slash = ze.getName().lastIndexOf('/');
				/** Path inside zip to file */
				final String path;
				/** Name of file */
				final String name;
				if (slash == -1) {
					path = zipFile.getPath();
					name = ze.getName();
				} else {
					path = ze.getName().substring(0, slash);
					name = ze.getName().substring(slash  + 1);
				}
				final long pathParentId;
				if ("".equals(name)) {
					/* Is directory. Pick the part before the last filename */
					int slash2 = path.lastIndexOf('/');
					final String pathFilename;
					if (slash2 == -1) {
						/* top level in zip: parent to given directory */
						Log.i(TAG, "Zip: directory %s is in top level", path);
						pathParentId = parentId;
						pathFilename = path;
					} else {
						/** Parent of the path (if any) */
						String parent = path.substring(0, slash2);
						pathFilename = path.substring(slash2 + 1);
						pathParentId = pathMap.get(parent);
					}

					Log.i(TAG, "New directory: %s", ze.getName());
					long rowId = insertDirectory(pathFilename, pathParentId);
					pathMap.put(path, rowId);
				} else {
					if (ze.getName().equals("Songlengths.txt")) {
						scanSonglengthsTxt(zis);
					} else {
						pathParentId = pathMap.get(path);
						/* We could store zipentry's modifytime here, but I doubt it makes a difference. */
						Log.i(TAG, "New file: %s", ze.getName());
						insertFile(new File(path, name), StreamUtil.readFully(zis, ze.getSize()), 0, pathParentId);
					}
				}

				int pct = (int) (fis.getChannel().position() / (fis.getChannel().size() / 100));
				if (shownPct != pct) {
					publishProgress(zipFile.getName(), pct);
					shownPct = pct;
				}
				zis.closeEntry();
			}

			zis.close();
		}

		/**
		 * Dir scan. Roots of the tree are those with parentId = null.
		 */
		private void scanFiles(File dir, Long parentId) throws IOException {
			Log.i(TAG, "Entering '%s'", dir.getPath());

			String where;
			String[] whereCond;
			if (parentId == null) {
				where = "parent_id IS NULL";
				whereCond = null;
			} else {
				where = "parent_id = ?";
				whereCond = new String[] { String.valueOf(parentId) };
			}
			final Cursor fileCursor = db.query(
					"files",
					new String[] { BaseColumns._ID, "filename", "modify_time" },
					where, whereCond,
					null, null, null
			);

			/** Going to recurse into these */
			Map<Long, File> dirsInDatabase = new HashMap<Long, File>();
			publishProgress(dir.getName(), 0);

			/**
			 * Set of files in examined directory. Entries are removed from this set
			 * if they are also found on the database, so the remainder corresponds to files to add.
			 */
			Set<File> files = new HashSet<File>();
			for (File f : dir.listFiles()) {
				if (! f.getName().startsWith(".")) {
					files.add(f);
				}
			}

			Set<Long> delFiles = new HashSet<Long>();
			/* Compare db and fs */
			while (fileCursor.moveToNext()) {
				long id = fileCursor.getLong(0);
				File file = new File(dir, fileCursor.getString(1));
				long lastScan = fileCursor.getLong(2);

				if (files.contains(file)) {
					if (file.isDirectory()) {
						dirsInDatabase.put(id, file);
						files.remove(file);
					} else {
						/* Has recorded modify-time changed? If so, rescan. */
						if (lastScan != file.lastModified()) {
							delFiles.add(id);
						} else {
							files.remove(file);
						}
					}
				} else {
					delFiles.add(id);
				}
			}
			fileCursor.close();

			/* Delete files that need refresh or which did not exist anymore. */
			for (long id : delFiles) {
				db.delete("files", "_id = ?", new String[] { String.valueOf(id) } );
			}

			/* Add files/directories that did not exist */
			for (File f : files) {
				if (f.isFile()) {
					Log.i(TAG, "New file: %s", f.getPath());
					String fnUpper = f.getName().toUpperCase();
					if (fnUpper.endsWith(".ZIP")) {
						ContentValues values = new ContentValues();
						values.put("parent_id", parentId);
						values.put("filename", f.getName());
						values.put("modify_time", f.lastModified());
						values.put("type", TYPE_ZIP);
						values.put("title", f.getName().substring(0, f.getName().length() - 4));
						long rowId = db.insert("files", null, values);
						scanZip(f, rowId);
					} else if (fnUpper.endsWith(".PLIST")) {
						ContentValues values = new ContentValues();
						values.put("parent_id", parentId);
						values.put("filename", f.getName());
						values.put("modify_time", f.lastModified());
						values.put("type", TYPE_PLIST);
						values.put("title", f.getName().substring(0, f.getName().length() - 6));
						db.insert("files", null, values);
					} else if (f.getName().equals("Songlengths.txt")) {
						FileInputStream fi = new FileInputStream(f);
						scanSonglengthsTxt(fi);
						fi.close();
					} else {
						FileInputStream fi = new FileInputStream(f);
						insertFile(f, StreamUtil.readFully(fi, f.length()), f.lastModified(), parentId);
						fi.close();
					}
				} else if (f.isDirectory()) {
					Log.i(TAG, "New Directory: %s", f.getPath());
					long rowId = insertDirectory(f.getName(), parentId);
					scanFiles(f, rowId);
				}
			}

			/* Continue scanning into found directories */
			for (Entry<Long, File> e : dirsInDatabase.entrySet()) {
				scanFiles(e.getValue(), e.getKey());
			}
		}

		private void scanSonglengthsTxt(InputStream is) throws IOException {
			BufferedReader br = new BufferedReader(new InputStreamReader(is, ISO88591));

			Pattern md5AndTimes = Pattern.compile("([a-fA-f0-9])=(.*)");
			Pattern timestamps = Pattern.compile("([0-9]{1,2}):([0-9]{2})");

			String line;
			while (null != (line = br.readLine())) {
				Matcher m = md5AndTimes.matcher(line);
				if (! m.matches()) {
					continue;
				}
				String md5 = m.group(1).toLowerCase();
				String times = m.group(2);

				m = timestamps.matcher(times);
				int song = 0;
				while (m.find()) {
					int minutes = Integer.valueOf(m.group(1));
					int seconds = Integer.valueOf(m.group(2));
					ContentValues cv = new ContentValues();
					cv.put("md5", md5);
					cv.put("subsong", ++ song);
					cv.put("timeMs", (minutes * 60 + seconds) * 1000);
					db.insert("songlength", null, cv);
				}
			}
		}

		private void doScan(File modsDir, boolean full) throws IOException {
			if (full) {
				publishProgress(modsDir.getPath(), 0);
				db.delete("files", null, null);
				db.delete("songlength", null, null);
			}

			scanFiles(modsDir, null);
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

		public Cursor search(String query, Sort sorting) {
			String q = "%" + query + "%" ;
			return db.query("files",
					COLUMNS,
					"title LIKE ? OR composer LIKE ? OR filename LIKE ?", new String[] { q, q, q },
					null, null, sorting.toSQL()
			);
		}

		/**
		 * Return files found in collection.
		 *
		 * @param parentId the parent to scan, null for roots
		 * @param sorting output order of results
		 * @return Cursor to read from
		 */
		public Cursor getFilesByParentId(Long parentId, Sort sorting) {
			String where;
			String[] whereCond;
			if (parentId == null) {
				where = "parent_id IS NULL";
				whereCond = null;
			} else {
				where = "parent_id = ?";
				whereCond = new String[] { String.valueOf(parentId) };
			}
			return db.query(
					"files",
					COLUMNS,
					where, whereCond,
					null, null, sorting.toSQL()
			);
		}

		/**
		 * Return a particular file's data from collection.
		 *
		 * @param id file's id
		 * @return cursor to read from
		 */
		public Cursor getFileById(long id) {
			return db.query(
					"files",
					COLUMNS,
					"_id = ?", new String[] { String.valueOf(id) },
					null, null, null
			);
		}

		/**
		 * Get a full {@link SongFile} instance from a collection entry.
		 *
		 * @param childId
		 * @return songfile
		 */
		public SongFile getSongFile(final long childId) {
			List<String> list = new ArrayList<String>();
			Cursor c = getFileById(childId);
			c.moveToFirst();

			String title = c.getString(COL_TITLE);
			String composer = c.getString(COL_COMPOSER);
			int date = c.getInt(COL_DATE);

			int zipIdx = -1;
			while (true) {
				if (c.getInt(COL_TYPE) == TYPE_ZIP) {
					zipIdx = list.size();
				}
				list.add(c.getString(COL_FILENAME));
				if (c.isNull(COL_PARENT_ID)) {
					break;
				}

				Long parentId = c.getLong(COL_PARENT_ID);
				c.close();
				c = getFileById(parentId);
				c.moveToFirst();
			}
			c.close();

			File zipFilePath = null;
			File path = null;

			if (zipIdx == -1) {
				path = Application.getModsDirectory();
				for (int i = list.size() - 1; i >= 0; i --) {
					path = new File(path, list.get(i));
				}
			} else {
				zipFilePath = Application.getModsDirectory();
				for (int i = list.size() - 1; i >= zipIdx; i --) {
					zipFilePath = new File(zipFilePath, list.get(i));
				}
				for (int i = zipIdx - 1; i >= 0; i --) {
					path = new File(path, list.get(i));
				}
			}

			return new SongFile(
					childId,
					-1,
					path.getPath(),
					zipFilePath != null ? zipFilePath.getPath() : null,
					title,
					composer,
					date
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
			Log.i(TAG, "Deleting old schema (if any)...");
			db.execSQL("DROP TABLE IF EXISTS files;");
			db.execSQL("DROP TABLE IF EXISTS songlength;");

			Log.i(TAG, "Creating new schema...");
			/* Record seen songs. */
			db.execSQL("CREATE TABLE IF NOT EXISTS files ("
					+ BaseColumns._ID + " INTEGER PRIMARY KEY,"
					+ "parent_id INTEGER REFERENCES files ON DELETE CASCADE,"
					+ "filename TEXT NOT NULL,"
					+ "type INTEGER NOT NULL,"
					+ "modify_time INTEGER,"
					+ "title TEXT,"
					+ "composer TEXT,"
					+ "date INTEGER,"
					+ "format TEXT"
					+ ");");

			/* If a Songlengths.txt file is seen, we parse and store it here.
			 * Rules are: if subsong is null, then the play length governs all
			 * subsongs. If a more specific subsong value is found, then that
			 * should be used.
			 *
			 * This is not for SID only, at least not in principle:
			 * any plugin-given md5 value in this table will do. */
			db.execSQL("CREATE TABLE IF NOT EXISTS songlength ("
					+ BaseColumns._ID + " INTEGER PRIMARY KEY,"
					+ "md5 CHAR(32) NOT NULL,"
					+ "subsong INTEGER,"
					+ "timeMs INTEGER"
					+ ");");

			db.execSQL("CREATE INDEX ui_files_parent_filename ON files (parent_id, filename);");
			db.execSQL("CREATE INDEX ui_songlength_md5 ON songlength (md5);");
			db.setVersion(DB_VERSION);
			Log.i(TAG, "Schema complete.");
		}

		return db;
	}
}
