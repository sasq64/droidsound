package com.ssb.droidsound;

import java.io.File;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.SearchManager;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.widget.AbsListView;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.ImageButton;
import android.widget.SlidingDrawer;
import android.widget.TextView;
import android.widget.AbsListView.OnScrollListener;

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

	private static AsyncTask<Void, String, Void> scanTask = null;
	
	private void scan(SongDatabase db, boolean full) {
		
		if(scanTask != null) {
			Log.v(TAG, "Already scanning! exiting scan...");
			return;
		}
			
		final SongDatabase songDatabase = db;
		final boolean fullScan = full;
		final NotificationManager manager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);	
		
		
		//RemoteViews contentView = new RemoteViews(getPackageName(), R.layout.notification_progress);
		//contentView.setProgressBar(R.id.np_progress, 100, 50, false);
		
		final Notification notification = new Notification(R.drawable.note, "Scanning", System.currentTimeMillis());				
		Intent notificationIntent = new Intent(PlayerActivity.this, PlayerActivity.class);
		final PendingIntent contentIntent = PendingIntent.getActivity(PlayerActivity.this, 0, notificationIntent, 0);

		//notification.contentView = contentView;
		//notification.contentIntent = contentIntent;
		
		//notification.setLatestEventInfo(PlayerActivity.this, "Scanning", "what", contentIntent);
		//manager.notify(1, notification);
		
		scanTask = new AsyncTask<Void, String, Void>() {
			
			boolean notified = false;
			String path = null;
			
			@Override
			protected Void doInBackground(Void... arg) {
								
				songDatabase.setScanCallback(new SongDatabase.ScanCallback() {					
					@Override
					public void notifyScan(String p, int percent) {
						
						Log.v(TAG, String.format("NOTIFY %s %s %d", p, path, percent));
						
						if(p != null) {
							path = p;
						}
						if(percent > 0) {
							publishProgress(String.format("%s [%02d%%]", path, percent));
						} else {
							publishProgress(String.format("%s", path));
						}
					}
				});

				songDatabase.scan(fullScan, modsDir);
				songDatabase.setScanCallback(null);
				return null;
			}
			
			@Override
			protected void onProgressUpdate(String... values) {
					
				
				//Log.v(TAG, String.format("NOTIFY %s", values[0]));

				if(values[0] != null) {
					notification.setLatestEventInfo(PlayerActivity.this, "Scanning", values[0], contentIntent);
					manager.notify(1, notification);
					if(!notified) {
						notified = true;
					}
				}
			}

			@Override
			protected void onPostExecute(Void result) {
				
				if(notified) {
					manager.cancel(1);
				}
				
				playListView.rescan();
				scanTask = null;
			}
		};

		scanTask.execute((Void)null);
	}
	
	@Override
	protected void onNewIntent(Intent intent) {
		setIntent(intent);
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
		
		songDatabase = new SongDatabase(this);
		playListView.setDatabase(songDatabase);
		
		songDatabase.setScanCallback(new SongDatabase.ScanCallback() {
			
			NotificationManager manager;
			Notification notification;
			PendingIntent contentIntent;
			
			@Override
			public void notifyScan(String path, int percent) {

				if(manager == null) {
					
					if(path == null) {
						return;
					}
					
					Log.v(TAG, String.format("NOTIFY %s %d", path, percent));
					
					NotificationManager manager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);		
					notification = new Notification(R.drawable.note, "Scanning", System.currentTimeMillis());
							
					Intent notificationIntent = new Intent(PlayerActivity.this, PlayerActivity.class);
					contentIntent = PendingIntent.getActivity(PlayerActivity.this, 0, notificationIntent, 0);
					notification.setLatestEventInfo(PlayerActivity.this, "Scanning", path, contentIntent);
					manager.notify(1, notification);
					return;
				}
				
				if(percent == -1) {
					manager.cancel(1);
				} else {				
					notification.setLatestEventInfo(PlayerActivity.this, "Scanning", path, contentIntent);
				}
				
			}
		});
		
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
					parentButton.setText("");
					parentButton.setVisibility(View.INVISIBLE);
				} else {
					parentButton.setText(f.getParentFile().getName());
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
		scan(songDatabase, false);
		//songDatabase.registerPath(name, cb)
		
		playListView.setDirectory(currentPath);
		playListView.setPlayer(player);
	}
	
	
	@Override
	protected void onResume() {
		super.onResume();
		player.bindService(this, this);
	}
	
	@Override
	protected void onPause() {
		super.onPause();
		player.unbindService(this);
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
			songLength = value;
			break;
		case PlayerService.SONG_POS :
			songPos = value/1000;
			songDigitsText.setText(String.format("%02d:%02d [%02d/%02d]", songPos/60, songPos%60, subTune+1, subTuneCount));
			break;
		case PlayerService.SONG_SUBSONG :
			subTune = value;
			songDigitsText.setText(String.format("%02d:%02d [%02d/%02d]", songPos/60, songPos%60, subTune+1, subTuneCount));
			break;
		case PlayerService.SONG_TOTALSONGS :
			subTuneCount = value;
			songDigitsText.setText(String.format("%02d:%02d [%02d/%02d]", songPos/60, songPos%60, subTune+1, subTuneCount));
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
	public boolean onCreateOptionsMenu(Menu menu) {
		menu.add(0, 10, 0, "Rescan").setIcon(R.drawable.ic_menu_music_library);
		menu.add(0, 11, 0, "About").setIcon(android.R.drawable.ic_menu_info_details);
		menu.add(0, 12, 0, "Quit").setIcon(android.R.drawable.ic_menu_close_clear_cancel);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		int choice = item.getItemId();
		switch(choice) {
		case 10:
			scan(songDatabase, true);
			break;
		case 11 :
			showDialog(0);
			break;
		case 12:
			player.stop();
			finish();
		}		
		return true;
	}
	
	@Override
	protected Dialog onCreateDialog(int id) {
		
		String msg = "SWAY WAT?";
		
		switch(id) {
		case 0:
			msg = "Droidsound Beta 1\nBy sasq64@gmail.com";
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
		}
		
		AlertDialog.Builder builder = new AlertDialog.Builder(this);
		builder.setMessage(msg)
		       .setPositiveButton("OK", new DialogInterface.OnClickListener() {
		           public void onClick(DialogInterface dialog, int id) {
		                dialog.cancel();
		           }
		       });
		AlertDialog alert = builder.create();
		return alert;
	}

	
}
