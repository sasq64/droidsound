package com.ssb.droidsound.view;

public class Color {
	private final float r, g, b;

	protected Color(float r, float g, float b) {
		this.r = r;
		this.g = g;
		this.b = b;
	}

	protected float gamma(float arg) {
		return (float) Math.pow(arg, 1/2.2);
	}

	protected int toRGB(float luminosity, float saturation) {
		float s = (r + g + b) / 3;
		float r2 = r * saturation + s * (1f - saturation);
		float g2 = g * saturation + s * (1f - saturation);
		float b2 = b * saturation + s * (1f - saturation);

		return 0xff000000
				| (Math.round(gamma(luminosity * r2) * 255) << 16)
				| (Math.round(gamma(luminosity * g2) * 255) << 8)
				| (Math.round(gamma(luminosity * b2) * 255) << 0);
	}
}