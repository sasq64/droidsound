package com.ssb.droidsound;

import java.io.File;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;

import android.app.ListActivity;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.DataSetObserver;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;
import android.widget.TextView;
import android.widget.TwoLineListItem;
import android.widget.AdapterView.OnItemSelectedListener;

public class SearchResultActivity extends ListActivity implements OnItemSelectedListener {
	
	private static final String TAG = "PlayList";
	private SQLiteDatabase db;
	
	
	class MyAdapter implements ListAdapter {
		private Context mContext;
		private Cursor mCursor;

		private int COL_NAME;
		private int COL_GAME;
		private int COL_AUTHOR;
		private int COL_TYPE;
		private int mCount;
		private int COL_ID;
		
		MyAdapter(Context context, Cursor cursor) {
			mContext = context;
			mCursor = cursor;
			
			COL_NAME = cursor.getColumnIndex("name");
			COL_GAME = cursor.getColumnIndex("game");
			COL_AUTHOR = cursor.getColumnIndex("author");
			COL_TYPE = cursor.getColumnIndex("type");
			COL_ID = cursor.getColumnIndex("_id");
			
			mCount = cursor.getCount();
			
		}
		
		@Override
		public boolean areAllItemsEnabled() {
			// TODO Auto-generated method stub
			return true;
		}

		@Override
		public boolean isEnabled(int position) {
			// TODO Auto-generated method stub
			return true;
		}

		@Override
		public int getCount() {
			// TODO Auto-generated method stub
			return mCount;
		}

		@Override
		public Object getItem(int position) {
			// TODO Auto-generated method stub
			mCursor.moveToPosition(position);
			String a = mCursor.getString(COL_AUTHOR);
			String g = mCursor.getString(COL_GAME);
			
			return new String [] { mCursor.getString(COL_TYPE), mCursor.getString(COL_AUTHOR), mCursor.getString(COL_GAME), mCursor.getString(COL_NAME) };
		}

		@Override
		public long getItemId(int position) {
			// TODO Auto-generated method stub
			mCursor.moveToPosition(position);
			return mCursor.getLong(COL_ID);
		}

		@Override
		public int getItemViewType(int position) {
			// TODO Auto-generated method stub
			return 0;
		}

		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			
			View item;
			
			if(convertView == null) {
				//item = (TwoLineListItem) findViewById(android.R.layout.two_line_list_item);
				LayoutInflater inflater = getLayoutInflater();
				item = inflater.inflate(R.layout.search_list_item, null);
				Log.v(TAG, "VIEW is " + item.getClass().getName());
			} else {
				item = convertView;
			}
			TextView h = (TextView) item.findViewById(R.id.search_header);
			TextView t = (TextView) item.findViewById(R.id.search_text);
			
			mCursor.moveToPosition(position);
			String a = mCursor.getString(COL_AUTHOR);
			String g = mCursor.getString(COL_GAME);
			if((a.length() == 0 || a.contains("nknown")) && g.compareTo("NONE") != 0) {
				a = g;
			}
			
			h.setText(a);
			t.setText(mCursor.getString(COL_NAME));
			
			// TODO Auto-generated method stub
			return item;
		}

		@Override
		public int getViewTypeCount() {
			// TODO Auto-generated method stub
			return 1;
		}

		@Override
		public boolean hasStableIds() {
			// TODO Auto-generated method stub
			return true;
		}

		@Override
		public boolean isEmpty() {
			// TODO Auto-generated method stub
			return false;
		}

