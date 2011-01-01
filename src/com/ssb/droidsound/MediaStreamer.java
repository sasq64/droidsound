package com.ssb.droidsound;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.URL;
import java.net.URLConnection;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.List;

import com.ssb.droidsound.plugins.MP3Plugin;

import android.media.MediaPlayer;
import android.media.MediaPlayer.OnPreparedListener;
import android.util.Log;

public class MediaStreamer implements Runnable {
	private static final String TAG = MediaStreamer.class.getSimpleName();
	
	public volatile boolean doQuit;
	public volatile int socketPort;
	
	private volatile boolean started;
	private volatile boolean prepared;
	private volatile boolean loaded;
	
	//private String httpName;
	private String streamTitle;
	
	private List<String> httpNames;

	private MediaPlayer mediaPlayer;
	
	private boolean newMeta;
	
	public MediaStreamer(String http, MediaPlayer mp) {
		//httpName = http;
		mediaPlayer = mp;
		httpNames = new ArrayList<String>();
		httpNames.add(http);			
		socketPort = -1;
	}
	
	public MediaStreamer(List<String> https, MediaPlayer mp) {
		
		mediaPlayer = mp;
		
		httpNames = new ArrayList<String>();
		for(String s : https)
			httpNames.add(s);			
		socketPort = -1;
	}

	void httpStream() throws IOException {

		
		for(String httpName : httpNames) {
			
			URL url = new URL(httpName);
			//if(songName.toUpperCase().endsWith(".MP3"))
			//	break;
	
			Log.v(TAG, "Opening URL " + httpName);
	
			URLConnection conn = url.openConnection();
			if (!(conn instanceof HttpURLConnection))
				throw new IOException("Not a HTTP connection");
	
			HttpURLConnection httpConn = (HttpURLConnection) conn;
			httpConn.setAllowUserInteraction(false);
			httpConn.setInstanceFollowRedirects(true);
			httpConn.setRequestMethod("GET");
			httpConn.addRequestProperty("Icy-MetaData", "1");
	
			Log.v(TAG, "Connecting");
	
			httpConn.connect();
	
			int response = httpConn.getResponseCode();
			if (response == HttpURLConnection.HTTP_OK) {
				
				int metaInterval = -1;

				String icy = httpConn.getHeaderField("icy-metaint");
				if(icy != null) {
					metaInterval = Integer.parseInt(icy);
				}

				Log.v(TAG, String.format("META INTERVAL %d", metaInterval));
				
				ServerSocket serverSocket = new ServerSocket(0);
				socketPort = serverSocket.getLocalPort();
				Log.v(TAG, String.format("Accepting on port %d", socketPort));
				Socket socket = serverSocket.accept();
			
				Log.v(TAG, String.format("Got connection from %s", socket.getInetAddress().getHostName()));
				
				//SocketChannel channel = socket.getChannel();
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
				
				String s = "HTTP/1.0 200 OK\r\n\r\n";
				os.write(s.getBytes());	
				
				int size;
				byte[] bufArray = new byte[128*1024];
				
				byte [] metaArray = new byte[4092];
				int metaPos = 0;
				int metaSize = 0;
				                             
				
				//ByteBuffer zeroes = ByteBuffer.allocateDirect(2048);
				//for(int i=0; i<2048; i++)
				//	zeroes.put(i, (byte) -1);
				
				ByteBuffer buffer = ByteBuffer.wrap(bufArray);
				
				Log.v(TAG, "HTTP connected");
				
				InputStream in = httpConn.getInputStream();
				
				int total = 0;
				metaSize = -1;
				
				while (!doQuit) {
						
					if(total == metaInterval) {
						
						
						int rem;
						if(metaSize == -1)
							rem = 1;
						else
							rem = metaSize - metaPos;
						size = in.read(metaArray, metaPos, rem);
						metaPos += size;

						Log.v(TAG, String.format("Read %d META bytes", size));

						
						if(metaPos == metaSize) {
							String data =  new String(metaArray, 1, metaSize-1);
							Log.v(TAG, "META DONE: " + data);
							int startPos = data.indexOf("StreamTitle='");
							if(startPos >= 0) {
								startPos += 13;
								int endPos = data.lastIndexOf('\'');
								if(endPos > startPos) {
									streamTitle = data.substring(startPos, endPos);
									newMeta = true;
								}
							}
							
							total = 0;
							metaPos = 0;
							metaSize = -1;
							continue;
						}
						
						if(metaPos > 0) {
							metaSize = (metaArray[0] * 16) + 1;
							Log.v(TAG, String.format("META SIZE %d", metaSize-1));
							if(metaSize == 1) {
								total = 0;
								metaPos = 0;
								metaSize = -1;
								continue;
							}
						}						
						
					} else {
						int rem = buffer.remaining();
						if(metaInterval > 0) {
							int toNextMeta = metaInterval - total;
							if(toNextMeta < rem) rem = toNextMeta;
						}						
						//Log.v(TAG, String.format("TO NEXT META %d", toNextMeta)); 
						
						size = in.read(bufArray, buffer.position(), rem);
						buffer.position(buffer.position() + size);
						
						total += size;
						
						if(total == metaInterval)
							Log.v(TAG, "META TIME");
						
					}
					
					os.write(bufArray, 0, buffer.position());
					buffer.clear();
				}
				
				socket.close();
				serverSocket.close();
				httpConn.disconnect();
	
			} else {
				Log.v(TAG, String.format("Connection failed: %d", response));
				continue;
			}
			break;
		}
		
		Log.v(TAG, "THREAD ENDING");
		doQuit = false;			
	}
	
	public int update() {
		
		if(socketPort < 0)
			return 0;
		
		if(!loaded) {
			try {
				mediaPlayer.setDataSource(String.format("http://127.0.0.1:%d/", socketPort));
				loaded = true;
				Log.v(TAG, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PREPARING ");
				mediaPlayer.setOnPreparedListener(new OnPreparedListener() {
					@Override
					public void onPrepared(MediaPlayer mp) {
						prepared = true;
					}
				});
				mediaPlayer.prepareAsync();
			} catch (IllegalArgumentException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IllegalStateException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		if(!prepared) {
			Log.v(TAG, "-------- Not prepared yet");
			return 0;
		}
		
		if(!started) {			
			Log.v(TAG, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> STARTING ");
			mediaPlayer.start();
			started = true;
		}
		
		int rc = mediaPlayer.getCurrentPosition();
		Log.v(TAG, ">>>>>>>>>> POS " + rc);
		return rc;
	}	

	@Override
	public void run() {
		try {
			httpStream();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public boolean checkNewMeta() {
		boolean rc = newMeta;
		newMeta = false;
		return rc;
	}

	public String getStreamTitle() {
		return streamTitle;
	}
}
