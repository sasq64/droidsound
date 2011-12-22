package com.ssb.droidsound;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.nio.channels.FileChannel;
import java.util.HashMap;
import java.util.Map;

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
import android.media.AudioManager;
import android.media.RingtoneManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.preference.PreferenceManager;
import android.provider.MediaStore;
import android.text.Html;
import android.text.InputType;
import android.text.method.ScrollingMovementMethod;
import android.view.ContextMenu;
import android.view.ContextMenu.ContextMenuInfo;
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

import com.ssb.droidsound.database.SongDatabase;
import com.ssb.droidsound.playlistview.FileInfo;
import com.ssb.droidsound.playlistview.PlayListView;
import com.ssb.droidsound.plugins.DroidSoundPlugin;
import com.ssb.droidsound.service.PlayerService;
import com.ssb.droidsound.utils.Log;

public class PlayerActivity extends Activity implements PlayerService.IPlayerServiceCallback {
	private static final String TAG = "PlayerActivity";
	public static final int VERSION = 17;

	private static class Config {
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

	protected static SongDatabase songDatabase = null;
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

	private SeekBar songSeeker;

	private OnItemClickListener listClickListener;

	private int sortOrder;

	private PlayListView playListView;
	private PlayListView searchListView;

	private PlayListView currentPlaylistView;

	private ProgressDialog progressDialog;

	private SearchCursor searchCursor;
	private SharedPreferences prefs;

	private int songPos;
	private int subTune;
	private int subTuneCount;
	private int songLength;
	private SongFile songFile;

	private File modsDir;
	private String currentPath;

	private BroadcastReceiver receiver;

	private String songTitle;
	private String songComposer;

	private String searchQuery;
	private String dirTitle;
	private String dirSubTitle;
	private String[] songDetails;

	private Config lastConfig;

	private final Map<Integer, Runnable> confirmables = new HashMap<Integer, Runnable>();

	private int songState;

	private SongFile operationSong;

	private TextView shuffleText;

	protected boolean shuffleSongs;

	private LinearLayout titleBar;

	private TextView repeatText;

	private int songRepeat;

	private TextView plusText;

	private String subtuneTitle;
	private String subtuneAuthor;

	private String operationTitle;

	private int operationTuneCount;

	private TextView plinfoText;

	protected boolean dialogShowing;

	private SongFile clipBoardFile;

	private int dumpingWav = 0;

	private TextView toneLenText;

	protected String toneName = "Droidsound Ringtone";
	protected boolean toneSet = true;

	protected int toneLength = 2;

	private TextView toneNameText;

