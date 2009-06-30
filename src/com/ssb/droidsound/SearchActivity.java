package com.ssb.droidsound;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.RemoteException;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

public class SearchActivity extends Activity {

	private Button searchButton;
	private Button cancelButton;
	private static final String TAG = "SearchActivity";

	@Override
    public void onCreate(Bundle savedInstanceState) {
    	super.onCreate(savedInstanceState);
    	
        setContentView(R.layout.search);
        
		searchButton = (Button) findViewById(R.id.searchButton);		
		searchButton.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				
				TextView t = (TextView) findViewById(R.id.titleEdit);
				TextView g = (TextView) findViewById(R.id.gameEdit);
				TextView a = (TextView) findViewById(R.id.authorEdit);

				
				Intent i = new Intent(SearchActivity.this, SearchResultActivity.class);
				i.putExtra("title", t.getText().toString());
				i.putExtra("game", g.getText().toString());
				i.putExtra("author", a.getText().toString());
				startActivityForResult(i, 1);
			}
		});

		cancelButton = (Button) findViewById(R.id.cancelButton);		
		cancelButton.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				finish();
			}
		});

	}
	
 	@Override
 	protected void onActivityResult(int requestCode, int resultCode, Intent data) {

 		Log.v(TAG, "Result " + resultCode);

 		if(resultCode != RESULT_CANCELED) {
 			Bundle b = data.getExtras();
 			String name = b.getString("name");
 			Log.v(TAG, "Got file " + name);

 			setResult(RESULT_OK, data);
 			finish();
 		}
 		
 		// ftp://modland.ziphoid.com/pub/modules/
 	}


}
