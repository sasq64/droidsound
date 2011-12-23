package com.ssb.droidsound;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.database.AbstractCursor;
import android.database.Cursor;

import com.ssb.droidsound.utils.Log;

public class Playlist {
	private static final String TAG = Playlist.class.getSimpleName();
	private static Map<File, Playlist> PLAY_LISTS = new HashMap<File, Playlist>();

	private MyCursor cursor;
	private final File plistFile;
	private final List<String> lines;

	private boolean changed;

	private String title;

	public static Playlist getPlaylist(File file) {
		synchronized (PLAY_LISTS) {
			if (! PLAY_LISTS.containsKey(file)) {
				PLAY_LISTS.put(file, new Playlist(file));
			}
			return PLAY_LISTS.get(file);
		}
	}

	public static void flushAll() {
		synchronized (PLAY_LISTS) {
			for (Playlist pl : PLAY_LISTS.values()) {
				pl.flush();
			}
		}
	}

	private Playlist(File file) {
		plistFile = file;
		changed = false;
		Log.d(TAG, "Opening playlist " + file.getPath());

		title = file.getName();
		int dot = title.lastIndexOf('.');
		if(dot > 0) {
			title = title.substring(0, dot);
		}

		lines = new ArrayList<String>();
		try {
			BufferedReader reader = new BufferedReader(new FileReader(plistFile));
			String line;
			while (null != (line = reader.readLine())) {
				lines.add(line);
			}
			reader.close();
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	 }

	 private static class MyCursor extends AbstractCursor {
		private final List<SongFile> songs;
		private int position;
		private final String[] columnNames;
		private final String[] currentRow;
		private SongFile currentSong;

		private static final int COL_PATH = 0;
		private static final int COL_FILENAME = 1;
		private static final int COL_TITLE = 2;
		private static final int COL_SUBTITLE = 3;

		public MyCursor(Playlist pl) {
			songs = pl.getSongs();
			columnNames = new String[] { "PATH", "FILENAME", "TITLE", "SUBTITLE" };
			currentRow = new String[4];
		}

		@Override
		public boolean onMove(int oldPosition, int newPosition) {
			position = newPosition;
			currentSong = songs.get(position);

			String path = currentSong.getPath();
			int slash = path.lastIndexOf('/');
			String fname = path.substring(slash+1);
			if (slash < 0) {
				path = "";
			} else {
				path = path.substring(0, slash);
			}

			currentRow[COL_FILENAME] = fname;
			currentRow[COL_PATH] = path;
			currentRow[COL_TITLE] = currentSong.getTitle();
			currentRow[COL_SUBTITLE] = currentSong.getComposer();
			return true;
		}

		@Override
		public String[] getColumnNames() {
			return columnNames;
		}

		@Override
		public int getCount() {
			return songs.size();
		}

		@Override
		public double getDouble(int column) {
			throw new RuntimeException("No double columns");
		}

		@Override
		public float getFloat(int column) {
			throw new RuntimeException("No float columns");
		}

		@Override
		public int getInt(int column) {
			throw new RuntimeException("No int columns");
		}

		@Override
		public long getLong(int column) {
			throw new RuntimeException("No long columns");
		}

		@Override
		public short getShort(int column) {
			throw new RuntimeException("No short columns");
		}

		@Override
		public String getString(int column) {
			return currentRow[column];
		}

		@Override
		public boolean isNull(int column) {
			return currentRow[column] == null;
		}
	 };

	 public synchronized Cursor getCursor() {
		if (cursor == null) {
			cursor  = new MyCursor(this);
		}
		cursor.moveToPosition(-1);
		return cursor;
	}

	private String serialize(SongFile songFile) throws IOException {
		File f = songFile.getFile();
		byte[] module = new byte[(int) f.length()];
		DataInputStream dis = new DataInputStream(new FileInputStream(f));
		dis.readFully(module);
		String s = songFile.getPath();
		FileIdentifier.MusicInfo minfo = FileIdentifier.identify(f.getName(), module);

		String title = songFile.getTitle();
		if(title == null && minfo != null)
			title = minfo.title;

		String composer = songFile.getComposer();
		if (composer == null && minfo != null)
			composer = minfo.composer;

		if (title != null) {
			s = s + "\t" + title;
			if (composer != null) {
				s = s + "\t" + composer;
			}
		}

		return s;
	}

	synchronized public void add(SongFile songFile) throws IOException {
		if (songFile.isDirectory()) {
			for (SongFile f : songFile.listSongFiles()) {
				lines.add(serialize(f));
			}
		} else {
			lines.add(serialize(songFile));
		}
		cursor = null;
		changed = true;
	}

	public void insert(int position, SongFile songFile) throws IOException {
		lines.add(position, serialize(songFile));
		changed = true;
		cursor = null;
	}

	public synchronized void add(Cursor c, int subtune, String tuneTitle) {
		while (true) {
			String title = c.getString(c.getColumnIndex("TITLE"));
			String composer = c.getString(c.getColumnIndex("COMPOSER"));
			String filename = c.getString(c.getColumnIndex("FILENAME"));
			String path = c.getString(c.getColumnIndex("PATH"));

			File f = new File(path, filename);
			String line = f.getPath();
			if (subtune >= 0) {
				if (tuneTitle != null) {
					title = tuneTitle;
				} else if (title != null) {
					title = String.format("%s #%02d", title, subtune+1);
				}

				line += ";" + subtune;

			}

			if (title != null) {
				line = line + "\t" + title;
				if (composer != null) {
					line = line + "\t" + composer;
				}
			}

			lines.add(line);
			if (! c.moveToNext())
				break;
		}

		changed = true;
		cursor = null;
	}

	public synchronized void flush() {
		if (! changed) {
			return;
		}
		changed = false;

		try {
			FileWriter writer = new FileWriter(plistFile);
			for (String line : lines) {
				writer.write(line + "\n");
			}
			writer.close();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public synchronized void clear() {
		lines.clear();
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

		for (String line : lines) {
			songs.add(new SongFile(line));
		}

		return songs;
	}
}