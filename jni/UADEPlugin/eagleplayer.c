/* UADE
 *
 * Copyright 2005 Heikki Orsila <heikki.orsila@iki.fi>
 *
 * Loads contents of 'eagleplayer.conf' and 'song.conf'. The file formats are
 * specified in doc/eagleplayer.conf and doc/song.conf.
 *
 * This source code module is dual licensed under GPL and Public Domain.
 * Hence you may use _this_ module (not another code module) in any you
 * want in your projects.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdint.h>

#include <errno.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <strlrep.h>

#include <eagleplayer.h>
#include <amifilemagic.h>
#include <md5.h>


#define LINESIZE (1024)
#define WS_DELIMITERS " \t\n"
#define OPTION_DELIMITER ","

#ifdef _WIN32

char *strsep(char **stringp, const char *delim)
{
	if(!*stringp)
		return NULL;

	int n = strlen(delim);
	int i;
	char *p = *stringp;
	char *org = p;
	int lastfound = 0;
	int found = 0;

	while(*p)
	{
		found = 0;
		for(i=0;i<n;i++)
		{
			if(delim[i] == *p)
			{
				found = 1;
				if(!lastfound)
					*p = 0;
				break;
			}
		}

		if(lastfound && !found)
		{
			*stringp = p;
			return org;
		}

		lastfound = found;
		p++;
	}
	*stringp = NULL;
	return org;
}

#endif

#define eperror(fmt, args...) do { fprintf(stderr, "Eagleplayer.conf error on line %zd: " fmt "\n", lineno, ## args); exit(-1); } while (0)


struct contentchecksum {
  uint32_t playtime; /* in milliseconds */
  char md5[33];
};


static struct contentchecksum *contentchecksums;
static size_t nccalloc;
static size_t nccused;
static int ccmodified;

static uint8_t fileformat_buf[8192];
static struct eagleplayerstore *playerstore;

static int nsongs;
static struct eaglesong *songstore;


static int ufcompare(const void *a, const void *b);


/* Compare function for bsearch() and qsort() to sort songs with respect
   to their md5sums */
static int escompare(const void *a, const void *b)
{
  return strcasecmp(((struct eaglesong *) a)->md5, ((struct eaglesong *) b)->md5);
}


static int contentcompare(const void *a, const void *b)
{
  return strcasecmp(((struct contentchecksum *) a)->md5, ((struct contentchecksum *) b)->md5);
}


/* replace must be zero if content db is unsorted */
int uade_add_playtime(const char *md5, uint32_t playtime, int replaceandsort)
{
  if (contentchecksums == NULL)
    return 0;
  /* Do not record song shorter than 5 secs */
  if (playtime < 5000)
    return 1;
  if (strlen(md5) != 32)
    return 0;

  if (replaceandsort) {
    struct contentchecksum key;
    struct contentchecksum *n;
    strlcpy(key.md5, md5, sizeof key.md5);
    n = bsearch(&key, contentchecksums, nccused, sizeof contentchecksums[0], contentcompare);
    if (n != NULL) {
      strlcpy(n->md5, md5, sizeof(n->md5));
      if (n->playtime != playtime)
	ccmodified = 1;
      n->playtime = playtime;
      return 1;
    }
  }
  if (nccused == nccalloc) {
    struct contentchecksum *n;
    nccalloc *= 2;
    n = realloc(contentchecksums, nccalloc * sizeof(struct contentchecksum));
    if (n == NULL) {
      fprintf(stderr, "uade: No memory for new md5s.\n");
      return 0;
    }
    contentchecksums = n;
  }
  strlcpy(contentchecksums[nccused].md5, md5, sizeof(contentchecksums[nccused].md5));
  contentchecksums[nccused].playtime = playtime;
  nccused++;
  ccmodified = 1;
  if (replaceandsort)
    qsort(contentchecksums, nccused, sizeof contentchecksums[0], contentcompare);
  return 1;
}


