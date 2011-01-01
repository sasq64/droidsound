package com.ssb.droidsound.plugins;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileDescriptor;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.RandomAccessFile;
import java.lang.reflect.Array;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.URL;
import java.net.URLConnection;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.SocketChannel;
import java.util.ArrayList;
import java.util.List;

import com.ssb.droidsound.utils.CueFile;
import com.ssb.droidsound.utils.ID3Tag;
import com.ssb.droidsound.utils.M3UParser;

import android.media.MediaPlayer;
import android.util.Log;

public class MP3Plugin extends DroidSoundPlugin {
	private static final String TAG = MP3Plugin.class.getSimpleName();
	
	private MediaPlayer mediaPlayer;
	private boolean started;
	private boolean prepared;

	private Mp3Streamer streamer;
	
	private ID3Tag id3Tag;
	private CueFile cueFile;
	private int currentSong;

	private Thread httpThread;

	@Override
	public boolean canHandle(String name) {
		int x = name.lastIndexOf('.');
		String ext = name.substring(x+1).toUpperCase();
		Log.v(TAG, String.format("Checking ext '%s'", ext));
		return ext.equals("MP3") || ext.equals("M3U");
	}

	@Override
	public String[] getDetailedInfo() {

		Log.v(TAG, "GetInfo");
		if(id3Tag != null) {
			Log.v(TAG, "ID3 here");
			List<String> info = new ArrayList<String>();
			String album = id3Tag.getStringInfo(ID3Tag.ID3INFO_ALBUM);
			if(album != null && album.length() > 0) {
				info.add("Album");
				info.add(album);				
			}
			String track = id3Tag.getStringInfo(ID3Tag.ID3INFO_TRACK);
			if(track != null && track.length() > 0) {
				info.add("Track");
				info.add(track);
			}
			String genre = id3Tag.getStringInfo(ID3Tag.ID3INFO_GENRE);
			if(genre != null && genre.length() > 0) {
				info.add("Genre");
				info.add(genre);
			}
			String comment = id3Tag.getStringInfo(ID3Tag.ID3INFO_COMMENT);
			if(comment != null && comment.length() > 0) {
				info.add("Comment");
				info.add(comment);
			}
			String [] strArray = new String[info.size()];
			info.toArray(strArray);
			return strArray;
		}
		
		return null;
		
	}
	
	@Override
	public int getIntInfo(int what) {
		// TODO Auto-generated method stub
		if(what == 1000) return 1;
		
		switch(what) {
		case INFO_LENGTH:
			if(mediaPlayer != null)
				return mediaPlayer.getDuration();
		case INFO_SUBTUNE_COUNT:
			if(cueFile != null) {
				return cueFile.getTrackCount();
			}
			break;
		case INFO_SUBTUNE_NO:
			int pos = mediaPlayer.getCurrentPosition();
			if(cueFile != null) {
				currentSong = cueFile.trackFromPos(pos);
				//Log.v(TAG, String.format("TRACK FROM POS %d => %d", pos, currentSong));
			}
			return currentSong;
		}
		
		if(id3Tag != null) {
			return id3Tag.getIntInfo(what);
		}
		
		return 0;
	}
	
	@Override
	public boolean setTune(int tune) {
		currentSong = tune;
		if(mediaPlayer != null && cueFile != null && currentSong >= 0) {
			mediaPlayer.seekTo(cueFile.getTrack(currentSong).offset);
		}
		return true;
	}

	@Override
	public String getStringInfo(int what) {
		switch(what) {
		case INFO_SUBTUNE_TITLE:
			if(cueFile != null && currentSong >= 0) {
				return cueFile.getTrack(currentSong).title;
			}
			break;
		case INFO_SUBTUNE_AUTHOR:
			if(cueFile != null && currentSong >= 0) {
				return cueFile.getTrack(currentSong).performer;
			}
			break;
		}
		if(id3Tag != null) {
			return id3Tag.getStringInfo(what);
		}

		return null;
	}

