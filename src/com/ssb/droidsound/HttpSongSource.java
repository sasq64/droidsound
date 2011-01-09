package com.ssb.droidsound;

import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.htmlcleaner.CleanerProperties;
import org.htmlcleaner.HtmlCleaner;
import org.htmlcleaner.TagNode;
import org.htmlcleaner.XPatherException;

import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.MatrixCursor;
import android.util.Log;

public class HttpSongSource {
	private static final String TAG = HttpSongSource.class.getSimpleName();
	
	private static Map<String, MatrixCursor> dirMap = new HashMap<String, MatrixCursor>();

	private static Map<String, Character> htmlMap = new HashMap<String, Character>();

	private static Thread httpThread = null;

	private static HTTPWorker httpWorker = null;
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

		if(s == null) return s;
		
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
	
	private static class HTTPWorker implements Runnable {

		private List<String> dirList = new ArrayList<String>();
		private Context context;
		private boolean doQuit;
		
		public HTTPWorker(Context ctx) {
			context = ctx;
		}

		@Override
		public void run() {
			
			while(!doQuit) {
				try {
					synchronized (this) {
						wait();						
					}
				} catch (InterruptedException e) {
					return;
				}
				Log.v(TAG, "HTTP THREAD WOKE UP");				
				while(true) {
					String path = null;
					synchronized (dirList) {
						if(dirList.size() > 0) {
							Log.v(TAG, String.format("List has %d entries ", dirList.size()));
							path = dirList.get(0);
							dirList.remove(0);
							Log.v(TAG, "Found " + path);
						}
					}
					if(path != null)
						getDirFromHTTP(path);
					else
						break;
				}
			}
			
		}

		public void getDir(String pathName) {
			
			synchronized (dirList) {
				
				if(dirList.contains(pathName)) {
					Log.v(TAG, "Already working on " + pathName);
				} else {				
					dirList.add(pathName);
					Log.v(TAG, "Added " + pathName);
				}
			}
			synchronized (this) {
				notify();				
			}
		}

		private void getDirFromHTTP(String pathName) {
			
			MatrixCursor cursor = new MatrixCursor(new String [] { "TITLE", "TYPE", "PATH", "FILENAME"} );
			String msg = null;
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
							 
							 if(href == null || text == null)
								 continue;
							 
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

					} catch (XPatherException e) {
						// TODO Auto-generated catch block
						msg = "<HTML parsing failed>";
						e.printStackTrace();
					}

				} else {
					msg = "<Connection failed>";
					Log.v(TAG, String.format("Connection failed: %d", response));
				}
			} catch (MalformedURLException me) {
				msg = "<Illegal URL>";
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				msg = "<IO Error>";
			}
			
			if(msg != null) {
				cursor.addRow(new Object [] { msg, SongDatabase.TYPE_FILE, "", "" } );
				msg = null;
			}
			
			 synchronized (dirMap) {
				 dirMap.put(pathName, cursor);							
			 }
			 
			Intent intent = new Intent("com.sddb.droidsound.REQUERY");
			context.sendBroadcast(intent);
		}
		
		
	}
	
	
	public static Cursor getFilesInPath(Context ctx, String pathName, int sorting) {
	
		
		Log.v(TAG, String.format("PATH '%s'", pathName));
		
		if(!pathName.endsWith("/"))
			pathName = pathName + "/";
		
		MatrixCursor cursor = null;
		synchronized (dirMap) {
			 cursor = dirMap.get(pathName);			
		}

		if(cursor != null) {
			Log.v(TAG, "IN CACHE!");
			return cursor;
		}
		
		if(httpThread == null) {
			httpWorker = new HTTPWorker(ctx);
			httpThread = new Thread(httpWorker);
			httpThread.start();
			try {
				Thread.sleep(300);
			} catch (InterruptedException e) {
			}
		}		

		httpWorker.getDir(pathName);
		cursor = new MatrixCursor(new String [] { "TITLE", "TYPE", "PATH", "FILENAME"} );
		cursor.addRow(new Object [] { "<Working>", SongDatabase.TYPE_FILE, "", "" } );
		return cursor;
	}
}
