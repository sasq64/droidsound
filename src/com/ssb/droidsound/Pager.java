package com.ssb.droidsound;

import java.util.ArrayList;
import java.util.List;

import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.view.View;
import android.view.ViewGroup;

public class Pager extends PagerAdapter {
	
	public static interface FlipCallback {
		void flipped(int to, int from, View v);
	}

	public static final int FILE_VIEW = 0;
	public static final int INFO_VIEW = 1;
	public static final int SEARCH_VIEW = 2;
	public static final int NEXT_VIEW = 3;
	public static final int PREV_VIEW = 4;
	public static final int SAME_VIEW = 5;
	
	private FlipCallback callBack;
	private ViewPager pager;
	
	private List<View> viewList = new ArrayList<View>();
	
	public Pager(View vf) {
		pager = (ViewPager) vf;
				
		pager.setAdapter(this);
		
		pager.setOnPageChangeListener(new ViewPager.OnPageChangeListener() {
			@Override
			public void onPageSelected(int what) {

				if(callBack != null)
					callBack.flipped(what, -1, viewList.get(what));
			}
			
			@Override
			public void onPageScrolled(int arg0, float arg1, int arg2) {
			}
			
			@Override
			public void onPageScrollStateChanged(int arg0) {
			}
		});
	}
	
	public void addView(View v) {
		viewList.add(v);
	}
	
	public void onFlip(FlipCallback cb) {
		callBack = cb;
	}
	

	public void flipTo(int what, boolean animate) {
		int old = getDisplayedChild();

		if(what < 3) {
			if(old != what) {
				pager.setCurrentItem(what, animate);
			}
		} else if(what == NEXT_VIEW) {
			what = (old+1)%3;
			pager.setCurrentItem(what, animate);
		} else if(what == PREV_VIEW) {
			what = (old-1)%3;
			pager.setCurrentItem(what, animate);
		} else if(what == SAME_VIEW) {
			what = old;
		}

		if(callBack != null)
			callBack.flipped(what, old, viewList.get(what));
	}
	
	public void flipTo(int what) {
		flipTo(what, true);
	}
	

	public int getDisplayedChild() {
		return pager.getCurrentItem();
	}

	@Override
	public int getCount() {
		return viewList.size();
	}

	@Override
	public boolean isViewFromObject(View arg0, Object arg1) {
		return arg0 == arg1;
	}
	
	@Override
	public Object instantiateItem(ViewGroup container, int position) {
		container.addView(viewList.get(position));
		
		return viewList.get(position);
		// TODO Auto-generated method stub
		//return super.instantiateItem(container, position);
	}
	
	@Override
	public void destroyItem(ViewGroup container, int position, Object object) {
		container.removeView((View)object);
	}
	
	private static final String [] titles = new String [] { "BROWSER", "PLAYER", "SEARCH" };
	
	@Override
	public CharSequence getPageTitle(int position) {
		return titles[position];
	}
}
