LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := playgsf
 
LOCAL_SRC_FILES := GSFPlugin.cpp playgsf/gsf.cpp playgsf/VBA/GBA.cpp playgsf/VBA/Globals.cpp playgsf/VBA/Sound.cpp playgsf/VBA/Util.cpp playgsf/VBA/bios.cpp playgsf/VBA/memgzio.c playgsf/VBA/snd_interp.cpp playgsf/VBA/unzip.cpp playgsf/VBA/psftag.c

LOCAL_SRC_FILES += playgsf/libresample-0.1.3/src/resample.c playgsf/libresample-0.1.3/src/resamplesubs.c playgsf/libresample-0.1.3/src/filterkit.c
 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/playgsf $(LOCAL_PATH)/playgsf/libresample-0.1.3/include
LOCAL_LDLIBS := -llog -lz
LOCAL_CFLAGS := -DLINUX -DC_CORE $(MY_CFLAGS)

include $(BUILD_SHARED_LIBRARY)
