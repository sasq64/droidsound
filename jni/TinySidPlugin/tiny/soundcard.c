#include <fcntl.h>
#include <sys/soundcard.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <stdio.h>

#include "defines.h"

//---------------------------------------SOUNDCARD-VARS--------------
#define DEVICE_NAME "/dev/dsp"
int BUF_SIZE=882*2;				// Audio Buffer size in byte
int audio_fd;					// Audio Device Handler
pthread_t soundcard_thread;			// Audio thread
int play_active=0;				// Audio thread active
word soundbuffer[882*16];			// The soundbuffer,
						// 16*50Hz WORD Buffer

//---------------------------------------SID-VARS--------------------
word play_addr;
byte play_speed;
//---------------------------------------SID-ENGINE-FUCTIONS
extern int cpuJSR(word npc, byte na);
extern void synth_render (word *buffer, dword len);

void stop_playing(void)
{
	if (play_active)
	{
		play_active=0;
		pthread_join(soundcard_thread, NULL);		
		// Reset Audio device
		ioctl(audio_fd, SNDCTL_DSP_RESET, 0);
		close(audio_fd);
	}
}

int is_little_endian(void)
{
        static const unsigned long a = 1;

        return *(const unsigned char *)&a;

}

void soundcard_init(void)
{
	int format, format_backup, stereo, speed;
		
	// If playing thread is active kill it
	stop_playing();	
	
	format_backup = format = is_little_endian()?AFMT_S16_LE:AFMT_S16_BE;
	stereo = 0;
	speed = 44100;
	
	if ((audio_fd = open(DEVICE_NAME, O_WRONLY)) == -1)
 	{ // Die Soundkarte ist nicht vorhanden oder besch�tigt
  		//dialog_box("SOUNDCARD FAILURE", ERROR_XPM, "AUDIO DEVICE IS BUSY.\n\nPlease make sure other applications do not use your soundcard.",OK_BUTTON);
  		perror(DEVICE_NAME);
    		return;
	}
  	if (ioctl(audio_fd, SNDCTL_DSP_SETFMT, &format)==-1)
  	{ /* Fatal error */
  		perror("SNDCTL_DSP_SETFMT");
  		//dialog_box("Device Error!", ERROR_XPM, "Your soundcard is not capable\nplaying the current audio-stream.\n\nIf your soundcard does not support\n16 bit samples try to convert your\ndata to 8 Bit.", OK_BUTTON);
   		close(audio_fd);
   		return;
    	}
    	if (format != format_backup)
    	{
		perror("FORMAT NOT SUPPORTED!");
		//dialog_box("Device Error!", ERROR_XPM, "Your soundcard is not capable\nplaying the current audio-stream.\n\nIf your soundcard does not support\n16 bit samples try to convert your\ndata to 8 Bit.", OK_BUTTON);
   		close(audio_fd);
   		return;
	}
        if (ioctl(audio_fd, SNDCTL_DSP_STEREO, &stereo)==-1)
        { /* Fatal error */
        	perror("SNDCTL_DSP_STEREO");
        	//dialog_box("Device Error!", ERROR_XPM, "Your soundcard is not capable\nplaying the current audio-stream.\n\nIf your soundcard does not support\nstereo samples try to convert your\ndata to mono output.", OK_BUTTON);
   		close(audio_fd);
   		return;
  	}
        if (stereo != 0)
        {
		perror("CHANNEL MODE NOT SUPPORTED!");
		//dialog_box("Device Error!", ERROR_XPM, "Your soundcard is not capable\nplaying the current audio-stream.\n\nIf your soundcard does not support\nstereo samples try to convert your\ndata to mono output.", OK_BUTTON);
   		close(audio_fd);
   		return;
        }
        if (ioctl(audio_fd, SNDCTL_DSP_SPEED, &speed)==-1)
        { /* Fatal error */
        	perror("SNDCTL_DSP_SPEED");
        	//dialog_box("Device Error!", ERROR_XPM, "Your soundcard is not capable\nplaying the current audio-stream.\n\nIf your soundcard does not support\nhigh samples-rates try to downsample your\ndata to lower bitrates.", OK_BUTTON);
   		close(audio_fd);
   		return;
        }
}

extern unsigned char memory[65536];
static void *play_thread_func(void *arg)
{
	int j;
	
	while (play_active)
	{		
                if (play_speed==0) // Single Speed (50Hz)
				   // Render 16*50Hz buffer
		{
			for (j=0;j<8;j++)
			{
				cpuJSR(play_addr, 0);
				synth_render(&soundbuffer[882*j], 882);
			}
		}
		
		if (play_speed==1) // Double Speed (100Hz)
				   // Render 16*50Hz buffer
			for (j=0;j<16;j++)
			{
				cpuJSR(play_addr, 0);
				synth_render(&soundbuffer[441*j], 441);
			}
		
			write(audio_fd, soundbuffer, BUF_SIZE*8);
	}
	return NULL;
}
void start_playing(word nplay_addr, byte nplay_speed)
{
	play_addr = nplay_addr;
	play_speed= nplay_speed;
	
	play_active = -1;
        pthread_create(&soundcard_thread, NULL, play_thread_func, NULL);
}
