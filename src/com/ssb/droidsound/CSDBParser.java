package com.ssb.droidsound;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.provider.BaseColumns;
import android.util.Log;

public class CSDBParser {
	private static final String TAG = CSDBParser.class.getSimpleName();
	
	static boolean parseCSDB(File file, SQLiteDatabase db, SongDatabase.ScanCallback scanCallback) {
		
		boolean ok = false;
		
		db.execSQL("DROP TABLE IF EXISTS RELEASES;");
		db.execSQL("DROP TABLE IF EXISTS GROUPS;");
		db.execSQL("DROP TABLE IF EXISTS EVENTS;");
		db.execSQL("DROP TABLE IF EXISTS RELEASESIDS;");
		
		db.execSQL("CREATE TABLE IF NOT EXISTS " + "RELEASES" + " (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
				"ID" + " INTEGER," +
				"NAME" + " TEXT," +
				"GROUPID" + " INTEGER," +

				"TYPE" + " TEXT," +
				"YEAR" + " INTEGER," +
				"EVENTID" + " INTEGER," +
				"COMPO" + " TEXT," +
				"PLACE" + " INTEGER" + ");");

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
			Log.v(TAG, "OPENING CSDB");			
			reader = new BufferedReader(new FileReader(file));				
			String line = reader.readLine();
			int count = 0;
			int total = line.length()+1;
			int fileSize = (int) file.length();
			while(line != null) {
				
				count++;
				if((count % 500) == 0) {
					if(scanCallback != null) {
						scanCallback.notifyScan(null, total * 100 / fileSize);
					}					
				}

				if(line.equals("[Releases]")) {
					Log.v(TAG, "RELEASES");
					place = 0;
				} else
				if(line.equals("[Groups]")) {
					Log.v(TAG, "GROUPS");
					place = 1;
				} else
				if(line.equals("[Events]")) {
					Log.v(TAG, "EVENTS");
					place = 2;
				} else {
					String[] args = line.split("\t");
					ContentValues values = new ContentValues();
					if(place == 0) {
						// (id, name, gid, type, y, eid, compo, place, ','.join(fnames))
						
						Log.v(TAG, String.format("Release (%s) %s [%s]\n", args[0], args[1], args[4]));
						
						values.put("ID", Integer.parseInt(args[0]));
						values.put("NAME", args[1]);
						if(args[2].length() > 0)
							values.put("GROUPID", Integer.parseInt(args[2])); 
						values.put("TYPE", args[3]); 
						if(args[4].length() > 0)
							values.put("YEAR", args[4]); 
						if(args[5].length() > 0)
							values.put("EVENTID", Integer.parseInt(args[5]));
						if(args[6].length() > 0)
							values.put("COMPO", args[6]);
						if(args[7].length() > 0)
							values.put("PLACE", Integer.parseInt(args[7]));
						
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
						Log.v(TAG, String.format("Group (%s) %s \n", args[0], args[1]));
						values.put("ID", Integer.parseInt(args[0]));
						values.put("NAME", args[1]);
						db.insert("GROUPS", "ID", values);
					} else if(place == 2) {
						Log.v(TAG, String.format("Event (%s) %s \n", args[0], args[1]));
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
		Log.v(TAG, "DONE");
		
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
	public static Cursor getPath(String path, SQLiteDatabase rdb) {
		
		if(path == "") {
			return rdb.rawQuery("select name, id from events order by date", null);
		} else {
			return null;
		}
		//return rdb.rawQuery("select releases.name, groups.name from releases,groups where releases.groupid=groups.id and releases.eventid=1577", null);
		//return rdb.query("RELEASES", new String[] { "NAME AS TITLE, GROUP AS COMPOSER" }, "EVENTID=?", new String[] { "1577" }, null, null, "NAME");
	}	

}
