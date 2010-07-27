LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := tfmx

LOCAL_SRC_FILES :=  TFMXPlugin.cpp tfmx/tfmx_audio.c tfmx/tfmx_iface.c tfmx/tfmx_loader.c tfmx/tfmx_player.c 

# MY_SOURCES := $(wildcard $(LOCAL_PATH)/gme/*.cpp)
# LOCAL_SRC_FILES += $(MY_SOURCES:$(LOCAL_PATH)%=%)

LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)
