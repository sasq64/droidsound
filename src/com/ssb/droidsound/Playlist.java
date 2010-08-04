package com.ssb.droidsound;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.database.Cursor;
import android.database.MatrixCursor;
import android.util.Log;

public class Playlist {
	private static final String TAG = Playlist.class.getSimpleName();
	
	private MatrixCursor cursor;
	private File plistFile;
	private List<String> lines;

	private boolean changed;

	private String title;
	
	public Cursor getCursor() {
				
		if(cursor == null) {
			
			Log.v(TAG, "Creating cursor for " + plistFile.getPath());
			
			cursor  = new MatrixCursor(new String[] { "PATH", "FILENAME", "TITLE", "SUBTITLE" });
			String cols[] = new String [4];

			for(String line : lines) {
				Log.v(TAG, line);
				
				if(line.length() > 0) {
					
					String [] linecols = line.split("\t");
					File f = new File(linecols[0]);
					
					cols[0] = f.getParent();
					cols[1] = f.getName();
					cols[2] = cols[3] = null;
					
					if(cols[0].charAt(0) == '$') {
						int slash = cols[0].indexOf('/');
						String var = cols[0].substring(1, slash);
						cols[0] = "/sdcard/MODS/C64Music.zip/C64Music" + cols[0].substring(slash);
					}
					
					if(linecols.length > 1) {
						cols[2] = linecols[1];
					} else {
						cols[2] = f.getName();
					}
					
					if(linecols.length > 2) {
						cols[3] = linecols[2];
					} else {
						cols[3] = f.getParent();
					}
		
					cursor.addRow(cols);
				}
			}
		}		
		
		return cursor;
	}
	
	private static Map<File, Playlist> allPlaylists = new HashMap<File, Playlist>();
	
	public static Playlist getPlaylist(File file) {
		
		Playlist pl = allPlaylists.get(file);
		if(pl == null) {
			Log.v(TAG, "Creating new playlist " + file.getPath());
			pl = new Playlist(file);
			allPlaylists.put(file, pl);
		} else {
			Log.v(TAG, "Found playlist " + file.getPath());
		}
		return pl;
	}

	public static void flushAll() {
		
		for(File f : allPlaylists.keySet()) {
			Playlist pl = allPlaylists.get(f);
			pl.flush();
		}
	}
	
	
	private Playlist(File file) {
		
		plistFile = file;
		changed = false;
		Log.v(TAG, "Opening playlist " + file.getPath());
		
		title = file.getName();
		int dot = title.lastIndexOf('.');
		if(dot > 0) {
			title = title.substring(0, dot);
		}
		
		BufferedReader reader;
		lines = new ArrayList<String>();
		try {
			reader = new BufferedReader(new FileReader(file));
			String line = reader.readLine();
			while(line != null) {
				//Log.v(TAG, line);
				lines.add(line);
				line = reader.readLine();
			}
			reader.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}				
	}
	
	
	private String fileToLine(File file) {
		InputStream is;
		FileIdentifier.MusicInfo minfo = null;
		try {
			is = new FileInputStream(file);
			minfo = FileIdentifier.identify(file.getName(), is);
			is.close();
		} catch (FileNotFoundException e1) {
		} catch (IOException e) {
		}
		
		String s = file.getPath();
		if(minfo != null) {

			if(minfo.title != null) {
				s = s + "\t" + minfo.title;
				if(minfo.composer != null) {
					s = s + "\t" + minfo.composer;
				}
			}
		}
		return s;
	}
	
	void add(File file) {
		
		if(file.isDirectory()) {			
			File [] files = file.listFiles();
			for(File f : files) {
				lines.add(fileToLine(f));
			}			
		} else {
			// Log.v(TAG, "Adding " + file.getPath());
			lines.add(fileToLine(file));
		}
		cursor = null;
		changed = true;
	}
	
	public void add(Cursor c) {
		String title = c.getString(c.getColumnIndex("TITLE"));
		String composer = c.getString(c.getColumnIndex("COMPOSER"));
		String filename = c.getString(c.getColumnIndex("FILENAME"));
		String path = c.getString(c.getColumnIndex("PATH"));
		
		String line = new File(path, filename).getPath();
		
		
		if(title != null) {
			line = line + "\t" + title;
			if(composer != null) {
				line = line + "\t" + composer;
			}
		}

		// Log.v(TAG, "Adding ## " + line);

		
		lines.add(line);
		changed = true;
		cursor = null;
	}

	
	void remove(File file) {
		
		String removeMe = null;
		for(String line : lines) {
			String cols [] = line.split("\t");
			if(cols != null && cols[0] != null) {
				if(file.getPath().equals(cols[0])) {
					removeMe = line;
				}
			}
		}
		if(removeMe != null) {		
			lines.remove(removeMe);
			Log.v(TAG, "Removing " + removeMe);
			cursor = null;
			changed = true;
		}
	}
	
	void flush() {
		
		if(!changed) {
			//Log.v(TAG, "Not flushing unchanged " + plistFile.getPath());
			return;
		}
		
		changed = false;
		
		Log.v(TAG, "Flushing " + plistFile.getPath());
		
		try {
			FileWriter writer = new FileWriter(plistFile);
			
			for(String line : lines) {
				writer.write(line + "\n");
			}			
			writer.close();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void clear() {
		lines = new ArrayList<String>();
		cursor = null;
		changed = true;
	}

	public File getFile() {
		return plistFile;
	}

	public String getTitle() {
		return title;
	}
	/*
	public List<String> getLines() {
		return lines;
	}

	public void addLine(String line) {
		lines.add(line);
		cursor = null;
		changed = true;		
	}*/

	public List<File> getFiles() {
		List<File> files = new ArrayList<File>();
		for(String line : lines) {
			if(line.length() > 0) {
				int tab = line.indexOf('\t');
				if(tab > 0) {
					line = new File(line.substring(0, tab)).getPath();
				}				
				if(line.charAt(0) == '$') {
					int slash = line.indexOf('/');
					String var =line.substring(1, slash);
					line = "/sdcard/MODS/C64Music.zip/C64Music" + line.substring(slash);
				}
				
				files.add(new File(line));

			}
		}
		return files;
	}	
	
}
