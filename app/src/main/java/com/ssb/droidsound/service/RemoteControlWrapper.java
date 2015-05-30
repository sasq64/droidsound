package com.ssb.droidsound.service;

import android.annotation.TargetApi;
import android.app.PendingIntent;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.media.AudioManager;
import android.media.MediaMetadataRetriever;
import android.media.RemoteControlClient;
import android.media.RemoteControlClient.MetadataEditor;

@TargetApi(14)
public class RemoteControlWrapper {

	
	public static final int PLAYING = 0;
	public static final int STOPPED = 1;
	public static final int PAUSED = 2;
	
	private RemoteControlClient myRemoteControlClient;
	
	static {
		try {
			Class.forName("android.media.RemoteControlClient");
		} catch (Exception ex) {
			throw new RuntimeException(ex);
		}
	}
	 
	public static void checkAvailable() {}

	public RemoteControlWrapper(Context ctx, ComponentName myEventReceiver) {
		

		Intent mediaButtonIntent = new Intent(Intent.ACTION_MEDIA_BUTTON);
		mediaButtonIntent.setComponent(myEventReceiver);
		PendingIntent mediaPendingIntent = PendingIntent.getBroadcast(ctx.getApplicationContext(), 0, mediaButtonIntent, 0);
		
		 myRemoteControlClient = new RemoteControlClient(mediaPendingIntent);
		 
		 AudioManager myAudioManager = (AudioManager) ctx.getSystemService(Context.AUDIO_SERVICE);
		 
		 myAudioManager.registerRemoteControlClient(myRemoteControlClient);
		 myRemoteControlClient.setTransportControlFlags( 
				     RemoteControlClient.FLAG_KEY_MEDIA_PLAY_PAUSE | 
				     RemoteControlClient.FLAG_KEY_MEDIA_NEXT | 
				     RemoteControlClient.FLAG_KEY_MEDIA_PREVIOUS /*| 
				     RemoteControlClient.FLAG_KEY_MEDIA_FAST_FORWARD | 
				     RemoteControlClient.FLAG_KEY_MEDIA_REWIND */); 

	}

	public void setMetaData(String author, String title) {
		
		MetadataEditor editor = myRemoteControlClient.editMetadata(true);
		//editor.String(MediaMetadataRetriever.METADATA_KEY_HAS_AUDIO, "true");
		if(author != null) {
			editor.putString(MediaMetadataRetriever.METADATA_KEY_ARTIST,  author);
			editor.putString(MediaMetadataRetriever.METADATA_KEY_ALBUMARTIST,  author);
		}
		editor.putString(MediaMetadataRetriever.METADATA_KEY_COMPOSER,  (String) "composer");
		if(title != null)
			editor.putString(MediaMetadataRetriever.METADATA_KEY_TITLE, (String) title);
		else
			editor.putString(MediaMetadataRetriever.METADATA_KEY_TITLE, "UNKNOWN");
		editor.apply();
		myRemoteControlClient.setPlaybackState(RemoteControlClient.PLAYSTATE_PLAYING);
	}

	public void setState(int state) {
		int s = -1;
		switch(state) {
		case PLAYING:
			s = RemoteControlClient.PLAYSTATE_PLAYING;
			break;
		case PAUSED:
			s = RemoteControlClient.PLAYSTATE_PAUSED;
			break;
		case STOPPED:
			s = RemoteControlClient.PLAYSTATE_STOPPED;
			break;
		}
		if(s >= 0)
			myRemoteControlClient.setPlaybackState(s);
			
		
	}
	
}
