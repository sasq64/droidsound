package com.ssb.droidsound.service;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLConnection;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.zip.ZipEntry;

import android.content.Context;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.media.MediaPlayer;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

import com.ssb.droidsound.SongFile;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.utils.CueFile;
import com.ssb.droidsound.utils.NativeZipFile;

/*
 * The Player thread 
 */
public class Player implements Runnable {
	private static final String TAG = "Player";

	public enum State {
		STOPPED, PAUSED, PLAYING, SWITCHING
	};

	public enum Command {
		NO_COMMAND, STOP, // Unload and stop if playing
		PLAY, // Play new file or last file

		// Only when Playing:
		PAUSE, UNPAUSE, SET_POS, SET_TUNE,
	};

	public static final int MSG_NEWSONG = 0;
	public static final int MSG_DONE = 2;
	public static final int MSG_STATE = 1;
	public static final int MSG_PROGRESS = 3;
	protected static final int MSG_SILENT = 4;
	public static final int MSG_SUBTUNE = 5;

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

	private Handler mHandler;

	// Audio data
	private short[] samples;
	private AudioTrack audioTrack;
	private int bufSize;

	// Plugins
	private DroidSoundPlugin currentPlugin;
	private List<DroidSoundPlugin> plugins;

	// Incoming state
	private Object cmdLock = new Object();
	private Command command = Command.NO_COMMAND;
	private Object argument;

	// Player state
	// private int currentPosition;
	private int noPlayWait;
	private int lastPos;
	private int playPosOffset;
	private SongInfo currentSong = new SongInfo();

	// private Object songRef;

	private int currentTune;
	
	private File currentZipFile;
	private NativeZipFile currentZip;

	private volatile State currentState = State.STOPPED;
	private int silentPosition;

	int FREQ = 44100;
	private long audioTime;
	private int aCount;
	private long lastTime = -1;
	private long frameTime;
	// private int switchPos = -1;
	private boolean songEnded = false;
	private boolean reinitAudio;
	private int queuedFrames;
	private boolean startedFromSub;

	public Player(AudioManager am, Handler handler, Context ctx) {
		mHandler = handler;

		plugins = DroidSoundPlugin.createPluginList();

		silentPosition = -1;
		// Enough for 3000ms
		bufSize = 0x40000;

		samples = new short[bufSize / 2];
	}

	private File writeFile(String name, InputStream fs, boolean temp)
			throws IOException {
		File file;
		if (temp) {

			name = name.substring(name.lastIndexOf('/') + 1);

			int dot = name.indexOf('.');
			int lastDot = name.lastIndexOf('.');

			if (dot == -1) {
				file = File.createTempFile(name, "");
			} else {
				file = File.createTempFile(name.substring(0, dot + 1),
						name.substring(lastDot));
			}
		} else {
			file = new File(name);
		}

		FileOutputStream fo = new FileOutputStream(file);
		byte[] buffer = new byte[16384];

		while (true) {
			int rc = fs.read(buffer);
			if (rc <= 0) {
				break;
			}
			fo.write(buffer, 0, rc);
		}
		fo.close();
		return file;
	}

	private static String makeSize(long fileSize) {
		String s;
		if (fileSize < 10 * 1024) {
			s = String.format("%1.1fKB", (float) fileSize / 1024F);
		} else if (fileSize < 1024 * 1024) {
			s = String.format("%dKB", fileSize / 1024);
		} else if (fileSize < 10 * 1024 * 1024) {
			s = String.format("%1.1fMB", (float) fileSize / (1024F * 1024F));
		} else {
			s = String.format("%dMB", fileSize / (1024 * 1024));
		}
		return s;
	}

