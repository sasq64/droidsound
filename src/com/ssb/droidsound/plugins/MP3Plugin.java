package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.IOException;
import java.util.List;

import android.media.MediaPlayer;
import android.media.MediaPlayer.OnPreparedListener;

import com.ssb.droidsound.MediaStreamer;
import com.ssb.droidsound.file.FileSource;
import com.ssb.droidsound.utils.CueFile;
import com.ssb.droidsound.utils.ID3Tag;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.M3UParser;
import com.ssb.droidsound.utils.PLSParser;
import com.ssb.droidsound.utils.PlaylistParser;

public class MP3Plugin extends DroidSoundPlugin {
	private static final String TAG = MP3Plugin.class.getSimpleName();

	private MediaPlayer mediaPlayer;
	private volatile boolean started;
	private volatile boolean prepared;
	private volatile boolean loaded;

	private MediaStreamer streamer;

	// Details
	
	private String songTitle;
	private String songComposer;
	private int songLength;

	private String songAlbum;
	private String songTrack;
	private String songGenre;
	private String songComment;
	private String songCopyright;
	private String songYear;
	
	private ID3Tag id3Tag;
	private CueFile cueFile;
	private int currentSong;

	private Thread httpThread;

	private String description;

	private String type;

	public static boolean simpleStream = false;

	@Override
	public boolean canHandle(FileSource fs) {		
		String ext = fs.getExt();
		Log.d(TAG, "Checking ext '%s'", ext);
		return ext.equals("MP3") || ext.equals("M3U") || ext.equals("PLS");
	}
	
	@Override
	public void getDetailedInfo(List<String> info) {
		
		if(streamer != null) {
			streamer.getDetailedInfo(info);
			return;
		}

		Log.d(TAG, "getDetailedInfo");
		
		info.add("Format");
		info.add("MP3");
		
		if(songAlbum != null && songAlbum.length() > 0) {
			info.add("Album");
			info.add(songAlbum);
		}
		if(songTrack != null && songTrack.length() > 0) {
			info.add("Track");
			info.add(songTrack);
		}
		if(songGenre != null && songGenre.length() > 0) {
			info.add("Genre");
			info.add(songGenre);
		}
		if(songComment != null && songComment.length() > 0) {
			info.add("Comment");
			info.add(songComment);
		}		
	}

