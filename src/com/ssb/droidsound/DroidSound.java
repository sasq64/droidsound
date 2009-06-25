package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

import android.app.Activity;
import android.content.Intent;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.MediaController;
import android.widget.TextView;

public class DroidSound extends Activity implements OnClickListener {
	
	private static final String TAG = "Test";
	private MediaController mediaCtrl;
	private Player player;
	private Thread playerThread;
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.main);
        
        LinearLayout v = new LinearLayout(this);
        setContentView(v);

        Button b = new Button(this);
        b.setText("Play");
        b.setOnClickListener(this);
        v.addView(b);
        
        b = new Button(this);
        b.setText("Stop!");
		b.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				player.stop();
				finish();
			}
		});
		v.addView(b);
               
        b = new Button(this);
        b.setText("List!");
		b.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				Intent i = new Intent(DroidSound.this, PlayListActivity.class);
				startActivityForResult(i, 0);
			}
		});

		v.addView(b);

        AudioManager audioManager = (AudioManager) getSystemService(AUDIO_SERVICE);
        
		Log.v(TAG, "Creating player from thread " + Thread.currentThread().getId());
        
        player = new Player(audioManager);
        playerThread = new Thread(player);
        playerThread.start();
    }

 	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
 		
 		player.playMod("madness.mod");
 		Log.v(TAG, "Playing music");
	}
 	
 	@Override
 	protected void onActivityResult(int requestCode, int resultCode, Intent data) {

 		Log.v(TAG, "Result " + resultCode);

 		if(resultCode != RESULT_CANCELED) {
 			Bundle b = data.getExtras();
 			String name = b.getString("fileName");
 			Log.v(TAG, "Playing file " + name);
 			player.playMod(name);
 		}
 	}
}