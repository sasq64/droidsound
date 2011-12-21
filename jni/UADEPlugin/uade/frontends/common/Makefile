AR = ar
CC = gcc
CFLAGS = -Wall -O2 -I../include -I../common -g  -no-cpp-precomp -I/Users/alankila/git/uade/bencode-tools.bin/include
CLIBS =  -L/Users/alankila/git/uade/bencode-tools.bin/lib -Wl,-rpath,/Users/alankila/git/uade/bencode-tools.bin/lib -lm -lbencodetools

all:	libuade.a

%.o:	%.c
	$(CC) $(CFLAGS) -c $<

include ../common/Makefile.common

libuade.a: $(COMMONMODULES)
	$(AR) rcs $@ $(COMMONMODULES)

clean:	
	rm -f *.o *.a
