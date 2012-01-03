package com.ssb.droidsound.activity;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentTransaction;
import android.app.ListFragment;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.ServiceConnection;
import android.database.Cursor;
import android.os.Bundle;
import android.os.IBinder;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputMethodManager;
import android.widget.CursorAdapter;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.TextView;

import com.ssb.droidsound.R;
import com.ssb.droidsound.bo.SongFile;
import com.ssb.droidsound.service.MusicIndexService;
import com.ssb.droidsound.service.PlayerService;
import com.ssb.droidsound.utils.Log;

public class CollectionFragment extends Fragment {
	protected static final String TAG = CollectionFragment.class.getSimpleName();

	/** Currently playing song's id */
	private Long currentlyPlayingSong;

	/** Desired sorting of the collection */
	private final MusicIndexService.Sort sorting = MusicIndexService.Sort.TITLE;

	/** Shuffle playback? */
	private boolean shuffle;

	private TextView searchView;

	private TextView progressPercentageView;

	private FrameLayout progressContainerView;

	private MusicIndexService.LocalBinder db;

	private PlayerService.LocalBinder player;

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

	protected void refreshListFragment() {
		ListFragment lf = (ListFragment) getFragmentManager().findFragmentById(R.id.collection_view);
		if (lf != null) {
			((CollectionViewAdapter) lf.getListAdapter()).requery();
		}
	}

	private final ServiceConnection searchDbConnection = new ServiceConnection() {
		@Override
		public void onServiceConnected(ComponentName tag, IBinder binder) {
			db = (MusicIndexService.LocalBinder) binder;
			Log.i(TAG, "SongDatabase connection has been established. Showing initial view, and refreshing.");
			db.scan(false);

			ListFragment lf = new FastListFragment();
			CollectionViewAdapter cva = new CollectionViewAdapter(getActivity(), new ICursorFactory() {
				@Override
				public Cursor getCursor() {
					return db.getFilesByParentId(null, sorting);
				}
			});
			lf.setListAdapter(cva);
			FragmentTransaction ft = getFragmentManager().beginTransaction();
			ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_FADE);
			ft.replace(R.id.collection_view, lf);
			ft.commit();
		}

		@Override
		public void onServiceDisconnected(ComponentName tag) {
			db = null;
		}
	};

	protected static class FastListFragment extends ListFragment {
		@Override
		public void onViewCreated(View view, Bundle savedInstanceState) {
			super.onViewCreated(view, savedInstanceState);
			getListView().setFastScrollEnabled(true);
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
			final String filename = cursor.getString(MusicIndexService.COL_FILENAME);
			final int type = cursor.getInt(MusicIndexService.COL_TYPE);
			final String format = cursor.getString(MusicIndexService.COL_FORMAT);
			final String title = cursor.getString(MusicIndexService.COL_TITLE);
			final String composer = cursor.getString(MusicIndexService.COL_COMPOSER);
			final int date = cursor.getInt(MusicIndexService.COL_DATE);

			playingView.setVisibility(childId.equals(currentlyPlayingSong) ? View.VISIBLE : View.GONE);

			final int icon;
			switch (type) {
			case MusicIndexService.TYPE_SONGLENGTH:
			case MusicIndexService.TYPE_ZIP:
				icon = R.drawable.gflat_package;
				break;
			case MusicIndexService.TYPE_DIR:
				icon = R.drawable.gflat_folder;
				break;
			case MusicIndexService.TYPE_MUS_FOLDER:
				icon = R.drawable.gflat_mus_folder;
				break;
			case MusicIndexService.TYPE_FILE:
				icon = R.drawable.gflat_note;
				break;
			case MusicIndexService.TYPE_PLIST:
				if (filename.equals("Favorites.plist")) {
					icon = R.drawable.gflat_heart;
				} else {
					icon = R.drawable.gflat_bag;
				}
				break;
			default:
				icon = R.drawable.gflat_bag;
			}

			iconView.setImageDrawable(context.getResources().getDrawable(icon));
			formatView.setText(format);
			titleView.setText(title != null ? title : filename);
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

			view.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View arg0) {
					if (type != MusicIndexService.TYPE_FILE) {
						navigateWithBackStack(new ICursorFactory() {
							@Override
							public Cursor getCursor() {
								return db.getFilesByParentId(childId, sorting);
							}

						});
					} else {
						/* Scavenge the entries from our cursor */
						List<SongFile> fileList = new ArrayList<SongFile>();
						int idx = -1;
						Cursor c = getCursor();
						for (int i = 0; i < c.getCount(); i ++) {
							c.moveToPosition(i);
							long id = c.getLong(MusicIndexService.COL_ID);
							SongFile sibling = db.getSongFile(id);
							fileList.add(sibling);
							if (childId != null && id == childId) {
								idx = i;
							}
						}

						try {
							player.playPlaylist(fileList, idx, shuffle);
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

	private final BroadcastReceiver currentSongReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			String a = i.getAction();
			if (a.equals(PlayerService.ACTION_LOADING_SONG)) {
				currentlyPlayingSong = i.getLongExtra("file.id", 0);
			} else if (a.equals(PlayerService.ACTION_UNLOADING_SONG)) {
				currentlyPlayingSong = null;
			}
			refreshListFragment();
		}
	};

	private final BroadcastReceiver searchReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			int progress = i.getIntExtra("progress", 0);
			if (progress == 100) {
				refreshListFragment();
			}
			progressPercentageView.setText(String.format("%d%%", progress));
			progressContainerView.setVisibility(i.getBooleanExtra("scanning", false) ? View.VISIBLE : View.GONE);
		}
	};

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		getActivity().bindService(new Intent(getActivity(), MusicIndexService.class), searchDbConnection, Context.BIND_AUTO_CREATE);
		getActivity().bindService(new Intent(getActivity(), PlayerService.class), playerConnection, Context.BIND_AUTO_CREATE);
		IntentFilter songChangeFilter = new IntentFilter();
		songChangeFilter.addAction(PlayerService.ACTION_LOADING_SONG);
		songChangeFilter.addAction(PlayerService.ACTION_UNLOADING_SONG);
		getActivity().getApplicationContext().registerReceiver(currentSongReceiver, songChangeFilter);
		getActivity().getApplicationContext().registerReceiver(searchReceiver, new IntentFilter(MusicIndexService.ACTION_SCAN));
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle state) {
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
							return db.search(value, sorting);
						}
					});
				}
				InputMethodManager imm = (InputMethodManager) getActivity().getSystemService(Context.INPUT_METHOD_SERVICE);
				imm.hideSoftInputFromWindow(searchView.getWindowToken(), 0);
				return true;
			}
		});

		return view;
	}

	@Override
	public void onDestroy() {
		super.onDestroy();

		getActivity().getApplicationContext().unregisterReceiver(currentSongReceiver);
		getActivity().getApplicationContext().unregisterReceiver(searchReceiver);

		getActivity().unbindService(searchDbConnection);
		getActivity().unbindService(playerConnection);
	}
}
