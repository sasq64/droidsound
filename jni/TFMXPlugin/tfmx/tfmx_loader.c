/*
 * tfmx.c
 * File loader and UI for TFMX player.
 * jhp 29Feb96
 */

#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>

#include <stdint.h>

#include <android/log.h>

#include "tfmx.h"
#include "tfmx_player.h"
#include "tfmx_iface.h"

#include "tfmx_audio.h"

extern struct Hdb hdb[8];
extern struct Pdblk pdb;
extern struct Mdb mdb;
extern char act[8];

U32 outRate=44100;
unsigned int mlen = 0;
U8 *smplbuf = 0;
U8 *smplbuf_end = 0;
int *macros = 0;
int *patterns = 0;
short ts[512][8];

struct TFMXHeader mdat_header;

U32 mdat_editbuf[MDAT_EDITBUF_LONGS];

int num_ts;
int num_pat;
int num_mac;
int gubed=0;
int printinfo=0;
int loops=1;

/* structure of of cyb tfmx module (mdat and smpl in one file) */
/* format by my weird friend Alexis 'Cyb' Nasr, back in 1995, yeah ! */
/* FYI, he stopped coding (used asm m68k back then), and is now a doctor ! */
/* values are stored in big endian in the file */
struct CybHeader {
    uint32_t TFhd_head;    /* dc.l "TFHD" for recognition */
    uint32_t TFhd_offset;  /* dc.l		TFhd_sizeof */
    uint8_t  TFhd_type;    /* module type :0/1/2/3 (bit 7=FORCED) */
    uint8_t  TFhd_version; /* currently 0 */
    uint32_t _TFhd_mdatsize;  /* compiler may align them, use offsets */
    uint32_t _TFhd_smplsize;
    uint16_t _TFhd_sizeof;
};


static int tfmx_loader(char *mfn,char *sfn);


/* loading of a single Cyb' TFMX file */
/* return 0 on success */
static int
tfmx_cyb_file_load (char *fn)
{
    char *tmp_mdat = NULL;
    char *tmp_smpl = NULL;
    FILE *cybf = NULL;
    char *radix = NULL;
    uint8_t *cybmem = NULL;
    long fileSize;
    FILE *mdatf = NULL;
    FILE *smplf = NULL;
    struct CybHeader *cybh = NULL;
    int retval = 1;

    int mdatsize;
    int smplsize;
    uint32_t offset;

    /* get radix from filename */
    if (!(radix = strrchr(fn,'/')))
		radix = fn;
    else
		radix++;

    /* open the single file */
    cybf = fopen(fn, "rb");

    if (!cybf)
    {
		return retval;
    }

    /* get length */
    fseek(cybf,0, SEEK_END);
    fileSize = ftell(cybf);
    rewind(cybf);

    /* alloc mem */
    cybmem = (char *)malloc(fileSize);
    if (!cybmem)
		goto cleanup;

    /* read it */
    if (fread(cybmem, fileSize, 1, cybf) < 1)
		goto cleanup;
    fclose(cybf);
    cybf = NULL;

    if (strncmp(cybmem, "TFHD", 4))
		goto cleanup;

    cybh = (struct CybHeader *)cybmem;

    //offset = INT32_FROM_BE(cybh->TFhd_offset);
    offset = ntohl(cybh->TFhd_offset);
    fprintf(stderr, "Offset %x -> %x\n", cybh->TFhd_offset, offset);
//////
    return -1;

    mdatsize = 0;
    mdatsize  = cybmem[10]; mdatsize <<= 8;
    mdatsize |= cybmem[11]; mdatsize <<= 8;
    mdatsize |= cybmem[12]; mdatsize <<= 8; 
    mdatsize |= cybmem[13];

    smplsize = 0;
    smplsize  = cybmem[14]; smplsize <<= 8;
    smplsize |= cybmem[15]; smplsize <<= 8;
    smplsize |= cybmem[16]; smplsize <<= 8; 
    smplsize |= cybmem[17];



    /* create temp file names from radix */
    tmp_mdat = NULL; //strdup_printf("/tmp/__mdat_%s__", radix);
    tmp_smpl = NULL; //strdup_printf("/tmp/__smpl_%s__", radix);

    /* open and write temp files */
    mdatf = fopen(tmp_mdat, "wb");
    if (!mdatf)
		goto cleanup;
    fwrite(cybmem + offset, mdatsize, 1, mdatf);
    fclose(mdatf);

    smplf = fopen(tmp_smpl, "wb");
    if (!smplf)
		goto cleanup;
    fwrite(cybmem + offset + mdatsize, smplsize, 1, mdatf);
    fclose(smplf);

    /* tfmx loading */
   //// if (tfmx_loader(tmp_mdat, tmp_smpl) == 1) {
////		goto cleanup;
////    }
    retval = 0;

/* a kind of poor man exception handling :-/ */
  cleanup:
    /* if value for tmpfile => remove it */
    if (mdatf)
		remove(tmp_mdat);
    if (smplf)
		remove(tmp_smpl);
    if (tmp_mdat)
		free(tmp_mdat);
    if (tmp_smpl)
		free(tmp_smpl);
    if (cybmem)
		free(cybmem);
    if (cybf)
		fclose(cybf);
    return retval;
}
/*
char LoadTFMXFile(char *fName)
{
    int suffixPos, status;
    char *mfn = fName, *sfn, *c;

    if(!fName) return 1;

    mfn = strdup("r-type.mdat");
    sfn = strdup("r-type.smpl");

    if ((status=tfmx_loader(mfn,sfn))==1) {
		free(sfn); return 1;
    }
    else if (status==2) {
		free(sfn); return 1;
    }

    free(sfn);
    return 0;
} */

