package com.ssb.droidsound.utils;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.URL;
import java.net.UnknownHostException;
import java.util.HashMap;
import java.util.Map;

public class StreamingHttpConnection {
	private static final String TAG = StreamingHttpConnection.class.getSimpleName();
	private Socket httpSocket;
	private String requestMethod;
	private String requestProperties;
	private String requestPath;
	private String resultString;
	private boolean codeRead;

	private Map<String, String> headers;
	private int resultCode;

	public StreamingHttpConnection(URL url) throws UnknownHostException, IOException {

		Log.d(TAG, "Opening URL " + url.toString());
		int port = url.getPort();
		if(port < 0) port = 80;
		requestPath = url.getPath().trim();
		if(requestPath.length() == 0)
			requestPath = "/";
		
		requestProperties = new String();
		
		addRequestProperty("Host", url.getHost());
		addRequestProperty("User-Agent", "Droidsound 1.2 (Linux;Android)");
		addRequestProperty("Connection", "Close");

		httpSocket = new Socket(url.getHost(), port);
	}

	public void setAllowUserInteraction(boolean b) {
	}

	public void setInstanceFollowRedirects(boolean b) {
	}

	public void setRequestMethod(String method) {
		requestMethod = method; 
	}

	public void addRequestProperty(String prop, String val) {
		requestProperties += String.format("%s: %s\r\n", prop, val);
	}

	public void connect() throws IOException {
		String reqLine = String.format("%s %s %s\r\n", requestMethod, requestPath, "HTTP/1.0");
		
		OutputStream os = httpSocket.getOutputStream();
		
		String req = reqLine + requestProperties + "\r\n";
		
		Log.d(TAG, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! REQUEST:\n" + req);
		
		
		os.write(req.getBytes());
		
	}
	
	private String readLine(InputStream is) throws IOException {
		
		byte [] buffer = new byte [2048];
		int pos = 0;
		while(true) {
			int b = -1;
			while(b < 0)
				b = is.read();
			if(b == 0xa)
				break;
			else if(b != 0xd)
				buffer[pos++] = (byte) b;
		}
		
		return new String(buffer, 0, pos);
	}

	public int getResponseCode() throws IOException {
		if(!codeRead) {
			
			InputStream is = httpSocket.getInputStream();
			
			//br = new BufferedReader(new InputStreamReader(is));
			
			String line = null;
			while(line == null) {
				line = readLine(is);
				if(line != null) {
					Log.d(TAG, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! RESULT: " + line);
					String data [] = line.split(" ");
					resultCode = -1;
					if(data.length >= 3) {
						resultString = data[2];
						try {
							resultCode = Integer.parseInt(data[1]);
						} catch (NumberFormatException e) {
						}
					}

					codeRead = true;
					break;
				}
			}
			
		}
		return resultCode;
	}
	
	public String getResultString() throws IOException {
		getResponseCode();
		return resultString;
	}
	
	private void readHeaderFields() throws IOException {
		String line = null;
		headers = new HashMap<String, String>();
		
		InputStream is = httpSocket.getInputStream();
		while(true) {
			line = readLine(is);
			if(line != null) {
				Log.d(TAG, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! HEADER: " + line);
				int pos = line.indexOf(":");
				if(pos > 0) {
					String var = line.substring(0,pos++);					
					if(line.charAt(pos) == ' ') pos++;					
					String val = line.substring(pos);
					headers.put(var.toLowerCase(), val);
				} else {
					Log.d(TAG, "!! DONE");
					break;
				}
			}
		}
	}

	public String getHeaderField(String key) {
		if(headers == null) {
			try {
				readHeaderFields();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return headers.get(key);
	}

	public InputStream getInputStream() throws IOException {
		return httpSocket.getInputStream();
	}

	public void disconnect() throws IOException {
		httpSocket.close();
	}

	public void setUrl(URL url) {
		// TODO Auto-generated method stub
		
	}
	
}
