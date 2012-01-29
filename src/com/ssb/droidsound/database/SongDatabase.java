package com.ssb.droidsound.database;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.AsyncTask;
import android.provider.BaseColumns;

import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.async.Scanner;
import com.ssb.droidsound.bo.FilesEntry;
import com.ssb.droidsound.bo.Playlist;
import com.ssb.droidsound.bo.SongFileData;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.StreamUtil;
import com.ssb.droidsound.utils.ZipReader;

public class SongDatabase {
	public enum Sort {
		TITLE, COMPOSER, FILENAME;

		protected String toSQL() {
			return "type, lower(" + String.valueOf(this).toLowerCase() + "), lower(filename)";
		}
	}

	public static final int COL_ID = 0;
	public static final int COL_PARENT_ID = 1;
	public static final int COL_FILENAME = 2;
	public static final int COL_TYPE = 3;
	public static final int COL_FORMAT = 4;
	public static final int COL_TITLE = 5;
	public static final int COL_COMPOSER = 6;
	public static final int COL_DATE = 7;
	public static final int TYPE_ZIP = 1;
	public static final int TYPE_DIRECTORY = 2;
	public static final int TYPE_PLAYLIST = 3;
	public static final int TYPE_FILE = 4;
	public static final int TYPE_MUS_FOLDER = 5;
	public static final int TYPE_SONGLENGTH = 6;

	private static final int DB_VERSION = 1;
	private static final String TAG = SongDatabase.class.getSimpleName();
	private static final String[] COLUMNS = new String[] { "_id", "parent_id", "filename", "type", "format", "title", "composer", "date" };

	private final SQLiteDatabase db;

	public SongDatabase(Context ctx) {
		File f = ctx.getDatabasePath("index.db");
		f.getParentFile().mkdirs();

		db = SQLiteDatabase.openOrCreateDatabase(f, null);
		db.enableWriteAheadLogging();

		if (db.needUpgrade(DB_VERSION)) {
			Log.i(TAG, "Deleting old schema (if any)...");
			db.execSQL("DROP TABLE IF EXISTS songlength;");
			db.execSQL("DROP TABLE IF EXISTS files;");

			Log.i(TAG, "Creating new schema...");
			/* Record seen songs. */
			db.execSQL("CREATE TABLE IF NOT EXISTS files ("
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
			db.execSQL("CREATE UNIQUE INDEX ui_files_parent_filename ON files (parent_id, filename);");

			/* If a Songlengths.txt file is seen, we parse and store it here.
			 * Rules are: if subsong is null, then the play length governs all
			 * subsongs. If a more specific subsong value is found, then that
			 * should be used.
			 *
			 * This is not for SID only, at least not in principle:
			 * any plugin-given md5 value in this table will do. */
			db.execSQL("CREATE TABLE IF NOT EXISTS songlength ("
					+ BaseColumns._ID + " INTEGER PRIMARY KEY,"
					+ "file_id NOT NULL REFERENCES files ON DELETE CASCADE,"
					+ "md5 TEXT NOT NULL,"
					+ "subsong INTEGER,"
					+ "timeMs INTEGER NOT NULL"
					+ ");");
			db.execSQL("CREATE UNIQUE INDEX ui_songlength_md5_subsong ON songlength (md5, subsong);");
			db.execSQL("CREATE INDEX ui_songlength_file ON songlength (file_id);");

			db.setVersion(DB_VERSION);
			Log.i(TAG, "Schema complete.");
		}
	}

	public Cursor search(String query, Sort sorting) {
		String q = "%" + query.toLowerCase() + "%" ;
		return db.query("files",
				COLUMNS,
				"(lower(title) LIKE ? OR lower(composer) LIKE ? OR lower(filename) LIKE ?) AND type = ?", new String[] { q, q, q, String.valueOf(TYPE_FILE) },
				null, null, sorting.toSQL(),
				"100"
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

	public void scan(boolean full) {
		new Scanner(db, full).executeOnExecutor(AsyncTask.THREAD_POOL_EXECUTOR);
	}
}
