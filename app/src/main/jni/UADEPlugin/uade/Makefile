
NATIVECC = gcc

COMMONGCCOPTS = -Wall -Wno-unused -Wno-format -Wmissing-prototypes -Wstrict-prototypes -fno-exceptions -O2

TARGETCFLAGS = -fomit-frame-pointer $(COMMONGCCOPTS) $(DEBUGFLAGS) $(ARCHFLAGS)
LIBRARIES = -lm $(AUDIOLIBS) $(ARCHLIBS)

.SUFFIXES: .a .o .c .h .S

.SECONDARY: cpuemu.c cpustbl.c cputbl.h

NATIVEINCLUDES=-I. -I./include
INCLUDES= $(ARCHINCLUDES) -I. -I./include

all: cpuemu.c cputbl.h cpustbl.c cpudefs.c


# First native builds

build68k: build68k.o
	$(NATIVECC) $(NATIVECFLAGS) $(NATIVEINCLUDES) -o $@ build68k.o

gencpu:	gencpu.o nativereadcpu.o nativecpudefs.o nativemissing.o
	$(NATIVECC) $(NATIVECFLAGS) $(NATIVEINCLUDES) -o $@ gencpu.o nativereadcpu.o nativecpudefs.o nativemissing.o

build68k.o:	build68k.c include/readcpu.h
	$(NATIVECC) $(NATIVECFLAGS) $(NATIVEINCLUDES) -c $<

gencpu.o:	gencpu.c include/readcpu.h
	$(NATIVECC) $(NATIVECFLAGS) $(NATIVEINCLUDES) -c $<

nativereadcpu.o:	readcpu.c include/readcpu.h
	$(NATIVECC) $(NATIVECFLAGS) $(NATIVEINCLUDES) -c -o $@ $<

nativemissing.o:	missing.c
	$(NATIVECC) $(NATIVECFLAGS) $(NATIVEINCLUDES) -c -o $@ $<

cpuemu.c cputbl.h cpustbl.c: gencpu
	./gencpu

nativecpudefs.o:	cpudefs.c include/readcpu.h
	$(NATIVECC) $(NATIVECFLAGS) $(NATIVEINCLUDES) -c -o $@ $<

cpudefs.c:	build68k table68k
	./build68k <./table68k >cpudefs.c


cpudefs.o:	cpudefs.c include/readcpu.h
readcpu.o:	readcpu.c include/readcpu.h

main.o:	include/uae.h
cia.o: include/events.h
custom.o: include/events.h
newcpu.o: newcpu.c include/uade.h include/events.h include/uadeipc.h
	$(CC) $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  newcpu.c

sd-sound.o:	include/uade.h sd-sound.c sd-sound.h include/uadeconstants.h sd-sound-generic.h sd-sound-generic.c
audio.o: include/uade.h include/events.h sd-sound.h include/gensound.h include/audio.h include/uadeconstants.h include/sinctable.h include/text_scope.h sd-sound-generic.h
sinctable.o:	include/sinctable.h
memory.o:
debug.o: 
fpp.o: 

uademain.o:	uademain.c include/uae.h include/ossupport.h include/unixsupport.h

uade.o:	uade.c include/uade.h sd-sound.h include/uadeipc.h include/uadeconstants.h include/ossupport.h include/unixsupport.h include/amigamsg.h include/sysincludes.h

uadeipc.o:	uadeipc.c include/uadeipc.h include/ossupport.h include/unixsupport.h include/sysincludes.h

ossupport.o:	ossupport.c include/ossupport.h include/unixsupport.h include/uade.h include/unixatomic.h unixatomic.c

unixatomic.o:	unixatomic.c include/sysincludes.h include/unixatomic.h

textscope.o:	text_scope.c include/text_scope.h include/custom.h
