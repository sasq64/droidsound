package com.ssb.droidsound;

import java.io.File;
import java.io.InputStream;

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
	
	private static class MSWrapper extends CursorWrapper {

		public MSWrapper(Cursor cursor) {
			super(cursor);
		}
		
		public int getColumnIndex(String columnName) {
			if(columnName == "PATH") {
				return 97;
			} else if(columnName == "FILENAME") {
				return 99;
			} else if(columnName == "TITLE") {
				return 3;
			} else if(columnName == "TYPE") {
				return 98;
			} else if(columnName == "COMPOSER") {
				return 4;
			}
			return -1;
		}
		
		@Override
		public String getString(int columnIndex) {
			File f;
			switch(columnIndex) {
			case 97:
				f = new File(super.getString(5));
				return f.getParent();
			case 99:
				f = new File(super.getString(5));
				return f.getName();
			}
			return super.getString(columnIndex);
		}
		
		@Override
		public int getInt(int columnIndex) {
			switch(columnIndex) {
			case 98:
				return SongDatabase.TYPE_FILE;
			}
			return super.getInt(columnIndex);
		}
		
	}
	
	
	public static final String NAME = "mediastore.source";

	private Context context;
	
	public MediaSource(Context ctx) {
		context = ctx;
	}

	@Override
	public void createIndex(int mode, SQLiteDatabase db) {
	}

	@Override
	public Cursor getCursorFromPath(File file, SQLiteDatabase db) {
		Log.v(TAG, String.format("FILE '%s'", file.getPath()));
		
		ContentResolver cr = context.getContentResolver();
		
		  String[] fields = { MediaStore.Audio.Media._ID,
				  MediaStore.Audio.Media.DISPLAY_NAME,
				  MediaStore.Audio.Media.YEAR,
				  MediaStore.Audio.Media.TITLE,
				  MediaStore.Audio.Media.ARTIST,
				  MediaStore.Audio.Media.DATA,
				  MediaStore.Audio.Media.SIZE };
		
		Cursor cursor = cr.query(MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, fields, null, null, null);
		
		cursor.moveToFirst();
		String fileName = cursor.getString(2);
		Log.v(TAG, String.format("'%s', '%s'", cursor.getString(1), cursor.getString(5)));
		cursor.moveToPosition(-1);
		
		return new MSWrapper(cursor);
	}

	@Override
	public String getPathTitle(File file) {
		return "";
	}

	@Override
	public String getTitle() {
		return "Local Media";
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
