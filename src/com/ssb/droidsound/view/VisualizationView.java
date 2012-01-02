package com.ssb.droidsound.view;

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
	public static final int BINS = 12 * 7;

	protected static final String TAG = VisualizationView.class.getSimpleName();

	private final double minFreq = 110;
	private final float[] fft = new float[BINS];
	private final float[] lifetime = new float[BINS];
	private final float[][] coloring = new float[BINS][];

	private Queue<FFTData> queue;

	public VisualizationView(Context context, AttributeSet attrs) {
		super(context, attrs);
		setWillNotDraw(false);
		calculateColors();
	}

	/**
	 * Set the data array. Visualizer will update as long as this exists.
	 *
	 * @param data
	 */
	public void setData(Queue<PlayerService.FFTData> data) {
		this.queue = data;
		invalidate();
	}

	private void calculateColors() {
		for (int i = 0; i < coloring.length; i ++) {
			double note = i / 12.0;
			float r = (float) (.5 + .5 * Math.sin(2 * Math.PI * note));
			float g = (float) (.5 + .5 * Math.sin(2 * Math.PI * (note + 1/3.0)));
			float b = (float) (.5 + .5 * Math.sin(2 * Math.PI * (note + 2/3.0)));
			coloring[i] = new float[] { r, g, b };
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
			float a = lifetime[i];
			fftPaint.setColor(0xff000000
					| (Math.round((float) Math.sqrt(a * coloring[i][0]) * 255) << 16)
					| (Math.round((float) Math.sqrt(a * coloring[i][1]) * 255) << 8)
					| (Math.round((float) Math.sqrt(a * coloring[i][2]) * 255) << 0)
			);

			float x = (i + 0.5f) / (fft.length) * width;
			canvas.drawLine(x, height, x, height * (1f - dBNorm), fftPaint);
		}
	}

	private double projectFft(double idx) {
		return minFreq * Math.pow(2, idx / 12.0);
	}

	private static double getBin(int idx, short[] data) {
		/* FIXME: not sure of the scale factor. It's supposed to be 1 << 16 but it is not.
		 * The FFT code must apply some kind of scaling, but it's not a value I expect. */
		float re = data[idx * 2] / (float) (1 << 8);
		float im = data[idx * 2 + 1] / (float) (1 << 8);
		return re * re + im * im;
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