#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <android/log.h>
#include <uade/songdb.h>
#include <uade/uadeconf.h>
#include <uade/uadeconstants.h>
#include "md5.h"
#include <uade/unixatomic.h>
#include <uade/ossupport.h>
#include <uade/uadeoptions.h>
#include "support.h"

#define NORM_ID "n="
#define NORM_ID_LENGTH 2

#define eserror(fmt, args...) do { __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "song.conf error on line %zd: " fmt "\n", lineno, ## args); exit(1); } while (0)

static int escompare(const void *a, const void *b);
static struct uade_content *get_content(const char *md5, struct uade_state *state);

static void add_sub_normalisation(struct uade_content *n, char *normalisation)
{
    struct persub *subinfo;
    char *endptr;

    subinfo = malloc(sizeof(*subinfo));
    if (subinfo == NULL)
        uadeerror("Can't allocate memory for normalisation entry\n");

    subinfo->sub = strtol(normalisation, &endptr, 10);
    if (*endptr != ',' || subinfo->sub < 0) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Invalid normalisation entry: %s\n", normalisation);
        return;
    }

    subinfo->normalisation = strdup(endptr + 1);
    if (subinfo->normalisation == NULL)
        uadeerror("Can't allocate memory for normalisation string\n");

    vplist_append(n->subs, subinfo);
}

/* Compare function for bsearch() and qsort() to sort songs with respect
   to their md5sums */
static int contentcompare(const void *a, const void *b)
{
    return strcasecmp(((struct uade_content *)a)->md5,
              ((struct uade_content *)b)->md5);
}

static int escompare(const void *a, const void *b)
{
    return strcasecmp(((struct eaglesong *)a)->md5,
              ((struct eaglesong *)b)->md5);
}

static struct uade_content *get_content(const char *md5, struct uade_state *state)
{
    struct uade_content key;
    struct uade_songdb *db = &state->songdb;

    if (db->contentchecksums == NULL)
        return NULL;

    memset(&key, 0, sizeof key);
    strlcpy(key.md5, md5, sizeof key.md5);

    return bsearch(&key, db->contentchecksums, db->nccused,
               sizeof db->contentchecksums[0], contentcompare);
}

static struct uade_content *create_content_checksum(struct uade_state *state, const char *md5, uint32_t playtime)
{
    struct uade_content *n;
    struct uade_songdb *db = &state->songdb;

    if (db->nccused == db->nccalloc) {
        db->nccalloc = MAX(db->nccalloc * 2, 16);
        n = realloc(db->contentchecksums, db->nccalloc * sizeof(struct uade_content));
        if (n == NULL) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: No memory for new content checksums.\n");
            return NULL;
        }
        db->contentchecksums = n;
    }

    n = &db->contentchecksums[db->nccused];

    if (md5 == NULL)
        return n;

    db->nccused++;

    db->ccmodified = 1;

    memset(n, 0, sizeof(*n));
    strlcpy(n->md5, md5, sizeof(n->md5));
    n->playtime = playtime;

    n->subs = vplist_create(1);

    return n;
}

static void md5_from_buffer(char *dest, size_t destlen, uint8_t * buf, size_t bufsize)
{
    uint8_t md5[16];
    int ret;
    MD5_CTX ctx;
    MD5Init(&ctx);
    MD5Update(&ctx, buf, bufsize);
    MD5Final(md5, &ctx);
    ret =
        snprintf(dest, destlen,
             "%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x",
             md5[0], md5[1], md5[2], md5[3], md5[4], md5[5], md5[6],
             md5[7], md5[8], md5[9], md5[10], md5[11], md5[12], md5[13],
             md5[14], md5[15]);
    if (ret >= destlen || ret != 32) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "MD5 buffer error (%d/%zd)\n", ret, destlen);
        exit(1);
    }
}

static void update_playtime(struct uade_state *state, struct uade_content *n, uint32_t playtime)
{
    if (n->playtime != playtime) {
        state->songdb.ccmodified = 1;
        n->playtime = playtime;
    }
}

