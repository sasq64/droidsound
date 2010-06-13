package com.ssb.droidsound;

import java.io.File;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Environment;
import android.os.IBinder;
import android.os.RemoteException;
import android.text.util.Linkify;
import android.util.Log;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.View.OnClickListener;
import android.widget.ImageButton;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

public class DroidSound extends Activity {

	private static final String TAG = "DroidSound";
	private IPlayerService mService;
	private TextView titleTextView;
	private TextView authorTextView;
	private TextView lengthTextView;
	private TextView posTextView;
	private String author;
	private String title;
	private int songLength;
	private SeekBar seekBar;
	private boolean playPause = true;
	private boolean dragging;
	private int subSong;
	protected int totalSongs;
	private ImageButton pauseButton;
	private String modName;
	private ImageButton prevButton;
	private ImageButton nextButton;
	private String playListDir;
	private int playListPos;
	private TextView songsTextView;

	class DownloadTask extends AsyncTask<String, Integer, String> {

		protected String doInBackground(String... downloads) {

			final String ok = "Music downloaded successfully.";
			final String failed = "FAILED to download music";
			
			File modDir = new File(Environment.getExternalStorageDirectory() + "/MODS");

			if(HttpDownloader.downloadFiles(null, modDir.getPath(), downloads)) {
				return ok;
			} else {
				return failed;
			}
		}

		// protected void onProgressUpdate(Integer... progress) { setProgressPercent(progress[0]); }

		@Override
		protected void onPostExecute(String result) {
			Toast t = Toast.makeText(DroidSound.this, result, Toast.LENGTH_SHORT);
			t.show();
		}
	};

	private IPlayerServiceCallback mCallback = new IPlayerServiceCallback.Stub() {

		@Override
		public void stringChanged(int what, String value) throws RemoteException {
			//Log.v(TAG, String.format("%d is now %s", what, value));
			switch(what) {
			case PlayerService.SONG_TITLE:
				if(value != null && value.length() > 0) {
					title = value;
				} else {
					title = modName;
				}
				titleTextView.setText(title);
				playPause = true;
				pauseButton.setImageResource(android.R.drawable.ic_media_pause);
				break;
			case PlayerService.SONG_AUTHOR:
				if(value == null) {
					author = "?";
				} else {
					author = value;
				}
				authorTextView.setText(author);
				break;
			case PlayerService.SONG_FILENAME:
				modName = value;
				break;
			}
		}

		@Override
		public void intChanged(int what, int value) throws RemoteException {
			//Log.v(TAG, String.format("%d is now %d", what, value));
			switch(what) {

			case PlayerService.SONG_LENGTH:
				songLength = value / 1000;
				seekBar.setMax(songLength);
				seekBar.setProgress(0);
				lengthTextView.setText(String.format("%02d:%02d", songLength / 60, songLength % 60));
				break;
			case PlayerService.SONG_TOTALSONGS:
				Log.v(TAG, String.format("We have %d subgsong", value));
				//seekSongBar.setMax(value);
				//seekSongBar.setProgress(0);
				totalSongs = value;
				if(totalSongs > 0) {
					songsTextView.setText(String.format("SONG %02d/%02d", subSong+1, totalSongs));
				} else {
					songsTextView.setText("NO SUBSONGS");
				}
				// lengthTextView.setText(String.format("%02d:%02d",
				// songLength/60, songLength % 60));
				break;
			case PlayerService.SONG_SUBSONG:
				//seekSongBar.setProgress(value);
				subSong = value;
				songsTextView.setText(String.format("SONG %02d/%02d", subSong+1, totalSongs));
				// seekBar.setMax(value);
				// seekBar.s
				break;
			case PlayerService.SONG_POS:
				int sec = value / 1000;
				//Log.v(TAG, "Music at " + sec);
				if(!dragging) {
					seekBar.setProgress(sec);
				}
				posTextView.setText(String.format("%02d:%02d", sec / 60, sec % 60));
				break;
			}
		}
	};

