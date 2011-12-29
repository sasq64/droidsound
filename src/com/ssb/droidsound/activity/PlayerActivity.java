package com.ssb.droidsound.activity;

import android.app.ActionBar;
import android.app.ActionBar.Tab;
import android.app.ActionBar.TabListener;
import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.app.ProgressDialog;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
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
import com.ssb.droidsound.utils.Log;

public class PlayerActivity extends Activity {
	private static final String TAG = PlayerActivity.class.getSimpleName();

	private ActionBar actionBar;
	private ViewPager viewPager;
	private MyAdapter viewPagerAdapter;

	private MusicIndexService.LocalBinder db;

	private final ServiceConnection dbConnection = new ServiceConnection() {
		@Override
		public void onServiceConnected(ComponentName tag, IBinder binder) {
			db = (MusicIndexService.LocalBinder) binder;
			Log.i(TAG, "Refreshing database.");
			db.scan(false);
		}

		@Override
		public void onServiceDisconnected(ComponentName tag) {
			db = null;
		}
	};

	private final BroadcastReceiver searchReceiver = new BroadcastReceiver() {
		private ProgressDialog pd;

		@Override
		public void onReceive(Context c, Intent i) {
			String a = i.getAction();
			if (a.equals(MusicIndexService.SCAN_NOTIFY_BEGIN)) {
				pd = new ProgressDialog(c);
				pd.setCancelable(false);
				pd.show();
				return;
			}
			if (a.equals(MusicIndexService.SCAN_NOTIFY_UPDATE)) {
				String path = i.getStringExtra("path");
				int progress = i.getIntExtra("progress", 0);
				pd.setMessage(String.format("%s (%d %%)", path, progress));
			}
			if (a.equals(MusicIndexService.SCAN_NOTIFY_DONE)) {
				pd.dismiss();
				pd = null;
				return;
			}
		}
	};

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.top);

		IntentFilter searchReceiverFilter = new IntentFilter();
		searchReceiverFilter.addAction(MusicIndexService.SCAN_NOTIFY_BEGIN);
		searchReceiverFilter.addAction(MusicIndexService.SCAN_NOTIFY_UPDATE);
		searchReceiverFilter.addAction(MusicIndexService.SCAN_NOTIFY_DONE);
		registerReceiver(searchReceiver, searchReceiverFilter);

		bindService(new Intent(this, MusicIndexService.class), dbConnection, Context.BIND_AUTO_CREATE);

		actionBar = getActionBar();
		actionBar.setNavigationMode(ActionBar.NAVIGATION_MODE_TABS);
		actionBar.setDisplayShowTitleEnabled(true);

		viewPager = (ViewPager) findViewById(R.id.viewPager);
		viewPagerAdapter = new MyAdapter(getFragmentManager());

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
	protected void onDestroy() {
		super.onDestroy();
		unregisterReceiver(searchReceiver);
		unbindService(dbConnection);
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
		}
		return true;
	}
}

class MyAdapter extends FragmentPagerAdapter {
	private final String[] entries = { "collection", "playing" };

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
		} else {
			throw new RuntimeException("No such fragment: " + position);
		}
		f.setRetainInstance(true);
		return f;
	}
}