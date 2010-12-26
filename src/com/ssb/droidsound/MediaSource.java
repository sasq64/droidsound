package com.ssb.droidsound;

import java.io.File;
import java.io.InputStream;
import java.util.Map;

import android.content.ContentResolver;
import android.content.Context;
import android.database.Cursor;
import android.database.CursorWrapper;
import android.database.sqlite.SQLiteDatabase;
import android.provider.MediaStore;
import android.util.Log;

import com.ssb.droidsound.SongDatabase.ScanCallback;
/*
CursorConverter:
Convert column-names
Convert column-values

Path2Cursor
Virtual Part

VFSys
  addDir(name)
  addCursorDir()
  
  v = new vfsys
  a = v.add("ALBUMS")
  


 */

public class MediaSource implements SongDatabase.DataSource  {
	private static final String TAG = MediaSource.class.getSimpleName();
	
	private static class MSWrapper extends CursorWrapper {

		public static interface ColumnHook {
		};
		
		public static interface ColumnStringHook extends ColumnHook {
			String getString(Cursor cr);
		};

		public static interface ColumnIntHook extends ColumnHook{
			int getInt(Cursor cr);
		}

		private Cursor cursor;;

		public MSWrapper(Cursor cursor) {
			super(cursor);
			this.cursor = cursor;
		}
		
		private Map<String, Integer> colMap;
		private Map<Integer, ColumnHook> hookMap;
		private Map<Integer, String> toMap;
		private Integer colCounter;
		
		public int getColumnIndex(String columnName) {
			
			if(colMap.containsKey(columnName)) {
				return colMap.get(columnName);
			}
			
			return super.getColumnIndex(columnName);
			/*
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
			return -1;*/
		}
		
		public void mapColumn(String col, String toCol) {
			colMap.put(col, colCounter);
			//toMap.put(toCol, colCounter);
			colCounter++;
		}
		
		public void mapColumn(String col, ColumnHook hook) {
			colMap.put(col, colCounter);
			hookMap.put(colCounter, hook);
			colCounter++;
		}

		@Override
		public String getString(int columnIndex) {
			
			if(columnIndex > 99) {
				//indexMap.get(columnIndex);
				ColumnStringHook hook = (ColumnStringHook) hookMap.get(columnIndex);
				return hook.getString(cursor);
			}
			/*
			File f;
			switch(columnIndex) {
			case 97:
				f = new File(super.getString(5));
				return f.getParent();
			case 99:
				f = new File(super.getString(5));
				return f.getName();
			} */
			return super.getString(columnIndex);
		}
		
		@Override
		public int getInt(int columnIndex) {
			if(columnIndex > 99) {
				//indexMap.get(columnIndex);
				ColumnIntHook hook = (ColumnIntHook) hookMap.get(columnIndex);
				return hook.getInt(cursor);
			} /*
			switch(columnIndex) {
			case 98:
				return SongDatabase.TYPE_FILE;
			}*/
			return super.getInt(columnIndex);
		}
		
	}
	
	
	public static final String NAME = "mediastore.source";

	private Context context;

	private DBFileSystem dbfs;
	
	public MediaSource(Context ctx) {
		context = ctx;
		dbfs = new DBFileSystem(NAME);
		DBFileSystem.Directory a = dbfs.addDirectory(null, "ALBUMS");
		
		
	}

	@Override
	public void createIndex(int mode, SQLiteDatabase db) {
	}

	@Override
	public Cursor getCursorFromPath(File file, SQLiteDatabase db) {
		// '/mnt/sdcard/MODS/mediastore.source'
		Log.v(TAG, String.format("FILE '%s'", file.getPath()));
		
		ContentResolver cr = context.getContentResolver();
		
		  String[] fields = { MediaStore.Audio.Media._ID,
				  MediaStore.Audio.Media.DISPLAY_NAME,
				  MediaStore.Audio.Media.YEAR,
				  MediaStore.Audio.Media.TITLE,
				  MediaStore.Audio.Media.ARTIST,
				  MediaStore.Audio.Media.DATA,
				  MediaStore.Audio.Media.SIZE,
				  MediaStore.Audio.Media.ALBUM,
				  };
		
		Cursor cursor = cr.query(MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, fields, "album = 'Santogold'", null, null);
		
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
