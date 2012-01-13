package com.ssb.droidsound.activity;

import java.util.Queue;

import android.app.Fragment;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.ssb.droidsound.R;
import com.ssb.droidsound.service.PlayerService;
import com.ssb.droidsound.utils.OverlappingFFT;
import com.ssb.droidsound.view.VisualizationInfoView;
import com.ssb.droidsound.view.VisualizationView;

public class VisualizationFragment extends Fragment {
	protected static final String TAG = VisualizationFragment.class.getSimpleName();

	private VisualizationInfoView visualizationInfoView;

	protected VisualizationView visualizationView;

	private final BroadcastReceiver musicChangeReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			Queue<OverlappingFFT.Data> data = null;
			if (i.getAction().equals(PlayerService.ACTION_LOADING_SONG)) {
				data = ((PlayerActivity) getActivity()).getPlayerService().enableFftQueue();
			}
			visualizationView.setData(data);
		}
	};

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		View view = inflater.inflate(R.layout.visualization_view, null);
		visualizationInfoView = (VisualizationInfoView) view.findViewById(R.id.visualization_info);
		visualizationView = (VisualizationView) view.findViewById(R.id.visualization);
		visualizationView.setColors(visualizationInfoView.getColors());

		IntentFilter intentFilter = new IntentFilter();
		intentFilter.addAction(PlayerService.ACTION_LOADING_SONG);
		intentFilter.addAction(PlayerService.ACTION_UNLOADING_SONG);
		getActivity().registerReceiver(musicChangeReceiver, intentFilter);

		Queue<OverlappingFFT.Data> data = ((PlayerActivity) getActivity()).getPlayerService().enableFftQueue();
		visualizationView.setData(data);

		return view;
	}

	@Override
	public void onDestroyView() {
		super.onDestroyView();
		getActivity().unregisterReceiver(musicChangeReceiver);
		((PlayerActivity) getActivity()).getPlayerService().disableFftQueue();
	}
}
