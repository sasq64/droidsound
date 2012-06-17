package com.ssb.droidsound.file;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;

import com.ssb.droidsound.utils.Log;

public class StreamSource extends FileSource {
	private static final String TAG = StreamSource.class.getSimpleName();

	public StreamSource(String ref) {
		super(ref);
	}

	
	@Override
	protected InputStream intGetStream() {
				
		try {
			URL url = new URL(getReference());
	
			//Log.d(TAG, "Opening URL " + songName);		
			URLConnection conn = url.openConnection();
			if(!(conn instanceof HttpURLConnection))
				throw new IOException("Not a HTTP connection");
	
			HttpURLConnection httpConn = (HttpURLConnection) conn;
			httpConn.setAllowUserInteraction(false);
			httpConn.setInstanceFollowRedirects(true);
			httpConn.setRequestMethod("GET");
	
			Log.d(TAG, "Connecting");
	
			httpConn.connect();
	
			int response = httpConn.getResponseCode();
			if(response == HttpURLConnection.HTTP_OK) {
				Log.d(TAG, "HTTP connected");
				InputStream in = httpConn.getInputStream();
				return in;
			}
			
		} catch (MalformedURLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}	
}
