package com.ssb.droidsound;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.URL;
import java.net.URLConnection;
import java.util.ArrayList;
import java.util.List;

import android.media.MediaPlayer;
import android.media.MediaPlayer.OnPreparedListener;
import android.util.Log;

public class MediaStreamer implements Runnable {
	private static final String TAG = MediaStreamer.class.getSimpleName();
	
	private static class MetaString {
		public MetaString(int m, String t) {
			msec = m;
			text = t;
		}
		public int msec;
		public String text;
	};
	
	
	public volatile int socketPort;
	
	private volatile boolean started;
	private volatile boolean prepared;
	private volatile boolean loaded;
	
	//private String httpName;
	private List<MetaString> metaStrings = new ArrayList<MetaString>();
	
	private List<String> httpNames = new ArrayList<String>();

	private MediaPlayer mediaPlayer;
	
	//private boolean newMeta;


	//private int frameSize;

	private int bitRate;
	private int freq;

	private long usec;

	private long nextFramePos;
	private String streamTitle;

	private volatile boolean hasQuit;
	private volatile boolean doQuit;

	
	private static final int bitRateTab[] = new int [] {0,32,40,48,56,64,80,96,112,128,160,192,224,256,320,0};
	
	public MediaStreamer(String http, MediaPlayer mp) {
		//httpName = http;
		mediaPlayer = mp;
		httpNames.add(http);			
		socketPort = -1;
	}
	
	public MediaStreamer(List<String> https, MediaPlayer mp) {
		
		mediaPlayer = mp;
		for(String s : https)
			httpNames.add(s);			
		socketPort = -1;
	}
	/*
	private boolean findFrame(byte [] bufArray, int pos, int size) {
		for(int i=pos; i<size-3; i++) {
			if(bufArray[i] == -1 && (bufArray[i+1] & 0xfe) == 0xfa  && (bufArray[i+2] & 0xf0) != 0xf0) {
				
				frameStart = i;
				
				//Log.v(TAG, String.format("%04x: %02x %02x %02x %02x", i, bufArray[i],bufArray[i+1],bufArray[i+2],bufArray[i+3]));
				
				bitRate = bitRateTab[(bufArray[i+2]>>4) & 0xf] * 1000;
				
				if(bitRate == 0) break;
				
				freq = 44100;
				int ff = bufArray[i+2] & 0xc;
				
				if(ff == 0xc) break;
				
				if(ff == 4) freq = 48000;
				else if(ff == 8) freq = 32000;
				
				frameSize = 144000 * bitRate / freq;
				if((bufArray[i+2] & 0x02) == 2)
					frameSize++;
				
				//Log.v(TAG, String.format("BITRATE %d, FREQ %d -> FRAMESIZE %d", bitRate, freq, frameSize));
				return true;
				
				//fileSize = frameSize*1024;
				//channel.truncate(fileSize);
			}				
		}
		return false;
	} */
	
/*
V/MediaStreamer(12369): content-type: audio/mpeg
V/MediaStreamer(12369): icy-br: 128
V/MediaStreamer(12369): ice-audio-info: ice-samplerate=44100;ice-bitrate=128;ice-channels=2
V/MediaStreamer(12369): icy-br: 128
V/MediaStreamer(12369): icy-description: Watching the scene...
V/MediaStreamer(12369): icy-genre: Demoscene Amiga C64 Various Misc
V/MediaStreamer(12369): icy-name: SceneSat Radio
V/MediaStreamer(12369): icy-pub: 1
V/MediaStreamer(12369): icy-url: http://SceneSat.com/
V/MediaStreamer(12369): server: Icecast 2.3.2
V/MediaStreamer(12369): cache-control: no-cache
V/MediaStreamer(12369): icy-metaint: 16000
*/
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
			
			//Log.v(TAG, String.format("RESPONSE %d %s", response, httpConn.getResponseMessage()));
			
			if (response == HttpURLConnection.HTTP_OK) {
				
				int metaInterval = -1;

				for(int i=1; i<100; i++) {
					String key = httpConn.getHeaderFieldKey(i);
					if(key != null) {
						Log.v(TAG, String.format("%s: %s", key, httpConn.getHeaderField(key)));
					} else
						break;
				}
				
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
				byte[] head = new byte[4];
				byte[] buffer = new byte[128*1024];
				
				byte [] metaArray = new byte[4092];
				int metaPos = 0;
				int metaSize = 0;
				                             
				
				//ByteBuffer zeroes = ByteBuffer.allocateDirect(2048);
				//for(int i=0; i<2048; i++)
				//	zeroes.put(i, (byte) -1);
				
				//ByteBuffer buffer = ByteBuffer.wrap(bufArray);
				
				Log.v(TAG, "HTTP connected");
				
				InputStream in = httpConn.getInputStream();
				
				int metaCounter = 0;
				long total = 0;
				metaSize = -1;
				usec = 0L;
				nextFramePos = -1;
				int hf = 0;
				
				hasQuit = false;
				
				while (!doQuit) {
						
					if(metaCounter == metaInterval) {
						
						
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
									//streamTitle = data.substring(startPos, endPos);
									metaStrings.add(new MetaString((int) (usec/1000), data.substring(startPos, endPos)));
									//newMeta = true;
								}
							}
							
							metaCounter = 0;
							metaPos = 0;
							metaSize = -1;
							continue;
						}
						
