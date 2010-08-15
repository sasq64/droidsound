package com.ssb.droidsound.service;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import android.util.Log;

import com.ssb.droidsound.Playlist;

public class PlayQueue {
	private static final String TAG = PlayQueue.class.getSimpleName();

	public static class Song {
		String filename;
		String title;
		String composer;
		int startSong;
		int playTime;
		
		//Song() {}
		Song(String fname) {
			filename = fname;
			startSong = -1;
		}
		public Song(Playlist.Song ps) {
			filename = ps.file.getPath();
			title = ps.title;
			startSong = ps.startsong;
			composer = ps.subtitle;
		}
		
		/* @Override
		public int hashCode() {
			return filename.hashCode();
		}
		
		@Override
		public boolean equals(Object o) {
			if(o instanceof String) {
				return filename.equals(o);
			} else
			if(o instanceof Song) {
				return filename.equals(((Song)o).filename);
			}
			return super.equals(o);
		} */
	}

	
	private static Random rgen = new Random(System.currentTimeMillis());

	private List<Song> musicList;
	private int musicListPos;
	private Song[] musicNames;

	private boolean shuffleOn;

	private Playlist currentPlaylist;

	private int oldPlaylistHash;

	
	PlayQueue(String [] names) {
		musicList = new ArrayList<Song>();
		init(createSongs(names), 0);
	}

	PlayQueue(String [] names, int index, boolean shuffleSongs) {
		musicList = new ArrayList<Song>();
		shuffleOn = shuffleSongs;
		init(createSongs(names), index);		
	}
	
	public PlayQueue(Playlist pl, int index, boolean shuffleSongs) {
		
		shuffleOn = shuffleSongs;
		currentPlaylist = pl;
		oldPlaylistHash = pl.hashCode();

		List<Playlist.Song> songs = currentPlaylist.getSongs();
		int i = 0;
		Song names [] = new Song [songs.size()];
		musicList = new ArrayList<Song>();
		Log.v(TAG, String.format("POS %d in playlist with %d files", index, songs.size()));
		for(Playlist.Song ps : songs) {
			Song song = new Song(ps);
			
			Log.v(TAG, String.format("%s (%d)", song.filename, song.startSong));
			
			names[i++] = song;
		}
		init(names, index);
	}

	private Song [] createSongs(String [] names) {
		Song [] songs = new Song [names.length];
		for(int i=0; i<names.length; i++) {
			songs[i] = new Song(names[i]);
		}
		return songs;
	}

	private void init(Song [] songs, int index) {
		musicNames = songs;
		musicListPos = index;
		if(musicNames != null) {
			for(int i=0; i<musicNames.length; i++) {
				musicList.add(musicNames[i]);
			}
			if(shuffleOn) {
				String current = musicNames[index].filename;
				shuffle();
				setCurrent(current);
			}
		}
	}
	
	
	public int setCurrent(String name) {
		for(int i=0; i<musicList.size(); i++) {
			if(musicList.get(i).filename.equals(name)) {
				musicListPos = i;
				return i;
			}
		}
		return -1;
	}
	
	
	void setShuffle(boolean on) {
		
		String current = current();
		if(on && !shuffleOn) {
			// Turned on
			shuffle();
		} else
		if(!on && shuffleOn) {
			// Turned off
			unshuffle();
			setCurrent(current);
		}
		
		shuffleOn = on;
	}
	
	private void shuffle() {
		if(musicNames == null) {
			return;
		}
		Song t;
		int sz = musicList.size();
		
		// Shuffle files before current playing
		for (int i=0; i<musicListPos; i++) {					
		    int randomPosition = rgen.nextInt(musicListPos);
		    t = musicList.get(i);
		    musicList.set(i, musicList.get(randomPosition));
		    musicList.set(randomPosition, t);
		}

		// Shuffle files after current playing
		int p = musicListPos + 1;
		for (int i=p; i<sz; i++) {					
		    int randomPosition = rgen.nextInt(sz-p) + p;
		    t = musicList.get(i);
		    musicList.set(i, musicList.get(randomPosition));
		    musicList.set(randomPosition, t);
		}
		
		Log.v(TAG, "###### SHUFFLE ORDER #####");
		for(Song s : musicList) {
			Log.v(TAG, s.filename);
		}
	}
	
