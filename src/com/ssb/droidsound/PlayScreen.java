package com.ssb.droidsound;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;

import android.app.Activity;
import android.content.Context;
import android.os.Environment;
import android.text.Html;
import android.text.method.ScrollingMovementMethod;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.view.ViewGroup;
import android.webkit.WebResourceResponse;
import android.webkit.WebView;
import android.webkit.WebViewClient;
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

	//private TextView infoText;
	private WebView infoText;
	private TextView plinfoText;

	private Activity activity;

	private TextView titleText;

	private TextView subtitleText;
	
	private Map<String, Object> variables = new HashMap<String, Object>();
	
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
		
        /*WebViewClient client = new WebViewClient() {
        	@Override
        	public WebResourceResponse shouldInterceptRequest(WebView view, String url) {
        		Log.d(TAG, "WANT TO LOAD " + url);
        		return super.shouldInterceptRequest(view, url);
        	}
        };
        infoText.setWebViewClient(client); */

		
		//infoText.setMovementMethod(ScrollingMovementMethod.getInstance());
		plinfoText = (TextView) parent.findViewById(R.id.plinfo_text);

		titleText = (TextView) parent.findViewById(R.id.title_text);		
		subtitleText = (TextView) parent.findViewById(R.id.subtitle_text);
		
		shuffleText.setText(state.shuffleSongs ? "RND" : "SEQ");

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

	public void stringChanged(int what, String value) {
		switch(what) {
		case PlayerService.SONG_SOURCE:
			Log.d(TAG, "SOURCE IS " + value);
			if(value != null && value.length() > 0) {
				plinfoText.setText(value);
			} else 
				plinfoText.setText("");
			break;
		case PlayerService.SONG_TITLE:
			Log.d(TAG, "############################## Title is %s", value);
			state.songTitle = value;
			state.subtuneTitle = null;
		case PlayerService.SONG_DETAILS:
			state.songDetails = player.getSongInfo();
			
			Log.d(TAG, "#### Got %d details", state.songDetails != null ? state.songDetails.size() : -1);
			/*
			if(state.songDetails != null) {
				StringBuilder sb = new StringBuilder("<tt>");
				for(int i = 0; i < state.songDetails.length; i += 2) {
					// Log.d(TAG, songDetails[i]);
					// Log.d(TAG, songDetails[i+1]);
					sb.append("<font color='yellow'><b>").append(state.songDetails[i]).append("</font></b><br/>");
					if(state.songDetails[i].equals("Instruments")) {
						// sb.append(songDetails[i+1].replace("\n",
						// "<br/><font color='white'>"));
						String[] instr = state.songDetails[i + 1].split("\n");
						for(int j = 0; j < instr.length; j++) {
							sb.append(String.format("<font color='white'>%02d</font>: %s<br/>", j + 1, instr[j].replace(">", "&gt;")
									.replace("<", "&lt;")));
						}

					} else {
						sb.append(state.songDetails[i + 1].replace("\n", "<br/>"));
						sb.append("<br/>");
					}
				}
				sb.append("</tt>");
				//infoText.setText(Html.fromHtml(sb.toString()));
				infoText.loadData(sb.toString(), "text/html", "utf-8");
			} else {
				infoText.clearView();
			} */
			variables.clear();
			File imageDir = new File(Environment.getExternalStorageDirectory(), "droidsound/images");
			variables.put("IMAGEPATH", "file://" + imageDir.getPath() + "/");
			if(state.songDetails != null) {
				variables.putAll(state.songDetails);
				//for(int i=0; i<state.songDetails.length; i+=2) {
				//	variables.put(state.songDetails[i], state.songDetails[i+1]);
				//}
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
			// songCopyrightText.setText(value);
			break;

		}
	}
	
	void updateInfo() {
		
        InputStream is;
        String html = null;
        
        
		try {
			is = activity.getAssets().open("info.mod.html");
			byte [] data = new byte [is.available()];        
	        is.read(data);
	        is.close();
	        html = new String(data, "ISO8859_1");
		} catch (IOException e) {
			e.printStackTrace();
		}        
		
		Engine engine = new Engine();
		
		String output = engine.transform(html, variables);
		
		infoText.loadDataWithBaseURL("", output, "text/html", "utf-8", null);
	}
	
	void update() {
		if(state.songTitle != null) {
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
		}
	}
	
}
