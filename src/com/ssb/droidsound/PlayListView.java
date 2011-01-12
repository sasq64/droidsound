package com.ssb.droidsound;

import java.io.File;
import java.util.ArrayList;

import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.utils.TouchListView;

import android.app.Activity;
import android.content.Context;
import android.database.Cursor;
import android.util.AttributeSet;
import android.util.Log;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
/**
 * 
 * a music player for playing them.
 * 
 * Each song is a name and a reference. The reference can be either to a File or
 * 
 * If the File isDirectory() that item will be rendered differently
 * 
 * 
 *
 */
public class PlayListView extends ListView { //extends TouchListView {
	private static final String TAG = "PlayListView";
	
	public static class FileInfo {
		//File file;
		int type;
		String path;
		String name;
		FileInfo(String p, String fn, int fl) {
			path = p;
			if(path.endsWith("/"))
				path = path.substring(0,path.length()-1);
			name = fn;
			type = fl;
		}

		FileInfo(String p, String fn) {
			path = p;
			if(path.endsWith("/"))
				path = path.substring(0,path.length()-1);
			name = fn;
			type = SongDatabase.TYPE_FILE;
		}

		File getFile() {
			return new File(path, name);
		}

		public String getPath() {
			return path + "/" + name;
		}
	
		public String getName() {
			return name;
		}
		
		@Override
		public int hashCode() {
			return path.hashCode() ^ name.hashCode();
		}
		
		@Override
		public boolean equals(Object o) {
			if(o instanceof FileInfo) {
				FileInfo fi = (FileInfo)o;
				return (fi.path.equals(path) && fi.name.equals(name));
			}
			return super.equals(o);
		}
		
	};
	
