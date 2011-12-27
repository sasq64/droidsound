package com.ssb.droidsound.bo;

import java.io.File;
import java.util.HashMap;
import java.util.Map;

/**
 * This container represents a playable file at specific subsong.
 *
 * @author alankila
 */
public class SongFile {
	private static final Map<String, String> MAIN_TO_AUX = new HashMap<String, String>();
	static {
		MAIN_TO_AUX.put("MDAT", "SMPL");
		MAIN_TO_AUX.put("TFX", "SAM");
		MAIN_TO_AUX.put("SNG", "INS");
		MAIN_TO_AUX.put("RJP", "SMP");
		MAIN_TO_AUX.put("JPN", "SMP");
		MAIN_TO_AUX.put("DUM", "INS");
	}

	private final long id;
	private final int subtune;
	private final String filePath;
	private final String zipFilePath;

	private final String title;
	private final String composer;
	private final int date;

	public SongFile sibling(long id, String name) {
		String siblingPath = new File(new File(filePath).getParentFile(), name).getPath();
		return new SongFile(id, subtune, siblingPath, zipFilePath, title, composer, date);
	}

	public SongFile(long id, int subtune, String fileName, String zipFilePath, String title, String composer, int date) {
		this.id = id;
		this.subtune = subtune;
		this.filePath = fileName;
		this.zipFilePath = zipFilePath;
		this.title = title;
		this.composer = composer;
		this.date = date;
	}

	public String getSecondaryFileName() {
		int dot = filePath.lastIndexOf('.');
		int slash = filePath.lastIndexOf('/');
		if (dot <= slash) {
			return null;
		}

		int firstDot = filePath.indexOf('.', slash+1);
		String ext = filePath.substring(dot+1).toUpperCase();
		String pref = filePath.substring(slash+1, firstDot).toUpperCase();

		if (MAIN_TO_AUX.containsKey(pref)) {
			return filePath.substring(0, slash+1) + MAIN_TO_AUX.get(pref) + filePath.substring(firstDot);
		} else if (MAIN_TO_AUX.containsKey(ext)) {
			return filePath.substring(0, dot+1) + MAIN_TO_AUX.get(ext);
		}

		return null;
	}


	public int getSubtune() {
		return subtune;
	}

	public String getFilePath() {
		return filePath;
	}

	public String getZipFilePath() {
		return zipFilePath;
	}

	public String getTitle() {
		return title;
	}

	public String getComposer() {
		return composer;
	}

	public int getDate() {
		return date;
	}

	public long getId() {
		return id;
	}
}
