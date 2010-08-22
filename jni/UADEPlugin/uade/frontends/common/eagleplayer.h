#ifndef _UADE_EAGLEPLAYER_H_
#define _UADE_EAGLEPLAYER_H_

#include <stdio.h>
#include <stdint.h>

#define EP_A500              (1 << 0)
#define EP_A1200             (1 << 1)
#define EP_ALWAYS_ENDS       (1 << 2)
#define EP_CONTENT_DETECTION (1 << 3)
#define EP_SPEED_HACK        (1 << 4)

#define ES_A500              (1 <<  0)
#define ES_A1200             (1 <<  1)
#define ES_BROKEN_SUBSONGS   (1 <<  2)
#define ES_LED_OFF           (1 <<  3)
#define ES_LED_ON            (1 <<  4)
#define ES_NO_HEADPHONES     (1 <<  5)
#define ES_NO_PANNING        (1 <<  6)
#define ES_NO_POSTPROCESSING (1 <<  7)
#define ES_NTSC              (1 <<  8)
#define ES_SPEED_HACK        (1 <<  9)
#define ES_VBLANK            (1 << 10)

struct eagleplayer {
  char *playername;
  size_t nextensions;
  char **extensions;
  int attributes;
};

struct eagleplayermap {
  char *extension;
  struct eagleplayer *player;
};

struct eagleplayerstore {
  size_t nplayers;
  struct eagleplayer *players;
  size_t nextensions;
  struct eagleplayermap *map;
};

struct eaglesong {
  int flags;
  int nsubsongs;
  uint8_t *subsongs;
  char md5[33];
};

int uade_add_playtime(const char *md5, uint32_t playtime, int replaceandsort);
struct eagleplayer *uade_analyze_file_format(const char *modulename,
					     const char *basedir, int verbose);
struct eaglesong *uade_analyze_song(const char *asciimd5);
int uade_file_md5(char *asciimd5, const char *filename, size_t len);
int uade_find_playtime(const char *md5);
struct eagleplayer *uade_get_eagleplayer(const char *extension, 
					 struct eagleplayerstore *playerstore);
int uade_read_content_db(const char *filename);
struct eagleplayerstore *uade_read_eagleplayer_conf(const char *filename);
int uade_read_song_conf(const char *filename);
void uade_save_content_db(const char *filename);

#endif
