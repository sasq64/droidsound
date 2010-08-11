package com.ssb.droidsound;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.util.Log;

public class HVSCParser {
	private static final String TAG = HVSCParser.class.getSimpleName();
		
	static private class XInfo {
		List<String> names;
		List<short[]> lengths;
	};

	static private class Info {
		XInfo xinfo;
		short length;
	};
	
	
	Map<Integer, Info> nameMap;
	

	short[] getSongLength(String name) {
		String n = name.substring(8);
		int hc = n.hashCode();
		Info info = nameMap.get(hc);
		if(info != null) {
			if(info.xinfo == null) {
				short [] s = new short [1];
				s[0] = info.length;
				return s;
			}
			for(int i = 0; i<info.xinfo.names.size(); i++) {
				if(info.xinfo.names.get(i).equals(n)) {
					return info.xinfo.lengths.get(i);
				}
			}
		}
		return null;
	}
	
	void free() {
		nameMap = null;
	}

	
	void parseSongLengths(InputStream is) throws IOException {
		
		InputStreamReader reader = new InputStreamReader(is);
		BufferedReader breader = new BufferedReader(reader);
		String line0, line1;

		nameMap = new HashMap<Integer, Info>();
		
		line0 = breader.readLine();
		if(line0.equals("[Database]")) {
			int counter = 0;
			while(true) {
				line0 = breader.readLine();
				
				counter++;
				if(counter == 4630) {
					break;
				}
				
				if(line0 == null)
					break;
				line1 = breader.readLine();
				if(line1 == null)
					break;
				String name = line0.substring(2);
				int eq = line1.indexOf('=');
				if(eq > 0) {
					short [] array = null;
					
					String [] lengths;
					if(line1.indexOf(' ') < 0) {
						lengths = new String [1];
						lengths[0] = line1.substring(eq+1);
					} else {
						lengths = line1.substring(eq+1).split(" ");
					}
					//System.out.printf("%s = %s\n", name, length);
					//int len = Integer.parseInt(arg0);
					int hc = name.hashCode();
					if(name.equals("/GAMES/0-9/5_A_Row.sid")) {
						Log.v(TAG, String.format("Name '%s'%d %d : %s", name, hc, lengths.length, lengths[0]));
					}
											
					Info info = nameMap.get(hc);
					
					if(info != null || lengths.length > 1) {
						Log.v(TAG, "Allocating extra info");
						if(info == null) {
							info = new Info();
							info.length = -1;
						}
						if(info.xinfo == null) {
							info.xinfo = new XInfo();
							info.xinfo.names = new ArrayList<String>();
							info.xinfo.lengths = new ArrayList<short[]>();
						}

						info.xinfo.names.add(name);
						array = new short [lengths.length];
						info.xinfo.lengths.add(array);

					} else {
						info = new Info();
					}
					int i = 0;
					for(String x : lengths) {
						int colon = x.indexOf(':');
						int para =  x.indexOf('(');
						if(para > 0) {
							x = x.substring(0,para);
						}

						info.length = (short) (Integer.parseInt(x.substring(0, colon)) * 60 + Integer.parseInt(x.substring(colon+1)));
						if(array != null) {
							array[i++] = info.length;
						}
					}
					
					nameMap.put(name.hashCode(), info);
					
				}
			}
		}
		
	}
	/*
	ZipEntry le = zfile.getEntry("C64Music/DOCUMENTS/Songlengths.txt");
	if(le != null) {
		data = new byte [(int) le.getSize()] ;
		
		InputStreamReader reader = new InputStreamReader(zfile.getInputStream(le));
		BufferedReader breader = new BufferedReader(reader);
		String line0, line1;

		HashMap<String, String> hmap = new HashMap<String, String>();
		
		line0 = breader.readLine();
		if(line0.equals("[Database]")) {
			
			while(true) {
				line0 = breader.readLine();
				if(line0 == null)
					break;
				line1 = breader.readLine();
				if(line1 == null)
					break;
				String name = line0.substring(2);
				int eq = line1.indexOf('=');
				if(eq > 0) {
					String length = line1.substring(eq+1);
					//System.out.printf("%s = %s\n", name, length);
					//int len = Integer.parseInt(arg0);
					hmap.put(name, length);
				}
			}
		}
	}*/
	
	//String n = ze.getName().substring(8);
	/*
	System.out.printf("%s %s %s (%02d/%02d)\n", name, author, copyright, startSong, songs);
	String length = hmap.get(n.substring(8));
	int iLength = 0;
	if(length != null) {					
		String lens [] = length.split(" ");
		System.out.printf("%s --- %d\n", length, lens.length);
		if(lens.length > 1)
			length = lens[startSong-1];
		int colon = length.indexOf(':');
		int min = Integer.parseInt(length.substring(0, colon));
		int sec = Integer.parseInt(length.substring(colon+1, colon+3));
		iLength = min*60+sec;
		System.out.printf("%s %s ==> %d seconds\n", n, length, iLength);
	} */
	
	//int year = 0;
	//try {
	//	year = Integer.parseInt(copyright.substring(0,4));
	//} catch (NumberFormatException e) {
	//}
	


}
