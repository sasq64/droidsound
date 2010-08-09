package com.ssb.droidsound.service;
import com.ssb.droidsound.service.IPlayerServiceCallback;


// @SuppressWarnings("unused")
interface IPlayerService {

	boolean playMod(String name);
	boolean playList(in String [] names, int startIndex);
	void playPrev();
	void playNext();
	void setOption(int opt, String arg);
	boolean playPause(boolean play);
	boolean setSubSong(int song);
	boolean seekTo(int msec);
	void stop();
	
	void registerCallback(IPlayerServiceCallback cb, int flags);
	void unRegisterCallback(IPlayerServiceCallback cb);
}
