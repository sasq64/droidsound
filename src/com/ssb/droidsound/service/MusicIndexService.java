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
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.zip.ZipEntry;
import java.util.zip.ZipException;
import java.util.zip.ZipFile;
import java.util.zip.ZipInputStream;

import android.app.Service;
import android.content.ContentValues;
import android.content.Intent;
import android.database.Cursor;
import android.database.DatabaseUtils;
import android.database.sqlite.SQLiteDatabase;
import android.os.AsyncTask;
import android.os.Binder;
import android.os.IBinder;
import android.provider.BaseColumns;

import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.bo.FilesEntry;
import com.ssb.droidsound.bo.Playlist;
import com.ssb.droidsound.bo.SongFileData;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.StreamUtil;
import com.ssb.droidsound.utils.ZipReader;

public class MusicIndexService extends Service {
	public enum Sort {
		TITLE, COMPOSER, FILENAME;

		protected String toSQL() {
			return "type, lower(" + String.valueOf(this).toLowerCase() + "), lower(filename)";
		}
	}

	protected static final String TAG = MusicIndexService.class.getSimpleName();
	protected  static final String[] COLUMNS = new String[] { "_id", "parent_id", "filename", "type", "format", "title", "composer", "date" };

	protected static final Charset ISO88591 = Charset.forName("ISO-8859-1");

	public static final int COL_ID = 0;
	public static final int COL_PARENT_ID = 1;
	public static final int COL_FILENAME = 2;
	public static final int COL_TYPE = 3;
	public static final int COL_FORMAT = 4;
	public static final int COL_TITLE = 5;
	public static final int COL_COMPOSER = 6;
	public static final int COL_DATE = 7;

	public static final String ACTION_SCAN = "com.ssb.droidsound.SCAN";

	public static final int TYPE_ZIP = 1;
	public static final int TYPE_DIRECTORY = 2;
	public static final int TYPE_PLAYLIST = 3;
	public static final int TYPE_FILE = 4;
	public static final int TYPE_MUS_FOLDER = 5;
	public static final int TYPE_SONGLENGTH = 6;

	private static final int DB_VERSION = 19;

	protected SQLiteDatabase db;

	protected AtomicBoolean scanning = new AtomicBoolean();

	protected class Scanner extends AsyncTask<Void, Intent, Void> {
		private final boolean full;
		private final DatabaseUtils.InsertHelper filesHelper;
		private final DatabaseUtils.InsertHelper songlengthHelper;

		protected Scanner(boolean full) {
			this.full = full;
			filesHelper = new DatabaseUtils.InsertHelper(db, "files");
			songlengthHelper = new DatabaseUtils.InsertHelper(db, "songlength");
		}

		@Override
		protected void onPreExecute() {
			if (scanning.get()) {
				cancel(true);
				return;
			}
			if (scanning.compareAndSet(false, true)) {
				startService(new Intent(MusicIndexService.this, MusicIndexService.class));
			}
		}

		@Override
		protected void onProgressUpdate(Intent... intents) {
			for (Intent i : intents) {
				sendBroadcast(i);
			}
		}

		private void sendUpdate(int pct) {
			Intent intent = new Intent(ACTION_SCAN);
			intent.putExtra("progress", pct);
			intent.putExtra("scanning", true);
			publishProgress(intent);
		}

		@Override
		protected Void doInBackground(Void... ignored) {
			try {
				doScan(Application.getModsDirectory());
			} catch (IOException e) {
				Log.w(TAG, "Unable to finish scan", e);
			}
			return null;
		}

		@Override
		protected void onPostExecute(Void result) {
			stopService(new Intent(MusicIndexService.this, MusicIndexService.class));
			Intent endIntent = new Intent(ACTION_SCAN);
			endIntent.putExtra("progress", 100);
			endIntent.putExtra("scanning", false);
			sendBroadcast(endIntent);
			scanning.set(false);
		}

