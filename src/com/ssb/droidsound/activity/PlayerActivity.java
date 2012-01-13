package com.ssb.droidsound.activity;

import android.app.ActionBar;
import android.app.ActionBar.Tab;
import android.app.ActionBar.TabListener;
import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.support.v13.app.FragmentPagerAdapter;
import android.support.v4.view.ViewPager;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;

import com.ssb.droidsound.R;
import com.ssb.droidsound.service.MusicIndexService;
import com.ssb.droidsound.service.PlayerService;

public class PlayerActivity extends Activity {
	private MusicIndexService.LocalBinder musicIndex;

	private final ServiceConnection musicIndexConnection = new ServiceConnection() {
		@Override
		public void onServiceConnected(ComponentName tag, IBinder binder) {
			musicIndex = (MusicIndexService.LocalBinder) binder;
			musicIndex.scan(false);
			onCreateEnd();
		}

		@Override
		public void onServiceDisconnected(ComponentName tag) {
			musicIndex = null;
		}
	};

	private PlayerService.LocalBinder player;

	private final ServiceConnection playerConnection = new ServiceConnection() {
		@Override
		public void onServiceConnected(ComponentName tag, IBinder binder) {
			player = (PlayerService.LocalBinder) binder;
			onCreateEnd();
		}

		@Override
		public void onServiceDisconnected(ComponentName arg0) {
			player = null;
		}
	};

	public MusicIndexService.LocalBinder getMusicIndexService() {
		return musicIndex;
	}

	public PlayerService.LocalBinder getPlayerService() {
		return player;
	}

	private ActionBar actionBar;

	private ViewPager viewPager;

	private MyAdapter viewPagerAdapter;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.top);

		bindService(new Intent(this, MusicIndexService.class), musicIndexConnection, Context.BIND_AUTO_CREATE);
		bindService(new Intent(PlayerActivity.this, PlayerService.class), playerConnection, Context.BIND_AUTO_CREATE);
	}

	private void onCreateEnd() {
		if (musicIndex == null || player == null) {
			return;
		}

		if (actionBar != null) {
			return;
		}

		actionBar = getActionBar();
		actionBar.setNavigationMode(ActionBar.NAVIGATION_MODE_TABS);
		actionBar.setDisplayOptions(0);

		viewPager = (ViewPager) findViewById(R.id.viewPager);
		viewPagerAdapter = new MyAdapter(getFragmentManager());
		/* This is done because fragmentmanager crashes if the fragmenttransaction references
		 * a fragment which viewpager has deallocated. This stuff is pretty much shit. */
		viewPager.setOffscreenPageLimit(viewPagerAdapter.getCount());
		viewPager.setKeepScreenOn(true);

		for (String entry : viewPagerAdapter.getEntries()) {
			ActionBar.Tab tab = actionBar.newTab();
			tab.setTabListener(new TabListener() {
				@Override
				public void onTabReselected(Tab tab, FragmentTransaction ft) {
				}

				@Override
				public void onTabSelected(Tab tab, FragmentTransaction ft) {
					viewPager.setCurrentItem(tab.getPosition());
				}

				@Override
				public void onTabUnselected(Tab tab, FragmentTransaction ft) {
				}
			});

			try {
				int stringId = R.string.class.getField(entry + "_title").getInt(null);
				tab.setText(getString(stringId));
			} catch (Exception e) {
				throw new RuntimeException(e);
			}
			actionBar.addTab(tab);
		}

		viewPager.setAdapter(viewPagerAdapter);
		viewPager.setOnPageChangeListener(new ViewPager.OnPageChangeListener() {
			@Override
			public void onPageSelected(int idx) {
				actionBar.selectTab(actionBar.getTabAt(idx));
			}

			@Override
			public void onPageScrolled(int arg0, float arg1, int arg2) {
			}

			@Override
			public void onPageScrollStateChanged(int arg0) {
			}
		});
	}

	@Override
	public void onDestroy() {
		super.onDestroy();
		unbindService(musicIndexConnection);
		unbindService(playerConnection);
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
			return true;
		default:
			return false;
		}
	}
}

class MyAdapter extends FragmentPagerAdapter {
	private final String[] entries = { "collection", "playing", "visualization" };

	public MyAdapter(FragmentManager fm) {
		super(fm);
	}

	public String[] getEntries() {
		return entries;
	}

	@Override
	public int getCount() {
		return entries.length;
	}

	@Override
	public Fragment getItem(int position) {
		final Fragment f;
		if (position == 0) {
			f = new CollectionFragment();
		} else if (position == 1) {
			f = new PlayingFragment();
		} else if (position == 2) {
			f = new VisualizationFragment();
		} else {
			throw new RuntimeException("No such fragment: " + position);
		}
		f.setRetainInstance(true);
		return f;
	}
}