package com.ssb.droidsound;

public interface PlaylistSource {

	
	public int getCount();
	public boolean isDir(int pos);
	public String getName(int pos);
	
}
