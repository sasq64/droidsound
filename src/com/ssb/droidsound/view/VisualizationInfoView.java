package com.ssb.droidsound.view;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.SurfaceView;

public class VisualizationInfoView extends SurfaceView {
	public static class Color {
		private final float r, g, b;

		protected Color(float r, float g, float b) {
			this.r = r;
			this.g = g;
			this.b = b;
		}

		protected float gamma(float arg) {
			return (float) Math.pow(arg, 1/2.2);
		}

		protected int toRGB(float luminosity) {
			return 0xff000000
					| (Math.round(gamma(luminosity * r) * 255) << 16)
					| (Math.round(gamma(luminosity * g) * 255) << 8)
					| (Math.round(gamma(luminosity * b) * 255) << 0);
		}
	}

	public static final int BINS = 12 * 7;

	protected static final String TAG = VisualizationInfoView.class.getSimpleName();

	private final Color[] colors = new Color[BINS];

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

	private final Paint white;

	public VisualizationInfoView(Context context, AttributeSet attrs) {
		super(context, attrs);
		setWillNotDraw(false);
		calculateColors();
		white = new Paint();
		white.setColor(0xffffffff);
		white.setTextAlign(Paint.Align.CENTER);
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
				r = .4f + r * .6f;
				g = .4f + g * .6f;
				b = .4f + b * .6f;
			} else {
				r *= 0.6f;
				g *= 0.6f;
				b *= 0.6f;
			}
			colors[i] = new Color(r, g, b);
		}
	}

	@Override
	protected void onDraw(Canvas canvas) {
		Paint fftPaint = new Paint();
		int width = getWidth();
		int height = getHeight();
		for (int i = 0; i < 12; i ++) {
			float x1 = width / 2 + (i - 6) * height;
			float x2 = x1 + height - 1;
			float y1 = 0;
			float y2 = height - 1;
			fftPaint.setColor(colors[i].toRGB(0.5f));
			canvas.drawRect(x1, y1, x2, y2, fftPaint);
			canvas.drawText(NOTE_NAME[i], (x1 + x2) / 2f, (y1 + y2 - white.getFontMetrics().ascent) / 2f, white);
		}
	}

	public Color[] getColors() {
		return colors;
	}
}