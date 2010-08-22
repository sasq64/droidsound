#ifndef _UADE123_AUDIO_H_
#define _UADE123_AUDIO_H_

void audio_close(void);
int audio_init(void);
int audio_play(unsigned char *samples, int bytes);

#endif
