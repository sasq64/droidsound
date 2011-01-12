# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
 
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := sc68

LOCAL_SRC_FILES := SC68Plugin.cpp

MY_SOURCES := \
	$(wildcard $(LOCAL_PATH)/libsc68/*.c) \
	$(wildcard $(LOCAL_PATH)/libsc68/**/*.c) \
	$(wildcard $(LOCAL_PATH)/file68/**/*.c) \
	$(wildcard $(LOCAL_PATH)/unice68/*.c)

LOCAL_SRC_FILES += $(MY_SOURCES:$(LOCAL_PATH)%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/libsc68 \
	$(LOCAL_PATH)/libsc68/sc68 \
	$(LOCAL_PATH)/file68 \
	$(LOCAL_PATH)/file68/sc68 \
	$(LOCAL_PATH)/unice68

LOCAL_CFLAGS := -DHAVE_CONFIG_H

LOCAL_LDLIBS := -llog -lz

include $(BUILD_SHARED_LIBRARY)
