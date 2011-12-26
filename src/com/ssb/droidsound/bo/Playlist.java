package com.ssb.droidsound.bo;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import com.ssb.droidsound.utils.Log;

public class Playlist {
	private static final Charset UTF8 = Charset.forName("UTF-8");
	private static final String TAG = Playlist.class.getSimpleName();
	private static final Map<File, Playlist> PLAYLISTS = new HashMap<File, Playlist>();

	private final File plistFile;
	private final List<SongFile> songs;

	private String title;

	public static synchronized Playlist getPlaylist(File file) {
		if (! PLAYLISTS.containsKey(file)) {
			PLAYLISTS.put(file, new Playlist(file));
		}
		return PLAYLISTS.get(file);
	}

	protected Playlist(File file) {
		plistFile = file;
		Log.d(TAG, "Opening playlist " + file.getPath());

		title = file.getName();
		int dot = title.lastIndexOf('.');
		if(dot > 0) {
			title = title.substring(0, dot);
		}

		songs = new ArrayList<SongFile>();
		try {
			byte[] data = new byte[(int) plistFile.length()];
			DataInputStream dis = new DataInputStream(new FileInputStream(plistFile));
			dis.readFully(data);
			dis.close();

			JSONArray json = new JSONArray(new String(data, UTF8));
			for (int i = 0; i < json.length(); i ++) {
				JSONObject obj = json.getJSONObject(i);
				songs.add(deserialize(obj));
			}
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	 }

	private static JSONObject serialize(SongFile songFile) throws JSONException {
		JSONObject obj = new JSONObject();
		obj.put("subtune", songFile.getSubtune());
		obj.put("playtime", songFile.getPlaytime());
		obj.put("fileName", songFile.getFileName());
		obj.put("zipPath", songFile.getZipPath());
		obj.put("zipName", songFile.getZipName());
		obj.put("title", songFile.getTitle());
		obj.put("composer", songFile.getComposer());
		return obj;
	}

	private static SongFile deserialize(JSONObject obj) throws JSONException {
		return new SongFile(
				obj.getInt("subtune"),
				obj.getInt("playtime"),
				obj.getString("fileName"),
				obj.getString("zipPath"),
				obj.getString("zipName"),
				obj.getString("title"),
				obj.getString("composer")
		);
	}

	public synchronized void insert(int position, SongFile songFile) throws IOException {
		songs.add(position, songFile);
		flush();
	}

	private void flush() {
		try {
			FileOutputStream fos = new FileOutputStream(plistFile);
			JSONArray arr = new JSONArray();
			for (SongFile s : songs) {
				JSONObject obj = serialize(s);
				arr.put(obj);
			}
			fos.write(arr.toString().getBytes(UTF8));
			fos.close();
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}

	public synchronized void clear() {
		songs.clear();
		flush();
	}

	public String getTitle() {
		return title;
	}

	public synchronized boolean contains(SongFile songFile) {
		for (SongFile s : songs) {

			if (s.getFileName().equals(songFile.getFileName())) {
				return true;
			}
		}

		return false;
	}

	public synchronized void add(SongFile s) {
		songs.add(s);
	}

	public synchronized void remove(int location) {
		songs.remove(location);
		flush();
	}

	public synchronized List<SongFile> getSongs() {
		return Collections.unmodifiableList(songs);
	}

	public synchronized void deletePlaylist() {
		PLAYLISTS.remove(this);
		plistFile.delete();
	}
}