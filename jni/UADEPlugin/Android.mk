LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := uade

FE=uade/frontends/common

LOCAL_SRC_FILES :=  UADEPlugin.cpp $(FE)/uadecontrol.c $(FE)/effects.c $(FE)/support.c $(FE)/md5.c $(FE)/songdb.c $(FE)/uadeconf.c $(FE)/eagleplayer.c  $(FE)/amifilemagic.c $(FE)/vplist.c uade/unixatomic.c

LOCAL_SRC_FILES += uade/main.c uade/newcpu.c uade/memory.c uade/custom.c uade/cia.c uade/audio.c uade/compiler.c uade/cpustbl.c \
       uade/missing.c uade/sd-sound.c uade/md-support.c uade/cfgfile.c uade/fpp.c uade/debug.c \
       uade/readcpu.c uade/cpudefs.c uade/cpuemu.c \
       uade/uade.c uade/uadeipc.c \
       uade/uademain.c uade/sinctable.c uade/text_scope.c uade/simpleipc.c uade/simplesupport.c


LOCAL_C_INCLUDES := $(LOCAL_PATH)/uade $(LOCAL_PATH)/uade/include $(LOCAL_PATH)/$(FE)

LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)