	@Override
	public int getIntInfo(int what) {
		// TODO Auto-generated method stub
		if(what == 1000)
			return 1;

		switch(what) {
		case INFO_DETAILS_CHANGED:
			if(streamer != null) {
				if(streamer.checkNewMeta()) {
					songTitle = streamer.getStringInfo(DroidSoundPlugin.INFO_TITLE);
					songComposer = streamer.getStringInfo(DroidSoundPlugin.INFO_AUTHOR);
					songLength = streamer.getIntInfo(DroidSoundPlugin.INFO_LENGTH);
					Log.d(TAG, " NEW META %s %s %d", songTitle, songComposer, songLength);
					return 1;
				}
			}
			return 0;
		case 203:
			if(streamer != null) {
				return streamer.getLatency();
			}
			return -1;
		case 204:
			return (streamer != null && streamer.isBufferDone() ? 1 : 0);
		case INFO_LENGTH:
			if(songLength > 0) return songLength;
			if(mediaPlayer != null) {
				if(started)
					return mediaPlayer.getDuration();
				else
					return 0 * 1000;
			}
			break;
		case INFO_SUBTUNE_COUNT:
			if(cueFile != null) {
				return cueFile.getTrackCount();
			}
			break;
		case INFO_SUBTUNE_NO:			
			int pos = 0;
			if(started)
				pos = mediaPlayer.getCurrentPosition();
			if(cueFile != null) {
				currentSong = cueFile.trackFromPos(pos);
				// Log.d(TAG, String.format("TRACK FROM POS %d => %d", pos,
				// currentSong));
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
		case INFO_AUTHOR:
			return songComposer;
		case INFO_TITLE:
			return songTitle;
		case INFO_COPYRIGHT:
			return songCopyright;			
		case INFO_TYPE:
			return type;
		case 102:
			return description;
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
		return null;
	}

	@Override
	public int getSoundData(short[] dest, int size) {

		if(streamer != null) {
			return streamer.update();
		}

		if(!prepared) {
			Log.d(TAG, "-------- Not prepared yet");
			return 0;
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
	
	void clearInfo() {
		songAlbum = null;
		songComment = null;
		songComposer = null;
		songCopyright = null;
		songGenre = null;
		songLength = -1;
		songTitle = null;
		songTrack = null;
		songYear = null;
	}
	
	//@Override
	public boolean loadStream(String songName) throws IOException {

		currentSong = -1;
		description = null;
		clearInfo();

		prepared = false;
		started = false;
		loaded = false;
			
		if(simpleStream) {
			Log.d(TAG, "LOAD %s", songName);
			mediaPlayer = new MediaPlayer();
			mediaPlayer.setDataSource(songName);
			loaded = true;
			mediaPlayer.setOnPreparedListener(new OnPreparedListener() {
				@Override
				public void onPrepared(MediaPlayer mp) {
					prepared = true;
				}
			});
			mediaPlayer.prepareAsync();
			prepared = false;
		} else {
			if(httpThread == null) {
				mediaPlayer = new MediaPlayer();
				Log.d(TAG, "Creating thread");
				streamer = new MediaStreamer(songName , mediaPlayer, true);
				httpThread = new Thread(streamer);
				httpThread.start();
			}
			Log.d(TAG, "LOAD %s", songName);
			id3Tag = null;
			cueFile = null;
		}
		return true;
	}

	@Override
	public boolean load(FileSource fs) {
		
		String ref = fs.getReference();
		
		if(ref.toLowerCase().startsWith("http"))
			try {
				return loadStream(ref);
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		
		currentSong = -1;
		description = null;
		clearInfo();

		prepared = false;
		started = false;
		loaded = false;
		songLength = -1;
		
		File file = fs.getFile();

		PlaylistParser pls = null;
		type = "MP3";
		if(file.getName().toUpperCase().endsWith(".M3U")) {
			pls = new M3UParser(file);
			type = "M3U";
		} else if(file.getName().toUpperCase().endsWith(".PLS")) {
			pls = new PLSParser(file);
			type = "PLS";
		}
		
		if(pls != null) {
			if(pls.getMediaCount() > 0) {

				if(simpleStream) {
					Log.d(TAG, "LOAD %s", pls.getMedia(0));
					description = pls.getDescription(0);
					mediaPlayer = new MediaPlayer();
					try {
						mediaPlayer.setDataSource(pls.getMedia(0));
					} catch (IllegalArgumentException e) {
						e.printStackTrace();
					} catch (SecurityException e) {
						e.printStackTrace();
					} catch (IllegalStateException e) {
						e.printStackTrace();
					} catch (IOException e) {
						e.printStackTrace();
					}
					loaded = true;
					mediaPlayer.setOnPreparedListener(new OnPreparedListener() {
						@Override
						public void onPrepared(MediaPlayer mp) {
							prepared = true;
						}
					});
					mediaPlayer.prepareAsync();
					prepared = false;
				} else {
					try {
						if(httpThread == null) {
							mediaPlayer = new MediaPlayer();
							Log.d(TAG, "Creating thread");
							streamer = new MediaStreamer(pls.getMediaList(), mediaPlayer, false);
							description = pls.getDescription(0);
							httpThread = new Thread(streamer);
							// httpThread.setPriority(Thread.MAX_PRIORITY);
							httpThread.start();
						}

						Log.d(TAG, "LOAD %s", pls.getMedia(0));
						// mediaPlayer.setLooping(true);
						id3Tag = null;
						cueFile = null;

					} catch (Exception e) {
						e.printStackTrace();
						return false;
					}
				}
				return true;
			}
		}	

		try {
			Log.d(TAG, "LOAD %s", file.getPath());
			mediaPlayer = new MediaPlayer();
			mediaPlayer.setDataSource(file.getPath());
			loaded = true;
			mediaPlayer.prepare();
			prepared = true;			
			mediaPlayer.start();
			started = true;
			
			id3Tag = new ID3Tag(file);
			
			songAlbum = id3Tag.getStringInfo(ID3Tag.ID3INFO_ALBUM);
			songTrack = id3Tag.getStringInfo(ID3Tag.ID3INFO_TRACK);
			songGenre = id3Tag.getStringInfo(ID3Tag.ID3INFO_GENRE);
			songComment = id3Tag.getStringInfo(ID3Tag.ID3INFO_COMMENT);
			songTitle = id3Tag.getStringInfo(INFO_TITLE);
			songComposer = id3Tag.getStringInfo(INFO_AUTHOR);
			songCopyright = id3Tag.getStringInfo(INFO_COPYRIGHT);

			int x = file.getPath().lastIndexOf('.');
			String cueName = file.getPath().substring(0, x) + ".cue";

			Log.d(TAG, "CUENAME %s", cueName);
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

	@Override
	public boolean loadInfo(FileSource fs)  {

		File file = fs.getFile();
		Log.d(TAG, "LoadInfo %s", file.getPath());
		type = "MP3";
		if(file.getName().toUpperCase().endsWith(".M3U")) {
			id3Tag = null;
			//M3UParser m3u = new M3UParser(file);
			type = "M3U";
			return true;
		} else if(file.getName().toUpperCase().endsWith(".PLS")) {
			id3Tag = null;
			//PLSParser pls = new PLSParser(file);
			type = "PLS";
			return true;
		}

		id3Tag = new ID3Tag(file);
		return true;
	}

	@Override
	public void close() {
		Log.d(TAG, "CLOSE MP3");

		started = false;

		if(mediaPlayer != null) {
			mediaPlayer.stop();
			mediaPlayer.release();
			mediaPlayer = null;
		}

		if(streamer != null) {
			streamer.quit();
			httpThread = null;
			int counter = 10;
			while((!streamer.hasQuit()) && counter > 0) {

				try {
					Thread.sleep(100);
				} catch (InterruptedException e) {
				}
				counter--;
			}
			streamer = null;
		}

		id3Tag = null;
		cueFile = null;
	}
	
	@Override
	public void unload() {
		
		Log.d(TAG, "UNLOAD MP3");

		started = false;

		if(mediaPlayer != null) {
			mediaPlayer.stop();
			mediaPlayer.release();
			mediaPlayer = null;
		}

		if(streamer != null) {
			streamer.quit();
			httpThread = null;
			int counter = 10;
			while((!streamer.hasQuit()) && counter > 0) {

				try {
					Thread.sleep(100);
				} catch (InterruptedException e) {
				}
				counter--;
			}
			streamer = null;
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
	
	@Override
	public boolean delayedInfo() {
		return (!started);
	}

	@Override
	public void setOption(String opt, Object val) {

		// if(opt.equals("simplestream"))
		simpleStream = (Boolean) val;
		Log.d(TAG, "Simple Streaming %s", simpleStream ? "ON" : "OFF");
	}

}
