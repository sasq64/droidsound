package com.ssb.droidsound;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Currency;
import java.util.List;

import com.ssb.droidsound.VirtualFS.Node;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.database.DataSetObserver;
import android.os.Bundle;
import android.util.Log;
import android.view.ContextMenu;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.view.View.OnLongClickListener;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.Checkable;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.AdapterView.OnItemSelectedListener;

public class PlayListActivity extends Activity implements OnItemSelectedListener, OnItemClickListener, OnLongClickListener {
	
	private static final String TAG = "PlayList";

	private MyAdapter myAdapter;
	private ListView playListView;
	private VirtualFS myFileSys;
	private FileListNode myPlaylist;
	private VirtualFS.Node mCurrentNode;

	class MyTextVew extends TextView implements Checkable {

		private boolean mChecked;

		public MyTextVew(Context context) {
			super(context);
			this.setTextColor(0xffffff00);
		}

		@Override
		public boolean isChecked() {
			return mChecked;
		}

		@Override
		public void setChecked(boolean checked) {
			mChecked = checked;
			setTextColor(mChecked ? 0xffffff00 : 0xffffffff);
		}

		@Override
		public void toggle() {
			mChecked = !mChecked;
			setTextColor(mChecked ? 0xffffff00 : 0xffffffff);			
		}
	};
	
	class FileListNode extends VirtualFS.Node {
		
		private List<String> references;
		private List<VirtualFS.Node> resolved;

		private VirtualFS.Node mParent;
		private String mName;
		
		FileListNode(String name, VirtualFS.Node parent) {
			mParent = parent;
			mName = name;
			references = new ArrayList<String>();
			resolved = new ArrayList<VirtualFS.Node>();
		}
		
		List<String> getReferences() {
			return references;
		}
		
		void setReferences(List<String> ref) {
			references = ref;
		}
		
		void AddFile(String reference) {
			Node node = myFileSys.resolvePath(reference);
			references.add(reference);
			resolved.add(node);
		}

		@Override
		String getName() {
			return mName;
		}
		
		@Override
		VirtualFS.Node getChild(int pos) {
			if(resolved.get(pos) == null) {
				resolved.set(pos, myFileSys.resolvePath(references.get(pos)));
			}
			return resolved.get(pos);
		}
		
		@Override
		int getChildCount() {
			return references.size();
		}
		
		@Override
		VirtualFS.Node getParent() {
			return mParent;
		}

		public void RemoveFile(int position) {
			references.remove(position);
			resolved.remove(position);
		}
		
	};

	class MyAdapter extends BaseAdapter {
		
		static final int TYPE_FILE = 1;
		static final int TYPE_DIR = 2;
		static final int TYPE_REMOTE = 3;
		static final int TYPE_REFERENCE = 4;
		
		private Context mContext;
		
		MyAdapter(Context context, VirtualFS fs) {
			mContext = context;
			myFileSys.registerPath("My Music", "/sdcard/MODS");
			mCurrentNode = myFileSys.getRoot();
		}
		
		@Override
		public boolean areAllItemsEnabled() {
			return true;
		}

		@Override
		public boolean isEnabled(int position) {
			return true;
		}

		@Override
		public int getCount() {
			return mCurrentNode.getChildCount();
		}

		@Override
		public Object getItem(int position) {
			return mCurrentNode.getChild(position);
		}

		@Override
		public long getItemId(int position) {
			return position;
		}

		@Override
		public int getItemViewType(int position) {
			return 0;
		}

		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			
			TextView item;
			
			if(convertView == null) {
				item = new TextView(mContext);
				item.setTextSize(18.0F);
			} else {
				item = (TextView)convertView;
			}

			item.setTextColor(0xffffffff);
			VirtualFS.Node n = mCurrentNode.getChild(position);
			if(n == null) {
				item.setText("<NULL>");
			} else {
				item.setText(n.getName());
	
				if(n.getClass() == FileListNode.class) {
					item.setCompoundDrawablesWithIntrinsicBounds(R.drawable.play_list, 0, 0, 0);			
				} else if(n.getType() == VirtualFS.TYPE_DIR) {
					item.setCompoundDrawablesWithIntrinsicBounds(R.drawable.directory, 0, 0, 0);
				} else {
					item.setCompoundDrawablesWithIntrinsicBounds(R.drawable.note, 0, 0, 0);
				}
			}
			return item;
		}

		@Override
		public int getViewTypeCount() {
			return 1;
		}

		@Override
		public boolean hasStableIds() {
			return true;
		}

		@Override
		public boolean isEmpty() {
			return false;
		}

		@Override
		public void registerDataSetObserver(DataSetObserver observer) {
		}

		@Override
		public void unregisterDataSetObserver(DataSetObserver observer) {
		}

