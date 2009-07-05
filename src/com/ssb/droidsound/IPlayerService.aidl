package com.ssb.droidsound;
import com.ssb.droidsound.IPlayerServiceCallback;


// @SuppressWarnings("unused")
interface IPlayerService {

	boolean playMod(String name);
	boolean playList(String name, int startIndex);
	void setFlags(int flags);
	void playPause(boolean play);
	boolean setSubSong(int song);
	boolean seekTo(int msec);
	void stop();
	
	void registerCallback(IPlayerServiceCallback cb, int flags);
}
