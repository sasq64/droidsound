package com.ssb.droidsound;

import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLConnection;
import java.util.HashMap;
import java.util.Map;

import org.htmlcleaner.CleanerProperties;
import org.htmlcleaner.HtmlCleaner;
import org.htmlcleaner.TagNode;
import org.htmlcleaner.XPatherException;

import com.ssb.droidsound.plugins.DroidSoundPlugin;

import android.database.Cursor;
import android.database.MatrixCursor;
import android.util.Log;

public class HttpSongSource {
	private static final String TAG = HttpSongSource.class.getSimpleName();
	
	private static Map<String, MatrixCursor> dirMap = new HashMap<String, MatrixCursor>();

	public static Cursor getFilesInPath(String pathName, int sorting) {
		
		
		if(!pathName.endsWith("/"))
			pathName = pathName + "/";
		
		MatrixCursor cursor = dirMap.get(pathName);
		if(cursor != null) return cursor;
		
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
					 
					 for(int i=0; i<links.length; i++) {
						 TagNode atag = (TagNode) links[i];
						 String href = atag.getAttributeByName("href");
						 String text = atag.getText().toString();
						 Log.v(TAG, String.format("Found link to '%s' named '%s'", href, text));
						 
						 String path = pathName;
						 String fileName = href;
						 String title = text;
						 
						 int type = SongDatabase.TYPE_FILE;
						 if(!href.startsWith("/") && !href.startsWith("?")) {
							 if(href.endsWith("/")) {
								 type = SongDatabase.TYPE_DIR;
								 href = href.substring(0, href.length()-1);
								 cursor.addRow(new Object [] { title, type, path, fileName } );
							 } else {
								 if(FileIdentifier.canHandle(href) != null)
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
