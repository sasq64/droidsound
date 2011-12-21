#include <uade/uadeutils.h>

#include <assert.h>
#include <stdlib.h>
#include <string.h>

size_t uade_atomic_fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
	uint8_t *dest = ptr;
	size_t readmemb = 0;
	size_t ret;

	while (readmemb < nmemb) {
		ret = fread(dest, size, nmemb - readmemb, stream);
		if (ret == 0 && (feof(stream) || ferror(stream)))
			break;
		readmemb += ret;
		dest += size * ret;
	}

	assert(readmemb <= nmemb);
	return readmemb;
}

void *uade_read_file(size_t *fs, const char *filename)
{
	FILE *f;
	size_t off;
	void *mem = NULL;
	size_t msize;
	long pos;

	f = fopen(filename, "rb");
	if (f == NULL)
		goto error;

	if (fseek(f, 0, SEEK_END))
		goto error;
	pos = ftell(f);
	if (pos < 0)
		goto error;
	if (fseek(f, 0, SEEK_SET))
		goto error;

	*fs = pos;
	msize = (pos > 0) ? pos : 1;

	if ((mem = malloc(msize)) == NULL)
		goto error;

	off = uade_atomic_fread(mem, 1, *fs, f);
	if (off < *fs) {
		fprintf(stderr, "Not able to read the whole file %s\n", filename);
		goto error;
	}

	fclose(f);
	return mem;

error:
	if (f)
		fclose(f);
	free(mem);
	*fs = 0;
	return NULL;
}

struct uade_file *uade_file_load(const char *name)
{
	struct uade_file *f = calloc(1, sizeof(struct uade_file));
	if (f == NULL)
		return NULL;
	f->name = strdup(name);
	if (f->name == NULL)
		goto err;
	f->data = uade_read_file(&f->size, f->name);
	if (f->data == NULL)
		goto err;
	return f;
err:
	uade_file_free(f);
	return NULL;
}

struct uade_file *uade_file(const char *name, const void *data, size_t size)
{
	struct uade_file *f = calloc(1, sizeof(struct uade_file));
	if (f == NULL)
		return NULL;
	if (name) {
		f->name = strdup(name);
		if (f->name == NULL)
			goto err;
	}
	f->data = malloc(size);
	if (f->data == NULL)
		goto err;
	memcpy(f->data, data, size);
	f->size = size;
	return f;
err:
	uade_file_free(f);
	return NULL;
}

void uade_file_free(struct uade_file *f)
{
	if (f == NULL)
		return;
	free(f->name);
	free(f->data);
	f->name = f->data = NULL;
	f->size = 0;
	free(f);
}
