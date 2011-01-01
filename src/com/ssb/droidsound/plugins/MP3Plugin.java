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

	public static boolean simpleStream = false;

	@Override
	public boolean canHandle(String name) {
		int x = name.lastIndexOf('.');
		String ext = name.substring(x + 1).toUpperCase();
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
			String[] strArray = new String[info.size()];
			info.toArray(strArray);
			return strArray;
		}

		return null;

	}

	@Override
	public int getIntInfo(int what) {
		// TODO Auto-generated method stub
		if(what == 1000)
			return 1;

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
	public boolean load(File file) throws IOException {
		currentSong = -1;
		description = null;

		prepared = false;
		started = false;
		loaded = false;

		if(file.getName().toUpperCase().endsWith(".M3U")) {
			M3UParser m3u = new M3UParser(file);
			if(m3u.getMediaCount() > 0) {

				if(simpleStream) {
					Log.v(TAG, String.format("LOAD %s", m3u.getMedia(0)));
					description = m3u.getDescription(0);
					mediaPlayer = new MediaPlayer();
					mediaPlayer.setDataSource(m3u.getMedia(0));
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
							streamer = new MediaStreamer(m3u.getMediaList(), mediaPlayer);
							description = m3u.getDescription(0);
							httpThread = new Thread(streamer);
							// httpThread.setPriority(Thread.MAX_PRIORITY);
							httpThread.start();
						}

						Log.v(TAG, String.format("LOAD %s", m3u.getMedia(0)));
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
		if(file.getName().toUpperCase().endsWith(".M3U")) {
			id3Tag = null;
			M3UParser m3u = new M3UParser(file);

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
			streamer.doQuit = true;
			httpThread = null;
			int counter = 10;
			while(streamer.doQuit && counter > 0) {

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