		/**
		 * Insert a directory node to a parent.
		 *
		 * @param name
		 * @param parentId
		 * @return rowid
		 */
		private long insertDirectory(String name, Long parentId) {
			ContentValues values = new ContentValues();
			values.put("type", TYPE_DIRECTORY);
			values.put("parent_id", parentId);
			values.put("filename", name);
			values.put("title", name);
			return filesHelper.insert(values);
		}

		/**
		 * Insert a file node to a parent.
		 *
		 * @param name
		 * @param data
		 * @param modifyTime
		 * @param parentId
		 */
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
				filesHelper.insert(values);
			}
		}

		/**
		 * Insert a playlist node.
		 * <p>
		 * The playlist node is a bit tricky because it encodes the full path to the file
		 * sans the base directory of the collection. They are also serialized in different
		 * kind of files and only cached in db.
		 *
		 * @param rowId
		 * @param f
		 */
		private void insertPlaylist(long rowId, File f) {
			ContentValues values = new ContentValues();
			Playlist pl = new Playlist(rowId, f);

			for (FilesEntry sf : pl.getSongs()) {
				values.put("parent_id", rowId);
				/* okay, we'll encode zip path and file path into this field. Sorry. */
				String path = sf.getFilePath().getPath();
				File zipFilePath = sf.getZipFilePath();
				if (zipFilePath != null) {
					path += "\u0000" + zipFilePath.getPath();
				}
				values.put("filename", path);
				values.put("title", sf.getTitle());
				values.put("type", TYPE_FILE);
				values.put("title", sf.getTitle());
				values.put("composer", sf.getComposer());
				values.put("date", sf.getDate());
				values.put("format", sf.getFormat());
				filesHelper.insert(values);
			}
		}


		/**
		 * Zip scanner
		 *
		 * @param zipFile
		 * @return
		 * @throws ZipException
		 * @throws IOException
		 */
		private void scanZip(File zipFile, Long parentId) throws ZipException, IOException {
			Log.i(TAG, "Scanning ZIP %s for files...", zipFile.getPath());
			db.execSQL("PRAGMA foreign_keys=ON");
			db.delete("files", "parent_id = ?", new String [] { String.valueOf(parentId) });
			db.execSQL("PRAGMA foreign_keys=OFF");

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
					pathParentId = pathMap.get(path);
					if (name.equals("Songlengths.txt")) {
						ContentValues cv = new ContentValues();
						cv.put("filename", name);
						cv.put("parent_id", pathParentId);
						cv.put("type", TYPE_SONGLENGTH);
						long rowId = filesHelper.insert(cv);
						scanSonglengthsTxt(rowId, zis);
					} else {
						/* We could store zipentry's modifytime here, but I doubt it makes a difference. */
						//Log.i(TAG, "New file: %s", ze.getName());
						insertFile(new File(path, name), StreamUtil.readFully(zis, ze.getSize()), 0, pathParentId);
					}
				}

				int pct = (int) (fis.getChannel().position() / (fis.getChannel().size() / 100));
				if (shownPct != pct) {
					sendUpdate(pct);
				}
				zis.closeEntry();
			}

			zis.close();
		}

		/**
		 * Dir scan. Roots of the tree are those with parentId = null.
		 */
		private void scanFiles(File dir, Long parentId) throws IOException {
			sendUpdate(0);
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
			Map<Long, File> directoriesToRecurse = new HashMap<Long, File>();

			/**
			 * Set of files in examined directory. Entries are removed from this set
			 * if they are also found on the database, so the remainder corresponds to files to add.
			 */
			List<File> files = new ArrayList<File>();
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
						directoriesToRecurse.put(id, file);
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
			db.beginTransaction();
			db.execSQL("PRAGMA foreign_keys=ON");
			for (long id : delFiles) {
				db.delete("files", "_id = ?", new String[] { String.valueOf(id) } );
			}
			db.execSQL("PRAGMA foreign_keys=OFF");

			Map<File, ContentValues> zipsToScan = new HashMap<File, ContentValues>();
			List<File> songLengthsToDo = new ArrayList<File>();
			List<File> directoriesToAdd = new ArrayList<File>();

			/* Add files/directories that did not exist */
			int pct = 0;
			for (int i = 0; i < files.size(); i ++) {
				File f = files.get(i);
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
						zipsToScan.put(f, values);
					} else if (fnUpper.endsWith(".PLIST")) {
						ContentValues values = new ContentValues();
						values.put("parent_id", parentId);
						values.put("filename", f.getName());
						values.put("modify_time", f.lastModified());
						values.put("type", TYPE_PLAYLIST);
						values.put("title", f.getName().substring(0, f.getName().length() - 6));

						long rowId = filesHelper.insert(values);
						insertPlaylist(rowId, f);
					} else if (f.getName().equals("Songlengths.txt")) {
						songLengthsToDo.add(f);
					} else {
						FileInputStream fi = new FileInputStream(f);
						insertFile(f, StreamUtil.readFully(fi, f.length()), f.lastModified(), parentId);
						fi.close();
					}
				} else if (f.isDirectory()) {
					Log.i(TAG, "New directory: %s", f.getPath());
					directoriesToAdd.add(f);
				}

				int nextPct = i * 100 / files.size();
				if (pct != nextPct) {
					pct = nextPct;
					sendUpdate(pct);
				}
			}
			db.setTransactionSuccessful();
			db.endTransaction();
			sendUpdate(100);

			for (File f : directoriesToAdd) {
				/* This is unfortunate, we need to create the directory before we can recurse into it.
				 * Thankfully the transactionality here is not critical as we are talking about
				 * real files here, a future scan will look them up just fine. */
				long rowId = insertDirectory(f.getName(), parentId);
				scanFiles(f, rowId);
			}

			for (File f : songLengthsToDo) {
				db.beginTransaction();
				ContentValues cv = new ContentValues();
				cv.put("filename", f.getName());
				cv.put("parent_id", parentId);
				cv.put("type", TYPE_SONGLENGTH);
				long rowId = filesHelper.insert(cv);
				FileInputStream fi = new FileInputStream(f);
				scanSonglengthsTxt(rowId, fi);
				fi.close();
				db.setTransactionSuccessful();
				db.endTransaction();
			}

			for (Entry<File, ContentValues> entries : zipsToScan.entrySet()) {
				db.beginTransaction();
				long rowId = filesHelper.insert(entries.getValue());
				scanZip(entries.getKey(), rowId);
				db.setTransactionSuccessful();
				db.endTransaction();
				sendUpdate(100);
			}

			/* Continue scanning into found directories */
			for (Entry<Long, File> e : directoriesToRecurse.entrySet()) {
				scanFiles(e.getValue(), e.getKey());
			}
		}

		private void scanSonglengthsTxt(long fileId, InputStream is) throws IOException {
			BufferedReader br = new BufferedReader(new InputStreamReader(is, ISO88591));
			ContentValues cv = new ContentValues();
			cv.put("file_id", fileId);

			Pattern md5AndTimes = Pattern.compile("([a-fA-f0-9]{32})=(.*)");
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
					cv.put("md5", md5);
					cv.put("subsong", ++ song);
					cv.put("timeMs", (minutes * 60 + seconds) * 1000);
					songlengthHelper.insert(cv);
				}
			}
		}

		private void doScan(File modsDir) throws IOException {
			if (full) {
				sendUpdate(0);
				db.delete("files", null, null);
				sendUpdate(50);
				db.delete("songlength", null, null);
			}
			scanFiles(modsDir, null);
		}
	}

	public class LocalBinder extends Binder {
		public void scan(boolean full) {
			new Scanner(full).execute();
		}

		public Cursor search(String query, Sort sorting) {
			String q = "%" + query.toLowerCase() + "%" ;
			return db.query("files",
					COLUMNS,
					"(lower(title) LIKE ? OR lower(composer) LIKE ? OR lower(filename) LIKE ?) AND type = ?", new String[] { q, q, q, String.valueOf(TYPE_FILE) },
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

		public List<SongFileData> getSongFileData(FilesEntry song) throws IOException {
			final File name1 = song.getFilePath();
			final byte[] data1;

			final File name2 = song.getSecondaryFileName();
			byte[] data2 = null;

			if (song.getZipFilePath() != null) {
				ZipFile zr = ZipReader.openZip(song.getZipFilePath());
				ZipEntry ze = zr.getEntry(name1.getPath());
				InputStream is1 = zr.getInputStream(ze);
				data1 = StreamUtil.readFully(is1, ze.getSize());
				is1.close();

				/* If the name looks like there might be a secondary file, we extract that from zip also */
				if (name2 != null) {
					ZipEntry ze2 = zr.getEntry(name2.getPath());
					if (ze2 != null) {
						InputStream is2 = zr.getInputStream(ze2);
						data2 = StreamUtil.readFully(is1, ze2.getSize());
						is2.close();
					}
				}

				zr.close();
			} else {
				InputStream is1 = new FileInputStream(name1);
				data1 = StreamUtil.readFully(is1, name1.length());
				is1.close();
				if (name2 != null) {
					InputStream is2 = new FileInputStream(name2);
					data2 = StreamUtil.readFully(is2, name2.length());
					is2.close();
				}
			}

			List<SongFileData> list = new ArrayList<SongFileData>();
			list.add(new SongFileData(name1, data1));
			if (name2 != null) {
				list.add(new SongFileData(name2, data2));
			}
			return list;
		}

		/**
		 *
		 *
		 * @param md5 the plugin-generated md5sum for the tune
		 * @param subsong subsong value 1 .. N and 0 is never valid)
		 * @return
		 */
		public int getSongLength(byte[] md5, int subsong) {
			String hex = "";
			for (byte b : md5) {
				hex += String.format("%02x", b & 0xff);
			}

			int nonSubsongSpecificTime = -1;
			int subsongSpecificTime = -1;
			Cursor c = db.query("songlength",
					new String[] { "subsong", "timeMs" },
					"md5 = ?", new String[] { hex },
					null, null, null
			);
			while (c.moveToNext()) {
				int rowTime = c.getInt(1);
				if (c.isNull(0)) {
					nonSubsongSpecificTime = rowTime;
					continue;
				}

				int rowSubsong = c.getInt(0);
				if (rowSubsong == subsong) {
					subsongSpecificTime = rowTime;
				}
			}
			c.close();

			Log.i(TAG, "Looking up songlength for (%s, %d) => %d ms (fallback: %d ms)", hex, subsong, subsongSpecificTime, nonSubsongSpecificTime);
			return subsongSpecificTime != -1 ? subsongSpecificTime : nonSubsongSpecificTime;
		}

		/**
		 * Get a full {@link FilesEntry} instance from a collection entry.
		 *
		 * @param childId
		 * @return songfile
		 */
		public FilesEntry getSongFile(final long childId) {
			List<String> list = new ArrayList<String>();
			Cursor c = getFileById(childId);
			c.moveToFirst();

			String format = c.getString(COL_FORMAT);
			String title = c.getString(COL_TITLE);
			String composer = c.getString(COL_COMPOSER);
			int date = c.getInt(COL_DATE);

			int zipIdx = -1;
			int playlistIdx = -1;
			while (true) {
				if (c.getInt(COL_TYPE) == TYPE_PLAYLIST) {
					playlistIdx = list.size();
				}
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

			/* Ugly hack alert: selected file within playlist? */
			if (playlistIdx != -1 && list.size() > 1) {
				/* unpack filename (ugly alert) */
				String[] paths = list.get(0).split("\u0000");
				path = new File(paths[0]);
				if (paths.length == 2) {
					zipFilePath = new File(paths[1]);
				}
			} else if (zipIdx != -1) {
				zipFilePath = Application.getModsDirectory();
				for (int i = list.size() - 1; i >= zipIdx; i --) {
					zipFilePath = new File(zipFilePath, list.get(i));
				}
				for (int i = zipIdx - 1; i >= 0; i --) {
					path = new File(path, list.get(i));
				}
			} else {
				path = Application.getModsDirectory();
				for (int i = list.size() - 1; i >= 0; i --) {
					path = new File(path, list.get(i));
				}
			}

			return new FilesEntry(
					childId,
					-1,
					path,
					zipFilePath != null ? zipFilePath : null,
					format,
					title,
					composer,
					date
			);
		}

		public List<Playlist> getPlaylistsList() {
			Cursor c = db.query(
					"files",
					new String[] { "_id", "filename" },
					"parent_id IS NULL AND type = ?", new String[] { String.valueOf(TYPE_PLAYLIST) },
					null, null, null
			);

			List<Playlist> pl = new ArrayList<Playlist>();
			while (c.moveToNext()) {
				long id = c.getLong(0);
				String name = c.getString(1);
				File f = new File(Application.getModsDirectory(), name);
				pl.add(new Playlist(id, f));
			}

			return pl;
		}
	}

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
		File f = getDatabasePath("index.db");
		f.getParentFile().mkdirs();

		SQLiteDatabase toCheckDb = SQLiteDatabase.openOrCreateDatabase(f, null);
		toCheckDb.enableWriteAheadLogging();

		if (toCheckDb.needUpgrade(DB_VERSION)) {
			Log.i(TAG, "Deleting old schema (if any)...");
			toCheckDb.execSQL("DROP TABLE IF EXISTS songlength;");
			toCheckDb.execSQL("DROP TABLE IF EXISTS files;");

			Log.i(TAG, "Creating new schema...");
			/* Record seen songs. */
			toCheckDb.execSQL("CREATE TABLE IF NOT EXISTS files ("
					+ BaseColumns._ID + " INTEGER PRIMARY KEY,"
					+ "parent_id INTEGER REFERENCES files ON DELETE CASCADE,"
					+ "filename TEXT NOT NULL,"
					+ "type INTEGER NOT NULL,"
					+ "format TEXT,"
					+ "modify_time INTEGER,"
					+ "title TEXT,"
					+ "composer TEXT,"
					+ "date INTEGER"
					+ ");");
			toCheckDb.execSQL("CREATE UNIQUE INDEX ui_files_parent_filename ON files (parent_id, filename);");

			/* If a Songlengths.txt file is seen, we parse and store it here.
			 * Rules are: if subsong is null, then the play length governs all
			 * subsongs. If a more specific subsong value is found, then that
			 * should be used.
			 *
			 * This is not for SID only, at least not in principle:
			 * any plugin-given md5 value in this table will do. */
			toCheckDb.execSQL("CREATE TABLE IF NOT EXISTS songlength ("
					+ BaseColumns._ID + " INTEGER PRIMARY KEY,"
					+ "file_id NOT NULL REFERENCES files ON DELETE CASCADE,"
					+ "md5 TEXT NOT NULL,"
					+ "subsong INTEGER,"
					+ "timeMs INTEGER NOT NULL"
					+ ");");
			toCheckDb.execSQL("CREATE UNIQUE INDEX ui_songlength_md5_subsong ON songlength (md5, subsong);");
			toCheckDb.execSQL("CREATE INDEX ui_songlength_file ON songlength (file_id);");

			toCheckDb.setVersion(DB_VERSION);
			Log.i(TAG, "Schema complete.");
		}

		return toCheckDb;
	}
}