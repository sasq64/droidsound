package com.ssb.droidsound.utils;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLConnection;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

final class HttpDownloader  {
	private static final String TAG = HttpDownloader.class.getSimpleName();
	
	interface Callback {
		void onDisplayProgress(int progress);
		void onDone();
	}

    //static private String urlencode(String s){ weakened type below
	private static String urlencode(CharSequence s) {
		StringBuilder t = new StringBuilder();

		for(int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			switch(c) {
			case 0x20:
			case 0x24:
			case 0x25:
			case 0x26:
			case 0x2B:
			case 0x2C:
				// case 0x2F:
				// case 0x3A:
			case 0x3B:
			case 0x3D:
			case 0x3F:
			case 0x40:
				t.append(String.format("%%%02x", (int) c));
				break;
			default:
				t.append(c);
				break;
			}
		}

		return t.toString();
	}

	public static boolean downloadFiles(Callback cb, String target, String... urls) {

		try {
			InputStream in = null;
			int response = -1;
            byte[] buffer = new byte[16384];

			//String outDir = Environment.getExternalStorageDirectory() + "/MODS/";
            int fileCount = 0;
			for(String u : urls) {

				String uu = urlencode(u);
				URL url = new URL(uu);

				Log.d(TAG, "Opening URL " + uu);

				URLConnection conn = url.openConnection();
				if(!(conn instanceof HttpURLConnection)){
					throw new IOException("Not a HTTP connection");
				}

				HttpURLConnection httpConn = (HttpURLConnection) conn;
				httpConn.setAllowUserInteraction(false);
				httpConn.setInstanceFollowRedirects(true);
				httpConn.setRequestMethod("GET");

				Log.d(TAG, "Connecting");

				httpConn.connect();

				response = httpConn.getResponseCode();
				if(response == HttpURLConnection.HTTP_OK) {
					Log.d(TAG, "HTTP connected");
					in = httpConn.getInputStream();

					String ext = u.substring(u.lastIndexOf('.') + 1, u.length());
					String baseName = new File(u).getName();

                    int size;
                    if(ext.compareToIgnoreCase("ZIP") == 0) {
						ZipInputStream zip = new ZipInputStream(in);
						ZipEntry e;
						int zipCount = 0;
						while((e = zip.getNextEntry()) != null) {
							Log.d(TAG, "Found file " + e.getName());
							FileOutputStream fos = new FileOutputStream(target + e.getName());
							BufferedOutputStream bos = new BufferedOutputStream(fos, buffer.length);
							while((size = zip.read(buffer, 0, buffer.length)) != -1) {
								bos.write(buffer, 0, size);
							}
							bos.flush();
							bos.close();
							
							if(cb != null) {
								cb.onDisplayProgress(fileCount * 100 + zipCount);
							}
							zipCount += 1;
						}

					} else {

						Log.d(TAG, "Writing " + baseName);

						FileOutputStream fos = new FileOutputStream(target + baseName);
						BufferedOutputStream bos = new BufferedOutputStream(fos, buffer.length);
						while((size = in.read(buffer)) != -1) {
							bos.write(buffer, 0, size);
						}
						bos.flush();
						bos.close();
					}
					if(cb != null) {
						cb.onDisplayProgress(fileCount * 100);
					}

				} else {
					return false;
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
			Log.w(TAG, "OOPS");
			return false;
		}
		if(cb != null) {
			cb.onDone();
		}
		return true;
	}
}