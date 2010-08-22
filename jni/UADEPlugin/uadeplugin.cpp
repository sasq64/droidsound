/*  Copyright 2006 Jonas Minnberg

    This file is part of OldPlay - a portable, multiformat musicplayer.

    OldPlay is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    OldPlay is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with OldPlay; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include "../plugin.h"

extern "C" {
#include "eagleplayer.h"
#include "uadeipc.h"
#include "uadecontrol.h"
}

#include "SDL.h"
#include "SDL_thread.h"

//static SDL_mutex *mutex = NULL;

static struct eagleplayerstore *eaglestore;
struct eagleplayer *lastplayer = NULL;
char lastext[16] = "";
char current_format[80] = "";

#ifndef WIN32
#define stricmp strcasecmp
#define strnicmp strncasecmp
#endif

struct eagleplayer *get_player(const char *name)
{
	const char *sext = strrchr(name, '.');
	if(!sext)
		sext = "";
	else
		sext++;

	//fprintf(stderr, "extcheck %s \n", sext);

	if(lastplayer && stricmp(sext, lastext) == 0)
	{
		//fprintf(stderr, "=> %s\n", lastplayer->playername);	
		return lastplayer;
	}
	else
	{
		struct eagleplayer *plr = uade_get_eagleplayer(sext, eaglestore);
		if(plr)
		{
			lastplayer = plr;
			strcpy(lastext, sext);
			//fprintf(stderr, "=> %s\n", lastplayer->playername);	
		}
		return plr;
	}

}


int cprintf(char *fmt, ...);

//#if (defined _WIN32 || defined GP2X)
unsigned int htonl(unsigned int l)
{
	return ((l>>24) & 0xff) | ((l>>8) & 0xFF00) | ((l<<8) & 0xFF0000) | (l<<24);
}

unsigned int ntohl(unsigned int l)
{
	return ((l>>24) & 0xff) | ((l>>8) & 0xFF00) | ((l<<8) & 0xFF0000) | (l<<24);
}

 short ntohs(short l)
{
	return ((l>>8) & 0xff) | ((l<<8) & 0xFF00);
}

//#else
//#include <netinet/in.h>
//#endif

static struct sound_plugin plugin;

extern "C" {

#include "uadecontrol.h"
#include "uadeconf.h"

	
int uade_init();
void uade_go();
}

static struct uade_ipc uadeipc;


#define INSIZE 16384

unsigned char inbuffer[INSIZE];
unsigned char *add_ptr = inbuffer;

extern "C" {

void client_sleep()
{
	SDL_Delay(5);
}

int get_write_mutex(void **m)
{
	if(!*m)
		*m = SDL_CreateMutex();
	return (SDL_mutexP((SDL_mutex*)*m) == 0);

}

int release_write_mutex(void **m)
{
	return (SDL_mutexV((SDL_mutex*)*m) == 0);
}

int get_read_mutex(void **m)
{
	if(!*m)
		*m = SDL_CreateMutex();
	return (SDL_mutexP((SDL_mutex*)*m) == 0);
}

int release_read_mutex(void **m)
{
	return (SDL_mutexV((SDL_mutex*)*m) == 0);
}

} // extern "C"


int uade_thread(void *data)
{
	fprintf(stderr, "SERVER\n");
	uade_init();
	uade_go();
	return 0;
}


static bool inited = false;

static struct uade_config uadeconf;

static uint8_t space[UADE_MAX_MESSAGE_SIZE];
static struct uade_msg *um = (struct uade_msg *) space;
static int left = 0;
static int next_song = 0;
static int tailbytes = 0;
static int playbytes;

static int uade_song_end_trigger = 0;
static int subsong_end = 0;

enum uade_control_state state = UADE_S_STATE;

static short soundbuffer[32768];
static short *soundptr = soundbuffer;

void dbprintf(const char *fmt, ...)
{
	//va_list vl;
	//va_start(vl, fmt);
	//vfprintf(stderr, fmt, vl);
	//va_end(vl);
}

int new_subsong = -1;

static int run_client()
{
	if(state == UADE_S_STATE)
	{
		if(uade_song_end_trigger)
			return -1;
		/*if(uade_song_end_trigger)
		{
			next_song = 1;
			if(uade_send_short_message(UADE_COMMAND_REBOOT, &uadeipc))
			{
				fprintf(stderr, "\nCan not send reboot\n");
				return 0;
			}
		}
		else */

		if(new_subsong >= 0)
		{
			uade_change_subsong(new_subsong, &uadeipc);
			new_subsong = -1;
		}
		
		left = uade_read_request(&uadeipc); /* Request another batch of sample data from uadecore */

		if(uade_send_short_message(UADE_COMMAND_TOKEN, &uadeipc))
		{
			fprintf(stderr, "\nCan not send token\n");
			return 0;
		}
		state = UADE_R_STATE;
	}

	/* receive state */
	if(state == UADE_R_STATE)
	{	
		uint16_t *sm;

		if (uade_receive_message(um, sizeof(space), &uadeipc) <= 0)
		{
			fprintf(stderr, "\nCan not receive events from uade\n");
			return 0;
		}

		switch (um->msgtype)
		{
		case UADE_COMMAND_TOKEN:
			state = UADE_S_STATE;
			break;

		case UADE_REPLY_DATA:
			sm = (uint16_t *)um->data;

			if(subsong_end)
			{
				playbytes = tailbytes; /* Determined by UADE_REPLY_SONG_END */
				tailbytes = 0;
			}
			else
				playbytes = um->size;


			if(plugin.freq == 44100)
			{
				for (int i = 0; i < um->size/2; i++)
					soundptr[i] = ntohs(sm[i]);

				soundptr += (playbytes/2);
			}
			else
			if(plugin.freq == 22050)
			{
				for (int i = 0; i < um->size/2; i+=4)
				{
					soundptr[i/2] = (ntohs(sm[i]) + ntohs(sm[i+2])) / 2;
					soundptr[i/2+1] = (ntohs(sm[i+1]) + ntohs(sm[i+3])) / 2;
				}

				soundptr += (playbytes/4);
			}
			
			dbprintf("Got %d bytes sampledata\n", playbytes);
			

//			time_bytes += playbytes;
			assert(left >= um->size);
			left -= um->size;
			break;

		case UADE_REPLY_FORMATNAME:
			uade_check_fix_string(um, 128);
			fprintf(stderr, "\nFormat name: %s\n", (char*) um->data);
			strcpy(current_format, (char *)um->data);
			break; 

		case UADE_REPLY_MODULENAME:
			uade_check_fix_string(um, 128);
			fprintf(stderr, "\nModule name: %s\n", (char*) um->data);
			break; 

		case UADE_REPLY_MSG:
			uade_check_fix_string(um, 128);
			fprintf(stderr, "\nMessage: %s\n", (char *) um->data);
			break;

		case UADE_REPLY_PLAYERNAME:
			uade_check_fix_string(um, 128);
			fprintf(stderr, "Player name: %s\n", (char*) um->data);
			strcpy(current_format, (char *)um->data);
			break; 

		case UADE_REPLY_SONG_END:
			if (um->size < 9)
			{
				fprintf(stderr, "\nInvalid song end reply\n");
				exit(-1);
			}
			tailbytes = ntohl(((uint32_t *) um->data)[0]);
			uade_song_end_trigger = 1;
			fprintf(stderr, "\nSong end\n");
			break;

		case UADE_REPLY_SUBSONG_INFO:
			if(um->size != 12)
			{
				fprintf(stderr, "\nsubsong info: too short a message\n");
			}
			{
				unsigned int *u32ptr = (unsigned int *)um->data;
				int min_sub = ntohl(u32ptr[0]);
				int max_sub = ntohl(u32ptr[1]);
				int cur_sub = ntohl(u32ptr[2]);
				plugin.subtunes = max_sub;
				plugin.tune = cur_sub;
				fprintf(stderr, "\nsubsong: %d from range [%d, %d]\n", cur_sub, min_sub, max_sub);
			}
			break;
		case UADE_REPLY_CANT_PLAY:
		case UADE_REPLY_CAN_PLAY:


		default:
			fprintf(stderr, "\nExpected sound data. got %d.\n", um->msgtype);
			return 0;
		}
	}

}

 

