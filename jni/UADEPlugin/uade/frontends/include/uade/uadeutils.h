#ifndef _UADE_UTILS_H_
#define _UADE_UTILS_H_

#include <stdint.h>
#include <stdio.h>

struct uade_file {
	char *name;  /* filename */
	char *data;  /* file data, can be NULL */
	size_t size;
};

static inline uint16_t read_be_u16(void *s)
{
	uint16_t x;
	uint8_t *ptr = (uint8_t *) s;
	x = ptr[1] + (ptr[0] << 8);
	return x;
}

static inline uint32_t read_be_u32(void *s)
{
	uint32_t x;
	uint8_t *ptr = (uint8_t *) s;
	x = (ptr[0] << 24) + (ptr[1] << 16) + (ptr[2] << 8) + ptr[3];
	return x;
}

static inline void write_be_u32(void *s, uint32_t x)
{
	uint8_t *ptr = (uint8_t *) s;
	ptr[0] = (x >> 24);
	ptr[1] = (x >> 16);
	ptr[2] = (x >> 8);
	ptr[3] = x;
}

size_t uade_atomic_fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

/*
 * Create a 'struct uade_file' that is used to present and contain name
 * and data of a file. The structure has following members:
 *
 * char *name, the file name
 * char *data, the contents of the file. This can be NULL.
 * size_t size, the size of data
 *
 * buf is copied into the 'struct uade_file' so it can be changed or freed
 * afterwards.
 *
 * Returns NULL on error (out of memory).
 */
struct uade_file *uade_file(const char *name, const void *data, size_t size);

void uade_file_free(struct uade_file *f);

/* Create uade_file from a file name. Returns NULL on error. */
struct uade_file *uade_file_load(const char *name);

void *uade_read_file(size_t *fs, const char *filename);

#endif
