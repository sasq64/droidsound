package com.ssb.droidsound.service;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import android.util.Log;

import com.ssb.droidsound.Playlist;
import com.ssb.droidsound.SongFile;

public class PlayQueue {
	private static final String TAG = PlayQueue.class.getSimpleName();
/*
	public static class Song {
		String filename;
		String title;
		String composer;
		int startSong;
		int playTime;
		
		//SongFile() {}
		SongFile(String fname) {
			filename = fname;
			startSong = -1;
		}
		public SongFile(SongFile ps) {
			filename = ps.getFile().getPath();
			title = ps.getTitle();
			startSong = ps.getSubtune();
			composer = ps.getComposer();
		}
	}
*/		
		/* @Override
		public int hashCode() {
			return filename.hashCode();
		}
		
		@Override
		public boolean equals(Object o) {
			if(o instanceof String) {
				return filename.equals(o);
			} else
			if(o instanceof SongFile) {
				return filename.equals(((SongFile)o).filename);
			}
			return super.equals(o);
		} */

	
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
		Log.v(TAG, String.format("POS %d in playlist with %d files", index, songs.size()));
		for(SongFile ps : songs) {
			SongFile song = new SongFile(ps);
			
			// Log.v(TAG, String.format("%s (%d)", song.filename, song.startSong));
			
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
	
	
	public int setCurrent(String name) {
		for(int i=0; i<musicList.size(); i++) {
			Log.v(TAG, String.format("CMP %s to %s", musicList.get(i).getPath(), name));
			if(musicList.get(i).getPath().equals(name)) {
				musicListPos = i;
				return i;
			}
		}
		return -1;
	}
	
	
	void setShuffle(boolean on) {
		
		String current = currentWithStartSong();
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

		String current = currentWithStartSong();
		
		for (int i=0; i<sz; i++) {					
		    int randomPosition = rgen.nextInt(sz);
		    t = musicList.get(i);
		    musicList.set(i, musicList.get(randomPosition));
		    musicList.set(randomPosition, t);
		}

		setCurrent(current);

		/*
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
		} */
		
		// Log.v(TAG, "###### SHUFFLE ORDER #####");
		// for(SongFile s : musicList) {
		// 	Log.v(TAG, s.filename);
		// }
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
	
	boolean songContains(List<SongFile> psongs, SongFile s) {
		for(SongFile ps : psongs) {
			//Log.v(TAG, String.format("%s(%d) vs %s(%d)", s.filename, s.startSong, ps.file.getPath(), ps.startsong));
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
    			Log.v(TAG, "Current playlist has changed!");    			
    			List<SongFile> psongs = currentPlaylist.getSongs();
    			
    			
    			
    			String current = currentWithStartSong();
    			boolean setNext = false;
				List<SongFile> removes = new ArrayList<SongFile>();
    			for(SongFile s : musicList) {
    				if(setNext) {
    					Log.v(TAG, "Removed current song, changing to " + s);
    					current = s.getPath();
    					setNext = false;
    				}
    				if(!songContains(psongs, s)) {
    					Log.v(TAG, "Removing " + s.getPath());    					
    					//musicList.remove(s);
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
    					Log.v(TAG, "Adding " + ps.getFile().getPath());
    					musicList.add(new SongFile(ps));
    				}
    			}
    			
    			if(setCurrent(current) < 0) {
    				musicListPos = 0;
    			}
    			
    			SongFile[] newNames = new SongFile [musicList.size()];
    			int j = 0;
    			for(int i=0; i< musicNames.length; i++) {
    				SongFile ns = musicNames[i];
    				for(SongFile s : musicList) {
    					Log.v(TAG, String.format("%s(%d) vs %s(%d)", s.getName(), s.getSubtune(), ns.getName(), ns.getSubtune()));
    					if(s.getPath().equals(ns.getPath())) {
    						newNames[j++] = ns;
    						break;
    					}
    				}
    			}
    			
    			int s = musicList.size();
    			while(j < s) {
    				newNames[j] = musicList.get(j);
    				j++;
    			}
    			
    			musicNames = newNames;
    			Log.v(TAG, String.format("Size %d", j));
    		}
    		oldPlaylistHash = hash;
       	}
    }

	
	public String prev() {
		updatePlaylist();
		if(musicNames == null) {
			return null;
		}
		musicListPos--;
		if(musicListPos < 0) {
			musicListPos += musicList.size();
		}    		
		return musicList.get(musicListPos).getFile().getPath();
	}
	
	public String next() {
		updatePlaylist();
		if(musicNames == null || musicNames.length < 2) {
			return null;
		}
		musicListPos++;
		if(musicListPos >= musicList.size()) {
			musicListPos -= musicList.size();
		}    	
		return musicList.get(musicListPos).getFile().getPath();
	}
	
	public String current() { 
		if(musicNames == null || musicListPos < 0 || musicListPos >= musicList.size()) {
			return null;
		}
		return musicList.get(musicListPos).getFile().getPath();
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

	public String currentWithStartSong() {
		if(musicNames == null || musicListPos < 0 || musicListPos >= musicList.size()) {
			return null;
		}
		return musicList.get(musicListPos).getPath();
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
