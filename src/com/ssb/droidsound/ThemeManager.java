package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Properties;

import android.os.FileObserver;
import android.os.Handler;
import android.os.Message;

import com.osbcp.cssparser.CSSParser;
import com.osbcp.cssparser.PropertyValue;
import com.osbcp.cssparser.Rule;
import com.osbcp.cssparser.Selector;
import com.ssb.droidsound.utils.Utils;

public class ThemeManager {
	
	public static interface SelectorListener {
		void propertiesChanged(String selectorName, Map<String, String> changes);
	}
	
	private static ThemeManager __instance;
	
	public static ThemeManager getInstance() {
		if(__instance == null)
			__instance = new ThemeManager();
		return __instance;
	}

		
	private File basePath;
	private List<Rule> cssRules;
	private Map<String, List<SelectorListener> > listeners;
	private static FileObserver observer = null;
	private File themeFile;

	private ThemeManager() {
		listeners = new HashMap<String, List<SelectorListener> >();
		basePath = null;
	}
	
	public void registerListener(String pattern, SelectorListener sl) {
		List<SelectorListener> l = listeners.get(pattern);
		if(l == null) l = new ArrayList<SelectorListener>();
		l.add(sl);
		listeners.put(pattern, l);
		if(cssRules != null)
			sendChanges(pattern, sl);
	};
	
	private void sendChanges(String pattern, SelectorListener sl) {
		
		for(Rule r : cssRules) {
			List<Selector> selectors = r.getSelectors();
			for(Selector s : selectors) {
				if(s.toString().startsWith(pattern)) {
					Map<String, String> map = new HashMap<String, String>();
					for(PropertyValue val : r.getPropertyValues()) {
						map.put(val.getProperty(), val.getValue());
					}
					sl.propertiesChanged(s.toString(), map);
				}
			}
		}
		
	}
	
	private static class MyHandler extends Handler {

		private WeakReference<ThemeManager> tmRef;
		public MyHandler(ThemeManager ps) {
			tmRef = new WeakReference<ThemeManager>(ps);
		}
		@Override
		public void handleMessage(Message msg) {
			tmRef.get().reload();
		}
	};
	
	private void reload() {
		String css = Utils.readFile(themeFile);
		parseCss(css);
		for(Entry<String, List<SelectorListener> > e : listeners.entrySet()) {
			for(SelectorListener sl : e.getValue()) 
				sendChanges(e.getKey(), sl);
		}		
	}


	public boolean loadTheme(File themeFile) {

		if(!themeFile.exists())
			return false;
		this.themeFile = themeFile;
		basePath = themeFile.getParentFile();
		final Handler handler = new MyHandler(this);
		if(observer != null) {
			observer.stopWatching();
			observer = null;
		}
		observer = new FileObserver(basePath.getPath(), FileObserver.MODIFY | FileObserver.MOVED_TO | FileObserver.CREATE) {			
			@Override
			public void onEvent(int event, String path) {
				Message msg = handler.obtainMessage(0);
				handler.sendMessage(msg);
			}
		};
		observer.startWatching();
		reload();

		return true;
	}
	
	public boolean loadTheme(String css, String templateDir) {
		parseCss(css);
		for(Entry<String, List<SelectorListener> > e : listeners.entrySet()) {
			for(SelectorListener sl : e.getValue()) 
				sendChanges(e.getKey(), sl);
		}
		return true;
	}
	
	private void parseCss(String css) {
		
		try {
			cssRules = CSSParser.parse(css);
			for(Rule r : cssRules) {
				List<Selector> selectors = r.getSelectors();
				for(Selector s : selectors) {
					System.out.printf("%s\n", s.toString());
				}
				List<PropertyValue> vals = r.getPropertyValues();
				for(PropertyValue p : vals) {
					System.out.printf("%s = %s\n", p.getProperty(), p.getValue());
				}
				
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		
	}

	public File getBaseDir() {
		return basePath;
	}
	
}
