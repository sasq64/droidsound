package com.ssb.droidsound.database;

import java.io.File;
import java.io.InputStream;

import android.database.Cursor;
import android.database.MatrixCursor;
import android.database.sqlite.SQLiteDatabase;

import com.ssb.droidsound.FileIdentifier;

public class FileSystemSource implements DataSource {
	
	public static final String NAME = "filesystem.source";
	
	public static String BasePath = null;
	

	@Override
	public boolean parseDump(InputStream is, int size, SQLiteDatabase scanDb, ScanCallback scanCallback) {
		return true;
	}

	@Override
	public String getTitle() {
		return "Filesystem";
	}

	@Override
	public Cursor getCursorFromPath(File file, SQLiteDatabase db, int sorting) {
		
		String fs = file.getPath();
		int pos = fs.indexOf(NAME);
		
		String fsPath = fs.substring(0, pos);
		
		String dirPath = BasePath + "/" + fs.substring(pos + NAME.length());
		
		file = new File(dirPath);
		if(!file.exists())
			return null;

		MatrixCursor mc = new MatrixCursor(new String[] { "TITLE", "TYPE", "PATH", "FILENAME" });
		
		for(File f : file.listFiles()) {
			
			String name = f.getName();
			String path = f.getParent();
			name = name.substring(name.lastIndexOf('/') + 1);
			
			if(f.isDirectory()) {
				mc.addRow(new Object [] { name, SongDatabase.TYPE_DIR, null, name } );
			} else {
				if(FileIdentifier.canHandle(name) != null)
					mc.addRow(new Object [] { name, SongDatabase.TYPE_FILE, f.getParent(), f.getName() } );
			}
			
		}		
		return mc;

	}

	@Override
	public String getPathTitle(File file) {		
		//if(displayTitle != null) return displayTitle;
		String n = file.getName();
		if(n.equals(NAME)) return "Filesystem";
		return file.getName();
	}

	@Override
	public void createIndex(int mode, SQLiteDatabase db) {
	}

	@Override
	public Cursor search(String query, String fromPath, SQLiteDatabase db) {
		return null;
	}

}
