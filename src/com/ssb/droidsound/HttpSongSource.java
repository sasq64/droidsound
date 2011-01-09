package com.ssb.droidsound;

import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLConnection;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

import org.htmlcleaner.CleanerProperties;
import org.htmlcleaner.HtmlCleaner;
import org.htmlcleaner.TagNode;
import org.htmlcleaner.XPatherException;

import android.database.Cursor;
import android.database.MatrixCursor;
import android.util.Log;

public class HttpSongSource {
	private static final String TAG = HttpSongSource.class.getSimpleName();
	
	private static Map<String, MatrixCursor> dirMap = new HashMap<String, MatrixCursor>();

	private static Map<String, Character> htmlMap = new HashMap<String, Character>();
	static {
		htmlMap.put("amp", '&');
		htmlMap.put("lt", '<');
		htmlMap.put("gt", '>');
		htmlMap.put("quot", '"');
		/*String s = "Nothing to do";
		Log.v(TAG, String.format("'%s' became '%s'", s, htmlFix(s)));
		s = "Rythm &amp; Blues";
		Log.v(TAG, String.format("'%s' became '%s'", s, htmlFix(s)));
		s = "&lt;VERY&gt;&lt;MESSY&gt;";
		Log.v(TAG, String.format("'%s' became '%s'", s, htmlFix(s)));*/
	}
	
	
	private static String htmlFix(String s) {

		int a = 0;
		int start = 0;
		StringBuilder sb = new StringBuilder();
		
		while(a >= 0) {
			a = s.indexOf('&', start);
			if(a >= 0) {
				int e = s.indexOf(';', a+1);
				if(e >= 0) {
					sb.append(s, start, a);
					String code = s.substring(a+1, e);
					if(code.charAt(0) == '#') {
						try {
							sb.append((char)Integer.parseInt(code.substring(1)));
						} catch (NumberFormatException excp) {
						}
					} else {
						Character c = htmlMap.get(code);
						if(c != null)
							sb.append(c);
					}
					a = e;
				}
				start = a+1;
			}
		}
		
		sb.append(s.substring(start));
		
		return sb.toString();
		
	}
	
	public static Cursor getFilesInPath(String pathName, int sorting) {
		
		Log.v(TAG, String.format("PATH '%s'", pathName));
		
		if(!pathName.endsWith("/"))
			pathName = pathName + "/";
		
		MatrixCursor cursor = dirMap.get(pathName);
		if(cursor != null) {
			Log.v(TAG, "IN CACHE!");
			return cursor;
		}
		
		try {
			URL url = new URL(pathName);		
			URLConnection conn = url.openConnection();
			if (!(conn instanceof HttpURLConnection))
				throw new IOException("Not a HTTP connection");
	
			HttpURLConnection httpConn = (HttpURLConnection) conn;
			httpConn.setAllowUserInteraction(false);
			httpConn.setInstanceFollowRedirects(true);
			httpConn.setRequestMethod("GET");
	
			Log.v(TAG, "Connecting to " + pathName);
	
			httpConn.connect();
	
			int response = httpConn.getResponseCode();
			if (response == HttpURLConnection.HTTP_OK) {
				Log.v(TAG, "HTTP connected");

				HtmlCleaner cleaner = new HtmlCleaner();
				CleanerProperties props = cleaner.getProperties();
				props.setOmitComments(true);

				 TagNode node = cleaner.clean(new InputStreamReader(conn.getInputStream()));
				 try {
					 Object[] links = node.evaluateXPath("//a");
					 
					 cursor = new MatrixCursor(new String [] { "TITLE", "TYPE", "PATH", "FILENAME"} );
					 
					 Comparator<? super Object> comparator = new Comparator<Object>() {
						@Override
						public int compare(Object object1, Object object2) {
							 String n0 = ((TagNode)object1).getText().toString();
							 String n1 = ((TagNode)object2).getText().toString();
							 String h0 = ((TagNode)object1).getAttributeByName("href");
							 String h1 = ((TagNode)object2).getAttributeByName("href");

							 if(h0.endsWith("/")) {
								 if(h1.endsWith("/")) {
									 return n0.compareTo(n1);
								 }
								 return -1;
							 } else if(h1.endsWith("/")) {
								 if(h0.endsWith("/")) {
									 return n0.compareTo(n1);
								 }
								 return 1;
							 }

							 return n0.compareTo(n1);
						}
					 };
					//Arrays.sort(links, comparator);
					 
					 for(int i=0; i<links.length; i++) {
						 TagNode atag = (TagNode) links[i];
						 String href = atag.getAttributeByName("href");
						 String text = atag.getText().toString();
						 Log.v(TAG, String.format("Found link to '%s' named '%s'", href, text));
						 
						 String title = htmlFix(text);
						 String fileName = htmlFix(href);

						 String path = pathName;						 
						 
						 int type = SongDatabase.TYPE_FILE;
						 if(!fileName.startsWith("/") && !fileName.startsWith("?")) {
							 if(fileName.endsWith("/")) {								 
								 if(title.endsWith("/"))
									 title = title.substring(0, title.length()-1);
								 type = SongDatabase.TYPE_DIR;
								 fileName = fileName.substring(0, fileName.length()-1);
								 cursor.addRow(new Object [] { title, type, path, fileName } );
							 } else {
								 if(FileIdentifier.canHandle(fileName) != null)
									 cursor.addRow(new Object [] { title, type, path, fileName } );
							 }
						 }
					 }
					 					 
					 dirMap.put(pathName, cursor);
					 
					 return cursor;

				} catch (XPatherException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}

			} else {
				Log.v(TAG, String.format("Connection failed: %d", response));
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}
}
