package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.lang.ref.WeakReference;
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
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.database.Cursor;
import android.database.CursorWrapper;
import android.media.AudioManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceManager;
import android.speech.tts.TextToSpeech;
import android.support.v4.view.ViewPager;
import android.text.InputType;
import android.util.SparseArray;
import android.util.TypedValue;
import android.view.ContextMenu;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.AdapterView.AdapterContextMenuInfo;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.ssb.droidsound.database.CSDBParser;
import com.ssb.droidsound.database.MediaSource;
import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.playlistview.FileInfo;
import com.ssb.droidsound.playlistview.PlayListView;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.service.PlayerService;
import com.ssb.droidsound.utils.Log;
import com.ssb.droidsound.utils.NativeZipFile;
import com.ssb.droidsound.utils.Unzipper;
import com.viewpagerindicator.PageIndicator;
//import android.os.PowerManager;

@SuppressWarnings("deprecation") // No fragment support 
public class PlayerActivity extends Activity  {
	private static final String TAG = "PlayerActivity";
	public static final int VERSION = 18;

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

	private ImageButton searchButton;

	private Pager flipper;

	private TextView dirText;
	private TextView pathText;
	private TextView searchTitle;
	private TextView searchSubtitle;


	private OnItemClickListener listClickListener;

	private PlayListView playListView;
	private PlayListView searchListView;

	private PlayListView currentPlaylistView;

	private ProgressDialog progressDialog;

	private SearchCursor searchCursor;
	private SharedPreferences prefs;

	private int searchDirDepth;

	private File modsDir;
	private String currentPath;

	//private int backDown;
	private boolean atTop = true;

	private String searchQuery;
	private static final int TTS_UNCHECKED = -1000;
	private static final int TTS_OK = 2;
	private static final int TTS_UNINSTALLED = 0;
	private static final int TTS_UNINSTALLED_ASK = 1;

	private Config lastConfig;

	private SparseArray<Runnable> confirmables = new SparseArray<Runnable>();

	private ViewGroup playlistBar;
	private ViewGroup searchBar;


	//private PowerManager.WakeLock wakeLock;

	private File moveFileHere;

	private int foundVersion;

	protected boolean dialogShowing;

	protected PlayState state = new PlayState();
	private boolean backPressed;

