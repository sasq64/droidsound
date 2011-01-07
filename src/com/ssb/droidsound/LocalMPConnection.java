package com.ssb.droidsound;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

import android.media.MediaPlayer;
import android.util.Log;

public class LocalMPConnection {
	private static final String TAG = LocalMPConnection.class.getSimpleName();
	private ServerSocket serverSocket;
	private volatile int socketPort;
	private Socket socket;
	private String contentType;
	
	public LocalMPConnection() throws IOException {
		serverSocket = new ServerSocket(0);
		socketPort = serverSocket.getLocalPort();
		contentType = "audio/mpeg";
	}
	
	public void accept() throws IOException {
		
		Log.v(TAG, String.format("Accepting on port %d", socketPort));
		socket = serverSocket.accept();
		
		OutputStream os = socket.getOutputStream();
		InputStream is = socket.getInputStream();

		byte [] temp = new byte [2048];
		
		int bsize = -1;
		while(bsize <= 0) {
			bsize = is.read(temp);
			//Log.v(TAG, String.format("Got %d bytes", bsize));
		}
		String res = new String(temp, 0, bsize);
		Log.v(TAG, String.format("Got '%s'", res));
		
		//Log.v(TAG, String.format("CONTENT TYPE '%s'", contentType));

		String s = String.format("HTTP/1.1 200 OK\r\ncontent-type: %s\r\n\r\n", contentType);
		os.write(s.getBytes());	
	}
	
	
	public boolean isListening() {
		return (socketPort >= 0);
	}
	
	public void write(byte [] buffer, int offset, int size) throws IOException {
		socket.getOutputStream().write(buffer, offset, size);
	}
	
	
	public void connect(MediaPlayer mp) throws IllegalArgumentException, IllegalStateException, IOException {		
		mp.setDataSource(String.format("http://127.0.0.1:%d/", socketPort));
	}

	public void close() throws IOException {
		socket.close();
		serverSocket.close();
		
	}

	public void setContentType(String ct) {
		contentType = ct;
	}

}
