package com.ssb.droidsound;

import java.io.File;

import android.app.Activity;
import android.content.Context;
import android.database.Cursor;
import android.graphics.Typeface;
import android.util.AttributeSet;
import android.util.Log;
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
	private static final String TAG = "PlayListView";
	
	static class FileListAdapter extends BaseAdapter {
    	
    	private Context mContext;
		private Typeface mTypeface;
		private Cursor mSongCursor;
		private Cursor mDirCursor;

		private int mHeaderIndex;
		private int mItemIndex;
		private int mDirIndex;
		private String mDirName; 
		private int selectedPosition = -1;
		private boolean hasParent;

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
    		selectedPosition = -1;
		}
		
		@Override
		public int getViewTypeCount() { return 2; }
		
		@Override
		public int getItemViewType(int position) {
			if(position == selectedPosition) {
				return 1;
			} else {
				return 0;
			}
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
				tv.setTextColor(0xFFA0A0FF);
				tv.setText("..");
			} else if(position <= dcount ) {
				tv.setTextColor(0xFFA0A0FF);
				mDirCursor.moveToPosition(position-1);
				tv.setText(mDirCursor.getString(mDirIndex));
			} else {
				
				if(position == selectedPosition) {
					tv.setTextColor(0xFFFFFFA0);
				} else {
					tv.setTextColor(0xFF000000);
				}

				position -= (dcount+1);
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

		public File[] getFiles() {
			
			int fnIndex = mSongCursor.getColumnIndex("FILENAME");
			int pIndex = mSongCursor.getColumnIndex("PATH");
			
			File [] names = new File [ mSongCursor.getCount() ];
						
			mSongCursor.moveToFirst();
			for(int i=0; i<names.length; i++) {
				String fileName = mSongCursor.getString(fnIndex);
				String pathName = mSongCursor.getString(pIndex);
				names[i] = new File(pathName, fileName);
				mSongCursor.moveToNext();
			}			
			return names;
		}

		void setSelectedPosition(int pos) {
			selectedPosition = pos;
		}

		public int setSelectedFile(String name) {
			File [] files = getFiles();
			int realpos = -1;
			for(int i=0; i<files.length; i++) {
				//Log.v(TAG, String.format("%s vs %s", files[i].getPath(), name));
				if(name.equals(files[i].getPath())) {
					realpos = i + mDirCursor.getCount() + 1;
					setSelectedPosition(realpos);
				}
			}
			return realpos;
		}

		public void setHasParent(boolean b) {
			hasParent = b;
		}
	}

    static class PlayListAdapter extends BaseAdapter {
    	
    	private Context mContext;
		private Typeface mTypeface;
		private Cursor mSongCursor;
		private Cursor mDirCursor;

		private int mHeaderIndex;
		private int mItemIndex;
		private int selectedPosition = -1;

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
    		selectedPosition = -1;

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
			
			if(position == selectedPosition) {
				itemView.setTextColor(0xffffffff);
			} else {
				itemView.setTextColor(0xff000000);
			}
			
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
		
		void setSelectedPosition(int pos) {
			selectedPosition = pos;
		}
	}
    
	private FileListAdapter adapter;
	private PlayerServiceConnection mPlayer;
	private SongDatabase dataBase;
	
	private File selectedFile;
	private String pathName;
	private String baseDir;
	
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
					selectedFile = file;
					if(file.isDirectory()) {
						setDirectory(file.getPath());
					} else {
						int index = 0;
						File [] files = adapter.getFiles(); 
						String [] names = new String [files.length];
						for(int i=0; i<files.length; i++) {
							if(files[i].equals(file)) {
								index = i;
							}
							names[i] = files[i].getPath();
						}
						mPlayer.playList(names, index);
						adapter.notifyDataSetChanged();
						//adapter.setSelectedPosition(position);
					}
				}
			}
		});
	}

   // public void setDatabase(SongDatabase db) {
   // 	dataBase = db;
    //}

    public void setDirectory(String parent) {
    	
    	int bi = parent.indexOf(baseDir);
    	if(bi >= 0) {
    		parent = parent.substring(bi);
    	}

    	pathName = parent;    	
    	adapter.setCursors(dataBase.getSongsInPath(pathName), dataBase.getDirsInPath(pathName), pathName);
    	//adapter.setHasParent(!pathName.equals(baseDir));
    }

    public void setPlayer(PlayerServiceConnection player) {
    	mPlayer = player;
    }

	public void rescan() {
    	adapter.setCursors(dataBase.getSongsInPath(pathName), dataBase.getDirsInPath(pathName), pathName);
		adapter.notifyDataSetChanged();
		adapter.setSelectedPosition(-1);
	}
	
	public void selectPosition(int position) {
	}

	public void setSelection(String name) {
		
		int position = adapter.setSelectedFile(name);
		adapter.notifyDataSetChanged();
		//adapter.setSelectedPosition(position);
		setSelectionFromTop(position, getHeight()/2);
	}

	public void redraw() {
		adapter.notifyDataSetChanged();
	}

	public void setBaseDir(String modDir) {
		setDirectory(modDir);
		baseDir = modDir;
	}
}
