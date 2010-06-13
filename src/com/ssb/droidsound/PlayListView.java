package com.ssb.droidsound;

import java.io.File;

import android.content.Context;
import android.graphics.Typeface;
import android.util.AttributeSet;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.AdapterView.OnItemClickListener;

public class PlayListView extends ListView {

    class PlayListAdapter extends BaseAdapter {
    	
    	private Context mContext;
		private Typeface mTypeface;
		private File [] files;

		PlayListAdapter(Context context, Typeface tf) {
    		mContext = context;
    		mTypeface = tf;
    	}
    	
		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			TextView tv = (TextView)convertView;
			if(convertView == null) {
				convertView = tv = new TextView(mContext);
				tv.setTextSize(21);
				tv.setTypeface(mTypeface);
				tv.setPadding(10, 10, 10, 10);
				tv.setTextColor(0xff000000);
			}
			if(position == 0) {
				tv.setText("[..]");
				tv.setTextColor(0xffffffff);
			} else {
				if(files[position-1].isDirectory()) {
					tv.setText("[" + files[position-1].getName() + "]");
					tv.setTextColor(0xffffffff);
				} else {
					tv.setText(files[position-1].getName());
					tv.setTextColor(0xff000000);
				}
			}
			
			return convertView;
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
			return files != null ? files.length+1 : 0;
		}
	}
    
	private PlayListAdapter adapter;
	private File [] files;
	private File parentDir;
	private File topDir;
	private PlayerServiceConnection mPlayer;

    public PlayListView(Context context, AttributeSet attrs) {
		super(context, attrs);
		Typeface tf = Typeface.createFromAsset(context.getAssets(), "fonts/topaz_plus1200.ttf");
		adapter = new PlayListAdapter(context, tf);
		setAdapter(adapter);
		
        setOnItemClickListener(new OnItemClickListener() {
			@Override
			public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
				if(files != null) {
					if(position == 0) {
						if(parentDir != null) {
							if(!parentDir.equals(topDir)) { 
								parentDir = parentDir.getParentFile();
								adapter.files = files = parentDir.listFiles();
								adapter.notifyDataSetChanged();
							}
						}
					} else {
						if(files[position-1].isDirectory()) {
							//adapter.changeDir(files[position]);
							parentDir = files[position-1];
							adapter.files = files = parentDir.listFiles();
							
							adapter.notifyDataSetChanged();
						} else if (mPlayer != null) {
							String [] names = new String [files.length];
							for(int i=0; i<names.length; i++) {
								names[i] = files[i].getPath();
							}
							mPlayer.playList(names, position-1);
						}
					}
				}
			}
		});
	}
        
    public void setFiles(File [] files) {
    	this.files = files;
    	adapter.files = files;
    }
    
    public void setDirectory(File parent) {
    	parentDir = topDir = parent;
    	files = parent.listFiles();
    	adapter.files = files;
    }
    
    public void setPlayer(PlayerServiceConnection player) {
    	mPlayer = player;
    }

	public void rescan() {
		adapter.notifyDataSetChanged();		
	}
		

}
