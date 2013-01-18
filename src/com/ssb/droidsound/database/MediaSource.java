package com.ssb.droidsound.database;

import java.io.File;
import java.io.InputStream;

import android.content.ContentResolver;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.provider.MediaStore;

import com.ssb.droidsound.utils.CursorTransform;
import com.ssb.droidsound.utils.DBFileSystem;
import com.ssb.droidsound.utils.Log;

public class MediaSource implements DataSource  {
	private static final String TAG = MediaSource.class.getSimpleName();
	
	private static String[] albumsFields = { MediaStore.Audio.Albums._ID,
			  MediaStore.Audio.Albums.ALBUM,
			  MediaStore.Audio.Albums.ARTIST,
			  MediaStore.Audio.Albums.FIRST_YEAR,
			  MediaStore.Audio.Albums.LAST_YEAR,
			  MediaStore.Audio.Albums.NUMBER_OF_SONGS
			  };
	/*private static String[] artistFields = { MediaStore.Audio.Albums._ID,
		  MediaStore.Audio.Artists.ARTIST
		  }; */
	private static String[] fields = { MediaStore.Audio.Media._ID,
			  MediaStore.Audio.Media.DISPLAY_NAME,
			  MediaStore.Audio.Media.YEAR,
			  MediaStore.Audio.Media.TITLE,
			  MediaStore.Audio.Media.ARTIST,
			  MediaStore.Audio.Media.DATA,
			  MediaStore.Audio.Media.TRACK,
			  MediaStore.Audio.Media.ALBUM,
			  };

	
		public static final String NAME = "mediastore.source";

	private Context context;

	private DBFileSystem dbfs;
	private String displayTitle;
	
	private static final String sortOrder [] = new String[] { 
		String.format("%s, %s",  MediaStore.Audio.Media.TRACK, MediaStore.Audio.Media.TITLE),
		String.format("%s, %s",  MediaStore.Audio.Media.ARTIST, MediaStore.Audio.Media.TITLE),
		String.format("%s, %s",  MediaStore.Audio.Media.YEAR, MediaStore.Audio.Media.TITLE)
	};
	
	private static final String albumSortOrder [] = new String[] { 
		String.format("%s, %s", MediaStore.Audio.Albums.ALBUM, MediaStore.Audio.Albums.LAST_YEAR),
		String.format("%s, %s", MediaStore.Audio.Albums.ARTIST, MediaStore.Audio.Albums.LAST_YEAR),
		String.format("%s, %s", MediaStore.Audio.Albums.LAST_YEAR, MediaStore.Audio.Albums.ALBUM)
	};

	public MediaSource(Context ctx) {
		context = ctx;
		dbfs = new DBFileSystem(NAME);
		
		//dbfs.addPath("", new String[] { "Albums", "Artists", "Genres" });
		
		dbfs.addPath("", new DBFileSystem.CursorFactory() {
			@Override
			public Cursor getCursor(String[] parts, int sorting) {
				ContentResolver cr = context.getContentResolver();
				Cursor cursor = cr.query(MediaStore.Audio.Albums.EXTERNAL_CONTENT_URI, albumsFields, null, null, 
						albumSortOrder[sorting]);
				
				CursorTransform ct = new CursorTransform();
				ct.addTransform("TITLE", String.format("${%s}", MediaStore.Audio.Albums.ALBUM));
				ct.addTransform("SUBTITLE", String.format("${%s}", MediaStore.Audio.Albums.ARTIST));
				ct.addTransform("SIDETITLE", String.format("${%s}", MediaStore.Audio.Albums.LAST_YEAR));
				ct.addTransform("FILENAME", String.format("${%s}", MediaStore.Audio.Albums._ID));
				ct.addTransform("TYPE", SongDatabase.TYPE_DIR);
				return ct.transformCursor(cursor);
			}
		});
		
		dbfs.addPath("*", new DBFileSystem.CursorFactory() {

			@Override
			public Cursor getCursor(String[] parts, int sorting) {
				ContentResolver cr = context.getContentResolver();
				Cursor cursor = cr.query(MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, fields, 
						String.format("%s = ?", MediaStore.Audio.Media.ALBUM_ID), new String[] { parts[0] }, 
						sortOrder[sorting]);
				
				cursor.moveToFirst();
				displayTitle = "";
				if(cursor.getCount() > 0) {
					displayTitle = cursor.getString(cursor.getColumnIndex(MediaStore.Audio.Media.ALBUM));
				}
				cursor.moveToPosition(-1);
				
				CursorTransform ct = new CursorTransform();
				ct.addTransform("TITLE", String.format("${%s}", MediaStore.Audio.Media.TITLE));
				ct.addTransform("SUBTITLE", String.format("${%s}", MediaStore.Audio.Media.ARTIST));
				ct.addTransform("SIDETITLE", String.format("${%s}", MediaStore.Audio.Media.TRACK));
				ct.addTransform("PATH", "");
				ct.addTransform("FILENAME", String.format("${%s}", MediaStore.Audio.Media.DATA));
				ct.addTransform("TYPE", SongDatabase.TYPE_FILE);
				return ct.transformCursor(cursor);
				
			}
		});

	/*
	
		dbfs.addPath("Artists", new DBFileSystem.CursorFactory() {
			@Override
			public Cursor getCursor(String[] parts, int sorting) {
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
			public Cursor getCursor(String[] parts, int sorting) {
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
*/
	}

	@Override
	public void createIndex(int mode, SQLiteDatabase db) {
	}
	
	@Override
	public Cursor getCursorFromPath(File file, SQLiteDatabase db, int sorting) {
		Log.d(TAG, "FILE '%s'", file.getPath());
		displayTitle = null;
		return dbfs.getFileInPath(file.getPath(), sorting);
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
