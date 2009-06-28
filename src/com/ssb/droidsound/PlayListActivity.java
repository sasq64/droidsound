package com.ssb.droidsound;

import java.io.File;

import android.app.ListActivity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.AdapterView.OnItemSelectedListener;

public class PlayListActivity extends ListActivity implements OnItemSelectedListener {
	
    private File [] files;
	private static final String TAG = "PlayList";

	@Override
    public void onCreate(Bundle savedInstanceState) {
    	super.onCreate(savedInstanceState);
        //setContentView(R.layout.playlist);        
        //ListView view = (ListView)findViewById(R.id.PlayListView);
    	//this.setContentView(R.id.PlayListView);
    	
    	//ListView view = new ListView(this);
    	//setContentView(view);
    	
    	//view.setOnItemSelectedListener(this);

    	//ListView lv = getListView();    	
        //LinearLayout v = new LinearLayout(this);
        //setContentView(v);
    	
    	File modDir = new File(Environment.getExternalStorageDirectory()+"/MODS");    	
    	files = modDir.listFiles();
    	
    	String [] names = new String [files.length];
    	int i = 0;
    	for(File f : files) {
    		names[i++] = f.getName(); 
    	}

    	//view.setAdapter(new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, names));    	
    	setListAdapter(new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, names));
    }
	
	@Override
	protected void  onListItemClick  (ListView l, View v, int position, long id)
	{
		Log.v(TAG, "Clicked item " + position);
		
		File modFile = files[position];
		Intent i = new Intent();
		i.putExtra("fileName", modFile.getAbsolutePath());
		setResult(RESULT_OK, i);
		finish();
	}

	@Override
	public void onItemSelected(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
		
		Log.v(TAG, "Selected item: " + arg2);
		
		File modFile = files[arg2];
		Intent i = new Intent();
		i.putExtra("fileName", modFile.getName());
		setResult(RESULT_OK, i);
		finish();
	}

	@Override
	public void onNothingSelected(AdapterView<?> arg0) {
		// TODO Auto-generated method stub
		Log.v(TAG, "WHAT");
	}

}
