/*
 * ui_file.h - UI stuff dealing with files
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

#ifndef VICE__UI_FILE_H__
#define VICE__UI_FILE_H__

#include <FilePanel.h>
#include <ListView.h>

#include "imagecontents.h"

const uint32 AUTOSTART_MESSAGE = 'AS01';

enum filetype_t {
    AUTOSTART_FILE,
    AUTOSTART_DISK_IMAGE_FILE,
    DISK_FILE,
    TAPE_FILE,
    SNAPSHOTSAVE_FILE,
    SNAPSHOTLOAD_FILE,
    SNAPSHOT_HISTORY_START,
    SNAPSHOT_HISTORY_END,
    C64_CARTRIDGE_FILE,
    VIC20_CARTRIDGE_FILE,
    VSID_FILE,
    REU_FILE,
    GEORAM_FILE,
    RAMCART_FILE,
    MAGICVOICE_FILE,
    DQBB_FILE,
    ISEPIC_FILE,
    PLUS60K_FILE,
    PLUS256K_FILE,
    C64_256K_FILE,
    PETREU_FILE,
    PETDWW_FILE,
    V364SPEECH_FILE,
    MMC64_BIOS_FILE,
    MMC64_IMAGE_FILE,
    MMCR_EEPROM_FILE,
    MMCR_IMAGE_FILE,
    C64DTV_ROM_FILE,
    EXPERT_FILE,
    IDE64_FILE1,
    IDE64_FILE2,
    IDE64_FILE3,
    IDE64_FILE4,
    AIFF_FILE,
    IFF_FILE,
    MP3_FILE,
    VOC_FILE,
    WAV_FILE,
    PRINTER_OUTPUT_FILE1,
    PRINTER_OUTPUT_FILE2,
    PRINTER_OUTPUT_FILE3,
    VIC20_GENERIC_CART_FILE,
    VIC20_MEGACART_FILE,
    VIC20_MEGACART_NVRAM_FILE,
    VIC20_FINAL_EXPANSION_FILE,
    VIC20_FP_FILE,
    VIC20_SMART_CART_ATTACH_FILE
};

class ViceFilePanel;

class VicePreview : public BWindow {
    public :
        VicePreview(BPoint origin, ViceFilePanel *f);
        void DisplayContent(image_contents_t *content);
        void MessageReceived(BMessage *msg);
        BListView *contentlist;
        char image_name[256];
        ViceFilePanel *father;
};

class ViceFilePanel : public BFilePanel {
    public : 
        ViceFilePanel(file_panel_mode, BMessenger*, entry_ref*, uint32, bool);
        void SelectionChanged(void);
        void WasHidden(void);
        VicePreview *previewwindow;
};

extern void ui_select_file(file_panel_mode panelmode, filetype_t filetype, void *fileparam);
extern void ui_select_file_action(BMessage *msg);

#endif
