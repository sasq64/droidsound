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

	private PlayerService.LocalBinder player;

	private MyAdapter myAdapter;

	private ListView songInfoView;

	protected static class Entry {
		public final String key, value;

		public Entry(String key, String value) {
			this.key = key;
			this.value = value;
		}
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

	private final BroadcastReceiver songLoadingReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			myAdapter.clear();
			Bundle b = i.getExtras();
			for (String k : b.keySet()) {
				Object v = b.get(k);
				Log.i(TAG, "Received metadata: %s: %s", k, v);
				if (v == null) {
					continue;
				}
				Entry e = new Entry(k, String.valueOf(v));
				myAdapter.add(e);
			}
			myAdapter.notifyDataSetChanged();
		}
	};

	private final BroadcastReceiver advancingReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			String a = i.getAction();
			if (a.equals(PlayerService.ADVANCING)) {
				int time = i.getIntExtra("time", 0);
				timeView.setText(String.format("%2d:%02d", time/60, time % 60));
				int length = i.getIntExtra("length", 0);
				lengthView.setText(String.format("%d:%02d", length/60, length % 60));
				if (! seekBarDragging) {
					seekBar.setProgress(time);
					seekBar.setMax(length);
				}
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

			player.seekTo(pos * 1000);
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
	public void onStart() {
		super.onStart();


		getActivity().registerReceiver(songLoadingReceiver, new IntentFilter(PlayerService.LOADING_SONG));
		getActivity().registerReceiver(advancingReceiver, new IntentFilter(PlayerService.ADVANCING));
		getActivity().registerReceiver(songUnloadingReceiver, new IntentFilter(PlayerService.UNLOADING_SONG));
		getActivity().bindService(new Intent(getActivity(), PlayerService.class), playerConnection, Context.BIND_AUTO_CREATE);
	}

	@Override
	public void onStop() {
		super.onStop();
		getActivity().unregisterReceiver(songLoadingReceiver);
		getActivity().unregisterReceiver(advancingReceiver);
		getActivity().unregisterReceiver(songUnloadingReceiver);
		getActivity().unbindService(playerConnection);
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
					player.playPrev();
				} catch (Exception e) {
					Log.w(TAG, "Failed to play prev", e);
				}
			}
		});
		playButton = (ImageButton) view.findViewById(R.id.button_play);
		playButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				player.playPause(true);
			}
		});
		pauseButton = (ImageButton) view.findViewById(R.id.button_pause);
		pauseButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				player.playPause(false);
			}
		});
		stopButton = (ImageButton) view.findViewById(R.id.button_stop);
		stopButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				player.stop();
			}
		});
		forwardButton = (ImageButton) view.findViewById(R.id.button_forward);
		forwardButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				try {
					player.playNext();
				} catch (Exception e) {
					Log.w(TAG, "Failed to play prev", e);
				}
			}
		});

		return view;
	}

}
