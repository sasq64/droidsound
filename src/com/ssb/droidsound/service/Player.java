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
import java.util.List;
import java.util.zip.ZipEntry;

import android.content.Context;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.plugins.GMEPlugin;
import com.ssb.droidsound.plugins.ModPlugin;
import com.ssb.droidsound.plugins.SidplayPlugin;
import com.ssb.droidsound.plugins.TFMXPlugin;
import com.ssb.droidsound.plugins.UADEPlugin;
import com.ssb.droidsound.utils.NativeZipFile;

/*
 * The Player thread 
 */
public class Player implements Runnable {
	private static final String TAG = "Player";
	
	public enum State {
		STOPPED,
		PAUSED,
		PLAYING, 
		SWITCHING
	};

	public enum Command {
		NO_COMMAND,
		STOP, // Unload and stop if playing
		PLAY, // Play new file or last file

		// Only when Playing:
		PAUSE,
		UNPAUSE,
		SET_POS,
		SET_TUNE,	
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
		String game;
		int length;
		int subTunes;
		int startTune;
		public String[] details;
		public String subtuneTitle;
		public String fileName;		
	};
	
	private Handler mHandler;
	
	// Audio data
	private short [] samples;
	private AudioTrack audioTrack;
	private int bufSize;

	// Plugins
	private DroidSoundPlugin currentPlugin;	
	private DroidSoundPlugin [] plugins;
	
	
	// Incoming state
	private Object cmdLock = new Object();
	private Command command = Command.NO_COMMAND;
	private Object argument;
	private int intArgument;
	
	
	// Player state
	private int currentPosition;
	private int noPlayWait;
	private int lastPos;
	private SongInfo currentSong = new SongInfo();
	
	private Object songRef;
	
	private File currentZipFile;
	private NativeZipFile currentZip;
	
	private volatile State currentState = State.STOPPED;
	private int silentPosition;
	
	int FREQ = 44100;

	public Player(AudioManager am, Handler handler, Context ctx) {
		mHandler = handler;
		plugins = new DroidSoundPlugin [4];
		plugins[0] = new SidplayPlugin(ctx);
		//plugins[0] = new TinySidPlugin();
		plugins[1] = new ModPlugin(ctx);
		plugins[2] = new GMEPlugin(ctx);
		plugins[3] = new UADEPlugin(ctx);
		//plugins[3] = new TFMXPlugin(ctx);

		//bufSize = AudioTrack.getMinBufferSize(44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT);
		//if(bufSize < 32768*2) {
		//	bufSize = 32768*2;
		//}
		silentPosition = -1;
		// Enough for 1000ms
		bufSize = FREQ*8;

		samples = new short [bufSize/2];
	}