static void sort_content_checksums(struct uade_state *state)
{
    struct uade_songdb *db = &state->songdb;
    
    if (db->contentchecksums == NULL)
        return;

    qsort(db->contentchecksums, db->nccused, sizeof db->contentchecksums[0], contentcompare);
}

/* replace must be zero if content db is unsorted */
struct uade_content *uade_add_playtime(struct uade_state *state, const char *md5, uint32_t playtime)
{
    struct uade_content *n;

    /* If content db mhasn't been read into memory already, it is not used */
    if (state->songdb.contentchecksums == NULL)
        return NULL;

    /* Do not record song shorter than 3 secs */
    if (playtime < 3000)
        return NULL;

    if (strlen(md5) != 32)
        return NULL;

    n = get_content(md5, state);
    if (n != NULL) {
        update_playtime(state, n, playtime);
        return n;
    }

    n = create_content_checksum(state, md5, playtime);

    sort_content_checksums(state);

    return n;
}

void uade_lookup_volume_normalisation(struct uade_state *state)
{
    size_t i, nsubs;
    struct uade_effect *ue = &state->effects;
    struct uade_config *uc = &state->config;
    struct uade_song *us = state->song;
    struct uade_content *content = get_content(us->md5, state);

    if (content != NULL) {

        nsubs = vplist_len(content->subs);

        for (i = 0; i < nsubs; i++) {

            struct persub *subinfo = vplist_get(content->subs, i);

            if (subinfo->sub == us->cur_subsong) {
                uade_set_config_option(uc, UC_NORMALISE,
                               subinfo->normalisation);
                uade_effect_normalise_unserialise(uc->
                                  normalise_parameter);
                uade_effect_enable(ue, UADE_EFFECT_NORMALISE);
                break;
            }
        }
    }
}

static void get_song_flags_and_attributes_from_songstore(struct uade_song *us, struct uade_state *state)
{
    struct eaglesong key;
    struct eaglesong *es;
    struct uade_songdb *db = &state->songdb;

    if (db->songstore != NULL) {
        /* Lookup md5 from the songdb */
        strlcpy(key.md5, us->md5, sizeof key.md5);
        es = bsearch(&key, db->songstore, db->nsongs, sizeof db->songstore[0], escompare);

        if (es != NULL) {
            /* Found -> copy flags and attributes from database */
            us->flags |= es->flags;
            us->songattributes = es->attributes;
        }
    }
}

int uade_alloc_song(struct uade_state *state, const char *filename)
{
    struct uade_song *us;
    struct uade_content *content;

    state->song = NULL;

    us = calloc(1, sizeof *us);
    if (us == NULL)
        goto error;

    strlcpy(us->module_filename, filename, sizeof us->module_filename);

    us->buf = atomic_read_file(&us->bufsize, filename);
    if (us->buf == NULL)
        goto error;

    /* Compute an md5sum of the song */
    md5_from_buffer(us->md5, sizeof us->md5, us->buf, us->bufsize);

    /* Needs us->md5 sum */
    get_song_flags_and_attributes_from_songstore(us, state);

    /* Lookup playtime from content database */
    us->playtime = -1;
    content = get_content(us->md5, state);
    if (content != NULL && content->playtime > 0)
        us->playtime = content->playtime;

    /* We can't know subsong numbers yet. The eagleplayer will report them
     * in the playback state */
    us->min_subsong = us->max_subsong = us->cur_subsong = -1;

    state->song = us;
    return 1;

      error:
    if (us != NULL) {
        free(us->buf);
        free(us);
    }
    return 0;
}

static int uade_open_and_lock(const char *filename, int create)
{
    int fd, ret;
    fd = open(filename, O_RDWR);
    if (fd < 0) {
        if (errno == ENOENT && create) {
            fd = open(filename, O_RDWR | O_CREAT,
                  S_IRUSR | S_IWUSR);
            if (fd < 0)
                return -1;
        } else {
            return -1;
        }
    }

#if 0 //ndef UADE_HAVE_CYGWIN
    ret = lockf(fd, F_LOCK, 0);
    if (ret) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Unable to lock song.conf: %s (%s)\n",
            filename, strerror(errno));
        atomic_close(fd);
        return -1;
    }
#endif

    return fd;
}


