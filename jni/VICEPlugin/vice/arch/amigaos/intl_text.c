/*
 * intl_text.c - Translation texts to be included in intl.c
 *
 * Written by
 *  Marco van den Heuvel <blackystardust68@yahoo.com>
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

intl_translate_t intl_string_table[] = {


/* en */ { IDMS_FILE,    "File" },
/* da */ { IDMS_FILE_DA, "Fil" },
/* de */ { IDMS_FILE_DE, "Datei" },
/* es */ { IDMS_FILE_ES, "fichero" },
/* fr */ { IDMS_FILE_FR, "Fichier" },
/* hu */ { IDMS_FILE_HU, "F�jl" },
/* it */ { IDMS_FILE_IT, "File" },
/* ko */ { IDMS_FILE_KO, "����" },
/* nl */ { IDMS_FILE_NL, "Bestand" },
/* pl */ { IDMS_FILE_PL, "Plik" },
/* ru */ { IDMS_FILE_RU, "����" },
/* sv */ { IDMS_FILE_SV, "Arkiv" },
/* tr */ { IDMS_FILE_TR, "Dosya" },

/* en */ { IDMS_AUTOSTART_IMAGE,    "Autostart disk/tape image..." },
/* da */ { IDMS_AUTOSTART_IMAGE_DA, "Autostart disk-/b�nd-image..." },
/* de */ { IDMS_AUTOSTART_IMAGE_DE, "Autostart von Disk/Band Image..." },
/* es */ { IDMS_AUTOSTART_IMAGE_ES, "Autoarranque imagen de disco/cinta..." },
/* fr */ { IDMS_AUTOSTART_IMAGE_FR, "D�marrer automatiquement une image de disque/datassette..." },
/* hu */ { IDMS_AUTOSTART_IMAGE_HU, "Lemez/szalag k�pm�s automatikus ind�t�sa..." },
/* it */ { IDMS_AUTOSTART_IMAGE_IT, "Avvia automaticamente immagine disco/cassetta..." },
/* ko */ { IDMS_AUTOSTART_IMAGE_KO, "�ڵ� ���� ��ũ/������ �̹���..." },
/* nl */ { IDMS_AUTOSTART_IMAGE_NL, "Autostart disk-/tapebestand..." },
/* pl */ { IDMS_AUTOSTART_IMAGE_PL, "Automatycznie startuj z obrazu dysku lub ta�my..." },
/* ru */ { IDMS_AUTOSTART_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_AUTOSTART_IMAGE_SV, "Autostarta disk-/bandavbildningsfil..." },
/* tr */ { IDMS_AUTOSTART_IMAGE_TR, "Disk/Teyp imaj�n� otomatik ba�lat..." },

/* en */ { IDMS_ATTACH_DISK_IMAGE,    "Attach disk image" },
/* da */ { IDMS_ATTACH_DISK_IMAGE_DA, "Tilslut disk-image" },
/* de */ { IDMS_ATTACH_DISK_IMAGE_DE, "Disk Image einlegen" },
/* es */ { IDMS_ATTACH_DISK_IMAGE_ES, "Inserta imagen de disco" },
/* fr */ { IDMS_ATTACH_DISK_IMAGE_FR, "Ins�rer une image de disque" },
/* hu */ { IDMS_ATTACH_DISK_IMAGE_HU, "Lemez k�pm�s csatol�sa" },
/* it */ { IDMS_ATTACH_DISK_IMAGE_IT, "Seleziona immagine disco" },
/* ko */ { IDMS_ATTACH_DISK_IMAGE_KO, "��ũ �̹��� �ٿ��ֱ�" },
/* nl */ { IDMS_ATTACH_DISK_IMAGE_NL, "Koppel schijfbestand aan" },
/* pl */ { IDMS_ATTACH_DISK_IMAGE_PL, "Zamontuj obraz dyskietki" },
/* ru */ { IDMS_ATTACH_DISK_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ATTACH_DISK_IMAGE_SV, "Anslut diskettavbildningsfil" },
/* tr */ { IDMS_ATTACH_DISK_IMAGE_TR, "Disk imaj�n� yerle�tir" },

/* en */ {IDMS_DRIVE_8,    "Drive 8" },
/* da */ {IDMS_DRIVE_8_DA, "Drev 8" },
/* de */ {IDMS_DRIVE_8_DE, "Laufwerk 8" },
/* es */ {IDMS_DRIVE_8_ES, "Unidad disco 8" },
/* fr */ {IDMS_DRIVE_8_FR, "Lecteur #8" },
/* hu */ {IDMS_DRIVE_8_HU, "#8-as lemezegys�g" },
/* it */ {IDMS_DRIVE_8_IT, "Drive 8" },
/* ko */ {IDMS_DRIVE_8_KO, "����̺�8" },
/* nl */ {IDMS_DRIVE_8_NL, "Drive 8" },
/* pl */ {IDMS_DRIVE_8_PL, "Drukarka 8" },
/* ru */ {IDMS_DRIVE_8_RU, "" },  /* fuzzy */
/* sv */ {IDMS_DRIVE_8_SV, "Enhet 8" },
/* tr */ {IDMS_DRIVE_8_TR, "S�r�c� 8" },

/* en */ { IDMS_DRIVE_9,    "Drive 9" },
/* da */ { IDMS_DRIVE_9_DA, "Drev 9" },
/* de */ { IDMS_DRIVE_9_DE, "Laufwerk 9" },
/* es */ { IDMS_DRIVE_9_ES, "Unidad disco 9" },
/* fr */ { IDMS_DRIVE_9_FR, "Lecteur #9" },
/* hu */ { IDMS_DRIVE_9_HU, "#9-es lemezegys�g" },
/* it */ { IDMS_DRIVE_9_IT, "Drive 9" },
/* ko */ { IDMS_DRIVE_9_KO, "����̺�9" },
/* nl */ { IDMS_DRIVE_9_NL, "Drive 9" },
/* pl */ { IDMS_DRIVE_9_PL, "Drukarka 9" },
/* ru */ { IDMS_DRIVE_9_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DRIVE_9_SV, "Enhet 9" },
/* tr */ { IDMS_DRIVE_9_TR, "S�r�c� 9" },

/* en */ { IDMS_DRIVE_10,    "Drive 10" },
/* da */ { IDMS_DRIVE_10_DA, "Drev 10" },
/* de */ { IDMS_DRIVE_10_DE, "Laufwerk 10" },
/* es */ { IDMS_DRIVE_10_ES, "Unidad disco 10" },
/* fr */ { IDMS_DRIVE_10_FR, "Lecteur #10" },
/* hu */ { IDMS_DRIVE_10_HU, "#10-es lemezegys�g" },
/* it */ { IDMS_DRIVE_10_IT, "Drive 10" },
/* ko */ { IDMS_DRIVE_10_KO, "����̺�10" },
/* nl */ { IDMS_DRIVE_10_NL, "Drive 10" },
/* pl */ { IDMS_DRIVE_10_PL, "Drukarka 10" },
/* ru */ { IDMS_DRIVE_10_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DRIVE_10_SV, "Enhet 10" },
/* tr */ { IDMS_DRIVE_10_TR, "S�r�c� 10" },

/* en */ { IDMS_DRIVE_11,    "Drive 11" },
/* da */ { IDMS_DRIVE_11_DA, "Drev 11" },
/* de */ { IDMS_DRIVE_11_DE, "Laufwerk 11" },
/* es */ { IDMS_DRIVE_11_ES, "Unidad disco 11" },
/* fr */ { IDMS_DRIVE_11_FR, "Lecteur #11" },
/* hu */ { IDMS_DRIVE_11_HU, "#11-es lemezegys�g" },
/* it */ { IDMS_DRIVE_11_IT, "Drive 11" },
/* ko */ { IDMS_DRIVE_11_KO, "����̺�11" },
/* nl */ { IDMS_DRIVE_11_NL, "Drive 11" },
/* pl */ { IDMS_DRIVE_11_PL, "Drukarka 11" },
/* ru */ { IDMS_DRIVE_11_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DRIVE_11_SV, "Enhet 11" },
/* tr */ { IDMS_DRIVE_11_TR, "S�r�c� 11" },

/* en */ { IDMS_DETACH_DISK_IMAGE,    "Detach disk image" },
/* da */ { IDMS_DETACH_DISK_IMAGE_DA, "Frakobl disk-image" },
/* de */ { IDMS_DETACH_DISK_IMAGE_DE, "Disk Image entfernen" },
/* es */ { IDMS_DETACH_DISK_IMAGE_ES, "Quirar imagen de disco" },
/* fr */ { IDMS_DETACH_DISK_IMAGE_FR, "Retirer une image de disque" },
/* hu */ { IDMS_DETACH_DISK_IMAGE_HU, "Lemezk�pm�s lev�laszt�sa" },
/* it */ { IDMS_DETACH_DISK_IMAGE_IT, "Rimuovi immagine disco" },
/* ko */ { IDMS_DETACH_DISK_IMAGE_KO, "��ũ �̹��� �����" },
/* nl */ { IDMS_DETACH_DISK_IMAGE_NL, "Ontkoppel schijfbestand" },
/* pl */ { IDMS_DETACH_DISK_IMAGE_PL, "Wyjmij obraz dyskietki" },
/* ru */ { IDMS_DETACH_DISK_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DETACH_DISK_IMAGE_SV, "Koppla fr�n diskettavbildningsfil" },
/* tr */ { IDMS_DETACH_DISK_IMAGE_TR, "Disk imaj�n� ��kart" },

/* en */ { IDMS_ALL,    "All" },
/* da */ { IDMS_ALL_DA, "Alle" },
/* de */ { IDMS_ALL_DE, "Alle" },
/* es */ { IDMS_ALL_ES, "Todo" },
/* fr */ { IDMS_ALL_FR, "Tous" },
/* hu */ { IDMS_ALL_HU, "�sszes" },
/* it */ { IDMS_ALL_IT, "Tutti" },
/* ko */ { IDMS_ALL_KO, "����" },
/* nl */ { IDMS_ALL_NL, "Alles" },
/* pl */ { IDMS_ALL_PL, "Wszystkie" },
/* ru */ { IDMS_ALL_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ALL_SV, "Alla" },
/* tr */ { IDMS_ALL_TR, "T�m�" },

/* en */ { IDMS_FLIP_LIST,    "Flip list" },
/* da */ { IDMS_FLIP_LIST_DA, "Bladreliste" },
/* de */ { IDMS_FLIP_LIST_DE, "Flipliste" },
/* es */ { IDMS_FLIP_LIST_ES, "volcar la lista" },
/* fr */ { IDMS_FLIP_LIST_FR, "Groupement de disques" },
/* hu */ { IDMS_FLIP_LIST_HU, "Lemezlista" },
/* it */ { IDMS_FLIP_LIST_IT, "Flip list" },
/* ko */ { IDMS_FLIP_LIST_KO, "" },  /* fuzzy */
/* nl */ { IDMS_FLIP_LIST_NL, "Flip lijst" },
/* pl */ { IDMS_FLIP_LIST_PL, "Lista podmiany no�nika" },
/* ru */ { IDMS_FLIP_LIST_RU, "" },  /* fuzzy */
/* sv */ { IDMS_FLIP_LIST_SV, "Vallista" },
/* tr */ { IDMS_FLIP_LIST_TR, "S�ralama listesi" },

/* en */ { IDMS_ADD_CURRENT_IMAGE,    "Add current image (Unit 8)" },
/* da */ { IDMS_ADD_CURRENT_IMAGE_DA, "Tilf�j nuv�rende image (Enhed 8)" },
/* de */ { IDMS_ADD_CURRENT_IMAGE_DE, "Aktuelles Image hinzuf�gen (Ger�t 8)" },
/* es */ { IDMS_ADD_CURRENT_IMAGE_ES, "A�adir imagen actual (Unidad 8)" },
/* fr */ { IDMS_ADD_CURRENT_IMAGE_FR, "Ajouter l'image de disque courante (#8) au groupement" },
/* hu */ { IDMS_ADD_CURRENT_IMAGE_HU, "Az aktu�lis k�pm�s hozz�ad�sa (8-as egys�g)" },
/* it */ { IDMS_ADD_CURRENT_IMAGE_IT, "Aggiungi immagine attuale (Unit� 8)" },
/* ko */ { IDMS_ADD_CURRENT_IMAGE_KO, "���� �̹��� (Unit 8) ���ϱ�" },
/* nl */ { IDMS_ADD_CURRENT_IMAGE_NL, "Voeg huidig bestand toe (Drive 8)" },
/* pl */ { IDMS_ADD_CURRENT_IMAGE_PL, "Dodaj aktualny obraz (jednostka 8)" },
/* ru */ { IDMS_ADD_CURRENT_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ADD_CURRENT_IMAGE_SV, "L�gg till aktuell avbildning (enhet 8)" },
/* tr */ { IDMS_ADD_CURRENT_IMAGE_TR, "Ge�erli imaj� ekle (Birim 8)" },

/* en */ { IDMS_REMOVE_CURRENT_IMAGE,    "Remove current image (Unit 8)" },
/* da */ { IDMS_REMOVE_CURRENT_IMAGE_DA, "Fjern nuv�rende image (Enhed 8)" },
/* de */ { IDMS_REMOVE_CURRENT_IMAGE_DE, "Aktuelles Image entfernen (Ger�t 8)" },
/* es */ { IDMS_REMOVE_CURRENT_IMAGE_ES, "Quitar imagen actual (Unidad 8)" },
/* fr */ { IDMS_REMOVE_CURRENT_IMAGE_FR, "Retirer l'image de disque courante (#8) au groupement" },
/* hu */ { IDMS_REMOVE_CURRENT_IMAGE_HU, "Az aktu�lis k�pm�s elt�vol�t�sa (8-as egys�g)" },
/* it */ { IDMS_REMOVE_CURRENT_IMAGE_IT, "Rimuovi immagine attuale (Unit� 8)" },
/* ko */ { IDMS_REMOVE_CURRENT_IMAGE_KO, "���� �̹��� (Unit 8) �����ϱ�" },
/* nl */ { IDMS_REMOVE_CURRENT_IMAGE_NL, "Verwijder huidig bestand (Drive 8)" },
/* pl */ { IDMS_REMOVE_CURRENT_IMAGE_PL, "Usu� aktualny obraz (jednostka 8)" },
/* ru */ { IDMS_REMOVE_CURRENT_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_REMOVE_CURRENT_IMAGE_SV, "Ta bort aktuell avbildning (enhet 8)" },
/* tr */ { IDMS_REMOVE_CURRENT_IMAGE_TR, "Ge�erli imaj� kald�r (Birim 8)" },

/* en */ { IDMS_ATTACH_NEXT_IMAGE,    "Attach next image (Unit 8)" },
/* da */ { IDMS_ATTACH_NEXT_IMAGE_DA, "Tilslut n�ste image (Enhed 8)" },
/* de */ { IDMS_ATTACH_NEXT_IMAGE_DE, "N�chstes Image (Ger�t 8)" },
/* es */ { IDMS_ATTACH_NEXT_IMAGE_ES, "Insestar nueva imagen (Unidad 8)" },
/* fr */ { IDMS_ATTACH_NEXT_IMAGE_FR, "Ins�rer le prochain disque du groupement dans le lecteur #8" },
/* hu */ { IDMS_ATTACH_NEXT_IMAGE_HU, "K�vetkez� k�pm�s csatol�sa (8-as egys�g)" },
/* it */ { IDMS_ATTACH_NEXT_IMAGE_IT, "Seleziona immagine successiva (Unit� 8)" },
/* ko */ { IDMS_ATTACH_NEXT_IMAGE_KO, "���� �̹��� (Unit 8) ���̱�" },
/* nl */ { IDMS_ATTACH_NEXT_IMAGE_NL, "Koppel volgend bestand (Drive 8)" },
/* pl */ { IDMS_ATTACH_NEXT_IMAGE_PL, "Zamontuj nast�pny obraz (jednostka 8)" },
/* ru */ { IDMS_ATTACH_NEXT_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ATTACH_NEXT_IMAGE_SV, "Anslut n�sta avbildning (enhet 8)" },
/* tr */ { IDMS_ATTACH_NEXT_IMAGE_TR, "Sonraki imaj� yerle�tir (Birim 8)" },

/* en */ { IDMS_ATTACH_PREVIOUS_IMAGE,    "Attach previous image (Unit 8)" },
/* da */ { IDMS_ATTACH_PREVIOUS_IMAGE_DA, "Tilslut forrige image (Enhed 8)" },
/* de */ { IDMS_ATTACH_PREVIOUS_IMAGE_DE, "Voriges Image (Ger�t 8)" },
/* es */ { IDMS_ATTACH_PREVIOUS_IMAGE_ES, "Insertar imagen previa (Unidad 8)" },
/* fr */ { IDMS_ATTACH_PREVIOUS_IMAGE_FR, "Ins�rer le disque pr�c�dent du groupement dans le lecteur #8" },
/* hu */ { IDMS_ATTACH_PREVIOUS_IMAGE_HU, "El�z� k�pm�s csatol�sa (8-as egys�g)" },
/* it */ { IDMS_ATTACH_PREVIOUS_IMAGE_IT, "Seleziona immagine precedente (Unit� 8)" },
/* ko */ { IDMS_ATTACH_PREVIOUS_IMAGE_KO, "���� �̹��� (Unit 8) ���̱�" },
/* nl */ { IDMS_ATTACH_PREVIOUS_IMAGE_NL, "Koppel vorig bestand (Drive 8)" },
/* pl */ { IDMS_ATTACH_PREVIOUS_IMAGE_PL, "Zamontuj poprzedni obraz (jednostka 8)" },
/* ru */ { IDMS_ATTACH_PREVIOUS_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ATTACH_PREVIOUS_IMAGE_SV, "Anslut f�reg�ende avbildning (enhet 8)" },
/* tr */ { IDMS_ATTACH_PREVIOUS_IMAGE_TR, "�nceki imaj� yerle�tir (Birim 8)" },

/* en */ { IDMS_LOAD_FLIP_LIST,    "Load flip list file" },
/* da */ { IDMS_LOAD_FLIP_LIST_DA, "Indl�s bladrelistefil" },
/* de */ { IDMS_LOAD_FLIP_LIST_DE, "Fliplist Datei laden" },
/* es */ { IDMS_LOAD_FLIP_LIST_ES, "Cargar lista de ficheros a commutar" },
/* fr */ { IDMS_LOAD_FLIP_LIST_FR, "Charger un fichier de groupement de disques" },
/* hu */ { IDMS_LOAD_FLIP_LIST_HU, "Lemezlista bet�lt�se" },
/* it */ { IDMS_LOAD_FLIP_LIST_IT, "Carica file fliplist" },
/* ko */ { IDMS_LOAD_FLIP_LIST_KO, "�ø� ����Ʈ ���� �ҷ�����" },
/* nl */ { IDMS_LOAD_FLIP_LIST_NL, "Laad fliplijstbestand" },
/* pl */ { IDMS_LOAD_FLIP_LIST_PL, "Wczytaj plik listy podmiany no�nik�w" },
/* ru */ { IDMS_LOAD_FLIP_LIST_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LOAD_FLIP_LIST_SV, "L�s vallistefil" },
/* tr */ { IDMS_LOAD_FLIP_LIST_TR, "S�ralama listesi dosyas�n� y�kle" },

/* en */ { IDMS_SAVE_FLIP_LIST,    "Save flip list file" },
/* da */ { IDMS_SAVE_FLIP_LIST_DA, "Gem bladrelistefil" },
/* de */ { IDMS_SAVE_FLIP_LIST_DE, "Fliplist Datei speichern" },
/* es */ { IDMS_SAVE_FLIP_LIST_ES, "Grabar lista de ficheros a commutar" },
/* fr */ { IDMS_SAVE_FLIP_LIST_FR, "Enregistrer le fichier de groupement de disques actuel" },
/* hu */ { IDMS_SAVE_FLIP_LIST_HU, "Lemezlista ment�se f�jlba" },
/* it */ { IDMS_SAVE_FLIP_LIST_IT, "Salva file fliplist" },
/* ko */ { IDMS_SAVE_FLIP_LIST_KO, "�ø� ����Ʈ ���� �����ϱ�" },
/* nl */ { IDMS_SAVE_FLIP_LIST_NL, "Fliplijstbestand opslaan" },
/* pl */ { IDMS_SAVE_FLIP_LIST_PL, "Zapisz plik listy podmiany no�nik�w" },
/* ru */ { IDMS_SAVE_FLIP_LIST_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SAVE_FLIP_LIST_SV, "Spara vallistefil" },
/* tr */ { IDMS_SAVE_FLIP_LIST_TR, "S�ralama listesi dosyas�n� kaydet" },

/* en */ { IDMS_ATTACH_TAPE_IMAGE,    "Attach tape image..." },
/* da */ { IDMS_ATTACH_TAPE_IMAGE_DA, "Tilslut b�nd-image..." },
/* de */ { IDMS_ATTACH_TAPE_IMAGE_DE, "Band Image einlegen..." },
/* es */ { IDMS_ATTACH_TAPE_IMAGE_ES, "Insertar imagen de cinta..." },
/* fr */ { IDMS_ATTACH_TAPE_IMAGE_FR, "Ins�rer une image de datassette..." },
/* hu */ { IDMS_ATTACH_TAPE_IMAGE_HU, "Szalag k�pm�s csatol�sa..." },
/* it */ { IDMS_ATTACH_TAPE_IMAGE_IT, "Seleziona immagine cassetta..." },
/* ko */ { IDMS_ATTACH_TAPE_IMAGE_KO, "������ �̹��� �ٿ��ֱ�..." },
/* nl */ { IDMS_ATTACH_TAPE_IMAGE_NL, "Koppel tapebestand aan..." },
/* pl */ { IDMS_ATTACH_TAPE_IMAGE_PL, "Zamontuj obraz ta�my..." },
/* ru */ { IDMS_ATTACH_TAPE_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ATTACH_TAPE_IMAGE_SV, "Anslut bandavbildningsfil..." },
/* tr */ { IDMS_ATTACH_TAPE_IMAGE_TR, "Teyp imaj�n� yerle�tir..." },

/* en */ { IDMS_DETACH_TAPE_IMAGE,    "Detach tape image" },
/* da */ { IDMS_DETACH_TAPE_IMAGE_DA, "Frakobl b�nd-image" },
/* de */ { IDMS_DETACH_TAPE_IMAGE_DE, "Band Image entfernen" },
/* es */ { IDMS_DETACH_TAPE_IMAGE_ES, "Quirar imagen de cinta" },
/* fr */ { IDMS_DETACH_TAPE_IMAGE_FR, "Retirer une image datassette..." },
/* hu */ { IDMS_DETACH_TAPE_IMAGE_HU, "Szalag k�pm�s lev�laszt�sa" },
/* it */ { IDMS_DETACH_TAPE_IMAGE_IT, "Rimuovi immagine cassetta" },
/* ko */ { IDMS_DETACH_TAPE_IMAGE_KO, "������ �̹��� �����" },
/* nl */ { IDMS_DETACH_TAPE_IMAGE_NL, "Ontkoppel tapebestand" },
/* pl */ { IDMS_DETACH_TAPE_IMAGE_PL, "Wyjmij obraz ta�my" },
/* ru */ { IDMS_DETACH_TAPE_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DETACH_TAPE_IMAGE_SV, "Koppla fr�n bandavbildningsfil" },
/* tr */ { IDMS_DETACH_TAPE_IMAGE_TR, "Teyp imaj�n� ��kart" },

/* en */ { IDMS_DATASSETTE_CONTROL,    "Datassette control" },
/* da */ { IDMS_DATASSETTE_CONTROL_DA, "Datasettestyring" },
/* de */ { IDMS_DATASSETTE_CONTROL_DE, "Bandlaufwerk Kontrolle" },
/* es */ { IDMS_DATASSETTE_CONTROL_ES, "Control del datasette" },
/* fr */ { IDMS_DATASSETTE_CONTROL_FR, "Contr�le datassette" },
/* hu */ { IDMS_DATASSETTE_CONTROL_HU, "Magn� vez�rl�s" },
/* it */ { IDMS_DATASSETTE_CONTROL_IT, "Comandi registratore" },
/* ko */ { IDMS_DATASSETTE_CONTROL_KO, "����Ÿ�� ĿƮ��" },
/* nl */ { IDMS_DATASSETTE_CONTROL_NL, "Datasette regeling" },
/* pl */ { IDMS_DATASSETTE_CONTROL_PL, "Zarz�dzanie magnetofonem" },
/* ru */ { IDMS_DATASSETTE_CONTROL_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DATASSETTE_CONTROL_SV, "Datasettestyrning" },
/* tr */ { IDMS_DATASSETTE_CONTROL_TR, "Teyp kontrol�" },

/* en */ { IDMS_STOP,    "Stop" },
/* da */ { IDMS_STOP_DA, "Stop" },
/* de */ { IDMS_STOP_DE, "Stop" },
/* es */ { IDMS_STOP_ES, "Alto" },
/* fr */ { IDMS_STOP_FR, "Arr�t" },
/* hu */ { IDMS_STOP_HU, "Le�ll�t�s" },
/* it */ { IDMS_STOP_IT, "Stop" },
/* ko */ { IDMS_STOP_KO, "����" },
/* nl */ { IDMS_STOP_NL, "Stop" },
/* pl */ { IDMS_STOP_PL, "Zatrzymaj" },
/* ru */ { IDMS_STOP_RU, "" },  /* fuzzy */
/* sv */ { IDMS_STOP_SV, "Stoppa" },
/* tr */ { IDMS_STOP_TR, "Dur" },

/* en */ { IDMS_START,    "Start" },
/* da */ { IDMS_START_DA, "Start" },
/* de */ { IDMS_START_DE, "Start" },
/* es */ { IDMS_START_ES, "Empezar" },
/* fr */ { IDMS_START_FR, "D�marrer" },
/* hu */ { IDMS_START_HU, "Ind�t�s" },
/* it */ { IDMS_START_IT, "Avvia" },
/* ko */ { IDMS_START_KO, "" },  /* fuzzy */
/* nl */ { IDMS_START_NL, "Start" },
/* pl */ { IDMS_START_PL, "Start" },
/* ru */ { IDMS_START_RU, "" },  /* fuzzy */
/* sv */ { IDMS_START_SV, "Starta" },
/* tr */ { IDMS_START_TR, "Ba�lat" },

/* en */ { IDMS_FORWARD,    "Forward" },
/* da */ { IDMS_FORWARD_DA, "Spol frem" },
/* de */ { IDMS_FORWARD_DE, "Forward" },
/* es */ { IDMS_FORWARD_ES, "Adelante" },
/* fr */ { IDMS_FORWARD_FR, "En avant" },
/* hu */ { IDMS_FORWARD_HU, "El�recs�v�l�s" },
/* it */ { IDMS_FORWARD_IT, "Avanti" },
/* ko */ { IDMS_FORWARD_KO, "��������" },
/* nl */ { IDMS_FORWARD_NL, "Vooruit" },
/* pl */ { IDMS_FORWARD_PL, "Przewi� do przodu" },
/* ru */ { IDMS_FORWARD_RU, "" },  /* fuzzy */
/* sv */ { IDMS_FORWARD_SV, "Spola fram�t" },
/* tr */ { IDMS_FORWARD_TR, "�leri" },

/* en */ { IDMS_REWIND,    "Rewind" },
/* da */ { IDMS_REWIND_DA, "Spol tilbage" },
/* de */ { IDMS_REWIND_DE, "Rewind" },
/* es */ { IDMS_REWIND_ES, "Rebobinar" },
/* fr */ { IDMS_REWIND_FR, "En arri�re" },
/* hu */ { IDMS_REWIND_HU, "Visszacs�v�l�s" },
/* it */ { IDMS_REWIND_IT, "Indietro" },
/* ko */ { IDMS_REWIND_KO, "�ǰ���" },
/* nl */ { IDMS_REWIND_NL, "Terug" },
/* pl */ { IDMS_REWIND_PL, "Przewi� do ty�u" },
/* ru */ { IDMS_REWIND_RU, "" },  /* fuzzy */
/* sv */ { IDMS_REWIND_SV, "Spola bak�t" },
/* tr */ { IDMS_REWIND_TR, "Geri" },

/* en */ { IDMS_RECORD,    "Record" },
/* da */ { IDMS_RECORD_DA, "Optag" },
/* de */ { IDMS_RECORD_DE, "Record" },
/* es */ { IDMS_RECORD_ES, "Grabar" },
/* fr */ { IDMS_RECORD_FR, "Enregistrer" },
/* hu */ { IDMS_RECORD_HU, "Felv�tel" },
/* it */ { IDMS_RECORD_IT, "Registra" },
/* ko */ { IDMS_RECORD_KO, "��ȭ" },
/* nl */ { IDMS_RECORD_NL, "Opname" },
/* pl */ { IDMS_RECORD_PL, "Nagrywaj" },
/* ru */ { IDMS_RECORD_RU, "" },  /* fuzzy */
/* sv */ { IDMS_RECORD_SV, "Spela in" },
/* tr */ { IDMS_RECORD_TR, "Kay�t" },

/* en */ { IDMS_RESET,    "Reset" },
/* da */ { IDMS_RESET_DA, "Reset" },
/* de */ { IDMS_RESET_DE, "Reset" },
/* es */ { IDMS_RESET_ES, "Reiniciar" },
/* fr */ { IDMS_RESET_FR, "R�initialiser" },
/* hu */ { IDMS_RESET_HU, "Reset" },
/* it */ { IDMS_RESET_IT, "Reset" },
/* ko */ { IDMS_RESET_KO, "����" },
/* nl */ { IDMS_RESET_NL, "Reset" },
/* pl */ { IDMS_RESET_PL, "Reset" },
/* ru */ { IDMS_RESET_RU, "" },  /* fuzzy */
/* sv */ { IDMS_RESET_SV, "�terst�ll" },
/* tr */ { IDMS_RESET_TR, "Reset" },

/* en */ { IDMS_RESET_COUNTER,    "Reset Counter" },
/* da */ { IDMS_RESET_COUNTER_DA, "Nulstil t�ller" },
/* de */ { IDMS_RESET_COUNTER_DE, "Z�hler zur�cksetzen" },
/* es */ { IDMS_RESET_COUNTER_ES, "Reiniciar contador" },
/* fr */ { IDMS_RESET_COUNTER_FR, "R�inialiser le compteur" },
/* hu */ { IDMS_RESET_COUNTER_HU, "Sz�ml�l� null�z�sa" },
/* it */ { IDMS_RESET_COUNTER_IT, "Reset contantore" },
/* ko */ { IDMS_RESET_COUNTER_KO, "" },  /* fuzzy */
/* nl */ { IDMS_RESET_COUNTER_NL, "Reset Teller" },
/* pl */ { IDMS_RESET_COUNTER_PL, "Skasuj licznik" },
/* ru */ { IDMS_RESET_COUNTER_RU, "" },  /* fuzzy */
/* sv */ { IDMS_RESET_COUNTER_SV, "Nollst�ll r�knare" },
/* tr */ { IDMS_RESET_COUNTER_TR, "Sayac� Resetle" },

/* en */ { IDMS_ATTACH_CART_IMAGE,    "Attach cartridge image..." },
/* da */ { IDMS_ATTACH_CART_IMAGE_DA, "Tilslut cartridge-image..." },
/* de */ { IDMS_ATTACH_CART_IMAGE_DE, "Erweiterungsmodul einlegen..." },
/* es */ { IDMS_ATTACH_CART_IMAGE_ES, "Insertar imagen de cartucho..." },
/* fr */ { IDMS_ATTACH_CART_IMAGE_FR, "Ins�rer une cartouche..." },
/* hu */ { IDMS_ATTACH_CART_IMAGE_HU, "Cartridge k�pm�s csatol�sa..." },
/* it */ { IDMS_ATTACH_CART_IMAGE_IT, "Seleziona immagine cartuccia..." },
/* ko */ { IDMS_ATTACH_CART_IMAGE_KO, "īƮ���� �̹��� ���̱�..." },
/* nl */ { IDMS_ATTACH_CART_IMAGE_NL, "Koppel cartridge bestand..." },
/* pl */ { IDMS_ATTACH_CART_IMAGE_PL, "Zamontuj obraz kartrid�a..." },
/* ru */ { IDMS_ATTACH_CART_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ATTACH_CART_IMAGE_SV, "Anslut insticksmodulfil..." },
/* tr */ { IDMS_ATTACH_CART_IMAGE_TR, "Kartu� imaj� yerle�tir..." },

/* en */ { IDMS_GENERIC_IMAGE,    "Generic image..." },
/* da */ { IDMS_GENERIC_IMAGE_DA, "Standard-image..." },
/* de */ { IDMS_GENERIC_IMAGE_DE, "Generisches Image..." },
/* es */ { IDMS_GENERIC_IMAGE_ES, "Imagen generica..." },
/* fr */ { IDMS_GENERIC_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_GENERIC_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_GENERIC_IMAGE_IT, "Immagine generica..." },
/* ko */ { IDMS_GENERIC_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_GENERIC_IMAGE_NL, "Algemeen bestand..." },
/* pl */ { IDMS_GENERIC_IMAGE_PL, "Standardowy obraz..." },
/* ru */ { IDMS_GENERIC_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_GENERIC_IMAGE_SV, "Generisk avbild..." },
/* tr */ { IDMS_GENERIC_IMAGE_TR, "Jenerik imaj..." },

/* en */ { IDMS_MEGA_CART_IMAGE,    "Mega-Cart image..." },
/* da */ { IDMS_MEGA_CART_IMAGE_DA, "Mega-Cart image..." },
/* de */ { IDMS_MEGA_CART_IMAGE_DE, "Mega-Cart Image..." },
/* es */ { IDMS_MEGA_CART_IMAGE_ES, "Imagen Mega-Cart..." },
/* fr */ { IDMS_MEGA_CART_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_MEGA_CART_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_MEGA_CART_IMAGE_IT, "Immagine Mega-Cart..." },
/* ko */ { IDMS_MEGA_CART_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_MEGA_CART_IMAGE_NL, "Mega-Cart bestand..." },
/* pl */ { IDMS_MEGA_CART_IMAGE_PL, "Obraz Mega-Cart..." },
/* ru */ { IDMS_MEGA_CART_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_MEGA_CART_IMAGE_SV, "Mega-Cart-avbildning..." },
/* tr */ { IDMS_MEGA_CART_IMAGE_TR, "Mega-Cart imaj�..." },

/* en */ { IDMS_FINAL_EXPANSION_IMAGE,    "Final Expansion image..." },
/* da */ { IDMS_FINAL_EXPANSION_IMAGE_DA, "Final Expansion-image..." },
/* de */ { IDMS_FINAL_EXPANSION_IMAGE_DE, "Final Expansion Image..." },
/* es */ { IDMS_FINAL_EXPANSION_IMAGE_ES, "Imagen Final Expansion..." },
/* fr */ { IDMS_FINAL_EXPANSION_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_FINAL_EXPANSION_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_FINAL_EXPANSION_IMAGE_IT, "Immagine Final Expansion..." },
/* ko */ { IDMS_FINAL_EXPANSION_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_FINAL_EXPANSION_IMAGE_NL, "Final Expansion bestand..." },
/* pl */ { IDMS_FINAL_EXPANSION_IMAGE_PL, "Obraz Final Expansion..." },
/* ru */ { IDMS_FINAL_EXPANSION_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_FINAL_EXPANSION_IMAGE_SV, "Final Expansion-fil..." },
/* tr */ { IDMS_FINAL_EXPANSION_IMAGE_TR, "Final Expansion imaj�..." },

/* en */ { IDMS_FP_IMAGE,    "Vic Flash Plugin image..." },
/* da */ { IDMS_FP_IMAGE_DA, "Vic Flash Plugin-image..." },
/* de */ { IDMS_FP_IMAGE_DE, "Vic Flash Plugin Image..." },
/* es */ { IDMS_FP_IMAGE_ES, "Imagen Vic Flash Plugin..." },
/* fr */ { IDMS_FP_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_FP_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_FP_IMAGE_IT, "Immagine Vic Flash Plugin..." },
/* ko */ { IDMS_FP_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_FP_IMAGE_NL, "Vic Flash Plugin bestand..." },
/* pl */ { IDMS_FP_IMAGE_PL, "Obraz Vic Flash Plugin..." },
/* ru */ { IDMS_FP_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_FP_IMAGE_SV, "Vic Flash insticksmodul-fil..." },
/* tr */ { IDMS_FP_IMAGE_TR, "Vic Flash Plugin imaj�..." },

/* en */ { IDMS_ADD_TO_GENERIC,    "Add to generic cartridge..." },
/* da */ { IDMS_ADD_TO_GENERIC_DA, "Tilf�j til standardcartridge..." },
/* de */ { IDMS_ADD_TO_GENERIC_DE, "Zu universellem Erweiterungsmodul hinzuf�gen..." },
/* es */ { IDMS_ADD_TO_GENERIC_ES, "A�adir al cartucho generico..." },
/* fr */ { IDMS_ADD_TO_GENERIC_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ADD_TO_GENERIC_HU, "Hozz�ad�s �ltal�nos cartridge-hoz..." },
/* it */ { IDMS_ADD_TO_GENERIC_IT, "Aggiungi a cartuccia generica..." },
/* ko */ { IDMS_ADD_TO_GENERIC_KO, "���ʸ� īƮ������ ���ϱ�..." },
/* nl */ { IDMS_ADD_TO_GENERIC_NL, "Voeg toe aan algemeen cartridge..." },
/* pl */ { IDMS_ADD_TO_GENERIC_PL, "Dodaj do standardowego kartrid�a..." },
/* ru */ { IDMS_ADD_TO_GENERIC_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ADD_TO_GENERIC_SV, "L�gg till generisk insticksmodul..." },
/* tr */ { IDMS_ADD_TO_GENERIC_TR, "Jenerik kartu�a ekle..." },

/* en */ { IDMS_SMART_ATTACH_IMAGE,    "Smart-attach image..." },
/* da */ { IDMS_SMART_ATTACH_IMAGE_DA, "Smart-tilslut image..." },
/* de */ { IDMS_SMART_ATTACH_IMAGE_DE, "Smart-Einlegen Image Date..." },
/* es */ { IDMS_SMART_ATTACH_IMAGE_ES, "Imagen Smart-attach..." },
/* fr */ { IDMS_SMART_ATTACH_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_SMART_ATTACH_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_SMART_ATTACH_IMAGE_IT, "Immagine Smart-attach..." },
/* ko */ { IDMS_SMART_ATTACH_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SMART_ATTACH_IMAGE_NL, "Slimme bestandskoppeling..." },
/* pl */ { IDMS_SMART_ATTACH_IMAGE_PL, "Inteligentne montowanie obrazu..." },
/* ru */ { IDMS_SMART_ATTACH_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SMART_ATTACH_IMAGE_SV, "Smartanslut avbildning..." },
/* tr */ { IDMS_SMART_ATTACH_IMAGE_TR, "Smart-attach imaj�..." },

/* en */ { IDMS_4_8_16KB_AT_2000,    "4/8/16KB image at $2000..." },
/* da */ { IDMS_4_8_16KB_AT_2000_DA, "4/8/16KB-image p� $2000..." },
/* de */ { IDMS_4_8_16KB_AT_2000_DE, "4/8/16KB Image bei $2000..." },
/* es */ { IDMS_4_8_16KB_AT_2000_ES, "4/8/16KB imagen en $2000..." },
/* fr */ { IDMS_4_8_16KB_AT_2000_FR, "" },  /* fuzzy */
/* hu */ { IDMS_4_8_16KB_AT_2000_HU, "" },  /* fuzzy */
/* it */ { IDMS_4_8_16KB_AT_2000_IT, "Immagine di 4/8/16KB a $2000..." },
/* ko */ { IDMS_4_8_16KB_AT_2000_KO, "" },  /* fuzzy */
/* nl */ { IDMS_4_8_16KB_AT_2000_NL, "4/8/16KB bestand in $2000..." },
/* pl */ { IDMS_4_8_16KB_AT_2000_PL, "4/8/16KB obraz w $2000..." },
/* ru */ { IDMS_4_8_16KB_AT_2000_RU, "" },  /* fuzzy */
/* sv */ { IDMS_4_8_16KB_AT_2000_SV, "4/8/16KB-fil vid $2000..." },
/* tr */ { IDMS_4_8_16KB_AT_2000_TR, "4/8/16KB imaj� $2000 adresinde..." },

/* en */ { IDMS_4_8_16KB_AT_4000,    "4/8/16KB image at $4000..." },
/* da */ { IDMS_4_8_16KB_AT_4000_DA, "4/8/16KB-image p� $4000..." },
/* de */ { IDMS_4_8_16KB_AT_4000_DE, "4/8/16KB Image bei $4000..." },
/* es */ { IDMS_4_8_16KB_AT_4000_ES, "4/8/16KB imagen en $4000..." },
/* fr */ { IDMS_4_8_16KB_AT_4000_FR, "" },  /* fuzzy */
/* hu */ { IDMS_4_8_16KB_AT_4000_HU, "" },  /* fuzzy */
/* it */ { IDMS_4_8_16KB_AT_4000_IT, "Immagine di 4/8/16KB a $4000..." },
/* ko */ { IDMS_4_8_16KB_AT_4000_KO, "" },  /* fuzzy */
/* nl */ { IDMS_4_8_16KB_AT_4000_NL, "4/8/16KB bestand in $4000..." },
/* pl */ { IDMS_4_8_16KB_AT_4000_PL, "4/8/16KB obraz w $4000..." },
/* ru */ { IDMS_4_8_16KB_AT_4000_RU, "" },  /* fuzzy */
/* sv */ { IDMS_4_8_16KB_AT_4000_SV, "4/8/16KB-fil vid $4000..." },
/* tr */ { IDMS_4_8_16KB_AT_4000_TR, "4/8/16KB imaj� $4000 adresinde..." },

/* en */ { IDMS_4_8_16KB_AT_6000,    "4/8/16KB image at $6000..." },
/* da */ { IDMS_4_8_16KB_AT_6000_DA, "4/8/16KB-image p� $6000..." },
/* de */ { IDMS_4_8_16KB_AT_6000_DE, "4/8/16KB Image bei $6000..." },
/* es */ { IDMS_4_8_16KB_AT_6000_ES, "4/8/16KB imagen en $6000..." },
/* fr */ { IDMS_4_8_16KB_AT_6000_FR, "" },  /* fuzzy */
/* hu */ { IDMS_4_8_16KB_AT_6000_HU, "" },  /* fuzzy */
/* it */ { IDMS_4_8_16KB_AT_6000_IT, "Immagine di 4/8/16KB a $6000..." },
/* ko */ { IDMS_4_8_16KB_AT_6000_KO, "" },  /* fuzzy */
/* nl */ { IDMS_4_8_16KB_AT_6000_NL, "4/8/16KB bestand in $6000..." },
/* pl */ { IDMS_4_8_16KB_AT_6000_PL, "4/8/16KB obraz w $6000..." },
/* ru */ { IDMS_4_8_16KB_AT_6000_RU, "" },  /* fuzzy */
/* sv */ { IDMS_4_8_16KB_AT_6000_SV, "4/8/16KB-fil vid $6000..." },
/* tr */ { IDMS_4_8_16KB_AT_6000_TR, "4/8/16KB imaj� $6000 adresinde..." },

/* en */ { IDMS_4_8KB_AT_A000,    "4/8KB image at $A000..." },
/* da */ { IDMS_4_8KB_AT_A000_DA, "4/8KB-image p� $A000..." },
/* de */ { IDMS_4_8KB_AT_A000_DE, "4/8KB Image bei $A000..." },
/* es */ { IDMS_4_8KB_AT_A000_ES, "4/8KB imagen en $A000..." },
/* fr */ { IDMS_4_8KB_AT_A000_FR, "" },  /* fuzzy */
/* hu */ { IDMS_4_8KB_AT_A000_HU, "" },  /* fuzzy */
/* it */ { IDMS_4_8KB_AT_A000_IT, "Immagine di 4/8KB a $A000..." },
/* ko */ { IDMS_4_8KB_AT_A000_KO, "" },  /* fuzzy */
/* nl */ { IDMS_4_8KB_AT_A000_NL, "4/8KB bestand in $A000..." },
/* pl */ { IDMS_4_8KB_AT_A000_PL, "4/8KB obraz w $A000..." },
/* ru */ { IDMS_4_8KB_AT_A000_RU, "" },  /* fuzzy */
/* sv */ { IDMS_4_8KB_AT_A000_SV, "4/8KB-fil vid $A000..." },
/* tr */ { IDMS_4_8KB_AT_A000_TR, "4/8KB imaj� $A000 adresinde..." },

/* en */ { IDMS_4KB_AT_B000,    "4KB image at $B000..." },
/* da */ { IDMS_4KB_AT_B000_DA, "4KB-image p� $B000..." },
/* de */ { IDMS_4KB_AT_B000_DE, "4KB Image bei $B000..." },
/* es */ { IDMS_4KB_AT_B000_ES, "4KB imagen en $B000..." },
/* fr */ { IDMS_4KB_AT_B000_FR, "" },  /* fuzzy */
/* hu */ { IDMS_4KB_AT_B000_HU, "" },  /* fuzzy */
/* it */ { IDMS_4KB_AT_B000_IT, "Immagine di 4KB a $B000..." },
/* ko */ { IDMS_4KB_AT_B000_KO, "" },  /* fuzzy */
/* nl */ { IDMS_4KB_AT_B000_NL, "4KB bestand in $B000..." },
/* pl */ { IDMS_4KB_AT_B000_PL, "4KB obraz w $B000..." },
/* ru */ { IDMS_4KB_AT_B000_RU, "" },  /* fuzzy */
/* sv */ { IDMS_4KB_AT_B000_SV, "4KB-fil vid $B000..." },
/* tr */ { IDMS_4KB_AT_B000_TR, "4KB imaj� $B000 adresinde..." },

/* en */ { IDMS_DETACH_CART_IMAGE,    "Detach cartridge image(s)" },
/* da */ { IDMS_DETACH_CART_IMAGE_DA, "Frakobl cartridge-image" },
/* de */ { IDMS_DETACH_CART_IMAGE_DE, "Erweiterungsmodul Image(s) entfernen" },
/* es */ { IDMS_DETACH_CART_IMAGE_ES, "Extraer imagen(es) cartucho" },
/* fr */ { IDMS_DETACH_CART_IMAGE_FR, "Retirer une cartouche" },
/* hu */ { IDMS_DETACH_CART_IMAGE_HU, "Cartridge k�pm�s(ok) lev�laszt�sa" },
/* it */ { IDMS_DETACH_CART_IMAGE_IT, "Rimuovi le immagini delle cartucce" },
/* ko */ { IDMS_DETACH_CART_IMAGE_KO, "īƮ���� �̹��� ����" },
/* nl */ { IDMS_DETACH_CART_IMAGE_NL, "Ontkoppel cartridge bestand(en)" },
/* pl */ { IDMS_DETACH_CART_IMAGE_PL, "Wysu� obraz(y) kartrid�a" },
/* ru */ { IDMS_DETACH_CART_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DETACH_CART_IMAGE_SV, "Koppla fr�n insticksmodulfil(er)" },
/* tr */ { IDMS_DETACH_CART_IMAGE_TR, "Kartu� imaj(lar)�n� ��kart" },

/* en */ { IDMS_C1_LOW_IMAGE,    "C1 low  image..." },
/* da */ { IDMS_C1_LOW_IMAGE_DA, "C1 lav-image..." },
/* de */ { IDMS_C1_LOW_IMAGE_DE, "C1 low Image Datei..." },
/* es */ { IDMS_C1_LOW_IMAGE_ES, "C1 imagen bajo..." },
/* fr */ { IDMS_C1_LOW_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_C1_LOW_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_C1_LOW_IMAGE_IT, "Immagine C1 bassa..." },
/* ko */ { IDMS_C1_LOW_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_C1_LOW_IMAGE_NL, "C1 low bestand..." },
/* pl */ { IDMS_C1_LOW_IMAGE_PL, "Obraz C1 low..." },
/* ru */ { IDMS_C1_LOW_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_C1_LOW_IMAGE_SV, "C1 l�g-avbildning..." },
/* tr */ { IDMS_C1_LOW_IMAGE_TR, "C1 low imaj�..." },

/* en */ { IDMS_C1_HIGH_IMAGE,    "C1 high image..." },
/* da */ { IDMS_C1_HIGH_IMAGE_DA, "C1 h�j-image..." },
/* de */ { IDMS_C1_HIGH_IMAGE_DE, "C1 high Image Datei..." },
/* es */ { IDMS_C1_HIGH_IMAGE_ES, "C1 imagen alto..." },
/* fr */ { IDMS_C1_HIGH_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_C1_HIGH_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_C1_HIGH_IMAGE_IT, "Immagine C1 alta..." },
/* ko */ { IDMS_C1_HIGH_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_C1_HIGH_IMAGE_NL, "C1 high bestand..." },
/* pl */ { IDMS_C1_HIGH_IMAGE_PL, "Obraz C1 high..." },
/* ru */ { IDMS_C1_HIGH_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_C1_HIGH_IMAGE_SV, "C1 h�g-avbildning..." },
/* tr */ { IDMS_C1_HIGH_IMAGE_TR, "C1 high imaj�..." },

/* en */ { IDMS_C2_LOW_IMAGE,    "C2 low  image..." },
/* da */ { IDMS_C2_LOW_IMAGE_DA, "C2 lav-image..." },
/* de */ { IDMS_C2_LOW_IMAGE_DE, "C2 low  Image Datei..." },
/* es */ { IDMS_C2_LOW_IMAGE_ES, "C2 imagen bajo..." },
/* fr */ { IDMS_C2_LOW_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_C2_LOW_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_C2_LOW_IMAGE_IT, "Immagine C2 bassa..." },
/* ko */ { IDMS_C2_LOW_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_C2_LOW_IMAGE_NL, "C2 low bestand..." },
/* pl */ { IDMS_C2_LOW_IMAGE_PL, "Obraz C2 low..." },
/* ru */ { IDMS_C2_LOW_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_C2_LOW_IMAGE_SV, "C2 l�g-avbildning..." },
/* tr */ { IDMS_C2_LOW_IMAGE_TR, "C2 low imaj�..." },

/* en */ { IDMS_C2_HIGH_IMAGE,    "C2 high image..." },
/* da */ { IDMS_C2_HIGH_IMAGE_DA, "C2 h�j-image..." },
/* de */ { IDMS_C2_HIGH_IMAGE_DE, "C2 high Image Datei..." },
/* es */ { IDMS_C2_HIGH_IMAGE_ES, "C2 imagen alto..." },
/* fr */ { IDMS_C2_HIGH_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_C2_HIGH_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_C2_HIGH_IMAGE_IT, "Immagine C2 alta..." },
/* ko */ { IDMS_C2_HIGH_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_C2_HIGH_IMAGE_NL, "C2 high bestand..." },
/* pl */ { IDMS_C2_HIGH_IMAGE_PL, "Obraz C2 low..." },
/* ru */ { IDMS_C2_HIGH_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_C2_HIGH_IMAGE_SV, "C2 h�g-avbildning..." },
/* tr */ { IDMS_C2_HIGH_IMAGE_TR, "C2 high imaj�..." },

/* en */ { IDMS_FUNCTION_LOW_3PLUS1,    "Function low  image (3plus1)..." },
/* da */ { IDMS_FUNCTION_LOW_3PLUS1_DA, "Funktion lav-image (3plus1)..." },
/* de */ { IDMS_FUNCTION_LOW_3PLUS1_DE, "Funktions ROM Image Datei low (3plus1)..." },
/* es */ { IDMS_FUNCTION_LOW_3PLUS1_ES, "Funci�n imagen bajo (3plus1)..." },
/* fr */ { IDMS_FUNCTION_LOW_3PLUS1_FR, "" },  /* fuzzy */
/* hu */ { IDMS_FUNCTION_LOW_3PLUS1_HU, "" },  /* fuzzy */
/* it */ { IDMS_FUNCTION_LOW_3PLUS1_IT, "Immagine Function low (3plus1)..." },
/* ko */ { IDMS_FUNCTION_LOW_3PLUS1_KO, "" },  /* fuzzy */
/* nl */ { IDMS_FUNCTION_LOW_3PLUS1_NL, "Function low bestand (3plus1)..." },
/* pl */ { IDMS_FUNCTION_LOW_3PLUS1_PL, "Obraz Function low (3plus1)..." },
/* ru */ { IDMS_FUNCTION_LOW_3PLUS1_RU, "" },  /* fuzzy */
/* sv */ { IDMS_FUNCTION_LOW_3PLUS1_SV, "Funktion l�g-avbildning (3plus1)..." },
/* tr */ { IDMS_FUNCTION_LOW_3PLUS1_TR, "Function low  imaj� (3plus1)..." },

/* en */ { IDMS_FUNCTION_HIGH_3PLUS1,    "Function high image (3plus1)..." },
/* da */ { IDMS_FUNCTION_HIGH_3PLUS1_DA, "Funktion h�j-image (3plus1)..." },
/* de */ { IDMS_FUNCTION_HIGH_3PLUS1_DE, "Funktions ROM Image Datei high (3plus1)..." },
/* es */ { IDMS_FUNCTION_HIGH_3PLUS1_ES, "Funci�n imagen alto (3plus1)..." },
/* fr */ { IDMS_FUNCTION_HIGH_3PLUS1_FR, "" },  /* fuzzy */
/* hu */ { IDMS_FUNCTION_HIGH_3PLUS1_HU, "" },  /* fuzzy */
/* it */ { IDMS_FUNCTION_HIGH_3PLUS1_IT, "Immagine Function high (3plus1)..." },
/* ko */ { IDMS_FUNCTION_HIGH_3PLUS1_KO, "" },  /* fuzzy */
/* nl */ { IDMS_FUNCTION_HIGH_3PLUS1_NL, "Function high bestand (3plus1)..." },
/* pl */ { IDMS_FUNCTION_HIGH_3PLUS1_PL, "Obraz Function High (3plus1)..." },
/* ru */ { IDMS_FUNCTION_HIGH_3PLUS1_RU, "" },  /* fuzzy */
/* sv */ { IDMS_FUNCTION_HIGH_3PLUS1_SV, "Funktion h�g-avbildning (3plus1)..." },
/* tr */ { IDMS_FUNCTION_HIGH_3PLUS1_TR, "Function high imaj� (3plus1)..." },

/* en */ { IDMS_CRT_IMAGE,    "CRT image..." },
/* da */ { IDMS_CRT_IMAGE_DA, "CRT-fil..." },
/* de */ { IDMS_CRT_IMAGE_DE, "CRT Image..." },
/* es */ { IDMS_CRT_IMAGE_ES, "Imagen CRT..." },
/* fr */ { IDMS_CRT_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_CRT_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_CRT_IMAGE_IT, "Immagine CRT..." },
/* ko */ { IDMS_CRT_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_CRT_IMAGE_NL, "CRT bestand..." },
/* pl */ { IDMS_CRT_IMAGE_PL, "Obraz CRT..." },
/* ru */ { IDMS_CRT_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_CRT_IMAGE_SV, "CRT-fil..." },
/* tr */ { IDMS_CRT_IMAGE_TR, "CRT imaj�..." },

/* en */ { IDMS_GENERIC_8KB_IMAGE,    "Generic 8KB image..." },
/* da */ { IDMS_GENERIC_8KB_IMAGE_DA, "Standard 8KB-image..." },
/* de */ { IDMS_GENERIC_8KB_IMAGE_DE, "Generisches 8kB Image..." },
/* es */ { IDMS_GENERIC_8KB_IMAGE_ES, "Imagen generica 8KB..." },
/* fr */ { IDMS_GENERIC_8KB_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_GENERIC_8KB_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_GENERIC_8KB_IMAGE_IT, "Immagine generica di 8KB..." },
/* ko */ { IDMS_GENERIC_8KB_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_GENERIC_8KB_IMAGE_NL, "Algemeen 8KB bestand..." },
/* pl */ { IDMS_GENERIC_8KB_IMAGE_PL, "Obraz Generic 8KB..." },
/* ru */ { IDMS_GENERIC_8KB_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_GENERIC_8KB_IMAGE_SV, "Vanlig 8KB-fil..." },
/* tr */ { IDMS_GENERIC_8KB_IMAGE_TR, "8KB Jenerik imaj..." },

/* en */ { IDMS_GENERIC_16KB_IMAGE,    "Generic 16KB image..." },
/* da */ { IDMS_GENERIC_16KB_IMAGE_DA, "Standard 16KB-image..." },
/* de */ { IDMS_GENERIC_16KB_IMAGE_DE, "Generisches 16kB Image..." },
/* es */ { IDMS_GENERIC_16KB_IMAGE_ES, "Imagen generica 16KB..." },
/* fr */ { IDMS_GENERIC_16KB_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_GENERIC_16KB_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_GENERIC_16KB_IMAGE_IT, "Immagine generica di 16KB..." },
/* ko */ { IDMS_GENERIC_16KB_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_GENERIC_16KB_IMAGE_NL, "Algemeen 16KB bestand..." },
/* pl */ { IDMS_GENERIC_16KB_IMAGE_PL, "Obraz Generic 16KB..." },
/* ru */ { IDMS_GENERIC_16KB_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_GENERIC_16KB_IMAGE_SV, "Vanlig 16KB-fil..." },
/* tr */ { IDMS_GENERIC_16KB_IMAGE_TR, "16KB Jenerik imaj..." },

/* en */ { IDMS_ACTION_REPLAY_IMAGE,    "Action Replay image..." },
/* da */ { IDMS_ACTION_REPLAY_IMAGE_DA, "Action Replay-image..." },
/* de */ { IDMS_ACTION_REPLAY_IMAGE_DE, "Action Replay Image..." },
/* es */ { IDMS_ACTION_REPLAY_IMAGE_ES, "Imagen Action Replay..." },
/* fr */ { IDMS_ACTION_REPLAY_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ACTION_REPLAY_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_ACTION_REPLAY_IMAGE_IT, "Immagine Action Replay..." },
/* ko */ { IDMS_ACTION_REPLAY_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_ACTION_REPLAY_IMAGE_NL, "Action Replay bestand..." },
/* pl */ { IDMS_ACTION_REPLAY_IMAGE_PL, "Obraz Action Replay..." },
/* ru */ { IDMS_ACTION_REPLAY_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ACTION_REPLAY_IMAGE_SV, "Action Replay-fil..." },
/* tr */ { IDMS_ACTION_REPLAY_IMAGE_TR, "Action Replay imaj�..." },

/* en */ { IDMS_ACTION_REPLAY3_IMAGE,    "Action Replay MK3 image..." },
/* da */ { IDMS_ACTION_REPLAY3_IMAGE_DA, "Action Replay MK3 image..." },
/* de */ { IDMS_ACTION_REPLAY3_IMAGE_DE, "Action Replay MK3 Image..." },
/* es */ { IDMS_ACTION_REPLAY3_IMAGE_ES, "Imagen Action Replay MK3..." },
/* fr */ { IDMS_ACTION_REPLAY3_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ACTION_REPLAY3_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_ACTION_REPLAY3_IMAGE_IT, "Immagine Action Replay MK3..." },
/* ko */ { IDMS_ACTION_REPLAY3_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_ACTION_REPLAY3_IMAGE_NL, "Action Replay MK3 bestand..." },
/* pl */ { IDMS_ACTION_REPLAY3_IMAGE_PL, "Obraz Action Replay MK3..." },
/* ru */ { IDMS_ACTION_REPLAY3_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ACTION_REPLAY3_IMAGE_SV, "Action Replay MK3-fil..." },
/* tr */ { IDMS_ACTION_REPLAY3_IMAGE_TR, "Action Replay MK3 imaj�..." },

/* en */ { IDMS_ACTION_REPLAY4_IMAGE,    "Action Replay MK4 image..." },
/* da */ { IDMS_ACTION_REPLAY4_IMAGE_DA, "Action Replay MK4 image..." },
/* de */ { IDMS_ACTION_REPLAY4_IMAGE_DE, "Action Replay MK4 Image..." },
/* es */ { IDMS_ACTION_REPLAY4_IMAGE_ES, "Imagen Action Replay MK4..." },
/* fr */ { IDMS_ACTION_REPLAY4_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ACTION_REPLAY4_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_ACTION_REPLAY4_IMAGE_IT, "Immagine Action Replay MK4..." },
/* ko */ { IDMS_ACTION_REPLAY4_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_ACTION_REPLAY4_IMAGE_NL, "Action Replay MK4 bestand..." },
/* pl */ { IDMS_ACTION_REPLAY4_IMAGE_PL, "Obraz Action Replay MK4..." },
/* ru */ { IDMS_ACTION_REPLAY4_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ACTION_REPLAY4_IMAGE_SV, "Action Replay MK4-fil..." },
/* tr */ { IDMS_ACTION_REPLAY4_IMAGE_TR, "Action Replay MK4 imaj�..." },

/* en */ { IDMS_STARDOS_IMAGE,    "Stardos image..." },
/* da */ { IDMS_STARDOS_IMAGE_DA, "Stardos image..." },
/* de */ { IDMS_STARDOS_IMAGE_DE, "Stardos Image..." },
/* es */ { IDMS_STARDOS_IMAGE_ES, "Imagen Stardos..." },
/* fr */ { IDMS_STARDOS_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_STARDOS_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_STARDOS_IMAGE_IT, "Immagine Stardos..." },
/* ko */ { IDMS_STARDOS_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_STARDOS_IMAGE_NL, "Stardos bestand..." },
/* pl */ { IDMS_STARDOS_IMAGE_PL, "Obraz Stardos..." },
/* ru */ { IDMS_STARDOS_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_STARDOS_IMAGE_SV, "Stardos-fil..." },
/* tr */ { IDMS_STARDOS_IMAGE_TR, "Stardos imaj�..." },

/* en */ { IDMS_ATOMIC_POWER_IMAGE,    "Atomic Power image..." },
/* da */ { IDMS_ATOMIC_POWER_IMAGE_DA, "Atomic Power-image..." },
/* de */ { IDMS_ATOMIC_POWER_IMAGE_DE, "Atomic Power Image..." },
/* es */ { IDMS_ATOMIC_POWER_IMAGE_ES, "Imagen Atomic Power..." },
/* fr */ { IDMS_ATOMIC_POWER_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ATOMIC_POWER_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_ATOMIC_POWER_IMAGE_IT, "Immagine Atomic Power..." },
/* ko */ { IDMS_ATOMIC_POWER_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_ATOMIC_POWER_IMAGE_NL, "Atomic Power bestand..." },
/* pl */ { IDMS_ATOMIC_POWER_IMAGE_PL, "Obraz Atomic Power..." },
/* ru */ { IDMS_ATOMIC_POWER_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ATOMIC_POWER_IMAGE_SV, "Atomic Power-fil..." },
/* tr */ { IDMS_ATOMIC_POWER_IMAGE_TR, "Atomic Power imaj�..." },

/* en */ { IDMS_EPYX_FASTLOAD_IMAGE,    "Epyx FastLoad image..." },
/* da */ { IDMS_EPYX_FASTLOAD_IMAGE_DA, "Epyx FastLoad image..." },
/* de */ { IDMS_EPYX_FASTLOAD_IMAGE_DE, "Epyx Fastload Image..." },
/* es */ { IDMS_EPYX_FASTLOAD_IMAGE_ES, "Imagen Epyx FastLoad..." },
/* fr */ { IDMS_EPYX_FASTLOAD_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_EPYX_FASTLOAD_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_EPYX_FASTLOAD_IMAGE_IT, "Immagine Epyx FastLoad..." },
/* ko */ { IDMS_EPYX_FASTLOAD_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_EPYX_FASTLOAD_IMAGE_NL, "Epyx FastLoad bestand..." },
/* pl */ { IDMS_EPYX_FASTLOAD_IMAGE_PL, "Obraz Epyx FastLoad..." },
/* ru */ { IDMS_EPYX_FASTLOAD_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_EPYX_FASTLOAD_IMAGE_SV, "Epyx FastLoad-fil..." },
/* tr */ { IDMS_EPYX_FASTLOAD_IMAGE_TR, "Epyx FastLoad imaj�..." },

/* en */ { IDMS_IEEE488_INTERFACE_IMAGE,    "IEEE488 Interface image..." },
/* da */ { IDMS_IEEE488_INTERFACE_IMAGE_DA, "IEEE488-interface image..." },
/* de */ { IDMS_IEEE488_INTERFACE_IMAGE_DE, "IEEE 488 Schnittstellenmodul..." },
/* es */ { IDMS_IEEE488_INTERFACE_IMAGE_ES, "Imagen perif�rico IEEE 488..." },
/* fr */ { IDMS_IEEE488_INTERFACE_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_IEEE488_INTERFACE_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_IEEE488_INTERFACE_IMAGE_IT, "Immagine interfaccia IEEE 488..." },
/* ko */ { IDMS_IEEE488_INTERFACE_IMAGE_KO, "IEEE488 �������̽� �̹���..." },
/* nl */ { IDMS_IEEE488_INTERFACE_IMAGE_NL, "IEEE488 interfacebestand..." },
/* pl */ { IDMS_IEEE488_INTERFACE_IMAGE_PL, "Obraz interfejsu IEEE488..." },
/* ru */ { IDMS_IEEE488_INTERFACE_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_IEEE488_INTERFACE_IMAGE_SV, "IEEE488-gr�nssnittsfil..." },
/* tr */ { IDMS_IEEE488_INTERFACE_IMAGE_TR, "IEEE 488 Arabirimi imaj�..." },

/* en */ { IDMS_RETRO_REPLAY_IMAGE,    "Retro Replay image..." },
/* da */ { IDMS_RETRO_REPLAY_IMAGE_DA, "Retro Replay-image..." },
/* de */ { IDMS_RETRO_REPLAY_IMAGE_DE, "Retro Replay Image..." },
/* es */ { IDMS_RETRO_REPLAY_IMAGE_ES, "Imagen Retro Replay..." },
/* fr */ { IDMS_RETRO_REPLAY_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_RETRO_REPLAY_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_RETRO_REPLAY_IMAGE_IT, "Immagine Retro Replay..." },
/* ko */ { IDMS_RETRO_REPLAY_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_RETRO_REPLAY_IMAGE_NL, "Retro Replay bestand..." },
/* pl */ { IDMS_RETRO_REPLAY_IMAGE_PL, "Obraz Retro Replay..." },
/* ru */ { IDMS_RETRO_REPLAY_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_RETRO_REPLAY_IMAGE_SV, "Retro Replay-fil..." },
/* tr */ { IDMS_RETRO_REPLAY_IMAGE_TR, "Retro Replay imaj�..." },

/* en */ { IDMS_IDE64_INTERFACE_IMAGE,    "IDE64 interface image..." },
/* da */ { IDMS_IDE64_INTERFACE_IMAGE_DA, "IDE64-interface image..." },
/* de */ { IDMS_IDE64_INTERFACE_IMAGE_DE, "IDE64 Schnittstellenmodul..." },
/* es */ { IDMS_IDE64_INTERFACE_IMAGE_ES, "Imagen interface IDE64..." },
/* fr */ { IDMS_IDE64_INTERFACE_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_IDE64_INTERFACE_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_IDE64_INTERFACE_IMAGE_IT, "Immagine interfaccia IDE64..." },
/* ko */ { IDMS_IDE64_INTERFACE_IMAGE_KO, "IDE64 �������̽� �̹���..." },
/* nl */ { IDMS_IDE64_INTERFACE_IMAGE_NL, "IDE64 interfacebestand..." },
/* pl */ { IDMS_IDE64_INTERFACE_IMAGE_PL, "Obraz interfejsu IDE64..." },
/* ru */ { IDMS_IDE64_INTERFACE_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_IDE64_INTERFACE_IMAGE_SV, "IDE64-gr�nssnittsfil..." },
/* tr */ { IDMS_IDE64_INTERFACE_IMAGE_TR, "IDE64 arabirim imaj�..." },

/* en */ { IDMS_SUPER_SNAPSHOT_4_IMAGE,    "Super Snapshot V4 image..." },
/* da */ { IDMS_SUPER_SNAPSHOT_4_IMAGE_DA, "Super Snapshot V4 image..." },
/* de */ { IDMS_SUPER_SNAPSHOT_4_IMAGE_DE, "Super Snapshot V4 Image..." },
/* es */ { IDMS_SUPER_SNAPSHOT_4_IMAGE_ES, "Imagen Super Snapshot V4..." },
/* fr */ { IDMS_SUPER_SNAPSHOT_4_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_SUPER_SNAPSHOT_4_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_SUPER_SNAPSHOT_4_IMAGE_IT, "Immagine Super Snapshot V4..." },
/* ko */ { IDMS_SUPER_SNAPSHOT_4_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SUPER_SNAPSHOT_4_IMAGE_NL, "Super Snapshot V4 bestand..." },
/* pl */ { IDMS_SUPER_SNAPSHOT_4_IMAGE_PL, "Obraz Super Snapshot V4..." },
/* ru */ { IDMS_SUPER_SNAPSHOT_4_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SUPER_SNAPSHOT_4_IMAGE_SV, "Super Snapshot V4-fil..." },
/* tr */ { IDMS_SUPER_SNAPSHOT_4_IMAGE_TR, "Super Snapshot V4 imaj�..." },

/* en */ { IDMS_SUPER_SNAPSHOT_5_IMAGE,    "Super Snapshot V5 image..." },
/* da */ { IDMS_SUPER_SNAPSHOT_5_IMAGE_DA, "Super Snapshot V5 image..." },
/* de */ { IDMS_SUPER_SNAPSHOT_5_IMAGE_DE, "Super Snapshot V5 Image..." },
/* es */ { IDMS_SUPER_SNAPSHOT_5_IMAGE_ES, "Imagen Super Snapshot V5..." },
/* fr */ { IDMS_SUPER_SNAPSHOT_5_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_SUPER_SNAPSHOT_5_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_SUPER_SNAPSHOT_5_IMAGE_IT, "Immagine Super Snapshot V5..." },
/* ko */ { IDMS_SUPER_SNAPSHOT_5_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SUPER_SNAPSHOT_5_IMAGE_NL, "Super Snapshot V5 bestand..." },
/* pl */ { IDMS_SUPER_SNAPSHOT_5_IMAGE_PL, "Obraz Super Snapshot V5..." },
/* ru */ { IDMS_SUPER_SNAPSHOT_5_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SUPER_SNAPSHOT_5_IMAGE_SV, "Super Snapshot V5-fil..." },
/* tr */ { IDMS_SUPER_SNAPSHOT_5_IMAGE_TR, "Super Snapshot V5 imaj�..." },

/* en */ { IDMS_STRUCTURED_BASIC_IMAGE,    "Structured BASIC image..." },
/* da */ { IDMS_STRUCTURED_BASIC_IMAGE_DA, "Structured BASIC-image..." },
/* de */ { IDMS_STRUCTURED_BASIC_IMAGE_DE, "Structured Basic Image..." },
/* es */ { IDMS_STRUCTURED_BASIC_IMAGE_ES, "Imagen Structured BASIC..." },
/* fr */ { IDMS_STRUCTURED_BASIC_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_STRUCTURED_BASIC_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDMS_STRUCTURED_BASIC_IMAGE_IT, "Immagine Structured BASIC..." },
/* ko */ { IDMS_STRUCTURED_BASIC_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_STRUCTURED_BASIC_IMAGE_NL, "Structured BASIC bestand..." },
/* pl */ { IDMS_STRUCTURED_BASIC_IMAGE_PL, "Obraz Structured BASIC..." },
/* ru */ { IDMS_STRUCTURED_BASIC_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_STRUCTURED_BASIC_IMAGE_SV, "Structured BASIC-fil..." },
/* tr */ { IDMS_STRUCTURED_BASIC_IMAGE_TR, "Structured BASIC imaj�..." },

/* en */ { IDMS_ENABLE,    "Enable" },
/* da */ { IDMS_ENABLE_DA, "Aktiv�r" },
/* de */ { IDMS_ENABLE_DE, "Aktivieren" },
/* es */ { IDMS_ENABLE_ES, "Permitir" },
/* fr */ { IDMS_ENABLE_FR, "Activer" },
/* hu */ { IDMS_ENABLE_HU, "Enged�lyez�s" },
/* it */ { IDMS_ENABLE_IT, "Attivo" },
/* ko */ { IDMS_ENABLE_KO, "�۵���Ű��" },
/* nl */ { IDMS_ENABLE_NL, "Activeer" },
/* pl */ { IDMS_ENABLE_PL, "W��cz" },
/* ru */ { IDMS_ENABLE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ENABLE_SV, "Aktivera" },
/* tr */ { IDMS_ENABLE_TR, "Aktif Et" },

/* en */ { IDMS_SET_CART_AS_DEFAULT,    "Set cartridge as default" },
/* da */ { IDMS_SET_CART_AS_DEFAULT_DA, "V�lg cartridge som standard" },
/* de */ { IDMS_SET_CART_AS_DEFAULT_DE, "Aktuelles Erweiterungsmodul als Standard aktivieren" },
/* es */ { IDMS_SET_CART_AS_DEFAULT_ES, "Usar cartucho por defecto" },
/* fr */ { IDMS_SET_CART_AS_DEFAULT_FR, "D�finir cette cartouche par d�faut" },
/* hu */ { IDMS_SET_CART_AS_DEFAULT_HU, "Cartridge alap�rtelmezett� t�tele" },
/* it */ { IDMS_SET_CART_AS_DEFAULT_IT, "Imposta la cartuccia come predefinita" },
/* ko */ { IDMS_SET_CART_AS_DEFAULT_KO, "īƮ������ ����Ʈ �� �ϱ�" },
/* nl */ { IDMS_SET_CART_AS_DEFAULT_NL, "Zet cartridge als standaard" },
/* pl */ { IDMS_SET_CART_AS_DEFAULT_PL, "Ustaw kartrid� jako domy�lny" },
/* ru */ { IDMS_SET_CART_AS_DEFAULT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SET_CART_AS_DEFAULT_SV, "V�lj insticksmodul som f�rval" },
/* tr */ { IDMS_SET_CART_AS_DEFAULT_TR, "Kartu�u varsay�lan yap" },

/* en */ { IDMS_RESET_ON_CART_CHANGE,    "Reset on cart change" },
/* da */ { IDMS_RESET_ON_CART_CHANGE_DA, "Reset ved cartridge-skift" },
/* de */ { IDMS_RESET_ON_CART_CHANGE_DE, "Reset bei Wechsel von Erweiterungsmodulen" },
/* es */ { IDMS_RESET_ON_CART_CHANGE_ES, "Reiniciar al cambiar cartucho" },
/* fr */ { IDMS_RESET_ON_CART_CHANGE_FR, "R�inialiser sur changement de cartouche" },
/* hu */ { IDMS_RESET_ON_CART_CHANGE_HU, "�jraind�t�s cartridge cser�n�l" },
/* it */ { IDMS_RESET_ON_CART_CHANGE_IT, "Reset al cambio di cartuccia" },
/* ko */ { IDMS_RESET_ON_CART_CHANGE_KO, "īƮ���� ���� ����" },
/* nl */ { IDMS_RESET_ON_CART_CHANGE_NL, "Reset bij cartwisseling" },
/* pl */ { IDMS_RESET_ON_CART_CHANGE_PL, "Restart przy zmianie kartrid�a" },
/* ru */ { IDMS_RESET_ON_CART_CHANGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_RESET_ON_CART_CHANGE_SV, "Nollst�ll vid modulbyte" },
/* tr */ { IDMS_RESET_ON_CART_CHANGE_TR, "Kartu� de�i�iminde resetle" },

/* en */ { IDMS_CART_FREEZE,    "Cartridge freeze" },
/* da */ { IDMS_CART_FREEZE_DA, "Cartridgets frys-funktion" },
/* de */ { IDMS_CART_FREEZE_DE, "Erweiterungsmodul Freeze" },
/* es */ { IDMS_CART_FREEZE_ES, "Congelar cartucho" },
/* fr */ { IDMS_CART_FREEZE_FR, "Geler la cartouche" },
/* hu */ { IDMS_CART_FREEZE_HU, "Fagyaszt�s Cartridge-dzsel" },
/* it */ { IDMS_CART_FREEZE_IT, "Freeze cartuccia" },
/* ko */ { IDMS_CART_FREEZE_KO, "īƮ���� ������" },
/* nl */ { IDMS_CART_FREEZE_NL, "Cartridge freeze" },
/* pl */ { IDMS_CART_FREEZE_PL, "Zamro�enie kartrid�a" },
/* ru */ { IDMS_CART_FREEZE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_CART_FREEZE_SV, "Insticksmodulens frysfunktion" },
/* tr */ { IDMS_CART_FREEZE_TR, "Kartu� freeze" },

/* en */ { IDMS_PAUSE,    "Pause" },
/* da */ { IDMS_PAUSE_DA, "Pause" },
/* de */ { IDMS_PAUSE_DE, "Pause" },
/* es */ { IDMS_PAUSE_ES, "Pausa" },
/* fr */ { IDMS_PAUSE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_PAUSE_HU, "Sz�net" },
/* it */ { IDMS_PAUSE_IT, "Pausa" },
/* ko */ { IDMS_PAUSE_KO, "�Ͻ�����" },
/* nl */ { IDMS_PAUSE_NL, "Pauze" },
/* pl */ { IDMS_PAUSE_PL, "Pauza" },
/* ru */ { IDMS_PAUSE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_PAUSE_SV, "Paus" },
/* tr */ { IDMS_PAUSE_TR, "Duraklat" },

/* en */ { IDMS_MONITOR,    "Monitor" },
/* da */ { IDMS_MONITOR_DA, "Monitor" },
/* de */ { IDMS_MONITOR_DE, "Monitor" },
/* es */ { IDMS_MONITOR_ES, "Monitor" },
/* fr */ { IDMS_MONITOR_FR, "Moniteur" },
/* hu */ { IDMS_MONITOR_HU, "Monitor" },
/* it */ { IDMS_MONITOR_IT, "Monitor" },
/* ko */ { IDMS_MONITOR_KO, "�����" },
/* nl */ { IDMS_MONITOR_NL, "Monitor" },
/* pl */ { IDMS_MONITOR_PL, "Monitor" },
/* ru */ { IDMS_MONITOR_RU, "" },  /* fuzzy */
/* sv */ { IDMS_MONITOR_SV, "Monitor" },
/* tr */ { IDMS_MONITOR_TR, "Monit�r" },

/* en */ { IDMS_HARD,    "Hard" },
/* da */ { IDMS_HARD_DA, "H�rd" },
/* de */ { IDMS_HARD_DE, "Hart" },
/* es */ { IDMS_HARD_ES, "Hard" },
/* fr */ { IDMS_HARD_FR, "� froid" },
/* hu */ { IDMS_HARD_HU, "Hideg" },
/* it */ { IDMS_HARD_IT, "Hard" },
/* ko */ { IDMS_HARD_KO, "�ܴ���" },
/* nl */ { IDMS_HARD_NL, "Hard" },
/* pl */ { IDMS_HARD_PL, "Twardy" },
/* ru */ { IDMS_HARD_RU, "" },  /* fuzzy */
/* sv */ { IDMS_HARD_SV, "H�rd" },
/* tr */ { IDMS_HARD_TR, "Hard" },

/* en */ { IDMS_SOFT,    "Soft" },
/* da */ { IDMS_SOFT_DA, "Bl�d" },
/* de */ { IDMS_SOFT_DE, "Weich" },
/* es */ { IDMS_SOFT_ES, "Soft" },
/* fr */ { IDMS_SOFT_FR, "� chaud" },
/* hu */ { IDMS_SOFT_HU, "Meleg" },
/* it */ { IDMS_SOFT_IT, "Soft" },
/* ko */ { IDMS_SOFT_KO, "�ε巯��" },
/* nl */ { IDMS_SOFT_NL, "Zacht" },
/* pl */ { IDMS_SOFT_PL, "Mi�kki" },
/* ru */ { IDMS_SOFT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SOFT_SV, "Mjuk" },
/* tr */ { IDMS_SOFT_TR, "Soft" },

/* en */ { IDMS_EXIT,    "Exit" },
/* da */ { IDMS_EXIT_DA, "Afslut" },
/* de */ { IDMS_EXIT_DE, "Exit" },
/* es */ { IDMS_EXIT_ES, "Salir" },
/* fr */ { IDMS_EXIT_FR, "" },  /* fuzzy */
/* hu */ { IDMS_EXIT_HU, "Kil�p�s" },
/* it */ { IDMS_EXIT_IT, "Esci" },
/* ko */ { IDMS_EXIT_KO, "������" },
/* nl */ { IDMS_EXIT_NL, "Afsluiten" },
/* pl */ { IDMS_EXIT_PL, "Wyj�cie" },
/* ru */ { IDMS_EXIT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_EXIT_SV, "Avsluta" },
/* tr */ { IDMS_EXIT_TR, "��k��" },

/* en */ { IDMS_EDIT,    "Edit" },
/* da */ { IDMS_EDIT_DA, "Redig�r" },
/* de */ { IDMS_EDIT_DE, "Bearbeiten" },
/* es */ { IDMS_EDIT_ES, "Editar" },
/* fr */ { IDMS_EDIT_FR, "" },  /* fuzzy */
/* hu */ { IDMS_EDIT_HU, "Szerkeszt" },
/* it */ { IDMS_EDIT_IT, "Modifica" },
/* ko */ { IDMS_EDIT_KO, "����" },
/* nl */ { IDMS_EDIT_NL, "Bewerken" },
/* pl */ { IDMS_EDIT_PL, "Edycja" },
/* ru */ { IDMS_EDIT_RU, "������" },
/* sv */ { IDMS_EDIT_SV, "Redigera" },
/* tr */ { IDMS_EDIT_TR, "D�zenle" },

/* en */ { IDMS_COPY,    "Copy" },
/* da */ { IDMS_COPY_DA, "Kopi�r" },
/* de */ { IDMS_COPY_DE, "Kopie" },
/* es */ { IDMS_COPY_ES, "copiar" },
/* fr */ { IDMS_COPY_FR, "" },  /* fuzzy */
/* hu */ { IDMS_COPY_HU, "M�sol" },
/* it */ { IDMS_COPY_IT, "Copia" },
/* ko */ { IDMS_COPY_KO, "����" },
/* nl */ { IDMS_COPY_NL, "Kopie" },
/* pl */ { IDMS_COPY_PL, "Kopiuj" },
/* ru */ { IDMS_COPY_RU, "" },  /* fuzzy */
/* sv */ { IDMS_COPY_SV, "Kopiera" },
/* tr */ { IDMS_COPY_TR, "Kopyala" },

/* en */ { IDMS_PASTE,    "Paste" },
/* da */ { IDMS_PASTE_DA, "Inds�t" },
/* de */ { IDMS_PASTE_DE, "Einf�gen" },
/* es */ { IDMS_PASTE_ES, "Pegar" },
/* fr */ { IDMS_PASTE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_PASTE_HU, "Beilleszt" },
/* it */ { IDMS_PASTE_IT, "Incolla" },
/* ko */ { IDMS_PASTE_KO, "�ٿ��ֱ�" },
/* nl */ { IDMS_PASTE_NL, "Plakken" },
/* pl */ { IDMS_PASTE_PL, "Wklej" },
/* ru */ { IDMS_PASTE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_PASTE_SV, "Klistra in" },
/* tr */ { IDMS_PASTE_TR, "Yap��t�r" },

/* en */ { IDMS_SNAPSHOT,    "Snapshot" },
/* da */ { IDMS_SNAPSHOT_DA, "Snapshot" },
/* de */ { IDMS_SNAPSHOT_DE, "Snapshot" },
/* es */ { IDMS_SNAPSHOT_ES, "Snapshot" },
/* fr */ { IDMS_SNAPSHOT_FR, "Instantan�s" },
/* hu */ { IDMS_SNAPSHOT_HU, "Pillanatk�p" },
/* it */ { IDMS_SNAPSHOT_IT, "Snapshot" },
/* ko */ { IDMS_SNAPSHOT_KO, "������" },
/* nl */ { IDMS_SNAPSHOT_NL, "Momentopname" },
/* pl */ { IDMS_SNAPSHOT_PL, "Zrzut" },
/* ru */ { IDMS_SNAPSHOT_RU, "�������" },
/* sv */ { IDMS_SNAPSHOT_SV, "�gonblicksbild" },
/* tr */ { IDMS_SNAPSHOT_TR, "Anl�k G�r�nt�" },

/* en */ { IDMS_LOAD_SNAPSHOT_IMAGE,    "Load snapshot image..." },
/* da */ { IDMS_LOAD_SNAPSHOT_IMAGE_DA, "Indl�s snapshot..." },
/* de */ { IDMS_LOAD_SNAPSHOT_IMAGE_DE, "Snapshot laden..." },
/* es */ { IDMS_LOAD_SNAPSHOT_IMAGE_ES, "Cargar Imagen snapshot..." },
/* fr */ { IDMS_LOAD_SNAPSHOT_IMAGE_FR, "Charger le fichier de sauvegarde..." },
/* hu */ { IDMS_LOAD_SNAPSHOT_IMAGE_HU, "Pillanatk�p bet�lt�se..." },
/* it */ { IDMS_LOAD_SNAPSHOT_IMAGE_IT, "Carica immagine snapshot..." },
/* ko */ { IDMS_LOAD_SNAPSHOT_IMAGE_KO, "������ �̹��� �ҷ�����..." },
/* nl */ { IDMS_LOAD_SNAPSHOT_IMAGE_NL, "Laad momentopnamebestand..." },
/* pl */ { IDMS_LOAD_SNAPSHOT_IMAGE_PL, "Wczytaj obraz zrzutu..." },
/* ru */ { IDMS_LOAD_SNAPSHOT_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LOAD_SNAPSHOT_IMAGE_SV, "L�ser in �gonblicksbild..." },
/* tr */ { IDMS_LOAD_SNAPSHOT_IMAGE_TR, "Anl�k g�r�nt� imaj�n� y�kle..." },

/* en */ { IDMS_SAVE_SNAPSHOT_IMAGE,    "Save snapshot image..." },
/* da */ { IDMS_SAVE_SNAPSHOT_IMAGE_DA, "Gem snapshot..." },
/* de */ { IDMS_SAVE_SNAPSHOT_IMAGE_DE, "Snapshot Datei speichern..." },
/* es */ { IDMS_SAVE_SNAPSHOT_IMAGE_ES, "Grabar imagen de volcado de memoria..." },
/* fr */ { IDMS_SAVE_SNAPSHOT_IMAGE_FR, "Enregistrer le fichier de sauvegarde..." },
/* hu */ { IDMS_SAVE_SNAPSHOT_IMAGE_HU, "Pillanatk�p f�jl ment�se..." },
/* it */ { IDMS_SAVE_SNAPSHOT_IMAGE_IT, "Salva immagine snapshot..." },
/* ko */ { IDMS_SAVE_SNAPSHOT_IMAGE_KO, "������ �̹��� ����..." },
/* nl */ { IDMS_SAVE_SNAPSHOT_IMAGE_NL, "Momentopnamebestand opslaan..." },
/* pl */ { IDMS_SAVE_SNAPSHOT_IMAGE_PL, "Zapisz obraz zrzutu..." },
/* ru */ { IDMS_SAVE_SNAPSHOT_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SAVE_SNAPSHOT_IMAGE_SV, "Spara �gonblicksbildfil..." },
/* tr */ { IDMS_SAVE_SNAPSHOT_IMAGE_TR, "Anl�k g�r�nt� imaj�n� kaydet..." },

/* en */ { IDMS_START_STOP_RECORDING,    "Start/Stop Recording History" },
/* da */ { IDMS_START_STOP_RECORDING_DA, "Start/stop optagelse af historik" },
/* de */ { IDMS_START_STOP_RECORDING_DE, "Start/Stop Aufnahme History" },
/* es */ { IDMS_START_STOP_RECORDING_ES, "Iniciar/finalizar grabaci�n historial" },
/* fr */ { IDMS_START_STOP_RECORDING_FR, "D�marrer/Arr�ter l'historique de l'enregistrement" },
/* hu */ { IDMS_START_STOP_RECORDING_HU, "Esem�ny felv�tel ind�t�sa/meg�ll�t�sa" },
/* it */ { IDMS_START_STOP_RECORDING_IT, "Avvia/termina registrazione cronologia" },
/* ko */ { IDMS_START_STOP_RECORDING_KO, "" },  /* fuzzy */
/* nl */ { IDMS_START_STOP_RECORDING_NL, "Start/Stop Opnamegeschiedenis" },
/* pl */ { IDMS_START_STOP_RECORDING_PL, "Odtwarzaj/Zatrzymaj histori� zapisu" },
/* ru */ { IDMS_START_STOP_RECORDING_RU, "" },  /* fuzzy */
/* sv */ { IDMS_START_STOP_RECORDING_SV, "B�rja/sluta spela in h�ndelser" },
/* tr */ { IDMS_START_STOP_RECORDING_TR, "Kay�t Tarih�esini Ba�lat/Durdur" },

/* en */ { IDMS_START_STOP_PLAYBACK,    "Start/Stop Playback History" },
/* da */ { IDMS_START_STOP_PLAYBACK_DA, "Start/stop afspilning af historik" },
/* de */ { IDMS_START_STOP_PLAYBACK_DE, "Start/Stop Wiedergabe History" },
/* es */ { IDMS_START_STOP_PLAYBACK_ES, "Iniciar/finalizar reproducci�n historial" },
/* fr */ { IDMS_START_STOP_PLAYBACK_FR, "D�marrer/Arr�ter l'historique de la lecture" },
/* hu */ { IDMS_START_STOP_PLAYBACK_HU, "Esem�ny visszaj�tsz�s ind�t�sa/meg�ll�t�sa" },
/* it */ { IDMS_START_STOP_PLAYBACK_IT, "Avvia/termina riproduzione cronologia" },
/* ko */ { IDMS_START_STOP_PLAYBACK_KO, "" },  /* fuzzy */
/* nl */ { IDMS_START_STOP_PLAYBACK_NL, "Start/Stop Afspeelgeschiedenis" },
/* pl */ { IDMS_START_STOP_PLAYBACK_PL, "Odtwarzaj/Zatrzymaj histori� odtwarzania" },
/* ru */ { IDMS_START_STOP_PLAYBACK_RU, "" },  /* fuzzy */
/* sv */ { IDMS_START_STOP_PLAYBACK_SV, "B�rja/sluta spela upp h�ndelser" },
/* tr */ { IDMS_START_STOP_PLAYBACK_TR, "Kay�ttan Y�r�tme Tarih�esini Ba�lat/Durdur" },

/* en */ { IDMS_SET_MILESTONE,    "Set recording milestone" },
/* da */ { IDMS_SET_MILESTONE_DA, "Angiv optagelses-bogm�rke" },
/* de */ { IDMS_SET_MILESTONE_DE, "Setze Aufnahme Meilenstein" },
/* es */ { IDMS_SET_MILESTONE_ES, "Insertar marca de grabaci�n" },
/* fr */ { IDMS_SET_MILESTONE_FR, "Lever le signet d'enregistrement" },
/* hu */ { IDMS_SET_MILESTONE_HU, "Kil�m�terk� elhelyez�se a felv�telben" },
/* it */ { IDMS_SET_MILESTONE_IT, "Imposta segnalibro" },
/* ko */ { IDMS_SET_MILESTONE_KO, "���ڵ� ���Ͻ��� ����" },
/* nl */ { IDMS_SET_MILESTONE_NL, "Zet opname mijlpaal" },
/* pl */ { IDMS_SET_MILESTONE_PL, "Ustaw kamie� milowy zapisu" },
/* ru */ { IDMS_SET_MILESTONE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SET_MILESTONE_SV, "Ange inspelningsbokm�rke" },
/* tr */ { IDMS_SET_MILESTONE_TR, "Kay�t kilometre ta�� koy" },

/* en */ { IDMS_RETURN_TO_MILESTONE,    "Return to milestone" },
/* da */ { IDMS_RETURN_TO_MILESTONE_DA, "G� til bogm�rke" },
/* de */ { IDMS_RETURN_TO_MILESTONE_DE, "R�ckkehr zum Meilenstein" },
/* es */ { IDMS_RETURN_TO_MILESTONE_ES, "Volver a la marca" },
/* fr */ { IDMS_RETURN_TO_MILESTONE_FR, "Retourner au signet d'enregistrement" },
/* hu */ { IDMS_RETURN_TO_MILESTONE_HU, "Visszaugr�s az el�z� kil�m�terk�h�z" },
/* it */ { IDMS_RETURN_TO_MILESTONE_IT, "Vai al segnalibro" },
/* ko */ { IDMS_RETURN_TO_MILESTONE_KO, "���Ͻ��� ���� ���ư���" },
/* nl */ { IDMS_RETURN_TO_MILESTONE_NL, "Ga terug naar mijlpaal" },
/* pl */ { IDMS_RETURN_TO_MILESTONE_PL, "Powr�� do kamienia milowego" },
/* ru */ { IDMS_RETURN_TO_MILESTONE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_RETURN_TO_MILESTONE_SV, "�terg� till bokm�rke" },
/* tr */ { IDMS_RETURN_TO_MILESTONE_TR, "Kilometre ta��na geri d�n" },

/* en */ { IDMS_RECORDING_START_MODE,    "Recording start mode" },
/* da */ { IDMS_RECORDING_START_MODE_DA, "Start-tilstand for optagelse" },
/* de */ { IDMS_RECORDING_START_MODE_DE, "Aufnahme Start Modus" },
/* es */ { IDMS_RECORDING_START_MODE_ES, "Grabar modo de inicio" },
/* fr */ { IDMS_RECORDING_START_MODE_FR, "Mode de d�part d'enregistrement" },
/* hu */ { IDMS_RECORDING_START_MODE_HU, "R�gz�t�s ind�t�s�nak m�dja" },
/* it */ { IDMS_RECORDING_START_MODE_IT, "Modalit� di avvio registrazione" },
/* ko */ { IDMS_RECORDING_START_MODE_KO, "���ڵ� ���� ���" },
/* nl */ { IDMS_RECORDING_START_MODE_NL, "Opname start modus" },
/* pl */ { IDMS_RECORDING_START_MODE_PL, "Rozpocznij tryb zapisu" },
/* ru */ { IDMS_RECORDING_START_MODE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_RECORDING_START_MODE_SV, "Spelar in startl�ge" },
/* tr */ { IDMS_RECORDING_START_MODE_TR, "Kay�t ba�lang�� modu" },

/* en */ { IDMS_SAVE_NEW_SNAPSHOT,    "Save new snapshot" },
/* da */ { IDMS_SAVE_NEW_SNAPSHOT_DA, "Gem nyt snapshot" },
/* de */ { IDMS_SAVE_NEW_SNAPSHOT_DE, "Speichere neuen Snapshot" },
/* es */ { IDMS_SAVE_NEW_SNAPSHOT_ES, "Grabando nuevo snapshot" },
/* fr */ { IDMS_SAVE_NEW_SNAPSHOT_FR, "Enregistrer une nouvelle sauvegarde" },
/* hu */ { IDMS_SAVE_NEW_SNAPSHOT_HU, "�j pillanatk�p ment�se" },
/* it */ { IDMS_SAVE_NEW_SNAPSHOT_IT, "Salva nuovo snapshot" },
/* ko */ { IDMS_SAVE_NEW_SNAPSHOT_KO, "���ο� ������ ����" },
/* nl */ { IDMS_SAVE_NEW_SNAPSHOT_NL, "Opslaan nieuwe momentopname" },
/* pl */ { IDMS_SAVE_NEW_SNAPSHOT_PL, "Zapisz nowy zrzut" },
/* ru */ { IDMS_SAVE_NEW_SNAPSHOT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SAVE_NEW_SNAPSHOT_SV, "Spara ny �gonblicksbild" },
/* tr */ { IDMS_SAVE_NEW_SNAPSHOT_TR, "Yeni anl�k g�r�nt� kaydet" },

/* en */ { IDMS_LOAD_EXISTING_SNAPSHOT,    "Load existing snapshot" },
/* da */ { IDMS_LOAD_EXISTING_SNAPSHOT_DA, "Indl�s eksisterende snapshot" },
/* de */ { IDMS_LOAD_EXISTING_SNAPSHOT_DE, "Lade existierenden Snapshot" },
/* es */ { IDMS_LOAD_EXISTING_SNAPSHOT_ES, "Cargando snapshot" },
/* fr */ { IDMS_LOAD_EXISTING_SNAPSHOT_FR, "Charger un instantan�" },
/* hu */ { IDMS_LOAD_EXISTING_SNAPSHOT_HU, "L�tez� pillanatk�p bet�lt�se" },
/* it */ { IDMS_LOAD_EXISTING_SNAPSHOT_IT, "Carica snapshot esistente" },
/* ko */ { IDMS_LOAD_EXISTING_SNAPSHOT_KO, "�����ϴ� ������ �ҷ�����" },
/* nl */ { IDMS_LOAD_EXISTING_SNAPSHOT_NL, "Laad bestaande momentopname" },
/* pl */ { IDMS_LOAD_EXISTING_SNAPSHOT_PL, "Wczytaj istniej�cy zrzut" },
/* ru */ { IDMS_LOAD_EXISTING_SNAPSHOT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LOAD_EXISTING_SNAPSHOT_SV, "L�s in existerande �gonblicksbild" },
/* tr */ { IDMS_LOAD_EXISTING_SNAPSHOT_TR, "Varolan anl�k g�r�nt�y� y�kle" },

/* en */ { IDMS_START_WITH_RESET,    "Start with reset" },
/* da */ { IDMS_START_WITH_RESET_DA, "Start med reset" },
/* de */ { IDMS_START_WITH_RESET_DE, "Mit Reset starten" },
/* es */ { IDMS_START_WITH_RESET_ES, "Comenzar con reinicio" },
/* fr */ { IDMS_START_WITH_RESET_FR, "R�initialiser au d�marrage" },
/* hu */ { IDMS_START_WITH_RESET_HU, "Indul�s RESET-tel" },
/* it */ { IDMS_START_WITH_RESET_IT, "Avvia con reset" },
/* ko */ { IDMS_START_WITH_RESET_KO, "�������� �����ϱ�" },
/* nl */ { IDMS_START_WITH_RESET_NL, "Start met reset" },
/* pl */ { IDMS_START_WITH_RESET_PL, "Rozpocznij z resetem" },
/* ru */ { IDMS_START_WITH_RESET_RU, "" },  /* fuzzy */
/* sv */ { IDMS_START_WITH_RESET_SV, "Starta med nollst�llning" },
/* tr */ { IDMS_START_WITH_RESET_TR, "Reset ile ba�lat" },

/* en */ { IDMS_OVERWRITE_PLAYBACK,    "Overwrite Playback" },
/* da */ { IDMS_OVERWRITE_PLAYBACK_DA, "Overskriv afspilning" },
/* de */ { IDMS_OVERWRITE_PLAYBACK_DE, "Laufende Aufnahme �berschreiben" },
/* es */ { IDMS_OVERWRITE_PLAYBACK_ES, "Sobreescribir reproducci�n" },
/* fr */ { IDMS_OVERWRITE_PLAYBACK_FR, "�craser la lecture actuelle" },
/* hu */ { IDMS_OVERWRITE_PLAYBACK_HU, "Visszaj�tsz�s fel�l�r�sa" },
/* it */ { IDMS_OVERWRITE_PLAYBACK_IT, "Sovrascrivi riproduzione" },
/* ko */ { IDMS_OVERWRITE_PLAYBACK_KO, "" },  /* fuzzy */
/* nl */ { IDMS_OVERWRITE_PLAYBACK_NL, "Overschrijf weergave" },
/* pl */ { IDMS_OVERWRITE_PLAYBACK_PL, "Nadpisuj wyj�ciowy sygna�" },
/* ru */ { IDMS_OVERWRITE_PLAYBACK_RU, "" },  /* fuzzy */
/* sv */ { IDMS_OVERWRITE_PLAYBACK_SV, "Skriv �ver aktiv uppspelning" },
/* tr */ { IDMS_OVERWRITE_PLAYBACK_TR, "Kay�ttan Y�r�tmenin �zerine Yaz" },

/* en */ { IDMS_SELECT_HISTORY_DIR,    "Select History files/directory" },
/* da */ { IDMS_SELECT_HISTORY_DIR_DA, "V�lg historikfiler/-katalog" },
/* de */ { IDMS_SELECT_HISTORY_DIR_DE, "Verzeichnis f�r Event Aufnahme" },
/* es */ { IDMS_SELECT_HISTORY_DIR_ES, "Seleccionar historial ficheros/directorios" },
/* fr */ { IDMS_SELECT_HISTORY_DIR_FR, "S�lectionnez le r�pertoire des captures" },
/* hu */ { IDMS_SELECT_HISTORY_DIR_HU, "V�lassza ki a felv�teleket/k�nyvt�rat" },
/* it */ { IDMS_SELECT_HISTORY_DIR_IT, "Seleziona file/directory della cronologia" },
/* ko */ { IDMS_SELECT_HISTORY_DIR_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SELECT_HISTORY_DIR_NL, "Selecteer geschiedenisdirectory" },
/* pl */ { IDMS_SELECT_HISTORY_DIR_PL, "Wybierz pliki lub katalog historii" },
/* ru */ { IDMS_SELECT_HISTORY_DIR_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SELECT_HISTORY_DIR_SV, "V�lj historikfiler/-katalog" },
/* tr */ { IDMS_SELECT_HISTORY_DIR_TR, "Tarih�e dosyalar�/dizin se�" },

/* en */ { IDMS_SAVE_STOP_MEDIA_FILE,    "Save/stop media file..." },
/* da */ { IDMS_SAVE_STOP_MEDIA_FILE_DA, "Gem/stop mediefil..." },
/* de */ { IDMS_SAVE_STOP_MEDIA_FILE_DE, "Speichern/stop media Datei..." },
/* es */ { IDMS_SAVE_STOP_MEDIA_FILE_ES, "Grabar/Parar fichero media..." },
/* fr */ { IDMS_SAVE_STOP_MEDIA_FILE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_SAVE_STOP_MEDIA_FILE_HU, "" },  /* fuzzy */
/* it */ { IDMS_SAVE_STOP_MEDIA_FILE_IT, "Salva/arresta file multimediale..." },
/* ko */ { IDMS_SAVE_STOP_MEDIA_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SAVE_STOP_MEDIA_FILE_NL, "Opslaan/stop mediabestand..." },
/* pl */ { IDMS_SAVE_STOP_MEDIA_FILE_PL, "Zapisz i zatrzymaj plik multimedi�w..." },
/* ru */ { IDMS_SAVE_STOP_MEDIA_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SAVE_STOP_MEDIA_FILE_SV, "Starta/stoppa mediafil..." },
/* tr */ { IDMS_SAVE_STOP_MEDIA_FILE_TR, "Ortam dosyas� kaydet/durdur..." },

/* en */ { IDMS_NETPLAY,    "Netplay (experimental)..." },
/* da */ { IDMS_NETPLAY_DA, "Netv�rksspil (eksperimentelt)..." },
/* de */ { IDMS_NETPLAY_DE, "Netplay (experimentell)..." },
/* es */ { IDMS_NETPLAY_ES, "Juego en red (experimental)..." },
/* fr */ { IDMS_NETPLAY_FR, "Jeu en r�seau (experimental)..." },
/* hu */ { IDMS_NETPLAY_HU, "H�l�zati j�t�k (k�s�rleti)..." },
/* it */ { IDMS_NETPLAY_IT, "Netplay (sperimentale)..." },
/* ko */ { IDMS_NETPLAY_KO, "���÷��� (������)..." },
/* nl */ { IDMS_NETPLAY_NL, "Netplay (experimenteel)..." },
/* pl */ { IDMS_NETPLAY_PL, "Netplay (eksperymentalne)..." },
/* ru */ { IDMS_NETPLAY_RU, "" },  /* fuzzy */
/* sv */ { IDMS_NETPLAY_SV, "N�tverksspel (experimentellt)..." },
/* tr */ { IDMS_NETPLAY_TR, "Netplay (deneysel)..." },

/* en */ { IDMS_OPTIONS,    "Options" },
/* da */ { IDMS_OPTIONS_DA, "Valg" },
/* de */ { IDMS_OPTIONS_DE, "Optionen" },
/* es */ { IDMS_OPTIONS_ES, "Opcciones" },
/* fr */ { IDMS_OPTIONS_FR, "Options" },
/* hu */ { IDMS_OPTIONS_HU, "Opci�k" },
/* it */ { IDMS_OPTIONS_IT, "Opzioni" },
/* ko */ { IDMS_OPTIONS_KO, "����" },
/* nl */ { IDMS_OPTIONS_NL, "Opties" },
/* pl */ { IDMS_OPTIONS_PL, "Opcje" },
/* ru */ { IDMS_OPTIONS_RU, "�����" },
/* sv */ { IDMS_OPTIONS_SV, "Alternativ" },
/* tr */ { IDMS_OPTIONS_TR, "Se�enekler" },

/* en */ { IDMS_REFRESH_RATE,    "Refresh rate" },
/* da */ { IDMS_REFRESH_RATE_DA, "Opdateringsfrekvens" },
/* de */ { IDMS_REFRESH_RATE_DE, "Wiederholrate" },
/* es */ { IDMS_REFRESH_RATE_ES, "Velocidad de refresco" },
/* fr */ { IDMS_REFRESH_RATE_FR, "Taux de rafra�chissement" },
/* hu */ { IDMS_REFRESH_RATE_HU, "Friss�t�si r�ta" },
/* it */ { IDMS_REFRESH_RATE_IT, "Frequenza di aggiornamento" },
/* ko */ { IDMS_REFRESH_RATE_KO, "�����" },
/* nl */ { IDMS_REFRESH_RATE_NL, "Vernieuwing snelheid" },
/* pl */ { IDMS_REFRESH_RATE_PL, "Cz�stotliwo�� od�wie�ania" },
/* ru */ { IDMS_REFRESH_RATE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_REFRESH_RATE_SV, "Uppdateringshastighet" },
/* tr */ { IDMS_REFRESH_RATE_TR, "Yenileme h�z�" },

/* en */ { IDMS_AUTO,    "Auto" },
/* da */ { IDMS_AUTO_DA, "Auto" },
/* de */ { IDMS_AUTO_DE, "Automatisch" },
/* es */ { IDMS_AUTO_ES, "Auto" },
/* fr */ { IDMS_AUTO_FR, "Automatique" },
/* hu */ { IDMS_AUTO_HU, "Automatikus" },
/* it */ { IDMS_AUTO_IT, "Auto" },
/* ko */ { IDMS_AUTO_KO, "�ڵ�" },
/* nl */ { IDMS_AUTO_NL, "Auto" },
/* pl */ { IDMS_AUTO_PL, "Automatyczna" },
/* ru */ { IDMS_AUTO_RU, "" },  /* fuzzy */
/* sv */ { IDMS_AUTO_SV, "Auto" },
/* tr */ { IDMS_AUTO_TR, "Otomatik" },

/* en */ { IDMS_1_1,    "1/1" },
/* da */ { IDMS_1_1_DA, "1/1" },
/* de */ { IDMS_1_1_DE, "1/1" },
/* es */ { IDMS_1_1_ES, "1/1" },
/* fr */ { IDMS_1_1_FR, "1/1" },
/* hu */ { IDMS_1_1_HU, "" },  /* fuzzy */
/* it */ { IDMS_1_1_IT, "1/1" },
/* ko */ { IDMS_1_1_KO, "1/1" },
/* nl */ { IDMS_1_1_NL, "1/1" },
/* pl */ { IDMS_1_1_PL, "1/1" },
/* ru */ { IDMS_1_1_RU, "" },  /* fuzzy */
/* sv */ { IDMS_1_1_SV, "1/1" },
/* tr */ { IDMS_1_1_TR, "1/1" },

/* en */ { IDMS_1_2,    "1/2" },
/* da */ { IDMS_1_2_DA, "1/2" },
/* de */ { IDMS_1_2_DE, "1/2" },
/* es */ { IDMS_1_2_ES, "1/2" },
/* fr */ { IDMS_1_2_FR, "1/2" },
/* hu */ { IDMS_1_2_HU, "" },  /* fuzzy */
/* it */ { IDMS_1_2_IT, "1/2" },
/* ko */ { IDMS_1_2_KO, "1/2" },
/* nl */ { IDMS_1_2_NL, "1/2" },
/* pl */ { IDMS_1_2_PL, "1/2" },
/* ru */ { IDMS_1_2_RU, "" },  /* fuzzy */
/* sv */ { IDMS_1_2_SV, "1/2" },
/* tr */ { IDMS_1_2_TR, "1/2" },

/* en */ { IDMS_1_3,    "1/3" },
/* da */ { IDMS_1_3_DA, "1/3" },
/* de */ { IDMS_1_3_DE, "1/3" },
/* es */ { IDMS_1_3_ES, "1/3" },
/* fr */ { IDMS_1_3_FR, "1/3" },
/* hu */ { IDMS_1_3_HU, "" },  /* fuzzy */
/* it */ { IDMS_1_3_IT, "1/3" },
/* ko */ { IDMS_1_3_KO, "1/3" },
/* nl */ { IDMS_1_3_NL, "1/3" },
/* pl */ { IDMS_1_3_PL, "1/3" },
/* ru */ { IDMS_1_3_RU, "" },  /* fuzzy */
/* sv */ { IDMS_1_3_SV, "1/3" },
/* tr */ { IDMS_1_3_TR, "1/3" },

/* en */ { IDMS_1_4,    "1/4" },
/* da */ { IDMS_1_4_DA, "1/4" },
/* de */ { IDMS_1_4_DE, "1/4" },
/* es */ { IDMS_1_4_ES, "1/4" },
/* fr */ { IDMS_1_4_FR, "1/4" },
/* hu */ { IDMS_1_4_HU, "" },  /* fuzzy */
/* it */ { IDMS_1_4_IT, "1/4" },
/* ko */ { IDMS_1_4_KO, "1/4" },
/* nl */ { IDMS_1_4_NL, "1/4" },
/* pl */ { IDMS_1_4_PL, "1/4" },
/* ru */ { IDMS_1_4_RU, "" },  /* fuzzy */
/* sv */ { IDMS_1_4_SV, "1/4" },
/* tr */ { IDMS_1_4_TR, "1/4" },

/* en */ { IDMS_1_5,    "1/5" },
/* da */ { IDMS_1_5_DA, "1/5" },
/* de */ { IDMS_1_5_DE, "1/5" },
/* es */ { IDMS_1_5_ES, "1/5" },
/* fr */ { IDMS_1_5_FR, "1/5" },
/* hu */ { IDMS_1_5_HU, "" },  /* fuzzy */
/* it */ { IDMS_1_5_IT, "1/5" },
/* ko */ { IDMS_1_5_KO, "1/5" },
/* nl */ { IDMS_1_5_NL, "1/5" },
/* pl */ { IDMS_1_5_PL, "1/5" },
/* ru */ { IDMS_1_5_RU, "" },  /* fuzzy */
/* sv */ { IDMS_1_5_SV, "1/5" },
/* tr */ { IDMS_1_5_TR, "1/5" },

/* en */ { IDMS_1_6,    "1/6" },
/* da */ { IDMS_1_6_DA, "1/6" },
/* de */ { IDMS_1_6_DE, "1/6" },
/* es */ { IDMS_1_6_ES, "1/6" },
/* fr */ { IDMS_1_6_FR, "1/6" },
/* hu */ { IDMS_1_6_HU, "" },  /* fuzzy */
/* it */ { IDMS_1_6_IT, "1/6" },
/* ko */ { IDMS_1_6_KO, "1/6" },
/* nl */ { IDMS_1_6_NL, "1/6" },
/* pl */ { IDMS_1_6_PL, "1/6" },
/* ru */ { IDMS_1_6_RU, "" },  /* fuzzy */
/* sv */ { IDMS_1_6_SV, "1/6" },
/* tr */ { IDMS_1_6_TR, "1/6" },

/* en */ { IDMS_1_7,    "1/7" },
/* da */ { IDMS_1_7_DA, "1/7" },
/* de */ { IDMS_1_7_DE, "1/7" },
/* es */ { IDMS_1_7_ES, "1/7" },
/* fr */ { IDMS_1_7_FR, "1/7" },
/* hu */ { IDMS_1_7_HU, "" },  /* fuzzy */
/* it */ { IDMS_1_7_IT, "1/7" },
/* ko */ { IDMS_1_7_KO, "1/7" },
/* nl */ { IDMS_1_7_NL, "1/7" },
/* pl */ { IDMS_1_7_PL, "1/7" },
/* ru */ { IDMS_1_7_RU, "" },  /* fuzzy */
/* sv */ { IDMS_1_7_SV, "1/7" },
/* tr */ { IDMS_1_7_TR, "1/7" },

/* en */ { IDMS_1_8,    "1/8" },
/* da */ { IDMS_1_8_DA, "1/8" },
/* de */ { IDMS_1_8_DE, "1/8" },
/* es */ { IDMS_1_8_ES, "1/8" },
/* fr */ { IDMS_1_8_FR, "1/8" },
/* hu */ { IDMS_1_8_HU, "" },  /* fuzzy */
/* it */ { IDMS_1_8_IT, "1/8" },
/* ko */ { IDMS_1_8_KO, "1/8" },
/* nl */ { IDMS_1_8_NL, "1/8" },
/* pl */ { IDMS_1_8_PL, "1/8" },
/* ru */ { IDMS_1_8_RU, "" },  /* fuzzy */
/* sv */ { IDMS_1_8_SV, "1/8" },
/* tr */ { IDMS_1_8_TR, "1/8" },

/* en */ { IDMS_1_9,    "1/9" },
/* da */ { IDMS_1_9_DA, "1/9" },
/* de */ { IDMS_1_9_DE, "1/9" },
/* es */ { IDMS_1_9_ES, "1/9" },
/* fr */ { IDMS_1_9_FR, "1/9" },
/* hu */ { IDMS_1_9_HU, "" },  /* fuzzy */
/* it */ { IDMS_1_9_IT, "1/9" },
/* ko */ { IDMS_1_9_KO, "1/9" },
/* nl */ { IDMS_1_9_NL, "1/9" },
/* pl */ { IDMS_1_9_PL, "1/9" },
/* ru */ { IDMS_1_9_RU, "" },  /* fuzzy */
/* sv */ { IDMS_1_9_SV, "1/9" },
/* tr */ { IDMS_1_9_TR, "1/9" },

/* en */ { IDMS_1_10,    "1/10" },
/* da */ { IDMS_1_10_DA, "1/10" },
/* de */ { IDMS_1_10_DE, "1/10" },
/* es */ { IDMS_1_10_ES, "1/10" },
/* fr */ { IDMS_1_10_FR, "1/10" },
/* hu */ { IDMS_1_10_HU, "" },  /* fuzzy */
/* it */ { IDMS_1_10_IT, "1/10" },
/* ko */ { IDMS_1_10_KO, "1/10" },
/* nl */ { IDMS_1_10_NL, "1/10" },
/* pl */ { IDMS_1_10_PL, "1/10" },
/* ru */ { IDMS_1_10_RU, "" },  /* fuzzy */
/* sv */ { IDMS_1_10_SV, "1/10" },
/* tr */ { IDMS_1_10_TR, "1/10" },

/* en */ { IDMS_MAXIMUM_SPEED,    "Maximum speed" },
/* da */ { IDMS_MAXIMUM_SPEED_DA, "Maksimal hastighed" },
/* de */ { IDMS_MAXIMUM_SPEED_DE, "Maximale Geschwindigkeit" },
/* es */ { IDMS_MAXIMUM_SPEED_ES, "Velocidad m�xima" },
/* fr */ { IDMS_MAXIMUM_SPEED_FR, "Vitesse maximale" },
/* hu */ { IDMS_MAXIMUM_SPEED_HU, "Maxim�lis sebess�g" },
/* it */ { IDMS_MAXIMUM_SPEED_IT, "Velocit� massima" },
/* ko */ { IDMS_MAXIMUM_SPEED_KO, "" },  /* fuzzy */
/* nl */ { IDMS_MAXIMUM_SPEED_NL, "Maximale snelheid" },
/* pl */ { IDMS_MAXIMUM_SPEED_PL, "Maksymalna pr�dko��" },
/* ru */ { IDMS_MAXIMUM_SPEED_RU, "" },  /* fuzzy */
/* sv */ { IDMS_MAXIMUM_SPEED_SV, "Maximal hastighet" },
/* tr */ { IDMS_MAXIMUM_SPEED_TR, "Maksimum h�z" },

/* en */ { IDMS_200_PERCENT,    "200%" },
/* da */ { IDMS_200_PERCENT_DA, "200%" },
/* de */ { IDMS_200_PERCENT_DE, "200%" },
/* es */ { IDMS_200_PERCENT_ES, "200%" },
/* fr */ { IDMS_200_PERCENT_FR, "200%" },
/* hu */ { IDMS_200_PERCENT_HU, "" },  /* fuzzy */
/* it */ { IDMS_200_PERCENT_IT, "200%" },
/* ko */ { IDMS_200_PERCENT_KO, "200%" },
/* nl */ { IDMS_200_PERCENT_NL, "200%" },
/* pl */ { IDMS_200_PERCENT_PL, "200%" },
/* ru */ { IDMS_200_PERCENT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_200_PERCENT_SV, "200%" },
/* tr */ { IDMS_200_PERCENT_TR, "200%" },

/* en */ { IDMS_100_PERCENT,    "100%" },
/* da */ { IDMS_100_PERCENT_DA, "100%" },
/* de */ { IDMS_100_PERCENT_DE, "100%" },
/* es */ { IDMS_100_PERCENT_ES, "100%" },
/* fr */ { IDMS_100_PERCENT_FR, "100%" },
/* hu */ { IDMS_100_PERCENT_HU, "" },  /* fuzzy */
/* it */ { IDMS_100_PERCENT_IT, "100%" },
/* ko */ { IDMS_100_PERCENT_KO, "100%" },
/* nl */ { IDMS_100_PERCENT_NL, "100%" },
/* pl */ { IDMS_100_PERCENT_PL, "100%" },
/* ru */ { IDMS_100_PERCENT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_100_PERCENT_SV, "100%" },
/* tr */ { IDMS_100_PERCENT_TR, "100%" },

/* en */ { IDMS_50_PERCENT,    "50%" },
/* da */ { IDMS_50_PERCENT_DA, "50%" },
/* de */ { IDMS_50_PERCENT_DE, "50%" },
/* es */ { IDMS_50_PERCENT_ES, "50%" },
/* fr */ { IDMS_50_PERCENT_FR, "50%" },
/* hu */ { IDMS_50_PERCENT_HU, "" },  /* fuzzy */
/* it */ { IDMS_50_PERCENT_IT, "50%" },
/* ko */ { IDMS_50_PERCENT_KO, "50%" },
/* nl */ { IDMS_50_PERCENT_NL, "50%" },
/* pl */ { IDMS_50_PERCENT_PL, "50%" },
/* ru */ { IDMS_50_PERCENT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_50_PERCENT_SV, "50%" },
/* tr */ { IDMS_50_PERCENT_TR, "50%" },

/* en */ { IDMS_20_PERCENT,    "20%" },
/* da */ { IDMS_20_PERCENT_DA, "20%" },
/* de */ { IDMS_20_PERCENT_DE, "20%" },
/* es */ { IDMS_20_PERCENT_ES, "20%" },
/* fr */ { IDMS_20_PERCENT_FR, "20%" },
/* hu */ { IDMS_20_PERCENT_HU, "" },  /* fuzzy */
/* it */ { IDMS_20_PERCENT_IT, "20%" },
/* ko */ { IDMS_20_PERCENT_KO, "20%" },
/* nl */ { IDMS_20_PERCENT_NL, "20%" },
/* pl */ { IDMS_20_PERCENT_PL, "20%" },
/* ru */ { IDMS_20_PERCENT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_20_PERCENT_SV, "20%" },
/* tr */ { IDMS_20_PERCENT_TR, "20%" },

/* en */ { IDMS_10_PERCENT,    "10%" },
/* da */ { IDMS_10_PERCENT_DA, "10%" },
/* de */ { IDMS_10_PERCENT_DE, "10%" },
/* es */ { IDMS_10_PERCENT_ES, "10%" },
/* fr */ { IDMS_10_PERCENT_FR, "10%" },
/* hu */ { IDMS_10_PERCENT_HU, "" },  /* fuzzy */
/* it */ { IDMS_10_PERCENT_IT, "10%" },
/* ko */ { IDMS_10_PERCENT_KO, "10%" },
/* nl */ { IDMS_10_PERCENT_NL, "10%" },
/* pl */ { IDMS_10_PERCENT_PL, "10%" },
/* ru */ { IDMS_10_PERCENT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_10_PERCENT_SV, "10%" },
/* tr */ { IDMS_10_PERCENT_TR, "10%" },

/* en */ { IDMS_NO_LIMIT,    "No limit" },
/* da */ { IDMS_NO_LIMIT_DA, "Ubegr�nset" },
/* de */ { IDMS_NO_LIMIT_DE, "Kein Limit" },
/* es */ { IDMS_NO_LIMIT_ES, "Sin l�mite" },
/* fr */ { IDMS_NO_LIMIT_FR, "Aucune limite" },
/* hu */ { IDMS_NO_LIMIT_HU, "Nincs hat�r" },
/* it */ { IDMS_NO_LIMIT_IT, "Nessun limite" },
/* ko */ { IDMS_NO_LIMIT_KO, "�Ѱ����" },
/* nl */ { IDMS_NO_LIMIT_NL, "Geen limiet" },
/* pl */ { IDMS_NO_LIMIT_PL, "Bez limitu" },
/* ru */ { IDMS_NO_LIMIT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_NO_LIMIT_SV, "Ingen gr�ns" },
/* tr */ { IDMS_NO_LIMIT_TR, "Limitsiz" },

/* en */ { IDMS_CUSTOM,    "Custom" },
/* da */ { IDMS_CUSTOM_DA, "Egen" },
/* de */ { IDMS_CUSTOM_DE, "Benutzerdefiniert" },
/* es */ { IDMS_CUSTOM_ES, "Personalizado" },
/* fr */ { IDMS_CUSTOM_FR, "" },  /* fuzzy */
/* hu */ { IDMS_CUSTOM_HU, "Egy�ni" },
/* it */ { IDMS_CUSTOM_IT, "Personalizzato" },
/* ko */ { IDMS_CUSTOM_KO, "Ŀ����" },
/* nl */ { IDMS_CUSTOM_NL, "Aangepast" },
/* pl */ { IDMS_CUSTOM_PL, "W�asna" },
/* ru */ { IDMS_CUSTOM_RU, "" },  /* fuzzy */
/* sv */ { IDMS_CUSTOM_SV, "Egen" },
/* tr */ { IDMS_CUSTOM_TR, "�zel" },

/* en */ { IDMS_WARP_MODE,    "Warp mode" },
/* da */ { IDMS_WARP_MODE_DA, "Warp-tilstand" },
/* de */ { IDMS_WARP_MODE_DE, "Warp modus" },
/* es */ { IDMS_WARP_MODE_ES, "Modo m�xima velocidad" },
/* fr */ { IDMS_WARP_MODE_FR, "Mode turbo " },
/* hu */ { IDMS_WARP_MODE_HU, "Hipergyors m�d" },
/* it */ { IDMS_WARP_MODE_IT, "Modalit� turbo" },
/* ko */ { IDMS_WARP_MODE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_WARP_MODE_NL, "Warpmodus" },
/* pl */ { IDMS_WARP_MODE_PL, "Tryb przyspieszony" },
/* ru */ { IDMS_WARP_MODE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_WARP_MODE_SV, "Warpl�ge" },
/* tr */ { IDMS_WARP_MODE_TR, "Warp modu" },

/* en */ { IDMS_FULLSCREEN,    "Fullscreen" },
/* da */ { IDMS_FULLSCREEN_DA, "Fuldsk�rm" },
/* de */ { IDMS_FULLSCREEN_DE, "Vollbild" },
/* es */ { IDMS_FULLSCREEN_ES, "Pantalla completa" },
/* fr */ { IDMS_FULLSCREEN_FR, "Plein �cran" },
/* hu */ { IDMS_FULLSCREEN_HU, "Teljes k�perny�" },
/* it */ { IDMS_FULLSCREEN_IT, "Schermo intero" },
/* ko */ { IDMS_FULLSCREEN_KO, "��üȭ��" },
/* nl */ { IDMS_FULLSCREEN_NL, "Volscherm" },
/* pl */ { IDMS_FULLSCREEN_PL, "Pe�ny ekran" },
/* ru */ { IDMS_FULLSCREEN_RU, "" },  /* fuzzy */
/* sv */ { IDMS_FULLSCREEN_SV, "Fullsk�rm" },
/* tr */ { IDMS_FULLSCREEN_TR, "Tam ekran" },

/* en */ { IDMS_VIDEO_CACHE,    "Video cache" },
/* da */ { IDMS_VIDEO_CACHE_DA, "Grafikcache" },
/* de */ { IDMS_VIDEO_CACHE_DE, "Video Cache" },
/* es */ { IDMS_VIDEO_CACHE_ES, "Cach� de video" },
/* fr */ { IDMS_VIDEO_CACHE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_VIDEO_CACHE_HU, "K�p gyors�t�t�r" },
/* it */ { IDMS_VIDEO_CACHE_IT, "Cache video" },
/* ko */ { IDMS_VIDEO_CACHE_KO, "���� ĳ��" },
/* nl */ { IDMS_VIDEO_CACHE_NL, "Videocache" },
/* pl */ { IDMS_VIDEO_CACHE_PL, "Cache video" },
/* ru */ { IDMS_VIDEO_CACHE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_VIDEO_CACHE_SV, "Grafikcache" },
/* tr */ { IDMS_VIDEO_CACHE_TR, "G�r�nt� �nbelle�i" },

/* en */ { IDMS_DOUBLE_SIZE,    "Double size" },
/* da */ { IDMS_DOUBLE_SIZE_DA, "Dobbelt st�rrelse" },
/* de */ { IDMS_DOUBLE_SIZE_DE, "Doppelte Gr��e" },
/* es */ { IDMS_DOUBLE_SIZE_ES, "Tama�o doble" },
/* fr */ { IDMS_DOUBLE_SIZE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_DOUBLE_SIZE_HU, "Dupla m�ret" },
/* it */ { IDMS_DOUBLE_SIZE_IT, "Dimensione doppia" },
/* ko */ { IDMS_DOUBLE_SIZE_KO, "���� ������" },
/* nl */ { IDMS_DOUBLE_SIZE_NL, "Dubbele grootte" },
/* pl */ { IDMS_DOUBLE_SIZE_PL, "Podw�jny rozmiar" },
/* ru */ { IDMS_DOUBLE_SIZE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DOUBLE_SIZE_SV, "Dubbel storlek" },
/* tr */ { IDMS_DOUBLE_SIZE_TR, "�ift boyut" },

/* en */ { IDMS_DOUBLE_SCAN,    "Double scan" },
/* da */ { IDMS_DOUBLE_SCAN_DA, "Dobbelt-skan" },
/* de */ { IDMS_DOUBLE_SCAN_DE, "Doppelt Scan" },
/* es */ { IDMS_DOUBLE_SCAN_ES, "Doble escaneo" },
/* fr */ { IDMS_DOUBLE_SCAN_FR, "" },  /* fuzzy */
/* hu */ { IDMS_DOUBLE_SCAN_HU, "Dupla p�szt�z�s" },
/* it */ { IDMS_DOUBLE_SCAN_IT, "Scansione doppia" },
/* ko */ { IDMS_DOUBLE_SCAN_KO, "���� ��ĵ" },
/* nl */ { IDMS_DOUBLE_SCAN_NL, "Dubbele scan" },
/* pl */ { IDMS_DOUBLE_SCAN_PL, "Podw�jne skanowanie" },
/* ru */ { IDMS_DOUBLE_SCAN_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DOUBLE_SCAN_SV, "Dubbelskanning" },
/* tr */ { IDMS_DOUBLE_SCAN_TR, "�ift tarama" },

/* en */ { IDMS_VDC_SETTINGS,    "VDC settings" },
/* da */ { IDMS_VDC_SETTINGS_DA, "VDC-indstillinger" },
/* de */ { IDMS_VDC_SETTINGS_DE, "VDC Einstellungen" },
/* es */ { IDMS_VDC_SETTINGS_ES, "Ajustes VDC" },
/* fr */ { IDMS_VDC_SETTINGS_FR, "Param�tres VDC" },
/* hu */ { IDMS_VDC_SETTINGS_HU, "VDC be�ll�t�sai" },
/* it */ { IDMS_VDC_SETTINGS_IT, "Impostazioni VDC" },
/* ko */ { IDMS_VDC_SETTINGS_KO, "VDC ����" },
/* nl */ { IDMS_VDC_SETTINGS_NL, "VDC instellingen" },
/* pl */ { IDMS_VDC_SETTINGS_PL, "Ustawienia VDC" },
/* ru */ { IDMS_VDC_SETTINGS_RU, "��������� VDC" },
/* sv */ { IDMS_VDC_SETTINGS_SV, "VDC-inst�llningar" },
/* tr */ { IDMS_VDC_SETTINGS_TR, "VDC ayarlar�" },

/* en */ { IDMS_64KB_VIDEO_MEMORY,    "64KB video memory" },
/* da */ { IDMS_64KB_VIDEO_MEMORY_DA, "64KB grafikhukommelse" },
/* de */ { IDMS_64KB_VIDEO_MEMORY_DE, "64KB Bildschirm Speicher" },
/* es */ { IDMS_64KB_VIDEO_MEMORY_ES, "Memoria de video 64KB" },
/* fr */ { IDMS_64KB_VIDEO_MEMORY_FR, "" },  /* fuzzy */
/* hu */ { IDMS_64KB_VIDEO_MEMORY_HU, "64KB k�perny� mem�ria" },
/* it */ { IDMS_64KB_VIDEO_MEMORY_IT, "Memoria video di 64KB" },
/* ko */ { IDMS_64KB_VIDEO_MEMORY_KO, "64KB ���� �޸�" },
/* nl */ { IDMS_64KB_VIDEO_MEMORY_NL, "64KB videogeheugen" },
/* pl */ { IDMS_64KB_VIDEO_MEMORY_PL, "Pami�� wideo 64KB" },
/* ru */ { IDMS_64KB_VIDEO_MEMORY_RU, "" },  /* fuzzy */
/* sv */ { IDMS_64KB_VIDEO_MEMORY_SV, "64KB grafikminne" },
/* tr */ { IDMS_64KB_VIDEO_MEMORY_TR, "64KB g�r�nt� belle�i" },

/* en */ { IDMS_VDC_REVISION,    "VDC revision" },
/* da */ { IDMS_VDC_REVISION_DA, "VDC-revision" },
/* de */ { IDMS_VDC_REVISION_DE, "VDC Revision" },
/* es */ { IDMS_VDC_REVISION_ES, "Revisi�n VDC" },
/* fr */ { IDMS_VDC_REVISION_FR, "" },  /* fuzzy */
/* hu */ { IDMS_VDC_REVISION_HU, "VDC v�ltozat" },
/* it */ { IDMS_VDC_REVISION_IT, "Revisione VDC" },
/* ko */ { IDMS_VDC_REVISION_KO, "" },  /* fuzzy */
/* nl */ { IDMS_VDC_REVISION_NL, "VDC revisie" },
/* pl */ { IDMS_VDC_REVISION_PL, "Wersja VDC" },
/* ru */ { IDMS_VDC_REVISION_RU, "" },  /* fuzzy */
/* sv */ { IDMS_VDC_REVISION_SV, "VDC-revision" },
/* tr */ { IDMS_VDC_REVISION_TR, "VDC revizyonu" },

/* en */ { IDMS_VDC_REV_0,    "Rev 0" },
/* da */ { IDMS_VDC_REV_0_DA, "Udgave 0" },
/* de */ { IDMS_VDC_REV_0_DE, "Rev 0" },
/* es */ { IDMS_VDC_REV_0_ES, "Rev 0" },
/* fr */ { IDMS_VDC_REV_0_FR, "" },  /* fuzzy */
/* hu */ { IDMS_VDC_REV_0_HU, "0-�s v�ltozat" },
/* it */ { IDMS_VDC_REV_0_IT, "Rev 0" },
/* ko */ { IDMS_VDC_REV_0_KO, "���� 0" },
/* nl */ { IDMS_VDC_REV_0_NL, "Revisie 0" },
/* pl */ { IDMS_VDC_REV_0_PL, "Rev 0" },
/* ru */ { IDMS_VDC_REV_0_RU, "" },  /* fuzzy */
/* sv */ { IDMS_VDC_REV_0_SV, "Utg�va 0" },
/* tr */ { IDMS_VDC_REV_0_TR, "Rev 0" },

/* en */ { IDMS_VDC_REV_1,    "Rev 1" },
/* da */ { IDMS_VDC_REV_1_DA, "Udgave 1" },
/* de */ { IDMS_VDC_REV_1_DE, "Rev 1" },
/* es */ { IDMS_VDC_REV_1_ES, "Rev 1" },
/* fr */ { IDMS_VDC_REV_1_FR, "" },  /* fuzzy */
/* hu */ { IDMS_VDC_REV_1_HU, "1-es v�ltozat" },
/* it */ { IDMS_VDC_REV_1_IT, "Rev 1" },
/* ko */ { IDMS_VDC_REV_1_KO, "���� 1" },
/* nl */ { IDMS_VDC_REV_1_NL, "Revisie 1" },
/* pl */ { IDMS_VDC_REV_1_PL, "Rev 1" },
/* ru */ { IDMS_VDC_REV_1_RU, "" },  /* fuzzy */
/* sv */ { IDMS_VDC_REV_1_SV, "Utg�va 1" },
/* tr */ { IDMS_VDC_REV_1_TR, "Rev 1" },

/* en */ { IDMS_VDC_REV_2,    "Rev 2" },
/* da */ { IDMS_VDC_REV_2_DA, "Udgave 2" },
/* de */ { IDMS_VDC_REV_2_DE, "Rev 2" },
/* es */ { IDMS_VDC_REV_2_ES, "Rev 2" },
/* fr */ { IDMS_VDC_REV_2_FR, "" },  /* fuzzy */
/* hu */ { IDMS_VDC_REV_2_HU, "2-es v�ltozat" },
/* it */ { IDMS_VDC_REV_2_IT, "Rev 2" },
/* ko */ { IDMS_VDC_REV_2_KO, "���� 2" },
/* nl */ { IDMS_VDC_REV_2_NL, "Revisie 2" },
/* pl */ { IDMS_VDC_REV_2_PL, "Rev 2" },
/* ru */ { IDMS_VDC_REV_2_RU, "" },  /* fuzzy */
/* sv */ { IDMS_VDC_REV_2_SV, "Utg�va 2" },
/* tr */ { IDMS_VDC_REV_2_TR, "Rev 2" },

/* en */ { IDMS_SWAP_JOYSTICKS,    "Swap joysticks" },
/* da */ { IDMS_SWAP_JOYSTICKS_DA, "Byt om p� joystickportene" },
/* de */ { IDMS_SWAP_JOYSTICKS_DE, "Joystick ports austauschen" },
/* es */ { IDMS_SWAP_JOYSTICKS_ES, "Intercambiar joysticks" },
/* fr */ { IDMS_SWAP_JOYSTICKS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_SWAP_JOYSTICKS_HU, "" },  /* fuzzy */
/* it */ { IDMS_SWAP_JOYSTICKS_IT, "Scambia joystick" },
/* ko */ { IDMS_SWAP_JOYSTICKS_KO, "���̽�ƽ�� �ٲټ���" },
/* nl */ { IDMS_SWAP_JOYSTICKS_NL, "Verwissel joysticks" },
/* pl */ { IDMS_SWAP_JOYSTICKS_PL, "Zamie� joysticki" },
/* ru */ { IDMS_SWAP_JOYSTICKS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SWAP_JOYSTICKS_SV, "V�xla spelportarna" },
/* tr */ { IDMS_SWAP_JOYSTICKS_TR, "Joystickleri de�i�tir" },

/* en */ { IDMS_SWAP_USERPORT_JOYSTICKS,    "Swap userport joysticks" },
/* da */ { IDMS_SWAP_USERPORT_JOYSTICKS_DA, "Byt om p� brugerportjoysticks" },
/* de */ { IDMS_SWAP_USERPORT_JOYSTICKS_DE, "Userport Joystick ports austauschen" },
/* es */ { IDMS_SWAP_USERPORT_JOYSTICKS_ES, "Intercambiar puertos joysticks" },
/* fr */ { IDMS_SWAP_USERPORT_JOYSTICKS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_SWAP_USERPORT_JOYSTICKS_HU, "" },  /* fuzzy */
/* it */ { IDMS_SWAP_USERPORT_JOYSTICKS_IT, "Scambia joystick su userport" },
/* ko */ { IDMS_SWAP_USERPORT_JOYSTICKS_KO, "������Ʈ ���̽�ƽ�� �ٲټ���" },
/* nl */ { IDMS_SWAP_USERPORT_JOYSTICKS_NL, "Verwissel userport joysticks" },
/* pl */ { IDMS_SWAP_USERPORT_JOYSTICKS_PL, "Zamie� joysticki w userportach" },
/* ru */ { IDMS_SWAP_USERPORT_JOYSTICKS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SWAP_USERPORT_JOYSTICKS_SV, "V�xla anv�ndarportstyrspakar" },
/* tr */ { IDMS_SWAP_USERPORT_JOYSTICKS_TR, "Userport joysticklerini yer de�i�tir" },

/* en */ { IDMS_ENABLE_JOY_KEYS,    "Enable Joy Keys" },
/* da */ { IDMS_ENABLE_JOY_KEYS_DA, "Aktiv�r joystick via keyboard" },
/* de */ { IDMS_ENABLE_JOY_KEYS_DE, "Joystick Tasten aktivieren" },
/* es */ { IDMS_ENABLE_JOY_KEYS_ES, "Permitir Teclas en joy" },
/* fr */ { IDMS_ENABLE_JOY_KEYS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ENABLE_JOY_KEYS_HU, "Botkorm�ny gombok enged�lyez�se" },
/* it */ { IDMS_ENABLE_JOY_KEYS_IT, "Attiva tasti joystick" },
/* ko */ { IDMS_ENABLE_JOY_KEYS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_ENABLE_JOY_KEYS_NL, "Activeer Joy Keys" },
/* pl */ { IDMS_ENABLE_JOY_KEYS_PL, "W��cz klawisze joysticka" },
/* ru */ { IDMS_ENABLE_JOY_KEYS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ENABLE_JOY_KEYS_SV, "Aktivera styrspak via tangenter" },
/* tr */ { IDMS_ENABLE_JOY_KEYS_TR, "Joy Tu�lar�n� Aktif Et" },

/* en */ { IDMS_ENABLE_JOY_KEYS,    "Allow opposite directions" },
/* da */ { IDMS_ENABLE_JOY_KEYS_DA, "Tillad modsatte retninger" },
/* de */ { IDMS_ENABLE_JOY_KEYS_DE, "Gegen�berliegende Richtungen zulassen" },
/* es */ { IDMS_ENABLE_JOY_KEYS_ES, "Permitir direcciones opuestas" },
/* fr */ { IDMS_ENABLE_JOY_KEYS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ENABLE_JOY_KEYS_HU, "" },  /* fuzzy */
/* it */ { IDMS_ENABLE_JOY_KEYS_IT, "Consenti direzioni opposte" },
/* ko */ { IDMS_ENABLE_JOY_KEYS_KO, "�ݴ� ���� �㰡�ϱ�" },
/* nl */ { IDMS_ENABLE_JOY_KEYS_NL, "Tegenovergestelde richtingen toestaan" },
/* pl */ { IDMS_ENABLE_JOY_KEYS_PL, "Pozw�l na przeciwstawne kierunki" },
/* ru */ { IDMS_ENABLE_JOY_KEYS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ENABLE_JOY_KEYS_SV, "Till�t motsatta riktningar" },
/* tr */ { IDMS_ENABLE_JOY_KEYS_TR, "Z�t y�nlere izin ver" },

/* en */ { IDMS_SOUND_PLAYBACK,    "Sound playback" },
/* da */ { IDMS_SOUND_PLAYBACK_DA, "Sl� lydemulering til" },
/* de */ { IDMS_SOUND_PLAYBACK_DE, "Sound Wiedergabe" },
/* es */ { IDMS_SOUND_PLAYBACK_ES, "Reproducci�n sonido" },
/* fr */ { IDMS_SOUND_PLAYBACK_FR, "Lecture audio" },
/* hu */ { IDMS_SOUND_PLAYBACK_HU, "Hangok enged�lyez�se" },
/* it */ { IDMS_SOUND_PLAYBACK_IT, "Riproduzione audio" },
/* ko */ { IDMS_SOUND_PLAYBACK_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SOUND_PLAYBACK_NL, "Geluidsuitvoer" },
/* pl */ { IDMS_SOUND_PLAYBACK_PL, "Odtwarzanie d�wi�ku" },
/* ru */ { IDMS_SOUND_PLAYBACK_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SOUND_PLAYBACK_SV, "Aktivera ljud�tergivning" },
/* tr */ { IDMS_SOUND_PLAYBACK_TR, "Ses" },

/* en */ { IDMS_TRUE_DRIVE_EMU,    "True drive emulation" },
/* da */ { IDMS_TRUE_DRIVE_EMU_DA, "�gte drev-emulering" },
/* de */ { IDMS_TRUE_DRIVE_EMU_DE, "Pr�zise Floppy Emulation" },
/* es */ { IDMS_TRUE_DRIVE_EMU_ES, "Emulacion unidad disco verdadera" },
/* fr */ { IDMS_TRUE_DRIVE_EMU_FR, "Activer l'�mulation r�elle des lecteurs" },
/* hu */ { IDMS_TRUE_DRIVE_EMU_HU, "Val�s lemezegys�g emul�ci�" },
/* it */ { IDMS_TRUE_DRIVE_EMU_IT, "Attiva emulazione hardware dei drive" },
/* ko */ { IDMS_TRUE_DRIVE_EMU_KO, "Ʈ�� ����̺� ���ķ�����" },
/* nl */ { IDMS_TRUE_DRIVE_EMU_NL, "Hardwarematige driveemulatie" },
/* pl */ { IDMS_TRUE_DRIVE_EMU_PL, "Rzeczywista emulacja nap�du" },
/* ru */ { IDMS_TRUE_DRIVE_EMU_RU, "" },  /* fuzzy */
/* sv */ { IDMS_TRUE_DRIVE_EMU_SV, "�kta diskettenhetsemulering" },
/* tr */ { IDMS_TRUE_DRIVE_EMU_TR, "Ger�ek s�r�c� em�lasyonu" },

/* en */ { IDMS_AUTOSTART_HANDLE_TDE,    "Handle True Drive Emulation on autostart" },
/* da */ { IDMS_AUTOSTART_HANDLE_TDE_DA, "Anvend �gte drev-emulering ved autostart" },
/* de */ { IDMS_AUTOSTART_HANDLE_TDE_DE, "Pr�zise Floppy Emulation bei Autostart beachten" },
/* es */ { IDMS_AUTOSTART_HANDLE_TDE_ES, "Manejar en autoarranque emulaci�n de disco verdadera" },
/* fr */ { IDMS_AUTOSTART_HANDLE_TDE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_AUTOSTART_HANDLE_TDE_HU, "Val�s lemezegys�g emul�ci� kezel�se autostartn�l" },
/* it */ { IDMS_AUTOSTART_HANDLE_TDE_IT, "Emulazione hardware dei drive all'avvio automatico" },
/* ko */ { IDMS_AUTOSTART_HANDLE_TDE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_AUTOSTART_HANDLE_TDE_NL, "Manipuleer hardwarematige drive emulatie bij autostarten" },
/* pl */ { IDMS_AUTOSTART_HANDLE_TDE_PL, "W��cz rzeczywist� emulacj� nap�du przy autostarcie" },
/* ru */ { IDMS_AUTOSTART_HANDLE_TDE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_AUTOSTART_HANDLE_TDE_SV, "Hantera �kta diskettenhetsemulering vid autostart" },
/* tr */ { IDMS_AUTOSTART_HANDLE_TDE_TR, "Otomatik ba�latmada Ger�ek S�r�c� Em�lasyonu'nu denetle" },

/* en */ { IDMS_VIRTUAL_DEVICE_TRAPS,    "Virtual device traps" },
/* da */ { IDMS_VIRTUAL_DEVICE_TRAPS_DA, "Virtuelle enheds-traps" },
/* de */ { IDMS_VIRTUAL_DEVICE_TRAPS_DE, "Virtuelle Ger�te Traps" },
/* es */ { IDMS_VIRTUAL_DEVICE_TRAPS_ES, "interceptar perif�ricos virtuales" },
/* fr */ { IDMS_VIRTUAL_DEVICE_TRAPS_FR, "Activer les p�riph�riques virtuels" },
/* hu */ { IDMS_VIRTUAL_DEVICE_TRAPS_HU, "Virtu�lis eszk�z�k ciklus kihagy�sa" },
/* it */ { IDMS_VIRTUAL_DEVICE_TRAPS_IT, "Attiva periferiche virtuali" },
/* ko */ { IDMS_VIRTUAL_DEVICE_TRAPS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_VIRTUAL_DEVICE_TRAPS_NL, "Virtuele apparaattraps" },
/* pl */ { IDMS_VIRTUAL_DEVICE_TRAPS_PL, "Traps urz�dzenia wirtualnego." },
/* ru */ { IDMS_VIRTUAL_DEVICE_TRAPS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_VIRTUAL_DEVICE_TRAPS_SV, "Virtuella enhetstrap:ar" },
/* tr */ { IDMS_VIRTUAL_DEVICE_TRAPS_TR, "Sanal ayg�t trapleri" },

/* en */ { IDMS_DRIVE_SYNC_FACTOR,    "Drive sync factor" },
/* da */ { IDMS_DRIVE_SYNC_FACTOR_DA, "Synkfaktor for diskettedrev" },
/* de */ { IDMS_DRIVE_SYNC_FACTOR_DE, "Laufwerkt Sync Faktor" },
/* es */ { IDMS_DRIVE_SYNC_FACTOR_ES, "Factor sincronizaci�n unidad disco" },
/* fr */ { IDMS_DRIVE_SYNC_FACTOR_FR, "Facteur de synchro du lecteur" },
/* hu */ { IDMS_DRIVE_SYNC_FACTOR_HU, "Lemezegys�g szinkron faktor" },
/* it */ { IDMS_DRIVE_SYNC_FACTOR_IT, "Fattore di sincronizzazione del drive" },
/* ko */ { IDMS_DRIVE_SYNC_FACTOR_KO, "" },  /* fuzzy */
/* nl */ { IDMS_DRIVE_SYNC_FACTOR_NL, "Drive synchronisatiefactor" },
/* pl */ { IDMS_DRIVE_SYNC_FACTOR_PL, "Czynnik synchronizacji stacji" },
/* ru */ { IDMS_DRIVE_SYNC_FACTOR_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DRIVE_SYNC_FACTOR_SV, "Synkfaktor f�r diskettstation" },
/* tr */ { IDMS_DRIVE_SYNC_FACTOR_TR, "S�r�c� senkron fakt�r�" },

/* en */ { IDMS_PAL,    "PAL" },
/* da */ { IDMS_PAL_DA, "PAL-G" },
/* de */ { IDMS_PAL_DE, "PAL" },
/* es */ { IDMS_PAL_ES, "PAL" },
/* fr */ { IDMS_PAL_FR, "PAL" },
/* hu */ { IDMS_PAL_HU, "" },  /* fuzzy */
/* it */ { IDMS_PAL_IT, "PAL" },
/* ko */ { IDMS_PAL_KO, "" },  /* fuzzy */
/* nl */ { IDMS_PAL_NL, "PAL" },
/* pl */ { IDMS_PAL_PL, "PAL" },
/* ru */ { IDMS_PAL_RU, "" },  /* fuzzy */
/* sv */ { IDMS_PAL_SV, "PAL-G" },
/* tr */ { IDMS_PAL_TR, "PAL" },

/* en */ { IDMS_NTSC,    "NTSC" },
/* da */ { IDMS_NTSC_DA, "NTSC-M" },
/* de */ { IDMS_NTSC_DE, "NTSC" },
/* es */ { IDMS_NTSC_ES, "NTSC" },
/* fr */ { IDMS_NTSC_FR, "NTSC" },
/* hu */ { IDMS_NTSC_HU, "" },  /* fuzzy */
/* it */ { IDMS_NTSC_IT, "NTSC" },
/* ko */ { IDMS_NTSC_KO, "" },  /* fuzzy */
/* nl */ { IDMS_NTSC_NL, "NTSC" },
/* pl */ { IDMS_NTSC_PL, "NTSC" },
/* ru */ { IDMS_NTSC_RU, "" },  /* fuzzy */
/* sv */ { IDMS_NTSC_SV, "NTSC-M" },
/* tr */ { IDMS_NTSC_TR, "NTSC" },

/* en */ { IDMS_VIDEO_STANDARD,    "Video standard" },
/* da */ { IDMS_VIDEO_STANDARD_DA, "TV-standard" },
/* de */ { IDMS_VIDEO_STANDARD_DE, "Video Standard" },
/* es */ { IDMS_VIDEO_STANDARD_ES, "Video estandar" },
/* fr */ { IDMS_VIDEO_STANDARD_FR, "Standard vid�o" },
/* hu */ { IDMS_VIDEO_STANDARD_HU, "Vide� szabv�ny" },
/* it */ { IDMS_VIDEO_STANDARD_IT, "Standard video" },
/* ko */ { IDMS_VIDEO_STANDARD_KO, "ǥ�� ����" },
/* nl */ { IDMS_VIDEO_STANDARD_NL, "Videostandaard" },
/* pl */ { IDMS_VIDEO_STANDARD_PL, "Standard video" },
/* ru */ { IDMS_VIDEO_STANDARD_RU, "" },  /* fuzzy */
/* sv */ { IDMS_VIDEO_STANDARD_SV, "TV-standard" },
/* tr */ { IDMS_VIDEO_STANDARD_TR, "G�r�nt� standard�" },

/* en */ { IDMS_PAL_G,    "PAL-G" },
/* da */ { IDMS_PAL_G_DA, "PAL-G" },
/* de */ { IDMS_PAL_G_DE, "PAL-G" },
/* es */ { IDMS_PAL_G_ES, "PAL-G" },
/* fr */ { IDMS_PAL_G_FR, "PAL-G" },
/* hu */ { IDMS_PAL_G_HU, "" },  /* fuzzy */
/* it */ { IDMS_PAL_G_IT, "PAL-G" },
/* ko */ { IDMS_PAL_G_KO, "" },  /* fuzzy */
/* nl */ { IDMS_PAL_G_NL, "PAL-G" },
/* pl */ { IDMS_PAL_G_PL, "PAL-G" },
/* ru */ { IDMS_PAL_G_RU, "" },  /* fuzzy */
/* sv */ { IDMS_PAL_G_SV, "PAL-G" },
/* tr */ { IDMS_PAL_G_TR, "PAL-G" },

/* en */ { IDMS_NTSC_M,    "NTSC-M" },
/* da */ { IDMS_NTSC_M_DA, "NTSC-M" },
/* de */ { IDMS_NTSC_M_DE, "NTSC-M" },
/* es */ { IDMS_NTSC_M_ES, "NTSC-M" },
/* fr */ { IDMS_NTSC_M_FR, "" },  /* fuzzy */
/* hu */ { IDMS_NTSC_M_HU, "" },  /* fuzzy */
/* it */ { IDMS_NTSC_M_IT, "NTSC-M" },
/* ko */ { IDMS_NTSC_M_KO, "" },  /* fuzzy */
/* nl */ { IDMS_NTSC_M_NL, "NTSC-M" },
/* pl */ { IDMS_NTSC_M_PL, "NTSC-M" },
/* ru */ { IDMS_NTSC_M_RU, "" },  /* fuzzy */
/* sv */ { IDMS_NTSC_M_SV, "NTSC-M" },
/* tr */ { IDMS_NTSC_M_TR, "NTSC-M" },

/* en */ { IDMS_OLD_NTSC_M,    "Old NTSC-M" },
/* da */ { IDMS_OLD_NTSC_M_DA, "Gammel NTSC-M" },
/* de */ { IDMS_OLD_NTSC_M_DE, "NTSC-M alt" },
/* es */ { IDMS_OLD_NTSC_M_ES, "Antiguo NTSC-M" },
/* fr */ { IDMS_OLD_NTSC_M_FR, "Ancien NTSC-M" },
/* hu */ { IDMS_OLD_NTSC_M_HU, "R�gi NTSC-M" },
/* it */ { IDMS_OLD_NTSC_M_IT, "NTSC-M vecchio" },
/* ko */ { IDMS_OLD_NTSC_M_KO, "�õ� NTSC-M" },
/* nl */ { IDMS_OLD_NTSC_M_NL, "Oud NTSC-M" },
/* pl */ { IDMS_OLD_NTSC_M_PL, "Stary NTSC-M" },
/* ru */ { IDMS_OLD_NTSC_M_RU, "" },  /* fuzzy */
/* sv */ { IDMS_OLD_NTSC_M_SV, "Gammal NTSC-M" },
/* tr */ { IDMS_OLD_NTSC_M_TR, "Eski NTSC-M" },

/* en */ { IDMS_VIC_1112_IEEE_488,    "VIC-1112 IEEE-488 module" },
/* da */ { IDMS_VIC_1112_IEEE_488_DA, "VIC-1112 IEEE-488-modul" },
/* de */ { IDMS_VIC_1112_IEEE_488_DE, "VIC-1112 IEEE-488 Modul" },
/* es */ { IDMS_VIC_1112_IEEE_488_ES, "M�dulo VIC-1112 IEEE-488" },
/* fr */ { IDMS_VIC_1112_IEEE_488_FR, "Module VIC-1112 IEEE 488" },
/* hu */ { IDMS_VIC_1112_IEEE_488_HU, "" },  /* fuzzy */
/* it */ { IDMS_VIC_1112_IEEE_488_IT, "Modulo VIC-1112 IEEE-488" },
/* ko */ { IDMS_VIC_1112_IEEE_488_KO, "" },  /* fuzzy */
/* nl */ { IDMS_VIC_1112_IEEE_488_NL, "VIC-1112 IEEE-488 module" },
/* pl */ { IDMS_VIC_1112_IEEE_488_PL, "Modu� IEEE-488 VIC-1112" },
/* ru */ { IDMS_VIC_1112_IEEE_488_RU, "" },  /* fuzzy */
/* sv */ { IDMS_VIC_1112_IEEE_488_SV, "VIC-1112 IEEE-488-modul" },
/* tr */ { IDMS_VIC_1112_IEEE_488_TR, "VIC-1112 IEEE-488 mod�l�" },

/* en */ { IDMS_ENABLE_PADDLES,    "Enable paddles" },
/* da */ { IDMS_ENABLE_PADDLES_DA, "Aktiv�r paddles" },
/* de */ { IDMS_ENABLE_PADDLES_DE, "Paddles aktivieren" },
/* es */ { IDMS_ENABLE_PADDLES_ES, "Permitir paddles" },
/* fr */ { IDMS_ENABLE_PADDLES_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ENABLE_PADDLES_HU, "" },  /* fuzzy */
/* it */ { IDMS_ENABLE_PADDLES_IT, "Attiva paddle" },
/* ko */ { IDMS_ENABLE_PADDLES_KO, "�е� ��밡���ϰ� �ϱ�" },
/* nl */ { IDMS_ENABLE_PADDLES_NL, "Activeer paddles" },
/* pl */ { IDMS_ENABLE_PADDLES_PL, "W��cz pokr�t�a steruj�ce" },
/* ru */ { IDMS_ENABLE_PADDLES_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ENABLE_PADDLES_SV, "Aktivera paddlar" },
/* tr */ { IDMS_ENABLE_PADDLES_TR, "Paddlelar� aktif et" },

/* en */ { IDMS_IEEE_488_INTERFACE,    "IEEE488 Interface emulation" },
/* da */ { IDMS_IEEE_488_INTERFACE_DA, "Emulering af IEEE488-interface" },
/* de */ { IDMS_IEEE_488_INTERFACE_DE, "IEEE488 Schnittstellen-Emulation" },
/* es */ { IDMS_IEEE_488_INTERFACE_ES, "Emulaci�n de interface IEEE488" },
/* fr */ { IDMS_IEEE_488_INTERFACE_FR, "Interface d'�mulation IEEE488" },
/* hu */ { IDMS_IEEE_488_INTERFACE_HU, "" },  /* fuzzy */
/* it */ { IDMS_IEEE_488_INTERFACE_IT, "Emulazione interfaccia IEEE488" },
/* ko */ { IDMS_IEEE_488_INTERFACE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_IEEE_488_INTERFACE_NL, "IEEE488 Interface emulatie" },
/* pl */ { IDMS_IEEE_488_INTERFACE_PL, "Emulacja interfejsu IEEE488" },
/* ru */ { IDMS_IEEE_488_INTERFACE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_IEEE_488_INTERFACE_SV, "Emulering av IEEE488-gr�nssnitt" },
/* tr */ { IDMS_IEEE_488_INTERFACE_TR, "IEEE488 Arabirimi em�lasyonu" },

/* en */ { IDMS_GRAB_MOUSE,    "Grab mouse events" },
/* da */ { IDMS_GRAB_MOUSE_DA, "Fang musseh�ndelser" },
/* de */ { IDMS_GRAB_MOUSE_DE, "Maus Ereignisse abfangen" },
/* es */ { IDMS_GRAB_MOUSE_ES, "Capturar eventos del rat�n" },
/* fr */ { IDMS_GRAB_MOUSE_FR, "Attraper les �v�nements souris" },
/* hu */ { IDMS_GRAB_MOUSE_HU, "Eg�r esem�nyek elkap�sa" },
/* it */ { IDMS_GRAB_MOUSE_IT, "Cattura eventi mouse" },
/* ko */ { IDMS_GRAB_MOUSE_KO, "�׷� ���콺 �̺�Ʈ" },
/* nl */ { IDMS_GRAB_MOUSE_NL, "Gebruik de muis" },
/* pl */ { IDMS_GRAB_MOUSE_PL, "Przechwytuj zdarzenia myszy" },
/* ru */ { IDMS_GRAB_MOUSE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_GRAB_MOUSE_SV, "F�nga mush�ndelser" },
/* tr */ { IDMS_GRAB_MOUSE_TR, "Mouse olaylar�n� yakala" },

/* en */ { IDMS_PS2_MOUSE,    "PS/2 mouse on Userport" },
/* da */ { IDMS_PS2_MOUSE_DA, "PS/2-mus p� brugerporten" },
/* de */ { IDMS_PS2_MOUSE_DE, "PS/2 Userport Mausemulation" },
/* es */ { IDMS_PS2_MOUSE_ES, "Rat�n PS/2 en puerto usuario" },
/* fr */ { IDMS_PS2_MOUSE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_PS2_MOUSE_HU, "PS/2 eg�r a userporton" },
/* it */ { IDMS_PS2_MOUSE_IT, "Mouse PS/2 su userport" },
/* ko */ { IDMS_PS2_MOUSE_KO, "������Ʈ�� PS/S ���콺 " },
/* nl */ { IDMS_PS2_MOUSE_NL, "Aktiveer emulatie van een PS/2 muis op de userport" },
/* pl */ { IDMS_PS2_MOUSE_PL, "Mysz PS/2 w userporcie" },
/* ru */ { IDMS_PS2_MOUSE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_PS2_MOUSE_SV, "PS/2-mus p� anv�ndarport" },
/* tr */ { IDMS_PS2_MOUSE_TR, "Userport �zerinde PS/2 mouse" },

/* en */ { IDMS_SETTINGS,    "Settings" },
/* da */ { IDMS_SETTINGS_DA, "Indstillinger" },
/* de */ { IDMS_SETTINGS_DE, "Einstellungen" },
/* es */ { IDMS_SETTINGS_ES, "Ajustes" },
/* fr */ { IDMS_SETTINGS_FR, "Param�tres" },
/* hu */ { IDMS_SETTINGS_HU, "Be�ll�t�sok" },
/* it */ { IDMS_SETTINGS_IT, "Impostazioni" },
/* ko */ { IDMS_SETTINGS_KO, "����" },
/* nl */ { IDMS_SETTINGS_NL, "Instellingen" },
/* pl */ { IDMS_SETTINGS_PL, "Ustawienia" },
/* ru */ { IDMS_SETTINGS_RU, "���������" },
/* sv */ { IDMS_SETTINGS_SV, "Inst�llningar" },
/* tr */ { IDMS_SETTINGS_TR, "Ayarlar" },

/* en */ { IDMS_C64_MODEL_SETTINGS,    "C64 model settings..." },
/* da */ { IDMS_C64_MODEL_SETTINGS_DA, "C64-model indstillinger..." },
/* de */ { IDMS_C64_MODEL_SETTINGS_DE, "C64 Modell Einstellungen..." },
/* es */ { IDMS_C64_MODEL_SETTINGS_ES, "Ajustes modelo C64..." },
/* fr */ { IDMS_C64_MODEL_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_C64_MODEL_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_C64_MODEL_SETTINGS_IT, "Impostazioni modello C64..." },
/* ko */ { IDMS_C64_MODEL_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_C64_MODEL_SETTINGS_NL, "C64 model instellingen..." },
/* pl */ { IDMS_C64_MODEL_SETTINGS_PL, "Ustawienia modelu C64..." },
/* ru */ { IDMS_C64_MODEL_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_C64_MODEL_SETTINGS_SV, "C64-modellinst�llningar..." },
/* tr */ { IDMS_C64_MODEL_SETTINGS_TR, "C64 model ayarlar�..." },

/* en */ { IDMS_C64_PAL,    "C64 PAL" },
/* da */ { IDMS_C64_PAL_DA, "C64 PAL" },
/* de */ { IDMS_C64_PAL_DE, "C64 PAL" },
/* es */ { IDMS_C64_PAL_ES, "C64 PAL" },
/* fr */ { IDMS_C64_PAL_FR, "" },  /* fuzzy */
/* hu */ { IDMS_C64_PAL_HU, "" },  /* fuzzy */
/* it */ { IDMS_C64_PAL_IT, "C64 PAL" },
/* ko */ { IDMS_C64_PAL_KO, "" },  /* fuzzy */
/* nl */ { IDMS_C64_PAL_NL, "C64 PAL" },
/* pl */ { IDMS_C64_PAL_PL, "C64 PAL" },
/* ru */ { IDMS_C64_PAL_RU, "" },  /* fuzzy */
/* sv */ { IDMS_C64_PAL_SV, "C64 PAL" },
/* tr */ { IDMS_C64_PAL_TR, "C64 PAL" },

/* en */ { IDMS_C64C_PAL,    "C64C PAL" },
/* da */ { IDMS_C64C_PAL_DA, "C64C PAL" },
/* de */ { IDMS_C64C_PAL_DE, "C64C PAL" },
/* es */ { IDMS_C64C_PAL_ES, "C64C PAL" },
/* fr */ { IDMS_C64C_PAL_FR, "" },  /* fuzzy */
/* hu */ { IDMS_C64C_PAL_HU, "" },  /* fuzzy */
/* it */ { IDMS_C64C_PAL_IT, "C64C PAL" },
/* ko */ { IDMS_C64C_PAL_KO, "" },  /* fuzzy */
/* nl */ { IDMS_C64C_PAL_NL, "C64C PAL" },
/* pl */ { IDMS_C64C_PAL_PL, "C64C PAL" },
/* ru */ { IDMS_C64C_PAL_RU, "" },  /* fuzzy */
/* sv */ { IDMS_C64C_PAL_SV, "C64C PAL" },
/* tr */ { IDMS_C64C_PAL_TR, "C64C PAL" },

/* en */ { IDMS_C64_OLD_PAL,    "C64 old PAL" },
/* da */ { IDMS_C64_OLD_PAL_DA, "C64 gammel PAL" },
/* de */ { IDMS_C64_OLD_PAL_DE, "C64 alt PAL" },
/* es */ { IDMS_C64_OLD_PAL_ES, "C64 PAL antiguo" },
/* fr */ { IDMS_C64_OLD_PAL_FR, "" },  /* fuzzy */
/* hu */ { IDMS_C64_OLD_PAL_HU, "" },  /* fuzzy */
/* it */ { IDMS_C64_OLD_PAL_IT, "C64 PAL vecchio" },
/* ko */ { IDMS_C64_OLD_PAL_KO, "C64 �õ� PAL" },
/* nl */ { IDMS_C64_OLD_PAL_NL, "C64 oud PAL" },
/* pl */ { IDMS_C64_OLD_PAL_PL, "C64 stary PAL" },
/* ru */ { IDMS_C64_OLD_PAL_RU, "" },  /* fuzzy */
/* sv */ { IDMS_C64_OLD_PAL_SV, "C64 gammal PAL" },
/* tr */ { IDMS_C64_OLD_PAL_TR, "C64 eski PAL" },

/* en */ { IDMS_C64_NTSC,    "C64 NTSC" },
/* da */ { IDMS_C64_NTSC_DA, "C64 NTSC" },
/* de */ { IDMS_C64_NTSC_DE, "C64 NTSC" },
/* es */ { IDMS_C64_NTSC_ES, "C64 NTSC" },
/* fr */ { IDMS_C64_NTSC_FR, "" },  /* fuzzy */
/* hu */ { IDMS_C64_NTSC_HU, "" },  /* fuzzy */
/* it */ { IDMS_C64_NTSC_IT, "C64 NTSC" },
/* ko */ { IDMS_C64_NTSC_KO, "" },  /* fuzzy */
/* nl */ { IDMS_C64_NTSC_NL, "C64 NTSC" },
/* pl */ { IDMS_C64_NTSC_PL, "C64 NTSC" },
/* ru */ { IDMS_C64_NTSC_RU, "" },  /* fuzzy */
/* sv */ { IDMS_C64_NTSC_SV, "C64 NTSC" },
/* tr */ { IDMS_C64_NTSC_TR, "C64 NTSC" },

/* en */ { IDMS_C64C_NTSC,    "C64C NTSC" },
/* da */ { IDMS_C64C_NTSC_DA, "C64C NTSC" },
/* de */ { IDMS_C64C_NTSC_DE, "C64C NTSC" },
/* es */ { IDMS_C64C_NTSC_ES, "C64C NTSC" },
/* fr */ { IDMS_C64C_NTSC_FR, "" },  /* fuzzy */
/* hu */ { IDMS_C64C_NTSC_HU, "" },  /* fuzzy */
/* it */ { IDMS_C64C_NTSC_IT, "C64C NTSC" },
/* ko */ { IDMS_C64C_NTSC_KO, "" },  /* fuzzy */
/* nl */ { IDMS_C64C_NTSC_NL, "C64C NTSC" },
/* pl */ { IDMS_C64C_NTSC_PL, "C64C NTSC" },
/* ru */ { IDMS_C64C_NTSC_RU, "" },  /* fuzzy */
/* sv */ { IDMS_C64C_NTSC_SV, "C64C NTSC" },
/* tr */ { IDMS_C64C_NTSC_TR, "C64C NTSC" },

/* en */ { IDMS_C64_OLD_NTSC,    "C64 old NTSC" },
/* da */ { IDMS_C64_OLD_NTSC_DA, "C64 gammel NTSC" },
/* de */ { IDMS_C64_OLD_NTSC_DE, "C64 alt NTSC" },
/* es */ { IDMS_C64_OLD_NTSC_ES, "C64 NTSC antiguo" },
/* fr */ { IDMS_C64_OLD_NTSC_FR, "" },  /* fuzzy */
/* hu */ { IDMS_C64_OLD_NTSC_HU, "" },  /* fuzzy */
/* it */ { IDMS_C64_OLD_NTSC_IT, "C64 NTSC vecchio" },
/* ko */ { IDMS_C64_OLD_NTSC_KO, "C64 �õ� NTSC" },
/* nl */ { IDMS_C64_OLD_NTSC_NL, "C64 oud NTSC" },
/* pl */ { IDMS_C64_OLD_NTSC_PL, "C64 stary NTSC" },
/* ru */ { IDMS_C64_OLD_NTSC_RU, "" },  /* fuzzy */
/* sv */ { IDMS_C64_OLD_NTSC_SV, "C64 gammal NTSC" },
/* tr */ { IDMS_C64_OLD_NTSC_TR, "C64 eski NTSC" },

/* en */ { IDMS_DREAN,    "Drean" },
/* da */ { IDMS_DREAN_DA, "Drean" },
/* de */ { IDMS_DREAN_DE, "Drean" },
/* es */ { IDMS_DREAN_ES, "Drean" },
/* fr */ { IDMS_DREAN_FR, "" },  /* fuzzy */
/* hu */ { IDMS_DREAN_HU, "" },  /* fuzzy */
/* it */ { IDMS_DREAN_IT, "Drean" },
/* ko */ { IDMS_DREAN_KO, "�帰" },
/* nl */ { IDMS_DREAN_NL, "Drean" },
/* pl */ { IDMS_DREAN_PL, "Drean" },
/* ru */ { IDMS_DREAN_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DREAN_SV, "Drean" },
/* tr */ { IDMS_DREAN_TR, "Drean" },

/* en */ { IDMS_CUSTOM_C64_MODEL,    "Custom C64 model" },
/* da */ { IDMS_CUSTOM_C64_MODEL_DA, "Speciel C64 model" },
/* de */ { IDMS_CUSTOM_C64_MODEL_DE, "Modifiziertes C64 Modell" },
/* es */ { IDMS_CUSTOM_C64_MODEL_ES, "Custom C64 model" },
/* fr */ { IDMS_CUSTOM_C64_MODEL_FR, "" },  /* fuzzy */
/* hu */ { IDMS_CUSTOM_C64_MODEL_HU, "" },  /* fuzzy */
/* it */ { IDMS_CUSTOM_C64_MODEL_IT, "Modello C64 personalizzato" },
/* ko */ { IDMS_CUSTOM_C64_MODEL_KO, "" },  /* fuzzy */
/* nl */ { IDMS_CUSTOM_C64_MODEL_NL, "Aangepast C64 model" },
/* pl */ { IDMS_CUSTOM_C64_MODEL_PL, "W�asny model C64" },
/* ru */ { IDMS_CUSTOM_C64_MODEL_RU, "" },  /* fuzzy */
/* sv */ { IDMS_CUSTOM_C64_MODEL_SV, "Speciell C64-modell" },
/* tr */ { IDMS_CUSTOM_C64_MODEL_TR, "�zel C64 modeli" },

/* en */ { IDMS_AUTOSTART_SETTINGS,    "Autostart settings..." },
/* da */ { IDMS_AUTOSTART_SETTINGS_DA, "Autostart-indstillinger..." },
/* de */ { IDMS_AUTOSTART_SETTINGS_DE, "Autostart Einstellungen..." },
/* es */ { IDMS_AUTOSTART_SETTINGS_ES, "Ajustes de autoinicio..." },
/* fr */ { IDMS_AUTOSTART_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_AUTOSTART_SETTINGS_HU, "Autostart be�ll�t�sai..." },
/* it */ { IDMS_AUTOSTART_SETTINGS_IT, "Impostazioni avvio automatico..." },
/* ko */ { IDMS_AUTOSTART_SETTINGS_KO, "�ڵ����� ����..." },
/* nl */ { IDMS_AUTOSTART_SETTINGS_NL, "Autostart instellingen..." },
/* pl */ { IDMS_AUTOSTART_SETTINGS_PL, "Ustawienia autostartu..." },
/* ru */ { IDMS_AUTOSTART_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_AUTOSTART_SETTINGS_SV, "Autostartinst�llningar..." },
/* tr */ { IDMS_AUTOSTART_SETTINGS_TR, "Otomatik ba�latma ayarlar�..." },

/* en */ { IDMS_VIDEO_SETTINGS,    "Video settings..." },
/* da */ { IDMS_VIDEO_SETTINGS_DA, "Grafikindstillinger..." },
/* de */ { IDMS_VIDEO_SETTINGS_DE, "Video Einstellungen..." },
/* es */ { IDMS_VIDEO_SETTINGS_ES, "Ajustes de video..." },
/* fr */ { IDMS_VIDEO_SETTINGS_FR, "Param�tres vid�o..." },
/* hu */ { IDMS_VIDEO_SETTINGS_HU, "Vide� be�ll�t�sai..." },
/* it */ { IDMS_VIDEO_SETTINGS_IT, "Impostazioni video..." },
/* ko */ { IDMS_VIDEO_SETTINGS_KO, "���� ����..." },
/* nl */ { IDMS_VIDEO_SETTINGS_NL, "Video instellingen..." },
/* pl */ { IDMS_VIDEO_SETTINGS_PL, "Ustawienia wideo..." },
/* ru */ { IDMS_VIDEO_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_VIDEO_SETTINGS_SV, "Grafikinst�llningar..." },
/* tr */ { IDMS_VIDEO_SETTINGS_TR, "G�r�nt� ayarlar�..." },

/* en */ { IDMS_VIC_SETTINGS,    "VIC settings..." },
/* da */ { IDMS_VIC_SETTINGS_DA, "VIC-indstillinger..." },
/* de */ { IDMS_VIC_SETTINGS_DE, "VIC Einstellungen..." },
/* es */ { IDMS_VIC_SETTINGS_ES, "Ajustes VIC..." },
/* fr */ { IDMS_VIC_SETTINGS_FR, "Param�tres VIC..." },
/* hu */ { IDMS_VIC_SETTINGS_HU, "VIC be�ll�t�sai..." },
/* it */ { IDMS_VIC_SETTINGS_IT, "Impostazioni VIC..." },
/* ko */ { IDMS_VIC_SETTINGS_KO, "VIC ����..." },
/* nl */ { IDMS_VIC_SETTINGS_NL, "VIC instellingen..." },
/* pl */ { IDMS_VIC_SETTINGS_PL, "Ustawienia VIC..." },
/* ru */ { IDMS_VIC_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_VIC_SETTINGS_SV, "VIC-inst�llningar..." },
/* tr */ { IDMS_VIC_SETTINGS_TR, "VIC ayarlar�..." },

/* en */ { IDMS_CBM2_SETTINGS,    "CBM2 settings..." },
/* da */ { IDMS_CBM2_SETTINGS_DA, "CBM2-indstillinger..." },
/* de */ { IDMS_CBM2_SETTINGS_DE, "CBM2 Einstellungen..." },
/* es */ { IDMS_CBM2_SETTINGS_ES, "Ajustes CBM2..." },
/* fr */ { IDMS_CBM2_SETTINGS_FR, "Param�tres CBM2..." },
/* hu */ { IDMS_CBM2_SETTINGS_HU, "CBM2 be�ll�t�sai..." },
/* it */ { IDMS_CBM2_SETTINGS_IT, "Impostazioni CBM2..." },
/* ko */ { IDMS_CBM2_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_CBM2_SETTINGS_NL, "CBM2 instellingen..." },
/* pl */ { IDMS_CBM2_SETTINGS_PL, "Ustawienia CBM2..." },
/* ru */ { IDMS_CBM2_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_CBM2_SETTINGS_SV, "CBM2-inst�llningar..." },
/* tr */ { IDMS_CBM2_SETTINGS_TR, "CBM2 ayarlar�..." },

/* en */ { IDMS_SET_PET_MODEL,    "Change PET model" },
/* da */ { IDMS_SET_PET_MODEL_DA, "Skift PET-model" },
/* de */ { IDMS_SET_PET_MODEL_DE, "PET Modell ver�ndern" },
/* es */ { IDMS_SET_PET_MODEL_ES, "Cambiar modelo PET" },
/* fr */ { IDMS_SET_PET_MODEL_FR, "" },  /* fuzzy */
/* hu */ { IDMS_SET_PET_MODEL_HU, "PET modell kiv�laszt�sa" },
/* it */ { IDMS_SET_PET_MODEL_IT, "Cambia modello di PET" },
/* ko */ { IDMS_SET_PET_MODEL_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SET_PET_MODEL_NL, "Verander PET model" },
/* pl */ { IDMS_SET_PET_MODEL_PL, "Zmie� model PET" },
/* ru */ { IDMS_SET_PET_MODEL_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SET_PET_MODEL_SV, "Byt PET-modell" },
/* tr */ { IDMS_SET_PET_MODEL_TR, "PET modelini de�i�tir" },

/* en */ { IDMS_PET_SETTINGS,    "PET settings..." },
/* da */ { IDMS_PET_SETTINGS_DA, "PET-indstillinger..." },
/* de */ { IDMS_PET_SETTINGS_DE, "PET Einstellungen..." },
/* es */ { IDMS_PET_SETTINGS_ES, "Ajustes PET..." },
/* fr */ { IDMS_PET_SETTINGS_FR, "Param�tres PET..." },
/* hu */ { IDMS_PET_SETTINGS_HU, "PET be�ll�t�sai..." },
/* it */ { IDMS_PET_SETTINGS_IT, "Impostazioni PET..." },
/* ko */ { IDMS_PET_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_PET_SETTINGS_NL, "PET instellingen..." },
/* pl */ { IDMS_PET_SETTINGS_PL, "Ustawienia PET..." },
/* ru */ { IDMS_PET_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_PET_SETTINGS_SV, "PET-inst�llningar..." },
/* tr */ { IDMS_PET_SETTINGS_TR, "PET ayarlar�..." },

/* en */ { IDMS_PERIPHERAL_SETTINGS,    "Peripheral settings..." },
/* da */ { IDMS_PERIPHERAL_SETTINGS_DA, "Eksterne enhedsindstillinger..." },
/* de */ { IDMS_PERIPHERAL_SETTINGS_DE, "Peripherie Einstellungen..." },
/* es */ { IDMS_PERIPHERAL_SETTINGS_ES, "Ajustes de perif�ricos..." },
/* fr */ { IDMS_PERIPHERAL_SETTINGS_FR, "Param�tres des p�riph�riques..." },
/* hu */ { IDMS_PERIPHERAL_SETTINGS_HU, "Perif�ri�k be�ll�t�sai..." },
/* it */ { IDMS_PERIPHERAL_SETTINGS_IT, "Impostazioni periferiche..." },
/* ko */ { IDMS_PERIPHERAL_SETTINGS_KO, "�ֺ���ġ ����..." },
/* nl */ { IDMS_PERIPHERAL_SETTINGS_NL, "Randapparaten instellingen..." },
/* pl */ { IDMS_PERIPHERAL_SETTINGS_PL, "Ustawienia zewn�trzne..." },
/* ru */ { IDMS_PERIPHERAL_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_PERIPHERAL_SETTINGS_SV, "Inst�llningar f�r kringutrustning..." },
/* tr */ { IDMS_PERIPHERAL_SETTINGS_TR, "�evresel ayarlar..." },

/* en */ { IDMS_DRIVE_SETTINGS,    "Drive settings..." },
/* da */ { IDMS_DRIVE_SETTINGS_DA, "Diskettedrevsindstillinger..." },
/* de */ { IDMS_DRIVE_SETTINGS_DE, "Floppy Einstellungen..." },
/* es */ { IDMS_DRIVE_SETTINGS_ES, "Ajustes unidad disco..." },
/* fr */ { IDMS_DRIVE_SETTINGS_FR, "Param�tres des lecteurs..." },
/* hu */ { IDMS_DRIVE_SETTINGS_HU, "Lemezegys�g be�ll�t�sai..." },
/* it */ { IDMS_DRIVE_SETTINGS_IT, "Impostazioni drive..." },
/* ko */ { IDMS_DRIVE_SETTINGS_KO, "����̺� ����..." },
/* nl */ { IDMS_DRIVE_SETTINGS_NL, "Drive instellingen..." },
/* pl */ { IDMS_DRIVE_SETTINGS_PL, "Ustawienia nap�du..." },
/* ru */ { IDMS_DRIVE_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DRIVE_SETTINGS_SV, "Diskettenhetsinst�llningar..." },
/* tr */ { IDMS_DRIVE_SETTINGS_TR, "S�r�c� ayarlar�..." },

/* en */ { IDMS_PRINTER_SETTINGS,    "Printer settings..." },
/* da */ { IDMS_PRINTER_SETTINGS_DA, "Printerindstillinger..." },
/* de */ { IDMS_PRINTER_SETTINGS_DE, "Drucker Einstellungen..." },
/* es */ { IDMS_PRINTER_SETTINGS_ES, "Ajustes de impresora..." },
/* fr */ { IDMS_PRINTER_SETTINGS_FR, "Param�tres d'imprimante..." },
/* hu */ { IDMS_PRINTER_SETTINGS_HU, "Nyomtat� be�ll�t�sai..." },
/* it */ { IDMS_PRINTER_SETTINGS_IT, "Impostazioni stampanti..." },
/* ko */ { IDMS_PRINTER_SETTINGS_KO, "������ ����..." },
/* nl */ { IDMS_PRINTER_SETTINGS_NL, "Printer instellingen..." },
/* pl */ { IDMS_PRINTER_SETTINGS_PL, "Ustawienia drukarki..." },
/* ru */ { IDMS_PRINTER_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_PRINTER_SETTINGS_SV, "Skrivarinst�llningar..." },
/* tr */ { IDMS_PRINTER_SETTINGS_TR, "Yaz�c� ayarlar�..." },

/* en */ { IDMS_DATASETTE_SETTINGS,    "Datasette settings..." },
/* da */ { IDMS_DATASETTE_SETTINGS_DA, "Datasetteindstillinger..." },
/* de */ { IDMS_DATASETTE_SETTINGS_DE, "Datasette Einstellungen..." },
/* es */ { IDMS_DATASETTE_SETTINGS_ES, "Ajustes Datasette..." },
/* fr */ { IDMS_DATASETTE_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_DATASETTE_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_DATASETTE_SETTINGS_IT, "Impostazioni registratore..." },
/* ko */ { IDMS_DATASETTE_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_DATASETTE_SETTINGS_NL, "Datasette instellingen..." },
/* pl */ { IDMS_DATASETTE_SETTINGS_PL, "Ustawienia magnetofonu..." },
/* ru */ { IDMS_DATASETTE_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DATASETTE_SETTINGS_SV, "Datasetteinst�llningar..." },
/* tr */ { IDMS_DATASETTE_SETTINGS_TR, "Teyp Ayarlar�..." },

/* en */ { IDMS_PLUS4_SETTINGS,    "Plus4 settings..." },
/* da */ { IDMS_PLUS4_SETTINGS_DA, "Plus4-indstillinger..." },
/* de */ { IDMS_PLUS4_SETTINGS_DE, "Plus4 Einstellungen..." },
/* es */ { IDMS_PLUS4_SETTINGS_ES, "Ajustes Plus4..." },
/* fr */ { IDMS_PLUS4_SETTINGS_FR, "Param�tres Plus4..." },
/* hu */ { IDMS_PLUS4_SETTINGS_HU, "Plus4 be�ll�t�sai..." },
/* it */ { IDMS_PLUS4_SETTINGS_IT, "Impostazioni Plus4..." },
/* ko */ { IDMS_PLUS4_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_PLUS4_SETTINGS_NL, "Plus4 instellingen..." },
/* pl */ { IDMS_PLUS4_SETTINGS_PL, "Ustawienia Plus4..." },
/* ru */ { IDMS_PLUS4_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_PLUS4_SETTINGS_SV, "Plus4-inst�llningar..." },
/* tr */ { IDMS_PLUS4_SETTINGS_TR, "Plus4 ayarlar�..." },

/* en */ { IDMS_VICII_SETTINGS,    "VIC-II settings..." },
/* da */ { IDMS_VICII_SETTINGS_DA, "VIC-II-indstillinger..." },
/* de */ { IDMS_VICII_SETTINGS_DE, "VIC-II Einstellungen..." },
/* es */ { IDMS_VICII_SETTINGS_ES, "Ajuester VIC-II..." },
/* fr */ { IDMS_VICII_SETTINGS_FR, "Param�tres VIC-II..." },
/* hu */ { IDMS_VICII_SETTINGS_HU, "VIC-II be�ll�t�sai..." },
/* it */ { IDMS_VICII_SETTINGS_IT, "Impostazioni VIC-II..." },
/* ko */ { IDMS_VICII_SETTINGS_KO, "VIC-II ����..." },
/* nl */ { IDMS_VICII_SETTINGS_NL, "VIC-II instellingen..." },
/* pl */ { IDMS_VICII_SETTINGS_PL, "Ustawienia VIC-II..." },
/* ru */ { IDMS_VICII_SETTINGS_RU, "��������� VIC-II..." },
/* sv */ { IDMS_VICII_SETTINGS_SV, "VIC-II-inst�llningar..." },
/* tr */ { IDMS_VICII_SETTINGS_TR, "VIC-II ayarlar�..." },

/* en */ { IDMS_JOYSTICK_SETTINGS,    "Joystick settings..." },
/* da */ { IDMS_JOYSTICK_SETTINGS_DA, "Joystick indstillinger..." },
/* de */ { IDMS_JOYSTICK_SETTINGS_DE, "Joystick Einstellungen..." },
/* es */ { IDMS_JOYSTICK_SETTINGS_ES, "Ajustes de joystick..." },
/* fr */ { IDMS_JOYSTICK_SETTINGS_FR, "Param�tres des joysticks..." },
/* hu */ { IDMS_JOYSTICK_SETTINGS_HU, "Botkorm�ny be�ll�t�sai..." },
/* it */ { IDMS_JOYSTICK_SETTINGS_IT, "Impostazioni joystick..." },
/* ko */ { IDMS_JOYSTICK_SETTINGS_KO, "���̽�ƽ ����..." },
/* nl */ { IDMS_JOYSTICK_SETTINGS_NL, "Joystick instellingen..." },
/* pl */ { IDMS_JOYSTICK_SETTINGS_PL, "Ustawienia joysticka..." },
/* ru */ { IDMS_JOYSTICK_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_JOYSTICK_SETTINGS_SV, "Inst�llningar f�r styrspak..." },
/* tr */ { IDMS_JOYSTICK_SETTINGS_TR, "Joystick ayarlar�..." },

/* en */ { IDMS_JOYSTICK_DEVICE_SELECT,    "Joystick device selection" },
/* da */ { IDMS_JOYSTICK_DEVICE_SELECT_DA, "Joystick enheds-valg" },
/* de */ { IDMS_JOYSTICK_DEVICE_SELECT_DE, "Joystick Ger�te Auswahl" },
/* es */ { IDMS_JOYSTICK_DEVICE_SELECT_ES, "Selecci�n periferico joystick" },
/* fr */ { IDMS_JOYSTICK_DEVICE_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDMS_JOYSTICK_DEVICE_SELECT_HU, "Botkorm�ny eszk�z kiv�laszt�sa" },
/* it */ { IDMS_JOYSTICK_DEVICE_SELECT_IT, "Selezione dispositivo joystick" },
/* ko */ { IDMS_JOYSTICK_DEVICE_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDMS_JOYSTICK_DEVICE_SELECT_NL, "Joystickapparaatselectie" },
/* pl */ { IDMS_JOYSTICK_DEVICE_SELECT_PL, "Wyb�r urz�dzenia joysticka" },
/* ru */ { IDMS_JOYSTICK_DEVICE_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_JOYSTICK_DEVICE_SELECT_SV, "V�lj styrspakenhet" },
/* tr */ { IDMS_JOYSTICK_DEVICE_SELECT_TR, "Joystick ayg�t se�imi" },

/* en */ { IDMS_JOYSTICK_FIRE_SELECT,    "Joystick fire button selection" },
/* da */ { IDMS_JOYSTICK_FIRE_SELECT_DA, "V�lg fireknap for joystick" },
/* de */ { IDMS_JOYSTICK_FIRE_SELECT_DE, "Joystick Feuerknopf Wahl" },
/* es */ { IDMS_JOYSTICK_FIRE_SELECT_ES, "Selecci�n bot�n disparo joystick" },
/* fr */ { IDMS_JOYSTICK_FIRE_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDMS_JOYSTICK_FIRE_SELECT_HU, "Botkorm�ny t�zgomb kiv�laszt�s" },
/* it */ { IDMS_JOYSTICK_FIRE_SELECT_IT, "Selezione pulsante di fuoco del joystick" },
/* ko */ { IDMS_JOYSTICK_FIRE_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDMS_JOYSTICK_FIRE_SELECT_NL, "Joystickvuurknopselectie" },
/* pl */ { IDMS_JOYSTICK_FIRE_SELECT_PL, "Wyb�r przycisku fire joysticka" },
/* ru */ { IDMS_JOYSTICK_FIRE_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_JOYSTICK_FIRE_SELECT_SV, "V�lj fireknapp f�r styrspak" },
/* tr */ { IDMS_JOYSTICK_FIRE_SELECT_TR, "Joystick ate� d��mesi se�imi" },

/* en */ { IDMS_KEYBOARD_SETTINGS,    "Keyboard settings..." },
/* da */ { IDMS_KEYBOARD_SETTINGS_DA, "Tastaturindstillinger..." },
/* de */ { IDMS_KEYBOARD_SETTINGS_DE, "Tastatur Einstellungen..." },
/* es */ { IDMS_KEYBOARD_SETTINGS_ES, "Ajustes de teclado..." },
/* fr */ { IDMS_KEYBOARD_SETTINGS_FR, "Param�tres du clavier..." },
/* hu */ { IDMS_KEYBOARD_SETTINGS_HU, "Billenty�zet be�ll�t�sai..." },
/* it */ { IDMS_KEYBOARD_SETTINGS_IT, "Impostazioni tastiera..." },
/* ko */ { IDMS_KEYBOARD_SETTINGS_KO, "Ű���� ����..." },
/* nl */ { IDMS_KEYBOARD_SETTINGS_NL, "Toetsenbord instellingen..." },
/* pl */ { IDMS_KEYBOARD_SETTINGS_PL, "Ustawienia klawiatury..." },
/* ru */ { IDMS_KEYBOARD_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_KEYBOARD_SETTINGS_SV, "Tangentbordsinst�llningar..." },
/* tr */ { IDMS_KEYBOARD_SETTINGS_TR, "Klavye ayarlar�..." },

/* en */ { IDMS_MOUSE_SETTINGS,    "Mouse settings..." },
/* da */ { IDMS_MOUSE_SETTINGS_DA, "Musseindstillinger..." },
/* de */ { IDMS_MOUSE_SETTINGS_DE, "Maus Einstellungen..." },
/* es */ { IDMS_MOUSE_SETTINGS_ES, "Ajustes rat�n..." },
/* fr */ { IDMS_MOUSE_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_MOUSE_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_MOUSE_SETTINGS_IT, "Impostazioni mouse..." },
/* ko */ { IDMS_MOUSE_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_MOUSE_SETTINGS_NL, "Muis instellingen..." },
/* pl */ { IDMS_MOUSE_SETTINGS_PL, "Ustawienia myszy..." },
/* ru */ { IDMS_MOUSE_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_MOUSE_SETTINGS_SV, "Musinst�llningar..." },
/* tr */ { IDMS_MOUSE_SETTINGS_TR, "Mouse Ayarlar�..." },

/* en */ { IDMS_SOUND_SETTINGS,    "Sound settings..." },
/* da */ { IDMS_SOUND_SETTINGS_DA, "Lydindstillinger..." },
/* de */ { IDMS_SOUND_SETTINGS_DE, "Sound Einstellungen..." },
/* es */ { IDMS_SOUND_SETTINGS_ES, "Ajustes de sonido..." },
/* fr */ { IDMS_SOUND_SETTINGS_FR, "Param�tres son..." },
/* hu */ { IDMS_SOUND_SETTINGS_HU, "Hang be�ll�t�sai..." },
/* it */ { IDMS_SOUND_SETTINGS_IT, "Impostazioni audio..." },
/* ko */ { IDMS_SOUND_SETTINGS_KO, "�Ҹ� ����..." },
/* nl */ { IDMS_SOUND_SETTINGS_NL, "Geluidsinstellingen..." },
/* pl */ { IDMS_SOUND_SETTINGS_PL, "Ustawienia d�wi�ku..." },
/* ru */ { IDMS_SOUND_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SOUND_SETTINGS_SV, "Ljudinst�llningar..." },
/* tr */ { IDMS_SOUND_SETTINGS_TR, "Ses ayarlar�..." },

/* en */ { IDMS_SID_SETTINGS,    "SID settings..." },
/* da */ { IDMS_SID_SETTINGS_DA, "SID-indstillinger..." },
/* de */ { IDMS_SID_SETTINGS_DE, "SID Einstellungen..." },
/* es */ { IDMS_SID_SETTINGS_ES, "Ajustes SID..." },
/* fr */ { IDMS_SID_SETTINGS_FR, "Param�tres SID..." },
/* hu */ { IDMS_SID_SETTINGS_HU, "SID be�ll�t�sai..." },
/* it */ { IDMS_SID_SETTINGS_IT, "Impostazioni SID..." },
/* ko */ { IDMS_SID_SETTINGS_KO, "SID ����..." },
/* nl */ { IDMS_SID_SETTINGS_NL, "SID instellingen..." },
/* pl */ { IDMS_SID_SETTINGS_PL, "Ustawienia SID..." },
/* ru */ { IDMS_SID_SETTINGS_RU, "��������� SID..." },
/* sv */ { IDMS_SID_SETTINGS_SV, "SID-inst�llningar..." },
/* tr */ { IDMS_SID_SETTINGS_TR, "SID ayarlar�..." },

/* en */ { IDMS_COMPUTER_ROM_SETTINGS,    "Computer ROM settings..." },
/* da */ { IDMS_COMPUTER_ROM_SETTINGS_DA, "Computer ROM-indstillinger..." },
/* de */ { IDMS_COMPUTER_ROM_SETTINGS_DE, "Computer ROM Einstellungen..." },
/* es */ { IDMS_COMPUTER_ROM_SETTINGS_ES, "Ajustes ROM ordenador..." },
/* fr */ { IDMS_COMPUTER_ROM_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_COMPUTER_ROM_SETTINGS_HU, "Sz�m�t�g�p ROM be�ll�t�sai..." },
/* it */ { IDMS_COMPUTER_ROM_SETTINGS_IT, "Impostazioni ROM del computer..." },
/* ko */ { IDMS_COMPUTER_ROM_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_COMPUTER_ROM_SETTINGS_NL, "Computer ROM instellingen..." },
/* pl */ { IDMS_COMPUTER_ROM_SETTINGS_PL, "Ustawienia ROM komputera..." },
/* ru */ { IDMS_COMPUTER_ROM_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_COMPUTER_ROM_SETTINGS_SV, "ROM-inst�llningar f�r dator..." },
/* tr */ { IDMS_COMPUTER_ROM_SETTINGS_TR, "Bilgisayar ROM ayarlar�..." },

/* en */ { IDMS_DRIVE_ROM_SETTINGS,    "Drive ROM settings..." },
/* da */ { IDMS_DRIVE_ROM_SETTINGS_DA, "Drev ROM-indstillinger..." },
/* de */ { IDMS_DRIVE_ROM_SETTINGS_DE, "Floppy ROM Einstellungen..." },
/* es */ { IDMS_DRIVE_ROM_SETTINGS_ES, "Ajustes ROM unidad disco..." },
/* fr */ { IDMS_DRIVE_ROM_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_DRIVE_ROM_SETTINGS_HU, "Lemezegys�g ROM be�ll�t�sai..." },
/* it */ { IDMS_DRIVE_ROM_SETTINGS_IT, "Impostazioni ROM del drive..." },
/* ko */ { IDMS_DRIVE_ROM_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_DRIVE_ROM_SETTINGS_NL, "Drive ROM instellingen..." },
/* pl */ { IDMS_DRIVE_ROM_SETTINGS_PL, "Ustawienia ROM nap�du..." },
/* ru */ { IDMS_DRIVE_ROM_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DRIVE_ROM_SETTINGS_SV, "ROM-inst�llningar f�r diskettenhet..." },
/* tr */ { IDMS_DRIVE_ROM_SETTINGS_TR, "S�r�c� ROM ayarlar�..." },

/* en */ { IDMS_RAM_SETTINGS,    "RAM settings..." },
/* da */ { IDMS_RAM_SETTINGS_DA, "RAM-indstillinger..." },
/* de */ { IDMS_RAM_SETTINGS_DE, "RAM Einstellungen..." },
/* es */ { IDMS_RAM_SETTINGS_ES, "Ajustes RAM..." },
/* fr */ { IDMS_RAM_SETTINGS_FR, "Param�tres de la RAM..." },
/* hu */ { IDMS_RAM_SETTINGS_HU, "RAM be�ll�t�sai..." },
/* it */ { IDMS_RAM_SETTINGS_IT, "Impostazioni RAM..." },
/* ko */ { IDMS_RAM_SETTINGS_KO, "RAM ����..." },
/* nl */ { IDMS_RAM_SETTINGS_NL, "RAM instellingen..." },
/* pl */ { IDMS_RAM_SETTINGS_PL, "Ustawienia RAM..." },
/* ru */ { IDMS_RAM_SETTINGS_RU, "��������� RAM..." },
/* sv */ { IDMS_RAM_SETTINGS_SV, "RAM-inst�llningar..." },
/* tr */ { IDMS_RAM_SETTINGS_TR, "RAM ayarlar�..." },

/* en */ { IDMS_RS232_SETTINGS,    "RS232 settings..." },
/* da */ { IDMS_RS232_SETTINGS_DA, "RS232-indstillinger..." },
/* de */ { IDMS_RS232_SETTINGS_DE, "RS232 Einstellungen..." },
/* es */ { IDMS_RS232_SETTINGS_ES, "Ajustes RS232..." },
/* fr */ { IDMS_RS232_SETTINGS_FR, "Param�tres RS232..." },
/* hu */ { IDMS_RS232_SETTINGS_HU, "RS232 be�ll�t�sai..." },
/* it */ { IDMS_RS232_SETTINGS_IT, "Impostazioni RS232..." },
/* ko */ { IDMS_RS232_SETTINGS_KO, "RS232 ����..." },
/* nl */ { IDMS_RS232_SETTINGS_NL, "RS232 instellingen..." },
/* pl */ { IDMS_RS232_SETTINGS_PL, "Ustawienia RS232..." },
/* ru */ { IDMS_RS232_SETTINGS_RU, "��������� RS232..." },
/* sv */ { IDMS_RS232_SETTINGS_SV, "RS232-inst�llningar..." },
/* tr */ { IDMS_RS232_SETTINGS_TR, "RS232 ayarlar�..." },

/* en */ { IDMS_C128_SETTINGS,    "C128 settings..." },
/* da */ { IDMS_C128_SETTINGS_DA, "C128-indstillinger..." },
/* de */ { IDMS_C128_SETTINGS_DE, "C128 Einstellungen..." },
/* es */ { IDMS_C128_SETTINGS_ES, "Ajustes C128..." },
/* fr */ { IDMS_C128_SETTINGS_FR, "Param�tres C128..." },
/* hu */ { IDMS_C128_SETTINGS_HU, "C128 be�ll�t�sai..." },
/* it */ { IDMS_C128_SETTINGS_IT, "Impostazioni C128..." },
/* ko */ { IDMS_C128_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_C128_SETTINGS_NL, "C128 instellingen..." },
/* pl */ { IDMS_C128_SETTINGS_PL, "Ustawienia C128..." },
/* ru */ { IDMS_C128_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_C128_SETTINGS_SV, "C128-inst�llningar..." },
/* tr */ { IDMS_C128_SETTINGS_TR, "C128 ayarlar�..." },

/* en */ { IDMS_CART_IO_SETTINGS,    "Cartridge/IO settings" },
/* da */ { IDMS_CART_IO_SETTINGS_DA, "Modul/IO-indstillinger" },
/* de */ { IDMS_CART_IO_SETTINGS_DE, "Erweiterungsmodul I/O Einstellungen" },
/* es */ { IDMS_CART_IO_SETTINGS_ES, "Ajustes entrada/salida cartucho" },
/* fr */ { IDMS_CART_IO_SETTINGS_FR, "Param�tres E/S cartouche" },
/* hu */ { IDMS_CART_IO_SETTINGS_HU, "Cartridge/IO be�ll�t�sai" },
/* it */ { IDMS_CART_IO_SETTINGS_IT, "Impostazioni cartuccia/IO" },
/* ko */ { IDMS_CART_IO_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_CART_IO_SETTINGS_NL, "Cartridge/IO instellingen" },
/* pl */ { IDMS_CART_IO_SETTINGS_PL, "Ustawienia kartrid�a i we/wy" },
/* ru */ { IDMS_CART_IO_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_CART_IO_SETTINGS_SV, "Modul/IO-inst�llningar" },
/* tr */ { IDMS_CART_IO_SETTINGS_TR, "Kartu�/G� ayarlar�" },

/* en */ { IDMS_REU_SETTINGS,    "REU settings..." },
/* da */ { IDMS_REU_SETTINGS_DA, "REU-indstillinger..." },
/* de */ { IDMS_REU_SETTINGS_DE, "REU Einstellungen..." },
/* es */ { IDMS_REU_SETTINGS_ES, "Ajustes REU..." },
/* fr */ { IDMS_REU_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_REU_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_REU_SETTINGS_IT, "Impostazioni REU..." },
/* ko */ { IDMS_REU_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_REU_SETTINGS_NL, "REU instellingen..." },
/* pl */ { IDMS_REU_SETTINGS_PL, "Ustawienia REU..." },
/* ru */ { IDMS_REU_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_REU_SETTINGS_SV, "REU-Inst�llningar..." },
/* tr */ { IDMS_REU_SETTINGS_TR, "REU Ayarlar�..." },

/* en */ { IDMS_MAGIC_VOICE_SETTINGS,    "Magic Voice settings..." },
/* da */ { IDMS_MAGIC_VOICE_SETTINGS_DA, "Magic Voice indstillinger..." },
/* de */ { IDMS_MAGIC_VOICE_SETTINGS_DE, "Magic Voice Einstellungen..." },
/* es */ { IDMS_MAGIC_VOICE_SETTINGS_ES, "Ajustes Magic Voice..." },
/* fr */ { IDMS_MAGIC_VOICE_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_MAGIC_VOICE_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_MAGIC_VOICE_SETTINGS_IT, "Impostazioni Magic Voice..." },
/* ko */ { IDMS_MAGIC_VOICE_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_MAGIC_VOICE_SETTINGS_NL, "Magic Voice instellingen..." },
/* pl */ { IDMS_MAGIC_VOICE_SETTINGS_PL, "Ustawienia Magic Voice..." },
/* ru */ { IDMS_MAGIC_VOICE_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_MAGIC_VOICE_SETTINGS_SV, "Magic Voice-inst�llningar..." },
/* tr */ { IDMS_MAGIC_VOICE_SETTINGS_TR, "Magic Voice ayarlar�..." },

/* en */ { IDMS_GEORAM_SETTINGS,    "GEO-RAM settings..." },
/* da */ { IDMS_GEORAM_SETTINGS_DA, "GEO-RAM-indstillinger..." },
/* de */ { IDMS_GEORAM_SETTINGS_DE, "GEO-RAM Einstellungen..." },
/* es */ { IDMS_GEORAM_SETTINGS_ES, "Ajustes GEO-RAM..." },
/* fr */ { IDMS_GEORAM_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_GEORAM_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_GEORAM_SETTINGS_IT, "Impostazioni GEO-RAM..." },
/* ko */ { IDMS_GEORAM_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_GEORAM_SETTINGS_NL, "GEO-RAM instellingen..." },
/* pl */ { IDMS_GEORAM_SETTINGS_PL, "Ustawienia GEO-RAM..." },
/* ru */ { IDMS_GEORAM_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_GEORAM_SETTINGS_SV, "GEO-RAM-inst�llningar..." },
/* tr */ { IDMS_GEORAM_SETTINGS_TR, "GEO-RAM ayarlar�..." },

/* en */ { IDMS_GEORAM_SETTINGS_MASCUERADE,    "GEO-RAM settings (MasC=uerade)..." },
/* da */ { IDMS_GEORAM_SETTINGS_MASCUERADE_DA, "GEO-RAM-indstillinger (MasC=uerade)..." },
/* de */ { IDMS_GEORAM_SETTINGS_MASCUERADE_DE, "GEO-RAM Einstellungen (MasC=uerade)..." },
/* es */ { IDMS_GEORAM_SETTINGS_MASCUERADE_ES, "Ajustes GEO-RAM (MasC=uerade)..." },
/* fr */ { IDMS_GEORAM_SETTINGS_MASCUERADE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_GEORAM_SETTINGS_MASCUERADE_HU, "" },  /* fuzzy */
/* it */ { IDMS_GEORAM_SETTINGS_MASCUERADE_IT, "Impostazioni GEO-RAM (MasC=uerade)..." },
/* ko */ { IDMS_GEORAM_SETTINGS_MASCUERADE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_GEORAM_SETTINGS_MASCUERADE_NL, "GEO-RAM instellingen (MasC=uerade)..." },
/* pl */ { IDMS_GEORAM_SETTINGS_MASCUERADE_PL, "Ustawienia GEO-RAM (MasC=uerade)..." },
/* ru */ { IDMS_GEORAM_SETTINGS_MASCUERADE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_GEORAM_SETTINGS_MASCUERADE_SV, "GEO-RAM-inst�llningar (MasC=uerade)..." },
/* tr */ { IDMS_GEORAM_SETTINGS_MASCUERADE_TR, "GEO-RAM ayarlar� (MasC=uerade)..." },

/* en */ { IDMS_RAMCART_SETTINGS,    "RamCart settings..." },
/* da */ { IDMS_RAMCART_SETTINGS_DA, "RamCart-indstillinger..." },
/* de */ { IDMS_RAMCART_SETTINGS_DE, "RamCart Einstellungen..." },
/* es */ { IDMS_RAMCART_SETTINGS_ES, "Ajustes RamCart..." },
/* fr */ { IDMS_RAMCART_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_RAMCART_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_RAMCART_SETTINGS_IT, "Impostazioni RamCart ..." },
/* ko */ { IDMS_RAMCART_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_RAMCART_SETTINGS_NL, "RamCart instellingen..." },
/* pl */ { IDMS_RAMCART_SETTINGS_PL, "Ustawienia RamCart..." },
/* ru */ { IDMS_RAMCART_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_RAMCART_SETTINGS_SV, "RamCart-inst�llningar..." },
/* tr */ { IDMS_RAMCART_SETTINGS_TR, "RamCart ayarlar�..." },

/* en */ { IDMS_DQBB_SETTINGS,    "Double Quick Brown Box settings..." },
/* da */ { IDMS_DQBB_SETTINGS_DA, "Double Quick Brown Box indstillinger..." },
/* de */ { IDMS_DQBB_SETTINGS_DE, "Double Quick Brown Box Einstellungen..." },
/* es */ { IDMS_DQBB_SETTINGS_ES, "Ajustes Double Quick Brown Box..." },
/* fr */ { IDMS_DQBB_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_DQBB_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_DQBB_SETTINGS_IT, "Impostazioni Double Quick Brown Box..." },
/* ko */ { IDMS_DQBB_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_DQBB_SETTINGS_NL, "Double Quick Brown Box instellingen..." },
/* pl */ { IDMS_DQBB_SETTINGS_PL, "Ustawienia Double Quick Brown Box..." },
/* ru */ { IDMS_DQBB_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DQBB_SETTINGS_SV, "Inst�llninga f�r dubbel Quick Brown Box..." },
/* tr */ { IDMS_DQBB_SETTINGS_TR, "Double Quick Brown Box ayarlar�..." },

/* en */ { IDMS_ISEPIC_SETTINGS,    "ISEPIC settings..." },
/* da */ { IDMS_ISEPIC_SETTINGS_DA, "ISEPIC-indstillinger..." },
/* de */ { IDMS_ISEPIC_SETTINGS_DE, "ISEPIC Einstellungen..." },
/* es */ { IDMS_ISEPIC_SETTINGS_ES, "Ajustes ISEPIC..." },
/* fr */ { IDMS_ISEPIC_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ISEPIC_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_ISEPIC_SETTINGS_IT, "Impostazioni ISEPIC..." },
/* ko */ { IDMS_ISEPIC_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_ISEPIC_SETTINGS_NL, "ISEPIC instellingen..." },
/* pl */ { IDMS_ISEPIC_SETTINGS_PL, "Ustawienia ISEPIC..." },
/* ru */ { IDMS_ISEPIC_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ISEPIC_SETTINGS_SV, "ISEPIC-inst�llningar..." },
/* tr */ { IDMS_ISEPIC_SETTINGS_TR, "ISEPIC ayarlar�..." },

/* en */ { IDMS_EXPERT_SETTINGS,    "Expert Cartridge settings..." },
/* da */ { IDMS_EXPERT_SETTINGS_DA, "Expert Cartridge-indstillinger..." },
/* de */ { IDMS_EXPERT_SETTINGS_DE, "Expert Cartridge Einstellungen..." },
/* es */ { IDMS_EXPERT_SETTINGS_ES, "Ajustes Expert Cartrige..." },
/* fr */ { IDMS_EXPERT_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_EXPERT_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_EXPERT_SETTINGS_IT, "Impostazioni Expert Cartridge..." },
/* ko */ { IDMS_EXPERT_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_EXPERT_SETTINGS_NL, "Expert Cartridge instellingen..." },
/* pl */ { IDMS_EXPERT_SETTINGS_PL, "Ustawienia Expert Cartridge..." },
/* ru */ { IDMS_EXPERT_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_EXPERT_SETTINGS_SV, "Inst�llningar f�r Expert Cartridge..." },
/* tr */ { IDMS_EXPERT_SETTINGS_TR, "Expert Kartu�u ayarlar�..." },

/* en */ { IDMS_PLUS60K_SETTINGS,    "PLUS60K settings..." },
/* da */ { IDMS_PLUS60K_SETTINGS_DA, "PLUS60K-indstillinger..." },
/* de */ { IDMS_PLUS60K_SETTINGS_DE, "PLUS60K Einstellungen..." },
/* es */ { IDMS_PLUS60K_SETTINGS_ES, "Ajustes PLUS60K..." },
/* fr */ { IDMS_PLUS60K_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_PLUS60K_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_PLUS60K_SETTINGS_IT, "Impostazioni PLUS256K..." },
/* ko */ { IDMS_PLUS60K_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_PLUS60K_SETTINGS_NL, "PLUS60K instellingen..." },
/* pl */ { IDMS_PLUS60K_SETTINGS_PL, "Ustawienia PLUS60K..." },
/* ru */ { IDMS_PLUS60K_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_PLUS60K_SETTINGS_SV, "PLUS60K-inst�llningar..." },
/* tr */ { IDMS_PLUS60K_SETTINGS_TR, "PLUS60K Ayarlar�..." },

/* en */ { IDS_PLUS256K_FILENAME,    "PLUS256K file" },
/* da */ { IDS_PLUS256K_FILENAME_DA, "PLUS256K-fil" },
/* de */ { IDS_PLUS256K_FILENAME_DE, "PLUS256K Image Name" },
/* es */ { IDS_PLUS256K_FILENAME_ES, "Fichero PLUS256K" },
/* fr */ { IDS_PLUS256K_FILENAME_FR, "Fichier PLUS256K" },
/* hu */ { IDS_PLUS256K_FILENAME_HU, "PLUS256K f�jl" },
/* it */ { IDS_PLUS256K_FILENAME_IT, "File PLUS256K" },
/* ko */ { IDS_PLUS256K_FILENAME_KO, "PLUS256K ����" },
/* nl */ { IDS_PLUS256K_FILENAME_NL, "PLUS256K bestand" },
/* pl */ { IDS_PLUS256K_FILENAME_PL, "Plik PLUS256K" },
/* ru */ { IDS_PLUS256K_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_PLUS256K_FILENAME_SV, "PLUS256K-fil" },
/* tr */ { IDS_PLUS256K_FILENAME_TR, "PLUS256K dosyas�" },

/* en */ { IDS_PLUS256K_FILENAME_SELECT,    "Select file for PLUS256K" },
/* da */ { IDS_PLUS256K_FILENAME_SELECT_DA, "V�lg fil for PLUS256K" },
/* de */ { IDS_PLUS256K_FILENAME_SELECT_DE, "Datei f�r PLUS256K ausw�hlen" },
/* es */ { IDS_PLUS256K_FILENAME_SELECT_ES, "Seleccionar fichero para PLUS256K" },
/* fr */ { IDS_PLUS256K_FILENAME_SELECT_FR, "S�lectionner fichier pour PLUS256K" },
/* hu */ { IDS_PLUS256K_FILENAME_SELECT_HU, "V�lasszon f�jlt a PLUS256K-hoz" },
/* it */ { IDS_PLUS256K_FILENAME_SELECT_IT, "Seleziona file per PLUS256K" },
/* ko */ { IDS_PLUS256K_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_PLUS256K_FILENAME_SELECT_NL, "Selecteer bestand voor PLUS256K" },
/* pl */ { IDS_PLUS256K_FILENAME_SELECT_PL, "Wybierz plik PLUS256K" },
/* ru */ { IDS_PLUS256K_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_PLUS256K_FILENAME_SELECT_SV, "Ange fil f�r PLUS256K" },
/* tr */ { IDS_PLUS256K_FILENAME_SELECT_TR, "PLUS256K i�in dosya se�in" },

/* en */ { IDMS_PLUS256K_SETTINGS,    "PLUS256K settings..." },
/* da */ { IDMS_PLUS256K_SETTINGS_DA, "PLUS256K-indstillinger..." },
/* de */ { IDMS_PLUS256K_SETTINGS_DE, "PLUS256K Einstellungen..." },
/* es */ { IDMS_PLUS256K_SETTINGS_ES, "Ajustes PLUS256K..." },
/* fr */ { IDMS_PLUS256K_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_PLUS256K_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_PLUS256K_SETTINGS_IT, "Impostazioni PLUS256K..." },
/* ko */ { IDMS_PLUS256K_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_PLUS256K_SETTINGS_NL, "PLUS256K instellingen..." },
/* pl */ { IDMS_PLUS256K_SETTINGS_PL, "Ustawienia PLUS256K..." },
/* ru */ { IDMS_PLUS256K_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_PLUS256K_SETTINGS_SV, "PLUS256K-inst�llningar..." },
/* tr */ { IDMS_PLUS256K_SETTINGS_TR, "PLUS256K Ayarlar�..." },

/* en */ { IDMS_256K_SETTINGS,    "256K settings..." },
/* da */ { IDMS_256K_SETTINGS_DA, "256K-indstillinger..." },
/* de */ { IDMS_256K_SETTINGS_DE, "256K Einstellungen..." },
/* es */ { IDMS_256K_SETTINGS_ES, "Ajustes 256K..." },
/* fr */ { IDMS_256K_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_256K_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_256K_SETTINGS_IT, "Impostazioni 256K..." },
/* ko */ { IDMS_256K_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_256K_SETTINGS_NL, "256K instellingen..." },
/* pl */ { IDMS_256K_SETTINGS_PL, "Ustawienia 256K..." },
/* ru */ { IDMS_256K_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_256K_SETTINGS_SV, "256K-inst�llningar..." },
/* tr */ { IDMS_256K_SETTINGS_TR, "256K Ayarlar�..." },

/* en */ { IDMS_IDE64_SETTINGS,    "IDE64 settings..." },
/* da */ { IDMS_IDE64_SETTINGS_DA, "IDE64-indstillinger..." },
/* de */ { IDMS_IDE64_SETTINGS_DE, "IDE64 Einstellungen..." },
/* es */ { IDMS_IDE64_SETTINGS_ES, "Ajustes IDE64..." },
/* fr */ { IDMS_IDE64_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_IDE64_SETTINGS_HU, "IDE64 be�ll�t�sai..." },
/* it */ { IDMS_IDE64_SETTINGS_IT, "Impostazioni IDE64..." },
/* ko */ { IDMS_IDE64_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_IDE64_SETTINGS_NL, "IDE64 instellingen..." },
/* pl */ { IDMS_IDE64_SETTINGS_PL, "Ustawienia IDE64..." },
/* ru */ { IDMS_IDE64_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_IDE64_SETTINGS_SV, "IDE64-inst�llningar..." },
/* tr */ { IDMS_IDE64_SETTINGS_TR, "IDE64 ayarlar�..." },

/* en */ { IDMS_MMC64_SETTINGS,    "MMC64 settings..." },
/* da */ { IDMS_MMC64_SETTINGS_DA, "MMC64-indstillinger..." },
/* de */ { IDMS_MMC64_SETTINGS_DE, "MMC64 Einstellungen..." },
/* es */ { IDMS_MMC64_SETTINGS_ES, "Ajustes MMC64..." },
/* fr */ { IDMS_MMC64_SETTINGS_FR, "Param�tres MMC64......" },
/* hu */ { IDMS_MMC64_SETTINGS_HU, "MMC64 be�ll�t�sai..." },
/* it */ { IDMS_MMC64_SETTINGS_IT, "Impostazioni MMC64..." },
/* ko */ { IDMS_MMC64_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_MMC64_SETTINGS_NL, "MMC64 instellingen..." },
/* pl */ { IDMS_MMC64_SETTINGS_PL, "Ustawienia MMC64..." },
/* ru */ { IDMS_MMC64_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_MMC64_SETTINGS_SV, "MMC64-inst�llningar......" },
/* tr */ { IDMS_MMC64_SETTINGS_TR, "MMC64 ayarlar�..." },

/* en */ { IDMS_MMCREPLAY_SETTINGS,    "MMC Replay settings..." },
/* da */ { IDMS_MMCREPLAY_SETTINGS_DA, "MMC Replay-indstillinger..." },
/* de */ { IDMS_MMCREPLAY_SETTINGS_DE, "MMC Replay Einstellungen..." },
/* es */ { IDMS_MMCREPLAY_SETTINGS_ES, "Ajustes MMC Replay..." },
/* fr */ { IDMS_MMCREPLAY_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_MMCREPLAY_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_MMCREPLAY_SETTINGS_IT, "Impostazioni MMC Replay..." },
/* ko */ { IDMS_MMCREPLAY_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_MMCREPLAY_SETTINGS_NL, "MMC Replay instellingen..." },
/* pl */ { IDMS_MMCREPLAY_SETTINGS_PL, "Ustawienia MMC Replay..." },
/* ru */ { IDMS_MMCREPLAY_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_MMCREPLAY_SETTINGS_SV, "MMC Replay-inst�llningar..." },
/* tr */ { IDMS_MMCREPLAY_SETTINGS_TR, "MMC Replay ayarlar�..." },

/* en */ { IDMS_DIGIMAX_SETTINGS,    "DigiMAX settings..." },
/* da */ { IDMS_DIGIMAX_SETTINGS_DA, "DigiMAX-indstillinger..." },
/* de */ { IDMS_DIGIMAX_SETTINGS_DE, "DigiMAX Einstellungen..." },
/* es */ { IDMS_DIGIMAX_SETTINGS_ES, "Ajustes DigiMAX..." },
/* fr */ { IDMS_DIGIMAX_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_DIGIMAX_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_DIGIMAX_SETTINGS_IT, "Impostazioni DigiMAX..." },
/* ko */ { IDMS_DIGIMAX_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_DIGIMAX_SETTINGS_NL, "DigiMAX instellingen..." },
/* pl */ { IDMS_DIGIMAX_SETTINGS_PL, "Ustawienia DigiMAX..." },
/* ru */ { IDMS_DIGIMAX_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DIGIMAX_SETTINGS_SV, "DigiMAX-inst�llningar..." },
/* tr */ { IDMS_DIGIMAX_SETTINGS_TR, "DigiMAX ayarlar�..." },

/* en */ { IDMS_DIGIMAX_SETTINGS_MASCUERADE,    "DigiMAX settings (MasC=uerade)..." },
/* da */ { IDMS_DIGIMAX_SETTINGS_MASCUERADE_DA, "DigiMAX-indstillinger (MasC=uerade)..." },
/* de */ { IDMS_DIGIMAX_SETTINGS_MASCUERADE_DE, "DigiMAX Einstellungen (MasC=uerade)..." },
/* es */ { IDMS_DIGIMAX_SETTINGS_MASCUERADE_ES, "Ajustes DigiMAX (MasC=uerade)..." },
/* fr */ { IDMS_DIGIMAX_SETTINGS_MASCUERADE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_DIGIMAX_SETTINGS_MASCUERADE_HU, "" },  /* fuzzy */
/* it */ { IDMS_DIGIMAX_SETTINGS_MASCUERADE_IT, "Impostazioni DigiMAX (MasC=uerade)..." },
/* ko */ { IDMS_DIGIMAX_SETTINGS_MASCUERADE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_DIGIMAX_SETTINGS_MASCUERADE_NL, "DigiMAX instellingen (MasC=uerade)..." },
/* pl */ { IDMS_DIGIMAX_SETTINGS_MASCUERADE_PL, "Ustawienia DigiMAX (MasC=uerade)..." },
/* ru */ { IDMS_DIGIMAX_SETTINGS_MASCUERADE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DIGIMAX_SETTINGS_MASCUERADE_SV, "DigiMAX-inst�llningar (MasC=uerade)..." },
/* tr */ { IDMS_DIGIMAX_SETTINGS_MASCUERADE_TR, "DigiMAX ayarlar� (MasC=uerade)..." },

/* en */ { IDMS_SFX_SE_SETTINGS,    "SFX Sound Expander settings..." },
/* da */ { IDMS_SFX_SE_SETTINGS_DA, "SFX Sound Expander-indstillinger..." },
/* de */ { IDMS_SFX_SE_SETTINGS_DE, "SFX Sound Expander Einstellungen..." },
/* es */ { IDMS_SFX_SE_SETTINGS_ES, "Ajustes SFX Sound Expander..." },
/* fr */ { IDMS_SFX_SE_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_SFX_SE_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_SFX_SE_SETTINGS_IT, "Impostazioni SFX Sound Expander..." },
/* ko */ { IDMS_SFX_SE_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SFX_SE_SETTINGS_NL, "SFX Sound Expander instellingen..." },
/* pl */ { IDMS_SFX_SE_SETTINGS_PL, "Ustawienia SFX Sound Expander..." },
/* ru */ { IDMS_SFX_SE_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SFX_SE_SETTINGS_SV, "Inst�llningar f�r SFX Sound Expander..." },
/* tr */ { IDMS_SFX_SE_SETTINGS_TR, "SFX Sound Expander Ayarlar�..." },

/* en */ { IDMS_SFX_SE_SETTINGS_MASCUERADE,    "SFX Sound Expander settings (MasC=uerade)..." },
/* da */ { IDMS_SFX_SE_SETTINGS_MASCUERADE_DA, "SFX Sound Expander-indstillinger (MasC=uerade)..." },
/* de */ { IDMS_SFX_SE_SETTINGS_MASCUERADE_DE, "SFX Sound Expander Einstellungen (MasC=uerade)..." },
/* es */ { IDMS_SFX_SE_SETTINGS_MASCUERADE_ES, "Ajustes SFX Sound Expander (MasC=uerade)..." },
/* fr */ { IDMS_SFX_SE_SETTINGS_MASCUERADE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_SFX_SE_SETTINGS_MASCUERADE_HU, "" },  /* fuzzy */
/* it */ { IDMS_SFX_SE_SETTINGS_MASCUERADE_IT, "Impostazioni SFX Sound Expander (MasC=uerade)..." },
/* ko */ { IDMS_SFX_SE_SETTINGS_MASCUERADE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SFX_SE_SETTINGS_MASCUERADE_NL, "SFX Sound Expander instellingen (MasC=uerade)..." },
/* pl */ { IDMS_SFX_SE_SETTINGS_MASCUERADE_PL, "Ustawienia SFX Sound Expander (MasC=uerade)..." },
/* ru */ { IDMS_SFX_SE_SETTINGS_MASCUERADE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SFX_SE_SETTINGS_MASCUERADE_SV, "Inst�llningar f�r SFX Sound Expander (MasC=uerade)..." },
/* tr */ { IDMS_SFX_SE_SETTINGS_MASCUERADE_TR, "SFX Sound Expander Ayarlar� (MasC=uerade)..." },

/* en */ { IDMS_SFX_SS_SETTINGS_MASCUERADE,    "SFX Sound Sampler settings (MasC=uerade)..." },
/* da */ { IDMS_SFX_SS_SETTINGS_MASCUERADE_DA, "" },  /* fuzzy */
/* de */ { IDMS_SFX_SS_SETTINGS_MASCUERADE_DE, "SFX Sound Sampler Einstellungen (MasC=uerade)..." },
/* es */ { IDMS_SFX_SS_SETTINGS_MASCUERADE_ES, "Ajustes SFX Sound Sampler (MasC=uerade)..." },
/* fr */ { IDMS_SFX_SS_SETTINGS_MASCUERADE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_SFX_SS_SETTINGS_MASCUERADE_HU, "" },  /* fuzzy */
/* it */ { IDMS_SFX_SS_SETTINGS_MASCUERADE_IT, "" },  /* fuzzy */
/* ko */ { IDMS_SFX_SS_SETTINGS_MASCUERADE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SFX_SS_SETTINGS_MASCUERADE_NL, "SFX Sound Sampler instellingen (MasC=uerade)..." },
/* pl */ { IDMS_SFX_SS_SETTINGS_MASCUERADE_PL, "Ustawienia samplera d�wi�ku SFX (MasC=uerade)..." },
/* ru */ { IDMS_SFX_SS_SETTINGS_MASCUERADE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SFX_SS_SETTINGS_MASCUERADE_SV, "" },  /* fuzzy */
/* tr */ { IDMS_SFX_SS_SETTINGS_MASCUERADE_TR, "" },  /* fuzzy */

/* en */ { IDMS_EASYFLASH_SETTINGS,    "EasyFlash settings..." },
/* da */ { IDMS_EASYFLASH_SETTINGS_DA, "EasyFlash-indstillinger..." },
/* de */ { IDMS_EASYFLASH_SETTINGS_DE, "EasyFlash Einstellungen..." },
/* es */ { IDMS_EASYFLASH_SETTINGS_ES, "Ajuestes EasyFlash..." },
/* fr */ { IDMS_EASYFLASH_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_EASYFLASH_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_EASYFLASH_SETTINGS_IT, "Impostazioni EasyFlash..." },
/* ko */ { IDMS_EASYFLASH_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_EASYFLASH_SETTINGS_NL, "EasyFlash instellingen..." },
/* pl */ { IDMS_EASYFLASH_SETTINGS_PL, "Ustawienia EasyFlash..." },
/* ru */ { IDMS_EASYFLASH_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_EASYFLASH_SETTINGS_SV, "EasyFlash-inst�llningar..." },
/* tr */ { IDMS_EASYFLASH_SETTINGS_TR, "EasyFlash ayarlar�..." },

/* en */ { IDMS_ENABLE_SFX_SS,    "Enable the SFX Sound Sampler cartridge" },
/* da */ { IDMS_ENABLE_SFX_SS_DA, "Aktiv�r SFX Sound Sampler cartridge" },
/* de */ { IDMS_ENABLE_SFX_SS_DE, "SFX Sound Sampler Modul aktivieren" },
/* es */ { IDMS_ENABLE_SFX_SS_ES, "Permitir cartucho SFX Sound Sampler" },
/* fr */ { IDMS_ENABLE_SFX_SS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ENABLE_SFX_SS_HU, "SFX Sound Sampler enged�lyez�se" },
/* it */ { IDMS_ENABLE_SFX_SS_IT, "Attiva cartuccia SFX Sound Sampler" },
/* ko */ { IDMS_ENABLE_SFX_SS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_ENABLE_SFX_SS_NL, "Activeer de SFX Sound Sampler cartridge" },
/* pl */ { IDMS_ENABLE_SFX_SS_PL, "W��cz kartrid� SFX Sound Sampler" },
/* ru */ { IDMS_ENABLE_SFX_SS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ENABLE_SFX_SS_SV, "Aktivera SFX Sound Sampler-insticksmodul" },
/* tr */ { IDMS_ENABLE_SFX_SS_TR, "SFX Sound Sampler kartu�unu aktif et" },

/* en */ { IDMS_ENABLE_USERPORT_DAC,    "Enable Userport DAC for sound output" },
/* da */ { IDMS_ENABLE_USERPORT_DAC_DA, "Aktiv�r brugerport DAC for lydoutput" },
/* de */ { IDMS_ENABLE_USERPORT_DAC_DE, "Userport DAC Sound aktivieren" },
/* es */ { IDMS_ENABLE_USERPORT_DAC_ES, "Permitir puerto DAC para salida de sonido" },
/* fr */ { IDMS_ENABLE_USERPORT_DAC_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ENABLE_USERPORT_DAC_HU, "" },  /* fuzzy */
/* it */ { IDMS_ENABLE_USERPORT_DAC_IT, "Attiva DAC su userport per la riproduzione audio" },
/* ko */ { IDMS_ENABLE_USERPORT_DAC_KO, "" },  /* fuzzy */
/* nl */ { IDMS_ENABLE_USERPORT_DAC_NL, "Activeer userport DAC voor geluidsuitvoer" },
/* pl */ { IDMS_ENABLE_USERPORT_DAC_PL, "W��cz userport DAC jako wyj�cie d�wi�ku" },
/* ru */ { IDMS_ENABLE_USERPORT_DAC_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ENABLE_USERPORT_DAC_SV, "Aktivera D/A-omvandlare p� anv�ndarporten f�r ljudutdata" },
/* tr */ { IDMS_ENABLE_USERPORT_DAC_TR, "Ses ��k��� i�in Userport DAC'� aktif et" },

/* en */ { IDMS_ETHERNET_SETTINGS,    "Ethernet settings..." },
/* da */ { IDMS_ETHERNET_SETTINGS_DA, "Ethernetindstillinger..." },
/* de */ { IDMS_ETHERNET_SETTINGS_DE, "Ethernet Einstellungen..." },
/* es */ { IDMS_ETHERNET_SETTINGS_ES, "Ajustes Ethernet..." },
/* fr */ { IDMS_ETHERNET_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ETHERNET_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_ETHERNET_SETTINGS_IT, "Impostazioni Ethernet..." },
/* ko */ { IDMS_ETHERNET_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_ETHERNET_SETTINGS_NL, "Ethernet instellingen..." },
/* pl */ { IDMS_ETHERNET_SETTINGS_PL, "Ustawienia Ethernet..." },
/* ru */ { IDMS_ETHERNET_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ETHERNET_SETTINGS_SV, "Ethernetinst�llningar..." },
/* tr */ { IDMS_ETHERNET_SETTINGS_TR, "Ethernet Ayarlar�..." },

/* en */ { IDMS_ACIA_SETTINGS,    "ACIA settings..." },
/* da */ { IDMS_ACIA_SETTINGS_DA, "ACIA-indstillinger..." },
/* de */ { IDMS_ACIA_SETTINGS_DE, "ACIA Einstellungen..." },
/* es */ { IDMS_ACIA_SETTINGS_ES, "Ajustes ACIA..." },
/* fr */ { IDMS_ACIA_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ACIA_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_ACIA_SETTINGS_IT, "Impostazioni ACIA..." },
/* ko */ { IDMS_ACIA_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_ACIA_SETTINGS_NL, "ACIA instellingen..." },
/* pl */ { IDMS_ACIA_SETTINGS_PL, "Ustawienia ACIA..." },
/* ru */ { IDMS_ACIA_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ACIA_SETTINGS_SV, "ACIA-inst�llningar..." },
/* tr */ { IDMS_ACIA_SETTINGS_TR, "ACIA Ayarlar�..." },

/* en */ { IDMS_ACIA_SETTINGS_MASCUERADE,    "ACIA settings (MasC=uerade)..." },
/* da */ { IDMS_ACIA_SETTINGS_MASCUERADE_DA, "ACIA-indstillinger (MasC=uerade)..." },
/* de */ { IDMS_ACIA_SETTINGS_MASCUERADE_DE, "ACIA Einstellungen (MasC=uerade)..." },
/* es */ { IDMS_ACIA_SETTINGS_MASCUERADE_ES, "Ajustes ACIA (MasC=uerade)..." },
/* fr */ { IDMS_ACIA_SETTINGS_MASCUERADE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ACIA_SETTINGS_MASCUERADE_HU, "" },  /* fuzzy */
/* it */ { IDMS_ACIA_SETTINGS_MASCUERADE_IT, "Impostazioni ACIA (MasC=uerade)..." },
/* ko */ { IDMS_ACIA_SETTINGS_MASCUERADE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_ACIA_SETTINGS_MASCUERADE_NL, "ACIA instellingen (MasC=uerade)..." },
/* pl */ { IDMS_ACIA_SETTINGS_MASCUERADE_PL, "Ustawienia ACIA (MasC=uerade)..." },
/* ru */ { IDMS_ACIA_SETTINGS_MASCUERADE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ACIA_SETTINGS_MASCUERADE_SV, "ACIA-inst�llningar (MasC=uerade)..." },
/* tr */ { IDMS_ACIA_SETTINGS_MASCUERADE_TR, "ACIA Ayarlar� (MasC=uerade)..." },

/* en */ { IDMS_PETREU_SETTINGS,    "PET REU settings..." },
/* da */ { IDMS_PETREU_SETTINGS_DA, "PET REU-indstillinger..." },
/* de */ { IDMS_PETREU_SETTINGS_DE, "PET REU Einstellungen..." },
/* es */ { IDMS_PETREU_SETTINGS_ES, "Ajustes PET REU..." },
/* fr */ { IDMS_PETREU_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_PETREU_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_PETREU_SETTINGS_IT, "Impostazioni PET REU..." },
/* ko */ { IDMS_PETREU_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_PETREU_SETTINGS_NL, "PET REU instellingen..." },
/* pl */ { IDMS_PETREU_SETTINGS_PL, "Ustawienia PET REU..." },
/* ru */ { IDMS_PETREU_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_PETREU_SETTINGS_SV, "PET REU-Inst�llningar..." },
/* tr */ { IDMS_PETREU_SETTINGS_TR, "PET REU Ayarlar�..." },

/* en */ { IDMS_V364_SPEECH_SETTINGS,    "V364 Speech settings..." },
/* da */ { IDMS_V364_SPEECH_SETTINGS_DA, "V364 tale-indstillinger..." },
/* de */ { IDMS_V364_SPEECH_SETTINGS_DE, "V364 Stimme Einstellungen..." },
/* es */ { IDMS_V364_SPEECH_SETTINGS_ES, "Ajustes V364 Speech..." },
/* fr */ { IDMS_V364_SPEECH_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_V364_SPEECH_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_V364_SPEECH_SETTINGS_IT, "Impostazioni V364 Speech..." },
/* ko */ { IDMS_V364_SPEECH_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_V364_SPEECH_SETTINGS_NL, "V364 Spraak instellingen..." },
/* pl */ { IDMS_V364_SPEECH_SETTINGS_PL, "Ustawienia mowy V364..." },
/* ru */ { IDMS_V364_SPEECH_SETTINGS_RU, "��������� ���� V364..." },
/* sv */ { IDMS_V364_SPEECH_SETTINGS_SV, "V364-r�stinst�llningar..." },
/* tr */ { IDMS_V364_SPEECH_SETTINGS_TR, "V364 Speech ayarlar�..." },

/* en */ { IDMS_SIDCART_SETTINGS,    "SID cart settings..." },
/* da */ { IDMS_SIDCART_SETTINGS_DA, "SID-cartridgeindstillinger..." },
/* de */ { IDMS_SIDCART_SETTINGS_DE, "SID Modul Einstellungen..." },
/* es */ { IDMS_SIDCART_SETTINGS_ES, "Ajustes SID Cart..." },
/* fr */ { IDMS_SIDCART_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_SIDCART_SETTINGS_HU, "SID k�rtya be�ll�t�sai......" },
/* it */ { IDMS_SIDCART_SETTINGS_IT, "Impostazioni cartuccia SID..." },
/* ko */ { IDMS_SIDCART_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SIDCART_SETTINGS_NL, "SID cart instellingen..." },
/* pl */ { IDMS_SIDCART_SETTINGS_PL, "Ustawienia karty SID..." },
/* ru */ { IDMS_SIDCART_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SIDCART_SETTINGS_SV, "SID-modulinst�llningarg..." },
/* tr */ { IDMS_SIDCART_SETTINGS_TR, "SID kartu�u ayarlar�..." },

/* en */ { IDMS_PETDWW_SETTINGS,    "PET DWW settings..." },
/* da */ { IDMS_PETDWW_SETTINGS_DA, "PET DWW-indstillinger..." },
/* de */ { IDMS_PETDWW_SETTINGS_DE, "PET DWW Einstellungen..." },
/* es */ { IDMS_PETDWW_SETTINGS_ES, "Ajustes PET DWW..." },
/* fr */ { IDMS_PETDWW_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_PETDWW_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_PETDWW_SETTINGS_IT, "Impostazioni PET DWW..." },
/* ko */ { IDMS_PETDWW_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_PETDWW_SETTINGS_NL, "PET DWW instellingen..." },
/* pl */ { IDMS_PETDWW_SETTINGS_PL, "Ustawienia PET DWW..." },
/* ru */ { IDMS_PETDWW_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_PETDWW_SETTINGS_SV, "PET DWW-Inst�llningar..." },
/* tr */ { IDMS_PETDWW_SETTINGS_TR, "PET DWW Ayarlar�..." },

/* en */ { IDMS_FINAL_EXPANSION_WRITEBACK,    "Enable Final Expansion write back to ROM file" },
/* da */ { IDMS_FINAL_EXPANSION_WRITEBACK_DA, "Aktiv�r Final Expansion tilbageskrivning til ROM-fil" },
/* de */ { IDMS_FINAL_EXPANSION_WRITEBACK_DE, "Final Expansion ROM Schreibzugriff aktivieren" },
/* es */ { IDMS_FINAL_EXPANSION_WRITEBACK_ES, "Permitir grabaci�n en fichero ROM Final Expansion" },
/* fr */ { IDMS_FINAL_EXPANSION_WRITEBACK_FR, "" },  /* fuzzy */
/* hu */ { IDMS_FINAL_EXPANSION_WRITEBACK_HU, "Final Expansion ROM f�jlba vissza�r�s enged�lyez�se" },
/* it */ { IDMS_FINAL_EXPANSION_WRITEBACK_IT, "Attiva write back per Final Expansion su file ROM" },
/* ko */ { IDMS_FINAL_EXPANSION_WRITEBACK_KO, "" },  /* fuzzy */
/* nl */ { IDMS_FINAL_EXPANSION_WRITEBACK_NL, "Activeer terug schrijven naar ROM bestand voor Final Expansion" },
/* pl */ { IDMS_FINAL_EXPANSION_WRITEBACK_PL, "W��cz zapis do pliku ROM Final Expansion" },
/* ru */ { IDMS_FINAL_EXPANSION_WRITEBACK_RU, "" },  /* fuzzy */
/* sv */ { IDMS_FINAL_EXPANSION_WRITEBACK_SV, "Aktivera �terskrivning till ROM-fil f�r Final Expansion" },
/* tr */ { IDMS_FINAL_EXPANSION_WRITEBACK_TR, "Final Expansion ROM dosyas�na geri yazmay� aktif et" },

/* en */ { IDMS_FP_WRITEBACK,    "Enable Vic Flash Plugin write back to ROM file" },
/* da */ { IDMS_FP_WRITEBACK_DA, "Aktiv�r Vic Flash Plugin tilbageskrivning til ROM-fil" },
/* de */ { IDMS_FP_WRITEBACK_DE, "Vic Flash Plugin R�ckschreiben auf ROM Datei aktivieren" },
/* es */ { IDMS_FP_WRITEBACK_ES, "Permitir grabacion en ROM Vic Flash Plugin" },
/* fr */ { IDMS_FP_WRITEBACK_FR, "" },  /* fuzzy */
/* hu */ { IDMS_FP_WRITEBACK_HU, "" },  /* fuzzy */
/* it */ { IDMS_FP_WRITEBACK_IT, "Attiva write back per Vic Flash Plugin su file ROM" },
/* ko */ { IDMS_FP_WRITEBACK_KO, "" },  /* fuzzy */
/* nl */ { IDMS_FP_WRITEBACK_NL, "Activeer terug schrijven naar ROM bestand voor Vic Flash Plugin" },
/* pl */ { IDMS_FP_WRITEBACK_PL, "W��cz zapis do pliku ROM Vic Flash Plugin" },
/* ru */ { IDMS_FP_WRITEBACK_RU, "" },  /* fuzzy */
/* sv */ { IDMS_FP_WRITEBACK_SV, "Aktivera �terskrivning till ROM-fil f�r Vic Flash-insticksmodul" },
/* tr */ { IDMS_FP_WRITEBACK_TR, "Flash Plugin ROM dosyas�na geri yazmay� aktif et" },

/* en */ { IDMS_MEGACART_WRITEBACK,    "Enable Mega-Cart NvRAM writeback" },
/* da */ { IDMS_MEGACART_WRITEBACK_DA, "Aktiv�r Mega-Cart NvRAM tilbageskrivning" },
/* de */ { IDMS_MEGACART_WRITEBACK_DE, "Mega-Cart NvRAM R�ckschreiben aktivieren" },
/* es */ { IDMS_MEGACART_WRITEBACK_ES, "Permitir respuesta Mega-Cart NvRAM" },
/* fr */ { IDMS_MEGACART_WRITEBACK_FR, "" },  /* fuzzy */
/* hu */ { IDMS_MEGACART_WRITEBACK_HU, "" },  /* fuzzy */
/* it */ { IDMS_MEGACART_WRITEBACK_IT, "Write back NvRAM Mega-Cart" },
/* ko */ { IDMS_MEGACART_WRITEBACK_KO, "" },  /* fuzzy */
/* nl */ { IDMS_MEGACART_WRITEBACK_NL, "Activeer Mega-Cart NvRAM terug schrijven" },
/* pl */ { IDMS_MEGACART_WRITEBACK_PL, "W��cz zapis do NvRAM Mega-Cart" },
/* ru */ { IDMS_MEGACART_WRITEBACK_RU, "" },  /* fuzzy */
/* sv */ { IDMS_MEGACART_WRITEBACK_SV, "Aktivera Mega-Cart NvRAM-�terskrivning" },
/* tr */ { IDMS_MEGACART_WRITEBACK_TR, "Mega-Cart NvRAM geri yazmay� aktif et" },

/* en */ { IDMS_MEGACART_WRITEBACK_FILE,    "Select Mega-Cart non-volatile RAM file" },
/* da */ { IDMS_MEGACART_WRITEBACK_FILE_DA, "V�lg Mega-Cart NVRAM-fil" },
/* de */ { IDMS_MEGACART_WRITEBACK_FILE_DE, "Mega-Cart nicht-fl�chtiges RAM Datei w�hlen" },
/* es */ { IDMS_MEGACART_WRITEBACK_FILE_ES, "Seleccionar fichero RAM Mega-Cart no volatil" },
/* fr */ { IDMS_MEGACART_WRITEBACK_FILE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_MEGACART_WRITEBACK_FILE_HU, "V�lassza ki az NvRAM k�pf�jlt" },
/* it */ { IDMS_MEGACART_WRITEBACK_FILE_IT, "Seleziona file non-volatile RAM Mega-Cart" },
/* ko */ { IDMS_MEGACART_WRITEBACK_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_MEGACART_WRITEBACK_FILE_NL, "Selecteer Mega-Cart non-volatile RAM bestand" },
/* pl */ { IDMS_MEGACART_WRITEBACK_FILE_PL, "Wybierz sta�y plik RAM Mega-Cart" },
/* ru */ { IDMS_MEGACART_WRITEBACK_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_MEGACART_WRITEBACK_FILE_SV, "V�lj NvRAM-fil f�r Mega-Cart" },
/* tr */ { IDMS_MEGACART_WRITEBACK_FILE_TR, "Mega-Cart non-volatile RAM dosyas�n� se�" },

/* en */ { IDMS_C64DTV_SETTINGS,    "C64DTV settings..." },
/* da */ { IDMS_C64DTV_SETTINGS_DA, "C64DTV-indstillinger..." },
/* de */ { IDMS_C64DTV_SETTINGS_DE, "C64DTV Einstellungen..." },
/* es */ { IDMS_C64DTV_SETTINGS_ES, "Ajustes C64DTV..." },
/* fr */ { IDMS_C64DTV_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_C64DTV_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_C64DTV_SETTINGS_IT, "Impostazioni C64DTV..." },
/* ko */ { IDMS_C64DTV_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_C64DTV_SETTINGS_NL, "C64DTV Instellingen..." },
/* pl */ { IDMS_C64DTV_SETTINGS_PL, "Ustawienia C64DTV..." },
/* ru */ { IDMS_C64DTV_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_C64DTV_SETTINGS_SV, "C64DTV-inst�llningar..." },
/* tr */ { IDMS_C64DTV_SETTINGS_TR, "C64DTV Ayarlar�..." },

/* en */ { IDMS_RS232_USERPORT_SETTINGS,    "RS232 userport settings..." },
/* da */ { IDMS_RS232_USERPORT_SETTINGS_DA, "RS232-brugerportindstillinger..." },
/* de */ { IDMS_RS232_USERPORT_SETTINGS_DE, "RS232 Userport Einstellungen..." },
/* es */ { IDMS_RS232_USERPORT_SETTINGS_ES, "Ajustes puerto RS232..." },
/* fr */ { IDMS_RS232_USERPORT_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDMS_RS232_USERPORT_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDMS_RS232_USERPORT_SETTINGS_IT, "Impostazioni RS232 su userport..." },
/* ko */ { IDMS_RS232_USERPORT_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_RS232_USERPORT_SETTINGS_NL, "RS232 userport instellingen..." },
/* pl */ { IDMS_RS232_USERPORT_SETTINGS_PL, "Ustawienia userportu RS232..." },
/* ru */ { IDMS_RS232_USERPORT_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_RS232_USERPORT_SETTINGS_SV, "RS232-anv�ndarportinst�llningar..." },
/* tr */ { IDMS_RS232_USERPORT_SETTINGS_TR, "RS232 userport ayarlar�..." },

/* en */ { IDMS_SAVE_CURRENT_SETTINGS_FILE,    "Save current settings to specified file" },
/* da */ { IDMS_SAVE_CURRENT_SETTINGS_FILE_DA, "Gem indstillinger som" },
/* de */ { IDMS_SAVE_CURRENT_SETTINGS_FILE_DE, "Speichere Einstellungen in angegebene Datei" },
/* es */ { IDMS_SAVE_CURRENT_SETTINGS_FILE_ES, "Grabar ajustes actuales en el fichero especificado" },
/* fr */ { IDMS_SAVE_CURRENT_SETTINGS_FILE_FR, "Enregistrer les param�tres courants" },
/* hu */ { IDMS_SAVE_CURRENT_SETTINGS_FILE_HU, "Jelenlegi be�ll�t�sok ment�se adott f�jlba" },
/* it */ { IDMS_SAVE_CURRENT_SETTINGS_FILE_IT, "Salva impostazioni attuali sul file specificato" },
/* ko */ { IDMS_SAVE_CURRENT_SETTINGS_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SAVE_CURRENT_SETTINGS_FILE_NL, "Huidige instellingen opslaan naar opgegeven bestand" },
/* pl */ { IDMS_SAVE_CURRENT_SETTINGS_FILE_PL, "Zapisz obecne ustawienia do danego pliku" },
/* ru */ { IDMS_SAVE_CURRENT_SETTINGS_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SAVE_CURRENT_SETTINGS_FILE_SV, "Spara nuvarande inst�llningar till den angivna filen" },
/* tr */ { IDMS_SAVE_CURRENT_SETTINGS_FILE_TR, "Belirtilen dosyaya ge�erli ayarlar� kaydet" },

/* en */ { IDMS_LOAD_SAVED_SETTINGS_FILE,    "Load settings from specified file" },
/* da */ { IDMS_LOAD_SAVED_SETTINGS_FILE_DA, "Indl�s indstillinger fra" },
/* de */ { IDMS_LOAD_SAVED_SETTINGS_FILE_DE, "Lade Einstellungen aus Datei" },
/* es */ { IDMS_LOAD_SAVED_SETTINGS_FILE_ES, "Cargar ajustes desde el fichero especificado" },
/* fr */ { IDMS_LOAD_SAVED_SETTINGS_FILE_FR, "" },  /* fuzzy */
/* hu */ { IDMS_LOAD_SAVED_SETTINGS_FILE_HU, "Be�ll�t�sok bet�lt�se a megadott f�jlb�l" },
/* it */ { IDMS_LOAD_SAVED_SETTINGS_FILE_IT, "Carica impostazioni dal file specificato" },
/* ko */ { IDMS_LOAD_SAVED_SETTINGS_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDMS_LOAD_SAVED_SETTINGS_FILE_NL, "Instellingen laden van opgegeven bestand" },
/* pl */ { IDMS_LOAD_SAVED_SETTINGS_FILE_PL, "Wczytaj ustawienia z danego plku" },
/* ru */ { IDMS_LOAD_SAVED_SETTINGS_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LOAD_SAVED_SETTINGS_FILE_SV, "L�s inst�llningar fr�n den angivna filen" },
/* tr */ { IDMS_LOAD_SAVED_SETTINGS_FILE_TR, "Belirtilen dosyadan ayarlar� y�kle" },

/* en */ { IDMS_SAVE_CURRENT_SETTINGS,    "Save current settings" },
/* da */ { IDMS_SAVE_CURRENT_SETTINGS_DA, "Gen aktuelle indstillinger" },
/* de */ { IDMS_SAVE_CURRENT_SETTINGS_DE, "Einstellungen speichern" },
/* es */ { IDMS_SAVE_CURRENT_SETTINGS_ES, "Grabar ajustes actuales" },
/* fr */ { IDMS_SAVE_CURRENT_SETTINGS_FR, "Enregistrer les param�tres courants" },
/* hu */ { IDMS_SAVE_CURRENT_SETTINGS_HU, "Jelenlegi be�ll�t�sok ment�se" },
/* it */ { IDMS_SAVE_CURRENT_SETTINGS_IT, "Salva impostazioni attuali" },
/* ko */ { IDMS_SAVE_CURRENT_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SAVE_CURRENT_SETTINGS_NL, "Huidige instellingen opslaan" },
/* pl */ { IDMS_SAVE_CURRENT_SETTINGS_PL, "Zapisz obecne ustawienia" },
/* ru */ { IDMS_SAVE_CURRENT_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SAVE_CURRENT_SETTINGS_SV, "Spara nuvarande inst�llningar" },
/* tr */ { IDMS_SAVE_CURRENT_SETTINGS_TR, "Ge�erli ayarlar� kaydet" },

/* en */ { IDMS_LOAD_SAVED_SETTINGS,    "Load saved settings" },
/* da */ { IDMS_LOAD_SAVED_SETTINGS_DA, "Indl�s gemte indstillinger" },
/* de */ { IDMS_LOAD_SAVED_SETTINGS_DE, "Gespeicherte Einstellungen Laden" },
/* es */ { IDMS_LOAD_SAVED_SETTINGS_ES, "Cargar ajustes grabados" },
/* fr */ { IDMS_LOAD_SAVED_SETTINGS_FR, "Charger les param�tres" },
/* hu */ { IDMS_LOAD_SAVED_SETTINGS_HU, "Be�ll�t�sok bet�lt�se" },
/* it */ { IDMS_LOAD_SAVED_SETTINGS_IT, "Carica impostazioni salvate" },
/* ko */ { IDMS_LOAD_SAVED_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_LOAD_SAVED_SETTINGS_NL, "Opgeslagen instellingen laden" },
/* pl */ { IDMS_LOAD_SAVED_SETTINGS_PL, "Wczytaj zapisane ustawienia" },
/* ru */ { IDMS_LOAD_SAVED_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LOAD_SAVED_SETTINGS_SV, "L�s sparade inst�llningar" },
/* tr */ { IDMS_LOAD_SAVED_SETTINGS_TR, "Kaydedilmi� ayarlar� y�kle" },

/* en */ { IDMS_SET_DEFAULT_SETTINGS,    "Set default settings" },
/* da */ { IDMS_SET_DEFAULT_SETTINGS_DA, "Gendan standard indstillinger" },
/* de */ { IDMS_SET_DEFAULT_SETTINGS_DE, "Standard Einstellungen wiederherstellen" },
/* es */ { IDMS_SET_DEFAULT_SETTINGS_ES, "Usar ajustes por defecto" },
/* fr */ { IDMS_SET_DEFAULT_SETTINGS_FR, "R�tablir les param�tres par d�faut" },
/* hu */ { IDMS_SET_DEFAULT_SETTINGS_HU, "Alap�rtelmez�s be�ll�t�sa" },
/* it */ { IDMS_SET_DEFAULT_SETTINGS_IT, "Ripristina impostazioni originarie" },
/* ko */ { IDMS_SET_DEFAULT_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMS_SET_DEFAULT_SETTINGS_NL, "Herstel standaard instellingen" },
/* pl */ { IDMS_SET_DEFAULT_SETTINGS_PL, "Ustaw domy�lne ustawienia" },
/* ru */ { IDMS_SET_DEFAULT_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SET_DEFAULT_SETTINGS_SV, "�terst�ll f�rvalda inst�llningar" },
/* tr */ { IDMS_SET_DEFAULT_SETTINGS_TR, "Mevcut ayarlar� varsay�lan olarak kaydet" },

/* en */ { IDMS_SAVE_SETTING_ON_EXIT,    "Save settings on exit" },
/* da */ { IDMS_SAVE_SETTING_ON_EXIT_DA, "Gem indstillinger n�r programmet afsluttes" },
/* de */ { IDMS_SAVE_SETTING_ON_EXIT_DE, "Einstellungen beim Beenden speichern" },
/* es */ { IDMS_SAVE_SETTING_ON_EXIT_ES, "Grabar ajustes al salir" },
/* fr */ { IDMS_SAVE_SETTING_ON_EXIT_FR, "" },  /* fuzzy */
/* hu */ { IDMS_SAVE_SETTING_ON_EXIT_HU, "Be�ll�t�sok ment�se kil�p�skor" },
/* it */ { IDMS_SAVE_SETTING_ON_EXIT_IT, "Salva impostazioni in uscita" },
/* ko */ { IDMS_SAVE_SETTING_ON_EXIT_KO, "����� ���� �����ϱ�" },
/* nl */ { IDMS_SAVE_SETTING_ON_EXIT_NL, "Sla instellingen op bij afsluiten" },
/* pl */ { IDMS_SAVE_SETTING_ON_EXIT_PL, "Zapisz ustawienia przy wyj�ciu" },
/* ru */ { IDMS_SAVE_SETTING_ON_EXIT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_SAVE_SETTING_ON_EXIT_SV, "Spara inst�llningar vid avslut" },
/* tr */ { IDMS_SAVE_SETTING_ON_EXIT_TR, "��k��ta ayarlar� kaydet" },

/* en */ { IDMS_CONFIRM_ON_EXIT,    "Confirm quiting VICE" },
/* da */ { IDMS_CONFIRM_ON_EXIT_DA, "Bekr�ft programafslutning" },
/* de */ { IDMS_CONFIRM_ON_EXIT_DE, "Best�tige beenden von VICE" },
/* es */ { IDMS_CONFIRM_ON_EXIT_ES, "Confirmar el cierre de VICE" },
/* fr */ { IDMS_CONFIRM_ON_EXIT_FR, "Demander une confirmation avant de quitter VICE" },
/* hu */ { IDMS_CONFIRM_ON_EXIT_HU, "Meger�s�t�s kil�p�s el�tt" },
/* it */ { IDMS_CONFIRM_ON_EXIT_IT, "Conferma l'uscita da VICE" },
/* ko */ { IDMS_CONFIRM_ON_EXIT_KO, "VICE Ȯ�� ����" },
/* nl */ { IDMS_CONFIRM_ON_EXIT_NL, "Bevestigen van het aflsuiten van VICE" },
/* pl */ { IDMS_CONFIRM_ON_EXIT_PL, "Potwierdzaj zamkni�cie VICE" },
/* ru */ { IDMS_CONFIRM_ON_EXIT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_CONFIRM_ON_EXIT_SV, "Bekr�fta f�r att avsluta VICE" },
/* tr */ { IDMS_CONFIRM_ON_EXIT_TR, "VICE'dan ��karken teyit et" },

/* en */ { IDMS_HELP,    "Help" },
/* da */ { IDMS_HELP_DA, "Hj�lp" },
/* de */ { IDMS_HELP_DE, "Hilfe" },
/* es */ { IDMS_HELP_ES, "Ayuda" },
/* fr */ { IDMS_HELP_FR, "Aide" },
/* hu */ { IDMS_HELP_HU, "Seg�ts�g" },
/* it */ { IDMS_HELP_IT, "Aiuto" },
/* ko */ { IDMS_HELP_KO, "����" },
/* nl */ { IDMS_HELP_NL, "Help" },
/* pl */ { IDMS_HELP_PL, "Pomoc" },
/* ru */ { IDMS_HELP_RU, "" },  /* fuzzy */
/* sv */ { IDMS_HELP_SV, "Hj�lp" },
/* tr */ { IDMS_HELP_TR, "Yard�m" },

/* en */ { IDMS_ABOUT,    "About VICE..." },
/* da */ { IDMS_ABOUT_DA, "Om VICE..." },
/* de */ { IDMS_ABOUT_DE, "�ber VICE..." },
/* es */ { IDMS_ABOUT_ES, "Acerca de VICE..." },
/* fr */ { IDMS_ABOUT_FR, "" },  /* fuzzy */
/* hu */ { IDMS_ABOUT_HU, "A VICE n�vjegye..." },
/* it */ { IDMS_ABOUT_IT, "Informazioni su VICE..." },
/* ko */ { IDMS_ABOUT_KO, "���� VICE..." },
/* nl */ { IDMS_ABOUT_NL, "Over VICE..." },
/* pl */ { IDMS_ABOUT_PL, "O VICE..." },
/* ru */ { IDMS_ABOUT_RU, "" },  /* fuzzy */
/* sv */ { IDMS_ABOUT_SV, "Om VICE..." },
/* tr */ { IDMS_ABOUT_TR, "VICE Hakk�nda..." },

/* en */ { IDMS_COMMAND_LINE_OPTIONS,    "Command line options" },
/* da */ { IDMS_COMMAND_LINE_OPTIONS_DA, "Kommandolinjeparametre" },
/* de */ { IDMS_COMMAND_LINE_OPTIONS_DE, "Kommandozeilen Paramteter" },
/* es */ { IDMS_COMMAND_LINE_OPTIONS_ES, "Opciones de la linea de comandos" },
/* fr */ { IDMS_COMMAND_LINE_OPTIONS_FR, "Options de ligne de commande" },
/* hu */ { IDMS_COMMAND_LINE_OPTIONS_HU, "Parancssori opci�k" },
/* it */ { IDMS_COMMAND_LINE_OPTIONS_IT, "Parametri della riga di comando" },
/* ko */ { IDMS_COMMAND_LINE_OPTIONS_KO, "Ŀ�ǵ� ���� �ɼ�" },
/* nl */ { IDMS_COMMAND_LINE_OPTIONS_NL, "Commando opties" },
/* pl */ { IDMS_COMMAND_LINE_OPTIONS_PL, "Opcje wiersza polece�" },
/* ru */ { IDMS_COMMAND_LINE_OPTIONS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_COMMAND_LINE_OPTIONS_SV, "Kommandoradsflaggor" },
/* tr */ { IDMS_COMMAND_LINE_OPTIONS_TR, "Komut sat�r� se�enekleri" },

/* en */ { IDMS_CONTRIBUTORS,    "Contributors" },
/* da */ { IDMS_CONTRIBUTORS_DA, "Bidragsydere" },
/* de */ { IDMS_CONTRIBUTORS_DE, "VICE Hackers" },
/* es */ { IDMS_CONTRIBUTORS_ES, "Contribuyentes" },
/* fr */ { IDMS_CONTRIBUTORS_FR, "Contributeurs" },
/* hu */ { IDMS_CONTRIBUTORS_HU, "K�zrem�k�d�k" },
/* it */ { IDMS_CONTRIBUTORS_IT, "Collaboratori" },
/* ko */ { IDMS_CONTRIBUTORS_KO, "������" },
/* nl */ { IDMS_CONTRIBUTORS_NL, "Medewerkers" },
/* pl */ { IDMS_CONTRIBUTORS_PL, "Wsp�pracownicy" },
/* ru */ { IDMS_CONTRIBUTORS_RU, "" },  /* fuzzy */
/* sv */ { IDMS_CONTRIBUTORS_SV, "Bidragsl�mnare" },
/* tr */ { IDMS_CONTRIBUTORS_TR, "Kat�l�mc�lar" },

/* en */ { IDMS_LICENSE,    "License" },
/* da */ { IDMS_LICENSE_DA, "Licens" },
/* de */ { IDMS_LICENSE_DE, "Lizenz" },
/* es */ { IDMS_LICENSE_ES, "Licencia" },
/* fr */ { IDMS_LICENSE_FR, "License" },
/* hu */ { IDMS_LICENSE_HU, "Licensz" },
/* it */ { IDMS_LICENSE_IT, "Licenza" },
/* ko */ { IDMS_LICENSE_KO, "����" },
/* nl */ { IDMS_LICENSE_NL, "Licentie" },
/* pl */ { IDMS_LICENSE_PL, "Licencja" },
/* ru */ { IDMS_LICENSE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LICENSE_SV, "Licens" },
/* tr */ { IDMS_LICENSE_TR, "Lisans" },

/* en */ { IDMS_NO_WARRANTY,    "No warranty!" },
/* da */ { IDMS_NO_WARRANTY_DA, "Ingen garanti!" },
/* de */ { IDMS_NO_WARRANTY_DE, "Keine Garantie!" },
/* es */ { IDMS_NO_WARRANTY_ES, "�Sin garantias!" },
/* fr */ { IDMS_NO_WARRANTY_FR, "Aucune garantie!" },
/* hu */ { IDMS_NO_WARRANTY_HU, "Nincs garancia!" },
/* it */ { IDMS_NO_WARRANTY_IT, "Nessuna garanzia!" },
/* ko */ { IDMS_NO_WARRANTY_KO, "����Ƽ �����ϴ�" },
/* nl */ { IDMS_NO_WARRANTY_NL, "Geen garantie!" },
/* pl */ { IDMS_NO_WARRANTY_PL, "Bez gwarancji!" },
/* ru */ { IDMS_NO_WARRANTY_RU, "" },  /* fuzzy */
/* sv */ { IDMS_NO_WARRANTY_SV, "Ingen garanti!" },
/* tr */ { IDMS_NO_WARRANTY_TR, "Garanti verilmez!" },

/* en */ { IDMS_LANGUAGE_INTERNATIONAL,    "International" },
/* da */ { IDMS_LANGUAGE_INTERNATIONAL_DA, "International" },
/* de */ { IDMS_LANGUAGE_INTERNATIONAL_DE, "International" },
/* es */ { IDMS_LANGUAGE_INTERNATIONAL_ES, "Internacional" },
/* fr */ { IDMS_LANGUAGE_INTERNATIONAL_FR, "" },  /* fuzzy */
/* hu */ { IDMS_LANGUAGE_INTERNATIONAL_HU, "Nemzetk�zi" },
/* it */ { IDMS_LANGUAGE_INTERNATIONAL_IT, "Internazionale" },
/* ko */ { IDMS_LANGUAGE_INTERNATIONAL_KO, "����" },
/* nl */ { IDMS_LANGUAGE_INTERNATIONAL_NL, "Internationaal" },
/* pl */ { IDMS_LANGUAGE_INTERNATIONAL_PL, "Mi�dzynarodowa" },
/* ru */ { IDMS_LANGUAGE_INTERNATIONAL_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_INTERNATIONAL_SV, "Internationell" },
/* tr */ { IDMS_LANGUAGE_INTERNATIONAL_TR, "Uluslararas�" },

/* en */ { IDMS_LANGUAGE_ENGLISH,    "English" },
/* da */ { IDMS_LANGUAGE_ENGLISH_DA, "Engelsk" },
/* de */ { IDMS_LANGUAGE_ENGLISH_DE, "Englisch" },
/* es */ { IDMS_LANGUAGE_ENGLISH_ES, "ingl�s" },
/* fr */ { IDMS_LANGUAGE_ENGLISH_FR, "Anglais" },
/* hu */ { IDMS_LANGUAGE_ENGLISH_HU, "Angol" },
/* it */ { IDMS_LANGUAGE_ENGLISH_IT, "Inglese" },
/* ko */ { IDMS_LANGUAGE_ENGLISH_KO, "����" },
/* nl */ { IDMS_LANGUAGE_ENGLISH_NL, "Engels" },
/* pl */ { IDMS_LANGUAGE_ENGLISH_PL, "Angielski" },
/* ru */ { IDMS_LANGUAGE_ENGLISH_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_ENGLISH_SV, "Engelska" },
/* tr */ { IDMS_LANGUAGE_ENGLISH_TR, "�ngilizce" },

/* en */ { IDMS_LANGUAGE_DANISH,    "Danish" },
/* da */ { IDMS_LANGUAGE_DANISH_DA, "Dansk" },
/* de */ { IDMS_LANGUAGE_DANISH_DE, "D�nisch" },
/* es */ { IDMS_LANGUAGE_DANISH_ES, "Dan�s" },
/* fr */ { IDMS_LANGUAGE_DANISH_FR, "" },  /* fuzzy */
/* hu */ { IDMS_LANGUAGE_DANISH_HU, "D�n" },
/* it */ { IDMS_LANGUAGE_DANISH_IT, "Danese" },
/* ko */ { IDMS_LANGUAGE_DANISH_KO, "����ũ��" },
/* nl */ { IDMS_LANGUAGE_DANISH_NL, "Deens" },
/* pl */ { IDMS_LANGUAGE_DANISH_PL, "Du�ski" },
/* ru */ { IDMS_LANGUAGE_DANISH_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_DANISH_SV, "Danska" },
/* tr */ { IDMS_LANGUAGE_DANISH_TR, "Danimarkaca" },

/* en */ { IDMS_LANGUAGE_GERMAN,    "German" },
/* da */ { IDMS_LANGUAGE_GERMAN_DA, "Tysk" },
/* de */ { IDMS_LANGUAGE_GERMAN_DE, "Deutsch" },
/* es */ { IDMS_LANGUAGE_GERMAN_ES, "Alem�n" },
/* fr */ { IDMS_LANGUAGE_GERMAN_FR, "Allemand" },
/* hu */ { IDMS_LANGUAGE_GERMAN_HU, "N�met" },
/* it */ { IDMS_LANGUAGE_GERMAN_IT, "Tedesco" },
/* ko */ { IDMS_LANGUAGE_GERMAN_KO, "���Ͼ�" },
/* nl */ { IDMS_LANGUAGE_GERMAN_NL, "Duits" },
/* pl */ { IDMS_LANGUAGE_GERMAN_PL, "Niemiecki" },
/* ru */ { IDMS_LANGUAGE_GERMAN_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_GERMAN_SV, "Tyska" },
/* tr */ { IDMS_LANGUAGE_GERMAN_TR, "Almanca" },

/* en */ { IDMS_LANGUAGE_SPANISH,    "Spanish" },
/* da */ { IDMS_LANGUAGE_SPANISH_DA, "" },  /* fuzzy */
/* de */ { IDMS_LANGUAGE_SPANISH_DE, "Spanisch" },
/* es */ { IDMS_LANGUAGE_SPANISH_ES, "Espa�ol" },
/* fr */ { IDMS_LANGUAGE_SPANISH_FR, "" },  /* fuzzy */
/* hu */ { IDMS_LANGUAGE_SPANISH_HU, "" },  /* fuzzy */
/* it */ { IDMS_LANGUAGE_SPANISH_IT, "" },  /* fuzzy */
/* ko */ { IDMS_LANGUAGE_SPANISH_KO, "" },  /* fuzzy */
/* nl */ { IDMS_LANGUAGE_SPANISH_NL, "Spaans" },
/* pl */ { IDMS_LANGUAGE_SPANISH_PL, "Hiszpa�ski" },
/* ru */ { IDMS_LANGUAGE_SPANISH_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_SPANISH_SV, "" },  /* fuzzy */
/* tr */ { IDMS_LANGUAGE_SPANISH_TR, "" },  /* fuzzy */

/* en */ { IDMS_LANGUAGE_FINNISH,    "Finnish" },
/* da */ { IDMS_LANGUAGE_FINNISH_DA, "Finsk" },
/* de */ { IDMS_LANGUAGE_FINNISH_DE, "Finnisch" },
/* es */ { IDMS_LANGUAGE_FINNISH_ES, "Finland�s" },
/* fr */ { IDMS_LANGUAGE_FINNISH_FR, "" },  /* fuzzy */
/* hu */ { IDMS_LANGUAGE_FINNISH_HU, "Finn" },
/* it */ { IDMS_LANGUAGE_FINNISH_IT, "Finlandese" },
/* ko */ { IDMS_LANGUAGE_FINNISH_KO, "�ɶ����" },
/* nl */ { IDMS_LANGUAGE_FINNISH_NL, "Fins" },
/* pl */ { IDMS_LANGUAGE_FINNISH_PL, "Fi�ski" },
/* ru */ { IDMS_LANGUAGE_FINNISH_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_FINNISH_SV, "Finska" },
/* tr */ { IDMS_LANGUAGE_FINNISH_TR, "Fince" },

/* en */ { IDMS_LANGUAGE_FRENCH,    "French" },
/* da */ { IDMS_LANGUAGE_FRENCH_DA, "Fransk" },
/* de */ { IDMS_LANGUAGE_FRENCH_DE, "Franz�sisch" },
/* es */ { IDMS_LANGUAGE_FRENCH_ES, "Franc�s" },
/* fr */ { IDMS_LANGUAGE_FRENCH_FR, "Fran�ais" },
/* hu */ { IDMS_LANGUAGE_FRENCH_HU, "Francia" },
/* it */ { IDMS_LANGUAGE_FRENCH_IT, "Francese" },
/* ko */ { IDMS_LANGUAGE_FRENCH_KO, "��������" },
/* nl */ { IDMS_LANGUAGE_FRENCH_NL, "Frans" },
/* pl */ { IDMS_LANGUAGE_FRENCH_PL, "Francuski" },
/* ru */ { IDMS_LANGUAGE_FRENCH_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_FRENCH_SV, "Franska" },
/* tr */ { IDMS_LANGUAGE_FRENCH_TR, "Frans�zca" },

/* en */ { IDMS_LANGUAGE_HUNGARIAN,    "Hungarian" },
/* da */ { IDMS_LANGUAGE_HUNGARIAN_DA, "Ungersk" },
/* de */ { IDMS_LANGUAGE_HUNGARIAN_DE, "Ungarisch" },
/* es */ { IDMS_LANGUAGE_HUNGARIAN_ES, "H�ngaro" },
/* fr */ { IDMS_LANGUAGE_HUNGARIAN_FR, "Hungarian" },
/* hu */ { IDMS_LANGUAGE_HUNGARIAN_HU, "Magyar" },
/* it */ { IDMS_LANGUAGE_HUNGARIAN_IT, "Ungherese" },
/* ko */ { IDMS_LANGUAGE_HUNGARIAN_KO, "�밡����" },
/* nl */ { IDMS_LANGUAGE_HUNGARIAN_NL, "Hongaars" },
/* pl */ { IDMS_LANGUAGE_HUNGARIAN_PL, "W�gierski" },
/* ru */ { IDMS_LANGUAGE_HUNGARIAN_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_HUNGARIAN_SV, "Ungerska" },
/* tr */ { IDMS_LANGUAGE_HUNGARIAN_TR, "Macarca" },

/* en */ { IDMS_LANGUAGE_ITALIAN,    "Italian" },
/* da */ { IDMS_LANGUAGE_ITALIAN_DA, "Italiensk" },
/* de */ { IDMS_LANGUAGE_ITALIAN_DE, "Italienisch" },
/* es */ { IDMS_LANGUAGE_ITALIAN_ES, "Italiano" },
/* fr */ { IDMS_LANGUAGE_ITALIAN_FR, "Italien" },
/* hu */ { IDMS_LANGUAGE_ITALIAN_HU, "Olasz" },
/* it */ { IDMS_LANGUAGE_ITALIAN_IT, "Italiano" },
/* ko */ { IDMS_LANGUAGE_ITALIAN_KO, "��Ż���ƾ�" },
/* nl */ { IDMS_LANGUAGE_ITALIAN_NL, "Italiaans" },
/* pl */ { IDMS_LANGUAGE_ITALIAN_PL, "W�oski" },
/* ru */ { IDMS_LANGUAGE_ITALIAN_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_ITALIAN_SV, "Italienska" },
/* tr */ { IDMS_LANGUAGE_ITALIAN_TR, "�talyanca" },

/* en */ { IDMS_LANGUAGE_KOREAN,    "Korean" },
/* da */ { IDMS_LANGUAGE_KOREAN_DA, "" },  /* fuzzy */
/* de */ { IDMS_LANGUAGE_KOREAN_DE, "Koreanisch" },
/* es */ { IDMS_LANGUAGE_KOREAN_ES, "Coreano" },
/* fr */ { IDMS_LANGUAGE_KOREAN_FR, "" },  /* fuzzy */
/* hu */ { IDMS_LANGUAGE_KOREAN_HU, "" },  /* fuzzy */
/* it */ { IDMS_LANGUAGE_KOREAN_IT, "" },  /* fuzzy */
/* ko */ { IDMS_LANGUAGE_KOREAN_KO, "�ѱ���" },
/* nl */ { IDMS_LANGUAGE_KOREAN_NL, "Koreaans" },
/* pl */ { IDMS_LANGUAGE_KOREAN_PL, "Korea�ski" },
/* ru */ { IDMS_LANGUAGE_KOREAN_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_KOREAN_SV, "Koreanska" },
/* tr */ { IDMS_LANGUAGE_KOREAN_TR, "" },  /* fuzzy */

/* en */ { IDMS_LANGUAGE_DUTCH,    "Dutch" },
/* da */ { IDMS_LANGUAGE_DUTCH_DA, "Hollandsk" },
/* de */ { IDMS_LANGUAGE_DUTCH_DE, "Holl�ndisch" },
/* es */ { IDMS_LANGUAGE_DUTCH_ES, "Holand�s" },
/* fr */ { IDMS_LANGUAGE_DUTCH_FR, "Hollandais" },
/* hu */ { IDMS_LANGUAGE_DUTCH_HU, "Holland" },
/* it */ { IDMS_LANGUAGE_DUTCH_IT, "Olandese" },
/* ko */ { IDMS_LANGUAGE_DUTCH_KO, "�״������" },
/* nl */ { IDMS_LANGUAGE_DUTCH_NL, "Nederlands" },
/* pl */ { IDMS_LANGUAGE_DUTCH_PL, "Holenderski" },
/* ru */ { IDMS_LANGUAGE_DUTCH_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_DUTCH_SV, "Nederl�ndska" },
/* tr */ { IDMS_LANGUAGE_DUTCH_TR, "Hollandaca" },

/* en */ { IDMS_LANGUAGE_POLISH,    "Polish" },
/* da */ { IDMS_LANGUAGE_POLISH_DA, "Polsk" },
/* de */ { IDMS_LANGUAGE_POLISH_DE, "Polnisch" },
/* es */ { IDMS_LANGUAGE_POLISH_ES, "polaco" },
/* fr */ { IDMS_LANGUAGE_POLISH_FR, "Polonais" },
/* hu */ { IDMS_LANGUAGE_POLISH_HU, "Lengyel" },
/* it */ { IDMS_LANGUAGE_POLISH_IT, "Polacco" },
/* ko */ { IDMS_LANGUAGE_POLISH_KO, "�������" },
/* nl */ { IDMS_LANGUAGE_POLISH_NL, "Pools" },
/* pl */ { IDMS_LANGUAGE_POLISH_PL, "Polski" },
/* ru */ { IDMS_LANGUAGE_POLISH_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_POLISH_SV, "Polska" },
/* tr */ { IDMS_LANGUAGE_POLISH_TR, "Polonyaca" },

/* en */ { IDMS_LANGUAGE_NORWEGIAN,    "Norwegian" },
/* da */ { IDMS_LANGUAGE_NORWEGIAN_DA, "Norsk" },
/* de */ { IDMS_LANGUAGE_NORWEGIAN_DE, "Norwegisch" },
/* es */ { IDMS_LANGUAGE_NORWEGIAN_ES, "Noruego" },
/* fr */ { IDMS_LANGUAGE_NORWEGIAN_FR, "" },  /* fuzzy */
/* hu */ { IDMS_LANGUAGE_NORWEGIAN_HU, "Norv�g" },
/* it */ { IDMS_LANGUAGE_NORWEGIAN_IT, "Norvegese" },
/* ko */ { IDMS_LANGUAGE_NORWEGIAN_KO, "�븣���̾�" },
/* nl */ { IDMS_LANGUAGE_NORWEGIAN_NL, "Noors" },
/* pl */ { IDMS_LANGUAGE_NORWEGIAN_PL, "Norweski" },
/* ru */ { IDMS_LANGUAGE_NORWEGIAN_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_NORWEGIAN_SV, "Norska" },
/* tr */ { IDMS_LANGUAGE_NORWEGIAN_TR, "Norve��e" },

/* en */ { IDMS_LANGUAGE_RUSSIAN,    "Russian" },
/* da */ { IDMS_LANGUAGE_RUSSIAN_DA, "" },  /* fuzzy */
/* de */ { IDMS_LANGUAGE_RUSSIAN_DE, "Russisch" },
/* es */ { IDMS_LANGUAGE_RUSSIAN_ES, "Ruso" },
/* fr */ { IDMS_LANGUAGE_RUSSIAN_FR, "" },  /* fuzzy */
/* hu */ { IDMS_LANGUAGE_RUSSIAN_HU, "" },  /* fuzzy */
/* it */ { IDMS_LANGUAGE_RUSSIAN_IT, "" },  /* fuzzy */
/* ko */ { IDMS_LANGUAGE_RUSSIAN_KO, "���þƾ�" },
/* nl */ { IDMS_LANGUAGE_RUSSIAN_NL, "Russies" },
/* pl */ { IDMS_LANGUAGE_RUSSIAN_PL, "Rosyjski" },
/* ru */ { IDMS_LANGUAGE_RUSSIAN_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_RUSSIAN_SV, "Ryska" },
/* tr */ { IDMS_LANGUAGE_RUSSIAN_TR, "" },  /* fuzzy */

/* en */ { IDMS_LANGUAGE_SWEDISH,    "Swedish" },
/* da */ { IDMS_LANGUAGE_SWEDISH_DA, "Svensk" },
/* de */ { IDMS_LANGUAGE_SWEDISH_DE, "Schwedisch" },
/* es */ { IDMS_LANGUAGE_SWEDISH_ES, "Sueco" },
/* fr */ { IDMS_LANGUAGE_SWEDISH_FR, "Su�dois" },
/* hu */ { IDMS_LANGUAGE_SWEDISH_HU, "Sv�d" },
/* it */ { IDMS_LANGUAGE_SWEDISH_IT, "Svedese" },
/* ko */ { IDMS_LANGUAGE_SWEDISH_KO, "��������" },
/* nl */ { IDMS_LANGUAGE_SWEDISH_NL, "Zweeds" },
/* pl */ { IDMS_LANGUAGE_SWEDISH_PL, "Szwedzki" },
/* ru */ { IDMS_LANGUAGE_SWEDISH_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_SWEDISH_SV, "Svenska" },
/* tr */ { IDMS_LANGUAGE_SWEDISH_TR, "�sve��e" },

/* en */ { IDMS_LANGUAGE_TURKISH,    "Turkish" },
/* da */ { IDMS_LANGUAGE_TURKISH_DA, "Tyrkisk" },
/* de */ { IDMS_LANGUAGE_TURKISH_DE, "T�rkisch" },
/* es */ { IDMS_LANGUAGE_TURKISH_ES, "Turco" },
/* fr */ { IDMS_LANGUAGE_TURKISH_FR, "" },  /* fuzzy */
/* hu */ { IDMS_LANGUAGE_TURKISH_HU, "T�r�k" },
/* it */ { IDMS_LANGUAGE_TURKISH_IT, "Turco" },
/* ko */ { IDMS_LANGUAGE_TURKISH_KO, "��Ű��" },
/* nl */ { IDMS_LANGUAGE_TURKISH_NL, "Turks" },
/* pl */ { IDMS_LANGUAGE_TURKISH_PL, "Turecki" },
/* ru */ { IDMS_LANGUAGE_TURKISH_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_TURKISH_SV, "Turkiska" },
/* tr */ { IDMS_LANGUAGE_TURKISH_TR, "T�rk�e" },

/* en */ { IDMS_LANGUAGE,    "Language" },
/* da */ { IDMS_LANGUAGE_DA, "Sprog" },
/* de */ { IDMS_LANGUAGE_DE, "Sprache" },
/* es */ { IDMS_LANGUAGE_ES, "Lenguaje" },
/* fr */ { IDMS_LANGUAGE_FR, "Langage" },
/* hu */ { IDMS_LANGUAGE_HU, "Nyelv" },
/* it */ { IDMS_LANGUAGE_IT, "Lingua" },
/* ko */ { IDMS_LANGUAGE_KO, "���" },
/* nl */ { IDMS_LANGUAGE_NL, "Taal" },
/* pl */ { IDMS_LANGUAGE_PL, "J�zyk" },
/* ru */ { IDMS_LANGUAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMS_LANGUAGE_SV, "Spr�k" },
/* tr */ { IDMS_LANGUAGE_TR, "Dil" },

/* en */ { IDMS_FULLSCREEN_STATUSBAR,    "Fullscreen Statusbar" },
/* da */ { IDMS_FULLSCREEN_STATUSBAR_DA, "Statusbar i fullscreen" },
/* de */ { IDMS_FULLSCREEN_STATUSBAR_DE, "Vollbild Statusleiste" },
/* es */ { IDMS_FULLSCREEN_STATUSBAR_ES, "Barra estado pantalla completa" },
/* fr */ { IDMS_FULLSCREEN_STATUSBAR_FR, "" },  /* fuzzy */
/* hu */ { IDMS_FULLSCREEN_STATUSBAR_HU, "�llapotsor teljes k�perny�n�l" },
/* it */ { IDMS_FULLSCREEN_STATUSBAR_IT, "Barra di stato nella modalit� a schermo intero" },
/* ko */ { IDMS_FULLSCREEN_STATUSBAR_KO, "" },  /* fuzzy */
/* nl */ { IDMS_FULLSCREEN_STATUSBAR_NL, "Volscherm Statusbalk" },
/* pl */ { IDMS_FULLSCREEN_STATUSBAR_PL, "Pasek stanu w trybie pe�nego ekranu" },
/* ru */ { IDMS_FULLSCREEN_STATUSBAR_RU, "" },  /* fuzzy */
/* sv */ { IDMS_FULLSCREEN_STATUSBAR_SV, "Statusrad i fullsk�rm" },
/* tr */ { IDMS_FULLSCREEN_STATUSBAR_TR, "Tam ekran durum �ubu�u" },

/* en */ { IDMS_VIDEO_OVERLAY,    "Video overlay" },
/* da */ { IDMS_VIDEO_OVERLAY_DA, "Video-overlay" },
/* de */ { IDMS_VIDEO_OVERLAY_DE, "Video Overlay" },
/* es */ { IDMS_VIDEO_OVERLAY_ES, "Video overlay" },
/* fr */ { IDMS_VIDEO_OVERLAY_FR, "" },  /* fuzzy */
/* hu */ { IDMS_VIDEO_OVERLAY_HU, "Vide� overlay" },
/* it */ { IDMS_VIDEO_OVERLAY_IT, "Overlay video" },
/* ko */ { IDMS_VIDEO_OVERLAY_KO, "" },  /* fuzzy */
/* nl */ { IDMS_VIDEO_OVERLAY_NL, "Video overlay" },
/* pl */ { IDMS_VIDEO_OVERLAY_PL, "Video overlay" },
/* ru */ { IDMS_VIDEO_OVERLAY_RU, "" },  /* fuzzy */
/* sv */ { IDMS_VIDEO_OVERLAY_SV, "Video-overlay" },
/* tr */ { IDMS_VIDEO_OVERLAY_TR, "G�r�nt� bindirme" },

/* en */ { IDMS_START_SOUND_RECORD,    "Start Sound Record..." },
/* da */ { IDMS_START_SOUND_RECORD_DA, "Start lydoptagelse..." },
/* de */ { IDMS_START_SOUND_RECORD_DE, "Tonaufnahme starten..." },
/* es */ { IDMS_START_SOUND_RECORD_ES, "Iniciar grabaci�n sonido..." },
/* fr */ { IDMS_START_SOUND_RECORD_FR, "" },  /* fuzzy */
/* hu */ { IDMS_START_SOUND_RECORD_HU, "" },  /* fuzzy */
/* it */ { IDMS_START_SOUND_RECORD_IT, "Avvia la registrazione audio..." },
/* ko */ { IDMS_START_SOUND_RECORD_KO, "" },  /* fuzzy */
/* nl */ { IDMS_START_SOUND_RECORD_NL, "Start Geluidsopname..." },
/* pl */ { IDMS_START_SOUND_RECORD_PL, "Rozpocznij zapis d�wi�ku..." },
/* ru */ { IDMS_START_SOUND_RECORD_RU, "" },  /* fuzzy */
/* sv */ { IDMS_START_SOUND_RECORD_SV, "Starta ljudinspelning..." },
/* tr */ { IDMS_START_SOUND_RECORD_TR, "Ses Kayd�n� Ba�lat..." },

/* en */ { IDMS_STOP_SOUND_RECORD,    "Stop Sound record" },
/* da */ { IDMS_STOP_SOUND_RECORD_DA, "Stop lydoptagelse" },
/* de */ { IDMS_STOP_SOUND_RECORD_DE, "Tonaufnahme stoppen" },
/* es */ { IDMS_STOP_SOUND_RECORD_ES, "Finalizar grabaci�n de sonido" },
/* fr */ { IDMS_STOP_SOUND_RECORD_FR, "" },  /* fuzzy */
/* hu */ { IDMS_STOP_SOUND_RECORD_HU, "Hangfelv�tel le�ll�t�sa" },
/* it */ { IDMS_STOP_SOUND_RECORD_IT, "Interrompi registrazione audio" },
/* ko */ { IDMS_STOP_SOUND_RECORD_KO, "���� ���ڵ� ����" },
/* nl */ { IDMS_STOP_SOUND_RECORD_NL, "Stop geluidsopname" },
/* pl */ { IDMS_STOP_SOUND_RECORD_PL, "Zatrzymaj zapis d�wi�ku" },
/* ru */ { IDMS_STOP_SOUND_RECORD_RU, "" },  /* fuzzy */
/* sv */ { IDMS_STOP_SOUND_RECORD_SV, "Stoppa ljudinspelning" },
/* tr */ { IDMS_STOP_SOUND_RECORD_TR, "Ses kayd�n� durdur" },

/* en */ { IDMES_VALUE_D_OUT_OF_RANGE_USING_D_INSTEAD,    "Value %d out of range, range is from %d to %d, using %d instead" },
/* da */ { IDMES_VALUE_D_OUT_OF_RANGE_USING_D_INSTEAD_DA, "V�rdi %d ugyldig. Tilladt v�rdi fra %d til %d. Bruger %d istedet" },
/* de */ { IDMES_VALUE_D_OUT_OF_RANGE_USING_D_INSTEAD_DE, "Wert %d ist unzul�ssig, Bereich muss zwischen %d und %d liegen, benutze %d" },
/* es */ { IDMES_VALUE_D_OUT_OF_RANGE_USING_D_INSTEAD_ES, "Valor %d fuera de rango, rango de %d a %d, usando %d en su lugar" },
/* fr */ { IDMES_VALUE_D_OUT_OF_RANGE_USING_D_INSTEAD_FR, "" },  /* fuzzy */
/* hu */ { IDMES_VALUE_D_OUT_OF_RANGE_USING_D_INSTEAD_HU, "" },  /* fuzzy */
/* it */ { IDMES_VALUE_D_OUT_OF_RANGE_USING_D_INSTEAD_IT, "Valore %d fuori dai limiti, l' intervallo � da %d a %d, uso %d al suo posto" },
/* ko */ { IDMES_VALUE_D_OUT_OF_RANGE_USING_D_INSTEAD_KO, "" },  /* fuzzy */
/* nl */ { IDMES_VALUE_D_OUT_OF_RANGE_USING_D_INSTEAD_NL, "Waarde %d is buiten het bereik, het bereik is van %d tot %d, %d zal gebruikt worden" },
/* pl */ { IDMES_VALUE_D_OUT_OF_RANGE_USING_D_INSTEAD_PL, "Warto�� %d jest poza zakresem, zakres to %d do %d, u�ywam %d" },
/* ru */ { IDMES_VALUE_D_OUT_OF_RANGE_USING_D_INSTEAD_RU, "" },  /* fuzzy */
/* sv */ { IDMES_VALUE_D_OUT_OF_RANGE_USING_D_INSTEAD_SV, "V�rdet %d �r utanf�r gr�nserna, giltiga v�rden mellan %d och %d, anv�nder %d ist�llet" },
/* tr */ { IDMES_VALUE_D_OUT_OF_RANGE_USING_D_INSTEAD_TR, "%d de�eri alan d���na ��kt�, alan %d - %d aral���nda, yerine %d kullan�l�yor" },

/* en */ { IDMES_VALUE_F_OUT_OF_RANGE_USING_F_INSTEAD,    "Value %.3f out of range, range is from %.3f to %.3f, using %.3f instead" },
/* da */ { IDMES_VALUE_F_OUT_OF_RANGE_USING_F_INSTEAD_DA, "V�rdi %.3f ugyldig. Tilladt v�rdi fra %.3f til %.3f. Bruger %.3f istedet" },
/* de */ { IDMES_VALUE_F_OUT_OF_RANGE_USING_F_INSTEAD_DE, "Wert %.3f ist unzul�ssig, Bereich muss zwischen %.3f und %.3f liegen, benutze %.3f" },
/* es */ { IDMES_VALUE_F_OUT_OF_RANGE_USING_F_INSTEAD_ES, "Valor %.3f fuera de rango, rango de %.3f a %.3f, usando %.3f en su lugar" },
/* fr */ { IDMES_VALUE_F_OUT_OF_RANGE_USING_F_INSTEAD_FR, "" },  /* fuzzy */
/* hu */ { IDMES_VALUE_F_OUT_OF_RANGE_USING_F_INSTEAD_HU, "" },  /* fuzzy */
/* it */ { IDMES_VALUE_F_OUT_OF_RANGE_USING_F_INSTEAD_IT, "Valore %.3f fuori dai limiti, l' intervallo � da %.3f a %.3f, uso %.3f al suo posto" },
/* ko */ { IDMES_VALUE_F_OUT_OF_RANGE_USING_F_INSTEAD_KO, "" },  /* fuzzy */
/* nl */ { IDMES_VALUE_F_OUT_OF_RANGE_USING_F_INSTEAD_NL, "Waarde %.3f is buiten het bereik, het bereik is van %.3f tot %.3f, %.3f zal gebruikt worden" },
/* pl */ { IDMES_VALUE_F_OUT_OF_RANGE_USING_F_INSTEAD_PL, "Warto�� %.3f jest poza zakresem, zakres to %.3f do %.3f, u�ywam %.3f" },
/* ru */ { IDMES_VALUE_F_OUT_OF_RANGE_USING_F_INSTEAD_RU, "" },  /* fuzzy */
/* sv */ { IDMES_VALUE_F_OUT_OF_RANGE_USING_F_INSTEAD_SV, "V�rdet %.3f �r utanf�r gr�nserna, giltiga v�rden mellan %.3f och %.3f, anv�nder %.3f ist�llet" },
/* tr */ { IDMES_VALUE_F_OUT_OF_RANGE_USING_F_INSTEAD_TR, "%.3f de�eri alan d���na ��kt�, alan %.3f - %.3f aral���nda, yerine %.3f kullan�l�yor" },

/* en */ { IDMES_SETTINGS_SAVED_SUCCESS,    "Settings saved successfully." },
/* da */ { IDMES_SETTINGS_SAVED_SUCCESS_DA, "Indstillingerne er gemt." },
/* de */ { IDMES_SETTINGS_SAVED_SUCCESS_DE, "Einstellungen erfolgreich gespeichert" },
/* es */ { IDMES_SETTINGS_SAVED_SUCCESS_ES, "Ajustes grabados correctamente" },
/* fr */ { IDMES_SETTINGS_SAVED_SUCCESS_FR, "Sauvegarde des param�tres effectu�e correctement." },
/* hu */ { IDMES_SETTINGS_SAVED_SUCCESS_HU, "Be�ll�t�sok sikeresen elmentve." },
/* it */ { IDMES_SETTINGS_SAVED_SUCCESS_IT, "Impostazioni salvate con successo." },
/* ko */ { IDMES_SETTINGS_SAVED_SUCCESS_KO, "" },  /* fuzzy */
/* nl */ { IDMES_SETTINGS_SAVED_SUCCESS_NL, "Instellingen met succes opgeslagen." },
/* pl */ { IDMES_SETTINGS_SAVED_SUCCESS_PL, "Zapisywanie ustawie� powiod�o si�." },
/* ru */ { IDMES_SETTINGS_SAVED_SUCCESS_RU, "" },  /* fuzzy */
/* sv */ { IDMES_SETTINGS_SAVED_SUCCESS_SV, "Inst�llningarna har sparats." },
/* tr */ { IDMES_SETTINGS_SAVED_SUCCESS_TR, "Ayarlar ba�ar�yla kaydedildi." },

/* en */ { IDMES_SETTINGS_LOAD_SUCCESS,    "Settings loaded successfully." },
/* da */ { IDMES_SETTINGS_LOAD_SUCCESS_DA, "Indstillinger indl�st med success." },
/* de */ { IDMES_SETTINGS_LOAD_SUCCESS_DE, "Einstellungen erfolgreich geladen." },
/* es */ { IDMES_SETTINGS_LOAD_SUCCESS_ES, "Ajustes cargados con �xito." },
/* fr */ { IDMES_SETTINGS_LOAD_SUCCESS_FR, "Chargement des param�tres r�ussi." },
/* hu */ { IDMES_SETTINGS_LOAD_SUCCESS_HU, "Be�ll�t�sok sikeresen elmentve." },
/* it */ { IDMES_SETTINGS_LOAD_SUCCESS_IT, "Impostazioni caricate con successo." },
/* ko */ { IDMES_SETTINGS_LOAD_SUCCESS_KO, "������ ���������� �ҷ����� ����ϴ�" },
/* nl */ { IDMES_SETTINGS_LOAD_SUCCESS_NL, "Instellingen met succes geladen." },
/* pl */ { IDMES_SETTINGS_LOAD_SUCCESS_PL, "Wczytywanie ustawie� powiod�o si�." },
/* ru */ { IDMES_SETTINGS_LOAD_SUCCESS_RU, "" },  /* fuzzy */
/* sv */ { IDMES_SETTINGS_LOAD_SUCCESS_SV, "Inst�llningarna har l�sts in." },
/* tr */ { IDMES_SETTINGS_LOAD_SUCCESS_TR, "Ayarlar ba�ar�yla y�klendi." },

/* en */ { IDMES_DFLT_SETTINGS_RESTORED,    "Default settings restored." },
/* da */ { IDMES_DFLT_SETTINGS_RESTORED_DA, "Standardindstillinger gendannet." },
/* de */ { IDMES_DFLT_SETTINGS_RESTORED_DE, "Standard wiederhergestellt" },
/* es */ { IDMES_DFLT_SETTINGS_RESTORED_ES, "Ajustes por defecto restaurados." },
/* fr */ { IDMES_DFLT_SETTINGS_RESTORED_FR, "Param�tres par d�faut restaur�s." },
/* hu */ { IDMES_DFLT_SETTINGS_RESTORED_HU, "Alap�rtelmezett be�ll�t�sok vissza�ll�tva." },
/* it */ { IDMES_DFLT_SETTINGS_RESTORED_IT, "Impostazioni originarie ripristinate." },
/* ko */ { IDMES_DFLT_SETTINGS_RESTORED_KO, "" },  /* fuzzy */
/* nl */ { IDMES_DFLT_SETTINGS_RESTORED_NL, "Standaard instellingen hersteld." },
/* pl */ { IDMES_DFLT_SETTINGS_RESTORED_PL, "Przywr�ono domy�lne ustawienia." },
/* ru */ { IDMES_DFLT_SETTINGS_RESTORED_RU, "" },  /* fuzzy */
/* sv */ { IDMES_DFLT_SETTINGS_RESTORED_SV, "F�rvalda inst�llningar �terst�llda." },
/* tr */ { IDMES_DFLT_SETTINGS_RESTORED_TR, "Varsay�lan ayarlara geri d�n�ld�." },

/* en */ { IDMES_VICE_MESSAGE,    "VICE Message" },
/* da */ { IDMES_VICE_MESSAGE_DA, "VICE-besked" },
/* de */ { IDMES_VICE_MESSAGE_DE, "VICE Nachricht" },
/* es */ { IDMES_VICE_MESSAGE_ES, "Mensaje VICE" },
/* fr */ { IDMES_VICE_MESSAGE_FR, "Message VICE" },
/* hu */ { IDMES_VICE_MESSAGE_HU, "VICE �zenet" },
/* it */ { IDMES_VICE_MESSAGE_IT, "Messaggio di VICE" },
/* ko */ { IDMES_VICE_MESSAGE_KO, "VICE �޼���" },
/* nl */ { IDMES_VICE_MESSAGE_NL, "VICE bericht" },
/* pl */ { IDMES_VICE_MESSAGE_PL, "Komunikat VICE" },
/* ru */ { IDMES_VICE_MESSAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMES_VICE_MESSAGE_SV, "VICE-meddelande" },
/* tr */ { IDMES_VICE_MESSAGE_TR, "VICE Mesaj�" },

/* en */ { IDMES_OK,    "OK" },
/* da */ { IDMES_OK_DA, "OK" },
/* de */ { IDMES_OK_DE, "OK" },
/* es */ { IDMES_OK_ES, "OK" },
/* fr */ { IDMES_OK_FR, "OK" },
/* hu */ { IDMES_OK_HU, "OK" },
/* it */ { IDMES_OK_IT, "OK" },
/* ko */ { IDMES_OK_KO, "ok" },
/* nl */ { IDMES_OK_NL, "OK" },
/* pl */ { IDMES_OK_PL, "OK" },
/* ru */ { IDMES_OK_RU, "" },  /* fuzzy */
/* sv */ { IDMES_OK_SV, "OK" },
/* tr */ { IDMES_OK_TR, "Tamam" },

/* en */ { IDMES_VICE_CONTRIBUTORS,    "VICE contributors" },
/* da */ { IDMES_VICE_CONTRIBUTORS_DA, "VICE bidragsydere" },
/* de */ { IDMES_VICE_CONTRIBUTORS_DE, "VICE Hackers" },
/* es */ { IDMES_VICE_CONTRIBUTORS_ES, "Colaboradores VICE" },
/* fr */ { IDMES_VICE_CONTRIBUTORS_FR, "Contributeurs � VICE" },
/* hu */ { IDMES_VICE_CONTRIBUTORS_HU, "VICE - k�zrem�k�d�k" },
/* it */ { IDMES_VICE_CONTRIBUTORS_IT, "Collaboratori" },
/* ko */ { IDMES_VICE_CONTRIBUTORS_KO, "VICE ������" },
/* nl */ { IDMES_VICE_CONTRIBUTORS_NL, "VICE medewerkers" },
/* pl */ { IDMES_VICE_CONTRIBUTORS_PL, "Wsp�pracownicy VICE" },
/* ru */ { IDMES_VICE_CONTRIBUTORS_RU, "" },  /* fuzzy */
/* sv */ { IDMES_VICE_CONTRIBUTORS_SV, "Bidragsl�mnare till VICE" },
/* tr */ { IDMES_VICE_CONTRIBUTORS_TR, "VICE kat�l�mc�lar�" },

/* en */ { IDMES_WHO_MADE_WHAT,    "Who made what?" },
/* da */ { IDMES_WHO_MADE_WHAT_DA, "Hvem har lavet hvad?" },
/* de */ { IDMES_WHO_MADE_WHAT_DE, "Wer hat was gemacht?" },
/* es */ { IDMES_WHO_MADE_WHAT_ES, "�Quien hizo qu�?" },
/* fr */ { IDMES_WHO_MADE_WHAT_FR, "Qui fait quoi?" },
/* hu */ { IDMES_WHO_MADE_WHAT_HU, "Ki mit csin�lt?" },
/* it */ { IDMES_WHO_MADE_WHAT_IT, "Chi ha fatto cosa?" },
/* ko */ { IDMES_WHO_MADE_WHAT_KO, "���� ������ ���������?" },
/* nl */ { IDMES_WHO_MADE_WHAT_NL, "Wie heeft wat gemaakt?" },
/* pl */ { IDMES_WHO_MADE_WHAT_PL, "Kto co zrobi�?" },
/* ru */ { IDMES_WHO_MADE_WHAT_RU, "" },  /* fuzzy */
/* sv */ { IDMES_WHO_MADE_WHAT_SV, "Vem gjorde vad?" },
/* tr */ { IDMES_WHO_MADE_WHAT_TR, "Kim ne yapt�?" },

/* en */ { IDMES_VICE_DIST_NO_WARRANTY,    "VICE is distributed WITHOUT ANY WARRANTY!" },
/* da */ { IDMES_VICE_DIST_NO_WARRANTY_DA, "VICE distribueres UDEN NOGEN SOM HELST GARANTI!" },
/* de */ { IDMES_VICE_DIST_NO_WARRANTY_DE, "VICE ist ohne Garantie" },
/* es */ { IDMES_VICE_DIST_NO_WARRANTY_ES, "�VICE se distribuye SIN NINGUNA GARANTIA!" },
/* fr */ { IDMES_VICE_DIST_NO_WARRANTY_FR, "VICE est distribu� SANS AUCUN GARANTIE!" },
/* hu */ { IDMES_VICE_DIST_NO_WARRANTY_HU, "A VICE-t garancia n�lk�l terjesztj�k!" },
/* it */ { IDMES_VICE_DIST_NO_WARRANTY_IT, "VICE � distribuito SENZA NESSUNA GARANZIA!" },
/* ko */ { IDMES_VICE_DIST_NO_WARRANTY_KO, "VICE �� ��� ����Ƽ ���� �����ǰ� �ֽ��ϴ�!" },
/* nl */ { IDMES_VICE_DIST_NO_WARRANTY_NL, "VICE heeft ABSOLUUT GEEN GARANTIE!" },
/* pl */ { IDMES_VICE_DIST_NO_WARRANTY_PL, "VICE jest rozpowszechniany BEZ �ADNEJ GWARANCJI!" },
/* ru */ { IDMES_VICE_DIST_NO_WARRANTY_RU, "" },  /* fuzzy */
/* sv */ { IDMES_VICE_DIST_NO_WARRANTY_SV, "VICE distribueras UTAN N�GON SOM HELST GARANTI!" },
/* tr */ { IDMES_VICE_DIST_NO_WARRANTY_TR, "VICE H��B�R GARANT� VER�LMEDEN da��t�lm��t�r!" },

/* en */ { IDMES_WHICH_COMMANDS_AVAILABLE,    "Which command line options are available?" },
/* da */ { IDMES_WHICH_COMMANDS_AVAILABLE_DA, "Hvilke kommandolinjeparametre er tilg�ngelige?" },
/* de */ { IDMES_WHICH_COMMANDS_AVAILABLE_DE, "Welche Kommandozeilen Parameter sind verf�gbar?" },
/* es */ { IDMES_WHICH_COMMANDS_AVAILABLE_ES, "�Qu� opciones de linea de comando est�n disponibles?" },
/* fr */ { IDMES_WHICH_COMMANDS_AVAILABLE_FR, "Quelles sont les lignes de commandes disponibles?" },
/* hu */ { IDMES_WHICH_COMMANDS_AVAILABLE_HU, "Milyen parancssori opci�k lehets�gesek?" },
/* it */ { IDMES_WHICH_COMMANDS_AVAILABLE_IT, "Quali parametri della riga di comando sono disponibili?" },
/* ko */ { IDMES_WHICH_COMMANDS_AVAILABLE_KO, "� Ŀ�ǵ� ���� �ɼ��� �����մϱ�?" },
/* nl */ { IDMES_WHICH_COMMANDS_AVAILABLE_NL, "Welke commando opties zijn beschikbaar?" },
/* pl */ { IDMES_WHICH_COMMANDS_AVAILABLE_PL, "Kt�re opcje wiersza polece� s� dost�pne?" },
/* ru */ { IDMES_WHICH_COMMANDS_AVAILABLE_RU, "" },  /* fuzzy */
/* sv */ { IDMES_WHICH_COMMANDS_AVAILABLE_SV, "Vilka kommandoradsflaggor �r tillg�ngliga?" },
/* tr */ { IDMES_WHICH_COMMANDS_AVAILABLE_TR, "Hangi komut sat�r� se�enekleri mevcut?" },

/* en */ { IDMES_CANNOT_SAVE_SETTINGS,    "Cannot save settings." },
/* da */ { IDMES_CANNOT_SAVE_SETTINGS_DA, "Kunne ikke gemme indstillinger." },
/* de */ { IDMES_CANNOT_SAVE_SETTINGS_DE, "Fehler beim Speichern der Einstellungen." },
/* es */ { IDMES_CANNOT_SAVE_SETTINGS_ES, "No puedo grabar ajustes" },
/* fr */ { IDMES_CANNOT_SAVE_SETTINGS_FR, "Impossible d'enregistrer les param�tres." },
/* hu */ { IDMES_CANNOT_SAVE_SETTINGS_HU, "A be�ll�t�sok ment�se nem siker�lt." },
/* it */ { IDMES_CANNOT_SAVE_SETTINGS_IT, "Non � possibile salvare le impostazioni." },
/* ko */ { IDMES_CANNOT_SAVE_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMES_CANNOT_SAVE_SETTINGS_NL, "Kan de instellingen niet opslaan." },
/* pl */ { IDMES_CANNOT_SAVE_SETTINGS_PL, "Nie mo�na zapisa� ustawie�." },
/* ru */ { IDMES_CANNOT_SAVE_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMES_CANNOT_SAVE_SETTINGS_SV, "Kan inte spara inst�llningar." },
/* tr */ { IDMES_CANNOT_SAVE_SETTINGS_TR, "Ayarlar kaydedilemedi." },

/* en */ { IDMES_CANNOT_LOAD_SETTINGS,    "Cannot load settings." },
/* da */ { IDMES_CANNOT_LOAD_SETTINGS_DA, "Kunne ikke indl�se indstillinger." },
/* de */ { IDMES_CANNOT_LOAD_SETTINGS_DE, "Fehler beim Laden der Einstellungen." },
/* es */ { IDMES_CANNOT_LOAD_SETTINGS_ES, "No puedo cargar ajustes." },
/* fr */ { IDMES_CANNOT_LOAD_SETTINGS_FR, "Impossible de charger les param�tres." },
/* hu */ { IDMES_CANNOT_LOAD_SETTINGS_HU, "A be�ll�t�sok bet�lt�se nem siker�lt." },
/* it */ { IDMES_CANNOT_LOAD_SETTINGS_IT, "Non � possibile caricare le impostazioni." },
/* ko */ { IDMES_CANNOT_LOAD_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDMES_CANNOT_LOAD_SETTINGS_NL, "Kan de instellingen niet laden." },
/* pl */ { IDMES_CANNOT_LOAD_SETTINGS_PL, "Nie mo�na wczyta� ustawie�." },
/* ru */ { IDMES_CANNOT_LOAD_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDMES_CANNOT_LOAD_SETTINGS_SV, "Kan inte l�sa inst�llningar." },
/* tr */ { IDMES_CANNOT_LOAD_SETTINGS_TR, "Ayarlar y�klenemedi." },

/* en */ { IDMES_VICE_ERROR,    "VICE Error!" },
/* da */ { IDMES_VICE_ERROR_DA, "VICE-fejl!" },
/* de */ { IDMES_VICE_ERROR_DE, "VICE Fehler!" },
/* es */ { IDMES_VICE_ERROR_ES, "�Error VICE!" },
/* fr */ { IDMES_VICE_ERROR_FR, "Erreur VICE!" },
/* hu */ { IDMES_VICE_ERROR_HU, "VICE hiba!" },
/* it */ { IDMES_VICE_ERROR_IT, "Errore di VICE!" },
/* ko */ { IDMES_VICE_ERROR_KO, "VICE ����!" },
/* nl */ { IDMES_VICE_ERROR_NL, "VICE Fout!" },
/* pl */ { IDMES_VICE_ERROR_PL, "B��d VICE!" },
/* ru */ { IDMES_VICE_ERROR_RU, "" },  /* fuzzy */
/* sv */ { IDMES_VICE_ERROR_SV, "VICE-fel!" },
/* tr */ { IDMES_VICE_ERROR_TR, "VICE Hatas�!" },

/* en */ { IDMES_DEVICE_NOT_GAMEPAD,    "The device on this port is not a gamepad" },
/* da */ { IDMES_DEVICE_NOT_GAMEPAD_DA, "Enheden p� denne port er ikke en joypad" },
/* de */ { IDMES_DEVICE_NOT_GAMEPAD_DE, "Das Ger�t in diesem Port ist kein Gamepad" },
/* es */ { IDMES_DEVICE_NOT_GAMEPAD_ES, "El perif�rico en este puerto no es un gamepad" },
/* fr */ { IDMES_DEVICE_NOT_GAMEPAD_FR, "Le p�riph�rique sur ce port n�est pas une manette" },
/* hu */ { IDMES_DEVICE_NOT_GAMEPAD_HU, "Az eszk�z ezen a porton nem gamepad" },
/* it */ { IDMES_DEVICE_NOT_GAMEPAD_IT, "Il dispositivo su questa porta non � un gamepad" },
/* ko */ { IDMES_DEVICE_NOT_GAMEPAD_KO, "" },  /* fuzzy */
/* nl */ { IDMES_DEVICE_NOT_GAMEPAD_NL, "Het apparaat op deze poort is geen gamepad" },
/* pl */ { IDMES_DEVICE_NOT_GAMEPAD_PL, "Urz�dzenie w tym porcie nie jest padem" },
/* ru */ { IDMES_DEVICE_NOT_GAMEPAD_RU, "" },  /* fuzzy */
/* sv */ { IDMES_DEVICE_NOT_GAMEPAD_SV, "Enheten p� denna port �r inte en styrplatta" },
/* tr */ { IDMES_DEVICE_NOT_GAMEPAD_TR, "Bu port �zerindeki ayg�t gamepad de�il" },

/* en */ { IDMES_NOT_MAPPED_TO_AMIGA_PORT,    "The port is not mapped to an Amiga port" },
/* da */ { IDMES_NOT_MAPPED_TO_AMIGA_PORT_DA, "Denne port er ikke koblet til en Amigaport" },
/* de */ { IDMES_NOT_MAPPED_TO_AMIGA_PORT_DE, "Dieses Port ist keinem Amiga Port zugeordnet" },
/* es */ { IDMES_NOT_MAPPED_TO_AMIGA_PORT_ES, "El puerto no est� mapeado como puerto Amiga" },
/* fr */ { IDMES_NOT_MAPPED_TO_AMIGA_PORT_FR, "Le port n�est pas mapp� sur un port Amiga" },
/* hu */ { IDMES_NOT_MAPPED_TO_AMIGA_PORT_HU, "A port nincs lek�pezve egy Amiga portra" },
/* it */ { IDMES_NOT_MAPPED_TO_AMIGA_PORT_IT, "Questa porta non � mappata su una porta dell'Amiga" },
/* ko */ { IDMES_NOT_MAPPED_TO_AMIGA_PORT_KO, "" },  /* fuzzy */
/* nl */ { IDMES_NOT_MAPPED_TO_AMIGA_PORT_NL, "De poort is niet verbonden met een Amigapoort" },
/* pl */ { IDMES_NOT_MAPPED_TO_AMIGA_PORT_PL, "Port nie jest zmapowany do portu Amigi" },
/* ru */ { IDMES_NOT_MAPPED_TO_AMIGA_PORT_RU, "" },  /* fuzzy */
/* sv */ { IDMES_NOT_MAPPED_TO_AMIGA_PORT_SV, "Porten �r inte kopplad till en Amigaport" },
/* tr */ { IDMES_NOT_MAPPED_TO_AMIGA_PORT_TR, "Port bir Amiga portuyla e�le�tirilemedi" },

/* en */ { IDMES_CANNOT_AUTOSTART_FILE,    "Cannot autostart specified file." },
/* da */ { IDMES_CANNOT_AUTOSTART_FILE_DA, "Kan ikke autostarte valgt fil" },
/* de */ { IDMES_CANNOT_AUTOSTART_FILE_DE, "Autostart von angeforderter Datei fehlgeschlagen." },
/* es */ { IDMES_CANNOT_AUTOSTART_FILE_ES, "No puedo autoarrancar el fichero especificado." },
/* fr */ { IDMES_CANNOT_AUTOSTART_FILE_FR, "Impossible de d�marrer automatiquement le fichier sp�cifi�" },
/* hu */ { IDMES_CANNOT_AUTOSTART_FILE_HU, "Nem lehet automatikusan elind�tani a megadott f�jlt." },
/* it */ { IDMES_CANNOT_AUTOSTART_FILE_IT, "Non � possibile avviare automaticamente il file specificato." },
/* ko */ { IDMES_CANNOT_AUTOSTART_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDMES_CANNOT_AUTOSTART_FILE_NL, "Kan opgegeven bestand niet autostarten." },
/* pl */ { IDMES_CANNOT_AUTOSTART_FILE_PL, "Nie mo�na automatycznie wystartowa� z danego pliku." },
/* ru */ { IDMES_CANNOT_AUTOSTART_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDMES_CANNOT_AUTOSTART_FILE_SV, "Kan inte autostarta angiven fil." },
/* tr */ { IDMES_CANNOT_AUTOSTART_FILE_TR, "Belirtilen dosya otomatik ba�lat�lamad�." },

/* en */ { IDMES_CANNOT_ATTACH_FILE,    "Cannot attach specified file" },
/* da */ { IDMES_CANNOT_ATTACH_FILE_DA, "Kan ikke tilslutte den valgte fil" },
/* de */ { IDMES_CANNOT_ATTACH_FILE_DE, "Kann Image Datei nicht einlegen" },
/* es */ { IDMES_CANNOT_ATTACH_FILE_ES, "No puedo insertar el fichero especificado" },
/* fr */ { IDMES_CANNOT_ATTACH_FILE_FR, "Impossible d'attacher le fichier sp�cifi�" },
/* hu */ { IDMES_CANNOT_ATTACH_FILE_HU, "Nem lehet csatolni a megadott f�jlt" },
/* it */ { IDMES_CANNOT_ATTACH_FILE_IT, "Non � possibile selezionare il file specificato" },
/* ko */ { IDMES_CANNOT_ATTACH_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDMES_CANNOT_ATTACH_FILE_NL, "Kan het opgegeven bestand niet koppelen" },
/* pl */ { IDMES_CANNOT_ATTACH_FILE_PL, "Nie mo�na zamontowa� danego pliku" },
/* ru */ { IDMES_CANNOT_ATTACH_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDMES_CANNOT_ATTACH_FILE_SV, "Kan inte ansluta filen" },
/* tr */ { IDMES_CANNOT_ATTACH_FILE_TR, "Belirtilen dosya yerle�tirilemedi" },

/* en */ { IDMES_INVALID_CART,    "Invalid cartridge image" },
/* da */ { IDMES_INVALID_CART_DA, "Ugyldigt cartridge-image" },
/* de */ { IDMES_INVALID_CART_DE, "Ung�ltiges Erweiterungsmodul Image" },
/* es */ { IDMES_INVALID_CART_ES, "Imagen de cartucho incorrecta" },
/* fr */ { IDMES_INVALID_CART_FR, "Image de cartouche invalide" },
/* hu */ { IDMES_INVALID_CART_HU, "�rv�nytelen cartridge k�pm�s" },
/* it */ { IDMES_INVALID_CART_IT, "Immagine cartuccia non valida" },
/* ko */ { IDMES_INVALID_CART_KO, "īƮ���� �̹��� ���Ұ�" },
/* nl */ { IDMES_INVALID_CART_NL, "Ongeldig cartridge bestand" },
/* pl */ { IDMES_INVALID_CART_PL, "Nieprawid�owy obraz kartrid�a" },
/* ru */ { IDMES_INVALID_CART_RU, "" },  /* fuzzy */
/* sv */ { IDMES_INVALID_CART_SV, "Ogiltig insticksmodulfil" },
/* tr */ { IDMES_INVALID_CART_TR, "Ge�ersiz kartu� imaj�" },

/* en */ { IDMES_BAD_CART_CONFIG_IN_UI,    "Bad cartridge config in UI!" },
/* da */ { IDMES_BAD_CART_CONFIG_IN_UI_DA, "Ugyldig cartridgekonfiguration i brugergr�nseflade!" },
/* de */ { IDMES_BAD_CART_CONFIG_IN_UI_DE, "Fehlerhafte Modul Konfiguration im UI!" },
/* es */ { IDMES_BAD_CART_CONFIG_IN_UI_ES, "�Configuracion erronea del cartucho en UI!" },
/* fr */ { IDMES_BAD_CART_CONFIG_IN_UI_FR, "Mauvaise configuration de la cartouche dans l'interface utilisateur!" },
/* hu */ { IDMES_BAD_CART_CONFIG_IN_UI_HU, "Rossz cartridge konfigur�ci�!" },
/* it */ { IDMES_BAD_CART_CONFIG_IN_UI_IT, "Configurazione della cartuccia errata nell'IU!" },
/* ko */ { IDMES_BAD_CART_CONFIG_IN_UI_KO, "UI �� �߸��� īƮ������ �ֽ��ϴ�" },
/* nl */ { IDMES_BAD_CART_CONFIG_IN_UI_NL, "Slechte cartridge configuratie in UI!" },
/* pl */ { IDMES_BAD_CART_CONFIG_IN_UI_PL, "Z�a konfiguracja kartrid�a w UI!" },
/* ru */ { IDMES_BAD_CART_CONFIG_IN_UI_RU, "" },  /* fuzzy */
/* sv */ { IDMES_BAD_CART_CONFIG_IN_UI_SV, "Felaktiga insticksmodulsinst�llningar i UI!" },
/* tr */ { IDMES_BAD_CART_CONFIG_IN_UI_TR, "UI'de k�t� kartu� konfig�rasyonu!" },

/* en */ { IDMES_INVALID_CART_IMAGE,    "Invalid cartridge image" },
/* da */ { IDMES_INVALID_CART_IMAGE_DA, "Ugyldigt cartridge-image" },
/* de */ { IDMES_INVALID_CART_IMAGE_DE, "Ung�ltiges Erweiterungsmodul Image" },
/* es */ { IDMES_INVALID_CART_IMAGE_ES, "Imagen de cartucho incorrecta" },
/* fr */ { IDMES_INVALID_CART_IMAGE_FR, "Image de cartouche invalide" },
/* hu */ { IDMES_INVALID_CART_IMAGE_HU, "�rv�nytelen cartridge k�pm�s" },
/* it */ { IDMES_INVALID_CART_IMAGE_IT, "Immagine cartuccia non valida" },
/* ko */ { IDMES_INVALID_CART_IMAGE_KO, "īƮ���� �̹��� ���Ұ�" },
/* nl */ { IDMES_INVALID_CART_IMAGE_NL, "Ongeldig cartridge bestand" },
/* pl */ { IDMES_INVALID_CART_IMAGE_PL, "Nieprawid�owy obraz kartrid�a" },
/* ru */ { IDMES_INVALID_CART_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMES_INVALID_CART_IMAGE_SV, "Ogiltig insticksmodulfil" },
/* tr */ { IDMES_INVALID_CART_IMAGE_TR, "Ge�ersiz kartu� imaj�" },

/* en */ { IDMES_CANNOT_CREATE_IMAGE,    "Cannot create image file!" },
/* da */ { IDMES_CANNOT_CREATE_IMAGE_DA, "Kunne ikke oprette image-fil!" },
/* de */ { IDMES_CANNOT_CREATE_IMAGE_DE, "Kann Imagedatei nicht erzeugen!" },
/* es */ { IDMES_CANNOT_CREATE_IMAGE_ES, "�No puedo crear fichero imagen!" },
/* fr */ { IDMES_CANNOT_CREATE_IMAGE_FR, "Impossible de cr�er le fichier image!" },
/* hu */ { IDMES_CANNOT_CREATE_IMAGE_HU, "Nem siker�lt a k�pm�s f�jlt l�trehozni!" },
/* it */ { IDMES_CANNOT_CREATE_IMAGE_IT, "Non � possibile creare il file immagine!" },
/* ko */ { IDMES_CANNOT_CREATE_IMAGE_KO, "�̹��� ������ �����Ҽ� �����ϴ�!" },
/* nl */ { IDMES_CANNOT_CREATE_IMAGE_NL, "Kan bestand niet maken!" },
/* pl */ { IDMES_CANNOT_CREATE_IMAGE_PL, "Nie mo�na utworzy� pliku obrazu!" },
/* ru */ { IDMES_CANNOT_CREATE_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDMES_CANNOT_CREATE_IMAGE_SV, "Kan inte skapa avbildningsfil!" },
/* tr */ { IDMES_CANNOT_CREATE_IMAGE_TR, "Imaj dosyas� yarat�lamad�!" },

/* en */ { IDMES_ERROR_STARTING_SERVER,    "An error occured starting the server." },
/* da */ { IDMES_ERROR_STARTING_SERVER_DA, "Fejl under start af serveren." },
/* de */ { IDMES_ERROR_STARTING_SERVER_DE, "Fehler beim Starten des Netplay Servers." },
/* es */ { IDMES_ERROR_STARTING_SERVER_ES, "Ha ocurrido error al iniciar el servidor" },
/* fr */ { IDMES_ERROR_STARTING_SERVER_FR, "Il y a eu une erreur au d�marrage du serveur." },
/* hu */ { IDMES_ERROR_STARTING_SERVER_HU, "Hiba t�rt�nt a j�t�k kiszolg�l� ind�t�sakor." },
/* it */ { IDMES_ERROR_STARTING_SERVER_IT, "Si � verificato un errore all'avvio del server." },
/* ko */ { IDMES_ERROR_STARTING_SERVER_KO, "������ �����ϴ��� ������ �߻��߽��ϴ�" },
/* nl */ { IDMES_ERROR_STARTING_SERVER_NL, "Een fout is opgetreden bij het starten van de server." },
/* pl */ { IDMES_ERROR_STARTING_SERVER_PL, "Wyst�pi� b��d poczas uruchamiania serwera." },
/* ru */ { IDMES_ERROR_STARTING_SERVER_RU, "" },  /* fuzzy */
/* sv */ { IDMES_ERROR_STARTING_SERVER_SV, "Fel vid start av servern." },
/* tr */ { IDMES_ERROR_STARTING_SERVER_TR, "Sunucu ba�lat�l�rken bir hata olu�tu." },

/* en */ { IDMES_ERROR_CONNECTING_CLIENT,    "An error occured connecting the client." },
/* da */ { IDMES_ERROR_CONNECTING_CLIENT_DA, "Fejl under tilslutning af klienten." },
/* de */ { IDMES_ERROR_CONNECTING_CLIENT_DE, "Fehler beim Verbindungsaufbau zum Client" },
/* es */ { IDMES_ERROR_CONNECTING_CLIENT_ES, "Ha ocurrido error al conectar el cliente" },
/* fr */ { IDMES_ERROR_CONNECTING_CLIENT_FR, "" },  /* fuzzy */
/* hu */ { IDMES_ERROR_CONNECTING_CLIENT_HU, "Hiba t�rt�nt a kapcsol�d�skor." },
/* it */ { IDMES_ERROR_CONNECTING_CLIENT_IT, "Si � verificato un errore durante il collegamento col client." },
/* ko */ { IDMES_ERROR_CONNECTING_CLIENT_KO, "ũ���̾�Ʈ�� ������ ������ �߻��߽��ϴ�" },
/* nl */ { IDMES_ERROR_CONNECTING_CLIENT_NL, "Een fout is opgetreden bij het verbinden." },
/* pl */ { IDMES_ERROR_CONNECTING_CLIENT_PL, "Wydarzy� si� b��d podczas ��czenia z klientem." },
/* ru */ { IDMES_ERROR_CONNECTING_CLIENT_RU, "" },  /* fuzzy */
/* sv */ { IDMES_ERROR_CONNECTING_CLIENT_SV, "Fel vid anslutning til klienten." },
/* tr */ { IDMES_ERROR_CONNECTING_CLIENT_TR, "�stemciye ba�lan�rken bir hata olu�tu." },

/* en */ { IDMES_INVALID_PORT_NUMBER,    "Invalid port number" },
/* da */ { IDMES_INVALID_PORT_NUMBER_DA, "Ugyldigt portnummer" },
/* de */ { IDMES_INVALID_PORT_NUMBER_DE, "Ung�ltige Port Nummer" },
/* es */ { IDMES_INVALID_PORT_NUMBER_ES, "N�mero de puerto incorrecto" },
/* fr */ { IDMES_INVALID_PORT_NUMBER_FR, "" },  /* fuzzy */
/* hu */ { IDMES_INVALID_PORT_NUMBER_HU, "�rv�nytelen port sz�m" },
/* it */ { IDMES_INVALID_PORT_NUMBER_IT, "Numero di porta non valido" },
/* ko */ { IDMES_INVALID_PORT_NUMBER_KO, "���Ұ����� ��Ʈ �ѹ�" },
/* nl */ { IDMES_INVALID_PORT_NUMBER_NL, "Ongeldig poort nummer" },
/* pl */ { IDMES_INVALID_PORT_NUMBER_PL, "B��dny numer portu" },
/* ru */ { IDMES_INVALID_PORT_NUMBER_RU, "" },  /* fuzzy */
/* sv */ { IDMES_INVALID_PORT_NUMBER_SV, "Ogiltigt portnummer" },
/* tr */ { IDMES_INVALID_PORT_NUMBER_TR, "Ge�ersiz port numaras�" },

/* en */ { IDMES_THIS_MACHINE_NO_SID,    "This machine may not have a SID" },
/* da */ { IDMES_THIS_MACHINE_NO_SID_DA, "Denne maskine kan ikke have en SID" },
/* de */ { IDMES_THIS_MACHINE_NO_SID_DE, "Diese Maschine hat m�glicherweise keinen SID" },
/* es */ { IDMES_THIS_MACHINE_NO_SID_ES, "Esta m�quina dispone de SID" },
/* fr */ { IDMES_THIS_MACHINE_NO_SID_FR, "Cette machine n'a peut-�tre pas de SID" },
/* hu */ { IDMES_THIS_MACHINE_NO_SID_HU, "Ennek a g�pnek nem lehet SIDje" },
/* it */ { IDMES_THIS_MACHINE_NO_SID_IT, "Questa macchina potrebbe non avere un SID" },
/* ko */ { IDMES_THIS_MACHINE_NO_SID_KO, "" },  /* fuzzy */
/* nl */ { IDMES_THIS_MACHINE_NO_SID_NL, "Deze machine heeft mogelijk geen SID" },
/* pl */ { IDMES_THIS_MACHINE_NO_SID_PL, "W tej maszynie mo�e nie by� SID" },
/* ru */ { IDMES_THIS_MACHINE_NO_SID_RU, "" },  /* fuzzy */
/* sv */ { IDMES_THIS_MACHINE_NO_SID_SV, "Denna maskin kan inte ha en SID" },
/* tr */ { IDMES_THIS_MACHINE_NO_SID_TR, "Bu makinede SID olmayabilir" },

/* en */ { IDMES_SCREENSHOT_SAVE_S_FAILED,    "Screenshot save of %s failed" },
/* da */ { IDMES_SCREENSHOT_SAVE_S_FAILED_DA, "Kunne ikke gemme screenshot %s" },
/* de */ { IDMES_SCREENSHOT_SAVE_S_FAILED_DE, "Screenshot speicherung von %s ist fehlgeschlagen" },
/* es */ { IDMES_SCREENSHOT_SAVE_S_FAILED_ES, "Error en la grabaci�n Captura de pantalla %s" },
/* fr */ { IDMES_SCREENSHOT_SAVE_S_FAILED_FR, "" },  /* fuzzy */
/* hu */ { IDMES_SCREENSHOT_SAVE_S_FAILED_HU, "F�nyk�p f�jl ment�se %s f�jlba nem siker�lt" },
/* it */ { IDMES_SCREENSHOT_SAVE_S_FAILED_IT, "Il salvataggio della schermata %s � fallito" },
/* ko */ { IDMES_SCREENSHOT_SAVE_S_FAILED_KO, "" },  /* fuzzy */
/* nl */ { IDMES_SCREENSHOT_SAVE_S_FAILED_NL, "Opslaan schermafdrukbestand %s is mislukt" },
/* pl */ { IDMES_SCREENSHOT_SAVE_S_FAILED_PL, "Zapis zrzutu ekranu %s nie powi�d� si�" },
/* ru */ { IDMES_SCREENSHOT_SAVE_S_FAILED_RU, "" },  /* fuzzy */
/* sv */ { IDMES_SCREENSHOT_SAVE_S_FAILED_SV, "Kunde inte spara sk�rmdump %s" },
/* tr */ { IDMES_SCREENSHOT_SAVE_S_FAILED_TR, "%s ekran g�r�nt�s� kaydedilemedi" },

/* en */ { IDMES_SCREENSHOT_S_SAVED,    "Screenshot %s saved." },
/* da */ { IDMES_SCREENSHOT_S_SAVED_DA, "Screenshot %s gemt." },
/* de */ { IDMES_SCREENSHOT_S_SAVED_DE, "Screenshots %s gespeicher." },
/* es */ { IDMES_SCREENSHOT_S_SAVED_ES, "Captura de pantalla %s grabada." },
/* fr */ { IDMES_SCREENSHOT_S_SAVED_FR, "" },  /* fuzzy */
/* hu */ { IDMES_SCREENSHOT_S_SAVED_HU, "F�nyk�p %s f�jlba elmentve." },
/* it */ { IDMES_SCREENSHOT_S_SAVED_IT, "Schermata %s salvata." },
/* ko */ { IDMES_SCREENSHOT_S_SAVED_KO, "" },  /* fuzzy */
/* nl */ { IDMES_SCREENSHOT_S_SAVED_NL, "Scherm afdruk %s opgeslagen." },
/* pl */ { IDMES_SCREENSHOT_S_SAVED_PL, "Zapisano zrzut ekranu %s." },
/* ru */ { IDMES_SCREENSHOT_S_SAVED_RU, "" },  /* fuzzy */
/* sv */ { IDMES_SCREENSHOT_S_SAVED_SV, "Sk�rmdump %s sparad." },
/* tr */ { IDMES_SCREENSHOT_S_SAVED_TR, "%s ekran g�r�nt�s� kaydedildi." },

/* en */ { IDS_PRESS_KEY_BUTTON,    "Press desired key/button, move stick or press ESC for no key." },
/* da */ { IDS_PRESS_KEY_BUTTON_DA, "Tryk �nsket tast, bev�g joystick eller tryk ESC for ingen binding." },
/* de */ { IDS_PRESS_KEY_BUTTON_DE, "Gew�nschte Taste/Knopf dr�cken, Kn�ppel bewegen oder ESC f�r keine Taste dr�cken." },
/* es */ { IDS_PRESS_KEY_BUTTON_ES, "Pulsa la tecla deseada/bot�n, mueve stick o pulsa ESC para ninguna tecla." },
/* fr */ { IDS_PRESS_KEY_BUTTON_FR, "Appuyez sur la touche/bouton desire(e), d�placez le stick ou appuyez sur ESC pour effacer cette touche." },
/* hu */ { IDS_PRESS_KEY_BUTTON_HU, "Nyomja meg a v�lasztott gombot, mozd�tsa a botkorm�nyt, vagy nyomjon ESC-et �reshez" },
/* it */ { IDS_PRESS_KEY_BUTTON_IT, "Premi il tasto/bottone desiderato, muovi la leva o premi ESC per non selezionare alcun tasto." },
/* ko */ { IDS_PRESS_KEY_BUTTON_KO, "" },  /* fuzzy */
/* nl */ { IDS_PRESS_KEY_BUTTON_NL, "Druk de toets/knop, beweeg de joystick of druk op ESC voor geen toets." },
/* pl */ { IDS_PRESS_KEY_BUTTON_PL, "Wci�nij po��dany klawisz, rusz dr��kiem, albo wci�nij ESC by nie ustawia� klawisza." },
/* ru */ { IDS_PRESS_KEY_BUTTON_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRESS_KEY_BUTTON_SV, "Tryck �nskad tangent/knapp, flytta styrspaken eller tryck ESC f�r att inte koppla n�gon tangent." },
/* tr */ { IDS_PRESS_KEY_BUTTON_TR, "�stenilen tu�/d��meye bas�n, �ubu�u hareket ettirin veya tu� se�memek i�in ESC'e bas�n." },

/* en */ { IDS_SAVE,    "Save" },
/* da */ { IDS_SAVE_DA, "Gem" },
/* de */ { IDS_SAVE_DE, "Speichern" },
/* es */ { IDS_SAVE_ES, "Grabaci�n" },
/* fr */ { IDS_SAVE_FR, "Enregistrer" },
/* hu */ { IDS_SAVE_HU, "Ment�s" },
/* it */ { IDS_SAVE_IT, "Salva" },
/* ko */ { IDS_SAVE_KO, "����" },
/* nl */ { IDS_SAVE_NL, "Opslaan" },
/* pl */ { IDS_SAVE_PL, "Zapisz" },
/* ru */ { IDS_SAVE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_SV, "Spara" },
/* tr */ { IDS_SAVE_TR, "Kaydet" },

/* en */ { IDS_BROWSE,    "Browse" },
/* da */ { IDS_BROWSE_DA, "Gennemse" },
/* de */ { IDS_BROWSE_DE, "St�bern" },
/* es */ { IDS_BROWSE_ES, "Navega" },
/* fr */ { IDS_BROWSE_FR, "Parcourir" },
/* hu */ { IDS_BROWSE_HU, "Tall�z" },
/* it */ { IDS_BROWSE_IT, "Sfoglia" },
/* ko */ { IDS_BROWSE_KO, "���콺" },
/* nl */ { IDS_BROWSE_NL, "Bladeren" },
/* pl */ { IDS_BROWSE_PL, "Przegl�daj" },
/* ru */ { IDS_BROWSE_RU, "" },  /* fuzzy */
/* sv */ { IDS_BROWSE_SV, "Bl�ddra" },
/* tr */ { IDS_BROWSE_TR, "G�z at" },

/* en */ { IDS_CURRENT_MODE,    "Current mode" },
/* da */ { IDS_CURRENT_MODE_DA, "Nuv�rende tilstand" },
/* de */ { IDS_CURRENT_MODE_DE, "Aktueller Modus" },
/* es */ { IDS_CURRENT_MODE_ES, "Modo actual" },
/* fr */ { IDS_CURRENT_MODE_FR, "" },  /* fuzzy */
/* hu */ { IDS_CURRENT_MODE_HU, "Jelenlegi m�d" },
/* it */ { IDS_CURRENT_MODE_IT, "Modalit� attuale" },
/* ko */ { IDS_CURRENT_MODE_KO, "���� ���" },
/* nl */ { IDS_CURRENT_MODE_NL, "Huidige modus" },
/* pl */ { IDS_CURRENT_MODE_PL, "Obecny tryb" },
/* ru */ { IDS_CURRENT_MODE_RU, "" },  /* fuzzy */
/* sv */ { IDS_CURRENT_MODE_SV, "Nuvarande l�ge" },
/* tr */ { IDS_CURRENT_MODE_TR, "Ge�erli mod" },

/* en */ { IDS_TCP_PORT,    "TCP port" },
/* da */ { IDS_TCP_PORT_DA, "TCP-port" },
/* de */ { IDS_TCP_PORT_DE, "TCP Port: " },
/* es */ { IDS_TCP_PORT_ES, "Puerto TCP" },
/* fr */ { IDS_TCP_PORT_FR, "Port TCP" },
/* hu */ { IDS_TCP_PORT_HU, "TCP port" },
/* it */ { IDS_TCP_PORT_IT, "Porta TCP" },
/* ko */ { IDS_TCP_PORT_KO, "TCP ��Ʈ" },
/* nl */ { IDS_TCP_PORT_NL, "TCP poort" },
/* pl */ { IDS_TCP_PORT_PL, "Port TCP" },
/* ru */ { IDS_TCP_PORT_RU, "" },  /* fuzzy */
/* sv */ { IDS_TCP_PORT_SV, "TCP-port" },
/* tr */ { IDS_TCP_PORT_TR, "TCP portu" },

/* en */ { IDS_START_SERVER,    "Start server" },
/* da */ { IDS_START_SERVER_DA, "Start server" },
/* de */ { IDS_START_SERVER_DE, "Server starten" },
/* es */ { IDS_START_SERVER_ES, "Iniciar servidor" },
/* fr */ { IDS_START_SERVER_FR, "D�marrer le serveur" },
/* hu */ { IDS_START_SERVER_HU, "Kiszolg�l� elind�t�sa" },
/* it */ { IDS_START_SERVER_IT, "Avvia server" },
/* ko */ { IDS_START_SERVER_KO, "���� ����" },
/* nl */ { IDS_START_SERVER_NL, "Start server" },
/* pl */ { IDS_START_SERVER_PL, "Uruchom serwer" },
/* ru */ { IDS_START_SERVER_RU, "" },  /* fuzzy */
/* sv */ { IDS_START_SERVER_SV, "Starta server" },
/* tr */ { IDS_START_SERVER_TR, "Sunucuyu ba�lat" },

/* en */ { IDS_SERVER_BIND,    "Server Bind" },
/* da */ { IDS_SERVER_BIND_DA, "Server" },
/* de */ { IDS_SERVER_BIND_DE, "Server Bind" },
/* es */ { IDS_SERVER_BIND_ES, "Server Bind" },
/* fr */ { IDS_SERVER_BIND_FR, "" },  /* fuzzy */
/* hu */ { IDS_SERVER_BIND_HU, "Szerver c�m+port" },
/* it */ { IDS_SERVER_BIND_IT, "Server Bind" },
/* ko */ { IDS_SERVER_BIND_KO, "" },  /* fuzzy */
/* nl */ { IDS_SERVER_BIND_NL, "Server binding" },
/* pl */ { IDS_SERVER_BIND_PL, "Po��czenie serwera" },
/* ru */ { IDS_SERVER_BIND_RU, "" },  /* fuzzy */
/* sv */ { IDS_SERVER_BIND_SV, "Serverbindning" },
/* tr */ { IDS_SERVER_BIND_TR, "Sunucu Ba�lant�s�" },

/* en */ { IDS_CONNECT_TO,    "Connect to" },
/* da */ { IDS_CONNECT_TO_DA, "Tilslut til" },
/* de */ { IDS_CONNECT_TO_DE, "Verbinden mit" },
/* es */ { IDS_CONNECT_TO_ES, "Conectar a" },
/* fr */ { IDS_CONNECT_TO_FR, "Se connecter �" },
/* hu */ { IDS_CONNECT_TO_HU, "Kapcsol�d�s ehhez:" },
/* it */ { IDS_CONNECT_TO_IT, "Connetti a" },
/* ko */ { IDS_CONNECT_TO_KO, "����" },
/* nl */ { IDS_CONNECT_TO_NL, "Maak verbinding naar" },
/* pl */ { IDS_CONNECT_TO_PL, "Po��cz z" },
/* ru */ { IDS_CONNECT_TO_RU, "" },  /* fuzzy */
/* sv */ { IDS_CONNECT_TO_SV, "Anslut till" },
/* tr */ { IDS_CONNECT_TO_TR, "Ba�lan�lan" },

/* en */ { IDS_DISCONNECT,    "Disconnect" },
/* da */ { IDS_DISCONNECT_DA, "Afbryd forbindelse" },
/* de */ { IDS_DISCONNECT_DE, "Verbindung Trennen" },
/* es */ { IDS_DISCONNECT_ES, "Desconectar" },
/* fr */ { IDS_DISCONNECT_FR, "Se d�connecter du serveur" },
/* hu */ { IDS_DISCONNECT_HU, "Sz�tkapcsol�d�s" },
/* it */ { IDS_DISCONNECT_IT, "Disconnetti" },
/* ko */ { IDS_DISCONNECT_KO, "������ ����" },
/* nl */ { IDS_DISCONNECT_NL, "Verbreek verbinding" },
/* pl */ { IDS_DISCONNECT_PL, "Roz��cz" },
/* ru */ { IDS_DISCONNECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_DISCONNECT_SV, "Koppla fr�n" },
/* tr */ { IDS_DISCONNECT_TR, "Ba�lant�y� kes" },

/* en */ { IDS_IDLE,    "Idle" },
/* da */ { IDS_IDLE_DA, "Venter" },
/* de */ { IDS_IDLE_DE, "Idle" },
/* es */ { IDS_IDLE_ES, "Inactivo" },
/* fr */ { IDS_IDLE_FR, "Inactif" },
/* hu */ { IDS_IDLE_HU, "T�tlen" },
/* it */ { IDS_IDLE_IT, "Inattivo" },
/* ko */ { IDS_IDLE_KO, "���������ʴ�" },
/* nl */ { IDS_IDLE_NL, "Idle" },
/* pl */ { IDS_IDLE_PL, "Bezczynny" },
/* ru */ { IDS_IDLE_RU, "" },  /* fuzzy */
/* sv */ { IDS_IDLE_SV, "V�ntar" },
/* tr */ { IDS_IDLE_TR, "Bo�a vakit ge�irme" },

/* en */ { IDS_SERVER_LISTENING,    "Server listening" },
/* da */ { IDS_SERVER_LISTENING_DA, "Server lytter" },
/* de */ { IDS_SERVER_LISTENING_DE, "Server wartet auf Verbindung" },
/* es */ { IDS_SERVER_LISTENING_ES, "Servidor en escucha" },
/* fr */ { IDS_SERVER_LISTENING_FR, "" },  /* fuzzy */
/* hu */ { IDS_SERVER_LISTENING_HU, "V�rakoz�s kliensre" },
/* it */ { IDS_SERVER_LISTENING_IT, "Server in ascolto" },
/* ko */ { IDS_SERVER_LISTENING_KO, "���� ������" },
/* nl */ { IDS_SERVER_LISTENING_NL, "Server wacht op verbinding" },
/* pl */ { IDS_SERVER_LISTENING_PL, "Serwer nas�uchuje" },
/* ru */ { IDS_SERVER_LISTENING_RU, "" },  /* fuzzy */
/* sv */ { IDS_SERVER_LISTENING_SV, "Servern lyssnar" },
/* tr */ { IDS_SERVER_LISTENING_TR, "Sunucu dinleniyor" },

/* en */ { IDS_CONNECTED_SERVER,    "Connected server" },
/* da */ { IDS_CONNECTED_SERVER_DA, "Tilsluttet server" },
/* de */ { IDS_CONNECTED_SERVER_DE, "Server verbunden" },
/* es */ { IDS_CONNECTED_SERVER_ES, "Servidor conectado" },
/* fr */ { IDS_CONNECTED_SERVER_FR, "Connect� au serveur" },
/* hu */ { IDS_CONNECTED_SERVER_HU, "Kapcsol�dva kiszolg�l�hoz" },
/* it */ { IDS_CONNECTED_SERVER_IT, "Server connesso" },
/* ko */ { IDS_CONNECTED_SERVER_KO, "����� ����" },
/* nl */ { IDS_CONNECTED_SERVER_NL, "Verbonden server" },
/* pl */ { IDS_CONNECTED_SERVER_PL, "Po��czony serwer" },
/* ru */ { IDS_CONNECTED_SERVER_RU, "" },  /* fuzzy */
/* sv */ { IDS_CONNECTED_SERVER_SV, "Ansluten server" },
/* tr */ { IDS_CONNECTED_SERVER_TR, "Sunucuya ba�lan�ld�" },

/* en */ { IDS_CONNECTED_CLIENT,    "Connected client" },
/* da */ { IDS_CONNECTED_CLIENT_DA, "Tilsluttet klient" },
/* de */ { IDS_CONNECTED_CLIENT_DE, "Verbunden, Client" },
/* es */ { IDS_CONNECTED_CLIENT_ES, "Cliente conectado" },
/* fr */ { IDS_CONNECTED_CLIENT_FR, "Client connect�" },
/* hu */ { IDS_CONNECTED_CLIENT_HU, "Kapcsol�d� kliens" },
/* it */ { IDS_CONNECTED_CLIENT_IT, "Client connesso" },
/* ko */ { IDS_CONNECTED_CLIENT_KO, "����� Ŭ���̾�Ʈ" },
/* nl */ { IDS_CONNECTED_CLIENT_NL, "Verbonden client" },
/* pl */ { IDS_CONNECTED_CLIENT_PL, "Po��czony klient" },
/* ru */ { IDS_CONNECTED_CLIENT_RU, "" },  /* fuzzy */
/* sv */ { IDS_CONNECTED_CLIENT_SV, "Ansluten klient" },
/* tr */ { IDS_CONNECTED_CLIENT_TR, "Ba�l� istemci" },

/* en */ { IDS_NETPLAY_SETTINGS,    "Netplay Settings" },
/* da */ { IDS_NETPLAY_SETTINGS_DA, "N�tv�rksspilindstillinger" },
/* de */ { IDS_NETPLAY_SETTINGS_DE, "Netplay Einstellungen" },
/* es */ { IDS_NETPLAY_SETTINGS_ES, "Ajustes Netplay" },
/* fr */ { IDS_NETPLAY_SETTINGS_FR, "Param�tres de jeu en r�seau" },
/* hu */ { IDS_NETPLAY_SETTINGS_HU, "H�l�zati j�t�k be�ll�t�sai" },
/* it */ { IDS_NETPLAY_SETTINGS_IT, "Impostazioni Netplay" },
/* ko */ { IDS_NETPLAY_SETTINGS_KO, "���÷��� ����" },
/* nl */ { IDS_NETPLAY_SETTINGS_NL, "Netplay instellingen" },
/* pl */ { IDS_NETPLAY_SETTINGS_PL, "Ustawienia netplay" },
/* ru */ { IDS_NETPLAY_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_NETPLAY_SETTINGS_SV, "Inst�llningar f�r n�tverksspel" },
/* tr */ { IDS_NETPLAY_SETTINGS_TR, "Netplay Ayarlar�" },

/* en */ { IDS_SAVE_SCREENSHOT,    "Save screenshot file" },
/* da */ { IDS_SAVE_SCREENSHOT_DA, "Gem screenshot" },
/* de */ { IDS_SAVE_SCREENSHOT_DE, "Screenshot speichern" },
/* es */ { IDS_SAVE_SCREENSHOT_ES, "Grabar fichero de captura de pantalla" },
/* fr */ { IDS_SAVE_SCREENSHOT_FR, "Enregistrer une capture d'�cran" },
/* hu */ { IDS_SAVE_SCREENSHOT_HU, "F�nyk�p f�jl ment�se" },
/* it */ { IDS_SAVE_SCREENSHOT_IT, "Salva schermata su file" },
/* ko */ { IDS_SAVE_SCREENSHOT_KO, "��ũ���� ���� ����" },
/* nl */ { IDS_SAVE_SCREENSHOT_NL, "Opslaan schermafdrukbestand" },
/* pl */ { IDS_SAVE_SCREENSHOT_PL, "Zapisz plik zrzutu ekranu" },
/* ru */ { IDS_SAVE_SCREENSHOT_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_SCREENSHOT_SV, "Spara sk�rmdump" },
/* tr */ { IDS_SAVE_SCREENSHOT_TR, "Ekran g�r�nt�s� dosyas� kaydet" },

/* en */ { IDS_CANCEL,    "Cancel" },
/* da */ { IDS_CANCEL_DA, "Annull�r" },
/* de */ { IDS_CANCEL_DE, "Abbruch" },
/* es */ { IDS_CANCEL_ES, "Cancelar" },
/* fr */ { IDS_CANCEL_FR, "Annuler" },
/* hu */ { IDS_CANCEL_HU, "M�gsem" },
/* it */ { IDS_CANCEL_IT, "Annulla" },
/* ko */ { IDS_CANCEL_KO, "���" },
/* nl */ { IDS_CANCEL_NL, "Annuleren" },
/* pl */ { IDS_CANCEL_PL, "Anuluj" },
/* ru */ { IDS_CANCEL_RU, "" },  /* fuzzy */
/* sv */ { IDS_CANCEL_SV, "Avbryt" },
/* tr */ { IDS_CANCEL_TR, "�ptal" },

/* en */ { IDS_CHOOSE_SCREENSHOT_FORMAT,    "Choose screenshot format" },
/* da */ { IDS_CHOOSE_SCREENSHOT_FORMAT_DA, "V�lg screenshot format" },
/* de */ { IDS_CHOOSE_SCREENSHOT_FORMAT_DE, "W�hle Screenshot Format" },
/* es */ { IDS_CHOOSE_SCREENSHOT_FORMAT_ES, "Elige formato Captura de pantalla" },
/* fr */ { IDS_CHOOSE_SCREENSHOT_FORMAT_FR, "Chosir le format de capture d'�cran" },
/* hu */ { IDS_CHOOSE_SCREENSHOT_FORMAT_HU, "V�lasszon f�nyk�p form�tumot" },
/* it */ { IDS_CHOOSE_SCREENSHOT_FORMAT_IT, "Seleziona il formato per il salvataggio della schermata" },
/* ko */ { IDS_CHOOSE_SCREENSHOT_FORMAT_KO, "" },  /* fuzzy */
/* nl */ { IDS_CHOOSE_SCREENSHOT_FORMAT_NL, "Kies schermafdrukformaat" },
/* pl */ { IDS_CHOOSE_SCREENSHOT_FORMAT_PL, "Wybierz format zrzutu ekranu" },
/* ru */ { IDS_CHOOSE_SCREENSHOT_FORMAT_RU, "" },  /* fuzzy */
/* sv */ { IDS_CHOOSE_SCREENSHOT_FORMAT_SV, "V�lj format p� sk�rmdump" },
/* tr */ { IDS_CHOOSE_SCREENSHOT_FORMAT_TR, "Ekran g�r�nt�s� bi�imi se�in" },

/* en */ { IDS_SAVE_S_SCREENSHOT,    "Save %s screenshot" },
/* da */ { IDS_SAVE_S_SCREENSHOT_DA, "Gem %s-screenshot" },
/* de */ { IDS_SAVE_S_SCREENSHOT_DE, "Screenshot %s speichern" },
/* es */ { IDS_SAVE_S_SCREENSHOT_ES, "Graba %s Captura de pantalla" },
/* fr */ { IDS_SAVE_S_SCREENSHOT_FR, "Enregistrer une capture d'�cran %s" },
/* hu */ { IDS_SAVE_S_SCREENSHOT_HU, "%s f�nyk�p ment�se" },
/* it */ { IDS_SAVE_S_SCREENSHOT_IT, "Salva schermata %s" },
/* ko */ { IDS_SAVE_S_SCREENSHOT_KO, "" },  /* fuzzy */
/* nl */ { IDS_SAVE_S_SCREENSHOT_NL, "Scherm afdruk %s opslaan" },
/* pl */ { IDS_SAVE_S_SCREENSHOT_PL, "Zapisz zrzut ekranu %s" },
/* ru */ { IDS_SAVE_S_SCREENSHOT_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_S_SCREENSHOT_SV, "Spara %s-sk�rmdump" },
/* tr */ { IDS_SAVE_S_SCREENSHOT_TR, "%s ekran g�r�nt�s�n� kaydet" },

/* en */ { IDS_DETACHED_DEVICE_D,    "Detached device %d" },
/* da */ { IDS_DETACHED_DEVICE_D_DA, "Frakoblet enhed %d" },
/* de */ { IDS_DETACHED_DEVICE_D_DE, "Ger�t %d entfernt" },
/* es */ { IDS_DETACHED_DEVICE_D_ES, "Perif�rico extraido %d" },
/* fr */ { IDS_DETACHED_DEVICE_D_FR, "P�riph�rique d�tach� %d" },
/* hu */ { IDS_DETACHED_DEVICE_D_HU, "%d eszk�z lev�lasztva" },
/* it */ { IDS_DETACHED_DEVICE_D_IT, "Rimosso dispositivo %d" },
/* ko */ { IDS_DETACHED_DEVICE_D_KO, "" },  /* fuzzy */
/* nl */ { IDS_DETACHED_DEVICE_D_NL, "Apparaat %d ontkoppelt" },
/* pl */ { IDS_DETACHED_DEVICE_D_PL, "Od��czono urz�dzenie %d" },
/* ru */ { IDS_DETACHED_DEVICE_D_RU, "" },  /* fuzzy */
/* sv */ { IDS_DETACHED_DEVICE_D_SV, "Kopplade fr�n enhet %d" },
/* tr */ { IDS_DETACHED_DEVICE_D_TR, "��kart�lm�� ayg�t %d" },

/* en */ { IDS_ATTACHED_S_TO_DEVICE_D,    "Attached %s to device#%d" },
/* da */ { IDS_ATTACHED_S_TO_DEVICE_D_DA, "Tilsluttet %s til enhed #%d" },
/* de */ { IDS_ATTACHED_S_TO_DEVICE_D_DE, "%s mit Ger�t#%d verbunden" },
/* es */ { IDS_ATTACHED_S_TO_DEVICE_D_ES, "Insertado %s en perif�rico#%d" },
/* fr */ { IDS_ATTACHED_S_TO_DEVICE_D_FR, "%s attach� au p�riph�rique #%d" },
/* hu */ { IDS_ATTACHED_S_TO_DEVICE_D_HU, "%s csatolva #%d eszk�zh�z" },
/* it */ { IDS_ATTACHED_S_TO_DEVICE_D_IT, "Selezionato %s per la periferica #%d" },
/* ko */ { IDS_ATTACHED_S_TO_DEVICE_D_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACHED_S_TO_DEVICE_D_NL, "%s aan apparaat#%d gekoppelt" },
/* pl */ { IDS_ATTACHED_S_TO_DEVICE_D_PL, "Pod��czono %s pod urz�dzenie#%d" },
/* ru */ { IDS_ATTACHED_S_TO_DEVICE_D_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACHED_S_TO_DEVICE_D_SV, "Ansl�t %s till enhet %d" },
/* tr */ { IDS_ATTACHED_S_TO_DEVICE_D_TR, "%s ayg�t#%d'e ba�lanm��" },

/* en */ { IDS_VICE_QUESTION,    "VICE Question" },
/* da */ { IDS_VICE_QUESTION_DA, "VICE-sp�rgsm�l" },
/* de */ { IDS_VICE_QUESTION_DE, "VICE Frage" },
/* es */ { IDS_VICE_QUESTION_ES, "VICE cuestion" },
/* fr */ { IDS_VICE_QUESTION_FR, "Question VICE" },
/* hu */ { IDS_VICE_QUESTION_HU, "VICE k�rd�s" },
/* it */ { IDS_VICE_QUESTION_IT, "Domanda di VICE" },
/* ko */ { IDS_VICE_QUESTION_KO, "" },  /* fuzzy */
/* nl */ { IDS_VICE_QUESTION_NL, "VICE vraag" },
/* pl */ { IDS_VICE_QUESTION_PL, "Pytanie VICE" },
/* ru */ { IDS_VICE_QUESTION_RU, "" },  /* fuzzy */
/* sv */ { IDS_VICE_QUESTION_SV, "VICE-fr�ga" },
/* tr */ { IDS_VICE_QUESTION_TR, "VICE Sorusu" },

/* en */ { IDS_EXTEND_TO_40_TRACK,    "Extend image to 40-track format?" },
/* da */ { IDS_EXTEND_TO_40_TRACK_DA, "Udvid disk-image til 40 spor?" },
/* de */ { IDS_EXTEND_TO_40_TRACK_DE, "Image Dateu auf 40-Spur Format erweitern?" },
/* es */ { IDS_EXTEND_TO_40_TRACK_ES, "�Imagen extendida a formato 40-tracks?" },
/* fr */ { IDS_EXTEND_TO_40_TRACK_FR, "�tendre l'image au format 40 pistes?" },
/* hu */ { IDS_EXTEND_TO_40_TRACK_HU, "Kiterjesszem a k�pm�st 40 s�vos form�tumra?" },
/* it */ { IDS_EXTEND_TO_40_TRACK_IT, "Estendere l'immagine al formato di 40 tracce?" },
/* ko */ { IDS_EXTEND_TO_40_TRACK_KO, "" },  /* fuzzy */
/* nl */ { IDS_EXTEND_TO_40_TRACK_NL, "Bestand uitbreiden naar 40-sporen formaat?" },
/* pl */ { IDS_EXTEND_TO_40_TRACK_PL, "Rozszerzy� obraz do formatu 40-�cie�kowego?" },
/* ru */ { IDS_EXTEND_TO_40_TRACK_RU, "" },  /* fuzzy */
/* sv */ { IDS_EXTEND_TO_40_TRACK_SV, "Ut�ka avbildning till 40-sp�rsformat?" },
/* tr */ { IDS_EXTEND_TO_40_TRACK_TR, "Imaj 40-track bi�imine geni�letilsin mi?" },

/* en */ { IDS_YES_NO,    "Yes|No" },
/* da */ { IDS_YES_NO_DA, "Ja|Nej" },
/* de */ { IDS_YES_NO_DE, "Ja|Nein" },
/* es */ { IDS_YES_NO_ES, "S�/No" },
/* fr */ { IDS_YES_NO_FR, "Oui|Non" },
/* hu */ { IDS_YES_NO_HU, "Igen|Nem" },
/* it */ { IDS_YES_NO_IT, "S�|No" },
/* ko */ { IDS_YES_NO_KO, "��|�ƴϿ�" },
/* nl */ { IDS_YES_NO_NL, "Ja|Nee" },
/* pl */ { IDS_YES_NO_PL, "Tak|Nie" },
/* ru */ { IDS_YES_NO_RU, "" },  /* fuzzy */
/* sv */ { IDS_YES_NO_SV, "Ja|Nej" },
/* tr */ { IDS_YES_NO_TR, "Evet|Hay�r" },

/* en */ { IDS_DETACHED_TAPE,    "Detached tape" },
/* da */ { IDS_DETACHED_TAPE_DA, "Frakoblet b�nd" },
/* de */ { IDS_DETACHED_TAPE_DE, "Band Image entfernt" },
/* es */ { IDS_DETACHED_TAPE_ES, "Extraer cinta" },
/* fr */ { IDS_DETACHED_TAPE_FR, "Datassette d�tach�" },
/* hu */ { IDS_DETACHED_TAPE_HU, "Szalag lev�lasztva" },
/* it */ { IDS_DETACHED_TAPE_IT, "Cassetta rimossa" },
/* ko */ { IDS_DETACHED_TAPE_KO, "" },  /* fuzzy */
/* nl */ { IDS_DETACHED_TAPE_NL, "Tape ontkoppelt" },
/* pl */ { IDS_DETACHED_TAPE_PL, "Od��czono ta�m�" },
/* ru */ { IDS_DETACHED_TAPE_RU, "" },  /* fuzzy */
/* sv */ { IDS_DETACHED_TAPE_SV, "Kopplade fr�n band" },
/* tr */ { IDS_DETACHED_TAPE_TR, "Teyp ��kart�ld�" },

/* en */ { IDS_ATTACHED_TAPE_S,    "Attached tape %s" },
/* da */ { IDS_ATTACHED_TAPE_S_DA, "Tilsluttet b�nd %s" },
/* de */ { IDS_ATTACHED_TAPE_S_DE, "Band Image %s eingelegt" },
/* es */ { IDS_ATTACHED_TAPE_S_ES, "Cinta insertada %s" },
/* fr */ { IDS_ATTACHED_TAPE_S_FR, "Datassette %s attach�" },
/* hu */ { IDS_ATTACHED_TAPE_S_HU, "%s szalag csatolva" },
/* it */ { IDS_ATTACHED_TAPE_S_IT, "Cassetta %s selezionata" },
/* ko */ { IDS_ATTACHED_TAPE_S_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACHED_TAPE_S_NL, "Tape %s gekoppelt" },
/* pl */ { IDS_ATTACHED_TAPE_S_PL, "Zamontowana ta�ma %s" },
/* ru */ { IDS_ATTACHED_TAPE_S_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACHED_TAPE_S_SV, "Ansl�t band %s" },
/* tr */ { IDS_ATTACHED_TAPE_S_TR, "Yerle�tirilmi� teyp %s" },

/* en */ { IDS_SELECT_START_SNAPSHOT,    "Select start snapshot for event history" },
/* da */ { IDS_SELECT_START_SNAPSHOT_DA, "V�lg start-snapshot for h�ndelseshistorik" },
/* de */ { IDS_SELECT_START_SNAPSHOT_DE, "Startsnapshot f�r Ereignishistory festlegen" },
/* es */ { IDS_SELECT_START_SNAPSHOT_ES, "Selecionar inicio volcado para historial de eventos" },
/* fr */ { IDS_SELECT_START_SNAPSHOT_FR, "S�lectionner l'instantan� de d�part pour l'historique des �v�nements" },
/* hu */ { IDS_SELECT_START_SNAPSHOT_HU, "V�lasszon kezdeti pillanatk�pet az esem�ny r�gz�t�shez" },
/* it */ { IDS_SELECT_START_SNAPSHOT_IT, "Seleziona snapshot iniziale per la cronologia degli eventi" },
/* ko */ { IDS_SELECT_START_SNAPSHOT_KO, "�̺�Ʈ �����丮 �������� ���� ���� �ϼ���" },
/* nl */ { IDS_SELECT_START_SNAPSHOT_NL, "Selecteer start momentopname voor gebeurtenis geschiedenis" },
/* pl */ { IDS_SELECT_START_SNAPSHOT_PL, "Wybierz pocz�tkowy zrzut historii zdarze�" },
/* ru */ { IDS_SELECT_START_SNAPSHOT_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_START_SNAPSHOT_SV, "V�lj start�gonblicksmodul f�r h�ndelsehistorik" },
/* tr */ { IDS_SELECT_START_SNAPSHOT_TR, "Olay tarih�esi i�in ba�lang�� anl�k g�r�nt�s�n� se�" },

/* en */ { IDS_SELECT_END_SNAPSHOT,    "Select end snapshot for event history" },
/* da */ { IDS_SELECT_END_SNAPSHOT_DA, "V�lg slut-snapshot for h�ndelseshistorik" },
/* de */ { IDS_SELECT_END_SNAPSHOT_DE, "Startsnapshot f�r Ereignishistory festlegen" },
/* es */ { IDS_SELECT_END_SNAPSHOT_ES, "Seleccionar fin volcado para historial de eventos" },
/* fr */ { IDS_SELECT_END_SNAPSHOT_FR, "S�lectionner l'instantan� de d�part pour l'historique des �v�nements" },
/* hu */ { IDS_SELECT_END_SNAPSHOT_HU, "V�lasszon v�gs� pillanatk�pet az esem�ny r�gz�t�shez" },
/* it */ { IDS_SELECT_END_SNAPSHOT_IT, "Seleziona snapshot finale per la cronologia degli eventi" },
/* ko */ { IDS_SELECT_END_SNAPSHOT_KO, "�̺�Ʈ �����丮 �������� ���� ���� �ϼ���" },
/* nl */ { IDS_SELECT_END_SNAPSHOT_NL, "Selecteer eind momentopname voor gebeurtenis geschiedenis" },
/* pl */ { IDS_SELECT_END_SNAPSHOT_PL, "Wybierz ko�cowy zrzut historii zdarze�" },
/* ru */ { IDS_SELECT_END_SNAPSHOT_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_END_SNAPSHOT_SV, "V�lj slut�gonblicksbild f�r h�ndelsehistorik" },
/* tr */ { IDS_SELECT_END_SNAPSHOT_TR, "Olay tarih�esi i�in biti� anl�k g�r�nt�s�n� se�" },

/* en */ { IDS_REALLY_EXIT,    "Do you really want to exit?\n\nAll the data present in the emulated RAM will be lost." },
/* da */ { IDS_REALLY_EXIT_DA, "Vil du virkelig afslutte?\n\nAlle data i emuleret RAM g�r tabt." },
/* de */ { IDS_REALLY_EXIT_DE, "Willst Du wirklich beenden?\nDaten im emulierten Speicher RAM gehen verloren." },
/* es */ { IDS_REALLY_EXIT_ES, "�Realmente quieres salir?\n\nSe perder�n todos los datos presentes en la RAM emulada." },
/* fr */ { IDS_REALLY_EXIT_FR, "D�sirez-vous vraiment quitter?\n\nToutes les donn�es pr�sentes dans la m�moire de l'�mulateur seront perdues." },
/* hu */ { IDS_REALLY_EXIT_HU, "Biztosan kil�p?\n\nAz emul�lt mem�ria teljes tartalma el fog veszni." },
/* it */ { IDS_REALLY_EXIT_IT, "Uscire davvero?\n\nTutti i dati presenti nella RAM emulata saranno persi." },
/* ko */ { IDS_REALLY_EXIT_KO, "" },  /* fuzzy */
/* nl */ { IDS_REALLY_EXIT_NL, "Wilt U echt afsluiten?\n\nAlle data in ge�muleerd geheugen zal verloren gaan." },
/* pl */ { IDS_REALLY_EXIT_PL, "Na pewno wyj��?\n\nWszystkie dane w emulowanym RAM-ie zostan� utracone." },
/* ru */ { IDS_REALLY_EXIT_RU, "" },  /* fuzzy */
/* sv */ { IDS_REALLY_EXIT_SV, "Vill du verkligen avsluta?\n\nAlla data i emulerat RAM kommer f�rloras." },
/* tr */ { IDS_REALLY_EXIT_TR, "��kmak istedi�inizden emin misiniz?\n\nEm�le edilmi� RAM'de bulunan mevcut t�m veri kaybedilecektir." },

/* en */ { IDS_ATTACH_CRT_IMAGE,    "Attach CRT cartridge image" },
/* da */ { IDS_ATTACH_CRT_IMAGE_DA, "Tilslut CRT-cartridge image" },
/* de */ { IDS_ATTACH_CRT_IMAGE_DE, "CRT Erweiterungsmodul Image einlegen" },
/* es */ { IDS_ATTACH_CRT_IMAGE_ES, "Insertar imagen de cartucho CRT" },
/* fr */ { IDS_ATTACH_CRT_IMAGE_FR, "Ins�rer une cartouche CRT" },
/* hu */ { IDS_ATTACH_CRT_IMAGE_HU, "CRT cartridge k�pm�s csatol�sa" },
/* it */ { IDS_ATTACH_CRT_IMAGE_IT, "Seleziona immagine cartuccia CRT" },
/* ko */ { IDS_ATTACH_CRT_IMAGE_KO, "CRT īƮ���� �̹����� �ٿ������ÿ�" },
/* nl */ { IDS_ATTACH_CRT_IMAGE_NL, "Koppel CRT cartridge bestand aan" },
/* pl */ { IDS_ATTACH_CRT_IMAGE_PL, "Zamontuj obraz kartrid�a CRT" },
/* ru */ { IDS_ATTACH_CRT_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_CRT_IMAGE_SV, "Anslut CRT-insticksmodulfil" },
/* tr */ { IDS_ATTACH_CRT_IMAGE_TR, "CRT kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_RAW_8KB_IMAGE,    "Attach raw 8KB cartridge image" },
/* da */ { IDS_ATTACH_RAW_8KB_IMAGE_DA, "Tilslut r�t 8KB-cartridge image" },
/* de */ { IDS_ATTACH_RAW_8KB_IMAGE_DE, "8KB Erweiterungsmodul (raw) Image einlegen" },
/* es */ { IDS_ATTACH_RAW_8KB_IMAGE_ES, "Insertar imagen de cartucho 8KB" },
/* fr */ { IDS_ATTACH_RAW_8KB_IMAGE_FR, "Ins�rer une cartouche 8KO" },
/* hu */ { IDS_ATTACH_RAW_8KB_IMAGE_HU, "Nyers 8KB-os cartridge k�pm�s csatol�sa" },
/* it */ { IDS_ATTACH_RAW_8KB_IMAGE_IT, "Seleziona immagine cartuccia di 8KB" },
/* ko */ { IDS_ATTACH_RAW_8KB_IMAGE_KO, "8kb īƮ���� �̹����� ���̼���" },
/* nl */ { IDS_ATTACH_RAW_8KB_IMAGE_NL, "Koppel binair 8KB cartridge bestand" },
/* pl */ { IDS_ATTACH_RAW_8KB_IMAGE_PL, "Zamontuj surowy obraz kartrid�a 8KB" },
/* ru */ { IDS_ATTACH_RAW_8KB_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_RAW_8KB_IMAGE_SV, "Anslut r� 8KB-insticksmodulavbilding" },
/* tr */ { IDS_ATTACH_RAW_8KB_IMAGE_TR, "D�z 8KB kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_RAW_16KB_IMAGE,    "Attach raw 16KB cartridge image" },
/* da */ { IDS_ATTACH_RAW_16KB_IMAGE_DA, "Tilslut r�t 16KB-cartridge image" },
/* de */ { IDS_ATTACH_RAW_16KB_IMAGE_DE, "16KB Erweiterungsmodul (raw) Image einlegen" },
/* es */ { IDS_ATTACH_RAW_16KB_IMAGE_ES, "Insertar imagen de cartucho 16KB" },
/* fr */ { IDS_ATTACH_RAW_16KB_IMAGE_FR, "Ins�rer une cartouche 16KO" },
/* hu */ { IDS_ATTACH_RAW_16KB_IMAGE_HU, "Nyers 16KB-os cartridge k�pm�s csatol�sa" },
/* it */ { IDS_ATTACH_RAW_16KB_IMAGE_IT, "Seleziona immagine cartuccia di 16KB" },
/* ko */ { IDS_ATTACH_RAW_16KB_IMAGE_KO, "16kb īƮ���� �̹����� ���̼���" },
/* nl */ { IDS_ATTACH_RAW_16KB_IMAGE_NL, "Koppel binair 16KB cartridge bestand" },
/* pl */ { IDS_ATTACH_RAW_16KB_IMAGE_PL, "Zamontuj surowy obraz kartrid�a 16KB" },
/* ru */ { IDS_ATTACH_RAW_16KB_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_RAW_16KB_IMAGE_SV, "Anslut r� 16KB-insticksmodulavbilding" },
/* tr */ { IDS_ATTACH_RAW_16KB_IMAGE_TR, "D�z 16KB kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_ACTION_REPLAY_IMAGE,    "Attach raw 32KB Action Replay cartridge image" },
/* da */ { IDS_ATTACH_ACTION_REPLAY_IMAGE_DA, "Tilslut r�t 32KB Action Replay cartridge image" },
/* de */ { IDS_ATTACH_ACTION_REPLAY_IMAGE_DE, "32kB Action Replay Image (raw) einlegen" },
/* es */ { IDS_ATTACH_ACTION_REPLAY_IMAGE_ES, "Insertar imagen cartucho Action Replay 32KB" },
/* fr */ { IDS_ATTACH_ACTION_REPLAY_IMAGE_FR, "Ins�rer une cartouche Action Replay 32KO" },
/* hu */ { IDS_ATTACH_ACTION_REPLAY_IMAGE_HU, "32KB-os Action Replay cartridge k�pm�s csatol�sa" },
/* it */ { IDS_ATTACH_ACTION_REPLAY_IMAGE_IT, "Seleziona immagine cartuccia Action Replay di 32KB" },
/* ko */ { IDS_ATTACH_ACTION_REPLAY_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACH_ACTION_REPLAY_IMAGE_NL, "Koppel binair 32KB Action Replay cartridge bestand" },
/* pl */ { IDS_ATTACH_ACTION_REPLAY_IMAGE_PL, "Zamontuj surowy obraz kartid�a 32KB Action Replay" },
/* ru */ { IDS_ATTACH_ACTION_REPLAY_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_ACTION_REPLAY_IMAGE_SV, "Anslut r� 32KB-Action Replay-insticksmodulfil" },
/* tr */ { IDS_ATTACH_ACTION_REPLAY_IMAGE_TR, "D�z 32KB Action Replay kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_ACTION_REPLAY3_IMAGE,    "Attach raw 16KB Action Replay MK3 cartridge image" },
/* da */ { IDS_ATTACH_ACTION_REPLAY3_IMAGE_DA, "Tilslut r�t 16KB Action Replay MK3 cartridge image" },
/* de */ { IDS_ATTACH_ACTION_REPLAY3_IMAGE_DE, "16kB Action Replay MK3 Image (raw) einlegen" },
/* es */ { IDS_ATTACH_ACTION_REPLAY3_IMAGE_ES, "Insertar imagen cartucho Action Replay MK3 16KB" },
/* fr */ { IDS_ATTACH_ACTION_REPLAY3_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDS_ATTACH_ACTION_REPLAY3_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDS_ATTACH_ACTION_REPLAY3_IMAGE_IT, "Seleziona immagine cartuccia Action Replay MK3 di 16KB" },
/* ko */ { IDS_ATTACH_ACTION_REPLAY3_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACH_ACTION_REPLAY3_IMAGE_NL, "Koppel binair 16KB Action Replay MK3 cartridge bestand" },
/* pl */ { IDS_ATTACH_ACTION_REPLAY3_IMAGE_PL, "Zamontuj surowy obraz kartrid�a 16KB Action Replay MK3" },
/* ru */ { IDS_ATTACH_ACTION_REPLAY3_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_ACTION_REPLAY3_IMAGE_SV, "Anslut r� 16KB-Action Replay MK3-insticksmodulfil" },
/* tr */ { IDS_ATTACH_ACTION_REPLAY3_IMAGE_TR, "D�z 16KB Action Replay MK3 kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_ACTION_REPLAY4_IMAGE,    "Attach raw 32KB Action Replay MK4 cartridge image" },
/* da */ { IDS_ATTACH_ACTION_REPLAY4_IMAGE_DA, "Tilslut r�t 32KB Action Replay MK4 cartridge image" },
/* de */ { IDS_ATTACH_ACTION_REPLAY4_IMAGE_DE, "32kB Action Replay MK4 Image einlegen" },
/* es */ { IDS_ATTACH_ACTION_REPLAY4_IMAGE_ES, "Insertar imagen cartucho Action Replay MK4 32KB" },
/* fr */ { IDS_ATTACH_ACTION_REPLAY4_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDS_ATTACH_ACTION_REPLAY4_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDS_ATTACH_ACTION_REPLAY4_IMAGE_IT, "Seleziona immagine cartuccia Action Replay MK4 di 326KB" },
/* ko */ { IDS_ATTACH_ACTION_REPLAY4_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACH_ACTION_REPLAY4_IMAGE_NL, "Koppel binair 32KB Action Replay MK4 cartridge bestand" },
/* pl */ { IDS_ATTACH_ACTION_REPLAY4_IMAGE_PL, "Zamontuj surowy obraz kartrid�a 32KB Action Replay MK4" },
/* ru */ { IDS_ATTACH_ACTION_REPLAY4_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_ACTION_REPLAY4_IMAGE_SV, "Anslut r� 32KB-Action Replay MK4-insticksmodulfil" },
/* tr */ { IDS_ATTACH_ACTION_REPLAY4_IMAGE_TR, "D�z 32KB Action Replay MK4 kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_STARDOS_IMAGE,    "Attach raw 16KB Stardos cartridge image" },
/* da */ { IDS_ATTACH_STARDOS_IMAGE_DA, "Tilslut r�t 16KB StarDOS cartridge image" },
/* de */ { IDS_ATTACH_STARDOS_IMAGE_DE, "16kB Stardos Erweiterungsmodul Image (raw) einlegen" },
/* es */ { IDS_ATTACH_STARDOS_IMAGE_ES, "Insertar imagen cartucho Stardos 16KB" },
/* fr */ { IDS_ATTACH_STARDOS_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDS_ATTACH_STARDOS_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDS_ATTACH_STARDOS_IMAGE_IT, "Seleziona immagine cartuccia Stardos di 16KB" },
/* ko */ { IDS_ATTACH_STARDOS_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACH_STARDOS_IMAGE_NL, "Koppel binair 16KB Stardos cartridge bestand" },
/* pl */ { IDS_ATTACH_STARDOS_IMAGE_PL, "Zamontuj surowy obraz kartrid�a 16KB Stardos" },
/* ru */ { IDS_ATTACH_STARDOS_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_STARDOS_IMAGE_SV, "Anslut r� 16KB Stardos-insticksmodulfil" },
/* tr */ { IDS_ATTACH_STARDOS_IMAGE_TR, "D�z 16KB Stardos kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_ATOMIC_POWER_IMAGE,    "Attach raw 32KB Atomic Power cartridge image" },
/* da */ { IDS_ATTACH_ATOMIC_POWER_IMAGE_DA, "Tilslut r�t 32KB Atomic Power-cartridge image" },
/* de */ { IDS_ATTACH_ATOMIC_POWER_IMAGE_DE, "32kB Atomic Power Image einlegen" },
/* es */ { IDS_ATTACH_ATOMIC_POWER_IMAGE_ES, "Insertar imagen cartucho Atomic Power 32KB" },
/* fr */ { IDS_ATTACH_ATOMIC_POWER_IMAGE_FR, "Ins�rer une cartouche Atomic Power 32KO" },
/* hu */ { IDS_ATTACH_ATOMIC_POWER_IMAGE_HU, "32KB-os Atomic Power cartridge k�pm�s csatol�sa" },
/* it */ { IDS_ATTACH_ATOMIC_POWER_IMAGE_IT, "Seleziona immagine cartuccia Atomic Power di 32KB" },
/* ko */ { IDS_ATTACH_ATOMIC_POWER_IMAGE_KO, "32kb Atomic Power īƮ���� �̹����� ���̼���" },
/* nl */ { IDS_ATTACH_ATOMIC_POWER_IMAGE_NL, "Koppel binair 32KB Atomic Power cartridge bestand" },
/* pl */ { IDS_ATTACH_ATOMIC_POWER_IMAGE_PL, "Zamontuj surowy obraz kartrid�a 32KB Atomic Power" },
/* ru */ { IDS_ATTACH_ATOMIC_POWER_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_ATOMIC_POWER_IMAGE_SV, "Anslut r� 32KB Atomic Power-insticksmodulfil" },
/* tr */ { IDS_ATTACH_ATOMIC_POWER_IMAGE_TR, "D�z 32KB Atomic Power kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_EPYX_FASTLOAD_IMAGE,    "Attach raw 8KB Epyx FastLoad cartridge image" },
/* da */ { IDS_ATTACH_EPYX_FASTLOAD_IMAGE_DA, "Tilslut r�t 8KB Epyx FastLoad cartridge image" },
/* de */ { IDS_ATTACH_EPYX_FASTLOAD_IMAGE_DE, "8kB Epyx Fastload Image (raw) einlegen" },
/* es */ { IDS_ATTACH_EPYX_FASTLOAD_IMAGE_ES, "Insertar imagen cartucho Epyx Fastload 8KB" },
/* fr */ { IDS_ATTACH_EPYX_FASTLOAD_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDS_ATTACH_EPYX_FASTLOAD_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDS_ATTACH_EPYX_FASTLOAD_IMAGE_IT, "Seleziona immagine cartuccia Epyx FastLoad di 8KB" },
/* ko */ { IDS_ATTACH_EPYX_FASTLOAD_IMAGE_KO, "8kb Epyx FastLoad īƮ���� �̹����� ���̼���" },
/* nl */ { IDS_ATTACH_EPYX_FASTLOAD_IMAGE_NL, "Koppel binair 8KB Epyx FastLoad cartridge bestand" },
/* pl */ { IDS_ATTACH_EPYX_FASTLOAD_IMAGE_PL, "Zamontuj obraz kartrid�a 8KB Epyx FastLoad" },
/* ru */ { IDS_ATTACH_EPYX_FASTLOAD_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_EPYX_FASTLOAD_IMAGE_SV, "Anslut r� 8KB Epyx FastLoad-insticksmodulfil" },
/* tr */ { IDS_ATTACH_EPYX_FASTLOAD_IMAGE_TR, "D�z 8KB Epyx FastLoad kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_IEEE488_IMAGE,    "Attach IEEE-488 Interface cartridge image" },
/* da */ { IDS_ATTACH_IEEE488_IMAGE_DA, "Tilslut IEEE-488 interface cartridge image" },
/* de */ { IDS_ATTACH_IEEE488_IMAGE_DE, "IEEE Schnittstellen Erweiterungsmodul Image einlegen" },
/* es */ { IDS_ATTACH_IEEE488_IMAGE_ES, "Insertar imagen de cartucho Interface IEEE-488" },
/* fr */ { IDS_ATTACH_IEEE488_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDS_ATTACH_IEEE488_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDS_ATTACH_IEEE488_IMAGE_IT, "Seleziona immagine cartuccia interfaccia IEEE" },
/* ko */ { IDS_ATTACH_IEEE488_IMAGE_KO, "IEEE-488 �������̽� īƮ���� �̹����� �ٿ���������" },
/* nl */ { IDS_ATTACH_IEEE488_IMAGE_NL, "Koppel IEEE-488 Interface cartridge bestand" },
/* pl */ { IDS_ATTACH_IEEE488_IMAGE_PL, "Zamontuj obraz kartrid�a IEEE-488 Interface" },
/* ru */ { IDS_ATTACH_IEEE488_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_IEEE488_IMAGE_SV, "Anslut IEEE-488-gr�nssnittsavbildningsfil" },
/* tr */ { IDS_ATTACH_IEEE488_IMAGE_TR, "IEEE-488 Arabirimi kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_RETRO_REPLAY_IMAGE,    "Attach raw 64KB Retro Replay cartridge image" },
/* da */ { IDS_ATTACH_RETRO_REPLAY_IMAGE_DA, "Tilslut r�t 64KB-Retro Replay-cartridge image" },
/* de */ { IDS_ATTACH_RETRO_REPLAY_IMAGE_DE, "64kB Retro Replay Image einlegen" },
/* es */ { IDS_ATTACH_RETRO_REPLAY_IMAGE_ES, "Insertar imagen cartucho Retro Replay 64KB" },
/* fr */ { IDS_ATTACH_RETRO_REPLAY_IMAGE_FR, "Ins�rer une cartouche Retro Replay 64KO" },
/* hu */ { IDS_ATTACH_RETRO_REPLAY_IMAGE_HU, "64KB-os Retro Replay cartridge k�pm�s csatol�sa" },
/* it */ { IDS_ATTACH_RETRO_REPLAY_IMAGE_IT, "Seleziona immagine cartuccia Retro Replay di 64KB" },
/* ko */ { IDS_ATTACH_RETRO_REPLAY_IMAGE_KO, "64KB Retro Replay īƮ���� �̹����� ���̼���" },
/* nl */ { IDS_ATTACH_RETRO_REPLAY_IMAGE_NL, "Koppel binair 64KB Retro Replay cartridge bestand" },
/* pl */ { IDS_ATTACH_RETRO_REPLAY_IMAGE_PL, "Zamontuj surowy obraz kartrid�a 64KB Retro Replay" },
/* ru */ { IDS_ATTACH_RETRO_REPLAY_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_RETRO_REPLAY_IMAGE_SV, "Anslut r� 64KB-Retro Replay-insticksmodulfil" },
/* tr */ { IDS_ATTACH_RETRO_REPLAY_IMAGE_TR, "D�z 64KB Retro Replay kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_IDE64_IMAGE,    "Attach raw 64KB IDE64 cartridge image" },
/* da */ { IDS_ATTACH_IDE64_IMAGE_DA, "Tilslut r�t 64KB IDE64-cartridge image" },
/* de */ { IDS_ATTACH_IDE64_IMAGE_DE, "64kB IDE64 Image einlegen" },
/* es */ { IDS_ATTACH_IDE64_IMAGE_ES, "Insertar imagen cartucho IDE64 64KB" },
/* fr */ { IDS_ATTACH_IDE64_IMAGE_FR, "Ins�rer une cartouche IDE64 64KO" },
/* hu */ { IDS_ATTACH_IDE64_IMAGE_HU, "64KB-os IDE64 cartridge k�pm�s csatol�sa" },
/* it */ { IDS_ATTACH_IDE64_IMAGE_IT, "Seleziona immagine cartuccia IDE64 di 64KB" },
/* ko */ { IDS_ATTACH_IDE64_IMAGE_KO, "64kb IDE64 īƮ���� �̹����� ���̼���" },
/* nl */ { IDS_ATTACH_IDE64_IMAGE_NL, "Koppel binair 64KB IDE64 cartridge bestand" },
/* pl */ { IDS_ATTACH_IDE64_IMAGE_PL, "Zamontuj surowy obraz kartrid�a 64KB IDE64" },
/* ru */ { IDS_ATTACH_IDE64_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_IDE64_IMAGE_SV, "Anslut r� 64KB IDE64-insticksmodulfil" },
/* tr */ { IDS_ATTACH_IDE64_IMAGE_TR, "D�z 64KB IDE64 kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_SS4_IMAGE,    "Attach raw 32KB Super Snapshot V4 cartridge image" },
/* da */ { IDS_ATTACH_SS4_IMAGE_DA, "Tilslut r�t 32KB Super Snapshot V4 cartridge image" },
/* de */ { IDS_ATTACH_SS4_IMAGE_DE, "32kB Super Snapshot V4 Image (raw) einlegen" },
/* es */ { IDS_ATTACH_SS4_IMAGE_ES, "Insertar imagen cartucho Super Snapshot V4 32KB" },
/* fr */ { IDS_ATTACH_SS4_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDS_ATTACH_SS4_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDS_ATTACH_SS4_IMAGE_IT, "Seleziona immagine cartuccia Super Snapshot V4 di 32KB" },
/* ko */ { IDS_ATTACH_SS4_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACH_SS4_IMAGE_NL, "Koppel binair 32KB Super Snapshot V4 cartridge bestand" },
/* pl */ { IDS_ATTACH_SS4_IMAGE_PL, "Zamontuj surowy obraz kartrid�a 32KB Super Snapshot V4" },
/* ru */ { IDS_ATTACH_SS4_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_SS4_IMAGE_SV, "Anslut r� 32KB Super Snapshot V4-insticksmodulfil" },
/* tr */ { IDS_ATTACH_SS4_IMAGE_TR, "D�z 32KB Super Snapshot V4 kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_SS5_IMAGE,    "Attach raw 64KB Super Snapshot V5 cartridge image" },
/* da */ { IDS_ATTACH_SS5_IMAGE_DA, "Tilslut r�t 64KB Super Snapshot V5 cartridge image" },
/* de */ { IDS_ATTACH_SS5_IMAGE_DE, "64kB Super Snapshot V5 Image (raw) einlegen" },
/* es */ { IDS_ATTACH_SS5_IMAGE_ES, "Insertar imagen cartucho Super Snapshot V5 64KB" },
/* fr */ { IDS_ATTACH_SS5_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDS_ATTACH_SS5_IMAGE_HU, "" },  /* fuzzy */
/* it */ { IDS_ATTACH_SS5_IMAGE_IT, "Seleziona immagine cartuccia Super Snapshot V5 di 64KB" },
/* ko */ { IDS_ATTACH_SS5_IMAGE_KO, "64KB Super Snapshot V5 īƮ���� �̹����� ���̼���" },
/* nl */ { IDS_ATTACH_SS5_IMAGE_NL, "Koppel binair 64KB Super Snapshot V5 cartridge bestand" },
/* pl */ { IDS_ATTACH_SS5_IMAGE_PL, "Zamontuj surowy obraz kartrid�a Super Snapshot V5" },
/* ru */ { IDS_ATTACH_SS5_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_SS5_IMAGE_SV, "Anslut r� 64KB-Super Snapshot V5-insticksmodulfil" },
/* tr */ { IDS_ATTACH_SS5_IMAGE_TR, "D�z 64KB Super Snapshot V5 kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_SB_IMAGE,    "Attach raw Structured Basic cartridge image" },
/* da */ { IDS_ATTACH_SB_IMAGE_DA, "Tilslut r� Strucured BASIC-cartridge image" },
/* de */ { IDS_ATTACH_SB_IMAGE_DE, "Erweiterungsmodul Structured Basic (raw) Image einlegen" },
/* es */ { IDS_ATTACH_SB_IMAGE_ES, "Insertar imagen cartucho Structured Basic" },
/* fr */ { IDS_ATTACH_SB_IMAGE_FR, "Ins�rer une cartouche Raw Structured Basic" },
/* hu */ { IDS_ATTACH_SB_IMAGE_HU, "Structured Basic cartridge k�pm�s csatol�sa" },
/* it */ { IDS_ATTACH_SB_IMAGE_IT, "Seleziona immagine cartuccia Structured Basic" },
/* ko */ { IDS_ATTACH_SB_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACH_SB_IMAGE_NL, "Koppel binair Structured Basic cartridge bestand aan" },
/* pl */ { IDS_ATTACH_SB_IMAGE_PL, "Zamontuj surowy obraz kartrid�a Structured Basic" },
/* ru */ { IDS_ATTACH_SB_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_SB_IMAGE_SV, "Anslut r� Strucured Basic-insticksmodulfil" },
/* tr */ { IDS_ATTACH_SB_IMAGE_TR, "D�z yap�land�r�lm�� Basic kartu� imaj� yerle�tir" },

/* en */ { IDS_AVAILABLE_CMDLINE_OPTIONS,    "\nAvailable command-line options:\n\n" },
/* da */ { IDS_AVAILABLE_CMDLINE_OPTIONS_DA, "\nMulige kommandolinjeparametre:\n\n" },
/* de */ { IDS_AVAILABLE_CMDLINE_OPTIONS_DE, "\nZul�ssige Kommandozeilen Optionen:\n\n" },
/* es */ { IDS_AVAILABLE_CMDLINE_OPTIONS_ES, "\nOpciones de comando disponibles:\n\n" },
/* fr */ { IDS_AVAILABLE_CMDLINE_OPTIONS_FR, "\nOptions de ligne de commande disponibles:\n\n" },
/* hu */ { IDS_AVAILABLE_CMDLINE_OPTIONS_HU, "\nLehets�ges parancssori opci�k:\n\n" },
/* it */ { IDS_AVAILABLE_CMDLINE_OPTIONS_IT, "\nOpzioni disponibili da riga di comando:\n\n" },
/* ko */ { IDS_AVAILABLE_CMDLINE_OPTIONS_KO, "\n��밡���� Ŀ�ǵ� ���� �ɼ�:\n\n" },
/* nl */ { IDS_AVAILABLE_CMDLINE_OPTIONS_NL, "\nBeschikbare command-line opties:\n\n" },
/* pl */ { IDS_AVAILABLE_CMDLINE_OPTIONS_PL, "\nDost�pne opcje wiersza polece�:\n\n" },
/* ru */ { IDS_AVAILABLE_CMDLINE_OPTIONS_RU, "" },  /* fuzzy */
/* sv */ { IDS_AVAILABLE_CMDLINE_OPTIONS_SV, "\nTillg�ngliga kommandoradsflaggor:\n\n" },
/* tr */ { IDS_AVAILABLE_CMDLINE_OPTIONS_TR, "\nMevcut komut sat�r� se�enekleri:\n\n" },

/* en */ { IDS_ATTACH_4_8_16KB_AT_2000,    "Attach 4/8/16KB cartridge image at $2000" },
/* da */ { IDS_ATTACH_4_8_16KB_AT_2000_DA, "Tilslut 4/8/16KB-cartridge image p� $2000" },
/* de */ { IDS_ATTACH_4_8_16KB_AT_2000_DE, "4/8/16KB Modul Image bei $2000 einlegen" },
/* es */ { IDS_ATTACH_4_8_16KB_AT_2000_ES, "Insertar 4/8/16KB imagen cartucho en $2000" },
/* fr */ { IDS_ATTACH_4_8_16KB_AT_2000_FR, "Insertion d'une image 4/8/16Ko � $2000" },
/* hu */ { IDS_ATTACH_4_8_16KB_AT_2000_HU, "4/8/16KB k�pm�s csatol�sa $2000 c�mre" },
/* it */ { IDS_ATTACH_4_8_16KB_AT_2000_IT, "Seleziona immagine cartuccia di 4/8/16KB a $2000" },
/* ko */ { IDS_ATTACH_4_8_16KB_AT_2000_KO, "4/8/16KB īƮ���� �̹��� ��  $2000 �� ���̱�" },
/* nl */ { IDS_ATTACH_4_8_16KB_AT_2000_NL, "Koppel 4/8/16KB bestand op $2000" },
/* pl */ { IDS_ATTACH_4_8_16KB_AT_2000_PL, "Wsu� 4/8/16KB obraz w $2000" },
/* ru */ { IDS_ATTACH_4_8_16KB_AT_2000_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_4_8_16KB_AT_2000_SV, "Anslut 4/8/16KB-modulfil vid $2000" },
/* tr */ { IDS_ATTACH_4_8_16KB_AT_2000_TR, "$2000 adresine 4/8/16KB kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_4_8_16KB_AT_4000,    "Attach 4/8/16KB cartridge image at $4000" },
/* da */ { IDS_ATTACH_4_8_16KB_AT_4000_DA, "Tilslut 4/8/16KB-cartridge image p� $4000" },
/* de */ { IDS_ATTACH_4_8_16KB_AT_4000_DE, "4/8/16KB Modul Image bei $4000 einlegen" },
/* es */ { IDS_ATTACH_4_8_16KB_AT_4000_ES, "Insertar 4/8/16KB imagen cartucho en $4000" },
/* fr */ { IDS_ATTACH_4_8_16KB_AT_4000_FR, "Insertion d'une image 4/8/16Ko � $4000" },
/* hu */ { IDS_ATTACH_4_8_16KB_AT_4000_HU, "4/8/16KB k�pm�s csatol�sa $4000 c�mre" },
/* it */ { IDS_ATTACH_4_8_16KB_AT_4000_IT, "Seleziona immagine cartuccia di 4/8/16KB a $4000" },
/* ko */ { IDS_ATTACH_4_8_16KB_AT_4000_KO, "4/8/16KB īƮ���� �̹��� ��  $4000 �� ���̱�" },
/* nl */ { IDS_ATTACH_4_8_16KB_AT_4000_NL, "Koppel 4/8/16KB bestand op $4000" },
/* pl */ { IDS_ATTACH_4_8_16KB_AT_4000_PL, "Wsu� 4/8/16KB obraz w $4000" },
/* ru */ { IDS_ATTACH_4_8_16KB_AT_4000_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_4_8_16KB_AT_4000_SV, "Anslut 4/8/16KB-modulfil vid $4000" },
/* tr */ { IDS_ATTACH_4_8_16KB_AT_4000_TR, "$4000 adresine 4/8/16KB kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_4_8_16KB_AT_6000,    "Attach 4/8/16KB cartridge image at $6000" },
/* da */ { IDS_ATTACH_4_8_16KB_AT_6000_DA, "Tilslut 4/8/16KB-cartridge image p� $6000" },
/* de */ { IDS_ATTACH_4_8_16KB_AT_6000_DE, "4/8/16KB Modul Image bei $6000 einlegen" },
/* es */ { IDS_ATTACH_4_8_16KB_AT_6000_ES, "Insertar 4/8/16KB imagen cartucho en $6000" },
/* fr */ { IDS_ATTACH_4_8_16KB_AT_6000_FR, "Insertion d'une image 4/8/16Ko � $6000" },
/* hu */ { IDS_ATTACH_4_8_16KB_AT_6000_HU, "4/8/16KB k�pm�s csatol�sa $6000 c�mre" },
/* it */ { IDS_ATTACH_4_8_16KB_AT_6000_IT, "Seleziona immagine cartuccia di 4/8/16KB a $6000" },
/* ko */ { IDS_ATTACH_4_8_16KB_AT_6000_KO, "4/8/16KB īƮ���� �̹��� ��  $6000 �� ���̱�" },
/* nl */ { IDS_ATTACH_4_8_16KB_AT_6000_NL, "Koppel 4/8/16KB bestand op $6000" },
/* pl */ { IDS_ATTACH_4_8_16KB_AT_6000_PL, "Wsu� 4/8/16KB obraz w $6000" },
/* ru */ { IDS_ATTACH_4_8_16KB_AT_6000_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_4_8_16KB_AT_6000_SV, "Anslut 4/8/16KB-modulfil vid $6000" },
/* tr */ { IDS_ATTACH_4_8_16KB_AT_6000_TR, "$6000 adresine 4/8/16KB kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_4_8KB_AT_A000,    "Attach 4/8KB cartridge image at $A000" },
/* da */ { IDS_ATTACH_4_8KB_AT_A000_DA, "Tilslut 4/8KB-cartridge image p� $A000" },
/* de */ { IDS_ATTACH_4_8KB_AT_A000_DE, "4/8KB Modul Image bei $A000 einlegen" },
/* es */ { IDS_ATTACH_4_8KB_AT_A000_ES, "Insertar 4/8KB imagen cartucho en $A000" },
/* fr */ { IDS_ATTACH_4_8KB_AT_A000_FR, "Insertion d'une image 4/8Ko � $A000" },
/* hu */ { IDS_ATTACH_4_8KB_AT_A000_HU, "4/8KB k�pm�s csatol�sa $A000 c�mre" },
/* it */ { IDS_ATTACH_4_8KB_AT_A000_IT, "Seleziona immagine cartuccia di 4/8KB a $A000" },
/* ko */ { IDS_ATTACH_4_8KB_AT_A000_KO, "4/8KB īƮ���� �̹��� ��  $A000 �� ���̱�" },
/* nl */ { IDS_ATTACH_4_8KB_AT_A000_NL, "Koppel 4/8KB bestand op $A000" },
/* pl */ { IDS_ATTACH_4_8KB_AT_A000_PL, "Wsu� 4/8KB obraz w $A000" },
/* ru */ { IDS_ATTACH_4_8KB_AT_A000_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_4_8KB_AT_A000_SV, "Anslut 4/8KB-modulfil vid $A000" },
/* tr */ { IDS_ATTACH_4_8KB_AT_A000_TR, "$A000 adresine 4/8KB kartu� imaj� yerle�tir" },

/* en */ { IDS_ATTACH_4KB_AT_B000,    "Attach 4KB cartridge image at $B000" },
/* da */ { IDS_ATTACH_4KB_AT_B000_DA, "Tilslut 4KB-cartridge image p� $B000" },
/* de */ { IDS_ATTACH_4KB_AT_B000_DE, "4KB Modul Image bei $B000 einlegen" },
/* es */ { IDS_ATTACH_4KB_AT_B000_ES, "Insertar 4KB imagen cartucho en $B000" },
/* fr */ { IDS_ATTACH_4KB_AT_B000_FR, "Insertion d'une image 4Ko � $B000" },
/* hu */ { IDS_ATTACH_4KB_AT_B000_HU, "4KB k�pm�s csatol�sa $B000 c�mre" },
/* it */ { IDS_ATTACH_4KB_AT_B000_IT, "Seleziona immagine cartuccia di 4KB a $B000" },
/* ko */ { IDS_ATTACH_4KB_AT_B000_KO, "4KB īƮ���� �̹��� ��  $B000 �� ���̱�" },
/* nl */ { IDS_ATTACH_4KB_AT_B000_NL, "Koppel 4KB bestand op $B000" },
/* pl */ { IDS_ATTACH_4KB_AT_B000_PL, "Wsu� 4KB obraz w $B000" },
/* ru */ { IDS_ATTACH_4KB_AT_B000_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_4KB_AT_B000_SV, "Anslut 4KB-modulfil vid $B000" },
/* tr */ { IDS_ATTACH_4KB_AT_B000_TR, "$B000 adresine 4KB kartu� imaj� yerle�tir" },

/* en */ { IDS_S_AT_D_SPEED,    "%s at %d%% speed, %d fps%s" },
/* da */ { IDS_S_AT_D_SPEED_DA, "%s med %d%% hastighed, %d b/s%s" },
/* de */ { IDS_S_AT_D_SPEED_DE, "%s bei %d%% Geschwindigkeit, %d fps%s" },
/* es */ { IDS_S_AT_D_SPEED_ES, "%s at %d%% velocidad, %d fps%s" },
/* fr */ { IDS_S_AT_D_SPEED_FR, "%s � une vitesse de %d%%, � %d img/s%s" },
/* hu */ { IDS_S_AT_D_SPEED_HU, "%s %d%% sebess�gen, %d fps%s" },
/* it */ { IDS_S_AT_D_SPEED_IT, "velocit� %s al %d%%, %d fps%s" },
/* ko */ { IDS_S_AT_D_SPEED_KO, "%s �� %d%% ���ǵ�, %d fps%$s" },
/* nl */ { IDS_S_AT_D_SPEED_NL, "%s met %d%% snelheid, %d fps%s" },
/* pl */ { IDS_S_AT_D_SPEED_PL, "%s, pr�dko�� %d%%, %d fps%s" },
/* ru */ { IDS_S_AT_D_SPEED_RU, "" },  /* fuzzy */
/* sv */ { IDS_S_AT_D_SPEED_SV, "%s med %d%% hastighet, %d b/s%s" },
/* tr */ { IDS_S_AT_D_SPEED_TR, "%s %d%% h�z�nda, %d fps%s" },

/* en */ { IDS_ATTACH,    "Attach" },
/* da */ { IDS_ATTACH_DA, "Tilslut" },
/* de */ { IDS_ATTACH_DE, "Einlegen" },
/* es */ { IDS_ATTACH_ES, "Anexar" },
/* fr */ { IDS_ATTACH_FR, "Ins�rer" },
/* hu */ { IDS_ATTACH_HU, "Csatol�s" },
/* it */ { IDS_ATTACH_IT, "Seleziona" },
/* ko */ { IDS_ATTACH_KO, "���̴�" },
/* nl */ { IDS_ATTACH_NL, "Koppel" },
/* pl */ { IDS_ATTACH_PL, "Zamontuj" },
/* ru */ { IDS_ATTACH_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_SV, "Anslut" },
/* tr */ { IDS_ATTACH_TR, "Yerle�tir" },

/* en */ { IDS_PARENT,    "Parent" },
/* da */ { IDS_PARENT_DA, "For�lder" },
/* de */ { IDS_PARENT_DE, "Vorg�nger" },
/* es */ { IDS_PARENT_ES, "Padre" },
/* fr */ { IDS_PARENT_FR, "" },  /* fuzzy */
/* hu */ { IDS_PARENT_HU, "Sz�l�" },
/* it */ { IDS_PARENT_IT, "Su" },
/* ko */ { IDS_PARENT_KO, "�θ�" },
/* nl */ { IDS_PARENT_NL, "Bevenliggende directory" },
/* pl */ { IDS_PARENT_PL, "Nadrz�dny" },
/* ru */ { IDS_PARENT_RU, "" },  /* fuzzy */
/* sv */ { IDS_PARENT_SV, "F�r�lder" },
/* tr */ { IDS_PARENT_TR, "�st ��e" },

/* en */ { IDS_ATTACH_READ_ONLY,    "Attach read only" },
/* da */ { IDS_ATTACH_READ_ONLY_DA, "Tilslut skrivebeskyttet" },
/* de */ { IDS_ATTACH_READ_ONLY_DE, "Schreibgesch�tzt einlegen" },
/* es */ { IDS_ATTACH_READ_ONLY_ES, "Inserta s�lo lectura" },
/* fr */ { IDS_ATTACH_READ_ONLY_FR, "Ins�rer en lecture seule" },
/* hu */ { IDS_ATTACH_READ_ONLY_HU, "Csatol�s csak olvashat� m�don" },
/* it */ { IDS_ATTACH_READ_ONLY_IT, "Seleziona in sola lettura" },
/* ko */ { IDS_ATTACH_READ_ONLY_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACH_READ_ONLY_NL, "Alleen lezen" },
/* pl */ { IDS_ATTACH_READ_ONLY_PL, "Zamontuj tylko do odczytu" },
/* ru */ { IDS_ATTACH_READ_ONLY_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_READ_ONLY_SV, "Anslut skrivskyddat" },
/* tr */ { IDS_ATTACH_READ_ONLY_TR, "Salt okunur yerle�tir" },

/* en */ { IDS_NAME,    "Name" },
/* da */ { IDS_NAME_DA, "Navn" },
/* de */ { IDS_NAME_DE, "Name" },
/* es */ { IDS_NAME_ES, "Nombre" },
/* fr */ { IDS_NAME_FR, "Nom" },
/* hu */ { IDS_NAME_HU, "N�v" },
/* it */ { IDS_NAME_IT, "Nome" },
/* ko */ { IDS_NAME_KO, "�̸�" },
/* nl */ { IDS_NAME_NL, "Naam" },
/* pl */ { IDS_NAME_PL, "Nazwa" },
/* ru */ { IDS_NAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_NAME_SV, "Namn" },
/* tr */ { IDS_NAME_TR, "�sim" },

/* en */ { IDS_CREATE_IMAGE,    "Create Image" },
/* da */ { IDS_CREATE_IMAGE_DA, "Opret image" },
/* de */ { IDS_CREATE_IMAGE_DE, "Image Datei erzeugen" },
/* es */ { IDS_CREATE_IMAGE_ES, "Crear imagen" },
/* fr */ { IDS_CREATE_IMAGE_FR, "Cr�ation d'image" },
/* hu */ { IDS_CREATE_IMAGE_HU, "K�pm�s l�trehoz�sa" },
/* it */ { IDS_CREATE_IMAGE_IT, "Crea immagine" },
/* ko */ { IDS_CREATE_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDS_CREATE_IMAGE_NL, "Maak Bestand" },
/* pl */ { IDS_CREATE_IMAGE_PL, "Utw�rz obraz" },
/* ru */ { IDS_CREATE_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_CREATE_IMAGE_SV, "Skapa avbildning" },
/* tr */ { IDS_CREATE_IMAGE_TR, "Imaj Yarat" },

/* en */ { IDS_NEW_IMAGE,    "New Image" },
/* da */ { IDS_NEW_IMAGE_DA, "Nyt image" },
/* de */ { IDS_NEW_IMAGE_DE, "Neue Image Datei" },
/* es */ { IDS_NEW_IMAGE_ES, "Nueva imagen" },
/* fr */ { IDS_NEW_IMAGE_FR, "Nouvelle image" },
/* hu */ { IDS_NEW_IMAGE_HU, "�j k�pm�s" },
/* it */ { IDS_NEW_IMAGE_IT, "Nuova immagine" },
/* ko */ { IDS_NEW_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDS_NEW_IMAGE_NL, "Nieuw Bestand" },
/* pl */ { IDS_NEW_IMAGE_PL, "Nowy obraz" },
/* ru */ { IDS_NEW_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_NEW_IMAGE_SV, "Ny avbildning" },
/* tr */ { IDS_NEW_IMAGE_TR, "Yeni �maj" },

/* en */ { IDS_NEW_TAP_IMAGE,    "New TAP Image" },
/* da */ { IDS_NEW_TAP_IMAGE_DA, "Nyt TAP-image" },
/* de */ { IDS_NEW_TAP_IMAGE_DE, "Neue TAP Image Datei" },
/* es */ { IDS_NEW_TAP_IMAGE_ES, "Nueva imagen TAP" },
/* fr */ { IDS_NEW_TAP_IMAGE_FR, "Nouvelle image TAP" },
/* hu */ { IDS_NEW_TAP_IMAGE_HU, "�j TAP k�pm�s" },
/* it */ { IDS_NEW_TAP_IMAGE_IT, "Nuova immagine TAP" },
/* ko */ { IDS_NEW_TAP_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDS_NEW_TAP_IMAGE_NL, "Nieuw TAP bestand" },
/* pl */ { IDS_NEW_TAP_IMAGE_PL, "Obraz New TAP" },
/* ru */ { IDS_NEW_TAP_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_NEW_TAP_IMAGE_SV, "Ny TAP-avbildning" },
/* tr */ { IDS_NEW_TAP_IMAGE_TR, "Yeni TAP Imaj�" },

/* en */ { IDS_OVERWRITE_EXISTING_IMAGE,    "Overwrite existing image?" },
/* da */ { IDS_OVERWRITE_EXISTING_IMAGE_DA, "Overskriv eksisterende image?" },
/* de */ { IDS_OVERWRITE_EXISTING_IMAGE_DE, "Existierende Datei �berschreiben?" },
/* es */ { IDS_OVERWRITE_EXISTING_IMAGE_ES, "�Sobreescribo la imagen actual?" },
/* fr */ { IDS_OVERWRITE_EXISTING_IMAGE_FR, "�craser les images existantes?" },
/* hu */ { IDS_OVERWRITE_EXISTING_IMAGE_HU, "Fel�l�rjam a megl�v� k�pm�st?" },
/* it */ { IDS_OVERWRITE_EXISTING_IMAGE_IT, "Sovrascrivo l'immagine esistente?" },
/* ko */ { IDS_OVERWRITE_EXISTING_IMAGE_KO, "���� �̹����� ���� ���� �ұ��?" },
/* nl */ { IDS_OVERWRITE_EXISTING_IMAGE_NL, "Bestaand bestand overschrijven?" },
/* pl */ { IDS_OVERWRITE_EXISTING_IMAGE_PL, "Nadpisa� istniej�cy obraz?" },
/* ru */ { IDS_OVERWRITE_EXISTING_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_OVERWRITE_EXISTING_IMAGE_SV, "Skriva �ver existerande avbildning?" },
/* tr */ { IDS_OVERWRITE_EXISTING_IMAGE_TR, "Varolan imaj�n �zerine yaz�ls�n m�?" },

/* en */ { IDS_ABOUT,    "About VICE" },
/* da */ { IDS_ABOUT_DA, "Om VICE" },
/* de */ { IDS_ABOUT_DE, "�ber VICE" },
/* es */ { IDS_ABOUT_ES, "Acerca de VICE" },
/* fr */ { IDS_ABOUT_FR, "" },  /* fuzzy */
/* hu */ { IDS_ABOUT_HU, "A VICE n�vjegye" },
/* it */ { IDS_ABOUT_IT, "Informazioni su VICE" },
/* ko */ { IDS_ABOUT_KO, "���� VICE" },
/* nl */ { IDS_ABOUT_NL, "Over VICE" },
/* pl */ { IDS_ABOUT_PL, "O VICE" },
/* ru */ { IDS_ABOUT_RU, "" },  /* fuzzy */
/* sv */ { IDS_ABOUT_SV, "Om VICE" },
/* tr */ { IDS_ABOUT_TR, "VICE Hakk�nda" },

/* en */ { IDS_IMAGE_CONTENTS,    "Image Contents" },
/* da */ { IDS_IMAGE_CONTENTS_DA, "Indhold i image" },
/* de */ { IDS_IMAGE_CONTENTS_DE, "Image Datei Inhalt" },
/* es */ { IDS_IMAGE_CONTENTS_ES, "Contenidos imagen" },
/* fr */ { IDS_IMAGE_CONTENTS_FR, "" },  /* fuzzy */
/* hu */ { IDS_IMAGE_CONTENTS_HU, "Tartalom" },
/* it */ { IDS_IMAGE_CONTENTS_IT, "Contenuti immagine" },
/* ko */ { IDS_IMAGE_CONTENTS_KO, "" },  /* fuzzy */
/* nl */ { IDS_IMAGE_CONTENTS_NL, "bestandsinhoud" },
/* pl */ { IDS_IMAGE_CONTENTS_PL, "Zawarto�� obrazu" },
/* ru */ { IDS_IMAGE_CONTENTS_RU, "" },  /* fuzzy */
/* sv */ { IDS_IMAGE_CONTENTS_SV, "Inneh�ll i avbildning" },
/* tr */ { IDS_IMAGE_CONTENTS_TR, "Imaj ��eri�i" },

/* en */ { IDMS_DISABLED,    "Disabled" },
/* da */ { IDMS_DISABLED_DA, "Deaktiveret" },
/* de */ { IDMS_DISABLED_DE, "Deaktiviert" },
/* es */ { IDMS_DISABLED_ES, "Deshabilitado" },
/* fr */ { IDMS_DISABLED_FR, "" },  /* fuzzy */
/* hu */ { IDMS_DISABLED_HU, "Tiltva" },
/* it */ { IDMS_DISABLED_IT, "Disattivo" },
/* ko */ { IDMS_DISABLED_KO, "�۵���������" },
/* nl */ { IDMS_DISABLED_NL, "Uit" },
/* pl */ { IDMS_DISABLED_PL, "Wy��cz" },
/* ru */ { IDMS_DISABLED_RU, "" },  /* fuzzy */
/* sv */ { IDMS_DISABLED_SV, "Inaktiverad" },
/* tr */ { IDMS_DISABLED_TR, "Pasif" },

/* en */ { IDS_ENABLED,    "Enabled" },
/* da */ { IDS_ENABLED_DA, "Aktiveret" },
/* de */ { IDS_ENABLED_DE, "Aktiviert" },
/* es */ { IDS_ENABLED_ES, "Habilitado" },
/* fr */ { IDS_ENABLED_FR, "" },  /* fuzzy */
/* hu */ { IDS_ENABLED_HU, "Enged�lyezve" },
/* it */ { IDS_ENABLED_IT, "Attivo" },
/* ko */ { IDS_ENABLED_KO, "�۵�" },
/* nl */ { IDS_ENABLED_NL, "Aan" },
/* pl */ { IDS_ENABLED_PL, "W��cz" },
/* ru */ { IDS_ENABLED_RU, "" },  /* fuzzy */
/* sv */ { IDS_ENABLED_SV, "Aktiverad" },
/* tr */ { IDS_ENABLED_TR, "Aktif" },

/* en */ { IDS_RS232_DEVICE_1,    "RS232 device 1" },
/* da */ { IDS_RS232_DEVICE_1_DA, "RS232-enhed 1" },
/* de */ { IDS_RS232_DEVICE_1_DE, "RS232 Ger�t 1" },
/* es */ { IDS_RS232_DEVICE_1_ES, "Perif�rico RS232 1" },
/* fr */ { IDS_RS232_DEVICE_1_FR, "1er P�riph�rique RS232" },
/* hu */ { IDS_RS232_DEVICE_1_HU, "RS232 1-es eszk�z" },
/* it */ { IDS_RS232_DEVICE_1_IT, "Dispositivo RS232 #1" },
/* ko */ { IDS_RS232_DEVICE_1_KO, "" },  /* fuzzy */
/* nl */ { IDS_RS232_DEVICE_1_NL, "RS232 apparaat 1" },
/* pl */ { IDS_RS232_DEVICE_1_PL, "Urz�dzenie RS232 1" },
/* ru */ { IDS_RS232_DEVICE_1_RU, "" },  /* fuzzy */
/* sv */ { IDS_RS232_DEVICE_1_SV, "RS232-enhet 1" },
/* tr */ { IDS_RS232_DEVICE_1_TR, "RS232 ayg�t 1" },

/* en */ { IDS_RS232_DEVICE_2,    "RS232 device 2" },
/* da */ { IDS_RS232_DEVICE_2_DA, "RS232-enhed 2" },
/* de */ { IDS_RS232_DEVICE_2_DE, "RS232 Ger�t 2" },
/* es */ { IDS_RS232_DEVICE_2_ES, "Perif�rico RS232 2" },
/* fr */ { IDS_RS232_DEVICE_2_FR, "2e P�riph�rique RS232" },
/* hu */ { IDS_RS232_DEVICE_2_HU, "RS232 2-es eszk�z" },
/* it */ { IDS_RS232_DEVICE_2_IT, "Dispositivo RS232 #2" },
/* ko */ { IDS_RS232_DEVICE_2_KO, "" },  /* fuzzy */
/* nl */ { IDS_RS232_DEVICE_2_NL, "RS232 apparaat 2" },
/* pl */ { IDS_RS232_DEVICE_2_PL, "Urz�dzenie RS232 2" },
/* ru */ { IDS_RS232_DEVICE_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_RS232_DEVICE_2_SV, "RS232-enhet 2" },
/* tr */ { IDS_RS232_DEVICE_2_TR, "RS232 ayg�t 2" },

/* en */ { IDS_RS232_DEVICE_3,    "RS232 device 3" },
/* da */ { IDS_RS232_DEVICE_3_DA, "RS232-enhed 3" },
/* de */ { IDS_RS232_DEVICE_3_DE, "RS232 Ger�t 3" },
/* es */ { IDS_RS232_DEVICE_3_ES, "Perif�rico RS232 3" },
/* fr */ { IDS_RS232_DEVICE_3_FR, "3e P�riph�rique RS232" },
/* hu */ { IDS_RS232_DEVICE_3_HU, "RS232 3-as eszk�z" },
/* it */ { IDS_RS232_DEVICE_3_IT, "Dispositivo RS232 #3" },
/* ko */ { IDS_RS232_DEVICE_3_KO, "" },  /* fuzzy */
/* nl */ { IDS_RS232_DEVICE_3_NL, "RS232 apparaat 3" },
/* pl */ { IDS_RS232_DEVICE_3_PL, "Urz�dzenie RS232 3" },
/* ru */ { IDS_RS232_DEVICE_3_RU, "" },  /* fuzzy */
/* sv */ { IDS_RS232_DEVICE_3_SV, "RS232-enhet 3" },
/* tr */ { IDS_RS232_DEVICE_3_TR, "RS232 ayg�t 3" },

/* en */ { IDS_RS232_DEVICE_4,    "RS232 device 4" },
/* da */ { IDS_RS232_DEVICE_4_DA, "RS232-enhed 4" },
/* de */ { IDS_RS232_DEVICE_4_DE, "RS232 Ger�t 4" },
/* es */ { IDS_RS232_DEVICE_4_ES, "Perif�rico RS232 4" },
/* fr */ { IDS_RS232_DEVICE_4_FR, "4e P�riph�rique RS232" },
/* hu */ { IDS_RS232_DEVICE_4_HU, "RS232 4-es eszk�z" },
/* it */ { IDS_RS232_DEVICE_4_IT, "Dispositivo RS232 #4" },
/* ko */ { IDS_RS232_DEVICE_4_KO, "" },  /* fuzzy */
/* nl */ { IDS_RS232_DEVICE_4_NL, "RS232 apparaat 4" },
/* pl */ { IDS_RS232_DEVICE_4_PL, "Urz�dzenie RS232 4" },
/* ru */ { IDS_RS232_DEVICE_4_RU, "" },  /* fuzzy */
/* sv */ { IDS_RS232_DEVICE_4_SV, "RS232-enhet 4" },
/* tr */ { IDS_RS232_DEVICE_4_TR, "RS232 ayg�t 4" },

/* en */ { IDS_NONE,    "None" },
/* da */ { IDS_NONE_DA, "Ingen" },
/* de */ { IDS_NONE_DE, "Kein" },
/* es */ { IDS_NONE_ES, "no" },
/* fr */ { IDS_NONE_FR, "Aucun" },
/* hu */ { IDS_NONE_HU, "Nincs" },
/* it */ { IDS_NONE_IT, "Nessuno" },
/* ko */ { IDS_NONE_KO, "����" },
/* nl */ { IDS_NONE_NL, "Geen" },
/* pl */ { IDS_NONE_PL, "Brak" },
/* ru */ { IDS_NONE_RU, "" },  /* fuzzy */
/* sv */ { IDS_NONE_SV, "Ingen" },
/* tr */ { IDS_NONE_TR, "Yok" },

/* en */ { IDS_FILESYSTEM,    "Filesystem" },
/* da */ { IDS_FILESYSTEM_DA, "Filsystem" },
/* de */ { IDS_FILESYSTEM_DE, "Dateisystem" },
/* es */ { IDS_FILESYSTEM_ES, "Sistema de ficheros" },
/* fr */ { IDS_FILESYSTEM_FR, "" },  /* fuzzy */
/* hu */ { IDS_FILESYSTEM_HU, "" },  /* fuzzy */
/* it */ { IDS_FILESYSTEM_IT, "Filesystem" },
/* ko */ { IDS_FILESYSTEM_KO, "���Ͻý���" },
/* nl */ { IDS_FILESYSTEM_NL, "Bestandssysteem" },
/* pl */ { IDS_FILESYSTEM_PL, "System plik�w" },
/* ru */ { IDS_FILESYSTEM_RU, "" },  /* fuzzy */
/* sv */ { IDS_FILESYSTEM_SV, "Filsystem" },
/* tr */ { IDS_FILESYSTEM_TR, "Dosya sistemi" },

/* en */ { IDS_RAW,    "Raw" },
/* da */ { IDS_RAW_DA, "R�" },
/* de */ { IDS_RAW_DE, "Raw" },
/* es */ { IDS_RAW_ES, "Sin formato" },
/* fr */ { IDS_RAW_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAW_HU, "" },  /* fuzzy */
/* it */ { IDS_RAW_IT, "Raw" },
/* ko */ { IDS_RAW_KO, "Raw" },
/* nl */ { IDS_RAW_NL, "Raw" },
/* pl */ { IDS_RAW_PL, "Surowy" },
/* ru */ { IDS_RAW_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAW_SV, "R�tt" },
/* tr */ { IDS_RAW_TR, "D�z" },

/* en */ { IDS_JOYSTICK,    "Joystick" },
/* da */ { IDS_JOYSTICK_DA, "Joystick" },
/* de */ { IDS_JOYSTICK_DE, "Joystick" },
/* es */ { IDS_JOYSTICK_ES, "Joystick" },
/* fr */ { IDS_JOYSTICK_FR, "" },  /* fuzzy */
/* hu */ { IDS_JOYSTICK_HU, "Botkorm�ny" },
/* it */ { IDS_JOYSTICK_IT, "Joystick" },
/* ko */ { IDS_JOYSTICK_KO, "���̽�ƽ" },
/* nl */ { IDS_JOYSTICK_NL, "Joystick" },
/* pl */ { IDS_JOYSTICK_PL, "Joystick" },
/* ru */ { IDS_JOYSTICK_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOYSTICK_SV, "Styrspak" },
/* tr */ { IDS_JOYSTICK_TR, "Joystick" },

/* en */ { IDS_IRQ,    "IRQ" },
/* da */ { IDS_IRQ_DA, "IRQ" },
/* de */ { IDS_IRQ_DE, "IRQ" },
/* es */ { IDS_IRQ_ES, "IRQ" },
/* fr */ { IDS_IRQ_FR, "IRQ" },
/* hu */ { IDS_IRQ_HU, "IRQ" },
/* it */ { IDS_IRQ_IT, "IRQ" },
/* ko */ { IDS_IRQ_KO, "IRQ" },
/* nl */ { IDS_IRQ_NL, "IRQ" },
/* pl */ { IDS_IRQ_PL, "IRQ" },
/* ru */ { IDS_IRQ_RU, "" },  /* fuzzy */
/* sv */ { IDS_IRQ_SV, "IRQ" },
/* tr */ { IDS_IRQ_TR, "IRQ" },

/* en */ { IDS_NMI,    "NMI" },
/* da */ { IDS_NMI_DA, "NMI" },
/* de */ { IDS_NMI_DE, "NMI" },
/* es */ { IDS_NMI_ES, "NMI" },
/* fr */ { IDS_NMI_FR, "NMI" },
/* hu */ { IDS_NMI_HU, "NMI" },
/* it */ { IDS_NMI_IT, "NMI" },
/* ko */ { IDS_NMI_KO, "NMI" },
/* nl */ { IDS_NMI_NL, "NMI" },
/* pl */ { IDS_NMI_PL, "NMI" },
/* ru */ { IDS_NMI_RU, "" },  /* fuzzy */
/* sv */ { IDS_NMI_SV, "NMI" },
/* tr */ { IDS_NMI_TR, "NMI" },

/* en */ { IDS_ACIA_DEVICE,    "ACIA device" },
/* da */ { IDS_ACIA_DEVICE_DA, "ACIA-enhed" },
/* de */ { IDS_ACIA_DEVICE_DE, "ACIA Ger�t" },
/* es */ { IDS_ACIA_DEVICE_ES, "Perif�rico ACIA" },
/* fr */ { IDS_ACIA_DEVICE_FR, "P�riph�rique ACIA" },
/* hu */ { IDS_ACIA_DEVICE_HU, "ACIA eszk�z" },
/* it */ { IDS_ACIA_DEVICE_IT, "Dispositivo ACIA" },
/* ko */ { IDS_ACIA_DEVICE_KO, "" },  /* fuzzy */
/* nl */ { IDS_ACIA_DEVICE_NL, "ACIA apparaat" },
/* pl */ { IDS_ACIA_DEVICE_PL, "Urz�dzenia ACIA" },
/* ru */ { IDS_ACIA_DEVICE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ACIA_DEVICE_SV, "ACIA-enhet" },
/* tr */ { IDS_ACIA_DEVICE_TR, "ACIA ayg�t�" },

/* en */ { IDS_ACIA_BASE,    "ACIA base address" },
/* da */ { IDS_ACIA_BASE_DA, "" },  /* fuzzy */
/* de */ { IDS_ACIA_BASE_DE, "ACIA Basis Adresse" },
/* es */ { IDS_ACIA_BASE_ES, "ACIA direcci�n base" },
/* fr */ { IDS_ACIA_BASE_FR, "" },  /* fuzzy */
/* hu */ { IDS_ACIA_BASE_HU, "" },  /* fuzzy */
/* it */ { IDS_ACIA_BASE_IT, "" },  /* fuzzy */
/* ko */ { IDS_ACIA_BASE_KO, "" },  /* fuzzy */
/* nl */ { IDS_ACIA_BASE_NL, "ACIA basisadres" },
/* pl */ { IDS_ACIA_BASE_PL, "Adres bazowy ACIA" },
/* ru */ { IDS_ACIA_BASE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ACIA_BASE_SV, "" },  /* fuzzy */
/* tr */ { IDS_ACIA_BASE_TR, "" },  /* fuzzy */

/* en */ { IDS_ACIA_INTERRUPT,    "ACIA interrupt" },
/* da */ { IDS_ACIA_INTERRUPT_DA, "ACIA-interrupt" },
/* de */ { IDS_ACIA_INTERRUPT_DE, "ACIA Interrupt" },
/* es */ { IDS_ACIA_INTERRUPT_ES, "Interruptor ACIA" },
/* fr */ { IDS_ACIA_INTERRUPT_FR, "Interruption ACIA" },
/* hu */ { IDS_ACIA_INTERRUPT_HU, "ACIA megszak�t�s" },
/* it */ { IDS_ACIA_INTERRUPT_IT, "Interrupt ACIA" },
/* ko */ { IDS_ACIA_INTERRUPT_KO, "" },  /* fuzzy */
/* nl */ { IDS_ACIA_INTERRUPT_NL, "ACIA interrupt" },
/* pl */ { IDS_ACIA_INTERRUPT_PL, "Przerwanie ACIA" },
/* ru */ { IDS_ACIA_INTERRUPT_RU, "" },  /* fuzzy */
/* sv */ { IDS_ACIA_INTERRUPT_SV, "ACIA-avbrott" },
/* tr */ { IDS_ACIA_INTERRUPT_TR, "ACIA kesmesi" },

/* en */ { IDS_ACIA_MODE,    "ACIA mode" },
/* da */ { IDS_ACIA_MODE_DA, "ACIA-tilstand" },
/* de */ { IDS_ACIA_MODE_DE, "ACIA Modus" },
/* es */ { IDS_ACIA_MODE_ES, "Modo ACIA" },
/* fr */ { IDS_ACIA_MODE_FR, "" },  /* fuzzy */
/* hu */ { IDS_ACIA_MODE_HU, "ACIA m�d" },
/* it */ { IDS_ACIA_MODE_IT, "Modalit� ACIA" },
/* ko */ { IDS_ACIA_MODE_KO, "" },  /* fuzzy */
/* nl */ { IDS_ACIA_MODE_NL, "ACIA modus" },
/* pl */ { IDS_ACIA_MODE_PL, "Tryb ACIA" },
/* ru */ { IDS_ACIA_MODE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ACIA_MODE_SV, "ACIA-l�ge" },
/* tr */ { IDS_ACIA_MODE_TR, "ACIA modu" },

/* en */ { IDS_ACIA_SETTINGS,    "ACIA settings" },
/* da */ { IDS_ACIA_SETTINGS_DA, "ACIA-indstillinger" },
/* de */ { IDS_ACIA_SETTINGS_DE, "ACIA Einstellungen" },
/* es */ { IDS_ACIA_SETTINGS_ES, "Ajustes ACIA" },
/* fr */ { IDS_ACIA_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_ACIA_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_ACIA_SETTINGS_IT, "Impostazioni ACIA" },
/* ko */ { IDS_ACIA_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_ACIA_SETTINGS_NL, "ACIA instellingen" },
/* pl */ { IDS_ACIA_SETTINGS_PL, "Ustawienia ACIA" },
/* ru */ { IDS_ACIA_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_ACIA_SETTINGS_SV, "ACIA-inst�llningar" },
/* tr */ { IDS_ACIA_SETTINGS_TR, "ACIA Ayarlar�" },

/* en */ { IDS_256K_ENABLED,    "256K Enabled" },
/* da */ { IDS_256K_ENABLED_DA, "256K aktiveret" },
/* de */ { IDS_256K_ENABLED_DE, "256K aktiviert" },
/* es */ { IDS_256K_ENABLED_ES, "Permitir 256K" },
/* fr */ { IDS_256K_ENABLED_FR, "" },  /* fuzzy */
/* hu */ { IDS_256K_ENABLED_HU, "256K enged�lyezve" },
/* it */ { IDS_256K_ENABLED_IT, "256K attivi" },
/* ko */ { IDS_256K_ENABLED_KO, "" },  /* fuzzy */
/* nl */ { IDS_256K_ENABLED_NL, "256K aan" },
/* pl */ { IDS_256K_ENABLED_PL, "W��cz 256K" },
/* ru */ { IDS_256K_ENABLED_RU, "" },  /* fuzzy */
/* sv */ { IDS_256K_ENABLED_SV, "256K aktiverat" },
/* tr */ { IDS_256K_ENABLED_TR, "256K Aktif" },

/* en */ { IDS_256K_BASE,    "256K base address" },
/* da */ { IDS_256K_BASE_DA, "256K-baseadresse" },
/* de */ { IDS_256K_BASE_DE, "256K Basis Adresse" },
/* es */ { IDS_256K_BASE_ES, "Direcci�n base 256K" },
/* fr */ { IDS_256K_BASE_FR, "Adresse de base 256K" },
/* hu */ { IDS_256K_BASE_HU, "256K b�zisc�m" },
/* it */ { IDS_256K_BASE_IT, "indirizzo base 256K" },
/* ko */ { IDS_256K_BASE_KO, "" },  /* fuzzy */
/* nl */ { IDS_256K_BASE_NL, "256K basisadres" },
/* pl */ { IDS_256K_BASE_PL, "Adres bazowy 256K" },
/* ru */ { IDS_256K_BASE_RU, "" },  /* fuzzy */
/* sv */ { IDS_256K_BASE_SV, "256K-basadress" },
/* tr */ { IDS_256K_BASE_TR, "256K taban adresi" },

/* en */ { IDS_256K_FILENAME,    "256K file" },
/* da */ { IDS_256K_FILENAME_DA, "256K-fil" },
/* de */ { IDS_256K_FILENAME_DE, "256K Datei" },
/* es */ { IDS_256K_FILENAME_ES, "Fichero 256K" },
/* fr */ { IDS_256K_FILENAME_FR, "Fichier 256K" },
/* hu */ { IDS_256K_FILENAME_HU, "256K f�jl" },
/* it */ { IDS_256K_FILENAME_IT, "File 256K" },
/* ko */ { IDS_256K_FILENAME_KO, "256k ����" },
/* nl */ { IDS_256K_FILENAME_NL, "256K bestand" },
/* pl */ { IDS_256K_FILENAME_PL, "Plik 256K" },
/* ru */ { IDS_256K_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_256K_FILENAME_SV, "256K-fil" },
/* tr */ { IDS_256K_FILENAME_TR, "256K dosyas�" },

/* en */ { IDS_256K_FILENAME_SELECT,    "Select file for 256K" },
/* da */ { IDS_256K_FILENAME_SELECT_DA, "Angiv fil for 256K" },
/* de */ { IDS_256K_FILENAME_SELECT_DE, "Datei f�r 256K ausw�hlen" },
/* es */ { IDS_256K_FILENAME_SELECT_ES, "Seleccionar fichero para 256K" },
/* fr */ { IDS_256K_FILENAME_SELECT_FR, "S�lectionner fichier pour 256K" },
/* hu */ { IDS_256K_FILENAME_SELECT_HU, "V�lasszon f�jlt a 256K-hoz" },
/* it */ { IDS_256K_FILENAME_SELECT_IT, "Seleziona file per 256K" },
/* ko */ { IDS_256K_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_256K_FILENAME_SELECT_NL, "Selecteer bestand voor 256K" },
/* pl */ { IDS_256K_FILENAME_SELECT_PL, "Wybierz plik 256K" },
/* ru */ { IDS_256K_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_256K_FILENAME_SELECT_SV, "Ange fil f�r 256K" },
/* tr */ { IDS_256K_FILENAME_SELECT_TR, "256K i�in dosya se�in" },

/* en */ { IDS_256K_SETTINGS,    "256K settings" },
/* da */ { IDS_256K_SETTINGS_DA, "256K-indstillinger" },
/* de */ { IDS_256K_SETTINGS_DE, "256K Einstellungen" },
/* es */ { IDS_256K_SETTINGS_ES, "Ajustes 256K" },
/* fr */ { IDS_256K_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_256K_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_256K_SETTINGS_IT, "Impostazioni 256K" },
/* ko */ { IDS_256K_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_256K_SETTINGS_NL, "256K instellingen" },
/* pl */ { IDS_256K_SETTINGS_PL, "Ustawienia 256K" },
/* ru */ { IDS_256K_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_256K_SETTINGS_SV, "256K-inst�llningar" },
/* tr */ { IDS_256K_SETTINGS_TR, "256K Ayarlar�" },

/* en */ { IDS_C64DTV_ROM_FILENAME_SELECT,    "Select file for C64DTV ROM" },
/* da */ { IDS_C64DTV_ROM_FILENAME_SELECT_DA, "V�lg fil for C64DTV-ROM" },
/* de */ { IDS_C64DTV_ROM_FILENAME_SELECT_DE, "Datei f�r C64DTV ROM ausw�hlen" },
/* es */ { IDS_C64DTV_ROM_FILENAME_SELECT_ES, "Seleccionar fichero para C64DTV ROM" },
/* fr */ { IDS_C64DTV_ROM_FILENAME_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_C64DTV_ROM_FILENAME_SELECT_HU, "V�lasszon f�jlt a C64DTV ROM-hoz" },
/* it */ { IDS_C64DTV_ROM_FILENAME_SELECT_IT, "Seleziona il file per la ROM C64DTV" },
/* ko */ { IDS_C64DTV_ROM_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_C64DTV_ROM_FILENAME_SELECT_NL, "Selecteer bestand voor C64DTV ROM" },
/* pl */ { IDS_C64DTV_ROM_FILENAME_SELECT_PL, "Wybierz plik ROM C64DTV" },
/* ru */ { IDS_C64DTV_ROM_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_C64DTV_ROM_FILENAME_SELECT_SV, "V�lj fil f�r C64DTV-ROM" },
/* tr */ { IDS_C64DTV_ROM_FILENAME_SELECT_TR, "C64DTV ROM'u i�in dosya se�in" },

/* en */ { IDS_C64DTV_ROM_FILENAME,    "C64DTV ROM file" },
/* da */ { IDS_C64DTV_ROM_FILENAME_DA, "C64DTV-ROM-fil" },
/* de */ { IDS_C64DTV_ROM_FILENAME_DE, "C64DTV ROM Datei" },
/* es */ { IDS_C64DTV_ROM_FILENAME_ES, "Fichero C64DTV ROM" },
/* fr */ { IDS_C64DTV_ROM_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_C64DTV_ROM_FILENAME_HU, "C64DTV ROM f�jl" },
/* it */ { IDS_C64DTV_ROM_FILENAME_IT, "File ROM C64DTV" },
/* ko */ { IDS_C64DTV_ROM_FILENAME_KO, "C64DTV ROM ����" },
/* nl */ { IDS_C64DTV_ROM_FILENAME_NL, "C64DTV ROM bestand" },
/* pl */ { IDS_C64DTV_ROM_FILENAME_PL, "Plik ROM C64DTV" },
/* ru */ { IDS_C64DTV_ROM_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_C64DTV_ROM_FILENAME_SV, "C64DTV-ROM-fil" },
/* tr */ { IDS_C64DTV_ROM_FILENAME_TR, "C64DTV ROM dosyas�" },

/* en */ { IDS_C64DTV_REVISION,    "DTV revision" },
/* da */ { IDS_C64DTV_REVISION_DA, "DTV-revision" },
/* de */ { IDS_C64DTV_REVISION_DE, "DTV Revision" },
/* es */ { IDS_C64DTV_REVISION_ES, "Revisi�n DTV" },
/* fr */ { IDS_C64DTV_REVISION_FR, "" },  /* fuzzy */
/* hu */ { IDS_C64DTV_REVISION_HU, "" },  /* fuzzy */
/* it */ { IDS_C64DTV_REVISION_IT, "Revisione DTV" },
/* ko */ { IDS_C64DTV_REVISION_KO, "DTV ����" },
/* nl */ { IDS_C64DTV_REVISION_NL, "DTV revisie" },
/* pl */ { IDS_C64DTV_REVISION_PL, "Wersja DRV" },
/* ru */ { IDS_C64DTV_REVISION_RU, "" },  /* fuzzy */
/* sv */ { IDS_C64DTV_REVISION_SV, "DTV-utg�va" },
/* tr */ { IDS_C64DTV_REVISION_TR, "DTV revizyonu" },

/* en */ { IDS_C64DTV_WRITE_ENABLE,    "Writes to C64DTV ROM" },
/* da */ { IDS_C64DTV_WRITE_ENABLE_DA, "Skrivning til C64DTV-ROM" },
/* de */ { IDS_C64DTV_WRITE_ENABLE_DE, "Schreibzugriff auf C64DTV ROM" },
/* es */ { IDS_C64DTV_WRITE_ENABLE_ES, "Escribir en C64DTV ROM" },
/* fr */ { IDS_C64DTV_WRITE_ENABLE_FR, "" },  /* fuzzy */
/* hu */ { IDS_C64DTV_WRITE_ENABLE_HU, "C64DTV ROM-ba �r�sok" },
/* it */ { IDS_C64DTV_WRITE_ENABLE_IT, "Scrivi sulla ROM C64DTV" },
/* ko */ { IDS_C64DTV_WRITE_ENABLE_KO, "" },  /* fuzzy */
/* nl */ { IDS_C64DTV_WRITE_ENABLE_NL, "Schrijven naar C64DTV ROM" },
/* pl */ { IDS_C64DTV_WRITE_ENABLE_PL, "Zapis do ROM-u C64DTV" },
/* ru */ { IDS_C64DTV_WRITE_ENABLE_RU, "" },  /* fuzzy */
/* sv */ { IDS_C64DTV_WRITE_ENABLE_SV, "Skrivningar till C64DTV-ROM" },
/* tr */ { IDS_C64DTV_WRITE_ENABLE_TR, "C64DTV ROM'una yazar" },

/* en */ { IDS_C64DTV_HUMMER_ADC,    "Hummer ADC" },
/* da */ { IDS_C64DTV_HUMMER_ADC_DA, "Hummer ADC" },
/* de */ { IDS_C64DTV_HUMMER_ADC_DE, "Hummer ADC" },
/* es */ { IDS_C64DTV_HUMMER_ADC_ES, "Hummer ADC" },
/* fr */ { IDS_C64DTV_HUMMER_ADC_FR, "" },  /* fuzzy */
/* hu */ { IDS_C64DTV_HUMMER_ADC_HU, "" },  /* fuzzy */
/* it */ { IDS_C64DTV_HUMMER_ADC_IT, "Hummer ADC" },
/* ko */ { IDS_C64DTV_HUMMER_ADC_KO, "��� ADC" },
/* nl */ { IDS_C64DTV_HUMMER_ADC_NL, "Hummer ADC" },
/* pl */ { IDS_C64DTV_HUMMER_ADC_PL, "Hummer ADC" },
/* ru */ { IDS_C64DTV_HUMMER_ADC_RU, "" },  /* fuzzy */
/* sv */ { IDS_C64DTV_HUMMER_ADC_SV, "Hummer A/D-omvandlare" },
/* tr */ { IDS_C64DTV_HUMMER_ADC_TR, "Hummer ADC" },

/* en */ { IDS_C64DTV_SETTINGS,    "C64DTV settings" },
/* da */ { IDS_C64DTV_SETTINGS_DA, "C64DTV-indstillinger" },
/* de */ { IDS_C64DTV_SETTINGS_DE, "C64DTV Einstellungen" },
/* es */ { IDS_C64DTV_SETTINGS_ES, "Ajustes C64DTV" },
/* fr */ { IDS_C64DTV_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_C64DTV_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_C64DTV_SETTINGS_IT, "Impostazioni C64DTV" },
/* ko */ { IDS_C64DTV_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_C64DTV_SETTINGS_NL, "C64DTV Instellingen" },
/* pl */ { IDS_C64DTV_SETTINGS_PL, "Ustawienia C64DTV" },
/* ru */ { IDS_C64DTV_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_C64DTV_SETTINGS_SV, "C64DTV-inst�llningar" },
/* tr */ { IDS_C64DTV_SETTINGS_TR, "C64DTV Ayarlar�" },

/* en */ { IDS_MODEL_LINE,    "Model line" },
/* da */ { IDS_MODEL_LINE_DA, "Modelltyp" },
/* de */ { IDS_MODEL_LINE_DE, "Modell Linie" },
/* es */ { IDS_MODEL_LINE_ES, "Linea modelo" },
/* fr */ { IDS_MODEL_LINE_FR, "Ligne du mod�le" },
/* hu */ { IDS_MODEL_LINE_HU, "" },  /* fuzzy */
/* it */ { IDS_MODEL_LINE_IT, "Linea" },
/* ko */ { IDS_MODEL_LINE_KO, "" },  /* fuzzy */
/* nl */ { IDS_MODEL_LINE_NL, "Model lijn" },
/* pl */ { IDS_MODEL_LINE_PL, "Linia modelu" },
/* ru */ { IDS_MODEL_LINE_RU, "" },  /* fuzzy */
/* sv */ { IDS_MODEL_LINE_SV, "Modelltyp" },
/* tr */ { IDS_MODEL_LINE_TR, "Model hatt�" },

/* en */ { IDS_RAM_SIZE,    "RAM size" },
/* da */ { IDS_RAM_SIZE_DA, "" },  /* fuzzy */
/* de */ { IDS_RAM_SIZE_DE, "RAM Gr��e" },
/* es */ { IDS_RAM_SIZE_ES, "Tama�o RAM" },
/* fr */ { IDS_RAM_SIZE_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAM_SIZE_HU, "" },  /* fuzzy */
/* it */ { IDS_RAM_SIZE_IT, "" },  /* fuzzy */
/* ko */ { IDS_RAM_SIZE_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAM_SIZE_NL, "RAM grootte" },
/* pl */ { IDS_RAM_SIZE_PL, "Rozmiar RAM" },
/* ru */ { IDS_RAM_SIZE_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAM_SIZE_SV, "RAM-storlek" },
/* tr */ { IDS_RAM_SIZE_TR, "" },  /* fuzzy */

/* en */ { IDS_RAM_BLOCK_0400_0FFF,    "RAM Block $0400-$0FFF" },
/* da */ { IDS_RAM_BLOCK_0400_0FFF_DA, "RAM-blok $0400-$0FFF" },
/* de */ { IDS_RAM_BLOCK_0400_0FFF_DE, "RAM Block $0400-$0FFF" },
/* es */ { IDS_RAM_BLOCK_0400_0FFF_ES, "Bloque RAM $0400-$0FFF" },
/* fr */ { IDS_RAM_BLOCK_0400_0FFF_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAM_BLOCK_0400_0FFF_HU, "Mem�ria blokk $0400-$0FFF" },
/* it */ { IDS_RAM_BLOCK_0400_0FFF_IT, "Blocco RAM $0400-$0FFF" },
/* ko */ { IDS_RAM_BLOCK_0400_0FFF_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAM_BLOCK_0400_0FFF_NL, "RAM blok $0400-$0FFF" },
/* pl */ { IDS_RAM_BLOCK_0400_0FFF_PL, "Blok RAM $0400-$0FFF" },
/* ru */ { IDS_RAM_BLOCK_0400_0FFF_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAM_BLOCK_0400_0FFF_SV, "RAM-block $0400-$0FFF" },
/* tr */ { IDS_RAM_BLOCK_0400_0FFF_TR, "RAM Blok $0400-$0FFF" },

/* en */ { IDS_RAM_BLOCK_0800_0FFF,    "RAM Block $0800-$0FFF" },
/* da */ { IDS_RAM_BLOCK_0800_0FFF_DA, "RAM-blok $0800-$0FFF" },
/* de */ { IDS_RAM_BLOCK_0800_0FFF_DE, "RAM Block $0800-$0FFF" },
/* es */ { IDS_RAM_BLOCK_0800_0FFF_ES, "Bloque RAM $0800-$0FFF" },
/* fr */ { IDS_RAM_BLOCK_0800_0FFF_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAM_BLOCK_0800_0FFF_HU, "Mem�ria blokk $0800-$0FFF" },
/* it */ { IDS_RAM_BLOCK_0800_0FFF_IT, "Blocco RAM $0800-$0FFF" },
/* ko */ { IDS_RAM_BLOCK_0800_0FFF_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAM_BLOCK_0800_0FFF_NL, "RAM blok $0800-$0FFF" },
/* pl */ { IDS_RAM_BLOCK_0800_0FFF_PL, "Blok RAM $0800-$0FFF" },
/* ru */ { IDS_RAM_BLOCK_0800_0FFF_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAM_BLOCK_0800_0FFF_SV, "RAM-block $0800-$0FFF" },
/* tr */ { IDS_RAM_BLOCK_0800_0FFF_TR, "RAM Blok $0800-$0FFF" },

/* en */ { IDS_RAM_BLOCK_1000_1FFF,    "RAM Block $1000-$1FFF" },
/* da */ { IDS_RAM_BLOCK_1000_1FFF_DA, "RAM-blok $1000-$1FFF" },
/* de */ { IDS_RAM_BLOCK_1000_1FFF_DE, "RAM Block $1000-$1FFF" },
/* es */ { IDS_RAM_BLOCK_1000_1FFF_ES, "Bloque RAM $1000-$1FFF" },
/* fr */ { IDS_RAM_BLOCK_1000_1FFF_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAM_BLOCK_1000_1FFF_HU, "Mem�ria blokk $1000-$1FFF" },
/* it */ { IDS_RAM_BLOCK_1000_1FFF_IT, "Blocco RAM $1000-$1FFF" },
/* ko */ { IDS_RAM_BLOCK_1000_1FFF_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAM_BLOCK_1000_1FFF_NL, "RAM blok $1000-$1FFF" },
/* pl */ { IDS_RAM_BLOCK_1000_1FFF_PL, "Blok RAM $1000-$1FFF" },
/* ru */ { IDS_RAM_BLOCK_1000_1FFF_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAM_BLOCK_1000_1FFF_SV, "RAM-block $1000-$1FFF" },
/* tr */ { IDS_RAM_BLOCK_1000_1FFF_TR, "RAM Blok $1000-$1FFF" },

/* en */ { IDS_RAM_BLOCK_2000_3FFF,    "RAM Block $2000-$3FFF" },
/* da */ { IDS_RAM_BLOCK_2000_3FFF_DA, "RAM-blok $2000-$3FFF" },
/* de */ { IDS_RAM_BLOCK_2000_3FFF_DE, "RAM Block $2000-$3FFF" },
/* es */ { IDS_RAM_BLOCK_2000_3FFF_ES, "Bloque RAM $2000-$3FFF" },
/* fr */ { IDS_RAM_BLOCK_2000_3FFF_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAM_BLOCK_2000_3FFF_HU, "Mem�ria blokk $2000-$3FFF" },
/* it */ { IDS_RAM_BLOCK_2000_3FFF_IT, "Blocco RAM $2000-$3FFF" },
/* ko */ { IDS_RAM_BLOCK_2000_3FFF_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAM_BLOCK_2000_3FFF_NL, "RAM blok $2000-$3FFF" },
/* pl */ { IDS_RAM_BLOCK_2000_3FFF_PL, "Blok RAM $2000-$3FFF" },
/* ru */ { IDS_RAM_BLOCK_2000_3FFF_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAM_BLOCK_2000_3FFF_SV, "RAM-block $2000-$3FFF" },
/* tr */ { IDS_RAM_BLOCK_2000_3FFF_TR, "RAM Blok $2000-$3FFF" },

/* en */ { IDS_RAM_BLOCK_4000_5FFF,    "RAM Block $4000-$5FFF" },
/* da */ { IDS_RAM_BLOCK_4000_5FFF_DA, "RAM-blok $4000-$5FFF" },
/* de */ { IDS_RAM_BLOCK_4000_5FFF_DE, "RAM Block $4000-$5FFF" },
/* es */ { IDS_RAM_BLOCK_4000_5FFF_ES, "Bloque RAM $4000-$5FFF" },
/* fr */ { IDS_RAM_BLOCK_4000_5FFF_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAM_BLOCK_4000_5FFF_HU, "Mem�ria blokk $4000-$5FFF" },
/* it */ { IDS_RAM_BLOCK_4000_5FFF_IT, "Blocco RAM $4000-$5FFF" },
/* ko */ { IDS_RAM_BLOCK_4000_5FFF_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAM_BLOCK_4000_5FFF_NL, "RAM blok $4000-$5FFF" },
/* pl */ { IDS_RAM_BLOCK_4000_5FFF_PL, "Blok RAM $4000-$5FFF" },
/* ru */ { IDS_RAM_BLOCK_4000_5FFF_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAM_BLOCK_4000_5FFF_SV, "RAM-block $4000-$5FFF" },
/* tr */ { IDS_RAM_BLOCK_4000_5FFF_TR, "RAM Blok $4000-$5FFF" },

/* en */ { IDS_RAM_BLOCK_6000_7FFF,    "RAM Block $6000-$7FFF" },
/* da */ { IDS_RAM_BLOCK_6000_7FFF_DA, "RAM-blok $6000-$7FFF" },
/* de */ { IDS_RAM_BLOCK_6000_7FFF_DE, "RAM Block $6000-$7FFF" },
/* es */ { IDS_RAM_BLOCK_6000_7FFF_ES, "Bloque RAM $6000-$7FFF" },
/* fr */ { IDS_RAM_BLOCK_6000_7FFF_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAM_BLOCK_6000_7FFF_HU, "Mem�ria blokk $6000-$7FFF" },
/* it */ { IDS_RAM_BLOCK_6000_7FFF_IT, "Blocco RAM $6000-$7FFF" },
/* ko */ { IDS_RAM_BLOCK_6000_7FFF_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAM_BLOCK_6000_7FFF_NL, "RAM blok $6000-$7FFF" },
/* pl */ { IDS_RAM_BLOCK_6000_7FFF_PL, "Blok RAM $6000-$7FFF" },
/* ru */ { IDS_RAM_BLOCK_6000_7FFF_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAM_BLOCK_6000_7FFF_SV, "RAM-block $6000-$7FFF" },
/* tr */ { IDS_RAM_BLOCK_6000_7FFF_TR, "RAM Blok $6000-$7FFF" },

/* en */ { IDS_RAM_BLOCK_A000_BFFF,    "RAM Block $A000-$BFFF" },
/* da */ { IDS_RAM_BLOCK_A000_BFFF_DA, "RAM-blok $A000-$BFFF" },
/* de */ { IDS_RAM_BLOCK_A000_BFFF_DE, "RAM Block $A000-$BFFF" },
/* es */ { IDS_RAM_BLOCK_A000_BFFF_ES, "Bloque RAM $A000-$BFFF" },
/* fr */ { IDS_RAM_BLOCK_A000_BFFF_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAM_BLOCK_A000_BFFF_HU, "Mem�ria blokk $A000-$BFFF" },
/* it */ { IDS_RAM_BLOCK_A000_BFFF_IT, "Blocco RAM $A000-$BFFF" },
/* ko */ { IDS_RAM_BLOCK_A000_BFFF_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAM_BLOCK_A000_BFFF_NL, "RAM blok $A000-$BFFF" },
/* pl */ { IDS_RAM_BLOCK_A000_BFFF_PL, "Blok RAM $A000-$BFFF" },
/* ru */ { IDS_RAM_BLOCK_A000_BFFF_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAM_BLOCK_A000_BFFF_SV, "RAM-block $A000-$BFFF" },
/* tr */ { IDS_RAM_BLOCK_A000_BFFF_TR, "RAM Blok $A000-$BFFF" },

/* en */ { IDS_RAM_BLOCK_C000_CFFF,    "RAM Block $C000-$CFFF" },
/* da */ { IDS_RAM_BLOCK_C000_CFFF_DA, "RAM-blok $C000-$CFFF" },
/* de */ { IDS_RAM_BLOCK_C000_CFFF_DE, "RAM Block $C000-$CFFF" },
/* es */ { IDS_RAM_BLOCK_C000_CFFF_ES, "Bloque RAM $C000-$CFFF" },
/* fr */ { IDS_RAM_BLOCK_C000_CFFF_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAM_BLOCK_C000_CFFF_HU, "Mem�ria blokk $C000-$CFFF" },
/* it */ { IDS_RAM_BLOCK_C000_CFFF_IT, "Blocco RAM $C000-$CFFF" },
/* ko */ { IDS_RAM_BLOCK_C000_CFFF_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAM_BLOCK_C000_CFFF_NL, "RAM blok $C000-$CFFF" },
/* pl */ { IDS_RAM_BLOCK_C000_CFFF_PL, "Blok RAM $C000-$CFFF" },
/* ru */ { IDS_RAM_BLOCK_C000_CFFF_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAM_BLOCK_C000_CFFF_SV, "RAM-block $C000-$CFFF" },
/* tr */ { IDS_RAM_BLOCK_C000_CFFF_TR, "RAM Blok $C000-$CFFF" },

/* en */ { IDS_CBM2_SETTINGS,    "CBM2 settings" },
/* da */ { IDS_CBM2_SETTINGS_DA, "CBM2-indstillinger" },
/* de */ { IDS_CBM2_SETTINGS_DE, "CBM2 Einstellungen" },
/* es */ { IDS_CBM2_SETTINGS_ES, "Ajustes CBM2" },
/* fr */ { IDS_CBM2_SETTINGS_FR, "Param�tres CBM2" },
/* hu */ { IDS_CBM2_SETTINGS_HU, "CBM2 be�ll�t�sai" },
/* it */ { IDS_CBM2_SETTINGS_IT, "Impostazioni CBM2" },
/* ko */ { IDS_CBM2_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_CBM2_SETTINGS_NL, "CBM2 instellingen" },
/* pl */ { IDS_CBM2_SETTINGS_PL, "Ustawienia CBM2" },
/* ru */ { IDS_CBM2_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_CBM2_SETTINGS_SV, "CBM2-inst�llningar" },
/* tr */ { IDS_CBM2_SETTINGS_TR, "CBM2 ayarlar�" },

/* en */ { IDS_RESET_DATASETTE_WITH_CPU,    "Reset Datasette with CPU" },
/* da */ { IDS_RESET_DATASETTE_WITH_CPU_DA, "Reset Datasette ved CPU-reset" },
/* de */ { IDS_RESET_DATASETTE_WITH_CPU_DE, "Zur�cksetzen des Bandlaufwerks bei CPU Reset" },
/* es */ { IDS_RESET_DATASETTE_WITH_CPU_ES, "Reiniciar Datasette con la CPU" },
/* fr */ { IDS_RESET_DATASETTE_WITH_CPU_FR, "R�initialiser la datassette avec l'UCT" },
/* hu */ { IDS_RESET_DATASETTE_WITH_CPU_HU, "Alaphelyzetbe hoz�s CPU Reset eset�n" },
/* it */ { IDS_RESET_DATASETTE_WITH_CPU_IT, "Reset del registratore al reset della CPU" },
/* ko */ { IDS_RESET_DATASETTE_WITH_CPU_KO, "����Ÿ�� �� CPU �� ���� �Ͻÿ�" },
/* nl */ { IDS_RESET_DATASETTE_WITH_CPU_NL, "Reset Datasette met CPU" },
/* pl */ { IDS_RESET_DATASETTE_WITH_CPU_PL, "Resetuj magnetofon razem z CPU" },
/* ru */ { IDS_RESET_DATASETTE_WITH_CPU_RU, "" },  /* fuzzy */
/* sv */ { IDS_RESET_DATASETTE_WITH_CPU_SV, "Nollst�ll Datasette med CPU" },
/* tr */ { IDS_RESET_DATASETTE_WITH_CPU_TR, "CPU ile birlikte Teyp'i resetle" },

/* en */ { IDS_ADDITIONAL_DELAY,    "Additional Delay" },
/* da */ { IDS_ADDITIONAL_DELAY_DA, "Yderligere forsinkelse" },
/* de */ { IDS_ADDITIONAL_DELAY_DE, "Zus�tzliche Verz�gerung" },
/* es */ { IDS_ADDITIONAL_DELAY_ES, "Retardo adicional" },
/* fr */ { IDS_ADDITIONAL_DELAY_FR, "D�lai additionnel" },
/* hu */ { IDS_ADDITIONAL_DELAY_HU, "T�bblet sz�net" },
/* it */ { IDS_ADDITIONAL_DELAY_IT, "Ritardo aggiuntivo" },
/* ko */ { IDS_ADDITIONAL_DELAY_KO, "" },  /* fuzzy */
/* nl */ { IDS_ADDITIONAL_DELAY_NL, "Extra vertraging" },
/* pl */ { IDS_ADDITIONAL_DELAY_PL, "Dodatkowy delay" },
/* ru */ { IDS_ADDITIONAL_DELAY_RU, "" },  /* fuzzy */
/* sv */ { IDS_ADDITIONAL_DELAY_SV, "Ytterligare f�rdr�jning" },
/* tr */ { IDS_ADDITIONAL_DELAY_TR, "Ekstra Bekletme" },

/* en */ { IDS_DELAY_AT_ZERO_VALUES,    "Datasette zero gap delay" },
/* da */ { IDS_DELAY_AT_ZERO_VALUES_DA, "Datasette nulgabs-forsinkelse" },
/* de */ { IDS_DELAY_AT_ZERO_VALUES_DE, "Bandlaufwerk Zero Gap Verz�gerung" },
/* es */ { IDS_DELAY_AT_ZERO_VALUES_ES, "Retardo datasette zero gap" },
/* fr */ { IDS_DELAY_AT_ZERO_VALUES_FR, "D�lai du datassette lors de la lecture des groupes de z�ros" },
/* hu */ { IDS_DELAY_AT_ZERO_VALUES_HU, "Magn� �res r�s k�sleltet�s" },
/* it */ { IDS_DELAY_AT_ZERO_VALUES_IT, "Ritardo del gap di zero del registratore" },
/* ko */ { IDS_DELAY_AT_ZERO_VALUES_KO, "����Ÿ�� �� ���� ������" },
/* nl */ { IDS_DELAY_AT_ZERO_VALUES_NL, "Datasette zero gap vertraging" },
/* pl */ { IDS_DELAY_AT_ZERO_VALUES_PL, "Op�nienie pocz�tkowej przerwy magnetofonu" },
/* ru */ { IDS_DELAY_AT_ZERO_VALUES_RU, "" },  /* fuzzy */
/* sv */ { IDS_DELAY_AT_ZERO_VALUES_SV, "Datasette nollgapsf�rdr�jning" },
/* tr */ { IDS_DELAY_AT_ZERO_VALUES_TR, "Teyp s�f�r ara beklemesi" },

/* en */ { IDS_DATASETTE_SETTINGS,    "Datasette settings" },
/* da */ { IDS_DATASETTE_SETTINGS_DA, "Datasetteindstillinger" },
/* de */ { IDS_DATASETTE_SETTINGS_DE, "Datasette Einstellungen" },
/* es */ { IDS_DATASETTE_SETTINGS_ES, "Ajustes Datasette" },
/* fr */ { IDS_DATASETTE_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_DATASETTE_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_DATASETTE_SETTINGS_IT, "Impostazioni registratore" },
/* ko */ { IDS_DATASETTE_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_DATASETTE_SETTINGS_NL, "Datasette instellingen" },
/* pl */ { IDS_DATASETTE_SETTINGS_PL, "Ustawienia magnetofonu" },
/* ru */ { IDS_DATASETTE_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_DATASETTE_SETTINGS_SV, "Datasetteinst�llningar" },
/* tr */ { IDS_DATASETTE_SETTINGS_TR, "Teyp Ayarlar�" },

/* en */ { IDS_NEVER_EXTEND,    "Never extend" },
/* da */ { IDS_NEVER_EXTEND_DA, "Udvid aldrig" },
/* de */ { IDS_NEVER_EXTEND_DE, "Nie Erweitern" },
/* es */ { IDS_NEVER_EXTEND_ES, "No extender nunca" },
/* fr */ { IDS_NEVER_EXTEND_FR, "Ne jamais �tendre" },
/* hu */ { IDS_NEVER_EXTEND_HU, "Nincs kiterjeszt�s" },
/* it */ { IDS_NEVER_EXTEND_IT, "Mai" },
/* ko */ { IDS_NEVER_EXTEND_KO, "���� ���������ʱ�" },
/* nl */ { IDS_NEVER_EXTEND_NL, "Nooit uitbreiden" },
/* pl */ { IDS_NEVER_EXTEND_PL, "Nigdy nie rozszerzaj" },
/* ru */ { IDS_NEVER_EXTEND_RU, "" },  /* fuzzy */
/* sv */ { IDS_NEVER_EXTEND_SV, "Ut�ka aldrig" },
/* tr */ { IDS_NEVER_EXTEND_TR, "Asla geni�letme" },

/* en */ { IDS_ASK_ON_EXTEND,    "Ask on extend" },
/* da */ { IDS_ASK_ON_EXTEND_DA, "Sp�rg ved udviddelse" },
/* de */ { IDS_ASK_ON_EXTEND_DE, "Bei Erweiterung R�ckfrage" },
/* es */ { IDS_ASK_ON_EXTEND_ES, "Preguntar antes de extender" },
/* fr */ { IDS_ASK_ON_EXTEND_FR, "Demander avant d'�tendre" },
/* hu */ { IDS_ASK_ON_EXTEND_HU, "K�rd�s kiterjeszt�s eset�n" },
/* it */ { IDS_ASK_ON_EXTEND_IT, "Chiedi all'accesso" },
/* ko */ { IDS_ASK_ON_EXTEND_KO, "�����ϴ°Ϳ� ���� ����" },
/* nl */ { IDS_ASK_ON_EXTEND_NL, "Vragen bij uitbreiden" },
/* pl */ { IDS_ASK_ON_EXTEND_PL, "Zapytaj przy rozszerzaniu" },
/* ru */ { IDS_ASK_ON_EXTEND_RU, "" },  /* fuzzy */
/* sv */ { IDS_ASK_ON_EXTEND_SV, "Fr�ga vid ut�kning" },
/* tr */ { IDS_ASK_ON_EXTEND_TR, "Geni�letirken sor" },

/* en */ { IDS_EXTEND_ON_ACCESS,    "Extend on access" },
/* da */ { IDS_EXTEND_ON_ACCESS_DA, "Udvid ved tilgang" },
/* de */ { IDS_EXTEND_ON_ACCESS_DE, "Erweitern wenn n�tig" },
/* es */ { IDS_EXTEND_ON_ACCESS_ES, "Extender al acceder" },
/* fr */ { IDS_EXTEND_ON_ACCESS_FR, "�tendre � l'acc�s" },
/* hu */ { IDS_EXTEND_ON_ACCESS_HU, "Kiterjeszt�s hozz�f�r�skor" },
/* it */ { IDS_EXTEND_ON_ACCESS_IT, "All'accesso" },
/* ko */ { IDS_EXTEND_ON_ACCESS_KO, "������ �����ϱ�" },
/* nl */ { IDS_EXTEND_ON_ACCESS_NL, "Uitbreiden bij toegang" },
/* pl */ { IDS_EXTEND_ON_ACCESS_PL, "Rozszerz przy dost�pie" },
/* ru */ { IDS_EXTEND_ON_ACCESS_RU, "" },  /* fuzzy */
/* sv */ { IDS_EXTEND_ON_ACCESS_SV, "Ut�ka vid �tkomst" },
/* tr */ { IDS_EXTEND_ON_ACCESS_TR, "Eri�ildi�inde geni�let" },

/* en */ { IDS_NO_TRAPS,    "No traps" },
/* da */ { IDS_NO_TRAPS_DA, "Ingen traps" },
/* de */ { IDS_NO_TRAPS_DE, "Keine Traps" },
/* es */ { IDS_NO_TRAPS_ES, "No interceptar" },
/* fr */ { IDS_NO_TRAPS_FR, "" },  /* fuzzy */
/* hu */ { IDS_NO_TRAPS_HU, "Folyamatos emul�ci�" },
/* it */ { IDS_NO_TRAPS_IT, "Non rilevare" },
/* ko */ { IDS_NO_TRAPS_KO, "Ʈ���� �����ϴ�" },
/* nl */ { IDS_NO_TRAPS_NL, "Geen traps" },
/* pl */ { IDS_NO_TRAPS_PL, "No traps" },
/* ru */ { IDS_NO_TRAPS_RU, "" },  /* fuzzy */
/* sv */ { IDS_NO_TRAPS_SV, "Ingen inf�ngning" },
/* tr */ { IDS_NO_TRAPS_TR, "Trap Yok" },

/* en */ { IDS_SKIP_CYCLES,    "Skip cycles" },
/* da */ { IDS_SKIP_CYCLES_DA, "Spring over cykler" },
/* de */ { IDS_SKIP_CYCLES_DE, "Zyklen auslassen" },
/* es */ { IDS_SKIP_CYCLES_ES, "Saltar ciclos" },
/* fr */ { IDS_SKIP_CYCLES_FR, "Sauter des cycles" },
/* hu */ { IDS_SKIP_CYCLES_HU, "Ciklusok kihagy�sa" },
/* it */ { IDS_SKIP_CYCLES_IT, "Salta cicli" },
/* ko */ { IDS_SKIP_CYCLES_KO, "����Ŭ �Ѿ��" },
/* nl */ { IDS_SKIP_CYCLES_NL, "Sla cycli over" },
/* pl */ { IDS_SKIP_CYCLES_PL, "Opuszczaj cykle" },
/* ru */ { IDS_SKIP_CYCLES_RU, "" },  /* fuzzy */
/* sv */ { IDS_SKIP_CYCLES_SV, "Hoppa cykler" },
/* tr */ { IDS_SKIP_CYCLES_TR, "Cyclelar� atla" },

/* en */ { IDS_TRAP_IDLE,    "Trap idle" },
/* da */ { IDS_TRAP_IDLE_DA, "Fang inaktive" },
/* de */ { IDS_TRAP_IDLE_DE, "Trap idle" },
/* es */ { IDS_TRAP_IDLE_ES, "Interceptar tiempos muertos" },
/* fr */ { IDS_TRAP_IDLE_FR, "Traper l�inactivit�" },
/* hu */ { IDS_TRAP_IDLE_HU, "�res ciklusok kihagy�sa" },
/* it */ { IDS_TRAP_IDLE_IT, "Rileva inattivit�" },
/* ko */ { IDS_TRAP_IDLE_KO, "Ʈ�� ���̵�" },
/* nl */ { IDS_TRAP_IDLE_NL, "Trap idle" },
/* pl */ { IDS_TRAP_IDLE_PL, "Trap idle" },
/* ru */ { IDS_TRAP_IDLE_RU, "" },  /* fuzzy */
/* sv */ { IDS_TRAP_IDLE_SV, "F�nga inaktiva" },
/* tr */ { IDS_TRAP_IDLE_TR, "Trap bo�a vakit ge�irme" },

/* en */ { IDS_DRIVE_TYPE,    "Drive type" },
/* da */ { IDS_DRIVE_TYPE_DA, "Drevtype" },
/* de */ { IDS_DRIVE_TYPE_DE, "Ger�te Typ" },
/* es */ { IDS_DRIVE_TYPE_ES, "Tipo unidad disco" },
/* fr */ { IDS_DRIVE_TYPE_FR, "Type de lecteur" },
/* hu */ { IDS_DRIVE_TYPE_HU, "Lemezegys�g t�pus" },
/* it */ { IDS_DRIVE_TYPE_IT, "Tipo drive" },
/* ko */ { IDS_DRIVE_TYPE_KO, "" },  /* fuzzy */
/* nl */ { IDS_DRIVE_TYPE_NL, "Drivesoort" },
/* pl */ { IDS_DRIVE_TYPE_PL, "Typ nap�du" },
/* ru */ { IDS_DRIVE_TYPE_RU, "" },  /* fuzzy */
/* sv */ { IDS_DRIVE_TYPE_SV, "Enhetstyp" },
/* tr */ { IDS_DRIVE_TYPE_TR, "S�r�c� tipi" },

/* en */ { IDS_40_TRACK_HANDLING,    "40 track handling" },
/* da */ { IDS_40_TRACK_HANDLING_DA, "H�ndtering af 40 spor" },
/* de */ { IDS_40_TRACK_HANDLING_DE, "40 Spur Umgang" },
/* es */ { IDS_40_TRACK_HANDLING_ES, "Manipulador 40 pistas" },
/* fr */ { IDS_40_TRACK_HANDLING_FR, "" },  /* fuzzy */
/* hu */ { IDS_40_TRACK_HANDLING_HU, "40 s�v kezel�se" },
/* it */ { IDS_40_TRACK_HANDLING_IT, "Gestione 40 tracce" },
/* ko */ { IDS_40_TRACK_HANDLING_KO, "" },  /* fuzzy */
/* nl */ { IDS_40_TRACK_HANDLING_NL, "40-sporenondersteuning" },
/* pl */ { IDS_40_TRACK_HANDLING_PL, "Obs�uga 40 �cie�ek" },
/* ru */ { IDS_40_TRACK_HANDLING_RU, "" },  /* fuzzy */
/* sv */ { IDS_40_TRACK_HANDLING_SV, "Hantering av 40 sp�r" },
/* tr */ { IDS_40_TRACK_HANDLING_TR, "40 track i�leme" },

/* en */ { IDS_DRIVE_EXPANSION,    "Drive expansion" },
/* da */ { IDS_DRIVE_EXPANSION_DA, "Drevudviddelse" },
/* de */ { IDS_DRIVE_EXPANSION_DE, "Laufwerk Erweiterung" },
/* es */ { IDS_DRIVE_EXPANSION_ES, "Expansi�n Unidad disco" },
/* fr */ { IDS_DRIVE_EXPANSION_FR, "Expansion de lecteur" },
/* hu */ { IDS_DRIVE_EXPANSION_HU, "Lemezegys�g b�v�t�s" },
/* it */ { IDS_DRIVE_EXPANSION_IT, "Espasione del drive" },
/* ko */ { IDS_DRIVE_EXPANSION_KO, "" },  /* fuzzy */
/* nl */ { IDS_DRIVE_EXPANSION_NL, "Drive uitbreiding" },
/* pl */ { IDS_DRIVE_EXPANSION_PL, "Rozszerzenie nap�du" },
/* ru */ { IDS_DRIVE_EXPANSION_RU, "" },  /* fuzzy */
/* sv */ { IDS_DRIVE_EXPANSION_SV, "Enhetsut�kning" },
/* tr */ { IDS_DRIVE_EXPANSION_TR, "S�r�c� geni�lemesi" },

/* en */ { IDS_IDLE_METHOD,    "Idle method" },
/* da */ { IDS_IDLE_METHOD_DA, "Pausemetode" },
/* de */ { IDS_IDLE_METHOD_DE, "Idle Methode" },
/* es */ { IDS_IDLE_METHOD_ES, "Metodo tiempo inactivo" },
/* fr */ { IDS_IDLE_METHOD_FR, "" },  /* fuzzy */
/* hu */ { IDS_IDLE_METHOD_HU, "�resj�rat m�d" },
/* it */ { IDS_IDLE_METHOD_IT, "Rileva inattivit�" },
/* ko */ { IDS_IDLE_METHOD_KO, "" },  /* fuzzy */
/* nl */ { IDS_IDLE_METHOD_NL, "Idlemethode" },
/* pl */ { IDS_IDLE_METHOD_PL, "Metoda bezczynno�ci" },
/* ru */ { IDS_IDLE_METHOD_RU, "" },  /* fuzzy */
/* sv */ { IDS_IDLE_METHOD_SV, "Pausmetod" },
/* tr */ { IDS_IDLE_METHOD_TR, "Bo�a vakit ge�irme metodu" },

/* en */ { IDS_PARALLEL_CABLE,    "Parallel cable" },
/* da */ { IDS_PARALLEL_CABLE_DA, "Parallelkabel" },
/* de */ { IDS_PARALLEL_CABLE_DE, "Parallel Kabel" },
/* es */ { IDS_PARALLEL_CABLE_ES, "Cable paralelo" },
/* fr */ { IDS_PARALLEL_CABLE_FR, "C�ble parall�le" },
/* hu */ { IDS_PARALLEL_CABLE_HU, "P�rhuzamos k�bel" },
/* it */ { IDS_PARALLEL_CABLE_IT, "Cavo parallelo" },
/* ko */ { IDS_PARALLEL_CABLE_KO, "���� ĳ�̺�" },
/* nl */ { IDS_PARALLEL_CABLE_NL, "Parallelle kabel" },
/* pl */ { IDS_PARALLEL_CABLE_PL, "��cze portu r�wnoleg�ego" },
/* ru */ { IDS_PARALLEL_CABLE_RU, "" },  /* fuzzy */
/* sv */ { IDS_PARALLEL_CABLE_SV, "Parallellkabel" },
/* tr */ { IDS_PARALLEL_CABLE_TR, "Paralel kablo" },

/* en */ { IDS_DRIVE_SETTINGS,    "Drive settings" },
/* da */ { IDS_DRIVE_SETTINGS_DA, "Diskettedrevsindstillinger" },
/* de */ { IDS_DRIVE_SETTINGS_DE, "Floppy Einstellungen" },
/* es */ { IDS_DRIVE_SETTINGS_ES, "Ajustes unidad disco" },
/* fr */ { IDS_DRIVE_SETTINGS_FR, "Param�tres des lecteurs" },
/* hu */ { IDS_DRIVE_SETTINGS_HU, "Lemezegys�g be�ll�t�sai" },
/* it */ { IDS_DRIVE_SETTINGS_IT, "Impostazioni drive" },
/* ko */ { IDS_DRIVE_SETTINGS_KO, "����̺� ����" },
/* nl */ { IDS_DRIVE_SETTINGS_NL, "Drive instellingen" },
/* pl */ { IDS_DRIVE_SETTINGS_PL, "Ustawienia nap�du" },
/* ru */ { IDS_DRIVE_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_DRIVE_SETTINGS_SV, "Diskettenhetsinst�llningar" },
/* tr */ { IDS_DRIVE_SETTINGS_TR, "S�r�c� ayarlar�" },

/* en */ { IDS_GEORAM_SIZE,    "GEO-RAM size" },
/* da */ { IDS_GEORAM_SIZE_DA, "GEO-RAM-st�rrelse" },
/* de */ { IDS_GEORAM_SIZE_DE, "GEO-RAM Gr��e" },
/* es */ { IDS_GEORAM_SIZE_ES, "Tama�o GEO-RAM" },
/* fr */ { IDS_GEORAM_SIZE_FR, "" },  /* fuzzy */
/* hu */ { IDS_GEORAM_SIZE_HU, "" },  /* fuzzy */
/* it */ { IDS_GEORAM_SIZE_IT, "Dimensione GEO-RAM" },
/* ko */ { IDS_GEORAM_SIZE_KO, "" },  /* fuzzy */
/* nl */ { IDS_GEORAM_SIZE_NL, "GEO-RAM grootte" },
/* pl */ { IDS_GEORAM_SIZE_PL, "Rozmiar GEO-RAM" },
/* ru */ { IDS_GEORAM_SIZE_RU, "" },  /* fuzzy */
/* sv */ { IDS_GEORAM_SIZE_SV, "GEO-RAM-storlek" },
/* tr */ { IDS_GEORAM_SIZE_TR, "GEO-RAM boyutu" },

/* en */ { IDS_MASCUERADE_IO_SWAP,    "MasC=uerade I/O swap" },
/* da */ { IDS_MASCUERADE_IO_SWAP_DA, "" },  /* fuzzy */
/* de */ { IDS_MASCUERADE_IO_SWAP_DE, "MasC=uerade I/O swap" },
/* es */ { IDS_MASCUERADE_IO_SWAP_ES, "Intercambio m�scara Entrada/Salida" },
/* fr */ { IDS_MASCUERADE_IO_SWAP_FR, "" },  /* fuzzy */
/* hu */ { IDS_MASCUERADE_IO_SWAP_HU, "" },  /* fuzzy */
/* it */ { IDS_MASCUERADE_IO_SWAP_IT, "" },  /* fuzzy */
/* ko */ { IDS_MASCUERADE_IO_SWAP_KO, "MasC=uerade I/O ����" },
/* nl */ { IDS_MASCUERADE_IO_SWAP_NL, "MasC=uerade I/O verwisseling" },
/* pl */ { IDS_MASCUERADE_IO_SWAP_PL, "Zamiana we/wy MasC=uerade" },
/* ru */ { IDS_MASCUERADE_IO_SWAP_RU, "" },  /* fuzzy */
/* sv */ { IDS_MASCUERADE_IO_SWAP_SV, "" },  /* fuzzy */
/* tr */ { IDS_MASCUERADE_IO_SWAP_TR, "" },  /* fuzzy */

/* en */ { IDS_GEORAM_FILENAME,    "GEO-RAM file" },
/* da */ { IDS_GEORAM_FILENAME_DA, "GEO-RAM-fil" },
/* de */ { IDS_GEORAM_FILENAME_DE, "GEO-RAM Datei" },
/* es */ { IDS_GEORAM_FILENAME_ES, "Fihcero GEO-RAM" },
/* fr */ { IDS_GEORAM_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_GEORAM_FILENAME_HU, "" },  /* fuzzy */
/* it */ { IDS_GEORAM_FILENAME_IT, "File GEO-RAM" },
/* ko */ { IDS_GEORAM_FILENAME_KO, "GEO-RAM ����" },
/* nl */ { IDS_GEORAM_FILENAME_NL, "GEO-RAM bestand" },
/* pl */ { IDS_GEORAM_FILENAME_PL, "Plik GEO-RAM" },
/* ru */ { IDS_GEORAM_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_GEORAM_FILENAME_SV, "GEO-RAM-fil" },
/* tr */ { IDS_GEORAM_FILENAME_TR, "GEO-RAM dosyas�" },

/* en */ { IDS_SAVE_GEORAM_IMAGE_WHEN_CHANGED,    "Save GEO-RAM image when changed" },
/* da */ { IDS_SAVE_GEORAM_IMAGE_WHEN_CHANGED_DA, "Gem GEO-RAM image ved �ndringer" },
/* de */ { IDS_SAVE_GEORAM_IMAGE_WHEN_CHANGED_DE, "GEO-RAM Imagedatei bei �nderung speichern" },
/* es */ { IDS_SAVE_GEORAM_IMAGE_WHEN_CHANGED_ES, "Grabar imagen GEO-RAM cuando cambie" },
/* fr */ { IDS_SAVE_GEORAM_IMAGE_WHEN_CHANGED_FR, "" },  /* fuzzy */
/* hu */ { IDS_SAVE_GEORAM_IMAGE_WHEN_CHANGED_HU, "" },  /* fuzzy */
/* it */ { IDS_SAVE_GEORAM_IMAGE_WHEN_CHANGED_IT, "Salva immagine GEO-RAM al cambio" },
/* ko */ { IDS_SAVE_GEORAM_IMAGE_WHEN_CHANGED_KO, "" },  /* fuzzy */
/* nl */ { IDS_SAVE_GEORAM_IMAGE_WHEN_CHANGED_NL, "GEO-RAM bestand opslaan indien gewijzigd" },
/* pl */ { IDS_SAVE_GEORAM_IMAGE_WHEN_CHANGED_PL, "Zapisuj obraz GEO-RAM przy zmianie" },
/* ru */ { IDS_SAVE_GEORAM_IMAGE_WHEN_CHANGED_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_GEORAM_IMAGE_WHEN_CHANGED_SV, "Spara GEO-RAM-avbildning vid �ndringar" },
/* tr */ { IDS_SAVE_GEORAM_IMAGE_WHEN_CHANGED_TR, "GEO-RAM imaj� de�i�ti�inde kaydet" },

/* en */ { IDS_GEORAM_FILENAME_SELECT,    "Select file for GEO-RAM" },
/* da */ { IDS_GEORAM_FILENAME_SELECT_DA, "V�lg fil for GEO-RAM" },
/* de */ { IDS_GEORAM_FILENAME_SELECT_DE, "Datei f�r GEO-RAM ausw�hlen" },
/* es */ { IDS_GEORAM_FILENAME_SELECT_ES, "Seleccionar fichero para GEO-RAM" },
/* fr */ { IDS_GEORAM_FILENAME_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_GEORAM_FILENAME_SELECT_HU, "" },  /* fuzzy */
/* it */ { IDS_GEORAM_FILENAME_SELECT_IT, "Seleziona file per GEO-RAM" },
/* ko */ { IDS_GEORAM_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_GEORAM_FILENAME_SELECT_NL, "Selecteer bestand voor GEO-RAM" },
/* pl */ { IDS_GEORAM_FILENAME_SELECT_PL, "Wybierz plik GEO-RAM" },
/* ru */ { IDS_GEORAM_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_GEORAM_FILENAME_SELECT_SV, "V�lj fil f�r GEO-RAM" },
/* tr */ { IDS_GEORAM_FILENAME_SELECT_TR, "GEO-RAM i�in dosya se�in" },

/* en */ { IDS_GEORAM_SETTINGS,    "GEO-RAM settings" },
/* da */ { IDS_GEORAM_SETTINGS_DA, "GEO-RAM-indstillinger" },
/* de */ { IDS_GEORAM_SETTINGS_DE, "GEO-RAM Einstellungen" },
/* es */ { IDS_GEORAM_SETTINGS_ES, "Ajustes GEO-RAM" },
/* fr */ { IDS_GEORAM_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_GEORAM_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_GEORAM_SETTINGS_IT, "Impostazioni GEO-RAM" },
/* ko */ { IDS_GEORAM_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_GEORAM_SETTINGS_NL, "GEO-RAM instellingen" },
/* pl */ { IDS_GEORAM_SETTINGS_PL, "Ustawienia GEO-RAM" },
/* ru */ { IDS_GEORAM_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_GEORAM_SETTINGS_SV, "GEO-RAM-inst�llningar" },
/* tr */ { IDS_GEORAM_SETTINGS_TR, "GEO-RAM ayarlar�" },

/* en */ { IDS_EXPERT_MODE,    "Expert Cartridge mode" },
/* da */ { IDS_EXPERT_MODE_DA, "Expert Cartridge-tilstand" },
/* de */ { IDS_EXPERT_MODE_DE, "Expert Cartridge Modus" },
/* es */ { IDS_EXPERT_MODE_ES, "Modo Expert Cartridge" },
/* fr */ { IDS_EXPERT_MODE_FR, "" },  /* fuzzy */
/* hu */ { IDS_EXPERT_MODE_HU, "" },  /* fuzzy */
/* it */ { IDS_EXPERT_MODE_IT, "Modalit� Expert Cartridge" },
/* ko */ { IDS_EXPERT_MODE_KO, "" },  /* fuzzy */
/* nl */ { IDS_EXPERT_MODE_NL, "Expert Cartridge modus" },
/* pl */ { IDS_EXPERT_MODE_PL, "Tryb Expert Cartridge" },
/* ru */ { IDS_EXPERT_MODE_RU, "" },  /* fuzzy */
/* sv */ { IDS_EXPERT_MODE_SV, "Expert Cartridge-l�ge" },
/* tr */ { IDS_EXPERT_MODE_TR, "Expert Kartu�u modu" },

/* en */ { IDS_OFF,    "Off" },
/* da */ { IDS_OFF_DA, "Slukket" },
/* de */ { IDS_OFF_DE, "Aus" },
/* es */ { IDS_OFF_ES, "Apagado" },
/* fr */ { IDS_OFF_FR, "Off" },
/* hu */ { IDS_OFF_HU, "Ki" },
/* it */ { IDS_OFF_IT, "No" },
/* ko */ { IDS_OFF_KO, "����" },
/* nl */ { IDS_OFF_NL, "Uit" },
/* pl */ { IDS_OFF_PL, "Wy��cz" },
/* ru */ { IDS_OFF_RU, "" },  /* fuzzy */
/* sv */ { IDS_OFF_SV, "Av" },
/* tr */ { IDS_OFF_TR, "Kapal�" },

/* en */ { IDS_PRG,    "Prg" },
/* da */ { IDS_PRG_DA, "Prg" },
/* de */ { IDS_PRG_DE, "Prg" },
/* es */ { IDS_PRG_ES, "Prg" },
/* fr */ { IDS_PRG_FR, "Prg" },
/* hu */ { IDS_PRG_HU, "Prg" },
/* it */ { IDS_PRG_IT, "Prg" },
/* ko */ { IDS_PRG_KO, "Prg" },
/* nl */ { IDS_PRG_NL, "Prg" },
/* pl */ { IDS_PRG_PL, "Prg" },
/* ru */ { IDS_PRG_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRG_SV, "Prg" },
/* tr */ { IDS_PRG_TR, "Prg" },

/* en */ { IDS_ON,    "On" },
/* da */ { IDS_ON_DA, "T�ndt" },
/* de */ { IDS_ON_DE, "Ein" },
/* es */ { IDS_ON_ES, "Encendido" },
/* fr */ { IDS_ON_FR, "On" },
/* hu */ { IDS_ON_HU, "Be" },
/* it */ { IDS_ON_IT, "S�" },
/* ko */ { IDS_ON_KO, "����" },
/* nl */ { IDS_ON_NL, "Aan" },
/* pl */ { IDS_ON_PL, "W��cz" },
/* ru */ { IDS_ON_RU, "" },  /* fuzzy */
/* sv */ { IDS_ON_SV, "P�" },
/* tr */ { IDS_ON_TR, "A��k" },

/* en */ { IDS_EXPERT_FILENAME,    "Expert Cartridge file" },
/* da */ { IDS_EXPERT_FILENAME_DA, "Expert Cartridge-fil" },
/* de */ { IDS_EXPERT_FILENAME_DE, "Expert Cartridge Imagedatei" },
/* es */ { IDS_EXPERT_FILENAME_ES, "Fichero Expert Cartrige" },
/* fr */ { IDS_EXPERT_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_EXPERT_FILENAME_HU, "" },  /* fuzzy */
/* it */ { IDS_EXPERT_FILENAME_IT, "File Expert Cartridge" },
/* ko */ { IDS_EXPERT_FILENAME_KO, "Expert īƮ���� ����" },
/* nl */ { IDS_EXPERT_FILENAME_NL, "Expert Cartridge bestand" },
/* pl */ { IDS_EXPERT_FILENAME_PL, "Plik Expert Cartridge" },
/* ru */ { IDS_EXPERT_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_EXPERT_FILENAME_SV, "Expert Cartridge-fil" },
/* tr */ { IDS_EXPERT_FILENAME_TR, "Expert Kartu�u dosyas�" },

/* en */ { IDS_SAVE_EXPERT_IMAGE_WHEN_CHANGED,    "Save Expert Cartridge image when changed" },
/* da */ { IDS_SAVE_EXPERT_IMAGE_WHEN_CHANGED_DA, "Gem Expert Cartridge image ved �ndringer" },
/* de */ { IDS_SAVE_EXPERT_IMAGE_WHEN_CHANGED_DE, "Expert Cartridge Imagedatei bei �nderungen speichern" },
/* es */ { IDS_SAVE_EXPERT_IMAGE_WHEN_CHANGED_ES, "Grabar imagen Expert Cartridge cuando cambie" },
/* fr */ { IDS_SAVE_EXPERT_IMAGE_WHEN_CHANGED_FR, "" },  /* fuzzy */
/* hu */ { IDS_SAVE_EXPERT_IMAGE_WHEN_CHANGED_HU, "" },  /* fuzzy */
/* it */ { IDS_SAVE_EXPERT_IMAGE_WHEN_CHANGED_IT, "Salva immagine Expert Cartridge al cambio" },
/* ko */ { IDS_SAVE_EXPERT_IMAGE_WHEN_CHANGED_KO, "" },  /* fuzzy */
/* nl */ { IDS_SAVE_EXPERT_IMAGE_WHEN_CHANGED_NL, "Expert Cartridge bestand opslaan indien gewijzigd" },
/* pl */ { IDS_SAVE_EXPERT_IMAGE_WHEN_CHANGED_PL, "Zapisuj obraz Expert Cartridge przy zmianie" },
/* ru */ { IDS_SAVE_EXPERT_IMAGE_WHEN_CHANGED_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_EXPERT_IMAGE_WHEN_CHANGED_SV, "Spara Expert Cartrdige-avbildning vid �ndringar" },
/* tr */ { IDS_SAVE_EXPERT_IMAGE_WHEN_CHANGED_TR, "Expert Kartu� imaj�n� de�i�ti�inde kaydet" },

/* en */ { IDS_EXPERT_FILENAME_SELECT,    "Select file for Expert Cartridge" },
/* da */ { IDS_EXPERT_FILENAME_SELECT_DA, "V�lg fil for Expert Cartridge" },
/* de */ { IDS_EXPERT_FILENAME_SELECT_DE, "Export Cartridge Imagedatei ausw�hlen" },
/* es */ { IDS_EXPERT_FILENAME_SELECT_ES, "Seleccionar fichero para Expert Cartrige" },
/* fr */ { IDS_EXPERT_FILENAME_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_EXPERT_FILENAME_SELECT_HU, "" },  /* fuzzy */
/* it */ { IDS_EXPERT_FILENAME_SELECT_IT, "Seleziona file per Expert Cartridge" },
/* ko */ { IDS_EXPERT_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_EXPERT_FILENAME_SELECT_NL, "Selecteer bestand voor Expert Cartridge" },
/* pl */ { IDS_EXPERT_FILENAME_SELECT_PL, "Wybierz plik Expert Cartridge" },
/* ru */ { IDS_EXPERT_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_EXPERT_FILENAME_SELECT_SV, "V�lj fil f�r Expert Cartridge" },
/* tr */ { IDS_EXPERT_FILENAME_SELECT_TR, "Expert Kartu�u i�in dosya se�in" },

/* en */ { IDS_EXPERT_SETTINGS,    "Expert Cartridge settings" },
/* da */ { IDS_EXPERT_SETTINGS_DA, "Expert Cartridge-indstillinger" },
/* de */ { IDS_EXPERT_SETTINGS_DE, "Expert Cartridge Einstellungen" },
/* es */ { IDS_EXPERT_SETTINGS_ES, "Ajustes Expert Cartrige" },
/* fr */ { IDS_EXPERT_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_EXPERT_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_EXPERT_SETTINGS_IT, "Impostazioni Expert Cartridge" },
/* ko */ { IDS_EXPERT_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_EXPERT_SETTINGS_NL, "Expert Cartridge instellingen" },
/* pl */ { IDS_EXPERT_SETTINGS_PL, "Ustawienia Expert Cartridge" },
/* ru */ { IDS_EXPERT_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_EXPERT_SETTINGS_SV, "Inst�llningar f�r Expert Cartridge" },
/* tr */ { IDS_EXPERT_SETTINGS_TR, "Expert Kartu�u ayarlar�" },

/* en */ { IDS_DQBB_FILENAME,    "DQBB file" },
/* da */ { IDS_DQBB_FILENAME_DA, "DQBB-fil" },
/* de */ { IDS_DQBB_FILENAME_DE, "DQBB Datei" },
/* es */ { IDS_DQBB_FILENAME_ES, "Fichero DQBB" },
/* fr */ { IDS_DQBB_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_DQBB_FILENAME_HU, "DQBB f�jl" },
/* it */ { IDS_DQBB_FILENAME_IT, "File DQBB" },
/* ko */ { IDS_DQBB_FILENAME_KO, "DQBB ����" },
/* nl */ { IDS_DQBB_FILENAME_NL, "DQBB bestand" },
/* pl */ { IDS_DQBB_FILENAME_PL, "Plik DQBB" },
/* ru */ { IDS_DQBB_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_DQBB_FILENAME_SV, "DQBB-fil" },
/* tr */ { IDS_DQBB_FILENAME_TR, "DQBB dosyas�" },

/* en */ { IDS_SAVE_DQBB_IMAGE_WHEN_CHANGED,    "Save DQBB image when changed" },
/* da */ { IDS_SAVE_DQBB_IMAGE_WHEN_CHANGED_DA, "Gem DQBB image ved �ndringer" },
/* de */ { IDS_SAVE_DQBB_IMAGE_WHEN_CHANGED_DE, "DQBB Imagedatei bei �nderung speichern" },
/* es */ { IDS_SAVE_DQBB_IMAGE_WHEN_CHANGED_ES, "Grabar imagen DQBB cuando cambie" },
/* fr */ { IDS_SAVE_DQBB_IMAGE_WHEN_CHANGED_FR, "" },  /* fuzzy */
/* hu */ { IDS_SAVE_DQBB_IMAGE_WHEN_CHANGED_HU, "" },  /* fuzzy */
/* it */ { IDS_SAVE_DQBB_IMAGE_WHEN_CHANGED_IT, "Salva immagine DQBB al cambio" },
/* ko */ { IDS_SAVE_DQBB_IMAGE_WHEN_CHANGED_KO, "" },  /* fuzzy */
/* nl */ { IDS_SAVE_DQBB_IMAGE_WHEN_CHANGED_NL, "DQBB bestand opslaan indien gewijzigd" },
/* pl */ { IDS_SAVE_DQBB_IMAGE_WHEN_CHANGED_PL, "Zapisuj obraz DQBB przy zmianie" },
/* ru */ { IDS_SAVE_DQBB_IMAGE_WHEN_CHANGED_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_DQBB_IMAGE_WHEN_CHANGED_SV, "Spara DQBB-avbildning vid �ndringar" },
/* tr */ { IDS_SAVE_DQBB_IMAGE_WHEN_CHANGED_TR, "DQBB imaj� de�i�ti�inde kaydet" },

/* en */ { IDS_DQBB_FILENAME_SELECT,    "Select file for DQBB" },
/* da */ { IDS_DQBB_FILENAME_SELECT_DA, "V�lg fil for DQBB" },
/* de */ { IDS_DQBB_FILENAME_SELECT_DE, "Datei f�r DQBB ausw�hlen" },
/* es */ { IDS_DQBB_FILENAME_SELECT_ES, "Seleccionar fichero para DQBB" },
/* fr */ { IDS_DQBB_FILENAME_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_DQBB_FILENAME_SELECT_HU, "V�lasszon f�jlt a DQBB-hez" },
/* it */ { IDS_DQBB_FILENAME_SELECT_IT, "Seleziona file per DQBB" },
/* ko */ { IDS_DQBB_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_DQBB_FILENAME_SELECT_NL, "Selecteer bestand voor DQBB" },
/* pl */ { IDS_DQBB_FILENAME_SELECT_PL, "Wybierz plik DQBB" },
/* ru */ { IDS_DQBB_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_DQBB_FILENAME_SELECT_SV, "V�lj fil f�r DQBB" },
/* tr */ { IDS_DQBB_FILENAME_SELECT_TR, "DQBB i�in dosya se�" },

/* en */ { IDS_DQBB_SETTINGS,    "Double Quick Brown Box settings" },
/* da */ { IDS_DQBB_SETTINGS_DA, "Double Quick Brown Box indstillinger" },
/* de */ { IDS_DQBB_SETTINGS_DE, "Double Quick Brown Box Einstellungen" },
/* es */ { IDS_DQBB_SETTINGS_ES, "Ajustes Double Quick Brown Box" },
/* fr */ { IDS_DQBB_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_DQBB_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_DQBB_SETTINGS_IT, "Impostazioni Double Quick Brown Box" },
/* ko */ { IDS_DQBB_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_DQBB_SETTINGS_NL, "Double Quick Brown Box instellingen" },
/* pl */ { IDS_DQBB_SETTINGS_PL, "Ustawienia Double Quick Brown Box" },
/* ru */ { IDS_DQBB_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_DQBB_SETTINGS_SV, "Inst�llninga f�r dubbel Quick Brown Box" },
/* tr */ { IDS_DQBB_SETTINGS_TR, "Double Quick Brown Box ayarlar�" },

/* en */ { IDS_ISEPIC_SETTINGS,    "ISEPIC settings" },
/* da */ { IDS_ISEPIC_SETTINGS_DA, "ISEPIC-indstillinger" },
/* de */ { IDS_ISEPIC_SETTINGS_DE, "ISEPIC Einstellungen" },
/* es */ { IDS_ISEPIC_SETTINGS_ES, "Ajustes ISEPIC" },
/* fr */ { IDS_ISEPIC_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_ISEPIC_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_ISEPIC_SETTINGS_IT, "Impostazioni ISEPIC" },
/* ko */ { IDS_ISEPIC_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_ISEPIC_SETTINGS_NL, "ISEPIC instellingen" },
/* pl */ { IDS_ISEPIC_SETTINGS_PL, "Ustawienia ISEPIC" },
/* ru */ { IDS_ISEPIC_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_ISEPIC_SETTINGS_SV, "ISEPIC-inst�llningar" },
/* tr */ { IDS_ISEPIC_SETTINGS_TR, "ISEPIC ayarlar�" },

/* en */ { IDS_ISEPIC_SWITCH,    "ISEPIC switch" },
/* da */ { IDS_ISEPIC_SWITCH_DA, "ISEPIC-kontakt" },
/* de */ { IDS_ISEPIC_SWITCH_DE, "ISEPIC Schalter" },
/* es */ { IDS_ISEPIC_SWITCH_ES, "interruptor ISEPIC" },
/* fr */ { IDS_ISEPIC_SWITCH_FR, "" },  /* fuzzy */
/* hu */ { IDS_ISEPIC_SWITCH_HU, "" },  /* fuzzy */
/* it */ { IDS_ISEPIC_SWITCH_IT, "Interruttore ISEPIC" },
/* ko */ { IDS_ISEPIC_SWITCH_KO, "" },  /* fuzzy */
/* nl */ { IDS_ISEPIC_SWITCH_NL, "ISEPIC schakelaar" },
/* pl */ { IDS_ISEPIC_SWITCH_PL, "Prze��cznik ISEPIC" },
/* ru */ { IDS_ISEPIC_SWITCH_RU, "" },  /* fuzzy */
/* sv */ { IDS_ISEPIC_SWITCH_SV, "ISEPIC-omkopplare" },
/* tr */ { IDS_ISEPIC_SWITCH_TR, "ISEPIC anahtar�" },

/* en */ { IDS_ISEPIC_FILENAME,    "ISEPIC file" },
/* da */ { IDS_ISEPIC_FILENAME_DA, "ISEPIC-fil" },
/* de */ { IDS_ISEPIC_FILENAME_DE, "ISEPIC Imagedatei" },
/* es */ { IDS_ISEPIC_FILENAME_ES, "Fichero ISEPIC" },
/* fr */ { IDS_ISEPIC_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_ISEPIC_FILENAME_HU, "" },  /* fuzzy */
/* it */ { IDS_ISEPIC_FILENAME_IT, "File ISEPIC" },
/* ko */ { IDS_ISEPIC_FILENAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_ISEPIC_FILENAME_NL, "ISEPIC bestand" },
/* pl */ { IDS_ISEPIC_FILENAME_PL, "Plik ISEPIC" },
/* ru */ { IDS_ISEPIC_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_ISEPIC_FILENAME_SV, "ISEPIC-fil" },
/* tr */ { IDS_ISEPIC_FILENAME_TR, "ISEPIC dosyas�" },

/* en */ { IDS_SAVE_ISEPIC_IMAGE_WHEN_CHANGED,    "Save ISEPIC image when changed" },
/* da */ { IDS_SAVE_ISEPIC_IMAGE_WHEN_CHANGED_DA, "Gem ISEPIC image ved �ndringer" },
/* de */ { IDS_SAVE_ISEPIC_IMAGE_WHEN_CHANGED_DE, "ISEPIC Imagedatei bei �nderung speichern" },
/* es */ { IDS_SAVE_ISEPIC_IMAGE_WHEN_CHANGED_ES, "Grabar imagen ISEPIC cuando cambie" },
/* fr */ { IDS_SAVE_ISEPIC_IMAGE_WHEN_CHANGED_FR, "" },  /* fuzzy */
/* hu */ { IDS_SAVE_ISEPIC_IMAGE_WHEN_CHANGED_HU, "" },  /* fuzzy */
/* it */ { IDS_SAVE_ISEPIC_IMAGE_WHEN_CHANGED_IT, "Salva immagine ISEPIC al cambio" },
/* ko */ { IDS_SAVE_ISEPIC_IMAGE_WHEN_CHANGED_KO, "" },  /* fuzzy */
/* nl */ { IDS_SAVE_ISEPIC_IMAGE_WHEN_CHANGED_NL, "ISEPIC bestand opslaan indien gewijzigd" },
/* pl */ { IDS_SAVE_ISEPIC_IMAGE_WHEN_CHANGED_PL, "Zapisuj obraz ISEPIC przy zmianie" },
/* ru */ { IDS_SAVE_ISEPIC_IMAGE_WHEN_CHANGED_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_ISEPIC_IMAGE_WHEN_CHANGED_SV, "Spara ISEPIC-avbildning vid �ndringar" },
/* tr */ { IDS_SAVE_ISEPIC_IMAGE_WHEN_CHANGED_TR, "ISEPIC imaj� de�i�ti�inde kaydet" },

/* en */ { IDS_ISEPIC_FILENAME_SELECT,    "Select file for ISEPIC" },
/* da */ { IDS_ISEPIC_FILENAME_SELECT_DA, "V�lg fil for ISEPIC" },
/* de */ { IDS_ISEPIC_FILENAME_SELECT_DE, "Datei f�r ISEPIC ausw�hlen" },
/* es */ { IDS_ISEPIC_FILENAME_SELECT_ES, "Seleccionar fichero para ISEPIC" },
/* fr */ { IDS_ISEPIC_FILENAME_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_ISEPIC_FILENAME_SELECT_HU, "" },  /* fuzzy */
/* it */ { IDS_ISEPIC_FILENAME_SELECT_IT, "Seleziona file per ISEPIC" },
/* ko */ { IDS_ISEPIC_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_ISEPIC_FILENAME_SELECT_NL, "Selecteer bestand voor ISEPIC" },
/* pl */ { IDS_ISEPIC_FILENAME_SELECT_PL, "Wybierz plik ISEPIC" },
/* ru */ { IDS_ISEPIC_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_ISEPIC_FILENAME_SELECT_SV, "V�lj fil f�r ISEPIC" },
/* tr */ { IDS_ISEPIC_FILENAME_SELECT_TR, "ISEPIC i�in dosya se�in" },

/* en */ { IDS_EASYFLASH_SETTINGS,    "EasyFlash settings" },
/* da */ { IDS_EASYFLASH_SETTINGS_DA, "EasyFlash-indstillinger" },
/* de */ { IDS_EASYFLASH_SETTINGS_DE, "EasyFlash Einstellungen" },
/* es */ { IDS_EASYFLASH_SETTINGS_ES, "Ajuestes EasyFlash" },
/* fr */ { IDS_EASYFLASH_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_EASYFLASH_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_EASYFLASH_SETTINGS_IT, "Impostazioni EasyFlash" },
/* ko */ { IDS_EASYFLASH_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_EASYFLASH_SETTINGS_NL, "EasyFlash instellingen" },
/* pl */ { IDS_EASYFLASH_SETTINGS_PL, "Ustawienia EasyFlash" },
/* ru */ { IDS_EASYFLASH_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_EASYFLASH_SETTINGS_SV, "EasyFlash-inst�llningar" },
/* tr */ { IDS_EASYFLASH_SETTINGS_TR, "EasyFlash ayarlar�" },

/* en */ { IDS_CONFIG_FILENAME_SELECT,    "Select config file" },
/* da */ { IDS_CONFIG_FILENAME_SELECT_DA, "V�lg konfigurationsfil" },
/* de */ { IDS_CONFIG_FILENAME_SELECT_DE, "Konfigurationsdateiname definieren" },
/* es */ { IDS_CONFIG_FILENAME_SELECT_ES, "Seleccionar fichero de configuraci�n" },
/* fr */ { IDS_CONFIG_FILENAME_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_CONFIG_FILENAME_SELECT_HU, "V�lassza ki a konfigur�ci�s f�jlt" },
/* it */ { IDS_CONFIG_FILENAME_SELECT_IT, "Seleziona il file di configurazione" },
/* ko */ { IDS_CONFIG_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_CONFIG_FILENAME_SELECT_NL, "Selecteer configuratie bestand" },
/* pl */ { IDS_CONFIG_FILENAME_SELECT_PL, "Wybierz plik konfiguracji" },
/* ru */ { IDS_CONFIG_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_CONFIG_FILENAME_SELECT_SV, "Ange inst�llningsfil" },
/* tr */ { IDS_CONFIG_FILENAME_SELECT_TR, "Konfig�rasyon dosyas�n� se�in" },

/* en */ { IDS_JOYSTICK_IN_PORT_1,    "Joystick in port #1" },
/* da */ { IDS_JOYSTICK_IN_PORT_1_DA, "Joystick i port 1" },
/* de */ { IDS_JOYSTICK_IN_PORT_1_DE, "Joystick in Port #1" },
/* es */ { IDS_JOYSTICK_IN_PORT_1_ES, "Joystick en puerto #1" },
/* fr */ { IDS_JOYSTICK_IN_PORT_1_FR, "" },  /* fuzzy */
/* hu */ { IDS_JOYSTICK_IN_PORT_1_HU, "Botkorm�ny az 1-es porton" },
/* it */ { IDS_JOYSTICK_IN_PORT_1_IT, "Joystick nella porta #1" },
/* ko */ { IDS_JOYSTICK_IN_PORT_1_KO, "1�� ��Ʈ ���̽�ƽ" },
/* nl */ { IDS_JOYSTICK_IN_PORT_1_NL, "Joystick in poort #1" },
/* pl */ { IDS_JOYSTICK_IN_PORT_1_PL, "Joystick w porcie #1" },
/* ru */ { IDS_JOYSTICK_IN_PORT_1_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOYSTICK_IN_PORT_1_SV, "Styrspak i spelport 1" },
/* tr */ { IDS_JOYSTICK_IN_PORT_1_TR, "Joystick port #1'de" },

/* en */ { IDS_JOYSTICK_IN_PORT_2,    "Joystick in port #2" },
/* da */ { IDS_JOYSTICK_IN_PORT_2_DA, "Joystick i port 2" },
/* de */ { IDS_JOYSTICK_IN_PORT_2_DE, "Joystick in Port #2" },
/* es */ { IDS_JOYSTICK_IN_PORT_2_ES, "Joystick en puerto #2" },
/* fr */ { IDS_JOYSTICK_IN_PORT_2_FR, "" },  /* fuzzy */
/* hu */ { IDS_JOYSTICK_IN_PORT_2_HU, "Botkorm�ny a 2-es porton" },
/* it */ { IDS_JOYSTICK_IN_PORT_2_IT, "Joystick nella porta #2" },
/* ko */ { IDS_JOYSTICK_IN_PORT_2_KO, "2�� ��Ʈ ���̽�ƽ" },
/* nl */ { IDS_JOYSTICK_IN_PORT_2_NL, "Joystick in poort #2" },
/* pl */ { IDS_JOYSTICK_IN_PORT_2_PL, "Joystick w porcie #2" },
/* ru */ { IDS_JOYSTICK_IN_PORT_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOYSTICK_IN_PORT_2_SV, "Styrspak i spelport 2" },
/* tr */ { IDS_JOYSTICK_IN_PORT_2_TR, "Joystick port #2'de" },

/* en */ { IDS_USERPORT_ADAPTER,    "Userport joystick adapter" },
/* da */ { IDS_USERPORT_ADAPTER_DA, "Brugerportjoystickadapter" },
/* de */ { IDS_USERPORT_ADAPTER_DE, "Userport Joystick Adapter" },
/* es */ { IDS_USERPORT_ADAPTER_ES, "Adaptador de puerto usuario joystick" },
/* fr */ { IDS_USERPORT_ADAPTER_FR, "" },  /* fuzzy */
/* hu */ { IDS_USERPORT_ADAPTER_HU, "Userport botkorm�ny adapter" },
/* it */ { IDS_USERPORT_ADAPTER_IT, "Adattatore joystick su userport" },
/* ko */ { IDS_USERPORT_ADAPTER_KO, "������Ʈ ���̽�ƽ �ƴ���" },
/* nl */ { IDS_USERPORT_ADAPTER_NL, "Userport joystick adapter" },
/* pl */ { IDS_USERPORT_ADAPTER_PL, "Z��cze userportu joysticka" },
/* ru */ { IDS_USERPORT_ADAPTER_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_ADAPTER_SV, "Adapter f�r anv�ndarportstyrspakar" },
/* tr */ { IDS_USERPORT_ADAPTER_TR, "Userport joystick d�n��t�r�c�" },

/* en */ { IDS_USERPORT_ADAPTER_TYPE,    "Userport joystick adapter type" },
/* da */ { IDS_USERPORT_ADAPTER_TYPE_DA, "Brugerportjoystickadapter-type" },
/* de */ { IDS_USERPORT_ADAPTER_TYPE_DE, "Userport Joystick Adadptertype" },
/* es */ { IDS_USERPORT_ADAPTER_TYPE_ES, "Tipo de adaptador de puerto usuario joystick" },
/* fr */ { IDS_USERPORT_ADAPTER_TYPE_FR, "" },  /* fuzzy */
/* hu */ { IDS_USERPORT_ADAPTER_TYPE_HU, "Userport botkorm�ny adapter t�pusa" },
/* it */ { IDS_USERPORT_ADAPTER_TYPE_IT, "Tipo adattatore joystick su userport" },
/* ko */ { IDS_USERPORT_ADAPTER_TYPE_KO, "������Ʈ ���̽�ƽ �ƴ��� ����" },
/* nl */ { IDS_USERPORT_ADAPTER_TYPE_NL, "Userport joystick adapter model" },
/* pl */ { IDS_USERPORT_ADAPTER_TYPE_PL, "Typ z��cza userportu joysticka" },
/* ru */ { IDS_USERPORT_ADAPTER_TYPE_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_ADAPTER_TYPE_SV, "Typ av adapter f�r anv�ndarportstyrspakar" },
/* tr */ { IDS_USERPORT_ADAPTER_TYPE_TR, "Userport joystick d�n��t�r�c� tipi" },

/* en */ { IDS_JOYSTICK_IN_USERPORT_PORT_1,    "Joystick in extra port #1" },
/* da */ { IDS_JOYSTICK_IN_USERPORT_PORT_1_DA, "Joystick i ekstra port #1" },
/* de */ { IDS_JOYSTICK_IN_USERPORT_PORT_1_DE, "Joystick in extra Port #1" },
/* es */ { IDS_JOYSTICK_IN_USERPORT_PORT_1_ES, "Joystick en puerto suplementario #1" },
/* fr */ { IDS_JOYSTICK_IN_USERPORT_PORT_1_FR, "" },  /* fuzzy */
/* hu */ { IDS_JOYSTICK_IN_USERPORT_PORT_1_HU, "" },  /* fuzzy */
/* it */ { IDS_JOYSTICK_IN_USERPORT_PORT_1_IT, "Joystick nella porta supplementare #1" },
/* ko */ { IDS_JOYSTICK_IN_USERPORT_PORT_1_KO, "����Ʈ�� ��Ʈ #1 �� ���̽�ƽ" },
/* nl */ { IDS_JOYSTICK_IN_USERPORT_PORT_1_NL, "Joystick in extra poort #1" },
/* pl */ { IDS_JOYSTICK_IN_USERPORT_PORT_1_PL, "Joystick w dodatkowym porcie #1" },
/* ru */ { IDS_JOYSTICK_IN_USERPORT_PORT_1_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOYSTICK_IN_USERPORT_PORT_1_SV, "Styrspak i extraport #1" },
/* tr */ { IDS_JOYSTICK_IN_USERPORT_PORT_1_TR, "Joystick ekstra port #1'de" },

/* en */ { IDS_JOYSTICK_IN_USERPORT_PORT_2,    "Joystick in extra port #2" },
/* da */ { IDS_JOYSTICK_IN_USERPORT_PORT_2_DA, "Joystick i ekstra port #2" },
/* de */ { IDS_JOYSTICK_IN_USERPORT_PORT_2_DE, "Joystick in extra Port #2" },
/* es */ { IDS_JOYSTICK_IN_USERPORT_PORT_2_ES, "Joystick en puerto suplementario #2" },
/* fr */ { IDS_JOYSTICK_IN_USERPORT_PORT_2_FR, "" },  /* fuzzy */
/* hu */ { IDS_JOYSTICK_IN_USERPORT_PORT_2_HU, "" },  /* fuzzy */
/* it */ { IDS_JOYSTICK_IN_USERPORT_PORT_2_IT, "Joystick nella porta supplementare #2" },
/* ko */ { IDS_JOYSTICK_IN_USERPORT_PORT_2_KO, "����Ʈ�� ��Ʈ #2 �� ���̽�ƽ" },
/* nl */ { IDS_JOYSTICK_IN_USERPORT_PORT_2_NL, "Joystick in extra poort #2" },
/* pl */ { IDS_JOYSTICK_IN_USERPORT_PORT_2_PL, "Joystick w dodatkowym porcie #2" },
/* ru */ { IDS_JOYSTICK_IN_USERPORT_PORT_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOYSTICK_IN_USERPORT_PORT_2_SV, "Styrspak i extraport #2" },
/* tr */ { IDS_JOYSTICK_IN_USERPORT_PORT_2_TR, "Joystick ekstra port #2'de" },

/* en */ { IDS_SIDCART_JOY,    "SIDcart joystick" },
/* da */ { IDS_SIDCART_JOY_DA, "SIDcart joystick" },
/* de */ { IDS_SIDCART_JOY_DE, "SIDcart Joystick" },
/* es */ { IDS_SIDCART_JOY_ES, "Joystick SIDcart" },
/* fr */ { IDS_SIDCART_JOY_FR, "" },  /* fuzzy */
/* hu */ { IDS_SIDCART_JOY_HU, "SIDcart botkorm�ny" },
/* it */ { IDS_SIDCART_JOY_IT, "Joystick SIDcart" },
/* ko */ { IDS_SIDCART_JOY_KO, "SIDcard ���̽�ƽ" },
/* nl */ { IDS_SIDCART_JOY_NL, "SIDcart joystick" },
/* pl */ { IDS_SIDCART_JOY_PL, "Joystick SIDcart" },
/* ru */ { IDS_SIDCART_JOY_RU, "" },  /* fuzzy */
/* sv */ { IDS_SIDCART_JOY_SV, "SIDcart-styrspak" },
/* tr */ { IDS_SIDCART_JOY_TR, "SID kartu�u joystick'i" },


/* en */ { IDS_JOYSTICK_IN_SIDCART_PORT,    "Joystick in SIDcart joystick port" },
/* da */ { IDS_JOYSTICK_IN_SIDCART_PORT_DA, "Joystick i SIDcart joystickport" },
/* de */ { IDS_JOYSTICK_IN_SIDCART_PORT_DE, "Joystick in SIDcart Joystick Port" },
/* es */ { IDS_JOYSTICK_IN_SIDCART_PORT_ES, "Joystick en puerto joystick SIDcart" },
/* fr */ { IDS_JOYSTICK_IN_SIDCART_PORT_FR, "" },  /* fuzzy */
/* hu */ { IDS_JOYSTICK_IN_SIDCART_PORT_HU, "Botkorm�ny a SIDcart porton" },
/* it */ { IDS_JOYSTICK_IN_SIDCART_PORT_IT, "Joystick nella porta joystick su SIDcart" },
/* ko */ { IDS_JOYSTICK_IN_SIDCART_PORT_KO, "" },  /* fuzzy */
/* nl */ { IDS_JOYSTICK_IN_SIDCART_PORT_NL, "Joystick in SIDcart joystick poort" },
/* pl */ { IDS_JOYSTICK_IN_SIDCART_PORT_PL, "Joystick w porcie joysticka SIDcart" },
/* ru */ { IDS_JOYSTICK_IN_SIDCART_PORT_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOYSTICK_IN_SIDCART_PORT_SV, "Styrspak i SIDcart-spelport" },
/* tr */ { IDS_JOYSTICK_IN_SIDCART_PORT_TR, "Joystick SID kartu�u joystick portuna tak�l�" },

/* en */ { IDS_JOYSTICK_SETTINGS,    "Joystick settings" },
/* da */ { IDS_JOYSTICK_SETTINGS_DA, "Joystick indstillinger" },
/* de */ { IDS_JOYSTICK_SETTINGS_DE, "Joystick Einstellungen" },
/* es */ { IDS_JOYSTICK_SETTINGS_ES, "Ajustes de joystick" },
/* fr */ { IDS_JOYSTICK_SETTINGS_FR, "Param�tres des joysticks" },
/* hu */ { IDS_JOYSTICK_SETTINGS_HU, "Botkorm�ny be�ll�t�sai" },
/* it */ { IDS_JOYSTICK_SETTINGS_IT, "Impostazioni joystick" },
/* ko */ { IDS_JOYSTICK_SETTINGS_KO, "���̽�ƽ ����" },
/* nl */ { IDS_JOYSTICK_SETTINGS_NL, "Joystick instellingen" },
/* pl */ { IDS_JOYSTICK_SETTINGS_PL, "Ustawienia joysticka" },
/* ru */ { IDS_JOYSTICK_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOYSTICK_SETTINGS_SV, "Inst�llningar f�r styrspak" },
/* tr */ { IDS_JOYSTICK_SETTINGS_TR, "Joystick ayarlar�" },

/* en */ { IDS_KEYPAD,    "Numpad" },
/* da */ { IDS_KEYPAD_DA, "Numerisk tastatur" },
/* de */ { IDS_KEYPAD_DE, "Ziffernblock" },
/* es */ { IDS_KEYPAD_ES, "Teclado n�merico" },
/* fr */ { IDS_KEYPAD_FR, "" },  /* fuzzy */
/* hu */ { IDS_KEYPAD_HU, "Numerikus billenty�k" },
/* it */ { IDS_KEYPAD_IT, "Tastierino numerico" },
/* ko */ { IDS_KEYPAD_KO, "���е�" },
/* nl */ { IDS_KEYPAD_NL, "Numpad" },
/* pl */ { IDS_KEYPAD_PL, "Klawiatura numeryczna" },
/* ru */ { IDS_KEYPAD_RU, "" },  /* fuzzy */
/* sv */ { IDS_KEYPAD_SV, "Numeriskt tangentbord" },
/* tr */ { IDS_KEYPAD_TR, "Numpad" },

/* en */ { IDS_JOY_PORT_0,    "Joy Port 0" },
/* da */ { IDS_JOY_PORT_0_DA, "Joystickport 0" },
/* de */ { IDS_JOY_PORT_0_DE, "Joystick Port 0" },
/* es */ { IDS_JOY_PORT_0_ES, "Puerto Joy 0" },
/* fr */ { IDS_JOY_PORT_0_FR, "Port joystick 0" },
/* hu */ { IDS_JOY_PORT_0_HU, "Botkorm�ny port 0" },
/* it */ { IDS_JOY_PORT_0_IT, "Joystick nella porta 0" },
/* ko */ { IDS_JOY_PORT_0_KO, "" },  /* fuzzy */
/* nl */ { IDS_JOY_PORT_0_NL, "Joy Poort 0" },
/* pl */ { IDS_JOY_PORT_0_PL, "Port joysticka 0" },
/* ru */ { IDS_JOY_PORT_0_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOY_PORT_0_SV, "Spelport 0" },
/* tr */ { IDS_JOY_PORT_0_TR, "Joy Port 0" },

/* en */ { IDS_JOY_PORT_1,    "Joy Port 1" },
/* da */ { IDS_JOY_PORT_1_DA, "Joystickport 1" },
/* de */ { IDS_JOY_PORT_1_DE, "Joystick Port 1" },
/* es */ { IDS_JOY_PORT_1_ES, "Puerto Joy 1" },
/* fr */ { IDS_JOY_PORT_1_FR, "" },  /* fuzzy */
/* hu */ { IDS_JOY_PORT_1_HU, "Botkorm�ny port 1" },
/* it */ { IDS_JOY_PORT_1_IT, "Joystick nella porta 1" },
/* ko */ { IDS_JOY_PORT_1_KO, "" },  /* fuzzy */
/* nl */ { IDS_JOY_PORT_1_NL, "Joy Poort 1" },
/* pl */ { IDS_JOY_PORT_1_PL, "Port joysticka 1" },
/* ru */ { IDS_JOY_PORT_1_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOY_PORT_1_SV, "Spelport 1" },
/* tr */ { IDS_JOY_PORT_1_TR, "Joy Port 1" },

/* en */ { IDS_JOY_PORT_2,    "Joy Port 2" },
/* da */ { IDS_JOY_PORT_2_DA, "Joystickport 2" },
/* de */ { IDS_JOY_PORT_2_DE, "Joystick Port 2" },
/* es */ { IDS_JOY_PORT_2_ES, "Puerto Joy 2" },
/* fr */ { IDS_JOY_PORT_2_FR, "" },  /* fuzzy */
/* hu */ { IDS_JOY_PORT_2_HU, "Botkorm�ny port 2" },
/* it */ { IDS_JOY_PORT_2_IT, "Joystick nella porta 2" },
/* ko */ { IDS_JOY_PORT_2_KO, "" },  /* fuzzy */
/* nl */ { IDS_JOY_PORT_2_NL, "Joy Poort 2" },
/* pl */ { IDS_JOY_PORT_2_PL, "Port joysticka 2" },
/* ru */ { IDS_JOY_PORT_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOY_PORT_2_SV, "Spelport 2" },
/* tr */ { IDS_JOY_PORT_2_TR, "Joy Port 2" },

/* en */ { IDS_JOY_PORT_3,    "Joy Port 3" },
/* da */ { IDS_JOY_PORT_3_DA, "Joystickport 2" },
/* de */ { IDS_JOY_PORT_3_DE, "Joystick Port 3" },
/* es */ { IDS_JOY_PORT_3_ES, "Puerto Joy 3" },
/* fr */ { IDS_JOY_PORT_3_FR, "Port joystick 3" },
/* hu */ { IDS_JOY_PORT_3_HU, "Botkorm�ny port 3" },
/* it */ { IDS_JOY_PORT_3_IT, "Joystick nella porta 3" },
/* ko */ { IDS_JOY_PORT_3_KO, "" },  /* fuzzy */
/* nl */ { IDS_JOY_PORT_3_NL, "Joy Poort 3" },
/* pl */ { IDS_JOY_PORT_3_PL, "Port joysticka 3" },
/* ru */ { IDS_JOY_PORT_3_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOY_PORT_3_SV, "Spelport 2" },
/* tr */ { IDS_JOY_PORT_3_TR, "Joy Port 3" },

/* en */ { IDS_STOP_BLUE,    "Stop/Blue" },
/* da */ { IDS_STOP_BLUE_DA, "Stop/Bl�" },
/* de */ { IDS_STOP_BLUE_DE, "Stop/Blau" },
/* es */ { IDS_STOP_BLUE_ES, "Parar/Azul" },
/* fr */ { IDS_STOP_BLUE_FR, "Arr�t/Bleu" },
/* hu */ { IDS_STOP_BLUE_HU, "Le�ll�t/K�k" },
/* it */ { IDS_STOP_BLUE_IT, "Stop/Blu" },
/* ko */ { IDS_STOP_BLUE_KO, "����/�Ķ�" },
/* nl */ { IDS_STOP_BLUE_NL, "Stop/Blauw" },
/* pl */ { IDS_STOP_BLUE_PL, "Zatrzymaj/B��kitny" },
/* ru */ { IDS_STOP_BLUE_RU, "" },  /* fuzzy */
/* sv */ { IDS_STOP_BLUE_SV, "Stopp/Bl�" },
/* tr */ { IDS_STOP_BLUE_TR, "Durdur/Mavi" },

/* en */ { IDS_SELECT_RED,    "Select/Red" },
/* da */ { IDS_SELECT_RED_DA, "V�lg/R�d" },
/* de */ { IDS_SELECT_RED_DE, "Auswahl/Rot" },
/* es */ { IDS_SELECT_RED_ES, "Seleccionar/Rojo" },
/* fr */ { IDS_SELECT_RED_FR, "S�lectionner/Rouge" },
/* hu */ { IDS_SELECT_RED_HU, "Kiv�laszt/Piros" },
/* it */ { IDS_SELECT_RED_IT, "Seleziona/Rosso" },
/* ko */ { IDS_SELECT_RED_KO, "����/����" },
/* nl */ { IDS_SELECT_RED_NL, "Selecy/Rood" },
/* pl */ { IDS_SELECT_RED_PL, "Wybierz/Czerwony" },
/* ru */ { IDS_SELECT_RED_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_RED_SV, "V�lj/R�d" },
/* tr */ { IDS_SELECT_RED_TR, "Se�im/K�rm�z�" },

/* en */ { IDS_REPEAT_YELLOW,    "Repeat/Yellow" },
/* da */ { IDS_REPEAT_YELLOW_DA, "Gentag/Gul" },
/* de */ { IDS_REPEAT_YELLOW_DE, "Wiederhole/Gelb" },
/* es */ { IDS_REPEAT_YELLOW_ES, "Repetir/Amarillo" },
/* fr */ { IDS_REPEAT_YELLOW_FR, "R�p�ter/Jaune" },
/* hu */ { IDS_REPEAT_YELLOW_HU, "Ism�tel/S�rga" },
/* it */ { IDS_REPEAT_YELLOW_IT, "Ripeti/Giallo" },
/* ko */ { IDS_REPEAT_YELLOW_KO, "�ݺ�/���" },
/* nl */ { IDS_REPEAT_YELLOW_NL, "Repeat/Geel" },
/* pl */ { IDS_REPEAT_YELLOW_PL, "Powtarzaj/��ty" },
/* ru */ { IDS_REPEAT_YELLOW_RU, "" },  /* fuzzy */
/* sv */ { IDS_REPEAT_YELLOW_SV, "Repetera/Gul" },
/* tr */ { IDS_REPEAT_YELLOW_TR, "Tekrar/Sar�" },

/* en */ { IDS_SHUFFLE_GREEN,    "Shuffle/Green" },
/* da */ { IDS_SHUFFLE_GREEN_DA, "Bland/Gr�n" },
/* de */ { IDS_SHUFFLE_GREEN_DE, "Mische/Gr�n" },
/* es */ { IDS_SHUFFLE_GREEN_ES, "Shuffle/Verde" },
/* fr */ { IDS_SHUFFLE_GREEN_FR, "M�langer/Vert" },
/* hu */ { IDS_SHUFFLE_GREEN_HU, "V�letlenszer�/Z�ld" },
/* it */ { IDS_SHUFFLE_GREEN_IT, "Mischia/Verde" },
/* ko */ { IDS_SHUFFLE_GREEN_KO, "����/�ʷ�" },
/* nl */ { IDS_SHUFFLE_GREEN_NL, "Shuffle/Groen" },
/* pl */ { IDS_SHUFFLE_GREEN_PL, "Losuj/Zielony" },
/* ru */ { IDS_SHUFFLE_GREEN_RU, "" },  /* fuzzy */
/* sv */ { IDS_SHUFFLE_GREEN_SV, "Blanda/Gr�n" },
/* tr */ { IDS_SHUFFLE_GREEN_TR, "Kar��t�r/Ye�il" },

/* en */ { IDS_FORWARD_CHARCOAL,    "Forward/Charcoal" },
/* da */ { IDS_FORWARD_CHARCOAL_DA, "Fremad/Grafit" },
/* de */ { IDS_FORWARD_CHARCOAL_DE, "Vorw�rts/Kohle" },
/* es */ { IDS_FORWARD_CHARCOAL_ES, "Adelante/Negro" },
/* fr */ { IDS_FORWARD_CHARCOAL_FR, "Avancer/Charcoal" },
/* hu */ { IDS_FORWARD_CHARCOAL_HU, "El�re/Fekete" },
/* it */ { IDS_FORWARD_CHARCOAL_IT, "Avanti/Carboncino" },
/* ko */ { IDS_FORWARD_CHARCOAL_KO, "��������/£�� ȸ��" },
/* nl */ { IDS_FORWARD_CHARCOAL_NL, "Forward/Charcoal" },
/* pl */ { IDS_FORWARD_CHARCOAL_PL, "W prz�d/W�giel drzewny" },
/* ru */ { IDS_FORWARD_CHARCOAL_RU, "" },  /* fuzzy */
/* sv */ { IDS_FORWARD_CHARCOAL_SV, "Fram�t/Svart" },
/* tr */ { IDS_FORWARD_CHARCOAL_TR, "�leri/K�m�r" },

/* en */ { IDS_REVERSE_CHARCOAL,    "Reverse/Charcoal" },
/* da */ { IDS_REVERSE_CHARCOAL_DA, "Bagud/Grafit" },
/* de */ { IDS_REVERSE_CHARCOAL_DE, "R�ckw�rts/Kohle" },
/* es */ { IDS_REVERSE_CHARCOAL_ES, "Atras/Negro" },
/* fr */ { IDS_REVERSE_CHARCOAL_FR, "Reculer/Charcoal" },
/* hu */ { IDS_REVERSE_CHARCOAL_HU, "Vissza/Fekete" },
/* it */ { IDS_REVERSE_CHARCOAL_IT, "Indietro/Carboncino" },
/* ko */ { IDS_REVERSE_CHARCOAL_KO, "������/£�� ȸ��" },
/* nl */ { IDS_REVERSE_CHARCOAL_NL, "Reverse/Charcoal" },
/* pl */ { IDS_REVERSE_CHARCOAL_PL, "Do ty�u/W�glowy" },
/* ru */ { IDS_REVERSE_CHARCOAL_RU, "" },  /* fuzzy */
/* sv */ { IDS_REVERSE_CHARCOAL_SV, "Bak�t/Svart" },
/* tr */ { IDS_REVERSE_CHARCOAL_TR, "Ters/K�m�r" },

/* en */ { IDS_PLAY_PAUSE_GREY,    "Play-Pause/Grey" },
/* da */ { IDS_PLAY_PAUSE_GREY_DA, "Play-Pause/Gr�" },
/* de */ { IDS_PLAY_PAUSE_GREY_DE, "Play-Pause/Grau" },
/* es */ { IDS_PLAY_PAUSE_GREY_ES, "Iniciar-Pausa/Gris" },
/* fr */ { IDS_PLAY_PAUSE_GREY_FR, "Play-Pause/Gris" },
/* hu */ { IDS_PLAY_PAUSE_GREY_HU, "Lej�tsz�s-Meg�ll�t�s/Sz�rke" },
/* it */ { IDS_PLAY_PAUSE_GREY_IT, "Avvia-Pausa/Grigio" },
/* ko */ { IDS_PLAY_PAUSE_GREY_KO, "���-����/ȸ��" },
/* nl */ { IDS_PLAY_PAUSE_GREY_NL, "Play-Pause/Grijs" },
/* pl */ { IDS_PLAY_PAUSE_GREY_PL, "Odtwarzaj-Pauza/Szary" },
/* ru */ { IDS_PLAY_PAUSE_GREY_RU, "" },  /* fuzzy */
/* sv */ { IDS_PLAY_PAUSE_GREY_SV, "Spela-Paus/Gr�" },
/* tr */ { IDS_PLAY_PAUSE_GREY_TR, "�al-Duraklat/Gri" },

/* en */ { IDS_JOY_1_DEVICE,    "Joy 1 Device" },
/* da */ { IDS_JOY_1_DEVICE_DA, "Joystick 1 enhed" },
/* de */ { IDS_JOY_1_DEVICE_DE, "Joystick 1 Ger�t" },
/* es */ { IDS_JOY_1_DEVICE_ES, "Perif�rico Joy 1" },
/* fr */ { IDS_JOY_1_DEVICE_FR, "P�riph�rique joystick 1" },
/* hu */ { IDS_JOY_1_DEVICE_HU, "1-es botkorm�ny eszk�z" },
/* it */ { IDS_JOY_1_DEVICE_IT, "Dispositivo Joystick 1" },
/* ko */ { IDS_JOY_1_DEVICE_KO, "" },  /* fuzzy */
/* nl */ { IDS_JOY_1_DEVICE_NL, "Joy 1 apparaat" },
/* pl */ { IDS_JOY_1_DEVICE_PL, "Urz�dzenie joysticka 1" },
/* ru */ { IDS_JOY_1_DEVICE_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOY_1_DEVICE_SV, "Enhet f�r styrspak 1" },
/* tr */ { IDS_JOY_1_DEVICE_TR, "Joy 1 Ayg�t�" },

/* en */ { IDS_JOY_2_DEVICE,    "Joy 2 Device" },
/* da */ { IDS_JOY_2_DEVICE_DA, "Joystick 2 enhed" },
/* de */ { IDS_JOY_2_DEVICE_DE, "Joystick 2 Ger�t" },
/* es */ { IDS_JOY_2_DEVICE_ES, "Perif�rico Joy 2" },
/* fr */ { IDS_JOY_2_DEVICE_FR, "P�riph�rique joystick 2" },
/* hu */ { IDS_JOY_2_DEVICE_HU, "2-es botkorm�ny eszk�z" },
/* it */ { IDS_JOY_2_DEVICE_IT, "Dispositivo Joystick 2" },
/* ko */ { IDS_JOY_2_DEVICE_KO, "" },  /* fuzzy */
/* nl */ { IDS_JOY_2_DEVICE_NL, "Joy 2 apparaat" },
/* pl */ { IDS_JOY_2_DEVICE_PL, "Urz�dzenie joysticka 2" },
/* ru */ { IDS_JOY_2_DEVICE_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOY_2_DEVICE_SV, "Enhet f�r styrspak 2" },
/* tr */ { IDS_JOY_2_DEVICE_TR, "Joy 2 Ayg�t�" },

/* en */ { IDS_USERPORT_JOY_1_DEVICE,    "Userport Joy 1 Device" },
/* da */ { IDS_USERPORT_JOY_1_DEVICE_DA, "Brugerport Joystick 1 enhed" },
/* de */ { IDS_USERPORT_JOY_1_DEVICE_DE, "Userport Joystick 1 Ger�t" },
/* es */ { IDS_USERPORT_JOY_1_DEVICE_ES, "Puerto periferico joy 1" },
/* fr */ { IDS_USERPORT_JOY_1_DEVICE_FR, "" },  /* fuzzy */
/* hu */ { IDS_USERPORT_JOY_1_DEVICE_HU, "Userport 1-es botkorm�ny eszk�z" },
/* it */ { IDS_USERPORT_JOY_1_DEVICE_IT, "Dispositivo joystick 1 su userport" },
/* ko */ { IDS_USERPORT_JOY_1_DEVICE_KO, "" },  /* fuzzy */
/* nl */ { IDS_USERPORT_JOY_1_DEVICE_NL, "Userport Joy 1 apparaat" },
/* pl */ { IDS_USERPORT_JOY_1_DEVICE_PL, "Urz�dzenie userportu joysticka 1" },
/* ru */ { IDS_USERPORT_JOY_1_DEVICE_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_JOY_1_DEVICE_SV, "Anv�ndarportspak 1 enhet" },
/* tr */ { IDS_USERPORT_JOY_1_DEVICE_TR, "Userport Joy 1 Ayg�t�" },

/* en */ { IDS_USERPORT_JOY_2_DEVICE,    "Userport Joy 2 Device" },
/* da */ { IDS_USERPORT_JOY_2_DEVICE_DA, "Brugerport Joystick 2 enhed" },
/* de */ { IDS_USERPORT_JOY_2_DEVICE_DE, "Userport Joystick 2 Ger�t" },
/* es */ { IDS_USERPORT_JOY_2_DEVICE_ES, "Puerto periferico joy 2" },
/* fr */ { IDS_USERPORT_JOY_2_DEVICE_FR, "" },  /* fuzzy */
/* hu */ { IDS_USERPORT_JOY_2_DEVICE_HU, "Userport 2-es botkorm�ny eszk�z" },
/* it */ { IDS_USERPORT_JOY_2_DEVICE_IT, "Dispositivo joystick 2 su userport" },
/* ko */ { IDS_USERPORT_JOY_2_DEVICE_KO, "" },  /* fuzzy */
/* nl */ { IDS_USERPORT_JOY_2_DEVICE_NL, "Userport Joy 2 apparaat" },
/* pl */ { IDS_USERPORT_JOY_2_DEVICE_PL, "Urz�dzenie userportu joysticka 2" },
/* ru */ { IDS_USERPORT_JOY_2_DEVICE_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_JOY_2_DEVICE_SV, "Anv�ndarportspak 2 enhet" },
/* tr */ { IDS_USERPORT_JOY_2_DEVICE_TR, "Userport Joy 2 Ayg�t�" },

/* en */ { IDS_SIDCART_JOY_DEVICE,    "SIDcart Joy Device" },
/* da */ { IDS_SIDCART_JOY_DEVICE_DA, "SIDcart joystick-enhed" },
/* de */ { IDS_SIDCART_JOY_DEVICE_DE, "SIDcart Joystick Ger�t" },
/* es */ { IDS_SIDCART_JOY_DEVICE_ES, "Perif�rico Joy SIDCart" },
/* fr */ { IDS_SIDCART_JOY_DEVICE_FR, "" },  /* fuzzy */
/* hu */ { IDS_SIDCART_JOY_DEVICE_HU, "SIDcart botkorm�ny eszk�z" },
/* it */ { IDS_SIDCART_JOY_DEVICE_IT, "Dispositivo Joystick SIDcart" },
/* ko */ { IDS_SIDCART_JOY_DEVICE_KO, "" },  /* fuzzy */
/* nl */ { IDS_SIDCART_JOY_DEVICE_NL, "SIDcart Joy apparaat" },
/* pl */ { IDS_SIDCART_JOY_DEVICE_PL, "Urz�dzenie joysticka SIDcart" },
/* ru */ { IDS_SIDCART_JOY_DEVICE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SIDCART_JOY_DEVICE_SV, "SIDcart-spakenhet" },
/* tr */ { IDS_SIDCART_JOY_DEVICE_TR, "SID Kartu�u Joy Ayg�t�" },

/* en */ { IDS_JOY_1_FIRE,    "Joy 1 Fire" },
/* da */ { IDS_JOY_1_FIRE_DA, "Joystick 1 skydeknap" },
/* de */ { IDS_JOY_1_FIRE_DE, "Joystick 1 Feuer" },
/* es */ { IDS_JOY_1_FIRE_ES, "Joy 1 disparo" },
/* fr */ { IDS_JOY_1_FIRE_FR, "Jeu joystick 1" },
/* hu */ { IDS_JOY_1_FIRE_HU, "1-es botkorm�ny t�z" },
/* it */ { IDS_JOY_1_FIRE_IT, "Fuoco Joystick 1" },
/* ko */ { IDS_JOY_1_FIRE_KO, "" },  /* fuzzy */
/* nl */ { IDS_JOY_1_FIRE_NL, "Joy 1 Vuur" },
/* pl */ { IDS_JOY_1_FIRE_PL, "Fire joysticka 1" },
/* ru */ { IDS_JOY_1_FIRE_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOY_1_FIRE_SV, "Fire f�r styrspak 1" },
/* tr */ { IDS_JOY_1_FIRE_TR, "Joy 1 Ate�" },

/* en */ { IDS_JOY_2_FIRE,    "Joy 2 Fire" },
/* da */ { IDS_JOY_2_FIRE_DA, "Joystick 2 skydeknap" },
/* de */ { IDS_JOY_2_FIRE_DE, "Joystick 2 Feuer" },
/* es */ { IDS_JOY_2_FIRE_ES, "Joy 2 disparo" },
/* fr */ { IDS_JOY_2_FIRE_FR, "Jeu joystick 2" },
/* hu */ { IDS_JOY_2_FIRE_HU, "2-es botkorm�ny t�z" },
/* it */ { IDS_JOY_2_FIRE_IT, "Fuoco Joystick 2" },
/* ko */ { IDS_JOY_2_FIRE_KO, "" },  /* fuzzy */
/* nl */ { IDS_JOY_2_FIRE_NL, "Joy 2 Vuur" },
/* pl */ { IDS_JOY_2_FIRE_PL, "Fire joysticka 2" },
/* ru */ { IDS_JOY_2_FIRE_RU, "" },  /* fuzzy */
/* sv */ { IDS_JOY_2_FIRE_SV, "Fire f�r styrspak 2" },
/* tr */ { IDS_JOY_2_FIRE_TR, "Joy 2 Ate�" },

/* en */ { IDS_USERPORT_JOY_1_FIRE,    "Userport Joy 1 Fire" },
/* da */ { IDS_USERPORT_JOY_1_FIRE_DA, "Brugerport joystick 1 skydeknap" },
/* de */ { IDS_USERPORT_JOY_1_FIRE_DE, "Userport Joystick 1 Feuer" },
/* es */ { IDS_USERPORT_JOY_1_FIRE_ES, "Puerto Joy 1 disparo" },
/* fr */ { IDS_USERPORT_JOY_1_FIRE_FR, "" },  /* fuzzy */
/* hu */ { IDS_USERPORT_JOY_1_FIRE_HU, "1-es userport botkorm�ny t�z" },
/* it */ { IDS_USERPORT_JOY_1_FIRE_IT, "Fuoco joystick 1 su userport" },
/* ko */ { IDS_USERPORT_JOY_1_FIRE_KO, "" },  /* fuzzy */
/* nl */ { IDS_USERPORT_JOY_1_FIRE_NL, "Userport Joy 1 Vuur" },
/* pl */ { IDS_USERPORT_JOY_1_FIRE_PL, "Fire userportu joysticka 1" },
/* ru */ { IDS_USERPORT_JOY_1_FIRE_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_JOY_1_FIRE_SV, "Anv�ndarportspak 1 fire" },
/* tr */ { IDS_USERPORT_JOY_1_FIRE_TR, "Userport Joy 1 Ate�" },

/* en */ { IDS_USERPORT_JOY_2_FIRE,    "Userport Joy 2 Fire" },
/* da */ { IDS_USERPORT_JOY_2_FIRE_DA, "Brugerport joystick 2 skydeknap" },
/* de */ { IDS_USERPORT_JOY_2_FIRE_DE, "Userport Joystick 2 Feuer" },
/* es */ { IDS_USERPORT_JOY_2_FIRE_ES, "Puerto Joy 2 disparo" },
/* fr */ { IDS_USERPORT_JOY_2_FIRE_FR, "" },  /* fuzzy */
/* hu */ { IDS_USERPORT_JOY_2_FIRE_HU, "2-es userport botkorm�ny t�z" },
/* it */ { IDS_USERPORT_JOY_2_FIRE_IT, "Fuoco joystick 2 su userport" },
/* ko */ { IDS_USERPORT_JOY_2_FIRE_KO, "" },  /* fuzzy */
/* nl */ { IDS_USERPORT_JOY_2_FIRE_NL, "Userport Joy 2 Vuur" },
/* pl */ { IDS_USERPORT_JOY_2_FIRE_PL, "Fire userportu joysticka 2" },
/* ru */ { IDS_USERPORT_JOY_2_FIRE_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_JOY_2_FIRE_SV, "Anv�ndarportspak 2 fire" },
/* tr */ { IDS_USERPORT_JOY_2_FIRE_TR, "Userport Joy 2 Ate�" },

/* en */ { IDS_SIDCART_JOY_FIRE,    "SIDcart Joy Fire" },
/* da */ { IDS_SIDCART_JOY_FIRE_DA, "SIDcart joystick skydeknap" },
/* de */ { IDS_SIDCART_JOY_FIRE_DE, "SIDcart Joystick Feuer" },
/* es */ { IDS_SIDCART_JOY_FIRE_ES, "Joy SIDCart disparo" },
/* fr */ { IDS_SIDCART_JOY_FIRE_FR, "" },  /* fuzzy */
/* hu */ { IDS_SIDCART_JOY_FIRE_HU, "SIDcart botkorm�ny t�z" },
/* it */ { IDS_SIDCART_JOY_FIRE_IT, "Fuoco joystick su SIDcart" },
/* ko */ { IDS_SIDCART_JOY_FIRE_KO, "" },  /* fuzzy */
/* nl */ { IDS_SIDCART_JOY_FIRE_NL, "SIDcart Joy Vuur" },
/* pl */ { IDS_SIDCART_JOY_FIRE_PL, "Fire joysticka SIDcart" },
/* ru */ { IDS_SIDCART_JOY_FIRE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SIDCART_JOY_FIRE_SV, "SIDcart-spak fire" },
/* tr */ { IDS_SIDCART_JOY_FIRE_TR, "SID kartu�u Joy Ate�" },

/* en */ { IDS_SET_INPUT_JOYSTICK_1,    "Joystick #1 emulation: (0:None, 1: Numpad, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* da */ { IDS_SET_INPUT_JOYSTICK_1_DA, "Emulering af Joystick 1: (0: ingen, 1: numerisk, 2: tastes�t A/AI, 3: tastes�t B/AI)" },
/* de */ { IDS_SET_INPUT_JOYSTICK_1_DE, "Joystick #1 Emulation: (0:Keine, 1: Numpad, 2: Keysatz A/AI, 3: Keysatz B/AI)" },
/* es */ { IDS_SET_INPUT_JOYSTICK_1_ES, "Emulaci�n Joystick #1: (0:No, 1: Teclado n�merico, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* fr */ { IDS_SET_INPUT_JOYSTICK_1_FR, "�mulation Joystick #1: (0:Aucun, 1: Numpad, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* hu */ { IDS_SET_INPUT_JOYSTICK_1_HU, "#1-es botkorm�ny emul�ci�: (0: Nincs, 1: numerikus, 2: 'A' gombk�szlet, 3: 'B' gombk�szlet)" },
/* it */ { IDS_SET_INPUT_JOYSTICK_1_IT, "Emulazione joystick #1: (0: Nessuna, 1: Tastierino numerico, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* ko */ { IDS_SET_INPUT_JOYSTICK_1_KO, "" },  /* fuzzy */
/* nl */ { IDS_SET_INPUT_JOYSTICK_1_NL, "Emulatie joystick #1: (0: Geen, 1: Numpad, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* pl */ { IDS_SET_INPUT_JOYSTICK_1_PL, "Emulacja joysticka #1: (0: brak, 1: numeryczna, 2: klawisze A/AI, 3: klawisze B/AI)" },
/* ru */ { IDS_SET_INPUT_JOYSTICK_1_RU, "" },  /* fuzzy */
/* sv */ { IDS_SET_INPUT_JOYSTICK_1_SV, "Emulering f�r styrspak 1: (0: ingen, 1: numerisk, 2: tangentupps�ttning A/AI, 3: tangentupps�ttning B/AI)" },
/* tr */ { IDS_SET_INPUT_JOYSTICK_1_TR, "Joystick #1 em�lasyonu: (0:Yok, 1: Numpad, 2: Tu� Seti A/AI, 3: Tu� Seti B/AI)" },

/* en */ { IDS_SET_INPUT_JOYSTICK_2,    "Joystick #2 emulation: (0: None, 1: Numpad, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* da */ { IDS_SET_INPUT_JOYSTICK_2_DA, "Emulering af Joystick 2: (0: ingen, 1: numerisk, 2: tastes�t A/AI, 3: tastes�t B/AI)" },
/* de */ { IDS_SET_INPUT_JOYSTICK_2_DE, "Joystick #2 Emulation: (0: Keine, 1: Numpad, 2: Keysatz A/AI, 3: Keysatz B/AI)" },
/* es */ { IDS_SET_INPUT_JOYSTICK_2_ES, "Emulaci�n Joystick #2: (0:No, 1: Teclado n�merico, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* fr */ { IDS_SET_INPUT_JOYSTICK_2_FR, "�mulation joystick #2: (0: Aucune, 1: Numpad, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* hu */ { IDS_SET_INPUT_JOYSTICK_2_HU, "#2-es botkorm�ny emul�ci�: (0: Nincs, 1: numerikus, 2: 'A' gombk�szlet, 3: 'B' gombk�szlet)" },
/* it */ { IDS_SET_INPUT_JOYSTICK_2_IT, "Emulazione joystick #2: (0: Nessuna, 1: Tastierino numerico, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* ko */ { IDS_SET_INPUT_JOYSTICK_2_KO, "" },  /* fuzzy */
/* nl */ { IDS_SET_INPUT_JOYSTICK_2_NL, "Emulatie joystick #2: (0: Geen, 1: Numpad, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* pl */ { IDS_SET_INPUT_JOYSTICK_2_PL, "Emulacja joysticka #2: (0: brak, 1: numeryczna, 2: klawisze A/AI, 3: klawisze B/AI)" },
/* ru */ { IDS_SET_INPUT_JOYSTICK_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_SET_INPUT_JOYSTICK_2_SV, "Emulering f�r styrspak 2: (0: ingen, 1: numerisk, 2: tangentupps�ttning A/AI, 3: tangentupps�ttning B/AI)" },
/* tr */ { IDS_SET_INPUT_JOYSTICK_2_TR, "Joystick #2 em�lasyonu: (0:Yok, 1: Numpad, 2: Tu� Seti A/AI, 3: Tu� Seti B/AI)" },

/* en */ { IDS_SET_INPUT_EXTRA_JOYSTICK_1,    "Extra joystick #1 emulation: (0:None, 1: Numpad, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* da */ { IDS_SET_INPUT_EXTRA_JOYSTICK_1_DA, "Emulering af Joystick 1: (0: ingen, 1: numerisk, 2: tastes�t A/AI, 3: tastes�t B/AI)" },
/* de */ { IDS_SET_INPUT_EXTRA_JOYSTICK_1_DE, "Extra Joystick #1 Emulation: (0: Keine, 1: Numpad, 2: Keysatz A/AI, 3: Keysatz B/AI)" },
/* es */ { IDS_SET_INPUT_EXTRA_JOYSTICK_1_ES, "Emulaci�n Joystick suplementario #1: (0:No, 1: Teclado n�merico, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* fr */ { IDS_SET_INPUT_EXTRA_JOYSTICK_1_FR, "" },  /* fuzzy */
/* hu */ { IDS_SET_INPUT_EXTRA_JOYSTICK_1_HU, "" },  /* fuzzy */
/* it */ { IDS_SET_INPUT_EXTRA_JOYSTICK_1_IT, "Emulazione joystick supplementare #1: (0: Nessuna, 1: Tastierino numerico, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* ko */ { IDS_SET_INPUT_EXTRA_JOYSTICK_1_KO, "" },  /* fuzzy */
/* nl */ { IDS_SET_INPUT_EXTRA_JOYSTICK_1_NL, "Emulatie extra joystick #1: (0: Geen, 1: Numpad, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* pl */ { IDS_SET_INPUT_EXTRA_JOYSTICK_1_PL, "Emulacja dodatkowego joysticka #1: (0: brak, 1: numeryczna, 2: klawisze A/AI, 3: klawisze B/AI)" },
/* ru */ { IDS_SET_INPUT_EXTRA_JOYSTICK_1_RU, "" },  /* fuzzy */
/* sv */ { IDS_SET_INPUT_EXTRA_JOYSTICK_1_SV, "Emulering f�r extra styrspak 1: (0: ingen, 1: numerisk, 2: tangentupps�ttning A/AI, 3: tangentupps�ttning B/AI)" },
/* tr */ { IDS_SET_INPUT_EXTRA_JOYSTICK_1_TR, "Ekstra joystick #1 em�lasyonu: (0:Yok, 1: Numpad, 2: Tu� Seti A/AI, 3: Tu� Seti B/AI)" },

/* en */ { IDS_SET_INPUT_EXTRA_JOYSTICK_2,    "Extra joystick #2 emulation: (0: None, 1: Numpad, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* da */ { IDS_SET_INPUT_EXTRA_JOYSTICK_2_DA, "Emulering af Joystick 2: (0: ingen, 1: numerisk, 2: tastes�t A/AI, 3: tastes�t B/AI)" },
/* de */ { IDS_SET_INPUT_EXTRA_JOYSTICK_2_DE, "Extra Joystick #2 Emulation: (0: Keine, 1: Numpad, 2: Keysatz A/AI, 3: Keysatz B/AI)" },
/* es */ { IDS_SET_INPUT_EXTRA_JOYSTICK_2_ES, "Emulaci�n Joystick suplementario #2: (0:No, 1: Teclado n�merico, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* fr */ { IDS_SET_INPUT_EXTRA_JOYSTICK_2_FR, "" },  /* fuzzy */
/* hu */ { IDS_SET_INPUT_EXTRA_JOYSTICK_2_HU, "" },  /* fuzzy */
/* it */ { IDS_SET_INPUT_EXTRA_JOYSTICK_2_IT, "Emulazione joystick supplementare #2: (0: Nessuna, 1: Tastierino numerico, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* ko */ { IDS_SET_INPUT_EXTRA_JOYSTICK_2_KO, "" },  /* fuzzy */
/* nl */ { IDS_SET_INPUT_EXTRA_JOYSTICK_2_NL, "Emulatie extra joystick #2: (0: Geen, 1: Numpad, 2: Keyset A/AI, 3: Keyset B/AI)" },
/* pl */ { IDS_SET_INPUT_EXTRA_JOYSTICK_2_PL, "Emulacja dodatkowego joysticka #2: (0: brak, 1: numeryczna, 2: klawisze A/AI, 3: klawisze B/AI)" },
/* ru */ { IDS_SET_INPUT_EXTRA_JOYSTICK_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_SET_INPUT_EXTRA_JOYSTICK_2_SV, "Emulering f�r extra styrspak 2: (0: ingen, 1: numerisk, 2: tangentupps�ttning A/AI, 3: tangentupps�ttning B/AI)" },
/* tr */ { IDS_SET_INPUT_EXTRA_JOYSTICK_2_TR, "Ekstra joystick #2 em�lasyonu: (0:Yok, 1: Numpad, 2: Tu� Seti A/AI, 3: Tu� Seti B/AI)" },

/* en */ { IDS_SET_INPUT_JOYLL_1,    "Joystick #1 emulation: (0: None, 1: Numpad, 2-5: Amiga Joy 0-3)" },
/* da */ { IDS_SET_INPUT_JOYLL_1_DA, "Joystick 1 emularing: (0: ingen, 1: numerisk, 2-5: Amigajoystick 0-3)" },
/* de */ { IDS_SET_INPUT_JOYLL_1_DE, "Joystick #1 Emulation: (0: Keine, 1: Numpad, 2-5: Amiga Joystick 0-3)" },
/* es */ { IDS_SET_INPUT_JOYLL_1_ES, "Emulaci�n Joystick #1: (0:No, 1: Teclado n�merico, 2-5: Amiga Joy0-3 )" },
/* fr */ { IDS_SET_INPUT_JOYLL_1_FR, "" },  /* fuzzy */
/* hu */ { IDS_SET_INPUT_JOYLL_1_HU, "#1-es botkorm�ny emul�ci�: (0: nincs, 1: numerikus billenty�k, 2-5: amiga botkorm�ny 0-3)" },
/* it */ { IDS_SET_INPUT_JOYLL_1_IT, "Emulazione joystick #1: (0: Nessuna, 1: Tastierino numerico, 2-5: Joy Amiga 0-3)" },
/* ko */ { IDS_SET_INPUT_JOYLL_1_KO, "" },  /* fuzzy */
/* nl */ { IDS_SET_INPUT_JOYLL_1_NL, "Emulatie joystick #1: (0: Geen, 1: Numpad, 2-5: Amiga Joy 0-3)" },
/* pl */ { IDS_SET_INPUT_JOYLL_1_PL, "Emulacja joysticka #1: (0: brak, 1: numeryczna, 2-5: joystick Amigi 0-3)" },
/* ru */ { IDS_SET_INPUT_JOYLL_1_RU, "" },  /* fuzzy */
/* sv */ { IDS_SET_INPUT_JOYLL_1_SV, "Emulering f�r styrspak 1: (0: ingen, 1: numerisk, 2-5: Amigastyrspak 0-3)" },
/* tr */ { IDS_SET_INPUT_JOYLL_1_TR, "Joystick #1 em�lasyonu: (0: Yok, 1: Numpad, 2-5: Amiga Joy 0-3)" },

/* en */ { IDS_SET_INPUT_JOYLL_2,    "Joystick #2 emulation: (0: None, 1: Numpad, 2-5: Amiga Joy 0-3)" },
/* da */ { IDS_SET_INPUT_JOYLL_2_DA, "Joystick 2 emularing: (0: ingen, 1: numerisk, 2-5: Amigajoystick 0-3)" },
/* de */ { IDS_SET_INPUT_JOYLL_2_DE, "Joystick #2 Emulation: (0: Keine, 1: Numpad, 2-5: Amiga Joystick 0-3)" },
/* es */ { IDS_SET_INPUT_JOYLL_2_ES, "Emulaci�n Joystick #2: (0:No, 1: Teclado n�merico, 2-5: Amiga Joy0-3 )" },
/* fr */ { IDS_SET_INPUT_JOYLL_2_FR, "" },  /* fuzzy */
/* hu */ { IDS_SET_INPUT_JOYLL_2_HU, "#2-es botkorm�ny emul�ci�: (0: nincs, 1: numerikus billenty�k, 2-5: amiga botkorm�ny 0-3)" },
/* it */ { IDS_SET_INPUT_JOYLL_2_IT, "Emulazione joystick #2: (0: Nessuna, 1: Tastierino numerico, 2-5: Joy Amiga 0-3)" },
/* ko */ { IDS_SET_INPUT_JOYLL_2_KO, "" },  /* fuzzy */
/* nl */ { IDS_SET_INPUT_JOYLL_2_NL, "Emulatie joystick #2: (0: Geen, 1: Numpad, 2-5: Amiga Joy 0-3)" },
/* pl */ { IDS_SET_INPUT_JOYLL_2_PL, "Emulacja joysticka #2: (0: brak, 1: numeryczna, 2-5: joystick Amigi 0-3)" },
/* ru */ { IDS_SET_INPUT_JOYLL_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_SET_INPUT_JOYLL_2_SV, "Emulering f�r styrspak 2: (0: ingen, 1: numerisk, 2-5: Amigastyrspak 0-3)" },
/* tr */ { IDS_SET_INPUT_JOYLL_2_TR, "Joystick #2 em�lasyonu: (0: Yok, 1: Numpad, 2-5: Amiga Joy 0-3)" },

/* en */ { IDS_SET_INPUT_EXTRA_JOYLL_1,    "Extra joystick #1 emulation: (0: None, 1: Numpad, 2-5: Amiga Joy 0-3)" },
/* da */ { IDS_SET_INPUT_EXTRA_JOYLL_1_DA, "Ekstra joystick 1 emulering: (0: ingen, 1: numerisk, 2-5: Amigajoystick 0-3)" },
/* de */ { IDS_SET_INPUT_EXTRA_JOYLL_1_DE, "Extra Joystick #1 Emulation: (0: Keine, 1: Numpad, 2-5: Amiga Joystick 0-3)" },
/* es */ { IDS_SET_INPUT_EXTRA_JOYLL_1_ES, "Emulaci�n Joystick suplementario #1: (0:No, 1: Teclado n�merico, 2-5: Amiga Joy0-3 )" },
/* fr */ { IDS_SET_INPUT_EXTRA_JOYLL_1_FR, "" },  /* fuzzy */
/* hu */ { IDS_SET_INPUT_EXTRA_JOYLL_1_HU, "#1-es extra botkorm�ny emul�ci� (0: Nincs, 1: numerikus, 2-5: Amiga botkorm�ny 0-3)" },
/* it */ { IDS_SET_INPUT_EXTRA_JOYLL_1_IT, "Emulazione joystick supplementare #1: (0: Nessuna, 1: Tastierino numerico, 2-5: Joy Amiga 0-3)" },
/* ko */ { IDS_SET_INPUT_EXTRA_JOYLL_1_KO, "" },  /* fuzzy */
/* nl */ { IDS_SET_INPUT_EXTRA_JOYLL_1_NL, "Emulatie extra joystick #1: (0: Geen, 1: Numpad, 2-5: Amiga Joy 0-3)" },
/* pl */ { IDS_SET_INPUT_EXTRA_JOYLL_1_PL, "Emulacja dodatkowego joysticka #1: (0: brak, 1: numeryczna, 2-5: joystick Amigi 0-3)" },
/* ru */ { IDS_SET_INPUT_EXTRA_JOYLL_1_RU, "" },  /* fuzzy */
/* sv */ { IDS_SET_INPUT_EXTRA_JOYLL_1_SV, "Emulering f�r extra styrspak 1: (0: ingen, 1: numerisk, 2-5: Amigastyrspak 0-3)" },
/* tr */ { IDS_SET_INPUT_EXTRA_JOYLL_1_TR, "Ekstra joystick #1 em�lasyonu: (0: Yok, 1: Numpad, 2-5: Amiga Joy 0-3)" },

/* en */ { IDS_SET_INPUT_EXTRA_JOYLL_2,    "Extra joystick #2 emulation: (0: None, 1: Numpad, 2-5: Amiga Joy 0-3)" },
/* da */ { IDS_SET_INPUT_EXTRA_JOYLL_2_DA, "Ekstra joystick 2 emulering: (0: ingen, 1: numerisk, 2-5: Amigajoystick 0-3)" },
/* de */ { IDS_SET_INPUT_EXTRA_JOYLL_2_DE, "Extra Joystick #2 Emulation: (0: Keine, 1: Numpad, 2-5: Amiga Joystick 0-3)" },
/* es */ { IDS_SET_INPUT_EXTRA_JOYLL_2_ES, "Emulaci�n Joystick suplementario #2: (0:No, 1: Teclado n�merico, 2-5: Amiga Joy0-3 )" },
/* fr */ { IDS_SET_INPUT_EXTRA_JOYLL_2_FR, "" },  /* fuzzy */
/* hu */ { IDS_SET_INPUT_EXTRA_JOYLL_2_HU, "#2-es extra botkorm�ny emul�ci� (0: Nincs, 1: numerikus, 2-5: Amiga botkorm�ny 0-3)" },
/* it */ { IDS_SET_INPUT_EXTRA_JOYLL_2_IT, "Emulazione joystick supplementare #2: (0: Nessuna, 1: Tastierino numerico, 2-5: Joy Amiga 0-3)" },
/* ko */ { IDS_SET_INPUT_EXTRA_JOYLL_2_KO, "" },  /* fuzzy */
/* nl */ { IDS_SET_INPUT_EXTRA_JOYLL_2_NL, "Emulatie extra joystick #2: (0: Geen, 1: Numpad, 2-5: Amiga Joy 0-3)" },
/* pl */ { IDS_SET_INPUT_EXTRA_JOYLL_2_PL, "Emulacja dodatkowego joysticka #2: (0: brak, 1: numeryczna, 2-5: joystick Amigi 0-3)" },
/* ru */ { IDS_SET_INPUT_EXTRA_JOYLL_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_SET_INPUT_EXTRA_JOYLL_2_SV, "Emulering f�r extra styrspak 2: (0: ingen, 1: numerisk, 2-5: Amigastyrspak 0-3)" },
/* tr */ { IDS_SET_INPUT_EXTRA_JOYLL_2_TR, "Ekstra joystick #2 em�lasyonu: (0: Yok, 1: Numpad, 2-5: Amiga Joy 0-3)" },

/* en */ { IDS_SAVE_SETTINGS_ON_EXIT,    "Save settings on exit" },
/* da */ { IDS_SAVE_SETTINGS_ON_EXIT_DA, "Gem indstillinger n�r programmet afsluttes" },
/* de */ { IDS_SAVE_SETTINGS_ON_EXIT_DE, "Einstellungen beim Beenden speichern" },
/* es */ { IDS_SAVE_SETTINGS_ON_EXIT_ES, "Grabar ajustes al salir" },
/* fr */ { IDS_SAVE_SETTINGS_ON_EXIT_FR, "" },  /* fuzzy */
/* hu */ { IDS_SAVE_SETTINGS_ON_EXIT_HU, "Be�ll�t�sok ment�se kil�p�skor" },
/* it */ { IDS_SAVE_SETTINGS_ON_EXIT_IT, "Salva impostazioni in uscita" },
/* ko */ { IDS_SAVE_SETTINGS_ON_EXIT_KO, "����� ���� �����ϱ�" },
/* nl */ { IDS_SAVE_SETTINGS_ON_EXIT_NL, "Sla instellingen op bij afsluiten" },
/* pl */ { IDS_SAVE_SETTINGS_ON_EXIT_PL, "Zapisz ustawienia przy wyj�ciu" },
/* ru */ { IDS_SAVE_SETTINGS_ON_EXIT_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_SETTINGS_ON_EXIT_SV, "Spara inst�llningar vid avslut" },
/* tr */ { IDS_SAVE_SETTINGS_ON_EXIT_TR, "��k��ta ayarlar� kaydet" },

/* en */ { IDS_NEVER_SAVE_SETTINGS_EXIT,    "Never save settings on exit" },
/* da */ { IDS_NEVER_SAVE_SETTINGS_EXIT_DA, "" },  /* fuzzy */
/* de */ { IDS_NEVER_SAVE_SETTINGS_EXIT_DE, "Einstellungen beim Beenden nie speichern" },
/* es */ { IDS_NEVER_SAVE_SETTINGS_EXIT_ES, "no grabar ajustes al salir" },
/* fr */ { IDS_NEVER_SAVE_SETTINGS_EXIT_FR, "" },  /* fuzzy */
/* hu */ { IDS_NEVER_SAVE_SETTINGS_EXIT_HU, "" },  /* fuzzy */
/* it */ { IDS_NEVER_SAVE_SETTINGS_EXIT_IT, "" },  /* fuzzy */
/* ko */ { IDS_NEVER_SAVE_SETTINGS_EXIT_KO, "����� ���� ������ �������� �ʽ��ϴ�" },
/* nl */ { IDS_NEVER_SAVE_SETTINGS_EXIT_NL, "Instellingen nooit opslaan bij afsluiten" },
/* pl */ { IDS_NEVER_SAVE_SETTINGS_EXIT_PL, "Nigdy nie zapisuj ustawie� przy wyj�ciu" },
/* ru */ { IDS_NEVER_SAVE_SETTINGS_EXIT_RU, "" },  /* fuzzy */
/* sv */ { IDS_NEVER_SAVE_SETTINGS_EXIT_SV, "Spara aldrig inst�llningar vid avslut" },
/* tr */ { IDS_NEVER_SAVE_SETTINGS_EXIT_TR, "" },  /* fuzzy */

/* en */ { IDS_CONFIRM_QUITING_VICE,    "Confirm quiting VICE" },
/* da */ { IDS_CONFIRM_QUITING_VICE_DA, "Bekr�ft programafslutning" },
/* de */ { IDS_CONFIRM_QUITING_VICE_DE, "Best�tige beenden von VICE" },
/* es */ { IDS_CONFIRM_QUITING_VICE_ES, "Confirmar el cierre de VICE" },
/* fr */ { IDS_CONFIRM_QUITING_VICE_FR, "Demander une confirmation avant de quitter VICE" },
/* hu */ { IDS_CONFIRM_QUITING_VICE_HU, "Meger�s�t�s kil�p�s el�tt" },
/* it */ { IDS_CONFIRM_QUITING_VICE_IT, "Conferma l'uscita da VICE" },
/* ko */ { IDS_CONFIRM_QUITING_VICE_KO, "VICE Ȯ�� ����" },
/* nl */ { IDS_CONFIRM_QUITING_VICE_NL, "Bevestigen van het aflsuiten van VICE" },
/* pl */ { IDS_CONFIRM_QUITING_VICE_PL, "Potwierdzaj zamkni�cie VICE" },
/* ru */ { IDS_CONFIRM_QUITING_VICE_RU, "" },  /* fuzzy */
/* sv */ { IDS_CONFIRM_QUITING_VICE_SV, "Bekr�fta f�r att avsluta VICE" },
/* tr */ { IDS_CONFIRM_QUITING_VICE_TR, "VICE'dan ��karken teyit et" },

/* en */ { IDS_NEVER_CONFIRM_QUITING_VICE,    "Never confirm quiting VICE" },
/* da */ { IDS_NEVER_CONFIRM_QUITING_VICE_DA, "Bekr�ft ikke programafslutning" },
/* de */ { IDS_NEVER_CONFIRM_QUITING_VICE_DE, "Keine Best�tigung beim Beenden von VICE" },
/* es */ { IDS_NEVER_CONFIRM_QUITING_VICE_ES, "Nunca confirmar el cierre de VICE" },
/* fr */ { IDS_NEVER_CONFIRM_QUITING_VICE_FR, "Ne pas demander de confirmation pour quitter VICE" },
/* hu */ { IDS_NEVER_CONFIRM_QUITING_VICE_HU, "Sosem k�r meger�s�t�st kil�p�s el�tt" },
/* it */ { IDS_NEVER_CONFIRM_QUITING_VICE_IT, "Non confermare mai l'uscita da VICE" },
/* ko */ { IDS_NEVER_CONFIRM_QUITING_VICE_KO, "VICE �� ���� ������ �ʽ��ϴ�" },
/* nl */ { IDS_NEVER_CONFIRM_QUITING_VICE_NL, "Niet bevestigen van het afsluiten van VICE" },
/* pl */ { IDS_NEVER_CONFIRM_QUITING_VICE_PL, "Nigdy nie potwierdzaj zamkni�cia VICE" },
/* ru */ { IDS_NEVER_CONFIRM_QUITING_VICE_RU, "" },  /* fuzzy */
/* sv */ { IDS_NEVER_CONFIRM_QUITING_VICE_SV, "Bekr�fta inte f�r att avsluta VICE" },
/* tr */ { IDS_NEVER_CONFIRM_QUITING_VICE_TR, "VICE'dan ��karken asla teyit etme" },

/* en */ { IDS_PET_REU_SIZE,    "PET REU size" },
/* da */ { IDS_PET_REU_SIZE_DA, "PET REU st�rrelse" },
/* de */ { IDS_PET_REU_SIZE_DE, "PET REU Gr��e" },
/* es */ { IDS_PET_REU_SIZE_ES, "Tama�o REU PET" },
/* fr */ { IDS_PET_REU_SIZE_FR, "" },  /* fuzzy */
/* hu */ { IDS_PET_REU_SIZE_HU, "PET REU m�rete" },
/* it */ { IDS_PET_REU_SIZE_IT, "Dimensione PET REU" },
/* ko */ { IDS_PET_REU_SIZE_KO, "" },  /* fuzzy */
/* nl */ { IDS_PET_REU_SIZE_NL, "PET REU grootte" },
/* pl */ { IDS_PET_REU_SIZE_PL, "Rozmiar PET REU" },
/* ru */ { IDS_PET_REU_SIZE_RU, "" },  /* fuzzy */
/* sv */ { IDS_PET_REU_SIZE_SV, "Storlek p� PET REU" },
/* tr */ { IDS_PET_REU_SIZE_TR, "PET REU boyutu" },

/* en */ { IDS_PET_REU_FILENAME,    "PET REU file" },
/* da */ { IDS_PET_REU_FILENAME_DA, "PET REU-fil" },
/* de */ { IDS_PET_REU_FILENAME_DE, "PET REU Datei" },
/* es */ { IDS_PET_REU_FILENAME_ES, "Fichero REU PET" },
/* fr */ { IDS_PET_REU_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_PET_REU_FILENAME_HU, "PET REU f�jl" },
/* it */ { IDS_PET_REU_FILENAME_IT, "File PET REU" },
/* ko */ { IDS_PET_REU_FILENAME_KO, "PET REU ����" },
/* nl */ { IDS_PET_REU_FILENAME_NL, "PET REU bestand" },
/* pl */ { IDS_PET_REU_FILENAME_PL, "Plik PET REU" },
/* ru */ { IDS_PET_REU_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_PET_REU_FILENAME_SV, "PET REU-fil" },
/* tr */ { IDS_PET_REU_FILENAME_TR, "PET REU dosyas�" },

/* en */ { IDS_PET_REU_FILENAME_SELECT,    "Select file for PET REU" },
/* da */ { IDS_PET_REU_FILENAME_SELECT_DA, "V�lg fil for PET REU" },
/* de */ { IDS_PET_REU_FILENAME_SELECT_DE, "Datei f�r PET REU ausw�hlen" },
/* es */ { IDS_PET_REU_FILENAME_SELECT_ES, "Seleccionar fichero para REU PET" },
/* fr */ { IDS_PET_REU_FILENAME_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_PET_REU_FILENAME_SELECT_HU, "V�lasszon f�jlt a PET REU-hoz" },
/* it */ { IDS_PET_REU_FILENAME_SELECT_IT, "Seleziona il file per il PET REU" },
/* ko */ { IDS_PET_REU_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_PET_REU_FILENAME_SELECT_NL, "Selecteer bestand voor PET REU" },
/* pl */ { IDS_PET_REU_FILENAME_SELECT_PL, "Wybierz plik PET REU" },
/* ru */ { IDS_PET_REU_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_PET_REU_FILENAME_SELECT_SV, "V�lj fil f�r PET REU" },
/* tr */ { IDS_PET_REU_FILENAME_SELECT_TR, "PET REU i�in dosya se�in" },

/* en */ { IDS_PET_REU_SETTINGS,    "PET REU settings" },
/* da */ { IDS_PET_REU_SETTINGS_DA, "PET REU-indstillinger" },
/* de */ { IDS_PET_REU_SETTINGS_DE, "PET REU Einstellungen" },
/* es */ { IDS_PET_REU_SETTINGS_ES, "Ajustes PET REU" },
/* fr */ { IDS_PET_REU_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_PET_REU_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_PET_REU_SETTINGS_IT, "Impostazioni PET REU" },
/* ko */ { IDS_PET_REU_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_PET_REU_SETTINGS_NL, "PET REU instellingen" },
/* pl */ { IDS_PET_REU_SETTINGS_PL, "Ustawienia PET REU" },
/* ru */ { IDS_PET_REU_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_PET_REU_SETTINGS_SV, "PET REU-Inst�llningar" },
/* tr */ { IDS_PET_REU_SETTINGS_TR, "PET REU Ayarlar�" },

/* en */ { IDS_V364_SPEECH_FILENAME,    "V364 Speech ROM file" },
/* da */ { IDS_V364_SPEECH_FILENAME_DA, "V364 Speech ROM-fil" },
/* de */ { IDS_V364_SPEECH_FILENAME_DE, "V364 Stimme ROM Datei" },
/* es */ { IDS_V364_SPEECH_FILENAME_ES, "Fichero ROM  V364 Speech" },
/* fr */ { IDS_V364_SPEECH_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_V364_SPEECH_FILENAME_HU, "" },  /* fuzzy */
/* it */ { IDS_V364_SPEECH_FILENAME_IT, "File ROM V364 Speech" },
/* ko */ { IDS_V364_SPEECH_FILENAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_V364_SPEECH_FILENAME_NL, "V364 spraak ROM bestand" },
/* pl */ { IDS_V364_SPEECH_FILENAME_PL, "Plik ROM V364 Speech" },
/* ru */ { IDS_V364_SPEECH_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_V364_SPEECH_FILENAME_SV, "ROM-fil f�r V364-r�st" },
/* tr */ { IDS_V364_SPEECH_FILENAME_TR, "V364 Speech ROM dosyas�" },

/* en */ { IDS_V364_SPEECH_FILENAME_SELECT,    "Select file for V364 Speech" },
/* da */ { IDS_V364_SPEECH_FILENAME_SELECT_DA, "Angiv fil for V364 Speech" },
/* de */ { IDS_V364_SPEECH_FILENAME_SELECT_DE, "Datei f�r V364 Stimme ausw�hlen" },
/* es */ { IDS_V364_SPEECH_FILENAME_SELECT_ES, "Seleccionar fichero para V364 Speech" },
/* fr */ { IDS_V364_SPEECH_FILENAME_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_V364_SPEECH_FILENAME_SELECT_HU, "" },  /* fuzzy */
/* it */ { IDS_V364_SPEECH_FILENAME_SELECT_IT, "Seleziona file per V364 Speech" },
/* ko */ { IDS_V364_SPEECH_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_V364_SPEECH_FILENAME_SELECT_NL, "Selecteer bestand voor V364 Spraak" },
/* pl */ { IDS_V364_SPEECH_FILENAME_SELECT_PL, "Wybierz plik mowy V364" },
/* ru */ { IDS_V364_SPEECH_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_V364_SPEECH_FILENAME_SELECT_SV, "V�lj fil f�r V364-r�st" },
/* tr */ { IDS_V364_SPEECH_FILENAME_SELECT_TR, "V364 Speech i�in dosya se�in" },

/* en */ { IDS_V364_SPEECH_SETTINGS,    "V364 Speech settings" },
/* da */ { IDS_V364_SPEECH_SETTINGS_DA, "V364 tale-indstillinger" },
/* de */ { IDS_V364_SPEECH_SETTINGS_DE, "V364 Stimme Einstellungen" },
/* es */ { IDS_V364_SPEECH_SETTINGS_ES, "Ajustes V364 Speech" },
/* fr */ { IDS_V364_SPEECH_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_V364_SPEECH_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_V364_SPEECH_SETTINGS_IT, "Impostazioni V364 Speech" },
/* ko */ { IDS_V364_SPEECH_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_V364_SPEECH_SETTINGS_NL, "V364 Spraak instellingen" },
/* pl */ { IDS_V364_SPEECH_SETTINGS_PL, "Ustawienia mowy V364" },
/* ru */ { IDS_V364_SPEECH_SETTINGS_RU, "��������� ���� V364" },
/* sv */ { IDS_V364_SPEECH_SETTINGS_SV, "V364-r�stinst�llningar" },
/* tr */ { IDS_V364_SPEECH_SETTINGS_TR, "V364 Speech ayarlar�" },

/* en */ { IDS_PET_DWW_FILENAME,    "PET DWW file" },
/* da */ { IDS_PET_DWW_FILENAME_DA, "PET DWW fil" },
/* de */ { IDS_PET_DWW_FILENAME_DE, "PET DWW Datei" },
/* es */ { IDS_PET_DWW_FILENAME_ES, "Fihcero DWW PET" },
/* fr */ { IDS_PET_DWW_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_PET_DWW_FILENAME_HU, "" },  /* fuzzy */
/* it */ { IDS_PET_DWW_FILENAME_IT, "File PET DWW" },
/* ko */ { IDS_PET_DWW_FILENAME_KO, "PET DWW ����" },
/* nl */ { IDS_PET_DWW_FILENAME_NL, "PET DWW bestand" },
/* pl */ { IDS_PET_DWW_FILENAME_PL, "Plik PET DWW" },
/* ru */ { IDS_PET_DWW_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_PET_DWW_FILENAME_SV, "PET DWW-fil" },
/* tr */ { IDS_PET_DWW_FILENAME_TR, "PET DWW dosyas�" },

/* en */ { IDS_PET_DWW_FILENAME_SELECT,    "Select file for PET DWW" },
/* da */ { IDS_PET_DWW_FILENAME_SELECT_DA, "V�lg fil for PET DWW" },
/* de */ { IDS_PET_DWW_FILENAME_SELECT_DE, "Datei f�r PET DWW ausw�hlen" },
/* es */ { IDS_PET_DWW_FILENAME_SELECT_ES, "Seleccionar fichero para DWW PET" },
/* fr */ { IDS_PET_DWW_FILENAME_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_PET_DWW_FILENAME_SELECT_HU, "" },  /* fuzzy */
/* it */ { IDS_PET_DWW_FILENAME_SELECT_IT, "Seleziona file per il PET DWW" },
/* ko */ { IDS_PET_DWW_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_PET_DWW_FILENAME_SELECT_NL, "Selecteer bestand voor PET DWW" },
/* pl */ { IDS_PET_DWW_FILENAME_SELECT_PL, "Wybierz plik PET DWW" },
/* ru */ { IDS_PET_DWW_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_PET_DWW_FILENAME_SELECT_SV, "V�lj fil f�r PET DWW" },
/* tr */ { IDS_PET_DWW_FILENAME_SELECT_TR, "PET DWW i�in dosya se�in" },

/* en */ { IDS_PET_DWW_SETTINGS,    "PET DWW settings" },
/* da */ { IDS_PET_DWW_SETTINGS_DA, "PET DWW-indstillinger" },
/* de */ { IDS_PET_DWW_SETTINGS_DE, "PET DWW Einstellungen" },
/* es */ { IDS_PET_DWW_SETTINGS_ES, "Ajustes PET DWW" },
/* fr */ { IDS_PET_DWW_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_PET_DWW_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_PET_DWW_SETTINGS_IT, "Impostazioni PET DWW" },
/* ko */ { IDS_PET_DWW_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_PET_DWW_SETTINGS_NL, "PET DWW instellingen" },
/* pl */ { IDS_PET_DWW_SETTINGS_PL, "Ustawienia PET DWW" },
/* ru */ { IDS_PET_DWW_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_PET_DWW_SETTINGS_SV, "PET DWW-Inst�llningar" },
/* tr */ { IDS_PET_DWW_SETTINGS_TR, "PET DWW Ayarlar�" },

/* en */ { IDS_PLUS256K_SETTINGS,    "PLUS256K settings" },
/* da */ { IDS_PLUS256K_SETTINGS_DA, "PLUS256K-indstillinger" },
/* de */ { IDS_PLUS256K_SETTINGS_DE, "PLUS256K Einstellungen" },
/* es */ { IDS_PLUS256K_SETTINGS_ES, "Ajustes PLUS256K" },
/* fr */ { IDS_PLUS256K_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_PLUS256K_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_PLUS256K_SETTINGS_IT, "Impostazioni PLUS256K" },
/* ko */ { IDS_PLUS256K_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_PLUS256K_SETTINGS_NL, "PLUS256K instellingen" },
/* pl */ { IDS_PLUS256K_SETTINGS_PL, "Ustawienia PLUS256K" },
/* ru */ { IDS_PLUS256K_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_PLUS256K_SETTINGS_SV, "PLUS256K-inst�llningar" },
/* tr */ { IDS_PLUS256K_SETTINGS_TR, "PLUS256K Ayarlar�" },

/* en */ { IDS_PLUS60K_BASE,    "PLUS60K base address" },
/* da */ { IDS_PLUS60K_BASE_DA, "Basadress f�r PLUS60K" },
/* de */ { IDS_PLUS60K_BASE_DE, "PLUS60K Basis Adresse" },
/* es */ { IDS_PLUS60K_BASE_ES, "Direcci�n base PLUS60K" },
/* fr */ { IDS_PLUS60K_BASE_FR, "" },  /* fuzzy */
/* hu */ { IDS_PLUS60K_BASE_HU, "PLUS60K b�zisc�me" },
/* it */ { IDS_PLUS60K_BASE_IT, "indirizzo base PLUS60K" },
/* ko */ { IDS_PLUS60K_BASE_KO, "" },  /* fuzzy */
/* nl */ { IDS_PLUS60K_BASE_NL, "PLUS60K basisadres" },
/* pl */ { IDS_PLUS60K_BASE_PL, "Adres bazowy PLUS60K" },
/* ru */ { IDS_PLUS60K_BASE_RU, "" },  /* fuzzy */
/* sv */ { IDS_PLUS60K_BASE_SV, "Basadress f�r PLUS60K" },
/* tr */ { IDS_PLUS60K_BASE_TR, "PLUS60K taban adresi" },

/* en */ { IDS_PLUS60K_FILENAME,    "PLUS60K file" },
/* da */ { IDS_PLUS60K_FILENAME_DA, "PLUS60K-fil" },
/* de */ { IDS_PLUS60K_FILENAME_DE, "PLUS60K Datei" },
/* es */ { IDS_PLUS60K_FILENAME_ES, "Fichero PLUS60K" },
/* fr */ { IDS_PLUS60K_FILENAME_FR, "Fichier POLUS60K" },
/* hu */ { IDS_PLUS60K_FILENAME_HU, "PLUS60K f�jl" },
/* it */ { IDS_PLUS60K_FILENAME_IT, "File PLUS60K" },
/* ko */ { IDS_PLUS60K_FILENAME_KO, "PLUS60K ����" },
/* nl */ { IDS_PLUS60K_FILENAME_NL, "PLUS60K bestand" },
/* pl */ { IDS_PLUS60K_FILENAME_PL, "Plik PLUS60K" },
/* ru */ { IDS_PLUS60K_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_PLUS60K_FILENAME_SV, "PLUS60K-fil" },
/* tr */ { IDS_PLUS60K_FILENAME_TR, "PLUS60K dosyas�" },

/* en */ { IDS_PLUS60K_FILENAME_SELECT,    "Select file for PLUS60K" },
/* da */ { IDS_PLUS60K_FILENAME_SELECT_DA, "V�lg fil for PLUS60K" },
/* de */ { IDS_PLUS60K_FILENAME_SELECT_DE, "Datei f�r PLUS60K ausw�hlen" },
/* es */ { IDS_PLUS60K_FILENAME_SELECT_ES, "Seleccionar fichero para PLUS60K" },
/* fr */ { IDS_PLUS60K_FILENAME_SELECT_FR, "S�lectionner fichier pour PLUS60K" },
/* hu */ { IDS_PLUS60K_FILENAME_SELECT_HU, "V�lasszon f�jlt a PLUS60K-hoz" },
/* it */ { IDS_PLUS60K_FILENAME_SELECT_IT, "Seleziona file per PLUS60K" },
/* ko */ { IDS_PLUS60K_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_PLUS60K_FILENAME_SELECT_NL, "Selecteer bestand voor PLUS60K" },
/* pl */ { IDS_PLUS60K_FILENAME_SELECT_PL, "Wybierz plik PLUS60K" },
/* ru */ { IDS_PLUS60K_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_PLUS60K_FILENAME_SELECT_SV, "Ange fil f�r PLUS60K" },
/* tr */ { IDS_PLUS60K_FILENAME_SELECT_TR, "PLUS60K i�in dosya se�in" },

/* en */ { IDS_PLUS60K_SETTINGS,    "PLUS60K settings" },
/* da */ { IDS_PLUS60K_SETTINGS_DA, "PLUS60K-indstillinger" },
/* de */ { IDS_PLUS60K_SETTINGS_DE, "PLUS60K Einstellungen" },
/* es */ { IDS_PLUS60K_SETTINGS_ES, "Ajustes PLUS60K" },
/* fr */ { IDS_PLUS60K_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_PLUS60K_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_PLUS60K_SETTINGS_IT, "Impostazioni PLUS256K" },
/* ko */ { IDS_PLUS60K_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_PLUS60K_SETTINGS_NL, "PLUS60K instellingen" },
/* pl */ { IDS_PLUS60K_SETTINGS_PL, "Ustawienia PLUS60K" },
/* ru */ { IDS_PLUS60K_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_PLUS60K_SETTINGS_SV, "PLUS60K-inst�llningar" },
/* tr */ { IDS_PLUS60K_SETTINGS_TR, "PLUS60K Ayarlar�" },

/* en */ { IDS_VALUE_FIRST_BYTE,    "Value of first byte" },
/* da */ { IDS_VALUE_FIRST_BYTE_DA, "V�rdi p� f�rste byte" },
/* de */ { IDS_VALUE_FIRST_BYTE_DE, "Wert erstes Byte" },
/* es */ { IDS_VALUE_FIRST_BYTE_ES, "Valor del primer byte" },
/* fr */ { IDS_VALUE_FIRST_BYTE_FR, "Valeur du premier octet" },
/* hu */ { IDS_VALUE_FIRST_BYTE_HU, "Els� b�jt �rt�ke" },
/* it */ { IDS_VALUE_FIRST_BYTE_IT, "Valore del primo byte" },
/* ko */ { IDS_VALUE_FIRST_BYTE_KO, "" },  /* fuzzy */
/* nl */ { IDS_VALUE_FIRST_BYTE_NL, "Waarde van eerste byte" },
/* pl */ { IDS_VALUE_FIRST_BYTE_PL, "Warto�� pierwszego bajta" },
/* ru */ { IDS_VALUE_FIRST_BYTE_RU, "" },  /* fuzzy */
/* sv */ { IDS_VALUE_FIRST_BYTE_SV, "V�rde p� f�rsta byte" },
/* tr */ { IDS_VALUE_FIRST_BYTE_TR, "�lk byte de�eri" },

/* en */ { IDS_LENGTH_CONSTANT_VALUES,    "Length of constant values" },
/* da */ { IDS_LENGTH_CONSTANT_VALUES_DA, "L�ngde af konstant v�rdi" },
/* de */ { IDS_LENGTH_CONSTANT_VALUES_DE, "L�nge der konstaten Werte" },
/* es */ { IDS_LENGTH_CONSTANT_VALUES_ES, "Longitud de valores constantes" },
/* fr */ { IDS_LENGTH_CONSTANT_VALUES_FR, "Longeur des valeurs constantes" },
/* hu */ { IDS_LENGTH_CONSTANT_VALUES_HU, "�lland� �rt�kek hossza" },
/* it */ { IDS_LENGTH_CONSTANT_VALUES_IT, "Lunghezza dei valori costanti" },
/* ko */ { IDS_LENGTH_CONSTANT_VALUES_KO, "" },  /* fuzzy */
/* nl */ { IDS_LENGTH_CONSTANT_VALUES_NL, "Lengte van constante waarden" },
/* pl */ { IDS_LENGTH_CONSTANT_VALUES_PL, "D�ugo�� sta�ych warto�ci" },
/* ru */ { IDS_LENGTH_CONSTANT_VALUES_RU, "" },  /* fuzzy */
/* sv */ { IDS_LENGTH_CONSTANT_VALUES_SV, "L�ngd p� konstanta v�rden" },
/* tr */ { IDS_LENGTH_CONSTANT_VALUES_TR, "Sabit de�erlerin uzunlu�u" },

/* en */ { IDS_LENGTH_CONSTANT_PATTERN,    "Length of constant pattern" },
/* da */ { IDS_LENGTH_CONSTANT_PATTERN_DA, "L�ngde af konstant m�nster" },
/* de */ { IDS_LENGTH_CONSTANT_PATTERN_DE, "L�nge des konstanten Musters" },
/* es */ { IDS_LENGTH_CONSTANT_PATTERN_ES, "Longitud de patrones constantes" },
/* fr */ { IDS_LENGTH_CONSTANT_PATTERN_FR, "Longeur des contantes pattern" },
/* hu */ { IDS_LENGTH_CONSTANT_PATTERN_HU, "�lland� minta hossza" },
/* it */ { IDS_LENGTH_CONSTANT_PATTERN_IT, "Lunghezza dei pattern costanti" },
/* ko */ { IDS_LENGTH_CONSTANT_PATTERN_KO, "" },  /* fuzzy */
/* nl */ { IDS_LENGTH_CONSTANT_PATTERN_NL, "Lengte van constant patroon" },
/* pl */ { IDS_LENGTH_CONSTANT_PATTERN_PL, "L�ugo�� sta�ego wzorca" },
/* ru */ { IDS_LENGTH_CONSTANT_PATTERN_RU, "" },  /* fuzzy */
/* sv */ { IDS_LENGTH_CONSTANT_PATTERN_SV, "L�ngd p� konstant m�nster" },
/* tr */ { IDS_LENGTH_CONSTANT_PATTERN_TR, "Sabit desenlerin uzunlu�u" },

/* en */ { IDS_RAM_SETTINGS,    "RAM settings" },
/* da */ { IDS_RAM_SETTINGS_DA, "RAM-indstillinger" },
/* de */ { IDS_RAM_SETTINGS_DE, "RAM Einstellungen" },
/* es */ { IDS_RAM_SETTINGS_ES, "Ajustes RAM" },
/* fr */ { IDS_RAM_SETTINGS_FR, "Param�tres de la RAM" },
/* hu */ { IDS_RAM_SETTINGS_HU, "RAM be�ll�t�sai" },
/* it */ { IDS_RAM_SETTINGS_IT, "Impostazioni RAM" },
/* ko */ { IDS_RAM_SETTINGS_KO, "RAM ����" },
/* nl */ { IDS_RAM_SETTINGS_NL, "RAM instellingen" },
/* pl */ { IDS_RAM_SETTINGS_PL, "Ustawienia RAM" },
/* ru */ { IDS_RAM_SETTINGS_RU, "��������� RAM" },
/* sv */ { IDS_RAM_SETTINGS_SV, "RAM-inst�llningar" },
/* tr */ { IDS_RAM_SETTINGS_TR, "RAM ayarlar�" },

/* en */ { IDS_READ_WRITE,    "read/write" },
/* da */ { IDS_READ_WRITE_DA, "skrivbar" },
/* de */ { IDS_READ_WRITE_DE, "lese/schreibe" },
/* es */ { IDS_READ_WRITE_ES, "Leer/Grabar" },
/* fr */ { IDS_READ_WRITE_FR, "lecture/�criture" },
/* hu */ { IDS_READ_WRITE_HU, "�rhat�/olvashat�" },
/* it */ { IDS_READ_WRITE_IT, "lettura/scrittura" },
/* ko */ { IDS_READ_WRITE_KO, "�б�/����" },
/* nl */ { IDS_READ_WRITE_NL, "lees/schrijf" },
/* pl */ { IDS_READ_WRITE_PL, "oczyt/zapis" },
/* ru */ { IDS_READ_WRITE_RU, "" },  /* fuzzy */
/* sv */ { IDS_READ_WRITE_SV, "skrivbar" },
/* tr */ { IDS_READ_WRITE_TR, "oku/yaz" },

/* en */ { IDS_READ_ONLY,    "Read-only" },
/* da */ { IDS_READ_ONLY_DA, "" },  /* fuzzy */
/* de */ { IDS_READ_ONLY_DE, "Schreibgesch�tzt" },
/* es */ { IDS_READ_ONLY_ES, "S�lo lectura" },
/* fr */ { IDS_READ_ONLY_FR, "" },  /* fuzzy */
/* hu */ { IDS_READ_ONLY_HU, "" },  /* fuzzy */
/* it */ { IDS_READ_ONLY_IT, "" },  /* fuzzy */
/* ko */ { IDS_READ_ONLY_KO, "�б� ����" },
/* nl */ { IDS_READ_ONLY_NL, "Alleen-lezen" },
/* pl */ { IDS_READ_ONLY_PL, "Tylko do odczytu" },
/* ru */ { IDS_READ_ONLY_RU, "" },  /* fuzzy */
/* sv */ { IDS_READ_ONLY_SV, "Endast l�sning" },
/* tr */ { IDS_READ_ONLY_TR, "" },  /* fuzzy */

/* en */ { IDS_RAMCART_READ_WRITE,    "RamCart Read/Write" },
/* da */ { IDS_RAMCART_READ_WRITE_DA, "RamCart l�s/skriv" },
/* de */ { IDS_RAMCART_READ_WRITE_DE, "RamCart Lesen/Schreiben" },
/* es */ { IDS_RAMCART_READ_WRITE_ES, "Lectura/Grabaci�n RamCart" },
/* fr */ { IDS_RAMCART_READ_WRITE_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAMCART_READ_WRITE_HU, "" },  /* fuzzy */
/* it */ { IDS_RAMCART_READ_WRITE_IT, "RamCart in lettura/scrittura" },
/* ko */ { IDS_RAMCART_READ_WRITE_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAMCART_READ_WRITE_NL, "RamCart lees/schrijf" },
/* pl */ { IDS_RAMCART_READ_WRITE_PL, "Odczyt i zapis na RamCart" },
/* ru */ { IDS_RAMCART_READ_WRITE_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAMCART_READ_WRITE_SV, "Skrivbart RamCart" },
/* tr */ { IDS_RAMCART_READ_WRITE_TR, "RamCart Oku/Yaz" },

/* en */ { IDS_RAMCART_SIZE,    "RamCart size" },
/* da */ { IDS_RAMCART_SIZE_DA, "RamCart-st�rrelse" },
/* de */ { IDS_RAMCART_SIZE_DE, "RamCart Gr��e" },
/* es */ { IDS_RAMCART_SIZE_ES, "Tama�o RamCart" },
/* fr */ { IDS_RAMCART_SIZE_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAMCART_SIZE_HU, "" },  /* fuzzy */
/* it */ { IDS_RAMCART_SIZE_IT, "Dimensione RamCart" },
/* ko */ { IDS_RAMCART_SIZE_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAMCART_SIZE_NL, "RamCart grootte" },
/* pl */ { IDS_RAMCART_SIZE_PL, "Rozmiar RamCart" },
/* ru */ { IDS_RAMCART_SIZE_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAMCART_SIZE_SV, "RamCart-storlek" },
/* tr */ { IDS_RAMCART_SIZE_TR, "RamCart boyutu" },

/* en */ { IDS_RAMCART_FILENAME,    "RamCart file" },
/* da */ { IDS_RAMCART_FILENAME_DA, "RamCart fil" },
/* de */ { IDS_RAMCART_FILENAME_DE, "RamCart Datei" },
/* es */ { IDS_RAMCART_FILENAME_ES, "Fichero RamCart" },
/* fr */ { IDS_RAMCART_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAMCART_FILENAME_HU, "" },  /* fuzzy */
/* it */ { IDS_RAMCART_FILENAME_IT, "File RamCart" },
/* ko */ { IDS_RAMCART_FILENAME_KO, "RamCart ����" },
/* nl */ { IDS_RAMCART_FILENAME_NL, "RamCart bestand" },
/* pl */ { IDS_RAMCART_FILENAME_PL, "Plik RamCart" },
/* ru */ { IDS_RAMCART_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAMCART_FILENAME_SV, "RamCart-fil" },
/* tr */ { IDS_RAMCART_FILENAME_TR, "RamCart dosyas�" },

/* en */ { IDS_SAVE_RAMCART_IMAGE_WHEN_CHANGED,    "Save RamCart image when changed" },
/* da */ { IDS_SAVE_RAMCART_IMAGE_WHEN_CHANGED_DA, "Gem RamCart image ved �ndringer" },
/* de */ { IDS_SAVE_RAMCART_IMAGE_WHEN_CHANGED_DE, "RamCart Imagedatei bei �nderung speichern" },
/* es */ { IDS_SAVE_RAMCART_IMAGE_WHEN_CHANGED_ES, "Grabar imagen RamChart cuando cambie" },
/* fr */ { IDS_SAVE_RAMCART_IMAGE_WHEN_CHANGED_FR, "" },  /* fuzzy */
/* hu */ { IDS_SAVE_RAMCART_IMAGE_WHEN_CHANGED_HU, "" },  /* fuzzy */
/* it */ { IDS_SAVE_RAMCART_IMAGE_WHEN_CHANGED_IT, "Salva immagine RamCart al cambio" },
/* ko */ { IDS_SAVE_RAMCART_IMAGE_WHEN_CHANGED_KO, "" },  /* fuzzy */
/* nl */ { IDS_SAVE_RAMCART_IMAGE_WHEN_CHANGED_NL, "Ramcart bestand opslaan indien gewijzigd" },
/* pl */ { IDS_SAVE_RAMCART_IMAGE_WHEN_CHANGED_PL, "Zapisuj obraz RamCart przy zmianie" },
/* ru */ { IDS_SAVE_RAMCART_IMAGE_WHEN_CHANGED_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_RAMCART_IMAGE_WHEN_CHANGED_SV, "Spara RamCart-avbildning vid �ndringar" },
/* tr */ { IDS_SAVE_RAMCART_IMAGE_WHEN_CHANGED_TR, "RamCart imaj� de�i�ti�inde kaydet" },

/* en */ { IDS_RAMCART_FILENAME_SELECT,    "Select file for RamCart" },
/* da */ { IDS_RAMCART_FILENAME_SELECT_DA, "V�lg fil for RamCart" },
/* de */ { IDS_RAMCART_FILENAME_SELECT_DE, "Datei f�r RamCart ausw�hlen" },
/* es */ { IDS_RAMCART_FILENAME_SELECT_ES, "Seleccionar fichero para RamCart" },
/* fr */ { IDS_RAMCART_FILENAME_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAMCART_FILENAME_SELECT_HU, "" },  /* fuzzy */
/* it */ { IDS_RAMCART_FILENAME_SELECT_IT, "Seleziona file per RamCart" },
/* ko */ { IDS_RAMCART_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAMCART_FILENAME_SELECT_NL, "Selecteer bestand voor RamCart" },
/* pl */ { IDS_RAMCART_FILENAME_SELECT_PL, "Wybierz plik RamCart" },
/* ru */ { IDS_RAMCART_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAMCART_FILENAME_SELECT_SV, "V�lj fil f�r RamCart" },
/* tr */ { IDS_RAMCART_FILENAME_SELECT_TR, "RamCart i�in dosya se�in" },

/* en */ { IDS_RAMCART_SETTINGS,    "RamCart settings" },
/* da */ { IDS_RAMCART_SETTINGS_DA, "RamCart-indstillinger" },
/* de */ { IDS_RAMCART_SETTINGS_DE, "RamCart Einstellungen" },
/* es */ { IDS_RAMCART_SETTINGS_ES, "Ajustes RamCart" },
/* fr */ { IDS_RAMCART_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAMCART_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_RAMCART_SETTINGS_IT, "Impostazioni RamCart " },
/* ko */ { IDS_RAMCART_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAMCART_SETTINGS_NL, "RamCart instellingen" },
/* pl */ { IDS_RAMCART_SETTINGS_PL, "Ustawienia RamCart" },
/* ru */ { IDS_RAMCART_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAMCART_SETTINGS_SV, "RamCart-inst�llningar" },
/* tr */ { IDS_RAMCART_SETTINGS_TR, "RamCart ayarlar�" },

/* en */ { IDS_REU_SIZE,    "REU size" },
/* da */ { IDS_REU_SIZE_DA, "REU st�rrelse" },
/* de */ { IDS_REU_SIZE_DE, "REU Gr��e" },
/* es */ { IDS_REU_SIZE_ES, "Tama�o REU" },
/* fr */ { IDS_REU_SIZE_FR, "Taille du REU" },
/* hu */ { IDS_REU_SIZE_HU, "REU m�rete" },
/* it */ { IDS_REU_SIZE_IT, "Dimensione REU" },
/* ko */ { IDS_REU_SIZE_KO, "" },  /* fuzzy */
/* nl */ { IDS_REU_SIZE_NL, "REU grootte" },
/* pl */ { IDS_REU_SIZE_PL, "Rozmiar REU" },
/* ru */ { IDS_REU_SIZE_RU, "" },  /* fuzzy */
/* sv */ { IDS_REU_SIZE_SV, "Storlek p� minnesexpansion" },
/* tr */ { IDS_REU_SIZE_TR, "REU boyutu" },

/* en */ { IDS_REU_FILENAME,    "REU file" },
/* da */ { IDS_REU_FILENAME_DA, "REU-fil" },
/* de */ { IDS_REU_FILENAME_DE, "REU Datei" },
/* es */ { IDS_REU_FILENAME_ES, "Fichero REU" },
/* fr */ { IDS_REU_FILENAME_FR, "Fichier REU" },
/* hu */ { IDS_REU_FILENAME_HU, "REU f�jl" },
/* it */ { IDS_REU_FILENAME_IT, "File del REU" },
/* ko */ { IDS_REU_FILENAME_KO, "REU ����" },
/* nl */ { IDS_REU_FILENAME_NL, "REU bestand" },
/* pl */ { IDS_REU_FILENAME_PL, "Plik REU" },
/* ru */ { IDS_REU_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_REU_FILENAME_SV, "REU-fil" },
/* tr */ { IDS_REU_FILENAME_TR, "REU dosyas�" },

/* en */ { IDS_SAVE_REU_IMAGE_WHEN_CHANGED,    "Save REU image when changed" },
/* da */ { IDS_SAVE_REU_IMAGE_WHEN_CHANGED_DA, "Gem REU image ved �ndringer" },
/* de */ { IDS_SAVE_REU_IMAGE_WHEN_CHANGED_DE, "REU Imagedatei bei �nderung speichern" },
/* es */ { IDS_SAVE_REU_IMAGE_WHEN_CHANGED_ES, "Grabar imagen REU cuando cambie" },
/* fr */ { IDS_SAVE_REU_IMAGE_WHEN_CHANGED_FR, "" },  /* fuzzy */
/* hu */ { IDS_SAVE_REU_IMAGE_WHEN_CHANGED_HU, "" },  /* fuzzy */
/* it */ { IDS_SAVE_REU_IMAGE_WHEN_CHANGED_IT, "Salva immagine REU al cambio" },
/* ko */ { IDS_SAVE_REU_IMAGE_WHEN_CHANGED_KO, "" },  /* fuzzy */
/* nl */ { IDS_SAVE_REU_IMAGE_WHEN_CHANGED_NL, "REU bestand opslaan indien gewijzigd" },
/* pl */ { IDS_SAVE_REU_IMAGE_WHEN_CHANGED_PL, "Zapisuj obraz REU przy zmianie" },
/* ru */ { IDS_SAVE_REU_IMAGE_WHEN_CHANGED_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_REU_IMAGE_WHEN_CHANGED_SV, "Spara REU-avbildning vid �ndringar" },
/* tr */ { IDS_SAVE_REU_IMAGE_WHEN_CHANGED_TR, "REU imaj� de�i�ti�inde kaydet" },

/* en */ { IDS_REU_FILENAME_SELECT,    "Select file for REU" },
/* da */ { IDS_REU_FILENAME_SELECT_DA, "V�lg fil for REU" },
/* de */ { IDS_REU_FILENAME_SELECT_DE, "Datei f�r REU ausw�hlen" },
/* es */ { IDS_REU_FILENAME_SELECT_ES, "Seleccionar fichero para REU" },
/* fr */ { IDS_REU_FILENAME_SELECT_FR, "S�lectionner fichier pour REU" },
/* hu */ { IDS_REU_FILENAME_SELECT_HU, "V�lasszon f�jlt a REU-hoz" },
/* it */ { IDS_REU_FILENAME_SELECT_IT, "Seleziona il file per il REU" },
/* ko */ { IDS_REU_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_REU_FILENAME_SELECT_NL, "Selecteer bestand voor REU" },
/* pl */ { IDS_REU_FILENAME_SELECT_PL, "Wybierz plik REU" },
/* ru */ { IDS_REU_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_REU_FILENAME_SELECT_SV, "V�lj fil f�r REU" },
/* tr */ { IDS_REU_FILENAME_SELECT_TR, "REU i�in dosya se�in" },

/* en */ { IDS_REU_SETTINGS,    "REU settings" },
/* da */ { IDS_REU_SETTINGS_DA, "REU-indstillinger" },
/* de */ { IDS_REU_SETTINGS_DE, "REU Einstellungen" },
/* es */ { IDS_REU_SETTINGS_ES, "Ajustes REU" },
/* fr */ { IDS_REU_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_REU_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_REU_SETTINGS_IT, "Impostazioni REU" },
/* ko */ { IDS_REU_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_REU_SETTINGS_NL, "REU instellingen" },
/* pl */ { IDS_REU_SETTINGS_PL, "Ustawienia REU" },
/* ru */ { IDS_REU_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_REU_SETTINGS_SV, "REU-Inst�llningar" },
/* tr */ { IDS_REU_SETTINGS_TR, "REU Ayarlar�" },

/* en */ { IDS_PRINTER_OUTPUT_FILENAME_SELECT,    "Select printer dump file" },
/* da */ { IDS_PRINTER_OUTPUT_FILENAME_SELECT_DA, "V�lg udskriftsdumpfil" },
/* de */ { IDS_PRINTER_OUTPUT_FILENAME_SELECT_DE, "Drucker Ausgabedatei definieren" },
/* es */ { IDS_PRINTER_OUTPUT_FILENAME_SELECT_ES, "Seleccionar fichero de volcado impresion" },
/* fr */ { IDS_PRINTER_OUTPUT_FILENAME_SELECT_FR, "S�lectionnez le fichier de sortie d'imprimante" },
/* hu */ { IDS_PRINTER_OUTPUT_FILENAME_SELECT_HU, "V�lassza ki a nyomtat� kimeneti f�jlt" },
/* it */ { IDS_PRINTER_OUTPUT_FILENAME_SELECT_IT, "Seleziona file su cui stampare" },
/* ko */ { IDS_PRINTER_OUTPUT_FILENAME_SELECT_KO, "������ ���� ������ �����ϼ���" },
/* nl */ { IDS_PRINTER_OUTPUT_FILENAME_SELECT_NL, "Selecteer printerdumpbestand" },
/* pl */ { IDS_PRINTER_OUTPUT_FILENAME_SELECT_PL, "Wybierz plik zrzutu drukarki" },
/* ru */ { IDS_PRINTER_OUTPUT_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_OUTPUT_FILENAME_SELECT_SV, "V�lj utskriftsdumpfil" },
/* tr */ { IDS_PRINTER_OUTPUT_FILENAME_SELECT_TR, "Yaz�c� d�k�m dosyas�n� se�in" },

/* en */ { IDS_PRINTER_4_EMULATION,    "Printer #4 emulation" },
/* da */ { IDS_PRINTER_4_EMULATION_DA, "Printer #4 emulering" },
/* de */ { IDS_PRINTER_4_EMULATION_DE, "Drucker #4 Emulation" },
/* es */ { IDS_PRINTER_4_EMULATION_ES, "Emulaci�n impresora #4" },
/* fr */ { IDS_PRINTER_4_EMULATION_FR, "" },  /* fuzzy */
/* hu */ { IDS_PRINTER_4_EMULATION_HU, "" },  /* fuzzy */
/* it */ { IDS_PRINTER_4_EMULATION_IT, "Emulazione stampante #4" },
/* ko */ { IDS_PRINTER_4_EMULATION_KO, "������ #4 ���ķ��̼�" },
/* nl */ { IDS_PRINTER_4_EMULATION_NL, "Printer #4 emulatie" },
/* pl */ { IDS_PRINTER_4_EMULATION_PL, "Emulacja drukarki #4" },
/* ru */ { IDS_PRINTER_4_EMULATION_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_4_EMULATION_SV, "Skrivaremulering f�r enhet 4" },
/* tr */ { IDS_PRINTER_4_EMULATION_TR, "Yaz�c� #4 em�lasyonu" },

/* en */ { IDS_PRINTER_5_EMULATION,    "Printer #5 emulation" },
/* da */ { IDS_PRINTER_5_EMULATION_DA, "Printer #5 emulering" },
/* de */ { IDS_PRINTER_5_EMULATION_DE, "Drucker #5 Emulation" },
/* es */ { IDS_PRINTER_5_EMULATION_ES, "Emulaci�n impresora #5" },
/* fr */ { IDS_PRINTER_5_EMULATION_FR, "" },  /* fuzzy */
/* hu */ { IDS_PRINTER_5_EMULATION_HU, "" },  /* fuzzy */
/* it */ { IDS_PRINTER_5_EMULATION_IT, "Emulazione stampante #5" },
/* ko */ { IDS_PRINTER_5_EMULATION_KO, "������ #5 ���ķ��̼�" },
/* nl */ { IDS_PRINTER_5_EMULATION_NL, "Printer #5 emulatie" },
/* pl */ { IDS_PRINTER_5_EMULATION_PL, "Emulacja drukarki #5" },
/* ru */ { IDS_PRINTER_5_EMULATION_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_5_EMULATION_SV, "Skrivaremulering f�r enhet 5" },
/* tr */ { IDS_PRINTER_5_EMULATION_TR, "Yaz�c� #5 em�lasyonu" },

/* en */ { IDS_USERPORT_PRINTER_EMULATION,    "Userport printer emulation" },
/* da */ { IDS_USERPORT_PRINTER_EMULATION_DA, "Emulering af printer p� brugerporten" },
/* de */ { IDS_USERPORT_PRINTER_EMULATION_DE, "Userport Drucker Emulation" },
/* es */ { IDS_USERPORT_PRINTER_EMULATION_ES, "Emulaci�n puerto usuario impresora" },
/* fr */ { IDS_USERPORT_PRINTER_EMULATION_FR, "" },  /* fuzzy */
/* hu */ { IDS_USERPORT_PRINTER_EMULATION_HU, "" },  /* fuzzy */
/* it */ { IDS_USERPORT_PRINTER_EMULATION_IT, "Stampante su userport: emulazione" },
/* ko */ { IDS_USERPORT_PRINTER_EMULATION_KO, "������Ʈ ������ ���ķ��̼�" },
/* nl */ { IDS_USERPORT_PRINTER_EMULATION_NL, "Userport printer emulatie" },
/* pl */ { IDS_USERPORT_PRINTER_EMULATION_PL, "Emulacja drukarki w userporcie" },
/* ru */ { IDS_USERPORT_PRINTER_EMULATION_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_PRINTER_EMULATION_SV, "Emulering av skrivare p� anv�ndarporten" },
/* tr */ { IDS_USERPORT_PRINTER_EMULATION_TR, "Userport yaz�c�s� em�lasyonu" },

/* en */ { IDS_PRINTER_4_DRIVER,    "Printer #4 driver" },
/* da */ { IDS_PRINTER_4_DRIVER_DA, "Printer #4 driver" },
/* de */ { IDS_PRINTER_4_DRIVER_DE, "Drucker #4 Treiber" },
/* es */ { IDS_PRINTER_4_DRIVER_ES, "Controlador impresora #4" },
/* fr */ { IDS_PRINTER_4_DRIVER_FR, "" },  /* fuzzy */
/* hu */ { IDS_PRINTER_4_DRIVER_HU, "" },  /* fuzzy */
/* it */ { IDS_PRINTER_4_DRIVER_IT, "Driver stampante #4" },
/* ko */ { IDS_PRINTER_4_DRIVER_KO, "������ #4 ����̹�" },
/* nl */ { IDS_PRINTER_4_DRIVER_NL, "Printer #4 stuurprogramma" },
/* pl */ { IDS_PRINTER_4_DRIVER_PL, "Sterownik drukarki #4" },
/* ru */ { IDS_PRINTER_4_DRIVER_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_4_DRIVER_SV, "Skrivardrivrutin f�r enhet 4" },
/* tr */ { IDS_PRINTER_4_DRIVER_TR, "Yaz�c� #4 s�r�c�s�" },

/* en */ { IDS_PRINTER_5_DRIVER,    "Printer #5 driver" },
/* da */ { IDS_PRINTER_5_DRIVER_DA, "Printer #5 driver" },
/* de */ { IDS_PRINTER_5_DRIVER_DE, "Drucker #5 Treiber" },
/* es */ { IDS_PRINTER_5_DRIVER_ES, "Controlador impresora #5" },
/* fr */ { IDS_PRINTER_5_DRIVER_FR, "" },  /* fuzzy */
/* hu */ { IDS_PRINTER_5_DRIVER_HU, "" },  /* fuzzy */
/* it */ { IDS_PRINTER_5_DRIVER_IT, "Driver stampante #5" },
/* ko */ { IDS_PRINTER_5_DRIVER_KO, "IEC ������ #5 ����̹�" },
/* nl */ { IDS_PRINTER_5_DRIVER_NL, "Printer #5 stuurprogramma" },
/* pl */ { IDS_PRINTER_5_DRIVER_PL, "Sterownik drukarki #5" },
/* ru */ { IDS_PRINTER_5_DRIVER_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_5_DRIVER_SV, "Skrivardrivrutin f�r enhet 5" },
/* tr */ { IDS_PRINTER_5_DRIVER_TR, "Yaz�c� #5 s�r�c�s�" },

/* en */ { IDS_USERPORT_PRINTER_DRIVER,    "Userport printer driver" },
/* da */ { IDS_USERPORT_PRINTER_DRIVER_DA, "Printerdriver for brugerporten" },
/* de */ { IDS_USERPORT_PRINTER_DRIVER_DE, "Userport Drucker Treiber" },
/* es */ { IDS_USERPORT_PRINTER_DRIVER_ES, "controlador puerto usuario" },
/* fr */ { IDS_USERPORT_PRINTER_DRIVER_FR, "Pilote de l'imprimante sur port utilisateur" },
/* hu */ { IDS_USERPORT_PRINTER_DRIVER_HU, "Userport-os nyomtat� meghajt�" },
/* it */ { IDS_USERPORT_PRINTER_DRIVER_IT, "Stampante su userport: driver" },
/* ko */ { IDS_USERPORT_PRINTER_DRIVER_KO, "������Ʈ ������ ����̹�" },
/* nl */ { IDS_USERPORT_PRINTER_DRIVER_NL, "Userport printer stuurprogramma" },
/* pl */ { IDS_USERPORT_PRINTER_DRIVER_PL, "Sterownik drukarki w userporcie" },
/* ru */ { IDS_USERPORT_PRINTER_DRIVER_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_PRINTER_DRIVER_SV, "Skrivardrivrutin f�r anv�ndarporten" },
/* tr */ { IDS_USERPORT_PRINTER_DRIVER_TR, "Userport yaz�c�s� s�r�c�s�" },

/* en */ { IDS_PRINTER_4_OUTPUT_TYPE,    "Printer #4 output type" },
/* da */ { IDS_PRINTER_4_OUTPUT_TYPE_DA, "Printer #4 uddatatype" },
/* de */ { IDS_PRINTER_4_OUTPUT_TYPE_DE, "Drucker #4 Ausgabetyp" },
/* es */ { IDS_PRINTER_4_OUTPUT_TYPE_ES, "Tipo salida impresora #4" },
/* fr */ { IDS_PRINTER_4_OUTPUT_TYPE_FR, "" },  /* fuzzy */
/* hu */ { IDS_PRINTER_4_OUTPUT_TYPE_HU, "" },  /* fuzzy */
/* it */ { IDS_PRINTER_4_OUTPUT_TYPE_IT, "Tipo di output stampante #4" },
/* ko */ { IDS_PRINTER_4_OUTPUT_TYPE_KO, "" },  /* fuzzy */
/* nl */ { IDS_PRINTER_4_OUTPUT_TYPE_NL, "Printer #4 uitvoer soort" },
/* pl */ { IDS_PRINTER_4_OUTPUT_TYPE_PL, "Typ wyj�cia drukarki #4" },
/* ru */ { IDS_PRINTER_4_OUTPUT_TYPE_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_4_OUTPUT_TYPE_SV, "Utdatatyp f�r skrivare 4" },
/* tr */ { IDS_PRINTER_4_OUTPUT_TYPE_TR, "Yaz�c� #4 ��kt� tipi" },

/* en */ { IDS_PRINTER_5_OUTPUT_TYPE,    "Printer #5 output type" },
/* da */ { IDS_PRINTER_5_OUTPUT_TYPE_DA, "Printer #5 uddatatype" },
/* de */ { IDS_PRINTER_5_OUTPUT_TYPE_DE, "Drucker #5 Ausgabetyp" },
/* es */ { IDS_PRINTER_5_OUTPUT_TYPE_ES, "Tipo salida impresora #5" },
/* fr */ { IDS_PRINTER_5_OUTPUT_TYPE_FR, "" },  /* fuzzy */
/* hu */ { IDS_PRINTER_5_OUTPUT_TYPE_HU, "" },  /* fuzzy */
/* it */ { IDS_PRINTER_5_OUTPUT_TYPE_IT, "Tipo di output stampante #5" },
/* ko */ { IDS_PRINTER_5_OUTPUT_TYPE_KO, "" },  /* fuzzy */
/* nl */ { IDS_PRINTER_5_OUTPUT_TYPE_NL, "Printer #5 uitvoer soort" },
/* pl */ { IDS_PRINTER_5_OUTPUT_TYPE_PL, "Typ wyj�cia drukarki #5" },
/* ru */ { IDS_PRINTER_5_OUTPUT_TYPE_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_5_OUTPUT_TYPE_SV, "Utdatatyp f�r skrivare 5" },
/* tr */ { IDS_PRINTER_5_OUTPUT_TYPE_TR, "Yaz�c� #5 ��kt� tipi" },

/* en */ { IDS_USERPORT_PRINTER_OUTPUT_TYPE,    "Userport printer output type" },
/* da */ { IDS_USERPORT_PRINTER_OUTPUT_TYPE_DA, "Printer uddatatype p� brugerporten" },
/* de */ { IDS_USERPORT_PRINTER_OUTPUT_TYPE_DE, "Userport Drucker Ausgabetyp" },
/* es */ { IDS_USERPORT_PRINTER_OUTPUT_TYPE_ES, "Tipo salida puerto impresora" },
/* fr */ { IDS_USERPORT_PRINTER_OUTPUT_TYPE_FR, "" },  /* fuzzy */
/* hu */ { IDS_USERPORT_PRINTER_OUTPUT_TYPE_HU, "" },  /* fuzzy */
/* it */ { IDS_USERPORT_PRINTER_OUTPUT_TYPE_IT, "Tipo di output stampante su userport" },
/* ko */ { IDS_USERPORT_PRINTER_OUTPUT_TYPE_KO, "" },  /* fuzzy */
/* nl */ { IDS_USERPORT_PRINTER_OUTPUT_TYPE_NL, "Userport printer uitvoer soort" },
/* pl */ { IDS_USERPORT_PRINTER_OUTPUT_TYPE_PL, "Typ wyj�cia drukarki w userporcie" },
/* ru */ { IDS_USERPORT_PRINTER_OUTPUT_TYPE_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_PRINTER_OUTPUT_TYPE_SV, "Utdatatyp f�r anv�ndarportskrivare" },
/* tr */ { IDS_USERPORT_PRINTER_OUTPUT_TYPE_TR, "Userport yaz�c�s� ��kt� tipi" },

/* en */ { IDS_PRINTER_4_OUTPUT_DEVICE,    "Printer #4 output device" },
/* da */ { IDS_PRINTER_4_OUTPUT_DEVICE_DA, "Printer #4 uddataenhed" },
/* de */ { IDS_PRINTER_4_OUTPUT_DEVICE_DE, "Drucker #4 Ausgabeger�t" },
/* es */ { IDS_PRINTER_4_OUTPUT_DEVICE_ES, "Perif�rico salida impresoara #4" },
/* fr */ { IDS_PRINTER_4_OUTPUT_DEVICE_FR, "" },  /* fuzzy */
/* hu */ { IDS_PRINTER_4_OUTPUT_DEVICE_HU, "" },  /* fuzzy */
/* it */ { IDS_PRINTER_4_OUTPUT_DEVICE_IT, "Dispositivo di output stampante #4" },
/* ko */ { IDS_PRINTER_4_OUTPUT_DEVICE_KO, "" },  /* fuzzy */
/* nl */ { IDS_PRINTER_4_OUTPUT_DEVICE_NL, "Printer #4 uitvoer apparaat" },
/* pl */ { IDS_PRINTER_4_OUTPUT_DEVICE_PL, "Urz�dzenie wyj�cia drukarki #4" },
/* ru */ { IDS_PRINTER_4_OUTPUT_DEVICE_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_4_OUTPUT_DEVICE_SV, "Textutenhet f�r skrivare 4" },
/* tr */ { IDS_PRINTER_4_OUTPUT_DEVICE_TR, "Yaz�c� #4 ��kt� ayg�t�" },

/* en */ { IDS_PRINTER_5_OUTPUT_DEVICE,    "Printer #5 output device" },
/* da */ { IDS_PRINTER_5_OUTPUT_DEVICE_DA, "Printer #5 uddataenhed" },
/* de */ { IDS_PRINTER_5_OUTPUT_DEVICE_DE, "Drucker #5 Ausgabeger�t" },
/* es */ { IDS_PRINTER_5_OUTPUT_DEVICE_ES, "Perif�rico salida impresoara #5" },
/* fr */ { IDS_PRINTER_5_OUTPUT_DEVICE_FR, "" },  /* fuzzy */
/* hu */ { IDS_PRINTER_5_OUTPUT_DEVICE_HU, "" },  /* fuzzy */
/* it */ { IDS_PRINTER_5_OUTPUT_DEVICE_IT, "Dispositivo di output stampante #5" },
/* ko */ { IDS_PRINTER_5_OUTPUT_DEVICE_KO, "" },  /* fuzzy */
/* nl */ { IDS_PRINTER_5_OUTPUT_DEVICE_NL, "Printer #5 uitvoer apparaat" },
/* pl */ { IDS_PRINTER_5_OUTPUT_DEVICE_PL, "Urz�dzenie wyj�cia drukarki #5" },
/* ru */ { IDS_PRINTER_5_OUTPUT_DEVICE_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_5_OUTPUT_DEVICE_SV, "Textutenhet f�r skrivare 5" },
/* tr */ { IDS_PRINTER_5_OUTPUT_DEVICE_TR, "Yaz�c� #5 ��kt� ayg�t�" },

/* en */ { IDS_USERPORT_PRINTER_OUTPUT_DEVICE,    "Userport printer output device" },
/* da */ { IDS_USERPORT_PRINTER_OUTPUT_DEVICE_DA, "Brugerport printer uddataenhed" },
/* de */ { IDS_USERPORT_PRINTER_OUTPUT_DEVICE_DE, "Userport Drucker Ausgabeger�t" },
/* es */ { IDS_USERPORT_PRINTER_OUTPUT_DEVICE_ES, "Perif�rico salida puerto impresora" },
/* fr */ { IDS_USERPORT_PRINTER_OUTPUT_DEVICE_FR, "" },  /* fuzzy */
/* hu */ { IDS_USERPORT_PRINTER_OUTPUT_DEVICE_HU, "" },  /* fuzzy */
/* it */ { IDS_USERPORT_PRINTER_OUTPUT_DEVICE_IT, "Dispositivo di output stampante su userport" },
/* ko */ { IDS_USERPORT_PRINTER_OUTPUT_DEVICE_KO, "" },  /* fuzzy */
/* nl */ { IDS_USERPORT_PRINTER_OUTPUT_DEVICE_NL, "Userport printer uitvoer apparaat" },
/* pl */ { IDS_USERPORT_PRINTER_OUTPUT_DEVICE_PL, "Urz�dzenie wyj�cia drukarki w userporcie" },
/* ru */ { IDS_USERPORT_PRINTER_OUTPUT_DEVICE_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_PRINTER_OUTPUT_DEVICE_SV, "Textutenhet f�r anv�ndarportskrivare" },
/* tr */ { IDS_USERPORT_PRINTER_OUTPUT_DEVICE_TR, "Userport yaz�c�s� ��kt� ayg�t�" },

/* en */ { IDS_PRINTER_4_SEND_FORMFEED,    "Send formfeed to printer #4" },
/* da */ { IDS_PRINTER_4_SEND_FORMFEED_DA, "Send sideskift til printer #4" },
/* de */ { IDS_PRINTER_4_SEND_FORMFEED_DE, "Seitenvorschub zu Drucker #4 senden" },
/* es */ { IDS_PRINTER_4_SEND_FORMFEED_ES, "Enviar alimentaci�n formulario a impresora #4" },
/* fr */ { IDS_PRINTER_4_SEND_FORMFEED_FR, "" },  /* fuzzy */
/* hu */ { IDS_PRINTER_4_SEND_FORMFEED_HU, "" },  /* fuzzy */
/* it */ { IDS_PRINTER_4_SEND_FORMFEED_IT, "Invia formfeed alla stampante #4" },
/* ko */ { IDS_PRINTER_4_SEND_FORMFEED_KO, "" },  /* fuzzy */
/* nl */ { IDS_PRINTER_4_SEND_FORMFEED_NL, "Zend formfeed naar printer #4" },
/* pl */ { IDS_PRINTER_4_SEND_FORMFEED_PL, "Wy�lij Form Feed do drukarki #4" },
/* ru */ { IDS_PRINTER_4_SEND_FORMFEED_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_4_SEND_FORMFEED_SV, "S�nd sidmatning till skrivare 4" },
/* tr */ { IDS_PRINTER_4_SEND_FORMFEED_TR, "Yaz�c� #4'e sayfa ilerletme g�nder" },

/* en */ { IDS_PRINTER_5_SEND_FORMFEED,    "Send formfeed to printer #5" },
/* da */ { IDS_PRINTER_5_SEND_FORMFEED_DA, "Send sideskift til printer #5" },
/* de */ { IDS_PRINTER_5_SEND_FORMFEED_DE, "Seitenvorschub zu Drucker #5 senden" },
/* es */ { IDS_PRINTER_5_SEND_FORMFEED_ES, "Enviar alimentaci�n formulario a impresora #5" },
/* fr */ { IDS_PRINTER_5_SEND_FORMFEED_FR, "" },  /* fuzzy */
/* hu */ { IDS_PRINTER_5_SEND_FORMFEED_HU, "" },  /* fuzzy */
/* it */ { IDS_PRINTER_5_SEND_FORMFEED_IT, "Invia formfeed alla stampante #5" },
/* ko */ { IDS_PRINTER_5_SEND_FORMFEED_KO, "" },  /* fuzzy */
/* nl */ { IDS_PRINTER_5_SEND_FORMFEED_NL, "Zend formfeed naar printer #5" },
/* pl */ { IDS_PRINTER_5_SEND_FORMFEED_PL, "Wy�lij Form Feed do drukarki #5" },
/* ru */ { IDS_PRINTER_5_SEND_FORMFEED_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_5_SEND_FORMFEED_SV, "S�nd sidmatning till skrivare 5" },
/* tr */ { IDS_PRINTER_5_SEND_FORMFEED_TR, "Yaz�c� #5'e sayfa ilerletme g�nder" },

/* en */ { IDS_USERPORT_PRINTER_SEND_FORMFEED,    "Send formfeed to userport printer" },
/* da */ { IDS_USERPORT_PRINTER_SEND_FORMFEED_DA, "Send sideskift til brugerports-printer" },
/* de */ { IDS_USERPORT_PRINTER_SEND_FORMFEED_DE, "Seitenvorschub zui Userport Drucker senden" },
/* es */ { IDS_USERPORT_PRINTER_SEND_FORMFEED_ES, "Enviar alimentaci�n formulario a puerto impresora" },
/* fr */ { IDS_USERPORT_PRINTER_SEND_FORMFEED_FR, "" },  /* fuzzy */
/* hu */ { IDS_USERPORT_PRINTER_SEND_FORMFEED_HU, "" },  /* fuzzy */
/* it */ { IDS_USERPORT_PRINTER_SEND_FORMFEED_IT, "Invia formfeed alla stampante su userport" },
/* ko */ { IDS_USERPORT_PRINTER_SEND_FORMFEED_KO, "" },  /* fuzzy */
/* nl */ { IDS_USERPORT_PRINTER_SEND_FORMFEED_NL, "Zend formfeed naar userport printer" },
/* pl */ { IDS_USERPORT_PRINTER_SEND_FORMFEED_PL, "Wy�lij Form Feed do drukarki w userporcie" },
/* ru */ { IDS_USERPORT_PRINTER_SEND_FORMFEED_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_PRINTER_SEND_FORMFEED_SV, "S�nd sidmatning till anv�ndarportskrivare" },
/* tr */ { IDS_USERPORT_PRINTER_SEND_FORMFEED_TR, "Userport yaz�c�s�'na sayfa ilerletme g�nder" },

/* en */ { IDS_PRINTER_DEVICE_1_FILENAME,    "Printer device #1 output" },
/* da */ { IDS_PRINTER_DEVICE_1_FILENAME_DA, "Printer enhed #1 uddata" },
/* de */ { IDS_PRINTER_DEVICE_1_FILENAME_DE, "Drucker Ger�t #1 Ausgabe" },
/* es */ { IDS_PRINTER_DEVICE_1_FILENAME_ES, "Perif�rico de salida impresora #1" },
/* fr */ { IDS_PRINTER_DEVICE_1_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_PRINTER_DEVICE_1_FILENAME_HU, "" },  /* fuzzy */
/* it */ { IDS_PRINTER_DEVICE_1_FILENAME_IT, "Output stampante #1..." },
/* ko */ { IDS_PRINTER_DEVICE_1_FILENAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_PRINTER_DEVICE_1_FILENAME_NL, "Printer apparaat #1 uitvoer" },
/* pl */ { IDS_PRINTER_DEVICE_1_FILENAME_PL, "Wyj�cie urz�dzenia drukarki #1" },
/* ru */ { IDS_PRINTER_DEVICE_1_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_DEVICE_1_FILENAME_SV, "Utdata f�r skrivarenhet 1" },
/* tr */ { IDS_PRINTER_DEVICE_1_FILENAME_TR, "Yaz�c� ayg�t� #1 ��kt�s�" },

/* en */ { IDS_PRINTER_DEVICE_2_FILENAME,    "Printer device #2 output" },
/* da */ { IDS_PRINTER_DEVICE_2_FILENAME_DA, "Printer enhed #2 uddata" },
/* de */ { IDS_PRINTER_DEVICE_2_FILENAME_DE, "Drucker Ger�t #2 Ausgabe" },
/* es */ { IDS_PRINTER_DEVICE_2_FILENAME_ES, "Perif�rico de salida impresora #2" },
/* fr */ { IDS_PRINTER_DEVICE_2_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_PRINTER_DEVICE_2_FILENAME_HU, "" },  /* fuzzy */
/* it */ { IDS_PRINTER_DEVICE_2_FILENAME_IT, "Output stampante #2..." },
/* ko */ { IDS_PRINTER_DEVICE_2_FILENAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_PRINTER_DEVICE_2_FILENAME_NL, "Printer apparaat #2 uitvoer" },
/* pl */ { IDS_PRINTER_DEVICE_2_FILENAME_PL, "Wyj�cie urz�dzenia drukarki #2" },
/* ru */ { IDS_PRINTER_DEVICE_2_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_DEVICE_2_FILENAME_SV, "Utdata f�r skrivarenhet 2" },
/* tr */ { IDS_PRINTER_DEVICE_2_FILENAME_TR, "Yaz�c� ayg�t� #2 ��kt�s�" },

/* en */ { IDS_PRINTER_DEVICE_3_FILENAME,    "Printer device #3 output" },
/* da */ { IDS_PRINTER_DEVICE_3_FILENAME_DA, "Printer enhed #3 uddata" },
/* de */ { IDS_PRINTER_DEVICE_3_FILENAME_DE, "Drucker Ger�t #3 Ausgabe" },
/* es */ { IDS_PRINTER_DEVICE_3_FILENAME_ES, "Perif�rico de salida impresora #3" },
/* fr */ { IDS_PRINTER_DEVICE_3_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_PRINTER_DEVICE_3_FILENAME_HU, "" },  /* fuzzy */
/* it */ { IDS_PRINTER_DEVICE_3_FILENAME_IT, "Output stampante #3..." },
/* ko */ { IDS_PRINTER_DEVICE_3_FILENAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_PRINTER_DEVICE_3_FILENAME_NL, "Printer apparaat #3 uitvoer" },
/* pl */ { IDS_PRINTER_DEVICE_3_FILENAME_PL, "Wyj�cie urz�dzenia drukarki #3" },
/* ru */ { IDS_PRINTER_DEVICE_3_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_DEVICE_3_FILENAME_SV, "Utdata f�r skrivarenhet 3" },
/* tr */ { IDS_PRINTER_DEVICE_3_FILENAME_TR, "Yaz�c� ayg�t� #3 ��kt�s�" },

/* en */ { IDS_ENABLE_IEC_PRINTER_4,    "IEC emulation for printer #4" },
/* da */ { IDS_ENABLE_IEC_PRINTER_4_DA, "IEC-emulering for printer #4" },
/* de */ { IDS_ENABLE_IEC_PRINTER_4_DE, "IEC Ger�te Emulation f�r Drucker #4" },
/* es */ { IDS_ENABLE_IEC_PRINTER_4_ES, "Emulaci�n IEC para impresora #4" },
/* fr */ { IDS_ENABLE_IEC_PRINTER_4_FR, "" },  /* fuzzy */
/* hu */ { IDS_ENABLE_IEC_PRINTER_4_HU, "" },  /* fuzzy */
/* it */ { IDS_ENABLE_IEC_PRINTER_4_IT, "Emulazione IEC per la stampante #4" },
/* ko */ { IDS_ENABLE_IEC_PRINTER_4_KO, "" },  /* fuzzy */
/* nl */ { IDS_ENABLE_IEC_PRINTER_4_NL, "IEC emulatie voor apparaat #4" },
/* pl */ { IDS_ENABLE_IEC_PRINTER_4_PL, "Emulacja IEC drukarki #4" },
/* ru */ { IDS_ENABLE_IEC_PRINTER_4_RU, "" },  /* fuzzy */
/* sv */ { IDS_ENABLE_IEC_PRINTER_4_SV, "IEC-emulering f�r skrivare 4" },
/* tr */ { IDS_ENABLE_IEC_PRINTER_4_TR, "Yaz�c� #4 i�in IEC em�lasyonu" },

/* en */ { IDS_ENABLE_IEC_PRINTER_5,    "IEC emulation for printer #5" },
/* da */ { IDS_ENABLE_IEC_PRINTER_5_DA, "IEC-emulering for printer #5" },
/* de */ { IDS_ENABLE_IEC_PRINTER_5_DE, "IEC Ger�te Emulation f�r Drucker #5" },
/* es */ { IDS_ENABLE_IEC_PRINTER_5_ES, "Emulaci�n IEC para impresora #5" },
/* fr */ { IDS_ENABLE_IEC_PRINTER_5_FR, "" },  /* fuzzy */
/* hu */ { IDS_ENABLE_IEC_PRINTER_5_HU, "" },  /* fuzzy */
/* it */ { IDS_ENABLE_IEC_PRINTER_5_IT, "Emulazione IEC per la stampante #5" },
/* ko */ { IDS_ENABLE_IEC_PRINTER_5_KO, "" },  /* fuzzy */
/* nl */ { IDS_ENABLE_IEC_PRINTER_5_NL, "IEC emulatie voor apparaat #5" },
/* pl */ { IDS_ENABLE_IEC_PRINTER_5_PL, "Emulacja IEC drukarki #5" },
/* ru */ { IDS_ENABLE_IEC_PRINTER_5_RU, "" },  /* fuzzy */
/* sv */ { IDS_ENABLE_IEC_PRINTER_5_SV, "IEC-emulering f�r skrivare 5" },
/* tr */ { IDS_ENABLE_IEC_PRINTER_5_TR, "Yaz�c� #5 i�in IEC em�lasyonu" },

/* en */ { IDS_PRINTER_SETTINGS,    "Printer settings" },
/* da */ { IDS_PRINTER_SETTINGS_DA, "Printerindstillinger" },
/* de */ { IDS_PRINTER_SETTINGS_DE, "Drucker Einstellungen" },
/* es */ { IDS_PRINTER_SETTINGS_ES, "Ajustes de impresora" },
/* fr */ { IDS_PRINTER_SETTINGS_FR, "Param�tres d'imprimante" },
/* hu */ { IDS_PRINTER_SETTINGS_HU, "Nyomtat� be�ll�t�sai" },
/* it */ { IDS_PRINTER_SETTINGS_IT, "Impostazioni stampanti" },
/* ko */ { IDS_PRINTER_SETTINGS_KO, "������ ����" },
/* nl */ { IDS_PRINTER_SETTINGS_NL, "Printer instellingen" },
/* pl */ { IDS_PRINTER_SETTINGS_PL, "Ustawienia drukarki" },
/* ru */ { IDS_PRINTER_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_PRINTER_SETTINGS_SV, "Skrivarinst�llningar" },
/* tr */ { IDS_PRINTER_SETTINGS_TR, "Yaz�c� ayarlar�" },

/* en */ { IDS_MAGIC_VOICE_FILENAME,    "Magic Voice file" },
/* da */ { IDS_MAGIC_VOICE_FILENAME_DA, "Magic Voice-fil" },
/* de */ { IDS_MAGIC_VOICE_FILENAME_DE, "Magic Voice Datei" },
/* es */ { IDS_MAGIC_VOICE_FILENAME_ES, "Fichero Magic Voice" },
/* fr */ { IDS_MAGIC_VOICE_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_MAGIC_VOICE_FILENAME_HU, "" },  /* fuzzy */
/* it */ { IDS_MAGIC_VOICE_FILENAME_IT, "File Magic Voice" },
/* ko */ { IDS_MAGIC_VOICE_FILENAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_MAGIC_VOICE_FILENAME_NL, "Magic Voice bestand" },
/* pl */ { IDS_MAGIC_VOICE_FILENAME_PL, "Plik Magic Voice" },
/* ru */ { IDS_MAGIC_VOICE_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_MAGIC_VOICE_FILENAME_SV, "Magic Voice-fil" },
/* tr */ { IDS_MAGIC_VOICE_FILENAME_TR, "Magic Voice dosyas�" },

/* en */ { IDS_MAGIC_VOICE_FILENAME_SELECT,    "Select file for Magic Voice" },
/* da */ { IDS_MAGIC_VOICE_FILENAME_SELECT_DA, "V�lg fil for Magic Voice" },
/* de */ { IDS_MAGIC_VOICE_FILENAME_SELECT_DE, "Datei f�r Magic Voice ausw�hlen" },
/* es */ { IDS_MAGIC_VOICE_FILENAME_SELECT_ES, "Seleccionar fichero para Magic Voice" },
/* fr */ { IDS_MAGIC_VOICE_FILENAME_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_MAGIC_VOICE_FILENAME_SELECT_HU, "" },  /* fuzzy */
/* it */ { IDS_MAGIC_VOICE_FILENAME_SELECT_IT, "Seleziona file per Magic Voice" },
/* ko */ { IDS_MAGIC_VOICE_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_MAGIC_VOICE_FILENAME_SELECT_NL, "Selecteer bestand voor Magic Voice" },
/* pl */ { IDS_MAGIC_VOICE_FILENAME_SELECT_PL, "Wybierz filtr Magic Voice" },
/* ru */ { IDS_MAGIC_VOICE_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_MAGIC_VOICE_FILENAME_SELECT_SV, "V�lj fil f�r Magic Voice" },
/* tr */ { IDS_MAGIC_VOICE_FILENAME_SELECT_TR, "Magic Voice i�in dosya se�in" },

/* en */ { IDS_MAGIC_VOICE_SETTINGS,    "Magic Voice settings" },
/* da */ { IDS_MAGIC_VOICE_SETTINGS_DA, "Magic Voice indstillinger" },
/* de */ { IDS_MAGIC_VOICE_SETTINGS_DE, "Magic Voice Einstellungen" },
/* es */ { IDS_MAGIC_VOICE_SETTINGS_ES, "Ajustes Magic Voice" },
/* fr */ { IDS_MAGIC_VOICE_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_MAGIC_VOICE_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_MAGIC_VOICE_SETTINGS_IT, "Impostazioni Magic Voice" },
/* ko */ { IDS_MAGIC_VOICE_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_MAGIC_VOICE_SETTINGS_NL, "Magic Voice instellingen" },
/* pl */ { IDS_MAGIC_VOICE_SETTINGS_PL, "Ustawienia Magic Voice" },
/* ru */ { IDS_MAGIC_VOICE_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_MAGIC_VOICE_SETTINGS_SV, "Magic Voice-inst�llningar" },
/* tr */ { IDS_MAGIC_VOICE_SETTINGS_TR, "Magic Voice ayarlar�" },

/* en */ { IDS_USERPORT_RS232,    "Userport RS232" },
/* da */ { IDS_USERPORT_RS232_DA, "Brugerport RS232" },
/* de */ { IDS_USERPORT_RS232_DE, "Userport RS232" },
/* es */ { IDS_USERPORT_RS232_ES, "Puerto RS232" },
/* fr */ { IDS_USERPORT_RS232_FR, "" },  /* fuzzy */
/* hu */ { IDS_USERPORT_RS232_HU, "Userport RS232" },
/* it */ { IDS_USERPORT_RS232_IT, "Userport RS232" },
/* ko */ { IDS_USERPORT_RS232_KO, "" },  /* fuzzy */
/* nl */ { IDS_USERPORT_RS232_NL, "Userport RS232" },
/* pl */ { IDS_USERPORT_RS232_PL, "Userport RS232" },
/* ru */ { IDS_USERPORT_RS232_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_RS232_SV, "Anv�ndarport-RS232" },
/* tr */ { IDS_USERPORT_RS232_TR, "Userport RS232" },

/* en */ { IDS_USERPORT_DEVICE,    "Userport RS232 device" },
/* da */ { IDS_USERPORT_DEVICE_DA, "Brugerportens RS232-enhed" },
/* de */ { IDS_USERPORT_DEVICE_DE, "Userport RS232 Ger�t" },
/* es */ { IDS_USERPORT_DEVICE_ES, "Perif�rico puerto RS232" },
/* fr */ { IDS_USERPORT_DEVICE_FR, "P�riph�rique de port utilisateur RS232" },
/* hu */ { IDS_USERPORT_DEVICE_HU, "Userport RS232 eszk�z" },
/* it */ { IDS_USERPORT_DEVICE_IT, "Dispositivo RS232 su userport" },
/* ko */ { IDS_USERPORT_DEVICE_KO, "" },  /* fuzzy */
/* nl */ { IDS_USERPORT_DEVICE_NL, "Userport RS232 apparaat" },
/* pl */ { IDS_USERPORT_DEVICE_PL, "Urz�dzenie userportu RS232" },
/* ru */ { IDS_USERPORT_DEVICE_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_DEVICE_SV, "Anv�ndarportens RS232-enhet" },
/* tr */ { IDS_USERPORT_DEVICE_TR, "Userport RS232 ayg�t�" },

/* en */ { IDS_USERPORT_BAUD_RATE,    "Userport RS232 baud rate" },
/* da */ { IDS_USERPORT_BAUD_RATE_DA, "Brugerportens RS232-baudhastighet" },
/* de */ { IDS_USERPORT_BAUD_RATE_DE, "Userport RS232 Baud Rate" },
/* es */ { IDS_USERPORT_BAUD_RATE_ES, "Velocidad (baudios) puerto RS232" },
/* fr */ { IDS_USERPORT_BAUD_RATE_FR, "P�riph�rique de port utilisateur RS232" },
/* hu */ { IDS_USERPORT_BAUD_RATE_HU, "Userport RS232 �tviteli r�ta" },
/* it */ { IDS_USERPORT_BAUD_RATE_IT, "Velocit� RS232 su userport" },
/* ko */ { IDS_USERPORT_BAUD_RATE_KO, "" },  /* fuzzy */
/* nl */ { IDS_USERPORT_BAUD_RATE_NL, "Userport RS232 baudrate" },
/* pl */ { IDS_USERPORT_BAUD_RATE_PL, "Szybko�� transmisji userportu RS232" },
/* ru */ { IDS_USERPORT_BAUD_RATE_RU, "" },  /* fuzzy */
/* sv */ { IDS_USERPORT_BAUD_RATE_SV, "Anv�ndarportens RS232-baudhastighet" },
/* tr */ { IDS_USERPORT_BAUD_RATE_TR, "Userport RS232 baud rate" },

/* en */ { IDS_RS232_USERPORT_SETTINGS,    "RS232 userport settings" },
/* da */ { IDS_RS232_USERPORT_SETTINGS_DA, "RS232-brugerportindstillinger" },
/* de */ { IDS_RS232_USERPORT_SETTINGS_DE, "RS232 Userport Einstellungen" },
/* es */ { IDS_RS232_USERPORT_SETTINGS_ES, "Ajustes puerto RS232" },
/* fr */ { IDS_RS232_USERPORT_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_RS232_USERPORT_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_RS232_USERPORT_SETTINGS_IT, "Impostazioni RS232 su userport" },
/* ko */ { IDS_RS232_USERPORT_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_RS232_USERPORT_SETTINGS_NL, "RS232 userport instellingen" },
/* pl */ { IDS_RS232_USERPORT_SETTINGS_PL, "Ustawienia userportu RS232" },
/* ru */ { IDS_RS232_USERPORT_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_RS232_USERPORT_SETTINGS_SV, "RS232-anv�ndarportinst�llningar" },
/* tr */ { IDS_RS232_USERPORT_SETTINGS_TR, "RS232 userport ayarlar�" },

/* en */ { IDS_FAST,    "Fast" },
/* da */ { IDS_FAST_DA, "Hurtig" },
/* de */ { IDS_FAST_DE, "Schnell" },
/* es */ { IDS_FAST_ES, "R�pido" },
/* fr */ { IDS_FAST_FR, "" },  /* fuzzy */
/* hu */ { IDS_FAST_HU, "" },  /* fuzzy */
/* it */ { IDS_FAST_IT, "Veloce" },
/* ko */ { IDS_FAST_KO, "����" },
/* nl */ { IDS_FAST_NL, "Snel" },
/* pl */ { IDS_FAST_PL, "Szybko" },
/* ru */ { IDS_FAST_RU, "" },  /* fuzzy */
/* sv */ { IDS_FAST_SV, "Snabbt" },
/* tr */ { IDS_FAST_TR, "H�zl�" },

/* en */ { IDS_INTERPOLATING,    "Interpolating" },
/* da */ { IDS_INTERPOLATING_DA, "Interpolerende" },
/* de */ { IDS_INTERPOLATING_DE, "Interpolierend" },
/* es */ { IDS_INTERPOLATING_ES, "Interpolando" },
/* fr */ { IDS_INTERPOLATING_FR, "" },  /* fuzzy */
/* hu */ { IDS_INTERPOLATING_HU, "" },  /* fuzzy */
/* it */ { IDS_INTERPOLATING_IT, "Interpolazione" },
/* ko */ { IDS_INTERPOLATING_KO, "�����ϴ�" },
/* nl */ { IDS_INTERPOLATING_NL, "Interpoleren" },
/* pl */ { IDS_INTERPOLATING_PL, "Interpolacja" },
/* ru */ { IDS_INTERPOLATING_RU, "" },  /* fuzzy */
/* sv */ { IDS_INTERPOLATING_SV, "Interpolerande" },
/* tr */ { IDS_INTERPOLATING_TR, "Ara de�er bulma" },

/* en */ { IDS_RESAMPLING,    "Resampling" },
/* da */ { IDS_RESAMPLING_DA, "Resampling" },
/* de */ { IDS_RESAMPLING_DE, "Resampling" },
/* es */ { IDS_RESAMPLING_ES, "Remuestreo" },
/* fr */ { IDS_RESAMPLING_FR, "" },  /* fuzzy */
/* hu */ { IDS_RESAMPLING_HU, "" },  /* fuzzy */
/* it */ { IDS_RESAMPLING_IT, "Ricampionamento" },
/* ko */ { IDS_RESAMPLING_KO, "�����ø�" },
/* nl */ { IDS_RESAMPLING_NL, "Resampling" },
/* pl */ { IDS_RESAMPLING_PL, "Przesamplowanie" },
/* ru */ { IDS_RESAMPLING_RU, "" },  /* fuzzy */
/* sv */ { IDS_RESAMPLING_SV, "Omsamplande" },
/* tr */ { IDS_RESAMPLING_TR, "Yeniden �rnekleme" },

/* en */ { IDS_FAST_RESAMPLING,    "Fast resampling" },
/* da */ { IDS_FAST_RESAMPLING_DA, "Hurtig omsampling" },
/* de */ { IDS_FAST_RESAMPLING_DE, "Schnelles Resampling" },
/* es */ { IDS_FAST_RESAMPLING_ES, "Remuestreo r�pido" },
/* fr */ { IDS_FAST_RESAMPLING_FR, "" },  /* fuzzy */
/* hu */ { IDS_FAST_RESAMPLING_HU, "" },  /* fuzzy */
/* it */ { IDS_FAST_RESAMPLING_IT, "Ricampionamento veloce" },
/* ko */ { IDS_FAST_RESAMPLING_KO, "���� ������" },
/* nl */ { IDS_FAST_RESAMPLING_NL, "Snelle resampling" },
/* pl */ { IDS_FAST_RESAMPLING_PL, "Szybkie przesamplowanie" },
/* ru */ { IDS_FAST_RESAMPLING_RU, "" },  /* fuzzy */
/* sv */ { IDS_FAST_RESAMPLING_SV, "Snabb omsampling" },
/* tr */ { IDS_FAST_RESAMPLING_TR, "H�zl� yeniden �rnekleme" },

/* en */ { IDS_SID_STEREO,    "SID Stereo" },
/* da */ { IDS_SID_STEREO_DA, "SID-stereo" },
/* de */ { IDS_SID_STEREO_DE, "SID Stereo" },
/* es */ { IDS_SID_STEREO_ES, "SID estereo" },
/* fr */ { IDS_SID_STEREO_FR, "SID St�r�o" },
/* hu */ { IDS_SID_STEREO_HU, "SID sztere�" },
/* it */ { IDS_SID_STEREO_IT, "Stereo SID" },
/* ko */ { IDS_SID_STEREO_KO, "" },  /* fuzzy */
/* nl */ { IDS_SID_STEREO_NL, "Stereo SID" },
/* pl */ { IDS_SID_STEREO_PL, "Stereo SID" },
/* ru */ { IDS_SID_STEREO_RU, "" },  /* fuzzy */
/* sv */ { IDS_SID_STEREO_SV, "SID-stereo" },
/* tr */ { IDS_SID_STEREO_TR, "Stereo SID" },

/* en */ { IDS_STEREO_SID_AT,    "Stereo SID at" },
/* da */ { IDS_STEREO_SID_AT_DA, "Stereo-SID p�" },
/* de */ { IDS_STEREO_SID_AT_DE, "Stereo SID bei" },
/* es */ { IDS_STEREO_SID_AT_ES, "SID estereo en" },
/* fr */ { IDS_STEREO_SID_AT_FR, "SID St�r�o �" },
/* hu */ { IDS_STEREO_SID_AT_HU, "Sztere� SID itt:" },
/* it */ { IDS_STEREO_SID_AT_IT, "Stereo SID a" },
/* ko */ { IDS_STEREO_SID_AT_KO, "" },  /* fuzzy */
/* nl */ { IDS_STEREO_SID_AT_NL, "Stereo SID op" },
/* pl */ { IDS_STEREO_SID_AT_PL, "SID stereo w" },
/* ru */ { IDS_STEREO_SID_AT_RU, "" },  /* fuzzy */
/* sv */ { IDS_STEREO_SID_AT_SV, "Stereo-SID p�" },
/* tr */ { IDS_STEREO_SID_AT_TR, "Stereo SID konumu" },

/* en */ { IDS_SID_FILTERS,    "SID filters" },
/* da */ { IDS_SID_FILTERS_DA, "SID-filtre" },
/* de */ { IDS_SID_FILTERS_DE, "SID Filter" },
/* es */ { IDS_SID_FILTERS_ES, "Filtros SID" },
/* fr */ { IDS_SID_FILTERS_FR, "" },  /* fuzzy */
/* hu */ { IDS_SID_FILTERS_HU, "" },  /* fuzzy */
/* it */ { IDS_SID_FILTERS_IT, "Filtri SID" },
/* ko */ { IDS_SID_FILTERS_KO, "SID ����" },
/* nl */ { IDS_SID_FILTERS_NL, "SID filters" },
/* pl */ { IDS_SID_FILTERS_PL, "Filtry SID" },
/* ru */ { IDS_SID_FILTERS_RU, "" },  /* fuzzy */
/* sv */ { IDS_SID_FILTERS_SV, "SID-filter" },
/* tr */ { IDS_SID_FILTERS_TR, "SID filtreleri" },

/* en */ { IDS_SAMPLE_METHOD,    "Sample method" },
/* da */ { IDS_SAMPLE_METHOD_DA, "Samplingmetode" },
/* de */ { IDS_SAMPLE_METHOD_DE, "Sample Methode" },
/* es */ { IDS_SAMPLE_METHOD_ES, "M�todo de muestreo" },
/* fr */ { IDS_SAMPLE_METHOD_FR, "M�thode d'�chantillonnage" },
/* hu */ { IDS_SAMPLE_METHOD_HU, "Mintav�telez�s m�dja" },
/* it */ { IDS_SAMPLE_METHOD_IT, "Metodo di campionamento" },
/* ko */ { IDS_SAMPLE_METHOD_KO, "" },  /* fuzzy */
/* nl */ { IDS_SAMPLE_METHOD_NL, "Sample methode" },
/* pl */ { IDS_SAMPLE_METHOD_PL, "Metoda samplowania" },
/* ru */ { IDS_SAMPLE_METHOD_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAMPLE_METHOD_SV, "Samplingsmetod" },
/* tr */ { IDS_SAMPLE_METHOD_TR, "�rnekleme metodu" },

/* en */ { IDS_PASSBAND_0_90,    "Passband (0..90%)" },
/* da */ { IDS_PASSBAND_0_90_DA, "" },  /* fuzzy */
/* de */ { IDS_PASSBAND_0_90_DE, "Passband (0..90%)" },
/* es */ { IDS_PASSBAND_0_90_ES, "Pasabanda (0..90%)" },
/* fr */ { IDS_PASSBAND_0_90_FR, "" },  /* fuzzy */
/* hu */ { IDS_PASSBAND_0_90_HU, "" },  /* fuzzy */
/* it */ { IDS_PASSBAND_0_90_IT, "" },  /* fuzzy */
/* ko */ { IDS_PASSBAND_0_90_KO, "" },  /* fuzzy */
/* nl */ { IDS_PASSBAND_0_90_NL, "Passband (0..90%)" },
/* pl */ { IDS_PASSBAND_0_90_PL, "Pasmo przepuszczania (0..90%)" },
/* ru */ { IDS_PASSBAND_0_90_RU, "" },  /* fuzzy */
/* sv */ { IDS_PASSBAND_0_90_SV, "Passband (0..90%)" },
/* tr */ { IDS_PASSBAND_0_90_TR, "" },  /* fuzzy */

/* en */ { IDS_NOT_IMPLEMENTED_YET,    "Not implemented yet!" },
/* da */ { IDS_NOT_IMPLEMENTED_YET_DA, "Ikke implementeret endnu!" },
/* de */ { IDS_NOT_IMPLEMENTED_YET_DE, "Noch nicht implementiert!" },
/* es */ { IDS_NOT_IMPLEMENTED_YET_ES, "�No implementado a�n!" },
/* fr */ { IDS_NOT_IMPLEMENTED_YET_FR, "Pas encore impl�ment�!" },
/* hu */ { IDS_NOT_IMPLEMENTED_YET_HU, "M�g nem implement�lt!" },
/* it */ { IDS_NOT_IMPLEMENTED_YET_IT, "Non ancora implementato!" },
/* ko */ { IDS_NOT_IMPLEMENTED_YET_KO, "" },  /* fuzzy */
/* nl */ { IDS_NOT_IMPLEMENTED_YET_NL, "Nog niet ondersteund!" },
/* pl */ { IDS_NOT_IMPLEMENTED_YET_PL, "Jeszcze nie zaimplementowano!" },
/* ru */ { IDS_NOT_IMPLEMENTED_YET_RU, "" },  /* fuzzy */
/* sv */ { IDS_NOT_IMPLEMENTED_YET_SV, "Ej implementerat �nnu!" },
/* tr */ { IDS_NOT_IMPLEMENTED_YET_TR, "Hen�z tamamlanmad�!" },

/* en */ { IDS_SID_SETTINGS,    "SID settings" },
/* da */ { IDS_SID_SETTINGS_DA, "SID-indstillinger" },
/* de */ { IDS_SID_SETTINGS_DE, "SID Einstellungen" },
/* es */ { IDS_SID_SETTINGS_ES, "Ajustes SID" },
/* fr */ { IDS_SID_SETTINGS_FR, "Param�tres SID" },
/* hu */ { IDS_SID_SETTINGS_HU, "SID be�ll�t�sai" },
/* it */ { IDS_SID_SETTINGS_IT, "Impostazioni SID" },
/* ko */ { IDS_SID_SETTINGS_KO, "SID ����" },
/* nl */ { IDS_SID_SETTINGS_NL, "SID instellingen" },
/* pl */ { IDS_SID_SETTINGS_PL, "Ustawienia SID" },
/* ru */ { IDS_SID_SETTINGS_RU, "��������� SID" },
/* sv */ { IDS_SID_SETTINGS_SV, "SID-inst�llningar" },
/* tr */ { IDS_SID_SETTINGS_TR, "SID ayarlar�" },

/* en */ { IDS_FLEXIBLE,    "Flexible" },
/* da */ { IDS_FLEXIBLE_DA, "Fleksibel" },
/* de */ { IDS_FLEXIBLE_DE, "Flexibel" },
/* es */ { IDS_FLEXIBLE_ES, "Flexible" },
/* fr */ { IDS_FLEXIBLE_FR, "Flexible" },
/* hu */ { IDS_FLEXIBLE_HU, "Rugalmas" },
/* it */ { IDS_FLEXIBLE_IT, "Flessibile" },
/* ko */ { IDS_FLEXIBLE_KO, "������" },
/* nl */ { IDS_FLEXIBLE_NL, "Flexibel" },
/* pl */ { IDS_FLEXIBLE_PL, "Elastyczna" },
/* ru */ { IDS_FLEXIBLE_RU, "" },  /* fuzzy */
/* sv */ { IDS_FLEXIBLE_SV, "Flexibel" },
/* tr */ { IDS_FLEXIBLE_TR, "Esnek" },

/* en */ { IDS_ADJUSTING,    "Adjusting" },
/* da */ { IDS_ADJUSTING_DA, "Tilpassende" },
/* de */ { IDS_ADJUSTING_DE, "Anpassend" },
/* es */ { IDS_ADJUSTING_ES, "Ajustado" },
/* fr */ { IDS_ADJUSTING_FR, "Ajust�" },
/* hu */ { IDS_ADJUSTING_HU, "Igazod�" },
/* it */ { IDS_ADJUSTING_IT, "Adattabile" },
/* ko */ { IDS_ADJUSTING_KO, "����" },
/* nl */ { IDS_ADJUSTING_NL, "Aanpassend" },
/* pl */ { IDS_ADJUSTING_PL, "Dopasowana" },
/* ru */ { IDS_ADJUSTING_RU, "" },  /* fuzzy */
/* sv */ { IDS_ADJUSTING_SV, "Anpassande" },
/* tr */ { IDS_ADJUSTING_TR, "D�zeltme" },

/* en */ { IDS_EXACT,    "Exact" },
/* da */ { IDS_EXACT_DA, "N�jagtig" },
/* de */ { IDS_EXACT_DE, "Exakt" },
/* es */ { IDS_EXACT_ES, "Exacto" },
/* fr */ { IDS_EXACT_FR, "Exact" },
/* hu */ { IDS_EXACT_HU, "Pontos" },
/* it */ { IDS_EXACT_IT, "Esatta" },
/* ko */ { IDS_EXACT_KO, "��Ȯ��" },
/* nl */ { IDS_EXACT_NL, "Exact" },
/* pl */ { IDS_EXACT_PL, "Dok�adna" },
/* ru */ { IDS_EXACT_RU, "" },  /* fuzzy */
/* sv */ { IDS_EXACT_SV, "Exakt" },
/* tr */ { IDS_EXACT_TR, "Aynen" },

/* en */ { IDS_SAMPLE_RATE,    "Sample rate" },
/* da */ { IDS_SAMPLE_RATE_DA, "Samplingfrekvens" },
/* de */ { IDS_SAMPLE_RATE_DE, "Sample Rate" },
/* es */ { IDS_SAMPLE_RATE_ES, "Velocidad de sampleado" },
/* fr */ { IDS_SAMPLE_RATE_FR, "Taux d'�chantillonage" },
/* hu */ { IDS_SAMPLE_RATE_HU, "Mintav�telez�si r�ta" },
/* it */ { IDS_SAMPLE_RATE_IT, "Frequenza di campionamento" },
/* ko */ { IDS_SAMPLE_RATE_KO, "���� ����Ʈ" },
/* nl */ { IDS_SAMPLE_RATE_NL, "Sample snelheid" },
/* pl */ { IDS_SAMPLE_RATE_PL, "Pr�bkowanie" },
/* ru */ { IDS_SAMPLE_RATE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAMPLE_RATE_SV, "Samplingshastighet" },
/* tr */ { IDS_SAMPLE_RATE_TR, "�rnek h�z�" },

/* en */ { IDS_BUFFER_SIZE,    "Buffer size" },
/* da */ { IDS_BUFFER_SIZE_DA, "Bufferst�rrelse" },
/* de */ { IDS_BUFFER_SIZE_DE, "Puffergr��e" },
/* es */ { IDS_BUFFER_SIZE_ES, "Tama�o del buffer" },
/* fr */ { IDS_BUFFER_SIZE_FR, "Taille du tampon" },
/* hu */ { IDS_BUFFER_SIZE_HU, "Puffer m�ret" },
/* it */ { IDS_BUFFER_SIZE_IT, "Dimensione buffer" },
/* ko */ { IDS_BUFFER_SIZE_KO, "���� ������" },
/* nl */ { IDS_BUFFER_SIZE_NL, "Buffergrootte" },
/* pl */ { IDS_BUFFER_SIZE_PL, "Rozmiar buffora" },
/* ru */ { IDS_BUFFER_SIZE_RU, "" },  /* fuzzy */
/* sv */ { IDS_BUFFER_SIZE_SV, "Buffertstorlek" },
/* tr */ { IDS_BUFFER_SIZE_TR, "Arabellek boyutu" },

/* en */ { IDS_FRAGMENT_SIZE,    "Fragment size" },
/* da */ { IDS_FRAGMENT_SIZE_DA, "Fragmentst�rrelse" },
/* de */ { IDS_FRAGMENT_SIZE_DE, "Fragmentgr��e" },
/* es */ { IDS_FRAGMENT_SIZE_ES, "Tama�o de fragmento" },
/* fr */ { IDS_FRAGMENT_SIZE_FR, "" },  /* fuzzy */
/* hu */ { IDS_FRAGMENT_SIZE_HU, "T�red�k m�rete" },
/* it */ { IDS_FRAGMENT_SIZE_IT, "Dimensione frammento" },
/* ko */ { IDS_FRAGMENT_SIZE_KO, "" },  /* fuzzy */
/* nl */ { IDS_FRAGMENT_SIZE_NL, "Fragment grootte" },
/* pl */ { IDS_FRAGMENT_SIZE_PL, "Rozmiar fragmentu" },
/* ru */ { IDS_FRAGMENT_SIZE_RU, "" },  /* fuzzy */
/* sv */ { IDS_FRAGMENT_SIZE_SV, "Fragmentstorlek" },
/* tr */ { IDS_FRAGMENT_SIZE_TR, "Par�a boyutu" },

/* en */ { IDS_SPEED_ADJUSTMENT,    "Speed Adjustment" },
/* da */ { IDS_SPEED_ADJUSTMENT_DA, "Hastighedsjustering" },
/* de */ { IDS_SPEED_ADJUSTMENT_DE, "Geschwindigkeitsanpassung" },
/* es */ { IDS_SPEED_ADJUSTMENT_ES, "Ajuste velocidad" },
/* fr */ { IDS_SPEED_ADJUSTMENT_FR, "Ajustement de vitesse" },
/* hu */ { IDS_SPEED_ADJUSTMENT_HU, "Sebess�g be�ll�t�s" },
/* it */ { IDS_SPEED_ADJUSTMENT_IT, "Variazione velocit�" },
/* ko */ { IDS_SPEED_ADJUSTMENT_KO, "" },  /* fuzzy */
/* nl */ { IDS_SPEED_ADJUSTMENT_NL, "Snelheidsaanpassing" },
/* pl */ { IDS_SPEED_ADJUSTMENT_PL, "Regulacja pr�dko�ci" },
/* ru */ { IDS_SPEED_ADJUSTMENT_RU, "" },  /* fuzzy */
/* sv */ { IDS_SPEED_ADJUSTMENT_SV, "Hastighetsjusering" },
/* tr */ { IDS_SPEED_ADJUSTMENT_TR, "H�z Ayarlamas�" },

/* en */ { IDS_SOUND_SETTINGS,    "Sound settings" },
/* da */ { IDS_SOUND_SETTINGS_DA, "Lydindstillinger" },
/* de */ { IDS_SOUND_SETTINGS_DE, "Sound Einstellungen" },
/* es */ { IDS_SOUND_SETTINGS_ES, "Ajustes de sonido" },
/* fr */ { IDS_SOUND_SETTINGS_FR, "Param�tres son" },
/* hu */ { IDS_SOUND_SETTINGS_HU, "Hang be�ll�t�sai" },
/* it */ { IDS_SOUND_SETTINGS_IT, "Impostazioni audio" },
/* ko */ { IDS_SOUND_SETTINGS_KO, "�Ҹ� ����" },
/* nl */ { IDS_SOUND_SETTINGS_NL, "Geluidsinstellingen" },
/* pl */ { IDS_SOUND_SETTINGS_PL, "Ustawienia d�wi�ku" },
/* ru */ { IDS_SOUND_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_SOUND_SETTINGS_SV, "Ljudinst�llningar" },
/* tr */ { IDS_SOUND_SETTINGS_TR, "Ses ayarlar�" },

/* en */ { IDS_VIC_SETTINGS,    "VIC settings" },
/* da */ { IDS_VIC_SETTINGS_DA, "VIC-indstillinger" },
/* de */ { IDS_VIC_SETTINGS_DE, "VIC Einstellungen" },
/* es */ { IDS_VIC_SETTINGS_ES, "Ajustes VIC" },
/* fr */ { IDS_VIC_SETTINGS_FR, "Param�tres VIC" },
/* hu */ { IDS_VIC_SETTINGS_HU, "VIC be�ll�t�sai" },
/* it */ { IDS_VIC_SETTINGS_IT, "Impostazioni VIC" },
/* ko */ { IDS_VIC_SETTINGS_KO, "VIC ����" },
/* nl */ { IDS_VIC_SETTINGS_NL, "VIC instellingen" },
/* pl */ { IDS_VIC_SETTINGS_PL, "Ustawienia VIC" },
/* ru */ { IDS_VIC_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_VIC_SETTINGS_SV, "VIC-inst�llningar" },
/* tr */ { IDS_VIC_SETTINGS_TR, "VIC ayarlar�" },

/* en */ { IDS_SPRITE_SPRITE_COL,    "Sprite-sprite collisions" },
/* da */ { IDS_SPRITE_SPRITE_COL_DA, "Sprite-til-sprite-kollision" },
/* de */ { IDS_SPRITE_SPRITE_COL_DE, "Sprite-sprite Kollisionen" },
/* es */ { IDS_SPRITE_SPRITE_COL_ES, "Colisiones sprite-sprite" },
/* fr */ { IDS_SPRITE_SPRITE_COL_FR, "" },  /* fuzzy */
/* hu */ { IDS_SPRITE_SPRITE_COL_HU, "" },  /* fuzzy */
/* it */ { IDS_SPRITE_SPRITE_COL_IT, "Collisioni sprite-sprite" },
/* ko */ { IDS_SPRITE_SPRITE_COL_KO, "��������Ʈ-��������Ʈ �浹" },
/* nl */ { IDS_SPRITE_SPRITE_COL_NL, "Sprite-sprite botsingen" },
/* pl */ { IDS_SPRITE_SPRITE_COL_PL, "Kolizje duszk�w" },
/* ru */ { IDS_SPRITE_SPRITE_COL_RU, "" },  /* fuzzy */
/* sv */ { IDS_SPRITE_SPRITE_COL_SV, "Sprite-till-sprite-kollision" },
/* tr */ { IDS_SPRITE_SPRITE_COL_TR, "Yart�k-yarat�k �arp��malar�" },

/* en */ { IDS_SPRITE_BACKGROUND_COL,    "Sprite-background collisions" },
/* da */ { IDS_SPRITE_BACKGROUND_COL_DA, "Sprite-til-baggrunds-kollision" },
/* de */ { IDS_SPRITE_BACKGROUND_COL_DE, "Sprite-Hintergrund Kollisionen" },
/* es */ { IDS_SPRITE_BACKGROUND_COL_ES, "Colisiones sprite-fondo" },
/* fr */ { IDS_SPRITE_BACKGROUND_COL_FR, "" },  /* fuzzy */
/* hu */ { IDS_SPRITE_BACKGROUND_COL_HU, "" },  /* fuzzy */
/* it */ { IDS_SPRITE_BACKGROUND_COL_IT, "Collisioni sprite-sfondo" },
/* ko */ { IDS_SPRITE_BACKGROUND_COL_KO, "��������Ʈ-��� �浹" },
/* nl */ { IDS_SPRITE_BACKGROUND_COL_NL, "Sprite-achtergrond botsingen" },
/* pl */ { IDS_SPRITE_BACKGROUND_COL_PL, "Kolizje duszk�w z t�em" },
/* ru */ { IDS_SPRITE_BACKGROUND_COL_RU, "" },  /* fuzzy */
/* sv */ { IDS_SPRITE_BACKGROUND_COL_SV, "Sprite-till-bakgrund-kollision" },
/* tr */ { IDS_SPRITE_BACKGROUND_COL_TR, "Yarat�k-arkaplan �arp��malar�" },

/* en */ { IDS_NEW_LUMINANCES,    "New luminances" },
/* da */ { IDS_NEW_LUMINANCES_DA, "Nye lysstyrker" },
/* de */ { IDS_NEW_LUMINANCES_DE, "Neue Helligkeitsemulation" },
/* es */ { IDS_NEW_LUMINANCES_ES, "Nuevas luminancias" },
/* fr */ { IDS_NEW_LUMINANCES_FR, "" },  /* fuzzy */
/* hu */ { IDS_NEW_LUMINANCES_HU, "" },  /* fuzzy */
/* it */ { IDS_NEW_LUMINANCES_IT, "Nuove luminanze" },
/* ko */ { IDS_NEW_LUMINANCES_KO, "���ο� ���" },
/* nl */ { IDS_NEW_LUMINANCES_NL, "Nieuwe kleuren" },
/* pl */ { IDS_NEW_LUMINANCES_PL, "Nowy typ jaskrawo�ci" },
/* ru */ { IDS_NEW_LUMINANCES_RU, "" },  /* fuzzy */
/* sv */ { IDS_NEW_LUMINANCES_SV, "Nya ljusstyrkor" },
/* tr */ { IDS_NEW_LUMINANCES_TR, "Yeni parlakl�klar" },

/* en */ { IDS_VICII_SETTINGS,    "VIC-II settings" },
/* da */ { IDS_VICII_SETTINGS_DA, "VIC-II-indstillinger" },
/* de */ { IDS_VICII_SETTINGS_DE, "VIC-II Einstellungen" },
/* es */ { IDS_VICII_SETTINGS_ES, "Ajuester VIC-II" },
/* fr */ { IDS_VICII_SETTINGS_FR, "Param�tres VIC-II" },
/* hu */ { IDS_VICII_SETTINGS_HU, "VIC-II be�ll�t�sai" },
/* it */ { IDS_VICII_SETTINGS_IT, "Impostazioni VIC-II" },
/* ko */ { IDS_VICII_SETTINGS_KO, "VIC-II ����" },
/* nl */ { IDS_VICII_SETTINGS_NL, "VIC-II instellingen" },
/* pl */ { IDS_VICII_SETTINGS_PL, "Ustawienia VIC-II" },
/* ru */ { IDS_VICII_SETTINGS_RU, "��������� VIC-II" },
/* sv */ { IDS_VICII_SETTINGS_SV, "VIC-II-inst�llningar" },
/* tr */ { IDS_VICII_SETTINGS_TR, "VIC-II ayarlar�" },

/* en */ { IDS_ATTACH_TAPE_IMAGE,    "Attach tape image" },
/* da */ { IDS_ATTACH_TAPE_IMAGE_DA, "Tilslut b�nd-image" },
/* de */ { IDS_ATTACH_TAPE_IMAGE_DE, "Band Image einlegen" },
/* es */ { IDS_ATTACH_TAPE_IMAGE_ES, "Insertar imagen de cinta" },
/* fr */ { IDS_ATTACH_TAPE_IMAGE_FR, "Ins�rer une image de datassette" },
/* hu */ { IDS_ATTACH_TAPE_IMAGE_HU, "Szalag k�pm�s csatol�sa" },
/* it */ { IDS_ATTACH_TAPE_IMAGE_IT, "Seleziona immagine cassetta" },
/* ko */ { IDS_ATTACH_TAPE_IMAGE_KO, "������ �̹��� �ٿ��ֱ�" },
/* nl */ { IDS_ATTACH_TAPE_IMAGE_NL, "Koppel tapebestand aan" },
/* pl */ { IDS_ATTACH_TAPE_IMAGE_PL, "Zamontuj obraz ta�my" },
/* ru */ { IDS_ATTACH_TAPE_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_TAPE_IMAGE_SV, "Anslut bandavbildningsfil" },
/* tr */ { IDS_ATTACH_TAPE_IMAGE_TR, "Teyp imaj�n� yerle�tir" },

/* en */ { IDS_AUTOSTART_IMAGE,    "Autostart disk/tape image" },
/* da */ { IDS_AUTOSTART_IMAGE_DA, "Autostart disk-/b�nd-image" },
/* de */ { IDS_AUTOSTART_IMAGE_DE, "Autostart von Disk/Band Image" },
/* es */ { IDS_AUTOSTART_IMAGE_ES, "Autoarranque imagen de disco/cinta" },
/* fr */ { IDS_AUTOSTART_IMAGE_FR, "D�marrer automatiquement une image de disque/datassette" },
/* hu */ { IDS_AUTOSTART_IMAGE_HU, "Lemez/szalag k�pm�s automatikus ind�t�sa" },
/* it */ { IDS_AUTOSTART_IMAGE_IT, "Avvia automaticamente immagine disco/cassetta" },
/* ko */ { IDS_AUTOSTART_IMAGE_KO, "�ڵ� ���� ��ũ/������ �̹���" },
/* nl */ { IDS_AUTOSTART_IMAGE_NL, "Autostart disk-/tapebestand" },
/* pl */ { IDS_AUTOSTART_IMAGE_PL, "Automatycznie startuj z obrazu dysku lub ta�my" },
/* ru */ { IDS_AUTOSTART_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_AUTOSTART_IMAGE_SV, "Autostarta disk-/bandavbildningsfil" },
/* tr */ { IDS_AUTOSTART_IMAGE_TR, "Disk/Teyp imaj�n� otomatik ba�lat" },

/* en */ { IDS_IDE64_FILENAME,    "HD image file" },
/* da */ { IDS_IDE64_FILENAME_DA, "" },  /* fuzzy */
/* de */ { IDS_IDE64_FILENAME_DE, "HD Image Name" },
/* es */ { IDS_IDE64_FILENAME_ES, "Fichero imagen HD" },
/* fr */ { IDS_IDE64_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_IDE64_FILENAME_HU, "Merevlemez k�pm�s f�jl" },
/* it */ { IDS_IDE64_FILENAME_IT, "File immagine HD" },
/* ko */ { IDS_IDE64_FILENAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_IDE64_FILENAME_NL, "HD bestand" },
/* pl */ { IDS_IDE64_FILENAME_PL, "Plik obrazu HD" },
/* ru */ { IDS_IDE64_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_IDE64_FILENAME_SV, "HD-avbildningsfil" },
/* tr */ { IDS_IDE64_FILENAME_TR, "HD imaj dosyas�" },

/* en */ { IDS_IDE64_FILENAME_SELECT,    "Select HD image file" },
/* da */ { IDS_IDE64_FILENAME_SELECT_DA, "Angiv HD-imagefil" },
/* de */ { IDS_IDE64_FILENAME_SELECT_DE, "HD Image Datei ausw�hlen" },
/* es */ { IDS_IDE64_FILENAME_SELECT_ES, "Seleccionar fichero imagen HD" },
/* fr */ { IDS_IDE64_FILENAME_SELECT_FR, "S�lectionnez le fichier image du D.D." },
/* hu */ { IDS_IDE64_FILENAME_SELECT_HU, "V�lassza ki a merevlemez k�pm�s f�jlt" },
/* it */ { IDS_IDE64_FILENAME_SELECT_IT, "Seleziona il file immagine HD" },
/* ko */ { IDS_IDE64_FILENAME_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_IDE64_FILENAME_SELECT_NL, "Selecteer HD bestand" },
/* pl */ { IDS_IDE64_FILENAME_SELECT_PL, "Wybierz plik obrazu HD" },
/* ru */ { IDS_IDE64_FILENAME_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_IDE64_FILENAME_SELECT_SV, "Ange HD-avbildningsfil" },
/* tr */ { IDS_IDE64_FILENAME_SELECT_TR, "HD imaj dosyas� se�" },

/* en */ { IDS_IDE64_HD_1_SETTINGS,    "IDE64 HD 1 settings" },
/* da */ { IDS_IDE64_HD_1_SETTINGS_DA, "" },  /* fuzzy */
/* de */ { IDS_IDE64_HD_1_SETTINGS_DE, "IDE64 HD 1 Einstellungen" },
/* es */ { IDS_IDE64_HD_1_SETTINGS_ES, "Ajustes IDE64 HD 1" },
/* fr */ { IDS_IDE64_HD_1_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_IDE64_HD_1_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_IDE64_HD_1_SETTINGS_IT, "" },  /* fuzzy */
/* ko */ { IDS_IDE64_HD_1_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_IDE64_HD_1_SETTINGS_NL, "IDE64 HD 1 instellingen" },
/* pl */ { IDS_IDE64_HD_1_SETTINGS_PL, "Ustawienia IDE64 HD 1" },
/* ru */ { IDS_IDE64_HD_1_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_IDE64_HD_1_SETTINGS_SV, "" },  /* fuzzy */
/* tr */ { IDS_IDE64_HD_1_SETTINGS_TR, "" },  /* fuzzy */

/* en */ { IDS_IDE64_HD_2_SETTINGS,    "IDE64 HD 2 settings" },
/* da */ { IDS_IDE64_HD_2_SETTINGS_DA, "" },  /* fuzzy */
/* de */ { IDS_IDE64_HD_2_SETTINGS_DE, "IDE64 HD 2 Einstellungen" },
/* es */ { IDS_IDE64_HD_2_SETTINGS_ES, "Ajustes IDE64 HD 2" },
/* fr */ { IDS_IDE64_HD_2_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_IDE64_HD_2_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_IDE64_HD_2_SETTINGS_IT, "" },  /* fuzzy */
/* ko */ { IDS_IDE64_HD_2_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_IDE64_HD_2_SETTINGS_NL, "IDE64 HD 2 instellingen" },
/* pl */ { IDS_IDE64_HD_2_SETTINGS_PL, "Ustawienia IDE64 HD 2" },
/* ru */ { IDS_IDE64_HD_2_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_IDE64_HD_2_SETTINGS_SV, "" },  /* fuzzy */
/* tr */ { IDS_IDE64_HD_2_SETTINGS_TR, "" },  /* fuzzy */

/* en */ { IDS_IDE64_HD_3_SETTINGS,    "IDE64 HD 3 settings" },
/* da */ { IDS_IDE64_HD_3_SETTINGS_DA, "" },  /* fuzzy */
/* de */ { IDS_IDE64_HD_3_SETTINGS_DE, "IDE64 HD 3 Einstellungen" },
/* es */ { IDS_IDE64_HD_3_SETTINGS_ES, "Ajustes IDE64 HD 3" },
/* fr */ { IDS_IDE64_HD_3_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_IDE64_HD_3_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_IDE64_HD_3_SETTINGS_IT, "" },  /* fuzzy */
/* ko */ { IDS_IDE64_HD_3_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_IDE64_HD_3_SETTINGS_NL, "IDE64 HD 3 instellingen" },
/* pl */ { IDS_IDE64_HD_3_SETTINGS_PL, "Ustawienia IDE64 HD 3" },
/* ru */ { IDS_IDE64_HD_3_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_IDE64_HD_3_SETTINGS_SV, "" },  /* fuzzy */
/* tr */ { IDS_IDE64_HD_3_SETTINGS_TR, "" },  /* fuzzy */

/* en */ { IDS_IDE64_HD_4_SETTINGS,    "IDE64 HD 4 settings" },
/* da */ { IDS_IDE64_HD_4_SETTINGS_DA, "" },  /* fuzzy */
/* de */ { IDS_IDE64_HD_4_SETTINGS_DE, "IDE64 HD 4 Einstellungen" },
/* es */ { IDS_IDE64_HD_4_SETTINGS_ES, "Ajustes IDE64 HD 4" },
/* fr */ { IDS_IDE64_HD_4_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_IDE64_HD_4_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_IDE64_HD_4_SETTINGS_IT, "" },  /* fuzzy */
/* ko */ { IDS_IDE64_HD_4_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_IDE64_HD_4_SETTINGS_NL, "IDE64 HD 4 instellingen" },
/* pl */ { IDS_IDE64_HD_4_SETTINGS_PL, "Ustawienia IDE64 HD 4" },
/* ru */ { IDS_IDE64_HD_4_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_IDE64_HD_4_SETTINGS_SV, "" },  /* fuzzy */
/* tr */ { IDS_IDE64_HD_4_SETTINGS_TR, "" },  /* fuzzy */

/* en */ { IDS_IDE64_V4,    "IDE64 V4" },
/* da */ { IDS_IDE64_V4_DA, "IDE64 V4" },
/* de */ { IDS_IDE64_V4_DE, "IDE64 V4" },
/* es */ { IDS_IDE64_V4_ES, "IDE64 V4" },
/* fr */ { IDS_IDE64_V4_FR, "" },  /* fuzzy */
/* hu */ { IDS_IDE64_V4_HU, "" },  /* fuzzy */
/* it */ { IDS_IDE64_V4_IT, "IDE64 V4" },
/* ko */ { IDS_IDE64_V4_KO, "" },  /* fuzzy */
/* nl */ { IDS_IDE64_V4_NL, "IDE64 V4" },
/* pl */ { IDS_IDE64_V4_PL, "IDE64 V4" },
/* ru */ { IDS_IDE64_V4_RU, "" },  /* fuzzy */
/* sv */ { IDS_IDE64_V4_SV, "IDE64 V4" },
/* tr */ { IDS_IDE64_V4_TR, "IDE64 V4" },

/* en */ { IDS_AUTODETECT,    "Autodetect image size" },
/* da */ { IDS_AUTODETECT_DA, "Autodetekt�r st�rrelse p� image" },
/* de */ { IDS_AUTODETECT_DE, "Image Gr��e automatisch erkennen" },
/* es */ { IDS_AUTODETECT_ES, "Autodetecci�n del tama�o de la imagen" },
/* fr */ { IDS_AUTODETECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_AUTODETECT_HU, "" },  /* fuzzy */
/* it */ { IDS_AUTODETECT_IT, "Rileva automaticamente immagine" },
/* ko */ { IDS_AUTODETECT_KO, "�̹��� ũ�� �ڵ����� ã��" },
/* nl */ { IDS_AUTODETECT_NL, "Automatisch detecteren bestandsgrootte" },
/* pl */ { IDS_AUTODETECT_PL, "Automatycznie wykrywaj rozmiar obrazu" },
/* ru */ { IDS_AUTODETECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_AUTODETECT_SV, "Autodetektera storlek p� avbildning" },
/* tr */ { IDS_AUTODETECT_TR, "Imaj boyutunu otomatik alg�la" },

/* en */ { IDS_CYLINDERS,    "Cylinders" },
/* da */ { IDS_CYLINDERS_DA, "Cylindrer" },
/* de */ { IDS_CYLINDERS_DE, "Zylinder" },
/* es */ { IDS_CYLINDERS_ES, "Cilindros" },
/* fr */ { IDS_CYLINDERS_FR, "Cylindres" },
/* hu */ { IDS_CYLINDERS_HU, "S�vok" },
/* it */ { IDS_CYLINDERS_IT, "Cilindri" },
/* ko */ { IDS_CYLINDERS_KO, "�Ǹ���" },
/* nl */ { IDS_CYLINDERS_NL, "Cylinders" },
/* pl */ { IDS_CYLINDERS_PL, "Cylindry" },
/* ru */ { IDS_CYLINDERS_RU, "" },  /* fuzzy */
/* sv */ { IDS_CYLINDERS_SV, "Cylindrar" },
/* tr */ { IDS_CYLINDERS_TR, "Silindirler" },

/* en */ { IDS_HEADS,    "Heads" },
/* da */ { IDS_HEADS_DA, "Hoveder" },
/* de */ { IDS_HEADS_DE, "K�pfe" },
/* es */ { IDS_HEADS_ES, "Cabezas" },
/* fr */ { IDS_HEADS_FR, "T�tes" },
/* hu */ { IDS_HEADS_HU, "Fejek" },
/* it */ { IDS_HEADS_IT, "Testine" },
/* ko */ { IDS_HEADS_KO, "���" },
/* nl */ { IDS_HEADS_NL, "Koppen" },
/* pl */ { IDS_HEADS_PL, "G�owice" },
/* ru */ { IDS_HEADS_RU, "" },  /* fuzzy */
/* sv */ { IDS_HEADS_SV, "Huvuden" },
/* tr */ { IDS_HEADS_TR, "Kafalar" },

/* en */ { IDS_SECTORS,    "Sectors" },
/* da */ { IDS_SECTORS_DA, "Sektorer" },
/* de */ { IDS_SECTORS_DE, "Sektoren" },
/* es */ { IDS_SECTORS_ES, "Sectores" },
/* fr */ { IDS_SECTORS_FR, "Secteurs" },
/* hu */ { IDS_SECTORS_HU, "Szektorok" },
/* it */ { IDS_SECTORS_IT, "Settori" },
/* ko */ { IDS_SECTORS_KO, "����" },
/* nl */ { IDS_SECTORS_NL, "Sectors" },
/* pl */ { IDS_SECTORS_PL, "Sektory" },
/* ru */ { IDS_SECTORS_RU, "" },  /* fuzzy */
/* sv */ { IDS_SECTORS_SV, "Sektorer" },
/* tr */ { IDS_SECTORS_TR, "Sekt�rler" },

/* en */ { IDS_IDE64_SETTINGS,    "IDE64 settings" },
/* da */ { IDS_IDE64_SETTINGS_DA, "IDE64-indstillinger" },
/* de */ { IDS_IDE64_SETTINGS_DE, "IDE64 Einstellungen" },
/* es */ { IDS_IDE64_SETTINGS_ES, "Ajustes IDE64" },
/* fr */ { IDS_IDE64_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_IDE64_SETTINGS_HU, "IDE64 be�ll�t�sai" },
/* it */ { IDS_IDE64_SETTINGS_IT, "Impostazioni IDE64" },
/* ko */ { IDS_IDE64_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_IDE64_SETTINGS_NL, "IDE64 instellingen" },
/* pl */ { IDS_IDE64_SETTINGS_PL, "Ustawienia IDE64" },
/* ru */ { IDS_IDE64_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_IDE64_SETTINGS_SV, "IDE64-inst�llningar" },
/* tr */ { IDS_IDE64_SETTINGS_TR, "IDE64 ayarlar�" },

/* en */ { IDS_BIOS_REVISION,    "BIOS Revision" },
/* da */ { IDS_BIOS_REVISION_DA, "BIOS-revision" },
/* de */ { IDS_BIOS_REVISION_DE, "BIOS Revision" },
/* es */ { IDS_BIOS_REVISION_ES, "Revisi�n BIOS" },
/* fr */ { IDS_BIOS_REVISION_FR, "" },  /* fuzzy */
/* hu */ { IDS_BIOS_REVISION_HU, "BIOS v�ltozat" },
/* it */ { IDS_BIOS_REVISION_IT, "Revisione BIOS" },
/* ko */ { IDS_BIOS_REVISION_KO, "" },  /* fuzzy */
/* nl */ { IDS_BIOS_REVISION_NL, "BIOS revisie" },
/* pl */ { IDS_BIOS_REVISION_PL, "Wersja BIOS" },
/* ru */ { IDS_BIOS_REVISION_RU, "" },  /* fuzzy */
/* sv */ { IDS_BIOS_REVISION_SV, "BIOS-utg�va" },
/* tr */ { IDS_BIOS_REVISION_TR, "BIOS Revizyonu" },

/* en */ { IDS_BIOS_FLASH_JUMPER,    "BIOS Flash Jumper" },
/* da */ { IDS_BIOS_FLASH_JUMPER_DA, "BIOS-flashjumper" },
/* de */ { IDS_BIOS_FLASH_JUMPER_DE, "BIOS Flashjumper" },
/* es */ { IDS_BIOS_FLASH_JUMPER_ES, "BIOS Flash Jumper" },
/* fr */ { IDS_BIOS_FLASH_JUMPER_FR, "Flash Jumper BIOS" },
/* hu */ { IDS_BIOS_FLASH_JUMPER_HU, "BIOS Flash jumper" },
/* it */ { IDS_BIOS_FLASH_JUMPER_IT, "Flash Jumper del BIOS" },
/* ko */ { IDS_BIOS_FLASH_JUMPER_KO, "" },  /* fuzzy */
/* nl */ { IDS_BIOS_FLASH_JUMPER_NL, "BIOS Flash Jumper" },
/* pl */ { IDS_BIOS_FLASH_JUMPER_PL, "Prze��cznik BIOS Flash" },
/* ru */ { IDS_BIOS_FLASH_JUMPER_RU, "" },  /* fuzzy */
/* sv */ { IDS_BIOS_FLASH_JUMPER_SV, "BIOS-flashbygel" },
/* tr */ { IDS_BIOS_FLASH_JUMPER_TR, "BIOS Flash Jumper" },

/* en */ { IDS_SAVE_BIOS_WHEN_CHANGED,    "Save BIOS when changed" },
/* da */ { IDS_SAVE_BIOS_WHEN_CHANGED_DA, "Gem BIOS ved �ndringer" },
/* de */ { IDS_SAVE_BIOS_WHEN_CHANGED_DE, "BIOS bei �nderung speichern" },
/* es */ { IDS_SAVE_BIOS_WHEN_CHANGED_ES, "Grabar BIOS cuando cambien" },
/* fr */ { IDS_SAVE_BIOS_WHEN_CHANGED_FR, "Enregistrer le BIOS lorsque modifi�" },
/* hu */ { IDS_SAVE_BIOS_WHEN_CHANGED_HU, "BIOS ment�se v�ltoz�s ut�n" },
/* it */ { IDS_SAVE_BIOS_WHEN_CHANGED_IT, "Salva BIOS al cambio" },
/* ko */ { IDS_SAVE_BIOS_WHEN_CHANGED_KO, "" },  /* fuzzy */
/* nl */ { IDS_SAVE_BIOS_WHEN_CHANGED_NL, "Sla de MMC64 BIOS op als er veranderingen zijn gemaakt" },
/* pl */ { IDS_SAVE_BIOS_WHEN_CHANGED_PL, "Zapisuj BIOS przy zmianie" },
/* ru */ { IDS_SAVE_BIOS_WHEN_CHANGED_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_BIOS_WHEN_CHANGED_SV, "Spara BIOS vid �ndring" },
/* tr */ { IDS_SAVE_BIOS_WHEN_CHANGED_TR, "BIOS de�i�ti�inde kaydet" },

/* en */ { IDS_BIOS_FILE,    "BIOS File" },
/* da */ { IDS_BIOS_FILE_DA, "BIOS-fil" },
/* de */ { IDS_BIOS_FILE_DE, "BIOS Datei" },
/* es */ { IDS_BIOS_FILE_ES, "Fichero BIOS" },
/* fr */ { IDS_BIOS_FILE_FR, "Fichier du BIOS" },
/* hu */ { IDS_BIOS_FILE_HU, "BIOS f�jl" },
/* it */ { IDS_BIOS_FILE_IT, "File BIOS" },
/* ko */ { IDS_BIOS_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDS_BIOS_FILE_NL, "BIOS bestand" },
/* pl */ { IDS_BIOS_FILE_PL, "Plik BIOS" },
/* ru */ { IDS_BIOS_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_BIOS_FILE_SV, "BIOS-fil" },
/* tr */ { IDS_BIOS_FILE_TR, "BIOS Dosyas�" },

/* en */ { IDS_SELECT_BIOS_FILE,    "Select BIOS file" },
/* da */ { IDS_SELECT_BIOS_FILE_DA, "V�lg BIOS-fil" },
/* de */ { IDS_SELECT_BIOS_FILE_DE, "BIOS Datei w�hlen" },
/* es */ { IDS_SELECT_BIOS_FILE_ES, "Seleccionar fichero BIOS" },
/* fr */ { IDS_SELECT_BIOS_FILE_FR, "S�lectionner le fichier du BIOS" },
/* hu */ { IDS_SELECT_BIOS_FILE_HU, "V�lasszon BIOS f�jlt" },
/* it */ { IDS_SELECT_BIOS_FILE_IT, "Seleziona file BIOS" },
/* ko */ { IDS_SELECT_BIOS_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_BIOS_FILE_NL, "Selecteer BIOS bestand" },
/* pl */ { IDS_SELECT_BIOS_FILE_PL, "Wybierz plik BIOS" },
/* ru */ { IDS_SELECT_BIOS_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_BIOS_FILE_SV, "V�lj BIOS-fil" },
/* tr */ { IDS_SELECT_BIOS_FILE_TR, "BIOS dosyas� se�in" },

/* en */ { IDS_MMC64_IMAGE_READ_ONLY,    "MMC/SD Image read-only" },
/* da */ { IDS_MMC64_IMAGE_READ_ONLY_DA, "MMC/SD-image skrivebeskyttet" },
/* de */ { IDS_MMC64_IMAGE_READ_ONLY_DE, "MMC/SD Image Schreibschutz" },
/* es */ { IDS_MMC64_IMAGE_READ_ONLY_ES, "Imagen MMC/SD de s�lo lectura" },
/* fr */ { IDS_MMC64_IMAGE_READ_ONLY_FR, "Image MMC/SD en lecture seule" },
/* hu */ { IDS_MMC64_IMAGE_READ_ONLY_HU, "MMC/SD k�pm�s csak olvashat�" },
/* it */ { IDS_MMC64_IMAGE_READ_ONLY_IT, "Immagine MMC/SD in sola lettura" },
/* ko */ { IDS_MMC64_IMAGE_READ_ONLY_KO, "" },  /* fuzzy */
/* nl */ { IDS_MMC64_IMAGE_READ_ONLY_NL, "MMC/SD bestand alleen-lezen" },
/* pl */ { IDS_MMC64_IMAGE_READ_ONLY_PL, "Obraz MMC/SC tylko do odczytu" },
/* ru */ { IDS_MMC64_IMAGE_READ_ONLY_RU, "" },  /* fuzzy */
/* sv */ { IDS_MMC64_IMAGE_READ_ONLY_SV, "MMC/SD-avbildning skrivskyddad" },
/* tr */ { IDS_MMC64_IMAGE_READ_ONLY_TR, "Salt Okunur MMC/SD Imaj�" },

/* en */ { IDS_MMC64_IMAGE_FILE,    "MMC/SD Image File" },
/* da */ { IDS_MMC64_IMAGE_FILE_DA, "MMC/SD-image" },
/* de */ { IDS_MMC64_IMAGE_FILE_DE, "MMC/SD Image Name" },
/* es */ { IDS_MMC64_IMAGE_FILE_ES, "Fichero imagen MMC/SD" },
/* fr */ { IDS_MMC64_IMAGE_FILE_FR, "Nom d'image MMC/SD" },
/* hu */ { IDS_MMC64_IMAGE_FILE_HU, "MMC/SD k�pm�s f�jl" },
/* it */ { IDS_MMC64_IMAGE_FILE_IT, "File immagine MMC/SD" },
/* ko */ { IDS_MMC64_IMAGE_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDS_MMC64_IMAGE_FILE_NL, "MMC/SD bestand" },
/* pl */ { IDS_MMC64_IMAGE_FILE_PL, "Plik obrazu MMC/SD" },
/* ru */ { IDS_MMC64_IMAGE_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_MMC64_IMAGE_FILE_SV, "MMC/SD-avbildningsfil" },
/* tr */ { IDS_MMC64_IMAGE_FILE_TR, "MMC/SD Imaj Dosyas�" },

/* en */ { IDS_SD_TYPE,    "Card type" },
/* da */ { IDS_SD_TYPE_DA, "Korttype" },
/* de */ { IDS_SD_TYPE_DE, "Card Typ" },
/* es */ { IDS_SD_TYPE_ES, "Tipo de tarjeta" },
/* fr */ { IDS_SD_TYPE_FR, "" },  /* fuzzy */
/* hu */ { IDS_SD_TYPE_HU, "" },  /* fuzzy */
/* it */ { IDS_SD_TYPE_IT, "Tipo card" },
/* ko */ { IDS_SD_TYPE_KO, "ī�� ����" },
/* nl */ { IDS_SD_TYPE_NL, "Card soort" },
/* pl */ { IDS_SD_TYPE_PL, "Typ karty" },
/* ru */ { IDS_SD_TYPE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SD_TYPE_SV, "Korttyp" },
/* tr */ { IDS_SD_TYPE_TR, "Kart tipi" },

/* en */ { IDS_SELECT_MMC64_IMAGE_FILE,    "Select MMC/SD image file" },
/* da */ { IDS_SELECT_MMC64_IMAGE_FILE_DA, "V�lg MMC/SD-image" },
/* de */ { IDS_SELECT_MMC64_IMAGE_FILE_DE, "MMC/SD Image Date w�hlen" },
/* es */ { IDS_SELECT_MMC64_IMAGE_FILE_ES, "Seleccionar fichero imagen MMC/SD" },
/* fr */ { IDS_SELECT_MMC64_IMAGE_FILE_FR, "S�lectionnez le fichier image du MMC/SD" },
/* hu */ { IDS_SELECT_MMC64_IMAGE_FILE_HU, "V�lassza ki az MMC/SD k�pm�s f�jlt" },
/* it */ { IDS_SELECT_MMC64_IMAGE_FILE_IT, "Seleziona file immagine MMC/SD" },
/* ko */ { IDS_SELECT_MMC64_IMAGE_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_MMC64_IMAGE_FILE_NL, "Selecteer MMC/SD bestand" },
/* pl */ { IDS_SELECT_MMC64_IMAGE_FILE_PL, "Wybierz plik obrazu MMC/SD" },
/* ru */ { IDS_SELECT_MMC64_IMAGE_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_MMC64_IMAGE_FILE_SV, "Ange MMC/SD-avbildningsfil" },
/* tr */ { IDS_SELECT_MMC64_IMAGE_FILE_TR, "MMC/SD imaj dosyas� se�in" },

/* en */ { IDS_MMC64_SETTINGS,    "MMC64 settings" },
/* da */ { IDS_MMC64_SETTINGS_DA, "MMC64-indstillinger" },
/* de */ { IDS_MMC64_SETTINGS_DE, "MMC64 Einstellungen" },
/* es */ { IDS_MMC64_SETTINGS_ES, "Ajustes MMC64" },
/* fr */ { IDS_MMC64_SETTINGS_FR, "Param�tres MMC64..." },
/* hu */ { IDS_MMC64_SETTINGS_HU, "MMC64 be�ll�t�sai" },
/* it */ { IDS_MMC64_SETTINGS_IT, "Impostazioni MMC64" },
/* ko */ { IDS_MMC64_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_MMC64_SETTINGS_NL, "MMC64 instellingen" },
/* pl */ { IDS_MMC64_SETTINGS_PL, "Ustawienia MMC64" },
/* ru */ { IDS_MMC64_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_MMC64_SETTINGS_SV, "MMC64-inst�llningar..." },
/* tr */ { IDS_MMC64_SETTINGS_TR, "MMC64 ayarlar�" },

/* en */ { IDS_SELECT_EEPROM_FILE,    "Select EEPROM file" },
/* da */ { IDS_SELECT_EEPROM_FILE_DA, "V�lg EEPROM-fil" },
/* de */ { IDS_SELECT_EEPROM_FILE_DE, "EEPROM Datei w�hlen" },
/* es */ { IDS_SELECT_EEPROM_FILE_ES, "Seleccionar fichero EEPROM" },
/* fr */ { IDS_SELECT_EEPROM_FILE_FR, "" },  /* fuzzy */
/* hu */ { IDS_SELECT_EEPROM_FILE_HU, "" },  /* fuzzy */
/* it */ { IDS_SELECT_EEPROM_FILE_IT, "Seleziona file EEPROM" },
/* ko */ { IDS_SELECT_EEPROM_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_EEPROM_FILE_NL, "Selecteer EEPROM bestand" },
/* pl */ { IDS_SELECT_EEPROM_FILE_PL, "Wybierz plik EEPROM" },
/* ru */ { IDS_SELECT_EEPROM_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_EEPROM_FILE_SV, "V�lj EEPROM-fil" },
/* tr */ { IDS_SELECT_EEPROM_FILE_TR, "EEPROM dosyas� se�in" },

/* en */ { IDS_SELECT_CARD_IMAGE_FILE,    "Select card image file" },
/* da */ { IDS_SELECT_CARD_IMAGE_FILE_DA, "Angiv kortimagefil" },
/* de */ { IDS_SELECT_CARD_IMAGE_FILE_DE, "Card Image Datei ausw�hlen" },
/* es */ { IDS_SELECT_CARD_IMAGE_FILE_ES, "Selecionar fichero imagen tarjeta" },
/* fr */ { IDS_SELECT_CARD_IMAGE_FILE_FR, "" },  /* fuzzy */
/* hu */ { IDS_SELECT_CARD_IMAGE_FILE_HU, "" },  /* fuzzy */
/* it */ { IDS_SELECT_CARD_IMAGE_FILE_IT, "Seleziona file immagine card" },
/* ko */ { IDS_SELECT_CARD_IMAGE_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_CARD_IMAGE_FILE_NL, "Selecteer card bestand" },
/* pl */ { IDS_SELECT_CARD_IMAGE_FILE_PL, "Wybierz plik obrazu karty" },
/* ru */ { IDS_SELECT_CARD_IMAGE_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_CARD_IMAGE_FILE_SV, "Ange kortavbildningsfil" },
/* tr */ { IDS_SELECT_CARD_IMAGE_FILE_TR, "Kart imaj dosyas� se�" },

/* en */ { IDS_CARD_FILE,    "Card image file" },
/* da */ { IDS_CARD_FILE_DA, "" },  /* fuzzy */
/* de */ { IDS_CARD_FILE_DE, "Card Image Datei" },
/* es */ { IDS_CARD_FILE_ES, "Fichero imagen tarjeta" },
/* fr */ { IDS_CARD_FILE_FR, "" },  /* fuzzy */
/* hu */ { IDS_CARD_FILE_HU, "" },  /* fuzzy */
/* it */ { IDS_CARD_FILE_IT, "" },  /* fuzzy */
/* ko */ { IDS_CARD_FILE_KO, "ī�� �̹��� ����" },
/* nl */ { IDS_CARD_FILE_NL, "Card bestand" },
/* pl */ { IDS_CARD_FILE_PL, "Plik obrazu karty" },
/* ru */ { IDS_CARD_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_CARD_FILE_SV, "Kortavbildningsfil" },
/* tr */ { IDS_CARD_FILE_TR, "" },  /* fuzzy */

/* en */ { IDS_CARD_READ_WRITE,    "Card read/write" },
/* da */ { IDS_CARD_READ_WRITE_DA, "Kort l�s/skriv" },
/* de */ { IDS_CARD_READ_WRITE_DE, "Card lese/schreibe" },
/* es */ { IDS_CARD_READ_WRITE_ES, "Tarjeta lectura/grabaci�n" },
/* fr */ { IDS_CARD_READ_WRITE_FR, "" },  /* fuzzy */
/* hu */ { IDS_CARD_READ_WRITE_HU, "" },  /* fuzzy */
/* it */ { IDS_CARD_READ_WRITE_IT, "Card in lettura/scrittura" },
/* ko */ { IDS_CARD_READ_WRITE_KO, "" },  /* fuzzy */
/* nl */ { IDS_CARD_READ_WRITE_NL, "Card lees/schrijf" },
/* pl */ { IDS_CARD_READ_WRITE_PL, "odczyt/zapis na kart�" },
/* ru */ { IDS_CARD_READ_WRITE_RU, "" },  /* fuzzy */
/* sv */ { IDS_CARD_READ_WRITE_SV, "Skrivbart kort" },
/* tr */ { IDS_CARD_READ_WRITE_TR, "Kart oku/yaz" },

/* en */ { IDS_EEPROM_FILE,    "EEPROM image file" },
/* da */ { IDS_EEPROM_FILE_DA, "" },  /* fuzzy */
/* de */ { IDS_EEPROM_FILE_DE, "EEPROM Image Datei" },
/* es */ { IDS_EEPROM_FILE_ES, "Fichero imagen EEPROM" },
/* fr */ { IDS_EEPROM_FILE_FR, "" },  /* fuzzy */
/* hu */ { IDS_EEPROM_FILE_HU, "" },  /* fuzzy */
/* it */ { IDS_EEPROM_FILE_IT, "" },  /* fuzzy */
/* ko */ { IDS_EEPROM_FILE_KO, "EEPROM �̹��� ����" },
/* nl */ { IDS_EEPROM_FILE_NL, "EEPROM bestand" },
/* pl */ { IDS_EEPROM_FILE_PL, "Plik obrazu EEPROM" },
/* ru */ { IDS_EEPROM_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_EEPROM_FILE_SV, "EEPROM-avbildningsfil" },
/* tr */ { IDS_EEPROM_FILE_TR, "" },  /* fuzzy */

/* en */ { IDS_WRITE_TO_EEPROM_WHEN_CHANGED,    "Save EEPROM image when changed" },
/* da */ { IDS_WRITE_TO_EEPROM_WHEN_CHANGED_DA, "Gem EEPROM image ved �ndringer" },
/* de */ { IDS_WRITE_TO_EEPROM_WHEN_CHANGED_DE, "GEO-RAM Imagedatei bei �nderung speichern" },
/* es */ { IDS_WRITE_TO_EEPROM_WHEN_CHANGED_ES, "Grabar imagen EEPROM cuando cambie" },
/* fr */ { IDS_WRITE_TO_EEPROM_WHEN_CHANGED_FR, "" },  /* fuzzy */
/* hu */ { IDS_WRITE_TO_EEPROM_WHEN_CHANGED_HU, "" },  /* fuzzy */
/* it */ { IDS_WRITE_TO_EEPROM_WHEN_CHANGED_IT, "Salva immagine EEPROM al cambio" },
/* ko */ { IDS_WRITE_TO_EEPROM_WHEN_CHANGED_KO, "" },  /* fuzzy */
/* nl */ { IDS_WRITE_TO_EEPROM_WHEN_CHANGED_NL, "GEO-RAM bestand opslaan indien gewijzigd" },
/* pl */ { IDS_WRITE_TO_EEPROM_WHEN_CHANGED_PL, "Zapisuj obraz EEPROM przy zmianie" },
/* ru */ { IDS_WRITE_TO_EEPROM_WHEN_CHANGED_RU, "" },  /* fuzzy */
/* sv */ { IDS_WRITE_TO_EEPROM_WHEN_CHANGED_SV, "Spara EEPROM-avbildning vid �ndringar" },
/* tr */ { IDS_WRITE_TO_EEPROM_WHEN_CHANGED_TR, "EEPROM imaj� de�i�ti�inde kaydet" },

/* en */ { IDS_EEPROM_READ_WRITE,    "EEPROM read/write" },
/* da */ { IDS_EEPROM_READ_WRITE_DA, "EEPROM l�s/skriv" },
/* de */ { IDS_EEPROM_READ_WRITE_DE, "EEPROM lese/schreibe" },
/* es */ { IDS_EEPROM_READ_WRITE_ES, "Lectura/grabaci�n EEPROM" },
/* fr */ { IDS_EEPROM_READ_WRITE_FR, "" },  /* fuzzy */
/* hu */ { IDS_EEPROM_READ_WRITE_HU, "" },  /* fuzzy */
/* it */ { IDS_EEPROM_READ_WRITE_IT, "EEPROM in lettura/scrittura" },
/* ko */ { IDS_EEPROM_READ_WRITE_KO, "" },  /* fuzzy */
/* nl */ { IDS_EEPROM_READ_WRITE_NL, "EEPROM lees/schrijf" },
/* pl */ { IDS_EEPROM_READ_WRITE_PL, "odczyt/zapis EEPROM" },
/* ru */ { IDS_EEPROM_READ_WRITE_RU, "" },  /* fuzzy */
/* sv */ { IDS_EEPROM_READ_WRITE_SV, "Skrivbar EEPROM" },
/* tr */ { IDS_EEPROM_READ_WRITE_TR, "EEPROM oku/yaz" },

/* en */ { IDS_RESCUE_MODE,    "Rescue mode" },
/* da */ { IDS_RESCUE_MODE_DA, "Fejlsikret tilstand" },
/* de */ { IDS_RESCUE_MODE_DE, "Rescue Modus" },
/* es */ { IDS_RESCUE_MODE_ES, "Modo rescate" },
/* fr */ { IDS_RESCUE_MODE_FR, "" },  /* fuzzy */
/* hu */ { IDS_RESCUE_MODE_HU, "" },  /* fuzzy */
/* it */ { IDS_RESCUE_MODE_IT, "Modalit� ripristino" },
/* ko */ { IDS_RESCUE_MODE_KO, "" },  /* fuzzy */
/* nl */ { IDS_RESCUE_MODE_NL, "Reddingsmodus" },
/* pl */ { IDS_RESCUE_MODE_PL, "Tryb ratunkowy" },
/* ru */ { IDS_RESCUE_MODE_RU, "" },  /* fuzzy */
/* sv */ { IDS_RESCUE_MODE_SV, "R�ddningsl�ge" },
/* tr */ { IDS_RESCUE_MODE_TR, "Kurtarma modu" },

/* en */ { IDS_MMCREPLAY_SETTINGS,    "MMC Replay settings" },
/* da */ { IDS_MMCREPLAY_SETTINGS_DA, "MMC Replay-indstillinger" },
/* de */ { IDS_MMCREPLAY_SETTINGS_DE, "MMC Replay Einstellungen" },
/* es */ { IDS_MMCREPLAY_SETTINGS_ES, "Ajustes MMC Replay" },
/* fr */ { IDS_MMCREPLAY_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_MMCREPLAY_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_MMCREPLAY_SETTINGS_IT, "Impostazioni MMC Replay" },
/* ko */ { IDS_MMCREPLAY_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_MMCREPLAY_SETTINGS_NL, "MMC Replay instellingen" },
/* pl */ { IDS_MMCREPLAY_SETTINGS_PL, "Ustawienia MMC Replay" },
/* ru */ { IDS_MMCREPLAY_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_MMCREPLAY_SETTINGS_SV, "MMC Replay-inst�llningar" },
/* tr */ { IDS_MMCREPLAY_SETTINGS_TR, "MMC Replay ayarlar�" },

/* en */ { IDS_SELECT_GENERIC,    "Select generic cartridge image" },
/* da */ { IDS_SELECT_GENERIC_DA, "V�lg standardcartridgeimage" },
/* de */ { IDS_SELECT_GENERIC_DE, "Unverselles Erweiterungsmodul Image Datei w�hlen" },
/* es */ { IDS_SELECT_GENERIC_ES, "Seleccionar imagen cartucho generico" },
/* fr */ { IDS_SELECT_GENERIC_FR, "" },  /* fuzzy */
/* hu */ { IDS_SELECT_GENERIC_HU, "" },  /* fuzzy */
/* it */ { IDS_SELECT_GENERIC_IT, "Seleziona immagine cartuccia generica" },
/* ko */ { IDS_SELECT_GENERIC_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_GENERIC_NL, "Selecteer algemeen cartridge bestand" },
/* pl */ { IDS_SELECT_GENERIC_PL, "Wybierz typowy obraz kartrid�a" },
/* ru */ { IDS_SELECT_GENERIC_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_GENERIC_SV, "V�lj generisk insticksmodulavbildning" },
/* tr */ { IDS_SELECT_GENERIC_TR, "Jenerik kartu� imaj� se�" },

/* en */ { IDS_SELECT_FP,    "Select Vic Flash Plugin image" },
/* da */ { IDS_SELECT_FP_DA, "V�lg Vic Flash Plugin-image" },
/* de */ { IDS_SELECT_FP_DE, "Vic Flash Plugin Image ausw�hlen" },
/* es */ { IDS_SELECT_FP_ES, "Seleccionar imagen Vic Flash Plugin" },
/* fr */ { IDS_SELECT_FP_FR, "" },  /* fuzzy */
/* hu */ { IDS_SELECT_FP_HU, "" },  /* fuzzy */
/* it */ { IDS_SELECT_FP_IT, "Seleziona immagine Vic Flash Plugin " },
/* ko */ { IDS_SELECT_FP_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_FP_NL, "Selecteer Vic Flash Plugin bestand" },
/* pl */ { IDS_SELECT_FP_PL, "Wybierz obraz Vic Flash Plugin" },
/* ru */ { IDS_SELECT_FP_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_FP_SV, "V�lj avbildning f�r Vic Flash-insticksmodul" },
/* tr */ { IDS_SELECT_FP_TR, "Vic Flash Plugin imaj� se�" },

/* en */ { IDS_SELECT_MEGACART,    "Select Mega-Cart image" },
/* da */ { IDS_SELECT_MEGACART_DA, "V�lg MegaCart-imagefil" },
/* de */ { IDS_SELECT_MEGACART_DE, "Mega-Cart Image Date w�hlen" },
/* es */ { IDS_SELECT_MEGACART_ES, "Seleccionar imagen Mega-Cart" },
/* fr */ { IDS_SELECT_MEGACART_FR, "" },  /* fuzzy */
/* hu */ { IDS_SELECT_MEGACART_HU, "V�lassza ki a Mega-Cart k�pm�st" },
/* it */ { IDS_SELECT_MEGACART_IT, "Seleziona immagine Mega-Cart" },
/* ko */ { IDS_SELECT_MEGACART_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_MEGACART_NL, "Selecteer Mega-Cart bestand" },
/* pl */ { IDS_SELECT_MEGACART_PL, "Wybierz obraz Mega-Cart" },
/* ru */ { IDS_SELECT_MEGACART_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_MEGACART_SV, "V�lj Mega-Cart-modulfil" },
/* tr */ { IDS_SELECT_MEGACART_TR, "Mega-Cart imaj� se�" },

/* en */ { IDS_SELECT_FINAL_EXPANSION,    "Select Final Expansion image" },
/* da */ { IDS_SELECT_FINAL_EXPANSION_DA, "V�lg Final Expansion-imagefil" },
/* de */ { IDS_SELECT_FINAL_EXPANSION_DE, "Final Expansion Image Datei ausw�hlen" },
/* es */ { IDS_SELECT_FINAL_EXPANSION_ES, "Seleccionar imagen Final Expansion" },
/* fr */ { IDS_SELECT_FINAL_EXPANSION_FR, "" },  /* fuzzy */
/* hu */ { IDS_SELECT_FINAL_EXPANSION_HU, "V�lassza ki a Final Expansion k�pm�st" },
/* it */ { IDS_SELECT_FINAL_EXPANSION_IT, "Seleziona immagine Final Expansion" },
/* ko */ { IDS_SELECT_FINAL_EXPANSION_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_FINAL_EXPANSION_NL, "Selecteer Final Expansion bestand" },
/* pl */ { IDS_SELECT_FINAL_EXPANSION_PL, "Wybierz obraz Final Expansion" },
/* ru */ { IDS_SELECT_FINAL_EXPANSION_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_FINAL_EXPANSION_SV, "V�lj avbildning f�r Final Expansion" },
/* tr */ { IDS_SELECT_FINAL_EXPANSION_TR, "Final Expansion imaj� se�" },

/* en */ { IDS_SELECT_CARTRIDGE_IMAGE,    "Select cartridge file" },
/* da */ { IDS_SELECT_CARTRIDGE_IMAGE_DA, "V�lg cartridge-fil" },
/* de */ { IDS_SELECT_CARTRIDGE_IMAGE_DE, "Erweiterungsmodul Image Datei w�hlen" },
/* es */ { IDS_SELECT_CARTRIDGE_IMAGE_ES, "Seleccionar imagen cartucho" },
/* fr */ { IDS_SELECT_CARTRIDGE_IMAGE_FR, "" },  /* fuzzy */
/* hu */ { IDS_SELECT_CARTRIDGE_IMAGE_HU, "Cartridge f�jl kiv�laszt�sa" },
/* it */ { IDS_SELECT_CARTRIDGE_IMAGE_IT, "Seleziona file cartuccia" },
/* ko */ { IDS_SELECT_CARTRIDGE_IMAGE_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_CARTRIDGE_IMAGE_NL, "Selecteer cartridge bestand" },
/* pl */ { IDS_SELECT_CARTRIDGE_IMAGE_PL, "Wybierz plik kartrid�a" },
/* ru */ { IDS_SELECT_CARTRIDGE_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_CARTRIDGE_IMAGE_SV, "V�lj insticksmodulfil" },
/* tr */ { IDS_SELECT_CARTRIDGE_IMAGE_TR, "Kartu� dosyas�n� se�" },

/* en */ { IDS_SID_CART,    "SID cartridge" },
/* da */ { IDS_SID_CART_DA, "SID-cartridge" },
/* de */ { IDS_SID_CART_DE, "SID Modul" },
/* es */ { IDS_SID_CART_ES, "Cartucho SID" },
/* fr */ { IDS_SID_CART_FR, "" },  /* fuzzy */
/* hu */ { IDS_SID_CART_HU, "SID cartridge" },
/* it */ { IDS_SID_CART_IT, "Cartuccia SID" },
/* ko */ { IDS_SID_CART_KO, "SID īƮ����" },
/* nl */ { IDS_SID_CART_NL, "SID cartridge" },
/* pl */ { IDS_SID_CART_PL, "Kartrid� SID" },
/* ru */ { IDS_SID_CART_RU, "�������� SID" },
/* sv */ { IDS_SID_CART_SV, "SID-insticksmodul" },
/* tr */ { IDS_SID_CART_TR, "SID kartu�u" },

/* en */ { IDS_SID_ENGINE_MODEL,    "SID model" },
/* da */ { IDS_SID_ENGINE_MODEL_DA, "SID-model" },
/* de */ { IDS_SID_ENGINE_MODEL_DE, "SID Modell" },
/* es */ { IDS_SID_ENGINE_MODEL_ES, "Modelo SID" },
/* fr */ { IDS_SID_ENGINE_MODEL_FR, "" },  /* fuzzy */
/* hu */ { IDS_SID_ENGINE_MODEL_HU, "SID modell" },
/* it */ { IDS_SID_ENGINE_MODEL_IT, "Modello SID" },
/* ko */ { IDS_SID_ENGINE_MODEL_KO, "SID ��" },
/* nl */ { IDS_SID_ENGINE_MODEL_NL, "SID model" },
/* pl */ { IDS_SID_ENGINE_MODEL_PL, "Model SID-a" },
/* ru */ { IDS_SID_ENGINE_MODEL_RU, "������ ��������������� SID" },
/* sv */ { IDS_SID_ENGINE_MODEL_SV, "SID-modell" },
/* tr */ { IDS_SID_ENGINE_MODEL_TR, "SID modeli" },

/* en */ { IDS_SID_ADDRESS,    "SID address" },
/* da */ { IDS_SID_ADDRESS_DA, "SID-adresse" },
/* de */ { IDS_SID_ADDRESS_DE, "SID Adresse" },
/* es */ { IDS_SID_ADDRESS_ES, "Direcci�n SID" },
/* fr */ { IDS_SID_ADDRESS_FR, "" },  /* fuzzy */
/* hu */ { IDS_SID_ADDRESS_HU, "SID c�m" },
/* it */ { IDS_SID_ADDRESS_IT, "Indirizzo SID" },
/* ko */ { IDS_SID_ADDRESS_KO, "SID �ּ�" },
/* nl */ { IDS_SID_ADDRESS_NL, "SID adres" },
/* pl */ { IDS_SID_ADDRESS_PL, "Adres SID" },
/* ru */ { IDS_SID_ADDRESS_RU, "����� SID" },
/* sv */ { IDS_SID_ADDRESS_SV, "SID-adress" },
/* tr */ { IDS_SID_ADDRESS_TR, "SID adresi" },

/* en */ { IDS_SID_CLOCK,    "SID clock" },
/* da */ { IDS_SID_CLOCK_DA, "SID-klok" },
/* de */ { IDS_SID_CLOCK_DE, "SID Takt" },
/* es */ { IDS_SID_CLOCK_ES, "Reloj SID" },
/* fr */ { IDS_SID_CLOCK_FR, "Horloge SID" },
/* hu */ { IDS_SID_CLOCK_HU, "SID �rajel" },
/* it */ { IDS_SID_CLOCK_IT, "Clock SID" },
/* ko */ { IDS_SID_CLOCK_KO, "SID Ŭ��" },
/* nl */ { IDS_SID_CLOCK_NL, "SID klok" },
/* pl */ { IDS_SID_CLOCK_PL, "Zegar SID" },
/* ru */ { IDS_SID_CLOCK_RU, "SID �����" },
/* sv */ { IDS_SID_CLOCK_SV, "SID-klocka" },
/* tr */ { IDS_SID_CLOCK_TR, "SID saati" },

/* en */ { IDS_SID_DIGIBLASTER,    "Digiblaster add-on" },
/* da */ { IDS_SID_DIGIBLASTER_DA, "Digiblaster udviddelse" },
/* de */ { IDS_SID_DIGIBLASTER_DE, "Digiblaster add-on" },
/* es */ { IDS_SID_DIGIBLASTER_ES, "A�adir Digiblaster" },
/* fr */ { IDS_SID_DIGIBLASTER_FR, "" },  /* fuzzy */
/* hu */ { IDS_SID_DIGIBLASTER_HU, "Digiblaster kiterjeszt�s" },
/* it */ { IDS_SID_DIGIBLASTER_IT, "Estensione digiblaster" },
/* ko */ { IDS_SID_DIGIBLASTER_KO, "Digiblaster ���� ��" },
/* nl */ { IDS_SID_DIGIBLASTER_NL, "Digiblaster add-on" },
/* pl */ { IDS_SID_DIGIBLASTER_PL, "Dodatek digiblaster" },
/* ru */ { IDS_SID_DIGIBLASTER_RU, "" },  /* fuzzy */
/* sv */ { IDS_SID_DIGIBLASTER_SV, "Digiblaster-till�gg" },
/* tr */ { IDS_SID_DIGIBLASTER_TR, "Digiblaster eklentisi" },

/* en */ { IDS_SIDCART_SETTINGS,    "SID cart settings" },
/* da */ { IDS_SIDCART_SETTINGS_DA, "SID-cartridgeindstillinger" },
/* de */ { IDS_SIDCART_SETTINGS_DE, "SID Modul Einstellungen" },
/* es */ { IDS_SIDCART_SETTINGS_ES, "Ajustes SID Cart" },
/* fr */ { IDS_SIDCART_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_SIDCART_SETTINGS_HU, "SID k�rtya be�ll�t�sai..." },
/* it */ { IDS_SIDCART_SETTINGS_IT, "Impostazioni cartuccia SID" },
/* ko */ { IDS_SIDCART_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_SIDCART_SETTINGS_NL, "SID cart instellingen" },
/* pl */ { IDS_SIDCART_SETTINGS_PL, "Ustawienia karty SID" },
/* ru */ { IDS_SIDCART_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_SIDCART_SETTINGS_SV, "SID-modulinst�llningarg" },
/* tr */ { IDS_SIDCART_SETTINGS_TR, "SID kartu�u ayarlar�" },

/* en */ { IDS_LOAD_FLIP_LIST_FILE,    "Load flip list file" },
/* da */ { IDS_LOAD_FLIP_LIST_FILE_DA, "Indl�s bladrelistefil" },
/* de */ { IDS_LOAD_FLIP_LIST_FILE_DE, "Fliplist Datei laden" },
/* es */ { IDS_LOAD_FLIP_LIST_FILE_ES, "Cargar lista de ficheros a commutar" },
/* fr */ { IDS_LOAD_FLIP_LIST_FILE_FR, "Charger un fichier de groupement de disques" },
/* hu */ { IDS_LOAD_FLIP_LIST_FILE_HU, "Lemezlista bet�lt�se" },
/* it */ { IDS_LOAD_FLIP_LIST_FILE_IT, "Carica file fliplist" },
/* ko */ { IDS_LOAD_FLIP_LIST_FILE_KO, "�ø� ����Ʈ ���� �ҷ�����" },
/* nl */ { IDS_LOAD_FLIP_LIST_FILE_NL, "Laad fliplijstbestand" },
/* pl */ { IDS_LOAD_FLIP_LIST_FILE_PL, "Wczytaj plik listy podmiany no�nik�w" },
/* ru */ { IDS_LOAD_FLIP_LIST_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_LOAD_FLIP_LIST_FILE_SV, "L�s vallistefil" },
/* tr */ { IDS_LOAD_FLIP_LIST_FILE_TR, "S�ralama listesi dosyas�n� y�kle" },

/* en */ { IDS_CANNOT_READ_FLIP_LIST,    "Cannot read flip list file" },
/* da */ { IDS_CANNOT_READ_FLIP_LIST_DA, "Kunne ikke l�se bladrelistefil" },
/* de */ { IDS_CANNOT_READ_FLIP_LIST_DE, "Lesen von Fliplist Datei fehlgeschlagen" },
/* es */ { IDS_CANNOT_READ_FLIP_LIST_ES, "No puedo leer fichero de lista de intercambio" },
/* fr */ { IDS_CANNOT_READ_FLIP_LIST_FR, "" },  /* fuzzy */
/* hu */ { IDS_CANNOT_READ_FLIP_LIST_HU, "Nem lehet olvasni a lemezlista f�jlt" },
/* it */ { IDS_CANNOT_READ_FLIP_LIST_IT, "Non � possibile caricare il file della flip list" },
/* ko */ { IDS_CANNOT_READ_FLIP_LIST_KO, "�ø� ����Ʈ ������ ������ �����ϴ�" },
/* nl */ { IDS_CANNOT_READ_FLIP_LIST_NL, "Kan het fliplijstbestand niet lezen" },
/* pl */ { IDS_CANNOT_READ_FLIP_LIST_PL, "Nie mo�na odczyta� pliku listy podmiany no�nik�w" },
/* ru */ { IDS_CANNOT_READ_FLIP_LIST_RU, "" },  /* fuzzy */
/* sv */ { IDS_CANNOT_READ_FLIP_LIST_SV, "Kunde inte l�sa vallistefil" },
/* tr */ { IDS_CANNOT_READ_FLIP_LIST_TR, "S�ralama listesi dosyas� okunamad�" },

/* en */ { IDS_SAVE_FLIP_LIST_FILE,    "Save flip list file" },
/* da */ { IDS_SAVE_FLIP_LIST_FILE_DA, "Gem bladrelistefil" },
/* de */ { IDS_SAVE_FLIP_LIST_FILE_DE, "Fliplist Datei speichern" },
/* es */ { IDS_SAVE_FLIP_LIST_FILE_ES, "Grabar lista de ficheros a commutar" },
/* fr */ { IDS_SAVE_FLIP_LIST_FILE_FR, "Enregistrer le fichier de groupement de disques actuel" },
/* hu */ { IDS_SAVE_FLIP_LIST_FILE_HU, "Lemezlista ment�se f�jlba" },
/* it */ { IDS_SAVE_FLIP_LIST_FILE_IT, "Salva file fliplist" },
/* ko */ { IDS_SAVE_FLIP_LIST_FILE_KO, "�ø� ����Ʈ ���� �����ϱ�" },
/* nl */ { IDS_SAVE_FLIP_LIST_FILE_NL, "Fliplijstbestand opslaan" },
/* pl */ { IDS_SAVE_FLIP_LIST_FILE_PL, "Zapisz plik listy podmiany no�nik�w" },
/* ru */ { IDS_SAVE_FLIP_LIST_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_FLIP_LIST_FILE_SV, "Spara vallistefil" },
/* tr */ { IDS_SAVE_FLIP_LIST_FILE_TR, "S�ralama listesi dosyas�n� kaydet" },

/* en */ { IDS_CANNOT_WRITE_FLIP_LIST,    "Cannot write flip list file" },
/* da */ { IDS_CANNOT_WRITE_FLIP_LIST_DA, "Kunne ikke skrive bladrelistefil" },
/* de */ { IDS_CANNOT_WRITE_FLIP_LIST_DE, "Schreiben von Fliplist Datei fehlgeschlagen" },
/* es */ { IDS_CANNOT_WRITE_FLIP_LIST_ES, "No puedo grabar fichero de lista de intercambio" },
/* fr */ { IDS_CANNOT_WRITE_FLIP_LIST_FR, "Impossible d'�crire le fichier de groupement de disques" },
/* hu */ { IDS_CANNOT_WRITE_FLIP_LIST_HU, "Nem siker�lt a lemezlist�t f�jlba �rni" },
/* it */ { IDS_CANNOT_WRITE_FLIP_LIST_IT, "Non � possibile scrivere il file della flip list" },
/* ko */ { IDS_CANNOT_WRITE_FLIP_LIST_KO, "�ø� ����Ʈ ������ ���� �����ϴ�" },
/* nl */ { IDS_CANNOT_WRITE_FLIP_LIST_NL, "Kan fliplijstbestand niet schrijven" },
/* pl */ { IDS_CANNOT_WRITE_FLIP_LIST_PL, "Nie mo�na zapisa� pliku listy wymiany no�nik�w" },
/* ru */ { IDS_CANNOT_WRITE_FLIP_LIST_RU, "" },  /* fuzzy */
/* sv */ { IDS_CANNOT_WRITE_FLIP_LIST_SV, "Kan inte skriva vallistefil" },
/* tr */ { IDS_CANNOT_WRITE_FLIP_LIST_TR, "S�ralama listesi dosyas� yaz�lamad�" },

/* en */ { IDS_ATTACH_FUNCTION_LOW_CART,    "Attach cartridge image for Function Low" },
/* da */ { IDS_ATTACH_FUNCTION_LOW_CART_DA, "Tilslut cartridge for Function Lav" },
/* de */ { IDS_ATTACH_FUNCTION_LOW_CART_DE, "Funktions ROM (low) Erweiterungsmodul einlegen" },
/* es */ { IDS_ATTACH_FUNCTION_LOW_CART_ES, "Insertar imagen cartucho para funci�n baja" },
/* fr */ { IDS_ATTACH_FUNCTION_LOW_CART_FR, "Ins�rer une cartouche Fonction basse" },
/* hu */ { IDS_ATTACH_FUNCTION_LOW_CART_HU, "Cartridge k�pm�s csatol�sa Function Low-hoz" },
/* it */ { IDS_ATTACH_FUNCTION_LOW_CART_IT, "Seleziona immagine cartuccia per la Function Low" },
/* ko */ { IDS_ATTACH_FUNCTION_LOW_CART_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACH_FUNCTION_LOW_CART_NL, "Koppel cartridge bestand voor 'Function Low'" },
/* pl */ { IDS_ATTACH_FUNCTION_LOW_CART_PL, "Zamontuj obraz kartrid�a do Function Low" },
/* ru */ { IDS_ATTACH_FUNCTION_LOW_CART_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_FUNCTION_LOW_CART_SV, "Anslut insticksmodulfil f�r funktion l�g" },
/* tr */ { IDS_ATTACH_FUNCTION_LOW_CART_TR, "Function Low i�in kartu� imaj� yerle�tirin" },

/* en */ { IDS_ATTACH_FUNCTION_HIGH_CART,    "Attach cartridge image for Function High" },
/* da */ { IDS_ATTACH_FUNCTION_HIGH_CART_DA, "Tilslut cartridge for Function H�j" },
/* de */ { IDS_ATTACH_FUNCTION_HIGH_CART_DE, "Funktions ROM (high) Erweiterungsmodul einlegen" },
/* es */ { IDS_ATTACH_FUNCTION_HIGH_CART_ES, "Insertar imagen cartucho para funci�n alta" },
/* fr */ { IDS_ATTACH_FUNCTION_HIGH_CART_FR, "Ins�rer une cartouche Fonction haute" },
/* hu */ { IDS_ATTACH_FUNCTION_HIGH_CART_HU, "Cartridge k�pm�s csatol�sa Function High-hez" },
/* it */ { IDS_ATTACH_FUNCTION_HIGH_CART_IT, "Seleziona immagine cartuccia per la Function High" },
/* ko */ { IDS_ATTACH_FUNCTION_HIGH_CART_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACH_FUNCTION_HIGH_CART_NL, "Koppel cartridge bestand voor 'Function High'" },
/* pl */ { IDS_ATTACH_FUNCTION_HIGH_CART_PL, "Zamontuj obraz kartrid�a do Function High" },
/* ru */ { IDS_ATTACH_FUNCTION_HIGH_CART_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_FUNCTION_HIGH_CART_SV, "Anslut insticksmodulfil f�r funktion h�g" },
/* tr */ { IDS_ATTACH_FUNCTION_HIGH_CART_TR, "Function High i�in kartu� imaj� yerle�tirin" },

/* en */ { IDS_ATTACH_CART1_LOW,    "Attach cartridge image for Cartridge1 Low" },
/* da */ { IDS_ATTACH_CART1_LOW_DA, "Tilslut cartridge image for Cartridge1 Lav" },
/* de */ { IDS_ATTACH_CART1_LOW_DE, "Cartridge1 (low) Erweiterungsmodul einlegen" },
/* es */ { IDS_ATTACH_CART1_LOW_ES, "Insertar imagen cartucho para cartucho1 bajo" },
/* fr */ { IDS_ATTACH_CART1_LOW_FR, "Ins�rer une cartouche pour Cartouche1 basse" },
/* hu */ { IDS_ATTACH_CART1_LOW_HU, "Cartridge k�pm�s csatol�sa als� Cartridge1-hez" },
/* it */ { IDS_ATTACH_CART1_LOW_IT, "Seleziona immagine cartuccia per la Cartridge Low" },
/* ko */ { IDS_ATTACH_CART1_LOW_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACH_CART1_LOW_NL, "Koppel cartridge bestand voor 'Cartridge1 Low'" },
/* pl */ { IDS_ATTACH_CART1_LOW_PL, "Zamontuj obraz kartrid�a do Cartridge1 Low" },
/* ru */ { IDS_ATTACH_CART1_LOW_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_CART1_LOW_SV, "Anslut insticksmodulfil f�r modul1 l�g" },
/* tr */ { IDS_ATTACH_CART1_LOW_TR, "Kartu�1 Low i�in kartu� imaj� yerle�tirin" },

/* en */ { IDS_ATTACH_CART1_HIGH,    "Attach cartridge image for Cartridge1 High" },
/* da */ { IDS_ATTACH_CART1_HIGH_DA, "Tilslut cartridge image for Cartridge1 H�j" },
/* de */ { IDS_ATTACH_CART1_HIGH_DE, "Cartridge1 (high) Erweiterungsmodul einlegen" },
/* es */ { IDS_ATTACH_CART1_HIGH_ES, "Insertar imagen cartucho para cartucho1 alto" },
/* fr */ { IDS_ATTACH_CART1_HIGH_FR, "Ins�rer une cartouche pour Cartouche1 haute" },
/* hu */ { IDS_ATTACH_CART1_HIGH_HU, "Cartridge k�pm�s csatol�sa fels� Cartridge1-hez" },
/* it */ { IDS_ATTACH_CART1_HIGH_IT, "Seleziona immagine cartuccia per la Cartridge1 High" },
/* ko */ { IDS_ATTACH_CART1_HIGH_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACH_CART1_HIGH_NL, "Koppel cartridge bestand voor 'Cartridge1 High'" },
/* pl */ { IDS_ATTACH_CART1_HIGH_PL, "Zamontuj obraz kartrid�a do Cartridge1 High" },
/* ru */ { IDS_ATTACH_CART1_HIGH_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_CART1_HIGH_SV, "Anslut insticksmodulfil f�r modul1 h�g" },
/* tr */ { IDS_ATTACH_CART1_HIGH_TR, "Kartu�1 High i�in kartu� imaj� yerle�tirin" },

/* en */ { IDS_ATTACH_CART2_LOW,    "Attach cartridge image for Cartridge2 Low" },
/* da */ { IDS_ATTACH_CART2_LOW_DA, "Tilslut cartridge image for Cartridge2 Lav" },
/* de */ { IDS_ATTACH_CART2_LOW_DE, "Cartridge2 (low) Erweiterungsmodul einlegen" },
/* es */ { IDS_ATTACH_CART2_LOW_ES, "Insertar imagen cartucho para cartucho2 bajo" },
/* fr */ { IDS_ATTACH_CART2_LOW_FR, "Ins�rer une cartouche pour Cartouche2 basse" },
/* hu */ { IDS_ATTACH_CART2_LOW_HU, "Cartridge k�pm�s csatol�sa als� Cartridge2-h�z" },
/* it */ { IDS_ATTACH_CART2_LOW_IT, "Seleziona immagine cartuccia per la Cartridge2 Low" },
/* ko */ { IDS_ATTACH_CART2_LOW_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACH_CART2_LOW_NL, "Koppel cartridge bestand voor 'Cartridge2 Low'" },
/* pl */ { IDS_ATTACH_CART2_LOW_PL, "Zamontuj obraz kartrid�a do Cartridge2 Low" },
/* ru */ { IDS_ATTACH_CART2_LOW_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_CART2_LOW_SV, "Anslut insticksmodulfil f�r modul2 l�g" },
/* tr */ { IDS_ATTACH_CART2_LOW_TR, "Kartu�2 Low i�in kartu� imaj� yerle�tirin" },

/* en */ { IDS_ATTACH_CART2_HIGH,    "Attach cartridge image for Cartridge2 High" },
/* da */ { IDS_ATTACH_CART2_HIGH_DA, "Tilslut cartridge image for Cartridge2 H�j" },
/* de */ { IDS_ATTACH_CART2_HIGH_DE, "Cartridge1 (high) Erweiterungsmodul einlegen" },
/* es */ { IDS_ATTACH_CART2_HIGH_ES, "Insertar imagen cartucho para cartucho2 alto" },
/* fr */ { IDS_ATTACH_CART2_HIGH_FR, "Ins�rer une cartouche pour Cartouche2 haute" },
/* hu */ { IDS_ATTACH_CART2_HIGH_HU, "Cartridge k�pm�s csatol�sa fels� Cartridge2-h�z" },
/* it */ { IDS_ATTACH_CART2_HIGH_IT, "Seleziona immagine cartuccia per la Cartridge2 High" },
/* ko */ { IDS_ATTACH_CART2_HIGH_KO, "" },  /* fuzzy */
/* nl */ { IDS_ATTACH_CART2_HIGH_NL, "Koppel cartridge bestand voor 'Cartridge2 High'" },
/* pl */ { IDS_ATTACH_CART2_HIGH_PL, "Zamontuj obraz kartrid�a do Cartridge2 High" },
/* ru */ { IDS_ATTACH_CART2_HIGH_RU, "" },  /* fuzzy */
/* sv */ { IDS_ATTACH_CART2_HIGH_SV, "Anslut insticksmodulfil f�r modul2 h�g" },
/* tr */ { IDS_ATTACH_CART2_HIGH_TR, "Kartu�2 High i�in kartu� imaj� yerle�tirin" },

/* en */ { IDS_SAVE_SNAPSHOT_IMAGE,    "Save snapshot image" },
/* da */ { IDS_SAVE_SNAPSHOT_IMAGE_DA, "Gem snapshot" },
/* de */ { IDS_SAVE_SNAPSHOT_IMAGE_DE, "Snapshot Datei speichern" },
/* es */ { IDS_SAVE_SNAPSHOT_IMAGE_ES, "Grabar imagen de volcado de memoria" },
/* fr */ { IDS_SAVE_SNAPSHOT_IMAGE_FR, "Enregistrer le fichier de sauvegarde" },
/* hu */ { IDS_SAVE_SNAPSHOT_IMAGE_HU, "Pillanatk�p f�jl ment�se" },
/* it */ { IDS_SAVE_SNAPSHOT_IMAGE_IT, "Salva immagine snapshot" },
/* ko */ { IDS_SAVE_SNAPSHOT_IMAGE_KO, "������ �̹��� ����" },
/* nl */ { IDS_SAVE_SNAPSHOT_IMAGE_NL, "Momentopnamebestand opslaan" },
/* pl */ { IDS_SAVE_SNAPSHOT_IMAGE_PL, "Zapisz obraz zrzutu" },
/* ru */ { IDS_SAVE_SNAPSHOT_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_SNAPSHOT_IMAGE_SV, "Spara �gonblicksbildfil" },
/* tr */ { IDS_SAVE_SNAPSHOT_IMAGE_TR, "Anl�k g�r�nt� imaj�n� kaydet" },

/* en */ { IDS_LOAD_SNAPSHOT_IMAGE,    "Load snapshot image" },
/* da */ { IDS_LOAD_SNAPSHOT_IMAGE_DA, "Indl�s snapshot" },
/* de */ { IDS_LOAD_SNAPSHOT_IMAGE_DE, "Snapshot laden" },
/* es */ { IDS_LOAD_SNAPSHOT_IMAGE_ES, "Cargar Imagen snapshot" },
/* fr */ { IDS_LOAD_SNAPSHOT_IMAGE_FR, "Charger le fichier de sauvegarde" },
/* hu */ { IDS_LOAD_SNAPSHOT_IMAGE_HU, "Pillanatk�p bet�lt�se" },
/* it */ { IDS_LOAD_SNAPSHOT_IMAGE_IT, "Carica immagine snapshot" },
/* ko */ { IDS_LOAD_SNAPSHOT_IMAGE_KO, "������ �̹��� �ҷ�����" },
/* nl */ { IDS_LOAD_SNAPSHOT_IMAGE_NL, "Laad momentopnamebestand" },
/* pl */ { IDS_LOAD_SNAPSHOT_IMAGE_PL, "Wczytaj obraz zrzutu" },
/* ru */ { IDS_LOAD_SNAPSHOT_IMAGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_LOAD_SNAPSHOT_IMAGE_SV, "L�ser in �gonblicksbild" },
/* tr */ { IDS_LOAD_SNAPSHOT_IMAGE_TR, "Anl�k g�r�nt� imaj�n� y�kle" },

/* en */ { IDS_SAVE_CURRENTLY_ATTACHED_DISKS,    "Save currently attached disk images" },
/* da */ { IDS_SAVE_CURRENTLY_ATTACHED_DISKS_DA, "Gem tilsluttede disk-images" },
/* de */ { IDS_SAVE_CURRENTLY_ATTACHED_DISKS_DE, "Aktuell eingelegte Diskimages speichern" },
/* es */ { IDS_SAVE_CURRENTLY_ATTACHED_DISKS_ES, "Grabar imagenes de disco actualmente insertados" },
/* fr */ { IDS_SAVE_CURRENTLY_ATTACHED_DISKS_FR, "" },  /* fuzzy */
/* hu */ { IDS_SAVE_CURRENTLY_ATTACHED_DISKS_HU, "A jelenleg csatolt lemezek ment�se" },
/* it */ { IDS_SAVE_CURRENTLY_ATTACHED_DISKS_IT, "Salva immagini dischi attualmente selezionati" },
/* ko */ { IDS_SAVE_CURRENTLY_ATTACHED_DISKS_KO, "���� �پ��ִ� ��ũ �̹��� ����" },
/* nl */ { IDS_SAVE_CURRENTLY_ATTACHED_DISKS_NL, "Opslaan huidige gekoppelde schijfbestanden" },
/* pl */ { IDS_SAVE_CURRENTLY_ATTACHED_DISKS_PL, "Zapisz zaontowane obrazy dyskietek" },
/* ru */ { IDS_SAVE_CURRENTLY_ATTACHED_DISKS_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_CURRENTLY_ATTACHED_DISKS_SV, "Spara anslutna diskettavbildningar" },
/* tr */ { IDS_SAVE_CURRENTLY_ATTACHED_DISKS_TR, "Halihaz�rda yerle�tirilmi� disk imajlar�n� kaydet" },

/* en */ { IDS_SAVE_CURRENTLY_ATTACHED_ROMS,    "Save currently loaded ROM images" },
/* da */ { IDS_SAVE_CURRENTLY_ATTACHED_ROMS_DA, "Gem tilsluttede ROM-images" },
/* de */ { IDS_SAVE_CURRENTLY_ATTACHED_ROMS_DE, "Aktuelle ROMs speichern" },
/* es */ { IDS_SAVE_CURRENTLY_ATTACHED_ROMS_ES, "Grabar imagenes ROM actualmente cargadas" },
/* fr */ { IDS_SAVE_CURRENTLY_ATTACHED_ROMS_FR, "Sauvegarder les images ROM pr�sentement charg�s" },
/* hu */ { IDS_SAVE_CURRENTLY_ATTACHED_ROMS_HU, "A jelenleg bet�lt�tt ROM-ok ment�se" },
/* it */ { IDS_SAVE_CURRENTLY_ATTACHED_ROMS_IT, "Salva immagini ROM attualmente caricate" },
/* ko */ { IDS_SAVE_CURRENTLY_ATTACHED_ROMS_KO, "���� �ҷ����� �� ROM �̹��� ����" },
/* nl */ { IDS_SAVE_CURRENTLY_ATTACHED_ROMS_NL, "Opslaan huidig gekoppelde ROMs" },
/* pl */ { IDS_SAVE_CURRENTLY_ATTACHED_ROMS_PL, "Zapisz wczytane obrazy ROM" },
/* ru */ { IDS_SAVE_CURRENTLY_ATTACHED_ROMS_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_CURRENTLY_ATTACHED_ROMS_SV, "Spara inl�sta ROM-avbildningar" },
/* tr */ { IDS_SAVE_CURRENTLY_ATTACHED_ROMS_TR, "Halihaz�rda y�klenmi� ROM imajlar�n� kaydet" },

/* en */ { IDS_CANNOT_WRITE_SNAPSHOT_S,    "Cannot write snapshot file `%s'." },
/* da */ { IDS_CANNOT_WRITE_SNAPSHOT_S_DA, "Kunne ikke gemme snapshot \"%s\"." },
/* de */ { IDS_CANNOT_WRITE_SNAPSHOT_S_DE, "Kann Snapshot Datei `%s' nicht speichern." },
/* es */ { IDS_CANNOT_WRITE_SNAPSHOT_S_ES, "No puedo grabar imagen de volcado de memoria `%s'." },
/* fr */ { IDS_CANNOT_WRITE_SNAPSHOT_S_FR, "" },  /* fuzzy */
/* hu */ { IDS_CANNOT_WRITE_SNAPSHOT_S_HU, "Nem siker�lt a pillanatk�p �r�sa %s f�jlba." },
/* it */ { IDS_CANNOT_WRITE_SNAPSHOT_S_IT, "Non � possibile scrivere il file di snapshot `%s'." },
/* ko */ { IDS_CANNOT_WRITE_SNAPSHOT_S_KO, "������ ���� `%s' �� ���� �����ϴ�." },
/* nl */ { IDS_CANNOT_WRITE_SNAPSHOT_S_NL, "Kan momentopnamebestand `%s' niet schrijven." },
/* pl */ { IDS_CANNOT_WRITE_SNAPSHOT_S_PL, "Nie mo�na zapisa� pliku zrzutu '%s'" },
/* ru */ { IDS_CANNOT_WRITE_SNAPSHOT_S_RU, "" },  /* fuzzy */
/* sv */ { IDS_CANNOT_WRITE_SNAPSHOT_S_SV, "Kan inte skriva �gonblicksbildfil \"%s\"." },
/* tr */ { IDS_CANNOT_WRITE_SNAPSHOT_S_TR, "Anl�k g�r�nt� dosyas� yaz�lamad� `%s'." },

/* en */ { IDS_CANNOT_READ_SNAPSHOT_IMG,    "Cannot read snapshot image" },
/* da */ { IDS_CANNOT_READ_SNAPSHOT_IMG_DA, "Kunne ikke indl�se snapshot fil" },
/* de */ { IDS_CANNOT_READ_SNAPSHOT_IMG_DE, "Kann Snapshot Datei nicht laden" },
/* es */ { IDS_CANNOT_READ_SNAPSHOT_IMG_ES, "No puedo leer fichero de volcado de memoria" },
/* fr */ { IDS_CANNOT_READ_SNAPSHOT_IMG_FR, "Impossible de charger l'instantan�." },
/* hu */ { IDS_CANNOT_READ_SNAPSHOT_IMG_HU, "A pillanatk�p f�jl nem olvashat�" },
/* it */ { IDS_CANNOT_READ_SNAPSHOT_IMG_IT, "Non � possibile leggere l'immagine dello snapshot" },
/* ko */ { IDS_CANNOT_READ_SNAPSHOT_IMG_KO, "���Ǽ� ������ ������ �����ϴ�" },
/* nl */ { IDS_CANNOT_READ_SNAPSHOT_IMG_NL, "Kan momentopnamebestand niet lezen" },
/* pl */ { IDS_CANNOT_READ_SNAPSHOT_IMG_PL, "Nie mo�na wczyta� obrazu zrzutu" },
/* ru */ { IDS_CANNOT_READ_SNAPSHOT_IMG_RU, "" },  /* fuzzy */
/* sv */ { IDS_CANNOT_READ_SNAPSHOT_IMG_SV, "Kan inte l�sa in �gonblicksbildfil" },
/* tr */ { IDS_CANNOT_READ_SNAPSHOT_IMG_TR, "Anl�k g�r�nt� dosyas� okunamad�." },

/* en */ { IDS_SNAPSHOT_FILE,    "snapshot file" },
/* da */ { IDS_SNAPSHOT_FILE_DA, "snapshot-fil" },
/* de */ { IDS_SNAPSHOT_FILE_DE, "Snapshot Datei" },
/* es */ { IDS_SNAPSHOT_FILE_ES, "Fichero volcado memoria" },
/* fr */ { IDS_SNAPSHOT_FILE_FR, "Fichier de sauvegarde" },
/* hu */ { IDS_SNAPSHOT_FILE_HU, "pillanatk�p f�jl" },
/* it */ { IDS_SNAPSHOT_FILE_IT, "File snapshot" },
/* ko */ { IDS_SNAPSHOT_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDS_SNAPSHOT_FILE_NL, "momentopnamebestand" },
/* pl */ { IDS_SNAPSHOT_FILE_PL, "plik zrzutu" },
/* ru */ { IDS_SNAPSHOT_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SNAPSHOT_FILE_SV, "�gonblicksbildfil" },
/* tr */ { IDS_SNAPSHOT_FILE_TR, "Anl�k g�r�nt� dosyas�" },

/* en */ { IDS_SELECT_SNAPSHOT_FILE,    "Select snapshot file" },
/* da */ { IDS_SELECT_SNAPSHOT_FILE_DA, "V�lg snapshot-fil" },
/* de */ { IDS_SELECT_SNAPSHOT_FILE_DE, "Snapshot Datei w�hlen" },
/* es */ { IDS_SELECT_SNAPSHOT_FILE_ES, "Seleccionar fichero volcado memoria" },
/* fr */ { IDS_SELECT_SNAPSHOT_FILE_FR, "S�lectionner le fichier de sauvegarde" },
/* hu */ { IDS_SELECT_SNAPSHOT_FILE_HU, "V�lasszon pillanatk�p f�jlt" },
/* it */ { IDS_SELECT_SNAPSHOT_FILE_IT, "Seleziona file snapshot" },
/* ko */ { IDS_SELECT_SNAPSHOT_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_SNAPSHOT_FILE_NL, "Selecteer momentopnamebestand" },
/* pl */ { IDS_SELECT_SNAPSHOT_FILE_PL, "Wybierz plik zrzutu" },
/* ru */ { IDS_SELECT_SNAPSHOT_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_SNAPSHOT_FILE_SV, "V�lj �gonblicksbildfil" },
/* tr */ { IDS_SELECT_SNAPSHOT_FILE_TR, "Anl�k g�r�nt� dosyas� se�in" },

/* en */ { IDS_CRT_EMULATION,    "CRT emulation" },
/* da */ { IDS_CRT_EMULATION_DA, "CRT-emulering" },
/* de */ { IDS_CRT_EMULATION_DE, "CRT Emulation" },
/* es */ { IDS_CRT_EMULATION_ES, "Emulaci�n CRT" },
/* fr */ { IDS_CRT_EMULATION_FR, "" },  /* fuzzy */
/* hu */ { IDS_CRT_EMULATION_HU, "" },  /* fuzzy */
/* it */ { IDS_CRT_EMULATION_IT, "Emulazione CRT" },
/* ko */ { IDS_CRT_EMULATION_KO, "����� ���� �͹̳� ���ķ�����" },
/* nl */ { IDS_CRT_EMULATION_NL, "CRT emulatie" },
/* pl */ { IDS_CRT_EMULATION_PL, "Emulacja CRT" },
/* ru */ { IDS_CRT_EMULATION_RU, "" },  /* fuzzy */
/* sv */ { IDS_CRT_EMULATION_SV, "CRT-emulering" },
/* tr */ { IDS_CRT_EMULATION_TR, "CRT em�lasyonu" },

/* en */ { IDS_SCALE2X,    "Scale2x" },
/* da */ { IDS_SCALE2X_DA, "Scale2x" },
/* de */ { IDS_SCALE2X_DE, "Scale2x" },
/* es */ { IDS_SCALE2X_ES, "Escala 2x" },
/* fr */ { IDS_SCALE2X_FR, "Scale2x" },
/* hu */ { IDS_SCALE2X_HU, "�lsim�t�s" },
/* it */ { IDS_SCALE2X_IT, "Scale2x" },
/* ko */ { IDS_SCALE2X_KO, "Scale2x" },
/* nl */ { IDS_SCALE2X_NL, "Schaal2x" },
/* pl */ { IDS_SCALE2X_PL, "Skalowanie2x" },
/* ru */ { IDS_SCALE2X_RU, "" },  /* fuzzy */
/* sv */ { IDS_SCALE2X_SV, "Scale2x" },
/* tr */ { IDS_SCALE2X_TR, "2x Geni�let" },

/* en */ { IDS_RENDER_FILTER,    "Render filter" },
/* da */ { IDS_RENDER_FILTER_DA, "Renderingsfilter" },
/* de */ { IDS_RENDER_FILTER_DE, "Render Filter" },
/* es */ { IDS_RENDER_FILTER_ES, "Filtro de renderizado" },
/* fr */ { IDS_RENDER_FILTER_FR, "" },  /* fuzzy */
/* hu */ { IDS_RENDER_FILTER_HU, "" },  /* fuzzy */
/* it */ { IDS_RENDER_FILTER_IT, "Filtro renderer" },
/* ko */ { IDS_RENDER_FILTER_KO, "���� ����" },
/* nl */ { IDS_RENDER_FILTER_NL, "Render filter" },
/* pl */ { IDS_RENDER_FILTER_PL, "Filtr renderera" },
/* ru */ { IDS_RENDER_FILTER_RU, "" },  /* fuzzy */
/* sv */ { IDS_RENDER_FILTER_SV, "Rendrerarfilter" },
/* tr */ { IDS_RENDER_FILTER_TR, "�mge olu�turma filtresi" },

/* en */ { IDS_EXTERNAL_PALETTE_SELECT,    "Select External Palette file" },
/* da */ { IDS_EXTERNAL_PALETTE_SELECT_DA, "Brug ekstern palette-fil" },
/* de */ { IDS_EXTERNAL_PALETTE_SELECT_DE, "Benutze externe Palette (Datei)" },
/* es */ { IDS_EXTERNAL_PALETTE_SELECT_ES, "Seleccionar fichero paleta externa" },
/* fr */ { IDS_EXTERNAL_PALETTE_SELECT_FR, "Utiliser une palette externe (fichier)" },
/* hu */ { IDS_EXTERNAL_PALETTE_SELECT_HU, "V�lasszon k�ls� paletta f�jlt" },
/* it */ { IDS_EXTERNAL_PALETTE_SELECT_IT, "Seleziona file palette esterna" },
/* ko */ { IDS_EXTERNAL_PALETTE_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_EXTERNAL_PALETTE_SELECT_NL, "Selecteer extern paletbestand" },
/* pl */ { IDS_EXTERNAL_PALETTE_SELECT_PL, "Wybierz plik zewn�trznej palety kolor�w" },
/* ru */ { IDS_EXTERNAL_PALETTE_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_EXTERNAL_PALETTE_SELECT_SV, "Anv�nd en extern palett (fil)" },
/* tr */ { IDS_EXTERNAL_PALETTE_SELECT_TR, "Harici Palet dosyas� se�in" },

/* en */ { IDS_GAMMA_0_4,    "Gamma (0..4)" },
/* da */ { IDS_GAMMA_0_4_DA, "Gamma (0..4)" },
/* de */ { IDS_GAMMA_0_4_DE, "Gamma (0..4)" },
/* es */ { IDS_GAMMA_0_4_ES, "Gamma (0..4)" },
/* fr */ { IDS_GAMMA_0_4_FR, "Intensit� (0..4)" },
/* hu */ { IDS_GAMMA_0_4_HU, "Gamma (0..4)" },
/* it */ { IDS_GAMMA_0_4_IT, "Gamma (0..4)" },
/* ko */ { IDS_GAMMA_0_4_KO, "���� (0..4)" },
/* nl */ { IDS_GAMMA_0_4_NL, "Gamma (0..4)" },
/* pl */ { IDS_GAMMA_0_4_PL, "Gamma (0..4)" },
/* ru */ { IDS_GAMMA_0_4_RU, "" },  /* fuzzy */
/* sv */ { IDS_GAMMA_0_4_SV, "Gamma (0..4)" },
/* tr */ { IDS_GAMMA_0_4_TR, "Gama (0..4)" },

/* en */ { IDS_SCANLINE_SHADE_0_1,    "Scanline shade (0..1)" },
/* da */ { IDS_SCANLINE_SHADE_0_1_DA, "Skanlinjeskygge (0..1)" },
/* de */ { IDS_SCANLINE_SHADE_0_1_DE, "Scanline Schatten (0..1)" },
/* es */ { IDS_SCANLINE_SHADE_0_1_ES, "Sombra linea de escaneo (0..1)" },
/* fr */ { IDS_SCANLINE_SHADE_0_1_FR, "" },  /* fuzzy */
/* hu */ { IDS_SCANLINE_SHADE_0_1_HU, "" },  /* fuzzy */
/* it */ { IDS_SCANLINE_SHADE_0_1_IT, "Ombra scanline (0..1)" },
/* ko */ { IDS_SCANLINE_SHADE_0_1_KO, "�ֻ缱 ������ (0..1)" },
/* nl */ { IDS_SCANLINE_SHADE_0_1_NL, "Scanlijnschaduw (0..1)" },
/* pl */ { IDS_SCANLINE_SHADE_0_1_PL, "Cieniowane scanline (0..1)" },
/* ru */ { IDS_SCANLINE_SHADE_0_1_RU, "" },  /* fuzzy */
/* sv */ { IDS_SCANLINE_SHADE_0_1_SV, "Skuggning av skannlinjer (0..1)" },
/* tr */ { IDS_SCANLINE_SHADE_0_1_TR, "Tarama sat�r� n�ans� (0..1)" },

/* en */ { IDS_BLUR_0_1,    "Blur (0..1)" },
/* da */ { IDS_BLUR_0_1_DA, "Udtv�ring (0..1)" },
/* de */ { IDS_BLUR_0_1_DE, "Unsch�rfe (0..1)" },
/* es */ { IDS_BLUR_0_1_ES, "Blur (0..1)" },
/* fr */ { IDS_BLUR_0_1_FR, "" },  /* fuzzy */
/* hu */ { IDS_BLUR_0_1_HU, "" },  /* fuzzy */
/* it */ { IDS_BLUR_0_1_IT, "Sfuocatura (0..1)" },
/* ko */ { IDS_BLUR_0_1_KO, "�帴�� (0..1)" },
/* nl */ { IDS_BLUR_0_1_NL, "Wazigheid (0..1)" },
/* pl */ { IDS_BLUR_0_1_PL, "Rozmycie (0..1)" },
/* ru */ { IDS_BLUR_0_1_RU, "" },  /* fuzzy */
/* sv */ { IDS_BLUR_0_1_SV, "Suddighet (0..1)" },
/* tr */ { IDS_BLUR_0_1_TR, "Bulan�kl�k (0..1)" },

/* en */ { IDS_TINT_0_2,    "Tint (0..2)" },
/* da */ { IDS_TINT_0_2_DA, "Farvetone (0..2)" },
/* de */ { IDS_TINT_0_2_DE, "Farbton (0..2)" },
/* es */ { IDS_TINT_0_2_ES, "Matiz (0..2)" },
/* fr */ { IDS_TINT_0_2_FR, "" },  /* fuzzy */
/* hu */ { IDS_TINT_0_2_HU, "Sz�n (0..2)" },
/* it */ { IDS_TINT_0_2_IT, "Sfumatura (0..2)" },
/* ko */ { IDS_TINT_0_2_KO, "ƾƮ (0..2)" },
/* nl */ { IDS_TINT_0_2_NL, "Tint (0..2)" },
/* pl */ { IDS_TINT_0_2_PL, "Odcie� (0..2)" },
/* ru */ { IDS_TINT_0_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_TINT_0_2_SV, "F�rgton (0..2)" },
/* tr */ { IDS_TINT_0_2_TR, "Ton (0..2)" },

/* en */ { IDS_ODDLINE_PHASE_0_2,    "Odd lines phase (0..2)" },
/* da */ { IDS_ODDLINE_PHASE_0_2_DA, "Fase for ulige linjer (0..2)" },
/* de */ { IDS_ODDLINE_PHASE_0_2_DE, "Ungerade Zeilenphase (0..2)" },
/* es */ { IDS_ODDLINE_PHASE_0_2_ES, "Lineas fase impar (0..2)" },
/* fr */ { IDS_ODDLINE_PHASE_0_2_FR, "" },  /* fuzzy */
/* hu */ { IDS_ODDLINE_PHASE_0_2_HU, "" },  /* fuzzy */
/* it */ { IDS_ODDLINE_PHASE_0_2_IT, "Fase linee dispari (0..2)" },
/* ko */ { IDS_ODDLINE_PHASE_0_2_KO, "" },  /* fuzzy */
/* nl */ { IDS_ODDLINE_PHASE_0_2_NL, "Oneven lijnen fase (0..2)" },
/* pl */ { IDS_ODDLINE_PHASE_0_2_PL, "Faza linii nieparzystych (0..2)" },
/* ru */ { IDS_ODDLINE_PHASE_0_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_ODDLINE_PHASE_0_2_SV, "Fas f�r udda linjer (0..2)" },
/* tr */ { IDS_ODDLINE_PHASE_0_2_TR, "Tek sat�r faz� (0..2)" },

/* en */ { IDS_ODDLINE_OFFSET_0_2,    "Odd lines offset (0..2)" },
/* da */ { IDS_ODDLINE_OFFSET_0_2_DA, "Offset for ulige linjer (0..2)" },
/* de */ { IDS_ODDLINE_OFFSET_0_2_DE, "Ungerader Zeilenoffset (0..2)" },
/* es */ { IDS_ODDLINE_OFFSET_0_2_ES, "Offset lineas impares (0..2)" },
/* fr */ { IDS_ODDLINE_OFFSET_0_2_FR, "" },  /* fuzzy */
/* hu */ { IDS_ODDLINE_OFFSET_0_2_HU, "" },  /* fuzzy */
/* it */ { IDS_ODDLINE_OFFSET_0_2_IT, "Offset linee dispari (0..2)" },
/* ko */ { IDS_ODDLINE_OFFSET_0_2_KO, "Ȧ�� ���� ������ (0..2)" },
/* nl */ { IDS_ODDLINE_OFFSET_0_2_NL, "Oneven lijnen compensatie (0..2)" },
/* pl */ { IDS_ODDLINE_OFFSET_0_2_PL, "Wyr�wnanie linii nieparzystych (0..2)" },
/* ru */ { IDS_ODDLINE_OFFSET_0_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_ODDLINE_OFFSET_0_2_SV, "Utj�mning f�r udda linjer (0..2)" },
/* tr */ { IDS_ODDLINE_OFFSET_0_2_TR, "Tek sat�r ofseti (0..2)" },

/* en */ { IDS_VICII_EXTERNAL_PALETTE,    "External VICII palette" },
/* da */ { IDS_VICII_EXTERNAL_PALETTE_DA, "Ekstern VICII palette" },
/* de */ { IDS_VICII_EXTERNAL_PALETTE_DE, "Externe VICII Palette" },
/* es */ { IDS_VICII_EXTERNAL_PALETTE_ES, "Paleta VICII externa" },
/* fr */ { IDS_VICII_EXTERNAL_PALETTE_FR, "" },  /* fuzzy */
/* hu */ { IDS_VICII_EXTERNAL_PALETTE_HU, "" },  /* fuzzy */
/* it */ { IDS_VICII_EXTERNAL_PALETTE_IT, "Palette VICII esterna" },
/* ko */ { IDS_VICII_EXTERNAL_PALETTE_KO, "" },  /* fuzzy */
/* nl */ { IDS_VICII_EXTERNAL_PALETTE_NL, "Extern VICII palet" },
/* pl */ { IDS_VICII_EXTERNAL_PALETTE_PL, "Zewn�trzna paleta VICII" },
/* ru */ { IDS_VICII_EXTERNAL_PALETTE_RU, "" },  /* fuzzy */
/* sv */ { IDS_VICII_EXTERNAL_PALETTE_SV, "Extern VICII-palett" },
/* tr */ { IDS_VICII_EXTERNAL_PALETTE_TR, "Harici VICII paleti" },

/* en */ { IDS_VIC_EXTERNAL_PALETTE,    "External VIC palette" },
/* da */ { IDS_VIC_EXTERNAL_PALETTE_DA, "Ekstern VIC palette" },
/* de */ { IDS_VIC_EXTERNAL_PALETTE_DE, "Externe VIC Palette" },
/* es */ { IDS_VIC_EXTERNAL_PALETTE_ES, "Paleta VIC externa" },
/* fr */ { IDS_VIC_EXTERNAL_PALETTE_FR, "" },  /* fuzzy */
/* hu */ { IDS_VIC_EXTERNAL_PALETTE_HU, "" },  /* fuzzy */
/* it */ { IDS_VIC_EXTERNAL_PALETTE_IT, "Palette VIC esterna" },
/* ko */ { IDS_VIC_EXTERNAL_PALETTE_KO, "" },  /* fuzzy */
/* nl */ { IDS_VIC_EXTERNAL_PALETTE_NL, "Extern VIC palet" },
/* pl */ { IDS_VIC_EXTERNAL_PALETTE_PL, "Zewn�trzna paleta VIC" },
/* ru */ { IDS_VIC_EXTERNAL_PALETTE_RU, "" },  /* fuzzy */
/* sv */ { IDS_VIC_EXTERNAL_PALETTE_SV, "Extern VIC-palett" },
/* tr */ { IDS_VIC_EXTERNAL_PALETTE_TR, "Harici VIC paleti" },

/* en */ { IDS_TED_EXTERNAL_PALETTE,    "External TED palette" },
/* da */ { IDS_TED_EXTERNAL_PALETTE_DA, "Ekstern TED palette" },
/* de */ { IDS_TED_EXTERNAL_PALETTE_DE, "Externe TED Palette" },
/* es */ { IDS_TED_EXTERNAL_PALETTE_ES, "Paleta TED externa" },
/* fr */ { IDS_TED_EXTERNAL_PALETTE_FR, "" },  /* fuzzy */
/* hu */ { IDS_TED_EXTERNAL_PALETTE_HU, "" },  /* fuzzy */
/* it */ { IDS_TED_EXTERNAL_PALETTE_IT, "Palette TED esterna" },
/* ko */ { IDS_TED_EXTERNAL_PALETTE_KO, "" },  /* fuzzy */
/* nl */ { IDS_TED_EXTERNAL_PALETTE_NL, "Extern TED palet" },
/* pl */ { IDS_TED_EXTERNAL_PALETTE_PL, "Zewn�trzna paleta TED" },
/* ru */ { IDS_TED_EXTERNAL_PALETTE_RU, "" },  /* fuzzy */
/* sv */ { IDS_TED_EXTERNAL_PALETTE_SV, "Extern TED-palett" },
/* tr */ { IDS_TED_EXTERNAL_PALETTE_TR, "Harici TED paleti" },

/* en */ { IDS_VDC_EXTERNAL_PALETTE,    "External VDC palette" },
/* da */ { IDS_VDC_EXTERNAL_PALETTE_DA, "Ekstern VDC palette" },
/* de */ { IDS_VDC_EXTERNAL_PALETTE_DE, "Externe VDC Palette" },
/* es */ { IDS_VDC_EXTERNAL_PALETTE_ES, "Paleta VDC externa" },
/* fr */ { IDS_VDC_EXTERNAL_PALETTE_FR, "" },  /* fuzzy */
/* hu */ { IDS_VDC_EXTERNAL_PALETTE_HU, "" },  /* fuzzy */
/* it */ { IDS_VDC_EXTERNAL_PALETTE_IT, "Palette VDC esterna" },
/* ko */ { IDS_VDC_EXTERNAL_PALETTE_KO, "" },  /* fuzzy */
/* nl */ { IDS_VDC_EXTERNAL_PALETTE_NL, "Extern VDC palet" },
/* pl */ { IDS_VDC_EXTERNAL_PALETTE_PL, "Zewn�trzna paleta VDC" },
/* ru */ { IDS_VDC_EXTERNAL_PALETTE_RU, "" },  /* fuzzy */
/* sv */ { IDS_VDC_EXTERNAL_PALETTE_SV, "Extern VDC-palett" },
/* tr */ { IDS_VDC_EXTERNAL_PALETTE_TR, "Harici VDC paleti" },

/* en */ { IDS_CRTC_EXTERNAL_PALETTE,    "External CRTC palette" },
/* da */ { IDS_CRTC_EXTERNAL_PALETTE_DA, "Ekstern CRTC palette" },
/* de */ { IDS_CRTC_EXTERNAL_PALETTE_DE, "Externe CRTC Palette" },
/* es */ { IDS_CRTC_EXTERNAL_PALETTE_ES, "Paleta CRT externa" },
/* fr */ { IDS_CRTC_EXTERNAL_PALETTE_FR, "" },  /* fuzzy */
/* hu */ { IDS_CRTC_EXTERNAL_PALETTE_HU, "" },  /* fuzzy */
/* it */ { IDS_CRTC_EXTERNAL_PALETTE_IT, "Palette CRTC esterna" },
/* ko */ { IDS_CRTC_EXTERNAL_PALETTE_KO, "" },  /* fuzzy */
/* nl */ { IDS_CRTC_EXTERNAL_PALETTE_NL, "Extern CRTC palet" },
/* pl */ { IDS_CRTC_EXTERNAL_PALETTE_PL, "Zewn�trzna paleta CRTC" },
/* ru */ { IDS_CRTC_EXTERNAL_PALETTE_RU, "" },  /* fuzzy */
/* sv */ { IDS_CRTC_EXTERNAL_PALETTE_SV, "Extern CRTC-palett" },
/* tr */ { IDS_CRTC_EXTERNAL_PALETTE_TR, "Harici CRTC paleti" },

/* en */ { IDS_VICII_PALETTE_NAME,    "VICII palette file" },
/* da */ { IDS_VICII_PALETTE_NAME_DA, "VICII-palettefil" },
/* de */ { IDS_VICII_PALETTE_NAME_DE, "VICII Paletten Datei" },
/* es */ { IDS_VICII_PALETTE_NAME_ES, "Fichero paleta VICII" },
/* fr */ { IDS_VICII_PALETTE_NAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_VICII_PALETTE_NAME_HU, "" },  /* fuzzy */
/* it */ { IDS_VICII_PALETTE_NAME_IT, "File palette VICII" },
/* ko */ { IDS_VICII_PALETTE_NAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_VICII_PALETTE_NAME_NL, "VICII palet bestand" },
/* pl */ { IDS_VICII_PALETTE_NAME_PL, "Plik palety VICII" },
/* ru */ { IDS_VICII_PALETTE_NAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_VICII_PALETTE_NAME_SV, "VICII-palettfil" },
/* tr */ { IDS_VICII_PALETTE_NAME_TR, "VICII palet dosyas�" },

/* en */ { IDS_VIC_PALETTE_NAME,    "VIC palette file" },
/* da */ { IDS_VIC_PALETTE_NAME_DA, "VIC-palettefil" },
/* de */ { IDS_VIC_PALETTE_NAME_DE, "VIC Paletten Datei" },
/* es */ { IDS_VIC_PALETTE_NAME_ES, "Fichero paleta VIC" },
/* fr */ { IDS_VIC_PALETTE_NAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_VIC_PALETTE_NAME_HU, "" },  /* fuzzy */
/* it */ { IDS_VIC_PALETTE_NAME_IT, "File palette VIC" },
/* ko */ { IDS_VIC_PALETTE_NAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_VIC_PALETTE_NAME_NL, "VIC palet bestand" },
/* pl */ { IDS_VIC_PALETTE_NAME_PL, "Plik palety VIC" },
/* ru */ { IDS_VIC_PALETTE_NAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_VIC_PALETTE_NAME_SV, "VIC-palettfil" },
/* tr */ { IDS_VIC_PALETTE_NAME_TR, "VIC palet dosyas�" },

/* en */ { IDS_TED_PALETTE_NAME,    "TED palette file" },
/* da */ { IDS_TED_PALETTE_NAME_DA, "TED-palettefil" },
/* de */ { IDS_TED_PALETTE_NAME_DE, "TED Paletten Datei" },
/* es */ { IDS_TED_PALETTE_NAME_ES, "Fichero paleta TED" },
/* fr */ { IDS_TED_PALETTE_NAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_TED_PALETTE_NAME_HU, "" },  /* fuzzy */
/* it */ { IDS_TED_PALETTE_NAME_IT, "File palette TED" },
/* ko */ { IDS_TED_PALETTE_NAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_TED_PALETTE_NAME_NL, "TED palet bestand" },
/* pl */ { IDS_TED_PALETTE_NAME_PL, "Plik palety TED" },
/* ru */ { IDS_TED_PALETTE_NAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_TED_PALETTE_NAME_SV, "TED-palettfil" },
/* tr */ { IDS_TED_PALETTE_NAME_TR, "TED palet dosyas�" },

/* en */ { IDS_VDC_PALETTE_NAME,    "VDC palette file" },
/* da */ { IDS_VDC_PALETTE_NAME_DA, "VDC-palettefil" },
/* de */ { IDS_VDC_PALETTE_NAME_DE, "VDC Paletten Datei" },
/* es */ { IDS_VDC_PALETTE_NAME_ES, "Fichero paleta VDC" },
/* fr */ { IDS_VDC_PALETTE_NAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_VDC_PALETTE_NAME_HU, "" },  /* fuzzy */
/* it */ { IDS_VDC_PALETTE_NAME_IT, "File palette VDC" },
/* ko */ { IDS_VDC_PALETTE_NAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_VDC_PALETTE_NAME_NL, "VDC palet bestand" },
/* pl */ { IDS_VDC_PALETTE_NAME_PL, "Plik palety VDC" },
/* ru */ { IDS_VDC_PALETTE_NAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_VDC_PALETTE_NAME_SV, "VDC-palettfil" },
/* tr */ { IDS_VDC_PALETTE_NAME_TR, "VDC palet dosyas�" },

/* en */ { IDS_CRTC_PALETTE_NAME,    "CRTC palette file" },
/* da */ { IDS_CRTC_PALETTE_NAME_DA, "CRTC-palettefil" },
/* de */ { IDS_CRTC_PALETTE_NAME_DE, "CRTC Paletten Datei" },
/* es */ { IDS_CRTC_PALETTE_NAME_ES, "Fichero paleta CRT" },
/* fr */ { IDS_CRTC_PALETTE_NAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_CRTC_PALETTE_NAME_HU, "" },  /* fuzzy */
/* it */ { IDS_CRTC_PALETTE_NAME_IT, "File palette CRTC" },
/* ko */ { IDS_CRTC_PALETTE_NAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_CRTC_PALETTE_NAME_NL, "CRTC palet bestand" },
/* pl */ { IDS_CRTC_PALETTE_NAME_PL, "Plik palety CRTC" },
/* ru */ { IDS_CRTC_PALETTE_NAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_CRTC_PALETTE_NAME_SV, "CRTC-palettfil" },
/* tr */ { IDS_CRTC_PALETTE_NAME_TR, "CRTC palet dosyas�" },

/* en */ { IDS_SATURATION_0_2,    "Saturation (0..2)" },
/* da */ { IDS_SATURATION_0_2_DA, "M�ttethed (0..2)" },
/* de */ { IDS_SATURATION_0_2_DE, "S�ttigung (0..2)" },
/* es */ { IDS_SATURATION_0_2_ES, "Saturacion (0..2)" },
/* fr */ { IDS_SATURATION_0_2_FR, "Saturation (0..2)" },
/* hu */ { IDS_SATURATION_0_2_HU, "Tel�tetts�g (0..2)" },
/* it */ { IDS_SATURATION_0_2_IT, "Saturazione (0..2)" },
/* ko */ { IDS_SATURATION_0_2_KO, "��ȭ�� (0..2)" },
/* nl */ { IDS_SATURATION_0_2_NL, "Verzadiging (0..2)" },
/* pl */ { IDS_SATURATION_0_2_PL, "Nasycenie (0..2)" },
/* ru */ { IDS_SATURATION_0_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_SATURATION_0_2_SV, "M�ttnad (0..2)" },
/* tr */ { IDS_SATURATION_0_2_TR, "Doygunluk (0..2)" },

/* en */ { IDS_CONTRAST_0_2,    "Contrast (0..2)" },
/* da */ { IDS_CONTRAST_0_2_DA, "Kontrast (0..2)" },
/* de */ { IDS_CONTRAST_0_2_DE, "Kontrast (0..2)" },
/* es */ { IDS_CONTRAST_0_2_ES, "Contraste (0..2)" },
/* fr */ { IDS_CONTRAST_0_2_FR, "Contraste (0..2)" },
/* hu */ { IDS_CONTRAST_0_2_HU, "Kontraszt (0..2)" },
/* it */ { IDS_CONTRAST_0_2_IT, "Contrasto (0..2)" },
/* ko */ { IDS_CONTRAST_0_2_KO, "��� (0..2)" },
/* nl */ { IDS_CONTRAST_0_2_NL, "Contrast (0..2)" },
/* pl */ { IDS_CONTRAST_0_2_PL, "Kontrast (0..2)" },
/* ru */ { IDS_CONTRAST_0_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_CONTRAST_0_2_SV, "Kontrast (0..2)" },
/* tr */ { IDS_CONTRAST_0_2_TR, "Kar��tl�k (0..2)" },

/* en */ { IDS_BRIGHTNESS_0_2,    "Brightness (0..2)" },
/* da */ { IDS_BRIGHTNESS_0_2_DA, "Lysstyrke (0..2)" },
/* de */ { IDS_BRIGHTNESS_0_2_DE, "Helligkeit (0..2)" },
/* es */ { IDS_BRIGHTNESS_0_2_ES, "Brillo (0..2)" },
/* fr */ { IDS_BRIGHTNESS_0_2_FR, "Luminosit� (0..2)" },
/* hu */ { IDS_BRIGHTNESS_0_2_HU, "F�nyess�g (0..2)" },
/* it */ { IDS_BRIGHTNESS_0_2_IT, "Luminosit� (0..2)" },
/* ko */ { IDS_BRIGHTNESS_0_2_KO, "��� (0..2)" },
/* nl */ { IDS_BRIGHTNESS_0_2_NL, "Helderheid (0..2)" },
/* pl */ { IDS_BRIGHTNESS_0_2_PL, "Jasno�� (0..2)" },
/* ru */ { IDS_BRIGHTNESS_0_2_RU, "" },  /* fuzzy */
/* sv */ { IDS_BRIGHTNESS_0_2_SV, "Ljusstyrka (0..2)" },
/* tr */ { IDS_BRIGHTNESS_0_2_TR, "Parlakl�k (0..2)" },

/* en */ { IDS_VIDEO_SETTINGS,    "Video settings" },
/* da */ { IDS_VIDEO_SETTINGS_DA, "Grafikindstillinger" },
/* de */ { IDS_VIDEO_SETTINGS_DE, "Video Einstellungen" },
/* es */ { IDS_VIDEO_SETTINGS_ES, "Ajustes de video" },
/* fr */ { IDS_VIDEO_SETTINGS_FR, "Param�tres vid�o" },
/* hu */ { IDS_VIDEO_SETTINGS_HU, "Vide� be�ll�t�sai" },
/* it */ { IDS_VIDEO_SETTINGS_IT, "Impostazioni video" },
/* ko */ { IDS_VIDEO_SETTINGS_KO, "���� ����" },
/* nl */ { IDS_VIDEO_SETTINGS_NL, "Video instellingen" },
/* pl */ { IDS_VIDEO_SETTINGS_PL, "Ustawienia wideo" },
/* ru */ { IDS_VIDEO_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_VIDEO_SETTINGS_SV, "Grafikinst�llningar" },
/* tr */ { IDS_VIDEO_SETTINGS_TR, "G�r�nt� ayarlar�" },

/* en */ { IDS_AUTO_FROM_ROM,    "Auto (from ROM)" },
/* da */ { IDS_AUTO_FROM_ROM_DA, "Automatisk (fra ROM)" },
/* de */ { IDS_AUTO_FROM_ROM_DE, "Automatisch (von ROM)" },
/* es */ { IDS_AUTO_FROM_ROM_ES, "Auto (desde ROM)" },
/* fr */ { IDS_AUTO_FROM_ROM_FR, "" },  /* fuzzy */
/* hu */ { IDS_AUTO_FROM_ROM_HU, "Automatikus (ROM-b�l)" },
/* it */ { IDS_AUTO_FROM_ROM_IT, "Auto (dalla ROM)" },
/* ko */ { IDS_AUTO_FROM_ROM_KO, "�ڵ� (ROM ����)" },
/* nl */ { IDS_AUTO_FROM_ROM_NL, "Automatisch (van ROM)" },
/* pl */ { IDS_AUTO_FROM_ROM_PL, "Automatycznie (z ROM)" },
/* ru */ { IDS_AUTO_FROM_ROM_RU, "" },  /* fuzzy */
/* sv */ { IDS_AUTO_FROM_ROM_SV, "Automatisk (fr�n ROM)" },
/* tr */ { IDS_AUTO_FROM_ROM_TR, "Otomatik (ROM'dan)" },

/* en */ { IDS_40_COLUMNS,    "40 Columns" },
/* da */ { IDS_40_COLUMNS_DA, "40 kolonner" },
/* de */ { IDS_40_COLUMNS_DE, "40 Spalten" },
/* es */ { IDS_40_COLUMNS_ES, "40 columnas" },
/* fr */ { IDS_40_COLUMNS_FR, "40 Colonnes" },
/* hu */ { IDS_40_COLUMNS_HU, "40 Oszlop" },
/* it */ { IDS_40_COLUMNS_IT, "40 Colonne" },
/* ko */ { IDS_40_COLUMNS_KO, "40ĭ" },
/* nl */ { IDS_40_COLUMNS_NL, "40 Kolommen" },
/* pl */ { IDS_40_COLUMNS_PL, "40 kolumn" },
/* ru */ { IDS_40_COLUMNS_RU, "" },  /* fuzzy */
/* sv */ { IDS_40_COLUMNS_SV, "40 kolumner" },
/* tr */ { IDS_40_COLUMNS_TR, "40 S�tun" },

/* en */ { IDS_80_COLUMNS,    "80 Columns" },
/* da */ { IDS_80_COLUMNS_DA, "80 kolonner" },
/* de */ { IDS_80_COLUMNS_DE, "80 Spalten" },
/* es */ { IDS_80_COLUMNS_ES, "80 columnas" },
/* fr */ { IDS_80_COLUMNS_FR, "80 Colonnes" },
/* hu */ { IDS_80_COLUMNS_HU, "80 Oszlop" },
/* it */ { IDS_80_COLUMNS_IT, "80 Colonne" },
/* ko */ { IDS_80_COLUMNS_KO, "80ĭ" },
/* nl */ { IDS_80_COLUMNS_NL, "80 Kolommen" },
/* pl */ { IDS_80_COLUMNS_PL, "80 kolumn" },
/* ru */ { IDS_80_COLUMNS_RU, "" },  /* fuzzy */
/* sv */ { IDS_80_COLUMNS_SV, "80 kolumner" },
/* tr */ { IDS_80_COLUMNS_TR, "80 S�tun" },

/* en */ { IDS_256_BYTE,    "256 Byte" },
/* da */ { IDS_256_BYTE_DA, "256 byte" },
/* de */ { IDS_256_BYTE_DE, "256 Byte" },
/* es */ { IDS_256_BYTE_ES, "256 Bytes" },
/* fr */ { IDS_256_BYTE_FR, "256 Octets" },
/* hu */ { IDS_256_BYTE_HU, "256 B�jt" },
/* it */ { IDS_256_BYTE_IT, "256 Byte" },
/* ko */ { IDS_256_BYTE_KO, "256 byte" },
/* nl */ { IDS_256_BYTE_NL, "256 Byte" },
/* pl */ { IDS_256_BYTE_PL, "256 bajt�w" },
/* ru */ { IDS_256_BYTE_RU, "" },  /* fuzzy */
/* sv */ { IDS_256_BYTE_SV, "256 byte" },
/* tr */ { IDS_256_BYTE_TR, "256 Byte" },

/* en */ { IDS_2_KBYTE,    "2 kByte" },
/* da */ { IDS_2_KBYTE_DA, "2 kbyte" },
/* de */ { IDS_2_KBYTE_DE, "2 kByte" },
/* es */ { IDS_2_KBYTE_ES, "2 kBytes" },
/* fr */ { IDS_2_KBYTE_FR, "2 kOctets" },
/* hu */ { IDS_2_KBYTE_HU, "2 kB�jt" },
/* it */ { IDS_2_KBYTE_IT, "2 kByte" },
/* ko */ { IDS_2_KBYTE_KO, "2 kbyte" },
/* nl */ { IDS_2_KBYTE_NL, "2 kByte" },
/* pl */ { IDS_2_KBYTE_PL, "2 kBajty " },
/* ru */ { IDS_2_KBYTE_RU, "" },  /* fuzzy */
/* sv */ { IDS_2_KBYTE_SV, "2 kbyte" },
/* tr */ { IDS_2_KBYTE_TR, "2 kByte" },

/* en */ { IDS_GRAPHICS,    "Graphics" },
/* da */ { IDS_GRAPHICS_DA, "Grafisk" },
/* de */ { IDS_GRAPHICS_DE, "Grafik" },
/* es */ { IDS_GRAPHICS_ES, "Gr�ficos" },
/* fr */ { IDS_GRAPHICS_FR, "Graphiques" },
/* hu */ { IDS_GRAPHICS_HU, "Grafikus" },
/* it */ { IDS_GRAPHICS_IT, "Grafica" },
/* ko */ { IDS_GRAPHICS_KO, "�׷���" },
/* nl */ { IDS_GRAPHICS_NL, "Grafiek" },
/* pl */ { IDS_GRAPHICS_PL, "Grafika" },
/* ru */ { IDS_GRAPHICS_RU, "" },  /* fuzzy */
/* sv */ { IDS_GRAPHICS_SV, "Grafisk" },
/* tr */ { IDS_GRAPHICS_TR, "Grafikler" },

/* en */ { IDS_TEXT,    "Text" },
/* da */ { IDS_TEXT_DA, "Tekst" },
/* de */ { IDS_TEXT_DE, "Text" },
/* es */ { IDS_TEXT_ES, "Texto" },
/* fr */ { IDS_TEXT_FR, "" },  /* fuzzy */
/* hu */ { IDS_TEXT_HU, "" },  /* fuzzy */
/* it */ { IDS_TEXT_IT, "Testo" },
/* ko */ { IDS_TEXT_KO, "�ؽ�Ʈ" },
/* nl */ { IDS_TEXT_NL, "Tekst" },
/* pl */ { IDS_TEXT_PL, "Tekst" },
/* ru */ { IDS_TEXT_RU, "" },  /* fuzzy */
/* sv */ { IDS_TEXT_SV, "Text" },
/* tr */ { IDS_TEXT_TR, "Metin" },

/* en */ { IDS_BUSINESS_UK,    "Business (UK)" },
/* da */ { IDS_BUSINESS_UK_DA, "Business (Storbritannien)" },
/* de */ { IDS_BUSINESS_UK_DE, "Business (UK)" },
/* es */ { IDS_BUSINESS_UK_ES, "Negocios (UK)" },
/* fr */ { IDS_BUSINESS_UK_FR, "Business (UK)" },
/* hu */ { IDS_BUSINESS_UK_HU, "Hivatalos (UK)" },
/* it */ { IDS_BUSINESS_UK_IT, "Business (UK)" },
/* ko */ { IDS_BUSINESS_UK_KO, "�����Ͻ�(UK)" },
/* nl */ { IDS_BUSINESS_UK_NL, "Zakelijk (UK)" },
/* pl */ { IDS_BUSINESS_UK_PL, "Biznesowa (UK)" },
/* ru */ { IDS_BUSINESS_UK_RU, "" },  /* fuzzy */
/* sv */ { IDS_BUSINESS_UK_SV, "Business (Storbritannien)" },
/* tr */ { IDS_BUSINESS_UK_TR, "Business (UK)" },

/* en */ { IDS_SET_PET_MODEL,    "Set PET Model" },
/* da */ { IDS_SET_PET_MODEL_DA, "V�lg PET-model" },
/* de */ { IDS_SET_PET_MODEL_DE, "W�hle PET Modell" },
/* es */ { IDS_SET_PET_MODEL_ES, "Seleccionar modelo PET" },
/* fr */ { IDS_SET_PET_MODEL_FR, "" },  /* fuzzy */
/* hu */ { IDS_SET_PET_MODEL_HU, "PET modell kiv�laszt�sa" },
/* it */ { IDS_SET_PET_MODEL_IT, "Imposta modello di PET" },
/* ko */ { IDS_SET_PET_MODEL_KO, "" },  /* fuzzy */
/* nl */ { IDS_SET_PET_MODEL_NL, "Stel PET model in" },
/* pl */ { IDS_SET_PET_MODEL_PL, "Ustaw model PET" },
/* ru */ { IDS_SET_PET_MODEL_RU, "" },  /* fuzzy */
/* sv */ { IDS_SET_PET_MODEL_SV, "V�lj PET-modell" },
/* tr */ { IDS_SET_PET_MODEL_TR, "PET Modelini Belirle" },

/* en */ { IDS_MEMORY,    "Memory" },
/* da */ { IDS_MEMORY_DA, "Hukommelse" },
/* de */ { IDS_MEMORY_DE, "Speicher" },
/* es */ { IDS_MEMORY_ES, "Memoria" },
/* fr */ { IDS_MEMORY_FR, "M�moire" },
/* hu */ { IDS_MEMORY_HU, "Mem�ria" },
/* it */ { IDS_MEMORY_IT, "Memoria" },
/* ko */ { IDS_MEMORY_KO, "�޸�" },
/* nl */ { IDS_MEMORY_NL, "Geheugen" },
/* pl */ { IDS_MEMORY_PL, "Pami��" },
/* ru */ { IDS_MEMORY_RU, "" },  /* fuzzy */
/* sv */ { IDS_MEMORY_SV, "Minne" },
/* tr */ { IDS_MEMORY_TR, "Bellek" },

/* en */ { IDS_VIDEO_SIZE,    "Video size" },
/* da */ { IDS_VIDEO_SIZE_DA, "Sk�rmbredde" },
/* de */ { IDS_VIDEO_SIZE_DE, "Videospeichergr��e" },
/* es */ { IDS_VIDEO_SIZE_ES, "Tama�o de pantalla" },
/* fr */ { IDS_VIDEO_SIZE_FR, "Taille vid�o" },
/* hu */ { IDS_VIDEO_SIZE_HU, "Vide� m�ret" },
/* it */ { IDS_VIDEO_SIZE_IT, "Dimensione video" },
/* ko */ { IDS_VIDEO_SIZE_KO, "���� ũ��" },
/* nl */ { IDS_VIDEO_SIZE_NL, "Videogrootte" },
/* pl */ { IDS_VIDEO_SIZE_PL, "Rozmiar wideo" },
/* ru */ { IDS_VIDEO_SIZE_RU, "������ �����" },
/* sv */ { IDS_VIDEO_SIZE_SV, "Sk�rmbredd" },
/* tr */ { IDS_VIDEO_SIZE_TR, "G�r�nt� boyutu" },

/* en */ { IDS_IO_SIZE,    "I/O size" },
/* da */ { IDS_IO_SIZE_DA, "I/O-st�rrelse" },
/* de */ { IDS_IO_SIZE_DE, "I/O Gr��e" },
/* es */ { IDS_IO_SIZE_ES, "Tama�o de entradas/salidas" },
/* fr */ { IDS_IO_SIZE_FR, "Taille d'E/S" },
/* hu */ { IDS_IO_SIZE_HU, "I/O m�ret" },
/* it */ { IDS_IO_SIZE_IT, "Dimensione I/O" },
/* ko */ { IDS_IO_SIZE_KO, "I/O ũ��" },
/* nl */ { IDS_IO_SIZE_NL, "I/O grootte" },
/* pl */ { IDS_IO_SIZE_PL, "Rozmiar we/wy" },
/* ru */ { IDS_IO_SIZE_RU, "������ I/O" },
/* sv */ { IDS_IO_SIZE_SV, "I/O-utrymme" },
/* tr */ { IDS_IO_SIZE_TR, "G/� boyutu" },

/* en */ { IDS_KEYBOARD,    "Keyboard" },
/* da */ { IDS_KEYBOARD_DA, "Tastatur" },
/* de */ { IDS_KEYBOARD_DE, "Tastatur" },
/* es */ { IDS_KEYBOARD_ES, "Teclado" },
/* fr */ { IDS_KEYBOARD_FR, "" },  /* fuzzy */
/* hu */ { IDS_KEYBOARD_HU, "Billenty�zet" },
/* it */ { IDS_KEYBOARD_IT, "Tastiera" },
/* ko */ { IDS_KEYBOARD_KO, "Ű����" },
/* nl */ { IDS_KEYBOARD_NL, "Toetsenbord" },
/* pl */ { IDS_KEYBOARD_PL, "Klawiatura" },
/* ru */ { IDS_KEYBOARD_RU, "" },  /* fuzzy */
/* sv */ { IDS_KEYBOARD_SV, "Tangentbord" },
/* tr */ { IDS_KEYBOARD_TR, "Klavye" },

/* en */ { IDS_CRTC_CHIP,    "CRTC chip" },
/* da */ { IDS_CRTC_CHIP_DA, "CRTC-kreds" },
/* de */ { IDS_CRTC_CHIP_DE, "CRTC Chip" },
/* es */ { IDS_CRTC_CHIP_ES, "Chip CRTC" },
/* fr */ { IDS_CRTC_CHIP_FR, "" },  /* fuzzy */
/* hu */ { IDS_CRTC_CHIP_HU, "CRTC csip" },
/* it */ { IDS_CRTC_CHIP_IT, "Chip CRTC" },
/* ko */ { IDS_CRTC_CHIP_KO, "" },  /* fuzzy */
/* nl */ { IDS_CRTC_CHIP_NL, "CRTC chip" },
/* pl */ { IDS_CRTC_CHIP_PL, "Uk�ad CRTC" },
/* ru */ { IDS_CRTC_CHIP_RU, "" },  /* fuzzy */
/* sv */ { IDS_CRTC_CHIP_SV, "CRTC-krets" },
/* tr */ { IDS_CRTC_CHIP_TR, "CRTC �ipi" },

/* en */ { IDS_SUPERPET_IO,    "SuperPET I/O enable (disables 8x96)" },
/* da */ { IDS_SUPERPET_IO_DA, "Aktiv�r SuperPET-I/O (deaktiverer 8x96)" },
/* de */ { IDS_SUPERPET_IO_DE, "SuperPET I/O aktivieren (deaktiviert 8x96)" },
/* es */ { IDS_SUPERPET_IO_ES, "SuperPET entradas/salidas habilitadas (deshabilitado 8x96)" },
/* fr */ { IDS_SUPERPET_IO_FR, "" },  /* fuzzy */
/* hu */ { IDS_SUPERPET_IO_HU, "SuperPET I/O enged�lyez�se (8x96-ot tiltja)" },
/* it */ { IDS_SUPERPET_IO_IT, "Attiva I/O SuperPET (disattiva 8x96)" },
/* ko */ { IDS_SUPERPET_IO_KO, "SuperPET I/O ����ϱ� (��������ʱ� 8x96)" },
/* nl */ { IDS_SUPERPET_IO_NL, "SuperPET I/O activeren (zet 8x96 uit)" },
/* pl */ { IDS_SUPERPET_IO_PL, "W��cz SuperPET I/O (wy��cza 8x96)" },
/* ru */ { IDS_SUPERPET_IO_RU, "" },  /* fuzzy */
/* sv */ { IDS_SUPERPET_IO_SV, "Aktivera SuperPET-I/O (inaktiverar 8x96)" },
/* tr */ { IDS_SUPERPET_IO_TR, "SuperPET G/� aktif et (8x96'y� pasifle�tir)" },

/* en */ { IDS_9xxx_AS_RAM,    "$9*** as RAM" },
/* da */ { IDS_9xxx_AS_RAM_DA, "$9*** som RAM" },
/* de */ { IDS_9xxx_AS_RAM_DE, "$9*** als RAM" },
/* es */ { IDS_9xxx_AS_RAM_ES, "$9*** como RAM" },
/* fr */ { IDS_9xxx_AS_RAM_FR, "" },  /* fuzzy */
/* hu */ { IDS_9xxx_AS_RAM_HU, "$9*** RAM-k�nt" },
/* it */ { IDS_9xxx_AS_RAM_IT, "$9*** come RAM" },
/* ko */ { IDS_9xxx_AS_RAM_KO, "" },  /* fuzzy */
/* nl */ { IDS_9xxx_AS_RAM_NL, "$9*** als RAM" },
/* pl */ { IDS_9xxx_AS_RAM_PL, "$9*** jako RAM" },
/* ru */ { IDS_9xxx_AS_RAM_RU, "" },  /* fuzzy */
/* sv */ { IDS_9xxx_AS_RAM_SV, "$9*** som RAM" },
/* tr */ { IDS_9xxx_AS_RAM_TR, "RAM olarak $9***" },

/* en */ { IDS_Axxx_AS_RAM,    "$A*** as RAM" },
/* da */ { IDS_Axxx_AS_RAM_DA, "$A*** som RAM" },
/* de */ { IDS_Axxx_AS_RAM_DE, "$A*** als RAM" },
/* es */ { IDS_Axxx_AS_RAM_ES, "$A*** como RAM" },
/* fr */ { IDS_Axxx_AS_RAM_FR, "" },  /* fuzzy */
/* hu */ { IDS_Axxx_AS_RAM_HU, "$A*** RAM-k�nt" },
/* it */ { IDS_Axxx_AS_RAM_IT, "$A*** come RAM" },
/* ko */ { IDS_Axxx_AS_RAM_KO, "" },  /* fuzzy */
/* nl */ { IDS_Axxx_AS_RAM_NL, "$A*** als RAM" },
/* pl */ { IDS_Axxx_AS_RAM_PL, "$A*** jako RAM" },
/* ru */ { IDS_Axxx_AS_RAM_RU, "" },  /* fuzzy */
/* sv */ { IDS_Axxx_AS_RAM_SV, "$A*** som RAM" },
/* tr */ { IDS_Axxx_AS_RAM_TR, "RAM olarak $A***" },

/* en */ { IDS_PET_SETTINGS,    "PET settings" },
/* da */ { IDS_PET_SETTINGS_DA, "PET-indstillinger" },
/* de */ { IDS_PET_SETTINGS_DE, "PET Einstellungen" },
/* es */ { IDS_PET_SETTINGS_ES, "Ajustes PET" },
/* fr */ { IDS_PET_SETTINGS_FR, "Param�tres PET" },
/* hu */ { IDS_PET_SETTINGS_HU, "PET be�ll�t�sai" },
/* it */ { IDS_PET_SETTINGS_IT, "Impostazioni PET" },
/* ko */ { IDS_PET_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_PET_SETTINGS_NL, "PET instellingen" },
/* pl */ { IDS_PET_SETTINGS_PL, "Ustawienia PET" },
/* ru */ { IDS_PET_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_PET_SETTINGS_SV, "PET-inst�llningar" },
/* tr */ { IDS_PET_SETTINGS_TR, "PET ayarlar�" },

/* en */ { IDS_CURRENT_MODEL,    "Current Model" },
/* da */ { IDS_CURRENT_MODEL_DA, "Nuv�rende model" },
/* de */ { IDS_CURRENT_MODEL_DE, "Aktuelles Modell" },
/* es */ { IDS_CURRENT_MODEL_ES, "modelo actual" },
/* fr */ { IDS_CURRENT_MODEL_FR, "" },  /* fuzzy */
/* hu */ { IDS_CURRENT_MODEL_HU, "Jelenlegi modell" },
/* it */ { IDS_CURRENT_MODEL_IT, "Modello attuale" },
/* ko */ { IDS_CURRENT_MODEL_KO, "" },  /* fuzzy */
/* nl */ { IDS_CURRENT_MODEL_NL, "Huidig model" },
/* pl */ { IDS_CURRENT_MODEL_PL, "Obecny model" },
/* ru */ { IDS_CURRENT_MODEL_RU, "" },  /* fuzzy */
/* sv */ { IDS_CURRENT_MODEL_SV, "Aktuell modell" },
/* tr */ { IDS_CURRENT_MODEL_TR, "Ge�erli Model" },

/* en */ { IDS_PET_MODEL,    "PET Model" },
/* da */ { IDS_PET_MODEL_DA, "PET-model" },
/* de */ { IDS_PET_MODEL_DE, "PET Modell" },
/* es */ { IDS_PET_MODEL_ES, "Modelo PET" },
/* fr */ { IDS_PET_MODEL_FR, "" },  /* fuzzy */
/* hu */ { IDS_PET_MODEL_HU, "PET modell" },
/* it */ { IDS_PET_MODEL_IT, "Modello PET" },
/* ko */ { IDS_PET_MODEL_KO, "" },  /* fuzzy */
/* nl */ { IDS_PET_MODEL_NL, "PET model" },
/* pl */ { IDS_PET_MODEL_PL, "Model PET" },
/* ru */ { IDS_PET_MODEL_RU, "" },  /* fuzzy */
/* sv */ { IDS_PET_MODEL_SV, "PET-modell" },
/* tr */ { IDS_PET_MODEL_TR, "PET Modeli" },

/* en */ { IDS_PLUS4_SETTINGS,    "Plus4 settings" },
/* da */ { IDS_PLUS4_SETTINGS_DA, "Plus4-indstillinger" },
/* de */ { IDS_PLUS4_SETTINGS_DE, "Plus4 Einstellungen" },
/* es */ { IDS_PLUS4_SETTINGS_ES, "Ajustes Plus4" },
/* fr */ { IDS_PLUS4_SETTINGS_FR, "Param�tres Plus4" },
/* hu */ { IDS_PLUS4_SETTINGS_HU, "Plus4 be�ll�t�sai" },
/* it */ { IDS_PLUS4_SETTINGS_IT, "Impostazioni Plus4" },
/* ko */ { IDS_PLUS4_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_PLUS4_SETTINGS_NL, "Plus4 instellingen" },
/* pl */ { IDS_PLUS4_SETTINGS_PL, "Ustawienia Plus4" },
/* ru */ { IDS_PLUS4_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_PLUS4_SETTINGS_SV, "Plus4-inst�llningar" },
/* tr */ { IDS_PLUS4_SETTINGS_TR, "Plus4 ayarlar�" },

/* en */ { IDS_SELECT_INTERNAL_FUNCTION_ROM_FILENAME,    "Select Internal Function ROM file" },
/* da */ { IDS_SELECT_INTERNAL_FUNCTION_ROM_FILENAME_DA, "V�lg image for intern funktions-ROM" },
/* de */ { IDS_SELECT_INTERNAL_FUNCTION_ROM_FILENAME_DE, "Internes Funktions ROM Image Datei ausw�hlen" },
/* es */ { IDS_SELECT_INTERNAL_FUNCTION_ROM_FILENAME_ES, "Seleccionar fichero ROM funci�n interno" },
/* fr */ { IDS_SELECT_INTERNAL_FUNCTION_ROM_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_SELECT_INTERNAL_FUNCTION_ROM_FILENAME_HU, "Adja meg a bels� Function ROM k�pm�s nev�t" },
/* it */ { IDS_SELECT_INTERNAL_FUNCTION_ROM_FILENAME_IT, "Seleziona file function ROM interna" },
/* ko */ { IDS_SELECT_INTERNAL_FUNCTION_ROM_FILENAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_INTERNAL_FUNCTION_ROM_FILENAME_NL, "Selecteer intern functie ROM bestand" },
/* pl */ { IDS_SELECT_INTERNAL_FUNCTION_ROM_FILENAME_PL, "Wybierz plik ROM Internal Function" },
/* ru */ { IDS_SELECT_INTERNAL_FUNCTION_ROM_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_INTERNAL_FUNCTION_ROM_FILENAME_SV, "V�lj avbildning f�r internt funktions-ROM" },
/* tr */ { IDS_SELECT_INTERNAL_FUNCTION_ROM_FILENAME_TR, "Dahili Function ROM dosyas� se�in" },

/* en */ { IDS_SELECT_EXTERNAL_FUNCTION_ROM_FILENAME,    "Select External Function ROM file" },
/* da */ { IDS_SELECT_EXTERNAL_FUNCTION_ROM_FILENAME_DA, "V�lg image for ekstern funktions-ROM" },
/* de */ { IDS_SELECT_EXTERNAL_FUNCTION_ROM_FILENAME_DE, "Externes Funktions ROM Image Datei ausw�hlen" },
/* es */ { IDS_SELECT_EXTERNAL_FUNCTION_ROM_FILENAME_ES, "Seleccionar fichero ROM funci�n externo" },
/* fr */ { IDS_SELECT_EXTERNAL_FUNCTION_ROM_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_SELECT_EXTERNAL_FUNCTION_ROM_FILENAME_HU, "Adja meg a k�ls� Function ROM k�pm�s nev�t" },
/* it */ { IDS_SELECT_EXTERNAL_FUNCTION_ROM_FILENAME_IT, "Seleziona file function ROM esterna" },
/* ko */ { IDS_SELECT_EXTERNAL_FUNCTION_ROM_FILENAME_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_EXTERNAL_FUNCTION_ROM_FILENAME_NL, "Selecteer extern functie ROM bestand" },
/* pl */ { IDS_SELECT_EXTERNAL_FUNCTION_ROM_FILENAME_PL, "Wybierz plik ROM External Function" },
/* ru */ { IDS_SELECT_EXTERNAL_FUNCTION_ROM_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_EXTERNAL_FUNCTION_ROM_FILENAME_SV, "V�lj avbildning f�r externt funktions-ROM" },
/* tr */ { IDS_SELECT_EXTERNAL_FUNCTION_ROM_FILENAME_TR, "Harici Function ROM dosyas� se�in" },

/* en */ { IDS_MACHINE_TYPE,    "Machine type" },
/* da */ { IDS_MACHINE_TYPE_DA, "Maskintype" },
/* de */ { IDS_MACHINE_TYPE_DE, "Maschinen Typ" },
/* es */ { IDS_MACHINE_TYPE_ES, "Tipo de m�quina" },
/* fr */ { IDS_MACHINE_TYPE_FR, "Type de machine" },
/* hu */ { IDS_MACHINE_TYPE_HU, "G�p t�pus" },
/* it */ { IDS_MACHINE_TYPE_IT, "Tipo macchina" },
/* ko */ { IDS_MACHINE_TYPE_KO, "�ӽ� ����" },
/* nl */ { IDS_MACHINE_TYPE_NL, "Machinesoort" },
/* pl */ { IDS_MACHINE_TYPE_PL, "Typ maszyny" },
/* ru */ { IDS_MACHINE_TYPE_RU, "��� ����������" },
/* sv */ { IDS_MACHINE_TYPE_SV, "Maskintyp" },
/* tr */ { IDS_MACHINE_TYPE_TR, "Makine tipi" },

/* en */ { IDS_INTERNAL_FUNCTION_ROM,    "Internal Function ROM" },
/* da */ { IDS_INTERNAL_FUNCTION_ROM_DA, "Intern funktions-ROM" },
/* de */ { IDS_INTERNAL_FUNCTION_ROM_DE, "Internes Funktions ROM" },
/* es */ { IDS_INTERNAL_FUNCTION_ROM_ES, "ROM de funci�n interna" },
/* fr */ { IDS_INTERNAL_FUNCTION_ROM_FR, "Image ROM Fonction interne" },
/* hu */ { IDS_INTERNAL_FUNCTION_ROM_HU, "Bels� Function ROM" },
/* it */ { IDS_INTERNAL_FUNCTION_ROM_IT, "Function ROM interna" },
/* ko */ { IDS_INTERNAL_FUNCTION_ROM_KO, "" },  /* fuzzy */
/* nl */ { IDS_INTERNAL_FUNCTION_ROM_NL, "Interne functie ROM" },
/* pl */ { IDS_INTERNAL_FUNCTION_ROM_PL, "Wewn�trzna funkcja ROM" },
/* ru */ { IDS_INTERNAL_FUNCTION_ROM_RU, "" },  /* fuzzy */
/* sv */ { IDS_INTERNAL_FUNCTION_ROM_SV, "Internt funktions-ROM" },
/* tr */ { IDS_INTERNAL_FUNCTION_ROM_TR, "Uluslararas� Function ROM" },

/* en */ { IDS_INTERNAL_FUNCTION_ROM_FILENAME,    "Internal Function ROM file" },
/* da */ { IDS_INTERNAL_FUNCTION_ROM_FILENAME_DA, "Intern funktions-ROM" },
/* de */ { IDS_INTERNAL_FUNCTION_ROM_FILENAME_DE, "Interne Funktions ROM Datei" },
/* es */ { IDS_INTERNAL_FUNCTION_ROM_FILENAME_ES, "Fichero ROM funci�n interno" },
/* fr */ { IDS_INTERNAL_FUNCTION_ROM_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_INTERNAL_FUNCTION_ROM_FILENAME_HU, "Bels� Function ROM f�jl" },
/* it */ { IDS_INTERNAL_FUNCTION_ROM_FILENAME_IT, "File function ROM interna" },
/* ko */ { IDS_INTERNAL_FUNCTION_ROM_FILENAME_KO, "���ͳ� Function ROM ����" },
/* nl */ { IDS_INTERNAL_FUNCTION_ROM_FILENAME_NL, "Intern functie ROM bestand" },
/* pl */ { IDS_INTERNAL_FUNCTION_ROM_FILENAME_PL, "Plik wewn�trznej funkcji ROM" },
/* ru */ { IDS_INTERNAL_FUNCTION_ROM_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_INTERNAL_FUNCTION_ROM_FILENAME_SV, "Internt funktions-ROM" },
/* tr */ { IDS_INTERNAL_FUNCTION_ROM_FILENAME_TR, "Dahili Function ROM dosyas�" },

/* en */ { IDS_EXTERNAL_FUNCTION_ROM,    "External Function ROM" },
/* da */ { IDS_EXTERNAL_FUNCTION_ROM_DA, "Extern funktions-ROM" },
/* de */ { IDS_EXTERNAL_FUNCTION_ROM_DE, "Externes Funktions ROM" },
/* es */ { IDS_EXTERNAL_FUNCTION_ROM_ES, "ROM externa de funci�n" },
/* fr */ { IDS_EXTERNAL_FUNCTION_ROM_FR, "Image ROM Fonction externe" },
/* hu */ { IDS_EXTERNAL_FUNCTION_ROM_HU, "K�ls� Function ROM" },
/* it */ { IDS_EXTERNAL_FUNCTION_ROM_IT, "Function ROM esterna" },
/* ko */ { IDS_EXTERNAL_FUNCTION_ROM_KO, "" },  /* fuzzy */
/* nl */ { IDS_EXTERNAL_FUNCTION_ROM_NL, "Externe functie ROM" },
/* pl */ { IDS_EXTERNAL_FUNCTION_ROM_PL, "Zewn�trzna funkcja ROM" },
/* ru */ { IDS_EXTERNAL_FUNCTION_ROM_RU, "" },  /* fuzzy */
/* sv */ { IDS_EXTERNAL_FUNCTION_ROM_SV, "Externt funktions-ROM" },
/* tr */ { IDS_EXTERNAL_FUNCTION_ROM_TR, "Harici Function ROM" },

/* en */ { IDS_EXTERNAL_FUNCTION_ROM_FILENAME,    "External Function ROM file" },
/* da */ { IDS_EXTERNAL_FUNCTION_ROM_FILENAME_DA, "Extern funktions-ROM" },
/* de */ { IDS_EXTERNAL_FUNCTION_ROM_FILENAME_DE, "Externe Funktions ROM Datei" },
/* es */ { IDS_EXTERNAL_FUNCTION_ROM_FILENAME_ES, "Fichero ROM funci�n externo" },
/* fr */ { IDS_EXTERNAL_FUNCTION_ROM_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_EXTERNAL_FUNCTION_ROM_FILENAME_HU, "K�ls� Function ROM f�jl" },
/* it */ { IDS_EXTERNAL_FUNCTION_ROM_FILENAME_IT, "File function ROM esterna" },
/* ko */ { IDS_EXTERNAL_FUNCTION_ROM_FILENAME_KO, "�ܺ��Լ� ROM ����" },
/* nl */ { IDS_EXTERNAL_FUNCTION_ROM_FILENAME_NL, "Extern functie ROM bestand" },
/* pl */ { IDS_EXTERNAL_FUNCTION_ROM_FILENAME_PL, "Plik zewn�trznej funkcji ROM" },
/* ru */ { IDS_EXTERNAL_FUNCTION_ROM_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_EXTERNAL_FUNCTION_ROM_FILENAME_SV, "Externt funktions-ROM" },
/* tr */ { IDS_EXTERNAL_FUNCTION_ROM_FILENAME_TR, "Harici Function ROM dosyas�" },

/* en */ { IDS_RAM_BANKS_2_AND_3,    "RAM banks 2 & 3" },
/* da */ { IDS_RAM_BANKS_2_AND_3_DA, "RAM bank 2 & 3" },
/* de */ { IDS_RAM_BANKS_2_AND_3_DE, "RAM B�nkte 2 & 3" },
/* es */ { IDS_RAM_BANKS_2_AND_3_ES, "RAM bancos 2 y 3" },
/* fr */ { IDS_RAM_BANKS_2_AND_3_FR, "" },  /* fuzzy */
/* hu */ { IDS_RAM_BANKS_2_AND_3_HU, "2-es �s 3-as RAM bankok" },
/* it */ { IDS_RAM_BANKS_2_AND_3_IT, "Banchi RAM 2 & 3" },
/* ko */ { IDS_RAM_BANKS_2_AND_3_KO, "" },  /* fuzzy */
/* nl */ { IDS_RAM_BANKS_2_AND_3_NL, "RAM banken 2 & 3" },
/* pl */ { IDS_RAM_BANKS_2_AND_3_PL, "Banki RAM 2 i 3" },
/* ru */ { IDS_RAM_BANKS_2_AND_3_RU, "" },  /* fuzzy */
/* sv */ { IDS_RAM_BANKS_2_AND_3_SV, "RAM-bank 2 & 3" },
/* tr */ { IDS_RAM_BANKS_2_AND_3_TR, "RAM banklar� 2 & 3" },

/* en */ { IDS_C128_SETTINGS,    "C128 settings" },
/* da */ { IDS_C128_SETTINGS_DA, "C128-indstillinger" },
/* de */ { IDS_C128_SETTINGS_DE, "C128 Einstellungen" },
/* es */ { IDS_C128_SETTINGS_ES, "Ajustes C128" },
/* fr */ { IDS_C128_SETTINGS_FR, "Param�tres C128" },
/* hu */ { IDS_C128_SETTINGS_HU, "C128 be�ll�t�sai" },
/* it */ { IDS_C128_SETTINGS_IT, "Impostazioni C128" },
/* ko */ { IDS_C128_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_C128_SETTINGS_NL, "C128 instellingen" },
/* pl */ { IDS_C128_SETTINGS_PL, "Ustawienia C128" },
/* ru */ { IDS_C128_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_C128_SETTINGS_SV, "C128-inst�llningar" },
/* tr */ { IDS_C128_SETTINGS_TR, "C128 ayarlar�" },

/* en */ { IDS_SELECT_ROM_FILE,    "Select ROM file" },
/* da */ { IDS_SELECT_ROM_FILE_DA, "V�lg ROM-fil" },
/* de */ { IDS_SELECT_ROM_FILE_DE, "ROM Datei w�hlen" },
/* es */ { IDS_SELECT_ROM_FILE_ES, "Seleccionar fichero ROM" },
/* fr */ { IDS_SELECT_ROM_FILE_FR, "" },  /* fuzzy */
/* hu */ { IDS_SELECT_ROM_FILE_HU, "V�lasszon ROM f�jlt" },
/* it */ { IDS_SELECT_ROM_FILE_IT, "Seleziona file ROM" },
/* ko */ { IDS_SELECT_ROM_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_ROM_FILE_NL, "Selecteer ROM bestand" },
/* pl */ { IDS_SELECT_ROM_FILE_PL, "wybierz plik ROM" },
/* ru */ { IDS_SELECT_ROM_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_ROM_FILE_SV, "V�lj ROM-fil" },
/* tr */ { IDS_SELECT_ROM_FILE_TR, "ROM dosyas� se�in" },

/* en */ { IDS_COMPUTER_ROM_SETTINGS,    "Computer ROM settings" },
/* da */ { IDS_COMPUTER_ROM_SETTINGS_DA, "Computer ROM-indstillinger" },
/* de */ { IDS_COMPUTER_ROM_SETTINGS_DE, "Computer ROM Einstellungen" },
/* es */ { IDS_COMPUTER_ROM_SETTINGS_ES, "Ajustes ROM ordenador" },
/* fr */ { IDS_COMPUTER_ROM_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_COMPUTER_ROM_SETTINGS_HU, "Sz�m�t�g�p ROM be�ll�t�sai" },
/* it */ { IDS_COMPUTER_ROM_SETTINGS_IT, "Impostazioni ROM del computer" },
/* ko */ { IDS_COMPUTER_ROM_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_COMPUTER_ROM_SETTINGS_NL, "Computer ROM instellingen" },
/* pl */ { IDS_COMPUTER_ROM_SETTINGS_PL, "Ustawienia ROM komputera" },
/* ru */ { IDS_COMPUTER_ROM_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_COMPUTER_ROM_SETTINGS_SV, "ROM-inst�llningar f�r dator" },
/* tr */ { IDS_COMPUTER_ROM_SETTINGS_TR, "Bilgisayar ROM ayarlar�" },

/* en */ { IDS_DRIVE_ROM_SETTINGS,    "Drive ROM settings" },
/* da */ { IDS_DRIVE_ROM_SETTINGS_DA, "Drev ROM-indstillinger" },
/* de */ { IDS_DRIVE_ROM_SETTINGS_DE, "Floppy ROM Einstellungen" },
/* es */ { IDS_DRIVE_ROM_SETTINGS_ES, "Ajustes ROM unidad disco" },
/* fr */ { IDS_DRIVE_ROM_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_DRIVE_ROM_SETTINGS_HU, "Lemezegys�g ROM be�ll�t�sai" },
/* it */ { IDS_DRIVE_ROM_SETTINGS_IT, "Impostazioni ROM del drive" },
/* ko */ { IDS_DRIVE_ROM_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_DRIVE_ROM_SETTINGS_NL, "Drive ROM instellingen" },
/* pl */ { IDS_DRIVE_ROM_SETTINGS_PL, "Ustawienia ROM nap�du" },
/* ru */ { IDS_DRIVE_ROM_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_DRIVE_ROM_SETTINGS_SV, "ROM-inst�llningar f�r diskettenhet" },
/* tr */ { IDS_DRIVE_ROM_SETTINGS_TR, "S�r�c� ROM ayarlar�" },

/* en */ { IDS_DIGIMAX_ENABLED,    "DigiMAX Enabled" },
/* da */ { IDS_DIGIMAX_ENABLED_DA, "DigiMAX aktiv�ret" },
/* de */ { IDS_DIGIMAX_ENABLED_DE, "DigiMAX aktiviert" },
/* es */ { IDS_DIGIMAX_ENABLED_ES, "Permitir DigiMAX" },
/* fr */ { IDS_DIGIMAX_ENABLED_FR, "" },  /* fuzzy */
/* hu */ { IDS_DIGIMAX_ENABLED_HU, "" },  /* fuzzy */
/* it */ { IDS_DIGIMAX_ENABLED_IT, "DigiMAX attivato" },
/* ko */ { IDS_DIGIMAX_ENABLED_KO, "" },  /* fuzzy */
/* nl */ { IDS_DIGIMAX_ENABLED_NL, "DigiMAX Aan/Uit" },
/* pl */ { IDS_DIGIMAX_ENABLED_PL, "DigiMAX w��czony" },
/* ru */ { IDS_DIGIMAX_ENABLED_RU, "" },  /* fuzzy */
/* sv */ { IDS_DIGIMAX_ENABLED_SV, "DigiMAX aktiverad" },
/* tr */ { IDS_DIGIMAX_ENABLED_TR, "DigiMAX'� Aktif Et" },

/* en */ { IDS_DIGIMAX_BASE,    "DigiMAX base" },
/* da */ { IDS_DIGIMAX_BASE_DA, "DigiMAX-base" },
/* de */ { IDS_DIGIMAX_BASE_DE, "DigiMAX Basis" },
/* es */ { IDS_DIGIMAX_BASE_ES, "DigiMAX base" },
/* fr */ { IDS_DIGIMAX_BASE_FR, "" },  /* fuzzy */
/* hu */ { IDS_DIGIMAX_BASE_HU, "" },  /* fuzzy */
/* it */ { IDS_DIGIMAX_BASE_IT, "Indirizzo base DigiMAX" },
/* ko */ { IDS_DIGIMAX_BASE_KO, "" },  /* fuzzy */
/* nl */ { IDS_DIGIMAX_BASE_NL, "DigiMAX basisadres" },
/* pl */ { IDS_DIGIMAX_BASE_PL, "Baza DigiMAX" },
/* ru */ { IDS_DIGIMAX_BASE_RU, "" },  /* fuzzy */
/* sv */ { IDS_DIGIMAX_BASE_SV, "DigiMAX-bas" },
/* tr */ { IDS_DIGIMAX_BASE_TR, "DigiMAX taban" },

/* en */ { IDS_DIGIMAX_SETTINGS,    "DigiMAX settings" },
/* da */ { IDS_DIGIMAX_SETTINGS_DA, "DigiMAX-indstillinger" },
/* de */ { IDS_DIGIMAX_SETTINGS_DE, "DigiMAX Einstellungen" },
/* es */ { IDS_DIGIMAX_SETTINGS_ES, "Ajustes DigiMAX" },
/* fr */ { IDS_DIGIMAX_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_DIGIMAX_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_DIGIMAX_SETTINGS_IT, "Impostazioni DigiMAX" },
/* ko */ { IDS_DIGIMAX_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_DIGIMAX_SETTINGS_NL, "DigiMAX instellingen" },
/* pl */ { IDS_DIGIMAX_SETTINGS_PL, "Ustawienia DigiMAX" },
/* ru */ { IDS_DIGIMAX_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_DIGIMAX_SETTINGS_SV, "DigiMAX-inst�llningar" },
/* tr */ { IDS_DIGIMAX_SETTINGS_TR, "DigiMAX ayarlar�" },

/* en */ { IDS_SFX_SE_ENABLED,    "SFX Sound Expander Enabled" },
/* da */ { IDS_SFX_SE_ENABLED_DA, "SFX Sound Expander Aktiveret" },
/* de */ { IDS_SFX_SE_ENABLED_DE, "SFX Sound Expander aktiviert" },
/* es */ { IDS_SFX_SE_ENABLED_ES, "Permitir SFX Sound Expander" },
/* fr */ { IDS_SFX_SE_ENABLED_FR, "" },  /* fuzzy */
/* hu */ { IDS_SFX_SE_ENABLED_HU, "SFX Sound Expander enged�lyezve" },
/* it */ { IDS_SFX_SE_ENABLED_IT, "Attiva SFX Sound Expander" },
/* ko */ { IDS_SFX_SE_ENABLED_KO, "" },  /* fuzzy */
/* nl */ { IDS_SFX_SE_ENABLED_NL, "SFX Sound Expander Aan/Uit" },
/* pl */ { IDS_SFX_SE_ENABLED_PL, "SFX Sound Expander w��czony" },
/* ru */ { IDS_SFX_SE_ENABLED_RU, "" },  /* fuzzy */
/* sv */ { IDS_SFX_SE_ENABLED_SV, "SFX Sound Expander aktiverad" },
/* tr */ { IDS_SFX_SE_ENABLED_TR, "SFX Sound Expander Aktif" },

/* en */ { IDS_SFX_SE_CHIP,    "SFX Sound Expander Chip" },
/* da */ { IDS_SFX_SE_CHIP_DA, "SFX Sound Expander chip" },
/* de */ { IDS_SFX_SE_CHIP_DE, "SFX Sound Expander Chip" },
/* es */ { IDS_SFX_SE_CHIP_ES, "SFX Sound Expander Chip" },
/* fr */ { IDS_SFX_SE_CHIP_FR, "" },  /* fuzzy */
/* hu */ { IDS_SFX_SE_CHIP_HU, "SFX Sound Expander csip" },
/* it */ { IDS_SFX_SE_CHIP_IT, "Chip SFX Sound Expander" },
/* ko */ { IDS_SFX_SE_CHIP_KO, "" },  /* fuzzy */
/* nl */ { IDS_SFX_SE_CHIP_NL, "SFX Sound Expander Chip" },
/* pl */ { IDS_SFX_SE_CHIP_PL, "Uk�ad SFX Sound Expander" },
/* ru */ { IDS_SFX_SE_CHIP_RU, "" },  /* fuzzy */
/* sv */ { IDS_SFX_SE_CHIP_SV, "SFX Sound Expander-krets" },
/* tr */ { IDS_SFX_SE_CHIP_TR, "SFX Sound Expander �ipi" },

/* en */ { IDS_SFX_SS_ENABLED,    "SFX Sound Sampler Enabled" },
/* da */ { IDS_SFX_SS_ENABLED_DA, "" },  /* fuzzy */
/* de */ { IDS_SFX_SS_ENABLED_DE, "SFX Sound Sampler aktiviert" },
/* es */ { IDS_SFX_SS_ENABLED_ES, "Permitir SFX Sound Sampler" },
/* fr */ { IDS_SFX_SS_ENABLED_FR, "" },  /* fuzzy */
/* hu */ { IDS_SFX_SS_ENABLED_HU, "" },  /* fuzzy */
/* it */ { IDS_SFX_SS_ENABLED_IT, "" },  /* fuzzy */
/* ko */ { IDS_SFX_SS_ENABLED_KO, "" },  /* fuzzy */
/* nl */ { IDS_SFX_SS_ENABLED_NL, "SFX Sound Sampler Aan/Uit" },
/* pl */ { IDS_SFX_SS_ENABLED_PL, "W��czony sampler d�wi�ku SFX" },
/* ru */ { IDS_SFX_SS_ENABLED_RU, "" },  /* fuzzy */
/* sv */ { IDS_SFX_SS_ENABLED_SV, "" },  /* fuzzy */
/* tr */ { IDS_SFX_SS_ENABLED_TR, "" },  /* fuzzy */

/* en */ { IDS_SFX_SE_SETTINGS,    "SFX Sound Expander settings" },
/* da */ { IDS_SFX_SE_SETTINGS_DA, "SFX Sound Expander-indstillinger" },
/* de */ { IDS_SFX_SE_SETTINGS_DE, "SFX Sound Expander Einstellungen" },
/* es */ { IDS_SFX_SE_SETTINGS_ES, "Ajustes SFX Sound Expander" },
/* fr */ { IDS_SFX_SE_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_SFX_SE_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_SFX_SE_SETTINGS_IT, "Impostazioni SFX Sound Expander" },
/* ko */ { IDS_SFX_SE_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_SFX_SE_SETTINGS_NL, "SFX Sound Expander instellingen" },
/* pl */ { IDS_SFX_SE_SETTINGS_PL, "Ustawienia SFX Sound Expander" },
/* ru */ { IDS_SFX_SE_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_SFX_SE_SETTINGS_SV, "Inst�llningar f�r SFX Sound Expander" },
/* tr */ { IDS_SFX_SE_SETTINGS_TR, "SFX Sound Expander Ayarlar�" },

/* en */ { IDS_SFX_SS_SETTINGS,    "SFX Sound Sampler settings" },
/* da */ { IDS_SFX_SS_SETTINGS_DA, "" },  /* fuzzy */
/* de */ { IDS_SFX_SS_SETTINGS_DE, "SFX Sound Sampler Einstellungen" },
/* es */ { IDS_SFX_SS_SETTINGS_ES, "Ajustes SFX Sound Sampler" },
/* fr */ { IDS_SFX_SS_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_SFX_SS_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_SFX_SS_SETTINGS_IT, "" },  /* fuzzy */
/* ko */ { IDS_SFX_SS_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_SFX_SS_SETTINGS_NL, "SFX Sound Sampler instellingen" },
/* pl */ { IDS_SFX_SS_SETTINGS_PL, "Ustawienia samplera d�wi�ku SFX" },
/* ru */ { IDS_SFX_SS_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_SFX_SS_SETTINGS_SV, "" },  /* fuzzy */
/* tr */ { IDS_SFX_SS_SETTINGS_TR, "" },  /* fuzzy */

/* en */ { IDS_SOUND_RECORDING_STOPPED,    "Sound Recording stopped..." },
/* da */ { IDS_SOUND_RECORDING_STOPPED_DA, "Lydoptagelse stoppet..." },
/* de */ { IDS_SOUND_RECORDING_STOPPED_DE, "Tonaufnahme gestoppt..." },
/* es */ { IDS_SOUND_RECORDING_STOPPED_ES, "Grabaci�n de sonido detenida..." },
/* fr */ { IDS_SOUND_RECORDING_STOPPED_FR, "" },  /* fuzzy */
/* hu */ { IDS_SOUND_RECORDING_STOPPED_HU, "" },  /* fuzzy */
/* it */ { IDS_SOUND_RECORDING_STOPPED_IT, "Registrazione audio interrotta..." },
/* ko */ { IDS_SOUND_RECORDING_STOPPED_KO, "���� ���ڵ� ����..." },
/* nl */ { IDS_SOUND_RECORDING_STOPPED_NL, "Geluidsopname gestopt..." },
/* pl */ { IDS_SOUND_RECORDING_STOPPED_PL, "Zatrzymano odtwarzanie d�wi�ku..." },
/* ru */ { IDS_SOUND_RECORDING_STOPPED_RU, "" },  /* fuzzy */
/* sv */ { IDS_SOUND_RECORDING_STOPPED_SV, "Ljudinspelning stoppad..." },
/* tr */ { IDS_SOUND_RECORDING_STOPPED_TR, "Ses Kayd� durduruldu..." },

/* en */ { IDS_SOUND_RECORDING_STARTED,    "Sound Recording started..." },
/* da */ { IDS_SOUND_RECORDING_STARTED_DA, "Lydoptagelse startet..." },
/* de */ { IDS_SOUND_RECORDING_STARTED_DE, "Tonaufnahme gestartet..." },
/* es */ { IDS_SOUND_RECORDING_STARTED_ES, "Grabaci�n de sonido iniciada..." },
/* fr */ { IDS_SOUND_RECORDING_STARTED_FR, "" },  /* fuzzy */
/* hu */ { IDS_SOUND_RECORDING_STARTED_HU, "" },  /* fuzzy */
/* it */ { IDS_SOUND_RECORDING_STARTED_IT, "Registrazione audio avviata..." },
/* ko */ { IDS_SOUND_RECORDING_STARTED_KO, "���� ���ڵ��� �����߽��ϴ�..." },
/* nl */ { IDS_SOUND_RECORDING_STARTED_NL, "Geluidsopname gestart..." },
/* pl */ { IDS_SOUND_RECORDING_STARTED_PL, "Rozpocz�to odtwarzanie d�wi�ku..." },
/* ru */ { IDS_SOUND_RECORDING_STARTED_RU, "" },  /* fuzzy */
/* sv */ { IDS_SOUND_RECORDING_STARTED_SV, "Ljudinspelning startad..." },
/* tr */ { IDS_SOUND_RECORDING_STARTED_TR, "Ses Kayd� ba�lad�..." },

/* en */ { IDS_SELECT_RECORD_FILE,    "Select Sound Record File" },
/* da */ { IDS_SELECT_RECORD_FILE_DA, "V�lg lydoptagelsesfil" },
/* de */ { IDS_SELECT_RECORD_FILE_DE, "Tonaufnahmedatei definieren" },
/* es */ { IDS_SELECT_RECORD_FILE_ES, "Seleccionar fichero grabaci�n sonido" },
/* fr */ { IDS_SELECT_RECORD_FILE_FR, "" },  /* fuzzy */
/* hu */ { IDS_SELECT_RECORD_FILE_HU, "V�lassza ki a hangfelv�tel kimeneti f�jlt" },
/* it */ { IDS_SELECT_RECORD_FILE_IT, "Seleziona file per registrazione audio" },
/* ko */ { IDS_SELECT_RECORD_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDS_SELECT_RECORD_FILE_NL, "Selecteer geluidsopnamebestand" },
/* pl */ { IDS_SELECT_RECORD_FILE_PL, "Wybierz plik zapisu d�wi�ku" },
/* ru */ { IDS_SELECT_RECORD_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SELECT_RECORD_FILE_SV, "V�lj ljudinspelningsfil" },
/* tr */ { IDS_SELECT_RECORD_FILE_TR, "Ses Kay�t Dosyas� Se�in" },

/* en */ { IDS_SOUND_RECORD_FORMAT,    "Sound Record Format" },
/* da */ { IDS_SOUND_RECORD_FORMAT_DA, "Format for lydoptagelse" },
/* de */ { IDS_SOUND_RECORD_FORMAT_DE, "Tonaufnahmeformat" },
/* es */ { IDS_SOUND_RECORD_FORMAT_ES, "Formato grabaci�n de sonido" },
/* fr */ { IDS_SOUND_RECORD_FORMAT_FR, "" },  /* fuzzy */
/* hu */ { IDS_SOUND_RECORD_FORMAT_HU, "Hangfelv�tel form�tuma" },
/* it */ { IDS_SOUND_RECORD_FORMAT_IT, "Formato registrazione audio" },
/* ko */ { IDS_SOUND_RECORD_FORMAT_KO, "" },  /* fuzzy */
/* nl */ { IDS_SOUND_RECORD_FORMAT_NL, "Geluidsopname Formaat" },
/* pl */ { IDS_SOUND_RECORD_FORMAT_PL, "Format zapisu d�wi�ku" },
/* ru */ { IDS_SOUND_RECORD_FORMAT_RU, "" },  /* fuzzy */
/* sv */ { IDS_SOUND_RECORD_FORMAT_SV, "Format f�r ljudinspelning" },
/* tr */ { IDS_SOUND_RECORD_FORMAT_TR, "Ses Kay�t Bi�imi" },

/* en */ { IDS_SOUND_RECORD_FILE,    "Sound Record File" },
/* da */ { IDS_SOUND_RECORD_FILE_DA, "Lydoptagelsesfil" },
/* de */ { IDS_SOUND_RECORD_FILE_DE, "Tonaufnahmedatei" },
/* es */ { IDS_SOUND_RECORD_FILE_ES, "Fichero grabaci�n de sonido" },
/* fr */ { IDS_SOUND_RECORD_FILE_FR, "" },  /* fuzzy */
/* hu */ { IDS_SOUND_RECORD_FILE_HU, "Hangfelv�tel f�jl" },
/* it */ { IDS_SOUND_RECORD_FILE_IT, "File registrazione audio" },
/* ko */ { IDS_SOUND_RECORD_FILE_KO, "" },  /* fuzzy */
/* nl */ { IDS_SOUND_RECORD_FILE_NL, "Geluid opnamebestand" },
/* pl */ { IDS_SOUND_RECORD_FILE_PL, "Plik zapisu d�wi�ku" },
/* ru */ { IDS_SOUND_RECORD_FILE_RU, "" },  /* fuzzy */
/* sv */ { IDS_SOUND_RECORD_FILE_SV, "Ljudinspelningsfil" },
/* tr */ { IDS_SOUND_RECORD_FILE_TR, "Ses Kay�t Dosyas�" },

/* en */ { IDS_SOUND_RECORD_SETTINGS,    "Sound record settings" },
/* da */ { IDS_SOUND_RECORD_SETTINGS_DA, "Lydoptagelsesindstillinger" },
/* de */ { IDS_SOUND_RECORD_SETTINGS_DE, "Tonaufnahme Einstellungen" },
/* es */ { IDS_SOUND_RECORD_SETTINGS_ES, "Ajustes grabaci�n de sonido" },
/* fr */ { IDS_SOUND_RECORD_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_SOUND_RECORD_SETTINGS_HU, "Hangfelv�tel be�ll�t�sai" },
/* it */ { IDS_SOUND_RECORD_SETTINGS_IT, "Impostazioni registrazione audio" },
/* ko */ { IDS_SOUND_RECORD_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_SOUND_RECORD_SETTINGS_NL, "Geluidsopname instellingen" },
/* pl */ { IDS_SOUND_RECORD_SETTINGS_PL, "Ustawienia zapisu d�wi�ku" },
/* ru */ { IDS_SOUND_RECORD_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_SOUND_RECORD_SETTINGS_SV, "Inst�llningar f�r ljudinspelning" },
/* tr */ { IDS_SOUND_RECORD_SETTINGS_TR, "Ses kay�t ayarlar�" },

/* en */ { IDS_SMALL,    "Small" },
/* da */ { IDS_SMALL_DA, "Lille" },
/* de */ { IDS_SMALL_DE, "Klein" },
/* es */ { IDS_SMALL_ES, "Peque�o" },
/* fr */ { IDS_SMALL_FR, "Petit" },
/* hu */ { IDS_SMALL_HU, "Kicsi" },
/* it */ { IDS_SMALL_IT, "Piccolo" },
/* ko */ { IDS_SMALL_KO, "�۴�" },
/* nl */ { IDS_SMALL_NL, "Klein" },
/* pl */ { IDS_SMALL_PL, "Ma�y" },
/* ru */ { IDS_SMALL_RU, "" },  /* fuzzy */
/* sv */ { IDS_SMALL_SV, "Liten" },
/* tr */ { IDS_SMALL_TR, "K���k" },

/* en */ { IDS_MEDIUM,    "Medium" },
/* da */ { IDS_MEDIUM_DA, "Medium" },
/* de */ { IDS_MEDIUM_DE, "Mittel" },
/* es */ { IDS_MEDIUM_ES, "Medio" },
/* fr */ { IDS_MEDIUM_FR, "" },  /* fuzzy */
/* hu */ { IDS_MEDIUM_HU, "K�zepes" },
/* it */ { IDS_MEDIUM_IT, "Medio" },
/* ko */ { IDS_MEDIUM_KO, "�߰�" },
/* nl */ { IDS_MEDIUM_NL, "Middelmatig" },
/* pl */ { IDS_MEDIUM_PL, "�redni" },
/* ru */ { IDS_MEDIUM_RU, "" },  /* fuzzy */
/* sv */ { IDS_MEDIUM_SV, "Medium" },
/* tr */ { IDS_MEDIUM_TR, "Orta" },

/* en */ { IDS_LARGE,    "Large" },
/* da */ { IDS_LARGE_DA, "Stor" },
/* de */ { IDS_LARGE_DE, "Gro�" },
/* es */ { IDS_LARGE_ES, "Grande" },
/* fr */ { IDS_LARGE_FR, "" },  /* fuzzy */
/* hu */ { IDS_LARGE_HU, "Nagy" },
/* it */ { IDS_LARGE_IT, "Grande" },
/* ko */ { IDS_LARGE_KO, "ū" },
/* nl */ { IDS_LARGE_NL, "Groot" },
/* pl */ { IDS_LARGE_PL, "Wielki" },
/* ru */ { IDS_LARGE_RU, "" },  /* fuzzy */
/* sv */ { IDS_LARGE_SV, "Stor" },
/* tr */ { IDS_LARGE_TR, "B�y�k" },

/* en */ { IDS_BORDER_MODE,    "Border mode" },
/* da */ { IDS_BORDER_MODE_DA, "Ramme-tilstand" },
/* de */ { IDS_BORDER_MODE_DE, "Rahmen Modus" },
/* es */ { IDS_BORDER_MODE_ES, "Modo del borde" },
/* fr */ { IDS_BORDER_MODE_FR, "" },  /* fuzzy */
/* hu */ { IDS_BORDER_MODE_HU, "Keret m�d" },
/* it */ { IDS_BORDER_MODE_IT, "Modalit� del bordo" },
/* ko */ { IDS_BORDER_MODE_KO, "���� ���" },
/* nl */ { IDS_BORDER_MODE_NL, "Bordermodus" },
/* pl */ { IDS_BORDER_MODE_PL, "Tryb ramki" },
/* ru */ { IDS_BORDER_MODE_RU, "" },  /* fuzzy */
/* sv */ { IDS_BORDER_MODE_SV, "Raml�ge" },
/* tr */ { IDS_BORDER_MODE_TR, "�er�eve modu" },

/* en */ { IDMS_NORMAL,    "Normal" },
/* da */ { IDMS_NORMAL_DA, "Normal" },
/* de */ { IDMS_NORMAL_DE, "Normal" },
/* es */ { IDMS_NORMAL_ES, "Normal" },
/* fr */ { IDMS_NORMAL_FR, "Normal" },
/* hu */ { IDMS_NORMAL_HU, "Norm�l" },
/* it */ { IDMS_NORMAL_IT, "Normale" },
/* ko */ { IDMS_NORMAL_KO, "����" },
/* nl */ { IDMS_NORMAL_NL, "Normaal" },
/* pl */ { IDMS_NORMAL_PL, "Zwyk�y" },
/* ru */ { IDMS_NORMAL_RU, "" },  /* fuzzy */
/* sv */ { IDMS_NORMAL_SV, "Normal" },
/* tr */ { IDMS_NORMAL_TR, "Normal" },

/* en */ { IDS_FULL,    "Full" },
/* da */ { IDS_FULL_DA, "Fuld" },
/* de */ { IDS_FULL_DE, "Full" },
/* es */ { IDS_FULL_ES, "Completo" },
/* fr */ { IDS_FULL_FR, "" },  /* fuzzy */
/* hu */ { IDS_FULL_HU, "Teljes" },
/* it */ { IDS_FULL_IT, "Intero" },
/* ko */ { IDS_FULL_KO, "����" },
/* nl */ { IDS_FULL_NL, "Volledig" },
/* pl */ { IDS_FULL_PL, "Pe�ny" },
/* ru */ { IDS_FULL_RU, "" },  /* fuzzy */
/* sv */ { IDS_FULL_SV, "Full" },
/* tr */ { IDS_FULL_TR, "Tam" },

/* en */ { IDS_DEBUG,    "Debug" },
/* da */ { IDS_DEBUG_DA, "Debug" },
/* de */ { IDS_DEBUG_DE, "Debug" },
/* es */ { IDS_DEBUG_ES, "Depurar" },
/* fr */ { IDS_DEBUG_FR, "D�bug" },
/* hu */ { IDS_DEBUG_HU, "Nyomk�vet�s" },
/* it */ { IDS_DEBUG_IT, "Debug" },
/* ko */ { IDS_DEBUG_KO, "���" },
/* nl */ { IDS_DEBUG_NL, "Debug" },
/* pl */ { IDS_DEBUG_PL, "Debug" },
/* ru */ { IDS_DEBUG_RU, "" },  /* fuzzy */
/* sv */ { IDS_DEBUG_SV, "Fels�k" },
/* tr */ { IDS_DEBUG_TR, "Hata Ay�klama" },

/* en */ { IDS_VOLUME,    "Volume (0-100%)" },
/* da */ { IDS_VOLUME_DA, "Volume (0-100 %)" },
/* de */ { IDS_VOLUME_DE, "Lautst�rke (0-100%)" },
/* es */ { IDS_VOLUME_ES, "Volumen (0-100%)" },
/* fr */ { IDS_VOLUME_FR, "Volume (0-100%)" },
/* hu */ { IDS_VOLUME_HU, "Hanger� (0-100%)" },
/* it */ { IDS_VOLUME_IT, "Volume (0-100%)" },
/* ko */ { IDS_VOLUME_KO, "���� (0-100%)" },
/* nl */ { IDS_VOLUME_NL, "Volume (0-100%)" },
/* pl */ { IDS_VOLUME_PL, "G�o�no�� (0-100%)" },
/* ru */ { IDS_VOLUME_RU, "" },  /* fuzzy */
/* sv */ { IDS_VOLUME_SV, "Volym (0-100 %)" },
/* tr */ { IDS_VOLUME_TR, "Ses D�zeyi (0-100%)" },

/* en */ { IDS_MOUSE_TYPE,    "Mouse type" },
/* da */ { IDS_MOUSE_TYPE_DA, "Mussetype" },
/* de */ { IDS_MOUSE_TYPE_DE, "Maustyp" },
/* es */ { IDS_MOUSE_TYPE_ES, "Tipo rat�n" },
/* fr */ { IDS_MOUSE_TYPE_FR, "Type de souris" },
/* hu */ { IDS_MOUSE_TYPE_HU, "Eg�r t�pusa" },
/* it */ { IDS_MOUSE_TYPE_IT, "Tipo di mouse" },
/* ko */ { IDS_MOUSE_TYPE_KO, "���콺 Ÿ��" },
/* nl */ { IDS_MOUSE_TYPE_NL, "Muis soort" },
/* pl */ { IDS_MOUSE_TYPE_PL, "Typ myszy" },
/* ru */ { IDS_MOUSE_TYPE_RU, "" },  /* fuzzy */
/* sv */ { IDS_MOUSE_TYPE_SV, "Mustyp" },
/* tr */ { IDS_MOUSE_TYPE_TR, "Mouse tipi" },

/* en */ { IDS_MOUSE_SETTINGS,    "Mouse settings" },
/* da */ { IDS_MOUSE_SETTINGS_DA, "Musseindstillinger" },
/* de */ { IDS_MOUSE_SETTINGS_DE, "Maus Einstellungen" },
/* es */ { IDS_MOUSE_SETTINGS_ES, "Ajustes rat�n" },
/* fr */ { IDS_MOUSE_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_MOUSE_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_MOUSE_SETTINGS_IT, "Impostazioni mouse" },
/* ko */ { IDS_MOUSE_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_MOUSE_SETTINGS_NL, "Muis instellingen" },
/* pl */ { IDS_MOUSE_SETTINGS_PL, "Ustawienia myszy" },
/* ru */ { IDS_MOUSE_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_MOUSE_SETTINGS_SV, "Musinst�llningar" },
/* tr */ { IDS_MOUSE_SETTINGS_TR, "Mouse Ayarlar�" },

/* en */ { IDS_MOUSE_PORT,    "Mouse port" },
/* da */ { IDS_MOUSE_PORT_DA, "Musseport" },
/* de */ { IDS_MOUSE_PORT_DE, "Maus Port" },
/* es */ { IDS_MOUSE_PORT_ES, "Puerto del rat�n" },
/* fr */ { IDS_MOUSE_PORT_FR, "Port de la souris" },
/* hu */ { IDS_MOUSE_PORT_HU, "Eg�r port" },
/* it */ { IDS_MOUSE_PORT_IT, "Porta del mouse" },
/* ko */ { IDS_MOUSE_PORT_KO, "���콺 ��Ʈ" },
/* nl */ { IDS_MOUSE_PORT_NL, "Muis poort" },
/* pl */ { IDS_MOUSE_PORT_PL, "Port myszy" },
/* ru */ { IDS_MOUSE_PORT_RU, "" },  /* fuzzy */
/* sv */ { IDS_MOUSE_PORT_SV, "Musport" },
/* tr */ { IDS_MOUSE_PORT_TR, "Mouse portu" },

/* en */ { IDS_MOUSE_1351,    "1351 mouse" },
/* da */ { IDS_MOUSE_1351_DA, "1351-mus" },
/* de */ { IDS_MOUSE_1351_DE, "1351 Maus" },
/* es */ { IDS_MOUSE_1351_ES, "Rat�n 1531" },
/* fr */ { IDS_MOUSE_1351_FR, "Souris 1351" },
/* hu */ { IDS_MOUSE_1351_HU, "1351 eg�r" },
/* it */ { IDS_MOUSE_1351_IT, "Mouse 1351" },
/* ko */ { IDS_MOUSE_1351_KO, "1351 ���콺" },
/* nl */ { IDS_MOUSE_1351_NL, "1351 muis" },
/* pl */ { IDS_MOUSE_1351_PL, "Mysz 1351" },
/* ru */ { IDS_MOUSE_1351_RU, "" },  /* fuzzy */
/* sv */ { IDS_MOUSE_1351_SV, "1351-mus" },
/* tr */ { IDS_MOUSE_1351_TR, "1351 mouse" },

/* en */ { IDS_MOUSE_NEOS,    "NEOS mouse" },
/* da */ { IDS_MOUSE_NEOS_DA, "NEOS-mus" },
/* de */ { IDS_MOUSE_NEOS_DE, "NEOS Maus" },
/* es */ { IDS_MOUSE_NEOS_ES, "Rat�n NEOS" },
/* fr */ { IDS_MOUSE_NEOS_FR, "Souris NEOS" },
/* hu */ { IDS_MOUSE_NEOS_HU, "NEOS eg�r" },
/* it */ { IDS_MOUSE_NEOS_IT, "Mouse NEOS" },
/* ko */ { IDS_MOUSE_NEOS_KO, "" },  /* fuzzy */
/* nl */ { IDS_MOUSE_NEOS_NL, "NEOS muis" },
/* pl */ { IDS_MOUSE_NEOS_PL, "Mysz NEOS" },
/* ru */ { IDS_MOUSE_NEOS_RU, "" },  /* fuzzy */
/* sv */ { IDS_MOUSE_NEOS_SV, "NEOS-mus" },
/* tr */ { IDS_MOUSE_NEOS_TR, "NEOS mouse" },

/* en */ { IDS_MOUSE_AMIGA,    "Amiga mouse" },
/* da */ { IDS_MOUSE_AMIGA_DA, "Amigamus" },
/* de */ { IDS_MOUSE_AMIGA_DE, "Amiga Maus" },
/* es */ { IDS_MOUSE_AMIGA_ES, "Rat�n Amiga" },
/* fr */ { IDS_MOUSE_AMIGA_FR, "Souris Amiga" },
/* hu */ { IDS_MOUSE_AMIGA_HU, "Amiga eg�r" },
/* it */ { IDS_MOUSE_AMIGA_IT, "Mouse Amiga" },
/* ko */ { IDS_MOUSE_AMIGA_KO, "" },  /* fuzzy */
/* nl */ { IDS_MOUSE_AMIGA_NL, "Amiga muis" },
/* pl */ { IDS_MOUSE_AMIGA_PL, "Mysz z Amigi" },
/* ru */ { IDS_MOUSE_AMIGA_RU, "" },  /* fuzzy */
/* sv */ { IDS_MOUSE_AMIGA_SV, "Amigamus" },
/* tr */ { IDS_MOUSE_AMIGA_TR, "Amiga mouse" },

/* en */ { IDS_MOUSE_PADDLES,    "Paddles" },
/* da */ { IDS_MOUSE_PADDLES_DA, "Paddles" },
/* de */ { IDS_MOUSE_PADDLES_DE, "Paddles" },
/* es */ { IDS_MOUSE_PADDLES_ES, "Paddles" },
/* fr */ { IDS_MOUSE_PADDLES_FR, "" },  /* fuzzy */
/* hu */ { IDS_MOUSE_PADDLES_HU, "" },  /* fuzzy */
/* it */ { IDS_MOUSE_PADDLES_IT, "Paddle" },
/* ko */ { IDS_MOUSE_PADDLES_KO, "�е�" },
/* nl */ { IDS_MOUSE_PADDLES_NL, "Paddles" },
/* pl */ { IDS_MOUSE_PADDLES_PL, "Pokr�t�a steruj�ce" },
/* ru */ { IDS_MOUSE_PADDLES_RU, "" },  /* fuzzy */
/* sv */ { IDS_MOUSE_PADDLES_SV, "Paddlar" },
/* tr */ { IDS_MOUSE_PADDLES_TR, "Paddlelar" },

/* en */ { IDS_MOUSE_CX22,    "Atari CX-22 trackball" },
/* da */ { IDS_MOUSE_CX22_DA, "" },  /* fuzzy */
/* de */ { IDS_MOUSE_CX22_DE, "Atari CX-22 Trackball" },
/* es */ { IDS_MOUSE_CX22_ES, "Trackball Atari CX-22" },
/* fr */ { IDS_MOUSE_CX22_FR, "" },  /* fuzzy */
/* hu */ { IDS_MOUSE_CX22_HU, "" },  /* fuzzy */
/* it */ { IDS_MOUSE_CX22_IT, "" },  /* fuzzy */
/* ko */ { IDS_MOUSE_CX22_KO, "" },  /* fuzzy */
/* nl */ { IDS_MOUSE_CX22_NL, "Atari CX-22 trackball" },
/* pl */ { IDS_MOUSE_CX22_PL, "Trackball Atari CX-22" },
/* ru */ { IDS_MOUSE_CX22_RU, "" },  /* fuzzy */
/* sv */ { IDS_MOUSE_CX22_SV, "" },  /* fuzzy */
/* tr */ { IDS_MOUSE_CX22_TR, "" },  /* fuzzy */

/* en */ { IDS_MOUSE_ST,    "Atari ST mouse" },
/* da */ { IDS_MOUSE_ST_DA, "" },  /* fuzzy */
/* de */ { IDS_MOUSE_ST_DE, "Amiga ST Maus" },
/* es */ { IDS_MOUSE_ST_ES, "Rat�n Atari ST" },
/* fr */ { IDS_MOUSE_ST_FR, "" },  /* fuzzy */
/* hu */ { IDS_MOUSE_ST_HU, "" },  /* fuzzy */
/* it */ { IDS_MOUSE_ST_IT, "" },  /* fuzzy */
/* ko */ { IDS_MOUSE_ST_KO, "" },  /* fuzzy */
/* nl */ { IDS_MOUSE_ST_NL, "Atari ST muis" },
/* pl */ { IDS_MOUSE_ST_PL, "Mysz z Atari ST" },
/* ru */ { IDS_MOUSE_ST_RU, "" },  /* fuzzy */
/* sv */ { IDS_MOUSE_ST_SV, "" },  /* fuzzy */
/* tr */ { IDS_MOUSE_ST_TR, "" },  /* fuzzy */

/* en */ { IDS_AUTOSTART_VIRTUAL_FS,    "Virtual FS" },
/* da */ { IDS_AUTOSTART_VIRTUAL_FS_DA, "Virtuelt FS" },
/* de */ { IDS_AUTOSTART_VIRTUAL_FS_DE, "Virtual FS" },
/* es */ { IDS_AUTOSTART_VIRTUAL_FS_ES, "FS virtual" },
/* fr */ { IDS_AUTOSTART_VIRTUAL_FS_FR, "" },  /* fuzzy */
/* hu */ { IDS_AUTOSTART_VIRTUAL_FS_HU, "Virtu�lis f�jlrendszer" },
/* it */ { IDS_AUTOSTART_VIRTUAL_FS_IT, "Virtual FS" },
/* ko */ { IDS_AUTOSTART_VIRTUAL_FS_KO, "���߾� ���Ͻ�Ÿ��" },
/* nl */ { IDS_AUTOSTART_VIRTUAL_FS_NL, "Virtueel Bestandssysteem" },
/* pl */ { IDS_AUTOSTART_VIRTUAL_FS_PL, "Wirtualny system plik�w" },
/* ru */ { IDS_AUTOSTART_VIRTUAL_FS_RU, "" },  /* fuzzy */
/* sv */ { IDS_AUTOSTART_VIRTUAL_FS_SV, "Virtuellt FS" },
/* tr */ { IDS_AUTOSTART_VIRTUAL_FS_TR, "Sanal FS" },

/* en */ { IDS_AUTOSTART_INJECT,    "Inject to RAM" },
/* da */ { IDS_AUTOSTART_INJECT_DA, "Indskyd til RAM" },
/* de */ { IDS_AUTOSTART_INJECT_DE, "Inject ins RAM" },
/* es */ { IDS_AUTOSTART_INJECT_ES, "Introducir en RAM" },
/* fr */ { IDS_AUTOSTART_INJECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_AUTOSTART_INJECT_HU, "" },  /* fuzzy */
/* it */ { IDS_AUTOSTART_INJECT_IT, "Immetti su RAM" },
/* ko */ { IDS_AUTOSTART_INJECT_KO, "RAM �� �����ϱ�" },
/* nl */ { IDS_AUTOSTART_INJECT_NL, "injecteer in RAM" },
/* pl */ { IDS_AUTOSTART_INJECT_PL, "Wstrzyknij w RAM" },
/* ru */ { IDS_AUTOSTART_INJECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_AUTOSTART_INJECT_SV, "L�gg in i RAM" },
/* tr */ { IDS_AUTOSTART_INJECT_TR, "RAM'e enjekte et" },

/* en */ { IDS_AUTOSTART_DISK,    "Disk image" },
/* da */ { IDS_AUTOSTART_DISK_DA, "Diskimage" },
/* de */ { IDS_AUTOSTART_DISK_DE, "Disk Image" },
/* es */ { IDS_AUTOSTART_DISK_ES, "Imagen de disco" },
/* fr */ { IDS_AUTOSTART_DISK_FR, "Image de disque" },
/* hu */ { IDS_AUTOSTART_DISK_HU, "Lemez k�pm�s" },
/* it */ { IDS_AUTOSTART_DISK_IT, "Immagine disco" },
/* ko */ { IDS_AUTOSTART_DISK_KO, "��ũ �̹���" },
/* nl */ { IDS_AUTOSTART_DISK_NL, "Disk bestand" },
/* pl */ { IDS_AUTOSTART_DISK_PL, "Obraz dyskietki" },
/* ru */ { IDS_AUTOSTART_DISK_RU, "" },  /* fuzzy */
/* sv */ { IDS_AUTOSTART_DISK_SV, "Diskavbildning" },
/* tr */ { IDS_AUTOSTART_DISK_TR, "Disk imaj�" },

/* en */ { IDS_AUTOSTART_DISK_IMAGE_SELECT,    "Select file for PRG autostart disk" },
/* da */ { IDS_AUTOSTART_DISK_IMAGE_SELECT_DA, "V�lg fil for PRG autostartdiskette" },
/* de */ { IDS_AUTOSTART_DISK_IMAGE_SELECT_DE, "Datei f�r PRG Autostart ausw�hlen" },
/* es */ { IDS_AUTOSTART_DISK_IMAGE_SELECT_ES, "Seleccionar fichero par autorranque disco para PRG" },
/* fr */ { IDS_AUTOSTART_DISK_IMAGE_SELECT_FR, "" },  /* fuzzy */
/* hu */ { IDS_AUTOSTART_DISK_IMAGE_SELECT_HU, "V�lasszon lemezf�jlt a PRG automatikus ind�t�shoz" },
/* it */ { IDS_AUTOSTART_DISK_IMAGE_SELECT_IT, "Seleziona file per avvio automatico PRG" },
/* ko */ { IDS_AUTOSTART_DISK_IMAGE_SELECT_KO, "" },  /* fuzzy */
/* nl */ { IDS_AUTOSTART_DISK_IMAGE_SELECT_NL, "Selecteer bestand voor PRG autostart disk" },
/* pl */ { IDS_AUTOSTART_DISK_IMAGE_SELECT_PL, "Wybierz plik dysku do automatycznego startu z PRG" },
/* ru */ { IDS_AUTOSTART_DISK_IMAGE_SELECT_RU, "" },  /* fuzzy */
/* sv */ { IDS_AUTOSTART_DISK_IMAGE_SELECT_SV, "V�lj fil f�r PRG-autostartdisk" },
/* tr */ { IDS_AUTOSTART_DISK_IMAGE_SELECT_TR, "PRG otomatik ba�latma i�in dosya se�in" },

/* en */ { IDS_WARP_ON_AUTOSTART,    "Autostart warp" },
/* da */ { IDS_WARP_ON_AUTOSTART_DA, "Autostart i warp-tilstand" },
/* de */ { IDS_WARP_ON_AUTOSTART_DE, "Autostart Warp" },
/* es */ { IDS_WARP_ON_AUTOSTART_ES, "Autoarranque Warp" },
/* fr */ { IDS_WARP_ON_AUTOSTART_FR, "" },  /* fuzzy */
/* hu */ { IDS_WARP_ON_AUTOSTART_HU, "Automatikus ind�t�s hipergyors" },
/* it */ { IDS_WARP_ON_AUTOSTART_IT, "Avvio automatico in turbo" },
/* ko */ { IDS_WARP_ON_AUTOSTART_KO, "�ڵ� ���� warp" },
/* nl */ { IDS_WARP_ON_AUTOSTART_NL, "Autostart warp" },
/* pl */ { IDS_WARP_ON_AUTOSTART_PL, "Turbo przy autostarcie" },
/* ru */ { IDS_WARP_ON_AUTOSTART_RU, "" },  /* fuzzy */
/* sv */ { IDS_WARP_ON_AUTOSTART_SV, "Starta warp automatiskt" },
/* tr */ { IDS_WARP_ON_AUTOSTART_TR, "Warp modunda otomatik ba�lat" },

/* en */ { IDS_RUN_WITH_COLON,    "Use ':' with RUN" },
/* da */ { IDS_RUN_WITH_COLON_DA, "Brug \":\" med RUN" },
/* de */ { IDS_RUN_WITH_COLON_DE, "Verwende ':' mit RUN" },
/* es */ { IDS_RUN_WITH_COLON_ES, "Usar ':' con RUN" },
/* fr */ { IDS_RUN_WITH_COLON_FR, "" },  /* fuzzy */
/* hu */ { IDS_RUN_WITH_COLON_HU, "" },  /* fuzzy */
/* it */ { IDS_RUN_WITH_COLON_IT, "Usa ':' con RUN" },
/* ko */ { IDS_RUN_WITH_COLON_KO, "':' �� RUN �� ����ϱ�" },
/* nl */ { IDS_RUN_WITH_COLON_NL, "Gebruik ':' met RUN" },
/* pl */ { IDS_RUN_WITH_COLON_PL, "U�ywaj ':' z RUN" },
/* ru */ { IDS_RUN_WITH_COLON_RU, "" },  /* fuzzy */
/* sv */ { IDS_RUN_WITH_COLON_SV, "Anv�nd \":\" med RUN" },
/* tr */ { IDS_RUN_WITH_COLON_TR, "�ALI�TIR ile ':' kullan" },

/* en */ { IDS_AUTOSTART_PRG_MODE,    "PRG autostart mode" },
/* da */ { IDS_AUTOSTART_PRG_MODE_DA, "PRG-autostarttilstand" },
/* de */ { IDS_AUTOSTART_PRG_MODE_DE, "PRG Autostartmodus" },
/* es */ { IDS_AUTOSTART_PRG_MODE_ES, "Modo autoarranque PRG" },
/* fr */ { IDS_AUTOSTART_PRG_MODE_FR, "" },  /* fuzzy */
/* hu */ { IDS_AUTOSTART_PRG_MODE_HU, "PRG automatikus ind�t�s m�d" },
/* it */ { IDS_AUTOSTART_PRG_MODE_IT, "Avvio automatico PRG" },
/* ko */ { IDS_AUTOSTART_PRG_MODE_KO, "PRG ���佺��Ʈ ���" },
/* nl */ { IDS_AUTOSTART_PRG_MODE_NL, "PRG autostart modus" },
/* pl */ { IDS_AUTOSTART_PRG_MODE_PL, "Tryb autostartu z PRG" },
/* ru */ { IDS_AUTOSTART_PRG_MODE_RU, "" },  /* fuzzy */
/* sv */ { IDS_AUTOSTART_PRG_MODE_SV, "Autostartl�ge f�r PRG" },
/* tr */ { IDS_AUTOSTART_PRG_MODE_TR, "PRG otomatik ba�latma modu" },

/* en */ { IDS_AUTOSTART_LOAD_TO_BASIC_START,    "Load to BASIC start" },
/* da */ { IDS_AUTOSTART_LOAD_TO_BASIC_START_DA, "Indl�s ved BASIC start" },
/* de */ { IDS_AUTOSTART_LOAD_TO_BASIC_START_DE, "Lade an Basic Start" },
/* es */ { IDS_AUTOSTART_LOAD_TO_BASIC_START_ES, "Cargar a inicio BASIC" },
/* fr */ { IDS_AUTOSTART_LOAD_TO_BASIC_START_FR, "" },  /* fuzzy */
/* hu */ { IDS_AUTOSTART_LOAD_TO_BASIC_START_HU, "" },  /* fuzzy */
/* it */ { IDS_AUTOSTART_LOAD_TO_BASIC_START_IT, "Carica all'inizio del BASIC" },
/* ko */ { IDS_AUTOSTART_LOAD_TO_BASIC_START_KO, "BASIC ���� �� �ε��ϱ�" },
/* nl */ { IDS_AUTOSTART_LOAD_TO_BASIC_START_NL, "Laad naar BASIC start" },
/* pl */ { IDS_AUTOSTART_LOAD_TO_BASIC_START_PL, "Wczytuj do BASIC-a" },
/* ru */ { IDS_AUTOSTART_LOAD_TO_BASIC_START_RU, "" },  /* fuzzy */
/* sv */ { IDS_AUTOSTART_LOAD_TO_BASIC_START_SV, "L�s till BASIC-start" },
/* tr */ { IDS_AUTOSTART_LOAD_TO_BASIC_START_TR, "BASIC ba�lang�c�na y�kle" },

/* en */ { IDS_AUTOSTART_DISK_IMAGE_FILENAME,    "PRG autostart disk image" },
/* da */ { IDS_AUTOSTART_DISK_IMAGE_FILENAME_DA, "PRG Autostart disk-image" },
/* de */ { IDS_AUTOSTART_DISK_IMAGE_FILENAME_DE, "PRG Autostart Disk Image" },
/* es */ { IDS_AUTOSTART_DISK_IMAGE_FILENAME_ES, "Autoarranque imagen disco PRG" },
/* fr */ { IDS_AUTOSTART_DISK_IMAGE_FILENAME_FR, "" },  /* fuzzy */
/* hu */ { IDS_AUTOSTART_DISK_IMAGE_FILENAME_HU, "PRG automatikus ind�t�s k�pm�s" },
/* it */ { IDS_AUTOSTART_DISK_IMAGE_FILENAME_IT, "Immagine disco avvio automatico PRG" },
/* ko */ { IDS_AUTOSTART_DISK_IMAGE_FILENAME_KO, "PRG ���佺��Ʈ ��ũ �̹���" },
/* nl */ { IDS_AUTOSTART_DISK_IMAGE_FILENAME_NL, "PRG autostart disk bestand" },
/* pl */ { IDS_AUTOSTART_DISK_IMAGE_FILENAME_PL, "Obraz dyskietki do autostartu z PRG" },
/* ru */ { IDS_AUTOSTART_DISK_IMAGE_FILENAME_RU, "" },  /* fuzzy */
/* sv */ { IDS_AUTOSTART_DISK_IMAGE_FILENAME_SV, "Autostartdiskavbildning f�r PRG" },
/* tr */ { IDS_AUTOSTART_DISK_IMAGE_FILENAME_TR, "PRG otomatik ba�latma disk imaj�" },

/* en */ { IDS_AUTOSTART_SETTINGS,    "Autostart settings" },
/* da */ { IDS_AUTOSTART_SETTINGS_DA, "Autostart-indstillinger" },
/* de */ { IDS_AUTOSTART_SETTINGS_DE, "Autostart Einstellungen" },
/* es */ { IDS_AUTOSTART_SETTINGS_ES, "Ajustes de autoinicio" },
/* fr */ { IDS_AUTOSTART_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_AUTOSTART_SETTINGS_HU, "Autostart be�ll�t�sai" },
/* it */ { IDS_AUTOSTART_SETTINGS_IT, "Impostazioni avvio automatico" },
/* ko */ { IDS_AUTOSTART_SETTINGS_KO, "�ڵ����� ����" },
/* nl */ { IDS_AUTOSTART_SETTINGS_NL, "Autostart instellingen" },
/* pl */ { IDS_AUTOSTART_SETTINGS_PL, "Ustawienia autostartu" },
/* ru */ { IDS_AUTOSTART_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_AUTOSTART_SETTINGS_SV, "Autostartinst�llningar" },
/* tr */ { IDS_AUTOSTART_SETTINGS_TR, "Otomatik ba�latma ayarlar�" },

/* en */ { IDS_ERROR_SAVING_EASYFLASH_CRT,    "Error saving EasyFlash crt file" },
/* da */ { IDS_ERROR_SAVING_EASYFLASH_CRT_DA, "Fejl under skrivning af EasyFlash CRT-fil" },
/* de */ { IDS_ERROR_SAVING_EASYFLASH_CRT_DE, "Fehler beim Speichern der EasyFlash CRT Datei" },
/* es */ { IDS_ERROR_SAVING_EASYFLASH_CRT_ES, "Error al grabar fichero EasyFlash crt" },
/* fr */ { IDS_ERROR_SAVING_EASYFLASH_CRT_FR, "" },  /* fuzzy */
/* hu */ { IDS_ERROR_SAVING_EASYFLASH_CRT_HU, "Hiba az EasyFlash crt f�jl ment�se k�zben" },
/* it */ { IDS_ERROR_SAVING_EASYFLASH_CRT_IT, "Errore durante il salvataggio del file crt EasyFlash" },
/* ko */ { IDS_ERROR_SAVING_EASYFLASH_CRT_KO, "" },  /* fuzzy */
/* nl */ { IDS_ERROR_SAVING_EASYFLASH_CRT_NL, "Kan het EasyFlash crt bestand niet opslaan" },
/* pl */ { IDS_ERROR_SAVING_EASYFLASH_CRT_PL, "B��d zapisu pliku crt EasyFlash" },
/* ru */ { IDS_ERROR_SAVING_EASYFLASH_CRT_RU, "" },  /* fuzzy */
/* sv */ { IDS_ERROR_SAVING_EASYFLASH_CRT_SV, "Fel vid skrivning av EasyFlash-crt-fil." },
/* tr */ { IDS_ERROR_SAVING_EASYFLASH_CRT_TR, "EasyFlash crt dosyas� kay�t hatas�" },

/* en */ { IDS_EASYFLASH_JUMPER,    "EasyFlash jumper" },
/* da */ { IDS_EASYFLASH_JUMPER_DA, "EasyFlashjumper" },
/* de */ { IDS_EASYFLASH_JUMPER_DE, "EasyFlash Jumper" },
/* es */ { IDS_EASYFLASH_JUMPER_ES, "Puente EasyFlash" },
/* fr */ { IDS_EASYFLASH_JUMPER_FR, "" },  /* fuzzy */
/* hu */ { IDS_EASYFLASH_JUMPER_HU, "EasyFlash jumper" },
/* it */ { IDS_EASYFLASH_JUMPER_IT, "Ponticello EasyFlash" },
/* ko */ { IDS_EASYFLASH_JUMPER_KO, "" },  /* fuzzy */
/* nl */ { IDS_EASYFLASH_JUMPER_NL, "EasyFlash jumper" },
/* pl */ { IDS_EASYFLASH_JUMPER_PL, "Prze��cznik EasyFlash" },
/* ru */ { IDS_EASYFLASH_JUMPER_RU, "" },  /* fuzzy */
/* sv */ { IDS_EASYFLASH_JUMPER_SV, "EasyFlash-bygel" },
/* tr */ { IDS_EASYFLASH_JUMPER_TR, "EasyFlash jumper" },

/* en */ { IDS_SAVE_EASYFLASH_CRT_ON_DETACH,    "Save to EasyFlash CRT file on detach" },
/* da */ { IDS_SAVE_EASYFLASH_CRT_ON_DETACH_DA, "Gem til EasyFlash CRT-fil ved afbrydelse" },
/* de */ { IDS_SAVE_EASYFLASH_CRT_ON_DETACH_DE, "EasyFlash CRT Imagedatei beim entfernen speichern" },
/* es */ { IDS_SAVE_EASYFLASH_CRT_ON_DETACH_ES, "Grabar fichero al extraer EasyFlash CRT" },
/* fr */ { IDS_SAVE_EASYFLASH_CRT_ON_DETACH_FR, "" },  /* fuzzy */
/* hu */ { IDS_SAVE_EASYFLASH_CRT_ON_DETACH_HU, "EasyFlash CRT f�jl ment�se lev�laszt�skor" },
/* it */ { IDS_SAVE_EASYFLASH_CRT_ON_DETACH_IT, "Salva su file CRT EasyFlash alla rimozione" },
/* ko */ { IDS_SAVE_EASYFLASH_CRT_ON_DETACH_KO, "" },  /* fuzzy */
/* nl */ { IDS_SAVE_EASYFLASH_CRT_ON_DETACH_NL, "Sla op naar het EasyFlash CRT bestand bij ontkoppelen" },
/* pl */ { IDS_SAVE_EASYFLASH_CRT_ON_DETACH_PL, "Zapisz do pliku CRT Easy Flash przy od��czeniu" },
/* ru */ { IDS_SAVE_EASYFLASH_CRT_ON_DETACH_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_EASYFLASH_CRT_ON_DETACH_SV, "Spara till EasyFlash-CRT-fil vid fr�nkoppling" },
/* tr */ { IDS_SAVE_EASYFLASH_CRT_ON_DETACH_TR, "��kart�ld���nda EasyFlash CRT dosyas�na kaydet" },

/* en */ { IDS_SAVE_EASYFLASH_CRT_NOW,    "Save to EasyFlash CRT now" },
/* da */ { IDS_SAVE_EASYFLASH_CRT_NOW_DA, "Gem til EasyFlash CRT nu" },
/* de */ { IDS_SAVE_EASYFLASH_CRT_NOW_DE, "EasyFlash CRT Imagedatei jetzt speichern" },
/* es */ { IDS_SAVE_EASYFLASH_CRT_NOW_ES, "Grabar en EasyFlash CRT ahora" },
/* fr */ { IDS_SAVE_EASYFLASH_CRT_NOW_FR, "" },  /* fuzzy */
/* hu */ { IDS_SAVE_EASYFLASH_CRT_NOW_HU, "EasyFlash CRT f�jl ment�se most" },
/* it */ { IDS_SAVE_EASYFLASH_CRT_NOW_IT, "Salva su CRT EasyFlash ora" },
/* ko */ { IDS_SAVE_EASYFLASH_CRT_NOW_KO, "" },  /* fuzzy */
/* nl */ { IDS_SAVE_EASYFLASH_CRT_NOW_NL, "Sla nu op naar het EasyFlash CRT bestand" },
/* pl */ { IDS_SAVE_EASYFLASH_CRT_NOW_PL, "Zapisz do CRT Easy Flash teraz" },
/* ru */ { IDS_SAVE_EASYFLASH_CRT_NOW_RU, "" },  /* fuzzy */
/* sv */ { IDS_SAVE_EASYFLASH_CRT_NOW_SV, "Spara till EasyFlash-CRT nu" },
/* tr */ { IDS_SAVE_EASYFLASH_CRT_NOW_TR, "Hemen EasyFlash CRT'ye kaydet" },

/* en */ { IDS_6569_PAL,    "6569 (PAL)" },
/* da */ { IDS_6569_PAL_DA, "6569 (PAL)" },
/* de */ { IDS_6569_PAL_DE, "6569 (PAL)" },
/* es */ { IDS_6569_PAL_ES, "6569 (PAL)" },
/* fr */ { IDS_6569_PAL_FR, "" },  /* fuzzy */
/* hu */ { IDS_6569_PAL_HU, "" },  /* fuzzy */
/* it */ { IDS_6569_PAL_IT, "6569 (PAL)" },
/* ko */ { IDS_6569_PAL_KO, "" },  /* fuzzy */
/* nl */ { IDS_6569_PAL_NL, "6569 (PAL)" },
/* pl */ { IDS_6569_PAL_PL, "6569 (PAL)" },
/* ru */ { IDS_6569_PAL_RU, "" },  /* fuzzy */
/* sv */ { IDS_6569_PAL_SV, "6569 (PAL)" },
/* tr */ { IDS_6569_PAL_TR, "6569 (PAL)" },

/* en */ { IDS_8565_PAL,    "8565 (PAL)" },
/* da */ { IDS_8565_PAL_DA, "8565 (PAL)" },
/* de */ { IDS_8565_PAL_DE, "8565 (PAL)" },
/* es */ { IDS_8565_PAL_ES, "8565 (PAL)" },
/* fr */ { IDS_8565_PAL_FR, "" },  /* fuzzy */
/* hu */ { IDS_8565_PAL_HU, "" },  /* fuzzy */
/* it */ { IDS_8565_PAL_IT, "8565 (PAL)" },
/* ko */ { IDS_8565_PAL_KO, "" },  /* fuzzy */
/* nl */ { IDS_8565_PAL_NL, "8565 (PAL)" },
/* pl */ { IDS_8565_PAL_PL, "8565 (PAL)" },
/* ru */ { IDS_8565_PAL_RU, "" },  /* fuzzy */
/* sv */ { IDS_8565_PAL_SV, "8565 (PAL)" },
/* tr */ { IDS_8565_PAL_TR, "8565 (PAL)" },

/* en */ { IDS_6569R1_OLD_PAL,    "6569R1 (old PAL)" },
/* da */ { IDS_6569R1_OLD_PAL_DA, "6569R1 (gammel PAL)" },
/* de */ { IDS_6569R1_OLD_PAL_DE, "6569R1 (alt PAL)" },
/* es */ { IDS_6569R1_OLD_PAL_ES, "6569R1 (PAL antiguo)" },
/* fr */ { IDS_6569R1_OLD_PAL_FR, "" },  /* fuzzy */
/* hu */ { IDS_6569R1_OLD_PAL_HU, "" },  /* fuzzy */
/* it */ { IDS_6569R1_OLD_PAL_IT, "6569R1 (PAL vecchio)" },
/* ko */ { IDS_6569R1_OLD_PAL_KO, "6569R1 (�õ� PAL)" },
/* nl */ { IDS_6569R1_OLD_PAL_NL, "6569R1 (oud PAL)" },
/* pl */ { IDS_6569R1_OLD_PAL_PL, "6569R1 (stary PAL)" },
/* ru */ { IDS_6569R1_OLD_PAL_RU, "" },  /* fuzzy */
/* sv */ { IDS_6569R1_OLD_PAL_SV, "6569R1 (gammal PAL)" },
/* tr */ { IDS_6569R1_OLD_PAL_TR, "6569R1 (eski PAL)" },

/* en */ { IDS_6567_NTSC,    "6567 (NTSC)" },
/* da */ { IDS_6567_NTSC_DA, "6567 (NTSC)" },
/* de */ { IDS_6567_NTSC_DE, "6567 (NTSC)" },
/* es */ { IDS_6567_NTSC_ES, "6567 (NTSC)" },
/* fr */ { IDS_6567_NTSC_FR, "" },  /* fuzzy */
/* hu */ { IDS_6567_NTSC_HU, "" },  /* fuzzy */
/* it */ { IDS_6567_NTSC_IT, "6567 (NTSC)" },
/* ko */ { IDS_6567_NTSC_KO, "" },  /* fuzzy */
/* nl */ { IDS_6567_NTSC_NL, "6567 (NTSC)" },
/* pl */ { IDS_6567_NTSC_PL, "6567 (NTSC)" },
/* ru */ { IDS_6567_NTSC_RU, "" },  /* fuzzy */
/* sv */ { IDS_6567_NTSC_SV, "6567 (NTSC)" },
/* tr */ { IDS_6567_NTSC_TR, "6567 (NTSC)" },

/* en */ { IDS_8562_NTSC,    "8562 (NTSC)" },
/* da */ { IDS_8562_NTSC_DA, "8562 (NTSC)" },
/* de */ { IDS_8562_NTSC_DE, "8562 (NTSC)" },
/* es */ { IDS_8562_NTSC_ES, "8562 (NTSC)" },
/* fr */ { IDS_8562_NTSC_FR, "" },  /* fuzzy */
/* hu */ { IDS_8562_NTSC_HU, "" },  /* fuzzy */
/* it */ { IDS_8562_NTSC_IT, "8562 (NTSC)" },
/* ko */ { IDS_8562_NTSC_KO, "" },  /* fuzzy */
/* nl */ { IDS_8562_NTSC_NL, "8562 (NTSC)" },
/* pl */ { IDS_8562_NTSC_PL, "8562 (NTSC)" },
/* ru */ { IDS_8562_NTSC_RU, "" },  /* fuzzy */
/* sv */ { IDS_8562_NTSC_SV, "8562 (NTSC)" },
/* tr */ { IDS_8562_NTSC_TR, "8562 (NTSC)" },

/* en */ { IDS_6567R56A_OLD_NTSC,    "6567R56A (old NTSC)" },
/* da */ { IDS_6567R56A_OLD_NTSC_DA, "6567R56A (gammel NTSC)" },
/* de */ { IDS_6567R56A_OLD_NTSC_DE, "6567R56A (alt NTSC)" },
/* es */ { IDS_6567R56A_OLD_NTSC_ES, "6567R56A (NTSC antiguo)" },
/* fr */ { IDS_6567R56A_OLD_NTSC_FR, "" },  /* fuzzy */
/* hu */ { IDS_6567R56A_OLD_NTSC_HU, "" },  /* fuzzy */
/* it */ { IDS_6567R56A_OLD_NTSC_IT, "6567R56A (NTSC vecchio)" },
/* ko */ { IDS_6567R56A_OLD_NTSC_KO, "6567R56A (�õ� NTSC)" },
/* nl */ { IDS_6567R56A_OLD_NTSC_NL, "6567R56A (oud NTSC)" },
/* pl */ { IDS_6567R56A_OLD_NTSC_PL, "6567R56A (stary NTSC)" },
/* ru */ { IDS_6567R56A_OLD_NTSC_RU, "" },  /* fuzzy */
/* sv */ { IDS_6567R56A_OLD_NTSC_SV, "6567R56A (gammal NTSC)" },
/* tr */ { IDS_6567R56A_OLD_NTSC_TR, "6567R56A (eski NTSC)" },

/* en */ { IDS_6572_PAL_N,    "6572 (PAL-N)" },
/* da */ { IDS_6572_PAL_N_DA, "6572 (PAL-N)" },
/* de */ { IDS_6572_PAL_N_DE, "6572 (PAL-N)" },
/* es */ { IDS_6572_PAL_N_ES, "6572 (PAL-N)" },
/* fr */ { IDS_6572_PAL_N_FR, "" },  /* fuzzy */
/* hu */ { IDS_6572_PAL_N_HU, "" },  /* fuzzy */
/* it */ { IDS_6572_PAL_N_IT, "6572 (PAL-N)" },
/* ko */ { IDS_6572_PAL_N_KO, "" },  /* fuzzy */
/* nl */ { IDS_6572_PAL_N_NL, "6572 (PAL-N)" },
/* pl */ { IDS_6572_PAL_N_PL, "6572 (PAL-N)" },
/* ru */ { IDS_6572_PAL_N_RU, "" },  /* fuzzy */
/* sv */ { IDS_6572_PAL_N_SV, "6572 (PAL-N)" },
/* tr */ { IDS_6572_PAL_N_TR, "6572 (PAL-N)" },

/* en */ { IDS_6526_OLD,    "6526 (old)" },
/* da */ { IDS_6526_OLD_DA, "6526 (gammel)" },
/* de */ { IDS_6526_OLD_DE, "6526 (alt)" },
/* es */ { IDS_6526_OLD_ES, "6526 (antiguo)" },
/* fr */ { IDS_6526_OLD_FR, "" },  /* fuzzy */
/* hu */ { IDS_6526_OLD_HU, "" },  /* fuzzy */
/* it */ { IDS_6526_OLD_IT, "6526 (vecchio)" },
/* ko */ { IDS_6526_OLD_KO, "6526 (������)" },
/* nl */ { IDS_6526_OLD_NL, "6526 (oud)" },
/* pl */ { IDS_6526_OLD_PL, "6526 (stary)" },
/* ru */ { IDS_6526_OLD_RU, "" },  /* fuzzy */
/* sv */ { IDS_6526_OLD_SV, "6526 (gammal)" },
/* tr */ { IDS_6526_OLD_TR, "6526 (eski)" },

/* en */ { IDS_6526A_NEW,    "6526A (new)" },
/* da */ { IDS_6526A_NEW_DA, "6526A (ny)" },
/* de */ { IDS_6526A_NEW_DE, "6526A (neu)" },
/* es */ { IDS_6526A_NEW_ES, "6526A (nuevo)" },
/* fr */ { IDS_6526A_NEW_FR, "" },  /* fuzzy */
/* hu */ { IDS_6526A_NEW_HU, "" },  /* fuzzy */
/* it */ { IDS_6526A_NEW_IT, "6526A (nuovo)" },
/* ko */ { IDS_6526A_NEW_KO, "6526A (���ο�)" },
/* nl */ { IDS_6526A_NEW_NL, "6526A (nieuw)" },
/* pl */ { IDS_6526A_NEW_PL, "6526A (nowy)" },
/* ru */ { IDS_6526A_NEW_RU, "" },  /* fuzzy */
/* sv */ { IDS_6526A_NEW_SV, "6526A (ny)" },
/* tr */ { IDS_6526A_NEW_TR, "6526A (yeni)" },

/* en */ { IDS_DISCRETE,    "Discrete" },
/* da */ { IDS_DISCRETE_DA, "Diskret" },
/* de */ { IDS_DISCRETE_DE, "Diskret" },
/* es */ { IDS_DISCRETE_ES, "Discreto" },
/* fr */ { IDS_DISCRETE_FR, "" },  /* fuzzy */
/* hu */ { IDS_DISCRETE_HU, "" },  /* fuzzy */
/* it */ { IDS_DISCRETE_IT, "Discreto" },
/* ko */ { IDS_DISCRETE_KO, "�ٸ�" },
/* nl */ { IDS_DISCRETE_NL, "Diskreet" },
/* pl */ { IDS_DISCRETE_PL, "Dyskretny" },
/* ru */ { IDS_DISCRETE_RU, "" },  /* fuzzy */
/* sv */ { IDS_DISCRETE_SV, "Diskret" },
/* tr */ { IDS_DISCRETE_TR, "Ba�lant�y� kes" },

/* en */ { IDS_CUSTOM_IC,    "Custom IC" },
/* da */ { IDS_CUSTOM_IC_DA, "Egen IC" },
/* de */ { IDS_CUSTOM_IC_DE, "Benutzerdefinierte IC" },
/* es */ { IDS_CUSTOM_IC_ES, "IC habitual" },
/* fr */ { IDS_CUSTOM_IC_FR, "" },  /* fuzzy */
/* hu */ { IDS_CUSTOM_IC_HU, "" },  /* fuzzy */
/* it */ { IDS_CUSTOM_IC_IT, "IC personalizzato" },
/* ko */ { IDS_CUSTOM_IC_KO, "Ŀ���� IC" },
/* nl */ { IDS_CUSTOM_IC_NL, "Aangepast IC" },
/* pl */ { IDS_CUSTOM_IC_PL, "W�asne IC" },
/* ru */ { IDS_CUSTOM_IC_RU, "" },  /* fuzzy */
/* sv */ { IDS_CUSTOM_IC_SV, "Egen krets" },
/* tr */ { IDS_CUSTOM_IC_TR, "�zel IC" },

/* en */ { IDS_VICII_MODEL,    "VIC-II model" },
/* da */ { IDS_VICII_MODEL_DA, "VIC-II-model" },
/* de */ { IDS_VICII_MODEL_DE, "VIC-II Modell" },
/* es */ { IDS_VICII_MODEL_ES, "Modelo VIC-II" },
/* fr */ { IDS_VICII_MODEL_FR, "" },  /* fuzzy */
/* hu */ { IDS_VICII_MODEL_HU, "" },  /* fuzzy */
/* it */ { IDS_VICII_MODEL_IT, "Modello VIC-II" },
/* ko */ { IDS_VICII_MODEL_KO, "VIC-II ��" },
/* nl */ { IDS_VICII_MODEL_NL, "VIC-II model" },
/* pl */ { IDS_VICII_MODEL_PL, "Model VIC-II" },
/* ru */ { IDS_VICII_MODEL_RU, "������ VIC-II" },
/* sv */ { IDS_VICII_MODEL_SV, "VIC II-modell" },
/* tr */ { IDS_VICII_MODEL_TR, "VIC-II modeli" },

/* en */ { IDS_CIA1_MODEL,    "CIA 1 model" },
/* da */ { IDS_CIA1_MODEL_DA, "CIA 1 model" },
/* de */ { IDS_CIA1_MODEL_DE, "CIA 1 Modell" },
/* es */ { IDS_CIA1_MODEL_ES, "Modelo CIA 1" },
/* fr */ { IDS_CIA1_MODEL_FR, "" },  /* fuzzy */
/* hu */ { IDS_CIA1_MODEL_HU, "" },  /* fuzzy */
/* it */ { IDS_CIA1_MODEL_IT, "Modello CIA 1" },
/* ko */ { IDS_CIA1_MODEL_KO, "CIA 1 ��" },
/* nl */ { IDS_CIA1_MODEL_NL, "CIA 1 model" },
/* pl */ { IDS_CIA1_MODEL_PL, "Model CIA 1" },
/* ru */ { IDS_CIA1_MODEL_RU, "������ CIA 1" },
/* sv */ { IDS_CIA1_MODEL_SV, "CIA 1-modell" },
/* tr */ { IDS_CIA1_MODEL_TR, "CIA 1 modeli" },

/* en */ { IDS_CIA2_MODEL,    "CIA 2 model" },
/* da */ { IDS_CIA2_MODEL_DA, "CIA 2 model" },
/* de */ { IDS_CIA2_MODEL_DE, "CIA 2 Modell" },
/* es */ { IDS_CIA2_MODEL_ES, "Modelo CIA 2" },
/* fr */ { IDS_CIA2_MODEL_FR, "" },  /* fuzzy */
/* hu */ { IDS_CIA2_MODEL_HU, "" },  /* fuzzy */
/* it */ { IDS_CIA2_MODEL_IT, "Modello CIA 2" },
/* ko */ { IDS_CIA2_MODEL_KO, "CIA 2 ��" },
/* nl */ { IDS_CIA2_MODEL_NL, "CIA 2 model" },
/* pl */ { IDS_CIA2_MODEL_PL, "Model CIA 2" },
/* ru */ { IDS_CIA2_MODEL_RU, "������ CIA 2" },
/* sv */ { IDS_CIA2_MODEL_SV, "CIA 2-modell" },
/* tr */ { IDS_CIA2_MODEL_TR, "CIA 2 modeli" },

/* en */ { IDS_GLUE_LOGIC,    "Glue logic" },
/* da */ { IDS_GLUE_LOGIC_DA, "Glue logic" },
/* de */ { IDS_GLUE_LOGIC_DE, "Glue Logik" },
/* es */ { IDS_GLUE_LOGIC_ES, "Glue logic" },
/* fr */ { IDS_GLUE_LOGIC_FR, "Glue logic" },
/* hu */ { IDS_GLUE_LOGIC_HU, "" },  /* fuzzy */
/* it */ { IDS_GLUE_LOGIC_IT, "Glue logic" },
/* ko */ { IDS_GLUE_LOGIC_KO, "�۷� ����" },
/* nl */ { IDS_GLUE_LOGIC_NL, "Glue logic" },
/* pl */ { IDS_GLUE_LOGIC_PL, "Glue logic" },
/* ru */ { IDS_GLUE_LOGIC_RU, "" },  /* fuzzy */
/* sv */ { IDS_GLUE_LOGIC_SV, "Klisterlogik" },
/* tr */ { IDS_GLUE_LOGIC_TR, "Glue logic" },

/* en */ { IDS_C64_MODEL_SETTINGS,    "C64 model settings" },
/* da */ { IDS_C64_MODEL_SETTINGS_DA, "C64-model indstillinger" },
/* de */ { IDS_C64_MODEL_SETTINGS_DE, "C64 Modell Einstellungen" },
/* es */ { IDS_C64_MODEL_SETTINGS_ES, "Ajustes modelo C64" },
/* fr */ { IDS_C64_MODEL_SETTINGS_FR, "" },  /* fuzzy */
/* hu */ { IDS_C64_MODEL_SETTINGS_HU, "" },  /* fuzzy */
/* it */ { IDS_C64_MODEL_SETTINGS_IT, "Impostazioni modello C64" },
/* ko */ { IDS_C64_MODEL_SETTINGS_KO, "" },  /* fuzzy */
/* nl */ { IDS_C64_MODEL_SETTINGS_NL, "C64 model instellingen" },
/* pl */ { IDS_C64_MODEL_SETTINGS_PL, "Ustawienia modelu C64" },
/* ru */ { IDS_C64_MODEL_SETTINGS_RU, "" },  /* fuzzy */
/* sv */ { IDS_C64_MODEL_SETTINGS_SV, "C64-modellinst�llningar" },
/* tr */ { IDS_C64_MODEL_SETTINGS_TR, "C64 model ayarlar�" },

};
