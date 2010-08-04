package com.ssb.droidsound;

import java.io.File;
import java.util.ArrayList;

import android.app.Activity;
import android.content.Context;
import android.database.Cursor;
import android.util.AttributeSet;
import android.util.Log;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
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
	
	public static class FileInfo {
		File file;
		int type;
		FileInfo(File f, int fl) {
			file = f;
			type = fl;
		}
	};
	
	public static final String [] monthNames = { "Jan", "Feb", "Mars", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dev" };
	
	static class PlayListAdapter extends BaseAdapter {
    	
    	private Context mContext;
		private Cursor mCursor;

		private int mSubIndex;
		private int mTitleIndex;
		private int mTypeIndex;
		private int mFileIndex;
		private int mPathIndex;
		private String pathName; 
		private int selectedPosition = -1;
		private int itemColor;
		private int subitemColor;
		private int archiveColor;
		private int dirColor;
		private float titleHeight;
		private float subtitleHeight;
		private boolean subDate;

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
    		mTitleIndex = mCursor.getColumnIndex("TITLE");
    		mTypeIndex = mCursor.getColumnIndex("TYPE");
    		mFileIndex = mCursor.getColumnIndex("FILENAME");
    		if(mFileIndex < 0) {
    			mFileIndex = mCursor.getColumnIndex("NAME");
    		}
    		mPathIndex = mCursor.getColumnIndex("PATH");
    		notifyDataSetChanged();
    		selectedPosition = -1;
		}
		
		protected void finalize() throws Throwable {
			Log.v(TAG, "FINALIIIIIIIIZE!");
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

			LayoutInflater inflater = ((Activity)mContext).getLayoutInflater();

			if(convertView == null) {
				convertView = inflater.inflate(R.layout.songlist_item, null);
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

			if(mTitleIndex >= 0) {
				title = mCursor.getString(mTitleIndex);
			}
			
			if(title == null && mFileIndex >= 0) {
				title = mCursor.getString(mFileIndex);
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

			if(type == SongDatabase.TYPE_FILE) {
				tv0.setTextColor(itemColor);
				iv.setVisibility(View.GONE);
			} else if(type == SongDatabase.TYPE_ARCHIVE) {
				tv0.setTextColor(archiveColor);
				//iv.setImageResource(R.drawable.play_list);
				iv.setImageResource(R.drawable.gflat_folder);
				iv.setVisibility(View.VISIBLE);
			} else if(type == SongDatabase.TYPE_PLIST) {
				tv0.setTextColor(archiveColor);
				//iv.setImageResource(R.drawable.play_list);
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
			
			if(position == selectedPosition) {
				tv0.setTextColor(0xffffa000);
			}
			
			return convertView;
		}
		
		public File getFile(int position) {
			File f;
			mCursor.moveToPosition(position);
			String fileName = mCursor.getString(mFileIndex);			
			if(mPathIndex >= 0) {
				f = new File(mCursor.getString(mPathIndex), fileName);
			} else {
				f = new File(pathName, fileName);
			}
			return f;
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
			File f;
			if(mPathIndex >= 0) {
				f = new File(mCursor.getString(mPathIndex), fileName);
			} else {
				f = new File(pathName, fileName);
			}				
			int type = SongDatabase.TYPE_FILE;
			if(mTypeIndex >= 0) {
				type = mCursor.getInt(mTypeIndex);
			}
			return new FileInfo(f, type);
		}

		@Override
		public long getItemId(int position) {
			return 0;
		}

		public File[] getFiles(boolean skipDirs) {
			
			if(mCursor == null) {
				return new File [] {};
			}
			
			//File [] names = new File [ mCursor.getCount() ];
			ArrayList<File> files = new ArrayList<File>();
						
			mCursor.moveToPosition(-1);
			while(mCursor.moveToNext()) {
				String fileName = mCursor.getString(mFileIndex);
				File f;
				if(mPathIndex >= 0) {
					f = new File(mCursor.getString(mPathIndex), fileName);
				} else {
					f = new File(pathName, fileName);
				}	
				//String pathName = mCursor.getString(mPathIndex);
				
				int type = SongDatabase.TYPE_FILE;
				if(mTypeIndex >= 0) {
					type = mCursor.getInt(mTypeIndex);
				}
				
				//Log.v(TAG, String.format("File %s type %d", f.getPath(), type));
				
				if(!skipDirs || (type == SongDatabase.TYPE_FILE)) {
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
			if(name == null) {
				return -1;
			}
			File [] files = getFiles(false);
			int realpos = -1;
			for(int i=0; i<files.length; i++) {
				//Log.v(TAG, String.format("%s vs %s", files[i].getPath(), name));
				if(name.equals(files[i].getPath())) {
					setSelectedPosition(i);
					realpos = i;
					break;
				}
			}
			return realpos;
		}

		public Cursor getCursor(int position) {
			if(mCursor != null) {
				mCursor.moveToPosition(position);
			}
			return mCursor;
		}
				
	}
	
	public static interface DirChangeCallback {
		void dirChange(String dir, String title);
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
	private String selectedName;

    public PlayListView(Context context, AttributeSet attrs) {
		super(context, attrs);
		
		int itemColor = 0xFFA0A0FF;
		int subitemColor = 0xFFA0A0FF;
		int archiveColor = 0xFFFFA080;
		int dirColor = 0xFFA0A080;

		
		for(int i=0; i<attrs.getAttributeCount(); i++) {
			String name = attrs.getAttributeName(i);
			if(name.equals("dirColor")) {
				dirColor = attrs.getAttributeIntValue(i, -1);
			} else
			if(name.equals("archiveColor")) {
				archiveColor = attrs.getAttributeIntValue(i, -1);
			} else
			if(name.equals("itemColor")) {
				itemColor = attrs.getAttributeIntValue(i, -1);
			}
			if(name.equals("subitemColor")) {
				subitemColor = attrs.getAttributeIntValue(i, -1);
			}
		}
				
		//Typeface tf = Typeface.createFromAsset(context.getAssets(), "fonts/topaz_plus1200.ttf");
		
		adapter = new PlayListAdapter(context, dirColor, archiveColor, itemColor, subitemColor);
		setAdapter(adapter);
		
		setOnItemLongClickListener(new OnItemLongClickListener() {
			@Override
			public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
				return false;
			}
		});
				
        setOnItemClickListener(new OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View view, int position, long id) {				
				//mPlayer.playList(names, position-1);
				FileInfo fi = (FileInfo) adapter.getItem(position);
				if(fi.file != null) {
					selectedFile = fi.file;
					if(fi.type == SongDatabase.TYPE_DIR || fi.type == SongDatabase.TYPE_ARCHIVE || fi.type == SongDatabase.TYPE_PLIST) {
						setDirectory(fi.file.getPath());
					} else {
						int index = 0;
						File [] files = adapter.getFiles(true); 
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

    public void setDatabase(SongDatabase db) {
    	dataBase = db;
    }

    public void setDirectory(String parent) {
    	
    	//int bi = parent.indexOf(baseDir);
    	//if(bi >= 0) {
    	//	parent = parent.substring(bi);
    	
    	Playlist.flushAll();


    	pathName = parent;    	
    	adapter.setCursor(dataBase.getFilesInPath(pathName), pathName);
    	adapter.setSelectedFile(selectedName);
    	if(dirChangeCallback != null) {
    		dirChangeCallback.dirChange(pathName, dataBase.getPathTitle());
    	}
    	
    	//adapter.setHasParent(!pathName.equals(baseDir));
    }
    
    public void gotoParent() {
    	String s = pathName;

    	pathName = new File(pathName).getParent();
    	if(pathName == null) {
    		return;
    	}
    	adapter.setCursor(dataBase.getFilesInPath(pathName), pathName);

    	if(dirChangeCallback != null) {
    		dirChangeCallback.dirChange(pathName, dataBase.getPathTitle());
    	}
   
    	File [] files = adapter.getFiles(false);
    	Log.v(TAG, String.format("PARENT from %s", s));
		for(int i=0; i<files.length; i++) {
			//Log.v(TAG, String.format("%s vs %s", files[i].getPath(), s));
			if(s.equals(files[i].getPath())) {
				setSelection(i);
				break;
			}
		}
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
		adapter.setSelectedFile(selectedName);
	}
	
	public void selectPosition(int position) {
	}

	public void setSelection(String name) {
		
		Log.v(TAG, String.format("SET_SELECTION %s", name));
		int position = adapter.setSelectedFile(name);
		selectedName = name;
		adapter.notifyDataSetChanged();
		//adapter.setSelectedPosition(position);
		setSelectionFromTop(position, getHeight()/4);
	}

	public void redraw() {
		adapter.notifyDataSetChanged();
	}

	public void setBaseDir(String modDir) {
		setDirectory(modDir);
	}

	public void search(String query) {
		boolean csdb = false;
		if(pathName.toUpperCase().contains("/CSDB.DUMP")) {
			csdb = true;
		}  		
		Cursor cursor = dataBase.search(query, csdb);

		if(!pathName.endsWith("/SEARCH")) {
			pathName = pathName + "/SEARCH";
		}
    	adapter.setCursor(cursor, null);    	
    	if(dirChangeCallback != null) {
    		dirChangeCallback.dirChange(pathName, dataBase.getPathTitle());
    	}
	}
	
	public void close() {
		adapter.close();
	}

	public Cursor getCursor(int position) {
		return adapter.getCursor(position);		
	}
	
	public File getFile(int position) {
		return adapter.getFile(position);
	}
	
}
