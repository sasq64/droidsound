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

	private final PlayListAdapter adapter;

    public PlayListView(Context context, AttributeSet attrs) {
		super(context, attrs);

		int itemColor = 0xFFA0A0FF;
		int subitemColor = 0xFFA0A0FF;
		int archiveColor = 0xFFFFA080;
		int dirColor = 0xFFA0A080;

		for (int i=0; i<attrs.getAttributeCount(); i++) {
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

	public void rescan() {
		if(adapter.getCursor() != null) {
			adapter.getCursor().requery();
		}
		adapter.notifyDataSetChanged();
		adapter.setHilightedFile(null);
	}

	public void setHilighted(String name) {
		adapter.setHilightedFile(new File(name));
		adapter.notifyDataSetChanged();
	}

	public void setScrollPosition(String name) {
		if(name == null) {
			setSelectionFromTop(0, 0);
		} else {
			FileInfo [] files = adapter.getFiles(false);
			for(int i=0; i<files.length; i++) {
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


}
