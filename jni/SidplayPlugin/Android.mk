LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := sidplay2

LOCAL_ARM_MODE := arm

LOCAL_SRC_FILES :=  SidplayPlugin.cpp \
        resid/envelope.cpp \
        resid/extfilt.cpp \
        resid/filter.cpp \
        resid/pot.cpp \
        resid/sid.cpp \
        resid/version.cpp \
        resid/voice.cpp \
        resid/wave.cpp \
        resid/wave6581__ST.cpp \
        resid/wave6581_P_T.cpp \
        resid/wave6581_PS_.cpp \
        resid/wave6581_PST.cpp \
        resid/wave8580__ST.cpp \
        resid/wave8580_P_T.cpp \
        resid/wave8580_PS_.cpp \
        resid/wave8580_PST.cpp \
        libsidplay2/config.cpp \
        libsidplay2/event.cpp \
        libsidplay2/mixer.cpp \
        libsidplay2/player.cpp \
        libsidplay2/psiddrv.cpp \
        libsidplay2/reloc65.cpp \
        libsidplay2/sidplay2.cpp \
        libsidplay2/mos6510/mos6510.cpp \
        libsidplay2/mos656x/mos656x.cpp \
        libsidplay2/mos6526/mos6526.cpp \
        libsidplay2/sid6526/sid6526.cpp \
        libsidplay2/resid/resid-builder.cpp \
        libsidplay2/resid/resid.cpp \
        libsidplay2/sidtune/IconInfo.cpp \
        libsidplay2/sidtune/InfoFile.cpp \
        libsidplay2/sidtune/MUS.cpp \
        libsidplay2/sidtune/p00.cpp \
        libsidplay2/sidtune/PP20.cpp \
        libsidplay2/sidtune/prg.cpp \
        libsidplay2/sidtune/PSID.cpp \
        libsidplay2/sidtune/SidTune.cpp \
        libsidplay2/sidtune/SidTuneTools.cpp \
        libsidplay2/xsid/xsid.cpp



LOCAL_C_INCLUDES  += $(LOCAL_PATH)
LOCAL_C_INCLUDES  += $(LOCAL_PATH)/libsidplay2/include/sidplay
LOCAL_C_INCLUDES  += $(LOCAL_PATH)/libsidplay2/include
LOCAL_C_INCLUDES  += $(LOCAL_PATH)/libsidplay2/include/sidplay/builders
LOCAL_C_INCLUDES  += $(LOCAL_PATH)/resid

# MY_SOURCES := $(wildcard $(LOCAL_PATH)/gme/*.cpp)
# LOCAL_SRC_FILES += $(MY_SOURCES:$(LOCAL_PATH)%=%)

# LOCAL_C_INCLUDES := $(LOCAL_PATH)/include/sidplay $(LOCAL_PATH)/include 

#-I$(LOCAL_PATH)/include/sidplay -I$(LOCAL_PATH)/include
LOCAL_LDLIBS := -llog -lstdc++
# -L$(LOCAL_PATH)/lib/sidplay/builders -lresid-builder -L$(LOCAL_PATH)/lib -lresid -lsidplay2
#LOCAL_LDLIBS := -llog -L$(LOCAL_PATH)/lib/sidplay/builders -L$(LOCAL_PATH)/lib
#LOCAL_STATIC_LIBRARIES := resid-builder resid sidplay2


include $(BUILD_SHARED_LIBRARY)
