package com.ssb.droidsound;

import java.util.ArrayList;
import java.util.List;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.os.RemoteException;

import com.ssb.droidsound.service.IPlayerService;
import com.ssb.droidsound.service.IPlayerServiceCallback;
import com.ssb.droidsound.service.PlayerService;
import com.ssb.droidsound.utils.Log;

public class PlayerServiceConnection implements ServiceConnection {
	private static final String TAG = PlayerServiceConnection.class.getSimpleName();

	public static interface Callback {
		public void stringChanged(int what, String value);
		public void intChanged(int what, int value);
	};
	
	protected IPlayerService mService;
	private String modToPlay;
	private Callback callback;
	
	private static class Opt {
		int opt;
		String arg;
		public Opt(int o, String a) {
			opt = o;
			arg = a;
		}
	};
	
	private List<Opt> options = new ArrayList<Opt>();
	
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
	private boolean bound;
	
	@Override
	public void onServiceConnected(ComponentName name, IBinder service) {
		mService = IPlayerService.Stub.asInterface(service);
		if(bound) {
			Log.d(TAG, "Service Connected");
		} else {
			Log.d(TAG, "Service Connected, but was unbound in the meantime");
			return;
		}

		try {
			mService.registerCallback(mCallback, 0);
		} catch (RemoteException e) {
			throw new RuntimeException(e);
		}
		
		for(Opt o : options) {
			setOption(o.opt, o.arg);
		}
		options.clear();

		if(modToPlay != null) {
			playMod(modToPlay);
			modToPlay = null;
		}
	}

	@Override
	public void onServiceDisconnected(ComponentName name) {
		Log.d(TAG, "Service Disconnected!");
	}

	public void bindService(Context ctx, Callback cb) {
		callback = cb;
		Log.d(TAG, "binding");
		Intent i = new Intent(ctx, PlayerService.class);
		bound = true;
		ctx.startService(i);
		ctx.bindService(i, this, Context.BIND_AUTO_CREATE);        		
	}

	public void unbindService(Context ctx) {
		Log.d(TAG, "Unbinding");
		callback = null;
		bound = false;
		if(mService != null) {
			try {
				mService.unRegisterCallback(mCallback);
			} catch (RemoteException e) {
				throw new RuntimeException(e);
			}
		}
		ctx.unbindService(this);
	}
	/*
	public int getInt(int what) {
		try {
			return mService.getInt(what);
		} catch (RemoteException e) {
			return -1;
		}
	} */

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
	public boolean playPlaylist(String path, int index) {
		try {
			return mService.playPlaylist(path, index);
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
	public void setOption(int opt, String arg) {
		
		if(mService == null) {
			options.add(new Opt(opt, arg));
			return;
		}
		
		try {
			mService.setOption(opt, arg);
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
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
		try {
			return mService.seekTo(msec);
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
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
	
	public String [] getSongInfo() {
		try {
			return mService.getSongInfo();
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}

	public byte [] getSongMD5() {
		try {
			return mService.getSongMD5();
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}

	public boolean dumpWav(String modName, String destFile, int length, int flags) {
		try {
			return mService.dumpWav(modName, destFile, length, flags);
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
	
	

}
