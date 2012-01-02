package com.ssb.droidsound.view;

import java.util.Arrays;
import java.util.Queue;
import java.util.concurrent.TimeUnit;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.SurfaceView;

import com.ssb.droidsound.utils.OverlappingFFT;

public class VisualizationView extends SurfaceView {
	public static final int BINS = 12 * 7;

	protected static final String TAG = VisualizationView.class.getSimpleName();

	private final double minFreq = 110; /* A */
	private final float[] fft = new float[BINS];
	private final float[] lifetime = new float[BINS];
	private VisualizationInfoView.Color[] colors;

	private Queue<OverlappingFFT.Data> queue;

	private final Paint white;

	public VisualizationView(Context context, AttributeSet attrs) {
		super(context, attrs);
		setWillNotDraw(false);
		white = new Paint();
		white.setColor(0xffffffff);
		white.setTextAlign(Paint.Align.CENTER);
	}

	public void setColors(VisualizationInfoView.Color[] colors) {
		this.colors = colors;
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

		long futureDelay = -1;
		while (futureDelay < 0) {
			futureDelay = updateFftData();
		}
		postInvalidateDelayed(futureDelay);

		int width = getWidth();
		int height = getHeight();

		Paint fftPaint = new Paint();
		for (int i = 0; i < fft.length; i ++) {
			float dBNorm = fft[i];
			float luminosity = lifetime[i];
			fftPaint.setColor(colors[i].toRGB(luminosity));

			float x = (i + 0.5f) / (fft.length) * width;
			canvas.drawLine(x, height, x, height * (1f - dBNorm), fftPaint);
		}
	}

	private long updateFftData() {
		synchronized (queue) {
			OverlappingFFT.Data data = queue.poll();
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
				float re = buf[intStartIdx << 1] / (float) (1 << 10);
				float im = buf[(intStartIdx << 1) + 1] / (float) (1 << 10);
				lenSq += re * re + im * im;
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