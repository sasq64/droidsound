#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <netinet/in.h>

//  #include <ipcsupport.h>
#include <android/log.h>

#include <uade/unixsupport.h>

extern int get_write_mutex(volatile void **);
extern int release_write_mutex(volatile void **);
extern int get_read_mutex(volatile void **);
extern int release_read_mutex(volatile void **);
extern void client_sleep(void);

/*
unsigned int htonl(unsigned int l)
{
	return ((l>>24) & 0xff) | ((l>>8) & 0xFF00) | ((l<<8) & 0xFF0000) | (l<<24);
}

unsigned int ntohl(unsigned int l)
{
	return ((l>>24) & 0xff) | ((l>>8) & 0xFF00) | ((l<<8) & 0xFF0000) | (l<<24);
}*/
 

#define BUF_SIZE 8192

struct buffer
{
	unsigned char *inbuffer;
	unsigned char *add_ptr;
	volatile void *mutex;
};

static struct buffer *server_buf = NULL;
static struct buffer *client_buf = NULL;

int uade_ipc_data_available(void *f)
{
	struct buffer *b = (struct buffer*)f;

	if(get_read_mutex(&b->mutex))
	{
		int filled = b->add_ptr - b->inbuffer;

		release_read_mutex(&b->mutex);
		return filled;
	}
	return -1;
}

ssize_t uade_ipc_read(void *f, const void *data, size_t size)
{
	struct buffer *b = (struct buffer*)f;

	// __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "%s tries to read %d bytes from %p\n", (b == client_buf ? "CLIENT" : "SERVER"), size, b);

	if(get_read_mutex(&b->mutex))
	{
		int filled = b->add_ptr - b->inbuffer;

		while(filled < size)
		{
			release_read_mutex(&b->mutex);
			client_sleep();
			get_read_mutex(&b->mutex);
			filled = b->add_ptr - b->inbuffer;
		}

		if(size > filled)
			size = filled;

		if(size)
		{
			memcpy((void*)data, b->inbuffer, size);
			memmove(b->inbuffer, b->inbuffer+size, BUF_SIZE-size);
			b->add_ptr -= size;
		}
		release_read_mutex(&b->mutex);

		// __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "%s read %d bytes, %d bytes left\n", (b == client_buf ? "CLIENT" : "SERVER"), size, b->add_ptr - b->inbuffer);

		return size;
	}
	return -1;

}


ssize_t uade_ipc_write(void *f, const void *data, size_t size)
{
	struct buffer *b = (struct buffer*)f;

	// __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "%s tries to write %d bytes to %p\n",  (b == server_buf ? "CLIENT" : "SERVER"), size, b);

	if(get_write_mutex(&b->mutex))
	{
	
		int filled = b->add_ptr - b->inbuffer;

		if(filled + size > BUF_SIZE)
			size = BUF_SIZE-filled;

		if(size)
		{
			memcpy(b->add_ptr, data, size);
			b->add_ptr += size;
		}
		// __android_log_print(ANDROID_LOG_VERBOSE, "UADE", "%s wrote %d bytes\n", (b == server_buf ? "CLIENT" : "SERVER"), size);
		release_write_mutex(&b->mutex);
		return size;
	}
	return -1;
}

struct buffer *new_buf(void)
{
	struct buffer *b = malloc(sizeof(struct buffer));
	b->inbuffer = malloc(BUF_SIZE);
	b->add_ptr = b->inbuffer;
	b->mutex = NULL;
	return b;
}

void *uade_ipc_set_input(const char *input)
{
	if(!server_buf)
	{
		server_buf = new_buf();
		client_buf = new_buf();
	}

	if(strcmp(input, "server") == 0)
	  return (void *)server_buf;
	else
	if(strcmp(input, "client") == 0)
	  return (void *)client_buf;

	return NULL;
}


void *uade_ipc_set_output(const char *output)
{
	if(!server_buf)
	{
		server_buf = new_buf();
		client_buf = new_buf();
	}

	if(strcmp(output, "server") == 0)
	  return (void *)server_buf;
	else
	if(strcmp(output, "client") == 0)
	  return (void *)client_buf;

	return NULL;
}