		public boolean enterDir(int position) {			
			if(position == -1) {
				mCurrentNode = mCurrentNode.getParent();
				if(mCurrentNode == null)
					return false;
				return true;
			}
			
			VirtualFS.Node node = mCurrentNode.getChild(position);
			if(node.getType() == VirtualFS.TYPE_DIR) {
				mCurrentNode = node;
				return true;
			}
			
			return false;
		}
	};

	@Override
	protected void onDestroy() {
		
		List<String> list = myPlaylist.getReferences();
		
		Log.v(TAG, ">> Saving PLAYLIST");
		
		File file = new File("/sdcard/playlist.plist");
		try {
			file.createNewFile();
			PrintStream ps = new PrintStream(file);
			for(String s : list) {
				ps.println(s);
			}
			ps.close();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		super.onDestroy();
	}
	
	@Override
	protected void onSaveInstanceState(Bundle outState) {
		super.onSaveInstanceState(outState);
		String path = mCurrentNode.pathName();
		Log.v(TAG, ">> Saving path " + path);
		outState.putString("path", path);
	}
	
	@Override
	protected void onPause() {
		super.onPause();
		Log.v(TAG, ">> OnPause");
	}

	@Override
    public void onCreate(Bundle savedInstanceState) {
    	super.onCreate(savedInstanceState);
    	
		Log.v(TAG, ">> OnCreate");
    	
    	Log.v(TAG, (mCurrentNode == null) ? "NONE" : mCurrentNode.pathName());
  	
    	//File modDir = new File(Environment.getExternalStorageDirectory()+"/MODS");
        setContentView(R.layout.playlist);        
        playListView = (ListView)findViewById(R.id.playListView);
        
        playListView.setFastScrollEnabled(true);
        
        registerForContextMenu(playListView);
        
    	//playListView.setChoiceMode(ListView.CHOICE_MODE_MULTIPLE);
    	//this.setContentView(R.id.PlayListView);
        
        String path = null;
        
    	if(savedInstanceState != null) {
	    	path = savedInstanceState.getString("path");	    	
    	}

        int pos = -1;
        Intent intent = getIntent();        
        Bundle b = intent.getExtras();
        if(b != null) {
        	String p = b.getString("directory");
        	pos = b.getInt("position");
        	if(p != null) {
        		path = p;
        	}
        }
    	
    	
        myFileSys = new VirtualFS();
		myPlaylist = new FileListNode("My Playlist", myFileSys.getRoot());

		File file = new File("/sdcard/playlist.plist");
		try {
			String s;
			FileReader fr = new FileReader(file);
			BufferedReader br = new BufferedReader(fr);
			
			while((s = br.readLine()) != null) {
				myPlaylist.AddFile(s);
			}
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		myFileSys.registerNode(myPlaylist);

		myAdapter = new MyAdapter(this, myFileSys);
    	
			Log.v(TAG, ">> Restroing path " + path);
	    	
	    	if(path != null) {
	    		mCurrentNode = myFileSys.resolvePath(path);
	    	}	

    	playListView.setAdapter(myAdapter);
    	playListView.setOnItemSelectedListener(this);
    	playListView.setOnItemClickListener(this);
    	
    	if(pos >= 0) {
    		playListView.setSelection(pos);
    	}
    }
	
	@Override
	public void onItemClick(AdapterView<?> av, View v, int position, long id) {
		
		ListView l = (ListView) av;
		VirtualFS.Node file = (VirtualFS.Node) l.getItemAtPosition(position);
		String path = file.pathName();
		Log.v(TAG, "Clicked item " + path + "  at " + position);
		
		VirtualFS.Node rnode = myFileSys.resolvePath(path);

		if(rnode != null) {
			Log.v(TAG, "Resolves to " + rnode.getName());
		}
		
		if(file.getType() == VirtualFS.TYPE_DIR) {
			myAdapter.enterDir(position);
			l.invalidateViews();
		} else {
			
			Intent intent = new Intent();
			
			String dirPath = mCurrentNode.pathName();
			intent.putExtra("directory", dirPath);
			intent.putExtra("position", position);

			try {
				String [] list = new String [ mCurrentNode.getChildCount() ];				
				for(int i=0; i< list.length; i++) {
					list[i] = mCurrentNode.getChild(i).getFile().getPath();
					if(i<10) {
						Log.v(TAG, String.format("%d : %s", i, list[i]));
					}
				}
				intent.putExtra("musicList", list);
				intent.putExtra("musicPos", position);
			} catch (IOException e) {
			}
			
			//intent.putExtra("musicName", file.getName());
			try {
				intent.putExtra("musicFile", file.getFile().getPath());
			} catch (IOException e) {
				Log.e(TAG, "Could not read file");
			}
			//i.putExtra("musicData", data);
			setResult(RESULT_OK, intent);
			finish();
		}
	}

	@Override
	public void onItemSelected(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
	}

	@Override
	public void onNothingSelected(AdapterView<?> arg0) {
		// TODO Auto-generated method stub
	}
	
	@Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {

        switch(event.getKeyCode())
        {
        	case KeyEvent.KEYCODE_BACK:
        		if(myAdapter.enterDir(-1) == false)
        			finish();
        		else 
        			playListView.invalidateViews();

        		return true;
        }
        return super.onKeyDown(keyCode, event);
    }
	
	
	@Override
	public void onCreateContextMenu(ContextMenu cmenu, View view, ContextMenu.ContextMenuInfo cinfo)
	{
		//Log.v(TAG, "Class " + cinfo.getClass().getName());
		AdapterView.AdapterContextMenuInfo aci = (AdapterView.AdapterContextMenuInfo) cinfo;
		
		VirtualFS.Node file = (VirtualFS.Node) ((ListView)view).getItemAtPosition(aci.position);
		if(file == null)
			return;
		VirtualFS.Node parent = file.getParent();		
		String path = file.pathName();
		int t = file.getType();
		
		
		Log.v(TAG, String.format("File %s, Class %s Parent class %s", path, file.getClass().getName(), parent.getClass().getName()));
		
		if(path != null) {

			if(t != VirtualFS.TYPE_DIR) {
				cmenu.add(0, 2, 0, "Play");
			}

			cmenu.add(0, 3, 0, "Information");
			
			if(t == VirtualFS.TYPE_REMOTE) {
				cmenu.add(0, 4, 0, "Download");
			}

			if(mCurrentNode.getClass() == FileListNode.class) {
				cmenu.add(0, 5, 0, "Remove From Playlist");
			} else if(myPlaylist != null) {
				cmenu.add(0, 3, 0, R.string.add_to_playlist);
			}
		}
	}
	
	@Override
	public boolean onContextItemSelected(MenuItem item) {
		int id = item.getItemId();
		AdapterView.AdapterContextMenuInfo aci = (AdapterView.AdapterContextMenuInfo) item.getMenuInfo();

		VirtualFS.Node file = (VirtualFS.Node) playListView.getItemAtPosition(aci.position);
		String path = file.pathName();
		
		Log.v(TAG, String.format("Selected %d on %s", id, path));

		switch(id) {
		case 2:

			try {
				Intent intent = new Intent(this, PlayerService.class);
				String [] list = new String [ mCurrentNode.getChildCount() ];				
				for(int i=0; i< list.length; i++) {
					list[i] = mCurrentNode.getChild(i).getFile().getPath();
					if(i<10) {
						Log.v(TAG, String.format("%d : %s", i, list[i]));
					}
				}
				intent.putExtra("musicList", list);
				intent.putExtra("musicPos", aci.position);
				
				intent.setAction(Intent.ACTION_VIEW);
				startService(intent);

			} catch (IOException e) {
			}
			break;
		case 3:
			if(file.getType() == VirtualFS.TYPE_DIR) {
				for(int i = 0 ; i<file.getChildCount(); i++) {
					VirtualFS.Node node = file.getChild(i);
					if(node.getType() == VirtualFS.TYPE_FILE) {
						myPlaylist.AddFile(node.pathName());
					}
				}
			} else {
				myPlaylist.AddFile(path);
			}
			break;
		case 5:
			myPlaylist.RemoveFile(aci.position);
			playListView.invalidateViews();
			break;
		}
		return true;
	}

	public boolean onCreateOptionsMenu(Menu menu) {
		menu.add(0, 10, 0, "Player").setIcon(R.drawable.ic_menu_playback);
		
		Log.v(TAG, mCurrentNode.getClass().getName());
		
		if(mCurrentNode.getClass() == FileListNode.class) {
			menu.add(0, 12, 0, "Clear all").setIcon(android.R.drawable.ic_menu_delete);
		}
		
		menu.add(0, 11, 0, "Quit").setIcon(android.R.drawable.ic_menu_close_clear_cancel);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		if(item.getItemId() == 11) {
			finish();
		} else if(item.getItemId() == 10) {
			finish();
		} else if(item.getItemId() == 12) {
			
			FileListNode node = (FileListNode) mCurrentNode;
			int count = node.getChildCount();
			for(int i=count-1; i >= 0; i--) {
				node.RemoveFile(i);
			}			
			mCurrentNode = new FileListNode(mCurrentNode.getName(), mCurrentNode.getParent());
			playListView.invalidateViews();
		}
		return true;
	}

	@Override
	public boolean onLongClick(View v) {
		return false;
	}


}
