package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLDecoder;
import java.nio.channels.FileChannel;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.app.SearchManager;
import android.content.BroadcastReceiver;
import android.content.ContentValues;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.database.Cursor;
import android.database.CursorWrapper;
import android.database.sqlite.SQLiteDatabase;
import android.media.AudioManager;
import android.media.RingtoneManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.os.PowerManager;
import android.preference.PreferenceManager;
import android.provider.MediaStore;
import android.speech.tts.TextToSpeech;
import android.text.Html;
import android.text.InputType;
import android.text.method.ScrollingMovementMethod;
import android.util.SparseArray;
import android.view.ContextMenu;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.widget.AdapterView;
import android.widget.AdapterView.AdapterContextMenuInfo;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ViewFlipper;

import com.ssb.droidsound.database.CSDBParser;
import com.ssb.droidsound.database.MediaSource;
import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.playlistview.FileInfo;
import com.ssb.droidsound.playlistview.PlayListView;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.service.PlayerService;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.Unzipper;

public class PlayerActivity extends Activity implements PlayerServiceConnection.Callback {
	private static final String TAG = "PlayerActivity";
	public static final int VERSION = 17;

	private static class Config {
		int ttsStatus;
		SearchCursor searchCursor;
		String activePlaylist;
		String query;
		int flipper;
		boolean shuffleSongs;
	}

	private static class SearchCursor extends CursorWrapper {

		public SearchCursor(Cursor cursor) {
			super(cursor);
		}

		@Override
		public void close() {
		}

		public void realClose() {
			super.close();
		}
	}

	public static final int FILE_VIEW = 0;
	public static final int INFO_VIEW = 1;
	public static final int SEARCH_VIEW = 2;
	public static final int NEXT_VIEW = 3;
	public static final int PREV_VIEW = 4;
	public static final int SAME_VIEW = 5;
	
	private static String[] repnames = { "CONT", "----", "REPT", "CS", "RS" };


	static SongDatabase songDatabase = null;
	private static Thread dbThread = null;

	private PlayerServiceConnection player;

	private ImageButton playButton;
	private ImageButton backButton;
	private ImageButton fwdButton;
	private ImageButton stopButton;
	private ImageButton goinfoButton;
	private ImageButton searchButton;

	private ViewFlipper flipper;
	private TextView songSecondsText;
	private TextView songTotalText;
	private TextView songSubtunesText;
	private TextView titleText;
	private TextView subtitleText;
	private TextView infoText;

	private int seekingSong;

	// private ViewFlipper seekFlipper;
	private SeekBar songSeeker;

	private OnItemClickListener listClickListener;

	private int sortOrder;
	
	private PlayListView playListView;
	private PlayListView searchListView;

	private PlayListView currentPlaylistView;

	private ProgressDialog progressDialog;

	private SearchCursor searchCursor;
	private SharedPreferences prefs;

	private int searchDirDepth;

	private int songPos;
	private int subTune;
	private int subTuneCount;
	private int songLength;
	// private String songName;
	private SongFile songFile;

	private File modsDir;
	private String currentPath;

	private BroadcastReceiver receiver;

	private SQLiteDatabase db;

	//private int backDown;
	private boolean atTop = true;

	private String songTitle;
	private String songComposer;

	private String searchQuery;
	private String dirTitle;
	private String dirSubTitle;
	private String[] songDetails;
	//private String indexSetting;

	private static final int TTS_UNCHECKED = -1000;
	private static final int TTS_OK = 2;
	private static final int TTS_UNINSTALLED = 0;
	private static final int TTS_UNINSTALLED_ASK = 1;

	private int ttsStatus = TTS_UNCHECKED;

	private Config lastConfig;

	private SparseArray<Runnable> confirmables = new SparseArray<Runnable>();

	private int songState;

	//private File operationFile;
	private SongFile operationSong;

	private TextView shuffleText;

	protected boolean shuffleSongs;

	private LinearLayout titleBar;

	private TextView repeatText;

	private int songRepeat;

	private TextView plusText;
	private TextView wakeText;

	private PowerManager.WakeLock wakeLock;

	// protected int favSelection;

	private String subtuneTitle;
	private String subtuneAuthor;

	private File moveFileHere;

	//private int operationTune;

	private String operationTitle;

	private int operationTuneCount;

	private TextView plinfoText;

	private int foundVersion;

	protected boolean dialogShowing;

	//private TextView lowText;

	private byte[] md5;

	private SongFile clipBoardFile;

	private boolean backPressed;

	private int dumpingWav = 0;

	private TextView toneLenText;

	protected boolean toneHQ = false;
	protected String toneName = "Droidsound Ringtone";
	protected boolean toneSet = true;

	protected int toneLength = 2;

	private TextView toneNameText;

	protected void finalize() throws Throwable {
		Log.d(TAG, "########## Activity finalize");
	};

	private void setDirectory(String path, PlayListView plv) {

		if(plv == null) {
			plv = currentPlaylistView;
		}

		if(path == null) {
			String p = plv.getPath();
			if(p != null) {
				path = p; //f = new File(p);
			} else if(currentPlaylistView == searchListView) {
				searchCursor.requery();
				searchListView.setCursor(searchCursor, null);
				flipTo(SEARCH_VIEW);
				return;
			} else {
				return;
			}
		}

		Cursor cursor = songDatabase.getFilesInPath(path, sortOrder);
		// Cursor cursor = songDatabase.getFilesInPath("http://swimmer.se/mp3/", sortOrder);
		plv.setCursor(cursor, path);

		File f = new File(path);

		if(f.equals(modsDir)) {
			atTop = true;
		} else {
			atTop = false;
		}
		if(plv == playListView) {
			dirTitle = songDatabase.getPathTitle();
			if(dirTitle == null) {
				dirTitle = f.getName();
			}
			dirSubTitle = f.getParent().replaceFirst(modsDir.getParent(), "");
			flipTo(FILE_VIEW);
			currentPath = path;
		} else if(plv == searchListView) {
			flipTo(SEARCH_VIEW);
		}

	}
	
	private void setDirectory(File path, PlayListView plv) {
		setDirectory(path.getPath(), plv);
	}
	private void setDirectory(PlayListView plv) {
		setDirectory((String)null, plv);
	}


	private void gotoParent(PlayListView plv) {

		if(plv == null) {
			plv = currentPlaylistView;
		}

		if(plv == searchListView && searchDirDepth <= 1) {
			searchListView.setCursor(searchCursor, null);
			searchDirDepth = 0;
			flipTo(SEARCH_VIEW);
			return;
		}

		if(atTop) {
			return;
		}

		String p = plv.getPath();
		if(p != null) {
			
			if(p.startsWith("http://")) {
				URL url;
				try {
					url = new URL(p);
				} catch (MalformedURLException e) {
					return;
				}
				
				Log.d(TAG, "Parent from URL %s", p);
				
				File f = new File(url.getPath());
				String newPath = f.getParent();

				Log.d(TAG, "Parent path %s", newPath == null ? "null" : newPath);

				
				if(newPath == null) {
					newPath = modsDir.getPath();
				} else
					newPath = "http://" + url.getHost() + newPath;

				Log.d(TAG, "NewPath %s", newPath);
				
				setDirectory(newPath, plv);
				//currentPlaylistView.setScrollPosition( "http://" + url.getHost() + url.getPath());				
				currentPlaylistView.setScrollPosition(p);
				
			} else {
				File f = new File(plv.getPath());
				setDirectory(f.getParentFile(), plv);
				currentPlaylistView.setScrollPosition(f.getPath());
				if(plv == searchListView) {
					searchDirDepth--;
				}
			}
		} else {
		}
	}

	@Override
	protected void onNewIntent(Intent intent) {
		setIntent(intent);
		Log.d(TAG, "INTENT " + intent.getAction());

		if(Intent.ACTION_VIEW.equals(intent.getAction())) {
			String music = intent.getDataString();
			if(music.toUpperCase().endsWith(".ZIP")) {
				if(music.startsWith("file:/")) {
					music = music.substring(6);
				}
				File f = new File(music);
				moveFileHere(f);
			} else {
				Intent newIntent = new Intent(intent);
				newIntent.setClass(this, PlayerService.class);
				startService(newIntent);
			}
		} else if(Intent.ACTION_SEND.equals(intent.getAction())) {
			Log.d(TAG, "<<NEW INTENT>> Want to share '%s'", intent.getDataString());			
			Intent newIntent = new Intent(intent);
			intent.setAction(Intent.ACTION_VIEW);
			newIntent.setClass(this, PlayerService.class);
			startService(newIntent);
			
		} else if(Intent.ACTION_SEARCH.equals(intent.getAction())) {
			String query = intent.getStringExtra(SearchManager.QUERY);
			Log.d(TAG, "QUERY " + query);
			if(searchCursor != null) {
				searchCursor.realClose();
			}
			searchCursor = new SearchCursor(songDatabase.search(query, currentPath, sortOrder));
			searchQuery = query;
			searchDirDepth = 0;
			if(searchCursor != null) {
				searchListView.setCursor(searchCursor, null);
				currentPlaylistView = searchListView;
				flipTo(SEARCH_VIEW);
			}
		}
	}

