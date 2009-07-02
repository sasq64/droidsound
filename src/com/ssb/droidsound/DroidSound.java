package com.ssb.droidsound;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.ServiceConnection;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Environment;
import android.os.IBinder;
import android.os.RemoteException;					
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.view.View.OnClickListener;
import android.widget.BaseAdapter;
import android.widget.ImageButton;
import android.widget.MediaController;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.MediaController.MediaPlayerControl;

public class DroidSound extends Activity implements MediaPlayerControl, MediaPlayer.OnPreparedListener,MediaPlayer.OnBufferingUpdateListener {
	
	private static final String TAG = "Test";
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

    private IPlayerServiceCallback mCallback = new IPlayerServiceCallback.Stub() {


		@Override
		public void stringChanged(int what, String value) throws RemoteException {
			Log.v(TAG, String.format("%d is now %s", what, value));
			switch(what) {
			case PlayerService.SONG_TITLE:
				if(value != null && value.length() > 0) {
					title = value;
				} else {
					title = modName;
				}
				titleTextView.setText(title);
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
			Log.v(TAG, String.format("%d is now %d", what, value));
			switch(what) {
			
			case PlayerService.SONG_LENGTH:
				songLength = value / 1000;
				seekBar.setMax(songLength);
				seekBar.setProgress(0);
				lengthTextView.setText(String.format("%02d:%02d", songLength/60, songLength % 60));
				break;
			case PlayerService.SONG_TOTALSONGS:
				Log.v(TAG, String.format("We have %d subgsong", value));
				seekSongBar.setMax(value);
				seekSongBar.setProgress(0);
				songsTextView.setText(String.format("%02d", value));
				totalSongs = value;
				//lengthTextView.setText(String.format("%02d:%02d", songLength/60, songLength % 60));
				break;
			case PlayerService.SONG_SUBSONG:
				seekSongBar.setProgress(value);
				subSong = value;
				//seekBar.setMax(value);
				//seekBar.s
				break;
			case PlayerService.SONG_POS:
				int sec = value/1000;
				Log.v(TAG, "Music at " + sec);
				if(!dragging) {
					seekBar.setProgress(sec);
				}
				posTextView.setText(String.format("%02d:%02d", sec/60, sec % 60));
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
    			//modName = mService.getStringValue(PlayerService.SONG_FILENAME);
    			//songLength = mService.getIntValue(PlayerService.SONG_LENGTH) / 1000;
    			//lengthTextView.setText(String.format("%02d:%02d", songLength/60, songLength % 60));
    			//int sec = mService.getIntValue(PlayerService.SONG_POS) / 1000;
				//seekBar.setProgress(sec);
				//posTextView.setText(String.format("%02d:%02d", sec/60, sec % 60));
    		} catch (RemoteException e) {
    			// TODO Auto-generated catch block
    			e.printStackTrace();
    		}

        	
        }

		@Override
		public void onServiceDisconnected(ComponentName name) {
			// TODO Auto-generated method stub
			
		}
   };
private ImageButton pauseButton;
private String modName;
private ImageButton prevButton;
private ImageButton nextButton;
private SeekBar seekSongBar;
private TextView songsTextView;


	@Override
	protected void onStart() {
		// TODO Auto-generated method stub
		super.onStart();
		Log.v(TAG, "Droidsound started");
	}
		
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

        
        
        //requestWindowFeature(Window.FEATURE_PROGRESS);
        // 
        
        setContentView(R.layout.main);
        
        //setProgressBarVisibility(true);
        //setProgress(500);

  /*
        URL url = null;
		URI uri = null;
		try {
			url = new URL("ftp://modland.com/pub/some thing/more here.xxx");
		} catch (MalformedURLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
        try {
			uri = url.toURI();
		} catch (URISyntaxException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
    */    
        //try {
        //} catch (URISyntaxException e) {
            // do nothing.
        //}
  
        
        
        //LinearLayout v = new LinearLayout(this);
        //v.set
        //setContentView(v);

        //LinearLayout v = (LinearLayout)findViewById(R.id.LinearLayout01);
        
        //ListView mGrid = (ListView) findViewById(R.id.infoList);
        //mGrid.setAdapter(new MyAdapter());

        
        //Button b;

       // b = (Button) findViewById(R.id.playButton);
        //b.setOnClickListener(this);
        
		//b = new Button(this);
		//b.setText("Stop!");
        //b = (Button) findViewById(R.id.stopButton);
		//b.setOnClickListener(new OnClickListener() {
		//	public void onClick(View v) {
		//		player.stop();
		//		finish();
		//	}
		//});
		//v.addView(b);
               
        //b = new Button(this);
        //b.setText("List!");
		ImageButton b = (ImageButton) findViewById(R.id.moreButton);
		b.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				Intent i = new Intent(DroidSound.this, PlayListActivity.class);
				startActivityForResult(i, 0);
			}
		});
		
		titleTextView = (TextView) findViewById(R.id.titleText);
		authorTextView = (TextView) findViewById(R.id.authorText);
		lengthTextView = (TextView) findViewById(R.id.lengthView);
		posTextView = (TextView) findViewById(R.id.posTextView);
		seekBar = (SeekBar) findViewById(R.id.seekBar);
		seekSongBar = (SeekBar) findViewById(R.id.seekSongBar);
		seekSongBar.setMax(3);
		seekSongBar.setProgress(0);
		songsTextView = (TextView) findViewById(R.id.songsView);

		pauseButton = (ImageButton) findViewById(R.id.pauseButton);		
		pauseButton.setOnClickListener(new OnClickListener() {			

			@Override
			public void onClick(View v) {
				playPause = !playPause;
				if(playPause) {
					pauseButton.setImageResource(android.R.drawable.ic_media_pause);
				} else {
					pauseButton.setImageResource(android.R.drawable.ic_media_play);
				}
				try {
					mService.playPause(playPause);
				} catch (RemoteException e) {
				}
				
			}
		});
		
		prevButton = (ImageButton) findViewById(R.id.prevButton);		
		prevButton.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				if(skip(-1)) {
					try {
						mService.playMod(modName);
					} catch (RemoteException e) {
					}
				}				
			}
		});

		nextButton = (ImageButton) findViewById(R.id.nextButton);		
		nextButton.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				if(skip(1)) {
					try {
						mService.playMod(modName);
					} catch (RemoteException e) {
					}
				}				
			}
		});

		seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
			
			private int to = -1;
			@Override
			public void onStopTrackingTouch(SeekBar seekBar) {
				dragging = false;
				lengthTextView.setText(String.format("%02d:%02d", songLength/60, songLength % 60));
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
					lengthTextView.setText(String.format("%02d:%02d", to/60, to % 60));
				}
			}
		});
		
		seekSongBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
			
			private boolean dragging;
			private int to = -1;
			@Override
			public void onStopTrackingTouch(SeekBar seekBar) {
				dragging = false;
				//lengthTextView.setText(String.format("%02d:%02d", songLength/60, songLength % 60));
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
					//lengthTextView.setText(String.format("%02d:%02d", to/60, to % 60));
				}
			}
		});

		author = "";
		title = "";
		if(state != null) {
			Log.v(TAG, "Setting title");
			title = state.getString("title");
			if(title == null) title = "";
	
			Log.v(TAG, "Setting author");
			author = state.getString("author");
			if(author == null) author = "";
		}
		titleTextView.setText(title);
		authorTextView.setText(author);

		//v.addView(b);
		
		//SurfaceView sv = (SurfaceView) findViewById(R.id.surfaceView);

		//SurfaceView sv = new SurfaceView(this);
		//sv.set
		//v.addView(sv);
		
		//FrameLayout fl = (FrameLayout) findViewById(R.id.FrameLayout01);
		
		//mediaCtrl =  (MediaController) findViewById(R.id.mediaController);		
		//mediaCtrl = new MediaController(this);		
		//mediaCtrl.setMediaPlayer(this);
        //mediaCtrl.setAnchorView(sv);
        //mediaCtrl.setEnabled(true);
        
        //fl.addView(mediaCtrl);
        
        //mediaCtrl.show(0);
		

		//Intent intent = getIntent();
        //Uri uri = intent.getData();
        
        //Log.v(TAG, String.format("INTENT %s %s %s", intent.getAction(), intent.getDataString(), intent.getType()));

        //String action = intent.getAction();

        Intent i = new Intent(this, PlayerService.class);
        //if(action != null && action.contentEquals(Intent.ACTION_VIEW)) {
        //	i.setData(uri);
        //	i.setAction(Intent.ACTION_VIEW);
        //}
        startService(i);
        bindService(i, mConnection, Context.BIND_AUTO_CREATE);
        
    	File modDir = new File(Environment.getExternalStorageDirectory()+"/MODS");
    	
		if(!modDir.exists()) {
    		modDir.mkdir();
            showDialog(0);
    	} else {
        	String [] s = modDir.list();
        	if(s.length <= 0) {
        		showDialog(0);
        	}
    	}
    }
    
	@Override
	protected Dialog onCreateDialog(int id) {

		AlertDialog.Builder builder = new AlertDialog.Builder(this);
		builder.setMessage("Modules goes into the 'MODS' directory on your sdcard, but it seems you don't have any. Do you want to donload a few (~100KB) to get you going?")
				.setCancelable(false).setPositiveButton("Yes",
						new DialogInterface.OnClickListener() {
							public void onClick(DialogInterface dialog, int id) {
								new DroidSound.DownloadTask()
										.execute("http://swimmer.se/droidsound/mods.zip");
							}
						}).setNegativeButton("No",
						new DialogInterface.OnClickListener() {
							public void onClick(DialogInterface dialog, int id) {
								dialog.cancel();
							}
						});
		return builder.create();
	}
    
	class DownloadTask extends AsyncTask<String, Integer, String> {

		protected String doInBackground(String... downloads) {

			final String ok = "Music downloaded successfully.";
			final String failed = "FAILED to download music";
			
			if(downloadMods(downloads)) {
				return ok;
			} else {
				return failed;
			}
		}
		/*
		 * protected void onProgressUpdate(Integer... progress) {
		 * //setProgressPercent(progress[0]); }
		 */
		@Override
		protected void onPostExecute(String result) {
			Toast t = Toast.makeText(DroidSound.this, result,
					Toast.LENGTH_SHORT);// new Toast(DroidSound.this);
			t.show();
		}
	};
    
    protected boolean downloadMods(String...urls) {
    	    	
		try {
			InputStream in = null;
			int response = -1;
			int size;
			byte[] buffer = new byte[16384];

			String outDir = Environment.getExternalStorageDirectory() + "/MODS/";

			for (String u : urls) {
				
				String uu = urlencode(u);
				URL url = new URL(uu);
				
				Log.v(TAG, "Opening URL " + uu);
				
				URLConnection conn = url.openConnection();
				if (!(conn instanceof HttpURLConnection))
					throw new IOException("Not a HTTP connection");

				HttpURLConnection httpConn = (HttpURLConnection) conn;
				httpConn.setAllowUserInteraction(false);
				httpConn.setInstanceFollowRedirects(true);
				httpConn.setRequestMethod("GET");
				
				Log.v(TAG, "Connecting");
				
				httpConn.connect();

				response = httpConn.getResponseCode();
				if(response == HttpURLConnection.HTTP_OK)
				{
					Log.v(TAG, "HTTP connected");
					in = httpConn.getInputStream();
					
					String ext = u.substring(u.lastIndexOf('.') + 1, u.length());
					String baseName = new File(u).getName();

					if(ext.compareToIgnoreCase("ZIP") == 0) {
						ZipInputStream zip = new ZipInputStream(in);
						ZipEntry e;
						while ((e = zip.getNextEntry()) != null) {
							Log.v(TAG, "Found file " + e.getName());
							FileOutputStream fos = new FileOutputStream(outDir
									+ e.getName());
							BufferedOutputStream bos = new BufferedOutputStream(
									fos, buffer.length);
							while ((size = zip.read(buffer, 0, buffer.length)) != -1) {
								bos.write(buffer, 0, size);
							}
							bos.flush();
							bos.close();
						}

					} else {
						
						Log.v(TAG, "Writing " + baseName);
						
						FileOutputStream fos = new FileOutputStream(outDir + baseName);
						BufferedOutputStream bos = new BufferedOutputStream(fos, buffer.length);
						
						while ((size = in.read(buffer)) != -1) {
							bos.write(buffer, 0, size);
						}
						bos.flush();
						bos.close();
					}

				} else
					return false;
			}
		} catch (IOException e) {
			e.printStackTrace();
			Log.w(TAG, "OOPS");
			return false;
		}
		return true;
	}
  
	boolean skip(int i) {
    	
    	if(modName == null)
    		return false;
    	
    	File modDir = new File(modName).getParentFile();
    	if(modDir == null)
    		return false;
    	File [] files = modDir.listFiles();
    	
    	if(files.length <= 0)
    		return false;

    	boolean getNext = false;
    	File lastFile = null;
    	for(File f : files) {
    		if(getNext) {
    			modName = f.getPath();
    			return true;
    		}
    		if(f.getPath().compareToIgnoreCase(modName) == 0) {
    			if(i < 0) {
    				if(lastFile != null) {
    					modName = lastFile.getPath();
    					return true;
    				}
    				return false;
    			}
    			getNext = true;
    		}
    		
    		lastFile = f;
    	}
    	
    	if(getNext)
    		return false;
    	
   		return true;
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
	public boolean onTouchEvent(MotionEvent event) {
		// TODO Auto-generated method stub
 		//mediaCtrl.show(0);
 		//player.playMod("madness.mod");
 		//Log.v(TAG, "Playing music");
		return true;
	}
 	
 	String urlencode(String s) {
 		StringBuilder t = new StringBuilder();
 		
 		for(int i = 0; i<s.length(); i++) {
 			char c = s.charAt(i);
 			switch(c) {
 			case 0x20:
 			case 0x24:
 			case 0x25:
 			case 0x26:
 			case 0x2B:
 			case 0x2C:
 			//case 0x2F:
 			//case 0x3A:
 			case 0x3B:
 			case 0x3D:
 			case 0x3F:
 			case 0x40:
 				t.append(String.format("%%%02x", (int)c));
 				break;
 			default:
 				t.append(c);
 				break;
 			}
 		}
 		
 		return t.toString();
 	}
 	
 	@Override
 	protected void onActivityResult(int requestCode, int resultCode, Intent data) {

 		Log.v(TAG, "Result " + resultCode);

 		if(resultCode != RESULT_CANCELED) {

 			Bundle b = data.getExtras();
 			
 			if(requestCode == 0) {
	 			modName = b.getString("fileName");
	 			Log.v(TAG, "Playing file " + modName);
	 			
	 			if(mService != null)
					try {
						mService.playMod(modName);
					} catch (RemoteException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
	 			
	 			//player.playMod(name);
 			} else {
 				String name = "http://ftp.amigascne.org/mirrors/ftp.modland.com/pub/modules/" + b.getString("name");
 				Log.v(TAG, "Trying to download " + name);
				new DownloadTask().execute(name);
 			}
 		}
 		
 		// ftp://modland.ziphoid.com/pub/modules/
 	}

	@Override
	public int getBufferPercentage() {
		// TODO Auto-generated method stub
		return 100;
	}

	@Override
	public int getCurrentPosition() {
		// TODO Auto-generated method stub
		return 0;//player.getPosition();
	}

	@Override
	public int getDuration() {
		// TODO Auto-generated method stub
		return songLength;//player.getLength();
	}

	@Override
	public boolean isPlaying() {
		// TODO Auto-generated method stub
		return true;
	}

	@Override
	public void pause() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void seekTo(int pos) {
		// TODO Auto-generated method stub
		Log.v(TAG, "Seek to " + pos);
		//player.seekTo(pos);
		
	}

	@Override
	public void start() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onPrepared(MediaPlayer mp) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onBufferingUpdate(MediaPlayer mp, int percent) {
		// TODO Auto-generated method stub
		
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		menu.add(0, 10, 0, "Search MODLAND").setIcon(android.R.drawable.ic_menu_search);
		menu.add(0, 11, 0, "Quit").setIcon(android.R.drawable.ic_menu_close_clear_cancel);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		if(item.getItemId() == 11) {
			//player.stop();
			try {
				mService.stop();
			} catch (RemoteException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			finish();
		} else if(item.getItemId() == 10) {
			//Intent i = new Intent(DroidSound.this, SearchResultActivity.class);
			//i.putExtra("game", "Combat%");
			Intent i = new Intent(DroidSound.this, SearchActivity.class);
			startActivityForResult(i, 1);
		}
			//mediaCtrl.show(0);
		return true;
	}

	
	
    public class MyAdapter extends BaseAdapter {
        public MyAdapter() {
        }

        public View getView(int position, View convertView, ViewGroup parent) {
            TextView i;
            //TwoLineListItem i;

            if (convertView == null) {
                //i = new TwoLineListItem(DroidSound.this);
                i = new TextView(DroidSound.this);
                i.setText("Tjo " + position);
                //i.getText1().setText("Author");
                //i.getText1().setPadding(20,0,0,0);
                //i.getText2().setText("Tjo " + position);
            } else {
                //i = (TwoLineListItem) convertView;
                i = (TextView) convertView;
            }

            return i;
        }


        public final int getCount() {
            return 3;
        }
        
        @Override
        public boolean isEnabled(int pos) {
        	return false;
        }

        public final Object getItem(int position) {
            return position; //mApps.get(position);
        }

        public final long getItemId(int position) {
            return position;
        }
    }
    
    class MyMediaController extends MediaController {

		public MyMediaController(Context context) {
			super(context);
		}
		@Override
		public void hide() {
			super.hide();
		}		    
		
    }

}