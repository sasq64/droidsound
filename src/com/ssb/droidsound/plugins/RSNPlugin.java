package com.ssb.droidsound.plugins;

import java.io.DataInputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import com.ssb.droidsound.service.FileCache;
import com.ssb.droidsound.utils.FileSource;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.UnRar;

public class RSNPlugin extends DroidSoundPlugin {
	private static final String TAG = RSNPlugin.class.getSimpleName();

	GMEPlugin plugin;
	private UnRar rarFile;
	private ArrayList<FileSource> spcFiles;
	private boolean loaded;
	private File targetFile;

	private String title;
	
	private static Map<String, String> lookup = new HashMap<String, String>();
	
	RSNPlugin() {
		
		synchronized (lookup) {
			if(lookup.size() == 0) {
				try {
					InputStream is = getContext().getAssets().open("rsnsets.dat");
					DataInputStream dis = new DataInputStream(is);
					while(true) {
						String line = dis.readLine();
						if(line == null)
							break;
						int sc = line.lastIndexOf(';');
						if(sc > 0) {
							String title = line.substring(0,sc);
							String name = line.substring(sc+1);
							Log.d(TAG, "Found %s = %s", name, title);
							lookup.put(name, title);
						}
					}
					dis.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
		
		
	}
	

	@Override
	public boolean canHandle(FileSource fs) {
		return fs.getExt().equals("RSN");
	}
	
	@Override
	public boolean load(FileSource fs) {
		
		if(plugin == null)
			plugin = new GMEPlugin();
		
		title = FileCache.getBaseName(fs.getName());
		
		if(lookup.containsKey(title)) {
			title = lookup.get(title);
		}
		Log.d(TAG, "Found title %s", title);
		
	
		Log.d(TAG, "Unrar RSN");
		rarFile = new UnRar(fs.getFile().getPath());
		targetFile = FileCache.getTempDir();//fs.getFile().getParentFile();
		rarFile.extractTo(targetFile.getPath());		
		File [] files = targetFile.listFiles();
		spcFiles = new ArrayList<FileSource>();
		for(File f : files) {
			int dot = f.getName().lastIndexOf('.');
			if(dot >= 0) {
				String ext = f.getName().substring(dot+1).toUpperCase();
				if(ext.equals("SPC")) {
					spcFiles.add(new FileSource(f));
				}
			}
		}
		return true;
	}
	
	@Override
	public boolean loadInfo(FileSource fs) {
		
		title = FileCache.getBaseName(fs.getName());
		
		if(lookup.containsKey(title)) {
			title = lookup.get(title);
		}
		
		return true;
	}

	@Override
	public void unload() {
		if(loaded) {
			plugin.unload();
			loaded = false;
		}
		
		if(targetFile != null)
			FileCache.removeDir(targetFile);
	}

	@Override
	public int getSoundData(short[] dest, int size) {
		if(!loaded) {
			plugin.load(spcFiles.get(0));
			loaded = true;
		}
		return plugin.getSoundData(dest, size);
	}
	
	@Override
	public boolean setTune(int tune) {

		if(loaded) {
			plugin.unload();
			loaded = true;
		}
		plugin.load(spcFiles.get(tune));
		
		return true;
	}

	@Override
	public String getStringInfo(int what) {
		
		if(what == INFO_TITLE)
			return title;

		if(spcFiles == null)
			return null;
		
		if(what == INFO_SUBTUNE_TITLE)
			what = INFO_TITLE;
		else if(what == INFO_SUBTUNE_AUTHOR)
			what = INFO_AUTHOR;
		
		if(!loaded) {
			plugin.load(spcFiles.get(0));
			loaded = true;
		}		
		
		return plugin.getStringInfo(what);
	}

	@Override
	public int getIntInfo(int what) {

		if(spcFiles == null)
			return 0;
		
		if(what == INFO_SUBTUNE_COUNT) {
			return spcFiles.size();
		}
				
		if(!loaded) {
			plugin.load(spcFiles.get(0));
			loaded = true;
		}

		return plugin.getIntInfo(what);
	}

}
