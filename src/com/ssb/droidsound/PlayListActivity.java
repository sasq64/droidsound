package com.ssb.droidsound;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.DataSetObserver;
import android.os.Bundle;
import android.os.RemoteException;
import android.util.Log;
import android.util.SparseBooleanArray;
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
	
	//private File [] files;
	private MyAdapter myAdapter;
	private ListView playListView;
	private VirtualFS myFileSys;
	private static final String TAG = "PlayList";
	private FileListNode myPlaylist;
	private VirtualFS.Node mCurrentNode;
	
	public PlayListActivity() {
		Log.v(TAG, ">>>> CONSTRUCTOR CALLED\n");
	}

	
	class MyTextVew extends TextView implements Checkable {

		private boolean mChecked;

		public MyTextVew(Context context) {
			super(context);
			this.setTextColor(0xffffff00);
			// TODO Auto-generated constructor stub
		}

		@Override
		public boolean isChecked() {
			// TODO Auto-generated method stub
			return mChecked;
		}

		@Override
		public void setChecked(boolean checked) {
			// TODO Auto-generated method stub
			mChecked = checked;
			this.setTextColor(mChecked ? 0xffffff00 : 0xffffffff);
			Log.v(TAG, "SET CHECKED " + mChecked);
			//invalidate();
		}

		@Override
		public void toggle() {
			mChecked = !mChecked;
			this.setTextColor(mChecked ? 0xffffff00 : 0xffffffff);
			//invalidate();
			// TODO Auto-generated method stub
			Log.v(TAG, "Toggle");
			
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
			references.add(reference);
			resolved.add(myFileSys.resolvePath(reference));
		}

		@Override
		String getName() {
			// TODO Auto-generated method stub
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

		//private final static int TYPE_HOME = 10;
		//private final static int TYPE_REMOTE = 11;
		//private final static int TYPE_PLAYLIST = 12;
		//private final static int TYPE_MUSICFILE = 13;
		//private final static int TYPE_OTHERFILE = 14;
		
		//private int drawables[] = new int [] { R.drawable.folder, R.drawable.home, R.drawable.remote, 0, R.drawable.note, 0 }; 
		
		private Context mContext;
		private VirtualFS mFS;
		
		private class BookMarks extends VirtualFS.Node {
			
			VirtualFS.Node mParent;
			
			BookMarks(VirtualFS.Node parent) {
				mParent = parent;
			}

			@Override
			public VirtualFS.Node getChild(int pos) {
				return new VirtualFS.FileSystemNode(new File("strange/path"), "playlist01", this);
			}

			@Override
			public String getName() {
				// TODO Auto-generated method stub
				return "My BookMarks";
			}

			@Override
			public long getSize() {
				// TODO Auto-generated method stub
				return 0;
			}

			@Override
			public int getType() {
				// TODO Auto-generated method stub
				return TYPE_DIR;
			}

			@Override
			public InputStream read() throws IOException {
				// TODO Auto-generated method stub
				return null;
			}

			@Override
			public int getChildCount() {
				// TODO Auto-generated method stub
				return 1;
			}

			@Override
			public VirtualFS.Node getParent() {
				// TODO Auto-generated method stub
				return mParent;
			}
		};
		
		
		MyAdapter(Context context, VirtualFS fs) {
			mContext = context;
			mFS = fs;
			mFS.registerPath("My Music", "/sdcard/MODS");
			mFS.registerNode(new BookMarks(mFS.getRoot()));
			mCurrentNode = mFS.getRoot();
			//mFS.registerNode(node)
		}
		
		void setPath(String path) {
		
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
			return mCurrentNode.getChildCount();
		}

		@Override
		public Object getItem(int position) {
			// TODO Auto-generated method stub
			return mCurrentNode.getChild(position);
			//return entries[position];
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
			
			MyTextVew item;
			
			if(convertView == null) {
				//item = (TwoLineListItem) findViewById(android.R.layout.two_line_list_item);
				//LayoutInflater inflater = getLayoutInflater();
				//item = inflater.inflate(R.layout.search_list_item, null);
				
				item = new MyTextVew(mContext);
				item.setTextSize(18.0F);
				Log.v(TAG, "VIEW is " + item.getClass().getName());
			} else {
				item = (MyTextVew)convertView;
			}
			
			item.setTextColor(0xffffffff);

			VirtualFS.Node n = mCurrentNode.getChild(position);
			
			item.setText(n.getName());

			if(n.getClass() == FileListNode.class) {
				item.setCompoundDrawablesWithIntrinsicBounds(R.drawable.play_list, 0, 0, 0);			
			} else if(n.getType() == VirtualFS.TYPE_DIR) {
				item.setCompoundDrawablesWithIntrinsicBounds(R.drawable.directory, 0, 0, 0);
			} else {
				item.setCompoundDrawablesWithIntrinsicBounds(R.drawable.note, 0, 0, 0);
			}
		
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
  	
    	
        setContentView(R.layout.playlist);        
        playListView = (ListView)findViewById(R.id.playListView);
        
        playListView.setFastScrollEnabled(true);
        
        registerForContextMenu(playListView);
        
    	//playListView.setChoiceMode(ListView.CHOICE_MODE_MULTIPLE);
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
		//myPlaylist.AddFile("/My Music/quick/intr(o)uder alert.mod");

        
    	myAdapter = new MyAdapter(this, myFileSys);
    	
    	if(savedInstanceState != null) {
	    	String path = savedInstanceState.getString("path");
	    	
			Log.v(TAG, ">> Restroing path " + path);
	    	
	    	if(path != null)
	    		mCurrentNode = myFileSys.resolvePath(path);
    	}

    	//view.setAdapter(new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, names));    	
    	//setListAdapter(new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, names));
    	//setListAdapter(myAdapter);
    	playListView.setAdapter(myAdapter);
    	playListView.setOnItemSelectedListener(this);
    	playListView.setOnItemClickListener(this);
    	//playListView.setOnLongClickListener(this);
    	Log.v(TAG, "Choicemode " + playListView.getChoiceMode());
    }
	
	@Override
//	protected void  onItemClick  (ListView l, View v, int position, long id)
	public void onItemClick(AdapterView<?> av, View v, int position, long id) {
		
		ListView l = (ListView) av;
		VirtualFS.Node file = (VirtualFS.Node) l.getItemAtPosition(position);
		String path = file.pathName();
		Log.v(TAG, "Clicked item " + path + "  at " + position);
		
		VirtualFS.Node rnode = myFileSys.resolvePath(path);

		if(rnode != null) {
			Log.v(TAG, "Resolves to " + rnode.getName());
		}
		
		//((MyTextVew)v).toggle();
		//v.invalidate();
		
		if(file.getType() == VirtualFS.TYPE_DIR) {
			myAdapter.enterDir(position);
			l.invalidateViews();
		} else {
			//File modFile = files[position];
			
			Intent i = new Intent();
			i.putExtra("musicName", file.getName());
			try {
				i.putExtra("musicFile", file.getFile());
			} catch (IOException e) {
				Log.e(TAG, "Could not read file");
			}
			//i.putExtra("musicData", data);
			setResult(RESULT_OK, i);
			finish();
		}
	}

	@Override
	public void onItemSelected(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
		
		Log.v(TAG, "Selected item: " + arg2);
		
		//File modFile = files[arg2];
		//Intent i = new Intent();
		//i.putExtra("fileName", modFile.getName());
		//setResult(RESULT_OK, i);
		//finish();
	}

	@Override
	public void onNothingSelected(AdapterView<?> arg0) {
		// TODO Auto-generated method stub
		Log.v(TAG, "WHAT");
	}
	
	@Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
		
		/*
		SparseBooleanArray array = playListView.getCheckedItemPositions();
		if(array != null) {
			for(int i=0; i<array.size(); i++) {
				Log.v(TAG, "SET " + array.get(i));
			}
		}

		
        switch(event.getKeyCode())
        {
        	case KeyEvent.KEYCODE_BACK:
        		if(myAdapter.enterDir(-1) == false)
        			finish();
        		else 
        			playListView.invalidateViews();

        		return true;
        }*/
        return super.onKeyDown(keyCode, event);
    }
	
	
	@Override
	public void onCreateContextMenu(ContextMenu cmenu, View view, ContextMenu.ContextMenuInfo cinfo)
	{
		//Log.v(TAG, "Class " + cinfo.getClass().getName());
		AdapterView.AdapterContextMenuInfo aci = (AdapterView.AdapterContextMenuInfo) cinfo;
		
		VirtualFS.Node file = (VirtualFS.Node) ((ListView)view).getItemAtPosition(aci.position);
		VirtualFS.Node parent = file.getParent();		
		String path = file.pathName();
		int t = file.getType();
		
		
		Log.v(TAG, String.format("File %s, Class %s Parent class %s", path, file.getClass().getName(), parent.getClass().getName()));
		
		if(path != null) {
			cmenu.add(0, 3, 0, "Information");
			
			if(t == VirtualFS.TYPE_REMOTE) {
				cmenu.add(0, 4, 0, "Download");
			}

			if(parent != null && mCurrentNode.getClass() == FileListNode.class) {
				cmenu.add(0, 5, 0, "Remove From Playlist");
			} if(myPlaylist != null && t == VirtualFS.TYPE_FILE) {
				cmenu.add(0, 3, 0, R.string.add_to_playlist); 
			}
		}
	}
	
	@Override
	public boolean onContextItemSelected(MenuItem item) {
		int i = item.getItemId();
		AdapterView.AdapterContextMenuInfo aci = (AdapterView.AdapterContextMenuInfo) item.getMenuInfo();

		VirtualFS.Node file = (VirtualFS.Node) playListView.getItemAtPosition(aci.position);
		//VirtualFS.Node parent = file.getParent();		
		String path = file.pathName();
		//int t = file.getType();
		
		Log.v(TAG, String.format("Selected %d on %s", i, path));

		switch(i) {
		case 3:
			myPlaylist.AddFile(path);
			break;
		case 5:
			myPlaylist.RemoveFile(aci.position);
			playListView.invalidateViews();
			break;
		}
		return true;
	}

	public boolean onCreateOptionsMenu(Menu menu) {
		menu.add(0, 10, 0, "Player").setIcon(android.R.drawable.ic_media_pause);
		menu.add(0, 11, 0, "Quit").setIcon(android.R.drawable.ic_menu_close_clear_cancel);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		if(item.getItemId() == 11) {
			finish();
		} else if(item.getItemId() == 10) {
			finish();
		}
		return true;
	}

	@Override
	public boolean onLongClick(View v) {
		// TODO Auto-generated method stub
		return false;
	}


}
