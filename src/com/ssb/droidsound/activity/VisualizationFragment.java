package com.ssb.droidsound.activity;

import java.util.Queue;

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
import com.ssb.droidsound.utils.OverlappingFFT;
import com.ssb.droidsound.view.VisualizationInfoView;
import com.ssb.droidsound.view.VisualizationView;

public class VisualizationFragment extends Fragment {
	protected static final String TAG = VisualizationFragment.class.getSimpleName();;

	private VisualizationInfoView visualizationInfoView;

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
		public void onReceive(Context c, Intent i) {
			Queue<OverlappingFFT.Data> data = null;
			if (i.getAction().equals(PlayerService.ACTION_LOADING_SONG)) {
				data = player.getFftQueue();
			}
			visualizationView.setData(data);
		}
	};

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		getActivity().bindService(new Intent(getActivity(), PlayerService.class), playerConnection, Context.BIND_AUTO_CREATE);
		IntentFilter intentFilter = new IntentFilter();
		intentFilter.addAction(PlayerService.ACTION_LOADING_SONG);
		intentFilter.addAction(PlayerService.ACTION_UNLOADING_SONG);
		getActivity().getApplicationContext().registerReceiver(musicChangeReceiver, intentFilter);
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
		visualizationInfoView = (VisualizationInfoView) view.findViewById(R.id.visualization_info);
		visualizationView = (VisualizationView) view.findViewById(R.id.visualization);
		visualizationView.setColors(visualizationInfoView.getColors());
		return view;
	}
}
