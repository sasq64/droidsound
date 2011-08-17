package com.ssb.droidsound.utils;

import android.content.Context;
import android.os.Build;
import android.util.AttributeSet;
import android.widget.ViewFlipper;

public final class FixedViewFlipper extends ViewFlipper {

	public FixedViewFlipper(Context context) {
		super(context);
	}

	public FixedViewFlipper(Context context, AttributeSet attrs) {
		super(context, attrs);
	}

	@Override
	protected void onDetachedFromWindow() {
		int apiLevel = Integer.parseInt(Build.VERSION.SDK);
		if(apiLevel >= 7) {
			try {
				super.onDetachedFromWindow();
			} catch (IllegalArgumentException e) {
				Log.w("ViewFlipper", "Android project  issue 6191  workaround.");
			} finally {
				//super.stopFlipping();
                stopFlipping(); //Super is not needed here
			}
		} else {
			super.onDetachedFromWindow();
		}
	}

}
