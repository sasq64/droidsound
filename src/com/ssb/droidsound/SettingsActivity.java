package com.ssb.droidsound;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;

import android.app.Activity;
import android.app.ListActivity;
import android.content.Context;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.SimpleAdapter;

public class SettingsActivity extends ListActivity {

	class Setting {
		public Setting(String t, String st, int d) {
			title = t;
			subtitle = st;
			type = 0;
		}
		String title;
		String subtitle;
		int type;
		List<Setting> children;
	};
	
	Setting[] settings;
	
	class SettingsAdapter extends BaseAdapter {

		
		private Context context;

		public SettingsAdapter(Context ctx) {
			context = ctx;
		}
		
		@Override
		public int getCount() {
			return settings.length;
		}

		@Override
		public Object getItem(int position) {
			return settings[position];
		}

		@Override
		public long getItemId(int position) {
			// TODO Auto-generated method stub
			return position;
		}

		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			LayoutInflater inflater = ((Activity)context).getLayoutInflater();

			if(convertView == null) {
				convertView = inflater.inflate(R.layout.settings_item, null);
				ViewGroup vg = (ViewGroup)convertView;

				convertView.findViewById(R.id.text1);
				convertView.findViewById(R.id.text2);
				convertView.findViewById(R.id.check);
				
			}
			
			return convertView;
		}
	};
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		Resources res = getResources();
		String [] setting_strings = res.getStringArray(R.array.settings);
		List<Setting> settings = new ArrayList<Setting>();
		
		for(int i=0; i<setting_strings.length; i += 3) {
			settings.add(new Setting(setting_strings[i], setting_strings[i+1], 0));
		}

		SettingsAdapter adapter = new SettingsAdapter();		
		setListAdapter(adapter);
		
	}
	
	@Override
	protected void onDestroy() {
		super.onDestroy();
	}
	
}
