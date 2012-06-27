package com.ssb.droidsound;

import android.support.v4.view.ViewPager;
import android.view.View;
import android.view.animation.Animation;
import android.widget.ViewFlipper;

public class Flipper {
	
	public static interface FlipCallback {
		void flipped(int to, int from, View v);
	}

	public static final int FILE_VIEW = 0;
	public static final int INFO_VIEW = 1;
	public static final int SEARCH_VIEW = 2;
	public static final int NEXT_VIEW = 3;
	public static final int PREV_VIEW = 4;
	public static final int SAME_VIEW = 5;
	
	private ViewFlipper flipper;
	private FlipCallback callBack;
	private ViewPager pager;
	
	public Flipper(View vf) {
		flipper = (ViewFlipper) vf;
	}
	
	public void addView(View v) {
		flipper.addView(v);
	}
	
	public void onFlip(FlipCallback cb) {
		callBack = cb;
	}
	

	public void flipTo(int what, boolean animate) {
		Animation ia = null;
		Animation oa = null;
		if(!animate) {
			ia = flipper.getInAnimation();
			oa = flipper.getOutAnimation();
			flipper.setInAnimation(null);
			flipper.setOutAnimation(null);
		}
		
		int old = flipper.getDisplayedChild();

		if(what < 3) {
			if(old != what) {
				flipper.setDisplayedChild(what);
			}
		} else if(what == NEXT_VIEW) {
			flipper.showNext();
			what = (old+1)%3;
		} else if(what == PREV_VIEW) {
			flipper.showPrevious();
			what = (old-1)%3;
		}

		if(ia != null) {
			flipper.setInAnimation(ia);
			flipper.setOutAnimation(oa);
		}
		
		if(callBack != null)
			callBack.flipped(what, old, flipper.getCurrentView());


	}
	
	public void flipTo(int what) {
		flipTo(what, true);
	}

	public int getDisplayedChild() {
		return flipper.getDisplayedChild();
	}
}
