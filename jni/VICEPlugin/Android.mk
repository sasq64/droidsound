LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := resid
LOCAL_ARM_MODE := arm
LOCAL_CPP_EXTENSION := cc
MY_RESID_FILES = $(wildcard $(LOCAL_PATH)/vice/resid/*.cc)
LOCAL_SRC_FILES := $(MY_RESID_FILES:$(LOCAL_PATH)%=%)
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := vice
LOCAL_ARM_MODE := arm
LOCAL_CPP_EXTENSION := cc
LOCAL_SRC_FILES := \
	VICEPlugin.cc \
	android/archdep.c \
	android/console.c \
	android/joy.c \
	android/signals.c \
	android/vsyncarch.c \
	android/gui/c64ui.c \
	android/gui/c64scui.c \
	android/gui/uicmdline.c \
	android/gui/vsidui.c \
	android/null/fullscreen.c \
	android/null/ui.c \
	android/null/uiapi.c \
	android/null/keyboard.c \
	vice/alarm.c \
	vice/clkguard.c \
	vice/charset.c \
	vice/cmdline.c \
	vice/crc32.c \
	vice/debug.c \
	vice/dma.c \
	vice/event.c \
	vice/findpath.c \
	vice/fliplist.c \
	vice/init.c \
	vice/initcmdline.c \
	vice/interrupt.c \
	vice/ioutil.c \
	vice/kbdbuf.c \
	vice/keyboard.c \
	vice/joystick.c \
	vice/lib.c \
	vice/lightpen.c \
	vice/machine.c \
	vice/machine-bus.c \
	vice/network.c \
	vice/palette.c \
	vice/ram.c \
	vice/romset.c \
	vice/resources.c \
	vice/screenshot.c \
	vice/snapshot.c \
	vice/sound.c \
	vice/sysfile.c \
	vice/translate.c \
	vice/traps.c \
	vice/util.c \
	vice/vsync.c \
	vice/zfile.c \
	vice/zipcode.c \
	vice/c64/c64.c \
	vice/c64/c64_256k.c \
	vice/c64/c64-cmdline-options.c \
	vice/c64/c64-resources.c \
	vice/c64/c64-snapshot.c \
	vice/c64/c64bus.c \
	vice/c64/c64cia1.c \
	vice/c64/c64cia2.c \
	vice/c64/c64datasette.c \
	vice/c64/c64embedded.c \
	vice/c64/c64export.c \
	vice/c64/c64fastiec.c \
	vice/c64/c64gluelogic.c \
	vice/c64/c64iec.c \
	vice/c64/c64io.c \
	vice/c64/c64keyboard.c \
	vice/c64/c64mem.c \
	vice/c64/c64meminit.c \
	vice/c64/c64memlimit.c \
	vice/c64/c64memrom.c \
	vice/c64/c64memsnapshot.c \
	vice/c64/c64model.c \
	vice/c64/c64pla.c \
	vice/c64/c64printer.c \
	vice/c64/c64rom.c \
	vice/c64/c64romset.c \
	vice/c64/c64rsuser.c \
	vice/c64/c64video.c \
	vice/c64/patchrom.c \
	vice/c64/plus256k.c \
	vice/c64/plus60k.c \
	vice/c64/psid.c \
	vice/c64/reloc65.c \
	vice/core/ciacore.c \
	vice/core/ciatimer.c \
	vice/raster/raster.c \
	vice/raster/raster-cache.c \
	vice/raster/raster-canvas.c \
	vice/raster/raster-changes.c \
	vice/raster/raster-cmdline-options.c \
	vice/raster/raster-line.c \
	vice/raster/raster-line-changes.c \
	vice/raster/raster-line-changes-sprite.c \
	vice/raster/raster-modes.c \
	vice/raster/raster-resources.c \
	vice/raster/raster-sprite.c \
	vice/raster/raster-sprite-cache.c \
	vice/raster/raster-sprite-status.c \
	vice/rs232drv/rs232drv.c \
	vice/rs232drv/rsuser.c \
	vice/sid/fastsid.c \
	vice/sid/sid.c \
	vice/sid/sid-cmdline-options.c \
	vice/sid/sid-resources.c \
	vice/sid/sid-snapshot.c \
	vice/sid/resid.cc \
	vice/sounddrv/soundaiff.c \
	vice/sounddrv/sounddump.c \
	vice/sounddrv/soundfs.c \
	vice/sounddrv/soundiff.c \
	vice/sounddrv/soundmovie.c \
	vice/sounddrv/soundvoc.c \
	vice/sounddrv/soundwav.c \
	vice/vicii/vicii.c \
	vice/vicii/vicii-badline.c \
	vice/vicii/vicii-color.c \
	vice/vicii/vicii-cmdline-options.c \
	vice/vicii/vicii-fetch.c \
	vice/vicii/vicii-irq.c \
	vice/vicii/vicii-mem.c \
	vice/vicii/vicii-phi1.c \
	vice/vicii/vicii-resources.c \
	vice/vicii/vicii-snapshot.c \
	vice/vicii/vicii-sprites.c \
	vice/vicii/vicii-stubs.c \
	vice/vicii/vicii-timing.c \
	overrides/attach.c \
	overrides/autostart.c \
	overrides/datasette.c \
	overrides/log.c \
	overrides/maincpu.c \
	overrides/mouse.c \
	overrides/serial.c \
	overrides/c64/c64drive.c \
	overrides/c64/c64parallel.c \
	overrides/c64/c64sound.c \
	overrides/c64/cart/c64cart.c \
	overrides/c64/cart/c64carthooks.c \
	overrides/c64/cart/c64cartmem.c \
	overrides/c64/cart/crt.c \
	overrides/c64/cart/digimax.c \
	overrides/c64/cart/reu.c \
	overrides/diskimage/diskimage.c \
	overrides/drive/drive.c \
	overrides/drive/drive-cmdline-options.c \
	overrides/drive/drive-resources.c \
	overrides/drive/drive-snapshot.c \
	overrides/drive/drivecpu.c \
	overrides/drive/driveimage.c \
	overrides/fsdevice/fsdevice.c \
	overrides/gfxoutputdrv/gfxoutput.c \
	overrides/iecbus/iecbus.c \
	overrides/imagecontents/imagecontents.c \
	overrides/monitor/monitor.c \
	overrides/parallel/parallel.c \
	overrides/printer/printer.c \
	overrides/sounddrv/sounddummy.c \
	overrides/tape/tape.c \
	overrides/tape/tape-snapshot.c \
	overrides/vdrive/vdrive.c \
	overrides/vicii/vicii-draw.c \
	overrides/video/video.c \
#terminator for last backslash

LOCAL_CFLAGS := -DHAVE_NEON -DHAVE_CONFIG_H


LOCAL_C_INCLUDES := $(LOCAL_PATH) \
	$(LOCAL_PATH)/android \
	$(LOCAL_PATH)/android/readline \
	$(LOCAL_PATH)/vice \
	$(LOCAL_PATH)/vice/c64 \
	$(LOCAL_PATH)/vice/c64/cart \
	$(LOCAL_PATH)/vice/c64dtv \
	$(LOCAL_PATH)/vice/drive \
	$(LOCAL_PATH)/vice/imagecontents \
	$(LOCAL_PATH)/vice/raster \
	$(LOCAL_PATH)/vice/rs232drv \
	$(LOCAL_PATH)/vice/sid \
	$(LOCAL_PATH)/vice/tape \
	$(LOCAL_PATH)/vice/vdrive \
	$(LOCAL_PATH)/vice/vicii \
#terminator for last backslash

LOCAL_STATIC_LIBRARIES := resid

LOCAL_LDLIBS := -llog -lz

include $(BUILD_SHARED_LIBRARY)
