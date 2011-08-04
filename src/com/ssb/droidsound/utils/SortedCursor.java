package com.ssb.droidsound.utils;

import android.database.Cursor;
import android.database.CursorWrapper;

class SortedCursor extends CursorWrapper {

	private int [] sorted;

	public SortedCursor(Cursor cursor) {
		super(cursor);
	}

	@Override
	public boolean move(int offset) {
		return super.move(sorted[offset]);
	}

	@Override
	public boolean moveToFirst() {
		//return super.moveToPosition(sorted[0]);
        return moveToPosition(sorted[0]); //Super is redundant
	}

	@Override
	public boolean moveToLast() {
		//return super.moveToPosition(sorted[sorted.length-1]);
        return moveToPosition(sorted[sorted.length-1]); //super is redundant
	}

	@Override
	public boolean moveToNext() {
		// TODO Auto-generated method stub
		return super.moveToNext();
	}

    public void setSorted(int... sorted) {
        this.sorted = sorted;
    }
}
