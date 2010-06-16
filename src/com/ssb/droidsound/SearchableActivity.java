package com.ssb.droidsound;

import android.app.ListActivity;
import android.app.SearchManager;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CursorAdapter;
import android.widget.TextView;

public class SearchableActivity extends ListActivity {
	private static final String TAG = SearchableActivity.class.getSimpleName();

	private SongDatabase songDatabase;

	private Cursor cursor;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

	    Intent intent = getIntent();

	    if(Intent.ACTION_SEARCH.equals(intent.getAction())) {
	    	songDatabase = new SongDatabase(this);
	    	String query = intent.getStringExtra(SearchManager.QUERY);
	 		Log.v(TAG, "QUERY " + query);
	    	cursor = songDatabase.search(query);
	    	CursorAdapter adapter = new SongListAdapter(this, cursor);
	    	setListAdapter(adapter);
	    }
	}
	
	@Override
	protected void onDestroy() {
		super.onDestroy();
		cursor.close();
		songDatabase.closeDB();
	}
}