	private ServiceConnection mConnection = new ServiceConnection() {

		@Override
		public void onServiceConnected(ComponentName className, IBinder service) {
			mService = IPlayerService.Stub.asInterface(service);
			Log.v(TAG, "Service now bound");

			try {
				mService.registerCallback(mCallback, 0);
			} catch (RemoteException e) {
				e.printStackTrace();
			}

		}

		@Override
		public void onServiceDisconnected(ComponentName name) {
			// TODO Auto-generated method stub

		}
	};

	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle state) {
		super.onCreate(state);

		Intent intent = getIntent();
		String action = intent.getAction();

		if(action != null && action.contentEquals(Intent.ACTION_VIEW)) {
			Intent i = new Intent(this, PlayerService.class);
			i.setData(intent.getData());
			i.setAction(Intent.ACTION_VIEW);
			startService(i);
			finish();
			return;
		}

		// requestWindowFeature(Window.FEATURE_PROGRESS);

		setContentView(R.layout.main);

		// setProgressBarVisibility(true);
		// setProgress(500);

		/*ImageButton b = (ImageButton) findViewById(R.id.moreButton);
		b.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				Intent i = new Intent(DroidSound.this, PlayListActivity.class);
				startActivityForResult(i, 0);
			}
		});*/

		titleTextView = (TextView) findViewById(R.id.titleText);
		authorTextView = (TextView) findViewById(R.id.authorText);
		lengthTextView = (TextView) findViewById(R.id.totaltime);
		posTextView = (TextView) findViewById(R.id.currenttime);
		seekBar = (SeekBar) findViewById(R.id.seekBar);
		/*
		seekBar.setOnLongClickListener(new OnLongClickListener() {			
			@Override
			public boolean onLongClick(View v) {
				return false;
			}
		});
		*/
		/*
		seekBar.setOnCreateContextMenuListener(new OnCreateContextMenuListener() {			
		});
		*/

		
		//seekSongBar = (SeekBar) findViewById(R.id.seekSongBar);
		//seekSongBar.setMax(3);
		//seekSongBar.setProgress(0);
		songsTextView = (TextView) findViewById(R.id.songsView);

		
		pauseButton = (ImageButton) findViewById(R.id.pauseButton);
        registerForContextMenu(pauseButton);

		pauseButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				try {
					if(mService.playPause(!playPause)) {
						playPause = !playPause;
						if(playPause) {
							pauseButton.setImageResource(android.R.drawable.ic_media_pause);
						} else {
							pauseButton.setImageResource(android.R.drawable.ic_media_play);
						}
					} else {
						Intent i = new Intent(DroidSound.this, PlayListActivity.class);
						i.putExtra("directory", playListDir);
						startActivityForResult(i, 0);
					}
				} catch (RemoteException e) {
				}

			}
		});

		prevButton = (ImageButton) findViewById(R.id.prevButton);
		prevButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				try {
					mService.playPrev();
				} catch (RemoteException e) {
				}
			}
		});

		nextButton = (ImageButton) findViewById(R.id.nextButton);
		nextButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				try {
					mService.playNext();
				} catch (RemoteException e) {
				}
			}
		});

		seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {

			private int to = -1;

			@Override
			public void onStopTrackingTouch(SeekBar seekBar) {
				dragging = false;
				lengthTextView.setText(String.format("%02d:%02d", songLength / 60, songLength % 60));
				try {
					if(to >= 0) {
						mService.seekTo(to * 1000);
					}
				} catch (RemoteException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				to = -1;
			}

			@Override
			public void onStartTrackingTouch(SeekBar seekBar) {
				dragging = true;
			}

			@Override
			public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
				if(fromUser) {
					to = progress;
					lengthTextView.setText(String.format("%02d:%02d", to / 60, to % 60));
				}
			}
		});
