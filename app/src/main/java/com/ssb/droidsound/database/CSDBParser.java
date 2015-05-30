package com.ssb.droidsound.database;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.CursorWrapper;
import android.database.MatrixCursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.os.Environment;
import android.provider.BaseColumns;
import android.util.SparseArray;

import com.ssb.droidsound.utils.Log;


public class CSDBParser implements DataSource {
	private static final String TAG = CSDBParser.class.getSimpleName();

	public static final String DUMP_NAME = "CSDBDUMP";

	private static String hvsc = null;
	
	//static Map<String, Integer> events = new HashMap<String, Integer>();
	SparseArray<String> groups = null;
	String pathName = null;
	
	public void setPath(String p) {
		pathName = p;
	}
		
	
	boolean parseCSDB(InputStream is, int fileSize, SQLiteDatabase db, ScanCallback scanCallback) {
		
		boolean ok = false;
		
		try {
			db.execSQL("DELETE FROM RELEASES;");
			db.execSQL("DELETE FROM GROUPS;");
			db.execSQL("DELETE FROM EVENTS;");
			db.execSQL("DELETE FROM RELEASESIDS;");
		} catch (SQLException e) {
		}
		
		// db.execSQL("DROP TABLE IF EXISTS RELEASES;");
		// db.execSQL("DROP TABLE IF EXISTS GROUPS;");
		// db.execSQL("DROP TABLE IF EXISTS EVENTS;");
		// db.execSQL("DROP TABLE IF EXISTS RELEASESIDS;");
		
		db.execSQL("CREATE TABLE IF NOT EXISTS " + "RELEASES" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
				"ID INTEGER," +
				"NAME TEXT," +
				"GROUPID INTEGER," +
				"TYPE TEXT," +
				"DATE INTEGER," +
				"EVENTID INTEGER," +
				"RATING INTEGER," +
				"PLACE INTEGER" + ");");

		db.execSQL("CREATE TABLE IF NOT EXISTS " + "GROUPS" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
				"ID" + " INTEGER," +
				"NAME" + " TEXT" + ");");

		db.execSQL("CREATE TABLE IF NOT EXISTS " + "EVENTS" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
				"ID" + " INTEGER," +
				"DATE" + " INTEGER," +
				"NAME" + " TEXT" + ");");

		db.execSQL("CREATE TABLE IF NOT EXISTS " + "RELEASESIDS" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
				"RELEASEID" + " INTEGER," +
				"PATH" + " TEXT," +
				"FILENAME" + " TEXT" + ");");

		
		BufferedReader reader;
		db.beginTransaction();
		try {
			int place = -1;
			Log.d(TAG, "OPENING CSDB");			
			
			reader = new BufferedReader(new InputStreamReader(is, "ISO-8859-1"));			
			//reader = new BufferedReader(new FileReader(file));				
			String line = reader.readLine();
			int count = 0;
			int total = line.length()+1;
			//int fileSize = (int) is.available();
			while(line != null) {
				
				count++;
				if((count % 300) == 0) {
					if(scanCallback != null) {
						scanCallback.notifyScan(null, total * 100 / fileSize);
					}
					// db.yieldIfContendedSafely();
				}

				if(line.equals("[Releases]")) {
					Log.d(TAG, "RELEASES");
					place = 0;
				} else
				if(line.equals("[Groups]")) {
					Log.d(TAG, "GROUPS");
					place = 1;
				} else
				if(line.equals("[Events]")) {
					Log.d(TAG, "EVENTS");
					place = 2;
				} else {
					String[] args = line.split("\t");
					ContentValues values = new ContentValues();
					if(place == 0) {
						// (id, name, gid, type, y, eid, compo, place, ','.join(fnames))						
						
						values.put("ID", Integer.parseInt(args[0]));
						values.put("NAME", args[1]);
						if(args[2].length() > 0)
							values.put("GROUPID", Integer.parseInt(args[2])); 
						values.put("TYPE", args[3]); 
						if(args[4].length() > 0)
							values.put("DATE", Integer.parseInt(args[4])); 
						if(args[5].length() > 0)
							values.put("EVENTID", Integer.parseInt(args[5]));
						if(args[6].length() > 0)
							values.put("PLACE", Integer.parseInt(args[6]));
						if(args[7].length() > 0)
							values.put("RATING", Integer.parseInt(args[7]));
						
						db.insert("RELEASES", "ID", values);
						
						String [] sids = args[8].split(",");
						if(sids.length > 0) {
							ContentValues values2 = new ContentValues();
							for(String s : sids) {
								values2.put("RELEASEID", Integer.parseInt(args[0]));
								File f = new File(s);
								values2.put("FILENAME", f.getName());
								values2.put("PATH", f.getParent());
								db.insert("RELEASESIDS", "PATH", values2);
							}
						}
					} else if(place == 1) {
						//Log.d(TAG, "Group (%s) %s \n", args[0], args[1]);
						values.put("ID", Integer.parseInt(args[0]));
						values.put("NAME", args[1]);
						db.insert("GROUPS", "ID", values);
					} else if(place == 2) {
						//Log.d(TAG, "Event (%s) %s \n", args[0], args[1]);
						values.put("ID", Integer.parseInt(args[0]));
						values.put("DATE", Integer.parseInt(args[1]));
						values.put("NAME", args[2]);
						db.insert("EVENTS", "ID", values);
					}
				}
				line = reader.readLine();
				if(line != null) {
					total += (line.length()+1);
				}
			}
			db.setTransactionSuccessful();
			ok = true;
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			db.endTransaction();
		}
		Log.d(TAG, "DONE");
		
		return ok;
	}

