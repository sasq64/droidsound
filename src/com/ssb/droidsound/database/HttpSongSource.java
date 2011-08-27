package com.ssb.droidsound.database;

import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ConnectException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.net.UnknownHostException;
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

import com.ssb.droidsound.FileIdentifier;
import com.ssb.droidsound.utils.Log;

final class HttpSongSource {
	private static final String TAG = HttpSongSource.class.getSimpleName();
	private static final class CacheEntry {
		public final MatrixCursor cursor;
		public final int status;
		private CacheEntry(MatrixCursor cr, int st) {
			status = st;
			cursor = cr;
		}
	}

	private static final Map<String, CacheEntry> dirMap = new HashMap<String, CacheEntry>();

	private static final Map<String, Character> htmlMap = new HashMap<String, Character>();

	private static Thread httpThread = null;

	private static HTTPWorker httpWorker = null;
	static {
		htmlMap.put("amp", '&');
		htmlMap.put("lt", '<');
		htmlMap.put("gt", '>');
		htmlMap.put("quot", '"');
		/*String s = "Nothing to do";
		Log.d(TAG, "'%s' became '%s'", s, htmlFix(s));
		s = "Rythm &amp; Blues";
		Log.d(TAG, "'%s' became '%s'", s, htmlFix(s));
		s = "&lt;VERY&gt;&lt;MESSY&gt;";
		Log.d(TAG, "'%s' became '%s'", s, htmlFix(s));*/
	}




