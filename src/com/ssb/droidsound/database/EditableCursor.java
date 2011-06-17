package com.ssb.droidsound.database;

public interface EditableCursor {
	
	boolean moveRow(int from, int to);
	boolean removeRow(int row);

}
