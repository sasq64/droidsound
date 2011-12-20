package com.ssb.droidsound.playlistview;

import java.io.File;
import java.util.ArrayList;

import android.app.Activity;
import android.content.Context;
import android.database.Cursor;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import com.ssb.droidsound.R;
import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.utils.Log;

class PlayListAdapter extends BaseAdapter {
	private static final String TAG = PlayListAdapter.class.getSimpleName();

	private static final String [] monthNames = { "Jan", "Feb", "Mars", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dev" };


	private final Context mContext;
	private Cursor mCursor;

	private int mSubIndex;
	private int mTitleIndex;
	private int mTypeIndex;
	private int mFileIndex;
	private int mPathIndex;
	private String pathName;
	private int hilightedPosition = -1;
	private final int itemColor;
	private final int subitemColor;
	private final int archiveColor;
	private final int dirColor;
	private float titleHeight;
	private float subtitleHeight;
	private boolean subDate;
	private File hilightedFile;

	PlayListAdapter(Context context, int dc, int ac, int ic, int sc) {
		mContext = context;

		itemColor = ic;
		subitemColor = sc;
		archiveColor = ac;
		dirColor = dc;
		titleHeight = -1;
		subtitleHeight = -1;
	}

	public void setCursor(Cursor cursor, String dirName) {

		if(mCursor != null) {
			mCursor.close();
		}

		mCursor = cursor;
		pathName = dirName;

		if(mCursor == null) {
			return;
		}

		subDate = false;
		mSubIndex = mCursor.getColumnIndex("SUBTITLE");
		if(mSubIndex < 0) {
			mSubIndex = mCursor.getColumnIndex("COMPOSER");
		}
		if(mSubIndex < 0) {
			mSubIndex = mCursor.getColumnIndex("DATE");
			if(mSubIndex >= 0) {
				subDate = true;
			}
		}

		//Log.d(TAG, "%% SIDETITLE %d", mSideTitleIndex);

		mTitleIndex = mCursor.getColumnIndex("TITLE");
		mTypeIndex = mCursor.getColumnIndex("TYPE");
		mFileIndex = mCursor.getColumnIndex("FILENAME");
		if(mFileIndex < 0) {
			mFileIndex = mCursor.getColumnIndex("NAME");
		}
		mPathIndex = mCursor.getColumnIndex("PATH");
		notifyDataSetChanged();
		setHilightedFile(null);
	}

	@Override
	protected void finalize() throws Throwable {
		Log.d(TAG, "finalize()");
		if(mCursor != null) {
			mCursor.close();
		}
	};

	public void close() {
		if(mCursor != null) {
			mCursor.close();
			mCursor = null;
		}
	}

	@Override
	public View getView(int position, View convertView, ViewGroup parent) {

		LayoutInflater inflater = ((Activity)mContext).getLayoutInflater();

		if(convertView == null) {
			convertView = inflater.inflate(R.layout.songlist_item, parent, false);
			ViewGroup vg = (ViewGroup)convertView;
			TextView tv0 = (TextView)vg.getChildAt(1);
			TextView tv1 = (TextView)vg.getChildAt(2);
			tv1.setTextColor(subitemColor);
			if(titleHeight < 0) {
				titleHeight = tv0.getTextSize();
			}
			if(subtitleHeight < 0) {
				subtitleHeight = tv1.getTextSize();
			}
		}
		ViewGroup vg = (ViewGroup)convertView;
		ImageView iv = (ImageView)vg.getChildAt(0);
		TextView tv0 = (TextView)vg.getChildAt(1);
		TextView tv1 = (TextView)vg.getChildAt(2);

		mCursor.moveToPosition(position);
		int type = SongDatabase.TYPE_FILE;
		if(mTypeIndex >= 0) {
			type = mCursor.getInt(mTypeIndex);
		}

		String title = null;
		String sub = null;

		String filename = mCursor.getString(mFileIndex);
		if(mTitleIndex >= 0) {
			title = mCursor.getString(mTitleIndex);
		}

		if(title == null && mFileIndex >= 0) {
			title = filename;
			int sc = title.lastIndexOf(';');

			if(sc >= 0) {
				try {
					int tune = Integer.parseInt(title.substring(sc+1));
					title = String.format("%s [#%02d]", title.substring(0, sc), tune+1);
				} catch (NumberFormatException e) {
				}
			}
		}

		if(title == null) {
			title = "<ERROR>";
		}

		if(mSubIndex >= 0) {
			if(subDate) {
				int d = mCursor.getInt(mSubIndex);
				if(d > 0) {
					int year = d / 10000;
					int rest = d - year*10000;
					int month = rest / 100;
					sub = String.format("%04d %s", year, month > 0 ? monthNames[month-1] : "");
				}
			} else {
				sub = mCursor.getString(mSubIndex);
			}
		}

		if(sub == null && type == SongDatabase.TYPE_FILE) {
			sub = "Unknown";
		}

		tv0.setText(title);

		if(sub != null) {
			tv0.setTextSize(TypedValue.COMPLEX_UNIT_PX, titleHeight);
			tv1.setText(sub);
			tv1.setVisibility(View.VISIBLE);
		} else {
			tv0.setTextSize(TypedValue.COMPLEX_UNIT_PX, titleHeight + subtitleHeight/2);
			tv1.setVisibility(View.GONE);
		}


		String path = mPathIndex >= 0 ? mCursor.getString(mPathIndex) : null;
		if(path == null)
			path = pathName;

		if(type == SongDatabase.TYPE_FILE) {
			tv0.setTextColor(itemColor);
			iv.setVisibility(View.GONE);
		} else if(type == SongDatabase.TYPE_ARCHIVE) {
			tv0.setTextColor(archiveColor);
			if (title.equals("CSDb")) {
				iv.setImageResource(R.drawable.gflat_bag);
			} else {
				iv.setImageResource(R.drawable.gflat_package);
			}
			iv.setVisibility(View.VISIBLE);
		} else if(type == SongDatabase.TYPE_PLIST) {
			tv0.setTextColor(archiveColor);
			if(title.equals("Favorites")) {
				iv.setImageResource(R.drawable.gflat_heart);
			} else {
				iv.setImageResource(R.drawable.gflat_note3);
			}

			iv.setVisibility(View.VISIBLE);
		} else {
			tv0.setTextColor(dirColor);
			iv.setImageResource(R.drawable.gflat_folder);
			iv.setVisibility(View.VISIBLE);
		}

		if(position == hilightedPosition) {
			tv0.setTextColor(0xffffa000);
		}

		return convertView;
	}

	public File getFile(int position) {
		File f;
		mCursor.moveToPosition(position);
		String fileName = mCursor.getString(mFileIndex);
		if(mPathIndex >= 0 && mCursor.getString(mPathIndex) != null) {
			f = new File(mCursor.getString(mPathIndex), fileName);
		} else {
			f = new File(pathName, fileName);
		}
		return f;
	}

	public String getPath(int position) {
		mCursor.moveToPosition(position);
		String s;
		String fileName = mCursor.getString(mFileIndex);
		if(mPathIndex >= 0 && mCursor.getString(mPathIndex) != null) {
			s = mCursor.getString(mPathIndex) + "/" + fileName;
		} else {
			s = pathName + "/" + fileName;
		}
		return s;
	}


	@Override
	public int getCount() {
		if(mCursor == null)
			return 0;
		return mCursor.getCount();
	}

	@Override
	public Object getItem(int position) {
		mCursor.moveToPosition(position);
		String fileName = mCursor.getString(mFileIndex);
		String path = pathName;
		Log.d(TAG, "FILENAME " + fileName);
		if (mPathIndex >= 0 && mCursor.getString(mPathIndex) != null) {
			String p = mCursor.getString(mPathIndex);
			if(p != null) {
				path = p;
				Log.d(TAG, "PATH " + path);
			}
		}

		int type = SongDatabase.TYPE_FILE;
		if(mTypeIndex >= 0) {
			type = mCursor.getInt(mTypeIndex);
		}
		return new FileInfo(path, fileName, type);
	}

	@Override
	public long getItemId(int position) {
		return 0;
	}

	public FileInfo [] getFiles(boolean skipDirs) {

		if(mCursor == null) {
			return new FileInfo [] {};
		}

		//File [] names = new File [ mCursor.getCount() ];
		ArrayList<FileInfo> files = new ArrayList<FileInfo>();

		mCursor.moveToPosition(-1);
		while(mCursor.moveToNext()) {
			String fileName = mCursor.getString(mFileIndex);
			FileInfo f;
			if(mPathIndex >= 0 && mCursor.getString(mPathIndex) != null) {
				f = new FileInfo(mCursor.getString(mPathIndex), fileName);
			} else {
				f = new FileInfo(pathName, fileName);
			}
			//String pathName = mCursor.getString(mPathIndex);

			int type = SongDatabase.TYPE_FILE;
			if(mTypeIndex >= 0) {
				type = mCursor.getInt(mTypeIndex);
			}

			//Log.d(TAG, "File %s type %d", f.getPath(), type);

			if(!skipDirs || (type == SongDatabase.TYPE_FILE)) {
				files.add(f);
			}
		}
		FileInfo [] names = new FileInfo [ files.size() ];
		int i = 0;
		for(FileInfo f : files) {
			names[i++] = f;
		}
		return names;
	}

	public void setHilightedFile(File hfile) {
		if(hfile == null) {
			hfile = hilightedFile;
		}
		hilightedPosition = -1;
		hilightedFile = hfile;

		if(hilightedFile == null) {
			return;
		}

		FileInfo [] files = getFiles(false);
		for(int i=0; i<files.length; i++) {
			//Log.d(TAG, "%s vs %s", files[i].getPath(), hfile.getPath());
			if(hilightedFile.equals(files[i].getFile())) {
				hilightedPosition = i;
				break;
			}
		}
	}

	public Cursor getCursor() {
		return mCursor;
	}

	public Cursor getCursor(int position) {
		if(mCursor != null) {
			mCursor.moveToPosition(position);
		}
		return mCursor;
	}

	public String getPathName() {
		return pathName;
	}
}
