package com.ssb.droidsound;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Application;
import android.app.Dialog;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.SearchManager;
import android.content.BroadcastReceiver;
import android.content.ContentValues;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.content.DialogInterface.OnMultiChoiceClickListener;
import android.content.SharedPreferences.Editor;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.widget.AbsListView;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.ImageButton;
import android.widget.SlidingDrawer;
import android.widget.TextView;
import android.widget.AbsListView.OnScrollListener;
import android.widget.AdapterView.AdapterContextMenuInfo;

import com.ssb.droidsound.service.PlayerService;

public class PlayerActivity extends Activity implements PlayerServiceConnection.Callback {
	private static final String TAG = "DroidSound";

	private PlayerServiceConnection player;
	private ImageButton playButton;
	private ImageButton backButton;
	private ImageButton fwdButton;
	private ImageButton stopButton;
	
	private ImageButton searchButton;
	
	private Button parentButton;
	
	private TextView songTitleText;
	private TextView songComposerText;
	private TextView songDigitsText;
	private PlayListView playListView;
	private SlidingDrawer drawer;

	private int songPos;
	private int subTune;
	private int subTuneCount;
	private int songLength;
	private String songName;
	private boolean mIsPlaying = false;
	private boolean controlsHidden = false;

	private SongDatabase songDatabase;

	private View infoDisplay;
	private View controls;
	private TextView titleText;

	private String modsDir;

	private BroadcastReceiver receiver;

	private SQLiteDatabase db;

	//private static AsyncTask<Void, String, Void> scanTask = null;
	private static ScanTask scanTask = null;
	
	private static class ScanTask extends AsyncTask<Void, String, Void> {
		
		private boolean notified = false;
		private String lastPath = null;
		private SongDatabase songDatabase;
		private boolean fullScan;
		private String modsDir;
		private NotificationManager manager;
		private Notification notification;
		private PendingIntent contentIntent;
		private Application application;
		private boolean drop;
		
		protected void finalize() throws Throwable {
			Log.v(TAG, "########## ScanTask finalize");
		};
		
		ScanTask(boolean fullScan, String modsDir, Application app, boolean drop) {
			this.fullScan = fullScan;
			this.modsDir = modsDir;
			this.drop = drop;
			application = app;
			
			manager = (NotificationManager) app.getSystemService(Context.NOTIFICATION_SERVICE);	
			notification = new Notification(R.drawable.note, "Scanning", System.currentTimeMillis());				
			Intent notificationIntent = new Intent();
			contentIntent = PendingIntent.getActivity(app, 0, notificationIntent, 0);
		
			if(drop) {
				notification.setLatestEventInfo(application, "Scanning", "Clearing database", contentIntent);
				manager.notify(1, notification);
				notified = true;
			}
			
			
		}

		@Override
		protected Void doInBackground(Void... arg) {
					
			synchronized (this) {
				songDatabase = new SongDatabase(application, drop);
				songDatabase.setScanCallback(new SongDatabase.ScanCallback() {					
					@Override
					public void notifyScan(String path, int percent) {					
						Log.v(TAG, String.format("NOTIFY %s %d", path, percent));
						publishProgress(path, Integer.toString(percent));
					}
				});
			}

			songDatabase.scan(fullScan, modsDir);

			synchronized (this) {
				songDatabase.setScanCallback(null);
				songDatabase.closeDB();
				songDatabase = null;
			}
				
			return null;
		}
		
		synchronized void cancel() {
			if(songDatabase != null) {
				songDatabase.stopScan();
			}
		}

		
		@Override
		protected void onProgressUpdate(String... values) {
			
			String path = values[0];
			int percent = Integer.parseInt(values[1]);

			if(path == null) {
				path = lastPath;
			} else {
				lastPath = path;
			}
			if(percent > 0) {
				path = String.format("%s [%02d%%]", path, percent);
			}
			notification.setLatestEventInfo(application, "Scanning", path, contentIntent);
			manager.notify(1, notification);
			notified = true;
		}

		@Override
		protected void onPostExecute(Void result) {
			if(notified) {
				manager.cancel(1);
				notified = false;
			}
			synchronized (scanTask) {
				scanTask = null;
			}
			Intent intent = new Intent("com.sddb.droidsound.SCAN_DONE");
			application.sendBroadcast(intent);

		}
	}

	
	protected void finalize() throws Throwable {
		Log.v(TAG, "########## Activity finalize");
	};
	
