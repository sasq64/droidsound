package com.ssb.droidsound;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.app.SearchManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.content.DialogInterface.OnMultiChoiceClickListener;
import android.content.SharedPreferences.Editor;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.ContextMenu;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.SlidingDrawer;
import android.widget.TextView;
import android.widget.ViewFlipper;
import android.widget.AdapterView.AdapterContextMenuInfo;

import com.ssb.droidsound.service.PlayerService;

public class PlayerActivity extends Activity implements PlayerServiceConnection.Callback {
	private static final String TAG = "DroidSound";
	
	public static final String DROIDSOUND_VERSION = "Beta 3";

	private PlayerServiceConnection player;
	private ImageButton playButton;
	private ImageButton backButton;
	private ImageButton fwdButton;
	private ImageButton stopButton;
	
	private ImageButton goinfoButton;
	
	//private Button parentButton;
	
	private TextView songTitleText;
	private TextView songComposerText;
	private PlayListView playListView;

	private int songPos;
	private int subTune;
	private int subTuneCount;
	private int songLength;
	private String songName;
	private boolean mIsPlaying = false;

	
	//private static ScanTask scanTask = null;
	private static SongDatabase songDatabase = null;
	private static Thread dbThread = null;

	private View infoDisplay;
	private View controls;
	private TextView titleText;

	private String modsDir;
	private String currentPath;


	private BroadcastReceiver receiver;

	private SQLiteDatabase db;

	private SlidingDrawer drawer;

	private int backDown;
	private int downCount;
	private boolean atTop;
	
	private ProgressDialog progressDialog;

	private boolean bcRegistered;

	private ViewFlipper flipper;

	private TextView songCopyrightText;

	private ImageButton golistButton;

	private TextView songSecondsText;

	private TextView songTotalText;

	private TextView songSubtunesText;
	

	
	protected void finalize() throws Throwable {
		Log.v(TAG, "########## Activity finalize");
	};

	@Override
	protected void onNewIntent(Intent intent) {
		setIntent(intent);
		Log.v(TAG, "INTENT " + intent.getAction());
		if(Intent.ACTION_SEARCH.equals(intent.getAction())) {
			String query = intent.getStringExtra(SearchManager.QUERY);
	 		Log.v(TAG, "QUERY " + query);
	 		CSDBParser.setPath(playListView.getDirectory());
	 		playListView.search(query);
		}
	}
	
