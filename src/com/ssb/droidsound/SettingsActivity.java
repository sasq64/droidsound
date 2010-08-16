package com.ssb.droidsound;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.content.DialogInterface.OnMultiChoiceClickListener;
import android.net.Uri;
import android.os.Bundle;
import android.os.FileObserver;
import android.preference.CheckBoxPreference;
import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.preference.PreferenceManager;
import android.preference.PreferenceScreen;
import android.util.Log;
import android.view.KeyEvent;
import android.widget.EditText;

public class SettingsActivity extends PreferenceActivity {

	protected static final String TAG = SettingsActivity.class.getSimpleName();
	private SongDatabase songDatabase;
	private boolean doFullScan;
	private SharedPreferences prefs;
	private String modsDir;
/*
	private List<String> downloadList = new ArrayList<String>();
	private FileObserver fo;
	private BroadcastReceiver receiver;
	
	private class Downloader implements Preference.OnPreferenceChangeListener {

		private String url;
		private List<String> dlList;
		
		public Downloader(String s, List<String> list) {
			url = s;
			dlList = list;
		}
		@Override
		public boolean onPreferenceChange(Preference preference, Object v) {
			if((Boolean)v) {
				dlList.add(url);
			} else {
				dlList.remove(url);
				songDatabase.cancelDownload(url);
			}
			return true;
		}
	};
	
	private Map<String, CheckBoxPreference> dlPrefs;
	
	private void addDownloadable(String url, String name, int description) {
		
		PreferenceScreen screen = (PreferenceScreen) findPreference("download_prefs");
		
		CheckBoxPreference pref = new CheckBoxPreference(this);
		
		pref.setTitle(name);
		pref.setSummaryOff(description);
		
		String wbd = getString(R.string.will_be_downloaded);
		String idl = getString(R.string.is_downloading);
		String dl = getString(R.string.is_downloaded);
		String iq = getString(R.string.is_queued);
		
		String basename = new File(url).getName();
		
		File f = new File(modsDir, basename);
		File ft = new File(modsDir, basename + ".temp");

		if(f.exists()) {
			pref.setChecked(true);
			pref.setEnabled(false);
			pref.setSummaryOn(name + dl);
			pref.setEnabled(false);
		} else
		if(songDatabase.isQueued(url)) {
			pref.setChecked(true);
			pref.setSummaryOn(name + idl);
			pref.setEnabled(true);
			if(ft.exists()) {
				pref.setSummaryOn(name + iq);
			} else {
				pref.setSummaryOn(name + idl);
			}
				
		} else {
			pref.setSummaryOn(name + wbd);			
			pref.setChecked(false);
			pref.setEnabled(true);
			pref.setOnPreferenceChangeListener(new Downloader(url, downloadList));
		}
			
		screen.addPreference(pref);
		dlPrefs.put(basename + ".temp", pref);
	}
*/
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);		
		addPreferencesFromResource(R.layout.preferences);
		
		songDatabase = PlayerActivity.songDatabase;

		prefs = PreferenceManager.getDefaultSharedPreferences(this);
		modsDir = prefs.getString("modsDir", null);
/*
		fo = new FileObserver(modsDir) {			
			@Override
			public void onEvent(int event, String path) {
				Log.v(TAG, String.format("FILEOBSERVE %d %s", event, path));
			}
		};
		fo.startWatching(); */
		
		Preference pref = findPreference("rescan_pref");
		pref.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
			@Override
			public boolean onPreferenceClick(Preference preference) {
				Log.v(TAG, "Rescan database");
				showDialog(R.string.scan_db);
				return false;
			}
		});
		
		pref = findPreference("about_pref");
		pref.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
			@Override
			public boolean onPreferenceClick(Preference preference) {
				showDialog(R.string.about_droidsound);
				return false;
			}
		});
		
		pref = findPreference("download_link");
		pref.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
			@Override
			public boolean onPreferenceClick(Preference preference) {
				Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://swimsuitboys.com/droidsound/dl/"));
				startActivity(intent);
				return true;
			}
		});	
		
/*
		dlPrefs = new HashMap<String, CheckBoxPreference>();
		
		addDownloadable("http://swimsuitboys.com/droidsound/dl/C64Music.zip", "HVSC", R.string.hvsc_desc);
		addDownloadable("http://swimsuitboys.com/droidsound/dl/csdb.dump.zip", "CSDb", R.string.csdb_desc);
		addDownloadable("http://swimsuitboys.com/droidsound/dl/MODS.zip", "Test mods", R.string.testmods_desc);
		IntentFilter filter = new IntentFilter();
		filter.addAction("com.sddb.droidsound.DOWNLOAD");
		filter.addAction("com.sddb.droidsound.DOWNLOAD_DONE");
		
		receiver = new BroadcastReceiver() {
			@Override
			public void onReceive(Context context, Intent intent) {
				String path = intent.getStringExtra("PATH");
				Log.v(TAG, path + " downloaded");
				String baseName = new File(path).getName();
				CheckBoxPreference cpref = dlPrefs.get(baseName);
				if(cpref != null) {
					Log.v(TAG, baseName + " found");
					if(intent.getAction().equals("com.sddb.droidsound.DOWNLOAD")) {
						int bytes = intent.getIntExtra("BYTES", 0);
						int size = intent.getIntExtra("SIZE", 1);
						cpref.setSummaryOn(String.format("%d%%", (long)bytes * 100 / size));
					} else
					if(intent.getAction().equals("com.sddb.droidsound.DOWNLOAD_DONE")) {
						cpref.setSummaryOn(String.format("Downloaded"));
					}
				}
			}
		};
		
		registerReceiver(receiver, filter);		*/
	}
	
	//@Override
	//public boolean onKeyDown(int keyCode, KeyEvent event) {
	//	return super.onKeyDown(keyCode, event);
	//}
	
	@Override
	protected void onPause() {
		super.onPause();
		/* if(downloadList.size() > 0) {
			for(String s : downloadList) {
				songDatabase.download(s);
			}
			downloadList.clear();
		} */
	}
	
	@Override
	protected void onDestroy() {
		super.onDestroy();
		// unregisterReceiver(receiver);
	}
	
	@Override
	protected Dialog onCreateDialog(int id) {
		
		AlertDialog.Builder builder = new AlertDialog.Builder(this);
		
		switch(id) {		
		case R.string.recreate_confirm:
			builder.setMessage(id);
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					songDatabase.rescan(modsDir);
					finish();
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}				
			});
			break;
		case R.string.scan_db:
			doFullScan = false;
			builder.setTitle(id);
			builder.setMultiChoiceItems(R.array.scan_opts, null, new OnMultiChoiceClickListener() {				
				@Override
				public void onClick(DialogInterface dialog, int which, boolean isChecked) {
					Log.v(TAG, String.format("%d %s", which, String.valueOf(isChecked)));
					doFullScan = isChecked;
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}				
			});
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dialog, int id) {
					dialog.cancel();
					if(doFullScan) {
						showDialog(R.string.recreate_confirm);
					} else {
						songDatabase.scan(true, modsDir);
						finish();
					}
				}
			});
			break;
		default:
			builder.setMessage(id);
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dialog, int id) {
					dialog.cancel();
				}
			});
			break;
		}

		AlertDialog alert = builder.create();
		return alert;
	}

	
}
