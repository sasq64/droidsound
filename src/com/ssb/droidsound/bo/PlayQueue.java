package com.ssb.droidsound.bo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class PlayQueue {
	private final List<SongFile> musicListInOriginalOrder = new ArrayList<SongFile>();
	private final List<SongFile> musicList = new ArrayList<SongFile>();
	private int musicListPos;
	private boolean shuffle;

	public PlayQueue(String[] names, int index, boolean shuffle) {
		List<SongFile> tmp = new ArrayList<SongFile>();
		for (String fileName : names) {
			tmp.add(SongFile.fromFileName(fileName));
		}
		init(tmp, index, shuffle);
	}

	public PlayQueue(Playlist pl, int index, boolean shuffle) {
		init(pl.getSongs(), index, shuffle);
	}

	private void init(List<SongFile> songs, int index, boolean shuffle) {
		musicListInOriginalOrder.addAll(songs);
		musicList.addAll(songs);
		musicListPos = index;
		setShuffle(shuffle);
	}

	public void setShuffle(boolean on) {
		if (on && !shuffle) {
			SongFile c = getCurrent();
			Collections.shuffle(musicList);
			setCurrent(c);
		} else if (!on && shuffle) {
			SongFile c = getCurrent();
			musicList.clear();
			musicList.addAll(musicListInOriginalOrder);
			setCurrent(c);
		}
	}

	public SongFile prev() {
		musicListPos--;
		if (musicListPos < 0) {
			musicListPos += musicList.size();
		}
		return musicList.get(musicListPos);
	}

	public SongFile next() {
		musicListPos++;
		if (musicListPos >= musicList.size()) {
			musicListPos -= musicList.size();
		}
		return musicList.get(musicListPos);
	}

	public SongFile getCurrent() {
		if (musicListPos >= musicList.size()) {
			return null;
		}
		return musicList.get(musicListPos);
	}

	public int getCurrentStartSong() {
		if (musicListPos >= musicList.size()) {
			return -1;
		}
		return musicList.get(musicListPos).getSubtune();
	}

	public void setCurrent(int i) {
		musicListPos = i;
	}

	public int setCurrent(SongFile song) {
		musicListPos = musicList.indexOf(song);
		return musicListPos;
	}
}
