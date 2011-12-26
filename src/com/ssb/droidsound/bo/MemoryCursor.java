package com.ssb.droidsound.bo;

import android.database.AbstractCursor;

public final class MemoryCursor extends AbstractCursor {
	private final String[] columns;
	private final Object[][] data;

	public MemoryCursor(String[] columns, Object[][] data) {
		this.columns = columns;
		this.data = data;
	}

	@Override
	public String[] getColumnNames() {
		return columns;
	}

	@Override
	public int getCount() {
		return data.length;
	}

	@Override
	public double getDouble(int c) {
		if (isNull(c)) {
			return 0;
		}
		return (Double) data[getPosition()][c];
	}

	@Override
	public float getFloat(int c) {
		if (isNull(c)) {
			return 0;
		}
		return (Float) data[getPosition()][c];
	}

	@Override
	public int getInt(int c) {
		if (isNull(c)) {
			return 0;
		}
		return (Integer) data[getPosition()][c];
	}

	@Override
	public long getLong(int c) {
		if (isNull(c)) {
			return 0;
		}
		return (Long) data[getPosition()][c];
	}

	@Override
	public short getShort(int c) {
		if (isNull(c)) {
			return 0;
		}
		return (Short) data[getPosition()][c];
	}

	@Override
	public String getString(int c) {
		return (String) data[getPosition()][c];
	}

	@Override
	public boolean isNull(int c) {
		return data[getPosition()][c] == null;
	}
}