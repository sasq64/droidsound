LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := uade

FE=uade/frontends/common

LOCAL_SRC_FILES := \
	UADEPlugin.cpp \
        bencode-tools/bencode.c \
	uade/audio.c \
	uade/cia.c \
	uade/cfgfile.c \
	uade/compiler.c \
	uade/custom.c \
	uade/cpudefs.c \
	uade/cpuemu.c \
	uade/cpustbl.c \
	uade/debug.c \
	uade/fpp.c \
	uade/main.c \
	uade/memory.c \
	uade/newcpu.c \
	uade/md-support.c \
	uade/missing.c \
	uade/sd-sound.c \
	uade/readcpu.c \
	uade/sinctable.c \
	uade/text_scope.c \
	uade/uade.c \
	uade/uademain.c \
	$(FE)/amifilemagic.c \
	$(FE)/eagleplayer.c \
	$(FE)/effects.c \
	$(FE)/md5.c \
	$(FE)/rmc.c \
	$(FE)/songdb.c \
	$(FE)/support.c \
	$(FE)/uadeconf.c \
	$(FE)/uadecontrol.c \
	$(FE)/uadeipc.c \
	$(FE)/uadestate.c \
	$(FE)/uadeutils.c \
	$(FE)/unixatomic.c \
	$(FE)/unixsupport.c \
# terminator

# just to avoid using F_LOCK
LOCAL_CFLAGS := -DUADE_HAVE_CYGWIN

LOCAL_C_INCLUDES := $(LOCAL_PATH)/uade $(LOCAL_PATH)/uade/include $(LOCAL_PATH)/uade/frontends/include $(LOCAL_PATH)/$(FE) $(LOCAL_PATH)/bencode-tools/include

LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)
