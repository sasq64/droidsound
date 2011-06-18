package com.ssb.droidsound.utils;

import java.util.ArrayList;
import java.util.List;


import android.database.Cursor;
import android.database.MatrixCursor;

import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.utils.Log;

public class DBFileSystem {
	private static final String TAG = DBFileSystem.class.getSimpleName();
	
	public static interface CursorFactory {
		Cursor getCursor(String parts[], int sorting);
	}
	
	private static class Path {
		public String [] parts;
		public CursorFactory factory;
		public String [] contents;
		public String[] contentPaths;
		public Path(String [] parts, CursorFactory factory) {
			this.parts = parts;
			this.factory = factory;
		}
		public Path(String [] parts, String [] contents, String [] contentPaths) {
			this.parts = parts;
			this.contents = contents;
			this.contentPaths = contentPaths;
		}
	};
	
	private List<Path> pathList;

	
	private String baseName;
	
	public DBFileSystem(String base) {
		baseName = base;
		pathList = new ArrayList<Path>();
	}
	
	public void addPath(String pathPattern, CursorFactory qf) {
		String [] parts = pathPattern.split("/");		
		pathList.add(new Path(parts, qf));
	}
	
	public void addPath(String pathPattern, String [] contents) {
		String [] parts = pathPattern.split("/");		
		pathList.add(new Path(parts, contents, contents));
	}

	public void addPath(String pathPattern, String [] contents, String [] contentPaths) {
		String [] parts = pathPattern.split("/");		
		pathList.add(new Path(parts, contents, contentPaths));
	}

	private boolean matchPath(String [] pattern, String [] path) {
		
		// **,ALBUM
		// NEW RELEASES,* 
		
		int j = 0;
		//boolean starstar = false;
		for(int i=0; i<path.length; i++) {
			if(j >= pattern.length)
				return false;
			Log.d(TAG, "Match %s vs %s", i, pattern[j], path[i]);

			if(pattern[j].equals("*") || path[i].equals(pattern[j])) {
				j++;	
			} else
				break;			
		}
		
		return (j == path.length);		
	}
	
	
	public Cursor getFileInPath(String path, int sorting) {
		
		Log.d(TAG, "PATH %s", path);
		String [] parts = path.split("/");
		int n = parts.length;
		for(int i=0; i<n; i++) {
			Log.d(TAG, "PART %d: '%s'", i, parts[i]);
		}
		
		String newParts [] = null;

		for(int i=0; i<n; i++) {
			if(parts[i].startsWith(baseName)) {
				n -= (i+1);
				newParts = new String [n];
				for(int j=0; j<n; j++) {
					newParts[j] = parts[i+j+1];
				}
				break;
			}
		}

		if(newParts == null) {
			return null;
		}
		
		for(int i=0; i<n; i++) {
			Log.d(TAG, "NEWPART %d: '%s'", i, newParts[i]);
		}

		for(Path p : pathList) {
			if(matchPath(p.parts, newParts)) {
				if(p.contents != null) {
					
					MatrixCursor mc = new MatrixCursor(new String [] { "TITLE", "FILENAME", "TYPE" } );
					for(int i=0; i<p.contents.length; i++) {
						mc.addRow(new String [] {p.contents[i], p.contentPaths[i], Integer.toString(SongDatabase.TYPE_DIR)});
					}
					return mc;
				} else
					return p.factory.getCursor(newParts, sorting);
			}
		}

		return null;
	}
	

}
