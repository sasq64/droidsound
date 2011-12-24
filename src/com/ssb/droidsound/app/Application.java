package com.ssb.droidsound.app;

import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.Map;
import java.util.Map.Entry;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.res.AssetManager;
import android.os.Environment;
import android.preference.PreferenceManager;
import android.widget.Toast;

import com.ssb.droidsound.R;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.service.SongDatabaseService;
import com.ssb.droidsound.utils.StreamUtil;

public class Application extends android.app.Application {
	private static Application app;

	public static File getPluginDataDirectory(Class<? extends DroidSoundPlugin> pluginClass) {
		return app.getDir(pluginClass.getSimpleName(), Context.MODE_PRIVATE);
	}

	public static AssetManager getAssetManager() {
		return app.getAssets();
	}

	public static File getModsDirectory() {
		File modsDir = new File(Environment.getExternalStorageDirectory(), "MODS");
		return modsDir;
	}

	@Override
	public void onCreate() {
		super.onCreate();
		app = this;

		startService(new Intent(this, SongDatabaseService.class));

		setupModsDir();

		PreferenceManager.setDefaultValues(this, R.layout.preferences, false);
		SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(this);
		Map<String, ?> prefsMap = prefs.getAll();

		for (DroidSoundPlugin plugin : DroidSoundPlugin.getPluginList()) {
			String pluginClass = plugin.getClass().getSimpleName();
			for (Entry<String, ?> entry : prefsMap.entrySet()) {
				String k = entry.getKey();
				int dot = k.indexOf('.');
				if (dot == -1) {
					continue;
				}

				if (k.substring(0, dot).equals(pluginClass)) {
					Object val = entry.getValue();
					plugin.setOption(k.substring(dot+1), val);
				}
			}
		}
	}

	private void setupModsDir() {
		File modsDir = getModsDirectory();
		if (! modsDir.exists()) {
			if (! modsDir.mkdirs()) {
				Toast.makeText(this, "Directory " + modsDir.getPath() + " could not be accessed nor created.", Toast.LENGTH_LONG).show();
				return;
			}

			File tempFile = new File(modsDir, "Examples.zip");
			if (! tempFile.exists()) {
				try {
					InputStream is = getAssets().open("Examples.zip");
					FileOutputStream os = new FileOutputStream(tempFile);
					StreamUtil.copy(is, os);
					os.close();
					is.close();

					FileWriter fw = new FileWriter(new File(modsDir, ".nomedia"));
					fw.close();
				} catch (IOException e) {
					Toast.makeText(this, e.toString(), Toast.LENGTH_LONG).show();
				}
			}
		}
	}


}
