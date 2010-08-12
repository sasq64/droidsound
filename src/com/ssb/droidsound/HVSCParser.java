package com.ssb.droidsound;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import android.content.ContentValues;
import android.database.sqlite.SQLiteDatabase;
import android.provider.BaseColumns;

public class HVSCParser {
	private static final String TAG = HVSCParser.class.getSimpleName();

	static void parseSongLengths(InputStream is, SQLiteDatabase db) throws IOException {
		
		ContentValues values = new ContentValues();
		
		InputStreamReader reader = new InputStreamReader(is);
		BufferedReader breader = new BufferedReader(reader);
		String line;
		
		line = breader.readLine();
		if(line.equals("[Database]")) {
			//int counter = 0;
			
			db.execSQL("DROP TABLE IF EXISTS SONGINFO");
			db.execSQL("CREATE TABLE IF NOT EXISTS SONGINFO (" + BaseColumns._ID + " INTEGER PRIMARY KEY," +
					"HASH INTEGER," +
					"MD5 TEXT," +
					"COMMENT TEXT," +
					"SONGLENGTH TEXT" + ");");
			
			//db.beginTransaction();
			while(true) {
				breader.readLine();
				
				//counter++;
				//if(counter == 4630) {
				//	break;
				//}
				
				line = breader.readLine();
				if(line == null)
					break;
				int eq = line.indexOf('=');
				if(eq > 0) {
					String md5 = line.substring(0,eq);
					String lens = line.substring(eq+1);
					int hash = (int)(Long.parseLong(md5.substring(24), 16) & 0xffffffff);
					values.put("HASH", hash);
					values.put("MD5", md5);
					values.put("SONGLENGTH", lens);
					db.insert("SONGINFO", "HASH", values);
				}
			}
		}
		
	}
	/*
	ZipEntry le = zfile.getEntry("C64Music/DOCUMENTS/Songlengths.txt");
	if(le != null) {
		data = new byte [(int) le.getSize()] ;
		
		InputStreamReader reader = new InputStreamReader(zfile.getInputStream(le));
		BufferedReader breader = new BufferedReader(reader);
		String line0, line1;

		HashMap<String, String> hmap = new HashMap<String, String>();
		
		line0 = breader.readLine();
		if(line0.equals("[Database]")) {
			
			while(true) {
				line0 = breader.readLine();
				if(line0 == null)
					break;
				line1 = breader.readLine();
				if(line1 == null)
					break;
				String name = line0.substring(2);
				int eq = line1.indexOf('=');
				if(eq > 0) {
					String length = line1.substring(eq+1);
					//System.out.printf("%s = %s\n", name, length);
					//int len = Integer.parseInt(arg0);
					hmap.put(name, length);
				}
			}
		}
	}*/
	
	//String n = ze.getName().substring(8);
	/*
	System.out.printf("%s %s %s (%02d/%02d)\n", name, author, copyright, startSong, songs);
	String length = hmap.get(n.substring(8));
	int iLength = 0;
	if(length != null) {					
		String lens [] = length.split(" ");
		System.out.printf("%s --- %d\n", length, lens.length);
		if(lens.length > 1)
			length = lens[startSong-1];
		int colon = length.indexOf(':');
		int min = Integer.parseInt(length.substring(0, colon));
		int sec = Integer.parseInt(length.substring(colon+1, colon+3));
		iLength = min*60+sec;
		System.out.printf("%s %s ==> %d seconds\n", n, length, iLength);
	} */
	
	//int year = 0;
	//try {
	//	year = Integer.parseInt(copyright.substring(0,4));
	//} catch (NumberFormatException e) {
	//}
	


}
