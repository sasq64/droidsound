package com.ssb.droidsound.service;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import com.ssb.droidsound.utils.Log;

import com.ssb.droidsound.Playlist;
import com.ssb.droidsound.SongFile;

public class PlayQueue {
	private static final String TAG = PlayQueue.class.getSimpleName();
	
	private static Random rgen = new Random(System.currentTimeMillis());

	private List<SongFile> musicList;
	private int musicListPos;
	private SongFile[] musicNames;

	private boolean shuffleOn;

	private Playlist currentPlaylist;

	private int oldPlaylistHash;

	
	PlayQueue(String [] names) {
		musicList = new ArrayList<SongFile>();
		init(createSongs(names), 0);
	}

	PlayQueue(String [] names, int index, boolean shuffleSongs) {
		musicList = new ArrayList<SongFile>();
		shuffleOn = shuffleSongs;
		init(createSongs(names), index);		
	}
	
	public PlayQueue(Playlist pl, int index, boolean shuffleSongs) {
		
		shuffleOn = shuffleSongs;
		currentPlaylist = pl;
		oldPlaylistHash = pl.hashCode();

		List<SongFile> songs = currentPlaylist.getSongs();
		int i = 0;
		SongFile names [] = new SongFile [songs.size()];
		musicList = new ArrayList<SongFile>();
		Log.d(TAG, "POS %d in playlist with %d files", index, songs.size());
		for(SongFile ps : songs) {
			SongFile song = new SongFile(ps);
			
			// Log.d(TAG, "%s (%d)", song.filename, song.startSong);
			
			names[i++] = song;
		}
		init(names, index);
	}

	private SongFile [] createSongs(String [] names) {
		SongFile [] songs = new SongFile [names.length];
		for(int i=0; i<names.length; i++) {
			songs[i] = new SongFile(names[i]);
		}
		return songs;
	}

	private void init(SongFile [] songs, int index) {
		musicNames = songs;
		musicListPos = index;
		if(musicNames != null) {
			for(int i=0; i<musicNames.length; i++) {
				musicList.add(musicNames[i]);
			}
			if(shuffleOn) {
				shuffle();
			}
		}
	}

	void setShuffle(boolean on) {
		
		SongFile current = current();
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
		SongFile t;
		int sz = musicList.size();

		SongFile current = current();
		
		for (int i=0; i<sz; i++) {					
		    int randomPosition = rgen.nextInt(sz);
		    t = musicList.get(i);
		    musicList.set(i, musicList.get(randomPosition));
		    musicList.set(randomPosition, t);
		}

		setCurrent(current);
	}
	
	private void unshuffle() {
		
		if(musicNames != null) {
			Log.d(TAG, "Unshuffling");
			musicList.clear();
			for(int i=0; i<musicNames.length; i++) {
				musicList.add(musicNames[i]);
			}
		}
	}
	
	boolean songContains(List<SongFile> psongs, SongFile s) {
		for(SongFile ps : psongs) {
			//Log.d(TAG, "%s(%d) vs %s(%d)", s.filename, s.startSong, ps.file.getPath(), ps.startsong);
			if(s.getPath().equals(ps.getPath())) {
				return true;
			}
		}
		return false;
	}

	void updatePlaylist() {
        if(currentPlaylist != null) {
    		int hash = currentPlaylist.hashCode();
    		if(hash != oldPlaylistHash) {
    			Log.d(TAG, "Current playlist has changed!");    			
    			List<SongFile> psongs = currentPlaylist.getSongs();
    			
    			musicNames = new SongFile [psongs.size()]; 
    			int i = 0;
    			for(SongFile sf : psongs) {
    				musicNames[i++] = new SongFile(sf);
    			}
    			
    			SongFile current = current();
    			boolean setNext = false;
				List<SongFile> removes = new ArrayList<SongFile>();
    			for(SongFile s : musicList) {
    				if(setNext) {
    					Log.d(TAG, "Removed current song, changing to " + s);
    					current = s;
    					setNext = false;
    				}
    				if(!songContains(psongs, s)) {
    					Log.d(TAG, "Removing " + s.getPath());    					

    					removes.add(s);
    					if(s.getPath().equals(current)) {
    						setNext = true;
    					}
    				}
    			}
    			
    			for(SongFile s : removes) {
    				musicList.remove(s);
    			}
    			
    			for(SongFile ps : psongs) {
    				if(!songContains(musicList, ps)) {
    					Log.d(TAG, "Adding " + ps.getFile().getPath());
    					musicList.add(new SongFile(ps));
    				}
    			}
    			
    			if(current == null || setCurrent(current) < 0) {
    				musicListPos = 0;
    			}

    		}
    		oldPlaylistHash = hash;
       	}
    }


	public SongFile prev() {
		updatePlaylist();
		if(musicNames == null) {
			return null;
		}
		musicListPos--;
		if(musicListPos < 0) {
			musicListPos += musicList.size();
		}    		
		return musicList.get(musicListPos);
	}
	
	public SongFile next() {
		updatePlaylist();
		if(musicNames == null || musicNames.length < 2) {
			return null;
		}
		musicListPos++;
		if(musicListPos >= musicList.size()) {
			musicListPos -= musicList.size();
		}    	
		return musicList.get(musicListPos);
	}
	
	public SongFile current() { 
		if(musicNames == null || musicListPos < 0 || musicListPos >= musicList.size()) {
			return null;
		}
		return musicList.get(musicListPos);
	}
	
	public int startSong() { 
		if(musicNames == null || musicListPos < 0 || musicListPos >= musicList.size()) {
			return -1;
		}
		return musicList.get(musicListPos).getSubtune();
	}

	
	public void setCurrent(int i) {		
		musicListPos = i;
	}

	public int setCurrent(SongFile song) {
		for(int i=0; i<musicList.size(); i++) {
			//Log.d(TAG, "CMP %s to %s", musicList.get(i).getPath(), song.getPath());
			if(musicList.get(i).getPath().equals(song.getPath())) {
				musicListPos = i;
				return i;
			}
		}
		return -1;
	}
	

	public SongFile getNextSong() {
		updatePlaylist();
		if(musicNames == null || musicNames.length < 2) {
			return null;
		}
		int i = musicListPos+1;
		if(i >= musicList.size()) {
			i -= musicList.size();
		}    	
		return musicList.get(i);
	}	

	public SongFile getPrevSong() {
		updatePlaylist();
		if(musicNames == null || musicNames.length < 2) {
			return null;
		}
		int i = musicListPos-1;
		if(i < 0) {
			i += musicList.size();
		}    	
		return musicList.get(i);
	}	
}
