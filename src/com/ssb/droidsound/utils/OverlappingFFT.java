package com.ssb.droidsound.utils;

import java.util.Queue;
import java.util.concurrent.DelayQueue;
import java.util.concurrent.Delayed;
import java.util.concurrent.TimeUnit;

/**
 * This class performs 4096 point FFT with 75 % overlap between
 * successive frames, and publishes results with timestamps which mark the time
 * for their consumption.
 *
 * @author alankila
 */
public class OverlappingFFT {
	public static class Data implements Delayed {
		private final Long time;
		private final short[] fft;

		public Data(long time, short[] fft) {
			this.time = time;
			this.fft = fft;
		}

		public short[] getFft() {
			return fft;
		}

		@Override
		public int compareTo(Delayed other) {
			return time.compareTo(((Data) other).time);
		}

		@Override
		public long getDelay(TimeUnit tu) {
			long millis = time - System.currentTimeMillis();
			return tu.convert(millis, TimeUnit.MILLISECONDS);
		}
	}

	private static final String TAG = OverlappingFFT.class.getSimpleName();

	/** Queue of generated FFT frames for later processing. */
	private final Queue<Data> queue = new DelayQueue<Data>();

	/** Accumulation buffer until full FFT has been reached. 16-bit stereo. */
	private final short[] fftSamples = new short[8192 * 2];

	/** Current index within accumulation buffer */
	private int fftSamplesIdx;

	/** Audio output rate */
	private final int frameRate;

	/** Length of data buffering */
	private final int bufferingMs;

	/** Maximum # of entries permitted in queue. */
	private final int maxLength;

	public OverlappingFFT(int bufsizeFrames, int frameRate) {
		this.frameRate = frameRate;
		bufferingMs = bufsizeFrames * 1000 / frameRate;
		int framesPerFft = fftSamples.length / 2;
		int fullFramesPerSecond = frameRate / framesPerFft;
		int fullFramesPerSecondWithOverlap = fullFramesPerSecond * 4;
		int fftFramesRequired = fullFramesPerSecondWithOverlap * bufferingMs / 1000;

		Log.i(TAG, "FFT timing information: %d full frames required, %d ms buffer",
				fftFramesRequired, bufferingMs);

		/* Adding some extra buffers here to allow scheduling glitches etc. */
		maxLength = fftFramesRequired + 4;
	}

	public void feed(short[] samples, int posInSamples, int lengthInSamples) {
		/* This assumes that the last audiotrack.write() just filled the buffer
		 * maximally. However, I don't know if it's actually true. */
		long estimatedPlaybackTime = System.currentTimeMillis() + bufferingMs;
		while (posInSamples < lengthInSamples) {
			/* Fill as much as possible into fftInput1 */
			int copyLenInSamples = Math.min(lengthInSamples - posInSamples, fftSamples.length - fftSamplesIdx);
			System.arraycopy(samples, posInSamples, fftSamples, fftSamplesIdx, copyLenInSamples);
			fftSamplesIdx += copyLenInSamples;
			posInSamples += copyLenInSamples;

			/* Complete buffer? */
			if (fftSamplesIdx == fftSamples.length) {
				/* The length is halved because FFT is computed over mono signal,
				 * and then halved again because only half of the FFT spectrum is
				 * actually returned.
				 */
				short[] buf = new short[fftSamples.length >> 2];
				synchronized (queue) {
					if (queue.size() > maxLength) {
						queue.poll();
					}

					/* Run FFT, and place estimated time this buffer will be played back
					 * at start of some ignored FFT components... */
					FFT.fft(fftSamples, buf);
					long time = estimatedPlaybackTime + 1000 * posInSamples / 2 / frameRate;
					queue.add(new Data(time, buf));
				}

				fftSamplesIdx = (fftSamples.length >> 2) * 3;
				System.arraycopy(fftSamples, fftSamples.length >> 2, fftSamples, 0, fftSamplesIdx);
			}
		}
	}

	public Queue<Data> getQueue() {
		return queue;
	}
}