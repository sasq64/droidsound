package com.ssb.droidsound;

public class HVSCParser {
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
