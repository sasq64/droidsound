package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.net.URI;
import java.nio.channels.FileChannel;
import java.util.HashMap;
import java.util.Map;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.app.SearchManager;
import android.content.BroadcastReceiver;
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
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.os.PowerManager;
import android.preference.PreferenceManager;
import android.speech.tts.TextToSpeech;
import android.text.Html;
import android.text.method.ScrollingMovementMethod;
import android.util.Log;
import android.view.ContextMenu;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.view.animation.Animation;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.ViewFlipper;
import android.widget.AdapterView.AdapterContextMenuInfo;
import android.widget.AdapterView.OnItemClickListener;

import com.ssb.droidsound.PlayListView.FileInfo;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.service.PlayerService;

public class PlayerActivity extends Activity implements PlayerServiceConnection.Callback {
	private static final String TAG = "PlayerActivity";

	//public static final String DROIDSOUND_VERSION = "1.1beta3";
	public static final int VERSION = 16;

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
	private File currentPath;

	private BroadcastReceiver receiver;

	private SQLiteDatabase db;

	private int backDown;
	private boolean atTop;

	private String songTitle;
	private String songComposer;

	private String searchQuery;
	private String dirTitle;
	private String dirSubTitle;
	private String[] songDetails;
	private String indexSetting;

	private static final int TTS_UNCHECKED = -1000;
	private static final int TTS_OK = 2;
	private static final int TTS_UNINSTALLED = 0;
	private static final int TTS_UNINSTALLED_ASK = 1;

	private int ttsStatus = TTS_UNCHECKED;

	private Config lastConfig;

	private Map<Integer, Runnable> confirmables = new HashMap<Integer, Runnable>();

	private int songState;

	private File operationFile;

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

	private int operationTune;

	private String operationTitle;

	private int operationTuneCount;

	private TextView plinfoText;

	private int foundVersion;

	protected boolean dialogShowing;

	private TextView lowText;

	private float aTime = 0;

	protected void finalize() throws Throwable {
		Log.v(TAG, "########## Activity finalize");
	};

