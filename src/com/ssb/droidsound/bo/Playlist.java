package com.ssb.droidsound.bo;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import com.ssb.droidsound.utils.Log;

public class Playlist {
	private static final Charset UTF8 = Charset.forName("UTF-8");
	private static final String TAG = Playlist.class.getSimpleName();

	private final File plistFile;
	private final List<SongFile> songs;

	private String title;

	public Playlist(File file) {
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

			if (data.length != 0) {
				JSONArray json = new JSONArray(new String(data, UTF8));
				for (int i = 0; i < json.length(); i ++) {
					JSONObject obj = json.getJSONObject(i);
					songs.add(deserialize(obj));
				}
			}
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	 }

	private static JSONObject serialize(SongFile songFile) throws JSONException {
		JSONObject obj = new JSONObject();
		obj.put("id", songFile.getId());
		obj.put("subtune", songFile.getSubtune());
		obj.put("filePath", songFile.getFilePath().getPath());
		obj.put("zipFilePath", songFile.getZipFilePath().getPath());
		obj.put("title", songFile.getTitle());
		obj.put("composer", songFile.getComposer());
		obj.put("date", songFile.getDate());
		return obj;
	}

	private static SongFile deserialize(JSONObject obj) throws JSONException {
		return new SongFile(
				obj.getLong("id"),
				obj.getInt("subtune"),
				new File(obj.getString("fileName")),
				new File(obj.getString("zipFilePath")),
				obj.getString("title"),
				obj.getString("composer"),
				obj.getInt("date")
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

	public String getTitle() {
		return title;
	}

	public synchronized void clear() {
		songs.clear();
		flush();
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
}