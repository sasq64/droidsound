CC = gcc
XMMSFLAGS=
XMMSLIBS=
SHAREDLIBRARYFLAGS=-fPIC -shared
CFLAGS = -Wall -O2 $(SHAREDLIBRARYFLAGS) -g $(XMMSFLAGS) -I../common -I../../include
CLIBS = $(XMMSLIBS)
MODULES = plugin.o amifilemagic.o eagleplayer.o strlrep.o uadecontrol.o \
	uadeipc.o unixatomic.o subsongseek.o effects.o uadeconf.o md5.o \
	unixipc.o

libuade2.so:	$(MODULES)
	$(CC) $(CFLAGS) -o $@ $(MODULES) $(CLIBS)

amifilemagic.o:	../common/amifilemagic.c ../common/amifilemagic.h
	$(CC) $(CFLAGS) -c $<

eagleplayer.o:	../common/eagleplayer.c ../common/eagleplayer.h ../common/md5.h
	$(CC) $(CFLAGS) -c $<

effects.o:	../common/effects.c ../common/effects.h
	$(CC) $(CFLAGS) -c $<

md5.o:	../common/md5.c ../common/md5.h
	$(CC) $(CFLAGS) -c $<

plugin.o:	plugin.c plugin.h ../common/eagleplayer.h ../common/uadecontrol.h ../../include/uadeipc.h ../../include/uadeconstants.h subsongseek.h ../../include/uadeconfig.h ../common/uadeconf.h ../common/effects.h ../common/md5.h

	$(CC) $(CFLAGS) -c $<

strlrep.o:	../../strlrep.c ../../include/strlrep.h
	$(CC) $(CFLAGS) -c $<

subsongseek.o:	subsongseek.c subsongseek.h plugin.h
	$(CC) $(CFLAGS) -c $<

uadeconf.o:	../common/uadeconf.c ../common/uadeconf.h
	$(CC) $(CFLAGS) -c $<

uadecontrol.o:	../common/uadecontrol.c ../common/uadecontrol.h ../../include/uadeipc.h
	$(CC) $(CFLAGS) -c $<

uadeipc.o:	../../uadeipc.c ../../include/uadeipc.h
	$(CC) $(CFLAGS) -c $<

unixatomic.o:	../../unixatomic.c ../../include/unixatomic.h
	$(CC) $(CFLAGS) -c $<

unixipc.o:	../../unixipc.c ../../include/ipcsupport.h
	$(CC) $(CFLAGS) -c $<

clean:	
	rm -f *.so *.o
