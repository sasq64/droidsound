package com.ssb.droidsound.view;

import java.util.Arrays;
import java.util.Queue;
import java.util.concurrent.TimeUnit;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.SurfaceView;

import com.ssb.droidsound.service.PlayerService;
import com.ssb.droidsound.service.PlayerService.FFTData;

public class VisualizationView extends SurfaceView {
	private static class Color {
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

	protected static final String TAG = VisualizationView.class.getSimpleName();

	private final double minFreq = 110; /* A */
	private final float[] fft = new float[BINS];
	private final float[] lifetime = new float[BINS];
	private final Color[] coloring = new Color[BINS];

	private Queue<FFTData> queue;

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

	public VisualizationView(Context context, AttributeSet attrs) {
		super(context, attrs);
		setWillNotDraw(false);
		calculateColors();
		white = new Paint();
		white.setColor(0xffffffff);
		white.setTextAlign(Paint.Align.CENTER);
	}

	/**
	 * Set the data array. Visualizer will update as long as this exists.
	 *
	 * @param data
	 */
	public void setData(Queue<PlayerService.FFTData> data) {
		this.queue = data;
		Arrays.fill(fft, 0);
		Arrays.fill(lifetime, 0);
		invalidate();
	}

	private void calculateColors() {
		for (int i = 0; i < coloring.length; i ++) {
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
			coloring[i] = new Color(r, g, b);
		}
	}

	@Override
	protected void onDraw(Canvas canvas) {
		if (queue == null) {
			return;
		}

		long futureDelay = updateFftData();
		postInvalidateDelayed(futureDelay);

		int width = getWidth();
		int height = getHeight();

		Paint fftPaint = new Paint();
		for (int i = 0; i < fft.length; i ++) {
			float dBNorm = fft[i];
			float luminosity = lifetime[i];
			fftPaint.setColor(coloring[i].toRGB(luminosity));

			float x = (i + 0.5f) / (fft.length) * width;
			canvas.drawLine(x, height, x, height * (1f - dBNorm), fftPaint);
		}

		float ref = Math.min(width, height) / 12f;
		for (int i = 0; i < 12; i ++) {
			float x1 = width / 2 + (i - 6) * ref;
			float x2 = x1 + ref - 1;
			float y1 = 0;
			float y2 = ref;
			fftPaint.setColor(coloring[i].toRGB(0.5f));
			canvas.drawRect(x1, y1, x2, y2, fftPaint);
			canvas.drawText(NOTE_NAME[i], (x1 + x2) / 2f, (y1 + y2 - white.getFontMetrics().ascent) / 2f, white);
		}
	}

	private long updateFftData() {
		synchronized (queue) {
			PlayerService.FFTData data = queue.poll();
			if (data != null) {
				updateFftData(data.getFft());
			}

			data = queue.peek();
			if (data == null) {
				return 100;
			}
			return data.getDelay(TimeUnit.MILLISECONDS);
		}
	}

	private double projectFft(double idx) {
		return minFreq * Math.pow(2, idx / 12.0);
	}

	private static double getBin(int idx, short[] data) {
		float re = data[idx * 2] / (float) (1 << 9);
		float im = data[idx * 2 + 1] / (float) (1 << 9);
		return re * re + im * im;
	}

	private void updateFftData(short[] buf) {
		/* Remap data bins into our freq-linear fft */
		for (int i = 0; i < fft.length; i ++) {
			double startFreq = projectFft(i - 0.5);
			double endFreq = projectFft(i + 0.5);

			double startIdx = startFreq / 22050 * (buf.length >> 1);
			double endIdx = endFreq / 22050 * (buf.length >> 1);

			double lenSq = 0;
			double n = 0;
			while (endIdx - startIdx > 1e-10) {
				int intStartIdx = (int) startIdx;
				/* Determine width inside the current bin. */
				double width = Math.min(endIdx - startIdx, intStartIdx + 1 - startIdx) + 1e-10;
				lenSq += getBin(intStartIdx, buf) * width;
				startIdx += width;
				n += width;
			}
			lenSq /= n;

			double dB = Math.log(lenSq + 1e-10) / Math.log(10) * 10;

			/* FIXME: is -60 dB good limit? I think that because this class is used
			 * for module playback with 8 bit samples, showing much lower than 50 dB is
			 * not a good idea. */
			float x = ((float) dB / 60f) + 0.8f;

			if (x >= fft[i]) {
				fft[i] = x;
				lifetime[i] = 1f;
			} else {
				fft[i] = Math.max(x, fft[i] - 0.05f);
				lifetime[i] = Math.max(0, lifetime[i] - 0.1f);
			}
		}
	}
}