static struct uade_content *store_playtime(const char *md5, long playtime,
                       int *newccmodified,
                       size_t oldnccused,
                       struct uade_state *state)
{
    struct uade_content *n = NULL;
    struct uade_songdb *db = &state->songdb;

    if (oldnccused > 0) {
        struct uade_content key;
        memset(&key, 0, sizeof key);
        strlcpy(key.md5, md5, sizeof key.md5);

        /* We use "oldnccused" here as the length, while new entries
           are added in unsorted manner to the end of the array */
        n = bsearch(&key, db->contentchecksums, oldnccused, sizeof db->contentchecksums[0], contentcompare);
        if (n == NULL)
            /* new songs on disk db -> merge -> need saving */
            *newccmodified = 1;
    }

    /* We value a playtime determined during run-time over
       a database value */
    if (n == NULL) {
        /* Note, create_content_checksum() makes "ccmodified"
           true, which we work-around later with the "newccmodified" */
        n = create_content_checksum(state, md5, (uint32_t) playtime);
    }

    if (n == NULL) {
        /* No memory, fuck. We shouldn't save anything to
           avoid losing data. */
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Warning, no memory for the song database\n");
        db->cccorrupted = 1;
    }

    return n;
}



int uade_read_content_db(const char *filename, struct uade_state *state)
{
    char line[1024];
    FILE *f;
    size_t lineno = 0;
    long playtime;
    int i, j, nexti;
    char *id, *eptr;
    char numberstr[1024];
    char *md5;
    struct uade_songdb *db = &state->songdb;

    /* We make backups of some variables because following loop will
       make it always true, which is not what we want. The end result should
       be that ccmodified is true in following cases only:
       1. the in-memory db is already dirty
       2. the in-memory db gets new data from disk db (merge operation)
       Otherwise ccmodified should be false. */
    int newccmodified = db->ccmodified;
    size_t oldnccused = db->nccused;
    int fd;
    struct uade_content *n;

    /* Try to create a database if it doesn't exist */
    if (db->contentchecksums == NULL &&
        create_content_checksum(state, NULL, 0) == NULL)
        return 0;

    fd = uade_open_and_lock(filename, 0);
    if (fd < 0) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Can not find %s\n", filename);
        return 0;
    }

    f = fdopen(fd, "r");
    if (f == NULL) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Can not create FILE structure for %s\n",
            filename);
        close(fd);
        return 0;
    }

    while (xfgets(line, sizeof line, f) != NULL) {
        lineno++;

        if (line[0] == '#')
            continue;

        md5 = line;
        i = skip_and_terminate_word(line, 0);
        if (i < 0)
            continue; /* playtime doesn't exist */

        for (j = 0; isxdigit(line[j]); j++);

        if (j != 32)
            continue; /* is not a valid md5sum */

        /* Grab and validate playtime (in milliseconds) */
        nexti = skip_and_terminate_word(line, i);

        playtime = strtol(&line[i], &eptr, 10);
        if (*eptr != 0 || playtime < 0) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Invalid playtime for md5 %s on contentdb line %zd: %s\n", md5, lineno, numberstr);
            continue;
        }

        n = store_playtime(md5, playtime, &newccmodified, oldnccused, state);
        if (n == NULL)
            continue;

        i = nexti; /* Note, it could be that i < 0 */

        /* Get rest of the directives in a loop */
        while (i >= 0) {
            id = &line[i];
            i = skip_and_terminate_word(line, i);

            /* Subsong volume normalisation: n=sub1,XXX */
            if (strncmp(id, NORM_ID, NORM_ID_LENGTH) == 0) {
                id += NORM_ID_LENGTH;
                add_sub_normalisation(n, id);
            } else {
                __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Unknown contentdb directive on line %zd: %s\n", lineno, id);
            }
        }
    }
    fclose(f);

    db->ccmodified = newccmodified;

    sort_content_checksums(state);

    return 1;
}

