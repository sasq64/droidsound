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
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputMethodManager;
import android.widget.CursorAdapter;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.TextView;

import com.ssb.droidsound.R;
import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.bo.FilesEntry;
import com.ssb.droidsound.bo.Playlist;
import com.ssb.droidsound.service.MusicIndexService;
import com.ssb.droidsound.service.PlayerService;
import com.ssb.droidsound.utils.Log;

public class CollectionFragment extends Fragment {
	protected static final String TAG = CollectionFragment.class.getSimpleName();
	protected static final int MENU_GROUP_DELETE = 1;
	protected static final int MENU_GROUP_ADD_TO_PLAYLIST = 2;
	protected static final int MENU_GROUP_REMOVE_FROM_PLAYLIST = 3;
	protected static final int MENU_GROUP_CREATE_PLAYLIST = 4;

	protected Long currentSongId;

	private TextView searchView;

	private TextView progressPercentageView;

	private FrameLayout progressContainerView;

	private void navigateStart() {
		((PlayerActivity) getActivity()).getMusicIndexService().scan(false);

		ListFragment lf = new FastListFragment();
		CollectionViewAdapter cva = new CollectionViewAdapter(getActivity(), new ICursorFactory() {
			@Override
			public Cursor getCursor() {
				return ((PlayerActivity) getActivity()).getMusicIndexService().getFilesByParentId(null, getSorting());
			}
		});
		lf.setListAdapter(cva);
		FragmentTransaction ft = getFragmentManager().beginTransaction();
		ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_FADE);
		ft.replace(R.id.collection_view, lf);
		ft.commit();
	}

	protected void navigateWithBackStack(ICursorFactory cursorFactory) {
		/* Move to subfolder */
		ListFragment lf = new FastListFragment();
		CollectionViewAdapter cva = new CollectionViewAdapter(getActivity(), cursorFactory);
		lf.setListAdapter(cva);

		/* Only adding collection_view the first time around. */
		FragmentTransaction ft = getFragmentManager().beginTransaction();
		ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_OPEN);
		ft.addToBackStack(null);
		ft.replace(R.id.collection_view, lf);
		ft.commit();
	}

	protected MusicIndexService.Sort getSorting() {
		SharedPreferences prefs = Application.getAppPreferences();
		String sorting = prefs.getString("sorting", "TITLE");
		return MusicIndexService.Sort.valueOf(sorting);
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
					Log.i(TAG, "Fragment will requery");
					CollectionViewAdapter listAdapter = (CollectionViewAdapter) getListAdapter();
					listAdapter.requery();
				}
			}
		};

		@Override
		public void onViewCreated(View view, Bundle savedInstanceState) {
			super.onViewCreated(view, savedInstanceState);
			getListView().setFastScrollEnabled(true);
			IntentFilter intentFilter = new IntentFilter();
			intentFilter.addAction(PlayerService.ACTION_LOADING_SONG);
			intentFilter.addAction(PlayerService.ACTION_UNLOADING_SONG);
			getActivity().getApplicationContext().registerReceiver(songChangeReceiver, intentFilter);
			getActivity().getApplicationContext().registerReceiver(updateReceiver, new IntentFilter(MusicIndexService.ACTION_SCAN));
		}

		@Override
		public void onDestroyView() {
			super.onDestroyView();
			getActivity().getApplicationContext().unregisterReceiver(songChangeReceiver);
			getActivity().getApplicationContext().unregisterReceiver(updateReceiver);
		}
	}

	protected interface ICursorFactory {
		public Cursor getCursor();
	}

	protected class CollectionViewAdapter extends CursorAdapter {
		private final ICursorFactory cursorFactory;

		protected CollectionViewAdapter(Context context, ICursorFactory cursorFactory) {
			super(context, cursorFactory.getCursor());
			this.cursorFactory = cursorFactory;
		}

		public void requery() {
			changeCursor(cursorFactory.getCursor());
			Log.i(TAG, "After query: " + getCursor().getCount());
		}

		@Override
		public void bindView(View view, Context context, Cursor cursor) {
			ImageView iconView = (ImageView) view.findViewById(R.id.icon);
			TextView formatView = (TextView) view.findViewById(R.id.format);
			ImageView playingView = (ImageView) view.findViewById(R.id.playing);
			TextView titleView = (TextView) view.findViewById(R.id.title);
			TextView subtitleView = (TextView) view.findViewById(R.id.subtitle);
			TextView sidetitleView = (TextView) view.findViewById(R.id.sidetitle);

			final Long childId = cursor.getLong(MusicIndexService.COL_ID);
			final Long parentId = cursor.isNull(MusicIndexService.COL_PARENT_ID) ? null : cursor.getLong(MusicIndexService.COL_PARENT_ID);
			final int type = cursor.getInt(MusicIndexService.COL_TYPE);
			final String format = cursor.getString(MusicIndexService.COL_FORMAT);
			final String title = cursor.getString(MusicIndexService.COL_TITLE);
			final String composer = cursor.getString(MusicIndexService.COL_COMPOSER);
			final int date = cursor.getInt(MusicIndexService.COL_DATE);

			playingView.setVisibility(childId.equals(currentSongId) ? View.VISIBLE : View.GONE);

			final int icon;
			switch (type) {
			case MusicIndexService.TYPE_MUS_FOLDER:
				icon = R.drawable.gflat_mus_folder;
				break;
			case MusicIndexService.TYPE_SONGLENGTH:
			case MusicIndexService.TYPE_ZIP:
				icon = R.drawable.gflat_package;
				break;
			case MusicIndexService.TYPE_PLAYLIST:
				icon = R.drawable.gflat_heart;
				break;
			case MusicIndexService.TYPE_DIRECTORY:
				icon = R.drawable.gflat_folder;
				break;
			case MusicIndexService.TYPE_FILE:
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
					int intChildId = (int) (long) childId;
					menu.setHeaderTitle(title);

					int parentType = 0;
					if (parentId != null) {
						Cursor pc = ((PlayerActivity) getActivity()).getMusicIndexService().getFileById(parentId);
						pc.moveToFirst();
						parentType = pc.getInt(MusicIndexService.COL_TYPE);
						pc.close();
					}

					/* Add to playlist: X */
					if (parentType != MusicIndexService.TYPE_PLAYLIST && type == MusicIndexService.TYPE_FILE) {
						String fav = getString(R.string.add_to_playlist);
						for (Playlist pl : ((PlayerActivity) getActivity()).getMusicIndexService().getPlaylistsList()) {
							int id = (int) pl.getId();
							String title = pl.getTitle();
							menu.add(MENU_GROUP_ADD_TO_PLAYLIST, intChildId, id, fav + " " + title);
						}
					}

					/* Remove from playlist */
					if (parentType == MusicIndexService.TYPE_PLAYLIST) {
						menu.add(MENU_GROUP_REMOVE_FROM_PLAYLIST, intChildId, (int) (long) parentId, R.string.remove_from_playlist);
					}

					/* Delete file (not contained in zip) */
					FilesEntry sf = ((PlayerActivity) getActivity()).getMusicIndexService().getSongFile(childId);
					if (parentType != MusicIndexService.TYPE_PLAYLIST
							&& type == MusicIndexService.TYPE_FILE
							&& sf.getZipFilePath() == null) {
						menu.add(MENU_GROUP_DELETE, intChildId, Menu.NONE, R.string.delete);
					}
					if (type == MusicIndexService.TYPE_ZIP) {
						menu.add(MENU_GROUP_DELETE, intChildId, Menu.NONE, R.string.delete_zip);
					}
					if (type == MusicIndexService.TYPE_DIRECTORY) {
						Cursor kids = ((PlayerActivity) getActivity()).getMusicIndexService().getFilesByParentId(childId, MusicIndexService.Sort.TITLE);
						if (kids.getCount() == 0) {
							menu.add(MENU_GROUP_DELETE, intChildId, Menu.NONE, R.string.delete_directory);
						}
						kids.close();
					}
					if (type == MusicIndexService.TYPE_PLAYLIST) {
						menu.add(MENU_GROUP_DELETE, intChildId, Menu.NONE, R.string.delete_playlist);
					}
				}
			});
			view.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View arg0) {
					if (type != MusicIndexService.TYPE_FILE) {
						navigateWithBackStack(new ICursorFactory() {
							@Override
							public Cursor getCursor() {
								Log.i(TAG, "Querying elements for child: %d", childId);
								return ((PlayerActivity) getActivity()).getMusicIndexService().getFilesByParentId(childId, getSorting());
							}

						});
					} else {
						/* Scavenge the entries from our cursor */
						List<FilesEntry> fileList = new ArrayList<FilesEntry>();
						int idx = -1;
						Cursor c = getCursor();
						for (int i = 0; i < c.getCount(); i ++) {
							c.moveToPosition(i);
							long id = c.getLong(MusicIndexService.COL_ID);
							FilesEntry sibling = ((PlayerActivity) getActivity()).getMusicIndexService().getSongFile(id);
							fileList.add(sibling);
							if (childId != null && id == childId) {
								idx = i;
							}
						}

						try {
							SharedPreferences prefs = Application.getAppPreferences();
							boolean shuffle = prefs.getBoolean("shuffle", false);
							((PlayerActivity) getActivity()).getPlayerService().playPlaylist(fileList, idx, shuffle);
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
		final FilesEntry sf = ((PlayerActivity) getActivity()).getMusicIndexService().getSongFile(item.getItemId());

		switch (item.getGroupId()) {
		case MENU_GROUP_ADD_TO_PLAYLIST: {
			for (Playlist pl : ((PlayerActivity) getActivity()).getMusicIndexService().getPlaylistsList()) {
				if ((int) pl.getId() == item.getOrder()) {
					/* Avoid adding a file twice. */
					if (! pl.getSongs().contains(sf)) {
						pl.getSongs().add(sf);
					}
					pl.persist();
					((PlayerActivity) getActivity()).getMusicIndexService().scan(false);
				}
			}

			return true;
		}

		case MENU_GROUP_REMOVE_FROM_PLAYLIST: {
			for (Playlist pl : ((PlayerActivity) getActivity()).getMusicIndexService().getPlaylistsList()) {
				if ((int) pl.getId() == item.getOrder()) {
					pl.getSongs().remove(sf);
					pl.persist();
					((PlayerActivity) getActivity()).getMusicIndexService().scan(false);
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
					((PlayerActivity) getActivity()).getMusicIndexService().scan(false);
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
					((PlayerActivity) getActivity()).getMusicIndexService().scan(false);
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
			if (a.equals(PlayerService.ACTION_LOADING_SONG)) {
				currentSongId = i.getLongExtra("file.id", 0);
			} else if (a.equals(PlayerService.ACTION_UNLOADING_SONG)) {
				currentSongId = null;
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
		intentFilter.addAction(PlayerService.ACTION_LOADING_SONG);
		intentFilter.addAction(PlayerService.ACTION_UNLOADING_SONG);
		getActivity().getApplicationContext().registerReceiver(songChangeReceiver, intentFilter);
		getActivity().getApplicationContext().registerReceiver(searchReceiver, new IntentFilter(MusicIndexService.ACTION_SCAN));
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle state) {
		Log.i(TAG, "Creating view");

		View view = inflater.inflate(R.layout.collection_view, null);
		progressContainerView = (FrameLayout) view.findViewById(R.id.progress_container);
		progressPercentageView = (TextView) view.findViewById(R.id.progress_percentage);
		searchView = (TextView) view.findViewById(R.id.search);

		progressContainerView.setVisibility(View.GONE);
		searchView.setOnEditorActionListener(new TextView.OnEditorActionListener() {
			@Override
			public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
				/* Is return press? */
				if (actionId != EditorInfo.IME_NULL || event.getAction() != KeyEvent.ACTION_DOWN) {
					return false;
				}
				final String value = String.valueOf(searchView.getText());
				if (! "".equals(value)) {
					navigateWithBackStack(new ICursorFactory() {
						@Override
						public Cursor getCursor() {
							Log.i(TAG, "Querying for search: " + value);
							return ((PlayerActivity) getActivity()).getMusicIndexService().search(value, getSorting());
						}
					});
				}
				InputMethodManager imm = (InputMethodManager) getActivity().getSystemService(Context.INPUT_METHOD_SERVICE);
				imm.hideSoftInputFromWindow(searchView.getWindowToken(), 0);
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
