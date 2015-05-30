package com.ssb.droidsound.utils;

import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import android.database.Cursor;
import android.database.CursorWrapper;
import android.util.SparseArray;

public class CursorTransform {
	private static final String TAG = CursorTransform.class.getSimpleName();
	
	private static class ColTransform {
		public String pattern;
		public int offsets [];
		public String varnames [];
		public int columnIndex;
		public int value;
	}

	private static class TransformWrapper extends CursorWrapper {

		private Map<String, ColTransform> transformMap;
		//private Map<Integer, Map<String, Integer> > transformColMap;

		
		private SparseArray<ColTransform> indexMap;
		private Cursor cursor;
		private int colIndex = 100;

		public TransformWrapper(Cursor cr, Map<String, ColTransform> txmap) {
			super(cr);
			transformMap = txmap;
			indexMap = new SparseArray<ColTransform>();
			cursor = cr;
			
			Set<Entry<String, ColTransform>> es = txmap.entrySet();
			for(Entry<String, ColTransform> e : es) {
				ColTransform ct = e.getValue();
				ct.columnIndex = -1;
				
				if(ct.varnames != null) {
					for(int i=0; i<ct.varnames.length; i++) {
						//Log.d(TAG, "Checking %s", ct.varnames[i]);
						ct.offsets[i] |= (cursor.getColumnIndex(ct.varnames[i]) << 8);
						//Log.d(TAG, "Offset %d: %x", i, ct.offsets[i]);
					}
				}
				
			}
		}
		
		@Override
		public int getColumnIndex(String columnName) {
			ColTransform ct = transformMap.get(columnName);
			if(ct != null) {
				if(ct.columnIndex >= 0)
					return ct.columnIndex;
				ct.columnIndex = colIndex++;
				//Log.d(TAG, "Assigning %d to column %s", ct.columnIndex, columnName);
				indexMap.put(ct.columnIndex, ct);				
				return ct.columnIndex;
			}
			
			return super.getColumnIndex(columnName);
		}
		
		@Override
		public String getString(int columnIndex) {
			ColTransform cols = indexMap.get(columnIndex);
			if(cols != null) {
				String result = cols.pattern;				
				for(int i=0; i<cols.offsets.length; i++) {
					String txt = cursor.getString(cols.offsets[i]>>8);
					if(txt == null || txt.equals("null")) txt = "";
					//Log.d(TAG, "Col %d -> %d -> %s", columnIndex, cols.offsets[i]>>8, txt);
					int pos = cols.offsets[i]&0xff;
					result = result.substring(0,pos) + txt + result.substring(pos);
				}
				return result;
			}
			
			return super.getString(columnIndex);
		}
		
		@Override
		public int getInt(int columnIndex) {
			ColTransform cols = indexMap.get(columnIndex);
			if(cols != null) {
				return cols.value;
			}
			return super.getInt(columnIndex);
		}
	};
	
	private Map<String, ColTransform> transformMap = new HashMap<String, ColTransform>();
	
	
	public void addTransform(String column, int val) {
		
		ColTransform ct = new ColTransform();
		ct.value = val;
		transformMap.put(column, ct);
	}	

	public void addTransform(String column, String pattern) {
		
		int start, end;
		//Map<String, Integer> cols = new HashMap<String, Integer>();
		int offsets [] = new int [16];
		String varnames [] = new String [16]; 
		
		Log.d(TAG, "Checking '%s'", pattern);
		
		start = end = 0;
		int i = 0;
		while(start >= 0 && end >= 0) {
			start = pattern.indexOf("${", start);
			if(start >= 0) {
				end = pattern.indexOf('}', start);
				if(end >= 0) {
					String s = pattern.substring(start+2, end);
					offsets[i] = start;
					varnames[i] = s;
					i++;
					//Log.d(TAG, "Found '%s' at %d", s, start);
					pattern = pattern.substring(0, start) + pattern.substring(end+1);
					//Log.d(TAG, "Pattern now '%s'", pattern);
				}
			}
		}
		int len = i;
		
		ColTransform ct = new ColTransform();
		ct.pattern = pattern;
		ct.offsets = new int [len];
		ct.varnames = new String [len];
		for(i=0; i<len; i++) {
			ct.varnames[i] = varnames[i];
			ct.offsets[i] = offsets[i];
		}
		
		
		transformMap.put(column, ct);
	}
	
	
	public Cursor transformCursor(Cursor cr) {
		return new TransformWrapper(cr, transformMap);
	}


}
