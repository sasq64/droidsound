LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := sidplay2

LOCAL_SRC_FILES :=  SidplayPlugin.cpp

# MY_SOURCES := $(wildcard $(LOCAL_PATH)/gme/*.cpp)
# LOCAL_SRC_FILES += $(MY_SOURCES:$(LOCAL_PATH)%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include/sidplay $(LOCAL_PATH)/include 

#-I$(LOCAL_PATH)/include/sidplay -I$(LOCAL_PATH)/include
LOCAL_LDLIBS := -llog -L$(LOCAL_PATH)/lib/sidplay/builders -lresid-builder -L$(LOCAL_PATH)/lib -lresid -lsidplay2
#LOCAL_LDLIBS := -llog -L$(LOCAL_PATH)/lib/sidplay/builders -L$(LOCAL_PATH)/lib
#LOCAL_STATIC_LIBRARIES := resid-builder resid sidplay2


include $(BUILD_SHARED_LIBRARY)
