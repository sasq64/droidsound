package com.ssb.droidsound;

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

import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.net.Uri;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

public class Player implements Runnable {

	private static final String TAG = "Player";
	private short [] samples;
	private DroidSoundPlugin currentPlugin;
	
	private DroidSoundPlugin [] plugins;
	
	private String modToPlay;
	private String modName;
	private AudioTrack audioTrack;
	private int bufSize;
	private boolean doStop;
	private boolean playing;
	private int currentPosition;
	private int moduleLength;
	//private String moduleTitle;
	//private String moduleAuthor;
	private int seekTo;
	private Handler mHandler;
	private int noPlayWait;
	private int lastPos;
	private boolean setPaused;
	private int subSong;
	//private Uri uriToPlay;
		
	public Player(AudioManager am, Handler handler) {
		mHandler = handler;
		plugins = new DroidSoundPlugin [3];
		plugins[0] = new TinySidPlugin();
		plugins[1] = new ModPlugin();
		plugins[2] = new GMEPlugin();

		bufSize = AudioTrack.getMinBufferSize(44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT);
		if(bufSize < 32768*4) {
			bufSize = 32768*4;
		}
		
		samples = new short [bufSize/2];
	}

    public void startMod() {
    	
    	synchronized (this) {
    		modName = modToPlay;  
    		modToPlay = null;
		}
    	
    	currentPlugin = null;
    	
    	List<DroidSoundPlugin> list = new ArrayList<DroidSoundPlugin>();
    	
    	for(int i=0; i< plugins.length; i++) {
    		if(plugins[i].canHandle(modName)) {    			
    			list.add(plugins[i]);
    			Log.v(TAG, String.format("%s handled by %d", modName, i));
    		}
    	}
                
		byte [] songBuffer = null;
		long fileSize = 0;
		
		try {
			//File f = new File(Environment.getExternalStorageDirectory()+"/" + modName);
			
			if(modName.startsWith("file://")) {
				modName = modName.substring(7);
			}
			
			if(modName.startsWith("http://")) {
				
				URL url = new URL(modName);
				
				Log.v(TAG, "Opening URL " + modName);
				
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

				}
			} else {
				File f = new File(modName);
				fileSize = f.length();
				songBuffer = new byte [(int) fileSize];
				FileInputStream fs = new FileInputStream(f);
				fs.read(songBuffer);
			}

		} catch (IOException e) {
			Log.w(TAG, "Could not load music!");
			// TODO Auto-generated catch block
			//e.printStackTrace();
		}
		
		if(songBuffer != null) {
			
			for(DroidSoundPlugin plugin : list) {
				Log.v(TAG, "Trying " + plugin.getClass().getName());
				if(plugin.load(songBuffer, (int) fileSize)) {
					currentPlugin = plugin;
					break;
				}
			}
		}

		if(currentPlugin != null) {
			Log.w(TAG, "HERE WE GO:" + currentPlugin.getClass().getName());
			String title = currentPlugin.getStringInfo(DroidSoundPlugin.INFO_TITLE);
			String author = currentPlugin.getStringInfo(DroidSoundPlugin.INFO_AUTHOR);
			String copyright = currentPlugin.getStringInfo(DroidSoundPlugin.INFO_COPYRIGHT);
			String type = currentPlugin.getStringInfo(DroidSoundPlugin.INFO_TYPE);
			int subsongs = currentPlugin.getIntInfo(DroidSoundPlugin.INFO_SUBSONGS);
			if(subsongs == -1)
				subsongs = 0;
			Log.v(TAG, String.format(":%s:%s:%s:%s:", title, author, copyright, type));
			synchronized (this) {
				moduleLength = currentPlugin.getIntInfo(DroidSoundPlugin.INFO_LENGTH);
				Log.v(TAG, "Got length " + moduleLength);
				/*moduleTitle = title;
				if(moduleTitle == null)
					moduleTitle = "Unknown";
				moduleAuthor = author;
				if(moduleAuthor == null)
					moduleAuthor = "Unknown";*/
				
				Message msg = mHandler.obtainMessage();
				msg.what = 0;
				msg.arg1 = moduleLength;
				msg.arg2 = subsongs;
				msg.obj = new String [] { title, author, copyright, type };
				mHandler.sendMessage(msg);
			}
			Log.w(TAG, "Modname is " + title);
			audioTrack.play();				
			playing = true;

        }
    }

	@Override
	public void run() {

		currentPlugin = null;

		doStop = false;
		playing = false;
		seekTo = -1;
		subSong = -1;

		audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC, 44100, AudioFormat.CHANNEL_CONFIGURATION_STEREO, AudioFormat.ENCODING_PCM_16BIT, bufSize, AudioTrack.MODE_STREAM);

		Log.v(TAG, "AudioTrack created in thread " + Thread.currentThread().getId());
		noPlayWait = 0;

		while(noPlayWait < 50) {
			try {
				boolean doPlay = false;

				synchronized (this) {
					if(modToPlay != null)
						doPlay = true;
				}

				if(doPlay) {
					if(playing) {
						audioTrack.stop();
						currentPlugin.unload();
					}
					playing = false;
					startMod();
					currentPosition = lastPos = 0;
				}
				
				if(doStop) {
					if(playing) {
						audioTrack.stop();
						currentPlugin.unload();
					}
					audioTrack.stop();
					doStop = false;
					playing = false;
					currentPosition = lastPos = 0;
				}
				
				if(subSong >= 0) {
					currentPlugin.setSong(subSong);
					currentPosition = 0;
					subSong = -1;
				}
				

				if(playing && !setPaused) {					
					noPlayWait = 0;
					if(seekTo >= 0) {
						if(currentPlugin.seekTo(seekTo)) {
							currentPosition = lastPos = seekTo;
						}
						seekTo = -1;
					}

					int rc = currentPlugin.getSoundData(samples, bufSize/4);
					//synchronized (this) {
						currentPosition += ((rc * 1000) / 88200);
						
						if(currentPosition >= lastPos + 1000) {
							Message msg = mHandler.obtainMessage();
							msg.what = 3;
							msg.arg1 = currentPosition;
							mHandler.sendMessage(msg);
							lastPos = currentPosition;
						}
						
					//}
					if(rc > 0) {
						audioTrack.write(samples, 0, rc);
					} else {
						playing = false;
						Message msg = mHandler.obtainMessage();
						msg.what = 1;
						mHandler.sendMessage(msg);
					}
				} else {
					if(!setPaused)
						noPlayWait++;
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
	
	synchronized int getLength() {
		return moduleLength;
	}
	
	//synchronized String getTitle() {
	//	return moduleTitle;
	//}

	//synchronized String getAuthor() {
	//	return moduleAuthor;
	//}

	synchronized public void stop() {		
		doStop = true;
	}
	
	synchronized public void paused(boolean pause) {
		setPaused = pause;
	}

	synchronized public void seekTo(int pos) {
		seekTo = pos;		
	}

	synchronized void playMod(String mod) {
		modToPlay = mod;
	}

	public void setSubSong(int song) {
		// TODO Auto-generated method stub
		subSong = song;
		
	}

	public void playMod(Uri uri) {
		// TODO Auto-generated method stub
		//uriToPlay = uri;
		
	}

}
