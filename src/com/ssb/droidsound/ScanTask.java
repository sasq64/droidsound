package com.ssb.droidsound;

import android.app.Application;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.os.AsyncTask;
import android.util.Log;

public class ScanTask extends AsyncTask<Void, String, Void> {
	private static final String TAG = ScanTask.class.getSimpleName();
	
	private boolean notified = false;
	private String lastPath = null;
	private static SongDatabase songDatabase;
	private boolean fullScan;
	private String modsDir;
	private NotificationManager manager;
	private Notification notification;
	private PendingIntent contentIntent;
	private Application application;
	private boolean drop;
	private String scanning;
	
	private static volatile ScanTask scanTask = null; 
	
	protected void finalize() throws Throwable {
		Log.v(TAG, "########## ScanTask finalize");
	};
	
	public static boolean scan(boolean fullScan, String modsDir, Application app, SongDatabase db) {
		if(scanTask != null) {
			return false;
		}
		songDatabase = db;
		scanTask = new ScanTask(fullScan, modsDir, app);
		scanTask.execute((Void)null);
		return true;
	}
	
	public static boolean isScanning() {
		return (scanTask != null);
	}
	
	private ScanTask(boolean fullScan, String modsDir, Application app) {
		this.fullScan = fullScan;
		this.modsDir = modsDir;
		application = app;
		
		scanning = app.getString(R.string.scanning);
		
		manager = (NotificationManager) app.getSystemService(Context.NOTIFICATION_SERVICE);	
		notification = new Notification(R.drawable.note, scanning, System.currentTimeMillis());				
		Intent notificationIntent = new Intent();
		contentIntent = PendingIntent.getActivity(app, 0, notificationIntent, 0);
	
		if(drop) {
			notification.setLatestEventInfo(application, scanning, "Clearing database", contentIntent);
			manager.notify(1, notification);
			notified = true;
		}
		
		
	}

	@Override
	protected Void doInBackground(Void... arg) {
				
		synchronized (this) {
			songDatabase = new SongDatabase(application, modsDir, drop);
			songDatabase.setScanCallback(new SongDatabase.ScanCallback() {					
				@Override
				public void notifyScan(String path, int percent) {					
					Log.v(TAG, String.format("NOTIFY %s %d", path, percent));
					publishProgress(path, Integer.toString(percent));
				}
			});
		}

		songDatabase.scan(fullScan);

		synchronized (this) {
			songDatabase.setScanCallback(null);
			songDatabase.closeDB();
			songDatabase = null;
		}
			
		return null;
	}
	
	public static void cancel() {
		scanTask.doCancel();
	}
	
	private synchronized void doCancel() {
		if(songDatabase != null) {
			songDatabase.stopScan();
		}
	}

	
	@Override
	protected void onProgressUpdate(String... values) {
		
		String path = values[0];
		int percent = Integer.parseInt(values[1]);

		if(path == null) {
			path = lastPath;
		} else {
			lastPath = path;
		}
		if(percent > 0) {
			path = String.format("%s [%02d%%]", path, percent);
		}
		notification.setLatestEventInfo(application, scanning, path, contentIntent);
		manager.notify(1, notification);
		notified = true;
	}

	@Override
	protected void onPostExecute(Void result) {
		if(notified) {
			manager.cancel(1);
			notified = false;
		}
		synchronized (scanTask) {
			scanTask = null;
		}
		Intent intent = new Intent("com.sddb.droidsound.SCAN_DONE");
		application.sendBroadcast(intent);

	}
}
