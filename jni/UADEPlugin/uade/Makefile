LIBDIR = /usr/local/lib/uade2
UADECORENAME=uadecore
PKGCONFIGDIR = /usr/local/lib/pkgconfig



NDK=/home/sasq/code/android-ndk-r4-crystax
PLATFORM=android-4

CC = $(NDK)/build/prebuilt/linux-x86/arm-eabi-4.4.0/bin/arm-eabi-gcc


ARCHFLAGS = 
ARCHFLAGS += -fpic -mthumb-interwork -ffunction-sections -funwind-tables -fstack-protector -fno-short-enums -D__ARM_ARCH_5__ -D__ARM_ARCH_5T__ -D__ARM_ARCH_5E__ -D__ARM_ARCH_5TE__  -fomit-frame-pointer -fno-strict-aliasing -finline-limit=64  

ARCHFLAGS += -Wno-psabi -march=armv5te -mtune=xscale -msoft-float -mthumb -Os
# ARCHFLAGS += -Wno-psabi -march=armv7-a -mfloat-abi=softfp -mfpu=vfp -mthumb -Os -mfpu=neon

 

ARCHFLAGS += -DANDROID  -Wa,--noexecstack  -O2 -DNDEBUG -g   

ARCHLIBS = 
DEBUGFLAGS = 


# /home/sasq/android/android-ndk-r4-crystax/build/prebuilt/linux-x86/arm-eabi-4.4.0/bin/arm-eabi-g++
# -I/home/sasq/android/android-ndk-r4-crystax/build/platforms/android-4/arch-arm/usr/include
# -fpic -mthumb-interwork -ffunction-sections -funwind-tables -fstack-protector -fno-short-enums
# -D__ARM_ARCH_5__ -D__ARM_ARCH_5T__ -D__ARM_ARCH_5E__ -D__ARM_ARCH_5TE__  -Wno-psabi 
# -march=armv5te -mtune=xscale -msoft-float -mthumb -Os -fomit-frame-pointer -fno-strict-aliasing -finline-limit=64 
# -I/home/sasq/code/android/droidsound/jni/GMEPlugin -DANDROID  -Wa,--noexecstack   -O2 -DNDEBUG -g    
# -c -MMD -MP -MF /home/sasq/code/android/droidsound/obj/local/armeabi/objs/gme/GMEPlugin.o.d 
# /home/sasq/code/android/droidsound/jni/GMEPlugin/GMEPlugin.cpp -o /home/sasq/code/android/droidsound/obj/local/armeabi/objs/gme/GMEPlugin.o

ARCHINCLUDES = -I$(NDK)/build/platforms/android-4/arch-arm/usr/include

NATIVECC = gcc

COMMONGCCOPTS = -Wall -Wno-unused -Wno-format -Wmissing-prototypes -Wstrict-prototypes -fno-exceptions -O2

TARGETCFLAGS = -fomit-frame-pointer $(COMMONGCCOPTS) $(DEBUGFLAGS) $(ARCHFLAGS)
LIBRARIES = -lm $(AUDIOLIBS) $(ARCHLIBS)

# Native flags are used to build tools that generate new code that is then
# compiled with the target compiler.
NATIVECFLAGS = $(COMMONGCCOPTS) $(DEBUGFLAGS)

.SUFFIXES: .a .o .c .h .S

.SECONDARY: cpuemu.c cpustbl.c cputbl.h

NATIVEINCLUDES=-I. -I./include
INCLUDES= $(ARCHINCLUDES) -I. -I./include


CPUEMUOBJS = cpuemu1.o cpuemu2.o cpuemu3.o cpuemu4.o cpuemu5.o cpuemu6.o cpuemu7.o cpuemu8.o

BASEOBJS = main.o newcpu.o memory.o custom.o cia.o audio.o compiler.o cpustbl.o \
       missing.o sd-sound.o md-support.o cfgfile.o fpp.o debug.o \
       readcpu.o cpudefs.o $(CPUEMUOBJS) \
       uade.o uadeipc.o \
       uademain.o sinctable.o text_scope.o

OBJS = main.o $(BASEOBJS) unixatomic.o ossupport.o
LIBOBJS = $(BASEOBJS) simpleipc.o simplesupport.o


all:	uadecore

uadecore:	$(OBJS)
	$(CC) $(ARCHFLAGS) -o $@ $(OBJS) $(LIBRARIES)

libuade.a:	$(LIBOBJS)
	$(AR) rs $@ $(LIBOBJS) 


clean:
	-rm -f $(OBJS) *.o uadecore
	-rm -f gencpu cpudefs.c
	-rm -f cpuemu.c build68k cputmp.s cpustbl.c cputbl.h

install:	$(UADECORENAME)
	mkdir -p "$(LIBDIR)" "$(PKGCONFIGDIR)"
	chmod og+rx "$(LIBDIR)"
	cp -f "$(UADECORENAME)" "$(LIBDIR)"/
	chmod og+rx "$(LIBDIR)/$(UADECORENAME)"
	install ../uade.pc "$(PKGCONFIGDIR)"/
	chmod og+rx "$(PKGCONFIGDIR)"
	chmod 644 "$(PKGCONFIGDIR)/uade.pc"

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


# Then target builds

cpustbl.o: cpuemu.c
	$(CC) $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  -o $@ cpustbl.c

cpuemu1.o: cpuemu.c
	$(CC) -DPART_1 $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  -o $@ $<

cpuemu2.o: cpuemu.c
	$(CC) -DPART_2 $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  -o $@ $<

cpuemu3.o: cpuemu.c
	$(CC) -DPART_3 $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  -o $@ $<

cpuemu4.o: cpuemu.c
	$(CC) -DPART_4 $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  -o $@ $<

cpuemu5.o: cpuemu.c
	$(CC) -DPART_5 $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  -o $@ $<

cpuemu6.o: cpuemu.c
	$(CC) -DPART_6 $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  -o $@ $<

cpuemu7.o: cpuemu.c
	$(CC) -DPART_7 $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  -o $@ $<

cpuemu8.o: cpuemu.c
	$(CC) -DPART_8 $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  -Wno-sign-compare -o $@ $<

custom.o:	include/audio.h

.rc.res:
	$(WRC) $(INCLUDES) $<
.m.o:
	$(CC) $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  $<
.c.o:
	$(CC) $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  $< -o $@
.c.s:
	$(CC) $(INCLUDES) -S $(INCDIRS) $(TARGETCFLAGS)  $< -o $@
.c.i:
	$(CC) $(INCLUDES) -E $(INCDIRS) $(TARGETCFLAGS)  $< > $@
.S.o:
	$(CC) $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  $< -o $@
.s.o:
	$(CC) $(INCLUDES) -c $(INCDIRS) $(TARGETCFLAGS)  $< -o $@

# Saves recompiling...
touch:	
	touch *.o; touch build68k; touch cpudefs.c; touch cpudefs.o; touch gencpu; touch cpuemu.c; touch cpuemu*.o cpufast.o

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
