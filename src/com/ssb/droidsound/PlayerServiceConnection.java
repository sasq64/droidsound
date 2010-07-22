package com.ssb.droidsound;

import com.ssb.droidsound.service.IPlayerService;
import com.ssb.droidsound.service.IPlayerServiceCallback;
import com.ssb.droidsound.service.PlayerService;

import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

public class PlayerServiceConnection implements ServiceConnection {
	private static final String TAG = PlayerServiceConnection.class.getSimpleName();

	public static interface Callback {
		public void stringChanged(int what, String value);
		public void intChanged(int what, int value);
	};
	
	protected IPlayerService mService;
	private Activity mActivity;
	private String modToPlay;
	private Callback callback;
	
	private IPlayerServiceCallback mCallback = new IPlayerServiceCallback.Stub() {

		@Override
		public void stringChanged(int what, String value) throws RemoteException {
			if(callback != null) {
				callback.stringChanged(what, value);
			}
		}

		@Override
		public void intChanged(int what, int value) throws RemoteException {
			if(callback != null) {
				callback.intChanged(what, value);
			}
		}
	};
	
	@Override
	public void onServiceConnected(ComponentName name, IBinder service) {
		mService = IPlayerService.Stub.asInterface(service);
		Log.v(TAG, "Service now bound");
		
		try {
			mService.registerCallback(mCallback, 0);
		} catch (RemoteException e) {
			throw new RuntimeException(e);
		}
		
		if(modToPlay != null) {
			playMod(modToPlay);
			modToPlay = null;
		}
	}

	@Override
	public void onServiceDisconnected(ComponentName name) {
		// TODO Auto-generated method stub
	}

	public void bindService(Activity activity, Callback cb) {
		mActivity = activity;
		callback = cb;

		Intent i = new Intent(activity, PlayerService.class);
		activity.startService(i);
		activity.bindService(i, this, Context.BIND_AUTO_CREATE);        		
	}

	public void unbindService() {
		if(mService != null) {
			mActivity.unbindService(this);
		}
	}

	public boolean playMod(String name) {
		if(mService == null) {
			modToPlay = name;
			return true;
		}
			
		try {
			return mService.playMod(name);
		} catch (RemoteException e) {
			return false;
		}
	}
	public boolean playList(java.lang.String[] names, int startIndex) {
		try {
			return mService.playList(names, startIndex);
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
	public void playPrev() {
		try {
			mService.playPrev();
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public void playNext() {
		try {
			mService.playNext();
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public void setFlags(int flags) {
	}
	public boolean playPause(boolean play) {
		try {
			return mService.playPause(play);
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
	public boolean setSubSong(int song) {
		try {
			return mService.setSubSong(song);
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
	public boolean seekTo(int msec) {
		return false;
	}
	public void stop() {
		try {
			mService.stop();
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
