package com.ssb.droidsound;

import android.content.Context;
import android.graphics.Typeface;
import android.util.AttributeSet;
import android.widget.TextView;

public class AsciiTextView extends TextView {

	public AsciiTextView(Context context, AttributeSet attrs) {
		super(context, attrs);
		Typeface tr = Typeface.createFromAsset(context.getAssets(), "fonts/topaz_plus1200.ttf");
		setTypeface(tr);
		boolean hasTC = false;
		//boolean hasTS = false;
		float size = -1F;
		
		//float size0 = attrs.getAttributeFloatValue("android", "textSize", 10.7F);
		//int size1 = attrs.getAttributeIntValue("android", "textSize", 10);
		
		for(int i=0; i<attrs.getAttributeCount(); i++) {
			if(attrs.getAttributeName(i).equals("textColor")) {
				hasTC = true;
			}
			String x = attrs.getAttributeValue(i);
			if(attrs.getAttributeName(i).equals("textSize")) {
				//size = Float.parseFloat(x);
				if(x.startsWith("20")) {
					size = 20;
				}
			}
		}
		if(!hasTC) {
			setTextColor(0xff000000);
		}
		
		if(size < 15) {
			size = 10.7F;
		} else if(size < 25) {
			size = 21.4F;
		} else {
			size = 31.0F;
		}
		
		setTextSize(size);

	}

}
