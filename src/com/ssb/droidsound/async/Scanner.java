package com.ssb.droidsound.async;

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
import java.util.zip.ZipInputStream;

import android.content.ContentValues;
import android.content.Intent;
import android.database.Cursor;
import android.database.DatabaseUtils;
import android.database.sqlite.SQLiteDatabase;
import android.os.AsyncTask;
import android.provider.BaseColumns;

import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.bo.FilesEntry;
import com.ssb.droidsound.bo.Playlist;
import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.StreamUtil;

/**
 * Perform a collection scan against a writable database instance.
 * This class used to be a Service until I decided that android's
 * conception of Services is so useless (due to lack of synchronous
 * bindService) that I am no longer willing to accept the level of
 * bullshit it takes to use them.
 *
 * @author alankila
 */
public class Scanner extends AsyncTask<Void, Intent, Void> {
	public static final String ACTION_SCAN = "com.ssb.droidsound.SCAN";

	private static AtomicBoolean scanning = new AtomicBoolean();
	private static final String TAG = Scanner.class.getSimpleName();
	private static final Charset ISO88591 = Charset.forName("ISO-8859-1");

	private final SQLiteDatabase db;
	private final boolean full;
	private final DatabaseUtils.InsertHelper filesHelper;
	private final DatabaseUtils.InsertHelper songlengthHelper;

	public Scanner(SQLiteDatabase db, boolean full) {
		this.db = db;
		this.full = full;
		filesHelper = new DatabaseUtils.InsertHelper(db, "files");
		songlengthHelper = new DatabaseUtils.InsertHelper(db, "songlength");
	}

	@Override
	protected void onPreExecute() {
		if (scanning.compareAndSet(false, true)) {
			Application.payProtectionMoney(1);
		} else {
			cancel(false);
		}
	}

	@Override
	protected void onProgressUpdate(Intent... intents) {
		for (Intent i : intents) {
			Application.broadcast(i);
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
		Intent endIntent = new Intent(ACTION_SCAN);
		endIntent.putExtra("progress", 100);
		endIntent.putExtra("scanning", false);
		Application.broadcast(endIntent);
		Application.payProtectionMoney(-1);
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
		values.put("type", SongDatabase.TYPE_DIRECTORY);
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
		values.put("type", SongDatabase.TYPE_FILE);
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
			values.put("type", SongDatabase.TYPE_FILE);
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
					cv.put("type", SongDatabase.TYPE_SONGLENGTH);
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
					values.put("type", SongDatabase.TYPE_ZIP);
					values.put("title", f.getName().substring(0, f.getName().length() - 4));
					zipsToScan.put(f, values);
				} else if (fnUpper.endsWith(".PLIST")) {
					ContentValues values = new ContentValues();
					values.put("parent_id", parentId);
					values.put("filename", f.getName());
					values.put("modify_time", f.lastModified());
					values.put("type", SongDatabase.TYPE_PLAYLIST);
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
			cv.put("type", SongDatabase.TYPE_SONGLENGTH);
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
