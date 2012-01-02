package com.ssb.droidsound.activity;

import android.app.Fragment;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.ssb.droidsound.R;
import com.ssb.droidsound.service.PlayerService;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.view.VisualizationView;

public class VisualizationFragment extends Fragment {
	protected static final String TAG = VisualizationFragment.class.getSimpleName();;

	protected VisualizationView visualizationView;

	private PlayerService.LocalBinder player;
	private final ServiceConnection playerConnection = new ServiceConnection() {
		@Override
		public void onServiceConnected(ComponentName tag, IBinder binder) {
			player = (PlayerService.LocalBinder) binder;
		}

		@Override
		public void onServiceDisconnected(ComponentName arg0) {
			player = null;
		}
	};

	private final BroadcastReceiver musicChangeReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context arg0, Intent arg1) {
			short[] data = player.getFftBuffer();
			Log.i(TAG, "Got array: " + data);
			visualizationView.setData(data);
		}
	};

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		getActivity().bindService(new Intent(getActivity(), PlayerService.class), playerConnection, Context.BIND_AUTO_CREATE);
		getActivity().getApplicationContext().registerReceiver(musicChangeReceiver, new IntentFilter(PlayerService.ACTION_LOADING_SONG));
	}

	@Override
	public void onDestroy() {
		super.onDestroy();
		getActivity().unbindService(playerConnection);
		getActivity().getApplicationContext().unregisterReceiver(musicChangeReceiver);
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		View view = inflater.inflate(R.layout.visualization_view, null);
		visualizationView = (VisualizationView) view.findViewById(R.id.visualization);
		return view;
	}
}
