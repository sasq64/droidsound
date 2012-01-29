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
import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.async.Player;
import com.ssb.droidsound.utils.Log;

public class PlayingFragment extends Fragment {
	protected static final String TAG = PlayingFragment.class.getSimpleName();

	protected MyAdapter myAdapter;

	private ListView songInfoView;

	protected static class Entry {
		public final String key, value;

		public Entry(String key, String value) {
			this.key = key;
			this.value = value;
		}
	}

	protected void playButton(boolean enabled) {
		playButton.setVisibility(enabled ? View.VISIBLE : View.GONE);
		pauseButton.setVisibility(enabled ? View.GONE : View.VISIBLE);
	}

	protected class MyAdapter extends ArrayAdapter<Entry> {
		public MyAdapter(Context context) {
			super(context, 0);
		}

		@Override
		public int getViewTypeCount() {
			return 2;
		}

		@Override
		public int getItemViewType(int position) {
			Entry e = getItem(position);
			return e.key == null ? 0 : 1;
		}

		@Override
		public View getView(int position, View view, ViewGroup parent) {
			Entry e = getItem(position);
			if (view == null) {
				LayoutInflater li = getActivity().getLayoutInflater();
				if (e.key != null) {
					view = li.inflate(R.layout.songinfo_pair, null);
				} else {
					view = li.inflate(R.layout.songinfo_details, null);
				}
			}

			TextView key = (TextView) view.findViewById(R.id.key);
			if (key != null) {
				key.setText(e.key);
			}

			TextView value = (TextView) view.findViewById(R.id.value);
			value.setText(e.value);
			return view;
		}
	}

	protected String getString(String name) {
		try {
			return getString((Integer) R.string.class.getField(name).get(null));
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
	}

	protected String dateFormat(int date) {
		int year = date / 10000;
		int month = (date / 100) % 100;
		if (month != 0) {
			return String.format("%04d/%02d", year, month);
		} else {
			return String.valueOf(year);
		}
	}

	private final BroadcastReceiver songLoadingReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			myAdapter.clear();
			Bundle b = i.getExtras();

			myAdapter.add(new Entry(getString("file_title"), b.getString("file.title")));
			myAdapter.add(new Entry(getString("file_composer"), b.getString("file.composer")));
			if (b.getInt("file.date") > 19000000) {
				String date = dateFormat(b.getInt("file.date"));
				if (date != null) {
					myAdapter.add(new Entry(getString("file_date"), date));
				}
			}
			if (b.getInt("file.subsongs") > 0) {
				int cur = b.getInt("plugin.currentSubsongs");
				int max = b.getInt("file.subsongs");
				myAdapter.add(new Entry(getString("file_subsongs"), String.format("%d/%d", cur, max)));
			}

			myAdapter.add(new Entry(getString("plugin_name"), b.getString("plugin.name")));

			String[] di = b.getStringArray("plugin.detailedInfo");
			if (di != null) {
				String sv = "";
				for (String s : di) {
					sv += s + "\n";
				}
				myAdapter.add(new Entry(null, sv));
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

			Player.State state = (Player.State) intent.getSerializableExtra("state");
			if (state == Player.State.PLAY) {
				try {
					Application.playNext();
				} catch (Exception e) {
					Log.w(TAG, "Failed to auto-switch to next song");
				}
			}
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

			Application.seekTo(pos * 1000);
		}
	};

	protected SeekBar seekBar;

	protected TextView timeView;

	protected TextView lengthView;

	private ImageButton backButton;

	private ImageButton playButton;

	private ImageButton pauseButton;

	private ImageButton stopButton;

	private ImageButton forwardButton;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		getActivity().getApplicationContext().registerReceiver(songLoadingReceiver, new IntentFilter(Player.ACTION_LOADING_SONG));
		getActivity().getApplicationContext().registerReceiver(advancingReceiver, new IntentFilter(Player.ACTION_ADVANCING));
		getActivity().getApplicationContext().registerReceiver(songUnloadingReceiver, new IntentFilter(Player.ACTION_UNLOADING_SONG));
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
					Application.playPrev();
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
					Application.playPause(true);
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
					Application.playPause(false);
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
				Application.stop();
			}
		});
		forwardButton = (ImageButton) view.findViewById(R.id.button_forward);
		forwardButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				try {
					Application.playNext();
				} catch (Exception e) {
					Log.w(TAG, "Failed to play prev", e);
				}
			}
		});

		return view;
	}

}
