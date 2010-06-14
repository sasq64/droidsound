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
	    	CursorAdapter adapter = new CursorAdapter(this, cursor) {
				@Override
				public void bindView(View view, Context context, Cursor cursor) {
					((TextView)view).setText(cursor.getString(1));
				}

				@Override
				public View newView(Context context, Cursor cursor, ViewGroup parent) {
					TextView tv = new TextView(context);					
					tv.setText(cursor.getString(1));
					return tv;
				}
			};
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