	private void flipTo(int what, boolean animate) {
		Animation ia = null;
		Animation oa = null;
		if(!animate) {
			ia = flipper.getInAnimation();
			oa = flipper.getOutAnimation();
			flipper.setInAnimation(null);
			flipper.setOutAnimation(null);
		}

		if(what < 3) {
			if(flipper.getDisplayedChild() != what) {

				if(what == FILE_VIEW) {
					String p = playListView.getPath();
					Cursor cursor = songDatabase.getFilesInPath(p, sortOrder);
					playListView.setCursor(cursor, p);
				}

				flipper.setDisplayedChild(what);
			}
		} else if(what == NEXT_VIEW) {
			flipper.showNext();
		} else if(what == PREV_VIEW) {
			flipper.showPrevious();
		}

		if(ia != null) {
			flipper.setInAnimation(ia);
			flipper.setOutAnimation(oa);
		}

		switch(flipper.getDisplayedChild()) {
		case INFO_VIEW:
			currentPlaylistView = null;
			searchButton.setVisibility(View.GONE);
			// shuffleButton.setVisibility(View.VISIBLE);
			if(subtuneTitle != null && subtuneTitle.length() > 0) {
				titleText.setText(subtuneTitle + " (" + songTitle + ")");
			} else {
				titleText.setText(songTitle);
			}
			if(subtuneAuthor != null && subtuneAuthor.length() > 0) {
				subtitleText.setText(subtuneAuthor);
			} else
				subtitleText.setText(songComposer);
			titleBar.setBackgroundColor(0xff000080);

			break;
		case SEARCH_VIEW:
			currentPlaylistView = searchListView;
			searchButton.setVisibility(View.VISIBLE);
			// shuffleButton.setVisibility(View.GONE);
			titleBar.setBackgroundColor(0xff800000);

			if(searchQuery != null) {
				titleText.setText("SEARCH: " + searchQuery);
			} else {
				titleText.setText("SEARCH");
			}
			String p = searchListView.getPath();
			if(p != null) {
				String st = p.replaceFirst(modsDir.getParent(), "");
				subtitleText.setText(st);
			} else {
				subtitleText.setText("");
			}
			break;
		case FILE_VIEW:
			currentPlaylistView = playListView;
			searchButton.setVisibility(View.GONE);
			// shuffleButton.setVisibility(View.GONE);
			titleText.setText(dirTitle);
			subtitleText.setText(dirSubTitle);
			titleBar.setBackgroundColor(0xff000080);

			break;
		}

	}
	
	private void flipTo(int what) {
		flipTo(what, true);
	}


	private static boolean copyFile(File in, File out) {
		FileChannel inChannel = null;
		FileChannel outChannel = null;
		try {
			inChannel = new FileInputStream(in).getChannel();
			outChannel = new FileOutputStream(out).getChannel();
			inChannel.transferTo(0, inChannel.size(), outChannel);
		} catch (IOException e) {
			return false;
		} finally {
			try {
				if(inChannel != null)
					inChannel.close();
				if(outChannel != null)
					outChannel.close();
			} catch (IOException e) {
				return false;
			}
		}
		return true;
	}

