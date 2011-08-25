package com.ssb.droidsound;

import java.util.List;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.preference.PreferenceCategory;
import android.preference.PreferenceGroup;
import android.preference.PreferenceManager;
import android.preference.PreferenceScreen;

import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.plugins.SidPlugin;
import com.ssb.droidsound.plugins.SidplayPlugin;
import com.ssb.droidsound.plugins.VICEPlugin;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsoundedit.R;

public final class SettingsActivity extends PreferenceActivity {

	private static final String TAG = SettingsActivity.class.getSimpleName();
	private SongDatabase songDatabase;
	private boolean doFullScan;
    private String modsDir;

final class AudiopPrefsListener implements Preference.OnPreferenceChangeListener {
		
		private final DroidSoundPlugin plugin;

		AudiopPrefsListener(DroidSoundPlugin pi) {
			plugin = pi;
		}
		
		@Override
		public boolean onPreferenceChange(Preference preference, Object newValue) {
			String k = preference.getKey();
			String k2 = k.substring(k.indexOf('.')+1);
			
			Log.d(TAG, "CHANGED " + k);
			
			if("SidPlugin.engine".equals(k)) {
				boolean isVice = ((String) newValue).startsWith("VICE");
				/* FIXME: Both sid model and resampling actually could be done
				 * also in sidplayplugin, but it's not currently supported. */
				findPreference("SidPlugin.filter_bias").setEnabled(isVice);
				findPreference("SidPlugin.sid_model").setEnabled(isVice);
				findPreference("SidPlugin.resampling").setEnabled(isVice);
			}
			
			if(newValue instanceof String) {
				try {
                    newValue = Integer.parseInt((String) newValue);
				} catch (NumberFormatException e) {
				}
			}
			
			plugin.setOption(k2, newValue);
			return true;
		}
	}
	

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);		
		addPreferencesFromResource(R.layout.preferences);
		
		songDatabase = PlayerActivity.songDatabase;

        SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(this);
		modsDir = prefs.getString("modsDir", null);
		
		String s = prefs.getString("SidPlugin.engine", null);
		Preference p = findPreference("SidPlugin.resampling");
		if(s.startsWith("VICE")) {
			p.setEnabled(true);
		} else {
			p.setEnabled(false);
		}
		
		Preference pref = findPreference("rescan_pref");
		pref.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
			@Override
			public boolean onPreferenceClick(Preference preference) {
				Log.d(TAG, "Rescan database");
				showDialog(R.string.scan_db);
				return true;
			}
		});
		
		pref = findPreference("help_pref");
		pref.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
			@Override
			public boolean onPreferenceClick(Preference preference) {
				startActivity(new Intent(SettingsActivity.this, HelpActivity.class));
				return true;
			}
		});
		pref = findPreference("download_local_link");
		pref.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
			@Override
			public boolean onPreferenceClick(Preference preference) {
				startActivity(new Intent(SettingsActivity.this, DownloadLocalActivity.class));
				return true;
			}
		});

		pref = findPreference("download_link");
		pref.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
			@Override
			public boolean onPreferenceClick(Preference preference) {
				
				PackageInfo pinfo = null;
				try {
					pinfo = getPackageManager().getPackageInfo(getPackageName(), 0);
				} catch (PackageManager.NameNotFoundException e) {}
				Intent intent;
				if(pinfo != null && pinfo.versionName.contains("beta")) {
					intent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://lioncash.uni.cc/droidsound/downloads.html"));
				} else {
					intent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://lioncash.uni.cc/droidsound/downloads.html"));
				}
				startActivity(intent);
				return true;
			}
		});	

		
		PackageInfo pinfo = null;
		try {
			pinfo = getPackageManager().getPackageInfo(getPackageName(), 0);
		} catch (PackageManager.NameNotFoundException e) {}

		List<DroidSoundPlugin> list = DroidSoundPlugin.createPluginList();
		String appName = getString(pinfo.applicationInfo.labelRes);
			
		PreferenceScreen aScreen = (PreferenceScreen) findPreference("audio_prefs");
		
		for(int i=0; i<aScreen.getPreferenceCount(); i++) {
			p = aScreen.getPreference(i);
			Log.d(TAG, "Pref '%s'", p.getKey());
			if(p instanceof PreferenceGroup) {
				PreferenceGroup pg = (PreferenceGroup) p;
				
				DroidSoundPlugin plugin = null;
				for(DroidSoundPlugin pl : list) {
					if(pl.getClass().getSimpleName().equals(pg.getKey())) {
						plugin = pl;
						break;
					}
				}
				if(plugin != null) {
					
					//String plname = plugin.getClass().getSimpleName();
					
					for(int j=0; j<pg.getPreferenceCount(); j++) {
						p = pg.getPreference(j);
						
						//p.setKey(plname + "." + p.getKey());
						
						Log.d(TAG, "Pref %s for %s", p.getKey(), plugin.getClass().getName());
						
						p.setOnPreferenceChangeListener(new AudiopPrefsListener(plugin));
					}
				}
			}
		}
		
		list.add(new SidplayPlugin());
		list.add(new VICEPlugin());
				
		PreferenceScreen abScreen = (PreferenceScreen) findPreference("about_prefs");

		if(abScreen != null) {
			PreferenceCategory pc = new PreferenceCategory(this);
			pc.setTitle("Droidsound");
			abScreen.addPreference(pc);
	
			p = new Preference(this);
			p.setTitle("Application");
			p.setSummary(String.format("%s v%s\n(C) 2010,2011 by Jonas Minnberg (Sasq)", appName, pinfo.versionName));		
			abScreen.addPreference(p);
	
			pc = new PreferenceCategory(this);
			pc.setTitle("Plugins");
			abScreen.addPreference(pc);
	
			for(DroidSoundPlugin pl : list) {
				if(pl instanceof SidPlugin) {					
				} else {
					p = new Preference(this);
					p.setTitle(pl.getClass().getSimpleName());
					p.setSummary(pl.getVersion());		
					abScreen.addPreference(p);
				}
			}
			
			pc = new PreferenceCategory(this);
			pc.setTitle("Other");
			abScreen.addPreference(pc);

			p = new Preference(this);
			p.setTitle("Icons");
			p.setSummary("G-Flat SVG by poptones");		
			abScreen.addPreference(p);
			
			p = new Preference(this);
			p.setTitle("Libzip (Mercurial Rev. 972)");
			p.setSummary("by Not Invented Here");
			abScreen.addPreference(p);
			
			
		}

	}
	
	//TODO: This should do more than invoke the overridden method
	/*@Override
	protected void onPause() {
		super.onPause();
	}*/
	
	//TODO: This should do more than invoke the overridden method
	/*@Override
	protected void onDestroy() {
		super.onDestroy();
	}*/
	
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
			builder.setMultiChoiceItems(R.array.scan_opts, null, new DialogInterface.OnMultiChoiceClickListener() {				
				@Override
				public void onClick(DialogInterface dialog, int which, boolean isChecked) {
					Log.d(TAG, "%d %s", which, String.valueOf(isChecked));
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
/*
		case R.string.about_droidsound:
			String fullName = "<ERROR>";
			try {
				PackageInfo pinfo = getPackageManager().getPackageInfo(getPackageName(), 0);
				
				String appName = getString(pinfo.applicationInfo.labelRes);
				fullName = String.format("%s %s (vc%d)\n%s", appName, pinfo.versionName, pinfo.versionCode, getString(R.string.about_droidsound)); 					
			} catch (NameNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			builder.setMessage(fullName);
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dialog, int id) {
					dialog.cancel();
				}
			});
			break; */
		default:
			builder.setMessage(id);
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dialog, int id) {
					dialog.cancel();
				}
			});
			break;
		}

        return builder.create();
	}

	
}
