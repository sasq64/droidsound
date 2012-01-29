package com.ssb.droidsound.view;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.SurfaceView;

import com.ssb.droidsound.utils.Color;

public class VisualizationInfoView extends SurfaceView {
	protected static final String TAG = VisualizationInfoView.class.getSimpleName();

	private final Color[] colors = new Color[12];

	private final String NOTE_NAME[] = new String[] {
			"A",
			"A#",
			"H",
			"C",
			"C#",
			"D",
			"D#",
			"E",
			"F",
			"F#",
			"G",
			"G#"
	};

	private final Paint noteLabel;

	public VisualizationInfoView(Context context, AttributeSet attrs) {
		super(context, attrs);
		setWillNotDraw(false);
		calculateColors();
		noteLabel = new Paint();
		noteLabel.setColor(0xffffffff);
		noteLabel.setTextAlign(Paint.Align.CENTER);
		noteLabel.setShadowLayer(1, 0, 1, 0xb4000000);
	}

	@Override
	protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
		int width = MeasureSpec.getSize(widthMeasureSpec);
		setMeasuredDimension(width, width / 12);
		noteLabel.setTextSize(width / 12f / 3f);
	}

	private void calculateColors() {
		for (int i = 0; i < colors.length; i ++) {
			String noteName = NOTE_NAME[i % 12];
			double note = i / 12.0;

			/* Generate colors around the color wheel */
			float r2 = (float) (.5 + .5 * Math.sin(2 * Math.PI * note));
			float g2 = (float) (.5 + .5 * Math.sin(2 * Math.PI * (note + 1/3.0)));
			float b2 = (float) (.5 + .5 * Math.sin(2 * Math.PI * (note + 2/3.0)));

			/* Increase saturation */
			float r = r2 - (g2 + b2) * .2f;
			float g = g2 - (r2 + b2) * .2f;
			float b = b2 - (r2 + g2) * .2f;

			/* Approximate white keys by reducing saturation. */
			if (! noteName.contains("#")) {
				r = .25f + r * .75f;
				g = .25f + g * .75f;
				b = .25f + b * .75f;
			} else {
				r *= 0.75f;
				g *= 0.75f;
				b *= 0.75f;
			}
			colors[i] = new Color(r, g, b);
		}
	}

	@Override
	protected void onDraw(Canvas canvas) {
		Paint fftPaint = new Paint();
		int width = getWidth();
		int height = getHeight();
		float fh = noteLabel.getFontMetrics().ascent + noteLabel.getFontMetrics().descent;
		for (int i = 0; i < 12; i ++) {
			int n = (i + 3) % 12;
			float x1 = (width + 1f) * i / 12f;
			float x2 = (width + 1f) * (i + 1) / 12f - 1;
			float y1 = 0;
			float y2 = height-1;
			fftPaint.setColor(colors[n].toRGB(0.5f, 1f));
			canvas.drawRect(x1, y1, x2, y2, fftPaint);
			canvas.drawText(NOTE_NAME[n], (x1 + x2) / 2f, (y1 + y2 - fh) / 2f, noteLabel);
		}
	}

	public Color[] getColors() {
		return colors;
	}
}