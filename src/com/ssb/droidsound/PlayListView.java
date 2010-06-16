package com.ssb.droidsound;

import java.io.File;

import android.app.Activity;
import android.content.Context;
import android.database.Cursor;
import android.graphics.Typeface;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.AdapterView.OnItemClickListener;
/**
 * 
 * A ListView that presents a list of songs, and that maintains a connection to
 * a music player for playing them.
 * 
 * Each song is a name and a reference. The reference can be either to a File or
 * 
 * If the File isDirectory() that item will be rendered differently
 * 
 * 
 *
 */
public class PlayListView extends ListView {
	
	static class FileListAdapter extends BaseAdapter {
    	
    	private Context mContext;
		private Typeface mTypeface;
		private Cursor mSongCursor;
		private Cursor mDirCursor;

		private int mHeaderIndex;
		private int mItemIndex;
		private int mDirIndex;
		private String mDirName; 

		FileListAdapter(Context context, Typeface tf) {
    		mContext = context;
    		mTypeface = tf;
    	}
		
		public void setCursors(Cursor songCursor, Cursor dirCursor, String dirName) {
			
			if(mSongCursor != null) {
				mSongCursor.close();
			}
			if(mDirCursor != null) {
				mDirCursor.close();
			}
			
    		mSongCursor = songCursor;
    		mDirCursor = dirCursor;
    		mDirName = dirName;
    		mHeaderIndex = mSongCursor.getColumnIndex("COMPOSER");
    		mItemIndex = mSongCursor.getColumnIndex("TITLE");
    		mDirIndex = mDirCursor.getColumnIndex("FILENAME");
    		notifyDataSetChanged();
		}
    	
		
		@Override
		public View getView(int position, View convertView, ViewGroup parent) {

			View view = null;
			LayoutInflater inflater = ((Activity)mContext).getLayoutInflater();
			
			if(convertView == null) {
				convertView = inflater.inflate(R.layout.songlist_item, null);
			}
			
			TextView tv = (TextView)convertView;
			
			int dcount = mDirCursor.getCount();

			if(position == 0) {
				tv.setTextColor(0xFF4040F0);
				tv.setText("..");
			} else if(position <= dcount ) {
				tv.setTextColor(0xFF4040F0);
				mDirCursor.moveToPosition(position-1);
				tv.setText(mDirCursor.getString(mDirIndex));
			} else {
				position -= (dcount+1);
				tv.setTextColor(0xFF000000);
				mSongCursor.moveToPosition(position);
				tv.setText(mSongCursor.getString(mItemIndex));
			}
			return convertView;
		}
		
		public File getFile(int position) {
			int dc = mDirCursor.getCount();
			if(position == 0) {
				return new File(mDirName).getParentFile();
			} else if(position <= dc) {
				mDirCursor.moveToPosition(position-1);
				String fileName = mDirCursor.getString(mDirCursor.getColumnIndex("FILENAME"));
				String pathName = mDirCursor.getString(mDirCursor.getColumnIndex("PATH"));
				return new File(pathName, fileName);
			} else {
				mSongCursor.moveToPosition(position-dc-1);
				String fileName = mSongCursor.getString(mSongCursor.getColumnIndex("FILENAME"));
				String pathName = mSongCursor.getString(mSongCursor.getColumnIndex("PATH"));
				return new File(pathName, fileName);
			}
		}

	
		@Override
		public int getCount() {
			int count = 0;			
			if(mSongCursor != null) {
				count += mSongCursor.getCount();
			}
			if(mDirCursor != null) {
				count += mDirCursor.getCount();
			}
			return count + 1;
		}

		@Override
		public Object getItem(int position) {
			// TODO Auto-generated method stub
			return getFile(position);
		}

		@Override
		public long getItemId(int position) {
			// TODO Auto-generated method stub
			return 0;
		}

	}

    static class PlayListAdapter extends BaseAdapter {
    	
    	private Context mContext;
		private Typeface mTypeface;
		private Cursor mSongCursor;
		private Cursor mDirCursor;

