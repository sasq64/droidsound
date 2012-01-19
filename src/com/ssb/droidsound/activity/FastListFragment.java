package com.ssb.droidsound.activity;

import android.app.ListFragment;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.os.Bundle;
import android.view.View;

import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.async.Player;
import com.ssb.droidsound.async.Scanner;
import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.utils.Log;

public class FastListFragment extends ListFragment {
	public interface ICursorFactory {
		public Cursor getCursor();
	}

	protected static SongDatabase.Sort getSorting() {
		SharedPreferences prefs = Application.getAppPreferences();
		String sorting = prefs.getString("sorting", "TITLE");
		return SongDatabase.Sort.valueOf(sorting);
	}

	private final BroadcastReceiver songChangeReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			Log.i(CollectionFragment.TAG, "Song change received, redisplaying");
			CollectionViewAdapter listAdapter = (CollectionViewAdapter) getListAdapter();
			if (listAdapter != null) {
				listAdapter.notifyDataSetChanged();
			}
		}
	};

	private final BroadcastReceiver updateReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			if (i.getIntExtra("progress", 0) == 100) {
				CollectionViewAdapter listAdapter = (CollectionViewAdapter) getListAdapter();
				if (listAdapter != null) {
					listAdapter.requery();
				}
			}
		}
	};

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		Bundle args = getArguments();

		final ICursorFactory icf;
		if (args.containsKey("query")) {
			final String query = args.getString("query");
			icf = new ICursorFactory() {
				@Override
				public Cursor getCursor() {
					return Application.getSongDatabase().search(query, getSorting());
				}
			};
		} else if (args.containsKey("parentId")) {
			final long parentId = args.getLong("parentId");
			icf = new ICursorFactory() {
				@Override
				public Cursor getCursor() {
					return Application.getSongDatabase().getFilesByParentId(parentId, getSorting());
				}
			};
		} else {
			icf = new ICursorFactory() {
				@Override
				public Cursor getCursor() {
					return Application.getSongDatabase().getFilesByParentId(null, getSorting());
				}
			};
		}

		CollectionViewAdapter cva = new CollectionViewAdapter(getActivity(), icf);
		setListAdapter(cva);
	}

	@Override
	public void onViewCreated(View view, Bundle savedInstanceState) {
		super.onViewCreated(view, savedInstanceState);
		getListView().setFastScrollEnabled(true);
		IntentFilter intentFilter = new IntentFilter();
		intentFilter.addAction(Player.ACTION_LOADING_SONG);
		intentFilter.addAction(Player.ACTION_UNLOADING_SONG);
		getActivity().registerReceiver(songChangeReceiver, intentFilter);
		getActivity().registerReceiver(updateReceiver, new IntentFilter(Scanner.ACTION_SCAN));
	}

	@Override
	public void onDestroyView() {
		super.onDestroyView();
		getActivity().unregisterReceiver(songChangeReceiver);
		getActivity().unregisterReceiver(updateReceiver);
	}
}