package com.ssb.droidsound.service;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.telephony.TelephonyManager;
import android.view.KeyEvent;

import com.ssb.droidsound.utils.Log;

public class RemoteControlReceiver extends BroadcastReceiver {
	private static final String TAG = RemoteControlReceiver.class.getSimpleName();
	private static Handler handler;
	private volatile static MyRunnable currentRunnable;
	public static boolean paused;
	
	private static class MyRunnable implements Runnable {		

		//private RemoteControlReceiver parent;
		private PlayerInterface player;
		private int pressTime;
		private volatile int clicks;
		private volatile int cancel;

		public MyRunnable(int pressTime) {
			this.pressTime = pressTime;
			clicks = 0;
			player = PlayerService.getPlayerInterface();
		}
		
		@Override
		public void run() {
			
			if(cancel > 0) {
				cancel--;
				return;
			}
						
			Log.d(TAG, "RUNNING RUNNABLE %d/%d", clicks,pressTime);
			
			if(clicks > 0) {				
				if(paused) {
					paused = false;					
					player.playPrevSong(clicks);
					player.paused(false);
				} else {
					player.playNextSong(clicks);
				}
			} else
			if(pressTime > 2000) {								
				player.speechOnOff();
			} else
			if(pressTime > 300) {
				if(paused) {
					paused = false;
					player.playPrevFile();
				} else {
					player.playNextFile();
				}
				
			} else  {
				if(player.isPlaying()) {
					paused = true;
					player.paused(true);						
				} else {
					paused = false;
					player.paused(false);
				}
			}
			
			RemoteControlReceiver.currentRunnable = null;
			
		}

		public void click() {
			clicks++;
			cancel++;
			handler.postDelayed(this, 500);
			Log.d(TAG, "CLICKS %d", clicks);
		}
	}
		
	public RemoteControlReceiver() {
		super();
		if(handler == null)
			handler = new Handler();
	}
	
	@Override
	public void onReceive(Context context, Intent intent) {
		Log.d(TAG, "##### GOT MEDIA INTENT %s", intent.getAction());
		
		PlayerInterface player = PlayerService.getPlayerInterface();
		
		if(player != null)
			Log.d(TAG, "PLAYER FOUND");
		else
			Log.d(TAG, "NO PLAYER FOUND");
		
		if(player == null) return;
		
		if(intent.getAction().equals(Intent.ACTION_MEDIA_BUTTON)) {
			Log.d(TAG, "MEDIA BUTTON");
			
			Bundle b = intent.getExtras();
			KeyEvent evt = (KeyEvent)b.get("android.intent.extra.KEY_EVENT");
			
			
			if(player.isActive()) {
				if(evt != null) {
					if(evt.getAction() == KeyEvent.ACTION_DOWN) {
						
						//downTime = evt.getDownTime();
						Log.d(TAG, "TIME %d %d", evt.getDownTime(), evt.getEventTime());
						
						//if(!actionHandled) {
						//	if(evt.getRepeatCount() > 2) {
						//		playNextSong();
						//		actionHandled = true;
						//	}
						//}
					} else if(evt.getAction() == KeyEvent.ACTION_UP) {
						
						int keycode = evt.getKeyCode();
				
						int pressTime = (int)(evt.getEventTime() - evt.getDownTime());
						
						
						Log.d(TAG, "PRESSTIME %d", pressTime);

						switch (keycode) {							 
		                case KeyEvent.KEYCODE_MEDIA_STOP:
		                	player.stop();
		        			//info[SONG_REPEAT] = defaultRepeatMode;
		        			//performCallback(SONG_REPEAT);
		                    break;
		                case KeyEvent.KEYCODE_MEDIA_NEXT:
		                	player.playNextSong();
		                    break;
		                case KeyEvent.KEYCODE_MEDIA_PREVIOUS:
		                	player.playPrevSong();
		                    break;
		                case KeyEvent.KEYCODE_MEDIA_PLAY_PAUSE:
		                	if(player.isPlaying()) {
								player.paused(true);						
							} else {
								player.paused(false);
							}
		                	break;
		                default:
		                case KeyEvent.KEYCODE_HEADSETHOOK:
		                			                	
		                	// Dont read headset button if call is in progress
		                	if(player.getCallState() != TelephonyManager.CALL_STATE_IDLE)
		                		return;
		                	
		                	if(currentRunnable != null) {
		                		currentRunnable.click();
		                	} else {
			                	currentRunnable = new MyRunnable(pressTime);
			                	handler.postDelayed(currentRunnable, 500);
		                	}
		                	
							//actionHandled = false;
							break;
			            }							
					}
				} else {
					
					if(player.isPlaying()) {
						player.paused(true);						
					} else {
						player.paused(false);
					}
				}
				
				//abortBroadcast();
			}
			
			
		}
	}

}
