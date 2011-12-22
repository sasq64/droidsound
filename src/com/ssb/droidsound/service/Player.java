package com.ssb.droidsound.service;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import android.content.Context;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.os.Handler;
import android.os.Message;

import com.ssb.droidsound.SongFile;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.ZipReader;

/*
 * The Player thread
 */
public class Player implements Runnable {
	private static final String TAG = "Player";

	public enum State {
		STOPPED, PAUSED, PLAYING, SWITCHING
	};

	public enum Command {
		NO_COMMAND,
		STOP, // Unload and stop if playing
		PLAY, // Play new file or last file
		PLAY_MULTIPLE,
		DUMP_WAV,
		// Only when Playing:
		PAUSE, UNPAUSE, SET_POS, SET_TUNE,
	};

	public static final int MSG_NEWSONG = 0;
	public static final int MSG_DONE = 2;
	public static final int MSG_STATE = 1;
	public static final int MSG_PROGRESS = 3;
	protected static final int MSG_SILENT = 4;
	public static final int MSG_SUBTUNE = 5;
	public static final int MSG_DETAILS = 6;
	public static final int MSG_INFO = 7;
	protected static final int MSG_WAVDUMPED = 8;

	// public static final int MSG_SUBTUNE = 5;

	public static class SongInfo {
		String title;
		String author;
		String copyright;
		String type;
		boolean canSeek;
		// String game;
		int length;
		int subTunes;
		int startTune;
		public String[] details;
		public String subtuneTitle;
		public String subtuneAuthor;
		public String fileName;
		public String source;
	};

	private final Handler mHandler;

	// Audio data
	private short[] samples;
	private AudioTrack audioTrack;
	private int bufSize;

	// Plugins
	private DroidSoundPlugin currentPlugin;
	private final List<DroidSoundPlugin> plugins;

	// Incoming state
	private final Object cmdLock = new Object();
	private Command command = Command.NO_COMMAND;
	private Object argument;

	// Player state
	// private int currentPosition;
	private int noPlayWait;
	private int lastPos;
	private int playPosOffset;
	private final SongInfo currentSong = new SongInfo();

	// private Object songRef;

	private volatile State currentState = State.STOPPED;
	private int silentPosition;

	int FREQ = 44100;
	private boolean songEnded = false;

	public Player(AudioManager am, Handler handler, Context ctx) {
		mHandler = handler;

		plugins = DroidSoundPlugin.getPluginList();

		silentPosition = -1;
		// Enough for 3000ms
		bufSize = 0x40000;

		samples = new short[bufSize / 2];
	}

	private File writeFile(String name, InputStream fs, boolean temp) throws IOException {
		File file;
		if(temp) {

			name = name.substring(name.lastIndexOf('/') + 1);

			int dot = name.indexOf('.');
			int lastDot = name.lastIndexOf('.');

			if(dot == -1) {
				file = File.createTempFile(name, "");
			} else {
				file = File.createTempFile(name.substring(0, dot + 1), name.substring(lastDot));
			}
		} else {
			file = new File(name);
		}

		FileOutputStream fo = new FileOutputStream(file);
		byte[] buffer = new byte[16384];

		while(true) {
			int rc = fs.read(buffer);
			if(rc <= 0) {
				break;
			}
			fo.write(buffer, 0, rc);
		}
		fo.close();
		return file;
	}

	public static String makeSize(long fileSize) {
		String s;
		if(fileSize < 10 * 1024) {
			s = String.format("%1.1fKB", fileSize / 1024F);
		} else if(fileSize < 1024 * 1024) {
			s = String.format("%dKB", fileSize / 1024);
		} else if(fileSize < 10 * 1024 * 1024) {
			s = String.format("%1.1fMB", fileSize / (1024F * 1024F));
		} else {
			s = String.format("%dMB", fileSize / (1024 * 1024));
		}
		return s;
	}

	private void startSong(SongFile song, SongFile song2) {
		startSong(song, false);
	}