	private void scan(boolean full) {
		
		if(scanTask != null) {
			Log.v(TAG, "Already scanning! exiting scan...");
			return;
		}
		scanTask = new ScanTask(full, modsDir, getApplication(), false);		
		scanTask.execute((Void)null);
	}
	
	private void rescan() {
		
		if(scanTask != null) {
			Log.v(TAG, "Already scanning! exiting scan...");
			return;
		}
		scanTask = new ScanTask(true, modsDir, getApplication(), true);		
		scanTask.execute((Void)null);
	}

	@Override
	protected void onNewIntent(Intent intent) {
		setIntent(intent);
		Log.v(TAG, "INTENT " + intent.getAction());
		if(Intent.ACTION_SEARCH.equals(intent.getAction())) {
			String query = intent.getStringExtra(SearchManager.QUERY);
	 		Log.v(TAG, "QUERY " + query);
	 		playListView.search(query);
		}
	}
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		player = new PlayerServiceConnection();
		
		setContentView(R.layout.player);
		playButton = (ImageButton) findViewById(R.id.play_button);
		backButton = (ImageButton) findViewById(R.id.back_button);
		fwdButton = (ImageButton) findViewById(R.id.fwd_button);
		stopButton = (ImageButton) findViewById(R.id.stop_button);
		songTitleText = (TextView) findViewById(R.id.title_text);
		songComposerText = (TextView) findViewById(R.id.composer_text);
		songDigitsText = (TextView) findViewById(R.id.seconds_text);
		playListView = (PlayListView) findViewById(R.id.play_list);
		drawer = (SlidingDrawer) findViewById(R.id.drawer);
		infoDisplay = findViewById(R.id.info_display);
		controls = findViewById(R.id.controls);
		parentButton = (Button) findViewById(R.id.parent_button);
		titleText = (TextView) findViewById(R.id.list_title);
		searchButton = (ImageButton) findViewById(R.id.search_button);
				
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
					showDialog(11);
				} else {
					
					modsDir = mf.getPath();
					Editor editor = prefs.edit();
					editor.putString("modsDir", modsDir);
					editor.commit();
					
					showDialog(12);
					
				}
				
			} else {
				showDialog(10);
			}
		}
		
		File mf = new File(modsDir, "Favorites.lnk");
		if(!mf.exists()) {
			try {
				Log.v(TAG, "Trying to write Favorites");
				FileWriter fw = new FileWriter(mf);
				fw.write("LINK:0\n");
				fw.close();
				Log.v(TAG, "Done");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		
		
		receiver = new BroadcastReceiver() {
			@Override
			public void onReceive(Context context, Intent intent) {
				// TODO Auto-generated method stub
				Log.v(TAG, "Scan done!");
				playListView.rescan();
			} 
		};

		
		Log.v(TAG, String.format("MODS at %s", modsDir));
		//return rdb.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "FILENAME", "FLAGS" }, "PATH=?", new String[] { pathName }, null, null, "FLAGS, FILENAME");	

		/*
		String[] projection = new String[] {
                SongProvider._ID,
                SongProvider.TITLE,
                SongProvider.COMPOSER,
                SongProvider.FILENAME,
                SongProvider.FLAGS,
             };
		
		ContentResolver cr = getContentResolver();
		String pathName = "/sdcard/MODS";		
		Cursor c = cr.query(SongProvider.SONG_URI, projection, "PATH=?", new String[] { pathName }, "FLAGS, FILENAME");
		*/
		//int top = drawer.getTop();
		//Log.v(TAG, String.format("TOP %d", top));
		
		songDatabase = new SongDatabase(this, false);
		
		db = songDatabase.getWritableDatabase();
		
		
		songDatabase.registerPath("LINK", new SongDatabase.PathCallback() {
			@Override
			public Cursor getCursorFromPath(String path, SQLiteDatabase db) {
				Log.v(TAG, "Getting LINK path " + path);
				String cp = String.format("%s%%", path);
				//return db.query("FILES", new String[] { "_id", "TITLE", "COMPOSER", "PATH", "FILENAME", "FLAGS" }, "COPYRIGHT LIKE ?", new String[] { cp }, null, null, "COMPOSER, TITLE");
				return db.query("LINKS", new String[] { "_id", "LIST", "TITLE", "COMPOSER", "PATH", "FILENAME", }, "LIST=?", new String[] { path }, null, null, null);
			}			
		});
		
		playListView.setDatabase(songDatabase);		
		registerForContextMenu(playListView);
		
		searchButton.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				onSearchRequested();
			}
		});
		
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
		
		playListView.setOnScrollListener(new OnScrollListener() {
			@Override
			public void onScrollStateChanged(AbsListView view, int scrollState) {
				// TODO Auto-generated method stub
				/*Log("Scroll state %d", scrollState);
				if(scrollState == SCROLL_STATE_FLING) {
					if(!controlsHidden) {
						controlsHidden = true;
						controls.setVisibility(View.GONE);
						infoDisplay.setVisibility(View.GONE);
					}
				}*/
			}
			
			@Override
			public void onScroll(AbsListView view, int firstVisibleItem, int visibleItemCount, int totalItemCount) {
				//Log("Scroll %d/%d/%d", firstVisibleItem, visibleItemCount, totalItemCount);
			}
		});
		
		playListView.setOnDirChangeCallback(new PlayListView.DirChangeCallback() {			
			@Override
			public void dirChange(String dir) {
				File f = new File(dir);
				if(f.getPath().equals(modsDir)) {
					//parentButton.setText("");
					parentButton.setVisibility(View.INVISIBLE);
				} else {
					//parentButton.setText(f.getParentFile().getName());
					parentButton.setVisibility(View.VISIBLE);
				}
				titleText.setText(f.getName());
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
				/*
				View view = listFrame.getChildAt(0);
				ViewGroup.LayoutParams oldParams = view.getLayoutParams();
				Log.v(TAG, String.format("%s", oldParams.getClass().getSimpleName()));
				//int rules [] = oldParams.getRules();
				LayoutParams params = new LayoutParams(oldParams.width, oldParams.height);
				params.addRule(RelativeLayout.ALIGN_PARENT_TOP);
				view.setLayoutParams(params);
				listFrame.requestLayout(); */
				
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
		
		
		songDigitsText.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				
			}
		});

		//SharedPreferences prefs = getSharedPreferences("songdb", Context.MODE_PRIVATE);
		String currentPath = prefs.getString("currentPath", null);
		if(currentPath == null) {
			currentPath = modsDir;
		}

		Intent intent = getIntent();
		Log.v(TAG, String.format("Intent %s / %s", intent.getAction(), intent.getDataString()));
		if(Intent.ACTION_SEARCH.equals(intent.getAction())) {
			String query = intent.getStringExtra(SearchManager.QUERY);
	 		Log.v(TAG, "QUERY " + query);
			//cursor = songDatabase.search(query);
			//SongListAdapter adapter = new SongListAdapter(this, cursor);
		}
				
		//File modDir = new File(modDirName);
		//if(!modDir.exists()) {
		//	modDir.mkdir();
		//}
