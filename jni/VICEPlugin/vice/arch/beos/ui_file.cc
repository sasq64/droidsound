/*
 * ui_file.cc - UI stuff dealing with files
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

#include <Application.h>
#include <Button.h>
#include <CheckBox.h>
#include <FilePanel.h>
#include <Font.h>
#include <ListView.h>
#include <Message.h>
#include <Path.h>
#include <ScrollView.h>
#include <stdio.h>
#include <string.h>
#include <View.h>
#include <Window.h>

extern "C" {
#include "attach.h"
#include "autostart.h"
#include "c64ui.h"
#include "cartridge.h"
#include "constants.h"
#include "diskcontents.h"
#include "imagecontents.h"
#include "interrupt.h"
#include "lib.h"
#include "machine.h"
#include "resources.h"
#include "tape.h"
#include "tapecontents.h"
#include "ui.h"
#include "uiapi.h"
#include "ui_file.h"
#include "util.h"
#include "vic20ui.h"
#include "vicemenu.h"
#include "vicewindow.h"
#include "vsync.h"
}

extern ViceWindow *windowlist[];

static int last_fileparam[2]; /* 0=filepanel, 1=savepanel */
static int last_filetype[2];
static BCheckBox *cb_readonly;

static image_contents_t *read_disk_or_tape_image_contents(const char *name)
{
    image_contents_t *contents;

    contents = diskcontents_filesystem_read(name);
    if (contents == NULL) {
        contents = tapecontents_read(name);
    }
    return contents;
}

static void create_content_list(BListView *contentlist, image_contents_t *contents)
{
    char *start;
    image_contents_file_list_t *p = contents->file_list;

    while (contentlist->CountItems()) {
        BListItem *item = contentlist->FirstItem();
        contentlist->RemoveItem(item);
        delete item;
    }

    start = image_contents_to_string(contents, 0);
    contentlist->AddItem(new BStringItem(start));
    lib_free(start);

    if (p == NULL) {
        contentlist->AddItem(new BStringItem("(EMPTY IMAGE.)"));
    } else do {
        start = image_contents_file_to_string(p, 0);
        contentlist->AddItem(new BStringItem(start));
        lib_free(start);
    } while ((p = p->next) != NULL);

    if (contents->blocks_free >= 0) {
        start = lib_msprintf("%d BLOCKS FREE.", contents->blocks_free);
        contentlist->AddItem(new BStringItem(start));
        lib_free(start);
    }
}

VicePreview::VicePreview(BPoint origin, ViceFilePanel *f)
    : BWindow(BRect(origin.x, origin.y, origin.x + 300, origin.y + 200),
    "Image Contents", B_MODAL_WINDOW_LOOK, B_FLOATING_APP_WINDOW_FEEL, B_AVOID_FOCUS)
{
    BView *background;
    BRect r;
    BFont font(be_fixed_font);

    father = f;         

    r = Bounds();
    background = new BView(r, "backview", B_FOLLOW_NONE, B_WILL_DRAW);
    background->SetViewColor(220, 220, 220, 0);
    AddChild(background);

    r.InsetBy(10, 10);
    r.right -= 80;
    contentlist = new BListView(r, "contents", B_SINGLE_SELECTION_LIST);
    contentlist->SetInvocationMessage(new BMessage(AUTOSTART_MESSAGE));

    font.SetSize(10.0);
    contentlist->SetFont(&font);

    background->AddChild(new BScrollView("scroll_contents", contentlist, B_FOLLOW_LEFT | B_FOLLOW_TOP, 0, false, true));
        
    background->AddChild(new BButton(BRect(r.right + 20, 10, r.right + 80, 30), "Autostart", "Autostart", new BMessage(AUTOSTART_MESSAGE)));

    Minimize(true);
    Show();
    Hide();
}

