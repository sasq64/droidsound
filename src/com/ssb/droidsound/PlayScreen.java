package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.lang.ref.WeakReference;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

import android.app.Activity;
import android.content.Context;
import android.os.Environment;
import android.os.FileObserver;
import android.os.Handler;
import android.os.Message;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.view.ViewGroup;
import android.webkit.WebView;
import android.widget.ImageButton;
import android.widget.SeekBar;
import android.widget.TextView;

import com.floreysoft.jmte.Engine;
import com.ssb.droidsound.service.PlayerService;
import com.ssb.droidsound.utils.Log;

public class PlayScreen {
	private static final String TAG = PlayScreen.class.getSimpleName();

	private static String[] repnames = { "CONT", "HOLD", "REPT", "CS", "RS" };

	private ViewGroup parent;
	private PlayerServiceConnection player;
	private PlayState state;

	private ImageButton playButton;
	private ImageButton backButton;
	private ImageButton fwdButton;
	private ImageButton stopButton;

	private TextView songSecondsText;
	private TextView songTotalText;
	private TextView songSubtunesText;
	private SeekBar songSeeker;

	private TextView shuffleText;
	private TextView repeatText;
	private TextView plusText;

	private WebView infoText;


	private Activity activity;


	
	private Map<String, Object> variables = new HashMap<String, Object>();

	private Engine engine;

	private String infoHtml;

	private String empty = "<html><body style=\"background-color: #000000;\"></body></body>";

	private File htmlDir;
	private Map<String, String> templates = new HashMap<String, String>();

	private FileObserver observer;

	private String currentPluginName;

	private FileObserver observer2;
	
	private class MyHandler extends Handler {

		private WeakReference<PlayScreen> psRef;

		public MyHandler(PlayScreen ps) {
			psRef = new WeakReference<PlayScreen>(ps);
		}

		@Override
		public void handleMessage(Message msg) {
			PlayScreen ps = psRef.get();
			ps.updateInfo();
			// switch (msg.what) {
			// }
		}
	};
	
	public View getView() {
		return parent;
	}

