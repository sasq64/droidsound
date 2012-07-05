# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.cpprg/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
 
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := unrar

UNRAR_FILES = unrar/filestr.cpp unrar/recvol.cpp unrar/rs.cpp unrar/scantree.cpp
LIB_FILES = unrar/filestr.cpp unrar/scantree.cpp unrar/dll.cpp

FILES = unrar/rar.cpp unrar/strlist.cpp unrar/strfn.cpp unrar/pathfn.cpp unrar/savepos.cpp unrar/smallfn.cpp unrar/global.cpp unrar/file.cpp unrar/filefn.cpp unrar/filcreat.cpp \
	unrar/archive.cpp unrar/arcread.cpp unrar/unicode.cpp unrar/system.cpp unrar/isnt.cpp unrar/crypt.cpp unrar/crc.cpp unrar/rawread.cpp unrar/encname.cpp \
	unrar/resource.cpp unrar/match.cpp unrar/timefn.cpp unrar/rdwrfn.cpp unrar/consio.cpp unrar/options.cpp unrar/ulinks.cpp unrar/errhnd.cpp unrar/rarvm.cpp \
	unrar/rijndael.cpp unrar/getbits.cpp unrar/sha1.cpp unrar/extinfo.cpp unrar/extract.cpp unrar/volume.cpp unrar/list.cpp unrar/find.cpp unrar/unpack.cpp unrar/cmddata.cpp


LOCAL_SRC_FILES := UnRar.cpp $(FILES) $(LIB_FILES)

LOCAL_CFLAGS := -DSILENT -DRARDLL -I$(LOCAL_PATH)/rar $(MY_CFLAGS)
LOCAL_LDLIBS := -llog -lz

include $(BUILD_SHARED_LIBRARY)