struct eagleplayer *uade_analyze_file_format(const char *modulename,
					     const char *basedir, int verbose)
{
  struct stat st;
  char extension[11];

  FILE *f;
  size_t readed;
  struct eagleplayer *candidate;
  char *t, *tn;
  int len;
  static int warnings = 1;
  size_t bufsize;

  if ((f = fopen(modulename, "rb")) == NULL) {
    fprintf(stderr, "Can not open module: %s\n", modulename);
    return NULL;
  }
  if (fstat(fileno(f), &st)) {
    fprintf(stderr, "Very weird stat error: %s (%s)\n", modulename, strerror(errno));
    exit(-1);
  }
  bufsize = sizeof fileformat_buf;
  readed = fread(fileformat_buf, 1, bufsize, f);
  fclose(f);
  if (readed == 0)
    return NULL;
  memset(&fileformat_buf[readed], 0, bufsize - readed);
  bufsize = readed;
  uade_filemagic(fileformat_buf, bufsize, extension, st.st_size);

  if (verbose == 2)
    fprintf(stderr, "%s: deduced extension: %s\n", modulename, extension);

  if (strcmp(extension, "packed") == 0)
    return NULL;

  if (playerstore == NULL) {
    char formatsfile[PATH_MAX];
    snprintf(formatsfile, sizeof(formatsfile), "%s/eagleplayer.conf", basedir);
    if ((playerstore = uade_read_eagleplayer_conf(formatsfile)) == NULL) {
      if (warnings)
	fprintf(stderr, "Tried to load uadeformats file from %s, but failed\n", formatsfile);
      warnings = 0;
      return NULL;
    }
  }

  /* if filemagic found a match, we'll use player plugins associated with
     that extension. if filemagic didn't find a match, we'll try to parse
     pre- and postfixes from the modulename */

  if (extension[0]) {
    candidate = uade_get_eagleplayer(extension, playerstore);
    if (candidate)
      return candidate;
    if (verbose >= 1)
      fprintf(stderr, "Deduced file extension (%s) is not on the uadeformats list.\n", extension);
  }

  /* magic wasn't able to deduce the format, so we'll try prefix and postfix
     from modulename */
  t = strrchr(modulename, (int) '/');
  if (t == NULL) {
    t = (char *) modulename;
  } else {
    t++;
  }

  /* try prefix first */
  tn = strchr(t, '.');
  if (tn == NULL) {
    if (verbose >= 1)
      fprintf(stderr, "Unknown format: %s\n", modulename);
    return NULL;
  }
  len = ((intptr_t) tn) - ((intptr_t) t);
  if (len < sizeof(extension)) {
    memcpy(extension, t, len);
    extension[len] = 0;
    candidate = uade_get_eagleplayer(extension, playerstore);
    if (candidate && (candidate->attributes & EP_CONTENT_DETECTION) == 0)
      return candidate;
  }

  /* prefix didn't match anything. trying postfix */
  t = strrchr(t, '.');
  if (strlcpy(extension, t + 1, sizeof(extension)) >= sizeof(extension)) {
    /* too long to be an extension */
    if (verbose >= 1)
      fprintf(stderr, "Unknown format: %s\n", modulename);
    return NULL;
  }

  candidate = uade_get_eagleplayer(extension, playerstore);
  if (candidate && (candidate->attributes & EP_CONTENT_DETECTION) == 0)
    return candidate;

  return NULL;
}


struct eaglesong *uade_analyze_song(const char *asciimd5)
{
  struct eaglesong key;
  if (strlcpy(key.md5, asciimd5, sizeof key.md5) != ((sizeof key.md5) - 1)) {
    fprintf(stderr, "Invalid md5sum: %s\n", asciimd5);
    exit(-1);
  }
  return bsearch(&key, songstore, nsongs, sizeof songstore[0], escompare);
}


int uade_file_md5(char *asciimd5, const char *filename, size_t len)
{
  uint8_t buf[4096];
  FILE *f;
  size_t s;
  MD5_CTX ctx;
  uint8_t md5[16];

  if (len < 33)
    return 0;
  if ((f = fopen(filename, "rb")) == NULL)
    return 0;

  MD5Init(&ctx);

  while (1) {
    s = fread(buf, 1, sizeof buf, f);
    if (s == 0)
      break;
    MD5Update(&ctx, buf, s);
  }
  MD5Final(md5, &ctx);
  snprintf(asciimd5, len, "%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x\n",md5[0],md5[1],md5[2],md5[3],md5[4],md5[5],md5[6],md5[7],md5[8],md5[9],md5[10],md5[11],md5[12],md5[13],md5[14],md5[15]);
  return 1;
}


