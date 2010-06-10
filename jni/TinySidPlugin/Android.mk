LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := tinysid

LOCAL_SRC_FILES :=  TinySidPlugin.cpp tiny/sidengine.c

# MY_SOURCES := $(wildcard $(LOCAL_PATH)/gme/*.cpp)
# LOCAL_SRC_FILES += $(MY_SOURCES:$(LOCAL_PATH)%=%)

include $(BUILD_SHARED_LIBRARY)
