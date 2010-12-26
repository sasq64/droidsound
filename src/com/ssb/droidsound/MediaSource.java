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
	
	private static class MSWrapper {

		private Map<String, Integer> colMap;
		private Integer colCounter;

		public MSWrapper() {
			colCounter = 100;
			colMap = new HashMap<String, Integer>();
			registerColumn("PATH", 97);
			registerColumn("TYPE", 98);
			registerColumn("FILENAME", 99);
			registerColumn("TITLE", 3);
			registerColumn("COMPOSER", 4);
		}
				
		public int registerColumn(String col, int colno) {
			colMap.put(col, colno);
			return colno;
		}
		
		public Cursor createWrapper(Cursor cr) {
			return new Wrapper(cr, colMap);
		}

		public static class Wrapper extends CursorWrapper {

			private Map<String, Integer> colMap;
					
			public Wrapper(Cursor cursor, Map<String, Integer> cm) {
				super(cursor);
				colMap = cm;
			}

			public int getColumnIndex(String columnName) {
				
				if(colMap.containsKey(columnName)) {
					return colMap.get(columnName);
				}			
				return super.getColumnIndex(columnName);
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
		
	}
	
	private class ColumnMapping {
		
		private Map<String, Integer> colMap;
		private Map<String, String> fmtMap;
		
		public String formatString(Cursor cr, String s) {
			
			
			
			
			return null;
		}
		
	}
	
	
	public static final String NAME = "mediastore.source";

	private Context context;

	private DBFileSystem dbfs;

	private MSWrapper wrapper;
	
	public MediaSource(Context ctx) {
		context = ctx;
		//dbfs = new DBFileSystem(NAME);
		//DBFileSystem.Directory a = dbfs.addDirectory(null, "ALBUMS");
		wrapper = new MSWrapper();
		
		
	}

	@Override
	public void createIndex(int mode, SQLiteDatabase db) {
	}

	String [] getParts(String path) {		
		String [] parts = path.split("/");
		int n = parts.length;
		boolean found = false;
		//pathTitle = null;

		for(int i=0; i<n; i++) {
			Log.v(TAG, String.format("PART %d: '%s'", i, parts[i]));
		}

		for(int i=0; i<n; i++) {
			if(parts[i].startsWith(NAME)) {
				for(int j=0; j<(n-i); j++) {
					parts[j] = parts[i+j];
				}
				found = true;
				n -= i;
				break;
			}
		}

		if(!found) {
			Log.v(TAG, "Not found");
			return null;
		}
		return parts;
	}
	
	@Override
	public Cursor getCursorFromPath(File file, SQLiteDatabase db) {
		// '/mnt/sdcard/MODS/mediastore.source'
		Log.v(TAG, String.format("FILE '%s'", file.getPath()));
		
		
		String [] parts = getParts(file.getPath());

		String last = null;
		if(parts != null)
			last = parts[parts.length-1].toLowerCase();

		String[] albumsFields = { MediaStore.Audio.Media._ID,
				  MediaStore.Audio.Albums.ALBUM,
				  MediaStore.Audio.Albums.ARTIST,
				  MediaStore.Audio.Albums.FIRST_YEAR,
				  MediaStore.Audio.Albums.LAST_YEAR,
				  MediaStore.Audio.Albums.NUMBER_OF_SONGS
				  };
		String[] fields = { MediaStore.Audio.Media._ID,
				  MediaStore.Audio.Media.DISPLAY_NAME,
				  MediaStore.Audio.Media.YEAR,
				  MediaStore.Audio.Media.TITLE,
				  MediaStore.Audio.Media.ARTIST,
				  MediaStore.Audio.Media.DATA,
				  MediaStore.Audio.Media.SIZE,
				  MediaStore.Audio.Media.ALBUM,
				  };

		ContentResolver cr = context.getContentResolver();
		Cursor cursor = null;
		  
		if(last != null && last.equals("albums")) {
			cursor = cr.query(MediaStore.Audio.Albums.EXTERNAL_CONTENT_URI, albumsFields, null, null, null);
		}
		cursor = cr.query(MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, fields, "album = 'Santogold'", null, null);
		//cursor = cr.query(MediaStore.Audio.Albums.EXTERNAL_CONTENT_URI, albumsFields, null, null, null);
		
		//cursor.moveToFirst();
		//String fileName = cursor.getString(2);
		//Log.v(TAG, String.format("%*s'%s', '%s'", "DUMMY", cursor.getString(1), cursor.getString(5)));
		//cursor.moveToPosition(-1);
		
		return wrapper.createWrapper(cursor);
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