	/*
	 * CSDB:EVENTS/X2008/EdgeOfDisgrace/  song.sid
	 * CSDB:RELEASES/EdgeOfDisgrace/ song.sid
	 * CSDB:RELEASES/SomeCollection/ song.sid
	 * CSDB:GROUPS/BoozeDesign/EdgeOfDisgrace/ song.sid
	 * 
	 * select * from releasesids where group=booze release=eod
	 * 
	 */
	
	static class DirWrapper extends CursorWrapper {

		public DirWrapper(Cursor cursor) {
			super(cursor);
		}
		
		@Override
		public int getColumnIndex(String columnName) {
			if(columnName.equals("TYPE")) {
				return 99;
			}
			return super.getColumnIndex(columnName);
		}
		
		@Override
		public int getInt(int columnIndex) {
			if(columnIndex == 99) {
				return SongDatabase.TYPE_DIR;
			}
			return super.getInt(columnIndex);
		}
	};

	private class SidCursor extends CursorWrapper {
		private int pathIndex;

		public SidCursor(Cursor cursor) {
			super(cursor);
			pathIndex = cursor.getColumnIndex("PATH");
		}
		
		@Override
		public int getColumnIndex(String columnName) {
			if(columnName.equals("PATH")) {
				return 99;
			} else
			if(columnName.equals("SUBTITLE")) {
				return 98;
			}
			return super.getColumnIndex(columnName);
		}
		
		@Override
		public String getString(int columnIndex) {
			if(columnIndex == 99) {
				String path = getString(pathIndex);
				return hvsc + path;
			} else
			if(columnIndex == 98) {
				return getString(pathIndex);
			}
			return super.getString(columnIndex);
		}
		
	}

	private class ReleaseCursor extends CursorWrapper {
		private int gidIndex;
		private int nameIndex;
		private int typeIndex;
		private int placeIndex;
		private int ratingIndex;
		private String pathName;
		private int idIndex;

		public ReleaseCursor(Cursor cursor, String path) {
			super(cursor);
			pathName = path;
			gidIndex = cursor.getColumnIndex("GROUPID");
			nameIndex = cursor.getColumnIndex("NAME");
			typeIndex = cursor.getColumnIndex("TYPE");
			placeIndex = cursor.getColumnIndex("PLACE");
			ratingIndex = cursor.getColumnIndex("RATING");
			idIndex = cursor.getColumnIndex("ID");
		}
		
		public ReleaseCursor(Cursor cursor) {
			super(cursor);
			gidIndex = cursor.getColumnIndex("GROUPID");
			nameIndex = cursor.getColumnIndex("NAME");
			typeIndex = cursor.getColumnIndex("TYPE");
			placeIndex = cursor.getColumnIndex("PLACE");
			ratingIndex = cursor.getColumnIndex("RATING");
			idIndex = cursor.getColumnIndex("ID");
		}
		
		@Override
		public int getColumnIndex(String columnName) {
			if(columnName.equals("TYPE")) {
				return 97;
			}
			if(columnName.equals("TITLE")) {
				return 99;
			}
			if(columnName.equals("FILENAME")) {
				return 95;
			}
			if(columnName.equals("SUBTITLE")) {
				return 98;
			}
			if(pathName != null && columnName.equals("PATH")) {
				return 96;
			}
			return super.getColumnIndex(columnName);
		}
		
		@Override
		public String getString(int columnIndex) {
			
			if(columnIndex == 99) {
				String group = groups.get(getInt(gidIndex));
				if(group != null) {
					return String.format("%s / %s", getString(nameIndex), group);
				} else {
					return getString(nameIndex);
				}
			} else
			if(columnIndex == 98) {
				if(placeIndex >= 0) {
					return String.format("%s #%d", getString(typeIndex), getInt(placeIndex));
				} else {
					int r = getInt(ratingIndex);
					if(r > 0) {
						return String.format("%s (%02.2f)", getString(typeIndex), ((float)r)/100.0);
					} else {
						return getString(typeIndex);
					}
				}
			} else if(columnIndex == 96) {
				return pathName;
			} else if(columnIndex == 95) {
				return Integer.toString(getInt(idIndex));
			}
			return super.getString(columnIndex);
		}
		
