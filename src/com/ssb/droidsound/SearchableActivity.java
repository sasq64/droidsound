package com.ssb.droidsound;

import android.app.ListActivity;
import android.app.SearchManager;
import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.util.Log;

public class SearchableActivity extends ListActivity {
	private static final String TAG = SearchableActivity.class.getSimpleName();

	private SongDatabase songDatabase;

	private Cursor cursor;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

	    Intent intent = getIntent();

	    if(Intent.ACTION_SEARCH.equals(intent.getAction())) {
	    	songDatabase = new SongDatabase(this, null);
	    	String query = intent.getStringExtra(SearchManager.QUERY);
	 		Log.v(TAG, "QUERY " + query);
	    	cursor = songDatabase.search(query);
	    	SongListAdapter adapter = new SongListAdapter(this, cursor);
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
