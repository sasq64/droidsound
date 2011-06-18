package com.ssb.droidsound.database;

import java.io.File;
import java.io.InputStream;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

public interface DataSource {

	boolean parseDump(InputStream is, int size, SQLiteDatabase scanDb, ScanCallback scanCallback);
	String getTitle();
	Cursor getCursorFromPath(File file, SQLiteDatabase db, int sorting);
	String getPathTitle(File file);
	void createIndex(int mode, SQLiteDatabase db);
	Cursor search(String query, String fromPath, SQLiteDatabase db);
}