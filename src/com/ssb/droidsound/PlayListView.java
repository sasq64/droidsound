package com.ssb.droidsound;

import java.io.File;
import java.util.ArrayList;

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
	
	private static class FileInfo {
		File file;
		int flags;
		FileInfo(File f, int fl) {
			file = f;
			flags = fl;
		}
	};
	
	static class PlayListAdapter extends BaseAdapter {
    	
    	private Context mContext;
		private Typeface mTypeface;
		private Cursor mCursor;

		private int mAuthorIndex;
		private int mTitleIndex;
		private int mFlagsIndex;
		private int mFileIndex;
		private int mPathIndex;
		private String mDirName; 
		private int selectedPosition = -1;
		private boolean hasParent;

		PlayListAdapter(Context context, Typeface tf) {
    		mContext = context;
    		mTypeface = tf;
    	}
		
		public void setCursor(Cursor cursor, String dirName) {
			
			if(mCursor != null) {
				mCursor.close();
			}
			
    		mCursor = cursor;
    		mDirName = dirName;
    		mAuthorIndex = mCursor.getColumnIndex("COMPOSER");
    		mTitleIndex = mCursor.getColumnIndex("TITLE");
    		mFlagsIndex = mCursor.getColumnIndex("FLAGS");
    		mFileIndex = mCursor.getColumnIndex("FILENAME");
    		mPathIndex = mCursor.getColumnIndex("PATH");
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
			ViewGroup vg = (ViewGroup)convertView;

			TextView tv0 = (TextView)vg.getChildAt(0);
			TextView tv1 = (TextView)vg.getChildAt(1);

			mCursor.moveToPosition(position);
			int flags = mCursor.getInt(mFlagsIndex);
			
			
			if((flags & 1) != 0) {
				tv0.setText(mCursor.getString(mTitleIndex));
				tv1.setText(mCursor.getString(mAuthorIndex));
				tv0.setTextColor(0xFFA0A0FF);
				tv1.setVisibility(View.VISIBLE);
			}
			else if((flags & 2) != 0) {
				tv0.setText(mCursor.getString(mFileIndex));
				tv0.setTextColor(0xFFA0A080);
				tv1.setVisibility(View.GONE);				
			} else {
				tv0.setText(mCursor.getString(mFileIndex));
				tv0.setTextColor(0xFFA0A080);
				tv1.setVisibility(View.GONE);				
			}
			
			if(position == selectedPosition) {
				tv0.setTextColor(0xFFFFFFFF);
			}
			
			return convertView;
		}
		
		/*public File getFile(int position) {
			mCursor.moveToPosition(position);
			String fileName = mCursor.getString(mCursor.getColumnIndex("FILENAME"));
			String pathName = mCursor.getString(mCursor.getColumnIndex("PATH"));
			return new File(pathName, fileName);
		}*/

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
			String pathName = mCursor.getString(mPathIndex);
			int flags = mCursor.getInt(mFlagsIndex);
			return new FileInfo(new File(pathName, fileName), flags);
		}

		@Override
		public long getItemId(int position) {
			// TODO Auto-generated method stub
			return 0;
		}

		public File[] getFiles() {
			
			//File [] names = new File [ mCursor.getCount() ];
			ArrayList<File> files = new ArrayList<File>();
						
			mCursor.move(-1);
			while(mCursor.moveToNext()) {
				String fileName = mCursor.getString(mFileIndex);
				String pathName = mCursor.getString(mPathIndex);
				int flags = mCursor.getInt(mFlagsIndex);
				File f = new File(pathName, fileName);
				if((flags & 1) != 0) {
					files.add(f);
				}
			}
			File [] names = new File [ files.size() ];
			int i = 0;
			for(File f : files) {
				names[i++] = f;
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
					setSelectedPosition(i);
					realpos = i;
				}
			}
			return realpos;
		}

		public void setHasParent(boolean b) {
			hasParent = b;
		}
	}
	
	public static interface DirChangeCallback {
		void dirChange(String dir);
	}

	private DirChangeCallback dirChangeCallback;
	
	public void setOnDirChangeCallback(DirChangeCallback cb) {
		dirChangeCallback = cb;
	}
	
    
	private PlayListAdapter adapter;
	private PlayerServiceConnection mPlayer;
	private SongDatabase dataBase;
	
	private File selectedFile;
	private String pathName;
	private String baseDir;
	
    public PlayListView(Context context, AttributeSet attrs) {
		super(context, attrs);
		Typeface tf = Typeface.createFromAsset(context.getAssets(), "fonts/topaz_plus1200.ttf");
		dataBase = new SongDatabase(context);
		
		adapter = new PlayListAdapter(context, tf);
		setAdapter(adapter);
				
        setOnItemClickListener(new OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View view, int position, long id) {				
				//mPlayer.playList(names, position-1);
				FileInfo fi = (FileInfo) adapter.getItem(position);
				if(fi.file != null) {
					selectedFile = fi.file;
					String name = fi.file.getName().toUpperCase();
					if(fi.flags == 0 || fi.flags == 2) {
						setDirectory(fi.file.getPath());
					} else {
						int index = 0;
						File [] files = adapter.getFiles(); 
						String [] names = new String [files.length];
						for(int i=0; i<files.length; i++) {
							if(files[i].equals(fi.file)) {
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
    	adapter.setCursor(dataBase.getFilesInPath(pathName), pathName);
    	
    	if(dirChangeCallback != null) {
    		dirChangeCallback.dirChange(pathName);
    	}
    	
    	//adapter.setHasParent(!pathName.equals(baseDir));
    }
    
    public void gotoParent() {    	
    	setDirectory(new File(pathName).getParent());
    }
    
    public String getDirectory() {
    	return pathName;
    }

    public void setPlayer(PlayerServiceConnection player) {
    	mPlayer = player;
    }

	public void rescan() {
		adapter.setCursor(dataBase.getFilesInPath(pathName), pathName);
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
		baseDir = modDir;
		setDirectory(modDir);
	}

	public void search(String query) {
		Cursor cursor = dataBase.search(query);
    	pathName = pathName + "/SEARCH";    	
    	adapter.setCursor(cursor, pathName);    	
    	if(dirChangeCallback != null) {
    		dirChangeCallback.dirChange(pathName);
    	}
	
	}
}
