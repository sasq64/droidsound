package com.ssb.droidsound.activity;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.app.Fragment;
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
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.CursorAdapter;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.ListView;
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

	/** Currently displayed folder's id. */
	private Long childId;

	/** Desired sorting of the collection */
	private final MusicIndexService.Sort sorting = MusicIndexService.Sort.TITLE;

	/** Shuffle playback? */
	private boolean shuffle;

	private MyAdapter collectionViewAdapter;

	private ListView collectionView;

	private Button backButton;

	private TextView searchView;

	private TextView progressPercentageView;

	private FrameLayout progressContainerView;

	private MusicIndexService.LocalBinder db;

	private PlayerService.LocalBinder player;

	private final ServiceConnection searchDbConnection = new ServiceConnection() {
		@Override
		public void onServiceConnected(ComponentName tag, IBinder binder) {
			db = (MusicIndexService.LocalBinder) binder;
			Log.i(TAG, "SongDatabase connection has been established. Showing initial view, and refreshing.");

			db.scan(false);

			collectionViewAdapter = new MyAdapter(getActivity(), getDisplayedChildIdCursor());
			collectionView.setAdapter(collectionViewAdapter);
		}

		@Override
		public void onServiceDisconnected(ComponentName tag) {
			db = null;
		}
	};

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

	protected class MyAdapter extends CursorAdapter {
		protected MyAdapter(Context context, Cursor cursor) {
			super(context, cursor);
		}

		@Override
		public void bindView(View view, Context context, Cursor cursor) {
			ImageView iconView = (ImageView) view.findViewById(R.id.icon);
			ImageView playingView = (ImageView) view.findViewById(R.id.playing);
			TextView titleView = (TextView) view.findViewById(R.id.title);
			TextView subtitleView = (TextView) view.findViewById(R.id.subtitle);
			TextView sidetitleView = (TextView) view.findViewById(R.id.sidetitle);

			final Long childId = cursor.isNull(MusicIndexService.COL_ID) ? null : cursor.getLong(MusicIndexService.COL_ID);
			final String filename = cursor.getString(MusicIndexService.COL_FILENAME);
			final int type = cursor.getInt(MusicIndexService.COL_TYPE);
			final String title = cursor.getString(MusicIndexService.COL_TITLE);
			final String composer = cursor.getString(MusicIndexService.COL_COMPOSER);
			final int date = cursor.getInt(MusicIndexService.COL_DATE);

			playingView.setVisibility(childId != null && childId.equals(currentlyPlayingSong) ? View.VISIBLE : View.GONE);

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
						/* Move to subfolder */
						setDisplayedChildId(childId);
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
			return ((Activity) context).getLayoutInflater().inflate(R.layout.songlist_item, null);
		}
	}

	private final BroadcastReceiver currentSongReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			String a = i.getAction();
			if (a.equals(PlayerService.LOADING_SONG)) {
				currentlyPlayingSong = i.getLongExtra("file.id", 0);
			} else if (a.equals(PlayerService.UNLOADING_SONG)) {
				currentlyPlayingSong = null;
			}
			if (collectionViewAdapter != null) {
				collectionViewAdapter.notifyDataSetChanged();
			}
		}
	};

	private final BroadcastReceiver searchReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context c, Intent i) {
			String a = i.getAction();
			if (a.equals(MusicIndexService.SCAN_NOTIFY_BEGIN)) {
				progressContainerView.setVisibility(View.VISIBLE);
				return;
			}
			if (a.equals(MusicIndexService.SCAN_NOTIFY_UPDATE)) {
				int progress = i.getIntExtra("progress", 0);
				if (progress == 100 && collectionViewAdapter != null) {
					collectionViewAdapter.notifyDataSetChanged();
				}
				progressPercentageView.setText(String.format("%d%%", progress));
			}
			if (a.equals(MusicIndexService.SCAN_NOTIFY_DONE)) {
				progressContainerView.setVisibility(View.INVISIBLE);
			}
		}
	};

	protected Long getDisplayedChildId() {
		return childId;
	}
	protected void setDisplayedChildId(Long childId) {
		this.childId = childId;
		backButton.setEnabled(childId != null);
		if (collectionViewAdapter != null) {
			collectionViewAdapter.changeCursor(getDisplayedChildIdCursor());
		}
	}
	private Cursor getDisplayedChildIdCursor() {
		String search = searchView.getText().toString();
		if ("".equals(search)) {
			return db.getFilesByParentId(childId, sorting);
		} else {
			return db.search(search, sorting);
		}
	}

	@Override
	public void onStart() {
		Log.i(TAG, "onStart");
		super.onStart();
		getActivity().bindService(new Intent(getActivity(), MusicIndexService.class), searchDbConnection, Context.BIND_AUTO_CREATE);
		getActivity().bindService(new Intent(getActivity(), PlayerService.class), playerConnection, Context.BIND_AUTO_CREATE);

		IntentFilter songChangeFilter = new IntentFilter();
		songChangeFilter.addAction(PlayerService.LOADING_SONG);
		songChangeFilter.addAction(PlayerService.UNLOADING_SONG);
		getActivity().registerReceiver(currentSongReceiver, songChangeFilter);

		IntentFilter searchReceiverFilter = new IntentFilter();
		searchReceiverFilter.addAction(MusicIndexService.SCAN_NOTIFY_BEGIN);
		searchReceiverFilter.addAction(MusicIndexService.SCAN_NOTIFY_UPDATE);
		searchReceiverFilter.addAction(MusicIndexService.SCAN_NOTIFY_DONE);
		getActivity().registerReceiver(searchReceiver, searchReceiverFilter);
	}

	@Override
	public void onStop() {
		Log.i(TAG, "onStop");
		super.onStop();
		getActivity().unbindService(searchDbConnection);
		getActivity().unbindService(playerConnection);
		getActivity().unregisterReceiver(currentSongReceiver);
		getActivity().unregisterReceiver(searchReceiver);
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle state) {
		View view = inflater.inflate(R.layout.collection_view, null);
		collectionView = (ListView) view.findViewById(R.id.collection_view);
		backButton = (Button) view.findViewById(R.id.back);
		progressContainerView = (FrameLayout) view.findViewById(R.id.progress_container);
		progressPercentageView = (TextView) view.findViewById(R.id.progress_percentage);
		searchView = (TextView) view.findViewById(R.id.search);

		backButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				Cursor child = db.getFileById(getDisplayedChildId());
				if (child.getCount() == 0) {
					setDisplayedChildId(null);
				} else {
					child.moveToFirst();
					setDisplayedChildId(child.isNull(MusicIndexService.COL_PARENT_ID) ? null : child.getLong(MusicIndexService.COL_PARENT_ID));
					child.close();
				}
			}
		});

		progressContainerView.setVisibility(View.GONE);
		searchView.setOnEditorActionListener(new TextView.OnEditorActionListener() {
			@Override
			public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
				collectionViewAdapter.changeCursor(getDisplayedChildIdCursor());
				InputMethodManager imm = (InputMethodManager) getActivity().getSystemService(Context.INPUT_METHOD_SERVICE);
				imm.hideSoftInputFromWindow(searchView.getWindowToken(), 0);
				return true;
			}
		});

		if (state != null) {
			setDisplayedChildId(state.containsKey("childId") ? state.getLong("childId", 0) : null);
		} else {
			setDisplayedChildId(null);
		}

		return view;
	}

	@Override
	public void onSaveInstanceState(Bundle outState) {
		super.onSaveInstanceState(outState);
		Long child = getDisplayedChildId();
		if (child != null) {
			outState.putLong("childId", child);
		}
	}
}
