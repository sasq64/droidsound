package com.ssb.droidsound.plugins;

import java.util.HashSet;
import java.util.Locale;
import java.util.Map;
import java.util.Set;

import com.ssb.droidsound.file.FileSource;
import com.ssb.droidsound.utils.Log;

public class ModPlugin extends DroidSoundPlugin {
	private static final String TAG = ModPlugin.class.getSimpleName();

	static {
		System.loadLibrary("modplug");
	}
	private Set<String> extensions;
	private String author;

	public ModPlugin() {
		extensions = new HashSet<String>();
		extensions.add("MOD");
		extensions.add("XM");
		extensions.add("S3M");
		extensions.add("IT");
		extensions.add("UMX");
		extensions.add("ULT");
		extensions.add("669");
		extensions.add("STM");
		extensions.add("FAR");
		extensions.add("OKT");
		extensions.add("MDL");
		extensions.add("DMF");
		extensions.add("MDL");
		extensions.add("MT2");
		extensions.add("PSM");
		extensions.add("AMF");
		extensions.add("AMS");
	}

	long currentSong = 0;
	private byte[] data;
	private int len;

	@Override
	public boolean canHandle(FileSource fs) {
		return extensions.contains(fs.getExt());
	}

	
	@Override
	public boolean restart() {
		
		if (currentSong != 0)
			N_unload(currentSong);
		currentSong = N_load(data, len);		
		return true;
	}
	
	@Override
	public boolean load(FileSource fs) {

		data = fs.getContents();
		len = (int) fs.getLength();

		currentSong = N_load(data, len);
		if (currentSong != 0) {
			author = guessAuthor(N_getStringInfo(currentSong, 100));
		}
		return (currentSong != 0);
	}

	static String t[] = new String[256];

	private String guessAuthor(String instr) {

		String s[] = instr.split("\\n");

		int n = 0;

		for (int k = 0; k < s.length; k++) {
			String d[] = s[k].split("\\s+");

			for (int i = 0; i < d.length; i++) {
				// Log.d(TAG, d[i]);

				if (n >= t.length - 6)
					break;

				String x = "";
				if (d[i].equals("/")) {
					// Log.d(TAG, "/BY/");
					x = "/";
				} else if (d[i].equals("&") || d[i].equals("&")) {
					x = "and";
				} else if (d[i].length() > 1) {

					if (d[i].endsWith("/")) {
						x = d[i].replaceAll("^[^\\w]*", "");
					} else if (d[i].startsWith("/")) {
						x = d[i].replaceAll("[^\\w]*$", "");
					} else {
						x = d[i].replaceAll("^[^\\w]*", "").replaceAll("[^\\w]*$", "");
					}
					// Log.d(TAG, "'%s' '%s'", t[i], x);
				}

				if (x.length() > 0) {

					int plus = x.indexOf('&');
					if (plus == -1) {
						plus = x.indexOf('+');
					}

					if (plus > 0) {
						t[n++] = x.substring(0, plus);
						t[n++] = "and";
						x = x.substring(plus + 1);
					}

					int slash = x.indexOf('/');

					if (slash >= 0) {
						t[n++] = x.substring(0, slash);
						t[n++] = "/";
						x = x.substring(slash + 1);
					}

					t[n++] = x;
				}
			}

			t[n++] = "EOL";

			if (n >= t.length - 5)
				break;

		}

		String author[] = new String[4];

		String lastWord = "";
		String lastLastWord = "";
		for (int i = 0; i < n; i++) {

			if (t[i].length() > 0 && !t[i].equals("EOL")) {
				// Log.d(TAG, "'%s'", t[i]);

				if (t[i].toUpperCase(Locale.ENGLISH).equals("PRO-WIZARD")) {
					break;
				}

				String nextWord = "EOL";
				int ii = i + 1;
				while (ii < n && (nextWord.equals("EOL") || nextWord.length() == 0)) {
					nextWord = t[ii++].toUpperCase(Locale.ENGLISH);
				}

				// Log.d(TAG, "NW:%s", nextWord);

				String a = t[i];
				if (lastWord.equals("BY")) {

					// if(nextWord.equals("AND") && i<n-2) {
					// a += ("and" + t[i+2]);
					// }

					if (a.toUpperCase(Locale.ENGLISH).equals("ME")) {
						break;
					}

					ii = i + 1;
					while (!t[ii].equals("EOL")) {
						if (t[ii].toUpperCase(Locale.ENGLISH).equals("OF") || t[ii].equals("/")) {
							break;
						}
						a += (" " + t[ii]);
						ii++;
					}

					/*
					 * if(nextWord.equals("OF") && i<n-2) { a += (" of " +
					 * t[i+2]); if(i<n-3 && t[i+2].toUpperCase().equals("THE"))
					 * { a += (" " + t[i+2]); } }
					 */

					if (lastLastWord.equals("COMPOSED") || lastLastWord.equals("MADE")) {
						author[0] = a;
						break;
					} else if (lastLastWord.equals("RIPPED") || lastLastWord.equals("ORIGINAL")) {
					} else {
						if (author[1] == null) {
							author[1] = a;
						}
					}
				} else if (nextWord.equals("/") || nextWord.equals("OF")) {

					// int x = 2;
					// if(nextWord.equals("of")) {
					// x = 3;
					// }
					// Log.d(TAG, "OF AUTHOR '%s'", a);

					if (author[2] == null) {

						if (lastWord.equals("AND")) {
							if (t[i - 2].length() > 0) {
								a = t[i - 2] + " and " + a;
							}
						}

						author[2] = a;
					}
				}

				lastLastWord = lastWord;
				lastWord = t[i].toUpperCase();
			} else {
				// Log.d(TAG, "(%s)", t[i]);
			}
		}
		String a = null;
		for (int i = 0; i < 4; i++) {
			if (author[i] != null) {
				// a = author[i].replace("/", " of ");
				a = author[i];
				Log.d(TAG, "AUTHOR '%s', %d", author[i], i);
				break;
			}
		}
		return a;

	}