	private void setDirectory(String path, PlayListView plv) {
		if (plv == null) {
			plv = currentPlaylistView;
		}

		if(path == null) {
			String p = plv.getPath();
			if(p != null) {
				path = p;
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
		plv.setCursor(cursor, path);

		File f = new File(path);

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

	private void setDirectory(PlayListView plv) {
		setDirectory((String)null, plv);
	}

	@Override
	public void onBackPressed() {
		if (flipper.getDisplayedChild() != FILE_VIEW) {
			return;
		}

		File f = new File(playListView.getPath());
		if (! f.equals(modsDir)) {
			setDirectory(f.getParent(), playListView);
			currentPlaylistView.setScrollPosition(f.getPath());
		} else {
			super.onBackPressed();
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
		super.onCreate(savedInstanceState);
		PreferenceManager.setDefaultValues(this, R.layout.preferences, false);

		Intent intent = getIntent();
		Log.i(TAG, "PlayerActivity launched to handle: %s (data=%s)", intent.getAction(), intent.getDataString());
		if (Intent.ACTION_VIEW.equals(intent.getAction())) {
			Intent newIntent = new Intent(intent);
			newIntent.setClass(this, PlayerService.class);
			startService(newIntent);
			finish();
			return;
		} else if (Intent.ACTION_SEND.equals(intent.getAction())) {
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
		player.bindService(this, this);

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

		plinfoText = (TextView) findViewById(R.id.plinfo_text);

		prefs = PreferenceManager.getDefaultSharedPreferences(this);

		seekingSong = 0;

		currentPlaylistView = playListView;

		modsDir = null;

		setupModsDir();

		String cp = prefs.getString("currentPath", null);
		if(cp == null) {
			currentPath = modsDir.getPath();
		} else {
			currentPath = cp;
		}

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

					if(lastConfig != null) {
						Log.d(TAG, "CONFIG CHANGE");
					} else {
						Log.d(TAG, "SCANNING");
						songDatabase.scan(false, modsDir.getPath());
					}

					setDirectory(playListView);
				} else if(intent.getAction().equals("com.sddb.droidsound.SCAN_DONE")) {
					if(progressDialog != null) {
						progressDialog.cancel();
						progressDialog = null;
					}

					setDirectory(playListView);
				} else if(intent.getAction().equals("com.sddb.droidsound.SCAN_UPDATE")) {
					checkProgressDialog();
					if(progressDialog != null) {
						int percent = intent.getIntExtra("PERCENT", 0);
						String path = intent.getStringExtra("PATH");
						if(percent >= 0) {
							progressDialog.setMessage(String.format("Updating database...\n%s (%d %%)", path, percent));
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
		registerReceiver(receiver, filter);

		if (songDatabase == null) {
			songDatabase = new SongDatabase(getApplicationContext());
			dbThread = new Thread(songDatabase);
			dbThread.start();

			while (!songDatabase.isReadyToServe()) {
				try {
					Thread.sleep(100);
				} catch (InterruptedException e1) {
					e1.printStackTrace();
				}
			}
		}

		setDirectory(currentPath, null);

		checkProgressDialog();

		lastConfig = (Config) getLastNonConfigurationInstance();
		if (lastConfig != null) {
			searchCursor = lastConfig.searchCursor;
			searchListView.setCursor(searchCursor, null);
			songDatabase.setActivePlaylist(new File(lastConfig.activePlaylist));
			searchQuery = lastConfig.query;
			shuffleSongs = lastConfig.shuffleSongs;
			flipTo(lastConfig.flipper, false);
		} else {
			File mf = new File(modsDir, "Favorites.plist");
			songDatabase.setActivePlaylist(mf);

			DroidSoundPlugin.setOptions(prefs);

			shuffleSongs = prefs.getBoolean("shuffle", false);
			songDatabase.scan(false, modsDir.getPath());
		}
		shuffleText.setText(shuffleSongs ? "RND" : "SEQ");

		listClickListener = new OnItemClickListener() {
			@Override
			public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
				PlayListView plv = (PlayListView) parent;
				FileInfo fi = (FileInfo) plv.getItemAtPosition(position);

				Log.d(TAG, "Clicked %s got file %s", plv, fi);

				if(fi != null) {

					if(fi.getType() == SongDatabase.TYPE_DIR || fi.getType() == SongDatabase.TYPE_ARCHIVE || fi.getType() == SongDatabase.TYPE_PLIST) {
						setDirectory(fi.getPath(), plv);
						plv.setScrollPosition(null);

					} else {
						int index = 0;
						FileInfo[] files = plv.getFiles(true);

						if(currentPlaylistView == playListView) {
							Playlist plist = songDatabase.getCurrentPlaylist();
							if(plist != null) {
								index = position;
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
					}
				}
			}
		};

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
	}

	private void setupModsDir() {
		modsDir = new File(prefs.getString("modsDir", new File(Environment.getExternalStorageDirectory(), "MODS").getPath()));
		if (! modsDir.exists()) {
			if (! modsDir.mkdirs()) {
				showDialog(R.string.create_moddir_failed);
				dialogShowing = true;
				return;
			}

			Editor editor = prefs.edit();
			editor.putString("modsDir", modsDir.getPath());
			editor.commit();

			File tempFile = new File(modsDir, "Examples.zip");
			if (! tempFile.exists()) {
				try {
					InputStream is = getAssets().open("Examples.zip");
					FileOutputStream os = new FileOutputStream(tempFile);
					byte[] buffer = new byte[1024];

					int length;
					while (0 != (length = is.read(buffer))) {
						os.write(buffer, 0, length);
					}
					os.close();
					is.close();

					File ns = new File(modsDir, ".nomedia");
					if (!ns.exists()) {
						FileWriter fw;
						try {
							fw = new FileWriter(ns);
							fw.close();
						} catch (IOException e1) {
						}
					}

					File mf = new File(modsDir, "Favorites.plist");
					if(!mf.exists()) {
						try {
							FileWriter fw = new FileWriter(mf);
							fw.close();
						} catch (IOException e2) {
						}
					}

					showDialog(R.string.unpack_examples);
					dialogShowing = true;
				} catch (IOException e) {
					Toast.makeText(this, e.toString(), Toast.LENGTH_LONG).show();
				}
			}
		}
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
	}

	@Override
	protected void onResume() {
		super.onResume();
		Log.d(TAG, "#### onResume()");

		if(!songDatabase.isScanning() && progressDialog != null) {
			progressDialog.cancel();
			progressDialog = null;
			setDirectory(playListView);
		}
	}

	@Override
	protected void onPause() {
		super.onPause();

		Editor editor = prefs.edit();
		editor.putString("currentPath", currentPath);
		editor.putBoolean("shuffle", shuffleSongs);
		editor.commit();
		Playlist.flushAll();
	}

	@Override
	protected void onDestroy() {
		super.onDestroy();

		if(receiver != null) {
			unregisterReceiver(receiver);
		}

		if(playListView != null) {
			playListView.close();
		}

		if(searchCursor != null) {
			searchCursor.realClose();
		}

		if(progressDialog != null) {
			progressDialog.dismiss();
		}

		player.unbindService(this);
		player = null;
	}

	@Override
	public Object onRetainNonConfigurationInstance() {
		Config c = new Config();
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


	@Override
	public void setInitialConfig() {
		player.setOption(PlayerService.OPTION_SILENCE_DETECT, prefs.getBoolean("silence", false) ? "on" : "off");
		player.setOption(PlayerService.OPTION_DEFAULT_LENGTH, prefs.getString("default_length", "0"));
		player.setOption(PlayerService.OPTION_PLAYBACK_ORDER, shuffleSongs ? "R" : "S");
		String b = prefs.getString("buffer", "Long");
		player.setOption(PlayerService.OPTION_BUFFERSIZE, b);
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
			if (value < 0) {
				value = 0;
				songTotalText.setVisibility(View.GONE);
			} else {
				songTotalText.setVisibility(View.VISIBLE);
			}
			songLength = value / 1000;
			Log.d(TAG, "Songlength %02d:%02d", songLength / 60, songLength % 60);
			songTotalText.setText(String.format("%02d:%02d", songLength / 60, songLength % 60));
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
			break;
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

		if (confirmables.containsKey(id)) {
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
		case R.string.make_wav: {
			final String [] progressNames = new String [] { "0:10", "0:20", "0:30", "1:00", "5:00", "10:00" };
			LayoutInflater inflater = (LayoutInflater) getSystemService(LAYOUT_INFLATER_SERVICE);
			View dialog = inflater.inflate(R.layout.ringtone_dialog, (ViewGroup) findViewById(R.layout.player));
			builder.setView(dialog);
			builder.setTitle(id);

			toneNameText = (TextView) dialog.findViewById(R.id.tone_name);
			toneNameText.setText(toneName);

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
					File file = new File("/sdcard/droidsound/ringtones");
					file.mkdir();
					int tl = toneLength;
					if(tl == 3) tl = 6;
					else if(tl == 4) tl = 6*5;
					else if(tl == 5) tl = 6*10;
					else tl += 1;
					dumpingWav = tl * 10000;//30000;
					toneName = toneNameText.getText().toString();
					file = new File(file, toneName + ".wav");
					player.dumpWav(operationSong.getPath(), file.getPath(), dumpingWav);
				}
			});
			builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface dialog, int which) {
					dialog.cancel();
				}
			});
			break;
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
					if (!file.exists() && !file.getName().equals("Favorites.plist")) {
						try {
							songDatabase.createPlaylist(file);
						}
						catch (IOException ioe) {
							Toast.makeText(PlayerActivity.this, ""+ioe, Toast.LENGTH_LONG).show();
							return;
						}
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
					dialog.dismiss();
					if(al == null || operationSong == null) {
						return;
					}

					Log.d(TAG, "Adding '%s' to playlist '%s'", operationSong.getPath(), al.getFile().getPath());

					try {
						switch (favSelection) {
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
					}
					catch (IOException ioe) {
						Toast.makeText(PlayerActivity.this, "" + ioe, Toast.LENGTH_LONG).show();
					}
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
				@Override
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
		AdapterContextMenuInfo info = (AdapterContextMenuInfo) item.getMenuInfo();
		File file = currentPlaylistView.getFile(info.position);
		operationSong = new SongFile(currentPlaylistView.getPath(info.position));
		Log.d(TAG, "%d %s %d %d", item.getItemId(), item.getTitle(), info.position, info.id);
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
			flipTo(FILE_VIEW);
			break;
		case R.id.set_plist:
			songDatabase.setActivePlaylist(file);
			break;
		case R.id.add_to_plist:
			if(al != null) {
				if (!currentPath.equals(al.getFile().getPath())) {
					try {
						songDatabase.addToPlaylist(al, operationSong);
					}
					catch (IOException ioe) {
						Toast.makeText(this, "" + ioe, Toast.LENGTH_LONG).show();
					}
				}
			}
			break;
		case R.id.cut:
			if(pl != null) {
				//pl.remove(file);
				pl.remove(info.position);
				clipBoardFile = song;
				setDirectory(null);
			}
			break;
		case R.id.paste:
			if (pl != null && clipBoardFile != null) {
				try {
					pl.insert(info.position, clipBoardFile);
				} catch (IOException ioe) {
					Toast.makeText(this, ""+ioe, Toast.LENGTH_LONG).show();
				}
				clipBoardFile = null;
				setDirectory(null);
			}
			break;


		case R.id.del_dir:
			operationSong = new SongFile(file);
			runConfirmable(R.string.do_del_dir, new Runnable() {
				@Override
				public void run() {
					if (songDatabase.deleteDir(operationSong.getFile())) {
						delDir(operationSong.getFile());
						setDirectory(null);
					}
				}
			});
			break;

		case R.id.del_file:
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
