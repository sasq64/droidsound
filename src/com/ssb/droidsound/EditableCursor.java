package com.ssb.droidsound;

public interface EditableCursor {
	
	boolean moveRow(int from, int to);
	boolean removeRow(int row);

}
