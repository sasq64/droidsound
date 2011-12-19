/*
 * ui_sound.cc - Sound settings
 *
 * Written by
 *  Andreas Matthies <andreas.matthies@gmx.net>
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
 
#include <Box.h>
#include <CheckBox.h>
#include <RadioButton.h>
#include <string.h>
#include <Window.h>

extern "C" {
#include "machine.h" 
#include "resources.h"
#include "sound.h"
#include "ui.h"
#include "ui_sound.h"
#include "vsync.h"
}

static int ui_sound_freq_count = 3;
static int ui_sound_freq[] = {
    11025,
    22050,
    44100
};

static int ui_sound_buffer_count = 5;
static int ui_sound_buffer[] = {
    100,
    150,
    200,
    300,
    350
};

static int ui_sound_adjusting_count = 3;
static int ui_sound_adjusting[] = {
    SOUND_ADJUST_FLEXIBLE,
    SOUND_ADJUST_ADJUSTING,
    SOUND_ADJUST_EXACT
};

static char *ui_sound_adjusting_text[] = {
    "Flexible",
    "Adjusting",
    "Exact"
};

static int ui_sound_fragment_size_count = 3;
static int ui_sound_fragment_size[] = {
    SOUND_FRAGMENT_SMALL,
    SOUND_FRAGMENT_MEDIUM,
    SOUND_FRAGMENT_LARGE
};

static char *ui_sound_fragment_size_text[] = {
    "Small",
    "Medium",
    "Large"
};

class SoundWindow : public BWindow {
    public:
        SoundWindow();
        ~SoundWindow();
        virtual void MessageReceived(BMessage *msg);
};	

static SoundWindow *soundwindow = NULL;

SoundWindow::SoundWindow() 
    : BWindow(BRect(50, 50, 450, 190), "Sound settings", B_TITLED_WINDOW_LOOK, B_MODAL_APP_WINDOW_FEEL, B_NOT_ZOOMABLE | B_NOT_RESIZABLE) 
{
    BView *background;
    BRect r;
    BBox *box;
    BMessage *msg;
    BRadioButton *radiobutton;
    char str[128];
    int i;
    int res_value;

    r = Bounds();
    background = new BView(r, "backview", B_FOLLOW_NONE, B_WILL_DRAW);
    background->SetViewColor(220, 220, 220, 0);
    AddChild(background);

    /* Frequency */
    r = Bounds();
    r.right = r.left + r.Width() / 4;
    r.InsetBy(5, 5);
    box = new BBox(r, "Frequency");
    box->SetViewColor(220, 220, 220, 0);
    box->SetLabel("Frequency");

    resources_get_int("SoundSampleRate", &res_value);

    for (i = 0; i < ui_sound_freq_count; i++) {
        msg = new BMessage(MESSAGE_SOUND_FREQ);
        msg->AddInt32("frequency", ui_sound_freq[i]);
        sprintf(str, "%d", ui_sound_freq[i]);
        radiobutton = new BRadioButton(BRect(10, 20 + 20 * i, r.Width() - 10, 35 + 20 * i), str, str, msg);
        radiobutton->SetValue(res_value == ui_sound_freq[i]);
        box->AddChild(radiobutton);
    }
    background->AddChild(box);

    /* Buffer */
    r = Bounds();
    r.right = r.left + r.Width() / 4;
    r.OffsetBy(r.Width(), 0);
    r.InsetBy(5, 5);
    box = new BBox(r, "Buffer Size");
    box->SetViewColor(220, 220, 220, 0);
    box->SetLabel("Buffer Size");

    resources_get_int("SoundBufferSize", &res_value);

    for (i = 0; i < ui_sound_buffer_count; i++) {
        msg = new BMessage(MESSAGE_SOUND_BUFF);
        msg->AddInt32("buffer", ui_sound_buffer[i]);
        sprintf(str, "%d", ui_sound_buffer[i]);
        radiobutton = new BRadioButton(BRect(10, 20 + 20 * i, r.Width() - 10, 35 + 20 * i), str, str, msg);
        radiobutton->SetValue(res_value == ui_sound_buffer[i]);
        box->AddChild(radiobutton);
    }
    background->AddChild(box);

    /* Fragment size */
    r = Bounds();
    r.right = r.left + r.Width() / 4;
    r.OffsetBy(2 * r.Width(), 0);
    r.InsetBy(5, 5);
    r.bottom -= 20;
    box = new BBox(r, "Fragment Size");
    box->SetViewColor(220, 220, 220, 0);
    box->SetLabel("Fragment Size");

    resources_get_int("SoundFragmentSize", &res_value);

    for (i = 0; i < ui_sound_fragment_size_count; i++) {
        msg = new BMessage(MESSAGE_SOUND_FRAG);
        msg->AddInt32("fragment", i);
        radiobutton = new BRadioButton(BRect(10, 20 + 20 * i, r.Width() - 10, 35 + 20 * i), ui_sound_fragment_size_text[i], ui_sound_fragment_size_text[i], msg);
        radiobutton->SetValue(res_value == ui_sound_fragment_size[i]);
        box->AddChild(radiobutton); 	 
    }
    background->AddChild(box);

    /* Sync method */
    r = Bounds();
    r.right = r.left + r.Width() / 4;
    r.OffsetBy(3 * r.Width(), 0);
    r.InsetBy(5, 5);
    r.bottom -= 20;
    box = new BBox(r, "Sync Method");
    box->SetViewColor(220, 220, 220, 0);
    box->SetLabel("Sync Method");

    resources_get_int("SoundSpeedAdjustment", &res_value);
	
    for (i = 0; i < ui_sound_adjusting_count; i++) {
        msg = new BMessage(MESSAGE_SOUND_SYNC);
        msg->AddInt32("sync", i);
        radiobutton = new BRadioButton(BRect(10, 20 + 20 * i, r.Width() - 10, 35 + 20 * i), ui_sound_adjusting_text[i], ui_sound_adjusting_text[i], msg);
        radiobutton->SetValue(res_value == i);
        box->AddChild(radiobutton);
    }
    background->AddChild(box);

    Show();
}

SoundWindow::~SoundWindow() 
{
    soundwindow = NULL;	
}

void SoundWindow::MessageReceived(BMessage *msg)
{
    int32 res_value;

    switch (msg->what) {
        case MESSAGE_SOUND_FREQ:
            msg->FindInt32("frequency", &res_value);
            resources_set_int("SoundSampleRate", res_value);
            break;
        case MESSAGE_SOUND_BUFF:
            msg->FindInt32("buffer", &res_value);
            resources_set_int("SoundBufferSize", res_value);
            break;
        case MESSAGE_SOUND_SYNC:
            msg->FindInt32("sync", &res_value);
            resources_set_int("SoundSpeedAdjustment", res_value);
            break;
        case MESSAGE_SOUND_FRAG:
            msg->FindInt32("fragment", &res_value);
            resources_set_int("SoundFragmentSize", res_value);
            break;
        default:
            BWindow::MessageReceived(msg);
    }
}

void ui_sound()
{
    thread_id soundthread;
    status_t exit_value;

    if (soundwindow != NULL) {
        return;
    }

    soundwindow = new SoundWindow;

    vsync_suspend_speed_eval();

    /* wait until window closed */
    soundthread = soundwindow->Thread();
    wait_for_thread(soundthread, &exit_value);
}
