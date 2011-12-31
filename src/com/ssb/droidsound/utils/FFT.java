package com.ssb.droidsound.utils;

public class FFT {
	private static Complex[] fft(Complex[] in) {
		if (in.length == 2) {
			Complex even = in[0];
			Complex odd = in[1];
			return new Complex[] { even.add(odd), even.sub(odd) };
		}

		/* Get FFT of the odd and even samples */
		Complex[] half = new Complex[in.length >> 1];
		for (int i = 0; i < in.length; i += 2) {
			half[i >> 1] = in[i];
		}
		Complex[] evenFft = fft(half);
		for (int i = 1; i < in.length; i += 2) {
			half[i >> 1] = in[i];
		}
		Complex[] oddFft = fft(half);

		/* Merge the halves */
		Complex[] out = new Complex[in.length];
		for (int i = 0; i < half.length; i ++) {
			double angle = -2 * Math.PI * i / in.length;
			Complex wk = new Complex(Math.cos(angle), Math.sin(angle));
			Complex tmp = wk.mul(oddFft[i]);

			out[i] = evenFft[i].add(tmp);
			out[i + half.length] = evenFft[i].sub(tmp);
		}

		return out;
	}

	public static double[] spectrum(byte[] samples) {
		return powerDb(fft(windowedMono(samples)));
	}

	public static double[] cepstrum(byte[] samples) {
		Complex[] in = windowedMono(samples);
		Complex[] fft = fft(in);
		for (int i = 0; i < fft.length; i ++) {
			in[i] = new Complex(Math.log(fft[i].rhoSquared()), 0);
		}

		fft = fft(in);
		double[] out = new double[fft.length];
		for (int i = 0; i < fft.length; i ++) {
			out[i] = Math.log(fft[i].rhoSquared());
		}

		return out;
	}

	private static Complex[] windowedMono(byte[] samples) {
		Complex[] in = new Complex[samples.length];
		for (int i = 0; i < samples.length; i ++) {
			in[i] = new Complex(samples[i] / 128.0, 0);
		}
		return in;
	}

	private static double[] powerDb(Complex[] in) {
		double[] power = new double[in.length];
		for (int i = 0; i < in.length; i ++) {
			power[i] = lin2db(in[i].rhoSquared());
		}
		return power;
	}

	private static double lin2db(double rhoSquared) {
		return Math.log(rhoSquared) / Math.log(10) * 10; // 10 because squared
	}
}