		@Override
		public int getInt(int columnIndex) {
			if(columnIndex == 97) {
				return SongDatabase.TYPE_DIR;
			}
			return super.getInt(columnIndex);
		}
	}


	private String pathTitle;

	public Cursor getPath(String path, SQLiteDatabase rdb, int sorting) {
		
		String [] parts = path.split("/");
		int n = parts.length;
		boolean found = false;
		pathTitle = null;

		for(int i=0; i<n; i++) {
			Log.d(TAG, "PART %d: '%s'", i, parts[i]);
		}

		for(int i=0; i<n; i++) {
			if(parts[i].toUpperCase().startsWith(DUMP_NAME)) {
				for(int j=0; j<(n-i); j++) {
					parts[j] = parts[i+j];
				}
				found = true;
				n -= i;
				break;
			}
		}

		if(!found) {
			return null;
		}

		for(int i=0; i<n; i++) {
			Log.d(TAG, "PART %d: '%s'", i, parts[i]);
		}

		if(groups == null) {
			groups = new SparseArray<String>();
			 Cursor c = rdb.rawQuery("select id, name from groups", null);
			 c.moveToPosition(-1);
			 while(c.moveToNext()) {
				 groups.put(c.getInt(0), c.getString(1));
			 }
			 c.close();
		}
		
		if(hvsc == null) {
			Cursor c = rdb.rawQuery("select path from files where path like '%C64Music'", null);			
			if(c.getCount() > 0) {
				c.moveToFirst();
				hvsc = c.getString(0);
			} else {
				File extFile = Environment.getExternalStorageDirectory();
				if(extFile != null) {
					hvsc = extFile + "/C64Music.zip/C64Music";
				}				
				if(hvsc == null || !(new File(hvsc).exists())) {
					// TODO: This does not work since File() translates // to /
					hvsc = "http://swimsuitboys.com/droidsound/dl/C64Music";
				}
				
			}
			Log.d(TAG, "HVSC is " + hvsc);
			c.close();
		}
		
		if(n == 1) {
			
			pathTitle = "CSDb";
			
			MatrixCursor cursor = new MatrixCursor(new String [] {"NAME", "ID", "TYPE"});
			cursor.addRow(new Object [] { "EVENTS", 0, SongDatabase.TYPE_DIR} );
			cursor.addRow(new Object [] { "GROUPS", 1, SongDatabase.TYPE_DIR} );
			cursor.addRow(new Object [] { "TOP DEMOS", 2, SongDatabase.TYPE_DIR} );
			cursor.addRow(new Object [] { "TOP MUSIC", 3, SongDatabase.TYPE_DIR} );
			cursor.addRow(new Object [] { "TOP RELEASES", 4, SongDatabase.TYPE_DIR} );
			cursor.addRow(new Object [] { "LATEST RELEASES", 5, SongDatabase.TYPE_DIR} );
			return cursor;
		} else if(n == 2) {
			//pathTitle = parts[1];
			if(parts[1].equals("SEARCH")) {
				return null;
			} else
			if(parts[1].equals("EVENTS")) {
				return new DirWrapper(rdb.rawQuery("select name, date, id from events order by date desc", null));
			} else
			if(parts[1].equals("GROUPS")) {
				return new DirWrapper(rdb.rawQuery("select name, id from groups order by name collate nocase", null));
			} else
			if(parts[1].equals("TOP DEMOS")) {
				return new ReleaseCursor(rdb.rawQuery("select id, name, type, groupid, rating from releases where type='C64 Demo' order by rating desc limit 500", null));			
			} else
			if(parts[1].equals("TOP MUSIC")) {
				return new ReleaseCursor(rdb.rawQuery("select id, name, type, groupid, rating from releases where type='C64 Music' order by rating desc limit 250", null));			
			} else
			if(parts[1].equals("TOP RELEASES")) {
				return new ReleaseCursor(rdb.rawQuery("select id, name, type, groupid, rating from releases order by rating desc limit 2000", null));			
			} else
			if(parts[1].equals("LATEST RELEASES")) {
				return new ReleaseCursor(rdb.rawQuery("select id, name, type, groupid, rating from releases order by date desc limit 2000", null));			
			} else {
				return null;
			}
		} else if(n == 3) {
			if(parts[1].equals("EVENTS")) {
				/*Integer evid = events.get(parts[2]);
				if(evid == null) {
					Cursor c = rdb.rawQuery("select id from events where name=?", new String[]  { parts[2] });
					c.moveToFirst();
					evid = c.getInt(0);
				} */			
				//return new ReleaseCursor(rdb.rawQuery("select name, type, groupid, place, rating from releases where eventid=? order by type, place", new String[] { evid.toString() }));
				return new ReleaseCursor(rdb.rawQuery("select id, name, type, groupid, place, rating from releases where eventid in (select id from events where name=?) order by type, place", new String[] { parts[2] }));
			} else if(parts[1].equals("GROUPS")) {
				return new ReleaseCursor(rdb.rawQuery("select id, name, type, groupid, rating from releases where groupid in (select id from groups where name=?) order by rating desc", new String[] { parts[2] }));				
			} else if(parts[1].equals("RELEASES")) {
				Log.d(TAG, "RELEASES " + parts[2]);
				setTitle(parts[2], rdb);
				return new SidCursor(rdb.rawQuery("select path,filename from releasesids where releaseid=?", new String[] { parts[2] }));
			}			
			else { // Releases
				Log.d(TAG, "Release " + parts[2]);
				setTitle(parts[2], rdb);
				return new SidCursor(rdb.rawQuery("select path,filename from releasesids where releaseid=?", new String[] { parts[2] }));
			}
		} else {
			Log.d(TAG, "SID " + parts[3]);
			setTitle(parts[3], rdb);
			return new SidCursor(rdb.rawQuery("select path,filename from releasesids where releaseid=?", new String[] { parts[3] }));
			//return new SidCursor(rdb.rawQuery("select path,filename from releasesids where releaseid in (select id from releases where name=?)", new String[] { parts[3] })); 
			//return new SidWrapper("select releaseid, path, filename from releasesids where releaseid=?
		}
		//return rdb.rawQuery("select releases.name, groups.name from releases,groups where releases.groupid=groups.id and releases.eventid=1577", null);
		//return rdb.query("RELEASES", new String[] { "NAME AS TITLE, GROUP AS COMPOSER" }, "EVENTID=?", new String[] { "1577" }, null, null, "NAME");
	}

