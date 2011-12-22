package com.ssb.droidsound.app;

import java.io.File;

import android.content.Context;
import android.content.res.AssetManager;

import com.ssb.droidsound.plugins.DroidSoundPlugin;

public class Application extends android.app.Application {
	private static Application app;

	@Override
	public void onCreate() {
		super.onCreate();
		Application.app = this;
	}

	public static File getPluginDataDirectory(Class<? extends DroidSoundPlugin> pluginClass) {
		return app.getDir(pluginClass.getSimpleName(), Context.MODE_PRIVATE);
	}

	public static AssetManager getAssetManager() {
		return app.getAssets();
	}
}
