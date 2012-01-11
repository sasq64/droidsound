package com.ssb.droidsound.bo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class PlayQueue {
	private final List<FilesEntry> musicListInOriginalOrder = new ArrayList<FilesEntry>();
	private final List<FilesEntry> musicList = new ArrayList<FilesEntry>();
	private int musicListPos;
	private boolean shuffle;

	public PlayQueue(List<FilesEntry> songs, int index, boolean shuffle) {
		musicListInOriginalOrder.addAll(songs);
		musicList.addAll(songs);
		musicListPos = index;
		setShuffle(shuffle);
	}

	public void setShuffle(boolean on) {
		if (on && !shuffle) {
			FilesEntry c = getCurrent();
			Collections.shuffle(musicList);
			setCurrent(c);
		} else if (!on && shuffle) {
			FilesEntry c = getCurrent();
			musicList.clear();
			musicList.addAll(musicListInOriginalOrder);
			setCurrent(c);
		}
	}

	public FilesEntry prev() {
		musicListPos--;
		if (musicListPos < 0) {
			musicListPos += musicList.size();
		}
		return musicList.get(musicListPos);
	}

	public FilesEntry next() {
		musicListPos++;
		if (musicListPos >= musicList.size()) {
			musicListPos -= musicList.size();
		}
		return musicList.get(musicListPos);
	}

	public FilesEntry getCurrent() {
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

	public int setCurrent(FilesEntry song) {
		musicListPos = musicList.indexOf(song);
		return musicListPos;
	}
}