	private void setTitle(String id, SQLiteDatabase rdb) {
		
		Cursor c = rdb.rawQuery("select name from releases where id=?", new String[] {id });
		if(c != null) {
			if(c.moveToFirst()) {
				pathTitle = c.getString(0);
			}
			c.close();
		}
	}


	@Override
	public Cursor search(String query, String path, SQLiteDatabase db) {
	//public static Cursor search(SQLiteDatabase db, String query) {
		Log.d(TAG, "QUERY: %s PATH: %s",query, path);
		int csdb = path.toUpperCase().lastIndexOf(DUMP_NAME);
		path = path.substring(0, csdb + DUMP_NAME.length()) + "/RELEASES";
		return new ReleaseCursor(db.rawQuery("select id, name, type, groupid, rating from releases where name like ? order by name collate nocase limit 250", new String [] {"%" + query + "%"} ), path);		
	}


	@Override
	public String getTitle() {
		return "CSDb";
	}


	@Override
	public boolean parseDump(InputStream is, int size, SQLiteDatabase scanDb, ScanCallback scanCallback) {
		return parseCSDB(is, size, scanDb, scanCallback);
	}


	@Override
	public Cursor getCursorFromPath(File file, SQLiteDatabase rdb, int sorting) {
		return getPath(file.getPath(), rdb, sorting);
	}


	@Override
	public String getPathTitle(File file) {
		return pathTitle;
	}


	@Override
	public void createIndex(int mode, SQLiteDatabase db) {
		
		// TODO: Check that tables exist (csdb was imported)
		/*
		switch(mode) {
		case SongDatabase.INDEX_NONE:
			db.execSQL("DROP INDEX IF EXISTS relindex ;");		
			db.execSQL("DROP INDEX IF EXISTS grpindex ;");
			db.execSQL("DROP INDEX IF EXISTS evtindex ;");
			break;
		case SongDatabase.INDEX_BASIC:
			db.execSQL("DROP INDEX IF EXISTS relindex ;");		
			db.execSQL("DROP INDEX IF EXISTS grpindex ;");
			db.execSQL("DROP INDEX IF EXISTS evtindex ;");
			break;
		case SongDatabase.INDEX_FULL:
			db.execSQL("CREATE INDEX IF NOT EXISTS relindex ON RELEASES (NAME) ;");		
			db.execSQL("CREATE INDEX IF NOT EXISTS grpindex ON GROUPS (NAME) ;");
			db.execSQL("CREATE INDEX IF NOT EXISTS evtindex ON EVENTS (NAME) ;");
			break;
		} */
	}


	public static void init() {
		hvsc = null;
	}



}
