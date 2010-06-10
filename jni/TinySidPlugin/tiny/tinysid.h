#ifdef __cplusplus
	extern "C" {
#endif

// TinySID.h File
#include "defines.h"
// Externe Daten aus sidengine.c

extern void synth_render (word *buffer, dword len);
extern void c64Init(void);
extern word c64SidLoad(char *filename, word *init_addr, word *play_addr, byte *sub_song_start, byte *max_sub_songs, byte *speed, char *name, char *author, char *copyright);
unsigned short LoadSIDFromMemory(void *pSidData, unsigned short *load_addr, unsigned short *init_addr, unsigned short *play_addr, unsigned char *subsongs, unsigned char *startsong, unsigned char *speed, unsigned short size);

extern int cpuJSR(word npc, byte na);
extern void synth_init(unsigned long mixfrq);

// Externe Daten aus soundcard.c

extern void soundcard_init(void);
extern void start_playing(word nplay_addr, byte nplay_speed);
extern void stop_playing(void);

extern int gui_init(void);

#ifdef __cplusplus
	}
#endif
