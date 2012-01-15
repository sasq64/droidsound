package com.ssb.droidsound.view;

import java.util.Arrays;
import java.util.Queue;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.SurfaceView;

import com.ssb.droidsound.utils.Color;
import com.ssb.droidsound.utils.OverlappingFFT;

public class VisualizationView extends SurfaceView {
	public static final int BINS = 12 * 7;

	protected static final String TAG = VisualizationView.class.getSimpleName();

	private final double minFreq = 110; /* A */
	private final float[] fft = new float[BINS * 2];
	private Color[] colors;

	private Queue<OverlappingFFT.Data> queue;

	private final Paint white;
	private final Paint fftPaint;

	public VisualizationView(Context context, AttributeSet attrs) {
		super(context, attrs);
		setWillNotDraw(false);
		white = new Paint();
		white.setColor(0xffffffff);
		white.setTextAlign(Paint.Align.CENTER);

		fftPaint = new Paint();
		//fftPaint.setAntiAlias(true);
	}

	public void setColors(Color[] colors) {
		this.colors = colors;
	}

	@Override
	protected void onSizeChanged(int w, int h, int oldw, int oldh) {
		fftPaint.setStrokeWidth((float) w / fft.length * 2f - 1f);
	}

	/**
	 * Set the data array. Visualizer will update as long as this exists.
	 *
	 * @param data
	 */
	public void setData(Queue<OverlappingFFT.Data> data) {
		this.queue = data;
		Arrays.fill(fft, 0);
		invalidate();
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

		for (int i = 1; i < fft.length - 1; i += 2) {
			float dbPrev = fft[i-1];
			float dbNorm = fft[i];
			float dbNext = fft[i+1];

			float hump = 2f * dbNorm - dbPrev - dbNext;
			float saturation = Math.max(0, Math.min(1, hump * 10f));
			fftPaint.setColor(colors[i / 2].toRGB((1f + saturation) * 0.5f, saturation));

			float x = (i + 0.5f) / (fft.length) * width;
			canvas.drawLine(x, height, x, height * (1f - dbNorm), fftPaint);
		}
	}

	private long updateFftData() {
		while (true) {
			long ctm = System.currentTimeMillis();
			OverlappingFFT.Data data = queue.peek();
			if (data == null) {
				return 100;
			}
			if (data.getTime() > ctm) {
				return data.getTime() - ctm;
			}

			data = queue.poll();
			if (data != null) {
				updateFftData(data.getFft());
			}
		}
	}

	private double projectFft(double idx) {
		return minFreq * Math.pow(2, idx / 12.0);
	}

	private static double getInterpolated(short[] buf, double x) {
		int i = (int) x;
		double f = x - i;

		/* Magnitude squared interpolation. */
		double re1 = buf[i << 1];
		double im1 = buf[(i << 1) | 1];
		double c1 = re1 * re1 + im1 * im1;
		double re2 = buf[(i + 1) << 1];
		double im2 = buf[((i + 1) << 1) | 1];
		double c2 = re2 * re2 + im2 * im2;
		return (c1 + (c2 - c1) * f) / (1 << 20);
	}

	private void updateFftData(short[] buf) {
		/* Remap data bins into our freq-linear fft */
		for (int i = 0; i < fft.length; i ++) {
			final double startFreq = projectFft((i - 1 - 0.5) / 2);
			final double endFreq = projectFft((i - 1 + 0.5) / 2);

			final double startIdx = startFreq / 22050 * (buf.length >> 1);
			final double endIdx = endFreq / 22050 * (buf.length >> 1);

			double lenSqMax = getInterpolated(buf, startIdx);
			int x = (int) startIdx + 1;
			int xEnd = (int) endIdx + 1;
			while (x < xEnd) {
				double re = buf[x << 1];
				double im = buf[(x << 1) | 1];
				lenSqMax = Math.max(lenSqMax, (re * re + im * im) / (1 << 20));
				x += 1;
			}

			double dB = Math.log(lenSqMax) / Math.log(10) * 10;

			/* 60 dB correlates with 1 << 10 above. The lowest bit seems to be pure noise,
			 * but because there's great degree of averaging of bins, the noise level is pushed
			 * to somewhat less than 60 dB except for lowest displayed bass frequencies. */
			fft[i] = ((float) dB / 60f) + 0.8f;
		}
	}
}