						if(metaPos > 0) {
							metaSize = (metaArray[0] * 16) + 1;
							Log.v(TAG, String.format("META SIZE %d", metaSize-1));
							if(metaSize == 1) {
								metaCounter = 0;
								metaPos = 0;
								metaSize = -1;
								continue;
							}
						}						
						
					} else {
						int rem = buffer.length;
						if(metaInterval > 0) {
							int toNextMeta = metaInterval - metaCounter;
							if(toNextMeta < rem) rem = toNextMeta;
						}						
						//Log.v(TAG, String.format("TO NEXT META %d", toNextMeta)); 
						
						size = in.read(buffer, 0, rem);
						
						if(size == -1) {
							Log.v(TAG, "####### End of buffer");
							break;
						}
						
						//buffer.position(buffer.position() + size);
						
						// 0 ---------------- size
						

						// nextFramePos = 1007
						// total = 1000
						// size = 8
						
						if(nextFramePos < 0) {
							for(int i=0; i<size-3; i++) {
								if(buffer[i] == -1 && (buffer[i+1] & 0xfe) == 0xfa  && (buffer[i+2] & 0xf0) != 0xf0) {
									
									Log.v(TAG, String.format("Synced at %d", i));
									
									nextFramePos = i;
									/*hf = 0xf;
									head[0] = buffer[i];
									head[1] = buffer[i+1];
									head[2] = buffer[i+2];
									head[3] = buffer[i+3]; */
									break;									
								}
							}
						}
						
						while(nextFramePos >= 0) {
							int o = (int) (nextFramePos - total);
							// o = 7
							//Log.v(TAG, String.format("NFP %d, TOTAL %d, HF %x", nextFramePos, total, hf));
							
							
							//if(o >=0 && o < size-3) {
							//	Log.v(TAG, String.format("%d: Expect frame: %02x %02x %02x %02x", nextFramePos, buffer[o], buffer[o+1], buffer[o+2], buffer[o+3]));
							//}
	
							if(o >=0 && o < size) {
								head[0] = buffer[o];
								hf |= 1;
							}
							o++;
							if(o >=0 && o < size) {
								head[1] = buffer[o];
								hf |= 2;
							}
							o++;
							if(o >=0 && o < size) {
								head[2] = buffer[o];
								hf |= 4;
							}
							o++;
							if(o >=0 && o < size) {
								head[3] = buffer[o];
								hf |= 8;
							}
							
							if(hf == 0xf) {
								//Log.v(TAG, String.format("Got frame: %02x %02x %02x %02x", head[0], head[1], head[2], head[3]));
								
								bitRate = bitRateTab[(head[2]>>4) & 0xf] * 1000;
								
								if(bitRate != 0) { 							
									freq = 44100;
									int ff = head[2] & 0xc;
									
									if(ff != 0xc) {
										
										if(ff == 4) freq = 48000;
										else if(ff == 8) freq = 32000;
										
										int frameSize = 144 * bitRate / freq;

										if((head[2] & 0x02) == 2)
											frameSize++;

										usec += frameSize * 1000 / (bitRate/8000);

										nextFramePos += frameSize;
										
										
										
										//Log.v(TAG, String.format("BITRATE %d, FREQ %d -> FRAMESIZE %d, nextFramePos = %d", bitRate, freq, frameSize, nextFramePos));
									} else nextFramePos = -1;
								} else nextFramePos = -1;
								hf = 0;
								if(nextFramePos == -1) {
									//Log.v(TAG, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
									//Log.v(TAG, "!!!!!!!!!!!!!!!!!!!!!!!! LOST SYNC !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
									Log.v(TAG, "!!!!!!!!!!!!!!!!!!!!!!!! LOST SYNC !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
									//Log.v(TAG, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
								}
							} else
								break;
						}
						
						metaCounter += size;						
						total += size;
						
						if(metaCounter == metaInterval)
							Log.v(TAG, "META TIME");
						
					}
					
					os.write(buffer, 0, size);	
					
					Log.v(TAG, String.format("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Queue pos %d msec", (int)(usec / 1000)));
					
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
		hasQuit = true;		
		Log.v(TAG, "THREAD ENDING");
		doQuit = false;			
	}
	
	public int getLatency() {
				
		return (int) (usec/1000 - (mediaPlayer == null ? 0 : mediaPlayer.getCurrentPosition()));
	}
	
	public int update() {
		
		if(hasQuit)
			return -1;
		
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
	
	public void quit() {
		doQuit = true;
	}
	
	public boolean hasQuit() {
		return hasQuit;
	}

	public boolean checkNewMeta() {
		
		if(metaStrings.size() > 0 && mediaPlayer != null) {
			MetaString ms = metaStrings.get(0);
			if(ms.msec <= mediaPlayer.getCurrentPosition()) {
				streamTitle = ms.text;
				metaStrings.remove(0);
				return true;
			}
		}
		return false;
		
	}

	public String getStreamTitle() {
		return streamTitle;
	}
}


