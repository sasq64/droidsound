package com.ssb.droidsound.activity;

import android.app.Fragment;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.media.audiofx.AudioEffect;
import android.media.audiofx.Visualizer;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.ssb.droidsound.R;
import com.ssb.droidsound.view.VisualizationView;

public class VisualizationFragment extends Fragment {
	public static final String ACTION_DATA = "com.ssb.droidsound.DATA";

	private final BroadcastReceiver musicDataReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			String a = i.getAction();
			if (a.equals(AudioEffect.ACTION_OPEN_AUDIO_EFFECT_CONTROL_SESSION)) {
				Visualizer v = new Visualizer(i.getIntExtra(AudioEffect.EXTRA_AUDIO_SESSION, 0));
				visualizationView.setVisualizer(v);
				return;
			}
			if (a.equals(AudioEffect.ACTION_CLOSE_AUDIO_EFFECT_CONTROL_SESSION)) {
				Visualizer v = visualizationView.getVisualizer();
				if (v != null) {
					v.setEnabled(false);
					v.release();
					visualizationView.setVisualizer(null);
				}
			}
		}
	};

	protected VisualizationView visualizationView;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		IntentFilter intentFilter = new IntentFilter();
		intentFilter.addAction(AudioEffect.ACTION_OPEN_AUDIO_EFFECT_CONTROL_SESSION);
		intentFilter.addAction(AudioEffect.ACTION_CLOSE_AUDIO_EFFECT_CONTROL_SESSION);
		getActivity().getApplicationContext().registerReceiver(musicDataReceiver, intentFilter);
	}

	@Override
	public void onDestroy() {
		super.onDestroy();
		getActivity().getApplicationContext().unregisterReceiver(musicDataReceiver);
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		View view = inflater.inflate(R.layout.visualization_view, null);
		visualizationView = (VisualizationView) view.findViewById(R.id.visualization);
		return view;
	}
}
