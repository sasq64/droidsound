package com.ssb.droidsound.bo;

import java.io.File;
import java.util.HashMap;
import java.util.Map;

/**
 * This container represents a playable file at specific subsong
 * setting.
 *
 * @author alankila
 */
public class FilesEntry {
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
	private final File filePath;
	private final File zipFilePath;

	private final String format;
	private final String title;
	private final String composer;
	private final int date;

	public FilesEntry(long id, File fileName, File zipFilePath, String format, String title, String composer, int date) {
		this.id = id;
		this.filePath = fileName;
		this.zipFilePath = zipFilePath;
		this.format = format;
		this.title = title;
		this.composer = composer;
		this.date = date;
	}

	public File getSecondaryFileName() {
		String name = filePath.getName();

		int lastDot = name.lastIndexOf('.');
		String ext = name.substring(lastDot + 1).toUpperCase();
		if (MAIN_TO_AUX.containsKey(ext)) {
			return new File(filePath.getParentFile(), name.substring(lastDot + 1) + MAIN_TO_AUX.get(ext));
		}

		int firstDot = name.indexOf('.');
		String pref = name.substring(0, firstDot).toUpperCase();
		if (MAIN_TO_AUX.containsKey(pref)) {
			return new File(filePath.getParentFile(), MAIN_TO_AUX.get(pref) + name.substring(firstDot));
		}

		return null;
	}

	public long getId() {
		return id;
	}

	public File getFilePath() {
		return filePath;
	}

	public File getZipFilePath() {
		return zipFilePath;
	}

	public String getFormat() {
		return format;
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

	@Override
	public int hashCode() {
		return filePath.hashCode();
	}

	@Override
	public boolean equals(Object other) {
		if (other instanceof FilesEntry) {
			return filePath.equals(((FilesEntry) other).filePath);
		}
		return super.equals(other);
	}
}
