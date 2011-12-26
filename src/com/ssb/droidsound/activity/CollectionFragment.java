package com.ssb.droidsound.activity;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.app.Fragment;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
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
import com.ssb.droidsound.service.PlayerService;
import com.ssb.droidsound.service.SongDatabaseService;
import com.ssb.droidsound.utils.Log;

public class CollectionFragment extends Fragment {
	protected static final String TAG = CollectionFragment.class.getSimpleName();

	private ListView collectionView;

	private SongDatabaseService.LocalBinder db;

	private PlayerService.LocalBinder player;

	private final SongDatabaseService.Sort sorting = SongDatabaseService.Sort.TITLE;

	private boolean shuffle;

	private final ServiceConnection searchDbConnection = new ServiceConnection() {
		@Override
		public void onServiceConnected(ComponentName tag, IBinder binder) {
			db = (SongDatabaseService.LocalBinder) binder;
			Log.i(TAG, "SongDatabase connection has been established. Showing initial view, and refreshing.");

			MyAdapter ma = new MyAdapter(getActivity(), getCursor(null, null));
			collectionView.setAdapter(ma);
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
			TextView titleView = (TextView) view.findViewById(R.id.title);
			TextView subtitleView = (TextView) view.findViewById(R.id.subtitle);
			TextView sidetitleView = (TextView) view.findViewById(R.id.sidetitle);

			final Long childId = cursor.isNull(SongDatabaseService.COL_ID) ? null : cursor.getLong(SongDatabaseService.COL_ID);
			final int type = cursor.getInt(SongDatabaseService.COL_TYPE);
			final String title = cursor.getString(SongDatabaseService.COL_TITLE);
			final Long parentId = cursor.isNull(SongDatabaseService.COL_PARENT_ID) ? null : cursor.getLong(SongDatabaseService.COL_PARENT_ID);
			final String filename = cursor.getString(SongDatabaseService.COL_FILENAME);
			final String composer = cursor.getString(SongDatabaseService.COL_COMPOSER);
			final int date = cursor.getInt(SongDatabaseService.COL_DATE);

			final int icon;
			switch (type) {
			case SongDatabaseService.TYPE_ZIP:
				icon = R.drawable.gflat_package;
				break;
			case SongDatabaseService.TYPE_DIR:
				icon = R.drawable.gflat_folder;
				break;
			case SongDatabaseService.TYPE_MUS_FOLDER:
				icon = R.drawable.gflat_mus_folder;
				break;
			case SongDatabaseService.TYPE_FILE:
				icon = R.drawable.gflat_note;
				break;
			case SongDatabaseService.TYPE_PLIST:
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
					if (type != SongDatabaseService.TYPE_FILE) {
						changeCursor(CollectionFragment.this.getCursor(parentId, childId));
					} else {
						Cursor playListCursor = db.getFilesInPath(parentId, sorting);
						List<SongFile> fileList = new ArrayList<SongFile>();
						playListCursor.moveToFirst();
						int idx = -1;

						SongFile selectedFile = db.getSongFile(childId);
						while (! playListCursor.isAfterLast()) {
							String name = playListCursor.getString(SongDatabaseService.COL_FILENAME);
							SongFile sibling = selectedFile.sibling(name);
							fileList.add(sibling);
							if (selectedFile.getFilePath().equals(sibling.getFilePath())) {
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

	private Cursor getCursor(final Long parentId, final Long childId) {
		Cursor cf = db.getFilesInPath(childId, sorting);
		Cursor cp = null;
		if (parentId != null) {
			cp = db.getFileById(parentId);
		} else {
			cp = new MemoryCursor(
					cf.getColumnNames(),
					new Object[][] {
						{ null, null, Application.getModsDirectory().getPath(), SongDatabaseService.TYPE_MUS_FOLDER, null, null, 0 }
					}
			);
		}
		return cp != null ? new MergeCursor(new Cursor[] { cp, cf }) : cf;
	}

	@Override
	public void onStart() {
		Log.i(TAG, "onStart");
		super.onStart();
		getActivity().bindService(new Intent(getActivity(), SongDatabaseService.class), searchDbConnection, Context.BIND_AUTO_CREATE);
		getActivity().bindService(new Intent(getActivity(), PlayerService.class), playerConnection, Context.BIND_AUTO_CREATE);
	}

	@Override
	public void onStop() {
		Log.i(TAG, "onStop");
		super.onStop();
		getActivity().unbindService(searchDbConnection);
		getActivity().unbindService(playerConnection);
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
		Log.i(TAG, "onCreateView");
		View view = inflater.inflate(R.layout.collection_view, null);
		collectionView = (ListView) view.findViewById(R.id.collection_view);
		return view;
	}
}