	@Override
	public void unload() {
		author = null;
		if (currentSong != 0)
			N_unload(currentSong);
		currentSong = 0;
	}

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	@Override
	public int getSoundData(short[] dest, int size) {
		return N_getSoundData(currentSong, dest, size);
	}

	@Override
	public boolean seekTo(int seconds) {
		return N_seekTo(currentSong, seconds);
	}

	@Override
	public boolean setTune(int tune) {
		if (currentSong != 0)
			N_unload(currentSong);
		currentSong = N_load(data, len);
		return true;
	}

	@Override
	public String getStringInfo(int what) {

		if (what == INFO_AUTHOR) {
			return author;
		}
		if (currentSong == 0)
			return null;
		return N_getStringInfo(currentSong, what);
	}

	@Override
	public int getIntInfo(int what) {
		if (currentSong == 0)
			return -1;
		return N_getIntInfo(currentSong, what);
	}

	@Override
	public boolean loadInfo(FileSource fs) {

		return true; /*
					 * long song = N_load(fs.getContents(), (int)
					 * fs.getLength()); if(song == 0) return false; else {
					 * author = guessAuthor(N_getStringInfo(song, 100)); return
					 * true; }
					 */
	}

	@Override
	public boolean canSeek() {
		return true;
	}

	@Override
	public void setOption(String o, Object val) {
		if (o.equals("loop")) {
			N_setOption(0, (Integer) val);
		}
	}

	@Override
	public void getDetailedInfo(Map<String, Object> list) {

		if (currentSong == 0)
			return;

		String instruments = N_getStringInfo(currentSong, 100);
		String fmt = N_getStringInfo(currentSong, INFO_TYPE);
		int channels = N_getIntInfo(currentSong, 101);

		list.put("plugin", "MOD");
		list.put("is" + fmt, Boolean.TRUE);

		list.put("format", fmt);
		list.put("channels", channels);

		if (instruments != null && instruments.length() > 0) {
			String[] instrArray = instruments.split("\\n");
			list.put("instruments", instrArray);
		}
	}

	@Override
	public String getVersion() {
		return "libmodplug v0.8.8.4";
	}

	// --- Native functions

	// native public boolean N_canHandle(String name);
	native public long N_load(byte[] module, int size);

	native public long N_loadInfo(byte[] module, int size);

	native public void N_unload(long song);

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native public int N_getSoundData(long song, short[] dest, int size);

	native public boolean N_seekTo(long song, int seconds);

	native public boolean N_setTune(long song, int tune);

	native public String N_getStringInfo(long song, int what);

	native public int N_getIntInfo(long song, int what);

	native public void N_setOption(int opt, int val);

}