int uade_read_song_conf(const char *filename, struct uade_state *state)
{
    FILE *f = NULL;
    struct eaglesong *s;
    size_t allocated;
    size_t lineno = 0;
    size_t i;
    int fd;
    struct uade_songdb *db = &state->songdb;

    fd = uade_open_and_lock(filename, 1);
    /* open_and_lock() may fail without harm (it's actually supposed to
       fail if the process does not have lock (write) permissions to
       the song.conf file */

    f = fopen(filename, "r");
    if (f == NULL)
        goto error;

    db->nsongs = 0;
    allocated = 16;
    db->songstore = calloc(allocated, sizeof db->songstore[0]);
    if (db->songstore == NULL)
        eserror("No memory for song store.");

    while (1) {
        char **items;
        size_t nitems;

        items = read_and_split_lines(&nitems, &lineno, f,
                         UADE_WS_DELIMITERS);
        if (items == NULL)
            break;

        assert(nitems > 0);

        if (db->nsongs == allocated) {
            allocated *= 2;
            db->songstore = realloc(db->songstore, allocated * sizeof(db->songstore[0]));
            if (db->songstore == NULL)
                eserror("No memory for players.");
        }

        s = &db->songstore[db->nsongs];
        db->nsongs++;

        memset(s, 0, sizeof s[0]);

        if (strncasecmp(items[0], "md5=", 4) != 0) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Line %zd must begin with MD5= in %s\n", lineno, filename);
            free(items);
            continue;
        }
        if (strlcpy(s->md5, items[0] + 4, sizeof s->md5) !=
            ((sizeof s->md5) - 1)) {
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Line %zd in %s has too long an md5sum.\n", lineno, filename);
            free(items);
            continue;
        }

        for (i = 1; i < nitems; i++) {
            if (strncasecmp(items[i], "comment:", 7) == 0)
                break;
            if (uade_song_and_player_attribute(&s->attributes, &s->flags, items[i], lineno))
                continue;
            __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Song option %s is invalid\n", items[i]);
        }

        for (i = 0; items[i] != NULL; i++)
            free(items[i]);

        free(items);
    }

    fclose(f);

    /* we may not have the file locked */
    if (fd >= 0)
        atomic_close(fd);	/* lock is closed too */

    /* Sort MD5 sums for binary searching songs */
    qsort(db->songstore, db->nsongs, sizeof db->songstore[0], escompare);
    return 1;

      error:
    if (f)
        fclose(f);
    if (fd >= 0)
        atomic_close(fd);
    return 0;
}

void uade_save_content_db(const char *filename, struct uade_state *state)
{
    int fd;
    FILE *f;
    size_t i;
    struct uade_songdb *db = &state->songdb;

    if (db->ccmodified == 0 || db->cccorrupted)
        return;

    fd = uade_open_and_lock(filename, 1);
    if (fd < 0) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Cannot write content db: %s\n", filename);
        return;
    }

    f = fdopen(fd, "w");
    if (f == NULL) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Cannot create a FILE structure for content db: %s\n", filename);
        close(fd);
        return;
    }

    for (i = 0; i < db->nccused; i++) {
        char str[1024];
        size_t subi, nsubs;
        size_t bindex, bleft;
        struct uade_content *n = &db->contentchecksums[i];

        str[0] = 0;

        bindex = 0;
        bleft = sizeof(str);

        nsubs = vplist_len(n->subs);

        for (subi = 0; subi < nsubs; subi++) {
            struct persub *sub = vplist_get(n->subs, subi);
            int ret;
            ret = snprintf(&str[bindex], bleft, NORM_ID "%s ", sub->normalisation);
            if (ret >= bleft) {
                __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Too much subsong infos for %s\n", n->md5);
                break;
            }
            bleft -= ret;
            bindex += ret;
        }

        fprintf(f, "%s %u %s\n", n->md5, (unsigned int) n->playtime, str);
    }

    db->ccmodified = 0;

    fclose(f);
    __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "UADE: Saved %zd entries into content db.\n", db->nccused);
}