int LoadTFMXFile (char *musicData, int musicLen, char *sampleData, int sampleLen)
{
    /* struct stat s; */
    int x, y, z = 0;
    U16 *sh, *lg;

    memcpy(&mdat_header, musicData, sizeof(mdat_header));

  //  __android_log_print(ANDROID_LOG_VERBOSE, "tfmx_loader", "%s -> %s", musicData, mdat_header.magic);


    if (strncmp("TFMX-SONG", mdat_header.magic, 9)
		&& strncmp("TFMX_SONG", mdat_header.magic, 9)
		&& strncasecmp("TFMXSONG", mdat_header.magic, 8)
		&& strncasecmp("TFMX ", mdat_header.magic, 5))
    {
		TFMXERR("LoadTFMX: Not a TFMX module");
		return(2);
    }

    memcpy(mdat_editbuf, musicData + sizeof(mdat_header), MDAT_EDITBUF_LONGS * 4);

    mlen = (musicLen - sizeof(mdat_header)) / 4;

    mdat_editbuf[mlen] = -1;
    if (!mdat_header.trackstart)
		mdat_header.trackstart = 0x180;
    else
		mdat_header.trackstart = (ntohl(mdat_header.trackstart) - 0x200L) >> 2;
    if (!mdat_header.pattstart)
		mdat_header.pattstart = 0x80;
    else mdat_header.pattstart = (ntohl(mdat_header.pattstart) - 0x200L) >> 2;
    if (!mdat_header.macrostart) mdat_header.macrostart=0x100;
    else mdat_header.macrostart=(ntohl(mdat_header.macrostart)-0x200L)>>2;
    if (mlen<136) {
		return(2);
    }

    for (x=0;x<32;x++) {
		mdat_header.start[x]=ntohs(mdat_header.start[x]);
		mdat_header.end[x]=ntohs(mdat_header.end[x]);
		mdat_header.tempo[x]=ntohs(mdat_header.tempo[x]);
    }

    /* Calc the # of subsongs */
    nSongs = 0;
    for (x = 0; x < 31; x++)
    {
		if ((mdat_header.start[x] <= mdat_header.end[x])
		    && !(x > 0 && mdat_header.end[x] == 0L))
		{
		    nSongs++;
		}
    }
/* Now that we have pointers to most everything, this would be a good time to
   fix everything we can... ntohs tracksteps, convert pointers to array
   indices, ntohl patterns and macros.  We fix the macros first, then the
   patterns, and then the tracksteps (because we have to know when the
   patterns begin to know when the tracksteps end...) */
    z = mdat_header.macrostart;
    macros = &(mdat_editbuf[z]);

    for (x = 0; x < 128; x++) {
		y=(ntohl(mdat_editbuf[z])-0x200);
		if ((y&3) || ((y>>2) > mlen)) /* probably not strictly right */
		    break;
		mdat_editbuf[z++]=y >> 2;
    }
    num_mac = x;

    z=mdat_header.pattstart;
    patterns = &mdat_editbuf[z];
    for (x = 0; x < 128; x++) {
		y=(ntohl(mdat_editbuf[z])-0x200);
		if ((y&3) || ((y>>2) > mlen))
		    break;
		mdat_editbuf[z++] = y>>2;
    }
    num_pat = x;

    lg = (U16 *)&mdat_editbuf[patterns[0]];
    sh = (U16 *)&mdat_editbuf[mdat_header.trackstart];
    num_ts = (patterns[0] - mdat_header.trackstart) >> 2;
    y=0;
    while (sh<lg) {
		x=ntohs(*sh);
		*sh++=x;
    }

/* Now at long last we calc the size of and load the sample file. */

	smplbuf = sampleData;
	smplbuf_end = smplbuf + sampleLen - 1;

///    if (plugin_cfg.blend)
	output_chans = 2;
/// plugin_cfg.blend &= 1;

    tfmx_calc_sizes();
    TFMXRewind();

    return 0;

/* Now the song is fully loaded.  Everything is done but ntohl'ing the actual
   pattern and macro data. The routines that use the data do it for themselves.*/
}

void tfmx_fill_module_info(char *t)
{
    int x;

    /* Don't print info if there's no song... */
    if(!smplbuf) {
		sprintf(t, "No song loaded!");
		return;
    }

    t += sprintf(t, "Module text section:\n\n");
    for (x = 0;x < 6; x++)
		t += sprintf(t, ">%40.40s\n", mdat_header.text[x]);

    t += sprintf(t, "\n%d tracksteps at 0x%04lx\n", num_ts, (mdat_header.trackstart<<2)+0x200);
    t += sprintf(t, "%d patterns at 0x%04lx\n", num_pat, (mdat_header.pattstart<<2)+0x200);
    t += sprintf(t, "%d macros at 0x%04lx\n", num_mac, (mdat_header.macrostart<<2)+0x200);

    t += sprintf(t, "\nSubsongs:\n\n");
    for (x = 0; x < 31; x++)
    {
		if ((mdat_header.start[x] <= mdat_header.end[x])
		    && !(x > 0 && mdat_header.end[x] == 0L))
		{
		    t += sprintf(t,"Song %2d: start %3x end %3x tempo %d\n", x,
						 ntohs(mdat_header.start[x]), ntohs(mdat_header.end[x]),
						 mdat_header.tempo[x]);
		}
    }
}
