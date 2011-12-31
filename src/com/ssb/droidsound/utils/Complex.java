package com.ssb.droidsound.utils;

/**
 * Java support for complex numbers.
 *
 * @author alankila
 */
class Complex {
	private final double re, im;

	protected Complex(double re, double im) {
		this.re = re;
		this.im = im;
	}

	/**
	 * Return length of complex number
	 *
	 * @return length
	 */
	protected double rhoSquared() {
		return re * re + im * im;
	}

	/**
	 * Complex addition
	 *
	 * @param other
	 * @return sum
	 */
	protected Complex add(Complex other) {
		return new Complex(re + other.re, im + other.im);
	}

	/**
	 * Complex subtraction
	 *
	 * @param other
	 * @return sum
	 */
	public Complex sub(Complex other) {
		return new Complex(re - other.re, im - other.im);
	}

	/**
	 * Complex multipply
	 *
	 * @param other
	 * @return multiplication result
	 */
	protected Complex mul(Complex other) {
		return new Complex(re * other.re - im * other.im, re * other.im + im * other.re);
	}
}