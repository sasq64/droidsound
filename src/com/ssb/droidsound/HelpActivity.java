package com.ssb.droidsound;

import java.io.IOException;
import java.io.InputStream;

import android.app.Activity;
import android.os.Bundle;
import android.webkit.WebView;
import com.ssb.droidsoundedit.R;

public class HelpActivity extends Activity {

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.main);
        WebView webView = new WebView(this);

        try {
            InputStream is = getAssets().open("doc.html");
            byte [] data = new byte [is.available()];
	        is.read(data);
	        is.close();
	        String html = new String(data, "ISO8859_1");
	        webView.loadData(html, "text/html", "utf-8");
	        setContentView(webView);
		} catch (IOException e) {
			e.printStackTrace();
		}
    }
}
