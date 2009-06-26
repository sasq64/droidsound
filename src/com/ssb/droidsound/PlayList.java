package com.ssb.droidsound;

import java.io.File;
import java.util.List;
import java.util.ListIterator;

import android.os.Environment;

public class PlayList {

	private List<Song> songList;
	
	public SongSequence getSongSequence() {
		return new SongSequence() {
			private ListIterator<Song> songIterator = songList.listIterator();						
			@Override
			public Song getNextSong(Song current) {
				return songIterator.next();
			}
			
		};
	}
	
	static PlayList fromFiles(String rootDir) {
		
		PlayList pl = new PlayList();
		
    	File modDir = new File(rootDir);    	
    	File [] files = modDir.listFiles();

		
		return pl;
	}

}
