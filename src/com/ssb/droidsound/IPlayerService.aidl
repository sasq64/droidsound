package com.ssb.droidsound;
import com.ssb.droidsound.IPlayerServiceCallback;


// @SuppressWarnings("unused")
interface IPlayerService {

	boolean playMod(String name);
	boolean playList(in String [] names, int startIndex);
	void playPrev();
	void playNext();
	void setFlags(int flags);
	boolean playPause(boolean play);
	boolean setSubSong(int song);
	boolean seekTo(int msec);
	void stop();
	
	void registerCallback(IPlayerServiceCallback cb, int flags);
}
