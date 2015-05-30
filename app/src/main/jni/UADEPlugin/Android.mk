LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := uade

FE = uade/frontends/common

LOCAL_SRC_FILES := \
                UADEPlugin.cpp \
                $(FE)/amifilemagic.c \
                $(FE)/eagleplayer.c \
                $(FE)/effects.c \
                $(FE)/md5.c \
                $(FE)/songdb.c \
                $(FE)/support.c \
                $(FE)/uadeconf.c \
                $(FE)/uadecontrol.c \
                $(FE)/vplist.c \
                uade/unixatomic.c


LOCAL_SRC_FILES += \
                uade/audio.c \
                uade/cfgfile.c \
                uade/cia.c \
                uade/compiler.c \
                uade/cpudefs.c \
                uade/cpuemu.c \
                uade/cpustbl.c \
                uade/custom.c \
                uade/debug.c \
                uade/fpp.c \
                uade/main.c \
                uade/md-support.c \
                uade/memory.c \
                uade/missing.c \
                uade/newcpu.c \
                uade/readcpu.c \
                uade/sd-sound.c \
                uade/simpleipc.c \
                uade/simplesupport.c \
                uade/sinctable.c \
                uade/text_scope.c \
                uade/uade.c \
                uade/uadeipc.c \
                uade/uademain.c 

LOCAL_C_INCLUDES := \
                $(LOCAL_PATH)/uade \
                $(LOCAL_PATH)/uade/include \
                $(LOCAL_PATH)/uade/frontends/include \
                $(LOCAL_PATH)/$(FE) \


LOCAL_CFLAGS := $(MY_CFLAGS)

LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)
