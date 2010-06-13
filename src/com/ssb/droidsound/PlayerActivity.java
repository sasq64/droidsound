package com.ssb.droidsound;

import java.io.File;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageButton;
import android.widget.TextView;

public class PlayerActivity extends Activity implements PlayerServiceConnection.Callback {
	private static final String TAG = "DroidSound";

	private PlayerServiceConnection player = new PlayerServiceConnection();
	private ImageButton playButton;
	private ImageButton backButton;
	private ImageButton fwdButton;
	private ImageButton back2Button;
	private ImageButton fwd2Button;
	
	private TextView songTitleText;
	private TextView songComposerText;
	private TextView songDigitsText;
	private PlayListView playListView;

	private int songLength;
	private int songPos;
	private int subTune;
	private int subTuneCount;
	private boolean mIsPlaying = false;



	
	@Override
	public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        player.bindService(this, this);

        setContentView(R.layout.player);
        playButton = (ImageButton) findViewById(R.id.play_button);
        backButton = (ImageButton) findViewById(R.id.back_button);
        fwdButton = (ImageButton) findViewById(R.id.fwd_button);
        back2Button = (ImageButton) findViewById(R.id.sub_back_button);
        fwd2Button = (ImageButton) findViewById(R.id.sub_fwd_button);
        songTitleText = (TextView) findViewById(R.id.title_text);
        songComposerText = (TextView) findViewById(R.id.composer_text);
        songDigitsText = (TextView) findViewById(R.id.seconds_text);
        playListView = (PlayListView) findViewById(R.id.play_list);
        
        playButton.setOnClickListener(new OnClickListener() {			

			@Override
			public void onClick(View v) {
				mIsPlaying = !mIsPlaying;
				player.playPause(mIsPlaying);
				if(mIsPlaying) {
					playButton.setImageResource(R.drawable.mg_pause);
				} else {
					playButton.setImageResource(R.drawable.mg_forward);
				}
			}
		});
        
        backButton.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				player.playPrev();
			}
		});

        fwdButton.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				player.playNext();
			}
		});
        
        back2Button.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				if(subTune > 0) {
					player.setSubSong(subTune-1);
				}	
			}
		});
        
        songDigitsText.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				
			}
		});

        fwd2Button.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				if(subTune <= subTuneCount) {
					player.setSubSong(subTune+1);
				}
			}
		});
        
                
        File modDir = new File("/sdcard/MODS");
        
        playListView.setDirectory(modDir);
        playListView.setPlayer(player);
        /*
        HttpDownloader.downloadFiles(new HttpDownloader.Callback() {			
			@Override
			public void onDisplayProgress(int progress) {}

			@Override
			public void onDone() {
				playListView.rescan();
			}
		}, "/sdcard/MODS/", "http://swimmer.se/droidsound/mods.zip"); */
      
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
		}
	}

	@Override
	public void stringChanged(int what, String value) {
		switch(what) {
		case PlayerService.SONG_TITLE :
			songTitleText.setText(value);
			break;
		case PlayerService.SONG_AUTHOR :
			songComposerText.setText(value);
			break;
		}
	}
}
