package com.ssb.droidsound.service;

public interface PlayerInterface {

	boolean isActive();

	void stop();

	boolean playNextSong();

	boolean isPlaying();

	void paused(boolean b);

	boolean playPrevSong();

	void speechOnOff();

	int getCallState();

}