int uade_find_playtime(const char *md5)
{
  struct contentchecksum key;
  struct contentchecksum *n;
  int playtime = 0;
  if (nccused == 0)
    return 0;
  strlcpy(key.md5, md5, sizeof key.md5);
  n = bsearch(&key, contentchecksums, nccused, sizeof contentchecksums[0], contentcompare);
  if (n != NULL)
    playtime = n->playtime;
  if (playtime < 0)
    playtime = 0;
  return playtime;
}


struct eagleplayer *uade_get_eagleplayer(const char *extension, struct eagleplayerstore *ps)
{
  struct eagleplayermap *uf = ps->map;
  struct eagleplayermap *f;
  struct eagleplayermap key = {.extension = (char *) extension};

  f = bsearch(&key, uf, ps->nextensions, sizeof(uf[0]), ufcompare);
  if (f == NULL)
    return NULL;

  return f->player;
}


/* Split line with respect to white space. */
static char **split_line(size_t *nitems, size_t *lineno, FILE *f,
			 const char *delimiters)
{
  char line[LINESIZE], templine[LINESIZE];
  char **items = NULL;
  size_t pos;
  char *sp, *s;

  *nitems = 0;

  while (fgets(line, sizeof line, f) != NULL) {

    if (lineno != NULL)
      (*lineno)++;

    /* Skip, if a comment line */
    if (line[0] == '#')
      continue;

    /* strsep() modifies line that it touches, so we make a copy of it, and
       then count the number of items on the line */
    strlcpy(templine, line, sizeof(templine));
    sp = templine;
    while ((s = strsep(&sp, delimiters)) != NULL) {
      if (*s == 0)
	continue;
      (*nitems)++;
    }

    if (*nitems > 0)
      break;
  }

  if (*nitems == 0)
    return NULL;

  if ((items = malloc(sizeof(items[0]) * (*nitems + 1))) == NULL) {
    fprintf(stderr, "No memory for nws items.\n");
    exit(-1);
  }

  sp = line;
  pos = 0;
  while ((s = strsep(&sp, delimiters)) != NULL) {
    if (*s == 0)
      continue;
    if ((items[pos] = strdup(s)) == NULL) {
      fprintf(stderr, "No memory for an nws item.\n");
      exit(-1);
    }
    pos++;
  }
  items[pos] = NULL;
  assert(pos == *nitems);

  return items;
}


int uade_read_content_db(const char *filename)
{
  char line[256];
  FILE *f;
  nccused = 0;
  if (nccalloc == 0) {
    nccalloc = 16;
    contentchecksums = malloc(nccalloc * sizeof(struct contentchecksum));
    if (contentchecksums == NULL) {
      fprintf(stderr, "uade: No memory for content checksums\n");
      return 0;
    }
  }
  if ((f = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "uade: Can not find %s\n", filename);
    return 0;
  }

  while (fgets(line, sizeof line, f)) {
    long playtime;
    int i;
    char *eptr;
    if (line[0] == '#')
      continue;
    for (i = 0; i < 32; i++) {
      if (line[i] == 0 || !isxdigit(line[i]))
	break;
    }
    if (i != 32)
      continue;
    if (line[32] != ' ')
      continue;
    line[32] = 0;
    if (line[33] == '\n' || line[33] == 0)
      continue;
    playtime = strtol(&line[33], &eptr, 10);
    if (*eptr == '\n' || *eptr == 0) {
      if (playtime > 0)
	uade_add_playtime(line, playtime, 0);
    }
  }
  fclose(f);
  qsort(contentchecksums, nccused, sizeof contentchecksums[0], contentcompare);
  ccmodified = 0;

  /* fprintf(stderr, "uade: Read content database with %zd entries\n", nccused); */
  return 1;
}


/* Read eagleplayer.conf. */
struct eagleplayerstore *uade_read_eagleplayer_conf(const char *filename)
{
  FILE *f;
  struct eagleplayer *p;
  size_t allocated;
  size_t lineno = 0;
  struct eagleplayerstore *ps = NULL;
  size_t exti;
  size_t i;

  f = fopen(filename, "r");
  if (f == NULL)
    goto error;

  ps = calloc(1, sizeof ps[0]);
  if (ps == NULL)
    eperror("No memory for ps.");

  allocated = 16;
  if ((ps->players = malloc(allocated * sizeof(ps->players[0]))) == NULL)
    eperror("No memory for eagleplayer.conf file.\n");

