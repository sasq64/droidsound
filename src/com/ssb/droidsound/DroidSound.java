package com.ssb.droidsound;

import java.io.File;

import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.View.OnClickListener;
import android.widget.BaseAdapter;
import android.widget.ImageButton;
import android.widget.MediaController;
import android.widget.SeekBar;
import android.widget.TextView;
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

    
    
    private IPlayerServiceCallback mCallback = new IPlayerServiceCallback.Stub() {

		@Override
		public void stringChanged(int what, String value) throws RemoteException {
			Log.v(TAG, String.format("%d is now %s", what, value));
			switch(what) {
			case DroidSoundPlugin.INFO_TITLE:
				title = value;
				titleTextView.setText(title);
				break;
			}
		}

		@Override
		public void intChanged(int what, int value) throws RemoteException {
			Log.v(TAG, String.format("%d is now %d", what, value));
			switch(what) {
			case DroidSoundPlugin.INFO_LENGTH:
				songLength = value / 1000;
				seekBar.setMax(songLength);
				seekBar.setProgress(0);
				lengthTextView.setText(String.format("%02d:%02d", songLength/60, songLength % 60));
				break;
			case PlayerService.SONG_POS:
				int sec = value/1000;
				Log.v(TAG, "Music at " + sec);				
				seekBar.setProgress(sec);
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
    			modName = mService.getStringValue(PlayerService.SONG_FILENAME);
    			songLength = mService.getIntValue(PlayerService.SONG_LENGTH) / 1000;
    			lengthTextView.setText(String.format("%02d:%02d", songLength/60, songLength % 60));
    			int sec = mService.getIntValue(PlayerService.SONG_POS) / 1000;
				seekBar.setProgress(sec);
				posTextView.setText(String.format("%02d:%02d", sec/60, sec % 60));
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

		
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle state) {
        super.onCreate(state);
        setContentView(R.layout.main);
        
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
		
		pauseButton = (ImageButton) findViewById(R.id.pauseButton);		
		pauseButton.setOnClickListener(new OnClickListener() {			
			private boolean playPause;

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
				try {
					if(to >= 0) {
						mService.seekTo(to * 1000);
						to = -1;
						lengthTextView.setText(String.format("%02d:%02d", songLength/60, songLength % 60));
					}
				} catch (RemoteException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			
			@Override
			public void onStartTrackingTouch(SeekBar seekBar) {
			}
			
			@Override
			public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
				if(fromUser) {
					to = progress;
					lengthTextView.setText(String.format("%02d:%02d", to/60, to % 60));
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

        Intent i = new Intent(this, PlayerService.class);
        startService(i);
        bindService(i, mConnection, Context.BIND_AUTO_CREATE);
    }

    boolean skip(int i) {
    	
    	if(modName == null)
    		return false;
    	
    	File modDir = new File(modName).getParentFile();    	
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
		unbindService(mConnection);
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
 	
 	@Override
 	protected void onActivityResult(int requestCode, int resultCode, Intent data) {

 		Log.v(TAG, "Result " + resultCode);

 		if(resultCode != RESULT_CANCELED) {
 			Bundle b = data.getExtras();
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
 		}
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
		menu.add(0, 10, 0, "Settings").setIcon(android.R.drawable.ic_menu_preferences);
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
		} //else
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