	private void startSong(SongFile song) {

		if (currentPlugin != null) {
			currentPlugin.unload();
		}
		currentPlugin = null;
		playPosOffset = 0;
		songEnded = false;

		boolean flush = true; // (currentState != State.SWITCHING);

		currentState = State.SWITCHING;

		// SongFile sf = new SongFile(songName);

		List<DroidSoundPlugin> list = new ArrayList<DroidSoundPlugin>();

		for (DroidSoundPlugin plugin : plugins) {
			if (plugin.canHandle(song.getName())) {
				list.add(plugin);
				Log.v(TAG, String.format("%s handled by %s", song.getName(),
						plugin.getClass().getSimpleName()));
			}
		}

		byte[] songBuffer = null;
		long fileSize = 0;
		long fileSize2 = 0;

		File songFile = null;
		File songFile2 = null;

		String baseName = song.getName(); // songName.substring(songName.lastIndexOf('/')
											// + 1);

		try {
			// File f = new File(Environment.getExternalStorageDirectory()+"/" +
			// modName);

			// if(songName.startsWith("file://")) {
			// songName = songName.substring(7);
			// }

			// int zipExt = songName.toUpperCase().indexOf(".ZIP/");

			if (song.getZipPath() != null) {

				Log.v(TAG, "ZIP FILE");

				File f = new File(song.getZipPath()); // songName.substring(0,
														// zipExt + 5));

				if (currentZipFile != null && f.equals(currentZipFile)) {
				} else {
					if (currentZip != null) {
						currentZip.close();
					}
					currentZipFile = f;
					currentZip = new NativeZipFile(f);
				}

				String name = song.getZipName(); // songName.substring(zipExt+5);

				Log.v(TAG, String.format(
						"Trying to open '%s' in zipfile '%s'\n", name,
						f.getPath()));

				if (currentZip != null) {

					String name2 = DroidSoundPlugin.getSecondaryFile(name);

					if (name2 != null) {

						Log.v(TAG, String.format("Got secondary file '%s'\n",
								name2));

						ZipEntry entry = currentZip.getEntry(name);
						if (entry != null) {
							InputStream fs = currentZip.getInputStream(entry);
							songFile = writeFile(name, fs, true);

							Log.v(TAG,
									String.format("Wrote '%s'\n",
											songFile.getPath()));

							fileSize = songFile.length();
							fs.close();

							String fname2 = DroidSoundPlugin
									.getSecondaryFile(songFile.getPath());

							Log.v(TAG, String.format("Writing '%s'\n", fname2));

							entry = currentZip.getEntry(name2);

							if (entry != null && fname2 != null) {
								fs = currentZip.getInputStream(entry);
								songFile2 = writeFile(fname2, fs, false);
								fs.close();
								fileSize2 = songFile2.length();
							}
						}

					} else {

						Log.v(TAG, "ENTRY");
						ZipEntry entry = currentZip.getEntry(name);
						if (entry != null) {
							Log.v(TAG,
									String.format("Entry  '%s' %d\n",
											entry.getName(), entry.getSize()));
							InputStream fs = currentZip.getInputStream(entry);
							fileSize = entry.getSize();
							songBuffer = new byte[(int) fileSize];
							fs.read(songBuffer);
							fs.close();
						}
					}
				}
			} else if (song.getPath().startsWith("http://")) {

				String songName = song.getPath();
				URL url = new URL(songName);
				//if(songName.toUpperCase().endsWith(".MP3"))
				//	break;

				Log.v(TAG, "Opening URL " + songName);

				URLConnection conn = url.openConnection();
				if (!(conn instanceof HttpURLConnection))
					throw new IOException("Not a HTTP connection");

				HttpURLConnection httpConn = (HttpURLConnection) conn;
				httpConn.setAllowUserInteraction(false);
				httpConn.setInstanceFollowRedirects(true);
				httpConn.setRequestMethod("GET");

				Log.v(TAG, "Connecting");

				httpConn.connect();

				int response = httpConn.getResponseCode();
				if (response == HttpURLConnection.HTTP_OK) {
					int size;
					byte[] buffer = new byte[16384];
					Log.v(TAG, "HTTP connected");
					InputStream in = httpConn.getInputStream();
					
					int dot = songName.lastIndexOf('.');
					String ext = null;
					if(dot > 0)
						ext = songName.substring(dot);					
					File f = File.createTempFile("music", ext);
					FileOutputStream fos = new FileOutputStream(f);
					BufferedOutputStream bos = new BufferedOutputStream(fos,
							buffer.length);
					while ((size = in.read(buffer)) != -1) {
						bos.write(buffer, 0, size);
					}
					bos.flush();
					bos.close();

					fileSize = f.length();

					Log.v(TAG, "Bytes written: " + fileSize);

					songBuffer = new byte[(int) fileSize];
					FileInputStream fs = new FileInputStream(f);
					fs.read(songBuffer);
					fs.close();
					//f.delete();
					songFile = f;
					songFile2 = f;
				} else {
					Log.v(TAG, String.format("Connection failed: %d", response));
				}
			} else {
				songFile = song.getFile(); // new File(songName);

				Log.v(TAG, "Trying to read normal file " + songFile.getPath());

				fileSize = songFile.length();
				System.gc();

				if (!songFile.exists())
					songFile = null;
				else {

					String fname2 = DroidSoundPlugin.getSecondaryFile(songFile
							.getPath());
					if (fname2 != null) {
						File f2 = new File(fname2);
						if (f2.exists()) {
							fileSize2 = f2.length();
						}
					}
				}

				// songBuffer = new byte [(int) fileSize];
				// FileInputStream fs = new FileInputStream(f);
				// fs.read(songBuffer);
				// fs.close();
			}

		} catch (IOException e) {
			Log.w(TAG, "Could not load music!");
			e.printStackTrace();
		}

		if (songBuffer != null || songFile != null) {
			boolean songLoaded = false;
			for (DroidSoundPlugin plugin : list) {
				Log.v(TAG, "Trying " + plugin.getClass().getName());
				if (songFile != null) {
					try {
						songLoaded = plugin.load(songFile);
					} catch (IOException e) {
					}
				} else {
					songLoaded = plugin.load(baseName, songBuffer,
							(int) fileSize);
				}
				if (songLoaded) {
					currentPlugin = plugin;
					break;
				}
			}

			if (currentPlugin == null) {
				for (DroidSoundPlugin plugin : plugins) {
					if (!plugin.canHandle(song.getName())) {
						if (songFile != null) {
							try {
								songLoaded = plugin.load(songFile);
							} catch (IOException e) {
							}
						} else {
							songLoaded = plugin.load(baseName, songBuffer,
									(int) fileSize);
						}
						Log.v(TAG, String.format("%s gave Songref %s", plugin
								.getClass().getName(), songLoaded ? "TRUE"
								: "FALSE"));
						if (songLoaded) {
							currentPlugin = plugin;
							break;
						}
					}
				}
			}
		}

		if (currentPlugin != null) {
			Log.v(TAG, "HERE WE GO:" + currentPlugin.getClass().getName());

			Log.v(TAG,
					String.format("'%s' by '%s'", song.getTitle(),
							song.getComposer()));

			synchronized (this) {
				currentSong.fileName = song.getPath(); // songName;

				if (song.getTitle() != null) {
					currentSong.title = song.getTitle();
				} else {
					currentSong.title = getPluginInfo(DroidSoundPlugin.INFO_TITLE);
				}

				if (song.getComposer() != null) {
					currentSong.author = song.getComposer();
				} else {
					currentSong.author = getPluginInfo(DroidSoundPlugin.INFO_AUTHOR);
				}

				currentSong.copyright = getPluginInfo(DroidSoundPlugin.INFO_COPYRIGHT);
				currentSong.type = getPluginInfo(DroidSoundPlugin.INFO_TYPE);
				// currentSong.game = getPluginInfo(DroidSoundPlugin.INFO_GAME);
				currentSong.subTunes = currentPlugin
						.getIntInfo(DroidSoundPlugin.INFO_SUBTUNE_COUNT);
				currentSong.startTune = currentPlugin
						.getIntInfo(DroidSoundPlugin.INFO_STARTTUNE);
				String[] info = currentPlugin.getDetailedInfo();
				if (info == null) {
					info = new String[0];
				}
				
				currentSong.canSeek = currentPlugin.canSeek();
				
				currentSong.details = new String[info.length + 2];
				for (int i = 0; i < info.length; i++) {
					currentSong.details[i] = info[i];
				}
				currentSong.details[info.length] = "Size";

				String size = makeSize(fileSize);
				if (fileSize2 > 0) {
					size = size + " + " + makeSize(fileSize2);
				}
				currentSong.details[info.length + 1] = size;
				info = null;

				currentSong.length = currentPlugin
						.getIntInfo(DroidSoundPlugin.INFO_LENGTH);

				if (currentSong.title == null || currentSong.title.equals("")) {

					currentSong.title = currentPlugin.getBaseName(song
							.getName());
					/*
					 * int slash = songName.lastIndexOf('/') + 1; int dot =
					 * songName.lastIndexOf('.'); if(dot < 0) {
					 * currentSong.title = songName.substring(slash); } else {
					 * currentSong.title = songName.substring(slash, dot); }
					 */
					Log.v(TAG, String.format("FN Title '%s'", currentSong.title));
				}

				currentSong.subtuneTitle = getPluginInfo(DroidSoundPlugin.INFO_SUBTUNE_TITLE);
				currentSong.subtuneAuthor = getPluginInfo(DroidSoundPlugin.INFO_SUBTUNE_AUTHOR);

				if (currentSong.subTunes == -1)
					currentSong.subTunes = 0;
			}
			
			startedFromSub = false;

			if (song.getSubtune() >= 0) {
				currentSong.startTune = song.getSubtune();
				currentSong.subTunes = 0;
				currentPlugin.setTune(song.getSubtune());
				currentTune = song.getSubtune();
				currentSong.length = currentPlugin.getIntInfo(DroidSoundPlugin.INFO_LENGTH);
				currentSong.subtuneTitle = getPluginInfo(DroidSoundPlugin.INFO_SUBTUNE_TITLE);
				currentSong.subtuneAuthor = getPluginInfo(DroidSoundPlugin.INFO_SUBTUNE_AUTHOR);
				startedFromSub = true;
			}

			currentSong.source = "";
			
			Log.v(TAG, String.format(":%s:%s:%s:%s:", currentSong.title,currentSong.author, currentSong.copyright,currentSong.type));

			Message msg = mHandler.obtainMessage(MSG_NEWSONG);

			MediaPlayer mp = currentPlugin.getMediaPlayer();
			if (mp != null) {
				currentState = State.PLAYING;
				lastPos = -1000;				
				currentSong.source = currentPlugin.getStringInfo(102);
				Log.v(TAG, "MP3 SOURCE IS " + currentSong.source);

				mHandler.sendMessage(msg);
				
				mp.start();
				return;
			}

			mHandler.sendMessage(msg);

			if (flush) {
				audioTrack.stop();
				audioTrack.flush();
				try {
					Thread.sleep(100);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				// audioTrack.stop();
				// audioTrack.flush();

				Log.v(TAG, "START, pos " + audioTrack.getPlaybackHeadPosition());
			}

			if (reinitAudio) {
				audioTrack.release();
				audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ,
						AudioFormat.CHANNEL_CONFIGURATION_STEREO,
						AudioFormat.ENCODING_PCM_16BIT, bufSize,
						AudioTrack.MODE_STREAM);
				samples = new short[bufSize / 2];
				reinitAudio = false;
			}

			audioTrack.play();
			currentState = State.PLAYING;
			// currentPosition = 0;
			lastPos = -1000;
			if (songFile2 != null) {
				Log.v(TAG, String.format("Deleting temporary files %s and %s",
						songFile.getPath(), songFile2.getPath()));

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
		if (s == null) {
			s = "";
		}
		return s;
	}

	@Override
	public void run() {

		currentPlugin = null;

		audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);
		reinitAudio = false;
		Log.v(TAG, "AudioTrack created in thread " + Thread.currentThread().getId());
		noPlayWait = 0;
		int pos = 0;
		while(noPlayWait < 50) {
			try {				
				if(command != Command.NO_COMMAND) {
					
					Log.v(TAG, String.format("Command %s while in state %s", command.toString(), currentState.toString()));
					

					synchronized (cmdLock) {
						switch(command) {
						case PLAY:
							//int subtune = -1;
							SongFile song = (SongFile)argument;
							Log.v(TAG, "Playmod " + song.getName());
							/*int sc = song.indexOf(';');
							if(sc > 0) {								
								try {
									subtune = Integer.parseInt(song.substring(sc+1));
								} catch (NumberFormatException e) {
								}
								song = song.substring(0, sc);
							}*/
							startSong(song);
							break;
						case STOP:
							if(currentState != State.STOPPED) {
								//audioTrack.pause();
								Log.v(TAG, "STOP");
								MediaPlayer mp = currentPlugin == null ? null : currentPlugin.getMediaPlayer();
								if(mp != null) {
									mp.stop();
								} else {
									
									audioTrack.stop();
									audioTrack.flush();
									
									if(reinitAudio) {
										audioTrack.release();
										audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);
										samples = new short [bufSize/2];
										reinitAudio = false;
									}
								}
								
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
								int msec = (Integer)argument;
								if(currentState == State.SWITCHING) {
									currentState = State.PLAYING;
								}
								if(currentPlugin.seekTo(msec)) {
									
									//
									int playPos = audioTrack.getPlaybackHeadPosition() * 10 / (FREQ/100);
									Log.v(TAG, String.format("Offset %d/1000 - %d", msec, playPos));
									playPosOffset = msec - playPos;
									
									//currentPosition = msec;
									//lastPos = -1000;
								}
								break;
							case SET_TUNE:
								Log.v(TAG, "Setting tune");
								if(currentPlugin.setTune((Integer)argument)) {
									playPosOffset = 0;
									//currentPosition = 0;
									currentTune = (Integer)argument;
									lastPos = -1000;
									//Log.v(TAG, "TUNE, pos " + audioTrack.getPlaybackHeadPosition());
									audioTrack.pause();									
									audioTrack.flush();			
									try {
										Thread.sleep(100);
									} catch (InterruptedException e) {
										e.printStackTrace();
									}
									//Log.v(TAG, "TUNE, pos " + audioTrack.getPlaybackHeadPosition());
									
									if(reinitAudio) {
										audioTrack.release();
										audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);
										samples = new short [bufSize/2];
										reinitAudio = false;
									}

									if(currentState == State.SWITCHING) {
										currentState = State.PLAYING;
									}

									//int pos = audioTrack.getPlaybackHeadPosition();
									currentSong.length = currentPlugin.getIntInfo(DroidSoundPlugin.INFO_LENGTH);									
									currentSong.subtuneTitle = currentPlugin.getStringInfo(DroidSoundPlugin.INFO_SUBTUNE_TITLE);
									currentSong.subtuneAuthor = getPluginInfo(DroidSoundPlugin.INFO_SUBTUNE_AUTHOR);
									Message msg = mHandler.obtainMessage(MSG_SUBTUNE, (Integer)argument, currentSong.length, new String[] {currentSong.subtuneTitle, currentSong.subtuneAuthor});
									mHandler.sendMessage(msg);									
									audioTrack.play();
								}
								break;
							case PAUSE :
								if(currentState == State.PLAYING) {
									currentState = State.PAUSED;
									Message msg = mHandler.obtainMessage(MSG_STATE, 2, 0);
									mHandler.sendMessage(msg);
									MediaPlayer mp = currentPlugin == null ? null : currentPlugin.getMediaPlayer();
									if(mp != null)
										mp.pause();
									else
										audioTrack.pause();
								}
								
								break;
							case UNPAUSE :
								if(currentState == State.PAUSED) {
									currentState = State.PLAYING;
									Message msg = mHandler.obtainMessage(MSG_STATE, 1, 0);
									mHandler.sendMessage(msg);
									MediaPlayer mp = currentPlugin == null ? null : currentPlugin.getMediaPlayer();
									if(mp != null)
										mp.start();
									else
										audioTrack.play();
								}
								
								break;
							}								
						}
						command = Command.NO_COMMAND;
					}					
				}
				
				/*
				 * Always feed track - play zeroes after song ends
				 * Report song end at correct time
				 * 
				 */
				
				if(currentState == State.PLAYING) {
					//Log.v(TAG, "Get sound data");
					int len = 0;
					MediaPlayer mp = currentPlugin == null ? null : currentPlugin.getMediaPlayer();
					if(mp != null) {
						
						int playPos = currentPlugin.getSoundData(null, 0);
												
						if(playPos < -0) { //!mp.isPlaying()) {
							//songEnded = true;
							currentState = State.SWITCHING;
							Message msg = mHandler.obtainMessage(MSG_DONE);
							mHandler.sendMessage(msg);
						}
						
						//int playPos = mp.getCurrentPosition();
						
						String title = currentPlugin.getStringInfo(101);
						if(title != null) {
							
							Log.v(TAG, "########################################### GOT NEW META INFO");
							
							String author = null;
							int split = title.indexOf(" - ");
							if(split > 0) {
								author = title.substring(0, split);
								title = title.substring(split+3);
							}
							
							Message msg = mHandler.obtainMessage(MSG_SUBTUNE, -1, 0, new String[] {title, author});
							mHandler.sendMessage(msg);
						}
						
						
						int song = currentPlugin.getIntInfo(DroidSoundPlugin.INFO_SUBTUNE_NO);
						if(song >= 0 && song != currentTune) {
							
							if(startedFromSub) {
								currentState = State.SWITCHING;
								Message msg = mHandler.obtainMessage(MSG_DONE);
								mHandler.sendMessage(msg);								
								startedFromSub = false;
							}
							
							currentTune = song;
							//currentSong.length = currentPlugin.getIntInfo(DroidSoundPlugin.INFO_LENGTH);									
							currentSong.subtuneTitle = currentPlugin.getStringInfo(DroidSoundPlugin.INFO_SUBTUNE_TITLE);
							currentSong.subtuneAuthor = getPluginInfo(DroidSoundPlugin.INFO_SUBTUNE_AUTHOR);
							Message msg = mHandler.obtainMessage(MSG_SUBTUNE, currentTune, currentSong.length, new String[] {currentSong.subtuneTitle, currentSong.subtuneAuthor});
							mHandler.sendMessage(msg);									
						}

						Message msg = mHandler.obtainMessage(MSG_PROGRESS, playPos, 0);
						mHandler.sendMessage(msg);
						Thread.sleep(100);
						continue;
					}
					
					if(!songEnded) {
						len = currentPlugin.getSoundData(samples, bufSize/16);
					} else {
						Thread.sleep(100);
					}

					int p = audioTrack.getPlaybackHeadPosition();
					
					//currentPosition += ((len * 1000) / (FREQ*2));						
					//Log.v(TAG, "pos " + currentPosition);
					
					//Log.v(TAG, String.format("%d vs %d", pos, p));
					if(songEnded && p == pos) {
						lastTime = -1;
						currentState = State.SWITCHING;
						Message msg = mHandler.obtainMessage(MSG_DONE);
						mHandler.sendMessage(msg);			
					}

					pos = p;
					int playPos = pos * 10 / (FREQ/100);
					
					if(pos >= lastPos + FREQ/2) {
						//Log.v(TAG, String.format("PLAY %d sec %d pos = %d msec ", currentPosition, pos, pos * 1000 / 44100));

						if(aCount == 0) aCount = 1;
						Message msg = mHandler.obtainMessage(MSG_PROGRESS, playPos + playPosOffset, 100 - (int) (audioTime / aCount));
						aCount = 0;
						audioTime = 0;
						mHandler.sendMessage(msg);
						lastPos = pos;
												
						if(currentPlugin.isSilent()) {
							if(silentPosition < 0) {
								silentPosition = pos;
							}
							else
							if(pos > silentPosition + 2500) {
								msg = mHandler.obtainMessage(MSG_SILENT);
								mHandler.sendMessage(msg);
								Log.v(TAG, "Silence");
								silentPosition = -1;
							}
						} else {
							silentPosition = -1;
						}
						
					}
					//Log.v(TAG, "write " + len);
					
					if(len < 0) {
						if(playPos > 5000) {
							songEnded = true;
						}
						len = bufSize/16;						
						Arrays.fill(samples, 0, len, (short) 0);
					}
					if(len > 0) {			
						long t = System.currentTimeMillis();
						audioTrack.write(samples, 0, len);

						long tt = System.currentTimeMillis();
						if(lastTime > 0) {							
							frameTime = (tt - lastTime);
							long d = tt - t;
							//Log.v(TAG, String.format("Frame %d, write %d", frameTime, d));
							if(frameTime > 0) {
								audioTime += ((d * 100) / frameTime);
								aCount++;
							}
						}
						lastTime = tt;
					}
					
					//Log.v(TAG, "loop");
					noPlayWait = 0;
				}
				else {
					if(currentState == State.STOPPED) {
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
		
		for(DroidSoundPlugin plugin : plugins) {
			plugin.exit();
		}
		
		Log.v(TAG, "Player Thread exiting due to inactivity");
		
	}

	synchronized int getPosition() {
		return audioTrack.getPlaybackHeadPosition();
	}

	synchronized public boolean getSongInfo(SongInfo target) {
		target.title = new String(currentSong.title);
		target.author = new String(currentSong.author);
		target.copyright = new String(currentSong.copyright);
		// target.game = new String(currentSong.game);
		target.type = new String(currentSong.type);
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
			if (pause) {
				Log.v(TAG, "Pausing");
				command = Command.PAUSE;
			} else {
				Log.v(TAG, "Unpausing");
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
			Log.v(TAG, "Buffersize now " + bs);
			reinitAudio = true;
		}
	}

}
