BINDIR = /usr/local/bin
MANDIR = /usr/local/share/man/man1
UADE123NAME=uade123

CC = gcc
CFLAGS = -Wall -O2 -pthread -I../../include -I../common `pkg-config fuse --cflags` -DUADENAME=\"/usr/local/bin/uade123\" -g 
CLIBS =  `pkg-config fuse --libs` -lm

all:	uadefs

include ../common/Makefile.common

MODULES = uadefs.o $(COMMONMODULES)

%.o:	%.c
	$(CC) $(CFLAGS) -c $<

uadefs:	$(MODULES)
	$(CC) $(CFLAGS) -o $@ $(MODULES) $(CLIBS)

uadefs.o:	uadefs.c

install:	uadefs
	mkdir -p "$(BINDIR)" "$(MANDIR)"
	install uadefs "$(BINDIR)"/
	install uadefs.1 "$(MANDIR)"/

clean:	
	rm -f uadefs *.o

