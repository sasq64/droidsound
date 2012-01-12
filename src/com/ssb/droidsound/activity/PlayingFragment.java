package com.ssb.droidsound.activity;

import android.app.Fragment;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.SeekBar;
import android.widget.TextView;

import com.ssb.droidsound.R;
import com.ssb.droidsound.service.PlayerService;
import com.ssb.droidsound.utils.Log;

public class PlayingFragment extends Fragment {
	protected static final String TAG = PlayingFragment.class.getSimpleName();

	private MyAdapter myAdapter;

	private ListView songInfoView;

	protected static class Entry {
		public final String key, value;

		public Entry(String key, String value) {
			this.key = key;
			this.value = value;
		}
	}

	private void playButton(boolean enabled) {
		playButton.setVisibility(enabled ? View.VISIBLE : View.GONE);
		pauseButton.setVisibility(enabled ? View.GONE : View.VISIBLE);
	}

	protected class MyAdapter extends ArrayAdapter<Entry> {
		public MyAdapter(Context context) {
			super(context, 0);
		}

		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			if (convertView == null) {
				convertView = getActivity().getLayoutInflater().inflate(R.layout.songinfo_pair, null);
			}
			TextView key = (TextView) convertView.findViewById(R.id.key);
			TextView value = (TextView) convertView.findViewById(R.id.value);

			Entry e = getItem(position);
			key.setText(e.key);
			value.setText(e.value);
			return convertView;
		}
	}

	private final BroadcastReceiver songLoadingReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			myAdapter.clear();
			Bundle b = i.getExtras();
			for (String k : b.keySet()) {
				Object v = b.get(k);
				if (v == null) {
					continue;
				}
				Entry e = new Entry(k, String.valueOf(v));
				myAdapter.add(e);
			}

			int length = i.getIntExtra("subsong.length", 0);
			lengthView.setText(String.format("%d:%02d", length/60, length % 60));
			seekBar.setEnabled(i.getBooleanExtra("plugin.seekable", false));
			seekBar.setMax(length);

			playButton(false);
			myAdapter.notifyDataSetChanged();
		}
	};

	private final BroadcastReceiver advancingReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			int time = i.getIntExtra("time", 0);
			timeView.setText(String.format("%2d:%02d", time/60, time % 60));
			if (! seekBarDragging) {
				seekBar.setProgress(time);
			}
		}
	};

	private final BroadcastReceiver songUnloadingReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context context, Intent intent) {
			myAdapter.clear();
			timeView.setText("-:--");
			lengthView.setText("-:--");
			seekBar.setProgress(0);
			seekBar.setMax(1);
			playButton(true);
		}
	};
	protected boolean seekBarDragging;

	private final SeekBar.OnSeekBarChangeListener seekBarListener = new SeekBar.OnSeekBarChangeListener() {
		@Override
		public void onStopTrackingTouch(SeekBar arg0) {
			seekBarDragging = false;
		}

		@Override
		public void onStartTrackingTouch(SeekBar arg0) {
			seekBarDragging = true;
		}

		@Override
		public void onProgressChanged(SeekBar arg0, int pos, boolean user) {
			if (! user) {
				return;
			}

			((PlayerActivity) getActivity()).getPlayerService().seekTo(pos * 1000);
		}
	};

	private SeekBar seekBar;

	private TextView timeView;

	private TextView lengthView;

	private ImageButton backButton;

	private ImageButton playButton;

	private ImageButton pauseButton;

	private ImageButton stopButton;

	private ImageButton forwardButton;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		getActivity().getApplicationContext().registerReceiver(songLoadingReceiver, new IntentFilter(PlayerService.ACTION_LOADING_SONG));
		getActivity().getApplicationContext().registerReceiver(advancingReceiver, new IntentFilter(PlayerService.ACTION_ADVANCING));
		getActivity().getApplicationContext().registerReceiver(songUnloadingReceiver, new IntentFilter(PlayerService.ACTION_UNLOADING_SONG));
	}

	@Override
	public void onDestroy() {
		super.onDestroy();

		getActivity().getApplicationContext().unregisterReceiver(songLoadingReceiver);
		getActivity().getApplicationContext().unregisterReceiver(advancingReceiver);
		getActivity().getApplicationContext().unregisterReceiver(songUnloadingReceiver);
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
		View view = inflater.inflate(R.layout.playing_view, null);

		songInfoView = (ListView) view.findViewById(R.id.song_info_list);
		myAdapter = new MyAdapter(getActivity());
		songInfoView.setAdapter(myAdapter);

		timeView = (TextView) view.findViewById(R.id.time);
		timeView.setText("-:--");
		lengthView = (TextView) view.findViewById(R.id.length);
		lengthView.setText("-:--");
		seekBar = (SeekBar) view.findViewById(R.id.seek_bar);
		seekBar.setOnSeekBarChangeListener(seekBarListener);
		seekBar.setProgress(0);
		seekBar.setMax(1);

		backButton = (ImageButton) view.findViewById(R.id.button_back);
		backButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				try {
					((PlayerActivity) getActivity()).getPlayerService().playPrev();
				} catch (Exception e) {
					Log.w(TAG, "Failed to play prev", e);
				}
			}
		});
		playButton = (ImageButton) view.findViewById(R.id.button_play);
		playButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				try {
					((PlayerActivity) getActivity()).getPlayerService().playPause(true);
				} catch (Exception e) {
					Log.w(TAG, "Failed to start playing", e);
					return;
				}
				playButton(false);
			}
		});
		pauseButton = (ImageButton) view.findViewById(R.id.button_pause);
		pauseButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				try {
					((PlayerActivity) getActivity()).getPlayerService().playPause(false);
				} catch (Exception e) {
					Log.w(TAG, "Failed to pause playing", e);
					return;
				}
				playButton(true);
			}
		});
		stopButton = (ImageButton) view.findViewById(R.id.button_stop);
		stopButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				((PlayerActivity) getActivity()).getPlayerService().stop();
			}
		});
		forwardButton = (ImageButton) view.findViewById(R.id.button_forward);
		forwardButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				try {
					((PlayerActivity) getActivity()).getPlayerService().playNext();
				} catch (Exception e) {
					Log.w(TAG, "Failed to play prev", e);
				}
			}
		});

		return view;
	}

}
