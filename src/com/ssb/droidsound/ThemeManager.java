package com.ssb.droidsound;

import java.io.File;
import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Typeface;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.GradientDrawable;
import android.graphics.drawable.GradientDrawable.Orientation;
import android.graphics.drawable.StateListDrawable;
import android.os.FileObserver;
import android.os.Handler;
import android.os.Message;
import android.util.DisplayMetrics;
import android.util.StateSet;
import android.util.TypedValue;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewGroup.LayoutParams;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.SeekBar;
import android.widget.TextView;

import com.osbcp.cssparser.CSSParser;
import com.osbcp.cssparser.PropertyValue;
import com.osbcp.cssparser.Rule;
import com.osbcp.cssparser.Selector;
import com.ssb.droidsound.utils.Utils;

public class ThemeManager {
	@SuppressWarnings("unused")
	private static final String TAG = ThemeManager.class.getSimpleName();
	
	public static class Property {
		private String name;
		private String data;
		private ThemeManager tm;
		//private String selector;

		private float size = -1;
		private Bitmap bitmap = null;
		private Drawable drawable = null;
		private Typeface typeface = null;
		
		public Property(ThemeManager tm, String name, String data) {
			this.name = name;

			data = data.replaceAll("^\"|\"$", "");
			data = data.replaceAll("^'|'$", "");
			this.data = data;
			
			//this.selector = selector;
			this.tm = tm;
		}
		
		public boolean isNamed(String what) {
			return name.equals(what);
		}
		
		public Typeface getFont() {

			if(typeface == null) {
				
				if(data.equals("bold"))
					return Typeface.DEFAULT_BOLD;
				else if(data.equals("serif"))
					return Typeface.SERIF;
				if(data.equals("sans"))
					return Typeface.SANS_SERIF;
				if(data.equals("mono"))
					return Typeface.MONOSPACE;
				
				typeface = tm.fontCache.get(data);
				if(typeface == null && tm.basePath != null) {
					File f = new File(tm.basePath, data);
					if(f.exists()) {
						typeface = Typeface.createFromFile(f);
						tm.fontCache.put(data, typeface);
					}
				}
				if(typeface == null)
					typeface = Typeface.createFromAsset(tm.mContext.getAssets(), data);
				if(typeface == null)
					typeface = Typeface.DEFAULT;
			}
			return typeface;				
		}
		
		public int getColor() {
			return parseColor(data);
		}

		private int parseColor(String data) {
			if(data.charAt(0) == '#') {
				data = data.substring(1);
			}
			if(data.startsWith("transp"))
				return 0;
			if(data.length() <= 6)
				return 0xff000000 | Integer.parseInt(data, 16);
			else
				return Integer.parseInt(data, 16);
				
		}
		
		public Drawable getDrawable() {
			if(drawable == null) {
				drawable = parseDrawable(data);
			}
			return drawable;
		}
		
		public Drawable parseDrawable(String data) {

			Drawable drawable = null;

			if(data.charAt(0) == '#') {
				return new ColorDrawable(parseColor(data.substring(1)));
			} else if(data.charAt(0) == '(') {
				String[] what = data.split("[\\(,\\s\\)]+");
				StateListDrawable sld = new StateListDrawable();

				if(what.length > 3) {
					drawable = parseDrawable(what[3]); //new BitmapDrawable(tm.mContext.getResources(), parseBitmap(what[3]));
					sld.addState(new int [] { android.R.attr.state_focused }, drawable);
				}
				if(what.length > 2) {
					drawable =  parseDrawable(what[2]); //new BitmapDrawable(tm.mContext.getResources(), parseBitmap(what[2]));
					sld.addState(new int [] { android.R.attr.state_pressed }, drawable);
				}
				if(what.length > 1) {
					drawable =  parseDrawable(what[1]); //new BitmapDrawable(tm.mContext.getResources(), parseBitmap(what[1]));
					sld.addState(StateSet.WILD_CARD, drawable);
				}
				drawable = sld;
			}
			else {
				String[] what = data.split("[\\(,\\s\\)]+");				
				if(what[0].startsWith("-webkit-"))
					what[0] = what[0].substring(8);
				if(what[0].equals("linear-gradient") || what[0].equals("radial-gradient")) {
					
					int [] colors = new int [ what.length - 2];
					for(int i=0; i<colors.length; i++) {
						colors[i] = parseColor(what[i+2]);
					}
					
					Orientation o = Orientation.LEFT_RIGHT;
					if(what[1].equals("right"))
						o = Orientation.RIGHT_LEFT;
					if(what[1].equals("top"))
						o = Orientation.TOP_BOTTOM;
					if(what[1].equals("bottom"))
						o = Orientation.BOTTOM_TOP;
					if(what[1].equals("right"))
						o = Orientation.RIGHT_LEFT;
					GradientDrawable gd = new GradientDrawable(o, colors);
					if(what[0].startsWith("radial-"))
						gd.setGradientType(GradientDrawable.RADIAL_GRADIENT);
					drawable = gd;
				} else {
					Bitmap bm = parseBitmap(data);
					drawable = new BitmapDrawable(tm.mContext.getResources(), bm);
				}
				
				//linear-gradient(top, #2F2727, #1a82f7);
				//radial-gradient(circle, #1a82f7, #2F2727);
			}
			return drawable;			
		}
		
