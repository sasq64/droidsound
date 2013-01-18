package com.ssb.droidsound;

import java.io.File;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.ContentValues;
import android.content.Context;
import android.content.DialogInterface;
import android.media.RingtoneManager;
import android.net.Uri;
import android.os.Environment;
import android.provider.MediaStore;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import com.ssb.droidsound.utils.Log;

public class RingToneCreator {
	private static final String TAG = RingToneCreator.class.getSimpleName();
	
	public static class RingTone {

		public boolean HQ = false;
		public String name = "Droidsound Ringtone";
		public boolean setDefault = true;
		public int seconds = 30;

	}

	public static interface Callback {
		void createWav(RingTone rt);
	}
	
	private Activity activity;
	private TextView toneNameText;
	private RingTone ringTone;
	private TextView toneLenText;
	private Callback createCallback;
	
	private int toneLength;

	public void onCreateWav(Callback cb) {
		createCallback = cb;
	}
	
	public RingToneCreator(Activity a) {
		activity = a;
		ringTone = new RingTone();
	}
	
	
	public AlertDialog createDialog() {
		int id = R.string.make_wav;
		AlertDialog.Builder builder = new AlertDialog.Builder(activity);
		//Dialog dialog = new Dialog(this);
		//dialog.setContentView(R.layout.ringtone_dialog);
		//dialog.setTitle(id);
		final String [] progressNames = new String [] { "0:10", "0:20", "0:30", "1:00", "5:00", "10:00" };
		LayoutInflater inflater = (LayoutInflater) activity.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
		View dialog = inflater.inflate(R.layout.ringtone_dialog, null);
		builder.setView(dialog);			
		builder.setTitle(id);
		
		toneNameText = (TextView) dialog.findViewById(R.id.tone_name);
		toneNameText.setText(ringTone.name);
		
		CheckBox hqCheck = (CheckBox) dialog.findViewById(R.id.tone_hq);
		hqCheck.setChecked(ringTone.HQ);
		hqCheck.setOnCheckedChangeListener(new CheckBox.OnCheckedChangeListener() {
			@Override
			public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
				ringTone.HQ = isChecked;
			}
		});
		CheckBox setCheck = (CheckBox) dialog.findViewById(R.id.tone_set);
		setCheck.setChecked(ringTone.setDefault);
		setCheck.setOnCheckedChangeListener(new CheckBox.OnCheckedChangeListener() {
			@Override
			public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
				ringTone.setDefault = isChecked;
			}
		});
		
		toneLength = (ringTone.seconds / 10) - 1;
		if(toneLength > 30)
			toneLength = 5;
		else if(toneLength > 6)
			toneLength = 4;
		else if(toneLength > 3)
			toneLength = 3;
		
		toneLenText =  (TextView) dialog.findViewById(R.id.tone_lentext);
		toneLenText.setText(progressNames[toneLength]);
		SeekBar seekBar = (SeekBar) dialog.findViewById(R.id.tone_length);
		seekBar.setProgress(toneLength);
		seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
			@Override
			public void onStopTrackingTouch(SeekBar seekBar) {
			}
			
			@Override
			public void onStartTrackingTouch(SeekBar seekBar) {
			}
			
			@Override
			public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
				Log.d(TAG, "SEEK " + progress);
				toneLenText.setText(progressNames[progress]);	
				toneLength = progress;
			}
		});
		builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
			@Override
			public void onClick(DialogInterface dialog, int which) {
				File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
				File file = new File(droidDir, "ringtones");
				file.mkdir();
				int tl = toneLength;
				if(tl == 3) tl = 6;
				else if(tl == 4) tl = 6*5;
				else if(tl == 5) tl = 6*10;
				else tl += 1;
				ringTone.seconds = tl * 10;//30000;
				ringTone.name = (String) toneNameText.getText().toString();
				
				/*file = new File(file, ringTone.toneName + ".wav"); 
				int flags = 0;
				if(ringTone.HQ) flags |= 2;
				player.dumpWav(operationSong.getPath(), file.getPath(), dumpingWav, flags); */
				
				createCallback.createWav(ringTone);
				
			}
		});
		builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
			@Override
			public void onClick(DialogInterface dialog, int which) {
				dialog.cancel();
			}
		});
		AlertDialog alert = builder.create();
		return alert;
	}

	public void save(String value) {
		
		File f = new File(value);
		
		Log.d(TAG, "SETTING RINGTONE %s %d", value, f.length());
		
		ContentValues values = new ContentValues();
		values.put(MediaStore.MediaColumns.DATA, value);
		values.put(MediaStore.MediaColumns.TITLE, ringTone.name);
		values.put(MediaStore.MediaColumns.SIZE, f.length());
		values.put(MediaStore.MediaColumns.MIME_TYPE, "audio/x-wav");
		values.put(MediaStore.Audio.Media.ARTIST, "Droidsound");
		values.put(MediaStore.Audio.Media.DURATION, ringTone.seconds);
		values.put(MediaStore.Audio.Media.IS_RINGTONE, true);
		values.put(MediaStore.Audio.Media.IS_NOTIFICATION, false);
		values.put(MediaStore.Audio.Media.IS_ALARM, false);
		values.put(MediaStore.Audio.Media.IS_MUSIC, false);

		//Insert it into the database
		Uri uri = MediaStore.Audio.Media.getContentUriForPath(value);
		Uri newUri = null;
		Log.d(TAG, "URI " + uri.toString());
		try {
			int rows = activity.getContentResolver().delete(uri, String.format("%s = ?", MediaStore.MediaColumns.TITLE), new String [] { ringTone.name });
			Log.d(TAG, "ROWS " + rows);
		} catch (Exception e) {
			e.printStackTrace();
		}
		try {
			newUri = activity.getContentResolver().insert(uri, values);
		} catch (Exception e) {
			e.printStackTrace();
		}
		if(newUri == null) {
			int rows = activity.getContentResolver().update(uri, values, String.format("%s = ?", MediaStore.MediaColumns.TITLE), new String [] { ringTone.name });
			Log.d(TAG, "UPDATE ROWS " + rows);
			newUri = uri;
		} else {
			Log.d(TAG, "NEWURI " + uri.getPath());
		}
		Toast toast;
		if(ringTone.setDefault) {
			RingtoneManager.setActualDefaultRingtoneUri(activity, RingtoneManager.TYPE_RINGTONE, newUri);				
			toast = Toast.makeText(activity, R.string.ringtone_set, Toast.LENGTH_LONG);
		} else {
			toast = Toast.makeText(activity, R.string.ringtone_created, Toast.LENGTH_LONG);
		}
		toast.show();

	}
	
	
}
