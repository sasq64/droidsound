package com.ssb.droidsound;

import java.io.File;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;

import android.content.ContentResolver;
import android.content.Context;
import android.database.Cursor;
import android.database.CursorWrapper;
import android.database.sqlite.SQLiteDatabase;
import android.provider.MediaStore;
import android.util.Log;

import com.ssb.droidsound.SongDatabase.ScanCallback;

public class MediaSource implements SongDatabase.DataSource  {
	private static final String TAG = MediaSource.class.getSimpleName();
	
	private static String[] albumsFields = { MediaStore.Audio.Albums._ID,
			  MediaStore.Audio.Albums.ALBUM,
			  MediaStore.Audio.Albums.ARTIST,
			  MediaStore.Audio.Albums.FIRST_YEAR,
			  MediaStore.Audio.Albums.LAST_YEAR,
			  MediaStore.Audio.Albums.NUMBER_OF_SONGS
			  };
	private static String[] artistFields = { MediaStore.Audio.Albums._ID,
		  MediaStore.Audio.Artists.ARTIST
		  };
	private static String[] fields = { MediaStore.Audio.Media._ID,
			  MediaStore.Audio.Media.DISPLAY_NAME,
			  MediaStore.Audio.Media.YEAR,
			  MediaStore.Audio.Media.TITLE,
			  MediaStore.Audio.Media.ARTIST,
			  MediaStore.Audio.Media.DATA,
			  MediaStore.Audio.Media.SIZE,
			  MediaStore.Audio.Media.ALBUM,
			  };

	
		public static final String NAME = "mediastore.source";

	private Context context;

	private DBFileSystem dbfs;
	private String displayTitle;
	
	public MediaSource(Context ctx) {
		context = ctx;
		dbfs = new DBFileSystem(NAME);
		
		dbfs.addPath("", new String[] { "Albums", "Artists", "Genres" });
		
		dbfs.addPath("Albums", new DBFileSystem.CursorFactory() {
			@Override
			public Cursor getCursor(String[] parts) {
				ContentResolver cr = context.getContentResolver();
				Cursor cursor = cr.query(MediaStore.Audio.Albums.EXTERNAL_CONTENT_URI, albumsFields, null, null, null);
				
				CursorTransform ct = new CursorTransform();
				ct.addTransform("TITLE", String.format("${%s}", MediaStore.Audio.Albums.ALBUM));
				ct.addTransform("SUBTITLE", String.format("${%s}", MediaStore.Audio.Albums.ARTIST));
				ct.addTransform("SIDETITLE", String.format("${%s}", MediaStore.Audio.Albums.LAST_YEAR));
				ct.addTransform("FILENAME", String.format("${%s}", MediaStore.Audio.Albums._ID));
				ct.addTransform("TYPE", SongDatabase.TYPE_DIR);
				return ct.transformCursor(cursor);
			}
		});
		
		dbfs.addPath("Albums/*", new DBFileSystem.CursorFactory() {

			@Override
			public Cursor getCursor(String[] parts) {
				ContentResolver cr = context.getContentResolver();
				Cursor cursor = cr.query(MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, fields, 
						String.format("%s = ?", MediaStore.Audio.Media.ALBUM_ID), new String[] { parts[1] }, 
						null);
				
				cursor.moveToFirst();
				displayTitle = cursor.getString(cursor.getColumnIndex(MediaStore.Audio.Media.ALBUM));
				cursor.moveToPosition(-1);
				
				CursorTransform ct = new CursorTransform();
				ct.addTransform("TITLE", String.format("${%s}", MediaStore.Audio.Media.TITLE));
				ct.addTransform("SUBTITLE", String.format("${%s}", MediaStore.Audio.Media.ARTIST));
				ct.addTransform("PATH", "");
				ct.addTransform("FILENAME", String.format("${%s}", MediaStore.Audio.Media.DATA));
				ct.addTransform("TYPE", SongDatabase.TYPE_FILE);
				return ct.transformCursor(cursor);
				
			}
		});

	
	
		dbfs.addPath("Artists", new DBFileSystem.CursorFactory() {
			@Override
			public Cursor getCursor(String[] parts) {
				ContentResolver cr = context.getContentResolver();
				Cursor cursor = cr.query(MediaStore.Audio.Artists.EXTERNAL_CONTENT_URI, artistFields, null, null, null);
				
				CursorTransform ct = new CursorTransform();
				ct.addTransform("TITLE", String.format("${%s}", MediaStore.Audio.Artists.ARTIST));
				ct.addTransform("FILENAME", String.format("${%s}", MediaStore.Audio.Artists._ID));
				ct.addTransform("TYPE", SongDatabase.TYPE_DIR);
				return ct.transformCursor(cursor);
			}
		});
		
		dbfs.addPath("Artists/*", new DBFileSystem.CursorFactory() {
			@Override
			public Cursor getCursor(String[] parts) {
				ContentResolver cr = context.getContentResolver();
				Cursor cursor = cr.query(MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, fields, 
						String.format("%s = ?", MediaStore.Audio.Media.ARTIST_ID), new String[] { parts[1] }, 
						null);
				
				cursor.moveToFirst();
				displayTitle = cursor.getString(cursor.getColumnIndex(MediaStore.Audio.Media.ARTIST));
				cursor.moveToPosition(-1);

				CursorTransform ct = new CursorTransform();
				ct.addTransform("TITLE", String.format("${%s}", MediaStore.Audio.Media.TITLE));
				ct.addTransform("SUBTITLE", String.format("${%s}", MediaStore.Audio.Media.ARTIST));
				ct.addTransform("PATH", "");
				ct.addTransform("FILENAME", String.format("${%s}", MediaStore.Audio.Media.DATA));
				ct.addTransform("TYPE", SongDatabase.TYPE_FILE);
				return ct.transformCursor(cursor);
				
			}
		});

	}

	@Override
	public void createIndex(int mode, SQLiteDatabase db) {
	}
	
	@Override
	public Cursor getCursorFromPath(File file, SQLiteDatabase db) {
		Log.v(TAG, String.format("FILE '%s'", file.getPath()));
		displayTitle = null;
		return dbfs.getFileInPath(file.getPath());
	}

	@Override
	public String getPathTitle(File file) {
		if(displayTitle != null) return displayTitle;
		String n = file.getName();
		if(n.equals(NAME)) return "Local Mediastore";
		return file.getName();
	}

	@Override
	public String getTitle() {
		return "Local Mediastore";
	}

	@Override
	public boolean parseDump(InputStream is, int size, SQLiteDatabase scanDb, ScanCallback scanCallback) {
		return true;
	}

	@Override
	public Cursor search(String query, String fromPath, SQLiteDatabase db) {
		return null;
	}

}
