package com.ssb.droidsound.bo;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

/**
 * Represents snapshots of database entries.
 * ID is not provided because it is not reliable (could change from scan to scan).
 *
 * @author alankila
 */
public class Playlist {
	private static final Charset UTF8 = Charset.forName("UTF-8");

	private final long id;
	private final File file;
	private final List<FilesEntry> songs;

	private String title;

	public Playlist(long id, File file) {
		this.id = id;
		this.file = file;

		title = file.getName();
		int dot = title.lastIndexOf('.');
		if(dot > 0) {
			title = title.substring(0, dot);
		}

		songs = new ArrayList<FilesEntry>();
		try {
			byte[] data = new byte[(int) file.length()];
			if (data.length != 0) {
				DataInputStream dis = new DataInputStream(new FileInputStream(file));
				dis.readFully(data);
				dis.close();

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

	public void persist() {
		try {
			FileOutputStream fos = new FileOutputStream(file);
			JSONArray arr = new JSONArray();
			for (FilesEntry s : songs) {
				JSONObject obj = serialize(s);
				arr.put(obj);
			}
			fos.write(arr.toString().getBytes(UTF8));
			fos.close();
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}

	private static JSONObject serialize(FilesEntry songFile) throws JSONException {
		File zipFilePath = songFile.getZipFilePath();
		JSONObject obj = new JSONObject();
		obj.put("filePath", songFile.getFilePath().getPath());
		obj.put("zipFilePath", zipFilePath != null ? zipFilePath.getPath() : null);
		obj.put("format", songFile.getFormat());
		obj.put("title", songFile.getTitle());
		obj.put("composer", songFile.getComposer());
		obj.put("date", songFile.getDate());
		return obj;
	}

	private static FilesEntry deserialize(JSONObject obj) throws JSONException {
		return new FilesEntry(
				obj.getInt("subtune"),
				new File(obj.getString("filePath")),
				obj.has("zipFilePath") ? new File(obj.getString("zipFilePath")) : null,
				obj.has("format") ? obj.getString("format") : null,
				obj.has("title") ? obj.getString("title") : null,
				obj.has("composer") ? obj.getString("composer") : null,
				obj.getInt("date")
		);
	}

	public long getId() {
		return id;
	}

	public String getTitle() {
		return title;
	}

	public List<FilesEntry> getSongs() {
		return songs;
	}
}