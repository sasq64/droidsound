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
	private final float[] fft = new float[BINS];
	private final float[] lifetime = new float[BINS];
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
		fftPaint.setAntiAlias(true);
	}

	public void setColors(Color[] colors) {
		this.colors = colors;
	}

	@Override
	protected void onSizeChanged(int w, int h, int oldw, int oldh) {
		fftPaint.setStrokeWidth(w / 2f / fft.length);
	}

	/**
	 * Set the data array. Visualizer will update as long as this exists.
	 *
	 * @param data
	 */
	public void setData(Queue<OverlappingFFT.Data> data) {
		this.queue = data;
		Arrays.fill(fft, 0);
		Arrays.fill(lifetime, 0);
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

		Paint fftPaint = new Paint();
		fftPaint.setAntiAlias(true);
		fftPaint.setStrokeWidth(width / 2f / fft.length);
		for (int i = 0; i < fft.length; i ++) {
			float dbPrev = i == 0 ? fft[i] : fft[i - 1];
			float dbNorm = fft[i];
			float dbNext = i == fft.length - 1 ? fft[i] : fft[i + 1];

			float hump = 2f * dbNorm - dbPrev - dbNext;
			float saturation = Math.max(0, Math.min(1, hump * 5f));

			float luminosity = lifetime[i];
			fftPaint.setColor(colors[i].toRGB(luminosity, saturation));

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

	private void updateFftData(short[] buf) {
		/* Remap data bins into our freq-linear fft */
		for (int i = 0; i < fft.length; i ++) {
			double startFreq = projectFft(i - 0.5);
			double endFreq = projectFft(i + 0.5);

			double startIdx = startFreq / 22050 * (buf.length >> 1);
			double endIdx = endFreq / 22050 * (buf.length >> 1);

			double lenSqMax = 1e-10;
			while (endIdx - startIdx > 1e-10) {
				int intStartIdx = (int) startIdx;
				/* Determine width inside the current bin. */
				double width = Math.min(endIdx - startIdx, intStartIdx + 1 - startIdx) + 1e-10;
				float re = buf[intStartIdx << 1] / (float) (1 << 10);
				float im = buf[(intStartIdx << 1) + 1] / (float) (1 << 10);
				double lenSq = (re * re + im * im) * width;
				if (lenSq > lenSqMax) {
					lenSqMax = lenSq;
				}
				startIdx += width;
			}

			double dB = Math.log(lenSqMax) / Math.log(10) * 10;

			/* 60 dB correlates with 1 << 10 above. The lowest bit seems to be pure noise,
			 * but because there's great degree of averaging of bins, the noise level is pushed
			 * to somewhat less than 60 dB except for lowest displayed bass frequencies. */
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