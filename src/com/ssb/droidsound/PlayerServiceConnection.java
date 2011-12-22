package com.ssb.droidsound;

import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;

import com.ssb.droidsound.service.PlayerService;

public class PlayerServiceConnection implements ServiceConnection {
	protected PlayerService.LocalBinder mService;
	private PlayerService.IPlayerServiceCallback callback;

	@Override
	public void onServiceConnected(ComponentName name, IBinder service) {
		mService = (PlayerService.LocalBinder) service;
		mService.registerCallback(callback, 0);
	}

	@Override
	public void onServiceDisconnected(ComponentName name) {
		mService = null;
	}

	public void bindService(Activity activity, PlayerService.IPlayerServiceCallback callback) {
		this.callback = callback;
		activity.bindService(new Intent(activity, PlayerService.class), this, Context.BIND_AUTO_CREATE);
	}

	public void unbindService(Activity activity) {
		mService.unRegisterCallback(callback);
		activity.unbindService(this);
	}

	public boolean playMod(String name) {
		return mService.playMod(name);
	}

	public boolean playList(java.lang.String[] names, int startIndex) {
		return mService.playList(names, startIndex);
	}

	public boolean playPlaylist(String path, int index) {
		return mService.playPlaylist(path, index);
	}

	public void playPrev() {
		mService.playPrev();
	}

	public void playNext() {
		mService.playNext();
	}

	public void setOption(int opt, String arg) {
		mService.setOption(opt, arg);
	}

	public boolean playPause(boolean play) {
		return mService.playPause(play);
	}

	public boolean setSubSong(int song) {
		return mService.setSubSong(song);
	}
	public boolean seekTo(int msec) {
		return mService.seekTo(msec);
	}
	public void stop() {
		mService.stop();
	}

	public String[] getSongInfo() {
		return mService.getSongInfo();
	}

	public boolean dumpWav(String modName, String destFile, int length) {
		return mService.dumpWav(modName, destFile, length);
	}
}
