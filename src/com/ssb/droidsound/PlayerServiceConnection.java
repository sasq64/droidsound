package com.ssb.droidsound;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
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
	//private Callback callback;
	
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
			if(handler != null) {
				Message msg = handler.obtainMessage(what, value);
				handler.sendMessage(msg);
				//callback.stringChanged(what, value);
			}
		}

		@Override
		public void intChanged(int what, int value) throws RemoteException {
			if(handler != null) {
				Message msg = handler.obtainMessage(what, value, -1);
				handler.sendMessage(msg);
				//callback.stringChanged(what, value);
			}
		}
	};
	private boolean bound;
	private Handler handler;
	
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
		if(handler != null) {
			Message msg = handler.obtainMessage(999);
			handler.sendMessage(msg);
		}
	}

	public void bindService(Context ctx, Handler h) {
		handler = h;
		Log.d(TAG, "binding");
		Intent i = new Intent(ctx, PlayerService.class);
		bound = true;
		ctx.startService(i);
		ctx.bindService(i, this, Context.BIND_AUTO_CREATE);        		
	}

	public void unbindService(Context ctx) {
		Log.d(TAG, "Unbinding");
		handler = null;
		bound = false;
		if(mService != null) {
			try {
				mService.unRegisterCallback(mCallback);
			} catch (RemoteException e) {
				//throw new RuntimeException(e);
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
	

	public Map<String, Object> getSongInfo() {
		try {
			String[] s = mService.getSongInfo();
			return arrayToMap(s);
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}

	private Map<String, Object> arrayToMap(String[] s) {
		
		HashMap<String, Object> m = new HashMap<String, Object>();
		
		for(int i=0; i<s.length; i+=3) {
			
			String type = s[i];
			String key = s[i+1];
			String val = s[i+2];
			
			switch(type.charAt(0)) {
			case 'I':
				m.put(key,  Integer.parseInt(val));
				break;
			case 'A':
				m.put(key, val.split("\n"));
				break;
			case 'B':
				m.put(key, Boolean.parseBoolean(val));
				break;
			default:
				m.put(key, val);
				break;
			}
			
						
		}
		return m;
		
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