		private int mHeaderIndex;
		private int mItemIndex;

		PlayListAdapter(Context context, Typeface tf) {
    		mContext = context;
    		mTypeface = tf;
    	}
		
		public void setCursors(Cursor songCursor, Cursor dirCursor) {
    		mSongCursor = songCursor;
    		mDirCursor = dirCursor;
    		mHeaderIndex = mSongCursor.getColumnIndex("COMPOSER");
    		mItemIndex = mSongCursor.getColumnIndex("TITLE");
    		notifyDataSetChanged();
		}
    	
		
		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			LayoutInflater inflater = ((Activity)mContext).getLayoutInflater();
			String oldHeader = null;
			if(position > 0) {
				mSongCursor.moveToPosition(position-1);
				oldHeader = mSongCursor.getString(mHeaderIndex);
				mSongCursor.moveToNext();
			} else {
				mSongCursor.moveToPosition(position);
			}
			
			String item = mSongCursor.getString(mItemIndex);
			String header = mSongCursor.getString(mHeaderIndex);
			
			TextView headerView;
			TextView itemView;

			if(convertView == null) {
				convertView = inflater.inflate(R.layout.songlist_header, null);
				headerView = (TextView)((ViewGroup)convertView).getChildAt(0);
				itemView = (TextView)((ViewGroup)convertView).getChildAt(1);
				headerView.setTextSize(10.7F);
				headerView.setTypeface(mTypeface);
				itemView.setTextSize(21.2F);
				itemView.setTypeface(mTypeface);
			} else {
				headerView = (TextView)((ViewGroup)convertView).getChildAt(0);
				itemView = (TextView)((ViewGroup)convertView).getChildAt(1);
			}
			if(!header.equals(oldHeader)) {
				headerView.setText(header);
				headerView.setVisibility(View.VISIBLE);
			} else {
				headerView.setVisibility(View.GONE);
			}
			itemView.setText(item);
			
			return convertView;
			
		}
		
		public File getFile(int position) {
			mSongCursor.moveToPosition(position);
			String fileName = mSongCursor.getString(mSongCursor.getColumnIndex("FILENAME"));
			String pathName = mSongCursor.getString(mSongCursor.getColumnIndex("PATH"));
			return new File(pathName, fileName);
			
		}

		@Override
		public long getItemId(int position) {
			// TODO Auto-generated method stub
			return position;
		}
		
		@Override
		public Object getItem(int position) {
			// TODO Auto-generated method stub
			return getFile(position);
		}
		
		@Override
		public int getCount() {
			if(mSongCursor == null) {
				return 0;
			}
			// TODO Auto-generated method stub
			return mSongCursor.getCount();
		}
	}
    
	private FileListAdapter adapter;
	private PlayerServiceConnection mPlayer;
	private SongDatabase dataBase;

    public PlayListView(Context context, AttributeSet attrs) {
		super(context, attrs);
		Typeface tf = Typeface.createFromAsset(context.getAssets(), "fonts/topaz_plus1200.ttf");
		dataBase = new SongDatabase(context);
		
		adapter = new FileListAdapter(context, tf);
		setAdapter(adapter);
		
        setOnItemClickListener(new OnItemClickListener() {
			@Override
			public void onItemClick(AdapterView<?> parent, View view, int position, long id) {				
				//mPlayer.playList(names, position-1);
				File file = adapter.getFile(position);
				if(file != null) {
					if(file.isDirectory()) {
						setDirectory(file);
					} else {
						mPlayer.playMod(file.getPath());
					}
				}
			}
		});
	}

   // public void setDatabase(SongDatabase db) {
   // 	dataBase = db;
    //}

    public void setDirectory(File parent) {
    	String pathName = parent.getPath();
    	adapter.setCursors(dataBase.getSongsInPath(pathName), dataBase.getDirsInPath(pathName), pathName);
    }

    public void setPlayer(PlayerServiceConnection player) {
    	mPlayer = player;
    }

	public void rescan() {
		adapter.notifyDataSetChanged();		
	}
}
