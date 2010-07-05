package com.ssb.droidsound;

import java.io.File;

import android.app.Activity;
import android.app.SearchManager;
import android.content.Context;
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
import android.view.ViewGroup;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.widget.AbsListView;
import android.widget.FrameLayout;
import android.widget.ImageButton;
import android.widget.RelativeLayout;
import android.widget.SlidingDrawer;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.AbsListView.OnScrollListener;
import android.widget.RelativeLayout.LayoutParams;

public class PlayerActivity extends Activity implements PlayerServiceConnection.Callback {
	private static final String TAG = "DroidSound";

	private PlayerServiceConnection player = new PlayerServiceConnection();
	private ImageButton playButton;
	private ImageButton backButton;
	private ImageButton fwdButton;
	private ImageButton stopButton;
	
	private TextView songTitleText;
	private TextView songComposerText;
	private TextView songDigitsText;
	private PlayListView playListView;
	private SlidingDrawer drawer;

	private int songLength;
	private int songPos;
	private int subTune;
	private int subTuneCount;
	private boolean mIsPlaying = false;
	private boolean controlsHidden = false;

	private SongDatabase songDatabase;

	private FrameLayout listFrame;

	private View infoDisplay;

	private View controls;

	private String playingFile;


	private static void Log(String fmt, Object...args) {
		Log.v(TAG, String.format(fmt, args));
	}

	private void scan(SongDatabase db, boolean full) {
		
		final SongDatabase songDatabase = db;
		final boolean fullScan = full;
		
		AsyncTask<Void, Void, Void> task = new AsyncTask<Void, Void, Void>() {
			@Override
			protected Void doInBackground(Void... arg) {
				songDatabase.scan(fullScan);
				return null;
			}

			@Override
			protected void onPostExecute(Void result) {
				Toast t = Toast.makeText(PlayerActivity.this, "Scan done", Toast.LENGTH_SHORT);
				t.show();
				playListView.rescan();				
			}
		};

		task.execute((Void)null);
	}
	
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		player.bindService(this, this);
		
		setContentView(R.layout.player2);
		playButton = (ImageButton) findViewById(R.id.play_button);
		backButton = (ImageButton) findViewById(R.id.back_button);
		fwdButton = (ImageButton) findViewById(R.id.fwd_button);
		stopButton = (ImageButton) findViewById(R.id.stop_button);
		songTitleText = (TextView) findViewById(R.id.title_text);
		songComposerText = (TextView) findViewById(R.id.composer_text);
		songDigitsText = (TextView) findViewById(R.id.seconds_text);
		playListView = (PlayListView) findViewById(R.id.play_list);
		drawer = (SlidingDrawer) findViewById(R.id.drawer);
		listFrame = (FrameLayout) findViewById(R.id.play_list_frame);
		infoDisplay = findViewById(R.id.info_display);
		controls = findViewById(R.id.controls);
		
		//int top = drawer.getTop();
		//Log.v(TAG, String.format("TOP %d", top));
		
		playListView.setOnScrollListener(new OnScrollListener() {
			@Override
			public void onScrollStateChanged(AbsListView view, int scrollState) {
				// TODO Auto-generated method stub
				Log("Scroll state %d", scrollState);
				if(scrollState == SCROLL_STATE_FLING) {
					if(!controlsHidden) {
						controlsHidden = true;
						controls.setVisibility(View.GONE);
						infoDisplay.setVisibility(View.GONE);
					}
				}
			}
			
			@Override
			public void onScroll(AbsListView view, int firstVisibleItem, int visibleItemCount, int totalItemCount) {
				Log("Scroll %d/%d/%d", firstVisibleItem, visibleItemCount, totalItemCount);
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
				subTune -= 1;
				if(subTune < 0) {
					player.playPrev();
				} else {
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
				subTune += 1;
				if(subTune < subTuneCount) {
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
		
		SharedPreferences prefs = getSharedPreferences("songdb", Context.MODE_PRIVATE);
		String searchPath = prefs.getString("searchPath", null);
		if(searchPath == null) {
			File ext = Environment.getExternalStorageDirectory();
			searchPath = ext + "/MODS";
			// Galaxy S Hack
			if(new File(ext, "sd").isDirectory()) {
				searchPath += (":" + ext + "/sd/MODS");
			}
			Editor editor = prefs.edit();
			editor.putString("searchPath", searchPath);
			editor.commit();
		}

		Intent intent = getIntent();
		
		Log.v(TAG, String.format("SEARCHPATH: %s", searchPath));

		if(Intent.ACTION_SEARCH.equals(intent.getAction())) {
			songDatabase = new SongDatabase(this);
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
		
		songDatabase = new SongDatabase(this);		
		scan(songDatabase, false);
		
		playListView.setBaseDir("/MODS");
		playListView.setPlayer(player);	  
	}
	
	@Override
	protected void onDestroy() {
		super.onDestroy();
		player.unbindService();
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
	}

	@Override
	public void stringChanged(int what, String value) {
		switch(what) {
		case PlayerService.SONG_FILENAME :
			playListView.setSelection(value);
			playingFile = value;
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
		
		if(choice == 10) {
			scan(songDatabase, true);
		}
		
		return true;
	}

	
}