	private void dumpWav(SongFile song, File outFile, int length, int flags) throws IOException {

		Log.d(TAG, "IN DUMP WAV");

		startSong(song, true);

		audioTrack.stop();
		audioTrack.flush();

		byte [] bbuffer = new byte [bufSize];

		//FileOutputStream fos = new FileOutputStream(outFile);
		//BufferedOutputStream bos = new BufferedOutputStream(fos, bufSize);


		int numSamples = (int)(((long)length * FREQ) / 1000);

		int numChannels = 1;
		int divider = 2;


		if((flags & 2) != 0) {
			Log.d(TAG, "HIGH QUALITY!");
			numChannels = 2;
			divider = 1;
		}

		int wavSamples = numSamples / divider;

		// the /2 halves the frequency

		int freq = FREQ/divider;

		// Size in bytes of wavdata
		int dataSize = wavSamples * numChannels * 16/8;

		Log.d(TAG, "%dsec => %d samples, %d wavSamples, %d dataSize", length/1000, numSamples, wavSamples, dataSize);


		byte [] barray = new byte [128];
		ByteBuffer bb = ByteBuffer.wrap(barray);
		bb.order(ByteOrder.LITTLE_ENDIAN);
		bb.put(new byte[] { 'R', 'I', 'F', 'F' });
		bb.putInt(36 + dataSize);
		bb.put(new byte[] { 'W', 'A', 'V', 'E' });
		bb.put(new byte[] { 'f', 'm', 't', ' ' });
		bb.putInt(16);
		bb.putShort((short) 1);
		bb.putShort((short) numChannels);
		bb.putInt(freq);
		bb.putInt(freq * numChannels * 16/8);
		bb.putShort((short) (numChannels * 16/8));
		bb.putShort((short) 16);

		bb.put(new byte[] { 'd', 'a', 't', 'a' });
		bb.putInt(dataSize);

		//bos.write(barray, 0, bb.position());

		RandomAccessFile raf = new RandomAccessFile(outFile, "rw");
		raf.write(barray, 0, bb.position());

		int sampleCount = 0;
		int bytesWritten = 0;
		while(sampleCount < numSamples) {
			// In and out are number of shorts, not number of samples (2 bytes vs 4 bytes in 16bit stereo)
			int len = currentPlugin.getSoundData(samples, bufSize / 16);
			Log.d(TAG, "READ %d (%d)", len, bufSize);
			if(len < 0) {
				wavSamples = sampleCount / divider;
				dataSize = wavSamples * numChannels * 16/8;

				Log.d(TAG, "Early end, new datasize is %d", dataSize);

				bb.putInt(4, dataSize + 36);
				bb.putInt(40, dataSize);
				raf.seek(0);
				raf.write(barray, 0, bb.position());
				break;
			}

			len /= 2; // len now samples, not shorts

			if(sampleCount + len > numSamples)
				len = numSamples - sampleCount;

			sampleCount += len;

			Log.d(TAG, "%d vs %d frames", numSamples, sampleCount);

			int j = 0;
			int i = 0;
			int volume = 100;
			// Now we iterate over sample values which are twice as many
			while(i < len*2) {

				if((flags & 2) != 0) {
					bbuffer[j++] = (byte) (samples[i]&0xff);
					bbuffer[j++] = (byte) ((samples[i]>>8)&0xff);
					i += 1;
				} else {
					int avg = (samples[i] + samples[i+1] + samples[i+2] + samples[i+3]);
					short savg = (short) (avg * volume / 400);
					i += 4;
					bbuffer[j++] = (byte) (savg&0xff);
					bbuffer[j++] = (byte) ((savg>>8)&0xff);
				}
			}
			raf.write(bbuffer, 0, j);
			bytesWritten += j;
		}
		//bos.flush();
		//bos.close();
		raf.close();

		Log.d(TAG, "Wrote %d samples in %d bytes", numSamples, bytesWritten);

		audioTrack.release();
		audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ,
				AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize,
				AudioTrack.MODE_STREAM);
		samples = new short[bufSize / 2];

		currentPlugin.unload();
		currentPlugin = null;
		currentState = State.STOPPED;

