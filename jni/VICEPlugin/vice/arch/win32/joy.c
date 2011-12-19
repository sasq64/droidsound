/*
 * joy.c - Joystick support for Windows.
 *
 * Written by
 *  Tibor Biczo <crown@mail.matav.hu>
 *  Ettore Perazzoli <ettore@comm2000.it>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include "vice.h"

#include "cmdline.h"
#include "resources.h"

#ifdef HAVE_DINPUT
#include "dinput_handle.h"
#endif

#include <windows.h>

#include <assert.h>

#include "lib.h"
#include "joy.h"
#include "joystick.h"
#include "keyboard.h"
#include "machine.h"
#include "maincpu.h"
#include "res.h"
#include "translate.h"
#include "types.h"
#include "ui.h"
#include "winjoy.h"
#include "winmain.h"

static enum {
    WIN_JOY_UNINIT,
#ifdef HAVE_DINPUT
    WIN_JOY_DINPUT,
#endif
    WIN_JOY_WINMM
} joystick_inited = WIN_JOY_UNINIT;

/* Notice that this has to be `int' to make resources work.  */
static int joystick_fire_speed[4];
static int joystick_fire_axis[4];
static int joystick_autofire_button[4];

static int joystick_fire_button[4];

/* ------------------------------------------------------------------------ */

#ifdef HAVE_DINPUT
/* Joystick devices.  */
static LPDIRECTINPUTDEVICE  joystick_di_devices[4] = { NULL, NULL };
static LPDIRECTINPUTDEVICE2  joystick_di_devices2[4] = { NULL, NULL };

typedef struct _JoyAxis {
    struct _JoyAxis *next;
    DWORD id;
    char *name;
    DWORD dwOffs;
} JoyAxis;

typedef struct _JoyButton {
    struct _JoyButton *next;
    DWORD id;
    char *name;
    DWORD dwOffs;
} JoyButton;

typedef struct _JoyInfo {
    struct _JoyInfo *next;
    GUID guid;
    char *name;
    JoyAxis *axes;
    JoyButton *buttons;
} JoyInfo;

static JoyInfo *joystick_list = NULL;

static BOOL CALLBACK EnumJoyAxes(LPCDIDEVICEOBJECTINSTANCE lpddoi, LPVOID pvRef)
{
    JoyAxis *axis;
    JoyInfo *joy;

    joy = (JoyInfo*)pvRef;

    //  Save info about axis
    axis = lib_malloc(sizeof(JoyAxis));
    axis->next = NULL;
    axis->id = DIDFT_GETINSTANCE(lpddoi->dwType);
    axis->name = lib_stralloc(lpddoi->tszName);
    axis->dwOffs = lpddoi->dwOfs;

    //  Link axis into list for this joystick
    if (joy->axes == NULL) {
        joy->axes = axis;
    } else {
        JoyAxis *s;
        s = joy->axes;
        while (s->next != NULL) {
            s = s->next;
        }
        s->next = axis;
    }
    return DIENUM_CONTINUE;
}

static BOOL CALLBACK EnumJoyButtons(LPCDIDEVICEOBJECTINSTANCE lpddoi, LPVOID pvRef)
{
    JoyButton *button;
    JoyInfo *joy;

    joy = (JoyInfo*)pvRef;

    //  Save info about button
    button = lib_malloc(sizeof(JoyButton));
    button->next = NULL;
    button->id = DIDFT_GETINSTANCE(lpddoi->dwType);
    button->name = lib_stralloc(lpddoi->tszName);
    button->dwOffs = lpddoi->dwOfs;

    //  Link button into list for this joystick
    if (joy->buttons == NULL) {
        joy->buttons = button;
    } else {
        JoyButton *s;
        s = joy->buttons;
        while (s->next != NULL) {
            s = s->next;
        }
        s->next = button;
    }
    return DIENUM_CONTINUE;
}

static void joystick_release_axes(JoyAxis *axis)
{
    while (axis != NULL) {
        JoyAxis *next;

        next = axis->next;
        lib_free(axis->name);
        lib_free(axis);
        axis = next;
    }
}

static void joystick_release_buttons(JoyButton *button)
{
    while (button != NULL) {
        JoyButton *next;

        next = button->next;
        lib_free(button->name);
        lib_free(button);
        button = next;
    }
}

static void joystick_release_joysticks(void)
{
    JoyInfo *joystick;

    joystick = joystick_list;

    while (joystick != NULL) {
        JoyInfo *next;

        next = joystick->next;
        lib_free(joystick->name);
        joystick_release_axes(joystick->axes);
        joystick_release_buttons(joystick->buttons);
        lib_free(joystick);
        joystick = next;
    }
}

