package com.ssb.droidsound.activity;

import android.app.ActionBar;
import android.app.ActionBar.Tab;
import android.app.ActionBar.TabListener;
import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.Intent;
import android.os.Bundle;
import android.support.v13.app.FragmentPagerAdapter;
import android.support.v4.view.ViewPager;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;

import com.ssb.droidsound.R;

public class PlayerActivity extends Activity {
	private ActionBar actionBar;

	private ViewPager viewPager;

	private MyAdapter viewPagerAdapter;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.top);

		actionBar = getActionBar();
		actionBar.setNavigationMode(ActionBar.NAVIGATION_MODE_TABS);
		actionBar.setDisplayOptions(0);

		viewPager = (ViewPager) findViewById(R.id.viewPager);
		viewPagerAdapter = new MyAdapter(getFragmentManager());
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