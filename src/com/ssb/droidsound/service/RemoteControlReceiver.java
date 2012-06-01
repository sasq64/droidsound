package com.ssb.droidsound.service;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.telephony.TelephonyManager;
import android.view.KeyEvent;

import com.ssb.droidsound.utils.Log;

public class RemoteControlReceiver extends BroadcastReceiver {
	private static final String TAG = RemoteControlReceiver.class.getSimpleName();
		
	public RemoteControlReceiver() {
		super();
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

							if(pressTime > 2000) {								
								player.speechOnOff();
							} else
							if(pressTime > 300) {
								player.playNextSong();
							} else  {
								if(player.isPlaying()) {
									player.paused(true);						
								} else {
									player.paused(false);
								}
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
