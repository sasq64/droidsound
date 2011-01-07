package com.ssb.droidsound.plugins;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import android.media.MediaPlayer;
import android.media.MediaPlayer.OnPreparedListener;
import android.util.Log;

import com.ssb.droidsound.MediaStreamer;
import com.ssb.droidsound.utils.CueFile;
import com.ssb.droidsound.utils.ID3Tag;
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

	private ID3Tag id3Tag;
	private CueFile cueFile;
	private int currentSong;

	private Thread httpThread;

	private String description;

	private String type;

	public static boolean simpleStream = false;

	@Override
	public boolean canHandleExt(String ext) {		
		ext = ext.toUpperCase();
		Log.v(TAG, String.format("Checking ext '%s'", ext));
		return ext.equals(".MP3") || ext.equals(".M3U") || ext.equals(".PLS");
	}

	@Override
	public String[] getDetailedInfo() {

		Log.v(TAG, "getDetailedInfo");
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
			String[] strArray = new String[info.size()];
			info.toArray(strArray);
			return strArray;
		} else if(streamer != null) {
			return streamer.getDetailedInfo();
		}

		return null;

	}

	@Override
	public int getIntInfo(int what) {
		// TODO Auto-generated method stub
		if(what == 1000)
			return 1;

		switch(what) {
		case 203:
			if(streamer != null) {
				return streamer.getLatency();
			}
			return -1;
		case INFO_LENGTH:
			if(mediaPlayer != null && streamer == null) {
				if(started)
					return mediaPlayer.getDuration();
				else
					return 0;
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
				// Log.v(TAG, String.format("TRACK FROM POS %d => %d", pos,
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
		case 101:
			if(streamer != null) {
				if(streamer.checkNewMeta()) {
					return streamer.getStreamTitle();
				}
			}
			return null;
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
		if(id3Tag != null) {
			return id3Tag.getStringInfo(what);
		}

		return null;
	}

	@Override
	public int getSoundData(short[] dest, int size) {

		if(streamer != null) {
			return streamer.update();
		}

		if(!prepared) {
			Log.v(TAG, "-------- Not prepared yet");
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

	@Override
	public boolean load(String name, byte[] module, int size) {
		currentSong = -1;
		return false;
	}
	
	@Override
	public boolean loadStream(String songName) throws IOException {

		currentSong = -1;
		description = null;

		prepared = false;
		started = false;
		loaded = false;
			
		if(simpleStream) {
			Log.v(TAG, String.format("LOAD %s", songName));
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
				Log.v(TAG, "Creating thread");
				streamer = new MediaStreamer(songName , mediaPlayer);
				httpThread = new Thread(streamer);
				httpThread.start();
			}
			Log.v(TAG, String.format("LOAD %s", songName));
			id3Tag = null;
			cueFile = null;
		}
		return true;
	}

	@Override
	public boolean load(File file) throws IOException {
		currentSong = -1;
		description = null;

		prepared = false;
		started = false;
		loaded = false;

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
					Log.v(TAG, String.format("LOAD %s", pls.getMedia(0)));
					description = pls.getDescription(0);
					mediaPlayer = new MediaPlayer();
					mediaPlayer.setDataSource(pls.getMedia(0));
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
							Log.v(TAG, "Creating thread");
							streamer = new MediaStreamer(pls.getMediaList(), mediaPlayer);
							description = pls.getDescription(0);
							httpThread = new Thread(streamer);
							// httpThread.setPriority(Thread.MAX_PRIORITY);
							httpThread.start();
						}

						Log.v(TAG, String.format("LOAD %s", pls.getMedia(0)));
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
			Log.v(TAG, String.format("LOAD %s", file.getPath()));
			mediaPlayer = new MediaPlayer();
			mediaPlayer.setDataSource(file.getPath());
			loaded = true;
			mediaPlayer.prepare();
			prepared = true;
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
	public void unload() {
		// TODO Auto-generated method stub
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
	public void setOption(String opt, Object val) {

		// if(opt.equals("simplestream"))
		simpleStream = (Boolean) val;
		Log.v(TAG, String.format("Simple Streaming %s", simpleStream ? "ON" : "OFF"));
	}

}
