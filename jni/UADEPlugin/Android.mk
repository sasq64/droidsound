LOCAL_PATH := $(call my-dir)

# ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)

include $(CLEAR_VARS)

# LOCAL_ARM_NEON := true

LOCAL_MODULE    := uade

FE=uade/frontends/common


LOCAL_SRC_FILES :=  UADEPlugin.cpp $(FE)/uadecontrol.c $(FE)/effects.c $(FE)/support.c $(FE)/md5.c $(FE)/songdb.c $(FE)/uadeconf.c $(FE)/eagleplayer.c  $(FE)/amifilemagic.c $(FE)/vplist.c uade/unixatomic.c

LOCAL_SRC_FILES += uade/main.c uade/newcpu.c uade/memory.c uade/custom.c uade/cia.c uade/audio.c uade/compiler.c uade/cpustbl.c \
       uade/missing.c uade/sd-sound.c uade/md-support.c uade/cfgfile.c uade/fpp.c uade/debug.c \
       uade/readcpu.c uade/cpudefs.c uade/cpuemu.c \
       uade/uade.c uade/uadeipc.c \
       uade/uademain.c uade/sinctable.c uade/text_scope.c uade/simpleipc.c uade/simplesupport.c


 

# MY_SOURCES := $(wildcard $(LOCAL_PATH)/gme/*.cpp)
# LOCAL_SRC_FILES += $(MY_SOURCES:$(LOCAL_PATH)%=%)

#LOCAL_CFLAGS := -I$(LOCAL_PATH)/include/sidplay -I$(LOCAL_PATH)/include
#LOCAL_LDLIBS := -llog -L$(LOCAL_PATH)/lib/sidplay/builders -lresid-builder -L$(LOCAL_PATH)/lib -lresid -lsidplay2

#LOCAL_CFLAGS := -I$(LOCAL_PATH)/uade/include -I$(LOCAL_PATH)/$(FE)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/uade $(LOCAL_PATH)/uade/include $(LOCAL_PATH)/$(FE)

LOCAL_LDLIBS := -llog
# -L$(LOCAL_PATH)/uade -luade

include $(BUILD_SHARED_LIBRARY)

# gcc -I. -I./include -c  -fomit-frame-pointer -Wall -Wno-unused -Wno-format -Wmissing-prototypes -Wstrict-prototypes -DGCCCONSTFUNC="__attribute__((const))" -D_REENTRANT -fno-exceptions -fno-strength-reduce -DREGPARAM= -D__inline__=inline -O2  -g   main.c -o main.o

# endif