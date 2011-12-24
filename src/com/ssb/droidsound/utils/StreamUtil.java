package com.ssb.droidsound.utils;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class StreamUtil {
	public static void copy(InputStream is, OutputStream os) throws IOException {
		byte[] buffer = new byte[10240];
		int length;
		while (0 != (length = is.read(buffer))) {
			os.write(buffer, 0, length);
		}
	}
}
