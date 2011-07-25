﻿/*
 * translate_text.c - Translation texts to be included in translate.c
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

translate_t string_table[] = {

/* autostart.c */
/* en */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE,    N_("Cannot load snapshot file.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_DA, "Kunne ikke indlæse snapshot-fil."},
/* de */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_DE, "Kann Snapshot Datei nicht laden."},
/* fr */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_FR, "Impossible de charger l'instantané."},
/* hu */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_HU, "Nem sikerült betölteni a pillanatkép fájlt."},
/* it */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_IT, "Non è possibile caricare il file di snapshot."},
/* ko */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_NL, "Kan momentopnamebestand niet laden."},
/* ru */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_SV, "Kan inte läsa in ögonblicksbildfil."},
/* tr */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_TR, "Anlýk görüntü dosyasý yüklenemedi."},
#endif

/* debug.c */
/* en */ {IDGS_PLAYBACK_ERROR_DIFFERENT,    N_("Playback error: %s different from line %d of file debug%06d")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_PLAYBACK_ERROR_DIFFERENT_DA, "Afspilningsfejl: %s forskellig fra linje %d i filen debug%06d"},
/* de */ {IDGS_PLAYBACK_ERROR_DIFFERENT_DE, "Wiedergabe Fehler: %s ist unterschiedlich von Zeile %d in Datei debug%06d"},
/* fr */ {IDGS_PLAYBACK_ERROR_DIFFERENT_FR, "Erreur de lecture: %s différent de la ligne %d du fichier debug%06d"},
/* hu */ {IDGS_PLAYBACK_ERROR_DIFFERENT_HU, "Visszajátszási hiba: %s különbözik a %d. sorban a debug%06d fájl esetén"},
/* it */ {IDGS_PLAYBACK_ERROR_DIFFERENT_IT, "Errore di riproduzione: %s è differente dalla linea %d del file di debug %06d"},
/* ko */ {IDGS_PLAYBACK_ERROR_DIFFERENT_KO, ""},  /* fuzzy */
/* nl */ {IDGS_PLAYBACK_ERROR_DIFFERENT_NL, "Afspeelfout: %s is anders dan regel %d van bestand debug%06d"},
/* ru */ {IDGS_PLAYBACK_ERROR_DIFFERENT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_PLAYBACK_ERROR_DIFFERENT_SV, "Återspelningsfel: %s inte lika som rad %d i filen debug%06d"},
/* tr */ {IDGS_PLAYBACK_ERROR_DIFFERENT_TR, "Kayýttan yürütme hatasý: %s dosyanýn %d satýrýndan farklý (hata ayýklama%06d)"},
#endif

/* event.c */
/* en */ {IDGS_CANNOT_CREATE_IMAGE,    N_("Cannot create image file!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_CREATE_IMAGE_DA, "Kunne ikke oprette image-fil!"},
/* de */ {IDGS_CANNOT_CREATE_IMAGE_DE, "Kann Imagedatei nicht erzeugen!"},
/* fr */ {IDGS_CANNOT_CREATE_IMAGE_FR, "Impossible de créer le fichier image!"},
/* hu */ {IDGS_CANNOT_CREATE_IMAGE_HU, "Nem sikerült a képmás fájlt létrehozni!"},
/* it */ {IDGS_CANNOT_CREATE_IMAGE_IT, "Non è possibile creare il file immagine!"},
/* ko */ {IDGS_CANNOT_CREATE_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_CREATE_IMAGE_NL, "Kan bestand niet maken!"},
/* ru */ {IDGS_CANNOT_CREATE_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_CREATE_IMAGE_SV, "Kan inte skapa avbildningsfil!"},
/* tr */ {IDGS_CANNOT_CREATE_IMAGE_TR, "Imaj dosyasý yaratýlamadý!"},
#endif

/* event.c */
/* en */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S,    N_("Cannot write image file %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_DA, "Kunne ikks skrive image-fil %s"},
/* de */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_DE, "Kann Datei %s nicht schreiben"},
/* fr */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_FR, "Impossible d'écrire le fichier image %s"},
/* hu */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_HU, "Nem sikerült a %s képmás fájlba írni"},
/* it */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_IT, "Non è possibile scrivere l'immagine %s"},
/* ko */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_NL, "Kan niet schrijven naar bestand %s"},
/* ru */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_SV, "Kan inte skriva avbildningsfil %s"},
/* tr */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_TR, "%s imaj dosyasýna yazýlamadý"},
#endif

/* event.c */
/* en */ {IDGS_CANNOT_FIND_MAPPED_NAME_S,    N_("Cannot find mapped name for %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_DA, "Kunne ikke finde mappet navn for %s"},
/* de */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_DE, "Kann zugeordneten Namen für `%s' nicht finden."},
/* fr */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_FR, "Impossible de trouver le nom correspondant à %s"},
/* hu */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_HU, "A VICE %s leképzett nevét nem találja"},
/* it */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_IT, "Non è possibile trovare il nome mappato per %s"},
/* ko */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_NL, "Kan vertaalde naam voor %s niet vinden"},
/* ru */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_SV, "Kan inte kopplat namn för %s"},
/* tr */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_TR, "%s için eþleþme ismi bulunamadý"},
#endif

/* event.c */
/* en */ {IDGS_CANT_CREATE_START_SNAP_S,    N_("Could not create start snapshot file %s.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANT_CREATE_START_SNAP_S_DA, "Kunne ikke oprette start-snapshot-filen %s."},
/* de */ {IDGS_CANT_CREATE_START_SNAP_S_DE, "Kann Start Snapshot Datei nicht erzeugen: %s"},
/* fr */ {IDGS_CANT_CREATE_START_SNAP_S_FR, "Impossible de créer l'instantané de départ %s."},
/* hu */ {IDGS_CANT_CREATE_START_SNAP_S_HU, "Nem sikerült a %s kezdeti pillanatkép fájlt létrehozni."},
/* it */ {IDGS_CANT_CREATE_START_SNAP_S_IT, "Non è possibile creare il file di inizio snapshot %s."},
/* ko */ {IDGS_CANT_CREATE_START_SNAP_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANT_CREATE_START_SNAP_S_NL, "Kon het start momentopnamebestand %s niet maken."},
/* ru */ {IDGS_CANT_CREATE_START_SNAP_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANT_CREATE_START_SNAP_S_SV, "Kunde inte skapa startögonblicksbildfilen %s."},
/* tr */ {IDGS_CANT_CREATE_START_SNAP_S_TR, "Anlýk görüntü dosyasý %s yaratýlamadý."},
#endif

/* event.c */
/* en */ {IDGS_ERROR_READING_END_SNAP_S,    N_("Error reading end snapshot file %s.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ERROR_READING_END_SNAP_S_DA, "Fejl under læsning af slut-snapshot %s."},
/* de */ {IDGS_ERROR_READING_END_SNAP_S_DE, "Kann Ende Snapshot Datei nicht lesen: %s"},
/* fr */ {IDGS_ERROR_READING_END_SNAP_S_FR, "Erreur de lecture de l'instantané de fin %s."},
/* hu */ {IDGS_ERROR_READING_END_SNAP_S_HU, "Hiba az utolsó %s pillanatkép fájl írásakor."},
/* it */ {IDGS_ERROR_READING_END_SNAP_S_IT, "Errore durante la lettura del file di fine snapshot %s."},
/* ko */ {IDGS_ERROR_READING_END_SNAP_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ERROR_READING_END_SNAP_S_NL, "Fout bij het lezen van het eind van het momentopnamebestand %s."},
/* ru */ {IDGS_ERROR_READING_END_SNAP_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ERROR_READING_END_SNAP_S_SV, "Fel vid läsning av slutögonblicksbildfilen %s."},
/* tr */ {IDGS_ERROR_READING_END_SNAP_S_TR, "Anlýk görüntü dosyasý %s okuma hatasý."},
#endif

/* event.c */
/* en */ {IDGS_CANT_CREATE_END_SNAP_S,    N_("Could not create end snapshot file %s.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANT_CREATE_END_SNAP_S_DA, "Kunne ikke oprette slut-snapshot-filen %s."},
/* de */ {IDGS_CANT_CREATE_END_SNAP_S_DE, "Kann Ende Snapshot Datei nicht erzeugen: %s"},
/* fr */ {IDGS_CANT_CREATE_END_SNAP_S_FR, "Impossible de créer l'instantané de fin %s."},
/* hu */ {IDGS_CANT_CREATE_END_SNAP_S_HU, "Nem sikerült a %s befejezõ pillanatkép fájlt létrehozni."},
/* it */ {IDGS_CANT_CREATE_END_SNAP_S_IT, "Non è possibile creare il file di fine snapshot %s."},
/* ko */ {IDGS_CANT_CREATE_END_SNAP_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANT_CREATE_END_SNAP_S_NL, "Kon het eind momentopnamebestand %s niet maken."},
/* ru */ {IDGS_CANT_CREATE_END_SNAP_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANT_CREATE_END_SNAP_S_SV, "Kunde inte skapa slutögonblicksbildfilen %s."},
/* tr */ {IDGS_CANT_CREATE_END_SNAP_S_TR, "Son anlýk görüntü dosyasý %s yaratýlamadý."},
#endif

/* event.c */
/* en */ {IDGS_CANT_OPEN_END_SNAP_S,    N_("Could not open end snapshot file %s.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANT_OPEN_END_SNAP_S_DA, "Kunne ikke åbne slut-snapshot-filen %s."},
/* de */ {IDGS_CANT_OPEN_END_SNAP_S_DE, "Kann Ende Snapshot Datei nicht öffnen: %s"},
/* fr */ {IDGS_CANT_OPEN_END_SNAP_S_FR, "Impossible d'ouvrir l'instantané de fin %s."},
/* hu */ {IDGS_CANT_OPEN_END_SNAP_S_HU, "Nem sikerült az utolsó %s pillanatkép fájlt megnyitni."},
/* it */ {IDGS_CANT_OPEN_END_SNAP_S_IT, "Non è possibile aprire il file di fine snapshot %s."},
/* ko */ {IDGS_CANT_OPEN_END_SNAP_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANT_OPEN_END_SNAP_S_NL, "Kon het eind momentopnamebestand %s niet openen."},
/* ru */ {IDGS_CANT_OPEN_END_SNAP_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANT_OPEN_END_SNAP_S_SV, "Kunde inte öppna slutögonblicksbildfilen %s."},
/* tr */ {IDGS_CANT_OPEN_END_SNAP_S_TR, "Son anlýk görüntü dosyasý %s açýlamadý."},
#endif

/* event.c */
/* en */ {IDGS_CANT_FIND_SECTION_END_SNAP,    N_("Could not find event section in end snapshot file.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANT_FIND_SECTION_END_SNAP_DA, "Kunne ikke finde hændelses-sektionen i slut-snapshot-filen."},
/* de */ {IDGS_CANT_FIND_SECTION_END_SNAP_DE, "Kann Sektion in Ende Snapshotdatei nicht finden."},
/* fr */ {IDGS_CANT_FIND_SECTION_END_SNAP_FR, "Impossible de trouver la section event dans l'instantané de fin."},
/* hu */ {IDGS_CANT_FIND_SECTION_END_SNAP_HU, "Nem találtam esemény részt az utolsó pillanatkép fájlban."},
/* it */ {IDGS_CANT_FIND_SECTION_END_SNAP_IT, "Non è possibile trovare la sezione eventi nel file di fine snapshot."},
/* ko */ {IDGS_CANT_FIND_SECTION_END_SNAP_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANT_FIND_SECTION_END_SNAP_NL, "Kon de gebeurtenis sectie in eind momentopnamebestand niet vinden."},
/* ru */ {IDGS_CANT_FIND_SECTION_END_SNAP_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANT_FIND_SECTION_END_SNAP_SV, "Kunde inte hinna händelsedelen i slutögonblicksbilden."},
/* tr */ {IDGS_CANT_FIND_SECTION_END_SNAP_TR, "Son anlýk görüntü dosyasýnda olay bölümü bulunamadý."},
#endif

/* event.c */
/* en */ {IDGS_ERROR_READING_START_SNAP_TRIED,    N_("Error reading start snapshot file. Tried %s and %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ERROR_READING_START_SNAP_TRIED_DA, "Fejl under læsning af start-snapshot. Prøvede %s og %s"},
/* de */ {IDGS_ERROR_READING_START_SNAP_TRIED_DE, "Fehler beim Lesen der Start Snapshot Datei. Versuch gescheitert bei %s und %s."},
/* fr */ {IDGS_ERROR_READING_START_SNAP_TRIED_FR, "Erreur de lecture de l'instantané de départ. Essayé %s et %s"},
/* hu */ {IDGS_ERROR_READING_START_SNAP_TRIED_HU, "Nem sikerült az elsõ pillanatkép fájl olvasása. Kipróbálva: %s és %s"},
/* it */ {IDGS_ERROR_READING_START_SNAP_TRIED_IT, "Errore durante la lettura del file di inizio snapshot. Ho provato %s e %s"},
/* ko */ {IDGS_ERROR_READING_START_SNAP_TRIED_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ERROR_READING_START_SNAP_TRIED_NL, "Fout bij het lezen van het start momentopnamebestand. Heb %s en %s geprobeerd"},
/* ru */ {IDGS_ERROR_READING_START_SNAP_TRIED_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ERROR_READING_START_SNAP_TRIED_SV, "Fel vid läsning av startögonblicksbildfil. Försökte med %s och %s"},
/* tr */ {IDGS_ERROR_READING_START_SNAP_TRIED_TR, "Baþlangýç anlýk görüntü dosyasý okuma hatasý. %s ve %s denendi"},
#endif

/* event.c */
/* en */ {IDGS_ERROR_READING_START_SNAP,    N_("Error reading start snapshot file.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ERROR_READING_START_SNAP_DA, "Fejl under læsning af start-snapshot."},
/* de */ {IDGS_ERROR_READING_START_SNAP_DE, "Fehler beim Lesen der Start Snapshot Datei."},
/* fr */ {IDGS_ERROR_READING_START_SNAP_FR, "Erreur de lecture de l'instantané de départ."},
/* hu */ {IDGS_ERROR_READING_START_SNAP_HU, "Nem sikerült az indító pillanatkép fájl olvasása."},
/* it */ {IDGS_ERROR_READING_START_SNAP_IT, "Errore durante la lettura del file di inizio snapshot."},
/* ko */ {IDGS_ERROR_READING_START_SNAP_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ERROR_READING_START_SNAP_NL, "Fout bij het lezen van het start momentopnamebestand."},
/* ru */ {IDGS_ERROR_READING_START_SNAP_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ERROR_READING_START_SNAP_SV, "Fel vid läsning av startögonblicksbildfil."},
/* tr */ {IDGS_ERROR_READING_START_SNAP_TR, "Baþlangýç anlýk görüntü dosyasý okuma hatasý."},
#endif

/* screenshot.c */
/* en */ {IDGS_SORRY_NO_MULTI_RECORDING,    N_("Sorry. Multiple recording is not supported.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_SORRY_NO_MULTI_RECORDING_DA, "Kun en optagelse kan foretages ad gangen."},
/* de */ {IDGS_SORRY_NO_MULTI_RECORDING_DE, "Eine Aufnahme ist zur Zeit aktiv. Mehrfache Aufnahme ist nicht möglich."},
/* fr */ {IDGS_SORRY_NO_MULTI_RECORDING_FR, "Désolé. De multiples enregistrements ne sont pas supporté."},
/* hu */ {IDGS_SORRY_NO_MULTI_RECORDING_HU, "Sajnálom: többszörös felvétel nem támogatott."},
/* it */ {IDGS_SORRY_NO_MULTI_RECORDING_IT, "Le registrazioni multiple non sono supportate."},
/* ko */ {IDGS_SORRY_NO_MULTI_RECORDING_KO, ""},  /* fuzzy */
/* nl */ {IDGS_SORRY_NO_MULTI_RECORDING_NL, "Sorry. Meerdere opnamen wordt niet ondersteund."},
/* ru */ {IDGS_SORRY_NO_MULTI_RECORDING_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SORRY_NO_MULTI_RECORDING_SV, "Endast en inspelning kan göras åt gången."},
/* tr */ {IDGS_SORRY_NO_MULTI_RECORDING_TR, "Üzgünüz. Çoklu kayýt desteklenmiyor."},
#endif

/* sound.c */
/* en */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED,    N_("write to sound device failed.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_DA, "Kunne ikke skrive til lydenhed."},
/* de */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_DE, "Schreiben auf Sound Gerät ist fehlgeschlagen."},
/* fr */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_FR, "impossible d'écrire sur le périphérique son."},
/* hu */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_HU, "Nem sikerült a hangeszközre írni"},
/* it */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_IT, "scrittura sulla scheda audio fallita."},
/* ko */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_KO, ""},  /* fuzzy */
/* nl */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_NL, "schrijfactie naar geluidsapparaat is mislukt."},
/* ru */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_RU, ""},  /* fuzzy */
/* sv */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_SV, "misslyckades att skriva till ljudenhet."},
/* tr */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_TR, "ses aygýtýna yazma baþarýsýz oldu."},
#endif

/* sound.c */
/* en */ {IDGS_CANNOT_OPEN_SID_ENGINE,    N_("Cannot open SID engine")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_OPEN_SID_ENGINE_DA, "Kunne ikke åbne SID-motor"},
/* de */ {IDGS_CANNOT_OPEN_SID_ENGINE_DE, "Kann SID Engine nicht öffnen"},
/* fr */ {IDGS_CANNOT_OPEN_SID_ENGINE_FR, "Erreur d'ouverture de l'engin SID"},
/* hu */ {IDGS_CANNOT_OPEN_SID_ENGINE_HU, "Nem sikerült a SID motort megnyitni"},
/* it */ {IDGS_CANNOT_OPEN_SID_ENGINE_IT, "Non è possibile aprire il motore SID"},
/* ko */ {IDGS_CANNOT_OPEN_SID_ENGINE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_OPEN_SID_ENGINE_NL, "Kan de SID kern niet openen"},
/* ru */ {IDGS_CANNOT_OPEN_SID_ENGINE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_OPEN_SID_ENGINE_SV, "Kan inte öppna SID-motor"},
/* tr */ {IDGS_CANNOT_OPEN_SID_ENGINE_TR, "SID motoru açýlamýyor"},
#endif

/* sound.c */
/* en */ {IDGS_CANNOT_INIT_SID_ENGINE,    N_("Cannot initialize SID engine")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_INIT_SID_ENGINE_DA, "Kunne ikke initialisere SID-motor"},
/* de */ {IDGS_CANNOT_INIT_SID_ENGINE_DE, "Kann SID Engine nicht initialisieren"},
/* fr */ {IDGS_CANNOT_INIT_SID_ENGINE_FR, "Erreur d'initialisation de l'engin SID"},
/* hu */ {IDGS_CANNOT_INIT_SID_ENGINE_HU, "Nem sikerült a SID motort elindítani"},
/* it */ {IDGS_CANNOT_INIT_SID_ENGINE_IT, "Non è possibile inizializzare il motore SID"},
/* ko */ {IDGS_CANNOT_INIT_SID_ENGINE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_INIT_SID_ENGINE_NL, "Kan de SID kern niet initialiseren"},
/* ru */ {IDGS_CANNOT_INIT_SID_ENGINE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_INIT_SID_ENGINE_SV, "Kan inte initiera SID-motor"},
/* tr */ {IDGS_CANNOT_INIT_SID_ENGINE_TR, "SID motorunun baþlangýç ayarlarý yapýlamýyor"},
#endif

/* sound.c */
/* en */ {IDGS_INIT_FAILED_FOR_DEVICE_S,    N_("initialization failed for device `%s'.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_INIT_FAILED_FOR_DEVICE_S_DA, "Initialisering fejlede for enhed \"%s\"."},
/* de */ {IDGS_INIT_FAILED_FOR_DEVICE_S_DE, "Initialisierung von Gerät `%s' fehlgeschlagen."},
/* fr */ {IDGS_INIT_FAILED_FOR_DEVICE_S_FR, "erreur d'initialisation du périphérique `%s'."},
/* hu */ {IDGS_INIT_FAILED_FOR_DEVICE_S_HU, "A `%s' eszközt nem sikerült elindítani."},
/* it */ {IDGS_INIT_FAILED_FOR_DEVICE_S_IT, "inizializzazione fallita per il device `%s'."},
/* ko */ {IDGS_INIT_FAILED_FOR_DEVICE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_INIT_FAILED_FOR_DEVICE_S_NL, "initialisatie voor apparaat `%s' is mislukt."},
/* ru */ {IDGS_INIT_FAILED_FOR_DEVICE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_INIT_FAILED_FOR_DEVICE_S_SV, "initiering misslyckades för enhet \"%s\"."},
/* tr */ {IDGS_INIT_FAILED_FOR_DEVICE_S_TR, "`%s' aygýtý için baþlangýç ayarlarý baþarýsýz oldu."},
#endif

/* sound.c */
/* en */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT,    N_("device '%s' not found or not supported.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_DA, "enhed \"%s\" ikke fundet eller understøttet."},
/* de */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_DE, "Gerät '%s' konnte nicht gefunden werden oder ist nicht unterstützt."},
/* fr */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_FR, "périphérique '%s' non trouvé ou non supporté."},
/* hu */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_HU, "A '%s' eszköz nem létezik, vagy nem támogatott."},
/* it */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_IT, "il device '%s' non è stato trovato oppure non è supportato."},
/* ko */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_KO, ""},  /* fuzzy */
/* nl */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_NL, "apparaat '%s' niet gevonden of wordt niet ondersteund"},
/* ru */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_SV, "enheten \"%s\" hittades eller stöds ej."},
/* tr */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_TR, "'%s' aygýtý yok ya da desteklenmiyor."},
#endif

/* sound.c */
/* en */ {IDGS_RECORD_DEVICE_S_NOT_EXIST,    N_("Recording device %s doesn't exist!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_DA, "Optageenheden %s findes ikke!"},
/* de */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_DE, "Aufnahmegerät %s existiert nicht!"},
/* fr */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_FR, "Le périphérique d'enregistrement %s n'existe pas!"},
/* hu */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_HU, "A %s felvevõ eszköz nem létezik!"},
/* it */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_IT, "Il device di registrazione %s non esiste!"},
/* ko */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_KO, ""},  /* fuzzy */
/* nl */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_NL, "Opnameapparaat %s bestaat niet!"},
/* ru */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_SV, "Inspelningsenhet %s finns inte!"},
/* tr */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_TR, "Kayýt aygýtý %s mevcut deðil!"},
#endif

/* sound.c */
/* en */ {IDGS_RECORD_DIFFERENT_PLAYBACK,    N_("Recording device must be different from playback device")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_RECORD_DIFFERENT_PLAYBACK_DA, "Indspilningsenhed og optagelsesenhed skal være forskellige"},
/* de */ {IDGS_RECORD_DIFFERENT_PLAYBACK_DE, "Aufnahmegerät muss unterschiedlich vom Abspielgerät sein"},
/* fr */ {IDGS_RECORD_DIFFERENT_PLAYBACK_FR, "Le périphérique de son d'enregistrement doivent être différents"},
/* hu */ {IDGS_RECORD_DIFFERENT_PLAYBACK_HU, "A felvevõ és lejátszó eszközöknek különböznie kell"},
/* it */ {IDGS_RECORD_DIFFERENT_PLAYBACK_IT, "Il device di registrazione deve essere differente da quello di riproduzione"},
/* ko */ {IDGS_RECORD_DIFFERENT_PLAYBACK_KO, ""},  /* fuzzy */
/* nl */ {IDGS_RECORD_DIFFERENT_PLAYBACK_NL, "Opnameapparaat moet anders zijn dan afspeelapparaat"},
/* ru */ {IDGS_RECORD_DIFFERENT_PLAYBACK_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RECORD_DIFFERENT_PLAYBACK_SV, "Inspelningsenhet och återspelningsenhet kan inte vara samma"},
/* tr */ {IDGS_RECORD_DIFFERENT_PLAYBACK_TR, "Kayýt aygýtý kayýttan yürütme aygýtý ile farklý olmak zorundadýr"},
#endif

/* sound.c */
/* en */ {IDGS_WARNING_RECORDING_REALTIME,    N_("Warning! Recording device %s seems to be a realtime device!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_WARNING_RECORDING_REALTIME_DA, "Advarsel! Optageenheden %s synes at være en realtidsenhed!"},
/* de */ {IDGS_WARNING_RECORDING_REALTIME_DE, "Warnung! Aufnahmegerät %s scheint ein Echtzeitgerät zu sein!"},
/* fr */ {IDGS_WARNING_RECORDING_REALTIME_FR, "Attention! Le périphérique d'enregistrement %s semble être un périphérique temps réel"},
/* hu */ {IDGS_WARNING_RECORDING_REALTIME_HU, "Figyelem! A %s felvevõ eszköz úgy tûnik, valós idejû eszköz!"},
/* it */ {IDGS_WARNING_RECORDING_REALTIME_IT, "Attenzione! Il device di registrazione %s sembra essere un dispositivo realtime!"},
/* ko */ {IDGS_WARNING_RECORDING_REALTIME_KO, ""},  /* fuzzy */
/* nl */ {IDGS_WARNING_RECORDING_REALTIME_NL, "Waarschuwing! Opnameapparaat %s lijkt een realtime apparaat te zijn!"},
/* ru */ {IDGS_WARNING_RECORDING_REALTIME_RU, ""},  /* fuzzy */
/* sv */ {IDGS_WARNING_RECORDING_REALTIME_SV, "Varning! Inspelningsenheten %s verkar vara en realtidsenhet!"},
/* tr */ {IDGS_WARNING_RECORDING_REALTIME_TR, "Uyarý! Kayýt aygýtý %s gerçek zamanlý bir aygýt gibi görünüyor!"},
#endif

/* sound.c */
/* en */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR,    N_("The recording device doesn't support current sound parameters")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_DA, "Optageenheden understøtter ikke de valgte lydparametre"},
/* de */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_DE, "Aufnahmegerät unterstützt derzeitige Soundeinstellungen nicht"},
/* fr */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_FR, "Le périphérique d'enregistrement ne supporte pas les paramètres actuels"},
/* hu */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_HU, "A felvevõ eszköz nem támogatja az aktuális hangbeállításokat"},
/* it */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_IT, "Il device di registrazione non supporta i parametri attuali"},
/* ko */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_KO, ""},  /* fuzzy */
/* nl */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_NL, "Het opname apparaat ondersteunt de huidige geluid opties niet"},
/* ru */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_SV, "Inspelningsenheten stöder inte aktuella ljudinställningar"},
/* tr */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_TR, "Kayýt aygýtý geçerli ses parametrelerini desteklemiyor"},
#endif

/* sound.c */
/* en */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE,    N_("Sound buffer overflow (cycle based)")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_DA, "Lydbuffer overløb (cykelbaseret)"},
/* de */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_DE, "Sound Puffer Überlauf (Zyklus basiert)"},
/* fr */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_FR, "Erreur de dépassement de tampon son (cycle based)"},
/* hu */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_HU, "Hangpuffer túlcsordulás (ciklus alapú)"},
/* it */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_IT, "Overflow del buffer audio (cycle based)"},
/* ko */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_NL, "Geluidsbuffer overloop (cyclus gebaseerd)"},
/* ru */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_SV, "För mycket data i ljudbufferten (cykelbaserad)"},
/* tr */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_TR, "Ses arabellek taþmasý (cycle bazlý)"},
#endif

/* sound.c */
/* en */ {IDGS_SOUND_BUFFER_OVERFLOW,    N_("Sound buffer overflow.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_SOUND_BUFFER_OVERFLOW_DA, "Lydbuffer overløb."},
/* de */ {IDGS_SOUND_BUFFER_OVERFLOW_DE, "Sound Puffer Überlauf."},
/* fr */ {IDGS_SOUND_BUFFER_OVERFLOW_FR, "Erreur de dépassement de tampon son."},
/* hu */ {IDGS_SOUND_BUFFER_OVERFLOW_HU, "Hangpuffer túlcsordulás."},
/* it */ {IDGS_SOUND_BUFFER_OVERFLOW_IT, "Overflow del buffer audio."},
/* ko */ {IDGS_SOUND_BUFFER_OVERFLOW_KO, ""},  /* fuzzy */
/* nl */ {IDGS_SOUND_BUFFER_OVERFLOW_NL, "Geluidsbuffer overloop."},
/* ru */ {IDGS_SOUND_BUFFER_OVERFLOW_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SOUND_BUFFER_OVERFLOW_SV, "För mycket data i ljudbufferten."},
/* tr */ {IDGS_SOUND_BUFFER_OVERFLOW_TR, "Ses arabellek taþmasý."},
#endif

/* sound.c */
/* en */ {IDGS_CANNOT_FLUSH,    N_("cannot flush.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_FLUSH_DA, "Kan ikke tømme."},
/* de */ {IDGS_CANNOT_FLUSH_DE, "Entleerung nicht möglich."},
/* fr */ {IDGS_CANNOT_FLUSH_FR, "impossible de vider."},
/* hu */ {IDGS_CANNOT_FLUSH_HU, "nem sikerült üríteni a puffert."},
/* it */ {IDGS_CANNOT_FLUSH_IT, "non è possibile svuotare."},
/* ko */ {IDGS_CANNOT_FLUSH_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_FLUSH_NL, "kan niet spoelen."},
/* ru */ {IDGS_CANNOT_FLUSH_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_FLUSH_SV, "kan inte tömma."},
/* tr */ {IDGS_CANNOT_FLUSH_TR, "temizlenemedi."},
#endif

/* sound.c */
/* en */ {IDGS_FRAGMENT_PROBLEMS,    N_("fragment problems.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_FRAGMENT_PROBLEMS_DA, "Fragmentproblem."},
/* de */ {IDGS_FRAGMENT_PROBLEMS_DE, "Fragmentierungsproblem."},
/* fr */ {IDGS_FRAGMENT_PROBLEMS_FR, "problèmes de fragments."},
/* hu */ {IDGS_FRAGMENT_PROBLEMS_HU, "töredékrész problémák."},
/* it */ {IDGS_FRAGMENT_PROBLEMS_IT, "problemi di frammentazione."},
/* ko */ {IDGS_FRAGMENT_PROBLEMS_KO, ""},  /* fuzzy */
/* nl */ {IDGS_FRAGMENT_PROBLEMS_NL, "fragment problemen."},
/* ru */ {IDGS_FRAGMENT_PROBLEMS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_FRAGMENT_PROBLEMS_SV, "fragmentprogram."},
/* tr */ {IDGS_FRAGMENT_PROBLEMS_TR, "parçalara ayýrma problemi."},
#endif

/* sound.c */
/* en */ {IDGS_RUNNING_TOO_SLOW,    N_("running too slow.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_RUNNING_TOO_SLOW_DA, "Kører for langsomt."},
/* de */ {IDGS_RUNNING_TOO_SLOW_DE, "Ablauf zu langsam."},
/* fr */ {IDGS_RUNNING_TOO_SLOW_FR, "exécution trop lente."},
/* hu */ {IDGS_RUNNING_TOO_SLOW_HU, "túl lassan megy."},
/* it */ {IDGS_RUNNING_TOO_SLOW_IT, "esecuzione troppo lenta."},
/* ko */ {IDGS_RUNNING_TOO_SLOW_KO, ""},  /* fuzzy */
/* nl */ {IDGS_RUNNING_TOO_SLOW_NL, "draait te langzaam."},
/* ru */ {IDGS_RUNNING_TOO_SLOW_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RUNNING_TOO_SLOW_SV, "går för långsamt."},
/* tr */ {IDGS_RUNNING_TOO_SLOW_TR, "çok yavaþ çalýþýyor."},
#endif

/* sound.c */
/* en */ {IDGS_STORE_SOUNDDEVICE_FAILED,    N_("store to sounddevice failed.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_STORE_SOUNDDEVICE_FAILED_DA, "skrivning til lydenhed fejlede."},
/* de */ {IDGS_STORE_SOUNDDEVICE_FAILED_DE, "Speichern auf Sound Gerät ist fehlgeschlagen."},
/* fr */ {IDGS_STORE_SOUNDDEVICE_FAILED_FR, "erreur d'enregistrement sur le périphérique son."},
/* hu */ {IDGS_STORE_SOUNDDEVICE_FAILED_HU, "a hangeszközön történõ tárolás nem sikerült."},
/* it */ {IDGS_STORE_SOUNDDEVICE_FAILED_IT, "memorizzazione sulla scheda audio fallita."},
/* ko */ {IDGS_STORE_SOUNDDEVICE_FAILED_KO, ""},  /* fuzzy */
/* nl */ {IDGS_STORE_SOUNDDEVICE_FAILED_NL, "opslag naar geluidsapparaat is mislukt."},
/* ru */ {IDGS_STORE_SOUNDDEVICE_FAILED_RU, ""},  /* fuzzy */
/* sv */ {IDGS_STORE_SOUNDDEVICE_FAILED_SV, "misslyckades spara i ljudenheten."},
/* tr */ {IDGS_STORE_SOUNDDEVICE_FAILED_TR, "ses aygýtýna saklama baþarýsýz oldu."},
#endif

/* c64/c64export.c */
/* en */ {IDGS_RESOURCE_S_BLOCKED_BY_S,    N_("Resource %s blocked by %s.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_RESOURCE_S_BLOCKED_BY_S_DA, "Resoursen %s er blokeret af %s."},
/* de */ {IDGS_RESOURCE_S_BLOCKED_BY_S_DE, "Resource %s wird von %s blockiert."},
/* fr */ {IDGS_RESOURCE_S_BLOCKED_BY_S_FR, "La ressource %s est bloquée par %s."},
/* hu */ {IDGS_RESOURCE_S_BLOCKED_BY_S_HU, "A %s erõforrást %s fogja."},
/* it */ {IDGS_RESOURCE_S_BLOCKED_BY_S_IT, "Risorsa %s bloccata da %s."},
/* ko */ {IDGS_RESOURCE_S_BLOCKED_BY_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_RESOURCE_S_BLOCKED_BY_S_NL, "Bron %s geblokeerd door %s."},
/* ru */ {IDGS_RESOURCE_S_BLOCKED_BY_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RESOURCE_S_BLOCKED_BY_S_SV, "Resursen %s blockeras av %s."},
/* tr */ {IDGS_RESOURCE_S_BLOCKED_BY_S_TR, "Kaynak %s, %s tarafýndan bloklandý."},
#endif

#ifdef HAVE_NETWORK
/* network.c */
/* en */ {IDGS_TESTING_BEST_FRAME_DELAY,    N_("Testing best frame delay...")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_TESTING_BEST_FRAME_DELAY_DA, "Tester bedste billed-forsinkelse..."},
/* de */ {IDGS_TESTING_BEST_FRAME_DELAY_DE, "Teste optimale Framerate..."},
/* fr */ {IDGS_TESTING_BEST_FRAME_DELAY_FR, ""},  /* fuzzy */
/* hu */ {IDGS_TESTING_BEST_FRAME_DELAY_HU, ""},  /* fuzzy */
/* it */ {IDGS_TESTING_BEST_FRAME_DELAY_IT, "Rileva il miglior ritardo tra frame..."},
/* ko */ {IDGS_TESTING_BEST_FRAME_DELAY_KO, ""},  /* fuzzy */
/* nl */ {IDGS_TESTING_BEST_FRAME_DELAY_NL, "Beste framevertraging aan het testen..."},
/* ru */ {IDGS_TESTING_BEST_FRAME_DELAY_RU, ""},  /* fuzzy */
/* sv */ {IDGS_TESTING_BEST_FRAME_DELAY_SV, "Testar bästa ramfördröjning..."},
/* tr */ {IDGS_TESTING_BEST_FRAME_DELAY_TR, "En iyi frame bekleme süresi test ediliyor..."},
#endif

/* network.c */
/* en */ {IDGS_USING_D_FRAMES_DELAY,    N_("Using %d frames delay.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_USING_D_FRAMES_DELAY_DA, "Bruger %d billeders forsinkelse."},
/* de */ {IDGS_USING_D_FRAMES_DELAY_DE, "Benutze %d Frameverzögerung."},
/* fr */ {IDGS_USING_D_FRAMES_DELAY_FR, "Utilisation d'un délai de %d images."},
/* hu */ {IDGS_USING_D_FRAMES_DELAY_HU, "%d képkocka késleltetés használata."},
/* it */ {IDGS_USING_D_FRAMES_DELAY_IT, "Utilizzo %d frame di ritardo."},
/* ko */ {IDGS_USING_D_FRAMES_DELAY_KO, ""},  /* fuzzy */
/* nl */ {IDGS_USING_D_FRAMES_DELAY_NL, "%d frames vertraging in gebruik."},
/* ru */ {IDGS_USING_D_FRAMES_DELAY_RU, ""},  /* fuzzy */
/* sv */ {IDGS_USING_D_FRAMES_DELAY_SV, "Använder %d ramars fördröjning."},
/* tr */ {IDGS_USING_D_FRAMES_DELAY_TR, "%d frame bekleme süresi kullanýlýyor."},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER,    N_("Cannot load snapshot file for transfer")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_DA, "Kunne ikke indlæse snapshot til overførsel."},
/* de */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_DE, "Kann Snapshot Datei für Transfer nicht laden"},
/* fr */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_FR, "Impossible de charger l'instantané pour le transfer"},
/* hu */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_HU, "Nem sikerült az átküldendõ pillanatkép fájlt betölteni"},
/* it */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_IT, "Non è possibile caricare il file di snapshot per il trasferimento"},
/* ko */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_NL, "Kan het momentopnamebestand voor versturen niet laden"},
/* ru */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_SV, "Kan inte läsa in ögonblicksbildfil för överföring."},
/* tr */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_TR, "Transfer için anlýk görüntü dosyasý yüklenemedi"},
#endif

/* network.c */
/* en */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT,    N_("Sending snapshot to client...")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_DA, "Sender snapshot til klient..."},
/* de */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_DE, "Sende Snapshot zu Client..."},
/* fr */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_FR, ""},  /* fuzzy */
/* hu */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_HU, ""},  /* fuzzy */
/* it */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_IT, "Invio snapshot al client in corso..."},
/* ko */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_KO, ""},  /* fuzzy */
/* nl */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_NL, "Momentopname wordt naar de andere computer verstuurd..."},
/* ru */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_SV, "Sänder ögonblicksbild till klient..."},
/* tr */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_TR, "Anlýk görüntü dosyasý istemciye gönderiliyor..."},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT,    N_("Cannot send snapshot to client")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_DA, "Kunne ikke sende snapshot til klient"},
/* de */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_DE, "Kann Snapshot Datei nicht senden"},
/* fr */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_FR, "Impossible d'envoyer l'instantané au client"},
/* hu */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_HU, "Nem sikerült pillanatképet elküldeni a klienshez"},
/* it */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_IT, "Non è possibile inviare lo snapshot al client"},
/* ko */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_NL, "Kan de momentopname niet naar de andere computer versturen"},
/* ru */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_SV, "Kan inte sända ögonblicksbild till klient"},
/* tr */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_TR, "Anlýk görüntü dosyasý istemciye gönderilemedi"},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S,    N_("Cannot create snapshot file %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_DA, "Kunne ikke oprette snapshot-fil %s"},
/* de */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_DE, "Kann Snapshot Datei `%s' nicht erzeugen"},
/* fr */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_FR, "Impossible de créer l'instantané %s"},
/* hu */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_HU, "Nem sikerült a pillanatképfájlt létrehozni (%s)"},
/* it */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_IT, "Non è possibile creare il file di snapshot %s"},
/* ko */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_NL, "Kan het momentopnamebestand %s niet maken"},
/* ru */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_SV, "Kan inte skapa ögonblicksbildfil %s"},
/* tr */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_TR, "Anlýk görüntü dosyasý %s yaratýlamadý"},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S,    N_("Cannot open snapshot file %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_DA, "Kunne ikke åbne snapshot-fil %s"},
/* de */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_DE, "Kann Snapshot Datei `%s' nicht öffnen."},
/* fr */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_FR, "Impossible d'ouvrir le fichier %s"},
/* hu */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_HU, "Nem sikerült a pillanatképfájlt megnyitni (%s)"},
/* it */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_IT, "Non è possibile aprire il file di snapshot %s"},
/* ko */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_NL, "Kan het momentopnamebestand %s niet openen"},
/* ru */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_SV, "Kan inte öppna ögonblicksbildfil %s"},
/* tr */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_TR, "Anlýk görüntü dosyasý %s açýlamadý"},
#endif

/* network.c */
/* en */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT,    N_("Server is waiting for a client...")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_DA, "Server venter på en klient..."},
/* de */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_DE, "Server wartet auf Client..."},
/* fr */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_FR, ""},  /* fuzzy */
/* hu */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_HU, ""},  /* fuzzy */
/* it */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_IT, "Il server è in attesa di un client..."},
/* ko */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_KO, ""},  /* fuzzy */
/* nl */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_NL, "De server wacht op de andere computer..."},
/* ru */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_SV, "Servern väntar på en klient..."},
/* tr */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_TR, "Sunucu bir istemcinin baðlanmasý için bekliyor..."},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT,    N_("Cannot create snapshot file. Select different history directory!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_DA, "Kunne ikke oprette snapshot-fil. Vælg et andet historik-katalog!"},
/* de */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_DE, "Kann Snapshot Datei nicht erzeugen. Verwende ein anderes Verzeichnis!"},
/* fr */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_FR, "Impossible de créer le fichier d'instantané. Sélectionnez un répertoire d'historique différent"},
/* hu */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_HU, "Nem sikerült pillanatkép fájlt létrehozni. Kérem válasszon más könyvtárat!"},
/* it */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_IT, "Non è possibile creare il file di snapshot. Seleziona una directory diversa per la cronologia."},
/* ko */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_NL, "Kan het momentopnamebestand niet maken. Selecteer een andere geschiedenisdirectory!"},
/* ru */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_SV, "Kan inte skapa ögonblicksbildfil. Välj en annan historikkatalog!"},
/* tr */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_TR, "Anlýk görüntü dosyasý yaratýlamadý. Farklý bir tarihçe dizini seçin!"},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_RESOLVE_S,    N_("Cannot resolve %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_RESOLVE_S_DA, "Kan ikke opslå %s"},
/* de */ {IDGS_CANNOT_RESOLVE_S_DE, "Kann %s nicht auflösen"},
/* fr */ {IDGS_CANNOT_RESOLVE_S_FR, "Impossible de résoudre %s"},
/* hu */ {IDGS_CANNOT_RESOLVE_S_HU, "Nem sikerült %s-t feloldani"},
/* it */ {IDGS_CANNOT_RESOLVE_S_IT, "Non è possibile risolvere %s"},
/* ko */ {IDGS_CANNOT_RESOLVE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_RESOLVE_S_NL, "Onbekende host %s"},
/* ru */ {IDGS_CANNOT_RESOLVE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_RESOLVE_S_SV, "Kan inte slå upp %s"},
/* tr */ {IDGS_CANNOT_RESOLVE_S_TR, "%s çözülemedi"},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_CONNECT_TO_S,    N_("Cannot connect to %s (no server running on port %d).")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_CONNECT_TO_S_DA, "Kan ikke forbinde til %s (ingen server på port %d)."},
/* de */ {IDGS_CANNOT_CONNECT_TO_S_DE, "Kann zu %s nicht verbinden (Kein Server aktiv auf Port %d)."},
/* fr */ {IDGS_CANNOT_CONNECT_TO_S_FR, "Impossible de se connecter à %s (aucun serveur sur le port %d)."},
/* hu */ {IDGS_CANNOT_CONNECT_TO_S_HU, "Nem sikerült %s-hez kapcsolódni (a %d porton nem fut kiszolgáló)"},
/* it */ {IDGS_CANNOT_CONNECT_TO_S_IT, "Non è possibile connettersi a %s (nessun server è attivo sulla porta %d)."},
/* ko */ {IDGS_CANNOT_CONNECT_TO_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_CONNECT_TO_S_NL, "Kan geen verbinding maken met %s (er is geen server aanwezig op poort %d)."},
/* ru */ {IDGS_CANNOT_CONNECT_TO_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_CONNECT_TO_S_SV, "Kan inte ansluta till %s (ingen server igång på port %d)."},
/* tr */ {IDGS_CANNOT_CONNECT_TO_S_TR, "%s baðlantýsý kurulamadý (port %d üzerinde çalýþan sunucu yok)."},
#endif

/* network.c */
/* en */ {IDGS_RECEIVING_SNAPSHOT_SERVER,    N_("Receiving snapshot from server...")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_RECEIVING_SNAPSHOT_SERVER_DA, "Modtager snapshot fra server..."},
/* de */ {IDGS_RECEIVING_SNAPSHOT_SERVER_DE, "Empfange Snapshot von Server..."},
/* fr */ {IDGS_RECEIVING_SNAPSHOT_SERVER_FR, ""},  /* fuzzy */
/* hu */ {IDGS_RECEIVING_SNAPSHOT_SERVER_HU, ""},  /* fuzzy */
/* it */ {IDGS_RECEIVING_SNAPSHOT_SERVER_IT, "Ricezione dello snapshot dal server in corso..."},
/* ko */ {IDGS_RECEIVING_SNAPSHOT_SERVER_KO, ""},  /* fuzzy */
/* nl */ {IDGS_RECEIVING_SNAPSHOT_SERVER_NL, "Momentopname van de server wordt ontvangen..."},
/* ru */ {IDGS_RECEIVING_SNAPSHOT_SERVER_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RECEIVING_SNAPSHOT_SERVER_SV, "Tar emot ögoblicksbild från server..."},
/* tr */ {IDGS_RECEIVING_SNAPSHOT_SERVER_TR, "Sunucudan anlýk görüntü alýnýyor..."},
#endif

/* network.c */
/* en */ {IDGS_NETWORK_OUT_OF_SYNC,    N_("Network out of sync - disconnecting.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_NETWORK_OUT_OF_SYNC_DA, "Netværk ude af synk - afbryder forbindelsen."},
/* de */ {IDGS_NETWORK_OUT_OF_SYNC_DE, "Netzwerksynchronisationsproblem - Trenne Verbindung."},
/* fr */ {IDGS_NETWORK_OUT_OF_SYNC_FR, "Le réseau n'est pas synchronisé (out of sync error). Déconnexion."},
/* hu */ {IDGS_NETWORK_OUT_OF_SYNC_HU, "A hálózat kiesett a szinkronból - szétkapcsolódás"},
/* it */ {IDGS_NETWORK_OUT_OF_SYNC_IT, "Rete non sincronizzata - disconnesione in corso."},
/* ko */ {IDGS_NETWORK_OUT_OF_SYNC_KO, ""},  /* fuzzy */
/* nl */ {IDGS_NETWORK_OUT_OF_SYNC_NL, "Netwerk niet synchroon - verbinding wordt verbroken."},
/* ru */ {IDGS_NETWORK_OUT_OF_SYNC_RU, ""},  /* fuzzy */
/* sv */ {IDGS_NETWORK_OUT_OF_SYNC_SV, "Nätverket ur synk - kopplar från."},
/* tr */ {IDGS_NETWORK_OUT_OF_SYNC_TR, "Að senkronizasyonu bozuldu - baðlantý kesiliyor."},
#endif

/* network.c */
/* en */ {IDGS_REMOTE_HOST_DISCONNECTED,    N_("Remote host disconnected.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_REMOTE_HOST_DISCONNECTED_DA, "Fjernmaskine afbrudt."},
/* de */ {IDGS_REMOTE_HOST_DISCONNECTED_DE, "Entfernter Rechner getrennt."},
/* fr */ {IDGS_REMOTE_HOST_DISCONNECTED_FR, "L'hôte distant s'est déconnecté."},
/* hu */ {IDGS_REMOTE_HOST_DISCONNECTED_HU, "A távoli számítogép lekapcsolódott."},
/* it */ {IDGS_REMOTE_HOST_DISCONNECTED_IT, "Host remoto disconnesso."},
/* ko */ {IDGS_REMOTE_HOST_DISCONNECTED_KO, ""},  /* fuzzy */
/* nl */ {IDGS_REMOTE_HOST_DISCONNECTED_NL, "Andere computer heeft de verbinding verbroken."},
/* ru */ {IDGS_REMOTE_HOST_DISCONNECTED_RU, ""},  /* fuzzy */
/* sv */ {IDGS_REMOTE_HOST_DISCONNECTED_SV, "Frånkopplad från fjärrvärd."},
/* tr */ {IDGS_REMOTE_HOST_DISCONNECTED_TR, "Uzak sunucu baðlantýsý kesildi."},
#endif

/* network.c */
/* en */ {IDGS_REMOTE_HOST_SUSPENDING,    N_("Remote host suspending...")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_REMOTE_HOST_SUSPENDING_DA, "Fjernmaskine pauser..."},
/* de */ {IDGS_REMOTE_HOST_SUSPENDING_DE, "Entfernter Rechner angehaltedn..."},
/* fr */ {IDGS_REMOTE_HOST_SUSPENDING_FR, ""},  /* fuzzy */
/* hu */ {IDGS_REMOTE_HOST_SUSPENDING_HU, ""},  /* fuzzy */
/* it */ {IDGS_REMOTE_HOST_SUSPENDING_IT, "Sospesione host remoto in corso..."},
/* ko */ {IDGS_REMOTE_HOST_SUSPENDING_KO, ""},  /* fuzzy */
/* nl */ {IDGS_REMOTE_HOST_SUSPENDING_NL, "Andere computer halt de netplay..."},
/* ru */ {IDGS_REMOTE_HOST_SUSPENDING_RU, ""},  /* fuzzy */
/* sv */ {IDGS_REMOTE_HOST_SUSPENDING_SV, "FJärrvärden pausar..."},
/* tr */ {IDGS_REMOTE_HOST_SUSPENDING_TR, "Uzak sunucu askýda..."},
#endif
#endif

/* gfxoutputdrv/ffmpegdrv.c */
/* en */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM,    N_("ffmpegdrv: Cannot open video stream")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_DA, "ffmpegdrv: Kan ikke åbne video-strøm"},
/* de */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_DE, "ffmpegdrv: Kann video stream nicht öffnen"},
/* fr */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_FR, "ffmpegdrv: Impossible d'ouvrir le flux vidéo"},
/* hu */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_HU, "ffmpegdrv: Nem sikerült megnyitni a videó adatfolyamot"},
/* it */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_IT, "ffmpegdrv: Non è possibile aprire il flusso video"},
/* ko */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_KO, ""},  /* fuzzy */
/* nl */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_NL, "ffmpegdrv: Kan de videostroom niet openen"},
/* ru */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_RU, ""},  /* fuzzy */
/* sv */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_SV, "ffmpegdrv: Kan inte öppna videoström"},
/* tr */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_TR, "ffmpegdrv: Görüntü akýþý açýlamadý"},
#endif

/* gfxoutputdrv/ffmpegdrv.c */
/* en */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM,    N_("ffmpegdrv: Cannot open audio stream")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_DA, "ffmpegdrv: Kan ikke åbne lyd-strøm"},
/* de */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_DE, "ffmpegdrv: Kann audio stream nicht öffnen"},
/* fr */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_FR, "ffmpegdrv: Impossible d'ouvrir le flux audio"},
/* hu */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_HU, "ffmpegdrv: Nem sikerült megnyitni a audió adatfolyamot"},
/* it */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_IT, "ffmpegdrv: Non è possibile aprire il flusso audio"},
/* ko */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_KO, ""},  /* fuzzy */
/* nl */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_NL, "ffmpegdrv: Kan de audiostroom niet openen"},
/* ru */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_RU, ""},  /* fuzzy */
/* sv */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_SV, "ffmpegdrv: Kan inte öppna ljudström"},
/* tr */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_TR, "ffmpegdrv: Ses akýþý açýlamadý"},
#endif

/* gfxoutputdrv/ffmpegdrv.c */
/* en */ {IDGS_FFMPEG_CANNOT_OPEN_S,    N_("ffmpegdrv: Cannot open %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_FFMPEG_CANNOT_OPEN_S_DA, "ffmpegdrv: Kan ikke åbne %s"},
/* de */ {IDGS_FFMPEG_CANNOT_OPEN_S_DE, "ffmpegdrv: Öffnen von %s fehlgeschlagen"},
/* fr */ {IDGS_FFMPEG_CANNOT_OPEN_S_FR, "ffmpegdrv: Impossible d'ouvrir %s"},
/* hu */ {IDGS_FFMPEG_CANNOT_OPEN_S_HU, "ffmpegdrv: Nem sikerült megnyitni: %s"},
/* it */ {IDGS_FFMPEG_CANNOT_OPEN_S_IT, "ffmpegdrv: Non è possibile aprire %s"},
/* ko */ {IDGS_FFMPEG_CANNOT_OPEN_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_FFMPEG_CANNOT_OPEN_S_NL, "ffmpegdrv: Kan %s niet openen"},
/* ru */ {IDGS_FFMPEG_CANNOT_OPEN_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_FFMPEG_CANNOT_OPEN_S_SV, "ffmpegdrv: Kan inte öppna %s"},
/* tr */ {IDGS_FFMPEG_CANNOT_OPEN_S_TR, "ffmpegdrv: %s açýlamadý"},
#endif

/* c64/c64io.c */
/* en */ {IDGS_IO_READ_COLL_AT_X_FROM,    N_("I/O read collision at %X from ")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_IO_READ_COLL_AT_X_FROM_DA, "I/O-læsekollision ved %X fra "},
/* de */ {IDGS_IO_READ_COLL_AT_X_FROM_DE, "I/O Lese Kollision bei %X von "},
/* fr */ {IDGS_IO_READ_COLL_AT_X_FROM_FR, ""},  /* fuzzy */
/* hu */ {IDGS_IO_READ_COLL_AT_X_FROM_HU, ""},  /* fuzzy */
/* it */ {IDGS_IO_READ_COLL_AT_X_FROM_IT, "Collisione di I/O in lettura a %X da "},
/* ko */ {IDGS_IO_READ_COLL_AT_X_FROM_KO, ""},  /* fuzzy */
/* nl */ {IDGS_IO_READ_COLL_AT_X_FROM_NL, "I/O lees botsing op %X van "},
/* ru */ {IDGS_IO_READ_COLL_AT_X_FROM_RU, ""},  /* fuzzy */
/* sv */ {IDGS_IO_READ_COLL_AT_X_FROM_SV, "I/O-läskollision vid %X från "},
/* tr */ {IDGS_IO_READ_COLL_AT_X_FROM_TR, "G/Ç okuma çakýþmasý %X'de "},
#endif

/* c64/c64io.c */
/* en */ {IDGS_AND,    N_(" and ")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_AND_DA, " og "},
/* de */ {IDGS_AND_DE, " und "},
/* fr */ {IDGS_AND_FR, ""},  /* fuzzy */
/* hu */ {IDGS_AND_HU, ""},  /* fuzzy */
/* it */ {IDGS_AND_IT, " e "},
/* ko */ {IDGS_AND_KO, " ±×¸®°í "},
/* nl */ {IDGS_AND_NL, " en "},
/* ru */ {IDGS_AND_RU, ""},  /* fuzzy */
/* sv */ {IDGS_AND_SV, " och "},
/* tr */ {IDGS_AND_TR, " ve "},
#endif

/* c64/c64io.c */
/* en */ {IDGS_ALL_DEVICES_DETACHED,    N_(".\nAll the named devices will be detached.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ALL_DEVICES_DETACHED_DA, ".\nAlle de navngivne enheder vil blive frakoblet."},
/* de */ {IDGS_ALL_DEVICES_DETACHED_DE, ".\nAlle genannten Geräte werden entfernt."},
/* fr */ {IDGS_ALL_DEVICES_DETACHED_FR, ".\nTous les périphériques nommés vont être détachés."},
/* hu */ {IDGS_ALL_DEVICES_DETACHED_HU, ".\nMinden megnevezett eszköz le lesz választva."},
/* it */ {IDGS_ALL_DEVICES_DETACHED_IT, ".\nTutti i device specificati sarranno rimossi."},
/* ko */ {IDGS_ALL_DEVICES_DETACHED_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ALL_DEVICES_DETACHED_NL, ".\nAlle genoemde apparaten zullen worden ontkoppelt."},
/* ru */ {IDGS_ALL_DEVICES_DETACHED_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ALL_DEVICES_DETACHED_SV, ".\nAlla namngivna enheter kommer kopplas från."},
/* tr */ {IDGS_ALL_DEVICES_DETACHED_TR, ".\nTüm isimlendirilmiþ aygýtlar çýkartýlacaktýr."},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDGS_NO_FILENAME,    N_("No filename!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_NO_FILENAME_DA, "Intet filnavn!"},
/* de */ {IDGS_NO_FILENAME_DE, "Dateiname fehlt!"},
/* fr */ {IDGS_NO_FILENAME_FR, ""},  /* fuzzy */
/* hu */ {IDGS_NO_FILENAME_HU, "Nincs fájlnév!"},
/* it */ {IDGS_NO_FILENAME_IT, "Nessun nome file!"},
/* ko */ {IDGS_NO_FILENAME_KO, ""},  /* fuzzy */
/* nl */ {IDGS_NO_FILENAME_NL, "Geen bestandsnaam!"},
/* ru */ {IDGS_NO_FILENAME_RU, ""},  /* fuzzy */
/* sv */ {IDGS_NO_FILENAME_SV, "Filnamn saknas!"},
/* tr */ {IDGS_NO_FILENAME_TR, "Dosya ismi yok!"},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDGS_ILLEGAL_FILENAME,    N_("Illegal filename!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ILLEGAL_FILENAME_DA, "Ugyldigt filnavn!"},
/* de */ {IDGS_ILLEGAL_FILENAME_DE, "Ungültiger Dateiname!"},
/* fr */ {IDGS_ILLEGAL_FILENAME_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ILLEGAL_FILENAME_HU, "Érvénytelen fájlnév!"},
/* it */ {IDGS_ILLEGAL_FILENAME_IT, "Nome file non valido!"},
/* ko */ {IDGS_ILLEGAL_FILENAME_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ILLEGAL_FILENAME_NL, "Bestandsnaam ongeldig!"},
/* ru */ {IDGS_ILLEGAL_FILENAME_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ILLEGAL_FILENAME_SV, "Ogiltigt filnamn!"},
/* tr */ {IDGS_ILLEGAL_FILENAME_TR, "Kural dýþý dosya ismi!"},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDGS_ERROR_CREATING_FILE_S,    N_("Error creating file %s!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ERROR_CREATING_FILE_S_DA, "Fejl under oprettelse af filen %s!"},
/* de */ {IDGS_ERROR_CREATING_FILE_S_DE, "Fehler beim Schreiben: %s."},
/* fr */ {IDGS_ERROR_CREATING_FILE_S_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ERROR_CREATING_FILE_S_HU, "Hiba %s fájl létrehozása közben!"},
/* it */ {IDGS_ERROR_CREATING_FILE_S_IT, "Errore durante la creazione del file %s!"},
/* ko */ {IDGS_ERROR_CREATING_FILE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ERROR_CREATING_FILE_S_NL, "Fout bij het maken van bestand %s!"},
/* ru */ {IDGS_ERROR_CREATING_FILE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ERROR_CREATING_FILE_S_SV, "Fel när filen \"%s\" skulle skapas!"},
/* tr */ {IDGS_ERROR_CREATING_FILE_S_TR, "%s dosyasý yaratýlýrken hata oluþtu!"},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDGS_ERROR_WRITING_TO_FILE_S,    N_("Error writing to file %s!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ERROR_WRITING_TO_FILE_S_DA, "Fejl ved skrivning til filen %s!"},
/* de */ {IDGS_ERROR_WRITING_TO_FILE_S_DE, "Fehler bei Schreibzugriff: %s!"},
/* fr */ {IDGS_ERROR_WRITING_TO_FILE_S_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ERROR_WRITING_TO_FILE_S_HU, "Hiba %s fájlba írás közben!"},
/* it */ {IDGS_ERROR_WRITING_TO_FILE_S_IT, "Errore durante la scrittura sul file %s!"},
/* ko */ {IDGS_ERROR_WRITING_TO_FILE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ERROR_WRITING_TO_FILE_S_NL, "Fout bij het schrijven naar bestand %s!"},
/* ru */ {IDGS_ERROR_WRITING_TO_FILE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ERROR_WRITING_TO_FILE_S_SV, "Fel vid skrivning till filen %s!"},
/* tr */ {IDGS_ERROR_WRITING_TO_FILE_S_TR, "%s dosyasýna yazýlýrken hata oluþtu!"},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDGS_DTV_ROM_CREATED,    N_("DTV ROM image created successfully")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_DTV_ROM_CREATED_DA, "DTV-ROM-image oprettet med success"},
/* de */ {IDGS_DTV_ROM_CREATED_DE, "DTV ROM Image erfolgreich erzeugt"},
/* fr */ {IDGS_DTV_ROM_CREATED_FR, ""},  /* fuzzy */
/* hu */ {IDGS_DTV_ROM_CREATED_HU, "DTV ROM képmás sikeresen létrehozva"},
/* it */ {IDGS_DTV_ROM_CREATED_IT, "Immagine ROM DTV creata con successo"},
/* ko */ {IDGS_DTV_ROM_CREATED_KO, ""},  /* fuzzy */
/* nl */ {IDGS_DTV_ROM_CREATED_NL, "DTV ROM bestand gemaakt!"},
/* ru */ {IDGS_DTV_ROM_CREATED_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DTV_ROM_CREATED_SV, "DTV-ROM-avbildning skapades framgångsrikt"},
/* tr */ {IDGS_DTV_ROM_CREATED_TR, "DTV ROM imajý baþarýyla oluþturuldu"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_TYPE,    N_("Type")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_TYPE_DA, "Type"},
/* de */ {IDGS_TYPE_DE, "Typ"},
/* fr */ {IDGS_TYPE_FR, "type"},
/* hu */ {IDGS_TYPE_HU, "Típus"},
/* it */ {IDGS_TYPE_IT, "Tipo"},
/* ko */ {IDGS_TYPE_KO, "Á¾·ù"},
/* nl */ {IDGS_TYPE_NL, "Soort"},
/* ru */ {IDGS_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_TYPE_SV, "Typ"},
/* tr */ {IDGS_TYPE_TR, "Tip"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_COMMAND_S_UNKNOWN,    N_("Command `%s' unknown.\n")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_COMMAND_S_UNKNOWN_DA, "Ukendt kommando \"%s\".\n"},
/* de */ {IDGS_COMMAND_S_UNKNOWN_DE, "Kommand `%s' ist unbekannt.\n"},
/* fr */ {IDGS_COMMAND_S_UNKNOWN_FR, ""},  /* fuzzy */
/* hu */ {IDGS_COMMAND_S_UNKNOWN_HU, "`%s' parancs ismeretlen.\n"},
/* it */ {IDGS_COMMAND_S_UNKNOWN_IT, "Comando `%s' sconosciuto.\n"},
/* ko */ {IDGS_COMMAND_S_UNKNOWN_KO, ""},  /* fuzzy */
/* nl */ {IDGS_COMMAND_S_UNKNOWN_NL, "Commando %s' is onbekent.\n"},
/* ru */ {IDGS_COMMAND_S_UNKNOWN_RU, ""},  /* fuzzy */
/* sv */ {IDGS_COMMAND_S_UNKNOWN_SV, "Kommandot \"%s\" är okänt.\n"},
/* tr */ {IDGS_COMMAND_S_UNKNOWN_TR, "`%s' komutu bilinmiyor.\n"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_NO_HELP_AVAILABLE_FOR_S,    N_("No help available for `%s'\n")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_NO_HELP_AVAILABLE_FOR_S_DA, "Ingen hjælp tilgængelig for \"%s\"\n"},
/* de */ {IDGS_NO_HELP_AVAILABLE_FOR_S_DE, "Es ist keine Hilfe für `%s' verfügbar\n"},
/* fr */ {IDGS_NO_HELP_AVAILABLE_FOR_S_FR, ""},  /* fuzzy */
/* hu */ {IDGS_NO_HELP_AVAILABLE_FOR_S_HU, "Nincs súgó a `%s' parancshoz\n"},
/* it */ {IDGS_NO_HELP_AVAILABLE_FOR_S_IT, "Nessun help disponibile per `%s'\n"},
/* ko */ {IDGS_NO_HELP_AVAILABLE_FOR_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_NO_HELP_AVAILABLE_FOR_S_NL, "Geen help beschikbaar voor `%s'\n"},
/* ru */ {IDGS_NO_HELP_AVAILABLE_FOR_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_NO_HELP_AVAILABLE_FOR_S_SV, "Hjälp saknas för \"%s\"\n"},
/* tr */ {IDGS_NO_HELP_AVAILABLE_FOR_S_TR, "`%s' için mevcut bir yardým metni yok\n"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_SYNTAX_S_S,    N_("\nSyntax: %s %s\n")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_SYNTAX_S_S_DA, "\nSyntax: %s %s\n"},
/* de */ {IDGS_SYNTAX_S_S_DE, "\nSyntax: %s %s\n"},
/* fr */ {IDGS_SYNTAX_S_S_FR, ""},  /* fuzzy */
/* hu */ {IDGS_SYNTAX_S_S_HU, "\nSzintaxis: %s %s\n"},
/* it */ {IDGS_SYNTAX_S_S_IT, "\nSintassi: %s %s\n"},
/* ko */ {IDGS_SYNTAX_S_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_SYNTAX_S_S_NL, "\nSyntax: %s %s\n"},
/* ru */ {IDGS_SYNTAX_S_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SYNTAX_S_S_SV, "\nSyntax: %s %s\n"},
/* tr */ {IDGS_SYNTAX_S_S_TR, "\nSözdizimi: %s %s\n"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_ABBREVIATION_S,    N_("Abbreviation: %s\n")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ABBREVIATION_S_DA, "Forkortelse: %s\n"},
/* de */ {IDGS_ABBREVIATION_S_DE, "Abkürzung: %s\n"},
/* fr */ {IDGS_ABBREVIATION_S_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ABBREVIATION_S_HU, "Rövidítés: %s\n"},
/* it */ {IDGS_ABBREVIATION_S_IT, "Abbreviazione: %s\n"},
/* ko */ {IDGS_ABBREVIATION_S_KO, "Ãà¾à: %s\n"},
/* nl */ {IDGS_ABBREVIATION_S_NL, "Afkorting: %s\n"},
/* ru */ {IDGS_ABBREVIATION_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ABBREVIATION_S_SV, "Förkortning: %s\n"},
/* tr */ {IDGS_ABBREVIATION_S_TR, "Kýsaltma: %s\n"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_AVAILABLE_COMMANDS_ARE,    N_("Available commands are:")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_AVAILABLE_COMMANDS_ARE_DA, "Tilgængelige kommandoer:"},
/* de */ {IDGS_AVAILABLE_COMMANDS_ARE_DE, "Zulässige Kommandos sind:"},
/* fr */ {IDGS_AVAILABLE_COMMANDS_ARE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_AVAILABLE_COMMANDS_ARE_HU, ""},  /* fuzzy */
/* it */ {IDGS_AVAILABLE_COMMANDS_ARE_IT, "I comandi disponibili sono:"},
/* ko */ {IDGS_AVAILABLE_COMMANDS_ARE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_AVAILABLE_COMMANDS_ARE_NL, "Beschikbare commandos zijn:"},
/* ru */ {IDGS_AVAILABLE_COMMANDS_ARE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_AVAILABLE_COMMANDS_ARE_SV, "Tillgängliga kommandon:"},
/* tr */ {IDGS_AVAILABLE_COMMANDS_ARE_TR, "Kullanýlabilir komutlar:"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MACHINE_STATE_COMMANDS,    N_("Machine state commands:")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MACHINE_STATE_COMMANDS_DA, "Kommandoer for maskinstatus:"},
/* de */ {IDGS_MACHINE_STATE_COMMANDS_DE, "Maschinen Zustandskommandos:"},
/* fr */ {IDGS_MACHINE_STATE_COMMANDS_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MACHINE_STATE_COMMANDS_HU, ""},  /* fuzzy */
/* it */ {IDGS_MACHINE_STATE_COMMANDS_IT, "Comandi di stato del computer:"},
/* ko */ {IDGS_MACHINE_STATE_COMMANDS_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MACHINE_STATE_COMMANDS_NL, "Machine status commandos:"},
/* ru */ {IDGS_MACHINE_STATE_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MACHINE_STATE_COMMANDS_SV, "Kommandon för maskinstatus:"},
/* tr */ {IDGS_MACHINE_STATE_COMMANDS_TR, "Makine durum komutlarý:"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MEMSPACE,    N_("memspace")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MEMSPACE_DA, "huk.område"},
/* de */ {IDGS_MEMSPACE_DE, "Speicherbereich"},
/* fr */ {IDGS_MEMSPACE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MEMSPACE_HU, ""},  /* fuzzy */
/* it */ {IDGS_MEMSPACE_IT, "spazio di memoria"},
/* ko */ {IDGS_MEMSPACE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MEMSPACE_NL, "geheugenruimte"},
/* ru */ {IDGS_MEMSPACE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MEMSPACE_SV, "minnesområde"},
/* tr */ {IDGS_MEMSPACE_TR, "bellekalaný"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_BANKNAME,    N_("bankname")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_BANKNAME_DA, "banknavn"},
/* de */ {IDGS_BANKNAME_DE, "Speicherbank"},
/* fr */ {IDGS_BANKNAME_FR, ""},  /* fuzzy */
/* hu */ {IDGS_BANKNAME_HU, ""},  /* fuzzy */
/* it */ {IDGS_BANKNAME_IT, "nome banco"},
/* ko */ {IDGS_BANKNAME_KO, ""},  /* fuzzy */
/* nl */ {IDGS_BANKNAME_NL, "bank naam"},
/* ru */ {IDGS_BANKNAME_RU, ""},  /* fuzzy */
/* sv */ {IDGS_BANKNAME_SV, "banknamn"},
/* tr */ {IDGS_BANKNAME_TR, "bankismi"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BANK_DESCRIPTION,    N_("If bankname is not given, print the possible banks for the memspace.\nIf bankname is given set the current bank in the memspace to the given\nbank.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BANK_DESCRIPTION_DA, "Hvis banknavn ikke angives vises mulige banker for hukommelsesområdet.\nHvis banknavn angives sættes aktuel bank i hukommelsesområdet til den\nangivne bank."},
/* de */ {IDGS_MON_BANK_DESCRIPTION_DE, "Falls `bankname' nicht angegeben wird, Ausgabe der möglichen Bänke in `memspace'.\nFalls `bankname' angegeben wird, setze aktuelle Bank in `memspace' mit angegebener Bank."},
/* fr */ {IDGS_MON_BANK_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BANK_DESCRIPTION_HU, "Ha a lap száma nincs megadva, kiírja a lehetséges lapokat a memória térbõl.\nHa meg van adva, az aktuális lap számot a memória térben a megadott lapra állítja."},
/* it */ {IDGS_MON_BANK_DESCRIPTION_IT, "Se non viene specificato il nome del banco, stampa tutti i banchi\npossibili per lo spazio di memoria.\nSe viene specificato il nome del banco, imposta il banco attuale nello\nspazio di memoria specificato."},
/* ko */ {IDGS_MON_BANK_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BANK_DESCRIPTION_NL, "Als de banknaam niet is opgegeven worden de mogelijke banken voor de\ngeheugenruimte weergegeven. Als de banknaam is opgegeven dan wordt de\nhuidige bank in de geheugenruimte gezet volgens de opgegeven banknaam."},
/* ru */ {IDGS_MON_BANK_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BANK_DESCRIPTION_SV, "Om banknamn inte anges, skriv ut möjliga bankar för minnesområdet.\nOm banknamn anges, sätt aktuell bank i minnesområdet till den givna\nbanken."},
/* tr */ {IDGS_MON_BANK_DESCRIPTION_TR, "Eðer bank ismi verilmemiþse, bellek alaný için uygun banklar yazdýrýlýr.\nEðer bank ismi verilmiþse, geçerli bank bellek alaný içinde verilen\nbanka eþitlenir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BACKTRACE_DESCRIPTION,    N_("Print JSR call chain (most recent call first). Stack offset\nrelative to SP+1 is printed in parentheses. This is a best guess\nonly.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BACKTRACE_DESCRIPTION_DA, "Vis JSR-kaldekæde (seneste kald øverst). Stakafstand\nrelativ til SP+1 vises i parantes. Dette er kun et\ngæt."},
/* de */ {IDGS_MON_BACKTRACE_DESCRIPTION_DE, "Zeige JSR Aufrufkette (letzter Aufruf zuerst). Stack offset\nwird relative zu SP+1 in Klammern gezeigt. Dies ist jedoch nur\neine Schätzung."},
/* fr */ {IDGS_MON_BACKTRACE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BACKTRACE_DESCRIPTION_HU, "JSR hívás lista kiírása (legutóbbi elõször). A verem SP+1\nhelyen lévõ tartalma zárójelben. Ez csak\negy legjobb becslés."},
/* it */ {IDGS_MON_BACKTRACE_DESCRIPTION_IT, "Stampa la catena di chiamate JSR (la chiamata più recente per prima).\nL'offset dello stack relativo a SP+1 è stampato tra parentesi. Questo è\nsolo l'ipotesi migliore."},
/* ko */ {IDGS_MON_BACKTRACE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BACKTRACE_DESCRIPTION_NL, "Toon JSR gebruik (meest recent gebruikt eerst). De stack\ncompensatie relatief ten opzichte van SP+1 zal worden getoont\nbinnen de aanhalingtekens. Dit is op basis van de beste gok."},
/* ru */ {IDGS_MON_BACKTRACE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BACKTRACE_DESCRIPTION_SV, "Skriv JSR-anropskedja (senaste anrop först). Stackavstånd\nrelativt till SP+1 visas inom parantes. Detta är bara en\ngissning."},
/* tr */ {IDGS_MON_BACKTRACE_DESCRIPTION_TR, "JSR çaðrý zincirini yazdýr (en son çaðrýlar öncelikli). Yýðýt ofseti\nSP+1'e baðlý olarak parantez içersinde yazdýrýlýr. Bu yalnýzca en iyi\ntahmindir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_CPU_DESCRIPTION,    N_("Specify the type of CPU currently used (6502/z80).")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_CPU_DESCRIPTION_DA, "Angiv typen af CPU der anvendes for øjeblikket (6502/z80)."},
/* de */ {IDGS_MON_CPU_DESCRIPTION_DE, "CPU Typ setzen (6502/z80)"},
/* fr */ {IDGS_MON_CPU_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_CPU_DESCRIPTION_HU, "A processzor típusának megadása (6502/z80)."},
/* it */ {IDGS_MON_CPU_DESCRIPTION_IT, "Specifica il tipo di CPU utilizzata al momento (6502/z80)."},
/* ko */ {IDGS_MON_CPU_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_CPU_DESCRIPTION_NL, "Geef de soort CPU die op dit moment in gebruik is (6502/z80)."},
/* ru */ {IDGS_MON_CPU_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_CPU_DESCRIPTION_SV, "Ange typ av CPU som används för närvarande (6502/z80)."},
/* tr */ {IDGS_MON_CPU_DESCRIPTION_TR, "Þu anda kullanýlmakta olan CPU tipini belirleyin (6502/z80)."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_COUNT,    N_("count")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_COUNT_DA, "antal"},
/* de */ {IDGS_COUNT_DE, "Zähler"},
/* fr */ {IDGS_COUNT_FR, ""},  /* fuzzy */
/* hu */ {IDGS_COUNT_HU, ""},  /* fuzzy */
/* it */ {IDGS_COUNT_IT, "contatore"},
/* ko */ {IDGS_COUNT_KO, ""},  /* fuzzy */
/* nl */ {IDGS_COUNT_NL, "hoeveelheid"},
/* ru */ {IDGS_COUNT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_COUNT_SV, "antal"},
/* tr */ {IDGS_COUNT_TR, "adet"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_CPUHISTORY_DESCRIPTION,    N_("Show <count> last executed commands.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_CPUHISTORY_DESCRIPTION_DA, "Vis <antal> senest eksekverede instruktioner."},
/* de */ {IDGS_MON_CPUHISTORY_DESCRIPTION_DE, "Zeige [<Zähler>] zuletzt ausgeführte Kommandos"},
/* fr */ {IDGS_MON_CPUHISTORY_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_CPUHISTORY_DESCRIPTION_HU, "<darab> utoljára végrehajtott utasítás mutatása."},
/* it */ {IDGS_MON_CPUHISTORY_DESCRIPTION_IT, "Mostra gli ultimi <contatore> comandi eseguiti."},
/* ko */ {IDGS_MON_CPUHISTORY_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_CPUHISTORY_DESCRIPTION_NL, "Toon <hoeveelheid> laatst uitgevoerde commandos."},
/* ru */ {IDGS_MON_CPUHISTORY_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_CPUHISTORY_DESCRIPTION_SV, "Visa <antal> senast exekverade kommandon."},
/* tr */ {IDGS_MON_CPUHISTORY_DESCRIPTION_TR, "<adet> son çalýþtýrýlan komutlarý göster."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_FILENAME,    N_("filename")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_FILENAME_DA, "filnavn"},
/* de */ {IDGS_FILENAME_DE, "Dateiname"},
/* fr */ {IDGS_FILENAME_FR, ""},  /* fuzzy */
/* hu */ {IDGS_FILENAME_HU, ""},  /* fuzzy */
/* it */ {IDGS_FILENAME_IT, "nome file"},
/* ko */ {IDGS_FILENAME_KO, ""},  /* fuzzy */
/* nl */ {IDGS_FILENAME_NL, "bestandsnaam"},
/* ru */ {IDGS_FILENAME_RU, ""},  /* fuzzy */
/* sv */ {IDGS_FILENAME_SV, "filnamn"},
/* tr */ {IDGS_FILENAME_TR, "dosyaismi"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DUMP_DESCRIPTION,    N_("Write a snapshot of the machine into the file specified.\nThis snapshot is compatible with a snapshot written out by the UI.\nNote: No ROM images are included into the dump.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DUMP_DESCRIPTION_DA, "Skriv et snapshot til den angivne fil.\nDette snapshot er kompatibelt med dem, der oprettes fra menuen.\nOBS: ROM-images inkluderes ikke i snapshot."},
/* de */ {IDGS_MON_DUMP_DESCRIPTION_DE, "Schreibe eine Snapsho Datei der Maschine auf die angebene Datei.\nDieser Snapshot ist kompatible zu einem Snapshot initiiert aus dem Menü.\nHinweis: Die ROM Images werden im Snapshot nicht inkludiert."},
/* fr */ {IDGS_MON_DUMP_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DUMP_DESCRIPTION_HU, "Pillanatkép írása a géprõl a megadott fájlba. A pillanatkép\nkompatibilis azzal, amelyet a grafikus felület hoz létre.\nMegjegyzés: a ROM képmások nem kerülnek bele."},
/* it */ {IDGS_MON_DUMP_DESCRIPTION_IT, "Scrive uno snapshot del computer sul file specificato.\nQuesto snapshot è compatibile con uno snapshot scritto dall'IU.\nNota: Le immagini ROM non sono incluse nel dump."},
/* ko */ {IDGS_MON_DUMP_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DUMP_DESCRIPTION_NL, "Schrijf een momentopname van de machine naar de opgegeven bestand.\nDeze momentopname is compatibel met een momentopname zoals geschreven van\nuit het menu.\nNB: ROM bestanden zijn niet opgenomen in de momentopname."},
/* ru */ {IDGS_MON_DUMP_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DUMP_DESCRIPTION_SV, "Skriv en ögonblicksbild av maskinen till den angivna filen.\nÖgonblicksbilden är kompatibel med de som skapas från menyn.\nObservera: ROM-avbildningar inkluderas inte i bilden."},
/* tr */ {IDGS_MON_DUMP_DESCRIPTION_TR, "Belirtilen dosya içersine makinenin anlýk görüntüsünü yaz.\nBu anlýk görüntü UI dýþýndan yazdýrýlan anlýk görüntü ile uyumludur.\nNot: Hiçbir ROM imajý döküm içersinde yer almaz."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_ADDRESS,    N_("address")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ADDRESS_DA, "adresse"},
/* de */ {IDGS_ADDRESS_DE, "Adresse"},
/* fr */ {IDGS_ADDRESS_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ADDRESS_HU, ""},  /* fuzzy */
/* it */ {IDGS_ADDRESS_IT, "indirizzo"},
/* ko */ {IDGS_ADDRESS_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ADDRESS_NL, "adres"},
/* ru */ {IDGS_ADDRESS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ADDRESS_SV, "adress"},
/* tr */ {IDGS_ADDRESS_TR, "adres"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_GOTO_DESCRIPTION,    N_("Change the PC to ADDRESS and continue execution")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_GOTO_DESCRIPTION_DA, "Ændr programtælleren (PC) til ADRESSE og fortsæt eksekvering"},
/* de */ {IDGS_MON_GOTO_DESCRIPTION_DE, "Setze PC auf ADRESSE und setze Ausführung fort"},
/* fr */ {IDGS_MON_GOTO_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_GOTO_DESCRIPTION_HU, "A PC állítása ADDRESS címre és folytatás"},
/* it */ {IDGS_MON_GOTO_DESCRIPTION_IT, "Cambia il PC in INDIRIZZO e continua l'esecuzione"},
/* ko */ {IDGS_MON_GOTO_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_GOTO_DESCRIPTION_NL, "Zet de PC naar ADRES en ga door met de uitvoering van instructies."},
/* ru */ {IDGS_MON_GOTO_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_GOTO_DESCRIPTION_SV, "Ändra PC till ADRESS och fortsätt exekveringen"},
/* tr */ {IDGS_MON_GOTO_DESCRIPTION_TR, "PC'yi ADDRESS'e çevirip çalýþtýrmaya devam edin"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_IO_DESCRIPTION,    N_("Print out the I/O area of the emulated machine.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_IO_DESCRIPTION_DA, "Udskriv I/O-området for den emulerede maskine."},
/* de */ {IDGS_MON_IO_DESCRIPTION_DE, "Zeige den I/O Bereich der emulierten Maschine."},
/* fr */ {IDGS_MON_IO_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_IO_DESCRIPTION_HU, "Az emulált gép I/O tartományának mutatása."},
/* it */ {IDGS_MON_IO_DESCRIPTION_IT, "Stampa l'area di I/O del computer emulato."},
/* ko */ {IDGS_MON_IO_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_IO_DESCRIPTION_NL, "Toon de I/O geheugenruimte van de huidige machine."},
/* ru */ {IDGS_MON_IO_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_IO_DESCRIPTION_SV, "Skriv I/O-området för den emulerade maskinen."},
/* tr */ {IDGS_MON_IO_DESCRIPTION_TR, "Emüle edilen makinenin G/Ç alanýný yazdýr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_EXPORT_DESCRIPTION,    N_("Print out list of attached expansion port devices.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_EXPORT_DESCRIPTION_DA, "Udskriv liste over tilsluttede udviddelsesportenheder"},
/* de */ {IDGS_MON_EXPORT_DESCRIPTION_DE, "Zeige eine Liste der Geräte am Expansion Port."},
/* fr */ {IDGS_MON_EXPORT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_EXPORT_DESCRIPTION_HU, ""},  /* fuzzy */
/* it */ {IDGS_MON_EXPORT_DESCRIPTION_IT, "Stampa lista dei dispositivi collegati sulla porta di espansione."},
/* ko */ {IDGS_MON_EXPORT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_EXPORT_DESCRIPTION_NL, "Druk een lijst van gekoppelde uitbreidingspoort apparaten af."},
/* ru */ {IDGS_MON_EXPORT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_EXPORT_DESCRIPTION_SV, "Skriv ut lista över anslutna expansionsportsenheter."},
/* tr */ {IDGS_MON_EXPORT_DESCRIPTION_TR, "Geniþletme yuvasýna takýlý aygýtlarýn listesini yazdýr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_NEXT_DESCRIPTION,    N_("Advance to the next instruction.  Subroutines are treated as\na single instruction.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_NEXT_DESCRIPTION_DA, "Gå frem til næste instruktion. Subrutiner bliver behandlet som\nen enkelt instruktion."},
/* de */ {IDGS_MON_NEXT_DESCRIPTION_DE, "Fahre bis zur nächsten Instruktion fort.\nUnterroutinen werden wie eine einzelne Instruktion behandelt."},
/* fr */ {IDGS_MON_NEXT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_NEXT_DESCRIPTION_HU, "A következõ utasításra lépés.  A szubrutinokat egy\nutasításnak tekinti."},
/* it */ {IDGS_MON_NEXT_DESCRIPTION_IT, "Passa alla prossima istruzione. Le subrutine sono trattate come\nuna singola istruzione."},
/* ko */ {IDGS_MON_NEXT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_NEXT_DESCRIPTION_NL, "Ga naar de volgende instructie. Subroutines worden behandled als een\nenkele instructie."},
/* ru */ {IDGS_MON_NEXT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_NEXT_DESCRIPTION_SV, "Gå till nästa instruktion. Underrutiner hanteras som en\nenda instruktion."},
/* tr */ {IDGS_MON_NEXT_DESCRIPTION_TR, "Sonraki komuta ilerle.  Altrutinler tek bir komutmuþ\ngibi iþlendi."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_REG_NAME,    N_("reg_name")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_REG_NAME_DA, "regnavn"},
/* de */ {IDGS_REG_NAME_DE, "Register Name"},
/* fr */ {IDGS_REG_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDGS_REG_NAME_HU, ""},  /* fuzzy */
/* it */ {IDGS_REG_NAME_IT, "nome registro"},
/* ko */ {IDGS_REG_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDGS_REG_NAME_NL, "register naam"},
/* ru */ {IDGS_REG_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDGS_REG_NAME_SV, "regnamn"},
/* tr */ {IDGS_REG_NAME_TR, "reg_ismi"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_NUMBER,    N_("number")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_NUMBER_DA, "nummer"},
/* de */ {IDGS_NUMBER_DE, "Nummer"},
/* fr */ {IDGS_NUMBER_FR, ""},  /* fuzzy */
/* hu */ {IDGS_NUMBER_HU, ""},  /* fuzzy */
/* it */ {IDGS_NUMBER_IT, "numero"},
/* ko */ {IDGS_NUMBER_KO, "¼ýÀÚ"},
/* nl */ {IDGS_NUMBER_NL, "nummer"},
/* ru */ {IDGS_NUMBER_RU, ""},  /* fuzzy */
/* sv */ {IDGS_NUMBER_SV, "nummer"},
/* tr */ {IDGS_NUMBER_TR, "sayý"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_REGISTERS_DESCRIPTION,    N_("Assign respective registers.  With no parameters, display register\nvalues.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_REGISTERS_DESCRIPTION_DA, "Tildel værdi til registre. Uden parametre vises nuværende værdier\ni registrene."},
/* de */ {IDGS_MON_REGISTERS_DESCRIPTION_DE, "Zuweisung auf entsprechende Register. Ohne Parameter, zeige Register Werte."},
/* fr */ {IDGS_MON_REGISTERS_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_REGISTERS_DESCRIPTION_HU, "Megadott regiszterek beállítása. Paraméterek nélkül, a regiszterek\ntartalmának kiírása."},
/* it */ {IDGS_MON_REGISTERS_DESCRIPTION_IT, "Assegna i rispettivi registri. Senza parametri, mostra i valori dei\nregistri."},
/* ko */ {IDGS_MON_REGISTERS_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_REGISTERS_DESCRIPTION_NL, "Vul opgegeven registers met de toebehorende waarde. Zonder parameter, toon\nde huidige waarden in de registers."},
/* ru */ {IDGS_MON_REGISTERS_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_REGISTERS_DESCRIPTION_SV, "Tilldela respektive register. Utan parametrar visas innehållet\ni registren."},
/* tr */ {IDGS_MON_REGISTERS_DESCRIPTION_TR, "Sýrayla registerlara ata.  parametreler olmadan, register deðerlerini\ngörüntüle."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_RESET_DESCRIPTION,    N_("Reset the machine or drive. Type: 0 = soft, 1 = hard, 8-11 = drive.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_RESET_DESCRIPTION_DA, "Reset maskine eller diskettedrev. Type: 0 = blød, 1 = hård,\n8-11 = diskettedrev."},
/* de */ {IDGS_MON_RESET_DESCRIPTION_DE, "Reset der Maschine oder des Laufwerks. Typ: 0 = soft, 1 = hart, 8-11 = Laufwerk."},
/* fr */ {IDGS_MON_RESET_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_RESET_DESCRIPTION_HU, "A számítógép vagy meghajtó újraindítása. Típus: 0 = meleg, 1 = hideg, 8-11 = meghajtó."},
/* it */ {IDGS_MON_RESET_DESCRIPTION_IT, "Resetta il computer o il drive. Tipo: 0 = soft, 1 = hard, 8-11 = drive."},
/* ko */ {IDGS_MON_RESET_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_RESET_DESCRIPTION_NL, "Reset de machine of drive. Soort: 0 = zacht, 1 = hard, 8-11 = drive."},
/* ru */ {IDGS_MON_RESET_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_RESET_DESCRIPTION_SV, "Återställ maskinen eller diskettstationen. Typ: 0 = mjuk, 1 = hård,\n8-11 = diskettstation."},
/* tr */ {IDGS_MON_RESET_DESCRIPTION_TR, "Makine ya da sürücüyü resetle. Tip: 0 = soft, 1 = hard, 8-11 = drive."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_RETURN_DESCRIPTION,    N_("Continues execution and returns to the monitor just before the next\nRTS or RTI is executed.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_RETURN_DESCRIPTION_DA, "Fortsæt eksekveringen og vend tilbage til monitoren lige inden næste\nRTS eller RTI udføres."},
/* de */ {IDGS_MON_RETURN_DESCRIPTION_DE, "Setzt Ausführung fort und retourniert bevor der nächsten RTS oder RTI instruction."},
/* fr */ {IDGS_MON_RETURN_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_RETURN_DESCRIPTION_HU, "Folytatja a végrehajtást és visszatér a monitorba a következõ\nRTS vagy RTI utasítás elõtt."},
/* it */ {IDGS_MON_RETURN_DESCRIPTION_IT, "Continua l'esecuzione e ritorna al monitor subito prima della prossima\nesecuzione di RTS o RTI."},
/* ko */ {IDGS_MON_RETURN_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_RETURN_DESCRIPTION_NL, "Ga door met uitvoeren van instructies en kom terug naar de monitor net voor de\nvolgende RTS of RTI wordt uitgevoerd."},
/* ru */ {IDGS_MON_RETURN_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_RETURN_DESCRIPTION_SV, "Fortsätt exekveringen och återgå till monitorn precis innan nästa\nRTS eller RTI exekveras."},
/* tr */ {IDGS_MON_RETURN_DESCRIPTION_TR, "Çalýþmaya devam eder ve sonraki RTS ya da RTI çalýþtýrýlmadan hemen önce\nmonitöre geri döner."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_SCREEN_DESCRIPTION,    N_("Displays the contents of the screen.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_SCREEN_DESCRIPTION_DA, "Viser skærmens indhold."},
/* de */ {IDGS_MON_SCREEN_DESCRIPTION_DE, "Zeigt Bildschirminhalt."},
/* fr */ {IDGS_MON_SCREEN_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_SCREEN_DESCRIPTION_HU, "A képernyõ tartalmának mutatása."},
/* it */ {IDGS_MON_SCREEN_DESCRIPTION_IT, "Mostra il contenuto dello schermo."},
/* ko */ {IDGS_MON_SCREEN_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_SCREEN_DESCRIPTION_NL, "Toont de inhoud van het scherm."},
/* ru */ {IDGS_MON_SCREEN_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_SCREEN_DESCRIPTION_SV, "Visar skärmens innehåll."},
/* tr */ {IDGS_MON_SCREEN_DESCRIPTION_TR, "Ekran içeriðini görüntüler."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_STEP_DESCRIPTION,    N_("Single-step through instructions.  COUNT allows stepping\nmore than a single instruction at a time.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_STEP_DESCRIPTION_DA, "Gå skridtvis gennem instruktioner. Hvis ANTAL angives kan\nflere instruktioner udføres i hvert skridt."},
/* de */ {IDGS_MON_STEP_DESCRIPTION_DE, "Einzelschritt Ausführung durch Instruktionen. COUNT erlaubt die Ausführung\nmehrerer Instruktionen auf einmal."},
/* fr */ {IDGS_MON_STEP_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_STEP_DESCRIPTION_HU, "Lépkedés egyesével az utasításokon.  A DARAB-bal beállítható,\nha több utasítást kell ugrani egyszerre."},
/* it */ {IDGS_MON_STEP_DESCRIPTION_IT, "Modalità single step attraverso le istruzioni. Il CONTATORE permette\ndi attraversare più di una singola istruzione per volta."},
/* ko */ {IDGS_MON_STEP_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_STEP_DESCRIPTION_NL, "Enkel-stap door de instructies. AANTAL zorgt ervoor dat er meerdere\ninstructies worden uitgevoerd in een keer."},
/* ru */ {IDGS_MON_STEP_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_STEP_DESCRIPTION_SV, "Stega genom instruktioner. ANTAL gör det möjligt att stega\ngenom mer än en enkel instruktion i varje steg."},
/* tr */ {IDGS_MON_STEP_DESCRIPTION_TR, "Komutlara doðru tek-adým.  COUNT bir defada birden fazla\nkomutu adýmlamaya izin verir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_UNDUMP_DESCRIPTION,    N_("Read a snapshot of the machine from the file specified.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_UNDUMP_DESCRIPTION_DA, "Indlæs snapshot af maskinen fra den angivne fil."},
/* de */ {IDGS_MON_UNDUMP_DESCRIPTION_DE, "Lese einen Snapshot der Maschine aus der angegebenen Datei."},
/* fr */ {IDGS_MON_UNDUMP_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_UNDUMP_DESCRIPTION_HU, "A pillanatkép betöltése a megadott fájlból."},
/* it */ {IDGS_MON_UNDUMP_DESCRIPTION_IT, "Legge lo snapshot del computer dal file specificato."},
/* ko */ {IDGS_MON_UNDUMP_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_UNDUMP_DESCRIPTION_NL, "Lees een momentopname voor de machine van het opgegeven bestand."},
/* ru */ {IDGS_MON_UNDUMP_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_UNDUMP_DESCRIPTION_SV, "Läs en ögonblicksbild för maskinen från den angivna filen."},
/* tr */ {IDGS_MON_UNDUMP_DESCRIPTION_TR, "Belirtilen dosyadan makinenin anlýk görüntüsünü oku."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_SYMBOL_TABLE_COMMANDS,    N_("Symbol table commands:")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_SYMBOL_TABLE_COMMANDS_DA, "Symboltabel-kommandoer:"},
/* de */ {IDGS_SYMBOL_TABLE_COMMANDS_DE, "Symbol Tabellen Kommandos:"},
/* fr */ {IDGS_SYMBOL_TABLE_COMMANDS_FR, ""},  /* fuzzy */
/* hu */ {IDGS_SYMBOL_TABLE_COMMANDS_HU, ""},  /* fuzzy */
/* it */ {IDGS_SYMBOL_TABLE_COMMANDS_IT, "Comandi tabella dei simboli:"},
/* ko */ {IDGS_SYMBOL_TABLE_COMMANDS_KO, ""},  /* fuzzy */
/* nl */ {IDGS_SYMBOL_TABLE_COMMANDS_NL, "Symbool tabel commandos:"},
/* ru */ {IDGS_SYMBOL_TABLE_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SYMBOL_TABLE_COMMANDS_SV, "Kommandon för symboltabell:"},
/* tr */ {IDGS_SYMBOL_TABLE_COMMANDS_TR, "Sembol tablosu komutlarý:"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_LABEL,    N_("label")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_LABEL_DA, "etiket"},
/* de */ {IDGS_LABEL_DE, "Bezeichner"},
/* fr */ {IDGS_LABEL_FR, ""},  /* fuzzy */
/* hu */ {IDGS_LABEL_HU, ""},  /* fuzzy */
/* it */ {IDGS_LABEL_IT, "etichetta"},
/* ko */ {IDGS_LABEL_KO, ""},  /* fuzzy */
/* nl */ {IDGS_LABEL_NL, "label"},
/* ru */ {IDGS_LABEL_RU, ""},  /* fuzzy */
/* sv */ {IDGS_LABEL_SV, "etikett"},
/* tr */ {IDGS_LABEL_TR, "etiket"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_ADD_LABEL_DESCRIPTION,    N_("<memspace> is one of: C: 8: 9: 10: 11:\n<address>  is the address which should get the label.\n<label>    is the name of the label; it must start with a dot (\".\").\n\nMap a given address to a label.  This label can be used when entering\nassembly code and is shown during disassembly.  Additionally, it can\nbe used whenever an address must be specified.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_ADD_LABEL_DESCRIPTION_DA, "<huk.område>   er en af C: 8: 9: 10: eller 11:\n<adresse>      Er adressen som skal have etiketten.\n<etiket>       er navnet på etiketten; skal starte med punktum (\".\").\n\nSæt en etiket for en adresse. Etiketten kan angives når der indtastes\nassemblerkode, og vises ved disassemblering. Desuden kan den bruges\nhvor en adresse skal angives."},
/* de */ {IDGS_MON_ADD_LABEL_DESCRIPTION_DE, "<Speicherbereich> ist aus: C: 8: 9: 10: 11:\n<Adresse>         bezeichnet die Adresse welche mit dem Bezeichner assoziert werden soll.\n<Bezeichner>      Name des Bezeichners; Muss mit einem Punkt (\".\") starten.\n\nAssoziiert einen Bezeichner mit einer Adresse. Dieser Bezeichner kann \nbei der Eingabe von Asssmblercode benutzt werden und wird auch beim\nDisassemblieren gezeigt. Darüber hinaus kann der Bezeichner überall\ndort genutzt werden, wo eine Adresseingabe nötig ist."},
/* fr */ {IDGS_MON_ADD_LABEL_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_ADD_LABEL_DESCRIPTION_HU, "A <memória tér> ezek közül: C: 8: 9: 10: 11:\n<cím>  amelyik címhez a címkét rendelje.\n<címke>    a címke neve; ponttal kell kezdõdjön (\".\").\n\nAz adott cím rendelése a címkéhez.  Ez a címke használható assembly\nprogram beírásakor, és visszafejtéskor megjelenik.  Mindig használható,\namikor valamilyen címet kell megadni."},
/* it */ {IDGS_MON_ADD_LABEL_DESCRIPTION_IT, "<spazio di memoria> è uno tra: C: 8: 9: 10: 11:\n<indirizzo> è l'indirizzo a cui deve essere associata l'etichettal.\n<etichetta> è il nome dell'etichetta; deve iniziare con un punto (\".\").\n\nAssocia l'indirizzo specificato all'etichetta. Questa etichetta può\nessere usata quando si inserisce codice assembly ed è mostrata\nnella disassemblazione. In aggiunta, può essere usata ogni volta che\ndeve essere specificato un indirizzo."},
/* ko */ {IDGS_MON_ADD_LABEL_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_ADD_LABEL_DESCRIPTION_NL, "<geheugenruimte> is een van: C: 8: 9: 10: 11:\n<adres>          is het adres waaraan de label gekoppelt moet worden.\n<label>          is de naam van de label; de naam moet beginnen met een punt\n                 (\".\").\n\nKoppel een opgegeven adres aan een label. Dit label kan worden gebruikt bij\nhet invoeren van assembleer code en wordt getoont bij een disassemblering.\nTevens kan de label gebruikt worden in plaats van het adres."},
/* ru */ {IDGS_MON_ADD_LABEL_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_ADD_LABEL_DESCRIPTION_SV, "<minnesområde> är en av: C: 8: 9: 10: 11:\n<adress>       är adressen som ska få etiketten.\n<etikett>      är namnet på etiketten; måste starta med punkt (\".\").\n\nKoppla en adress till en etikett. Etiketten kan anges när assemblerkod\nmatas in och visas vid disassemblering. I tillägg kan den användas\nnärhelst en adress måste anges."},
/* tr */ {IDGS_MON_ADD_LABEL_DESCRIPTION_TR, "<bellekalaný> bunlardan biridir: C: 8: 9: 10: 11:\n<adres>       etiketin duracaðý adresi belirler.\n<etiket>      etiketin ismidir; nokta karakteriyle baþlamalýdýr (\".\").\n\nEtiketi verilen adrese eþleþtir.  Bu etiket assembly kod girilirken kullanýlýr\nve disassembly sýrasýnda gösterilir.  Ek olarak, ne zaman bir adres\nbelirtilmesi gerekse kullanýlabilir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DELETE_LABEL_DESCRIPTION,    N_("<memspace> is one of: C: 8: 9: 10: 11:\n<label>    is the name of the label; it must start with a dot (\".\").\n\nDelete a previously defined label.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_DA, "<huk.område>   er en af C: 8: 9: 10: eller 11:\n<etiket>       er navnet på etiketten; skal starte med punktum (\".\").\n\nFjern en tidligere oprettet etiket."},
/* de */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_DE, "<Speicherbereich> ist aus: C: 8: 9: 10: 11:\n<Bezeichner>      Name des Bezeichners; Muss mit einem Punkt (\".\") starten.\n\nLöscht einen zuvor definierten Bezeichner."},
/* fr */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_HU, "<memória tér> egy ezek közül: C: 8: 9: 10: 11:\n<címke>    a címke neve; ponttal kell kezdõdjön (\".\").\n\nElõzõleg megadott címke törlése."},
/* it */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_IT, "<spazio di memoria> è uno tra: C: 8: 9: 10: 11:\n<etichetta> è il nome dell'etichetta; deve iniziare con un punto (\".\").\n\nCancella una etichetta definita precedentemente."},
/* ko */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_NL, "<geheugenruimte> is een van: C: 8: 9: 10: 11:\n<label>          is de naam van de label; de naam moet beginnen met een\npunt (\".\").\n\nVerwijder een gekoppelde label."},
/* ru */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_SV, "<minnesområde> är en av: C: 8: 9: 10: 11:\n<etikett>      är namnet på etiketten; måste starta med punkt (\".\").\n\nTa bort en tidigare angiven etikett."},
/* tr */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_TR, "<bellekalaný> bunlardan biridir: C: 8: 9: 10: 11:\n<etiket>      etiketin ismidir; nokta karakteriyle baþlamalýdýr (\".\").\n\nÖnceden tanýmlanmýþ bir etiketi sil."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_LOAD_LABELS_DESCRIPTION,    N_("Load a file containing a mapping of labels to addresses.  If no memory\nspace is specified, the default readspace is used.\n\nThe format of the file is the one written out by the `save_labels' command;\nit consists of some `add_label' commands, written one after the other.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_DA, "Indlæs en fil som indeholder mapning fra labels til adresser.\nHvis der ikke angives hukommelsesområde, anvendes det normale læseområde.\n\nFormatet på filen er det, som skrives af \"save_labels\"-kommandoen;\ndet består af \"add_label\"-kommandoer efter hinanden."},
/* de */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_DE, "Lädt eine Datei mit Zuordnung von Adressen zu Bezeichnern. Wenn kein \nSpeicherbereich angegeben wurde, wird der Standard Speicherplatz\nverwendet. Das Format der Datei wird durch das Kommande `save_lables'\ndefiniert. Es besteht aus eine Reihe von `add_label' Kommandos,\nhintereinander angeordnet."},
/* fr */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_HU, "Címkékrõl címekre leképezéseket tartalmazó fájl betöltése.  Ha nincs memória\ntér megadva, az alap tér lesz használva.\n\nA fájl formátuma megegyezik a `save_labels' parancs által kiírtéval;\nnéhány egymás után írt `add_label' parancsból áll."},
/* it */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_IT, "Carica un file che contiente l'associazione tra le etichette e gli indirizzi.\nSe non è specificato alcuno spazio di memoria, viene usato lo spazio\ndi lettura predefinito.\n\nIl formato del file è quello dato in output dal comando `save_labels';\nè composto da alcuni comandi `add_label', scritti uno di seguito all'altro."},
/* ko */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_NL, "Laad een bestand met de koppelingen tussen labels en adressen. Als er geen\ngeheugenruimte is opgegeven zal de standaard geheugenruimte worden gebruikt.\nHet formaat van het bestand is die door het commando 'save_labels' wordt\ngeschreven; het bestaat uit een aantal 'add_label' commandos na elkaar."},
/* ru */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_SV, "Läs in en fil som innehåller koppling från etiketter till adresser.\nOm inget minnesområde anges användas standard-läsadressen.\n\nFormatet på filen är samma som skrivs av \"save_labels\"-kommandot;\ndet består av några \"add_label\"-kommandon efter varandra."},
/* tr */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_TR, "Etiketleri adreslerle eþleþtirilmiþ bir dosya yükleyin.  Eðer bellek\nalaný belirtilmemiþse, varsayýlan okuma alaný kullanýlýr.\n\nDosyanýn biçimi `save_labels' komutu ile yazýlmýþ olandýr;\nbu peþ peþe yazýlmýþ `add_label' komutlarýndan ibarettir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_SAVE_LABELS_DESCRIPTION,    N_("Save labels to a file.  If no memory space is specified, all of the\nlabels are saved.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_DA, "Gem etiketter til fil. Hvis der ikke angives et hukommelsesområde\ngemmes alle etiketter."},
/* de */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_DE, "Speichere Bezeichner in eine Datei. Wenn kein Speicherbereich\nangegeben wurde, werden alle Bezeichner gespeichert."},
/* fr */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_HU, "Címkék mentése fájlba.  Ha nincs memória tartomány megadva, az\nösszes címkét menti."},
/* it */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_IT, "Salva le etichette su file. Se non è specificato alcuno spazio di memoria,\nvengono salvate tutte le etichette."},
/* ko */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_NL, "Sla de labels op in een bestand. Als er geen geheugenruimte is opgegeven\nworden alle labels opgeslagen."},
/* ru */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_SV, "Spara etiketter till en fil. Om inget minnesområde anges sparas alla\netiketterna."},
/* tr */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_TR, "Etiketleri bir dosyaya kaydet.  Eðer bellek alaný belirtilmemiþse, tüm\netiketler kaydedilir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_SHOW_LABELS_DESCRIPTION,    N_("Display current label mappings.  If no memory space is specified, show\nall labels.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_DA, "Vis aktuelle etiketter. Hvis der ikke angives et hukommelsesområde vises\nalle etiketter."},
/* de */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_DE, "Zeige aktuelle Bezeichner Zuordnungen. Wenn kein Speicherbereich angegeben\nwurde, werden alle Bezeichner gezeigt."},
/* fr */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_HU, "Az aktuális címke leképezések mutatása.  Ha nincs a memória tér megadva, az\nösszeset mutatja."},
/* it */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_IT, "Mostra l'associazione delle etichette correnti. Se non è specificato alcun\nspazio di memoria, verranno mostrate tutte le etichette."},
/* ko */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_NL, "Toon huidige label koppelingen. Als er geen geheugenruimte is opgegeven\nworden all labels getoont."},
/* ru */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_SV, "Visar aktuella etiketter. Om inget minnesområde anges visas alla\netiketter."},
/* tr */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_TR, "Geçerli etiket eþleþmelerini görüntüle.  Eðer bellek alaný belirtilmemiþse,\ntüm etiketleri göster."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS,    N_("Assembler and memory commands:")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_DA, "Assembler- og hukommelseskommandoer:"},
/* de */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_DE, "Assembler und Speicher Kommandos:"},
/* fr */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_HU, ""},  /* fuzzy */
/* it */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_IT, "Comandi assembler e memoria:"},
/* ko */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_NL, "Assembler en geheugen commandos:"},
/* ru */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_SV, "Assembler- och minneskommandon:"},
/* tr */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_TR, "Assembler ve bellek komutlarý:"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_DATA_LIST,    N_("data_list")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_DATA_LIST_DA, "dataliste"},
/* de */ {IDGS_DATA_LIST_DE, "Datenliste"},
/* fr */ {IDGS_DATA_LIST_FR, ""},  /* fuzzy */
/* hu */ {IDGS_DATA_LIST_HU, ""},  /* fuzzy */
/* it */ {IDGS_DATA_LIST_IT, "lista di dati"},
/* ko */ {IDGS_DATA_LIST_KO, ""},  /* fuzzy */
/* nl */ {IDGS_DATA_LIST_NL, "data_lijst"},
/* ru */ {IDGS_DATA_LIST_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DATA_LIST_SV, "datalista"},
/* tr */ {IDGS_DATA_LIST_TR, "veri_listesi"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_WRITE_DESCRIPTION,    N_("Write the specified data at `address'.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_WRITE_DESCRIPTION_DA, "Gem angivne data på \"adresse\"."},
/* de */ {IDGS_MON_WRITE_DESCRIPTION_DE, "Schreibe das angegebene Datum auf `Adresse'."},
/* fr */ {IDGS_MON_WRITE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_WRITE_DESCRIPTION_HU, "A megadott adat `cím' helyre írása."},
/* it */ {IDGS_MON_WRITE_DESCRIPTION_IT, "Scrive il dato specificato all'indirizzo."},
/* ko */ {IDGS_MON_WRITE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_WRITE_DESCRIPTION_NL, "Schrijf de opgegevem data op `adres'."},
/* ru */ {IDGS_MON_WRITE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_WRITE_DESCRIPTION_SV, "Skriv angiven data på \"adress\"."},
/* tr */ {IDGS_MON_WRITE_DESCRIPTION_TR, "`adres' bölümünde belirlenmiþ bir veri yaz."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_INSTRUCTION,    N_("instruction")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_INSTRUCTION_DA, "instruktion"},
/* de */ {IDGS_INSTRUCTION_DE, "Instruktion"},
/* fr */ {IDGS_INSTRUCTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_INSTRUCTION_HU, ""},  /* fuzzy */
/* it */ {IDGS_INSTRUCTION_IT, "istruzione"},
/* ko */ {IDGS_INSTRUCTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_INSTRUCTION_NL, "instructie"},
/* ru */ {IDGS_INSTRUCTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_INSTRUCTION_SV, "instruktion"},
/* tr */ {IDGS_INSTRUCTION_TR, "komut"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_ASSEMBLE_DESCRIPTION,    N_("Assemble instructions to the specified address.  If only one\ninstruction is specified, enter assembly mode (enter an empty line to\nexit assembly mode).")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_ASSEMBLE_DESCRIPTION_DA, "Skriv assemblerinstruktioner til adresse. Hvis kun en instruktion\nangives, skiftes til assembler-tilstand (indtast en tom linje for\nat afslutte assembler-tilstanden)."},
/* de */ {IDGS_MON_ASSEMBLE_DESCRIPTION_DE, "Assmbler Instruktionen zur angebenen Adresse. Wenn nur eine Instruktion\nangegeben wurde, wird der assemblier Modus aktiviert (Eingabe einer leeren\nZeile beendet den assemblier Modus)."},
/* fr */ {IDGS_MON_ASSEMBLE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_ASSEMBLE_DESCRIPTION_HU, "Utasítások fordítása a megadott címre. Ha csak egy utasítás\nvan, fordító módba lép (üres sort kell beírni a kilépéshez)."},
/* it */ {IDGS_MON_ASSEMBLE_DESCRIPTION_IT, "Assembla le istruzioni a partire dall'indirizzo specificato. Se solo una\nistruzione è specificata, entra in modalità assembly (inserire una\nlinea vuota per uscire da questa modalità)."},
/* ko */ {IDGS_MON_ASSEMBLE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_ASSEMBLE_DESCRIPTION_NL, "Assembleer instructies naar het opgegeven adres. Als er alleen een instructie\nis opgegeven dan wordt de assembleer modus ingeschakelt (geef een lege regel\nin om de assembleer modus te verlaten)."},
/* ru */ {IDGS_MON_ASSEMBLE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_ASSEMBLE_DESCRIPTION_SV, "Assemblera instruktioner till angiven adress. Om endast en\ninstruktion angavs, aktivera assemblerläge (mata in en tom rad\nför att avsluta assemblerläget)."},
/* tr */ {IDGS_MON_ASSEMBLE_DESCRIPTION_TR, "Komutlarý belirlenmiþ adrese çevir.  Eðer yalnýzca bir\nkomut belirlenmiþse, assembly moduna gir (assembly modundan çýkmak için\nboþ bir satýr girin)."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_ADDRESS_RANGE,    N_("address_range")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ADDRESS_RANGE_DA, "adresseområde"},
/* de */ {IDGS_ADDRESS_RANGE_DE, "Adressbereich"},
/* fr */ {IDGS_ADDRESS_RANGE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ADDRESS_RANGE_HU, ""},  /* fuzzy */
/* it */ {IDGS_ADDRESS_RANGE_IT, "intervallo indirizzi"},
/* ko */ {IDGS_ADDRESS_RANGE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ADDRESS_RANGE_NL, "adres_bereik"},
/* ru */ {IDGS_ADDRESS_RANGE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ADDRESS_RANGE_SV, "adressområde"},
/* tr */ {IDGS_ADDRESS_RANGE_TR, ""},  /* fuzzy */
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_COMPARE_DESCRIPTION,    N_("Compare memory from the source specified by the address range to the\ndestination specified by the address.  The regions may overlap.  Any\nvalues that miscompare are displayed using the default displaytype.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_COMPARE_DESCRIPTION_DA, "Sammenlign hukommelse fra kilden, angivet ved adresseområdet med\nmålet, angivet ved adresse. Områderne kan overlappe. Alle værdier\nsom er forskellige vil blive vist med standard visning."},
/* de */ {IDGS_MON_COMPARE_DESCRIPTION_DE, "Vergleiche angegebenen Adressbereich mit der Zieladresse.\nDie Bereiche können überlappen. Ungleiche Werte werden mit dem\nStandardanzeigetyp gezeigt."},
/* fr */ {IDGS_MON_COMPARE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_COMPARE_DESCRIPTION_HU, "A forrás memóriatartomány összehasonlítása a céllal megadott\nmemóriatartománnyal. A tartományok átfedése megengedett.  Minden\nmeg nem egyezõ értéket kiír az alap adat típussal."},
/* it */ {IDGS_MON_COMPARE_DESCRIPTION_IT, "Confronta la memoria della sorgente specificata dall'intervallo di\nindirizzi con la destinazione specificata dall'indirizzo. Le regioni possono\nsovrapporsi. Qualsiasi valore che non corrisponde è visualizzato\nutilizzando il tipo di dato predefinito."},
/* ko */ {IDGS_MON_COMPARE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_COMPARE_DESCRIPTION_NL, "Vergelijk geheugen van de bron opgegeven door de adres reeks met het doel\nopgegeven door het adres. De reeksen mogen overlappen. De data die niet\ngelijk is zal worden getoont volgens de huidige toon soort."},
/* ru */ {IDGS_MON_COMPARE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_COMPARE_DESCRIPTION_SV, "Jämför minne från källan som anges av adressområdet mot destinationen\nsom anges av adressen. Områdena kan vara överlappande. Alla värden\nsom skiljer sig vid jämförelsen visas med standardvisningssättet."},
/* tr */ {IDGS_MON_COMPARE_DESCRIPTION_TR, "Belleði adresle belirtilen kaynaktan adresle belirtilen hedefin bulunduðu\naralýkta karþýlaþtýr.  Bölgeler belki üst üste binebilir.  Uyuþmayan\nherhangi bir deðer varsayýlan görüntüleme tipine baðlý olarak görüntülenir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_CHECKNUM,    N_("checknum")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CHECKNUM_DA, "checknum"},
/* de */ {IDGS_CHECKNUM_DE, "Checknummer"},
/* fr */ {IDGS_CHECKNUM_FR, ""},  /* fuzzy */
/* hu */ {IDGS_CHECKNUM_HU, ""},  /* fuzzy */
/* it */ {IDGS_CHECKNUM_IT, "checknum"},
/* ko */ {IDGS_CHECKNUM_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CHECKNUM_NL, "checknum"},
/* ru */ {IDGS_CHECKNUM_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CHECKNUM_SV, "kontrollnr"},
/* tr */ {IDGS_CHECKNUM_TR, "kontrolnumarasý"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DELETE_DESCRIPTION,    N_("Delete checkpoint `checknum'.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DELETE_DESCRIPTION_DA, "Slet checkpoint \"checknum\"."},
/* de */ {IDGS_MON_DELETE_DESCRIPTION_DE, "Lösche Checkpoint `Checknummer'."},
/* fr */ {IDGS_MON_DELETE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DELETE_DESCRIPTION_HU, "`ell_pont_szám' ellenõrzési pont törlése."},
/* it */ {IDGS_MON_DELETE_DESCRIPTION_IT, "Cancella il punto di controllo `checknum'."},
/* ko */ {IDGS_MON_DELETE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DELETE_DESCRIPTION_NL, "Verwijder checkpunt `checknum'."},
/* ru */ {IDGS_MON_DELETE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DELETE_DESCRIPTION_SV, "Ta bort kontrollpunkt \"kontrollnr\"."},
/* tr */ {IDGS_MON_DELETE_DESCRIPTION_TR, "`kontrolnumarasý' kontrol noktasýný sil."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DISASS_DESCRIPTION,    N_("Disassemble instructions.  If two addresses are specified, they are\nused as a start and end address.  If only one is specified, it is\ntreated as the start address and a default number of instructions are\ndisassembled.  If no addresses are specified, a default number of\ninstructions are disassembled from the dot address.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DISASS_DESCRIPTION_DA, "Disassemblér instruktioner. Hvis der angives to adresser anvendes disse\nsom start- og slutadresse. Angives kun en adresse bruges denne som startadresse\nog et standard antal instruktioner disassembleres. Hvis ingen adresse\nangives disassembleres et standard antal instruktioner fra den aktuelle\nadresse."},
/* de */ {IDGS_MON_DISASS_DESCRIPTION_DE, "Disassembliere Instruktionen. Wenn zwei Adressen angegeben werden,\nwerden diese als Start- und Zieladresse interpretiert. Wenn nur eine\nAdress angegeben wird, wird diese asl Startadresse interpretiert und\ndie Standardanzahl an Instruktionen werden disassembliert. Wenn keine\nAdresse angegeben wird, wird von der aktuellen Adresse disassembliert."},
/* fr */ {IDGS_MON_DISASS_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DISASS_DESCRIPTION_HU, "Utasítások visszafejtése. Ha két cím van megadva, elsõ és utolsó\ncímként értelmezi õket. Ha csak egy, akkor elsõ címként, és az alap\nszámú utasítás kerül visszafejtésre. Ha nincs cím megadva, az aktuális\ncímtõl kezdi a visszafejtést, és a szokásos számú utasítást ír ki."},
/* it */ {IDGS_MON_DISASS_DESCRIPTION_IT, "Disassembla le istruzioni. Se sono specificati due indirizzi, questi\nsono utilizzati come indirizzo di inizio e fine. Se ne viene specificato\nsolo uno, è usato come indirizzo di partenza e viene disassemblato\nil numero di istruzioni predefinito. Se non viene specificato nessun\nindirizzo, viene disassemblato il numero di istruzioni predefinito\ndall'indirizzo dot."},
/* ko */ {IDGS_MON_DISASS_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DISASS_DESCRIPTION_NL, "Disassembleer instructies. Als er twee adressen zijn opgegeven dan worden\ndeze gebruikt als een start en eind adres. Als er maar een adres is\nopgegeven dan wordt deze gebruikt als het start adres en een standaard\naantal instructies zal worden gedisassembleerd. Als er geen adressen zijn\nopgegeven dan wordt een standaard aantal instructies gedisassembleerd vanaf\nhet huidige adres."},
/* ru */ {IDGS_MON_DISASS_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DISASS_DESCRIPTION_SV, "Disassemblera instruktioner. Om två adresser anges används de som\nstart- och slutadress. Om endast en anges används den som startadress\noch ett standardantal instruktioner disassembleras. Om ingen adress\nanges disassembleras ett standardantal instruktioner från punktadressen."},
/* tr */ {IDGS_MON_DISASS_DESCRIPTION_TR, "Komutlarý disassemble et.  Eðer iki adres girildiyse, bunlar baþlangýç\nve bitiþ adresleri olarak kullanýlýr.  Eðer tek adres girildiyse, bu\nadres baþlangýç adresi olarak kabul edilir ve varsayýlan sayýda komutlar\ndisassemble edilir.  Eðer hiç adres girilmediyse, varsayýlan sayýda\nkomutlar nokta baþlangýç adresinden itibaren disassemble edilir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_FILL_DESCRIPTION,    N_("Fill memory in the specified address range with the data in\n<data_list>.  If the size of the address range is greater than the size\nof the data_list, the data_list is repeated.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_FILL_DESCRIPTION_DA, "Fyld hukommelsen i det angivne adresseområde med data fra <dataliste>.\nHvis størrelsen på adresseområdet er større end størrelsen af dataliste\ngentages indholdet i dataliste."},
/* de */ {IDGS_MON_FILL_DESCRIPTION_DE, "Fülle den angegebenen Adressbereich mit den Daten aus <Datenliste>.\nWenn die Größe des Adressbereichs größer als <Datenliste> ist, werden\ndie Daten wiederholt."},
/* fr */ {IDGS_MON_FILL_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_FILL_DESCRIPTION_HU, "A memória kitöltése az <adat_lista> paraméterben megadott adatokkal.\nHa a címtartomány nagyobb, mint a lista, ismételni fogja azt."},
/* it */ {IDGS_MON_FILL_DESCRIPTION_IT, "Riempe la memoria nell'intervallo di indirizzi specificato con i dati\npresenti in <lista di dati>. Se la dimensione dell'intervallo è maggiore\ndella dimensione della lista di dati, la lista di dati è ripetuta."},
/* ko */ {IDGS_MON_FILL_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_FILL_DESCRIPTION_NL, "Vul het geheugen van de opgegeven adres reeks op met de data in <data_lijst>.\nAls de grootte van de adres reeks groter is dan de grootte van de data_lijst\ndan zal de data_lijst worder herhaald."},
/* ru */ {IDGS_MON_FILL_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_FILL_DESCRIPTION_SV, "Fyll minnet i det angivna området med data i <datalista>.\nOm storleken på adressområdet är större än storleken på datalistan\nrepeteras innehållet i datalistan."},
/* tr */ {IDGS_MON_FILL_DESCRIPTION_TR, "<veri_listesi>'nde bulunan verilerle belirtilen bellek aralýðýný doldur.\nEðer verilen adres aralýðý veri_listesi'nden büyükse, veri_listesi'nde\nyer alan veriler tekrar ettirilir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_HUNT_DESCRIPTION,    N_("Hunt memory in the specified address range for the data in\n<data_list>.  If the data is found, the starting address of the match\nis displayed.  The entire range is searched for all possible matches.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_HUNT_DESCRIPTION_DA, "Søg i hukommelsen i det angivne dataområde efter <dataliste>.\nOm data findes vises startadressen for matchet. Hele\nområdet gennemsøges for at finde alle mulige match."},
/* de */ {IDGS_MON_HUNT_DESCRIPTION_DE, "Suche in angebenen Adressbereich nach <Datenliste>. Wenn die Daten gefunden\nwurden, wird die Startadresse gezeigt. Der komplette Bereich wird alle\nVorkommnisse von <Datenliste> untersucht."},
/* fr */ {IDGS_MON_HUNT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_HUNT_DESCRIPTION_HU, "Az <adat_lista> adat keresése a memóriában. Ha megtalálja a sorozatot,\na kezdõcímét kiírja. Az egész tartományt végignézi az összes lehetséges\ntalálat felfedezéséhez."},
/* it */ {IDGS_MON_HUNT_DESCRIPTION_IT, "Cerca nell'intervallo di indirizzi specificato i dati nella <lista di dati>.\nSe il dato è trovato, viene visualizzato l'indirizzo iniziale della\ncorrispondenza. Tutto l'intervallo viene ricercato per tutte le possibili\ncorrispondenze."},
/* ko */ {IDGS_MON_HUNT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_HUNT_DESCRIPTION_NL, "Zoek het adres bereik voor de data in <data_lijst>. Als de data is gevonden\ndan wordt het start adres getoont. Er zal door de hele reeks worden gezocht."},
/* ru */ {IDGS_MON_HUNT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_HUNT_DESCRIPTION_SV, "Sök i minnet i det angivna området med data efter <datalista>.\nOm data påträffas visas startadressen för träffen. Hela\nområdet genomsöks för att hitta alla möjliga träffar."},
/* tr */ {IDGS_MON_HUNT_DESCRIPTION_TR, "<veri_listesi>'nde bulunan veriler için belirtilen bellek aralýðýnda\narama yap.  Eðer veri bulunursa, eþleþen adres aralýðýnýn baþlangýç\nadresi görüntülenir.  Tüm alan mümkün olan eþleþmeler için aranacaktýr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_ADDRESS_OPT_RANGE,    N_("address_opt_range")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ADDRESS_OPT_RANGE_DA, "adresse_evt_område"},
/* de */ {IDGS_ADDRESS_OPT_RANGE_DE, "Optionaler Adressbereich"},
/* fr */ {IDGS_ADDRESS_OPT_RANGE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ADDRESS_OPT_RANGE_HU, ""},  /* fuzzy */
/* it */ {IDGS_ADDRESS_OPT_RANGE_IT, "intervallo di indirizzi opzionale"},
/* ko */ {IDGS_ADDRESS_OPT_RANGE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ADDRESS_OPT_RANGE_NL, "optionele_adres_bereik"},
/* ru */ {IDGS_ADDRESS_OPT_RANGE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ADDRESS_OPT_RANGE_SV, "adress_ev_område"},
/* tr */ {IDGS_ADDRESS_OPT_RANGE_TR, "opsiyonel_adres_aralýðý"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_I_DESCRIPTION,    N_("Display memory contents as PETSCII text.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_I_DESCRIPTION_DA, "Vis hukommelsesindhold som PETSCII-text."},
/* de */ {IDGS_MON_I_DESCRIPTION_DE, "Zeige Speicherinhalt als PETSCII Text."},
/* fr */ {IDGS_MON_I_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_I_DESCRIPTION_HU, "Memória tartalom mutatása PETSCII szövegként."},
/* it */ {IDGS_MON_I_DESCRIPTION_IT, "Mostra il contenuto della memoria come testo PETSCII."},
/* ko */ {IDGS_MON_I_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_I_DESCRIPTION_NL, "Toon geheugen inhoud als PETSCII tekst."},
/* ru */ {IDGS_MON_I_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_I_DESCRIPTION_SV, "Visa minnesinnehåll som PETSCII-text."},
/* tr */ {IDGS_MON_I_DESCRIPTION_TR, "Bellek içeriðini PETSCII yazý biçiminde görüntüle."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_II_DESCRIPTION,    N_("Display memory contents as screen code text.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_II_DESCRIPTION_DA, "Vis hukommelses-indhold som skærm-koder."},
/* de */ {IDGS_MON_II_DESCRIPTION_DE, "Zeige Speicherinhalt als Bildschirmcode Text."},
/* fr */ {IDGS_MON_II_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_II_DESCRIPTION_HU, "Memória tartalom megjelenítése képernyõ kód szövegként."},
/* it */ {IDGS_MON_II_DESCRIPTION_IT, "Mostra il contenuto della memoria come testo screen code."},
/* ko */ {IDGS_MON_II_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_II_DESCRIPTION_NL, "Toon geheugen inhoud als scherm code tekst."},
/* ru */ {IDGS_MON_II_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_II_DESCRIPTION_SV, "Visa minnesinnehåll som skärmkodstext."},
/* tr */ {IDGS_MON_II_DESCRIPTION_TR, "Bellek içeriðini ekran kodu yazý biçiminde görüntüle."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_DATA_TYPE,    N_("data_type")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_DATA_TYPE_DA, "datatype"},
/* de */ {IDGS_DATA_TYPE_DE, "Datentyp"},
/* fr */ {IDGS_DATA_TYPE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_DATA_TYPE_HU, ""},  /* fuzzy */
/* it */ {IDGS_DATA_TYPE_IT, "dati"},
/* ko */ {IDGS_DATA_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_DATA_TYPE_NL, "data_soort"},
/* ru */ {IDGS_DATA_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DATA_TYPE_SV, "datatyp"},
/* tr */ {IDGS_DATA_TYPE_TR, "veri_tipi"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MEM_DESCRIPTION,    N_("Display the contents of memory.  If no datatype is given, the default\nis used.  If only one address is specified, the length of data\ndisplayed is based on the datatype.  If no addresses are given, the\n'dot' address is used.\nPlease note: due to the ambiguous meaning of 'b' and 'd' these data-\ntypes must be given in uppercase!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MEM_DESCRIPTION_DA, "Vis hukommelsens indhold. Hvis datatype ikke angives, bruges standard.\nHvis kun en adresse angives, justeres længden på visningen baseret\npå datatypen. Hvis der ikke angives nogen adresse anvendes \"punktum\"-adressen.\nNote: På grund af tvetydighed for 'b' og 'd' skal disse datatyper\nangives med store bogstaver!"},
/* de */ {IDGS_MON_MEM_DESCRIPTION_DE, "Zeige Speicherinhalt. Wenn kein Datentyp angegeben wurde, wird der\nStandarddatentyp verwendet. Wenn nur eine Adresse angegeben wird, hängt\ndie Länge der Daten vom Datentyp ab. Wenn keine Adresse angeben wurde, \nwird die aktuelle Adresse verwendet.\nAchtung: Wegen der Mehrdeutigkeit von `b' und `d', müssen die\nDatentypen in Großbuchstaben angegeben werden!"},
/* fr */ {IDGS_MON_MEM_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MEM_DESCRIPTION_HU, ""},  /* fuzzy */
/* it */ {IDGS_MON_MEM_DESCRIPTION_IT, "Mostra il contenuto della memoria. Se non è specificato alcun tipo di\ndato, verrà utilizzato quello predefinito. Se è specificato solo un indirizzo,\nla lunghezza del dato visualizzato è basata sul tipo. Se non è specificato\nnessun indirizzo, varrà utilizzato l'indirizzo 'dot'.Nota bene: a causa del significato ambiguo di 'b' e 'd' questi tipi di dati\ndevono essere inseriti in maiuscolo!"},
/* ko */ {IDGS_MON_MEM_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MEM_DESCRIPTION_NL, "Toon de geheugen inhoud. Als er geen datasoort is opgegeven dan zal de standaard\nworden gebruikt. Als er maar een adres is opgegeven dan zal de lengte van de\ngetoonde data gebaseerd worden op de datasoort. Als er geen adres is opgegeven\ndan zal het huidige adres worden gebruikt. Door de onduidelijke betekenis \nvan 'b' en 'd' moeten deze datasoorten opgegeven worden in hoofdletters!"},
/* ru */ {IDGS_MON_MEM_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MEM_DESCRIPTION_SV, "Visa minnets innehåll. Om ingen datatyp anges, används standard.\nOm endast en adress anges, justeras längden på visad data baserat\npå datatypen. Om ingen adress anges används \"punkt\"-adressen.\nObservera: på grund av tvetydig betydelse av \"b\" och \"d\" måste dessa\ndatatyper anges med stora bokstäver!"},
/* tr */ {IDGS_MON_MEM_DESCRIPTION_TR, "Bellek içeriðini göster.  Eðer veri tipi girilmemiþse, varsayýlan\nkullanýlýr.  Yalnýzca bir adres belirtilmiþse, gösterilen verinin\nuzunluðu veri tipine baðlýdýr.  Eðer hiç adres girilmemiþse, 'nokta'\nadresi kullanýlýr.\nLütfen dikkat: 'b' ve 'd'nin karmaþýk anlamlarýndan ötürü bu veri\ntipleri büyükharf olarak verilmelidir!"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MEMCHAR_DESCRIPTION,    N_("Display the contents of memory as character data.  If only one address\nis specified, only one character is displayed.  If no addresses are\ngiven, the ``dot'' address is used.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MEMCHAR_DESCRIPTION_DA, "Vis hukommelsens indhold som tegndata. Hvis kun en adresse\nangives, vises kun et tegn. Hvis ingen adresse angives benyttes\n\"punktum\"-adressen."},
/* de */ {IDGS_MON_MEMCHAR_DESCRIPTION_DE, "Zeige den Inhalt von Speicher als Character Daten. Wenn nur eine Adresse\nangegeben wurde, wird nur ein Zeichen gezeigt. Wenn keine Adresse angegeben\nwurde, wird die aktuelle Adresse verwendet."},
/* fr */ {IDGS_MON_MEMCHAR_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MEMCHAR_DESCRIPTION_HU, "A memória tartalmának megjelenítése karakter grafikaként.  Ha csak egy cím\nadott, egyetlen karakter rajzolódik ki.  Ha nincs cím megadva,\na ``pont'' címet használja."},
/* it */ {IDGS_MON_MEMCHAR_DESCRIPTION_IT, "Mosta il contenuto della memoria come dati caratteri. Se è specificato\nsolo un indirizzo, verrà visualizzato solo un carattere. Se non è\nspecificato alcun indirizzo, varrà utilizzato l'indirizzo ``dot'' ."},
/* ko */ {IDGS_MON_MEMCHAR_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MEMCHAR_DESCRIPTION_NL, "Toon de geheugen inhoud als karakter data. Als er maar een adres is\nopgegeven dan zal er maar een karakter worden weergegeven. Als er geen\nadres is opgegeven dan zal het huidige adres gebruikt worden."},
/* ru */ {IDGS_MON_MEMCHAR_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MEMCHAR_DESCRIPTION_SV, "Visa minnets innehåll som teckendata. Om endast en adress\nanges, visas endast ett tecken. Om ingen adress anges används\n\"punkt\"-adressen."},
/* tr */ {IDGS_MON_MEMCHAR_DESCRIPTION_TR, "Bellek içeriðini karakter verisi olarak göster.  Yalnýzca bir adres\nbelirtilmiþse, yalnýzca tek karakter görüntülenir.  Eðer hiç adres\ngirilmemiþse, 'nokta' adresi kullanýlýr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_FORMAT,    N_("Format")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_FORMAT_DA, "Format"},
/* de */ {IDGS_FORMAT_DE, "Format"},
/* fr */ {IDGS_FORMAT_FR, "Format"},
/* hu */ {IDGS_FORMAT_HU, "Formátum"},
/* it */ {IDGS_FORMAT_IT, "Formato"},
/* ko */ {IDGS_FORMAT_KO, "±¸¼º ¹æ½Ä"},
/* nl */ {IDGS_FORMAT_NL, "Formaat"},
/* ru */ {IDGS_FORMAT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_FORMAT_SV, "Format"},
/* tr */ {IDGS_FORMAT_TR, "Biçim"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION,    N_("Save the memmap as a picture. Format is:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_DA, "Gem memmap som billede. Format:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* de */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_DE, "Speicher die memmap als Bilddaten. Formate:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* fr */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_HU, "Memória térkép mentése képként. A formátum:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* it */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_IT, "Salva la mappa di memoria come immagine. I Formati sono:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* ko */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_NL, "Sla de memmap op als een afbeelding. Formaat is:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* ru */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_SV, "Sparar minneskartan som en bild. Format:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* tr */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_TR, "Bellek haritasýný resim olarak kaydet. Biçim:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MASK,    N_("mask")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MASK_DA, "maske"},
/* de */ {IDGS_MASK_DE, "Maske"},
/* fr */ {IDGS_MASK_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MASK_HU, ""},  /* fuzzy */
/* it */ {IDGS_MASK_IT, "maschera"},
/* ko */ {IDGS_MASK_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MASK_NL, "masker"},
/* ru */ {IDGS_MASK_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MASK_SV, "mask"},
/* tr */ {IDGS_MASK_TR, "maske"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION,    N_("Show the memmap. The mask can be specified to show only those\nlocations with accesses of certain type(s). The mask is a number\nwith the bits \"ioRWXrwx\", where RWX are for ROM and rwx for RAM.\nOptionally, an address range can be specified.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_DA, "Vis memmap. Masken kan angives for kun at vise de celler, som\ner tilgået med valgte typer tilgang. Masken er et tal med\nbitsne \"ioRWXrwx\", hvor RWX er ROM og rwx er RAM.\nEt adresseområde kan eventuelt angives."},
/* de */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_DE, "Zeige die memmap. Die Maske kann so definiert werden, dass nur jene Orte\nmit Zugriff auf spezifische Typ(en) gezeigt werden. Die Maske ist eine Nummer\nmit Bits \"ioRWXrwx\", wobei RWX für ROM und rwx für RAM steht.\nOptional kann ein Adressbereich definiert werden."},
/* fr */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_HU, "A memória térkép mutatása. A maszk úgy állítható, hogy csak azokat a\nhelyeket mutassa, amelyek a megadott eléréssel rendelkeznek. A maszk\negy szám az \"ioRWXrwx\" bitekkel, ahol az RWX a ROM-ra, az rwx a RAM-ra\nvonatkozik. Tetszés szerint egy címtartomány is megadható."},
/* it */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_IT, "Mostra la mappa di memoria. La maschera può essere specificata per\nmostrare solo quelle locazioni con accessi un un certo tipo. La maschera\nè un numero con i bit \"ioRWXrwx\", dove RWX sono per la ROM e\nrwx per la RAM.\nOpzionalmente, può essere specificato anche un intervallo di indirizzi."},
/* ko */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_NL, "Toon de memmap. Het masker kan worden opgegeven zodat er alleen de\nadressen met toegrijpingen van een bepaalde soort(en) zal worden getoond.\nHet masker is een nummer met de bits \"ioRWXrwx\", waar RWX is voor ROM,\nen rwx voor RAM. Er kan optioneel een adres bereik worden opgegeven."},
/* ru */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_SV, "Visa minneskartan. Masken kan anges för att endast visa de\nceller som gäller specifik(a) typ(er). Masken är ett tal\nmed bitarna \"ioRWXrwx\", där RWX är för ROM och rwx är för\nRAM. Ett minnesområde kan eventuellt anges."},
/* tr */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_TR, "Bellek haritasýný göster. Maske, yalnýzca belirli tiplerce eriþilebilen\nkonumlarda belirtilebilir. Maske \"ioRWXrwx\" bitlerinden oluþan bir\nsayýdýr. RWX ROM'u, rwx RAM'i ifade eder. Opsiyonel olarak bir adres\naralýðý belirtilebilir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MEMMAPZAP_DESCRIPTION,    N_("Clear the memmap.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_DA, "Nulstil memmap."},
/* de */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_DE, "Lösche die memmap."},
/* fr */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_HU, "A memória térkép törlése."},
/* it */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_IT, "Cancella la mappa di meoria."},
/* ko */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_NL, "Veeg de memmap schoon."},
/* ru */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_SV, "Töm minneskartan."},
/* tr */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_TR, "Bellek haritasýný temizle."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MEMSPRITE_DESCRIPTION,    N_("Display the contents of memory as sprite data.  If only one address is\nspecified, only one sprite is displayed.  If no addresses are given,\nthe ``dot'' address is used.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MEMSPRITE_DESCRIPTION_DA, "Vis hukommelsens indhold som spritedata. Hvis kun en adresse\nangives, vises kun en sprite. Hvis ingen adresse angives bruges\n\"punktum\"-adressen."},
/* de */ {IDGS_MON_MEMSPRITE_DESCRIPTION_DE, "Zeige den Speicher als Sprite Daten. Wenn nur eine Adresse angegeben wurde,\nwird nur ein Sprite gezeitg. Wenn keine Adresse angegeben wurde, wird\ndie aktuelle Adresse verwendet."},
/* fr */ {IDGS_MON_MEMSPRITE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MEMSPRITE_DESCRIPTION_HU, "A memória tartalmának megjelenítése sprite adatkéne. Ha csak egy cím\nvan megadva, egyetlen sprite-ot mutat.  Ha egyáltalán nincs cím megadva,\naz aktuális címet használja."},
/* it */ {IDGS_MON_MEMSPRITE_DESCRIPTION_IT, "Mostra il contenuto della memoria come dati sprite. Se è specificato\nsolo un indirizzo, verrà mostrato solo uno sprite. Se non è specificato\nalcun indirizzo, varrà utilizzato l'indirizzo ``dot''."},
/* ko */ {IDGS_MON_MEMSPRITE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MEMSPRITE_DESCRIPTION_NL, "Toon de geheugen inhoud als sprite data. Als er maar een adres is opgegeven\ndan zal er maar een sprite worden getoond. Als er geen adres is opgegeven\ndan zal het huidige adres worden gebruikt."},
/* ru */ {IDGS_MON_MEMSPRITE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MEMSPRITE_DESCRIPTION_SV, "Visa minnets innehåll som spritedata. Om endast en adress\nanges, visas endast en sprite. Om ingen adress anges används\n\"punkt\"-adressen."},
/* tr */ {IDGS_MON_MEMSPRITE_DESCRIPTION_TR, "Bellek içeriðini yaratýk verisi olarak göster.  Yalnýzca bir adres\nbelirtilmiþse, yalnýzca tek yaratýk görüntülenir.  Eðer hiç adres\ngirilmemiþse, 'nokta' adresi kullanýlýr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MOVE_DESCRIPTION,    N_("Move memory from the source specified by the address range to\nthe destination specified by the address.  The regions may overlap.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MOVE_DESCRIPTION_DA, "Kopiér data fra kilden angivet af hukommelsesområdet til destinationen\nsom angives af adressen. Regionerne kan overlappe."},
/* de */ {IDGS_MON_MOVE_DESCRIPTION_DE, "Verschiebe Speicher von Startadresse definiert durch den Adressbereich zum\nZielbereich definiert durch die Adresse. Die Bereiche können überlappend sein."},
/* fr */ {IDGS_MON_MOVE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MOVE_DESCRIPTION_HU, "Memória másolása a forrás területrõl a cél cím által meghatározott\nterületre. A tartományok átfedése megengedett."},
/* it */ {IDGS_MON_MOVE_DESCRIPTION_IT, "Sposta la memoria dalla sorgente specificata dall'intervallo di indirizzi\nalla destinazione specificata dall'indirizzo. Le regioni possono\nsovrapporsi."},
/* ko */ {IDGS_MON_MOVE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MOVE_DESCRIPTION_NL, "Verplaats data van de opgegeven bron adres reeks naar het doel adres. De\nreeksen kunnen overlappen."},
/* ru */ {IDGS_MON_MOVE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MOVE_DESCRIPTION_SV, "Flytta minne från källadressen som anges av minnesområdet\ntill destinationen som anges av adressen. Regionerna kan vara\növerlappande."},
/* tr */ {IDGS_MON_MOVE_DESCRIPTION_TR, "Belleði belirtilmiþ kaynak adres aralýðýndan belirtilmiþ hedef\nadresine taþý.  Alanlar üst üste binebilir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_CHECKPOINT_COMMANDS,    N_("Checkpoint commands:")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CHECKPOINT_COMMANDS_DA, "Checkpoint-kommandoer:"},
/* de */ {IDGS_CHECKPOINT_COMMANDS_DE, "Checkpoint Kommandos:"},
/* fr */ {IDGS_CHECKPOINT_COMMANDS_FR, ""},  /* fuzzy */
/* hu */ {IDGS_CHECKPOINT_COMMANDS_HU, ""},  /* fuzzy */
/* it */ {IDGS_CHECKPOINT_COMMANDS_IT, "Comandi punti di controllo:"},
/* ko */ {IDGS_CHECKPOINT_COMMANDS_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CHECKPOINT_COMMANDS_NL, "Checkpunt commandos:"},
/* ru */ {IDGS_CHECKPOINT_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CHECKPOINT_COMMANDS_SV, "Kommandon för brytpunkter:"},
/* tr */ {IDGS_CHECKPOINT_COMMANDS_TR, "Kontrol Noktasý komutlarý:"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_COND_EXPR,    N_("cond_expr")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_COND_EXPR_DA, "betingelse"},
/* de */ {IDGS_COND_EXPR_DE, "bedingter Ausdruck"},
/* fr */ {IDGS_COND_EXPR_FR, ""},  /* fuzzy */
/* hu */ {IDGS_COND_EXPR_HU, ""},  /* fuzzy */
/* it */ {IDGS_COND_EXPR_IT, "espressione condizione"},
/* ko */ {IDGS_COND_EXPR_KO, ""},  /* fuzzy */
/* nl */ {IDGS_COND_EXPR_NL, "cond_expr"},
/* ru */ {IDGS_COND_EXPR_RU, ""},  /* fuzzy */
/* sv */ {IDGS_COND_EXPR_SV, "villkorsuttryck"},
/* tr */ {IDGS_COND_EXPR_TR, "koþul_idafesi"},
#endif

/*
   Translators: this command was extended:

   - "load|store|exec" option added

   TODO: update these languages: DA, DE, HU, IT, NL, SV, TR
*/

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BREAK_DESCRIPTION,    N_("Set a breakpoint, If no address is given, the currently valid break-\npoints are printed.\nIf an address is given, a breakpoint is set for that address and the\nbreakpoint number is printed.\n`load|store|exec' is either `load', `store' or `exec' (or any combina-\ntion of these) to specify on which operation the monitor breaks. If\nnot specified, the monitor breaks on `exec'.\nA conditional expression can also be specified for the breakpoint.\nFor more information on conditions, see the CONDITION command.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BREAK_DESCRIPTION_DA, "Hvis ingen adresse angives vises nuværende watchpoints. Hvis en\nadresse angives sættes et watchpoint på denne och watchpointets\nnummer vises. En betingelse kan også angives for et watchpoint.\nFor mere information om betingelser, se kommandoen CONDITION."},
/* de */ {IDGS_MON_BREAK_DESCRIPTION_DE, "Wenn keine Adresse angegeben wurde, werden die aktuellen watchpoints gezeigt.\nWenn eine Adresse angegebene wurde, wird ein breakpoint auf diese Adresse\ngesetzt und die breakpoint Nummer wird ausgegeben. Ein bedingter Ausdruck\ncan zu dem breakpoint zugeordnet werden. Für mehr Informations über \nbedingte Ausdrücke, bitte Kommando CONDITION ansehen."},
/* fr */ {IDGS_MON_BREAK_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BREAK_DESCRIPTION_HU, "Ha nincs cím megadva, az aktuálisan érvényes figyelési pontokat\nlistázza. Ha van cím a paraméterben, töréspontot helyez el az adott\ncímre, és a számát kiírja. Egy feltétel kifejezés is megadható a törésponthoz.\nA feltételekrõl több információhoz lásd a CONDITION parancs súgóját!"},
/* it */ {IDGS_MON_BREAK_DESCRIPTION_IT, "Se non viene specificato alcun indirizzo, i watchpoint attuali vengono\nstampati.Se viene specificato un indirizzo, viene impostato un breakpoint\nper tale indirizzo e viene stampato il suo numero. Può anche essere\nspecificata una condizione per il breakpoint. Per ulteriori informazioni,\nvedere il comando CONDITION."},
/* ko */ {IDGS_MON_BREAK_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BREAK_DESCRIPTION_NL, "Als er geen adres is opgegeven dan zullen de huidige geldige kijkpunten\ngeprint. Als er een adres is opgegeven dan zal er een breekpunt gezet worden\nvoor dat adres en de nummer van het breekpunt zal worden getoond. Een\nconditie kan worden opgegeven voor het breekpunt. Voor meer informatie over\ncondities zie het CONDITION commando."},
/* ru */ {IDGS_MON_BREAK_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BREAK_DESCRIPTION_SV, "Om ingen adress anges visas de övervakningspunkter som är giltiga.\nOm en adress anges sätts en brytpunkt på den adressen och dess\nnummer visas. Ett villkorsuttryck kan också anges för brytpunkten.\nFör mer information om villkor, se kommandot CONDITION."},
/* tr */ {IDGS_MON_BREAK_DESCRIPTION_TR, "Eðer adres girilmemiþse, geçerli mevcut izleme noktalarý yazdýrýlýr.\nEðer bir adres girilmiþse, o adres için bir kesme noktasý iþaretlenir\nve kesme noktasý sayýsý yazdýrýlýr.  Ayný zamanda kesme noktasý için bir\nkoþul ifadesi de belirtilebilir.  Koþullar ile ilgili daha çok bilgi almak\niçin, CONDITION komutuna bakabilirsiniz."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_COMMAND,    N_("Command")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_COMMAND_DA, ""},  /* fuzzy */
/* de */ {IDGS_COMMAND_DE, "Kommando"},
/* fr */ {IDGS_COMMAND_FR, ""},  /* fuzzy */
/* hu */ {IDGS_COMMAND_HU, ""},  /* fuzzy */
/* it */ {IDGS_COMMAND_IT, ""},  /* fuzzy */
/* ko */ {IDGS_COMMAND_KO, "¸í·É"},
/* nl */ {IDGS_COMMAND_NL, "Commando"},
/* ru */ {IDGS_COMMAND_RU, ""},  /* fuzzy */
/* sv */ {IDGS_COMMAND_SV, "Kommando"},
/* tr */ {IDGS_COMMAND_TR, ""},  /* fuzzy */
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_COMMAND_DESCRIPTION,    N_("Specify `command' as the command to execute when checkpoint `checknum'\nis hit.  Note that the `x' command is not yet supported as a\ncommand argument.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_COMMAND_DESCRIPTION_DA, "Angiv \"kommando\" som kommando der skal eksekveres når ckeckpoint\n\"checknum\" nås. Vær opmærksom på at kommandoen \"x\" endnu ikke\ner understøttet som parameter."},
/* de */ {IDGS_MON_COMMAND_DESCRIPTION_DE, "Definiere `Kommando', welches bei Checkpoint `Checknum' ausgeführt wird.\nAchtung Kommando `x' wird zurzeit noch nicht als Kommando Argument\nunterstützt."},
/* fr */ {IDGS_MON_COMMAND_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_COMMAND_DESCRIPTION_HU, "`parancs' megadása egy `ell_pont_szám' sorszámával adott ellenõrzési pont\nelérésekor történõ végrehajtásra.  Az `x' parancs egyelõre nem használható\nitt paraméterként."},
/* it */ {IDGS_MON_COMMAND_DESCRIPTION_IT, "Specifica `comando' come il comando da eseguire quando\nviene incontrato il punto di controllo `checknum'. Nota che \nil comando `x' non è ancora supportato come parametro."},
/* ko */ {IDGS_MON_COMMAND_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_COMMAND_DESCRIPTION_NL, "Geef `commando' als het command om uit te voeren wanneer checkpunt `checknum'\nwordt uitgevoerd. NB: het `x' commando is op dit moment geen geldige\nparameter."},
/* ru */ {IDGS_MON_COMMAND_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_COMMAND_DESCRIPTION_SV, "Ange \"kommando\" som kommando att exekvera när vid träff på\nkontrollpunkten·\"kontrollnr\". Observera att kommandot \"x\" ännu\ninte stöds som kommandoparameter."},
/* tr */ {IDGS_MON_COMMAND_DESCRIPTION_TR, "Kontrol noktasý `kontrolnumarasý'na ulaþýldýðýnda `komut' olarak\nçalýþtýrýlacak komutu belirt.  Henüz `x' komutunun bir komut argümaný\nolarak desteklenmediðini not edin."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_CONDITION_DESCRIPTION,    N_("Each time the specified checkpoint is examined, the condition is\nevaluated.  If it evalutes to true, the checkpoint is activated.\nOtherwise, it is ignored.  If registers are specified in the expression,\nthe values used are those at the time the checkpoint is examined, not\nwhen the condition is set.\nThe condition can make use of registers (.A, .X, .Y, .PC, .SP) and\ncompare them (==, !=, <, >, <=, >=) again other registers or constants.\nRegisters can be the registers of other devices; this is denoted by\na memspace prefix (i.e., c:, 8:, 9:, 10:, 11:\nExamples: .A == 0, .X == .Y, 8:.X == .X\n")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_CONDITION_DESCRIPTION_DA, "Betingelsen evalueres hver gang det angivne checkpoint undersøges.\nHvis evalueres til sand aktiveres checkpointet, allers ignoreres\ndet. Hvis betingelsen indeholder registre, anvendes de værdier,\nregistrene har når betingelsen evalueres, ikke når betingelsen\noprettes.\nBetingelsen kan anvende registrene (.A, .X, .Y, .PC, .SP) og\nsammenligne dem (==, !=, <, >, <=, >=) med andre registre eller\nkonstanter. Registre kan være i andre enheder, og dette angives\nsom et hukommelsesområdeprefix (dvs., c:, 8:, 9:, 10:, 11:)\nEksempel: .A == 0, .X == .Y, 8:.X == .X\n"},
/* de */ {IDGS_MON_CONDITION_DESCRIPTION_DE, "Bei jeder Überprüfung des Checkpoints, wird die Bedingung evaluiert.\nIst das Ergebnis `Wahr', wird der Checkpoint aktiviert, sonst ingnoriert.\nWenn Register benutzt werden, werden deren Werte zum Zeitpunkt der \nÜberprüfung herangezogen.\nDie Bedingung kann Register benutzen (.A, .X, .Y, .PC, .SP) und gegen \nRegister oder Konstanten vergleichen (==, !=, <, >, <=, >=).\nRegister können auch Geräteregister sein; dazu wird die memspace Prefix-syntax \nverwendet: c:, 8:, 9:, 10:, 11:\nBeispiel: .A == 0, .X == .Y, 8:.X == .X\n"},
/* fr */ {IDGS_MON_CONDITION_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_CONDITION_DESCRIPTION_HU, "Minden alkalommal, amikor egy adott ellenõrzési pontot megvizsgál, a\nfeltételt kiértékeli. Ha az eredmény igaz, a töréspont aktiválódik.\nEgyébként, figyelmen kívül hagyja. Ha regiszterek szerepelnek a kifejezésben,\naz ellenõrzés pillanatában vett értékük számít, nem pedig a beállításkori.\nA feltétel használhatja a regisztereket ( .A, .X, .Y, .PC, .SP) és össze is\nhasonlíthatja õket (==, !=, <, >, <=, >=) más regiszterekkel.\nA regiszterek lehetnek más eszközök regiszterei is; azokat egy memória tér\nelõtaggal kell ellátni (vagyis c:, 8:, 9:, 10:, 11:).\nPéldák: .A == 0, .X == .Y, 8:.X == .X\n"},
/* it */ {IDGS_MON_CONDITION_DESCRIPTION_IT, "Ogni volta che si esamina il punto di controllo specificato, viene valutata\nla condizione. Se è vera, il punto di controllo è attivato.\nAltrimenti viene ignorato. Se nell'espressione sono specificati i registri,\nquesti valori sono quelli usati quando viene esaminato il punto di controllo,\nnon quando viene impostata la condizione.\nLa condizione può fare uso dei registri (.A, .X, .Y, .PC, .SP) e confontarli\n(==, !=, <, >, <=, >=) con altri registri o costanti.\nI registri possono essere registri di altre periferiche; questo è denotato da\nun prefisso che specifica lo spazio di memoria (cioé, c:, 8:, 9:, 10:, 11:)\nAlcuni esempi: .A == 0, .X == .Y, 8:.X == .X\n"},
/* ko */ {IDGS_MON_CONDITION_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_CONDITION_DESCRIPTION_NL, "Elke keer de opgegeven checkpunt wordt onderzocht zal de conditie worden\ngeevalueerd. Als de evaluatie positief is dan zal de checkpunt geactiveerd\nworden, bij negatief zal er niets worden gedaan. Als er registers zijn\nopgegeven in de expressie dan zullen de waarden in die registers gebruikt\nworden op het moment dat de checkpunt wordt onderzocht, niet op het moment\ndat de conditie is opgegeven.\nDe conditie kan gebruik maken van registers (.A, .X, .Y, .PC, .SP) en\nkan ze vergelijken (==, !=, <, >, <=, >=) met andere registers of constanten\nRegisters kunnen de registers van andere apparaten zijn; de manier van opgeven\nis door een geheugenruimte prefix (bijvoorbeeld: c:, 8:, 9:, 10:, 11:\nVoorbeelden: .A == 0, .X == .Y, 8:.X == .X\n"},
/* ru */ {IDGS_MON_CONDITION_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_CONDITION_DESCRIPTION_SV, "Villkoret utvärderas varje gång den givna kontrollpunkten\nundersöks. Om det utvärderas till sant aktiveras kontrollpunkten.\nI annat fall ignoreras den. Om uttrycket innehåller register\nanvänds de värden de har då kontrollpunkten utvärderas, inte\nnär villkoret sattes.\nVillkoret kan använda register (.A, .X, .Y, .PC, .SP) och\njämföra dem (==, !=, <, >, <=, >=) mot andra register eller\nkonstanter. Register kan vara register i andra enheter, detta\nanges som ett minnesområdesprefix (dvs., c:, 8:, 9:, 10:, 11:)\nExempel: .A == 0, .X == .Y, 8:.X == .X\n"},
/* tr */ {IDGS_MON_CONDITION_DESCRIPTION_TR, "Her defasýnda belirtilmiþ bir kontrol noktasý incelendiðinde, koþul\ndeðerlendirilir.  Koþul doðru sonuç verirse, kontrol noktasý aktive edilir.\nAksi taktirde göz ardý edilir.  Eðer ifadede registerlar tanýmlanmýþsa,\nbu deðerler ifade tanýmlandýðýnda deðil kontrol noktasý incelendiðinde\nkullanýlýrlar.\nÝfadelerde (.A, .X, .Y, .PC, .SP) registerlarý kullanýlabilir ve\n(==, !=, <, >, <=, >=) opertatörleriyle diðer register ve sabit deðerlerle.\nkarþýlaþtýrýlabilirler. Registerlar baþka aygýtlarýn registerlarý da olabilir;\nbu bir bellek alaný ön ekiyle ifade edilir (yani, c:, 8:, 9:, 10:, 11:\nÖrnekler: .A == 0, .X == .Y, 8:.X == .X\n"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DISABLE_DESCRIPTION,    N_("Disable checkpoint `checknum'.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DISABLE_DESCRIPTION_DA, "Deaktivér checkpoint \"checknum\"."},
/* de */ {IDGS_MON_DISABLE_DESCRIPTION_DE, "Checkpoint `Checknum' deaktivieren."},
/* fr */ {IDGS_MON_DISABLE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DISABLE_DESCRIPTION_HU, "`ell_pont_szám' jelû ellenõrzési pont tiltása."},
/* it */ {IDGS_MON_DISABLE_DESCRIPTION_IT, "Disattiva il punto di controllo `checknum'."},
/* ko */ {IDGS_MON_DISABLE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DISABLE_DESCRIPTION_NL, "Checkpunt `checknum' uitschakelen."},
/* ru */ {IDGS_MON_DISABLE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DISABLE_DESCRIPTION_SV, "Inaktivera kontrollpunkt \"kontrollnr\"."},
/* tr */ {IDGS_MON_DISABLE_DESCRIPTION_TR, "Kontrol Noktasý `kontrolnumarasý'ný pasifleþtir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_ENABLE_DESCRIPTION,    N_("Enable checkpoint `checknum'.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_ENABLE_DESCRIPTION_DA, "Aktivér checkpoint \"checknum\"."},
/* de */ {IDGS_MON_ENABLE_DESCRIPTION_DE, "Checkpoint `Checknum' aktivieren."},
/* fr */ {IDGS_MON_ENABLE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_ENABLE_DESCRIPTION_HU, "`ell_pont_szám' jelû ellenõrzési pont engedélyezése."},
/* it */ {IDGS_MON_ENABLE_DESCRIPTION_IT, "Attiva il punto di controllo `checknum'."},
/* ko */ {IDGS_MON_ENABLE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_ENABLE_DESCRIPTION_NL, "Activeer checkpunt `checknum'."},
/* ru */ {IDGS_MON_ENABLE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_ENABLE_DESCRIPTION_SV, "Aktivera kontrollpunkt \"kontrollnr\"."},
/* tr */ {IDGS_MON_ENABLE_DESCRIPTION_TR, "Kontrol Noktasý `kontrolnumarasý'ný aktif et."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_IGNORE_DESCRIPTION,    N_("Ignore a checkpoint a given number of crossings.  If no count is given,\nthe default value is 1.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_IGNORE_DESCRIPTION_DA, "Ignorér et checkpoint det angivne antal gange. Hvis antal ikke angives\nbruges standardværdien 1."},
/* de */ {IDGS_MON_IGNORE_DESCRIPTION_DE, "Ignoriere den Checkpoint für die angegebene Anzahl an Aktivierungen.\nWenn kein `Zähler' angegeben wurde, wird der Standardwert 1 verwendet."},
/* fr */ {IDGS_MON_IGNORE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_IGNORE_DESCRIPTION_HU, "Az ellenõrzési pont figyelmen kívül hagyása megadott számú áthaladáskor.  Ha nincs\nszám megadva, az alapértelmezett érték 1."},
/* it */ {IDGS_MON_IGNORE_DESCRIPTION_IT, "Ignora un punto di controllo un numero specificato di occorrenze. Se\nnon è specificato alcun valore, quello predefinito è 1."},
/* ko */ {IDGS_MON_IGNORE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_IGNORE_DESCRIPTION_NL, "Negeer een checkpunt een opgegeven aantal keer. Als er geen aantal is\nopgegeven dan wordt de standaard waarde van 1 worden gebruikt."},
/* ru */ {IDGS_MON_IGNORE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_IGNORE_DESCRIPTION_SV, "Ignorera en kontrollpunkt det givna antalet gånger. Om inget antal ges\när standardvärdet 1."},
/* tr */ {IDGS_MON_IGNORE_DESCRIPTION_TR, "Bir kontrol noktasýný verilen adette geçiþ için yoksay.  Eðer adet verilmemiþse,\nvarsayýlan deðer 1'dir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_UNTIL_DESCRIPTION,    N_("If no address is given, the currently valid breakpoints are printed.\nIf an address is given, a temporary breakpoint is set for that address\nand the breakpoint number is printed.  Control is returned to the\nemulator by this command.  The breakpoint is deleted once it is hit.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_UNTIL_DESCRIPTION_DA, "Hvis ingen adresse angives vises de aktuelle breakpoints. Hvis en\nadresse angives sættes et midlertidigt breakpoint, og nummeret på\nbreakpointet vises. Kontrollen returneres til emulatoren af denne\nkommando. Breakpointet fjernes når det nås."},
/* de */ {IDGS_MON_UNTIL_DESCRIPTION_DE, "Wenn keine Adresse angegeben wurde, werden die aktuell gültigen \nBreakpoints angezeigt. Wenn eine Adresse angegeben wurde, wird ein \ntemporärer Breakpoint auf dieser Adresse gesetzt und die Breakpoint Nummer wird\nangezeigt. Die Kontrolle wirdd bei diesem Kommando an die Emulation gegeben.\nDer Breakpoint wird gelöscht, wenn er einmal getroffen wurde."},
/* fr */ {IDGS_MON_UNTIL_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_UNTIL_DESCRIPTION_HU, "Ha nincs cím megadva, a jelenleg érvényes töréspontokat írja ki.\nHa van adott cím, egy ideiglenes töréspontot helyez el az adott címre,\nés a töréspont száma kiíródik.  A vezérlés visszakerül az emulátorhoz\ne parancs által. A töréspont elérésekor törlõdik."},
/* it */ {IDGS_MON_UNTIL_DESCRIPTION_IT, "Se non viene specificato alcun indirizzo, vengono stampati i\nbreakpoint attualmente validi. Se viene specificato un indirizzo,\nviene impostato un breakpoint temporaneo per tale indirizzo e\nviene stampato il suo numero. Il controllo ritorna all'emulatore\nper mezzo di questo comando. Il breakpoint è cancellato quando\nviene incontrato."},
/* ko */ {IDGS_MON_UNTIL_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_UNTIL_DESCRIPTION_NL, "Als er geen adres is opgegeven dan zullen de huidig geldige breekpunten\nworden geprint. Als er een adres is opgegeven dan wordt er een tijdelijk\nbreekpunt worden gezet voor dat adres en het breekpunt nummer zal worden\ngetoond. Na het geven van dit commando zal er terug worden gegaan naar de\nemulator. Het breekpunt zal worden verwijdert na het uitvoeren."},
/* ru */ {IDGS_MON_UNTIL_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_UNTIL_DESCRIPTION_SV, "Om du inte anger någon adress visas de för närvarande giltiga\nbrytpunkterna. Om en adress anges sätts en temporär brytpunkt för\nden adressen och numret på den nya brytpunkten visas. Styrningen\nåterlämnas till emulatorn för det här kommandot. Brytpunkten\ntas bort när den har nåtts."},
/* tr */ {IDGS_MON_UNTIL_DESCRIPTION_TR, "Eðer adres girilmemiþse, geçerli mevcut kesme noktalarý yazdýrýlýr.\nEðer bir adres girilmiþse, o adres için geçici bir kesme noktasý\niþaretlenir ve kesme noktasý sayýsý yazdýrýlýr.  Kontrol bu komutla\nemülatöre döndürülür.  Bir kere eriþildiði zaman kesme noktasý silinir."},
#endif

/*
   Translators: this is part of an actual command and should not get translated
*/

/* monitor/mon_command.c */
/* en */ {IDGS_LOADSTORE,    N_("load|store|exec")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_LOADSTORE_DA, "load|store|exec"},
/* de */ {IDGS_LOADSTORE_DE, "load|store|exec"},
/* fr */ {IDGS_LOADSTORE_FR, "load|store|exec"},
/* hu */ {IDGS_LOADSTORE_HU, "load|store|exec"},
/* it */ {IDGS_LOADSTORE_IT, "load|store|exec"},
/* ko */ {IDGS_LOADSTORE_KO, "load|store|exec"},
/* nl */ {IDGS_LOADSTORE_NL, "load|store|exec"},
/* ru */ {IDGS_LOADSTORE_RU, "load|store|exec"},
/* sv */ {IDGS_LOADSTORE_SV, "load|store|exec"},
/* tr */ {IDGS_LOADSTORE_TR, "load|store|exec"},
#endif

/*
   Translators: this command was extended:

   - "loadstore" option is now "load|store|exec"
   - conditional expression was added

   TODO: update these languages: DA, DE, HU, IT, NL, SV, TR
*/

/* monitor/mon_command.c */
/* en */ {IDGS_MON_WATCH_DESCRIPTION,    N_("Set a watchpoint. If no address is given, the currently valid watch-\npoints are printed. If a single address is specified, set a watchpoint\nfor that address.  If two addresses are specified, set a watchpoint\nfor the memory locations between the two addresses.\n`load|store|exec' is either `load', `store' or `exec' (or any combina-\ntion of these) to specify on which operation the monitor breaks. If\nnot specified, the monitor breaks on `load' and `store'.\n")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_WATCH_DESCRIPTION_DA, "Sæt et watchpoint. Hvis der angives en enkelt adresse sættes et\nwatchpoint for adressen. Hvis der angives to adresser sættes et\nwatchpoint for hukommelsesområdet mellem adresserne.\n\"loadstore\" er enten \"load\" eller \"store\" og angiver hvilken\noperation emulatoren skal stoppe ved. Hvis loadstore ikke angives\nstopper emulatoren på begge operationer."},
/* de */ {IDGS_MON_WATCH_DESCRIPTION_DE, "Setze einen Watchpoint. Wenn eine einzelne Adresse angegeben wurde, setze \nden Watchpoint für diese Adresse. Wenn zwei Adressen angegeben wurden, \nsetze den Watchpoint auf die Adressen zwischen den beiden Adressen.\n`loadstore' ist entweder `load' oder `store' und bezeichnet die Operation, \nbei welcher der Monitor anhalten soll. Wenn keine Angabe gemacht wurde, \nhält der Monitor bei beiden Operationen an."},
/* fr */ {IDGS_MON_WATCH_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_WATCH_DESCRIPTION_HU, "Figyelési pont megadása.  Ha egy cím van a paraméterben, az adott\ncímre állítbe figyelési pontot. Ha két cím adott, akkor a kettõ közötti\nösszes memória helyre beállítja.\nA `loadstore' vagy `load' vagy `store' lehet, azt adja meg, hogy olvasás\nvagy írás hatására áll meg a monitor program. Ha nincs megadva,\nmindkét mûvelet hatására megáll."},
/* it */ {IDGS_MON_WATCH_DESCRIPTION_IT, "Imposta un watchpoint. Se viene specificato solo un indirizzo, imposta\nun watchpoint per tale indirizzo. Se vengono specificati due indirizzi,\nimposta un watchpoint per le locazioni di memoria comprese tra i due\nindirizzi.\n`loadstore' può essere `load' o `store' per specificare su quale\noperazione il monitor si interrompe. Se non viene specificato, il monitor\nsi interrompe su entrambe le operazioni."},
/* ko */ {IDGS_MON_WATCH_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_WATCH_DESCRIPTION_NL, "Zet een kijkpunt. Als er een enkel adres is opgegeven dan zal er een\nkijkpunt worden gezet voor dat adres. Als er twee adressen zijn opgegeven\ndan zal er een kijkpunt worden gezet voor de adressen tussen de twee\nadressen.\nlaad/opslaan is 'load' of 'store' om aan te geven bij welke operatie de\nmonitor zou moeten starten. Als deze niet opgegeven is dan zal de monitor\nstarten bij beide operaties."},
/* ru */ {IDGS_MON_WATCH_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_WATCH_DESCRIPTION_SV, "Sätt en övervakningspunkt. Om du anger en ensam adress sätts en\növervakningspunkt för adressen. Om två adresser anges sätts en\növervakningspunkt för minnesområdet mellan adresserna.\n\"loadstore\" är antingen \"load\" eller \"store\" och anger vilken\noperation emulatorn skall stoppa för. Om den inte anges stoppar\nemulatorn på bägge operationerna."},
/* tr */ {IDGS_MON_WATCH_DESCRIPTION_TR, "Bir izleme noktasý koy.  Eðer tek bir adres belirtilmiþse, izleme\nnoktasýný o adrese koy.  Eðer iki adres belirtilmiþse, izleme noktasýný\no iki adres arasýnda kalan adreslere koy.\n`yükle/depola' monitörün kesildiði operatöre baðlý olarak `yükle' ya da\n`depola' iþlemlerinde çalýþabilir. Eðer belirtilmemiþse, her iki iþlemde de\nmonitör kesilecektir."},
#endif

/*
   Translators: this command was extended:

   - "load|store|exec" option added
   - conditional expression was added

   TODO: update these languages: DA, DE, HU, IT, NL, SV, TR
*/

/* monitor/mon_command.c */
/* en */ {IDGS_MON_TRACE_DESCRIPTION,    N_("Set a tracepoint. If no address is given, the currently valid trace-\npoints are printed. If a single address is specified, set a tracepoint\nfor that address.  If two addresses are specified, set a tracepoint\nfor the memory locations between the two addresses.\n`load|store|exec' is either `load', `store' or `exec' (or any combina-\ntion of these) to specify on which operation the monitor breaks. If\nnot specified, the monitor traces all three operations.\n")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_TRACE_DESCRIPTION_DA, "Sæt et tracepoint. Hvis der angives en enkelt adresse sættes et\ntracepoint for adressen. Hvis der angives to adresser sættes et\ntracepoint for hukommelsesområdet mellem adresserne."},
/* de */ {IDGS_MON_TRACE_DESCRIPTION_DE, "Setze einen Tracepoint. Wenn eine einzelne Adresse angegeben wurde, setze eine\nTracepoint für diese Adresse. Wenn zwei Adressen angegeben wurden, \nsetze Tracepoints für die Speicheradressen zwischen diesen beiden Adressen."},
/* fr */ {IDGS_MON_TRACE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_TRACE_DESCRIPTION_HU, "Követési pont beállítása.  Ha egyetlen cím van megadva, a követési pontot\nahhoz állítja be.  Ha két cím van megadva, a követési pontot\naz adott tartományra állítja be."},
/* it */ {IDGS_MON_TRACE_DESCRIPTION_IT, "Imposta un tracepoint. Se viene specificato solo un indirizzo, imposta\nun tracepoint per tale indirizzo. Se vengono specificati due indirizzi,\nimposta un tracepoint per le locazioni di memoria comprese tra i\ndue indirizzi."},
/* ko */ {IDGS_MON_TRACE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_TRACE_DESCRIPTION_NL, "Zet een traceerpunt. Als er een enkel adres is opgegeven dan zal er een\ntraceerpunt worden gezet voor het adres. Als er twee adressen zijn\nopgegeven dan zal er een traceerpunt worden gezet voor de adressen tussen\nde twee adressen."},
/* ru */ {IDGS_MON_TRACE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_TRACE_DESCRIPTION_SV, "Sätt en spårningspunkt. Om du anger en ensam adress sätts en\nspårningspunkt för adressen. Om två adresser anges sätts en\nspårningspunkt för minnesområdet mellan adresserna."},
/* tr */ {IDGS_MON_TRACE_DESCRIPTION_TR, "Takip noktasý koy.  Eðer tek bir adres belirtilmiþse, takip nokasýný\no adrese koy.  Eðer iki adres belirtilmiþse, izleme noktasýný\no iki adres arasýnda kalan adreslere koy."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MONITOR_STATE_COMMANDS,    N_("Monitor state commands:")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MONITOR_STATE_COMMANDS_DA, "Monitorstatuskommandoer:"},
/* de */ {IDGS_MONITOR_STATE_COMMANDS_DE, "Monitor Zustand Kommandos:"},
/* fr */ {IDGS_MONITOR_STATE_COMMANDS_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MONITOR_STATE_COMMANDS_HU, ""},  /* fuzzy */
/* it */ {IDGS_MONITOR_STATE_COMMANDS_IT, "Comandi stato monitor:"},
/* ko */ {IDGS_MONITOR_STATE_COMMANDS_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MONITOR_STATE_COMMANDS_NL, "Monitor status commandos:"},
/* ru */ {IDGS_MONITOR_STATE_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MONITOR_STATE_COMMANDS_SV, "Kommandon för monitorstatus:"},
/* tr */ {IDGS_MONITOR_STATE_COMMANDS_TR, "Monitör durum komutlarý:"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DEVICE_DESCRIPTION,    N_("Set the default memory device to either the computer `c:' or the\nspecified disk drive (`8:', `9:').")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DEVICE_DESCRIPTION_DA, "Sæt det valgte hukommelses område til enten computeren \"c:\" eller\ndet angivne diskettedrev (\"8:\", \"9:\")."},
/* de */ {IDGS_MON_DEVICE_DESCRIPTION_DE, "Setze das aktuelle Speichergerät entweder auf `c:' \noder das angegebene Laufwerk (`8:', `9:')."},
/* fr */ {IDGS_MON_DEVICE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DEVICE_DESCRIPTION_HU, "Az alapértelmezett memória eszköz beállítása a számítógépre `c:' vagy\na megadott lemezmeghajtóra (`8:', `9:')."},
/* it */ {IDGS_MON_DEVICE_DESCRIPTION_IT, "Imposta la periferica di memoria predefinita o sul computer `c:'\noppure sul disk drive specificato (`8:', `9:')."},
/* ko */ {IDGS_MON_DEVICE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DEVICE_DESCRIPTION_NL, "Zet de standaard geheugen apparaat naar of de computer `c:' of de\nopgegeven disk drive (`8:', `9:')."},
/* ru */ {IDGS_MON_DEVICE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DEVICE_DESCRIPTION_SV, "Sätt förvald minnesenhet antingen till datorn \"c:\" eller\nden angivna diskettenheten (\"8:\", \"9:\")."},
/* tr */ {IDGS_MON_DEVICE_DESCRIPTION_TR, "Varsayýlan bellek aygýtýný bilgisayar `c:' ya da (`8:', `9:') ile\nbelirtilmiþ disket dürücü olarak belirle."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_EXIT_DESCRIPTION,    N_("Leave the monitor and return to execution.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_EXIT_DESCRIPTION_DA, "Forlad monitoren og gå tilbage til eksekvering."},
/* de */ {IDGS_MON_EXIT_DESCRIPTION_DE, "Verlasse Monitor und setze Ausführung fort."},
/* fr */ {IDGS_MON_EXIT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_EXIT_DESCRIPTION_HU, "A monitor elhagyása és a végrehajtás folytatása."},
/* it */ {IDGS_MON_EXIT_DESCRIPTION_IT, "Esce dal monitor e ritorna all'esecuzione."},
/* ko */ {IDGS_MON_EXIT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_EXIT_DESCRIPTION_NL, "Verlaat de monitor en ga terug naar de uitvoering."},
/* ru */ {IDGS_MON_EXIT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_EXIT_DESCRIPTION_SV, "Lämna monitorn och återgå till programkörningen."},
/* tr */ {IDGS_MON_EXIT_DESCRIPTION_TR, "Monitörü terk et ve çalýþtýrmaya geri dön."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_QUIT_DESCRIPTION,    N_("Exit the emulator immediately.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_QUIT_DESCRIPTION_DA, "Afslut emulatoren øjblikkeligt."},
/* de */ {IDGS_MON_QUIT_DESCRIPTION_DE, "Emulator sofort beenden."},
/* fr */ {IDGS_MON_QUIT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_QUIT_DESCRIPTION_HU, "Azonnali kilépés az emulátorból."},
/* it */ {IDGS_MON_QUIT_DESCRIPTION_IT, "Esci immediatamente dall'emulatore."},
/* ko */ {IDGS_MON_QUIT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_QUIT_DESCRIPTION_NL, "Onmiddelijk de emulator afsluiten."},
/* ru */ {IDGS_MON_QUIT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_QUIT_DESCRIPTION_SV, "Avsluta emulatorn omedelbart."},
/* tr */ {IDGS_MON_QUIT_DESCRIPTION_TR, "Emülasyondan derhal çýk."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_RADIX_DESCRIPTION,    N_("Set the default radix to hex, decimal, octal, or binary.  With no\nargument, the current radix is printed.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_RADIX_DESCRIPTION_DA, "Sæt standardradix til hex, decimal, oktal eller binær. Hvis der\nikke angives et argument vises det aktuelle radix."},
/* de */ {IDGS_MON_RADIX_DESCRIPTION_DE, "Setze die Standardzahlenbasis auf Hexadezimal, Dezimal, Oktal oder Binär.\nBei keinem Argument wird die akteulle Zahlenbasis ausgegeben."},
/* fr */ {IDGS_MON_RADIX_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_RADIX_DESCRIPTION_HU, "Az alap számrendszer hexadecimális, decimális, oktális vagy bináris.\nParaméter nélkül az aktuálisat mutatja."},
/* it */ {IDGS_MON_RADIX_DESCRIPTION_IT, "Imposta la radice predefinita a esadecimale, decimale, ottale o\nbinaria. Senza parametro viene stampata la radice attuale."},
/* ko */ {IDGS_MON_RADIX_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_RADIX_DESCRIPTION_NL, "Zet de standaard radix naar hex, decimaal, octaal of binair. Als er\ngeen parameter is opgegeven dan zal de huidige radix worden getoond."},
/* ru */ {IDGS_MON_RADIX_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_RADIX_DESCRIPTION_SV, "Sätt standardradix till hex, decimal, oktal eller binär. Om du\ninte ger något argument visas nuvarande radix."},
/* tr */ {IDGS_MON_RADIX_DESCRIPTION_TR, "Varsayýlan sayý tabanýný 16'lý, 10'lu, 8'li ya da 2'li yap.\nArgümansýz olarak geçerli sayý tabaný yazdýrýlýr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_SIDEFX_DESCRIPTION,    N_("Control how monitor generated reads affect memory locations that have\nread side-effects.  If the argument is 'on' then reads may cause\nside-effects.  If the argument is 'off' then reads don't cause\nside-effects.  If the argument is 'toggle' then the current mode is\nswitched.  No argument displays the current state.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_SIDEFX_DESCRIPTION_DA, "Bestemmer hvordan læsninger i monitoren påvirker hukommelsesområder,\nder har sedeeffekter ved læsning. Hvis argumentet er \"on\" kan læsninger\nforesage sideeffekter. Hvis argumentet er \"off\" vil læsninger ikke\nforesage sideeffekter. Hvis argumentet er \"toggle\" skiftes\nden nuværende tilstand. Hvis der ikke angives noget argument vises\nden nuværende tilstand."},
/* de */ {IDGS_MON_SIDEFX_DESCRIPTION_DE, "Steuerung, wie die vom Monitor erzeugten Lesezugriffe die Speicherzellen\nmit Lese-Seiteneffekten betreffen.\nBei Argument \"on\" werden Lese-Seiteneffekte erzeugt.\nBei Argument \"off\" werden keine Lese-Seiteneffekte erzeugt.\nBei Argumenrt \"toggle\" wird das Verhalten vertauscht.\nBei keinem Argument wird das aktuelle Verhalten ausgegebene."},
/* fr */ {IDGS_MON_SIDEFX_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_SIDEFX_DESCRIPTION_HU, "Beállítja, hogyan hatnak a monitorprogram memória olvasásai azokra a\nmemóriahelyekre, amelyeknek olvasás-mellékhatásai vannak. Ha a paraméter\n'on', az olvasások okozhatnak mellékhatásokat. Ha a paraméter 'off', akkor pedig\nnem okoznak. Ha a paraméter 'toggle', az aktuális módot átkapcsolja.\nParaméter nélküli hívás kiírja az aktuális módot."},
/* it */ {IDGS_MON_SIDEFX_DESCRIPTION_IT, "Controlla come le letture generate dal monitor affliggono le locazioni\ndi memoria che hanno degli effetti collaterali sulla lettura.\nSe il paremetro è 'on', le letture possono causare effetti collaterali.\nSe il parametro è 'off', le letture non causano effetti collaterali.\nSe il parametro è 'scambia', la modalità attuale viene invertita.\nNessun parametro mostra lo stato attuale."},
/* ko */ {IDGS_MON_SIDEFX_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_SIDEFX_DESCRIPTION_NL, "Geef aan hoe de lees acties van de monitor de geheugen locaties met lees\nbij-effecten beinvloed. Als de parameter 'off' is dan zullen lees acties\ngeen bij-effecten vertonen. Als de parameter 'on' is dan zullen lees\nacties bij-effecten vertonen. Als de parameter 'toggle' is dan zal de\nhuidige modus worden geschakeld. Als er geen parameter is dan zal de\nhuidige modus worden getoond."},
/* ru */ {IDGS_MON_SIDEFX_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_SIDEFX_DESCRIPTION_SV, "Styr hur läsningar i monitorn påverkar minnesområden som har\nsidoeffekter vid läsning. Om argumentet är \"on\" tillåts läsningar\natt orsaka sidoeffekter. Om argumentet är \"off\" tillåts inte\nläsningar att orsaka sidoeffekter. Om argumentet är \"toggle\" byts\ndet nuvarande läget. Om du inte anger några argument visas\nnuvarande läge."},
/* tr */ {IDGS_MON_SIDEFX_DESCRIPTION_TR, "Okuma yan etkileri bulunan bellek konumlarýný monitör tarafýndan oluþturulan\nokumalarýn nasýl etkilediðini kontrol et.  Argüman 'on' ise, okumalar yan\netkiye neden olabilir.  Argüman 'off' ise okumalarýn bir yan etkisi\nolmayacaktýr.  Eðer argüman 'toggle' ise geçerli mod deðiþtirilecektir.\nArgüman verilmemesi o anki durumu görüntüler."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_DISK_COMMANDS,    N_("Disk commands:")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_DISK_COMMANDS_DA, "Diskettekommandoer:"},
/* de */ {IDGS_DISK_COMMANDS_DE, "Disk Kommandos:"},
/* fr */ {IDGS_DISK_COMMANDS_FR, ""},  /* fuzzy */
/* hu */ {IDGS_DISK_COMMANDS_HU, ""},  /* fuzzy */
/* it */ {IDGS_DISK_COMMANDS_IT, "Comandi disco:"},
/* ko */ {IDGS_DISK_COMMANDS_KO, ""},  /* fuzzy */
/* nl */ {IDGS_DISK_COMMANDS_NL, "Disk commandos:"},
/* ru */ {IDGS_DISK_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DISK_COMMANDS_SV, "Diskettkommandon:"},
/* tr */ {IDGS_DISK_COMMANDS_TR, "Disk komutlarý:"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_DISK_COMMAND,    N_("disk command")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_DISK_COMMAND_DA, "diskkommando"},
/* de */ {IDGS_DISK_COMMAND_DE, "Disk Kommando"},
/* fr */ {IDGS_DISK_COMMAND_FR, ""},  /* fuzzy */
/* hu */ {IDGS_DISK_COMMAND_HU, ""},  /* fuzzy */
/* it */ {IDGS_DISK_COMMAND_IT, "comando disco"},
/* ko */ {IDGS_DISK_COMMAND_KO, ""},  /* fuzzy */
/* nl */ {IDGS_DISK_COMMAND_NL, "disk commando"},
/* ru */ {IDGS_DISK_COMMAND_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DISK_COMMAND_SV, "diskkommando"},
/* tr */ {IDGS_DISK_COMMAND_TR, "disk komutu"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_AT_DESCRIPTION,    N_("Perform a disk command on the currently attached disk image on drive 8.\nThe specified disk command is sent to the drive's channel #15.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_AT_DESCRIPTION_DA, "Udfører en diskkommando på det diskette-image, der er tilsluttet\ndrev 8. Diskkommandoen sendes til drevets kanal #15."},
/* de */ {IDGS_MON_AT_DESCRIPTION_DE, "Führe ein Diskkommando auf dem aktuell eingelegtem Diskimage auf Laufwerk 8\naus.\nDas angegebene Kommando wird auf dem Laufwerks Kommandokanal #15 geschickt."},
/* fr */ {IDGS_MON_AT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_AT_DESCRIPTION_HU, "Lemez parancs végrehajtása az aktuálisan csatolt lemezen, a 8-as egységen.\nA megadott lemez parancsot a meghajtó #15-ös csatornájára küldi."},
/* it */ {IDGS_MON_AT_DESCRIPTION_IT, "Esegue un comando disco sull'immagine disco attualmente presente nel\ndrive 8. Il comando specificato è inviato al canale #15 del drive."},
/* ko */ {IDGS_MON_AT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_AT_DESCRIPTION_NL, "Doe een disk commando operatie op de huidig gekoppelde disk bestand in drive\n8, Het opgegeven disk commando zal worden gestuurt naar kanaal #15 van de\ndrive."},
/* ru */ {IDGS_MON_AT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_AT_DESCRIPTION_SV, "Utför ett diskkommando på den diskettavbildning som är ansluten till\nenhet 8. Diskkommandot sänds på diskettenhetens kanal nummer 15."},
/* tr */ {IDGS_MON_AT_DESCRIPTION_TR, "8 nolu sürücüde takýlý disk imajý üzerinde bir disk komutu çalýþtýr.\nBelirtilen disk komutu sürücünün 15 numaralý kanalýna gönderilir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_DEVICE,    N_("device")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_DEVICE_DA, "enhed"},
/* de */ {IDGS_DEVICE_DE, "Gerät"},
/* fr */ {IDGS_DEVICE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_DEVICE_HU, ""},  /* fuzzy */
/* it */ {IDGS_DEVICE_IT, "dispositivo"},
/* ko */ {IDGS_DEVICE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_DEVICE_NL, "apparaat"},
/* ru */ {IDGS_DEVICE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DEVICE_SV, "enhet"},
/* tr */ {IDGS_DEVICE_TR, "aygýt"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_FILE_INDEX,    N_("file_index")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_FILE_INDEX_DA, ""},  /* fuzzy */
/* de */ {IDGS_FILE_INDEX_DE, "Datei_Index"},
/* fr */ {IDGS_FILE_INDEX_FR, ""},  /* fuzzy */
/* hu */ {IDGS_FILE_INDEX_HU, ""},  /* fuzzy */
/* it */ {IDGS_FILE_INDEX_IT, ""},  /* fuzzy */
/* ko */ {IDGS_FILE_INDEX_KO, ""},  /* fuzzy */
/* nl */ {IDGS_FILE_INDEX_NL, "bestandsindex"},
/* ru */ {IDGS_FILE_INDEX_RU, ""},  /* fuzzy */
/* sv */ {IDGS_FILE_INDEX_SV, "filindex"},
/* tr */ {IDGS_FILE_INDEX_TR, ""},  /* fuzzy */
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_AUTOSTART_DESCRIPTION,    N_("autostart a given disk/tape image or program")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_AUTOSTART_DESCRIPTION_DA, ""},  /* fuzzy */
/* de */ {IDGS_MON_AUTOSTART_DESCRIPTION_DE, "Autostart ein Disk/Band Image oder Programm"},
/* fr */ {IDGS_MON_AUTOSTART_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_AUTOSTART_DESCRIPTION_HU, ""},  /* fuzzy */
/* it */ {IDGS_MON_AUTOSTART_DESCRIPTION_IT, ""},  /* fuzzy */
/* ko */ {IDGS_MON_AUTOSTART_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_AUTOSTART_DESCRIPTION_NL, "autostart een opgegeven disk-/tapebestand of programma"},
/* ru */ {IDGS_MON_AUTOSTART_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_AUTOSTART_DESCRIPTION_SV, "starta given disk-/bandavbildningsfil eller program automatiskt"},
/* tr */ {IDGS_MON_AUTOSTART_DESCRIPTION_TR, ""},  /* fuzzy */
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_AUTOLOAD_DESCRIPTION,    N_("autoload given disk/tape image or program")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_AUTOLOAD_DESCRIPTION_DA, ""},  /* fuzzy */
/* de */ {IDGS_MON_AUTOLOAD_DESCRIPTION_DE, "Autoload ein Disk/Band Image oder Programm"},
/* fr */ {IDGS_MON_AUTOLOAD_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_AUTOLOAD_DESCRIPTION_HU, ""},  /* fuzzy */
/* it */ {IDGS_MON_AUTOLOAD_DESCRIPTION_IT, ""},  /* fuzzy */
/* ko */ {IDGS_MON_AUTOLOAD_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_AUTOLOAD_DESCRIPTION_NL, "autolaad een opgegeven disk-/tapebestand of programma"},
/* ru */ {IDGS_MON_AUTOLOAD_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_AUTOLOAD_DESCRIPTION_SV, "läs in given disk-/bandavbildningsfil eller program automatiskt"},
/* tr */ {IDGS_MON_AUTOLOAD_DESCRIPTION_TR, ""},  /* fuzzy */
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_ATTACH_DESCRIPTION,    N_("Attach file to device. (device 32 = cart)")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_ATTACH_DESCRIPTION_DA, "Tilslut en fil til enhed. (enhed 32 = cartridge)"},
/* de */ {IDGS_MON_ATTACH_DESCRIPTION_DE, "Benutze Datei für das Gerät. (Gerät 32 = Modul)"},
/* fr */ {IDGS_MON_ATTACH_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_ATTACH_DESCRIPTION_HU, "Fájl csatolása az eszközhöz. (32-es eszköz = cart)"},
/* it */ {IDGS_MON_ATTACH_DESCRIPTION_IT, "Seleziona il file per la perifica. (periferica 32 = cartuccia)"},
/* ko */ {IDGS_MON_ATTACH_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_ATTACH_DESCRIPTION_NL, "Koppel bestand aan apparaat. (apparaat 32 = cart"},
/* ru */ {IDGS_MON_ATTACH_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_ATTACH_DESCRIPTION_SV, "Anslut en fil till en enhet. (enhet 32 = insticksmodul)"},
/* tr */ {IDGS_MON_ATTACH_DESCRIPTION_TR, "Aygýta dosya yerleþtir. (aygýt 32 = kartuþ)"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BLOAD_DESCRIPTION,    N_("Load the specified file into memory at the specified address.\nIf device is 0, the file is read from the file system.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BLOAD_DESCRIPTION_DA, "Indlæs den angivne fil til hukommelsen på den angivne adresse.\nHvis enhed er 0 læses fra filsystemet."},
/* de */ {IDGS_MON_BLOAD_DESCRIPTION_DE, "Lade angegebene Datei in den Speicher an die angegebene Adresse.\nBei Gerät 0, wird die Datei vom Dateisystem gelesen."},
/* fr */ {IDGS_MON_BLOAD_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BLOAD_DESCRIPTION_HU, "A megadott fájl betöltése a memóriába a megadott címre.\nHa az eszköz 0, a fájlt a fájlrendszerbõl olvassa."},
/* it */ {IDGS_MON_BLOAD_DESCRIPTION_IT, "Carica il file specificato in memoria all'indirizzo specificato.\nSe la periferica è 0, il file è letto dal file system."},
/* ko */ {IDGS_MON_BLOAD_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BLOAD_DESCRIPTION_NL, "Laad het opgegeven bestand naar het geheugen met het opgegeven adres.\nAls het apparaat 0 is dan zal het bestand van het bestandssysteem\nworden geladen."},
/* ru */ {IDGS_MON_BLOAD_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BLOAD_DESCRIPTION_SV, "Läs den angivna filen till minnet på den angivna adressen.\nOm enheten är 0 läses filen från filsystemet."},
/* tr */ {IDGS_MON_BLOAD_DESCRIPTION_TR, "Belirtilmiþ dosyayý belirtilen adresten itibaren belleðe yükle.\nAygýt 0 ise, dosya dosya sistemi üzerinden okunur."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_TRACK,    N_("track")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_TRACK_DA, "spor"},
/* de */ {IDGS_TRACK_DE, "Spur"},
/* fr */ {IDGS_TRACK_FR, ""},  /* fuzzy */
/* hu */ {IDGS_TRACK_HU, ""},  /* fuzzy */
/* it */ {IDGS_TRACK_IT, "traccia"},
/* ko */ {IDGS_TRACK_KO, ""},  /* fuzzy */
/* nl */ {IDGS_TRACK_NL, "spoor"},
/* ru */ {IDGS_TRACK_RU, ""},  /* fuzzy */
/* sv */ {IDGS_TRACK_SV, "spår"},
/* tr */ {IDGS_TRACK_TR, "track"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_SECTOR,    N_("sector")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_SECTOR_DA, "sektor"},
/* de */ {IDGS_SECTOR_DE, "Sektor"},
/* fr */ {IDGS_SECTOR_FR, ""},  /* fuzzy */
/* hu */ {IDGS_SECTOR_HU, ""},  /* fuzzy */
/* it */ {IDGS_SECTOR_IT, "settore"},
/* ko */ {IDGS_SECTOR_KO, ""},  /* fuzzy */
/* nl */ {IDGS_SECTOR_NL, "sector"},
/* ru */ {IDGS_SECTOR_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SECTOR_SV, "sektor"},
/* tr */ {IDGS_SECTOR_TR, "sektör"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BLOCK_READ_DESCRIPTION,    N_("Read the block at the specified track and sector.  If an address is\nspecified, the data is loaded into memory.  If no address is given, the\ndata is displayed using the default datatype.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BLOCK_READ_DESCRIPTION_DA, "Læser en blok fra det angivne spor og sektor. Hvis en adresse angives\nindlæses data til hukommelsen. Hvis der ikke angives nogen adresse vises\nindholdet med standarddatatypen."},
/* de */ {IDGS_MON_BLOCK_READ_DESCRIPTION_DE, "Lese den Block von angegebener Spur und Sektor. Wenn eine Adresse\nangegeben wurde, lade in auf die entsprechende Adresse. Wenn keine Adresse\nangegeben ist, zeige die Daten im aktuellen Anzeigemodus für Daten."},
/* fr */ {IDGS_MON_BLOCK_READ_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BLOCK_READ_DESCRIPTION_HU, "Blokk beolvasása a megadott sávból és szektorból.,  Ha egy cím is meg\nvan adva, az adatot a memóriába tölti.  Ha az nincs, az\nadatot az alapbeállítás szerinti formában mutatja."},
/* it */ {IDGS_MON_BLOCK_READ_DESCRIPTION_IT, "Legge il blocco dalla traccia e settore specificati. Se è specificato\nun indirizzo, il dato è caricato in memoria. Se non è specificato alcun\nindirizzo, il dato è mostrato usando il tipo di dato predefinito."},
/* ko */ {IDGS_MON_BLOCK_READ_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BLOCK_READ_DESCRIPTION_NL, "Lees het blok van de opgegeven spoor en sector. Als er een adres is\nopgegeven dan zal de data naar dat adres in geheugen worden geladen.\nAls er geen adres is opgegeven dan zal de data worder getoond met de\nhuidige datasoort."},
/* ru */ {IDGS_MON_BLOCK_READ_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BLOCK_READ_DESCRIPTION_SV, "Läser blocket på det angivna spåret och sektorn. Om du anger en\nadress läses data till minnet. Om du inte anger någon adress visas\ninnehållet enligt standarddatatypen."},
/* tr */ {IDGS_MON_BLOCK_READ_DESCRIPTION_TR, "Belirtilmiþ track ve sektördeki bloðu oku.  Eðer bir adres belirtilmiþse,\nveri belleðe yüklenir.  Eðer adres belirtilmemiþse, veri varsayýlan veri\ntipi kullanýlarak görüntülenir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BSAVE_DESCRIPTION,    N_("Save the memory from address1 to address2 to the specified file.\nIf device is 0, the file is written to the file system.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BSAVE_DESCRIPTION_DA, "Gem hukommelsen fra adresse1 til adresse2 til den angivne fil.\nHvis enhed er 0 skrives til filsystemet."},
/* de */ {IDGS_MON_BSAVE_DESCRIPTION_DE, "Speichere den Speicherinhalt von Adresse1 zu Adresse2 in die angegebene Datei.\nWenn das Gerät 0 angegeben wurde, speichere im Dateisystem."},
/* fr */ {IDGS_MON_BSAVE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BSAVE_DESCRIPTION_HU, "A memória cím1 és cím2 közötti részének fájlba mentése.\nHa az eszköz 0, a fájl a fájlrendszerbe kerül."},
/* it */ {IDGS_MON_BSAVE_DESCRIPTION_IT, "Salva la memoria compresa tra indirizzo1 e indirizzo2 sul file specificato.\nSe la periferica è 0, il file è scritto sul file system."},
/* ko */ {IDGS_MON_BSAVE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BSAVE_DESCRIPTION_NL, "Sla het geheugen tussen adres1 en adres2 op naar het opgegeven bestand.\nAls het apparaat 0 is dan zal het bestand naar het bestandssysteem worden\ngeschreven."},
/* ru */ {IDGS_MON_BSAVE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BSAVE_DESCRIPTION_SV, "Spara minnet från adress1 till adress2 till den angivna filen.\nOm enheten är 0 skrivs filen till filsystemet."},
/* tr */ {IDGS_MON_BSAVE_DESCRIPTION_TR, "Adres1'den adres2'ye kadar olan belleði belirtilen dosyaya kaydet.\nEðer aygýt 0 ise, dosya dosya sistemine yazýlýr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION,    N_("Write a block of data at `address' on the specified track and sector\nof disk in drive 8.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_DA, "Skriv datablok på \"adresse\" til det angivne spor og sektor\npå disken i drev 8."},
/* de */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_DE, "Schreibe einen Datenblock von `Adresse' auf die angegebene Spure und Sektor\nin die Imagedatei von Laufwerk 8."},
/* fr */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_HU, "Egy adat blokk írása `cím' helyrõl a megadott sávba és szektorba\na 8-as meghajtón."},
/* it */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_IT, "Scrive il blocco di dati all'indirizzo sulla traccia e settore specificati\ndel disco nel drive 8."},
/* ko */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_NL, "Schrijf een data blok van `adres' naar de opgegeven spoor en sector van\nde disk in drive 8."},
/* ru */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_SV, "Skriv ett datablock på \"adress\" till det angivna spåret och sektorn\npå disken i enhet 8."},
/* tr */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_TR, "Belirtilmiþ track ve sektörlerde `adres'te yer alan veri bloðunu 8\nnumaralý sürücüdeki diske yaz."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_DIRECTORY,    N_("Directory")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_DIRECTORY_DA, "Katalog"},
/* de */ {IDGS_DIRECTORY_DE, "Verzeichnis"},
/* fr */ {IDGS_DIRECTORY_FR, "Répertoire"},
/* hu */ {IDGS_DIRECTORY_HU, ""},  /* fuzzy */
/* it */ {IDGS_DIRECTORY_IT, "Directory"},
/* ko */ {IDGS_DIRECTORY_KO, "µð·ºÅä¸®"},
/* nl */ {IDGS_DIRECTORY_NL, "Directory"},
/* ru */ {IDGS_DIRECTORY_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DIRECTORY_SV, "Katalog"},
/* tr */ {IDGS_DIRECTORY_TR, "Dizin"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_P_DIRECTORY,    N_("<Directory>")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_P_DIRECTORY_DA, "<Katalog>"},
/* de */ {IDGS_P_DIRECTORY_DE, "<Verzeichnis>"},
/* fr */ {IDGS_P_DIRECTORY_FR, "<Répertoire>"},
/* hu */ {IDGS_P_DIRECTORY_HU, ""},  /* fuzzy */
/* it */ {IDGS_P_DIRECTORY_IT, "<Directory>"},
/* ko */ {IDGS_P_DIRECTORY_KO, "<µð·ºÅä¸®>"},
/* nl */ {IDGS_P_DIRECTORY_NL, "<Directory>"},
/* ru */ {IDGS_P_DIRECTORY_RU, ""},  /* fuzzy */
/* sv */ {IDGS_P_DIRECTORY_SV, "<Katalog>"},
/* tr */ {IDGS_P_DIRECTORY_TR, "<Dizin>"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_CD_DESCRIPTION,    N_("Change current working directory.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_CD_DESCRIPTION_DA, ""},  /* fuzzy */
/* de */ {IDGS_MON_CD_DESCRIPTION_DE, "Arbeitsverzeichnis ändern."},
/* fr */ {IDGS_MON_CD_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_CD_DESCRIPTION_HU, ""},  /* fuzzy */
/* it */ {IDGS_MON_CD_DESCRIPTION_IT, ""},  /* fuzzy */
/* ko */ {IDGS_MON_CD_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_CD_DESCRIPTION_NL, "Verander de huidige werk directory"},
/* ru */ {IDGS_MON_CD_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_CD_DESCRIPTION_SV, "Ändra aktuell arbetskatalog"},
/* tr */ {IDGS_MON_CD_DESCRIPTION_TR, ""},  /* fuzzy */
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DETACH_DESCRIPTION,    N_("Detach file from device. (device 32 = cart)")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DETACH_DESCRIPTION_DA, "Frakobl filen fra enheden. (enhed 32 = cartridge)"},
/* de */ {IDGS_MON_DETACH_DESCRIPTION_DE, "Entferne Datei von Gerät. (Gerät 32 = Modul)"},
/* fr */ {IDGS_MON_DETACH_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DETACH_DESCRIPTION_HU, "Fájl leválasztása az eszközrõl. (32-es eszköz = cart)"},
/* it */ {IDGS_MON_DETACH_DESCRIPTION_IT, "Rimuovi il file dalla periferica. (periferica 32 = cart)"},
/* ko */ {IDGS_MON_DETACH_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DETACH_DESCRIPTION_NL, "Ontkoppel bestand van apparaat. (apparaat 32 = cart)"},
/* ru */ {IDGS_MON_DETACH_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DETACH_DESCRIPTION_SV, "Koppla från filen från enheten. (enhet 32 = insticksmodul)"},
/* tr */ {IDGS_MON_DETACH_DESCRIPTION_TR, "Aygýttan dosya çýkart. (aygýt 32 = kartuþ)"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DIR_DESCRIPTION,    N_("Display the directory contents.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DIR_DESCRIPTION_DA, "Vis katalogets indhold."},
/* de */ {IDGS_MON_DIR_DESCRIPTION_DE, "Zeige den Verzeichnisinhalt."},
/* fr */ {IDGS_MON_DIR_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DIR_DESCRIPTION_HU, "A könyvtár tartalmának mutatása."},
/* it */ {IDGS_MON_DIR_DESCRIPTION_IT, "Mostra il contenuto della directory."},
/* ko */ {IDGS_MON_DIR_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DIR_DESCRIPTION_NL, "Toon de directory inhoud."},
/* ru */ {IDGS_MON_DIR_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DIR_DESCRIPTION_SV, "Visa katalogens innehåll."},
/* tr */ {IDGS_MON_DIR_DESCRIPTION_TR, "Dizin içeriðini görüntüle."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_LIST_DESCRIPTION,    N_("List disk contents.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_LIST_DESCRIPTION_DA, "Vis diskens indhold."},
/* de */ {IDGS_MON_LIST_DESCRIPTION_DE, "Zeige den Verzeichnisinhalt."},
/* fr */ {IDGS_MON_LIST_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_LIST_DESCRIPTION_HU, ""},  /* fuzzy */
/* it */ {IDGS_MON_LIST_DESCRIPTION_IT, "Elenca i contenuti del disco."},
/* ko */ {IDGS_MON_LIST_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_LIST_DESCRIPTION_NL, "Toon disk inhoud."},
/* ru */ {IDGS_MON_LIST_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_LIST_DESCRIPTION_SV, "Visa diskens innehåll"},
/* tr */ {IDGS_MON_LIST_DESCRIPTION_TR, "Disk içeriðini listele."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_LOAD_DESCRIPTION,    N_("Load the specified file into memory at the specified address. Set BASIC\npointers appropriately if loaded into computer memory (not all emulators).\nUse (otherwise ignored) two-byte load address from file if no address\nspecified.\nIf device is 0, the file is read from the file system.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_LOAD_DESCRIPTION_DA, "Indlæs filen i hukommelsen på den angivne adresse. Opdaterer\nBASIC-pointers ved læsning til computerens hukommelse (ikke alle\nemulatorer). Hvis ingen adresse angives bruges load-adressen fra(som ellers ignoreres).\nHvis enhed er 0 læses fra filsystemet."},
/* de */ {IDGS_MON_LOAD_DESCRIPTION_DE, "Lade die angegebene Datei in den Speicher auf die angegebene Adresse.\nSetze den BASIC Zeiger entsprechend, wenn in den Rechnerspeicher geladen \nwurde (nicht bei allen Emulatoren!).\nVerwende (sonst ignoriert) die zwei-Byte Lade-Adresse aus der Datei, wenn\nkeine Adresse angegeben wurde.\nBei Gerät 0, wird die Datei vom Dateisystem gelade."},
/* fr */ {IDGS_MON_LOAD_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_LOAD_DESCRIPTION_HU, "A megadott fájl betöltése a megadott címre. A BASIC mutatókat\na megfelelõ módon beállítja, ha a számítógép memóriába tölti az adatot\n(nem minden emulátornál). Ha nincs cím megadva, az amúgy figyelmen hagyott\nkét bájtos betöltési címet használja a fájlból.\nHa az eszköz 0, a fájlt a fájlrendszerrõl olvassa."},
/* it */ {IDGS_MON_LOAD_DESCRIPTION_IT, "Carica il file specificato in memroia all'indirizzo specificato. Imposta\ni puntatori del BASIC in modo appropriato se caricato nella memoria\ndel computer (non su tutti gli emulatori).\nUsa (altrimenti ignora) l'indirizzo di caricamento su due byte del file\nse non viene specificato alcun indirizzo.\nSe la periferica è 0, il file viene letto dal file system."},
/* ko */ {IDGS_MON_LOAD_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_LOAD_DESCRIPTION_NL, "Laad het opgegeven bestand naar geheugen op het opgegeven adres. Zet de BASIC\nstart en eind indicators correct als het bestand naar het computer geheugen\ngeladen wordt (niet alle emulatoren). De eerste twee bytes van het bestand\nzullen als laad adres worden gebruikt als er geen adres is opgegeven. Als\nhet apparaat 0 is dan zal het bestand van het bestandssysteem worden geladen."},
/* ru */ {IDGS_MON_LOAD_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_LOAD_DESCRIPTION_SV, "Läs in den angivna filen i minnet på den angivna adressen. Sätter\nmotsvarande BASIC-pekare vid läsning till datorminnet (inte alla\nemulatorer). Om ingen adress anges används tvåbytesadressen i filen(ignoreras annars).\nOm enheten är 0 läses filen från filsystemet."},
/* tr */ {IDGS_MON_LOAD_DESCRIPTION_TR, "Belirtilmiþ dosyayý belirtilen adresten itibaren belleðe yükle. Eðer\nbilgisayar belleðine yüklenmiþse BASIC imleçlerini uygun bir biçimde\nayarla (tüm emülatörlerde deðil). Eðer adres belirtilmemiþse iki bytelýk\ndosya yükleme adresini kullan (diðer ihtimalde yoksay).\nEðer aygýt 0 ise, dosya dosya sisteminden okunur."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_PWD_DESCRIPTION,    N_("Show current working directory.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_PWD_DESCRIPTION_DA, "Vis aktuelt arbejdskatalog."},
/* de */ {IDGS_MON_PWD_DESCRIPTION_DE, "Zeige aktuelles Arbeitsverzeichnis."},
/* fr */ {IDGS_MON_PWD_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_PWD_DESCRIPTION_HU, "Munkakönyvtár mutatása."},
/* it */ {IDGS_MON_PWD_DESCRIPTION_IT, "Mostra la directory di lavoro attuale."},
/* ko */ {IDGS_MON_PWD_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_PWD_DESCRIPTION_NL, "Toon de huidige werk directory."},
/* ru */ {IDGS_MON_PWD_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_PWD_DESCRIPTION_SV, "Visa aktuell arbetskatalog."},
/* tr */ {IDGS_MON_PWD_DESCRIPTION_TR, "Geçerli çalýþma dizinini göster."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_SAVE_DESCRIPTION,    N_("Save the memory from address1 to address2 to the specified file.\nWrite two-byte load address.\nIf device is 0, the file is written to the file system.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_SAVE_DESCRIPTION_DA, "Gem hukommelsen fra  adresse1 til adresse2 til den angivne fil.\nSkriv 2-byte loadadresse i starten af filen.\nHvis enhed er 0 skrives til filsystemet."},
/* de */ {IDGS_MON_SAVE_DESCRIPTION_DE, "Speichere den Speicher von Adresse1 bis Adresse2 in die angegebene Datei.\nSchreibe eine zwei-Byte Lade Adresse.\nBei Gerät 0, wird dei Datei in das Dateisystem geschrieben."},
/* fr */ {IDGS_MON_SAVE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_SAVE_DESCRIPTION_HU, "A memória cím1 és cím2 közötti tartományának fájlba mentése.\nA kétbájtos betöltési címet is kiírja.\nHa az eszköz 0, a fájlt a fájlrendszeren hozza létre."},
/* it */ {IDGS_MON_SAVE_DESCRIPTION_IT, "Salva la memoria compresa tra indirizzo1 e indirizzo2 sul file\nspecificato.\nScrive l'indirizzo di caricamento su due byte.\nSe la periferica è 0, il file è scritto sul file system."},
/* ko */ {IDGS_MON_SAVE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_SAVE_DESCRIPTION_NL, "Sla het geheugen tussen adres1 en adres2 op naar het opgegeven bestand.\nSchrijf een load adres van twee bytes.\nAls het apparaat 0 is dan zal het bestand geschreven worden naar het\nbestandssysteem."},
/* ru */ {IDGS_MON_SAVE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_SAVE_DESCRIPTION_SV, "Spara minnet från adress1 till adress2 till den angivna filen.\nSkriv tvåbytes inläsningsadress.\nOm enheten är 0 skrivs filen till filsystemet."},
/* tr */ {IDGS_MON_SAVE_DESCRIPTION_TR, "Adres1'den adres2'ye kadar olan belleði belirtilen dosyaya kaydet.\nÝki bytelýk yükeme adresini yaz.\nEðer aygýt 0 ise, dosya dosya sistemine yazýlýr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_OTHER_COMMANDS,    N_("Other commands:")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_OTHER_COMMANDS_DA, "Andre kommandoer:"},
/* de */ {IDGS_OTHER_COMMANDS_DE, "Andere Kommandos:"},
/* fr */ {IDGS_OTHER_COMMANDS_FR, ""},  /* fuzzy */
/* hu */ {IDGS_OTHER_COMMANDS_HU, ""},  /* fuzzy */
/* it */ {IDGS_OTHER_COMMANDS_IT, "Altri comandi:"},
/* ko */ {IDGS_OTHER_COMMANDS_KO, ""},  /* fuzzy */
/* nl */ {IDGS_OTHER_COMMANDS_NL, "Andere commandos:"},
/* ru */ {IDGS_OTHER_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_OTHER_COMMANDS_SV, "Andra kommandon:"},
/* tr */ {IDGS_OTHER_COMMANDS_TR, "Diðer komutlar:"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION,    N_("Display the specified number in decimal, hex, octal and binary.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_DA, "Vis det angivne tal som decimal, hexadecimal, oktal og binært."},
/* de */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_DE, "Zeige die angegebene Zahl in dezimal, hexadezimal, oktal oder binär."},
/* fr */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_HU, "A megadott szám kiírása decimálisan, hexadecimálisan, oktálisan és binárisan."},
/* it */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_IT, "Mostra il numero specificato in decimale, esadecimale, ottale e binario."},
/* ko */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_NL, "Toon het opgegeven nummer in decimaal, hex, octaal en binair."},
/* ru */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_SV, "Visa det angivna talet decimalt, hexadecimalt, oktalt och binärt."},
/* tr */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_TR, "Belirtilen sayýyý 10'lu, 16'lý, 8'li ya da 2'li olarak görüntüle."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_CARTFREEZE_DESCRIPTION,    N_("Use cartridge freeze.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_CARTFREEZE_DESCRIPTION_DA, "Brug cartridge frys-funktion."},
/* de */ {IDGS_MON_CARTFREEZE_DESCRIPTION_DE, "Erweiterungsmodul Freeze benutzen."},
/* fr */ {IDGS_MON_CARTFREEZE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_CARTFREEZE_DESCRIPTION_HU, "Cartridge fagyasztás használata."},
/* it */ {IDGS_MON_CARTFREEZE_DESCRIPTION_IT, "Usa freeze della cartuccia."},
/* ko */ {IDGS_MON_CARTFREEZE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_CARTFREEZE_DESCRIPTION_NL, "Gebruik cartridge freeze."},
/* ru */ {IDGS_MON_CARTFREEZE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_CARTFREEZE_DESCRIPTION_SV, "Använd insticksmodulens frysfunktion."},
/* tr */ {IDGS_MON_CARTFREEZE_DESCRIPTION_TR, "Kartuþ freeze kullan"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_HELP_DESCRIPTION,    N_("If no argument is given, prints out a list of all available commands\nIf an argument is given, prints out specific help for that command.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_HELP_DESCRIPTION_DA, "Hvis der ikke angives et argument vises en liste over mulige kommandoer.\nAngives et argument vises hjælp for denne kommando."},
/* de */ {IDGS_MON_HELP_DESCRIPTION_DE, "Wenn kein Argement angegeben wurde, werden alle Kommandos ausgegeben.\nMit Argument, zeige die Hilfe für das angegebene Kommand."},
/* fr */ {IDGS_MON_HELP_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_HELP_DESCRIPTION_HU, "Ha nincs paraméter, az összes létezõ parancs listáját mutatja.\nHa van, az adott parancshoz mutatja a súgót."},
/* it */ {IDGS_MON_HELP_DESCRIPTION_IT, "Se non viene specificato alcun argomeno, stamapa la lista di tutti i\ncomandi disponibili.\nSe viene specificato un argomento, stampa l'aiuto relativo a quel\ncomando."},
/* ko */ {IDGS_MON_HELP_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_HELP_DESCRIPTION_NL, "Als er geen parameter is opgegeven dan zal een lijst van alle commandos\nworden weergegeven. Als er een parameter is opgegeven dan zal de help voor\nhet opgegeven command worden weergegeven."},
/* ru */ {IDGS_MON_HELP_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_HELP_DESCRIPTION_SV, "Om du inte anger några argument visas alla tillgängliga kommandon.\nOm du anger ett argument visas hjälp för det specifika kommandot."},
/* tr */ {IDGS_MON_HELP_DESCRIPTION_TR, "Eðer hiç argüman verilmemiþse, tüm mevcut komutlarýn listesi yazdýrýlýr\nEðer bir argüman verilmiþse, o komuta özel yardým bilgisi yazdýrýlýr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_STRING,    N_("string")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_STRING_DA, "streng"},
/* de */ {IDGS_STRING_DE, "String"},
/* fr */ {IDGS_STRING_FR, ""},  /* fuzzy */
/* hu */ {IDGS_STRING_HU, ""},  /* fuzzy */
/* it */ {IDGS_STRING_IT, "stringa"},
/* ko */ {IDGS_STRING_KO, ""},  /* fuzzy */
/* nl */ {IDGS_STRING_NL, "string"},
/* ru */ {IDGS_STRING_RU, ""},  /* fuzzy */
/* sv */ {IDGS_STRING_SV, "sträng"},
/* tr */ {IDGS_STRING_TR, "yazý"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_KEYBUF_DESCRIPTION,    N_("Put the specified string into the keyboard buffer.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_KEYBUF_DESCRIPTION_DA, "Indsæt den angivne streng i tastatur-bufferen."},
/* de */ {IDGS_MON_KEYBUF_DESCRIPTION_DE, "Definierte Eingabe in Tastaturpuffer bereitstellen."},
/* fr */ {IDGS_MON_KEYBUF_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_KEYBUF_DESCRIPTION_HU, "A megadott sztring elhelyezése a billentyûzet pufferben."},
/* it */ {IDGS_MON_KEYBUF_DESCRIPTION_IT, "Metti la stringa specificata nel buffer di tastiera."},
/* ko */ {IDGS_MON_KEYBUF_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_KEYBUF_DESCRIPTION_NL, "Plaats de opgegeven string in de toetsenbordbuffer."},
/* ru */ {IDGS_MON_KEYBUF_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_KEYBUF_DESCRIPTION_SV, "Lägg den angivna strängen i tangentbordsbufferten."},
/* tr */ {IDGS_MON_KEYBUF_DESCRIPTION_TR, "Klavye arabelleðine belirtilen yazýyý koy."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_PLAYBACK_DESCRIPTION,    N_("Monitor commands from the specified file are read and executed.  This\ncommand stops at the end of file or when a STOP command is read.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_PLAYBACK_DESCRIPTION_DA, "Monitorkommandoer indlæses fra den angivne fil og udføres. Kommandoen\nstopper når slutningen af filen nås, eller når der opdages en STOP-kommando."},
/* de */ {IDGS_MON_PLAYBACK_DESCRIPTION_DE, "Monitor Kommandos aus der angegebenen Datei werden gelesen und ausgeführt.\nDieses Kommando stoppt, wenn das Ende der Datei erreicht wurde, oder das\nKommando STOP gelesen wurde."},
/* fr */ {IDGS_MON_PLAYBACK_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_PLAYBACK_DESCRIPTION_HU, "A monitor parancsokat beolvassa és végrehajtja a megadott fájlból.\nA fájl végéig halad, vagy egy beolvasott STOP parancsig."},
/* it */ {IDGS_MON_PLAYBACK_DESCRIPTION_IT, "I comandi del monitor sono letti ed eseguiti dal file specificato. Questo\ncomando si arresta alla fine del file o quando viene letto il comando\nSTOP."},
/* ko */ {IDGS_MON_PLAYBACK_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_PLAYBACK_DESCRIPTION_NL, "Monitor commandos van het opgegeven bestand zullen worden gelezen en\nuitgevoerd. Dit commando stopt aan het einde van het bestand of wanneer\neen STOP commando wordt gelezen."},
/* ru */ {IDGS_MON_PLAYBACK_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_PLAYBACK_DESCRIPTION_SV, "Monitorkommandon läses in och körs från den angivna filen. Kommandot\nstoppar vid filslut eller när ett STOP-kommando läses."},
/* tr */ {IDGS_MON_PLAYBACK_DESCRIPTION_TR, "Belirtilen dosyadaki monitör komutlarý okundu ve çalýþtýrýldý.  Bu\nkomut dosya sonunda ya da STOP komutu okunduðunda sonlanýr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_EXPRESSION,    N_("expression")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_EXPRESSION_DA, ""},  /* fuzzy */
/* de */ {IDGS_EXPRESSION_DE, "Ausdruck"},
/* fr */ {IDGS_EXPRESSION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_EXPRESSION_HU, ""},  /* fuzzy */
/* it */ {IDGS_EXPRESSION_IT, "espressione"},
/* ko */ {IDGS_EXPRESSION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_EXPRESSION_NL, "expressie"},
/* ru */ {IDGS_EXPRESSION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_EXPRESSION_SV, "uttryck"},
/* tr */ {IDGS_EXPRESSION_TR, "ifade"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_PRINT_DESCRIPTION,    N_("Evaluate the specified expression and output the result.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_PRINT_DESCRIPTION_DA, "Evaluér det angivne udtryk og vis resultatet."},
/* de */ {IDGS_MON_PRINT_DESCRIPTION_DE, "Evaluiere den angegebenen Ausdruck und zeige das Ergebnis."},
/* fr */ {IDGS_MON_PRINT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_PRINT_DESCRIPTION_HU, "Kiértékeli a megadott kifejezést és kiírja az eredményt."},
/* it */ {IDGS_MON_PRINT_DESCRIPTION_IT, "Calcola l'espressione specificata e mostra il risultato."},
/* ko */ {IDGS_MON_PRINT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_PRINT_DESCRIPTION_NL, "Evalueer de opgegeven expressie en toon het resultaat."},
/* ru */ {IDGS_MON_PRINT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_PRINT_DESCRIPTION_SV, "Utvärdera det angivna uttrycket och visa resultatet."},
/* tr */ {IDGS_MON_PRINT_DESCRIPTION_TR, "Belirtilen ifadeyi deðerlendir ve sonucun çýktýsýný ver."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_RECORD_DESCRIPTION,    N_("After this command, all commands entered are written to the specified\nfile until the STOP command is entered.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_RECORD_DESCRIPTION_DA, "Efter denne kommando skrives alle kommandoer til den angivne fil,\nindtil der angives en STOP-kommando."},
/* de */ {IDGS_MON_RECORD_DESCRIPTION_DE, "Nach diesem Kommando werden alle eingebenen Kommands in die angegebene\nDatei gespeicher solang bis das Kommando STOP eingegeben wurde."},
/* fr */ {IDGS_MON_RECORD_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_RECORD_DESCRIPTION_HU, "Ezután a parancs után az összes parancsot a megadott fájlba\nírja, amíg STOP parancs nem érkezik."},
/* it */ {IDGS_MON_RECORD_DESCRIPTION_IT, "Dopo questo comando, tutti i comandi inseriti saranno scritti sul file\nspecificato fino a quando verrà inserito il comando STOP."},
/* ko */ {IDGS_MON_RECORD_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_RECORD_DESCRIPTION_NL, "Na dit commando zullen alle opgegeven commandos worden geschreven naar\nhet opgegeven bestand totdat het STOP command wordt opgegeven."},
/* ru */ {IDGS_MON_RECORD_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_RECORD_DESCRIPTION_SV, "Efter detta kommando kommer alla kommandon som anges att skrivas till\nden angivna filen tills ett STOP-kommando anges."},
/* tr */ {IDGS_MON_RECORD_DESCRIPTION_TR, "Bu komuttan sonra, tüm girilen komutlar ve STOP komutunu görene dek\nbelirtilen dosyaya yazýlacaktýr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_RESOURCE,    N_("resource")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_RESOURCE_DA, "resource"},
/* de */ {IDGS_RESOURCE_DE, "Ressource"},
/* fr */ {IDGS_RESOURCE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_RESOURCE_HU, ""},  /* fuzzy */
/* it */ {IDGS_RESOURCE_IT, "risorsa"},
/* ko */ {IDGS_RESOURCE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_RESOURCE_NL, "bron"},
/* ru */ {IDGS_RESOURCE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RESOURCE_SV, "resurs"},
/* tr */ {IDGS_RESOURCE_TR, "kaynak"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_RESOURCEGET_DESCRIPTION,    N_("Displays the value of the resource.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_RESOURCEGET_DESCRIPTION_DA, "Viser værdien for ressourcen."},
/* de */ {IDGS_MON_RESOURCEGET_DESCRIPTION_DE, "Zeige den Werde der Ressource."},
/* fr */ {IDGS_MON_RESOURCEGET_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_RESOURCEGET_DESCRIPTION_HU, "Az erõforrás értékének kiírása."},
/* it */ {IDGS_MON_RESOURCEGET_DESCRIPTION_IT, "Mostra il valore della risorsa."},
/* ko */ {IDGS_MON_RESOURCEGET_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_RESOURCEGET_DESCRIPTION_NL, "Toont de waarde van de resource."},
/* ru */ {IDGS_MON_RESOURCEGET_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_RESOURCEGET_DESCRIPTION_SV, "Visar värdet för resursen."},
/* tr */ {IDGS_MON_RESOURCEGET_DESCRIPTION_TR, "Kaynaðýn deðerini görüntüler."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_VALUE,    N_("value")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_VALUE_DA, "værdi"},
/* de */ {IDGS_VALUE_DE, "Wert"},
/* fr */ {IDGS_VALUE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_VALUE_HU, ""},  /* fuzzy */
/* it */ {IDGS_VALUE_IT, "valore"},
/* ko */ {IDGS_VALUE_KO, "°¡Ä¡"},
/* nl */ {IDGS_VALUE_NL, "waarde"},
/* ru */ {IDGS_VALUE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_VALUE_SV, "värde"},
/* tr */ {IDGS_VALUE_TR, "deðer"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_RESOURCESET_DESCRIPTION,    N_("Sets the value of the resource.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_RESOURCESET_DESCRIPTION_DA, "Sætter værdien for ressourcen."},
/* de */ {IDGS_MON_RESOURCESET_DESCRIPTION_DE, "Setze den Werde der Ressource."},
/* fr */ {IDGS_MON_RESOURCESET_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_RESOURCESET_DESCRIPTION_HU, "Az erõforrás értékének beállítása."},
/* it */ {IDGS_MON_RESOURCESET_DESCRIPTION_IT, "Imposta il valore della risorsa."},
/* ko */ {IDGS_MON_RESOURCESET_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_RESOURCESET_DESCRIPTION_NL, "Plaats de waarde in de resource."},
/* ru */ {IDGS_MON_RESOURCESET_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_RESOURCESET_DESCRIPTION_SV, "Ställer in ett värde för resursen."},
/* tr */ {IDGS_MON_RESOURCESET_DESCRIPTION_TR, "Kaynaðýn deðerini belirler."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_STOP_DESCRIPTION,    N_("Stop recording commands.  See `record'.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_STOP_DESCRIPTION_DA, "Afslut optagelse. Se \"record\"."},
/* de */ {IDGS_MON_STOP_DESCRIPTION_DE, "Stoppe die Aufnahme von Kommandos. Siehe auch `Record'."},
/* fr */ {IDGS_MON_STOP_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_STOP_DESCRIPTION_HU, "A parancsok rögzítésének befejezése.  Lásd `record'"},
/* it */ {IDGS_MON_STOP_DESCRIPTION_IT, "Ferma il comando di registrazione. Guarda `registra'."},
/* ko */ {IDGS_MON_STOP_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_STOP_DESCRIPTION_NL, "Stop de opname van commandos. Zie 'record'."},
/* ru */ {IDGS_MON_STOP_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_STOP_DESCRIPTION_SV, "Sluta spela in kommandon. Se \"record\"."},
/* tr */ {IDGS_MON_STOP_DESCRIPTION_TR, "Kayýt komutlarýný durdur.  `record'a bak."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_SCREENSHOT_DESCRIPTION,    N_("Take a screenshot. Format is:\ndefault = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_SCREENSHOT_DESCRIPTION_DA, "Gem et screenshot. Format er:\nstandard = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* de */ {IDGS_MON_SCREENSHOT_DESCRIPTION_DE, "Erzeuge Screenshot. Format ist:\nStandard = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* fr */ {IDGS_MON_SCREENSHOT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_SCREENSHOT_DESCRIPTION_HU, "Képernyõkép készítése. A formátum lehet:\nalap = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* it */ {IDGS_MON_SCREENSHOT_DESCRIPTION_IT, "Cattura schermo. Il formato è:\npredefinito = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* ko */ {IDGS_MON_SCREENSHOT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_SCREENSHOT_DESCRIPTION_NL, "Sla een schermafdruk op. Formaat is:\nstandaard = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* ru */ {IDGS_MON_SCREENSHOT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_SCREENSHOT_DESCRIPTION_SV, "Ta en skärmbild. Format är:\nstandard = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* tr */ {IDGS_MON_SCREENSHOT_DESCRIPTION_TR, "Ekran görüntüsü al. Biçim:\nvarsayýlan = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_TAPECTRL_DESCRIPTION,    N_("Control the datasette. Valid commands:\n0 = stop, 1 = start, 2 = forward, 3 = rewind, 4 = record,\n5 = reset, 6 = reset counter.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_TAPECTRL_DESCRIPTION_DA, "Styr datasette. Lovlige kommandoer:\n0 = stop, 1 = start, 2 = spol frem, 3 = spol tilbage,\n4 = optag, 5 = reset, 6 = nulstil tæller."},
/* de */ {IDGS_MON_TAPECTRL_DESCRIPTION_DE, "Steuere die Datasette. Gültige Kommandos sind:\n0 = Stop, 1 = Start, 2 = Forwärts, 3 = Rückwärts, 4 = Aufnahme,\n5 = Reset, 6 = Reset Zähler."},
/* fr */ {IDGS_MON_TAPECTRL_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_TAPECTRL_DESCRIPTION_HU, "Szalagos egység vezérlése. Érvényes parancsok:\n0 = start, 1 = indít, 2 = elõre, 3 = vissza, 4 = felvétel,\n5 = újraindít, 6 = számlálót nulláz"},
/* it */ {IDGS_MON_TAPECTRL_DESCRIPTION_IT, "Controlla il registratore. Comandi validi:\n0 = ferma, 1 = avvia, 2 = avanti, 3 = indietro, 4 = registra,\n5 = reset, 6 = reset contatore."},
/* ko */ {IDGS_MON_TAPECTRL_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_TAPECTRL_DESCRIPTION_NL, "Geef datasette commandos. Geldige commandos:\n0 = stop, 1 = start, 2 = vooruit, 3 = terug, 4 = opnemen,\n5 = reset, 6 = reset teller."},
/* ru */ {IDGS_MON_TAPECTRL_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_TAPECTRL_DESCRIPTION_SV, "Styr bandspelaren. Giltiga kommandon:\n0 = stoppa, 1 = starta, 2 = spola framåt, 3 = spola bakåt,\n4 = spela in, 5 = återställ, 6 = nollställ räknare."},
/* tr */ {IDGS_MON_TAPECTRL_DESCRIPTION_TR, "Teybi kontrol et. Geçerli komutlar:\n0 = durdur, 1 = baþlat, 2 = ileri, 3 = geri, 4 = kayýt,\n5 = reset, 6 = reset sayacý."},
#endif

/* ------------------------ COMMAND LINE OPTION STRINGS -------------------- */

/* autostart.c */
/* en */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START,    N_("On autostart, load to BASIC start (without ',1')")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_DA, "Indlæs til BASIC start ved autostart (uden ',1')"},
/* de */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_DE, "Bei Autostart, lade an BASIC Start (ohne ',1')"},
/* fr */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_HU, ""},  /* fuzzy */
/* it */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_IT, "All'avvio automatico, carica all'inizio del BASIC (senza ',1')"},
/* ko */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_NL, "Bij autostarten, laad naar BASIC start (zonder ',1')"},
/* ru */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_SV, "Vid autostart, hämta till BASIC-start (utan \",1\")"},
/* tr */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_TR, "Otomatik baþlatýldýðýnda, BASIC baþlangýcýna yükle (',1' olmadan)"},
#endif

/* autostart.c */
/* en */ {IDCLS_AUTOSTART_LOAD_WITH_1,    N_("On autostart, load with ',1'")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_AUTOSTART_LOAD_WITH_1_DA, "Indlæs med ',1' ved autostart"},
/* de */ {IDCLS_AUTOSTART_LOAD_WITH_1_DE, "Bei Autostart, lade mit ',1'"},
/* fr */ {IDCLS_AUTOSTART_LOAD_WITH_1_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_AUTOSTART_LOAD_WITH_1_HU, ""},  /* fuzzy */
/* it */ {IDCLS_AUTOSTART_LOAD_WITH_1_IT, "All'avvio automatico, carica con ',1'"},
/* ko */ {IDCLS_AUTOSTART_LOAD_WITH_1_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_AUTOSTART_LOAD_WITH_1_NL, "Bij autostarten, laad met ',1'"},
/* ru */ {IDCLS_AUTOSTART_LOAD_WITH_1_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_AUTOSTART_LOAD_WITH_1_SV, "Vid autostart, hämta med \",1\""},
/* tr */ {IDCLS_AUTOSTART_LOAD_WITH_1_TR, "Otomatik baþlatýldýðýnda, ',1' ile yükle"},
#endif

/* autostart.c */
/* en */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON,    N_("On autostart, use the 'RUN' command with a colon, i.e., 'RUN:'")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_DA, "Brug \"RUN\"-kommando med kolon ved autostart, dvs. \"RUN:\""},
/* de */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_DE, "Bei Autostart soll 'RUN' mit Doppelpunkt ausgeführt werden ('RUN:')"},
/* fr */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_HU, "Automatikus indításnál a 'RUN' parancs kettõsponttal, vagyis 'RUN:'"},
/* it */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_IT, "All'avvio automatico, usa il comando 'RUN' con i due punti; cioè 'RUN:'"},
/* ko */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_NL, "Bij het autostarten, gebruik het 'RUN' commando met een dubbele punt, dus 'RUN:'"},
/* ru */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_SV, "Vid autostart, använd \"RUN\"-kommando med kolon, dvs. \"RUN:\""},
/* tr */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_TR, "Otomatik baþlatýldýðýnda, 'RUN' komutunu ':' ile kullan, yani, 'RUN:'"},
#endif

/* autostart.c */
/* en */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON,    N_("On autostart, do not use the 'RUN' command with a colon; i.e., 'RUN'")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_DA, "Brug ikke \"RUN\"-kommando med kolon ved autostart, dvs. \"RUN\""},
/* de */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_DE, "Bei Autostart soll 'RUN' ohne Doppelpunkt ausgeführt werden ('RUN')"},
/* fr */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_HU, "Automatikus indításnak a 'RUN' parancs kettõspont nélkül, vagyis 'RUN'"},
/* it */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_IT, "All'avvio automatico, non usare il comando 'RUN' con i due punti; cioè 'RUN'"},
/* ko */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_NL, "Bij het autostarten, gebruik het 'RUN' commando niet met een dubbele punt, dus 'RUN'"},
/* ru */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_SV, "Vid autostart, använd inte \"RUN\"-kommando med kolon, dvs. \"RUN\""},
/* tr */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_TR, "Otomatik baþlatýldýðýnda, 'RUN' komutunu ':' ile kullanma, yani, 'RUN'"},
#endif

/* autostart.c */
/* en */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE,    N_("Handle True Drive Emulation on autostart")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_DA, "Anvend ægte drev-emulering ved autostart"},
/* de */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_DE, "Präzise Floppy Emulation bei Autostart beachten"},
/* fr */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_HU, "Valós lemezegység emuláció kezelése autostartnál"},
/* it */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_IT, "Emulazione hardware dei drive all'avvio automatico"},
/* ko */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_NL, "Manipuleer hardwarematige drive emulatie bij autostarten"},
/* ru */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_SV, "Hantera äkta diskettenhetsemulering vid autostart"},
/* tr */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_TR, "Otomatik baþlatmada Gerçek Sürücü Emülasyonu'nu denetle"},
#endif

/* autostart.c */
/* en */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE,    N_("Do not handle True Drive Emulation on autostart")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_DA, "Anvend ikke ægte drev-emulering ved autostart"},
/* de */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_DE, "Präzise Floppy Emulation bei Autostart nicht beachten"},
/* fr */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_HU, "Valós lemezegység emulációt nem kezeli autostartnál"},
/* it */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_IT, "Non gestire l'emulazione hardware dei drive all'avvio automatico"},
/* ko */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_NL, "Geen manipulatie van de hardwarematige drive emulatie bij autostarten"},
/* ru */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_SV, "Hantera inte äkta diskettenhetsemulering vid autostart"},
/* tr */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_TR, "Baþlangýçta Gerçek Sürücü Emülasyonu'nu Denetleme"},
#endif

/* autostart.c */
/* en */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART,    N_("Enable warp mode during autostart")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_DA, "Aktivér warp-tilstand under autostart"},
/* de */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_DE, "Warp Mode während Autostart aktivieren"},
/* fr */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_HU, "Hipergyors mód engedélyezése autostartnál"},
/* it */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_IT, "Attiva la modalità turbo all'avvio automatico"},
/* ko */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_NL, "Activeer warp modus tijdens autostarten"},
/* ru */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_SV, "Aktivera warpläge för autostart"},
/* tr */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_TR, "Otomatik baþlatma esnasýnda warp modu aktif et"},
#endif

/* autostart.c */
/* en */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART,    N_("Disable warp mode during autostart")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_DA, "Deaktivér warp-tilstand under autostart"},
/* de */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_DE, "Warp Mode währen Autostart deaktivieren"},
/* fr */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_HU, "Hipergyors mód tiltása autostartnál"},
/* it */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_IT, "Disattiva la modalità turbo all'avvio automatico"},
/* ko */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_NL, "Warp modus tijdens autostarten uitschakelen"},
/* ru */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_SV, "Inaktivera warpläge för autostart"},
/* tr */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_TR, "Otomatik baþlatma esnasýnda warp modu pasifleþtir"},
#endif

/* autostart.c */
/* en */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG,    N_("Set autostart mode for PRG files")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_DA, "Vælg autostart-tilstand for PRG-filer"},
/* de */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_DE, "Autostart Modus für PRG Dateien definieren"},
/* fr */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_HU, "Automatikus indítás módja PRG fájloknál"},
/* it */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_IT, "Imposta avvio automatico per i file PRG"},
/* ko */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_NL, "Zet autostart modus voor PRG bestanden"},
/* ru */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_SV, "Välj autostartläge för PRG-filer"},
/* tr */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_TR, "PRG dosyalarý için otomatik baþlatma ayarla"},
#endif

/* autostart.c */
/* en */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG,    N_("Set disk image for autostart of PRG files")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_DA, "Vælg diskimage for autostart af PRG-filer"},
/* de */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_DE, "Disk Imagedatei für Autostart definieren"},
/* fr */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_HU, "Lmeez képmás megadása PRG automatikus indításhoz"},
/* it */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_IT, "Imposta immagine disco per l'avvio automatico dei file PRG"},
/* ko */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_NL, "Zet disk bestand voor het autostarten van PRG bestanden"},
/* ru */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_SV, "Ange diskavbildning för autostart av PRG-filer"},
/* tr */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_TR, "PRG dosyalarýnýn otomatik baþlatýlmasý için disk imajý ayarla"},
#endif

/* autostart.c */
/* en */ {IDCLS_SET_AUTOSTART_DELAY,    N_("Set initial autostart delay (0: use default)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_AUTOSTART_DELAY_DA, ""},  /* fuzzy */
/* de */ {IDCLS_SET_AUTOSTART_DELAY_DE, "Autostart Verzögerung definieren. (0: Standard)"},
/* fr */ {IDCLS_SET_AUTOSTART_DELAY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_AUTOSTART_DELAY_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_AUTOSTART_DELAY_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_SET_AUTOSTART_DELAY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_AUTOSTART_DELAY_NL, ""},  /* fuzzy */
/* ru */ {IDCLS_SET_AUTOSTART_DELAY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_AUTOSTART_DELAY_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_SET_AUTOSTART_DELAY_TR, ""},  /* fuzzy */
#endif

/* autostart.c */
/* en */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY,    N_("Enable random initial autostart delay.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_DE, "Zufällige Autostart Verzögerung aktivieren."},
/* fr */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_NL, ""},  /* fuzzy */
/* ru */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_TR, ""},  /* fuzzy */
#endif

/* autostart.c */
/* en */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY,    N_("Disable random initial autostart delay.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_DA, ""},  /* fuzzy */
/* de */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_DE, "Zufällige Autostart Verzögerung deaktivieren."},
/* fr */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_NL, ""},  /* fuzzy */
/* ru */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_TR, ""},  /* fuzzy */
#endif

/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c,
   c64/psid.c, plus4/plus4-cmdline-options.c,
   vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_USE_PAL_SYNC_FACTOR,    N_("Use PAL sync factor")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_PAL_SYNC_FACTOR_DA, "Anvend PAL-synkfaktor"},
/* de */ {IDCLS_USE_PAL_SYNC_FACTOR_DE, "PAL Sync Faktor benutzen"},
/* fr */ {IDCLS_USE_PAL_SYNC_FACTOR_FR, "Utiliser PAL"},
/* hu */ {IDCLS_USE_PAL_SYNC_FACTOR_HU, "PAL szinkron faktor használata"},
/* it */ {IDCLS_USE_PAL_SYNC_FACTOR_IT, "Usa fattore di sincronizzazione PAL"},
/* ko */ {IDCLS_USE_PAL_SYNC_FACTOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_PAL_SYNC_FACTOR_NL, "Gebruik PAL synchronisatiefaktor"},
/* ru */ {IDCLS_USE_PAL_SYNC_FACTOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_PAL_SYNC_FACTOR_SV, "Använd PAL-synkfaktor"},
/* tr */ {IDCLS_USE_PAL_SYNC_FACTOR_TR, "PAL senkron faktörü kullan"},
#endif

/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c,
   c64/psid.c, plus4/plus4-cmdline-options.c,
   vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_USE_NTSC_SYNC_FACTOR,    N_("Use NTSC sync factor")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_NTSC_SYNC_FACTOR_DA, "Anvend NTSC-synkfaktor"},
/* de */ {IDCLS_USE_NTSC_SYNC_FACTOR_DE, "NTSC Sync Faktor benutzen"},
/* fr */ {IDCLS_USE_NTSC_SYNC_FACTOR_FR, "Utiliser NTSC"},
/* hu */ {IDCLS_USE_NTSC_SYNC_FACTOR_HU, "NTSC szinkron faktor használata"},
/* it */ {IDCLS_USE_NTSC_SYNC_FACTOR_IT, "Usa fattore di sincronizzazione NTSC"},
/* ko */ {IDCLS_USE_NTSC_SYNC_FACTOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_NTSC_SYNC_FACTOR_NL, "Gebruik NTSC synchronisatiefaktor"},
/* ru */ {IDCLS_USE_NTSC_SYNC_FACTOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_NTSC_SYNC_FACTOR_SV, "Använd NTSC-synkfaktor"},
/* tr */ {IDCLS_USE_NTSC_SYNC_FACTOR_TR, "NTSC senkron faktörü kullan"},
#endif

/* c64/c64-cmdline-options.c, c64/psid.c */
/* en */ {IDCLS_USE_PALN_SYNC_FACTOR,    N_("Use PAL-N sync factor")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_PALN_SYNC_FACTOR_DA, "Anvend PAL-N synkfaktor"},
/* de */ {IDCLS_USE_PALN_SYNC_FACTOR_DE, "PAL Sync Faktor benutzen"},
/* fr */ {IDCLS_USE_PALN_SYNC_FACTOR_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_USE_PALN_SYNC_FACTOR_HU, ""},  /* fuzzy */
/* it */ {IDCLS_USE_PALN_SYNC_FACTOR_IT, "Usa fattore di sincronizzazione PAL-N"},
/* ko */ {IDCLS_USE_PALN_SYNC_FACTOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_PALN_SYNC_FACTOR_NL, "Gebruik PAL-N synchronisatiefaktor"},
/* ru */ {IDCLS_USE_PALN_SYNC_FACTOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_PALN_SYNC_FACTOR_SV, "Använd PAL N-synkfaktor"},
/* tr */ {IDCLS_USE_PALN_SYNC_FACTOR_TR, "PAL-N senkron faktörü kullan"},
#endif

/* c128/c128-cmdline-options.c, c128/functionrom.c,
   c64/c64-cmdline-options.c, c64/cart/georam.c,
   c64/cart/ramcart.c, c64/cart/reu.c, c64/cart/c64cart.c,
   c64/cart/ide64.c, cbm2/cbm2-cmdline-options.c,
   drive/iec/iec-cmdline-options.c, drive/iec128dcr/iec128dcr-cmdline-options.c,
   drive/ieee/ieee-cmdline-options.c, drive/tcbm/tcbm-cmdline-options.c,
   fsdevice/fsdevice-cmdline-options.c, pet/pet-cmdline-options.c,
   plus4/plus4-cmdline-options.c, printerdrv/driver-select.c,
   printerdrv/output-select.c, printerdrv/output-text.c,
   rs232drv/rs232drv.c, vic20/vic20-cmdline-options.c,
   vic20/vic20cartridge.c, video/video-cmdline-options.c,
   fliplist.c, initcmdline.c, log.c, sound.c, c64/plus60k.c,
   c64/c64_256k.c, pet/petreu.c, c64/plus256k.c */
/* en */ {IDCLS_P_NAME,    N_("<Name>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_NAME_DA, "<Navn>"},
/* de */ {IDCLS_P_NAME_DE, "<Name>"},
/* fr */ {IDCLS_P_NAME_FR, "<Nom>"},
/* hu */ {IDCLS_P_NAME_HU, "<Név>"},
/* it */ {IDCLS_P_NAME_IT, "<Nome>"},
/* ko */ {IDCLS_P_NAME_KO, "<ÀÌ¸§>"},
/* nl */ {IDCLS_P_NAME_NL, "<Naam>"},
/* ru */ {IDCLS_P_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_NAME_SV, "<Namn>"},
/* tr */ {IDCLS_P_NAME_TR, "<Ýsim>"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_INT_KERNEL_NAME,    N_("Specify name of international Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_INT_KERNEL_NAME_DA, "Angiv navn på internationalt kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_INT_KERNEL_NAME_DE, "Bitte Namen für internationale Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_INT_KERNEL_NAME_FR, "Spécifier le nom de l'image Kernal internationale"},
/* hu */ {IDCLS_SPECIFY_INT_KERNEL_NAME_HU, "Adja meg a nemzetközi Kernal ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_INT_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal internazionale"},
/* ko */ {IDCLS_SPECIFY_INT_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_INT_KERNEL_NAME_NL, "Geef de naam van het internationaal Kernal ROM bestand"},
/* ru */ {IDCLS_SPECIFY_INT_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_INT_KERNEL_NAME_SV, "Ange namn på internationell kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_INT_KERNEL_NAME_TR, "Uluslararasý Kernal ROM imajýnýn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_DE_KERNEL_NAME,    N_("Specify name of German Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_DE_KERNEL_NAME_DA, "Angiv navn på tysk kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_DE_KERNEL_NAME_DE, "Name für deutsche Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_DE_KERNEL_NAME_FR, "Spécifier le nom de l'image Kernal allemande"},
/* hu */ {IDCLS_SPECIFY_DE_KERNEL_NAME_HU, "Adja meg a német Kernal ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_DE_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal tedesca"},
/* ko */ {IDCLS_SPECIFY_DE_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_DE_KERNEL_NAME_NL, "Geef de naam van het Duitse Kernal ROM bestand"},
/* ru */ {IDCLS_SPECIFY_DE_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_DE_KERNEL_NAME_SV, "Ange namn på tysk kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_DE_KERNEL_NAME_TR, "Alman Kernal ROM imajýnýn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_FI_KERNEL_NAME,    N_("Specify name of Finnish Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FI_KERNEL_NAME_DA, "Angiv navn på finsk kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_FI_KERNEL_NAME_DE, "Name für finnische Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_FI_KERNEL_NAME_FR, "Spécifier le nom de l'image Kernal finlandaise"},
/* hu */ {IDCLS_SPECIFY_FI_KERNEL_NAME_HU, "Adja meg a finn Kernal ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_FI_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal finlandese"},
/* ko */ {IDCLS_SPECIFY_FI_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FI_KERNEL_NAME_NL, "Geef de naam van het Finse Kernal ROM bestand"},
/* ru */ {IDCLS_SPECIFY_FI_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FI_KERNEL_NAME_SV, "Ange namn på finsk kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_FI_KERNEL_NAME_TR, "Finlandiya Kernal ROM imajýnýn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_FR_KERNEL_NAME,    N_("Specify name of French Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FR_KERNEL_NAME_DA, "Angiv navn på fransk kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_FR_KERNEL_NAME_DE, "Name für französische Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_FR_KERNEL_NAME_FR, "Spécifier le nom de l'image Kernal française"},
/* hu */ {IDCLS_SPECIFY_FR_KERNEL_NAME_HU, "Adja meg a francia Kernal ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_FR_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal francese"},
/* ko */ {IDCLS_SPECIFY_FR_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FR_KERNEL_NAME_NL, "Geef de naam van het Franse Kernal ROM bestand"},
/* ru */ {IDCLS_SPECIFY_FR_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FR_KERNEL_NAME_SV, "Ange namn på fransk kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_FR_KERNEL_NAME_TR, "Fransýz Kernal ROM imajýnýn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_IT_KERNEL_NAME,    N_("Specify name of Italian Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_IT_KERNEL_NAME_DA, "Angiv navn på italiensk kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_IT_KERNEL_NAME_DE, "Name für italienische Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_IT_KERNEL_NAME_FR, "Spécifier le nom de l'image Kernal italienne"},
/* hu */ {IDCLS_SPECIFY_IT_KERNEL_NAME_HU, "Adja meg az olasz Kernal ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_IT_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal italiana"},
/* ko */ {IDCLS_SPECIFY_IT_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_IT_KERNEL_NAME_NL, "Geef de naam van het Italiaanse Kernal ROM bestand"},
/* ru */ {IDCLS_SPECIFY_IT_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_IT_KERNEL_NAME_SV, "Ange namn på italiensk kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_IT_KERNEL_NAME_TR, "Ýtalyan Kernal ROM imajýnýn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_NO_KERNEL_NAME,    N_("Specify name of Norwegian Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_NO_KERNEL_NAME_DA, "Angiv navn på norsk kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_NO_KERNEL_NAME_DE, "Name für norwegische Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_NO_KERNEL_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_NO_KERNEL_NAME_HU, "Adja meg a norvég Kernal ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_NO_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal norvegese"},
/* ko */ {IDCLS_SPECIFY_NO_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_NO_KERNEL_NAME_NL, "Geef de naam van het Noorse Kernal ROM bestand"},
/* ru */ {IDCLS_SPECIFY_NO_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_NO_KERNEL_NAME_SV, "Ange namn på norsk kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_NO_KERNEL_NAME_TR, "Norveç Kernal ROM imajýnýn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_SV_KERNEL_NAME,    N_("Specify name of Swedish Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SV_KERNEL_NAME_DA, "Angiv navn på svensk kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_SV_KERNEL_NAME_DE, "Name für schwedische Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_SV_KERNEL_NAME_FR, "Spécifier le nom de l'image Kernal suédoise"},
/* hu */ {IDCLS_SPECIFY_SV_KERNEL_NAME_HU, "Adja meg s svéd Kernal ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_SV_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal svedese"},
/* ko */ {IDCLS_SPECIFY_SV_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SV_KERNEL_NAME_NL, "Geef de naam van het Zweedse Kernal ROM bestand"},
/* ru */ {IDCLS_SPECIFY_SV_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SV_KERNEL_NAME_SV, "Ange namn på svensk kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_SV_KERNEL_NAME_TR, "Ýsveç Kernal ROM imajýnýn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW,    N_("Specify name of BASIC ROM image (lower part)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_DA, "Angiv navn på BASIC ROM-image (lav del)"},
/* de */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_DE, "Namen für Basic ROM Datei spezifizieren (unterer Teil)"},
/* fr */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_FR, "Spécifier le nom de l'image BASIC ROM (partie basse)"},
/* hu */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_HU, "Adja meg a BASIC ROM képmás nevét (alsó rész)"},
/* it */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_IT, "Specifica il nome immagine della ROM del BASIC (parte inferiore)"},
/* ko */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_NL, "Geef de naam van het BASIC ROM bestand (laag gedeelte)"},
/* ru */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_SV, "Ange namn på BASIC ROM-avbildning (nedre delen)"},
/* tr */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_TR, "BASIC ROM imajýnýn (alt kýsým) ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH,    N_("Specify name of BASIC ROM image (higher part)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_DA, "Angiv navn på BASIC ROM-image (høj del)"},
/* de */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_DE, "Namen für Basic ROM Datei spezifizieren (oberer Teil)"},
/* fr */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_FR, "Spécifier le nom de l'image BASIC ROM (partie haute)"},
/* hu */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_HU, "Adja meg a BASIC ROM képmás nevét (felsõ rész)"},
/* it */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_IT, "Specifica il nome immagine della ROM del BASIC (parte superiore)"},
/* ko */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_NL, "Geef de naam van het BASIC ROM bestand (hoog gedeelte)"},
/* ru */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_SV, "Ange namn på BASIC ROM-avbildning (övre delen)"},
/* tr */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_TR, "BASIC ROM imajýnýn (üst kýsým) ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME,    N_("Specify name of international character generator ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_DA, "Angiv navn på internationalt tegngenerator-ROM-image"},
/* de */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_DE, "Name für internationale Charakter ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_FR, "Spécifier le nom de l'image du générateur de caractères internationaux"},
/* hu */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_HU, "Adja meg a nemzetközi karaktergenerátor ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_IT, "Specifica il nome immagine della ROM del generatore di caratteri internazionale"},
/* ko */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_NL, "Geef de naam van het internationaal CHARGEN ROM bestand"},
/* ru */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_SV, "Ange namn på internationell teckengenerator-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_TR, "Uluslararasý Karakter Oluþturucu ROM imajýnýn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME,    N_("Specify name of German character generator ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_DA, "Angiv navn på tysk tegngenerator-ROM-image"},
/* de */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_DE, "Name für deutsche Charakter ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_FR, "Spécifier le nom de l'image du générateur de caractères allemands"},
/* hu */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_HU, "Adja meg a német karaktergenerátor ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_IT, "Specifica il nome immagine della ROM del generatore di caratteri tedesco"},
/* ko */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_NL, "Geef de naam van het Duitse CHARGEN ROM bestand"},
/* ru */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_SV, "Ange namn på tysk teckengenerator-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_TR, "Alman Karakter Oluþturucu ROM imajýnýn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME,    N_("Specify name of French character generator ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_DA, "Angiv navn på fransk tegngenerator-ROM-image"},
/* de */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_DE, "Name für französische Charakter ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_FR, "Spécifier le nom de l'image du générateur de caractères français"},
/* hu */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_HU, "Adja meg a francia karaktergenerátor ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_IT, "Specifica il nome immagine della ROM del generatore di caratteri francese"},
/* ko */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_NL, "Geef de naam van het Franse CHARGEN ROM bestand"},
/* ru */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_SV, "Ange namn på fransk teckengenerator-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_TR, "Finlandiya Karakter Oluþturucu ROM imajýnýn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME,    N_("Specify name of Swedish character generator ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_DA, "Angiv navn på svensk tegngenerator-ROM-image"},
/* de */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_DE, "Name für schwedische Charakter ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_FR, "Spécifier le nom de l'image du générateur de caractères suédois"},
/* hu */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_HU, "Adja meg a svéd karaktergenerátor ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_IT, "Specifica il nome immagine della ROM del generatore di caratteri svedese"},
/* ko */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_NL, "Geef de naam van het Zweedse CHARGEN ROM bestand"},
/* ru */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_SV, "Ange namn på svensk teckengenerator-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_TR, "Ýsveç Karakter Oluþturucu ROM imajýnýn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME,    N_("Specify name of C64 mode Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_DA, "Angiv navn på C64-kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_DE, "Name für C64 Modus Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_FR, "Spécifier le nom de l'image Kernal du mode C64"},
/* hu */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_HU, "Adja meg a C64 módú Kernal ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_IT, "Specifica il nome immagine della ROM del Kernal in modalità C64"},
/* ko */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_NL, "Geef de naam van het Kernal ROM bestand voor de C64 modus"},
/* ru */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_SV, "Ange namn på C64-kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_TR, "C64 modu Kernal ROM imajýnýn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME,    N_("Specify name of C64 mode BASIC ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_DA, "Angiv navn på C64-BASIC-ROM-image"},
/* de */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_DE, "Name für C64 Modus Basic ROM Datei spezifizieren"},
/* fr */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_FR, "Spécifier le nom de l'image BASIC ROM du mode C64"},
/* hu */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_HU, "Adja meg a C64 módú BASIC ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_IT, "Specifica il nome immagine della ROM in modalità C64"},
/* ko */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_NL, "Geef de naam van het BASIC ROM bestand voor de C64 modus"},
/* ru */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_SV, "Ange namn på C64-BASIC-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_TR, "C64 modu BASIC ROM imajýnýn ismini belirt"},
#endif

/* vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_ENABLE_OEM_JOY,    N_("Enable the OEM userport joystick adapter")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_OEM_JOY_DA, "Aktivér OEM brugerportjoystickadapter"},
/* de */ {IDCLS_ENABLE_OEM_JOY_DE, "OEM Userport Joystick Adapter aktivieren"},
/* fr */ {IDCLS_ENABLE_OEM_JOY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_OEM_JOY_HU, "OEM userport botkormány adapter engedélyezése"},
/* it */ {IDCLS_ENABLE_OEM_JOY_IT, "Attiva adattatore joystick OEM su userport"},
/* ko */ {IDCLS_ENABLE_OEM_JOY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_OEM_JOY_NL, "Activeer de OEM userport joystick adapter"},
/* ru */ {IDCLS_ENABLE_OEM_JOY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_OEM_JOY_SV, "Aktivera OEM-användarportspelportsadapter"},
/* tr */ {IDCLS_ENABLE_OEM_JOY_TR, "OEM userport joystick dönüþtürücüyü aktif et"},
#endif

/* vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_DISABLE_OEM_JOY,    N_("Disable the OEM userport joystick adapter")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_OEM_JOY_DA, "Deaktivér OEM brugerportjoystickadapter"},
/* de */ {IDCLS_DISABLE_OEM_JOY_DE, "OEM Userport Joystick Adapter deaktivieren"},
/* fr */ {IDCLS_DISABLE_OEM_JOY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_OEM_JOY_HU, "OEM userport botkormány adapter tiltása"},
/* it */ {IDCLS_DISABLE_OEM_JOY_IT, "Disattiva adattatore joystick OEM su userport"},
/* ko */ {IDCLS_DISABLE_OEM_JOY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_OEM_JOY_NL, "De OEM userport joystick adapter uitschakelen"},
/* ru */ {IDCLS_DISABLE_OEM_JOY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_OEM_JOY_SV, "Inaktivera OEM-användarportspelportsadapter"},
/* tr */ {IDCLS_DISABLE_OEM_JOY_TR, "OEM userport joystick dönüþtürücüyü pasifleþtir"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_ENABLE_IEE488,    N_("Enable the IEEE488 interface emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEE488_DA, "Aktivér emulering af IEEE488-interface"},
/* de */ {IDCLS_ENABLE_IEE488_DE, "IEEE488 Schnittstellen-Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_IEE488_FR, "Activer l'interface d'émulation IEEE488"},
/* hu */ {IDCLS_ENABLE_IEE488_HU, "IEEE488 interfész emuláció engedélyezése"},
/* it */ {IDCLS_ENABLE_IEE488_IT, "Attiva emulazione interfaccia IEEE488"},
/* ko */ {IDCLS_ENABLE_IEE488_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEE488_NL, "Activeer de IEEE488 interface emulatie"},
/* ru */ {IDCLS_ENABLE_IEE488_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEE488_SV, "Aktivera emulering av IEEE488-gränssnitt"},
/* tr */ {IDCLS_ENABLE_IEE488_TR, "IEEE488 arabirim emülasyonunu aktif et"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_DISABLE_IEE488,    N_("Disable the IEEE488 interface emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEE488_DA, "Deaktivér emulering af IEEE488-interface"},
/* de */ {IDCLS_DISABLE_IEE488_DE, "IEEE488 Schnittstellen-Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEE488_FR, "Désactiver l'interface d'émulation IEEE488"},
/* hu */ {IDCLS_DISABLE_IEE488_HU, "IEEE488 interfész emuláció tiltása"},
/* it */ {IDCLS_DISABLE_IEE488_IT, "Disattiva emulazione interfaccia IEEE488"},
/* ko */ {IDCLS_DISABLE_IEE488_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEE488_NL, "De IEEE488 interface emulatie uitschakelen"},
/* ru */ {IDCLS_DISABLE_IEE488_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEE488_SV, "Inaktivera emulering av IEEE488-gränssnitt"},
/* tr */ {IDCLS_DISABLE_IEE488_TR, "IEEE488 arabirim emülasyonunu pasifleþtir"},
#endif

/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c */
/* en */ {IDCLS_P_REVISION,    N_("<Revision>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_REVISION_DA, "<Udgave>"},
/* de */ {IDCLS_P_REVISION_DE, "<Revision>"},
/* fr */ {IDCLS_P_REVISION_FR, "<Révision>"},
/* hu */ {IDCLS_P_REVISION_HU, "<Változatszám>"},
/* it */ {IDCLS_P_REVISION_IT, "<Revisione>"},
/* ko */ {IDCLS_P_REVISION_KO, "<¼öÁ¤>"},
/* nl */ {IDCLS_P_REVISION_NL, "<Revisie>"},
/* ru */ {IDCLS_P_REVISION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_REVISION_SV, "<Utgåva>"},
/* tr */ {IDCLS_P_REVISION_TR, "<Revizyon>"},
#endif

/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c */
/* en */ {IDCLS_PATCH_KERNAL_TO_REVISION,    N_("Patch the Kernal ROM to the specified <revision>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PATCH_KERNAL_TO_REVISION_DA, "Patch kerne-ROM til den angivne <revision>"},
/* de */ {IDCLS_PATCH_KERNAL_TO_REVISION_DE, "Kernal ROM auf spezifizierte <Revision> verändern"},
/* fr */ {IDCLS_PATCH_KERNAL_TO_REVISION_FR, "Mettre à jour le ROM Kernal à la <revision> spécifiée"},
/* hu */ {IDCLS_PATCH_KERNAL_TO_REVISION_HU, "A Kernal ROM átírása adott <változatra>"},
/* it */ {IDCLS_PATCH_KERNAL_TO_REVISION_IT, "Fai il patch della ROM del Kernal alla <revisione> specificata"},
/* ko */ {IDCLS_PATCH_KERNAL_TO_REVISION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PATCH_KERNAL_TO_REVISION_NL, "Verbeter de Kernal ROM naar de opgegeven <revisie>"},
/* ru */ {IDCLS_PATCH_KERNAL_TO_REVISION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PATCH_KERNAL_TO_REVISION_SV, "Patcha kernal-ROM till angiven <utgåva>"},
/* tr */ {IDCLS_PATCH_KERNAL_TO_REVISION_TR, "Kernal ROM'u belirtilmiþ <revizyon>'a yama"},
#endif

#ifdef HAVE_RS232
/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU,    N_("Enable the ACIA RS232 interface emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU_DE, "ACIA RS232 Schnittstellen-Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU_NL, "Activeer de ACIA RS232 interface emulatie"},
/* ru */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU_SV, "Aktivera ACIA RS232-gränssnittsemulering"},
/* tr */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU_TR, ""},  /* fuzzy */
#endif

/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU,    N_("Disable the ACIA RS232 interface emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_DA, ""},  /* fuzzy */
/* de */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_DE, "ACIA RS232 Schnittstellen-Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_NL, "De ACIA RS232 interface emulatie aflsuiten"},
/* ru */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_SV, "Inaktivera ACIA-RS232-gränssnittsemulering"},
/* tr */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_TR, ""},  /* fuzzy */
#endif
#endif

/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c,
   c64/psid.c, cbm2/cbm2-cmdline-options.c,
   pet/pet-cmdline-options.c, plus4/plus4-cmdline-options.c,
   vdc/vdc-cmdline-options.c, vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_P_NUMBER,    N_("<number>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_NUMBER_DA, "<nummer>"},
/* de */ {IDCLS_P_NUMBER_DE, "<Nummer>"},
/* fr */ {IDCLS_P_NUMBER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_NUMBER_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_NUMBER_IT, "<numero>"},
/* ko */ {IDCLS_P_NUMBER_KO, "<¼ýÀÚ>"},
/* nl */ {IDCLS_P_NUMBER_NL, "<nummer>"},
/* ru */ {IDCLS_P_NUMBER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_NUMBER_SV, "<nummer>"},
/* tr */ {IDCLS_P_NUMBER_TR, "<sayý>"},
#endif

#ifdef COMMON_KBD
/* c128/c128-cmdline-options.c, plus4/plus4-cmdline-options.c,
   vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX,    N_("Specify index of keymap file (0=symbol, 1=positional)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_DA, "Angiv indeks for tastaturindstillingsfil (0=symbolsk, 1=positionsbestemt)"},
/* de */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_DE, "Index für Kymap Datei festlegen (0=symbol, 1=positional)"},
/* fr */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_FR, "Spécifier l'index du fichier keymap (0=symboles, 1=position)"},
/* hu */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_HU, "Adja meg a billentyûzet leképzési módot (0=szimbolikus, 1=pozíció szerinti)"},
/* it */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_IT, "Specifica l'indice del file della mappa della tastiera (0=simbolica, 1=posizionale)"},
/* ko */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_NL, "Geef index van het keymapbestand (0=symbool, 1=positioneel)"},
/* ru */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_SV, "Ange index för för tangentbordsinställningsfil (0=symbolisk, 1=positionsriktig)"},
/* tr */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_TR, "Tuþ haritasý dosyasýnýn indeksini belirt (0=sembol, 1=konumsal)"},
#endif

/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c,
   plus4/plus4-cmdline-options.c, vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME,    N_("Specify name of symbolic keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_DA, "Angiv filnavn for symbolsk tastatur"},
/* de */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_DE, "Bitte Namen für symbolische Keymap Datei definieren"},
/* fr */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_FR, "Spécifier le nom du fichier de mappage clavier symbolique"},
/* hu */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_HU, "Adja meg a szimbolikus leképzésfájl nevét"},
/* it */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_IT, "Specifica il nome del file della mappa simbolica della tastiera"},
/* ko */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_NL, "Geef naam van het symbolisch keymapbestand"},
/* ru */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_SV, "Ange fil för symbolisk tangentbordsemulering"},
/* tr */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_TR, "Sembolik tuþ haritasý dosyasýnýn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c,
   plus4/plus4-cmdline-options.c, vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME,    N_("Specify name of positional keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_DA, "Angiv fil for positionsbestemt tastatur"},
/* de */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_DE, "Bitte Namen für positions Keymap Datei definieren"},
/* fr */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_FR, "Spécifier le nom du fichier de mappage clavier positionnel"},
/* hu */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_HU, "Adja meg a pozíció szerinti leképzésfájl nevét"},
/* it */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_IT, "Specifica il nome del file della mappa posizionale della tastiera"},
/* ko */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_NL, "Geef naam van het positioneel keymapbestand"},
/* ru */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_SV, "Ange fil för positionsriktig tangentbordsemulering"},
/* tr */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_TR, "Konumsal tuþ haritasý dosyasýnýn ismini belirt"},
#endif
#endif

/* c128/c128mmu.c */
/* en */ {IDCLS_ACTIVATE_40_COL_MODE,    N_("Activate 40 column mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ACTIVATE_40_COL_MODE_DA, "Aktivér 40-kolonners tilstand"},
/* de */ {IDCLS_ACTIVATE_40_COL_MODE_DE, "40 Spalten Modus aktivieren"},
/* fr */ {IDCLS_ACTIVATE_40_COL_MODE_FR, "Activer le mode 40 colonnes"},
/* hu */ {IDCLS_ACTIVATE_40_COL_MODE_HU, "40 oszlopos mód aktiválása"},
/* it */ {IDCLS_ACTIVATE_40_COL_MODE_IT, "Attiva modalità a 40 colonne"},
/* ko */ {IDCLS_ACTIVATE_40_COL_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ACTIVATE_40_COL_MODE_NL, "Activeer 40 kolomsmodus"},
/* ru */ {IDCLS_ACTIVATE_40_COL_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ACTIVATE_40_COL_MODE_SV, "Aktivera 40-kolumnersläge"},
/* tr */ {IDCLS_ACTIVATE_40_COL_MODE_TR, "40 sütun modunu aktif et"},
#endif

/* c128/c128mmu.c */
/* en */ {IDCLS_ACTIVATE_80_COL_MODE,    N_("Activate 80 column mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ACTIVATE_80_COL_MODE_DA, "Aktivér 80-kolonners tilstand"},
/* de */ {IDCLS_ACTIVATE_80_COL_MODE_DE, "80 Spalten Modus aktivieren"},
/* fr */ {IDCLS_ACTIVATE_80_COL_MODE_FR, "Activer le mode 80 colonnes"},
/* hu */ {IDCLS_ACTIVATE_80_COL_MODE_HU, "80 oszlopos mód aktiválása"},
/* it */ {IDCLS_ACTIVATE_80_COL_MODE_IT, "Attiva modalità a 80 colonne"},
/* ko */ {IDCLS_ACTIVATE_80_COL_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ACTIVATE_80_COL_MODE_NL, "Activeer 80 kolomsmodus"},
/* ru */ {IDCLS_ACTIVATE_80_COL_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ACTIVATE_80_COL_MODE_SV, "Aktivera 80-kolumnersläge"},
/* tr */ {IDCLS_ACTIVATE_80_COL_MODE_TR, "80 sütun modunu aktif et"},
#endif

/* c128/c128mmu.c */
/* en */ {IDCLS_GO64_MODE,    N_("Always switch to C64 mode on reset")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_GO64_MODE_DA, "Skift altid til C64-tilstand ved reset"},
/* de */ {IDCLS_GO64_MODE_DE, "Immer bei Reset in C64 Modus schalten"},
/* fr */ {IDCLS_GO64_MODE_FR, "Toujours revenir au mode C64 au redémarrage"},
/* hu */ {IDCLS_GO64_MODE_HU, "Mindig C64 módban újraindítás után"},
/* it */ {IDCLS_GO64_MODE_IT, "Cambia sempre in modalita C64 al reset"},
/* ko */ {IDCLS_GO64_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_GO64_MODE_NL, "Start altijd op in C64 modus na reset"},
/* ru */ {IDCLS_GO64_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_GO64_MODE_SV, "Växla alltid till C64-läge vid återställning"},
/* tr */ {IDCLS_GO64_MODE_TR, "Resetlendiðinde her zaman C64 moduna geç"},
#endif

/* c128/c128mmu.c */
/* en */ {IDCLS_GO128_MODE,    N_("Always switch to C128 mode on reset")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_GO128_MODE_DA, "Skift altid til C128-tilstand ved reset"},
/* de */ {IDCLS_GO128_MODE_DE, "Immer be Reset in C128 Modus schalten"},
/* fr */ {IDCLS_GO128_MODE_FR, "Toujours revenir au mode C128 au redémarrage"},
/* hu */ {IDCLS_GO128_MODE_HU, "Mindig C128 mód újraindítás után"},
/* it */ {IDCLS_GO128_MODE_IT, "Cambia sempre in modalita C128 al reset"},
/* ko */ {IDCLS_GO128_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_GO128_MODE_NL, "Start altijd op in C128 modus na reset"},
/* ru */ {IDCLS_GO128_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_GO128_MODE_SV, "Växla alltid till C128-läge vid återställning"},
/* tr */ {IDCLS_GO128_MODE_TR, "Resetlendiðinde her zaman C128 moduna geç"},
#endif

/* c128/functionrom.c */
/* en */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME,    N_("Specify name of internal Function ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_DA, "Angiv navn på internt funktions-ROM-image"},
/* de */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_DE, "Name der internen Funktions ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_FR, "Spécifier le nom de l'image ROM des fonctions internes"},
/* hu */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_HU, "Adja meg a belsõ Function ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_IT, "Specifica il nome immagine della Function ROM interna"},
/* ko */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_NL, "Geef de naam van het intern functie ROM bestand"},
/* ru */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_SV, "Ange namn på intern funktions-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_TR, "Dahili Function ROM imajýnýn ismini belirt"},
#endif

/* c128/functionrom.c */
/* en */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME,    N_("Specify name of external Function ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_DA, "Angiv navn på externt funktions-ROM-image"},
/* de */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_DE, "Name der externen Funktions ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_FR, "Spécifier le nom de l'image ROM des fonctions externes"},
/* hu */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_HU, "Adja meg a külsõ Function ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_IT, "Specifica il nome immagine della Function ROM esterna"},
/* ko */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_NL, "Geef de naam van het extern functie ROM bestand"},
/* ru */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_SV, "Ange namn på extern funktions-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_TR, "Harici Function ROM imajýnýn ismini belirt"},
#endif

/* c128/functionrom.c */
/* en */ {IDCLS_ENABLE_INT_FUNC_ROM,    N_("Enable the internal Function ROM")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_INT_FUNC_ROM_DA, "Aktivér intern funktions-ROM"},
/* de */ {IDCLS_ENABLE_INT_FUNC_ROM_DE, "Internes Funktions ROM aktivieren"},
/* fr */ {IDCLS_ENABLE_INT_FUNC_ROM_FR, "Activer l'image ROM des fonctions internes"},
/* hu */ {IDCLS_ENABLE_INT_FUNC_ROM_HU, "Belsõ Function ROM engedélyezése"},
/* it */ {IDCLS_ENABLE_INT_FUNC_ROM_IT, "Attiva la Function ROM interna"},
/* ko */ {IDCLS_ENABLE_INT_FUNC_ROM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_INT_FUNC_ROM_NL, "Activeer de interne functie ROM"},
/* ru */ {IDCLS_ENABLE_INT_FUNC_ROM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_INT_FUNC_ROM_SV, "Aktivera internt funktions-ROM"},
/* tr */ {IDCLS_ENABLE_INT_FUNC_ROM_TR, "Dahili Function ROM'u aktif et"},
#endif

/* c128/functionrom.c */
/* en */ {IDCLS_DISABLE_INT_FUNC_ROM,    N_("Disable the internal Function ROM")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_INT_FUNC_ROM_DA, "Deaktivér intern funktions-ROM"},
/* de */ {IDCLS_DISABLE_INT_FUNC_ROM_DE, "Internes Funktions ROM deaktivieren"},
/* fr */ {IDCLS_DISABLE_INT_FUNC_ROM_FR, "Désactiver l'image ROM des fonctions internes"},
/* hu */ {IDCLS_DISABLE_INT_FUNC_ROM_HU, "Belsõ Function ROM tiltása"},
/* it */ {IDCLS_DISABLE_INT_FUNC_ROM_IT, "Disattiva la Function ROM interna"},
/* ko */ {IDCLS_DISABLE_INT_FUNC_ROM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_INT_FUNC_ROM_NL, "De interne functie ROM uitschakelen"},
/* ru */ {IDCLS_DISABLE_INT_FUNC_ROM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_INT_FUNC_ROM_SV, "Inaktivera internt funktions-ROM"},
/* tr */ {IDCLS_DISABLE_INT_FUNC_ROM_TR, "Dahili Function ROM'u pasifleþtir"},
#endif

/* c128/functionrom.c */
/* en */ {IDCLS_ENABLE_EXT_FUNC_ROM,    N_("Enable the external Function ROM")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_EXT_FUNC_ROM_DA, "Aktivér extern funktions-ROM"},
/* de */ {IDCLS_ENABLE_EXT_FUNC_ROM_DE, "Externes Funktions ROM aktivieren"},
/* fr */ {IDCLS_ENABLE_EXT_FUNC_ROM_FR, "Activer l'image ROM des fonctions externes"},
/* hu */ {IDCLS_ENABLE_EXT_FUNC_ROM_HU, "Külsõ Function ROM engedélyezése"},
/* it */ {IDCLS_ENABLE_EXT_FUNC_ROM_IT, "Attiva la Function ROM esterna"},
/* ko */ {IDCLS_ENABLE_EXT_FUNC_ROM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_EXT_FUNC_ROM_NL, "Activeer de externe functie ROM"},
/* ru */ {IDCLS_ENABLE_EXT_FUNC_ROM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_EXT_FUNC_ROM_SV, "Aktivera externt funktions-ROM"},
/* tr */ {IDCLS_ENABLE_EXT_FUNC_ROM_TR, "Harici Function ROM'u aktif et"},
#endif

/* c128/functionrom.c */
/* en */ {IDCLS_DISABLE_EXT_FUNC_ROM,    N_("Disable the external Function ROM")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_EXT_FUNC_ROM_DA, "Deaktivér extern funktions-ROM"},
/* de */ {IDCLS_DISABLE_EXT_FUNC_ROM_DE, "Externes Funktions ROM deaktivieren"},
/* fr */ {IDCLS_DISABLE_EXT_FUNC_ROM_FR, "Désactiver l'image ROM des fonctions externes"},
/* hu */ {IDCLS_DISABLE_EXT_FUNC_ROM_HU, "Külsõ Function ROM tiltása"},
/* it */ {IDCLS_DISABLE_EXT_FUNC_ROM_IT, "Disattiva la Function ROM esterna"},
/* ko */ {IDCLS_DISABLE_EXT_FUNC_ROM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_EXT_FUNC_ROM_NL, "De externe functie ROM uitschakelen"},
/* ru */ {IDCLS_DISABLE_EXT_FUNC_ROM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_EXT_FUNC_ROM_SV, "Inaktivera externt funktions-ROM"},
/* tr */ {IDCLS_DISABLE_EXT_FUNC_ROM_TR, "Harici Function ROM'u pasifleþtir"},
#endif

/* c64/c64-cmdline-options.c, c64/psid.c */
/* en */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR,    N_("Use old NTSC sync factor")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_DA, "Anvend gammel NTSC-synkfaktor"},
/* de */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_DE, "Alten NTSC Sync Faktor verwenden"},
/* fr */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_FR, "Utiliser l'ancien mode NTSC"},
/* hu */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_HU, "Régi NTSC szinkron faktor használata"},
/* it */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_IT, "Usa il vecchio fattore di sincronizzazione NTSC"},
/* ko */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_NL, "Gebruik oude NTSC synchronisatiefactor"},
/* ru */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_SV, "Använd gammal NTSC-synkfaktor"},
/* tr */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_TR, "Eski NTSC senkron faktörü kullan"},
#endif

/* c64/c64-cmdline-options.c, viciisc/vicii-cmdline-options.c */
/* en */ {IDCLS_P_MODEL,    N_("<Model>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_MODEL_DA, "<Model>"},
/* de */ {IDCLS_P_MODEL_DE, "<Modell>"},
/* fr */ {IDCLS_P_MODEL_FR, "<Modèle>"},
/* hu */ {IDCLS_P_MODEL_HU, "<Modell>"},
/* it */ {IDCLS_P_MODEL_IT, "<Modello>"},
/* ko */ {IDCLS_P_MODEL_KO, "<¸ðµ¨>"},
/* nl */ {IDCLS_P_MODEL_NL, "<Model>"},
/* ru */ {IDCLS_P_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_MODEL_SV, "<Modell>"},
/* tr */ {IDCLS_P_MODEL_TR, "<Model>"},
#endif

/* c64/c64-cmdline-options.c */
/* en */ {IDCLS_SET_BOTH_CIA_MODELS,    N_("Set both CIA models (0 = old 6526, 1 = new 6526A)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_BOTH_CIA_MODELS_DA, "Vælg type for begge CIA-kredse (0=gammel 6526, 1=ny 6526A)"},
/* de */ {IDCLS_SET_BOTH_CIA_MODELS_DE, "Wähle beide CIA Modelle (0 = alt 6526, 1 = neu 6526A)"},
/* fr */ {IDCLS_SET_BOTH_CIA_MODELS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_BOTH_CIA_MODELS_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_BOTH_CIA_MODELS_IT, "Imposta entrambi i modelli CIA (0 = 6526 vecchio, 1 = 6526A nuovo)"},
/* ko */ {IDCLS_SET_BOTH_CIA_MODELS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_BOTH_CIA_MODELS_NL, "Zet model voor beide CIAs (0 = oud 6526, 1 = nieuw 6526A)"},
/* ru */ {IDCLS_SET_BOTH_CIA_MODELS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_BOTH_CIA_MODELS_SV, "Välj båda CIA-modellerna (0 = gammal 6526, 1 = ny 2526A)"},
/* tr */ {IDCLS_SET_BOTH_CIA_MODELS_TR, "Her iki CIA modelini belirle (0 = eski 6526, 1 = yeni 6526A)"},
#endif

/* c64/c64-cmdline-options.c */
/* en */ {IDCLS_SET_CIA1_MODEL,    N_("Set CIA 1 model (0 = old 6526, 1 = new 6526A)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_CIA1_MODEL_DA, "Vælg CIA 1 type (0=gammel 6526, 1=ny 6526A)"},
/* de */ {IDCLS_SET_CIA1_MODEL_DE, "Wähle CIA 1 Modell (0 = alt 6526, 1 = neu 6526A)"},
/* fr */ {IDCLS_SET_CIA1_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_CIA1_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_CIA1_MODEL_IT, "Imposta modello CIA 1 (0 = 6526 vecchio, 1 = 6526A nuovo)"},
/* ko */ {IDCLS_SET_CIA1_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_CIA1_MODEL_NL, "Zet CIA 1 model (0 = oud 6526, 1 = nieuw 6526A)"},
/* ru */ {IDCLS_SET_CIA1_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_CIA1_MODEL_SV, "Välj CIA 1-modell (0 = gammal 6526, 1 = ny 2526A)"},
/* tr */ {IDCLS_SET_CIA1_MODEL_TR, "CIA 1 modelini belirle (0 = eski 6526, 1 = yeni 6526A)"},
#endif

/* c64/c64-cmdline-options.c */
/* en */ {IDCLS_SET_CIA2_MODEL,    N_("Set CIA 2 model (0 = old 6526, 1 = new 6526A)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_CIA2_MODEL_DA, "Vælg CIA 2 type (0=gammel 6526, 1=ny 6526A)"},
/* de */ {IDCLS_SET_CIA2_MODEL_DE, "Wähle CIA 2 Modell (0 = alt 6526, 1 = neu 6526A)\""},
/* fr */ {IDCLS_SET_CIA2_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_CIA2_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_CIA2_MODEL_IT, "Imposta modello CIA 2 (0 = 6526 vecchio, 1 = 6526A nuovo)"},
/* ko */ {IDCLS_SET_CIA2_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_CIA2_MODEL_NL, "Zet CIA 2 model (0 = oud 6526, 1 = nieuw 6526A)"},
/* ru */ {IDCLS_SET_CIA2_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_CIA2_MODEL_SV, "Välj CIA 2-modell (0 = gammal 6526, 1 = ny 2526A)"},
/* tr */ {IDCLS_SET_CIA2_MODEL_TR, "CIA 2 modelini belirle (0 = eski 6526, 1 = yeni 6526A)"},
#endif

/* c64/c64-cmdline-options.c */
/* en */ {IDCLS_SET_C64_MODEL,    N_("Set C64 model (c64/c64c/c64old, ntsc/newntsc/oldntsc, drean)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_C64_MODEL_DA, "Vælg C64 model (c64/c64c/c64old, ntsc/newntsc/oldntsc, drean)"},
/* de */ {IDCLS_SET_C64_MODEL_DE, "Wähle C64 Modell (c64/c64c/c64alt/c64ntsc/c64cntsc/c64oldntsc/drean)"},
/* fr */ {IDCLS_SET_C64_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_C64_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_C64_MODEL_IT, "Imposta modello C64 (c64/c64c/c64old, ntsc/newntsc/oldntsc, drean)"},
/* ko */ {IDCLS_SET_C64_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_C64_MODEL_NL, "Zet C64 model (c64/c64c/c64old, ntsc/newntsc/oldntsc, drean)"},
/* ru */ {IDCLS_SET_C64_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_C64_MODEL_SV, "Välj C64-modell (c64/c64c/c64old, ntsc/newntsc/oldntsc, drean)"},
/* tr */ {IDCLS_SET_C64_MODEL_TR, "C64 modelini belirle (c64/c64c/c64eski, ntsc/yenintsc/eskintsc, drean)"},
#endif

/* c64/c64-cmdline-options.c, cbm2/cbm2-cmdline-options.c,
   pet/pet-cmdline-options.c, plus4/plus4-cmdline-options.c,
   vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_KERNAL_ROM_NAME,    N_("Specify name of Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_DA, "Angiv navn på kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_DE, "Name von Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_FR, "Spécifier le nom de l'image ROM Kernal"},
/* hu */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_HU, "Adja meg a Kernal ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_IT, "Specifica il nome immagine della ROM del Kernal"},
/* ko */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_NL, "Geef de naam van het Kernal ROM bestand"},
/* ru */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_SV, "Ange namn på kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_TR, "Kernal ROM imajýnýn ismini belirt"},
#endif

/* c64/c64-cmdline-options.c, cbm2/cbm2-cmdline-options.c,
   pet/pet-cmdline-options.c, plus4/plus4-cmdline-options.c,
   vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BASIC_ROM_NAME,    N_("Specify name of BASIC ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BASIC_ROM_NAME_DA, "Angiv navn på BASIC-ROM-image"},
/* de */ {IDCLS_SPECIFY_BASIC_ROM_NAME_DE, "Name von Basic ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_BASIC_ROM_NAME_FR, "Spécifier le nom de l'image BASIC ROM"},
/* hu */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HU, "Adja meg a BASIC ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_BASIC_ROM_NAME_IT, "Specifica il nome immagine della ROM del BASIC"},
/* ko */ {IDCLS_SPECIFY_BASIC_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BASIC_ROM_NAME_NL, "Geef de naam van het BASIC ROM bestand"},
/* ru */ {IDCLS_SPECIFY_BASIC_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BASIC_ROM_NAME_SV, "Ange namn på BASIC-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_BASIC_ROM_NAME_TR, "BASIC ROM imajýnýn ismini belirt"},
#endif

/* c64/c64-cmdline-options.c, cbm2/cbm2-cmdline-options.c,
   pet/pet-cmdline-options.c, vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME,    N_("Specify name of character generator ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_DA, "Angiv navn på BASIC-ROM-image"},
/* de */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_DE, "Name von Druckerausgabe Datei definieren (print.dump)"},
/* fr */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_FR, "Spécifier le nom de l'image du générateur de caractères"},
/* hu */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_HU, "Adja meg a karaktergenerátor ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_IT, "Specifica il nome della ROM del generatore di caratteri"},
/* ko */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_NL, "Geef de naam van het CHARGEN ROM bestand"},
/* ru */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_SV, "Ange namn på teckengenerator-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_TR, "Karakter Oluþturucu ROM imajýnýn ismini belirt"},
#endif

#ifdef COMMON_KBD
/* c64/c64-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2,    N_("Specify index of keymap file (0=sym, 1=symDE, 2=pos)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_DA, "Angiv indeks for tastaturindstillingsfil (0=symbolsk, 1=symbolsk tysk, 2=positionsbestemt)"},
/* de */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_DE, "Index für Keymap Datei festlegen (0=symbol, 1=symDE, 2=positional)"},
/* fr */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_FR, "Spécifier l'index du fichier keymap (0=sym, 1=symDE, 2=pos)"},
/* hu */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_HU, "Adja meg a billentyûzet leképzési fájl típusát (0=szimbolikus, 1=német szimbolikus, 2=pozíció szerinti)"},
/* it */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_IT, "Specifica l'indice del file della mappa della tastiera (0=sim, 1=simGER, 2=pos)"},
/* ko */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_NL, "Geef de index van het keymapbestand (0=sym, 1=symDE, 2=pos)"},
/* ru */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_SV, "Ange index för för tangentbordsinställningsfil (0=symbolisk, 1=symbolisk tysk, 2=positionsriktig)"},
/* tr */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_TR, "Tuþ haritasý dosyasýnýn indeksini belirt (0=sembol, 1=sembol Almanca, 2=konumsal)"},
#endif

/* c64/c64-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP,    N_("Specify name of symbolic German keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_DA, "Angiv fil for tysk symbolsk tastaturindstilling"},
/* de */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_DE, "Name von symbolischer Keymap Datei definieren"},
/* fr */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_FR, "Spécifier le nom du fichier symbolique de mappage clavier"},
/* hu */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_HU, "Adja meg a nevét a német billentyûzet leképzés fájlnak"},
/* it */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_IT, "Specifica il nome del file della mappa simbolica della tastiera tedesca"},
/* ko */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_NL, "Geef de naam van het symbolische Duitse keymapbestand"},
/* ru */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_SV, "Ange fil för tysk symbolisk tangentbordsemulering"},
/* tr */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_TR, "Sembolik Almanca tuþ haritasý dosyasýnýn ismini belirt"},
#endif
#endif

/* c64/c64gluelogic.c */
/* en */ {IDCLS_SET_GLUE_LOGIC_TYPE,    N_("Set glue logic type (0 = discrete, 1 = 252535-01)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_GLUE_LOGIC_TYPE_DA, "Vælg glue logic type (0=diskret, 1=252535-01)"},
/* de */ {IDCLS_SET_GLUE_LOGIC_TYPE_DE, "Setze Glue-Lokig Typ (0 = diskret, 1 = 252535-01)"},
/* fr */ {IDCLS_SET_GLUE_LOGIC_TYPE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_GLUE_LOGIC_TYPE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_GLUE_LOGIC_TYPE_IT, "Imposta il tipo di glue logic (0 = discreta, 1 = 252535-01)"},
/* ko */ {IDCLS_SET_GLUE_LOGIC_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_GLUE_LOGIC_TYPE_NL, "Zet lijk logica soort (0 = discreet, 1 = 252535-01)"},
/* ru */ {IDCLS_SET_GLUE_LOGIC_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_GLUE_LOGIC_TYPE_SV, "Välj typ av klisterlogik (0 = diskret, 1 = 252535-01)"},
/* tr */ {IDCLS_SET_GLUE_LOGIC_TYPE_TR, "Glue logic tipini ayarla (0 = baðlantýyý kes, 1 = 252535-01)"},
#endif

/* c64dtv/c64dtv-cmdline-options.c */
/* en */ {IDCLS_ENABLE_HUMMER_ADC,    N_("Enable Hummer ADC")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_HUMMER_ADC_DA, "Aktivér Hummer ADC"},
/* de */ {IDCLS_ENABLE_HUMMER_ADC_DE, "Hummer ADC Aktivieren"},
/* fr */ {IDCLS_ENABLE_HUMMER_ADC_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_HUMMER_ADC_HU, "Hummer ADC engedélyezése"},
/* it */ {IDCLS_ENABLE_HUMMER_ADC_IT, "Attiva Hummer ADC"},
/* ko */ {IDCLS_ENABLE_HUMMER_ADC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_HUMMER_ADC_NL, "Activeer Hummer ADC"},
/* ru */ {IDCLS_ENABLE_HUMMER_ADC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_HUMMER_ADC_SV, "Aktivera Hummer-A/D-omvandlare"},
/* tr */ {IDCLS_ENABLE_HUMMER_ADC_TR, "Hummer ADC'yi aktif et"},
#endif

/* c64dtv/c64dtv-cmdline-options.c */
/* en */ {IDCLS_DISABLE_HUMMER_ADC,    N_("Disable Hummer ADC")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_HUMMER_ADC_DA, "Deaktivér Hummer ADC"},
/* de */ {IDCLS_DISABLE_HUMMER_ADC_DE, "Hummer ADC deaktivieren"},
/* fr */ {IDCLS_DISABLE_HUMMER_ADC_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_HUMMER_ADC_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_HUMMER_ADC_IT, "Disattiva Hummer ADC"},
/* ko */ {IDCLS_DISABLE_HUMMER_ADC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_HUMMER_ADC_NL, "Hummer ADC uitschakelen"},
/* ru */ {IDCLS_DISABLE_HUMMER_ADC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_HUMMER_ADC_SV, "Inaktivera Hummer-A/D-omvandlare"},
/* tr */ {IDCLS_DISABLE_HUMMER_ADC_TR, "Hummer ADC'yi pasifleþtir"},
#endif

/* c64/cart/c64tpi.c */
/* en */ {IDCLS_ENABLE_IEEE488_INTERFACE,    N_("Enable the IEEE488 interface emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEEE488_INTERFACE_DA, "Aktivér emulering af IEEE488-interface"},
/* de */ {IDCLS_ENABLE_IEEE488_INTERFACE_DE, "IEEE488 Schnittstellen-Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_IEEE488_INTERFACE_FR, "Activer l'interface d'émulation IEEE488"},
/* hu */ {IDCLS_ENABLE_IEEE488_INTERFACE_HU, "IEEE488 interfész emuláció engedélyezése"},
/* it */ {IDCLS_ENABLE_IEEE488_INTERFACE_IT, "Attiva emulazione interfaccia IEEE488"},
/* ko */ {IDCLS_ENABLE_IEEE488_INTERFACE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEEE488_INTERFACE_NL, "Activeer de IEEE488 interface emulatie"},
/* ru */ {IDCLS_ENABLE_IEEE488_INTERFACE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEEE488_INTERFACE_SV, "Aktivera emulering av IEEE488-gränssnitt"},
/* tr */ {IDCLS_ENABLE_IEEE488_INTERFACE_TR, "IEEE488 arabirim emülasyonunu aktif et"},
#endif

/* c64/cart/c64tpi.c */
/* en */ {IDCLS_DISABLE_IEEE488_INTERFACE,    N_("Disable the IEEE488 interface emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEEE488_INTERFACE_DA, "Deaktivér emulering af IEEE488-interface"},
/* de */ {IDCLS_DISABLE_IEEE488_INTERFACE_DE, "IEEE488 Schnittstellen-Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEEE488_INTERFACE_FR, "Désactiver l'interface d'émulation IEEE488"},
/* hu */ {IDCLS_DISABLE_IEEE488_INTERFACE_HU, "IEEE488 interfész emuláció tiltása"},
/* it */ {IDCLS_DISABLE_IEEE488_INTERFACE_IT, "Disattiva emulazione interfaccia IEEE488"},
/* ko */ {IDCLS_DISABLE_IEEE488_INTERFACE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEEE488_INTERFACE_NL, "De IEEE488 interface emulatie uitschakelen"},
/* ru */ {IDCLS_DISABLE_IEEE488_INTERFACE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEEE488_INTERFACE_SV, "Inaktivera emulering av IEEE488-gränssnitt"},
/* tr */ {IDCLS_DISABLE_IEEE488_INTERFACE_TR, "IEEE488 arabirim emülasyonunu pasifleþtir"},
#endif

/* c64/cart/c64tpi.c */
/* en */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME,    N_("specify IEEE488 interface image name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME_DA, "angiv IEEE488-interface image navn"},
/* de */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME_DE, "IEEE488 Schnittstellenmodul Imagename"},
/* fr */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME_IT, "specifica il nome immagine dell'interfaccia IEEE488"},
/* ko */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME_NL, "Geef de naam van het IEEE488 interface bestand"},
/* ru */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME_SV, "ange namn på IEEE488-gränssnittsfil"},
/* tr */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME_TR, "IEEE488 arabirimi imaj ismini belirleyin"},
#endif

/* c64/cart/georam.c */
/* en */ {IDCLS_ENABLE_GEORAM,    N_("Enable the GEO-RAM expansion unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_GEORAM_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ENABLE_GEORAM_DE, "GEO-RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_GEORAM_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_GEORAM_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_GEORAM_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ENABLE_GEORAM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_GEORAM_NL, "Activeer de GEO-RAM uitbreidingseenheid"},
/* ru */ {IDCLS_ENABLE_GEORAM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_GEORAM_SV, "Aktivera GEORAM-expansionsenhet"},
/* tr */ {IDCLS_ENABLE_GEORAM_TR, ""},  /* fuzzy */
#endif

/* c64/cart/georam.c */
/* en */ {IDCLS_DISABLE_GEORAM,    N_("Disable the GEO-RAM expansion unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_GEORAM_DA, ""},  /* fuzzy */
/* de */ {IDCLS_DISABLE_GEORAM_DE, "GEO-RAM Erweiterung deaktivieren"},
/* fr */ {IDCLS_DISABLE_GEORAM_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_GEORAM_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_GEORAM_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_DISABLE_GEORAM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_GEORAM_NL, "De GEO-RAM uitbreidingseenheid uitschakelen"},
/* ru */ {IDCLS_DISABLE_GEORAM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_GEORAM_SV, "Inaktivera GEO RAM-expansionsenhet"},
/* tr */ {IDCLS_DISABLE_GEORAM_TR, ""},  /* fuzzy */
#endif

/* c64/cart/georam.c */
/* en */ {IDCLS_SPECIFY_GEORAM_NAME,    N_("Specify name of GEORAM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_GEORAM_NAME_DA, "Angiv navn på GEORAM-image"},
/* de */ {IDCLS_SPECIFY_GEORAM_NAME_DE, "GEORAM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_GEORAM_NAME_FR, "Spécifier le nom de l'image GEORAM"},
/* hu */ {IDCLS_SPECIFY_GEORAM_NAME_HU, "Adja meg a GEORAM képmás nevét"},
/* it */ {IDCLS_SPECIFY_GEORAM_NAME_IT, "Specifica il nome immagine GEORAM"},
/* ko */ {IDCLS_SPECIFY_GEORAM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_GEORAM_NAME_NL, "Geef de naam van het GEORAM bestand"},
/* ru */ {IDCLS_SPECIFY_GEORAM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_GEORAM_NAME_SV, "Ange namn på GEORAM-avbildning"},
/* tr */ {IDCLS_SPECIFY_GEORAM_NAME_TR, "GEORAM imajýnýn ismini belirt"},
#endif

/* c64/cart/georam.c */
/* en */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE,    N_("Allow writing to GEORAM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_DA, "Tillad skrivning til GEORAM-image."},
/* de */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_DE, "Schreibzugriff auf GEORAM Image erlauben"},
/* fr */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_IT, "Attiva la scrittura su immagine GEORAM"},
/* ko */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_NL, "Aktiveer schrijven naar GEORAM bestand"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_SV, "Tillåt skrivning till GEORAM-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_TR, "GEORAM imajýna yazmayý aktif et"},
#endif

/* c64/cart/georam.c */
/* en */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE,    N_("Do not write to GEORAM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_DA, "Skriv ikke til GEORAM-image"},
/* de */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_DE, "Kein Schreibzugriff auf GEORAM Image"},
/* fr */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_IT, "Disattiva la scrittura su immagine GEORAM"},
/* ko */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_NL, "Schrijf niet naar GEORAM bestand"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_SV, "Skriv inte till GEORAM-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_TR, "GEORAM imajýna yazma"},
#endif

/* c64/cart/georam.c, c64/cart/ramcart.c, c64/cart/reu.c, pet/petreu.c */
/* en */ {IDCLS_P_SIZE_IN_KB,    N_("<size in KB>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_SIZE_IN_KB_DA, "<størrelse i KB>"},
/* de */ {IDCLS_P_SIZE_IN_KB_DE, "<Größe in KB>"},
/* fr */ {IDCLS_P_SIZE_IN_KB_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_SIZE_IN_KB_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_SIZE_IN_KB_IT, "<dimensione in KB>"},
/* ko */ {IDCLS_P_SIZE_IN_KB_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_SIZE_IN_KB_NL, "<grootte in KB>"},
/* ru */ {IDCLS_P_SIZE_IN_KB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_SIZE_IN_KB_SV, "<storlek i KB>"},
/* tr */ {IDCLS_P_SIZE_IN_KB_TR, "<KB cinsinden boyut>"},
#endif

/* c64/cart/georam.c */
/* en */ {IDCLS_GEORAM_SIZE,    N_("Size of the GEORAM expansion unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_GEORAM_SIZE_DA, "Størrelse af GEORAM-udviddelsesenhed"},
/* de */ {IDCLS_GEORAM_SIZE_DE, "Größe der GEORAM Erweiterung"},
/* fr */ {IDCLS_GEORAM_SIZE_FR, "Taille de l'unité d'expansion GEORAM"},
/* hu */ {IDCLS_GEORAM_SIZE_HU, "GEORAM Expansion Unit mérete"},
/* it */ {IDCLS_GEORAM_SIZE_IT, "Dimensione dell'espansione GEORAM"},
/* ko */ {IDCLS_GEORAM_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_GEORAM_SIZE_NL, "Grootte van de GEORAM uitbreidingseenheid"},
/* ru */ {IDCLS_GEORAM_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_GEORAM_SIZE_SV, "Storlek på GEORAM-expansionsenhet"},
/* tr */ {IDCLS_GEORAM_SIZE_TR, "GEORAM geniþletme biriminin boyutu"},
#endif

/* pet/petreu.c */
/* en */ {IDCLS_ENABLE_PETREU,    N_("Enable the PET Ram and Expansion Unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PETREU_DA, "Aktivér PET REU"},
/* de */ {IDCLS_ENABLE_PETREU_DE, "PET RAM Speicher und Erweiterungsmodul aktivieren"},
/* fr */ {IDCLS_ENABLE_PETREU_FR, "Activer l'expansion d'unité et de RAM du PET"},
/* hu */ {IDCLS_ENABLE_PETREU_HU, "PET RAM and Expansion Unit engedélyezése"},
/* it */ {IDCLS_ENABLE_PETREU_IT, "Attiva la RAM e l'unità di espansione del PET"},
/* ko */ {IDCLS_ENABLE_PETREU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_PETREU_NL, "Activeer de PET RAM en uitbreidingseenheid"},
/* ru */ {IDCLS_ENABLE_PETREU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PETREU_SV, "Aktivera PET Ram- och -expansionsenhet"},
/* tr */ {IDCLS_ENABLE_PETREU_TR, "PET Ram ve Geniþletme Birimi'ni aktif et"},
#endif

/* pet/petreu.c */
/* en */ {IDCLS_DISABLE_PETREU,    N_("Disable the PET Ram and Expansion Unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PETREU_DA, "Deaktivér PET REU"},
/* de */ {IDCLS_DISABLE_PETREU_DE, "PET RAM Speicher und Erweiterungsmodul dektivieren"},
/* fr */ {IDCLS_DISABLE_PETREU_FR, "Désactiver l'expansion d'unité et de RAM du PET"},
/* hu */ {IDCLS_DISABLE_PETREU_HU, "PET RAM and Expansion Unit tiltása"},
/* it */ {IDCLS_DISABLE_PETREU_IT, "Disattiva la RAM e l'unità di espansione del PET"},
/* ko */ {IDCLS_DISABLE_PETREU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PETREU_NL, "De PET RAM en uitbreidingseenheid uitschakelen"},
/* ru */ {IDCLS_DISABLE_PETREU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PETREU_SV, "Inaktivera PET Ram- och -expansionsenhet"},
/* tr */ {IDCLS_DISABLE_PETREU_TR, "PET Ram ve Geniþletme Birimi'ni pasifleþtir"},
#endif

/* pet/petreu.c */
/* en */ {IDCLS_SPECIFY_PETREU_NAME,    N_("Specify name of PET Ram and Expansion Unit image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PETREU_NAME_DA, "Angiv navn på PET REU-image"},
/* de */ {IDCLS_SPECIFY_PETREU_NAME_DE, "Namen für PET RAM Speicher und Erweiterungsmodul definieren"},
/* fr */ {IDCLS_SPECIFY_PETREU_NAME_FR, "Spécifier le nom de l'image d’unité d'expansion RAM"},
/* hu */ {IDCLS_SPECIFY_PETREU_NAME_HU, "Adja meg a PET RAM and Expansion Unit képmás nevét"},
/* it */ {IDCLS_SPECIFY_PETREU_NAME_IT, "Specifica il nome immagine della RAM e dell'unità di espansione del PET"},
/* ko */ {IDCLS_SPECIFY_PETREU_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PETREU_NAME_NL, "Geef de naam van het PET RAM en uitbreidingseenheid bestand"},
/* ru */ {IDCLS_SPECIFY_PETREU_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PETREU_NAME_SV, "Ange namn på PET Ram- och -expansionsenhet"},
/* tr */ {IDCLS_SPECIFY_PETREU_NAME_TR, "PET Ram ve Geniþletme Birimi'nin ismini belirt"},
#endif

/* pet/petreu.c */
/* en */ {IDCLS_PETREU_SIZE,    N_("Size of the PET Ram and Expansion Unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PETREU_SIZE_DA, "Størrelse på PET REU"},
/* de */ {IDCLS_PETREU_SIZE_DE, "Größe des PET RAM Speicher und Erweiterungsmodul"},
/* fr */ {IDCLS_PETREU_SIZE_FR, "Taille de l'unité d'expansion RAM"},
/* hu */ {IDCLS_PETREU_SIZE_HU, "PET RAM and Expansion Unit mérete"},
/* it */ {IDCLS_PETREU_SIZE_IT, "Dimensione della RAM e dell'unità di espansione del PET"},
/* ko */ {IDCLS_PETREU_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PETREU_SIZE_NL, "Grootte van de PET RAM en uitbreidingseenheid"},
/* ru */ {IDCLS_PETREU_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PETREU_SIZE_SV, "Storlek på PET Ram- och -expansionsenhet"},
/* tr */ {IDCLS_PETREU_SIZE_TR, "PET Ram ve Geniþletme Birimi'nin boyutu"},
#endif

/* pet/petdww.c */
/* en */ {IDCLS_SPECIFY_PETDWW_NAME,    N_("Specify name of PET DWW image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PETDWW_NAME_DA, "Angiv navn på PET DWW-image"},
/* de */ {IDCLS_SPECIFY_PETDWW_NAME_DE, "Namen für PET DWW Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_PETDWW_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_PETDWW_NAME_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SPECIFY_PETDWW_NAME_IT, "Specifica il nome immagine PET DWW"},
/* ko */ {IDCLS_SPECIFY_PETDWW_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PETDWW_NAME_NL, "Geef de naam van het PET DWW bestand"},
/* ru */ {IDCLS_SPECIFY_PETDWW_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PETDWW_NAME_SV, "Ange namn på PET DWW-avbildning"},
/* tr */ {IDCLS_SPECIFY_PETDWW_NAME_TR, "PET DWW imajýnýn ismini belirt"},
#endif

/* pet/petdww.c */
/* en */ {IDCLS_ENABLE_PETDWW,    N_("Enable the PET DWW hi-res board")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PETDWW_DA, "Aktivér PET DWW højopløsningskort"},
/* de */ {IDCLS_ENABLE_PETDWW_DE, "PET DWW hi-res Karte aktivieren"},
/* fr */ {IDCLS_ENABLE_PETDWW_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_PETDWW_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_PETDWW_IT, "Attiva la scheda hi-res PET DWW"},
/* ko */ {IDCLS_ENABLE_PETDWW_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_PETDWW_NL, "Activeer het PET DWW hi-res bord"},
/* ru */ {IDCLS_ENABLE_PETDWW_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PETDWW_SV, "Aktivera PET DWW-högupplösningskort"},
/* tr */ {IDCLS_ENABLE_PETDWW_TR, "PET DWW hi-res boardunu aktif et"},
#endif

/* pet/petdww.c */
/* en */ {IDCLS_DISABLE_PETDWW,    N_("Disable the PET DWW hi-res board")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PETDWW_DA, "Deaktivér PET DWW højopløsningskort"},
/* de */ {IDCLS_DISABLE_PETDWW_DE, "PET DWW Hi-Res Karte deaktivieren"},
/* fr */ {IDCLS_DISABLE_PETDWW_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_PETDWW_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_PETDWW_IT, "Disattiva la scheda hi-res PET DWW"},
/* ko */ {IDCLS_DISABLE_PETDWW_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PETDWW_NL, "Het PET DWW hi-res bord uitschakelen"},
/* ru */ {IDCLS_DISABLE_PETDWW_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PETDWW_SV, "Inaktivera PET DWW-högupplösningskort"},
/* tr */ {IDCLS_DISABLE_PETDWW_TR, "PET DWW hi-res boardu pasifleþtir"},
#endif

/* pet/pet_userport_dac.c */
/* en */ {IDCLS_ENABLE_USERPORT_DAC,    N_("Enable Userport DAC for sound output")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_USERPORT_DAC_DA, "Aktivér brugerport DAC for lydoutput"},
/* de */ {IDCLS_ENABLE_USERPORT_DAC_DE, "Userport DAC Sound aktivieren"},
/* fr */ {IDCLS_ENABLE_USERPORT_DAC_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_USERPORT_DAC_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_USERPORT_DAC_IT, "Attiva DAC su userport per la riproduzione audio"},
/* ko */ {IDCLS_ENABLE_USERPORT_DAC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_USERPORT_DAC_NL, "Activeer userport DAC voor geluidsuitvoer"},
/* ru */ {IDCLS_ENABLE_USERPORT_DAC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_USERPORT_DAC_SV, "Aktivera D/A-omvandlare på användarporten för ljudutdata"},
/* tr */ {IDCLS_ENABLE_USERPORT_DAC_TR, "Ses çýkýþý için Userport DAC'ý aktif et"},
#endif

/* pet/pet_userport_dac.c */
/* en */ {IDCLS_DISABLE_USERPORT_DAC,    N_("Disable Userport DAC for sound output")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_USERPORT_DAC_DA, "Deaktivér brugerport DAC for lydoutput"},
/* de */ {IDCLS_DISABLE_USERPORT_DAC_DE, "Userport DAC Sound deaktivieren"},
/* fr */ {IDCLS_DISABLE_USERPORT_DAC_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_USERPORT_DAC_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_USERPORT_DAC_IT, "Disattiva DAC su userport per la riproduzione audio"},
/* ko */ {IDCLS_DISABLE_USERPORT_DAC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_USERPORT_DAC_NL, "Userport DAC voor geluidsuitvoer uitschakelen"},
/* ru */ {IDCLS_DISABLE_USERPORT_DAC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_USERPORT_DAC_SV, "Inaktivera D/A-omvandlare på användarporten för ljudutdata"},
/* tr */ {IDCLS_DISABLE_USERPORT_DAC_TR, "Ses çýkýþý için Userport DAC'ý pasifleþtir"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_SID_PLAYER_MODE,    N_("SID player mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SID_PLAYER_MODE_DA, "SID-afspiller tilstand"},
/* de */ {IDCLS_SID_PLAYER_MODE_DE, "SID Player Modus"},
/* fr */ {IDCLS_SID_PLAYER_MODE_FR, "Mode jukebox SID"},
/* hu */ {IDCLS_SID_PLAYER_MODE_HU, "SID lejátszó mód"},
/* it */ {IDCLS_SID_PLAYER_MODE_IT, "Modalità del SID player"},
/* ko */ {IDCLS_SID_PLAYER_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SID_PLAYER_MODE_NL, "SID playermodus"},
/* ru */ {IDCLS_SID_PLAYER_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SID_PLAYER_MODE_SV, "SID-spelarläge"},
/* tr */ {IDCLS_SID_PLAYER_MODE_TR, "SID çalar modu"},
#endif

/* c64/psid.c */
/* en */ {IDCLS_OVERWRITE_PSID_SETTINGS,    N_("Override PSID settings for Video standard and SID model")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_OVERWRITE_PSID_SETTINGS_DA, "Overstyr PSID-indstillinger for Video-standard og SID-model"},
/* de */ {IDCLS_OVERWRITE_PSID_SETTINGS_DE, "PSID Einstellung für Video Standard und SID Modell verändern"},
/* fr */ {IDCLS_OVERWRITE_PSID_SETTINGS_FR, "Écraser les paramètres PSID pour le standard vidéo et le modèle SID"},
/* hu */ {IDCLS_OVERWRITE_PSID_SETTINGS_HU, "A videó szabvány és a SID modell PSID beállításainak felülbírálása"},
/* it */ {IDCLS_OVERWRITE_PSID_SETTINGS_IT, "Non tener conto delle impostazioni del PSID per lo standard video e il modello di SID"},
/* ko */ {IDCLS_OVERWRITE_PSID_SETTINGS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_OVERWRITE_PSID_SETTINGS_NL, "Overschrijf PSID instellingen voor videostandaard en SID model"},
/* ru */ {IDCLS_OVERWRITE_PSID_SETTINGS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_OVERWRITE_PSID_SETTINGS_SV, "Ersätt PSID-inställningar för videostandard och SID-modell"},
/* tr */ {IDCLS_OVERWRITE_PSID_SETTINGS_TR, "Video standardý ve SID modeli için PSID ayarlarýný geçersiz kýl"},
#endif

/* c64/psid.c */
/* en */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER,    N_("Specify PSID tune <number>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_DA, "Vælg PSID-nummer <nummer>"},
/* de */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_DE, "PSID Stück <Nummer> definieren"},
/* fr */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_FR, "Spécifier le <numero> de piste PSID"},
/* hu */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_HU, "Adja meg a PSID hangzatok <szám>"},
/* it */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_IT, "Specifica la melodia <numero> del PSID"},
/* ko */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_NL, "Geef PSID deuntje <nummer>"},
/* ru */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_SV, "Ange PSID-låt <nummer>"},
/* tr */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_TR, "PSID parça <numara>'sýný belirt"},
#endif

/* c64/cart/ramcart.c */
/* en */ {IDCLS_ENABLE_RAMCART,    N_("Enable the RamCart expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RAMCART_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ENABLE_RAMCART_DE, "RamCart Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_RAMCART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_RAMCART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_RAMCART_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ENABLE_RAMCART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RAMCART_NL, "Activeer de RamCart uitbreiding"},
/* ru */ {IDCLS_ENABLE_RAMCART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RAMCART_SV, "Aktivera RamCart-expansion"},
/* tr */ {IDCLS_ENABLE_RAMCART_TR, ""},  /* fuzzy */
#endif

/* c64/cart/ramcart.c */
/* en */ {IDCLS_DISABLE_RAMCART,    N_("Disable the RamCart expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RAMCART_DA, ""},  /* fuzzy */
/* de */ {IDCLS_DISABLE_RAMCART_DE, "RamCart Erweiterung deaktivieren"},
/* fr */ {IDCLS_DISABLE_RAMCART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_RAMCART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_RAMCART_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_DISABLE_RAMCART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RAMCART_NL, "De RamCart uitbreiding uitschakelen"},
/* ru */ {IDCLS_DISABLE_RAMCART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAMCART_SV, "Inaktivera RamCart-expansion"},
/* tr */ {IDCLS_DISABLE_RAMCART_TR, ""},  /* fuzzy */
#endif

/* c64/cart/ramcart.c */
/* en */ {IDCLS_SPECIFY_RAMCART_NAME,    N_("Specify name of RAMCART image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RAMCART_NAME_DA, "Angiv navn på RAMCART-image"},
/* de */ {IDCLS_SPECIFY_RAMCART_NAME_DE, "Name für RAMCART Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_RAMCART_NAME_FR, "Spécifier le nom de l'image RAMCART"},
/* hu */ {IDCLS_SPECIFY_RAMCART_NAME_HU, "Adja meg a RAMCART képmás nevét"},
/* it */ {IDCLS_SPECIFY_RAMCART_NAME_IT, "Specifica il nome immagine RAMCART"},
/* ko */ {IDCLS_SPECIFY_RAMCART_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RAMCART_NAME_NL, "Geef de naam van het RAMCART bestand"},
/* ru */ {IDCLS_SPECIFY_RAMCART_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RAMCART_NAME_SV, "Ange namn på RAMCART-avbildning"},
/* tr */ {IDCLS_SPECIFY_RAMCART_NAME_TR, "RAMCART imajýnýn ismini belirt"},
#endif

/* c64/cart/ramcart.c */
/* en */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE,    N_("Allow writing to RAMCart image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_DA, "Tillad skrivning til RAMCart-image."},
/* de */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_DE, "Schreibzugriff auf RAMCart Image erlauben"},
/* fr */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_IT, "Attiva scrittura su immagine RAMCart"},
/* ko */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_NL, "Aktiveer schrijven naar RAMCart bestand"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_SV, "Tillåt skrivning till RAMCart-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_TR, "RAMCart imajýna yazmayý aktif et"},
#endif

/* c64/cart/ramcart.c */
/* en */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE,    N_("Do not write to RAMCart image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_DA, "Skriv ikke til RAMcart-image"},
/* de */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_DE, "Kein Schreibzugriff auf RAMCart Image"},
/* fr */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_IT, "Disattiva scrittura su immagine RAMCart"},
/* ko */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_NL, "Schrijf niet naar RAMCart bestand"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_SV, "Skriv inte till RAMCart-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_TR, "RAMCart imajýna yazma"},
#endif

/* c64/cart/ramcart.c */
/* en */ {IDCLS_RAMCART_SIZE,    N_("Size of the RAMCART expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RAMCART_SIZE_DA, "Størrelse på RAMCART-udviddelse"},
/* de */ {IDCLS_RAMCART_SIZE_DE, "Größe der RAMCART Erweiterung"},
/* fr */ {IDCLS_RAMCART_SIZE_FR, "Taille de l'expansion RAMCART"},
/* hu */ {IDCLS_RAMCART_SIZE_HU, "RAMCART bõvítés mérete"},
/* it */ {IDCLS_RAMCART_SIZE_IT, "Dimensione dell'espansione RAMCART"},
/* ko */ {IDCLS_RAMCART_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_RAMCART_SIZE_NL, "Grootte van de RAMCART uitbreiding"},
/* ru */ {IDCLS_RAMCART_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RAMCART_SIZE_SV, "Storlek på RAMCART-expansion"},
/* tr */ {IDCLS_RAMCART_SIZE_TR, "RAMCART geniþlemesinin boyutu"},
#endif

/* c64/cart/dqbb.c */
/* en */ {IDCLS_ENABLE_DQBB,    N_("Enable Double Quick Brown Box")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DQBB_DA, "Aktivér Double Quick Brown Box"},
/* de */ {IDCLS_ENABLE_DQBB_DE, "Double Quick Brown Box aktivieren"},
/* fr */ {IDCLS_ENABLE_DQBB_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_DQBB_HU, "Double Quick Brown Box engedélyezése"},
/* it */ {IDCLS_ENABLE_DQBB_IT, "Attiva Double Quick Brown Box"},
/* ko */ {IDCLS_ENABLE_DQBB_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DQBB_NL, "Activeer de Double Quick Brown Box cartridge"},
/* ru */ {IDCLS_ENABLE_DQBB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DQBB_SV, "Aktivera Double Quick Brown Box"},
/* tr */ {IDCLS_ENABLE_DQBB_TR, "Double Quick Brown Box'ý aktif et"},
#endif

/* c64/cart/dqbb.c */
/* en */ {IDCLS_DISABLE_DQBB,    N_("Disable Double Quick Brown Box")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DQBB_DA, "Deaktivér Double Quick Brown Box"},
/* de */ {IDCLS_DISABLE_DQBB_DE, "Double Quick Brown Box Modul deaktivieren"},
/* fr */ {IDCLS_DISABLE_DQBB_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_DQBB_HU, "Double Quick Brown Box tiltása"},
/* it */ {IDCLS_DISABLE_DQBB_IT, "Disattiva Double Quick Brown Box"},
/* ko */ {IDCLS_DISABLE_DQBB_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DQBB_NL, "De Double Quick Brown Box cartridge uitschakelen"},
/* ru */ {IDCLS_DISABLE_DQBB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DQBB_SV, "Inaktivera Double Quick Brown Box"},
/* tr */ {IDCLS_DISABLE_DQBB_TR, "Double Quick Brown Box'ý pasifleþtir"},
#endif

/* c64/cart/dqbb.c */
/* en */ {IDCLS_SPECIFY_DQBB_NAME,    N_("Specify Double Quick Brown Box filename")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_DQBB_NAME_DA, "Angiv filnavn for Double Quick Brown Box"},
/* de */ {IDCLS_SPECIFY_DQBB_NAME_DE, "Double Quick Brown Box Dateiname spezifizieren"},
/* fr */ {IDCLS_SPECIFY_DQBB_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_DQBB_NAME_HU, "Adja meg a Double Quick Brown Box fájlnevet"},
/* it */ {IDCLS_SPECIFY_DQBB_NAME_IT, "Specifica il nome del file Double Quick Brown Box"},
/* ko */ {IDCLS_SPECIFY_DQBB_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_DQBB_NAME_NL, "Geef de naam van het Double Quick Brown Box cartridge bestand"},
/* ru */ {IDCLS_SPECIFY_DQBB_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_DQBB_NAME_SV, "Ange filnamn för Double Quick Brown Box"},
/* tr */ {IDCLS_SPECIFY_DQBB_NAME_TR, "Double Quick Brown Box dosya ismi belirt"},
#endif

/* c64/cart/dqbb.c */
/* en */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE,    N_("Allow writing to DQBB image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_DA, "Tillad skrivning til DQBB-image."},
/* de */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_DE, "Schreibzugriff auf DQBB Image erlauben"},
/* fr */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_IT, "Attiva scrittura su immagine DQBB"},
/* ko */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_NL, "Aktiveer schrijven naar DQBB bestand"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_SV, "Tillåt skrivning till DQBB-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_TR, "DQBB imajýna yazmayý aktif et"},
#endif

/* c64/cart/dqbb.c */
/* en */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE,    N_("Do not write to DQBB image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_DA, "Skriv ikke til DQBB-image"},
/* de */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_DE, "Kein Schreibzugriff auf DQBB Image"},
/* fr */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_IT, "Disattiva scrittura su immagine DQBB"},
/* ko */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_NL, "Schrijf niet naar DQBB bestand"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_SV, "Skriv inte till DQBB-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_TR, "DQBB imajýna yazma"},
#endif

/* c64/cart/isepic.c */
/* en */ {IDCLS_ENABLE_ISEPIC,    N_("Enable the ISEPIC cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_ISEPIC_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ENABLE_ISEPIC_DE, "ISEPIC Modul aktivieren"},
/* fr */ {IDCLS_ENABLE_ISEPIC_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_ISEPIC_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_ISEPIC_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ENABLE_ISEPIC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_ISEPIC_NL, "*Activeer de ISEPIC cartridge"},
/* ru */ {IDCLS_ENABLE_ISEPIC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_ISEPIC_SV, "Aktivera ISEPIC-modul"},
/* tr */ {IDCLS_ENABLE_ISEPIC_TR, ""},  /* fuzzy */
#endif

/* c64/cart/isepic.c */
/* en */ {IDCLS_DISABLE_ISEPIC,    N_("Disable the ISEPIC cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_ISEPIC_DA, ""},  /* fuzzy */
/* de */ {IDCLS_DISABLE_ISEPIC_DE, "ISEPIC Modul deaktivieren"},
/* fr */ {IDCLS_DISABLE_ISEPIC_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_ISEPIC_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_ISEPIC_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_DISABLE_ISEPIC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_ISEPIC_NL, "De ISEPIC cartridge uitschakelen"},
/* ru */ {IDCLS_DISABLE_ISEPIC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_ISEPIC_SV, "Inaktivera ISEPIC-modul"},
/* tr */ {IDCLS_DISABLE_ISEPIC_TR, ""},  /* fuzzy */
#endif

/* c64/cart/isepic.c */
/* en */ {IDCLS_SET_ISEPIC_FILENAME,    N_("Set ISEPIC image name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_ISEPIC_FILENAME_DA, "Vælg ISEPIC image-navn"},
/* de */ {IDCLS_SET_ISEPIC_FILENAME_DE, "ISEPIC Imagedateiname setzen"},
/* fr */ {IDCLS_SET_ISEPIC_FILENAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_ISEPIC_FILENAME_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_ISEPIC_FILENAME_IT, "Imposta nome immagine ISEPIC"},
/* ko */ {IDCLS_SET_ISEPIC_FILENAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_ISEPIC_FILENAME_NL, "Geef de naam op van het ISEPIC cartridge bestand"},
/* ru */ {IDCLS_SET_ISEPIC_FILENAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_ISEPIC_FILENAME_SV, "Namn på ISEPIC-avbildning"},
/* tr */ {IDCLS_SET_ISEPIC_FILENAME_TR, "ISEPIC imaj ismini belirle"},
#endif

/* c64/cart/isepic.c */
/* en */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE,    N_("Allow writing to ISEPIC image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_DA, "Tillad skrivning til ISEPIC-image"},
/* de */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_DE, "Schreibzugriff auf ISEPIC Image erlauben"},
/* fr */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_IT, "Attiva scrittura su immagine ISEPIC"},
/* ko */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_NL, "Aktiveer schrijven naar ISEPIC bestand"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_SV, "Tillåt skrivning till ISEPIC-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_TR, "ISEPIC imajýna yazmayý aktif et"},
#endif

/* c64/cart/isepic.c */
/* en */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE,    N_("Do not write to ISEPIC image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_DA, "Skriv ikke til ISEPIC-image"},
/* de */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_DE, "Kein Schreibzugriff auf ISEPIC Image"},
/* fr */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_IT, "Disattiva scrittura su immagine ISEPIC"},
/* ko */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_NL, "Schrijf niet naar ISEPIC bestand"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_SV, "Skriv inte till ISEPIC-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_TR, "ISEPIC imajýna yazma"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_ENABLE_MMC64,    N_("Enable the MMC64 expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_MMC64_DA, "Aktivér MMC64-udviddelse"},
/* de */ {IDCLS_ENABLE_MMC64_DE, "MMC64 Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_MMC64_FR, "Activer l'expansion MMC64"},
/* hu */ {IDCLS_ENABLE_MMC64_HU, "MMC64 bõvítés engedélyezése"},
/* it */ {IDCLS_ENABLE_MMC64_IT, "Attiva l'espansione MMC64"},
/* ko */ {IDCLS_ENABLE_MMC64_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_MMC64_NL, "Activeer de MMC64 uitbreiding"},
/* ru */ {IDCLS_ENABLE_MMC64_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_MMC64_SV, "Aktivera MMC64-expansion"},
/* tr */ {IDCLS_ENABLE_MMC64_TR, "MMC64 geniþlemesini aktif et"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_DISABLE_MMC64,    N_("Disable the MMC64 expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_MMC64_DA, "Deaktivér MMC64-udviddelse"},
/* de */ {IDCLS_DISABLE_MMC64_DE, "MMC64 Erweiterung deaktivieren"},
/* fr */ {IDCLS_DISABLE_MMC64_FR, "Désactiver l'expansion MMC64"},
/* hu */ {IDCLS_DISABLE_MMC64_HU, "MMC64 bõvítés tiltása"},
/* it */ {IDCLS_DISABLE_MMC64_IT, "Disattiva l'espansione MMC64"},
/* ko */ {IDCLS_DISABLE_MMC64_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_MMC64_NL, "De MMC64 uitbreiding uitschakelen"},
/* ru */ {IDCLS_DISABLE_MMC64_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_MMC64_SV, "Inaktivera MMC64-expansion"},
/* tr */ {IDCLS_DISABLE_MMC64_TR, "MMC64 geniþlemesini pasifleþtir"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_SPECIFY_MMC64_BIOS_NAME,    N_("Specify name of MMC64 BIOS image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_DA, "Angiv navn på MMC64-BIOS-image"},
/* de */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_DE, "Name für MMC64 BIOS Datei spezifizieren"},
/* fr */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_FR, "Spécifier le nom de l'image MMC64 BIOS"},
/* hu */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_HU, "Adja meg az MMC64 BIOS képmás nevét"},
/* it */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_IT, "Specifica il nome immagine del BIOS MMC64"},
/* ko */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_NL, "Geef de naam van het MMC64 BIOS bestand"},
/* ru */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_SV, "Ange namn på MMC64-BIOS-avbildning"},
/* tr */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_TR, "MMC64 BIOS imajýnýn ismini belirt"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME,    N_("Specify name of MMC64 image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_DA, "Angiv navn på MMC64-image"},
/* de */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_DE, "Name der MMC64 Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_FR, "Spécifier le nom de l'image MMC64"},
/* hu */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_HU, "Adja meg az MMC64 képmás nevét"},
/* it */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_IT, "Specifica il nome immagine MMC64"},
/* ko */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_NL, "Geef de naam van het MMC64 bestand"},
/* ru */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_SV, "Ange namn på MMC64-avbildning"},
/* tr */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_TR, "MMC64 imajýnýn ismini belirt"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_MMC64_READONLY,    N_("Set the MMC64 card to read-only")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC64_READONLY_DA, "Skrivebeskyt MMC64-kort"},
/* de */ {IDCLS_MMC64_READONLY_DE, "MMC64 Karte Schreibschutz"},
/* fr */ {IDCLS_MMC64_READONLY_FR, "Définir la carte MMC64 en lecture seule"},
/* hu */ {IDCLS_MMC64_READONLY_HU, "MMC64 kártya csak olvasható"},
/* it */ {IDCLS_MMC64_READONLY_IT, "Imposta la card MMC64 in sola lettura"},
/* ko */ {IDCLS_MMC64_READONLY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC64_READONLY_NL, "Zet de MMC64 als alleen-lezen"},
/* ru */ {IDCLS_MMC64_READONLY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC64_READONLY_SV, "Skrivskydda MMC64-kort"},
/* tr */ {IDCLS_MMC64_READONLY_TR, "MMC64 kartýný salt okunura çevir"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_MMC64_READWRITE,    N_("Set the MMC64 card to read/write")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC64_READWRITE_DA, "Tillad skrivning på MMC64-kort"},
/* de */ {IDCLS_MMC64_READWRITE_DE, "MMC64 Karte Schreibzugriff"},
/* fr */ {IDCLS_MMC64_READWRITE_FR, "Définir la carte MMC64 en lecture/écriture"},
/* hu */ {IDCLS_MMC64_READWRITE_HU, "MMC64 kártya írható/olvasható"},
/* it */ {IDCLS_MMC64_READWRITE_IT, "Imposta la card MMC64 in lettura/scrittura"},
/* ko */ {IDCLS_MMC64_READWRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC64_READWRITE_NL, "Zet de MMC64 als lezen/schrijven"},
/* ru */ {IDCLS_MMC64_READWRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC64_READWRITE_SV, "Tillåt skrivning på MMC64-kort"},
/* tr */ {IDCLS_MMC64_READWRITE_TR, "MMC64 kartýný okunur/yazýlýra çevir"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_MMC64_BIOS_WRITE,    N_("Save the MMC64 bios when changed")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC64_BIOS_WRITE_DA, "Gem MMC64-BIOS ved ændring"},
/* de */ {IDCLS_MMC64_BIOS_WRITE_DE, "MMC64 BIOS speichern bei Änderung"},
/* fr */ {IDCLS_MMC64_BIOS_WRITE_FR, "Sauvegarder le BIOS MMC64 lorsque modifié"},
/* hu */ {IDCLS_MMC64_BIOS_WRITE_HU, "MMC64 BIOS mentése változás után"},
/* it */ {IDCLS_MMC64_BIOS_WRITE_IT, "Salva il bios MMC64 al cambio"},
/* ko */ {IDCLS_MMC64_BIOS_WRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC64_BIOS_WRITE_NL, "Sla de MMC64 BIOS op als er veranderingen zijn gemaakt"},
/* ru */ {IDCLS_MMC64_BIOS_WRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC64_BIOS_WRITE_SV, "Spara MMC64-BIOS vid ändring"},
/* tr */ {IDCLS_MMC64_BIOS_WRITE_TR, "MMC64 BIOS'unu deðiþtiðinde kaydet"},
#endif

/* c64/cart/mmcreplay.c */
/* en */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME,    N_("Specify MMC Replay card image filename")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME_DA, "Angiv filnavn for MMC Replay kort-image"},
/* de */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME_DE, "MMC Replay Modul imeage datei definieren"},
/* fr */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME_IT, "Specifica il nome file immagine della card MMC Replay"},
/* ko */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME_NL, "Geef de naam van het MMC Replay card bestand"},
/* ru */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME_SV, "Ange namn på avbildningsfil för MMC Replay-kort"},
/* tr */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME_TR, "MMC Replay kart imaj dosyaismini belirt"},
#endif

/* c64/cart/mmcreplay.c */
/* en */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE,    N_("Enable writes to MMC Replay card image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_DA, "Tillad skrivning til MMC Replay kort-image"},
/* de */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_DE, "Erlaube Schreibzugriff auf MMC Replay Imagedatei"},
/* fr */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_IT, "Attiva scrittura su immagine card MMC Replay"},
/* ko */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_NL, "Aktiveer schrijven naar MMC Replay card bestand"},
/* ru */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_SV, "Aktivera skrivning till MMC Replay-kortavbildning"},
/* tr */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_TR, "MMC Replay kart imajýnda yazmalarý aktif et"},
#endif

/* c64/cart/mmcreplay.c */
/* en */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE,    N_("Disable writes to MMC Replay card image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_DA, "Skriv ikke til MMC Replay kort-image"},
/* de */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_DE, "Schreibzugriff auf MMC Replay Imagedatei verhindern"},
/* fr */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_IT, "Disattiva scrittura su immagine card MMC Replay"},
/* ko */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_NL, "Schrijven naar het MMC Replay card bestand uitschakelen"},
/* ru */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_SV, "Inaktivera skrivning till MMC Replay-kortavbildning"},
/* tr */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_TR, "MMC Replay kart imajýnda yazmalarý pasifleþtir"},
#endif

/* c64/cart/mmcreplay.c */
/* en */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE,    N_("Specify MMC Replay EEPROM image filename")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE_DA, "Angiv filnavn for MMC Replay EEPROM-image"},
/* de */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE_DE, "MMC Replay EEPROM Imagedatei definieren"},
/* fr */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE_IT, "Specifica il nome file immagine della EEPROM MMC Replay"},
/* ko */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE_NL, "Geef de naam van het MMC Replay EEPROM bestand"},
/* ru */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE_SV, "Ange filnamn för MMC Replay EEPROM-avbildning"},
/* tr */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE_TR, "MMC Replay EEPROM imaj dosyaismini belirt"},
#endif

/* c64/cart/mmcreplay.c */
/* en */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE,    N_("Enable writes to MMC Replay EEPROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_DA, "Tillad skrivning til MMC Replay EEPROM-image"},
/* de */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_DE, "Erlaube Schreibzugriff auf MMC Replay EEPROM Imagedatei"},
/* fr */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_IT, "Attiva scrittura su immagine EEPROM MMC Replay"},
/* ko */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_NL, "Aktiveer schrijven naar MMC Replay EEPROM bestand"},
/* ru */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_SV, "Aktivera skrivning till MMC Replay EEPROM-avbildning"},
/* tr */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_TR, "MMC Replay EEPROM imajýnda yazmalarý aktif et"},
#endif

/* c64/cart/mmcreplay.c */
/* en */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE,    N_("Disable writes to MMC Replay EEPROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_DA, "Skriv ikke til MMC Replay EEPROM-image"},
/* de */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_DE, "Schreibzugriff auf MMC Replay EEPROM Imagedatei verhindern"},
/* fr */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_IT, "Disattiva scrittura su immagine EEPROM MMC Replay"},
/* ko */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_NL, "Schrijven naar MMC Replay EEPROM bestand uitschakelen"},
/* ru */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_SV, "Inaktivera skrivning till MMC Replay EEPROM-avbildning"},
/* tr */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_TR, "MMC Replay EEPROM imajýnda yazmalarý pasifleþtir"},
#endif

/* c64/cart/mmcreplay.c */
/* en */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE,    N_("Enable MMC Replay rescue mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_DA, "Aktivér MMC Replay fejlsikret tilstand"},
/* de */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_DE, "MMC Replay Rescue Modus aktivieren"},
/* fr */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_IT, "Attiva modalità ripristino MMC Replay"},
/* ko */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_NL, "Activeer MMC Replay reddingsmodus"},
/* ru */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_SV, "Aktivera MMC Replay-räddningsläge"},
/* tr */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_TR, "MMC Replay kurtarma modunu aktif et"},
#endif

/* c64/cart/mmcreplay.c */
/* en */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE,    N_("Disable MMC Replay rescue mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_DA, "Deaktivér MMC Replay fejlsikret tilstand"},
/* de */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_DE, "MMC Replay Rescue Modus deaktivieren"},
/* fr */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_IT, "Disattiva modalità ripristino MMC Replay"},
/* ko */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_NL, "MMC Replay reddingsmodus uitschakelen"},
/* ru */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_SV, "Inaktivera MMC Replay-räddningsläge"},
/* tr */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_TR, "MMC Replay kurtarma modunu pasifleþtir"},
#endif

/* c64/cart/mmcreplay.c */
/* en */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE,    N_("Allow writing to MMC Replay image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_DA, "Tillad skrivning til MMC Replay-image"},
/* de */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_DE, "Erlaube Schreibzugriff auf MMC Replay Image"},
/* fr */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_IT, "Attiva scrittura su immagine MMC Replay"},
/* ko */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_NL, "Aktiveer schrijven naar MMC Replay bestand"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_SV, "Tillåt skrivning till MMC Replay-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_TR, "MMC Replay imajýna yazmayý aktif et"},
#endif

/* c64/cart/mmcreplay.c */
/* en */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE,    N_("Do not write to MMC Replay image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_DA, "Skriv ikke til MMC Replay-image"},
/* de */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_DE, "Kein Schreibzugriff auf MMC Replay Image"},
/* fr */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_IT, "Disattiva scrittura su immagine MMC Replay"},
/* ko */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_NL, "Schrijf niet naar MMC Replay bestand"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_SV, "Skriv inte till MMC Replay-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_TR, "MMC Replay imajýna yazma"},
#endif

/* c64/cart/retroreplay.c */
/* en */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT,    N_("Enable saving of the RR ROM at exit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_DA, "Aktivér skrivning af RR ROM ved afslutning"},
/* de */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_DE, "Speichern des RR ROMs beim Beenden aktivieren"},
/* fr */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_IT, "Attiva salvataggio della RR ROM all'uscita"},
/* ko */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_NL, "Activeer opslaan van het RR ROM bestand bij afsluiten"},
/* ru */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_SV, "Aktivera sparande av RR-ROM vid avslutning"},
/* tr */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_TR, "Çýkýþta RR ROM'un kaydedilmesini aktif et"},
#endif

/* c64/cart/retroreplay.c */
/* en */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT,    N_("Disable saving of the RR ROM at exit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_DA, "Dektivér skrivning af RR ROM ved afslutning"},
/* de */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_DE, "Speichern des RR ROMs beim Beenden deaktivieren"},
/* fr */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_IT, "Disattiva salvataggio della RR ROM all'uscita"},
/* ko */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_NL, "Uitschakelen van het opslaan van het RR ROM bestand bij afsluiten"},
/* ru */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_SV, "Inaktivera sparande av RR-ROM vid avslutning"},
/* tr */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_TR, "Çýkýþta RR ROM'un kaydedilmesini pasifleþtir"},
#endif

/* c64/cart/retroreplay.c */
/* en */ {IDCLS_SET_RR_BANK_JUMPER,    N_("Set RR Bank Jumper")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_RR_BANK_JUMPER_DA, "Tilslut RR Bank Jumper"},
/* de */ {IDCLS_SET_RR_BANK_JUMPER_DE, "Aktiviere RR Bank Jumpler"},
/* fr */ {IDCLS_SET_RR_BANK_JUMPER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_RR_BANK_JUMPER_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_RR_BANK_JUMPER_IT, "Imposta Bank Jumper RR"},
/* ko */ {IDCLS_SET_RR_BANK_JUMPER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_RR_BANK_JUMPER_NL, "Zet RR bank jumper"},
/* ru */ {IDCLS_SET_RR_BANK_JUMPER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_RR_BANK_JUMPER_SV, "Aktivera RR-bankbygel"},
/* tr */ {IDCLS_SET_RR_BANK_JUMPER_TR, "RR Bank Jumper'ý tak"},
#endif

/* c64/cart/retroreplay.c */
/* en */ {IDCLS_UNSET_RR_BANK_JUMPER,    N_("Unset RR Bank Jumper")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_UNSET_RR_BANK_JUMPER_DA, "Afbryd RR Bank Jumper"},
/* de */ {IDCLS_UNSET_RR_BANK_JUMPER_DE, "Deaktiviere RR Bank Jumper"},
/* fr */ {IDCLS_UNSET_RR_BANK_JUMPER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_UNSET_RR_BANK_JUMPER_HU, ""},  /* fuzzy */
/* it */ {IDCLS_UNSET_RR_BANK_JUMPER_IT, "Rimuovi Bank Jumper RR"},
/* ko */ {IDCLS_UNSET_RR_BANK_JUMPER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_UNSET_RR_BANK_JUMPER_NL, "Zet RR bank jumper niet"},
/* ru */ {IDCLS_UNSET_RR_BANK_JUMPER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_UNSET_RR_BANK_JUMPER_SV, "Inaktivera RR-bankbygel"},
/* tr */ {IDCLS_UNSET_RR_BANK_JUMPER_TR, "RR Bank Jumper'ý çýkart"},
#endif

/* c64/cart/retroreplay.c */
/* en */ {IDCLS_SET_RR_FLASH_JUMPER,    N_("Set RR Flash Jumper")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_RR_FLASH_JUMPER_DA, "Tilslut RR Flash jumper"},
/* de */ {IDCLS_SET_RR_FLASH_JUMPER_DE, "Aktviere RR Flash Jumper"},
/* fr */ {IDCLS_SET_RR_FLASH_JUMPER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_RR_FLASH_JUMPER_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_RR_FLASH_JUMPER_IT, "Imposta Flash Jumper RR"},
/* ko */ {IDCLS_SET_RR_FLASH_JUMPER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_RR_FLASH_JUMPER_NL, "Zet RR Flash Jumper"},
/* ru */ {IDCLS_SET_RR_FLASH_JUMPER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_RR_FLASH_JUMPER_SV, "Sätt RR-flashbygel"},
/* tr */ {IDCLS_SET_RR_FLASH_JUMPER_TR, "RR Flash Jumper'ý tak"},
#endif

/* c64/cart/retroreplay.c */
/* en */ {IDCLS_UNSET_RR_FLASH_JUMPER,    N_("Unset RR Bank Jumper")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_UNSET_RR_FLASH_JUMPER_DA, "Afbryd RR Bank Jumper"},
/* de */ {IDCLS_UNSET_RR_FLASH_JUMPER_DE, "Deaktiviere RR Bank Jumper"},
/* fr */ {IDCLS_UNSET_RR_FLASH_JUMPER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_UNSET_RR_FLASH_JUMPER_HU, ""},  /* fuzzy */
/* it */ {IDCLS_UNSET_RR_FLASH_JUMPER_IT, "Rimuovi Bank Jumper RR"},
/* ko */ {IDCLS_UNSET_RR_FLASH_JUMPER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_UNSET_RR_FLASH_JUMPER_NL, "Zet RR bank jumper niet"},
/* ru */ {IDCLS_UNSET_RR_FLASH_JUMPER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_UNSET_RR_FLASH_JUMPER_SV, "Inaktivera RR-bankbygel"},
/* tr */ {IDCLS_UNSET_RR_FLASH_JUMPER_TR, "RR Bank Jumper'ý çýkart"},
#endif

/* c64/cart/reu.c */
/* en */ {IDCLS_ENABLE_REU,    N_("Enable the RAM Expansion Unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_REU_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ENABLE_REU_DE, "RAM Speichererweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_REU_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_REU_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_REU_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ENABLE_REU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_REU_NL, "Activeer de RAM uitbreidingseenheid (REU)"},
/* ru */ {IDCLS_ENABLE_REU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_REU_SV, "Aktivera RAM-expansionsenhet"},
/* tr */ {IDCLS_ENABLE_REU_TR, ""},  /* fuzzy */
#endif

/* c64/cart/reu.c */
/* en */ {IDCLS_DISABLE_REU,    N_("Disable the RAM Expansion Unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_REU_DA, ""},  /* fuzzy */
/* de */ {IDCLS_DISABLE_REU_DE, "RAM Speichererweiterung deaktivieren"},
/* fr */ {IDCLS_DISABLE_REU_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_REU_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_REU_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_DISABLE_REU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_REU_NL, "De RAM uitbreidingseenheid (REU) uitschakelen"},
/* ru */ {IDCLS_DISABLE_REU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_REU_SV, "Inaktivera RAM-expansionsenhet"},
/* tr */ {IDCLS_DISABLE_REU_TR, ""},  /* fuzzy */
#endif

/* c64/cart/reu.c */
/* en */ {IDCLS_SPECIFY_REU_NAME,    N_("Specify name of REU image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_REU_NAME_DA, "Angiv navn på REU-image"},
/* de */ {IDCLS_SPECIFY_REU_NAME_DE, "Namen für REU Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_REU_NAME_FR, "Spécifier le nom de l'image REU"},
/* hu */ {IDCLS_SPECIFY_REU_NAME_HU, "Adja meg a REU képmás nevét"},
/* it */ {IDCLS_SPECIFY_REU_NAME_IT, "Specifica il nome immagine REU"},
/* ko */ {IDCLS_SPECIFY_REU_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_REU_NAME_NL, "Geef de naam van het REU bestand"},
/* ru */ {IDCLS_SPECIFY_REU_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_REU_NAME_SV, "Ange namn på REU-avbildning"},
/* tr */ {IDCLS_SPECIFY_REU_NAME_TR, "REU imajýnýn ismini belirt"},
#endif

/* c64/cart/reu.c */
/* en */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE,    N_("Allow writing to REU image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_DA, "Tillad skrivning til REU-image"},
/* de */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_DE, "Schreibzugriff auf REU Image erlauben"},
/* fr */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_IT, "Attiva scrittura su immagine REU"},
/* ko */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_NL, "Aktiveer schrijven naar REU bestand"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_SV, "Tillåt skrivning till REU-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_TR, "REU imajýna yazmayý aktif et"},
#endif

/* c64/cart/reu.c */
/* en */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE,    N_("Do not write to REU image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_DA, "Skriv ikke til REU-image"},
/* de */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_DE, "Kein Schreibzugriff auf REU Image"},
/* fr */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_IT, "Disattiva scrittura su immagine REU"},
/* ko */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_NL, "Schrijf niet naar REU bestand"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_SV, "Skriv inte till REU-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_TR, "REU imajýna yazma"},
#endif

/* c64/cart/reu.c */
/* en */ {IDCLS_REU_SIZE,    N_("Size of the RAM expansion unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_REU_SIZE_DA, "Størrelse på RAM-udviddelsesenhed"},
/* de */ {IDCLS_REU_SIZE_DE, "Größe der RAM Speichererweiterung"},
/* fr */ {IDCLS_REU_SIZE_FR, "Taille de l'unité d'expansion RAM"},
/* hu */ {IDCLS_REU_SIZE_HU, "RAM Expansion Unit mérete"},
/* it */ {IDCLS_REU_SIZE_IT, "Dimensione dell'espansione di RAM"},
/* ko */ {IDCLS_REU_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_REU_SIZE_NL, "Grootte van de RAM uitbreidingseenheid (REU)"},
/* ru */ {IDCLS_REU_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_REU_SIZE_SV, "Storlek på RAM-expansionsenhet"},
/* tr */ {IDCLS_REU_SIZE_TR, "RAM geniþletme biriminin boyutu"},
#endif

#ifdef HAVE_TFE
/* c64/cart/tfe.c */
/* en */ {IDCLS_ENABLE_TFE,    N_("Enable the TFE (\"The Final Ethernet\") unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_TFE_DA, "Aktivér TFE-enhed (\"The Final Ethernet\")"},
/* de */ {IDCLS_ENABLE_TFE_DE, "TFE (\"the final ethernet\") Erweiterung aktivitieren"},
/* fr */ {IDCLS_ENABLE_TFE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_TFE_HU, "TFE (\"the final ethernet\") egység engedélyezése"},
/* it */ {IDCLS_ENABLE_TFE_IT, "Attiva l'unità TFE (\"The Final Ethernet\")"},
/* ko */ {IDCLS_ENABLE_TFE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_TFE_NL, "Activeer de TFE (\"The Final Ethernet\") eenheid"},
/* ru */ {IDCLS_ENABLE_TFE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_TFE_SV, "Aktivera TFE-enhet (\"The Final Ethernet\")"},
/* tr */ {IDCLS_ENABLE_TFE_TR, "TFE (\"The Final Ethernet\") birimini aktif et"},
#endif

/* c64/cart/tfe.c */
/* en */ {IDCLS_DISABLE_TFE,    N_("Disable the TFE (\"The Final Ethernet\") unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_TFE_DA, "Deaktivér TFE-enhed (\"The Final Ethernet\")"},
/* de */ {IDCLS_DISABLE_TFE_DE, "TFE (\"the final ethernet\") Erweiterung deaktivitieren"},
/* fr */ {IDCLS_DISABLE_TFE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_TFE_HU, "TFE (\"The Final Ethernet\") egység tiltása"},
/* it */ {IDCLS_DISABLE_TFE_IT, "Disattiva l'unità TFE (\"The Final Ethernet\")"},
/* ko */ {IDCLS_DISABLE_TFE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_TFE_NL, "De TFE (\"The Final Ethernet\") eenheid uitschakelen"},
/* ru */ {IDCLS_DISABLE_TFE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_TFE_SV, "Inaktivera TFE-enhet (\"The Final Ethernet\")"},
/* tr */ {IDCLS_DISABLE_TFE_TR, "TFE (\"The Final Ethernet\") birimini pasifleþtir"},
#endif

/* c64/cart/tfe.c */
/* en */ {IDCLS_TFE_INTERFACE,    N_("Set the system ethernet interface for TFE emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TFE_INTERFACE_DA, "Indstil systemets netkort til TFE-emulering"},
/* de */ {IDCLS_TFE_INTERFACE_DE, "Setze die System Ethernet Schnittstelle für die TFE Emulation"},
/* fr */ {IDCLS_TFE_INTERFACE_FR, "Définir l’interface ethernet pour l’émulation TFE"},
/* hu */ {IDCLS_TFE_INTERFACE_HU, "Rendszer ethernet eszköz beállítása TFE emulációhoz"},
/* it */ {IDCLS_TFE_INTERFACE_IT, "Imposta l'interfaccia ethernet per l'emulazione TFE"},
/* ko */ {IDCLS_TFE_INTERFACE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TFE_INTERFACE_NL, "Zet de systeem ethernetinterface voor de TFE emulatie"},
/* ru */ {IDCLS_TFE_INTERFACE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TFE_INTERFACE_SV, "Ställ in systemets ethernetgränssnitt för TFE-emulering"},
/* tr */ {IDCLS_TFE_INTERFACE_TR, "Sistem ethernet arabirimini TFE emülasyonu için ayarla"},
#endif

/* c64/cart/tfe.c */
/* en */ {IDCLS_ENABLE_TFE_AS_RRNET,    N_("Enable RRNet mode of TFE emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_TFE_AS_RRNET_DA, "Aktivér RRNet-tilstand af TFE-emulering"},
/* de */ {IDCLS_ENABLE_TFE_AS_RRNET_DE, "RRNet Modus der TFE Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_TFE_AS_RRNET_FR, "Activer le mode RRNet de l’émulation TFE"},
/* hu */ {IDCLS_ENABLE_TFE_AS_RRNET_HU, "RRNet mód engedélyezése TFE emulációhoz"},
/* it */ {IDCLS_ENABLE_TFE_AS_RRNET_IT, "Attiva la modalità RRNet dell'emulazione TFE"},
/* ko */ {IDCLS_ENABLE_TFE_AS_RRNET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_TFE_AS_RRNET_NL, "Activeer RRNet modus van de TFE emulatie"},
/* ru */ {IDCLS_ENABLE_TFE_AS_RRNET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_TFE_AS_RRNET_SV, "Aktivera RRNet-läge på TFE-emulering"},
/* tr */ {IDCLS_ENABLE_TFE_AS_RRNET_TR, "TFE emülasyonunun RRNet modunu aktif et"},
#endif

/* c64/cart/tfe.c */
/* en */ {IDCLS_DISABLE_TFE_AS_RRNET,    N_("Disable RRNet mode of TFE emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_TFE_AS_RRNET_DA, "Deaktivér RRNet-läge af TFE-emulering"},
/* de */ {IDCLS_DISABLE_TFE_AS_RRNET_DE, "RRNet Modus der TFE Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_TFE_AS_RRNET_FR, "Désactiver le mode RRNet de l’émulation TFE"},
/* hu */ {IDCLS_DISABLE_TFE_AS_RRNET_HU, "RRNet mód tiltása TFE emulációhoz"},
/* it */ {IDCLS_DISABLE_TFE_AS_RRNET_IT, "Disattiva la modalità RRNet dell'emulazione TFE"},
/* ko */ {IDCLS_DISABLE_TFE_AS_RRNET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_TFE_AS_RRNET_NL, "RRNet modus van de TFE emulatie uitschakelen"},
/* ru */ {IDCLS_DISABLE_TFE_AS_RRNET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_TFE_AS_RRNET_SV, "Inaktivera RRNet-läge på TFE-emulering"},
/* tr */ {IDCLS_DISABLE_TFE_AS_RRNET_TR, "TFE emülasyonunun RRNet modunu pasifleþtir"},
#endif
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_CART_ATTACH_DETACH_RESET,    N_("Reset machine if a cartridge is attached or detached")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_CART_ATTACH_DETACH_RESET_DA, "Reset maskinen hvis et cartridge tilsluttes eller frakobles"},
/* de */ {IDCLS_CART_ATTACH_DETACH_RESET_DE, "Reset der Maschine wenn ein Erweiterungsmodul eingelegt oder entfernt wird"},
/* fr */ {IDCLS_CART_ATTACH_DETACH_RESET_FR, "Réinitialiser si une cartouche est insérée ou retirée"},
/* hu */ {IDCLS_CART_ATTACH_DETACH_RESET_HU, "Reset a cartridge csatolásakorgy leválasztásakor"},
/* it */ {IDCLS_CART_ATTACH_DETACH_RESET_IT, "Fare il reset della macchina se una cartuccia è collegata o rimossa"},
/* ko */ {IDCLS_CART_ATTACH_DETACH_RESET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_CART_ATTACH_DETACH_RESET_NL, "Reset machine als een cartridge wordt gekoppeld of ontkoppeld"},
/* ru */ {IDCLS_CART_ATTACH_DETACH_RESET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_CART_ATTACH_DETACH_RESET_SV, "Nollställ maskinen om en insticksmodul kopplas till eller från"},
/* tr */ {IDCLS_CART_ATTACH_DETACH_RESET_TR, "Bir kartuþ takýlýr ya da çýkartýlýrsa makineyi resetle"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_CART_ATTACH_DETACH_NO_RESET,    N_("Do not reset machine if a cartridge is attached or detached")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_DA, "Reset ikke maskinen hvis et cartridge tilsluttes eller frakobles"},
/* de */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_DE, "Kein Reset der Maschine wenn ein Erweiterungsmodul eingelegt oder entfernt wird"},
/* fr */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_FR, "Ne pas réinitialiser si une cartouche est insérée ou retirée"},
/* hu */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_HU, "Nincs reset a cartridge csatolásakorgy leválasztásakor"},
/* it */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_IT, "Non fare il reset della macchina se una cartuccia è collegata o rimossa"},
/* ko */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_NL, "Reset machine niet als een cartridge wordt gekoppeld of ontkoppeld"},
/* ru */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_SV, "Nollställ inte maskinen om en insticksmodul kopplas till eller från"},
/* tr */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_TR, "Bir kartuþ takýlýr ya da çýkartýlýrsa makineyi resetleme"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_CRT_CART,    N_("Attach CRT cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_CRT_CART_DA, "Tilslut CRT-cartridge image"},
/* de */ {IDCLS_ATTACH_CRT_CART_DE, "CRT Erweiterungsmodul Image einlegen"},
/* fr */ {IDCLS_ATTACH_CRT_CART_FR, "Insérer une cartouche CRT"},
/* hu */ {IDCLS_ATTACH_CRT_CART_HU, "CRT cartridge képmás csatolása"},
/* it */ {IDCLS_ATTACH_CRT_CART_IT, "Seleziona immagine cartuccia CRT"},
/* ko */ {IDCLS_ATTACH_CRT_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_CRT_CART_NL, "Koppel CRT cartridge bestand aan"},
/* ru */ {IDCLS_ATTACH_CRT_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_CRT_CART_SV, "Anslut CRT-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_CRT_CART_TR, "CRT kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_GENERIC_8KB_CART,    N_("Attach raw 8KB cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_GENERIC_8KB_CART_DA, "Tilslut råt 8KB-cartridge image"},
/* de */ {IDCLS_ATTACH_GENERIC_8KB_CART_DE, "8KB Erweiterungsmodul (raw) Image einlegen"},
/* fr */ {IDCLS_ATTACH_GENERIC_8KB_CART_FR, "Insérer une cartouche 8KO"},
/* hu */ {IDCLS_ATTACH_GENERIC_8KB_CART_HU, "Nyers 8KB-os cartridge képmás csatolása"},
/* it */ {IDCLS_ATTACH_GENERIC_8KB_CART_IT, "Seleziona immagine cartuccia di 8KB"},
/* ko */ {IDCLS_ATTACH_GENERIC_8KB_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_GENERIC_8KB_CART_NL, "Koppel binair 8KB cartridge bestand"},
/* ru */ {IDCLS_ATTACH_GENERIC_8KB_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_GENERIC_8KB_CART_SV, "Anslut rå 8KB-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_GENERIC_8KB_CART_TR, "Düz 8KB kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_GENERIC_16KB_CART,    N_("Attach raw 16KB cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_GENERIC_16KB_CART_DA, "Tilslut råt 16KB-cartridge image"},
/* de */ {IDCLS_ATTACH_GENERIC_16KB_CART_DE, "16KB Erweiterungsmodul (raw) Image einlegen"},
/* fr */ {IDCLS_ATTACH_GENERIC_16KB_CART_FR, "Insérer une cartouche 16KO"},
/* hu */ {IDCLS_ATTACH_GENERIC_16KB_CART_HU, "Nyers 16KB-os cartridge képmás csatolása"},
/* it */ {IDCLS_ATTACH_GENERIC_16KB_CART_IT, "Seleziona immagine cartuccia di 16KB"},
/* ko */ {IDCLS_ATTACH_GENERIC_16KB_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_GENERIC_16KB_CART_NL, "Koppel binair 16KB cartridge bestand"},
/* ru */ {IDCLS_ATTACH_GENERIC_16KB_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_GENERIC_16KB_CART_SV, "Anslut rå 16KB-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_GENERIC_16KB_CART_TR, "Düz 16KB kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART,    N_("Attach generic 16kB Ultimax cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_DA, "Tilslut standard 16KB Ultimax cartridge image"},
/* de */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_DE, "Generisches 16kB Ultimax Erweiterungsmodul Image einlegen"},
/* fr */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_IT, "Seleziona immagine cartuccia Ultimax generica di 16kB"},
/* ko */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_NL, "Koppel algemeen 16KB Ultimax cartridge bestand"},
/* ru */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_SV, "Anslut vanlig 16KB Ultimax-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_TR, "Jenerik 16KB Ultimax kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_STARDOS_CART,    N_("Attach raw 16KB Stardos cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_STARDOS_CART_DA, "Tilslut råt 16KB StarDOS cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_STARDOS_CART_DE, "16kB Stardos Erweiterungsmodul Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_STARDOS_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_STARDOS_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_STARDOS_CART_IT, "Seleziona immagine cartuccia Stardos di 16KB"},
/* ko */ {IDCLS_ATTACH_RAW_STARDOS_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_STARDOS_CART_NL, "Koppel binair 16KB Stardos cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_STARDOS_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_STARDOS_CART_SV, "Anslut rå 16KB Stardos-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_STARDOS_CART_TR, "Düz 16KB Stardos kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART,    N_("Attach raw 32KB Action Replay MK4 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_DA, "Tilslut råt 32KB Action Replay MK4 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_DE, "32kB Action Replay MK4 Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_IT, "Seleziona immagine cartuccia Action Replay MK4 di 326KB"},
/* ko */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_NL, "Koppel binair 32KB Action Replay MK4 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_SV, "Anslut rå 32KB-Action Replay MK4-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_TR, "Düz 32KB Action Replay MK4 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART,    N_("Attach raw 16kB Action Replay MK2 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_DA, "Tilslut råt 16KB Action Replay MK2 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_DE, "16kB Action Replay MK2 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_IT, "Seleziona immagine cartuccia Action Replay MK2 di 16KB"},
/* ko */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_NL, "Koppel binair 16kB Action Replay MK2 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_SV, "Anslut rå 16KB-Action Replay MK2-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_TR, "Düz 16kB Action Replay MK2 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART,    N_("Attach raw 16KB Action Replay MK3 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_DA, "Tilslut råt 16KB Action Replay MK3 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_DE, "16kB Action Replay MK3 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_IT, "Seleziona immagine cartuccia Action Replay MK3 di 16KB"},
/* ko */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_NL, "Koppel binair 16KB Action Replay MK3 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_SV, "Anslut rå 16KB-Action Replay MK3-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_TR, "Düz 16KB Action Replay MK3 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART,    N_("Attach raw 32KB Action Replay cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_DA, "Tilslut råt 32KB Action Replay cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_DE, "32kB Action Replay Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_FR, "Insérer une cartouche Action Replay 32KO"},
/* hu */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_HU, "32KB-os Action Replay cartridge képmás csatolása"},
/* it */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_IT, "Seleziona immagine cartuccia Action Replay di 32KB"},
/* ko */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_NL, "Koppel binair 32KB Action Replay cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_SV, "Anslut rå 32KB-Action Replay-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_TR, "Düz 32KB Action Replay kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_CAPTURE_CART,    N_("Attach raw 8kB Capture cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_CAPTURE_CART_DA, "Tilslut råt 8KB cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_CAPTURE_CART_DE, "8kB Capture Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_CAPTURE_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_CAPTURE_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_CAPTURE_CART_IT, "Seleziona immagine cartuccia Capture di 8KB"},
/* ko */ {IDCLS_ATTACH_RAW_CAPTURE_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_CAPTURE_CART_NL, "Koppel binair 8kB Capture cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_CAPTURE_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_CAPTURE_CART_SV, "Anslut rå 8KB Capture-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_CAPTURE_CART_TR, "Düz 8kB Capture kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_COMAL80_CART,    N_("Attach raw 64kB Comal 80 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_COMAL80_CART_DA, "Tilslut råt 64KB Comal 80 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_COMAL80_CART_DE, "64kB Comal 80 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_COMAL80_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_COMAL80_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_COMAL80_CART_IT, "Seleziona immagine cartuccia Comal 80 di 64kB"},
/* ko */ {IDCLS_ATTACH_RAW_COMAL80_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_COMAL80_CART_NL, "Koppel binair 64kB Comal 80 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_COMAL80_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_COMAL80_CART_SV, "Anslut rå 64kB Comal 80-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_COMAL80_CART_TR, "Düz 64kB Comal 80 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_DELA_EP256_CART,    N_("Attach raw Dela EP256 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_DA, "Tilslut råt Dela EP256 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_DE, "Dela EP256 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_IT, "Seleziona immagine cartuccia Dela EP256"},
/* ko */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_NL, "Koppel binair Dela EP256 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_SV, "Anslut rå dela EP256-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_TR, "Düz Dela EP256 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_DELA_EP64_CART,    N_("Attach raw Dela EP64 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_DA, "Tilslut råt Dela EP64 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_DE, "Dela EP64 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_IT, "Seleziona immagine cartuccia Dela EP64"},
/* ko */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_NL, "Koppel binair Dela EO64 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_SV, "Anslut rå Dela EP64-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_TR, "Düz Dela EP64 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART,    N_("Attach raw Dela EP7x8 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_DA, "Tilslut råt Dela EP7x8 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_DE, "Dela EP7x8 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_IT, "Seleziona immagine cartuccia Dela EP7x8"},
/* ko */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_NL, "Koppel binair Dela ep7x8 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_SV, "Anslut rå Dela EP7x8-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_TR, "Düz Dela EP7x8 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_DINAMIC_CART,    N_("Attach raw 128kB Dinamic cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_DINAMIC_CART_DA, "Tilslut råt 128KB Dinamic cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_DINAMIC_CART_DE, "128kB Dinamic Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_DINAMIC_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_DINAMIC_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_DINAMIC_CART_IT, "Seleziona immagine cartuccia Dinamic di 128kB"},
/* ko */ {IDCLS_ATTACH_RAW_DINAMIC_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_DINAMIC_CART_NL, "Koppel binair 128kB Dinamic cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_DINAMIC_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_DINAMIC_CART_SV, "Anslut rå 12kB Dinamic-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_DINAMIC_CART_TR, "Düz 128kB Dinamic kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART,    N_("Attach raw 8kB Diashow-Maker cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_DA, "Tilslut råt 8KB Diashow-Maker cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_DE, "8kB Diashow-Maker Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_IT, "Seleziona immagine cartuccia Diashow-Maker di 8KB"},
/* ko */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_NL, "Koppel binair 8kB Diashow-Maker cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_SV, "Anslut rå 8kB Diashow-Maker-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_TR, "Düz 8kB Diashow-Maker kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_DQBB_CART,    N_("Attach raw 16kB Double Quick Brown Box cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_DQBB_CART_DA, "Tilslut råt 16kB Double Quick Brown Box cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_DQBB_CART_DE, "16kB Double Quick Brown Box Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_DQBB_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_DQBB_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_DQBB_CART_IT, "Seleziona immagine cartuccia Double Quick Brown Box di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_DQBB_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_DQBB_CART_NL, "Koppel binair 16kB Double Quick Brown Box cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_DQBB_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_DQBB_CART_SV, "Anslut rå 16KB Double Quick Brown Box-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_DQBB_CART_TR, "Düz 16kB Double Quick Brown Box kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART,    N_("Attach raw EasyFlash cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_DA, "Tilslut råt EasyFlash cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_DE, "Easyflash Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_IT, "Seleziona immagine cartuccia EasyFlash"},
/* ko */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_NL, "Koppel binair EasyFlash cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_SV, "Anslut rå EasyFlash-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_TR, "Düz EasyFlash kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART,    N_("Attach raw 64KB Retro Replay cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_DA, "Tilslut råt 64KB-Retro Replay-cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_DE, "64kB Retro Replay Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_FR, "Insérer une cartouche Retro Replay 64KO"},
/* hu */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_HU, "64KB-os Retro Replay cartridge képmás csatolása"},
/* it */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_IT, "Seleziona immagine cartuccia Retro Replay di 64KB"},
/* ko */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_NL, "Koppel binair 64KB Retro Replay cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_SV, "Anslut rå 64KB-Retro Replay-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_TR, "Düz 64KB Retro Replay kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART,    N_("Attach raw 8kB REX Utility cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_DA, "Tilslut råt 8KB REX Utility cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_DE, "8kB REX Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_IT, "Seleziona immagine cartuccia REX Utility di 8kB"},
/* ko */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_NL, "Koppel binair 8kB REX Utility cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_SV, "Anslut rå 8kB REX Utility-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_TR, "Düz 8kB REX Utility kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_SS64_CART,    N_("Attach raw 4kB Snapshot 64 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_SS64_CART_DA, "Tilslut råt 4KB Snapshot 64 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_SS64_CART_DE, "4kB Snapshot 64 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_SS64_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_SS64_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_SS64_CART_IT, "Seleziona immagine cartuccia Snapshot 64 di 4kB"},
/* ko */ {IDCLS_ATTACH_RAW_SS64_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_SS64_CART_NL, "Koppel binair 4kB Snapshot 64 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_SS64_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_SS64_CART_SV, "Anslut rå 4kB Snapshot 64-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_SS64_CART_TR, "Düz 4kB Snapshot 64 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_IDE64_CART,    N_("Attach raw 64KB IDE64 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_IDE64_CART_DA, "Tilslut råt 64KB IDE64-cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_IDE64_CART_DE, "64kB IDE64 Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_IDE64_CART_FR, "Insérer une cartouche IDE64 64KO"},
/* hu */ {IDCLS_ATTACH_RAW_IDE64_CART_HU, "64KB-os IDE64 cartridge képmás csatolása"},
/* it */ {IDCLS_ATTACH_RAW_IDE64_CART_IT, "Seleziona immagine cartuccia IDE64 di 64KB"},
/* ko */ {IDCLS_ATTACH_RAW_IDE64_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_IDE64_CART_NL, "Koppel binair 64KB IDE64 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_IDE64_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_IDE64_CART_SV, "Anslut rå 64KB IDE64-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_IDE64_CART_TR, "Düz 64KB IDE64 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART,    N_("Attach raw 32KB Atomic Power cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_DA, "Tilslut råt 32KB Atomic Power-cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_DE, "32kB Atomic Power Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_FR, "Insérer une cartouche Atomic Power 32KO"},
/* hu */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_HU, "32KB-os Atomic Power cartridge képmás csatolása"},
/* it */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_IT, "Seleziona immagine cartuccia Atomic Power di 32KB"},
/* ko */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_NL, "Koppel binair 32KB Atomic Power cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_SV, "Anslut rå 32KB Atomic Power-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_TR, "Düz 32KB Atomic Power kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART,    N_("Attach raw 8KB Epyx FastLoad cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_DA, "Tilslut råt 8KB Epyx FastLoad cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_DE, "8kB Epyx Fastload Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_IT, "Seleziona immagine cartuccia Epyx FastLoad di 8KB"},
/* ko */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_NL, "Koppel binair 8KB Epyx FastLoad cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_SV, "Anslut rå 8KB Epyx FastLoad-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_TR, "Düz 8KB Epyx FastLoad kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_EXOS_CART,    N_("Attach raw 8kB EXOS cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_EXOS_CART_DA, "Tilslut råt 8KB EXOS cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_EXOS_CART_DE, "8kB EXOS Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_EXOS_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_EXOS_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_EXOS_CART_IT, "Seleziona immagine cartuccia EXOS di 8KB"},
/* ko */ {IDCLS_ATTACH_RAW_EXOS_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_EXOS_CART_NL, "Koppel binair 8kB EXOS cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_EXOS_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_EXOS_CART_SV, "Anslut rå 8kB EXOS-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_EXOS_CART_TR, "Düz 8kB EXOS kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_EXPERT_CART,    N_("Attach raw 8kB Expert Cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_EXPERT_CART_DA, "Tilslut råt 8KB Expert cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_EXPERT_CART_DE, "8kB Expert Cartridge Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_EXPERT_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_EXPERT_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_EXPERT_CART_IT, "Seleziona immagine cartuccia Expert Cartridge di 8kB"},
/* ko */ {IDCLS_ATTACH_RAW_EXPERT_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_EXPERT_CART_NL, "Koppel binair 8kB Expert Cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_EXPERT_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_EXPERT_CART_SV, "Anslut rå 8kB Expert Cartridge-avbilding"},
/* tr */ {IDCLS_ATTACH_RAW_EXPERT_CART_TR, "Düz 8kB Expert Kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_FC1_CART,    N_("Attach raw 16kB Final Cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_FC1_CART_DA, "Tilslut råt 16KB Final Cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_FC1_CART_DE, "16kB Final Cartridge Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_FC1_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_FC1_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_FC1_CART_IT, "Seleziona immagine cartuccia Final Cartridge di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_FC1_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_FC1_CART_NL, "Koppel binair 16kB Final Cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_FC1_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_FC1_CART_SV, "Anslut rå 16kB Final Cartridge-avbilding"},
/* tr */ {IDCLS_ATTACH_RAW_FC1_CART_TR, "Düz 16kB Final kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_FC3_CART,    N_("Attach raw 64kB Final Cartridge III image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_FC3_CART_DA, "Tilslut råt 64KB Final Cartridge III image"},
/* de */ {IDCLS_ATTACH_RAW_FC3_CART_DE, "64kB Final Cartridge Image III (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_FC3_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_FC3_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_FC3_CART_IT, "Seleziona immagine cartuccia Final Cartridge III di 64kB"},
/* ko */ {IDCLS_ATTACH_RAW_FC3_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_FC3_CART_NL, "Koppel binair 16kB Final Cartridge III bestand"},
/* ru */ {IDCLS_ATTACH_RAW_FC3_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_FC3_CART_SV, "Anslut rå 64kB Final Cartridge III-avbilding"},
/* tr */ {IDCLS_ATTACH_RAW_FC3_CART_TR, "Düz 64kB Final Cartridge III imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_FCPLUS_CART,    N_("Attach raw 32kB Final Cartridge Plus image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_FCPLUS_CART_DA, "Tilslut råt 32KB Final Cartridge Plus image"},
/* de */ {IDCLS_ATTACH_RAW_FCPLUS_CART_DE, "32kB Final Cartridge Plus Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_FCPLUS_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_FCPLUS_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_FCPLUS_CART_IT, "Seleziona immagine cartuccia Final Cartridge Plus di 32kB"},
/* ko */ {IDCLS_ATTACH_RAW_FCPLUS_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_FCPLUS_CART_NL, "Koppel binair 32kB Final Cartridge Plus bestand"},
/* ru */ {IDCLS_ATTACH_RAW_FCPLUS_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_FCPLUS_CART_SV, "Anslut rå 32kB Final Cartridge Plus-fil"},
/* tr */ {IDCLS_ATTACH_RAW_FCPLUS_CART_TR, "Düz 32kB Final Cartridge Plus imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART,    N_("Attach raw 8kB Freeze Frame image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_DA, "Tilslut råt 8KB Freeze Frame image"},
/* de */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_DE, "8kB Freeze Frame Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_IT, "Seleziona immagine cartuccia Freeze Frame di 8kb"},
/* ko */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_NL, "Koppel binair 8kB Freeze Frame cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_SV, "Anslut rå 8kB Freeze Frame-avbilding"},
/* tr */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_TR, "Düz 8kB Freeze Frame imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART,    N_("Attach raw 32kB Freeze Machine image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_DA, "Tilslut råt 32KB Freeze Machine image"},
/* de */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_DE, "8kB Freeze Machine Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_IT, "Seleziona immagine cartuccia Freeze Machine di 32kb"},
/* ko */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_NL, "Koppel binair 32kB Freeze Machine cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_SV, "Anslut rå 32kB Freeze Machine-avbilding"},
/* tr */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_TR, "Düz 32kB Freeze Machine imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_FP_PP_CART,    N_("Attach raw 128kB Fun Play/Power Play cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_FP_PP_CART_DA, "Tilslut råt 128KB Fun Play/Power Play cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_FP_PP_CART_DE, "128kB Fun Play/Power Play Cartridge  Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_FP_PP_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_FP_PP_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_FP_PP_CART_IT, "Seleziona immagine cartuccia Fun Play/Power Play di 128kB"},
/* ko */ {IDCLS_ATTACH_RAW_FP_PP_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_FP_PP_CART_NL, "Koppel binair 128kB Fun Play/Power Play cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_FP_PP_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_FP_PP_CART_SV, "Anslut rå 128kB Fun Play/Power Play-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_FP_PP_CART_TR, "Düz 128kB Fun Play/Power Play kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_SS4_CART,    N_("Attach raw 32KB Super Snapshot V4 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_SS4_CART_DA, "Tilslut råt 32KB Super Snapshot V4 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_SS4_CART_DE, "32kB Super Snapshot V4 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_SS4_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_SS4_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_SS4_CART_IT, "Seleziona immagine cartuccia Super Snapshot V4 di 32KB"},
/* ko */ {IDCLS_ATTACH_RAW_SS4_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_SS4_CART_NL, "Koppel binair 32KB Super Snapshot V4 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_SS4_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_SS4_CART_SV, "Anslut rå 32KB Super Snapshot V4-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_SS4_CART_TR, "Düz 32KB Super Snapshot V4 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_SS5_CART,    N_("Attach raw 64KB Super Snapshot V5 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_SS5_CART_DA, "Tilslut råt 64KB Super Snapshot V5 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_SS5_CART_DE, "64kB Super Snapshot V5 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_SS5_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_SS5_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_SS5_CART_IT, "Seleziona immagine cartuccia Super Snapshot V5 di 64KB"},
/* ko */ {IDCLS_ATTACH_RAW_SS5_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_SS5_CART_NL, "Koppel binair 64KB Super Snapshot V5 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_SS5_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_SS5_CART_SV, "Anslut rå 64KB-Super Snapshot V5-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_SS5_CART_TR, "Düz 64KB Super Snapshot V5 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_CBM_IEEE488_CART,    N_("Attach IEEE-488 Interface cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_CBM_IEEE488_CART_DA, "Tilslut IEEE-488 interface cartridge image"},
/* de */ {IDCLS_ATTACH_CBM_IEEE488_CART_DE, "IEEE Schnittstellen Erweiterungsmodul Image einlegen"},
/* fr */ {IDCLS_ATTACH_CBM_IEEE488_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_CBM_IEEE488_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_CBM_IEEE488_CART_IT, "Seleziona immagine cartuccia interfaccia IEEE"},
/* ko */ {IDCLS_ATTACH_CBM_IEEE488_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_CBM_IEEE488_CART_NL, "Koppel IEEE-488 Interface cartridge bestand"},
/* ru */ {IDCLS_ATTACH_CBM_IEEE488_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_CBM_IEEE488_CART_SV, "Anslut IEEE-488-gränssnittsavbildningsfil"},
/* tr */ {IDCLS_ATTACH_CBM_IEEE488_CART_TR, "IEEE-488 Arabirimi kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ISEPIC_CART,    N_("Attach raw 2kB ISEPIC cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ISEPIC_CART_DA, "Tilslut råt 2KB ISEPIC-cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ISEPIC_CART_DE, "2kB ISEPIC Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ISEPIC_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_ISEPIC_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_ISEPIC_CART_IT, "Seleziona immagine cartuccia ISEPIC di 2kB"},
/* ko */ {IDCLS_ATTACH_RAW_ISEPIC_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ISEPIC_CART_NL, "Koppel binair 2kB ISEPIC cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_ISEPIC_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ISEPIC_CART_SV, "Anslut rå 2kB ISEPIC-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_ISEPIC_CART_TR, "Düz 2kB ISEPIC kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_KCS_CART,    N_("Attach raw 16kB KCS Power cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_KCS_CART_DA, "Tilslut råt 16KB KCS Power Cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_KCS_CART_DE, "16kB KCS Power Cartridge Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_KCS_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_KCS_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_KCS_CART_IT, "Seleziona immagine cartuccia KCS Power di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_KCS_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_KCS_CART_NL, "Koppel binair 16kB KSC Power cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_KCS_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_KCS_CART_SV, "Anslut rå 16KB KCS Power-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_KCS_CART_TR, "Düz 16kB KCS Power kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_KINGSOFT_CART,    N_("Attach raw 24kB Kingsoft cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_DA, "Tilslut råt 8KB Kingsoft cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_DE, "24kB MAC 5 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_IT, "Seleziona immagine cartuccia Kingsoft di 24kB"},
/* ko */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_NL, "Koppel binair 24kB Kingsoft cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_SV, "Anslut rå 24kB Kingsoft-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_TR, "Düz 24kB Kingsoft kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MACH5_CART,    N_("Attach raw 8kB MACH 5 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MACH5_CART_DA, "Tilslut råt 8KB MACH 5 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MACH5_CART_DE, "8kB MAC 5 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MACH5_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MACH5_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MACH5_CART_IT, "Seleziona immagine cartuccia MACH 5 di 8kB"},
/* ko */ {IDCLS_ATTACH_RAW_MACH5_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_MACH5_CART_NL, "Koppel binair 8kB MACH 5 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_MACH5_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MACH5_CART_SV, "Anslut rå 8kB MACH 5-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_MACH5_CART_TR, "Düz 8kB MACH 5 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART,    N_("Attach raw 32/64/128kB Magic Desk cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_DA, "Tilslut råt 32/64/128KB Magic Desk cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_DE, "32/64/128kB Magic Desk Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_IT, "Seleziona immagine cartuccia Magic Desk di 32/64/128kB"},
/* ko */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_NL, "Koppel binair 32/64/128kB Magic Desk cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_SV, "Anslut rå 32/64/128kB Magic Desk-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_TR, "Düz 32/64/128kB Magic Desk kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART,    N_("Attach raw Magic Formel cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_DA, "Tilslut råt Magic Formel cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_DE, "Magic Formel Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_IT, "Seleziona immagine cartuccia Magic Formel"},
/* ko */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_NL, "Koppel binair Magic Formel cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_SV, "Anslut rå Magic Romel-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_TR, "Düz Magic Formel kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART,    N_("Attach raw 8kB Mikro Assembler cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_DA, "Tilslut råt 8kB Mikro Assembler cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_DE, "8kB Mikro Assembler Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_IT, "Seleziona immagine cartuccia Mikro Assembler di 8kB"},
/* ko */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_NL, "Koppel binair 8KB Mikro Assembler cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_SV, "Anslut rå 8kB Mikro Assembler-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_TR, "Düz 8kB Mikro Assembler kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MMC64_CART,    N_("Attach raw 8kB MMC64 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MMC64_CART_DA, "Tilslut råt 8KB MMC64 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MMC64_CART_DE, "8kB MMC64 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MMC64_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MMC64_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MMC64_CART_IT, "Seleziona immagine cartuccia MMC64 di 8kB"},
/* ko */ {IDCLS_ATTACH_RAW_MMC64_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_MMC64_CART_NL, "Koppel binair 8kB MMC64 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_MMC64_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MMC64_CART_SV, "Anslut rå 8kB MMC64-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_MMC64_CART_TR, "Düz 8kB MMC64 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART,    N_("Attach raw 512kB MMC Replay cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_DA, "Tilslut råt 512KB MMC Replay cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_DE, "512kB MMC Replay Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_IT, "Seleziona immagine cartuccia MMC Replay di 512kB"},
/* ko */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_NL, "Koppel binair 512kB MMC Replay cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_SV, "Anslut rå 512kB MMC Replay-avbildningsfil"},
/* tr */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_TR, "Düz 512kB MMC Replay kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART,    N_("Attach raw 16kB Magic Voice cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_DA, "Tilslut råt 16KB Magic Voice cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_DE, "16kB Magic Voice Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_IT, "Seleziona immagine cartuccia Magic Voice di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_NL, "Koppel binair 16kB Magic Voice cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_SV, "Anslut rå 16kB Magic Voice-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_TR, "Düz 16kB Magic Voice kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_OCEAN_CART,    N_("Attach raw Ocean cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_OCEAN_CART_DA, "Tilslut råt Ocean cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_OCEAN_CART_DE, "Ocean Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_OCEAN_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_OCEAN_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_OCEAN_CART_IT, "Seleziona immagine cartuccia Ocean"},
/* ko */ {IDCLS_ATTACH_RAW_OCEAN_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_OCEAN_CART_NL, "Koppel binair Ocean cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_OCEAN_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_OCEAN_CART_SV, "Anslut rå Ocean-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_OCEAN_CART_TR, "Düz Ocean kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_WESTERMANN_CART,    N_("Attach raw 16KB Westermann Learning cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_DA, "Tilslut råt 16KB Westermann Learning cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_DE, "16kB Westermann learning Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_IT, "Seleziona immagine cartuccia Westermann Learning di 16KB"},
/* ko */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_NL, "Koppel binair 16kB Westermann Learning cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_SV, "Anslut rå 16KB Westermann Learning-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_TR, "Düz 16KB Westermann Learning kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_WARPSPEED_CART,    N_("Attach raw 8kB Warp Speed cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_DA, "Tilslut råt 8KB Warp Speed cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_DE, "8kB Warp Speed Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_IT, "Seleziona immagine cartuccia Warp Speed di 8kB"},
/* ko */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_NL, "Koppel binair 8kB Warp Speed cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_SV, "Anslut rå 8kB-Warp Speed-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_TR, "Düz 8kB Warp Speed kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ZAXXON_CART,    N_("Attach raw 16kB Zaxxon cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ZAXXON_CART_DA, "Tilslut råt 16KB Zaxxon cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ZAXXON_CART_DE, "16kB Zaxxon Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ZAXXON_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_ZAXXON_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_ZAXXON_CART_IT, "Seleziona immagine cartuccia Zaxxon di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_ZAXXON_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ZAXXON_CART_NL, "Koppel binair 16kB Zaxxon cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_ZAXXON_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ZAXXON_CART_SV, "Anslut rå 16kB Zaxxon-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_ZAXXON_CART_TR, "Düz 16kB Zaxxon kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_PAGEFOX_CART,    N_("Attach raw 64KB Pagefox cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_DE, ""},  /* fuzzy */
/* fr */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_NL, ""},  /* fuzzy */
/* ru */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_TR, ""},  /* fuzzy */
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_P64_CART,    N_("Attach raw 256KB Prophet 64 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_P64_CART_DA, "Tilslut råt 256KB Prophet 64 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_P64_CART_DE, "256KB Prophet 64 Erweiterungsmodul Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_P64_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_P64_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_P64_CART_IT, "Seleziona immagine cartuccia Prophet 64 di 256KB"},
/* ko */ {IDCLS_ATTACH_RAW_P64_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_P64_CART_NL, "Koppel binair 256KB Prophet 64 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_P64_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_P64_CART_SV, "Anslut rå 256KB Prophet 64-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_P64_CART_TR, "Düz 256KB Prophet 64 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_RAMCART_CART,    N_("Attach raw RamCart cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_RAMCART_CART_DA, "Tilslut råt RamCart cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_RAMCART_CART_DE, "RamCart Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_RAMCART_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_RAMCART_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_RAMCART_CART_IT, "Seleziona immagine cartuccia RamCart"},
/* ko */ {IDCLS_ATTACH_RAW_RAMCART_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_RAMCART_CART_NL, "Koppel binair RamCart cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_RAMCART_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_RAMCART_CART_SV, "Anslut rå RamCart-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_RAMCART_CART_TR, "Düz RamCart kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_REU_CART,    N_("Attach raw REU cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_REU_CART_DA, "Tilslut råt REU cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_REU_CART_DE, "REU Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_REU_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_REU_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_REU_CART_IT, "Seleziona immagine cartuccia REU"},
/* ko */ {IDCLS_ATTACH_RAW_REU_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_REU_CART_NL, "Koppel binair REU cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_REU_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_REU_CART_SV, "Anslut rå REU-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_REU_CART_TR, "Düz REU kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_REX_EP256_CART,    N_("Attach raw REX EP256 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_REX_EP256_CART_DA, "Tilslut råt REX EP256 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_REX_EP256_CART_DE, "REX EP256 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_REX_EP256_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_REX_EP256_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_REX_EP256_CART_IT, "Seleziona immagine cartuccia REX EP256"},
/* ko */ {IDCLS_ATTACH_RAW_REX_EP256_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_REX_EP256_CART_NL, "Koppel binair REX EP256 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_REX_EP256_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_REX_EP256_CART_SV, "Anslut rå REX EP256-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_REX_EP256_CART_TR, "Düz REX EP256 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ROSS_CART,    N_("Attach raw 16/32kB ROSS cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ROSS_CART_DA, "Tilslut råt 16/32KB ROSS cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ROSS_CART_DE, "16/32kB ROSS Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ROSS_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_ROSS_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_ROSS_CART_IT, "Seleziona immagine cartuccia ROSS di 16/32kB"},
/* ko */ {IDCLS_ATTACH_RAW_ROSS_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ROSS_CART_NL, "Koppel binair 16/32kB ROSS cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_ROSS_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ROSS_CART_SV, "Anslut rå 16/32kB ROSS-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_ROSS_CART_TR, "Düz 16/32kB ROSS kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART,    N_("Attach raw 8KB Game Killer cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_DA, "Tilslut råt 8KB Game Killer cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_DE, "8KB Game Killer Erweiterungsmodul (raw) Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_IT, "Seleziona immagine cartuccia Game Killer di 8KB"},
/* ko */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_NL, "Koppel binair 8KB Game Killer cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_SV, "Anslut rå 8KB Game Killer-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_TR, "Düz 8KB Game Killer kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_GEORAM_CART,    N_("Attach raw GEO-RAM cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_GEORAM_CART_DA, "Tilslut råt GEO-RAM cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_GEORAM_CART_DE, "GEO-RAM Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_GEORAM_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_GEORAM_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_GEORAM_CART_IT, "Seleziona immagine cartuccia GEO-RAM"},
/* ko */ {IDCLS_ATTACH_RAW_GEORAM_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_GEORAM_CART_NL, "Koppel binair GEO-RAM cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_GEORAM_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_GEORAM_CART_SV, "Anslut rå GEO-RAM-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_GEORAM_CART_TR, "Düz GEO-RAM kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART,    N_("Attach raw 512kB Game System cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_DA, "Tilslut råt 512KB Game System cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_DE, "512kB Game System Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_IT, "Seleziona immagine cartuccia Game System di 512kB"},
/* ko */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_NL, "Koppel binair 512kB Game System cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_SV, "Anslut rå 512kB Game System-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_TR, "Düz 512kB Game System kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c, c64/expert.c */
/* en */ {IDCLS_ENABLE_EXPERT_CART,    N_("Enable the Expert Cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_EXPERT_CART_DA, "Aktivér Expert Cartridge"},
/* de */ {IDCLS_ENABLE_EXPERT_CART_DE, "Expert Cartridge aktivieren"},
/* fr */ {IDCLS_ENABLE_EXPERT_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_EXPERT_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_EXPERT_CART_IT, "Attiva Expert Cartridge"},
/* ko */ {IDCLS_ENABLE_EXPERT_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_EXPERT_CART_NL, "Activeer Expert Cartridge"},
/* ru */ {IDCLS_ENABLE_EXPERT_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_EXPERT_CART_SV, "Aktivera Expert Cartridge"},
/* tr */ {IDCLS_ENABLE_EXPERT_CART_TR, "Expert Kartuþu'nu aktif et"},
#endif

/* c64/expert.c */
/* en */ {IDCLS_DISABLE_EXPERT_CART,    N_("Disable the Expert Cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_EXPERT_CART_DA, "Deaktivér Expert Cartridge"},
/* de */ {IDCLS_DISABLE_EXPERT_CART_DE, "Expert Cartridge deaktivieren"},
/* fr */ {IDCLS_DISABLE_EXPERT_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_EXPERT_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_EXPERT_CART_IT, "Disattiva Expert Cartridge"},
/* ko */ {IDCLS_DISABLE_EXPERT_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_EXPERT_CART_NL, "Expert Cartridge uitschakelen"},
/* ru */ {IDCLS_DISABLE_EXPERT_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_EXPERT_CART_SV, "Inaktivera Expert Cartridge"},
/* tr */ {IDCLS_DISABLE_EXPERT_CART_TR, "Expert Kartuþu'nu pasifleþtir"},
#endif

/* c64/expert.c */
/* en */ {IDCLS_SET_EXPERT_FILENAME,    N_("Set Expert Cartridge image name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_EXPERT_FILENAME_DA, "Vælg Expert cartridge image-navn"},
/* de */ {IDCLS_SET_EXPERT_FILENAME_DE, "Expert Cartridge Imagedateiname setzen"},
/* fr */ {IDCLS_SET_EXPERT_FILENAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_EXPERT_FILENAME_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_EXPERT_FILENAME_IT, "Imposta nome immagine Expert Cartridge"},
/* ko */ {IDCLS_SET_EXPERT_FILENAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_EXPERT_FILENAME_NL, "Zet Expert Cartridge bestandsnaam"},
/* ru */ {IDCLS_SET_EXPERT_FILENAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_EXPERT_FILENAME_SV, "Välj Expert Cartridge-modulfil"},
/* tr */ {IDCLS_SET_EXPERT_FILENAME_TR, "Expert Kartuþ imaj ismini belirle"},
#endif

/* c64/expert.c */
/* en */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE,    N_("Allow writing to Expert Cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_DA, "Tillad skrivning til Expert Cartridge image"},
/* de */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_DE, "Schreibzugriff auf Expert Cartridge Image erlauben"},
/* fr */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_IT, "Attiva scrittura su immagine Expert Cartridge"},
/* ko */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_NL, "Activeer schrijven naar Expert Cartridge bestand"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_SV, "Tillåt skrivning till Expert Cartridge-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_TR, "Expert Kartuþ imajýna yazmaya izin ver"},
#endif

/* c64/expert.c */
/* en */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE,    N_("Do not write to Expert Cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_DA, "Skriv ikke til Expert Cartridge image"},
/* de */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_DE, "Kein Schreibzugriff auf Expert Cartridge Image"},
/* fr */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_IT, "Disattiva scrittura su immagine Expert Cartridge"},
/* ko */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_NL, "Schrijf niet naar Expert Cartridge bestand"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_SV, "Skriv inte till Expert Cartridge-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_TR, "Expert Kartuþ imajýna yazma"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_DISABLE_CART,    N_("Disable default cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_CART_DA, "Deaktivér standard cartridge"},
/* de */ {IDCLS_DISABLE_CART_DE, "Standard Modul deaktivieren"},
/* fr */ {IDCLS_DISABLE_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_CART_HU, "Alap cartridge tiltása"},
/* it */ {IDCLS_DISABLE_CART_IT, "Disattiva cartuccia predefinita"},
/* ko */ {IDCLS_DISABLE_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_CART_NL, "De standaard cartridge uitschakelen"},
/* ru */ {IDCLS_DISABLE_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_CART_SV, "Inaktivera standardinsticksmodul"},
/* tr */ {IDCLS_DISABLE_CART_TR, "Varsayýlan kartuþu pasifleþtir"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_SPECIFY_IDE64_NAME,    N_("Specify name of IDE64 image file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_IDE64_NAME_DA, "Angiv navn på IDE64-cartridge image"},
/* de */ {IDCLS_SPECIFY_IDE64_NAME_DE, "Namen für IDE64 Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_IDE64_NAME_FR, "Spécifier le nom de l'image IDE64"},
/* hu */ {IDCLS_SPECIFY_IDE64_NAME_HU, "Adja meg az IDE64 képmás fájlnevét"},
/* it */ {IDCLS_SPECIFY_IDE64_NAME_IT, "Specifica il nome del file immagine dell'IDE64"},
/* ko */ {IDCLS_SPECIFY_IDE64_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_IDE64_NAME_NL, "Geef de naam van het IDE64 bestand"},
/* ru */ {IDCLS_SPECIFY_IDE64_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_IDE64_NAME_SV, "Ange namn på IDE64-insticksmodulfil"},
/* tr */ {IDCLS_SPECIFY_IDE64_NAME_TR, "IDE64 imaj dosyasýnýn ismini belirt"},
#endif

/* c64/cart/ide64.c, gfxoutputdrv/ffmpegdrv.c, datasette.c,
   debug.c, mouse.c, ram.c, sound.c, vsync.c */
/* en */ {IDCLS_P_VALUE,    N_("<value>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_VALUE_DA, "<værdi>"},
/* de */ {IDCLS_P_VALUE_DE, "<Wert>"},
/* fr */ {IDCLS_P_VALUE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_VALUE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_VALUE_IT, "<valore>"},
/* ko */ {IDCLS_P_VALUE_KO, "<°¡Ä¡>"},
/* nl */ {IDCLS_P_VALUE_NL, "<waarde>"},
/* ru */ {IDCLS_P_VALUE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_VALUE_SV, "<värde>"},
/* tr */ {IDCLS_P_VALUE_TR, "<deðer>"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64,    N_("Set number of cylinders for the IDE64 emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_DA, "Vælg antal cylindrer for IDE64-emuleringen"},
/* de */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_DE, "Anzahl der Zylinder für IDE64 Emulation"},
/* fr */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_FR, "Régler le nombre de cylindres pour l'émulation IDE64"},
/* hu */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_HU, "Adja meg a sávok számát IDE64 emulációhoz"},
/* it */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_IT, "Imposta il numero di cilindri dell'emulazione IDE64"},
/* ko */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_NL, "Stel het aantal cylinders voor de IDE64 emulatie in"},
/* ru */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_SV, "Välj antal cylindrar för IDE64-emuleringen"},
/* tr */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_TR, "IDE64 emülasyonu için silindir adedini girin"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_SET_AMOUNT_HEADS_IDE64,    N_("Set number of heads for the IDE64 emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_AMOUNT_HEADS_IDE64_DA, "Vælg antal hoveder for IDE64-emuleringen"},
/* de */ {IDCLS_SET_AMOUNT_HEADS_IDE64_DE, "Anzahl der Laufwerksköpfe für IDE64 Emulation"},
/* fr */ {IDCLS_SET_AMOUNT_HEADS_IDE64_FR, "Régler le nombre de têtes pour l'émulation IDE64"},
/* hu */ {IDCLS_SET_AMOUNT_HEADS_IDE64_HU, "Adja meg a fejek számát IDE64 emulációhoz"},
/* it */ {IDCLS_SET_AMOUNT_HEADS_IDE64_IT, "Imposta il numero di testine dell'emulazione IDE64"},
/* ko */ {IDCLS_SET_AMOUNT_HEADS_IDE64_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_AMOUNT_HEADS_IDE64_NL, "Stel het aantal koppen voor de IDE64 emulatie in"},
/* ru */ {IDCLS_SET_AMOUNT_HEADS_IDE64_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_AMOUNT_HEADS_IDE64_SV, "Ange antal huvuden för IDE64-emuleringen"},
/* tr */ {IDCLS_SET_AMOUNT_HEADS_IDE64_TR, "IDE64 emülasyonu için kafa adedini girin"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_SET_AMOUNT_SECTORS_IDE64,    N_("Set number of sectors for the IDE64 emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_DA, "Vælg antal sektorer for IDE64-emuleringen"},
/* de */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_DE, "Anzahl der Sektoren für IDE64 Emulation"},
/* fr */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_FR, "Régler le nombre de secteurs pour l'émulation IDE64"},
/* hu */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_HU, "Adja meg a szektorok számát IDE64 emulációhoz"},
/* it */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_IT, "Imposta il numero di settori dell'emulazione IDE64"},
/* ko */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_NL, "Stel het aantal sectors voor de IDE64 emulatie in"},
/* ru */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_SV, "Ange antal sektorer för IDE64-emuleringen"},
/* tr */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_TR, "IDE64 emülasyonu için sektör adedini girin"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_AUTODETECT_IDE64_GEOMETRY,    N_("Autodetect image size")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_DA, "Autodetektér størrelse på image"},
/* de */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_DE, "Image Größe automatisch erkennen"},
/* fr */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_HU, ""},  /* fuzzy */
/* it */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_IT, "Rileva automaticamente immagine"},
/* ko */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_KO, "ÀÌ¹ÌÁö Å©±â ÀÚµ¿À¸·Î Ã£±â"},
/* nl */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_NL, "Automatisch detecteren bestandsgrootte"},
/* ru */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_SV, "Autodetektera storlek på avbildning"},
/* tr */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_TR, "Imaj boyutunu otomatik algýla"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY,    N_("Do not autodetect geometry of formatted images")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_DA, "Autodetektér ikke geometri fra formatterede images"},
/* de */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_DE, "Geometrie von formatierten Image Dateien nicht automatisch erkennen"},
/* fr */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_FR, "Ne pas détecter automatiquement la géométrie des images formattées"},
/* hu */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_HU, "Formázott képmások geometriáját ne ismerje fel automatikusan"},
/* it */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_IT, "Non rilevare automaticamente la geometrica delle immagini formattate"},
/* ko */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_NL, "Niet automatisch de grootte van de geformateerde bestanden detecteren"},
/* ru */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_SV, "Autodetektera inte geometri från formaterad avbildningsfil"},
/* tr */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_TR, "Formatlanmýþ imajlarýn yapýlarýný otomatik algýlama"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_IDE64_V4,    N_("Emulate version 4 hardware")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_IDE64_V4_DA, "Emulér version 4 hardware"},
/* de */ {IDCLS_IDE64_V4_DE, "Emulation der Version 5 Hardware"},
/* fr */ {IDCLS_IDE64_V4_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_IDE64_V4_HU, ""},  /* fuzzy */
/* it */ {IDCLS_IDE64_V4_IT, "Emula hardware versione 4"},
/* ko */ {IDCLS_IDE64_V4_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_IDE64_V4_NL, "Emuleer versie 4 hardware"},
/* ru */ {IDCLS_IDE64_V4_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_IDE64_V4_SV, "Emulera version 4-maskinvara"},
/* tr */ {IDCLS_IDE64_V4_TR, "Versiyon 4 donanýmýný emüle et"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_IDE64_PRE_V4,    N_("Emulate pre version 4 hardware")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_IDE64_PRE_V4_DA, "Emulér hardware før version 4"},
/* de */ {IDCLS_IDE64_PRE_V4_DE, "Emulation der pre-Version 4 Hardware"},
/* fr */ {IDCLS_IDE64_PRE_V4_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_IDE64_PRE_V4_HU, ""},  /* fuzzy */
/* it */ {IDCLS_IDE64_PRE_V4_IT, "Emula hardware pre-versione 4"},
/* ko */ {IDCLS_IDE64_PRE_V4_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_IDE64_PRE_V4_NL, "Emuleer hardware van voor versie 4"},
/* ru */ {IDCLS_IDE64_PRE_V4_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_IDE64_PRE_V4_SV, "Emulera för-version 4-maskinvara"},
/* tr */ {IDCLS_IDE64_PRE_V4_TR, "Ön versiyon 4 donanýmýný emüle et"},
#endif

/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_P_MODELNUMBER,    N_("<modelnumber>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_MODELNUMBER_DA, "<modelnummer>"},
/* de */ {IDCLS_P_MODELNUMBER_DE, "<Modell Nummer>"},
/* fr */ {IDCLS_P_MODELNUMBER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_MODELNUMBER_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_MODELNUMBER_IT, "<numero di modello>"},
/* ko */ {IDCLS_P_MODELNUMBER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_MODELNUMBER_NL, "<modelnummer>"},
/* ru */ {IDCLS_P_MODELNUMBER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_MODELNUMBER_SV, "<modellnummer>"},
/* tr */ {IDCLS_P_MODELNUMBER_TR, "<modelnumarasý>"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CBM2_MODEL,    N_("Specify CBM-II model to emulate")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CBM2_MODEL_DA, "Angiv emuleret CBM-II-model"},
/* de */ {IDCLS_SPECIFY_CBM2_MODEL_DE, "CBM-II Modell für Emulation definieren"},
/* fr */ {IDCLS_SPECIFY_CBM2_MODEL_FR, "Spécifier le modèle CBM-II à émuler"},
/* hu */ {IDCLS_SPECIFY_CBM2_MODEL_HU, "Adja meg az emulálandó CBM-II modell számát"},
/* it */ {IDCLS_SPECIFY_CBM2_MODEL_IT, "Specifica il modello di CBM II da emulare"},
/* ko */ {IDCLS_SPECIFY_CBM2_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CBM2_MODEL_NL, "Geef CBM-II model om te emuleren"},
/* ru */ {IDCLS_SPECIFY_CBM2_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CBM2_MODEL_SV, "Ange CBM-II-modell att emulera"},
/* tr */ {IDCLS_SPECIFY_CBM2_MODEL_TR, "Emüle edilecek CBM-II modelini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_TO_USE_VIC_II,    N_("Specify to use VIC-II")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_TO_USE_VIC_II_DA, "Brug VIC-II"},
/* de */ {IDCLS_SPECIFY_TO_USE_VIC_II_DE, "VIC-II Unterstützung aktivieren"},
/* fr */ {IDCLS_SPECIFY_TO_USE_VIC_II_FR, "Spécifier l'utilisation de VIC-II"},
/* hu */ {IDCLS_SPECIFY_TO_USE_VIC_II_HU, "VIC-II használata"},
/* it */ {IDCLS_SPECIFY_TO_USE_VIC_II_IT, "Specifica di utilizzare il VIC-II"},
/* ko */ {IDCLS_SPECIFY_TO_USE_VIC_II_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_TO_USE_VIC_II_NL, "Gebruik de VIC-II"},
/* ru */ {IDCLS_SPECIFY_TO_USE_VIC_II_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_TO_USE_VIC_II_SV, "Ange för att använda VIC-II"},
/* tr */ {IDCLS_SPECIFY_TO_USE_VIC_II_TR, "VIC-II kullanýmý için seçin"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_TO_USE_CRTC,    N_("Specify to use CRTC")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_TO_USE_CRTC_DA, "Brug CRTC"},
/* de */ {IDCLS_SPECIFY_TO_USE_CRTC_DE, "CRTC Unterstützung aktivieren"},
/* fr */ {IDCLS_SPECIFY_TO_USE_CRTC_FR, "Spécifier l'utilisation de CRTC"},
/* hu */ {IDCLS_SPECIFY_TO_USE_CRTC_HU, "CRTC használata"},
/* it */ {IDCLS_SPECIFY_TO_USE_CRTC_IT, "Specifica di utilizzare il CRTC"},
/* ko */ {IDCLS_SPECIFY_TO_USE_CRTC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_TO_USE_CRTC_NL, "Gebruik de CRTC"},
/* ru */ {IDCLS_SPECIFY_TO_USE_CRTC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_TO_USE_CRTC_SV, "Ange för att använda CRTC"},
/* tr */ {IDCLS_SPECIFY_TO_USE_CRTC_TR, "CRTC kullanýmý için seçin"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_P_LINENUMBER,    N_("<linenumber>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_LINENUMBER_DA, "<linjenummer>"},
/* de */ {IDCLS_P_LINENUMBER_DE, "<Zeilennummer>"},
/* fr */ {IDCLS_P_LINENUMBER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_LINENUMBER_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_LINENUMBER_IT, "<numero di linea>"},
/* ko */ {IDCLS_P_LINENUMBER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_LINENUMBER_NL, "<lijnnummer>"},
/* ru */ {IDCLS_P_LINENUMBER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_LINENUMBER_SV, "<linjenummer>"},
/* tr */ {IDCLS_P_LINENUMBER_TR, "<satýrnumarasý>"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE,    N_("Specify CBM-II model hardware (0=6x0, 1=7x0)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_DA, "Angiv hardware for CBM-II-model (0=6x0, 1=7x0)"},
/* de */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_DE, "CBM-II Hardware Modell definieren (0=6x0, 1=7x0)"},
/* fr */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_FR, "Spécifier le modèle hardware CBM-II (0=6x0, 1=7x0)"},
/* hu */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_HU, "Adja meg a CBM-II hardver modellt (0=6x0, 1=7x0)"},
/* it */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_IT, "Specifica il modello hardware del CBM-II (0=6x0, 1=7x0)"},
/* ko */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_NL, "Geef CBM-II hardwaremodel (0=6x0, 1=7x0)"},
/* ru */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_SV, "Ange maskinvara för CBM-II-modell (0=6x0, 1=7x0)"},
/* tr */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_TR, "CBM-II modeli donanýmýný belirt (0=6x0, 1=7x0)"},
#endif

/* cbm2/cbm2-cmdline-options.c, plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_P_RAMSIZE,    N_("<RAM size>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_RAMSIZE_DA, ""},  /* fuzzy */
/* de */ {IDCLS_P_RAMSIZE_DE, "<RAM Größe>"},
/* fr */ {IDCLS_P_RAMSIZE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_RAMSIZE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_RAMSIZE_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_P_RAMSIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_RAMSIZE_NL, "<RAM grootte>"},
/* ru */ {IDCLS_P_RAMSIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_RAMSIZE_SV, "<RAM-storlek>"},
/* tr */ {IDCLS_P_RAMSIZE_TR, ""},  /* fuzzy */
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_SIZE_OF_RAM,    N_("Specify size of RAM (64/128/256/512/1024 kByte)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SIZE_OF_RAM_DA, "Angiv størrelse på RAM (64/128/256/512/1024 kByte)"},
/* de */ {IDCLS_SPECIFY_SIZE_OF_RAM_DE, "RAM Größe definieren (64/128/256/512/1024 kByte)"},
/* fr */ {IDCLS_SPECIFY_SIZE_OF_RAM_FR, "Spécifier la taille de la RAM (64/128/256/512/1024 KO)"},
/* hu */ {IDCLS_SPECIFY_SIZE_OF_RAM_HU, "Adja meg a RAM méretét (64/128/256/512/1024 kBájt)"},
/* it */ {IDCLS_SPECIFY_SIZE_OF_RAM_IT, "Specifica la dimensione della RAM (4/128/256/512/1024 kByte)"},
/* ko */ {IDCLS_SPECIFY_SIZE_OF_RAM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SIZE_OF_RAM_NL, "Geef geheugengrootte (64/128/256/512/1024 kByte)"},
/* ru */ {IDCLS_SPECIFY_SIZE_OF_RAM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SIZE_OF_RAM_SV, "Ange storlek på RAM (64/128/256/512/1024 kByte)"},
/* tr */ {IDCLS_SPECIFY_SIZE_OF_RAM_TR, "RAM boyutunu belirt (64/128/256/512/1024 kByte)"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_ROM_1000_NAME,    N_("Specify name of cartridge ROM image for $1000")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_DA, "Angiv navn på cartridge-ROM-image for $1000"},
/* de */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_DE, "Name für ROM Module Image Datei ($1000)"},
/* fr */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_FR, "Spécifier le nom de l’image de cartouche ROM pour $1000"},
/* hu */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_HU, "Adja meg a $1000 címû cartridge ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_IT, "Specifica il nome immagine della cartuccia ROM a $1000"},
/* ko */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_NL, "Geef de naam van het cartridge ROM bestand voor $1000"},
/* ru */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_SV, "Ange namn på insticksmodul-ROM-avbildning för $1000"},
/* tr */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_TR, "$1000 adresi için kartuþ ROM imaj ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_ROM_2000_NAME,    N_("Specify name of cartridge ROM image for $2000-$3fff")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_DA, "Angiv navn på cartridge-ROM-image for $2000-3fff"},
/* de */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_DE, "Name für ROM Module Image Datei ($2000-3fff)"},
/* fr */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_FR, "Spécifier le nom de l’image de cartouche ROM pour $2000-$3fff"},
/* hu */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_HU, "Adja meg a $2000-$3fff címû cartridge ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_IT, "Specifica il nome immagine della ROM della cartuccia per $2000-$3fff"},
/* ko */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_NL, "Geef de naam van het cartridge ROM bestand voor $2000-$3fff"},
/* ru */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_SV, "Ange namn på insticksmodul-ROM-avbildning för $2000-3fff"},
/* tr */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_TR, "$2000-$3fff adres aralýðý için kartuþ ROM imaj ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_ROM_4000_NAME,    N_("Specify name of cartridge ROM image for $4000-$5fff")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_DA, "Angiv navn på cartridge-ROM-image for $4000-$5fff"},
/* de */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_DE, "Name für ROM Module Image Datei ($4000-5fff)"},
/* fr */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_FR, "Spécifier le nom de l’image de cartouche ROM pour $4000-$5fff"},
/* hu */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_HU, "Adja meg a $4000-$5fff címû cartridge ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_IT, "Specifica il nome immagine della ROM della cartuccia per $4000-$5fff"},
/* ko */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_NL, "Geef de naam van het cartridge ROM bestand voor $4000-$5fff"},
/* ru */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_SV, "Ange namn på insticksmodul-ROM-avbildning för $4000-$5fff"},
/* tr */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_TR, "$4000-$5fff adres aralýðý için kartuþ ROM imaj ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_ROM_6000_NAME,    N_("Specify name of cartridge ROM image for $6000-$7fff")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_DA, "Angiv navn på cartridge-ROM-image for $6000-$7fff"},
/* de */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_DE, "Name für ROM Module Image Datei ($6000-7fff)"},
/* fr */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_FR, "Spécifier le nom de l’image de cartouche ROM pour $6000-$7fff"},
/* hu */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_HU, "Adja meg a $6000-$7fff címû cartridge ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_IT, "Specifica il nome immagine della ROM della cartuccia per $6000-$7fff"},
/* ko */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_NL, "Geef de naam van het cartridge ROM bestand voor $6000-$7fff"},
/* ru */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_SV, "Ange namn på insticksmodul-ROM-avbildning för $6000-$7fff"},
/* tr */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_TR, "$6000-$7fff adres aralýðý için kartuþ ROM imaj ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800,    N_("Enable RAM mapping in $0800-$0FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_DA, "Aktivér RAM-mappning på $0800-$0FFF"},
/* de */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_DE, "RAM Zuordnung in $0800-$0FFF aktivieren"},
/* fr */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_FR, "Activer le mappage RAM dans $0800-$0FFF"},
/* hu */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_HU, "$0800-$0FFF RAM leképzés engedélyezése"},
/* it */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_IT, "Attiva mappatura della RAM a $0800-$0FFF"},
/* ko */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_NL, "Activeer RAM op adres $0800-$0FFF"},
/* ru */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_SV, "Aktivera RAM-mappning på $0800-$0FFF"},
/* tr */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_TR, "$0800-$0FFF aralýðýnda RAM eþleþtirmeyi aktif et"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800,    N_("Disable RAM mapping in $0800-$0FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_DA, "Deaktivér RAM-mappning på $0800-$0FFF"},
/* de */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_DE, "RAM Zuordnung in $0800-$0FFF deaktivieren"},
/* fr */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_FR, "Désactiver le mappage RAM dans $0800-$0FFF"},
/* hu */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_HU, "$0800-$0FFF RAM leképzés tiltása"},
/* it */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_IT, "Disattiva mappatura della RAM a $0800-$0FFF"},
/* ko */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_NL, "RAM op adres $0800-$0FFF uitschakelen"},
/* ru */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_SV, "Inaktivera RAM-mappning på $0800-$0FFF"},
/* tr */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_TR, "$0800-$0FFF aralýðýnda RAM eþleþtirmeyi pasifleþtir"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000,    N_("Enable RAM mapping in $1000-$1FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_DA, "Aktivér RAM-mappning på $1000-$1FFF"},
/* de */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_DE, "RAM Zuordnung in $1000-$1FFF aktivieren"},
/* fr */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_FR, "Activer le mappage RAM dans $1000-$1FFF"},
/* hu */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_HU, "$1000-$1FFF RAM leképzés engedélyezése"},
/* it */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_IT, "Attiva mappatura della RAM a $1000-$1FFF"},
/* ko */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_NL, "Activeer RAM op adres $1000-$1FFF"},
/* ru */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_SV, "Aktivera RAM-mappning på $1000-$1FFF"},
/* tr */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_TR, "$1000-$1FFF aralýðýnda RAM eþleþtirmeyi aktif et"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000,    N_("Disable RAM mapping in $1000-$1FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_DA, "Deaktivér RAM-mappning på $1000-$1FFF"},
/* de */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_DE, "RAM Zuordnung in $1000-$1FFF deaktivieren"},
/* fr */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_FR, "Désactiver le mappage RAM dans $1000-$1FFF"},
/* hu */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_HU, "$1000-$1FFF RAM leképzés tiltása"},
/* it */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_IT, "Disattiva mappatura della RAM a $1000-$1FFF"},
/* ko */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_NL, "RAM op adres $1000-$1FFF uitschakelen"},
/* ru */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_SV, "Inaktivera RAM-mappning på $1000-$1FFF"},
/* tr */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_TR, "$1000-$1FFF aralýðýnda RAM eþleþtirmeyi pasifleþtir"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000,    N_("Enable RAM mapping in $2000-$3FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_DA, "Aktivér RAM-mappning på $2000-$3FFF"},
/* de */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_DE, "RAM Zuordnung in $2000-3FFF aktivieren"},
/* fr */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_FR, "Activer le mappage RAM dans $2000-$3FFF"},
/* hu */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_HU, "$2000-$3FFF RAM leképzés engedélyezése"},
/* it */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_IT, "Attiva mappatura della RAM a $2000-$3FFF"},
/* ko */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_NL, "Activeer RAM op adres $2000-$3FFF"},
/* ru */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_SV, "Aktivera RAM-mappning på $2000-$3FFF"},
/* tr */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_TR, "$2000-$3FFF aralýðýnda RAM eþleþtirmeyi aktif et"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000,    N_("Disable RAM mapping in $2000-$3FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_DA, "Deaktivér RAM-mappning på $2000-$3FFF"},
/* de */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_DE, "RAM Zuordnung in $2000-$3FFF deaktivieren"},
/* fr */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_FR, "Désactiver le mappage RAM dans $2000-$3FFF"},
/* hu */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_HU, "$2000-$3FFF RAM leképzés tiltása"},
/* it */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_IT, "Disattiva mappatura della RAM a $2000-$3FFF"},
/* ko */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_NL, "RAM op adres $2000-$3FFF uitschakelen"},
/* ru */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_SV, "Inaktivera RAM-mappning på $2000-$3FFF"},
/* tr */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_TR, "$2000-$3FFF aralýðýnda RAM eþleþtirmeyi pasifleþtir"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000,    N_("Enable RAM mapping in $4000-$5FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_DA, "Aktivér RAM-mappning på $4000-$5FFF"},
/* de */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_DE, "RAM Zuordnung in $4000-$5FFF aktivieren"},
/* fr */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_FR, "Activer le mappage RAM dans $4000-$5FFF"},
/* hu */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_HU, "$4000-$5FFF RAM leképzés engedélyezése"},
/* it */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_IT, "Attiva mappatura della RAM a $4000-$5FFF"},
/* ko */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_NL, "Activeer RAM op adres $4000-$5FFF"},
/* ru */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_SV, "Aktivera RAM-mappning på $4000-$5FFF"},
/* tr */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_TR, "$4000-$5FFF aralýðýnda RAM eþleþtirmeyi aktif et"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000,    N_("Disable RAM mapping in $4000-$5FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_DA, "Deaktivér RAM-mappning på $4000-$5FFF"},
/* de */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_DE, "RAM Zuordnung in $4000-$5FFF deaktivieren"},
/* fr */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_FR, "Désactiver le mappage RAM dans $4000-$5FFF"},
/* hu */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_HU, "$4000-$5FFF RAM leképzés tiltása"},
/* it */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_IT, "Disattiva mappatura della RAM a $4000-$5FFF"},
/* ko */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_NL, "RAM op adres $4000-$5FFF uitchakelen"},
/* ru */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_SV, "Inaktivera RAM-mappning på $4000-$5FFF"},
/* tr */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_TR, "$4000-$5FFF aralýðýnda RAM eþleþtirmeyi pasifleþtir"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000,    N_("Enable RAM mapping in $6000-$7FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_DA, "Aktivér RAM-mappning på $6000-$7FFF"},
/* de */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_DE, "RAM Zuordnung in $6000-$7FFF aktivieren"},
/* fr */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_FR, "Activer le mappage RAM dans $6000-$7FFF"},
/* hu */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_HU, "$6000-$7FFF RAM leképzés engedélyezése"},
/* it */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_IT, "Attiva mappatura della RAM a $6000-$7FFF"},
/* ko */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_NL, "Activeer RAM op adres $6000-$7FFF"},
/* ru */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_SV, "Aktivera RAM-mappning på $6000-$7FFF"},
/* tr */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_TR, "$6000-$7FFF aralýðýnda RAM eþleþtirmeyi aktif et"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000,    N_("Disable RAM mapping in $6000-$7FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_DA, "Deaktivér RAM-mappning på $6000-$7FFF"},
/* de */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_DE, "RAM Zuordnung in $6000-$7FFF deaktivieren"},
/* fr */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_FR, "Désactiver le mappage RAM dans $6000-$7FFF"},
/* hu */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_HU, "$6000-$7FFF RAM leképzés tiltása"},
/* it */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_IT, "Disattiva mappatura della RAM a $6000-$7FFF"},
/* ko */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_NL, "RAM op adres $6000-$7FFF uitschakelen"},
/* ru */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_SV, "Inaktivera RAM-mappning på $6000-$7FFF"},
/* tr */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_TR, "$6000-$7FFF aralýðýnda RAM eþleþtirmeyi pasifleþtir"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000,    N_("Enable RAM mapping in $C000-$CFFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_DA, "Aktivér RAM-mappning på $C000-$CFFF"},
/* de */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_DE, "RAM Zuordnung in $C000-$CFFF aktivieren"},
/* fr */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_FR, "Activer le mappage RAM dans $C000-$CFFF"},
/* hu */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_HU, "$C000-$CFFF RAM leképzés engedélyezése"},
/* it */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_IT, "Attiva mappatura della RAM a $C000-$CFFF"},
/* ko */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_NL, "Activeer RAM op adres $C000-$CFFF"},
/* ru */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_SV, "Aktivera RAM-mappning på $C000-$CFFF"},
/* tr */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_TR, "$C000-$CFFF aralýðýnda RAM eþleþtirmeyi aktif et"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000,    N_("Disable RAM mapping in $C000-$CFFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_DA, "Deaktivér RAM-mappning på $C000-$CFFF"},
/* de */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_DE, "RAM Zuordnung in $C000-$CFFF deaktivieren"},
/* fr */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_FR, "Désactiver le mappage RAM dans $C000-$CFFF"},
/* hu */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_HU, "$C000-$CFFF RAM leképzés tiltása"},
/* it */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_IT, "Disattiva mappatura della RAM a $C000-$CFFF"},
/* ko */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_NL, "RAM op adres $C000-$CFFF uitschakelen"},
/* ru */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_SV, "Inaktivera RAM-mappning på $C000-$CFFF"},
/* tr */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_TR, "$C000-$CFFF aralýðýnda RAM eþleþtirmeyi pasifleþtir"},
#endif

#ifdef COMMON_KBD
/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_KEYMAP_INDEX,    N_("Specify index of keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_KEYMAP_INDEX_DA, "Angiv indeks for tastaturindstillingsfil"},
/* de */ {IDCLS_SPECIFY_KEYMAP_INDEX_DE, "Index der Keymap Datei definieren"},
/* fr */ {IDCLS_SPECIFY_KEYMAP_INDEX_FR, "Spécifier l'index du fichier de mappage clavier"},
/* hu */ {IDCLS_SPECIFY_KEYMAP_INDEX_HU, "Adja meg a billentyûzet leképzés fájl típusát"},
/* it */ {IDCLS_SPECIFY_KEYMAP_INDEX_IT, "Specifica l'indice del file della mappa della tastiera"},
/* ko */ {IDCLS_SPECIFY_KEYMAP_INDEX_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_KEYMAP_INDEX_NL, "Geef de index van het keymapbestand"},
/* ru */ {IDCLS_SPECIFY_KEYMAP_INDEX_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_KEYMAP_INDEX_SV, "Ange index o tangentbordsfil"},
/* tr */ {IDCLS_SPECIFY_KEYMAP_INDEX_TR, "Tuþ haritasý dosyasýnýn indeksini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME,    N_("Specify name of graphics keyboard symbolic keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_DA, "Angiv fil for symbolsk tastaturemulering for \"graphics\"-tastatur"},
/* de */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_DE, "Keymap Datei für graphics keyboard symbolic definieren"},
/* fr */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_FR, "Spécifier le nom du fichier de mappage clavier symbolique"},
/* hu */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_HU, "Adja meg a grafikus és szimbolikus billentyûzet leképzési fájl nevét."},
/* it */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_IT, "Specifica il nome del file della mappa simbolica della tastiera grafica"},
/* ko */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_NL, "Geef de naam van het symbolisch keymapbestand voor het grafische toetsenbord"},
/* ru */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_SV, "Ange fil för symbolisk tangentbordsemulering för \"graphics\"-tangentbord"},
/* tr */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_TR, "Grafik klavyesi sembolik tuþ haritasý dosyasýnýn ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME,    N_("Specify name of graphics keyboard positional keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_DA, "Angiv fil for positionsbestemt tastaturemulering for \"graphics\"-tastatur"},
/* de */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_DE, "Keymap Datei für graphics keyboard positional definieren"},
/* fr */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_FR, "Spécifier le nom du fichier de mappage clavier positionnel"},
/* hu */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_HU, "Adja meg a grafikus és pozíció szerinti billentyûzet leképzési fájl nevét."},
/* it */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_IT, "Specifica il nome del file della mappa posizionale della tastiera grafica"},
/* ko */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_NL, "Geef de naam van het positioneel keymapbestand voor het grafische toetsenbord"},
/* ru */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_SV, "Ange fil för positionsriktig tangentbordsemulering för \"graphics\"-tangentbord"},
/* tr */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_TR, "Grafik klavyesi konumsal tuþ haritasý dosyasýnýn ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME,    N_("Specify name of UK business keyboard symbolic keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_DA, "Angiv fil for symbolsk tastaturemulering for Britisk \"business\"-tastatur"},
/* de */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_DE, "Keymap Datei für UK business keyboard symbolic definieren"},
/* fr */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_FR, "Spécifier le nom du fichier de mappage clavier symbolique UK"},
/* hu */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_HU, "Adja meg az angol, hivatalos, szimbolikus billentyûzet leképzési fájl nevét."},
/* it */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_IT, "Specifica il nome del file della mappa simbolica della tastiera UK business"},
/* ko */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_NL, "Geef de naam van het symbolisch keymapbestand voor het UK zakelijk toetsenbord"},
/* ru */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_SV, "Ange fil för symbolisk tangentbordsemulering för brittiskt \"business\"-tangentbord"},
/* tr */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_TR, "UK business klavyesi sembolik tuþ haritasý dosyasýnýn ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME,    N_("Specify name of UK business keyboard positional keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_DA, "Angiv fil for positionsbestemt tastaturemulering for Britisk \"business\"-tastatur"},
/* de */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_DE, "Keymap Datei für UK business keyboard positional definieren"},
/* fr */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_FR, "Spécifier le nom du fichier de mappage clavier positionnel UK"},
/* hu */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_HU, "Adja meg az angol, hivatalos, pozíció szerinti billentyûzet leképzési fájl nevét."},
/* it */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_IT, "Specifica il nome del file della mappa posizionale della tastiera UK business"},
/* ko */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_NL, "Geef de naam van het positioneel keymapbestand voor het UK zakelijk toetsenbord"},
/* ru */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_SV, "Ange fil för positionsriktig tangentbordsemulering för brittiskt \"business\"-tangentbord"},
/* tr */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_TR, "UK business klavyesi konumsal tuþ haritasý dosyasýnýn ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME,    N_("Specify name of German business keyboard symbolic keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_DA, "Angiv fil for symbolsk tastaturemulering for Tysk \"business\"-tastatur"},
/* de */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_DE, "Keymap Datei für German business keyboard symbolic definieren"},
/* fr */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_FR, "Spécifier le nom du fichier de mappage clavier symbolique allemand"},
/* hu */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_HU, "Adja meg a német, hivatalos, szimbolikus billentyûzet leképzési fájl nevét."},
/* it */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_IT, "Specifica il nome del file della mappa simbolica della tastiera business tedesca"},
/* ko */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_NL, "Geef de naam van het symbolisch keymapbestand voor het Duitse zakelijk toetsenbord"},
/* ru */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_SV, "Ange fil för symbolisk tangentbordsemulering för tyskt \"business\"-tangentbord"},
/* tr */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_TR, "Alman business klavyesi sembolik tuþ haritasý dosyasýnýn ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME,    N_("Specify name of German business keyboard positional keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_DA, "Angiv fil for positionsbestemt tastaturemulering for Tysk \"business\"-tastatur"},
/* de */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_DE, "Keymap Datei für German business keyboard positional definieren"},
/* fr */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_FR, "Spécifier le nom du fichier de mappage clavier positionnel allemand"},
/* hu */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_HU, "Adja meg a német, hivatalos, pozíció szerinti billentyûzet leképzési fájl nevét."},
/* it */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_IT, "Specifica il nome del file della mappa posizionale della tastiera business tedesca"},
/* ko */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_NL, "Geef de naam van het positioneel keymapbestand voor het Duitse zakelijk toetsenbord"},
/* ru */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_SV, "Ange fil för positionsriktig tangentbordsemulering för tyskt \"business\"-tangentbord"},
/* tr */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_TR, "Alman business klavyesi konumsal tuþ haritasý dosyasýnýn ismini belirt"},
#endif
#endif

/* drive/drive-cmdline-options.c */
/* en */ {IDCLS_ENABLE_TRUE_DRIVE,    N_("Enable hardware-level emulation of disk drives")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_TRUE_DRIVE_DA, "Aktivér emulering af diskettedrev på hardware-niveau"},
/* de */ {IDCLS_ENABLE_TRUE_DRIVE_DE, "Hardware Emulation für Disklaufwerke aktivieren"},
/* fr */ {IDCLS_ENABLE_TRUE_DRIVE_FR, "Activer l'émulation de disques au niveau physique"},
/* hu */ {IDCLS_ENABLE_TRUE_DRIVE_HU, "Lemezegységek hardver szintû emulációjának engedélyezése"},
/* it */ {IDCLS_ENABLE_TRUE_DRIVE_IT, "Attiva emulazione hardware dei disk drive"},
/* ko */ {IDCLS_ENABLE_TRUE_DRIVE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_TRUE_DRIVE_NL, "Activeer hardwarematige emulatie van diskdrives"},
/* ru */ {IDCLS_ENABLE_TRUE_DRIVE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_TRUE_DRIVE_SV, "Aktivera emulering av diskettstationer på maskinvarunivå"},
/* tr */ {IDCLS_ENABLE_TRUE_DRIVE_TR, "Disk sürücülerinin donaným seviyesinde emülasyonunu aktif et"},
#endif

/* drive/drive-cmdline-options.c */
/* en */ {IDCLS_DISABLE_TRUE_DRIVE,    N_("Disable hardware-level emulation of disk drives")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_TRUE_DRIVE_DA, "Deaktivér emulering af diskettedrev på hardware-niveau"},
/* de */ {IDCLS_DISABLE_TRUE_DRIVE_DE, "Hardware Emulation für Disklaufwerke deaktivieren"},
/* fr */ {IDCLS_DISABLE_TRUE_DRIVE_FR, "Désactiver l'émulation de disques au niveau physique"},
/* hu */ {IDCLS_DISABLE_TRUE_DRIVE_HU, "Lemezegységek hardver szintû emulációjának tiltása"},
/* it */ {IDCLS_DISABLE_TRUE_DRIVE_IT, "Disattiva emulazione hardware dei disk drive"},
/* ko */ {IDCLS_DISABLE_TRUE_DRIVE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_TRUE_DRIVE_NL, "Hardwarematige emulatie van diskdrives uitschakelen"},
/* ru */ {IDCLS_DISABLE_TRUE_DRIVE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_TRUE_DRIVE_SV, "Inaktivera emulering av diskettstationer på maskinvarunivå"},
/* tr */ {IDCLS_DISABLE_TRUE_DRIVE_TR, "Disk sürücülerinin donaným seviyesinde emülasyonunu pasifleþtir"},
#endif

/* drive/drive-cmdline-options.c, printerdrv/interface-serial.c,
   attach.c, drive/iec/iec-cmdline-options.c, c64/c64gluelogic.c */
/* en */ {IDCLS_P_TYPE,    N_("<Type>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_TYPE_DA, "<Type>"},
/* de */ {IDCLS_P_TYPE_DE, "<Typ>"},
/* fr */ {IDCLS_P_TYPE_FR, "<type>"},
/* hu */ {IDCLS_P_TYPE_HU, "<Típus>"},
/* it */ {IDCLS_P_TYPE_IT, "<Tipo>"},
/* ko */ {IDCLS_P_TYPE_KO, "<Á¾·ù>"},
/* nl */ {IDCLS_P_TYPE_NL, "<Soort>"},
/* ru */ {IDCLS_P_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_TYPE_SV, "<Typ>"},
/* tr */ {IDCLS_P_TYPE_TR, "<Tip>"},
#endif

/* drive/drive-cmdline-options.c */
/* en */ {IDCLS_SET_DRIVE_TYPE,    N_("Set drive type (0: no drive)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DRIVE_TYPE_DA, "Angiv enhedstype (0: ingen enhed)"},
/* de */ {IDCLS_SET_DRIVE_TYPE_DE, "Setze Laufwerkstyp (0: kein Laufwerk)"},
/* fr */ {IDCLS_SET_DRIVE_TYPE_FR, "Spécifier le type de lecteur de disque (0: pas de lecteur)"},
/* hu */ {IDCLS_SET_DRIVE_TYPE_HU, "Adja meg a lemezegység típusát (0: nincs)"},
/* it */ {IDCLS_SET_DRIVE_TYPE_IT, "Imposta tipo drive (0: nessun drive)"},
/* ko */ {IDCLS_SET_DRIVE_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DRIVE_TYPE_NL, "Zet drive soort (0: geen drive)"},
/* ru */ {IDCLS_SET_DRIVE_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DRIVE_TYPE_SV, "Ange enhetstyp (0: ingen enhet)"},
/* tr */ {IDCLS_SET_DRIVE_TYPE_TR, "Sürücü tipini ayarlayýn (0: sürücü yok)"},
#endif

/* drive/drive-cmdline-options.c,
   drive/iec/iec-cmdline-options.c,
   gfxoutputdrv/doodledrv.c */
/* en */ {IDCLS_P_METHOD,    N_("<method>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_METHOD_DA, "<metode>"},
/* de */ {IDCLS_P_METHOD_DE, "<Methode>"},
/* fr */ {IDCLS_P_METHOD_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_METHOD_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_METHOD_IT, "<metodo>"},
/* ko */ {IDCLS_P_METHOD_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_METHOD_NL, "<methode>"},
/* ru */ {IDCLS_P_METHOD_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_METHOD_SV, "<metod>"},
/* tr */ {IDCLS_P_METHOD_TR, "<metod>"},
#endif

/* gfxoutputdrv/doodledrv.c */
/* en */ {IDCLS_P_COLOR,    N_("<color>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_COLOR_DA, "<farve>"},
/* de */ {IDCLS_P_COLOR_DE, "<Farbe>"},
/* fr */ {IDCLS_P_COLOR_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_COLOR_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_COLOR_IT, "<colore>"},
/* ko */ {IDCLS_P_COLOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_COLOR_NL, "<kleur>"},
/* ru */ {IDCLS_P_COLOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_COLOR_SV, "<färg>"},
/* tr */ {IDCLS_P_COLOR_TR, "<renk>"},
#endif

/* gfxoutputdrv/doodledrv.c */
/* en */ {IDCLS_OVERSIZED_HANDLING,    N_("Select the way the oversized input should be handled, (0: scale down, 1: crop left top, 2: crop center top,  3: crop right top, 4: crop left center, 5: crop center, 6: crop right center, 7: crop left bottom, 8: crop center bottom, 9:  crop right bottom)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_OVERSIZED_HANDLING_DA, "Angiv håndtering af for stort input (0: skalér ned, 1: klip venstre top, 2: klip midt top,  3: klip højre top, 4: klip venstre midt, 5: klip centreret, 6: klip højre midt, 7: klip venstre bund, 8: klip midt bund, 9: klip højre bund)"},
/* de */ {IDCLS_OVERSIZED_HANDLING_DE, "Wähle, wie übergroßer Input behandelt werden soll, (0: skaliere, 1: schneide links oben, 2: schneide mitte oben,  3: schneide rechts oben, 4: schneide links mitte, 5: schneide mitte, 6: schneide rechts mitte, 7: schneide links unten, 8: schneide mitte unten, 9:  schneide rechts unten)"},
/* fr */ {IDCLS_OVERSIZED_HANDLING_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_OVERSIZED_HANDLING_HU, ""},  /* fuzzy */
/* it */ {IDCLS_OVERSIZED_HANDLING_IT, "Seleziona come gestire il sovradimensionamento dell'input, (0: scale down, 1: ritaglia sinistra alto, 2: ritaglia centro alto,  3: ritaglia destra alto, 4: ritaglia sinistra centro, 5: ritaglia centro, 6: ritaglia destra centro, 7: ritaglia sinistra basso, 8: ritaglia centro basso, 9:  ritaglia destra basso)"},
/* ko */ {IDCLS_OVERSIZED_HANDLING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_OVERSIZED_HANDLING_NL, "Selecteer de manier waarop de te grootte invoer moet worden afgehandeld, (0: maak kleiner, 1: crop linker bovenkant, 2: crop midden bovenkant, 3: crop rechter bovenkant, 4: crop linker midden, 5: crop midden, 6: crop rechter midden, 7: crop linker onderkant, 8: crop midden onderkant, 9: crop rechter onderkant)"},
/* ru */ {IDCLS_OVERSIZED_HANDLING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_OVERSIZED_HANDLING_SV, "Välj hur för stor indata skall hanteras, (0: skala ned, 1: visa övre vänstra, 2: visa övre mitten, 3: visa övre högra, 4: visa vänstra mitten, 5: visa mitten, 6: visa högra mitten, 7: visa nedre vänstra, 8: visa nedre mitten, 9: visa nedre högre)"},
/* tr */ {IDCLS_OVERSIZED_HANDLING_TR, "Büyük girdilerin ele alýnma yöntemini seçin, (0: küçült, 1: sol üstten kýrp, 2: ortalý üstten kýrp,  3: sað üstten kýrp, 4: soldan ortalý kýrp, 5: ortadan kýrp, 6: saðdan ortalý kýrp, 7: sol alttan kýrp, 8: ortalý alttan kýrp, 9:  sað alttan kýrp)"},
#endif

/* gfxoutputdrv/doodledrv.c */
/* en */ {IDCLS_MULTICOLOR_HANDLING,    N_("Select the way the multicolor to hires should be handled, (0: b&w, 1: 2 colors, 2: 4 colors, 3: gray scale,  4: best cell colors)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MULTICOLOR_HANDLING_DA, "Angiv måden multicolor til højopløsning skal håndteres på, (0: sort/hvid, 1: 2 farver, 2: 4 farver, 3: gråtoner,  4: bedste cellefarver)"},
/* de */ {IDCLS_MULTICOLOR_HANDLING_DE, "Wähle, wie Mulitcolore zu Hochauflösung behandelte werden soll, (0: S&W, 1: 2 Farben, 2: 4 Farben, 4 Graustufen, 4: Beste Zellenfarben)"},
/* fr */ {IDCLS_MULTICOLOR_HANDLING_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_MULTICOLOR_HANDLING_HU, ""},  /* fuzzy */
/* it */ {IDCLS_MULTICOLOR_HANDLING_IT, "Seleziona come gestire il multicolor in hires, (0: b&w, 1: 2 colori, 2: 4 colori, 3: scala di grigi,  4: migliori colori cella)"},
/* ko */ {IDCLS_MULTICOLOR_HANDLING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MULTICOLOR_HANDLING_NL, "Selecteer de manier waarop 'multicolor' naar 'hires' conversie moet worden afgehandeld, (0: zwart/wit, 1: 2 kleuren, 2: 4 kleuren, 3: grijs, 4: best mogelijke kleuren in de cel)"},
/* ru */ {IDCLS_MULTICOLOR_HANDLING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MULTICOLOR_HANDLING_SV, "Välj hur flerfärgs-till-högupplöst skall hanteras, (0: svartvit, 1: 2 färger, 2: fyra färger, 3: gråskala, 4: bästa cellfärger)"},
/* tr */ {IDCLS_MULTICOLOR_HANDLING_TR, "Çok renkliden yüksek çözünürlüðe geçiþin ele alýnma yöntemini seçin, (0: siyah&beyaz, 1: 2 renk, 2: 4 renk, 3: gri tonlu,  4: en iyi hücre renkleri)"},
#endif

/* gfxoutputdrv/doodledrv.c */
/* en */ {IDCLS_TED_LUM_HANDLING,    N_("Select the way the TED luminosity should be handled, (0: ignore, 1: dither)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TED_LUM_HANDLING_DA, "Angiv måden TED-lysstyrker skal håndteres på (0: ignorér, 1: blanding)"},
/* de */ {IDCLS_TED_LUM_HANDLING_DE, "Wähle, wie TED Leuchtstärke behandelt werden soll, (0: ignorieren, 1: dither)"},
/* fr */ {IDCLS_TED_LUM_HANDLING_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_TED_LUM_HANDLING_HU, ""},  /* fuzzy */
/* it */ {IDCLS_TED_LUM_HANDLING_IT, "Seleziona come gestire la luminosità TED, (0: ignora, 1: dither)"},
/* ko */ {IDCLS_TED_LUM_HANDLING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TED_LUM_HANDLING_NL, "Selecteer de manier waarop de TED kleuren moeten worden afgehandeld, (0: negeren, 1: dither)"},
/* ru */ {IDCLS_TED_LUM_HANDLING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TED_LUM_HANDLING_SV, "Välj hur TED-luminositet skall hanteras, (0: ignorera, 1: färgutjämna)"},
/* tr */ {IDCLS_TED_LUM_HANDLING_TR, "TED lüminozitesinin ele alýnma yöntemini seçin, (0: yok say, 1: dither)"},
#endif

/* gfxoutputdrv/doodledrv.c */
/* en */ {IDCLS_CRTC_TEXT_COLOR,    N_("Select the CRTC text color (0: white, 1: amber, 2: green)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_CRTC_TEXT_COLOR_DA, "Vælg CRTC tekstfarve (0: hvid, 1: ravgul, 2: grøn)"},
/* de */ {IDCLS_CRTC_TEXT_COLOR_DE, "Wähle CRTC Textfarbe (0: weiß, 1: Amberbraun, 2: Grün)"},
/* fr */ {IDCLS_CRTC_TEXT_COLOR_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_CRTC_TEXT_COLOR_HU, ""},  /* fuzzy */
/* it */ {IDCLS_CRTC_TEXT_COLOR_IT, "Seleziona il colore del testo CRTC (0: bianco, 1: ambra, 2: verde)"},
/* ko */ {IDCLS_CRTC_TEXT_COLOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_CRTC_TEXT_COLOR_NL, "Selecteer de CRTC tekst kleur (0: wit, 1: amber, 2: groen)"},
/* ru */ {IDCLS_CRTC_TEXT_COLOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_CRTC_TEXT_COLOR_SV, "Välj CRTC-textfärg (0: vit, 1: gul, 2: grön)"},
/* tr */ {IDCLS_CRTC_TEXT_COLOR_TR, "CRTC yazý rengini seçin (0: beyaz, 1: kehribar, 2: yeþil)"},
#endif

/* drive/drive-cmdline-options.c */
/* en */ {IDCLS_SET_DRIVE_EXTENSION_POLICY,    N_("Set drive 40 track extension policy (0: never, 1: ask, 2: on access)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_DA, "Angiv drevets regel for 40-spors udviddelse (0: aldrig, 1: spørg, 2: ved tilgang)"},
/* de */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_DE, "40 Spur Erweiterungsmethode (0: nie, 1: Rückfrage, 2: bei Bedarf)"},
/* fr */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_FR, "Spécifier la règle d'extention 40 pistes (0: jamais, 1: demander, 2: à l'accès)"},
/* hu */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_HU, "Adja meg a 40 sávra kiterjesztés terjesztés módját (0: soha, 1: kérdés, 2: hozzáféréskor)"},
/* it */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_IT, "Imposta la politica di estensione a 40 tracce del drive (0: mai, 1: a richiesta, 2: all'accesso)"},
/* ko */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_NL, "Stel beleid voor 40-sporenuitbreiding drive in (0: nooit, 1: vraag, 2: bij toegang)"},
/* ru */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_SV, "Ange regel för 40-spårsutökning (0: aldrig, 1: fråga, 2: vid åtkomst)"},
/* tr */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_TR, "Sürücü 40 track büyüme kuralýný ayarla (0: asla, 1: sor, 2: eriþildiðinde)"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME,    N_("Specify name of 1541 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_DA, "Angiv navn på 1541-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_DE, "Name der 1541 DOS ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_FR, "Spécifier le nom de l'image 1541 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_HU, "Adja meg az 1541 DOS ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1541"},
/* ko */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_NL, "Geef de naam van het 1541 DOS ROM bestand"},
/* ru */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_SV, "Ange namn på 1541-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_TR, "1541 DOS ROM imajýnýn ismini belirt"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME,    N_("Specify name of 1541-II DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_DA, "Angivn navn på 1541-II-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_DE, "Name der 1541-II DOS ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_FR, "Spécifier le nom de l'image 1541-II DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_HU, "Adja meg az 1541-II DOS ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1541-II"},
/* ko */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_NL, "Geef de naam van het 1541-II DOS ROM bestand"},
/* ru */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_SV, "Ange namn på 1541-II-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_TR, "1541-II DOS ROM imajýnýn ismini belirt"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME,    N_("Specify name of 1570 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_DA, "Angivn navn på 1570-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_DE, "Name der 1570 DOS ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_FR, "Spécifier le nom de l'image 1570 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_HU, "Adja meg az 1570 DOS ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1570"},
/* ko */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_NL, "Geef de naam van het 1570 DOS ROM bestand"},
/* ru */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_SV, "Ange namn på 1570-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_TR, "1570 DOS ROM imajýnýn ismini belirt"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME,    N_("Specify name of 1571 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_DA, "Angivn navn på 1571-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_DE, "Name der 1571 DOS ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_FR, "Spécifier le nom de l'image 1571 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_HU, "Adja meg az 1571 DOS ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1571"},
/* ko */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_NL, "Geef de naam van het 1571 DOS ROM bestand"},
/* ru */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_SV, "Ange namn på 1571-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_TR, "1571 DOS ROM imajýnýn ismini belirt"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME,    N_("Specify name of 1581 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_DA, "Angivn navn på 1581-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_DE, "Name der 1581 DOS ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_FR, "Spécifier le nom de l'image 1581 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_HU, "Adja meg az 1581 DOS ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1581"},
/* ko */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_NL, "Geef de naam van het 1581 DOS ROM bestand"},
/* ru */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_SV, "Ange namn på 1581-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_TR, "1581 DOS ROM imajýnýn ismini belirt"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SET_IDLE_METHOD,    N_("Set drive idling method (0: no traps, 1: skip cycles, 2: trap idle)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_IDLE_METHOD_DA, "Vælg pausemetode for diskettedrev (0: ingen traps, 1: spring over cykler, 2: trap ledig)"},
/* de */ {IDCLS_SET_IDLE_METHOD_DE, "Laufwerks idling Methode (0: kein Traps, 1: Zyklen verwerfen, 2: trap idle)"},
/* fr */ {IDCLS_SET_IDLE_METHOD_FR, "Spécifier la méthode d'idle (0: pas de traps, 1: sauter des cycles, 2: trap idle)"},
/* hu */ {IDCLS_SET_IDLE_METHOD_HU, "Lemezegység üresjárási módja (0: folytonos emuláció, 1: ciklusok kihagyása, 2: üres DOS ciklusok kihagyása)"},
/* it */ {IDCLS_SET_IDLE_METHOD_IT, "Imposta il metodo per rilevare l'inattività del drive (0: non rilevare, 1: salta cicli, 2: rileva inattività)"},
/* ko */ {IDCLS_SET_IDLE_METHOD_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_IDLE_METHOD_NL, "Stel de drive idlemethode in (0: geen traps, 1: sla cycli over, 2: trap idle)"},
/* ru */ {IDCLS_SET_IDLE_METHOD_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_IDLE_METHOD_SV, "Ställ in väntemetod för diskettstation (0: fånta inge, 1: hoppa cykler, 2: fånga väntan)"},
/* tr */ {IDCLS_SET_IDLE_METHOD_TR, "Sürücü boþa vakit geçirme metodunu ayarlayýn (0: trap yok, 1: cyclelarý atla, 2: trap boþa vakit geçirme)"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DRIVE_RAM_2000,    N_("Enable 8KB RAM expansion at $2000-$3FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DRIVE_RAM_2000_DA, "Aktivér 8KB RAM-udviddelse på $2000-$3FFF"},
/* de */ {IDCLS_ENABLE_DRIVE_RAM_2000_DE, "8KB RAM Erweiterung bei $2000-3fff aktivieren"},
/* fr */ {IDCLS_ENABLE_DRIVE_RAM_2000_FR, "Activer l'exansion de 8KB RAM à $2000-$3FFF"},
/* hu */ {IDCLS_ENABLE_DRIVE_RAM_2000_HU, "8KB RAM kiterjeszés engedélyezése a $2000-$3FFF címen"},
/* it */ {IDCLS_ENABLE_DRIVE_RAM_2000_IT, "Attiva l'espansione di RAM di 8KB a $2000-$3FFF"},
/* ko */ {IDCLS_ENABLE_DRIVE_RAM_2000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DRIVE_RAM_2000_NL, "Activeer 8KB RAM uitbreiding op adres $2000-$3FFF"},
/* ru */ {IDCLS_ENABLE_DRIVE_RAM_2000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DRIVE_RAM_2000_SV, "Aktivera 8KB RAM-expansion på $2000-$3FFF"},
/* tr */ {IDCLS_ENABLE_DRIVE_RAM_2000_TR, "$2000-$3FFF arasýnda 8KB RAM geniþletmeyi aktif et"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DRIVE_RAM_2000,    N_("Disable 8KB RAM expansion at $2000-$3FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DRIVE_RAM_2000_DA, "Deaktivér 8KB RAM-udviddelse på $2000-$3FFF"},
/* de */ {IDCLS_DISABLE_DRIVE_RAM_2000_DE, "8KB RAM Erweiterung bei $2000-3fff deaktivieren"},
/* fr */ {IDCLS_DISABLE_DRIVE_RAM_2000_FR, "Désactiver l'exansion de 8KB RAM à $2000-$3FFF"},
/* hu */ {IDCLS_DISABLE_DRIVE_RAM_2000_HU, "8KB RAM kiterjeszés tiltása a $2000-$3FFF címen"},
/* it */ {IDCLS_DISABLE_DRIVE_RAM_2000_IT, "Disattiva l'espansione di RAM di 8KB a $2000-$3FFF"},
/* ko */ {IDCLS_DISABLE_DRIVE_RAM_2000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DRIVE_RAM_2000_NL, "8KB RAM uitbreiding op adres $2000-$3FFF uitschakelen"},
/* ru */ {IDCLS_DISABLE_DRIVE_RAM_2000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DRIVE_RAM_2000_SV, "Inaktivera 8KB RAM-expansion på $2000-$3FFF"},
/* tr */ {IDCLS_DISABLE_DRIVE_RAM_2000_TR, "$2000-$3FFF arasýnda 8KB RAM geniþletmeyi pasifleþtir"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DRIVE_RAM_4000,    N_("Enable 8KB RAM expansion at $4000-$5FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DRIVE_RAM_4000_DA, "Aktivér 8KB RAM-udviddelse på $4000-$5FFF"},
/* de */ {IDCLS_ENABLE_DRIVE_RAM_4000_DE, "8KB RAM Erweiterung bei $4000-5fff aktivieren"},
/* fr */ {IDCLS_ENABLE_DRIVE_RAM_4000_FR, "Activer l'exansion de 8KB RAM à $4000-$5FFF"},
/* hu */ {IDCLS_ENABLE_DRIVE_RAM_4000_HU, "8KB RAM kiterjeszés engedélyezése a $4000-$5FFF címen"},
/* it */ {IDCLS_ENABLE_DRIVE_RAM_4000_IT, "Attiva l'espansione di RAM di 8KB a $4000-$5FFF"},
/* ko */ {IDCLS_ENABLE_DRIVE_RAM_4000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DRIVE_RAM_4000_NL, "Activeer 8KB RAM uitbreiding op adres $4000-$5FFF"},
/* ru */ {IDCLS_ENABLE_DRIVE_RAM_4000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DRIVE_RAM_4000_SV, "Aktivera 8KB RAM-expansion på $4000-$5FFF"},
/* tr */ {IDCLS_ENABLE_DRIVE_RAM_4000_TR, "$4000-$5FFF arasýnda 8KB RAM geniþletmeyi aktif et"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DRIVE_RAM_4000,    N_("Disable 8KB RAM expansion at $4000-$5FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DRIVE_RAM_4000_DA, "Deaktivér 8KB RAM-udviddelse på $4000-$5FFF"},
/* de */ {IDCLS_DISABLE_DRIVE_RAM_4000_DE, "8KB RAM Erweiterung bei $4000-5fff deaktivieren"},
/* fr */ {IDCLS_DISABLE_DRIVE_RAM_4000_FR, "Désactiver l'exansion de 8KB RAM à $4000-$5FFF"},
/* hu */ {IDCLS_DISABLE_DRIVE_RAM_4000_HU, "8KB RAM kiterjeszés tiltása a $4000-$5FFF címen"},
/* it */ {IDCLS_DISABLE_DRIVE_RAM_4000_IT, "Disattiva l'espansione di RAM di 8KB a $4000-$5FFF"},
/* ko */ {IDCLS_DISABLE_DRIVE_RAM_4000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DRIVE_RAM_4000_NL, "8KB RAM uitbreiding op adres $4000-$5FFF uitschakelen"},
/* ru */ {IDCLS_DISABLE_DRIVE_RAM_4000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DRIVE_RAM_4000_SV, "Inaktivera 8KB RAM-expansion på $4000-$5FFF"},
/* tr */ {IDCLS_DISABLE_DRIVE_RAM_4000_TR, "$4000-$5FFF arasýnda 8KB RAM geniþletmeyi pasifleþtir"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DRIVE_RAM_6000,    N_("Enable 8KB RAM expansion at $6000-$7FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DRIVE_RAM_6000_DA, "Aktivér 8KB RAM-udviddelse på $6000-$7FFF"},
/* de */ {IDCLS_ENABLE_DRIVE_RAM_6000_DE, "8KB RAM Erweiterung bei $6000-7fff aktivieren"},
/* fr */ {IDCLS_ENABLE_DRIVE_RAM_6000_FR, "Activer l'exansion de 8KB RAM à $6000-$7FFF"},
/* hu */ {IDCLS_ENABLE_DRIVE_RAM_6000_HU, "8KB RAM kiterjeszés engedélyezése a $6000-$7FFF címen"},
/* it */ {IDCLS_ENABLE_DRIVE_RAM_6000_IT, "Attiva l'espansione di RAM di 8KB a $6000-$7FFF"},
/* ko */ {IDCLS_ENABLE_DRIVE_RAM_6000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DRIVE_RAM_6000_NL, "Activeer 8KB RAM uitbreiding op adres $6000-$7FFF"},
/* ru */ {IDCLS_ENABLE_DRIVE_RAM_6000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DRIVE_RAM_6000_SV, "Aktivera 8KB RAM-expansion på $6000-$7FFF"},
/* tr */ {IDCLS_ENABLE_DRIVE_RAM_6000_TR, "$6000-$7FFF arasýnda 8KB RAM geniþletmeyi aktif et"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DRIVE_RAM_6000,    N_("Disable 8KB RAM expansion at $6000-$7FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DRIVE_RAM_6000_DA, "Deaktivér 8KB RAM-udviddelse på $6000-$7FFF"},
/* de */ {IDCLS_DISABLE_DRIVE_RAM_6000_DE, "8KB RAM Erweiterung bei $6000-7fff deaktivieren"},
/* fr */ {IDCLS_DISABLE_DRIVE_RAM_6000_FR, "Désactiver l'exansion de 8KB RAM à $6000-$7FFF"},
/* hu */ {IDCLS_DISABLE_DRIVE_RAM_6000_HU, "8KB RAM kiterjeszés tiltása a $6000-$7FFF címen"},
/* it */ {IDCLS_DISABLE_DRIVE_RAM_6000_IT, "Disattiva l'espansione di RAM di 8KB a $6000-$7FFF"},
/* ko */ {IDCLS_DISABLE_DRIVE_RAM_6000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DRIVE_RAM_6000_NL, "8KB RAM uitbreiding op adres $6000-$7FFF uitschakelen"},
/* ru */ {IDCLS_DISABLE_DRIVE_RAM_6000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DRIVE_RAM_6000_SV, "Inaktivera 8KB RAM-expansion på $6000-$7FFF"},
/* tr */ {IDCLS_DISABLE_DRIVE_RAM_6000_TR, "$6000-$7FFF arasýnda 8KB RAM geniþletmeyi pasifleþtir"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DRIVE_RAM_8000,    N_("Enable 8KB RAM expansion at $8000-$9FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DRIVE_RAM_8000_DA, "Aktivér 8KB RAM-udviddelse på $8000-$9FFF"},
/* de */ {IDCLS_ENABLE_DRIVE_RAM_8000_DE, "8KB RAM Erweiterung bei $8000-9fff aktivieren"},
/* fr */ {IDCLS_ENABLE_DRIVE_RAM_8000_FR, "Activer l'exansion de 8KB RAM à $8000-$9FFF"},
/* hu */ {IDCLS_ENABLE_DRIVE_RAM_8000_HU, "8KB RAM kiterjeszés engedélyezése a $8000-$9FFF címen"},
/* it */ {IDCLS_ENABLE_DRIVE_RAM_8000_IT, "Attiva l'espansione di RAM di 8KB a $8000-$9FFF"},
/* ko */ {IDCLS_ENABLE_DRIVE_RAM_8000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DRIVE_RAM_8000_NL, "Activeer 8KB RAM uitbreiding op adres $8000-$9FFF"},
/* ru */ {IDCLS_ENABLE_DRIVE_RAM_8000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DRIVE_RAM_8000_SV, "Aktivera 8KB RAM-expansion på $8000-$9FFF"},
/* tr */ {IDCLS_ENABLE_DRIVE_RAM_8000_TR, "$8000-$9FFF arasýnda 8KB RAM geniþletmeyi aktif et"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DRIVE_RAM_8000,    N_("Disable 8KB RAM expansion at $8000-$9FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DRIVE_RAM_8000_DA, "Deaktivér 8KB RAM-udviddelse på $8000-$9FFF"},
/* de */ {IDCLS_DISABLE_DRIVE_RAM_8000_DE, "8KB RAM Erweiterung bei $8000-9fff deaktivieren"},
/* fr */ {IDCLS_DISABLE_DRIVE_RAM_8000_FR, "Désactiver l'exansion de 8KB RAM à $8000-$9FFF"},
/* hu */ {IDCLS_DISABLE_DRIVE_RAM_8000_HU, "8KB RAM kiterjeszés tiltása a $8000-$9FFF címen"},
/* it */ {IDCLS_DISABLE_DRIVE_RAM_8000_IT, "Disattiva l'espansione di RAM di 8KB a $8000-$9FFF"},
/* ko */ {IDCLS_DISABLE_DRIVE_RAM_8000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DRIVE_RAM_8000_NL, "8KB RAM uitbreiding op adres $8000-$9FFF uitschakelen"},
/* ru */ {IDCLS_DISABLE_DRIVE_RAM_8000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DRIVE_RAM_8000_SV, "Inaktivera 8KB RAM-expansion på $8000-$9FFF"},
/* tr */ {IDCLS_DISABLE_DRIVE_RAM_8000_TR, "$8000-$9FFF arasýnda 8KB RAM geniþletmeyi pasifleþtir"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DRIVE_RAM_A000,    N_("Enable 8KB RAM expansion at $A000-$BFFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DRIVE_RAM_A000_DA, "Aktivér 8KB RAM-udviddelse på $A000-$BFFF"},
/* de */ {IDCLS_ENABLE_DRIVE_RAM_A000_DE, "8KB RAM Erweiterung bei $A000-Bfff aktivieren"},
/* fr */ {IDCLS_ENABLE_DRIVE_RAM_A000_FR, "Activer l'exansion de 8KB RAM à $A000-$BFFF"},
/* hu */ {IDCLS_ENABLE_DRIVE_RAM_A000_HU, "8KB RAM kiterjeszés engedélyezése a $A000-$BFFF címen"},
/* it */ {IDCLS_ENABLE_DRIVE_RAM_A000_IT, "Attiva l'espansione di RAM di 8KB a $A000-$BFFF"},
/* ko */ {IDCLS_ENABLE_DRIVE_RAM_A000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DRIVE_RAM_A000_NL, "Activeer 8KB RAM uitbreiding op adres $A000-$BFFF"},
/* ru */ {IDCLS_ENABLE_DRIVE_RAM_A000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DRIVE_RAM_A000_SV, "Aktivera 8KB RAM-expansion på $A000-$BFFF"},
/* tr */ {IDCLS_ENABLE_DRIVE_RAM_A000_TR, "$A000-$BFFF arasýnda 8KB RAM geniþletmeyi aktif et"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DRIVE_RAM_A000,    N_("Disable 8KB RAM expansion at $A000-$BFFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DRIVE_RAM_A000_DA, "Deaktivér 8KB RAM-udviddelse på $A000-$BFFF"},
/* de */ {IDCLS_DISABLE_DRIVE_RAM_A000_DE, "8KB RAM Erweiterung bei $A000-Bfff deaktivieren"},
/* fr */ {IDCLS_DISABLE_DRIVE_RAM_A000_FR, "Désactiver l'exansion de 8KB RAM à $A000-$BFFF"},
/* hu */ {IDCLS_DISABLE_DRIVE_RAM_A000_HU, "8KB RAM kiterjeszés tiltása a $A000-$BFFF címen"},
/* it */ {IDCLS_DISABLE_DRIVE_RAM_A000_IT, "Disattiva l'espansione di RAM di 8KB a $A000-$BFFF"},
/* ko */ {IDCLS_DISABLE_DRIVE_RAM_A000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DRIVE_RAM_A000_NL, "8KB RAM uitbreiding op adres $A000-$BFFF uitschakelen"},
/* ru */ {IDCLS_DISABLE_DRIVE_RAM_A000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DRIVE_RAM_A000_SV, "Inaktivera 8KB RAM-expansion på $A000-$BFFF"},
/* tr */ {IDCLS_DISABLE_DRIVE_RAM_A000_TR, "$A000-$BFFF arasýnda 8KB RAM geniþletmeyi pasifleþtir"},
#endif

/* drive/iec/c64exp/c64exp-cmdline-options.c */
/* en */ {IDCLS_PAR_CABLE_C64EXP_TYPE,    N_("Set parallel cable type (0: none, 1: standard, 2: Dolphin DOS 3)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PAR_CABLE_C64EXP_TYPE_DA, "Vælg typen af parallelkabel (0: ingen, 1: standard, 2: Dolphin DOS 3)"},
/* de */ {IDCLS_PAR_CABLE_C64EXP_TYPE_DE, "Parallelkabel Typ (0: kein, 1: Standard, 2: Dolphin DOS 3)"},
/* fr */ {IDCLS_PAR_CABLE_C64EXP_TYPE_FR, "Définir le type de câble parallèle (0: aucun, 1: standard, 2: Dolphin DOS 3)"},
/* hu */ {IDCLS_PAR_CABLE_C64EXP_TYPE_HU, "Adja meg a párhuzamos kábel típusát (0: nincs, 1: standard, 2: Dolphin DOS 3)"},
/* it */ {IDCLS_PAR_CABLE_C64EXP_TYPE_IT, "Imposta il tipo di cavo parallelo (0: nessuno, 1: standard, 2: Dolphin DOS 3)"},
/* ko */ {IDCLS_PAR_CABLE_C64EXP_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PAR_CABLE_C64EXP_TYPE_NL, "Zet parallele kabelsoort (0: geen, 1: standaard, 2: Dolphin DOS 3)"},
/* ru */ {IDCLS_PAR_CABLE_C64EXP_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PAR_CABLE_C64EXP_TYPE_SV, "Välj typ av parallellkabel (0: ingen, 1: standard, 2: Dolphin DOS 3)"},
/* tr */ {IDCLS_PAR_CABLE_C64EXP_TYPE_TR, "Paralel kablo tipini ayarla (0: yok, 1: standart, 2: Dolphin DOS 3)"},
#endif

/* drive/iec/c64exp/c64exp-cmdline-options.c */
/* en */ {IDCLS_ENABLE_PROFDOS,    N_("Enable Professional DOS")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PROFDOS_DA, "Aktivér Professional DOS"},
/* de */ {IDCLS_ENABLE_PROFDOS_DE, "Professional DOS aktivieren"},
/* fr */ {IDCLS_ENABLE_PROFDOS_FR, "Activer le DOS Professionnel"},
/* hu */ {IDCLS_ENABLE_PROFDOS_HU, "Professional DOS engedélyezése"},
/* it */ {IDCLS_ENABLE_PROFDOS_IT, "Attiva Professional DOS"},
/* ko */ {IDCLS_ENABLE_PROFDOS_KO, "Professional DOS »ç¿ë°¡´ÉÇÏ°Ô ÇÏ±â"},
/* nl */ {IDCLS_ENABLE_PROFDOS_NL, "Activeer Professional DOS"},
/* ru */ {IDCLS_ENABLE_PROFDOS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PROFDOS_SV, "Aktivera Professional DOS"},
/* tr */ {IDCLS_ENABLE_PROFDOS_TR, "Professional DOS'u aktif et"},
#endif

/* drive/iec/c64exp/c64exp-cmdline-options.c */
/* en */ {IDCLS_DISABLE_PROFDOS,    N_("Disable Professional DOS")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PROFDOS_DA, "Deaktivér Professional DOS"},
/* de */ {IDCLS_DISABLE_PROFDOS_DE, "Professional DOS deaktivieren"},
/* fr */ {IDCLS_DISABLE_PROFDOS_FR, "Désactiver le DOS Professionnel"},
/* hu */ {IDCLS_DISABLE_PROFDOS_HU, "Professional DOS tiltása"},
/* it */ {IDCLS_DISABLE_PROFDOS_IT, "Disattiva Professional DOS"},
/* ko */ {IDCLS_DISABLE_PROFDOS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PROFDOS_NL, "Professional DOS uitschakelen"},
/* ru */ {IDCLS_DISABLE_PROFDOS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PROFDOS_SV, "Inaktivera Professional DOS"},
/* tr */ {IDCLS_DISABLE_PROFDOS_TR, "Professional DOS'u pasifleþtir"},
#endif

/* drive/iec/c64exp/c64exp-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME,    N_("Specify name of Professional DOS 1571 ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_DA, "Angiv navn på Professional DOS 1571-ROM-image"},
/* de */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_DE, "Name von Professional DOS 1571 Datei definieren"},
/* fr */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_HU, "Adja meg a Professional DOS 1571 ROM képmást"},
/* it */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_IT, "Specifica il nome immagine della ROM del Professional DOS 1571"},
/* ko */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_NL, "Geef de naam van het Professional DOS 1571 ROM bestand"},
/* ru */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_SV, "Ange namn på Professional DOS 1571-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_TR, "Professional DOS 1571 ROM imaj ismini belirt"},
#endif

/* drive/iec/plus4exp/plus4exp-cmdline-options.c */
/* en */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE,    N_("Set parallel cable type (0: none, 1: standard)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_DA, "Vælg typen af parallelkabel parallellkabel (0: ingen, 1: standard)"},
/* de */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_DE, "Parallelkabel Typ (0: kein, 1: Standard)"},
/* fr */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_FR, "Définir le type de câble parallèle (0: aucun, 1: standard)"},
/* hu */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_HU, "Adja meg a párhuzamos kábel típusát (0: nincs, 1: standard)"},
/* it */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_IT, "Imposta il tipo di cavo parallelo (0: nessuno, 1: standard)"},
/* ko */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_NL, "Zet parallelle kabelsoort (0: geen, 1: standaard)"},
/* ru */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_SV, "Välj typ av parallellkabel (0: ingen, 1: standard)"},
/* tr */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_TR, "Paralel kablo tipini ayarlayýn (0: yok, 1: standart)"},
#endif

/* drive/iec128dcr/iec128dcr-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME,    N_("Specify name of 1571CR DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_DA, "Angiv navn på 1571CR-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_DE, "Name der 1571CR DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_FR, "Spécifier le nom de l'image 1571CR DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_HU, "Adja meg az 1571CR DOS ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1571CR"},
/* ko */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_NL, "Geef de naam van het 1571CR DOS ROM bestand"},
/* ru */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_SV, "Ange namn på 1571CR-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_TR, "1571CR DOS ROM imaj ismini belirt"},
#endif

/* drive/ieee/ieee-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME,    N_("Specify name of 2031 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_DA, "Angiv navn på 2031-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_DE, "Name der 2031 DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_FR, "Spécifier le nom de l'image 2031 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_HU, "Adja meg a 2031 DOS ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 2031"},
/* ko */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_NL, "Geef de naam van het 2031 DOS ROM bestand"},
/* ru */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_SV, "Ange namn på 2031-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_TR, "2031 DOS ROM imaj ismini belirt"},
#endif

/* drive/ieee/ieee-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME,    N_("Specify name of 2040 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_DA, "Angiv navn på 2040-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_DE, "Name der 2040 DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_FR, "Spécifier le nom de l'image 2040 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_HU, "Adja meg a 2040 DOS ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 2040"},
/* ko */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_NL, "Geef de naam van het 2040 DOS ROM bestand"},
/* ru */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_SV, "Ange namn på 2040-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_TR, "2040 DOS ROM imaj ismini belirt"},
#endif

/* drive/ieee/ieee-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME,    N_("Specify name of 3040 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_DA, "Angiv navn på 3040-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_DE, "Name der 3040 DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_FR, "Spécifier le nom de l'image 3040 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_HU, "Adja meg a 3040 DOS ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 3040"},
/* ko */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_NL, "Geef de naam van het 3040 DOS ROM bestand"},
/* ru */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_SV, "Ange namn på 3040-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_TR, "3040 DOS ROM imaj ismini belirt"},
#endif

/* drive/ieee/ieee-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME,    N_("Specify name of 4040 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_DA, "Angiv navn på 4040-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_DE, "Name der 4040 DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_FR, "Spécifier le nom de l'image 4040 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_HU, "Adja meg a 4040 DOS ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 4040"},
/* ko */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_NL, "Geef de naam van het 4040 DOS ROM bestand"},
/* ru */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_SV, "Ange namn på 4040-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_TR, "4040 DOS ROM imaj ismini belirt"},
#endif

/* drive/ieee/ieee-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME,    N_("Specify name of 1001/8050/8250 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_DA, "Angiv navn på 1001/8050/8250-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_DE, "Name der 1001/8040/8205 DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_FR, "Spécifier le nom de l'image 1001/8050/8250 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_HU, "Adja meg az 1001/8050/8250 DOS ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1001/8050/8250"},
/* ko */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_NL, "Geef de naam van het 1001/8050/8250 DOS ROM bestand"},
/* ru */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_SV, "Ange namn på 1001/8050/8250-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_TR, "1001/8050/8250 DOS ROM imaj ismini belirt"},
#endif

/* drive/tcbm/tcbm-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME,    N_("Specify name of 1551 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_DA, "Angiv navn på 1551-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_DE, "Name der 1551 DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_FR, "Spécifier le nom de l'image 1551 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_HU, "Adja meg az 1551 DOS ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1551"},
/* ko */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_NL, "Geef de naam van het 1551 DOS ROM bestand"},
/* ru */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_SV, "Ange namn på 1551-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_TR, "1551 DOS ROM imaj ismini belirt"},
#endif

/* fsdevice/fsdevice-cmdline-options.c */
/* en */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8,    N_("Use <name> as directory for file system device #8")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_DA, "Brug <navn> som katalog for filsystembaseret drev #8"},
/* de */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_DE, "Benutze <Name> für Verzeichnis beim Verzeichniszugriff für Gerät #8"},
/* fr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_FR, "Utiliser le répertoire <nom> comme système de fichiers pour le lecteur #8"},
/* hu */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_HU, "<név> könyvtár használata az #8-as egység fájlrendszerének"},
/* it */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_IT, "Una <nome> come direcory per il file system della periferica #8"},
/* ko */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_NL, "Gebruik <naam> als directory voor bestandssysteemapparaat #8"},
/* ru */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_SV, "Ange <namn> som katalog för filsystemsbaserad enhet 8"},
/* tr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_TR, "<isim>'i aygýt #8'in dosya sistemi dizini olarak kullan"},
#endif

/* fsdevice/fsdevice-cmdline-options.c */
/* en */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9,    N_("Use <name> as directory for file system device #9")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_DA, "Brug <navn> som katalog for filsystembaseret drev #9"},
/* de */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_DE, "Benutze <Name> für Verzeichnis beim Verzeichniszugriff für Gerät #9"},
/* fr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_FR, "Utiliser le répertoire <nom> comme système de fichiers pour le lecteur #9"},
/* hu */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_HU, "<név> könyvtár használata az #9-es egység fájlrendszerének"},
/* it */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_IT, "Una <nome> come direcory per il file system della periferica #9"},
/* ko */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_NL, "Gebruik <naam> als directory voor bestandssysteemapparaat #9"},
/* ru */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_SV, "Ange <namn> som katalog för filsystemsbaserad enhet 9"},
/* tr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_TR, "<isim>'i aygýt #9'un dosya sistemi dizini olarak kullan"},
#endif

/* fsdevice/fsdevice-cmdline-options.c */
/* en */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10,    N_("Use <name> as directory for file system device #10")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_DA, "Brug <navn> som katalog for filsystembaseret drev #10"},
/* de */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_DE, "Benutze <Name> für Verzeichnis beim Verzeichniszugriff für Gerät #10"},
/* fr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_FR, "Utiliser le répertoire <nom> comme système de fichiers pour le lecteur #10"},
/* hu */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_HU, "<név> könyvtár használata az #10-es egység fájlrendszerének"},
/* it */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_IT, "Una <nome> come direcory per il file system della periferica #10"},
/* ko */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_NL, "Gebruik <naam> als directory voor bestandssysteemapparaat #10"},
/* ru */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_SV, "Ange <namn> som katalog för filsystemsbaserad enhet 10"},
/* tr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_TR, "<isim>'i aygýt #10'un dosya sistemi dizini olarak kullan"},
#endif

/* fsdevice/fsdevice-cmdline-options.c */
/* en */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11,    N_("Use <name> as directory for file system device #11")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_DA, "Brug <navn> som katalog for filsystembaseret drev #11"},
/* de */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_DE, "Benutze <Name> für Verzeichnis beim Verzeichniszugriff für Gerät #11"},
/* fr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_FR, "Utiliser le répertoire <nom> comme système de fichiers pour le lecteur #11"},
/* hu */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_HU, "<név> könyvtár használata az #11-es egység fájlrendszerének"},
/* it */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_IT, "Una <nome> come direcory per il file system della periferica #11"},
/* ko */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_NL, "Gebruik <naam> als directory voor bestandssysteemapparaat #11"},
/* ru */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_SV, "Ange <namn> som katalog för filsystemsbaserad enhet 11"},
/* tr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_TR, "<isim>'i aygýt #11'in dosya sistemi dizini olarak kullan"},
#endif

#ifdef HAVE_FFMPEG
/* gfxoutputdrv/ffmpegdrv.c */
/* en */ {IDCLS_SET_AUDIO_STREAM_BITRATE,    N_("Set bitrate for audio stream in media file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_AUDIO_STREAM_BITRATE_DA, "Angiv bitrate for lydstrøm i mediefil"},
/* de */ {IDCLS_SET_AUDIO_STREAM_BITRATE_DE, "Bitrate für Audio Stream für Media Datei setzen"},
/* fr */ {IDCLS_SET_AUDIO_STREAM_BITRATE_FR, "Régler le bitrate audio du fichier média"},
/* hu */ {IDCLS_SET_AUDIO_STREAM_BITRATE_HU, "Adja meg az audió bitrátát a média fájlhoz"},
/* it */ {IDCLS_SET_AUDIO_STREAM_BITRATE_IT, "Imposta il bitrate del flusso audio nel file multimediale"},
/* ko */ {IDCLS_SET_AUDIO_STREAM_BITRATE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_AUDIO_STREAM_BITRATE_NL, "Zet de bitrate voor het audiogedeelte van het mediabestand"},
/* ru */ {IDCLS_SET_AUDIO_STREAM_BITRATE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_AUDIO_STREAM_BITRATE_SV, "Ange bithastighet för ljudström i mediafil"},
/* tr */ {IDCLS_SET_AUDIO_STREAM_BITRATE_TR, "Ses akýþý için ortam dosyasýndaki bithýzý'ný ayarla"},
#endif

/* gfxoutputdrv/ffmpegdrv.c */
/* en */ {IDCLS_SET_VIDEO_STREAM_BITRATE,    N_("Set bitrate for video stream in media file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_VIDEO_STREAM_BITRATE_DA, "Angiv bitrate for videostrøm i mediefil"},
/* de */ {IDCLS_SET_VIDEO_STREAM_BITRATE_DE, "Bitrate für Video Stream für Media Datei setzen"},
/* fr */ {IDCLS_SET_VIDEO_STREAM_BITRATE_FR, "Régler le bitrate vidéo du fichier média"},
/* hu */ {IDCLS_SET_VIDEO_STREAM_BITRATE_HU, "Adja meg az videó bitrátát a média fájlhoz"},
/* it */ {IDCLS_SET_VIDEO_STREAM_BITRATE_IT, "Imposta il bitrate per il flusso video nel file multimediale"},
/* ko */ {IDCLS_SET_VIDEO_STREAM_BITRATE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_VIDEO_STREAM_BITRATE_NL, "Zet de bitrate voor het videogedeelte van het mediabestand"},
/* ru */ {IDCLS_SET_VIDEO_STREAM_BITRATE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_VIDEO_STREAM_BITRATE_SV, "Ange bithastighet för videoström i mediafil"},
/* tr */ {IDCLS_SET_VIDEO_STREAM_BITRATE_TR, "Görüntü akýþý için ortam dosyasýndaki bithýzý'ný ayarla"},
#endif
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_PET_MODEL,    N_("Specify PET model to emulate")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PET_MODEL_DA, "Angiv emuleret PET-model"},
/* de */ {IDCLS_SPECIFY_PET_MODEL_DE, "PET Modell spezifizieren"},
/* fr */ {IDCLS_SPECIFY_PET_MODEL_FR, "Spécifier le modèle PET à émuler"},
/* hu */ {IDCLS_SPECIFY_PET_MODEL_HU, "Adja meg az emulált PET modellt"},
/* it */ {IDCLS_SPECIFY_PET_MODEL_IT, "Specifica il modello di PET da emulare"},
/* ko */ {IDCLS_SPECIFY_PET_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PET_MODEL_NL, "Geef PET model om te emuleren"},
/* ru */ {IDCLS_SPECIFY_PET_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PET_MODEL_SV, "Ange PET-modell att emulera"},
/* tr */ {IDCLS_SPECIFY_PET_MODEL_TR, "Emüle edilecek PET modelini belirt"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_EDITOR_ROM_NAME,    N_("Specify name of Editor ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_DA, "Angiv navn på Editor-ROM-image"},
/* de */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_DE, "Name für Editor ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_FR, "Spécifier le nom de l’image ROM Editor"},
/* hu */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_HU, "Adja meg a szerkesztõ ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_IT, "Specifica il nome immagine della Editor ROM"},
/* ko */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_NL, "Geef naam van het Editor ROM bestand"},
/* ru */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_SV, "Ange namn på Editor-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_TR, "Editor ROM imajýnýn ismini belirt"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME,    N_("Specify 4K extension ROM name at $9***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_DA, "Angiv navn på 4K-udviddelses-ROM på $9***"},
/* de */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_DE, "4K Erweiterungs ROM Datei Name bei $9*** definieren"},
/* fr */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_FR, "Spécifier le nom de l'extension ROM 4K à $9***"},
/* hu */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_HU, "Adja meg a $9*** címû 4K ROM kiterjesztés nevét"},
/* it */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_IT, "Specifica il nome della ROM di estensione di 4k a $9***"},
/* ko */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_NL, "Geef naam van het 4K uitbreiding ROM bestand op adres $9***"},
/* ru */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_SV, "Ange namn på 4K-utöknings-ROM på $9***"},
/* tr */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_TR, "$9*** adresindeki 4K uzantýsý ROM ismini belirt"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME,    N_("Specify 4K extension ROM name at $A***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_DA, "Angiv navn på 4K-udviddelses-ROM på $A***"},
/* de */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_DE, "4K Erweiterungs ROM Datei Name bei $A*** definieren"},
/* fr */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_FR, "Spécifier le nom de l'extension ROM 4K à $A***"},
/* hu */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_HU, "Adja meg a $A*** címû 4K ROM kiterjesztés nevét"},
/* it */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_IT, "Specifica il nome della ROM di estensione di 4k a $A***"},
/* ko */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_NL, "Geef naam van het 4K uitbreiding ROM bestand op adres $A***"},
/* ru */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_SV, "Ange namn på 4K-utöknings-ROM på $A***"},
/* tr */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_TR, "$A*** adresindeki 4K uzantýsý ROM ismini belirt"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME,    N_("Specify 4K extension ROM name at $B***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_DA, "Angiv navn på 4K-udviddelses-ROM på $B***"},
/* de */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_DE, "4K Erweiterungs ROM Datei Name bei $B*** definieren"},
/* fr */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_FR, "Spécifier le nom de l'extension ROM 4K à $B***"},
/* hu */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_HU, "Adja meg a $B*** címû 4K ROM kiterjesztés nevét"},
/* it */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_IT, "Specifica il nome della ROM di estensione di 4k a $B***"},
/* ko */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_NL, "Geef naam van het 4K uitbreiding ROM bestand op adres $B***"},
/* ru */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_SV, "Ange namn på 4K-utöknings-ROM på $B***"},
/* tr */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_TR, "$B*** adresindeki 4K uzantýsý ROM ismini belirt"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000,    N_("Enable PET8296 4K RAM mapping at $9***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_DA, "Aktivér PET8296 4K-RAM-mapping på $9***"},
/* de */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_DE, "PET8296 4K RAM Zuordnung bei $9*** aktivieren"},
/* fr */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_FR, "Activer l'extension PET8296 4K à $9***"},
/* hu */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_HU, "PET8296 4K RAM engedélyezése a $9*** címen"},
/* it */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_IT, "Attiva la mappatura della RAM di 4K del PET8296 a $9***"},
/* ko */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_NL, "Activeer PET8296 4K RAM op adres $9***"},
/* ru */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_SV, "Aktivera PET8296 4K-RAM-mappning på $9***"},
/* tr */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_TR, "$9*** adresindeki PET8296 4K RAM eþleþtirmesini aktif et"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000,    N_("Disable PET8296 4K RAM mapping at $9***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_DA, "Deaktivér PET8296 4K-RAM-mapping på $9***"},
/* de */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_DE, "PET8296 4K RAM Zuordnung bei $9*** deaktivieren"},
/* fr */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_FR, "Désactiver l'extension PET8296 4K à $9***"},
/* hu */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_HU, "PET8296 4K RAM tiltása a $9*** címen"},
/* it */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_IT, "Disattiva la mappatura della RAM di 4K del PET8296 a $9***"},
/* ko */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_NL, "PET8296 4K RAM op adres $9*** uitschakelen"},
/* ru */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_SV, "Inaktivera PET8296 4K-RAM-mappning på $9***"},
/* tr */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_TR, "$9*** adresindeki PET8296 4K RAM eþleþtirmesini pasifleþtir"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000,    N_("Enable PET8296 4K RAM mapping at $A***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_DA, "Aktivér PET8296 4K-RAM-mapping på $A***"},
/* de */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_DE, "PET8296 4K RAM Zuordnung bei $A*** aktivieren"},
/* fr */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_FR, "Activer l'extension PET8296 4K à $A***"},
/* hu */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_HU, "PET8296 4K RAM engedélyezése a $A*** címen"},
/* it */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_IT, "Attiva la mappatura della RAM di 4K del PET8296 a $A***"},
/* ko */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_NL, "Activeer PET8296 4K RAM op adres $A***"},
/* ru */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_SV, "Aktivera PET8296 4K-RAM-mappning på $A***"},
/* tr */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_TR, "$A*** adresindeki PET8296 4K RAM eþleþtirmesini aktif et"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000,    N_("Disable PET8296 4K RAM mapping at $A***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_DA, "Deaktivér PET8296 4K-RAM-mapping på $A***"},
/* de */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_DE, "PET8296 4K RAM Zuordnung bei $A*** deaktivieren"},
/* fr */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_FR, "Désactiver l'extension PET8296 4K à $A***"},
/* hu */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_HU, "PET8296 4K RAM tiltása a $A*** címen"},
/* it */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_IT, "Disattiva la mappatura della RAM di 4K del PET8296 a $A***"},
/* ko */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_NL, "PET8296 4K RAM op adres $A*** uitschakelen"},
/* ru */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_SV, "Inaktivera PET8296 4K-RAM-mappning på $A***"},
/* tr */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_TR, "$A*** adresindeki PET8296 4K RAM eþleþtirmesini pasifleþtir"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_ENABLE_SUPERPET_IO,    N_("Enable SuperPET I/O")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SUPERPET_IO_DA, "Aktivér SuperPET-I/O"},
/* de */ {IDCLS_ENABLE_SUPERPET_IO_DE, "SuperPET I/O aktivieren"},
/* fr */ {IDCLS_ENABLE_SUPERPET_IO_FR, "Activer les E/S SuperPET"},
/* hu */ {IDCLS_ENABLE_SUPERPET_IO_HU, "SuperPET I/O engedélyezése"},
/* it */ {IDCLS_ENABLE_SUPERPET_IO_IT, "Attiva l'I/O del SuperPET"},
/* ko */ {IDCLS_ENABLE_SUPERPET_IO_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SUPERPET_IO_NL, "Activeer SuperPET I/O"},
/* ru */ {IDCLS_ENABLE_SUPERPET_IO_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SUPERPET_IO_SV, "Aktivera SuperPET-I/O"},
/* tr */ {IDCLS_ENABLE_SUPERPET_IO_TR, "SuperPET G/Ç'ý aktif et"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_DISABLE_SUPERPET_IO,    N_("Disable SuperPET I/O")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SUPERPET_IO_DA, "Deaktivér SuperPET-I/O"},
/* de */ {IDCLS_DISABLE_SUPERPET_IO_DE, "SuperPET I/O deaktivieren"},
/* fr */ {IDCLS_DISABLE_SUPERPET_IO_FR, "Désactiver les E/S SuperPET"},
/* hu */ {IDCLS_DISABLE_SUPERPET_IO_HU, "SuperPET I/O tiltása"},
/* it */ {IDCLS_DISABLE_SUPERPET_IO_IT, "Disattiva l'I/O del SuperPET"},
/* ko */ {IDCLS_DISABLE_SUPERPET_IO_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SUPERPET_IO_NL, "SuperPET I/O uitschakelen"},
/* ru */ {IDCLS_DISABLE_SUPERPET_IO_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SUPERPET_IO_SV, "Inaktivera SuperPET-I/O"},
/* tr */ {IDCLS_DISABLE_SUPERPET_IO_TR, "SuperPET G/Ç'ý pasifleþtir"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES,    N_("Enable ROM 1 Kernal patches")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_DA, "Aktivér ROM 1 kerneændringer"},
/* de */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_DE, "ROM 1 Kernal patches aktivieren"},
/* fr */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_FR, "Activer les patches ROM 1 Kernal"},
/* hu */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_HU, "ROM 1 Kernal foltozás engedélyezése"},
/* it */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_IT, "Attiva le patch del Kernal della ROM 1"},
/* ko */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_NL, "Activeer ROM 1 Kernalverbeteringen"},
/* ru */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_SV, "Aktivera ROM 1-Kernalpatchar"},
/* tr */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_TR, "ROM 1 Kernal yamalarýný aktif et"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES,    N_("Disable ROM 1 Kernal patches")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_DA, "Deaktivér ROM 1 kerneændringer"},
/* de */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_DE, "ROM 1 Kernal patches deaktivieren"},
/* fr */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_FR, "Désactiver les patches ROM 1 Kernal"},
/* hu */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_HU, "ROM 1 Kernal foltozás tiltása"},
/* it */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_IT, "Disattiva le patch del Kernal della ROM 1"},
/* ko */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_NL, "ROM 1 Kernalverbeteringen uitschakelen"},
/* ru */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_SV, "Inaktivera ROM 1-Kernalpatchar"},
/* tr */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_TR, "ROM 1 Kernal yamalarýný pasifleþtir"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET,    N_("Switch upper/lower case charset")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_DA, "Skift mellem store og små bogstaver"},
/* de */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_DE, "Wechsel Groß-/Kleinschreibung Zeichensatz"},
/* fr */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_FR, "Inverser le charset majuscule et minuscule"},
/* hu */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_HU, "Váltás nagy-/kisbetûs karakterkészletre"},
/* it */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_IT, "Scambia il set di caratteri maiuscolo/minuscolo"},
/* ko */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_NL, "Schakel tussen grote/kleine letters"},
/* ru */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_SV, "Växla små/stora bokstäver i teckengeneratorn"},
/* tr */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_TR, "Büyük/küçük harf karakter seti deðiþtir"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET,    N_("Do not switch upper/lower case charset")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_DA, "Skift ikke mellem store og små bogstaver"},
/* de */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_DE, "Kein Wechsel Groß-/Kleinschreibung Zeichensatz"},
/* fr */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_FR, "Ne pas inverser le charset majuscule et minuscule"},
/* hu */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_HU, "Ne váltson a nagy-/kisbetûs karakterkészletre"},
/* it */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_IT, "Non scambiare il set di caratteri maiuscolo/minuscolo"},
/* ko */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_NL, "Schakel niet tussen grote/kleine letters"},
/* ru */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_SV, "Växla inte små/stora bokstäver i teckengeneratorn"},
/* tr */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_TR, "Büyük/küçük harf karakter seti deðiþtirme"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_EOI_BLANKS_SCREEN,    N_("EOI blanks screen")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_EOI_BLANKS_SCREEN_DA, "EOI sletter skærmen"},
/* de */ {IDCLS_EOI_BLANKS_SCREEN_DE, "EOI löscht Bildschirm"},
/* fr */ {IDCLS_EOI_BLANKS_SCREEN_FR, "EOI vide l'écran"},
/* hu */ {IDCLS_EOI_BLANKS_SCREEN_HU, "EOI törli a képernyõt"},
/* it */ {IDCLS_EOI_BLANKS_SCREEN_IT, "EOI oscura lo schermo"},
/* ko */ {IDCLS_EOI_BLANKS_SCREEN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_EOI_BLANKS_SCREEN_NL, "EOI maakt het scherm leeg"},
/* ru */ {IDCLS_EOI_BLANKS_SCREEN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_EOI_BLANKS_SCREEN_SV, "EOI tömmer skärmen"},
/* tr */ {IDCLS_EOI_BLANKS_SCREEN_TR, "EOI ekraný boþaltýr"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN,    N_("EOI does not blank screen")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_DA, "EOI sletter ikke skærmen"},
/* de */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_DE, "EIO löscht Bildschirm nicht"},
/* fr */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_FR, "EOI ne vide pas l'écran"},
/* hu */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_HU, "EOI nem törli a képernyõt"},
/* it */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_IT, "EOI non oscura lo schermo"},
/* ko */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_NL, "EOI maakt het scherm niet leeg"},
/* ru */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_SV, "EOI tömmer inte skärmen"},
/* tr */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_TR, "EOI ekraný boþaltmaz"},
#endif

/* pet/petpia1.c */
/* en */ {IDCLS_ENABLE_USERPORT_DIAG_PIN,    N_("Enable userport diagnostic pin")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_DA, "Aktivér diagnostik på brugerporten"},
/* de */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_DE, "Userport Diagnose Pin aktivieren"},
/* fr */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_FR, "Activer la pin de diagnostique userport"},
/* hu */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_HU, "Userport diagnosztikai láb engedélyezése"},
/* it */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_IT, "Attiva pin diagnostico su userport"},
/* ko */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_NL, "Activeer userport diagnostic pin"},
/* ru */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_SV, "Aktivera diagnostik på användarporten"},
/* tr */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_TR, "Userport diyagnostik pinini aktif et"},
#endif

/* pet/petpia1.c */
/* en */ {IDCLS_DISABLE_USERPORT_DIAG_PIN,    N_("Disable userport diagnostic pin")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_DA, "Deaktivér diagnostik på brugerporten"},
/* de */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_DE, "Userport Diagnose Pin deaktivieren"},
/* fr */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_FR, "Désactiver la pin de diagnostique userport"},
/* hu */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_HU, "Userport diagnosztikai láb tiltása"},
/* it */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_IT, "Disattiva pin diagnostico su userport"},
/* ko */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_NL, "Userport diagnostic pin uitschakelen"},
/* ru */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_SV, "Inaktivera diagnostik på användarporten"},
/* tr */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_TR, "Userport diyagnostik pinini pasifleþtir"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME,    N_("Specify name of Function low ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_DA, "Angiv navn på image for lav funktions-ROM"},
/* de */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_DE, "Namen für Funktions ROM Datei (unterer Bereich) definieren"},
/* fr */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_FR, "Spécifier le nom de l'image basse ROM Fonction"},
/* hu */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_HU, "Adja meg az alsó Function ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_IT, "Specifica il nome immagine della Function ROM bassa"},
/* ko */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_NL, "Geef de naam van het Function low ROM bestand"},
/* ru */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_SV, "Ange namn på ROM-avbildning för lågt funktions-ROM"},
/* tr */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_TR, "Function low ROM imajýnýn ismini belirt"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME,    N_("Specify name of Function high ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_DA, "Angiv navn på image for høj funktions-ROM"},
/* de */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_DE, "Namen für Funktions ROM Datei (oberer Bereich) definieren"},
/* fr */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_FR, "Spécifier le nom de l'image haute ROM Fonction"},
/* hu */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_HU, "Adja meg a felsõ Function ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_IT, "Specifica il nome immagine della Function ROM alta"},
/* ko */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_NL, "Geef de naam van het Function high ROM bestand"},
/* ru */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_SV, "Ange namn på ROM-avbildning för högt funktions-ROM"},
/* tr */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_TR, "Function high ROM imajýnýn ismini belirt"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME,    N_("Specify name of Cartridge 1 low ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_DA, "Angiv navn på image for lav cartridge 1 ROM"},
/* de */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_DE, "Name für Erweiterungsmodul 1 ROM Datei (unterer Bereich) definieren"},
/* fr */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_FR, "Spécifier le nom de l'image basse ROM Cartouche 1"},
/* hu */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_HU, "Adja meg az alsó Cartridge 1 ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_IT, "Specifica il nome immagine della ROM Cartridge 1 bassa"},
/* ko */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_NL, "Geef de naam van het Cartridge 1 low ROM bestand"},
/* ru */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_SV, "Ange namn på ROM-avbildning för lågt insticksmodul 1-ROM"},
/* tr */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_TR, "Cartridge 1 low ROM imajýnýn ismini belirt"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME,    N_("Specify name of Cartridge 1 high ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_DA, "Angiv navn på image for høj cartridge 1 ROM"},
/* de */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_DE, "Name für Erweiterungsmodul 1 ROM Datei (oberer Bereich) definieren"},
/* fr */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_FR, "Spécifier le nom de l'image haute ROM Cartouche 1"},
/* hu */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_HU, "Adja meg a felsõ Cartridge 1 ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_IT, "Specifica il nome immagine della ROM Cartridge 1 alta"},
/* ko */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_NL, "Geef de naam van het Cartridge 1 high ROM bestand"},
/* ru */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_SV, "Ange namn på ROM-avbildning för högt insticksmodul 1-ROM"},
/* tr */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_TR, "Cartridge 1 high ROM imajýnýn ismini belirt"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME,    N_("Specify name of Cartridge 2 low ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_DA, "Angiv navn på image for lav cartridge 2 ROM"},
/* de */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_DE, "Name für Erweiterungsmodul 2 ROM Datei (unterer Bereich) definieren"},
/* fr */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_FR, "Spécifier le nom de l'image basse ROM Cartouche 2"},
/* hu */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_HU, "Adja meg az alsó Cartridge 2 ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_IT, "Specifica il nome immagine della ROM Cartridge 2 bassa"},
/* ko */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_NL, "Geef de naam van het Cartridge 2 low ROM bestand"},
/* ru */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_SV, "Ange namn på ROM-avbildning för lågt insticksmodul 2-ROM"},
/* tr */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_TR, "Cartridge 2 low ROM imajýnýn ismini belirt"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME,    N_("Specify name of Cartridge 2 high ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_DA, "Angiv navn på image for høj cartridge 1 ROM"},
/* de */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_DE, "Name für Erweiterungsmodul 2 ROM Datei (oberer Bereich) definieren"},
/* fr */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_FR, "Spécifier le nom de l'image haute ROM Cartouche 2"},
/* hu */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_HU, "Adja meg a felsõ Cartridge 2 ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_IT, "Specifica il nome immagine della ROM Cartridge 2 alta"},
/* ko */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_NL, "Geef de naam van het Cartridge 2 high ROM bestand"},
/* ru */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_SV, "Ange namn på ROM-avbildning för högt insticksmodul 2-ROM"},
/* tr */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_TR, "Cartridge 2 high ROM imajýnýn ismini belirt"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_RAM_INSTALLED,    N_("Specify size of RAM installed in kb (16/32/64)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RAM_INSTALLED_DA, "Angiv størrelse på installeret RAM i kB (16/32/64)"},
/* de */ {IDCLS_SPECIFY_RAM_INSTALLED_DE, "Größe des emulierten RAM Speichers in kb (16/32/64) spezifizieren"},
/* fr */ {IDCLS_SPECIFY_RAM_INSTALLED_FR, "Spécifier la taille du RAM installé (16/32/64)"},
/* hu */ {IDCLS_SPECIFY_RAM_INSTALLED_HU, "Adja meg a telepített RAM méretét kb-ban (16/32/64)"},
/* it */ {IDCLS_SPECIFY_RAM_INSTALLED_IT, "Specifica la dimensione della RAM installata in kb (16/32/64)"},
/* ko */ {IDCLS_SPECIFY_RAM_INSTALLED_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RAM_INSTALLED_NL, "Geef de hoeveelheid RAM in kb (16/32/64)"},
/* ru */ {IDCLS_SPECIFY_RAM_INSTALLED_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RAM_INSTALLED_SV, "Ange storlek på installerat RAM i kb (16/32/64)"},
/* tr */ {IDCLS_SPECIFY_RAM_INSTALLED_TR, "Kurulmuþ olan RAM boyutunu kb cinsinden belirt (16/32/64)"},
#endif

/* plus4/ted-cmdline-options.c, vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_SATURATION,    N_("Set saturation of internal calculated palette [1000]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_SATURATION_DA, "Indstil mætning af internt beregnet palette [1000]"},
/* de */ {IDCLS_SET_SATURATION_DE, "Sättigung für intern berechneten Palette setzen [1000]"},
/* fr */ {IDCLS_SET_SATURATION_FR, "Régler la saturation de la palette interne calculée [1000]"},
/* hu */ {IDCLS_SET_SATURATION_HU, "A számolt paletta telítettsége [1000]"},
/* it */ {IDCLS_SET_SATURATION_IT, "Imposta la saturazione della palette calcolata internamente [1000]"},
/* ko */ {IDCLS_SET_SATURATION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_SATURATION_NL, "Zet de verzadiging van het intern berekend kleurenpalet [1000]"},
/* ru */ {IDCLS_SET_SATURATION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_SATURATION_SV, "Ställ in mättnad på internt beräknad palett [1000]"},
/* tr */ {IDCLS_SET_SATURATION_TR, "Dahili hesaplanmýþ paletin doygunluðunu ayarlayýn [1000]"},
#endif

/* plus4/ted-cmdline-options.c, vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_CONTRAST,    N_("Set contrast of internal calculated palette [1000]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_CONTRAST_DA, "Indstil kontrast for internt beregnet palette [1000]"},
/* de */ {IDCLS_SET_CONTRAST_DE, "Kontrast für intern berechnete Palette setzen [1000]"},
/* fr */ {IDCLS_SET_CONTRAST_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_CONTRAST_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_CONTRAST_IT, "Imposta il constrasto della palette calcolata internamente [1000]"},
/* ko */ {IDCLS_SET_CONTRAST_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_CONTRAST_NL, "Zet het contrast van het intern berekend kleurenpalet [1000]"},
/* ru */ {IDCLS_SET_CONTRAST_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_CONTRAST_SV, "Ställ in kontrast på internt beräknad palett [1000]"},
/* tr */ {IDCLS_SET_CONTRAST_TR, "Dahili hesaplanmýþ paletin karþýtlýðýný ayarlayýn [1000]"},
#endif

/* plus4/ted-cmdline-options.c, vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_BRIGHTNESS,    N_("Set brightness of internal calculated palette [1000]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_BRIGHTNESS_DA, "Indstil lysstyrke for internt beregnet palette [1000]"},
/* de */ {IDCLS_SET_BRIGHTNESS_DE, "Helligkeit für intern berechnete Palette setzen [1000]"},
/* fr */ {IDCLS_SET_BRIGHTNESS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_BRIGHTNESS_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_BRIGHTNESS_IT, "Imposta la luminanza della palette calcolata internamente [1000]"},
/* ko */ {IDCLS_SET_BRIGHTNESS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_BRIGHTNESS_NL, "Zet de helderheid van het intern berekend kleurenpalet [1000]"},
/* ru */ {IDCLS_SET_BRIGHTNESS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_BRIGHTNESS_SV, "Ställ in ljusstyrka på internt beräknad palett [1000]"},
/* tr */ {IDCLS_SET_BRIGHTNESS_TR, "Dahili hesaplanmýþ paletin parlaklýðýný ayarlayýn [1000]"},
#endif

/* plus4/ted-cmdline-options.c`, vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_GAMMA,    N_("Set gamma of internal calculated palette [2200]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_GAMMA_DA, "Indstil gamma for internt beregnet palette [2200]"},
/* de */ {IDCLS_SET_GAMMA_DE, "Gamma für intern berechnete Palette setzen [2200]"},
/* fr */ {IDCLS_SET_GAMMA_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_GAMMA_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_GAMMA_IT, "Imposta la gamma della palette calcolata internamente [2200]"},
/* ko */ {IDCLS_SET_GAMMA_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_GAMMA_NL, "Zet de gamma van het intern berekend kleurenpalet [2200]"},
/* ru */ {IDCLS_SET_GAMMA_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_GAMMA_SV, "Ställ in gamma på internt beräknad palett [2200]"},
/* tr */ {IDCLS_SET_GAMMA_TR, "Dahili hesaplanmýþ paletin gamasýný ayarlayýn [2200]"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_TINT,    N_("Set tint of internal calculated palette [1000]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_TINT_DA, "Indstil farvetone for internt beregnet palette [1000]"},
/* de */ {IDCLS_SET_TINT_DE, "Farbton für intern berechneten Palette setzen [1000]"},
/* fr */ {IDCLS_SET_TINT_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_TINT_HU, "A számolt, belsõ paletta telítettsége [1000]"},
/* it */ {IDCLS_SET_TINT_IT, "Imposta la sfumatura della palette calcolata internamente [1000]"},
/* ko */ {IDCLS_SET_TINT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_TINT_NL, "Zet de tint van het intern berekend kleuren palette [1000]"},
/* ru */ {IDCLS_SET_TINT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_TINT_SV, "Ställ in ton på internt beräknad palett [1000]"},
/* tr */ {IDCLS_SET_TINT_TR, "Dahili hesaplanmýþ paletin tonunu ayarlayýn [1000]"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_ODDLINES_PHASE,    N_("Set phase for color carrier in odd lines [1250]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_ODDLINES_PHASE_DA, "Vælg fase for farve-bærebølge på ulige scanlinjer [1250]"},
/* de */ {IDCLS_SET_ODDLINES_PHASE_DE, "Phase für Farbträger in ungeraden Zeilen setzen [1250]"},
/* fr */ {IDCLS_SET_ODDLINES_PHASE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_ODDLINES_PHASE_HU, "Szín vivõ fázisa a páratlan sorokban [1250]"},
/* it */ {IDCLS_SET_ODDLINES_PHASE_IT, "Imposta la fase per la portante colore nelle linee dispari [1250]"},
/* ko */ {IDCLS_SET_ODDLINES_PHASE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_ODDLINES_PHASE_NL, "Zet de fase van de kleuren drager in oneven lijnen [1250]"},
/* ru */ {IDCLS_SET_ODDLINES_PHASE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_ODDLINES_PHASE_SV, "Välj fas för färgbärarvåg på udda rader [1250]"},
/* tr */ {IDCLS_SET_ODDLINES_PHASE_TR, "Tek satýrlardaki renk taþýyýcýlarý için fazý ayarlayýn [1250]"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_ODDLINES_OFFSET,    N_("Set phase offset for color carrier in odd lines [750]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_ODDLINES_OFFSET_DA, "Vælg fase-offset for farve-bærebølge på ulige scanlinjer [750]"},
/* de */ {IDCLS_SET_ODDLINES_OFFSET_DE, "Phasenoffset für Farbträger in ungeraden Zeilen setzen [750]"},
/* fr */ {IDCLS_SET_ODDLINES_OFFSET_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_ODDLINES_OFFSET_HU, "Szín vivõ fázis offszet a páratlan sorokban [750]"},
/* it */ {IDCLS_SET_ODDLINES_OFFSET_IT, "Imposta l'offset della fase per la portate colore nelle linee dispari [750]"},
/* ko */ {IDCLS_SET_ODDLINES_OFFSET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_ODDLINES_OFFSET_NL, "Zet de fase compensatie van de kleuren drager in oneven lijnen [750]"},
/* ru */ {IDCLS_SET_ODDLINES_OFFSET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_ODDLINES_OFFSET_SV, "Välj fasutjämning för färgbärarvåg på udda rader [1250]"},
/* tr */ {IDCLS_SET_ODDLINES_OFFSET_TR, "Tek satýrlardaki renk taþýyýcýlarý için faz ofsetini ayarlayýn [750]"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_BLUR,    N_("Amount of horizontal blur for the CRT emulation. [500]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_BLUR_DA, "Mængden af horizontal udtværing for CRT emulering. [500]"},
/* de */ {IDCLS_SET_BLUR_DE, "Wert für horizontale Unschärfe für CRT Emulation. [500]"},
/* fr */ {IDCLS_SET_BLUR_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_BLUR_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_BLUR_IT, "Valore della sfuocatura orizzontale per l'emulazione CRT [500]"},
/* ko */ {IDCLS_SET_BLUR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_BLUR_NL, "Wazigheid hoeveelheid voor de CRT emulatie. [500]"},
/* ru */ {IDCLS_SET_BLUR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_BLUR_SV, "Mängd horisontell oskärpa för CRT-emulering. [500]"},
/* tr */ {IDCLS_SET_BLUR_TR, "CRT emülasyonu için yatay bulanýklýk miktarý. [500]"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_SCANLINE_SHADE,    N_("Amount of scan line shading for the CRT emulation [667]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_SCANLINE_SHADE_DA, "Mængden af scanlinjeskygge for CRT emulering [667]"},
/* de */ {IDCLS_SET_SCANLINE_SHADE_DE, "Wert für Scanline Schatten für CRT Emulation [667]"},
/* fr */ {IDCLS_SET_SCANLINE_SHADE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_SCANLINE_SHADE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_SCANLINE_SHADE_IT, "Valore dell'ombreggiatura della scan line per l'emulazione CRT [667]"},
/* ko */ {IDCLS_SET_SCANLINE_SHADE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_SCANLINE_SHADE_NL, "Hoeveelheid van de scan lijn schaduw voor de CRT emulatie [667]"},
/* ru */ {IDCLS_SET_SCANLINE_SHADE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_SCANLINE_SHADE_SV, "Mängd skannlinjeskuggning i CRT-emuleringen [667]"},
/* tr */ {IDCLS_SET_SCANLINE_SHADE_TR, "CRT emülasyonu için tarama satýrý nüans miktarý [667]"},
#endif

/* viciisc/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_VICII_MODEL,    N_("Set VIC-II model (6569/6569r1/8565/6567/8562/6567r56a)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_VICII_MODEL_DA, "Vælg VIC-II model (6569/6569r1/8565/6567/8562/6567r56a)"},
/* de */ {IDCLS_SET_VICII_MODEL_DE, "Wähle VIC-II Modell (6569/6569r1/8565/6567/8562/6567r56a)"},
/* fr */ {IDCLS_SET_VICII_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_VICII_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_VICII_MODEL_IT, "Imposta modello VIC-II (6569/6569r1/8565/6567/8562/6567r56a)"},
/* ko */ {IDCLS_SET_VICII_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_VICII_MODEL_NL, "Zet VIC-II model (6569/6569r1/8565/6567/8562/6567r56a)"},
/* ru */ {IDCLS_SET_VICII_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_VICII_MODEL_SV, "Välj VIC-II-modell (6569/6569r1/8565/6567/8562/6567r56a)"},
/* tr */ {IDCLS_SET_VICII_MODEL_TR, "VIC-II modelini ayarla (6569/6569r1/8565/6567/8562/6567r56a)"},
#endif

/* printerdrv/driver-select.c */
/* en */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME,    N_("Specify name of printer driver for device #4")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_DA, "Angiv navn på printer-driver for enhed #4"},
/* de */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_DE, "Name für Druckertreiber Gerät #4 definieren"},
/* fr */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_FR, "Spécifier le nom du pilote imprimante pour le périphérique #4"},
/* hu */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_HU, "Adja meg a #4-es nyomtatómeghajtó nevét"},
/* it */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_IT, "Specifica il nome del driver di stampa per la periferica #4"},
/* ko */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_NL, "Geef de naam van het stuurprogramma voor apparaat #4"},
/* ru */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_SV, "Ange namn på skrivardrivrutin för enhet 4"},
/* tr */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_TR, "Aygýt #4 için yazýcý sürücüsü ismini belirt"},
#endif

/* printerdrv/driver-select.c */
/* en */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME,    N_("Specify name of printer driver for device #5")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_DA, "Angiv navn på printer-driver for enhed #5"},
/* de */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_DE, "Name für Druckertreiber Gerät #5 definieren"},
/* fr */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_FR, "Spécifier le nom du pilote imprimante pour le périphérique #5"},
/* hu */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_HU, "Adja meg a #5-ös nyomtatómeghajtó nevét"},
/* it */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_IT, "Specifica il nome del driver di stampa per la periferica #5"},
/* ko */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_NL, "Geef de naam van het stuurprogramma voor apparaat #5"},
/* ru */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_SV, "Ange namn på skrivardrivrutin för enhet 5"},
/* tr */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_TR, "Aygýt #5 için yazýcý sürücüsü ismini belirt"},
#endif

/* printerdrv/driver-select.c */
/* en */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME,    N_("Specify name of printer driver for the userport printer")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_DA, "Angiv navn på printerdriver for brugerport-printer"},
/* de */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_DE, "Name für Userport Druckertreiber definieren"},
/* fr */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_FR, "Spécifier le nom du pilote imprimante pour l'imprimante userport"},
/* hu */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_HU, "Adja meg a userport nyomtatómeghajtó nevét"},
/* it */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_IT, "Specifica il nome del driver di stampa per la stampante su userport"},
/* ko */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_NL, "Geef de naam van het stuurprogramma voor de userport printer"},
/* ru */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_SV, "Ange namn på skrivardrivrutin för användarporten"},
/* tr */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_TR, "Userport yazýcýsý için yazýcý sürücüsü ismini belirt"},
#endif

/* printerdrv/interface-serial.c */
/* en */ {IDCLS_SET_DEVICE_TYPE_4,    N_("Set device type for device #4 (0: NONE, 1: FS, 2: REAL)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DEVICE_TYPE_4_DA, "Sæt enhedstype for enhed #4 (0: INGEN, 1: FS, 2: ÆGTE)"},
/* de */ {IDCLS_SET_DEVICE_TYPE_4_DE, "Geräte Typ für Gerät #4 (0: NONE, 1: FS, 2: REAL) setzen"},
/* fr */ {IDCLS_SET_DEVICE_TYPE_4_FR, "Spécifier le type de périphérique pour #4 (0: AUCUN, 1: SF, 2: RÉEL)"},
/* hu */ {IDCLS_SET_DEVICE_TYPE_4_HU, "Adja meg a #4-es eszköz típusát (0:Nincs, 1: Fájlrendszer, 2: Valódi)"},
/* it */ {IDCLS_SET_DEVICE_TYPE_4_IT, "Specifica il tipo di periferica #4 (0 NESSUNA, 1 FS, 2 REALE)"},
/* ko */ {IDCLS_SET_DEVICE_TYPE_4_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DEVICE_TYPE_4_NL, "Zet apparaat soort voor apparaat #4 (0: GEEN, 1: FS, 2: ECHT)"},
/* ru */ {IDCLS_SET_DEVICE_TYPE_4_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DEVICE_TYPE_4_SV, "Ange enhetstyp för enhet 4 (0: INGEN, 1: FS, 2: ÄKTA)"},
/* tr */ {IDCLS_SET_DEVICE_TYPE_4_TR, "Aygýt #4 için aygýt tipini ayarlayýn (0: YOK, 1: FS, 2: GERÇEK)"},
#endif

/* printerdrv/interface-serial.c */
/* en */ {IDCLS_SET_DEVICE_TYPE_5,    N_("Set device type for device #5 (0: NONE, 1: FS, 2: REAL)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DEVICE_TYPE_5_DA, "Sæt enhedstype for enhed #5 (0: INGEN, 1: FS, 2: ÆGTE)"},
/* de */ {IDCLS_SET_DEVICE_TYPE_5_DE, "Geräte Typ für Gerät #5 (0: NONE, 1: FS, 2: REAL) setzen"},
/* fr */ {IDCLS_SET_DEVICE_TYPE_5_FR, "Spécifier le type de périphérique pour #5 (0: AUCUN, 1: SF, 2: RÉEL)"},
/* hu */ {IDCLS_SET_DEVICE_TYPE_5_HU, "Adja meg a #5-ös eszköz típusát (0:Nincs, 1: Fájlrendszer, 2: Valódi)"},
/* it */ {IDCLS_SET_DEVICE_TYPE_5_IT, "Specifica il tipo di periferica #5 (0 NESSUNA, 1 FS, 2 REALE)"},
/* ko */ {IDCLS_SET_DEVICE_TYPE_5_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DEVICE_TYPE_5_NL, "Zet apparaat soort voor apparaat #5 (0: GEEN, 1: FS, 2: ECHT)"},
/* ru */ {IDCLS_SET_DEVICE_TYPE_5_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DEVICE_TYPE_5_SV, "Ange enhetstyp för enhet 5 (0: INGEN, 1: FS, 2: ÄKTA)"},
/* tr */ {IDCLS_SET_DEVICE_TYPE_5_TR, "Aygýt #5 için aygýt tipini ayarlayýn (0: YOK, 1: FS, 2: GERÇEK)"},
#endif

/* printerdrv/interface-userport.c */
/* en */ {IDCLS_ENABLE_USERPORT_PRINTER,    N_("Enable the userport printer emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_USERPORT_PRINTER_DA, "Aktivér emulering af printer på brugerporten"},
/* de */ {IDCLS_ENABLE_USERPORT_PRINTER_DE, "Userport Drucker Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_USERPORT_PRINTER_FR, "Acviver l'émulation de l'imprimante userport"},
/* hu */ {IDCLS_ENABLE_USERPORT_PRINTER_HU, "Userport nyomtató emulációjának engedélyezése"},
/* it */ {IDCLS_ENABLE_USERPORT_PRINTER_IT, "Attiva l'emulazione della stampante su userport"},
/* ko */ {IDCLS_ENABLE_USERPORT_PRINTER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_USERPORT_PRINTER_NL, "Activeer userport printeremulatie"},
/* ru */ {IDCLS_ENABLE_USERPORT_PRINTER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_USERPORT_PRINTER_SV, "Aktivera emulering av skrivare på användarporten"},
/* tr */ {IDCLS_ENABLE_USERPORT_PRINTER_TR, "Userport yazýcý emülasyonunu aktif et"},
#endif

/* printerdrv/interface-userport.c */
/* en */ {IDCLS_DISABLE_USERPORT_PRINTER,    N_("Disable the userport printer emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_USERPORT_PRINTER_DA, "Deaktivér emulering af printer på brugerporten"},
/* de */ {IDCLS_DISABLE_USERPORT_PRINTER_DE, "Userport Drucker Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_USERPORT_PRINTER_FR, "Désactiver l'émulation de l'imprimante userport"},
/* hu */ {IDCLS_DISABLE_USERPORT_PRINTER_HU, "Userport nyomtató emulációjának tiltása"},
/* it */ {IDCLS_DISABLE_USERPORT_PRINTER_IT, "Disattiva l'emulazione della stampante su userport"},
/* ko */ {IDCLS_DISABLE_USERPORT_PRINTER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_USERPORT_PRINTER_NL, "De userport printeremulatie uitschakelen"},
/* ru */ {IDCLS_DISABLE_USERPORT_PRINTER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_USERPORT_PRINTER_SV, "Inaktivera emulering av skrivare på användarporten"},
/* tr */ {IDCLS_DISABLE_USERPORT_PRINTER_TR, "Userport yazýcý emülasyonunu pasifleþtir"},
#endif

/* printerdrv/output-select.c */
/* en */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME,    N_("Specify name of output device for device #4")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_DA, "Angiv navn på uddataenhed for enhed #4"},
/* de */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_DE, "Name für Druckerausgabe Datei Gerät #4 definieren"},
/* fr */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_FR, "Spécifiez le nom du périphérique de sortie pour le périphérique #4"},
/* hu */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_HU, "Adja meg a kimeneti eszköz nevét a #4-es egységhez"},
/* it */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_IT, "Specifica il nome del dispositivo di output per la periferica #4"},
/* ko */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_NL, "Geef de naam van het uitvoer apparaat voor apparaat #4"},
/* ru */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_SV, "Ange namn på utskriftsenhet för enhet 4"},
/* tr */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_TR, "Aygýt #4 için çýkýþ aygýtý ismini belirt"},
#endif

/* printerdrv/output-select.c */
/* en */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME,    N_("Specify name of output device for device #5")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_DA, "Angiv navn på uddataenhed for enhed #5"},
/* de */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_DE, "Name für Druckerausgabe Datei Gerät #5 definieren"},
/* fr */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_FR, "Spécifiez le nom du périphérique de sortie pour le périphérique #5"},
/* hu */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_HU, "Adja meg a kimeneti eszköz nevét a #5-ös egységhez"},
/* it */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_IT, "Specifica il nome del dispositivo di output per la periferica #5"},
/* ko */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_NL, "Geef de naam van het uitvoer apparaat voor apparaat #5"},
/* ru */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_SV, "Ange namn på utskriftsenhet för enhet 5"},
/* tr */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_TR, "Aygýt #5 için çýkýþ aygýtý ismini belirt"},
#endif

/* printerdrv/output-select.c */
/* en */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME,    N_("Specify name of output device for the userport printer")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_DA, "Angiv navn på uddataenhed for brugerports-printer"},
/* de */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_DE, "Name für Druckerausgabe Datei Userport definieren"},
/* fr */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_FR, "Spécifiez le nom du périphérique de sortie pour l'imprimante userport"},
/* hu */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_HU, "Adja meg a kimeneti eszköz nevét a userport nyomtatóhoz"},
/* it */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_IT, "Specifica il nome del dispositivo di output per la stampante su userport"},
/* ko */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_NL, "Geef de naam van het uitvoer apparaat voor de userport printer"},
/* ru */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_SV, "Ange namn på utskriftsenhet för användarporten"},
/* tr */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_TR, "Userport yazýcýsý için çýkýþ aygýtý ismini belirt"},
#endif

/* printerdrv/output-text.c */
/* en */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME,    N_("Specify name of printer text device or dump file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_DA, "Angiv navn på printer-tekst-enhed eller dump-fil"},
/* de */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_DE, "Name für Druckerausgabe Textgerät oder Dump Datei definieren"},
/* fr */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_FR, "Spécifier le nom de l'imprimante texte ou \"dump file\""},
/* hu */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_HU, "Adja meg a szövegnyomtató eszköz nevét, vagy a kimeneti fájlt"},
/* it */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_IT, "Specifica il nome del dispositivo testuale di stampa o salva su file"},
/* ko */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_NL, "Geef de naam van het text apparaat of het dumpbestand"},
/* ru */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_SV, "Ange namn på textenhet för utskrift eller dumpfil"},
/* tr */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_TR, "Metin aygýtý yazýcýsý ya da döküm dosyasýnýn ismini belirt"},
#endif

/* printerdrv/output-text.c */
/* en */ {IDCLS_SPECIFY_TEXT_DEVICE_4,    N_("Specify printer text output device for IEC printer #4")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_TEXT_DEVICE_4_DA, "Angiv printer tekst-uddata enhed for IEC-printer #4"},
/* de */ {IDCLS_SPECIFY_TEXT_DEVICE_4_DE, "IEC Drucker #4 Gerät für Textausgabe definieren"},
/* fr */ {IDCLS_SPECIFY_TEXT_DEVICE_4_FR, "Spécifier le périphérique de sortie text pour l'imprimante IEC #4"},
/* hu */ {IDCLS_SPECIFY_TEXT_DEVICE_4_HU, "Adja meg a szövegnyomtató eszközt a #4-es IEC nyomtatóhoz"},
/* it */ {IDCLS_SPECIFY_TEXT_DEVICE_4_IT, "Specifica il nome del dispositivo di output testuale di stampa per la stampante IEC #4"},
/* ko */ {IDCLS_SPECIFY_TEXT_DEVICE_4_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_TEXT_DEVICE_4_NL, "Geef het text uitvoer apparaat voor IEC printer #4"},
/* ru */ {IDCLS_SPECIFY_TEXT_DEVICE_4_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_TEXT_DEVICE_4_SV, "Ange skrivartextutenhet för IEC-skrivare 4"},
/* tr */ {IDCLS_SPECIFY_TEXT_DEVICE_4_TR, "IEC yazýcýsý #4 için metin çýktý aygýtý yazýcýsý belirt"},
#endif

/* printerdrv/output-text.c */
/* en */ {IDCLS_SPECIFY_TEXT_DEVICE_5,    N_("Specify printer text output device for IEC printer #5")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_TEXT_DEVICE_5_DA, "Angiv printer tekst-uddata enhed for IEC-printer #5"},
/* de */ {IDCLS_SPECIFY_TEXT_DEVICE_5_DE, "IEC Drucker #5 Gerät für Textausgabe definieren"},
/* fr */ {IDCLS_SPECIFY_TEXT_DEVICE_5_FR, "Spécifier le périphérique de sortie text pour l'imprimante IEC #5"},
/* hu */ {IDCLS_SPECIFY_TEXT_DEVICE_5_HU, "Adja meg a szövegnyomtató eszközt a #5-es IEC nyomtatóhoz"},
/* it */ {IDCLS_SPECIFY_TEXT_DEVICE_5_IT, "Specifica il nome del dispositivo di output testuale di stampa per la stampante IEC #5"},
/* ko */ {IDCLS_SPECIFY_TEXT_DEVICE_5_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_TEXT_DEVICE_5_NL, "Geef het text uitvoer apparaat voor IEC printer #5"},
/* ru */ {IDCLS_SPECIFY_TEXT_DEVICE_5_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_TEXT_DEVICE_5_SV, "Ange skrivartextutenhet för IEC-skrivare 5"},
/* tr */ {IDCLS_SPECIFY_TEXT_DEVICE_5_TR, "IEC yazýcýsý #5 için metin çýktý aygýtý yazýcýsý belirt"},
#endif

/* printerdrv/output-text.c */
/* en */ {IDCLS_SPECIFY_TEXT_USERPORT,    N_("Specify printer text output device for userport printer")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_TEXT_USERPORT_DA, "Angiv printer tekst-uddata enhed for brugerports-printer"},
/* de */ {IDCLS_SPECIFY_TEXT_USERPORT_DE, "IEC Userport Drucker Gerät für Textausgabe definieren"},
/* fr */ {IDCLS_SPECIFY_TEXT_USERPORT_FR, "Spécifier le périphérique de sortie text pour l'imprimante userport"},
/* hu */ {IDCLS_SPECIFY_TEXT_USERPORT_HU, "Adja meg a szövegnyomtató eszközt a userport nyomtatóhoz"},
/* it */ {IDCLS_SPECIFY_TEXT_USERPORT_IT, "Specifica il nome del dispositivo di output testuale di stampa per la stampante su userport"},
/* ko */ {IDCLS_SPECIFY_TEXT_USERPORT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_TEXT_USERPORT_NL, "Geef het text uitvoer apparaat voor de userport printer"},
/* ru */ {IDCLS_SPECIFY_TEXT_USERPORT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_TEXT_USERPORT_SV, "Ange skrivartextutenhet för användarportsskrivare"},
/* tr */ {IDCLS_SPECIFY_TEXT_USERPORT_TR, "Userport yazýcýsý için metin çýktý aygýtý yazýcýsý belirt"},
#endif

/* raster/raster-cmdline-options.c */
/* en */ {IDCLS_ENABLE_VIDEO_CACHE,    N_("Enable the video cache")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_VIDEO_CACHE_DA, "Aktivér videocache"},
/* de */ {IDCLS_ENABLE_VIDEO_CACHE_DE, "Video Cache aktivieren"},
/* fr */ {IDCLS_ENABLE_VIDEO_CACHE_FR, "Activer le cache vidéo"},
/* hu */ {IDCLS_ENABLE_VIDEO_CACHE_HU, "Videó gyorsítótár engedélyezése"},
/* it */ {IDCLS_ENABLE_VIDEO_CACHE_IT, "Attiva la cache video"},
/* ko */ {IDCLS_ENABLE_VIDEO_CACHE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_VIDEO_CACHE_NL, "Activeer de videocache"},
/* ru */ {IDCLS_ENABLE_VIDEO_CACHE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_VIDEO_CACHE_SV, "Aktivera videocache"},
/* tr */ {IDCLS_ENABLE_VIDEO_CACHE_TR, "Görüntü önbelleðini aktif et"},
#endif

/* raster/raster-cmdline-options.c */
/* en */ {IDCLS_DISABLE_VIDEO_CACHE,    N_("Disable the video cache")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_VIDEO_CACHE_DA, "Deaktivér videocache"},
/* de */ {IDCLS_DISABLE_VIDEO_CACHE_DE, "Video Cache deaktivieren"},
/* fr */ {IDCLS_DISABLE_VIDEO_CACHE_FR, "Désactiver le cache vidéo"},
/* hu */ {IDCLS_DISABLE_VIDEO_CACHE_HU, "Videó gyorsítótár tiltása"},
/* it */ {IDCLS_DISABLE_VIDEO_CACHE_IT, "Disattiva la cache video"},
/* ko */ {IDCLS_DISABLE_VIDEO_CACHE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_VIDEO_CACHE_NL, "De videocache uitschakelen"},
/* ru */ {IDCLS_DISABLE_VIDEO_CACHE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_VIDEO_CACHE_SV, "Inaktivera videocache"},
/* tr */ {IDCLS_DISABLE_VIDEO_CACHE_TR, "Görüntü önbelleðini pasifleþtir"},
#endif

#ifdef HAVE_RS232
/* rs232drv/rs232drv.c */
/* en */ {IDCLS_SPECIFY_RS232_1_NAME,    N_("Specify name of first RS232 device")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RS232_1_NAME_DA, "Angiv navn på første RS232-enhed"},
/* de */ {IDCLS_SPECIFY_RS232_1_NAME_DE, "Name für erstes RS232 Gerät definieren"},
/* fr */ {IDCLS_SPECIFY_RS232_1_NAME_FR, "Spécifier le nom du 1er périphérique RS232"},
/* hu */ {IDCLS_SPECIFY_RS232_1_NAME_HU, "Adja meg az elsõ RS232-es eszköz nevét"},
/* it */ {IDCLS_SPECIFY_RS232_1_NAME_IT, "Specifica il nome della prima RS232"},
/* ko */ {IDCLS_SPECIFY_RS232_1_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RS232_1_NAME_NL, "Geef de naam van het eerste RS232 apparaat"},
/* ru */ {IDCLS_SPECIFY_RS232_1_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RS232_1_NAME_SV, "Ange namn på första RS232-enheten"},
/* tr */ {IDCLS_SPECIFY_RS232_1_NAME_TR, "Ýlk RS232 aygýtýnýn ismini belirt"},
#endif

/* rs232drv/rs232drv.c */
/* en */ {IDCLS_SPECIFY_RS232_2_NAME,    N_("Specify name of second RS232 device")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RS232_2_NAME_DA, "Angiv navn på anden RS232-enhed"},
/* de */ {IDCLS_SPECIFY_RS232_2_NAME_DE, "Name für zweites RS232 Gerät definieren"},
/* fr */ {IDCLS_SPECIFY_RS232_2_NAME_FR, "Spécifier le nom du 2e périphérique RS232"},
/* hu */ {IDCLS_SPECIFY_RS232_2_NAME_HU, "Adja meg a második RS232-es eszköz nevét"},
/* it */ {IDCLS_SPECIFY_RS232_2_NAME_IT, "Specifica il nome della seconda RS232"},
/* ko */ {IDCLS_SPECIFY_RS232_2_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RS232_2_NAME_NL, "Geef de naam van het tweede RS232 apparaat"},
/* ru */ {IDCLS_SPECIFY_RS232_2_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RS232_2_NAME_SV, "Ange namn på andra RS232-enheten"},
/* tr */ {IDCLS_SPECIFY_RS232_2_NAME_TR, "Ýkinci RS232 aygýtýnýn ismini belirt"},
#endif

/* rs232drv/rs232drv.c */
/* en */ {IDCLS_SPECIFY_RS232_3_NAME,    N_("Specify name of third RS232 device")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RS232_3_NAME_DA, "Angiv navn på tredje RS232-enhed"},
/* de */ {IDCLS_SPECIFY_RS232_3_NAME_DE, "Name für drittes RS232 Gerät definieren"},
/* fr */ {IDCLS_SPECIFY_RS232_3_NAME_FR, "Spécifier le nom du 3e périphérique RS232"},
/* hu */ {IDCLS_SPECIFY_RS232_3_NAME_HU, "Adja meg a harmadik RS232-es eszköz nevét"},
/* it */ {IDCLS_SPECIFY_RS232_3_NAME_IT, "Specifica il nome della terza RS232"},
/* ko */ {IDCLS_SPECIFY_RS232_3_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RS232_3_NAME_NL, "Geef de naam van het derde RS232 apparaat"},
/* ru */ {IDCLS_SPECIFY_RS232_3_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RS232_3_NAME_SV, "Ange namn på tredje RS232-enheten"},
/* tr */ {IDCLS_SPECIFY_RS232_3_NAME_TR, "Üçüncü RS232 aygýtýnýn ismini belirt"},
#endif

/* rs232drv/rs232drv.c */
/* en */ {IDCLS_SPECIFY_RS232_4_NAME,    N_("Specify name of fourth RS232 device")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RS232_4_NAME_DA, "Angiv navn på fjerde RS232-enhed"},
/* de */ {IDCLS_SPECIFY_RS232_4_NAME_DE, "Name für viertes RS232 Gerät definieren"},
/* fr */ {IDCLS_SPECIFY_RS232_4_NAME_FR, "Spécifier le nom du 4e périphérique RS232"},
/* hu */ {IDCLS_SPECIFY_RS232_4_NAME_HU, "Adja meg a negyedik RS232-es eszköz nevét"},
/* it */ {IDCLS_SPECIFY_RS232_4_NAME_IT, "Specifica il nome della quarta RS232"},
/* ko */ {IDCLS_SPECIFY_RS232_4_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RS232_4_NAME_NL, "Geef de naam van het vierde RS232 apparaat"},
/* ru */ {IDCLS_SPECIFY_RS232_4_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RS232_4_NAME_SV, "Ange namn på fjärde RS232-enheten"},
/* tr */ {IDCLS_SPECIFY_RS232_4_NAME_TR, "Dördüncü RS232 aygýtýnýn ismini belirt"},
#endif
#endif

/* rs232drv/rsuser.c */
/* en */ {IDCLS_ENABLE_RS232_USERPORT,    N_("Enable RS232 userport emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RS232_USERPORT_DA, "Aktivér RS232-emulering på brugerporten"},
/* de */ {IDCLS_ENABLE_RS232_USERPORT_DE, "RS232 Userport Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_RS232_USERPORT_FR, "Activer l'émulation de périphérique RS232 userport"},
/* hu */ {IDCLS_ENABLE_RS232_USERPORT_HU, "RS232 userport emuláció engedélyezése"},
/* it */ {IDCLS_ENABLE_RS232_USERPORT_IT, "Attiva l'emulazione della RS232 su userport"},
/* ko */ {IDCLS_ENABLE_RS232_USERPORT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RS232_USERPORT_NL, "Activeer RS232 userportemulatie"},
/* ru */ {IDCLS_ENABLE_RS232_USERPORT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RS232_USERPORT_SV, "Aktivera RS232-emulering på användarporten"},
/* tr */ {IDCLS_ENABLE_RS232_USERPORT_TR, "RS232 userport emülasyonunu aktif et"},
#endif

/* rs232drv/rsuser.c */
/* en */ {IDCLS_DISABLE_RS232_USERPORT,    N_("Disable RS232 userport emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RS232_USERPORT_DA, "Deaktivér RS232-emulering på brugerporten"},
/* de */ {IDCLS_DISABLE_RS232_USERPORT_DE, "RS232 Userport Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_RS232_USERPORT_FR, "Désactiver l'émulation de périphérique RS232 userport"},
/* hu */ {IDCLS_DISABLE_RS232_USERPORT_HU, "RS232 userport emuláció tiltása"},
/* it */ {IDCLS_DISABLE_RS232_USERPORT_IT, "Disattiva l'emulazione della RS232 su userport"},
/* ko */ {IDCLS_DISABLE_RS232_USERPORT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RS232_USERPORT_NL, "RS232 userportemulatie uitschakelen"},
/* ru */ {IDCLS_DISABLE_RS232_USERPORT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RS232_USERPORT_SV, "Inaktivera RS232-emulering på användarporten"},
/* tr */ {IDCLS_DISABLE_RS232_USERPORT_TR, "RS232 userport emülasyonunu pasifleþtir"},
#endif

/* rs232drv/rsuser.c */
/* en */ {IDCLS_P_BAUD,    N_("<baud>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_BAUD_DA, "<baud>"},
/* de */ {IDCLS_P_BAUD_DE, "<Baud>"},
/* fr */ {IDCLS_P_BAUD_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_BAUD_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_BAUD_IT, "<baud>"},
/* ko */ {IDCLS_P_BAUD_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_BAUD_NL, "<baud>"},
/* ru */ {IDCLS_P_BAUD_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_BAUD_SV, "<baud>"},
/* tr */ {IDCLS_P_BAUD_TR, "<baud>"},
#endif

/* rs232drv/rsuser.c */
/* en */ {IDCLS_SET_BAUD_RS232_USERPORT,    N_("Set the baud rate of the RS232 userport emulation.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_BAUD_RS232_USERPORT_DA, "Angiv baudhastighet for RS232-emuleringen på brugerporten."},
/* de */ {IDCLS_SET_BAUD_RS232_USERPORT_DE, "Baudrate für RS232 Userport Emulation setzen"},
/* fr */ {IDCLS_SET_BAUD_RS232_USERPORT_FR, "Spécifiez la vitesse en baud du périphérique RS232 userport"},
/* hu */ {IDCLS_SET_BAUD_RS232_USERPORT_HU, "Bitráta megadása az RS232 userport emulációhoz."},
/* it */ {IDCLS_SET_BAUD_RS232_USERPORT_IT, "Imposta la velocità della RS232 su userport (in baud)"},
/* ko */ {IDCLS_SET_BAUD_RS232_USERPORT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_BAUD_RS232_USERPORT_NL, "Zet de baud rate van de RS232 userport emulatie."},
/* ru */ {IDCLS_SET_BAUD_RS232_USERPORT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_BAUD_RS232_USERPORT_SV, "Ange baudhastighet för RS232-emuleringen på användarporten."},
/* tr */ {IDCLS_SET_BAUD_RS232_USERPORT_TR, "RS232 userport emülasyonunun baud rate'ini ayarla."},
#endif

/* rs232drv/rsuser.c */
/* en */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT,    N_("Specify VICE RS232 device for userport")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_DA, "Angiv VICE RS232-enhed for brugerporten"},
/* de */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_DE, "VICE RS232 Gerät für Userport definieren"},
/* fr */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_FR, "Spécifier un périphérique VICE RS232 pour le userport"},
/* hu */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_HU, "VICE RS232-es userport eszköz megadása"},
/* it */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_IT, "Specifica il dispositivo RS232 di VICE per userport"},
/* ko */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_NL, "Geef VICE RS232 apparaat voor userport"},
/* ru */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_SV, "Ange VICE RS232-enhet för användarporten"},
/* tr */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_TR, "Userport için VICE RS232 aygýtýný belirt"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_ENABLE_IEC_4,    N_("Enable IEC device emulation for device #4")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEC_4_DA, "Aktivér IEC-enhedsemulering for enhed #4"},
/* de */ {IDCLS_ENABLE_IEC_4_DE, "IEC Geräte Emulation für Gerät #4 aktivieren"},
/* fr */ {IDCLS_ENABLE_IEC_4_FR, "Activer l'émulation IEC pour le périphérique #4"},
/* hu */ {IDCLS_ENABLE_IEC_4_HU, "IEC eszköz #4 emulációjának engedélyezése"},
/* it */ {IDCLS_ENABLE_IEC_4_IT, "Attiva emulazione IEC per la periferica #4"},
/* ko */ {IDCLS_ENABLE_IEC_4_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEC_4_NL, "Activeer IEC apparaat emulatie voor apparaat #4"},
/* ru */ {IDCLS_ENABLE_IEC_4_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEC_4_SV, "Aktivera IEC-enhetsemulering för enhet 4"},
/* tr */ {IDCLS_ENABLE_IEC_4_TR, "Aygýt #4 için IEC aygýt emülasyonunu aktif et"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_DISABLE_IEC_4,    N_("Disable IEC device emulation for device #4")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEC_4_DA, "Deaktivér IEC-enhedsemulering for enhed #4"},
/* de */ {IDCLS_DISABLE_IEC_4_DE, "IEC Geräte Emulation für Gerät #4 deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEC_4_FR, "Désactiver l'émulation IEC pour le périphérique #4"},
/* hu */ {IDCLS_DISABLE_IEC_4_HU, "IEC eszköz #4 emulációjának tiltása"},
/* it */ {IDCLS_DISABLE_IEC_4_IT, "Disattiva emulazione IEC per la periferica #4"},
/* ko */ {IDCLS_DISABLE_IEC_4_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEC_4_NL, "IEC apparaat emulatie voor apparaat #4 uitschakelen"},
/* ru */ {IDCLS_DISABLE_IEC_4_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEC_4_SV, "Inaktivera IEC-enhetsemulering för enhet 4"},
/* tr */ {IDCLS_DISABLE_IEC_4_TR, "Aygýt #4 için IEC aygýt emülasyonunu pasifleþtir"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_ENABLE_IEC_5,    N_("Enable IEC device emulation for device #5")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEC_5_DA, "Aktivér IEC-enhedsemulering for enhed #5"},
/* de */ {IDCLS_ENABLE_IEC_5_DE, "IEC Geräte Emulation für Gerät #5 aktivieren"},
/* fr */ {IDCLS_ENABLE_IEC_5_FR, "Activer l'émulation IEC pour le périphérique #5"},
/* hu */ {IDCLS_ENABLE_IEC_5_HU, "IEC eszköz #5 emulációjának engedélyezése"},
/* it */ {IDCLS_ENABLE_IEC_5_IT, "Attiva emulazione IEC per la periferica #5"},
/* ko */ {IDCLS_ENABLE_IEC_5_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEC_5_NL, "Activeer IEC apparaat emulatie voor apparaat #5"},
/* ru */ {IDCLS_ENABLE_IEC_5_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEC_5_SV, "Aktivera IEC-enhetsemulering för enhet 5"},
/* tr */ {IDCLS_ENABLE_IEC_5_TR, "Aygýt #5 için IEC aygýt emülasyonunu aktif et"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_DISABLE_IEC_5,    N_("Disable IEC device emulation for device #5")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEC_5_DA, "Deaktivér IEC-enhedsemulering for enhed #5"},
/* de */ {IDCLS_DISABLE_IEC_5_DE, "IEC Geräte Emulation für Gerät #5 deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEC_5_FR, "Désactiver l'émulation IEC pour le périphérique #5"},
/* hu */ {IDCLS_DISABLE_IEC_5_HU, "IEC eszköz #5 emulációjának tiltása"},
/* it */ {IDCLS_DISABLE_IEC_5_IT, "Disattiva emulazione IEC per la periferica #5"},
/* ko */ {IDCLS_DISABLE_IEC_5_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEC_5_NL, "IEC apparaat emulatie voor apparaat #5 uitschakelen"},
/* ru */ {IDCLS_DISABLE_IEC_5_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEC_5_SV, "Inaktivera IEC-enhetsemulering för enhet 5"},
/* tr */ {IDCLS_DISABLE_IEC_5_TR, "Aygýt #5 için IEC aygýt emülasyonunu pasifleþtir"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_ENABLE_IEC_8,    N_("Enable IEC device emulation for device #8")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEC_8_DA, "Aktivér IEC-enhedsemulering for enhed #8"},
/* de */ {IDCLS_ENABLE_IEC_8_DE, "IEC Geräte Emulation für Gerät #8 aktivieren"},
/* fr */ {IDCLS_ENABLE_IEC_8_FR, "Activer l'émulation IEC pour le lecteur #8"},
/* hu */ {IDCLS_ENABLE_IEC_8_HU, "IEC eszköz #8 emulációjának engedélyezése"},
/* it */ {IDCLS_ENABLE_IEC_8_IT, "Attiva emulazione IEC per la periferica #8"},
/* ko */ {IDCLS_ENABLE_IEC_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEC_8_NL, "Activeer IEC apparaat emulatie voor apparaat #8"},
/* ru */ {IDCLS_ENABLE_IEC_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEC_8_SV, "Aktivera IEC-enhetsemulering för enhet 8"},
/* tr */ {IDCLS_ENABLE_IEC_8_TR, "Aygýt #8 için IEC aygýt emülasyonunu aktif et"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_DISABLE_IEC_8,    N_("Disable IEC device emulation for device #8")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEC_8_DA, "Deaktivér IEC-enhedsemulering for enhed #8"},
/* de */ {IDCLS_DISABLE_IEC_8_DE, "IEC Geräte Emulation für Gerät #8 deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEC_8_FR, "Désactiver l'émulation IEC pour le lecteur #8"},
/* hu */ {IDCLS_DISABLE_IEC_8_HU, "IEC eszköz #8 emulációjának tiltása"},
/* it */ {IDCLS_DISABLE_IEC_8_IT, "Disattiva emulazione IEC per la periferica #8"},
/* ko */ {IDCLS_DISABLE_IEC_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEC_8_NL, "IEC apparaat emulatie voor apparaat #8 uitschakelen"},
/* ru */ {IDCLS_DISABLE_IEC_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEC_8_SV, "Inaktivera IEC-enhetsemulering för enhet 8"},
/* tr */ {IDCLS_DISABLE_IEC_8_TR, "Aygýt #8 için IEC aygýt emülasyonunu pasifleþtir"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_ENABLE_IEC_9,    N_("Enable IEC device emulation for device #9")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEC_9_DA, "Aktivér IEC-enhedsemulering for enhed #9"},
/* de */ {IDCLS_ENABLE_IEC_9_DE, "IEC Geräte Emulation für Gerät #9 aktivieren"},
/* fr */ {IDCLS_ENABLE_IEC_9_FR, "Activer l'émulation IEC pour le lecteur #9"},
/* hu */ {IDCLS_ENABLE_IEC_9_HU, "IEC eszköz #9 emulációjának engedélyezése"},
/* it */ {IDCLS_ENABLE_IEC_9_IT, "Attiva emulazione IEC per la periferica #9"},
/* ko */ {IDCLS_ENABLE_IEC_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEC_9_NL, "Activeer IEC apparaat emulatie voor apparaat #9"},
/* ru */ {IDCLS_ENABLE_IEC_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEC_9_SV, "Aktivera IEC-enhetsemulering för enhet 9"},
/* tr */ {IDCLS_ENABLE_IEC_9_TR, "Aygýt #9 için IEC aygýt emülasyonunu aktif et"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_DISABLE_IEC_9,    N_("Disable IEC device emulation for device #9")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEC_9_DA, "Deaktivér IEC-enhedsemulering for enhed #9"},
/* de */ {IDCLS_DISABLE_IEC_9_DE, "IEC Geräte Emulation für Gerät #9 deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEC_9_FR, "Désactiver l'émulation IEC pour le lecteur #9"},
/* hu */ {IDCLS_DISABLE_IEC_9_HU, "IEC eszköz #9 emulációjának tiltása"},
/* it */ {IDCLS_DISABLE_IEC_9_IT, "Disattiva emulazione IEC per la periferica #9"},
/* ko */ {IDCLS_DISABLE_IEC_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEC_9_NL, "IEC apparaat emulatie voor apparaat #9 uitschakelen"},
/* ru */ {IDCLS_DISABLE_IEC_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEC_9_SV, "Inaktivera IEC-enhetsemulering för enhet 9"},
/* tr */ {IDCLS_DISABLE_IEC_9_TR, "Aygýt #9 için IEC aygýt emülasyonunu pasifleþtir"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_ENABLE_IEC_10,    N_("Enable IEC device emulation for device #10")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEC_10_DA, "Aktivér IEC-enhedsemulering for enhed #10"},
/* de */ {IDCLS_ENABLE_IEC_10_DE, "IEC Geräte Emulation für Gerät #10 aktivieren"},
/* fr */ {IDCLS_ENABLE_IEC_10_FR, "Activer l'émulation IEC pour le lecteur #10"},
/* hu */ {IDCLS_ENABLE_IEC_10_HU, "IEC eszköz #10 emulációjának engedélyezése"},
/* it */ {IDCLS_ENABLE_IEC_10_IT, "Attiva emulazione IEC per la periferica #10"},
/* ko */ {IDCLS_ENABLE_IEC_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEC_10_NL, "Activeer IEC apparaat emulatie voor apparaat #10"},
/* ru */ {IDCLS_ENABLE_IEC_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEC_10_SV, "Aktivera IEC-enhetsemulering för enhet 10"},
/* tr */ {IDCLS_ENABLE_IEC_10_TR, "Aygýt #10 için IEC aygýt emülasyonunu aktif et"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_DISABLE_IEC_10,    N_("Disable IEC device emulation for device #10")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEC_10_DA, "Deaktivér IEC-enhedsemulering for enhed #10"},
/* de */ {IDCLS_DISABLE_IEC_10_DE, "IEC Geräte Emulation für Gerät #10 deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEC_10_FR, "Désactiver l'émulation IEC pour le lecteur #10"},
/* hu */ {IDCLS_DISABLE_IEC_10_HU, "IEC eszköz #10 emulációjának tiltása"},
/* it */ {IDCLS_DISABLE_IEC_10_IT, "Disattiva emulazione IEC per la periferica #10"},
/* ko */ {IDCLS_DISABLE_IEC_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEC_10_NL, "IEC apparaat emulatie voor apparaat #10 uitschakelen"},
/* ru */ {IDCLS_DISABLE_IEC_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEC_10_SV, "Inaktivera IEC-enhetsemulering för enhet 10"},
/* tr */ {IDCLS_DISABLE_IEC_10_TR, "Aygýt #10 için IEC aygýt emülasyonunu pasifleþtir"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_ENABLE_IEC_11,    N_("Enable IEC device emulation for device #11")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEC_11_DA, "Aktivér IEC-enhedsemulering for enhed #11"},
/* de */ {IDCLS_ENABLE_IEC_11_DE, "IEC Geräte Emulation für Gerät #11 aktivieren"},
/* fr */ {IDCLS_ENABLE_IEC_11_FR, "Activer l'émulation IEC pour le lecteur #11"},
/* hu */ {IDCLS_ENABLE_IEC_11_HU, "IEC eszköz #11 emulációjának engedélyezése"},
/* it */ {IDCLS_ENABLE_IEC_11_IT, "Attiva emulazione IEC per la periferica #11"},
/* ko */ {IDCLS_ENABLE_IEC_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEC_11_NL, "Activeer IEC apparaat emulatie voor apparaat #11"},
/* ru */ {IDCLS_ENABLE_IEC_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEC_11_SV, "Aktivera IEC-enhetsemulering för enhet 11"},
/* tr */ {IDCLS_ENABLE_IEC_11_TR, "Aygýt #11 için IEC aygýt emülasyonunu aktif et"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_DISABLE_IEC_11,    N_("Disable IEC device emulation for device #11")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEC_11_DA, "Deaktivér IEC-enhedsemulering for enhed #11"},
/* de */ {IDCLS_DISABLE_IEC_11_DE, "IEC Geräte Emulation für Gerät #11 deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEC_11_FR, "Désactiver l'émulation IEC pour le lecteur #11"},
/* hu */ {IDCLS_DISABLE_IEC_11_HU, "IEC eszköz #11 emulációjának tiltása"},
/* it */ {IDCLS_DISABLE_IEC_11_IT, "Disattiva emulazione IEC per la periferica #11"},
/* ko */ {IDCLS_DISABLE_IEC_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEC_11_NL, "IEC apparaat emulatie voor apparaat #11 uitschakelen"},
/* ru */ {IDCLS_DISABLE_IEC_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEC_11_SV, "Inaktivera IEC-enhetsemulering för enhet 11"},
/* tr */ {IDCLS_DISABLE_IEC_11_TR, "Aygýt #11 için IEC aygýt emülasyonunu pasifleþtir"},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_P_ENGINE_MODEL,    N_("<engine and model>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_ENGINE_MODEL_DA, "<motor og model>"},
/* de */ {IDCLS_P_ENGINE_MODEL_DE, "<Engine und Modell>"},
/* fr */ {IDCLS_P_ENGINE_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_ENGINE_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_ENGINE_MODEL_IT, "<motore e modello>"},
/* ko */ {IDCLS_P_ENGINE_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_ENGINE_MODEL_NL, "<kern en model>"},
/* ru */ {IDCLS_P_ENGINE_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_ENGINE_MODEL_SV, "<motor och modell>"},
/* tr */ {IDCLS_P_ENGINE_MODEL_TR, "<motor ve model>"},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_FASTSID_ENGINE_MODEL,    N_("0: FastSID 6581, 1: FastSID 8580")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_FASTSID_ENGINE_MODEL_DA, "0: FastSID 6581, 1: FastSID 8580"},
/* de */ {IDCLS_FASTSID_ENGINE_MODEL_DE, "0: FastSID 6581, 1: FastSID 8580"},
/* fr */ {IDCLS_FASTSID_ENGINE_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_FASTSID_ENGINE_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_FASTSID_ENGINE_MODEL_IT, "0: FastSID 6581, 1: FastSID 8580"},
/* ko */ {IDCLS_FASTSID_ENGINE_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_FASTSID_ENGINE_MODEL_NL, "0: FastSID 6581, 1: FastSID 8580"},
/* ru */ {IDCLS_FASTSID_ENGINE_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_FASTSID_ENGINE_MODEL_SV, "0: FastSID 6581, 1: FastSID 8580"},
/* tr */ {IDCLS_FASTSID_ENGINE_MODEL_TR, "0: FastSID 6581, 1: FastSID 8580"},
#endif

#ifdef HAVE_RESID
/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_RESID_ENGINE_MODEL,    N_("256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digiboost")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RESID_ENGINE_MODEL_DA, "256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digitalforstærkning"},
/* de */ {IDCLS_RESID_ENGINE_MODEL_DE, "256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digiboost"},
/* fr */ {IDCLS_RESID_ENGINE_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_RESID_ENGINE_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_RESID_ENGINE_MODEL_IT, "256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digiboost"},
/* ko */ {IDCLS_RESID_ENGINE_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_RESID_ENGINE_MODEL_NL, "256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digiboost"},
/* ru */ {IDCLS_RESID_ENGINE_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RESID_ENGINE_MODEL_SV, "256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digiförstärkning"},
/* tr */ {IDCLS_RESID_ENGINE_MODEL_TR, "256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digiboost"},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_RESIDDTV_ENGINE_MODEL,    N_("260: DTVSID")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RESIDDTV_ENGINE_MODEL_DA, "260: DTVSID"},
/* de */ {IDCLS_RESIDDTV_ENGINE_MODEL_DE, "260: DTVSID"},
/* fr */ {IDCLS_RESIDDTV_ENGINE_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_RESIDDTV_ENGINE_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_RESIDDTV_ENGINE_MODEL_IT, "260: DTVSID"},
/* ko */ {IDCLS_RESIDDTV_ENGINE_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_RESIDDTV_ENGINE_MODEL_NL, "260: DTVSID"},
/* ru */ {IDCLS_RESIDDTV_ENGINE_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RESIDDTV_ENGINE_MODEL_SV, "260: DTVSID"},
/* tr */ {IDCLS_RESIDDTV_ENGINE_MODEL_TR, "260: DTVSID"},
#endif
#endif

#ifdef HAVE_CATWEASELMKIII
/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_CATWEASELMKIII_ENGINE_MODEL,    N_("512: Catweasel")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_CATWEASELMKIII_ENGINE_MODEL_DA, "512: Catweasel"},
/* de */ {IDCLS_CATWEASELMKIII_ENGINE_MODEL_DE, "512: Catweasel"},
/* fr */ {IDCLS_CATWEASELMKIII_ENGINE_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_CATWEASELMKIII_ENGINE_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_CATWEASELMKIII_ENGINE_MODEL_IT, "512: Catweasel"},
/* ko */ {IDCLS_CATWEASELMKIII_ENGINE_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_CATWEASELMKIII_ENGINE_MODEL_NL, "512: Catweasel"},
/* ru */ {IDCLS_CATWEASELMKIII_ENGINE_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_CATWEASELMKIII_ENGINE_MODEL_SV, "512: Catweasel"},
/* tr */ {IDCLS_CATWEASELMKIII_ENGINE_MODEL_TR, "512: Catweasel"},
#endif
#endif

#ifdef HAVE_HARDSID
/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_HARDSID_ENGINE_MODEL,    N_("768: HardSID")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_HARDSID_ENGINE_MODEL_DA, "768: HardSID"},
/* de */ {IDCLS_HARDSID_ENGINE_MODEL_DE, "768: HardSID"},
/* fr */ {IDCLS_HARDSID_ENGINE_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_HARDSID_ENGINE_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_HARDSID_ENGINE_MODEL_IT, "768: HardSID"},
/* ko */ {IDCLS_HARDSID_ENGINE_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_HARDSID_ENGINE_MODEL_NL, "768: HardSID"},
/* ru */ {IDCLS_HARDSID_ENGINE_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_HARDSID_ENGINE_MODEL_SV, "768: HardSID"},
/* tr */ {IDCLS_HARDSID_ENGINE_MODEL_TR, "768: HardSID"},
#endif
#endif

#ifdef HAVE_PARSID
/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_PARSID_ENGINE_MODEL,    N_("1024: ParSID in par port 1, 1280: ParSID in par port 2, 1536: ParSID in par port 3")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PARSID_ENGINE_MODEL_DA, "1024: ParSID på port 1, 1280: ParSID på port 2, 1536: ParSID på port 3"},
/* de */ {IDCLS_PARSID_ENGINE_MODEL_DE, "1024: ParSID in par port 1, 1280: ParSID in par port 2, 1536: ParSID in par port 3"},
/* fr */ {IDCLS_PARSID_ENGINE_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_PARSID_ENGINE_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_PARSID_ENGINE_MODEL_IT, "1024: ParSID in par port 1, 1280: ParSID in par port 2, 1536: ParSID in par port 3"},
/* ko */ {IDCLS_PARSID_ENGINE_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PARSID_ENGINE_MODEL_NL, "1024: ParSID in par port 1, 1280: ParSID in par port 2, 1536: ParSID in par port 3"},
/* ru */ {IDCLS_PARSID_ENGINE_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PARSID_ENGINE_MODEL_SV, "1024: ParSID i parport 1, 1280: ParSID i parport 2, 1536: ParSID i parport 3"},
/* tr */ {IDCLS_PARSID_ENGINE_MODEL_TR, "1024: Par port 1'de ParSID, 1280: Par port 2'de ParSID, 1536: Par port 3'de ParSID"},
#endif
#endif

#ifdef HAVE_RESID_FP
/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_RESIDFP_ENGINE_MODEL,    N_("1800: ReSID-FP 6581R3 4885, 1801: ReSID-FP 6581R3 0486S, 1802: ReSID-FP 6581R3 3984, 1803: ReSID-FP 6581R4 AR 3789, 1804: ReSID-FP 6581R3 4485, 1805: ReSID-FP 6581R4 1986S, 1808: ReSID-FP 8580R5 3691, 1809: ReSID-FP 8580R5 3691 + digiboost, 1810: ReSID-FP 8580R5 1489, 1811: ReSID-FP 8580R5 1489D")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RESIDFP_ENGINE_MODEL_DA, "1800: ReSID-FP 6581R3 4885, 1801: ReSID-FP 6581R3 0486S, 1802: ReSID-FP 6581R3 3984, 1803: ReSID-FP 6581R4 AR 3789, 1804: ReSID-FP 6581R3 4485, 1805: ReSID-FP 6581R4 1986S, 1808: ReSID-FP 8580R5 3691, 1809: ReSID-FP 8580R5 3691 + digiboost, 1810: ReSID-FP 8580R5 1489, 1811: ReSID-FP 8580R5 1489D"},
/* de */ {IDCLS_RESIDFP_ENGINE_MODEL_DE, "1800: ReSID-FP 6581R3 4885, 1801: ReSID-FP 6581R3 0486S, 1802: ReSID-FP 6581R3 3984, 1803: ReSID-FP 6581R4 AR 3789, 1804: ReSID-FP 6581R3 4485, 1805: ReSID-FP 6581R4 1986S, 1808: ReSID-FP 8580R5 3691, 1809: ReSID-FP 8580R5 3691 + digiboost, 1810: ReSID-FP 8580R5 1489, 1811: ReSID-FP 8580R5 1489D"},
/* fr */ {IDCLS_RESIDFP_ENGINE_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_RESIDFP_ENGINE_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_RESIDFP_ENGINE_MODEL_IT, "1800: ReSID-FP 6581R3 4885, 1801: ReSID-FP 6581R3 0486S, 1802: ReSID-FP 6581R3 3984, 1803: ReSID-FP 6581R4 AR 3789, 1804: ReSID-FP 6581R3 4485, 1805: ReSID-FP 6581R4 1986S, 1808: ReSID-FP 8580R5 3691, 1809: ReSID-FP 8580R5 3691 + digiboost, 1810: ReSID-FP 8580R5 1489, 1811: ReSID-FP 8580R5 1489D"},
/* ko */ {IDCLS_RESIDFP_ENGINE_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_RESIDFP_ENGINE_MODEL_NL, "1800: ReSID-FP 6581R3 4885, 1801: ReSID-FP 6581R3 0486S, 1802: ReSID-FP 6581R3 3984, 1803: ReSID-FP 6581R4 AR 3789, 1804: ReSID-FP 6581R3 4485, 1805: ReSID-FP 6581R4 1986S, 1808: ReSID-FP 8580R5 3691, 1809: ReSID-FP 8580R5 3691 + digiboost, 1810: ReSID-FP 8580R5 1489, 1811: ReSID-FP 8580R5 1489 + digiboost"},
/* ru */ {IDCLS_RESIDFP_ENGINE_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RESIDFP_ENGINE_MODEL_SV, "1800: ReSID-FP 6581R3 4885, 1801: ReSID-FP 6581R3 0486S, 1802: ReSID-FP 6581R3 3984, 1803: ReSID-FP 6581R4 AR 3789, 1804: ReSID-FP 6581R3 4485, 1805: ReSID-FP 6581R4 1986S, 1808: ReSID-FP 8580R5 3691, 1809: ReSID-FP 8580R5 3691 + digiförstärkning, 1810: ReSID-FP 8580R5 1489, 1811: ReSID-FP 8580R5 1489 + digiförstärkning"},
/* tr */ {IDCLS_RESIDFP_ENGINE_MODEL_TR, "1800: ReSID-FP 6581R3 4885, 1801: ReSID-FP 6581R3 0486S, 1802: ReSID-FP 6581R3 3984, 1803: ReSID-FP 6581R4 AR 3789, 1804: ReSID-FP 6581R3 4485, 1805: ReSID-FP 6581R4 1986S, 1808: ReSID-FP 8580R5 3691, 1809: ReSID-FP 8580R5 3691 + digiboost, 1810: ReSID-FP 8580R5 1489, 1811: ReSID-FP 8580R5 1489D"},
#endif
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_ENABLE_SECOND_SID,    N_("Enable second SID")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SECOND_SID_DA, "Aktivér sekundær SID"},
/* de */ {IDCLS_ENABLE_SECOND_SID_DE, "Zweiten SID aktivieren"},
/* fr */ {IDCLS_ENABLE_SECOND_SID_FR, "Activer le second SID"},
/* hu */ {IDCLS_ENABLE_SECOND_SID_HU, "Második SID engedélyezése"},
/* it */ {IDCLS_ENABLE_SECOND_SID_IT, "Attiva secondo SID"},
/* ko */ {IDCLS_ENABLE_SECOND_SID_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SECOND_SID_NL, "Activeer stereo SID"},
/* ru */ {IDCLS_ENABLE_SECOND_SID_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SECOND_SID_SV, "Aktivera andra SID"},
/* tr */ {IDCLS_ENABLE_SECOND_SID_TR, "Ýkinci SID'i aktif et"},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_ENABLE_SIDCART,    N_("Enable the SID cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SIDCART_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ENABLE_SIDCART_DE, "SID Modul aktivieren"},
/* fr */ {IDCLS_ENABLE_SIDCART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_SIDCART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_SIDCART_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ENABLE_SIDCART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SIDCART_NL, "*Activeer de SID cartridge"},
/* ru */ {IDCLS_ENABLE_SIDCART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SIDCART_SV, "Aktivera SID-insticksmodul"},
/* tr */ {IDCLS_ENABLE_SIDCART_TR, ""},  /* fuzzy */
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_DISABLE_SIDCART,    N_("Disable the SID cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SIDCART_DA, ""},  /* fuzzy */
/* de */ {IDCLS_DISABLE_SIDCART_DE, "SID Modul deaktivieren"},
/* fr */ {IDCLS_DISABLE_SIDCART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_SIDCART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_SIDCART_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_DISABLE_SIDCART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SIDCART_NL, "De SID cartridge uitschakelen"},
/* ru */ {IDCLS_DISABLE_SIDCART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SIDCART_SV, "Inaktivera SID-insticksmodul"},
/* tr */ {IDCLS_DISABLE_SIDCART_TR, ""},  /* fuzzy */
#endif

/* sid/sid-cmdline-options.c, c64/plus60k, c64/c64_256k.c */
/* en */ {IDCLS_P_BASE_ADDRESS,    N_("<Base address>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_BASE_ADDRESS_DA, "<Baseadresse>"},
/* de */ {IDCLS_P_BASE_ADDRESS_DE, "<Basis Adresse>"},
/* fr */ {IDCLS_P_BASE_ADDRESS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_BASE_ADDRESS_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_BASE_ADDRESS_IT, "<Indirizzo base>"},
/* ko */ {IDCLS_P_BASE_ADDRESS_KO, "<º£ÀÌ½º ÁÖ¼Ò>"},
/* nl */ {IDCLS_P_BASE_ADDRESS_NL, "<Basisadres>"},
/* ru */ {IDCLS_P_BASE_ADDRESS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_BASE_ADDRESS_SV, "<Basadress>"},
/* tr */ {IDCLS_P_BASE_ADDRESS_TR, "<Taban adresi>"},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_SID_2_ADDRESS,    N_("Specify base address for 2nd SID")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SID_2_ADDRESS_DA, "Angiv baseadresse for sekundær SID"},
/* de */ {IDCLS_SPECIFY_SID_2_ADDRESS_DE, "Basis Adresse für zweiten SID definieren"},
/* fr */ {IDCLS_SPECIFY_SID_2_ADDRESS_FR, "Spécifier l'adresse de base pour le second SID"},
/* hu */ {IDCLS_SPECIFY_SID_2_ADDRESS_HU, "Adja meg a báziscímét a második SID-nek"},
/* it */ {IDCLS_SPECIFY_SID_2_ADDRESS_IT, "Specifica l'indirizzo di base per il secondo SID"},
/* ko */ {IDCLS_SPECIFY_SID_2_ADDRESS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SID_2_ADDRESS_NL, "Geef het basisadres van de 2e SID"},
/* ru */ {IDCLS_SPECIFY_SID_2_ADDRESS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SID_2_ADDRESS_SV, "Ange basadress för andra SID"},
/* tr */ {IDCLS_SPECIFY_SID_2_ADDRESS_TR, "2nci SID için taban adresini belirt"},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_ENABLE_SID_FILTERS,    N_("Emulate SID filters")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SID_FILTERS_DA, "Emulér SID-filtre"},
/* de */ {IDCLS_ENABLE_SID_FILTERS_DE, "SID Filter Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_SID_FILTERS_FR, "Émuler les filtres SID"},
/* hu */ {IDCLS_ENABLE_SID_FILTERS_HU, "SID szûrõk emulációja"},
/* it */ {IDCLS_ENABLE_SID_FILTERS_IT, "Emula i filtri del SID"},
/* ko */ {IDCLS_ENABLE_SID_FILTERS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SID_FILTERS_NL, "Emuleer SID filters"},
/* ru */ {IDCLS_ENABLE_SID_FILTERS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SID_FILTERS_SV, "Emulera SID-filter"},
/* tr */ {IDCLS_ENABLE_SID_FILTERS_TR, "SID filtrelerini emüle et"},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_DISABLE_SID_FILTERS,    N_("Do not emulate SID filters")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SID_FILTERS_DA, "Emulér ikke SID-filtre"},
/* de */ {IDCLS_DISABLE_SID_FILTERS_DE, "SID Filter Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_SID_FILTERS_FR, "Ne pas émuler les filtres SID"},
/* hu */ {IDCLS_DISABLE_SID_FILTERS_HU, "Nem emulálja a SID szûrõket"},
/* it */ {IDCLS_DISABLE_SID_FILTERS_IT, "Non emulare i filtri del SID"},
/* ko */ {IDCLS_DISABLE_SID_FILTERS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SID_FILTERS_NL, "SID filters niet emuleren"},
/* ru */ {IDCLS_DISABLE_SID_FILTERS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SID_FILTERS_SV, "Emulera inte SID-filter"},
/* tr */ {IDCLS_DISABLE_SID_FILTERS_TR, "SID filtrelerini emüle etme"},
#endif

#ifdef HAVE_RESID
/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_RESID_SAMPLING_METHOD,    N_("reSID sampling method (0: fast, 1: interpolating, 2: resampling, 3: fast resampling)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RESID_SAMPLING_METHOD_DA, "reSID-samplingmetode (0: hurtig, 1: interpolerende, 2: omsampling, 3: hurtig omsampling)"},
/* de */ {IDCLS_RESID_SAMPLING_METHOD_DE, "reSID Sample Methode (0: schnell, 1: interpolierend, 2: resampling, 3: schnelles resampling)"},
/* fr */ {IDCLS_RESID_SAMPLING_METHOD_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_RESID_SAMPLING_METHOD_HU, "reSID mintavételezési mód (0: gyors, 1: interpoláló, 2: újramintavételezõ, 3: gyors újramintavételezõ)"},
/* it */ {IDCLS_RESID_SAMPLING_METHOD_IT, "Metodo di campionamento del reSID (0: veloce, 1: interpolato, 2: ricampionato 3: ricampionamento veloce)"},
/* ko */ {IDCLS_RESID_SAMPLING_METHOD_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_RESID_SAMPLING_METHOD_NL, "reSID sampling methode (0: snel, 1: interpoleren, 2: resampling, 3: snelle resampling)"},
/* ru */ {IDCLS_RESID_SAMPLING_METHOD_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RESID_SAMPLING_METHOD_SV, "reSID-samplingsmetod (0: snabb, 1: interpolerande, 2: omsampling, 3: snabb omsampling)"},
/* tr */ {IDCLS_RESID_SAMPLING_METHOD_TR, "reSID örnekleme metodu (0: hýzlý, 1: ara deðer bulma, 2: yeniden örnekleme, 3: hýzlý yeniden örnekleme)"},
#endif

/* sid/sid-cmdline-options.c, vsync.c */
/* en */ {IDCLS_P_PERCENT,    N_("<percent>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_PERCENT_DA, "<procent>"},
/* de */ {IDCLS_P_PERCENT_DE, "<prozent>"},
/* fr */ {IDCLS_P_PERCENT_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_PERCENT_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_PERCENT_IT, "<percento>"},
/* ko */ {IDCLS_P_PERCENT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_PERCENT_NL, "<procent>"},
/* ru */ {IDCLS_P_PERCENT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_PERCENT_SV, "<procent>"},
/* tr */ {IDCLS_P_PERCENT_TR, "<yüzde>"},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_PASSBAND_PERCENTAGE,    N_("reSID resampling passband in percentage of total bandwidth (0 - 90)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PASSBAND_PERCENTAGE_DA, "Pasbånd for reSID-resampling i procent af total båndbredde (0 - 90)"},
/* de */ {IDCLS_PASSBAND_PERCENTAGE_DE, "reSID Resampling Passband Prozentwert der gesamte Bandbreite (0 - 90)\n(0 - 90, niedrig ist schneller, höher ist besser)"},
/* fr */ {IDCLS_PASSBAND_PERCENTAGE_FR, "Bande passante pour le resampling reSID en pourcentage de la bande totale (0 - 90)"},
/* hu */ {IDCLS_PASSBAND_PERCENTAGE_HU, "reSID újramintavételezési sávnak a teljes sávszélességre vonatkoztatott aránya (0 - 90)"},
/* it */ {IDCLS_PASSBAND_PERCENTAGE_IT, "Banda passante di ricampionamento del reSID in percentuale di quella totale (0 - 90)"},
/* ko */ {IDCLS_PASSBAND_PERCENTAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PASSBAND_PERCENTAGE_NL, "reSID resampling passband in percentage van de totale bandbreedte (0 - 90)"},
/* ru */ {IDCLS_PASSBAND_PERCENTAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PASSBAND_PERCENTAGE_SV, "Passband för reSID-resampling i procent av total bandbredd (0 - 90)"},
/* tr */ {IDCLS_PASSBAND_PERCENTAGE_TR, "reSID yeniden örnekleme passband'inin toplam bant geniþliðine yüzdesel oraný (0 - 90)"},
#endif

/* sid/sid-cmdline-options.c, vsync.c */
/* en */ {IDCLS_RESID_FILTER_BIAS,    N_("reSID filter bias setting, which can be used to adjust DAC bias in millivolts.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RESID_FILTER_BIAS_DA, "reSID filter biasindstilling, som kan bruges til at justere DAC bias i millivolt."},
/* de */ {IDCLS_RESID_FILTER_BIAS_DE, "reSID Filter Vorspannungseinstellung, welche für die Anpassung der DAC\nVorspannung in Millivolt benutzt werden kann"},
/* fr */ {IDCLS_RESID_FILTER_BIAS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_RESID_FILTER_BIAS_HU, ""},  /* fuzzy */
/* it */ {IDCLS_RESID_FILTER_BIAS_IT, "Impostazione del bias del filtro del reSID, che può essere usato per correggere il bias del DAC in millivolt."},
/* ko */ {IDCLS_RESID_FILTER_BIAS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_RESID_FILTER_BIAS_NL, "reSID filter bias instelling, dit kan gebruikt worden om de DAC bias in millivolts aan te passen."},
/* ru */ {IDCLS_RESID_FILTER_BIAS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RESID_FILTER_BIAS_SV, "Bias-inställning för reSID-filter, vilket kan användas för att justera D/A-bias i millivolt."},
/* tr */ {IDCLS_RESID_FILTER_BIAS_TR, "Millivolt cinsinden DAC meyilini ayarlamak için kullanýlabilen reSID filtresi meyil ayarý."},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_RESID_GAIN_PERCENTAGE,    N_("reSID gain in percent (90 - 100)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RESID_GAIN_PERCENTAGE_DA, "Gain for reSID i procent (90 - 100)"},
/* de */ {IDCLS_RESID_GAIN_PERCENTAGE_DE, "reSID Gain in Prozent (90 - 100)"},
/* fr */ {IDCLS_RESID_GAIN_PERCENTAGE_FR, "Gain reSID en pourcent (90 - 100)"},
/* hu */ {IDCLS_RESID_GAIN_PERCENTAGE_HU, "reSID százalékos erõsítés (90 - 100)"},
/* it */ {IDCLS_RESID_GAIN_PERCENTAGE_IT, "Guadagno del reSID in percentuale (90 - 100)"},
/* ko */ {IDCLS_RESID_GAIN_PERCENTAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_RESID_GAIN_PERCENTAGE_NL, "reSID versterking procent (90 - 100)"},
/* ru */ {IDCLS_RESID_GAIN_PERCENTAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RESID_GAIN_PERCENTAGE_SV, "Gain för reSID i procent (90 - 100)"},
/* tr */ {IDCLS_RESID_GAIN_PERCENTAGE_TR, "reSID gain yüzdesi (90 - 100)"},
#endif
#endif

/* vdc/vdc-cmdline-options.c */
/* en */ {IDCLS_SET_VDC_MEMORY_16KB,    N_("Set the VDC memory size to 16KB")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_VDC_MEMORY_16KB_DA, "Sæt VDC-hukommelsesstørrelse til 16KB"},
/* de */ {IDCLS_SET_VDC_MEMORY_16KB_DE, "VDC Speichgröße auf 16KB setzen"},
/* fr */ {IDCLS_SET_VDC_MEMORY_16KB_FR, "Régler la taille de la mémoire VDC à 16KO"},
/* hu */ {IDCLS_SET_VDC_MEMORY_16KB_HU, "VDC memória méret beállítása 16KB-ra"},
/* it */ {IDCLS_SET_VDC_MEMORY_16KB_IT, "Imposta la dimensione della memoria del VDC a 16KB"},
/* ko */ {IDCLS_SET_VDC_MEMORY_16KB_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_VDC_MEMORY_16KB_NL, "Zet de VDC geheugengrootte als 16KB"},
/* ru */ {IDCLS_SET_VDC_MEMORY_16KB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_VDC_MEMORY_16KB_SV, "Sätt VDC-minnesstorlek till 16KB"},
/* tr */ {IDCLS_SET_VDC_MEMORY_16KB_TR, "VDC bellek boyutunu 16KB'a ayarla"},
#endif

/* vdc/vdc-cmdline-options.c */
/* en */ {IDCLS_SET_VDC_MEMORY_64KB,    N_("Set the VDC memory size to 64KB")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_VDC_MEMORY_64KB_DA, "Sæt VDC-hukommelsesstørrelse til 64KB"},
/* de */ {IDCLS_SET_VDC_MEMORY_64KB_DE, "VDC Speichgröße auf 64KB setzen"},
/* fr */ {IDCLS_SET_VDC_MEMORY_64KB_FR, "Régler la taille de la mémoire VDC à 64KO"},
/* hu */ {IDCLS_SET_VDC_MEMORY_64KB_HU, "VDC memória méret beállítása 64KB-ra"},
/* it */ {IDCLS_SET_VDC_MEMORY_64KB_IT, "Imposta la dimensione della memoria del VDC a 64KB"},
/* ko */ {IDCLS_SET_VDC_MEMORY_64KB_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_VDC_MEMORY_64KB_NL, "Zet de VDC geheugengrootte als 64KB"},
/* ru */ {IDCLS_SET_VDC_MEMORY_64KB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_VDC_MEMORY_64KB_SV, "Sätt VDC-minnesstorlek till 64KB"},
/* tr */ {IDCLS_SET_VDC_MEMORY_64KB_TR, "VDC bellek boyutunu 64KB'a ayarla"},
#endif

/* vdc/vdc-cmdline-options.c */
/* en */ {IDCLS_SET_VDC_REVISION,    N_("Set VDC revision (0..2)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_VDC_REVISION_DA, "Angiv VDC-revision (0..2)"},
/* de */ {IDCLS_SET_VDC_REVISION_DE, "VDC Revision setzen (0..2)"},
/* fr */ {IDCLS_SET_VDC_REVISION_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_VDC_REVISION_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_VDC_REVISION_IT, "Imposta la revisione del VDC (0..2)"},
/* ko */ {IDCLS_SET_VDC_REVISION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_VDC_REVISION_NL, "Zet de VDC revisie (0..2)"},
/* ru */ {IDCLS_SET_VDC_REVISION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_VDC_REVISION_SV, "Ange VDC-revision (0..2)"},
/* tr */ {IDCLS_SET_VDC_REVISION_TR, "VDC revizyonunu ayarla (0..2)"},
#endif

/* vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_P_SPEC,    N_("<spec>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_SPEC_DA, "<spec>"},
/* de */ {IDCLS_P_SPEC_DE, "<Spec>"},
/* fr */ {IDCLS_P_SPEC_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_SPEC_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_SPEC_IT, "<spec>"},
/* ko */ {IDCLS_P_SPEC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_SPEC_NL, "<spec>"},
/* ru */ {IDCLS_P_SPEC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_SPEC_SV, "<spec>"},
/* tr */ {IDCLS_P_SPEC_TR, "<þart>"},
#endif

/* vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_MEMORY_CONFIG,    N_("Specify memory configuration")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_MEMORY_CONFIG_DA, "Angiv hukommelseskonfiguration"},
/* de */ {IDCLS_SPECIFY_MEMORY_CONFIG_DE, "Speicher Konfiguration definieren"},
/* fr */ {IDCLS_SPECIFY_MEMORY_CONFIG_FR, "Spécifier la configuration de la mémoire"},
/* hu */ {IDCLS_SPECIFY_MEMORY_CONFIG_HU, "Adja meg a memória konfigurációt"},
/* it */ {IDCLS_SPECIFY_MEMORY_CONFIG_IT, "Specifica la configurazione della memoria"},
/* ko */ {IDCLS_SPECIFY_MEMORY_CONFIG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_MEMORY_CONFIG_NL, "Geef geheugenconfiguratie"},
/* ru */ {IDCLS_SPECIFY_MEMORY_CONFIG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_MEMORY_CONFIG_SV, "Ange minneskonfiguration"},
/* tr */ {IDCLS_SPECIFY_MEMORY_CONFIG_TR, "Bellek konfigürasyonunu ayarlayýn"},
#endif

/* vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_ENABLE_VIC1112_IEEE488,    N_("Enable VIC-1112 IEEE488 interface")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_VIC1112_IEEE488_DA, "Aktivér VIC-1112-IEEE488-interface"},
/* de */ {IDCLS_ENABLE_VIC1112_IEEE488_DE, "VIC-1112 IEEE488 Schnittstelle aktivieren"},
/* fr */ {IDCLS_ENABLE_VIC1112_IEEE488_FR, "Activer l'interface VIC-1112 IEEE488"},
/* hu */ {IDCLS_ENABLE_VIC1112_IEEE488_HU, "VIC-1112 IEEE488 interfész engedélyezése"},
/* it */ {IDCLS_ENABLE_VIC1112_IEEE488_IT, "Attiva interfaccia IEEE488 VIC-1112"},
/* ko */ {IDCLS_ENABLE_VIC1112_IEEE488_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_VIC1112_IEEE488_NL, "Activeer VIC-1112 IEEE488 interface"},
/* ru */ {IDCLS_ENABLE_VIC1112_IEEE488_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_VIC1112_IEEE488_SV, "Aktivera VIC-1112-IEEE488-gränssnitt"},
/* tr */ {IDCLS_ENABLE_VIC1112_IEEE488_TR, "VIC-1112 IEEE488 arabirimini aktif et"},
#endif

/* vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_DISABLE_VIC1112_IEEE488,    N_("Disable VIC-1112 IEEE488 interface")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_VIC1112_IEEE488_DA, "Deaktivér VIC-1112-IEEE488-interface"},
/* de */ {IDCLS_DISABLE_VIC1112_IEEE488_DE, "VIC-1112 IEEE488 Schnittstelle deaktivieren"},
/* fr */ {IDCLS_DISABLE_VIC1112_IEEE488_FR, "Désactiver l'interface VIC-1112 IEEE488"},
/* hu */ {IDCLS_DISABLE_VIC1112_IEEE488_HU, "VIC-1112 IEEE488 interfész tiltása"},
/* it */ {IDCLS_DISABLE_VIC1112_IEEE488_IT, "Disattiva interfaccia IEEE488 VIC-1112"},
/* ko */ {IDCLS_DISABLE_VIC1112_IEEE488_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_VIC1112_IEEE488_NL, "VIC-1112 IEEE488 interface uitschakelen"},
/* ru */ {IDCLS_DISABLE_VIC1112_IEEE488_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_VIC1112_IEEE488_SV, "Inaktivera VIC-1112-IEEE488-gränssnitt"},
/* tr */ {IDCLS_DISABLE_VIC1112_IEEE488_TR, "VIC-1112 IEEE488 arabirimini pasifleþtir"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME,    N_("Specify 4/8/16K extension ROM name at $2000")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_DA, "Angiv navn for 4/8/16K-udviddelses-ROM på $2000"},
/* de */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_DE, "4/8/16K Erweiterungs ROM Datei Name für $2000 definieren"},
/* fr */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_FR, "Spécifier le nom de l'extension ROM 4/8/16K à $2000"},
/* hu */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_HU, "Adja meg a $2000 címû 4/8/16K ROM kiterjesztés nevét"},
/* it */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_IT, "Specifica il nome della ROM di estensione di 4/8/16K a $2000"},
/* ko */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_NL, "Geef de naam van het bestand voor de 4/8/16K ROM op $2000"},
/* ru */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_SV, "Ange namn för 4/8/16K-utöknings-ROM på $2000"},
/* tr */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_TR, "$2000 adresindeki 4/8/16K uzantýsý ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME,    N_("Specify 4/8/16K extension ROM name at $4000")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_DA, "Angiv navn for 4/8/16K-udviddelses-ROM på $4000"},
/* de */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_DE, "4/8/16K Erweiterungs ROM Datei Name für $4000 definieren"},
/* fr */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_FR, "Spécifier le nom de l'extension ROM 4/8/16K à $4000"},
/* hu */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_HU, "Adja meg a $4000 címû 4/8/16K ROM kiterjesztés nevét"},
/* it */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_IT, "Specifica il nome della ROM di estensione di 4/8/16K a $4000"},
/* ko */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_NL, "Geef de naam van het bestand voor de 4/8/16K ROM op $4000"},
/* ru */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_SV, "Ange namn för 4/8/16K-utöknings-ROM på $4000"},
/* tr */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_TR, "$4000 adresindeki 4/8/16K uzantýsý ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME,    N_("Specify 4/8/16K extension ROM name at $6000")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_DA, "Angiv navn for 4/8/16K-udviddelses-ROM på $6000"},
/* de */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_DE, "4/8/16K Erweiterungs ROM Datei Name für $6000 definieren"},
/* fr */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_FR, "Spécifier le nom de l'extension ROM 4/8/16K à $6000"},
/* hu */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_HU, "Adja meg a $6000 címû 4/8/16K ROM kiterjesztés nevét"},
/* it */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_IT, "Specifica il nome della ROM di estensione di 4/8/16K a $6000"},
/* ko */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_NL, "Geef de naam van het bestand voor de 4/8/16K ROM op $6000"},
/* ru */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_SV, "Ange namn för 4/8/16K-utöknings-ROM på $6000"},
/* tr */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_TR, "$6000 adresindeki 4/8/16K uzantýsý ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME,    N_("Specify 4/8K extension ROM name at $A000")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_DA, "Angiv navn for 4/8K-udviddelses-ROM på $A000"},
/* de */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_DE, "4/8/16K Erweiterungs ROM Datei Name für $A000 definieren"},
/* fr */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_FR, "Spécifier le nom de l'extension ROM 4/8K à $A000"},
/* hu */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_HU, "Adja meg a $A000 címû 4/8K ROM kiterjesztés nevét"},
/* it */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_IT, "Specifica il nome della ROM di estensione di 4/8K a $A000"},
/* ko */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_NL, "Geef de naam van het bestand voor de 4/8K ROM op $A000"},
/* ru */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_SV, "Ange namn för 4/8K-utöknings-ROM på $A000"},
/* tr */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_TR, "$A000 adresindeki 4/8K uzantýsý ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME,    N_("Specify 4K extension ROM name at $B000")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_DA, "Angiv navn for 4K-udviddelses-ROM på $B000"},
/* de */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_DE, "4/8/16K Erweiterungs ROM Datei Name für $B000 definieren"},
/* fr */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_FR, "Spécifier le nom de l'extension ROM 4K à $B000"},
/* hu */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_HU, "Adja meg a $B000 címû 4K ROM kiterjesztés nevét"},
/* it */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_IT, "Specifica il nome della ROM di estensione di 4 a $B000"},
/* ko */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_NL, "Geef de naam van het bestand voor de 4K ROM op $B000"},
/* ru */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_SV, "Ange namn för 4K-utöknings-ROM på $B000"},
/* tr */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_TR, "$B000 adresindeki 4K uzantýsý ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_GENERIC_ROM_NAME,    N_("Specify generic extension ROM name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_DA, "Angiv navn på standard-udviddelses-ROM"},
/* de */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_DE, "Generisches Erweiterungs ROM definieren"},
/* fr */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_HU, "Adja meg az általános ROM kiterjesztés nevét"},
/* it */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_IT, "Specifica il nome dell'estensione ROM generica"},
/* ko */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_NL, "Geef de naam van het bestand voor de algemene ROM"},
/* ru */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_SV, "Ange namn på generiskt utöknings-ROM"},
/* tr */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_TR, "Jenerik uzantý ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME,    N_("Specify Mega-Cart extension ROM name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_DA, "Angiv navn på MegaCart-udviddelses-ROM"},
/* de */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_DE, "Mega-Cart Erweiterungs ROM definieren"},
/* fr */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_HU, "Adja meg a Mega-Cart ROM kiterjesztés nevét"},
/* it */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_IT, "Specifica il nome dell'estensione ROM Mega-Cart"},
/* ko */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_NL, "Geef de naam van het bestand voor de Mega-Cart ROM"},
/* ru */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_SV, "Ange namn på Mega-Cart-utöknings-ROM"},
/* tr */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_TR, "Mega-Cart uzantýsý ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME,    N_("Specify Final Expansion extension ROM name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_DA, "Angiv navn på Final Expansion udviddelses-ROM"},
/* de */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_DE, "Name für Final Expansion Erweiterungs ROM definieren"},
/* fr */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_HU, "Adja meg a Final Expansion ROM kiterjesztés nevét"},
/* it */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_IT, "Specifica il nome dell'estensione ROM Final Expansion"},
/* ko */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_NL, "Geef de naam van het bestand voor de Final Expansion ROM"},
/* ru */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_SV, "Ange namn på Final Expansion utöknings-ROM"},
/* tr */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_TR, "Final Expansion uzantýsý ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME,    N_("Specify Vic Flash Plugin extension ROM name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_DA, "Angiv navn på Vic Flash Plugin udviddelses-ROM"},
/* de */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_DE, "Name für Vic Flash Plugin Erweiterungs ROM definieren"},
/* fr */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_IT, "Specifica il nome dell'estensione ROM Vic Flash Plugin"},
/* ko */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_NL, "Geef de naam van het bestand voor de Vic Flash Plugin ROM"},
/* ru */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_SV, "Ange namn på Vic Flash-insticksmodulutöknings-ROM"},
/* tr */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_TR, "Vic Flash Plugin uzantýsý ROM ismini belirt"},
#endif

/* vic20/cart/finalexpansion.c */
/* en */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK,    N_("Enable Final Expansion write back to ROM file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_DA, "Aktivér Final Expansion tilbageskrivning til ROM-fil"},
/* de */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_DE, "Final Expansion ROM Schreibzugriff aktivieren"},
/* fr */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_HU, "Final Expansion ROM fájlba visszaírás engedélyezése"},
/* it */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_IT, "Attiva write back per Final Expansion su file ROM"},
/* ko */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_NL, "Activeer terug schrijven naar ROM bestand voor Final Expansion"},
/* ru */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_SV, "Aktivera återskrivning till ROM-fil för Final Expansion"},
/* tr */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_TR, "Final Expansion ROM dosyasýna geri yazmayý aktif et"},
#endif

/* vic20/cart/finalexpansion.c */
/* en */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK,    N_("Disable Final Expansion write back to ROM file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_DA, "Deaktivér Final Expansion tilbageskrivning til ROM-fil"},
/* de */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_DE, "Final Expansion ROM Schreibzugriff deaktivieren"},
/* fr */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_HU, "Final Expansion ROM fájlba visszaírás tiltása"},
/* it */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_IT, "Disattiva write back per Final Expansion su file ROM"},
/* ko */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_NL, "Terug schrijven naar ROM bestand voor Final Expansion uitschakelen"},
/* ru */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_SV, "Inaktivera återskrivning till ROM-fil för Final Expansion"},
/* tr */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_TR, "Final Expansion ROM dosyasýna geri yazmayý pasifleþtir"},
#endif

/* vic20/cart/megacart.c */
/* en */ {IDCLS_SET_MEGACART_NVRAM_NAME,    N_("Set Mega-Cart NvRAM filename")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_MEGACART_NVRAM_NAME_DA, "Vælg Mega-Cart NvRAM filnavn"},
/* de */ {IDCLS_SET_MEGACART_NVRAM_NAME_DE, "Mega-Cart NvRAM Imagename definieren"},
/* fr */ {IDCLS_SET_MEGACART_NVRAM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_MEGACART_NVRAM_NAME_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_MEGACART_NVRAM_NAME_IT, "Imposta nome file NvRAM Mega-Cart"},
/* ko */ {IDCLS_SET_MEGACART_NVRAM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_MEGACART_NVRAM_NAME_NL, "Zet Mega-Cart NvRAM bestandsnaam"},
/* ru */ {IDCLS_SET_MEGACART_NVRAM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_MEGACART_NVRAM_NAME_SV, "Välj  Mega-Cart NvRAM-filnamn"},
/* tr */ {IDCLS_SET_MEGACART_NVRAM_NAME_TR, "Mega-Cart NvRAM dosyaismini gir"},
#endif

/* vic20/cart/megacart.c */
/* en */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE,    N_("Enable Mega-Cart NvRAM writeback")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_DA, "Aktivér Mega-Cart NvRAM tilbageskrivning"},
/* de */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_DE, "Mega-Cart NvRAM Rückschreiben aktivieren"},
/* fr */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_IT, "Write back NvRAM Mega-Cart"},
/* ko */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_NL, "Activeer Mega-Cart NvRAM terug schrijven"},
/* ru */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_SV, "Aktivera Mega-Cart NvRAM-återskrivning"},
/* tr */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_TR, "Mega-Cart NvRAM geri yazmayý aktif et"},
#endif

/* vic20/cart/megacart.c */
/* en */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE,    N_("Disable Mega-Cart NvRAM writeback")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_DA, "Deaktivér Mega-Cart NvRAM tilbageskrivning"},
/* de */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_DE, "Mega-Cart NvRAM Rückschreiben deaktivieren"},
/* fr */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_IT, "Disattiva write back su NvRAM Mega-Cart"},
/* ko */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_NL, "Mega-Cart NvRAM terug schrijven uitschakelen"},
/* ru */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_SV, "Inaktivera Mega-Cart NvRAM-återskrivning"},
/* tr */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_TR, "Mega-Cart NvRAM geri yazmayý pasifleþtir"},
#endif

/* vic20/cart/vic-fp.c */
/* en */ {IDCLS_ENABLE_VICFP_ROM_WRITE,    N_("Enable Vic Flash Plugin write back to ROM file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_VICFP_ROM_WRITE_DA, "Aktivér Vic Flash Plugin tilbageskrivning til ROM-fil"},
/* de */ {IDCLS_ENABLE_VICFP_ROM_WRITE_DE, "Vic Flash Plugin Rückschreiben auf ROM Datei aktivieren"},
/* fr */ {IDCLS_ENABLE_VICFP_ROM_WRITE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_VICFP_ROM_WRITE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_VICFP_ROM_WRITE_IT, "Attiva write back per Vic Flash Plugin su file ROM"},
/* ko */ {IDCLS_ENABLE_VICFP_ROM_WRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_VICFP_ROM_WRITE_NL, "Activeer terug schrijven naar ROM bestand voor Vic Flash Plugin"},
/* ru */ {IDCLS_ENABLE_VICFP_ROM_WRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_VICFP_ROM_WRITE_SV, "Aktivera återskrivning till ROM-fil för Vic Flash-insticksmodul"},
/* tr */ {IDCLS_ENABLE_VICFP_ROM_WRITE_TR, "Flash Plugin ROM dosyasýna geri yazmayý aktif et"},
#endif

/* vic20/cart/vic-fp.c */
/* en */ {IDCLS_DISABLE_VICFP_ROM_WRITE,    N_("Disable Vic Flash Plugin write back to ROM file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_VICFP_ROM_WRITE_DA, "Deaktivér Vic Flash Plugin tilbageskrivning til ROM-fil"},
/* de */ {IDCLS_DISABLE_VICFP_ROM_WRITE_DE, "Vic Flash Plugin Rückschreiben auf ROM Datei deaktivieren"},
/* fr */ {IDCLS_DISABLE_VICFP_ROM_WRITE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_VICFP_ROM_WRITE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_VICFP_ROM_WRITE_IT, "Disattiva write back per Vic Flash Plugin su file ROM"},
/* ko */ {IDCLS_DISABLE_VICFP_ROM_WRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_VICFP_ROM_WRITE_NL, "Terug schrijven naar ROM bestand voor Vic Flash Plugin uitschakelen"},
/* ru */ {IDCLS_DISABLE_VICFP_ROM_WRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_VICFP_ROM_WRITE_SV, "Inaktivera återskrivning till ROM-fil för Vic Flash-insticksmodul"},
/* tr */ {IDCLS_DISABLE_VICFP_ROM_WRITE_TR, "Flash Plugin ROM dosyasýna geri yazmayý pasifleþtir"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_BORDER_MODE,    N_("Set VIC-II border display mode (0: normal, 1: full, 2: debug)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_BORDER_MODE_DA, "Vælg VIC-II-rammevisningstilstand (0: normal, 1: fuld, 2: fejlsøgning)"},
/* de */ {IDCLS_SET_BORDER_MODE_DE, "VIC-II Rahmen Darstellung Modus (0: normal, 1: full, 2: debug)"},
/* fr */ {IDCLS_SET_BORDER_MODE_FR, "Régler le mode de bordure VIC-II (0: normal, 1: complet, 2: debug)"},
/* hu */ {IDCLS_SET_BORDER_MODE_HU, "VIC-II keret megjelenítési mód (0: normál, 1: teljes, 2: hibakeresés)"},
/* it */ {IDCLS_SET_BORDER_MODE_IT, "Imposta la modalità di visualizzazione del bordo del VIC-II (0: normale, 1: intero, 2: debug)"},
/* ko */ {IDCLS_SET_BORDER_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_BORDER_MODE_NL, "Zet VIC-II border weergavemodus (0: normaal, 1: volledig, 2: debug)"},
/* ru */ {IDCLS_SET_BORDER_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_BORDER_MODE_SV, "Välj VIC II-ramvisningsläge (0: normal, 1: full, 2: felsökning)"},
/* tr */ {IDCLS_SET_BORDER_MODE_TR, "VIC-II çerçeve gösterim modunu ayarlayýn (0: normal, 1: tam, 2: hata ayýklama)"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_ENABLE_SPRITE_BACKGROUND,    N_("Enable sprite-background collision registers")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SPRITE_BACKGROUND_DA, "Aktivér sprite-til-baggrunds-kollisionsregistre"},
/* de */ {IDCLS_ENABLE_SPRITE_BACKGROUND_DE, "Sprite-Hintergrund Kollisionen aktivieren"},
/* fr */ {IDCLS_ENABLE_SPRITE_BACKGROUND_FR, "Activer les registres de collisions de sprite avec arrière-plan"},
/* hu */ {IDCLS_ENABLE_SPRITE_BACKGROUND_HU, "Sprite-háttér ütközési regiszterek engedélyezése"},
/* it */ {IDCLS_ENABLE_SPRITE_BACKGROUND_IT, "Attiva registri di collisione sprite-sfondo"},
/* ko */ {IDCLS_ENABLE_SPRITE_BACKGROUND_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SPRITE_BACKGROUND_NL, "Activeer sprite-achtergrond botsing registers"},
/* ru */ {IDCLS_ENABLE_SPRITE_BACKGROUND_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SPRITE_BACKGROUND_SV, "Aktivera sprite-till-bakgrund-kollisionsregister"},
/* tr */ {IDCLS_ENABLE_SPRITE_BACKGROUND_TR, "Yaratýk-arka plan çarpýþma registerlarýný aktif et"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_DISABLE_SPRITE_BACKGROUND,    N_("Disable sprite-background collision registers")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SPRITE_BACKGROUND_DA, "Deaktivér sprite-til-baggrunds-kollisionsregistre"},
/* de */ {IDCLS_DISABLE_SPRITE_BACKGROUND_DE, "Sprite-Hintergrund Kollisionen deaktivieren"},
/* fr */ {IDCLS_DISABLE_SPRITE_BACKGROUND_FR, "Désactiver les registres de collisions de sprite avec arrière-plan"},
/* hu */ {IDCLS_DISABLE_SPRITE_BACKGROUND_HU, "Sprite-háttér ütközési regiszterek tiltása"},
/* it */ {IDCLS_DISABLE_SPRITE_BACKGROUND_IT, "Disattiva registri di collisione sprite-sfondo"},
/* ko */ {IDCLS_DISABLE_SPRITE_BACKGROUND_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SPRITE_BACKGROUND_NL, "Sprite-achtergrond botsing registers uitschakelen"},
/* ru */ {IDCLS_DISABLE_SPRITE_BACKGROUND_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SPRITE_BACKGROUND_SV, "Inaktivera sprite-till-bakgrund-kollisionsregister"},
/* tr */ {IDCLS_DISABLE_SPRITE_BACKGROUND_TR, "Yaratýk-arka plan çarpýþma registerlarýný pasifleþtir"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_ENABLE_SPRITE_SPRITE,    N_("Enable sprite-sprite collision registers")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SPRITE_SPRITE_DA, "Aktivér sprite-til-sprite-kollisionsregistre"},
/* de */ {IDCLS_ENABLE_SPRITE_SPRITE_DE, "Sprite-Sprite Kollisionen aktivieren"},
/* fr */ {IDCLS_ENABLE_SPRITE_SPRITE_FR, "Activer les registres de collisions de sprite avec sprite"},
/* hu */ {IDCLS_ENABLE_SPRITE_SPRITE_HU, "Sprite-sprite ütközési regiszterek engedélyezése"},
/* it */ {IDCLS_ENABLE_SPRITE_SPRITE_IT, "Attiva registri di collisione sprite-sprite"},
/* ko */ {IDCLS_ENABLE_SPRITE_SPRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SPRITE_SPRITE_NL, "Activeer sprite-sprite botsing registers"},
/* ru */ {IDCLS_ENABLE_SPRITE_SPRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SPRITE_SPRITE_SV, "Aktivera sprite-till-sprite-kollisionsregister"},
/* tr */ {IDCLS_ENABLE_SPRITE_SPRITE_TR, "Yaratýk-yaratýk çarpýþma registerlarýný aktif et"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_DISABLE_SPRITE_SPRITE,    N_("Disable sprite-sprite collision registers")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SPRITE_SPRITE_DA, "Deaktivér sprite-til-sprite-kollisionsregistre"},
/* de */ {IDCLS_DISABLE_SPRITE_SPRITE_DE, "Sprite-Sprite Kollisionen deaktivieren"},
/* fr */ {IDCLS_DISABLE_SPRITE_SPRITE_FR, "Désactiver les registres de collisions de sprite avec sprite"},
/* hu */ {IDCLS_DISABLE_SPRITE_SPRITE_HU, "Sprite-sprite ütközési regiszterek tiltása"},
/* it */ {IDCLS_DISABLE_SPRITE_SPRITE_IT, "Disattiva registri di collisione sprite-sprite"},
/* ko */ {IDCLS_DISABLE_SPRITE_SPRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SPRITE_SPRITE_NL, "Sprite-sprite botsing registers uitschakelen"},
/* ru */ {IDCLS_DISABLE_SPRITE_SPRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SPRITE_SPRITE_SV, "Inaktivera sprite-till-sprite-kollisionsregister"},
/* tr */ {IDCLS_DISABLE_SPRITE_SPRITE_TR, "Yaratýk-yaratýk çarpýþma registerlarýný pasifleþtir"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_USE_NEW_LUMINANCES,    N_("Use new luminances")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_NEW_LUMINANCES_DA, "Brug nye lysstyrker"},
/* de */ {IDCLS_USE_NEW_LUMINANCES_DE, "Neue Helligkeitsemulation"},
/* fr */ {IDCLS_USE_NEW_LUMINANCES_FR, "Utiliser les nouvelles luminescences"},
/* hu */ {IDCLS_USE_NEW_LUMINANCES_HU, "Az új fényerõket használja"},
/* it */ {IDCLS_USE_NEW_LUMINANCES_IT, "Usa nuove luminanze"},
/* ko */ {IDCLS_USE_NEW_LUMINANCES_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_NEW_LUMINANCES_NL, "Gebruik nieuwe kleuren"},
/* ru */ {IDCLS_USE_NEW_LUMINANCES_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_NEW_LUMINANCES_SV, "Använd nya ljusstyrkor"},
/* tr */ {IDCLS_USE_NEW_LUMINANCES_TR, "Yeni parlaklýklarý kullan"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_USE_OLD_LUMINANCES,    N_("Use old luminances")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_OLD_LUMINANCES_DA, "Brug gamle lysstyrker"},
/* de */ {IDCLS_USE_OLD_LUMINANCES_DE, "Alte Helligkeitsemulation"},
/* fr */ {IDCLS_USE_OLD_LUMINANCES_FR, "Utiliser les anciennes luminescences"},
/* hu */ {IDCLS_USE_OLD_LUMINANCES_HU, "A régi fényerõket használja"},
/* it */ {IDCLS_USE_OLD_LUMINANCES_IT, "Usa vecchie luminanze"},
/* ko */ {IDCLS_USE_OLD_LUMINANCES_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_OLD_LUMINANCES_NL, "Gebruik oude kleuren"},
/* ru */ {IDCLS_USE_OLD_LUMINANCES_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_OLD_LUMINANCES_SV, "Använd gamla ljusstyrkor"},
/* tr */ {IDCLS_USE_OLD_LUMINANCES_TR, "Eski parlaklýklarý kullan"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DOUBLE_SIZE,    N_("Enable double size")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DOUBLE_SIZE_DA, "Aktivér dobbelt størrelse"},
/* de */ {IDCLS_ENABLE_DOUBLE_SIZE_DE, "Doppelte Größe aktivieren"},
/* fr */ {IDCLS_ENABLE_DOUBLE_SIZE_FR, "Taille double"},
/* hu */ {IDCLS_ENABLE_DOUBLE_SIZE_HU, "Dupla méret engedélyezése"},
/* it */ {IDCLS_ENABLE_DOUBLE_SIZE_IT, "Attiva dimensione doppia"},
/* ko */ {IDCLS_ENABLE_DOUBLE_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DOUBLE_SIZE_NL, "Activeer dubbele grootte"},
/* ru */ {IDCLS_ENABLE_DOUBLE_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DOUBLE_SIZE_SV, "Aktivera dubbel storlek"},
/* tr */ {IDCLS_ENABLE_DOUBLE_SIZE_TR, "Çift boyutu aktif et"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DOUBLE_SIZE,    N_("Disable double size")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DOUBLE_SIZE_DA, "Deaktivér dobbelt størrelse"},
/* de */ {IDCLS_DISABLE_DOUBLE_SIZE_DE, "Doppelte Größe deaktivieren"},
/* fr */ {IDCLS_DISABLE_DOUBLE_SIZE_FR, "Taille normale"},
/* hu */ {IDCLS_DISABLE_DOUBLE_SIZE_HU, "Dupla méret tiltása"},
/* it */ {IDCLS_DISABLE_DOUBLE_SIZE_IT, "Disattiva dimensione doppia"},
/* ko */ {IDCLS_DISABLE_DOUBLE_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DOUBLE_SIZE_NL, "Dubbele grootte uitschakelen"},
/* ru */ {IDCLS_DISABLE_DOUBLE_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DOUBLE_SIZE_SV, "Inaktivera dubbel storlek"},
/* tr */ {IDCLS_DISABLE_DOUBLE_SIZE_TR, "Çift boyutu pasifleþtir"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DOUBLE_SCAN,    N_("Enable double scan")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DOUBLE_SCAN_DA, "Aktivér dobbelt-skan"},
/* de */ {IDCLS_ENABLE_DOUBLE_SCAN_DE, "Doppelt Scan aktivieren"},
/* fr */ {IDCLS_ENABLE_DOUBLE_SCAN_FR, "Activer le mode double scan"},
/* hu */ {IDCLS_ENABLE_DOUBLE_SCAN_HU, "Dupla pásztázás engedélyezése"},
/* it */ {IDCLS_ENABLE_DOUBLE_SCAN_IT, "Attiva scansione doppia"},
/* ko */ {IDCLS_ENABLE_DOUBLE_SCAN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DOUBLE_SCAN_NL, "Activeer dubbele scan"},
/* ru */ {IDCLS_ENABLE_DOUBLE_SCAN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DOUBLE_SCAN_SV, "Aktivera dubbelskanning"},
/* tr */ {IDCLS_ENABLE_DOUBLE_SCAN_TR, "Çift taramayý aktif et"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DOUBLE_SCAN,    N_("Disable double scan")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DOUBLE_SCAN_DA, "Deaktivér dobbelt-skan"},
/* de */ {IDCLS_DISABLE_DOUBLE_SCAN_DE, "Doppelt Scan deaktivieren"},
/* fr */ {IDCLS_DISABLE_DOUBLE_SCAN_FR, "Désactiver le mode double scan"},
/* hu */ {IDCLS_DISABLE_DOUBLE_SCAN_HU, "Dupla pásztázás tiltása"},
/* it */ {IDCLS_DISABLE_DOUBLE_SCAN_IT, "Disattiva scansione doppia"},
/* ko */ {IDCLS_DISABLE_DOUBLE_SCAN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DOUBLE_SCAN_NL, "Dubbele scan uitschakelen"},
/* ru */ {IDCLS_DISABLE_DOUBLE_SCAN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DOUBLE_SCAN_SV, "Inaktivera dubbelskanning"},
/* tr */ {IDCLS_DISABLE_DOUBLE_SCAN_TR, "Çift taramayý pasifleþtir"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_ENABLE_HARDWARE_SCALING,    N_("Enable hardware scaling")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_HARDWARE_SCALING_DA, "Aktivér hardware-skalering"},
/* de */ {IDCLS_ENABLE_HARDWARE_SCALING_DE, "Hardwareunterstützung für Skalierung aktivieren"},
/* fr */ {IDCLS_ENABLE_HARDWARE_SCALING_FR, "Activer le \"scaling\" matériel"},
/* hu */ {IDCLS_ENABLE_HARDWARE_SCALING_HU, "Hardver átméretezés engedélyezése"},
/* it */ {IDCLS_ENABLE_HARDWARE_SCALING_IT, "Attiva hardware scaling"},
/* ko */ {IDCLS_ENABLE_HARDWARE_SCALING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_HARDWARE_SCALING_NL, "Activeer hardwareschaling"},
/* ru */ {IDCLS_ENABLE_HARDWARE_SCALING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_HARDWARE_SCALING_SV, "Aktivera maskinvaruskalning"},
/* tr */ {IDCLS_ENABLE_HARDWARE_SCALING_TR, "Donaným destekli ölçeklendirmeyi aktif et"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_DISABLE_HARDWARE_SCALING,    N_("Disable hardware scaling")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_HARDWARE_SCALING_DA, "Deaktivér hardware-skalering"},
/* de */ {IDCLS_DISABLE_HARDWARE_SCALING_DE, "Hardwareunterstützung für Skalierung deaktivieren"},
/* fr */ {IDCLS_DISABLE_HARDWARE_SCALING_FR, "Désactiver le \"scaling\" matériel"},
/* hu */ {IDCLS_DISABLE_HARDWARE_SCALING_HU, "Hardver átméretezés tiltása"},
/* it */ {IDCLS_DISABLE_HARDWARE_SCALING_IT, "Disattiva hardware scaling"},
/* ko */ {IDCLS_DISABLE_HARDWARE_SCALING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_HARDWARE_SCALING_NL, "Hardwareschaling uitschakelen"},
/* ru */ {IDCLS_DISABLE_HARDWARE_SCALING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_HARDWARE_SCALING_SV, "Inaktivera maskinvaruskalning"},
/* tr */ {IDCLS_DISABLE_HARDWARE_SCALING_TR, "Donaným destekli ölçeklendirmeyi pasifleþtir"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_ENABLE_SCALE2X,    N_("Enable Scale2x")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SCALE2X_DA, "Aktivér Scale2x"},
/* de */ {IDCLS_ENABLE_SCALE2X_DE, "Scale2x aktivieren"},
/* fr */ {IDCLS_ENABLE_SCALE2X_FR, "Activer Scale2x"},
/* hu */ {IDCLS_ENABLE_SCALE2X_HU, "Élsimítás engedélyezése"},
/* it */ {IDCLS_ENABLE_SCALE2X_IT, "Attiva Scale2x"},
/* ko */ {IDCLS_ENABLE_SCALE2X_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SCALE2X_NL, "Activeer Schaal2x"},
/* ru */ {IDCLS_ENABLE_SCALE2X_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SCALE2X_SV, "Aktivera Scale2x"},
/* tr */ {IDCLS_ENABLE_SCALE2X_TR, "2x Geniþlet'i aktif et"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_DISABLE_SCALE2X,    N_("Disable Scale2x")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SCALE2X_DA, "Deaktivér Scale2x"},
/* de */ {IDCLS_DISABLE_SCALE2X_DE, "Scale2x deaktivieren"},
/* fr */ {IDCLS_DISABLE_SCALE2X_FR, "Désactiver Scale2x"},
/* hu */ {IDCLS_DISABLE_SCALE2X_HU, "Élsimítás tiltása"},
/* it */ {IDCLS_DISABLE_SCALE2X_IT, "Disattiva Scale2x"},
/* ko */ {IDCLS_DISABLE_SCALE2X_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SCALE2X_NL, "Schaal2x uitschakelen"},
/* ru */ {IDCLS_DISABLE_SCALE2X_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SCALE2X_SV, "Inaktivera Scale2x"},
/* tr */ {IDCLS_DISABLE_SCALE2X_TR, "2x Geniþlet'i pasifleþtir"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_USE_INTERNAL_CALC_PALETTE,    N_("Use an internal calculated palette")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_INTERNAL_CALC_PALETTE_DA, "Brug en internt beregnet palette"},
/* de */ {IDCLS_USE_INTERNAL_CALC_PALETTE_DE, "Benutze intern berechnete Palette"},
/* fr */ {IDCLS_USE_INTERNAL_CALC_PALETTE_FR, "Utiliser une palette interne calculée"},
/* hu */ {IDCLS_USE_INTERNAL_CALC_PALETTE_HU, "Belsõleg számított paletta használata"},
/* it */ {IDCLS_USE_INTERNAL_CALC_PALETTE_IT, "Usa una palette interna calcolata"},
/* ko */ {IDCLS_USE_INTERNAL_CALC_PALETTE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_INTERNAL_CALC_PALETTE_NL, "Gebruik een intern berekend kleurenpalet"},
/* ru */ {IDCLS_USE_INTERNAL_CALC_PALETTE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_INTERNAL_CALC_PALETTE_SV, "Använd en internt beräknad palett"},
/* tr */ {IDCLS_USE_INTERNAL_CALC_PALETTE_TR, "Dahili hesaplanmýþ bir palet kullan"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_USE_EXTERNAL_FILE_PALETTE,    N_("Use an external palette (file)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_DA, "Brug en ekstern palette (fil)"},
/* de */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_DE, "Benutze externe Palette (Datei)"},
/* fr */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_FR, "Utiliser une palette externe (fichier)"},
/* hu */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_HU, "Külsõ paletta használata (fájl)"},
/* it */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_IT, "Usa una palette esterna (file)"},
/* ko */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_NL, "Gebruik een extern kleurenpalet (bestand)"},
/* ru */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_SV, "Använd en extern palett (fil)"},
/* tr */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_TR, "Harici bir palet (dosyadan) kullan"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME,    N_("Specify name of file of external palette")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_DA, "Angiv filnavn for ekstern palette"},
/* de */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_DE, "Dateiname für externe Palette definieren"},
/* fr */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_FR, "Spécifier le nom du fichier de la palette externe"},
/* hu */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_HU, "Adja meg a külsõ paletta nevét"},
/* it */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_IT, "Specifica il nome del file della palette esterna"},
/* ko */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_NL, "Geef de naam van het extern kleurenpaletbestand"},
/* ru */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_SV, "Ange namn på fil för extern palett"},
/* tr */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_TR, "Harici palet dosyasýnýn ismini belirt"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_P_DEVICE,    N_("<device>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_DEVICE_DA, "<enhed>"},
/* de */ {IDCLS_P_DEVICE_DE, "<Gerät>"},
/* fr */ {IDCLS_P_DEVICE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_DEVICE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_DEVICE_IT, "<dispositivo>"},
/* ko */ {IDCLS_P_DEVICE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_DEVICE_NL, "<apparaat>"},
/* ru */ {IDCLS_P_DEVICE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_DEVICE_SV, "<enhet>"},
/* tr */ {IDCLS_P_DEVICE_TR, "<aygýt>"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_SELECT_FULLSCREEN_DEVICE,    N_("Select fullscreen device")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SELECT_FULLSCREEN_DEVICE_DA, "Angiv fuldskærmsenhed"},
/* de */ {IDCLS_SELECT_FULLSCREEN_DEVICE_DE, "Vollbild Gerät auswählen"},
/* fr */ {IDCLS_SELECT_FULLSCREEN_DEVICE_FR, "Sélectionner le périphérique plein écran"},
/* hu */ {IDCLS_SELECT_FULLSCREEN_DEVICE_HU, "Teljesképernyõs eszköz kiválasztása"},
/* it */ {IDCLS_SELECT_FULLSCREEN_DEVICE_IT, "Seleziona il dispositivo per la visualizzazione a schermo intero"},
/* ko */ {IDCLS_SELECT_FULLSCREEN_DEVICE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SELECT_FULLSCREEN_DEVICE_NL, "Selecteer volschermapparaat"},
/* ru */ {IDCLS_SELECT_FULLSCREEN_DEVICE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SELECT_FULLSCREEN_DEVICE_SV, "Ange fullskärmsenhet"},
/* tr */ {IDCLS_SELECT_FULLSCREEN_DEVICE_TR, "Tam ekran aygýtý seç"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_P_MODE,    N_("<Mode>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_MODE_DA, "<Tilstand>"},
/* de */ {IDCLS_P_MODE_DE, "<Modus>"},
/* fr */ {IDCLS_P_MODE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_MODE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_MODE_IT, "<Modalità>"},
/* ko */ {IDCLS_P_MODE_KO, "<¸ðµå>"},
/* nl */ {IDCLS_P_MODE_NL, "<Modus>"},
/* ru */ {IDCLS_P_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_MODE_SV, "<Läge>"},
/* tr */ {IDCLS_P_MODE_TR, "<Mod>"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_SELECT_FULLSCREEN_MODE,    N_("Select fullscreen mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SELECT_FULLSCREEN_MODE_DA, "Aktivér fuldskærms-tilstand"},
/* de */ {IDCLS_SELECT_FULLSCREEN_MODE_DE, "Vollbild Modus wählen"},
/* fr */ {IDCLS_SELECT_FULLSCREEN_MODE_FR, "Sélectionner le mode plein écran"},
/* hu */ {IDCLS_SELECT_FULLSCREEN_MODE_HU, "Teljes képernyõs mód kiválasztása"},
/* it */ {IDCLS_SELECT_FULLSCREEN_MODE_IT, "Seleziona modalità a schermo intero"},
/* ko */ {IDCLS_SELECT_FULLSCREEN_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SELECT_FULLSCREEN_MODE_NL, "Activeer volschermmodus"},
/* ru */ {IDCLS_SELECT_FULLSCREEN_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SELECT_FULLSCREEN_MODE_SV, "Aktivera fullskärmsläge"},
/* tr */ {IDCLS_SELECT_FULLSCREEN_MODE_TR, "Tam ekran modu seç"},
#endif

/* aciacore.c */
/* en */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE,    N_("Specify RS232 device this ACIA should work on")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_DA, "Angiv RS232-enhed denne ACIA skal bruge"},
/* de */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_DE, "RS232 Gerät für welches ACIA funktionieren soll ist zu spezifizieren"},
/* fr */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_FR, "Spécifier le périphérique RS232 sur lequel cet ACIA doit fonctionner"},
/* hu */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_HU, "Adja meg az RS232-es egységet, amivel az ACIA mûködni fog"},
/* it */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_IT, "Specifica il dispositivo RS232 con il quale questa ACIA dovrebbe funzionare"},
/* ko */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_NL, "Geef het RS232 apparaat waarmee deze ACIA moet werken"},
/* ru */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_SV, "Ange RS232-enhet denna ACIA skall arbeta på"},
/* tr */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_TR, "Bu ACIA'in çalýþmasý gereken RS232 aygýtýný belirt"},
#endif

/* attach.c */
/* en */ {IDCLS_SET_DEVICE_TYPE_8,    N_("Set device type for device #8 (0: NONE, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK DEVICE)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DEVICE_TYPE_8_DA, "Vælg type for enhed #8 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOKENHED)"},
/* de */ {IDCLS_SET_DEVICE_TYPE_8_DE, "Geräte Typ für Gerät #8 (0: Kein, 1: Dateisystem, 2: OpenCBM, 3: Block Gerät)"},
/* fr */ {IDCLS_SET_DEVICE_TYPE_8_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_DEVICE_TYPE_8_HU, "Adja meg a #8-es egység típusát (0: Nincs, 1: fájlrendszer, 2: OPENCBM, 3 blokk eszköz)"},
/* it */ {IDCLS_SET_DEVICE_TYPE_8_IT, "Imposta il tipo di periferica #8 (0 NESSUNA, 1: FILESYSTEM, 2: OPENCBM, 3: DISPOSITIVO A BLOCCHI)"},
/* ko */ {IDCLS_SET_DEVICE_TYPE_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DEVICE_TYPE_8_NL, "Zet het apparaatsoort voor apparaat #8 (0: GEEN, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK APPARAAT)"},
/* ru */ {IDCLS_SET_DEVICE_TYPE_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DEVICE_TYPE_8_SV, "Ställ in enhetstyp för enhet 8 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOCKENHET)"},
/* tr */ {IDCLS_SET_DEVICE_TYPE_8_TR, "Aygýt #8 için aygýt tipini belirt (0: YOK, 1: DOSYASÝSTEMÝ, 2: OPENCBM, 3: BLOK AYIGTI)"},
#endif

/* attach.c */
/* en */ {IDCLS_SET_DEVICE_TYPE_9,    N_("Set device type for device #9 (0: NONE, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK DEVICE)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DEVICE_TYPE_9_DA, "Vælg type for enhed #9 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOKENHED)"},
/* de */ {IDCLS_SET_DEVICE_TYPE_9_DE, "Geräte Typ für Gerät #9 (0: Kein, 1: Dateisystem, 2: OpenCBM, 3: Block Gerät)"},
/* fr */ {IDCLS_SET_DEVICE_TYPE_9_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_DEVICE_TYPE_9_HU, "Adja meg a #9-es egység típusát (0: Nincs, 1: fájlrendszer, 2: OPENCBM, 3: blokk eszköz)"},
/* it */ {IDCLS_SET_DEVICE_TYPE_9_IT, "Imposta il tipo di periferica #9 (0 NESSUNA, 1: FILESYSTEM, 2: OPENCBM, 3: DISPOSITIVO A BLOCCHI)"},
/* ko */ {IDCLS_SET_DEVICE_TYPE_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DEVICE_TYPE_9_NL, "Zet het apparaatsoort voor apparaat #9 (0: GEEN, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK APPARAAT)"},
/* ru */ {IDCLS_SET_DEVICE_TYPE_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DEVICE_TYPE_9_SV, "Ställ in enhetstyp för enhet 9 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOCKENHET)"},
/* tr */ {IDCLS_SET_DEVICE_TYPE_9_TR, "Aygýt #9 için aygýt tipini belirt (0: YOK, 1: DOSYASÝSTEMÝ, 2: OPENCBM, 3: BLOK AYIGTI)"},
#endif

/* attach.c */
/* en */ {IDCLS_SET_DEVICE_TYPE_10,    N_("Set device type for device #10 (0: NONE, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK DEVICE)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DEVICE_TYPE_10_DA, "Vælg type for enhed #10 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOKENHED)"},
/* de */ {IDCLS_SET_DEVICE_TYPE_10_DE, "Geräte Typ für Gerät #10 (0: Kein, 1: Dateisystem, 2: OpenCBM, 3: Block Gerät)"},
/* fr */ {IDCLS_SET_DEVICE_TYPE_10_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_DEVICE_TYPE_10_HU, "Adja meg a #10-es egység típusát (0: Nincs, 1: fájlrendszer, 2: OPENVMB, 3: blokk eszköz)"},
/* it */ {IDCLS_SET_DEVICE_TYPE_10_IT, "Imposta il tipo di periferica #10 (0 NESSUNA, 1: FILESYSTEM, 2: OPENCBM, 3: DISPOSITIVO A BLOCCHI)"},
/* ko */ {IDCLS_SET_DEVICE_TYPE_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DEVICE_TYPE_10_NL, "Zet het apparaatsoort voor apparaat #10 (0: GEEN, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK APPARAAT)"},
/* ru */ {IDCLS_SET_DEVICE_TYPE_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DEVICE_TYPE_10_SV, "Ställ in enhetstyp för enhet 10 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOCKENHET)"},
/* tr */ {IDCLS_SET_DEVICE_TYPE_10_TR, "Aygýt #10 için aygýt tipini belirt (0: YOK, 1: DOSYASÝSTEMÝ, 2: OPENCBM, 3: BLOK AYIGTI)"},
#endif

/* attach.c */
/* en */ {IDCLS_SET_DEVICE_TYPE_11,    N_("Set device type for device #11 (0: NONE, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK DEVICE)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DEVICE_TYPE_11_DA, "Vælg type for enhed #11 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOKENHED)"},
/* de */ {IDCLS_SET_DEVICE_TYPE_11_DE, "Geräte Typ für Gerät #11 (0: Kein, 1: Dateisystem, 2: OpenCBM, 3: Block Gerät)"},
/* fr */ {IDCLS_SET_DEVICE_TYPE_11_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_DEVICE_TYPE_11_HU, "Adja meg a #11-es egység típusát (0: Nincs, 1: fájlrendszer, 2: OPENCBM, 3: blokk eszköz)"},
/* it */ {IDCLS_SET_DEVICE_TYPE_11_IT, "Imposta il tipo di periferica #11 (0 NESSUNA, 1: FILESYSTEM, 2: OPENCBM, 3: DISPOSITIVO A BLOCCHI)"},
/* ko */ {IDCLS_SET_DEVICE_TYPE_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DEVICE_TYPE_11_NL, "Zet het apparaatsoort voor apparaat #11 (0: GEEN, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK APPARAAT)"},
/* ru */ {IDCLS_SET_DEVICE_TYPE_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DEVICE_TYPE_11_SV, "Ställ in enhetstyp för enhet 11 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOCKENHET)"},
/* tr */ {IDCLS_SET_DEVICE_TYPE_11_TR, "Aygýt #11 için aygýt tipini belirt (0: YOK, 1: DOSYASÝSTEMÝ, 2: OPENCBM, 3: BLOK AYIGTI)"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_ONLY_8,    N_("Attach disk image for drive #8 read only")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_ONLY_8_DA, "Tilslut disk-image til drev #8 skrivebeskyttet"},
/* de */ {IDCLS_ATTACH_READ_ONLY_8_DE, "Disk Image als Laufwerk #8 benutzen (schreibgeschützt)"},
/* fr */ {IDCLS_ATTACH_READ_ONLY_8_FR, "Charger une image de disque pour le lecteur #8 en lecture seule"},
/* hu */ {IDCLS_ATTACH_READ_ONLY_8_HU, "Csak olvasható képmás csatolása a #8-as lemezegységhez"},
/* it */ {IDCLS_ATTACH_READ_ONLY_8_IT, "Seleziona immagine del disco per il drive #8 in sola lettura"},
/* ko */ {IDCLS_ATTACH_READ_ONLY_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_ONLY_8_NL, "Koppel schijfbestand voor drive #8 als alleen-lezen"},
/* ru */ {IDCLS_ATTACH_READ_ONLY_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_ONLY_8_SV, "Anslut diskettavbildningsfil för enhet 8 med skrivskydd"},
/* tr */ {IDCLS_ATTACH_READ_ONLY_8_TR, "Sürücü #8 için disk imajýný salt okunur olarak yerleþtir"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_WRITE_8,    N_("Attach disk image for drive #8 read write (if possible)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_WRITE_8_DA, "Tilslut disk-image til drev #8 skrivbar (hvis muligt)"},
/* de */ {IDCLS_ATTACH_READ_WRITE_8_DE, "Disk Image als Laufwerk #8 benutzen (Schreibzugriff, wenn möglich)"},
/* fr */ {IDCLS_ATTACH_READ_WRITE_8_FR, "Charger une image de disque pour le lecteur #8 en lecture-écriture (si possible)"},
/* hu */ {IDCLS_ATTACH_READ_WRITE_8_HU, "Írható-olvasható képmás csatolása a #8-as lemezegységhez"},
/* it */ {IDCLS_ATTACH_READ_WRITE_8_IT, "Seleziona immagine del disco per il drive #8 in lettura/scrittura (se possibile)"},
/* ko */ {IDCLS_ATTACH_READ_WRITE_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_WRITE_8_NL, "Koppel schijfbestand voor drive #8 als schrijfbaar (indien mogelijk)"},
/* ru */ {IDCLS_ATTACH_READ_WRITE_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_WRITE_8_SV, "Anslut diskettavbildningsfil för enhet 8 skrivbar (om möjligt)"},
/* tr */ {IDCLS_ATTACH_READ_WRITE_8_TR, "Sürücü #8 için disk imajýný okunur/yazýlýr olarak yerleþtir (mümkünse)"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_ONLY_9,    N_("Attach disk image for drive #9 read only")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_ONLY_9_DA, "Tilslut disk-image til drev #9 skrivebeskyttet"},
/* de */ {IDCLS_ATTACH_READ_ONLY_9_DE, "Disk Image als Laufwerk #9 benutzen (schreibgeschützt)"},
/* fr */ {IDCLS_ATTACH_READ_ONLY_9_FR, "Charger une image de disque pour le lecteur #9 en lecture seule"},
/* hu */ {IDCLS_ATTACH_READ_ONLY_9_HU, "Csak olvasható képmás csatolása a #9-es lemezegységhez"},
/* it */ {IDCLS_ATTACH_READ_ONLY_9_IT, "Seleziona immagine del disco per il drive #9 in sola lettura"},
/* ko */ {IDCLS_ATTACH_READ_ONLY_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_ONLY_9_NL, "Koppel schijfbestand voor drive #9 als alleen-lezen"},
/* ru */ {IDCLS_ATTACH_READ_ONLY_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_ONLY_9_SV, "Anslut diskettavbildningsfil för enhet 9 med skrivskydd"},
/* tr */ {IDCLS_ATTACH_READ_ONLY_9_TR, "Sürücü #9 için disk imajýný salt okunur olarak yerleþtir"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_WRITE_9,    N_("Attach disk image for drive #9 read write (if possible)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_WRITE_9_DA, "Tilslut disk-image til drev #9 skrivbar (hvis muligt)"},
/* de */ {IDCLS_ATTACH_READ_WRITE_9_DE, "Disk Image als Laufwerk #9 benutzen (Schreibzugriff, wenn möglich)"},
/* fr */ {IDCLS_ATTACH_READ_WRITE_9_FR, "Charger une image de disque pour le lecteur #9 en lecture-écriture (si possible)"},
/* hu */ {IDCLS_ATTACH_READ_WRITE_9_HU, "Írható-olvasható képmás csatolása a #9-es lemezegységhez"},
/* it */ {IDCLS_ATTACH_READ_WRITE_9_IT, "Seleziona immagine del disco per il drive #9 in lettura/scrittura (se possibile)"},
/* ko */ {IDCLS_ATTACH_READ_WRITE_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_WRITE_9_NL, "Koppel schijfbestand voor drive #9 als schrijfbaar (indien mogelijk)"},
/* ru */ {IDCLS_ATTACH_READ_WRITE_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_WRITE_9_SV, "Anslut diskettavbildningsfil för enhet 9 skrivbar (om möjligt)"},
/* tr */ {IDCLS_ATTACH_READ_WRITE_9_TR, "Sürücü #9 için disk imajýný okunur/yazýlýr olarak yerleþtir (mümkünse)"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_ONLY_10,    N_("Attach disk image for drive #10 read only")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_ONLY_10_DA, "Tilslut disk-image til drev #10 skrivebeskyttet"},
/* de */ {IDCLS_ATTACH_READ_ONLY_10_DE, "Disk Image als Laufwerk #10 benutzen (schreibgeschützt)"},
/* fr */ {IDCLS_ATTACH_READ_ONLY_10_FR, "Charger une image de disque pour le lecteur #10 en lecture seule"},
/* hu */ {IDCLS_ATTACH_READ_ONLY_10_HU, "Csak olvasható képmás csatolása a #10-es lemezegységhez"},
/* it */ {IDCLS_ATTACH_READ_ONLY_10_IT, "Seleziona immagine del disco per il drive #10 in sola lettura"},
/* ko */ {IDCLS_ATTACH_READ_ONLY_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_ONLY_10_NL, "Koppel schijfbestand voor drive #10 als alleen-lezen"},
/* ru */ {IDCLS_ATTACH_READ_ONLY_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_ONLY_10_SV, "Anslut diskettavbildningsfil för enhet 10 med skrivskydd"},
/* tr */ {IDCLS_ATTACH_READ_ONLY_10_TR, "Sürücü #10 için disk imajýný salt okunur olarak yerleþtir"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_WRITE_10,    N_("Attach disk image for drive #10 read write (if possible)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_WRITE_10_DA, "Tilslut disk-image til drev #10 skrivbar (hvis muligt)"},
/* de */ {IDCLS_ATTACH_READ_WRITE_10_DE, "Disk Image als Laufwerk #10 benutzen (Schreibzugriff, wenn möglich)"},
/* fr */ {IDCLS_ATTACH_READ_WRITE_10_FR, "Charger une image de disque pour le lecteur #10 en lecture-écriture (si possible)"},
/* hu */ {IDCLS_ATTACH_READ_WRITE_10_HU, "Írható-olvasható képmás csatolása a #10-es lemezegységhez"},
/* it */ {IDCLS_ATTACH_READ_WRITE_10_IT, "Seleziona immagine del disco per il drive #10 in lettura/scrittura (se possibile)"},
/* ko */ {IDCLS_ATTACH_READ_WRITE_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_WRITE_10_NL, "Koppel schijfbestand voor drive #10 als schrijfbaar (indien mogelijk)"},
/* ru */ {IDCLS_ATTACH_READ_WRITE_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_WRITE_10_SV, "Anslut diskettavbildningsfil för enhet 10 skrivbar (om möjligt)"},
/* tr */ {IDCLS_ATTACH_READ_WRITE_10_TR, "Sürücü #10 için disk imajýný okunur/yazýlýr olarak yerleþtir (mümkünse)"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_ONLY_11,    N_("Attach disk image for drive #11 read only")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_ONLY_11_DA, "Tilslut disk-image til drev #11 skrivebeskyttet"},
/* de */ {IDCLS_ATTACH_READ_ONLY_11_DE, "Disk Image als Laufwerk #11 benutzen (schreibgeschützt)"},
/* fr */ {IDCLS_ATTACH_READ_ONLY_11_FR, "Charger une image de disque pour le lecteur #11 en lecture seule"},
/* hu */ {IDCLS_ATTACH_READ_ONLY_11_HU, "Csak olvasható képmás csatolása a #11-es lemezegységhez"},
/* it */ {IDCLS_ATTACH_READ_ONLY_11_IT, "Seleziona immagine del disco per il drive #11 in sola lettura"},
/* ko */ {IDCLS_ATTACH_READ_ONLY_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_ONLY_11_NL, "Koppel schijfbestand voor drive #11 als alleen-lezen"},
/* ru */ {IDCLS_ATTACH_READ_ONLY_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_ONLY_11_SV, "Anslut diskettavbildningsfil för enhet 11 med skrivskydd"},
/* tr */ {IDCLS_ATTACH_READ_ONLY_11_TR, "Sürücü #11 için disk imajýný salt okunur olarak yerleþtir"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_WRITE_11,    N_("Attach disk image for drive #11 read write (if possible)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_WRITE_11_DA, "Tilslut disk-image til drev #11 skrivbar (hvis muligt)"},
/* de */ {IDCLS_ATTACH_READ_WRITE_11_DE, "Disk Image als Laufwerk #11 benutzen (Schreibzugriff, wenn möglich)"},
/* fr */ {IDCLS_ATTACH_READ_WRITE_11_FR, "Charger une image de disque pour le lecteur #11 en lecture-écriture (si possible)"},
/* hu */ {IDCLS_ATTACH_READ_WRITE_11_HU, "Írható-olvasható képmás csatolása a #11-es lemezegységhez"},
/* it */ {IDCLS_ATTACH_READ_WRITE_11_IT, "Seleziona immagine del disco per il drive #11 in lettura/scrittura (se possibile)"},
/* ko */ {IDCLS_ATTACH_READ_WRITE_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_WRITE_11_NL, "Koppel schijfbestand voor drive #11 als schrijfbaar (indien mogelijk)"},
/* ru */ {IDCLS_ATTACH_READ_WRITE_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_WRITE_11_SV, "Anslut diskettavbildningsfil för enhet 11 skrivbar (om möjligt)"},
/* tr */ {IDCLS_ATTACH_READ_WRITE_11_TR, "Sürücü #11 için disk imajýný okunur/yazýlýr olarak yerleþtir (mümkünse)"},
#endif

/* datasette.c */
/* en */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET,    N_("Enable automatic Datasette-Reset")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_DA, "Aktivér automatisk Datasette-reset"},
/* de */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_DE, "Automatisches Datasette-Reset aktivieren"},
/* fr */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_FR, "Activer le redémarrage automatique du Datasette"},
/* hu */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_HU, "Automatikus magnó Reset engedélyezése"},
/* it */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_IT, "Attiva reset automatico del registratore"},
/* ko */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_NL, "Activeer automatische Datasette-Reset"},
/* ru */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_SV, "Aktivera automatisk Datasetteåterställning"},
/* tr */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_TR, "Otomatik Teyp-Reset'i aktif et"},
#endif

/* datasette.c */
/* en */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET,    N_("Disable automatic Datasette-Reset")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_DA, "Deaktivér automatisk Datasette-reset"},
/* de */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_DE, "Automatisches Datasette-Reset deaktivieren"},
/* fr */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_FR, "Désactiver le redémarrage automatique du Datasette"},
/* hu */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_HU, "Automatikus magnó Reset tiltása"},
/* it */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_IT, "Disattiva reset automatico del registratore"},
/* ko */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_NL, "Automatische Datasette-Reset uitschakelen"},
/* ru */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_SV, "Inaktivera automatisk Datasetteåterställning"},
/* tr */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_TR, "Otomatik Teyp-Reset'i pasifleþtir"},
#endif

/* datasette.c */
/* en */ {IDCLS_SET_ZERO_TAP_DELAY,    N_("Set delay in cycles for a zero in the tap")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_ZERO_TAP_DELAY_DA, "Angiv forsinkelse i cykler for et nul i tap-filen"},
/* de */ {IDCLS_SET_ZERO_TAP_DELAY_DE, "Verzögerung für Zero in Zyklen im Tap"},
/* fr */ {IDCLS_SET_ZERO_TAP_DELAY_FR, "Spécifier le délai en cycles pour un zéro sur le ruban"},
/* hu */ {IDCLS_SET_ZERO_TAP_DELAY_HU, "Adja meg ciklusokban a legelsõ szalagrés hosszát"},
/* it */ {IDCLS_SET_ZERO_TAP_DELAY_IT, "Imposta il ritardo in cicli per uno zero nel tap"},
/* ko */ {IDCLS_SET_ZERO_TAP_DELAY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_ZERO_TAP_DELAY_NL, "Zet de vertraging in cycli voor een nul in de tap"},
/* ru */ {IDCLS_SET_ZERO_TAP_DELAY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_ZERO_TAP_DELAY_SV, "Ange väntecykler för nolla i tap-filen"},
/* tr */ {IDCLS_SET_ZERO_TAP_DELAY_TR, "Baðlantý anýnda cycle tipinden bekleme süresini ayarla"},
#endif

/* datasette.c */
/* en */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP,    N_("Set number of cycles added to each gap in the tap")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_DA, "Angiv antal cykler der lægges til hvert hul i tap-filen"},
/* de */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_DE, "Setze Anzahl der Zyklen für jedes Loch im Tap"},
/* fr */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_FR, "Spécifier le nombre de cycles ajouté a chaque raccord du ruban"},
/* hu */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_HU, "Adja meg ciklusokban a szalagfájlok közti üres rés hosszát"},
/* it */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_IT, "Imposta il numero di cicli aggiunti ad ogni gap nel tap"},
/* ko */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_NL, "Zet aantal extra cycli voor elk gat in de tap"},
/* ru */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_SV, "Ange cykler som läggs till varje gap i tap-filen"},
/* tr */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_TR, "Baðlantý anýnda her boþluk için eklenecek cycle sayýsýný ayarla"},
#endif

#ifdef DEBUG
/* debug.c */
/* en */ {IDCLS_TRACE_MAIN_CPU,    N_("Trace the main CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TRACE_MAIN_CPU_DA, "Trace hovedprocessoren"},
/* de */ {IDCLS_TRACE_MAIN_CPU_DE, "Haupt CPU verfolgen"},
/* fr */ {IDCLS_TRACE_MAIN_CPU_FR, "Tracer l'UCT principal"},
/* hu */ {IDCLS_TRACE_MAIN_CPU_HU, "Fõ CPU nyomkövetése"},
/* it */ {IDCLS_TRACE_MAIN_CPU_IT, "Traccia la CPU principale"},
/* ko */ {IDCLS_TRACE_MAIN_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TRACE_MAIN_CPU_NL, "Traceer de hoofd CPU"},
/* ru */ {IDCLS_TRACE_MAIN_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TRACE_MAIN_CPU_SV, "Spåra huvudprocessorn"},
/* tr */ {IDCLS_TRACE_MAIN_CPU_TR, "Ana CPU'yu izle"},
#endif

/* debug.c */
/* en */ {IDCLS_DONT_TRACE_MAIN_CPU,    N_("Do not trace the main CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_TRACE_MAIN_CPU_DA, "Trace ikke hovedprocessoren"},
/* de */ {IDCLS_DONT_TRACE_MAIN_CPU_DE, "Haupt CPU nicht verfolgen"},
/* fr */ {IDCLS_DONT_TRACE_MAIN_CPU_FR, "Ne pas tracer l'UCT principal"},
/* hu */ {IDCLS_DONT_TRACE_MAIN_CPU_HU, "Fõ CPU nyomkövetésének tiltása"},
/* it */ {IDCLS_DONT_TRACE_MAIN_CPU_IT, "Non tracciare la CPU principale"},
/* ko */ {IDCLS_DONT_TRACE_MAIN_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_TRACE_MAIN_CPU_NL, "Traceer de hoofd CPU niet"},
/* ru */ {IDCLS_DONT_TRACE_MAIN_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_TRACE_MAIN_CPU_SV, "Spåra inte huvudprocessorn"},
/* tr */ {IDCLS_DONT_TRACE_MAIN_CPU_TR, "Ana CPU'yu izleme"},
#endif

/* debug.c */
/* en */ {IDCLS_TRACE_DRIVE0_CPU,    N_("Trace the drive0 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TRACE_DRIVE0_CPU_DA, "Trace processor i drev 0"},
/* de */ {IDCLS_TRACE_DRIVE0_CPU_DE, "Laufwerk0 CPU verfolgen"},
/* fr */ {IDCLS_TRACE_DRIVE0_CPU_FR, "Tracer l'UCT du drive0"},
/* hu */ {IDCLS_TRACE_DRIVE0_CPU_HU, "A 0-s lemezegység CPU-jának nyomkövetése"},
/* it */ {IDCLS_TRACE_DRIVE0_CPU_IT, "Traccia la CPU del drive0"},
/* ko */ {IDCLS_TRACE_DRIVE0_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TRACE_DRIVE0_CPU_NL, "Traceer de CPU van drive 0/8"},
/* ru */ {IDCLS_TRACE_DRIVE0_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TRACE_DRIVE0_CPU_SV, "Spåra processor i diskettstation 0"},
/* tr */ {IDCLS_TRACE_DRIVE0_CPU_TR, "Sürücü0 CPU'sunu izle"},
#endif

/* debug.c */
/* en */ {IDCLS_DONT_TRACE_DRIVE0_CPU,    N_("Do not trace the drive0 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_TRACE_DRIVE0_CPU_DA, "Trace ikke processor i drev 0"},
/* de */ {IDCLS_DONT_TRACE_DRIVE0_CPU_DE, "Laufwerk0 CPU nicht verfolgen"},
/* fr */ {IDCLS_DONT_TRACE_DRIVE0_CPU_FR, "Ne pas tracer l'UCT du drive0"},
/* hu */ {IDCLS_DONT_TRACE_DRIVE0_CPU_HU, "A 0-s lemezegység CPU-ja nyomkövetésének tiltása"},
/* it */ {IDCLS_DONT_TRACE_DRIVE0_CPU_IT, "Non tracciare la CPU del drive0"},
/* ko */ {IDCLS_DONT_TRACE_DRIVE0_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_TRACE_DRIVE0_CPU_NL, "Traceer de CPU van drive 0/8 niet"},
/* ru */ {IDCLS_DONT_TRACE_DRIVE0_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_TRACE_DRIVE0_CPU_SV, "Spåra inte processor i diskettstation 0"},
/* tr */ {IDCLS_DONT_TRACE_DRIVE0_CPU_TR, "Sürücü0 CPU'sunu izleme"},
#endif

/* debug.c */
/* en */ {IDCLS_TRACE_DRIVE1_CPU,    N_("Trace the drive1 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TRACE_DRIVE1_CPU_DA, "Trace processor i drev 1"},
/* de */ {IDCLS_TRACE_DRIVE1_CPU_DE, "Laufwerk1 CPU verfolgen"},
/* fr */ {IDCLS_TRACE_DRIVE1_CPU_FR, "Tracer l'UCT du drive1"},
/* hu */ {IDCLS_TRACE_DRIVE1_CPU_HU, "Az 1-es lemezegység CPU-jának nyomkövetése"},
/* it */ {IDCLS_TRACE_DRIVE1_CPU_IT, "Traccia la CPU del drive1"},
/* ko */ {IDCLS_TRACE_DRIVE1_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TRACE_DRIVE1_CPU_NL, "Traceer de CPU van drive 1/9"},
/* ru */ {IDCLS_TRACE_DRIVE1_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TRACE_DRIVE1_CPU_SV, "Spåra processor i diskettstation 1"},
/* tr */ {IDCLS_TRACE_DRIVE1_CPU_TR, "Sürücü1 CPU'sunu izle"},
#endif

/* debug.c */
/* en */ {IDCLS_DONT_TRACE_DRIVE1_CPU,    N_("Do not trace the drive1 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_TRACE_DRIVE1_CPU_DA, "Trace ikke processor i drev 1"},
/* de */ {IDCLS_DONT_TRACE_DRIVE1_CPU_DE, "Laufwerk1 CPU nicht verfolgen"},
/* fr */ {IDCLS_DONT_TRACE_DRIVE1_CPU_FR, "Ne pas tracer l'UCT du drive1"},
/* hu */ {IDCLS_DONT_TRACE_DRIVE1_CPU_HU, "Az 1-es lemezegység CPU-ja nyomkövetésének tiltása"},
/* it */ {IDCLS_DONT_TRACE_DRIVE1_CPU_IT, "Non tracciare la CPU del drive1"},
/* ko */ {IDCLS_DONT_TRACE_DRIVE1_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_TRACE_DRIVE1_CPU_NL, "Traceer de CPU van drive 1/9 niet"},
/* ru */ {IDCLS_DONT_TRACE_DRIVE1_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_TRACE_DRIVE1_CPU_SV, "Spåra inte processor i diskettstation 1"},
/* tr */ {IDCLS_DONT_TRACE_DRIVE1_CPU_TR, "Sürücü1 CPU'sunu izleme"},
#endif

#if DRIVE_NUM > 2
/* debug.c */
/* en */ {IDCLS_TRACE_DRIVE2_CPU,    N_("Trace the drive2 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TRACE_DRIVE2_CPU_DA, "Trace processor i drev 2"},
/* de */ {IDCLS_TRACE_DRIVE2_CPU_DE, "Laufwerk2 CPU verfolgen"},
/* fr */ {IDCLS_TRACE_DRIVE2_CPU_FR, "Tracer l'UCT du drive2"},
/* hu */ {IDCLS_TRACE_DRIVE2_CPU_HU, "A 2-es lemezegység CPU-jának nyomkövetése"},
/* it */ {IDCLS_TRACE_DRIVE2_CPU_IT, "Traccia la CPU del drive2"},
/* ko */ {IDCLS_TRACE_DRIVE2_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TRACE_DRIVE2_CPU_NL, "Traceer de CPU van drive 2/10"},
/* ru */ {IDCLS_TRACE_DRIVE2_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TRACE_DRIVE2_CPU_SV, "Spåra processor i diskettstation 2"},
/* tr */ {IDCLS_TRACE_DRIVE2_CPU_TR, "Sürücü2 CPU'sunu izle"},
#endif

/* debug.c */
/* en */ {IDCLS_DONT_TRACE_DRIVE2_CPU,    N_("Do not trace the drive2 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_TRACE_DRIVE2_CPU_DA, "Trace ikke processor i drev 2"},
/* de */ {IDCLS_DONT_TRACE_DRIVE2_CPU_DE, "Laufwerk2 CPU nicht verfolgen"},
/* fr */ {IDCLS_DONT_TRACE_DRIVE2_CPU_FR, "Ne pas tracer l'UCT du drive2"},
/* hu */ {IDCLS_DONT_TRACE_DRIVE2_CPU_HU, "A 2-es lemezegység CPU-ja nyomkövetésének tiltása"},
/* it */ {IDCLS_DONT_TRACE_DRIVE2_CPU_IT, "Non tracciare la CPU del drive2"},
/* ko */ {IDCLS_DONT_TRACE_DRIVE2_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_TRACE_DRIVE2_CPU_NL, "Traceer de CPU van drive 2/10 niet"},
/* ru */ {IDCLS_DONT_TRACE_DRIVE2_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_TRACE_DRIVE2_CPU_SV, "Spåra inte processor i diskettstation 2"},
/* tr */ {IDCLS_DONT_TRACE_DRIVE2_CPU_TR, "Sürücü2 CPU'sunu izleme"},
#endif
#endif

#if DRIVE_NUM > 3
/* debug.c */
/* en */ {IDCLS_TRACE_DRIVE3_CPU,    N_("Trace the drive3 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TRACE_DRIVE3_CPU_DA, "Trace processor i drev 3"},
/* de */ {IDCLS_TRACE_DRIVE3_CPU_DE, "Laufwerk3 CPU verfolgen"},
/* fr */ {IDCLS_TRACE_DRIVE3_CPU_FR, "Tracer l'UCT du drive3"},
/* hu */ {IDCLS_TRACE_DRIVE3_CPU_HU, "A 3-as lemezegység CPU-jának nyomkövetése"},
/* it */ {IDCLS_TRACE_DRIVE3_CPU_IT, "Traccia la CPU del drive3"},
/* ko */ {IDCLS_TRACE_DRIVE3_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TRACE_DRIVE3_CPU_NL, "Traceer de CPU van drive 3/11"},
/* ru */ {IDCLS_TRACE_DRIVE3_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TRACE_DRIVE3_CPU_SV, "Spåra processor i diskettstation 3"},
/* tr */ {IDCLS_TRACE_DRIVE3_CPU_TR, "Sürücü3 CPU'sunu izle"},
#endif

/* debug.c */
/* en */ {IDCLS_DONT_TRACE_DRIVE3_CPU,    N_("Do not trace the drive3 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_TRACE_DRIVE3_CPU_DA, "Trace ikke processor i drev 3"},
/* de */ {IDCLS_DONT_TRACE_DRIVE3_CPU_DE, "Laufwerk3 CPU nicht verfolgen"},
/* fr */ {IDCLS_DONT_TRACE_DRIVE3_CPU_FR, "Ne pas tracer l'UCT du drive3"},
/* hu */ {IDCLS_DONT_TRACE_DRIVE3_CPU_HU, "A 3-as lemezegység CPU-ja nyomkövetésének tiltása"},
/* it */ {IDCLS_DONT_TRACE_DRIVE3_CPU_IT, "Non tracciare la CPU del drive3"},
/* ko */ {IDCLS_DONT_TRACE_DRIVE3_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_TRACE_DRIVE3_CPU_NL, "Traceer de CPU van drive 3/11 niet"},
/* ru */ {IDCLS_DONT_TRACE_DRIVE3_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_TRACE_DRIVE3_CPU_SV, "Spåra inte processor i diskettstation 3"},
/* tr */ {IDCLS_DONT_TRACE_DRIVE3_CPU_TR, "Sürücü3 CPU'sunu izleme"},
#endif
#endif

/* debug.c */
/* en */ {IDCLS_TRACE_MODE,    N_("Trace mode (0=normal 1=small 2=history)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TRACE_MODE_DA, "Trace-tilstand (0=normal 1=lille 2=historik)"},
/* de */ {IDCLS_TRACE_MODE_DE, "Verfolgung Modus (0=normal 1=klein 2=Geschichte)"},
/* fr */ {IDCLS_TRACE_MODE_FR, "Mode de trace (0=normal 1=petit 2=historique)"},
/* hu */ {IDCLS_TRACE_MODE_HU, "Nyomkövetési mód (0=normál 1=kicsi 2=elõzmények)"},
/* it */ {IDCLS_TRACE_MODE_IT, "Modalità di tracciamento (0=normale 1=piccola 2=storica)"},
/* ko */ {IDCLS_TRACE_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TRACE_MODE_NL, "Traceermodus (0=normaal 1=klein 2=geschiedenis"},
/* ru */ {IDCLS_TRACE_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TRACE_MODE_SV, "Spårningsläge (0=normal 1=liten 2=historik)"},
/* tr */ {IDCLS_TRACE_MODE_TR, "Ýzleme modu (0=normal 1=küçük 2=tarihçe)"},
#endif
#endif

/* event.c */
/* en */ {IDCLS_PLAYBACK_RECORDED_EVENTS,    N_("Playback recorded events")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PLAYBACK_RECORDED_EVENTS_DA, "Afspil hændelsesoptagelse"},
/* de */ {IDCLS_PLAYBACK_RECORDED_EVENTS_DE, "Wiedergabe von aufgenommener Ereignisse"},
/* fr */ {IDCLS_PLAYBACK_RECORDED_EVENTS_FR, "Lire les événements enregistrés"},
/* hu */ {IDCLS_PLAYBACK_RECORDED_EVENTS_HU, "A felvett események visszajátszása"},
/* it */ {IDCLS_PLAYBACK_RECORDED_EVENTS_IT, "Riproduzione eventi registrati"},
/* ko */ {IDCLS_PLAYBACK_RECORDED_EVENTS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PLAYBACK_RECORDED_EVENTS_NL, "Afspelen opgenomen gebeurtenissen"},
/* ru */ {IDCLS_PLAYBACK_RECORDED_EVENTS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PLAYBACK_RECORDED_EVENTS_SV, "Spela upp inspelade händelser"},
/* tr */ {IDCLS_PLAYBACK_RECORDED_EVENTS_TR, "Kayýttan yürütme kaydedilmiþ olaylarý"},
#endif

/* monitor.c */
/* en */ {IDCLS_EXECUTE_MONITOR_FROM_FILE,    N_("Execute monitor commands from file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_DA, "Udfør monitorkommandoer fra fil"},
/* de */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_DE, "Monitor Kommandos aus Datei ausführen"},
/* fr */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_FR, "Exécuter des commandes moniteur depuis un fichier"},
/* hu */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_HU, "Monitorprogram parancsok futtatása fájlból"},
/* it */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_IT, "Esegui i comandi del monitor da un file"},
/* ko */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_NL, "Uitvoeren van commandos uit bestand"},
/* ru */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_SV, "Exekvera monitorkommandon från fil"},
/* tr */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_TR, "Dosyadan monitör komutlarý çalýþtýr"},
#endif

/* monitor.c */
/* en */ {IDCLS_SET_INITIAL_BREAKPOINT,    N_("Set an initial breakpoint for the monitor")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_INITIAL_BREAKPOINT_DA, "Sæt et initielt breakpoint for monitoren"},
/* de */ {IDCLS_SET_INITIAL_BREAKPOINT_DE, "Setze initialen Breakpoint für Monitor"},
/* fr */ {IDCLS_SET_INITIAL_BREAKPOINT_FR, "Régler un point d’arrêt initial pour le moniteur"},
/* hu */ {IDCLS_SET_INITIAL_BREAKPOINT_HU, "Kezdeti töréspont megadása a monitorprogramnak"},
/* it */ {IDCLS_SET_INITIAL_BREAKPOINT_IT, "Imposta un breakpoint iniziale per il monitor"},
/* ko */ {IDCLS_SET_INITIAL_BREAKPOINT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_INITIAL_BREAKPOINT_NL, "Zet een beginnende breakpunt voor de monitor"},
/* ru */ {IDCLS_SET_INITIAL_BREAKPOINT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_INITIAL_BREAKPOINT_SV, "Sätt en ursprunglig brytpunkt för monitorn"},
/* tr */ {IDCLS_SET_INITIAL_BREAKPOINT_TR, "Monitör için dahili bir kesme noktasý ayarla"},
#endif

/* monitor_network.c */
/* en */ {IDCLS_ENABLE_REMOTE_MONITOR,    N_("Enable remote monitor")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_REMOTE_MONITOR_DA, "Aktivér fjern-monitor"},
/* de */ {IDCLS_ENABLE_REMOTE_MONITOR_DE, "Monitor Fernsteuerung aktivieren"},
/* fr */ {IDCLS_ENABLE_REMOTE_MONITOR_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_REMOTE_MONITOR_HU, "Távoli monitor engedélyezése"},
/* it */ {IDCLS_ENABLE_REMOTE_MONITOR_IT, "Attiva monitor remoto"},
/* ko */ {IDCLS_ENABLE_REMOTE_MONITOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_REMOTE_MONITOR_NL, "Activeer monitor afstandsbediening"},
/* ru */ {IDCLS_ENABLE_REMOTE_MONITOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_REMOTE_MONITOR_SV, "Aktivera fjärrmonitor"},
/* tr */ {IDCLS_ENABLE_REMOTE_MONITOR_TR, "Uzak monitörü aktif et"},
#endif

/* monitor_network.c */
/* en */ {IDCLS_DISABLE_REMOTE_MONITOR,    N_("Disable remote monitor")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_REMOTE_MONITOR_DA, "Deaktivér fjern-monitor"},
/* de */ {IDCLS_DISABLE_REMOTE_MONITOR_DE, "Monitor Fernsteuerung deaktivieren"},
/* fr */ {IDCLS_DISABLE_REMOTE_MONITOR_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_REMOTE_MONITOR_HU, "Távoli monitor tiltása"},
/* it */ {IDCLS_DISABLE_REMOTE_MONITOR_IT, "Disattiva monitor remoto"},
/* ko */ {IDCLS_DISABLE_REMOTE_MONITOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_REMOTE_MONITOR_NL, "afstandsbediening monitor uitschakelen"},
/* ru */ {IDCLS_DISABLE_REMOTE_MONITOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_REMOTE_MONITOR_SV, "Inaktivera fjärrmonitor"},
/* tr */ {IDCLS_DISABLE_REMOTE_MONITOR_TR, "Uzak monitörü pasifleþtir"},
#endif

/* monitor_network.c */
/* en */ {IDCLS_REMOTE_MONITOR_ADDRESS,    N_("The local address the remote monitor should bind to")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_REMOTE_MONITOR_ADDRESS_DA, "Lokal adresse fjern-monitoren skal binde til"},
/* de */ {IDCLS_REMOTE_MONITOR_ADDRESS_DE, "Lokale Adresse für die Monitorfernsteuerung"},
/* fr */ {IDCLS_REMOTE_MONITOR_ADDRESS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_REMOTE_MONITOR_ADDRESS_HU, "A helyi cím, amelyet a monitorprogram lefoglal"},
/* it */ {IDCLS_REMOTE_MONITOR_ADDRESS_IT, "Indirizzo locale a cui il monitor remoto dovrebbe collegarsi"},
/* ko */ {IDCLS_REMOTE_MONITOR_ADDRESS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_REMOTE_MONITOR_ADDRESS_NL, "Lokaal adres waar de afstandsbediening voor de monitor aan gebonden moet worden"},
/* ru */ {IDCLS_REMOTE_MONITOR_ADDRESS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_REMOTE_MONITOR_ADDRESS_SV, "Lokal adress för fjärrmonitor att ansluta till"},
/* tr */ {IDCLS_REMOTE_MONITOR_ADDRESS_TR, "Uzak monitörün baðlanmasý gereken lokal adres"},
#endif

/* fliplist.c */
/* en */ {IDCLS_SPECIFY_FLIP_LIST_NAME,    N_("Specify name of the flip list file image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FLIP_LIST_NAME_DA, "Angiv navn på bladreliste"},
/* de */ {IDCLS_SPECIFY_FLIP_LIST_NAME_DE, "Namen für Fliplist Datei definieren"},
/* fr */ {IDCLS_SPECIFY_FLIP_LIST_NAME_FR, "Spécifier le nom de l'image du fichier de groupement de disques"},
/* hu */ {IDCLS_SPECIFY_FLIP_LIST_NAME_HU, "Adja meg a lemezlista fájl nevét"},
/* it */ {IDCLS_SPECIFY_FLIP_LIST_NAME_IT, "Specifica il nome immagine del file della flip list"},
/* ko */ {IDCLS_SPECIFY_FLIP_LIST_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FLIP_LIST_NAME_NL, "Geef de naam van het fliplijstbestand"},
/* ru */ {IDCLS_SPECIFY_FLIP_LIST_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FLIP_LIST_NAME_SV, "Ange namn på vallistefilavbildningen"},
/* tr */ {IDCLS_SPECIFY_FLIP_LIST_NAME_TR, "Sýralama listesi dosya imajý ismi belirt"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS,    N_("Show a list of the available options and exit normally")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_DA, "Vis en liste over tilgængelige parametre og afslut"},
/* de */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_DE, "Liste von verfügbaren Optionen zeigen und beenden"},
/* fr */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_FR, "Montrer une liste des options disponibles et terminer normalement"},
/* hu */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_HU, "Kilistázza a lehetséges opciókat és kilép"},
/* it */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_IT, "Mostra la lista delle opzioni disponibili ed esce"},
/* ko */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_NL, "Toon een lijst van de beschikbare opties en exit zoals normaal"},
/* ru */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_SV, "Visa lista över tillgängliga flaggor och avsluta normalt"},
/* tr */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_TR, "Mevcut seçeneklerin listesini göster ve normal çýk"},
#endif

#if (!defined  __OS2__ && !defined __BEOS__)
/* initcmdline.c */
/* en */ {IDCLS_CONSOLE_MODE,    N_("Console mode (for music playback)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_CONSOLE_MODE_DA, "Konsoltilstand (for musikafspilning)"},
/* de */ {IDCLS_CONSOLE_MODE_DE, "Konsolenmodus (für Musikwiedergabe)"},
/* fr */ {IDCLS_CONSOLE_MODE_FR, "Mode console (pour l'écoute de musique)"},
/* hu */ {IDCLS_CONSOLE_MODE_HU, "Konzol mód (zene lejátszáshoz)"},
/* it */ {IDCLS_CONSOLE_MODE_IT, "Modalità console (per la riproduzione musicale)"},
/* ko */ {IDCLS_CONSOLE_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_CONSOLE_MODE_NL, "Consolemodus (voor afspelen voor muziek)"},
/* ru */ {IDCLS_CONSOLE_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_CONSOLE_MODE_SV, "Konsolläge (för musikspelning)"},
/* tr */ {IDCLS_CONSOLE_MODE_TR, "Konsol modu (müzik çalmak için)"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ALLOW_CORE_DUMPS,    N_("Allow production of core dumps")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ALLOW_CORE_DUMPS_DA, "Tillad generering af core-dumps"},
/* de */ {IDCLS_ALLOW_CORE_DUMPS_DE, "Core Dumps ermöglichen"},
/* fr */ {IDCLS_ALLOW_CORE_DUMPS_FR, "Permettre la production de \"core dumps\""},
/* hu */ {IDCLS_ALLOW_CORE_DUMPS_HU, "Core dump készítés engedélyezése"},
/* it */ {IDCLS_ALLOW_CORE_DUMPS_IT, "Consente la produzione di core dump"},
/* ko */ {IDCLS_ALLOW_CORE_DUMPS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ALLOW_CORE_DUMPS_NL, "Maken van core dumps toestaan"},
/* ru */ {IDCLS_ALLOW_CORE_DUMPS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_CORE_DUMPS_SV, "Tillåt skapa minnesutskrift"},
/* tr */ {IDCLS_ALLOW_CORE_DUMPS_TR, "Bellek durumunun kayýtlarýnýn üretilmesine izin ver"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_DONT_ALLOW_CORE_DUMPS,    N_("Do not produce core dumps")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_ALLOW_CORE_DUMPS_DA, "Lav ikke core-dumps"},
/* de */ {IDCLS_DONT_ALLOW_CORE_DUMPS_DE, "Core Dumps verhindern"},
/* fr */ {IDCLS_DONT_ALLOW_CORE_DUMPS_FR, "Ne pas produire de \"core dumps\""},
/* hu */ {IDCLS_DONT_ALLOW_CORE_DUMPS_HU, "Core dump készítés tiltása"},
/* it */ {IDCLS_DONT_ALLOW_CORE_DUMPS_IT, "Non produce core dump"},
/* ko */ {IDCLS_DONT_ALLOW_CORE_DUMPS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_ALLOW_CORE_DUMPS_NL, "Maken van core dumps niet toestaan"},
/* ru */ {IDCLS_DONT_ALLOW_CORE_DUMPS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_ALLOW_CORE_DUMPS_SV, "Skapa inte minnesutskrift"},
/* tr */ {IDCLS_DONT_ALLOW_CORE_DUMPS_TR, "Bellek durumunun kayýtlarýný üretme"},
#endif

#else

/* initcmdline.c */
/* en */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER,    N_("Don't call exception handler")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_DA, "Kald ikke exception-handler"},
/* de */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_DE, "Ausnahmebehandlung vermeiden"},
/* fr */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_FR, "Ne pas utiliser l'assistant d'exception"},
/* hu */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_HU, "Ne hívja a kivétel kezelõt"},
/* it */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_IT, "Richiama il gestore delle eccezioni"},
/* ko */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_NL, "Geen gebruik maken van de exception handler"},
/* ru */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_SV, "Anropa inte undantagshanterare"},
/* tr */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_TR, "Kural dýþý iþleyiciyi çaðýrma"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_CALL_EXCEPTION_HANDLER,    N_("Call exception handler (default)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_CALL_EXCEPTION_HANDLER_DA, "Kald exception-handler (standard)"},
/* de */ {IDCLS_CALL_EXCEPTION_HANDLER_DE, "Ausnahmebehandlung aktivieren (Default)"},
/* fr */ {IDCLS_CALL_EXCEPTION_HANDLER_FR, "Utiliser l'assistant d'exception (par défaut)"},
/* hu */ {IDCLS_CALL_EXCEPTION_HANDLER_HU, "Kivétel kezelõ hívása (alapértelmezés)"},
/* it */ {IDCLS_CALL_EXCEPTION_HANDLER_IT, "Richiama il gestore delle eccezioni (predefinito)"},
/* ko */ {IDCLS_CALL_EXCEPTION_HANDLER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_CALL_EXCEPTION_HANDLER_NL, "Gebruik maken van de exception handler (standaard)"},
/* ru */ {IDCLS_CALL_EXCEPTION_HANDLER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_CALL_EXCEPTION_HANDLER_SV, "Anropa undantagshanterare (standard)"},
/* tr */ {IDCLS_CALL_EXCEPTION_HANDLER_TR, "Kural dýþý iþleyiciyi çaðýr (varsayýlan)"},
#endif
#endif

/* initcmdline.c */
/* en */ {IDCLS_RESTORE_DEFAULT_SETTINGS,    N_("Restore default settings")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RESTORE_DEFAULT_SETTINGS_DA, "Gendan standardindstillinger"},
/* de */ {IDCLS_RESTORE_DEFAULT_SETTINGS_DE, "Standard Einstellungen wiederherstellen"},
/* fr */ {IDCLS_RESTORE_DEFAULT_SETTINGS_FR, "Rétablir les paramètres par défaut"},
/* hu */ {IDCLS_RESTORE_DEFAULT_SETTINGS_HU, "Alapértelmezés visszaállítása"},
/* it */ {IDCLS_RESTORE_DEFAULT_SETTINGS_IT, "Ripristina impostazioni predefinite"},
/* ko */ {IDCLS_RESTORE_DEFAULT_SETTINGS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_RESTORE_DEFAULT_SETTINGS_NL, "Herstel standaard instellingen"},
/* ru */ {IDCLS_RESTORE_DEFAULT_SETTINGS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RESTORE_DEFAULT_SETTINGS_SV, "Återställ förvalda inställningar"},
/* tr */ {IDCLS_RESTORE_DEFAULT_SETTINGS_TR, "Varsayýlan ayarlarý geri yükle"},
#endif

/* initcmdline.c, c64/cart/mmcreplay.c */
/* en */ {IDCLS_P_FILE,    N_("<filename>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_FILE_DA, "<filnavn>"},
/* de */ {IDCLS_P_FILE_DE, "<Dateiname>"},
/* fr */ {IDCLS_P_FILE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_FILE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_FILE_IT, "<nome file>"},
/* ko */ {IDCLS_P_FILE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_FILE_NL, "<bestandsnaam>"},
/* ru */ {IDCLS_P_FILE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_FILE_SV, "<filnamn>"},
/* tr */ {IDCLS_P_FILE_TR, "<dosyaismi>"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_SPECIFY_CONFIG_FILE,    N_("Specify config file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CONFIG_FILE_DA, "Angiv konfigurationsfil"},
/* de */ {IDCLS_SPECIFY_CONFIG_FILE_DE, "Konfigurationsdateiname definieren"},
/* fr */ {IDCLS_SPECIFY_CONFIG_FILE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_CONFIG_FILE_HU, "Adja meg a konfigurációs fájl nevét"},
/* it */ {IDCLS_SPECIFY_CONFIG_FILE_IT, "Specifica il nome del file di configurazione"},
/* ko */ {IDCLS_SPECIFY_CONFIG_FILE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CONFIG_FILE_NL, "Geef configuratie bestandsnaam"},
/* ru */ {IDCLS_SPECIFY_CONFIG_FILE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CONFIG_FILE_SV, "Ange inställningsfil"},
/* tr */ {IDCLS_SPECIFY_CONFIG_FILE_TR, "Konfigürasyon dosyasýný belirt"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AND_AUTOSTART,    N_("Attach and autostart tape/disk image <name>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AND_AUTOSTART_DA, "Tilslut og autostart bånd-/disk-image <navn>"},
/* de */ {IDCLS_ATTACH_AND_AUTOSTART_DE, "Einlegen und Autostart Disk/Band Image Datei <Name>"},
/* fr */ {IDCLS_ATTACH_AND_AUTOSTART_FR, "Insérer et démarrer l'image de disque/datassette <nom>"},
/* hu */ {IDCLS_ATTACH_AND_AUTOSTART_HU, "<név> lemez/szalag képmás csatolása és automatikus elindítása"},
/* it */ {IDCLS_ATTACH_AND_AUTOSTART_IT, "Seleziona ed avvia l'immagine di una cassetta/disco <nome>"},
/* ko */ {IDCLS_ATTACH_AND_AUTOSTART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AND_AUTOSTART_NL, "Koppel en autostart een tape/diskbestand <naam>"},
/* ru */ {IDCLS_ATTACH_AND_AUTOSTART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AND_AUTOSTART_SV, "Anslut och starta band-/diskettavbildning <namn>"},
/* tr */ {IDCLS_ATTACH_AND_AUTOSTART_TR, "Teyp/Disk imajý <isim> yerleþtir ve otomatik baþlat"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AND_AUTOLOAD,    N_("Attach and autoload tape/disk image <name>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AND_AUTOLOAD_DA, "Tilslut og læs bånd-/disk-image <navn>"},
/* de */ {IDCLS_ATTACH_AND_AUTOLOAD_DE, "Einlegen und Autoload Disk/Band Image Datei <Name>"},
/* fr */ {IDCLS_ATTACH_AND_AUTOLOAD_FR, "Insérer et charger l'image de disque/datassette <nom>"},
/* hu */ {IDCLS_ATTACH_AND_AUTOLOAD_HU, "<név> lemez/szalag képmás csatolása és automatikus betöltése"},
/* it */ {IDCLS_ATTACH_AND_AUTOLOAD_IT, "Seleziona e carica l'immagine di una cassetta/disco <nome>"},
/* ko */ {IDCLS_ATTACH_AND_AUTOLOAD_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AND_AUTOLOAD_NL, "Koppel en autolaad een tape-/diskbestand <naam>"},
/* ru */ {IDCLS_ATTACH_AND_AUTOLOAD_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AND_AUTOLOAD_SV, "Anslut och läs in band-/diskettavbildning <namn>"},
/* tr */ {IDCLS_ATTACH_AND_AUTOLOAD_TR, "Teyp/Disk imajý <isim> yerleþtir ve otomatik yükle"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AS_TAPE,    N_("Attach <name> as a tape image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AS_TAPE_DA, "Tilslut <navn> som bånd-image"},
/* de */ {IDCLS_ATTACH_AS_TAPE_DE, "Image Datei <Name> einlegen"},
/* fr */ {IDCLS_ATTACH_AS_TAPE_FR, "Insérer <nom> comme image de datassette"},
/* hu */ {IDCLS_ATTACH_AS_TAPE_HU, "<név> szalag képmás csatolása"},
/* it */ {IDCLS_ATTACH_AS_TAPE_IT, "Seleziona <nome> come un'immagine di una cassetta"},
/* ko */ {IDCLS_ATTACH_AS_TAPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AS_TAPE_NL, "Koppel <naam> als een tapebestand"},
/* ru */ {IDCLS_ATTACH_AS_TAPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AS_TAPE_SV, "Anslut <namn> som bandavbildning"},
/* tr */ {IDCLS_ATTACH_AS_TAPE_TR, "Teyp imajý olarak <isim> yerleþtir"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AS_DISK_8,    N_("Attach <name> as a disk image in drive #8")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AS_DISK_8_DA, "Tilslut <navn> som disk-image i enhed #8"},
/* de */ {IDCLS_ATTACH_AS_DISK_8_DE, "Image Datei <Name> im Laufwerk #8 einlegen"},
/* fr */ {IDCLS_ATTACH_AS_DISK_8_FR, "Insérer <nom> comme image de disque dans le lecteur #8"},
/* hu */ {IDCLS_ATTACH_AS_DISK_8_HU, "<név> lemezképmás csatolása #8-as egységként"},
/* it */ {IDCLS_ATTACH_AS_DISK_8_IT, "Seleziona <nome> come un'immagine di un disco nel drive #8"},
/* ko */ {IDCLS_ATTACH_AS_DISK_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AS_DISK_8_NL, "Koppel <naam> aan als een schijfbestand in drive #8"},
/* ru */ {IDCLS_ATTACH_AS_DISK_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AS_DISK_8_SV, "Anslut <namn> som diskettavbildning i enhet 8"},
/* tr */ {IDCLS_ATTACH_AS_DISK_8_TR, "Sürücü #8 disk imajý olarak <isim> yerleþtir"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AS_DISK_9,    N_("Attach <name> as a disk image in drive #9")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AS_DISK_9_DA, "Tilslut <navn> som disk-image i enhed #9"},
/* de */ {IDCLS_ATTACH_AS_DISK_9_DE, "Image Datei <Name> im Laufwerk #9 einlegen"},
/* fr */ {IDCLS_ATTACH_AS_DISK_9_FR, "Insérer <nom> comme image de disque dans le lecteur #9"},
/* hu */ {IDCLS_ATTACH_AS_DISK_9_HU, "<név> lemezképmás csatolása #9-es egységként"},
/* it */ {IDCLS_ATTACH_AS_DISK_9_IT, "Seleziona <nome> come un'immagine di un disco nel drive #9"},
/* ko */ {IDCLS_ATTACH_AS_DISK_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AS_DISK_9_NL, "Koppel <naam> aan als een schijfbestand in drive #9"},
/* ru */ {IDCLS_ATTACH_AS_DISK_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AS_DISK_9_SV, "Anslut <namn> som diskettavbildning i enhet 9"},
/* tr */ {IDCLS_ATTACH_AS_DISK_9_TR, "Sürücü #9 disk imajý olarak <isim> yerleþtir"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AS_DISK_10,    N_("Attach <name> as a disk image in drive #10")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AS_DISK_10_DA, "Tilslut <navn> som disk-image i enhed #10"},
/* de */ {IDCLS_ATTACH_AS_DISK_10_DE, "Image Datei <Name> im Laufwerk #10 einlegen"},
/* fr */ {IDCLS_ATTACH_AS_DISK_10_FR, "Insérer <nom> comme image de disque dans le lecteur #10"},
/* hu */ {IDCLS_ATTACH_AS_DISK_10_HU, "<név> lemezképmás csatolása #10-es egységként"},
/* it */ {IDCLS_ATTACH_AS_DISK_10_IT, "Seleziona <nome> come un'immagine di un disco nel drive #10"},
/* ko */ {IDCLS_ATTACH_AS_DISK_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AS_DISK_10_NL, "Koppel <naam> aan als een schijfbestand in drive #10"},
/* ru */ {IDCLS_ATTACH_AS_DISK_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AS_DISK_10_SV, "Anslut <namn> som diskettavbildning i enhet 10"},
/* tr */ {IDCLS_ATTACH_AS_DISK_10_TR, "Sürücü #10 disk imajý olarak <isim> yerleþtir"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AS_DISK_11,    N_("Attach <name> as a disk image in drive #11")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AS_DISK_11_DA, "Tilslut <navn> som disk-image i enhed #11"},
/* de */ {IDCLS_ATTACH_AS_DISK_11_DE, "Image Datei <Name> im Laufwerk #11 einlegen"},
/* fr */ {IDCLS_ATTACH_AS_DISK_11_FR, "Insérer <nom> comme image de disque dans le lecteur #11"},
/* hu */ {IDCLS_ATTACH_AS_DISK_11_HU, "<név> lemezképmás csatolása #11-es egységként"},
/* it */ {IDCLS_ATTACH_AS_DISK_11_IT, "Seleziona <nome> come un'immagine di un disco nel drive #11"},
/* ko */ {IDCLS_ATTACH_AS_DISK_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AS_DISK_11_NL, "Koppel <naam> aan als een schijfbestand in drive #11"},
/* ru */ {IDCLS_ATTACH_AS_DISK_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AS_DISK_11_SV, "Anslut <namn> som diskettavbildning i enhet 11"},
/* tr */ {IDCLS_ATTACH_AS_DISK_11_TR, "Sürücü #11 disk imajý olarak <isim> yerleþtir"},
#endif

/* kbdbuf.c */
/* en */ {IDCLS_P_STRING,    N_("<string>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_STRING_DA, "<streng>"},
/* de */ {IDCLS_P_STRING_DE, "<String>"},
/* fr */ {IDCLS_P_STRING_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_STRING_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_STRING_IT, "<stringa>"},
/* ko */ {IDCLS_P_STRING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_STRING_NL, "<string>"},
/* ru */ {IDCLS_P_STRING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_STRING_SV, "<sträng>"},
/* tr */ {IDCLS_P_STRING_TR, "<yazý>"},
#endif

/* kbdbuf.c */
/* en */ {IDCLS_PUT_STRING_INTO_KEYBUF,    N_("Put the specified string into the keyboard buffer.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PUT_STRING_INTO_KEYBUF_DA, "Indsæt den angivne streng i tastatur-bufferen."},
/* de */ {IDCLS_PUT_STRING_INTO_KEYBUF_DE, "Definierte Eingabe in Tastaturpuffer bereitstellen."},
/* fr */ {IDCLS_PUT_STRING_INTO_KEYBUF_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_PUT_STRING_INTO_KEYBUF_HU, "A megadott sztring elhelyezése a billentyûzet pufferben."},
/* it */ {IDCLS_PUT_STRING_INTO_KEYBUF_IT, "Metti la stringa specificata nel buffer di tastiera."},
/* ko */ {IDCLS_PUT_STRING_INTO_KEYBUF_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PUT_STRING_INTO_KEYBUF_NL, "Plaats de opgegeven string in de toetsenbordbuffer."},
/* ru */ {IDCLS_PUT_STRING_INTO_KEYBUF_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PUT_STRING_INTO_KEYBUF_SV, "Lägg den angivna strängen i tangentbordsbufferten."},
/* tr */ {IDCLS_PUT_STRING_INTO_KEYBUF_TR, "Klavye arabelleðine belirtilen yazýyý koy."},
#endif

/* log.c */
/* en */ {IDCLS_SPECIFY_LOG_FILE_NAME,    N_("Specify log file name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_LOG_FILE_NAME_DA, "Angiv navn på logfil"},
/* de */ {IDCLS_SPECIFY_LOG_FILE_NAME_DE, "Logdateiname definieren"},
/* fr */ {IDCLS_SPECIFY_LOG_FILE_NAME_FR, "Spécifier le nom du fichier log"},
/* hu */ {IDCLS_SPECIFY_LOG_FILE_NAME_HU, "Adja meg a naplófájl nevét"},
/* it */ {IDCLS_SPECIFY_LOG_FILE_NAME_IT, "Specifica il nome del file di log"},
/* ko */ {IDCLS_SPECIFY_LOG_FILE_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_LOG_FILE_NAME_NL, "Geef de naam van het logbestand"},
/* ru */ {IDCLS_SPECIFY_LOG_FILE_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_LOG_FILE_NAME_SV, "Ange namn på loggfil"},
/* tr */ {IDCLS_SPECIFY_LOG_FILE_NAME_TR, "Log dosyasý ismini belirt"},
#endif

/* log.c */
/* en */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT,    N_("Enable verbose log output.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_DA, "Aktivér omstændeligt log-output"},
/* de */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_DE, "Ausführliche Diagnose aktivieren."},
/* fr */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_IT, "Attiva output dei log verboso."},
/* ko */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_NL, "Activeer verbose log uitvoer."},
/* ru */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_SV, "Aktivera pratsam loggutdata."},
/* tr */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_TR, "Verbose log çýktýsýný aktif et."},
#endif

/* mouse.c */
/* en */ {IDCLS_ENABLE_MOUSE_GRAB,    N_("Enable mouse grab")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_MOUSE_GRAB_DA, "Aktivér overtagelse af mus"},
/* de */ {IDCLS_ENABLE_MOUSE_GRAB_DE, "Maus aktivieren"},
/* fr */ {IDCLS_ENABLE_MOUSE_GRAB_FR, "Saisir la souris"},
/* hu */ {IDCLS_ENABLE_MOUSE_GRAB_HU, "Egér elkapás engedélyezése"},
/* it */ {IDCLS_ENABLE_MOUSE_GRAB_IT, "Attiva cattura mouse"},
/* ko */ {IDCLS_ENABLE_MOUSE_GRAB_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_MOUSE_GRAB_NL, "Gebruiken van de muis inschakelen"},
/* ru */ {IDCLS_ENABLE_MOUSE_GRAB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_MOUSE_GRAB_SV, "Aktivera fångande av mus"},
/* tr */ {IDCLS_ENABLE_MOUSE_GRAB_TR, "Mouse yakalamayý aktif et"},
#endif

/* mouse.c */
/* en */ {IDCLS_DISABLE_MOUSE_GRAB,    N_("Disable mouse grab")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_MOUSE_GRAB_DA, "Deaktivér overtagelse af mus"},
/* de */ {IDCLS_DISABLE_MOUSE_GRAB_DE, "Maus deaktivieren"},
/* fr */ {IDCLS_DISABLE_MOUSE_GRAB_FR, "Ne pas saisir la souris"},
/* hu */ {IDCLS_DISABLE_MOUSE_GRAB_HU, "Egér elkapás tiltása"},
/* it */ {IDCLS_DISABLE_MOUSE_GRAB_IT, "Disattiva cattura mouse"},
/* ko */ {IDCLS_DISABLE_MOUSE_GRAB_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_MOUSE_GRAB_NL, "Gebruiken van de muis uitschakelen"},
/* ru */ {IDCLS_DISABLE_MOUSE_GRAB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_MOUSE_GRAB_SV, "Inaktivera fångande av mus"},
/* tr */ {IDCLS_DISABLE_MOUSE_GRAB_TR, "Mouse yakalamayý pasifleþtir"},
#endif

/* mouse.c */
/* en */ {IDCLS_SELECT_MOUSE_JOY_PORT,    N_("Select the joystick port the mouse is attached to")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SELECT_MOUSE_JOY_PORT_DA, "Vælg hvilken joystickport musen er tilsluttet"},
/* de */ {IDCLS_SELECT_MOUSE_JOY_PORT_DE, "Joystickport für Maus auswählen"},
/* fr */ {IDCLS_SELECT_MOUSE_JOY_PORT_FR, "Sélectionner le port sur lequel attacher la souris"},
/* hu */ {IDCLS_SELECT_MOUSE_JOY_PORT_HU, "Válassza ki a joystick portot, ahová az egér csatolva van"},
/* it */ {IDCLS_SELECT_MOUSE_JOY_PORT_IT, "Seleziona la porta joystick a cui è collegato il mouse"},
/* ko */ {IDCLS_SELECT_MOUSE_JOY_PORT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SELECT_MOUSE_JOY_PORT_NL, "Selecteer de joystickpoort waar de muis aan gekoppelt is"},
/* ru */ {IDCLS_SELECT_MOUSE_JOY_PORT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SELECT_MOUSE_JOY_PORT_SV, "Ange vilken spelport musen är ansluten till"},
/* tr */ {IDCLS_SELECT_MOUSE_JOY_PORT_TR, "Mouse'un baðlý olduðu joystick portunu seçin"},
#endif

/* mouse.c */
/* en */ {IDCLS_SELECT_MOUSE_TYPE,    N_("Select the mouse type (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddles)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SELECT_MOUSE_TYPE_DA, "Vælg mussetype (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddles)"},
/* de */ {IDCLS_SELECT_MOUSE_TYPE_DE, "Maus typ wählen (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddles)"},
/* fr */ {IDCLS_SELECT_MOUSE_TYPE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SELECT_MOUSE_TYPE_HU, "Válassza ki az egér típusát (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddle)"},
/* it */ {IDCLS_SELECT_MOUSE_TYPE_IT, "Seleziona il tipo di mouse (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddle)"},
/* ko */ {IDCLS_SELECT_MOUSE_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SELECT_MOUSE_TYPE_NL, "Selecteer de muis soort (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddles)"},
/* ru */ {IDCLS_SELECT_MOUSE_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SELECT_MOUSE_TYPE_SV, "Välj mustyp (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = paddlar)"},
/* tr */ {IDCLS_SELECT_MOUSE_TYPE_TR, "Mouse tipini seçin (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddle)"},
#endif

/* ps2mouse.c */
/* en */ {IDCLS_ENABLE_PS2MOUSE,    N_("Enable PS/2 mouse on userport")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PS2MOUSE_DA, "Aktivér PS/2-mus på brugerporten"},
/* de */ {IDCLS_ENABLE_PS2MOUSE_DE, "PS/2 Userport Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_PS2MOUSE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_PS2MOUSE_HU, "PS/2 egér engedélyezése a userporton"},
/* it */ {IDCLS_ENABLE_PS2MOUSE_IT, "Attiva mouse PS/2 su userport"},
/* ko */ {IDCLS_ENABLE_PS2MOUSE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_PS2MOUSE_NL, "Aktiveer emulatie van een PS/2 muis op de userport"},
/* ru */ {IDCLS_ENABLE_PS2MOUSE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PS2MOUSE_SV, "Aktivera PS/2-mus på användarport"},
/* tr */ {IDCLS_ENABLE_PS2MOUSE_TR, "Userport üzerinde PS/2 mouse'u aktif et"},
#endif

/* ps2mouse.c */
/* en */ {IDCLS_DISABLE_PS2MOUSE,    N_("Disable PS/2 mouse on userport")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PS2MOUSE_DA, "Deaktivér PS/2-mus på brugerporten"},
/* de */ {IDCLS_DISABLE_PS2MOUSE_DE, "PS/2 Userport Emulation deaktivieren\""},
/* fr */ {IDCLS_DISABLE_PS2MOUSE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_PS2MOUSE_HU, "PS/2 egér tiltása a userporton"},
/* it */ {IDCLS_DISABLE_PS2MOUSE_IT, "Disattiva mouse PS/2 su userport"},
/* ko */ {IDCLS_DISABLE_PS2MOUSE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PS2MOUSE_NL, "Emulatie van een PS/2 muis op de userport uitschakelen"},
/* ru */ {IDCLS_DISABLE_PS2MOUSE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PS2MOUSE_SV, "Inaktivera PS/2-mus på användarport"},
/* tr */ {IDCLS_DISABLE_PS2MOUSE_TR, "Userport üzerinde PS/2 mouse'u pasifleþtir"},
#endif

/* ram.c */
/* en */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE,    N_("Set the value for the very first RAM address after powerup")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_DA, "Angiv værdien for den allerførste RAM adresse efter power-up"},
/* de */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_DE, "Wert für erstes Byte im RAM nach Kaltstart setzen"},
/* fr */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_FR, "Spécifier la valeur de la première adresse RAM après la mise sous tension"},
/* hu */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_HU, "Adja meg a legelsõ RAM cím értékét bekapcsolás után"},
/* it */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_IT, "Imposta il valore del primissimo indirizzo della RAM dopo l'accensione"},
/* ko */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_NL, "Zet de waarde voor het allereerste RAM adres na koude start"},
/* ru */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_SV, "Ange värdet på den allra första RAM-adressen efter strömpåslag"},
/* tr */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_TR, "Güç verildiðinde baþlangýçtaki RAM adreslerine atanacak deðeri belirle"},
#endif

/* ram.c */
/* en */ {IDCLS_P_NUM_OF_BYTES,    N_("<num of bytes>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_NUM_OF_BYTES_DA, "<antal bytes>"},
/* de */ {IDCLS_P_NUM_OF_BYTES_DE, "<Anzahl an Bytes>"},
/* fr */ {IDCLS_P_NUM_OF_BYTES_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_NUM_OF_BYTES_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_NUM_OF_BYTES_IT, "<numero di byte>"},
/* ko */ {IDCLS_P_NUM_OF_BYTES_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_NUM_OF_BYTES_NL, "<aantal bytes>"},
/* ru */ {IDCLS_P_NUM_OF_BYTES_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_NUM_OF_BYTES_SV, "<antal byte>"},
/* tr */ {IDCLS_P_NUM_OF_BYTES_TR, "<byte sayýsý>"},
#endif

/* ram.c */
/* en */ {IDCLS_LENGTH_BLOCK_SAME_VALUE,    N_("Length of memory block initialized with the same value")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_DA, "Længde på hukommelsesblok som initialiseres med samme værdi"},
/* de */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_DE, "Länge des Speicherblocks der mit dem gleichen Wert initialisiert ist"},
/* fr */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_FR, "Longeur du premier bloc mémoire initialisé avec la même valeur"},
/* hu */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_HU, "Azonos értékkel feltöltött memória blokkoknak a hossza"},
/* it */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_IT, "Lunghezza del blocco di memoria inizializzato con lo stesso valore"},
/* ko */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_NL, "Geheugenblokgrootte die dezelfde waarde krijgt bij initialisatie"},
/* ru */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_SV, "Längd på minnesblock som initierats med samma värde"},
/* tr */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_TR, "Ayný deðerle balangýç ayarlarý yapýlan bellek bloðu uzunluðu"},
#endif

/* ram.c */
/* en */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN,    N_("Length of memory block initialized with the same pattern")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_DA, "Længde på hukommelsesblok som initialiseres med samme mønster"},
/* de */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_DE, "Länge des Speicherblocks der mit dem gleichen Muster initialisiert ist"},
/* fr */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_FR, "Longeur du premier bloc mémoire initialisé avec le même pattern"},
/* hu */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_HU, "Azonos mintával feltöltött memória blokkoknak a hossza"},
/* it */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_IT, "Lunghezza del blocco di memoria inizializzato con lo stesso pattern"},
/* ko */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_NL, "Geheugenblokgrootte met hetzelfde patroon bij initialisatie"},
/* ru */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_SV, "Längd på minnesblock som initierats med samma mönster"},
/* tr */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_TR, "Ayný desenle balangýç ayarlarý yapýlan bellek bloðu uzunluðu"},
#endif

/* sound.c */
/* en */ {IDCLS_ENABLE_SOUND_PLAYBACK,    N_("Enable sound playback")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SOUND_PLAYBACK_DA, "Slå lydemulering til"},
/* de */ {IDCLS_ENABLE_SOUND_PLAYBACK_DE, "Sound Wiedergabe einschalten"},
/* fr */ {IDCLS_ENABLE_SOUND_PLAYBACK_FR, "Activer le son"},
/* hu */ {IDCLS_ENABLE_SOUND_PLAYBACK_HU, "Hangok engedélyezése"},
/* it */ {IDCLS_ENABLE_SOUND_PLAYBACK_IT, "Attiva riproduzione audio"},
/* ko */ {IDCLS_ENABLE_SOUND_PLAYBACK_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SOUND_PLAYBACK_NL, "Activeer geluidsweergave"},
/* ru */ {IDCLS_ENABLE_SOUND_PLAYBACK_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SOUND_PLAYBACK_SV, "Aktivera ljudåtergivning"},
/* tr */ {IDCLS_ENABLE_SOUND_PLAYBACK_TR, "Sesi aktif et"},
#endif

/* sound.c */
/* en */ {IDCLS_DISABLE_SOUND_PLAYBACK,    N_("Disable sound playback")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SOUND_PLAYBACK_DA, "Slå lydemulering fra"},
/* de */ {IDCLS_DISABLE_SOUND_PLAYBACK_DE, "Sound Wiedergabe ausschalten"},
/* fr */ {IDCLS_DISABLE_SOUND_PLAYBACK_FR, "Désactiver le son"},
/* hu */ {IDCLS_DISABLE_SOUND_PLAYBACK_HU, "Hangok tiltása"},
/* it */ {IDCLS_DISABLE_SOUND_PLAYBACK_IT, "Disattiva riproduzione audio"},
/* ko */ {IDCLS_DISABLE_SOUND_PLAYBACK_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SOUND_PLAYBACK_NL, "Geluid uitschakelen"},
/* ru */ {IDCLS_DISABLE_SOUND_PLAYBACK_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SOUND_PLAYBACK_SV, "Inaktivera ljudåtergivning"},
/* tr */ {IDCLS_DISABLE_SOUND_PLAYBACK_TR, "Sesi pasifleþtir"},
#endif

/* sound.c */
/* en */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ,    N_("Set sound sample rate to <value> Hz")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_DA, "Sæt lydsamplefrekvens til <værdi> Hz"},
/* de */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_DE, "Setze Sound Sample Rate zu <Wert> Hz"},
/* fr */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_FR, "Régler le taux d'échantillonage à <valeur> Hz"},
/* hu */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_HU, "Hang mintavételezési ráta beállítása <érték> Hz-re"},
/* it */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_IT, "Imposta la velocità di campionamento audio a <valore> Hz"},
/* ko */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_NL, "Zet de geluid sample rate naar <waarde> Hz"},
/* ru */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_SV, "Sätt ljudsamplingshastighet till <värde> Hz"},
/* tr */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_TR, "Ses örnekleme hýzýný <deðer> Hz olarak ayarla"},
#endif

/* sound.c */
/* en */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC,    N_("Set sound buffer size to <value> msec")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_DA, "Sæt lydbufferstørrelse til <værdi> ms"},
/* de */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_DE, "Setze Source Buffer Größe zu <Wert> msek"},
/* fr */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_FR, "Régler la taille du tampon son à <valeur> ms"},
/* hu */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_HU, "A hangpuffer méretét <érték> mp-re állítja"},
/* it */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_IT, "Imposta la dimensione del buffer audio a <valore> msec"},
/* ko */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_NL, "Zet de geluidsbuffergrootte naar <waarde> msec"},
/* ru */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_SV, "Sätt ljudbuffertstorlek till <värde> ms"},
/* tr */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_TR, "Ses arabellek boyutunu <deðer> milisaniye olarak ayarla"},
#endif

/* sound.c */
/* en */ {IDCLS_SET_SOUND_FRAGMENT_SIZE,    N_("Set sound fragment size (0 = small, 1 = medium, 2 = large)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_DA, "Sæt størrelse på lydfragmenter (0 = lille, 1 = medium, 2 = stor)"},
/* de */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_DE, "Setze Sound Fragmentgröße (0 = klein, 1 = mittel, 2 = groß)"},
/* fr */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_IT, "Imposta la dimensione dei frammenti audio (0 = piccola, 1 = media, 2 = grande)"},
/* ko */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_NL, "Zet geluidsfragment grootte (0 = klein, 1 = matig, 2 = groot)"},
/* ru */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_SV, "Välj storlek för ljudfragment (0 = liten, 1= medium, 2 = stor)"},
/* tr */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_TR, "Ses parça boyutunu ayarla (0 = küçük, 1 = orta, 2 = büyük)"},
#endif

/* sound.c */
/* en */ {IDCLS_SPECIFY_SOUND_DRIVER,    N_("Specify sound driver")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SOUND_DRIVER_DA, "Angiv lyddriver"},
/* de */ {IDCLS_SPECIFY_SOUND_DRIVER_DE, "Sound Treiber spezifieren"},
/* fr */ {IDCLS_SPECIFY_SOUND_DRIVER_FR, "Spécifier le pilote de son"},
/* hu */ {IDCLS_SPECIFY_SOUND_DRIVER_HU, "Adja meg a hangmodul nevét"},
/* it */ {IDCLS_SPECIFY_SOUND_DRIVER_IT, "Specifica il driver audio"},
/* ko */ {IDCLS_SPECIFY_SOUND_DRIVER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SOUND_DRIVER_NL, "Geef geluidsstuurprogramma"},
/* ru */ {IDCLS_SPECIFY_SOUND_DRIVER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SOUND_DRIVER_SV, "Ange ljuddrivrutin"},
/* tr */ {IDCLS_SPECIFY_SOUND_DRIVER_TR, "Ses sürücüsü belirt"},
#endif

/* sound.c */
/* en */ {IDCLS_P_ARGS,    N_("<args>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_ARGS_DA, "<argumenter>"},
/* de */ {IDCLS_P_ARGS_DE, "<Argumente>"},
/* fr */ {IDCLS_P_ARGS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_ARGS_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_ARGS_IT, "<argomenti>"},
/* ko */ {IDCLS_P_ARGS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_ARGS_NL, "<parameters>"},
/* ru */ {IDCLS_P_ARGS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_ARGS_SV, "<flaggor>"},
/* tr */ {IDCLS_P_ARGS_TR, "<argümanlar>"},
#endif

/* sound.c */
/* en */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM,    N_("Specify initialization parameters for sound driver")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_DA, "Angiv initialiseringsparametre for lyddriver"},
/* de */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_DE, "Initialisierungsparameter des Sound Treibers spezifizieren"},
/* fr */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_FR, "Spécifier les paramètres d'initialisation pour le pilote son"},
/* hu */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_HU, "Adja meg a hangmodul indulási paramétereit"},
/* it */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_IT, "Specifica i parametri di inizializzazione del driver audio"},
/* ko */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_NL, "Geef de initialisatieparameters voor het geluidsstuurprogramma"},
/* ru */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_SV, "Ange initieringsflaggor för ljuddrivrutin"},
/* tr */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_TR, "Ses sürücüsü için baþlangýç parametrelerini belirt"},
#endif

/* sound.c */
/* en */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER,    N_("Specify recording sound driver")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_DA, "Angiv driver til lydoptagelse"},
/* de */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_DE, "Sound Treiber für Aufnahme spezifizieren"},
/* fr */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_FR, "Spécifier le pilote d'enregistrement"},
/* hu */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_HU, "Adja meg a felvételhez használt hangmodult"},
/* it */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_IT, "Specifica il driver audio di registrazione"},
/* ko */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_NL, "Geef geluidsstuurprogramma voor opname"},
/* ru */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_SV, "Ange ljuddrivrutin för inspelning"},
/* tr */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_TR, "Ses kayýt sürücüsünü belirt"},
#endif

/* sound.c */
/* en */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM,    N_("Specify initialization parameters for recording sound driver")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_DA, "Angiv initialiseringsparametre for driver til lydoptagelse"},
/* de */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_DE, "Initialisierungsparameter für Aufnahme Sound Treiber spezifieren"},
/* fr */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_FR, "Spécifier les paramètres d'initialisation pour le pilote d'enregistrement"},
/* hu */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_HU, "Adja meg a felvételhez használt hangmodul indulási paramétereit"},
/* it */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_IT, "Specifica i parametri di inizializzazione per il driver audio di registrazione"},
/* ko */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_NL, "Geef initialisatieparameters voor het geluidsstuurprogramma voor opname"},
/* ru */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_SV, "Ange initieringsflaggor för ljuddrivrutin för inspelning"},
/* tr */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_TR, "Ses kayýt sürücüsü için baþlangýç parametrelerini belirt"},
#endif

/* sound.c */
/* en */ {IDCLS_P_SYNC,    N_("<sync>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_SYNC_DA, "<sync>"},
/* de */ {IDCLS_P_SYNC_DE, "<Sync>"},
/* fr */ {IDCLS_P_SYNC_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_SYNC_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_SYNC_IT, "<sync>"},
/* ko */ {IDCLS_P_SYNC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_SYNC_NL, "<sync>"},
/* ru */ {IDCLS_P_SYNC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_SYNC_SV, "<synk>"},
/* tr */ {IDCLS_P_SYNC_TR, "<senkron>"},
#endif

/* sound.c */
/* en */ {IDCLS_SET_SOUND_SPEED_ADJUST,    N_("Set sound speed adjustment (0: flexible, 1: adjusting, 2: exact)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_SOUND_SPEED_ADJUST_DA, "Indstil lydjusteringshastighed (0: fleksibel, 1: justerende, 2: nøjagtig)"},
/* de */ {IDCLS_SET_SOUND_SPEED_ADJUST_DE, "Setze Sound Geschwindigkeit Anpassung (0: flexibel, 1: anpassend, 2: exakt)"},
/* fr */ {IDCLS_SET_SOUND_SPEED_ADJUST_FR, "Choisir la méthode d'ajustement du son (0: flexible, 1: ajusté 2: exact)"},
/* hu */ {IDCLS_SET_SOUND_SPEED_ADJUST_HU, "Adja meg a zene sebesség igazítását (0: rugalmas. 1: igazodó, 2: pontos)"},
/* it */ {IDCLS_SET_SOUND_SPEED_ADJUST_IT, "Imposta il tipo di adattamento della velocità audio (0: flessibile, 1: adattabile, 2: esatta)"},
/* ko */ {IDCLS_SET_SOUND_SPEED_ADJUST_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_SOUND_SPEED_ADJUST_NL, "Zet geluidssnelheid aanpassing (0: flexibel, 1: aanpassend, 2: exact)"},
/* ru */ {IDCLS_SET_SOUND_SPEED_ADJUST_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_SOUND_SPEED_ADJUST_SV, "Ställ in ljudhastighetsjustering (0: flexibel, 1: justerande, 2: exakt)"},
/* tr */ {IDCLS_SET_SOUND_SPEED_ADJUST_TR, "Ses hýzý ayarlamasýný yapýn (0: esnek, 1: düzeltme, 2: aynen)"},
#endif

/* sysfile.c */
/* en */ {IDCLS_P_PATH,    N_("<Path>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_PATH_DA, ""},  /* fuzzy */
/* de */ {IDCLS_P_PATH_DE, "<Pfad>"},
/* fr */ {IDCLS_P_PATH_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_PATH_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_PATH_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_P_PATH_KO, "<±æ>"},
/* nl */ {IDCLS_P_PATH_NL, "<Pad>"},
/* ru */ {IDCLS_P_PATH_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_PATH_SV, "<Sökväg>"},
/* tr */ {IDCLS_P_PATH_TR, ""},  /* fuzzy */
#endif

/* sysfile.c */
/* en */ {IDCLS_DEFINE_SYSTEM_FILES_PATH,    N_("Define search path to locate system files")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_DA, "Angiv sti til systemfiler"},
/* de */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_DE, "Suchpfad für Systemdateien definieren"},
/* fr */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_FR, "Définir le chemin de recherche pour trouver les fichiers systèmes"},
/* hu */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_HU, "Keresési útvonal megadása a rendszerfájlok megtalálására"},
/* it */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_IT, "Definisci il path di ricerca per cercare i file di sistema"},
/* ko */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_NL, "Geef het zoek pad waar de systeem bestanden te vinden zijn"},
/* ru */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_SV, "Ange sökväg för att hitta systemfiler"},
/* tr */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_TR, "Sistem dosyalarýnýn konumunu belirlemek için arama yolu tanýmlayýn"},
#endif

/* traps.c */
/* en */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION,    N_("Enable general mechanisms for fast disk/tape emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_DA, "Aktivér generelle mekanismer for hurtig disk-/båndemulering"},
/* de */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_DE, "Allgemeine Mechanismen für schnelle Disk/Band Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_FR, "Activer les méchanismes généraux pour l'émulation disque/datassette rapide"},
/* hu */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_HU, "A lemez/szalag emulációt gyorsító mechanizmusok engedélyezése"},
/* it */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_IT, "Attiva meccanismo generale per l'emulazione veloce del disco/cassetta"},
/* ko */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_NL, "Activeer algemene methoden voor snelle disk/tape emulatie"},
/* ru */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_SV, "Aktivera generella mekanismer för snabb disk-/bandemulering"},
/* tr */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_TR, "Hýzlý disk/teyp emülasyonu için genel mekanizmayý aktif et"},
#endif

/* traps.c */
/* en */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION,    N_("Disable general mechanisms for fast disk/tape emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_DA, "Deaktivér generelle mekanismer for hurtig disk-/båndemulering"},
/* de */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_DE, "Allgemeine Mechanismen für schnelle Disk/Band Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_FR, "Désactiver les méchanismes généraux pour l'émulation disque/datassette rapide"},
/* hu */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_HU, "A lemez/szalag emulációt gyorsító mechanizmusok tiltása"},
/* it */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_IT, "Disattiva meccanismo generale per l'emulazione veloce del disco/cassetta"},
/* ko */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_NL, "Algemene methoden voor snelle disk/tape emulatie uitschakelen"},
/* ru */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_SV, "Inaktivera generella mekanismer för snabb disk-/bandemulering"},
/* tr */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_TR, "Hýzlý disk/teyp emülasyonu için genel mekanizmayý pasifleþtir"},
#endif

/* vsync.c */
/* en */ {IDCLS_LIMIT_SPEED_TO_VALUE,    N_("Limit emulation speed to specified value")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_LIMIT_SPEED_TO_VALUE_DA, "Begræns emuleringshastighed til angiven værdi"},
/* de */ {IDCLS_LIMIT_SPEED_TO_VALUE_DE, "Emulationsgeschwindigkeit auf Wert beschränken."},
/* fr */ {IDCLS_LIMIT_SPEED_TO_VALUE_FR, "Limiter la vitesse d'émulation à une valeur specifiée"},
/* hu */ {IDCLS_LIMIT_SPEED_TO_VALUE_HU, "Emulációs sebesség lehatárolása adott értékre"},
/* it */ {IDCLS_LIMIT_SPEED_TO_VALUE_IT, "Limita la velocità di emulazione al valore specificato"},
/* ko */ {IDCLS_LIMIT_SPEED_TO_VALUE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_LIMIT_SPEED_TO_VALUE_NL, "Beperk emulatiesnelheid tot de opgegeven waarde"},
/* ru */ {IDCLS_LIMIT_SPEED_TO_VALUE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_LIMIT_SPEED_TO_VALUE_SV, "Begränsa emuleringshastighet till angivet värde"},
/* tr */ {IDCLS_LIMIT_SPEED_TO_VALUE_TR, "Emülasyon hýzýný belirtilmiþ deðer ile limitle"},
#endif

/* vsync.c */
/* en */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES,    N_("Update every <value> frames (`0' for automatic)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_DA, "Opdatér for hver <værdi> billeder (\"0\" for automatisk)"},
/* de */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_DE, "Jedes <Wert> Bild aktualisieren (`0' für Automatik)"},
/* fr */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_FR, "Mise à jour toutes les <valeur> images (`0' pour auto.)"},
/* hu */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_HU, "Frissítsen minden <érték> képkocka elteltével (0 automatikust jelent)"},
/* it */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_IT, "Aggiorna ogni <valore> frame (`0' per automatico)"},
/* ko */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_NL, "Elke <waarde> beeld vernieuwen (`0' voor automatisch)"},
/* ru */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_SV, "Uppdatera varje <värde> ramar (\"0\" för automatiskt)"},
/* tr */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_TR, "Her <deðer> framede bir güncelle (otomatik için `0')"},
#endif

/* vsync.c */
/* en */ {IDCLS_ENABLE_WARP_MODE,    N_("Enable warp mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_WARP_MODE_DA, "Aktivér warp-tilstand"},
/* de */ {IDCLS_ENABLE_WARP_MODE_DE, "Warp Mode aktivieren"},
/* fr */ {IDCLS_ENABLE_WARP_MODE_FR, "Activer Turbo"},
/* hu */ {IDCLS_ENABLE_WARP_MODE_HU, "Hipergyors mód engedélyezése"},
/* it */ {IDCLS_ENABLE_WARP_MODE_IT, "Attiva modalità turbo"},
/* ko */ {IDCLS_ENABLE_WARP_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_WARP_MODE_NL, "Activeer warpmodus"},
/* ru */ {IDCLS_ENABLE_WARP_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_WARP_MODE_SV, "Aktivera warpläge"},
/* tr */ {IDCLS_ENABLE_WARP_MODE_TR, "Warp modu aktif et"},
#endif

/* vsync.c */
/* en */ {IDCLS_DISABLE_WARP_MODE,    N_("Disable warp mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_WARP_MODE_DA, "Deaktivér warp-tilstand"},
/* de */ {IDCLS_DISABLE_WARP_MODE_DE, "Warp Mode deaktivieren"},
/* fr */ {IDCLS_DISABLE_WARP_MODE_FR, "Désactiver Turbo"},
/* hu */ {IDCLS_DISABLE_WARP_MODE_HU, "Hipergyors mód tiltása"},
/* it */ {IDCLS_DISABLE_WARP_MODE_IT, "Disattiva modalità turbo"},
/* ko */ {IDCLS_DISABLE_WARP_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_WARP_MODE_NL, "Warpmodus uitschakelen"},
/* ru */ {IDCLS_DISABLE_WARP_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_WARP_MODE_SV, "Inaktivera warpläge"},
/* tr */ {IDCLS_DISABLE_WARP_MODE_TR, "Warp modu pasifleþtir"},
#endif

/* translate.c */
/* en */ {IDCLS_P_ISO_LANGUAGE_CODE,    N_("<iso language code>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_ISO_LANGUAGE_CODE_DA, "<iso-sprogkode>"},
/* de */ {IDCLS_P_ISO_LANGUAGE_CODE_DE, "<iso Sprachcode>"},
/* fr */ {IDCLS_P_ISO_LANGUAGE_CODE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_ISO_LANGUAGE_CODE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_ISO_LANGUAGE_CODE_IT, "<codice iso lingua>"},
/* ko */ {IDCLS_P_ISO_LANGUAGE_CODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_ISO_LANGUAGE_CODE_NL, "<iso taalcode>"},
/* ru */ {IDCLS_P_ISO_LANGUAGE_CODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_ISO_LANGUAGE_CODE_SV, "<iso-språkkod>"},
/* tr */ {IDCLS_P_ISO_LANGUAGE_CODE_TR, "<iso dil kodu>"},
#endif

/* translate.c */
/* en */ {IDCLS_SPECIFY_ISO_LANG_CODE,    N_("Specify the iso code of the language")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_ISO_LANG_CODE_DA, "Angiv ISO-koden for sproget"},
/* de */ {IDCLS_SPECIFY_ISO_LANG_CODE_DE, "Iso Sprachcode spezifizieren"},
/* fr */ {IDCLS_SPECIFY_ISO_LANG_CODE_FR, "Spécifier le code iso du langage"},
/* hu */ {IDCLS_SPECIFY_ISO_LANG_CODE_HU, "Adja meg a nyelv iso kódját"},
/* it */ {IDCLS_SPECIFY_ISO_LANG_CODE_IT, "Specifica il codice ISO della lingua"},
/* ko */ {IDCLS_SPECIFY_ISO_LANG_CODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_ISO_LANG_CODE_NL, "Geef de isocode van de taal"},
/* ru */ {IDCLS_SPECIFY_ISO_LANG_CODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_ISO_LANG_CODE_SV, "Ange ISO-koden för språket"},
/* tr */ {IDCLS_SPECIFY_ISO_LANG_CODE_TR, "Dil için iso kodu belirt"},
#endif

/* c64/plus256k.c */
/* en */ {IDCLS_ENABLE_PLUS256K_EXPANSION,    N_("Enable the PLUS256K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PLUS256K_EXPANSION_DA, "Aktivér PLUS256K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_PLUS256K_EXPANSION_DE, "PLUS256K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_PLUS256K_EXPANSION_FR, "Activer l'expansion PLUS256K RAM"},
/* hu */ {IDCLS_ENABLE_PLUS256K_EXPANSION_HU, "PLUS256K RAM kiterjesztés engedélyezése"},
/* it */ {IDCLS_ENABLE_PLUS256K_EXPANSION_IT, "Attiva espansione RAM PLUS256K"},
/* ko */ {IDCLS_ENABLE_PLUS256K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_PLUS256K_EXPANSION_NL, "Activeer de PLUS256K geheugenuitbreiding"},
/* ru */ {IDCLS_ENABLE_PLUS256K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PLUS256K_EXPANSION_SV, "Aktivera PLUS256K RAM-expansion"},
/* tr */ {IDCLS_ENABLE_PLUS256K_EXPANSION_TR, "PLUS256K RAM geniþletmesini aktif et"},
#endif

/* c64/plus256k.c */
/* en */ {IDCLS_DISABLE_PLUS256K_EXPANSION,    N_("Disable the PLUS256K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PLUS256K_EXPANSION_DA, "Deaktivér PLUS256K RAM-udviddelse"},
/* de */ {IDCLS_DISABLE_PLUS256K_EXPANSION_DE, "PLUS256K RAM Erweiterung deaktivieren"},
/* fr */ {IDCLS_DISABLE_PLUS256K_EXPANSION_FR, "Désactiver l'expansion PLUS256K RAM"},
/* hu */ {IDCLS_DISABLE_PLUS256K_EXPANSION_HU, "PLUS256K RAM kiterjesztés tiltása"},
/* it */ {IDCLS_DISABLE_PLUS256K_EXPANSION_IT, "Disattiva espansione RAM PLUS256K"},
/* ko */ {IDCLS_DISABLE_PLUS256K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PLUS256K_EXPANSION_NL, "De PLUS256K geheugenuitbreiding uitschakelen"},
/* ru */ {IDCLS_DISABLE_PLUS256K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PLUS256K_EXPANSION_SV, "Inaktivera PLUS256K RAM-expansion"},
/* tr */ {IDCLS_DISABLE_PLUS256K_EXPANSION_TR, "PLUS256K RAM geniþletmesini pasifleþtir"},
#endif

/* c64/plus256k.c */
/* en */ {IDCLS_SPECIFY_PLUS256K_NAME,    N_("Specify name of PLUS256K image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PLUS256K_NAME_DA, "Angiv navn på PLUS256K-image"},
/* de */ {IDCLS_SPECIFY_PLUS256K_NAME_DE, "Name der PLUS256K Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_PLUS256K_NAME_FR, "Spécifier le nom de l'image PLUS256K RAM"},
/* hu */ {IDCLS_SPECIFY_PLUS256K_NAME_HU, "Adja meg a PLUS256K-s képmás nevét"},
/* it */ {IDCLS_SPECIFY_PLUS256K_NAME_IT, "Specifica il nome immagine PLUS256K"},
/* ko */ {IDCLS_SPECIFY_PLUS256K_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PLUS256K_NAME_NL, "Geef de naam van het PLUS256K bestand"},
/* ru */ {IDCLS_SPECIFY_PLUS256K_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PLUS256K_NAME_SV, "Ange namn på PLUS256K-avbildning"},
/* tr */ {IDCLS_SPECIFY_PLUS256K_NAME_TR, "PLUS256K imajýnýn ismini belirt"},
#endif

/* c64/plus60k.c */
/* en */ {IDCLS_ENABLE_PLUS60K_EXPANSION,    N_("Enable the PLUS60K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PLUS60K_EXPANSION_DA, "Aktivér PLUS60K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_PLUS60K_EXPANSION_DE, "PLUS60K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_PLUS60K_EXPANSION_FR, "Activer l'expansion PLUS60K RAM"},
/* hu */ {IDCLS_ENABLE_PLUS60K_EXPANSION_HU, "PLUS60K RAM bõvítés engedélyezése"},
/* it */ {IDCLS_ENABLE_PLUS60K_EXPANSION_IT, "Attiva espansione RAM PLUS60K"},
/* ko */ {IDCLS_ENABLE_PLUS60K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_PLUS60K_EXPANSION_NL, "Activeer de PLUS60K geheugenuitbreiding"},
/* ru */ {IDCLS_ENABLE_PLUS60K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PLUS60K_EXPANSION_SV, "Aktivera PLUS60K RAM-expansionen"},
/* tr */ {IDCLS_ENABLE_PLUS60K_EXPANSION_TR, "PLUS60K RAM geniþletmesini aktif et"},
#endif

/* c64/plus60k.c */
/* en */ {IDCLS_DISABLE_PLUS60K_EXPANSION,    N_("Disable the PLUS60K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PLUS60K_EXPANSION_DA, "Deaktivér PLUS60K RAM-udviddelse"},
/* de */ {IDCLS_DISABLE_PLUS60K_EXPANSION_DE, "PLUS60K RAM Erweiterung deaktivieren"},
/* fr */ {IDCLS_DISABLE_PLUS60K_EXPANSION_FR, "Désactiver l'expansion PLUS60K RAM"},
/* hu */ {IDCLS_DISABLE_PLUS60K_EXPANSION_HU, "PLUS60K RAM bõvítés tiltása"},
/* it */ {IDCLS_DISABLE_PLUS60K_EXPANSION_IT, "Disattiva espansione RAM PLUS60K"},
/* ko */ {IDCLS_DISABLE_PLUS60K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PLUS60K_EXPANSION_NL, "De PLUS60K geheugenuitbreiding uitschakelen"},
/* ru */ {IDCLS_DISABLE_PLUS60K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PLUS60K_EXPANSION_SV, "Inaktivera PLUS60K RAM-expansion"},
/* tr */ {IDCLS_DISABLE_PLUS60K_EXPANSION_TR, "PLUS60K RAM geniþletmesini pasifleþtir"},
#endif

/* c64/plus60k.c */
/* en */ {IDCLS_SPECIFY_PLUS60K_NAME,    N_("Specify name of PLUS60K image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PLUS60K_NAME_DA, "Angiv navn på PLUS60K-image"},
/* de */ {IDCLS_SPECIFY_PLUS60K_NAME_DE, "Name der PLUS60K Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_PLUS60K_NAME_FR, "Spécifier le nom de l'image PLUS60K RAM"},
/* hu */ {IDCLS_SPECIFY_PLUS60K_NAME_HU, "Adja meg a nevét a PLUS60K képmásnak"},
/* it */ {IDCLS_SPECIFY_PLUS60K_NAME_IT, "Specifica il nome immagine PLUS60K"},
/* ko */ {IDCLS_SPECIFY_PLUS60K_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PLUS60K_NAME_NL, "Geef de naam van het PLUS60K bestand"},
/* ru */ {IDCLS_SPECIFY_PLUS60K_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PLUS60K_NAME_SV, "Ange namn på plUS60K-avbildning"},
/* tr */ {IDCLS_SPECIFY_PLUS60K_NAME_TR, "PLUS60K imajýnýn ismini belirt"},
#endif

/* c64/plus60k.c */
/* en */ {IDCLS_PLUS60K_BASE,    N_("Base address of the PLUS60K expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PLUS60K_BASE_DA, "Baseadresse for PLUS60K-udviddelse"},
/* de */ {IDCLS_PLUS60K_BASE_DE, "Basis Adresse für PLUS60K Erweiterung"},
/* fr */ {IDCLS_PLUS60K_BASE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_PLUS60K_BASE_HU, "A PLUS60K bõvítés báziscíme"},
/* it */ {IDCLS_PLUS60K_BASE_IT, "Indirizzo base espansione PLUS60K"},
/* ko */ {IDCLS_PLUS60K_BASE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PLUS60K_BASE_NL, "Basisadres van de PLUS60K geheugenuitbreiding"},
/* ru */ {IDCLS_PLUS60K_BASE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PLUS60K_BASE_SV, "Basadress för PLUS60K-expansion"},
/* tr */ {IDCLS_PLUS60K_BASE_TR, "PLUS60K geniþletmesinin taban adresi"},
#endif

/* c64/c64_256k.c */
/* en */ {IDCLS_ENABLE_C64_256K_EXPANSION,    N_("Enable the 256K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_C64_256K_EXPANSION_DA, "Aktivér 256K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_C64_256K_EXPANSION_DE, "256K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_C64_256K_EXPANSION_FR, "Activer l'expansion RAM 256K"},
/* hu */ {IDCLS_ENABLE_C64_256K_EXPANSION_HU, "256K RAM kiterjesztés engedélyezése"},
/* it */ {IDCLS_ENABLE_C64_256K_EXPANSION_IT, "Attiva espansione 256K RAM"},
/* ko */ {IDCLS_ENABLE_C64_256K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_C64_256K_EXPANSION_NL, "Activeer de 256K geheugenuitbreiding"},
/* ru */ {IDCLS_ENABLE_C64_256K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_C64_256K_EXPANSION_SV, "Aktivera 256K RAM-expansion"},
/* tr */ {IDCLS_ENABLE_C64_256K_EXPANSION_TR, "256K RAM geniþletmesini aktif et"},
#endif

/* c64/c64_256k.c */
/* en */ {IDCLS_DISABLE_C64_256K_EXPANSION,    N_("Disable the 256K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_C64_256K_EXPANSION_DA, "Deaktivér 256K RAM-udviddelse"},
/* de */ {IDCLS_DISABLE_C64_256K_EXPANSION_DE, "256K RAM Erweiterung deaktivieren"},
/* fr */ {IDCLS_DISABLE_C64_256K_EXPANSION_FR, "Désactiver l'expansion RAM 256K"},
/* hu */ {IDCLS_DISABLE_C64_256K_EXPANSION_HU, "256K RAM kiterjesztés tiltása"},
/* it */ {IDCLS_DISABLE_C64_256K_EXPANSION_IT, "Disattiva espansione 256K RAM"},
/* ko */ {IDCLS_DISABLE_C64_256K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_C64_256K_EXPANSION_NL, "De 256K geheugenuitbreiding uitschakelen"},
/* ru */ {IDCLS_DISABLE_C64_256K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_C64_256K_EXPANSION_SV, "Inaktivera 256K RAM-expansion"},
/* tr */ {IDCLS_DISABLE_C64_256K_EXPANSION_TR, "256K RAM geniþletmesini pasifleþtir"},
#endif

/* c64/c64_256k.c */
/* en */ {IDCLS_SPECIFY_C64_256K_NAME,    N_("Specify name of 256K image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_C64_256K_NAME_DA, "Angiv navn på 256K-image"},
/* de */ {IDCLS_SPECIFY_C64_256K_NAME_DE, "Name der 256K Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_C64_256K_NAME_FR, "Spécifier le nom de l'image 256K"},
/* hu */ {IDCLS_SPECIFY_C64_256K_NAME_HU, "Adja meg a 256K-s képmás nevét"},
/* it */ {IDCLS_SPECIFY_C64_256K_NAME_IT, "Specifica il nome immagine 256K"},
/* ko */ {IDCLS_SPECIFY_C64_256K_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_C64_256K_NAME_NL, "Geef de naam van het 256K bestand"},
/* ru */ {IDCLS_SPECIFY_C64_256K_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_C64_256K_NAME_SV, "Ange namn på 256K-avbildning"},
/* tr */ {IDCLS_SPECIFY_C64_256K_NAME_TR, "256K imajýnýn ismini belirt"},
#endif

/* c64/c64_256k.c */
/* en */ {IDCLS_C64_256K_BASE,    N_("Base address of the 256K expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_C64_256K_BASE_DA, "Baseadresse for 256K-udviddelse"},
/* de */ {IDCLS_C64_256K_BASE_DE, "Basis Adresse für 256K RAM Erweiterung"},
/* fr */ {IDCLS_C64_256K_BASE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_C64_256K_BASE_HU, "A 256K-s RAM kiterjesztés báziscíme"},
/* it */ {IDCLS_C64_256K_BASE_IT, "Indirizzo base dell'espansione 256K"},
/* ko */ {IDCLS_C64_256K_BASE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_C64_256K_BASE_NL, "Basisadres van de 256K geheugenuitbreiding"},
/* ru */ {IDCLS_C64_256K_BASE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_C64_256K_BASE_SV, "Basadress för 256K-expansionen"},
/* tr */ {IDCLS_C64_256K_BASE_TR, "256K geniþletmesinin taban adresi"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_STB_CART,    N_("Attach raw Structured Basic cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_STB_CART_DA, "Tilslut rå Strucured BASIC-cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_STB_CART_DE, "Erweiterungsmodul Structured Basic (raw) Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_STB_CART_FR, "Insérer une cartouche Raw Structured Basic"},
/* hu */ {IDCLS_ATTACH_RAW_STB_CART_HU, "Structured Basic cartridge képmás csatolása"},
/* it */ {IDCLS_ATTACH_RAW_STB_CART_IT, "Seleziona immagine cartuccia Structured Basic"},
/* ko */ {IDCLS_ATTACH_RAW_STB_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_STB_CART_NL, "Koppel binair Structured Basic cartridge bestand aan"},
/* ru */ {IDCLS_ATTACH_RAW_STB_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_STB_CART_SV, "Anslut rå Strucured Basic-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_STB_CART_TR, "Düz yapýlandýrýlmýþ Basic kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_SE5_CART,    N_("Attach raw 16kB Super Explode V5 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_SE5_CART_DA, "Tilslut råt 16KB Super Explode V5 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_SE5_CART_DE, "16kB Super Explode V5 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_SE5_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_SE5_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_SE5_CART_IT, "Seleziona immagine cartuccia Super Explode V5 di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_SE5_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_SE5_CART_NL, "Koppel binair 16kB Super Snapshot V5 cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_SE5_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_SE5_CART_SV, "Anslut rå 16kB Super Explode V5-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_SE5_CART_TR, "Düz 16kB Super Explode V5 kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART,    N_("Attach raw 64kB Super Games cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_DA, "Tilslut råt 64KB Super Games cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_DE, "64kB Super Games Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_IT, "Seleziona immagine cartuccia Super Games di 64kB"},
/* ko */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_NL, "Koppel binair 64kB Super Games cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_SV, "Anslut rå 64kB-Super Games-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_TR, "Düz 64kB Super Games kartuþ imajý yerleþtir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART,    N_("Attach raw 16kB Simons Basic cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_DA, "Tilslut råt 16KB Simons Basic cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_DE, "16kB Simons Basic Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_IT, "Seleziona immagine cartuccia Simons Basic di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_NL, "Koppel binair 16kB Simons Basic cartridge bestand"},
/* ru */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_SV, "Anslut rå 16kB Simons Basic-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_TR, "Düz 16kB Simons Basic kartuþ imajý yerleþtir"},
#endif

/* plus4/plus4memcsory256k.c */
/* en */ {IDCLS_ENABLE_CS256K_EXPANSION,    N_("Enable the CSORY 256K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_CS256K_EXPANSION_DA, "Aktivér CSORY 256K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_CS256K_EXPANSION_DE, "CSORY 256K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_CS256K_EXPANSION_FR, "Activer l'expansion RAM 256K CSORY"},
/* hu */ {IDCLS_ENABLE_CS256K_EXPANSION_HU, "CSORY 256K RAM kiterjesztés engedélyezése"},
/* it */ {IDCLS_ENABLE_CS256K_EXPANSION_IT, "Attiva espansione RAM CSORY 256K"},
/* ko */ {IDCLS_ENABLE_CS256K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_CS256K_EXPANSION_NL, "Activeer de CSORY 256K geheugenuitbreiding"},
/* ru */ {IDCLS_ENABLE_CS256K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_CS256K_EXPANSION_SV, "Aktivera CSORY 256K RAM-expansion"},
/* tr */ {IDCLS_ENABLE_CS256K_EXPANSION_TR, "CSORY 256K RAM geniþletmesini aktif et"},
#endif

/* plus4/plus4memhannes256k.c */
/* en */ {IDCLS_ENABLE_H256K_EXPANSION,    N_("Enable the HANNES 256K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_H256K_EXPANSION_DA, "Aktivér HANNES 256K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_H256K_EXPANSION_DE, "HANNES 256K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_H256K_EXPANSION_FR, "Activer l'expansion RAM 256K HANNES"},
/* hu */ {IDCLS_ENABLE_H256K_EXPANSION_HU, "HANNES 256K RAM kiterjesztés engedélyezése"},
/* it */ {IDCLS_ENABLE_H256K_EXPANSION_IT, "Attiva espansione RAM HANNES 256K"},
/* ko */ {IDCLS_ENABLE_H256K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_H256K_EXPANSION_NL, "Activeer de HANNES 256K geheugenuitbreiding"},
/* ru */ {IDCLS_ENABLE_H256K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_H256K_EXPANSION_SV, "Aktivera HANNES 256K RAM-expansion"},
/* tr */ {IDCLS_ENABLE_H256K_EXPANSION_TR, "HANNES 256K RAM geniþletmesini aktif et"},
#endif

/* plus4/plus4memhannes256k.c */
/* en */ {IDCLS_ENABLE_H1024K_EXPANSION,    N_("Enable the HANNES 1024K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_H1024K_EXPANSION_DA, "Aktivér HANNES 1024K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_H1024K_EXPANSION_DE, "HANNES 1024K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_H1024K_EXPANSION_FR, "Activer l'expansion RAM 1024K HANNES"},
/* hu */ {IDCLS_ENABLE_H1024K_EXPANSION_HU, "HANNES 1024K RAM kiterjesztés engedélyezése"},
/* it */ {IDCLS_ENABLE_H1024K_EXPANSION_IT, "Attiva espansione RAM HANNES 1024K"},
/* ko */ {IDCLS_ENABLE_H1024K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_H1024K_EXPANSION_NL, "Activeer de HANNES 1024K geheugenuitbreiding"},
/* ru */ {IDCLS_ENABLE_H1024K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_H1024K_EXPANSION_SV, "Aktivera HANNES 1024K RAM-expansion"},
/* tr */ {IDCLS_ENABLE_H1024K_EXPANSION_TR, "HANNES 1024K RAM geniþletmesini aktif et"},
#endif

/* plus4/plus4memhannes256k.c */
/* en */ {IDCLS_ENABLE_H4096K_EXPANSION,    N_("Enable the HANNES 4096K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_H4096K_EXPANSION_DA, "Aktivér HANNES 4096K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_H4096K_EXPANSION_DE, "HANNES 4096K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_H4096K_EXPANSION_FR, "Activer l'expansion RAM 4096K HANNES"},
/* hu */ {IDCLS_ENABLE_H4096K_EXPANSION_HU, "HANNES 4096K RAM kiterjesztés engedélyezése"},
/* it */ {IDCLS_ENABLE_H4096K_EXPANSION_IT, "Attiva espansione RAM HANNES 4096K"},
/* ko */ {IDCLS_ENABLE_H4096K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_H4096K_EXPANSION_NL, "Activeer de HANNES 4096K geheugenuitbreiding"},
/* ru */ {IDCLS_ENABLE_H4096K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_H4096K_EXPANSION_SV, "Aktivera HANNES 4096K RAM-expansion"},
/* tr */ {IDCLS_ENABLE_H4096K_EXPANSION_TR, "HANNES 4096K RAM geniþletmesini aktif et"},
#endif

/* c64dtv/c64dtvblitter.c */
/* en */ {IDCLS_SPECIFY_DTV_REVISION,    N_("Specify DTV Revision (2: DTV2, 3: DTV3)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_DTV_REVISION_DA, "Angiv DTV-revision (2: DTV2, 3: DTV3)"},
/* de */ {IDCLS_SPECIFY_DTV_REVISION_DE, "DTV Revision definieren (2: DTV2, 3: DTV3)"},
/* fr */ {IDCLS_SPECIFY_DTV_REVISION_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_DTV_REVISION_HU, "Adja meg a DTV verzióját (2: DTV2, 3: DTV3)"},
/* it */ {IDCLS_SPECIFY_DTV_REVISION_IT, "Specifica la revisione DTV (2: DTV2, 3: DTV3)"},
/* ko */ {IDCLS_SPECIFY_DTV_REVISION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_DTV_REVISION_NL, "Geef de DTV revisie (2: DTV2, 3: DTV3)"},
/* ru */ {IDCLS_SPECIFY_DTV_REVISION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_DTV_REVISION_SV, "Ange DTV-revision (2: DTV2, 3: DTV3)"},
/* tr */ {IDCLS_SPECIFY_DTV_REVISION_TR, "DTV Revizyonunu belirt (2: DTV2, 3: DTV3)"},
#endif

/* c64dtv/c64dtvblitter.c */
/* en */ {IDCLS_ENABLE_DTV_BLITTER_LOG,    N_("Enable DTV blitter logs.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DTV_BLITTER_LOG_DA, "Aktivér DTV-blitterlog."},
/* de */ {IDCLS_ENABLE_DTV_BLITTER_LOG_DE, "DTV Blitter Log aktivieren."},
/* fr */ {IDCLS_ENABLE_DTV_BLITTER_LOG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_DTV_BLITTER_LOG_HU, "DTV blit naplók engedélyezése."},
/* it */ {IDCLS_ENABLE_DTV_BLITTER_LOG_IT, "Attiva log del blitter DTV."},
/* ko */ {IDCLS_ENABLE_DTV_BLITTER_LOG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DTV_BLITTER_LOG_NL, "Aktiveer DTV blitter logs."},
/* ru */ {IDCLS_ENABLE_DTV_BLITTER_LOG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DTV_BLITTER_LOG_SV, "Aktivera DTV-blitterloggar."},
/* tr */ {IDCLS_ENABLE_DTV_BLITTER_LOG_TR, "DTV blitter loglarýný aktif et"},
#endif

/* c64dtv/c64dtvblitter.c */
/* en */ {IDCLS_DISABLE_DTV_BLITTER_LOG,    N_("Disable DTV blitter logs.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DTV_BLITTER_LOG_DA, "Deaktivér DTV-blitterlog."},
/* de */ {IDCLS_DISABLE_DTV_BLITTER_LOG_DE, "DTV Blitter Log deaktivieren."},
/* fr */ {IDCLS_DISABLE_DTV_BLITTER_LOG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_DTV_BLITTER_LOG_HU, "DTV blit naplók tiltása."},
/* it */ {IDCLS_DISABLE_DTV_BLITTER_LOG_IT, "Disattiva log del blitter DTV."},
/* ko */ {IDCLS_DISABLE_DTV_BLITTER_LOG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DTV_BLITTER_LOG_NL, "DTV Blitter logs uitschakelen."},
/* ru */ {IDCLS_DISABLE_DTV_BLITTER_LOG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DTV_BLITTER_LOG_SV, "Inaktivera DTV-blitterloggar."},
/* tr */ {IDCLS_DISABLE_DTV_BLITTER_LOG_TR, "DTV blitter loglarýný pasifleþtir"},
#endif

/* c64dtv/c64dtvdma.c */
/* en */ {IDCLS_ENABLE_DTV_DMA_LOG,    N_("Enable DTV DMA logs.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DTV_DMA_LOG_DA, "Aktivér DTV DMA-log."},
/* de */ {IDCLS_ENABLE_DTV_DMA_LOG_DE, "DTV DMA Logs aktivieren."},
/* fr */ {IDCLS_ENABLE_DTV_DMA_LOG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_DTV_DMA_LOG_HU, "DTV DMA naplók engedélyezése."},
/* it */ {IDCLS_ENABLE_DTV_DMA_LOG_IT, "Attiva log DMA DTV."},
/* ko */ {IDCLS_ENABLE_DTV_DMA_LOG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DTV_DMA_LOG_NL, "Aktiveer DTV DMA logs."},
/* ru */ {IDCLS_ENABLE_DTV_DMA_LOG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DTV_DMA_LOG_SV, "Aktivera DTV DMA-loggning."},
/* tr */ {IDCLS_ENABLE_DTV_DMA_LOG_TR, "DTV DMA loglarýný aktif et"},
#endif

/* c64dtv/c64dtvdma.c */
/* en */ {IDCLS_DISABLE_DTV_DMA_LOG,    N_("Disable DTV DMA logs.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DTV_DMA_LOG_DA, "Deaktivér DTV DMA-log."},
/* de */ {IDCLS_DISABLE_DTV_DMA_LOG_DE, "DTV DMA Logs deaktivieren."},
/* fr */ {IDCLS_DISABLE_DTV_DMA_LOG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_DTV_DMA_LOG_HU, "DTV DMA naplók tiltása."},
/* it */ {IDCLS_DISABLE_DTV_DMA_LOG_IT, "Disattiva log DMA DTV."},
/* ko */ {IDCLS_DISABLE_DTV_DMA_LOG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DTV_DMA_LOG_NL, "DTV DMA logs uitschakelen."},
/* ru */ {IDCLS_DISABLE_DTV_DMA_LOG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DTV_DMA_LOG_SV, "Inaktivera DTV DMA-loggning."},
/* tr */ {IDCLS_DISABLE_DTV_DMA_LOG_TR, "DTV DMA loglarýný pasifleþtir"},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDCLS_SPECIFY_C64DTVROM_NAME,    N_("Specify name of C64DTV ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_C64DTVROM_NAME_DA, "Angiv navn på C64DTV-ROM-image"},
/* de */ {IDCLS_SPECIFY_C64DTVROM_NAME_DE, "Name von C64DTV ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_C64DTVROM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_C64DTVROM_NAME_HU, "Adja meg a C64DTV ROM képmás nevét"},
/* it */ {IDCLS_SPECIFY_C64DTVROM_NAME_IT, "Specifica il nome immagine ROM DTV"},
/* ko */ {IDCLS_SPECIFY_C64DTVROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_C64DTVROM_NAME_NL, "Geef de naam van her C64DTV ROM bestand"},
/* ru */ {IDCLS_SPECIFY_C64DTVROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_C64DTVROM_NAME_SV, "Ange namn på C64DTV-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_C64DTVROM_NAME_TR, "C64DTV ROM imajýnýn ismini belirt"},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDCLS_ENABLE_C64DTVROM_RW,    N_("Enable writes to C64DTV ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_C64DTVROM_RW_DA, "Tillad skrivning til DTV-ROM-image"},
/* de */ {IDCLS_ENABLE_C64DTVROM_RW_DE, "Erlaube Schreibzugriff auf DTV ROM Datei"},
/* fr */ {IDCLS_ENABLE_C64DTVROM_RW_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_C64DTVROM_RW_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_C64DTVROM_RW_IT, "Attiva scrittura su immagini ROM C64DTV"},
/* ko */ {IDCLS_ENABLE_C64DTVROM_RW_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_C64DTVROM_RW_NL, "Aktiveer schrijven naar DTV ROM bestand"},
/* ru */ {IDCLS_ENABLE_C64DTVROM_RW_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_C64DTVROM_RW_SV, "Aktivera skrivning till C64DTV-ROM-avbildning"},
/* tr */ {IDCLS_ENABLE_C64DTVROM_RW_TR, "C64DTV ROM imajýnda yazmalarý aktif et"},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDCLS_DISABLE_C64DTVROM_RW,    N_("Disable writes to C64DTV ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_C64DTVROM_RW_DA, ""},  /* fuzzy */
/* de */ {IDCLS_DISABLE_C64DTVROM_RW_DE, "Schreibzugriff auf C64DTV ROM Image verhindern"},
/* fr */ {IDCLS_DISABLE_C64DTVROM_RW_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_C64DTVROM_RW_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_C64DTVROM_RW_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_DISABLE_C64DTVROM_RW_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_C64DTVROM_RW_NL, "Schrijven naar C64DTV ROM bestand uitschakelen"},
/* ru */ {IDCLS_DISABLE_C64DTVROM_RW_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_C64DTVROM_RW_SV, "Inaktivera skrivning till C64DTV-ROM-avbildning"},
/* tr */ {IDCLS_DISABLE_C64DTVROM_RW_TR, ""},  /* fuzzy */
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDCLS_ENABLE_DTV_FLASH_LOG,    N_("Enable DTV flash chip logs.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DTV_FLASH_LOG_DA, "Aktivér logs for DTV-flashkreds."},
/* de */ {IDCLS_ENABLE_DTV_FLASH_LOG_DE, "DTV Flashchip Log aktivieren."},
/* fr */ {IDCLS_ENABLE_DTV_FLASH_LOG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_DTV_FLASH_LOG_HU, "DTV flash chip naplók engedélyezése."},
/* it */ {IDCLS_ENABLE_DTV_FLASH_LOG_IT, "Attiva log del chip flash DTV."},
/* ko */ {IDCLS_ENABLE_DTV_FLASH_LOG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DTV_FLASH_LOG_NL, "Aktiveer DTV flash chip logs."},
/* ru */ {IDCLS_ENABLE_DTV_FLASH_LOG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DTV_FLASH_LOG_SV, "Aktivera loggar för DTV-flashkrets."},
/* tr */ {IDCLS_ENABLE_DTV_FLASH_LOG_TR, "DTV flash çip loglarýný aktif et."},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDCLS_DISABLE_DTV_FLASH_LOG,    N_("Disable DTV flash chip logs.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DTV_FLASH_LOG_DA, "Deaktivér logs for DTV-flashkreds."},
/* de */ {IDCLS_DISABLE_DTV_FLASH_LOG_DE, "DTV Flashchip Log deaktivieren."},
/* fr */ {IDCLS_DISABLE_DTV_FLASH_LOG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_DTV_FLASH_LOG_HU, "DTV flash chip naplók tiltása."},
/* it */ {IDCLS_DISABLE_DTV_FLASH_LOG_IT, "Disattiva log del chip flash DTV."},
/* ko */ {IDCLS_DISABLE_DTV_FLASH_LOG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DTV_FLASH_LOG_NL, "DTV flash chip logs uitschakelen."},
/* ru */ {IDCLS_DISABLE_DTV_FLASH_LOG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DTV_FLASH_LOG_SV, "Inaktivera loggar för DTV-flashkrets."},
/* tr */ {IDCLS_DISABLE_DTV_FLASH_LOG_TR, "DTV flash çip loglarýný pasifleþtir."},
#endif

/* c64dtv/flash-trap.c */
/* en */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS,    N_("Use <name> as directory for flash file system device")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_DA, "Brug <navn> som katalog for filsystembaseret flashenhed"},
/* de */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_DE, "Benutze <Name> für Verzeichnis Gerät Flash Dateisystem"},
/* fr */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_HU, "<név> könyvtár használata a flash fájlrendszer eszközhöz"},
/* it */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_IT, "Una <nome> come directory per il file system flash"},
/* ko */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_NL, "Gebruik <naam> als directory voor het flash bestandssysteem apparaat"},
/* ru */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_SV, "Ange <namn> som katalog för filsystemsbaserad flashenhet"},
/* tr */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_TR, "Flash dosya sistem aygýtý için <isim>'i dizin olarak kullan"},
#endif

/* c64dtv/flash-trap.c */
/* en */ {IDCLS_ENABLE_TRUE_FLASH_FS,    N_("Enable true hardware flash file system")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_TRUE_FLASH_FS_DA, "Aktivér ægte hardwareemulering af flashfilsystem"},
/* de */ {IDCLS_ENABLE_TRUE_FLASH_FS_DE, "Präzises Hardware Flashdateisystem aktivieren"},
/* fr */ {IDCLS_ENABLE_TRUE_FLASH_FS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_TRUE_FLASH_FS_HU, "Igazi hardver flash fájlrendszer engedélyezése"},
/* it */ {IDCLS_ENABLE_TRUE_FLASH_FS_IT, "Attiva emulazione hardware del file system flash"},
/* ko */ {IDCLS_ENABLE_TRUE_FLASH_FS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_TRUE_FLASH_FS_NL, "Activeer hardwarmatige flash bestandssysteem"},
/* ru */ {IDCLS_ENABLE_TRUE_FLASH_FS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_TRUE_FLASH_FS_SV, "Aktivera äkta maskinvaru-flashfilsystem"},
/* tr */ {IDCLS_ENABLE_TRUE_FLASH_FS_TR, "Gerçek donaným flash dosya sistemini aktif et"},
#endif

/* c64dtv/flash-trap.c */
/* en */ {IDCLS_DISABLE_TRUE_FLASH_FS,    N_("Disable true hardware flash file system")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_TRUE_FLASH_FS_DA, "Deaktivér ægte hardwareemulering af flashfilsystem"},
/* de */ {IDCLS_DISABLE_TRUE_FLASH_FS_DE, "Präzises Hardware Flashdateisystem deaktivieren"},
/* fr */ {IDCLS_DISABLE_TRUE_FLASH_FS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_TRUE_FLASH_FS_HU, "Igazi hardver flash fájlrendszer tiltása"},
/* it */ {IDCLS_DISABLE_TRUE_FLASH_FS_IT, "Disattiva emulazione hardware del file system flash"},
/* ko */ {IDCLS_DISABLE_TRUE_FLASH_FS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_TRUE_FLASH_FS_NL, "Hardwatematig flash bestandssysteem uitschakelen"},
/* ru */ {IDCLS_DISABLE_TRUE_FLASH_FS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_TRUE_FLASH_FS_SV, "Inaktivera maskinvaruemelring för flashfilsystem"},
/* tr */ {IDCLS_DISABLE_TRUE_FLASH_FS_TR, "Gerçek donaným flash dosya sistemini pasifleþtir"},
#endif

#ifdef HAVE_MIDI
/* midi.c */
/* en */ {IDCLS_ENABLE_MIDI_EMU,    N_("Enable MIDI emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_MIDI_EMU_DA, "Aktivér MIDI-emulering"},
/* de */ {IDCLS_ENABLE_MIDI_EMU_DE, "MIDI Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_MIDI_EMU_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_MIDI_EMU_HU, "MIDI emuláció engedélyezése"},
/* it */ {IDCLS_ENABLE_MIDI_EMU_IT, "Attiva emulazione MIDI"},
/* ko */ {IDCLS_ENABLE_MIDI_EMU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_MIDI_EMU_NL, "Activeer MIDI emulatie"},
/* ru */ {IDCLS_ENABLE_MIDI_EMU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_MIDI_EMU_SV, "Aktivera MIDI-emulering"},
/* tr */ {IDCLS_ENABLE_MIDI_EMU_TR, "MIDI emülasyonunu aktif et"},
#endif

/* midi.c */
/* en */ {IDCLS_DISABLE_MIDI_EMU,    N_("Disable MIDI emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_MIDI_EMU_DA, "Deaktivér MIDI-emulering"},
/* de */ {IDCLS_DISABLE_MIDI_EMU_DE, "MIDI Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_MIDI_EMU_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_MIDI_EMU_HU, "MIDI emuláció tiltása"},
/* it */ {IDCLS_DISABLE_MIDI_EMU_IT, "Disattiva emulazione MIDI"},
/* ko */ {IDCLS_DISABLE_MIDI_EMU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_MIDI_EMU_NL, "MIDI emulatie uitschakelen"},
/* ru */ {IDCLS_DISABLE_MIDI_EMU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_MIDI_EMU_SV, "Inaktivera MIDI-emulering"},
/* tr */ {IDCLS_DISABLE_MIDI_EMU_TR, "MIDI emülasyonunu pasifleþtir"},
#endif

/* c64/cart/c64-midi.c */
/* en */ {IDCLS_SPECIFY_C64_MIDI_TYPE,    N_("MIDI interface type (0: Sequential, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_C64_MIDI_TYPE_DA, "MIDI-interfacetype (0: Sekventiel, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
/* de */ {IDCLS_SPECIFY_C64_MIDI_TYPE_DE, "MIDI Interface Typ (0: Sequential, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
/* fr */ {IDCLS_SPECIFY_C64_MIDI_TYPE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_C64_MIDI_TYPE_HU, "MIDI interfész típus (0: soros, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
/* it */ {IDCLS_SPECIFY_C64_MIDI_TYPE_IT, "Tipo interfaccia MIDI (0: Sequential, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
/* ko */ {IDCLS_SPECIFY_C64_MIDI_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_C64_MIDI_TYPE_NL, "MIDI interface soort (0: Sequential, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
/* ru */ {IDCLS_SPECIFY_C64_MIDI_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_C64_MIDI_TYPE_SV, "Typ av MIDI-gränssnitt (0: sekventiell, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
/* tr */ {IDCLS_SPECIFY_C64_MIDI_TYPE_TR, "MIDI arabirim tipi (0: Sequential, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
#endif
#endif

/* plus4/digiblaster.c */
/* en */ {IDCLS_ENABLE_DIGIBLASTER,    N_("Enable the digiblaster add-on")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DIGIBLASTER_DA, "Aktivér digiblaster-tilføjelse"},
/* de */ {IDCLS_ENABLE_DIGIBLASTER_DE, "Digiblaster add-on aktivieren"},
/* fr */ {IDCLS_ENABLE_DIGIBLASTER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_DIGIBLASTER_HU, "Digiblaster engedélyezése"},
/* it */ {IDCLS_ENABLE_DIGIBLASTER_IT, "Attiva l'estensione digiblaster"},
/* ko */ {IDCLS_ENABLE_DIGIBLASTER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DIGIBLASTER_NL, "Activeer de digiblaster add-on"},
/* ru */ {IDCLS_ENABLE_DIGIBLASTER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DIGIBLASTER_SV, "Aktivera digiblaster-tillägg"},
/* tr */ {IDCLS_ENABLE_DIGIBLASTER_TR, "Digiblaster eklentisini aktif et"},
#endif

/* plus4/digiblaster.c */
/* en */ {IDCLS_DISABLE_DIGIBLASTER,    N_("Disable the digiblaster add-on")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DIGIBLASTER_DA, "Deaktivér digiblaster-tilføjelse"},
/* de */ {IDCLS_DISABLE_DIGIBLASTER_DE, "Digiblaster add-on deaktivieren"},
/* fr */ {IDCLS_DISABLE_DIGIBLASTER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_DIGIBLASTER_HU, "Digiblaster tiltása"},
/* it */ {IDCLS_DISABLE_DIGIBLASTER_IT, "Disattiva l'estensione digiblaster"},
/* ko */ {IDCLS_DISABLE_DIGIBLASTER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DIGIBLASTER_NL, "De digiblaster add-on uitschakelen"},
/* ru */ {IDCLS_DISABLE_DIGIBLASTER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DIGIBLASTER_SV, "Inaktivera digiblaster-tillägg"},
/* tr */ {IDCLS_DISABLE_DIGIBLASTER_TR, "Digiblaster eklentisini pasifleþtir"},
#endif

/* plus4/plus4speech.c */
/* en */ {IDCLS_ENABLE_PLUS4SPEECH,    N_("Enable the v364 speech add-on")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PLUS4SPEECH_DA, "Aktivér v364 Speech-tilføjelse"},
/* de */ {IDCLS_ENABLE_PLUS4SPEECH_DE, "v364 Spracherweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_PLUS4SPEECH_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_PLUS4SPEECH_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_PLUS4SPEECH_IT, "Attiva l'estensione v364 speech"},
/* ko */ {IDCLS_ENABLE_PLUS4SPEECH_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_PLUS4SPEECH_NL, "Activeer de v364 spraak add-on"},
/* ru */ {IDCLS_ENABLE_PLUS4SPEECH_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PLUS4SPEECH_SV, "Aktivera v364-rösttillägg"},
/* tr */ {IDCLS_ENABLE_PLUS4SPEECH_TR, "V364 speech eklentisini aktif et"},
#endif

/* plus4/plus4speech.c */
/* en */ {IDCLS_DISABLE_PLUS4SPEECH,    N_("Disable the v364 speech add-on")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PLUS4SPEECH_DA, "Deaktivér v364 Speech-tilføjelse"},
/* de */ {IDCLS_DISABLE_PLUS4SPEECH_DE, "v364 Spracherweiterung deaktivieren"},
/* fr */ {IDCLS_DISABLE_PLUS4SPEECH_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_PLUS4SPEECH_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_PLUS4SPEECH_IT, "Disattiva l'estensione v364 speech"},
/* ko */ {IDCLS_DISABLE_PLUS4SPEECH_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PLUS4SPEECH_NL, "De v364 spraak add-on uitschakelen"},
/* ru */ {IDCLS_DISABLE_PLUS4SPEECH_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PLUS4SPEECH_SV, "Inaktivera v364-rösttillägg"},
/* tr */ {IDCLS_DISABLE_PLUS4SPEECH_TR, "V364 speech eklentisini pasifleþtir"},
#endif

/* plus4/plus4speech.c */
/* en */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE,    N_("Attach Speech ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_DA, "Tilslut Speech ROM image"},
/* de */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_DE, "Spracherweiterung ROM Imagedatei einlegen"},
/* fr */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_IT, "Seleziona immagine Speech ROM"},
/* ko */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_NL, "Koppel spraak ROM bestand aan"},
/* ru */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_SV, "Anslut röst-ROM-avbildning"},
/* tr */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_TR, "Speech ROM imajýný yerleþtir"},
#endif

/* plus4/sidcartjoy.c */
/* en */ {IDCLS_ENABLE_SIDCARTJOY,    N_("Enable SID cartridge joystick")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SIDCARTJOY_DA, "Aktivér SID-cartridge joystick"},
/* de */ {IDCLS_ENABLE_SIDCARTJOY_DE, "SIDcart Modul aktivieren"},
/* fr */ {IDCLS_ENABLE_SIDCARTJOY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_SIDCARTJOY_HU, "SID cartridge botkormány engedélyezése"},
/* it */ {IDCLS_ENABLE_SIDCARTJOY_IT, "Attiva joystick su cartuccia SID"},
/* ko */ {IDCLS_ENABLE_SIDCARTJOY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SIDCARTJOY_NL, "Activeer SID cartridge joystick"},
/* ru */ {IDCLS_ENABLE_SIDCARTJOY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SIDCARTJOY_SV, "Aktivera SID-insticksmodul-styrspak"},
/* tr */ {IDCLS_ENABLE_SIDCARTJOY_TR, "SID kartuþu joystick'ini aktif et"},
#endif

/* plus4/sidcartjoy.c */
/* en */ {IDCLS_DISABLE_SIDCARTJOY,    N_("Disable SID cartridge joystick")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SIDCARTJOY_DA, "Deaktivér SID-cartridge joystick"},
/* de */ {IDCLS_DISABLE_SIDCARTJOY_DE, "SIDcart Modul deaktivieren"},
/* fr */ {IDCLS_DISABLE_SIDCARTJOY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_SIDCARTJOY_HU, "SID cartridge botkormány tiltása"},
/* it */ {IDCLS_DISABLE_SIDCARTJOY_IT, "Disattiva joystick su cartuccia SID"},
/* ko */ {IDCLS_DISABLE_SIDCARTJOY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SIDCARTJOY_NL, "De SID cartridge joystick uitschakelen"},
/* ru */ {IDCLS_DISABLE_SIDCARTJOY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SIDCARTJOY_SV, "Inaktivera SID-insticksmodul-styrspak"},
/* tr */ {IDCLS_DISABLE_SIDCARTJOY_TR, "SID kartuþu joystick'ini pasifleþtir"},
#endif

/* c64/cart/sfx_soundexpander.c */
/* en */ {IDCLS_ENABLE_SFX_SE,    N_("Enable the SFX Sound Expander cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SFX_SE_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ENABLE_SFX_SE_DE, "SFX Soundexpander Modul aktivieren"},
/* fr */ {IDCLS_ENABLE_SFX_SE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_SFX_SE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_SFX_SE_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ENABLE_SFX_SE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SFX_SE_NL, "Activeer de SFX Sound Expander cartridge"},
/* ru */ {IDCLS_ENABLE_SFX_SE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SFX_SE_SV, "Aktivera SFX Sound Expander-insticksmodul"},
/* tr */ {IDCLS_ENABLE_SFX_SE_TR, ""},  /* fuzzy */
#endif

/* c64/cart/sfx_soundexpander.c */
/* en */ {IDCLS_DISABLE_SFX_SE,    N_("Disable the SFX Sound Expander cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SFX_SE_DA, ""},  /* fuzzy */
/* de */ {IDCLS_DISABLE_SFX_SE_DE, "SFX Soundexpander Modul deaktivieren"},
/* fr */ {IDCLS_DISABLE_SFX_SE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_SFX_SE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_SFX_SE_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_DISABLE_SFX_SE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SFX_SE_NL, "De SFX Sound Expander cartridge uitschakelen"},
/* ru */ {IDCLS_DISABLE_SFX_SE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SFX_SE_SV, "Inaktivera SFX Sound Expander-insticksmodul"},
/* tr */ {IDCLS_DISABLE_SFX_SE_TR, ""},  /* fuzzy */
#endif

/* c64/cart/sfx_soundexpander.c */
/* en */ {IDCLS_SET_YM_CHIP_TYPE,    N_("Set YM chip type (3526 / 3812)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_YM_CHIP_TYPE_DA, "Vælg YM chiptype"},
/* de */ {IDCLS_SET_YM_CHIP_TYPE_DE, "YM Chip Typ (3526 / 3812) bestimmen"},
/* fr */ {IDCLS_SET_YM_CHIP_TYPE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_YM_CHIP_TYPE_HU, "YM csip típus megadása (3526 / 3812)"},
/* it */ {IDCLS_SET_YM_CHIP_TYPE_IT, "Imposta tipo chip YM (3526 / 3812)"},
/* ko */ {IDCLS_SET_YM_CHIP_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_YM_CHIP_TYPE_NL, "Kies de YM chip soort (3526 / 3812)"},
/* ru */ {IDCLS_SET_YM_CHIP_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_YM_CHIP_TYPE_SV, "Välj YM-kretstyp (3526 / 3812)"},
/* tr */ {IDCLS_SET_YM_CHIP_TYPE_TR, "YM çip tipini ayarla (3526 / 3812)"},
#endif

/* c64/cart/sfx_soundsampler.c */
/* en */ {IDCLS_ENABLE_SFX_SS,    N_("Enable the SFX Sound Sampler cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SFX_SS_DA, "Aktivér SFX Sound Sampler cartridge"},
/* de */ {IDCLS_ENABLE_SFX_SS_DE, "SFX Sound Sampler Modul aktivieren"},
/* fr */ {IDCLS_ENABLE_SFX_SS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_SFX_SS_HU, "SFX Sound Sampler engedélyezése"},
/* it */ {IDCLS_ENABLE_SFX_SS_IT, "Attiva cartuccia SFX Sound Sampler"},
/* ko */ {IDCLS_ENABLE_SFX_SS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SFX_SS_NL, "Activeer de SFX Sound Sampler cartridge"},
/* ru */ {IDCLS_ENABLE_SFX_SS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SFX_SS_SV, "Aktivera SFX Sound Sampler-insticksmodul"},
/* tr */ {IDCLS_ENABLE_SFX_SS_TR, "SFX Sound Sampler kartuþunu aktif et"},
#endif

/* c64/cart/sfx_soundsampler.c */
/* en */ {IDCLS_DISABLE_SFX_SS,    N_("Disable the SFX Sound Sampler cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SFX_SS_DA, "Deaktivér SFX Sound Sampler cartridge"},
/* de */ {IDCLS_DISABLE_SFX_SS_DE, "SFX Sound Sampler Modul  deaktivieren"},
/* fr */ {IDCLS_DISABLE_SFX_SS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_SFX_SS_HU, "SFX Sound Sampler tiltása"},
/* it */ {IDCLS_DISABLE_SFX_SS_IT, "Disattiva cartuccia SFX Sound Sampler"},
/* ko */ {IDCLS_DISABLE_SFX_SS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SFX_SS_NL, "De SFX Sound Sampler cartridge uitschakelen"},
/* ru */ {IDCLS_DISABLE_SFX_SS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SFX_SS_SV, "Inaktivera SFX Sound Sampler-insticksmodul"},
/* tr */ {IDCLS_DISABLE_SFX_SS_TR, "SFX Sound Sampler kartuþunu pasifleþtir"},
#endif

/* lightpen.c */
/* en */ {IDCLS_ENABLE_LIGHTPEN_EMULATION,    N_("Enable lightpen emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_DA, "Aktivér lyspen-emulering"},
/* de */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_DE, "Lichtgriffel Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_HU, "Fényceruza emuláció engedélyezése"},
/* it */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_IT, "Attiva emulazione della penna ottica"},
/* ko */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_NL, "Activeer de lichtpen emulatie"},
/* ru */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_SV, "Aktivera emulering av ljuspenna"},
/* tr */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_TR, "Iþýklý Kalem emülasyonunu aktif et"},
#endif

/* lightpen.c */
/* en */ {IDCLS_DISABLE_LIGHTPEN_EMULATION,    N_("Disable lightpen emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_DA, "Deaktivér lyspen-emulering"},
/* de */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_DE, "Lichtgriffel Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_HU, "Fényceruza emuláció tiltása"},
/* it */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_IT, "Disattiva emulazione della penna ottica"},
/* ko */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_NL, "De lichtpen emulatie uitschakelen"},
/* ru */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_SV, "Inaktivera emulering ljuspenna"},
/* tr */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_TR, "Iþýklý Kalem emülasyonunu pasifleþtir"},
#endif

/* lightpen.c */
/* en */ {IDCLS_SET_LIGHTPEN_TYPE,    N_("Set lightpen type")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_LIGHTPEN_TYPE_DA, "Angiv lyspen-type"},
/* de */ {IDCLS_SET_LIGHTPEN_TYPE_DE, "Lichtgriffel Type bestimmen"},
/* fr */ {IDCLS_SET_LIGHTPEN_TYPE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_LIGHTPEN_TYPE_HU, "Fényceruza típusának megadása"},
/* it */ {IDCLS_SET_LIGHTPEN_TYPE_IT, "Imposta tipo penna ottica"},
/* ko */ {IDCLS_SET_LIGHTPEN_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_LIGHTPEN_TYPE_NL, "Geef de lichtpen soort op"},
/* ru */ {IDCLS_SET_LIGHTPEN_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_LIGHTPEN_TYPE_SV, "Välj typ av ljuspenna"},
/* tr */ {IDCLS_SET_LIGHTPEN_TYPE_TR, "Iþýklý Kalem tipini ayarla"},
#endif

/* c64/cart/easyflash.c */
/* en */ {IDCLS_ENABLE_EASYFLASH_JUMPER,    N_("Enable EasyFlash jumper")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_EASYFLASH_JUMPER_DA, "Aktivér EasyFlash-jumper"},
/* de */ {IDCLS_ENABLE_EASYFLASH_JUMPER_DE, "EasyFlash Jumper aktivieren"},
/* fr */ {IDCLS_ENABLE_EASYFLASH_JUMPER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_EASYFLASH_JUMPER_HU, "EasyFlash Jumper engedélyezése"},
/* it */ {IDCLS_ENABLE_EASYFLASH_JUMPER_IT, "Attiva ponticello EasyFlash"},
/* ko */ {IDCLS_ENABLE_EASYFLASH_JUMPER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_EASYFLASH_JUMPER_NL, "Activeer de EasyFlash jumper"},
/* ru */ {IDCLS_ENABLE_EASYFLASH_JUMPER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_EASYFLASH_JUMPER_SV, "Aktivera EasyFlash-bygel"},
/* tr */ {IDCLS_ENABLE_EASYFLASH_JUMPER_TR, "EasyFlash jumper'ý aktif et"},
#endif

/* c64/cart/easyflash.c */
/* en */ {IDCLS_DISABLE_EASYFLASH_JUMPER,    N_("Disable EasyFlash jumper")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_EASYFLASH_JUMPER_DA, "Deaktivér EasyFlash-jumper"},
/* de */ {IDCLS_DISABLE_EASYFLASH_JUMPER_DE, "EasyFlash Jumer deaktivieren"},
/* fr */ {IDCLS_DISABLE_EASYFLASH_JUMPER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_EASYFLASH_JUMPER_HU, "EasyFlash Jumper tiltása"},
/* it */ {IDCLS_DISABLE_EASYFLASH_JUMPER_IT, "Disattiva ponticello EasyFlash"},
/* ko */ {IDCLS_DISABLE_EASYFLASH_JUMPER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_EASYFLASH_JUMPER_NL, "De EasyFlash jumper uitschakelen"},
/* ru */ {IDCLS_DISABLE_EASYFLASH_JUMPER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_EASYFLASH_JUMPER_SV, "Inaktivera EasyFlash-bygel"},
/* tr */ {IDCLS_DISABLE_EASYFLASH_JUMPER_TR, "EasyFlash jumper'ý pasifleþtir"},
#endif

/* c64/cart/easyflash.c */
/* en */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING,    N_("Enable writing to EasyFlash .crt image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_DA, "Tillad skrivning til EasyFlash CRT-image"},
/* de */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_DE, "Schreibzugriff auf EasyFlash CRT Image erlauben"},
/* fr */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_HU, "EasyFlash .crt képmásba írás engedélyezése"},
/* it */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_IT, "Attiva scrittura sull'immagine .crt EasyFlash"},
/* ko */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_NL, "Activeer schrijven naar het EasyFlash .crt bestand"},
/* ru */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_SV, "Aktivera skrivning till EasyFlash-.crt-avbildning."},
/* tr */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_TR, "EasyFlash .crt imajýna yazmayý aktif et"},
#endif

/* c64/cart/easyflash.c */
/* en */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING,    N_("Disable writing to EasyFlash .crt image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_DA, "Forbyd skrivning til EasyFlash CRT-image"},
/* de */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_DE, "Schreibzugriff auf EasyFlash ROM Image verhindern"},
/* fr */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_HU, "EasyFlash .crt képmásba írás tiltása"},
/* it */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_IT, "Disattiva scrittura sull'immagine .crt EasyFlash"},
/* ko */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_NL, "Schrijven naar het EasyFlash .crt bestand uitschakelen"},
/* ru */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_SV, "Inaktivera skrivning till EasyFlash-.crt-avbildning."},
/* tr */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_TR, "EasyFlash .crt imajýna yazmayý pasifleþtir"},
#endif

/* c64/cart/digimax.c */
/* en */ {IDCLS_ENABLE_DIGIMAX,    N_("Enable the DigiMAX cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DIGIMAX_DA, "Aktivér DigiMAX cartridge"},
/* de */ {IDCLS_ENABLE_DIGIMAX_DE, "DigiMAX Cartridge aktivieren"},
/* fr */ {IDCLS_ENABLE_DIGIMAX_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_DIGIMAX_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_DIGIMAX_IT, "Attiva la cartuccia DigiMAX"},
/* ko */ {IDCLS_ENABLE_DIGIMAX_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DIGIMAX_NL, "Activeer de DigiMAX cartridge"},
/* ru */ {IDCLS_ENABLE_DIGIMAX_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DIGIMAX_SV, "Aktivera DigiMAX-insticksmodul"},
/* tr */ {IDCLS_ENABLE_DIGIMAX_TR, "DigiMAX kartuþunu aktif et"},
#endif

/* c64/cart/digimax.c */
/* en */ {IDCLS_DISABLE_DIGIMAX,    N_("Disable the DigiMAX cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DIGIMAX_DA, "Deaktivér DigiMAX cartridge"},
/* de */ {IDCLS_DISABLE_DIGIMAX_DE, "DigiMAX Cartridge deaktivieren"},
/* fr */ {IDCLS_DISABLE_DIGIMAX_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_DIGIMAX_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_DIGIMAX_IT, "Disattiva la cartuccia DigiMAX"},
/* ko */ {IDCLS_DISABLE_DIGIMAX_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DIGIMAX_NL, "De DigiMAX cartridge uitschakelen"},
/* ru */ {IDCLS_DISABLE_DIGIMAX_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DIGIMAX_SV, "Inaktivera DigiMAX-insticksmodul"},
/* tr */ {IDCLS_DISABLE_DIGIMAX_TR, "DigiMAX kartuþunu pasifleþtir"},
#endif

/* c64/cart/digimax.c */
/* en */ {IDCLS_DIGIMAX_BASE,    N_("Base address of the DigiMAX cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DIGIMAX_BASE_DA, "Baseadresse for DigiMAX cartridge"},
/* de */ {IDCLS_DIGIMAX_BASE_DE, "Basis Adresse für DigiMAX Erweiterung"},
/* fr */ {IDCLS_DIGIMAX_BASE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DIGIMAX_BASE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DIGIMAX_BASE_IT, "Indirizzo base della cartuccia DigiMAX"},
/* ko */ {IDCLS_DIGIMAX_BASE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DIGIMAX_BASE_NL, "Basisadres van de DigiMAX cartridge"},
/* ru */ {IDCLS_DIGIMAX_BASE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DIGIMAX_BASE_SV, "Basadress för DigiMAC-insticksmodulen"},
/* tr */ {IDCLS_DIGIMAX_BASE_TR, "DigiMAX kartuþunun taban adresi"},
#endif

};