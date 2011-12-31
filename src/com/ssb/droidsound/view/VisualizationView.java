package com.ssb.droidsound.view;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.media.audiofx.Visualizer;
import android.util.AttributeSet;
import android.view.SurfaceView;

import com.ssb.droidsound.utils.Log;

public class VisualizationView extends SurfaceView {
	protected static final String TAG = VisualizationView.class.getSimpleName();

	private double minFreq;
	private double maxFreq;
	private float[] fft;
	private float[] lifetime;
	private float[][] coloring;

	private Visualizer visualizer;

	public VisualizationView(Context context, AttributeSet attrs) {
		super(context, attrs);
		setWillNotDraw(false);
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
		if (visualizer == null) {
			return;
		}

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

	private double projectFft(int idx) {
		return minFreq * Math.pow(2, idx / 12.0);
	}

	private void updateFftData(byte[] data) {
		data[1] = 0;
		/* Remap data bins into our freq-linear fft */
		for (int i = 0; i < fft.length; i ++) {
			double startFreq = projectFft(i);
			double endFreq = projectFft(i + 1);

			double startIdx = startFreq / 22050.0 * fft.length;
			double endIdx = endFreq / 22050.0 * fft.length;

			float n = (int) endIdx - (int) startIdx + 1;
			float lenSq = 0;
			for (int idx = (int) startIdx; idx < (int) endIdx + 1; idx ++) {
				float re = data[idx * 2] / 128f;
				float im = data[idx * 2 + 1] / 128f;
				lenSq += re * re + im * im;
			}
			lenSq /= n;

			double dB = Math.log(lenSq + 1e-5) / Math.log(10) * 10;

			float x = ((float) dB / 48f) + 0.8f;

			if (x > fft[i]) {
				fft[i] = x;
				lifetime[i] = 1f;
			} else {
				fft[i] = Math.max(x, fft[i] - 0.02f);
				lifetime[i] = Math.max(0, lifetime[i] - 0.1f);
			}
		}
		invalidate();
	}

	public Visualizer getVisualizer() {
		return visualizer;
	}

	public void setVisualizer(Visualizer v) {
		visualizer = v;
		if (v == null) {
			return;
		}

		int[] minmax = Visualizer.getCaptureSizeRange();
		int size = Math.min(4096, minmax[1]);
		size = Math.max(size, minmax[0]);

		minFreq = 1024 / size * 440;
		maxFreq = 14080;
		Log.i(TAG, "Requesting %d point FFT for %f-%f Hz display", size, minFreq, maxFreq);

		/* We try to get 2048 FFT values out (= 4096 bytes). This gives us about 10 Hz resolution,
		 * sufficient for good visualization.
		 */
		if (Visualizer.SUCCESS != v.setDataCaptureListener(new Visualizer.OnDataCaptureListener() {
			@Override
			public void onFftDataCapture(Visualizer visualizer, byte[] fft, int samplingRate) {
				updateFftData(fft);
			}

			@Override
			public void onWaveFormDataCapture(Visualizer visualizer, byte[] waveform, int samplingRate) {
			}
		}, 20000, false, true)) {
			throw new IllegalStateException("Invalid visualizer state");
		}
		if (Visualizer.SUCCESS != v.setCaptureSize(size)) {
			throw new IllegalStateException("Invalid visualizer state");
		}

		int bins = (int) ((Math.log(maxFreq) - Math.log(minFreq)) / Math.log(2) * 12);
		fft = new float[bins];
		lifetime = new float[bins];
		coloring = new float[bins][];
		calculateColors();

		if (Visualizer.SUCCESS != v.setEnabled(true)) {
			throw new IllegalStateException("Invalid visualizer state");
		}
	}
}