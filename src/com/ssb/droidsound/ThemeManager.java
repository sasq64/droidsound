package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Properties;

import com.osbcp.cssparser.CSSParser;
import com.osbcp.cssparser.PropertyValue;
import com.osbcp.cssparser.Rule;
import com.osbcp.cssparser.Selector;

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
	private Map<String, SelectorListener> listeners;

	private ThemeManager() {
		listeners = new HashMap<String, SelectorListener>();
		basePath = null;
	}
	
	public void registerListener(String pattern, SelectorListener sl) {		
		listeners.put(pattern, sl);
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

	public boolean loadTheme(File themeFile) {
		
		basePath = themeFile.getParentFile();
		
		Properties props = new Properties();
		try {
			FileInputStream is = new FileInputStream(themeFile);		
			props.load(is);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
	
	public boolean loadTheme(String css, String templateDir) {
		parseCss(css);
		for(Entry<String, SelectorListener> e : listeners.entrySet()) {
			sendChanges(e.getKey(), e.getValue());
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
