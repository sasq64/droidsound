package com.ssb.droidsound;

import android.content.BroadcastReceiver;
import android.database.sqlite.SQLiteDatabase;

public class PlayState {
	public int seekingSong;
	public int sortOrder;
	public int songPos;
	public int subTune;
	public int subTuneCount;
	public int songLength;
	public SongFile songFile;
	public BroadcastReceiver receiver;
	public SQLiteDatabase db;
	public String songTitle;
	public String songComposer;
	public String dirTitle;
	public String dirSubTitle;
	public String[] songDetails;
	public int ttsStatus;
	public int songState;
	public SongFile operationSong;
	public boolean shuffleSongs;
	public int songRepeat;
	public String subtuneTitle;
	public String subtuneAuthor;
	public String operationTitle;
	public int operationTuneCount;
	public SongFile clipBoardFile;

	public PlayState() {
	}
}