void VicePreview::DisplayContent(image_contents_t *content)
{
    Lock();
    if (content) {
        if (IsHidden()) {
            Minimize(false);
            Show();
        }
        create_content_list(contentlist, content);
    } else {
        if (!IsHidden()) {
           Hide();
        }
    }
    Unlock();
}

void VicePreview::MessageReceived(BMessage *msg)
{
    int file_num;

    switch (msg->what) {
        case AUTOSTART_MESSAGE:
            file_num = contentlist->CurrentSelection();
            if (file_num >= 0) {
                father->Hide();
                autostart_autodetect(image_name, NULL, file_num, AUTOSTART_MODE_RUN);
            }
            break;
        default:
            BWindow::MessageReceived(msg);
    }
}

ViceFilePanel::ViceFilePanel(file_panel_mode mode, BMessenger* target, entry_ref* panel_directory, uint32 node_flavors, bool allow_multiple_selection)
    : BFilePanel(mode, target, panel_directory, node_flavors, allow_multiple_selection)
{
    if (mode == B_OPEN_PANEL) {
        /* readonly checkbox */
        if (Window()->Lock()) {
            BView *back = Window()->ChildAt(0);
            BRect rect = back->Bounds();

            rect.InsetBy(20, 20);
            rect.right = rect.left + 150;
            rect.top = rect.bottom - 10;
            cb_readonly = new BCheckBox(rect, "Attach read only", "Attach read only", NULL);
            cb_readonly->SetTarget(Messenger());
            Window()->Unlock();
        }

        /* create window for the previewlist */
        previewwindow = new VicePreview(BPoint(Window()->Frame().left, Window()->Frame().bottom), this);
    } else {
        previewwindow = NULL;
    }
}

void ViceFilePanel::WasHidden(void)
{
    if (previewwindow) {
        previewwindow->DisplayContent(NULL);
    }
}
        
void ViceFilePanel::SelectionChanged(void)
{
    entry_ref ref;
    BPath *path;

    Rewind();
    if (GetNextSelectedRef(&ref) != B_ENTRY_NOT_FOUND && previewwindow) {
        path = new BPath(&ref);
        if (path->Path() && read_disk_or_tape_image_contents(path->Path())) {
            strncpy(previewwindow->image_name, path->Path(), 255); 
            previewwindow->DisplayContent(read_disk_or_tape_image_contents(path->Path()));
            previewwindow->MoveTo(BPoint(Window()->Frame().left, Window()->Frame().bottom+5));
            Window()->SendBehind(previewwindow);
        } else {
            previewwindow->DisplayContent(NULL);
        }
        delete path;
    }

    BFilePanel::SelectionChanged();
}