  while (1) {

    char **items;
    size_t nitems;

    if ((items = split_line(&nitems, &lineno, f, WS_DELIMITERS)) == NULL)
      break;

    assert(nitems > 0);

    if (ps->nplayers == allocated) {
      allocated *= 2;
      ps->players = realloc(ps->players, allocated * sizeof(ps->players[0]));
      if (ps->players == NULL)
	eperror("No memory for players.");
    }

    p = &ps->players[ps->nplayers];
    ps->nplayers++;

    memset(p, 0, sizeof p[0]);

    p->playername = strdup(items[0]);
    if (p->playername == NULL) {
      fprintf(stderr, "No memory for playername.\n");
      exit(-1);
    }

    for (i = 1; i < nitems; i++) {
      if (strncasecmp(items[i], "prefixes=", 9) == 0) {
	char prefixes[LINESIZE];
	char *prefixstart = items[i] + 9;
	char *sp, *s;
	size_t pos;

	assert(p->nextensions == 0 && p->extensions == NULL);
	
	p->nextensions = 0;
	strlcpy(prefixes, prefixstart, sizeof(prefixes));
	sp = prefixes;
	while ((s = strsep(&sp, OPTION_DELIMITER)) != NULL) {
	  if (*s == 0)
	    continue;
	  p->nextensions++;
	}

	p->extensions = malloc((p->nextensions + 1) * sizeof(p->extensions[0]));
	if (p->extensions == NULL)
	  eperror("No memory for extensions.");

	pos = 0;
	sp = prefixstart;
	while ((s = strsep(&sp, OPTION_DELIMITER)) != NULL) {
	  if (*s == 0)
	    continue;
	  if ((p->extensions[pos] = strdup(s)) == NULL)
	    eperror("No memory for prefix.");
	  pos++;
	}
	p->extensions[pos] = NULL;
	assert(pos == p->nextensions);

      } else if (strcasecmp(items[i], "a500") == 0) {
	p->attributes |= EP_A500;
      } else if (strcasecmp(items[i], "a1200") == 0) {
	p->attributes |= EP_A1200;
      } else if (strcasecmp(items[i], "always_ends") == 0) {
	p->attributes |= EP_ALWAYS_ENDS;
      } else if (strcasecmp(items[i], "content_detection") == 0) {
	p->attributes |= EP_CONTENT_DETECTION;
      } else if (strcasecmp(items[i], "speed_hack") == 0) {
	p->attributes |= EP_SPEED_HACK;
      } else if (strncasecmp(items[i], "comment:", 8) == 0) {
	break;
      } else {
	fprintf(stderr, "Unrecognized option: %s\n", items[i]);
      }
    }

    free(items);
  }

  fclose(f);

  if (ps->nplayers == 0) {
    free(ps->players);
    free(ps);
    return NULL;
  }

  for (i = 0; i < ps->nplayers; i++)
    ps->nextensions += ps->players[i].nextensions;

  ps->map = malloc(sizeof(ps->map[0]) * ps->nextensions);
  if (ps->map == NULL)
    eperror("No memory for extension map.");

  exti = 0;
  for (i = 0; i < ps->nplayers; i++) {
    size_t j;
    if (exti >= ps->nextensions) {
      fprintf(stderr, "pname %s\n", ps->players[i].playername);
      fflush(stderr);
    }
    assert(exti < ps->nextensions);
    p = &ps->players[i];
    for (j = 0; j < p->nextensions; j++) {
      ps->map[exti].player = p;
      ps->map[exti].extension = p->extensions[j];
      exti++;
    }
  }

  assert(exti == ps->nextensions);

  qsort(ps->map, ps->nextensions, sizeof(ps->map[0]), ufcompare);

  return ps;

 error:
  if (ps)
    free(ps->players);
  free(ps);
  if (f != NULL)
    fclose(f);
  return NULL;
}