		Message msg = mHandler.obtainMessage(MSG_WAVDUMPED, 0, 0, outFile.getPath());
		mHandler.sendMessage(msg);
	}


	private void startSong(SongFile song, boolean skipStart) {
		if(currentPlugin != null) {
			currentPlugin.unload();
		}
		currentPlugin = null;
		playPosOffset = 0;
		songEnded = false;

		boolean flush = true; // (currentState != State.SWITCHING);

		currentState = State.SWITCHING;

		// SongFile sf = new SongFile(songName);

		List<DroidSoundPlugin> list = new ArrayList<DroidSoundPlugin>();

		for(DroidSoundPlugin plugin : plugins) {
			if(plugin.canHandle(song.getName())) {
				list.add(plugin);
				Log.d(TAG, "%s handled by %s", song.getName(), plugin.getClass().getSimpleName());
			}
		}

		byte[] songBuffer = null;
		long fileSize = 0;
		long fileSize2 = 0;

		File songFile = null;
		File songFile2 = null;

		String baseName = song.getName();

		try {

			if(song.getZipPath() != null) {
				String name = song.getZipName();

				ZipFile zr = ZipReader.openZip(new File(song.getZipPath()));
				ZipEntry ze = zr.getEntry(name);

				String name2 = DroidSoundPlugin.getSecondaryFile(name);
				if (name2 != null) {
					InputStream is = zr.getInputStream(ze);
					songFile = writeFile(name, is, true);
					is.close();
					fileSize = songFile.length();

					ZipEntry ze2 = zr.getEntry(name2);
					if (ze2 != null) {
						InputStream is2 = zr.getInputStream(ze2);
						songFile2 = writeFile(name2, is2, false);
						is2.close();
						fileSize2 = songFile2.length();
					}
				} else {
					DataInputStream dis = new DataInputStream(zr.getInputStream(ze));
					fileSize = ze.getSize();
					songBuffer = new byte[(int) fileSize];
					dis.readFully(songBuffer);
					dis.close();
				}

				zr.close();
			} else {
				songFile = song.getFile();
				fileSize = songFile.length();

				if(!songFile.exists()) {
					songFile = null;
				} else {
					String fname2 = DroidSoundPlugin.getSecondaryFile(songFile.getPath());
					if(fname2 != null) {
						File f2 = new File(fname2);
						if(f2.exists()) {
							fileSize2 = f2.length();
						}
					}
				}
			}

		} catch (IOException e) {
			Log.w(TAG, "Could not load music!");
			e.printStackTrace();
		}

		if(songBuffer != null || songFile != null) {
			boolean songLoaded = false;
			for (DroidSoundPlugin plugin : list) {
				if (songFile != null) {
					try {
						songLoaded = plugin.load(songFile);
					} catch (IOException e) {
					}
				} else if (songBuffer != null) {
					songLoaded = plugin.load(baseName, songBuffer);
				}
				if(songLoaded) {
					currentPlugin = plugin;
					break;
				}
			}

			if(currentPlugin == null) {
				for(DroidSoundPlugin plugin : plugins) {
					if(!plugin.canHandle(song.getName())) {
						if (songFile != null) {
							try {
								songLoaded = plugin.load(songFile);
							} catch (IOException e) {
							}
						} else if(songBuffer != null) {
							songLoaded = plugin.load(baseName, songBuffer);
						}
						Log.d(TAG, "%s gave Songref %s", plugin.getClass().getName(), songLoaded ? "TRUE" : "FALSE");
						if(songLoaded) {
							currentPlugin = plugin;
							break;
						}
					}
				}
			}
		}

		if(currentPlugin != null) {
			Log.d(TAG, "HERE WE GO:" + currentPlugin.getClass().getName());

			Log.d(TAG, "'%s' by '%s'", song.getTitle(), song.getComposer());


			synchronized (this) {
				currentSong.fileName = song.getPath(); // songName;


				if(song.getTitle() != null) {
					currentSong.title = song.getTitle();
				} else {
					currentSong.title = getPluginInfo(DroidSoundPlugin.INFO_TITLE);
				}

				if(song.getComposer() != null) {
					currentSong.author = song.getComposer();
				} else {
					currentSong.author = getPluginInfo(DroidSoundPlugin.INFO_AUTHOR);
				}

				currentSong.copyright = getPluginInfo(DroidSoundPlugin.INFO_COPYRIGHT);
				currentSong.type = getPluginInfo(DroidSoundPlugin.INFO_TYPE);
				// currentSong.game = getPluginInfo(DroidSoundPlugin.INFO_GAME);
				currentSong.subTunes = currentPlugin.getIntInfo(DroidSoundPlugin.INFO_SUBTUNE_COUNT);
				currentSong.startTune = currentPlugin.getIntInfo(DroidSoundPlugin.INFO_STARTTUNE);
				String[] info = currentPlugin.getDetailedInfo();
				if(info == null) {
					info = new String[0];
				}

				currentSong.canSeek = currentPlugin.canSeek();

				currentSong.details = new String[info.length + 2];
				for(int i = 0; i < info.length; i++) {
					currentSong.details[i] = info[i];
				}
				currentSong.details[info.length] = "Size";

				String size = makeSize(fileSize);
				if(fileSize2 > 0) {
					size = size + " + " + makeSize(fileSize2);
				}
				currentSong.details[info.length + 1] = size;
				info = null;

				currentSong.length = currentPlugin.getIntInfo(DroidSoundPlugin.INFO_LENGTH);

				if (currentSong.title == null || currentSong.title.equals("")) {
					String basename = currentPlugin.getBaseName(currentSong.fileName);
					int sep = basename.indexOf(" - ");
					if(sep > 0) {
						currentSong.author = basename.substring(0, sep);
						currentSong.title = basename.substring(sep+3);
					} else
						currentSong.title = basename;
					Log.d(TAG, "FN Title '%s'", currentSong.title);
				}

				currentSong.subtuneTitle = getPluginInfo(DroidSoundPlugin.INFO_SUBTUNE_TITLE);
				currentSong.subtuneAuthor = getPluginInfo(DroidSoundPlugin.INFO_SUBTUNE_AUTHOR);

				if(currentSong.subTunes == -1)
					currentSong.subTunes = 0;
			}

			if(song.getSubtune() >= 0) {
				currentSong.startTune = song.getSubtune();
				currentSong.subTunes = 0;
				currentPlugin.setTune(song.getSubtune());
				currentSong.length = currentPlugin.getIntInfo(DroidSoundPlugin.INFO_LENGTH);
				currentSong.subtuneTitle = getPluginInfo(DroidSoundPlugin.INFO_SUBTUNE_TITLE);
				currentSong.subtuneAuthor = getPluginInfo(DroidSoundPlugin.INFO_SUBTUNE_AUTHOR);
			}

			currentSong.source = "";

			if (!skipStart) {

				Log.d(TAG, ":%s:%s:%s:%s:", currentSong.title, currentSong.author, currentSong.copyright, currentSong.type);

				Message msg = mHandler.obtainMessage(MSG_NEWSONG);
				mHandler.sendMessage(msg);

				if (flush) {
					audioTrack.stop();
					audioTrack.flush();
					try {
						Thread.sleep(100);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}

					Log.d(TAG, "START, pos " + audioTrack.getPlaybackHeadPosition());
				}

				audioTrack.release();
				audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ, AudioFormat.CHANNEL_CONFIGURATION_STEREO,
						AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);
				samples = new short[bufSize / 2];

				audioTrack.play();
				currentState = State.PLAYING;
				// currentPosition = 0;
			}

			lastPos = -1000;
			if(songFile2 != null) {
				Log.d(TAG, "Deleting temporary files %s and %s", songFile.getPath(), songFile2.getPath());

				if(songFile2 != songFile)
					songFile2.delete();
				songFile.delete();
				songFile2 = null;
			}
			return;
		}
		currentState = State.STOPPED;
	}

	private String getPluginInfo(int info) {
		String s = currentPlugin.getStringInfo(info);
		if(s == null) {
			s = "";
		}
		return s;
	}

	@Override
	public void run() {

		currentPlugin = null;

		audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ, AudioFormat.CHANNEL_CONFIGURATION_STEREO,
				AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);

		Log.d(TAG, "AudioTrack created in thread " + Thread.currentThread().getId());
		noPlayWait = 0;
		int pos = 0;
		while(noPlayWait < 50) {
			try {
				if(command != Command.NO_COMMAND) {

					Log.d(TAG, "Command %s while in state %s", command.toString(), currentState.toString());

					synchronized (cmdLock) {
						switch(command) {
						case PLAY_MULTIPLE:
							SongFile [] songs = (SongFile[]) argument;
							Log.d(TAG, "Playmod " + songs[0].getName());
							startSong(songs[0], songs[1]);
							break;
						case PLAY:
							SongFile song = (SongFile) argument;
							Log.d(TAG, "Playmod " + song.getName());
							startSong(song, false);
							break;
						case DUMP_WAV:
							Object [] args = (Object []) argument;
							SongFile song2 = (SongFile) args[0];
							File outFile = (File) args[1];
							int len = (Integer) args[2];
							int flags = (Integer) args[3];
							Log.d(TAG, "DUMP WAV " + song2.getName());
							try {
								dumpWav(song2, outFile, len, flags);
							} catch (IOException e1) {
								e1.printStackTrace();
							}
							break;
						case STOP:
							if(currentState != State.STOPPED) {
								// audioTrack.pause();
								Log.d(TAG, "STOP");

								audioTrack.stop();
								audioTrack.flush();
								audioTrack.release();
								audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ,
										AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize,
										AudioTrack.MODE_STREAM);
								samples = new short[bufSize / 2];

								currentPlugin.unload();
								currentPlugin = null;
								currentState = State.STOPPED;
								Message msg = mHandler.obtainMessage(MSG_STATE, 0, 0);
								mHandler.sendMessage(msg);
							}
							break;
						}
						if(currentState != State.STOPPED) {
							switch(command) {
							case SET_POS:
								int msec = (Integer) argument;
								if(currentState == State.SWITCHING) {
									currentState = State.PLAYING;
								}
								if(currentPlugin.seekTo(msec)) {

									//
									int playPos = audioTrack.getPlaybackHeadPosition() * 10 / (FREQ / 100);
									Log.d(TAG, "Offset %d/1000 - %d", msec, playPos);
									playPosOffset = msec - playPos;

									// currentPosition = msec;
									// lastPos = -1000;
								}
								break;

							case SET_TUNE:
								Log.d(TAG, "Setting tune");
								if (currentPlugin.setTune((Integer) argument)) {
									playPosOffset = 0;
									lastPos = -1000;
									audioTrack.pause();
									audioTrack.flush();

									audioTrack.release();
									audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ,
											AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize,
											AudioTrack.MODE_STREAM);
									samples = new short[bufSize / 2];

									if (currentState == State.SWITCHING) {
										currentState = State.PLAYING;
									}

									currentSong.length = currentPlugin.getIntInfo(DroidSoundPlugin.INFO_LENGTH);
									currentSong.subtuneTitle = currentPlugin.getStringInfo(DroidSoundPlugin.INFO_SUBTUNE_TITLE);
									currentSong.subtuneAuthor = getPluginInfo(DroidSoundPlugin.INFO_SUBTUNE_AUTHOR);
									Message msg = mHandler.obtainMessage(MSG_SUBTUNE, (Integer) argument, currentSong.length, new String[] {
											currentSong.subtuneTitle, currentSong.subtuneAuthor });
									mHandler.sendMessage(msg);
									audioTrack.play();
								}
								break;
							case PAUSE:
								if(currentState == State.PLAYING) {
									currentState = State.PAUSED;
									Message msg = mHandler.obtainMessage(MSG_STATE, 2, 0);
									mHandler.sendMessage(msg);
									audioTrack.pause();
								}

								break;
							case UNPAUSE:
								if(currentState == State.PAUSED) {
									currentState = State.PLAYING;
									Message msg = mHandler.obtainMessage(MSG_STATE, 1, 0);
									mHandler.sendMessage(msg);
									audioTrack.play();
								}

								break;
							}
						}
						command = Command.NO_COMMAND;
					}
				}

				/*
				 * Always feed track - play zeroes after song ends Report song
				 * end at correct time
				 */

				if(currentState == State.PLAYING) {
					int len = 0;
					if (!songEnded) {
						len = currentPlugin.getSoundData(samples, bufSize / 16);
					} else {
						Thread.sleep(100);
					}

					int p = audioTrack.getPlaybackHeadPosition();

					if (songEnded && p == pos) {
						currentState = State.SWITCHING;
						Message msg = mHandler.obtainMessage(MSG_DONE);
						mHandler.sendMessage(msg);
					}

					pos = p;
					int playPos = pos * 10 / (FREQ / 100);

					if(pos >= lastPos + FREQ / 2) {
						Message msg = mHandler.obtainMessage(MSG_PROGRESS, playPos + playPosOffset, -1);
						mHandler.sendMessage(msg);
						lastPos = pos;

						if(currentPlugin.isSilent()) {
							if (silentPosition < 0) {
								silentPosition = pos;
							} else if (pos > silentPosition + 2500) {
								msg = mHandler.obtainMessage(MSG_SILENT);
								mHandler.sendMessage(msg);
								Log.d(TAG, "Silence");
								silentPosition = -1;
							}
						} else {
							silentPosition = -1;
						}

					}

					if (len < 0) {
						if(playPos > 5000) {
							songEnded = true;
						}
						len = bufSize / 16;
						Arrays.fill(samples, 0, len, (short) 0);
					}
					if(len > 0) {
						audioTrack.write(samples, 0, len);
					}

					// Log.d(TAG, "loop");
					noPlayWait = 0;
				} else {
					if (currentState == State.STOPPED) {
						noPlayWait++;
					}
					Thread.sleep(100);
				}

			} catch (InterruptedException e) {
				break;
			}
		}

		audioTrack.release();
		audioTrack = null;
	}

	synchronized int getPosition() {
		return audioTrack.getPlaybackHeadPosition();
	}

	synchronized public boolean getSongInfo(SongInfo target) {
		target.title = currentSong.title == null ? null : new String(currentSong.title);
		target.author = currentSong.author == null ? null : new String(currentSong.author);
		target.copyright = currentSong.copyright == null ? null : new String(currentSong.copyright);
		// target.game = new String(currentSong.game);
		target.type = currentSong.type == null ? null : new String(currentSong.type);
		target.length = currentSong.length;
		target.subTunes = currentSong.subTunes;
		target.startTune = currentSong.startTune;
		target.details = currentSong.details;
		target.subtuneTitle = currentSong.subtuneTitle;
		target.subtuneAuthor = currentSong.subtuneAuthor;
		target.fileName = currentSong.fileName;
		target.canSeek = currentSong.canSeek;
		target.source = currentSong.source;
		return true;
	}

	public void stop() {
		synchronized (cmdLock) {
			command = Command.STOP;
		}
	}

	public void paused(boolean pause) {
		synchronized (cmdLock) {
			if(pause) {
				command = Command.PAUSE;
			} else {
				command = Command.UNPAUSE;
			}
		}
	}

	public void seekTo(int pos) {
		synchronized (cmdLock) {
			command = Command.SET_POS;
			argument = pos;
		}
	}

	public void playMod(SongFile mod) {
		synchronized (cmdLock) {
			command = Command.PLAY;
			argument = mod;
		}
	}
	public void playMod(SongFile mod, SongFile nextMod) {
		synchronized (cmdLock) {
			command = Command.PLAY_MULTIPLE;
			argument = new SongFile[] { mod, nextMod };
		}
	}

	public void setSubSong(int song) {
		synchronized (cmdLock) {
			command = Command.SET_TUNE;
			argument = song;
		}
	}

	public boolean isActive() {
		return currentState != State.STOPPED;
	}

	public boolean isPlaying() {
		return (currentState == State.PLAYING);
	}

	public boolean isSwitching() {
		return (currentState == State.SWITCHING);
	}

	public void setBufSize(int bs) {
		synchronized (cmdLock) {
			bufSize = bs;
		}
	}

	public void dumpWav(SongFile song, String destFile, int length, int flags) {
		synchronized (cmdLock) {
			command = Command.DUMP_WAV;
			argument = new Object [] {song, new File(destFile), length, flags};
		}

	}

}