	private void setDirectory(File f, PlayListView plv) {

		if(plv == null) {
			plv = currentPlaylistView;
		}

		if(f == null) {
			String p = plv.getPath();
			if(p != null) {
				f = new File(p);
			} else if(currentPlaylistView == searchListView) {
				searchCursor.requery();
				searchListView.setCursor(searchCursor, null);
				flipTo(SEARCH_VIEW);
				return;
			} else {
				return;
			}
		}

		Cursor cursor = songDatabase.getFilesInPath(f.getPath(), sortOrder);
		plv.setCursor(cursor, f.getPath());


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
			currentPath = f;
		} else if(plv == searchListView) {
			flipTo(SEARCH_VIEW);
		}

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
			File f = new File(plv.getPath());
			setDirectory(f.getParentFile(), plv);
			currentPlaylistView.setScrollPosition(f);
			if(plv == searchListView) {
				searchDirDepth--;
			}

		} else {
		}
	}

	@Override
	protected void onNewIntent(Intent intent) {
		setIntent(intent);
		Log.v(TAG, "INTENT " + intent.getAction());

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
			Log.v(TAG, String.format("<<NEW INTENT>> Want to share '%s'", intent.getDataString()));			
			Intent newIntent = new Intent(intent);
			intent.setAction(Intent.ACTION_VIEW);
			newIntent.setClass(this, PlayerService.class);
			startService(newIntent);
			
		} else if(Intent.ACTION_SEARCH.equals(intent.getAction())) {
			String query = intent.getStringExtra(SearchManager.QUERY);
			Log.v(TAG, "QUERY " + query);
			if(searchCursor != null) {
				searchCursor.realClose();
			}
			searchCursor = new SearchCursor(songDatabase.search(query, currentPath.getPath(), sortOrder));
			searchQuery = query;
			searchDirDepth = 0;
			if(searchCursor != null) {
				searchListView.setCursor(searchCursor, null);
				currentPlaylistView = searchListView;
				flipTo(SEARCH_VIEW);
			}
		}
	}

	private void flipTo(int what) {
		flipTo(what, true);
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
		Log.v(TAG, "#### onCreate()");

		DroidSoundPlugin.setContext(getApplicationContext());

		// SongFile sf = new SongFile("/test/MDAT.MonkeyIsland");
		// sf = new SongFile("MonkeyIsland");
		// sf = new SongFile("/path/to/myfile.mod;2");
		// sf = new SongFile("/path/to/myfile.mod;-1;800");

		Intent intent = getIntent();
		Log.v(TAG, String.format("Intent %s / %s", intent.getAction(), intent.getDataString()));
		if(Intent.ACTION_VIEW.equals(intent.getAction())) {
			String music = intent.getDataString();

			if(music.toUpperCase().endsWith(".ZIP")) {

				if(music.startsWith("file:/")) {
					music = music.substring(6);
				}

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
			Log.v(TAG, String.format(">> Want to share '%s'", intent.getStringExtra(Intent.EXTRA_TEXT)));
			
			Bundle bundle = intent.getExtras();
			for(String s : bundle.keySet()) {
				Log.v(TAG, s);
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
		goinfoButton = (ImageButton) findViewById(R.id.go_info_button);
		flipper = (ViewFlipper) findViewById(R.id.flipper);
		// seekFlipper = (ViewFlipper) findViewById(R.id.seek_flipper);
		songSeeker = (SeekBar) findViewById(R.id.song_seek);
		

		searchButton = (ImageButton) findViewById(R.id.search_button);
		titleBar = (LinearLayout) findViewById(R.id.title_bar);
		shuffleText = (TextView) findViewById(R.id.shuffle_text);
		repeatText = (TextView) findViewById(R.id.repeat_text);
		plusText = (TextView) findViewById(R.id.plus_text);
		wakeText = (TextView) findViewById(R.id.wake_text);

		lowText = (TextView) findViewById(R.id.low_text);

		plinfoText = (TextView) findViewById(R.id.plinfo_text);

		prefs = PreferenceManager.getDefaultSharedPreferences(this);

		boolean indexUnknown = prefs.getBoolean("extensions", false);
		FileIdentifier.setIndexUnknown(indexUnknown);

		seekingSong = 0;

		currentPlaylistView = playListView;

		String md = prefs.getString("modsDir", null);
		modsDir = new File("/XXX");
		if(md == null) {
			File extFile = Environment.getExternalStorageDirectory();
			if(extFile != null) {
				File mf = new File(extFile, "MODS");
				if(!mf.exists()) {
					mf.mkdir();
				}

				if(!mf.exists()) {
					showDialog(R.string.create_moddir_failed);
					dialogShowing = true;
				} else {
					modsDir = mf;
					Editor editor = prefs.edit();
					editor.putString("modsDir", modsDir.getPath());
					editor.commit();
					// showDialog(12);
				}

			} else {
				showDialog(R.string.sdcard_not_found);
				dialogShowing = true;
			}
		} else {
			modsDir = new File(md);
		}

		if(!modsDir.exists()) {
			showDialog(R.string.sdcard_not_found);
			dialogShowing = true;
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

		String cp = prefs.getString("currentPath", null);
		if(cp == null) {
			currentPath = modsDir;
		} else {
			currentPath = new File(cp);
		}

		atTop = currentPath.equals(modsDir);

		receiver = new BroadcastReceiver() {
			@Override
			public void onReceive(Context context, Intent intent) {
				// TODO Auto-generated method stub

				if(intent.getAction().equals("com.sddb.droidsound.OPEN_DONE")) {
					Log.v(TAG, "Open done!");

					String s = prefs.getString("indexing", "Basic");
					int imode = SongDatabase.INDEX_BASIC;
					if(s.equals("Full")) {
						imode = SongDatabase.INDEX_FULL;
					} else if(s.equals("None")) {
						imode = SongDatabase.INDEX_NONE;
					}
					songDatabase.setIndexMode(imode);

					// playListView.rescan();
					setDirectory(null, playListView);

					if(lastConfig != null) {
						Log.v(TAG, "CONFIG CHANGE");
					} else {
						Log.v(TAG, "SCANNING");
						songDatabase.scan(false, modsDir.getPath());
					}

					// songDatabase.scan(false, modsDir);
				} else if(intent.getAction().equals("com.sddb.droidsound.SCAN_DONE")) {

					if(progressDialog != null) {
						progressDialog.cancel();
						progressDialog = null;
					}

					Log.v(TAG, "Scan done!");
					setDirectory(null, playListView);
					// playListView.rescan();
				} else if(intent.getAction().equals("com.sddb.droidsound.SCAN_UPDATE")) {
					Log.v(TAG, "Scan update!");
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

				}/*
				 * else
				 * if(intent.getAction().equals("com.sddb.droidsound.DOWNLOAD_DONE"
				 * )) { String path = intent.getStringExtra("PATH"); Toast t =
				 * Toast.makeText(PlayerActivity.this, path + " downloaded",
				 * Toast.LENGTH_SHORT); t.show(); songDatabase.scan(false,
				 * modsDir.getPath()); }
				 */
			}
		};

		IntentFilter filter = new IntentFilter();
		filter.addAction("com.sddb.droidsound.OPEN_DONE");
		filter.addAction("com.sddb.droidsound.SCAN_DONE");
		filter.addAction("com.sddb.droidsound.SCAN_UPDATE");
		// filter.addAction("com.sddb.droidsound.DOWNLOAD_DONE");
		registerReceiver(receiver, filter);

		Log.v(TAG, String.format("MODS at %s", modsDir));

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
				Log.v(TAG, "Done");
			} catch (IOException e2) {
				// TODO Auto-generated catch block
				e2.printStackTrace();
			}
		}

		mf = new File(modsDir, "Favorites.plist");
		if(!mf.exists()) {
			try {
				Log.v(TAG, "Trying to write Favorites");
				FileWriter fw = new FileWriter(mf);
				fw.close();
				Log.v(TAG, "Done");
			} catch (IOException e2) {
				// TODO Auto-generated catch block
				e2.printStackTrace();
			}
		}

		new File(modsDir, "Favorites.lnk").delete();

		boolean created = false;

		if(songDatabase == null) {
			Log.v(TAG, "############ CREATING static SongDatabase object ##############");

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
			songDatabase.setActivePlaylist(mf);

			DroidSoundPlugin.setOptions(prefs);

			shuffleSongs = prefs.getBoolean("shuffle", false);

		}
		shuffleText.setText(shuffleSongs ? "RND" : "SEQ");
		// repeatText.setText("CONT");

		String b = prefs.getString("buffer", "Long");
		player.setOption(PlayerService.OPTION_BUFFERSIZE, b);

		if(!created && lastConfig == null) {
			songDatabase.open();
			songDatabase.scan(false, modsDir.getPath());
		}

		if(ttsStatus == TTS_UNCHECKED) {
			Intent checkIntent = new Intent();
			checkIntent.setAction(TextToSpeech.Engine.ACTION_CHECK_TTS_DATA);
			startActivityForResult(checkIntent, 1234);
		}

		// if(mf.exists()) {
		// songDatabase.setActivePlaylist(mf);
		// }

		listClickListener = new OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

				PlayListView plv = (PlayListView) parent;

				FileInfo fi = (FileInfo) plv.getItemAtPosition(position);

				Log.v(TAG, String.format("Clicked %s got file %s", plv, fi.getPath()));

				if(fi != null) {

					if(fi.type == SongDatabase.TYPE_DIR || fi.type == SongDatabase.TYPE_ARCHIVE || fi.type == SongDatabase.TYPE_PLIST) {
						setDirectory(fi.getFile(), plv);
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
								for(int i = 0; i < files.length; i++) {
									if(files[i].equals(fi)) {
										index = i;
									}
								}
								Log.v(TAG, String.format("Playing Playlist %s %s", plist.getFile().getPath(), plist.toString()));
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
				Log.v(TAG, String.format("NEXT %d %d", subTune, subTuneCount));
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
					operationFile = songFile.getFile();
					operationTune = subTune;
					operationTitle = null;
					operationTuneCount = subTuneCount;
					Log.v(TAG, String.format("%s - %s ADD", songTitle != null ? songTitle : "null", subtuneTitle != null ? subtuneTitle : "null"));
					if(songTitle != null && subtuneTitle != null) {
						// operationTitle = songTitle + " - " + subtuneTitle;
						operationTitle = subtuneTitle + " (" + songTitle + ")";
					}
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
		
	/*	
		titleText.setOnClickListener(new OnClickListener() {
			

			@Override
			public void onClick(View v) {
				sortOrder = (sortOrder + 1) % 3;
				Log.v(TAG, String.format("Sortorder now %d", sortOrder));
				flipTo(SAME_VIEW);
			}
		});
*/
		
		titleBar.setOnClickListener(new OnClickListener() {
			

			@Override
			public void onClick(View v) {
				//flipTo(SAME_VIEW);
				if(currentPlaylistView == playListView) {
					sortOrder = (sortOrder + 1) % 3;
					String p = currentPlaylistView.getPath();
					Cursor cursor = songDatabase.getFilesInPath(p, sortOrder);
					currentPlaylistView.setCursor(cursor, p);
				} else if(currentPlaylistView == searchListView) {
					sortOrder = (sortOrder + 1) % 3;
					if(searchCursor != null) {
						searchCursor.realClose();
					}
					searchCursor = new SearchCursor(songDatabase.search(searchQuery, currentPath.getPath(), sortOrder));
					//searchDirDepth = 0;
					if(searchCursor != null) {
						searchListView.setCursor(searchCursor, null);
						//currentPlaylistView = searchListView;
						flipTo(SAME_VIEW);
					}
				}
				Log.v(TAG, String.format("TB Sortorder now %d", sortOrder));
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
				Log.v(TAG, "Stop tracking");
				player.seekTo(songLength * seekBar.getProgress() * 10);
				seekingSong = 5;
			}

			@Override
			public void onStartTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				Log.v(TAG, "Start tracking");
				seekingSong = 5;
			}

			@Override
			public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
				if(fromUser) {
					// Log.v(TAG, String.format("Changed %d", progress));
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
			Log.v(TAG, "Successful");
			return true;
		} else if(copyFile(src, dest)) {
			Log.v(TAG, "COPY Successful");
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

		Log.v(TAG, "MOVE FILE " + f.getPath() + " TO " + t.getPath());

		if(t.exists()) {
			showDialog(R.string.zip_import_replace);
			moveFileHere = null;
			return;
		}

		if(f.renameTo(t)) {
			Log.v(TAG, "Successful");
			if(songDatabase != null) {
				songDatabase.scan(false, modsDir.getPath());
			}
		} else if(copyFile(f, t)) {
			Log.v(TAG, "COPY Successful");
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
		Log.v(TAG, String.format("Got speech result %d", resultCode));
		if(requestCode == 1234) {
			Log.v(TAG, String.format("Got speech result %d", 12345));
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
		Log.v(TAG, String.format("#### KEY EVENT %s", event.toString()));
		return super.dispatchKeyEvent(event);
	}

	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		Log.v(TAG, String.format("%%%% DOWN %d", keyCode));
		// if(keyCode == KeyEvent.KEYCODE_HEADSETHOOK) {
		// Log.v(TAG, String.format("MEDIA BUTTON DOWN %d",
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
			songDatabase.quit();
			songDatabase = null;
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
				operationFile = songFile.getFile();
				operationTune = subTune;
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
			backDown++;
			if(backDown == 3) {
				if(currentPlaylistView == searchListView) {
					searchDirDepth = 0;
					searchListView.setCursor(searchCursor, null);
					flipTo(SEARCH_VIEW);
				} else {
					setDirectory(modsDir, playListView);
					currentPlaylistView.setScrollPosition(null); // new
					// File(songName));
				}
			}
			return true;
		}

		backDown = 0;
		return super.onKeyDown(keyCode, event);
	}

	@Override
	public boolean onKeyUp(int keyCode, KeyEvent event) {
		// if(keyCode == KeyEvent.KEYCODE_HEADSETHOOK) {
		// Log.v(TAG, String.format("MEDIA BUTTON UP %d",
		// event.getRepeatCount()));
		// return true;
		// }
		if(keyCode == KeyEvent.KEYCODE_BACK || keyCode == KeyEvent.KEYCODE_DEL) {
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
		}
		return super.onKeyUp(keyCode, event);
	}

	@Override
	protected void onResume() {
		super.onResume();
		Log.v(TAG, "#### onResume()");

		player.bindService(this, this);

		if(!songDatabase.isScanning() && progressDialog != null) {
			progressDialog.cancel();
			progressDialog = null;
			// playListView.rescan();
			setDirectory(null, playListView);
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
		Log.v(TAG, "#### onPause()");

		indexSetting = prefs.getString("indexing", "Basic");

		Editor editor = prefs.edit();
		editor.putString("currentPath", currentPath.getPath());
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
		Log.v(TAG, "#### onDestroy()");

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

	private static String[] repnames = { "CONT", "----", "REPT", "CS", "RS" };

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
		case PlayerService.SONG_LENGTH:
			if(value < 0) {
				// TODO: Hide length
				value = 0;
			}
			songLength = value / 1000;
			Log.v(TAG, String.format("Songlength %02d:%02d", songLength / 60, songLength % 60));
			songTotalText.setText(String.format("%02d:%02d", songLength / 60, songLength % 60));
			songSeeker.setProgress(0);
			break;
		case PlayerService.SONG_POS:
			if(seekingSong == 0) {
				songPos = value / 1000;
				songSecondsText.setText(String.format("%02d:%02d", songPos / 60, songPos % 60));
				if(songLength > 0)
					songSeeker.setProgress(100 * songPos / songLength);
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
			subTune = value;
			songSubtunesText.setText(String.format("[%02d/%02d]", subTune + 1, subTuneCount));
			break;
		case PlayerService.SONG_TOTALSONGS:
			subTuneCount = value;
			songSubtunesText.setText(String.format("[%02d/%02d]", subTune + 1, subTuneCount));
			break;
		case PlayerService.SONG_STATE:
			Log.v(TAG, String.format("State now %d", value));
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
		case PlayerService.SONG_PLAYLIST:
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
			break;
		case PlayerService.SONG_FILENAME:
			playListView.setHilighted(value);
			searchListView.setHilighted(value);
			// songName = value;
			songFile = new SongFile(value);
			break;
		case PlayerService.SONG_SUBTUNE_TITLE:
			subtuneTitle = value;
			if(subtuneTitle != null && subtuneTitle.length() == 0) subtuneTitle = null;
			flipTo(SAME_VIEW);
			break;
		case PlayerService.SONG_SUBTUNE_AUTHOR:
			subtuneAuthor = value;
			flipTo(SAME_VIEW);
			break;
		case PlayerService.SONG_TITLE:
			songTitle = value;
			flipTo(SAME_VIEW);
			songDetails = player.getSongInfo();
			subtuneTitle = null;
			if(songDetails != null) {
				StringBuilder sb = new StringBuilder("<tt>");
				for(int i = 0; i < songDetails.length; i += 2) {
					// Log.v(TAG, songDetails[i]);
					// Log.v(TAG, songDetails[i+1]);
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
	public boolean onOptionsItemSelected(MenuItem item) {
		int choice = item.getItemId();
		switch(choice) {
		case R.id.settings:
			startActivity(new Intent(this, SettingsActivity.class));
			break;
		case R.id.quit:
			player.stop();
			songDatabase.quit();
			songDatabase = null;

			finish();
			break;
		case R.id.new_:
			showDialog(R.string.new_);
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
		AlertDialog ad = ((AlertDialog) dialog);

		switch(id) {
		case R.string.do_del_dir:
		case R.string.do_del_file:
		case R.string.do_del_plist:
		case R.string.do_remove_all:
			if(operationFile == null) {
				ad.cancel();
				return;
			}
			break;
		case R.string.add_to_plist:

			if(songTitle == null || operationFile == null) {
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

	/*
	 * 
	 * I/EventHub( 2621): New keyboard: device->id=0x10004 devname='Broadcom
	 * Bluetooth HID' propName='hw.keyboards.65540.devname'
	 * keylayout='/system/usr/keylayout/qwerty.kl' I/EventHub( 2621): New
	 * device: path=/dev/input/event4 name=Broadcom Bluetooth HID id=0x10004 (of
	 * 0x5) index=5 fd=134 classes=0x3 I/KeyInputQueue( 2621): Device added:
	 * id=0x10004, name=Broadcom Bluetooth HID, classes=3 I/ActivityManager(
	 * 2621): Config changed: { scale=1.0 imsi=240/1 loc=en_GB touch=3
	 * keys=2/1/2 nav=1/1 orien=1 layout=34 uiMode=17 seq=30 FlipFont=0}
	 * 
	 * 
	 * W/KeyCharacterMap( 4666): Can't open keycharmap file W/KeyCharacterMap(
	 * 4666): Error loading keycharmap file
	 * '/system/usr/keychars/Broadcom_Bluetooth_HID.kcm.bin'.
	 * hw.keyboards.65540.devname='Broadcom Bluetooth HID' W/KeyCharacterMap(
	 * 4666): Using default keymap: /system/usr/keychars/qwerty.kcm.bin
	 */
	@Override
	protected Dialog onCreateDialog(int id) {

		AlertDialog.Builder builder = new AlertDialog.Builder(this);

		if(confirmables.containsKey(id)) {
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
		case R.string.new_:
			builder.setTitle(id);
			builder.setSingleChoiceItems(R.array.new_opts, -1, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					Log.v(TAG, "Clicked " + which);
					dialog.dismiss();
					switch(which) {
					case 0:
						showDialog(R.string.name_folder);
						break;
					case 1:
						showDialog(R.string.name_playlist);
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
		case R.string.name_folder:
			final EditText input2 = new EditText(this);
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

					Log.v(TAG, "Clicked " + favSelection);
					Playlist al = songDatabase.getActivePlaylist();
					// File file = new File(songName);
					dialog.dismiss();
					if(al == null || operationFile == null) {
						return;
					}
					// if(currentPath.equals(al.getFile().getPath())) {
					// return;
					// }

					Log.v(TAG, String.format("Adding '%s' to playlist '%s'", operationFile.getPath(), al.getFile().getPath()));

					switch(favSelection) {
					case 0:
						songDatabase.addToPlaylist(al, new SongFile(operationFile));
						break;
					case 1:
						songDatabase.addToPlaylist(al, new SongFile(operationFile, operationTune, operationTitle));
						break;
					case 2:
						for(int i = 0; i < operationTuneCount; i++) {
							songDatabase.addToPlaylist(al, new SongFile(operationFile, i, null));
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
		Log.v(TAG, String.format("POS %d", info.position));
		Cursor cursor = currentPlaylistView.getCursor(info.position);
		int type = SongDatabase.TYPE_FILE;
		int t = cursor.getColumnIndex("TYPE");
		if(t >= 0) {
			type = cursor.getInt(t);
		}

		File file = currentPlaylistView.getFile(info.position);

		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.songmenu, menu);

		MenuItem aitem = menu.findItem(R.id.add_to_plist);
		Playlist pl = songDatabase.getActivePlaylist();
		if(pl != null) {
			String s = aitem.getTitle().toString();
			aitem.setTitle(s.replace("[playlist]", pl.getTitle()));
		}

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
		Log.v(TAG, String.format("%d %s %d %d", item.getItemId(), item.getTitle(), info.position, info.id));
		// int pi = cursor.getColumnIndex("PATH");
		// String path = playListView.getDirectory();
		// if(pi >= 0) {
		// path = cursor.getString(pi);
		// }
		Playlist pl = songDatabase.getCurrentPlaylist();
		Playlist al = songDatabase.getActivePlaylist();

		switch(item.getItemId()) {
		case R.id.go_dir:
			setDirectory(file.getParentFile(), playListView);
			currentPlaylistView.setScrollPosition(file);
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
					songDatabase.addToPlaylist(al, new SongFile(file));
				}
			}
			break;
		// case R.id.favorite:
		// songDatabase.addFavorite(file);
		// break;
		case R.id.remove:
			if(pl != null) {
				pl.remove(file);
				setDirectory(null, null);
			}
			break;

		case R.id.del_dir:
			operationFile = file;
			runConfirmable(R.string.do_del_dir, new Runnable() {
				@Override
				public void run() {
					if(songDatabase.deleteDir(operationFile)) {
						delDir(operationFile);
						setDirectory(null, null);
					}
				}
			});
			break;

		case R.id.del_file:
			operationFile = file;
			runConfirmable(R.string.do_del_file, new Runnable() {
				@Override
				public void run() {
					if(songDatabase.deleteFile(operationFile)) {
						operationFile.delete();
						setDirectory(null, null);
					}
				}
			});
			break;

		case R.id.del_plist:
			operationFile = file;
			if(operationFile.getName().equals("Favorites.plist")) {
				break;
			}
			runConfirmable(R.string.do_del_plist, new Runnable() {
				@Override
				public void run() {
					if(songDatabase.deleteFile(operationFile)) {
						operationFile.delete();
						setDirectory(null, null);
						Playlist apl = songDatabase.getActivePlaylist();
						if(apl.getFile().equals(operationFile)) {
							File mf = new File(modsDir, "Favorites.plist");
							songDatabase.setActivePlaylist(mf);
						}
					}
				}
			});
			break;

		case R.id.remove_all:
			if(pl != null) {
				operationFile = pl.getFile();
				Log.v(TAG, String.format("Clearing playlist %s", pl.getFile().getPath()));
				runConfirmable(R.string.do_remove_all, new Runnable() {
					@Override
					public void run() {
						Playlist.getPlaylist(operationFile).clear();
						setDirectory(null, null);
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