	@Override
	public void onCreate(Bundle savedInstanceState) {

		// final UncaughtExceptionHandler oldHandler =
		// Thread.getDefaultUncaughtExceptionHandler();
		// Thread.setDefaultUncaughtExceptionHandler()

		super.onCreate(savedInstanceState);
		Log.d(TAG, "#### onCreate()");

		DroidSoundPlugin.setContext(getApplicationContext());

		Intent intent = getIntent();
		Log.d(TAG, "Intent %s / %s", intent.getAction(), intent.getDataString());
		if(Intent.ACTION_VIEW.equals(intent.getAction())) {
			String music = intent.getDataString();

			if(music.toUpperCase().endsWith(".ZIP")) {

				if(music.startsWith("file:/")) {
					music = music.substring(6);
				}
				
				music = URLDecoder.decode(music);
				
				Log.d(TAG, "Moving %s", music);

				File f = new File(music);

				if(f.exists()) {
					moveFileHere = f;
				}			
			} else {
				Intent newIntent = new Intent(intent);
				newIntent.setClass(this, PlayerService.class);
				startService(newIntent);
				finish();
				return;
			}
		} else if(Intent.ACTION_SEND.equals(intent.getAction())) {
			Log.d(TAG, ">> Want to share '%s'", intent.getStringExtra(Intent.EXTRA_TEXT));
			
			Bundle bundle = intent.getExtras();
			for(String s : bundle.keySet()) {
				Log.d(TAG, s);
			}
			
			Intent newIntent = new Intent(intent);
			newIntent.setAction(Intent.ACTION_VIEW);
			
			Uri uri = Uri.parse(intent.getStringExtra(Intent.EXTRA_TEXT));			
			newIntent.setData(uri);
			newIntent.setClass(this, PlayerService.class);
			startService(newIntent);
			finish();
			return;
		}

		setVolumeControlStream(AudioManager.STREAM_MUSIC);

		player = new PlayerServiceConnection();

		setContentView(R.layout.player);
		flipper = (ViewFlipper) findViewById(R.id.flipper);
		goinfoButton = (ImageButton) findViewById(R.id.go_info_button);
		searchButton = (ImageButton) findViewById(R.id.search_button);
		titleBar = (LinearLayout) findViewById(R.id.title_bar);

		
		playButton = (ImageButton) findViewById(R.id.play_button);
		backButton = (ImageButton) findViewById(R.id.back_button);
		fwdButton = (ImageButton) findViewById(R.id.fwd_button);
		stopButton = (ImageButton) findViewById(R.id.stop_button);
		infoText = (TextView) findViewById(R.id.info_text);

		infoText.setMovementMethod(ScrollingMovementMethod.getInstance());

		songSecondsText = (TextView) findViewById(R.id.seconds_text);
		songTotalText = (TextView) findViewById(R.id.total_text);
		songSubtunesText = (TextView) findViewById(R.id.songs_text);

		playListView = (PlayListView) findViewById(R.id.play_list);
		searchListView = (PlayListView) findViewById(R.id.search_list);
		titleText = (TextView) findViewById(R.id.list_title);
		
		subtitleText = (TextView) findViewById(R.id.list_subtitle);

		songSeeker = (SeekBar) findViewById(R.id.song_seek);
	
		shuffleText = (TextView) findViewById(R.id.shuffle_text);
		repeatText = (TextView) findViewById(R.id.repeat_text);
		plusText = (TextView) findViewById(R.id.plus_text);
		wakeText = (TextView) findViewById(R.id.wake_text);

		//lowText = (TextView) findViewById(R.id.low_text);

		plinfoText = (TextView) findViewById(R.id.plinfo_text);

		
		
		prefs = PreferenceManager.getDefaultSharedPreferences(this);

		boolean indexUnknown = prefs.getBoolean("extensions", false);
		FileIdentifier.setIndexUnknown(indexUnknown);

		seekingSong = 0;

		currentPlaylistView = playListView;

		
		modsDir = null; //new File("/XXX");
		
		setupModsDir();
		
		String cp = prefs.getString("currentPath", null);
		if(cp == null) {
			currentPath = modsDir.getPath();
		} else {
			currentPath = cp;
		}
		atTop = currentPath.equals(modsDir);
		

		Log.d(TAG, "MODS at %s", modsDir);		
		
		receiver = new BroadcastReceiver() {
			@Override
			public void onReceive(Context context, Intent intent) {
				// TODO Auto-generated method stub

				if(intent.getAction().equals("com.sddb.droidsound.REQUERY")) {
					Log.d(TAG, "REQUERY");
					//playListView.rescan();
					setDirectory(playListView);
				}
				else if(intent.getAction().equals("com.sddb.droidsound.OPEN_DONE")) {
					Log.d(TAG, "Open done!");

					String s = prefs.getString("indexing", "Basic");
					int imode = SongDatabase.INDEX_BASIC;
					if(s.equals("Full")) {
						imode = SongDatabase.INDEX_FULL;
					} else if(s.equals("None")) {
						imode = SongDatabase.INDEX_NONE;
					}
					songDatabase.setIndexMode(imode);


					if(lastConfig != null) {
						Log.d(TAG, "CONFIG CHANGE");
					} else {
						Log.d(TAG, "SCANNING");
						songDatabase.scan(false, modsDir.getPath());
					}

					// playListView.rescan();
					setDirectory(playListView);

					// songDatabase.scan(false, modsDir);
				} else if(intent.getAction().equals("com.sddb.droidsound.SCAN_DONE")) {

					if(progressDialog != null) {
						progressDialog.cancel();
						progressDialog = null;
					}

					Log.d(TAG, "Scan done!");
					setDirectory(playListView);
					// playListView.rescan();
				} else if(intent.getAction().equals("com.sddb.droidsound.SCAN_UPDATE")) {
					Log.d(TAG, "Scan update!");
					checkProgressDialog();
					if(progressDialog != null) {
						int percent = intent.getIntExtra("PERCENT", 0);
						String path = intent.getStringExtra("PATH");
						if(percent > 0) {
							progressDialog.setMessage(String.format("Updating database...\n%s %02d%%", path, percent));
						} else {
							progressDialog.setMessage(String.format("Updating database...\n%s", path));
						}
					}

				}
			}
		};

		IntentFilter filter = new IntentFilter();
		filter.addAction("com.sddb.droidsound.REQUERY");
		filter.addAction("com.sddb.droidsound.OPEN_DONE");
		filter.addAction("com.sddb.droidsound.SCAN_DONE");
		filter.addAction("com.sddb.droidsound.SCAN_UPDATE");
		// filter.addAction("com.sddb.droidsound.DOWNLOAD_DONE");
		registerReceiver(receiver, filter);


		boolean created = false;

		if(songDatabase == null) {
			setupSongDatabase();
			created = true;
		}

		setDirectory(currentPath, null);

		if(foundVersion == -1) {
			dialogShowing = true;
			showDialog(R.string.unpack_examples);
		}

		checkProgressDialog();

		lastConfig = (Config) getLastNonConfigurationInstance();
		if(lastConfig != null) {
			// textToSpeech = lastConfig.textToSpeech;
			ttsStatus = lastConfig.ttsStatus;
			searchCursor = lastConfig.searchCursor;
			searchListView.setCursor(searchCursor, null);
			songDatabase.setActivePlaylist(new File(lastConfig.activePlaylist));
			searchQuery = lastConfig.query;
			shuffleSongs = lastConfig.shuffleSongs;
			flipTo(lastConfig.flipper, false);
		} else {
			CSDBParser.init();
			File mf = new File(modsDir, "Favorites.plist");
			songDatabase.setActivePlaylist(mf);

			DroidSoundPlugin.setOptions(prefs);

			shuffleSongs = prefs.getBoolean("shuffle", false);

		}
		shuffleText.setText(shuffleSongs ? "RND" : "SEQ");
		// repeatText.setText("CONT");

		String b = prefs.getString("buffer", "Long");
		player.setOption(PlayerService.OPTION_BUFFERSIZE, b);


		if(!created && lastConfig == null) {
			Log.d(TAG, "OPEN DB");
			songDatabase.open();
			songDatabase.scan(false, modsDir.getPath());
			Log.d(TAG, "DONE");
		}

		if(ttsStatus == TTS_UNCHECKED) {
			try {
				Intent checkIntent = new Intent();
				checkIntent.setAction(TextToSpeech.Engine.ACTION_CHECK_TTS_DATA);
				startActivityForResult(checkIntent, 1234);
			} catch (RuntimeException exc) {
				exc.printStackTrace();
				ttsStatus = TTS_UNINSTALLED;
			}
		}

		// if(mf.exists()) {
		// songDatabase.setActivePlaylist(mf);
		// }

		listClickListener = new OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

				PlayListView plv = (PlayListView) parent;

				FileInfo fi = (FileInfo) plv.getItemAtPosition(position);
				
				Log.d(TAG, "Clicked %s got file %s", plv, fi);

				if(fi != null) {

					if(fi.type == SongDatabase.TYPE_DIR || fi.type == SongDatabase.TYPE_ARCHIVE || fi.type == SongDatabase.TYPE_PLIST) {
						setDirectory(fi.getPath(), plv);
						plv.setScrollPosition(null);
						if(plv == searchListView) {
							searchDirDepth++;
						}

					} else {
						int index = 0;
						// File [] files = adapter.getFiles(true);

						FileInfo[] files = plv.getFiles(true);

						if(currentPlaylistView == playListView) {
							Playlist plist = songDatabase.getCurrentPlaylist();
							if(plist != null) {
								
								// TODO: Check if this shorcut works;
								index = position;
								
								/*for(int i = 0; i < files.length; i++) {
									if(files[i].equals(fi)) {
										index = i;
									}
								} */
								Log.d(TAG, "Playing Playlist %s %s", plist.getFile().getPath(), plist.toString());
								player.playPlaylist(plist.getFile().getPath(), index);
								return;
							}
						}

						String[] names = new String[files.length];
						for(int i = 0; i < files.length; i++) {
							if(files[i].equals(fi)) {
								index = i;
							}
							names[i] = files[i].getPath();
						}
						player.playList(names, index);
						// adapter.notifyDataSetChanged();
						// adapter.setSelectedPosition(position);
					}
				}
			}
		};

		PowerManager pm = (PowerManager) getSystemService(Context.POWER_SERVICE);
		wakeLock = pm.newWakeLock(PowerManager.SCREEN_DIM_WAKE_LOCK, "Droidsound");

		playListView.setOnItemClickListener(listClickListener);
		searchListView.setOnItemClickListener(listClickListener);

		registerForContextMenu(playListView);
		registerForContextMenu(searchListView);

		goinfoButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				flipTo(NEXT_VIEW);
			}
		});

		searchButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				onSearchRequested();
			}
		});

		playButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {

				if(songState == 1) {
					player.playPause(false);
				} else {
					player.playPause(true);
				}
			}
		});

		stopButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				player.stop();
			}
		});

		backButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				if(subTune == 0 || subTuneCount == 0) {
					player.playPrev();
				} else {
					subTune -= 1;
					player.setSubSong(subTune);
				}
			}
		});

		backButton.setOnLongClickListener(new OnLongClickListener() {
			@Override
			public boolean onLongClick(View v) {
				player.playPrev();
				return true;
			}
		});

		fwdButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				Log.d(TAG, "NEXT %d %d", subTune, subTuneCount);
				if((subTune + 1) < subTuneCount) {
					subTune += 1;
					player.setSubSong(subTune);
				} else {
					player.playNext();
				}
			}
		});

		fwdButton.setOnLongClickListener(new OnLongClickListener() {
			@Override
			public boolean onLongClick(View v) {
				player.playNext();
				return true;
			}
		});

		player.setOption(PlayerService.OPTION_PLAYBACK_ORDER, shuffleSongs ? "R" : "S");

		shuffleText.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				shuffleSongs = !shuffleSongs;
				player.setOption(PlayerService.OPTION_PLAYBACK_ORDER, shuffleSongs ? "R" : "S");
				shuffleText.setText(shuffleSongs ? "RND" : "SEQ");
			}
		});

		repeatText.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				// shuffleSongs = !shuffleSongs;
				if(songRepeat == 0) {
					songRepeat = 1;
				} else {
					songRepeat = 0;
				}
				player.setOption(PlayerService.OPTION_REPEATMODE, Integer.toString(songRepeat));
			}
		});

		plusText.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {

				if(songFile != null) {
					//operationFile = songFile.getFile();
					operationSong = new SongFile(songFile);
					//operationSong.setSubTune(subTune);
					
					//operationTune = subTune;
					operationTitle = null;
					operationTuneCount = subTuneCount;
					Log.d(TAG, "%s - %s ADD", songTitle != null ? songTitle : "null", subtuneTitle != null ? subtuneTitle : "null");
					if(songTitle != null && subtuneTitle != null) {
						// operationTitle = songTitle + " - " + subtuneTitle;
						operationTitle = subtuneTitle + " (" + songTitle + ")";
					}
					//operationSong.setTitle(operationTitle);
					showDialog(R.string.add_to_plist);
				}
			}
		});

		wakeText.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				if(wakeLock.isHeld()) {
					wakeLock.release();
					wakeText.setTextColor(0xff404060);
				} else {
					wakeLock.acquire();
					wakeText.setTextColor(0xffb0b0ff);
				}
			}
		});
		
		titleBar.setOnClickListener(new OnClickListener() {
			
			final int [] sortNames = new int [] { R.string.sort_name, R.string.sort_date, R.string.sort_author };

			@Override
			public void onClick(View v) {
				//flipTo(SAME_VIEW);
				if(currentPlaylistView == playListView) {
					sortOrder = (sortOrder + 1) % 3;
					
					Toast toast = Toast.makeText(PlayerActivity.this, sortNames[sortOrder], Toast.LENGTH_SHORT);
					toast.show();					
					
					String p = currentPlaylistView.getPath();
					Cursor cursor = songDatabase.getFilesInPath(p, sortOrder);
					currentPlaylistView.setCursor(cursor, p);
				} else if(currentPlaylistView == searchListView) {
					sortOrder = (sortOrder + 1) % 3;
					if(searchCursor != null) {
						searchCursor.realClose();
					}
					searchCursor = new SearchCursor(songDatabase.search(searchQuery, currentPath, sortOrder));
					//searchDirDepth = 0;
					if(searchCursor != null) {
						searchListView.setCursor(searchCursor, null);
						//currentPlaylistView = searchListView;
						flipTo(SAME_VIEW);
					}
				}
				Log.d(TAG, "TB Sortorder now %d", sortOrder);
			}
		});

		/*
		 * songSecondsText.setOnClickListener(new OnClickListener() {
		 * 
		 * @Override public void onClick(View v) { seekFlipper.showNext(); } });
		 * 
		 * seekFlipper.setOnClickListener(new OnClickListener() {
		 * 
		 * @Override public void onClick(View v) { seekFlipper.showNext(); } });
		 */

		songSeeker.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
			@Override
			public void onStopTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				Log.d(TAG, "Stop tracking");
				player.seekTo(songLength * seekBar.getProgress() * 10);
				seekingSong = 5;
			}

			@Override
			public void onStartTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				Log.d(TAG, "Start tracking");
				seekingSong = 5;
			}

			@Override
			public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
				if(fromUser) {
					// Log.d(TAG, "Changed %d", progress);
					int pos = songLength * seekBar.getProgress() / 100;
					songSecondsText.setText(String.format("%02d:%02d", pos / 60, pos % 60));
					seekingSong = 5;
				}
			}
		});

		/*
		 * shuffleButton.setOnCheckedChangeListener(new
		 * OnCheckedChangeListener() {
		 * 
		 * @Override public void onCheckedChanged(CompoundButton buttonView,
		 * boolean isChecked) { shuffleSongs = isChecked;
		 * player.setOption(PlayerService.OPTION_PLAYBACK_ORDER, isChecked ? "R"
		 * : "S" ); } });
		 */
		
		Log.d(TAG, "ON CREATE DONE");
	}
	
	private void setupSongDatabase() {
		Log.d(TAG, "############ CREATING static SongDatabase object ##############");

		songDatabase = new SongDatabase(getApplicationContext());

		CSDBParser csdb = new CSDBParser();
		songDatabase.registerDataSource(CSDBParser.DUMP_NAME, csdb);
		songDatabase.registerDataSource(CSDBParser.DUMP_NAME + ".ZIP", csdb);

		MediaSource ms = new MediaSource(this);
		songDatabase.registerDataSource(MediaSource.NAME, ms);

		dbThread = new Thread(songDatabase);
		dbThread.start();

		while(!songDatabase.isReady()) {
			try {
				Thread.sleep(100);
			} catch (InterruptedException e1) {
				e1.printStackTrace();
			}
		}

		Log.d(TAG, "CREATED");
	}

	private void setupModsDir() {
		
		String md = prefs.getString("modsDir", null);
		
		if(md == null) {
			File extFile = Environment.getExternalStorageDirectory();
			if(extFile != null) {
				modsDir = new File(extFile, "MODS");
			} else {
				showDialog(R.string.sdcard_not_found);
				dialogShowing = true;
			}
		} else {
			modsDir = new File(md);
		}
		
		if(modsDir == null) {
			modsDir = new File("/MODS");
			return;			
		}
	
		if(!modsDir.exists()) {
			modsDir.mkdirs();
		}

		if(!modsDir.exists()) {
			showDialog(R.string.create_moddir_failed);
			dialogShowing = true;
		} else {
			Editor editor = prefs.edit();
			editor.putString("modsDir", modsDir.getPath());
			editor.commit();
			// showDialog(12);
		}

		File[] files = modsDir.listFiles();
		if(files != null) {
			for(File f : files) {
				if(f.getName().endsWith(".temp")) {
					f.delete();
				}
			}
		}

		if(moveFileHere != null) {
			moveFileHere(moveFileHere);
		}

		foundVersion = prefs.getInt("version", -1);
		if(foundVersion == -1) {
			File tempFile = new File(modsDir, "Examples.zip");
			if(!tempFile.exists()) {
				try {
					InputStream is = getAssets().open("Examples.zip");
					if(is != null) {

						FileOutputStream os = new FileOutputStream(tempFile);

						byte[] buffer = new byte[1024 * 64];

						int rc = 0;
						while(rc >= 0) {
							rc = is.read(buffer);
							if(rc > 0) {
								os.write(buffer, 0, rc);
							}
						}
						os.close();
						is.close();
					}

				} catch (IOException e) {
					e.printStackTrace();
				}
			} else {
				foundVersion = 0;
			}
		}
	
		Editor e = prefs.edit();
		e.putInt("version", VERSION);
		e.commit();

		File ns = new File(modsDir, ".nomedia");
		if(!ns.exists()) {
			FileWriter fw;
			try {
				fw = new FileWriter(ns);
				fw.close();
			} catch (IOException e1) {
			}
		}

		File mf = new File(modsDir, MediaSource.NAME);
		if(!mf.exists()) {
			try {
				FileWriter fw = new FileWriter(mf);
				fw.close();
				Log.d(TAG, "Done");
			} catch (IOException e2) {
				// TODO Auto-generated catch block
				e2.printStackTrace();
			}
		}
		
		mf = new File(modsDir, "Streaming");
		if(mf.exists()) {
			deleteAll(mf);
		}
		
		mf = new File(modsDir, "Network");
		if(!mf.exists()) {			
			Unzipper.unzipAsset(this, "Network.zip", modsDir);
		}

		
		mf = new File(modsDir, "Favorites.plist");
		if(!mf.exists()) {
			try {
				Log.d(TAG, "Trying to write Favorites");
				FileWriter fw = new FileWriter(mf);
				fw.close();
				Log.d(TAG, "Done");
			} catch (IOException e2) {
				// TODO Auto-generated catch block
				e2.printStackTrace();
			}
		}

		new File(modsDir, "Favorites.lnk").delete();
		
	}

	private void deleteAll(File mf) {
		File [] files = mf.listFiles();
		if(files != null) {
			for(File f: files) {
				Log.d(TAG, f.getPath());
				if(f.isDirectory()) {
					deleteAll(f);
				}
				f.delete();
			}
		}
		mf.delete();
	}

	private void checkProgressDialog() {
		if(!dialogShowing && songDatabase.isScanning() && progressDialog == null) {
			progressDialog = new ProgressDialog(PlayerActivity.this);
			progressDialog.setProgressStyle(ProgressDialog.STYLE_SPINNER);
			progressDialog.setMessage("Updating database...");
			progressDialog.setCancelable(false);
			progressDialog.show();
		}
	}

	public static boolean moveFile(File src, File dest) {
		if(src.renameTo(dest)) {
			Log.d(TAG, "Successful");
			return true;
		} else if(copyFile(src, dest)) {
			Log.d(TAG, "COPY Successful");
			src.delete();
			return true;
		}
		return false;
	}

	private void moveFileHere(File f) {

		File t;// = new File(modsDir, f.getName());

		String n = f.getName();

		n = n.replace('_', ' ');

		int ext = n.indexOf('.');
		if(ext > 2 && Character.isDigit(n.charAt(ext - 1)) && n.charAt(ext - 2) == '-') {
			t = new File(modsDir, n.substring(0, ext - 2) + n.substring(ext));
		} else {
			t = new File(modsDir, n);
		}

		Log.d(TAG, "MOVE FILE " + f.getPath() + " TO " + t.getPath());

		if(t.exists()) {
			showDialog(R.string.zip_import_replace);
			moveFileHere = null;
			return;
		}

		if(f.renameTo(t)) {
			Log.d(TAG, "Successful");
			if(songDatabase != null) {
				songDatabase.scan(false, modsDir.getPath());
			}
		} else if(copyFile(f, t)) {
			Log.d(TAG, "COPY Successful");
			if(songDatabase != null) {
				songDatabase.scan(false, modsDir.getPath());
			}
		} else {
			showDialog(R.string.zip_import_failed);
		}
		moveFileHere = null;
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		Log.d(TAG, "Got speech result %d", resultCode);
		if(requestCode == 1234) {
			Log.d(TAG, "Got speech result %d", 12345);
			if(resultCode == TextToSpeech.Engine.CHECK_VOICE_DATA_PASS) {
				ttsStatus = TTS_OK;
				boolean useSpeech = prefs.getBoolean("speech", false);
				player.setOption(PlayerService.OPTION_SPEECH, useSpeech ? "on" : "off");
			} else {
				ttsStatus = TTS_UNINSTALLED;
				player.setOption(PlayerService.OPTION_SPEECH, "none");
				// missing data, install it
				// Intent installIntent = new Intent();
				// installIntent.setAction(TextToSpeech.Engine.ACTION_INSTALL_TTS_DATA);
				// startActivity(installIntent);
			}
		}
	}

	@Override
	public boolean dispatchKeyEvent(KeyEvent event) {
		Log.d(TAG, "#### KEY EVENT %s", event.toString());
		return super.dispatchKeyEvent(event);
	}

	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		Log.d(TAG, "%%%% DOWN %d", keyCode);
		// if(keyCode == KeyEvent.KEYCODE_HEADSETHOOK) {
		// Log.d(TAG, String.format("MEDIA BUTTON DOWN %d",
		// event.getRepeatCount()));
		// return true;
		// }

		if(keyCode >= KeyEvent.KEYCODE_0 && keyCode <= KeyEvent.KEYCODE_9) {

			int t = (keyCode - KeyEvent.KEYCODE_0) - 1;
			if(t == -1)
				t = 10;
			if(t < subTuneCount) {
				subTune = t;
				player.setSubSong(subTune);
			}
		}

		AudioManager amg = (AudioManager) getSystemService(Context.AUDIO_SERVICE);

		switch(keyCode) {
		case KeyEvent.KEYCODE_F:
			onSearchRequested();
			break;
		case KeyEvent.KEYCODE_Z:
			player.playPrev();
			break;
		case KeyEvent.KEYCODE_B:
			player.playNext();
			break;
		case KeyEvent.KEYCODE_N:
			if(subTune != 0 && subTuneCount != 0) {
				subTune -= 1;
				player.setSubSong(subTune);
			}
			break;
		case KeyEvent.KEYCODE_M:
			if((subTune + 1) < subTuneCount) {
				subTune += 1;
				player.setSubSong(subTune);
			}
			break;
		case KeyEvent.KEYCODE_V:
			player.stop();
			break;
		case KeyEvent.KEYCODE_X:
			player.stop();
			player.playPause(true);
			break;
		case KeyEvent.KEYCODE_C:
			if(songState == 1) {
				player.playPause(false);
			} else {
				player.playPause(true);
			}
			break;
		case KeyEvent.KEYCODE_PLUS:
		case KeyEvent.KEYCODE_PERIOD:
			amg.adjustStreamVolume(AudioManager.STREAM_MUSIC, AudioManager.ADJUST_RAISE, 0);
			break;
		case KeyEvent.KEYCODE_MINUS:
		case KeyEvent.KEYCODE_COMMA:
			amg.adjustStreamVolume(AudioManager.STREAM_MUSIC, AudioManager.ADJUST_LOWER, 0);
			break;
		case KeyEvent.KEYCODE_TAB:
			flipTo(NEXT_VIEW);
			break;
		case KeyEvent.KEYCODE_S:
			shuffleSongs = !shuffleSongs;
			player.setOption(PlayerService.OPTION_PLAYBACK_ORDER, shuffleSongs ? "R" : "S");
			shuffleText.setText(shuffleSongs ? "RND" : "SEQ");
			break;
		case KeyEvent.KEYCODE_R:
			if(songRepeat == 0) {
				songRepeat = 1;
			} else {
				songRepeat = 0;
			}
			player.setOption(PlayerService.OPTION_REPEATMODE, Integer.toString(songRepeat));
			break;
		// case KeyEvent.M:
		// player.setOption(PlayerService.OPTION_SPEECH, useSpeech ? "on" :
		// "off");
		// break;
		case KeyEvent.KEYCODE_Q:
			player.stop();
			//songDatabase.quit();
			//songDatabase = null;
			finish();
			break;
		case KeyEvent.KEYCODE_A:

			break;
		case KeyEvent.KEYCODE_D:
			break;

		case KeyEvent.KEYCODE_P:
			startActivity(new Intent(this, SettingsActivity.class));
			break;

		case KeyEvent.KEYCODE_I:
			openContextMenu(currentPlaylistView);
			break;

		case KeyEvent.KEYCODE_O:
			openOptionsMenu();
			break;

		case KeyEvent.KEYCODE_U:
			if(songFile != null) {
				//operationFile = songFile.getFile();
				operationSong = new SongFile(songFile);
				//operationTune = subTune;
				operationTitle = null;
				operationTuneCount = subTuneCount;
				if(songTitle != null && subtuneTitle != null) {
					// operationTitle = songTitle + " - " + subtuneTitle;
					operationTitle = subtuneTitle + " (" + songTitle + ")";
				}
				showDialog(R.string.add_to_plist);
			}
			break;
		case KeyEvent.KEYCODE_BACK:
		case KeyEvent.KEYCODE_DEL:
			Log.d(TAG, ">>>>>>>>>>>>> BACK PRESSED");			
			backPressed = true;
			event.startTracking();
			return true;
		}

		//backDown = 0;
		return super.onKeyDown(keyCode, event);
	}

	
	//@Override
	public boolean onKeyLongPress(int keyCode, KeyEvent event) {
	
		if(keyCode == KeyEvent.KEYCODE_BACK) {
			backPressed = false;
			Log.d(TAG, ">>>>>>>>>>>>> BACK LONG PRESSED");
			if(currentPlaylistView == searchListView) {
				searchDirDepth = 0;
				searchListView.setCursor(searchCursor, null);
				flipTo(SEARCH_VIEW);
			} else {
				setDirectory(modsDir, playListView);
				currentPlaylistView.setScrollPosition(null);
			}
			return true;
		}
		return false;
		////  return super.onKeyLongPress(keyCode, event);
	} 
	
	@Override
	public boolean onKeyUp(int keyCode, KeyEvent event) {
		
		if(keyCode == KeyEvent.KEYCODE_BACK ) {
			Log.d(TAG, ">>>>>>>>>>>>> BACK RELEASED");
			if(backPressed) {
				backPressed = false;			
				if(currentPlaylistView != playListView) {
					if(currentPlaylistView != searchListView || searchDirDepth == 0) {
						flipTo(FILE_VIEW);
						if(songFile != null) {
							playListView.setScrollPosition(songFile.getPath());
						}
						return true;
					}
				}
		
				if(atTop) {
					finish();
				} else {
					gotoParent(null);
				}
			}
			return true;
		}
		
		
		// if(keyCode == KeyEvent.KEYCODE_HEADSETHOOK) {
		// Log.d(TAG, String.format("MEDIA BUTTON UP %d",
		// event.getRepeatCount()));
		// return true;
		// }
		/* if(keyCode == KeyEvent.KEYCODE_BACK || keyCode == KeyEvent.KEYCODE_DEL) {
			if(backDown > 0 && backDown < 3) {
				backDown = 0;
				if(currentPlaylistView != playListView) {
					if(currentPlaylistView != searchListView || searchDirDepth == 0) {
						flipTo(FILE_VIEW);
						if(songFile != null) {
							playListView.setScrollPosition(songFile.getFile());
						}
						return true;
					}
				}

				if(atTop) {
					finish();
				} else {
					gotoParent(null);
				}
			}
			backDown = 0;
			return true;
		} */
		return super.onKeyUp(keyCode, event);
	}

	@Override
	protected void onResume() {
		super.onResume();
		Log.d(TAG, "#### onResume()");

		player.bindService(this, this);
		
		//if(songDatabase == null) {
		//	setupSongDatabase();
		//}

		if(!songDatabase.isScanning() && progressDialog != null) {
			progressDialog.cancel();
			progressDialog = null;
			// playListView.rescan();
			setDirectory(playListView);
		}

		boolean speech = prefs.getBoolean("speech", false);

		if(speech && ttsStatus == TTS_UNINSTALLED) {
			// missing data, install it
			ttsStatus = TTS_UNINSTALLED_ASK;

			runConfirmable(R.string.ask_speech, new Runnable() {
				@Override
				public void run() {
					Intent installIntent = new Intent();
					installIntent.setAction(TextToSpeech.Engine.ACTION_INSTALL_TTS_DATA);
					startActivity(installIntent);
				}
			});

		} else {
			player.setOption(PlayerService.OPTION_SPEECH, speech ? "on" : "off");
		}
		player.setOption(PlayerService.OPTION_SILENCE_DETECT, prefs.getBoolean("silence", false) ? "on" : "off");
		player.setOption(PlayerService.OPTION_DEFAULT_LENGTH, prefs.getString("default_length", "0"));
		
		player.setOption(PlayerService.OPTION_CYCLE_SUBTUNES, prefs.getBoolean("subtunes", false) ? "on" : "off");
		

		String b = prefs.getString("buffer", "Long");
		player.setOption(PlayerService.OPTION_BUFFERSIZE, b);

		String s = prefs.getString("indexing", "Basic");
		int imode = SongDatabase.INDEX_BASIC;
		if(s.equals("Full")) {
			imode = SongDatabase.INDEX_FULL;
		} else if(s.equals("None")) {
			imode = SongDatabase.INDEX_NONE;
		}

		songDatabase.setIndexMode(imode);

		FileIdentifier.setIndexUnknown(prefs.getBoolean("extensions", false));
	}

	@Override
	protected void onPause() {
		super.onPause();
		Log.d(TAG, "#### onPause()");

		//indexSetting = prefs.getString("indexing", "Basic");

		Editor editor = prefs.edit();
		editor.putString("currentPath", currentPath);
		editor.putBoolean("shuffle", shuffleSongs);
		editor.commit();

		Playlist.flushAll();

		if(wakeLock.isHeld()) {
			wakeLock.release();
		}

		player.unbindService(this);

		if(db != null) {
			db.close();
			db = null;
		}
	}

	@Override
	protected void onDestroy() {
		super.onDestroy();
		Log.d(TAG, "#### onDestroy()");

		if(receiver != null) {
			unregisterReceiver(receiver);
		}

		if(playListView != null) {
			playListView.close();
			// SharedPreferences prefs = getSharedPreferences("songdb",
			// Context.MODE_PRIVATE);
		}

		if(searchCursor != null) {
			searchCursor.realClose();
		}

		if(progressDialog != null) {
			progressDialog.dismiss();
		}

		player = null;

	}

	@Override
	public Object onRetainNonConfigurationInstance() {
		Config c = new Config();

		c.ttsStatus = ttsStatus;
		c.searchCursor = searchCursor;
		c.query = searchQuery;
		c.shuffleSongs = shuffleSongs;
		Playlist al = songDatabase.getActivePlaylist();
		if(al != null) {
			c.activePlaylist = al.getFile().getPath();
		}
		searchCursor = null;
		c.flipper = flipper.getDisplayedChild();
		return c;
	}

	private void hexdump(byte [] data) {
		StringBuilder sb = new StringBuilder();
		if(md5 == null) sb.append("NULL HEX");
		else
		for(int i=0; i<data.length; i++) {
			if(i % 8 == 0) {
				sb.append(String.format("\n%04x:  ", i));
			}
			sb.append(String.format("%02x ", data[i]));
		}
		Log.d(TAG, sb.toString());
	}
	@Override
	public void intChanged(int what, int value) {
		switch(what) {
		case PlayerService.SONG_FLAGS:
			songSeeker.setEnabled((value & 1) != 0);
			break;
		case PlayerService.SONG_REPEAT:
			songRepeat = value;
			repeatText.setText(repnames[value]);
			if(value == 1) {
				repeatText.setTextColor(0xff308050);
			} else {
				repeatText.setTextColor(0xff80ffc0);
			}

			break;
		case PlayerService.SONG_BUFFERING:
			if(value > 0) {
				songSubtunesText.setText(String.format("%02d:%02d", value / 1000 / 60, (value/1000) % 60));
			}
			break;
		case PlayerService.SONG_LENGTH:
			if(value < 0) {
				// TODO: Hide length
				value = 0;
				songTotalText.setVisibility(View.GONE);
			} else {
				songTotalText.setVisibility(View.VISIBLE);
			}
			songLength = value / 1000;
			Log.d(TAG, "Songlength %02d:%02d", songLength / 60, songLength % 60);
			songTotalText.setText(String.format("%02d:%02d", songLength / 60, songLength % 60));			
			//songSeeker.setProgress(0);
			break;
		case PlayerService.SONG_POS:
			if(seekingSong == 0) {
				songPos = value / 1000;
				songSecondsText.setText(String.format("%02d:%02d", songPos / 60, songPos % 60));
				if(songLength > 0) {
					int percent = 100 * songPos / songLength;
					if(percent > 100) percent = 100;
					songSeeker.setProgress(percent);
				} else {
					songSeeker.setProgress(0);
				}
			} else
				seekingSong--;

			break;
		case PlayerService.SONG_CPULOAD:
			// if (lowText != null) {
			// aTime = aTime * 0.7F + value * 0.3F;
			// lowText.setText(String.format("CPU %d%%", (int) aTime));
			// }
			break;
		case PlayerService.SONG_SUBSONG:
			if(value >= 0) {
				subTune = value;
				songSubtunesText.setText(String.format("[%02d/%02d]", subTune + 1, subTuneCount));
			}
			break;
		case PlayerService.SONG_TOTALSONGS:
			subTuneCount = value;
			songSubtunesText.setText(String.format("[%02d/%02d]", subTune + 1, subTuneCount));
			break;
		case PlayerService.SONG_STATE:
			Log.d(TAG, "State now %d", value);
			songState = value;
			if(value == 1) {
				playButton.setBackgroundResource(R.drawable.pause_button);
			} else {
				playButton.setBackgroundResource(R.drawable.play_button);
				if(value == 0) {
					// songTitleText.setText("");
					// songComposerText.setText("");
					// songCopyrightText.setText("");
					// songSubtunesText.setText("[00/00]");
					// songTotalText.setText("00:00");
					// songSecondsText.setText("00:00");
				}
			}
			break;
		}
	}

	@Override
	public void stringChanged(int what, String value) {

		switch(what) {
		case PlayerService.SONG_SOURCE:
			Log.d(TAG, "SOURCE IS " + value);
			if(value != null && value.length() > 0) {
				plinfoText.setText(value);
			} else 
				plinfoText.setText("");
			break;
/*		case PlayerService.SONG_PLAYLIST:
			if(value != null && value.length() > 0) {
				String n = new File(value).getName();
				int dot = n.lastIndexOf('.');
				if(dot > 0) {
					n = n.substring(0, dot);
				}
				plinfoText.setText(n);
			} else if(songFile != null) {
				String n = songFile.getFile().getParent();
				if(n != null) {
					n = n.replace(modsDir.getPath(), "");
				} else {
					n = "";
				}
				plinfoText.setText(n);
			} else {
				plinfoText.setText("");
			}
			break; */
		case PlayerService.SONG_FILENAME:
			
			Log.d(TAG, "DW %d, value '%s'", dumpingWav, value);
			if(dumpingWav > 0) { //&& value.endsWith("RINGTONE.WAV")) {
				
				File f = new File(value);
				
				Log.d(TAG, "SETTING RINGTONE %s %d", value, f.length());
				
				ContentValues values = new ContentValues();
				values.put(MediaStore.MediaColumns.DATA, value);
				values.put(MediaStore.MediaColumns.TITLE, toneName);
				values.put(MediaStore.MediaColumns.SIZE, f.length());
				values.put(MediaStore.MediaColumns.MIME_TYPE, "audio/x-wav");
				values.put(MediaStore.Audio.Media.ARTIST, "Droidsound");
				values.put(MediaStore.Audio.Media.DURATION, dumpingWav/1000);
				values.put(MediaStore.Audio.Media.IS_RINGTONE, true);
				values.put(MediaStore.Audio.Media.IS_NOTIFICATION, false);
				values.put(MediaStore.Audio.Media.IS_ALARM, false);
				values.put(MediaStore.Audio.Media.IS_MUSIC, false);

				//Insert it into the database
				Uri uri = MediaStore.Audio.Media.getContentUriForPath(value);
				Uri newUri = null;
				Log.d(TAG, "URI " + uri.toString());
				try {
					int rows = getContentResolver().delete(uri, String.format("%s = ?", MediaStore.MediaColumns.TITLE), new String [] { toneName });
					Log.d(TAG, "ROWS " + rows);
				} catch (Exception e) {
					e.printStackTrace();
				}
				try {
					newUri = getContentResolver().insert(uri, values);
				} catch (Exception e) {
					e.printStackTrace();
				}
				if(newUri == null) {
					int rows = getContentResolver().update(uri, values, String.format("%s = ?", MediaStore.MediaColumns.TITLE), new String [] { toneName });
					Log.d(TAG, "UPDATE ROWS " + rows);
					newUri = uri;
				} else {
					Log.d(TAG, "NEWURI " + uri.getPath());
				}
				Toast toast;
				if(toneSet) {
					RingtoneManager.setActualDefaultRingtoneUri(PlayerActivity.this, RingtoneManager.TYPE_RINGTONE, newUri);				
					toast = Toast.makeText(this, R.string.ringtone_set, Toast.LENGTH_LONG);
				} else {
					toast = Toast.makeText(this, R.string.ringtone_created, Toast.LENGTH_LONG);
				}
				toast.show();
				dumpingWav = 0;
				break;
				
			}
			dumpingWav = 0;
			
			songFile = new SongFile(value);
			String path = songFile.getFile().getPath();
			playListView.setHilighted(value);
			searchListView.setHilighted(value);
			// songName = value;
			
			Log.d(TAG, "############################## Song file is %s (%s)", value, path);
			
			break;
		case PlayerService.SONG_SUBTUNE_TITLE:
			Log.d(TAG, "############################## Subtunetitle is %s", value);
			subtuneTitle = value;
			if(subtuneTitle != null && subtuneTitle.length() == 0) subtuneTitle = null;
			flipTo(SAME_VIEW);
			break;
		case PlayerService.SONG_SUBTUNE_AUTHOR:
			Log.d(TAG, "############################## Author is %s", value);
			subtuneAuthor = value;
			flipTo(SAME_VIEW);
			break;
		case PlayerService.SONG_TITLE:
			Log.d(TAG, "############################## Title is %s", value);
			songTitle = value;
			subtuneTitle = null;
			flipTo(SAME_VIEW);
			// NOTE: Intentonal fall-through
		case PlayerService.SONG_DETAILS:
			songDetails = player.getSongInfo();
			md5 = player.getSongMD5();
			hexdump(md5);
			Log.d(TAG, "#### Got %d details", songDetails != null ? songDetails.length : -1);
			if(songDetails != null) {
				StringBuilder sb = new StringBuilder("<tt>");
				for(int i = 0; i < songDetails.length; i += 2) {
					// Log.d(TAG, songDetails[i]);
					// Log.d(TAG, songDetails[i+1]);
					sb.append("<font color='yellow'><b>").append(songDetails[i]).append("</font></b><br/>");
					if(songDetails[i].equals("Instruments")) {
						// sb.append(songDetails[i+1].replace("\n",
						// "<br/><font color='white'>"));
						String[] instr = songDetails[i + 1].split("\n");
						for(int j = 0; j < instr.length; j++) {
							sb.append(String.format("<font color='white'>%02d</font>: %s<br/>", j + 1, instr[j].replace(">", "&gt;")
									.replace("<", "&lt;")));
						}

					} else {
						sb.append(songDetails[i + 1].replace("\n", "<br/>"));
						sb.append("<br/>");
					}
				}
				sb.append("</tt>");
				infoText.setText(Html.fromHtml(sb.toString()));
			} else {
				infoText.setText("");
			}
			infoText.scrollTo(0, 0);
			break;
		case PlayerService.SONG_AUTHOR:
			// songComposerText.setText(value);
			songComposer = value;
			flipTo(SAME_VIEW);
			break;
		case PlayerService.SONG_COPYRIGHT:
			// songCopyrightText.setText(value);
			break;
		// case PlayerService.SONG_GAMENAME :
		// if(value != null && value.length() > 0) {
		// songCopyrightText.setText(value);
		// }
		// break;
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {

		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.optionsmenu, menu);
		return true;
	}
	
	@Override
	public boolean onPrepareOptionsMenu(Menu menu) {
		
		//MenuItem m = menu.getItem(0);
		//if(songDatabase.getCurrentPlaylist() != null) {
		//	m.setTitle("Edit");
		//} else {
		//	m.setTitle("New");
		//}
		
		return super.onPrepareOptionsMenu(menu);
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		int choice = item.getItemId();
		switch(choice) {
		case R.id.settings:
			startActivity(new Intent(this, SettingsActivity.class));
			break;
		case R.id.quit:
			player.stop();
			//songDatabase.quit();
			//songDatabase = null;
			finish();
			break;
		case R.id.new_:
			//if(songDatabase.getCurrentPlaylist() != null) {
			//	currentPlaylistView.setEditMode(true);
			//} else {
				showDialog(R.string.new_);
			//}
			break;
		case R.id.search:
			onSearchRequested();
			break;
		}
		return true;
	}

	@Override
	protected void onPrepareDialog(int id, Dialog dialog) {
		super.onPrepareDialog(id, dialog);
		AlertDialog ad;

		switch(id) {
		case R.string.do_del_dir:
		case R.string.do_del_file:
		case R.string.do_del_plist:
		case R.string.do_remove_all:
			ad = ((AlertDialog) dialog);
			if(operationSong == null) {
				ad.cancel();
				return;
			}
			break;
		case R.string.add_to_plist:
			ad = ((AlertDialog) dialog);
			if(songTitle == null || operationSong == null) {
				ad.cancel();
				return;
			}

			Button b = ad.getButton(DialogInterface.BUTTON_POSITIVE);
			ListView lv = ad.getListView();
			int i = lv.getCheckedItemPosition();

			if(i == ListView.INVALID_POSITION) {
				b.setEnabled(false);
			} else if(operationTuneCount < 2 && i > 0) {
				b.setEnabled(false);
			}

			Playlist pl = songDatabase.getActivePlaylist();
			if(pl != null) {
				String s = getString(R.string.add_to_plist);
				ad.setTitle(s.replace("[playlist]", pl.getTitle()));
			} else {
				ad.setTitle(id);
			}
			break;
		}
	}

	@Override
	protected Dialog onCreateDialog(int id) {

		AlertDialog.Builder builder = new AlertDialog.Builder(this);

		if(confirmables.get(id) != null) {
			final Runnable runnable = confirmables.get(id);
			builder.setMessage(id);
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					runnable.run();
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}
			});
			confirmables.remove(id);
			return builder.create();
		}

		switch(id) {
		case R.string.make_wav:
		{
			//Dialog dialog = new Dialog(this);
			//dialog.setContentView(R.layout.ringtone_dialog);
			//dialog.setTitle(id);
			final String [] progressNames = new String [] { "0:10", "0:20", "0:30", "1:00", "5:00", "10:00" };
			LayoutInflater inflater = (LayoutInflater) getSystemService(LAYOUT_INFLATER_SERVICE);
			View dialog = inflater.inflate(R.layout.ringtone_dialog, (ViewGroup) findViewById(R.layout.player));
			builder.setView(dialog);			
			builder.setTitle(id);
			
			toneNameText = (TextView) dialog.findViewById(R.id.tone_name);
			toneNameText.setText(toneName);
			
			CheckBox hqCheck = (CheckBox) dialog.findViewById(R.id.tone_hq);
			hqCheck.setChecked(toneHQ);
			hqCheck.setOnCheckedChangeListener(new CheckBox.OnCheckedChangeListener() {
				@Override
				public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
					toneHQ = isChecked;
				}
			});
			CheckBox setCheck = (CheckBox) dialog.findViewById(R.id.tone_set);
			setCheck.setChecked(toneSet);
			setCheck.setOnCheckedChangeListener(new CheckBox.OnCheckedChangeListener() {
				@Override
				public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
					toneSet = isChecked;
				}
			});
			
			toneLenText =  (TextView) dialog.findViewById(R.id.tone_lentext);
			toneLenText.setText(progressNames[toneLength]);
			SeekBar seekBar = (SeekBar) dialog.findViewById(R.id.tone_length);
			seekBar.setProgress(toneLength);
			seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
				@Override
				public void onStopTrackingTouch(SeekBar seekBar) {
				}
				
				@Override
				public void onStartTrackingTouch(SeekBar seekBar) {
				}
				
				@Override
				public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
					Log.d(TAG, "SEEK " + progress);
					toneLenText.setText(progressNames[progress]);	
					toneLength = progress;
				}
			});
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
					File file = new File(droidDir, "ringtones");
					file.mkdir();
					int tl = toneLength;
					if(tl == 3) tl = 6;
					else if(tl == 4) tl = 6*5;
					else if(tl == 5) tl = 6*10;
					else tl += 1;
					dumpingWav = tl * 10000;//30000;
					toneName = (String) toneNameText.getText().toString();
					file = new File(file, toneName + ".wav"); 
					
					int flags = 0;
					if(toneHQ) flags |= 2;
					player.dumpWav(operationSong.getPath(), file.getPath(), dumpingWav, flags);
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}
			});
			/*
			Button okButton = (Button) dialog.findViewById(R.id.ok_button);
			okButton.setOnClickListener(new OnClickListener() {				
				@Override
				public void onClick(View v) {
					File file = new File("/sdcard/droidsound/RINGTONE.WAV");
					dumpingWav = 10000 + toneLength * 1000;//30000;
					int flags = 0;
					if(toneHQ) flags |= 2;
					player.dumpWav(operationSong.getPath(), file.getPath(), dumpingWav, flags);
				}
			});
			Button cancelButton = (Button) dialog.findViewById(R.id.cancel_button);
			cancelButton.setOnClickListener(new OnClickListener() {
				@Override
				public void onClick(View v) {
				}
			}); */
			break;
			//return dialog;			
		}	
		case R.string.new_:
			builder.setTitle(id);
			builder.setSingleChoiceItems(R.array.new_opts, -1, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					Log.d(TAG, "Clicked " + which);
					dialog.dismiss();
					switch(which) {
					case 0:
						showDialog(R.string.name_folder);
						break;
					case 1:
						showDialog(R.string.name_playlist);
						break;
					case 2:
						showDialog(R.string.name_link);
						break;
					}
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}
			});
			break;
		case R.string.name_playlist:
			final EditText input = new EditText(this);
			input.setInputType(InputType.TYPE_CLASS_TEXT);
			// builder.setTitle(id);
			builder.setView(input);
			builder.setMessage(id);
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					String s = input.getText().toString();
					File file = new File(currentPath, s + ".plist");
					if(!file.exists() && !file.getName().equals("Favorites.plist")) {
						songDatabase.createPlaylist(file);
						songDatabase.setActivePlaylist(file);
						playListView.rescan();
					}
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}
			});
			break;
		case R.string.name_link:
			final EditText input3 = new EditText(this);
			input3.setHint("http://");
			input3.setInputType(InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_VARIATION_URI);
			// builder.setTitle(id);
			builder.setView(input3);
			builder.setMessage(id);
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					String s = input3.getText().toString();
					if(!s.startsWith("http://"))
						s = "http://" + s;
					try {
						URL url = new URL(s);
						Log.d(TAG, "'%s', '%s', '%s'",url.toString(), url.getProtocol(), url.getFile());
						File file = new File(currentPath, url.getHost() + ".lnk");
						if(!file.exists()) {							
							songDatabase.createLink(file, url.toString());
							playListView.rescan();
						}
					} catch (MalformedURLException e) {
						e.printStackTrace();
					}
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}
			});
			break;
		case R.string.name_folder:
			final EditText input2 = new EditText(this);
			input2.setInputType(InputType.TYPE_CLASS_TEXT);
			builder.setView(input2);
			builder.setMessage(id);
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					String s = input2.getText().toString();
					File f = new File(currentPath, s);
					if(!f.exists()) {
						songDatabase.createFolder(f);
						playListView.rescan();
					}
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}
			});
			break;
		case R.string.add_to_plist:

			builder.setTitle(id);

			builder.setSingleChoiceItems(R.array.fav_opts, -1, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					// favSelection = which;
					Button b = ((AlertDialog) dialog).getButton(DialogInterface.BUTTON_POSITIVE);

					if(operationTuneCount < 2) {
						if(which == 0) {
							b.setEnabled(true);
						} else {
							b.setEnabled(false);
						}
					} else {
						b.setEnabled(true);
					}
				}
			});
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {

					int favSelection = ((AlertDialog) dialog).getListView().getCheckedItemPosition();

					Log.d(TAG, "Clicked " + favSelection);
					Playlist al = songDatabase.getActivePlaylist();
					// File file = new File(songName);
					dialog.dismiss();
					if(al == null || operationSong == null) {
						return;
					}
					// if(currentPath.equals(al.getFile().getPath())) {
					// return;
					// }

					Log.d(TAG, "Adding '%s' to playlist '%s'", operationSong.getPath(), al.getFile().getPath());

					switch(favSelection) {
					case 0:
						songDatabase.addToPlaylist(al, operationSong);
						break;
					case 1:
						operationSong.setSubTune(subTune);
						operationSong.setTitle(operationTitle);
						songDatabase.addToPlaylist(al, operationSong);
						break;
					case 2:
						for(int i = 0; i < operationTuneCount; i++) {
							operationSong.setSubTune(i);
							songDatabase.addToPlaylist(al, operationSong);
						}
						break;
					}

					// Playlist cpl = songDatabase.getCurrentPlaylist();
					// if(cpl != null && cpl.equals(al)) {
					// setDirectory(null, null);
					// }

				}
			});

			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
					dialogShowing = false;
					checkProgressDialog();
				}
			});
			break;
		default:
			builder.setMessage(id);
			builder.setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dialog, int id) {
					dialog.cancel();
				}
			});
			break;
		}

		AlertDialog alert = builder.create();
		return alert;
	}

	@Override
	public void onCreateContextMenu(ContextMenu menu, View v, ContextMenuInfo menuInfo) {
		super.onCreateContextMenu(menu, v, menuInfo);

		AdapterView.AdapterContextMenuInfo info = (AdapterView.AdapterContextMenuInfo) menuInfo;
		if(info == null) {
			return;
		}
		Log.d(TAG, "POS %d", info.position);
		Cursor cursor = currentPlaylistView.getCursor(info.position);
		int type = SongDatabase.TYPE_FILE;
		int t = cursor.getColumnIndex("TYPE");
		if(t >= 0) {
			type = cursor.getInt(t);
		}

		//File file = currentPlaylistView.getFile(info.position);

		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.songmenu, menu);

		MenuItem aitem = menu.findItem(R.id.add_to_plist);
		Playlist pl = songDatabase.getActivePlaylist();
		if(pl != null) {
			String s = aitem.getTitle().toString();
			aitem.setTitle(s.replace("[playlist]", pl.getTitle()));
		}
		
		//menu.getItem(R.id.paste).setVisible(clipBoardFile != null);


		if(songDatabase.getCurrentPlaylist() != null) {
			menu.setGroupVisible(R.id.in_playlist, true);
			menu.setGroupVisible(R.id.on_file, false);
			menu.setGroupVisible(R.id.on_dir, false);
			menu.setGroupVisible(R.id.on_plist, false);
			return;
		} else {
			menu.setGroupVisible(R.id.in_playlist, false);
		}

		switch(type) {
		case SongDatabase.TYPE_FILE:
			menu.setGroupVisible(R.id.on_file, true);
			menu.setGroupVisible(R.id.on_dir, false);
			menu.setGroupVisible(R.id.on_plist, false);
			break;

		case SongDatabase.TYPE_DIR:
		case SongDatabase.TYPE_ARCHIVE:
			menu.setGroupVisible(R.id.on_file, false);
			menu.setGroupVisible(R.id.on_dir, true);
			menu.setGroupVisible(R.id.on_plist, false);
			break;

		case SongDatabase.TYPE_PLIST:
			menu.setGroupVisible(R.id.on_file, false);
			menu.setGroupVisible(R.id.on_dir, false);
			menu.setGroupVisible(R.id.on_plist, true);
			break;
		}
	}

	@Override
	public boolean onContextItemSelected(MenuItem item) {
		// SQLiteDatabase db;
		AdapterContextMenuInfo info = (AdapterContextMenuInfo) item.getMenuInfo();
		// PlayListView.FileInfo finfo = (PlayListView.FileInfo)
		// playListView.getItemAtPosition(info.position);
		// Cursor cursor = playListView.getCursor(info.position);
		File file = currentPlaylistView.getFile(info.position);
		operationSong = new SongFile(currentPlaylistView.getPath(info.position));
		Log.d(TAG, "%d %s %d %d", item.getItemId(), item.getTitle(), info.position, info.id);
		// int pi = cursor.getColumnIndex("PATH");
		// String path = playListView.getDirectory();
		// if(pi >= 0) {
		// path = cursor.getString(pi);
		// }
		Playlist pl = songDatabase.getCurrentPlaylist();
		Playlist al = songDatabase.getActivePlaylist();
		
		SongFile song = pl != null ? pl.getSong(info.position) : null;
		
		if(song != null) operationSong = song;
		
		if(song != null) {
			Log.d(TAG, "Operating on %s by %s", song.getTitle(), song.getComposer());
		}


		switch(item.getItemId()) {
		case R.id.go_dir:
			setDirectory(operationSong.getParent(), playListView);
			currentPlaylistView.setScrollPosition(file.getPath());
			// flipper.setDisplayedChild(0);
			flipTo(FILE_VIEW);
			break;
		case R.id.set_plist:
			songDatabase.setActivePlaylist(file);
			break;
		case R.id.add_to_plist:
			if(al != null) {
				if(!currentPath.equals(al.getFile().getPath())) {
					// al.add(file);
					songDatabase.addToPlaylist(al, operationSong);
				}
			}
			break;
		// case R.id.favorite:
		// songDatabase.addFavorite(file);
		// break;
		case R.id.cut:
			if(pl != null) {
				//pl.remove(file);
				pl.remove(info.position);
				clipBoardFile = song;
				setDirectory(null);
			}
			break;
		case R.id.paste:
			if(pl != null && clipBoardFile != null) {
				//pl.remove(file);
				pl.insert(info.position, clipBoardFile);
				clipBoardFile = null;
				setDirectory(null);
			}
			break;
			

		case R.id.del_dir:
			//operationFile = file;
			operationSong = new SongFile(file);
			runConfirmable(R.string.do_del_dir, new Runnable() {
				@Override
				public void run() {
					if(songDatabase.deleteDir(operationSong.getFile())) {
						delDir(operationSong.getFile());
						setDirectory(null);
					}
				}
			});
			break;

		case R.id.del_file:
			//operationFile = file;
			operationSong = new SongFile(file);
			runConfirmable(R.string.do_del_file, new Runnable() {
				@Override
				public void run() {
					if(songDatabase.deleteFile(operationSong)) {
						operationSong.delete();
						setDirectory(null);
					}
				}
			});
			break;

		case R.id.make_wav:
			showDialog(R.string.make_wav);			
			break;

		case R.id.del_plist:
			//operationFile = file;
			operationSong = new SongFile(file);
			if(operationSong.getName().equals("Favorites.plist")) {
				break;
			}
			runConfirmable(R.string.do_del_plist, new Runnable() {
				@Override
				public void run() {
					if(songDatabase.deleteFile(operationSong)) {
						operationSong.delete();
						setDirectory(null);
						Playlist apl = songDatabase.getActivePlaylist();
						if(apl.getFile().equals(operationSong.getFile())) {
							File mf = new File(modsDir, "Favorites.plist");
							songDatabase.setActivePlaylist(mf);
						}
					}
				}
			});
			break;

		case R.id.remove_all:
			if(pl != null) {
				//operationFile = pl.getFile();
				operationSong = new SongFile(pl.getFile());
				Log.d(TAG, "Clearing playlist %s", pl.getFile().getPath());
				runConfirmable(R.string.do_remove_all, new Runnable() {
					@Override
					public void run() {
						Playlist.getPlaylist(operationSong.getFile()).clear();
						setDirectory(null);
					}
				});
			}

			break;
		default:
			return super.onContextItemSelected(item);
		}
		return true;
	}

	private void runConfirmable(int textid, Runnable runnable) {
		confirmables.put(textid, runnable);
		showDialog(textid);
	}

	private void delDir(File dd) {

		if(dd.isDirectory()) {
			File[] files = dd.listFiles();
			for(File f : files) {
				delDir(f);
			}
		}
		dd.delete();
	}

}
