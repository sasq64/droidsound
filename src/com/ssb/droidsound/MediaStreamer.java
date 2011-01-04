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

import com.ssb.droidsound.utils.StreamingHttpConnection;

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
	
	
	//public volatile int socketPort;
	
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

	private long last_usec;

	private int lastPos = 0;

	private String icyDesc;
	private String icyGenre;
	private String icyName;
	private String icyUrl;
	private String icyBitrate;

	//private ServerSocket serverSocket;
	//private Socket socket;

	private LocalMPConnection localMPConnection;
	
	private static final int bitRateTab[] = new int [] {0,32,40,48,56,64,80,96,112,128,160,192,224,256,320,0};
	
	public MediaStreamer(String http, MediaPlayer mp) {
		//httpName = http;
		mediaPlayer = mp;
		httpNames.add(http);			
		//socketPort = -1;
	}
	
	public MediaStreamer(List<String> https, MediaPlayer mp) {
		
		mediaPlayer = mp;
		for(String s : https)
			httpNames.add(s);			
		//socketPort = -1;
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

		localMPConnection = null;
		
		for(int httpNo=0; httpNo < httpNames.size(); httpNo++) {

			boolean parseMp3 = false;
			boolean doRetry = false;

			String httpName = httpNames.get(httpNo);
			URL url = new URL(httpName);
	
			Log.v(TAG, "Opening URL " + httpName);
				
			StreamingHttpConnection httpConn = new StreamingHttpConnection(url);
			/*URLConnection conn = url.openConnection();
			if (!(conn instanceof HttpURLConnection))
				throw new IOException("Not a HTTP connection");
			HttpURLConnection httpConn = (HttpURLConnection) conn; */
			
			httpConn.setAllowUserInteraction(false);
			httpConn.setInstanceFollowRedirects(true);
			httpConn.setRequestMethod("GET");
			httpConn.addRequestProperty("Icy-MetaData", "1");
	
			Log.v(TAG, "Connecting");	
			httpConn.connect();
	
			int response = httpConn.getResponseCode();			
			//Log.v(TAG, String.format("RESPONSE %d %s", response, httpConn.getResponseMessage()));
			
			if (response == HttpURLConnection.HTTP_OK) {
				Log.v(TAG, "HTTP connected");
				
				int metaInterval = -1;
								
				icyDesc = httpConn.getHeaderField("icy-description");
				icyGenre = httpConn.getHeaderField("icy-genre");
				icyName = httpConn.getHeaderField("icy-name");
				icyUrl = httpConn.getHeaderField("icy-url");
				icyBitrate = httpConn.getHeaderField("icy-br");
				
				String contentType = httpConn.getHeaderField("content-type");
				
				if(contentType.trim().startsWith("audio/mp"))
					parseMp3 = true;
				
				String icy = httpConn.getHeaderField("icy-metaint");
				if(icy != null) {
					metaInterval = Integer.parseInt(icy);
				}

				Log.v(TAG, String.format("META INTERVAL %d", metaInterval));
				
				if(localMPConnection == null) {
					localMPConnection = new LocalMPConnection();
					localMPConnection.setContentType(contentType);
					localMPConnection.accept();
				}

				int size;
				byte[] head = new byte[4];
				byte[] buffer = new byte[128*1024];
				byte [] metaArray = new byte[4092];
				int metaPos = 0;
				int metaSize = -1;				
				int metaCounter = 0;
				long total = 0;
				int hf = 0;
				boolean firstRead = true;

				last_usec = usec = 0L;
				nextFramePos = -1;
				hasQuit = false;
				
				InputStream in = httpConn.getInputStream();

				if(!parseMp3)
					usec = -1000;

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
							String meta =  new String(metaArray, 1, metaSize-1);
							Log.v(TAG, "META DONE: " + meta);
							
							String split [] = meta.split(";");
							
							for(String data : split) {							
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
			
						try {
							size = in.read(buffer, 0, rem);
						} catch (IOException e) {
							Log.v(TAG, "LOST CONNECTION WITH ICECAST-SERVER");	
							httpNo--;
							doRetry = true;
							break;
						}	
						
						if(size == -1) {
							Log.v(TAG, "####### End of buffer");
							httpNo--;
							doRetry = true;
							break;
						}
						
						if(firstRead) {
							Log.v(TAG, String.format("### READ: %02x %02x %02x %02x", buffer[0], buffer[1], buffer[2], buffer[3]));
							firstRead = false;
						}
						
						if(parseMp3) {
							if(nextFramePos < 0) {
								for(int i=0; i<size-3; i++) {
									if(buffer[i] == -1 && (buffer[i+1] & 0xfe) == 0xfa  && (buffer[i+2] & 0xf0) != 0xf0) {							
										Log.v(TAG, String.format("Synced at %d", i));							
										nextFramePos = i+total;
										break;									
									}
								}
							}
							
							while(nextFramePos >= 0) {
								int o = (int) (nextFramePos - total);
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
						}
						
						metaCounter += size;						
						total += size;

						localMPConnection.write(buffer, 0, size);
						
						if(metaCounter == metaInterval)
							Log.v(TAG, "META TIME");
						
					}
					
					if(parseMp3) {
						if(usec - last_usec > 1000000) {
							Log.v(TAG, String.format("%%%%%%%%%% QUEUE POS %d msec", (int)(usec / 1000)));
							last_usec = usec;
						}
					}
					
				}
				
				if(!doRetry) {
					localMPConnection.close();
					localMPConnection = null;
				}
				httpConn.disconnect();
	
			} else {
				Log.v(TAG, String.format("Connection failed: %d", response));
				continue;
			}
			
			if(doRetry)
				continue;
			
			break;
		}
		hasQuit = true;		
		Log.v(TAG, "THREAD ENDING");
		doQuit = false;			
	}
	
	public int getLatency() {
		if(usec < 0) return -1;
		return (int) (usec/1000 - (mediaPlayer == null ? 0 : mediaPlayer.getCurrentPosition()));
	}
	
	public int update() {
		
		if(hasQuit)
			return -1;
		
		if(localMPConnection == null || !localMPConnection.isListening())
			return 0;
		
		if(!loaded) {
			try {
				localMPConnection.connect(mediaPlayer);
				//mediaPlayer.setDataSource(String.format("http://127.0.0.1:%d/", socketPort));
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
		if(rc - lastPos > 1000) {
			Log.v(TAG, String.format("########## READ POS %d msec",rc));
			lastPos  = rc;
		}
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

	public String[] getDetailedInfo() {
		
		List<String> info = new ArrayList<String>();
		if(icyName != null) {
			info.add("Name");
			info.add(icyName);
		}
		if(icyDesc != null) {
			info.add("Description");
			info.add(icyDesc);
		}
		if(icyUrl != null) {
			info.add("URL");
			info.add(icyUrl);
		}
		if(icyGenre != null) {
			info.add("Genre");
			info.add(icyGenre);
		}
		if(icyBitrate != null) {
			info.add("Bitrate");
			info.add(icyBitrate);
		}
		String[] strArray = new String[info.size()];
		info.toArray(strArray);
		return strArray;
	}
}