	public PlayScreen(PlayState st, PlayerServiceConnection plr, Activity act) {
		player = plr;
		state = st;
		//parent = ps;
		activity = act;
		
		LayoutInflater inflater = (LayoutInflater)activity.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
		parent = (ViewGroup) inflater.inflate(R.layout.info, null);

	
		stopButton = (ImageButton) parent.findViewById(R.id.stop_button);
		playButton = (ImageButton) parent.findViewById(R.id.play_button);
		backButton = (ImageButton) parent.findViewById(R.id.back_button);
		fwdButton = (ImageButton) parent.findViewById(R.id.fwd_button);

		songSecondsText = (TextView) parent.findViewById(R.id.seconds_text);
		songTotalText = (TextView) parent.findViewById(R.id.total_text);
		songSubtunesText = (TextView) parent.findViewById(R.id.songs_text);
		songSeeker = (SeekBar) parent.findViewById(R.id.song_seek);

		shuffleText = (TextView) parent.findViewById(R.id.shuffle_text);
		repeatText = (TextView) parent.findViewById(R.id.repeat_text);
		plusText = (TextView) parent.findViewById(R.id.plus_text);
		
		infoText = (WebView) parent.findViewById(R.id.web_view);
		
		infoText.loadData(empty, "text/html", "utf-8");
		
		htmlDir = new File(Environment.getExternalStorageDirectory(), "droidsound/html");
		if(!htmlDir.exists()) {
			htmlDir.mkdir();
			new File(htmlDir, "templates").mkdir();
			new File(htmlDir, "images").mkdir();
		}

		final Handler handler = new MyHandler(this);

		
		observer = new FileObserver(htmlDir.getPath(), FileObserver.MODIFY | FileObserver.MOVED_TO | FileObserver.CREATE) {			
			@Override
			public void onEvent(int event, String path) {
				updateHtml();
				Message msg = handler.obtainMessage(0);
				handler.sendMessage(msg);

			}
		};
		observer.startWatching();
		observer2 = new FileObserver(new File(htmlDir, "templates").getPath(), FileObserver.MODIFY | FileObserver.MOVED_TO | FileObserver.CREATE) {			
			@Override
			public void onEvent(int event, String path) {
				updateHtml();
				Message msg = handler.obtainMessage(0);
				handler.sendMessage(msg);

			}
		};
		observer2.startWatching();
		updateHtml();
		
		
		
		
        /*WebViewClient client = new WebViewClient() {
        	@Override
        	public WebResourceResponse shouldInterceptRequest(WebView view, String url) {
        		Log.d(TAG, "WANT TO LOAD " + url);
        		return super.shouldInterceptRequest(view, url);
        	}
        };
        infoText.setWebViewClient(client); */

		
		shuffleText.setText(state.shuffleSongs ? "RND" : "SEQ");
		
		engine = new Engine();

		stopButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				player.stop();
			}
		});
		playButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {

				if(state.songState == 1) {
					player.playPause(false);
				} else {
					player.playPause(true);
				}
			}
		});

		backButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				if(state.subTune == 0 || state.subTuneCount == 0) {
					player.playPrev();
				} else {
					state.subTune -= 1;
					player.setSubSong(state.subTune);
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
				Log.d(TAG, "NEXT %d %d", state.subTune, state.subTuneCount);
				if((state.subTune + 1) < state.subTuneCount) {
					state.subTune += 1;
					player.setSubSong(state.subTune);
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
		
		songSeeker.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
			@Override
			public void onStopTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				Log.d(TAG, "Stop tracking");
				player.seekTo(state.songLength * seekBar.getProgress() * 10);
				state.seekingSong = 5;
			}

			@Override
			public void onStartTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				Log.d(TAG, "Start tracking");
				state.seekingSong = 5;
			}

			@Override
			public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
				if(fromUser) {
					// Log.d(TAG, "Changed %d", progress);
					int pos = state.songLength * seekBar.getProgress() / 100;
					songSecondsText.setText(String.format("%02d:%02d", pos / 60, pos % 60));
					state.seekingSong = 5;
				}
			}
		});
		
		shuffleText.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				state.shuffleSongs = !state.shuffleSongs;
				player.setOption(PlayerService.OPTION_PLAYBACK_ORDER, state.shuffleSongs ? "R" : "S");
				shuffleText.setText(state.shuffleSongs ? "RND" : "SEQ");
			}
		});

		repeatText.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				// shuffleSongs = !shuffleSongs;
				if(state.songRepeat == 0) {
					state.songRepeat = 1;
				} else {
					state.songRepeat = 0;
				}
				player.setOption(PlayerService.OPTION_REPEATMODE, Integer.toString(state.songRepeat));
			}
		});

		plusText.setOnClickListener(new OnClickListener() {
			@SuppressWarnings("deprecation")
			@Override
			public void onClick(View v) {

				if(state.songFile != null) {
					//operationFile = songFile.getFile();
					state.operationSong = new SongFile(state.songFile);
					//operationSong.setSubTune(subTune);
					
					//operationTune = subTune;
					state.operationTitle = null;
					state.operationTuneCount = state.subTuneCount;
					Log.d(TAG, "%s - %s ADD", state.songTitle != null ? state.songTitle : "null", state.subtuneTitle != null ? state.subtuneTitle : "null");
					if(state.songTitle != null && state.subtuneTitle != null) {
						// operationTitle = songTitle + " - " + subtuneTitle;
						state.operationTitle = state.subtuneTitle + " (" + state.songTitle + ")";
					}
					//operationSong.setTitle(operationTitle);
					activity.showDialog(R.string.add_to_plist);
				}
			}
		});




	}

	public void intChanged(int what, int value) {
		switch(what) {
		case PlayerService.SONG_STATE:
			Log.d(TAG, "State now %d", value);
			state.songState = value;
			if(value == 1) {
				playButton.setBackgroundResource(R.drawable.pause_button);
			} else {
				playButton.setBackgroundResource(R.drawable.play_button);
				if(value == 0) {
					// songTitleText.setText("");
					// songComposerText.setText("");
					// songCopyrightText.setText("");
					// songSubtunesText.setText("[00/00]");
					// songTotalText.setText("00:00");
					// songSecondsText.setText("00:00");
				}
			}
			break;
		case PlayerService.SONG_BUFFERING:
			if(value > 0) {
				songSubtunesText.setText(String.format("%02d:%02d", value / 1000 / 60, (value/1000) % 60));
			}
			break;
		case PlayerService.SONG_LENGTH:
			if(value < 0) {
				// TODO: Hide length
				value = 0;
				songTotalText.setVisibility(View.GONE);
			} else {
				songTotalText.setVisibility(View.VISIBLE);
			}
			state.songLength = value / 1000;
			Log.d(TAG, "Songlength %02d:%02d", state.songLength / 60, state.songLength % 60);
			songTotalText.setText(String.format("%02d:%02d", state.songLength / 60, state.songLength % 60));			
			//songSeeker.setProgress(0);
			break;
		case PlayerService.SONG_POS:
			if(state.seekingSong == 0) {
				state.songPos = value / 1000;
				songSecondsText.setText(String.format("%02d:%02d", state.songPos / 60, state.songPos % 60));
				if(state.songLength > 0) {
					int percent = 100 * state.songPos / state.songLength;
					if(percent > 100) percent = 100;
					songSeeker.setProgress(percent);
				} else {
					songSeeker.setProgress(0);
				}
			} else
				state.seekingSong--;

			break;
		case PlayerService.SONG_SUBSONG:
			if(value >= 0) {
				state.subTune = value;
				songSubtunesText.setText(String.format("[%02d/%02d]", state.subTune + 1, state.subTuneCount));
			}
			break;
		case PlayerService.SONG_TOTALSONGS:
			state.subTuneCount = value;
			songSubtunesText.setText(String.format("[%02d/%02d]", state.subTune + 1, state.subTuneCount));
			break;
		case PlayerService.SONG_FLAGS:
			songSeeker.setEnabled((value & 1) != 0);
			break;
		case PlayerService.SONG_REPEAT:
			state.songRepeat = value;
			repeatText.setText(repnames[value]);
			if(value == 1) {
				repeatText.setTextColor(0xff80c0ff);
			} else {
				repeatText.setTextColor(0xff80ffc0);
			}

			break;
		}
	}
	
	private String readFile(File f) {
		FileInputStream is;
		String contents = null;
		try {
			is = new FileInputStream(f);
			byte [] data = new byte [is.available()];        
	        is.read(data);
	        is.close();
	        contents = new String(data, "ISO8859_1");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return contents;
	}
	
	public void updateHtml() {
		
		File tmplDir = new File(htmlDir, "templates");
		if(!tmplDir.exists())
			tmplDir.mkdirs();
		for(File f : tmplDir.listFiles()) {
			String parts[] = f.getName().split("\\.");
			if(parts.length == 2 && parts[1].toLowerCase().equals("html")) {
				String html = readFile(f);
				templates.put(parts[0].toUpperCase(), html);
			}
		}		
	}
	

	@SuppressWarnings("unused")
	public void stringChanged(int what, String value) {
		switch(what) {
		case PlayerService.SONG_SOURCE:
			Log.d(TAG, "SOURCE IS " + value);
			state.songSource = value;
			//if(value != null && value.length() > 0) {
			//	plinfoText.setText(value);
			//} else 
			//	plinfoText.setText("");
			break;
		case PlayerService.SONG_TITLE:
			Log.d(TAG, "############################## Title is %s", value);
			state.songTitle = value;
			state.subtuneTitle = null;
		case PlayerService.SONG_DETAILS:
			state.songDetails = player.getSongInfo();
			
			Log.d(TAG, "#### Got %d details", state.songDetails != null ? state.songDetails.size() : -1);
			
			variables.clear();
			//File imageDir = new File(Environment.getExternalStorageDirectory(), "droidsound/images");
			variables.put("IMAGEPATH", "file://" + htmlDir.getPath() + "/");
			variables.put("FONTPATH", "file://" + htmlDir.getPath() + "/");
			if(state.songDetails != null) {
				
				for(Entry<String, Object> e : state.songDetails.entrySet()) {
					
					Object val = e.getValue();
					
					if(val instanceof String[]) {
						// Transform String array into object array with extra fields
						Object[] newArray = new Object [ ((String[])val).length ];
						
						int counter = 0;
						for(final String s : (String[])val) {						
							counter++;
							final int idx = counter;
							newArray[counter-1] = new Object() {									
								public String text = s;
								public int index = idx;
								public String index2 = String.format("%02d", idx);;
							};							
						}
						
						variables.put(e.getKey(), newArray);
					} else					
						variables.put(e.getKey(), e.getValue());
				}
				
			}
			
	        InputStream is;
			try {
				is = activity.getAssets().open("info.def.html");
				byte [] data = new byte [is.available()];        
		        is.read(data);
		        is.close();
		        infoHtml = new String(data, "ISO8859_1");
			} catch (IOException e) {
				e.printStackTrace();
			}        
			
			updateInfo();			
			
			infoText.scrollTo(0, 0);
			update();
			break;
			
		case PlayerService.SONG_SUBTUNE_TITLE:
			Log.d(TAG, "############################## Subtunetitle is %s", value);
			state.subtuneTitle = value;
			if(state.subtuneTitle != null && state.subtuneTitle.length() == 0) state.subtuneTitle = null;
			update();
			break;
		case PlayerService.SONG_SUBTUNE_AUTHOR:
			Log.d(TAG, "############################## Author is %s", value);
			state.subtuneAuthor = value;
			update();
			break;
		case PlayerService.SONG_AUTHOR:
			// songComposerText.setText(value);
			state.songComposer = value;
			update();
			break;
		case PlayerService.SONG_COPYRIGHT:
			variables.put("copyright", value);			
			// songCopyrightText.setText(value);
			break;

		}
	}
	
	void updateInfo() {
		
		if(variables.containsKey("plugin"))
			currentPluginName = ((String)variables.get("plugin")).toUpperCase();
		else
			currentPluginName = "DEF";
		
		String html = templates.get(currentPluginName);
		if(html == null)
			html = infoHtml;
		
		String output = engine.transform(html, variables);		
		infoText.loadDataWithBaseURL("", output, "text/html", "utf-8", null);
	}
	
	void update() {
		/*if(state.songTitle != null) {
			if(state.subtuneTitle != null && state.subtuneTitle.length() > 0) {
				titleText.setText(state.subtuneTitle + " (" + state.songTitle + ")");
			} else {
				titleText.setText(state.songTitle);
			}
		}
		if(state.subtuneAuthor != null && state.subtuneAuthor.length() > 0) {
			subtitleText.setText(state.subtuneAuthor);
		} else if(state.songComposer != null) {
			subtitleText.setText(state.songComposer);
		} */
		
		variables.put("title", state.songTitle);
		variables.put("subtune_title", state.subtuneTitle);
		variables.put("composer", state.songComposer);
		variables.put("subtune_composer", state.subtuneAuthor);
		variables.put("song_source", state.songSource);
		
		updateInfo();
	}
	
}
