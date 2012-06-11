package com.ssb.droidsound.plugins;

import java.io.UnsupportedEncodingException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.HashMap;
import java.util.Map;

import com.ssb.droidsound.utils.Log;

public class PSFFile {
	private static final String TAG = PSFFile.class.getSimpleName();

	public static int parseLength(String s) {
		//int decimal = 0;
		int seconds = 0;

		if(s == null) return 0;
		int lastSep = 0; 
		for(int i = 0; ; i++) {
			char c = (i < s.length()) ? s.charAt(i) : '.';
			if(c == ':' || c == '.') {
				seconds *= 60;
				seconds += Integer.parseInt(s.substring(lastSep, i));
				lastSep = i+1;
				if(c == '.')
					break;
			}
		}
		return seconds * 1000;
	}
	
	public static Map<String, String> getTags(byte [] module, int size) {
		ByteBuffer src = ByteBuffer.wrap(module, 0, size);		
		src.order(ByteOrder.LITTLE_ENDIAN);		
		byte[] id = new byte[4];
		src.get(id);
		
		//for(int i=0; i<128; i++)
		//	info[i] = null;
		
		//info = new String [128];
		
		if(id[0] == 'P' && id[1] == 'S' && id[2] == 'F' /*&& id[3] == 1*/) {
			
			
			int resLen = src.getInt();
			int comprLen = src.getInt();

			src.position(resLen + comprLen + 16);
			
			if(src.remaining() >= 5) {
				
				byte [] tagHeader = new byte[5];		
				src.get(tagHeader);
				
				if(new String(tagHeader).equals("[TAG]")) {
					
					byte [] tagData = new byte [ size - comprLen - resLen - 21];
					src.get(tagData);
					
					try {
						String tags = new String(tagData, "ISO-8859-1").trim();
						
						if(tags.contains("utf8=1")) {
							tags = new String(tagData, "UTF-8").trim();
						}
						
						
						String [] lines = tags.split("\n");
						
						HashMap<String, String> tagMap = new HashMap<String, String>();
						
						for(String line : lines) {
							Log.d(TAG, "TAG: %s", line);
							String parts [] = line.split("=");
							if(parts.length >= 2)
								tagMap.put(parts[0], parts[1]);
						}
						return tagMap;
					} catch (UnsupportedEncodingException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
		}
		return null;
	}

}