		@Override
		public void registerDataSetObserver(DataSetObserver observer) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void unregisterDataSetObserver(DataSetObserver observer) {
			// TODO Auto-generated method stub		
		}
	};

	@Override
    public void onCreate(Bundle savedInstanceState) {
    	super.onCreate(savedInstanceState);
    	
    	setContentView(R.layout.search_result);
    	
    	Intent intent = getIntent();    	
    	String game = intent.getStringExtra("game");
    	String author = intent.getStringExtra("author");
    	String title = intent.getStringExtra("title");

    	StringBuilder where = new StringBuilder("select * from songs where ");
    	int i = 0;
    	if(title.length() > 0) {
    		if(title.contains("*")) {
    			where.append("name GLOB '").append(title).append("'");
    		} else {
    			where.append("name='").append(title).append("'");
    		}
    		i++;
    	}

    	if(game.length() > 0) {
    		if(i > 0)
    			where.append(" and ");
    		if(game.contains("*")) {
    			where.append("game GLOB '").append(game).append("'");
    		} else {
    			where.append("game='").append(game).append("'");
    		}
    		i++;
    	}

    	if(author.length() > 0) {
    		if(i > 0)
    			where.append(" and ");
    		if(author.contains("*")) {
    			where.append("author GLOB '").append(author).append("'");
    		} else {
    			where.append("author='").append(author).append("'");
    		}
    		i++;
    	}
    	
    	where.append(" LIMIT 100");
    	
    	Log.v(TAG, "Opening database");    	
    	db = SQLiteDatabase.openDatabase("/sdcard/modland.db", null, SQLiteDatabase.OPEN_READONLY | SQLiteDatabase.NO_LOCALIZED_COLLATORS);

    	Log.v(TAG, "Executing select: " + where.toString());
    	Cursor cursor = db.rawQuery(where.toString(), null);
    	Log.v(TAG, "Cursor ready");

    	startManagingCursor(cursor);
    	ListAdapter adapter = new MyAdapter(this, cursor);
/*    		
    	new SimpleCursorAdapter(this, 
                // Use a template that displays a text view
                android.R.layout.two_line_list_item, 
                // Give the cursor to the list adatper
                cursor, 
                // Map the NAME column in the people database to...
                new String[] {"game", "name"} ,
                // The "text1" view defined in the XML template
                new int[] {android.R.id.text1, android.R.id.text2});*/ 
        setListAdapter(adapter);
        
    	Log.v(TAG, "Adapter set");        
    }
	
	@Override
	protected void  onListItemClick  (ListView l, View v, int position, long id)
	{
		Log.v(TAG, "Clicked item " + id);

		Cursor cursor = db.query("songs", null, "_id=?", new String[] { Long.toString(id) }, null, null, null);
		//Cursor cursor = db.rawQuery("SELECT types.tname, authors.aname, games.gname, songs.name FROM songs JOIN types, authors, games ON(games._id=songs.game and authors._id=songs.author and types._id=songs.type) WHERE songs._id=?",
		//		new String [] { Long.toString(id) });
		cursor.moveToFirst();
		
		//Cursor cursor = db.rawQuery("SELECT types.tname, authors.aname, games.gname, songs.name FROM songs JOIN types, authors, games ON(games._id=songs.game and authors._id=songs.author and types._id=songs.type) WHERE songs._id=?",
		//		new String [] { Long.toString(id) });
		//cursor.moveToFirst();
		String path = "ILLEGAL";
		
		String n = cursor.getString(1);
		String a = cursor.getString(2);
		String g = cursor.getString(3);
		String t = cursor.getString(4);
		if(g.compareTo("NONE") == 0) {
			path = String.format("%s/%s/%s", t, a, n);
		} else {
			path = String.format("%s/%s/%s/%s", t, a, g, n);
		}
		
		Log.v(TAG, path + " selected");

		Intent i = new Intent();
		i.putExtra("name", path);
		setResult(RESULT_OK, i);
		finish();

		
		//File modFile = files[position];
		//Intent i = new Intent();
		//i.putExtra("fileName", modFile.getAbsolutePath());
		//setResult(RESULT_OK, i);
		finish();
	}

	@Override
	public void onItemSelected(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
		
		Log.v(TAG, "Selected item: " + arg2);
		
		//File modFile = files[arg2];
		//Intent i = new Intent();
		//i.putExtra("fileName", modFile.getName());
		//setResult(RESULT_OK, i);
		finish();
	}

	@Override
	public void onNothingSelected(AdapterView<?> arg0) {
		// TODO Auto-generated method stub
		Log.v(TAG, "WHAT");
	}

	@Override
	protected void onDestroy() {
		super.onDestroy();
		db.close();
	}
	
}