	public static final String [] monthNames = { "Jan", "Feb", "Mars", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dev" };
	
	private PlayListAdapter adapter;

	
	static class PlayListAdapter extends BaseAdapter {
    	
    	private Context mContext;
		private Cursor mCursor;

		private int mSubIndex;
		private int mTitleIndex;
		private int mTypeIndex;
		private int mFileIndex;
		private int mPathIndex;
		private String pathName; 
		private int hilightedPosition = -1;
		private int itemColor;
		private int subitemColor;
		private int archiveColor;
		private int dirColor;
		private float titleHeight;
		private float subtitleHeight;
		private boolean subDate;
		private File hilightedFile;
		private int mSideTitleIndex;
		private int mDateIndex;

		private boolean editMode;

		
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
    		mSideTitleIndex = mCursor.getColumnIndex("SIDETITLE");
    		mDateIndex = mCursor.getColumnIndex("DATE");
    		
    		//Log.v(TAG, String.format("%% SIDETITLE %d", mSideTitleIndex));
    		
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
			if(editMode) {
				return 1;
			} else {
				return 0;
			}
		}
		
		@Override
		public View getView(int position, View convertView, ViewGroup parent) {

			LayoutInflater inflater = ((Activity)mContext).getLayoutInflater();
			
			if(convertView == null) {
				if(editMode) {
					convertView = inflater.inflate(R.layout.editsong_item, parent, false);
				} else {
					convertView = inflater.inflate(R.layout.songlist_item, parent, false);
				}
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
			TextView tv2 = (TextView)vg.getChildAt(3);
			

			mCursor.moveToPosition(position);
			int type = SongDatabase.TYPE_FILE;
			if(mTypeIndex >= 0) {
				type = mCursor.getInt(mTypeIndex);
			}
			
			String title = null;
			String sub = null;
			String side = null;
			
			//Log.v(TAG, "DATEINDEX " + mDateIndex);
			
			if(mSideTitleIndex >= 0) {
				side = mCursor.getString(mSideTitleIndex);
			} else if(mDateIndex >= 0) {
				int date = mCursor.getInt(mDateIndex);
				if(date > 0) {
					//Log.v(TAG, "DATE " + date);
					side = String.format("(%04d)", date / 10000);
				}
			}
			
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

			if(!editMode)
				tv2.setText(side != null ? side : "");
			
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
			
			String ext = filename.substring(filename.lastIndexOf('.')+1).toUpperCase();
			
			boolean net = path != null && path.startsWith("http:/");
			
			if(type == SongDatabase.TYPE_FILE) {
				tv0.setTextColor(itemColor);
				if(net || ext.equals("M3U") || ext.equals("PLS"))
					tv0.setTextColor(0xffffc0c0);
					//iv.setImageResource(R.drawable.gflat_headphones);
				iv.setVisibility(View.GONE);
			} else if(type == SongDatabase.TYPE_ARCHIVE) {
				tv0.setTextColor(archiveColor);
				if(net)
					tv0.setTextColor(0xffff9090);
				//iv.setImageResource(R.drawable.play_list);
				if(title.equals("Local Mediastore")) {
					iv.setImageResource(R.drawable.gflat_mus_folder);
				} else if(title.equals("CSDb")) {
					iv.setImageResource(R.drawable.gflat_bag);
				} else {
					iv.setImageResource(R.drawable.gflat_package);
				}
				iv.setVisibility(View.VISIBLE);
			} else if(type == SongDatabase.TYPE_PLIST) {
				tv0.setTextColor(archiveColor);
				if(net)
					tv0.setTextColor(0xffff9090);
				//iv.setImageResource(R.drawable.play_list);
				if(title.equals("Favorites")) {
					iv.setImageResource(R.drawable.gflat_heart);
				} else {
					iv.setImageResource(R.drawable.gflat_note3);
				}

				iv.setVisibility(View.VISIBLE);
			} else {
				tv0.setTextColor(dirColor);
				if(net)
					tv0.setTextColor(0xffff9090);
				if(ext.equals("LNK")) {
					iv.setImageResource(R.drawable.gflat_net_folder);
					tv0.setTextColor(0xffffc0c0);
				} else {
					iv.setImageResource(R.drawable.gflat_folder);
				}
				iv.setVisibility(View.VISIBLE);
			}
			
			if(position == hilightedPosition) {
				tv0.setTextColor(0xffffa000);
			}
			
			if(editMode) {
				//iv.setImageResource(R.drawable.gflat_hand);
				iv.setVisibility(View.VISIBLE);
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

		public String getPath(int position) {
			mCursor.moveToPosition(position);
			String s;
			String fileName = mCursor.getString(mFileIndex);			
			if(mPathIndex >= 0) {
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
			Log.v(TAG, "FILENAME " + fileName);
			File f;
			if(mPathIndex >= 0) {
				path = mCursor.getString(mPathIndex);
				Log.v(TAG, "PATH " + path);
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
				if(mPathIndex >= 0) {
					f = new FileInfo(mCursor.getString(mPathIndex), fileName);
				} else {
					f = new FileInfo(pathName, fileName);
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
				//Log.v(TAG, String.format("%s vs %s", files[i].getPath(), hfile.getPath()));
				if(hilightedFile.equals(files[i].getFile())) {
					hilightedPosition = i;
					break;
				}
			}
		}

		public Cursor getCursor(int position) {
			if(mCursor != null) {
				mCursor.moveToPosition(position);
			}
			return mCursor;
		}
				
	}
	
		
	
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
				
		adapter = new PlayListAdapter(context, dirColor, archiveColor, itemColor, subitemColor);
		setAdapter(adapter);
	}
    
    public boolean editMode() { return adapter.editMode; }
    
    public void setEditMode(boolean on) {
    	/*
    	adapter.editMode = on;
    	if(on) {
    		setDropListener(new DropListener() {
    			@Override
    			public void drop(int from, int to) {
    				Log.v(TAG, "X");
    				EditableCursor ec = (EditableCursor) adapter.mCursor;
    				ec.moveRow(from, to);
    				adapter.notifyDataSetChanged();
    			}
    		});
    		
    		setRemoveListener(new RemoveListener() {
    			@Override
    			public void remove(int which) {
    				Log.v(TAG, "Y");
    				EditableCursor ec = (EditableCursor) adapter.mCursor;
    				ec.removeRow(which);
    				adapter.notifyDataSetChanged();
    			}
    		});
    	} else {
    		setDropListener(null);
    		setRemoveListener(null);
    	}
    	//redraw();
    	adapter.notifyDataSetChanged(); */
    	
    }

	public void rescan() {
		//adapter.setCursor(dataBase.getFilesInPath(pathName), pathName);
		if(adapter.mCursor != null) {
			adapter.mCursor.requery();
		}
		adapter.notifyDataSetChanged();
		adapter.setHilightedFile(null);
	}
	
	public void setHilighted(String name) {
		
		Log.v(TAG, String.format("SET_HILIGHT %s", name));
		adapter.setHilightedFile(new File(name));
		//hilightedName = name;
		adapter.notifyDataSetChanged();
		//adapter.setSelectedPosition(position);
		//setSelectionFromTop(position, getHeight()/4);
	}
	
	public void setScrollPosition(String name) {
		if(name == null) {
			setSelectionFromTop(0, 0);
		} else {
			FileInfo [] files = adapter.getFiles(false);
			for(int i=0; i<files.length; i++) {
				//Log.v(TAG, String.format("%s vs %s", files[i].getPath(), name));
				if(name.equals(files[i].getPath())) {
					Log.v(TAG, String.format("Scrolling to %s", name));
					setSelectionFromTop(i, 0);
					return;
				}
			}
			Log.v(TAG, String.format("Could not scroll to %s", name));
		}
	}

	public void redraw() {
		adapter.notifyDataSetChanged();
	}

	public void close() {
		adapter.close();
	}

	public Cursor getCursor(int position) {
		return adapter.getCursor(position);		
	}
	
	public Cursor obtainCursor() {
		Cursor c = adapter.mCursor;
		adapter.mCursor = null;
		return c;
	}
	
	public String getPath() {
		return adapter.pathName;
	}
	
	public File getFile(int position) {
		return adapter.getFile(position);
	}
	
	public void setCursor(Cursor cursor, String dirName) {
		adapter.setCursor(cursor, dirName);
	}

	public FileInfo [] getFiles(boolean b) {
		return adapter.getFiles(b);
	}

	public String getPath(int position) {
		return adapter.getPath(position);
	}

	
}
