package com.ssb.droidsound.plugins;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

import com.ssb.droidsound.utils.Log;


public class ModPlugin extends DroidSoundPlugin {
	private static final String TAG = ModPlugin.class.getSimpleName();
	static {
		System.loadLibrary("modplug");
	}
	private static final Set<String> extensions = new HashSet<String>(Arrays.asList(
			"XM", "S3M", "IT", "UMX", "ULT", "669", "STM"
	));

	long currentSong = 0;

	private String author;

	@Override
	public boolean canHandle(String name) {
		int x = name.lastIndexOf('.');
		if(x < 0) return false;
		String ext = name.substring(x+1).toUpperCase();
		return extensions.contains(ext);
	}

	@Override
	public boolean load(String name, byte[] module) {
		currentSong = N_load(module, module.length);
		if (currentSong != 0) {
			author = guessAuthor(N_getStringInfo(currentSong, 100));
		}
		return currentSong != 0;
	}

	private String guessAuthor(String instr) {
		String[] t = new String[256];
		String[] s = instr.split("\\n");

		int n = 0;

		for (int k = 0; k < s.length; k++) {
			String d[] = s[k].split("\\s+");

			for (int i=0; i<d.length; i++) {
				//Log.d(TAG, d[i]);

				if (n >= t.length - 6)
					break;

				String x = "";
				if(d[i].equals("/")) {
					//Log.d(TAG, "/BY/");
					x = "/";
				} else
				if(d[i].equals("&") || d[i].equals("&")) {
					x = "and";
				} else
				if(d[i].length() > 1) {

					if(d[i].endsWith("/")) {
						x = d[i].replaceAll("^[^\\w]*", "");
					} else if(d[i].startsWith("/")) {
						x = d[i].replaceAll("[^\\w]*$", "");
					} else {
						x = d[i].replaceAll("^[^\\w]*", "").replaceAll("[^\\w]*$", "");
					}
				}

				if(x.length() > 0) {

					int plus = x.indexOf('&');
					if(plus == -1) {
						plus = x.indexOf('+');
					}

					if(plus > 0) {
						t[n++] = x.substring(0, plus);
						t[n++] = "and";
						x = x.substring(plus+1);
					}

					int slash = x.indexOf('/');

					if(slash >= 0) {
						t[n++] = x.substring(0, slash);
						t[n++] = "/";
						x = x.substring(slash+1);
					}

					t[n++] = x;
				}
			}


			t[n++] = "EOL";

			if(n >= t.length - 5)
				break;

		}

		String author[] = new String[4];

		String lastWord = "";
		String lastLastWord = "";
		for (int i=0; i<n; i++) {
			if(t[i].length() > 0 && !t[i].equals("EOL")) {
				// Log.d(TAG, "'%s'", t[i]);

				if(t[i].toUpperCase().equals("PRO-WIZARD")) {
					break;
				}

				String nextWord = "EOL";
				int ii = i+1;
				while(ii < n && (nextWord.equals("EOL") || nextWord.length() == 0)) {
					nextWord = t[ii++].toUpperCase();
				}

				// Log.d(TAG, "NW:%s", nextWord);

				String a = t[i];
				if(lastWord.equals("BY")) {

					//if(nextWord.equals("AND") && i<n-2) {
					//	a += ("and" + t[i+2]);
					//}

					if(a.toUpperCase().equals("ME")) {
						break;
					}

					ii = i+1;
					while(!t[ii].equals("EOL")) {
						if(t[ii].toUpperCase().equals("OF") || t[ii].equals("/")) {
							break;
						}
						a += (" " + t[ii]);
						ii++;
					}

					/*
					if(nextWord.equals("OF") && i<n-2) {
						a += (" of " + t[i+2]);
						if(i<n-3 && t[i+2].toUpperCase().equals("THE")) {
							a += (" " + t[i+2]);
						}
					} */

					if(lastLastWord.equals("COMPOSED") || lastLastWord.equals("MADE")) {
						author[0] = a;
						break;
					}
					else
					if(lastLastWord.equals("RIPPED") || lastLastWord.equals("ORIGINAL")) {
					} else {
						if(author[1] == null) {
							author[1] = a;
						}
					}
				} else if(nextWord.equals("/") || nextWord.equals("OF")) {

					//int x = 2;
					//if(nextWord.equals("of")) {
					//	x = 3;
					//}
					//Log.d(TAG, "OF AUTHOR '%s'", a);

					if(author[2] == null) {

						if(lastWord.equals("AND")) {
							if(t[i-2].length() > 0) {
								a = t[i-2] + " and " + a;
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
		for(int i=0; i<4; i++) {
			if(author[i] != null) {
				//a = author[i].replace("/", " of ");
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
		N_unload(currentSong);
		currentSong = 0;
	}

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	@Override
	public int getSoundData(short [] dest, int size) { return N_getSoundData(currentSong, dest, size); }
	@Override
	public boolean seekTo(int seconds) { return N_seekTo(currentSong, seconds); }
	@Override
	public boolean setTune(int tune) { return false; }
	@Override
	public String getStringInfo(int what) {

		if(what == INFO_AUTHOR) {
			return author;
		}
		return N_getStringInfo(currentSong, what);
	}
	@Override
	public int getIntInfo(int what) { return N_getIntInfo(currentSong, what); }

	public boolean loadInfo(byte[] songBuffer) {
		long song = N_load(songBuffer, songBuffer.length);
		if (song == 0)
			return false;
		else {
			author = guessAuthor(N_getStringInfo(song, 100));
			return true;
		}
	}

	@Override
	public boolean canSeek() {
		return true;
	}

	@Override
	public String[] getDetailedInfo() {
		String instruments = N_getStringInfo(currentSong, 100);
		String fmt = N_getStringInfo(currentSong, INFO_TYPE);
		//Log.d(TAG, "INSTRUMENTS: " + instruments);
		int channels = N_getIntInfo(currentSong, 101);

		String[] info;
		if(instruments != null && instruments.length() > 0) {
			info = new String [6];
			info[4] = "Instruments";
			info[5] = instruments;
		} else {
			info = new String [4];
		}
		info[0] = "Format";
		info[1] = "MODPlug: " + fmt;
		info[2] = "Channels";
		info[3] = Integer.toString(channels);
		return info;
	}

	@Override
	public void setOption(String string, Object val) {
		/* No options */
	}

	@Override
	public String getVersion() {
		return "libmodplug v0.8.?";
	}

	native private long N_load(byte [] module, int size);
	native private long N_loadInfo(byte [] module, int size);
	native private void N_unload(long song);

	// Expects Stereo, 44.1Khz, signed, big-endian shorts
	native private int N_getSoundData(long song, short [] dest, int size);
	native private boolean N_seekTo(long song, int seconds);
	native private boolean N_setTune(long song, int tune);
	native private String N_getStringInfo(long song, int what);
	native private int N_getIntInfo(long song, int what);
}
