package com.ssb.droidsound.service;

public interface PlayerInterface {

	boolean isActive();

	void stop();

	boolean playNextSong();
	boolean playNextSong(int skips);
	public boolean playNextFile();
	public boolean playPrevFile();

	boolean isPlaying();

	void paused(boolean b);

	boolean playPrevSong();
	boolean playPrevSong(int skips);

	void speechOnOff();

	int getCallState();

}