int joystick_di_open(int index, int dev)
{
    JoyInfo *joy = joystick_list;
    int i = 0;
    LPDIRECTINPUT di = get_directinput_handle();
#ifndef HAVE_DINPUT_LIB

    DIOBJECTDATAFORMAT joystick_objects[] = {
        { &GUID_XAxis, 0, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
        { &GUID_YAxis, 4, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
        { &GUID_ZAxis, 8, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
        { &GUID_RxAxis, 0x0c, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
        { &GUID_RyAxis, 0x10, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
        { &GUID_RzAxis, 0x14, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
        { &GUID_Slider, 0x18, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
        { &GUID_Slider, 0x1c, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_AXIS, DIDOI_ASPECTPOSITION },
        { &GUID_POV, 0x20, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_POV, 0 },
        { &GUID_POV, 0x24, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_POV, 0 },
        { &GUID_POV, 0x28, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_POV, 0 },
        { &GUID_POV, 0x2c, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_POV, 0 },
        { NULL, 0x30, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x31, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x32, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x33, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x34, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x35, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x36, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x37, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x38, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x39, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x3a, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x3b, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x3c, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x3d, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x3e, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x3f, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x40, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x41, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x42, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x43, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x44, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x45, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x46, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x47, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x48, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x49, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x4a, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x4b, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x4c, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x4d, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x4e, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 },
        { NULL, 0x4f, DIDFT_OPTIONAL | DIDFT_ANYINSTANCE | DIDFT_BUTTON, 0 }
    };

    DIDATAFORMAT data_format_struct = {
        sizeof(DIDATAFORMAT),
        sizeof(DIOBJECTDATAFORMAT),
        DIDF_ABSAXIS,
        sizeof(DIJOYSTATE),
        sizeof(joystick_objects) / sizeof(*joystick_objects),
        joystick_objects
    };
    LPCDIDATAFORMAT data_format = &data_format_struct;
#else
    LPCDIDATAFORMAT data_format = &c_dfDIJoystick;
#endif

    if (di == NULL) {
        return 0;
    }
    while (joy && i < dev - JOYDEV_HW1) {
        joy = joy->next;
        i++;
    }
    if (joy) {
        IDirectInput_CreateDevice(di, &joy->guid, &joystick_di_devices[index], NULL);
        IDirectInputDevice_QueryInterface(joystick_di_devices[index], &IID_IDirectInputDevice2, (LPVOID*)&joystick_di_devices2[index]);
        IDirectInputDevice_SetDataFormat(joystick_di_devices[index], data_format);
        IDirectInputDevice_SetCooperativeLevel(joystick_di_devices[index], ui_active_window, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
        IDirectInputDevice_Acquire(joystick_di_devices[index]);
        if (joy->axes) {
            joystick_release_axes(joy->axes);
            joy->axes = NULL;
        }
        IDirectInputDevice_EnumObjects(joystick_di_devices[index], EnumJoyAxes, (LPVOID)joy, DIDFT_AXIS);
        if (joy->buttons) {
            joystick_release_buttons(joy->buttons);
            joy->buttons = NULL;
        }
        IDirectInputDevice_EnumObjects(joystick_di_devices[index], EnumJoyButtons, (LPVOID)joy, DIDFT_BUTTON);
        return 1;
    } else {
        return 0;
    }
}

void joystick_di_close(int index)
{
    if (joystick_di_devices[index]) {
        IDirectInputDevice_Unacquire(joystick_di_devices[index]);
        if (joystick_di_devices2[index]) {
            IDirectInputDevice2_Release(joystick_di_devices2[index]);
        }
        IDirectInputDevice_Release(joystick_di_devices[index]);
    }
    joystick_di_devices[index] = NULL;
    joystick_di_devices2[index] = NULL;
}
#endif

typedef struct joy_winmm_priv_s {
    UINT uJoyID;
    JOYCAPS joy_caps;
    struct joy_winmm_priv_s* next;
} joy_winmm_priv_t;

static joy_winmm_priv_t* joy_winmm_list = NULL;

static int set_joystick_device_1(int val, void *param)
{
    joystick_device_t dev = (joystick_device_t)val;

    if (joystick_inited == WIN_JOY_UNINIT) {
        joy_arch_init();
    }

#ifdef HAVE_DINPUT
    if ((joystick_inited == WIN_JOY_DINPUT) && (joystick_port_map[0] >= JOYDEV_HW1)) {
        joystick_di_close(0);
    }

    if ((joystick_inited == WIN_JOY_DINPUT) && (dev >= JOYDEV_HW1)) {
        if (joystick_di_open(0, dev)) {
            joystick_port_map[0] = dev;
        }
    } else
#endif
    {
        joystick_port_map[0] = dev;
    }

    return 0;
}

static int set_joystick_device_2(int val, void *param)
{
    joystick_device_t dev = (joystick_device_t)val;

    if (joystick_inited == WIN_JOY_UNINIT) {
        joy_arch_init();
    }

#ifdef HAVE_DINPUT
    if ((joystick_inited == WIN_JOY_DINPUT) && (joystick_port_map[1] >= JOYDEV_HW1)) {
        joystick_di_close(1);
    }

    if ((joystick_inited == WIN_JOY_DINPUT) && (dev >= JOYDEV_HW1)) {
        if (joystick_di_open(1, dev)) {
            joystick_port_map[1] = dev;
        }
    } else
#endif
    {
        joystick_port_map[1] = dev;
    }

    return 0;
}

static int set_joystick_device_3(int val, void *param)
{
    joystick_device_t dev = (joystick_device_t)val;

    if (joystick_inited == WIN_JOY_UNINIT) {
        joy_arch_init();
    }

#ifdef HAVE_DINPUT
    if ((joystick_inited == WIN_JOY_DINPUT) && (joystick_port_map[2] >= JOYDEV_HW1)) {
        joystick_di_close(2);
    }

    if ((joystick_inited == WIN_JOY_DINPUT) && (dev >= JOYDEV_HW1)) {
        if (joystick_di_open(2, dev)) {
            joystick_port_map[2] = dev;
        }
    } else
#endif
    {
        joystick_port_map[2] = dev;
    }

    return 0;
}

static int set_joystick_device_4(int val, void *param)
{
    joystick_device_t dev = (joystick_device_t)val;

    if (joystick_inited == WIN_JOY_UNINIT) {
        joy_arch_init();
    }

#ifdef HAVE_DINPUT
    if ((joystick_inited == WIN_JOY_DINPUT) && (joystick_port_map[3] >= JOYDEV_HW1)) {
        joystick_di_close(3);
    }

    if ((joystick_inited == WIN_JOY_DINPUT) && (dev >= JOYDEV_HW1)) {
        if (joystick_di_open(3, dev)) {
            joystick_port_map[3] = dev;
        }
    } else
#endif
    {
        joystick_port_map[3] = dev;
    }

    return 0;
}

static int set_joystick_fire1_speed(int speed, void *param)
{
    if (speed < 1) {
        speed = 1;
    }
    if (speed > 32) {
        speed = 32;
    }

    joystick_fire_speed[0] = speed;

    return 0;
}

static int set_joystick_fire2_speed(int speed, void *param)
{
    if (speed < 1) {
        speed = 1;
    }
    if (speed > 32) {
        speed = 32;
    }

    joystick_fire_speed[1] = speed;

    return 0;
}

static int set_joystick_fire3_speed(int speed, void *param)
{
    if (speed < 1) {
        speed = 1;
    }
    if (speed > 32) {
        speed = 32;
    }

    joystick_fire_speed[2] = speed;

    return 0;
}

static int set_joystick_fire4_speed(int speed, void *param)
{
    if (speed < 1) {
        speed = 1;
    }
    if (speed > 32) {
        speed = 32;
    }

    joystick_fire_speed[3] = speed;

    return 0;
}

static int set_joystick_fire1_axis(int axis, void *param)
{
    if (axis < 0) {
        axis = 0;
    }

    joystick_fire_axis[0] = axis;

    return 0;
}

static int set_joystick_fire2_axis(int axis, void *param)
{
    if (axis < 0) {
        axis = 0;
    }

    joystick_fire_axis[1] = axis;

    return 0;
}

static int set_joystick_fire3_axis(int axis, void *param)
{
    if (axis < 0) {
        axis = 0;
    }

    joystick_fire_axis[2] = axis;

    return 0;
}

static int set_joystick_fire4_axis(int axis, void *param)
{
    if (axis < 0) {
        axis = 0;
    }

    joystick_fire_axis[3] = axis;

    return 0;
}

static int set_joystick_autofire1_button(int button, void *param)
{
    if (button < 0) {
        button = 0;
    }

    joystick_autofire_button[0] = button;

    return 0;
}

static int set_joystick_autofire2_button(int button, void *param)
{
    if (button < 0) {
        button = 0;
    }

    joystick_autofire_button[1] = button;

    return 0;
}

static int set_joystick_autofire3_button(int button, void *param)
{
    if (button < 0) {
        button = 0;
    }

    joystick_autofire_button[2] = button;

    return 0;
}

static int set_joystick_autofire4_button(int button, void *param)
{
    if (button < 0) {
        button = 0;
    }

    joystick_autofire_button[3] = button;

    return 0;
}

static int set_joystick_fire1_button(int button, void *param)
{
    if (button < 0) {
        button = 0;
    }

    joystick_fire_button[0] = button;

    return 0;
}

static int set_joystick_fire2_button(int button, void *param)
{
    if (button < 0) {
        button = 0;
    }

    joystick_fire_button[1] = button;

    return 0;
}

static int set_joystick_fire3_button(int button, void *param)
{
    if (button < 0) {
        button = 0;
    }

    joystick_fire_button[2] = button;

    return 0;
}

static int set_joystick_fire4_button(int button, void *param)
{
    if (button < 0) {
        button = 0;
    }

    joystick_fire_button[3] = button;

    return 0;
}

static const resource_int_t resources_int[] = {
    { "JoyDevice1", JOYDEV_NONE, RES_EVENT_NO, NULL,
      &joystick_port_map[0], set_joystick_device_1, NULL },
    { "JoyDevice2", JOYDEV_NONE, RES_EVENT_NO, NULL,
      &joystick_port_map[1], set_joystick_device_2, NULL },
    { "JoyDevice3", JOYDEV_NONE, RES_EVENT_NO, NULL,
      &joystick_port_map[2], set_joystick_device_3, NULL },
    { "JoyDevice4", JOYDEV_NONE, RES_EVENT_NO, NULL,
      &joystick_port_map[3], set_joystick_device_4, NULL },
    { "JoyAutofire1Speed", 16, RES_EVENT_NO, NULL,
      &joystick_fire_speed[0], set_joystick_fire1_speed, NULL },
    { "JoyAutofire1Axis", 0, RES_EVENT_NO, NULL,
      &joystick_fire_axis[0], set_joystick_fire1_axis, NULL },
    { "JoyAutofire1Button", 0, RES_EVENT_NO, NULL,
      &joystick_autofire_button[0], set_joystick_autofire1_button, NULL },
    { "JoyAutofire2Speed", 16, RES_EVENT_NO, NULL,
      &joystick_fire_speed[1], set_joystick_fire2_speed, NULL },
    { "JoyAutofire2Axis", 0, RES_EVENT_NO, NULL,
      &joystick_fire_axis[1], set_joystick_fire2_axis, NULL },
    { "JoyAutofire2Button", 0, RES_EVENT_NO, NULL,
      &joystick_autofire_button[1], set_joystick_autofire2_button, NULL },
    { "JoyAutofire3Speed", 16, RES_EVENT_NO, NULL,
      &joystick_fire_speed[2], set_joystick_fire3_speed, NULL },
    { "JoyAutofire3Axis", 0, RES_EVENT_NO, NULL,
      &joystick_fire_axis[2], set_joystick_fire3_axis, NULL },
    { "JoyAutofire3Button", 0, RES_EVENT_NO, NULL,
      &joystick_autofire_button[2], set_joystick_autofire3_button, NULL },
    { "JoyAutofire4Speed", 16, RES_EVENT_NO, NULL,
      &joystick_fire_speed[3], set_joystick_fire4_speed, NULL },
    { "JoyAutofire4Axis", 0, RES_EVENT_NO, NULL,
      &joystick_fire_axis[3], set_joystick_fire4_axis, NULL },
    { "JoyAutofire4Button", 0, RES_EVENT_NO, NULL,
      &joystick_autofire_button[3], set_joystick_autofire4_button, NULL },
    { "JoyFire1Button", 0, RES_EVENT_NO, NULL,
      &joystick_fire_button[0], set_joystick_fire1_button, NULL },
    { "JoyFire2Button", 0, RES_EVENT_NO, NULL,
      &joystick_fire_button[1], set_joystick_fire2_button, NULL },
    { "JoyFire3Button", 0, RES_EVENT_NO, NULL,
      &joystick_fire_button[2], set_joystick_fire3_button, NULL },
    { "JoyFire4Button", 0, RES_EVENT_NO, NULL,
      &joystick_fire_button[3], set_joystick_fire4_button, NULL },
    { NULL }
};

int joystick_arch_init_resources(void)
{
    return resources_register_int(resources_int);
}

/* ------------------------------------------------------------------------- */

static const cmdline_option_t joydev1cmdline_options[] = {
    { "-joydev1", SET_RESOURCE, 1,
      NULL, NULL, "JoyDevice1", NULL,
      USE_PARAM_ID, USE_DESCRIPTION_ID,
      IDS_P_NUMBER, IDS_SET_INPUT_JOYSTICK_1,
      NULL, NULL },
    { NULL }
};

static const cmdline_option_t joydev2cmdline_options[] = {
    { "-joydev2", SET_RESOURCE, 1,
      NULL, NULL, "JoyDevice2", NULL,
      USE_PARAM_ID, USE_DESCRIPTION_ID,
      IDS_P_NUMBER, IDS_SET_INPUT_JOYSTICK_2,
      NULL, NULL },
    { NULL }
};

static const cmdline_option_t joydev3cmdline_options[] = {
    { "-extrajoydev1", SET_RESOURCE, 1,
      NULL, NULL, "JoyDevice3", NULL,
      USE_PARAM_ID, USE_DESCRIPTION_ID,
      IDS_P_NUMBER, IDS_SET_INPUT_EXTRA_JOYSTICK_1,
      NULL, NULL },
    { NULL }
};

static const cmdline_option_t joydev4cmdline_options[] = {
    { "-extrajoydev2", SET_RESOURCE, 1,
      NULL, NULL, "JoyDevice4", NULL,
      USE_PARAM_ID, USE_DESCRIPTION_ID,
      IDS_P_NUMBER, IDS_SET_INPUT_EXTRA_JOYSTICK_2,
      NULL, NULL },
    { NULL }
};

int joystick_init_cmdline_options(void)
{
    switch (machine_class) {
        case VICE_MACHINE_VSID:
            break;
        case VICE_MACHINE_C64:
        case VICE_MACHINE_C64SC:
        case VICE_MACHINE_C128:
        case VICE_MACHINE_C64DTV:
            if (cmdline_register_options(joydev1cmdline_options) < 0) {
                return -1;
            }
            if (cmdline_register_options(joydev2cmdline_options) < 0) {
                return -1;
            }
            if (cmdline_register_options(joydev3cmdline_options) < 0) {
                return -1;
            }
            return cmdline_register_options(joydev4cmdline_options);
            break;
        case VICE_MACHINE_PET:
        case VICE_MACHINE_CBM6x0:
            if (cmdline_register_options(joydev3cmdline_options) < 0) {
                return -1;
            }
            return cmdline_register_options(joydev4cmdline_options);
            break;
        case VICE_MACHINE_CBM5x0:
            if (cmdline_register_options(joydev1cmdline_options) < 0) {
                return -1;
            }
            return cmdline_register_options(joydev2cmdline_options);
            break;
        case VICE_MACHINE_PLUS4:
            if (cmdline_register_options(joydev1cmdline_options) < 0) {
                return -1;
            }
            if (cmdline_register_options(joydev2cmdline_options) < 0) {
                return -1;
            }
            return cmdline_register_options(joydev3cmdline_options);
            break;
        case VICE_MACHINE_VIC20:
            if (cmdline_register_options(joydev1cmdline_options) < 0) {
                return -1;
            }
            return cmdline_register_options(joydev3cmdline_options);
            break;
        default:
            assert("Unknown machine_class in joystick_init_cmdline_options" == NULL);
            return -1;
    }
    return 0;
}

/* ------------------------------------------------------------------------- */

#ifdef HAVE_DINPUT
static BOOL CALLBACK EnumCallBack(LPCDIDEVICEINSTANCE lpddi, LPVOID pvref)
{
    JoyInfo *new_joystick;

    new_joystick = lib_malloc(sizeof(JoyInfo));
    new_joystick->next = NULL;
    memcpy(&new_joystick->guid, &lpddi->guidInstance, sizeof(GUID));
    new_joystick->name = lib_stralloc(lpddi->tszInstanceName);
    new_joystick->axes = NULL;
    new_joystick->buttons = NULL;

    if (joystick_list == NULL) {
        joystick_list = new_joystick;
    } else {
        JoyInfo *s;
        s = joystick_list;
        while (s->next != NULL) {
            s = s->next;
        }
        s->next = new_joystick;
    }
    return DIENUM_CONTINUE;
}
#endif

int joy_arch_init(void)
{
#ifdef HAVE_DINPUT
    LPDIRECTINPUT di = get_directinput_handle();
#endif
    if (joystick_inited == WIN_JOY_UNINIT) {
#ifdef HAVE_DINPUT
        if (di) {
            IDirectInput_EnumDevices(di, DIDEVTYPE_JOYSTICK, EnumCallBack, NULL, DIEDFL_ALLDEVICES);
            joystick_inited = WIN_JOY_DINPUT;
        }
        else
#endif
        {
            joystick_inited = WIN_JOY_WINMM;
            if (joy_winmm_list == NULL) {
                joy_winmm_priv_t** joy_add = &joy_winmm_list;
                UINT wNumDevs = joyGetNumDevs();
                UINT i;
                MMRESULT result;

                for (i = JOYSTICKID1; i < wNumDevs; i++) {
                    joy_winmm_priv_t* priv = lib_malloc(sizeof(joy_winmm_priv_t));
                    result = joyGetDevCaps(i, &priv->joy_caps, sizeof(priv->joy_caps));
                    if (result != JOYERR_NOERROR) {
                        lib_free(priv);
                    } else {
                        priv->uJoyID = i;
                        priv->next = NULL;
                        *joy_add = priv;
                        joy_add = &priv->next;
                    }
                }
            }
        }
    }

    return 0;
}

static void joystick_release_winmm_joysticks()
{
    joy_winmm_priv_t* joy_list = joy_winmm_list;
    
    while (joy_list != NULL) {
        joy_winmm_priv_t* joy_remove = joy_list;
        joy_list = joy_list->next;
        free(joy_remove);
    }
}

int joystick_close(void)
{
#ifdef HAVE_DINPUT
    if ((joystick_inited == WIN_JOY_DINPUT) && (joystick_port_map[0] >= JOYDEV_HW1)) {
        joystick_di_close(0);
    }
    if ((joystick_inited == WIN_JOY_DINPUT) && (joystick_port_map[1] >= JOYDEV_HW1)) {
        joystick_di_close(1);
    }
    if ((joystick_inited == WIN_JOY_DINPUT) && (joystick_port_map[2] >= JOYDEV_HW1)) {
        joystick_di_close(2);
    }
    if ((joystick_inited == WIN_JOY_DINPUT) && (joystick_port_map[3] >= JOYDEV_HW1)) {
        joystick_di_close(3);
    }
    joystick_release_joysticks();
#endif

    joystick_release_winmm_joysticks();
    joystick_inited = WIN_JOY_UNINIT;
    return 0;
}

static JOYINFOEX joy_info;

#ifdef HAVE_DINPUT
static BYTE joystick_di5_update(int joy_no)
{
    BYTE value;
    int i;
    DIPROPRANGE prop;
    UINT amin;
    UINT amax;
    DWORD apos;
    DIJOYSTATE js;
    JoyInfo *joy;
    JoyButton *button;
    int afire_button;
    int fire_button;

    value = 0;

    IDirectInputDevice2_Poll(joystick_di_devices2[joy_no]);
    IDirectInputDevice_GetDeviceState(joystick_di_devices[joy_no], sizeof(DIJOYSTATE), &js);

    //  Get boundary values for X axis
    prop.diph.dwSize = sizeof(DIPROPRANGE);
    prop.diph.dwHeaderSize = sizeof(DIPROPHEADER);
    prop.diph.dwObj = 0;    // Offset of X axis
    prop.diph.dwHow = DIPH_BYOFFSET;
    IDirectInputDevice_GetProperty(joystick_di_devices[joy_no], DIPROP_RANGE, (DIPROPHEADER*)&prop);
    if (js.lX <= prop.lMin + (prop.lMax - prop.lMin) / 4) {
        value |= 4;
    }
    if (js.lX >= prop.lMin + (prop.lMax - prop.lMin) / 4 * 3) {
        value |= 8;
    }

    //  Get boundary values for Y axis
    prop.diph.dwSize = sizeof(DIPROPRANGE);
    prop.diph.dwHeaderSize = sizeof(DIPROPHEADER);
    prop.diph.dwObj = 4;    // Offset of Y axis
    prop.diph.dwHow = DIPH_BYOFFSET;
    IDirectInputDevice_GetProperty(joystick_di_devices[joy_no], DIPROP_RANGE, (DIPROPHEADER*)&prop);
    if (js.lY <= prop.lMin + (prop.lMax - prop.lMin) / 4) {
        value |= 1;
    }
    if (js.lY >= prop.lMin + (prop.lMax - prop.lMin) / 4 * 3) {
        value |= 2;
    }

    //  Find the joystick object

    afire_button = -1;
    fire_button = -1;
    joy = joystick_list;
    i = 0;
    while (joy && i < joystick_port_map[joy_no] - JOYDEV_HW1) {
        joy = joy->next;
        i++;
    }
    if (joy && (joystick_autofire_button[joy_no] > 0)) {
        button = joy->buttons;
        i = 0;
        while (button && i < joystick_autofire_button[joy_no] - 1) {
            button = button->next;
            i++;
        }
        if (button) {
            afire_button = button->dwOffs - 48;
        }
    }
    if ((afire_button >= 32) || (afire_button < -1)) {
        afire_button = -1;
    }
    if (joy && (joystick_fire_button[joy_no] > 0)) {
        button = joy->buttons;
        i = 0;
        while (button && i < joystick_fire_button[joy_no] - 1) {
            button = button->next;
            i++;
        }
        if (button) {
            fire_button = button->dwOffs - 48;
        }
    }
    if ((fire_button >= 32) || (fire_button < -1)) {
        fire_button = -1;
    }

    //	If fire button is not in valid range [0..31] then it means every button is
    //	treated as fire button, otherwise the only one selected.
    if (fire_button != -1) {
        if ((fire_button != afire_button) && (js.rgbButtons[fire_button] & 0x80)) {
            value |= 16;
        }
    } else {
        for (i = 0; i < 32; i++) {
            if ((i != afire_button) && (js.rgbButtons[i] & 0x80)) {
                value |= 16;
            }
        }
    }
    if ((afire_button != -1) && (js.rgbButtons[afire_button] & 0x80)) {
        if (joystick_fire_axis[joy_no]) {
            amin = 0;
            amax = 32;
            apos = 16;
            if (joy) {
                //  Find axis
                JoyAxis *axis;

                axis = joy->axes;
                i = 0;
                while (axis && i < joystick_fire_axis[joy_no] - 1) {
                    axis = axis->next;
                    i++;
                }
                if (axis) {
                    //  Get boundary values for axis
                    prop.diph.dwSize = sizeof(DIPROPRANGE);
                    prop.diph.dwHeaderSize = sizeof(DIPROPHEADER);
                    prop.diph.dwObj = axis->id;
                    prop.diph.dwHow = DIPH_BYID;
                    IDirectInputDevice_GetProperty(joystick_di_devices[joy_no], DIPROP_RANGE, (DIPROPHEADER*)&prop);
                    amin = prop.lMin;
                    amax = prop.lMax;
                    apos = *(DWORD*)(((BYTE*)&js) + axis->dwOffs);
                }
            }
            value |= maincpu_clk / (((amin + apos) * 0x2000) / (amax - amin) + 1) & 16;
        } else {
            value |= (maincpu_clk / (joystick_fire_speed[joy_no] * 0x100)) & 16;
        }
    }
    return value;
}
#endif

void joystick_update(void)
{
    BYTE value;
    MMRESULT result;
    int idx;
    DWORD addflag;
    UINT amin;
    UINT amax;
    DWORD apos;
    int afire_button;
    int fire_button;
    int j;

#ifdef HAVE_DINPUT
    if (joystick_inited == WIN_JOY_DINPUT) {
        int i;
        for (i = 0; i < 4; i++) {
            if (joystick_port_map[i] >= JOYDEV_HW1) {
                joystick_set_value_absolute(i + 1, joystick_di5_update(i));
            }
        }
    } else
#endif
    {
        joy_winmm_priv_t* current_joy = joy_winmm_list;
        int index = JOYDEV_HW1;
        
        while (current_joy) {
            idx = -1;
            if (joystick_port_map[0] == index && idx == -1) {
                idx = 0;
            }
            if (joystick_port_map[1] == index && idx == -1) {
                idx = 1;
            }
            if (joystick_port_map[2] == index && idx == -1) {
                idx = 2;
            }
            if (joystick_port_map[3] == index && idx == -1) {
                idx = 3;
            }
            if (idx != -1) {
                switch (joystick_fire_axis[idx]) {
                    case 1:
                        addflag = JOY_RETURNZ;
                        break;
                    case 2:
                        addflag = JOY_RETURNV;
                        break;
                    case 3:
                        addflag = JOY_RETURNU;
                        break;
                    case 4:
                        addflag = JOY_RETURNR;
                        break;
                    default:
                        addflag = 0;
                }
                joy_info.dwFlags = JOY_RETURNBUTTONS | JOY_RETURNCENTERED | JOY_RETURNX | JOY_RETURNY | addflag;
                value = 0;
                joy_info.dwSize = sizeof(JOYINFOEX);
                result = joyGetPosEx(current_joy->uJoyID, &joy_info);
                if (result == JOYERR_NOERROR) {
                    if (joy_info.dwXpos <= current_joy->joy_caps.wXmin + (current_joy->joy_caps.wXmax - current_joy->joy_caps.wXmin) / 4) {
                        value |= 4;
                    }
                    if (joy_info.dwXpos >= current_joy->joy_caps.wXmin + (current_joy->joy_caps.wXmax - current_joy->joy_caps.wXmin) / 4 * 3) {
                        value |= 8;
                    }
                    if (joy_info.dwYpos <= current_joy->joy_caps.wYmin + (current_joy->joy_caps.wYmax - current_joy->joy_caps.wYmin) / 4) {
                        value |= 1;
                    }
                    if (joy_info.dwYpos >= current_joy->joy_caps.wYmin + (current_joy->joy_caps.wYmax - current_joy->joy_caps.wYmin) / 4 * 3) {
                        value |= 2;
                    }
                    afire_button = joystick_autofire_button[idx] - 1;
                    fire_button = joystick_fire_button[idx] - 1;
                    if (fire_button != -1) {
                        if ((fire_button != afire_button) && (joy_info.dwButtons & (1 << fire_button))) {
                            value |= 16;
                        }
                    } else {
                        for (j = 0; j < 32; j++) {
                            if ((j != afire_button) && (joy_info.dwButtons & (1 << j))) {
                                value |= 16;
                            }
                        }
                    }
                    if ((afire_button != -1) && (joy_info.dwButtons & (1 << afire_button))) {
                        if ((joystick_fire_axis[idx]) && (joy_info.dwFlags & addflag)) {
                            switch(joystick_fire_axis[idx]) {
                                case 1:
                                    amin = current_joy->joy_caps.wZmin;
                                    amax = current_joy->joy_caps.wZmax;
                                    apos = joy_info.dwZpos;
                                    break;
                                case 2:
                                    amin = current_joy->joy_caps.wVmin;
                                    amax = current_joy->joy_caps.wVmax;
                                    apos = joy_info.dwVpos;       
                                    break;
                                case 3:
                                    amin = current_joy->joy_caps.wUmin;
                                    amax = current_joy->joy_caps.wUmax;
                                    apos = joy_info.dwUpos;
                                    break;
                                case 4:
                                    amin = current_joy->joy_caps.wRmin;
                                    amax = current_joy->joy_caps.wRmax;
                                    apos = joy_info.dwRpos;
                                    break;
                                default:
                                    amin = 0;
                                    amax = 32;
                                    apos = 16;
                                    break;
                            }
                            value |= maincpu_clk / (((amin + apos) * 0x2000) / (amax - amin) + 1) & 16;
                        } else {
                            value |= (maincpu_clk / (joystick_fire_speed[idx] * 0x100)) & 16;
                        }
                    }
                    joystick_set_value_absolute(idx + 1, value);
                }
            }
            current_joy = current_joy->next;
            index++;
        }
    }
}

#ifdef HAVE_DINPUT
void joystick_calibrate(HWND hwnd)
{
    LPDIRECTINPUT di = get_directinput_handle();

    if (di != NULL) {
        IDirectInput_RunControlPanel(di,hwnd,0);
    }
}
#endif

void joystick_ui_get_device_list(HWND joy_hwnd)
{
#ifdef HAVE_DINPUT
    if (joystick_inited == WIN_JOY_DINPUT) {
        JoyInfo *joy = joystick_list;

        while (joy) {
            SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)joy->name);
            joy = joy->next;
        }
    } else
#endif
    if (joystick_inited == WIN_JOY_WINMM) {
        joy_winmm_priv_t* joy = joy_winmm_list;

        while (joy) {
            char joyname[1024];

            snprintf(joyname, sizeof(joyname), "PC joystick #%u", joy->uJoyID);
            SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)joyname);
            joy = joy->next;
        }
    }
}

void joystick_ui_get_autofire_axes(HWND joy_hwnd, int device)
{
#ifdef HAVE_DINPUT
    int i;
    JoyInfo *joy;
    JoyAxis *axis;

    if (joystick_inited == WIN_JOY_DINPUT) {
        device = device - JOYDEV_HW1;
        joy = joystick_list;
        i = 0;
        while (joy && i < device) {
            joy = joy->next;
            i++;
        }
        if (joy) {
            axis = joy->axes;
            while (axis) {
                SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)axis->name);
                axis = axis->next;
            }
        }
    } else
#endif
    {
        SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)"Z-axis");
        SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)"V-axis");
        SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)"U-axis");
        SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)"R-axis");
    }
}

void joystick_ui_get_autofire_buttons(HWND joy_hwnd, int device)
{
#ifdef HAVE_DINPUT
    int i;
    JoyInfo *joy;
    JoyButton *button;

    if (joystick_inited == WIN_JOY_DINPUT) {
        device = device - JOYDEV_HW1;
        joy = joystick_list;
        i = 0;
        while (joy && i < device) {
            joy = joy->next;
            i++;
        }
        if (joy) {
            button = joy->buttons;
            while (button) {
                SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)button->name);
                button = button->next;
            }
        }
    } else
#endif
    {
        SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)"Button 1");
        SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)"Button 2");
        SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)"Button 3");
        SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)"Button 4");
        SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)"Button 5");
        SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)"Button 6");
        SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)"Button 7");
        SendMessage(joy_hwnd, CB_ADDSTRING, 0, (LPARAM)"Button 8");
    }
}

char joystick_uses_direct_input(void)
{
#ifdef HAVE_DINPUT
    return (joystick_inited == WIN_JOY_DINPUT);
#else
    return 0;
#endif
}
