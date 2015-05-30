LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := sexypsf
 
LOCAL_SRC_FILES := SexyPSFPlugin.cpp sexypsf/PsxBios.c sexypsf/PsxCounters.c sexypsf/PsxDma.c \
       sexypsf/Spu.c sexypsf/PsxHw.c sexypsf/PsxMem.c sexypsf/Misc.c \
       sexypsf/R3000A.c sexypsf/PsxInterpreter.c \
       sexypsf/PsxHLE.c sexypsf/spu/spu.c 

#LOCAL_SRC_FILES += $(MY_SOURCES:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/sexypsf
LOCAL_LDLIBS := -llog -lz
LOCAL_CFLAGS := -DPSS_STYLE=1 $(MY_CFLAGS)

include $(BUILD_SHARED_LIBRARY)