		public float getSize() {
			
			if(size < 0) {
				
				DisplayMetrics metrics =  tm.mContext.getResources().getDisplayMetrics();
				
				if(data.equals("match"))
					return LayoutParams.MATCH_PARENT;
				else if(data.equals("wrap"))
					return LayoutParams.WRAP_CONTENT;
				
				int i = 0;
				while(i < data.length() && Character.isDigit(data.charAt(i))) {
					i++;
				}
				size = (float) Integer.parseInt(data.substring(0,i));
				String unit = data.substring(i);
				
				if(unit.equals("dp"))
					size = TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, size, metrics);
				else if(unit.equals("pt"))
					size = TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_PT, size, metrics);
				else if(unit.equals("sp"))
					size = TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_SP, size, metrics);
				//Log.d(TAG, "%s GETSIZE: %s => %d %s => %d", name, data, size, unit, (int)px);
			}
			return size;
		}

		public Bitmap getBitmap() {
			
			if(bitmap == null)	
				bitmap = parseBitmap(data);
			return bitmap;
		}

		private Bitmap parseBitmap(String name) {
			Bitmap bitmap = null;
			if(tm.basePath != null) {
				File f = new File(tm.basePath, name);
				bitmap = tm.bitmapCache.get(f.getPath());
				if(bitmap == null && f.exists())
					bitmap = BitmapFactory.decodeFile(f.getPath());						
			}
			if(bitmap == null) {
				bitmap = tm.bitmapCache.get(name);
				if(bitmap == null)
					bitmap = Utils.getBitmapFromAsset(tm.mContext, name);
			}
			return bitmap;
		}

		public String name() {
			return name;
		}

		public boolean startsWith(String string) {
			return name.startsWith(string);
		}

		public boolean endsWith(String string) {
			return name.endsWith(string);
		}

		public Drawable getBackgroundDrawable() {
			Drawable drawable = getDrawable();			
			StateListDrawable sld = new StateListDrawable();			
			ColorDrawable t = new ColorDrawable(android.R.color.transparent);			
			sld.addState(new int [] { android.R.attr.state_focused }, t );
			sld.addState(new int [] { android.R.attr.state_pressed }, t);
			sld.addState(StateSet.WILD_CARD, drawable);
			return sld;
		}



	}

	public static interface SelectorListener {
		void propertyChanged(Property property, String selector);
	}
	
	public static interface ChangeListener {
		void themeChanged();
	}

	
	private static ThemeManager __instance;
	
	public static ThemeManager getInstance() {
		if(__instance == null)
			__instance = new ThemeManager();
		return __instance;
	}

	private Map<String, Typeface> fontCache;
	private Map<String, Bitmap> bitmapCache;
	private Map<String, View> managedViews;
		
	
	
	private File basePath;
	private List<Rule> cssRules;
	private Map<String, List<SelectorListener> > listeners;
	private FileObserver observer = null;
	private File themeFile;

	private Context mContext;
	private Map<Rule, List<Property>> ruleMap;
	private String css;
	private List<ChangeListener> changeListeners;
	private String defaultCss;

	private ThemeManager() {
		fontCache = new HashMap<String, Typeface>();
		bitmapCache = new HashMap<String, Bitmap>();
	}
	
	public void init() {
		listeners = new HashMap<String, List<SelectorListener> >();
		changeListeners = new ArrayList<ChangeListener>();
		basePath = null;
		cssRules = null;
		managedViews = new LinkedHashMap<String, View>();
	}

	
	
	public void registerListener(String pattern, SelectorListener sl) {
		List<SelectorListener> l = listeners.get(pattern);
		if(l == null) l = new ArrayList<SelectorListener>();
		l.add(sl);
		listeners.put(pattern, l);
		if(cssRules != null)
			sendChanges(pattern, sl);
	};
	
	public void manageView(String selector, View view) {
		if(view == null) {
			return;
		}
		managedViews.put(selector, view);
		if(cssRules != null) {
			updateViews(view);
		}
	}
	
	private void updateViews() {
		updateViews(null);
	}
	
	private void updateViews(View singleView) {
		

		for(Rule r : cssRules) {
			List<Selector> selectors = r.getSelectors();
			
			List<Property> list = ruleMap.get(r);
			
			for(Selector s : selectors) {
				String sname = s.toString();		
				for(Entry<String, View> e : managedViews.entrySet()) {
					if(singleView == null || singleView == e.getValue()) {
						if(e.getKey().startsWith(sname + ".") || e.getKey().equals(sname)) {
							
							Iterator<Property> iterator = list.iterator();
							while(iterator.hasNext()) {
								Property prop = iterator.next();
								if(updateViewProperty(prop, e.getValue())) {
									if(e.getKey().equals(sname))
										iterator.remove();
								}
							}
						}
					}
				}				
			}
		}
	}
	

	public void applySelector(View view, String selector) {
		

		for(Rule r : cssRules) {
			List<Selector> selectors = r.getSelectors();
			
			List<Property> list = ruleMap.get(r);
			
			for(Selector s : selectors) {
				if(selector.equals(s.toString())) {
					Iterator<Property> iterator = list.iterator();
					while(iterator.hasNext()) {
						Property prop = iterator.next();
						updateViewProperty(prop, view);
					}
				}				
			}
		}
	}

	public void applyProperty(View view, Property property) {
		updateViewProperty(property, view);
	}

	@SuppressWarnings("deprecation")
	private boolean updateViewProperty(Property p, View view) {
		boolean ok = true;

		int dot = p.name.lastIndexOf(".");
		
		if(dot > 0) {
			view = ((ViewGroup)view).findViewWithTag(p.name.substring(0,dot));
			p = new Property(this, p.name.substring(dot+1), p.data);
			return updateViewProperty(p, view);
		}
		
		if(Character.isDigit(p.name.charAt(0))) {
			int index = Integer.parseInt(p.name.substring(0,1));
			view = ((ViewGroup)view).getChildAt(index);
			p = new Property(this, p.name.substring(2), p.data);
			return updateViewProperty(p, view);
		}

		LayoutParams lp = view.getLayoutParams();
		if(p.isNamed("width")) {
			lp.width = (int) p.getSize();
			view.setLayoutParams(lp);
		} else
		if(p.isNamed("height")) {
			lp.height = (int) p.getSize();
			view.setLayoutParams(lp);
		} else
		if(p.isNamed("padding")) {
			int padding = (int) p.getSize();
			view.setPadding(padding, padding, padding, padding);
		} else
		if(p.startsWith("padding")) {
			int bottom = view.getPaddingBottom();
			int top = view.getPaddingTop();
			int left = view.getPaddingLeft();
			int right = view.getPaddingRight();
			
			if(p.endsWith("-left"))
				left = (int) p.getSize();
			if(p.endsWith("-right"))
				right = (int) p.getSize();
			if(p.endsWith("-top"))
				top = (int) p.getSize();
			if(p.endsWith("-bottom"))
				bottom = (int) p.getSize();			
			view.setPadding(left, top, right, bottom);
		} else if(p.isNamed("background")) {
			view.setBackgroundDrawable(p.getDrawable());
		} else if(p.isNamed("background-color")) {
			view.setBackgroundColor(p.getColor());
		} else			
			ok = false;
		
		if(ok) return true;
		
		if(view instanceof TextView) {
			ok = true;
			TextView tv = (TextView) view;
			if(p.isNamed("font-size"))
				tv.setTextSize(TypedValue.COMPLEX_UNIT_PX, p.getSize());
			else if(p.isNamed("color"))
				tv.setTextColor(p.getColor());
			else if(p.isNamed("font"))
				tv.setTypeface(p.getFont());
			else
				ok = false;
		}
		
		if(ok) return true;

		if(view instanceof ImageView) {
			ok = true;
			ImageView iv = (ImageView) view;
			if(p.isNamed("image"))
				iv.setImageDrawable(p.getDrawable());
			else ok = false;
		}
		
		if(ok) return true;
		
		if(view instanceof ProgressBar) {
			ProgressBar pb = (ProgressBar) view;
			ok = true;
			if(p.isNamed("progress-background"))
				pb.setProgressDrawable(p.getDrawable());
			else
				ok = false;
		}
		
		if(ok) return true;

		if(view instanceof SeekBar) {
			SeekBar sb = (SeekBar) view;
			ok = true;
			if(p.isNamed("thumb-image"))
				sb.setThumb(p.getDrawable());
			else
				ok = false;
		}

		return ok;
	}

	private void sendChanges(String pattern, SelectorListener sl) {
		
		for(Rule r : cssRules) {
			List<Selector> selectors = r.getSelectors();
			for(Selector s : selectors) {
				String sname = s.toString();
				if(sname.startsWith(pattern)) {
					//String [] parts = sname.split("\\.");
					for(PropertyValue val : r.getPropertyValues()) {
						Property p = new Property(this, val.getProperty(), val.getValue());
						sl.propertyChanged(p, sname);
					}
				}
			}
		}	
	}
	
	private void sendAllChanges() {
		for(Entry<String, List<SelectorListener> > e : listeners.entrySet()) {
			for(SelectorListener sl : e.getValue()) 
				sendChanges(e.getKey(), sl);
		}
		
		for(ChangeListener cl : changeListeners) {
			cl.themeChanged();
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
		
		String newCss = null;
		if(themeFile.exists())
			newCss = Utils.readFile(themeFile);

		if(newCss != null)
			css = newCss;
		else
			css = defaultCss;
		parseCss(css);
		
		if(cssRules == null) {
			css = defaultCss;
			parseCss(css);
		}
		
		sendAllChanges();
		updateViews();
	}
	
	public String getCSS() {
		return css;
	}


	public boolean loadTheme(Context ctx, File themeFile, String defaultCss) {

		mContext = ctx;
		
		this.defaultCss = defaultCss;
		
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
				if(path != null && path.endsWith("gui.css")) {
					Message msg = handler.obtainMessage(0);
					handler.sendMessage(msg);
				}
			}
		};
		observer.startWatching();
		reload();

		return true;
	}
	
	private void parseCss(String css) {
		
		try {
			cssRules = CSSParser.parse(css);
			
			
			ruleMap = new HashMap<Rule, List<Property>>();		
			for(Rule r : cssRules) {
				List<PropertyValue> pvals = r.getPropertyValues();
				List<Property> list = new ArrayList<Property>();
				for(PropertyValue val : pvals) {
					Property p = new Property(this, val.getProperty(), val.getValue());
					list.add(p);				
				}
				ruleMap.put(r, list);
			}

			
			/*for(Rule r : cssRules) {
				List<Selector> selectors = r.getSelectors();
				for(Selector s : selectors) {
					System.out.printf("%s\n", s.toString());
				}
				List<PropertyValue> vals = r.getPropertyValues();
				for(PropertyValue val : vals) {
					Property p = new Property(this, val.getProperty(), val.getValue(), null);
					//System.out.printf("%s = %s\n", p.getProperty(), p.getValue());
				}
				
			}*/

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public File getBaseDir() {
		return basePath;
	}

	public void onChange(ChangeListener changeListener) {
		changeListeners.add(changeListener);
	}

	
}