	@Override
	public int getSoundData(short[] dest, int size) {
		// TODO Auto-generated method stub
		
		//Log.v(TAG, "GET SOUND DATA");
		
		if(streamer != null) {
			
			//Log.v(TAG, "STREAMER");
			//if(streamer.position < 32*1024)
			//	return 0;
			if(streamer.socketPort < 0)
				return 0;
			
			
			if(!started) {
				try {
					//FileInputStream fi = new FileInputStream(streamer.outFile);
					//mediaPlayer.setDataSource(fi.getFD());
					
					mediaPlayer.setDataSource(String.format("http://127.0.0.1:%d/", streamer.socketPort));
					Log.v(TAG, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PREPARING ");
					mediaPlayer.prepare();
					Log.v(TAG, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PREPARE DONE ");
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
				//mediaPlayer.start();
				Log.v(TAG, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> STARTING ");
				mediaPlayer.start();
				started = true;
			}
			
			int rc = mediaPlayer.getCurrentPosition();
			Log.v(TAG, ">>>>>>>>>> POS " + rc);
			return rc;
		}
		
		if(!started) {
			mediaPlayer.start();
			started = true;
		}
		
		if(!mediaPlayer.isPlaying())
			return -1;
		
		return mediaPlayer.getCurrentPosition();
	}
	
	@Override
	public boolean seekTo(int msec) {
		mediaPlayer.seekTo(msec);
		return true;
	}


	@Override
	public boolean load(String name, byte[] module, int size) {
		currentSong = -1;
		return false;
	}

	private static class Mp3Streamer implements Runnable {

		private volatile boolean doQuit;
		public volatile File outFile;
		public volatile int position;
		public volatile int socketPort;

		private String httpName;
		//private FileChannel channel;
		private int fileSize;
		private int frameSize;
		private int frameStart;
		private String streamTitle;
		
		private static final int bitRateTab[] = new int [] {0,32,40,48,56,64,80,96,112,128,160,192,224,256,320,0};

		
		public Mp3Streamer(String httpName) {
			this.httpName = httpName;
			socketPort = -1;
			frameSize = 0;
			/*
			File f;
			try {
				//f = File.createTempFile("stream", null);
				f = new File("/sdcard/STREAMTEMP");
				RandomAccessFile ra = new RandomAccessFile(f, "rwd");			
				channel = ra.getChannel();
				fileSize = 256*1024;
				channel.truncate(fileSize);
				//byte [] inbuffer = new 
				channel.position(0);
				position = 0;				
				outFile = f;
				f.deleteOnExit();
				Log.v(TAG, "Created " + f.getPath());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} */
			
		}
		
		private boolean findFrame(byte [] bufArray, int pos, int size) {
			for(int i=pos; i<size-3; i++) {
				if(bufArray[i] == -1 && (bufArray[i+1] & 0xfe) == 0xfa  && (bufArray[i+2] & 0xf0) != 0xf0) {
					
					frameStart = i;
					
					// Log.v(TAG, String.format("%04x: %02x %02x %02x %02x", i, bufArray[i],bufArray[i+1],bufArray[i+2],bufArray[i+3]));
					
					int bitRate = bitRateTab[(bufArray[i+2]>>4) & 0xf];
					
					if(bitRate == 0) break;
					
					int freq = 44100;
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
		}
		
		
		void httpStream(String httpName) throws IOException {
	
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
				
				String icy = httpConn.getHeaderField("icy-metaint");
								
				int metaInterval = Integer.parseInt(icy);

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
				
				String s = "HTTP/1.0 200 OK\n\n";
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

				int offs = 0;
				
				ID3Tag id3 = new ID3Tag();
				
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
						int toNextMeta = metaInterval - total;
						if(toNextMeta < rem) rem = toNextMeta;
						
						Log.v(TAG, String.format("TO NEXT META %d", toNextMeta)); 
						
						size = in.read(bufArray, buffer.position(), rem);
						buffer.position(buffer.position() + size);
						
						total += size;
						
						if(total == metaInterval)
							Log.v(TAG, "META TIME");
						
					}
					
					//if(total >= toNextMeta) {
					//	
					//}
				
					/// 0 ---- pos ----- limit --------- capacity
					
					while(findFrame(bufArray, 0, buffer.position())) {
						if(frameStart + frameSize < buffer.position()) {
							
							
							//Log.v(TAG, String.format("Full frame, %d bytes at %d", frameSize, frameStart));

							//ByteBuffer bb = buffer.duplicate();
							//bb.position(frameStart);
							//bb.limit(frameStart + frameSize);
							
							/*
							if(fileSize - channel.position() < frameSize) {
								Log.v(TAG, String.format("############################################# Wrapping at pos %d, %d bytes left", channel.position(), fileSize - channel.position()));
								
								
								zeroes.position(0);
								zeroes.limit((int) (fileSize - channel.position()));
								channel.write(zeroes);
								//channel.truncate(channel.position());
								channel.position(0);
							} */
											
							os.write(bufArray, frameStart, frameSize);
							//Log.v(TAG, String.format("Wrote %d + %d", frameStart, frameSize));
							// channel.write(bb);
							// position = (int) channel.position();
							//Log.v(TAG, String.format("File pos %d", position));
							
							//buffer.flip();							
							//Log.v(TAG, String.format("Before changing %d -> %d", buffer.position(), buffer.limit()));							

							buffer.limit(buffer.position());
							buffer.position(frameStart + frameSize);	
							
							//Log.v(TAG, String.format("Before compacting %d -> %d", buffer.position(), buffer.limit()));							

							buffer.compact();
							//Log.v(TAG, String.format("After compacting %d -> %d", buffer.position(), buffer.limit()));							
						} else
							break;
					}
				}
	
			} else {
				Log.v(TAG, String.format("Connection failed: %d", response));
			}
		}

		@Override
		public void run() {
			try {
				httpStream(httpName);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	
	@Override
	public boolean load(File file) throws IOException {
		currentSong = -1;
				
		if(file.getName().toUpperCase().endsWith(".M3U")) {
			M3UParser m3u = new M3UParser(file);
			if(m3u.getMediaCount() > 0) {

				try {
					
					
			    	if(httpThread == null) {
						Log.v(TAG, "Creating thread");
						streamer = new Mp3Streamer(m3u.getMedia(0));
						httpThread = new Thread(streamer);
						//httpThread.setPriority(Thread.MAX_PRIORITY);
						httpThread.start();
			    	}

					Log.v(TAG, String.format("LOAD %s", m3u.getMedia(0)));
					mediaPlayer = new MediaPlayer();
					//mediaPlayer.setLooping(true);
					id3Tag = null;
					cueFile = null;
					/*
					id3Tag = new ID3Tag(file);
					
					
					int x = file.getPath().lastIndexOf('.');
					String cueName = file.getPath().substring(0, x) + ".cue";
					
					Log.v(TAG, String.format("CUENAME %s", cueName));
					currentSong = 0;
					cueFile = new CueFile(new File(cueName));
					if(cueFile.getTrackCount() <= 0) {
						cueFile = null;
					} */
				} catch (Exception e) {
					e.printStackTrace();
					return false;
				}
				return true;
			}
		}
		
		try {
			Log.v(TAG, String.format("LOAD %s", file.getPath()));
			mediaPlayer = new MediaPlayer();
			mediaPlayer.setDataSource(file.getPath());
			mediaPlayer.prepare();
			id3Tag = new ID3Tag(file);
			
			
			int x = file.getPath().lastIndexOf('.');
			String cueName = file.getPath().substring(0, x) + ".cue";
			
			Log.v(TAG, String.format("CUENAME %s", cueName));
			currentSong = 0;
			cueFile = new CueFile(new File(cueName));
			if(cueFile.getTrackCount() <= 0) {
				cueFile = null;
			}
		} catch (IOException e) {
			return false;
		}
		
		// TODO Auto-generated method stub
		return true;
	}
	
	public boolean loadInfo(File file) throws IOException {
		
		Log.v(TAG, String.format("LoadInfo %s", file.getPath()));
		if(file.getName().toUpperCase().endsWith(".M3U")) {
			id3Tag = null;
			return true;
		}
		
		id3Tag = new ID3Tag(file);
		return true;
	}
	
	@Override
	public void unload() {
		// TODO Auto-generated method stub
		started = false;
		if(mediaPlayer != null) {
			mediaPlayer.stop();
			mediaPlayer.release();
			mediaPlayer = null;
		}	
		id3Tag = null;
		cueFile = null;
	}
	
	@Override
	public boolean canSeek() {
		return (id3Tag != null);
	}
	
	@Override
	public MediaPlayer getMediaPlayer() {
		return mediaPlayer;
	}

}
