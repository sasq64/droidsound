package com.ssb.droidsound.plugins;

import java.io.File;
import java.util.ArrayList;

import com.ssb.droidsound.service.FileCache;
import com.ssb.droidsound.service.FileSource;
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

	@Override
	public boolean canHandle(FileSource fs) {
		return fs.getExt().equals("RSN");
	}
	
	@Override
	public boolean load(FileSource fs) {
		
		if(plugin == null)
			plugin = new GMEPlugin();
		
		title = fs.getName();
	
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
		return true;
	}

	@Override
	public void unload() {
		if(loaded) {
			plugin.unload();
			loaded = false;
		}
			
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
		
		if(spcFiles == null)
			return null;
		
		if(what == INFO_TITLE)
			return title;
		
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