	@Override
	public void onCreate(Bundle savedInstanceState) {

		//final UncaughtExceptionHandler oldHandler = Thread.getDefaultUncaughtExceptionHandler();		
		//Thread.setDefaultUncaughtExceptionHandler(		
		//modsDir.getParent()
		
		super.onCreate(savedInstanceState);

		Intent intent = getIntent();
		Log.v(TAG, String.format("Intent %s / %s", intent.getAction(), intent.getDataString()));
		if(Intent.ACTION_VIEW.equals(intent.getAction())) {			
			String music = intent.getDataString();
			Intent newIntent = new Intent(intent);
			newIntent.setClass(this, PlayerService.class);
			startService(newIntent);
			finish();
			return;
		}
		
		player = new PlayerServiceConnection();		
		
		setContentView(R.layout.player);
		playButton = (ImageButton) findViewById(R.id.play_button);
		backButton = (ImageButton) findViewById(R.id.back_button);
		fwdButton = (ImageButton) findViewById(R.id.fwd_button);
		stopButton = (ImageButton) findViewById(R.id.stop_button);
		songTitleText = (TextView) findViewById(R.id.title_text);
		songComposerText = (TextView) findViewById(R.id.composer_text);
		songCopyrightText = (TextView) findViewById(R.id.copyright_text);
		songSecondsText = (TextView) findViewById(R.id.seconds_text);
		songTotalText = (TextView) findViewById(R.id.total_text);
		songSubtunesText = (TextView) findViewById(R.id.songs_text);

		playListView = (PlayListView) findViewById(R.id.play_list);
		infoDisplay = findViewById(R.id.info_display);
		controls = findViewById(R.id.controls);
		//parentButton = (Button) findViewById(R.id.parent_button);
		titleText = (TextView) findViewById(R.id.list_title);
		goinfoButton = (ImageButton) findViewById(R.id.go_info_button);
		golistButton = (ImageButton) findViewById(R.id.go_list_button);
		flipper = (ViewFlipper) findViewById(R.id.flipper);
		
		SharedPreferences prefs = getSharedPreferences("songdb", Context.MODE_PRIVATE);
		modsDir = prefs.getString("modsDir", null);

		//modsDir = "/sdcard/MODS";
		if(modsDir == null) {
			File extFile = Environment.getExternalStorageDirectory();		
			if(extFile != null) {
				File mf = new File(extFile, "MODS");
				if(!mf.exists()) {
					mf.mkdir();
				}
								
				
				if(!mf.exists()) {
					showDialog(R.string.create_moddir_failed);
				} else {
					
					modsDir = mf.getPath();
					Editor editor = prefs.edit();
					editor.putString("modsDir", modsDir);
					editor.commit();					
					//showDialog(12);
				}
				
			} else {
				showDialog(R.string.sdcard_not_found);
			}
		}
		
		File modsFile = new File(modsDir);
		if(!modsFile.exists()) {
			showDialog(R.string.sdcard_not_found);
		}
		
		receiver = new BroadcastReceiver() {
			@Override
			public void onReceive(Context context, Intent intent) {
				// TODO Auto-generated method stub
								
				if(intent.getAction().equals("com.sddb.droidsound.OPEN_DONE")) {
					Log.v(TAG, "Open done!");
					playListView.rescan();
					songDatabase.scan(false, modsDir);
				} else
				if(intent.getAction().equals("com.sddb.droidsound.SCAN_DONE")) {
					
					if(progressDialog != null) {
						progressDialog.cancel();
						progressDialog = null;
					}
					
					Log.v(TAG, "Scan done!");
					playListView.rescan();
				} else
				if(intent.getAction().equals("com.sddb.droidsound.SCAN_UPDATE")) {
					Log.v(TAG, "Scan update!");
					if(progressDialog == null) {
						progressDialog = new ProgressDialog(PlayerActivity.this);
						progressDialog.setProgressStyle(ProgressDialog.STYLE_SPINNER);
						progressDialog.setMessage("Updating database...");
						progressDialog.setCancelable(false);
						progressDialog.show();
					}
					int percent = intent.getIntExtra("PERCENT", 0);
					String path = intent.getStringExtra("PATH");
					if(percent > 0) {
						progressDialog.setMessage(String.format("Updating database...\n%s %02d%%", path, percent));
					} else {
						progressDialog.setMessage(String.format("Updating database...\n%s", path));
					}
				
				}
			} 
		};
		
		IntentFilter filter = new IntentFilter();
		filter.addAction("com.sddb.droidsound.OPEN_DONE");
		filter.addAction("com.sddb.droidsound.SCAN_DONE");
		filter.addAction("com.sddb.droidsound.SCAN_UPDATE");
		registerReceiver(receiver, filter);
		bcRegistered = true;

		Log.v(TAG, String.format("MODS at %s", modsDir));

		if(songDatabase == null) {
			songDatabase = new SongDatabase(getApplicationContext());		
			dbThread = new Thread(songDatabase);
			dbThread.start();
		}
		
		if(songDatabase.isScanning() && progressDialog == null) {
				progressDialog = new ProgressDialog(PlayerActivity.this);
				progressDialog.setProgressStyle(ProgressDialog.STYLE_SPINNER);
				progressDialog.setMessage("Updating database...");
				progressDialog.setCancelable(false);
				progressDialog.show();
		}

		songDatabase.registerPath("CSDB", new SongDatabase.PathCallback() {			
			@Override
			public Cursor getCursorFromPath(String path, SQLiteDatabase db) {
				return CSDBParser.getPath(path, db);
			}
		});
		
		File mf = new File(modsDir, "Favorites.plist");
		if(!mf.exists()) {
			try {
				Log.v(TAG, "Trying to write Favorites");
				FileWriter fw = new FileWriter(mf);
				fw.close();
				Log.v(TAG, "Done");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		if(mf.exists()) {
			songDatabase.setActivePlaylist(mf);
		}
		
		
		playListView.setDatabase(songDatabase);
		
		//if(getLastNonConfigurationInstance() != null) {
		//	Log.v(TAG, "CONFIG CHANGE");
		//} else {
			//Log.v(TAG, "SCANNING");
			//songDatabase.scan(false, modsDir);
		//}
		
		registerForContextMenu(playListView);
		
		goinfoButton.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				flipper.setDisplayedChild(1);
			}
		});
		golistButton.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				flipper.setDisplayedChild(0);
			}
		});
		
		/*
		parentButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				playListView.gotoParent();
			}
		});
		
		parentButton.setOnLongClickListener(new OnLongClickListener() {
			@Override
			public boolean onLongClick(View v) {
				playListView.setDirectory(modsDir);
				return true;
			}
		});
		*/	
		playListView.setOnDirChangeCallback(new PlayListView.DirChangeCallback() {			


			@Override
			public void dirChange(String dir, String title) {
				File f = new File(dir);
				currentPath = dir;
				
				//inPlayList = dir.toUpperCase().endsWith(".PLIST");
				
				if(f.getPath().equals(modsDir)) {
					//parentButton.setText("");
					atTop = true;
					//parentButton.setVisibility(View.INVISIBLE);
				} else {
					//parentButton.setText(f.getParentFile().getName());
					atTop = false;
					//parentButton.setVisibility(View.VISIBLE);
				}
				if(title != null) {
					titleText.setText(title);
				} else {
					titleText.setText(f.getName());
				}
			}
		});
		
		playButton.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {				
				player.playPause(!mIsPlaying);
			}
		});
		
		stopButton.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {				
				player.stop();
			}
		});

		backButton.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				if(subTune == 0) {
					player.playPrev();
				} else {
					subTune -= 1;
					player.setSubSong(subTune);
				}
			}
		});
		
		backButton.setOnLongClickListener(new OnLongClickListener() {			
			@Override
			public boolean onLongClick(View v) {
				player.playPrev();
				return true;
			}
		});

		fwdButton.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				if((subTune+1) < subTuneCount) {
					subTune += 1;
					player.setSubSong(subTune);
				} else {
					player.playNext();
				}
			}
		});
		
		fwdButton.setOnLongClickListener(new OnLongClickListener() {			
			@Override
			public boolean onLongClick(View v) {
				player.playNext();
				return true;
			}
		});
		
		
		//SharedPreferences prefs = getSharedPreferences("songdb", Context.MODE_PRIVATE);
		currentPath = prefs.getString("currentPath", null);
		if(currentPath == null) {
			currentPath = modsDir;
		}
		
		//inPlayList = currentPath.toUpperCase().endsWith(".PLIST");
		atTop = currentPath.equals(modsDir);
	
		playListView.setDirectory(currentPath);
		playListView.setPlayer(player);
	}
	/*
	@Override
	public boolean onKeyLongPress(int keyCode, KeyEvent event) {
		Log.v(TAG, String.format("LONG PRESS %d", keyCode));
		if(keyCode == KeyEvent.KEYCODE_BACK) {
			backDown = 2;
			playListView.setDirectory(modsDir);
			return true;
		}
		return super.onKeyLongPress(keyCode, event);
	} */
	
	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		Log.v(TAG, String.format("DOWN %d", keyCode));
		if(keyCode == KeyEvent.KEYCODE_BACK) {
			downCount++;
			if(downCount == 3) {
				playListView.setDirectory(modsDir);
			}
			return true;
		//	backDown = 1;
		}
		return super.onKeyDown(keyCode, event);
	}
	
	@Override
	public boolean onKeyUp(int keyCode, KeyEvent event) {
		Log.v(TAG, String.format("UP %d", keyCode));
		if(keyCode == KeyEvent.KEYCODE_BACK) {
			if(downCount < 3) {
				//if(backDown == 1) {
					if(atTop) {
						finish();
					} else {
						playListView.gotoParent();
					}
				//}
			}
			//backDown = 0;
			downCount = 0;
			return true;
		}
		return super.onKeyDown(keyCode, event);
	}

	
	@Override
	protected void onResume() {
		super.onResume();
		player.bindService(this, this);
		
		if(!bcRegistered) {
			IntentFilter filter = new IntentFilter();
			filter.addAction("com.sddb.droidsound.OPEN_DONE");
			filter.addAction("com.sddb.droidsound.SCAN_DONE");
			filter.addAction("com.sddb.droidsound.SCAN_UPDATE");
			registerReceiver(receiver, filter);
			bcRegistered = true;
		}
		
		if(!songDatabase.isScanning() && progressDialog != null) {
			progressDialog.cancel();
			progressDialog = null;
			playListView.rescan();
		}
	}
	
	@Override
	protected void onPause() {
		super.onPause();
		
		Playlist.flushAll();
		
		player.unbindService(this);
		
		unregisterReceiver(receiver);
		bcRegistered = false;
		if(db != null) {
			db.close();
			db = null;
		}
	}
	
	@Override
	protected void onDestroy() {
		super.onDestroy();

		if(playListView != null) {
			playListView.close();
			SharedPreferences prefs = getSharedPreferences("songdb", Context.MODE_PRIVATE);
			Editor editor = prefs.edit();
			editor.putString("currentPath", playListView.getDirectory());
			editor.commit();
		}
		
		if(songDatabase != null) {
			songDatabase.unregisterAll();
		}
		
		if(progressDialog != null) {
			progressDialog.dismiss();			
		}
		
		Log.v(TAG, "DESTROYED");
		
		player = null;
		
	}
	
	//@Override
	//public Object onRetainNonConfigurationInstance() {
	//	return "CONFIG";
	//}

	@Override
	public void intChanged(int what, int value) {
		switch(what) {
		case PlayerService.SONG_LENGTH :
			songLength = value/1000;
			songTotalText.setText(String.format("%02d:%02d", songLength/60, songLength%60));
			break;
		case PlayerService.SONG_POS :
			songPos = value/1000;
			songSecondsText.setText(String.format("%02d:%02d", songPos/60, songPos%60));
			break;
		case PlayerService.SONG_SUBSONG :
			subTune = value;
			songSubtunesText.setText(String.format("[%02d/%02d]", subTune+1, subTuneCount));
			break;
		case PlayerService.SONG_TOTALSONGS :
			subTuneCount = value;
			songSubtunesText.setText(String.format("[%02d/%02d]", subTune+1, subTuneCount));
			break;
		case PlayerService.SONG_STATE:
			Log.v(TAG, String.format("State now %d", value));
			if(value == 1) {
				mIsPlaying = true;
				playButton.setBackgroundResource(R.drawable.pause_button);				
			} else {
				playButton.setBackgroundResource(R.drawable.play_button);				
				mIsPlaying = false;
				if(value == 0) {
					songTitleText.setText("");
					songComposerText.setText("");
					songCopyrightText.setText("");
					songSubtunesText.setText("[00/00]");
					songTotalText.setText("00:00");
					songSecondsText.setText("00:00");
				}
			}
			break;
		}
	}

	@Override
	public void stringChanged(int what, String value) {
		switch(what) {
		case PlayerService.SONG_FILENAME :
			playListView.setSelection(value);
			songName = value;
			break;
		case PlayerService.SONG_TITLE :
			songTitleText.setText(value);
			break;
		case PlayerService.SONG_AUTHOR :
			songComposerText.setText(value);
			break;
		case PlayerService.SONG_COPYRIGHT :
			songCopyrightText.setText(value);
			break;
		case PlayerService.SONG_GAMENAME :
			if(value != null && value.length() > 0) {
				songCopyrightText.setText(value);
			}
			break;
		}
	}
		
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		
		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.optionsmenu, menu);
		return true;
	}

	public boolean onPrepareOptionsMenu(Menu menu) {

		if(songDatabase.isScanning()) {
			menu.setGroupVisible(R.id.when_not_scanning, false);
			menu.setGroupVisible(R.id.when_scanning, true);
		} else {
			menu.setGroupVisible(R.id.when_not_scanning, true);
			menu.setGroupVisible(R.id.when_scanning, false);
		}
		return true;
	}


	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		int choice = item.getItemId();
		switch(choice) {
		case R.id.rescan:
			//scan(true);
			showDialog(R.string.scan_db);
			break;
		case R.id.about :
			showDialog(R.string.about_droidsound);
			break;
		case R.id.quit:
			player.stop();
			finish();
			break;
		case R.id.abort_scan:
			ScanTask.cancel();
			break;
		case R.id.new_:
			showDialog(R.string.new_);
			break;
		case R.id.search:
			onSearchRequested();
			break;		
		}		
		return true;
	}
	
	private boolean doFullScan;
	//private boolean inPlayList;