int uade_read_song_conf(const char *filename)
{
  FILE *f;
  struct eaglesong *s;
  size_t allocated;
  size_t lineno = 0;
  size_t i;

  if ((f = fopen(filename, "r")) == NULL)
    return 0;

  nsongs = 0;
  allocated = 16;
  songstore = calloc(allocated, sizeof songstore[0]);
  if (songstore == NULL)
    eperror("No memory for song store.");

  while (1) {
    char **items;
    size_t nitems;

    if ((items = split_line(&nitems, &lineno, f, WS_DELIMITERS)) == NULL)
      break;

    assert(nitems > 0);

    if (nsongs == allocated) {
      allocated *= 2;
      songstore = realloc(songstore, allocated * sizeof(songstore[0]));
      if (songstore == NULL)
	eperror("No memory for players.");
    }

    s = &songstore[nsongs];
    nsongs++;

    memset(s, 0, sizeof s[0]);

    if (strncasecmp(items[0], "md5=", 4) != 0) {
      fprintf(stderr, "Line %zd must begin with md5= in %s\n", lineno, filename);
      free(items);
      continue;
    }
    if (strlcpy(s->md5, items[0] + 4, sizeof s->md5) != ((sizeof s->md5) - 1)) {
      fprintf(stderr, "Line %zd in %s has too long an md5sum.\n", lineno, filename);
      free(items);
      continue;
    }

    for (i = 1; i < nitems; i++) {
      if (strcasecmp(items[i], "\\a500") == 0) {
	s->flags |= ES_A500;
      } else if (strcasecmp(items[i], "\\a1200") == 0) {
	s->flags |= ES_A1200;
      } else if (strcasecmp(items[i], "\\broken_subsongs") == 0) {
	s->flags |= ES_BROKEN_SUBSONGS;
      } else if (strcasecmp(items[i], "\\led_off") == 0) {
	s->flags |= ES_LED_OFF;
      } else if (strcasecmp(items[i], "\\led_on") == 0) {
	s->flags |= ES_LED_ON;
      } else if (strcasecmp(items[i], "\\no_headphones") == 0) {
	s->flags |= ES_NO_HEADPHONES;
      } else if (strcasecmp(items[i], "\\no_panning") == 0) {
	s->flags |= ES_NO_PANNING;
      } else if (strcasecmp(items[i], "\\no_postprocessing") == 0) {
	s->flags |= ES_NO_POSTPROCESSING;
      } else if (strcasecmp(items[i], "\\ntsc") == 0) {
	s->flags |= ES_NTSC;
      } else if (strncasecmp(items[i], "\\subsongs=", 10) == 0) {
	char subsongs[LINESIZE];
	char *subsongstart = items[i] + 10;
	char *sp, *str;
	size_t pos;

	s->nsubsongs = 0;
	strlcpy(subsongs, subsongstart, sizeof subsongs);
	sp = subsongs;
	while ((str = strsep(&sp, OPTION_DELIMITER)) != NULL) {
	  if (*str == 0)
	    continue;
	  s->nsubsongs++;
	}

	s->subsongs = malloc((s->nsubsongs + 1) * sizeof(s->subsongs[0]));
	if (s->subsongs == NULL)
	  eperror("No memory for subsongs.");

	pos = 0;
	sp = subsongstart;
	while ((str = strsep(&sp, OPTION_DELIMITER)) != NULL) {
	  if (*str == 0)
	    continue;
	  s->subsongs[pos] = atoi(str);
	  pos++;
	}
	s->subsongs[pos] = -1;
	assert(pos == s->nsubsongs);
      } else if (strcasecmp(items[i], "\\speedhack") == 0) {
	s->flags |= ES_SPEED_HACK;
      } else if (strcasecmp(items[i], "\\vblank") == 0) {
	s->flags |= ES_VBLANK;
      }
    }

    free(items);
  }

  fclose(f);

  /* Sort MD5 sums for binary searching songs */
  qsort(songstore, nsongs, sizeof songstore[0], escompare);
  return 1;
}


void uade_save_content_db(const char *filename)
{
  FILE *f;
  size_t i;
  if (ccmodified == 0)
    return;
  if ((f = fopen(filename, "w")) == NULL) {
    fprintf(stderr, "uade: Can not write content db: %s\n", filename);
    return;
  }
  for (i = 0; i < nccused; i++)
    fprintf(f, "%s %d\n", contentchecksums[i].md5, contentchecksums[i].playtime);
  fclose(f);
  fprintf(stderr, "uade: Saved %zd entries into content db.\n", nccused);
}


/* Compare function for bsearch() and qsort() to sort eagleplayers with
   respect to name extension. */
static int ufcompare(const void *a, const void *b)
{
  const struct eagleplayermap *ua = a;
  const struct eagleplayermap *ub = b;
  return strcasecmp(ua->extension, ub->extension);
}
