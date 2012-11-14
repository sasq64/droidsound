package com.ssb.droidsound.playlistview;

import java.io.File;

import android.content.Context;
import android.database.Cursor;
import android.util.AttributeSet;
import android.widget.ListView;

import com.ssb.droidsound.utils.Log;

/**
 * A ListView that lists songfiles. 
 * 
 * 
 *
 */
public class PlayListView extends ListView { //extends TouchListView {
	private static final String TAG = "PlayListView";

	private PlayListAdapter adapter;
	
    public PlayListView(final Context context, AttributeSet attrs) {
		super(context, attrs);
		
		int itemColor = 0xFFA0A0FF;
		int subitemColor = 0xFFA0A0FF;
		int archiveColor = 0xFFFFA080;
		int dirColor = 0xFFA0A080;

		if(attrs != null) {
			for(int i=0; i<attrs.getAttributeCount(); i++) {
				String name = attrs.getAttributeName(i);
				if(name != null) {
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
				} else {
					Log.d(TAG, "ATTR %d: %d", i, attrs.getAttributeNameResource(i));
				}
			}
		}

		adapter = new PlayListAdapter(this, context, dirColor, archiveColor, itemColor, subitemColor);
		setAdapter(adapter);

	}
    
    /*
    public PlayListView(Context context) {
    	super(context);
      	
		int itemColor = 0xFFFFFFFF;
		int subitemColor = 0xFFA0A0FF;
		int archiveColor = 0xFFFFFFA0;
		int dirColor = 0xFFFFFFA0;

		adapter = new PlayListAdapter(context, dirColor, archiveColor, itemColor, subitemColor);
		setAdapter(adapter);
    } */
    
    
   // public boolean editMode() { return adapter.isEditMode(); }
    
    public void setEditMode(boolean on) {
    	/*
    	adapter.editMode = on;
    	if(on) {
    		setDropListener(new DropListener() {
    			@Override
    			public void drop(int from, int to) {
    				Log.d(TAG, "X");
    				EditableCursor ec = (EditableCursor) adapter.mCursor;
    				ec.moveRow(from, to);
    				adapter.notifyDataSetChanged();
    			}
    		});
    		
    		setRemoveListener(new RemoveListener() {
    			@Override
    			public void remove(int which) {
    				Log.d(TAG, "Y");
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

	@SuppressWarnings("deprecation") // TODO: Really should fix this deprecation
	public void rescan() {
		//adapter.setCursor(dataBase.getFilesInPath(pathName), pathName);
		if(adapter.getCursor() != null) {
			adapter.getCursor().requery();
		}
		adapter.notifyDataSetChanged();
		adapter.setHilightedFile(null);
	}
	
	public void setHilighted(String name) {
		
		Log.d(TAG, "SET_HILIGHT %s", name);
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
				//Log.d(TAG, "%s vs %s", files[i].getPath(), name);
				if(name.equals(files[i].getPath())) {
					Log.d(TAG, "Scrolling to %s", name);
					setSelectionFromTop(i, 0);
					return;
				}
			}
			Log.d(TAG, "Could not scroll to %s", name);
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
	
	/*
	public Cursor obtainCursor() {
		Cursor c = adapter.getCursor();
		adapter.mCursor = null;
		return c;
	} */
	
	public String getPath() {
		return adapter.getPathName();
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

	public void init() {
		adapter.init();
	}

	
}
