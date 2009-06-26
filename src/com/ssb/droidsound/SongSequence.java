package com.ssb.droidsound;

/*
 * A SongSequence is a set of songs, and a way to iterate through them
 */
public interface SongSequence {
	
	Song getNextSong(Song current);
}
