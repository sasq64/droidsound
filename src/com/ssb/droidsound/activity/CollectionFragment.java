package com.ssb.droidsound.activity;

import java.io.File;

import android.app.AlertDialog;
import android.app.Fragment;
import android.app.FragmentTransaction;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.database.Cursor;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CursorAdapter;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.SearchView;
import android.widget.SimpleCursorAdapter;
import android.widget.TextView;

import com.ssb.droidsound.R;
import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.async.AsyncQueryResult;
import com.ssb.droidsound.async.Player;
import com.ssb.droidsound.async.Scanner;
import com.ssb.droidsound.bo.FilesEntry;
import com.ssb.droidsound.bo.Playlist;
import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.utils.Log;

public class CollectionFragment extends Fragment {
	protected static final String TAG = CollectionFragment.class.getSimpleName();
	protected static final int MENU_GROUP_DELETE = 1;
	protected static final int MENU_GROUP_ADD_TO_PLAYLIST = 2;
	protected static final int MENU_GROUP_REMOVE_FROM_PLAYLIST = 3;
	protected static final int MENU_GROUP_CREATE_PLAYLIST = 4;

	protected SearchView searchView;

	protected TextView progressPercentageView;

	protected FrameLayout progressContainerView;

	protected void navigateWithBackStack(String query) {
		Fragment f = new FastListFragment();
		Bundle b = new Bundle();
		b.putString("query", query);
		f.setArguments(b);

		FragmentTransaction ft = getFragmentManager().beginTransaction();
		ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_OPEN);
		ft.addToBackStack(null);
		ft.replace(R.id.collection_view, f);
		ft.commit();
	}

	protected void navigateWithBackStack(long parentId) {
		/* Move to subfolder */
		Fragment f = new FastListFragment();
		Bundle b = new Bundle();
		b.putLong("parentId", parentId);
		f.setArguments(b);

		FragmentTransaction ft = getFragmentManager().beginTransaction();
		ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_OPEN);
		ft.addToBackStack(null);
		ft.replace(R.id.collection_view, f);
		ft.commit();
	}

	@Override
	public boolean onContextItemSelected(MenuItem item) {
		final FilesEntry sf = Application.getSongDatabase().getSongFile(item.getItemId());

		switch (item.getGroupId()) {
		case MENU_GROUP_ADD_TO_PLAYLIST: {
			for (Playlist pl : Application.getSongDatabase().getPlaylistsList()) {
				if ((int) pl.getId() == item.getOrder()) {
					/* Avoid adding a file twice. */
					if (! pl.getSongs().contains(sf)) {
						pl.getSongs().add(sf);
					}
					pl.persist();
					Application.getSongDatabase().scan(false);
				}
			}

			return true;
		}

		case MENU_GROUP_REMOVE_FROM_PLAYLIST: {
			for (Playlist pl : Application.getSongDatabase().getPlaylistsList()) {
				if ((int) pl.getId() == item.getOrder()) {
					pl.getSongs().remove(sf);
					pl.persist();
					Application.getSongDatabase().scan(false);
				}
			}

			return true;
		}

		case MENU_GROUP_DELETE: {
			final File f = sf.getZipFilePath() != null ? sf.getZipFilePath() : sf.getFilePath();
			Log.i(TAG, "Confirm deletion of: %s", f.getPath());
			AlertDialog.Builder alert = new AlertDialog.Builder(getActivity());
			alert.setTitle(item.getTitle());
			alert.setMessage(R.string.confirm);
			alert.setNegativeButton(android.R.string.cancel, null);
			alert.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int whichButton) {
					f.delete();
					Application.getSongDatabase().scan(false);
				}
			});
			alert.create().show();
			return true;
		}

		default:
			return false;
		}
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		switch (item.getGroupId()) {
		case MENU_GROUP_CREATE_PLAYLIST: {
			AlertDialog.Builder alert = new AlertDialog.Builder(getActivity());
			alert.setTitle(R.string.create_playlist);

			final EditText nameField = new EditText(getActivity());
			alert.setView(nameField);

			alert.setNegativeButton(android.R.string.cancel, null);
			alert.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int whichButton) {
					String v = nameField.getText().toString();
					Playlist p = new Playlist(0, new File(Application.getModsDirectory(), v + ".plist"));
					p.persist();
					Application.getSongDatabase().scan(false);
				}
			});

			alert.create().show();
			return true;
		}

		default:
			return false;
		}
	}

	@Override
	public void onCreateOptionsMenu(Menu menu, android.view.MenuInflater inflater) {
		menu.add(MENU_GROUP_CREATE_PLAYLIST, Menu.NONE, Menu.NONE, R.string.create_playlist);
	}

	private final BroadcastReceiver searchReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			int progress = i.getIntExtra("progress", 0);
			progressPercentageView.setText(String.format("%d%%", progress));
			progressContainerView.setVisibility(i.getBooleanExtra("scanning", false) ? View.VISIBLE : View.GONE);
		}
	};

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setHasOptionsMenu(true);
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle state) {
		Log.i(TAG, "Creating view");

		View view = inflater.inflate(R.layout.collection_view, null);
		progressContainerView = (FrameLayout) view.findViewById(R.id.progress_container);
		progressPercentageView = (TextView) view.findViewById(R.id.progress_percentage);
		searchView = (SearchView) view.findViewById(R.id.search);

		progressContainerView.setVisibility(View.GONE);

		searchView.setOnSuggestionListener(new SearchView.OnSuggestionListener() {
			@Override
			public boolean onSuggestionSelect(int position) {
				return false;
			}

			@Override
			public boolean onSuggestionClick(int position) {
				CursorAdapter ca = searchView.getSuggestionsAdapter();
				Cursor c = ca.getCursor();
				c.moveToPosition(position);
				long childId = c.getLong(SongDatabase.COL_ID);
				FilesEntry fe = Application.getSongDatabase().getSongFile(childId);
				try {
					Application.playMod(fe);
				} catch (Exception e) {
					Log.w(TAG, "Can't play song from selection", e);
				}
				return true;
			}
		});

		searchView.setOnQueryTextListener(new SearchView.OnQueryTextListener() {
			@Override
			public boolean onQueryTextSubmit(final String query) {
				if (! "".equals(query)) {
					navigateWithBackStack(query);
					return true;
				}

				return false;
			}

			@Override
			public boolean onQueryTextChange(final String newText) {
				/* Remove adapter to hide obsolete result sets.
				 * Would be lovely to be able to interrupt any previous
				 * query, but that does not strike as possible to me. */
				searchView.setSuggestionsAdapter(null);

				if (newText.length() < 3) {
					return false;
				}

				/* We should probably ratelimit the asynctask spam we can cause.
				 * Ideally we'd maintain an internal queue here. I'll just spam them for now. */
				Log.i(TAG, "Firing a new suggestions scan for: '%s'", newText);
				Cursor c = Application.getSongDatabase().search(newText, SongDatabase.Sort.TITLE);
				CursorAdapter ca = new SimpleCursorAdapter(
						getActivity(),
						android.R.layout.simple_list_item_2,
						null,
						new String[] { "title", "composer" },
						new int[] { android.R.id.text1, android.R.id.text2 }
				);
				searchView.setSuggestionsAdapter(ca);
				new AsyncQueryResult(c, ca).executeOnExecutor(AsyncTask.SERIAL_EXECUTOR);
				return true;
			}
		});

		/* Restore list fragment */
		Fragment topFragment = getFragmentManager().findFragmentById(R.id.collection_view);
		if (topFragment == null) {
			Fragment f = new FastListFragment();
			f.setArguments(new Bundle());
			FragmentTransaction ft = getFragmentManager().beginTransaction();
			ft.add(R.id.collection_view, f);
			ft.commit();
		}

		IntentFilter intentFilter = new IntentFilter();
		intentFilter.addAction(Player.ACTION_LOADING_SONG);
		intentFilter.addAction(Player.ACTION_UNLOADING_SONG);
		getActivity().registerReceiver(searchReceiver, new IntentFilter(Scanner.ACTION_SCAN));

		return view;
	}

	@Override
	public void onDestroyView() {
		super.onDestroyView();
		getActivity().unregisterReceiver(searchReceiver);
	}
}
