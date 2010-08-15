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

	public class Song {

		public File file;
		public String title;
		public String subtitle;
		public int startsong;
		
	/*	
		@Override
		public int hashCode() {
			return file.getPath().hashCode();
		}
		
		@Override
		public boolean equals(Object o) {
			if(o instanceof String) {
				return file.getPath().equals(o);
			} else
			if(o instanceof Song) {
				return file.getPath().equals(((Song)o).file.getPath());
			}
			return super.equals(o);
		}
*/
		
	}

	private static final String TAG = Playlist.class.getSimpleName();
	
	
	private static Map<File, Playlist> allPlaylists = new HashMap<File, Playlist>();
	
	private static Object lock = new Object();
	
	public static Playlist getPlaylist(File file) {
		
		Playlist pl = null;
		synchronized (lock) {			
			pl = allPlaylists.get(file);
			if(pl == null) {
				Log.v(TAG, "Creating new playlist " + file.getPath());
				pl = new Playlist(file);
				allPlaylists.put(file, pl);
			} else {
				Log.v(TAG, "Found playlist " + file.getPath());
			}
		}
		return pl;
	}

	public static void flushAll() {
		synchronized (lock) {
			for(File f : allPlaylists.keySet()) {
				Playlist pl = allPlaylists.get(f);
				pl.flush();
			}
		}
	}

	
	private MatrixCursor cursor;
	private File plistFile;
	private List<String> lines;

	private boolean changed;

	private String title;
	private String subtitle;


	private boolean written;


	private long fileModified;
	
	
	 private Playlist(File file) {
		
		plistFile = file;
		changed = false;
		written = false;
		Log.v(TAG, "Opening playlist " + file.getPath());
		
		title = file.getName();
		int dot = title.lastIndexOf('.');
		if(dot > 0) {
			title = title.substring(0, dot);
		}
		readLines();		
	}
	
	 private void readLines() {
		BufferedReader reader;
		lines = new ArrayList<String>();
		try {
			reader = new BufferedReader(new FileReader(plistFile));
			String line = reader.readLine();
			while(line != null) {
				//Log.v(TAG, line);
				lines.add(line);
				line = reader.readLine();
			}
			reader.close();
			
			fileModified = plistFile.lastModified();
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}				
	 }
	 
	 
	
	 synchronized public Cursor getCursor() {
				
		if(cursor == null) {
			
			Log.v(TAG, "Creating cursor for " + plistFile.getPath());
			
			cursor  = new MatrixCursor(new String[] { "PATH", "FILENAME", "TITLE", "SUBTITLE" });
			Object cols[] = new Object [4];

			for(String line : lines) {
				Log.v(TAG, line);
				
				if(line.length() > 0) {
					
					String [] linecols = line.split("\t");

					// int sc = linecols[0].lastIndexOf(';');					
					cols[2] = cols[3] = null;					
					// if(sc >= 0) {
					// 	try {
					// 		cols[4] = Integer.parseInt(linecols[0].substring(sc+1));
					// 	} catch (NumberFormatException e) {
					// 	}
					// 	linecols[0] = linecols[0].substring(0, sc);
					// }
					
					File f = new File(linecols[0]);
					
					String path = f.getParent();
					cols[1] = f.getName();
					
					if(path.charAt(0) == '$') {
						int slash = path.indexOf('/');
						String var = path.substring(1, slash);
						path = "/sdcard/MODS/C64Music.zip/C64Music" + path.substring(slash);
					}
					
					cols[0] = path;
					
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
		cursor.moveToPosition(-1);
		return cursor;
	}
		
	
	
	private String fileToLine(SongFile songFile) {
		InputStream is;
		FileIdentifier.MusicInfo minfo = null;
		try {
			is = new FileInputStream(songFile.getFile());
			minfo = FileIdentifier.identify(songFile.getName(), is);
			is.close();
		} catch (FileNotFoundException e1) {
		} catch (IOException e) {
		}
		
		String s = songFile.getPath();
		if(minfo != null) {

			if(minfo.title != null) {
				s = s + "\t" + minfo.title;
				
				if(songFile.getSubtune() >= 0) {
					s += String.format(" #%02d", songFile.getSubtune()+1);
				}
				
				if(minfo.composer != null) {
					s = s + "\t" + minfo.composer;
				}
			}
		}
		return s;
	}
	
	synchronized void add(SongFile songFile) {
		
		if(songFile.isDirectory()) {			
			SongFile [] files = songFile.listSongFiles();
			for(SongFile f : files) {
				lines.add(fileToLine(f));
			}			
		} else {
			Log.v(TAG, "Adding " + songFile.getPath());
			lines.add(fileToLine(songFile));
		}
		cursor = null;
		changed = true;
	}
	
	synchronized public void add(Cursor c, int subtune) {
		
		while(true) {		
			String title = c.getString(c.getColumnIndex("TITLE"));
			String composer = c.getString(c.getColumnIndex("COMPOSER"));
			String filename = c.getString(c.getColumnIndex("FILENAME"));
			String path = c.getString(c.getColumnIndex("PATH"));
	
			File f = new File(path, filename);
			String line = f.getPath();
			if(subtune >= 0) {
				
				if(title != null) {
					title = String.format("%s #%02d", title, subtune+1);
				}

				line += (";" + subtune);

			}
	
			if(title != null) {
				line = line + "\t" + title;
				if(composer != null) {
					line = line + "\t" + composer;
				}
			}
	
			Log.v(TAG, "Adding ## " + line);

			lines.add(line);
			if(!c.moveToNext())
				break;
		}
		
		changed = true;
		cursor = null;
	}

	
	synchronized void remove(File file) {
		
		String removeMe = null;
		for(String line : lines) {
			String cols [] = line.split("\t");
			//int sc = cols[0].lastIndexOf(';');
			//if(sc >= 0) {
			//	cols[0] = cols[0].substring(0, sc);
			//}
			if(cols != null && cols[0] != null) {
				if(file.getPath().equals(cols[0])) {
					Log.v(TAG, String.format("Removing %s", cols[0]));
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
	
	synchronized void flush() {
		
		if(!changed) {
			//Log.v(TAG, "Not flushing unchanged " + plistFile.getPath());
			return;
		}
		
		changed = false;
		written = true;
		
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

	synchronized public void clear() {
		Log.v(TAG, String.format("Clearing playlist %s with %d entries", plistFile.getPath(), lines.size()));
		lines = new ArrayList<String>();
		cursor = null;
		changed = true;
	}

	synchronized public File getFile() {
		return plistFile;
	}

	synchronized public String getTitle() {
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

	synchronized public List<File> getFiles() {
		List<File> files = new ArrayList<File>();
		for(String line : lines) {
			if(line.length() > 0) {
				int tab = line.indexOf('\t');
				if(tab > 0) {					
					//int sc = line.indexOf(';');
					//if(sc >= 0 && sc < tab) {
					//	tab = sc;
					//}
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
	
	@Override
	public int hashCode() {
		
		if(!written && plistFile.lastModified() > fileModified) {
			// Changed in another process
			Log.v(TAG, "Rereading Playlst");
			readLines();
		}
		
		int hash = lines.size();
		for(String line : lines) {
			hash ^= line.hashCode();
		}		
		return hash;
	}

	public List<Song> getSongs() {
		List<Song> songs = new ArrayList<Song>();
		
		Cursor c = getCursor();
		
		while(c.moveToNext()) {
			
			Song song = new Song();
			
			String p = cursor.getString(cursor.getColumnIndex("PATH"));
			String n = cursor.getString(cursor.getColumnIndex("FILENAME"));
			song.startsong = -1;
			int sc = n.lastIndexOf(';');
			if(sc >= 0) {
				try {
					song.startsong = Integer.parseInt(n.substring(sc+1));
				} catch (NumberFormatException e) {
				}
				n = n.substring(0, sc);
			}
			
			song.subtitle = cursor.getString(cursor.getColumnIndex("SUBTITLE"));

			
			song.file = new File(p, n);
			song.title = cursor.getString(cursor.getColumnIndex("TITLE"));
			//song.startsong = cursor.getInt(cursor.getColumnIndex("STARTSONG"));
			Log.v(TAG, String.format("Songlist sentry %s %d",song.file.getPath(), song.startsong));
			songs.add(song);
			
		}
		return songs;
	}	
}