	private RingToneCreator.RingTone currentRingTone;
	private RingToneCreator ringToneCreator;
	private PlayScreen playScreen;

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
				if(searchCursor != null) {
					searchCursor.requery();
					searchListView.setCursor(searchCursor, null);
					updateSearch();
				}
				return;
			} else {
				return;
			}
		}
		
		int so = state.sortOrderPlayList;
		if(plv == searchListView)
			so = state.sortOrderSearch;

		Cursor cursor = songDatabase.getFilesInPath(path, so);
		// Cursor cursor = songDatabase.getFilesInPath("http://swimmer.se/mp3/", sortOrder);
		plv.setCursor(cursor, path);

		File f = new File(path);

		if(f.equals(modsDir)) {
			atTop = true;
		} else {
			atTop = false;
		}
		if(plv == playListView) {
			state.dirTitle = songDatabase.getPathTitle();
			if(state.dirTitle == null) {
				state.dirTitle = f.getName();
			}
			state.dirSubTitle = f.getParent().replaceFirst(modsDir.getParent(), "");
			
			dirText.setText(state.dirTitle);
			pathText.setText(state.dirSubTitle);		
			//flipper.flipTo(FILE_VIEW);
			updateFileView();
			currentPath = path;
		} else if(plv == searchListView) {
			updateSearch();
		}

	}
	
	private void updateFileView() {
		String p2 = playListView.getPath();
		Cursor cursor = songDatabase.getFilesInPath(p2, state.sortOrderPlayList);
		playListView.setCursor(cursor, p2);
	}
	
	private void updateSearch() {
		if(searchQuery != null) {
			searchTitle.setText("SEARCH: " + searchQuery);
		} else {
			searchTitle.setText("SEARCH");
		}
		String p = searchListView.getPath();
		if(p != null) {
			String st = p.replaceFirst(modsDir.getParent(), "");
			searchSubtitle.setText(st);
		} else {
			searchSubtitle.setText("");
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
			updateSearch();
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
			searchCursor = new SearchCursor(songDatabase.search(query, currentPath, state.sortOrderSearch));
			searchQuery = query;
			searchDirDepth = 0;
			if(searchCursor != null) {
				searchListView.setCursor(searchCursor, null);
				currentPlaylistView = searchListView;				
				updateSearch();
			}
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

		state.ttsStatus = TTS_UNCHECKED;
		
		player = new PlayerServiceConnection();

		setContentView(R.layout.player);
		
		
		//ViewGroup ps = (ViewGroup) findViewById(R.id.play_screen);
		playScreen = new PlayScreen(state, player, this);
		
		
		//flipper = new Flipper(findViewById(R.id.flipper));
		
		int pixels = (int)TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, 10, getResources().getDisplayMetrics());
		ViewPager vp = (ViewPager) findViewById(R.id.flipper);
		vp.setPageMargin(pixels);
		//vp.setPageMarginDrawable(0x444444);
		
		PageIndicator titleIndicator = (PageIndicator)findViewById(R.id.titles);
		flipper = new Pager(vp, titleIndicator);
		
		
		//playListView = (PlayListView) findViewById(R.id.play_list);
		//searchListView = (PlayListView) findViewById(R.id.search_list);
		//playListView = new PlayListView(this);
		//searchListView = new PlayListView(this);
		LayoutInflater inflater = (LayoutInflater)getSystemService(Context.LAYOUT_INFLATER_SERVICE);
		ViewGroup pl = (ViewGroup) inflater.inflate(R.layout.playlist, null);
		playListView = (PlayListView) pl.findViewById(R.id.play_list);
		flipper.addView(pl);
		
		flipper.addView(playScreen.getView());
		
		
		ViewGroup sl = (ViewGroup) inflater.inflate(R.layout.searchlist, null);
		searchListView = (PlayListView) sl.findViewById(R.id.search_list);
		flipper.addView(sl);


		searchButton = (ImageButton) sl.findViewById(R.id.search_button);
		searchBar = (ViewGroup) sl.findViewById(R.id.title_bar);
		playlistBar = (ViewGroup) pl.findViewById(R.id.title_bar);
		//titleText = (TextView) pl.findViewById(R.id.list_title);		
		//subtitleText = (TextView) pl.findViewById(R.id.list_subtitle);
		dirText = (TextView) pl.findViewById(R.id.dir_text);
		pathText = (TextView) pl.findViewById(R.id.path_text);
		searchTitle = (TextView) sl.findViewById(R.id.search_text);
		searchSubtitle = (TextView) sl.findViewById(R.id.subsearch_text);

		
		//flipper.addView(playListView);
		//flipper.addView(playScreen.getView());
		//flipper.addView(searchListView);
		
		flipper.onFlip(new Pager.FlipCallback() {
			@Override
			public void flipped(int to, int from, View v) {
				Log.d(TAG, "Flipped to %d", to);
				switch(to) {
				case INFO_VIEW:
					currentPlaylistView = null;
					break;
				case SEARCH_VIEW:
					currentPlaylistView = searchListView;
					break;
				case FILE_VIEW:
					currentPlaylistView = playListView;
					updateFileView();
					break;
				}			
			}
		});
		
	
		prefs = PreferenceManager.getDefaultSharedPreferences(this);

		state.seekingSong = 0;

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
		
		state.receiver = new BroadcastReceiver() {
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
/*
					String s = prefs.getString("indexing", "Basic");
					int imode = SongDatabase.INDEX_BASIC;
					if(s.equals("Full")) {
						imode = SongDatabase.INDEX_FULL;
					} else if(s.equals("None")) {
						imode = SongDatabase.INDEX_NONE;
					}
					songDatabase.setIndexMode(imode);
*/

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
		registerReceiver(state.receiver, filter);


		boolean created = false;

		if(songDatabase == null) {
			setupSongDatabase();
			created = true;
		}

		setDirectory(currentPath, null);

		if(foundVersion != VERSION) {
			dialogShowing = true;
			showDialog(R.string.unpack_examples);
		}

		checkProgressDialog();

		lastConfig = (Config) getLastNonConfigurationInstance();
		if(lastConfig != null) {
			// textToSpeech = lastConfig.textToSpeech;
			state.ttsStatus = lastConfig.ttsStatus;
			searchCursor = lastConfig.searchCursor;
			searchListView.setCursor(searchCursor, null);
			songDatabase.setActivePlaylist(new File(lastConfig.activePlaylist));
			searchQuery = lastConfig.query;
			state.shuffleSongs = lastConfig.shuffleSongs;
			flipper.flipTo(lastConfig.flipper, false);
		} else {
			CSDBParser.init();
			File mf = new File(modsDir, "Favorites.plist");
			songDatabase.setActivePlaylist(mf);

			DroidSoundPlugin.setOptions(prefs);

			state.shuffleSongs = prefs.getBoolean("shuffle", false);

		}
		// repeatText.setText("CONT");

		String b = prefs.getString("buffer", "Long");
		player.setOption(PlayerService.OPTION_BUFFERSIZE, b);


		if(!created && lastConfig == null) {
			Log.d(TAG, "OPEN DB");
			songDatabase.open();
			songDatabase.scan(false, modsDir.getPath());
			Log.d(TAG, "DONE");
		}

		if(state.ttsStatus == TTS_UNCHECKED) {
			try {
				Intent checkIntent = new Intent();
				checkIntent.setAction(TextToSpeech.Engine.ACTION_CHECK_TTS_DATA);
				startActivityForResult(checkIntent, 1234);
			} catch (RuntimeException exc) {
				exc.printStackTrace();
				state.ttsStatus = TTS_UNINSTALLED;
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
								state.songSelected = true;
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
						state.songSelected = true;
						// adapter.notifyDataSetChanged();
						// adapter.setSelectedPosition(position);
					}
				}
			}
		};

		//PowerManager pm = (PowerManager) getSystemService(Context.POWER_SERVICE);
		//wakeLock = pm.newWakeLock(PowerManager.SCREEN_DIM_WAKE_LOCK, "Droidsound");

		playListView.setOnItemClickListener(listClickListener);
		searchListView.setOnItemClickListener(listClickListener);

		registerForContextMenu(playListView);
		registerForContextMenu(searchListView);

		searchButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				onSearchRequested();
			}
		});


		player.setOption(PlayerService.OPTION_PLAYBACK_ORDER, state.shuffleSongs ? "R" : "S");


		/*wakeText.setOnClickListener(new OnClickListener() {
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
		});*/
		
		searchBar.setOnClickListener(new OnClickListener() {
			
			final int [] sortNames = new int [] { R.string.sort_name, R.string.sort_date, R.string.sort_author };

			@Override
			public void onClick(View v) {
				state.sortOrderSearch = (state.sortOrderSearch + 1) % 3;
				
				Toast toast = Toast.makeText(PlayerActivity.this, sortNames[state.sortOrderSearch], Toast.LENGTH_SHORT);
				toast.show();	
				
				if(searchCursor != null) {
					searchCursor.realClose();
				}
				Cursor cr = songDatabase.search(searchQuery, currentPath, state.sortOrderSearch);
				if(cr != null) {
					searchCursor = new SearchCursor(cr);
					searchListView.setCursor(searchCursor, null);
					//currentPlaylistView = searchListView;
					flipper.flipTo(SAME_VIEW);
				} else
					searchCursor = null;
				Log.d(TAG, "TB Sortorder now %d", state.sortOrderSearch);
			}
		});
		
		playlistBar.setOnClickListener(new OnClickListener() {
			
			final int [] sortNames = new int [] { R.string.sort_name, R.string.sort_date, R.string.sort_author };

			@Override
			public void onClick(View v) {
				state.sortOrderPlayList = (state.sortOrderPlayList + 1) % 3;
				
				Toast toast = Toast.makeText(PlayerActivity.this, sortNames[state.sortOrderPlayList], Toast.LENGTH_SHORT);
				toast.show();					
				
				String p = currentPlaylistView.getPath();
				Cursor cursor = songDatabase.getFilesInPath(p, state.sortOrderPlayList);
				currentPlaylistView.setCursor(cursor, p);
				Log.d(TAG, "TB Sortorder now %d", state.sortOrderPlayList);
			}
		});

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
	
	private void displayError(int what) {
		dialogShowing = true;
		showDialog(what);
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
		if(foundVersion != VERSION) {
			File tempFile = new File(modsDir, "Examples.zip");
			if(tempFile.exists()) {
				tempFile.delete();
			}
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
				state.ttsStatus = TTS_OK;
				boolean useSpeech = prefs.getBoolean("speech", false);
				player.setOption(PlayerService.OPTION_SPEECH, useSpeech ? "on" : "off");
			} else {
				state.ttsStatus = TTS_UNINSTALLED;
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
			if(t < state.subTuneCount) {
				state.subTune = t;
				player.setSubSong(state.subTune);
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
			if(state.subTune != 0 && state.subTuneCount != 0) {
				state.subTune -= 1;
				player.setSubSong(state.subTune);
			}
			break;
		case KeyEvent.KEYCODE_M:
			if((state.subTune + 1) < state.subTuneCount) {
				state.subTune += 1;
				player.setSubSong(state.subTune);
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
			if(state.songState == 1) {
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
			flipper.flipTo(NEXT_VIEW);
			break;
		case KeyEvent.KEYCODE_S:
			state.shuffleSongs = !state.shuffleSongs;
			player.setOption(PlayerService.OPTION_PLAYBACK_ORDER, state.shuffleSongs ? "R" : "S");
			// TODO shuffleText.setText(state.shuffleSongs ? "RND" : "SEQ");
			break;
		case KeyEvent.KEYCODE_R:
			if(state.songRepeat == 0) {
				state.songRepeat = 1;
			} else {
				state.songRepeat = 0;
			}
			player.setOption(PlayerService.OPTION_REPEATMODE, Integer.toString(state.songRepeat));
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
			if(state.songFile != null) {
				//operationFile = songFile.getFile();
				state.operationSong = new SongFile(state.songFile);
				//operationTune = subTune;
				state.operationTitle = null;
				state.operationTuneCount = state.subTuneCount;
				if(state.songTitle != null && state.subtuneTitle != null) {
					// operationTitle = songTitle + " - " + subtuneTitle;
					state.operationTitle = state.subtuneTitle + " (" + state.songTitle + ")";
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
				//flipper.flipTo(SEARCH_VIEW);
				updateSearch();
			} else if(currentPlaylistView == playListView) {
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
						updateFileView();
						flipper.flipTo(FILE_VIEW);
						if(state.songFile != null) {
							playListView.setScrollPosition(state.songFile.getPath());
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
		

		return super.onKeyUp(keyCode, event);
	}
	
	private static class ValueChangeHandler extends Handler {
		
		private WeakReference<PlayerActivity> activityRef;

		public ValueChangeHandler(PlayerActivity activity) {
			activityRef = new WeakReference<PlayerActivity>(activity);
		}
		
		@Override
		public void handleMessage(Message msg) {
			if(msg.obj != null)
				activityRef.get().stringChanged(msg.what, (String)msg.obj);
			else
				activityRef.get().intChanged(msg.what, msg.arg1);
		}
	}
	

	@Override
	protected void onResume() {
		super.onResume();
		Log.d(TAG, "#### onResume()");

		player.bindService(this, new ValueChangeHandler(this));
		
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

		if(speech && state.ttsStatus == TTS_UNINSTALLED) {
			// missing data, install it
			state.ttsStatus = TTS_UNINSTALLED_ASK;

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
		player.setOption(PlayerService.OPTION_DEFAULT_LENGTH, prefs.getString("default_length", "900"));		
		player.setOption(PlayerService.OPTION_CYCLE_SUBTUNES, prefs.getBoolean("subtunes", false) ? "on" : "off");

		state.playerSwitch = prefs.getBoolean("openplayer", true);
		

		String b = prefs.getString("buffer", "Long");
		player.setOption(PlayerService.OPTION_BUFFERSIZE, b);

		/*
		String s = prefs.getString("indexing", "Basic");
		int imode = SongDatabase.INDEX_BASIC;
		if(s.equals("Full")) {
			imode = SongDatabase.INDEX_FULL;
		} else if(s.equals("None")) {
			imode = SongDatabase.INDEX_NONE;
		}

		songDatabase.setIndexMode(imode);*/
	}

	@Override
	protected void onPause() {
		super.onPause();
		Log.d(TAG, "#### onPause()");

		//indexSetting = prefs.getString("indexing", "Basic");

		Editor editor = prefs.edit();
		editor.putString("currentPath", currentPath);
		editor.putBoolean("shuffle", state.shuffleSongs);
		editor.commit();

		Playlist.flushAll();

		//if(wakeLock.isHeld()) {
		//	wakeLock.release();
		//}

		player.unbindService(this);

		if(state.db != null) {
			state.db.close();
			state.db = null;
		}
	}

	@Override
	protected void onDestroy() {
		super.onDestroy();
		Log.d(TAG, "#### onDestroy()");

		if(state.receiver != null) {
			unregisterReceiver(state.receiver);
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

		c.ttsStatus = state.ttsStatus;
		c.searchCursor = searchCursor;
		c.query = searchQuery;
		c.shuffleSongs = state.shuffleSongs;
		Playlist al = songDatabase.getActivePlaylist();
		if(al != null) {
			c.activePlaylist = al.getFile().getPath();
		}
		searchCursor = null;
		c.flipper = flipper.getDisplayedChild();
		return c;
	}

	public static void hexdump(byte [] data) {
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<data.length; i++) {
			if(i % 8 == 0) {
				sb.append(String.format("\n%04x:  ", i));
			}
			sb.append(String.format("%02x ", data[i]));
		}
		Log.d(TAG, sb.toString());
	}
	
	public void intChanged(int what, int value) {
		
		if(what == 999) {
			displayError(R.string.player_crash);
			return;
		} else if (what == PlayerService.SONG_ERROR) {
			switch(value) {
			case 1:
				displayError(R.string.could_not_play);
				break;
			default:
				break;
			}
			return;
		}
		
		playScreen.intChanged(what, value);
	}

	public void stringChanged(int what, String value) {


		playScreen.stringChanged(what, value);
		
		switch(what) {
		case PlayerService.SONG_FILENAME:
			if(currentRingTone != null) {
				ringToneCreator.save(value);
				currentRingTone = null;
				break;
				
			}
			
			if(state.songSelected && state.playerSwitch) {
				flipper.flipTo(INFO_VIEW);
				state.songSelected = false;
			}
			
			state.songFile = new SongFile(value);
			String path = state.songFile.getFile().getPath();
			playListView.setHilighted(value);
			searchListView.setHilighted(value);
			// songName = value;
			
			Log.d(TAG, "############################## Song file is %s (%s)", value, path);
			
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
			NativeZipFile.closeCached();
			songDatabase.quit();
			songDatabase = null;
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
			if(state.operationSong == null) {
				ad.cancel();
				return;
			}
			break;
		case R.string.add_to_plist:
			ad = ((AlertDialog) dialog);
			if(state.songTitle == null || state.operationSong == null) {
				ad.cancel();
				return;
			}

			Button b = ad.getButton(DialogInterface.BUTTON_POSITIVE);
			ListView lv = ad.getListView();
			int i = lv.getCheckedItemPosition();

			if(i == ListView.INVALID_POSITION) {
				b.setEnabled(false);
			} else if(state.operationTuneCount < 2 && i > 0) {
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
			if(ringToneCreator == null)
				ringToneCreator = new RingToneCreator(this);
			ringToneCreator.onCreateWav(new RingToneCreator.Callback() {
				@Override
				public void createWav(RingToneCreator.RingTone rt) {
					File droidDir = new File(Environment.getExternalStorageDirectory(), "droidsound");
					File file = new File(droidDir, "ringtones");
					file.mkdir();
					file = new File(file, rt.name + ".wav"); 
					int flags = 0;
					if(rt.HQ) flags |= 2;
					currentRingTone = rt;
					player.dumpWav(state.operationSong.getPath(), file.getPath(), currentRingTone.seconds * 1000, flags);
				}
			});
			return ringToneCreator.createDialog();		
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

					if(state.operationTuneCount < 2) {
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
					if(al == null || state.operationSong == null) {
						return;
					}
					// if(currentPath.equals(al.getFile().getPath())) {
					// return;
					// }

					Log.d(TAG, "Adding '%s' to playlist '%s'", state.operationSong.getPath(), al.getFile().getPath());

					switch(favSelection) {
					case 0:
						songDatabase.addToPlaylist(al, state.operationSong);
						break;
					case 1:
						state.operationSong.setSubTune(state.subTune);
						state.operationSong.setTitle(state.operationTitle);
						songDatabase.addToPlaylist(al, state.operationSong);
						break;
					case 2:
						for(int i = 0; i < state.operationTuneCount; i++) {
							state.operationSong.setSubTune(i);
							songDatabase.addToPlaylist(al, state.operationSong);
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
		state.operationSong = new SongFile(currentPlaylistView.getPath(info.position));
		Log.d(TAG, "%d %s %d %d", item.getItemId(), item.getTitle(), info.position, info.id);
		// int pi = cursor.getColumnIndex("PATH");
		// String path = playListView.getDirectory();
		// if(pi >= 0) {
		// path = cursor.getString(pi);
		// }
		Playlist pl = songDatabase.getCurrentPlaylist();
		Playlist al = songDatabase.getActivePlaylist();
		
		SongFile song = pl != null ? pl.getSong(info.position) : null;
		
		if(song != null) state.operationSong = song;
		
		if(song != null) {
			Log.d(TAG, "Operating on %s by %s", song.getTitle(), song.getComposer());
		}


		switch(item.getItemId()) {
		case R.id.go_dir:
			setDirectory(state.operationSong.getParent(), playListView);
			currentPlaylistView.setScrollPosition(file.getPath());
			// flipper.setDisplayedChild(0);
			updateFileView();
			flipper.flipTo(FILE_VIEW);
			break;
		case R.id.set_plist:
			songDatabase.setActivePlaylist(file);
			break;
		case R.id.add_to_plist:
			if(al != null) {
				if(!currentPath.equals(al.getFile().getPath())) {
					// al.add(file);
					songDatabase.addToPlaylist(al, state.operationSong);
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
				state.clipBoardFile = song;
				setDirectory(null);
			}
			break;
		case R.id.paste:
			if(pl != null && state.clipBoardFile != null) {
				//pl.remove(file);
				pl.insert(info.position, state.clipBoardFile);
				state.clipBoardFile = null;
				setDirectory(null);
			}
			break;
			

		case R.id.scan_dir:
			songDatabase.scanDir(file.getPath());
			break;
		case R.id.del_dir:
			//operationFile = file;
			state.operationSong = new SongFile(file);
			runConfirmable(R.string.do_del_dir, new Runnable() {
				@Override
				public void run() {
					if(songDatabase.deleteDir(state.operationSong.getFile())) {
						delDir(state.operationSong.getFile());
						setDirectory(null);
					}
				}
			});
			break;

		case R.id.del_file:
			//operationFile = file;
			state.operationSong = new SongFile(file);
			runConfirmable(R.string.do_del_file, new Runnable() {
				@Override
				public void run() {
					if(songDatabase.deleteFile(state.operationSong)) {
						state.operationSong.delete();
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
			state.operationSong = new SongFile(file);
			if(state.operationSong.getName().equals("Favorites.plist")) {
				break;
			}
			runConfirmable(R.string.do_del_plist, new Runnable() {
				@Override
				public void run() {
					if(songDatabase.deleteFile(state.operationSong)) {
						state.operationSong.delete();
						setDirectory(null);
						Playlist apl = songDatabase.getActivePlaylist();
						if(apl.getFile().equals(state.operationSong.getFile())) {
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
				state.operationSong = new SongFile(pl.getFile());
				Log.d(TAG, "Clearing playlist %s", pl.getFile().getPath());
				runConfirmable(R.string.do_remove_all, new Runnable() {
					@Override
					public void run() {
						Playlist.getPlaylist(state.operationSong.getFile()).clear();
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
