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
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.support.v13.app.FragmentPagerAdapter;
import android.support.v4.view.ViewPager;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;

import com.ssb.droidsound.R;
import com.ssb.droidsound.service.SongDatabaseService;

public class PlayerActivity extends Activity {
	private static final String TAG = PlayerActivity.class.getSimpleName();

	private ActionBar actionBar;
	private ViewPager viewPager;
	private MyAdapter viewPagerAdapter;

	private final BroadcastReceiver searchReceiver = new BroadcastReceiver() {
		private ProgressDialog pd;

		@Override
		public void onReceive(Context c, Intent i) {
			String a = i.getAction();
			if (a.equals(SongDatabaseService.SCAN_NOTIFY_BEGIN)) {
				pd = new ProgressDialog(c);
				pd.setCancelable(false);
				pd.show();
				return;
			}
			if (a.equals(SongDatabaseService.SCAN_NOTIFY_UPDATE)) {
				String path = i.getStringExtra("path");
				int progress = i.getIntExtra("progress", 0);
				pd.setMessage(String.format("%s (%d %%)", path, progress));
			}
			if (a.equals(SongDatabaseService.SCAN_NOTIFY_DONE)) {
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
		searchReceiverFilter.addAction(SongDatabaseService.SCAN_NOTIFY_BEGIN);
		searchReceiverFilter.addAction(SongDatabaseService.SCAN_NOTIFY_UPDATE);
		searchReceiverFilter.addAction(SongDatabaseService.SCAN_NOTIFY_DONE);
		registerReceiver(searchReceiver, searchReceiverFilter);

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
				int stringId = R.string.class.getField(entry + "_title")
						.getInt(null);
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
		} else  if (position == 1) {
			f = new PlayingFragment();
		} else {
			throw new RuntimeException("No such fragment: " + position);
		}

		f.setRetainInstance(true);
		return f;
	}
}