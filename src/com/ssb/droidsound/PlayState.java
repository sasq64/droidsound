package com.ssb.droidsound;

import java.util.Map;

import android.content.BroadcastReceiver;
import android.database.sqlite.SQLiteDatabase;

public class PlayState {
	public int seekingSong;
	public int sortOrderSearch;
	public int sortOrderPlayList;
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
	public Map<String, Object> songDetails;
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
	public boolean songSelected;
	public boolean playerSwitch;
	public String songSource;
	public int buffering;

	public PlayState() {
	}
}