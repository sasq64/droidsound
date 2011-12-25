package com.ssb.droidsound.bo;

import java.io.File;
import java.util.HashMap;
import java.util.Map;

import com.ssb.droidsound.utils.Log;

/**
 * This container represents a playable file.
 *
 * @author alankila
 */
public class SongFile {
	private static final String TAG = SongFile.class.getSimpleName();
	private static final Map<String, String> MAIN_TO_AUX = new HashMap<String, String>();
	static {
		MAIN_TO_AUX.put("MDAT", "SMPL");
		MAIN_TO_AUX.put("TFX", "SAM");
		MAIN_TO_AUX.put("SNG", "INS");
		MAIN_TO_AUX.put("RJP", "SMP");
		MAIN_TO_AUX.put("JPN", "SMP");
		MAIN_TO_AUX.put("DUM", "INS");
	}

	private final int subtune;
	private final int playtime;
	private final String fileName;

	private final String zipPath;
	private final String zipName;

	private final String title;
	private final String composer;

	public static SongFile fromFileName(String fileName) {
		File f = new File(fileName);
		/* Check that file exists, and isn't inside an archive... */
		if (f.exists()) {
			return new SongFile(0, 0, fileName, null, null, f.getName(), null);
		} else {
			File parent = f;
			while (! parent.exists()) {
				parent = parent.getParentFile();
			}
			if (parent.exists()) {
				String parentPath = parent.getPath();
				String childPath = f.getPath().substring(parentPath.length() + 1);
				Log.i(TAG, "Archive decomposition for path %s => %s and %s", f.getPath(), parentPath, childPath);
				return new SongFile(0, 0, fileName, parentPath, childPath, f.getName(), null);
			} else {
				throw new IllegalArgumentException("The input file name could not be converted into something inside collection.");
			}
		}
	}

	public SongFile(SongFile s) {
		subtune = s.subtune;
		playtime = s.playtime;
		fileName = s.fileName;
		zipPath = s.zipPath;
		zipName = s.zipName;
		title = s.title;
		composer = s.composer;
	}

	public SongFile(int subtune, SongFile s) {
		this.subtune = subtune;
		playtime = s.playtime;
		fileName = s.fileName;
		zipPath = s.zipPath;
		zipName = s.zipName;
		title = s.title;
		composer = s.composer;
	}

	public SongFile(int subtune, int playtime, String fileName, String zipPath, String zipName, String title, String composer) {
		this.subtune = subtune;
		this.playtime = playtime;
		this.fileName = fileName;
		this.zipPath = zipPath;
		this.zipName = zipName;
		this.title = title;
		this.composer = composer;
	}

	public String getSecondaryFileName() {
		String path = zipName == null ? fileName : zipName;
		int dot = path.lastIndexOf('.');
		int slash = path.lastIndexOf('/');
		if (dot <= slash) {
			return null;
		}

		int firstDot = path.indexOf('.', slash+1);
		String ext = path.substring(dot+1).toUpperCase();
		String pref = path.substring(slash+1, firstDot).toUpperCase();

		if (MAIN_TO_AUX.containsKey(pref)) {
			return path.substring(0, slash+1) + MAIN_TO_AUX.get(pref) + path.substring(firstDot);
		} else if (MAIN_TO_AUX.containsKey(ext)) {
			return path.substring(0, dot+1) + MAIN_TO_AUX.get(ext);
		}

		return null;
	}


	public int getSubtune() {
		return subtune;
	}

	public int getPlaytime() {
		return playtime;
	}

	public String getFileName() {
		return fileName;
	}

	public String getZipPath() {
		return zipPath;
	}

	public String getZipName() {
		return zipName;
	}

	public String getTitle() {
		return title;
	}

	public String getComposer() {
		return composer;
	}
}
