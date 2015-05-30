package com.ssb.droidsound.utils;

import java.util.List;

public interface PlaylistParser {

	public String getMedia(int i);
	public String getDescription(int i);
	public int getMediaCount();
	public List<String> getMediaList();
	//String getWebPage();
	public String getVariable(String var);
}
