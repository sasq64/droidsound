package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.FileDescriptor;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import com.ssb.droidsound.utils.CueFile;
import com.ssb.droidsound.utils.ID3Tag;

import android.media.MediaPlayer;
import android.util.Log;

public class MP3Plugin extends DroidSoundPlugin {
	private static final String TAG = MP3Plugin.class.getSimpleName();
	
	private MediaPlayer mediaPlayer;
	private boolean started;

	private ID3Tag id3Tag;
	private CueFile cueFile;
	private int currentSong;

	@Override
	public boolean canHandle(String name) {
		int x = name.lastIndexOf('.');
		String ext = name.substring(x+1).toUpperCase();
		Log.v(TAG, String.format("Checking ext '%s'", ext));
		return ext.equals("MP3");
	}

	@Override
	public String[] getDetailedInfo() {

		Log.v(TAG, "GetInfo");
		if(id3Tag != null) {
			Log.v(TAG, "ID3 here");
			List<String> info = new ArrayList<String>();
			String album = id3Tag.getStringInfo(ID3Tag.ID3INFO_ALBUM);
			if(album != null && album.length() > 0) {
				info.add("Album");
				info.add(album);				
			}
			String track = id3Tag.getStringInfo(ID3Tag.ID3INFO_TRACK);
			if(track != null && track.length() > 0) {
				info.add("Track");
				info.add(track);
			}
			String genre = id3Tag.getStringInfo(ID3Tag.ID3INFO_GENRE);
			if(genre != null && genre.length() > 0) {
				info.add("Genre");
				info.add(genre);
			}
			String comment = id3Tag.getStringInfo(ID3Tag.ID3INFO_COMMENT);
			if(comment != null && comment.length() > 0) {
				info.add("Comment");
				info.add(comment);
			}
			String [] strArray = new String[info.size()];
			info.toArray(strArray);
			return strArray;
		}
		
		return null;
		
	}
	
	@Override
	public int getIntInfo(int what) {
		// TODO Auto-generated method stub
		if(what == 1000) return 1;
		
		switch(what) {
		case INFO_LENGTH:
			if(mediaPlayer != null)
				return mediaPlayer.getDuration();
		case INFO_SUBTUNE_COUNT:
			if(cueFile != null) {
				return cueFile.getTrackCount();
			}
			break;
		case INFO_SUBTUNE_NO:
			int pos = mediaPlayer.getCurrentPosition();
			if(cueFile != null) {
				currentSong = cueFile.trackFromPos(pos);
				//Log.v(TAG, String.format("TRACK FROM POS %d => %d", pos, currentSong));
			}
			return currentSong;
		}
		
		if(id3Tag != null) {
			return id3Tag.getIntInfo(what);
		}
		
		return 0;
	}
	
	@Override
	public boolean setTune(int tune) {
		currentSong = tune;
		if(mediaPlayer != null && cueFile != null && currentSong >= 0) {
			mediaPlayer.seekTo(cueFile.getTrack(currentSong).offset);
		}
		return true;
	}

	@Override
	public String getStringInfo(int what) {
		switch(what) {
		case INFO_SUBTUNE_TITLE:
			if(cueFile != null && currentSong >= 0) {
				return cueFile.getTrack(currentSong).title;
			}
			break;
		case INFO_SUBTUNE_AUTHOR:
			if(cueFile != null && currentSong >= 0) {
				return cueFile.getTrack(currentSong).performer;
			}
			break;
		}
		if(id3Tag != null) {
			return id3Tag.getStringInfo(what);
		}

		return null;
	}

	@Override
	public int getSoundData(short[] dest, int size) {
		// TODO Auto-generated method stub
		
		if(!started) {
			mediaPlayer.start();
			started = true;
		}
		
		if(!mediaPlayer.isPlaying())
			return -1;
		
		return mediaPlayer.getCurrentPosition();
	}
	
	@Override
	public boolean seekTo(int msec) {
		mediaPlayer.seekTo(msec);
		return true;
	}


	@Override
	public boolean load(String name, byte[] module, int size) {
		currentSong = -1;
		return false;
	}

	@Override
	public boolean load(File file) throws IOException {
		currentSong = -1;
		try {
			Log.v(TAG, String.format("LOAD %s", file.getPath()));
			mediaPlayer = new MediaPlayer();
			mediaPlayer.setDataSource(file.getPath());
			mediaPlayer.prepare();
			id3Tag = new ID3Tag(file);
			
			
			int x = file.getPath().lastIndexOf('.');
			String cueName = file.getPath().substring(0, x) + ".cue";
			
			Log.v(TAG, String.format("CUENAME %s", cueName));
			currentSong = 0;
			cueFile = new CueFile(new File(cueName));
			if(cueFile.getTrackCount() <= 0) {
				cueFile = null;
			}
		} catch (IOException e) {
			return false;
		}
		
		// TODO Auto-generated method stub
		return true;
	}
	
	public boolean loadInfo(File file) throws IOException {
		
		Log.v(TAG, String.format("LoadInfo %s", file.getPath()));
		
		id3Tag = new ID3Tag(file);
		return true;
	}
	
	@Override
	public void unload() {
		// TODO Auto-generated method stub
		started = false;
		if(mediaPlayer != null) {
			mediaPlayer.stop();
			mediaPlayer.release();
			mediaPlayer = null;
		}	
		id3Tag = null;
	}
	
	@Override
	public MediaPlayer getMediaPlayer() {
		return mediaPlayer;
	}

}