/*
		seekSongBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {

			//private boolean dragging;
			private int to = -1;

			@Override
			public void onStopTrackingTouch(SeekBar seekBar) {
				dragging = false;
				// lengthTextView.setText(String.format("%02d:%02d",
				// songLength/60, songLength % 60));
				songsTextView.setText(String.format("%02d", totalSongs));
				try {
					if(to >= 0) {
						mService.setSubSong(to);
					}
				} catch (RemoteException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				to = -1;
			}

			@Override
			public void onStartTrackingTouch(SeekBar seekBar) {
				dragging = true;
			}

			@Override
			public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
				if(fromUser) {
					to = progress;
					songsTextView.setText(String.format("%02d", to));
					// lengthTextView.setText(String.format("%02d:%02d", to/60,
					// to % 60));
				}
			}
		});
*/
		author = "";
		title = "";
		if(state != null) {
			Log.v(TAG, "Setting title");
			title = state.getString("title");
			if(title == null)
				title = "";

			Log.v(TAG, "Setting author");
			author = state.getString("author");
			if(author == null)
				author = "";
		}
		titleTextView.setText(title);
		authorTextView.setText(author);

		Intent i = new Intent(this, PlayerService.class);
		startService(i);
		bindService(i, mConnection, Context.BIND_AUTO_CREATE);

		File modDir = new File(Environment.getExternalStorageDirectory() + "/MODS");

		if(!modDir.exists()) {
			modDir.mkdir();
			showDialog(0);
		} else {
			String[] s = modDir.list();
			if(s.length <= 0) {
				showDialog(0);
			}
		}
	}

	@Override
	protected Dialog onCreateDialog(int id) {

		AlertDialog.Builder builder = new AlertDialog.Builder(this);
		switch(id) {
		case 0:
			builder.setMessage(R.string.mod_dl_text)
				.setCancelable(false).setPositiveButton("Yes", new DialogInterface.OnClickListener() {
					public void onClick(DialogInterface dialog, int id) {
						new DownloadTask().execute("http://swimmer.se/droidsound/mods.zip");
					}
				}).setNegativeButton("No", new DialogInterface.OnClickListener() {
					public void onClick(DialogInterface dialog, int id) {
						dialog.cancel();
					}
				});
			break;
		case 1:
			builder.setTitle("About DroidSound").setCancelable(true)
			.setNegativeButton("Ok", new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dialog, int id) {
					dialog.cancel();
				}
			});
			TextView tv = new TextView(this);
			tv.setAutoLinkMask(Linkify.WEB_URLS);
			tv.setText(R.string.about_text);
			builder.setView(tv);
			//.setMessage(R.string.about_text)
		break;
		}
		return builder.create();
	}


	@Override
	protected void onDestroy() {
		super.onDestroy();
		Log.v(TAG, "Destroy " + Thread.currentThread().getId());
		if(mConnection != null && mService != null) {
			unbindService(mConnection);
		}
	}

	@Override
	protected void onSaveInstanceState(Bundle outState) {
		// TODO Auto-generated method stub
		super.onSaveInstanceState(outState);
		outState.putString("title", title);
		outState.putString("author", author);
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {

		Log.v(TAG, "Result " + resultCode);

		if(resultCode != RESULT_CANCELED) {

			Bundle b = data.getExtras();
			
			playListDir = b.getString("directory");
			playListPos = b.getInt("position");

			if(requestCode == 0) {
				String f =  b.getString("musicFile");
				int musicListPos = b.getInt("musicPos");
				String [] musicList = (String []) b.getSerializable("musicList");
				
				modName = f;
				Log.v(TAG, "Playing file " + modName);

				if(playPause) {
					playPause = false;
			        pauseButton.setImageResource(android.R.drawable.ic_media_pause);
					try {
						mService.playPause(playPause);
					} catch (RemoteException e) {
					}
				}


				if(mService != null)
					try {
						if(musicList != null) {							
							Log.v(TAG, String.format("Playing list with %d entries, first %s,%s from position %d", musicList.length, musicList[0], musicList[1], musicListPos));							
							mService.playList(musicList, musicListPos);
						} else {						
							mService.playMod(modName);
						}
					} catch (RemoteException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}

				// player.playMod(name);
			} else {
				String name = "http://ftp.amigascne.org/mirrors/ftp.modland.com/pub/modules/" + b.getString("name");
				Log.v(TAG, "Trying to download " + name);
				new DownloadTask().execute(name);
			}
		}

		// ftp://modland.ziphoid.com/pub/modules/
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		menu.add(0, 10, 0, "Songs").setIcon(R.drawable.ic_menu_music_library);
		menu.add(0, 12, 0, "About").setIcon(android.R.drawable.ic_menu_info_details);
		menu.add(0, 11, 0, "Quit").setIcon(android.R.drawable.ic_menu_close_clear_cancel);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		int choice = item.getItemId();
		switch(choice) {
		case 11:
			try {
				mService.stop();
			} catch (RemoteException e) {
			}
			finish();
			break;
		case 10:
			Intent i = new Intent(DroidSound.this, PlayListActivity.class);
			i.putExtra("directory", playListDir);
			i.putExtra("position", playListPos);
			startActivityForResult(i, 0);
			break;
		case 12:
			showDialog(1);			
			break;
		}
		return true;
	}
	
	
	@Override
	public void onCreateContextMenu(ContextMenu menu, View v, ContextMenuInfo menuInfo) {
		Log.v(TAG, "We want menu");
		if(totalSongs < 2) {
			menu.add(0, -1, 0, "No Subsongs");
			return;
		}
		
		for(int i=0; i<totalSongs; i++) {
			menu.add(0, i, 0, "Subsong " + (i+1));
		}
	}

	@Override
	public boolean onContextItemSelected(MenuItem item) {
		int i = item.getItemId();
		if(i<0) return true;
		try {
			mService.setSubSong(i);
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return true;
		
	}


}