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
import android.database.MergeCursor;
import android.os.Bundle;
import android.os.IBinder;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CursorAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

import com.ssb.droidsound.R;
import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.bo.MemoryCursor;
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

	private MusicIndexService.LocalBinder db;

	private PlayerService.LocalBinder player;

	private final ServiceConnection searchDbConnection = new ServiceConnection() {
		@Override
		public void onServiceConnected(ComponentName tag, IBinder binder) {
			db = (MusicIndexService.LocalBinder) binder;
			Log.i(TAG, "SongDatabase connection has been established. Showing initial view, and refreshing.");

			collectionViewAdapter = new MyAdapter(getActivity(), getCursor(childId));
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
		protected MyAdapter(Context context, Cursor c) {
			super(context, c);
		}

		@Override
		public void bindView(View view, Context context, Cursor cursor) {
			ImageView iconView = (ImageView) view.findViewById(R.id.icon);
			ImageView playingView = (ImageView) view.findViewById(R.id.playing);
			TextView titleView = (TextView) view.findViewById(R.id.title);
			TextView subtitleView = (TextView) view.findViewById(R.id.subtitle);
			TextView sidetitleView = (TextView) view.findViewById(R.id.sidetitle);

			final Long childId = cursor.isNull(MusicIndexService.COL_ID) ? null : cursor.getLong(MusicIndexService.COL_ID);
			final Long parentId = cursor.isNull(MusicIndexService.COL_PARENT_ID) ? null : cursor.getLong(MusicIndexService.COL_PARENT_ID);
			final String filename = cursor.getString(MusicIndexService.COL_FILENAME);
			final int type = cursor.getInt(MusicIndexService.COL_TYPE);
			final String title = cursor.getString(MusicIndexService.COL_TITLE);
			final String composer = cursor.getString(MusicIndexService.COL_COMPOSER);
			final int date = cursor.getInt(MusicIndexService.COL_DATE);

			playingView.setVisibility(childId != null && childId.equals(currentlyPlayingSong) ? View.VISIBLE : View.GONE);

			final int icon;
			switch (type) {
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
				throw new RuntimeException("Invalid type " + type + " on item: " + title);
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
						CollectionFragment.this.childId = childId;
						changeCursor(CollectionFragment.this.getCursor(childId));
					} else {
						Cursor playListCursor = db.getFilesByParentId(parentId, sorting);
						List<SongFile> fileList = new ArrayList<SongFile>();
						playListCursor.moveToFirst();
						int idx = -1;

						while (! playListCursor.isAfterLast()) {
							long id = playListCursor.getLong(MusicIndexService.COL_ID);
							SongFile sibling = db.getSongFile(id);
							fileList.add(sibling);
							if (childId != null && id == childId) {
								idx = playListCursor.getPosition();
							}
							playListCursor.moveToNext();
						}
						playListCursor.close();

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
			collectionViewAdapter.notifyDataSetChanged();
		}
	};

	private Cursor getCursor(final Long selectedId) {
		Long parentId = null;
		/* Null means we are already at top level */
		if (selectedId != null) {
			Cursor child = db.getFileById(selectedId);
			child.moveToFirst();
			parentId = child.isNull(MusicIndexService.COL_PARENT_ID) ? null : child.getLong(MusicIndexService.COL_PARENT_ID);
			child.close();
		}

		Cursor cf = db.getFilesByParentId(selectedId, sorting);
		final Cursor cp;
		if (parentId != null) {
			cp = db.getFileById(parentId);
		} else {
			cp = new MemoryCursor(
					cf.getColumnNames(),
					new Object[][] {
						{ null, null, Application.getModsDirectory().getPath(), MusicIndexService.TYPE_MUS_FOLDER, null, null, 0 }
					}
			);
		}
		return new MergeCursor(new Cursor[] { cp, cf });
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
	}

	@Override
	public void onStop() {
		Log.i(TAG, "onStop");
		super.onStop();
		getActivity().unbindService(searchDbConnection);
		getActivity().unbindService(playerConnection);
		getActivity().unregisterReceiver(currentSongReceiver);
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle state) {
		Log.i(TAG, "onCreateView");
		if (state != null) {
			childId = state.containsKey("childId") ? state.getLong("childId", 0) : null;
		}
		View view = inflater.inflate(R.layout.collection_view, null);
		collectionView = (ListView) view.findViewById(R.id.collection_view);
		return view;
	}

	@Override
	public void onSaveInstanceState(Bundle outState) {
		super.onSaveInstanceState(outState);
		if (childId != null) {
			outState.putLong("childId", childId);
		}
	}
}
