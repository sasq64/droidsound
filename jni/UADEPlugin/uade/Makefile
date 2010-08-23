NATIVECC = gcc


AR = ar

NDK=/home/sasq/code/android-ndk-r4-crystax
PLATFORM=android-4

CC = $(NDK)/build/prebuilt/linux-x86/arm-eabi-4.4.0/bin/arm-eabi-gcc


ARCHFLAGS = 
ARCHFLAGS += -fpic -mthumb-interwork -ffunction-sections -funwind-tables -fstack-protector -fno-short-enums -D__ARM_ARCH_5__ -D__ARM_ARCH_5T__ -D__ARM_ARCH_5E__ -D__ARM_ARCH_5TE__  -Wno-psabi -march=armv5te -mtune=xscale -msoft-float -mthumb -Os -fomit-frame-pointer -fno-strict-aliasing -finline-limit=64  
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


CFLAGS = -fomit-frame-pointer -Wall -Wno-unused -Wno-format -Wmissing-prototypes -Wstrict-prototypes -DGCCCONSTFUNC="__attribute__((const))" -D_REENTRANT -fno-exceptions -fno-strength-reduce -DREGPARAM= -D__inline__=inline -O2 $(ARCHFLAGS) -g
LIBRARIES = -lm $(AUDIOLIBS) $(ARCHLIBS)

# Native flags are used to build tools that generate new code that is then
# compiled with the target compiler.
NATIVECFLAGS =  -Wall -Wno-unused -Wno-format -Wmissing-prototypes -Wstrict-prototypes -fno-exceptions -fno-strength-reduce -O2 -g

.SUFFIXES: .a .o .c .h .S

.SECONDARY: cpuemu.c cpustbl.c cputbl.h

INCLUDES= -I$(NDK)/build/platforms/android-4/arch-arm/usr/include -I. -I./include
NATIVEINCLUDES= -I. -I./include



CPUEMUOBJS = cpuemu1.o cpuemu2.o cpuemu3.o cpuemu4.o cpuemu5.o cpuemu6.o cpuemu7.o cpuemu8.o

BASEOBJS = newcpu.o memory.o custom.o cia.o audio.o compiler.o cpustbl.o \
       missing.o sd-sound.o md-support.o cfgfile.o fpp.o debug.o \
       readcpu.o cpudefs.o $(CPUEMUOBJS) \
       uade.o players.o strlrep.o uadeipc.o uademain.o
       
OBJS = main.o $(BASEOBJS) unixatomic.o ossupport.o ipcsupport.o
LIBOBJS = $(BASEOBJS) simpleipc.o simplesupport.o

all:	uadecore

uadecore:	$(OBJS)
	$(CC) $(ARCHFLAGS) $(DEBUGFLAGS) $(LIBRARIES) $(MATHLIB) -o $@ $(OBJS)

libuade.a:	$(LIBOBJS)
	$(AR) rs $@ $(LIBOBJS) 

clean:
	-rm -f $(OBJS) *.o uade
	-rm -f gencpu cpudefs.c
	-rm -f cpuemu.c build68k cputmp.s cpustbl.c cputbl.h

# First native builds

build68k: build68k.o
	$(NATIVECC) $(NATIVECFLAGS) $(NATIVEINCLUDES) -o build68k build68k.o

gencpu:	gencpu.o nativereadcpu.o nativecpudefs.o nativemissing.o
	$(NATIVECC) $(NATIVECFLAGS) $(NATIVEINCLUDES) -o gencpu gencpu.o nativereadcpu.o nativecpudefs.o nativemissing.o

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
	$(CC) $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) -o $@ cpustbl.c

cpuemu1.o: cpuemu.c
	$(CC) -DPART_1 $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) -o $@ $<

cpuemu2.o: cpuemu.c
	$(CC) -DPART_2 $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) -o $@ $<

cpuemu3.o: cpuemu.c
	$(CC) -DPART_3 $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) -o $@ $<

cpuemu4.o: cpuemu.c
	$(CC) -DPART_4 $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) -o $@ $<

cpuemu5.o: cpuemu.c
	$(CC) -DPART_5 $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) -o $@ $<

cpuemu6.o: cpuemu.c
	$(CC) -DPART_6 $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) -o $@ $<

cpuemu7.o: cpuemu.c
	$(CC) -DPART_7 $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) -o $@ $<

cpuemu8.o: cpuemu.c
	$(CC) -DPART_8 $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) -Wno-sign-compare $(DEBUGFLAGS) -o $@ $<

custom.o:	include/audio.h

.rc.res:
	$(WRC) $(INCLUDES) $<
.m.o:
	$(CC) $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) $<
.c.o:
	$(CC) $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) $< -o $@
.c.s:
	$(CC) $(INCLUDES) -S $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) $< -o $@
.c.i:
	$(CC) $(INCLUDES) -E $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) $< > $@
.S.o:
	$(CC) $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) $< -o $@
.s.o:
	$(CC) $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) $< -o $@

# Saves recompiling...
touch:	
	touch *.o; touch build68k; touch cpudefs.c; touch cpudefs.o; touch gencpu; touch cpuemu.c; touch cpuemu*.o cpufast.o

cpudefs.o:	cpudefs.c include/readcpu.h
readcpu.o:	readcpu.c include/readcpu.h

main.o:	include/uae.h
uademain.o:	include/uae.h
cia.o: include/events.h
custom.o: include/events.h
newcpu.o: newcpu.c include/uade.h include/events.h include/uadeipc.h
	$(CC) $(INCLUDES) -c $(INCDIRS) $(CFLAGS) $(X_CFLAGS) $(DEBUGFLAGS) newcpu.c

sd-sound.o:	include/uade.h sd-sound.c sd-sound.h include/uadeconstants.h sd-sound-generic.h sd-sound-generic.c
audio.o: include/uade.h include/events.h sd-sound.h include/gensound.h include/audio.h include/uadeconstants.h sd-sound-generic.h
memory.o: 
debug.o: 
fpp.o: 

uade.o: include/uade.h sd-sound.h include/uadeipc.h include/uadeconstants.h

uadeipc.o:	include/uadeipc.h

players.o:	players.c players.h

ossupport.o:	include/uade.h ossupport.c unixsupport.c include/unixsupport.h

ipcsupport.o:	include/uade.h ipcsupport.c include/ipcsupport.h unixipc.c