static int fill_buffer(signed short *dest, int len)
{
	if(run_client() < 0)
		return 0;

	int filled = (soundptr - soundbuffer)*2;

	while(filled < len)
	{
		//dbprintf("%d vs %d\n", filled, len);
		if(run_client() < 0)
			return 0;
		filled = (soundptr - soundbuffer)*2;
	}

	{
		//dbprintf("Playing %d of %d bytes\n", len, filled);
		memcpy(dest, soundbuffer, len);
		memmove(soundbuffer, soundbuffer+(len/2), filled-len);
		soundptr -= (len/2);
	}
	/*else
	{
		fprintf(stderr, "*************BAD\n", len, filled);
		memset(dest, 0, len);
	}*/
	return len;
}



static int init_file(char *filename)
{
	plugin.name = (char *)filename;

	struct eagleplayer *player = get_player(filename);
	fprintf(stderr, "PLAYING %s\n", player->playername);	
	char tmp[128];
	sprintf(tmp, "players/%s", player->playername);

	int rc;

	char tmp2[128];
	char *src = filename;
	char *dst = tmp2;
	/*if(src[1] == ':')
	{
		*dst++ = '/';
		*dst++ = src[0];
		src += 2;
	}*/
	while(*src)
	{
		if(*src == '\\')
			*dst++ = '/';
		else
			*dst++ = *src;
		src++;
	}
	*dst = 0;

	fprintf(stderr, "%s => %s\n", filename, tmp2);

	strcpy(current_format, "");

	plugin.subtunes = 1;
	plugin.tune = 0;


	if(strcmp("custom", player->playername) == 0)
	{
		rc = uade_song_initialization("score" , tmp2, "", &uadeipc);
		strcpy(current_format, "Amiga Custom");

	}
	else
		rc = uade_song_initialization("score" , tmp, tmp2, &uadeipc);

	plugin.name = "";
	plugin.artist = "";
	plugin.copyright = "";
	plugin.length = -1;
	plugin.format = current_format;

	uade_song_end_trigger = 0;

	if(rc)
		return rc;


	uade_config_set_defaults(&uadeconf);

#ifndef _WIN32
	uadeconf.filter_type = 0;
#endif

    uade_send_filter_command(uadeconf.filter_type, uadeconf.led_state, uadeconf.led_forced, &uadeipc);
    uade_send_interpolation_command(uadeconf.interpolator, &uadeipc);

	//uade_send_short_message(UADE_COMMAND_ACTIVATE_DEBUGGER, &uadeipc);


	run_client();

	dbprintf("%d\n", rc);

  //    if (rc == UADECORE_INIT_ERROR)
    //  } else if (ret == UADECORE_CANT_PLAY) {

	//cprintf("%p %p %p %d %02x %02x\n", mpfile, plugin.name, data, size, d[0], d[1]);

	return 0;
}


