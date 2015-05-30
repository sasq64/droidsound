package com.ssb.droidsound;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.database.AbstractCursor;
import android.database.Cursor;

import com.ssb.droidsound.database.EditableCursor;
import com.ssb.droidsound.file.FileSource;
import com.ssb.droidsound.utils.Log;

public class Playlist {
	private static final String TAG = Playlist.class.getSimpleName();
	
	
	private static Map<File, Playlist> allPlaylists = new HashMap<File, Playlist>();
	
	private static Object lock = new Object();
	
	
	private MyCursor cursor;
	private File plistFile;
	private List<String> lines;

	private boolean changed;

	private String title;
	//private String subtitle;

	private boolean written;
	private long fileModified;
	

	
	public static Playlist getPlaylist(File file) {
		
		Playlist pl = null;
		synchronized (lock) {			
			pl = allPlaylists.get(file);
			if(pl == null) {
				Log.d(TAG, "Creating new playlist " + file.getPath());
				pl = new Playlist(file);
				allPlaylists.put(file, pl);
			} else {
				Log.d(TAG, "Found playlist " + file.getPath());
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

	
	
	 private Playlist(File file) {
		
		plistFile = file;
		changed = false;
		written = false;
		Log.d(TAG, "Opening playlist " + file.getPath());
		
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
				//Log.d(TAG, line);
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
	 
	 private class MyCursor extends AbstractCursor implements EditableCursor {

		private List<SongFile> songs;
		private int position;
		private String[] columnNames;
		private String[] currentRow;
		private SongFile currentSong;
		private Playlist playlist;
		
		private static final int COL_PATH = 0;
		private static final int COL_FILENAME = 1;
		private static final int COL_TITLE = 2;
		private static final int COL_SUBTITLE = 3;

		public MyCursor(Playlist pl) {
			playlist = pl;
			songs = pl.getSongs();
			columnNames = new String[] { "PATH", "FILENAME", "TITLE", "SUBTITLE" };
			currentRow = new String [4];
		}
		/*
		private void build() {
			Object cols[] = new Object [4];

			for(String line : lines) {
				Log.d(TAG, line);
				
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
		} */
		
		@Override
		public boolean onMove(int oldPosition, int newPosition) {
			
			position = newPosition;
			currentSong = songs.get(position);
			
			String path = currentSong.getPath();
			int slash = path.lastIndexOf('/');
			String fname = path.substring(slash+1);
			if(slash < 0) path = "";
			else
			path = path.substring(0, slash);
			
			currentRow[COL_FILENAME] = fname;
			currentRow[COL_PATH] = path;
			currentRow[COL_TITLE] = currentSong.getTitle();
			currentRow[COL_SUBTITLE] = currentSong.getComposer();			
			return true;
			//super.onMove(oldPosition, newPosition);
		}

		@Override
		public boolean moveRow(int from, int to) {
			// TODO Auto-generated method stub
			int i = 0;
			for(SongFile s : songs) {
				Log.d(TAG, "%02d  %s", i++, s.getTitle());
			}

			Log.d(TAG, "Move %02d -> %02d", from, to);
			
			playlist.move(from, to);
			
			SongFile fromSong = songs.get(from);
			songs.add(to, fromSong);
			if(to < from) from++;
			songs.remove(from);	
			
			i = 0;
			for(SongFile s : songs) {
				Log.d(TAG, "%02d  %s", i++, s.getTitle());
			}
			
			
			
			
			return true;
		}

		@Override
		public boolean removeRow(int row) {
			// TODO Auto-generated method stub
			songs.remove(row);
			playlist.remove(row);
			return true;
		}

		@Override
		public String[] getColumnNames() {
			// TODO Auto-generated method stub
			return columnNames;
		}

		@Override
		public int getCount() {
			// TODO Auto-generated method stub
			return songs.size();
		}

		@Override
		public double getDouble(int column) {
			// TODO Auto-generated method stub
			return 0;
		}

		@Override
		public float getFloat(int column) {
			// TODO Auto-generated method stub
			return 0;
		}

		@Override
		public int getInt(int column) {
			// TODO Auto-generated method stub
			return 0;
		}

		@Override
		public long getLong(int column) {
			// TODO Auto-generated method stub
			return 0;
		}

		@Override
		public short getShort(int column) {
			// TODO Auto-generated method stub
			return 0;
		}

		@Override
		public String getString(int column) {

			return currentRow[column];
			
		}

		@Override
		public boolean isNull(int column) {
			// TODO Auto-generated method stub
			return false;
		}
	 };
	 
	 
	
	 synchronized public Cursor getCursor() {
				
		if(cursor == null) {
			
			Log.d(TAG, "Creating cursor for " + plistFile.getPath());
			
			cursor  = new MyCursor(this); //new String[] { "PATH", "FILENAME", "TITLE", "SUBTITLE" });
			
		}
		cursor.moveToPosition(-1);
		return cursor;
	}
		
	
	
	private String fileToLine(SongFile songFile) {

		String s = songFile.getPath();
		FileIdentifier.MusicInfo minfo = null;
		if(s.startsWith("http://")) {			
			try {
				songFile.setTitle(URLDecoder.decode(songFile.getName(), "UTF-8"));
			} catch (UnsupportedEncodingException e) {
				throw new RuntimeException(e);
			}
		} else {
			FileSource fs = FileSource.fromFile(songFile.getFile());
			minfo = FileIdentifier.identify(fs);
			fs.close();
		}
		
		String title = songFile.getTitle();
		if(title == null && minfo != null)
			title = minfo.title;
		
		//if(songFile.getSubtune() >= 0) {
		//	s += String.format(" #%02d", songFile.getSubtune()+1);
		//}

		
		String composer = songFile.getComposer();
		if(composer == null && minfo != null)
			composer = minfo.composer;

		if(title != null) {
			s = s + "\t" + title;
			if(composer != null) {
				s = s + "\t" + composer;
			}			
		}

		return s;
	}
	
	synchronized public void add(SongFile songFile) {
		
		if(songFile.isDirectory()) {			
			SongFile [] files = songFile.listSongFiles();
			for(SongFile f : files) {
				lines.add(fileToLine(f));
			}			
		} else {
			Log.d(TAG, "Adding " + songFile.getPath());
			lines.add(fileToLine(songFile));
		}
		cursor = null;
		changed = true;
	}

	public void insert(int position, SongFile songFile) {
		lines.add(position, fileToLine(songFile));
		changed = true;
		cursor = null;
	}

	
	synchronized public void add(Cursor c, int subtune, String tuneTitle) {
		
		while(true) {		
			String title = c.getString(c.getColumnIndex("TITLE"));
			String composer = c.getString(c.getColumnIndex("COMPOSER"));
			String filename = c.getString(c.getColumnIndex("FILENAME"));
			String path = c.getString(c.getColumnIndex("PATH"));
	
			File f = new File(path, filename);
			String line = f.getPath();
			if(subtune >= 0) {
				
				if(tuneTitle != null) {
					title = tuneTitle;
				} else				
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
	
			Log.d(TAG, "Adding ## " + line);

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
					Log.d(TAG, "Removing %s", cols[0]);
					removeMe = line;
				}
			}
		}
		if(removeMe != null) {		
			lines.remove(removeMe);
			Log.d(TAG, "Removing " + removeMe);
			cursor = null;
			changed = true;
		}
	}
	
	synchronized void flush() {
		
		if(!changed) {
			//Log.d(TAG, "Not flushing unchanged " + plistFile.getPath());
			return;
		}
		
		changed = false;
		written = true;
		
		Log.d(TAG, "Flushing " + plistFile.getPath());
		
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
		Log.d(TAG, "Clearing playlist %s with %d entries", plistFile.getPath(), lines.size());
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

	public boolean contains(SongFile songFile) {
		for(String line : lines) {
			if(line.length() > 0) {
				int tab = line.indexOf('\t');
				if(tab > 0) {
					line = line.substring(0, tab);
				}					
				if(songFile.getPath().equals(line)) {
					return true;
				}
			}
		}
		return false;
	}	

	
	@Override
	public int hashCode() {
		
		if(!written && plistFile.lastModified() > fileModified) {
			// Changed in another process
			Log.d(TAG, "Rereading Playlst");
			readLines();
		}
		
		int hash = lines.size();
		for(String line : lines) {
			hash ^= line.hashCode();
		}		
		return hash;
	}
	
	public void move(int from, int to) {
		
		String fromLine = lines.get(from);
		lines.add(to, fromLine);
		if(to < from) from++;
		lines.remove(from);	
		changed = true;
		cursor = null;
	}
	
	public void remove(int location) {
		lines.remove(location);
		changed = true;
		cursor = null;
	}
	
	public SongFile getSong(int position) {
		return new SongFile(lines.get(position));
	}


	public List<SongFile> getSongs() {
		List<SongFile> songs = new ArrayList<SongFile>();
		
		for(String line : lines) {
			songs.add(new SongFile(line));
		}
		return songs;
	}



}