//	private Playlist currentPlaylist;
	
	@Override
	protected Dialog onCreateDialog(int id) {
		
		AlertDialog.Builder builder = new AlertDialog.Builder(this);
		
		switch(id) {		
		case R.string.recreate_confirm:
			builder.setMessage(id);
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					songDatabase.rescan(modsDir);
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}				
			});
			break;
		case R.string.new_:
			builder.setTitle(id);
			builder.setSingleChoiceItems(R.array.new_opts, -1, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					Log.v(TAG, "Clicked " + which);
					dialog.dismiss();
					switch(which) {
					case 0:
						showDialog(R.string.name_folder);
						break;
					case 1:
						showDialog(R.string.name_playlist);
						break;
					}
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}				
			});
			break;
		case R.string.name_playlist:			
			final EditText input = new EditText(this);  
			builder.setView(input);  			  
			builder.setMessage(id);
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					String s = input.getText().toString();					
					songDatabase.createPlaylist(new File(currentPath, s + ".plist"));
					playListView.rescan();
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}				
			});			
			break;
		case R.string.name_folder:			
			final EditText input2 = new EditText(this);  
			builder.setView(input2);  			  
			builder.setMessage(id);
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					String s = input2.getText().toString();					
					songDatabase.createFolder(new File(currentPath, s));
					playListView.rescan();
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}				
			});			
			break;
		case R.string.scan_db:
			doFullScan = false;
			builder.setTitle(id);
			builder.setMultiChoiceItems(R.array.scan_opts, null, new OnMultiChoiceClickListener() {				
				@Override
				public void onClick(DialogInterface dialog, int which, boolean isChecked) {
					Log.v(TAG, String.format("%d %s", which, String.valueOf(isChecked)));
					doFullScan = isChecked;
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}				
			});
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dialog, int id) {
					dialog.cancel();
					if(doFullScan) {
						showDialog(R.string.recreate_confirm);
					} else {
						songDatabase.scan(true, modsDir);
					}
				}
			});
			break;
		default:
			builder.setMessage(id);
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dialog, int id) {
					dialog.cancel();
				}
			});
			break;
		}

		AlertDialog alert = builder.create();
		return alert;
	}
	
	@Override
	public void onCreateContextMenu(ContextMenu menu, View v, ContextMenuInfo menuInfo) {
		super.onCreateContextMenu(menu, v, menuInfo);		
		AdapterView.AdapterContextMenuInfo info = (AdapterView.AdapterContextMenuInfo) menuInfo;
		Log.v(TAG, String.format("POS %d", info.position));
		Cursor cursor = playListView.getCursor(info.position);
		int type = SongDatabase.TYPE_FILE;
		int t = cursor.getColumnIndex("TYPE");
		if(t >= 0) {
			type = cursor.getInt(t);
		}
		
		File file = playListView.getFile(info.position);
		
		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.songmenu, menu);

		MenuItem aitem = menu.findItem(R.id.add_to_plist);
		Playlist pl = songDatabase.getActivePlaylist();
		if(pl != null) {
			aitem.setTitle(String.format("Add to '%s'", pl.getTitle()));
		}

		if(songDatabase.getCurrentPlaylist() != null) {
			menu.setGroupVisible(R.id.in_playlist, true);
		} else {
			menu.setGroupVisible(R.id.in_playlist, false);
		}
		
		switch(type) {
		case SongDatabase.TYPE_FILE:
			menu.setGroupVisible(R.id.on_file, true);
			menu.setGroupVisible(R.id.on_dir, false);
			menu.setGroupVisible(R.id.on_plist, false);
			break;

		case SongDatabase.TYPE_DIR:
		case SongDatabase.TYPE_ARCHIVE:
			menu.setGroupVisible(R.id.on_file, false);
			menu.setGroupVisible(R.id.on_dir, true);
			menu.setGroupVisible(R.id.on_plist, false);
			break;

		case SongDatabase.TYPE_PLIST:
			menu.setGroupVisible(R.id.on_file, false);
			menu.setGroupVisible(R.id.on_dir, false);
			menu.setGroupVisible(R.id.on_plist, true);
			break;			
		}
	}	
	
	@Override
	public boolean onContextItemSelected(MenuItem item) {
		//SQLiteDatabase db;
		AdapterContextMenuInfo info = (AdapterContextMenuInfo) item.getMenuInfo();
		//PlayListView.FileInfo finfo = (PlayListView.FileInfo) playListView.getItemAtPosition(info.position);
		//Cursor cursor = playListView.getCursor(info.position);
		File file = playListView.getFile(info.position);
		Log.v(TAG, String.format("%d %s %d %d", item.getItemId(), item.getTitle(), info.position, info.id));
		//int pi = cursor.getColumnIndex("PATH");
		//String path = playListView.getDirectory();
		//if(pi >= 0) {
		//	path =  cursor.getString(pi);
		//}
		Playlist pl = songDatabase.getCurrentPlaylist();
		Playlist al = songDatabase.getActivePlaylist();

		switch(item.getItemId()) {
		case R.id.go_author:
			playListView.setDirectory(file.getParent());
			break;
		case R.id.set_plist:			
			songDatabase.setActivePlaylist(file);
			break;
		case R.id.add_to_plist:			
			if(al != null) {
				if(!currentPath.equals(al.getFile().getPath())) {
					//al.add(file);
					songDatabase.addToPlaylist(al, file);
				}
			}
			break;
		//case R.id.favorite:			
		//	songDatabase.addFavorite(file);
		//	break;
		case R.id.remove :
			if(pl != null) {
				pl.remove(file);
				playListView.rescan();
			}
			
			break;
		case R.id.remove_all :
			if(pl != null) {
				pl.clear();
				playListView.rescan();
			}
			
			break;
		default:
			return super.onContextItemSelected(item);
		}
		return true;
	}	
}

