package com.ssb.droidsound.view;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.media.audiofx.Visualizer;
import android.util.AttributeSet;
import android.view.SurfaceView;

public class VisualizationView extends SurfaceView {
	protected static final String TAG = VisualizationView.class.getSimpleName();
	private static final int FFT_SIZE = 256;

	private final float[] fft = new float[FFT_SIZE / 2];
	private final float[] lifetime = new float[FFT_SIZE / 2];

	private Visualizer visualizer;

	public VisualizationView(Context context, AttributeSet attrs) {
		super(context, attrs);
		setWillNotDraw(false);
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
			double frequency = i / 22050.0 * fft.length;
			float dBNorm = fft[i];
			double note = Math.log(frequency) / Math.log(2) * 2 * Math.PI;

			double phaseterm = Math.PI * 2 / 3;
			float r = (float) (.5 + .5 * Math.sin(note));
			float g = (float) (.5 + .5 * Math.sin(note + phaseterm));
			float b = (float) (.5 + .5 * Math.sin(note + 2 * phaseterm));
			float a = lifetime[i];
			fftPaint.setColor(0xff000000
					| (Math.round((float) Math.sqrt(a * r) * 255) << 16)
					| (Math.round((float) Math.sqrt(a * g) * 255) << 8)
					| (Math.round((float) Math.sqrt(a * b) * 255) << 0)
			);

			float x = (i + 0.5f) / (fft.length) * width;
			canvas.drawLine(x, height, x, height * (1f - dBNorm), fftPaint);
		}
	}

	private void updateFftData(byte[] waveData) {
		waveData[1] = 0;
		for (int i = 0; i < fft.length; i ++) {
			float re = waveData[i * 2] / 128f;
			float im = waveData[i * 2 + 1] / 128f;
			float lenSq = re * re + im * im;
			double dB = Math.log(lenSq + 1e-5) / Math.log(10) * 10;

			float x = ((float) dB / 48f) + 0.8f;

			if (x > fft[i]) {
				fft[i] = x;
				lifetime[i] = x;
			} else {
				fft[i] = Math.max(x, fft[i] - 0.02f);
				lifetime[i] = Math.max(0, lifetime[i] - 0.08f);
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
		if (Visualizer.SUCCESS != v.setCaptureSize(FFT_SIZE)) {
			throw new IllegalStateException("Invalid visualizer state");
		}
		if (Visualizer.SUCCESS != v.setEnabled(true)) {
			throw new IllegalStateException("Invalid visualizer state");
		}
	}
}