void ui_select_file(file_panel_mode panelmode, filetype_t filetype, void *fileparam)
{
    ViceFilePanel *filepanel;
    int panelnr; /* = (panelmode == B_OPEN_PANEL ? 0 : 1); */
    char title[40];

    if (panelmode == B_OPEN_PANEL) {
        filepanel = windowlist[0]->filepanel;
        panelnr = 0;
    } else {
        filepanel = windowlist[0]->savepanel;
        panelnr = 1;
    }

    sprintf(title,"VICE filepanel"); /* default */

    /* Modify the panel */
    /* first we may remove the readonly checkbox */
    if (filepanel->Window()->Lock()) {
        filepanel->Window()->ChildAt(0)->RemoveChild(cb_readonly);
        filepanel->Window()->Unlock();
    }
    if (filetype == DISK_FILE) {
        static BMessage msg = BMessage(MESSAGE_ATTACH_READONLY);
        int n;

        /* attach readonly checkbox */
        if (filepanel->Window()->Lock()) {
            filepanel->Window()->ChildAt(0)->AddChild(cb_readonly);
            msg.MakeEmpty();
            msg.AddInt32("device", *(int*)fileparam);
            cb_readonly->SetMessage(&msg);
            resources_get_int_sprintf("AttachDevice%dReadonly", &n, *(int*)fileparam);
            cb_readonly->SetValue(n);
            filepanel->Window()->Unlock();
        }

        sprintf(title, "Attach Disk %d", *(int*)fileparam);
        last_fileparam[panelnr] = *(int*)fileparam;
    }
    if (filetype == TAPE_FILE) {
        sprintf(title, "Attach Tape");
    }
    if (filetype == AUTOSTART_FILE) {
        sprintf(title, "Autostart");
    }
    if (filetype == AUTOSTART_DISK_IMAGE_FILE) {
        sprintf(title, "Autostart Disk Image");
    }
    if (filetype == SNAPSHOTSAVE_FILE) {
        sprintf(title, "Save snapshot");
    }
    if (filetype == SNAPSHOTLOAD_FILE) {
        sprintf(title, "Load snapshot");
    }
    if (filetype == C64_CARTRIDGE_FILE || filetype == VIC20_CARTRIDGE_FILE) {
        sprintf(title," Attach Cartridge (%s)", ((ui_cartridge_t*)fileparam)->cart_name);
        last_fileparam[panelnr] = ((ui_cartridge_t*)fileparam)->cart_type;
    }
    if (filetype == VSID_FILE) {
        sprintf(title, "Load psid file");
    }
    if (filetype == SNAPSHOT_HISTORY_START) {
        sprintf(title, "Select start snapshot");
    }
    if (filetype == SNAPSHOT_HISTORY_END) {
        sprintf(title, "Select end snapshot");
    }
    if (filetype == REU_FILE) {
        sprintf(title, "Select REU file");
    }
    if (filetype == GEORAM_FILE) {
        sprintf(title, "Select GEO-RAM file");
    }
    if (filetype == RAMCART_FILE) {
        sprintf(title, "Select RamCart file");
    }
    if (filetype == MAGICVOICE_FILE) {
        sprintf(title, "Select Magic Voice file");
    }
    if (filetype == DQBB_FILE) {
        sprintf(title, "Select DQBB file");
    }
    if (filetype == ISEPIC_FILE) {
        sprintf(title, "Select ISEPIC file");
    }
    if (filetype == PLUS60K_FILE) {
        sprintf(title, "Select +60K file");
    }
    if (filetype == PLUS256K_FILE) {
        sprintf(title, "Select +256K file");
    }
    if (filetype == C64_256K_FILE) {
        sprintf(title, "Select C64_256K file");
    }
    if (filetype == PETREU_FILE) {
        sprintf(title, "Select PET REU file");
    }
    if (filetype == PETDWW_FILE) {
        sprintf(title, "Select PET DWW file");
    }
    if (filetype == V364SPEECH_FILE) {
        sprintf(title, "Select V364 speech file");
    }
    if (filetype == MMC64_BIOS_FILE) {
        sprintf(title, "Select MMC64 BIOS file");
    }
    if (filetype == MMC64_IMAGE_FILE) {
        sprintf(title, "Select MMC64 image file");
    }
    if (filetype == MMCR_EEPROM_FILE) {
        sprintf(title, "Select MMC Replay EEPROM file");
    }
    if (filetype == MMCR_IMAGE_FILE) {
        sprintf(title, "Select MMC Replay image file");
    }
    if (filetype == C64DTV_ROM_FILE) {
        sprintf(title, "Select C64DTV ROM file");
    }
    if (filetype == EXPERT_FILE) {
        sprintf(title, "Select Expert Cartridge file");
    }
    if (filetype == IDE64_FILE1) {
        sprintf(title, "Select IDE64 HD #1 file");
    }
    if (filetype == IDE64_FILE2) {
        sprintf(title, "Select IDE64 HD #2 file");
    }
    if (filetype == IDE64_FILE3) {
        sprintf(title, "Select IDE64 HD #3 file");
    }
    if (filetype == IDE64_FILE4) {
        sprintf(title, "Select IDE64 HD #4 file");
    }
    if (filetype == PRINTER_OUTPUT_FILE1) {
        sprintf(title, "Select printer output #1");
    }
    if (filetype == PRINTER_OUTPUT_FILE2) {
        sprintf(title, "Select printer output #2");
    }
    if (filetype == PRINTER_OUTPUT_FILE3) {
        sprintf(title, "Select printer output #3");
    }
    if (filetype == AIFF_FILE) {
        sprintf(title, "Select AIFF Sound Recording file");
    }
    if (filetype == IFF_FILE) {
        sprintf(title, "Select IFF Sound Recording file");
    }
#ifdef USE_LAMEMP3
    if (filetype == MP3_FILE) {
        sprintf(title, "Select MP3 Sound Recording file");
    }
#endif
    if (filetype == VOC_FILE) {
        sprintf(title, "Select VOC Sound Recording file");
    }
    if (filetype == WAV_FILE) {
        sprintf(title,"Select WAV Sound Recording file");
    }
    if (filetype == VIC20_GENERIC_CART_FILE) {
        sprintf(title,"Select generic cartridge file");
    }
    if (filetype == VIC20_FP_FILE) {
        sprintf(title,"Select Vic Flash Plugin file");
    }
    if (filetype == VIC20_MEGACART_FILE) {
        sprintf(title,"Select Mega-Cart file");
    }
    if (filetype == VIC20_MEGACART_NVRAM_FILE) {
        sprintf(title,"Select Mega-Cart nvram file");
    }
    if (filetype == VIC20_FINAL_EXPANSION_FILE) {
        sprintf(title,"Select Final Expansion file");
    }
    if (filetype == VIC20_SMART_CART_ATTACH_FILE) {
        sprintf(title,"Select cartridge file");
    }

    filepanel->Window()->SetTitle(title);

    filepanel->Show();

    /* remember for later action */
    last_filetype[panelnr] = filetype;

    /* wait for save panel to disappear */
    if (filepanel->PanelMode() == B_SAVE_PANEL) {
        vsync_suspend_speed_eval();
        while (filepanel->IsShowing()) {
            snooze(1000);
        }
    }
}

