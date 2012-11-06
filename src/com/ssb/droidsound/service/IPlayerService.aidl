package com.ssb.droidsound.service;
import com.ssb.droidsound.service.IPlayerServiceCallback;


// @SuppressWarnings("unused")
interface IPlayerService {

	boolean playMod(String name);
	boolean playList(in String [] names, int startIndex);
	boolean playPlaylist(in String name, int startIndex);
	void playPrev();
	void playNext();
	void setOption(int opt, String arg);
	boolean playPause(boolean play);
	boolean setSubSong(int song);
	boolean seekTo(int msec);
	void stop();
	
	boolean dumpWav(String modName, String destFile, int length, int flags);
	
	String [] getSongInfo();

	byte [] getBinaryData(int what);
	
	void registerCallback(IPlayerServiceCallback cb, int flags);
	void unRegisterCallback(IPlayerServiceCallback cb);
}