    private void startSong(String songName, int startTune) {
    	    	
    	if(currentPlugin != null) {
    		currentPlugin.unload(songRef);
    	}
    	currentPlugin = null;
    	currentState = State.SWITCHING;
    	
    	List<DroidSoundPlugin> list = new ArrayList<DroidSoundPlugin>();
    	
    	for(int i=0; i< plugins.length; i++) {
    		if(plugins[i].canHandle(songName)) {    			
    			list.add(plugins[i]);
    			Log.v(TAG, String.format("%s handled by %d", songName, i));
    		}
    	}
                
		byte [] songBuffer = null;
		long fileSize = 0;
		File songFile = null;
		
		try {
			//File f = new File(Environment.getExternalStorageDirectory()+"/" + modName);
			
			if(songName.startsWith("file://")) {
				songName = songName.substring(7);
			}

			int zipExt = songName.toUpperCase().indexOf(".ZIP/");
			
			if(zipExt < 0) {
				if(currentZipFile != null) {
					currentZip.close();
					currentZip = null;
					currentZipFile = null;
				}
			}


			if(zipExt > 0) {
				
				File f = new File(songName.substring(0, zipExt + 5));
				
				if(currentZipFile != null && f.equals(currentZipFile)) {
				} else {
					currentZipFile = f;
					currentZip = new NativeZipFile(f);
				}

				String name = songName.substring(zipExt+5);
				
				Log.v(TAG, String.format("Trying to open '%s' in zipfile '%s'\n", name, f.getPath())); 
				
				if(currentZip != null) {
					Log.v(TAG, "ENTRY"); 
					ZipEntry entry = currentZip.getEntry(name);
					if(entry != null) {
						Log.v(TAG, String.format("Entry  '%s' %d\n", entry.getName(), entry.getSize())); 
						InputStream fs = currentZip.getInputStream(entry);
						fileSize = entry.getSize();
						songBuffer = new byte [(int) fileSize];
						fs.read(songBuffer);
						fs.close();
					}
				}
			}
			else
			if(songName.startsWith("http://")) {
				
				URL url = new URL(songName);
				
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
				if(response == HttpURLConnection.HTTP_OK)
				{
					int size;
					byte[] buffer = new byte[16384];
					Log.v(TAG, "HTTP connected");
					InputStream in = httpConn.getInputStream();
					File f = File.createTempFile("music", null);
					FileOutputStream fos = new FileOutputStream(f);
					BufferedOutputStream bos = new BufferedOutputStream(fos, buffer.length);					
					while ((size = in.read(buffer)) != -1) {
						bos.write(buffer, 0, size);
					}
					bos.flush();
					bos.close();
					
					fileSize = f.length();
					
					Log.v(TAG, "Bytes written: " + fileSize);

					songBuffer = new byte [(int) fileSize];
					FileInputStream fs = new FileInputStream(f);
					fs.read(songBuffer);
					fs.close();
					f.delete();
				}
			} else {
				songFile = new File(songName);
				fileSize = songFile.length();
				System.gc();
				
				if(!songFile.exists())
					songFile = null;				
				
				//songBuffer = new byte [(int) fileSize];
				//FileInputStream fs = new FileInputStream(f);
				//fs.read(songBuffer);
				//fs.close();
			}

		} catch (IOException e) {
			Log.w(TAG, "Could not load music!");
			e.printStackTrace();
		}
		
		if(songBuffer != null || songFile != null) {
			
			for(DroidSoundPlugin plugin : list) {
				Log.v(TAG, "Trying " + plugin.getClass().getName());
				if(songFile != null) {
					try {
						songRef = plugin.load(songFile);
					} catch (IOException e) {
					}
				} else {
					songRef = plugin.load(songBuffer, (int) fileSize);
				}
				if(songRef != null) {
					currentPlugin = plugin;
					break;
				}
			}
			
			if(currentPlugin == null) {
		    	for(int i=0; i< plugins.length; i++) {
		    		if(!plugins[i].canHandle(songName)) {    			
						if(songFile != null) {
							try {
								songRef = plugins[i].load(songFile);
							} catch (IOException e) {
							}
						} else {
							songRef = plugins[i].load(songBuffer, (int) fileSize);
						}
		    			Log.v(TAG, String.format("%s gave Songref %s", plugins[i].getClass().getName(), songRef != null ? songRef.toString() : "NULL"));
						if(songRef != null) {
							currentPlugin = plugins[i];
							break;
						}
		    		}
		    	}
			}
		}

		if(currentPlugin != null) {
			Log.w(TAG, "HERE WE GO:" + currentPlugin.getClass().getName());

			synchronized (this) {
				currentSong.fileName = songName;
				currentSong.title = getPluginInfo(DroidSoundPlugin.INFO_TITLE);
				currentSong.author = getPluginInfo(DroidSoundPlugin.INFO_AUTHOR);
				currentSong.copyright = getPluginInfo(DroidSoundPlugin.INFO_COPYRIGHT);
				currentSong.type = getPluginInfo(DroidSoundPlugin.INFO_TYPE);
				currentSong.game = getPluginInfo(DroidSoundPlugin.INFO_GAME);
				currentSong.subTunes = currentPlugin.getIntInfo(songRef, DroidSoundPlugin.INFO_SUBTUNES);
				currentSong.startTune = currentPlugin.getIntInfo(songRef, DroidSoundPlugin.INFO_STARTTUNE);
				String [] info  = currentPlugin.getDetailedInfo(songRef);
				if(info != null) {
					currentSong.details = new String [info.length + 2];
					for(int i=0; i<info.length; i++) {
						currentSong.details[i] = info[i];
					}
					currentSong.details[info.length] = "Size";
					
					if(fileSize < 10*1024) {
						currentSong.details[info.length+1] = String.format("%1.1fKB", (float)fileSize/1024F);
					} else if(fileSize < 1024*1024) {
						currentSong.details[info.length+1] = String.format("%dKB", fileSize/1024);
					} else if(fileSize < 10*1024*1024) {
						currentSong.details[info.length+1] = String.format("%1.1fMB", (float)fileSize/(1024F * 1024F));
					} else {
						currentSong.details[info.length+1] = String.format("%dMB", fileSize/(1024*1024));
					}
					info = null;
				} else {
					currentSong.details = new String [0];
				}
						
				
				currentSong.length = currentPlugin.getIntInfo(songRef, DroidSoundPlugin.INFO_LENGTH);
				
				if(currentSong.title == null || currentSong.title.equals("")) {
					int slash = songName.lastIndexOf('/') + 1;
					int dot = songName.lastIndexOf('.');
					if(dot < 0) {
						currentSong.title = songName.substring(slash);
					} else {
						currentSong.title = songName.substring(slash, dot);
					}
					Log.v(TAG, String.format("FN Title '%s'", currentSong.title));
				}
				
				currentSong.subtuneTitle =  getPluginInfo(DroidSoundPlugin.INFO_SUBTUNE_TITLE);
						
				

				if(currentSong.subTunes == -1)
					currentSong.subTunes = 0;			
			}
			
			if(startTune >= 0) {
				currentSong.startTune = startTune;
				currentPlugin.setTune(songRef, startTune);
				currentSong.length = currentPlugin.getIntInfo(songRef, DroidSoundPlugin.INFO_LENGTH);
				currentSong.subtuneTitle =  getPluginInfo(DroidSoundPlugin.INFO_SUBTUNE_TITLE);
			}

			Log.v(TAG, String.format(":%s:%s:%s:%s:", currentSong.title, currentSong.author, currentSong.copyright, currentSong.type));

			Message msg = mHandler.obtainMessage(MSG_NEWSONG);
			mHandler.sendMessage(msg);

			audioTrack.flush();
			audioTrack.play();				
			currentState = State.PLAYING;
			currentPosition = 0;
			lastPos = -1000;
			return;
        }
		currentState = State.STOPPED;
    }

