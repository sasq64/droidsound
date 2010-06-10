#include <stdio.h>
#include <stdlib.h>

#include "tinysid.h"

//---------------------------------------SID-VARS--------------------
static word init_addr, play_addr;
static byte actual_subsong, max_subsong, play_speed;
char song_name[32], song_author[32], song_copyright[32];

void show_info(int argc)
{
	printf("TinySID v0.94 linux version\n");
	printf("(c)Copyright 1999-2006 T. Hinrichs and R. Sinsch.\n");
	printf("All rights reserved.\n\n");
	if (argc < 2)
	{
		printf("Usage: tinysid [sid-file]\n");
		exit(0);
	}	
}
int main(int argc, char *argv[])
{
	show_info(argc);
	c64Init();
	synth_init(44100);
	soundcard_init();
	printf("Loading %s...", argv[1]);
	if (c64SidLoad(argv[1], &init_addr, &play_addr, &actual_subsong, &max_subsong, &play_speed, song_name, song_author, song_copyright) == 0)
	{
		printf("failed!.\n\n"); exit(0);
	} else printf("OK.\n");
	printf("TITLE    : %s\n", song_name);
	printf("AUTHOR   : %s\n", song_author);
	printf("COPYRIGHT: %s\n\n", song_copyright);
	
	cpuJSR(init_addr, actual_subsong);
	printf("Playing... Hit return quit.\n");
	start_playing(play_addr, play_speed);
	getchar();
	stop_playing();
	return(0);
}
