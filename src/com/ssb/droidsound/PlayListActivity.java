package com.ssb.droidsound;

import java.io.File;

import android.app.ListActivity;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.DataSetObserver;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.AdapterView.OnItemSelectedListener;

public class PlayListActivity extends ListActivity implements OnItemSelectedListener {
	

	class MyAdapter implements ListAdapter {
		private Context mContext;

		private int mCount;
		private int COL_ID;
		private String mDir;
		
		private File [] files;
		
		MyAdapter(Context context, String dir) {
			mContext = context;
			mDir = dir;
			
			files = new File(mDir).listFiles();
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
			return files.length;
		}

		@Override
		public Object getItem(int position) {
			// TODO Auto-generated method stub
			return files[position];
		}

		@Override
		public long getItemId(int position) {
			// TODO Auto-generated method stub
			return position;
		}

		@Override
		public int getItemViewType(int position) {
			// TODO Auto-generated method stub
			return 0;
		}

		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			
			TextView item;
			
			if(convertView == null) {
				//item = (TwoLineListItem) findViewById(android.R.layout.two_line_list_item);
				//LayoutInflater inflater = getLayoutInflater();
				//item = inflater.inflate(R.layout.search_list_item, null);
				
				item = new TextView(mContext);				
				Log.v(TAG, "VIEW is " + item.getClass().getName());
			} else {
				item = (TextView)convertView;
			}
			
			item.setText(files[position].getName());
			
			if(files[position].isDirectory())
				item.setCompoundDrawablesWithIntrinsicBounds(R.drawable.folder, 0, 0, 0);
			else
				item.setCompoundDrawablesWithIntrinsicBounds(R.drawable.sound, 0, 0, 0);
		
			//item.setCompoundDrawables(R.drawable.sound, null, null, null);
			
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

		public boolean enterDir(int position) {
			
			if(position == -1) {
				mDir = new File(mDir).getParent();
				if(mDir == null)
					return false;
				files = new File(mDir).listFiles();
			} else {
				mDir = files[position].getPath();
				files = new File(mDir).listFiles();
			}
			return true;
		}
	};

	private File [] files;
	private MyAdapter myAdapter;
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
    	/*
    	File modDir = new File(Environment.getExternalStorageDirectory()+"/MODS");    	
    	files = modDir.listFiles();
    	
    	String [] names = new String [files.length];
    	int i = 0;
    	for(File f : files) {
    		names[i++] = f.getName(); 
    	} */
    	
    	myAdapter = new MyAdapter(this, Environment.getExternalStorageDirectory()+"/MODS");

    	//view.setAdapter(new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, names));    	
    	//setListAdapter(new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, names));
    	setListAdapter(myAdapter);
    }
	
	@Override
	protected void  onListItemClick  (ListView l, View v, int position, long id)
	{
		
		File file = (File) l.getItemAtPosition(position);
		Log.v(TAG, "Clicked item " + position);

		if(file.isDirectory()) {
			myAdapter.enterDir(position);
			l.invalidateViews();
		} else {
			//File modFile = files[position];
			Intent i = new Intent();
			i.putExtra("fileName", file.getAbsolutePath());
			setResult(RESULT_OK, i);
			finish();
		}
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
	
	@Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
		
        switch(event.getKeyCode())
        {
        	case KeyEvent.KEYCODE_BACK:
        		if(myAdapter.enterDir(-1) == false)
        			finish();
        		else 
        			getListView().invalidateViews();

        		return true;
        }
        return super.onKeyDown(keyCode, event);
    }



}
