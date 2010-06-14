package com.ssb.droidsound;

import android.app.ListActivity;
import android.app.SearchManager;
import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;

public class SearchableActivity extends ListActivity {
	private static final String TAG = SearchableActivity.class.getSimpleName();

	private SongDatabase songDatabase;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

	    Intent intent = getIntent();

	    if(Intent.ACTION_SEARCH.equals(intent.getAction())) {
	    	songDatabase = new SongDatabase(this);
	    	String query = intent.getStringExtra(SearchManager.QUERY);
	 		Log.v(TAG, "QUERY " + query);
	    	Cursor cursor = songDatabase.query(query);
	    	BaseAdapter adapter = new BaseAdapter() {				
				@Override
				public View getView(int position, View convertView, ViewGroup parent) {
					// TODO Auto-generated method stub
					return null;
				}
				
				@Override
				public long getItemId(int position) {
					// TODO Auto-generated method stub
					return position;
				}
				
				@Override
				public Object getItem(int position) {
					// TODO Auto-generated method stub
					return null;
				}
				
				@Override
				public int getCount() {
					// TODO Auto-generated method stub
					return 0;
				}
			};
	    	setListAdapter(adapter);
	    }
	}
}
