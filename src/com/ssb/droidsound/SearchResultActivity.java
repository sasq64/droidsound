package com.ssb.droidsound;

import java.io.File;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;

import android.app.ListActivity;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;
import android.widget.AdapterView.OnItemSelectedListener;

public class SearchResultActivity extends ListActivity implements OnItemSelectedListener {
	
	private static final String TAG = "PlayList";
	private SQLiteDatabase db;

	@Override
    public void onCreate(Bundle savedInstanceState) {
    	super.onCreate(savedInstanceState);
    	
    	//String [] cols = new String { "name", "author", "game", "type"};
    	
    	Intent intent = getIntent();    	
    	String game = intent.getStringExtra("game");
    	String author = intent.getStringExtra("author");
    	String title = intent.getStringExtra("title");
    	
    	StringBuilder where = new StringBuilder("select * from songs where ");
    	//String [] args = new String [3];
    	//for(int i=0; i<3; i++)
//    		args[i] = "";
    	int i = 0;

    	if(title.length() > 0) {
    		if(i > 0)
    			where.append(" and ");
    		where.append("name like '").append(title).append("%'");
    		i++; //args[i++] = title + "%";
    	}

    	if(game.length() > 0) {
    		where.append("game like '").append(author).append("%'");
    		i++; //args[i++] = game + "%";
    	}

    	if(author.length() > 0) {
    		if(i > 0)
    			where.append(" and ");
    		where.append("author like '").append(author).append("%'");
    		//args[i++] = author + "%";
    		i++;
    	}
    	
    	where.append(" limit 50");

    	//where = new StringBuilder("select * from (select * from songs where name like 'winter%') where author like 'Ben%'");
    	//String [] args2 = new String [i];
    	//for(int j=0; j<i; j++)
    	//	args2[j] = args[j];
    	
    	
    	
    	Log.v(TAG, "Opening database");
    	
    	db = SQLiteDatabase.openDatabase("/sdcard/modland.db", null, SQLiteDatabase.OPEN_READONLY | SQLiteDatabase.NO_LOCALIZED_COLLATORS);

/*    	Cursor acursor = db.query("authors", null, "name=?", new String[] { "Ben Daglish" }, null, null, null);    	
    	acursor.moveToFirst();
    	int aid = acursor.getInt(0);
    	Log.v(TAG, "Got author " + aid);
    	Cursor cursor = db.query("songs", null, "author=?", new String[] { Integer.toString(aid) }, null, null, null);
*/
    	
    	Log.v(TAG, "Executing select: " + where.toString());
    	//Cursor cursor = db.query("songs", null, where.toString(), args2, null, null, null);
    	Cursor cursor = db.rawQuery(where.toString(), null);
    	//Cursor cursor = db.query("songs", null, "author like ? and name like ?", new String[] { "Oge%", "mega%", "" }, null, null, null);
    	//Cursor cursor = null;
    	
    	/*
    	if(title.length() > 0) {
    		cursor = db.rawQuery("SELECT songs._id, songs.name, games.gname FROM games JOIN songs ON (games._id=songs.game) WHERE songs.name LIKE ? LIMIT 50",
    			new String [] { title } );
    	} else if (game.length() > 0) {
    		cursor = db.rawQuery("SELECT songs._id, songs.name, games.gname FROM games JOIN songs ON (games._id=songs.game) WHERE games.gname LIKE ? LIMIT 50",
        			new String [] { game } );
    	}
    	*/
    	//Cursor gcursor = db.query("games", null, "name like ?", new String[] { game }, null, null, null);    	
    	//gcursor.moveToFirst();
    	//int gid = gcursor.getInt(0);
    	//Log.v(TAG, "Got game " + aid);
    	//Cursor cursor = db.query("songs", null, "author=?", new String[] { Integer.toString(aid) }, null, null, null);

    	startManagingCursor(cursor);
    	ListAdapter adapter = 
    	new SimpleCursorAdapter(this, 
                // Use a template that displays a text view
                android.R.layout.two_line_list_item, 
                // Give the cursor to the list adatper
                cursor, 
                // Map the NAME column in the people database to...
                new String[] {"game", "name"} ,
                // The "text1" view defined in the XML template
                new int[] {android.R.id.text1, android.R.id.text2}); 
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
		
		try {		
			String n = URLEncoder.encode(cursor.getString(1), "UTF-8");
			String a = URLEncoder.encode(cursor.getString(2), "UTF-8");
			String g = URLEncoder.encode(cursor.getString(3), "UTF-8");
			String t = URLEncoder.encode(cursor.getString(4), "UTF-8");
			if(g.compareTo("NONE") == 0) {
				path = String.format("%s/%s/%s", t, a, n);
			} else {
				path = String.format("%s/%s/%s%s", t, a, g, n);
			}
		} catch (UnsupportedEncodingException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
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