	private void unshuffle() {
		
		if(musicNames != null) {
			Log.v(TAG, "Unshuffling");
			musicList.clear();
			for(int i=0; i<musicNames.length; i++) {
				musicList.add(musicNames[i]);
			}
		}
	}
	
	boolean songContains(List<Playlist.Song> psongs, Song s) {
		for(Playlist.Song ps : psongs) {
			//Log.v(TAG, String.format("%s(%d) vs %s(%d)", s.filename, s.startSong, ps.file.getPath(), ps.startsong));
			if(s.startSong == ps.startsong && s.filename.equals(ps.file.getPath())) {
				return true;
			}
		}
		return false;
	}

	boolean songContains(List<Song> songs, Playlist.Song ps) {		
		for(Song s : songs) {
			//Log.v(TAG, String.format("%s(%d) vs %s(%d)", s.filename, s.startSong, ps.file.getPath(), ps.startsong));
			if(s.startSong == ps.startsong && s.filename.equals(ps.file.getPath())) {
				return true;
			}
		}
		return false;
	}

	void updatePlaylist() {
        if(currentPlaylist != null) {
    		int hash = currentPlaylist.hashCode();
    		if(hash != oldPlaylistHash) {
    			Log.v(TAG, "Current playlist has changed!");    			
    			List<Playlist.Song> psongs = currentPlaylist.getSongs();
    			
    			
    			
    			String current = current();
    			boolean setNext = false;
				List<Song> removes = new ArrayList<Song>();
    			for(Song s : musicList) {
    				if(setNext) {
    					Log.v(TAG, "Removed current song, changing to " + s);
    					current = s.filename;
    					setNext = false;
    				}
    				if(!songContains(psongs, s)) {
    					Log.v(TAG, "Removing " + s.filename);    					
    					//musicList.remove(s);
    					removes.add(s);
    					if(s.equals(current)) {
    						setNext = true;
    					}
    				}
    			}
    			
    			for(Song s : removes) {
    				musicList.remove(s);
    			}
    			
    			for(Playlist.Song ps : psongs) {
    				if(!songContains(musicList, ps)) {
    					Log.v(TAG, "Adding " + ps.file.getPath());
    					musicList.add(new Song(ps));
    				}
    			}
    			
    			if(setCurrent(current) < 0) {
    				musicListPos = 0;
    			}    			
    		}
    		oldPlaylistHash = hash;
       	}
    }

	
	public String prev() {
		if(musicNames == null) {
			return null;
		}
		updatePlaylist();
		musicListPos--;
		if(musicListPos < 0) {
			musicListPos += musicList.size();
		}    		
		return musicList.get(musicListPos).filename;
	}
	
	public String next() {
		if(musicNames == null || musicNames.length < 2) {
			return null;
		}
		updatePlaylist();
		musicListPos++;
		if(musicListPos >= musicList.size()) {
			musicListPos -= musicList.size();
		}    	
		return musicList.get(musicListPos).filename;
	}
	
	public String current() { 
		if(musicNames == null) {
			return null;
		}
		return musicList.get(musicListPos).filename;
	}
	
	public int startSong() { 
		if(musicNames == null) {
			return -1;
		}
		return musicList.get(musicListPos).startSong;
	}

	
	public void setCurrent(int i) {		
		musicListPos = i;
	}

	public String currentWithStartSong() {
		if(musicNames == null) {
			return null;
		}
		String n =  musicList.get(musicListPos).filename;
		int s = musicList.get(musicListPos).startSong;
		if(s >= 0) {
			n = n + ";" + s;
		}
		return n;
	}	
}
