package com.ssb.droidsound.plugins;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.ssb.droidsound.file.FileSource;
import com.ssb.droidsound.file.FileUtils;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.UnRar;

public class RSNPlugin extends DroidSoundPlugin {
	private static final String TAG = RSNPlugin.class.getSimpleName();

	private static class SongHandler {
		public SongHandler(FileSource fs, DroidSoundPlugin p) {
			source = fs;
			plugin = p;
		}
		public FileSource source;
		public DroidSoundPlugin plugin;
	}
	
	//GMEPlugin plugin;
	private UnRar rarFile;
	private ArrayList<SongHandler> handlers;
	//private boolean loaded;
	private File targetFile;

	private String title;
	private List<DroidSoundPlugin> plugins;
	private DroidSoundPlugin currentPlugin;
	
	private static Map<String, String> lookup = new HashMap<String, String>();
	
	public RSNPlugin() {
		
		synchronized (lookup) {
			if(lookup.size() == 0) {
				try {
					InputStream is = getContext().getAssets().open("rsnsets.dat");
					//DataInputStream dis = new DataInputStream(is);
					BufferedReader br = new BufferedReader(new InputStreamReader(is));
					while(true) {
						String line = br.readLine();
						if(line == null)
							break;
						int sc = line.lastIndexOf(';');
						if(sc > 0) {
							String title = line.substring(0,sc);
							String name = line.substring(sc+1);
							//Log.d(TAG, "Found %s = %s", name, title);
							lookup.put(name, title);
						}
					}
					br.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
		
		
	}
	

	@Override
	public boolean canHandle(FileSource source) {
		String ext = source.getExt();
		return ext.equals("RSN") || ext.equals("RMU");
	}
	
	@Override
	public boolean load(FileSource source) {
		
		if(plugins == null) {
			plugins = DroidSoundPlugin.createPluginList();
		}
		//	plugin = new GMEPlugin();
		
		title = FileUtils.getBaseName(source.getName());
		
		if(lookup.containsKey(title)) {
			title = lookup.get(title);
		}
		Log.d(TAG, "Found title %s", title);
		
	
		Log.d(TAG, "Unrar RSN");
		rarFile = new UnRar(source.getFile().getPath());
		targetFile = FileUtils.getTempDir();//fs.getFile().getParentFile();
		rarFile.extractTo(targetFile.getPath());		
		File [] files = targetFile.listFiles();
		handlers = new ArrayList<SongHandler>();
		for(File f : files) {
			int dot = f.getName().lastIndexOf('.');
			if(dot >= 0) {
				FileSource fs = FileSource.fromFile(f);
				for(DroidSoundPlugin p : plugins) {
					if(p.canHandle(fs)) {
						handlers.add(new SongHandler(fs, p));
						break;
					}
				}				
			}
		}
		
		
		
		return true;
	}
	
	@Override
	public boolean loadInfo(FileSource fs) {
		
		title = FileUtils.getBaseName(fs.getName());
		
		if(lookup.containsKey(title)) {
			title = lookup.get(title);
		}
		
		return true;
	}

	@Override
	public void unload() {
		if(currentPlugin != null) {
			currentPlugin.unload();
			currentPlugin = null;
		}
		
		if(targetFile != null)
			FileUtils.removeDir(targetFile);
	}

	@Override
	public int getSoundData(short[] dest, int size) {
		if(currentPlugin == null) {
			currentPlugin = handlers.get(0).plugin;
			currentPlugin.load(handlers.get(0).source);
		}
		return currentPlugin.getSoundData(dest, size);
	}
	
	@Override
	public boolean setTune(int tune) {

		if(currentPlugin != null) {
			currentPlugin.unload();
		}
		currentPlugin = handlers.get(tune).plugin;
		currentPlugin.load(handlers.get(tune).source);
		
		return true;
	}

	@Override
	public String getStringInfo(int what) {
		
		if(what == INFO_TITLE)
			return title;

		if(handlers == null)
			return null;
		
		if(what == INFO_SUBTUNE_TITLE)
			what = INFO_TITLE;
		else if(what == INFO_SUBTUNE_AUTHOR)
			what = INFO_AUTHOR;
		
		if(currentPlugin == null) {
			currentPlugin = handlers.get(0).plugin;
			currentPlugin.load(handlers.get(0).source);
		}		
		
		return currentPlugin.getStringInfo(what);
	}

	@Override
	public int getIntInfo(int what) {

		if(handlers == null)
			return 0;
		
		if(what == INFO_SUBTUNE_COUNT) {
			return handlers.size();
		}
				
		if(currentPlugin == null) {
			currentPlugin = handlers.get(0).plugin;
			currentPlugin.load(handlers.get(0).source);
		}

		return currentPlugin.getIntInfo(what);
	}

}