static int wait_token()
{
	do
	{
		int ret = uade_receive_message(um, sizeof(space), &uadeipc);
		if(ret < 0)
		{
			fprintf(stderr, "\nCan not receive events (TOKEN) from uade.\n");
			return 0;
		}
		if (ret == 0)
		{
			fprintf(stderr, "\nEnd of input after reboot.\n");
			return 0;
		}
	} while (um->msgtype != UADE_COMMAND_TOKEN);
	return 1;
}


static int close()
{
	cprintf("close1\n");
	if(state == UADE_R_STATE)
		wait_token();

	fprintf(stderr, "close2\n");
	if(uade_send_short_message(UADE_COMMAND_REBOOT, &uadeipc))
	{
		fprintf(stderr, "\nCan not send reboot\n");
		return 0;
	}
	fprintf(stderr, "close3\n");
    if (uade_send_short_message(UADE_COMMAND_TOKEN, &uadeipc))
	{
		fprintf(stderr, "\nCan not send token\n");
		return 0;
	}
 	fprintf(stderr, "close4\n");

	wait_token();
	cprintf("close5\n");

	state = UADE_S_STATE;

	return 0;
}


static int is_ext(const char *s, const char *ext)
{
	const char *sext = strrchr(s, '.');
	if(!sext)
		sext = "";
	else
		sext++;
	if(stricmp(ext, sext) == 0)
		return 1;
	if(strnicmp(s, ext, strlen(ext)) == 0)
		return 1;

	return 0;
}

int set_position(int seconds, int subtune)
{
	new_subsong = subtune;
}

static int can_handle(const char *name)
{
	return (get_player(name) != NULL);
	//return is_ext(name, "cust");// || is_ext(name, ".xm") || is_ext(name, ".s3m") || is_ext(name, ".ft") || is_ext(name, ".okt"));
}

extern "C" {

#ifndef INIT_SOUND_PLUGIN
#define INIT_SOUND_PLUGIN uade_init_sound_plugin
#endif

struct sound_plugin *INIT_SOUND_PLUGIN()
{

	eaglestore = uade_read_eagleplayer_conf("eagleplayer.conf");

	if(!eaglestore)
		return NULL;

	fprintf(stderr, "%d eagleplayer extentions\n", eaglestore->nextensions);

	fprintf(stderr, "CLIENT\n");
	uade_set_peer(&uadeipc, 1, "client", "server");
	inited = true;

	SDL_Thread *thread = SDL_CreateThread(uade_thread, NULL);


	if (uade_send_string(UADE_COMMAND_CONFIG, "uaerc", &uadeipc)) {
		fprintf(stderr, "Can not send config name\n");
		SDL_KillThread(thread);
		inited = false;
	    return NULL;
	} 

	memset(&plugin, 0, sizeof(plugin));

	plugin.plugname = "uade";

	plugin.freq = 22050;
	plugin.channels = 2;
	plugin.init_file = init_file;
	//plugin.init_data = init_data;
	plugin.fill_buffer = fill_buffer;
	plugin.can_handle = can_handle;
	plugin.close = close;
	plugin.set_position = set_position;

	plugin.clockfreq = 250;

	return &plugin;
}

}  // extern "C"
