package com.ssb.droidsound.provider;

import com.ssb.droidsound.database.SongDatabase;

import android.content.ContentProvider;
import android.content.ContentValues;
import android.database.Cursor;
import android.net.Uri;

public class SongProvider extends ContentProvider {
	
	public static final Uri CONTENT_URI = Uri.parse("content://com.ssb.droidsound.provider");
	private static final Uri SONG_URI = Uri.parse("content://com.ssb.droidsound.provider/songs");
	
	public static final String TITLE = "TITLE";
	public static final String _ID = "_id";
	public static final String COMPOSER = "COMPOSER";
	public static final String FILENAME = "FILENAME";
	public static final String FLAGS = "FLAGS";

    @Override
	public int delete(Uri arg0, String arg1, String... arg2) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public String getType(Uri uri) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Uri insert(Uri uri, ContentValues values) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean onCreate() {

        SongDatabase songDatabase = new SongDatabase(getContext());
		return true;
	}

	@Override
	public Cursor query(Uri uri, String[] projection, String selection, String[] selectionArgs, String sortOrder) {
		// TODO Auto-generated method stub
		
		if(uri.equals(SONG_URI)) {
			
		}
		
		return null;
	}

	@Override
	public int update(Uri uri, ContentValues values, String selection, String... selectionArgs) {
		// TODO Auto-generated method stub
		return 0;
	}

}
