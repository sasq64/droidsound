package com.ssb.droidsound;

import android.app.Activity;
import android.os.Bundle;
import android.widget.ListView;

public class PlayListActivity extends Activity {
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        setContentView(R.layout.playlist);
        
        ListView view = (ListView)findViewById(R.id.PlayListView);
    }

}