static void load_snapshot_trap(WORD unused_addr, void *path)
{
    if (machine_read_snapshot((char *)path, 0) < 0) {
        ui_error("Cannot read snapshot image.");
    }
    delete path;
}

static void save_snapshot_trap(WORD unused_addr, void *path)
{
    if (machine_write_snapshot((char *)path, 1, 1, 0) < 0) {
        ui_error("Cannot write snapshot file.");
    }
    delete path;
}
        
static void ui_sound_record_action(const char *name, const char *ext)
{
    char *ext_name = util_add_extension_const(name, ext);

    resources_set_string("SoundRecordDeviceArg", ext_name);
    resources_set_string("SoundRecordDeviceName", ext);
    ui_display_statustext("Sound Recording Started...", 1);
    delete ext_name;
}
        
void ui_select_file_action(BMessage *msg)
{
    entry_ref ref;
    status_t err;
    BPath *path;

    if (msg->what == B_REFS_RECEIVED) {
        /* an open action */            
        /* extract the selected filename from the message */
        if ((err = msg->FindRef("refs", 0, &ref)) != B_OK) {
            ui_error("No File selected ?!");
            return;
        }
        path = new BPath(&ref);
        
        /* now the ACTION */
        if (last_filetype[0] == DISK_FILE) {
                /* it's a disk-attach */
                if (file_system_attach_disk(last_fileparam[0], path->Path()) < 0) {
                ui_error("Cannot attach specified file");
            }
        } else if (last_filetype[0] == TAPE_FILE) {
            /* it's a tape-attach */
            if (tape_image_attach(1, path->Path()) < 0) {
                ui_error("Cannot attach specified file");
            }
        } else if (last_filetype[0] == AUTOSTART_FILE) {
            if (autostart_autodetect(path->Path(), NULL, 0, AUTOSTART_MODE_RUN) < 0) {
                ui_error("Cannot autostart specified file.");
            }
        } else if (last_filetype[0] == AUTOSTART_DISK_IMAGE_FILE) {
            if (path->Path() != NULL) {
                resources_set_string("AutostartPrgDiskImage", path->Path());
            }
        } else if (last_filetype[0] == SNAPSHOTLOAD_FILE) {
            /* we need a copy of the path that won't be deleted here */
            char *pathname = lib_stralloc(path->Path());

            interrupt_maincpu_trigger_trap(load_snapshot_trap, (void*) pathname);
        } else if (last_filetype[0] == C64_CARTRIDGE_FILE) {
            BMessage *msg = new BMessage(ATTACH_C64_CART);

            msg->AddInt32("type", last_fileparam[0]);
            msg->AddString("filename", path->Path());
            ui_add_event(msg);
        } else if (last_filetype[0] == VIC20_CARTRIDGE_FILE) {
            BMessage *msg = new BMessage(ATTACH_VIC20_CART);

            msg->AddInt32("type", last_fileparam[0]);
            msg->AddString("filename", path->Path());
            ui_add_event(msg);
        } else if (last_filetype[0] == VSID_FILE) {
            BMessage *msg = new BMessage(PLAY_VSID);

            msg->AddString("filename", path->Path());
            ui_add_event(msg);
        } else if (last_filetype[0] == C64DTV_ROM_FILE) {
            resources_set_string("c64dtvromfilename", path->Path());
        } else if (last_filetype[0] == MMC64_BIOS_FILE) {
            resources_set_string("MMC64BIOSfilename", path->Path());
        } else if (last_filetype[0] == MMC64_IMAGE_FILE) {
            resources_set_string("MMC64imagefilename", path->Path());
        } else if (last_filetype[0] == MMCR_EEPROM_FILE) {
            resources_set_string("MMCREEPROMImage", path->Path());
        } else if (last_filetype[0] == MMCR_IMAGE_FILE) {
            resources_set_string("MMCRCardImage", path->Path());
        }
        delete path;    
    }

    if (msg->what == B_SAVE_REQUESTED) {
        char *fullpath;
        const char *name;

        /* a save action */
        /* first create the full path */
        if ((err = msg->FindRef("directory", &ref)) != B_OK) {
            ui_error("Wrong directory");
            return;
        }
        if ((err = msg->FindString("name", &name)) != B_OK) {
            ui_error("Wrong name");
            return;
        }
        path = new BPath(&ref);
        fullpath = util_concat(path->Path(), "/", name, NULL);

        /* now the action */
        if (last_filetype[1] == SNAPSHOTSAVE_FILE) {
            /* we need a copy of the path that won't be deleted here */
            char *pathname = lib_stralloc(fullpath);

            interrupt_maincpu_trigger_trap(save_snapshot_trap, (void*) fullpath);
        } else if (last_filetype[1] == SNAPSHOT_HISTORY_START) {
            resources_set_string("EventStartSnapshot", name);
        } else if (last_filetype[1] == SNAPSHOT_HISTORY_END) {
            resources_set_string("EventEndSnapshot", name);
            resources_set_string("EventSnapshotDir", path->Path());
        } else if (last_filetype[1] == REU_FILE) {
            resources_set_string("REUfilename", fullpath);
        } else if (last_filetype[1] == GEORAM_FILE) {
            resources_set_string("GEORAMfilename", fullpath);
        } else if (last_filetype[1] == RAMCART_FILE) {
            resources_set_string("RAMCARTfilename", fullpath);
        } else if (last_filetype[1] == MAGICVOICE_FILE) {
            resources_set_string("MagicVoiceImage", fullpath);
        } else if (last_filetype[1] == DQBB_FILE) {
            resources_set_string("DQBBfilename", fullpath);
        } else if (last_filetype[1] == ISEPIC_FILE) {
            resources_set_string("Isepicfilename", fullpath);
        } else if (last_filetype[1] == PLUS60K_FILE) {
            resources_set_string("PLUS60Kfilename", fullpath);
        } else if (last_filetype[1] == PLUS256K_FILE) {
            resources_set_string("PLUS256Kfilename", fullpath);
        } else if (last_filetype[1] == C64_256K_FILE) {
            resources_set_string("C64_256Kfilename", fullpath);
        } else if (last_filetype[1] == PETREU_FILE) {
            resources_set_string("PETREUfilename", fullpath);
        } else if (last_filetype[1] == PETDWW_FILE) {
            resources_set_string("PETDWWfilename", fullpath);
        } else if (last_filetype[1] == V364SPEECH_FILE) {
            resources_set_string("SpeechImage", fullpath);
        } else if (last_filetype[1] == EXPERT_FILE) {
            resources_set_string("Expertfilename", fullpath);
        } else if (last_filetype[1] == IDE64_FILE1) {
            resources_set_string("IDE64Image1", fullpath);
        } else if (last_filetype[1] == IDE64_FILE2) {
            resources_set_string("IDE64Image2", fullpath);
        } else if (last_filetype[1] == IDE64_FILE3) {
            resources_set_string("IDE64Image3", fullpath);
        } else if (last_filetype[1] == IDE64_FILE4) {
            resources_set_string("IDE64Image4", fullpath);
        } else if (last_filetype[1] == PRINTER_OUTPUT_FILE1) {
            resources_set_string("PrinterTextDevice1", fullpath);
        } else if (last_filetype[1] == PRINTER_OUTPUT_FILE2) {
            resources_set_string("PrinterTextDevice2", fullpath);
        } else if (last_filetype[1] == PRINTER_OUTPUT_FILE3) {
            resources_set_string("PrinterTextDevice3", fullpath);
        } else if (last_filetype[1] == AIFF_FILE) {
            ui_sound_record_action(fullpath, "aiff");
        } else if (last_filetype[1] == IFF_FILE) {
            ui_sound_record_action(fullpath, "iff");
#ifdef USE_LAMEMP3
        } else if (last_filetype[1] == MP3_FILE) {
            ui_sound_record_action(fullpath, "mp3");
#endif
        } else if (last_filetype[1] == VOC_FILE) {
            ui_sound_record_action(fullpath, "voc");
        } else if (last_filetype[1] == WAV_FILE) {
            ui_sound_record_action(fullpath, "wav");
        } else if (last_filetype[1] == WAV_FILE) {
            ui_sound_record_action(fullpath, "wav");
        } else if (last_filetype[1] == VIC20_GENERIC_CART_FILE) {
            if (cartridge_attach_image(CARTRIDGE_VIC20_GENERIC, fullpath) < 0) {
                ui_error("Invalid cartridge image");
            }
        } else if (last_filetype[1] == VIC20_FP_FILE) {
            if (cartridge_attach_image(CARTRIDGE_VIC20_FP, fullpath) < 0) {
                ui_error("Invalid cartridge image");
            }
        } else if (last_filetype[1] == VIC20_MEGACART_FILE) {
            if (cartridge_attach_image(CARTRIDGE_VIC20_MEGACART, fullpath) < 0) {
                ui_error("Invalid cartridge image");
            }
        } else if (last_filetype[1] == VIC20_MEGACART_NVRAM_FILE) {
            if (fullpath != NULL) {
                resources_set_string("MegaCartNvRAMfilename", fullpath);
            }
        } else if (last_filetype[1] == VIC20_FINAL_EXPANSION_FILE) {
            if (cartridge_attach_image(CARTRIDGE_VIC20_FINAL_EXPANSION, fullpath) < 0) {
                ui_error("Invalid cartridge image");
            }
        } else if (last_filetype[1] == VIC20_SMART_CART_ATTACH_FILE) {
            if (cartridge_attach_image(CARTRIDGE_VIC20_DETECT, fullpath) < 0) {
                ui_error("Invalid cartridge image");
            }
        }
        delete path;
        delete fullpath;
    }
}
