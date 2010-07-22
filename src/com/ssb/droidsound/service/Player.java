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
import java.util.zip.ZipFile;

import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.plugins.GMEPlugin;
import com.ssb.droidsound.plugins.ModPlugin;
import com.ssb.droidsound.plugins.SidplayPlugin;
import com.ssb.droidsound.plugins.TinySidPlugin;
import com.ssb.droidsound.utils.NativeZipFile;

import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

/*
 * The Player thread 
 */
public class Player implements Runnable {
	private static final String TAG = "Player";
	
	public enum State {
		STOPPED,
		PAUSED,
		PLAYING;
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
	
	public static class SongInfo {
		String title;
		String author;
		String copyright;
		String type;
		String game;
		int length;
		int subTunes;
		int startTune;		
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
	
	
	// Player state
	private int currentPosition;
	private int noPlayWait;
	private int lastPos;
	private SongInfo currentSong = new SongInfo();
	
	private Object songRef;
	
	private File currentZipFile;
	private NativeZipFile currentZip;
	
	private volatile State currentState = State.STOPPED;

	public Player(AudioManager am, Handler handler) {
		mHandler = handler;
		plugins = new DroidSoundPlugin [3];
		plugins[0] = new SidplayPlugin();
		//plugins[0] = new TinySidPlugin();
		plugins[1] = new ModPlugin();
		plugins[2] = new GMEPlugin();

		//bufSize = AudioTrack.getMinBufferSize(44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT);
		//if(bufSize < 32768*2) {
		//	bufSize = 32768*2;
		//}
		
		// Enough for 1000ms
		bufSize = 44100*2;

		samples = new short [bufSize/2];
	}

    private void startSong(String songName) {
    	    	
    	if(currentPlugin != null) {
    		currentPlugin.unload(songRef);
    	}
    	currentPlugin = null;
    	currentState = State.STOPPED;
    	
    	List<DroidSoundPlugin> list = new ArrayList<DroidSoundPlugin>();
    	
    	for(int i=0; i< plugins.length; i++) {
    		if(plugins[i].canHandle(songName)) {    			
    			list.add(plugins[i]);
    			Log.v(TAG, String.format("%s handled by %d", songName, i));
    		}
    	}
                
		byte [] songBuffer = null;
		long fileSize = 0;
		
		try {
			//File f = new File(Environment.getExternalStorageDirectory()+"/" + modName);
			
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
			if(songName.startsWith("file://")) {
				songName = songName.substring(7);
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

				}
			} else {
				File f = new File(songName);
				fileSize = f.length();
				System.gc();
				songBuffer = new byte [(int) fileSize];
				FileInputStream fs = new FileInputStream(f);
				fs.read(songBuffer);
				fs.close();
			}

		} catch (IOException e) {
			Log.w(TAG, "Could not load music!");
			e.printStackTrace();
		}
		
		if(songBuffer != null) {
			
			for(DroidSoundPlugin plugin : list) {
				Log.v(TAG, "Trying " + plugin.getClass().getName());
				songRef = plugin.load(songBuffer, (int) fileSize);
				if(songRef != null) {
					currentPlugin = plugin;
					break;
				}
			}
		}

		if(currentPlugin != null) {
			Log.w(TAG, "HERE WE GO:" + currentPlugin.getClass().getName());
			synchronized (this) {
				currentSong.title = getPluginInfo(DroidSoundPlugin.INFO_TITLE);
				currentSong.author = getPluginInfo(DroidSoundPlugin.INFO_AUTHOR);
				currentSong.copyright = getPluginInfo(DroidSoundPlugin.INFO_COPYRIGHT);
				currentSong.type = getPluginInfo(DroidSoundPlugin.INFO_TYPE);
				currentSong.game = getPluginInfo(DroidSoundPlugin.INFO_GAME);
				currentSong.subTunes = currentPlugin.getIntInfo(songRef, DroidSoundPlugin.INFO_SUBTUNES);
				currentSong.startTune = currentPlugin.getIntInfo(songRef, DroidSoundPlugin.INFO_STARTTUNE);
				currentSong.length = currentPlugin.getIntInfo(songRef, DroidSoundPlugin.INFO_LENGTH);
				
				
				if(currentSong.title == null || currentSong.title.equals("")) {
					currentSong.title = currentSong.game;
					Log.v(TAG, String.format("G Title '%s'", currentSong.title));
					if(currentSong.title == null || currentSong.title.equals("")) {
						currentSong.title = songName;
						if(currentSong.title.contains(".")) {
							currentSong.title = currentSong.title.substring(0, currentSong.title.lastIndexOf('.'));
						}
						Log.v(TAG, String.format("FN Title '%s'", currentSong.title));
					}
				}
				
				
				if(currentSong.subTunes == -1)
					currentSong.subTunes = 0;			
			}

			Log.v(TAG, String.format(":%s:%s:%s:%s:", currentSong.title, currentSong.author, currentSong.copyright, currentSong.type));

			Message msg = mHandler.obtainMessage(MSG_NEWSONG);
			mHandler.sendMessage(msg);

			audioTrack.flush();
			audioTrack.play();				
			currentState = State.PLAYING;
			currentPosition = 0;
			lastPos = -1000;
        }
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

		currentPlugin = null;

		audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, 44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);
		Log.v(TAG, "AudioTrack created in thread " + Thread.currentThread().getId());
		noPlayWait = 0;

		while(noPlayWait < 50) {
			try {				
				if(command != Command.NO_COMMAND) {
					
					Log.v(TAG, String.format("Command %s while in state %s", command.toString(), currentState.toString()));
					
					synchronized (cmdLock) {
						switch(command) {
						case PLAY:
							startSong((String)argument);
							break;
						case STOP:
							if(currentState != State.STOPPED) {
								audioTrack.stop();
								currentPlugin.unload(songRef);
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
								if(currentPlugin.seekTo(songRef, msec)) {
									currentPosition = msec;
									lastPos = -1000;
								}
							case SET_TUNE:
								currentPlugin.setTune(songRef, (Integer)argument);
								break;
							case PAUSE :
								if(currentState == State.PLAYING) {
									currentState = State.PAUSED;
									Message msg = mHandler.obtainMessage(MSG_STATE, 2, 0);
									mHandler.sendMessage(msg);
								}
								audioTrack.pause();
								break;
							case UNPAUSE :
								if(currentState == State.PAUSED) {
									currentState = State.PLAYING;
									Message msg = mHandler.obtainMessage(MSG_STATE, 1, 0);
									mHandler.sendMessage(msg);
								}
								audioTrack.play();
								break;
							}								
						}
						command = Command.NO_COMMAND;
					}					
				}
				
				if(currentState == State.PLAYING) {
					
					int len = currentPlugin.getSoundData(songRef, samples, bufSize/4);
					currentPosition += ((len * 1000) / 88200);						
					if(currentPosition >= lastPos + 1000) {
						Message msg = mHandler.obtainMessage(MSG_PROGRESS, currentPosition, 0);
						mHandler.sendMessage(msg);
						lastPos = currentPosition;
					}
					if(len > 0) {
						audioTrack.write(samples, 0, len);
					} else {
						currentState = State.STOPPED;
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
		target.type = new String(currentSong.type);
		target.length = currentSong.length;
		target.subTunes = currentSong.subTunes;
		target.startTune = currentSong.startTune;
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

}