	private String getPluginInfo(int info) {
		String s = currentPlugin.getStringInfo(songRef, info);
		if(s == null) {
			s = "";
		}
		return s;
	}

	@Override
	public void run() {

		boolean ok;
		currentPlugin = null;

		audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, FREQ, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);
		Log.v(TAG, "AudioTrack created in thread " + Thread.currentThread().getId());
		noPlayWait = 0;

		while(noPlayWait < 50) {
			try {				
				if(command != Command.NO_COMMAND) {
					
					Log.v(TAG, String.format("Command %s while in state %s", command.toString(), currentState.toString()));

					synchronized (cmdLock) {
						switch(command) {
						case PLAY:
							
							int subtune = -1;
							String song = (String)argument;
							Log.v(TAG, "Playmod " + song);
							int sc = song.indexOf(';');
							if(sc > 0) {								
								try {
									subtune = Integer.parseInt(song.substring(sc+1));
								} catch (NumberFormatException e) {
								}
								song = song.substring(0, sc);
							}
							startSong(song, subtune);
							break;
						case STOP:
							if(currentState != State.STOPPED) {
								audioTrack.stop();
								currentPlugin.unload(songRef);
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
								if(currentPlugin.seekTo(songRef, msec)) {
									currentPosition = msec;
									lastPos = -1000;
								}
							case SET_TUNE:
								if(currentPlugin.setTune(songRef, (Integer)argument)) {
									currentPosition = 0;
									lastPos = -1000;
									audioTrack.flush();

									if(currentState == State.SWITCHING) {
										currentState = State.PLAYING;
									}
									//int pos = audioTrack.getPlaybackHeadPosition();
									currentSong.length = currentPlugin.getIntInfo(songRef, DroidSoundPlugin.INFO_LENGTH);									
									currentSong.subtuneTitle = currentPlugin.getStringInfo(songRef, DroidSoundPlugin.INFO_SUBTUNE_TITLE);
									Message msg = mHandler.obtainMessage(MSG_SUBTUNE, (Integer)argument, currentSong.length, currentSong.subtuneTitle);
									mHandler.sendMessage(msg);
								}
								break;
							case PAUSE :
								if(currentState == State.PLAYING) {
									currentState = State.PAUSED;
									Message msg = mHandler.obtainMessage(MSG_STATE, 2, 0);
									mHandler.sendMessage(msg);
									audioTrack.pause();
								}
								
								break;
							case UNPAUSE :
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
				
				if(currentState == State.PLAYING) {
					int len = currentPlugin.getSoundData(songRef, samples, bufSize/4);
					currentPosition += ((len * 1000) / (FREQ*2));						
					if(currentPosition >= lastPos + 1000) {
						Message msg = mHandler.obtainMessage(MSG_PROGRESS, currentPosition, 0);
						mHandler.sendMessage(msg);
						lastPos = currentPosition;
												
						if(currentPlugin.isSilent(songRef)) {
							if(silentPosition < 0) {
								silentPosition = currentPosition;
							}
							else
							if(currentPosition > silentPosition + 2500) {
								msg = mHandler.obtainMessage(MSG_SILENT);
								mHandler.sendMessage(msg);
								Log.v(TAG, "Silence");
								silentPosition = -1;
							}
						} else {
							silentPosition = -1;
						}
						
					}
					if(len > 0) {
						audioTrack.write(samples, 0, len);
					} else {
						currentState = State.SWITCHING;
						Message msg = mHandler.obtainMessage(MSG_DONE);
						mHandler.sendMessage(msg);
					}	
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
		Log.v(TAG, "Player Thread exiting due to inactivity");
		
	}
	
	synchronized int getPosition() {
		return currentPosition;
	}
	
	synchronized public boolean getSongInfo(SongInfo target) {		
		target.title = new String(currentSong.title);
		target.author = new String(currentSong.author);
		target.copyright = new String(currentSong.copyright);
		target.game = new String(currentSong.game);
		target.type = new String(currentSong.type);
		target.length = currentSong.length;
		target.subTunes = currentSong.subTunes;
		target.startTune = currentSong.startTune;
		target.details = currentSong.details;
		target.subtuneTitle = currentSong.subtuneTitle;
		target.fileName = currentSong.fileName;
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

	public void playMod(String mod) {
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

}
