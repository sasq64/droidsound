package com.ssb.droidsound.activity;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.app.FragmentManager;
import android.content.Context;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.os.AsyncTask;
import android.view.ContextMenu;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.Menu;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CursorAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import com.ssb.droidsound.R;
import com.ssb.droidsound.activity.FastListFragment.ICursorFactory;
import com.ssb.droidsound.app.Application;
import com.ssb.droidsound.async.AsyncQueryResult;
import com.ssb.droidsound.bo.FilesEntry;
import com.ssb.droidsound.bo.Playlist;
import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.utils.Log;

class CollectionViewAdapter extends CursorAdapter {
	protected static final String TAG = CollectionViewAdapter.class.getSimpleName();

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
	public void bindView(View view, final Context context, Cursor cursor) {
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

		Long currentSongId = Application.getCurrentlyPlayingSongId();
		playingView.setVisibility(currentSongId != null && currentSongId.equals(childId)
				? View.VISIBLE : View.GONE);

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
					String fav = context.getString(R.string.add_to_playlist);
					for (Playlist pl : Application.getSongDatabase().getPlaylistsList()) {
						int id = (int) pl.getId();
						menu.add(CollectionFragment.MENU_GROUP_ADD_TO_PLAYLIST, intChildId, id, fav + " " + pl.getTitle());
					}
				}

				/* Remove from playlist */
				if (parentId != null) {
					if (parentType == SongDatabase.TYPE_PLAYLIST) {
						menu.add(CollectionFragment.MENU_GROUP_REMOVE_FROM_PLAYLIST, intChildId, (int) (long) parentId, R.string.remove_from_playlist);
					}
				}

				/* Delete file (not contained in zip) */
				FilesEntry sf = Application.getSongDatabase().getSongFile(childId);
				if (parentType != SongDatabase.TYPE_PLAYLIST
						&& type == SongDatabase.TYPE_FILE
						&& sf.getZipFilePath() == null) {
					menu.add(CollectionFragment.MENU_GROUP_DELETE, intChildId, Menu.NONE, R.string.delete);
				}
				if (type == SongDatabase.TYPE_ZIP) {
					menu.add(CollectionFragment.MENU_GROUP_DELETE, intChildId, Menu.NONE, R.string.delete_zip);
				}
				if (type == SongDatabase.TYPE_DIRECTORY) {
					Cursor kids = Application.getSongDatabase().getFilesByParentId(childId, SongDatabase.Sort.TITLE);
					if (kids.getCount() == 0) {
						menu.add(CollectionFragment.MENU_GROUP_DELETE, intChildId, Menu.NONE, R.string.delete_directory);
					}
					kids.close();
				}
				if (type == SongDatabase.TYPE_PLAYLIST) {
					menu.add(CollectionFragment.MENU_GROUP_DELETE, intChildId, Menu.NONE, R.string.delete_playlist);
				}
			}
		});
		view.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View arg0) {
				Activity a = (Activity) context;
				FragmentManager fm = a.getFragmentManager();
				CollectionFragment cf = (CollectionFragment) fm.findFragmentByTag("android:switcher:" + R.id.viewPager + ":" + 0);

				if (type != SongDatabase.TYPE_FILE) {
					cf.navigateWithBackStack(childId);
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