/*
		if(modDir.listFiles().length < 1) {
			HttpDownloader.downloadFiles(new HttpDownloader.Callback() {			
				@Override
				public void onDisplayProgress(int progress) {}

				@Override
				public void onDone() {
					playListView.rescan();
				}
			}, "/sdcard/MODS/",  "http://swimmer.se/droidsound/mods.zip");	
		}
*/
		
		//songDatabase = new SongDatabase(this);		
		scan(false);
		//songDatabase.registerPath(name, cb)
		
		playListView.setDirectory(currentPath);
		playListView.setPlayer(player);
	}
	
	
	@Override
	protected void onResume() {
		super.onResume();
		player.bindService(this, this);
		registerReceiver(receiver, new IntentFilter("com.sddb.droidsound.SCAN_DONE")); 
	}
	
	@Override
	protected void onPause() {
		super.onPause();
		player.unbindService(this);
		unregisterReceiver(receiver);
		if(db != null) {
			db.close();
			db = null;
		}
	}
	
	@Override
	protected void onDestroy() {
		super.onDestroy();
		
		playListView.close();
		songDatabase.closeDB();
		
		Log.v(TAG, "DESTROYED");
		
		player = null;
		
		SharedPreferences prefs = getSharedPreferences("songdb", Context.MODE_PRIVATE);
		Editor editor = prefs.edit();
		editor.putString("currentPath", playListView.getDirectory());
		editor.commit();
	}

	@Override
	public void intChanged(int what, int value) {
		switch(what) {
		case PlayerService.SONG_LENGTH :
			songLength = value/1000;
			songDigitsText.setText(String.format("%02d:%02d / %02d:%02d [%02d/%02d]", songPos/60, songPos%60, songLength/60, songLength%60, subTune+1, subTuneCount));
			break;
		case PlayerService.SONG_POS :
			songPos = value/1000;
			songDigitsText.setText(String.format("%02d:%02d / %02d:%02d [%02d/%02d]", songPos/60, songPos%60, songLength/60, songLength%60, subTune+1, subTuneCount));
			break;
		case PlayerService.SONG_SUBSONG :
			subTune = value;
			songDigitsText.setText(String.format("%02d:%02d / %02d:%02d [%02d/%02d]", songPos/60, songPos%60, songLength/60, songLength%60, subTune+1, subTuneCount));
			break;
		case PlayerService.SONG_TOTALSONGS :
			subTuneCount = value;
			songDigitsText.setText(String.format("%02d:%02d / %02d:%02d [%02d/%02d]", songPos/60, songPos%60, songLength/60, songLength%60, subTune+1, subTuneCount));
			break;
		case PlayerService.SONG_STATE:
			Log.v(TAG, String.format("State now %d", value));
			if(value == 1) {
				mIsPlaying = true;
				playButton.setImageResource(R.drawable.mg_pause);
				if(controlsHidden) {
					controlsHidden = false;
					controls.setVisibility(View.VISIBLE);
					infoDisplay.setVisibility(View.VISIBLE);
					playListView.redraw();
					//playListView.setSelection(playingFile);

				}
				
			} else {
				playButton.setImageResource(R.drawable.mg_forward);
				mIsPlaying = false;
				if(value == 0) {
					songTitleText.setText("");
					songComposerText.setText("");
					songDigitsText.setText("00:00 [00/00]");
				}
			}
			break;
		}
	}
	/*
	@Override
	public void onBackPressed() {
		if(controlsHidden) {
			if(controlsHidden) {
				controlsHidden = false;
				controls.setVisibility(View.VISIBLE);
				infoDisplay.setVisibility(View.VISIBLE);
				//playListView.redraw();
			}
		} else {
			super.onBackPressed();
		}
	}*/

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
		}
	}
		
	@Override
	public boolean onPrepareOptionsMenu(Menu menu) {
	//public boolean onCreateOptionsMenu(Menu menu) {
		menu.clear();
		if(scanTask == null) {
			menu.add(0, 10, 0, "Rescan").setIcon(R.drawable.ic_menu_music_library);
		} else {
			menu.add(0, 13, 0, "Abort scan").setIcon(R.drawable.ic_menu_music_library);
		}
		//menu.add(0, 14, 0, "Backup DB").setIcon(R.drawable.ic_menu_music_library);
		//menu.add(0, 15, 0, "Restore DB").setIcon(R.drawable.ic_menu_music_library);
		menu.add(0, 11, 0, "About").setIcon(android.R.drawable.ic_menu_info_details);
		menu.add(0, 12, 0, "Quit").setIcon(android.R.drawable.ic_menu_close_clear_cancel);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		int choice = item.getItemId();
		switch(choice) {
		case 10:
			//scan(true);
			showDialog(20);
			break;
		case 11 :
			showDialog(0);
			break;
		case 12:
			player.stop();
			finish();
			break;
		case 14:
			break;
		case 15:
			break;
		case 13:
			if(scanTask != null) {
				synchronized (scanTask) {
					if(scanTask != null) {
						scanTask.cancel();
					}				
				}
			}
		}		
		return true;
	}
	
	private boolean doFullScan;
	
	@Override
	protected Dialog onCreateDialog(int id) {
		
		String msg = "SWAY HAT?";
		AlertDialog.Builder builder = new AlertDialog.Builder(this);
		
		builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
			public void onClick(DialogInterface dialog, int id) {
				dialog.cancel();
			}
		});
		
		switch(id) {
		case 0:
			msg = "Droidsound Beta 1\nBy sasq64@gmail.com";
			builder.setMessage(msg);

			break;
		case 10:
			msg = "Could not find sdcard";
			break;
		case 11:
			msg = "Could not write sdcard";
			break;
		case 12:
			msg = "MODS at " + modsDir;
			break;
		case 21:
			builder.setMessage("This will recreate the entire database. It may take a long time. Are you absolutely sure?");
			builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					rescan();
				}
			});
			builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}				
			});
			break;
		case 20 :
			doFullScan = false;
			builder.setTitle("Rescan database");
			builder.setMultiChoiceItems(new String[] { "Full" }, null, new OnMultiChoiceClickListener() {				
				@Override
				public void onClick(DialogInterface dialog, int which, boolean isChecked) {
					Log.v(TAG, String.format("%d %s", which, String.valueOf(isChecked)));
					doFullScan = isChecked;
				}
			});
			builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}				
			});
			builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dialog, int id) {
					dialog.cancel();
					if(doFullScan) {
						showDialog(21);
					} else {
						scan(true);
					}
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
		
		//MenuInflater inflater = getMenuInflater();
		//inflater.inflate(R.menu.songmenu, menu);
		menu.add(Menu.NONE, 10, Menu.NONE, "Details");
		menu.add(Menu.NONE, 11, Menu.NONE, "Favorite");
		menu.add(Menu.NONE, 12, Menu.NONE, "Go to author");
		if(cursor.getColumnIndex("LIST") >= 0) {
			menu.add(Menu.NONE, 13, Menu.NONE, "Remove");
			menu.add(Menu.NONE, 14, Menu.NONE, "Remove All");
		}
		
	}
	
	@Override
	public boolean onContextItemSelected(MenuItem item) {
		//SQLiteDatabase db;
		AdapterContextMenuInfo info = (AdapterContextMenuInfo) item.getMenuInfo();
		//PlayListView.FileInfo finfo = (PlayListView.FileInfo) playListView.getItemAtPosition(info.position);
		Cursor cursor = playListView.getCursor(info.position);
		Log.v(TAG, String.format("%d %s %d %d", item.getItemId(), item.getTitle(), info.position, info.id));
		ContentValues values;
		switch(item.getItemId()) {
		case 12:
			playListView.setDirectory(cursor.getString(cursor.getColumnIndex("PATH")));
			break;
		case 11:
			if(db == null) {
				db = songDatabase.getWritableDatabase();
			}
			values = new ContentValues();
			values.put("LIST", 0);
			int pi = cursor.getColumnIndex("PATH");
			String path = playListView.getDirectory();
			if(pi >= 0) {
				path =  cursor.getString(pi);
			}
			int idx =-1;
			values.put("PATH", path);
			values.put("FILENAME", cursor.getString(cursor.getColumnIndex("FILENAME")));
			idx = cursor.getColumnIndex("TITLE");
			if(idx >= 0)
				values.put("TITLE", cursor.getString(idx));
			idx = cursor.getColumnIndex("COMPOSER");
			if(idx >= 0)
				values.put("COMPOSER", cursor.getString(idx));
			idx = cursor.getColumnIndex("COPYRIGHT");
			if(idx >= 0)
				values.put("COPYRIGHT", cursor.getString(idx));
			idx = cursor.getColumnIndex("FORMAT");
			if(idx >= 0)
				values.put("FORMAT", cursor.getString(idx));
			db.insert("LINKS","PATH", values);
			//db.close();
			break;
		case 13 :
			if(db == null) {
				db = songDatabase.getWritableDatabase();
			}
			db.delete("LINKS", "_id=?", new String [] { Integer.toString(cursor.getInt( cursor.getColumnIndex("_id"))) } );
			//db.close();
			playListView.rescan();
			break;
		case 14 :
			if(db == null) {
				db = songDatabase.getWritableDatabase();
			}
			db.delete("LINKS", "LIST=?", new String [] { Integer.toString(cursor.getInt(cursor.getColumnIndex("LIST"))) } );
			//db.close();
			playListView.rescan();
			break;
		case R.id.details:
			break;
		default:
			return super.onContextItemSelected(item);
		}
		return true;
	}	
}
