package com.ssb.droidsound;

import java.util.List;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.DialogInterface.OnMultiChoiceClickListener;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager.NameNotFoundException;
import android.net.Uri;
import android.os.Bundle;
import android.preference.Preference;
import android.preference.Preference.OnPreferenceChangeListener;
import android.preference.PreferenceActivity;
import android.preference.PreferenceCategory;
import android.preference.PreferenceGroup;
import android.preference.PreferenceManager;
import android.preference.PreferenceScreen;

import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.utils.Log;

public class SettingsActivity extends PreferenceActivity {

	protected static final String TAG = SettingsActivity.class.getSimpleName();
	private SongDatabase songDatabase;
	private boolean doFullScan;
	private SharedPreferences prefs;
	private String modsDir;

	class AudiopPrefsListener implements OnPreferenceChangeListener {

		private final DroidSoundPlugin plugin;

		AudiopPrefsListener(DroidSoundPlugin pi) {
			plugin = pi;
		}

		@Override
		public boolean onPreferenceChange(Preference preference, Object newValue) {
			String k = preference.getKey();
			String k2 = k.substring(k.indexOf('.')+1);
			Log.d(TAG, "CHANGED %s=%s", k, k2);

			if(newValue instanceof String) {
				try {
					int i = Integer.parseInt((String) newValue);
					newValue = new Integer(i);
				} catch (NumberFormatException e) {
				}
			}

			plugin.setOption(k2, newValue);
			return true;
		}
	};


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		addPreferencesFromResource(R.layout.preferences);

		songDatabase = PlayerActivity.songDatabase;

		prefs = PreferenceManager.getDefaultSharedPreferences(this);
		modsDir = prefs.getString("modsDir", null);

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

		pref = findPreference("download_link");
		pref.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() {
			@Override
			public boolean onPreferenceClick(Preference preference) {

				PackageInfo pinfo = null;
				try {
					pinfo = getPackageManager().getPackageInfo(getPackageName(), 0);
				} catch (NameNotFoundException e) {}
				Intent intent;
				if(pinfo != null && pinfo.versionName.contains("beta")) {
					intent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://swimsuitboys.com/droidsound/dl/beta.html"));
				} else {
					intent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://swimsuitboys.com/droidsound/dl/"));
				}
				startActivity(intent);
				return true;
			}
		});


		PackageInfo pinfo = null;
		try {
			pinfo = getPackageManager().getPackageInfo(getPackageName(), 0);
		} catch (NameNotFoundException e) {}

		List<DroidSoundPlugin> list = DroidSoundPlugin.createPluginList();
		String appName = getString(pinfo.applicationInfo.labelRes);

		PreferenceScreen aScreen = (PreferenceScreen) findPreference("audio_prefs");

		for (int i = 0; i < aScreen.getPreferenceCount(); i++) {
			Preference p = aScreen.getPreference(i);
			Log.d(TAG, "Pref '%s'", p.getKey());
			if (p instanceof PreferenceGroup) {
				PreferenceGroup pg = (PreferenceGroup) p;

				DroidSoundPlugin plugin = null;
				for (DroidSoundPlugin pl : list) {
					if (pl.getClass().getSimpleName().equals(pg.getKey())) {
						plugin = pl;
						break;
					}
				}
				if (plugin != null) {
					for (int j=0; j<pg.getPreferenceCount(); j++) {
						p = pg.getPreference(j);
						Log.d(TAG, "Pref %s for %s", p.getKey(), plugin.getClass().getName());
						p.setOnPreferenceChangeListener(new AudiopPrefsListener(plugin));
					}
				}
			}
		}

		PreferenceScreen abScreen = (PreferenceScreen) findPreference("about_prefs");

		if(abScreen != null) {
			PreferenceCategory pc = new PreferenceCategory(this);
			pc.setTitle("Droidsound");
			abScreen.addPreference(pc);

			Preference p = new Preference(this);
			p.setTitle("Application");
			p.setSummary(String.format("%s v%s\n(C) 2010,2011 by Jonas Minnberg (Sasq)", appName, pinfo.versionName));
			abScreen.addPreference(p);

			pc = new PreferenceCategory(this);
			pc.setTitle("Plugins");
			abScreen.addPreference(pc);

			for (DroidSoundPlugin pl : list) {
				p = new Preference(this);
				p.setTitle(pl.getClass().getSimpleName());
				p.setSummary(pl.getVersion());
				abScreen.addPreference(p);
			}

			pc = new PreferenceCategory(this);
			pc.setTitle("Other");
			abScreen.addPreference(pc);

			p = new Preference(this);
			p.setTitle("Icons");
			p.setSummary("G-Flat SVG by poptones");
			abScreen.addPreference(p);
		}

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
				@Override
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
				@Override
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
