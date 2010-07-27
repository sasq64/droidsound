#include <stdio.h>

#include "tfmx/tfmx_iface.h"

char mbuffer[32768];
char sbuffer[512*1024];

int main(int argc, const char **argv)
{
	short *buffer = malloc(128*1024);

	memset(buffer, 0x55, 128*1024);
	int rc;

	FILE *fp = fopen("r-type.mdat", "rb");
	int mlen = fread(mbuffer, 1, sizeof(mbuffer), fp);
	fclose(fp);
	fp = fopen("r-type.smpl", "rb");
	int slen = fread(sbuffer, 1, sizeof(sbuffer), fp);
	fclose(fp);



	rc = LoadTFMXFile(mbuffer, mlen, sbuffer, slen);


	//rc = LoadTFMXFile(argv[1]);
	printf("RC %d\n", rc);

	//player_TfmxInit();
	//player_StartSong(0,0);
	TFMXSetSubSong(1);
	TFMXRewind();

	fp = fopen("dump.dat", "wb");
	int count = 256;
	while(count--) {
		rc = tfmx_try_to_make_block();
		printf("RC %d\n", rc);

		printf("BLOCK SIZE %d\n", tfmx_get_block_size());
		rc = tfmx_get_block(buffer);
		printf("RC %d\n", rc);

		printf("GOT %d %d %0d\n", buffer[0], buffer[1024], buffer[4000]);

		fwrite(buffer, 1, 4096, fp);
	}
	fclose(fp);


	return 0;
}