int uade_test_silence(void *buf, size_t size, struct uade_state *state)
{
    int i, s, exceptioncount;
    int16_t *sm;
    int nsamples;
    int64_t count = state->song->silence_count;
    int end = 0;

    if (state->config.silence_timeout < 0)
        return 0;

    exceptioncount = 0;
    sm = buf;
    nsamples = size / 2;

    for (i = 0; i < nsamples; i++) {
        s = (sm[i] >= 0) ? sm[i] : -sm[i];
        if (s >= (32767 * 1 / 100)) {
            exceptioncount++;
            if (exceptioncount >= (size * 2 / 100)) {
                count = 0;
                break;
            }
        }
    }

    if (i == nsamples) {
        count += size;
        if (count / (UADE_BYTES_PER_FRAME * state->config.frequency) >= state->config.silence_timeout) {
            count = 0;
            end = 1;
        }
    }

    state->song->silence_count = count;

    return end;
}

void uade_unalloc_song(struct uade_state *state)
{
    free(state->song->buf);
    state->song->buf = NULL;

    free(state->song);
    state->song = NULL;
}

int uade_update_song_conf(const char *songconfin, const char *songconfout,
              const char *songname, const char *options)
{
    int ret;
    int fd;
    char md5[33];
    void *mem = NULL;
    size_t filesize, newsize;
    int found = 0;
    size_t inputsize;
    char *input, *inputptr, *outputptr;
    size_t inputoffs;
    char newline[256];
    size_t i;
    int need_newline = 0;

    if (strlen(options) > 128) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Too long song.conf options.\n");
        return 0;
    }

    fd = uade_open_and_lock(songconfout, 1);

    input = atomic_read_file(&inputsize, songconfin);
    if (input == NULL) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot read song.conf: %s\n", songconfin);
        atomic_close(fd);	/* Closes the lock too */
        return 0;
    }

    newsize = inputsize + strlen(options) + strlen(songname) + 64;
    mem = realloc(input, newsize);
    if (mem == NULL) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot realloc the input file buffer for song.conf.\n");
        free(input);
        atomic_close(fd);	/* Closes the lock too */
        return 0;
    }
    input = mem;

    mem = atomic_read_file(&filesize, songname);
    if (mem == NULL)
        goto error;

    md5_from_buffer(md5, sizeof md5, mem, filesize);

    inputptr = outputptr = input;
    inputoffs = 0;

    while (inputoffs < inputsize) {
        if (inputptr[0] == '#')
            goto copyline;

        if ((inputoffs + 37) >= inputsize)
            goto copyline;

        if (strncasecmp(inputptr, "md5=", 4) != 0)
            goto copyline;

        if (strncasecmp(inputptr + 4, md5, 32) == 0) {
            if (found) {
                __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Warning: dupe entry in song.conf: %s (%s)\n" "Need manual resolving.\n", songname, md5);
                goto copyline;
            }
            found = 1;
            snprintf(newline, sizeof newline, "md5=%s\t%s\n", md5,
                 options);

            /* Skip this line. It will be appended later to the end of the buffer */
            for (i = inputoffs; i < inputsize; i++) {
                if (input[i] == '\n') {
                    i = i + 1 - inputoffs;
                    break;
                }
            }
            if (i == inputsize) {
                i = inputsize - inputoffs;
                found = 0;
                need_newline = 1;
            }
            inputoffs += i;
            inputptr += i;
            continue;
        }

          copyline:
        /* Copy the line */
        for (i = inputoffs; i < inputsize; i++) {
            if (input[i] == '\n') {
                i = i + 1 - inputoffs;
                break;
            }
        }
        if (i == inputsize) {
            i = inputsize - inputoffs;
            need_newline = 1;
        }
        memmove(outputptr, inputptr, i);
        inputoffs += i;
        inputptr += i;
        outputptr += i;
    }

    if (need_newline) {
        snprintf(outputptr, 2, "\n");
        outputptr += 1;
    }

    /* There is enough space */
    ret = snprintf(outputptr, PATH_MAX + 256, "md5=%s\t%s\tcomment %s\n", md5, options, songname);
    outputptr += ret;

    if (ftruncate(fd, 0)) {
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Cannot truncate the file.\n");
        goto error;
    }

    /* Final file size */
    i = (size_t) (outputptr - input);

    if (atomic_write(fd, input, i) < i)
        __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "Unable to write file contents back. Data loss happened. CRAP!\n");

      error:
    atomic_close(fd);	/* Closes the lock too */
    free(input);
    free(mem);
    return 1;
}
