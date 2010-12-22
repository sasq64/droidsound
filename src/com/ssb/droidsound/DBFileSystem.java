package com.ssb.droidsound;

import java.util.List;

import android.database.Cursor;
import android.util.Log;

public class DBFileSystem {
	private static final String TAG = DBFileSystem.class.getSimpleName();
	
	public static interface CursorDir {
		Cursor getCursorFromPath(String parts[]);
	}
	
	public static class Directory {
		public String name;
		public List<Directory> children;
		public CursorDir dirCursor;

		public Directory getChild(String name) {
			for(Directory d : children) {
				if(d.name.equals(name)) {
					return d;
				}
			}
			return null;					
		}
	}
	
	private String baseName;
	private Directory rootDir;
	
	public DBFileSystem(String baseName) {
		this.baseName = baseName;
		rootDir = new Directory();
	}
	
	public Directory addDirectory(Directory parent, String name) {
		
		Directory newDir = new Directory();
		newDir.name = name;		
		parent.children.add(newDir);		
		return newDir;
		
	}
	
	
	public Cursor getFileInPath(String path) {
		
		String [] parts = path.split("/");
		int n = parts.length;
		boolean found = false;
		//pathTitle = null;

		for(int i=0; i<n; i++) {
			Log.v(TAG, String.format("PART %d: '%s'", i, parts[i]));
		}

		for(int i=0; i<n; i++) {
			if(parts[i].toUpperCase().startsWith(baseName)) {
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
		
		Directory dir = rootDir;

		for(int i=0; i<n; i++) {
			Log.v(TAG, String.format("PART %d: '%s'", i, parts[i]));
			dir = dir.getChild(parts[i]);
		}
				
		return dir.dirCursor.getCursorFromPath(parts);

	}
	

}
