package com.ssb.droidsound.utils;

import java.util.List;

public interface PlaylistParser {

	String getMedia(int i);
	String getDescription(int i);
	int getMediaCount();
	List<String> getMediaList();
}
