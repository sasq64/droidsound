package com.ssb.droidsound;
import com.ssb.droidsound.IPlayerServiceCallback;

interface IPlayerService {

	void playMod(String name);
	void playList(String fileName);
	void playPause(boolean play);
	void seekTo(int msec);
	void stop();
	
	String getStringValue(int what);
	int getIntValue(int what);
	void registerCallback(IPlayerServiceCallback cb, int flags);
}
