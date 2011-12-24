package com.ssb.droidsound.activity;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.app.Fragment;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.database.Cursor;
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
import com.ssb.droidsound.bo.SongFile;
import com.ssb.droidsound.service.PlayerService;
import com.ssb.droidsound.service.SongDatabaseService;
import com.ssb.droidsound.utils.Log;

public class CollectionFragment extends Fragment {
	protected static final String TAG = CollectionFragment.class.getSimpleName();

	private final List<String> parents = new ArrayList<String>();

	private ListView collectionView;

	private SongDatabaseService.LocalBinder db;

	private PlayerService.LocalBinder player;

	private final SongDatabaseService.Sort sorting = SongDatabaseService.Sort.TITLE;

	private final ServiceConnection searchDbConnection = new ServiceConnection() {
		@Override
		public void onServiceConnected(ComponentName tag, IBinder binder) {
			db = (SongDatabaseService.LocalBinder) binder;
			Log.i(TAG, "SongDatabase connection has been established. Showing initial view, and refreshing.");
			MyAdapter ma = new MyAdapter(getActivity(), db.getFilesInPath(Application.getModsDirectory(), sorting));
			collectionView.setAdapter(ma);

			Log.i(TAG, "Refreshing database.");
			db.scan(false);
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

			final int type = cursor.getInt(SongDatabaseService.COL_TYPE);
			final String title = cursor.getString(SongDatabaseService.COL_TITLE);
			final String path = cursor.getString(SongDatabaseService.COL_PATH);
			final String filename = cursor.getString(SongDatabaseService.COL_FILENAME);
			final String composer = cursor.getString(SongDatabaseService.COL_COMPOSER);
			final int date = cursor.getInt(SongDatabaseService.COL_DATE);

			final int icon;
			switch (type) {
			case SongDatabaseService.TYPE_ARCHIVE:
				icon = R.drawable.gflat_package;
				break;
			case SongDatabaseService.TYPE_DIR:
				icon = R.drawable.gflat_folder;
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
			sidetitleView.setText(date != 0 ? String.valueOf(date / 10000) : null);

			view.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View arg0) {
					File f = new File(path, filename);
					if (type != SongDatabaseService.TYPE_FILE) {
						changeCursor(db.getFilesInPath(f, sorting));
					} else {
						parents.add(path);
						player.playMod(SongFile.fromFileName(f.getPath()));
					}
				}
			});
		}

		@Override
		public View newView(Context context, Cursor arg1, ViewGroup arg2) {
			return ((Activity) context).getLayoutInflater().inflate(R.layout.songlist_item, null);
		}
	}

	@Override
	public void onAttach(Activity activity) {
		super.onAttach(activity);
		activity.bindService(new Intent(getActivity(), SongDatabaseService.class), searchDbConnection, Context.BIND_AUTO_CREATE);
		activity.bindService(new Intent(getActivity(), PlayerService.class), playerConnection, Context.BIND_AUTO_CREATE);
	}

	@Override
	public void onDetach() {
		super.onDestroy();
		getActivity().unbindService(searchDbConnection);
		getActivity().unbindService(playerConnection);
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
		View view = inflater.inflate(R.layout.collection_view, null);
		collectionView = (ListView) view.findViewById(R.id.collection_view);
		return view;
	}
}
