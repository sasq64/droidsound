package com.ssb.droidsound.utils;

public final class Log {
	
	public static void d(String tag, String fmt, Object...args) {
		String line = tag + ": " + String.format(fmt, args);
		android.util.Log.d("Droidsound", line);
	}
	
	public static void d(String tag, String line) {
		android.util.Log.d("Droidsound", tag + ": " + line);
	}

	public static void w(String tag, String line) {
		android.util.Log.w("Droidsound", tag + ": " + line);
	}

	public static void w(String tag, String line, Throwable th) {
		android.util.Log.w("Droidsound", tag + ": " + line, th);
	}

	public static void i(String tag, String fmt, Object...args) {
		String line = tag + ": " + String.format(fmt, args);
		android.util.Log.i("Droidsound", line);
	}
}
