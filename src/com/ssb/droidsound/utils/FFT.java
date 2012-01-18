package com.ssb.droidsound.utils;

public class FFT {
	static {
		System.loadLibrary("fft");
	}

	/**
	 * Calculates the real-valued spectrum from input. The input is reduced to mono.
	 *
	 * @param in 16 bit stereo data, 2 * 2^n long
	 * @param out 16-bit spectral data in (real, imag) pairs, same length as input
	 */
	public static native void fft(short[] in, short[] out);
}