	private static String htmlFix(String s) {

		if(s == null) {
			return s;
		}

		int a = 0;
		int start = 0;
		final StringBuilder sb = new StringBuilder();

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
						if(c != null) {
							sb.append(c);
						}
					}
					a = e;
				}
				start = a+1;
			}
		}

		sb.append(s.substring(start));
		return sb.toString();
	}

	private static final class HTTPWorker implements Runnable {

		private final List<String> dirList = new ArrayList<String>();
		private final Context context;
		private boolean doQuit;
		private HTTPWorker(Context ctx) {
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
				Log.d(TAG, "HTTP THREAD WOKE UP");
				while(true) {
					String path = null;
					synchronized (dirList) {
						if(dirList.size() > 0) {
							Log.d(TAG, "List has %d entries ", dirList.size());
							path = dirList.get(0);
							dirList.remove(0);
							Log.d(TAG, "Found " + path);
						}
					}
					if(path != null) {
						getDirFromHTTP(path);
					} else {
						break;
					}
				}
			}
		}

		public void getDir(String pathName) {
			synchronized (dirList) {
				if(dirList.contains(pathName)) {
					Log.d(TAG, "Already working on " + pathName);
				} else {
					dirList.add(pathName);
					Log.d(TAG, "Added " + pathName);
				}
			}
			synchronized (this) {
				notifyAll();
			}
		}

		private void getDirFromHTTP(String pathName) {
			final MatrixCursor cursor = new MatrixCursor(new String [] { "TITLE", "TYPE", "PATH", "FILENAME"} );
			String msg = null;
			int status = 0;
			try {
				URL url = new URL(pathName);
				URLConnection conn = url.openConnection();
				if (!(conn instanceof HttpURLConnection)) {
					throw new IOException("Not a HTTP connection");
				}
				HttpURLConnection httpConn = (HttpURLConnection) conn;
				httpConn.setAllowUserInteraction(false);
				httpConn.setInstanceFollowRedirects(true);
				httpConn.setRequestMethod("GET");

				Log.d(TAG, "Connecting to " + pathName);

				httpConn.connect();

				int response = httpConn.getResponseCode();
				if (response == HttpURLConnection.HTTP_OK) {
					Log.d(TAG, "HTTP connected");

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
						 
						 Arrays.sort(links, comparator);
						 /*for(int i=0; i<links.length; i++) {
							 TagNode atag = (TagNode) links[i];
							 String href = atag.getAttributeByName("href");
							 String text = atag.getText().toString();

							 if(href == null || text == null) {
								continue;
							}

							 Log.d(TAG, "Found link to '%s' named '%s'", href, text);

							 String title = htmlFix(text);
							 String fileName = htmlFix(href);

                             int type = SongDatabase.TYPE_FILE;
							 if(!fileName.startsWith("/") && !fileName.startsWith("?")) {
								 if(fileName.endsWith("/")) {
									 if(title.endsWith("/")) {
										title = title.substring(0, title.length()-1);
									}
									 type = SongDatabase.TYPE_DIR;
									 fileName = fileName.substring(0, fileName.length()-1);
									 cursor.addRow(new Object [] { title, type, null, fileName } );
								 } else {
									 if(FileIdentifier.canHandle(fileName) != null) {
										cursor.addRow(new Object [] { title, type, pathName, fileName } );
									}
								 }
							 }
						 }*/

                         for (Object link : links) {  //Replaced above with a foreach loop
                             TagNode atag = (TagNode) link;
                             String href = atag.getAttributeByName("href");
                             String text = atag.getText().toString();

                             if (href == null || text == null) {
                                 continue;
                             }

                             Log.d(TAG, "Found link to '%s' named '%s'", href, text);

                             String title = htmlFix(text);
                             String fileName = htmlFix(href);

                             if (!fileName.startsWith("/") && !fileName.startsWith("?")) {
                                 int type = SongDatabase.TYPE_FILE;
                                 if (fileName.endsWith("/")) {
                                     if (title.endsWith("/")) {
                                         title = title.substring(0, title.length() - 1);
                                     }
                                     type = SongDatabase.TYPE_DIR;
                                     fileName = fileName.substring(0, fileName.length() - 1);
                                     cursor.addRow(new Object[]{title, type, null, fileName});
                                 } else {
                                     if (FileIdentifier.canHandle(fileName) != null) {
                                         cursor.addRow(new Object[]{title, type, pathName, fileName});
                                     }
                                 }
                             }
                         }

					} catch (XPatherException e) {
						// TODO Auto-generated catch block
						msg = "<HTML parsing failed>";
						status = -1;
						e.printStackTrace();
					}

				} else {
					msg = "<Connection failed>";
					status = -2;
					Log.d(TAG, "Connection failed: %d", response);
				}
			} catch (MalformedURLException me) {
				msg = "<Illegal URL>";
				status = -3;
				Log.d(TAG, "Illegal URL", me);
			} catch (ConnectException me) {
				msg = "<Connection Failed. Is Wifi turned on or configured?>";
				status = -4;
				Log.d(TAG, "Connection Failure. Is Wifi enabled and configured properly?");
			} catch (UnknownHostException me) {
				msg = "Unable to resolve host. Is Wifi enabled and configured properly?";
				status = -5;
				Log.d(TAG, "Unable to resolve host. Is Wifi enabled and configured properly?");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				msg = "<IO Error>";
				status = -6;
			}
			if(msg != null) {
				cursor.addRow(new Object [] { msg, SongDatabase.TYPE_FILE, null, "" } );
				msg = null;
			}
			 synchronized (dirMap) {
				 dirMap.put(pathName, new CacheEntry(cursor, status));
			 }
			 
			Intent intent = new Intent("com.sddb.droidsound.REQUERY");
			context.sendBroadcast(intent);
		}
	}

	public static Cursor getFilesInPath(Context ctx, String pathName, int sorting) {


		Log.d(TAG, "PATH '%s'", pathName);

		if(!pathName.endsWith("/")) {
			pathName = pathName + "/";
		}
		CacheEntry ce = null;
		synchronized (dirMap) {
			ce = dirMap.get(pathName);
			if(ce != null && ce.status < 0) {
				dirMap.remove(ce);
			}
		}

		if(ce != null) {
			Log.d(TAG, "IN CACHE!");
			return ce.cursor;
		}

		if(httpThread == null) {
			httpWorker = new HTTPWorker(ctx);
			httpThread = new Thread(httpWorker);
			httpThread.setName("HTTPSongSource-HTTPWorkerThread"); //Name of the processing thread specific to this class file.
			httpThread.start();
			try {
				Thread.sleep(300);
			} catch (InterruptedException e) {
			}
		}

		httpWorker.getDir(pathName);
		MatrixCursor cursor = new MatrixCursor(new String [] { "TITLE", "TYPE", "PATH", "FILENAME"} );
		cursor.addRow(new Object [] { "<Loading...>", SongDatabase.TYPE_FILE, null, "" } );
		return cursor;
	}
}
