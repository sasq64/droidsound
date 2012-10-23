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

import android.annotation.SuppressLint;
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
import com.ssb.droidsound.service.SongMeta;
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
	private File templateDir;
	private File dataDir;

	private Map<String, String> templates = new HashMap<String, String>();

	private FileObserver observer;

	private String currentPluginName;


	//private FileObserver observer2;
	
	private static class MyHandler extends Handler {

		private WeakReference<PlayScreen> psRef;

		public MyHandler(PlayScreen ps) {
			psRef = new WeakReference<PlayScreen>(ps);
		}

		@Override
		public void handleMessage(Message msg) {
			PlayScreen ps = psRef.get();
			ps.update();
		}
	};
	
	/*private static class SongInfo {
		public String title;
		public String composer;
	}; */
	
	@SuppressWarnings("unused")
	private static class VarJS {
		private Map<String, Object> map;

		public VarJS(Map<String, Object> map) {
			this.map = map;
		}
		
		public String getString(String what) {
			return (String) map.get(what);
		}
		
	}
	
//	private SongInfo songInfo = new SongInfo();
	
	public View getView() {
		return parent;
	}

	@SuppressLint("SetJavaScriptEnabled")
	public PlayScreen(PlayState st, PlayerServiceConnection plr, Activity act) {
		player = plr;
		state = st;
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
		infoText.getSettings().setJavaScriptEnabled(true);		
		infoText.addJavascriptInterface(new VarJS(variables), "info");
		//infoText.addJavascriptInterface(songInfo, "info");
		

		infoText.loadData(empty, "text/html", "utf-8");
		
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
		
		htmlDir = new File(Environment.getExternalStorageDirectory(), "droidsound/html");
		templateDir = new File(htmlDir, "templates");
		dataDir = new File(htmlDir, "data");
		if(!htmlDir.exists())
			htmlDir.mkdir();
		if(!templateDir.exists())
			templateDir.mkdir();
		if(!dataDir.exists())
			dataDir.mkdir();

		final Handler handler = new MyHandler(this);

		
		/*observer = new FileObserver(htmlDir.getPath(), FileObserver.MODIFY | FileObserver.MOVED_TO | FileObserver.CREATE) {			
			@Override
			public void onEvent(int event, String path) {
				updateHtml();
				Message msg = handler.obtainMessage(0);
				handler.sendMessage(msg);

			}
		};
		observer.startWatching(); */
		observer = new FileObserver(templateDir.getPath(), FileObserver.MODIFY | FileObserver.MOVED_TO | FileObserver.CREATE) {			
			@Override
			public void onEvent(int event, String path) {
				if(updateHtml()) {
					Message msg = handler.obtainMessage(0);
					handler.sendMessage(msg);
				}

			}
		};
		observer.startWatching();
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
	
	public void update(Map<String, Object> data, boolean newsong) {
		
		if(newsong || state.songDetails == null)
			state.songDetails = data;
		else
			state.songDetails.putAll(data);
		
		if(data.containsKey(SongMeta.STATE)) {
			state.songState = (Integer)data.get(SongMeta.STATE);
			
			Log.d(TAG, "State %d", state.songState);
			
			if(state.songState == 1) {
				playButton.setBackgroundResource(R.drawable.pause_button);
			} else {
				playButton.setBackgroundResource(R.drawable.play_button);
			}
		}
		if(data.containsKey(SongMeta.LENGTH)) {
			state.songLength = (Integer)data.get(SongMeta.LENGTH) / 1000;
			if(state.songLength < 0) {
				// TODO: Hide length
				state.songLength = 0;
				songTotalText.setVisibility(View.GONE);
			} else {
				songTotalText.setVisibility(View.VISIBLE);
			}
			Log.d(TAG, "Songlength %02d:%02d", state.songLength / 60, state.songLength % 60);
			songTotalText.setText(String.format("%02d:%02d", state.songLength / 60, state.songLength % 60));
		}
		if(data.containsKey(SongMeta.POSITION)) {
			int value = (Integer)data.get(SongMeta.POSITION) / 1000;
			if(state.seekingSong == 0) {
				state.songPos = value;
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
		}
		if(data.containsKey(SongMeta.BUFFERING)) {
			state.buffering = (Integer)data.get(SongMeta.BUFFERING);
			songSubtunesText.setText(String.format("%02d:%02d", state.buffering / 1000 / 60, (state.buffering/1000) % 60));
		}
		
		
		
		if(data.containsKey(SongMeta.TITLE)) {
			state.songTitle = (String) data.get(SongMeta.TITLE);
		}
		if(data.containsKey(SongMeta.SUBTUNE_TITLE)) {
			state.subtuneTitle = (String) data.get(SongMeta.SUBTUNE_TITLE);
		}
		if(data.containsKey(SongMeta.SUBTUNE_COMPOSER)) {
			state.subtuneAuthor = (String) data.get(SongMeta.SUBTUNE_COMPOSER);
		}
		if(data.containsKey(SongMeta.COMPOSER)) {
			state.songComposer = (String) data.get(SongMeta.COMPOSER);
		}
		if(data.containsKey(SongMeta.TOTAL_SUBTUNES)) {
			state.subTuneCount = (Integer) data.get(SongMeta.TOTAL_SUBTUNES);
		}
		if(data.containsKey(SongMeta.SOURCE)) {
			state.songSource = (String) data.get(SongMeta.SOURCE);
		}
		
		if(newsong)
			infoText.scrollTo(0, 0);


		update();
	}

	/*
	public void intChanged(int what, int value) {
		switch(what) {
		case -1:
			update();
			break;
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
	} */
	
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
	
	public boolean updateHtml() {
		
		if(!templateDir.exists())
			templateDir.mkdirs();
		boolean changed = false;
		for(File f : templateDir.listFiles()) {
			String parts[] = f.getName().split("\\.");
			if(parts.length == 2 && parts[1].toLowerCase().equals("html")) {
				String html = readFile(f);
				String what = parts[0].toUpperCase();
				String oldHtml = templates.get(what);
				if(oldHtml == null || !oldHtml.equals(html)) {
					templates.put(what, html);
					changed = true;
				}
			}
		}
		return changed;
	}
	
	
/*
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
			infoText.scrollTo(0, 0);
			break;
			
		case PlayerService.SONG_SUBTUNE_TITLE:
			Log.d(TAG, "############################## Subtunetitle is %s", value);
			state.subtuneTitle = value;
			if(state.subtuneTitle != null && state.subtuneTitle.length() == 0) state.subtuneTitle = null;
			break;
		case PlayerService.SONG_SUBTUNE_AUTHOR:
			Log.d(TAG, "############################## Author is %s", value);
			state.subtuneAuthor = value;
			break;
		case PlayerService.SONG_AUTHOR:
			// songComposerText.setText(value);
			state.songComposer = value;
			break;
		case PlayerService.SONG_COPYRIGHT:
			variables.put("copyright", value);			
			// songCopyrightText.setText(value);
			break;

		}
	} */
		
	@SuppressWarnings("unused")
	private void update() {
		
		variables.clear();
		variables.put("DATAPATH", "file://" + dataDir.getPath() + "/");
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

		variables.put("title", state.songTitle);
		variables.put("subtune_title", state.subtuneTitle);
		variables.put("composer", state.songComposer);
		variables.put("subtune_composer", state.subtuneAuthor);
		variables.put("song_source", state.songSource);
		
		//myWebView.loadUrl("javascript:testEcho('Hello World!')");
		
		if(variables.containsKey("plugin"))
			currentPluginName = ((String)variables.get("plugin")).toUpperCase();
		else
			currentPluginName = "DEF";
		
		
		if(variables.containsKey("webpage")) {
			String page = (String) variables.get("webpage");
			infoText.loadUrl(page);
		} else {
			
			String html = templates.get(currentPluginName);
			if(html == null)
				html = infoHtml;
			
			String output = engine.transform(html, variables);
			infoText.loadDataWithBaseURL("", output, "text/html", "utf-8", null);
		}
	}
	
}
