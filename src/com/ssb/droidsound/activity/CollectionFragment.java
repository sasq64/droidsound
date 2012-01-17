package com.ssb.droidsound.activity;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Fragment;
import android.app.FragmentTransaction;
import android.app.ListFragment;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CursorAdapter;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.ImageView;
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

	protected long currentSongId;

	protected SearchView searchView;

	protected TextView progressPercentageView;

	protected FrameLayout progressContainerView;

	private void navigateStart() {
		Application.getSongDatabase().scan(false);

		CollectionViewAdapter cva = new CollectionViewAdapter(getActivity(), new ICursorFactory() {
			@Override
			public Cursor getCursor() {
				return Application.getSongDatabase().getFilesByParentId(null, getSorting());
			}
		});
		ListFragment lf = new FastListFragment();
		lf.setListAdapter(cva);

		FragmentTransaction ft = getFragmentManager().beginTransaction();
		ft.replace(R.id.collection_view, lf);
		ft.commit();
	}

	protected void navigateWithBackStack(ICursorFactory cf) {
		/* Move to subfolder */
		ListFragment lf = new FastListFragment();
		CollectionViewAdapter cva = new CollectionViewAdapter(getActivity(), cf);
		lf.setListAdapter(cva);

		FragmentTransaction ft = getFragmentManager().beginTransaction();
		ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_OPEN);
		ft.addToBackStack(null);
		ft.replace(R.id.collection_view, lf);
		ft.commit();
	}

	protected static SongDatabase.Sort getSorting() {
		SharedPreferences prefs = Application.getAppPreferences();
		String sorting = prefs.getString("sorting", "TITLE");
		return SongDatabase.Sort.valueOf(sorting);
	}

	public static class FastListFragment extends ListFragment {
		private final BroadcastReceiver songChangeReceiver = new BroadcastReceiver() {
			@Override
			public void onReceive(Context c, Intent i) {
				Log.i(TAG, "Song change received, redisplaying");
				CollectionViewAdapter listAdapter = (CollectionViewAdapter) getListAdapter();
				listAdapter.notifyDataSetChanged();
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

	protected interface ICursorFactory {
		public Cursor getCursor();
	}

	protected class CollectionViewAdapter extends CursorAdapter {
		private final ICursorFactory cursorFactory;

		public CollectionViewAdapter(Context context, ICursorFactory cursorFactory) {
			super(context, null);
			this.cursorFactory = cursorFactory;
			requery();
		}

		public void requery() {
			Cursor c = cursorFactory.getCursor();
			new AsyncQueryResult(c, this).executeOnExecutor(AsyncTask.THREAD_POOL_EXECUTOR);
		}

		@Override
		public void bindView(View view, Context context, Cursor cursor) {
			ImageView iconView = (ImageView) view.findViewById(R.id.icon);
			TextView formatView = (TextView) view.findViewById(R.id.format);
			ImageView playingView = (ImageView) view.findViewById(R.id.playing);
			TextView titleView = (TextView) view.findViewById(R.id.title);
			TextView subtitleView = (TextView) view.findViewById(R.id.subtitle);
			TextView sidetitleView = (TextView) view.findViewById(R.id.sidetitle);

			final long childId = cursor.getLong(SongDatabase.COL_ID);
			final Long parentId = cursor.isNull(SongDatabase.COL_PARENT_ID) ? null : cursor.getLong(SongDatabase.COL_PARENT_ID);
			final int type = cursor.getInt(SongDatabase.COL_TYPE);
			final String format = cursor.getString(SongDatabase.COL_FORMAT);
			final String title = cursor.getString(SongDatabase.COL_TITLE);
			final String composer = cursor.getString(SongDatabase.COL_COMPOSER);
			final int date = cursor.getInt(SongDatabase.COL_DATE);

			playingView.setVisibility(childId == currentSongId ? View.VISIBLE : View.GONE);

			final int icon;
			switch (type) {
			case SongDatabase.TYPE_MUS_FOLDER:
				icon = R.drawable.gflat_mus_folder;
				break;
			case SongDatabase.TYPE_SONGLENGTH:
			case SongDatabase.TYPE_ZIP:
				icon = R.drawable.gflat_package;
				break;
			case SongDatabase.TYPE_PLAYLIST:
				icon = R.drawable.gflat_heart;
				break;
			case SongDatabase.TYPE_DIRECTORY:
				icon = R.drawable.gflat_folder;
				break;
			case SongDatabase.TYPE_FILE:
				icon = R.drawable.gflat_note;
				break;
			default:
				icon = R.drawable.gflat_note;
			}

			iconView.setImageDrawable(context.getResources().getDrawable(icon));
			formatView.setText(format);
			titleView.setText(title);
			subtitleView.setText(composer);
			String sidetitle = null;
			if (date > 19000000) {
				int year = date / 10000;
				int month = (date / 100) % 100;
				if (month != 0) {
					sidetitle = String.format("%04d/%02d", year, month);
				} else {
					sidetitle = String.valueOf(year);
				}
			}
			sidetitleView.setText(sidetitle);

			view.setOnCreateContextMenuListener(new View.OnCreateContextMenuListener() {
				@Override
				public void onCreateContextMenu(ContextMenu menu, View v, ContextMenuInfo menuInfo) {
					/* menuInfo is null.
					 * Encoding the data to the fields I got in menu, then.
					 * Thanks, android. */
					int intChildId = (int) childId;
					menu.setHeaderTitle(title);

					int parentType = 0;
					if (parentId != null) {
						Cursor pc = Application.getSongDatabase().getFileById(parentId);
						pc.moveToFirst();
						parentType = pc.getInt(SongDatabase.COL_TYPE);
						pc.close();
					}

					/* Add to playlist: X */
					if (parentType != SongDatabase.TYPE_PLAYLIST && type == SongDatabase.TYPE_FILE) {
						String fav = getString(R.string.add_to_playlist);
						for (Playlist pl : Application.getSongDatabase().getPlaylistsList()) {
							int id = (int) pl.getId();
							menu.add(MENU_GROUP_ADD_TO_PLAYLIST, intChildId, id, fav + " " + pl.getTitle());
						}
					}

					/* Remove from playlist */
					if (parentId != null) {
						if (parentType == SongDatabase.TYPE_PLAYLIST) {
							menu.add(MENU_GROUP_REMOVE_FROM_PLAYLIST, intChildId, (int) (long) parentId, R.string.remove_from_playlist);
						}
					}

					/* Delete file (not contained in zip) */
					FilesEntry sf = Application.getSongDatabase().getSongFile(childId);
					if (parentType != SongDatabase.TYPE_PLAYLIST
							&& type == SongDatabase.TYPE_FILE
							&& sf.getZipFilePath() == null) {
						menu.add(MENU_GROUP_DELETE, intChildId, Menu.NONE, R.string.delete);
					}
					if (type == SongDatabase.TYPE_ZIP) {
						menu.add(MENU_GROUP_DELETE, intChildId, Menu.NONE, R.string.delete_zip);
					}
					if (type == SongDatabase.TYPE_DIRECTORY) {
						Cursor kids = Application.getSongDatabase().getFilesByParentId(childId, SongDatabase.Sort.TITLE);
						if (kids.getCount() == 0) {
							menu.add(MENU_GROUP_DELETE, intChildId, Menu.NONE, R.string.delete_directory);
						}
						kids.close();
					}
					if (type == SongDatabase.TYPE_PLAYLIST) {
						menu.add(MENU_GROUP_DELETE, intChildId, Menu.NONE, R.string.delete_playlist);
					}
				}
			});
			view.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View arg0) {
					if (type != SongDatabase.TYPE_FILE) {
						navigateWithBackStack(new ICursorFactory() {
							@Override
							public Cursor getCursor() {
								return Application.getSongDatabase().getFilesByParentId(childId, getSorting());
							}
						});
					} else {
						/* Scavenge the entries from our cursor */
						List<FilesEntry> fileList = new ArrayList<FilesEntry>();
						int idx = -1;
						Cursor c = getCursor();
						for (int i = 0; i < c.getCount(); i ++) {
							c.moveToPosition(i);
							long id = c.getLong(SongDatabase.COL_ID);
							FilesEntry sibling = Application.getSongDatabase().getSongFile(id);
							fileList.add(sibling);
							if (id == childId) {
								idx = i;
							}
						}

						try {
							SharedPreferences prefs = Application.getAppPreferences();
							boolean shuffle = prefs.getBoolean("shuffle", false);
							Application.playPlaylist(fileList, idx, shuffle);
						} catch (Exception e) {
							Log.w(TAG, "Can't play file", e);
						}
					}
				}

			});
		}

		@Override
		public View newView(Context context, Cursor arg1, ViewGroup arg2) {
			return ((Activity) context).getLayoutInflater().inflate(R.layout.collection_item, null);
		}
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

	private final BroadcastReceiver songChangeReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			String a = i.getAction();
			if (a.equals(Player.ACTION_LOADING_SONG)) {
				currentSongId = i.getLongExtra("file.id", 0);
			} else if (a.equals(Player.ACTION_UNLOADING_SONG)) {
				currentSongId = 0;
			}
		}
	};

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
		Log.i(TAG, "Creating fragment");
		super.onCreate(savedInstanceState);
		setHasOptionsMenu(true);

		IntentFilter intentFilter = new IntentFilter();
		intentFilter.addAction(Player.ACTION_LOADING_SONG);
		intentFilter.addAction(Player.ACTION_UNLOADING_SONG);
		getActivity().getApplicationContext().registerReceiver(songChangeReceiver, intentFilter);
		getActivity().getApplicationContext().registerReceiver(searchReceiver, new IntentFilter(Scanner.ACTION_SCAN));
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
					navigateWithBackStack(new ICursorFactory() {
						@Override
						public Cursor getCursor() {
							return Application.getSongDatabase().search(query, getSorting());
						}
					});
					return true;
				}

				return false;
			}

			@Override
			public boolean onQueryTextChange(final String newText) {
				/* Do not try search if old query has not yet returned. */
				CursorAdapter old = searchView.getSuggestionsAdapter();
				if (old != null && old.getCursor() == null) {
					return false;
				}

				Log.i(TAG, "Firing a new suggestions scan for: '%s'", newText);
				Cursor c = Application.getSongDatabase().search(newText, getSorting());
				CursorAdapter ca = new SimpleCursorAdapter(
						getActivity(),
						android.R.layout.simple_list_item_2,
						null,
						new String[] { "title", "composer" },
						new int[] { android.R.id.text1, android.R.id.text2 }
				);
				searchView.setSuggestionsAdapter(ca);
				new AsyncQueryResult(c, ca).executeOnExecutor(AsyncTask.THREAD_POOL_EXECUTOR);
				return true;
			}
		});

		/* Restore list fragment */
		Fragment topFragment = getFragmentManager().findFragmentById(R.id.collection_view);
		if (topFragment != null) {
			FragmentTransaction ft = getFragmentManager().beginTransaction();
			ft.replace(R.id.collection_view, topFragment);
			ft.commit();
		} else {
			navigateStart();
		}

		return view;
	}

	@Override
	public void onDestroy() {
		super.onDestroy();

		getActivity().getApplicationContext().unregisterReceiver(songChangeReceiver);
		getActivity().getApplicationContext().unregisterReceiver(searchReceiver);
	}
}
