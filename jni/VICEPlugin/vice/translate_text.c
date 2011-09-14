/*
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
/* da */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_DA, "Kunne ikke indlase snapshot-fil."},
/* de */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_DE, "Kann Snapshot Datei nicht laden."},
/* fr */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_FR, "Impossible de charger l'instantane."},
/* hu */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_HU, "Nem sikerult betolteni a pillanatkep fajlt."},
/* it */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_IT, "Non e possibile caricare il file di snapshot."},
/* ko */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_NL, "Kan momentopnamebestand niet laden."},
/* pl */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_PL, "Nie mo?na wczytaa pliku zrzutu."},
/* ru */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_SV, "Kan inte lasa in ogonblicksbildfil."},
/* tr */ {IDGS_CANNOT_LOAD_SNAPSHOT_FILE_TR, "Anlyk goruntu dosyasy yuklenemedi."},
#endif

/* debug.c */
/* en */ {IDGS_PLAYBACK_ERROR_DIFFERENT,    N_("Playback error: %s different from line %d of file debug%06d")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_PLAYBACK_ERROR_DIFFERENT_DA, "Afspilningsfejl: %s forskellig fra linje %d i filen debug%06d"},
/* de */ {IDGS_PLAYBACK_ERROR_DIFFERENT_DE, "Wiedergabe Fehler: %s ist unterschiedlich von Zeile %d in Datei debug%06d"},
/* fr */ {IDGS_PLAYBACK_ERROR_DIFFERENT_FR, "Erreur de lecture: %s different de la ligne %d du fichier debug%06d"},
/* hu */ {IDGS_PLAYBACK_ERROR_DIFFERENT_HU, "Visszajatszasi hiba: %s kulonbozik a %d. sorban a debug%06d fajl eseten"},
/* it */ {IDGS_PLAYBACK_ERROR_DIFFERENT_IT, "Errore di riproduzione: %s e differente dalla linea %d del file di debug %06d"},
/* ko */ {IDGS_PLAYBACK_ERROR_DIFFERENT_KO, ""},  /* fuzzy */
/* nl */ {IDGS_PLAYBACK_ERROR_DIFFERENT_NL, "Afspeelfout: %s is anders dan regel %d van bestand debug%06d"},
/* pl */ {IDGS_PLAYBACK_ERROR_DIFFERENT_PL, "B3�}d otwarzania: %s ro?ni sie od linii %d pliku debug%06d"},
/* ru */ {IDGS_PLAYBACK_ERROR_DIFFERENT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_PLAYBACK_ERROR_DIFFERENT_SV, "Aterspelningsfel: %s inte lika som rad %d i filen debug%06d"},
/* tr */ {IDGS_PLAYBACK_ERROR_DIFFERENT_TR, "Kayyttan yurutme hatasy: %s dosyanyn %d satyryndan farkly (hata ayyklama%06d)"},
#endif

/* event.c */
/* en */ {IDGS_CANNOT_CREATE_IMAGE,    N_("Cannot create image file!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_CREATE_IMAGE_DA, "Kunne ikke oprette image-fil!"},
/* de */ {IDGS_CANNOT_CREATE_IMAGE_DE, "Kann Imagedatei nicht erzeugen!"},
/* fr */ {IDGS_CANNOT_CREATE_IMAGE_FR, "Impossible de creer le fichier image!"},
/* hu */ {IDGS_CANNOT_CREATE_IMAGE_HU, "Nem sikerult a kepmas fajlt letrehozni!"},
/* it */ {IDGS_CANNOT_CREATE_IMAGE_IT, "Non e possibile creare il file immagine!"},
/* ko */ {IDGS_CANNOT_CREATE_IMAGE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_CREATE_IMAGE_NL, "Kan bestand niet maken!"},
/* pl */ {IDGS_CANNOT_CREATE_IMAGE_PL, "Nie mo?na utworzya pliku obrazu!"},
/* ru */ {IDGS_CANNOT_CREATE_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_CREATE_IMAGE_SV, "Kan inte skapa avbildningsfil!"},
/* tr */ {IDGS_CANNOT_CREATE_IMAGE_TR, "Imaj dosyasy yaratylamady!"},
#endif

/* event.c */
/* en */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S,    N_("Cannot write image file %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_DA, "Kunne ikks skrive image-fil %s"},
/* de */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_DE, "Kann Datei %s nicht schreiben"},
/* fr */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_FR, "Impossible d'ecrire le fichier image %s"},
/* hu */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_HU, "Nem sikerult a %s kepmas fajlba irni"},
/* it */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_IT, "Non e possibile scrivere l'immagine %s"},
/* ko */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_NL, "Kan niet schrijven naar bestand %s"},
/* pl */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_PL, "Nie mo?na zapisaa pliku obrazu %s"},
/* ru */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_SV, "Kan inte skriva avbildningsfil %s"},
/* tr */ {IDGS_CANNOT_WRITE_IMAGE_FILE_S_TR, "%s imaj dosyasyna yazylamady"},
#endif

/* event.c */
/* en */ {IDGS_CANNOT_FIND_MAPPED_NAME_S,    N_("Cannot find mapped name for %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_DA, "Kunne ikke finde mappet navn for %s"},
/* de */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_DE, "Kann zugeordneten Namen fur `%s' nicht finden."},
/* fr */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_FR, "Impossible de trouver le nom correspondant a %s"},
/* hu */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_HU, "A VICE %s lekepzett nevet nem talalja"},
/* it */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_IT, "Non e possibile trovare il nome mappato per %s"},
/* ko */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_NL, "Kan vertaalde naam voor %s niet vinden"},
/* pl */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_PL, "Nie mo?na znale?a zmapowanej nazwy %s"},
/* ru */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_SV, "Kan inte kopplat namn for %s"},
/* tr */ {IDGS_CANNOT_FIND_MAPPED_NAME_S_TR, "%s icin etletme ismi bulunamady"},
#endif

/* event.c */
/* en */ {IDGS_CANT_CREATE_START_SNAP_S,    N_("Could not create start snapshot file %s.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANT_CREATE_START_SNAP_S_DA, "Kunne ikke oprette start-snapshot-filen %s."},
/* de */ {IDGS_CANT_CREATE_START_SNAP_S_DE, "Kann Start Snapshot Datei nicht erzeugen: %s"},
/* fr */ {IDGS_CANT_CREATE_START_SNAP_S_FR, "Impossible de creer l'instantane de depart %s."},
/* hu */ {IDGS_CANT_CREATE_START_SNAP_S_HU, "Nem sikerult a %s kezdeti pillanatkep fajlt letrehozni."},
/* it */ {IDGS_CANT_CREATE_START_SNAP_S_IT, "Non e possibile creare il file di inizio snapshot %s."},
/* ko */ {IDGS_CANT_CREATE_START_SNAP_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANT_CREATE_START_SNAP_S_NL, "Kon het start momentopnamebestand %s niet maken."},
/* pl */ {IDGS_CANT_CREATE_START_SNAP_S_PL, "Nie mo?na utworzya pocz�}tkowego pliku zrzutu %s."},
/* ru */ {IDGS_CANT_CREATE_START_SNAP_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANT_CREATE_START_SNAP_S_SV, "Kunde inte skapa startogonblicksbildfilen %s."},
/* tr */ {IDGS_CANT_CREATE_START_SNAP_S_TR, "Anlyk goruntu dosyasy %s yaratylamady."},
#endif

/* event.c */
/* en */ {IDGS_ERROR_READING_END_SNAP_S,    N_("Error reading end snapshot file %s.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ERROR_READING_END_SNAP_S_DA, "Fejl under lasning af slut-snapshot %s."},
/* de */ {IDGS_ERROR_READING_END_SNAP_S_DE, "Kann Ende Snapshot Datei nicht lesen: %s"},
/* fr */ {IDGS_ERROR_READING_END_SNAP_S_FR, "Erreur de lecture de l'instantane de fin %s."},
/* hu */ {IDGS_ERROR_READING_END_SNAP_S_HU, "Hiba az utolso %s pillanatkep fajl irasakor."},
/* it */ {IDGS_ERROR_READING_END_SNAP_S_IT, "Errore durante la lettura del file di fine snapshot %s."},
/* ko */ {IDGS_ERROR_READING_END_SNAP_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ERROR_READING_END_SNAP_S_NL, "Fout bij het lezen van het eind van het momentopnamebestand %s."},
/* pl */ {IDGS_ERROR_READING_END_SNAP_S_PL, "B3�}d odczytu koncowego pliku zrzutu %s."},
/* ru */ {IDGS_ERROR_READING_END_SNAP_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ERROR_READING_END_SNAP_S_SV, "Fel vid lasning av slutogonblicksbildfilen %s."},
/* tr */ {IDGS_ERROR_READING_END_SNAP_S_TR, "Anlyk goruntu dosyasy %s okuma hatasy."},
#endif

/* event.c */
/* en */ {IDGS_CANT_CREATE_END_SNAP_S,    N_("Could not create end snapshot file %s.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANT_CREATE_END_SNAP_S_DA, "Kunne ikke oprette slut-snapshot-filen %s."},
/* de */ {IDGS_CANT_CREATE_END_SNAP_S_DE, "Kann Ende Snapshot Datei nicht erzeugen: %s"},
/* fr */ {IDGS_CANT_CREATE_END_SNAP_S_FR, "Impossible de creer l'instantane de fin %s."},
/* hu */ {IDGS_CANT_CREATE_END_SNAP_S_HU, "Nem sikerult a %s befejezo pillanatkep fajlt letrehozni."},
/* it */ {IDGS_CANT_CREATE_END_SNAP_S_IT, "Non e possibile creare il file di fine snapshot %s."},
/* ko */ {IDGS_CANT_CREATE_END_SNAP_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANT_CREATE_END_SNAP_S_NL, "Kon het eind momentopnamebestand %s niet maken."},
/* pl */ {IDGS_CANT_CREATE_END_SNAP_S_PL, "Nie mo?na utworzya koncowego pliku zrzutu %s."},
/* ru */ {IDGS_CANT_CREATE_END_SNAP_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANT_CREATE_END_SNAP_S_SV, "Kunde inte skapa slutogonblicksbildfilen %s."},
/* tr */ {IDGS_CANT_CREATE_END_SNAP_S_TR, "Son anlyk goruntu dosyasy %s yaratylamady."},
#endif

/* event.c */
/* en */ {IDGS_CANT_OPEN_END_SNAP_S,    N_("Could not open end snapshot file %s.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANT_OPEN_END_SNAP_S_DA, "Kunne ikke abne slut-snapshot-filen %s."},
/* de */ {IDGS_CANT_OPEN_END_SNAP_S_DE, "Kann Ende Snapshot Datei nicht offnen: %s"},
/* fr */ {IDGS_CANT_OPEN_END_SNAP_S_FR, "Impossible d'ouvrir l'instantane de fin %s."},
/* hu */ {IDGS_CANT_OPEN_END_SNAP_S_HU, "Nem sikerult az utolso %s pillanatkep fajlt megnyitni."},
/* it */ {IDGS_CANT_OPEN_END_SNAP_S_IT, "Non e possibile aprire il file di fine snapshot %s."},
/* ko */ {IDGS_CANT_OPEN_END_SNAP_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANT_OPEN_END_SNAP_S_NL, "Kon het eind momentopnamebestand %s niet openen."},
/* pl */ {IDGS_CANT_OPEN_END_SNAP_S_PL, "Nie mo?na otworzya koncowego pliku zrzutu %s."},
/* ru */ {IDGS_CANT_OPEN_END_SNAP_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANT_OPEN_END_SNAP_S_SV, "Kunde inte oppna slutogonblicksbildfilen %s."},
/* tr */ {IDGS_CANT_OPEN_END_SNAP_S_TR, "Son anlyk goruntu dosyasy %s acylamady."},
#endif

/* event.c */
/* en */ {IDGS_CANT_FIND_SECTION_END_SNAP,    N_("Could not find event section in end snapshot file.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANT_FIND_SECTION_END_SNAP_DA, "Kunne ikke finde handelses-sektionen i slut-snapshot-filen."},
/* de */ {IDGS_CANT_FIND_SECTION_END_SNAP_DE, "Kann Sektion in Ende Snapshotdatei nicht finden."},
/* fr */ {IDGS_CANT_FIND_SECTION_END_SNAP_FR, "Impossible de trouver la section event dans l'instantane de fin."},
/* hu */ {IDGS_CANT_FIND_SECTION_END_SNAP_HU, "Nem talaltam esemeny reszt az utolso pillanatkep fajlban."},
/* it */ {IDGS_CANT_FIND_SECTION_END_SNAP_IT, "Non e possibile trovare la sezione eventi nel file di fine snapshot."},
/* ko */ {IDGS_CANT_FIND_SECTION_END_SNAP_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANT_FIND_SECTION_END_SNAP_NL, "Kon de gebeurtenis sectie in eind momentopnamebestand niet vinden."},
/* pl */ {IDGS_CANT_FIND_SECTION_END_SNAP_PL, "Nie znaleziono sekcji zdarzen w pliku koncowym zrzutu"},
/* ru */ {IDGS_CANT_FIND_SECTION_END_SNAP_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANT_FIND_SECTION_END_SNAP_SV, "Kunde inte hinna handelsedelen i slutogonblicksbilden."},
/* tr */ {IDGS_CANT_FIND_SECTION_END_SNAP_TR, "Son anlyk goruntu dosyasynda olay bolumu bulunamady."},
#endif

/* event.c */
/* en */ {IDGS_ERROR_READING_START_SNAP_TRIED,    N_("Error reading start snapshot file. Tried %s and %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ERROR_READING_START_SNAP_TRIED_DA, "Fejl under lasning af start-snapshot. Provede %s og %s"},
/* de */ {IDGS_ERROR_READING_START_SNAP_TRIED_DE, "Fehler beim Lesen der Start Snapshot Datei. Versuch gescheitert bei %s und %s."},
/* fr */ {IDGS_ERROR_READING_START_SNAP_TRIED_FR, "Erreur de lecture de l'instantane de depart. Essaye %s et %s"},
/* hu */ {IDGS_ERROR_READING_START_SNAP_TRIED_HU, "Nem sikerult az elso pillanatkep fajl olvasasa. Kiprobalva: %s es %s"},
/* it */ {IDGS_ERROR_READING_START_SNAP_TRIED_IT, "Errore durante la lettura del file di inizio snapshot. Ho provato %s e %s"},
/* ko */ {IDGS_ERROR_READING_START_SNAP_TRIED_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ERROR_READING_START_SNAP_TRIED_NL, "Fout bij het lezen van het start momentopnamebestand. Heb %s en %s geprobeerd"},
/* pl */ {IDGS_ERROR_READING_START_SNAP_TRIED_PL, "B3�}d odczytu pocz�}tkowego pliku zrzutu. Wyprobowano %s i %s"},
/* ru */ {IDGS_ERROR_READING_START_SNAP_TRIED_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ERROR_READING_START_SNAP_TRIED_SV, "Fel vid lasning av startogonblicksbildfil. Forsokte med %s och %s"},
/* tr */ {IDGS_ERROR_READING_START_SNAP_TRIED_TR, "Batlangyc anlyk goruntu dosyasy okuma hatasy. %s ve %s denendi"},
#endif

/* event.c */
/* en */ {IDGS_ERROR_READING_START_SNAP,    N_("Error reading start snapshot file.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ERROR_READING_START_SNAP_DA, "Fejl under lasning af start-snapshot."},
/* de */ {IDGS_ERROR_READING_START_SNAP_DE, "Fehler beim Lesen der Start Snapshot Datei."},
/* fr */ {IDGS_ERROR_READING_START_SNAP_FR, "Erreur de lecture de l'instantane de depart."},
/* hu */ {IDGS_ERROR_READING_START_SNAP_HU, "Nem sikerult az indito pillanatkep fajl olvasasa."},
/* it */ {IDGS_ERROR_READING_START_SNAP_IT, "Errore durante la lettura del file di inizio snapshot."},
/* ko */ {IDGS_ERROR_READING_START_SNAP_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ERROR_READING_START_SNAP_NL, "Fout bij het lezen van het start momentopnamebestand."},
/* pl */ {IDGS_ERROR_READING_START_SNAP_PL, "B3�}d odczytu pocz�}tkowego pliku zrzutu."},
/* ru */ {IDGS_ERROR_READING_START_SNAP_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ERROR_READING_START_SNAP_SV, "Fel vid lasning av startogonblicksbildfil."},
/* tr */ {IDGS_ERROR_READING_START_SNAP_TR, "Batlangyc anlyk goruntu dosyasy okuma hatasy."},
#endif

/* screenshot.c */
/* en */ {IDGS_SORRY_NO_MULTI_RECORDING,    N_("Sorry. Multiple recording is not supported.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_SORRY_NO_MULTI_RECORDING_DA, "Kun en optagelse kan foretages ad gangen."},
/* de */ {IDGS_SORRY_NO_MULTI_RECORDING_DE, "Eine Aufnahme ist zur Zeit aktiv. Mehrfache Aufnahme ist nicht moglich."},
/* fr */ {IDGS_SORRY_NO_MULTI_RECORDING_FR, "Desole. De multiples enregistrements ne sont pas supporte."},
/* hu */ {IDGS_SORRY_NO_MULTI_RECORDING_HU, "Sajnalom: tobbszoros felvetel nem tamogatott."},
/* it */ {IDGS_SORRY_NO_MULTI_RECORDING_IT, "Le registrazioni multiple non sono supportate."},
/* ko */ {IDGS_SORRY_NO_MULTI_RECORDING_KO, ""},  /* fuzzy */
/* nl */ {IDGS_SORRY_NO_MULTI_RECORDING_NL, "Sorry. Meerdere opnamen wordt niet ondersteund."},
/* pl */ {IDGS_SORRY_NO_MULTI_RECORDING_PL, "Przepraszamy, wielo��cie?kowy zapis nie jest obs3ugiwany."},
/* ru */ {IDGS_SORRY_NO_MULTI_RECORDING_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SORRY_NO_MULTI_RECORDING_SV, "Endast en inspelning kan goras at gangen."},
/* tr */ {IDGS_SORRY_NO_MULTI_RECORDING_TR, "Uzgunuz. Coklu kayyt desteklenmiyor."},
#endif

/* sound.c */
/* en */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED,    N_("write to sound device failed.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_DA, "Kunne ikke skrive til lydenhed."},
/* de */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_DE, "Schreiben auf Sound Gerat ist fehlgeschlagen."},
/* fr */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_FR, "impossible d'ecrire sur le peripherique son."},
/* hu */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_HU, "Nem sikerult a hangeszkozre irni"},
/* it */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_IT, "scrittura sulla scheda audio fallita."},
/* ko */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_KO, ""},  /* fuzzy */
/* nl */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_NL, "schrijfactie naar geluidsapparaat is mislukt."},
/* pl */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_PL, "Zapis do urz�}dzenia d?wieku nie powiod3 sie."},
/* ru */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_RU, ""},  /* fuzzy */
/* sv */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_SV, "misslyckades att skriva till ljudenhet."},
/* tr */ {IDGS_WRITE_TO_SOUND_DEVICE_FAILED_TR, "ses aygytyna yazma batarysyz oldu."},
#endif

/* sound.c */
/* en */ {IDGS_CANNOT_OPEN_SID_ENGINE,    N_("Cannot open SID engine")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_OPEN_SID_ENGINE_DA, "Kunne ikke abne SID-motor"},
/* de */ {IDGS_CANNOT_OPEN_SID_ENGINE_DE, "Kann SID Engine nicht offnen"},
/* fr */ {IDGS_CANNOT_OPEN_SID_ENGINE_FR, "Erreur d'ouverture de l'engin SID"},
/* hu */ {IDGS_CANNOT_OPEN_SID_ENGINE_HU, "Nem sikerult a SID motort megnyitni"},
/* it */ {IDGS_CANNOT_OPEN_SID_ENGINE_IT, "Non e possibile aprire il motore SID"},
/* ko */ {IDGS_CANNOT_OPEN_SID_ENGINE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_OPEN_SID_ENGINE_NL, "Kan de SID kern niet openen"},
/* pl */ {IDGS_CANNOT_OPEN_SID_ENGINE_PL, "Nie mo?na otworzya silnika SID"},
/* ru */ {IDGS_CANNOT_OPEN_SID_ENGINE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_OPEN_SID_ENGINE_SV, "Kan inte oppna SID-motor"},
/* tr */ {IDGS_CANNOT_OPEN_SID_ENGINE_TR, "SID motoru acylamyyor"},
#endif

/* sound.c */
/* en */ {IDGS_CANNOT_INIT_SID_ENGINE,    N_("Cannot initialize SID engine")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_INIT_SID_ENGINE_DA, "Kunne ikke initialisere SID-motor"},
/* de */ {IDGS_CANNOT_INIT_SID_ENGINE_DE, "Kann SID Engine nicht initialisieren"},
/* fr */ {IDGS_CANNOT_INIT_SID_ENGINE_FR, "Erreur d'initialisation de l'engin SID"},
/* hu */ {IDGS_CANNOT_INIT_SID_ENGINE_HU, "Nem sikerult a SID motort elinditani"},
/* it */ {IDGS_CANNOT_INIT_SID_ENGINE_IT, "Non e possibile inizializzare il motore SID"},
/* ko */ {IDGS_CANNOT_INIT_SID_ENGINE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_INIT_SID_ENGINE_NL, "Kan de SID kern niet initialiseren"},
/* pl */ {IDGS_CANNOT_INIT_SID_ENGINE_PL, "Nie mo?na uruchomia silnika SID"},
/* ru */ {IDGS_CANNOT_INIT_SID_ENGINE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_INIT_SID_ENGINE_SV, "Kan inte initiera SID-motor"},
/* tr */ {IDGS_CANNOT_INIT_SID_ENGINE_TR, "SID motorunun batlangyc ayarlary yapylamyyor"},
#endif

/* sound.c */
/* en */ {IDGS_INIT_FAILED_FOR_DEVICE_S,    N_("initialization failed for device `%s'.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_INIT_FAILED_FOR_DEVICE_S_DA, "Initialisering fejlede for enhed \"%s\"."},
/* de */ {IDGS_INIT_FAILED_FOR_DEVICE_S_DE, "Initialisierung von Gerat `%s' fehlgeschlagen."},
/* fr */ {IDGS_INIT_FAILED_FOR_DEVICE_S_FR, "erreur d'initialisation du peripherique `%s'."},
/* hu */ {IDGS_INIT_FAILED_FOR_DEVICE_S_HU, "A `%s' eszkozt nem sikerult elinditani."},
/* it */ {IDGS_INIT_FAILED_FOR_DEVICE_S_IT, "inizializzazione fallita per il device `%s'."},
/* ko */ {IDGS_INIT_FAILED_FOR_DEVICE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_INIT_FAILED_FOR_DEVICE_S_NL, "initialisatie voor apparaat `%s' is mislukt."},
/* pl */ {IDGS_INIT_FAILED_FOR_DEVICE_S_PL, "Inicjalizacja urz�}dzenia `%s' nie powiod3a sie."},
/* ru */ {IDGS_INIT_FAILED_FOR_DEVICE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_INIT_FAILED_FOR_DEVICE_S_SV, "initiering misslyckades for enhet \"%s\"."},
/* tr */ {IDGS_INIT_FAILED_FOR_DEVICE_S_TR, "`%s' aygyty icin batlangyc ayarlary batarysyz oldu."},
#endif

/* sound.c */
/* en */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT,    N_("device '%s' not found or not supported.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_DA, "enhed \"%s\" ikke fundet eller understottet."},
/* de */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_DE, "Gerat '%s' konnte nicht gefunden werden oder ist nicht unterstutzt."},
/* fr */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_FR, "peripherique '%s' non trouve ou non supporte."},
/* hu */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_HU, "A '%s' eszkoz nem letezik, vagy nem tamogatott."},
/* it */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_IT, "il device '%s' non e stato trovato oppure non e supportato."},
/* ko */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_KO, ""},  /* fuzzy */
/* nl */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_NL, "apparaat '%s' niet gevonden of wordt niet ondersteund"},
/* pl */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_PL, "Nie znaleziono urz�}dzenia '%s' lub jest ono niewspierane"},
/* ru */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_SV, "enheten \"%s\" hittades eller stods ej."},
/* tr */ {IDGS_DEVICE_S_NOT_FOUND_SUPPORT_TR, "'%s' aygyty yok ya da desteklenmiyor."},
#endif

/* sound.c */
/* en */ {IDGS_RECORD_DEVICE_S_NOT_EXIST,    N_("Recording device %s doesn't exist!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_DA, "Optageenheden %s findes ikke!"},
/* de */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_DE, "Aufnahmegerat %s existiert nicht!"},
/* fr */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_FR, "Le peripherique d'enregistrement %s n'existe pas!"},
/* hu */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_HU, "A %s felvevo eszkoz nem letezik!"},
/* it */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_IT, "Il device di registrazione %s non esiste!"},
/* ko */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_KO, ""},  /* fuzzy */
/* nl */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_NL, "Opnameapparaat %s bestaat niet!"},
/* pl */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_PL, "Urz�}dzenie zapisu %s nie istnieje!"},
/* ru */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_SV, "Inspelningsenhet %s finns inte!"},
/* tr */ {IDGS_RECORD_DEVICE_S_NOT_EXIST_TR, "Kayyt aygyty %s mevcut dedil!"},
#endif

/* sound.c */
/* en */ {IDGS_RECORD_DIFFERENT_PLAYBACK,    N_("Recording device must be different from playback device")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_RECORD_DIFFERENT_PLAYBACK_DA, "Indspilningsenhed og optagelsesenhed skal vare forskellige"},
/* de */ {IDGS_RECORD_DIFFERENT_PLAYBACK_DE, "Aufnahmegerat muss unterschiedlich vom Abspielgerat sein"},
/* fr */ {IDGS_RECORD_DIFFERENT_PLAYBACK_FR, "Le peripherique de son d'enregistrement doivent etre differents"},
/* hu */ {IDGS_RECORD_DIFFERENT_PLAYBACK_HU, "A felvevo es lejatszo eszkozoknek kulonboznie kell"},
/* it */ {IDGS_RECORD_DIFFERENT_PLAYBACK_IT, "Il device di registrazione deve essere differente da quello di riproduzione"},
/* ko */ {IDGS_RECORD_DIFFERENT_PLAYBACK_KO, ""},  /* fuzzy */
/* nl */ {IDGS_RECORD_DIFFERENT_PLAYBACK_NL, "Opnameapparaat moet anders zijn dan afspeelapparaat"},
/* pl */ {IDGS_RECORD_DIFFERENT_PLAYBACK_PL, "Urz�}dzenie zapisu musi bya inne ni? urz�}dzenie odtwarzania"},
/* ru */ {IDGS_RECORD_DIFFERENT_PLAYBACK_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RECORD_DIFFERENT_PLAYBACK_SV, "Inspelningsenhet och aterspelningsenhet kan inte vara samma"},
/* tr */ {IDGS_RECORD_DIFFERENT_PLAYBACK_TR, "Kayyt aygyty kayyttan yurutme aygyty ile farkly olmak zorundadyr"},
#endif

/* sound.c */
/* en */ {IDGS_WARNING_RECORDING_REALTIME,    N_("Warning! Recording device %s seems to be a realtime device!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_WARNING_RECORDING_REALTIME_DA, "Advarsel! Optageenheden %s synes at vare en realtidsenhed!"},
/* de */ {IDGS_WARNING_RECORDING_REALTIME_DE, "Warnung! Aufnahmegerat %s scheint ein Echtzeitgerat zu sein!"},
/* fr */ {IDGS_WARNING_RECORDING_REALTIME_FR, "Attention! Le peripherique d'enregistrement %s semble etre un peripherique temps reel"},
/* hu */ {IDGS_WARNING_RECORDING_REALTIME_HU, "Figyelem! A %s felvevo eszkoz ugy tunik, valos ideju eszkoz!"},
/* it */ {IDGS_WARNING_RECORDING_REALTIME_IT, "Attenzione! Il device di registrazione %s sembra essere un dispositivo realtime!"},
/* ko */ {IDGS_WARNING_RECORDING_REALTIME_KO, ""},  /* fuzzy */
/* nl */ {IDGS_WARNING_RECORDING_REALTIME_NL, "Waarschuwing! Opnameapparaat %s lijkt een realtime apparaat te zijn!"},
/* pl */ {IDGS_WARNING_RECORDING_REALTIME_PL, "Ostrze?enie! Urz�}dzenie zapisu %s dzia3a chyba w czasie rzeczywistym!"},
/* ru */ {IDGS_WARNING_RECORDING_REALTIME_RU, ""},  /* fuzzy */
/* sv */ {IDGS_WARNING_RECORDING_REALTIME_SV, "Varning! Inspelningsenheten %s verkar vara en realtidsenhet!"},
/* tr */ {IDGS_WARNING_RECORDING_REALTIME_TR, "Uyary! Kayyt aygyty %s gercek zamanly bir aygyt gibi gorunuyor!"},
#endif

/* sound.c */
/* en */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR,    N_("The recording device doesn't support current sound parameters")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_DA, "Optageenheden understotter ikke de valgte lydparametre"},
/* de */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_DE, "Aufnahmegerat unterstutzt derzeitige Soundeinstellungen nicht"},
/* fr */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_FR, "Le peripherique d'enregistrement ne supporte pas les parametres actuels"},
/* hu */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_HU, "A felvevo eszkoz nem tamogatja az aktualis hangbeallitasokat"},
/* it */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_IT, "Il device di registrazione non supporta i parametri attuali"},
/* ko */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_KO, ""},  /* fuzzy */
/* nl */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_NL, "Het opname apparaat ondersteunt de huidige geluid opties niet"},
/* pl */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_PL, "Urz�}dzenie zapisu nie obs3uguje obecnych parametrow d?wieku"},
/* ru */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_SV, "Inspelningsenheten stoder inte aktuella ljudinstallningar"},
/* tr */ {IDGS_RECORD_NOT_SUPPORT_SOUND_PAR_TR, "Kayyt aygyty gecerli ses parametrelerini desteklemiyor"},
#endif

/* sound.c */
/* en */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE,    N_("Sound buffer overflow (cycle based)")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_DA, "Lydbuffer overlob (cykelbaseret)"},
/* de */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_DE, "Sound Puffer Uberlauf (Zyklus basiert)"},
/* fr */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_FR, "Erreur de depassement de tampon son (cycle based)"},
/* hu */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_HU, "Hangpuffer tulcsordulas (ciklus alapu)"},
/* it */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_IT, "Overflow del buffer audio (cycle based)"},
/* ko */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_NL, "Geluidsbuffer overloop (cyclus gebaseerd)"},
/* pl */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_PL, "Przepe3niony bufor d?wieku (cykliczny)"},
/* ru */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_SV, "For mycket data i ljudbufferten (cykelbaserad)"},
/* tr */ {IDGS_SOUND_BUFFER_OVERFLOW_CYCLE_TR, "Ses arabellek tatmasy (cycle bazly)"},
#endif

/* sound.c */
/* en */ {IDGS_SOUND_BUFFER_OVERFLOW,    N_("Sound buffer overflow.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_SOUND_BUFFER_OVERFLOW_DA, "Lydbuffer overlob."},
/* de */ {IDGS_SOUND_BUFFER_OVERFLOW_DE, "Sound Puffer Uberlauf."},
/* fr */ {IDGS_SOUND_BUFFER_OVERFLOW_FR, "Erreur de depassement de tampon son."},
/* hu */ {IDGS_SOUND_BUFFER_OVERFLOW_HU, "Hangpuffer tulcsordulas."},
/* it */ {IDGS_SOUND_BUFFER_OVERFLOW_IT, "Overflow del buffer audio."},
/* ko */ {IDGS_SOUND_BUFFER_OVERFLOW_KO, ""},  /* fuzzy */
/* nl */ {IDGS_SOUND_BUFFER_OVERFLOW_NL, "Geluidsbuffer overloop."},
/* pl */ {IDGS_SOUND_BUFFER_OVERFLOW_PL, "Przepe3niony bufor d?wieku."},
/* ru */ {IDGS_SOUND_BUFFER_OVERFLOW_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SOUND_BUFFER_OVERFLOW_SV, "For mycket data i ljudbufferten."},
/* tr */ {IDGS_SOUND_BUFFER_OVERFLOW_TR, "Ses arabellek tatmasy."},
#endif

/* sound.c */
/* en */ {IDGS_CANNOT_FLUSH,    N_("cannot flush.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_FLUSH_DA, "Kan ikke tomme."},
/* de */ {IDGS_CANNOT_FLUSH_DE, "Entleerung nicht moglich."},
/* fr */ {IDGS_CANNOT_FLUSH_FR, "impossible de vider."},
/* hu */ {IDGS_CANNOT_FLUSH_HU, "nem sikerult uriteni a puffert."},
/* it */ {IDGS_CANNOT_FLUSH_IT, "non e possibile svuotare."},
/* ko */ {IDGS_CANNOT_FLUSH_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_FLUSH_NL, "kan niet spoelen."},
/* pl */ {IDGS_CANNOT_FLUSH_PL, "Nie mo?na opro?nia."},
/* ru */ {IDGS_CANNOT_FLUSH_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_FLUSH_SV, "kan inte tomma."},
/* tr */ {IDGS_CANNOT_FLUSH_TR, "temizlenemedi."},
#endif

/* sound.c */
/* en */ {IDGS_FRAGMENT_PROBLEMS,    N_("fragment problems.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_FRAGMENT_PROBLEMS_DA, "Fragmentproblem."},
/* de */ {IDGS_FRAGMENT_PROBLEMS_DE, "Fragmentierungsproblem."},
/* fr */ {IDGS_FRAGMENT_PROBLEMS_FR, "problemes de fragments."},
/* hu */ {IDGS_FRAGMENT_PROBLEMS_HU, "toredekresz problemak."},
/* it */ {IDGS_FRAGMENT_PROBLEMS_IT, "problemi di frammentazione."},
/* ko */ {IDGS_FRAGMENT_PROBLEMS_KO, ""},  /* fuzzy */
/* nl */ {IDGS_FRAGMENT_PROBLEMS_NL, "fragment problemen."},
/* pl */ {IDGS_FRAGMENT_PROBLEMS_PL, "Problemy z fragmentem"},
/* ru */ {IDGS_FRAGMENT_PROBLEMS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_FRAGMENT_PROBLEMS_SV, "fragmentprogram."},
/* tr */ {IDGS_FRAGMENT_PROBLEMS_TR, "parcalara ayyrma problemi."},
#endif

/* sound.c */
/* en */ {IDGS_RUNNING_TOO_SLOW,    N_("running too slow.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_RUNNING_TOO_SLOW_DA, "Korer for langsomt."},
/* de */ {IDGS_RUNNING_TOO_SLOW_DE, "Ablauf zu langsam."},
/* fr */ {IDGS_RUNNING_TOO_SLOW_FR, "execution trop lente."},
/* hu */ {IDGS_RUNNING_TOO_SLOW_HU, "tul lassan megy."},
/* it */ {IDGS_RUNNING_TOO_SLOW_IT, "esecuzione troppo lenta."},
/* ko */ {IDGS_RUNNING_TOO_SLOW_KO, ""},  /* fuzzy */
/* nl */ {IDGS_RUNNING_TOO_SLOW_NL, "draait te langzaam."},
/* pl */ {IDGS_RUNNING_TOO_SLOW_PL, "dzia3a za wolno."},
/* ru */ {IDGS_RUNNING_TOO_SLOW_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RUNNING_TOO_SLOW_SV, "gar for langsamt."},
/* tr */ {IDGS_RUNNING_TOO_SLOW_TR, "cok yavat calytyyor."},
#endif

/* sound.c */
/* en */ {IDGS_STORE_SOUNDDEVICE_FAILED,    N_("store to sounddevice failed.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_STORE_SOUNDDEVICE_FAILED_DA, "skrivning til lydenhed fejlede."},
/* de */ {IDGS_STORE_SOUNDDEVICE_FAILED_DE, "Speichern auf Sound Gerat ist fehlgeschlagen."},
/* fr */ {IDGS_STORE_SOUNDDEVICE_FAILED_FR, "erreur d'enregistrement sur le peripherique son."},
/* hu */ {IDGS_STORE_SOUNDDEVICE_FAILED_HU, "a hangeszkozon torteno tarolas nem sikerult."},
/* it */ {IDGS_STORE_SOUNDDEVICE_FAILED_IT, "memorizzazione sulla scheda audio fallita."},
/* ko */ {IDGS_STORE_SOUNDDEVICE_FAILED_KO, ""},  /* fuzzy */
/* nl */ {IDGS_STORE_SOUNDDEVICE_FAILED_NL, "opslag naar geluidsapparaat is mislukt."},
/* pl */ {IDGS_STORE_SOUNDDEVICE_FAILED_PL, "zapis do urz�}dzenia d?wieku nie powiod3 sie"},
/* ru */ {IDGS_STORE_SOUNDDEVICE_FAILED_RU, ""},  /* fuzzy */
/* sv */ {IDGS_STORE_SOUNDDEVICE_FAILED_SV, "misslyckades spara i ljudenheten."},
/* tr */ {IDGS_STORE_SOUNDDEVICE_FAILED_TR, "ses aygytyna saklama batarysyz oldu."},
#endif

/* c64/c64export.c */
/* en */ {IDGS_RESOURCE_S_BLOCKED_BY_S,    N_("Resource %s blocked by %s.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_RESOURCE_S_BLOCKED_BY_S_DA, "Resoursen %s er blokeret af %s."},
/* de */ {IDGS_RESOURCE_S_BLOCKED_BY_S_DE, "Resource %s wird von %s blockiert."},
/* fr */ {IDGS_RESOURCE_S_BLOCKED_BY_S_FR, "La ressource %s est bloquee par %s."},
/* hu */ {IDGS_RESOURCE_S_BLOCKED_BY_S_HU, "A %s eroforrast %s fogja."},
/* it */ {IDGS_RESOURCE_S_BLOCKED_BY_S_IT, "Risorsa %s bloccata da %s."},
/* ko */ {IDGS_RESOURCE_S_BLOCKED_BY_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_RESOURCE_S_BLOCKED_BY_S_NL, "Bron %s geblokeerd door %s."},
/* pl */ {IDGS_RESOURCE_S_BLOCKED_BY_S_PL, "Zasob %s blokowany przez %s."},
/* ru */ {IDGS_RESOURCE_S_BLOCKED_BY_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RESOURCE_S_BLOCKED_BY_S_SV, "Resursen %s blockeras av %s."},
/* tr */ {IDGS_RESOURCE_S_BLOCKED_BY_S_TR, "Kaynak %s, %s tarafyndan bloklandy."},
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
/* pl */ {IDGS_TESTING_BEST_FRAME_DELAY_PL, "Sprawdzam najlepsze opo?nienie klatek..."},
/* ru */ {IDGS_TESTING_BEST_FRAME_DELAY_RU, ""},  /* fuzzy */
/* sv */ {IDGS_TESTING_BEST_FRAME_DELAY_SV, "Testar basta ramfordrojning..."},
/* tr */ {IDGS_TESTING_BEST_FRAME_DELAY_TR, "En iyi frame bekleme suresi test ediliyor..."},
#endif

/* network.c */
/* en */ {IDGS_USING_D_FRAMES_DELAY,    N_("Using %d frames delay.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_USING_D_FRAMES_DELAY_DA, "Bruger %d billeders forsinkelse."},
/* de */ {IDGS_USING_D_FRAMES_DELAY_DE, "Benutze %d Frameverzogerung."},
/* fr */ {IDGS_USING_D_FRAMES_DELAY_FR, "Utilisation d'un delai de %d images."},
/* hu */ {IDGS_USING_D_FRAMES_DELAY_HU, "%d kepkocka kesleltetes hasznalata."},
/* it */ {IDGS_USING_D_FRAMES_DELAY_IT, "Utilizzo %d frame di ritardo."},
/* ko */ {IDGS_USING_D_FRAMES_DELAY_KO, ""},  /* fuzzy */
/* nl */ {IDGS_USING_D_FRAMES_DELAY_NL, "%d frames vertraging in gebruik."},
/* pl */ {IDGS_USING_D_FRAMES_DELAY_PL, "U?ywam opo?nienia klatek %d."},
/* ru */ {IDGS_USING_D_FRAMES_DELAY_RU, ""},  /* fuzzy */
/* sv */ {IDGS_USING_D_FRAMES_DELAY_SV, "Anvander %d ramars fordrojning."},
/* tr */ {IDGS_USING_D_FRAMES_DELAY_TR, "%d frame bekleme suresi kullanylyyor."},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER,    N_("Cannot load snapshot file for transfer")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_DA, "Kunne ikke indlase snapshot til overforsel."},
/* de */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_DE, "Kann Snapshot Datei fur Transfer nicht laden"},
/* fr */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_FR, "Impossible de charger l'instantane pour le transfer"},
/* hu */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_HU, "Nem sikerult az atkuldendo pillanatkep fajlt betolteni"},
/* it */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_IT, "Non e possibile caricare il file di snapshot per il trasferimento"},
/* ko */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_NL, "Kan het momentopnamebestand voor versturen niet laden"},
/* pl */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_PL, "Nie mo?na wczytaa pliku zrzutu do transferu"},
/* ru */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_SV, "Kan inte lasa in ogonblicksbildfil for overforing."},
/* tr */ {IDGS_CANNOT_LOAD_SNAPSHOT_TRANSFER_TR, "Transfer icin anlyk goruntu dosyasy yuklenemedi"},
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
/* pl */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_PL, "Wysy3am zrzut do klienta..."},
/* ru */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_SV, "Sander ogonblicksbild till klient..."},
/* tr */ {IDGS_SENDING_SNAPSHOT_TO_CLIENT_TR, "Anlyk goruntu dosyasy istemciye gonderiliyor..."},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT,    N_("Cannot send snapshot to client")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_DA, "Kunne ikke sende snapshot til klient"},
/* de */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_DE, "Kann Snapshot Datei nicht senden"},
/* fr */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_FR, "Impossible d'envoyer l'instantane au client"},
/* hu */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_HU, "Nem sikerult pillanatkepet elkuldeni a klienshez"},
/* it */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_IT, "Non e possibile inviare lo snapshot al client"},
/* ko */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_NL, "Kan de momentopname niet naar de andere computer versturen"},
/* pl */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_PL, "Nie mo?na wys3aa zrzutu do klienta"},
/* ru */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_SV, "Kan inte sanda ogonblicksbild till klient"},
/* tr */ {IDGS_CANNOT_SEND_SNAPSHOT_TO_CLIENT_TR, "Anlyk goruntu dosyasy istemciye gonderilemedi"},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S,    N_("Cannot create snapshot file %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_DA, "Kunne ikke oprette snapshot-fil %s"},
/* de */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_DE, "Kann Snapshot Datei `%s' nicht erzeugen"},
/* fr */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_FR, "Impossible de creer l'instantane %s"},
/* hu */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_HU, "Nem sikerult a pillanatkepfajlt letrehozni (%s)"},
/* it */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_IT, "Non e possibile creare il file di snapshot %s"},
/* ko */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_NL, "Kan het momentopnamebestand %s niet maken"},
/* pl */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_PL, "Nie mo?na utworzya pliku zrzutu %s"},
/* ru */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_SV, "Kan inte skapa ogonblicksbildfil %s"},
/* tr */ {IDGS_CANNOT_CREATE_SNAPSHOT_FILE_S_TR, "Anlyk goruntu dosyasy %s yaratylamady"},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S,    N_("Cannot open snapshot file %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_DA, "Kunne ikke abne snapshot-fil %s"},
/* de */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_DE, "Kann Snapshot Datei `%s' nicht offnen."},
/* fr */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_FR, "Impossible d'ouvrir le fichier %s"},
/* hu */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_HU, "Nem sikerult a pillanatkepfajlt megnyitni (%s)"},
/* it */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_IT, "Non e possibile aprire il file di snapshot %s"},
/* ko */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_NL, "Kan het momentopnamebestand %s niet openen"},
/* pl */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_PL, "Nie mo?na otworzya pliku zrzutu %s"},
/* ru */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_SV, "Kan inte oppna ogonblicksbildfil %s"},
/* tr */ {IDGS_CANNOT_OPEN_SNAPSHOT_FILE_S_TR, "Anlyk goruntu dosyasy %s acylamady"},
#endif

/* network.c */
/* en */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT,    N_("Server is waiting for a client...")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_DA, "Server venter pa en klient..."},
/* de */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_DE, "Server wartet auf Client..."},
/* fr */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_FR, ""},  /* fuzzy */
/* hu */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_HU, ""},  /* fuzzy */
/* it */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_IT, "Il server e in attesa di un client..."},
/* ko */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_KO, ""},  /* fuzzy */
/* nl */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_NL, "De server wacht op de andere computer..."},
/* pl */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_PL, "Serwer czeka na klienta..."},
/* ru */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_SV, "Servern vantar pa en klient..."},
/* tr */ {IDGS_SERVER_IS_WAITING_FOR_CLIENT_TR, "Sunucu bir istemcinin badlanmasy icin bekliyor..."},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT,    N_("Cannot create snapshot file. Select different history directory!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_DA, "Kunne ikke oprette snapshot-fil. Valg et andet historik-katalog!"},
/* de */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_DE, "Kann Snapshot Datei nicht erzeugen. Verwende ein anderes Verzeichnis!"},
/* fr */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_FR, "Impossible de creer le fichier d'instantane. Selectionnez un repertoire d'historique different"},
/* hu */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_HU, "Nem sikerult pillanatkep fajlt letrehozni. Kerem valasszon mas konyvtarat!"},
/* it */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_IT, "Non e possibile creare il file di snapshot. Seleziona una directory diversa per la cronologia."},
/* ko */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_NL, "Kan het momentopnamebestand niet maken. Selecteer een andere geschiedenisdirectory!"},
/* pl */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_PL, "Nie mo?na utworzya pliku zrzutu. Wybierz inny katalog historii!"},
/* ru */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_SV, "Kan inte skapa ogonblicksbildfil. Valj en annan historikkatalog!"},
/* tr */ {IDGS_CANNOT_CREATE_SNAPSHOT_S_SELECT_TR, "Anlyk goruntu dosyasy yaratylamady. Farkly bir tarihce dizini secin!"},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_RESOLVE_S,    N_("Cannot resolve %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_RESOLVE_S_DA, "Kan ikke opsla %s"},
/* de */ {IDGS_CANNOT_RESOLVE_S_DE, "Kann %s nicht auflosen"},
/* fr */ {IDGS_CANNOT_RESOLVE_S_FR, "Impossible de resoudre %s"},
/* hu */ {IDGS_CANNOT_RESOLVE_S_HU, "Nem sikerult %s-t feloldani"},
/* it */ {IDGS_CANNOT_RESOLVE_S_IT, "Non e possibile risolvere %s"},
/* ko */ {IDGS_CANNOT_RESOLVE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_RESOLVE_S_NL, "Onbekende host %s"},
/* pl */ {IDGS_CANNOT_RESOLVE_S_PL, "Nie mo?na znale?a %s"},
/* ru */ {IDGS_CANNOT_RESOLVE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_RESOLVE_S_SV, "Kan inte sla upp %s"},
/* tr */ {IDGS_CANNOT_RESOLVE_S_TR, "%s cozulemedi"},
#endif

/* network.c */
/* en */ {IDGS_CANNOT_CONNECT_TO_S,    N_("Cannot connect to %s (no server running on port %d).")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_CANNOT_CONNECT_TO_S_DA, "Kan ikke forbinde til %s (ingen server pa port %d)."},
/* de */ {IDGS_CANNOT_CONNECT_TO_S_DE, "Kann zu %s nicht verbinden (Kein Server aktiv auf Port %d)."},
/* fr */ {IDGS_CANNOT_CONNECT_TO_S_FR, "Impossible de se connecter a %s (aucun serveur sur le port %d)."},
/* hu */ {IDGS_CANNOT_CONNECT_TO_S_HU, "Nem sikerult %s-hez kapcsolodni (a %d porton nem fut kiszolgalo)"},
/* it */ {IDGS_CANNOT_CONNECT_TO_S_IT, "Non e possibile connettersi a %s (nessun server e attivo sulla porta %d)."},
/* ko */ {IDGS_CANNOT_CONNECT_TO_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_CANNOT_CONNECT_TO_S_NL, "Kan geen verbinding maken met %s (er is geen server aanwezig op poort %d)."},
/* pl */ {IDGS_CANNOT_CONNECT_TO_S_PL, "Nie mo?na pod3�}czya do %s (na porcie %d nie dzia3a ?aden serwer)."},
/* ru */ {IDGS_CANNOT_CONNECT_TO_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CANNOT_CONNECT_TO_S_SV, "Kan inte ansluta till %s (ingen server igang pa port %d)."},
/* tr */ {IDGS_CANNOT_CONNECT_TO_S_TR, "%s badlantysy kurulamady (port %d uzerinde calytan sunucu yok)."},
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
/* pl */ {IDGS_RECEIVING_SNAPSHOT_SERVER_PL, "Odbieranie zrzutu z serwera..."},
/* ru */ {IDGS_RECEIVING_SNAPSHOT_SERVER_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RECEIVING_SNAPSHOT_SERVER_SV, "Tar emot ogoblicksbild fran server..."},
/* tr */ {IDGS_RECEIVING_SNAPSHOT_SERVER_TR, "Sunucudan anlyk goruntu alynyyor..."},
#endif

/* network.c */
/* en */ {IDGS_NETWORK_OUT_OF_SYNC,    N_("Network out of sync - disconnecting.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_NETWORK_OUT_OF_SYNC_DA, "Netvark ude af synk - afbryder forbindelsen."},
/* de */ {IDGS_NETWORK_OUT_OF_SYNC_DE, "Netzwerksynchronisationsproblem - Trenne Verbindung."},
/* fr */ {IDGS_NETWORK_OUT_OF_SYNC_FR, "Le reseau n'est pas synchronise (out of sync error). Deconnexion."},
/* hu */ {IDGS_NETWORK_OUT_OF_SYNC_HU, "A halozat kiesett a szinkronbol - szetkapcsolodas"},
/* it */ {IDGS_NETWORK_OUT_OF_SYNC_IT, "Rete non sincronizzata - disconnesione in corso."},
/* ko */ {IDGS_NETWORK_OUT_OF_SYNC_KO, ""},  /* fuzzy */
/* nl */ {IDGS_NETWORK_OUT_OF_SYNC_NL, "Netwerk niet synchroon - verbinding wordt verbroken."},
/* pl */ {IDGS_NETWORK_OUT_OF_SYNC_PL, "Desynchronizacja sieci - roz3�}czam."},
/* ru */ {IDGS_NETWORK_OUT_OF_SYNC_RU, ""},  /* fuzzy */
/* sv */ {IDGS_NETWORK_OUT_OF_SYNC_SV, "Natverket ur synk - kopplar fran."},
/* tr */ {IDGS_NETWORK_OUT_OF_SYNC_TR, "Ad senkronizasyonu bozuldu - badlanty kesiliyor."},
#endif

/* network.c */
/* en */ {IDGS_REMOTE_HOST_DISCONNECTED,    N_("Remote host disconnected.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_REMOTE_HOST_DISCONNECTED_DA, "Fjernmaskine afbrudt."},
/* de */ {IDGS_REMOTE_HOST_DISCONNECTED_DE, "Entfernter Rechner getrennt."},
/* fr */ {IDGS_REMOTE_HOST_DISCONNECTED_FR, "L'hote distant s'est deconnecte."},
/* hu */ {IDGS_REMOTE_HOST_DISCONNECTED_HU, "A tavoli szamitogep lekapcsolodott."},
/* it */ {IDGS_REMOTE_HOST_DISCONNECTED_IT, "Host remoto disconnesso."},
/* ko */ {IDGS_REMOTE_HOST_DISCONNECTED_KO, ""},  /* fuzzy */
/* nl */ {IDGS_REMOTE_HOST_DISCONNECTED_NL, "Andere computer heeft de verbinding verbroken."},
/* pl */ {IDGS_REMOTE_HOST_DISCONNECTED_PL, "Zdalny host roz3�}czy3 sie."},
/* ru */ {IDGS_REMOTE_HOST_DISCONNECTED_RU, ""},  /* fuzzy */
/* sv */ {IDGS_REMOTE_HOST_DISCONNECTED_SV, "Frankopplad fran fjarrvard."},
/* tr */ {IDGS_REMOTE_HOST_DISCONNECTED_TR, "Uzak sunucu badlantysy kesildi."},
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
/* pl */ {IDGS_REMOTE_HOST_SUSPENDING_PL, "Zawieszenie zdalnego hosta...."},
/* ru */ {IDGS_REMOTE_HOST_SUSPENDING_RU, ""},  /* fuzzy */
/* sv */ {IDGS_REMOTE_HOST_SUSPENDING_SV, "FJarrvarden pausar..."},
/* tr */ {IDGS_REMOTE_HOST_SUSPENDING_TR, "Uzak sunucu askyda..."},
#endif
#endif

/* gfxoutputdrv/ffmpegdrv.c */
/* en */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM,    N_("ffmpegdrv: Cannot open video stream")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_DA, "ffmpegdrv: Kan ikke abne video-strom"},
/* de */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_DE, "ffmpegdrv: Kann video stream nicht offnen"},
/* fr */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_FR, "ffmpegdrv: Impossible d'ouvrir le flux video"},
/* hu */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_HU, "ffmpegdrv: Nem sikerult megnyitni a video adatfolyamot"},
/* it */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_IT, "ffmpegdrv: Non e possibile aprire il flusso video"},
/* ko */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_KO, ""},  /* fuzzy */
/* nl */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_NL, "ffmpegdrv: Kan de videostroom niet openen"},
/* pl */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_PL, "ffmpegdrv: Nie mo?na otworzya strumienia wideo"},
/* ru */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_RU, ""},  /* fuzzy */
/* sv */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_SV, "ffmpegdrv: Kan inte oppna videostrom"},
/* tr */ {IDGS_FFMPEG_CANNOT_OPEN_VSTREAM_TR, "ffmpegdrv: Goruntu akyty acylamady"},
#endif

/* gfxoutputdrv/ffmpegdrv.c */
/* en */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM,    N_("ffmpegdrv: Cannot open audio stream")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_DA, "ffmpegdrv: Kan ikke abne lyd-strom"},
/* de */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_DE, "ffmpegdrv: Kann audio stream nicht offnen"},
/* fr */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_FR, "ffmpegdrv: Impossible d'ouvrir le flux audio"},
/* hu */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_HU, "ffmpegdrv: Nem sikerult megnyitni a audio adatfolyamot"},
/* it */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_IT, "ffmpegdrv: Non e possibile aprire il flusso audio"},
/* ko */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_KO, ""},  /* fuzzy */
/* nl */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_NL, "ffmpegdrv: Kan de audiostroom niet openen"},
/* pl */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_PL, "ffmpegdrv: Nie mo?na otworzya strumienia audio"},
/* ru */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_RU, ""},  /* fuzzy */
/* sv */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_SV, "ffmpegdrv: Kan inte oppna ljudstrom"},
/* tr */ {IDGS_FFMPEG_CANNOT_OPEN_ASTREAM_TR, "ffmpegdrv: Ses akyty acylamady"},
#endif

/* gfxoutputdrv/ffmpegdrv.c */
/* en */ {IDGS_FFMPEG_CANNOT_OPEN_S,    N_("ffmpegdrv: Cannot open %s")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_FFMPEG_CANNOT_OPEN_S_DA, "ffmpegdrv: Kan ikke abne %s"},
/* de */ {IDGS_FFMPEG_CANNOT_OPEN_S_DE, "ffmpegdrv: Offnen von %s fehlgeschlagen"},
/* fr */ {IDGS_FFMPEG_CANNOT_OPEN_S_FR, "ffmpegdrv: Impossible d'ouvrir %s"},
/* hu */ {IDGS_FFMPEG_CANNOT_OPEN_S_HU, "ffmpegdrv: Nem sikerult megnyitni: %s"},
/* it */ {IDGS_FFMPEG_CANNOT_OPEN_S_IT, "ffmpegdrv: Non e possibile aprire %s"},
/* ko */ {IDGS_FFMPEG_CANNOT_OPEN_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_FFMPEG_CANNOT_OPEN_S_NL, "ffmpegdrv: Kan %s niet openen"},
/* pl */ {IDGS_FFMPEG_CANNOT_OPEN_S_PL, "ffmpegdrv: Nie mo?na otworzya %s"},
/* ru */ {IDGS_FFMPEG_CANNOT_OPEN_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_FFMPEG_CANNOT_OPEN_S_SV, "ffmpegdrv: Kan inte oppna %s"},
/* tr */ {IDGS_FFMPEG_CANNOT_OPEN_S_TR, "ffmpegdrv: %s acylamady"},
#endif

/* c64/c64io.c */
/* en */ {IDGS_IO_READ_COLL_AT_X_FROM,    N_("I/O read collision at %X from ")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_IO_READ_COLL_AT_X_FROM_DA, "I/O-lasekollision ved %X fra "},
/* de */ {IDGS_IO_READ_COLL_AT_X_FROM_DE, "I/O Lese Kollision bei %X von "},
/* fr */ {IDGS_IO_READ_COLL_AT_X_FROM_FR, ""},  /* fuzzy */
/* hu */ {IDGS_IO_READ_COLL_AT_X_FROM_HU, ""},  /* fuzzy */
/* it */ {IDGS_IO_READ_COLL_AT_X_FROM_IT, "Collisione di I/O in lettura a %X da "},
/* ko */ {IDGS_IO_READ_COLL_AT_X_FROM_KO, ""},  /* fuzzy */
/* nl */ {IDGS_IO_READ_COLL_AT_X_FROM_NL, "I/O lees botsing op %X van "},
/* pl */ {IDGS_IO_READ_COLL_AT_X_FROM_PL, "Kolizja odczytu we/wy w %X z"},
/* ru */ {IDGS_IO_READ_COLL_AT_X_FROM_RU, ""},  /* fuzzy */
/* sv */ {IDGS_IO_READ_COLL_AT_X_FROM_SV, "I/O-laskollision vid %X fran "},
/* tr */ {IDGS_IO_READ_COLL_AT_X_FROM_TR, "G/C okuma cakytmasy %X'de "},
#endif

/* c64/c64io.c */
/* en */ {IDGS_AND,    N_(" and ")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_AND_DA, " og "},
/* de */ {IDGS_AND_DE, " und "},
/* fr */ {IDGS_AND_FR, ""},  /* fuzzy */
/* hu */ {IDGS_AND_HU, ""},  /* fuzzy */
/* it */ {IDGS_AND_IT, " e "},
/* ko */ {IDGS_AND_KO, " �}�~�CR��i "},
/* nl */ {IDGS_AND_NL, " en "},
/* pl */ {IDGS_AND_PL, "i"},
/* ru */ {IDGS_AND_RU, ""},  /* fuzzy */
/* sv */ {IDGS_AND_SV, " och "},
/* tr */ {IDGS_AND_TR, " ve "},
#endif

/* c64/c64io.c */
/* en */ {IDGS_ALL_DEVICES_DETACHED,    N_(".\nAll the named devices will be detached.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ALL_DEVICES_DETACHED_DA, ".\nAlle de navngivne enheder vil blive frakoblet."},
/* de */ {IDGS_ALL_DEVICES_DETACHED_DE, ".\nAlle genannten Gerate werden entfernt."},
/* fr */ {IDGS_ALL_DEVICES_DETACHED_FR, ".\nTous les peripheriques nommes vont etre detaches."},
/* hu */ {IDGS_ALL_DEVICES_DETACHED_HU, ".\nMinden megnevezett eszkoz le lesz valasztva."},
/* it */ {IDGS_ALL_DEVICES_DETACHED_IT, ".\nTutti i device specificati sarranno rimossi."},
/* ko */ {IDGS_ALL_DEVICES_DETACHED_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ALL_DEVICES_DETACHED_NL, ".\nAlle genoemde apparaten zullen worden ontkoppelt."},
/* pl */ {IDGS_ALL_DEVICES_DETACHED_PL, ".\nWszystkie wymienione urz�}dzenia zostan�} odmontowane."},
/* ru */ {IDGS_ALL_DEVICES_DETACHED_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ALL_DEVICES_DETACHED_SV, ".\nAlla namngivna enheter kommer kopplas fran."},
/* tr */ {IDGS_ALL_DEVICES_DETACHED_TR, ".\nTum isimlendirilmit aygytlar cykartylacaktyr."},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDGS_NO_FILENAME,    N_("No filename!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_NO_FILENAME_DA, "Intet filnavn!"},
/* de */ {IDGS_NO_FILENAME_DE, "Dateiname fehlt!"},
/* fr */ {IDGS_NO_FILENAME_FR, ""},  /* fuzzy */
/* hu */ {IDGS_NO_FILENAME_HU, "Nincs fajlnev!"},
/* it */ {IDGS_NO_FILENAME_IT, "Nessun nome file!"},
/* ko */ {IDGS_NO_FILENAME_KO, ""},  /* fuzzy */
/* nl */ {IDGS_NO_FILENAME_NL, "Geen bestandsnaam!"},
/* pl */ {IDGS_NO_FILENAME_PL, "Brak nazwy pliku!"},
/* ru */ {IDGS_NO_FILENAME_RU, ""},  /* fuzzy */
/* sv */ {IDGS_NO_FILENAME_SV, "Filnamn saknas!"},
/* tr */ {IDGS_NO_FILENAME_TR, "Dosya ismi yok!"},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDGS_ILLEGAL_FILENAME,    N_("Illegal filename!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ILLEGAL_FILENAME_DA, "Ugyldigt filnavn!"},
/* de */ {IDGS_ILLEGAL_FILENAME_DE, "Ungultiger Dateiname!"},
/* fr */ {IDGS_ILLEGAL_FILENAME_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ILLEGAL_FILENAME_HU, "Ervenytelen fajlnev!"},
/* it */ {IDGS_ILLEGAL_FILENAME_IT, "Nome file non valido!"},
/* ko */ {IDGS_ILLEGAL_FILENAME_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ILLEGAL_FILENAME_NL, "Bestandsnaam ongeldig!"},
/* pl */ {IDGS_ILLEGAL_FILENAME_PL, "Z3a nazwa pliku!"},
/* ru */ {IDGS_ILLEGAL_FILENAME_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ILLEGAL_FILENAME_SV, "Ogiltigt filnamn!"},
/* tr */ {IDGS_ILLEGAL_FILENAME_TR, "Kural dyty dosya ismi!"},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDGS_ERROR_CREATING_FILE_S,    N_("Error creating file %s!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ERROR_CREATING_FILE_S_DA, "Fejl under oprettelse af filen %s!"},
/* de */ {IDGS_ERROR_CREATING_FILE_S_DE, "Fehler beim Schreiben: %s."},
/* fr */ {IDGS_ERROR_CREATING_FILE_S_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ERROR_CREATING_FILE_S_HU, "Hiba %s fajl letrehozasa kozben!"},
/* it */ {IDGS_ERROR_CREATING_FILE_S_IT, "Errore durante la creazione del file %s!"},
/* ko */ {IDGS_ERROR_CREATING_FILE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ERROR_CREATING_FILE_S_NL, "Fout bij het maken van bestand %s!"},
/* pl */ {IDGS_ERROR_CREATING_FILE_S_PL, "B3�}d tworzenia pliku %s!"},
/* ru */ {IDGS_ERROR_CREATING_FILE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ERROR_CREATING_FILE_S_SV, "Fel nar filen \"%s\" skulle skapas!"},
/* tr */ {IDGS_ERROR_CREATING_FILE_S_TR, "%s dosyasy yaratylyrken hata oluttu!"},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDGS_ERROR_WRITING_TO_FILE_S,    N_("Error writing to file %s!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ERROR_WRITING_TO_FILE_S_DA, "Fejl ved skrivning til filen %s!"},
/* de */ {IDGS_ERROR_WRITING_TO_FILE_S_DE, "Fehler bei Schreibzugriff: %s!"},
/* fr */ {IDGS_ERROR_WRITING_TO_FILE_S_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ERROR_WRITING_TO_FILE_S_HU, "Hiba %s fajlba iras kozben!"},
/* it */ {IDGS_ERROR_WRITING_TO_FILE_S_IT, "Errore durante la scrittura sul file %s!"},
/* ko */ {IDGS_ERROR_WRITING_TO_FILE_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ERROR_WRITING_TO_FILE_S_NL, "Fout bij het schrijven naar bestand %s!"},
/* pl */ {IDGS_ERROR_WRITING_TO_FILE_S_PL, "B3�}d zapisu do pliku %s!"},
/* ru */ {IDGS_ERROR_WRITING_TO_FILE_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ERROR_WRITING_TO_FILE_S_SV, "Fel vid skrivning till filen %s!"},
/* tr */ {IDGS_ERROR_WRITING_TO_FILE_S_TR, "%s dosyasyna yazylyrken hata oluttu!"},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDGS_DTV_ROM_CREATED,    N_("DTV ROM image created successfully")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_DTV_ROM_CREATED_DA, "DTV-ROM-image oprettet med success"},
/* de */ {IDGS_DTV_ROM_CREATED_DE, "DTV ROM Image erfolgreich erzeugt"},
/* fr */ {IDGS_DTV_ROM_CREATED_FR, ""},  /* fuzzy */
/* hu */ {IDGS_DTV_ROM_CREATED_HU, "DTV ROM kepmas sikeresen letrehozva"},
/* it */ {IDGS_DTV_ROM_CREATED_IT, "Immagine ROM DTV creata con successo"},
/* ko */ {IDGS_DTV_ROM_CREATED_KO, ""},  /* fuzzy */
/* nl */ {IDGS_DTV_ROM_CREATED_NL, "DTV ROM bestand gemaakt!"},
/* pl */ {IDGS_DTV_ROM_CREATED_PL, "Z powodzeniem utworzono obraz ROM DTV"},
/* ru */ {IDGS_DTV_ROM_CREATED_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DTV_ROM_CREATED_SV, "DTV-ROM-avbildning skapades framgangsrikt"},
/* tr */ {IDGS_DTV_ROM_CREATED_TR, "DTV ROM imajy bataryyla olutturuldu"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_TYPE,    N_("Type")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_TYPE_DA, "Type"},
/* de */ {IDGS_TYPE_DE, "Typ"},
/* fr */ {IDGS_TYPE_FR, "type"},
/* hu */ {IDGS_TYPE_HU, "Tipus"},
/* it */ {IDGS_TYPE_IT, "Tipo"},
/* ko */ {IDGS_TYPE_KO, "A?�Eu"},
/* nl */ {IDGS_TYPE_NL, "Soort"},
/* pl */ {IDGS_TYPE_PL, "Typ"},
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
/* pl */ {IDGS_COMMAND_S_UNKNOWN_PL, "Polecenie `%s' nieznane.\n"},
/* ru */ {IDGS_COMMAND_S_UNKNOWN_RU, ""},  /* fuzzy */
/* sv */ {IDGS_COMMAND_S_UNKNOWN_SV, "Kommandot \"%s\" ar okant.\n"},
/* tr */ {IDGS_COMMAND_S_UNKNOWN_TR, "`%s' komutu bilinmiyor.\n"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_NO_HELP_AVAILABLE_FOR_S,    N_("No help available for `%s'\n")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_NO_HELP_AVAILABLE_FOR_S_DA, "Ingen hjalp tilgangelig for \"%s\"\n"},
/* de */ {IDGS_NO_HELP_AVAILABLE_FOR_S_DE, "Es ist keine Hilfe fur `%s' verfugbar\n"},
/* fr */ {IDGS_NO_HELP_AVAILABLE_FOR_S_FR, ""},  /* fuzzy */
/* hu */ {IDGS_NO_HELP_AVAILABLE_FOR_S_HU, "Nincs sugo a `%s' parancshoz\n"},
/* it */ {IDGS_NO_HELP_AVAILABLE_FOR_S_IT, "Nessun help disponibile per `%s'\n"},
/* ko */ {IDGS_NO_HELP_AVAILABLE_FOR_S_KO, ""},  /* fuzzy */
/* nl */ {IDGS_NO_HELP_AVAILABLE_FOR_S_NL, "Geen help beschikbaar voor `%s'\n"},
/* pl */ {IDGS_NO_HELP_AVAILABLE_FOR_S_PL, "Pomoc dla '%s' niedostepna\n"},
/* ru */ {IDGS_NO_HELP_AVAILABLE_FOR_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_NO_HELP_AVAILABLE_FOR_S_SV, "Hjalp saknas for \"%s\"\n"},
/* tr */ {IDGS_NO_HELP_AVAILABLE_FOR_S_TR, "`%s' icin mevcut bir yardym metni yok\n"},
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
/* pl */ {IDGS_SYNTAX_S_S_PL, "\nSk3adnia: %s %s\n"},
/* ru */ {IDGS_SYNTAX_S_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SYNTAX_S_S_SV, "\nSyntax: %s %s\n"},
/* tr */ {IDGS_SYNTAX_S_S_TR, "\nSozdizimi: %s %s\n"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_ABBREVIATION_S,    N_("Abbreviation: %s\n")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ABBREVIATION_S_DA, "Forkortelse: %s\n"},
/* de */ {IDGS_ABBREVIATION_S_DE, "Abkurzung: %s\n"},
/* fr */ {IDGS_ABBREVIATION_S_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ABBREVIATION_S_HU, "Rovidites: %s\n"},
/* it */ {IDGS_ABBREVIATION_S_IT, "Abbreviazione: %s\n"},
/* ko */ {IDGS_ABBREVIATION_S_KO, "Aa?a: %s\n"},
/* nl */ {IDGS_ABBREVIATION_S_NL, "Afkorting: %s\n"},
/* pl */ {IDGS_ABBREVIATION_S_PL, "Skrot: %s\n"},
/* ru */ {IDGS_ABBREVIATION_S_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ABBREVIATION_S_SV, "Forkortning: %s\n"},
/* tr */ {IDGS_ABBREVIATION_S_TR, "Kysaltma: %s\n"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_AVAILABLE_COMMANDS_ARE,    N_("Available commands are:")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_AVAILABLE_COMMANDS_ARE_DA, "Tilgangelige kommandoer:"},
/* de */ {IDGS_AVAILABLE_COMMANDS_ARE_DE, "Zulassige Kommandos sind:"},
/* fr */ {IDGS_AVAILABLE_COMMANDS_ARE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_AVAILABLE_COMMANDS_ARE_HU, ""},  /* fuzzy */
/* it */ {IDGS_AVAILABLE_COMMANDS_ARE_IT, "I comandi disponibili sono:"},
/* ko */ {IDGS_AVAILABLE_COMMANDS_ARE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_AVAILABLE_COMMANDS_ARE_NL, "Beschikbare commandos zijn:"},
/* pl */ {IDGS_AVAILABLE_COMMANDS_ARE_PL, "Dostepne opcje to:"},
/* ru */ {IDGS_AVAILABLE_COMMANDS_ARE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_AVAILABLE_COMMANDS_ARE_SV, "Tillgangliga kommandon:"},
/* tr */ {IDGS_AVAILABLE_COMMANDS_ARE_TR, "Kullanylabilir komutlar:"},
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
/* pl */ {IDGS_MACHINE_STATE_COMMANDS_PL, "Komendy stanu maszyny:"},
/* ru */ {IDGS_MACHINE_STATE_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MACHINE_STATE_COMMANDS_SV, "Kommandon for maskinstatus:"},
/* tr */ {IDGS_MACHINE_STATE_COMMANDS_TR, "Makine durum komutlary:"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MEMSPACE,    N_("memspace")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MEMSPACE_DA, "huk.omrade"},
/* de */ {IDGS_MEMSPACE_DE, "Speicherbereich"},
/* fr */ {IDGS_MEMSPACE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MEMSPACE_HU, ""},  /* fuzzy */
/* it */ {IDGS_MEMSPACE_IT, "spazio di memoria"},
/* ko */ {IDGS_MEMSPACE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MEMSPACE_NL, "geheugenruimte"},
/* pl */ {IDGS_MEMSPACE_PL, "memspace"},
/* ru */ {IDGS_MEMSPACE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MEMSPACE_SV, "minnesomrade"},
/* tr */ {IDGS_MEMSPACE_TR, "bellekalany"},
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
/* pl */ {IDGS_BANKNAME_PL, "bankname"},
/* ru */ {IDGS_BANKNAME_RU, ""},  /* fuzzy */
/* sv */ {IDGS_BANKNAME_SV, "banknamn"},
/* tr */ {IDGS_BANKNAME_TR, "bankismi"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BANK_DESCRIPTION,    N_("If bankname is not given, print the possible banks for the memspace.\nIf bankname is given set the current bank in the memspace to the given\nbank.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BANK_DESCRIPTION_DA, "Hvis banknavn ikke angives vises mulige banker for hukommelsesomradet.\nHvis banknavn angives sattes aktuel bank i hukommelsesomradet til den\nangivne bank."},
/* de */ {IDGS_MON_BANK_DESCRIPTION_DE, "Falls `bankname' nicht angegeben wird, Ausgabe der moglichen Banke in `memspace'.\nFalls `bankname' angegeben wird, setze aktuelle Bank in `memspace' mit angegebener Bank."},
/* fr */ {IDGS_MON_BANK_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BANK_DESCRIPTION_HU, "Ha a lap szama nincs megadva, kiirja a lehetseges lapokat a memoria terbol.\nHa meg van adva, az aktualis lap szamot a memoria terben a megadott lapra allitja."},
/* it */ {IDGS_MON_BANK_DESCRIPTION_IT, "Se non viene specificato il nome del banco, stampa tutti i banchi\npossibili per lo spazio di memoria.\nSe viene specificato il nome del banco, imposta il banco attuale nello\nspazio di memoria specificato."},
/* ko */ {IDGS_MON_BANK_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BANK_DESCRIPTION_NL, "Als de banknaam niet is opgegeven worden de mogelijke banken voor de\ngeheugenruimte weergegeven. Als de banknaam is opgegeven dan wordt de\nhuidige bank in de geheugenruimte gezet volgens de opgegeven banknaam."},
/* pl */ {IDGS_MON_BANK_DESCRIPTION_PL, "Je��li nie podano nazwy banku, pokazuje mo?liwe banki pamieci.\nJe��li podano nazwe banku, ustawia obecny bank pamieci na\ndany bank."},
/* ru */ {IDGS_MON_BANK_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BANK_DESCRIPTION_SV, "Om banknamn inte anges, skriv ut mojliga bankar for minnesomradet.\nOm banknamn anges, satt aktuell bank i minnesomradet till den givna\nbanken."},
/* tr */ {IDGS_MON_BANK_DESCRIPTION_TR, "Eder bank ismi verilmemitse, bellek alany icin uygun banklar yazdyrylyr.\nEder bank ismi verilmitse, gecerli bank bellek alany icinde verilen\nbanka etitlenir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BACKTRACE_DESCRIPTION,    N_("Print JSR call chain (most recent call first). Stack offset\nrelative to SP+1 is printed in parentheses. This is a best guess\nonly.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BACKTRACE_DESCRIPTION_DA, "Vis JSR-kaldekade (seneste kald overst). Stakafstand\nrelativ til SP+1 vises i parantes. Dette er kun et\ngat."},
/* de */ {IDGS_MON_BACKTRACE_DESCRIPTION_DE, "Zeige JSR Aufrufkette (letzter Aufruf zuerst). Stack offset\nwird relative zu SP+1 in Klammern gezeigt. Dies ist jedoch nur\neine Schatzung."},
/* fr */ {IDGS_MON_BACKTRACE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BACKTRACE_DESCRIPTION_HU, "JSR hivas lista kiirasa (legutobbi eloszor). A verem SP+1\nhelyen levo tartalma zarojelben. Ez csak\negy legjobb becsles."},
/* it */ {IDGS_MON_BACKTRACE_DESCRIPTION_IT, "Stampa la catena di chiamate JSR (la chiamata piu recente per prima).\nL'offset dello stack relativo a SP+1 e stampato tra parentesi. Questo e\nsolo l'ipotesi migliore."},
/* ko */ {IDGS_MON_BACKTRACE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BACKTRACE_DESCRIPTION_NL, "Toon JSR gebruik (meest recent gebruikt eerst). De stack\ncompensatie relatief ten opzichte van SP+1 zal worden getoont\nbinnen de aanhalingtekens. Dit is op basis van de beste gok."},
/* pl */ {IDGS_MON_BACKTRACE_DESCRIPTION_PL, "Pokazuje 3ancuch wezwan JSR. Wyrownanie stosu relatywne\ndo SP+1 jest pokazane w nawiasach. Warto��a jest szacowana."},
/* ru */ {IDGS_MON_BACKTRACE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BACKTRACE_DESCRIPTION_SV, "Skriv JSR-anropskedja (senaste anrop forst). Stackavstand\nrelativt till SP+1 visas inom parantes. Detta ar bara en\ngissning."},
/* tr */ {IDGS_MON_BACKTRACE_DESCRIPTION_TR, "JSR cadry zincirini yazdyr (en son cadrylar oncelikli). Yydyt ofseti\nSP+1'e badly olarak parantez icersinde yazdyrylyr. Bu yalnyzca en iyi\ntahmindir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_CPU_DESCRIPTION,    N_("Specify the type of CPU currently used (6502/z80).")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_CPU_DESCRIPTION_DA, "Angiv typen af CPU der anvendes for ojeblikket (6502/z80)."},
/* de */ {IDGS_MON_CPU_DESCRIPTION_DE, "CPU Typ setzen (6502/z80)"},
/* fr */ {IDGS_MON_CPU_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_CPU_DESCRIPTION_HU, "A processzor tipusanak megadasa (6502/z80)."},
/* it */ {IDGS_MON_CPU_DESCRIPTION_IT, "Specifica il tipo di CPU utilizzata al momento (6502/z80)."},
/* ko */ {IDGS_MON_CPU_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_CPU_DESCRIPTION_NL, "Geef de soort CPU die op dit moment in gebruik is (6502/z80)."},
/* pl */ {IDGS_MON_CPU_DESCRIPTION_PL, "Okre��l typ obecnie u?ywanego CPU (6502/z80)."},
/* ru */ {IDGS_MON_CPU_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_CPU_DESCRIPTION_SV, "Ange typ av CPU som anvands for narvarande (6502/z80)."},
/* tr */ {IDGS_MON_CPU_DESCRIPTION_TR, "Tu anda kullanylmakta olan CPU tipini belirleyin (6502/z80)."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_COUNT,    N_("count")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_COUNT_DA, "antal"},
/* de */ {IDGS_COUNT_DE, "Zahler"},
/* fr */ {IDGS_COUNT_FR, ""},  /* fuzzy */
/* hu */ {IDGS_COUNT_HU, ""},  /* fuzzy */
/* it */ {IDGS_COUNT_IT, "contatore"},
/* ko */ {IDGS_COUNT_KO, ""},  /* fuzzy */
/* nl */ {IDGS_COUNT_NL, "hoeveelheid"},
/* pl */ {IDGS_COUNT_PL, "count"},
/* ru */ {IDGS_COUNT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_COUNT_SV, "antal"},
/* tr */ {IDGS_COUNT_TR, "adet"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_CPUHISTORY_DESCRIPTION,    N_("Show <count> last executed commands.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_CPUHISTORY_DESCRIPTION_DA, "Vis <antal> senest eksekverede instruktioner."},
/* de */ {IDGS_MON_CPUHISTORY_DESCRIPTION_DE, "Zeige [<Zahler>] zuletzt ausgefuhrte Kommandos"},
/* fr */ {IDGS_MON_CPUHISTORY_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_CPUHISTORY_DESCRIPTION_HU, "<darab> utoljara vegrehajtott utasitas mutatasa."},
/* it */ {IDGS_MON_CPUHISTORY_DESCRIPTION_IT, "Mostra gli ultimi <contatore> comandi eseguiti."},
/* ko */ {IDGS_MON_CPUHISTORY_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_CPUHISTORY_DESCRIPTION_NL, "Toon <hoeveelheid> laatst uitgevoerde commandos."},
/* pl */ {IDGS_MON_CPUHISTORY_DESCRIPTION_PL, "Pokazuje <ilo��a> ostatnio wykonanych polecen."},
/* ru */ {IDGS_MON_CPUHISTORY_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_CPUHISTORY_DESCRIPTION_SV, "Visa <antal> senast exekverade kommandon."},
/* tr */ {IDGS_MON_CPUHISTORY_DESCRIPTION_TR, "<adet> son calyttyrylan komutlary goster."},
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
/* pl */ {IDGS_FILENAME_PL, "filename"},
/* ru */ {IDGS_FILENAME_RU, ""},  /* fuzzy */
/* sv */ {IDGS_FILENAME_SV, "filnamn"},
/* tr */ {IDGS_FILENAME_TR, "dosyaismi"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DUMP_DESCRIPTION,    N_("Write a snapshot of the machine into the file specified.\nThis snapshot is compatible with a snapshot written out by the UI.\nNote: No ROM images are included into the dump.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DUMP_DESCRIPTION_DA, "Skriv et snapshot til den angivne fil.\nDette snapshot er kompatibelt med dem, der oprettes fra menuen.\nOBS: ROM-images inkluderes ikke i snapshot."},
/* de */ {IDGS_MON_DUMP_DESCRIPTION_DE, "Schreibe eine Snapsho Datei der Maschine auf die angebene Datei.\nDieser Snapshot ist kompatible zu einem Snapshot initiiert aus dem Menu.\nHinweis: Die ROM Images werden im Snapshot nicht inkludiert."},
/* fr */ {IDGS_MON_DUMP_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DUMP_DESCRIPTION_HU, "Pillanatkep irasa a geprol a megadott fajlba. A pillanatkep\nkompatibilis azzal, amelyet a grafikus felulet hoz letre.\nMegjegyzes: a ROM kepmasok nem kerulnek bele."},
/* it */ {IDGS_MON_DUMP_DESCRIPTION_IT, "Scrive uno snapshot del computer sul file specificato.\nQuesto snapshot e compatibile con uno snapshot scritto dall'IU.\nNota: Le immagini ROM non sono incluse nel dump."},
/* ko */ {IDGS_MON_DUMP_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DUMP_DESCRIPTION_NL, "Schrijf een momentopname van de machine naar de opgegeven bestand.\nDeze momentopname is compatibel met een momentopname zoals geschreven van\nuit het menu.\nNB: ROM bestanden zijn niet opgenomen in de momentopname."},
/* pl */ {IDGS_MON_DUMP_DESCRIPTION_PL, "Zapis zrzutu maszyny do danego pliku.\nZrzut ten jest kompatybilny ze zrzutami zapisywanymi przez UI.\nUwaga: W zrzucie nie s�} zawarte ?adne obrazy ROM."},
/* ru */ {IDGS_MON_DUMP_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DUMP_DESCRIPTION_SV, "Skriv en ogonblicksbild av maskinen till den angivna filen.\nOgonblicksbilden ar kompatibel med de som skapas fran menyn.\nObservera: ROM-avbildningar inkluderas inte i bilden."},
/* tr */ {IDGS_MON_DUMP_DESCRIPTION_TR, "Belirtilen dosya icersine makinenin anlyk goruntusunu yaz.\nBu anlyk goruntu UI dytyndan yazdyrylan anlyk goruntu ile uyumludur.\nNot: Hicbir ROM imajy dokum icersinde yer almaz."},
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
/* pl */ {IDGS_ADDRESS_PL, "address"},
/* ru */ {IDGS_ADDRESS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ADDRESS_SV, "adress"},
/* tr */ {IDGS_ADDRESS_TR, "adres"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_GOTO_DESCRIPTION,    N_("Change the PC to ADDRESS and continue execution")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_GOTO_DESCRIPTION_DA, "Andr programtalleren (PC) til ADRESSE og fortsat eksekvering"},
/* de */ {IDGS_MON_GOTO_DESCRIPTION_DE, "Setze PC auf ADRESSE und setze Ausfuhrung fort"},
/* fr */ {IDGS_MON_GOTO_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_GOTO_DESCRIPTION_HU, "A PC allitasa ADDRESS cimre es folytatas"},
/* it */ {IDGS_MON_GOTO_DESCRIPTION_IT, "Cambia il PC in INDIRIZZO e continua l'esecuzione"},
/* ko */ {IDGS_MON_GOTO_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_GOTO_DESCRIPTION_NL, "Zet de PC naar ADRES en ga door met de uitvoering van instructies."},
/* pl */ {IDGS_MON_GOTO_DESCRIPTION_PL, "Zmien PC na ADRES i wykonuj dalej"},
/* ru */ {IDGS_MON_GOTO_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_GOTO_DESCRIPTION_SV, "Andra PC till ADRESS och fortsatt exekveringen"},
/* tr */ {IDGS_MON_GOTO_DESCRIPTION_TR, "PC'yi ADDRESS'e cevirip calyttyrmaya devam edin"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_IO_DESCRIPTION,    N_("Print out the I/O area of the emulated machine.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_IO_DESCRIPTION_DA, "Udskriv I/O-omradet for den emulerede maskine."},
/* de */ {IDGS_MON_IO_DESCRIPTION_DE, "Zeige den I/O Bereich der emulierten Maschine."},
/* fr */ {IDGS_MON_IO_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_IO_DESCRIPTION_HU, "Az emulalt gep I/O tartomanyanak mutatasa."},
/* it */ {IDGS_MON_IO_DESCRIPTION_IT, "Stampa l'area di I/O del computer emulato."},
/* ko */ {IDGS_MON_IO_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_IO_DESCRIPTION_NL, "Toon de I/O geheugenruimte van de huidige machine."},
/* pl */ {IDGS_MON_IO_DESCRIPTION_PL, "Poka? obszar we/wy emulowanej maszyny."},
/* ru */ {IDGS_MON_IO_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_IO_DESCRIPTION_SV, "Skriv I/O-omradet for den emulerade maskinen."},
/* tr */ {IDGS_MON_IO_DESCRIPTION_TR, "Emule edilen makinenin G/C alanyny yazdyr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_EXPORT_DESCRIPTION,    N_("Print out list of attached expansion port devices.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_EXPORT_DESCRIPTION_DA, "Udskriv liste over tilsluttede udviddelsesportenheder"},
/* de */ {IDGS_MON_EXPORT_DESCRIPTION_DE, "Zeige eine Liste der Gerate am Expansion Port."},
/* fr */ {IDGS_MON_EXPORT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_EXPORT_DESCRIPTION_HU, ""},  /* fuzzy */
/* it */ {IDGS_MON_EXPORT_DESCRIPTION_IT, "Stampa lista dei dispositivi collegati sulla porta di espansione."},
/* ko */ {IDGS_MON_EXPORT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_EXPORT_DESCRIPTION_NL, "Druk een lijst van gekoppelde uitbreidingspoort apparaten af."},
/* pl */ {IDGS_MON_EXPORT_DESCRIPTION_PL, "Wydrukuj liste pod3�}czonych urz�}dzen portow rozszerzen."},
/* ru */ {IDGS_MON_EXPORT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_EXPORT_DESCRIPTION_SV, "Skriv ut lista over anslutna expansionsportsenheter."},
/* tr */ {IDGS_MON_EXPORT_DESCRIPTION_TR, "Genitletme yuvasyna takyly aygytlaryn listesini yazdyr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_NEXT_DESCRIPTION,    N_("Advance to the next instruction.  Subroutines are treated as\na single instruction.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_NEXT_DESCRIPTION_DA, "Ga frem til naste instruktion. Subrutiner bliver behandlet som\nen enkelt instruktion."},
/* de */ {IDGS_MON_NEXT_DESCRIPTION_DE, "Fahre bis zur nachsten Instruktion fort.\nUnterroutinen werden wie eine einzelne Instruktion behandelt."},
/* fr */ {IDGS_MON_NEXT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_NEXT_DESCRIPTION_HU, "A kovetkezo utasitasra lepes.  A szubrutinokat egy\nutasitasnak tekinti."},
/* it */ {IDGS_MON_NEXT_DESCRIPTION_IT, "Passa alla prossima istruzione. Le subrutine sono trattate come\nuna singola istruzione."},
/* ko */ {IDGS_MON_NEXT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_NEXT_DESCRIPTION_NL, "Ga naar de volgende instructie. Subroutines worden behandled als een\nenkele instructie."},
/* pl */ {IDGS_MON_NEXT_DESCRIPTION_PL, "Przechodzi do nastepnej instrukcji. Procedury s�} traktowane\njak pojedyncze instrukcje."},
/* ru */ {IDGS_MON_NEXT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_NEXT_DESCRIPTION_SV, "Ga till nasta instruktion. Underrutiner hanteras som en\nenda instruktion."},
/* tr */ {IDGS_MON_NEXT_DESCRIPTION_TR, "Sonraki komuta ilerle.  Altrutinler tek bir komutmut\ngibi itlendi."},
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
/* pl */ {IDGS_REG_NAME_PL, "reg_name"},
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
/* ko */ {IDGS_NUMBER_KO, "?yAU"},
/* nl */ {IDGS_NUMBER_NL, "nummer"},
/* pl */ {IDGS_NUMBER_PL, "numer"},
/* ru */ {IDGS_NUMBER_RU, ""},  /* fuzzy */
/* sv */ {IDGS_NUMBER_SV, "nummer"},
/* tr */ {IDGS_NUMBER_TR, "sayy"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_REGISTERS_DESCRIPTION,    N_("Assign respective registers.  With no parameters, display register\nvalues.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_REGISTERS_DESCRIPTION_DA, "Tildel vardi til registre. Uden parametre vises nuvarende vardier\ni registrene."},
/* de */ {IDGS_MON_REGISTERS_DESCRIPTION_DE, "Zuweisung auf entsprechende Register. Ohne Parameter, zeige Register Werte."},
/* fr */ {IDGS_MON_REGISTERS_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_REGISTERS_DESCRIPTION_HU, "Megadott regiszterek beallitasa. Parameterek nelkul, a regiszterek\ntartalmanak kiirasa."},
/* it */ {IDGS_MON_REGISTERS_DESCRIPTION_IT, "Assegna i rispettivi registri. Senza parametri, mostra i valori dei\nregistri."},
/* ko */ {IDGS_MON_REGISTERS_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_REGISTERS_DESCRIPTION_NL, "Vul opgegeven registers met de toebehorende waarde. Zonder parameter, toon\nde huidige waarden in de registers."},
/* pl */ {IDGS_MON_REGISTERS_DESCRIPTION_PL, "Przyporz�}dkowuje odpowiednie rejestry. Bez podanych parametrow\npokazuje warto��ci rejestrow."},
/* ru */ {IDGS_MON_REGISTERS_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_REGISTERS_DESCRIPTION_SV, "Tilldela respektive register. Utan parametrar visas innehallet\ni registren."},
/* tr */ {IDGS_MON_REGISTERS_DESCRIPTION_TR, "Syrayla registerlara ata.  parametreler olmadan, register dederlerini\ngoruntule."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_RESET_DESCRIPTION,    N_("Reset the machine or drive. Type: 0 = soft, 1 = hard, 8-11 = drive.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_RESET_DESCRIPTION_DA, "Reset maskine eller diskettedrev. Type: 0 = blod, 1 = hard,\n8-11 = diskettedrev."},
/* de */ {IDGS_MON_RESET_DESCRIPTION_DE, "Reset der Maschine oder des Laufwerks. Typ: 0 = soft, 1 = hart, 8-11 = Laufwerk."},
/* fr */ {IDGS_MON_RESET_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_RESET_DESCRIPTION_HU, "A szamitogep vagy meghajto ujrainditasa. Tipus: 0 = meleg, 1 = hideg, 8-11 = meghajto."},
/* it */ {IDGS_MON_RESET_DESCRIPTION_IT, "Resetta il computer o il drive. Tipo: 0 = soft, 1 = hard, 8-11 = drive."},
/* ko */ {IDGS_MON_RESET_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_RESET_DESCRIPTION_NL, "Reset de machine of drive. Soort: 0 = zacht, 1 = hard, 8-11 = drive."},
/* pl */ {IDGS_MON_RESET_DESCRIPTION_PL, "Reset maszyny lub napedu. Typ: 0 = miekki, 1 = twardy, 8-11 = napedu."},
/* ru */ {IDGS_MON_RESET_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_RESET_DESCRIPTION_SV, "Aterstall maskinen eller diskettstationen. Typ: 0 = mjuk, 1 = hard,\n8-11 = diskettstation."},
/* tr */ {IDGS_MON_RESET_DESCRIPTION_TR, "Makine ya da surucuyu resetle. Tip: 0 = soft, 1 = hard, 8-11 = drive."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_RETURN_DESCRIPTION,    N_("Continues execution and returns to the monitor just before the next\nRTS or RTI is executed.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_RETURN_DESCRIPTION_DA, "Fortsat eksekveringen og vend tilbage til monitoren lige inden naste\nRTS eller RTI udfores."},
/* de */ {IDGS_MON_RETURN_DESCRIPTION_DE, "Setzt Ausfuhrung fort und retourniert bevor der nachsten RTS oder RTI instruction."},
/* fr */ {IDGS_MON_RETURN_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_RETURN_DESCRIPTION_HU, "Folytatja a vegrehajtast es visszater a monitorba a kovetkezo\nRTS vagy RTI utasitas elott."},
/* it */ {IDGS_MON_RETURN_DESCRIPTION_IT, "Continua l'esecuzione e ritorna al monitor subito prima della prossima\nesecuzione di RTS o RTI."},
/* ko */ {IDGS_MON_RETURN_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_RETURN_DESCRIPTION_NL, "Ga door met uitvoeren van instructies en kom terug naar de monitor net voor de\nvolgende RTS of RTI wordt uitgevoerd."},
/* pl */ {IDGS_MON_RETURN_DESCRIPTION_PL, "Wykonuje dalej i wraca do monitora tu? przed wykonaniem\nnastepnego RTS lub RTI."},
/* ru */ {IDGS_MON_RETURN_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_RETURN_DESCRIPTION_SV, "Fortsatt exekveringen och aterga till monitorn precis innan nasta\nRTS eller RTI exekveras."},
/* tr */ {IDGS_MON_RETURN_DESCRIPTION_TR, "Calytmaya devam eder ve sonraki RTS ya da RTI calyttyrylmadan hemen once\nmonitore geri doner."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_SCREEN_DESCRIPTION,    N_("Displays the contents of the screen.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_SCREEN_DESCRIPTION_DA, "Viser skarmens indhold."},
/* de */ {IDGS_MON_SCREEN_DESCRIPTION_DE, "Zeigt Bildschirminhalt."},
/* fr */ {IDGS_MON_SCREEN_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_SCREEN_DESCRIPTION_HU, "A kepernyo tartalmanak mutatasa."},
/* it */ {IDGS_MON_SCREEN_DESCRIPTION_IT, "Mostra il contenuto dello schermo."},
/* ko */ {IDGS_MON_SCREEN_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_SCREEN_DESCRIPTION_NL, "Toont de inhoud van het scherm."},
/* pl */ {IDGS_MON_SCREEN_DESCRIPTION_PL, "Pokazuje zawarto��a ekranu."},
/* ru */ {IDGS_MON_SCREEN_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_SCREEN_DESCRIPTION_SV, "Visar skarmens innehall."},
/* tr */ {IDGS_MON_SCREEN_DESCRIPTION_TR, "Ekran iceridini goruntuler."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_STEP_DESCRIPTION,    N_("Single-step through instructions.  COUNT allows stepping\nmore than a single instruction at a time.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_STEP_DESCRIPTION_DA, "Ga skridtvis gennem instruktioner. Hvis ANTAL angives kan\nflere instruktioner udfores i hvert skridt."},
/* de */ {IDGS_MON_STEP_DESCRIPTION_DE, "Einzelschritt Ausfuhrung durch Instruktionen. COUNT erlaubt die Ausfuhrung\nmehrerer Instruktionen auf einmal."},
/* fr */ {IDGS_MON_STEP_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_STEP_DESCRIPTION_HU, "Lepkedes egyesevel az utasitasokon.  A DARAB-bal beallithato,\nha tobb utasitast kell ugrani egyszerre."},
/* it */ {IDGS_MON_STEP_DESCRIPTION_IT, "Modalita single step attraverso le istruzioni. Il CONTATORE permette\ndi attraversare piu di una singola istruzione per volta."},
/* ko */ {IDGS_MON_STEP_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_STEP_DESCRIPTION_NL, "Enkel-stap door de instructies. AANTAL zorgt ervoor dat er meerdere\ninstructies worden uitgevoerd in een keer."},
/* pl */ {IDGS_MON_STEP_DESCRIPTION_PL, "Przechodzi przez instrukcje krok po kroku. COUNT pozwala\nprzechodzia przez wiecej ni? jedn�} instrukcje na raz."},
/* ru */ {IDGS_MON_STEP_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_STEP_DESCRIPTION_SV, "Stega genom instruktioner. ANTAL gor det mojligt att stega\ngenom mer an en enkel instruktion i varje steg."},
/* tr */ {IDGS_MON_STEP_DESCRIPTION_TR, "Komutlara dodru tek-adym.  COUNT bir defada birden fazla\nkomutu adymlamaya izin verir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_UNDUMP_DESCRIPTION,    N_("Read a snapshot of the machine from the file specified.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_UNDUMP_DESCRIPTION_DA, "Indlas snapshot af maskinen fra den angivne fil."},
/* de */ {IDGS_MON_UNDUMP_DESCRIPTION_DE, "Lese einen Snapshot der Maschine aus der angegebenen Datei."},
/* fr */ {IDGS_MON_UNDUMP_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_UNDUMP_DESCRIPTION_HU, "A pillanatkep betoltese a megadott fajlbol."},
/* it */ {IDGS_MON_UNDUMP_DESCRIPTION_IT, "Legge lo snapshot del computer dal file specificato."},
/* ko */ {IDGS_MON_UNDUMP_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_UNDUMP_DESCRIPTION_NL, "Lees een momentopname voor de machine van het opgegeven bestand."},
/* pl */ {IDGS_MON_UNDUMP_DESCRIPTION_PL, "Odczytaj zrzut maszyny z okre��lonego pliku."},
/* ru */ {IDGS_MON_UNDUMP_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_UNDUMP_DESCRIPTION_SV, "Las en ogonblicksbild for maskinen fran den angivna filen."},
/* tr */ {IDGS_MON_UNDUMP_DESCRIPTION_TR, "Belirtilen dosyadan makinenin anlyk goruntusunu oku."},
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
/* pl */ {IDGS_SYMBOL_TABLE_COMMANDS_PL, "Polecenia tablicy symboli:"},
/* ru */ {IDGS_SYMBOL_TABLE_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SYMBOL_TABLE_COMMANDS_SV, "Kommandon for symboltabell:"},
/* tr */ {IDGS_SYMBOL_TABLE_COMMANDS_TR, "Sembol tablosu komutlary:"},
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
/* pl */ {IDGS_LABEL_PL, "label"},
/* ru */ {IDGS_LABEL_RU, ""},  /* fuzzy */
/* sv */ {IDGS_LABEL_SV, "etikett"},
/* tr */ {IDGS_LABEL_TR, "etiket"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_ADD_LABEL_DESCRIPTION,    N_("<memspace> is one of: C: 8: 9: 10: 11:\n<address>  is the address which should get the label.\n<label>    is the name of the label; it must start with a dot (\".\").\n\nMap a given address to a label.  This label can be used when entering\nassembly code and is shown during disassembly.  Additionally, it can\nbe used whenever an address must be specified.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_ADD_LABEL_DESCRIPTION_DA, "<huk.omrade>   er en af C: 8: 9: 10: eller 11:\n<adresse>      Er adressen som skal have etiketten.\n<etiket>       er navnet pa etiketten; skal starte med punktum (\".\").\n\nSat en etiket for en adresse. Etiketten kan angives nar der indtastes\nassemblerkode, og vises ved disassemblering. Desuden kan den bruges\nhvor en adresse skal angives."},
/* de */ {IDGS_MON_ADD_LABEL_DESCRIPTION_DE, "<Speicherbereich> ist aus: C: 8: 9: 10: 11:\n<Adresse>         bezeichnet die Adresse welche mit dem Bezeichner assoziert werden soll.\n<Bezeichner>      Name des Bezeichners; Muss mit einem Punkt (\".\") starten.\n\nAssoziiert einen Bezeichner mit einer Adresse. Dieser Bezeichner kann \nbei der Eingabe von Asssmblercode benutzt werden und wird auch beim\nDisassemblieren gezeigt. Daruber hinaus kann der Bezeichner uberall\ndort genutzt werden, wo eine Adresseingabe notig ist."},
/* fr */ {IDGS_MON_ADD_LABEL_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_ADD_LABEL_DESCRIPTION_HU, "A <memoria ter> ezek kozul: C: 8: 9: 10: 11:\n<cim>  amelyik cimhez a cimket rendelje.\n<cimke>    a cimke neve; ponttal kell kezdodjon (\".\").\n\nAz adott cim rendelese a cimkehez.  Ez a cimke hasznalhato assembly\nprogram beirasakor, es visszafejteskor megjelenik.  Mindig hasznalhato,\namikor valamilyen cimet kell megadni."},
/* it */ {IDGS_MON_ADD_LABEL_DESCRIPTION_IT, "<spazio di memoria> e uno tra: C: 8: 9: 10: 11:\n<indirizzo> e l'indirizzo a cui deve essere associata l'etichettal.\n<etichetta> e il nome dell'etichetta; deve iniziare con un punto (\".\").\n\nAssocia l'indirizzo specificato all'etichetta. Questa etichetta puo\nessere usata quando si inserisce codice assembly ed e mostrata\nnella disassemblazione. In aggiunta, puo essere usata ogni volta che\ndeve essere specificato un indirizzo."},
/* ko */ {IDGS_MON_ADD_LABEL_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_ADD_LABEL_DESCRIPTION_NL, "<geheugenruimte> is een van: C: 8: 9: 10: 11:\n<adres>          is het adres waaraan de label gekoppelt moet worden.\n<label>          is de naam van de label; de naam moet beginnen met een punt\n                 (\".\").\n\nKoppel een opgegeven adres aan een label. Dit label kan worden gebruikt bij\nhet invoeren van assembleer code en wordt getoont bij een disassemblering.\nTevens kan de label gebruikt worden in plaats van het adres."},
/* pl */ {IDGS_MON_ADD_LABEL_DESCRIPTION_PL, "<memspace> to jeden z: C: 8: 9: 10: 11:\n<address> to adres, pod ktory ma i��a notatka.\n<label> to nazwa notatki, musi zaczynaa sie kropk�} (\".\").\n\nMapuje dany adres pod notatke. Tej notatki mo?na u?ywaa\nprzy wprowadzaniu kodu asemblowania, a pokazywana jest\npodczas deasemblowania. Do tego mo?na jest u?ywaa\nzawsze gdy trzeba okre��lia adres."},
/* ru */ {IDGS_MON_ADD_LABEL_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_ADD_LABEL_DESCRIPTION_SV, "<minnesomrade> ar en av: C: 8: 9: 10: 11:\n<adress>       ar adressen som ska fa etiketten.\n<etikett>      ar namnet pa etiketten; maste starta med punkt (\".\").\n\nKoppla en adress till en etikett. Etiketten kan anges nar assemblerkod\nmatas in och visas vid disassemblering. I tillagg kan den anvandas\nnarhelst en adress maste anges."},
/* tr */ {IDGS_MON_ADD_LABEL_DESCRIPTION_TR, "<bellekalany> bunlardan biridir: C: 8: 9: 10: 11:\n<adres>       etiketin duracady adresi belirler.\n<etiket>      etiketin ismidir; nokta karakteriyle batlamalydyr (\".\").\n\nEtiketi verilen adrese etlettir.  Bu etiket assembly kod girilirken kullanylyr\nve disassembly syrasynda gosterilir.  Ek olarak, ne zaman bir adres\nbelirtilmesi gerekse kullanylabilir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DELETE_LABEL_DESCRIPTION,    N_("<memspace> is one of: C: 8: 9: 10: 11:\n<label>    is the name of the label; it must start with a dot (\".\").\n\nDelete a previously defined label.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_DA, "<huk.omrade>   er en af C: 8: 9: 10: eller 11:\n<etiket>       er navnet pa etiketten; skal starte med punktum (\".\").\n\nFjern en tidligere oprettet etiket."},
/* de */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_DE, "<Speicherbereich> ist aus: C: 8: 9: 10: 11:\n<Bezeichner>      Name des Bezeichners; Muss mit einem Punkt (\".\") starten.\n\nLoscht einen zuvor definierten Bezeichner."},
/* fr */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_HU, "<memoria ter> egy ezek kozul: C: 8: 9: 10: 11:\n<cimke>    a cimke neve; ponttal kell kezdodjon (\".\").\n\nElozoleg megadott cimke torlese."},
/* it */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_IT, "<spazio di memoria> e uno tra: C: 8: 9: 10: 11:\n<etichetta> e il nome dell'etichetta; deve iniziare con un punto (\".\").\n\nCancella una etichetta definita precedentemente."},
/* ko */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_NL, "<geheugenruimte> is een van: C: 8: 9: 10: 11:\n<label>          is de naam van de label; de naam moet beginnen met een\npunt (\".\").\n\nVerwijder een gekoppelde label."},
/* pl */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_PL, "<memspace> to jeden z: C: 8: 9: 10: 11:\n<label> to nazwa notatki, musi zaczynaa sie kropk�} (\".\").\n\nKasuje poprzednio zdefiniowan�} notatke."},
/* ru */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_SV, "<minnesomrade> ar en av: C: 8: 9: 10: 11:\n<etikett>      ar namnet pa etiketten; maste starta med punkt (\".\").\n\nTa bort en tidigare angiven etikett."},
/* tr */ {IDGS_MON_DELETE_LABEL_DESCRIPTION_TR, "<bellekalany> bunlardan biridir: C: 8: 9: 10: 11:\n<etiket>      etiketin ismidir; nokta karakteriyle batlamalydyr (\".\").\n\nOnceden tanymlanmyt bir etiketi sil."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_LOAD_LABELS_DESCRIPTION,    N_("Load a file containing a mapping of labels to addresses.  If no memory\nspace is specified, the default readspace is used.\n\nThe format of the file is the one written out by the `save_labels' command;\nit consists of some `add_label' commands, written one after the other.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_DA, "Indlas en fil som indeholder mapning fra labels til adresser.\nHvis der ikke angives hukommelsesomrade, anvendes det normale laseomrade.\n\nFormatet pa filen er det, som skrives af \"save_labels\"-kommandoen;\ndet bestar af \"add_label\"-kommandoer efter hinanden."},
/* de */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_DE, "Ladt eine Datei mit Zuordnung von Adressen zu Bezeichnern. Wenn kein \nSpeicherbereich angegeben wurde, wird der Standard Speicherplatz\nverwendet. Das Format der Datei wird durch das Kommande `save_lables'\ndefiniert. Es besteht aus eine Reihe von `add_label' Kommandos,\nhintereinander angeordnet."},
/* fr */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_HU, "Cimkekrol cimekre lekepezeseket tartalmazo fajl betoltese.  Ha nincs memoria\nter megadva, az alap ter lesz hasznalva.\n\nA fajl formatuma megegyezik a `save_labels' parancs altal kiirteval;\nnehany egymas utan irt `add_label' parancsbol all."},
/* it */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_IT, "Carica un file che contiente l'associazione tra le etichette e gli indirizzi.\nSe non e specificato alcuno spazio di memoria, viene usato lo spazio\ndi lettura predefinito.\n\nIl formato del file e quello dato in output dal comando `save_labels';\ne composto da alcuni comandi `add_label', scritti uno di seguito all'altro."},
/* ko */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_NL, "Laad een bestand met de koppelingen tussen labels en adressen. Als er geen\ngeheugenruimte is opgegeven zal de standaard geheugenruimte worden gebruikt.\nHet formaat van het bestand is die door het commando 'save_labels' wordt\ngeschreven; het bestaat uit een aantal 'add_label' commandos na elkaar."},
/* pl */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_PL, "Wczytuje plik zawieraj�}cy mapowanie notatek pod adresy. Je��li nie\nokre��lono zakresu pamieci, u?ywany jest domy��lny zakres pamieci.\n\nFormat pliku jest zapisywany komend�}`save_labels',\nktora sk3ada sie z komend `add_label', zapisanych jedna po drugiej."},
/* ru */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_SV, "Las in en fil som innehaller koppling fran etiketter till adresser.\nOm inget minnesomrade anges anvandas standard-lasadressen.\n\nFormatet pa filen ar samma som skrivs av \"save_labels\"-kommandot;\ndet bestar av nagra \"add_label\"-kommandon efter varandra."},
/* tr */ {IDGS_MON_LOAD_LABELS_DESCRIPTION_TR, "Etiketleri adreslerle etlettirilmit bir dosya yukleyin.  Eder bellek\nalany belirtilmemitse, varsayylan okuma alany kullanylyr.\n\nDosyanyn bicimi `save_labels' komutu ile yazylmyt olandyr;\nbu pet pete yazylmyt `add_label' komutlaryndan ibarettir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_SAVE_LABELS_DESCRIPTION,    N_("Save labels to a file.  If no memory space is specified, all of the\nlabels are saved.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_DA, "Gem etiketter til fil. Hvis der ikke angives et hukommelsesomrade\ngemmes alle etiketter."},
/* de */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_DE, "Speichere Bezeichner in eine Datei. Wenn kein Speicherbereich\nangegeben wurde, werden alle Bezeichner gespeichert."},
/* fr */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_HU, "Cimkek mentese fajlba.  Ha nincs memoria tartomany megadva, az\nosszes cimket menti."},
/* it */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_IT, "Salva le etichette su file. Se non e specificato alcuno spazio di memoria,\nvengono salvate tutte le etichette."},
/* ko */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_NL, "Sla de labels op in een bestand. Als er geen geheugenruimte is opgegeven\nworden alle labels opgeslagen."},
/* pl */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_PL, "Zapisuje notatki do pliku. Je��li nie okre��lono obszaru pamieci,\nzapisywanie s�} wszystkie notatki."},
/* ru */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_SV, "Spara etiketter till en fil. Om inget minnesomrade anges sparas alla\netiketterna."},
/* tr */ {IDGS_MON_SAVE_LABELS_DESCRIPTION_TR, "Etiketleri bir dosyaya kaydet.  Eder bellek alany belirtilmemitse, tum\netiketler kaydedilir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_SHOW_LABELS_DESCRIPTION,    N_("Display current label mappings.  If no memory space is specified, show\nall labels.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_DA, "Vis aktuelle etiketter. Hvis der ikke angives et hukommelsesomrade vises\nalle etiketter."},
/* de */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_DE, "Zeige aktuelle Bezeichner Zuordnungen. Wenn kein Speicherbereich angegeben\nwurde, werden alle Bezeichner gezeigt."},
/* fr */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_HU, "Az aktualis cimke lekepezesek mutatasa.  Ha nincs a memoria ter megadva, az\nosszeset mutatja."},
/* it */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_IT, "Mostra l'associazione delle etichette correnti. Se non e specificato alcun\nspazio di memoria, verranno mostrate tutte le etichette."},
/* ko */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_NL, "Toon huidige label koppelingen. Als er geen geheugenruimte is opgegeven\nworden all labels getoont."},
/* pl */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_PL, "Pokazuje obecne mapowania notatek. Je��li nie okre��lono obszaru pamieci,\npokazuje wszystkie notatki."},
/* ru */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_SV, "Visar aktuella etiketter. Om inget minnesomrade anges visas alla\netiketter."},
/* tr */ {IDGS_MON_SHOW_LABELS_DESCRIPTION_TR, "Gecerli etiket etletmelerini goruntule.  Eder bellek alany belirtilmemitse,\ntum etiketleri goster."},
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
/* pl */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_PL, "Asembler i polecenia pamieci:"},
/* ru */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_SV, "Assembler- och minneskommandon:"},
/* tr */ {IDGS_ASSEMBLER_AND_MEMORY_COMMANDS_TR, "Assembler ve bellek komutlary:"},
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
/* pl */ {IDGS_DATA_LIST_PL, "data_list"},
/* ru */ {IDGS_DATA_LIST_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DATA_LIST_SV, "datalista"},
/* tr */ {IDGS_DATA_LIST_TR, "veri_listesi"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_WRITE_DESCRIPTION,    N_("Write the specified data at `address'.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_WRITE_DESCRIPTION_DA, "Gem angivne data pa \"adresse\"."},
/* de */ {IDGS_MON_WRITE_DESCRIPTION_DE, "Schreibe das angegebene Datum auf `Adresse'."},
/* fr */ {IDGS_MON_WRITE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_WRITE_DESCRIPTION_HU, "A megadott adat `cim' helyre irasa."},
/* it */ {IDGS_MON_WRITE_DESCRIPTION_IT, "Scrive il dato specificato all'indirizzo."},
/* ko */ {IDGS_MON_WRITE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_WRITE_DESCRIPTION_NL, "Schrijf de opgegevem data op `adres'."},
/* pl */ {IDGS_MON_WRITE_DESCRIPTION_PL, "Zapisuje okre��lone dane w 'adresie'."},
/* ru */ {IDGS_MON_WRITE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_WRITE_DESCRIPTION_SV, "Skriv angiven data pa \"adress\"."},
/* tr */ {IDGS_MON_WRITE_DESCRIPTION_TR, "`adres' bolumunde belirlenmit bir veri yaz."},
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
/* pl */ {IDGS_INSTRUCTION_PL, "instruction"},
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
/* hu */ {IDGS_MON_ASSEMBLE_DESCRIPTION_HU, "Utasitasok forditasa a megadott cimre. Ha csak egy utasitas\nvan, fordito modba lep (ures sort kell beirni a kilepeshez)."},
/* it */ {IDGS_MON_ASSEMBLE_DESCRIPTION_IT, "Assembla le istruzioni a partire dall'indirizzo specificato. Se solo una\nistruzione e specificata, entra in modalita assembly (inserire una\nlinea vuota per uscire da questa modalita)."},
/* ko */ {IDGS_MON_ASSEMBLE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_ASSEMBLE_DESCRIPTION_NL, "Assembleer instructies naar het opgegeven adres. Als er alleen een instructie\nis opgegeven dan wordt de assembleer modus ingeschakelt (geef een lege regel\nin om de assembleer modus te verlaten)."},
/* pl */ {IDGS_MON_ASSEMBLE_DESCRIPTION_PL, "Assembluje instrukcje pod podanym adresem. Je��li podano tylko\njedn�} instrukcje, wchodzi w tryb asemblowania (pusta linia\nwychodzi z trybu asemblowania)."},
/* ru */ {IDGS_MON_ASSEMBLE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_ASSEMBLE_DESCRIPTION_SV, "Assemblera instruktioner till angiven adress. Om endast en\ninstruktion angavs, aktivera assemblerlage (mata in en tom rad\nfor att avsluta assemblerlaget)."},
/* tr */ {IDGS_MON_ASSEMBLE_DESCRIPTION_TR, "Komutlary belirlenmit adrese cevir.  Eder yalnyzca bir\nkomut belirlenmitse, assembly moduna gir (assembly modundan cykmak icin\nbot bir satyr girin)."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_ADDRESS_RANGE,    N_("address_range")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ADDRESS_RANGE_DA, "adresseomrade"},
/* de */ {IDGS_ADDRESS_RANGE_DE, "Adressbereich"},
/* fr */ {IDGS_ADDRESS_RANGE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ADDRESS_RANGE_HU, ""},  /* fuzzy */
/* it */ {IDGS_ADDRESS_RANGE_IT, "intervallo indirizzi"},
/* ko */ {IDGS_ADDRESS_RANGE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ADDRESS_RANGE_NL, "adres_bereik"},
/* pl */ {IDGS_ADDRESS_RANGE_PL, "address_range"},
/* ru */ {IDGS_ADDRESS_RANGE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ADDRESS_RANGE_SV, "adressomrade"},
/* tr */ {IDGS_ADDRESS_RANGE_TR, ""},  /* fuzzy */
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_COMPARE_DESCRIPTION,    N_("Compare memory from the source specified by the address range to the\ndestination specified by the address.  The regions may overlap.  Any\nvalues that miscompare are displayed using the default displaytype.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_COMPARE_DESCRIPTION_DA, "Sammenlign hukommelse fra kilden, angivet ved adresseomradet med\nmalet, angivet ved adresse. Omraderne kan overlappe. Alle vardier\nsom er forskellige vil blive vist med standard visning."},
/* de */ {IDGS_MON_COMPARE_DESCRIPTION_DE, "Vergleiche angegebenen Adressbereich mit der Zieladresse.\nDie Bereiche konnen uberlappen. Ungleiche Werte werden mit dem\nStandardanzeigetyp gezeigt."},
/* fr */ {IDGS_MON_COMPARE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_COMPARE_DESCRIPTION_HU, "A forras memoriatartomany osszehasonlitasa a cellal megadott\nmemoriatartomannyal. A tartomanyok atfedese megengedett.  Minden\nmeg nem egyezo erteket kiir az alap adat tipussal."},
/* it */ {IDGS_MON_COMPARE_DESCRIPTION_IT, "Confronta la memoria della sorgente specificata dall'intervallo di\nindirizzi con la destinazione specificata dall'indirizzo. Le regioni possono\nsovrapporsi. Qualsiasi valore che non corrisponde e visualizzato\nutilizzando il tipo di dato predefinito."},
/* ko */ {IDGS_MON_COMPARE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_COMPARE_DESCRIPTION_NL, "Vergelijk geheugen van de bron opgegeven door de adres reeks met het doel\nopgegeven door het adres. De reeksen mogen overlappen. De data die niet\ngelijk is zal worden getoont volgens de huidige toon soort."},
/* pl */ {IDGS_MON_COMPARE_DESCRIPTION_PL, "Porownuje pamiea z podanego zakresu adresow z podanym adresem.\nRejony mog�} sie pokrywaa. Wszystkie niepasuj�}ce warto��ci s�} pokazane\ndomy��lnym typem danych."},
/* ru */ {IDGS_MON_COMPARE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_COMPARE_DESCRIPTION_SV, "Jamfor minne fran kallan som anges av adressomradet mot destinationen\nsom anges av adressen. Omradena kan vara overlappande. Alla varden\nsom skiljer sig vid jamforelsen visas med standardvisningssattet."},
/* tr */ {IDGS_MON_COMPARE_DESCRIPTION_TR, "Belledi adresle belirtilen kaynaktan adresle belirtilen hedefin bulundudu\naralykta kartylattyr.  Bolgeler belki ust uste binebilir.  Uyutmayan\nherhangi bir deder varsayylan goruntuleme tipine badly olarak goruntulenir."},
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
/* pl */ {IDGS_CHECKNUM_PL, "checknum"},
/* ru */ {IDGS_CHECKNUM_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CHECKNUM_SV, "kontrollnr"},
/* tr */ {IDGS_CHECKNUM_TR, "kontrolnumarasy"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DELETE_DESCRIPTION,    N_("Delete checkpoint `checknum'.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DELETE_DESCRIPTION_DA, "Slet checkpoint \"checknum\"."},
/* de */ {IDGS_MON_DELETE_DESCRIPTION_DE, "Losche Checkpoint `Checknummer'."},
/* fr */ {IDGS_MON_DELETE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DELETE_DESCRIPTION_HU, "`ell_pont_szam' ellenorzesi pont torlese."},
/* it */ {IDGS_MON_DELETE_DESCRIPTION_IT, "Cancella il punto di controllo `checknum'."},
/* ko */ {IDGS_MON_DELETE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DELETE_DESCRIPTION_NL, "Verwijder checkpunt `checknum'."},
/* pl */ {IDGS_MON_DELETE_DESCRIPTION_PL, "Usun punkt kontrolny `checknum'."},
/* ru */ {IDGS_MON_DELETE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DELETE_DESCRIPTION_SV, "Ta bort kontrollpunkt \"kontrollnr\"."},
/* tr */ {IDGS_MON_DELETE_DESCRIPTION_TR, "`kontrolnumarasy' kontrol noktasyny sil."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DISASS_DESCRIPTION,    N_("Disassemble instructions.  If two addresses are specified, they are\nused as a start and end address.  If only one is specified, it is\ntreated as the start address and a default number of instructions are\ndisassembled.  If no addresses are specified, a default number of\ninstructions are disassembled from the dot address.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DISASS_DESCRIPTION_DA, "Disassembler instruktioner. Hvis der angives to adresser anvendes disse\nsom start- og slutadresse. Angives kun en adresse bruges denne som startadresse\nog et standard antal instruktioner disassembleres. Hvis ingen adresse\nangives disassembleres et standard antal instruktioner fra den aktuelle\nadresse."},
/* de */ {IDGS_MON_DISASS_DESCRIPTION_DE, "Disassembliere Instruktionen. Wenn zwei Adressen angegeben werden,\nwerden diese als Start- und Zieladresse interpretiert. Wenn nur eine\nAdress angegeben wird, wird diese asl Startadresse interpretiert und\ndie Standardanzahl an Instruktionen werden disassembliert. Wenn keine\nAdresse angegeben wird, wird von der aktuellen Adresse disassembliert."},
/* fr */ {IDGS_MON_DISASS_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DISASS_DESCRIPTION_HU, "Utasitasok visszafejtese. Ha ket cim van megadva, elso es utolso\ncimkent ertelmezi oket. Ha csak egy, akkor elso cimkent, es az alap\nszamu utasitas kerul visszafejtesre. Ha nincs cim megadva, az aktualis\ncimtol kezdi a visszafejtest, es a szokasos szamu utasitast ir ki."},
/* it */ {IDGS_MON_DISASS_DESCRIPTION_IT, "Disassembla le istruzioni. Se sono specificati due indirizzi, questi\nsono utilizzati come indirizzo di inizio e fine. Se ne viene specificato\nsolo uno, e usato come indirizzo di partenza e viene disassemblato\nil numero di istruzioni predefinito. Se non viene specificato nessun\nindirizzo, viene disassemblato il numero di istruzioni predefinito\ndall'indirizzo dot."},
/* ko */ {IDGS_MON_DISASS_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DISASS_DESCRIPTION_NL, "Disassembleer instructies. Als er twee adressen zijn opgegeven dan worden\ndeze gebruikt als een start en eind adres. Als er maar een adres is\nopgegeven dan wordt deze gebruikt als het start adres en een standaard\naantal instructies zal worden gedisassembleerd. Als er geen adressen zijn\nopgegeven dan wordt een standaard aantal instructies gedisassembleerd vanaf\nhet huidige adres."},
/* pl */ {IDGS_MON_DISASS_DESCRIPTION_PL, "Deasembluje instrukcje. Je��li podano dwa adresy, u?ywane s�} jako\nadres pocz�}tkowy i koncowy. Je��li podano tylko jeden, jest u?ywany\njako adres pocz�}tkowy i deasemblowana jest domy��lna liczba instrukcji\nz adresu dot."},
/* ru */ {IDGS_MON_DISASS_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DISASS_DESCRIPTION_SV, "Disassemblera instruktioner. Om tva adresser anges anvands de som\nstart- och slutadress. Om endast en anges anvands den som startadress\noch ett standardantal instruktioner disassembleras. Om ingen adress\nanges disassembleras ett standardantal instruktioner fran punktadressen."},
/* tr */ {IDGS_MON_DISASS_DESCRIPTION_TR, "Komutlary disassemble et.  Eder iki adres girildiyse, bunlar batlangyc\nve bitit adresleri olarak kullanylyr.  Eder tek adres girildiyse, bu\nadres batlangyc adresi olarak kabul edilir ve varsayylan sayyda komutlar\ndisassemble edilir.  Eder hic adres girilmediyse, varsayylan sayyda\nkomutlar nokta batlangyc adresinden itibaren disassemble edilir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_FILL_DESCRIPTION,    N_("Fill memory in the specified address range with the data in\n<data_list>.  If the size of the address range is greater than the size\nof the data_list, the data_list is repeated.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_FILL_DESCRIPTION_DA, "Fyld hukommelsen i det angivne adresseomrade med data fra <dataliste>.\nHvis storrelsen pa adresseomradet er storre end storrelsen af dataliste\ngentages indholdet i dataliste."},
/* de */ {IDGS_MON_FILL_DESCRIPTION_DE, "Fulle den angegebenen Adressbereich mit den Daten aus <Datenliste>.\nWenn die Grose des Adressbereichs groser als <Datenliste> ist, werden\ndie Daten wiederholt."},
/* fr */ {IDGS_MON_FILL_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_FILL_DESCRIPTION_HU, "A memoria kitoltese az <adat_lista> parameterben megadott adatokkal.\nHa a cimtartomany nagyobb, mint a lista, ismetelni fogja azt."},
/* it */ {IDGS_MON_FILL_DESCRIPTION_IT, "Riempe la memoria nell'intervallo di indirizzi specificato con i dati\npresenti in <lista di dati>. Se la dimensione dell'intervallo e maggiore\ndella dimensione della lista di dati, la lista di dati e ripetuta."},
/* ko */ {IDGS_MON_FILL_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_FILL_DESCRIPTION_NL, "Vul het geheugen van de opgegeven adres reeks op met de data in <data_lijst>.\nAls de grootte van de adres reeks groter is dan de grootte van de data_lijst\ndan zal de data_lijst worder herhaald."},
/* pl */ {IDGS_MON_FILL_DESCRIPTION_PL, "Wype3nia pamiea w danym zakresie adresow danymi z <lista_danych>.\nJe��li wielko��a zakresu adresow jest wieksza ni? wielko��a listy_danych,\nlista_danych jest powtarzana."},
/* ru */ {IDGS_MON_FILL_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_FILL_DESCRIPTION_SV, "Fyll minnet i det angivna omradet med data i <datalista>.\nOm storleken pa adressomradet ar storre an storleken pa datalistan\nrepeteras innehallet i datalistan."},
/* tr */ {IDGS_MON_FILL_DESCRIPTION_TR, "<veri_listesi>'nde bulunan verilerle belirtilen bellek aralydyny doldur.\nEder verilen adres aralydy veri_listesi'nden buyukse, veri_listesi'nde\nyer alan veriler tekrar ettirilir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_HUNT_DESCRIPTION,    N_("Hunt memory in the specified address range for the data in\n<data_list>.  If the data is found, the starting address of the match\nis displayed.  The entire range is searched for all possible matches.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_HUNT_DESCRIPTION_DA, "Sog i hukommelsen i det angivne dataomrade efter <dataliste>.\nOm data findes vises startadressen for matchet. Hele\nomradet gennemsoges for at finde alle mulige match."},
/* de */ {IDGS_MON_HUNT_DESCRIPTION_DE, "Suche in angebenen Adressbereich nach <Datenliste>. Wenn die Daten gefunden\nwurden, wird die Startadresse gezeigt. Der komplette Bereich wird alle\nVorkommnisse von <Datenliste> untersucht."},
/* fr */ {IDGS_MON_HUNT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_HUNT_DESCRIPTION_HU, "Az <adat_lista> adat keresese a memoriaban. Ha megtalalja a sorozatot,\na kezdocimet kiirja. Az egesz tartomanyt vegignezi az osszes lehetseges\ntalalat felfedezesehez."},
/* it */ {IDGS_MON_HUNT_DESCRIPTION_IT, "Cerca nell'intervallo di indirizzi specificato i dati nella <lista di dati>.\nSe il dato e trovato, viene visualizzato l'indirizzo iniziale della\ncorrispondenza. Tutto l'intervallo viene ricercato per tutte le possibili\ncorrispondenze."},
/* ko */ {IDGS_MON_HUNT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_HUNT_DESCRIPTION_NL, "Zoek het adres bereik voor de data in <data_lijst>. Als de data is gevonden\ndan wordt het start adres getoont. Er zal door de hele reeks worden gezocht."},
/* pl */ {IDGS_MON_HUNT_DESCRIPTION_PL, "Szukaj danych z <lista_danych> w pamieci w podanym zakresie\nadresow. Je��li znaleziono dane, pokazany jest pocz�}tkowy adres\ntrafienia. Ca3y zakres jest przeszukiwany dla wszystkich mo?liwych	rafien."},
/* ru */ {IDGS_MON_HUNT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_HUNT_DESCRIPTION_SV, "Sok i minnet i det angivna omradet med data efter <datalista>.\nOm data patraffas visas startadressen for traffen. Hela\nomradet genomsoks for att hitta alla mojliga traffar."},
/* tr */ {IDGS_MON_HUNT_DESCRIPTION_TR, "<veri_listesi>'nde bulunan veriler icin belirtilen bellek aralydynda\narama yap.  Eder veri bulunursa, etleten adres aralydynyn batlangyc\nadresi goruntulenir.  Tum alan mumkun olan etletmeler icin aranacaktyr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_ADDRESS_OPT_RANGE,    N_("address_opt_range")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_ADDRESS_OPT_RANGE_DA, "adresse_evt_omrade"},
/* de */ {IDGS_ADDRESS_OPT_RANGE_DE, "Optionaler Adressbereich"},
/* fr */ {IDGS_ADDRESS_OPT_RANGE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_ADDRESS_OPT_RANGE_HU, ""},  /* fuzzy */
/* it */ {IDGS_ADDRESS_OPT_RANGE_IT, "intervallo di indirizzi opzionale"},
/* ko */ {IDGS_ADDRESS_OPT_RANGE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_ADDRESS_OPT_RANGE_NL, "optionele_adres_bereik"},
/* pl */ {IDGS_ADDRESS_OPT_RANGE_PL, "address_opt_range"},
/* ru */ {IDGS_ADDRESS_OPT_RANGE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_ADDRESS_OPT_RANGE_SV, "adress_ev_omrade"},
/* tr */ {IDGS_ADDRESS_OPT_RANGE_TR, "opsiyonel_adres_aralydy"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_I_DESCRIPTION,    N_("Display memory contents as PETSCII text.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_I_DESCRIPTION_DA, "Vis hukommelsesindhold som PETSCII-text."},
/* de */ {IDGS_MON_I_DESCRIPTION_DE, "Zeige Speicherinhalt als PETSCII Text."},
/* fr */ {IDGS_MON_I_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_I_DESCRIPTION_HU, "Memoria tartalom mutatasa PETSCII szovegkent."},
/* it */ {IDGS_MON_I_DESCRIPTION_IT, "Mostra il contenuto della memoria come testo PETSCII."},
/* ko */ {IDGS_MON_I_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_I_DESCRIPTION_NL, "Toon geheugen inhoud als PETSCII tekst."},
/* pl */ {IDGS_MON_I_DESCRIPTION_PL, "Poka? zawarto��a pamieci jako tekst PETSCII."},
/* ru */ {IDGS_MON_I_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_I_DESCRIPTION_SV, "Visa minnesinnehall som PETSCII-text."},
/* tr */ {IDGS_MON_I_DESCRIPTION_TR, "Bellek iceridini PETSCII yazy biciminde goruntule."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_II_DESCRIPTION,    N_("Display memory contents as screen code text.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_II_DESCRIPTION_DA, "Vis hukommelses-indhold som skarm-koder."},
/* de */ {IDGS_MON_II_DESCRIPTION_DE, "Zeige Speicherinhalt als Bildschirmcode Text."},
/* fr */ {IDGS_MON_II_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_II_DESCRIPTION_HU, "Memoria tartalom megjelenitese kepernyo kod szovegkent."},
/* it */ {IDGS_MON_II_DESCRIPTION_IT, "Mostra il contenuto della memoria come testo screen code."},
/* ko */ {IDGS_MON_II_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_II_DESCRIPTION_NL, "Toon geheugen inhoud als scherm code tekst."},
/* pl */ {IDGS_MON_II_DESCRIPTION_PL, "Poka? zawarto��a pamieci jako tekst screen code."},
/* ru */ {IDGS_MON_II_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_II_DESCRIPTION_SV, "Visa minnesinnehall som skarmkodstext."},
/* tr */ {IDGS_MON_II_DESCRIPTION_TR, "Bellek iceridini ekran kodu yazy biciminde goruntule."},
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
/* pl */ {IDGS_DATA_TYPE_PL, "data_type"},
/* ru */ {IDGS_DATA_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DATA_TYPE_SV, "datatyp"},
/* tr */ {IDGS_DATA_TYPE_TR, "veri_tipi"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MEM_DESCRIPTION,    N_("Display the contents of memory.  If no datatype is given, the default\nis used.  If only one address is specified, the length of data\ndisplayed is based on the datatype.  If no addresses are given, the\n'dot' address is used.\nPlease note: due to the ambiguous meaning of 'b' and 'd' these data-\ntypes must be given in uppercase!")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MEM_DESCRIPTION_DA, "Vis hukommelsens indhold. Hvis datatype ikke angives, bruges standard.\nHvis kun en adresse angives, justeres langden pa visningen baseret\npa datatypen. Hvis der ikke angives nogen adresse anvendes \"punktum\"-adressen.\nNote: Pa grund af tvetydighed for 'b' og 'd' skal disse datatyper\nangives med store bogstaver!"},
/* de */ {IDGS_MON_MEM_DESCRIPTION_DE, "Zeige Speicherinhalt. Wenn kein Datentyp angegeben wurde, wird der\nStandarddatentyp verwendet. Wenn nur eine Adresse angegeben wird, hangt\ndie Lange der Daten vom Datentyp ab. Wenn keine Adresse angeben wurde, \nwird die aktuelle Adresse verwendet.\nAchtung: Wegen der Mehrdeutigkeit von `b' und `d', mussen die\nDatentypen in Grosbuchstaben angegeben werden!"},
/* fr */ {IDGS_MON_MEM_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MEM_DESCRIPTION_HU, ""},  /* fuzzy */
/* it */ {IDGS_MON_MEM_DESCRIPTION_IT, "Mostra il contenuto della memoria. Se non e specificato alcun tipo di\ndato, verra utilizzato quello predefinito. Se e specificato solo un indirizzo,\nla lunghezza del dato visualizzato e basata sul tipo. Se non e specificato\nnessun indirizzo, varra utilizzato l'indirizzo 'dot'.Nota bene: a causa del significato ambiguo di 'b' e 'd' questi tipi di dati\ndevono essere inseriti in maiuscolo!"},
/* ko */ {IDGS_MON_MEM_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MEM_DESCRIPTION_NL, "Toon de geheugen inhoud. Als er geen datasoort is opgegeven dan zal de standaard\nworden gebruikt. Als er maar een adres is opgegeven dan zal de lengte van de\ngetoonde data gebaseerd worden op de datasoort. Als er geen adres is opgegeven\ndan zal het huidige adres worden gebruikt. Door de onduidelijke betekenis \nvan 'b' en 'd' moeten deze datasoorten opgegeven worden in hoofdletters!"},
/* pl */ {IDGS_MON_MEM_DESCRIPTION_PL, "Pokazuje zawarto��a pamieci. Je��li nie ustalono typu danych, jest\nu?ywany domy��lny. Je��li okre��lono tylko jeden adres, d3ugo��a\npokazanych danych zale?y od ich typu. Je��li nie podano adresu,\nu?ywany jest adres 'kropka'. Uwaga: w zwi�}zku z wieloznaczno��ci�} 'b' i 'd', te typy danych\nnale?y podaa wielk�} liter�}!"},
/* ru */ {IDGS_MON_MEM_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MEM_DESCRIPTION_SV, "Visa minnets innehall. Om ingen datatyp anges, anvands standard.\nOm endast en adress anges, justeras langden pa visad data baserat\npa datatypen. Om ingen adress anges anvands \"punkt\"-adressen.\nObservera: pa grund av tvetydig betydelse av \"b\" och \"d\" maste dessa\ndatatyper anges med stora bokstaver!"},
/* tr */ {IDGS_MON_MEM_DESCRIPTION_TR, "Bellek iceridini goster.  Eder veri tipi girilmemitse, varsayylan\nkullanylyr.  Yalnyzca bir adres belirtilmitse, gosterilen verinin\nuzunludu veri tipine badlydyr.  Eder hic adres girilmemitse, 'nokta'\nadresi kullanylyr.\nLutfen dikkat: 'b' ve 'd'nin karmatyk anlamlaryndan oturu bu veri\ntipleri buyukharf olarak verilmelidir!"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MEMCHAR_DESCRIPTION,    N_("Display the contents of memory as character data.  If only one address\nis specified, only one character is displayed.  If no addresses are\ngiven, the ``dot'' address is used.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MEMCHAR_DESCRIPTION_DA, "Vis hukommelsens indhold som tegndata. Hvis kun en adresse\nangives, vises kun et tegn. Hvis ingen adresse angives benyttes\n\"punktum\"-adressen."},
/* de */ {IDGS_MON_MEMCHAR_DESCRIPTION_DE, "Zeige den Inhalt von Speicher als Character Daten. Wenn nur eine Adresse\nangegeben wurde, wird nur ein Zeichen gezeigt. Wenn keine Adresse angegeben\nwurde, wird die aktuelle Adresse verwendet."},
/* fr */ {IDGS_MON_MEMCHAR_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MEMCHAR_DESCRIPTION_HU, "A memoria tartalmanak megjelenitese karakter grafikakent.  Ha csak egy cim\nadott, egyetlen karakter rajzolodik ki.  Ha nincs cim megadva,\na ``pont'' cimet hasznalja."},
/* it */ {IDGS_MON_MEMCHAR_DESCRIPTION_IT, "Mosta il contenuto della memoria come dati caratteri. Se e specificato\nsolo un indirizzo, verra visualizzato solo un carattere. Se non e\nspecificato alcun indirizzo, varra utilizzato l'indirizzo ``dot'' ."},
/* ko */ {IDGS_MON_MEMCHAR_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MEMCHAR_DESCRIPTION_NL, "Toon de geheugen inhoud als karakter data. Als er maar een adres is\nopgegeven dan zal er maar een karakter worden weergegeven. Als er geen\nadres is opgegeven dan zal het huidige adres gebruikt worden."},
/* pl */ {IDGS_MON_MEMCHAR_DESCRIPTION_PL, "Poka? zawarto��a pamieci jako dane znakowe. Je��li podano tylko jeden\nadres, pokazany jest tylko jeden znak. Je��li nie podano adresow, u?yty\njest adres 'kropka'."},
/* ru */ {IDGS_MON_MEMCHAR_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MEMCHAR_DESCRIPTION_SV, "Visa minnets innehall som teckendata. Om endast en adress\nanges, visas endast ett tecken. Om ingen adress anges anvands\n\"punkt\"-adressen."},
/* tr */ {IDGS_MON_MEMCHAR_DESCRIPTION_TR, "Bellek iceridini karakter verisi olarak goster.  Yalnyzca bir adres\nbelirtilmitse, yalnyzca tek karakter goruntulenir.  Eder hic adres\ngirilmemitse, 'nokta' adresi kullanylyr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_FORMAT,    N_("Format")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_FORMAT_DA, "Format"},
/* de */ {IDGS_FORMAT_DE, "Format"},
/* fr */ {IDGS_FORMAT_FR, "Format"},
/* hu */ {IDGS_FORMAT_HU, "Formatum"},
/* it */ {IDGS_FORMAT_IT, "Formato"},
/* ko */ {IDGS_FORMAT_KO, "�}�C?o 1a?A"},
/* nl */ {IDGS_FORMAT_NL, "Formaat"},
/* pl */ {IDGS_FORMAT_PL, "Format"},
/* ru */ {IDGS_FORMAT_RU, ""},  /* fuzzy */
/* sv */ {IDGS_FORMAT_SV, "Format"},
/* tr */ {IDGS_FORMAT_TR, "Bicim"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION,    N_("Save the memmap as a picture. Format is:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_DA, "Gem memmap som billede. Format:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* de */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_DE, "Speicher die memmap als Bilddaten. Formate:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* fr */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_HU, "Memoria terkep mentese kepkent. A formatum:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* it */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_IT, "Salva la mappa di memoria come immagine. I Formati sono:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* ko */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_NL, "Sla de memmap op als een afbeelding. Formaat is:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* pl */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_PL, "Zapisz mape pamieci jako obrazek. Format:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* ru */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_SV, "Sparar minneskartan som en bild. Format:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* tr */ {IDGS_MON_MEMMAPSAVE_DESCRIPTION_TR, "Bellek haritasyny resim olarak kaydet. Bicim:\n0 = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
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
/* pl */ {IDGS_MASK_PL, "mask"},
/* ru */ {IDGS_MASK_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MASK_SV, "mask"},
/* tr */ {IDGS_MASK_TR, "maske"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION,    N_("Show the memmap. The mask can be specified to show only those\nlocations with accesses of certain type(s). The mask is a number\nwith the bits \"ioRWXrwx\", where RWX are for ROM and rwx for RAM.\nOptionally, an address range can be specified.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_DA, "Vis memmap. Masken kan angives for kun at vise de celler, som\ner tilgaet med valgte typer tilgang. Masken er et tal med\nbitsne \"ioRWXrwx\", hvor RWX er ROM og rwx er RAM.\nEt adresseomrade kan eventuelt angives."},
/* de */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_DE, "Zeige die memmap. Die Maske kann so definiert werden, dass nur jene Orte\nmit Zugriff auf spezifische Typ(en) gezeigt werden. Die Maske ist eine Nummer\nmit Bits \"ioRWXrwx\", wobei RWX fur ROM und rwx fur RAM steht.\nOptional kann ein Adressbereich definiert werden."},
/* fr */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_HU, "A memoria terkep mutatasa. A maszk ugy allithato, hogy csak azokat a\nhelyeket mutassa, amelyek a megadott eleressel rendelkeznek. A maszk\negy szam az \"ioRWXrwx\" bitekkel, ahol az RWX a ROM-ra, az rwx a RAM-ra\nvonatkozik. Tetszes szerint egy cimtartomany is megadhato."},
/* it */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_IT, "Mostra la mappa di memoria. La maschera puo essere specificata per\nmostrare solo quelle locazioni con accessi un un certo tipo. La maschera\ne un numero con i bit \"ioRWXrwx\", dove RWX sono per la ROM e\nrwx per la RAM.\nOpzionalmente, puo essere specificato anche un intervallo di indirizzi."},
/* ko */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_NL, "Toon de memmap. Het masker kan worden opgegeven zodat er alleen de\nadressen met toegrijpingen van een bepaalde soort(en) zal worden getoond.\nHet masker is een nummer met de bits \"ioRWXrwx\", waar RWX is voor ROM,\nen rwx voor RAM. Er kan optioneel een adres bereik worden opgegeven."},
/* pl */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_PL, "Pokazuje mape pamieci. By pokazaa tylko obszar dostepow danego typu,\nmo?na okre��lia maske. Maska to numer zawieraj�}cy bity \"ioRWXrwx\", gdzie\nRWX to ROM, a rwx to RAM. Opcjonalnie mo?na okre��lia zakres adresow."},
/* ru */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_SV, "Visa minneskartan. Masken kan anges for att endast visa de\nceller som galler specifik(a) typ(er). Masken ar ett tal\nmed bitarna \"ioRWXrwx\", dar RWX ar for ROM och rwx ar for\nRAM. Ett minnesomrade kan eventuellt anges."},
/* tr */ {IDGS_MON_MEMMAPSHOW_DESCRIPTION_TR, "Bellek haritasyny goster. Maske, yalnyzca belirli tiplerce eritilebilen\nkonumlarda belirtilebilir. Maske \"ioRWXrwx\" bitlerinden olutan bir\nsayydyr. RWX ROM'u, rwx RAM'i ifade eder. Opsiyonel olarak bir adres\naralydy belirtilebilir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MEMMAPZAP_DESCRIPTION,    N_("Clear the memmap.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_DA, "Nulstil memmap."},
/* de */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_DE, "Losche die memmap."},
/* fr */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_HU, "A memoria terkep torlese."},
/* it */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_IT, "Cancella la mappa di meoria."},
/* ko */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_NL, "Veeg de memmap schoon."},
/* pl */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_PL, "Wyczy��a mape pamieci."},
/* ru */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_SV, "Tom minneskartan."},
/* tr */ {IDGS_MON_MEMMAPZAP_DESCRIPTION_TR, "Bellek haritasyny temizle."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MEMSPRITE_DESCRIPTION,    N_("Display the contents of memory as sprite data.  If only one address is\nspecified, only one sprite is displayed.  If no addresses are given,\nthe ``dot'' address is used.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MEMSPRITE_DESCRIPTION_DA, "Vis hukommelsens indhold som spritedata. Hvis kun en adresse\nangives, vises kun en sprite. Hvis ingen adresse angives bruges\n\"punktum\"-adressen."},
/* de */ {IDGS_MON_MEMSPRITE_DESCRIPTION_DE, "Zeige den Speicher als Sprite Daten. Wenn nur eine Adresse angegeben wurde,\nwird nur ein Sprite gezeitg. Wenn keine Adresse angegeben wurde, wird\ndie aktuelle Adresse verwendet."},
/* fr */ {IDGS_MON_MEMSPRITE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MEMSPRITE_DESCRIPTION_HU, "A memoria tartalmanak megjelenitese sprite adatkene. Ha csak egy cim\nvan megadva, egyetlen sprite-ot mutat.  Ha egyaltalan nincs cim megadva,\naz aktualis cimet hasznalja."},
/* it */ {IDGS_MON_MEMSPRITE_DESCRIPTION_IT, "Mostra il contenuto della memoria come dati sprite. Se e specificato\nsolo un indirizzo, verra mostrato solo uno sprite. Se non e specificato\nalcun indirizzo, varra utilizzato l'indirizzo ``dot''."},
/* ko */ {IDGS_MON_MEMSPRITE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MEMSPRITE_DESCRIPTION_NL, "Toon de geheugen inhoud als sprite data. Als er maar een adres is opgegeven\ndan zal er maar een sprite worden getoond. Als er geen adres is opgegeven\ndan zal het huidige adres worden gebruikt."},
/* pl */ {IDGS_MON_MEMSPRITE_DESCRIPTION_PL, "Pokazuje zawarto��a pamieci jako dane duszkow. Je��li podano tylko jeden\nadres, pokazywany jest tylko jeden duszek. Je��li nie podano adresu,\nu?ywany jest adres ``dot'."},
/* ru */ {IDGS_MON_MEMSPRITE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MEMSPRITE_DESCRIPTION_SV, "Visa minnets innehall som spritedata. Om endast en adress\nanges, visas endast en sprite. Om ingen adress anges anvands\n\"punkt\"-adressen."},
/* tr */ {IDGS_MON_MEMSPRITE_DESCRIPTION_TR, "Bellek iceridini yaratyk verisi olarak goster.  Yalnyzca bir adres\nbelirtilmitse, yalnyzca tek yaratyk goruntulenir.  Eder hic adres\ngirilmemitse, 'nokta' adresi kullanylyr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_MOVE_DESCRIPTION,    N_("Move memory from the source specified by the address range to\nthe destination specified by the address.  The regions may overlap.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_MOVE_DESCRIPTION_DA, "Kopier data fra kilden angivet af hukommelsesomradet til destinationen\nsom angives af adressen. Regionerne kan overlappe."},
/* de */ {IDGS_MON_MOVE_DESCRIPTION_DE, "Verschiebe Speicher von Startadresse definiert durch den Adressbereich zum\nZielbereich definiert durch die Adresse. Die Bereiche konnen uberlappend sein."},
/* fr */ {IDGS_MON_MOVE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_MOVE_DESCRIPTION_HU, "Memoria masolasa a forras teruletrol a cel cim altal meghatarozott\nteruletre. A tartomanyok atfedese megengedett."},
/* it */ {IDGS_MON_MOVE_DESCRIPTION_IT, "Sposta la memoria dalla sorgente specificata dall'intervallo di indirizzi\nalla destinazione specificata dall'indirizzo. Le regioni possono\nsovrapporsi."},
/* ko */ {IDGS_MON_MOVE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_MOVE_DESCRIPTION_NL, "Verplaats data van de opgegeven bron adres reeks naar het doel adres. De\nreeksen kunnen overlappen."},
/* pl */ {IDGS_MON_MOVE_DESCRIPTION_PL, "Przesuwa pamiea z okre��lonego zakresu adresow pod podany adres.\nZakresy mog�} sie pokrywaa."},
/* ru */ {IDGS_MON_MOVE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_MOVE_DESCRIPTION_SV, "Flytta minne fran kalladressen som anges av minnesomradet\ntill destinationen som anges av adressen. Regionerna kan vara\noverlappande."},
/* tr */ {IDGS_MON_MOVE_DESCRIPTION_TR, "Belledi belirtilmit kaynak adres aralydyndan belirtilmit hedef\nadresine taty.  Alanlar ust uste binebilir."},
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
/* pl */ {IDGS_CHECKPOINT_COMMANDS_PL, "Komendy punktow kontrolnych:"},
/* ru */ {IDGS_CHECKPOINT_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_CHECKPOINT_COMMANDS_SV, "Kommandon for brytpunkter:"},
/* tr */ {IDGS_CHECKPOINT_COMMANDS_TR, "Kontrol Noktasy komutlary:"},
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
/* pl */ {IDGS_COND_EXPR_PL, "cond_expr"},
/* ru */ {IDGS_COND_EXPR_RU, ""},  /* fuzzy */
/* sv */ {IDGS_COND_EXPR_SV, "villkorsuttryck"},
/* tr */ {IDGS_COND_EXPR_TR, "kotul_idafesi"},
#endif

/*
   Translators: this command was extended:

   - "load|store|exec" option added

   TODO: update these languages: DA, DE, HU, IT, NL, SV, TR
*/

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BREAK_DESCRIPTION,    N_("Set a breakpoint, If no address is given, the currently valid break-\npoints are printed.\nIf an address is given, a breakpoint is set for that address and the\nbreakpoint number is printed.\n`load|store|exec' is either `load', `store' or `exec' (or any combina-\ntion of these) to specify on which operation the monitor breaks. If\nnot specified, the monitor breaks on `exec'.\nA conditional expression can also be specified for the breakpoint.\nFor more information on conditions, see the CONDITION command.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BREAK_DESCRIPTION_DA, ""},  /* fuzzy */
/* de */ {IDGS_MON_BREAK_DESCRIPTION_DE, "Setze einen Breakpoint. Wenn keine Adresse angegeben wurde, werden die\naktuellen gultigen Breakpoints gezeigt. \nWenn eine Adresse angegebene wurde, wird ein Breakpoint auf diese Adresse\ngesetzt und die Breakpoint Nummer wird ausgegeben.\n`load|store|exec' ist entweder `load', `store' oder `exec' (oder eine\nKombination) und dient zur Angabe, bei welcher Operation der Monitor\nanhalten soll. Wenn keine Angabe gemacht wird, stoppt der Monitor bei\n`exec'.\nEin bedingter Ausdruck kann zu Breakpoints zugeordnet werden. Fur\nmehr Informations uber bedingte Ausdrucke, bitte Kommando CONDITION\nansehen."},
/* fr */ {IDGS_MON_BREAK_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BREAK_DESCRIPTION_HU, ""},  /* fuzzy */
/* it */ {IDGS_MON_BREAK_DESCRIPTION_IT, ""},  /* fuzzy */
/* ko */ {IDGS_MON_BREAK_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BREAK_DESCRIPTION_NL, "Zet een breekpunt, als er geen adres is opgegeven dan zullen de huidige\ngeldige breekpunten worden geprint. Als er een adres is opgegeven dan\nzal er een breekpunt gezet worden voor dat adres en de nummer van het\nbreekpunt zal worden getoond.\n`load|store|exec' is `load', `store' of `exec' (of een combinatie) die\ngebruikt zal worden om aan te geven bij wlke operatie de monitor zou\nmoeten starten. Als er niets is opgegeven dan zal de monitor op 'exec'\nstarten.\nEen conditie kan worden opgegeven voor het breekpunt. Voor meer\ninformatie over condities zie het CONDITION commando."},
/* pl */ {IDGS_MON_BREAK_DESCRIPTION_PL, "Ustawia punkt wstrzymania. Je��li nie podano adresu, pokazywane s�}\nobecnie aktywne punkty wstrzymania.\nJe��li podano adres, ustawiany jest punkt wstrzymania dla tego adresu\ni pokazywany jest numer punktu wstrzymania.\n`load|store|exec' to `load', `store' lub `exec' (albo ich po3�}czenia),\nokre��laj�}ce  podczas ktorych operacji nastepuje b3�}d. Je��li nic\nnie okre��lono, monitor przerywa dzia3anie na `exec'.\nMo?na rownie? okre��lia wyra?enie warunkowe dla punktu wstrzymania.\nBy znale?a wiecej informacji o warunkach, zobacz polecenie CONDITION."},
/* ru */ {IDGS_MON_BREAK_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BREAK_DESCRIPTION_SV, ""},  /* fuzzy */
/* tr */ {IDGS_MON_BREAK_DESCRIPTION_TR, ""},  /* fuzzy */
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_COMMAND,    N_("Command")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_COMMAND_DA, ""},  /* fuzzy */
/* de */ {IDGS_COMMAND_DE, "Kommando"},
/* fr */ {IDGS_COMMAND_FR, ""},  /* fuzzy */
/* hu */ {IDGS_COMMAND_HU, ""},  /* fuzzy */
/* it */ {IDGS_COMMAND_IT, ""},  /* fuzzy */
/* ko */ {IDGS_COMMAND_KO, "�Ci�EE"},
/* nl */ {IDGS_COMMAND_NL, "Commando"},
/* pl */ {IDGS_COMMAND_PL, "Komenda"},
/* ru */ {IDGS_COMMAND_RU, ""},  /* fuzzy */
/* sv */ {IDGS_COMMAND_SV, "Kommando"},
/* tr */ {IDGS_COMMAND_TR, ""},  /* fuzzy */
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_COMMAND_DESCRIPTION,    N_("Specify `command' as the command to execute when checkpoint `checknum'\nis hit.  Note that the `x' command is not yet supported as a\ncommand argument.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_COMMAND_DESCRIPTION_DA, "Angiv \"kommando\" som kommando der skal eksekveres nar ckeckpoint\n\"checknum\" nas. Var opmarksom pa at kommandoen \"x\" endnu ikke\ner understottet som parameter."},
/* de */ {IDGS_MON_COMMAND_DESCRIPTION_DE, "Definiere `Kommando', welches bei Checkpoint `Checknum' ausgefuhrt wird.\nAchtung Kommando `x' wird zurzeit noch nicht als Kommando Argument\nunterstutzt."},
/* fr */ {IDGS_MON_COMMAND_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_COMMAND_DESCRIPTION_HU, "`parancs' megadasa egy `ell_pont_szam' sorszamaval adott ellenorzesi pont\neleresekor torteno vegrehajtasra.  Az `x' parancs egyelore nem hasznalhato\nitt parameterkent."},
/* it */ {IDGS_MON_COMMAND_DESCRIPTION_IT, "Specifica `comando' come il comando da eseguire quando\nviene incontrato il punto di controllo `checknum'. Nota che \nil comando `x' non e ancora supportato come parametro."},
/* ko */ {IDGS_MON_COMMAND_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_COMMAND_DESCRIPTION_NL, "Geef `commando' als het command om uit te voeren wanneer checkpunt `checknum'\nwordt uitgevoerd. NB: het `x' commando is op dit moment geen geldige\nparameter."},
/* pl */ {IDGS_MON_COMMAND_DESCRIPTION_PL, "Okre��l 'command' jako polecenie do wykonania przy osi�}gnieciu punktu 'checknum.'\nPolecenie 'x' nie jest jeszcze obs3ugiwane jako argument polecenia."},
/* ru */ {IDGS_MON_COMMAND_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_COMMAND_DESCRIPTION_SV, "Ange \"kommando\" som kommando att exekvera nar vid traff pa\nkontrollpunkten�E\"kontrollnr\". Observera att kommandot \"x\" annu\ninte stods som kommandoparameter."},
/* tr */ {IDGS_MON_COMMAND_DESCRIPTION_TR, "Kontrol noktasy `kontrolnumarasy'na ulatyldydynda `komut' olarak\ncalyttyrylacak komutu belirt.  Henuz `x' komutunun bir komut argumany\nolarak desteklenmedidini not edin."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_CONDITION_DESCRIPTION,    N_("Each time the specified checkpoint is examined, the condition is\nevaluated.  If it evalutes to true, the checkpoint is activated.\nOtherwise, it is ignored.  If registers are specified in the expression,\nthe values used are those at the time the checkpoint is examined, not\nwhen the condition is set.\nThe condition can make use of registers (.A, .X, .Y, .PC, .SP) and\ncompare them (==, !=, <, >, <=, >=) again other registers or constants.\nRegisters can be the registers of other devices; this is denoted by\na memspace prefix (i.e., c:, 8:, 9:, 10:, 11:\nExamples: .A == 0, .X == .Y, 8:.X == .X\n")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_CONDITION_DESCRIPTION_DA, "Betingelsen evalueres hver gang det angivne checkpoint undersoges.\nHvis evalueres til sand aktiveres checkpointet, allers ignoreres\ndet. Hvis betingelsen indeholder registre, anvendes de vardier,\nregistrene har nar betingelsen evalueres, ikke nar betingelsen\noprettes.\nBetingelsen kan anvende registrene (.A, .X, .Y, .PC, .SP) og\nsammenligne dem (==, !=, <, >, <=, >=) med andre registre eller\nkonstanter. Registre kan vare i andre enheder, og dette angives\nsom et hukommelsesomradeprefix (dvs., c:, 8:, 9:, 10:, 11:)\nEksempel: .A == 0, .X == .Y, 8:.X == .X\n"},
/* de */ {IDGS_MON_CONDITION_DESCRIPTION_DE, "Bei jeder Uberprufung des Checkpoints, wird die Bedingung evaluiert.\nIst das Ergebnis `Wahr', wird der Checkpoint aktiviert, sonst ingnoriert.\nWenn Register benutzt werden, werden deren Werte zum Zeitpunkt der \nUberprufung herangezogen.\nDie Bedingung kann Register benutzen (.A, .X, .Y, .PC, .SP) und gegen \nRegister oder Konstanten vergleichen (==, !=, <, >, <=, >=).\nRegister konnen auch Gerateregister sein; dazu wird die memspace Prefix-syntax \nverwendet: c:, 8:, 9:, 10:, 11:\nBeispiel: .A == 0, .X == .Y, 8:.X == .X\n"},
/* fr */ {IDGS_MON_CONDITION_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_CONDITION_DESCRIPTION_HU, "Minden alkalommal, amikor egy adott ellenorzesi pontot megvizsgal, a\nfeltetelt kiertekeli. Ha az eredmeny igaz, a torespont aktivalodik.\nEgyebkent, figyelmen kivul hagyja. Ha regiszterek szerepelnek a kifejezesben,\naz ellenorzes pillanataban vett ertekuk szamit, nem pedig a beallitaskori.\nA feltetel hasznalhatja a regisztereket ( .A, .X, .Y, .PC, .SP) es ossze is\nhasonlithatja oket (==, !=, <, >, <=, >=) mas regiszterekkel.\nA regiszterek lehetnek mas eszkozok regiszterei is; azokat egy memoria ter\nelotaggal kell ellatni (vagyis c:, 8:, 9:, 10:, 11:).\nPeldak: .A == 0, .X == .Y, 8:.X == .X\n"},
/* it */ {IDGS_MON_CONDITION_DESCRIPTION_IT, "Ogni volta che si esamina il punto di controllo specificato, viene valutata\nla condizione. Se e vera, il punto di controllo e attivato.\nAltrimenti viene ignorato. Se nell'espressione sono specificati i registri,\nquesti valori sono quelli usati quando viene esaminato il punto di controllo,\nnon quando viene impostata la condizione.\nLa condizione puo fare uso dei registri (.A, .X, .Y, .PC, .SP) e confontarli\n(==, !=, <, >, <=, >=) con altri registri o costanti.\nI registri possono essere registri di altre periferiche; questo e denotato da\nun prefisso che specifica lo spazio di memoria (cioe, c:, 8:, 9:, 10:, 11:)\nAlcuni esempi: .A == 0, .X == .Y, 8:.X == .X\n"},
/* ko */ {IDGS_MON_CONDITION_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_CONDITION_DESCRIPTION_NL, "Elke keer de opgegeven checkpunt wordt onderzocht zal de conditie worden\ngeevalueerd. Als de evaluatie positief is dan zal de checkpunt geactiveerd\nworden, bij negatief zal er niets worden gedaan. Als er registers zijn\nopgegeven in de expressie dan zullen de waarden in die registers gebruikt\nworden op het moment dat de checkpunt wordt onderzocht, niet op het moment\ndat de conditie is opgegeven.\nDe conditie kan gebruik maken van registers (.A, .X, .Y, .PC, .SP) en\nkan ze vergelijken (==, !=, <, >, <=, >=) met andere registers of constanten\nRegisters kunnen de registers van andere apparaten zijn; de manier van opgeven\nis door een geheugenruimte prefix (bijvoorbeeld: c:, 8:, 9:, 10:, 11:\nVoorbeelden: .A == 0, .X == .Y, 8:.X == .X\n"},
/* pl */ {IDGS_MON_CONDITION_DESCRIPTION_PL, "Za ka?dym razem, gdy analizowany jest punkt kontrolny, szacowany\njest stan. Je��li jest oszacowany na 'prawda', punkt kontrolny jest\nuaktywniany. W innym razie jest ignorowany. Je��li w wyra?eniu\npodano rejestry, u?ywane s�} warto��ci z czasu szacowania punktu\nkontrolnego, nie z czasu ustawienia stanu.Stan mo?e korzystaa z rejestrow (.A, .X, .Y, .PC, .SP) i porownywaa je\n(==, !=, <, >, <=, >=) z innymi rejestrami lub sta3ymi. Rejestry mog�} bya\nrejestrami innych urz�}dzen, co jest okre��lone przedrostkiem przestrzeni\npamieci (np. c:, 8:, 9:, 10:, 11)\nPrzyk3ady: A == 0, .X == .Y, 8:.X == .X\n"},
/* ru */ {IDGS_MON_CONDITION_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_CONDITION_DESCRIPTION_SV, "Villkoret utvarderas varje gang den givna kontrollpunkten\nundersoks. Om det utvarderas till sant aktiveras kontrollpunkten.\nI annat fall ignoreras den. Om uttrycket innehaller register\nanvands de varden de har da kontrollpunkten utvarderas, inte\nnar villkoret sattes.\nVillkoret kan anvanda register (.A, .X, .Y, .PC, .SP) och\njamfora dem (==, !=, <, >, <=, >=) mot andra register eller\nkonstanter. Register kan vara register i andra enheter, detta\nanges som ett minnesomradesprefix (dvs., c:, 8:, 9:, 10:, 11:)\nExempel: .A == 0, .X == .Y, 8:.X == .X\n"},
/* tr */ {IDGS_MON_CONDITION_DESCRIPTION_TR, "Her defasynda belirtilmit bir kontrol noktasy incelendidinde, kotul\ndederlendirilir.  Kotul dodru sonuc verirse, kontrol noktasy aktive edilir.\nAksi taktirde goz ardy edilir.  Eder ifadede registerlar tanymlanmytsa,\nbu dederler ifade tanymlandydynda dedil kontrol noktasy incelendidinde\nkullanylyrlar.\nYfadelerde (.A, .X, .Y, .PC, .SP) registerlary kullanylabilir ve\n(==, !=, <, >, <=, >=) opertatorleriyle dider register ve sabit dederlerle.\nkartylattyrylabilirler. Registerlar batka aygytlaryn registerlary da olabilir;\nbu bir bellek alany on ekiyle ifade edilir (yani, c:, 8:, 9:, 10:, 11:\nOrnekler: .A == 0, .X == .Y, 8:.X == .X\n"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DISABLE_DESCRIPTION,    N_("Disable checkpoint `checknum'.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DISABLE_DESCRIPTION_DA, "Deaktiver checkpoint \"checknum\"."},
/* de */ {IDGS_MON_DISABLE_DESCRIPTION_DE, "Checkpoint `Checknum' deaktivieren."},
/* fr */ {IDGS_MON_DISABLE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DISABLE_DESCRIPTION_HU, "`ell_pont_szam' jelu ellenorzesi pont tiltasa."},
/* it */ {IDGS_MON_DISABLE_DESCRIPTION_IT, "Disattiva il punto di controllo `checknum'."},
/* ko */ {IDGS_MON_DISABLE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DISABLE_DESCRIPTION_NL, "Checkpunt `checknum' uitschakelen."},
/* pl */ {IDGS_MON_DISABLE_DESCRIPTION_PL, "Wy3�}cz punkt kontrolny `checknum'."},
/* ru */ {IDGS_MON_DISABLE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DISABLE_DESCRIPTION_SV, "Inaktivera kontrollpunkt \"kontrollnr\"."},
/* tr */ {IDGS_MON_DISABLE_DESCRIPTION_TR, "Kontrol Noktasy `kontrolnumarasy'ny pasiflettir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_ENABLE_DESCRIPTION,    N_("Enable checkpoint `checknum'.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_ENABLE_DESCRIPTION_DA, "Aktiver checkpoint \"checknum\"."},
/* de */ {IDGS_MON_ENABLE_DESCRIPTION_DE, "Checkpoint `Checknum' aktivieren."},
/* fr */ {IDGS_MON_ENABLE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_ENABLE_DESCRIPTION_HU, "`ell_pont_szam' jelu ellenorzesi pont engedelyezese."},
/* it */ {IDGS_MON_ENABLE_DESCRIPTION_IT, "Attiva il punto di controllo `checknum'."},
/* ko */ {IDGS_MON_ENABLE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_ENABLE_DESCRIPTION_NL, "Activeer checkpunt `checknum'."},
/* pl */ {IDGS_MON_ENABLE_DESCRIPTION_PL, "W3�}cz punkt kontrolny `checknum'."},
/* ru */ {IDGS_MON_ENABLE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_ENABLE_DESCRIPTION_SV, "Aktivera kontrollpunkt \"kontrollnr\"."},
/* tr */ {IDGS_MON_ENABLE_DESCRIPTION_TR, "Kontrol Noktasy `kontrolnumarasy'ny aktif et."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_IGNORE_DESCRIPTION,    N_("Ignore a checkpoint a given number of crossings.  If no count is given,\nthe default value is 1.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_IGNORE_DESCRIPTION_DA, "Ignorer et checkpoint det angivne antal gange. Hvis antal ikke angives\nbruges standardvardien 1."},
/* de */ {IDGS_MON_IGNORE_DESCRIPTION_DE, "Ignoriere den Checkpoint fur die angegebene Anzahl an Aktivierungen.\nWenn kein `Zahler' angegeben wurde, wird der Standardwert 1 verwendet."},
/* fr */ {IDGS_MON_IGNORE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_IGNORE_DESCRIPTION_HU, "Az ellenorzesi pont figyelmen kivul hagyasa megadott szamu athaladaskor.  Ha nincs\nszam megadva, az alapertelmezett ertek 1."},
/* it */ {IDGS_MON_IGNORE_DESCRIPTION_IT, "Ignora un punto di controllo un numero specificato di occorrenze. Se\nnon e specificato alcun valore, quello predefinito e 1."},
/* ko */ {IDGS_MON_IGNORE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_IGNORE_DESCRIPTION_NL, "Negeer een checkpunt een opgegeven aantal keer. Als er geen aantal is\nopgegeven dan wordt de standaard waarde van 1 worden gebruikt."},
/* pl */ {IDGS_MON_IGNORE_DESCRIPTION_PL, "Ignoruje punkt kontrolny dan�} ilo��a razy. Je��li nie podano tej ilo��ci,\ndomy��lna warto��a wynosi 1."},
/* ru */ {IDGS_MON_IGNORE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_IGNORE_DESCRIPTION_SV, "Ignorera en kontrollpunkt det givna antalet ganger. Om inget antal ges\nar standardvardet 1."},
/* tr */ {IDGS_MON_IGNORE_DESCRIPTION_TR, "Bir kontrol noktasyny verilen adette gecit icin yoksay.  Eder adet verilmemitse,\nvarsayylan deder 1'dir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_UNTIL_DESCRIPTION,    N_("If no address is given, the currently valid breakpoints are printed.\nIf an address is given, a temporary breakpoint is set for that address\nand the breakpoint number is printed.  Control is returned to the\nemulator by this command.  The breakpoint is deleted once it is hit.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_UNTIL_DESCRIPTION_DA, "Hvis ingen adresse angives vises de aktuelle breakpoints. Hvis en\nadresse angives sattes et midlertidigt breakpoint, og nummeret pa\nbreakpointet vises. Kontrollen returneres til emulatoren af denne\nkommando. Breakpointet fjernes nar det nas."},
/* de */ {IDGS_MON_UNTIL_DESCRIPTION_DE, "Wenn keine Adresse angegeben wurde, werden die aktuell gultigen \nBreakpoints angezeigt. Wenn eine Adresse angegeben wurde, wird ein \ntemporarer Breakpoint auf dieser Adresse gesetzt und die Breakpoint Nummer wird\nangezeigt. Die Kontrolle wirdd bei diesem Kommando an die Emulation gegeben.\nDer Breakpoint wird geloscht, wenn er einmal getroffen wurde."},
/* fr */ {IDGS_MON_UNTIL_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_UNTIL_DESCRIPTION_HU, "Ha nincs cim megadva, a jelenleg ervenyes torespontokat irja ki.\nHa van adott cim, egy ideiglenes torespontot helyez el az adott cimre,\nes a torespont szama kiirodik.  A vezerles visszakerul az emulatorhoz\ne parancs altal. A torespont eleresekor torlodik."},
/* it */ {IDGS_MON_UNTIL_DESCRIPTION_IT, "Se non viene specificato alcun indirizzo, vengono stampati i\nbreakpoint attualmente validi. Se viene specificato un indirizzo,\nviene impostato un breakpoint temporaneo per tale indirizzo e\nviene stampato il suo numero. Il controllo ritorna all'emulatore\nper mezzo di questo comando. Il breakpoint e cancellato quando\nviene incontrato."},
/* ko */ {IDGS_MON_UNTIL_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_UNTIL_DESCRIPTION_NL, "Als er geen adres is opgegeven dan zullen de huidig geldige breekpunten\nworden geprint. Als er een adres is opgegeven dan wordt er een tijdelijk\nbreekpunt worden gezet voor dat adres en het breekpunt nummer zal worden\ngetoond. Na het geven van dit commando zal er terug worden gegaan naar de\nemulator. Het breekpunt zal worden verwijdert na het uitvoeren."},
/* pl */ {IDGS_MON_UNTIL_DESCRIPTION_PL, "Je��li nie podano adresu, pokazywane s�} obecne punkty wstrzymania.\nJe��li podano adres, ustawiany jest tymczasowy punkt wstrzymania\ni pokazywany jest numer punktu wstrzymania. To polecenie przywraca\nkontrole do emulatora. Punkt wstrzymania jest kasowany po jego osi�}gnieciu."},
/* ru */ {IDGS_MON_UNTIL_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_UNTIL_DESCRIPTION_SV, "Om du inte anger nagon adress visas de for narvarande giltiga\nbrytpunkterna. Om en adress anges satts en temporar brytpunkt for\nden adressen och numret pa den nya brytpunkten visas. Styrningen\naterlamnas till emulatorn for det har kommandot. Brytpunkten\ntas bort nar den har natts."},
/* tr */ {IDGS_MON_UNTIL_DESCRIPTION_TR, "Eder adres girilmemitse, gecerli mevcut kesme noktalary yazdyrylyr.\nEder bir adres girilmitse, o adres icin gecici bir kesme noktasy\nitaretlenir ve kesme noktasy sayysy yazdyrylyr.  Kontrol bu komutla\nemulatore dondurulur.  Bir kere eritildidi zaman kesme noktasy silinir."},
#endif

/*
   Translators: this is part of an actual command and should not get translated
*/

/* monitor/mon_command.c */
/* en */ {IDGS_LOADSTORE,    N_("load|store|exec")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_LOADSTORE_DA, ""},  /* fuzzy */
/* de */ {IDGS_LOADSTORE_DE, "load|store|exec"},
/* fr */ {IDGS_LOADSTORE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_LOADSTORE_HU, ""},  /* fuzzy */
/* it */ {IDGS_LOADSTORE_IT, ""},  /* fuzzy */
/* ko */ {IDGS_LOADSTORE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_LOADSTORE_NL, "load|store|exec"},
/* pl */ {IDGS_LOADSTORE_PL, "load|store|exec"},
/* ru */ {IDGS_LOADSTORE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_LOADSTORE_SV, ""},  /* fuzzy */
/* tr */ {IDGS_LOADSTORE_TR, ""},  /* fuzzy */
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
/* da */ {IDGS_MON_WATCH_DESCRIPTION_DA, ""},  /* fuzzy */
/* de */ {IDGS_MON_WATCH_DESCRIPTION_DE, "Setze einen Watchpoint. Wenn eine einzelne Adresse angegeben wurde, setze \nden Watchpoint fur diese Adresse. Wenn zwei Adressen angegeben wurden, \nsetze den Watchpoint auf die Adressen zwischen den beiden Adressen.\n`load|store|exec' ist entweder `load', `store' oder `exec' (oder eine\nKombination) und dient zur Angabe, bei welcher Operation der Monitor\nanhalten soll. Wenn keine Angabe gemacht wird, stoppt der Monitor bei\n`exec'.\nWenn keine Angabe gemacht wurde, halt der Monitor bei bei `load' und\n`store' Operationen an.\n"},
/* fr */ {IDGS_MON_WATCH_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_WATCH_DESCRIPTION_HU, ""},  /* fuzzy */
/* it */ {IDGS_MON_WATCH_DESCRIPTION_IT, ""},  /* fuzzy */
/* ko */ {IDGS_MON_WATCH_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_WATCH_DESCRIPTION_NL, "Zet een kijkpunt. Als er geen adres is opgegeven dan zal de huidige\ngeldige kijkpunten worden getoont. Als er een enkel adres is opgegeven\ndan zal er een kijkpunt worden gezet voor dat adres. Als er twee\nadressen zijn opgegeven dan zal er een kijkpunt worden gezet voor de\nadressen tussen de twee adressen.\n`load|store|exec' is `load',  `store' of `exec' om aan te geven bij\nwelke operatie de monitor zou moeten starten. Als deze niet opgegeven\nis dan zal de monitor starten bij `load' en `store' operaties.\n"},
/* pl */ {IDGS_MON_WATCH_DESCRIPTION_PL, "Ustawia punkt ��ledzenia. Je��li nie podano adresu, pokazywane s�}\nobecnie aktualne punkty ��ledzenia. Je��li okre��lono pojedynczy adres,\nustawia punkt ��ledzenia na ten adres. Jesli okre��lono dwa adresy,\nustawia punkt ��ledzenia dla obszaru pamieci pomiedzy tymi dwoma\nadresami.\n`load|store|exec' to `load', `store' lub `exec' (albo ich po3�}czenia),\nokre��laj�}ce  podczas ktorych operacji nastepuje b3�}d. Je��li nic\nnie okre��lono, monitor przerywa dzia3anie na `load' i `store'.\n"},
/* ru */ {IDGS_MON_WATCH_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_WATCH_DESCRIPTION_SV, ""},  /* fuzzy */
/* tr */ {IDGS_MON_WATCH_DESCRIPTION_TR, ""},  /* fuzzy */
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
/* da */ {IDGS_MON_TRACE_DESCRIPTION_DA, ""},  /* fuzzy */
/* de */ {IDGS_MON_TRACE_DESCRIPTION_DE, "Setze einen Tracepoint. Wenn keine Adresse angegeben wird, werden die\naktuellen gultigen Tracepoints ausgegeben. Wenn eine einzelne Adresse\nangegeben wurde, setze den Watchpoint fur diese Adresse. Wenn zwei\nAdressen angegeben wurden, setze den Watchpoint auf die Adressen\nzwischen den beiden Adressen.\n`load|store|exec' ist entweder `load', `store' oder `exec' (oder eine\nKombination) und dient zur Angabe, bei welcher Operation der Monitor\nanhalten soll. Wenn keine Angabe gemacht wird, beobachtet der Monitor\nalle Operationen.\n"},
/* fr */ {IDGS_MON_TRACE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_TRACE_DESCRIPTION_HU, ""},  /* fuzzy */
/* it */ {IDGS_MON_TRACE_DESCRIPTION_IT, ""},  /* fuzzy */
/* ko */ {IDGS_MON_TRACE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_TRACE_DESCRIPTION_NL, "Zet een traceerpunt. Als er geen adres is opgegeven dan zullen de huidige\ngeldige traceerpunten worden getoont. Als er een enkel adres is opgegeven\ndan zal er een traceerpunt worden gezet voor dat adres. Als er twee\nadressen zijn opgegeven dan zal er een traceerpunt worden gezet voor de\nadressen tussen de twee adressen.\n`load|store|exec' is `load', `store' of 'exec' om aan te geven bij welke\noperatie de monitor zou moeten starten. Als deze niet opgegeven is dan zal\nde monitor starten bij alle operaties.\n"},
/* pl */ {IDGS_MON_TRACE_DESCRIPTION_PL, "Ustawia punkt ��ledzenia. Je��li nie podano adresu, pokazywane s�}\nw3a��ciwe obecnie punkty ��ledzenia. Je��li podano jeden adres,\nustawia punkt ��ledzenia tego adresu. Je��li podano dwa adresy,\nustawia punkt ��ledzenia obszaru pamieci pomiedzy nimi.\n`load|store|exec' to `load', `store' lub `exec' (albo ich po3�}czenia),\nokre��laj�}ce  podczas ktorych operacji nastepuje b3�}d. Je��li nic\nnie okre��lono, monitor ��ledzi wszystkie trzy rodzaje operacji.\n"},
/* ru */ {IDGS_MON_TRACE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_TRACE_DESCRIPTION_SV, ""},  /* fuzzy */
/* tr */ {IDGS_MON_TRACE_DESCRIPTION_TR, ""},  /* fuzzy */
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
/* pl */ {IDGS_MONITOR_STATE_COMMANDS_PL, "Monitoruj polecenia stanu:"},
/* ru */ {IDGS_MONITOR_STATE_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MONITOR_STATE_COMMANDS_SV, "Kommandon for monitorstatus:"},
/* tr */ {IDGS_MONITOR_STATE_COMMANDS_TR, "Monitor durum komutlary:"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DEVICE_DESCRIPTION,    N_("Set the default memory device to either the computer `c:' or the\nspecified disk drive (`8:', `9:').")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DEVICE_DESCRIPTION_DA, "Sat det valgte hukommelses omrade til enten computeren \"c:\" eller\ndet angivne diskettedrev (\"8:\", \"9:\")."},
/* de */ {IDGS_MON_DEVICE_DESCRIPTION_DE, "Setze das aktuelle Speichergerat entweder auf `c:' \noder das angegebene Laufwerk (`8:', `9:')."},
/* fr */ {IDGS_MON_DEVICE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DEVICE_DESCRIPTION_HU, "Az alapertelmezett memoria eszkoz beallitasa a szamitogepre `c:' vagy\na megadott lemezmeghajtora (`8:', `9:')."},
/* it */ {IDGS_MON_DEVICE_DESCRIPTION_IT, "Imposta la periferica di memoria predefinita o sul computer `c:'\noppure sul disk drive specificato (`8:', `9:')."},
/* ko */ {IDGS_MON_DEVICE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DEVICE_DESCRIPTION_NL, "Zet de standaard geheugen apparaat naar of de computer `c:' of de\nopgegeven disk drive (`8:', `9:')."},
/* pl */ {IDGS_MON_DEVICE_DESCRIPTION_PL, "Ustawia komputer `c:', lub okre��lon�} stacje dyskow (`8:', `9:')\njako domy��lne urz�}dzenie pamieci."},
/* ru */ {IDGS_MON_DEVICE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DEVICE_DESCRIPTION_SV, "Satt forvald minnesenhet antingen till datorn \"c:\" eller\nden angivna diskettenheten (\"8:\", \"9:\")."},
/* tr */ {IDGS_MON_DEVICE_DESCRIPTION_TR, "Varsayylan bellek aygytyny bilgisayar `c:' ya da (`8:', `9:') ile\nbelirtilmit disket durucu olarak belirle."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_EXIT_DESCRIPTION,    N_("Leave the monitor and return to execution.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_EXIT_DESCRIPTION_DA, "Forlad monitoren og ga tilbage til eksekvering."},
/* de */ {IDGS_MON_EXIT_DESCRIPTION_DE, "Verlasse Monitor und setze Ausfuhrung fort."},
/* fr */ {IDGS_MON_EXIT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_EXIT_DESCRIPTION_HU, "A monitor elhagyasa es a vegrehajtas folytatasa."},
/* it */ {IDGS_MON_EXIT_DESCRIPTION_IT, "Esce dal monitor e ritorna all'esecuzione."},
/* ko */ {IDGS_MON_EXIT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_EXIT_DESCRIPTION_NL, "Verlaat de monitor en ga terug naar de uitvoering."},
/* pl */ {IDGS_MON_EXIT_DESCRIPTION_PL, "Opu��a monitor i wroa do wykonywania"},
/* ru */ {IDGS_MON_EXIT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_EXIT_DESCRIPTION_SV, "Lamna monitorn och aterga till programkorningen."},
/* tr */ {IDGS_MON_EXIT_DESCRIPTION_TR, "Monitoru terk et ve calyttyrmaya geri don."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_QUIT_DESCRIPTION,    N_("Exit the emulator immediately.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_QUIT_DESCRIPTION_DA, "Afslut emulatoren ojblikkeligt."},
/* de */ {IDGS_MON_QUIT_DESCRIPTION_DE, "Emulator sofort beenden."},
/* fr */ {IDGS_MON_QUIT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_QUIT_DESCRIPTION_HU, "Azonnali kilepes az emulatorbol."},
/* it */ {IDGS_MON_QUIT_DESCRIPTION_IT, "Esci immediatamente dall'emulatore."},
/* ko */ {IDGS_MON_QUIT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_QUIT_DESCRIPTION_NL, "Onmiddelijk de emulator afsluiten."},
/* pl */ {IDGS_MON_QUIT_DESCRIPTION_PL, "Natychmiast wyjd? z emulatora."},
/* ru */ {IDGS_MON_QUIT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_QUIT_DESCRIPTION_SV, "Avsluta emulatorn omedelbart."},
/* tr */ {IDGS_MON_QUIT_DESCRIPTION_TR, "Emulasyondan derhal cyk."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_RADIX_DESCRIPTION,    N_("Set the default radix to hex, decimal, octal, or binary.  With no\nargument, the current radix is printed.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_RADIX_DESCRIPTION_DA, "Sat standardradix til hex, decimal, oktal eller binar. Hvis der\nikke angives et argument vises det aktuelle radix."},
/* de */ {IDGS_MON_RADIX_DESCRIPTION_DE, "Setze die Standardzahlenbasis auf Hexadezimal, Dezimal, Oktal oder Binar.\nBei keinem Argument wird die akteulle Zahlenbasis ausgegeben."},
/* fr */ {IDGS_MON_RADIX_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_RADIX_DESCRIPTION_HU, "Az alap szamrendszer hexadecimalis, decimalis, oktalis vagy binaris.\nParameter nelkul az aktualisat mutatja."},
/* it */ {IDGS_MON_RADIX_DESCRIPTION_IT, "Imposta la radice predefinita a esadecimale, decimale, ottale o\nbinaria. Senza parametro viene stampata la radice attuale."},
/* ko */ {IDGS_MON_RADIX_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_RADIX_DESCRIPTION_NL, "Zet de standaard radix naar hex, decimaal, octaal of binair. Als er\ngeen parameter is opgegeven dan zal de huidige radix worden getoond."},
/* pl */ {IDGS_MON_RADIX_DESCRIPTION_PL, "Ustawia domy��lny korzen na heksadecymalny, decymalny, o��emkowy\nlub binarny. Bez podanego argumentu, pokazywany jest obecny korzen."},
/* ru */ {IDGS_MON_RADIX_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_RADIX_DESCRIPTION_SV, "Satt standardradix till hex, decimal, oktal eller binar. Om du\ninte ger nagot argument visas nuvarande radix."},
/* tr */ {IDGS_MON_RADIX_DESCRIPTION_TR, "Varsayylan sayy tabanyny 16'ly, 10'lu, 8'li ya da 2'li yap.\nArgumansyz olarak gecerli sayy tabany yazdyrylyr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_SIDEFX_DESCRIPTION,    N_("Control how monitor generated reads affect memory locations that have\nread side-effects.  If the argument is 'on' then reads may cause\nside-effects.  If the argument is 'off' then reads don't cause\nside-effects.  If the argument is 'toggle' then the current mode is\nswitched.  No argument displays the current state.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_SIDEFX_DESCRIPTION_DA, "Bestemmer hvordan lasninger i monitoren pavirker hukommelsesomrader,\nder har sedeeffekter ved lasning. Hvis argumentet er \"on\" kan lasninger\nforesage sideeffekter. Hvis argumentet er \"off\" vil lasninger ikke\nforesage sideeffekter. Hvis argumentet er \"toggle\" skiftes\nden nuvarende tilstand. Hvis der ikke angives noget argument vises\nden nuvarende tilstand."},
/* de */ {IDGS_MON_SIDEFX_DESCRIPTION_DE, "Steuerung, wie die vom Monitor erzeugten Lesezugriffe die Speicherzellen\nmit Lese-Seiteneffekten betreffen.\nBei Argument \"on\" werden Lese-Seiteneffekte erzeugt.\nBei Argument \"off\" werden keine Lese-Seiteneffekte erzeugt.\nBei Argumenrt \"toggle\" wird das Verhalten vertauscht.\nBei keinem Argument wird das aktuelle Verhalten ausgegebene."},
/* fr */ {IDGS_MON_SIDEFX_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_SIDEFX_DESCRIPTION_HU, "Beallitja, hogyan hatnak a monitorprogram memoria olvasasai azokra a\nmemoriahelyekre, amelyeknek olvasas-mellekhatasai vannak. Ha a parameter\n'on', az olvasasok okozhatnak mellekhatasokat. Ha a parameter 'off', akkor pedig\nnem okoznak. Ha a parameter 'toggle', az aktualis modot atkapcsolja.\nParameter nelkuli hivas kiirja az aktualis modot."},
/* it */ {IDGS_MON_SIDEFX_DESCRIPTION_IT, "Controlla come le letture generate dal monitor affliggono le locazioni\ndi memoria che hanno degli effetti collaterali sulla lettura.\nSe il paremetro e 'on', le letture possono causare effetti collaterali.\nSe il parametro e 'off', le letture non causano effetti collaterali.\nSe il parametro e 'scambia', la modalita attuale viene invertita.\nNessun parametro mostra lo stato attuale."},
/* ko */ {IDGS_MON_SIDEFX_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_SIDEFX_DESCRIPTION_NL, "Geef aan hoe de lees acties van de monitor de geheugen locaties met lees\nbij-effecten beinvloed. Als de parameter 'off' is dan zullen lees acties\ngeen bij-effecten vertonen. Als de parameter 'on' is dan zullen lees\nacties bij-effecten vertonen. Als de parameter 'toggle' is dan zal de\nhuidige modus worden geschakeld. Als er geen parameter is dan zal de\nhuidige modus worden getoond."},
/* pl */ {IDGS_MON_SIDEFX_DESCRIPTION_PL, "Kontroluje w jaki sposob wygenerowane w monitorze odczyty po3o?enia\nwp3ywaj�} na obszary pamieci, ktore maj�} efekty uboczne odczytu.\nJe��li argument to 'on', wtedy odczyty mog�} powodowaa efekty uboczne.\nJe��li argument to 'off', wtedy odczyty nie powoduj�} efektow ubocznych.\nJe��li argument to 'toggle', obecny tryb jest prze3�}czany.\nBrak argumentu pokazuje obecny stan."},
/* ru */ {IDGS_MON_SIDEFX_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_SIDEFX_DESCRIPTION_SV, "Styr hur lasningar i monitorn paverkar minnesomraden som har\nsidoeffekter vid lasning. Om argumentet ar \"on\" tillats lasningar\natt orsaka sidoeffekter. Om argumentet ar \"off\" tillats inte\nlasningar att orsaka sidoeffekter. Om argumentet ar \"toggle\" byts\ndet nuvarande laget. Om du inte anger nagra argument visas\nnuvarande lage."},
/* tr */ {IDGS_MON_SIDEFX_DESCRIPTION_TR, "Okuma yan etkileri bulunan bellek konumlaryny monitor tarafyndan olutturulan\nokumalaryn nasyl etkiledidini kontrol et.  Arguman 'on' ise, okumalar yan\netkiye neden olabilir.  Arguman 'off' ise okumalaryn bir yan etkisi\nolmayacaktyr.  Eder arguman 'toggle' ise gecerli mod dedittirilecektir.\nArguman verilmemesi o anki durumu goruntuler."},
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
/* pl */ {IDGS_DISK_COMMANDS_PL, "Polecenia dyskowe:"},
/* ru */ {IDGS_DISK_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DISK_COMMANDS_SV, "Diskettkommandon:"},
/* tr */ {IDGS_DISK_COMMANDS_TR, "Disk komutlary:"},
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
/* pl */ {IDGS_DISK_COMMAND_PL, "disk command"},
/* ru */ {IDGS_DISK_COMMAND_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DISK_COMMAND_SV, "diskkommando"},
/* tr */ {IDGS_DISK_COMMAND_TR, "disk komutu"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_AT_DESCRIPTION,    N_("Perform a disk command on the currently attached disk image on drive 8.\nThe specified disk command is sent to the drive's channel #15.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_AT_DESCRIPTION_DA, "Udforer en diskkommando pa det diskette-image, der er tilsluttet\ndrev 8. Diskkommandoen sendes til drevets kanal #15."},
/* de */ {IDGS_MON_AT_DESCRIPTION_DE, "Fuhre ein Diskkommando auf dem aktuell eingelegtem Diskimage auf Laufwerk 8\naus.\nDas angegebene Kommando wird auf dem Laufwerks Kommandokanal #15 geschickt."},
/* fr */ {IDGS_MON_AT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_AT_DESCRIPTION_HU, "Lemez parancs vegrehajtasa az aktualisan csatolt lemezen, a 8-as egysegen.\nA megadott lemez parancsot a meghajto #15-os csatornajara kuldi."},
/* it */ {IDGS_MON_AT_DESCRIPTION_IT, "Esegue un comando disco sull'immagine disco attualmente presente nel\ndrive 8. Il comando specificato e inviato al canale #15 del drive."},
/* ko */ {IDGS_MON_AT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_AT_DESCRIPTION_NL, "Doe een disk commando operatie op de huidig gekoppelde disk bestand in drive\n8, Het opgegeven disk commando zal worden gestuurt naar kanaal #15 van de\ndrive."},
/* pl */ {IDGS_MON_AT_DESCRIPTION_PL, "Wykonaj polecenie dyskowe na obecnie zamontowanym obrazie dyskietki\nw stacji 8. Dane polecenie jest wysy3ane na kana3 #15 stacji."},
/* ru */ {IDGS_MON_AT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_AT_DESCRIPTION_SV, "Utfor ett diskkommando pa den diskettavbildning som ar ansluten till\nenhet 8. Diskkommandot sands pa diskettenhetens kanal nummer 15."},
/* tr */ {IDGS_MON_AT_DESCRIPTION_TR, "8 nolu surucude takyly disk imajy uzerinde bir disk komutu calyttyr.\nBelirtilen disk komutu surucunun 15 numaraly kanalyna gonderilir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_DEVICE,    N_("device")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_DEVICE_DA, "enhed"},
/* de */ {IDGS_DEVICE_DE, "Gerat"},
/* fr */ {IDGS_DEVICE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_DEVICE_HU, ""},  /* fuzzy */
/* it */ {IDGS_DEVICE_IT, "dispositivo"},
/* ko */ {IDGS_DEVICE_KO, ""},  /* fuzzy */
/* nl */ {IDGS_DEVICE_NL, "apparaat"},
/* pl */ {IDGS_DEVICE_PL, "device"},
/* ru */ {IDGS_DEVICE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DEVICE_SV, "enhet"},
/* tr */ {IDGS_DEVICE_TR, "aygyt"},
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
/* pl */ {IDGS_FILE_INDEX_PL, "file_index"},
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
/* pl */ {IDGS_MON_AUTOSTART_DESCRIPTION_PL, "automatycznie uruchom dany program albo obraz dysku lub ta��my"},
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
/* pl */ {IDGS_MON_AUTOLOAD_DESCRIPTION_PL, "automatycznie wczytaj dany program albo obraz dysku lub ta��my"},
/* ru */ {IDGS_MON_AUTOLOAD_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_AUTOLOAD_DESCRIPTION_SV, "las in given disk-/bandavbildningsfil eller program automatiskt"},
/* tr */ {IDGS_MON_AUTOLOAD_DESCRIPTION_TR, ""},  /* fuzzy */
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_ATTACH_DESCRIPTION,    N_("Attach file to device. (device 32 = cart)")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_ATTACH_DESCRIPTION_DA, "Tilslut en fil til enhed. (enhed 32 = cartridge)"},
/* de */ {IDGS_MON_ATTACH_DESCRIPTION_DE, "Benutze Datei fur das Gerat. (Gerat 32 = Modul)"},
/* fr */ {IDGS_MON_ATTACH_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_ATTACH_DESCRIPTION_HU, "Fajl csatolasa az eszkozhoz. (32-es eszkoz = cart)"},
/* it */ {IDGS_MON_ATTACH_DESCRIPTION_IT, "Seleziona il file per la perifica. (periferica 32 = cartuccia)"},
/* ko */ {IDGS_MON_ATTACH_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_ATTACH_DESCRIPTION_NL, "Koppel bestand aan apparaat. (apparaat 32 = cart"},
/* pl */ {IDGS_MON_ATTACH_DESCRIPTION_PL, "Pod3�}cz plik pod urz�}dzenie (urz�}dzenie 32 = cart)"},
/* ru */ {IDGS_MON_ATTACH_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_ATTACH_DESCRIPTION_SV, "Anslut en fil till en enhet. (enhet 32 = insticksmodul)"},
/* tr */ {IDGS_MON_ATTACH_DESCRIPTION_TR, "Aygyta dosya yerlettir. (aygyt 32 = kartut)"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BLOAD_DESCRIPTION,    N_("Load the specified file into memory at the specified address.\nIf device is 0, the file is read from the file system.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BLOAD_DESCRIPTION_DA, "Indlas den angivne fil til hukommelsen pa den angivne adresse.\nHvis enhed er 0 lases fra filsystemet."},
/* de */ {IDGS_MON_BLOAD_DESCRIPTION_DE, "Lade angegebene Datei in den Speicher an die angegebene Adresse.\nBei Gerat 0, wird die Datei vom Dateisystem gelesen."},
/* fr */ {IDGS_MON_BLOAD_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BLOAD_DESCRIPTION_HU, "A megadott fajl betoltese a memoriaba a megadott cimre.\nHa az eszkoz 0, a fajlt a fajlrendszerbol olvassa."},
/* it */ {IDGS_MON_BLOAD_DESCRIPTION_IT, "Carica il file specificato in memoria all'indirizzo specificato.\nSe la periferica e 0, il file e letto dal file system."},
/* ko */ {IDGS_MON_BLOAD_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BLOAD_DESCRIPTION_NL, "Laad het opgegeven bestand naar het geheugen met het opgegeven adres.\nAls het apparaat 0 is dan zal het bestand van het bestandssysteem\nworden geladen."},
/* pl */ {IDGS_MON_BLOAD_DESCRIPTION_PL, "Wczytaj dany plik do pamieci w okre��lonym adresie.\nJe��li urz�}dzenie to 0, plik jest czytany z systemu plikow."},
/* ru */ {IDGS_MON_BLOAD_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BLOAD_DESCRIPTION_SV, "Las den angivna filen till minnet pa den angivna adressen.\nOm enheten ar 0 lases filen fran filsystemet."},
/* tr */ {IDGS_MON_BLOAD_DESCRIPTION_TR, "Belirtilmit dosyayy belirtilen adresten itibaren bellede yukle.\nAygyt 0 ise, dosya dosya sistemi uzerinden okunur."},
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
/* pl */ {IDGS_TRACK_PL, "track"},
/* ru */ {IDGS_TRACK_RU, ""},  /* fuzzy */
/* sv */ {IDGS_TRACK_SV, "spar"},
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
/* pl */ {IDGS_SECTOR_PL, "sector"},
/* ru */ {IDGS_SECTOR_RU, ""},  /* fuzzy */
/* sv */ {IDGS_SECTOR_SV, "sektor"},
/* tr */ {IDGS_SECTOR_TR, "sektor"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BLOCK_READ_DESCRIPTION,    N_("Read the block at the specified track and sector.  If an address is\nspecified, the data is loaded into memory.  If no address is given, the\ndata is displayed using the default datatype.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BLOCK_READ_DESCRIPTION_DA, "Laser en blok fra det angivne spor og sektor. Hvis en adresse angives\nindlases data til hukommelsen. Hvis der ikke angives nogen adresse vises\nindholdet med standarddatatypen."},
/* de */ {IDGS_MON_BLOCK_READ_DESCRIPTION_DE, "Lese den Block von angegebener Spur und Sektor. Wenn eine Adresse\nangegeben wurde, lade in auf die entsprechende Adresse. Wenn keine Adresse\nangegeben ist, zeige die Daten im aktuellen Anzeigemodus fur Daten."},
/* fr */ {IDGS_MON_BLOCK_READ_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BLOCK_READ_DESCRIPTION_HU, "Blokk beolvasasa a megadott savbol es szektorbol.,  Ha egy cim is meg\nvan adva, az adatot a memoriaba tolti.  Ha az nincs, az\nadatot az alapbeallitas szerinti formaban mutatja."},
/* it */ {IDGS_MON_BLOCK_READ_DESCRIPTION_IT, "Legge il blocco dalla traccia e settore specificati. Se e specificato\nun indirizzo, il dato e caricato in memoria. Se non e specificato alcun\nindirizzo, il dato e mostrato usando il tipo di dato predefinito."},
/* ko */ {IDGS_MON_BLOCK_READ_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BLOCK_READ_DESCRIPTION_NL, "Lees het blok van de opgegeven spoor en sector. Als er een adres is\nopgegeven dan zal de data naar dat adres in geheugen worden geladen.\nAls er geen adres is opgegeven dan zal de data worder getoond met de\nhuidige datasoort."},
/* pl */ {IDGS_MON_BLOCK_READ_DESCRIPTION_PL, "Czytaj blok z danej ��cie?ki i sektora. Je��li okre��lono adres, dane s�}\nwczytywane do pamieci. Je��li nie podano adresu, dane s�} pokazane\nw domy��lnym typie danych."},
/* ru */ {IDGS_MON_BLOCK_READ_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BLOCK_READ_DESCRIPTION_SV, "Laser blocket pa det angivna sparet och sektorn. Om du anger en\nadress lases data till minnet. Om du inte anger nagon adress visas\ninnehallet enligt standarddatatypen."},
/* tr */ {IDGS_MON_BLOCK_READ_DESCRIPTION_TR, "Belirtilmit track ve sektordeki blodu oku.  Eder bir adres belirtilmitse,\nveri bellede yuklenir.  Eder adres belirtilmemitse, veri varsayylan veri\ntipi kullanylarak goruntulenir."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BSAVE_DESCRIPTION,    N_("Save the memory from address1 to address2 to the specified file.\nIf device is 0, the file is written to the file system.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BSAVE_DESCRIPTION_DA, "Gem hukommelsen fra adresse1 til adresse2 til den angivne fil.\nHvis enhed er 0 skrives til filsystemet."},
/* de */ {IDGS_MON_BSAVE_DESCRIPTION_DE, "Speichere den Speicherinhalt von Adresse1 zu Adresse2 in die angegebene Datei.\nWenn das Gerat 0 angegeben wurde, speichere im Dateisystem."},
/* fr */ {IDGS_MON_BSAVE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BSAVE_DESCRIPTION_HU, "A memoria cim1 es cim2 kozotti reszenek fajlba mentese.\nHa az eszkoz 0, a fajl a fajlrendszerbe kerul."},
/* it */ {IDGS_MON_BSAVE_DESCRIPTION_IT, "Salva la memoria compresa tra indirizzo1 e indirizzo2 sul file specificato.\nSe la periferica e 0, il file e scritto sul file system."},
/* ko */ {IDGS_MON_BSAVE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BSAVE_DESCRIPTION_NL, "Sla het geheugen tussen adres1 en adres2 op naar het opgegeven bestand.\nAls het apparaat 0 is dan zal het bestand naar het bestandssysteem worden\ngeschreven."},
/* pl */ {IDGS_MON_BSAVE_DESCRIPTION_PL, "Zapisz pamiea z adres1 do adres2 do okre��lonego pliku.\nJe��li urz�}dzenie to 0, plik jest zapisywany do systemu plikow."},
/* ru */ {IDGS_MON_BSAVE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BSAVE_DESCRIPTION_SV, "Spara minnet fran adress1 till adress2 till den angivna filen.\nOm enheten ar 0 skrivs filen till filsystemet."},
/* tr */ {IDGS_MON_BSAVE_DESCRIPTION_TR, "Adres1'den adres2'ye kadar olan belledi belirtilen dosyaya kaydet.\nEder aygyt 0 ise, dosya dosya sistemine yazylyr."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION,    N_("Write a block of data at `address' on the specified track and sector\nof disk in drive 8.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_DA, "Skriv datablok pa \"adresse\" til det angivne spor og sektor\npa disken i drev 8."},
/* de */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_DE, "Schreibe einen Datenblock von `Adresse' auf die angegebene Spure und Sektor\nin die Imagedatei von Laufwerk 8."},
/* fr */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_HU, "Egy adat blokk irasa `cim' helyrol a megadott savba es szektorba\na 8-as meghajton."},
/* it */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_IT, "Scrive il blocco di dati all'indirizzo sulla traccia e settore specificati\ndel disco nel drive 8."},
/* ko */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_NL, "Schrijf een data blok van `adres' naar de opgegeven spoor en sector van\nde disk in drive 8."},
/* pl */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_PL, "Zapisz blok danych w `address' w podanej ��cie?ce i sektorze\ndysku w stacji 8."},
/* ru */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_SV, "Skriv ett datablock pa \"adress\" till det angivna sparet och sektorn\npa disken i enhet 8."},
/* tr */ {IDGS_MON_BLOCK_WRITE_DESCRIPTION_TR, "Belirtilmit track ve sektorlerde `adres'te yer alan veri blodunu 8\nnumaraly surucudeki diske yaz."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_DIRECTORY,    N_("Directory")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_DIRECTORY_DA, "Katalog"},
/* de */ {IDGS_DIRECTORY_DE, "Verzeichnis"},
/* fr */ {IDGS_DIRECTORY_FR, "Repertoire"},
/* hu */ {IDGS_DIRECTORY_HU, ""},  /* fuzzy */
/* it */ {IDGS_DIRECTORY_IT, "Directory"},
/* ko */ {IDGS_DIRECTORY_KO, "��d�EoAa�CR"},
/* nl */ {IDGS_DIRECTORY_NL, "Directory"},
/* pl */ {IDGS_DIRECTORY_PL, "Katalog"},
/* ru */ {IDGS_DIRECTORY_RU, ""},  /* fuzzy */
/* sv */ {IDGS_DIRECTORY_SV, "Katalog"},
/* tr */ {IDGS_DIRECTORY_TR, "Dizin"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_P_DIRECTORY,    N_("<Directory>")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_P_DIRECTORY_DA, "<Katalog>"},
/* de */ {IDGS_P_DIRECTORY_DE, "<Verzeichnis>"},
/* fr */ {IDGS_P_DIRECTORY_FR, "<Repertoire>"},
/* hu */ {IDGS_P_DIRECTORY_HU, ""},  /* fuzzy */
/* it */ {IDGS_P_DIRECTORY_IT, "<Directory>"},
/* ko */ {IDGS_P_DIRECTORY_KO, "<��d�EoAa�CR>"},
/* nl */ {IDGS_P_DIRECTORY_NL, "<Directory>"},
/* pl */ {IDGS_P_DIRECTORY_PL, "<Katalog>"},
/* ru */ {IDGS_P_DIRECTORY_RU, ""},  /* fuzzy */
/* sv */ {IDGS_P_DIRECTORY_SV, "<Katalog>"},
/* tr */ {IDGS_P_DIRECTORY_TR, "<Dizin>"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_CD_DESCRIPTION,    N_("Change current working directory.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_CD_DESCRIPTION_DA, ""},  /* fuzzy */
/* de */ {IDGS_MON_CD_DESCRIPTION_DE, "Arbeitsverzeichnis andern."},
/* fr */ {IDGS_MON_CD_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_CD_DESCRIPTION_HU, ""},  /* fuzzy */
/* it */ {IDGS_MON_CD_DESCRIPTION_IT, ""},  /* fuzzy */
/* ko */ {IDGS_MON_CD_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_CD_DESCRIPTION_NL, "Verander de huidige werk directory"},
/* pl */ {IDGS_MON_CD_DESCRIPTION_PL, "Zmien obecny katalog roboczy"},
/* ru */ {IDGS_MON_CD_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_CD_DESCRIPTION_SV, "Andra aktuell arbetskatalog"},
/* tr */ {IDGS_MON_CD_DESCRIPTION_TR, ""},  /* fuzzy */
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DETACH_DESCRIPTION,    N_("Detach file from device. (device 32 = cart)")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DETACH_DESCRIPTION_DA, "Frakobl filen fra enheden. (enhed 32 = cartridge)"},
/* de */ {IDGS_MON_DETACH_DESCRIPTION_DE, "Entferne Datei von Gerat. (Gerat 32 = Modul)"},
/* fr */ {IDGS_MON_DETACH_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DETACH_DESCRIPTION_HU, "Fajl levalasztasa az eszkozrol. (32-es eszkoz = cart)"},
/* it */ {IDGS_MON_DETACH_DESCRIPTION_IT, "Rimuovi il file dalla periferica. (periferica 32 = cart)"},
/* ko */ {IDGS_MON_DETACH_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DETACH_DESCRIPTION_NL, "Ontkoppel bestand van apparaat. (apparaat 32 = cart)"},
/* pl */ {IDGS_MON_DETACH_DESCRIPTION_PL, "Od3�}cz plik od urz�}dzenia (urz�}dzenie 32 = cart)"},
/* ru */ {IDGS_MON_DETACH_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DETACH_DESCRIPTION_SV, "Koppla fran filen fran enheten. (enhet 32 = insticksmodul)"},
/* tr */ {IDGS_MON_DETACH_DESCRIPTION_TR, "Aygyttan dosya cykart. (aygyt 32 = kartut)"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DIR_DESCRIPTION,    N_("Display the directory contents.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DIR_DESCRIPTION_DA, "Vis katalogets indhold."},
/* de */ {IDGS_MON_DIR_DESCRIPTION_DE, "Zeige den Verzeichnisinhalt."},
/* fr */ {IDGS_MON_DIR_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DIR_DESCRIPTION_HU, "A konyvtar tartalmanak mutatasa."},
/* it */ {IDGS_MON_DIR_DESCRIPTION_IT, "Mostra il contenuto della directory."},
/* ko */ {IDGS_MON_DIR_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DIR_DESCRIPTION_NL, "Toon de directory inhoud."},
/* pl */ {IDGS_MON_DIR_DESCRIPTION_PL, "Poka? zawarto��a katalogu."},
/* ru */ {IDGS_MON_DIR_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DIR_DESCRIPTION_SV, "Visa katalogens innehall."},
/* tr */ {IDGS_MON_DIR_DESCRIPTION_TR, "Dizin iceridini goruntule."},
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
/* pl */ {IDGS_MON_LIST_DESCRIPTION_PL, "Poka? zawarto��a dysku"},
/* ru */ {IDGS_MON_LIST_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_LIST_DESCRIPTION_SV, "Visa diskens innehall"},
/* tr */ {IDGS_MON_LIST_DESCRIPTION_TR, "Disk iceridini listele."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_LOAD_DESCRIPTION,    N_("Load the specified file into memory at the specified address. Set BASIC\npointers appropriately if loaded into computer memory (not all emulators).\nUse (otherwise ignored) two-byte load address from file if no address\nspecified.\nIf device is 0, the file is read from the file system.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_LOAD_DESCRIPTION_DA, "Indlas filen i hukommelsen pa den angivne adresse. Opdaterer\nBASIC-pointers ved lasning til computerens hukommelse (ikke alle\nemulatorer). Hvis ingen adresse angives bruges load-adressen fra(som ellers ignoreres).\nHvis enhed er 0 lases fra filsystemet."},
/* de */ {IDGS_MON_LOAD_DESCRIPTION_DE, "Lade die angegebene Datei in den Speicher auf die angegebene Adresse.\nSetze den BASIC Zeiger entsprechend, wenn in den Rechnerspeicher geladen \nwurde (nicht bei allen Emulatoren!).\nVerwende (sonst ignoriert) die zwei-Byte Lade-Adresse aus der Datei, wenn\nkeine Adresse angegeben wurde.\nBei Gerat 0, wird die Datei vom Dateisystem gelade."},
/* fr */ {IDGS_MON_LOAD_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_LOAD_DESCRIPTION_HU, "A megadott fajl betoltese a megadott cimre. A BASIC mutatokat\na megfelelo modon beallitja, ha a szamitogep memoriaba tolti az adatot\n(nem minden emulatornal). Ha nincs cim megadva, az amugy figyelmen hagyott\nket bajtos betoltesi cimet hasznalja a fajlbol.\nHa az eszkoz 0, a fajlt a fajlrendszerrol olvassa."},
/* it */ {IDGS_MON_LOAD_DESCRIPTION_IT, "Carica il file specificato in memroia all'indirizzo specificato. Imposta\ni puntatori del BASIC in modo appropriato se caricato nella memoria\ndel computer (non su tutti gli emulatori).\nUsa (altrimenti ignora) l'indirizzo di caricamento su due byte del file\nse non viene specificato alcun indirizzo.\nSe la periferica e 0, il file viene letto dal file system."},
/* ko */ {IDGS_MON_LOAD_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_LOAD_DESCRIPTION_NL, "Laad het opgegeven bestand naar geheugen op het opgegeven adres. Zet de BASIC\nstart en eind indicators correct als het bestand naar het computer geheugen\ngeladen wordt (niet alle emulatoren). De eerste twee bytes van het bestand\nzullen als laad adres worden gebruikt als er geen adres is opgegeven. Als\nhet apparaat 0 is dan zal het bestand van het bestandssysteem worden geladen."},
/* pl */ {IDGS_MON_LOAD_DESCRIPTION_PL, "Wczytaj podany plik do pamieci w konkretnym adresie. Ustaw wska?niki\nBASIC odpowiednio, jesli zostan�} wczytane do pamieci komputera\n(nie wszystkie emulatory). U?yj (w innym razie ignoruje) dwubajtowego\nadresu wczytywania z pliku, je��li nie zosta3 podany adres.\nJe��li urz�}dzenie jest 0, plik zostaje oczytany z systemu plikow."},
/* ru */ {IDGS_MON_LOAD_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_LOAD_DESCRIPTION_SV, "Las in den angivna filen i minnet pa den angivna adressen. Satter\nmotsvarande BASIC-pekare vid lasning till datorminnet (inte alla\nemulatorer). Om ingen adress anges anvands tvabytesadressen i filen(ignoreras annars).\nOm enheten ar 0 lases filen fran filsystemet."},
/* tr */ {IDGS_MON_LOAD_DESCRIPTION_TR, "Belirtilmit dosyayy belirtilen adresten itibaren bellede yukle. Eder\nbilgisayar belledine yuklenmitse BASIC imleclerini uygun bir bicimde\nayarla (tum emulatorlerde dedil). Eder adres belirtilmemitse iki bytelyk\ndosya yukleme adresini kullan (dider ihtimalde yoksay).\nEder aygyt 0 ise, dosya dosya sisteminden okunur."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_PWD_DESCRIPTION,    N_("Show current working directory.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_PWD_DESCRIPTION_DA, "Vis aktuelt arbejdskatalog."},
/* de */ {IDGS_MON_PWD_DESCRIPTION_DE, "Zeige aktuelles Arbeitsverzeichnis."},
/* fr */ {IDGS_MON_PWD_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_PWD_DESCRIPTION_HU, "Munkakonyvtar mutatasa."},
/* it */ {IDGS_MON_PWD_DESCRIPTION_IT, "Mostra la directory di lavoro attuale."},
/* ko */ {IDGS_MON_PWD_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_PWD_DESCRIPTION_NL, "Toon de huidige werk directory."},
/* pl */ {IDGS_MON_PWD_DESCRIPTION_PL, "Poka? obecny katalog roboczy."},
/* ru */ {IDGS_MON_PWD_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_PWD_DESCRIPTION_SV, "Visa aktuell arbetskatalog."},
/* tr */ {IDGS_MON_PWD_DESCRIPTION_TR, "Gecerli calytma dizinini goster."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_SAVE_DESCRIPTION,    N_("Save the memory from address1 to address2 to the specified file.\nWrite two-byte load address.\nIf device is 0, the file is written to the file system.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_SAVE_DESCRIPTION_DA, "Gem hukommelsen fra  adresse1 til adresse2 til den angivne fil.\nSkriv 2-byte loadadresse i starten af filen.\nHvis enhed er 0 skrives til filsystemet."},
/* de */ {IDGS_MON_SAVE_DESCRIPTION_DE, "Speichere den Speicher von Adresse1 bis Adresse2 in die angegebene Datei.\nSchreibe eine zwei-Byte Lade Adresse.\nBei Gerat 0, wird dei Datei in das Dateisystem geschrieben."},
/* fr */ {IDGS_MON_SAVE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_SAVE_DESCRIPTION_HU, "A memoria cim1 es cim2 kozotti tartomanyanak fajlba mentese.\nA ketbajtos betoltesi cimet is kiirja.\nHa az eszkoz 0, a fajlt a fajlrendszeren hozza letre."},
/* it */ {IDGS_MON_SAVE_DESCRIPTION_IT, "Salva la memoria compresa tra indirizzo1 e indirizzo2 sul file\nspecificato.\nScrive l'indirizzo di caricamento su due byte.\nSe la periferica e 0, il file e scritto sul file system."},
/* ko */ {IDGS_MON_SAVE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_SAVE_DESCRIPTION_NL, "Sla het geheugen tussen adres1 en adres2 op naar het opgegeven bestand.\nSchrijf een load adres van twee bytes.\nAls het apparaat 0 is dan zal het bestand geschreven worden naar het\nbestandssysteem."},
/* pl */ {IDGS_MON_SAVE_DESCRIPTION_PL, "Zapisz pamiea od address1 do address2 do podanego pliku.\nZapisz dwubajtowy adres wczytania.\nJe��li urz�}dzenie jest 0, plik zostaje zapisany do systemu plikow."},
/* ru */ {IDGS_MON_SAVE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_SAVE_DESCRIPTION_SV, "Spara minnet fran adress1 till adress2 till den angivna filen.\nSkriv tvabytes inlasningsadress.\nOm enheten ar 0 skrivs filen till filsystemet."},
/* tr */ {IDGS_MON_SAVE_DESCRIPTION_TR, "Adres1'den adres2'ye kadar olan belledi belirtilen dosyaya kaydet.\nYki bytelyk yukeme adresini yaz.\nEder aygyt 0 ise, dosya dosya sistemine yazylyr."},
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
/* pl */ {IDGS_OTHER_COMMANDS_PL, "Pozosta3e polecenia:"},
/* ru */ {IDGS_OTHER_COMMANDS_RU, ""},  /* fuzzy */
/* sv */ {IDGS_OTHER_COMMANDS_SV, "Andra kommandon:"},
/* tr */ {IDGS_OTHER_COMMANDS_TR, "Dider komutlar:"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION,    N_("Display the specified number in decimal, hex, octal and binary.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_DA, "Vis det angivne tal som decimal, hexadecimal, oktal og binart."},
/* de */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_DE, "Zeige die angegebene Zahl in dezimal, hexadezimal, oktal oder binar."},
/* fr */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_HU, "A megadott szam kiirasa decimalisan, hexadecimalisan, oktalisan es binarisan."},
/* it */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_IT, "Mostra il numero specificato in decimale, esadecimale, ottale e binario."},
/* ko */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_NL, "Toon het opgegeven nummer in decimaal, hex, octaal en binair."},
/* pl */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_PL, "Poka? dan�} liczbe w systemie dziesietnym, szesnastkowym, osemkowym i binarnym."},
/* ru */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_SV, "Visa det angivna talet decimalt, hexadecimalt, oktalt och binart."},
/* tr */ {IDGS_MON_DISPLAY_NUMBER_DESCRIPTION_TR, "Belirtilen sayyyy 10'lu, 16'ly, 8'li ya da 2'li olarak goruntule."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_CARTFREEZE_DESCRIPTION,    N_("Use cartridge freeze.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_CARTFREEZE_DESCRIPTION_DA, "Brug cartridge frys-funktion."},
/* de */ {IDGS_MON_CARTFREEZE_DESCRIPTION_DE, "Erweiterungsmodul Freeze benutzen."},
/* fr */ {IDGS_MON_CARTFREEZE_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_CARTFREEZE_DESCRIPTION_HU, "Cartridge fagyasztas hasznalata."},
/* it */ {IDGS_MON_CARTFREEZE_DESCRIPTION_IT, "Usa freeze della cartuccia."},
/* ko */ {IDGS_MON_CARTFREEZE_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_CARTFREEZE_DESCRIPTION_NL, "Gebruik cartridge freeze."},
/* pl */ {IDGS_MON_CARTFREEZE_DESCRIPTION_PL, "U?yj zamro?enia kartrid?a"},
/* ru */ {IDGS_MON_CARTFREEZE_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_CARTFREEZE_DESCRIPTION_SV, "Anvand insticksmodulens frysfunktion."},
/* tr */ {IDGS_MON_CARTFREEZE_DESCRIPTION_TR, "Kartut freeze kullan"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_HELP_DESCRIPTION,    N_("If no argument is given, prints out a list of all available commands\nIf an argument is given, prints out specific help for that command.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_HELP_DESCRIPTION_DA, "Hvis der ikke angives et argument vises en liste over mulige kommandoer.\nAngives et argument vises hjalp for denne kommando."},
/* de */ {IDGS_MON_HELP_DESCRIPTION_DE, "Wenn kein Argement angegeben wurde, werden alle Kommandos ausgegeben.\nMit Argument, zeige die Hilfe fur das angegebene Kommand."},
/* fr */ {IDGS_MON_HELP_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_HELP_DESCRIPTION_HU, "Ha nincs parameter, az osszes letezo parancs listajat mutatja.\nHa van, az adott parancshoz mutatja a sugot."},
/* it */ {IDGS_MON_HELP_DESCRIPTION_IT, "Se non viene specificato alcun argomeno, stamapa la lista di tutti i\ncomandi disponibili.\nSe viene specificato un argomento, stampa l'aiuto relativo a quel\ncomando."},
/* ko */ {IDGS_MON_HELP_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_HELP_DESCRIPTION_NL, "Als er geen parameter is opgegeven dan zal een lijst van alle commandos\nworden weergegeven. Als er een parameter is opgegeven dan zal de help voor\nhet opgegeven command worden weergegeven."},
/* pl */ {IDGS_MON_HELP_DESCRIPTION_PL, "Je��li nie jest podany argument, pokazuje liste dostepnych polecen.\nJe��li zosta3 podany argument, pokazuje pomoc do tego polecenia."},
/* ru */ {IDGS_MON_HELP_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_HELP_DESCRIPTION_SV, "Om du inte anger nagra argument visas alla tillgangliga kommandon.\nOm du anger ett argument visas hjalp for det specifika kommandot."},
/* tr */ {IDGS_MON_HELP_DESCRIPTION_TR, "Eder hic arguman verilmemitse, tum mevcut komutlaryn listesi yazdyrylyr\nEder bir arguman verilmitse, o komuta ozel yardym bilgisi yazdyrylyr."},
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
/* pl */ {IDGS_STRING_PL, "string"},
/* ru */ {IDGS_STRING_RU, ""},  /* fuzzy */
/* sv */ {IDGS_STRING_SV, "strang"},
/* tr */ {IDGS_STRING_TR, "yazy"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_KEYBUF_DESCRIPTION,    N_("Put the specified string into the keyboard buffer.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_KEYBUF_DESCRIPTION_DA, "Indsat den angivne streng i tastatur-bufferen."},
/* de */ {IDGS_MON_KEYBUF_DESCRIPTION_DE, "Definierte Eingabe in Tastaturpuffer bereitstellen."},
/* fr */ {IDGS_MON_KEYBUF_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_KEYBUF_DESCRIPTION_HU, "A megadott sztring elhelyezese a billentyuzet pufferben."},
/* it */ {IDGS_MON_KEYBUF_DESCRIPTION_IT, "Metti la stringa specificata nel buffer di tastiera."},
/* ko */ {IDGS_MON_KEYBUF_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_KEYBUF_DESCRIPTION_NL, "Plaats de opgegeven string in de toetsenbordbuffer."},
/* pl */ {IDGS_MON_KEYBUF_DESCRIPTION_PL, "Umie��a dany ci�}g znakow w buforze klawiatury."},
/* ru */ {IDGS_MON_KEYBUF_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_KEYBUF_DESCRIPTION_SV, "Lagg den angivna strangen i tangentbordsbufferten."},
/* tr */ {IDGS_MON_KEYBUF_DESCRIPTION_TR, "Klavye arabelledine belirtilen yazyyy koy."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_PLAYBACK_DESCRIPTION,    N_("Monitor commands from the specified file are read and executed.  This\ncommand stops at the end of file or when a STOP command is read.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_PLAYBACK_DESCRIPTION_DA, "Monitorkommandoer indlases fra den angivne fil og udfores. Kommandoen\nstopper nar slutningen af filen nas, eller nar der opdages en STOP-kommando."},
/* de */ {IDGS_MON_PLAYBACK_DESCRIPTION_DE, "Monitor Kommandos aus der angegebenen Datei werden gelesen und ausgefuhrt.\nDieses Kommando stoppt, wenn das Ende der Datei erreicht wurde, oder das\nKommando STOP gelesen wurde."},
/* fr */ {IDGS_MON_PLAYBACK_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_PLAYBACK_DESCRIPTION_HU, "A monitor parancsokat beolvassa es vegrehajtja a megadott fajlbol.\nA fajl vegeig halad, vagy egy beolvasott STOP parancsig."},
/* it */ {IDGS_MON_PLAYBACK_DESCRIPTION_IT, "I comandi del monitor sono letti ed eseguiti dal file specificato. Questo\ncomando si arresta alla fine del file o quando viene letto il comando\nSTOP."},
/* ko */ {IDGS_MON_PLAYBACK_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_PLAYBACK_DESCRIPTION_NL, "Monitor commandos van het opgegeven bestand zullen worden gelezen en\nuitgevoerd. Dit commando stopt aan het einde van het bestand of wanneer\neen STOP commando wordt gelezen."},
/* pl */ {IDGS_MON_PLAYBACK_DESCRIPTION_PL, "Polecenia monitora z podanego pliku s�} odczytywane i wykonywane.\nTa komenda zatrzymuje sie na koncu pliku, b�}d? przy odczycie komendy STOP."},
/* ru */ {IDGS_MON_PLAYBACK_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_PLAYBACK_DESCRIPTION_SV, "Monitorkommandon lases in och kors fran den angivna filen. Kommandot\nstoppar vid filslut eller nar ett STOP-kommando lases."},
/* tr */ {IDGS_MON_PLAYBACK_DESCRIPTION_TR, "Belirtilen dosyadaki monitor komutlary okundu ve calyttyryldy.  Bu\nkomut dosya sonunda ya da STOP komutu okundudunda sonlanyr."},
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
/* pl */ {IDGS_EXPRESSION_PL, "expression"},
/* ru */ {IDGS_EXPRESSION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_EXPRESSION_SV, "uttryck"},
/* tr */ {IDGS_EXPRESSION_TR, "ifade"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_PRINT_DESCRIPTION,    N_("Evaluate the specified expression and output the result.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_PRINT_DESCRIPTION_DA, "Evaluer det angivne udtryk og vis resultatet."},
/* de */ {IDGS_MON_PRINT_DESCRIPTION_DE, "Evaluiere den angegebenen Ausdruck und zeige das Ergebnis."},
/* fr */ {IDGS_MON_PRINT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_PRINT_DESCRIPTION_HU, "Kiertekeli a megadott kifejezest es kiirja az eredmenyt."},
/* it */ {IDGS_MON_PRINT_DESCRIPTION_IT, "Calcola l'espressione specificata e mostra il risultato."},
/* ko */ {IDGS_MON_PRINT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_PRINT_DESCRIPTION_NL, "Evalueer de opgegeven expressie en toon het resultaat."},
/* pl */ {IDGS_MON_PRINT_DESCRIPTION_PL, "Oszacuj okre��lone wyra?enie i podaj rezultat."},
/* ru */ {IDGS_MON_PRINT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_PRINT_DESCRIPTION_SV, "Utvardera det angivna uttrycket och visa resultatet."},
/* tr */ {IDGS_MON_PRINT_DESCRIPTION_TR, "Belirtilen ifadeyi dederlendir ve sonucun cyktysyny ver."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_RECORD_DESCRIPTION,    N_("After this command, all commands entered are written to the specified\nfile until the STOP command is entered.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_RECORD_DESCRIPTION_DA, "Efter denne kommando skrives alle kommandoer til den angivne fil,\nindtil der angives en STOP-kommando."},
/* de */ {IDGS_MON_RECORD_DESCRIPTION_DE, "Nach diesem Kommando werden alle eingebenen Kommands in die angegebene\nDatei gespeicher solang bis das Kommando STOP eingegeben wurde."},
/* fr */ {IDGS_MON_RECORD_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_RECORD_DESCRIPTION_HU, "Ezutan a parancs utan az osszes parancsot a megadott fajlba\nirja, amig STOP parancs nem erkezik."},
/* it */ {IDGS_MON_RECORD_DESCRIPTION_IT, "Dopo questo comando, tutti i comandi inseriti saranno scritti sul file\nspecificato fino a quando verra inserito il comando STOP."},
/* ko */ {IDGS_MON_RECORD_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_RECORD_DESCRIPTION_NL, "Na dit commando zullen alle opgegeven commandos worden geschreven naar\nhet opgegeven bestand totdat het STOP command wordt opgegeven."},
/* pl */ {IDGS_MON_RECORD_DESCRIPTION_PL, "Po tym poleceniu wszystkie wprowadzone polecenia s�} zapisywane\ndo podanego pliku, poki nie zostanie wprowadzone polecenie STOP."},
/* ru */ {IDGS_MON_RECORD_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_RECORD_DESCRIPTION_SV, "Efter detta kommando kommer alla kommandon som anges att skrivas till\nden angivna filen tills ett STOP-kommando anges."},
/* tr */ {IDGS_MON_RECORD_DESCRIPTION_TR, "Bu komuttan sonra, tum girilen komutlar ve STOP komutunu gorene dek\nbelirtilen dosyaya yazylacaktyr."},
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
/* pl */ {IDGS_RESOURCE_PL, "resource"},
/* ru */ {IDGS_RESOURCE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_RESOURCE_SV, "resurs"},
/* tr */ {IDGS_RESOURCE_TR, "kaynak"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_RESOURCEGET_DESCRIPTION,    N_("Displays the value of the resource.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_RESOURCEGET_DESCRIPTION_DA, "Viser vardien for ressourcen."},
/* de */ {IDGS_MON_RESOURCEGET_DESCRIPTION_DE, "Zeige den Werde der Ressource."},
/* fr */ {IDGS_MON_RESOURCEGET_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_RESOURCEGET_DESCRIPTION_HU, "Az eroforras ertekenek kiirasa."},
/* it */ {IDGS_MON_RESOURCEGET_DESCRIPTION_IT, "Mostra il valore della risorsa."},
/* ko */ {IDGS_MON_RESOURCEGET_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_RESOURCEGET_DESCRIPTION_NL, "Toont de waarde van de resource."},
/* pl */ {IDGS_MON_RESOURCEGET_DESCRIPTION_PL, "Pokazuje warto��a zasobu"},
/* ru */ {IDGS_MON_RESOURCEGET_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_RESOURCEGET_DESCRIPTION_SV, "Visar vardet for resursen."},
/* tr */ {IDGS_MON_RESOURCEGET_DESCRIPTION_TR, "Kaynadyn dederini goruntuler."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_VALUE,    N_("value")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_VALUE_DA, "vardi"},
/* de */ {IDGS_VALUE_DE, "Wert"},
/* fr */ {IDGS_VALUE_FR, ""},  /* fuzzy */
/* hu */ {IDGS_VALUE_HU, ""},  /* fuzzy */
/* it */ {IDGS_VALUE_IT, "valore"},
/* ko */ {IDGS_VALUE_KO, "��!A!"},
/* nl */ {IDGS_VALUE_NL, "waarde"},
/* pl */ {IDGS_VALUE_PL, "warto��a"},
/* ru */ {IDGS_VALUE_RU, ""},  /* fuzzy */
/* sv */ {IDGS_VALUE_SV, "varde"},
/* tr */ {IDGS_VALUE_TR, "deder"},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_RESOURCESET_DESCRIPTION,    N_("Sets the value of the resource.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_RESOURCESET_DESCRIPTION_DA, "Satter vardien for ressourcen."},
/* de */ {IDGS_MON_RESOURCESET_DESCRIPTION_DE, "Setze den Werde der Ressource."},
/* fr */ {IDGS_MON_RESOURCESET_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_RESOURCESET_DESCRIPTION_HU, "Az eroforras ertekenek beallitasa."},
/* it */ {IDGS_MON_RESOURCESET_DESCRIPTION_IT, "Imposta il valore della risorsa."},
/* ko */ {IDGS_MON_RESOURCESET_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_RESOURCESET_DESCRIPTION_NL, "Plaats de waarde in de resource."},
/* pl */ {IDGS_MON_RESOURCESET_DESCRIPTION_PL, "Ustawia warto��a zasobu."},
/* ru */ {IDGS_MON_RESOURCESET_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_RESOURCESET_DESCRIPTION_SV, "Staller in ett varde for resursen."},
/* tr */ {IDGS_MON_RESOURCESET_DESCRIPTION_TR, "Kaynadyn dederini belirler."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_STOP_DESCRIPTION,    N_("Stop recording commands.  See `record'.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_STOP_DESCRIPTION_DA, "Afslut optagelse. Se \"record\"."},
/* de */ {IDGS_MON_STOP_DESCRIPTION_DE, "Stoppe die Aufnahme von Kommandos. Siehe auch `Record'."},
/* fr */ {IDGS_MON_STOP_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_STOP_DESCRIPTION_HU, "A parancsok rogzitesenek befejezese.  Lasd `record'"},
/* it */ {IDGS_MON_STOP_DESCRIPTION_IT, "Ferma il comando di registrazione. Guarda `registra'."},
/* ko */ {IDGS_MON_STOP_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_STOP_DESCRIPTION_NL, "Stop de opname van commandos. Zie 'record'."},
/* pl */ {IDGS_MON_STOP_DESCRIPTION_PL, "Przestan zapisywaa polecenia. Zobacz `record'."},
/* ru */ {IDGS_MON_STOP_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_STOP_DESCRIPTION_SV, "Sluta spela in kommandon. Se \"record\"."},
/* tr */ {IDGS_MON_STOP_DESCRIPTION_TR, "Kayyt komutlaryny durdur.  `record'a bak."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_SCREENSHOT_DESCRIPTION,    N_("Take a screenshot. Format is:\ndefault = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_SCREENSHOT_DESCRIPTION_DA, "Gem et screenshot. Format er:\nstandard = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* de */ {IDGS_MON_SCREENSHOT_DESCRIPTION_DE, "Erzeuge Screenshot. Format ist:\nStandard = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* fr */ {IDGS_MON_SCREENSHOT_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_SCREENSHOT_DESCRIPTION_HU, "Kepernyokep keszitese. A formatum lehet:\nalap = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* it */ {IDGS_MON_SCREENSHOT_DESCRIPTION_IT, "Cattura schermo. Il formato e:\npredefinito = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* ko */ {IDGS_MON_SCREENSHOT_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_SCREENSHOT_DESCRIPTION_NL, "Sla een schermafdruk op. Formaat is:\nstandaard = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* pl */ {IDGS_MON_SCREENSHOT_DESCRIPTION_PL, "Zrob zrzut ekranu. Format:\ndomy��lny = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* ru */ {IDGS_MON_SCREENSHOT_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_SCREENSHOT_DESCRIPTION_SV, "Ta en skarmbild. Format ar:\nstandard = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
/* tr */ {IDGS_MON_SCREENSHOT_DESCRIPTION_TR, "Ekran goruntusu al. Bicim:\nvarsayylan = BMP, 1 = PCX, 2 = PNG, 3 = GIF, 4 = IFF."},
#endif

/* monitor/mon_command.c */
/* en */ {IDGS_MON_TAPECTRL_DESCRIPTION,    N_("Control the datasette. Valid commands:\n0 = stop, 1 = start, 2 = forward, 3 = rewind, 4 = record,\n5 = reset, 6 = reset counter.")},
#ifdef HAS_TRANSLATION
/* da */ {IDGS_MON_TAPECTRL_DESCRIPTION_DA, "Styr datasette. Lovlige kommandoer:\n0 = stop, 1 = start, 2 = spol frem, 3 = spol tilbage,\n4 = optag, 5 = reset, 6 = nulstil taller."},
/* de */ {IDGS_MON_TAPECTRL_DESCRIPTION_DE, "Steuere die Datasette. Gultige Kommandos sind:\n0 = Stop, 1 = Start, 2 = Forwarts, 3 = Ruckwarts, 4 = Aufnahme,\n5 = Reset, 6 = Reset Zahler."},
/* fr */ {IDGS_MON_TAPECTRL_DESCRIPTION_FR, ""},  /* fuzzy */
/* hu */ {IDGS_MON_TAPECTRL_DESCRIPTION_HU, "Szalagos egyseg vezerlese. Ervenyes parancsok:\n0 = start, 1 = indit, 2 = elore, 3 = vissza, 4 = felvetel,\n5 = ujraindit, 6 = szamlalot nullaz"},
/* it */ {IDGS_MON_TAPECTRL_DESCRIPTION_IT, "Controlla il registratore. Comandi validi:\n0 = ferma, 1 = avvia, 2 = avanti, 3 = indietro, 4 = registra,\n5 = reset, 6 = reset contatore."},
/* ko */ {IDGS_MON_TAPECTRL_DESCRIPTION_KO, ""},  /* fuzzy */
/* nl */ {IDGS_MON_TAPECTRL_DESCRIPTION_NL, "Geef datasette commandos. Geldige commandos:\n0 = stop, 1 = start, 2 = vooruit, 3 = terug, 4 = opnemen,\n5 = reset, 6 = reset teller."},
/* pl */ {IDGS_MON_TAPECTRL_DESCRIPTION_PL, "Kontrola magnetofonu. W3a��ciwe polecenia:\n0 = stop, 1 = start, 2 = naprzod, 3 = przewin, 4 = nagrywaj,\n5 = reset, 6 = reset licznika."},
/* ru */ {IDGS_MON_TAPECTRL_DESCRIPTION_RU, ""},  /* fuzzy */
/* sv */ {IDGS_MON_TAPECTRL_DESCRIPTION_SV, "Styr bandspelaren. Giltiga kommandon:\n0 = stoppa, 1 = starta, 2 = spola framat, 3 = spola bakat,\n4 = spela in, 5 = aterstall, 6 = nollstall raknare."},
/* tr */ {IDGS_MON_TAPECTRL_DESCRIPTION_TR, "Teybi kontrol et. Gecerli komutlar:\n0 = durdur, 1 = batlat, 2 = ileri, 3 = geri, 4 = kayyt,\n5 = reset, 6 = reset sayacy."},
#endif

/* ------------------------ COMMAND LINE OPTION STRINGS -------------------- */

/* autostart.c */
/* en */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START,    N_("On autostart, load to BASIC start (without ',1')")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_DA, "Indlas til BASIC start ved autostart (uden ',1')"},
/* de */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_DE, "Bei Autostart, lade an BASIC Start (ohne ',1')"},
/* fr */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_HU, ""},  /* fuzzy */
/* it */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_IT, "All'avvio automatico, carica all'inizio del BASIC (senza ',1')"},
/* ko */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_NL, "Bij autostarten, laad naar BASIC start (zonder ',1')"},
/* pl */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_PL, "Przy autostarcie wczytuj do BASIC-a (bez ',1')"},
/* ru */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_SV, "Vid autostart, hamta till BASIC-start (utan \",1\")"},
/* tr */ {IDCLS_AUTOSTART_LOAD_TO_BASIC_START_TR, "Otomatik batlatyldydynda, BASIC batlangycyna yukle (',1' olmadan)"},
#endif

/* autostart.c */
/* en */ {IDCLS_AUTOSTART_LOAD_WITH_1,    N_("On autostart, load with ',1'")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_AUTOSTART_LOAD_WITH_1_DA, "Indlas med ',1' ved autostart"},
/* de */ {IDCLS_AUTOSTART_LOAD_WITH_1_DE, "Bei Autostart, lade mit ',1'"},
/* fr */ {IDCLS_AUTOSTART_LOAD_WITH_1_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_AUTOSTART_LOAD_WITH_1_HU, ""},  /* fuzzy */
/* it */ {IDCLS_AUTOSTART_LOAD_WITH_1_IT, "All'avvio automatico, carica con ',1'"},
/* ko */ {IDCLS_AUTOSTART_LOAD_WITH_1_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_AUTOSTART_LOAD_WITH_1_NL, "Bij autostarten, laad met ',1'"},
/* pl */ {IDCLS_AUTOSTART_LOAD_WITH_1_PL, "Przy autostarcie wczytuj z ',1'"},
/* ru */ {IDCLS_AUTOSTART_LOAD_WITH_1_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_AUTOSTART_LOAD_WITH_1_SV, "Vid autostart, hamta med \",1\""},
/* tr */ {IDCLS_AUTOSTART_LOAD_WITH_1_TR, "Otomatik batlatyldydynda, ',1' ile yukle"},
#endif

/* autostart.c */
/* en */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON,    N_("On autostart, use the 'RUN' command with a colon, i.e., 'RUN:'")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_DA, "Brug \"RUN\"-kommando med kolon ved autostart, dvs. \"RUN:\""},
/* de */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_DE, "Bei Autostart soll 'RUN' mit Doppelpunkt ausgefuhrt werden ('RUN:')"},
/* fr */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_HU, "Automatikus inditasnal a 'RUN' parancs kettosponttal, vagyis 'RUN:'"},
/* it */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_IT, "All'avvio automatico, usa il comando 'RUN' con i due punti; cioe 'RUN:'"},
/* ko */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_NL, "Bij het autostarten, gebruik het 'RUN' commando met een dubbele punt, dus 'RUN:'"},
/* pl */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_PL, "Przy autostarcie u?ywaj polecenia 'RUN' z dwukropkiem, tj. 'RUN:'"},
/* ru */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_SV, "Vid autostart, anvand \"RUN\"-kommando med kolon, dvs. \"RUN:\""},
/* tr */ {IDCLS_ENABLE_AUTOSTARTWITHCOLON_TR, "Otomatik batlatyldydynda, 'RUN' komutunu ':' ile kullan, yani, 'RUN:'"},
#endif

/* autostart.c */
/* en */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON,    N_("On autostart, do not use the 'RUN' command with a colon; i.e., 'RUN'")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_DA, "Brug ikke \"RUN\"-kommando med kolon ved autostart, dvs. \"RUN\""},
/* de */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_DE, "Bei Autostart soll 'RUN' ohne Doppelpunkt ausgefuhrt werden ('RUN')"},
/* fr */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_HU, "Automatikus inditasnak a 'RUN' parancs kettospont nelkul, vagyis 'RUN'"},
/* it */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_IT, "All'avvio automatico, non usare il comando 'RUN' con i due punti; cioe 'RUN'"},
/* ko */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_NL, "Bij het autostarten, gebruik het 'RUN' commando niet met een dubbele punt, dus 'RUN'"},
/* pl */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_PL, "Przy autostarcie u?ywaj polecenia 'RUN' bez dwukropka, tj. 'RUN'"},
/* ru */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_SV, "Vid autostart, anvand inte \"RUN\"-kommando med kolon, dvs. \"RUN\""},
/* tr */ {IDCLS_DISABLE_AUTOSTARTWITHCOLON_TR, "Otomatik batlatyldydynda, 'RUN' komutunu ':' ile kullanma, yani, 'RUN'"},
#endif

/* autostart.c */
/* en */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE,    N_("Handle True Drive Emulation on autostart")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_DA, "Anvend agte drev-emulering ved autostart"},
/* de */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_DE, "Prazise Floppy Emulation bei Autostart beachten"},
/* fr */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_HU, "Valos lemezegyseg emulacio kezelese autostartnal"},
/* it */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_IT, "Emulazione hardware dei drive all'avvio automatico"},
/* ko */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_NL, "Manipuleer hardwarematige drive emulatie bij autostarten"},
/* pl */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_PL, "W3�}cz rzeczywist�} emulacje napedu przy autostarcie"},
/* ru */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_SV, "Hantera akta diskettenhetsemulering vid autostart"},
/* tr */ {IDCLS_ENABLE_AUTOSTART_HANDLE_TDE_TR, "Otomatik batlatmada Gercek Surucu Emulasyonu'nu denetle"},
#endif

/* autostart.c */
/* en */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE,    N_("Do not handle True Drive Emulation on autostart")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_DA, "Anvend ikke agte drev-emulering ved autostart"},
/* de */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_DE, "Prazise Floppy Emulation bei Autostart nicht beachten"},
/* fr */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_HU, "Valos lemezegyseg emulaciot nem kezeli autostartnal"},
/* it */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_IT, "Non gestire l'emulazione hardware dei drive all'avvio automatico"},
/* ko */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_NL, "Geen manipulatie van de hardwarematige drive emulatie bij autostarten"},
/* pl */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_PL, "Nie w3�}czaj rzeczywistej emulacji napedu przy autostarcie"},
/* ru */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_SV, "Hantera inte akta diskettenhetsemulering vid autostart"},
/* tr */ {IDCLS_DISABLE_AUTOSTART_HANDLE_TDE_TR, "Batlangycta Gercek Surucu Emulasyonu'nu Denetleme"},
#endif

/* autostart.c */
/* en */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART,    N_("Enable warp mode during autostart")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_DA, "Aktiver warp-tilstand under autostart"},
/* de */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_DE, "Warp Mode wahrend Autostart aktivieren"},
/* fr */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_HU, "Hipergyors mod engedelyezese autostartnal"},
/* it */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_IT, "Attiva la modalita turbo all'avvio automatico"},
/* ko */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_NL, "Activeer warp modus tijdens autostarten"},
/* pl */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_PL, "W3�}cz tryb przy��pieszony podczas automatycznego startu"},
/* ru */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_SV, "Aktivera warplage for autostart"},
/* tr */ {IDCLS_ENABLE_WARP_MODE_AUTOSTART_TR, "Otomatik batlatma esnasynda warp modu aktif et"},
#endif

/* autostart.c */
/* en */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART,    N_("Disable warp mode during autostart")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_DA, "Deaktiver warp-tilstand under autostart"},
/* de */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_DE, "Warp Mode wahren Autostart deaktivieren"},
/* fr */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_HU, "Hipergyors mod tiltasa autostartnal"},
/* it */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_IT, "Disattiva la modalita turbo all'avvio automatico"},
/* ko */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_NL, "Warp modus tijdens autostarten uitschakelen"},
/* pl */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_PL, "Wy3�}cz tryb przy��pieszony podczas automatycznego startu"},
/* ru */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_SV, "Inaktivera warplage for autostart"},
/* tr */ {IDCLS_DISABLE_WARP_MODE_AUTOSTART_TR, "Otomatik batlatma esnasynda warp modu pasiflettir"},
#endif

/* autostart.c */
/* en */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG,    N_("Set autostart mode for PRG files")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_DA, "Valg autostart-tilstand for PRG-filer"},
/* de */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_DE, "Autstart Modus fur PRG Dateien definieren"},
/* fr */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_HU, "Automatikus inditas modja PRG fajloknal"},
/* it */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_IT, "Imposta avvio automatico per i file PRG"},
/* ko */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_NL, "Zet autostart modus voor PRG bestanden"},
/* pl */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_PL, "Okre��l tryb autostartu z plikow PRG"},
/* ru */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_SV, "Valj autostartlage for PRG-filer"},
/* tr */ {IDCLS_SET_AUTOSTART_MODE_FOR_PRG_TR, "PRG dosyalary icin otomatik batlatma ayarla"},
#endif

/* autostart.c */
/* en */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG,    N_("Set disk image for autostart of PRG files")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_DA, "Valg diskimage for autostart af PRG-filer"},
/* de */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_DE, "Disk Imagedatei fur Autstart definieren"},
/* fr */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_HU, "Lmeez kepmas megadasa PRG automatikus inditashoz"},
/* it */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_IT, "Imposta immagine disco per l'avvio automatico dei file PRG"},
/* ko */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_NL, "Zet disk bestand voor het autostarten van PRG bestanden"},
/* pl */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_PL, "Okre��l obraz dysku do autostartu z plikow PRG"},
/* ru */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_SV, "Ange diskavbildning for autostart av PRG-filer"},
/* tr */ {IDCLS_SET_DISK_IMAGE_FOR_AUTOSTART_PRG_TR, "PRG dosyalarynyn otomatik batlatylmasy icin disk imajy ayarla"},
#endif

/* autostart.c */
/* en */ {IDCLS_SET_AUTOSTART_DELAY,    N_("Set initial autostart delay (0: use default)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_AUTOSTART_DELAY_DA, ""},  /* fuzzy */
/* de */ {IDCLS_SET_AUTOSTART_DELAY_DE, "Setze initiale Autostart Verzogerung (0: benutze Standard)"},
/* fr */ {IDCLS_SET_AUTOSTART_DELAY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_AUTOSTART_DELAY_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_AUTOSTART_DELAY_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_SET_AUTOSTART_DELAY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_AUTOSTART_DELAY_NL, ""},  /* fuzzy */
/* pl */ {IDCLS_SET_AUTOSTART_DELAY_PL, "Okre��l pocz�}tkowe opo?nienie autostartu (0: domy��lne)"},
/* ru */ {IDCLS_SET_AUTOSTART_DELAY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_AUTOSTART_DELAY_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_SET_AUTOSTART_DELAY_TR, ""},  /* fuzzy */
#endif

/* autostart.c */
/* en */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY,    N_("Enable random initial autostart delay.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_DE, "Zufalle Verzogerung wahrend Autostart aktivieren,"},
/* fr */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_NL, "Activeer willekeurige vertraging bij begin van het autostarten."},
/* pl */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_PL, "W3�}cz losowe opo?nienie na pocz�}tku autostartu."},
/* ru */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_ENABLE_AUTOSTART_RANDOM_DELAY_TR, ""},  /* fuzzy */
#endif

/* autostart.c */
/* en */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY,    N_("Disable random initial autostart delay.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_DA, ""},  /* fuzzy */
/* de */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_DE, "Zufalle Verzogerung wahrend Autostart deaktivieren."},
/* fr */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_NL, "Willekeurige vertraging bij begin van het uitostarten uitschakelen."},
/* pl */ {IDCLS_DISABLE_AUTOSTART_RANDOM_DELAY_PL, "Wy3�}cz losowe opo?nienie na pocz�}tku autostartu."},
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
/* hu */ {IDCLS_USE_PAL_SYNC_FACTOR_HU, "PAL szinkron faktor hasznalata"},
/* it */ {IDCLS_USE_PAL_SYNC_FACTOR_IT, "Usa fattore di sincronizzazione PAL"},
/* ko */ {IDCLS_USE_PAL_SYNC_FACTOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_PAL_SYNC_FACTOR_NL, "Gebruik PAL synchronisatiefaktor"},
/* pl */ {IDCLS_USE_PAL_SYNC_FACTOR_PL, "U?ywaj synchronizacji PAL"},
/* ru */ {IDCLS_USE_PAL_SYNC_FACTOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_PAL_SYNC_FACTOR_SV, "Anvand PAL-synkfaktor"},
/* tr */ {IDCLS_USE_PAL_SYNC_FACTOR_TR, "PAL senkron faktoru kullan"},
#endif

/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c,
   c64/psid.c, plus4/plus4-cmdline-options.c,
   vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_USE_NTSC_SYNC_FACTOR,    N_("Use NTSC sync factor")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_NTSC_SYNC_FACTOR_DA, "Anvend NTSC-synkfaktor"},
/* de */ {IDCLS_USE_NTSC_SYNC_FACTOR_DE, "NTSC Sync Faktor benutzen"},
/* fr */ {IDCLS_USE_NTSC_SYNC_FACTOR_FR, "Utiliser NTSC"},
/* hu */ {IDCLS_USE_NTSC_SYNC_FACTOR_HU, "NTSC szinkron faktor hasznalata"},
/* it */ {IDCLS_USE_NTSC_SYNC_FACTOR_IT, "Usa fattore di sincronizzazione NTSC"},
/* ko */ {IDCLS_USE_NTSC_SYNC_FACTOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_NTSC_SYNC_FACTOR_NL, "Gebruik NTSC synchronisatiefaktor"},
/* pl */ {IDCLS_USE_NTSC_SYNC_FACTOR_PL, "U?ywaj synchronizacji NTSC"},
/* ru */ {IDCLS_USE_NTSC_SYNC_FACTOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_NTSC_SYNC_FACTOR_SV, "Anvand NTSC-synkfaktor"},
/* tr */ {IDCLS_USE_NTSC_SYNC_FACTOR_TR, "NTSC senkron faktoru kullan"},
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
/* pl */ {IDCLS_USE_PALN_SYNC_FACTOR_PL, "U?ywaj synchronizacji PAL-N"},
/* ru */ {IDCLS_USE_PALN_SYNC_FACTOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_PALN_SYNC_FACTOR_SV, "Anvand PAL N-synkfaktor"},
/* tr */ {IDCLS_USE_PALN_SYNC_FACTOR_TR, "PAL-N senkron faktoru kullan"},
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
/* hu */ {IDCLS_P_NAME_HU, "<Nev>"},
/* it */ {IDCLS_P_NAME_IT, "<Nome>"},
/* ko */ {IDCLS_P_NAME_KO, "<AI�C��>"},
/* nl */ {IDCLS_P_NAME_NL, "<Naam>"},
/* pl */ {IDCLS_P_NAME_PL, "<Nazwa>"},
/* ru */ {IDCLS_P_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_NAME_SV, "<Namn>"},
/* tr */ {IDCLS_P_NAME_TR, "<Ysim>"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_INT_KERNEL_NAME,    N_("Specify name of international Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_INT_KERNEL_NAME_DA, "Angiv navn pa internationalt kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_INT_KERNEL_NAME_DE, "Bitte Namen fur internationale Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_INT_KERNEL_NAME_FR, "Specifier le nom de l'image Kernal internationale"},
/* hu */ {IDCLS_SPECIFY_INT_KERNEL_NAME_HU, "Adja meg a nemzetkozi Kernal ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_INT_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal internazionale"},
/* ko */ {IDCLS_SPECIFY_INT_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_INT_KERNEL_NAME_NL, "Geef de naam van het internationaal Kernal ROM bestand"},
/* pl */ {IDCLS_SPECIFY_INT_KERNEL_NAME_PL, "Okre��l nazwe obrazu miedzynarodowego ROM Kernala"},
/* ru */ {IDCLS_SPECIFY_INT_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_INT_KERNEL_NAME_SV, "Ange namn pa internationell kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_INT_KERNEL_NAME_TR, "Uluslararasy Kernal ROM imajynyn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_DE_KERNEL_NAME,    N_("Specify name of German Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_DE_KERNEL_NAME_DA, "Angiv navn pa tysk kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_DE_KERNEL_NAME_DE, "Name fur deutsche Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_DE_KERNEL_NAME_FR, "Specifier le nom de l'image Kernal allemande"},
/* hu */ {IDCLS_SPECIFY_DE_KERNEL_NAME_HU, "Adja meg a nemet Kernal ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_DE_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal tedesca"},
/* ko */ {IDCLS_SPECIFY_DE_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_DE_KERNEL_NAME_NL, "Geef de naam van het Duitse Kernal ROM bestand"},
/* pl */ {IDCLS_SPECIFY_DE_KERNEL_NAME_PL, "Podaj nazwe obrazu niemieckiego ROM-u Kernala"},
/* ru */ {IDCLS_SPECIFY_DE_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_DE_KERNEL_NAME_SV, "Ange namn pa tysk kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_DE_KERNEL_NAME_TR, "Alman Kernal ROM imajynyn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_FI_KERNEL_NAME,    N_("Specify name of Finnish Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FI_KERNEL_NAME_DA, "Angiv navn pa finsk kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_FI_KERNEL_NAME_DE, "Name fur finnische Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_FI_KERNEL_NAME_FR, "Specifier le nom de l'image Kernal finlandaise"},
/* hu */ {IDCLS_SPECIFY_FI_KERNEL_NAME_HU, "Adja meg a finn Kernal ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_FI_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal finlandese"},
/* ko */ {IDCLS_SPECIFY_FI_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FI_KERNEL_NAME_NL, "Geef de naam van het Finse Kernal ROM bestand"},
/* pl */ {IDCLS_SPECIFY_FI_KERNEL_NAME_PL, "Okre��l nazwe obrazu finskiego ROM Kernala"},
/* ru */ {IDCLS_SPECIFY_FI_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FI_KERNEL_NAME_SV, "Ange namn pa finsk kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_FI_KERNEL_NAME_TR, "Finlandiya Kernal ROM imajynyn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_FR_KERNEL_NAME,    N_("Specify name of French Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FR_KERNEL_NAME_DA, "Angiv navn pa fransk kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_FR_KERNEL_NAME_DE, "Name fur franzosische Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_FR_KERNEL_NAME_FR, "Specifier le nom de l'image Kernal francaise"},
/* hu */ {IDCLS_SPECIFY_FR_KERNEL_NAME_HU, "Adja meg a francia Kernal ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_FR_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal francese"},
/* ko */ {IDCLS_SPECIFY_FR_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FR_KERNEL_NAME_NL, "Geef de naam van het Franse Kernal ROM bestand"},
/* pl */ {IDCLS_SPECIFY_FR_KERNEL_NAME_PL, "Okre��l nazwe obrazu francuskiego ROM Kernala"},
/* ru */ {IDCLS_SPECIFY_FR_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FR_KERNEL_NAME_SV, "Ange namn pa fransk kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_FR_KERNEL_NAME_TR, "Fransyz Kernal ROM imajynyn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_IT_KERNEL_NAME,    N_("Specify name of Italian Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_IT_KERNEL_NAME_DA, "Angiv navn pa italiensk kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_IT_KERNEL_NAME_DE, "Name fur italienische Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_IT_KERNEL_NAME_FR, "Specifier le nom de l'image Kernal italienne"},
/* hu */ {IDCLS_SPECIFY_IT_KERNEL_NAME_HU, "Adja meg az olasz Kernal ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_IT_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal italiana"},
/* ko */ {IDCLS_SPECIFY_IT_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_IT_KERNEL_NAME_NL, "Geef de naam van het Italiaanse Kernal ROM bestand"},
/* pl */ {IDCLS_SPECIFY_IT_KERNEL_NAME_PL, "Okre��l nazwe obrazu w3oskiego ROM Kernala"},
/* ru */ {IDCLS_SPECIFY_IT_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_IT_KERNEL_NAME_SV, "Ange namn pa italiensk kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_IT_KERNEL_NAME_TR, "Ytalyan Kernal ROM imajynyn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_NO_KERNEL_NAME,    N_("Specify name of Norwegian Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_NO_KERNEL_NAME_DA, "Angiv navn pa norsk kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_NO_KERNEL_NAME_DE, "Name fur norwegische Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_NO_KERNEL_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_NO_KERNEL_NAME_HU, "Adja meg a norveg Kernal ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_NO_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal norvegese"},
/* ko */ {IDCLS_SPECIFY_NO_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_NO_KERNEL_NAME_NL, "Geef de naam van het Noorse Kernal ROM bestand"},
/* pl */ {IDCLS_SPECIFY_NO_KERNEL_NAME_PL, "Okre��l nazwe obrazu norweskiego ROM Kernala"},
/* ru */ {IDCLS_SPECIFY_NO_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_NO_KERNEL_NAME_SV, "Ange namn pa norsk kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_NO_KERNEL_NAME_TR, "Norvec Kernal ROM imajynyn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_SV_KERNEL_NAME,    N_("Specify name of Swedish Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SV_KERNEL_NAME_DA, "Angiv navn pa svensk kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_SV_KERNEL_NAME_DE, "Name fur schwedische Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_SV_KERNEL_NAME_FR, "Specifier le nom de l'image Kernal suedoise"},
/* hu */ {IDCLS_SPECIFY_SV_KERNEL_NAME_HU, "Adja meg s sved Kernal ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_SV_KERNEL_NAME_IT, "Specifica il nome immagine della ROM del Kernal svedese"},
/* ko */ {IDCLS_SPECIFY_SV_KERNEL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SV_KERNEL_NAME_NL, "Geef de naam van het Zweedse Kernal ROM bestand"},
/* pl */ {IDCLS_SPECIFY_SV_KERNEL_NAME_PL, "Okre��l nazwe obrazu szwedzkiego ROM Kernala"},
/* ru */ {IDCLS_SPECIFY_SV_KERNEL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SV_KERNEL_NAME_SV, "Ange namn pa svensk kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_SV_KERNEL_NAME_TR, "Ysvec Kernal ROM imajynyn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW,    N_("Specify name of BASIC ROM image (lower part)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_DA, "Angiv navn pa BASIC ROM-image (lav del)"},
/* de */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_DE, "Namen fur Basic ROM Datei spezifizieren (unterer Teil)"},
/* fr */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_FR, "Specifier le nom de l'image BASIC ROM (partie basse)"},
/* hu */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_HU, "Adja meg a BASIC ROM kepmas nevet (also resz)"},
/* it */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_IT, "Specifica il nome immagine della ROM del BASIC (parte inferiore)"},
/* ko */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_NL, "Geef de naam van het BASIC ROM bestand (laag gedeelte)"},
/* pl */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_PL, "Okre��l nazwe obrazu ROM BASIC (ni?sza partia)"},
/* ru */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_SV, "Ange namn pa BASIC ROM-avbildning (nedre delen)"},
/* tr */ {IDCLS_SPECIFY_BASIC_ROM_NAME_LOW_TR, "BASIC ROM imajynyn (alt kysym) ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH,    N_("Specify name of BASIC ROM image (higher part)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_DA, "Angiv navn pa BASIC ROM-image (hoj del)"},
/* de */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_DE, "Namen fur Basic ROM Datei spezifizieren (oberer Teil)"},
/* fr */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_FR, "Specifier le nom de l'image BASIC ROM (partie haute)"},
/* hu */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_HU, "Adja meg a BASIC ROM kepmas nevet (felso resz)"},
/* it */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_IT, "Specifica il nome immagine della ROM del BASIC (parte superiore)"},
/* ko */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_NL, "Geef de naam van het BASIC ROM bestand (hoog gedeelte)"},
/* pl */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_PL, "Okre��l nazwe obrazu ROM BASIC (wy?sza partia)"},
/* ru */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_SV, "Ange namn pa BASIC ROM-avbildning (ovre delen)"},
/* tr */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HIGH_TR, "BASIC ROM imajynyn (ust kysym) ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME,    N_("Specify name of international character generator ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_DA, "Angiv navn pa internationalt tegngenerator-ROM-image"},
/* de */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_DE, "Name fur internationale Charakter ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_FR, "Specifier le nom de l'image du generateur de caracteres internationaux"},
/* hu */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_HU, "Adja meg a nemzetkozi karaktergenerator ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_IT, "Specifica il nome immagine della ROM del generatore di caratteri internazionale"},
/* ko */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_NL, "Geef de naam van het internationaal CHARGEN ROM bestand"},
/* pl */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_PL, "Okre��l nazwe obrazu ROM generatora znakow miedzynarodowych"},
/* ru */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_SV, "Ange namn pa internationell teckengenerator-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_INT_CHARGEN_ROM_NAME_TR, "Uluslararasy Karakter Olutturucu ROM imajynyn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME,    N_("Specify name of German character generator ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_DA, "Angiv navn pa tysk tegngenerator-ROM-image"},
/* de */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_DE, "Name fur deutsche Charakter ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_FR, "Specifier le nom de l'image du generateur de caracteres allemands"},
/* hu */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_HU, "Adja meg a nemet karaktergenerator ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_IT, "Specifica il nome immagine della ROM del generatore di caratteri tedesco"},
/* ko */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_NL, "Geef de naam van het Duitse CHARGEN ROM bestand"},
/* pl */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_PL, "Okre��l nazwe obrazu ROM generatora niemieckich znakow"},
/* ru */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_SV, "Ange namn pa tysk teckengenerator-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_DE_CHARGEN_ROM_NAME_TR, "Alman Karakter Olutturucu ROM imajynyn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME,    N_("Specify name of French character generator ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_DA, "Angiv navn pa fransk tegngenerator-ROM-image"},
/* de */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_DE, "Name fur franzosische Charakter ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_FR, "Specifier le nom de l'image du generateur de caracteres francais"},
/* hu */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_HU, "Adja meg a francia karaktergenerator ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_IT, "Specifica il nome immagine della ROM del generatore di caratteri francese"},
/* ko */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_NL, "Geef de naam van het Franse CHARGEN ROM bestand"},
/* pl */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_PL, "Okre��l nazwe obrazu ROM generatora francuskich znakow"},
/* ru */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_SV, "Ange namn pa fransk teckengenerator-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_FR_CHARGEN_ROM_NAME_TR, "Finlandiya Karakter Olutturucu ROM imajynyn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME,    N_("Specify name of Swedish character generator ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_DA, "Angiv navn pa svensk tegngenerator-ROM-image"},
/* de */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_DE, "Name fur schwedische Charakter ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_FR, "Specifier le nom de l'image du generateur de caracteres suedois"},
/* hu */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_HU, "Adja meg a sved karaktergenerator ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_IT, "Specifica il nome immagine della ROM del generatore di caratteri svedese"},
/* ko */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_NL, "Geef de naam van het Zweedse CHARGEN ROM bestand"},
/* pl */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_PL, "Okre��l nazwe obrazu ROM generatora szwedzkich znakow"},
/* ru */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_SV, "Ange namn pa svensk teckengenerator-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_SV_CHARGEN_ROM_NAME_TR, "Ysvec Karakter Olutturucu ROM imajynyn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME,    N_("Specify name of C64 mode Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_DA, "Angiv navn pa C64-kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_DE, "Name fur C64 Modus Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_FR, "Specifier le nom de l'image Kernal du mode C64"},
/* hu */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_HU, "Adja meg a C64 modu Kernal ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_IT, "Specifica il nome immagine della ROM del Kernal in modalita C64"},
/* ko */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_NL, "Geef de naam van het Kernal ROM bestand voor de C64 modus"},
/* pl */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_PL, "Okre��l nazwe obrazu ROM Kernala trybu C64"},
/* ru */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_SV, "Ange namn pa C64-kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_C64_MODE_KERNAL_NAME_TR, "C64 modu Kernal ROM imajynyn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME,    N_("Specify name of C64 mode BASIC ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_DA, "Angiv navn pa C64-BASIC-ROM-image"},
/* de */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_DE, "Name fur C64 Modus Basic ROM Datei spezifizieren"},
/* fr */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_FR, "Specifier le nom de l'image BASIC ROM du mode C64"},
/* hu */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_HU, "Adja meg a C64 modu BASIC ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_IT, "Specifica il nome immagine della ROM in modalita C64"},
/* ko */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_NL, "Geef de naam van het BASIC ROM bestand voor de C64 modus"},
/* pl */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_PL, "Okre��l nazwe obrazu ROM BASIC trybu C64"},
/* ru */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_SV, "Ange namn pa C64-BASIC-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_C64_MODE_BASIC_NAME_TR, "C64 modu BASIC ROM imajynyn ismini belirt"},
#endif

/* vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_ENABLE_OEM_JOY,    N_("Enable the OEM userport joystick adapter")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_OEM_JOY_DA, "Aktiver OEM brugerportjoystickadapter"},
/* de */ {IDCLS_ENABLE_OEM_JOY_DE, "OEM Userport Joystick Adapter aktivieren"},
/* fr */ {IDCLS_ENABLE_OEM_JOY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_OEM_JOY_HU, "OEM userport botkormany adapter engedelyezese"},
/* it */ {IDCLS_ENABLE_OEM_JOY_IT, "Attiva adattatore joystick OEM su userport"},
/* ko */ {IDCLS_ENABLE_OEM_JOY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_OEM_JOY_NL, "Activeer de OEM userport joystick adapter"},
/* pl */ {IDCLS_ENABLE_OEM_JOY_PL, "W3�}cz z3�}cze OEM userportu joysticka"},
/* ru */ {IDCLS_ENABLE_OEM_JOY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_OEM_JOY_SV, "Aktivera OEM-anvandarportspelportsadapter"},
/* tr */ {IDCLS_ENABLE_OEM_JOY_TR, "OEM userport joystick donutturucuyu aktif et"},
#endif

/* vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_DISABLE_OEM_JOY,    N_("Disable the OEM userport joystick adapter")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_OEM_JOY_DA, "Deaktiver OEM brugerportjoystickadapter"},
/* de */ {IDCLS_DISABLE_OEM_JOY_DE, "OEM Userport Joystick Adapter deaktivieren"},
/* fr */ {IDCLS_DISABLE_OEM_JOY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_OEM_JOY_HU, "OEM userport botkormany adapter tiltasa"},
/* it */ {IDCLS_DISABLE_OEM_JOY_IT, "Disattiva adattatore joystick OEM su userport"},
/* ko */ {IDCLS_DISABLE_OEM_JOY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_OEM_JOY_NL, "De OEM userport joystick adapter uitschakelen"},
/* pl */ {IDCLS_DISABLE_OEM_JOY_PL, "Wy3�}cz z3�}cze OEM userportu joysticka"},
/* ru */ {IDCLS_DISABLE_OEM_JOY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_OEM_JOY_SV, "Inaktivera OEM-anvandarportspelportsadapter"},
/* tr */ {IDCLS_DISABLE_OEM_JOY_TR, "OEM userport joystick donutturucuyu pasiflettir"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_ENABLE_IEE488,    N_("Enable the IEEE488 interface emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEE488_DA, "Aktiver emulering af IEEE488-interface"},
/* de */ {IDCLS_ENABLE_IEE488_DE, "IEEE488 Schnittstellen-Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_IEE488_FR, "Activer l'interface d'emulation IEEE488"},
/* hu */ {IDCLS_ENABLE_IEE488_HU, "IEEE488 interfesz emulacio engedelyezese"},
/* it */ {IDCLS_ENABLE_IEE488_IT, "Attiva emulazione interfaccia IEEE488"},
/* ko */ {IDCLS_ENABLE_IEE488_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEE488_NL, "Activeer de IEEE488 interface emulatie"},
/* pl */ {IDCLS_ENABLE_IEE488_PL, "W3�}cz emulacje interfejsu IEEE488"},
/* ru */ {IDCLS_ENABLE_IEE488_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEE488_SV, "Aktivera emulering av IEEE488-granssnitt"},
/* tr */ {IDCLS_ENABLE_IEE488_TR, "IEEE488 arabirim emulasyonunu aktif et"},
#endif

/* c128/c128-cmdline-options.c */
/* en */ {IDCLS_DISABLE_IEE488,    N_("Disable the IEEE488 interface emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEE488_DA, "Deaktiver emulering af IEEE488-interface"},
/* de */ {IDCLS_DISABLE_IEE488_DE, "IEEE488 Schnittstellen-Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEE488_FR, "Desactiver l'interface d'emulation IEEE488"},
/* hu */ {IDCLS_DISABLE_IEE488_HU, "IEEE488 interfesz emulacio tiltasa"},
/* it */ {IDCLS_DISABLE_IEE488_IT, "Disattiva emulazione interfaccia IEEE488"},
/* ko */ {IDCLS_DISABLE_IEE488_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEE488_NL, "De IEEE488 interface emulatie uitschakelen"},
/* pl */ {IDCLS_DISABLE_IEE488_PL, "Wy3�}cz emulacje interfejsu IEEE488"},
/* ru */ {IDCLS_DISABLE_IEE488_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEE488_SV, "Inaktivera emulering av IEEE488-granssnitt"},
/* tr */ {IDCLS_DISABLE_IEE488_TR, "IEEE488 arabirim emulasyonunu pasiflettir"},
#endif

/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c */
/* en */ {IDCLS_P_REVISION,    N_("<Revision>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_REVISION_DA, "<Udgave>"},
/* de */ {IDCLS_P_REVISION_DE, "<Revision>"},
/* fr */ {IDCLS_P_REVISION_FR, "<Revision>"},
/* hu */ {IDCLS_P_REVISION_HU, "<Valtozatszam>"},
/* it */ {IDCLS_P_REVISION_IT, "<Revisione>"},
/* ko */ {IDCLS_P_REVISION_KO, "<?oA?>"},
/* nl */ {IDCLS_P_REVISION_NL, "<Revisie>"},
/* pl */ {IDCLS_P_REVISION_PL, "<Wersja>"},
/* ru */ {IDCLS_P_REVISION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_REVISION_SV, "<Utgava>"},
/* tr */ {IDCLS_P_REVISION_TR, "<Revizyon>"},
#endif

/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c */
/* en */ {IDCLS_PATCH_KERNAL_TO_REVISION,    N_("Patch the Kernal ROM to the specified <revision>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PATCH_KERNAL_TO_REVISION_DA, "Patch kerne-ROM til den angivne <revision>"},
/* de */ {IDCLS_PATCH_KERNAL_TO_REVISION_DE, "Kernal ROM auf spezifizierte <Revision> verandern"},
/* fr */ {IDCLS_PATCH_KERNAL_TO_REVISION_FR, "Mettre a jour le ROM Kernal a la <revision> specifiee"},
/* hu */ {IDCLS_PATCH_KERNAL_TO_REVISION_HU, "A Kernal ROM atirasa adott <valtozatra>"},
/* it */ {IDCLS_PATCH_KERNAL_TO_REVISION_IT, "Fai il patch della ROM del Kernal alla <revisione> specificata"},
/* ko */ {IDCLS_PATCH_KERNAL_TO_REVISION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PATCH_KERNAL_TO_REVISION_NL, "Verbeter de Kernal ROM naar de opgegeven <revisie>"},
/* pl */ {IDCLS_PATCH_KERNAL_TO_REVISION_PL, "Za3ataj ROM Kernala do konkretnej <wersji>"},
/* ru */ {IDCLS_PATCH_KERNAL_TO_REVISION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PATCH_KERNAL_TO_REVISION_SV, "Patcha kernal-ROM till angiven <utgava>"},
/* tr */ {IDCLS_PATCH_KERNAL_TO_REVISION_TR, "Kernal ROM'u belirtilmit <revizyon>'a yama"},
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
/* pl */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU_PL, "W3�}cz emulacje interfejsu ACIA RS232"},
/* ru */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DEXX_ACIA_RS232_EMU_SV, "Aktivera ACIA RS232-granssnittsemulering"},
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
/* pl */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_PL, "Wy3�}cz emulacje interfejsu ACIA RS232"},
/* ru */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_SV, "Inaktivera ACIA-RS232-granssnittsemulering"},
/* tr */ {IDCLS_DISABLE_DEXX_ACIA_RS232_EMU_TR, ""},  /* fuzzy */
#endif
#endif

/* plus4/plus4acia.c */
/* en */ {IDCLS_ENABLE_ACIA_EMU,    N_("Enable the ACIA emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_ACIA_EMU_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ENABLE_ACIA_EMU_DE, "ACIA Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_ACIA_EMU_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_ACIA_EMU_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_ACIA_EMU_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ENABLE_ACIA_EMU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_ACIA_EMU_NL, "Activeer de ACIA emulatie"},
/* pl */ {IDCLS_ENABLE_ACIA_EMU_PL, "W3�}cz emulacje ACIA"},
/* ru */ {IDCLS_ENABLE_ACIA_EMU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_ACIA_EMU_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_ENABLE_ACIA_EMU_TR, ""},  /* fuzzy */
#endif

/* plus4/plus4acia.c */
/* en */ {IDCLS_DISABLE_ACIA_EMU,    N_("Disable the ACIA emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_ACIA_EMU_DA, ""},  /* fuzzy */
/* de */ {IDCLS_DISABLE_ACIA_EMU_DE, "ACIA Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_ACIA_EMU_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_ACIA_EMU_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_ACIA_EMU_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_DISABLE_ACIA_EMU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_ACIA_EMU_NL, "De ACIA emulatie uitschakelen"},
/* pl */ {IDCLS_DISABLE_ACIA_EMU_PL, "Wy3�}cz emulacje ACIA"},
/* ru */ {IDCLS_DISABLE_ACIA_EMU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_ACIA_EMU_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_DISABLE_ACIA_EMU_TR, ""},  /* fuzzy */
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
/* ko */ {IDCLS_P_NUMBER_KO, "<?yAU>"},
/* nl */ {IDCLS_P_NUMBER_NL, "<nummer>"},
/* pl */ {IDCLS_P_NUMBER_PL, "<numer>"},
/* ru */ {IDCLS_P_NUMBER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_NUMBER_SV, "<nummer>"},
/* tr */ {IDCLS_P_NUMBER_TR, "<sayy>"},
#endif

#ifdef COMMON_KBD
/* c128/c128-cmdline-options.c, plus4/plus4-cmdline-options.c,
   vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX,    N_("Specify index of keymap file (0=symbol, 1=positional)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_DA, "Angiv indeks for tastaturindstillingsfil (0=symbolsk, 1=positionsbestemt)"},
/* de */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_DE, "Index fur Kymap Datei festlegen (0=symbol, 1=positional)"},
/* fr */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_FR, "Specifier l'index du fichier keymap (0=symboles, 1=position)"},
/* hu */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_HU, "Adja meg a billentyuzet lekepzesi modot (0=szimbolikus, 1=pozicio szerinti)"},
/* it */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_IT, "Specifica l'indice del file della mappa della tastiera (0=simbolica, 1=posizionale)"},
/* ko */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_NL, "Geef index van het keymapbestand (0=symbool, 1=positioneel)"},
/* pl */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_PL, "Podaj indeks uk3adu klawiatury (0=symbol, 1=pozycja)"},
/* ru */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_SV, "Ange index for for tangentbordsinstallningsfil (0=symbolisk, 1=positionsriktig)"},
/* tr */ {IDCLS_SPECIFY_KEYMAP_FILE_INDEX_TR, "Tut haritasy dosyasynyn indeksini belirt (0=sembol, 1=konumsal)"},
#endif

/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c,
   plus4/plus4-cmdline-options.c, vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME,    N_("Specify name of symbolic keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_DA, "Angiv filnavn for symbolsk tastatur"},
/* de */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_DE, "Bitte Namen fur symbolische Keymap Datei definieren"},
/* fr */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_FR, "Specifier le nom du fichier de mappage clavier symbolique"},
/* hu */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_HU, "Adja meg a szimbolikus lekepzesfajl nevet"},
/* it */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_IT, "Specifica il nome del file della mappa simbolica della tastiera"},
/* ko */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_NL, "Geef naam van het symbolisch keymapbestand"},
/* pl */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_PL, "Okre��l nazwe pliku symbolicznego uk3adu klawiatury"},
/* ru */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_SV, "Ange fil for symbolisk tangentbordsemulering"},
/* tr */ {IDCLS_SPECIFY_SYM_KEYMAP_FILE_NAME_TR, "Sembolik tut haritasy dosyasynyn ismini belirt"},
#endif

/* c128/c128-cmdline-options.c, c64/c64-cmdline-options.c,
   plus4/plus4-cmdline-options.c, vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME,    N_("Specify name of positional keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_DA, "Angiv fil for positionsbestemt tastatur"},
/* de */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_DE, "Bitte Namen fur positions Keymap Datei definieren"},
/* fr */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_FR, "Specifier le nom du fichier de mappage clavier positionnel"},
/* hu */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_HU, "Adja meg a pozicio szerinti lekepzesfajl nevet"},
/* it */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_IT, "Specifica il nome del file della mappa posizionale della tastiera"},
/* ko */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_NL, "Geef naam van het positioneel keymapbestand"},
/* pl */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_PL, "Okre��l nazwe pliku pozycyjnego uk3adu klawiatury"},
/* ru */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_SV, "Ange fil for positionsriktig tangentbordsemulering"},
/* tr */ {IDCLS_SPECIFY_POS_KEYMAP_FILE_NAME_TR, "Konumsal tut haritasy dosyasynyn ismini belirt"},
#endif
#endif

/* c128/c128mmu.c */
/* en */ {IDCLS_ACTIVATE_40_COL_MODE,    N_("Activate 40 column mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ACTIVATE_40_COL_MODE_DA, "Aktiver 40-kolonners tilstand"},
/* de */ {IDCLS_ACTIVATE_40_COL_MODE_DE, "40 Spalten Modus aktivieren"},
/* fr */ {IDCLS_ACTIVATE_40_COL_MODE_FR, "Activer le mode 40 colonnes"},
/* hu */ {IDCLS_ACTIVATE_40_COL_MODE_HU, "40 oszlopos mod aktivalasa"},
/* it */ {IDCLS_ACTIVATE_40_COL_MODE_IT, "Attiva modalita a 40 colonne"},
/* ko */ {IDCLS_ACTIVATE_40_COL_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ACTIVATE_40_COL_MODE_NL, "Activeer 40 kolomsmodus"},
/* pl */ {IDCLS_ACTIVATE_40_COL_MODE_PL, "W3�}cz tryb 40 kolumn"},
/* ru */ {IDCLS_ACTIVATE_40_COL_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ACTIVATE_40_COL_MODE_SV, "Aktivera 40-kolumnerslage"},
/* tr */ {IDCLS_ACTIVATE_40_COL_MODE_TR, "40 sutun modunu aktif et"},
#endif

/* c128/c128mmu.c */
/* en */ {IDCLS_ACTIVATE_80_COL_MODE,    N_("Activate 80 column mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ACTIVATE_80_COL_MODE_DA, "Aktiver 80-kolonners tilstand"},
/* de */ {IDCLS_ACTIVATE_80_COL_MODE_DE, "80 Spalten Modus aktivieren"},
/* fr */ {IDCLS_ACTIVATE_80_COL_MODE_FR, "Activer le mode 80 colonnes"},
/* hu */ {IDCLS_ACTIVATE_80_COL_MODE_HU, "80 oszlopos mod aktivalasa"},
/* it */ {IDCLS_ACTIVATE_80_COL_MODE_IT, "Attiva modalita a 80 colonne"},
/* ko */ {IDCLS_ACTIVATE_80_COL_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ACTIVATE_80_COL_MODE_NL, "Activeer 80 kolomsmodus"},
/* pl */ {IDCLS_ACTIVATE_80_COL_MODE_PL, "W3�}cz tryb 80 kolumn"},
/* ru */ {IDCLS_ACTIVATE_80_COL_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ACTIVATE_80_COL_MODE_SV, "Aktivera 80-kolumnerslage"},
/* tr */ {IDCLS_ACTIVATE_80_COL_MODE_TR, "80 sutun modunu aktif et"},
#endif

/* c128/c128mmu.c */
/* en */ {IDCLS_GO64_MODE,    N_("Always switch to C64 mode on reset")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_GO64_MODE_DA, "Skift altid til C64-tilstand ved reset"},
/* de */ {IDCLS_GO64_MODE_DE, "Immer bei Reset in C64 Modus schalten"},
/* fr */ {IDCLS_GO64_MODE_FR, "Toujours revenir au mode C64 au redemarrage"},
/* hu */ {IDCLS_GO64_MODE_HU, "Mindig C64 modban ujrainditas utan"},
/* it */ {IDCLS_GO64_MODE_IT, "Cambia sempre in modalita C64 al reset"},
/* ko */ {IDCLS_GO64_MODE_KO, "�LU?A?AAUCI�Ce C�~��o C64 �Cd��a �EI 1U2o�LI�LU"},
/* nl */ {IDCLS_GO64_MODE_NL, "Start altijd op in C64 modus na reset"},
/* pl */ {IDCLS_GO64_MODE_PL, "Przy restarcie zawsze prze3�}czaj w tryb C64"},
/* ru */ {IDCLS_GO64_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_GO64_MODE_SV, "Vaxla alltid till C64-lage vid aterstallning"},
/* tr */ {IDCLS_GO64_MODE_TR, "Resetlendidinde her zaman C64 moduna gec"},
#endif

/* c128/c128mmu.c */
/* en */ {IDCLS_GO128_MODE,    N_("Always switch to C128 mode on reset")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_GO128_MODE_DA, "Skift altid til C128-tilstand ved reset"},
/* de */ {IDCLS_GO128_MODE_DE, "Immer be Reset in C128 Modus schalten"},
/* fr */ {IDCLS_GO128_MODE_FR, "Toujours revenir au mode C128 au redemarrage"},
/* hu */ {IDCLS_GO128_MODE_HU, "Mindig C128 mod ujrainditas utan"},
/* it */ {IDCLS_GO128_MODE_IT, "Cambia sempre in modalita C128 al reset"},
/* ko */ {IDCLS_GO128_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_GO128_MODE_NL, "Start altijd op in C128 modus na reset"},
/* pl */ {IDCLS_GO128_MODE_PL, "Przy restarcie zawsze prze3�}czaj w tryb C128"},
/* ru */ {IDCLS_GO128_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_GO128_MODE_SV, "Vaxla alltid till C128-lage vid aterstallning"},
/* tr */ {IDCLS_GO128_MODE_TR, "Resetlendidinde her zaman C128 moduna gec"},
#endif

/* c128/functionrom.c */
/* en */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME,    N_("Specify name of internal Function ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_DA, "Angiv navn pa internt funktions-ROM-image"},
/* de */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_DE, "Name der internen Funktions ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_FR, "Specifier le nom de l'image ROM des fonctions internes"},
/* hu */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_HU, "Adja meg a belso Function ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_IT, "Specifica il nome immagine della Function ROM interna"},
/* ko */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_NL, "Geef de naam van het intern functie ROM bestand"},
/* pl */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_PL, "Okre��l nazwe obrazu ROM Internal Function"},
/* ru */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_SV, "Ange namn pa intern funktions-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_INT_FUNC_ROM_NAME_TR, "Dahili Function ROM imajynyn ismini belirt"},
#endif

/* c128/functionrom.c */
/* en */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME,    N_("Specify name of external Function ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_DA, "Angiv navn pa externt funktions-ROM-image"},
/* de */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_DE, "Name der externen Funktions ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_FR, "Specifier le nom de l'image ROM des fonctions externes"},
/* hu */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_HU, "Adja meg a kulso Function ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_IT, "Specifica il nome immagine della Function ROM esterna"},
/* ko */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_NL, "Geef de naam van het extern functie ROM bestand"},
/* pl */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_PL, "Okre��l nazwe obrazu ROM External Function"},
/* ru */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_SV, "Ange namn pa extern funktions-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_EXT_FUNC_ROM_NAME_TR, "Harici Function ROM imajynyn ismini belirt"},
#endif

/* c128/functionrom.c */
/* en */ {IDCLS_ENABLE_INT_FUNC_ROM,    N_("Enable the internal Function ROM")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_INT_FUNC_ROM_DA, "Aktiver intern funktions-ROM"},
/* de */ {IDCLS_ENABLE_INT_FUNC_ROM_DE, "Internes Funktions ROM aktivieren"},
/* fr */ {IDCLS_ENABLE_INT_FUNC_ROM_FR, "Activer l'image ROM des fonctions internes"},
/* hu */ {IDCLS_ENABLE_INT_FUNC_ROM_HU, "Belso Function ROM engedelyezese"},
/* it */ {IDCLS_ENABLE_INT_FUNC_ROM_IT, "Attiva la Function ROM interna"},
/* ko */ {IDCLS_ENABLE_INT_FUNC_ROM_KO, "AIAI3I Function ROM A�� ��c?e��!�LECI��O CI�}a"},
/* nl */ {IDCLS_ENABLE_INT_FUNC_ROM_NL, "Activeer de interne functie ROM"},
/* pl */ {IDCLS_ENABLE_INT_FUNC_ROM_PL, "W3�}cz wewnetrzn�} funkcje ROM"},
/* ru */ {IDCLS_ENABLE_INT_FUNC_ROM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_INT_FUNC_ROM_SV, "Aktivera internt funktions-ROM"},
/* tr */ {IDCLS_ENABLE_INT_FUNC_ROM_TR, "Dahili Function ROM'u aktif et"},
#endif

/* c128/functionrom.c */
/* en */ {IDCLS_DISABLE_INT_FUNC_ROM,    N_("Disable the internal Function ROM")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_INT_FUNC_ROM_DA, "Deaktiver intern funktions-ROM"},
/* de */ {IDCLS_DISABLE_INT_FUNC_ROM_DE, "Internes Funktions ROM deaktivieren"},
/* fr */ {IDCLS_DISABLE_INT_FUNC_ROM_FR, "Desactiver l'image ROM des fonctions internes"},
/* hu */ {IDCLS_DISABLE_INT_FUNC_ROM_HU, "Belso Function ROM tiltasa"},
/* it */ {IDCLS_DISABLE_INT_FUNC_ROM_IT, "Disattiva la Function ROM interna"},
/* ko */ {IDCLS_DISABLE_INT_FUNC_ROM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_INT_FUNC_ROM_NL, "De interne functie ROM uitschakelen"},
/* pl */ {IDCLS_DISABLE_INT_FUNC_ROM_PL, "Wy3�}cz ROM Internal Function"},
/* ru */ {IDCLS_DISABLE_INT_FUNC_ROM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_INT_FUNC_ROM_SV, "Inaktivera internt funktions-ROM"},
/* tr */ {IDCLS_DISABLE_INT_FUNC_ROM_TR, "Dahili Function ROM'u pasiflettir"},
#endif

/* c128/functionrom.c */
/* en */ {IDCLS_ENABLE_EXT_FUNC_ROM,    N_("Enable the external Function ROM")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_EXT_FUNC_ROM_DA, "Aktiver extern funktions-ROM"},
/* de */ {IDCLS_ENABLE_EXT_FUNC_ROM_DE, "Externes Funktions ROM aktivieren"},
/* fr */ {IDCLS_ENABLE_EXT_FUNC_ROM_FR, "Activer l'image ROM des fonctions externes"},
/* hu */ {IDCLS_ENABLE_EXT_FUNC_ROM_HU, "Kulso Function ROM engedelyezese"},
/* it */ {IDCLS_ENABLE_EXT_FUNC_ROM_IT, "Attiva la Function ROM esterna"},
/* ko */ {IDCLS_ENABLE_EXT_FUNC_ROM_KO, "?UoI Function ROM A�� ��c?e��!�LECI��O CI�}a"},
/* nl */ {IDCLS_ENABLE_EXT_FUNC_ROM_NL, "Activeer de externe functie ROM"},
/* pl */ {IDCLS_ENABLE_EXT_FUNC_ROM_PL, "W3�}cz zewnetrzn�} funkcje ROM"},
/* ru */ {IDCLS_ENABLE_EXT_FUNC_ROM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_EXT_FUNC_ROM_SV, "Aktivera externt funktions-ROM"},
/* tr */ {IDCLS_ENABLE_EXT_FUNC_ROM_TR, "Harici Function ROM'u aktif et"},
#endif

/* c128/functionrom.c */
/* en */ {IDCLS_DISABLE_EXT_FUNC_ROM,    N_("Disable the external Function ROM")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_EXT_FUNC_ROM_DA, "Deaktiver extern funktions-ROM"},
/* de */ {IDCLS_DISABLE_EXT_FUNC_ROM_DE, "Externes Funktions ROM deaktivieren"},
/* fr */ {IDCLS_DISABLE_EXT_FUNC_ROM_FR, "Desactiver l'image ROM des fonctions externes"},
/* hu */ {IDCLS_DISABLE_EXT_FUNC_ROM_HU, "Kulso Function ROM tiltasa"},
/* it */ {IDCLS_DISABLE_EXT_FUNC_ROM_IT, "Disattiva la Function ROM esterna"},
/* ko */ {IDCLS_DISABLE_EXT_FUNC_ROM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_EXT_FUNC_ROM_NL, "De externe functie ROM uitschakelen"},
/* pl */ {IDCLS_DISABLE_EXT_FUNC_ROM_PL, "Wy3�}cz ROM External Function"},
/* ru */ {IDCLS_DISABLE_EXT_FUNC_ROM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_EXT_FUNC_ROM_SV, "Inaktivera externt funktions-ROM"},
/* tr */ {IDCLS_DISABLE_EXT_FUNC_ROM_TR, "Harici Function ROM'u pasiflettir"},
#endif

/* c64/c64-cmdline-options.c, c64/psid.c */
/* en */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR,    N_("Use old NTSC sync factor")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_DA, "Anvend gammel NTSC-synkfaktor"},
/* de */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_DE, "Alten NTSC Sync Faktor verwenden"},
/* fr */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_FR, "Utiliser l'ancien mode NTSC"},
/* hu */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_HU, "Regi NTSC szinkron faktor hasznalata"},
/* it */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_IT, "Usa il vecchio fattore di sincronizzazione NTSC"},
/* ko */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_NL, "Gebruik oude NTSC synchronisatiefactor"},
/* pl */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_PL, "U?ywaj starej synchronizacji NTSC"},
/* ru */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_SV, "Anvand gammal NTSC-synkfaktor"},
/* tr */ {IDCLS_USE_OLD_NTSC_SYNC_FACTOR_TR, "Eski NTSC senkron faktoru kullan"},
#endif

/* c64/c64-cmdline-options.c, viciisc/vicii-cmdline-options.c */
/* en */ {IDCLS_P_MODEL,    N_("<Model>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_MODEL_DA, "<Model>"},
/* de */ {IDCLS_P_MODEL_DE, "<Modell>"},
/* fr */ {IDCLS_P_MODEL_FR, "<Modele>"},
/* hu */ {IDCLS_P_MODEL_HU, "<Modell>"},
/* it */ {IDCLS_P_MODEL_IT, "<Modello>"},
/* ko */ {IDCLS_P_MODEL_KO, "<�Cd�ʁN>"},
/* nl */ {IDCLS_P_MODEL_NL, "<Model>"},
/* pl */ {IDCLS_P_MODEL_PL, "<Model>"},
/* ru */ {IDCLS_P_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_MODEL_SV, "<Modell>"},
/* tr */ {IDCLS_P_MODEL_TR, "<Model>"},
#endif

/* c64/c64-cmdline-options.c */
/* en */ {IDCLS_SET_BOTH_CIA_MODELS,    N_("Set both CIA models (0 = old 6526, 1 = new 6526A)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_BOTH_CIA_MODELS_DA, "Valg type for begge CIA-kredse (0=gammel 6526, 1=ny 6526A)"},
/* de */ {IDCLS_SET_BOTH_CIA_MODELS_DE, "Wahle beide CIA Modelle (0 = alt 6526, 1 = neu 6526A)"},
/* fr */ {IDCLS_SET_BOTH_CIA_MODELS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_BOTH_CIA_MODELS_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_BOTH_CIA_MODELS_IT, "Imposta entrambi i modelli CIA (0 = 6526 vecchio, 1 = 6526A nuovo)"},
/* ko */ {IDCLS_SET_BOTH_CIA_MODELS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_BOTH_CIA_MODELS_NL, "Zet model voor beide CIAs (0 = oud 6526, 1 = nieuw 6526A)"},
/* pl */ {IDCLS_SET_BOTH_CIA_MODELS_PL, "Ustaw oba modele CIA (0 = stary 6526, 1 = nowy 6526A)"},
/* ru */ {IDCLS_SET_BOTH_CIA_MODELS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_BOTH_CIA_MODELS_SV, "Valj bada CIA-modellerna (0 = gammal 6526, 1 = ny 2526A)"},
/* tr */ {IDCLS_SET_BOTH_CIA_MODELS_TR, "Her iki CIA modelini belirle (0 = eski 6526, 1 = yeni 6526A)"},
#endif

/* c64/c64-cmdline-options.c */
/* en */ {IDCLS_SET_CIA1_MODEL,    N_("Set CIA 1 model (0 = old 6526, 1 = new 6526A)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_CIA1_MODEL_DA, "Valg CIA 1 type (0=gammel 6526, 1=ny 6526A)"},
/* de */ {IDCLS_SET_CIA1_MODEL_DE, "Wahle CIA 1 Modell (0 = alt 6526, 1 = neu 6526A)"},
/* fr */ {IDCLS_SET_CIA1_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_CIA1_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_CIA1_MODEL_IT, "Imposta modello CIA 1 (0 = 6526 vecchio, 1 = 6526A nuovo)"},
/* ko */ {IDCLS_SET_CIA1_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_CIA1_MODEL_NL, "Zet CIA 1 model (0 = oud 6526, 1 = nieuw 6526A)"},
/* pl */ {IDCLS_SET_CIA1_MODEL_PL, "Ustaw model CIA 1 (0 = stary 6526, 1 = nowy 6526A)"},
/* ru */ {IDCLS_SET_CIA1_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_CIA1_MODEL_SV, "Valj CIA 1-modell (0 = gammal 6526, 1 = ny 2526A)"},
/* tr */ {IDCLS_SET_CIA1_MODEL_TR, "CIA 1 modelini belirle (0 = eski 6526, 1 = yeni 6526A)"},
#endif

/* c64/c64-cmdline-options.c */
/* en */ {IDCLS_SET_CIA2_MODEL,    N_("Set CIA 2 model (0 = old 6526, 1 = new 6526A)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_CIA2_MODEL_DA, "Valg CIA 2 type (0=gammel 6526, 1=ny 6526A)"},
/* de */ {IDCLS_SET_CIA2_MODEL_DE, "Wahle CIA 2 Modell (0 = alt 6526, 1 = neu 6526A)\""},
/* fr */ {IDCLS_SET_CIA2_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_CIA2_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_CIA2_MODEL_IT, "Imposta modello CIA 2 (0 = 6526 vecchio, 1 = 6526A nuovo)"},
/* ko */ {IDCLS_SET_CIA2_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_CIA2_MODEL_NL, "Zet CIA 2 model (0 = oud 6526, 1 = nieuw 6526A)"},
/* pl */ {IDCLS_SET_CIA2_MODEL_PL, "Ustaw model CIA 2 (0 = stary 6526, 1 = nowy 6526A)"},
/* ru */ {IDCLS_SET_CIA2_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_CIA2_MODEL_SV, "Valj CIA 2-modell (0 = gammal 6526, 1 = ny 2526A)"},
/* tr */ {IDCLS_SET_CIA2_MODEL_TR, "CIA 2 modelini belirle (0 = eski 6526, 1 = yeni 6526A)"},
#endif

/* c64/c64-cmdline-options.c */
/* en */ {IDCLS_SET_C64_MODEL,    N_("Set C64 model (c64/c64c/c64old, ntsc/newntsc/oldntsc, drean)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_C64_MODEL_DA, "Valg C64 model (c64/c64c/c64old, ntsc/newntsc/oldntsc, drean)"},
/* de */ {IDCLS_SET_C64_MODEL_DE, "Wahle C64 Modell (c64/c64c/c64alt/c64ntsc/c64cntsc/c64oldntsc/drean)"},
/* fr */ {IDCLS_SET_C64_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_C64_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_C64_MODEL_IT, "Imposta modello C64 (c64/c64c/c64old, ntsc/newntsc/oldntsc, drean)"},
/* ko */ {IDCLS_SET_C64_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_C64_MODEL_NL, "Zet C64 model (c64/c64c/c64old, ntsc/newntsc/oldntsc, drean)"},
/* pl */ {IDCLS_SET_C64_MODEL_PL, "Okre��l model C64 (c64/c64c/c64old, ntsc/newntsc/oldntsc, drean)"},
/* ru */ {IDCLS_SET_C64_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_C64_MODEL_SV, "Valj C64-modell (c64/c64c/c64old, ntsc/newntsc/oldntsc, drean)"},
/* tr */ {IDCLS_SET_C64_MODEL_TR, "C64 modelini belirle (c64/c64c/c64eski, ntsc/yenintsc/eskintsc, drean)"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SET_PLUS4_MODEL,    N_("Set Plus4 model (c16/c16pal/c16ntsc, plus4/plus4pal/plus4ntsc, v364/cv364, c232)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_PLUS4_MODEL_DA, ""},  /* fuzzy */
/* de */ {IDCLS_SET_PLUS4_MODEL_DE, "Setze Plus4 Modell (c16/c16pal/c16ntsc, plus4/plus4pal/plus4ntsc, v364/cv364, c232)"},
/* fr */ {IDCLS_SET_PLUS4_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_PLUS4_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_PLUS4_MODEL_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_SET_PLUS4_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_PLUS4_MODEL_NL, ""},  /* fuzzy */
/* pl */ {IDCLS_SET_PLUS4_MODEL_PL, "Ustaw model Plus4 (c16/c16pal/c16ntsc, plus4/plus4pal/plus4ntsc, v364/cv364, c232)"},
/* ru */ {IDCLS_SET_PLUS4_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_PLUS4_MODEL_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_SET_PLUS4_MODEL_TR, ""},  /* fuzzy */
#endif

/* c64dtv/c64dtv-cmdline-options.c */
/* en */ {IDCLS_SET_DTV_MODEL,    N_("Set DTV model (v2/v2pal/v2ntsc, v3/v3pal/v3ntsc, hummer)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DTV_MODEL_DA, ""},  /* fuzzy */
/* de */ {IDCLS_SET_DTV_MODEL_DE, "Setze DTV Modell (v2/v2pal/v2ntsc, v3/v3pal/v3ntsc, hummer)"},
/* fr */ {IDCLS_SET_DTV_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_DTV_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_DTV_MODEL_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_SET_DTV_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DTV_MODEL_NL, ""},  /* fuzzy */
/* pl */ {IDCLS_SET_DTV_MODEL_PL, "Ustaw model DTV (v2/v2pal/v2ntsc, v3/v3pal/v3ntsc, hummer)"},
/* ru */ {IDCLS_SET_DTV_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DTV_MODEL_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_SET_DTV_MODEL_TR, ""},  /* fuzzy */
#endif

/* c64/c64-cmdline-options.c, cbm2/cbm2-cmdline-options.c,
   pet/pet-cmdline-options.c, plus4/plus4-cmdline-options.c,
   vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_KERNAL_ROM_NAME,    N_("Specify name of Kernal ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_DA, "Angiv navn pa kernal-ROM-image"},
/* de */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_DE, "Name von Kernal ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_FR, "Specifier le nom de l'image ROM Kernal"},
/* hu */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_HU, "Adja meg a Kernal ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_IT, "Specifica il nome immagine della ROM del Kernal"},
/* ko */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_NL, "Geef de naam van het Kernal ROM bestand"},
/* pl */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_PL, "Okre��l nazwe obrazu ROM Kernala"},
/* ru */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_SV, "Ange namn pa kernal-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_KERNAL_ROM_NAME_TR, "Kernal ROM imajynyn ismini belirt"},
#endif

/* c64/c64-cmdline-options.c, cbm2/cbm2-cmdline-options.c,
   pet/pet-cmdline-options.c, plus4/plus4-cmdline-options.c,
   vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BASIC_ROM_NAME,    N_("Specify name of BASIC ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BASIC_ROM_NAME_DA, "Angiv navn pa BASIC-ROM-image"},
/* de */ {IDCLS_SPECIFY_BASIC_ROM_NAME_DE, "Name von Basic ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_BASIC_ROM_NAME_FR, "Specifier le nom de l'image BASIC ROM"},
/* hu */ {IDCLS_SPECIFY_BASIC_ROM_NAME_HU, "Adja meg a BASIC ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_BASIC_ROM_NAME_IT, "Specifica il nome immagine della ROM del BASIC"},
/* ko */ {IDCLS_SPECIFY_BASIC_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BASIC_ROM_NAME_NL, "Geef de naam van het BASIC ROM bestand"},
/* pl */ {IDCLS_SPECIFY_BASIC_ROM_NAME_PL, "Okre��l nazwe obrazu BASIC ROM"},
/* ru */ {IDCLS_SPECIFY_BASIC_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BASIC_ROM_NAME_SV, "Ange namn pa BASIC-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_BASIC_ROM_NAME_TR, "BASIC ROM imajynyn ismini belirt"},
#endif

/* c64/c64-cmdline-options.c, cbm2/cbm2-cmdline-options.c,
   pet/pet-cmdline-options.c, vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME,    N_("Specify name of character generator ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_DA, "Angiv navn pa BASIC-ROM-image"},
/* de */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_DE, "Name von Druckerausgabe Datei definieren (print.dump)"},
/* fr */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_FR, "Specifier le nom de l'image du generateur de caracteres"},
/* hu */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_HU, "Adja meg a karaktergenerator ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_IT, "Specifica il nome della ROM del generatore di caratteri"},
/* ko */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_NL, "Geef de naam van het CHARGEN ROM bestand"},
/* pl */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_PL, "Okre��l nazwe obrazu ROM-u tworzenia znakow"},
/* ru */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_SV, "Ange namn pa teckengenerator-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_CHARGEN_ROM_NAME_TR, "Karakter Olutturucu ROM imajynyn ismini belirt"},
#endif

#ifdef COMMON_KBD
/* c64/c64-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2,    N_("Specify index of keymap file (0=sym, 1=symDE, 2=pos)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_DA, "Angiv indeks for tastaturindstillingsfil (0=symbolsk, 1=symbolsk tysk, 2=positionsbestemt)"},
/* de */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_DE, "Index fur Keymap Datei festlegen (0=symbol, 1=symDE, 2=positional)"},
/* fr */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_FR, "Specifier l'index du fichier keymap (0=sym, 1=symDE, 2=pos)"},
/* hu */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_HU, "Adja meg a billentyuzet lekepzesi fajl tipusat (0=szimbolikus, 1=nemet szimbolikus, 2=pozicio szerinti)"},
/* it */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_IT, "Specifica l'indice del file della mappa della tastiera (0=sim, 1=simGER, 2=pos)"},
/* ko */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_NL, "Geef de index van het keymapbestand (0=sym, 1=symDE, 2=pos)"},
/* pl */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_PL, "Podaj indeks dla uk3�}du klawiatury (0=symbol, 1=symbolDE, 2=pozycja)"},
/* ru */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_SV, "Ange index for for tangentbordsinstallningsfil (0=symbolisk, 1=symbolisk tysk, 2=positionsriktig)"},
/* tr */ {IDCLS_SPECIFY_INDEX_KEYMAP_FILE_0_2_TR, "Tut haritasy dosyasynyn indeksini belirt (0=sembol, 1=sembol Almanca, 2=konumsal)"},
#endif

/* c64/c64-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP,    N_("Specify name of symbolic German keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_DA, "Angiv fil for tysk symbolsk tastaturindstilling"},
/* de */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_DE, "Name von symbolischer Keymap Datei definieren"},
/* fr */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_FR, "Specifier le nom du fichier symbolique de mappage clavier"},
/* hu */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_HU, "Adja meg a nevet a nemet billentyuzet lekepzes fajlnak"},
/* it */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_IT, "Specifica il nome del file della mappa simbolica della tastiera tedesca"},
/* ko */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_NL, "Geef de naam van het symbolische Duitse keymapbestand"},
/* pl */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_PL, "Okre��l nazwe pliku symbolicznego niemieckiego uk3adu klawiatury"},
/* ru */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_SV, "Ange fil for tysk symbolisk tangentbordsemulering"},
/* tr */ {IDCLS_SPECIFY_NAME_SYM_DE_KEYMAP_TR, "Sembolik Almanca tut haritasy dosyasynyn ismini belirt"},
#endif
#endif

/* c64/c64gluelogic.c */
/* en */ {IDCLS_SET_GLUE_LOGIC_TYPE,    N_("Set glue logic type (0 = discrete, 1 = 252535-01)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_GLUE_LOGIC_TYPE_DA, "Valg glue logic type (0=diskret, 1=252535-01)"},
/* de */ {IDCLS_SET_GLUE_LOGIC_TYPE_DE, "Setze Glue-Lokig Typ (0 = diskret, 1 = 252535-01)"},
/* fr */ {IDCLS_SET_GLUE_LOGIC_TYPE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_GLUE_LOGIC_TYPE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_GLUE_LOGIC_TYPE_IT, "Imposta il tipo di glue logic (0 = discreta, 1 = 252535-01)"},
/* ko */ {IDCLS_SET_GLUE_LOGIC_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_GLUE_LOGIC_TYPE_NL, "Zet lijk logica soort (0 = discreet, 1 = 252535-01)"},
/* pl */ {IDCLS_SET_GLUE_LOGIC_TYPE_PL, "Ustaw typ glue logic (0 = dyskretna, 1 = 252535-01)"},
/* ru */ {IDCLS_SET_GLUE_LOGIC_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_GLUE_LOGIC_TYPE_SV, "Valj typ av klisterlogik (0 = diskret, 1 = 252535-01)"},
/* tr */ {IDCLS_SET_GLUE_LOGIC_TYPE_TR, "Glue logic tipini ayarla (0 = badlantyyy kes, 1 = 252535-01)"},
#endif

/* c64dtv/c64dtv-cmdline-options.c */
/* en */ {IDCLS_ENABLE_HUMMER_ADC,    N_("Enable Hummer ADC")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_HUMMER_ADC_DA, "Aktiver Hummer ADC"},
/* de */ {IDCLS_ENABLE_HUMMER_ADC_DE, "Hummer ADC Aktivieren"},
/* fr */ {IDCLS_ENABLE_HUMMER_ADC_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_HUMMER_ADC_HU, "Hummer ADC engedelyezese"},
/* it */ {IDCLS_ENABLE_HUMMER_ADC_IT, "Attiva Hummer ADC"},
/* ko */ {IDCLS_ENABLE_HUMMER_ADC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_HUMMER_ADC_NL, "Activeer Hummer ADC"},
/* pl */ {IDCLS_ENABLE_HUMMER_ADC_PL, "W3�}cz Hummer ADC"},
/* ru */ {IDCLS_ENABLE_HUMMER_ADC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_HUMMER_ADC_SV, "Aktivera Hummer-A/D-omvandlare"},
/* tr */ {IDCLS_ENABLE_HUMMER_ADC_TR, "Hummer ADC'yi aktif et"},
#endif

/* c64dtv/c64dtv-cmdline-options.c */
/* en */ {IDCLS_DISABLE_HUMMER_ADC,    N_("Disable Hummer ADC")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_HUMMER_ADC_DA, "Deaktiver Hummer ADC"},
/* de */ {IDCLS_DISABLE_HUMMER_ADC_DE, "Hummer ADC deaktivieren"},
/* fr */ {IDCLS_DISABLE_HUMMER_ADC_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_HUMMER_ADC_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_HUMMER_ADC_IT, "Disattiva Hummer ADC"},
/* ko */ {IDCLS_DISABLE_HUMMER_ADC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_HUMMER_ADC_NL, "Hummer ADC uitschakelen"},
/* pl */ {IDCLS_DISABLE_HUMMER_ADC_PL, "Wy3�}cz Hummer ADC"},
/* ru */ {IDCLS_DISABLE_HUMMER_ADC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_HUMMER_ADC_SV, "Inaktivera Hummer-A/D-omvandlare"},
/* tr */ {IDCLS_DISABLE_HUMMER_ADC_TR, "Hummer ADC'yi pasiflettir"},
#endif

/* c64/cart/c64tpi.c */
/* en */ {IDCLS_ENABLE_IEEE488_INTERFACE,    N_("Enable the IEEE488 interface emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEEE488_INTERFACE_DA, "Aktiver emulering af IEEE488-interface"},
/* de */ {IDCLS_ENABLE_IEEE488_INTERFACE_DE, "IEEE488 Schnittstellen-Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_IEEE488_INTERFACE_FR, "Activer l'interface d'emulation IEEE488"},
/* hu */ {IDCLS_ENABLE_IEEE488_INTERFACE_HU, "IEEE488 interfesz emulacio engedelyezese"},
/* it */ {IDCLS_ENABLE_IEEE488_INTERFACE_IT, "Attiva emulazione interfaccia IEEE488"},
/* ko */ {IDCLS_ENABLE_IEEE488_INTERFACE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEEE488_INTERFACE_NL, "Activeer de IEEE488 interface emulatie"},
/* pl */ {IDCLS_ENABLE_IEEE488_INTERFACE_PL, "W3�}cz emulacje interfejsu IEEE488"},
/* ru */ {IDCLS_ENABLE_IEEE488_INTERFACE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEEE488_INTERFACE_SV, "Aktivera emulering av IEEE488-granssnitt"},
/* tr */ {IDCLS_ENABLE_IEEE488_INTERFACE_TR, "IEEE488 arabirim emulasyonunu aktif et"},
#endif

/* c64/cart/c64tpi.c */
/* en */ {IDCLS_DISABLE_IEEE488_INTERFACE,    N_("Disable the IEEE488 interface emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEEE488_INTERFACE_DA, "Deaktiver emulering af IEEE488-interface"},
/* de */ {IDCLS_DISABLE_IEEE488_INTERFACE_DE, "IEEE488 Schnittstellen-Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEEE488_INTERFACE_FR, "Desactiver l'interface d'emulation IEEE488"},
/* hu */ {IDCLS_DISABLE_IEEE488_INTERFACE_HU, "IEEE488 interfesz emulacio tiltasa"},
/* it */ {IDCLS_DISABLE_IEEE488_INTERFACE_IT, "Disattiva emulazione interfaccia IEEE488"},
/* ko */ {IDCLS_DISABLE_IEEE488_INTERFACE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEEE488_INTERFACE_NL, "De IEEE488 interface emulatie uitschakelen"},
/* pl */ {IDCLS_DISABLE_IEEE488_INTERFACE_PL, "Wy3�}cz emulacje interfejsu IEEE488"},
/* ru */ {IDCLS_DISABLE_IEEE488_INTERFACE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEEE488_INTERFACE_SV, "Inaktivera emulering av IEEE488-granssnitt"},
/* tr */ {IDCLS_DISABLE_IEEE488_INTERFACE_TR, "IEEE488 arabirim emulasyonunu pasiflettir"},
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
/* pl */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME_PL, "okre��l nazwe obrazu interfejsu IEEE488"},
/* ru */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_IEEE488_INTERFACE_NAME_SV, "ange namn pa IEEE488-granssnittsfil"},
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
/* pl */ {IDCLS_ENABLE_GEORAM_PL, "W3�}cz jednostke rozszerzenia GEO-RAM"},
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
/* pl */ {IDCLS_DISABLE_GEORAM_PL, "Wy3�}cz jednostke rozszerzenia GEO-RAM"},
/* ru */ {IDCLS_DISABLE_GEORAM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_GEORAM_SV, "Inaktivera GEO RAM-expansionsenhet"},
/* tr */ {IDCLS_DISABLE_GEORAM_TR, ""},  /* fuzzy */
#endif

/* c64/cart/georam.c */
/* en */ {IDCLS_SPECIFY_GEORAM_NAME,    N_("Specify name of GEORAM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_GEORAM_NAME_DA, "Angiv navn pa GEORAM-image"},
/* de */ {IDCLS_SPECIFY_GEORAM_NAME_DE, "GEORAM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_GEORAM_NAME_FR, "Specifier le nom de l'image GEORAM"},
/* hu */ {IDCLS_SPECIFY_GEORAM_NAME_HU, "Adja meg a GEORAM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_GEORAM_NAME_IT, "Specifica il nome immagine GEORAM"},
/* ko */ {IDCLS_SPECIFY_GEORAM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_GEORAM_NAME_NL, "Geef de naam van het GEORAM bestand"},
/* pl */ {IDCLS_SPECIFY_GEORAM_NAME_PL, "Okre��l nazwe obrazu GEORAM"},
/* ru */ {IDCLS_SPECIFY_GEORAM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_GEORAM_NAME_SV, "Ange namn pa GEORAM-avbildning"},
/* tr */ {IDCLS_SPECIFY_GEORAM_NAME_TR, "GEORAM imajynyn ismini belirt"},
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
/* pl */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_PL, "Pozwol na zapis do obrazu GEORAM"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_SV, "Tillat skrivning till GEORAM-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_GEORAM_IMAGE_TR, "GEORAM imajyna yazmayy aktif et"},
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
/* pl */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_PL, "Nie zapisuj do obrazu GEORAM"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_SV, "Skriv inte till GEORAM-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_GEORAM_IMAGE_TR, "GEORAM imajyna yazma"},
#endif

/* c64/cart/georam.c, c64/cart/ramcart.c, c64/cart/reu.c, pet/petreu.c */
/* en */ {IDCLS_P_SIZE_IN_KB,    N_("<size in KB>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_SIZE_IN_KB_DA, "<storrelse i KB>"},
/* de */ {IDCLS_P_SIZE_IN_KB_DE, "<Grose in KB>"},
/* fr */ {IDCLS_P_SIZE_IN_KB_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_SIZE_IN_KB_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_SIZE_IN_KB_IT, "<dimensione in KB>"},
/* ko */ {IDCLS_P_SIZE_IN_KB_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_SIZE_IN_KB_NL, "<grootte in KB>"},
/* pl */ {IDCLS_P_SIZE_IN_KB_PL, "<rozmiar w KB>"},
/* ru */ {IDCLS_P_SIZE_IN_KB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_SIZE_IN_KB_SV, "<storlek i KB>"},
/* tr */ {IDCLS_P_SIZE_IN_KB_TR, "<KB cinsinden boyut>"},
#endif

/* c64/cart/georam.c */
/* en */ {IDCLS_GEORAM_SIZE,    N_("Size of the GEORAM expansion unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_GEORAM_SIZE_DA, "Storrelse af GEORAM-udviddelsesenhed"},
/* de */ {IDCLS_GEORAM_SIZE_DE, "Grose der GEORAM Erweiterung"},
/* fr */ {IDCLS_GEORAM_SIZE_FR, "Taille de l'unite d'expansion GEORAM"},
/* hu */ {IDCLS_GEORAM_SIZE_HU, "GEORAM Expansion Unit merete"},
/* it */ {IDCLS_GEORAM_SIZE_IT, "Dimensione dell'espansione GEORAM"},
/* ko */ {IDCLS_GEORAM_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_GEORAM_SIZE_NL, "Grootte van de GEORAM uitbreidingseenheid"},
/* pl */ {IDCLS_GEORAM_SIZE_PL, "Rozmiar jednostki rozszerzenia GEORAM"},
/* ru */ {IDCLS_GEORAM_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_GEORAM_SIZE_SV, "Storlek pa GEORAM-expansionsenhet"},
/* tr */ {IDCLS_GEORAM_SIZE_TR, "GEORAM genitletme biriminin boyutu"},
#endif

/* pet/petreu.c */
/* en */ {IDCLS_ENABLE_PETREU,    N_("Enable the PET Ram and Expansion Unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PETREU_DA, "Aktiver PET REU"},
/* de */ {IDCLS_ENABLE_PETREU_DE, "PET RAM Speicher und Erweiterungsmodul aktivieren"},
/* fr */ {IDCLS_ENABLE_PETREU_FR, "Activer l'expansion d'unite et de RAM du PET"},
/* hu */ {IDCLS_ENABLE_PETREU_HU, "PET RAM and Expansion Unit engedelyezese"},
/* it */ {IDCLS_ENABLE_PETREU_IT, "Attiva la RAM e l'unita di espansione del PET"},
/* ko */ {IDCLS_ENABLE_PETREU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_PETREU_NL, "Activeer de PET RAM en uitbreidingseenheid"},
/* pl */ {IDCLS_ENABLE_PETREU_PL, "W3�}cz PET Ram i Expansion Unit"},
/* ru */ {IDCLS_ENABLE_PETREU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PETREU_SV, "Aktivera PET Ram- och -expansionsenhet"},
/* tr */ {IDCLS_ENABLE_PETREU_TR, "PET Ram ve Genitletme Birimi'ni aktif et"},
#endif

/* pet/petreu.c */
/* en */ {IDCLS_DISABLE_PETREU,    N_("Disable the PET Ram and Expansion Unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PETREU_DA, "Deaktiver PET REU"},
/* de */ {IDCLS_DISABLE_PETREU_DE, "PET RAM Speicher und Erweiterungsmodul dektivieren"},
/* fr */ {IDCLS_DISABLE_PETREU_FR, "Desactiver l'expansion d'unite et de RAM du PET"},
/* hu */ {IDCLS_DISABLE_PETREU_HU, "PET RAM and Expansion Unit tiltasa"},
/* it */ {IDCLS_DISABLE_PETREU_IT, "Disattiva la RAM e l'unita di espansione del PET"},
/* ko */ {IDCLS_DISABLE_PETREU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PETREU_NL, "De PET RAM en uitbreidingseenheid uitschakelen"},
/* pl */ {IDCLS_DISABLE_PETREU_PL, "Wy3�}cz PET Ram i Expansion Unit"},
/* ru */ {IDCLS_DISABLE_PETREU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PETREU_SV, "Inaktivera PET Ram- och -expansionsenhet"},
/* tr */ {IDCLS_DISABLE_PETREU_TR, "PET Ram ve Genitletme Birimi'ni pasiflettir"},
#endif

/* pet/petreu.c */
/* en */ {IDCLS_SPECIFY_PETREU_NAME,    N_("Specify name of PET Ram and Expansion Unit image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PETREU_NAME_DA, "Angiv navn pa PET REU-image"},
/* de */ {IDCLS_SPECIFY_PETREU_NAME_DE, "Namen fur PET RAM Speicher und Erweiterungsmodul definieren"},
/* fr */ {IDCLS_SPECIFY_PETREU_NAME_FR, "Specifier le nom de l'image d�funite d'expansion RAM"},
/* hu */ {IDCLS_SPECIFY_PETREU_NAME_HU, "Adja meg a PET RAM and Expansion Unit kepmas nevet"},
/* it */ {IDCLS_SPECIFY_PETREU_NAME_IT, "Specifica il nome immagine della RAM e dell'unita di espansione del PET"},
/* ko */ {IDCLS_SPECIFY_PETREU_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PETREU_NAME_NL, "Geef de naam van het PET RAM en uitbreidingseenheid bestand"},
/* pl */ {IDCLS_SPECIFY_PETREU_NAME_PL, "Okre��l nazwe obrazu PET Ram i Expansion Unit"},
/* ru */ {IDCLS_SPECIFY_PETREU_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PETREU_NAME_SV, "Ange namn pa PET Ram- och -expansionsenhet"},
/* tr */ {IDCLS_SPECIFY_PETREU_NAME_TR, "PET Ram ve Genitletme Birimi'nin ismini belirt"},
#endif

/* pet/petreu.c */
/* en */ {IDCLS_PETREU_SIZE,    N_("Size of the PET Ram and Expansion Unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PETREU_SIZE_DA, "Storrelse pa PET REU"},
/* de */ {IDCLS_PETREU_SIZE_DE, "Grose des PET RAM Speicher und Erweiterungsmodul"},
/* fr */ {IDCLS_PETREU_SIZE_FR, "Taille de l'unite d'expansion RAM"},
/* hu */ {IDCLS_PETREU_SIZE_HU, "PET RAM and Expansion Unit merete"},
/* it */ {IDCLS_PETREU_SIZE_IT, "Dimensione della RAM e dell'unita di espansione del PET"},
/* ko */ {IDCLS_PETREU_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PETREU_SIZE_NL, "Grootte van de PET RAM en uitbreidingseenheid"},
/* pl */ {IDCLS_PETREU_SIZE_PL, "Rozmiar PET Ram i Expansion Unit"},
/* ru */ {IDCLS_PETREU_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PETREU_SIZE_SV, "Storlek pa PET Ram- och -expansionsenhet"},
/* tr */ {IDCLS_PETREU_SIZE_TR, "PET Ram ve Genitletme Birimi'nin boyutu"},
#endif

/* pet/petdww.c */
/* en */ {IDCLS_SPECIFY_PETDWW_NAME,    N_("Specify name of PET DWW image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PETDWW_NAME_DA, "Angiv navn pa PET DWW-image"},
/* de */ {IDCLS_SPECIFY_PETDWW_NAME_DE, "Namen fur PET DWW Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_PETDWW_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_PETDWW_NAME_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SPECIFY_PETDWW_NAME_IT, "Specifica il nome immagine PET DWW"},
/* ko */ {IDCLS_SPECIFY_PETDWW_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PETDWW_NAME_NL, "Geef de naam van het PET DWW bestand"},
/* pl */ {IDCLS_SPECIFY_PETDWW_NAME_PL, "Okre��l nazwe obrazu PET DWW"},
/* ru */ {IDCLS_SPECIFY_PETDWW_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PETDWW_NAME_SV, "Ange namn pa PET DWW-avbildning"},
/* tr */ {IDCLS_SPECIFY_PETDWW_NAME_TR, "PET DWW imajynyn ismini belirt"},
#endif

/* pet/petdww.c */
/* en */ {IDCLS_ENABLE_PETDWW,    N_("Enable the PET DWW hi-res board")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PETDWW_DA, "Aktiver PET DWW hojoplosningskort"},
/* de */ {IDCLS_ENABLE_PETDWW_DE, "PET DWW hi-res Karte aktivieren"},
/* fr */ {IDCLS_ENABLE_PETDWW_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_PETDWW_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_PETDWW_IT, "Attiva la scheda hi-res PET DWW"},
/* ko */ {IDCLS_ENABLE_PETDWW_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_PETDWW_NL, "Activeer het PET DWW hi-res bord"},
/* pl */ {IDCLS_ENABLE_PETDWW_PL, "W3�}cz uk3ad PET DWW hi-res"},
/* ru */ {IDCLS_ENABLE_PETDWW_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PETDWW_SV, "Aktivera PET DWW-hogupplosningskort"},
/* tr */ {IDCLS_ENABLE_PETDWW_TR, "PET DWW hi-res boardunu aktif et"},
#endif

/* pet/petdww.c */
/* en */ {IDCLS_DISABLE_PETDWW,    N_("Disable the PET DWW hi-res board")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PETDWW_DA, "Deaktiver PET DWW hojoplosningskort"},
/* de */ {IDCLS_DISABLE_PETDWW_DE, "PET DWW Hi-Res Karte deaktivieren"},
/* fr */ {IDCLS_DISABLE_PETDWW_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_PETDWW_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_PETDWW_IT, "Disattiva la scheda hi-res PET DWW"},
/* ko */ {IDCLS_DISABLE_PETDWW_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PETDWW_NL, "Het PET DWW hi-res bord uitschakelen"},
/* pl */ {IDCLS_DISABLE_PETDWW_PL, "Wy3�}cz p3yte PET DWW hi-res"},
/* ru */ {IDCLS_DISABLE_PETDWW_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PETDWW_SV, "Inaktivera PET DWW-hogupplosningskort"},
/* tr */ {IDCLS_DISABLE_PETDWW_TR, "PET DWW hi-res boardu pasiflettir"},
#endif

/* pet/pet_userport_dac.c */
/* en */ {IDCLS_ENABLE_USERPORT_DAC,    N_("Enable Userport DAC for sound output")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_USERPORT_DAC_DA, "Aktiver brugerport DAC for lydoutput"},
/* de */ {IDCLS_ENABLE_USERPORT_DAC_DE, "Userport DAC Sound aktivieren"},
/* fr */ {IDCLS_ENABLE_USERPORT_DAC_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_USERPORT_DAC_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_USERPORT_DAC_IT, "Attiva DAC su userport per la riproduzione audio"},
/* ko */ {IDCLS_ENABLE_USERPORT_DAC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_USERPORT_DAC_NL, "Activeer userport DAC voor geluidsuitvoer"},
/* pl */ {IDCLS_ENABLE_USERPORT_DAC_PL, "W3�}cz userport DAC jako wyj��cie d?wieku"},
/* ru */ {IDCLS_ENABLE_USERPORT_DAC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_USERPORT_DAC_SV, "Aktivera D/A-omvandlare pa anvandarporten for ljudutdata"},
/* tr */ {IDCLS_ENABLE_USERPORT_DAC_TR, "Ses cykyty icin Userport DAC'y aktif et"},
#endif

/* pet/pet_userport_dac.c */
/* en */ {IDCLS_DISABLE_USERPORT_DAC,    N_("Disable Userport DAC for sound output")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_USERPORT_DAC_DA, "Deaktiver brugerport DAC for lydoutput"},
/* de */ {IDCLS_DISABLE_USERPORT_DAC_DE, "Userport DAC Sound deaktivieren"},
/* fr */ {IDCLS_DISABLE_USERPORT_DAC_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_USERPORT_DAC_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_USERPORT_DAC_IT, "Disattiva DAC su userport per la riproduzione audio"},
/* ko */ {IDCLS_DISABLE_USERPORT_DAC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_USERPORT_DAC_NL, "Userport DAC voor geluidsuitvoer uitschakelen"},
/* pl */ {IDCLS_DISABLE_USERPORT_DAC_PL, "Wy3�}cz userport DAC jako wy��cie d?wieku"},
/* ru */ {IDCLS_DISABLE_USERPORT_DAC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_USERPORT_DAC_SV, "Inaktivera D/A-omvandlare pa anvandarporten for ljudutdata"},
/* tr */ {IDCLS_DISABLE_USERPORT_DAC_TR, "Ses cykyty icin Userport DAC'y pasiflettir"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_SID_PLAYER_MODE,    N_("SID player mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SID_PLAYER_MODE_DA, "SID-afspiller tilstand"},
/* de */ {IDCLS_SID_PLAYER_MODE_DE, "SID Player Modus"},
/* fr */ {IDCLS_SID_PLAYER_MODE_FR, "Mode jukebox SID"},
/* hu */ {IDCLS_SID_PLAYER_MODE_HU, "SID lejatszo mod"},
/* it */ {IDCLS_SID_PLAYER_MODE_IT, "Modalita del SID player"},
/* ko */ {IDCLS_SID_PLAYER_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SID_PLAYER_MODE_NL, "SID playermodus"},
/* pl */ {IDCLS_SID_PLAYER_MODE_PL, "Tryb odtwarzacza SID"},
/* ru */ {IDCLS_SID_PLAYER_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SID_PLAYER_MODE_SV, "SID-spelarlage"},
/* tr */ {IDCLS_SID_PLAYER_MODE_TR, "SID calar modu"},
#endif

/* c64/psid.c */
/* en */ {IDCLS_OVERWRITE_PSID_SETTINGS,    N_("Override PSID settings for Video standard and SID model")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_OVERWRITE_PSID_SETTINGS_DA, "Overstyr PSID-indstillinger for Video-standard og SID-model"},
/* de */ {IDCLS_OVERWRITE_PSID_SETTINGS_DE, "PSID Einstellung fur Video Standard und SID Modell verandern"},
/* fr */ {IDCLS_OVERWRITE_PSID_SETTINGS_FR, "Ecraser les parametres PSID pour le standard video et le modele SID"},
/* hu */ {IDCLS_OVERWRITE_PSID_SETTINGS_HU, "A video szabvany es a SID modell PSID beallitasainak felulbiralasa"},
/* it */ {IDCLS_OVERWRITE_PSID_SETTINGS_IT, "Non tener conto delle impostazioni del PSID per lo standard video e il modello di SID"},
/* ko */ {IDCLS_OVERWRITE_PSID_SETTINGS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_OVERWRITE_PSID_SETTINGS_NL, "Overschrijf PSID instellingen voor videostandaard en SID model"},
/* pl */ {IDCLS_OVERWRITE_PSID_SETTINGS_PL, "Zast�}p ustawienia PSID standardu wideo i modelu SID"},
/* ru */ {IDCLS_OVERWRITE_PSID_SETTINGS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_OVERWRITE_PSID_SETTINGS_SV, "Ersatt PSID-installningar for videostandard och SID-modell"},
/* tr */ {IDCLS_OVERWRITE_PSID_SETTINGS_TR, "Video standardy ve SID modeli icin PSID ayarlaryny gecersiz kyl"},
#endif

/* c64/psid.c */
/* en */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER,    N_("Specify PSID tune <number>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_DA, "Valg PSID-nummer <nummer>"},
/* de */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_DE, "PSID Stuck <Nummer> definieren"},
/* fr */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_FR, "Specifier le <numero> de piste PSID"},
/* hu */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_HU, "Adja meg a PSID hangzatok <szam>"},
/* it */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_IT, "Specifica la melodia <numero> del PSID"},
/* ko */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_NL, "Geef PSID deuntje <nummer>"},
/* pl */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_PL, "Okre��l ton PSID <numer>"},
/* ru */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_SV, "Ange PSID-lat <nummer>"},
/* tr */ {IDCLS_SPECIFY_PSID_TUNE_NUMBER_TR, "PSID parca <numara>'syny belirt"},
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
/* pl */ {IDCLS_ENABLE_RAMCART_PL, "W3�}cz rozszerzenie RamCart"},
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
/* pl */ {IDCLS_DISABLE_RAMCART_PL, "Wy3�}cz rozszerzenie Ram Cart"},
/* ru */ {IDCLS_DISABLE_RAMCART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAMCART_SV, "Inaktivera RamCart-expansion"},
/* tr */ {IDCLS_DISABLE_RAMCART_TR, ""},  /* fuzzy */
#endif

/* c64/cart/ramcart.c */
/* en */ {IDCLS_SPECIFY_RAMCART_NAME,    N_("Specify name of RAMCART image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RAMCART_NAME_DA, "Angiv navn pa RAMCART-image"},
/* de */ {IDCLS_SPECIFY_RAMCART_NAME_DE, "Name fur RAMCART Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_RAMCART_NAME_FR, "Specifier le nom de l'image RAMCART"},
/* hu */ {IDCLS_SPECIFY_RAMCART_NAME_HU, "Adja meg a RAMCART kepmas nevet"},
/* it */ {IDCLS_SPECIFY_RAMCART_NAME_IT, "Specifica il nome immagine RAMCART"},
/* ko */ {IDCLS_SPECIFY_RAMCART_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RAMCART_NAME_NL, "Geef de naam van het RAMCART bestand"},
/* pl */ {IDCLS_SPECIFY_RAMCART_NAME_PL, "Okre��l nazwe obrazu RAMCART"},
/* ru */ {IDCLS_SPECIFY_RAMCART_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RAMCART_NAME_SV, "Ange namn pa RAMCART-avbildning"},
/* tr */ {IDCLS_SPECIFY_RAMCART_NAME_TR, "RAMCART imajynyn ismini belirt"},
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
/* pl */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_PL, "Pozwol na zapis do obrazu RAMCart"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_SV, "Tillat skrivning till RAMCart-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_RAMCART_IMAGE_TR, "RAMCart imajyna yazmayy aktif et"},
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
/* pl */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_PL, "Nie zapisuj do obrazu RAMCart"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_SV, "Skriv inte till RAMCart-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_RAMCART_IMAGE_TR, "RAMCart imajyna yazma"},
#endif

/* c64/cart/ramcart.c */
/* en */ {IDCLS_RAMCART_SIZE,    N_("Size of the RAMCART expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RAMCART_SIZE_DA, "Storrelse pa RAMCART-udviddelse"},
/* de */ {IDCLS_RAMCART_SIZE_DE, "Grose der RAMCART Erweiterung"},
/* fr */ {IDCLS_RAMCART_SIZE_FR, "Taille de l'expansion RAMCART"},
/* hu */ {IDCLS_RAMCART_SIZE_HU, "RAMCART bovites merete"},
/* it */ {IDCLS_RAMCART_SIZE_IT, "Dimensione dell'espansione RAMCART"},
/* ko */ {IDCLS_RAMCART_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_RAMCART_SIZE_NL, "Grootte van de RAMCART uitbreiding"},
/* pl */ {IDCLS_RAMCART_SIZE_PL, "Rozmiar rozszerzenia RAMCART"},
/* ru */ {IDCLS_RAMCART_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RAMCART_SIZE_SV, "Storlek pa RAMCART-expansion"},
/* tr */ {IDCLS_RAMCART_SIZE_TR, "RAMCART genitlemesinin boyutu"},
#endif

/* c64/cart/dqbb.c */
/* en */ {IDCLS_ENABLE_DQBB,    N_("Enable Double Quick Brown Box")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DQBB_DA, "Aktiver Double Quick Brown Box"},
/* de */ {IDCLS_ENABLE_DQBB_DE, "Double Quick Brown Box aktivieren"},
/* fr */ {IDCLS_ENABLE_DQBB_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_DQBB_HU, "Double Quick Brown Box engedelyezese"},
/* it */ {IDCLS_ENABLE_DQBB_IT, "Attiva Double Quick Brown Box"},
/* ko */ {IDCLS_ENABLE_DQBB_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DQBB_NL, "Activeer de Double Quick Brown Box cartridge"},
/* pl */ {IDCLS_ENABLE_DQBB_PL, "W3�}cz Double Quick Brown Box"},
/* ru */ {IDCLS_ENABLE_DQBB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DQBB_SV, "Aktivera Double Quick Brown Box"},
/* tr */ {IDCLS_ENABLE_DQBB_TR, "Double Quick Brown Box'y aktif et"},
#endif

/* c64/cart/dqbb.c */
/* en */ {IDCLS_DISABLE_DQBB,    N_("Disable Double Quick Brown Box")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DQBB_DA, "Deaktiver Double Quick Brown Box"},
/* de */ {IDCLS_DISABLE_DQBB_DE, "Double Quick Brown Box Modul deaktivieren"},
/* fr */ {IDCLS_DISABLE_DQBB_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_DQBB_HU, "Double Quick Brown Box tiltasa"},
/* it */ {IDCLS_DISABLE_DQBB_IT, "Disattiva Double Quick Brown Box"},
/* ko */ {IDCLS_DISABLE_DQBB_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DQBB_NL, "De Double Quick Brown Box cartridge uitschakelen"},
/* pl */ {IDCLS_DISABLE_DQBB_PL, "Wy3�}cz Double Quick Brown Box"},
/* ru */ {IDCLS_DISABLE_DQBB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DQBB_SV, "Inaktivera Double Quick Brown Box"},
/* tr */ {IDCLS_DISABLE_DQBB_TR, "Double Quick Brown Box'y pasiflettir"},
#endif

/* c64/cart/dqbb.c */
/* en */ {IDCLS_SPECIFY_DQBB_NAME,    N_("Specify Double Quick Brown Box filename")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_DQBB_NAME_DA, "Angiv filnavn for Double Quick Brown Box"},
/* de */ {IDCLS_SPECIFY_DQBB_NAME_DE, "Double Quick Brown Box Dateiname spezifizieren"},
/* fr */ {IDCLS_SPECIFY_DQBB_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_DQBB_NAME_HU, "Adja meg a Double Quick Brown Box fajlnevet"},
/* it */ {IDCLS_SPECIFY_DQBB_NAME_IT, "Specifica il nome del file Double Quick Brown Box"},
/* ko */ {IDCLS_SPECIFY_DQBB_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_DQBB_NAME_NL, "Geef de naam van het Double Quick Brown Box cartridge bestand"},
/* pl */ {IDCLS_SPECIFY_DQBB_NAME_PL, "Okre��l nazwe pliku Double Quick Brown Box"},
/* ru */ {IDCLS_SPECIFY_DQBB_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_DQBB_NAME_SV, "Ange filnamn for Double Quick Brown Box"},
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
/* pl */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_PL, "Pozwol na zapis do obrazu DQBB"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_SV, "Tillat skrivning till DQBB-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_DQBB_IMAGE_TR, "DQBB imajyna yazmayy aktif et"},
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
/* pl */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_PL, "Nie zapisuj do obrazu DQBB"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_SV, "Skriv inte till DQBB-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_DQBB_IMAGE_TR, "DQBB imajyna yazma"},
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
/* pl */ {IDCLS_ENABLE_ISEPIC_PL, "W3�}cz kartrid? ISEPIC"},
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
/* pl */ {IDCLS_DISABLE_ISEPIC_PL, "Wy3�}cz kartrid? ISEPIC"},
/* ru */ {IDCLS_DISABLE_ISEPIC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_ISEPIC_SV, "Inaktivera ISEPIC-modul"},
/* tr */ {IDCLS_DISABLE_ISEPIC_TR, ""},  /* fuzzy */
#endif

/* c64/cart/isepic.c */
/* en */ {IDCLS_SET_ISEPIC_FILENAME,    N_("Set ISEPIC image name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_ISEPIC_FILENAME_DA, "Valg ISEPIC image-navn"},
/* de */ {IDCLS_SET_ISEPIC_FILENAME_DE, "ISEPIC Imagedateiname setzen"},
/* fr */ {IDCLS_SET_ISEPIC_FILENAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_ISEPIC_FILENAME_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_ISEPIC_FILENAME_IT, "Imposta nome immagine ISEPIC"},
/* ko */ {IDCLS_SET_ISEPIC_FILENAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_ISEPIC_FILENAME_NL, "Geef de naam op van het ISEPIC cartridge bestand"},
/* pl */ {IDCLS_SET_ISEPIC_FILENAME_PL, "Okre��l nazwe obrazu ISEPIC"},
/* ru */ {IDCLS_SET_ISEPIC_FILENAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_ISEPIC_FILENAME_SV, "Namn pa ISEPIC-avbildning"},
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
/* pl */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_PL, "Pozwol na zapis do obrazu ISEPIC"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_SV, "Tillat skrivning till ISEPIC-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_ISEPIC_IMAGE_TR, "ISEPIC imajyna yazmayy aktif et"},
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
/* pl */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_PL, "Nie zapisuj do obrazu ISEPIC"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_SV, "Skriv inte till ISEPIC-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_ISEPIC_IMAGE_TR, "ISEPIC imajyna yazma"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_ENABLE_MMC64,    N_("Enable the MMC64 expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_MMC64_DA, "Aktiver MMC64-udviddelse"},
/* de */ {IDCLS_ENABLE_MMC64_DE, "MMC64 Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_MMC64_FR, "Activer l'expansion MMC64"},
/* hu */ {IDCLS_ENABLE_MMC64_HU, "MMC64 bovites engedelyezese"},
/* it */ {IDCLS_ENABLE_MMC64_IT, "Attiva l'espansione MMC64"},
/* ko */ {IDCLS_ENABLE_MMC64_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_MMC64_NL, "Activeer de MMC64 uitbreiding"},
/* pl */ {IDCLS_ENABLE_MMC64_PL, "W3�}cz rozszerzenie MMC64"},
/* ru */ {IDCLS_ENABLE_MMC64_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_MMC64_SV, "Aktivera MMC64-expansion"},
/* tr */ {IDCLS_ENABLE_MMC64_TR, "MMC64 genitlemesini aktif et"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_DISABLE_MMC64,    N_("Disable the MMC64 expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_MMC64_DA, "Deaktiver MMC64-udviddelse"},
/* de */ {IDCLS_DISABLE_MMC64_DE, "MMC64 Erweiterung deaktivieren"},
/* fr */ {IDCLS_DISABLE_MMC64_FR, "Desactiver l'expansion MMC64"},
/* hu */ {IDCLS_DISABLE_MMC64_HU, "MMC64 bovites tiltasa"},
/* it */ {IDCLS_DISABLE_MMC64_IT, "Disattiva l'espansione MMC64"},
/* ko */ {IDCLS_DISABLE_MMC64_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_MMC64_NL, "De MMC64 uitbreiding uitschakelen"},
/* pl */ {IDCLS_DISABLE_MMC64_PL, "Wy3�}cz rozszerzenie MMC64"},
/* ru */ {IDCLS_DISABLE_MMC64_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_MMC64_SV, "Inaktivera MMC64-expansion"},
/* tr */ {IDCLS_DISABLE_MMC64_TR, "MMC64 genitlemesini pasiflettir"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_SPECIFY_MMC64_BIOS_NAME,    N_("Specify name of MMC64 BIOS image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_DA, "Angiv navn pa MMC64-BIOS-image"},
/* de */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_DE, "Name fur MMC64 BIOS Datei spezifizieren"},
/* fr */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_FR, "Specifier le nom de l'image MMC64 BIOS"},
/* hu */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_HU, "Adja meg az MMC64 BIOS kepmas nevet"},
/* it */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_IT, "Specifica il nome immagine del BIOS MMC64"},
/* ko */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_NL, "Geef de naam van het MMC64 BIOS bestand"},
/* pl */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_PL, "Okre��l nazwe obrazu BIOS MMC64"},
/* ru */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_SV, "Ange namn pa MMC64-BIOS-avbildning"},
/* tr */ {IDCLS_SPECIFY_MMC64_BIOS_NAME_TR, "MMC64 BIOS imajynyn ismini belirt"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME,    N_("Specify name of MMC64 image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_DA, "Angiv navn pa MMC64-image"},
/* de */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_DE, "Name der MMC64 Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_FR, "Specifier le nom de l'image MMC64"},
/* hu */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_HU, "Adja meg az MMC64 kepmas nevet"},
/* it */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_IT, "Specifica il nome immagine MMC64"},
/* ko */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_NL, "Geef de naam van het MMC64 bestand"},
/* pl */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_PL, "Okre��l nazwe obrazu MMC64"},
/* ru */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_SV, "Ange namn pa MMC64-avbildning"},
/* tr */ {IDCLS_SPECIFY_MMC64_IMAGE_NAME_TR, "MMC64 imajynyn ismini belirt"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_MMC64_READONLY,    N_("Set the MMC64 card to read-only")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC64_READONLY_DA, "Skrivebeskyt MMC64-kort"},
/* de */ {IDCLS_MMC64_READONLY_DE, "MMC64 Karte Schreibschutz"},
/* fr */ {IDCLS_MMC64_READONLY_FR, "Definir la carte MMC64 en lecture seule"},
/* hu */ {IDCLS_MMC64_READONLY_HU, "MMC64 kartya csak olvashato"},
/* it */ {IDCLS_MMC64_READONLY_IT, "Imposta la card MMC64 in sola lettura"},
/* ko */ {IDCLS_MMC64_READONLY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC64_READONLY_NL, "Zet de MMC64 als alleen-lezen"},
/* pl */ {IDCLS_MMC64_READONLY_PL, "Ustaw karte MMC64 na tryb tylko do odczytu"},
/* ru */ {IDCLS_MMC64_READONLY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC64_READONLY_SV, "Skrivskydda MMC64-kort"},
/* tr */ {IDCLS_MMC64_READONLY_TR, "MMC64 kartyny salt okunura cevir"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_MMC64_READWRITE,    N_("Set the MMC64 card to read/write")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC64_READWRITE_DA, "Tillad skrivning pa MMC64-kort"},
/* de */ {IDCLS_MMC64_READWRITE_DE, "MMC64 Karte Schreibzugriff"},
/* fr */ {IDCLS_MMC64_READWRITE_FR, "Definir la carte MMC64 en lecture/ecriture"},
/* hu */ {IDCLS_MMC64_READWRITE_HU, "MMC64 kartya irhato/olvashato"},
/* it */ {IDCLS_MMC64_READWRITE_IT, "Imposta la card MMC64 in lettura/scrittura"},
/* ko */ {IDCLS_MMC64_READWRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC64_READWRITE_NL, "Zet de MMC64 als lezen/schrijven"},
/* pl */ {IDCLS_MMC64_READWRITE_PL, "Ustaw karte MMC64 na tryb zapisu i odczytu"},
/* ru */ {IDCLS_MMC64_READWRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC64_READWRITE_SV, "Tillat skrivning pa MMC64-kort"},
/* tr */ {IDCLS_MMC64_READWRITE_TR, "MMC64 kartyny okunur/yazylyra cevir"},
#endif

/* c64/cart/mmc64.c */
/* en */ {IDCLS_MMC64_BIOS_WRITE,    N_("Save the MMC64 bios when changed")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC64_BIOS_WRITE_DA, "Gem MMC64-BIOS ved andring"},
/* de */ {IDCLS_MMC64_BIOS_WRITE_DE, "MMC64 BIOS speichern bei Anderung"},
/* fr */ {IDCLS_MMC64_BIOS_WRITE_FR, "Sauvegarder le BIOS MMC64 lorsque modifie"},
/* hu */ {IDCLS_MMC64_BIOS_WRITE_HU, "MMC64 BIOS mentese valtozas utan"},
/* it */ {IDCLS_MMC64_BIOS_WRITE_IT, "Salva il bios MMC64 al cambio"},
/* ko */ {IDCLS_MMC64_BIOS_WRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC64_BIOS_WRITE_NL, "Sla de MMC64 BIOS op als er veranderingen zijn gemaakt"},
/* pl */ {IDCLS_MMC64_BIOS_WRITE_PL, "Zapisuj bios MMC64 przy zmianie"},
/* ru */ {IDCLS_MMC64_BIOS_WRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC64_BIOS_WRITE_SV, "Spara MMC64-BIOS vid andring"},
/* tr */ {IDCLS_MMC64_BIOS_WRITE_TR, "MMC64 BIOS'unu dedittidinde kaydet"},
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
/* pl */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME_PL, "Okre��l nazwe pliku obrazu karty MMC Replay"},
/* ru */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SELECT_MMC_REPLAY_CARD_IMAGE_FILENAME_SV, "Ange namn pa avbildningsfil for MMC Replay-kort"},
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
/* pl */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_PL, "W3�}cz zapis do obrazu karty MMC Replay"},
/* ru */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_SV, "Aktivera skrivning till MMC Replay-kortavbildning"},
/* tr */ {IDCLS_MMC_REPLAY_CARD_WRITE_ENABLE_TR, "MMC Replay kart imajynda yazmalary aktif et"},
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
/* pl */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_PL, "Wy3�}cz zapis do obrazu karty MMC Replay"},
/* ru */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_SV, "Inaktivera skrivning till MMC Replay-kortavbildning"},
/* tr */ {IDCLS_MMC_REPLAY_CARD_WRITE_DISABLE_TR, "MMC Replay kart imajynda yazmalary pasiflettir"},
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
/* pl */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE_PL, "Okre��l nazwe pliku obrazu EEPROM MMC Replay"},
/* ru */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SELECT_MMC_REPLAY_EEPROM_IMAGE_SV, "Ange filnamn for MMC Replay EEPROM-avbildning"},
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
/* ko */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_KO, "MMC Replay EEPROM AI1IAo ?! ?2�}a ��!�LECI��O CI�}a"},
/* nl */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_NL, "Aktiveer schrijven naar MMC Replay EEPROM bestand"},
/* pl */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_PL, "W3�}cz zapis do obrazu EEPROM MMC Replay"},
/* ru */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_SV, "Aktivera skrivning till MMC Replay EEPROM-avbildning"},
/* tr */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_ENABLE_TR, "MMC Replay EEPROM imajynda yazmalary aktif et"},
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
/* pl */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_PL, "Wy3�}cz zapis do obrazu EEPROM MMC Replay"},
/* ru */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_SV, "Inaktivera skrivning till MMC Replay EEPROM-avbildning"},
/* tr */ {IDCLS_MMC_REPLAY_EEPROM_WRITE_DISABLE_TR, "MMC Replay EEPROM imajynda yazmalary pasiflettir"},
#endif

/* c64/cart/mmcreplay.c */
/* en */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE,    N_("Enable MMC Replay rescue mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_DA, "Aktiver MMC Replay fejlsikret tilstand"},
/* de */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_DE, "MMC Replay Rescue Modus aktivieren"},
/* fr */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_IT, "Attiva modalita ripristino MMC Replay"},
/* ko */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_NL, "Activeer MMC Replay reddingsmodus"},
/* pl */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_PL, "W3�}cz tryb ratunkowy MMC Replay"},
/* ru */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_SV, "Aktivera MMC Replay-raddningslage"},
/* tr */ {IDCLS_MMC_REPLAY_RESCUE_MODE_ENABLE_TR, "MMC Replay kurtarma modunu aktif et"},
#endif

/* c64/cart/mmcreplay.c */
/* en */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE,    N_("Disable MMC Replay rescue mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_DA, "Deaktiver MMC Replay fejlsikret tilstand"},
/* de */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_DE, "MMC Replay Rescue Modus deaktivieren"},
/* fr */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_IT, "Disattiva modalita ripristino MMC Replay"},
/* ko */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_NL, "MMC Replay reddingsmodus uitschakelen"},
/* pl */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_PL, "Wy3�}cz tryb ratunkowy MMC Replay"},
/* ru */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_SV, "Inaktivera MMC Replay-raddningslage"},
/* tr */ {IDCLS_MMC_REPLAY_RESCUE_MODE_DISABLE_TR, "MMC Replay kurtarma modunu pasiflettir"},
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
/* pl */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_PL, "Pozwol na zapis do obrazu MMC Replay"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_SV, "Tillat skrivning till MMC Replay-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_MMC_REPLAY_IMAGE_TR, "MMC Replay imajyna yazmayy aktif et"},
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
/* pl */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_PL, "Nie zapisuj do obrazu MMC Replay"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_SV, "Skriv inte till MMC Replay-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_MMC_REPLAY_IMAGE_TR, "MMC Replay imajyna yazma"},
#endif

/* c64/cart/retroreplay.c */
/* en */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT,    N_("Enable saving of the RR ROM at exit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_DA, "Aktiver skrivning af RR ROM ved afslutning"},
/* de */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_DE, "Speichern des RR ROMs beim Beenden aktivieren"},
/* fr */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_IT, "Attiva salvataggio della RR ROM all'uscita"},
/* ko */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_NL, "Activeer opslaan van het RR ROM bestand bij afsluiten"},
/* pl */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_PL, "W3�}az zapis ROM RR przy wyj��ciu"},
/* ru */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_SV, "Aktivera sparande av RR-ROM vid avslutning"},
/* tr */ {IDCLS_ENABLE_SAVE_RR_ROM_AT_EXIT_TR, "Cykytta RR ROM'un kaydedilmesini aktif et"},
#endif

/* c64/cart/retroreplay.c */
/* en */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT,    N_("Disable saving of the RR ROM at exit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_DA, "Dektiver skrivning af RR ROM ved afslutning"},
/* de */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_DE, "Speichern des RR ROMs beim Beenden deaktivieren"},
/* fr */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_IT, "Disattiva salvataggio della RR ROM all'uscita"},
/* ko */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_NL, "Uitschakelen van het opslaan van het RR ROM bestand bij afsluiten"},
/* pl */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_PL, "Wy3�}az zapis ROM RR przy wyj��ciu"},
/* ru */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_SV, "Inaktivera sparande av RR-ROM vid avslutning"},
/* tr */ {IDCLS_DISABLE_SAVE_RR_ROM_AT_EXIT_TR, "Cykytta RR ROM'un kaydedilmesini pasiflettir"},
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
/* pl */ {IDCLS_SET_RR_BANK_JUMPER_PL, "Ustaw prze3�}cznik RR Bank"},
/* ru */ {IDCLS_SET_RR_BANK_JUMPER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_RR_BANK_JUMPER_SV, "Aktivera RR-bankbygel"},
/* tr */ {IDCLS_SET_RR_BANK_JUMPER_TR, "RR Bank Jumper'y tak"},
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
/* pl */ {IDCLS_UNSET_RR_BANK_JUMPER_PL, "Wy3�}cz prze3�}cznik RR Bank"},
/* ru */ {IDCLS_UNSET_RR_BANK_JUMPER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_UNSET_RR_BANK_JUMPER_SV, "Inaktivera RR-bankbygel"},
/* tr */ {IDCLS_UNSET_RR_BANK_JUMPER_TR, "RR Bank Jumper'y cykart"},
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
/* pl */ {IDCLS_SET_RR_FLASH_JUMPER_PL, "Ustaw prze3�}cznik RR Flash"},
/* ru */ {IDCLS_SET_RR_FLASH_JUMPER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_RR_FLASH_JUMPER_SV, "Satt RR-flashbygel"},
/* tr */ {IDCLS_SET_RR_FLASH_JUMPER_TR, "RR Flash Jumper'y tak"},
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
/* pl */ {IDCLS_UNSET_RR_FLASH_JUMPER_PL, "Wy3�}cz prze3�}cznik RR Bank"},
/* ru */ {IDCLS_UNSET_RR_FLASH_JUMPER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_UNSET_RR_FLASH_JUMPER_SV, "Inaktivera RR-bankbygel"},
/* tr */ {IDCLS_UNSET_RR_FLASH_JUMPER_TR, "RR Bank Jumper'y cykart"},
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
/* pl */ {IDCLS_ENABLE_REU_PL, "W3�}cz RAM Expansion Unit"},
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
/* pl */ {IDCLS_DISABLE_REU_PL, "Wy3�}cz RAM Expansion Unit"},
/* ru */ {IDCLS_DISABLE_REU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_REU_SV, "Inaktivera RAM-expansionsenhet"},
/* tr */ {IDCLS_DISABLE_REU_TR, ""},  /* fuzzy */
#endif

/* c64/cart/reu.c */
/* en */ {IDCLS_SPECIFY_REU_NAME,    N_("Specify name of REU image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_REU_NAME_DA, "Angiv navn pa REU-image"},
/* de */ {IDCLS_SPECIFY_REU_NAME_DE, "Namen fur REU Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_REU_NAME_FR, "Specifier le nom de l'image REU"},
/* hu */ {IDCLS_SPECIFY_REU_NAME_HU, "Adja meg a REU kepmas nevet"},
/* it */ {IDCLS_SPECIFY_REU_NAME_IT, "Specifica il nome immagine REU"},
/* ko */ {IDCLS_SPECIFY_REU_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_REU_NAME_NL, "Geef de naam van het REU bestand"},
/* pl */ {IDCLS_SPECIFY_REU_NAME_PL, "Okre��l nazwe obrazu REU"},
/* ru */ {IDCLS_SPECIFY_REU_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_REU_NAME_SV, "Ange namn pa REU-avbildning"},
/* tr */ {IDCLS_SPECIFY_REU_NAME_TR, "REU imajynyn ismini belirt"},
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
/* pl */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_PL, "Pozwol na zapis do obrazu REU"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_SV, "Tillat skrivning till REU-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_REU_IMAGE_TR, "REU imajyna yazmayy aktif et"},
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
/* pl */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_PL, "Nie zapisuj do obrazu REU"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_SV, "Skriv inte till REU-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_REU_IMAGE_TR, "REU imajyna yazma"},
#endif

/* c64/cart/reu.c */
/* en */ {IDCLS_REU_SIZE,    N_("Size of the RAM expansion unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_REU_SIZE_DA, "Storrelse pa RAM-udviddelsesenhed"},
/* de */ {IDCLS_REU_SIZE_DE, "Grose der RAM Speichererweiterung"},
/* fr */ {IDCLS_REU_SIZE_FR, "Taille de l'unite d'expansion RAM"},
/* hu */ {IDCLS_REU_SIZE_HU, "RAM Expansion Unit merete"},
/* it */ {IDCLS_REU_SIZE_IT, "Dimensione dell'espansione di RAM"},
/* ko */ {IDCLS_REU_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_REU_SIZE_NL, "Grootte van de RAM uitbreidingseenheid (REU)"},
/* pl */ {IDCLS_REU_SIZE_PL, "Rozmiar jednostki rozszerzenia RAM"},
/* ru */ {IDCLS_REU_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_REU_SIZE_SV, "Storlek pa RAM-expansionsenhet"},
/* tr */ {IDCLS_REU_SIZE_TR, "RAM genitletme biriminin boyutu"},
#endif

#ifdef HAVE_TFE
/* c64/cart/tfe.c */
/* en */ {IDCLS_ENABLE_TFE,    N_("Enable the TFE (\"The Final Ethernet\") unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_TFE_DA, "Aktiver TFE-enhed (\"The Final Ethernet\")"},
/* de */ {IDCLS_ENABLE_TFE_DE, "TFE (\"the final ethernet\") Erweiterung aktivitieren"},
/* fr */ {IDCLS_ENABLE_TFE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_TFE_HU, "TFE (\"the final ethernet\") egyseg engedelyezese"},
/* it */ {IDCLS_ENABLE_TFE_IT, "Attiva l'unita TFE (\"The Final Ethernet\")"},
/* ko */ {IDCLS_ENABLE_TFE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_TFE_NL, "Activeer de TFE (\"The Final Ethernet\") eenheid"},
/* pl */ {IDCLS_ENABLE_TFE_PL, "W3�}cz jednostke TFE (\"The Final Ethernet\")"},
/* ru */ {IDCLS_ENABLE_TFE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_TFE_SV, "Aktivera TFE-enhet (\"The Final Ethernet\")"},
/* tr */ {IDCLS_ENABLE_TFE_TR, "TFE (\"The Final Ethernet\") birimini aktif et"},
#endif

/* c64/cart/tfe.c */
/* en */ {IDCLS_DISABLE_TFE,    N_("Disable the TFE (\"The Final Ethernet\") unit")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_TFE_DA, "Deaktiver TFE-enhed (\"The Final Ethernet\")"},
/* de */ {IDCLS_DISABLE_TFE_DE, "TFE (\"the final ethernet\") Erweiterung deaktivitieren"},
/* fr */ {IDCLS_DISABLE_TFE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_TFE_HU, "TFE (\"The Final Ethernet\") egyseg tiltasa"},
/* it */ {IDCLS_DISABLE_TFE_IT, "Disattiva l'unita TFE (\"The Final Ethernet\")"},
/* ko */ {IDCLS_DISABLE_TFE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_TFE_NL, "De TFE (\"The Final Ethernet\") eenheid uitschakelen"},
/* pl */ {IDCLS_DISABLE_TFE_PL, "Wy3�}cz jednostke TFE (\"The Final Ethernet\")"},
/* ru */ {IDCLS_DISABLE_TFE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_TFE_SV, "Inaktivera TFE-enhet (\"The Final Ethernet\")"},
/* tr */ {IDCLS_DISABLE_TFE_TR, "TFE (\"The Final Ethernet\") birimini pasiflettir"},
#endif

/* c64/cart/tfe.c */
/* en */ {IDCLS_TFE_INTERFACE,    N_("Set the system ethernet interface for TFE emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TFE_INTERFACE_DA, "Indstil systemets netkort til TFE-emulering"},
/* de */ {IDCLS_TFE_INTERFACE_DE, "Setze die System Ethernet Schnittstelle fur die TFE Emulation"},
/* fr */ {IDCLS_TFE_INTERFACE_FR, "Definir l�finterface ethernet pour l�femulation TFE"},
/* hu */ {IDCLS_TFE_INTERFACE_HU, "Rendszer ethernet eszkoz beallitasa TFE emulaciohoz"},
/* it */ {IDCLS_TFE_INTERFACE_IT, "Imposta l'interfaccia ethernet per l'emulazione TFE"},
/* ko */ {IDCLS_TFE_INTERFACE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TFE_INTERFACE_NL, "Zet de systeem ethernetinterface voor de TFE emulatie"},
/* pl */ {IDCLS_TFE_INTERFACE_PL, "Ustaw interfejs systemowy ethernet emulacji TFE"},
/* ru */ {IDCLS_TFE_INTERFACE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TFE_INTERFACE_SV, "Stall in systemets ethernetgranssnitt for TFE-emulering"},
/* tr */ {IDCLS_TFE_INTERFACE_TR, "Sistem ethernet arabirimini TFE emulasyonu icin ayarla"},
#endif

/* c64/cart/tfe.c */
/* en */ {IDCLS_ENABLE_TFE_AS_RRNET,    N_("Enable RRNet mode of TFE emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_TFE_AS_RRNET_DA, "Aktiver RRNet-tilstand af TFE-emulering"},
/* de */ {IDCLS_ENABLE_TFE_AS_RRNET_DE, "RRNet Modus der TFE Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_TFE_AS_RRNET_FR, "Activer le mode RRNet de l�femulation TFE"},
/* hu */ {IDCLS_ENABLE_TFE_AS_RRNET_HU, "RRNet mod engedelyezese TFE emulaciohoz"},
/* it */ {IDCLS_ENABLE_TFE_AS_RRNET_IT, "Attiva la modalita RRNet dell'emulazione TFE"},
/* ko */ {IDCLS_ENABLE_TFE_AS_RRNET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_TFE_AS_RRNET_NL, "Activeer RRNet modus van de TFE emulatie"},
/* pl */ {IDCLS_ENABLE_TFE_AS_RRNET_PL, "W3�}cz tryb RRNet emulacji TFE"},
/* ru */ {IDCLS_ENABLE_TFE_AS_RRNET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_TFE_AS_RRNET_SV, "Aktivera RRNet-lage pa TFE-emulering"},
/* tr */ {IDCLS_ENABLE_TFE_AS_RRNET_TR, "TFE emulasyonunun RRNet modunu aktif et"},
#endif

/* c64/cart/tfe.c */
/* en */ {IDCLS_DISABLE_TFE_AS_RRNET,    N_("Disable RRNet mode of TFE emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_TFE_AS_RRNET_DA, "Deaktiver RRNet-lage af TFE-emulering"},
/* de */ {IDCLS_DISABLE_TFE_AS_RRNET_DE, "RRNet Modus der TFE Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_TFE_AS_RRNET_FR, "Desactiver le mode RRNet de l�femulation TFE"},
/* hu */ {IDCLS_DISABLE_TFE_AS_RRNET_HU, "RRNet mod tiltasa TFE emulaciohoz"},
/* it */ {IDCLS_DISABLE_TFE_AS_RRNET_IT, "Disattiva la modalita RRNet dell'emulazione TFE"},
/* ko */ {IDCLS_DISABLE_TFE_AS_RRNET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_TFE_AS_RRNET_NL, "RRNet modus van de TFE emulatie uitschakelen"},
/* pl */ {IDCLS_DISABLE_TFE_AS_RRNET_PL, "Wy3�}cz tryb RRNet emulacji TFE"},
/* ru */ {IDCLS_DISABLE_TFE_AS_RRNET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_TFE_AS_RRNET_SV, "Inaktivera RRNet-lage pa TFE-emulering"},
/* tr */ {IDCLS_DISABLE_TFE_AS_RRNET_TR, "TFE emulasyonunun RRNet modunu pasiflettir"},
#endif
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_CART_ATTACH_DETACH_RESET,    N_("Reset machine if a cartridge is attached or detached")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_CART_ATTACH_DETACH_RESET_DA, "Reset maskinen hvis et cartridge tilsluttes eller frakobles"},
/* de */ {IDCLS_CART_ATTACH_DETACH_RESET_DE, "Reset der Maschine wenn ein Erweiterungsmodul eingelegt oder entfernt wird"},
/* fr */ {IDCLS_CART_ATTACH_DETACH_RESET_FR, "Reinitialiser si une cartouche est inseree ou retiree"},
/* hu */ {IDCLS_CART_ATTACH_DETACH_RESET_HU, "Reset a cartridge csatolasakorgy levalasztasakor"},
/* it */ {IDCLS_CART_ATTACH_DETACH_RESET_IT, "Fare il reset della macchina se una cartuccia e collegata o rimossa"},
/* ko */ {IDCLS_CART_ATTACH_DETACH_RESET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_CART_ATTACH_DETACH_RESET_NL, "Reset machine als een cartridge wordt gekoppeld of ontkoppeld"},
/* pl */ {IDCLS_CART_ATTACH_DETACH_RESET_PL, "Reset maszyny przy zamontowaniu i odmontowaniu kartrid?a"},
/* ru */ {IDCLS_CART_ATTACH_DETACH_RESET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_CART_ATTACH_DETACH_RESET_SV, "Nollstall maskinen om en insticksmodul kopplas till eller fran"},
/* tr */ {IDCLS_CART_ATTACH_DETACH_RESET_TR, "Bir kartut takylyr ya da cykartylyrsa makineyi resetle"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_CART_ATTACH_DETACH_NO_RESET,    N_("Do not reset machine if a cartridge is attached or detached")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_DA, "Reset ikke maskinen hvis et cartridge tilsluttes eller frakobles"},
/* de */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_DE, "Kein Reset der Maschine wenn ein Erweiterungsmodul eingelegt oder entfernt wird"},
/* fr */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_FR, "Ne pas reinitialiser si une cartouche est inseree ou retiree"},
/* hu */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_HU, "Nincs reset a cartridge csatolasakorgy levalasztasakor"},
/* it */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_IT, "Non fare il reset della macchina se una cartuccia e collegata o rimossa"},
/* ko */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_NL, "Reset machine niet als een cartridge wordt gekoppeld of ontkoppeld"},
/* pl */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_PL, "Nie resetuj maszyny przy zamontowaniu i odmontowaniu kartrid?a"},
/* ru */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_SV, "Nollstall inte maskinen om en insticksmodul kopplas till eller fran"},
/* tr */ {IDCLS_CART_ATTACH_DETACH_NO_RESET_TR, "Bir kartut takylyr ya da cykartylyrsa makineyi resetleme"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_CRT_CART,    N_("Attach CRT cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_CRT_CART_DA, "Tilslut CRT-cartridge image"},
/* de */ {IDCLS_ATTACH_CRT_CART_DE, "CRT Erweiterungsmodul Image einlegen"},
/* fr */ {IDCLS_ATTACH_CRT_CART_FR, "Inserer une cartouche CRT"},
/* hu */ {IDCLS_ATTACH_CRT_CART_HU, "CRT cartridge kepmas csatolasa"},
/* it */ {IDCLS_ATTACH_CRT_CART_IT, "Seleziona immagine cartuccia CRT"},
/* ko */ {IDCLS_ATTACH_CRT_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_CRT_CART_NL, "Koppel CRT cartridge bestand aan"},
/* pl */ {IDCLS_ATTACH_CRT_CART_PL, "Zamontuj obraz kartrid?a CRT"},
/* ru */ {IDCLS_ATTACH_CRT_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_CRT_CART_SV, "Anslut CRT-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_CRT_CART_TR, "CRT kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_GENERIC_8KB_CART,    N_("Attach raw 8KB cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_GENERIC_8KB_CART_DA, "Tilslut rat 8KB-cartridge image"},
/* de */ {IDCLS_ATTACH_GENERIC_8KB_CART_DE, "8KB Erweiterungsmodul (raw) Image einlegen"},
/* fr */ {IDCLS_ATTACH_GENERIC_8KB_CART_FR, "Inserer une cartouche 8KO"},
/* hu */ {IDCLS_ATTACH_GENERIC_8KB_CART_HU, "Nyers 8KB-os cartridge kepmas csatolasa"},
/* it */ {IDCLS_ATTACH_GENERIC_8KB_CART_IT, "Seleziona immagine cartuccia di 8KB"},
/* ko */ {IDCLS_ATTACH_GENERIC_8KB_CART_KO, "8kb A��AR�CRAo AI1IAo�C| oUAI???a"},
/* nl */ {IDCLS_ATTACH_GENERIC_8KB_CART_NL, "Koppel binair 8KB cartridge bestand"},
/* pl */ {IDCLS_ATTACH_GENERIC_8KB_CART_PL, "Zamontuj surowy obraz kartrid?a 8KB"},
/* ru */ {IDCLS_ATTACH_GENERIC_8KB_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_GENERIC_8KB_CART_SV, "Anslut ra 8KB-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_GENERIC_8KB_CART_TR, "Duz 8KB kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_GENERIC_16KB_CART,    N_("Attach raw 16KB cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_GENERIC_16KB_CART_DA, "Tilslut rat 16KB-cartridge image"},
/* de */ {IDCLS_ATTACH_GENERIC_16KB_CART_DE, "16KB Erweiterungsmodul (raw) Image einlegen"},
/* fr */ {IDCLS_ATTACH_GENERIC_16KB_CART_FR, "Inserer une cartouche 16KO"},
/* hu */ {IDCLS_ATTACH_GENERIC_16KB_CART_HU, "Nyers 16KB-os cartridge kepmas csatolasa"},
/* it */ {IDCLS_ATTACH_GENERIC_16KB_CART_IT, "Seleziona immagine cartuccia di 16KB"},
/* ko */ {IDCLS_ATTACH_GENERIC_16KB_CART_KO, "16kb A��AR�CRAo AI1IAo�C| oUAI???a"},
/* nl */ {IDCLS_ATTACH_GENERIC_16KB_CART_NL, "Koppel binair 16KB cartridge bestand"},
/* pl */ {IDCLS_ATTACH_GENERIC_16KB_CART_PL, "Zamontuj surowy obraz kartrid?a 16KB"},
/* ru */ {IDCLS_ATTACH_GENERIC_16KB_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_GENERIC_16KB_CART_SV, "Anslut ra 16KB-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_GENERIC_16KB_CART_TR, "Duz 16KB kartut imajy yerlettir"},
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
/* pl */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_PL, "Zamontuj standardowy obraz kartrid?a 16kB Ultimax"},
/* ru */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_SV, "Anslut vanlig 16KB Ultimax-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_GENERIC_16KB_ULTIMAX_CART_TR, "Jenerik 16KB Ultimax kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_STARDOS_CART,    N_("Attach raw 16KB Stardos cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_STARDOS_CART_DA, "Tilslut rat 16KB StarDOS cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_STARDOS_CART_DE, "16kB Stardos Erweiterungsmodul Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_STARDOS_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_STARDOS_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_STARDOS_CART_IT, "Seleziona immagine cartuccia Stardos di 16KB"},
/* ko */ {IDCLS_ATTACH_RAW_STARDOS_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_STARDOS_CART_NL, "Koppel binair 16KB Stardos cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_STARDOS_CART_PL, "Zamontuj surowy obraz kartrid?a 16KB Stardos"},
/* ru */ {IDCLS_ATTACH_RAW_STARDOS_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_STARDOS_CART_SV, "Anslut ra 16KB Stardos-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_STARDOS_CART_TR, "Duz 16KB Stardos kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART,    N_("Attach raw 32KB Action Replay MK4 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_DA, "Tilslut rat 32KB Action Replay MK4 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_DE, "32kB Action Replay MK4 Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_IT, "Seleziona immagine cartuccia Action Replay MK4 di 326KB"},
/* ko */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_NL, "Koppel binair 32KB Action Replay MK4 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_PL, "Zamontuj surowy obraz kartrid?a 32KB Action Replay MK4"},
/* ru */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_SV, "Anslut ra 32KB-Action Replay MK4-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY4_CART_TR, "Duz 32KB Action Replay MK4 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART,    N_("Attach raw 16kB Action Replay MK2 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_DA, "Tilslut rat 16KB Action Replay MK2 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_DE, "16kB Action Replay MK2 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_IT, "Seleziona immagine cartuccia Action Replay MK2 di 16KB"},
/* ko */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_NL, "Koppel binair 16kB Action Replay MK2 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_PL, "Zamontuj surowy obraz kartrid?a 16kB Action Replay MK2"},
/* ru */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_SV, "Anslut ra 16KB-Action Replay MK2-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY2_CART_TR, "Duz 16kB Action Replay MK2 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART,    N_("Attach raw 16KB Action Replay MK3 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_DA, "Tilslut rat 16KB Action Replay MK3 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_DE, "16kB Action Replay MK3 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_IT, "Seleziona immagine cartuccia Action Replay MK3 di 16KB"},
/* ko */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_NL, "Koppel binair 16KB Action Replay MK3 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_PL, "Zamontuj surowy obraz kartrid?a 16KB Action Replay MK3"},
/* ru */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_SV, "Anslut ra 16KB-Action Replay MK3-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY3_CART_TR, "Duz 16KB Action Replay MK3 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART,    N_("Attach raw 32KB Action Replay cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_DA, "Tilslut rat 32KB Action Replay cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_DE, "32kB Action Replay Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_FR, "Inserer une cartouche Action Replay 32KO"},
/* hu */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_HU, "32KB-os Action Replay cartridge kepmas csatolasa"},
/* it */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_IT, "Seleziona immagine cartuccia Action Replay di 32KB"},
/* ko */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_NL, "Koppel binair 32KB Action Replay cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_PL, "Zamontuj surowy obraz kartid?a 32KB Action Replay"},
/* ru */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_SV, "Anslut ra 32KB-Action Replay-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_ACTION_REPLAY_CART_TR, "Duz 32KB Action Replay kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_CAPTURE_CART,    N_("Attach raw 8kB Capture cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_CAPTURE_CART_DA, "Tilslut rat 8KB cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_CAPTURE_CART_DE, "8kB Capture Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_CAPTURE_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_CAPTURE_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_CAPTURE_CART_IT, "Seleziona immagine cartuccia Capture di 8KB"},
/* ko */ {IDCLS_ATTACH_RAW_CAPTURE_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_CAPTURE_CART_NL, "Koppel binair 8kB Capture cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_CAPTURE_CART_PL, "Zamontuj surowy obraz kartrid?a 8kB Capture"},
/* ru */ {IDCLS_ATTACH_RAW_CAPTURE_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_CAPTURE_CART_SV, "Anslut ra 8KB Capture-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_CAPTURE_CART_TR, "Duz 8kB Capture kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_COMAL80_CART,    N_("Attach raw 64kB Comal 80 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_COMAL80_CART_DA, "Tilslut rat 64KB Comal 80 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_COMAL80_CART_DE, "64kB Comal 80 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_COMAL80_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_COMAL80_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_COMAL80_CART_IT, "Seleziona immagine cartuccia Comal 80 di 64kB"},
/* ko */ {IDCLS_ATTACH_RAW_COMAL80_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_COMAL80_CART_NL, "Koppel binair 64kB Comal 80 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_COMAL80_CART_PL, "Zamontuj surowy obraz kartrid?a 64kB Comal 80"},
/* ru */ {IDCLS_ATTACH_RAW_COMAL80_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_COMAL80_CART_SV, "Anslut ra 64kB Comal 80-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_COMAL80_CART_TR, "Duz 64kB Comal 80 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_DELA_EP256_CART,    N_("Attach raw Dela EP256 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_DA, "Tilslut rat Dela EP256 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_DE, "Dela EP256 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_IT, "Seleziona immagine cartuccia Dela EP256"},
/* ko */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_NL, "Koppel binair Dela EP256 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_PL, "Zamontuj surowy obraz kartrid?a Dela EP256"},
/* ru */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_SV, "Anslut ra dela EP256-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_DELA_EP256_CART_TR, "Duz Dela EP256 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_DELA_EP64_CART,    N_("Attach raw Dela EP64 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_DA, "Tilslut rat Dela EP64 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_DE, "Dela EP64 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_IT, "Seleziona immagine cartuccia Dela EP64"},
/* ko */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_NL, "Koppel binair Dela EO64 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_PL, "Zamontuj surowy obraz kartrid?a EP64"},
/* ru */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_SV, "Anslut ra Dela EP64-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_DELA_EP64_CART_TR, "Duz Dela EP64 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART,    N_("Attach raw Dela EP7x8 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_DA, "Tilslut rat Dela EP7x8 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_DE, "Dela EP7x8 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_IT, "Seleziona immagine cartuccia Dela EP7x8"},
/* ko */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_NL, "Koppel binair Dela ep7x8 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_PL, "Zamontuj surowy obraz kartrid?a Dela EP7x8"},
/* ru */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_SV, "Anslut ra Dela EP7x8-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_DELA_EP7X8_CART_TR, "Duz Dela EP7x8 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_DINAMIC_CART,    N_("Attach raw 128kB Dinamic cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_DINAMIC_CART_DA, "Tilslut rat 128KB Dinamic cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_DINAMIC_CART_DE, "128kB Dinamic Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_DINAMIC_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_DINAMIC_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_DINAMIC_CART_IT, "Seleziona immagine cartuccia Dinamic di 128kB"},
/* ko */ {IDCLS_ATTACH_RAW_DINAMIC_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_DINAMIC_CART_NL, "Koppel binair 128kB Dinamic cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_DINAMIC_CART_PL, "Zamontuj surowy obraz kartrid?a 128kB Dinamic"},
/* ru */ {IDCLS_ATTACH_RAW_DINAMIC_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_DINAMIC_CART_SV, "Anslut ra 12kB Dinamic-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_DINAMIC_CART_TR, "Duz 128kB Dinamic kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART,    N_("Attach raw 8kB Diashow-Maker cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_DA, "Tilslut rat 8KB Diashow-Maker cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_DE, "8kB Diashow-Maker Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_IT, "Seleziona immagine cartuccia Diashow-Maker di 8KB"},
/* ko */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_NL, "Koppel binair 8kB Diashow-Maker cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_PL, "Zamontuj surowy obraz kartrid?a 8kB Diashow-Maker"},
/* ru */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_SV, "Anslut ra 8kB Diashow-Maker-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_DIASHOW_MAKER_CART_TR, "Duz 8kB Diashow-Maker kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_DQBB_CART,    N_("Attach raw 16kB Double Quick Brown Box cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_DQBB_CART_DA, "Tilslut rat 16kB Double Quick Brown Box cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_DQBB_CART_DE, "16kB Double Quick Brown Box Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_DQBB_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_DQBB_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_DQBB_CART_IT, "Seleziona immagine cartuccia Double Quick Brown Box di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_DQBB_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_DQBB_CART_NL, "Koppel binair 16kB Double Quick Brown Box cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_DQBB_CART_PL, "Zamontuj surowy obraz kartrid?a Double Quick Brown Box"},
/* ru */ {IDCLS_ATTACH_RAW_DQBB_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_DQBB_CART_SV, "Anslut ra 16KB Double Quick Brown Box-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_DQBB_CART_TR, "Duz 16kB Double Quick Brown Box kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART,    N_("Attach raw EasyFlash cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_DA, "Tilslut rat EasyFlash cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_DE, "Easyflash Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_IT, "Seleziona immagine cartuccia EasyFlash"},
/* ko */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_KO, "EasyFlash A��AR�CRAo AI1IAo�C| oUAI???a"},
/* nl */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_NL, "Koppel binair EasyFlash cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_PL, "Zamontuj surowy obraz kartrid?a EasyFlash"},
/* ru */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_SV, "Anslut ra EasyFlash-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_EASY_FLASH_CART_TR, "Duz EasyFlash kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART,    N_("Attach raw 64KB Retro Replay cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_DA, "Tilslut rat 64KB-Retro Replay-cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_DE, "64kB Retro Replay Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_FR, "Inserer une cartouche Retro Replay 64KO"},
/* hu */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_HU, "64KB-os Retro Replay cartridge kepmas csatolasa"},
/* it */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_IT, "Seleziona immagine cartuccia Retro Replay di 64KB"},
/* ko */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_KO, "64KB Retro Replay A��AR�CRAo AI1IAo�C| oUAI???a"},
/* nl */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_NL, "Koppel binair 64KB Retro Replay cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_PL, "Zamontuj surowy obraz kartrid?a 64KB Retro Replay"},
/* ru */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_SV, "Anslut ra 64KB-Retro Replay-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_RETRO_REPLAY_CART_TR, "Duz 64KB Retro Replay kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART,    N_("Attach raw 8kB REX Utility cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_DA, "Tilslut rat 8KB REX Utility cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_DE, "8kB REX Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_IT, "Seleziona immagine cartuccia REX Utility di 8kB"},
/* ko */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_NL, "Koppel binair 8kB REX Utility cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_PL, "Zamontuj surowy obraz kartrid?a 8kB REX Utility"},
/* ru */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_SV, "Anslut ra 8kB REX Utility-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_REX_UTILITY_CART_TR, "Duz 8kB REX Utility kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_SS64_CART,    N_("Attach raw 4kB Snapshot 64 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_SS64_CART_DA, "Tilslut rat 4KB Snapshot 64 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_SS64_CART_DE, "4kB Snapshot 64 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_SS64_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_SS64_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_SS64_CART_IT, "Seleziona immagine cartuccia Snapshot 64 di 4kB"},
/* ko */ {IDCLS_ATTACH_RAW_SS64_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_SS64_CART_NL, "Koppel binair 4kB Snapshot 64 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_SS64_CART_PL, "Zamontuj surowy obraz kartrid?a 4kB Snapshot 64"},
/* ru */ {IDCLS_ATTACH_RAW_SS64_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_SS64_CART_SV, "Anslut ra 4kB Snapshot 64-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_SS64_CART_TR, "Duz 4kB Snapshot 64 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_IDE64_CART,    N_("Attach raw 64KB IDE64 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_IDE64_CART_DA, "Tilslut rat 64KB IDE64-cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_IDE64_CART_DE, "64kB IDE64 Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_IDE64_CART_FR, "Inserer une cartouche IDE64 64KO"},
/* hu */ {IDCLS_ATTACH_RAW_IDE64_CART_HU, "64KB-os IDE64 cartridge kepmas csatolasa"},
/* it */ {IDCLS_ATTACH_RAW_IDE64_CART_IT, "Seleziona immagine cartuccia IDE64 di 64KB"},
/* ko */ {IDCLS_ATTACH_RAW_IDE64_CART_KO, "64kb IDE64 A��AR�CRAo AI1IAo�C| oUAI???a"},
/* nl */ {IDCLS_ATTACH_RAW_IDE64_CART_NL, "Koppel binair 64KB IDE64 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_IDE64_CART_PL, "Zamontuj surowy obraz kartrid?a 64KB IDE64"},
/* ru */ {IDCLS_ATTACH_RAW_IDE64_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_IDE64_CART_SV, "Anslut ra 64KB IDE64-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_IDE64_CART_TR, "Duz 64KB IDE64 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART,    N_("Attach raw 32KB Atomic Power cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_DA, "Tilslut rat 32KB Atomic Power-cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_DE, "32kB Atomic Power Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_FR, "Inserer une cartouche Atomic Power 32KO"},
/* hu */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_HU, "32KB-os Atomic Power cartridge kepmas csatolasa"},
/* it */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_IT, "Seleziona immagine cartuccia Atomic Power di 32KB"},
/* ko */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_KO, "32kb Atomic Power A��AR�CRAo AI1IAo�C| oUAI???a"},
/* nl */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_NL, "Koppel binair 32KB Atomic Power cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_PL, "Zamontuj surowy obraz kartrid?a 32KB Atomic Power"},
/* ru */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_SV, "Anslut ra 32KB Atomic Power-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_ATOMIC_POWER_CART_TR, "Duz 32KB Atomic Power kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART,    N_("Attach raw 8KB Epyx FastLoad cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_DA, "Tilslut rat 8KB Epyx FastLoad cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_DE, "8kB Epyx Fastload Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_IT, "Seleziona immagine cartuccia Epyx FastLoad di 8KB"},
/* ko */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_KO, "8kb Epyx FastLoad A��AR�CRAo AI1IAo�C| oUAI???a"},
/* nl */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_NL, "Koppel binair 8KB Epyx FastLoad cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_PL, "Zamontuj obraz kartrid?a 8KB Epyx FastLoad"},
/* ru */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_SV, "Anslut ra 8KB Epyx FastLoad-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_EPYX_FASTLOAD_CART_TR, "Duz 8KB Epyx FastLoad kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_EXOS_CART,    N_("Attach raw 8kB EXOS cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_EXOS_CART_DA, "Tilslut rat 8KB EXOS cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_EXOS_CART_DE, "8kB EXOS Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_EXOS_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_EXOS_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_EXOS_CART_IT, "Seleziona immagine cartuccia EXOS di 8KB"},
/* ko */ {IDCLS_ATTACH_RAW_EXOS_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_EXOS_CART_NL, "Koppel binair 8kB EXOS cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_EXOS_CART_PL, "Zamontuj surowy obraz kartrid?a 8kB EXOS"},
/* ru */ {IDCLS_ATTACH_RAW_EXOS_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_EXOS_CART_SV, "Anslut ra 8kB EXOS-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_EXOS_CART_TR, "Duz 8kB EXOS kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_EXPERT_CART,    N_("Attach raw 8kB Expert Cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_EXPERT_CART_DA, "Tilslut rat 8KB Expert cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_EXPERT_CART_DE, "8kB Expert Cartridge Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_EXPERT_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_EXPERT_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_EXPERT_CART_IT, "Seleziona immagine cartuccia Expert Cartridge di 8kB"},
/* ko */ {IDCLS_ATTACH_RAW_EXPERT_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_EXPERT_CART_NL, "Koppel binair 8kB Expert Cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_EXPERT_CART_PL, "Zamontuj surowy obraz 8kB Expert Cartridge"},
/* ru */ {IDCLS_ATTACH_RAW_EXPERT_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_EXPERT_CART_SV, "Anslut ra 8kB Expert Cartridge-avbilding"},
/* tr */ {IDCLS_ATTACH_RAW_EXPERT_CART_TR, "Duz 8kB Expert Kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_FC1_CART,    N_("Attach raw 16kB Final Cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_FC1_CART_DA, "Tilslut rat 16KB Final Cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_FC1_CART_DE, "16kB Final Cartridge Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_FC1_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_FC1_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_FC1_CART_IT, "Seleziona immagine cartuccia Final Cartridge di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_FC1_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_FC1_CART_NL, "Koppel binair 16kB Final Cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_FC1_CART_PL, "Zamontuj surowy obraz 16kB Final Cartridge"},
/* ru */ {IDCLS_ATTACH_RAW_FC1_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_FC1_CART_SV, "Anslut ra 16kB Final Cartridge-avbilding"},
/* tr */ {IDCLS_ATTACH_RAW_FC1_CART_TR, "Duz 16kB Final kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_FC3_CART,    N_("Attach raw 64kB Final Cartridge III image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_FC3_CART_DA, "Tilslut rat 64KB Final Cartridge III image"},
/* de */ {IDCLS_ATTACH_RAW_FC3_CART_DE, "64kB Final Cartridge Image III (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_FC3_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_FC3_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_FC3_CART_IT, "Seleziona immagine cartuccia Final Cartridge III di 64kB"},
/* ko */ {IDCLS_ATTACH_RAW_FC3_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_FC3_CART_NL, "Koppel binair 16kB Final Cartridge III bestand"},
/* pl */ {IDCLS_ATTACH_RAW_FC3_CART_PL, "Zamontuj surowy obraz Final Cartridge III"},
/* ru */ {IDCLS_ATTACH_RAW_FC3_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_FC3_CART_SV, "Anslut ra 64kB Final Cartridge III-avbilding"},
/* tr */ {IDCLS_ATTACH_RAW_FC3_CART_TR, "Duz 64kB Final Cartridge III imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_FCPLUS_CART,    N_("Attach raw 32kB Final Cartridge Plus image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_FCPLUS_CART_DA, "Tilslut rat 32KB Final Cartridge Plus image"},
/* de */ {IDCLS_ATTACH_RAW_FCPLUS_CART_DE, "32kB Final Cartridge Plus Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_FCPLUS_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_FCPLUS_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_FCPLUS_CART_IT, "Seleziona immagine cartuccia Final Cartridge Plus di 32kB"},
/* ko */ {IDCLS_ATTACH_RAW_FCPLUS_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_FCPLUS_CART_NL, "Koppel binair 32kB Final Cartridge Plus bestand"},
/* pl */ {IDCLS_ATTACH_RAW_FCPLUS_CART_PL, "Zamontuj surowy obraz 32kB Final Cartridge Plus"},
/* ru */ {IDCLS_ATTACH_RAW_FCPLUS_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_FCPLUS_CART_SV, "Anslut ra 32kB Final Cartridge Plus-fil"},
/* tr */ {IDCLS_ATTACH_RAW_FCPLUS_CART_TR, "Duz 32kB Final Cartridge Plus imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART,    N_("Attach raw 8kB Freeze Frame image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_DA, "Tilslut rat 8KB Freeze Frame image"},
/* de */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_DE, "8kB Freeze Frame Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_IT, "Seleziona immagine cartuccia Freeze Frame di 8kb"},
/* ko */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_NL, "Koppel binair 8kB Freeze Frame cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_PL, "Zamontuj surowy obraz 8kB Freeze Frame"},
/* ru */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_SV, "Anslut ra 8kB Freeze Frame-avbilding"},
/* tr */ {IDCLS_ATTACH_RAW_FREEZE_FRAME_CART_TR, "Duz 8kB Freeze Frame imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART,    N_("Attach raw 32kB Freeze Machine image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_DA, "Tilslut rat 32KB Freeze Machine image"},
/* de */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_DE, "8kB Freeze Machine Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_IT, "Seleziona immagine cartuccia Freeze Machine di 32kb"},
/* ko */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_NL, "Koppel binair 32kB Freeze Machine cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_PL, "Zamontuj surowy obraz 32kB Freeze Machine"},
/* ru */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_SV, "Anslut ra 32kB Freeze Machine-avbilding"},
/* tr */ {IDCLS_ATTACH_RAW_FREEZE_MACHINE_CART_TR, "Duz 32kB Freeze Machine imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_FP_PP_CART,    N_("Attach raw 128kB Fun Play/Power Play cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_FP_PP_CART_DA, "Tilslut rat 128KB Fun Play/Power Play cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_FP_PP_CART_DE, "128kB Fun Play/Power Play Cartridge  Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_FP_PP_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_FP_PP_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_FP_PP_CART_IT, "Seleziona immagine cartuccia Fun Play/Power Play di 128kB"},
/* ko */ {IDCLS_ATTACH_RAW_FP_PP_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_FP_PP_CART_NL, "Koppel binair 128kB Fun Play/Power Play cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_FP_PP_CART_PL, "Zamontuj surowy obraz kartrid?a 128kB Fun Play/Power Play"},
/* ru */ {IDCLS_ATTACH_RAW_FP_PP_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_FP_PP_CART_SV, "Anslut ra 128kB Fun Play/Power Play-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_FP_PP_CART_TR, "Duz 128kB Fun Play/Power Play kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_SS4_CART,    N_("Attach raw 32KB Super Snapshot V4 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_SS4_CART_DA, "Tilslut rat 32KB Super Snapshot V4 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_SS4_CART_DE, "32kB Super Snapshot V4 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_SS4_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_SS4_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_SS4_CART_IT, "Seleziona immagine cartuccia Super Snapshot V4 di 32KB"},
/* ko */ {IDCLS_ATTACH_RAW_SS4_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_SS4_CART_NL, "Koppel binair 32KB Super Snapshot V4 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_SS4_CART_PL, "Zamontuj surowy obraz kartrid?a 32KB Super Snapshot V4"},
/* ru */ {IDCLS_ATTACH_RAW_SS4_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_SS4_CART_SV, "Anslut ra 32KB Super Snapshot V4-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_SS4_CART_TR, "Duz 32KB Super Snapshot V4 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_SS5_CART,    N_("Attach raw 64KB Super Snapshot V5 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_SS5_CART_DA, "Tilslut rat 64KB Super Snapshot V5 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_SS5_CART_DE, "64kB Super Snapshot V5 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_SS5_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_SS5_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_SS5_CART_IT, "Seleziona immagine cartuccia Super Snapshot V5 di 64KB"},
/* ko */ {IDCLS_ATTACH_RAW_SS5_CART_KO, "64KB Super Snapshot V5 A��AR�CRAo AI1IAo�C| oUAI???a"},
/* nl */ {IDCLS_ATTACH_RAW_SS5_CART_NL, "Koppel binair 64KB Super Snapshot V5 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_SS5_CART_PL, "Zamontuj surowy obraz kartrid?a Super Snapshot V5"},
/* ru */ {IDCLS_ATTACH_RAW_SS5_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_SS5_CART_SV, "Anslut ra 64KB-Super Snapshot V5-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_SS5_CART_TR, "Duz 64KB Super Snapshot V5 kartut imajy yerlettir"},
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
/* pl */ {IDCLS_ATTACH_CBM_IEEE488_CART_PL, "Zamontuj obraz kartrid?a IEEE-488 Interface"},
/* ru */ {IDCLS_ATTACH_CBM_IEEE488_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_CBM_IEEE488_CART_SV, "Anslut IEEE-488-granssnittsavbildningsfil"},
/* tr */ {IDCLS_ATTACH_CBM_IEEE488_CART_TR, "IEEE-488 Arabirimi kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ISEPIC_CART,    N_("Attach raw 2kB ISEPIC cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ISEPIC_CART_DA, "Tilslut rat 2KB ISEPIC-cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ISEPIC_CART_DE, "2kB ISEPIC Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ISEPIC_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_ISEPIC_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_ISEPIC_CART_IT, "Seleziona immagine cartuccia ISEPIC di 2kB"},
/* ko */ {IDCLS_ATTACH_RAW_ISEPIC_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ISEPIC_CART_NL, "Koppel binair 2kB ISEPIC cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_ISEPIC_CART_PL, "Zamontuj surowy obraz kartrid?a 2kB ISEPIC"},
/* ru */ {IDCLS_ATTACH_RAW_ISEPIC_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ISEPIC_CART_SV, "Anslut ra 2kB ISEPIC-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_ISEPIC_CART_TR, "Duz 2kB ISEPIC kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_KCS_CART,    N_("Attach raw 16kB KCS Power cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_KCS_CART_DA, "Tilslut rat 16KB KCS Power Cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_KCS_CART_DE, "16kB KCS Power Cartridge Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_KCS_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_KCS_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_KCS_CART_IT, "Seleziona immagine cartuccia KCS Power di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_KCS_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_KCS_CART_NL, "Koppel binair 16kB KSC Power cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_KCS_CART_PL, "Zamontuj surowy obraz kartrid?a 16kB KCS Power"},
/* ru */ {IDCLS_ATTACH_RAW_KCS_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_KCS_CART_SV, "Anslut ra 16KB KCS Power-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_KCS_CART_TR, "Duz 16kB KCS Power kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_KINGSOFT_CART,    N_("Attach raw 24kB Kingsoft cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_DE, "24kB Kingsoft Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_NL, "Koppel binair 24kB Kingsoft cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_PL, "Zamontuj surowy obraz kartrid?a 24kB Kingsoft"},
/* ru */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_ATTACH_RAW_KINGSOFT_CART_TR, ""},  /* fuzzy */
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MACH5_CART,    N_("Attach raw 8kB MACH 5 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MACH5_CART_DA, "Tilslut rat 8KB MACH 5 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MACH5_CART_DE, "8kB MAC 5 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MACH5_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MACH5_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MACH5_CART_IT, "Seleziona immagine cartuccia MACH 5 di 8kB"},
/* ko */ {IDCLS_ATTACH_RAW_MACH5_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_MACH5_CART_NL, "Koppel binair 8kB MACH 5 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_MACH5_CART_PL, "Zamontuj surowy obraz kartrid?a 8kB MACH 5"},
/* ru */ {IDCLS_ATTACH_RAW_MACH5_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MACH5_CART_SV, "Anslut ra 8kB MACH 5-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_MACH5_CART_TR, "Duz 8kB MACH 5 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART,    N_("Attach raw 32/64/128kB Magic Desk cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_DA, "Tilslut rat 32/64/128KB Magic Desk cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_DE, "32/64/128kB Magic Desk Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_IT, "Seleziona immagine cartuccia Magic Desk di 32/64/128kB"},
/* ko */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_NL, "Koppel binair 32/64/128kB Magic Desk cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_PL, "Zamontuj surowy obraz kartrid?a 32/64/128kB Magic Desk"},
/* ru */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_SV, "Anslut ra 32/64/128kB Magic Desk-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_MAGIC_DESK_CART_TR, "Duz 32/64/128kB Magic Desk kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART,    N_("Attach raw Magic Formel cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_DA, "Tilslut rat Magic Formel cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_DE, "Magic Formel Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_IT, "Seleziona immagine cartuccia Magic Formel"},
/* ko */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_KO, "Magic Formel A��AR�CRAo AI1IAo�C| oUAI???a"},
/* nl */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_NL, "Koppel binair Magic Formel cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_PL, "Zamontuj surowy obraz kartrid?a Magic Formel"},
/* ru */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_SV, "Anslut ra Magic Romel-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_MAGIC_FORMEL_CART_TR, "Duz Magic Formel kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART,    N_("Attach raw 8kB Mikro Assembler cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_DA, "Tilslut rat 8kB Mikro Assembler cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_DE, "8kB Mikro Assembler Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_IT, "Seleziona immagine cartuccia Mikro Assembler di 8kB"},
/* ko */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_NL, "Koppel binair 8KB Mikro Assembler cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_PL, "Zamontuj surowy obraz kartrid?a 8kB Mikro Assembler"},
/* ru */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_SV, "Anslut ra 8kB Mikro Assembler-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_MIKRO_ASSEMBLER_CART_TR, "Duz 8kB Mikro Assembler kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MMC64_CART,    N_("Attach raw 8kB MMC64 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MMC64_CART_DA, "Tilslut rat 8KB MMC64 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MMC64_CART_DE, "8kB MMC64 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MMC64_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MMC64_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MMC64_CART_IT, "Seleziona immagine cartuccia MMC64 di 8kB"},
/* ko */ {IDCLS_ATTACH_RAW_MMC64_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_MMC64_CART_NL, "Koppel binair 8kB MMC64 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_MMC64_CART_PL, "Zamontuj surowy obraz kartrid?a 8kB MMC64"},
/* ru */ {IDCLS_ATTACH_RAW_MMC64_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MMC64_CART_SV, "Anslut ra 8kB MMC64-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_MMC64_CART_TR, "Duz 8kB MMC64 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART,    N_("Attach raw 512kB MMC Replay cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_DA, "Tilslut rat 512KB MMC Replay cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_DE, "512kB MMC Replay Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_IT, "Seleziona immagine cartuccia MMC Replay di 512kB"},
/* ko */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_KO, "512KB MMC Replay A��AR�CRAo AI1IAo�C| oUAI???a"},
/* nl */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_NL, "Koppel binair 512kB MMC Replay cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_PL, "Zamontuj surowy obraz kartrid?a 512kB MMC Replay"},
/* ru */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_SV, "Anslut ra 512kB MMC Replay-avbildningsfil"},
/* tr */ {IDCLS_ATTACH_RAW_MMC_REPLAY_CART_TR, "Duz 512kB MMC Replay kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART,    N_("Attach raw 16kB Magic Voice cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_DA, "Tilslut rat 16KB Magic Voice cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_DE, "16kB Magic Voice Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_IT, "Seleziona immagine cartuccia Magic Voice di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_NL, "Koppel binair 16kB Magic Voice cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_PL, "Zamontuj surowy obraz kartrid?a 16kB Magic Voice"},
/* ru */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_SV, "Anslut ra 16kB Magic Voice-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_MAGIC_VOICE_CART_TR, "Duz 16kB Magic Voice kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_OCEAN_CART,    N_("Attach raw Ocean cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_OCEAN_CART_DA, "Tilslut rat Ocean cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_OCEAN_CART_DE, "Ocean Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_OCEAN_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_OCEAN_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_OCEAN_CART_IT, "Seleziona immagine cartuccia Ocean"},
/* ko */ {IDCLS_ATTACH_RAW_OCEAN_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_OCEAN_CART_NL, "Koppel binair Ocean cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_OCEAN_CART_PL, "Zamontuj surowy obraz kartrid?a Ocean"},
/* ru */ {IDCLS_ATTACH_RAW_OCEAN_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_OCEAN_CART_SV, "Anslut ra Ocean-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_OCEAN_CART_TR, "Duz Ocean kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_WESTERMANN_CART,    N_("Attach raw 16KB Westermann Learning cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_DA, "Tilslut rat 16KB Westermann Learning cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_DE, "16kB Westermann learning Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_IT, "Seleziona immagine cartuccia Westermann Learning di 16KB"},
/* ko */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_NL, "Koppel binair 16kB Westermann Learning cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_PL, "Zamontuj surowy obraz kartrid?a 16KB Westermann Learning"},
/* ru */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_SV, "Anslut ra 16KB Westermann Learning-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_WESTERMANN_CART_TR, "Duz 16KB Westermann Learning kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_WARPSPEED_CART,    N_("Attach raw 8kB Warp Speed cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_DA, "Tilslut rat 8KB Warp Speed cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_DE, "8kB Warp Speed Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_IT, "Seleziona immagine cartuccia Warp Speed di 8kB"},
/* ko */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_NL, "Koppel binair 8kB Warp Speed cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_PL, "Zamontuj surowy obraz kartrid?a 8kB Warp Speed"},
/* ru */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_SV, "Anslut ra 8kB-Warp Speed-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_WARPSPEED_CART_TR, "Duz 8kB Warp Speed kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ZAXXON_CART,    N_("Attach raw 16kB Zaxxon cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ZAXXON_CART_DA, "Tilslut rat 16KB Zaxxon cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ZAXXON_CART_DE, "16kB Zaxxon Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ZAXXON_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_ZAXXON_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_ZAXXON_CART_IT, "Seleziona immagine cartuccia Zaxxon di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_ZAXXON_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ZAXXON_CART_NL, "Koppel binair 16kB Zaxxon cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_ZAXXON_CART_PL, "Zamontuj surowy obraz kartrid?a 16kB Zaxxon"},
/* ru */ {IDCLS_ATTACH_RAW_ZAXXON_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ZAXXON_CART_SV, "Anslut ra 16kB Zaxxon-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_ZAXXON_CART_TR, "Duz 16kB Zaxxon kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_PAGEFOX_CART,    N_("Attach raw 64KB Pagefox cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_DE, "Pagefox Erweiterungsmodul Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_NL, "Koppel binair 64KB Pagefox cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_PL, "Zamontuj surowy obraz kartrid?a 64KB Pagefox"},
/* ru */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_ATTACH_RAW_PAGEFOX_CART_TR, ""},  /* fuzzy */
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_P64_CART,    N_("Attach raw 256KB Prophet 64 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_P64_CART_DA, "Tilslut rat 256KB Prophet 64 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_P64_CART_DE, "256KB Prophet 64 Erweiterungsmodul Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_P64_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_P64_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_P64_CART_IT, "Seleziona immagine cartuccia Prophet 64 di 256KB"},
/* ko */ {IDCLS_ATTACH_RAW_P64_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_P64_CART_NL, "Koppel binair 256KB Prophet 64 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_P64_CART_PL, "Zamontuj surowy obraz kartrid?a 256KB Prophet 64"},
/* ru */ {IDCLS_ATTACH_RAW_P64_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_P64_CART_SV, "Anslut ra 256KB Prophet 64-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_P64_CART_TR, "Duz 256KB Prophet 64 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_RAMCART_CART,    N_("Attach raw RamCart cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_RAMCART_CART_DA, "Tilslut rat RamCart cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_RAMCART_CART_DE, "RamCart Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_RAMCART_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_RAMCART_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_RAMCART_CART_IT, "Seleziona immagine cartuccia RamCart"},
/* ko */ {IDCLS_ATTACH_RAW_RAMCART_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_RAMCART_CART_NL, "Koppel binair RamCart cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_RAMCART_CART_PL, "Zamontuj surowy obraz kartrid?a RamCart"},
/* ru */ {IDCLS_ATTACH_RAW_RAMCART_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_RAMCART_CART_SV, "Anslut ra RamCart-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_RAMCART_CART_TR, "Duz RamCart kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_REU_CART,    N_("Attach raw REU cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_REU_CART_DA, "Tilslut rat REU cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_REU_CART_DE, "REU Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_REU_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_REU_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_REU_CART_IT, "Seleziona immagine cartuccia REU"},
/* ko */ {IDCLS_ATTACH_RAW_REU_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_REU_CART_NL, "Koppel binair REU cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_REU_CART_PL, "Zamontuj surowy obraz kartrid?a REU"},
/* ru */ {IDCLS_ATTACH_RAW_REU_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_REU_CART_SV, "Anslut ra REU-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_REU_CART_TR, "Duz REU kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_REX_EP256_CART,    N_("Attach raw REX EP256 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_REX_EP256_CART_DA, "Tilslut rat REX EP256 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_REX_EP256_CART_DE, "REX EP256 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_REX_EP256_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_REX_EP256_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_REX_EP256_CART_IT, "Seleziona immagine cartuccia REX EP256"},
/* ko */ {IDCLS_ATTACH_RAW_REX_EP256_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_REX_EP256_CART_NL, "Koppel binair REX EP256 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_REX_EP256_CART_PL, "Zamontuj surowy obraz kartrid?a REX EP256"},
/* ru */ {IDCLS_ATTACH_RAW_REX_EP256_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_REX_EP256_CART_SV, "Anslut ra REX EP256-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_REX_EP256_CART_TR, "Duz REX EP256 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_ROSS_CART,    N_("Attach raw 16/32kB ROSS cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_ROSS_CART_DA, "Tilslut rat 16/32KB ROSS cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_ROSS_CART_DE, "16/32kB ROSS Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_ROSS_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_ROSS_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_ROSS_CART_IT, "Seleziona immagine cartuccia ROSS di 16/32kB"},
/* ko */ {IDCLS_ATTACH_RAW_ROSS_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_ROSS_CART_NL, "Koppel binair 16/32kB ROSS cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_ROSS_CART_PL, "Zamontuj surowy obraz kartrid?a 12/32kB ROSS"},
/* ru */ {IDCLS_ATTACH_RAW_ROSS_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_ROSS_CART_SV, "Anslut ra 16/32kB ROSS-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_ROSS_CART_TR, "Duz 16/32kB ROSS kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART,    N_("Attach raw 8KB Game Killer cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_DA, "Tilslut rat 8KB Game Killer cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_DE, "8KB Game Killer Erweiterungsmodul (raw) Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_IT, "Seleziona immagine cartuccia Game Killer di 8KB"},
/* ko */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_NL, "Koppel binair 8KB Game Killer cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_PL, "Zamontuj surowy obraz kartrid?a 8KB Game Killer"},
/* ru */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_SV, "Anslut ra 8KB Game Killer-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_GAME_KILLER_CART_TR, "Duz 8KB Game Killer kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_GEORAM_CART,    N_("Attach raw GEO-RAM cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_GEORAM_CART_DA, "Tilslut rat GEO-RAM cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_GEORAM_CART_DE, "GEO-RAM Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_GEORAM_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_GEORAM_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_GEORAM_CART_IT, "Seleziona immagine cartuccia GEO-RAM"},
/* ko */ {IDCLS_ATTACH_RAW_GEORAM_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_GEORAM_CART_NL, "Koppel binair GEO-RAM cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_GEORAM_CART_PL, "Zamontuj surowy obraz kartrid?a GEO-RAM"},
/* ru */ {IDCLS_ATTACH_RAW_GEORAM_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_GEORAM_CART_SV, "Anslut ra GEO-RAM-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_GEORAM_CART_TR, "Duz GEO-RAM kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART,    N_("Attach raw 512kB Game System cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_DA, "Tilslut rat 512KB Game System cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_DE, "512kB Game System Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_IT, "Seleziona immagine cartuccia Game System di 512kB"},
/* ko */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_NL, "Koppel binair 512kB Game System cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_PL, "Zamontuj surowy obraz kartrid?a 512kB Game System"},
/* ru */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_SV, "Anslut ra 512kB Game System-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_GAME_SYSTEM_CART_TR, "Duz 512kB Game System kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c, c64/expert.c */
/* en */ {IDCLS_ENABLE_EXPERT_CART,    N_("Enable the Expert Cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_EXPERT_CART_DA, "Aktiver Expert Cartridge"},
/* de */ {IDCLS_ENABLE_EXPERT_CART_DE, "Expert Cartridge aktivieren"},
/* fr */ {IDCLS_ENABLE_EXPERT_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_EXPERT_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_EXPERT_CART_IT, "Attiva Expert Cartridge"},
/* ko */ {IDCLS_ENABLE_EXPERT_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_EXPERT_CART_NL, "Activeer Expert Cartridge"},
/* pl */ {IDCLS_ENABLE_EXPERT_CART_PL, "W3�}cz Expert Cartridge"},
/* ru */ {IDCLS_ENABLE_EXPERT_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_EXPERT_CART_SV, "Aktivera Expert Cartridge"},
/* tr */ {IDCLS_ENABLE_EXPERT_CART_TR, "Expert Kartutu'nu aktif et"},
#endif

/* c64/expert.c */
/* en */ {IDCLS_DISABLE_EXPERT_CART,    N_("Disable the Expert Cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_EXPERT_CART_DA, "Deaktiver Expert Cartridge"},
/* de */ {IDCLS_DISABLE_EXPERT_CART_DE, "Expert Cartridge deaktivieren"},
/* fr */ {IDCLS_DISABLE_EXPERT_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_EXPERT_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_EXPERT_CART_IT, "Disattiva Expert Cartridge"},
/* ko */ {IDCLS_DISABLE_EXPERT_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_EXPERT_CART_NL, "Expert Cartridge uitschakelen"},
/* pl */ {IDCLS_DISABLE_EXPERT_CART_PL, "Wy3�}cz Expert Cartridge"},
/* ru */ {IDCLS_DISABLE_EXPERT_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_EXPERT_CART_SV, "Inaktivera Expert Cartridge"},
/* tr */ {IDCLS_DISABLE_EXPERT_CART_TR, "Expert Kartutu'nu pasiflettir"},
#endif

/* c64/expert.c */
/* en */ {IDCLS_SET_EXPERT_FILENAME,    N_("Set Expert Cartridge image name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_EXPERT_FILENAME_DA, "Valg Expert cartridge image-navn"},
/* de */ {IDCLS_SET_EXPERT_FILENAME_DE, "Expert Cartridge Imagedateiname setzen"},
/* fr */ {IDCLS_SET_EXPERT_FILENAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_EXPERT_FILENAME_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_EXPERT_FILENAME_IT, "Imposta nome immagine Expert Cartridge"},
/* ko */ {IDCLS_SET_EXPERT_FILENAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_EXPERT_FILENAME_NL, "Zet Expert Cartridge bestandsnaam"},
/* pl */ {IDCLS_SET_EXPERT_FILENAME_PL, "Okre��l nazwe obrazu Expert Cartridge"},
/* ru */ {IDCLS_SET_EXPERT_FILENAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_EXPERT_FILENAME_SV, "Valj Expert Cartridge-modulfil"},
/* tr */ {IDCLS_SET_EXPERT_FILENAME_TR, "Expert Kartut imaj ismini belirle"},
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
/* pl */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_PL, "Pozwol na zapis do obrazu Expert Cartridge"},
/* ru */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_SV, "Tillat skrivning till Expert Cartridge-avbildning"},
/* tr */ {IDCLS_ALLOW_WRITING_TO_EXPERT_IMAGE_TR, "Expert Kartut imajyna yazmaya izin ver"},
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
/* pl */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_PL, "Nie zapisuj do obrazu Expert Cartridge"},
/* ru */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_SV, "Skriv inte till Expert Cartridge-avbildning"},
/* tr */ {IDCLS_DO_NOT_WRITE_TO_EXPERT_IMAGE_TR, "Expert Kartut imajyna yazma"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_DISABLE_CART,    N_("Disable default cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_CART_DA, "Deaktiver standard cartridge"},
/* de */ {IDCLS_DISABLE_CART_DE, "Standard Modul deaktivieren"},
/* fr */ {IDCLS_DISABLE_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_CART_HU, "Alap cartridge tiltasa"},
/* it */ {IDCLS_DISABLE_CART_IT, "Disattiva cartuccia predefinita"},
/* ko */ {IDCLS_DISABLE_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_CART_NL, "De standaard cartridge uitschakelen"},
/* pl */ {IDCLS_DISABLE_CART_PL, "Wy3�}cz domy��lny kartrid?"},
/* ru */ {IDCLS_DISABLE_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_CART_SV, "Inaktivera standardinsticksmodul"},
/* tr */ {IDCLS_DISABLE_CART_TR, "Varsayylan kartutu pasiflettir"},
#endif

/* plus4/plus4cart.c */
/* en */ {IDCLS_SMART_ATTACH_CART,    N_("Smart-attach cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SMART_ATTACH_CART_DA, "Smart-tilslut cartridge-image"},
/* de */ {IDCLS_SMART_ATTACH_CART_DE, "Smart-Einlegen Modul Image"},
/* fr */ {IDCLS_SMART_ATTACH_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SMART_ATTACH_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SMART_ATTACH_CART_IT, "Seleziona una cartuccia"},
/* ko */ {IDCLS_SMART_ATTACH_CART_KO, "A��AR�CRAo AI1IAo�C| ?o�C��AR-oUAI�}a CI�}a"},
/* nl */ {IDCLS_SMART_ATTACH_CART_NL, "Slim-koppel cartridge bestand"},
/* pl */ {IDCLS_SMART_ATTACH_CART_PL, "Inteligentnie zamontuj obraz kartrid?a"},
/* ru */ {IDCLS_SMART_ATTACH_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SMART_ATTACH_CART_SV, "Smartanslut insticksmodulfil"},
/* tr */ {IDCLS_SMART_ATTACH_CART_TR, "Akylly kartut imajy yerlettir"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_SPECIFY_IDE64_NAME,    N_("Specify name of IDE64 image file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_IDE64_NAME_DA, "Angiv navn pa IDE64-cartridge image"},
/* de */ {IDCLS_SPECIFY_IDE64_NAME_DE, "Namen fur IDE64 Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_IDE64_NAME_FR, "Specifier le nom de l'image IDE64"},
/* hu */ {IDCLS_SPECIFY_IDE64_NAME_HU, "Adja meg az IDE64 kepmas fajlnevet"},
/* it */ {IDCLS_SPECIFY_IDE64_NAME_IT, "Specifica il nome del file immagine dell'IDE64"},
/* ko */ {IDCLS_SPECIFY_IDE64_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_IDE64_NAME_NL, "Geef de naam van het IDE64 bestand"},
/* pl */ {IDCLS_SPECIFY_IDE64_NAME_PL, "Okre��l nazwe pliku obrazu IDE64"},
/* ru */ {IDCLS_SPECIFY_IDE64_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_IDE64_NAME_SV, "Ange namn pa IDE64-insticksmodulfil"},
/* tr */ {IDCLS_SPECIFY_IDE64_NAME_TR, "IDE64 imaj dosyasynyn ismini belirt"},
#endif

/* c64/cart/ide64.c, gfxoutputdrv/ffmpegdrv.c, datasette.c,
   debug.c, mouse.c, ram.c, sound.c, vsync.c */
/* en */ {IDCLS_P_VALUE,    N_("<value>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_VALUE_DA, "<vardi>"},
/* de */ {IDCLS_P_VALUE_DE, "<Wert>"},
/* fr */ {IDCLS_P_VALUE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_VALUE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_VALUE_IT, "<valore>"},
/* ko */ {IDCLS_P_VALUE_KO, "<��!A!>"},
/* nl */ {IDCLS_P_VALUE_NL, "<waarde>"},
/* pl */ {IDCLS_P_VALUE_PL, "<warto��a>"},
/* ru */ {IDCLS_P_VALUE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_VALUE_SV, "<varde>"},
/* tr */ {IDCLS_P_VALUE_TR, "<deder>"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64,    N_("Set number of cylinders for the IDE64 emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_DA, "Valg antal cylindrer for IDE64-emuleringen"},
/* de */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_DE, "Anzahl der Zylinder fur IDE64 Emulation"},
/* fr */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_FR, "Regler le nombre de cylindres pour l'emulation IDE64"},
/* hu */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_HU, "Adja meg a savok szamat IDE64 emulaciohoz"},
/* it */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_IT, "Imposta il numero di cilindri dell'emulazione IDE64"},
/* ko */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_NL, "Stel het aantal cylinders voor de IDE64 emulatie in"},
/* pl */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_PL, "Ustaw liczbe cylindrow w emulacji IDE64"},
/* ru */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_SV, "Valj antal cylindrar for IDE64-emuleringen"},
/* tr */ {IDCLS_SET_AMOUNT_CYLINDERS_IDE64_TR, "IDE64 emulasyonu icin silindir adedini girin"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_SET_AMOUNT_HEADS_IDE64,    N_("Set number of heads for the IDE64 emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_AMOUNT_HEADS_IDE64_DA, "Valg antal hoveder for IDE64-emuleringen"},
/* de */ {IDCLS_SET_AMOUNT_HEADS_IDE64_DE, "Anzahl der Laufwerkskopfe fur IDE64 Emulation"},
/* fr */ {IDCLS_SET_AMOUNT_HEADS_IDE64_FR, "Regler le nombre de tetes pour l'emulation IDE64"},
/* hu */ {IDCLS_SET_AMOUNT_HEADS_IDE64_HU, "Adja meg a fejek szamat IDE64 emulaciohoz"},
/* it */ {IDCLS_SET_AMOUNT_HEADS_IDE64_IT, "Imposta il numero di testine dell'emulazione IDE64"},
/* ko */ {IDCLS_SET_AMOUNT_HEADS_IDE64_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_AMOUNT_HEADS_IDE64_NL, "Stel het aantal koppen voor de IDE64 emulatie in"},
/* pl */ {IDCLS_SET_AMOUNT_HEADS_IDE64_PL, "Ustaw liczbe g3owic w emulacji IDE64"},
/* ru */ {IDCLS_SET_AMOUNT_HEADS_IDE64_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_AMOUNT_HEADS_IDE64_SV, "Ange antal huvuden for IDE64-emuleringen"},
/* tr */ {IDCLS_SET_AMOUNT_HEADS_IDE64_TR, "IDE64 emulasyonu icin kafa adedini girin"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_SET_AMOUNT_SECTORS_IDE64,    N_("Set number of sectors for the IDE64 emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_DA, "Valg antal sektorer for IDE64-emuleringen"},
/* de */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_DE, "Anzahl der Sektoren fur IDE64 Emulation"},
/* fr */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_FR, "Regler le nombre de secteurs pour l'emulation IDE64"},
/* hu */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_HU, "Adja meg a szektorok szamat IDE64 emulaciohoz"},
/* it */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_IT, "Imposta il numero di settori dell'emulazione IDE64"},
/* ko */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_NL, "Stel het aantal sectors voor de IDE64 emulatie in"},
/* pl */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_PL, "Ustaw liczbe sektorow w emulacji IDE64"},
/* ru */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_SV, "Ange antal sektorer for IDE64-emuleringen"},
/* tr */ {IDCLS_SET_AMOUNT_SECTORS_IDE64_TR, "IDE64 emulasyonu icin sektor adedini girin"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_AUTODETECT_IDE64_GEOMETRY,    N_("Autodetect image size")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_DA, "Autodetekter storrelse pa image"},
/* de */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_DE, "Image Grose automatisch erkennen"},
/* fr */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_HU, ""},  /* fuzzy */
/* it */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_IT, "Rileva automaticamente immagine"},
/* ko */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_KO, "AI1IAo Ac�}a AU��?A�C�EI A���}a"},
/* nl */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_NL, "Automatisch detecteren bestandsgrootte"},
/* pl */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_PL, "Automatycznie wykrywaj rozmiar obrazu"},
/* ru */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_SV, "Autodetektera storlek pa avbildning"},
/* tr */ {IDCLS_AUTODETECT_IDE64_GEOMETRY_TR, "Imaj boyutunu otomatik algyla"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY,    N_("Do not autodetect geometry of formatted images")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_DA, "Autodetekter ikke geometri fra formatterede images"},
/* de */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_DE, "Geometrie von formatierten Image Dateien nicht automatisch erkennen"},
/* fr */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_FR, "Ne pas detecter automatiquement la geometrie des images formattees"},
/* hu */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_HU, "Formazott kepmasok geometriajat ne ismerje fel automatikusan"},
/* it */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_IT, "Non rilevare automaticamente la geometrica delle immagini formattate"},
/* ko */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_NL, "Niet automatisch de grootte van de geformateerde bestanden detecteren"},
/* pl */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_PL, "Nie wykrywaj geometrii sformatowanych obrazow"},
/* ru */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_SV, "Autodetektera inte geometri fran formaterad avbildningsfil"},
/* tr */ {IDCLS_NO_AUTODETECT_IDE64_GEOMETRY_TR, "Formatlanmyt imajlaryn yapylaryny otomatik algylama"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_IDE64_V4,    N_("Emulate version 4 hardware")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_IDE64_V4_DA, "Emuler version 4 hardware"},
/* de */ {IDCLS_IDE64_V4_DE, "Emulation der Version 5 Hardware"},
/* fr */ {IDCLS_IDE64_V4_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_IDE64_V4_HU, ""},  /* fuzzy */
/* it */ {IDCLS_IDE64_V4_IT, "Emula hardware versione 4"},
/* ko */ {IDCLS_IDE64_V4_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_IDE64_V4_NL, "Emuleer versie 4 hardware"},
/* pl */ {IDCLS_IDE64_V4_PL, "Emuluj sprzet w wersji 4"},
/* ru */ {IDCLS_IDE64_V4_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_IDE64_V4_SV, "Emulera version 4-maskinvara"},
/* tr */ {IDCLS_IDE64_V4_TR, "Versiyon 4 donanymyny emule et"},
#endif

/* c64/cart/ide64.c */
/* en */ {IDCLS_IDE64_PRE_V4,    N_("Emulate pre version 4 hardware")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_IDE64_PRE_V4_DA, "Emuler hardware for version 4"},
/* de */ {IDCLS_IDE64_PRE_V4_DE, "Emulation der pre-Version 4 Hardware"},
/* fr */ {IDCLS_IDE64_PRE_V4_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_IDE64_PRE_V4_HU, ""},  /* fuzzy */
/* it */ {IDCLS_IDE64_PRE_V4_IT, "Emula hardware pre-versione 4"},
/* ko */ {IDCLS_IDE64_PRE_V4_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_IDE64_PRE_V4_NL, "Emuleer hardware van voor versie 4"},
/* pl */ {IDCLS_IDE64_PRE_V4_PL, "Emuluj sprzet sprzed wersji 4"},
/* ru */ {IDCLS_IDE64_PRE_V4_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_IDE64_PRE_V4_SV, "Emulera for-version 4-maskinvara"},
/* tr */ {IDCLS_IDE64_PRE_V4_TR, "On versiyon 4 donanymyny emule et"},
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
/* pl */ {IDCLS_P_MODELNUMBER_PL, "<modelnumber>"},
/* ru */ {IDCLS_P_MODELNUMBER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_MODELNUMBER_SV, "<modellnummer>"},
/* tr */ {IDCLS_P_MODELNUMBER_TR, "<modelnumarasy>"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CBM2_MODEL,    N_("Specify CBM-II model to emulate")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CBM2_MODEL_DA, "Angiv emuleret CBM-II-model"},
/* de */ {IDCLS_SPECIFY_CBM2_MODEL_DE, "CBM-II Modell fur Emulation definieren"},
/* fr */ {IDCLS_SPECIFY_CBM2_MODEL_FR, "Specifier le modele CBM-II a emuler"},
/* hu */ {IDCLS_SPECIFY_CBM2_MODEL_HU, "Adja meg az emulalando CBM-II modell szamat"},
/* it */ {IDCLS_SPECIFY_CBM2_MODEL_IT, "Specifica il modello di CBM II da emulare"},
/* ko */ {IDCLS_SPECIFY_CBM2_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CBM2_MODEL_NL, "Geef CBM-II model om te emuleren"},
/* pl */ {IDCLS_SPECIFY_CBM2_MODEL_PL, "Okre��l emulowany model CBM-II"},
/* ru */ {IDCLS_SPECIFY_CBM2_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CBM2_MODEL_SV, "Ange CBM-II-modell att emulera"},
/* tr */ {IDCLS_SPECIFY_CBM2_MODEL_TR, "Emule edilecek CBM-II modelini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_TO_USE_VIC_II,    N_("Specify to use VIC-II")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_TO_USE_VIC_II_DA, "Brug VIC-II"},
/* de */ {IDCLS_SPECIFY_TO_USE_VIC_II_DE, "VIC-II Unterstutzung aktivieren"},
/* fr */ {IDCLS_SPECIFY_TO_USE_VIC_II_FR, "Specifier l'utilisation de VIC-II"},
/* hu */ {IDCLS_SPECIFY_TO_USE_VIC_II_HU, "VIC-II hasznalata"},
/* it */ {IDCLS_SPECIFY_TO_USE_VIC_II_IT, "Specifica di utilizzare il VIC-II"},
/* ko */ {IDCLS_SPECIFY_TO_USE_VIC_II_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_TO_USE_VIC_II_NL, "Gebruik de VIC-II"},
/* pl */ {IDCLS_SPECIFY_TO_USE_VIC_II_PL, "Okre��l u?ycie VIC-II"},
/* ru */ {IDCLS_SPECIFY_TO_USE_VIC_II_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_TO_USE_VIC_II_SV, "Ange for att anvanda VIC-II"},
/* tr */ {IDCLS_SPECIFY_TO_USE_VIC_II_TR, "VIC-II kullanymy icin secin"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_TO_USE_CRTC,    N_("Specify to use CRTC")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_TO_USE_CRTC_DA, "Brug CRTC"},
/* de */ {IDCLS_SPECIFY_TO_USE_CRTC_DE, "CRTC Unterstutzung aktivieren"},
/* fr */ {IDCLS_SPECIFY_TO_USE_CRTC_FR, "Specifier l'utilisation de CRTC"},
/* hu */ {IDCLS_SPECIFY_TO_USE_CRTC_HU, "CRTC hasznalata"},
/* it */ {IDCLS_SPECIFY_TO_USE_CRTC_IT, "Specifica di utilizzare il CRTC"},
/* ko */ {IDCLS_SPECIFY_TO_USE_CRTC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_TO_USE_CRTC_NL, "Gebruik de CRTC"},
/* pl */ {IDCLS_SPECIFY_TO_USE_CRTC_PL, "Okre��l u?ycie CRTC"},
/* ru */ {IDCLS_SPECIFY_TO_USE_CRTC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_TO_USE_CRTC_SV, "Ange for att anvanda CRTC"},
/* tr */ {IDCLS_SPECIFY_TO_USE_CRTC_TR, "CRTC kullanymy icin secin"},
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
/* pl */ {IDCLS_P_LINENUMBER_PL, "<linenumber>"},
/* ru */ {IDCLS_P_LINENUMBER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_LINENUMBER_SV, "<linjenummer>"},
/* tr */ {IDCLS_P_LINENUMBER_TR, "<satyrnumarasy>"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE,    N_("Specify CBM-II model hardware (0=6x0, 1=7x0)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_DA, "Angiv hardware for CBM-II-model (0=6x0, 1=7x0)"},
/* de */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_DE, "CBM-II Hardware Modell definieren (0=6x0, 1=7x0)"},
/* fr */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_FR, "Specifier le modele hardware CBM-II (0=6x0, 1=7x0)"},
/* hu */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_HU, "Adja meg a CBM-II hardver modellt (0=6x0, 1=7x0)"},
/* it */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_IT, "Specifica il modello hardware del CBM-II (0=6x0, 1=7x0)"},
/* ko */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_NL, "Geef CBM-II hardwaremodel (0=6x0, 1=7x0)"},
/* pl */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_PL, "Okre��l model sprzetu CBM-II (0=6x0, 1=7x0)"},
/* ru */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_SV, "Ange maskinvara for CBM-II-modell (0=6x0, 1=7x0)"},
/* tr */ {IDCLS_SPECIFY_CBM2_MODEL_HARDWARE_TR, "CBM-II modeli donanymyny belirt (0=6x0, 1=7x0)"},
#endif

/* cbm2/cbm2-cmdline-options.c, plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_P_RAMSIZE,    N_("<RAM size>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_RAMSIZE_DA, ""},  /* fuzzy */
/* de */ {IDCLS_P_RAMSIZE_DE, "<RAM Grose>"},
/* fr */ {IDCLS_P_RAMSIZE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_RAMSIZE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_RAMSIZE_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_P_RAMSIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_RAMSIZE_NL, "<RAM grootte>"},
/* pl */ {IDCLS_P_RAMSIZE_PL, "<Rozmiar RAM>"},
/* ru */ {IDCLS_P_RAMSIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_RAMSIZE_SV, "<RAM-storlek>"},
/* tr */ {IDCLS_P_RAMSIZE_TR, ""},  /* fuzzy */
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_SIZE_OF_RAM,    N_("Specify size of RAM (64/128/256/512/1024 kByte)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SIZE_OF_RAM_DA, "Angiv storrelse pa RAM (64/128/256/512/1024 kByte)"},
/* de */ {IDCLS_SPECIFY_SIZE_OF_RAM_DE, "RAM Grose definieren (64/128/256/512/1024 kByte)"},
/* fr */ {IDCLS_SPECIFY_SIZE_OF_RAM_FR, "Specifier la taille de la RAM (64/128/256/512/1024 KO)"},
/* hu */ {IDCLS_SPECIFY_SIZE_OF_RAM_HU, "Adja meg a RAM meretet (64/128/256/512/1024 kBajt)"},
/* it */ {IDCLS_SPECIFY_SIZE_OF_RAM_IT, "Specifica la dimensione della RAM (4/128/256/512/1024 kByte)"},
/* ko */ {IDCLS_SPECIFY_SIZE_OF_RAM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SIZE_OF_RAM_NL, "Geef geheugengrootte (64/128/256/512/1024 kByte)"},
/* pl */ {IDCLS_SPECIFY_SIZE_OF_RAM_PL, "Okre��l rozmiar RAM-u (64/128/256/512/1024 kBajty)"},
/* ru */ {IDCLS_SPECIFY_SIZE_OF_RAM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SIZE_OF_RAM_SV, "Ange storlek pa RAM (64/128/256/512/1024 kByte)"},
/* tr */ {IDCLS_SPECIFY_SIZE_OF_RAM_TR, "RAM boyutunu belirt (64/128/256/512/1024 kByte)"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_ROM_1000_NAME,    N_("Specify name of cartridge ROM image for $1000")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_DA, "Angiv navn pa cartridge-ROM-image for $1000"},
/* de */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_DE, "Name fur ROM Module Image Datei ($1000)"},
/* fr */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_FR, "Specifier le nom de l�fimage de cartouche ROM pour $1000"},
/* hu */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_HU, "Adja meg a $1000 cimu cartridge ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_IT, "Specifica il nome immagine della cartuccia ROM a $1000"},
/* ko */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_NL, "Geef de naam van het cartridge ROM bestand voor $1000"},
/* pl */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_PL, "Okre��l nazwe obrazu ROM kartrid?a w $1000"},
/* ru */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_SV, "Ange namn pa insticksmodul-ROM-avbildning for $1000"},
/* tr */ {IDCLS_SPECIFY_CART_ROM_1000_NAME_TR, "$1000 adresi icin kartut ROM imaj ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_ROM_2000_NAME,    N_("Specify name of cartridge ROM image for $2000-$3fff")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_DA, "Angiv navn pa cartridge-ROM-image for $2000-3fff"},
/* de */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_DE, "Name fur ROM Module Image Datei ($2000-3fff)"},
/* fr */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_FR, "Specifier le nom de l�fimage de cartouche ROM pour $2000-$3fff"},
/* hu */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_HU, "Adja meg a $2000-$3fff cimu cartridge ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_IT, "Specifica il nome immagine della ROM della cartuccia per $2000-$3fff"},
/* ko */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_NL, "Geef de naam van het cartridge ROM bestand voor $2000-$3fff"},
/* pl */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_PL, "Okre��l nazwe obrazu ROM kartrid?a w $2000-$3fff"},
/* ru */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_SV, "Ange namn pa insticksmodul-ROM-avbildning for $2000-3fff"},
/* tr */ {IDCLS_SPECIFY_CART_ROM_2000_NAME_TR, "$2000-$3fff adres aralydy icin kartut ROM imaj ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_ROM_4000_NAME,    N_("Specify name of cartridge ROM image for $4000-$5fff")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_DA, "Angiv navn pa cartridge-ROM-image for $4000-$5fff"},
/* de */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_DE, "Name fur ROM Module Image Datei ($4000-5fff)"},
/* fr */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_FR, "Specifier le nom de l�fimage de cartouche ROM pour $4000-$5fff"},
/* hu */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_HU, "Adja meg a $4000-$5fff cimu cartridge ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_IT, "Specifica il nome immagine della ROM della cartuccia per $4000-$5fff"},
/* ko */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_NL, "Geef de naam van het cartridge ROM bestand voor $4000-$5fff"},
/* pl */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_PL, "Okre��l nazwe obrazu ROM kartrid?a w $4000-$5fff"},
/* ru */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_SV, "Ange namn pa insticksmodul-ROM-avbildning for $4000-$5fff"},
/* tr */ {IDCLS_SPECIFY_CART_ROM_4000_NAME_TR, "$4000-$5fff adres aralydy icin kartut ROM imaj ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_ROM_6000_NAME,    N_("Specify name of cartridge ROM image for $6000-$7fff")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_DA, "Angiv navn pa cartridge-ROM-image for $6000-$7fff"},
/* de */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_DE, "Name fur ROM Module Image Datei ($6000-7fff)"},
/* fr */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_FR, "Specifier le nom de l�fimage de cartouche ROM pour $6000-$7fff"},
/* hu */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_HU, "Adja meg a $6000-$7fff cimu cartridge ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_IT, "Specifica il nome immagine della ROM della cartuccia per $6000-$7fff"},
/* ko */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_NL, "Geef de naam van het cartridge ROM bestand voor $6000-$7fff"},
/* pl */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_PL, "Okre��l nazwe obrazu ROM kartrid?a w $6000-$7fff"},
/* ru */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_SV, "Ange namn pa insticksmodul-ROM-avbildning for $6000-$7fff"},
/* tr */ {IDCLS_SPECIFY_CART_ROM_6000_NAME_TR, "$6000-$7fff adres aralydy icin kartut ROM imaj ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800,    N_("Enable RAM mapping in $0800-$0FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_DA, "Aktiver RAM-mappning pa $0800-$0FFF"},
/* de */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_DE, "RAM Zuordnung in $0800-$0FFF aktivieren"},
/* fr */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_FR, "Activer le mappage RAM dans $0800-$0FFF"},
/* hu */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_HU, "$0800-$0FFF RAM lekepzes engedelyezese"},
/* it */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_IT, "Attiva mappatura della RAM a $0800-$0FFF"},
/* ko */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_NL, "Activeer RAM op adres $0800-$0FFF"},
/* pl */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_PL, "W3�}cz mapowanie RAM w $0800-$0FFF"},
/* ru */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_SV, "Aktivera RAM-mappning pa $0800-$0FFF"},
/* tr */ {IDCLS_ENABLE_RAM_MAPPING_IN_0800_TR, "$0800-$0FFF aralydynda RAM etlettirmeyi aktif et"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800,    N_("Disable RAM mapping in $0800-$0FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_DA, "Deaktiver RAM-mappning pa $0800-$0FFF"},
/* de */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_DE, "RAM Zuordnung in $0800-$0FFF deaktivieren"},
/* fr */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_FR, "Desactiver le mappage RAM dans $0800-$0FFF"},
/* hu */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_HU, "$0800-$0FFF RAM lekepzes tiltasa"},
/* it */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_IT, "Disattiva mappatura della RAM a $0800-$0FFF"},
/* ko */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_NL, "RAM op adres $0800-$0FFF uitschakelen"},
/* pl */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_PL, "Wy3�}cz mapowanie RAM w $0800-$0FFF"},
/* ru */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_SV, "Inaktivera RAM-mappning pa $0800-$0FFF"},
/* tr */ {IDCLS_DISABLE_RAM_MAPPING_IN_0800_TR, "$0800-$0FFF aralydynda RAM etlettirmeyi pasiflettir"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000,    N_("Enable RAM mapping in $1000-$1FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_DA, "Aktiver RAM-mappning pa $1000-$1FFF"},
/* de */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_DE, "RAM Zuordnung in $1000-$1FFF aktivieren"},
/* fr */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_FR, "Activer le mappage RAM dans $1000-$1FFF"},
/* hu */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_HU, "$1000-$1FFF RAM lekepzes engedelyezese"},
/* it */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_IT, "Attiva mappatura della RAM a $1000-$1FFF"},
/* ko */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_NL, "Activeer RAM op adres $1000-$1FFF"},
/* pl */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_PL, "W3�}cz mapowanie RAM w $1000-$1FFF"},
/* ru */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_SV, "Aktivera RAM-mappning pa $1000-$1FFF"},
/* tr */ {IDCLS_ENABLE_RAM_MAPPING_IN_1000_TR, "$1000-$1FFF aralydynda RAM etlettirmeyi aktif et"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000,    N_("Disable RAM mapping in $1000-$1FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_DA, "Deaktiver RAM-mappning pa $1000-$1FFF"},
/* de */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_DE, "RAM Zuordnung in $1000-$1FFF deaktivieren"},
/* fr */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_FR, "Desactiver le mappage RAM dans $1000-$1FFF"},
/* hu */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_HU, "$1000-$1FFF RAM lekepzes tiltasa"},
/* it */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_IT, "Disattiva mappatura della RAM a $1000-$1FFF"},
/* ko */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_NL, "RAM op adres $1000-$1FFF uitschakelen"},
/* pl */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_PL, "Wy3�}cz mapowanie RAM w $1000-$1FFF"},
/* ru */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_SV, "Inaktivera RAM-mappning pa $1000-$1FFF"},
/* tr */ {IDCLS_DISABLE_RAM_MAPPING_IN_1000_TR, "$1000-$1FFF aralydynda RAM etlettirmeyi pasiflettir"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000,    N_("Enable RAM mapping in $2000-$3FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_DA, "Aktiver RAM-mappning pa $2000-$3FFF"},
/* de */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_DE, "RAM Zuordnung in $2000-3FFF aktivieren"},
/* fr */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_FR, "Activer le mappage RAM dans $2000-$3FFF"},
/* hu */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_HU, "$2000-$3FFF RAM lekepzes engedelyezese"},
/* it */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_IT, "Attiva mappatura della RAM a $2000-$3FFF"},
/* ko */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_NL, "Activeer RAM op adres $2000-$3FFF"},
/* pl */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_PL, "W3�}cz mapowanie RAM w $2000-$3FFF"},
/* ru */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_SV, "Aktivera RAM-mappning pa $2000-$3FFF"},
/* tr */ {IDCLS_ENABLE_RAM_MAPPING_IN_2000_TR, "$2000-$3FFF aralydynda RAM etlettirmeyi aktif et"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000,    N_("Disable RAM mapping in $2000-$3FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_DA, "Deaktiver RAM-mappning pa $2000-$3FFF"},
/* de */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_DE, "RAM Zuordnung in $2000-$3FFF deaktivieren"},
/* fr */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_FR, "Desactiver le mappage RAM dans $2000-$3FFF"},
/* hu */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_HU, "$2000-$3FFF RAM lekepzes tiltasa"},
/* it */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_IT, "Disattiva mappatura della RAM a $2000-$3FFF"},
/* ko */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_NL, "RAM op adres $2000-$3FFF uitschakelen"},
/* pl */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_PL, "Wy3�}cz mapowanie RAM w $2000-$3FFF"},
/* ru */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_SV, "Inaktivera RAM-mappning pa $2000-$3FFF"},
/* tr */ {IDCLS_DISABLE_RAM_MAPPING_IN_2000_TR, "$2000-$3FFF aralydynda RAM etlettirmeyi pasiflettir"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000,    N_("Enable RAM mapping in $4000-$5FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_DA, "Aktiver RAM-mappning pa $4000-$5FFF"},
/* de */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_DE, "RAM Zuordnung in $4000-$5FFF aktivieren"},
/* fr */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_FR, "Activer le mappage RAM dans $4000-$5FFF"},
/* hu */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_HU, "$4000-$5FFF RAM lekepzes engedelyezese"},
/* it */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_IT, "Attiva mappatura della RAM a $4000-$5FFF"},
/* ko */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_NL, "Activeer RAM op adres $4000-$5FFF"},
/* pl */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_PL, "W3�}cz mapowanie RAM w $4000-$5FFF"},
/* ru */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_SV, "Aktivera RAM-mappning pa $4000-$5FFF"},
/* tr */ {IDCLS_ENABLE_RAM_MAPPING_IN_4000_TR, "$4000-$5FFF aralydynda RAM etlettirmeyi aktif et"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000,    N_("Disable RAM mapping in $4000-$5FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_DA, "Deaktiver RAM-mappning pa $4000-$5FFF"},
/* de */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_DE, "RAM Zuordnung in $4000-$5FFF deaktivieren"},
/* fr */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_FR, "Desactiver le mappage RAM dans $4000-$5FFF"},
/* hu */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_HU, "$4000-$5FFF RAM lekepzes tiltasa"},
/* it */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_IT, "Disattiva mappatura della RAM a $4000-$5FFF"},
/* ko */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_NL, "RAM op adres $4000-$5FFF uitchakelen"},
/* pl */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_PL, "Wy3�}cz mapowanie RAM w $4000-$5FFF"},
/* ru */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_SV, "Inaktivera RAM-mappning pa $4000-$5FFF"},
/* tr */ {IDCLS_DISABLE_RAM_MAPPING_IN_4000_TR, "$4000-$5FFF aralydynda RAM etlettirmeyi pasiflettir"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000,    N_("Enable RAM mapping in $6000-$7FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_DA, "Aktiver RAM-mappning pa $6000-$7FFF"},
/* de */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_DE, "RAM Zuordnung in $6000-$7FFF aktivieren"},
/* fr */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_FR, "Activer le mappage RAM dans $6000-$7FFF"},
/* hu */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_HU, "$6000-$7FFF RAM lekepzes engedelyezese"},
/* it */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_IT, "Attiva mappatura della RAM a $6000-$7FFF"},
/* ko */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_NL, "Activeer RAM op adres $6000-$7FFF"},
/* pl */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_PL, "W3�}cz mapowanie RAM w $6000-$7FFF"},
/* ru */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_SV, "Aktivera RAM-mappning pa $6000-$7FFF"},
/* tr */ {IDCLS_ENABLE_RAM_MAPPING_IN_6000_TR, "$6000-$7FFF aralydynda RAM etlettirmeyi aktif et"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000,    N_("Disable RAM mapping in $6000-$7FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_DA, "Deaktiver RAM-mappning pa $6000-$7FFF"},
/* de */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_DE, "RAM Zuordnung in $6000-$7FFF deaktivieren"},
/* fr */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_FR, "Desactiver le mappage RAM dans $6000-$7FFF"},
/* hu */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_HU, "$6000-$7FFF RAM lekepzes tiltasa"},
/* it */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_IT, "Disattiva mappatura della RAM a $6000-$7FFF"},
/* ko */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_NL, "RAM op adres $6000-$7FFF uitschakelen"},
/* pl */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_PL, "Wy3�}cz mapowanie RAM w $6000-$7FFF"},
/* ru */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_SV, "Inaktivera RAM-mappning pa $6000-$7FFF"},
/* tr */ {IDCLS_DISABLE_RAM_MAPPING_IN_6000_TR, "$6000-$7FFF aralydynda RAM etlettirmeyi pasiflettir"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000,    N_("Enable RAM mapping in $C000-$CFFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_DA, "Aktiver RAM-mappning pa $C000-$CFFF"},
/* de */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_DE, "RAM Zuordnung in $C000-$CFFF aktivieren"},
/* fr */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_FR, "Activer le mappage RAM dans $C000-$CFFF"},
/* hu */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_HU, "$C000-$CFFF RAM lekepzes engedelyezese"},
/* it */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_IT, "Attiva mappatura della RAM a $C000-$CFFF"},
/* ko */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_NL, "Activeer RAM op adres $C000-$CFFF"},
/* pl */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_PL, "W3�}cz mapowanie RAM w $C000-$CFFF"},
/* ru */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_SV, "Aktivera RAM-mappning pa $C000-$CFFF"},
/* tr */ {IDCLS_ENABLE_RAM_MAPPING_IN_C000_TR, "$C000-$CFFF aralydynda RAM etlettirmeyi aktif et"},
#endif

/* cbm2/cbm2-cmdline-options.c */
/* en */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000,    N_("Disable RAM mapping in $C000-$CFFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_DA, "Deaktiver RAM-mappning pa $C000-$CFFF"},
/* de */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_DE, "RAM Zuordnung in $C000-$CFFF deaktivieren"},
/* fr */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_FR, "Desactiver le mappage RAM dans $C000-$CFFF"},
/* hu */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_HU, "$C000-$CFFF RAM lekepzes tiltasa"},
/* it */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_IT, "Disattiva mappatura della RAM a $C000-$CFFF"},
/* ko */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_NL, "RAM op adres $C000-$CFFF uitschakelen"},
/* pl */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_PL, "Wy3�}cz mapowanie RAM w $C000-$CFFF"},
/* ru */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_SV, "Inaktivera RAM-mappning pa $C000-$CFFF"},
/* tr */ {IDCLS_DISABLE_RAM_MAPPING_IN_C000_TR, "$C000-$CFFF aralydynda RAM etlettirmeyi pasiflettir"},
#endif

#ifdef COMMON_KBD
/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_KEYMAP_INDEX,    N_("Specify index of keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_KEYMAP_INDEX_DA, "Angiv indeks for tastaturindstillingsfil"},
/* de */ {IDCLS_SPECIFY_KEYMAP_INDEX_DE, "Index der Keymap Datei definieren"},
/* fr */ {IDCLS_SPECIFY_KEYMAP_INDEX_FR, "Specifier l'index du fichier de mappage clavier"},
/* hu */ {IDCLS_SPECIFY_KEYMAP_INDEX_HU, "Adja meg a billentyuzet lekepzes fajl tipusat"},
/* it */ {IDCLS_SPECIFY_KEYMAP_INDEX_IT, "Specifica l'indice del file della mappa della tastiera"},
/* ko */ {IDCLS_SPECIFY_KEYMAP_INDEX_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_KEYMAP_INDEX_NL, "Geef de index van het keymapbestand"},
/* pl */ {IDCLS_SPECIFY_KEYMAP_INDEX_PL, "Okre��l indeks pliku uk3adu klawiatury"},
/* ru */ {IDCLS_SPECIFY_KEYMAP_INDEX_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_KEYMAP_INDEX_SV, "Ange index o tangentbordsfil"},
/* tr */ {IDCLS_SPECIFY_KEYMAP_INDEX_TR, "Tut haritasy dosyasynyn indeksini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME,    N_("Specify name of graphics keyboard symbolic keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_DA, "Angiv fil for symbolsk tastaturemulering for \"graphics\"-tastatur"},
/* de */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_DE, "Keymap Datei fur graphics keyboard symbolic definieren"},
/* fr */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_FR, "Specifier le nom du fichier de mappage clavier symbolique"},
/* hu */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_HU, "Adja meg a grafikus es szimbolikus billentyuzet lekepzesi fajl nevet."},
/* it */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_IT, "Specifica il nome del file della mappa simbolica della tastiera grafica"},
/* ko */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_NL, "Geef de naam van het symbolisch keymapbestand voor het grafische toetsenbord"},
/* pl */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_PL, "Okre��l nazwe pliku symbolicznego uk3adu klawiatury graficznej"},
/* ru */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_SV, "Ange fil for symbolisk tangentbordsemulering for \"graphics\"-tangentbord"},
/* tr */ {IDCLS_SPECIFY_GFX_SYM_KEYMAP_NAME_TR, "Grafik klavyesi sembolik tut haritasy dosyasynyn ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME,    N_("Specify name of graphics keyboard positional keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_DA, "Angiv fil for positionsbestemt tastaturemulering for \"graphics\"-tastatur"},
/* de */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_DE, "Keymap Datei fur graphics keyboard positional definieren"},
/* fr */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_FR, "Specifier le nom du fichier de mappage clavier positionnel"},
/* hu */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_HU, "Adja meg a grafikus es pozicio szerinti billentyuzet lekepzesi fajl nevet."},
/* it */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_IT, "Specifica il nome del file della mappa posizionale della tastiera grafica"},
/* ko */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_NL, "Geef de naam van het positioneel keymapbestand voor het grafische toetsenbord"},
/* pl */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_PL, "Okre��l nazwe pliku pozycyjnego uk3adu klawiatury graficznej"},
/* ru */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_SV, "Ange fil for positionsriktig tangentbordsemulering for \"graphics\"-tangentbord"},
/* tr */ {IDCLS_SPECIFY_GFX_POS_KEYMAP_NAME_TR, "Grafik klavyesi konumsal tut haritasy dosyasynyn ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME,    N_("Specify name of UK business keyboard symbolic keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_DA, "Angiv fil for symbolsk tastaturemulering for Britisk \"business\"-tastatur"},
/* de */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_DE, "Keymap Datei fur UK business keyboard symbolic definieren"},
/* fr */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_FR, "Specifier le nom du fichier de mappage clavier symbolique UK"},
/* hu */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_HU, "Adja meg az angol, hivatalos, szimbolikus billentyuzet lekepzesi fajl nevet."},
/* it */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_IT, "Specifica il nome del file della mappa simbolica della tastiera UK business"},
/* ko */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_NL, "Geef de naam van het symbolisch keymapbestand voor het UK zakelijk toetsenbord"},
/* pl */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_PL, "Okre��l nazwe pliku symbolicznego uk3adu angielskiej klawiatury biznesowej"},
/* ru */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_SV, "Ange fil for symbolisk tangentbordsemulering for brittiskt \"business\"-tangentbord"},
/* tr */ {IDCLS_SPECIFY_BUK_SYM_KEYMAP_NAME_TR, "UK business klavyesi sembolik tut haritasy dosyasynyn ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME,    N_("Specify name of UK business keyboard positional keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_DA, "Angiv fil for positionsbestemt tastaturemulering for Britisk \"business\"-tastatur"},
/* de */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_DE, "Keymap Datei fur UK business keyboard positional definieren"},
/* fr */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_FR, "Specifier le nom du fichier de mappage clavier positionnel UK"},
/* hu */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_HU, "Adja meg az angol, hivatalos, pozicio szerinti billentyuzet lekepzesi fajl nevet."},
/* it */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_IT, "Specifica il nome del file della mappa posizionale della tastiera UK business"},
/* ko */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_NL, "Geef de naam van het positioneel keymapbestand voor het UK zakelijk toetsenbord"},
/* pl */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_PL, "Okre��l nazwe pliku pozycyjnego uk3adu angielskiej klawiatury biznesowej"},
/* ru */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_SV, "Ange fil for positionsriktig tangentbordsemulering for brittiskt \"business\"-tangentbord"},
/* tr */ {IDCLS_SPECIFY_BUK_POS_KEYMAP_NAME_TR, "UK business klavyesi konumsal tut haritasy dosyasynyn ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME,    N_("Specify name of German business keyboard symbolic keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_DA, "Angiv fil for symbolsk tastaturemulering for Tysk \"business\"-tastatur"},
/* de */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_DE, "Keymap Datei fur German business keyboard symbolic definieren"},
/* fr */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_FR, "Specifier le nom du fichier de mappage clavier symbolique allemand"},
/* hu */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_HU, "Adja meg a nemet, hivatalos, szimbolikus billentyuzet lekepzesi fajl nevet."},
/* it */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_IT, "Specifica il nome del file della mappa simbolica della tastiera business tedesca"},
/* ko */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_NL, "Geef de naam van het symbolisch keymapbestand voor het Duitse zakelijk toetsenbord"},
/* pl */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_PL, "Okre��l nazwe pliku symbolicznego uk3adu niemieckiej klawiatury biznesowej"},
/* ru */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_SV, "Ange fil for symbolisk tangentbordsemulering for tyskt \"business\"-tangentbord"},
/* tr */ {IDCLS_SPECIFY_BDE_SYM_KEYMAP_NAME_TR, "Alman business klavyesi sembolik tut haritasy dosyasynyn ismini belirt"},
#endif

/* cbm2/cbm2-cmdline-options.c, pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME,    N_("Specify name of German business keyboard positional keymap file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_DA, "Angiv fil for positionsbestemt tastaturemulering for Tysk \"business\"-tastatur"},
/* de */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_DE, "Keymap Datei fur German business keyboard positional definieren"},
/* fr */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_FR, "Specifier le nom du fichier de mappage clavier positionnel allemand"},
/* hu */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_HU, "Adja meg a nemet, hivatalos, pozicio szerinti billentyuzet lekepzesi fajl nevet."},
/* it */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_IT, "Specifica il nome del file della mappa posizionale della tastiera business tedesca"},
/* ko */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_NL, "Geef de naam van het positioneel keymapbestand voor het Duitse zakelijk toetsenbord"},
/* pl */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_PL, "Okre��l nazwe pliku pozycyjnego uk3adu niemieckiej klawiatury biznesowej"},
/* ru */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_SV, "Ange fil for positionsriktig tangentbordsemulering for tyskt \"business\"-tangentbord"},
/* tr */ {IDCLS_SPECIFY_BDE_POS_KEYMAP_NAME_TR, "Alman business klavyesi konumsal tut haritasy dosyasynyn ismini belirt"},
#endif
#endif

/* drive/drive-cmdline-options.c */
/* en */ {IDCLS_ENABLE_TRUE_DRIVE,    N_("Enable hardware-level emulation of disk drives")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_TRUE_DRIVE_DA, "Aktiver emulering af diskettedrev pa hardware-niveau"},
/* de */ {IDCLS_ENABLE_TRUE_DRIVE_DE, "Hardware Emulation fur Disklaufwerke aktivieren"},
/* fr */ {IDCLS_ENABLE_TRUE_DRIVE_FR, "Activer l'emulation de disques au niveau physique"},
/* hu */ {IDCLS_ENABLE_TRUE_DRIVE_HU, "Lemezegysegek hardver szintu emulaciojanak engedelyezese"},
/* it */ {IDCLS_ENABLE_TRUE_DRIVE_IT, "Attiva emulazione hardware dei disk drive"},
/* ko */ {IDCLS_ENABLE_TRUE_DRIVE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_TRUE_DRIVE_NL, "Activeer hardwarematige emulatie van diskdrives"},
/* pl */ {IDCLS_ENABLE_TRUE_DRIVE_PL, "W3�}cz sprzetow�} emulacje stacji dyskow"},
/* ru */ {IDCLS_ENABLE_TRUE_DRIVE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_TRUE_DRIVE_SV, "Aktivera emulering av diskettstationer pa maskinvaruniva"},
/* tr */ {IDCLS_ENABLE_TRUE_DRIVE_TR, "Disk suruculerinin donanym seviyesinde emulasyonunu aktif et"},
#endif

/* drive/drive-cmdline-options.c */
/* en */ {IDCLS_DISABLE_TRUE_DRIVE,    N_("Disable hardware-level emulation of disk drives")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_TRUE_DRIVE_DA, "Deaktiver emulering af diskettedrev pa hardware-niveau"},
/* de */ {IDCLS_DISABLE_TRUE_DRIVE_DE, "Hardware Emulation fur Disklaufwerke deaktivieren"},
/* fr */ {IDCLS_DISABLE_TRUE_DRIVE_FR, "Desactiver l'emulation de disques au niveau physique"},
/* hu */ {IDCLS_DISABLE_TRUE_DRIVE_HU, "Lemezegysegek hardver szintu emulaciojanak tiltasa"},
/* it */ {IDCLS_DISABLE_TRUE_DRIVE_IT, "Disattiva emulazione hardware dei disk drive"},
/* ko */ {IDCLS_DISABLE_TRUE_DRIVE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_TRUE_DRIVE_NL, "Hardwarematige emulatie van diskdrives uitschakelen"},
/* pl */ {IDCLS_DISABLE_TRUE_DRIVE_PL, "Wy3�}cz sprzetow�} emulacje stacji dyskow"},
/* ru */ {IDCLS_DISABLE_TRUE_DRIVE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_TRUE_DRIVE_SV, "Inaktivera emulering av diskettstationer pa maskinvaruniva"},
/* tr */ {IDCLS_DISABLE_TRUE_DRIVE_TR, "Disk suruculerinin donanym seviyesinde emulasyonunu pasiflettir"},
#endif

/* drive/drive-cmdline-options.c, printerdrv/interface-serial.c,
   attach.c, drive/iec/iec-cmdline-options.c, c64/c64gluelogic.c */
/* en */ {IDCLS_P_TYPE,    N_("<Type>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_TYPE_DA, "<Type>"},
/* de */ {IDCLS_P_TYPE_DE, "<Typ>"},
/* fr */ {IDCLS_P_TYPE_FR, "<type>"},
/* hu */ {IDCLS_P_TYPE_HU, "<Tipus>"},
/* it */ {IDCLS_P_TYPE_IT, "<Tipo>"},
/* ko */ {IDCLS_P_TYPE_KO, "<A?�Eu>"},
/* nl */ {IDCLS_P_TYPE_NL, "<Soort>"},
/* pl */ {IDCLS_P_TYPE_PL, "<Typ>"},
/* ru */ {IDCLS_P_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_TYPE_SV, "<Typ>"},
/* tr */ {IDCLS_P_TYPE_TR, "<Tip>"},
#endif

/* drive/drive-cmdline-options.c */
/* en */ {IDCLS_SET_DRIVE_TYPE,    N_("Set drive type (0: no drive)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DRIVE_TYPE_DA, "Angiv enhedstype (0: ingen enhed)"},
/* de */ {IDCLS_SET_DRIVE_TYPE_DE, "Setze Laufwerkstyp (0: kein Laufwerk)"},
/* fr */ {IDCLS_SET_DRIVE_TYPE_FR, "Specifier le type de lecteur de disque (0: pas de lecteur)"},
/* hu */ {IDCLS_SET_DRIVE_TYPE_HU, "Adja meg a lemezegyseg tipusat (0: nincs)"},
/* it */ {IDCLS_SET_DRIVE_TYPE_IT, "Imposta tipo drive (0: nessun drive)"},
/* ko */ {IDCLS_SET_DRIVE_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DRIVE_TYPE_NL, "Zet drive soort (0: geen drive)"},
/* pl */ {IDCLS_SET_DRIVE_TYPE_PL, "Ustaw typ stacji (0: brak stacji)"},
/* ru */ {IDCLS_SET_DRIVE_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DRIVE_TYPE_SV, "Ange enhetstyp (0: ingen enhet)"},
/* tr */ {IDCLS_SET_DRIVE_TYPE_TR, "Surucu tipini ayarlayyn (0: surucu yok)"},
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
/* pl */ {IDCLS_P_METHOD_PL, "<method>"},
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
/* pl */ {IDCLS_P_COLOR_PL, "<color>"},
/* ru */ {IDCLS_P_COLOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_COLOR_SV, "<farg>"},
/* tr */ {IDCLS_P_COLOR_TR, "<renk>"},
#endif

/* gfxoutputdrv/doodledrv.c */
/* en */ {IDCLS_OVERSIZED_HANDLING,    N_("Select the way the oversized input should be handled, (0: scale down, 1: crop left top, 2: crop center top,  3: crop right top, 4: crop left center, 5: crop center, 6: crop right center, 7: crop left bottom, 8: crop center bottom, 9:  crop right bottom)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_OVERSIZED_HANDLING_DA, "Angiv handtering af for stort input (0: skaler ned, 1: klip venstre top, 2: klip midt top,  3: klip hojre top, 4: klip venstre midt, 5: klip centreret, 6: klip hojre midt, 7: klip venstre bund, 8: klip midt bund, 9: klip hojre bund)"},
/* de */ {IDCLS_OVERSIZED_HANDLING_DE, "Wahle, wie ubergroser Input behandelt werden soll, (0: skaliere, 1: schneide links oben, 2: schneide mitte oben,  3: schneide rechts oben, 4: schneide links mitte, 5: schneide mitte, 6: schneide rechts mitte, 7: schneide links unten, 8: schneide mitte unten, 9:  schneide rechts unten)"},
/* fr */ {IDCLS_OVERSIZED_HANDLING_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_OVERSIZED_HANDLING_HU, ""},  /* fuzzy */
/* it */ {IDCLS_OVERSIZED_HANDLING_IT, "Seleziona come gestire il sovradimensionamento dell'input, (0: scale down, 1: ritaglia sinistra alto, 2: ritaglia centro alto,  3: ritaglia destra alto, 4: ritaglia sinistra centro, 5: ritaglia centro, 6: ritaglia destra centro, 7: ritaglia sinistra basso, 8: ritaglia centro basso, 9:  ritaglia destra basso)"},
/* ko */ {IDCLS_OVERSIZED_HANDLING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_OVERSIZED_HANDLING_NL, "Selecteer de manier waarop de te grootte invoer moet worden afgehandeld, (0: maak kleiner, 1: crop linker bovenkant, 2: crop midden bovenkant, 3: crop rechter bovenkant, 4: crop linker midden, 5: crop midden, 6: crop rechter midden, 7: crop linker onderkant, 8: crop midden onderkant, 9: crop rechter onderkant)"},
/* pl */ {IDCLS_OVERSIZED_HANDLING_PL, "Wybierz sposob, w jaki ma bya obs3ugiwany za du?y obraz, (0: zmniejszenie, 1: ��ciecie z gory z lewej, 2: ��ciecie z gory, 3: ��ciecie z prawej z gory, 4: ��ciecie z lewej, 5: ��ciecie od ��rodka, 6: ��ciecie z prawej, 7: ��ciecie z lewej z do3u, 8: ��ciecie z do3u, 9: ��ciecie z prawej z do3u)"},
/* ru */ {IDCLS_OVERSIZED_HANDLING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_OVERSIZED_HANDLING_SV, "Valj hur for stor indata skall hanteras, (0: skala ned, 1: visa ovre vanstra, 2: visa ovre mitten, 3: visa ovre hogra, 4: visa vanstra mitten, 5: visa mitten, 6: visa hogra mitten, 7: visa nedre vanstra, 8: visa nedre mitten, 9: visa nedre hogre)"},
/* tr */ {IDCLS_OVERSIZED_HANDLING_TR, "Buyuk girdilerin ele alynma yontemini secin, (0: kucult, 1: sol ustten kyrp, 2: ortaly ustten kyrp,  3: sad ustten kyrp, 4: soldan ortaly kyrp, 5: ortadan kyrp, 6: saddan ortaly kyrp, 7: sol alttan kyrp, 8: ortaly alttan kyrp, 9:  sad alttan kyrp)"},
#endif

/* gfxoutputdrv/doodledrv.c */
/* en */ {IDCLS_MULTICOLOR_HANDLING,    N_("Select the way the multicolor to hires should be handled, (0: b&w, 1: 2 colors, 2: 4 colors, 3: gray scale,  4: best cell colors)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_MULTICOLOR_HANDLING_DA, "Angiv maden multicolor til hojoplosning skal handteres pa, (0: sort/hvid, 1: 2 farver, 2: 4 farver, 3: gratoner,  4: bedste cellefarver)"},
/* de */ {IDCLS_MULTICOLOR_HANDLING_DE, "Wahle, wie Mulitcolore zu Hochauflosung behandelte werden soll, (0: S&W, 1: 2 Farben, 2: 4 Farben, 4 Graustufen, 4: Beste Zellenfarben)"},
/* fr */ {IDCLS_MULTICOLOR_HANDLING_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_MULTICOLOR_HANDLING_HU, ""},  /* fuzzy */
/* it */ {IDCLS_MULTICOLOR_HANDLING_IT, "Seleziona come gestire il multicolor in hires, (0: b&w, 1: 2 colori, 2: 4 colori, 3: scala di grigi,  4: migliori colori cella)"},
/* ko */ {IDCLS_MULTICOLOR_HANDLING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_MULTICOLOR_HANDLING_NL, "Selecteer de manier waarop 'multicolor' naar 'hires' conversie moet worden afgehandeld, (0: zwart/wit, 1: 2 kleuren, 2: 4 kleuren, 3: grijs, 4: best mogelijke kleuren in de cel)"},
/* pl */ {IDCLS_MULTICOLOR_HANDLING_PL, "Wybiera sposob obs3ugi multikoloru do hires (0: czarno-bia3y, 1: 2 kolory, 2: 4 kolory, 3: skala szaro��ci, 4: najlepsze kolory komorek)"},
/* ru */ {IDCLS_MULTICOLOR_HANDLING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_MULTICOLOR_HANDLING_SV, "Valj hur flerfargs-till-hogupplost skall hanteras, (0: svartvit, 1: 2 farger, 2: fyra farger, 3: graskala, 4: basta cellfarger)"},
/* tr */ {IDCLS_MULTICOLOR_HANDLING_TR, "Cok renkliden yuksek cozunurlude gecitin ele alynma yontemini secin, (0: siyah&beyaz, 1: 2 renk, 2: 4 renk, 3: gri tonlu,  4: en iyi hucre renkleri)"},
#endif

/* gfxoutputdrv/doodledrv.c */
/* en */ {IDCLS_TED_LUM_HANDLING,    N_("Select the way the TED luminosity should be handled, (0: ignore, 1: dither)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TED_LUM_HANDLING_DA, "Angiv maden TED-lysstyrker skal handteres pa (0: ignorer, 1: blanding)"},
/* de */ {IDCLS_TED_LUM_HANDLING_DE, "Wahle, wie TED Leuchtstarke behandelt werden soll, (0: ignorieren, 1: dither)"},
/* fr */ {IDCLS_TED_LUM_HANDLING_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_TED_LUM_HANDLING_HU, ""},  /* fuzzy */
/* it */ {IDCLS_TED_LUM_HANDLING_IT, "Seleziona come gestire la luminosita TED, (0: ignora, 1: dither)"},
/* ko */ {IDCLS_TED_LUM_HANDLING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TED_LUM_HANDLING_NL, "Selecteer de manier waarop de TED kleuren moeten worden afgehandeld, (0: negeren, 1: dither)"},
/* pl */ {IDCLS_TED_LUM_HANDLING_PL, "Wybor sposobu obs3ugi jaskrawo��ci TED (0: ignoruj, 1: ditheruj)"},
/* ru */ {IDCLS_TED_LUM_HANDLING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TED_LUM_HANDLING_SV, "Valj hur TED-luminositet skall hanteras, (0: ignorera, 1: fargutjamna)"},
/* tr */ {IDCLS_TED_LUM_HANDLING_TR, "TED luminozitesinin ele alynma yontemini secin, (0: yok say, 1: dither)"},
#endif

/* gfxoutputdrv/doodledrv.c */
/* en */ {IDCLS_CRTC_TEXT_COLOR,    N_("Select the CRTC text color (0: white, 1: amber, 2: green)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_CRTC_TEXT_COLOR_DA, "Valg CRTC tekstfarve (0: hvid, 1: ravgul, 2: gron)"},
/* de */ {IDCLS_CRTC_TEXT_COLOR_DE, "Wahle CRTC Textfarbe (0: weis, 1: Amberbraun, 2: Grun)"},
/* fr */ {IDCLS_CRTC_TEXT_COLOR_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_CRTC_TEXT_COLOR_HU, ""},  /* fuzzy */
/* it */ {IDCLS_CRTC_TEXT_COLOR_IT, "Seleziona il colore del testo CRTC (0: bianco, 1: ambra, 2: verde)"},
/* ko */ {IDCLS_CRTC_TEXT_COLOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_CRTC_TEXT_COLOR_NL, "Selecteer de CRTC tekst kleur (0: wit, 1: amber, 2: groen)"},
/* pl */ {IDCLS_CRTC_TEXT_COLOR_PL, "Wybierz kolor tekstu CRTC (0: bia3y, 1: bursztynowy, 2: zielony)"},
/* ru */ {IDCLS_CRTC_TEXT_COLOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_CRTC_TEXT_COLOR_SV, "Valj CRTC-textfarg (0: vit, 1: gul, 2: gron)"},
/* tr */ {IDCLS_CRTC_TEXT_COLOR_TR, "CRTC yazy rengini secin (0: beyaz, 1: kehribar, 2: yetil)"},
#endif

/* drive/drive-cmdline-options.c */
/* en */ {IDCLS_SET_DRIVE_EXTENSION_POLICY,    N_("Set drive 40 track extension policy (0: never, 1: ask, 2: on access)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_DA, "Angiv drevets regel for 40-spors udviddelse (0: aldrig, 1: sporg, 2: ved tilgang)"},
/* de */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_DE, "40 Spur Erweiterungsmethode (0: nie, 1: Ruckfrage, 2: bei Bedarf)"},
/* fr */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_FR, "Specifier la regle d'extention 40 pistes (0: jamais, 1: demander, 2: a l'acces)"},
/* hu */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_HU, "Adja meg a 40 savra kiterjesztes terjesztes modjat (0: soha, 1: kerdes, 2: hozzafereskor)"},
/* it */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_IT, "Imposta la politica di estensione a 40 tracce del drive (0: mai, 1: a richiesta, 2: all'accesso)"},
/* ko */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_NL, "Stel beleid voor 40-sporenuitbreiding drive in (0: nooit, 1: vraag, 2: bij toegang)"},
/* pl */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_PL, "Okre��l zasade rozszerzania do 40 ��cie?ek (0: nigdy, 1: pytaj, 2: przy dostepie)"},
/* ru */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_SV, "Ange regel for 40-sparsutokning (0: aldrig, 1: fraga, 2: vid atkomst)"},
/* tr */ {IDCLS_SET_DRIVE_EXTENSION_POLICY_TR, "Surucu 40 track buyume kuralyny ayarla (0: asla, 1: sor, 2: eritildidinde)"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME,    N_("Specify name of 1541 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_DA, "Angiv navn pa 1541-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_DE, "Name der 1541 DOS ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_FR, "Specifier le nom de l'image 1541 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_HU, "Adja meg az 1541 DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1541"},
/* ko */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_NL, "Geef de naam van het 1541 DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 1541 DOS ROM"},
/* ru */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_SV, "Ange namn pa 1541-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1541_DOS_ROM_NAME_TR, "1541 DOS ROM imajynyn ismini belirt"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME,    N_("Specify name of 1541-II DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_DA, "Angivn navn pa 1541-II-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_DE, "Name der 1541-II DOS ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_FR, "Specifier le nom de l'image 1541-II DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_HU, "Adja meg az 1541-II DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1541-II"},
/* ko */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_NL, "Geef de naam van het 1541-II DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 1541-II DOS ROM"},
/* ru */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_SV, "Ange namn pa 1541-II-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1541_II_DOS_ROM_NAME_TR, "1541-II DOS ROM imajynyn ismini belirt"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME,    N_("Specify name of 1570 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_DA, "Angivn navn pa 1570-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_DE, "Name der 1570 DOS ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_FR, "Specifier le nom de l'image 1570 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_HU, "Adja meg az 1570 DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1570"},
/* ko */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_NL, "Geef de naam van het 1570 DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 1570 DOS ROM"},
/* ru */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_SV, "Ange namn pa 1570-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1570_DOS_ROM_NAME_TR, "1570 DOS ROM imajynyn ismini belirt"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME,    N_("Specify name of 1571 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_DA, "Angivn navn pa 1571-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_DE, "Name der 1571 DOS ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_FR, "Specifier le nom de l'image 1571 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_HU, "Adja meg az 1571 DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1571"},
/* ko */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_NL, "Geef de naam van het 1571 DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 1571 DOS ROM"},
/* ru */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_SV, "Ange namn pa 1571-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1571_DOS_ROM_NAME_TR, "1571 DOS ROM imajynyn ismini belirt"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME,    N_("Specify name of 1581 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_DA, "Angivn navn pa 1581-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_DE, "Name der 1581 DOS ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_FR, "Specifier le nom de l'image 1581 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_HU, "Adja meg az 1581 DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1581"},
/* ko */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_NL, "Geef de naam van het 1581 DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 1581 DOS ROM"},
/* ru */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_SV, "Ange namn pa 1581-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1581_DOS_ROM_NAME_TR, "1581 DOS ROM imajynyn ismini belirt"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_2000_DOS_ROM_NAME,    N_("Specify name of 2000 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_2000_DOS_ROM_NAME_DA, "Angivn navn pa 2000-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_2000_DOS_ROM_NAME_DE, "Name der 2000 DOS ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_2000_DOS_ROM_NAME_FR, "Specifier le nom de l'image 2000 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_2000_DOS_ROM_NAME_HU, "Adja meg az 2000 DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_2000_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 2000"},
/* ko */ {IDCLS_SPECIFY_2000_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_2000_DOS_ROM_NAME_NL, "Geef de naam van het 2000 DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_2000_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 2000 DOS ROM"},
/* ru */ {IDCLS_SPECIFY_2000_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_2000_DOS_ROM_NAME_SV, "Ange namn pa 2000-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_2000_DOS_ROM_NAME_TR, "2000 DOS ROM imajynyn ismini belirt"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_4000_DOS_ROM_NAME,    N_("Specify name of 4000 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_4000_DOS_ROM_NAME_DA, "Angivn navn pa 4000-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_4000_DOS_ROM_NAME_DE, "Name der 4000 DOS ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_4000_DOS_ROM_NAME_FR, "Specifier le nom de l'image 4000 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_4000_DOS_ROM_NAME_HU, "Adja meg az 4000 DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_4000_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 4000"},
/* ko */ {IDCLS_SPECIFY_4000_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_4000_DOS_ROM_NAME_NL, "Geef de naam van het 4000 DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_4000_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 4000 DOS ROM"},
/* ru */ {IDCLS_SPECIFY_4000_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_4000_DOS_ROM_NAME_SV, "Ange namn pa 4000-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_4000_DOS_ROM_NAME_TR, "4000 DOS ROM imajynyn ismini belirt"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_SET_IDLE_METHOD,    N_("Set drive idling method (0: no traps, 1: skip cycles, 2: trap idle)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_IDLE_METHOD_DA, "Valg pausemetode for diskettedrev (0: ingen traps, 1: spring over cykler, 2: trap ledig)"},
/* de */ {IDCLS_SET_IDLE_METHOD_DE, "Laufwerks idling Methode (0: kein Traps, 1: Zyklen verwerfen, 2: trap idle)"},
/* fr */ {IDCLS_SET_IDLE_METHOD_FR, "Specifier la methode d'idle (0: pas de traps, 1: sauter des cycles, 2: trap idle)"},
/* hu */ {IDCLS_SET_IDLE_METHOD_HU, "Lemezegyseg uresjarasi modja (0: folytonos emulacio, 1: ciklusok kihagyasa, 2: ures DOS ciklusok kihagyasa)"},
/* it */ {IDCLS_SET_IDLE_METHOD_IT, "Imposta il metodo per rilevare l'inattivita del drive (0: non rilevare, 1: salta cicli, 2: rileva inattivita)"},
/* ko */ {IDCLS_SET_IDLE_METHOD_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_IDLE_METHOD_NL, "Stel de drive idlemethode in (0: geen traps, 1: sla cycli over, 2: trap idle)"},
/* pl */ {IDCLS_SET_IDLE_METHOD_PL, "Okre��l metode bezczynno��ci napedu (0: no traps, 1: opuszczaj cykle, 2: trap idle)"},
/* ru */ {IDCLS_SET_IDLE_METHOD_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_IDLE_METHOD_SV, "Stall in vantemetod for diskettstation (0: fanta inge, 1: hoppa cykler, 2: fanga vantan)"},
/* tr */ {IDCLS_SET_IDLE_METHOD_TR, "Surucu bota vakit gecirme metodunu ayarlayyn (0: trap yok, 1: cyclelary atla, 2: trap bota vakit gecirme)"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DRIVE_RAM_2000,    N_("Enable 8KB RAM expansion at $2000-$3FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DRIVE_RAM_2000_DA, "Aktiver 8KB RAM-udviddelse pa $2000-$3FFF"},
/* de */ {IDCLS_ENABLE_DRIVE_RAM_2000_DE, "8KB RAM Erweiterung bei $2000-3fff aktivieren"},
/* fr */ {IDCLS_ENABLE_DRIVE_RAM_2000_FR, "Activer l'exansion de 8KB RAM a $2000-$3FFF"},
/* hu */ {IDCLS_ENABLE_DRIVE_RAM_2000_HU, "8KB RAM kiterjeszes engedelyezese a $2000-$3FFF cimen"},
/* it */ {IDCLS_ENABLE_DRIVE_RAM_2000_IT, "Attiva l'espansione di RAM di 8KB a $2000-$3FFF"},
/* ko */ {IDCLS_ENABLE_DRIVE_RAM_2000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DRIVE_RAM_2000_NL, "Activeer 8KB RAM uitbreiding op adres $2000-$3FFF"},
/* pl */ {IDCLS_ENABLE_DRIVE_RAM_2000_PL, "W3�}cz rozszerzenie 8KB RAM w $2000-$3FFF"},
/* ru */ {IDCLS_ENABLE_DRIVE_RAM_2000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DRIVE_RAM_2000_SV, "Aktivera 8KB RAM-expansion pa $2000-$3FFF"},
/* tr */ {IDCLS_ENABLE_DRIVE_RAM_2000_TR, "$2000-$3FFF arasynda 8KB RAM genitletmeyi aktif et"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DRIVE_RAM_2000,    N_("Disable 8KB RAM expansion at $2000-$3FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DRIVE_RAM_2000_DA, "Deaktiver 8KB RAM-udviddelse pa $2000-$3FFF"},
/* de */ {IDCLS_DISABLE_DRIVE_RAM_2000_DE, "8KB RAM Erweiterung bei $2000-3fff deaktivieren"},
/* fr */ {IDCLS_DISABLE_DRIVE_RAM_2000_FR, "Desactiver l'exansion de 8KB RAM a $2000-$3FFF"},
/* hu */ {IDCLS_DISABLE_DRIVE_RAM_2000_HU, "8KB RAM kiterjeszes tiltasa a $2000-$3FFF cimen"},
/* it */ {IDCLS_DISABLE_DRIVE_RAM_2000_IT, "Disattiva l'espansione di RAM di 8KB a $2000-$3FFF"},
/* ko */ {IDCLS_DISABLE_DRIVE_RAM_2000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DRIVE_RAM_2000_NL, "8KB RAM uitbreiding op adres $2000-$3FFF uitschakelen"},
/* pl */ {IDCLS_DISABLE_DRIVE_RAM_2000_PL, "Wy3�}cz rozszerzenie 8KB RAM w $2000-$3FFF"},
/* ru */ {IDCLS_DISABLE_DRIVE_RAM_2000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DRIVE_RAM_2000_SV, "Inaktivera 8KB RAM-expansion pa $2000-$3FFF"},
/* tr */ {IDCLS_DISABLE_DRIVE_RAM_2000_TR, "$2000-$3FFF arasynda 8KB RAM genitletmeyi pasiflettir"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DRIVE_RAM_4000,    N_("Enable 8KB RAM expansion at $4000-$5FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DRIVE_RAM_4000_DA, "Aktiver 8KB RAM-udviddelse pa $4000-$5FFF"},
/* de */ {IDCLS_ENABLE_DRIVE_RAM_4000_DE, "8KB RAM Erweiterung bei $4000-5fff aktivieren"},
/* fr */ {IDCLS_ENABLE_DRIVE_RAM_4000_FR, "Activer l'exansion de 8KB RAM a $4000-$5FFF"},
/* hu */ {IDCLS_ENABLE_DRIVE_RAM_4000_HU, "8KB RAM kiterjeszes engedelyezese a $4000-$5FFF cimen"},
/* it */ {IDCLS_ENABLE_DRIVE_RAM_4000_IT, "Attiva l'espansione di RAM di 8KB a $4000-$5FFF"},
/* ko */ {IDCLS_ENABLE_DRIVE_RAM_4000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DRIVE_RAM_4000_NL, "Activeer 8KB RAM uitbreiding op adres $4000-$5FFF"},
/* pl */ {IDCLS_ENABLE_DRIVE_RAM_4000_PL, "W3�}cz rozszerzenie 8KB RAM w $4000-$5FFF"},
/* ru */ {IDCLS_ENABLE_DRIVE_RAM_4000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DRIVE_RAM_4000_SV, "Aktivera 8KB RAM-expansion pa $4000-$5FFF"},
/* tr */ {IDCLS_ENABLE_DRIVE_RAM_4000_TR, "$4000-$5FFF arasynda 8KB RAM genitletmeyi aktif et"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DRIVE_RAM_4000,    N_("Disable 8KB RAM expansion at $4000-$5FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DRIVE_RAM_4000_DA, "Deaktiver 8KB RAM-udviddelse pa $4000-$5FFF"},
/* de */ {IDCLS_DISABLE_DRIVE_RAM_4000_DE, "8KB RAM Erweiterung bei $4000-5fff deaktivieren"},
/* fr */ {IDCLS_DISABLE_DRIVE_RAM_4000_FR, "Desactiver l'exansion de 8KB RAM a $4000-$5FFF"},
/* hu */ {IDCLS_DISABLE_DRIVE_RAM_4000_HU, "8KB RAM kiterjeszes tiltasa a $4000-$5FFF cimen"},
/* it */ {IDCLS_DISABLE_DRIVE_RAM_4000_IT, "Disattiva l'espansione di RAM di 8KB a $4000-$5FFF"},
/* ko */ {IDCLS_DISABLE_DRIVE_RAM_4000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DRIVE_RAM_4000_NL, "8KB RAM uitbreiding op adres $4000-$5FFF uitschakelen"},
/* pl */ {IDCLS_DISABLE_DRIVE_RAM_4000_PL, "Wy3�}cz rozszerzenie 8KB RAM w $4000-$5FFF"},
/* ru */ {IDCLS_DISABLE_DRIVE_RAM_4000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DRIVE_RAM_4000_SV, "Inaktivera 8KB RAM-expansion pa $4000-$5FFF"},
/* tr */ {IDCLS_DISABLE_DRIVE_RAM_4000_TR, "$4000-$5FFF arasynda 8KB RAM genitletmeyi pasiflettir"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DRIVE_RAM_6000,    N_("Enable 8KB RAM expansion at $6000-$7FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DRIVE_RAM_6000_DA, "Aktiver 8KB RAM-udviddelse pa $6000-$7FFF"},
/* de */ {IDCLS_ENABLE_DRIVE_RAM_6000_DE, "8KB RAM Erweiterung bei $6000-7fff aktivieren"},
/* fr */ {IDCLS_ENABLE_DRIVE_RAM_6000_FR, "Activer l'exansion de 8KB RAM a $6000-$7FFF"},
/* hu */ {IDCLS_ENABLE_DRIVE_RAM_6000_HU, "8KB RAM kiterjeszes engedelyezese a $6000-$7FFF cimen"},
/* it */ {IDCLS_ENABLE_DRIVE_RAM_6000_IT, "Attiva l'espansione di RAM di 8KB a $6000-$7FFF"},
/* ko */ {IDCLS_ENABLE_DRIVE_RAM_6000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DRIVE_RAM_6000_NL, "Activeer 8KB RAM uitbreiding op adres $6000-$7FFF"},
/* pl */ {IDCLS_ENABLE_DRIVE_RAM_6000_PL, "W3�}cz rozszerzenie 8KB RAM w $6000-$7FFF"},
/* ru */ {IDCLS_ENABLE_DRIVE_RAM_6000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DRIVE_RAM_6000_SV, "Aktivera 8KB RAM-expansion pa $6000-$7FFF"},
/* tr */ {IDCLS_ENABLE_DRIVE_RAM_6000_TR, "$6000-$7FFF arasynda 8KB RAM genitletmeyi aktif et"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DRIVE_RAM_6000,    N_("Disable 8KB RAM expansion at $6000-$7FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DRIVE_RAM_6000_DA, "Deaktiver 8KB RAM-udviddelse pa $6000-$7FFF"},
/* de */ {IDCLS_DISABLE_DRIVE_RAM_6000_DE, "8KB RAM Erweiterung bei $6000-7fff deaktivieren"},
/* fr */ {IDCLS_DISABLE_DRIVE_RAM_6000_FR, "Desactiver l'exansion de 8KB RAM a $6000-$7FFF"},
/* hu */ {IDCLS_DISABLE_DRIVE_RAM_6000_HU, "8KB RAM kiterjeszes tiltasa a $6000-$7FFF cimen"},
/* it */ {IDCLS_DISABLE_DRIVE_RAM_6000_IT, "Disattiva l'espansione di RAM di 8KB a $6000-$7FFF"},
/* ko */ {IDCLS_DISABLE_DRIVE_RAM_6000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DRIVE_RAM_6000_NL, "8KB RAM uitbreiding op adres $6000-$7FFF uitschakelen"},
/* pl */ {IDCLS_DISABLE_DRIVE_RAM_6000_PL, "Wy3�}cz rozszerzenie 8KB RAM w $6000-$7FFF"},
/* ru */ {IDCLS_DISABLE_DRIVE_RAM_6000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DRIVE_RAM_6000_SV, "Inaktivera 8KB RAM-expansion pa $6000-$7FFF"},
/* tr */ {IDCLS_DISABLE_DRIVE_RAM_6000_TR, "$6000-$7FFF arasynda 8KB RAM genitletmeyi pasiflettir"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DRIVE_RAM_8000,    N_("Enable 8KB RAM expansion at $8000-$9FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DRIVE_RAM_8000_DA, "Aktiver 8KB RAM-udviddelse pa $8000-$9FFF"},
/* de */ {IDCLS_ENABLE_DRIVE_RAM_8000_DE, "8KB RAM Erweiterung bei $8000-9fff aktivieren"},
/* fr */ {IDCLS_ENABLE_DRIVE_RAM_8000_FR, "Activer l'exansion de 8KB RAM a $8000-$9FFF"},
/* hu */ {IDCLS_ENABLE_DRIVE_RAM_8000_HU, "8KB RAM kiterjeszes engedelyezese a $8000-$9FFF cimen"},
/* it */ {IDCLS_ENABLE_DRIVE_RAM_8000_IT, "Attiva l'espansione di RAM di 8KB a $8000-$9FFF"},
/* ko */ {IDCLS_ENABLE_DRIVE_RAM_8000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DRIVE_RAM_8000_NL, "Activeer 8KB RAM uitbreiding op adres $8000-$9FFF"},
/* pl */ {IDCLS_ENABLE_DRIVE_RAM_8000_PL, "W3�}cz rozszerzenie 8KB RAM w $8000-$9FFF"},
/* ru */ {IDCLS_ENABLE_DRIVE_RAM_8000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DRIVE_RAM_8000_SV, "Aktivera 8KB RAM-expansion pa $8000-$9FFF"},
/* tr */ {IDCLS_ENABLE_DRIVE_RAM_8000_TR, "$8000-$9FFF arasynda 8KB RAM genitletmeyi aktif et"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DRIVE_RAM_8000,    N_("Disable 8KB RAM expansion at $8000-$9FFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DRIVE_RAM_8000_DA, "Deaktiver 8KB RAM-udviddelse pa $8000-$9FFF"},
/* de */ {IDCLS_DISABLE_DRIVE_RAM_8000_DE, "8KB RAM Erweiterung bei $8000-9fff deaktivieren"},
/* fr */ {IDCLS_DISABLE_DRIVE_RAM_8000_FR, "Desactiver l'exansion de 8KB RAM a $8000-$9FFF"},
/* hu */ {IDCLS_DISABLE_DRIVE_RAM_8000_HU, "8KB RAM kiterjeszes tiltasa a $8000-$9FFF cimen"},
/* it */ {IDCLS_DISABLE_DRIVE_RAM_8000_IT, "Disattiva l'espansione di RAM di 8KB a $8000-$9FFF"},
/* ko */ {IDCLS_DISABLE_DRIVE_RAM_8000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DRIVE_RAM_8000_NL, "8KB RAM uitbreiding op adres $8000-$9FFF uitschakelen"},
/* pl */ {IDCLS_DISABLE_DRIVE_RAM_8000_PL, "Wy3�}cz rozszerzenie 8KB RAM w $8000-$9FFF"},
/* ru */ {IDCLS_DISABLE_DRIVE_RAM_8000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DRIVE_RAM_8000_SV, "Inaktivera 8KB RAM-expansion pa $8000-$9FFF"},
/* tr */ {IDCLS_DISABLE_DRIVE_RAM_8000_TR, "$8000-$9FFF arasynda 8KB RAM genitletmeyi pasiflettir"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DRIVE_RAM_A000,    N_("Enable 8KB RAM expansion at $A000-$BFFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DRIVE_RAM_A000_DA, "Aktiver 8KB RAM-udviddelse pa $A000-$BFFF"},
/* de */ {IDCLS_ENABLE_DRIVE_RAM_A000_DE, "8KB RAM Erweiterung bei $A000-Bfff aktivieren"},
/* fr */ {IDCLS_ENABLE_DRIVE_RAM_A000_FR, "Activer l'exansion de 8KB RAM a $A000-$BFFF"},
/* hu */ {IDCLS_ENABLE_DRIVE_RAM_A000_HU, "8KB RAM kiterjeszes engedelyezese a $A000-$BFFF cimen"},
/* it */ {IDCLS_ENABLE_DRIVE_RAM_A000_IT, "Attiva l'espansione di RAM di 8KB a $A000-$BFFF"},
/* ko */ {IDCLS_ENABLE_DRIVE_RAM_A000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DRIVE_RAM_A000_NL, "Activeer 8KB RAM uitbreiding op adres $A000-$BFFF"},
/* pl */ {IDCLS_ENABLE_DRIVE_RAM_A000_PL, "W3�}cz rozszerzenie 8KB RAM w $A000-$BFFF"},
/* ru */ {IDCLS_ENABLE_DRIVE_RAM_A000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DRIVE_RAM_A000_SV, "Aktivera 8KB RAM-expansion pa $A000-$BFFF"},
/* tr */ {IDCLS_ENABLE_DRIVE_RAM_A000_TR, "$A000-$BFFF arasynda 8KB RAM genitletmeyi aktif et"},
#endif

/* drive/iec/iec-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DRIVE_RAM_A000,    N_("Disable 8KB RAM expansion at $A000-$BFFF")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DRIVE_RAM_A000_DA, "Deaktiver 8KB RAM-udviddelse pa $A000-$BFFF"},
/* de */ {IDCLS_DISABLE_DRIVE_RAM_A000_DE, "8KB RAM Erweiterung bei $A000-Bfff deaktivieren"},
/* fr */ {IDCLS_DISABLE_DRIVE_RAM_A000_FR, "Desactiver l'exansion de 8KB RAM a $A000-$BFFF"},
/* hu */ {IDCLS_DISABLE_DRIVE_RAM_A000_HU, "8KB RAM kiterjeszes tiltasa a $A000-$BFFF cimen"},
/* it */ {IDCLS_DISABLE_DRIVE_RAM_A000_IT, "Disattiva l'espansione di RAM di 8KB a $A000-$BFFF"},
/* ko */ {IDCLS_DISABLE_DRIVE_RAM_A000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DRIVE_RAM_A000_NL, "8KB RAM uitbreiding op adres $A000-$BFFF uitschakelen"},
/* pl */ {IDCLS_DISABLE_DRIVE_RAM_A000_PL, "Wy3�}cz rozszerzenie 8KB RAM w $A000-$BFFF"},
/* ru */ {IDCLS_DISABLE_DRIVE_RAM_A000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DRIVE_RAM_A000_SV, "Inaktivera 8KB RAM-expansion pa $A000-$BFFF"},
/* tr */ {IDCLS_DISABLE_DRIVE_RAM_A000_TR, "$A000-$BFFF arasynda 8KB RAM genitletmeyi pasiflettir"},
#endif

/* drive/iec/c64exp/c64exp-cmdline-options.c */
/* en */ {IDCLS_PAR_CABLE_C64EXP_TYPE,    N_("Set parallel cable type (0: none, 1: standard, 2: Dolphin DOS 3)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PAR_CABLE_C64EXP_TYPE_DA, "Valg typen af parallelkabel (0: ingen, 1: standard, 2: Dolphin DOS 3)"},
/* de */ {IDCLS_PAR_CABLE_C64EXP_TYPE_DE, "Parallelkabel Typ (0: kein, 1: Standard, 2: Dolphin DOS 3)"},
/* fr */ {IDCLS_PAR_CABLE_C64EXP_TYPE_FR, "Definir le type de cable parallele (0: aucun, 1: standard, 2: Dolphin DOS 3)"},
/* hu */ {IDCLS_PAR_CABLE_C64EXP_TYPE_HU, "Adja meg a parhuzamos kabel tipusat (0: nincs, 1: standard, 2: Dolphin DOS 3)"},
/* it */ {IDCLS_PAR_CABLE_C64EXP_TYPE_IT, "Imposta il tipo di cavo parallelo (0: nessuno, 1: standard, 2: Dolphin DOS 3)"},
/* ko */ {IDCLS_PAR_CABLE_C64EXP_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PAR_CABLE_C64EXP_TYPE_NL, "Zet parallele kabelsoort (0: geen, 1: standaard, 2: Dolphin DOS 3)"},
/* pl */ {IDCLS_PAR_CABLE_C64EXP_TYPE_PL, "Okre��l typ 3�}cza rownoleg3ego (0: brak, 1: zwyk3e, 2: Dolphin DOS 3)"},
/* ru */ {IDCLS_PAR_CABLE_C64EXP_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PAR_CABLE_C64EXP_TYPE_SV, "Valj typ av parallellkabel (0: ingen, 1: standard, 2: Dolphin DOS 3)"},
/* tr */ {IDCLS_PAR_CABLE_C64EXP_TYPE_TR, "Paralel kablo tipini ayarla (0: yok, 1: standart, 2: Dolphin DOS 3)"},
#endif

/* drive/iec/c64exp/c64exp-cmdline-options.c */
/* en */ {IDCLS_ENABLE_PROFDOS,    N_("Enable Professional DOS")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PROFDOS_DA, "Aktiver Professional DOS"},
/* de */ {IDCLS_ENABLE_PROFDOS_DE, "Professional DOS aktivieren"},
/* fr */ {IDCLS_ENABLE_PROFDOS_FR, "Activer le DOS Professionnel"},
/* hu */ {IDCLS_ENABLE_PROFDOS_HU, "Professional DOS engedelyezese"},
/* it */ {IDCLS_ENABLE_PROFDOS_IT, "Attiva Professional DOS"},
/* ko */ {IDCLS_ENABLE_PROFDOS_KO, "Professional DOS ��c?e��!�LECI��O CI�}a"},
/* nl */ {IDCLS_ENABLE_PROFDOS_NL, "Activeer Professional DOS"},
/* pl */ {IDCLS_ENABLE_PROFDOS_PL, "W3�}cz Professional DOS"},
/* ru */ {IDCLS_ENABLE_PROFDOS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PROFDOS_SV, "Aktivera Professional DOS"},
/* tr */ {IDCLS_ENABLE_PROFDOS_TR, "Professional DOS'u aktif et"},
#endif

/* drive/iec/c64exp/c64exp-cmdline-options.c */
/* en */ {IDCLS_DISABLE_PROFDOS,    N_("Disable Professional DOS")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PROFDOS_DA, "Deaktiver Professional DOS"},
/* de */ {IDCLS_DISABLE_PROFDOS_DE, "Professional DOS deaktivieren"},
/* fr */ {IDCLS_DISABLE_PROFDOS_FR, "Desactiver le DOS Professionnel"},
/* hu */ {IDCLS_DISABLE_PROFDOS_HU, "Professional DOS tiltasa"},
/* it */ {IDCLS_DISABLE_PROFDOS_IT, "Disattiva Professional DOS"},
/* ko */ {IDCLS_DISABLE_PROFDOS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PROFDOS_NL, "Professional DOS uitschakelen"},
/* pl */ {IDCLS_DISABLE_PROFDOS_PL, "Wy3�}cz Professional DOS"},
/* ru */ {IDCLS_DISABLE_PROFDOS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PROFDOS_SV, "Inaktivera Professional DOS"},
/* tr */ {IDCLS_DISABLE_PROFDOS_TR, "Professional DOS'u pasiflettir"},
#endif

/* drive/iec/c64exp/c64exp-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME,    N_("Specify name of Professional DOS 1571 ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_DA, "Angiv navn pa Professional DOS 1571-ROM-image"},
/* de */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_DE, "Name von Professional DOS 1571 Datei definieren"},
/* fr */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_HU, "Adja meg a Professional DOS 1571 ROM kepmast"},
/* it */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_IT, "Specifica il nome immagine della ROM del Professional DOS 1571"},
/* ko */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_NL, "Geef de naam van het Professional DOS 1571 ROM bestand"},
/* pl */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_PL, "Okre��l nazwe obrazu ROM Professional DOS 1571"},
/* ru */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_SV, "Ange namn pa Professional DOS 1571-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_PROFDOS_1571_ROM_NAME_TR, "Professional DOS 1571 ROM imaj ismini belirt"},
#endif

/* drive/iec/plus4exp/plus4exp-cmdline-options.c */
/* en */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE,    N_("Set parallel cable type (0: none, 1: standard)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_DA, "Valg typen af parallelkabel parallellkabel (0: ingen, 1: standard)"},
/* de */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_DE, "Parallelkabel Typ (0: kein, 1: Standard)"},
/* fr */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_FR, "Definir le type de cable parallele (0: aucun, 1: standard)"},
/* hu */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_HU, "Adja meg a parhuzamos kabel tipusat (0: nincs, 1: standard)"},
/* it */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_IT, "Imposta il tipo di cavo parallelo (0: nessuno, 1: standard)"},
/* ko */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_NL, "Zet parallelle kabelsoort (0: geen, 1: standaard)"},
/* pl */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_PL, "Ustaw typ kabla portu rownoleg3ego (0: brak, 1: typowy)"},
/* ru */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_SV, "Valj typ av parallellkabel (0: ingen, 1: standard)"},
/* tr */ {IDCLS_PAR_CABLE_PLUS4EXP_TYPE_TR, "Paralel kablo tipini ayarlayyn (0: yok, 1: standart)"},
#endif

/* drive/iec128dcr/iec128dcr-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME,    N_("Specify name of 1571CR DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_DA, "Angiv navn pa 1571CR-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_DE, "Name der 1571CR DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_FR, "Specifier le nom de l'image 1571CR DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_HU, "Adja meg az 1571CR DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1571CR"},
/* ko */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_NL, "Geef de naam van het 1571CR DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 1571CR DOS ROM"},
/* ru */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_SV, "Ange namn pa 1571CR-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1571CR_DOS_ROM_NAME_TR, "1571CR DOS ROM imaj ismini belirt"},
#endif

/* drive/ieee/ieee-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME,    N_("Specify name of 2031 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_DA, "Angiv navn pa 2031-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_DE, "Name der 2031 DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_FR, "Specifier le nom de l'image 2031 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_HU, "Adja meg a 2031 DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 2031"},
/* ko */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_NL, "Geef de naam van het 2031 DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 2031 DOS ROM"},
/* ru */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_SV, "Ange namn pa 2031-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_2031_DOS_ROM_NAME_TR, "2031 DOS ROM imaj ismini belirt"},
#endif

/* drive/ieee/ieee-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME,    N_("Specify name of 2040 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_DA, "Angiv navn pa 2040-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_DE, "Name der 2040 DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_FR, "Specifier le nom de l'image 2040 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_HU, "Adja meg a 2040 DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 2040"},
/* ko */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_NL, "Geef de naam van het 2040 DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 2040 DOS ROM"},
/* ru */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_SV, "Ange namn pa 2040-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_2040_DOS_ROM_NAME_TR, "2040 DOS ROM imaj ismini belirt"},
#endif

/* drive/ieee/ieee-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME,    N_("Specify name of 3040 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_DA, "Angiv navn pa 3040-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_DE, "Name der 3040 DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_FR, "Specifier le nom de l'image 3040 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_HU, "Adja meg a 3040 DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 3040"},
/* ko */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_NL, "Geef de naam van het 3040 DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 3040 DOS ROM"},
/* ru */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_SV, "Ange namn pa 3040-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_3040_DOS_ROM_NAME_TR, "3040 DOS ROM imaj ismini belirt"},
#endif

/* drive/ieee/ieee-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME,    N_("Specify name of 4040 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_DA, "Angiv navn pa 4040-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_DE, "Name der 4040 DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_FR, "Specifier le nom de l'image 4040 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_HU, "Adja meg a 4040 DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 4040"},
/* ko */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_NL, "Geef de naam van het 4040 DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 4040 DOS ROM"},
/* ru */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_SV, "Ange namn pa 4040-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_4040_DOS_ROM_NAME_TR, "4040 DOS ROM imaj ismini belirt"},
#endif

/* drive/ieee/ieee-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME,    N_("Specify name of 1001/8050/8250 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_DA, "Angiv navn pa 1001/8050/8250-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_DE, "Name der 1001/8040/8205 DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_FR, "Specifier le nom de l'image 1001/8050/8250 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_HU, "Adja meg az 1001/8050/8250 DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1001/8050/8250"},
/* ko */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_NL, "Geef de naam van het 1001/8050/8250 DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 1001/8050/8250 DOS ROM"},
/* ru */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_SV, "Ange namn pa 1001/8050/8250-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1001_DOS_ROM_NAME_TR, "1001/8050/8250 DOS ROM imaj ismini belirt"},
#endif

/* drive/tcbm/tcbm-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME,    N_("Specify name of 1551 DOS ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_DA, "Angiv navn pa 1551-DOS-ROM-image"},
/* de */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_DE, "Name der 1551 DOS ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_FR, "Specifier le nom de l'image 1551 DOS ROM"},
/* hu */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_HU, "Adja meg az 1551 DOS ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_IT, "Specifica il nome immagine della ROM del DOS del 1551"},
/* ko */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_NL, "Geef de naam van het 1551 DOS ROM bestand"},
/* pl */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_PL, "Okre��l nazwe obrazu 1551 DOS ROM"},
/* ru */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_SV, "Ange namn pa 1551-DOS-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_1551_DOS_ROM_NAME_TR, "1551 DOS ROM imaj ismini belirt"},
#endif

/* fsdevice/fsdevice-cmdline-options.c */
/* en */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8,    N_("Use <name> as directory for file system device #8")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_DA, "Brug <navn> som katalog for filsystembaseret drev #8"},
/* de */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_DE, "Benutze <Name> fur Verzeichnis beim Verzeichniszugriff fur Gerat #8"},
/* fr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_FR, "Utiliser le repertoire <nom> comme systeme de fichiers pour le lecteur #8"},
/* hu */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_HU, "<nev> konyvtar hasznalata az #8-as egyseg fajlrendszerenek"},
/* it */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_IT, "Una <nome> come direcory per il file system della periferica #8"},
/* ko */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_NL, "Gebruik <naam> als directory voor bestandssysteemapparaat #8"},
/* pl */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_PL, "Uzyj <nazwa> jako katalog urz�}dzenia systemu plikow #8"},
/* ru */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_SV, "Ange <namn> som katalog for filsystemsbaserad enhet 8"},
/* tr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_8_TR, "<isim>'i aygyt #8'in dosya sistemi dizini olarak kullan"},
#endif

/* fsdevice/fsdevice-cmdline-options.c */
/* en */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9,    N_("Use <name> as directory for file system device #9")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_DA, "Brug <navn> som katalog for filsystembaseret drev #9"},
/* de */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_DE, "Benutze <Name> fur Verzeichnis beim Verzeichniszugriff fur Gerat #9"},
/* fr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_FR, "Utiliser le repertoire <nom> comme systeme de fichiers pour le lecteur #9"},
/* hu */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_HU, "<nev> konyvtar hasznalata az #9-es egyseg fajlrendszerenek"},
/* it */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_IT, "Una <nome> come direcory per il file system della periferica #9"},
/* ko */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_NL, "Gebruik <naam> als directory voor bestandssysteemapparaat #9"},
/* pl */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_PL, "Uzyj <nazwa> jako katalog urz�}dzenia systemu plikow #9"},
/* ru */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_SV, "Ange <namn> som katalog for filsystemsbaserad enhet 9"},
/* tr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_9_TR, "<isim>'i aygyt #9'un dosya sistemi dizini olarak kullan"},
#endif

/* fsdevice/fsdevice-cmdline-options.c */
/* en */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10,    N_("Use <name> as directory for file system device #10")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_DA, "Brug <navn> som katalog for filsystembaseret drev #10"},
/* de */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_DE, "Benutze <Name> fur Verzeichnis beim Verzeichniszugriff fur Gerat #10"},
/* fr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_FR, "Utiliser le repertoire <nom> comme systeme de fichiers pour le lecteur #10"},
/* hu */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_HU, "<nev> konyvtar hasznalata az #10-es egyseg fajlrendszerenek"},
/* it */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_IT, "Una <nome> come direcory per il file system della periferica #10"},
/* ko */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_NL, "Gebruik <naam> als directory voor bestandssysteemapparaat #10"},
/* pl */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_PL, "Uzyj <nazwa> jako katalog urz�}dzenia systemu plikow #10"},
/* ru */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_SV, "Ange <namn> som katalog for filsystemsbaserad enhet 10"},
/* tr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_10_TR, "<isim>'i aygyt #10'un dosya sistemi dizini olarak kullan"},
#endif

/* fsdevice/fsdevice-cmdline-options.c */
/* en */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11,    N_("Use <name> as directory for file system device #11")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_DA, "Brug <navn> som katalog for filsystembaseret drev #11"},
/* de */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_DE, "Benutze <Name> fur Verzeichnis beim Verzeichniszugriff fur Gerat #11"},
/* fr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_FR, "Utiliser le repertoire <nom> comme systeme de fichiers pour le lecteur #11"},
/* hu */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_HU, "<nev> konyvtar hasznalata az #11-es egyseg fajlrendszerenek"},
/* it */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_IT, "Una <nome> come direcory per il file system della periferica #11"},
/* ko */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_NL, "Gebruik <naam> als directory voor bestandssysteemapparaat #11"},
/* pl */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_PL, "Uzyj <nazwa> jako katalog urz�}dzenia systemu plikow #11"},
/* ru */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_SV, "Ange <namn> som katalog for filsystemsbaserad enhet 11"},
/* tr */ {IDCLS_USE_AS_DIRECTORY_FSDEVICE_11_TR, "<isim>'i aygyt #11'in dosya sistemi dizini olarak kullan"},
#endif

#ifdef HAVE_FFMPEG
/* gfxoutputdrv/ffmpegdrv.c */
/* en */ {IDCLS_SET_AUDIO_STREAM_BITRATE,    N_("Set bitrate for audio stream in media file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_AUDIO_STREAM_BITRATE_DA, "Angiv bitrate for lydstrom i mediefil"},
/* de */ {IDCLS_SET_AUDIO_STREAM_BITRATE_DE, "Bitrate fur Audio Stream fur Media Datei setzen"},
/* fr */ {IDCLS_SET_AUDIO_STREAM_BITRATE_FR, "Regler le bitrate audio du fichier media"},
/* hu */ {IDCLS_SET_AUDIO_STREAM_BITRATE_HU, "Adja meg az audio bitratat a media fajlhoz"},
/* it */ {IDCLS_SET_AUDIO_STREAM_BITRATE_IT, "Imposta il bitrate del flusso audio nel file multimediale"},
/* ko */ {IDCLS_SET_AUDIO_STREAM_BITRATE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_AUDIO_STREAM_BITRATE_NL, "Zet de bitrate voor het audiogedeelte van het mediabestand"},
/* pl */ {IDCLS_SET_AUDIO_STREAM_BITRATE_PL, "Okre��l szybko��a transmisji strumienia audio w pliku multimediow"},
/* ru */ {IDCLS_SET_AUDIO_STREAM_BITRATE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_AUDIO_STREAM_BITRATE_SV, "Ange bithastighet for ljudstrom i mediafil"},
/* tr */ {IDCLS_SET_AUDIO_STREAM_BITRATE_TR, "Ses akyty icin ortam dosyasyndaki bithyzy'ny ayarla"},
#endif

/* gfxoutputdrv/ffmpegdrv.c */
/* en */ {IDCLS_SET_VIDEO_STREAM_BITRATE,    N_("Set bitrate for video stream in media file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_VIDEO_STREAM_BITRATE_DA, "Angiv bitrate for videostrom i mediefil"},
/* de */ {IDCLS_SET_VIDEO_STREAM_BITRATE_DE, "Bitrate fur Video Stream fur Media Datei setzen"},
/* fr */ {IDCLS_SET_VIDEO_STREAM_BITRATE_FR, "Regler le bitrate video du fichier media"},
/* hu */ {IDCLS_SET_VIDEO_STREAM_BITRATE_HU, "Adja meg az video bitratat a media fajlhoz"},
/* it */ {IDCLS_SET_VIDEO_STREAM_BITRATE_IT, "Imposta il bitrate per il flusso video nel file multimediale"},
/* ko */ {IDCLS_SET_VIDEO_STREAM_BITRATE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_VIDEO_STREAM_BITRATE_NL, "Zet de bitrate voor het videogedeelte van het mediabestand"},
/* pl */ {IDCLS_SET_VIDEO_STREAM_BITRATE_PL, "Okre��l szybko��a transmisji strumienia wideo w pliku multimediow"},
/* ru */ {IDCLS_SET_VIDEO_STREAM_BITRATE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_VIDEO_STREAM_BITRATE_SV, "Ange bithastighet for videostrom i mediafil"},
/* tr */ {IDCLS_SET_VIDEO_STREAM_BITRATE_TR, "Goruntu akyty icin ortam dosyasyndaki bithyzy'ny ayarla"},
#endif
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_PET_MODEL,    N_("Specify PET model to emulate")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PET_MODEL_DA, "Angiv emuleret PET-model"},
/* de */ {IDCLS_SPECIFY_PET_MODEL_DE, "PET Modell spezifizieren"},
/* fr */ {IDCLS_SPECIFY_PET_MODEL_FR, "Specifier le modele PET a emuler"},
/* hu */ {IDCLS_SPECIFY_PET_MODEL_HU, "Adja meg az emulalt PET modellt"},
/* it */ {IDCLS_SPECIFY_PET_MODEL_IT, "Specifica il modello di PET da emulare"},
/* ko */ {IDCLS_SPECIFY_PET_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PET_MODEL_NL, "Geef PET model om te emuleren"},
/* pl */ {IDCLS_SPECIFY_PET_MODEL_PL, "Okre��l emulowany model PET"},
/* ru */ {IDCLS_SPECIFY_PET_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PET_MODEL_SV, "Ange PET-modell att emulera"},
/* tr */ {IDCLS_SPECIFY_PET_MODEL_TR, "Emule edilecek PET modelini belirt"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_EDITOR_ROM_NAME,    N_("Specify name of Editor ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_DA, "Angiv navn pa Editor-ROM-image"},
/* de */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_DE, "Name fur Editor ROM Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_FR, "Specifier le nom de l�fimage ROM Editor"},
/* hu */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_HU, "Adja meg a szerkeszto ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_IT, "Specifica il nome immagine della Editor ROM"},
/* ko */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_NL, "Geef naam van het Editor ROM bestand"},
/* pl */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_PL, "Okre��l nazwe obrazu ROM Editor"},
/* ru */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_SV, "Ange namn pa Editor-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_EDITOR_ROM_NAME_TR, "Editor ROM imajynyn ismini belirt"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME,    N_("Specify 4K extension ROM name at $9***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_DA, "Angiv navn pa 4K-udviddelses-ROM pa $9***"},
/* de */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_DE, "4K Erweiterungs ROM Datei Name bei $9*** definieren"},
/* fr */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_FR, "Specifier le nom de l'extension ROM 4K a $9***"},
/* hu */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_HU, "Adja meg a $9*** cimu 4K ROM kiterjesztes nevet"},
/* it */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_IT, "Specifica il nome della ROM di estensione di 4k a $9***"},
/* ko */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_NL, "Geef naam van het 4K uitbreiding ROM bestand op adres $9***"},
/* pl */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_PL, "Okre��l nazwe rozszerzenia 4K ROM w $9***"},
/* ru */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_SV, "Ange namn pa 4K-utoknings-ROM pa $9***"},
/* tr */ {IDCLS_SPECIFY_4K_ROM_9XXX_NAME_TR, "$9*** adresindeki 4K uzantysy ROM ismini belirt"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME,    N_("Specify 4K extension ROM name at $A***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_DA, "Angiv navn pa 4K-udviddelses-ROM pa $A***"},
/* de */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_DE, "4K Erweiterungs ROM Datei Name bei $A*** definieren"},
/* fr */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_FR, "Specifier le nom de l'extension ROM 4K a $A***"},
/* hu */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_HU, "Adja meg a $A*** cimu 4K ROM kiterjesztes nevet"},
/* it */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_IT, "Specifica il nome della ROM di estensione di 4k a $A***"},
/* ko */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_NL, "Geef naam van het 4K uitbreiding ROM bestand op adres $A***"},
/* pl */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_PL, "Okre��l nazwe rozszerzenia 4K ROM w $A***"},
/* ru */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_SV, "Ange namn pa 4K-utoknings-ROM pa $A***"},
/* tr */ {IDCLS_SPECIFY_4K_ROM_AXXX_NAME_TR, "$A*** adresindeki 4K uzantysy ROM ismini belirt"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME,    N_("Specify 4K extension ROM name at $B***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_DA, "Angiv navn pa 4K-udviddelses-ROM pa $B***"},
/* de */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_DE, "4K Erweiterungs ROM Datei Name bei $B*** definieren"},
/* fr */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_FR, "Specifier le nom de l'extension ROM 4K a $B***"},
/* hu */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_HU, "Adja meg a $B*** cimu 4K ROM kiterjesztes nevet"},
/* it */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_IT, "Specifica il nome della ROM di estensione di 4k a $B***"},
/* ko */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_NL, "Geef naam van het 4K uitbreiding ROM bestand op adres $B***"},
/* pl */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_PL, "Okre��l nazwe rozszerzenia 4K ROM w $B***"},
/* ru */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_SV, "Ange namn pa 4K-utoknings-ROM pa $B***"},
/* tr */ {IDCLS_SPECIFY_4K_ROM_BXXX_NAME_TR, "$B*** adresindeki 4K uzantysy ROM ismini belirt"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000,    N_("Enable PET8296 4K RAM mapping at $9***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_DA, "Aktiver PET8296 4K-RAM-mapping pa $9***"},
/* de */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_DE, "PET8296 4K RAM Zuordnung bei $9*** aktivieren"},
/* fr */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_FR, "Activer l'extension PET8296 4K a $9***"},
/* hu */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_HU, "PET8296 4K RAM engedelyezese a $9*** cimen"},
/* it */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_IT, "Attiva la mappatura della RAM di 4K del PET8296 a $9***"},
/* ko */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_NL, "Activeer PET8296 4K RAM op adres $9***"},
/* pl */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_PL, "W3�}cz mapowanie 4K RAM PET8296 w $9***"},
/* ru */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_SV, "Aktivera PET8296 4K-RAM-mappning pa $9***"},
/* tr */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_9000_TR, "$9*** adresindeki PET8296 4K RAM etlettirmesini aktif et"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000,    N_("Disable PET8296 4K RAM mapping at $9***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_DA, "Deaktiver PET8296 4K-RAM-mapping pa $9***"},
/* de */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_DE, "PET8296 4K RAM Zuordnung bei $9*** deaktivieren"},
/* fr */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_FR, "Desactiver l'extension PET8296 4K a $9***"},
/* hu */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_HU, "PET8296 4K RAM tiltasa a $9*** cimen"},
/* it */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_IT, "Disattiva la mappatura della RAM di 4K del PET8296 a $9***"},
/* ko */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_NL, "PET8296 4K RAM op adres $9*** uitschakelen"},
/* pl */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_PL, "Wy3�}cz mapowanie 4K RAM PET8296 w $9***"},
/* ru */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_SV, "Inaktivera PET8296 4K-RAM-mappning pa $9***"},
/* tr */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_9000_TR, "$9*** adresindeki PET8296 4K RAM etlettirmesini pasiflettir"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000,    N_("Enable PET8296 4K RAM mapping at $A***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_DA, "Aktiver PET8296 4K-RAM-mapping pa $A***"},
/* de */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_DE, "PET8296 4K RAM Zuordnung bei $A*** aktivieren"},
/* fr */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_FR, "Activer l'extension PET8296 4K a $A***"},
/* hu */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_HU, "PET8296 4K RAM engedelyezese a $A*** cimen"},
/* it */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_IT, "Attiva la mappatura della RAM di 4K del PET8296 a $A***"},
/* ko */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_NL, "Activeer PET8296 4K RAM op adres $A***"},
/* pl */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_PL, "W3�}cz mapowanie 4K RAM PET8296 w $A***"},
/* ru */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_SV, "Aktivera PET8296 4K-RAM-mappning pa $A***"},
/* tr */ {IDCLS_PET8296_ENABLE_4K_RAM_AT_A000_TR, "$A*** adresindeki PET8296 4K RAM etlettirmesini aktif et"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000,    N_("Disable PET8296 4K RAM mapping at $A***")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_DA, "Deaktiver PET8296 4K-RAM-mapping pa $A***"},
/* de */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_DE, "PET8296 4K RAM Zuordnung bei $A*** deaktivieren"},
/* fr */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_FR, "Desactiver l'extension PET8296 4K a $A***"},
/* hu */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_HU, "PET8296 4K RAM tiltasa a $A*** cimen"},
/* it */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_IT, "Disattiva la mappatura della RAM di 4K del PET8296 a $A***"},
/* ko */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_NL, "PET8296 4K RAM op adres $A*** uitschakelen"},
/* pl */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_PL, "Wy3�}cz mapowanie 4K RAM PET8296 w $A***"},
/* ru */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_SV, "Inaktivera PET8296 4K-RAM-mappning pa $A***"},
/* tr */ {IDCLS_PET8296_DISABLE_4K_RAM_AT_A000_TR, "$A*** adresindeki PET8296 4K RAM etlettirmesini pasiflettir"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_ENABLE_SUPERPET_IO,    N_("Enable SuperPET I/O")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SUPERPET_IO_DA, "Aktiver SuperPET-I/O"},
/* de */ {IDCLS_ENABLE_SUPERPET_IO_DE, "SuperPET I/O aktivieren"},
/* fr */ {IDCLS_ENABLE_SUPERPET_IO_FR, "Activer les E/S SuperPET"},
/* hu */ {IDCLS_ENABLE_SUPERPET_IO_HU, "SuperPET I/O engedelyezese"},
/* it */ {IDCLS_ENABLE_SUPERPET_IO_IT, "Attiva l'I/O del SuperPET"},
/* ko */ {IDCLS_ENABLE_SUPERPET_IO_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SUPERPET_IO_NL, "Activeer SuperPET I/O"},
/* pl */ {IDCLS_ENABLE_SUPERPET_IO_PL, "W3�}cz we/wy SuperPET"},
/* ru */ {IDCLS_ENABLE_SUPERPET_IO_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SUPERPET_IO_SV, "Aktivera SuperPET-I/O"},
/* tr */ {IDCLS_ENABLE_SUPERPET_IO_TR, "SuperPET G/C'y aktif et"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_DISABLE_SUPERPET_IO,    N_("Disable SuperPET I/O")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SUPERPET_IO_DA, "Deaktiver SuperPET-I/O"},
/* de */ {IDCLS_DISABLE_SUPERPET_IO_DE, "SuperPET I/O deaktivieren"},
/* fr */ {IDCLS_DISABLE_SUPERPET_IO_FR, "Desactiver les E/S SuperPET"},
/* hu */ {IDCLS_DISABLE_SUPERPET_IO_HU, "SuperPET I/O tiltasa"},
/* it */ {IDCLS_DISABLE_SUPERPET_IO_IT, "Disattiva l'I/O del SuperPET"},
/* ko */ {IDCLS_DISABLE_SUPERPET_IO_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SUPERPET_IO_NL, "SuperPET I/O uitschakelen"},
/* pl */ {IDCLS_DISABLE_SUPERPET_IO_PL, "Wy3�}cz we/wy SuperPET"},
/* ru */ {IDCLS_DISABLE_SUPERPET_IO_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SUPERPET_IO_SV, "Inaktivera SuperPET-I/O"},
/* tr */ {IDCLS_DISABLE_SUPERPET_IO_TR, "SuperPET G/C'y pasiflettir"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES,    N_("Enable ROM 1 Kernal patches")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_DA, "Aktiver ROM 1 kerneandringer"},
/* de */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_DE, "ROM 1 Kernal patches aktivieren"},
/* fr */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_FR, "Activer les patches ROM 1 Kernal"},
/* hu */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_HU, "ROM 1 Kernal foltozas engedelyezese"},
/* it */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_IT, "Attiva le patch del Kernal della ROM 1"},
/* ko */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_NL, "Activeer ROM 1 Kernalverbeteringen"},
/* pl */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_PL, "W3�}cz 3atki ROM 1 Kernala"},
/* ru */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_SV, "Aktivera ROM 1-Kernalpatchar"},
/* tr */ {IDCLS_ENABLE_ROM_1_KERNAL_PATCHES_TR, "ROM 1 Kernal yamalaryny aktif et"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES,    N_("Disable ROM 1 Kernal patches")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_DA, "Deaktiver ROM 1 kerneandringer"},
/* de */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_DE, "ROM 1 Kernal patches deaktivieren"},
/* fr */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_FR, "Desactiver les patches ROM 1 Kernal"},
/* hu */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_HU, "ROM 1 Kernal foltozas tiltasa"},
/* it */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_IT, "Disattiva le patch del Kernal della ROM 1"},
/* ko */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_NL, "ROM 1 Kernalverbeteringen uitschakelen"},
/* pl */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_PL, "W3�}cz 3atki ROM 1 Kernala"},
/* ru */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_SV, "Inaktivera ROM 1-Kernalpatchar"},
/* tr */ {IDCLS_DISABLE_ROM_1_KERNAL_PATCHES_TR, "ROM 1 Kernal yamalaryny pasiflettir"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET,    N_("Switch upper/lower case charset")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_DA, "Skift mellem store og sma bogstaver"},
/* de */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_DE, "Wechsel Gros-/Kleinschreibung Zeichensatz"},
/* fr */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_FR, "Inverser le charset majuscule et minuscule"},
/* hu */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_HU, "Valtas nagy-/kisbetus karakterkeszletre"},
/* it */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_IT, "Scambia il set di caratteri maiuscolo/minuscolo"},
/* ko */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_NL, "Schakel tussen grote/kleine letters"},
/* pl */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_PL, "Prze3�}cz zestaw wielkich/ma3ych znakow"},
/* ru */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_SV, "Vaxla sma/stora bokstaver i teckengeneratorn"},
/* tr */ {IDCLS_SWITCH_UPPER_LOWER_CHARSET_TR, "Buyuk/kucuk harf karakter seti dedittir"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET,    N_("Do not switch upper/lower case charset")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_DA, "Skift ikke mellem store og sma bogstaver"},
/* de */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_DE, "Kein Wechsel Gros-/Kleinschreibung Zeichensatz"},
/* fr */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_FR, "Ne pas inverser le charset majuscule et minuscule"},
/* hu */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_HU, "Ne valtson a nagy-/kisbetus karakterkeszletre"},
/* it */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_IT, "Non scambiare il set di caratteri maiuscolo/minuscolo"},
/* ko */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_NL, "Schakel niet tussen grote/kleine letters"},
/* pl */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_PL, "Nie prze3�}czaj zestawu wielkich/ma3ych znakow"},
/* ru */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_SV, "Vaxla inte sma/stora bokstaver i teckengeneratorn"},
/* tr */ {IDCLS_NO_SWITCH_UPPER_LOWER_CHARSET_TR, "Buyuk/kucuk harf karakter seti dedittirme"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_EOI_BLANKS_SCREEN,    N_("EOI blanks screen")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_EOI_BLANKS_SCREEN_DA, "EOI sletter skarmen"},
/* de */ {IDCLS_EOI_BLANKS_SCREEN_DE, "EOI loscht Bildschirm"},
/* fr */ {IDCLS_EOI_BLANKS_SCREEN_FR, "EOI vide l'ecran"},
/* hu */ {IDCLS_EOI_BLANKS_SCREEN_HU, "EOI torli a kepernyot"},
/* it */ {IDCLS_EOI_BLANKS_SCREEN_IT, "EOI oscura lo schermo"},
/* ko */ {IDCLS_EOI_BLANKS_SCREEN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_EOI_BLANKS_SCREEN_NL, "EOI maakt het scherm leeg"},
/* pl */ {IDCLS_EOI_BLANKS_SCREEN_PL, "Koniec przerwania czy��ci ekran"},
/* ru */ {IDCLS_EOI_BLANKS_SCREEN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_EOI_BLANKS_SCREEN_SV, "EOI tommer skarmen"},
/* tr */ {IDCLS_EOI_BLANKS_SCREEN_TR, "EOI ekrany botaltyr"},
#endif

/* pet/pet-cmdline-options.c */
/* en */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN,    N_("EOI does not blank screen")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_DA, "EOI sletter ikke skarmen"},
/* de */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_DE, "EIO loscht Bildschirm nicht"},
/* fr */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_FR, "EOI ne vide pas l'ecran"},
/* hu */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_HU, "EOI nem torli a kepernyot"},
/* it */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_IT, "EOI non oscura lo schermo"},
/* ko */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_NL, "EOI maakt het scherm niet leeg"},
/* pl */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_PL, "Koniec przerwania nie czy��ci ekranu"},
/* ru */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_SV, "EOI tommer inte skarmen"},
/* tr */ {IDCLS_EOI_DOES_NOT_BLANK_SCREEN_TR, "EOI ekrany botaltmaz"},
#endif

/* pet/petpia1.c */
/* en */ {IDCLS_ENABLE_USERPORT_DIAG_PIN,    N_("Enable userport diagnostic pin")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_DA, "Aktiver diagnostik pa brugerporten"},
/* de */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_DE, "Userport Diagnose Pin aktivieren"},
/* fr */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_FR, "Activer la pin de diagnostique userport"},
/* hu */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_HU, "Userport diagnosztikai lab engedelyezese"},
/* it */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_IT, "Attiva pin diagnostico su userport"},
/* ko */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_NL, "Activeer userport diagnostic pin"},
/* pl */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_PL, "W3�}cz pin diagnostyczny userportu"},
/* ru */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_SV, "Aktivera diagnostik pa anvandarporten"},
/* tr */ {IDCLS_ENABLE_USERPORT_DIAG_PIN_TR, "Userport diyagnostik pinini aktif et"},
#endif

/* pet/petpia1.c */
/* en */ {IDCLS_DISABLE_USERPORT_DIAG_PIN,    N_("Disable userport diagnostic pin")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_DA, "Deaktiver diagnostik pa brugerporten"},
/* de */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_DE, "Userport Diagnose Pin deaktivieren"},
/* fr */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_FR, "Desactiver la pin de diagnostique userport"},
/* hu */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_HU, "Userport diagnosztikai lab tiltasa"},
/* it */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_IT, "Disattiva pin diagnostico su userport"},
/* ko */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_NL, "Userport diagnostic pin uitschakelen"},
/* pl */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_PL, "Wy3�}cz pin diagnostyczny userportu"},
/* ru */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_SV, "Inaktivera diagnostik pa anvandarporten"},
/* tr */ {IDCLS_DISABLE_USERPORT_DIAG_PIN_TR, "Userport diyagnostik pinini pasiflettir"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME,    N_("Specify name of Function low ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_DA, "Angiv navn pa image for lav funktions-ROM"},
/* de */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_DE, "Namen fur Funktions ROM Datei (unterer Bereich) definieren"},
/* fr */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_FR, "Specifier le nom de l'image basse ROM Fonction"},
/* hu */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_HU, "Adja meg az also Function ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_IT, "Specifica il nome immagine della Function ROM bassa"},
/* ko */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_NL, "Geef de naam van het Function low ROM bestand"},
/* pl */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_PL, "Okre��l nazwe obrazu ROM Function low"},
/* ru */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_SV, "Ange namn pa ROM-avbildning for lagt funktions-ROM"},
/* tr */ {IDCLS_SPECIFY_FUNCTION_LOW_ROM_NAME_TR, "Function low ROM imajynyn ismini belirt"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME,    N_("Specify name of Function high ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_DA, "Angiv navn pa image for hoj funktions-ROM"},
/* de */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_DE, "Namen fur Funktions ROM Datei (oberer Bereich) definieren"},
/* fr */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_FR, "Specifier le nom de l'image haute ROM Fonction"},
/* hu */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_HU, "Adja meg a felso Function ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_IT, "Specifica il nome immagine della Function ROM alta"},
/* ko */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_NL, "Geef de naam van het Function high ROM bestand"},
/* pl */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_PL, "Okre��l nazwe obrazu ROM Function high"},
/* ru */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_SV, "Ange namn pa ROM-avbildning for hogt funktions-ROM"},
/* tr */ {IDCLS_SPECIFY_FUNCTION_HIGH_ROM_NAME_TR, "Function high ROM imajynyn ismini belirt"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME,    N_("Specify name of Cartridge 1 low ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_DA, "Angiv navn pa image for lav cartridge 1 ROM"},
/* de */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_DE, "Name fur Erweiterungsmodul 1 ROM Datei (unterer Bereich) definieren"},
/* fr */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_FR, "Specifier le nom de l'image basse ROM Cartouche 1"},
/* hu */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_HU, "Adja meg az also Cartridge 1 ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_IT, "Specifica il nome immagine della ROM Cartridge 1 bassa"},
/* ko */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_NL, "Geef de naam van het Cartridge 1 low ROM bestand"},
/* pl */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_PL, "Okre��l nazwe obrazu ROM Cartridge 1 low"},
/* ru */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_SV, "Ange namn pa ROM-avbildning for lagt insticksmodul 1-ROM"},
/* tr */ {IDCLS_SPECIFY_CART_1_LOW_ROM_NAME_TR, "Cartridge 1 low ROM imajynyn ismini belirt"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME,    N_("Specify name of Cartridge 1 high ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_DA, "Angiv navn pa image for hoj cartridge 1 ROM"},
/* de */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_DE, "Name fur Erweiterungsmodul 1 ROM Datei (oberer Bereich) definieren"},
/* fr */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_FR, "Specifier le nom de l'image haute ROM Cartouche 1"},
/* hu */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_HU, "Adja meg a felso Cartridge 1 ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_IT, "Specifica il nome immagine della ROM Cartridge 1 alta"},
/* ko */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_NL, "Geef de naam van het Cartridge 1 high ROM bestand"},
/* pl */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_PL, "Okre��l nazwe obrazu ROM Cartridge 1 high"},
/* ru */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_SV, "Ange namn pa ROM-avbildning for hogt insticksmodul 1-ROM"},
/* tr */ {IDCLS_SPECIFY_CART_1_HIGH_ROM_NAME_TR, "Cartridge 1 high ROM imajynyn ismini belirt"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME,    N_("Specify name of Cartridge 2 low ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_DA, "Angiv navn pa image for lav cartridge 2 ROM"},
/* de */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_DE, "Name fur Erweiterungsmodul 2 ROM Datei (unterer Bereich) definieren"},
/* fr */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_FR, "Specifier le nom de l'image basse ROM Cartouche 2"},
/* hu */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_HU, "Adja meg az also Cartridge 2 ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_IT, "Specifica il nome immagine della ROM Cartridge 2 bassa"},
/* ko */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_NL, "Geef de naam van het Cartridge 2 low ROM bestand"},
/* pl */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_PL, "Okre��l nazwe obrazu ROM Cartridge 2 low"},
/* ru */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_SV, "Ange namn pa ROM-avbildning for lagt insticksmodul 2-ROM"},
/* tr */ {IDCLS_SPECIFY_CART_2_LOW_ROM_NAME_TR, "Cartridge 2 low ROM imajynyn ismini belirt"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME,    N_("Specify name of Cartridge 2 high ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_DA, "Angiv navn pa image for hoj cartridge 1 ROM"},
/* de */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_DE, "Name fur Erweiterungsmodul 2 ROM Datei (oberer Bereich) definieren"},
/* fr */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_FR, "Specifier le nom de l'image haute ROM Cartouche 2"},
/* hu */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_HU, "Adja meg a felso Cartridge 2 ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_IT, "Specifica il nome immagine della ROM Cartridge 2 alta"},
/* ko */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_NL, "Geef de naam van het Cartridge 2 high ROM bestand"},
/* pl */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_PL, "Okre��l nazwe obrazu ROM Cartridge 2 high"},
/* ru */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_SV, "Ange namn pa ROM-avbildning for hogt insticksmodul 2-ROM"},
/* tr */ {IDCLS_SPECIFY_CART_2_HIGH_ROM_NAME_TR, "Cartridge 2 high ROM imajynyn ismini belirt"},
#endif

/* plus4/plus4-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_RAM_INSTALLED,    N_("Specify size of RAM installed in kb (16/32/64)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RAM_INSTALLED_DA, "Angiv storrelse pa installeret RAM i kB (16/32/64)"},
/* de */ {IDCLS_SPECIFY_RAM_INSTALLED_DE, "Grose des emulierten RAM Speichers in kb (16/32/64) spezifizieren"},
/* fr */ {IDCLS_SPECIFY_RAM_INSTALLED_FR, "Specifier la taille du RAM installe (16/32/64)"},
/* hu */ {IDCLS_SPECIFY_RAM_INSTALLED_HU, "Adja meg a telepitett RAM meretet kb-ban (16/32/64)"},
/* it */ {IDCLS_SPECIFY_RAM_INSTALLED_IT, "Specifica la dimensione della RAM installata in kb (16/32/64)"},
/* ko */ {IDCLS_SPECIFY_RAM_INSTALLED_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RAM_INSTALLED_NL, "Geef de hoeveelheid RAM in kb (16/32/64)"},
/* pl */ {IDCLS_SPECIFY_RAM_INSTALLED_PL, "Okre��l ilo��a zainstalowanego RAM-u w kb (16/32/64)"},
/* ru */ {IDCLS_SPECIFY_RAM_INSTALLED_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RAM_INSTALLED_SV, "Ange storlek pa installerat RAM i kb (16/32/64)"},
/* tr */ {IDCLS_SPECIFY_RAM_INSTALLED_TR, "Kurulmut olan RAM boyutunu kb cinsinden belirt (16/32/64)"},
#endif

/* plus4/ted-cmdline-options.c, vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_SATURATION,    N_("Set saturation of internal calculated palette [1000]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_SATURATION_DA, "Indstil matning af internt beregnet palette [1000]"},
/* de */ {IDCLS_SET_SATURATION_DE, "Sattigung fur intern berechneten Palette setzen [1000]"},
/* fr */ {IDCLS_SET_SATURATION_FR, "Regler la saturation de la palette interne calculee [1000]"},
/* hu */ {IDCLS_SET_SATURATION_HU, "A szamolt paletta telitettsege [1000]"},
/* it */ {IDCLS_SET_SATURATION_IT, "Imposta la saturazione della palette calcolata internamente [1000]"},
/* ko */ {IDCLS_SET_SATURATION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_SATURATION_NL, "Zet de verzadiging van het intern berekend kleurenpalet [1000]"},
/* pl */ {IDCLS_SET_SATURATION_PL, "Okre��l nasycenie wewnetrznie obliczonej palety kolorystycznej [1000]"},
/* ru */ {IDCLS_SET_SATURATION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_SATURATION_SV, "Stall in mattnad pa internt beraknad palett [1000]"},
/* tr */ {IDCLS_SET_SATURATION_TR, "Dahili hesaplanmyt paletin doygunludunu ayarlayyn [1000]"},
#endif

/* plus4/ted-cmdline-options.c, vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_CONTRAST,    N_("Set contrast of internal calculated palette [1000]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_CONTRAST_DA, "Indstil kontrast for internt beregnet palette [1000]"},
/* de */ {IDCLS_SET_CONTRAST_DE, "Kontrast fur intern berechnete Palette setzen [1000]"},
/* fr */ {IDCLS_SET_CONTRAST_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_CONTRAST_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_CONTRAST_IT, "Imposta il constrasto della palette calcolata internamente [1000]"},
/* ko */ {IDCLS_SET_CONTRAST_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_CONTRAST_NL, "Zet het contrast van het intern berekend kleurenpalet [1000]"},
/* pl */ {IDCLS_SET_CONTRAST_PL, "Okre��l kontrast wewnetrznie obliczonej palety kolorystycznej [1000]"},
/* ru */ {IDCLS_SET_CONTRAST_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_CONTRAST_SV, "Stall in kontrast pa internt beraknad palett [1000]"},
/* tr */ {IDCLS_SET_CONTRAST_TR, "Dahili hesaplanmyt paletin kartytlydyny ayarlayyn [1000]"},
#endif

/* plus4/ted-cmdline-options.c, vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_BRIGHTNESS,    N_("Set brightness of internal calculated palette [1000]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_BRIGHTNESS_DA, "Indstil lysstyrke for internt beregnet palette [1000]"},
/* de */ {IDCLS_SET_BRIGHTNESS_DE, "Helligkeit fur intern berechnete Palette setzen [1000]"},
/* fr */ {IDCLS_SET_BRIGHTNESS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_BRIGHTNESS_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_BRIGHTNESS_IT, "Imposta la luminanza della palette calcolata internamente [1000]"},
/* ko */ {IDCLS_SET_BRIGHTNESS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_BRIGHTNESS_NL, "Zet de helderheid van het intern berekend kleurenpalet [1000]"},
/* pl */ {IDCLS_SET_BRIGHTNESS_PL, "Okre��l jasno��a wewnetrznie obliczonej palety kolorystycznej [1000]"},
/* ru */ {IDCLS_SET_BRIGHTNESS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_BRIGHTNESS_SV, "Stall in ljusstyrka pa internt beraknad palett [1000]"},
/* tr */ {IDCLS_SET_BRIGHTNESS_TR, "Dahili hesaplanmyt paletin parlaklydyny ayarlayyn [1000]"},
#endif

/* plus4/ted-cmdline-options.c`, vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_GAMMA,    N_("Set gamma of internal calculated palette [2200]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_GAMMA_DA, "Indstil gamma for internt beregnet palette [2200]"},
/* de */ {IDCLS_SET_GAMMA_DE, "Gamma fur intern berechnete Palette setzen [2200]"},
/* fr */ {IDCLS_SET_GAMMA_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_GAMMA_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_GAMMA_IT, "Imposta la gamma della palette calcolata internamente [2200]"},
/* ko */ {IDCLS_SET_GAMMA_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_GAMMA_NL, "Zet de gamma van het intern berekend kleurenpalet [2200]"},
/* pl */ {IDCLS_SET_GAMMA_PL, "Okre��l jaskrawo��a wewnetrznie obliczonej palety kolorystycznej [1000]"},
/* ru */ {IDCLS_SET_GAMMA_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_GAMMA_SV, "Stall in gamma pa internt beraknad palett [2200]"},
/* tr */ {IDCLS_SET_GAMMA_TR, "Dahili hesaplanmyt paletin gamasyny ayarlayyn [2200]"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_TINT,    N_("Set tint of internal calculated palette [1000]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_TINT_DA, "Indstil farvetone for internt beregnet palette [1000]"},
/* de */ {IDCLS_SET_TINT_DE, "Farbton fur intern berechneten Palette setzen [1000]"},
/* fr */ {IDCLS_SET_TINT_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_TINT_HU, "A szamolt, belso paletta telitettsege [1000]"},
/* it */ {IDCLS_SET_TINT_IT, "Imposta la sfumatura della palette calcolata internamente [1000]"},
/* ko */ {IDCLS_SET_TINT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_TINT_NL, "Zet de tint van het intern berekend kleuren palette [1000]"},
/* pl */ {IDCLS_SET_TINT_PL, "Okre��l odcien wewnetrznie obliczonej palety kolorystycznej [1000]"},
/* ru */ {IDCLS_SET_TINT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_TINT_SV, "Stall in ton pa internt beraknad palett [1000]"},
/* tr */ {IDCLS_SET_TINT_TR, "Dahili hesaplanmyt paletin tonunu ayarlayyn [1000]"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_ODDLINES_PHASE,    N_("Set phase for color carrier in odd lines [1250]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_ODDLINES_PHASE_DA, "Valg fase for farve-barebolge pa ulige scanlinjer [1250]"},
/* de */ {IDCLS_SET_ODDLINES_PHASE_DE, "Phase fur Farbtrager in ungeraden Zeilen setzen [1250]"},
/* fr */ {IDCLS_SET_ODDLINES_PHASE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_ODDLINES_PHASE_HU, "Szin vivo fazisa a paratlan sorokban [1250]"},
/* it */ {IDCLS_SET_ODDLINES_PHASE_IT, "Imposta la fase per la portante colore nelle linee dispari [1250]"},
/* ko */ {IDCLS_SET_ODDLINES_PHASE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_ODDLINES_PHASE_NL, "Zet de fase van de kleuren drager in oneven lijnen [1250]"},
/* pl */ {IDCLS_SET_ODDLINES_PHASE_PL, "Okre��l faze no��nika koloru w liniach nieparzystych [1250]"},
/* ru */ {IDCLS_SET_ODDLINES_PHASE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_ODDLINES_PHASE_SV, "Valj fas for fargbararvag pa udda rader [1250]"},
/* tr */ {IDCLS_SET_ODDLINES_PHASE_TR, "Tek satyrlardaki renk tatyyycylary icin fazy ayarlayyn [1250]"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_ODDLINES_OFFSET,    N_("Set phase offset for color carrier in odd lines [750]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_ODDLINES_OFFSET_DA, "Valg fase-offset for farve-barebolge pa ulige scanlinjer [750]"},
/* de */ {IDCLS_SET_ODDLINES_OFFSET_DE, "Phasenoffset fur Farbtrager in ungeraden Zeilen setzen [750]"},
/* fr */ {IDCLS_SET_ODDLINES_OFFSET_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_ODDLINES_OFFSET_HU, "Szin vivo fazis offszet a paratlan sorokban [750]"},
/* it */ {IDCLS_SET_ODDLINES_OFFSET_IT, "Imposta l'offset della fase per la portate colore nelle linee dispari [750]"},
/* ko */ {IDCLS_SET_ODDLINES_OFFSET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_ODDLINES_OFFSET_NL, "Zet de fase compensatie van de kleuren drager in oneven lijnen [750]"},
/* pl */ {IDCLS_SET_ODDLINES_OFFSET_PL, "Okre��l wyrownanie fazy no��nika koloru w liniach nieparzystych [750]"},
/* ru */ {IDCLS_SET_ODDLINES_OFFSET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_ODDLINES_OFFSET_SV, "Valj fasutjamning for fargbararvag pa udda rader [1250]"},
/* tr */ {IDCLS_SET_ODDLINES_OFFSET_TR, "Tek satyrlardaki renk tatyyycylary icin faz ofsetini ayarlayyn [750]"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_BLUR,    N_("Amount of horizontal blur for the CRT emulation. [500]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_BLUR_DA, "Mangden af horizontal udtvaring for CRT emulering. [500]"},
/* de */ {IDCLS_SET_BLUR_DE, "Wert fur horizontale Unscharfe fur CRT Emulation. [500]"},
/* fr */ {IDCLS_SET_BLUR_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_BLUR_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_BLUR_IT, "Valore della sfuocatura orizzontale per l'emulazione CRT [500]"},
/* ko */ {IDCLS_SET_BLUR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_BLUR_NL, "Wazigheid hoeveelheid voor de CRT emulatie. [500]"},
/* pl */ {IDCLS_SET_BLUR_PL, "Rozmycie w poziomie emulacji CRT [500]"},
/* ru */ {IDCLS_SET_BLUR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_BLUR_SV, "Mangd horisontell oskarpa for CRT-emulering. [500]"},
/* tr */ {IDCLS_SET_BLUR_TR, "CRT emulasyonu icin yatay bulanyklyk miktary. [500]"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_SCANLINE_SHADE,    N_("Amount of scan line shading for the CRT emulation [667]")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_SCANLINE_SHADE_DA, "Mangden af scanlinjeskygge for CRT emulering [667]"},
/* de */ {IDCLS_SET_SCANLINE_SHADE_DE, "Wert fur Scanline Schatten fur CRT Emulation [667]"},
/* fr */ {IDCLS_SET_SCANLINE_SHADE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_SCANLINE_SHADE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_SCANLINE_SHADE_IT, "Valore dell'ombreggiatura della scan line per l'emulazione CRT [667]"},
/* ko */ {IDCLS_SET_SCANLINE_SHADE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_SCANLINE_SHADE_NL, "Hoeveelheid van de scan lijn schaduw voor de CRT emulatie [667]"},
/* pl */ {IDCLS_SET_SCANLINE_SHADE_PL, "Cieniowanie linii wybierania emulacji CRT [667]"},
/* ru */ {IDCLS_SET_SCANLINE_SHADE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_SCANLINE_SHADE_SV, "Mangd skannlinjeskuggning i CRT-emuleringen [667]"},
/* tr */ {IDCLS_SET_SCANLINE_SHADE_TR, "CRT emulasyonu icin tarama satyry nuans miktary [667]"},
#endif

/* viciisc/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_VICII_MODEL,    N_("Set VIC-II model (6569/6569r1/8565/6567/8562/6567r56a)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_VICII_MODEL_DA, "Valg VIC-II model (6569/6569r1/8565/6567/8562/6567r56a)"},
/* de */ {IDCLS_SET_VICII_MODEL_DE, "Wahle VIC-II Modell (6569/6569r1/8565/6567/8562/6567r56a)"},
/* fr */ {IDCLS_SET_VICII_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_VICII_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_VICII_MODEL_IT, "Imposta modello VIC-II (6569/6569r1/8565/6567/8562/6567r56a)"},
/* ko */ {IDCLS_SET_VICII_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_VICII_MODEL_NL, "Zet VIC-II model (6569/6569r1/8565/6567/8562/6567r56a)"},
/* pl */ {IDCLS_SET_VICII_MODEL_PL, "Ustaw model VIC-II (6569/6569r1/8565/6567/8562/6567r56a)"},
/* ru */ {IDCLS_SET_VICII_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_VICII_MODEL_SV, "Valj VIC-II-modell (6569/6569r1/8565/6567/8562/6567r56a)"},
/* tr */ {IDCLS_SET_VICII_MODEL_TR, "VIC-II modelini ayarla (6569/6569r1/8565/6567/8562/6567r56a)"},
#endif

/* printerdrv/driver-select.c */
/* en */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME,    N_("Specify name of printer driver for device #4")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_DA, "Angiv navn pa printer-driver for enhed #4"},
/* de */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_DE, "Name fur Druckertreiber Gerat #4 definieren"},
/* fr */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_FR, "Specifier le nom du pilote imprimante pour le peripherique #4"},
/* hu */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_HU, "Adja meg a #4-es nyomtatomeghajto nevet"},
/* it */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_IT, "Specifica il nome del driver di stampa per la periferica #4"},
/* ko */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_NL, "Geef de naam van het stuurprogramma voor apparaat #4"},
/* pl */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_PL, "Okre��l nazwe sterownika drukarki urz�}dzenia #4"},
/* ru */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_SV, "Ange namn pa skrivardrivrutin for enhet 4"},
/* tr */ {IDCLS_SPECIFY_PRT_DRIVER_4_NAME_TR, "Aygyt #4 icin yazycy surucusu ismini belirt"},
#endif

/* printerdrv/driver-select.c */
/* en */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME,    N_("Specify name of printer driver for device #5")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_DA, "Angiv navn pa printer-driver for enhed #5"},
/* de */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_DE, "Name fur Druckertreiber Gerat #5 definieren"},
/* fr */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_FR, "Specifier le nom du pilote imprimante pour le peripherique #5"},
/* hu */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_HU, "Adja meg a #5-os nyomtatomeghajto nevet"},
/* it */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_IT, "Specifica il nome del driver di stampa per la periferica #5"},
/* ko */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_NL, "Geef de naam van het stuurprogramma voor apparaat #5"},
/* pl */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_PL, "Okre��l nazwe sterownika drukarki urz�}dzenia #5"},
/* ru */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_SV, "Ange namn pa skrivardrivrutin for enhet 5"},
/* tr */ {IDCLS_SPECIFY_PRT_DRIVER_5_NAME_TR, "Aygyt #5 icin yazycy surucusu ismini belirt"},
#endif

/* printerdrv/driver-select.c */
/* en */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME,    N_("Specify name of printer driver for the userport printer")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_DA, "Angiv navn pa printerdriver for brugerport-printer"},
/* de */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_DE, "Name fur Userport Druckertreiber definieren"},
/* fr */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_FR, "Specifier le nom du pilote imprimante pour l'imprimante userport"},
/* hu */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_HU, "Adja meg a userport nyomtatomeghajto nevet"},
/* it */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_IT, "Specifica il nome del driver di stampa per la stampante su userport"},
/* ko */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_NL, "Geef de naam van het stuurprogramma voor de userport printer"},
/* pl */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_PL, "Okre��l nazwe sterownika drukarki dla drukarki w userporcie"},
/* ru */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_SV, "Ange namn pa skrivardrivrutin for anvandarporten"},
/* tr */ {IDCLS_SPECIFY_PRT_DRIVER_USR_NAME_TR, "Userport yazycysy icin yazycy surucusu ismini belirt"},
#endif

/* printerdrv/interface-serial.c */
/* en */ {IDCLS_SET_DEVICE_TYPE_4,    N_("Set device type for device #4 (0: NONE, 1: FS, 2: REAL)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DEVICE_TYPE_4_DA, "Sat enhedstype for enhed #4 (0: INGEN, 1: FS, 2: AGTE)"},
/* de */ {IDCLS_SET_DEVICE_TYPE_4_DE, "Gerate Typ fur Gerat #4 (0: NONE, 1: FS, 2: REAL) setzen"},
/* fr */ {IDCLS_SET_DEVICE_TYPE_4_FR, "Specifier le type de peripherique pour #4 (0: AUCUN, 1: SF, 2: REEL)"},
/* hu */ {IDCLS_SET_DEVICE_TYPE_4_HU, "Adja meg a #4-es eszkoz tipusat (0:Nincs, 1: Fajlrendszer, 2: Valodi)"},
/* it */ {IDCLS_SET_DEVICE_TYPE_4_IT, "Specifica il tipo di periferica #4 (0 NESSUNA, 1 FS, 2 REALE)"},
/* ko */ {IDCLS_SET_DEVICE_TYPE_4_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DEVICE_TYPE_4_NL, "Zet apparaat soort voor apparaat #4 (0: GEEN, 1: FS, 2: ECHT)"},
/* pl */ {IDCLS_SET_DEVICE_TYPE_4_PL, "Okre��l typ urz�}dzenia #4 (0: BRAK, 1: SYSTEM PLIKOW, 2: RZECZYWISTE)"},
/* ru */ {IDCLS_SET_DEVICE_TYPE_4_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DEVICE_TYPE_4_SV, "Ange enhetstyp for enhet 4 (0: INGEN, 1: FS, 2: AKTA)"},
/* tr */ {IDCLS_SET_DEVICE_TYPE_4_TR, "Aygyt #4 icin aygyt tipini ayarlayyn (0: YOK, 1: FS, 2: GERCEK)"},
#endif

/* printerdrv/interface-serial.c */
/* en */ {IDCLS_SET_DEVICE_TYPE_5,    N_("Set device type for device #5 (0: NONE, 1: FS, 2: REAL)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DEVICE_TYPE_5_DA, "Sat enhedstype for enhed #5 (0: INGEN, 1: FS, 2: AGTE)"},
/* de */ {IDCLS_SET_DEVICE_TYPE_5_DE, "Gerate Typ fur Gerat #5 (0: NONE, 1: FS, 2: REAL) setzen"},
/* fr */ {IDCLS_SET_DEVICE_TYPE_5_FR, "Specifier le type de peripherique pour #5 (0: AUCUN, 1: SF, 2: REEL)"},
/* hu */ {IDCLS_SET_DEVICE_TYPE_5_HU, "Adja meg a #5-os eszkoz tipusat (0:Nincs, 1: Fajlrendszer, 2: Valodi)"},
/* it */ {IDCLS_SET_DEVICE_TYPE_5_IT, "Specifica il tipo di periferica #5 (0 NESSUNA, 1 FS, 2 REALE)"},
/* ko */ {IDCLS_SET_DEVICE_TYPE_5_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DEVICE_TYPE_5_NL, "Zet apparaat soort voor apparaat #5 (0: GEEN, 1: FS, 2: ECHT)"},
/* pl */ {IDCLS_SET_DEVICE_TYPE_5_PL, "Okre��l typ urz�}dzenia #5 (0: BRAK, 1: SYSTEM PLIKOW, 2: RZECZYWISTE)"},
/* ru */ {IDCLS_SET_DEVICE_TYPE_5_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DEVICE_TYPE_5_SV, "Ange enhetstyp for enhet 5 (0: INGEN, 1: FS, 2: AKTA)"},
/* tr */ {IDCLS_SET_DEVICE_TYPE_5_TR, "Aygyt #5 icin aygyt tipini ayarlayyn (0: YOK, 1: FS, 2: GERCEK)"},
#endif

/* printerdrv/interface-userport.c */
/* en */ {IDCLS_ENABLE_USERPORT_PRINTER,    N_("Enable the userport printer emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_USERPORT_PRINTER_DA, "Aktiver emulering af printer pa brugerporten"},
/* de */ {IDCLS_ENABLE_USERPORT_PRINTER_DE, "Userport Drucker Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_USERPORT_PRINTER_FR, "Acviver l'emulation de l'imprimante userport"},
/* hu */ {IDCLS_ENABLE_USERPORT_PRINTER_HU, "Userport nyomtato emulaciojanak engedelyezese"},
/* it */ {IDCLS_ENABLE_USERPORT_PRINTER_IT, "Attiva l'emulazione della stampante su userport"},
/* ko */ {IDCLS_ENABLE_USERPORT_PRINTER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_USERPORT_PRINTER_NL, "Activeer userport printeremulatie"},
/* pl */ {IDCLS_ENABLE_USERPORT_PRINTER_PL, "W3�}cz emulacje drukarki w userporcie"},
/* ru */ {IDCLS_ENABLE_USERPORT_PRINTER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_USERPORT_PRINTER_SV, "Aktivera emulering av skrivare pa anvandarporten"},
/* tr */ {IDCLS_ENABLE_USERPORT_PRINTER_TR, "Userport yazycy emulasyonunu aktif et"},
#endif

/* printerdrv/interface-userport.c */
/* en */ {IDCLS_DISABLE_USERPORT_PRINTER,    N_("Disable the userport printer emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_USERPORT_PRINTER_DA, "Deaktiver emulering af printer pa brugerporten"},
/* de */ {IDCLS_DISABLE_USERPORT_PRINTER_DE, "Userport Drucker Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_USERPORT_PRINTER_FR, "Desactiver l'emulation de l'imprimante userport"},
/* hu */ {IDCLS_DISABLE_USERPORT_PRINTER_HU, "Userport nyomtato emulaciojanak tiltasa"},
/* it */ {IDCLS_DISABLE_USERPORT_PRINTER_IT, "Disattiva l'emulazione della stampante su userport"},
/* ko */ {IDCLS_DISABLE_USERPORT_PRINTER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_USERPORT_PRINTER_NL, "De userport printeremulatie uitschakelen"},
/* pl */ {IDCLS_DISABLE_USERPORT_PRINTER_PL, "Wy3�}cz emulacje drukarki w userporcie"},
/* ru */ {IDCLS_DISABLE_USERPORT_PRINTER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_USERPORT_PRINTER_SV, "Inaktivera emulering av skrivare pa anvandarporten"},
/* tr */ {IDCLS_DISABLE_USERPORT_PRINTER_TR, "Userport yazycy emulasyonunu pasiflettir"},
#endif

/* printerdrv/output-select.c */
/* en */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME,    N_("Specify name of output device for device #4")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_DA, "Angiv navn pa uddataenhed for enhed #4"},
/* de */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_DE, "Name fur Druckerausgabe Datei Gerat #4 definieren"},
/* fr */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_FR, "Specifiez le nom du peripherique de sortie pour le peripherique #4"},
/* hu */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_HU, "Adja meg a kimeneti eszkoz nevet a #4-es egyseghez"},
/* it */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_IT, "Specifica il nome del dispositivo di output per la periferica #4"},
/* ko */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_NL, "Geef de naam van het uitvoer apparaat voor apparaat #4"},
/* pl */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_PL, "Okre��l nazwe urz�}dzenia wyj��cia #4"},
/* ru */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_SV, "Ange namn pa utskriftsenhet for enhet 4"},
/* tr */ {IDCLS_SPECIFY_OUTPUT_DEVICE_4_NAME_TR, "Aygyt #4 icin cykyt aygyty ismini belirt"},
#endif

/* printerdrv/output-select.c */
/* en */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME,    N_("Specify name of output device for device #5")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_DA, "Angiv navn pa uddataenhed for enhed #5"},
/* de */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_DE, "Name fur Druckerausgabe Datei Gerat #5 definieren"},
/* fr */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_FR, "Specifiez le nom du peripherique de sortie pour le peripherique #5"},
/* hu */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_HU, "Adja meg a kimeneti eszkoz nevet a #5-os egyseghez"},
/* it */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_IT, "Specifica il nome del dispositivo di output per la periferica #5"},
/* ko */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_NL, "Geef de naam van het uitvoer apparaat voor apparaat #5"},
/* pl */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_PL, "Okre��l nazwe urz�}dzenia wyj��cia #5"},
/* ru */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_SV, "Ange namn pa utskriftsenhet for enhet 5"},
/* tr */ {IDCLS_SPECIFY_OUTPUT_DEVICE_5_NAME_TR, "Aygyt #5 icin cykyt aygyty ismini belirt"},
#endif

/* printerdrv/output-select.c */
/* en */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME,    N_("Specify name of output device for the userport printer")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_DA, "Angiv navn pa uddataenhed for brugerports-printer"},
/* de */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_DE, "Name fur Druckerausgabe Datei Userport definieren"},
/* fr */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_FR, "Specifiez le nom du peripherique de sortie pour l'imprimante userport"},
/* hu */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_HU, "Adja meg a kimeneti eszkoz nevet a userport nyomtatohoz"},
/* it */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_IT, "Specifica il nome del dispositivo di output per la stampante su userport"},
/* ko */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_NL, "Geef de naam van het uitvoer apparaat voor de userport printer"},
/* pl */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_PL, "Okre��l nazwe urz�}dzenia wyj��ciowego dla drukarki w userporcie"},
/* ru */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_SV, "Ange namn pa utskriftsenhet for anvandarporten"},
/* tr */ {IDCLS_SPECIFY_OUTPUT_DEVICE_USR_NAME_TR, "Userport yazycysy icin cykyt aygyty ismini belirt"},
#endif

/* printerdrv/output-text.c */
/* en */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME,    N_("Specify name of printer text device or dump file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_DA, "Angiv navn pa printer-tekst-enhed eller dump-fil"},
/* de */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_DE, "Name fur Druckerausgabe Textgerat oder Dump Datei definieren"},
/* fr */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_FR, "Specifier le nom de l'imprimante texte ou \"dump file\""},
/* hu */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_HU, "Adja meg a szovegnyomtato eszkoz nevet, vagy a kimeneti fajlt"},
/* it */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_IT, "Specifica il nome del dispositivo testuale di stampa o salva su file"},
/* ko */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_NL, "Geef de naam van het text apparaat of het dumpbestand"},
/* pl */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_PL, "Okre��l nazwe urz�}dzenia tekstowego drukarki lub pliku zrzutu"},
/* ru */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_SV, "Ange namn pa textenhet for utskrift eller dumpfil"},
/* tr */ {IDCLS_SPECIFY_TEXT_DEVICE_DUMP_NAME_TR, "Metin aygyty yazycysy ya da dokum dosyasynyn ismini belirt"},
#endif

/* printerdrv/output-text.c */
/* en */ {IDCLS_SPECIFY_TEXT_DEVICE_4,    N_("Specify printer text output device for printer #4")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_TEXT_DEVICE_4_DA, ""},  /* fuzzy */
/* de */ {IDCLS_SPECIFY_TEXT_DEVICE_4_DE, "Drucker #4 Gerat fur Textausgabe definieren"},
/* fr */ {IDCLS_SPECIFY_TEXT_DEVICE_4_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_TEXT_DEVICE_4_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SPECIFY_TEXT_DEVICE_4_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_SPECIFY_TEXT_DEVICE_4_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_TEXT_DEVICE_4_NL, "Geef het tekst uitvoer apparaat voor printer #4"},
/* pl */ {IDCLS_SPECIFY_TEXT_DEVICE_4_PL, "Okre��l urz�}dzenie wyj��cia tekstowego drukarki #4"},
/* ru */ {IDCLS_SPECIFY_TEXT_DEVICE_4_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_TEXT_DEVICE_4_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_SPECIFY_TEXT_DEVICE_4_TR, ""},  /* fuzzy */
#endif

/* printerdrv/output-text.c */
/* en */ {IDCLS_SPECIFY_TEXT_DEVICE_5,    N_("Specify printer text output device for printer #5")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_TEXT_DEVICE_5_DA, ""},  /* fuzzy */
/* de */ {IDCLS_SPECIFY_TEXT_DEVICE_5_DE, "Drucker #5 Gerat fur Textausgabe definieren"},
/* fr */ {IDCLS_SPECIFY_TEXT_DEVICE_5_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_TEXT_DEVICE_5_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SPECIFY_TEXT_DEVICE_5_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_SPECIFY_TEXT_DEVICE_5_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_TEXT_DEVICE_5_NL, "Geef het tekst uitvoer apparaat voor printer #5"},
/* pl */ {IDCLS_SPECIFY_TEXT_DEVICE_5_PL, "Okre��l urz�}dzenie wyj��cia tekstowego drukarki #5"},
/* ru */ {IDCLS_SPECIFY_TEXT_DEVICE_5_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_TEXT_DEVICE_5_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_SPECIFY_TEXT_DEVICE_5_TR, ""},  /* fuzzy */
#endif

/* printerdrv/output-text.c */
/* en */ {IDCLS_SPECIFY_TEXT_USERPORT,    N_("Specify printer text output device for userport printer")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_TEXT_USERPORT_DA, "Angiv printer tekst-uddata enhed for brugerports-printer"},
/* de */ {IDCLS_SPECIFY_TEXT_USERPORT_DE, "IEC Userport Drucker Gerat fur Textausgabe definieren"},
/* fr */ {IDCLS_SPECIFY_TEXT_USERPORT_FR, "Specifier le peripherique de sortie text pour l'imprimante userport"},
/* hu */ {IDCLS_SPECIFY_TEXT_USERPORT_HU, "Adja meg a szovegnyomtato eszkozt a userport nyomtatohoz"},
/* it */ {IDCLS_SPECIFY_TEXT_USERPORT_IT, "Specifica il nome del dispositivo di output testuale di stampa per la stampante su userport"},
/* ko */ {IDCLS_SPECIFY_TEXT_USERPORT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_TEXT_USERPORT_NL, "Geef het tekst uitvoer apparaat voor de userport printer"},
/* pl */ {IDCLS_SPECIFY_TEXT_USERPORT_PL, "Okre��l urz�}dzenie wyj��cia tekstu dla drukarki w userporcie"},
/* ru */ {IDCLS_SPECIFY_TEXT_USERPORT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_TEXT_USERPORT_SV, "Ange skrivartextutenhet for anvandarportsskrivare"},
/* tr */ {IDCLS_SPECIFY_TEXT_USERPORT_TR, "Userport yazycysy icin metin cykty aygyty yazycysy belirt"},
#endif

/* raster/raster-cmdline-options.c */
/* en */ {IDCLS_ENABLE_VIDEO_CACHE,    N_("Enable the video cache")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_VIDEO_CACHE_DA, "Aktiver videocache"},
/* de */ {IDCLS_ENABLE_VIDEO_CACHE_DE, "Video Cache aktivieren"},
/* fr */ {IDCLS_ENABLE_VIDEO_CACHE_FR, "Activer le cache video"},
/* hu */ {IDCLS_ENABLE_VIDEO_CACHE_HU, "Video gyorsitotar engedelyezese"},
/* it */ {IDCLS_ENABLE_VIDEO_CACHE_IT, "Attiva la cache video"},
/* ko */ {IDCLS_ENABLE_VIDEO_CACHE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_VIDEO_CACHE_NL, "Activeer de videocache"},
/* pl */ {IDCLS_ENABLE_VIDEO_CACHE_PL, "W3�}cz cache wideo"},
/* ru */ {IDCLS_ENABLE_VIDEO_CACHE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_VIDEO_CACHE_SV, "Aktivera videocache"},
/* tr */ {IDCLS_ENABLE_VIDEO_CACHE_TR, "Goruntu onbelledini aktif et"},
#endif

/* raster/raster-cmdline-options.c */
/* en */ {IDCLS_DISABLE_VIDEO_CACHE,    N_("Disable the video cache")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_VIDEO_CACHE_DA, "Deaktiver videocache"},
/* de */ {IDCLS_DISABLE_VIDEO_CACHE_DE, "Video Cache deaktivieren"},
/* fr */ {IDCLS_DISABLE_VIDEO_CACHE_FR, "Desactiver le cache video"},
/* hu */ {IDCLS_DISABLE_VIDEO_CACHE_HU, "Video gyorsitotar tiltasa"},
/* it */ {IDCLS_DISABLE_VIDEO_CACHE_IT, "Disattiva la cache video"},
/* ko */ {IDCLS_DISABLE_VIDEO_CACHE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_VIDEO_CACHE_NL, "De videocache uitschakelen"},
/* pl */ {IDCLS_DISABLE_VIDEO_CACHE_PL, "Wy3acz cache wideo"},
/* ru */ {IDCLS_DISABLE_VIDEO_CACHE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_VIDEO_CACHE_SV, "Inaktivera videocache"},
/* tr */ {IDCLS_DISABLE_VIDEO_CACHE_TR, "Goruntu onbelledini pasiflettir"},
#endif

#ifdef HAVE_RS232
/* rs232drv/rs232drv.c */
/* en */ {IDCLS_SPECIFY_RS232_1_NAME,    N_("Specify name of first RS232 device")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RS232_1_NAME_DA, "Angiv navn pa forste RS232-enhed"},
/* de */ {IDCLS_SPECIFY_RS232_1_NAME_DE, "Name fur erstes RS232 Gerat definieren"},
/* fr */ {IDCLS_SPECIFY_RS232_1_NAME_FR, "Specifier le nom du 1er peripherique RS232"},
/* hu */ {IDCLS_SPECIFY_RS232_1_NAME_HU, "Adja meg az elso RS232-es eszkoz nevet"},
/* it */ {IDCLS_SPECIFY_RS232_1_NAME_IT, "Specifica il nome della prima RS232"},
/* ko */ {IDCLS_SPECIFY_RS232_1_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RS232_1_NAME_NL, "Geef de naam van het eerste RS232 apparaat"},
/* pl */ {IDCLS_SPECIFY_RS232_1_NAME_PL, "Okre��l nazwe pierwszego urz�}dzenia RS232"},
/* ru */ {IDCLS_SPECIFY_RS232_1_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RS232_1_NAME_SV, "Ange namn pa forsta RS232-enheten"},
/* tr */ {IDCLS_SPECIFY_RS232_1_NAME_TR, "Ylk RS232 aygytynyn ismini belirt"},
#endif

/* rs232drv/rs232drv.c */
/* en */ {IDCLS_SPECIFY_RS232_2_NAME,    N_("Specify name of second RS232 device")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RS232_2_NAME_DA, "Angiv navn pa anden RS232-enhed"},
/* de */ {IDCLS_SPECIFY_RS232_2_NAME_DE, "Name fur zweites RS232 Gerat definieren"},
/* fr */ {IDCLS_SPECIFY_RS232_2_NAME_FR, "Specifier le nom du 2e peripherique RS232"},
/* hu */ {IDCLS_SPECIFY_RS232_2_NAME_HU, "Adja meg a masodik RS232-es eszkoz nevet"},
/* it */ {IDCLS_SPECIFY_RS232_2_NAME_IT, "Specifica il nome della seconda RS232"},
/* ko */ {IDCLS_SPECIFY_RS232_2_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RS232_2_NAME_NL, "Geef de naam van het tweede RS232 apparaat"},
/* pl */ {IDCLS_SPECIFY_RS232_2_NAME_PL, "Okre��l nazwe drugiego urz�}dzenia RS232"},
/* ru */ {IDCLS_SPECIFY_RS232_2_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RS232_2_NAME_SV, "Ange namn pa andra RS232-enheten"},
/* tr */ {IDCLS_SPECIFY_RS232_2_NAME_TR, "Ykinci RS232 aygytynyn ismini belirt"},
#endif

/* rs232drv/rs232drv.c */
/* en */ {IDCLS_SPECIFY_RS232_3_NAME,    N_("Specify name of third RS232 device")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RS232_3_NAME_DA, "Angiv navn pa tredje RS232-enhed"},
/* de */ {IDCLS_SPECIFY_RS232_3_NAME_DE, "Name fur drittes RS232 Gerat definieren"},
/* fr */ {IDCLS_SPECIFY_RS232_3_NAME_FR, "Specifier le nom du 3e peripherique RS232"},
/* hu */ {IDCLS_SPECIFY_RS232_3_NAME_HU, "Adja meg a harmadik RS232-es eszkoz nevet"},
/* it */ {IDCLS_SPECIFY_RS232_3_NAME_IT, "Specifica il nome della terza RS232"},
/* ko */ {IDCLS_SPECIFY_RS232_3_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RS232_3_NAME_NL, "Geef de naam van het derde RS232 apparaat"},
/* pl */ {IDCLS_SPECIFY_RS232_3_NAME_PL, "Okre��l nazwe trzeciego urz�}dzenia RS232"},
/* ru */ {IDCLS_SPECIFY_RS232_3_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RS232_3_NAME_SV, "Ange namn pa tredje RS232-enheten"},
/* tr */ {IDCLS_SPECIFY_RS232_3_NAME_TR, "Ucuncu RS232 aygytynyn ismini belirt"},
#endif

/* rs232drv/rs232drv.c */
/* en */ {IDCLS_SPECIFY_RS232_4_NAME,    N_("Specify name of fourth RS232 device")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RS232_4_NAME_DA, "Angiv navn pa fjerde RS232-enhed"},
/* de */ {IDCLS_SPECIFY_RS232_4_NAME_DE, "Name fur viertes RS232 Gerat definieren"},
/* fr */ {IDCLS_SPECIFY_RS232_4_NAME_FR, "Specifier le nom du 4e peripherique RS232"},
/* hu */ {IDCLS_SPECIFY_RS232_4_NAME_HU, "Adja meg a negyedik RS232-es eszkoz nevet"},
/* it */ {IDCLS_SPECIFY_RS232_4_NAME_IT, "Specifica il nome della quarta RS232"},
/* ko */ {IDCLS_SPECIFY_RS232_4_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RS232_4_NAME_NL, "Geef de naam van het vierde RS232 apparaat"},
/* pl */ {IDCLS_SPECIFY_RS232_4_NAME_PL, "Okre��l nazwe czwartego urz�}dzenia RS232"},
/* ru */ {IDCLS_SPECIFY_RS232_4_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RS232_4_NAME_SV, "Ange namn pa fjarde RS232-enheten"},
/* tr */ {IDCLS_SPECIFY_RS232_4_NAME_TR, "Dorduncu RS232 aygytynyn ismini belirt"},
#endif
#endif

/* rs232drv/rsuser.c */
/* en */ {IDCLS_ENABLE_RS232_USERPORT,    N_("Enable RS232 userport emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_RS232_USERPORT_DA, "Aktiver RS232-emulering pa brugerporten"},
/* de */ {IDCLS_ENABLE_RS232_USERPORT_DE, "RS232 Userport Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_RS232_USERPORT_FR, "Activer l'emulation de peripherique RS232 userport"},
/* hu */ {IDCLS_ENABLE_RS232_USERPORT_HU, "RS232 userport emulacio engedelyezese"},
/* it */ {IDCLS_ENABLE_RS232_USERPORT_IT, "Attiva l'emulazione della RS232 su userport"},
/* ko */ {IDCLS_ENABLE_RS232_USERPORT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_RS232_USERPORT_NL, "Activeer RS232 userportemulatie"},
/* pl */ {IDCLS_ENABLE_RS232_USERPORT_PL, "W3�}cz emulacje userportu RS232"},
/* ru */ {IDCLS_ENABLE_RS232_USERPORT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_RS232_USERPORT_SV, "Aktivera RS232-emulering pa anvandarporten"},
/* tr */ {IDCLS_ENABLE_RS232_USERPORT_TR, "RS232 userport emulasyonunu aktif et"},
#endif

/* rs232drv/rsuser.c */
/* en */ {IDCLS_DISABLE_RS232_USERPORT,    N_("Disable RS232 userport emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_RS232_USERPORT_DA, "Deaktiver RS232-emulering pa brugerporten"},
/* de */ {IDCLS_DISABLE_RS232_USERPORT_DE, "RS232 Userport Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_RS232_USERPORT_FR, "Desactiver l'emulation de peripherique RS232 userport"},
/* hu */ {IDCLS_DISABLE_RS232_USERPORT_HU, "RS232 userport emulacio tiltasa"},
/* it */ {IDCLS_DISABLE_RS232_USERPORT_IT, "Disattiva l'emulazione della RS232 su userport"},
/* ko */ {IDCLS_DISABLE_RS232_USERPORT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_RS232_USERPORT_NL, "RS232 userportemulatie uitschakelen"},
/* pl */ {IDCLS_DISABLE_RS232_USERPORT_PL, "Wy3�}cz emulacje userportu RS232"},
/* ru */ {IDCLS_DISABLE_RS232_USERPORT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_RS232_USERPORT_SV, "Inaktivera RS232-emulering pa anvandarporten"},
/* tr */ {IDCLS_DISABLE_RS232_USERPORT_TR, "RS232 userport emulasyonunu pasiflettir"},
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
/* pl */ {IDCLS_P_BAUD_PL, "<bod>"},
/* ru */ {IDCLS_P_BAUD_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_BAUD_SV, "<baud>"},
/* tr */ {IDCLS_P_BAUD_TR, "<baud>"},
#endif

/* rs232drv/rsuser.c */
/* en */ {IDCLS_SET_BAUD_RS232_USERPORT,    N_("Set the baud rate of the RS232 userport emulation.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_BAUD_RS232_USERPORT_DA, "Angiv baudhastighet for RS232-emuleringen pa brugerporten."},
/* de */ {IDCLS_SET_BAUD_RS232_USERPORT_DE, "Baudrate fur RS232 Userport Emulation setzen"},
/* fr */ {IDCLS_SET_BAUD_RS232_USERPORT_FR, "Specifiez la vitesse en baud du peripherique RS232 userport"},
/* hu */ {IDCLS_SET_BAUD_RS232_USERPORT_HU, "Bitrata megadasa az RS232 userport emulaciohoz."},
/* it */ {IDCLS_SET_BAUD_RS232_USERPORT_IT, "Imposta la velocita della RS232 su userport (in baud)"},
/* ko */ {IDCLS_SET_BAUD_RS232_USERPORT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_BAUD_RS232_USERPORT_NL, "Zet de baud rate van de RS232 userport emulatie."},
/* pl */ {IDCLS_SET_BAUD_RS232_USERPORT_PL, "Okre��l predko��a transmisji emulacji userportu RS232."},
/* ru */ {IDCLS_SET_BAUD_RS232_USERPORT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_BAUD_RS232_USERPORT_SV, "Ange baudhastighet for RS232-emuleringen pa anvandarporten."},
/* tr */ {IDCLS_SET_BAUD_RS232_USERPORT_TR, "RS232 userport emulasyonunun baud rate'ini ayarla."},
#endif

/* rs232drv/rsuser.c */
/* en */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT,    N_("Specify VICE RS232 device for userport")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_DA, "Angiv VICE RS232-enhed for brugerporten"},
/* de */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_DE, "VICE RS232 Gerat fur Userport definieren"},
/* fr */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_FR, "Specifier un peripherique VICE RS232 pour le userport"},
/* hu */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_HU, "VICE RS232-es userport eszkoz megadasa"},
/* it */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_IT, "Specifica il dispositivo RS232 di VICE per userport"},
/* ko */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_NL, "Geef VICE RS232 apparaat voor userport"},
/* pl */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_PL, "Okre��l urz�}dzenie VICE RS232 w userporcie"},
/* ru */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_SV, "Ange VICE RS232-enhet for anvandarporten"},
/* tr */ {IDCLS_SPECIFY_RS232_DEVICE_USERPORT_TR, "Userport icin VICE RS232 aygytyny belirt"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_ENABLE_IEC_4,    N_("Enable IEC device emulation for device #4")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEC_4_DA, "Aktiver IEC-enhedsemulering for enhed #4"},
/* de */ {IDCLS_ENABLE_IEC_4_DE, "IEC Gerate Emulation fur Gerat #4 aktivieren"},
/* fr */ {IDCLS_ENABLE_IEC_4_FR, "Activer l'emulation IEC pour le peripherique #4"},
/* hu */ {IDCLS_ENABLE_IEC_4_HU, "IEC eszkoz #4 emulaciojanak engedelyezese"},
/* it */ {IDCLS_ENABLE_IEC_4_IT, "Attiva emulazione IEC per la periferica #4"},
/* ko */ {IDCLS_ENABLE_IEC_4_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEC_4_NL, "Activeer IEC apparaat emulatie voor apparaat #4"},
/* pl */ {IDCLS_ENABLE_IEC_4_PL, "W3�}cz emulacje IEC urz�}dzenia #4"},
/* ru */ {IDCLS_ENABLE_IEC_4_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEC_4_SV, "Aktivera IEC-enhetsemulering for enhet 4"},
/* tr */ {IDCLS_ENABLE_IEC_4_TR, "Aygyt #4 icin IEC aygyt emulasyonunu aktif et"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_DISABLE_IEC_4,    N_("Disable IEC device emulation for device #4")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEC_4_DA, "Deaktiver IEC-enhedsemulering for enhed #4"},
/* de */ {IDCLS_DISABLE_IEC_4_DE, "IEC Gerate Emulation fur Gerat #4 deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEC_4_FR, "Desactiver l'emulation IEC pour le peripherique #4"},
/* hu */ {IDCLS_DISABLE_IEC_4_HU, "IEC eszkoz #4 emulaciojanak tiltasa"},
/* it */ {IDCLS_DISABLE_IEC_4_IT, "Disattiva emulazione IEC per la periferica #4"},
/* ko */ {IDCLS_DISABLE_IEC_4_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEC_4_NL, "IEC apparaat emulatie voor apparaat #4 uitschakelen"},
/* pl */ {IDCLS_DISABLE_IEC_4_PL, "Wy3�}cz emulacje urz�}dzenia IEC dla urz�}dzenia #4"},
/* ru */ {IDCLS_DISABLE_IEC_4_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEC_4_SV, "Inaktivera IEC-enhetsemulering for enhet 4"},
/* tr */ {IDCLS_DISABLE_IEC_4_TR, "Aygyt #4 icin IEC aygyt emulasyonunu pasiflettir"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_ENABLE_IEC_5,    N_("Enable IEC device emulation for device #5")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEC_5_DA, "Aktiver IEC-enhedsemulering for enhed #5"},
/* de */ {IDCLS_ENABLE_IEC_5_DE, "IEC Gerate Emulation fur Gerat #5 aktivieren"},
/* fr */ {IDCLS_ENABLE_IEC_5_FR, "Activer l'emulation IEC pour le peripherique #5"},
/* hu */ {IDCLS_ENABLE_IEC_5_HU, "IEC eszkoz #5 emulaciojanak engedelyezese"},
/* it */ {IDCLS_ENABLE_IEC_5_IT, "Attiva emulazione IEC per la periferica #5"},
/* ko */ {IDCLS_ENABLE_IEC_5_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEC_5_NL, "Activeer IEC apparaat emulatie voor apparaat #5"},
/* pl */ {IDCLS_ENABLE_IEC_5_PL, "W3�}cz emulacje IEC urz�}dzenia #5"},
/* ru */ {IDCLS_ENABLE_IEC_5_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEC_5_SV, "Aktivera IEC-enhetsemulering for enhet 5"},
/* tr */ {IDCLS_ENABLE_IEC_5_TR, "Aygyt #5 icin IEC aygyt emulasyonunu aktif et"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_DISABLE_IEC_5,    N_("Disable IEC device emulation for device #5")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEC_5_DA, "Deaktiver IEC-enhedsemulering for enhed #5"},
/* de */ {IDCLS_DISABLE_IEC_5_DE, "IEC Gerate Emulation fur Gerat #5 deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEC_5_FR, "Desactiver l'emulation IEC pour le peripherique #5"},
/* hu */ {IDCLS_DISABLE_IEC_5_HU, "IEC eszkoz #5 emulaciojanak tiltasa"},
/* it */ {IDCLS_DISABLE_IEC_5_IT, "Disattiva emulazione IEC per la periferica #5"},
/* ko */ {IDCLS_DISABLE_IEC_5_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEC_5_NL, "IEC apparaat emulatie voor apparaat #5 uitschakelen"},
/* pl */ {IDCLS_DISABLE_IEC_5_PL, "Wy3�}cz emulacje urz�}dzenia IEC dla urz�}dzenia #5"},
/* ru */ {IDCLS_DISABLE_IEC_5_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEC_5_SV, "Inaktivera IEC-enhetsemulering for enhet 5"},
/* tr */ {IDCLS_DISABLE_IEC_5_TR, "Aygyt #5 icin IEC aygyt emulasyonunu pasiflettir"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_ENABLE_IEC_8,    N_("Enable IEC device emulation for device #8")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEC_8_DA, "Aktiver IEC-enhedsemulering for enhed #8"},
/* de */ {IDCLS_ENABLE_IEC_8_DE, "IEC Gerate Emulation fur Gerat #8 aktivieren"},
/* fr */ {IDCLS_ENABLE_IEC_8_FR, "Activer l'emulation IEC pour le lecteur #8"},
/* hu */ {IDCLS_ENABLE_IEC_8_HU, "IEC eszkoz #8 emulaciojanak engedelyezese"},
/* it */ {IDCLS_ENABLE_IEC_8_IT, "Attiva emulazione IEC per la periferica #8"},
/* ko */ {IDCLS_ENABLE_IEC_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEC_8_NL, "Activeer IEC apparaat emulatie voor apparaat #8"},
/* pl */ {IDCLS_ENABLE_IEC_8_PL, "W3�}cz emulacje IEC urz�}dzenia #8"},
/* ru */ {IDCLS_ENABLE_IEC_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEC_8_SV, "Aktivera IEC-enhetsemulering for enhet 8"},
/* tr */ {IDCLS_ENABLE_IEC_8_TR, "Aygyt #8 icin IEC aygyt emulasyonunu aktif et"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_DISABLE_IEC_8,    N_("Disable IEC device emulation for device #8")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEC_8_DA, "Deaktiver IEC-enhedsemulering for enhed #8"},
/* de */ {IDCLS_DISABLE_IEC_8_DE, "IEC Gerate Emulation fur Gerat #8 deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEC_8_FR, "Desactiver l'emulation IEC pour le lecteur #8"},
/* hu */ {IDCLS_DISABLE_IEC_8_HU, "IEC eszkoz #8 emulaciojanak tiltasa"},
/* it */ {IDCLS_DISABLE_IEC_8_IT, "Disattiva emulazione IEC per la periferica #8"},
/* ko */ {IDCLS_DISABLE_IEC_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEC_8_NL, "IEC apparaat emulatie voor apparaat #8 uitschakelen"},
/* pl */ {IDCLS_DISABLE_IEC_8_PL, "Wy3�}cz emulacje urz�}dzenia IEC dla urz�}dzenia #8"},
/* ru */ {IDCLS_DISABLE_IEC_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEC_8_SV, "Inaktivera IEC-enhetsemulering for enhet 8"},
/* tr */ {IDCLS_DISABLE_IEC_8_TR, "Aygyt #8 icin IEC aygyt emulasyonunu pasiflettir"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_ENABLE_IEC_9,    N_("Enable IEC device emulation for device #9")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEC_9_DA, "Aktiver IEC-enhedsemulering for enhed #9"},
/* de */ {IDCLS_ENABLE_IEC_9_DE, "IEC Gerate Emulation fur Gerat #9 aktivieren"},
/* fr */ {IDCLS_ENABLE_IEC_9_FR, "Activer l'emulation IEC pour le lecteur #9"},
/* hu */ {IDCLS_ENABLE_IEC_9_HU, "IEC eszkoz #9 emulaciojanak engedelyezese"},
/* it */ {IDCLS_ENABLE_IEC_9_IT, "Attiva emulazione IEC per la periferica #9"},
/* ko */ {IDCLS_ENABLE_IEC_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEC_9_NL, "Activeer IEC apparaat emulatie voor apparaat #9"},
/* pl */ {IDCLS_ENABLE_IEC_9_PL, "W3�}cz emulacje IEC urz�}dzenia #9"},
/* ru */ {IDCLS_ENABLE_IEC_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEC_9_SV, "Aktivera IEC-enhetsemulering for enhet 9"},
/* tr */ {IDCLS_ENABLE_IEC_9_TR, "Aygyt #9 icin IEC aygyt emulasyonunu aktif et"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_DISABLE_IEC_9,    N_("Disable IEC device emulation for device #9")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEC_9_DA, "Deaktiver IEC-enhedsemulering for enhed #9"},
/* de */ {IDCLS_DISABLE_IEC_9_DE, "IEC Gerate Emulation fur Gerat #9 deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEC_9_FR, "Desactiver l'emulation IEC pour le lecteur #9"},
/* hu */ {IDCLS_DISABLE_IEC_9_HU, "IEC eszkoz #9 emulaciojanak tiltasa"},
/* it */ {IDCLS_DISABLE_IEC_9_IT, "Disattiva emulazione IEC per la periferica #9"},
/* ko */ {IDCLS_DISABLE_IEC_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEC_9_NL, "IEC apparaat emulatie voor apparaat #9 uitschakelen"},
/* pl */ {IDCLS_DISABLE_IEC_9_PL, "Wy3�}cz emulacje urz�}dzenia IEC dla urz�}dzenia #9"},
/* ru */ {IDCLS_DISABLE_IEC_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEC_9_SV, "Inaktivera IEC-enhetsemulering for enhet 9"},
/* tr */ {IDCLS_DISABLE_IEC_9_TR, "Aygyt #9 icin IEC aygyt emulasyonunu pasiflettir"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_ENABLE_IEC_10,    N_("Enable IEC device emulation for device #10")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEC_10_DA, "Aktiver IEC-enhedsemulering for enhed #10"},
/* de */ {IDCLS_ENABLE_IEC_10_DE, "IEC Gerate Emulation fur Gerat #10 aktivieren"},
/* fr */ {IDCLS_ENABLE_IEC_10_FR, "Activer l'emulation IEC pour le lecteur #10"},
/* hu */ {IDCLS_ENABLE_IEC_10_HU, "IEC eszkoz #10 emulaciojanak engedelyezese"},
/* it */ {IDCLS_ENABLE_IEC_10_IT, "Attiva emulazione IEC per la periferica #10"},
/* ko */ {IDCLS_ENABLE_IEC_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEC_10_NL, "Activeer IEC apparaat emulatie voor apparaat #10"},
/* pl */ {IDCLS_ENABLE_IEC_10_PL, "W3�}cz emulacje IEC urz�}dzenia #10"},
/* ru */ {IDCLS_ENABLE_IEC_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEC_10_SV, "Aktivera IEC-enhetsemulering for enhet 10"},
/* tr */ {IDCLS_ENABLE_IEC_10_TR, "Aygyt #10 icin IEC aygyt emulasyonunu aktif et"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_DISABLE_IEC_10,    N_("Disable IEC device emulation for device #10")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEC_10_DA, "Deaktiver IEC-enhedsemulering for enhed #10"},
/* de */ {IDCLS_DISABLE_IEC_10_DE, "IEC Gerate Emulation fur Gerat #10 deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEC_10_FR, "Desactiver l'emulation IEC pour le lecteur #10"},
/* hu */ {IDCLS_DISABLE_IEC_10_HU, "IEC eszkoz #10 emulaciojanak tiltasa"},
/* it */ {IDCLS_DISABLE_IEC_10_IT, "Disattiva emulazione IEC per la periferica #10"},
/* ko */ {IDCLS_DISABLE_IEC_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEC_10_NL, "IEC apparaat emulatie voor apparaat #10 uitschakelen"},
/* pl */ {IDCLS_DISABLE_IEC_10_PL, "Wy3�}cz emulacje urz�}dzenia IEC dla urz�}dzenia #10"},
/* ru */ {IDCLS_DISABLE_IEC_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEC_10_SV, "Inaktivera IEC-enhetsemulering for enhet 10"},
/* tr */ {IDCLS_DISABLE_IEC_10_TR, "Aygyt #10 icin IEC aygyt emulasyonunu pasiflettir"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_ENABLE_IEC_11,    N_("Enable IEC device emulation for device #11")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_IEC_11_DA, "Aktiver IEC-enhedsemulering for enhed #11"},
/* de */ {IDCLS_ENABLE_IEC_11_DE, "IEC Gerate Emulation fur Gerat #11 aktivieren"},
/* fr */ {IDCLS_ENABLE_IEC_11_FR, "Activer l'emulation IEC pour le lecteur #11"},
/* hu */ {IDCLS_ENABLE_IEC_11_HU, "IEC eszkoz #11 emulaciojanak engedelyezese"},
/* it */ {IDCLS_ENABLE_IEC_11_IT, "Attiva emulazione IEC per la periferica #11"},
/* ko */ {IDCLS_ENABLE_IEC_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_IEC_11_NL, "Activeer IEC apparaat emulatie voor apparaat #11"},
/* pl */ {IDCLS_ENABLE_IEC_11_PL, "W3�}cz emulacje IEC urz�}dzenia #11"},
/* ru */ {IDCLS_ENABLE_IEC_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_IEC_11_SV, "Aktivera IEC-enhetsemulering for enhet 11"},
/* tr */ {IDCLS_ENABLE_IEC_11_TR, "Aygyt #11 icin IEC aygyt emulasyonunu aktif et"},
#endif

/* serial/serial-iec-device.c */
/* en */ {IDCLS_DISABLE_IEC_11,    N_("Disable IEC device emulation for device #11")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_IEC_11_DA, "Deaktiver IEC-enhedsemulering for enhed #11"},
/* de */ {IDCLS_DISABLE_IEC_11_DE, "IEC Gerate Emulation fur Gerat #11 deaktivieren"},
/* fr */ {IDCLS_DISABLE_IEC_11_FR, "Desactiver l'emulation IEC pour le lecteur #11"},
/* hu */ {IDCLS_DISABLE_IEC_11_HU, "IEC eszkoz #11 emulaciojanak tiltasa"},
/* it */ {IDCLS_DISABLE_IEC_11_IT, "Disattiva emulazione IEC per la periferica #11"},
/* ko */ {IDCLS_DISABLE_IEC_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_IEC_11_NL, "IEC apparaat emulatie voor apparaat #11 uitschakelen"},
/* pl */ {IDCLS_DISABLE_IEC_11_PL, "Wy3�}cz emulacje urz�}dzenia IEC dla urz�}dzenia #11"},
/* ru */ {IDCLS_DISABLE_IEC_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_IEC_11_SV, "Inaktivera IEC-enhetsemulering for enhet 11"},
/* tr */ {IDCLS_DISABLE_IEC_11_TR, "Aygyt #11 icin IEC aygyt emulasyonunu pasiflettir"},
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
/* pl */ {IDCLS_P_ENGINE_MODEL_PL, "<silnik i model>"},
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
/* pl */ {IDCLS_FASTSID_ENGINE_MODEL_PL, "0: FastSID 6581, 1: FastSID 8580"},
/* ru */ {IDCLS_FASTSID_ENGINE_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_FASTSID_ENGINE_MODEL_SV, "0: FastSID 6581, 1: FastSID 8580"},
/* tr */ {IDCLS_FASTSID_ENGINE_MODEL_TR, "0: FastSID 6581, 1: FastSID 8580"},
#endif

#ifdef HAVE_RESID
/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_RESID_ENGINE_MODEL,    N_("256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digiboost")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RESID_ENGINE_MODEL_DA, "256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digitalforstarkning"},
/* de */ {IDCLS_RESID_ENGINE_MODEL_DE, "256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digiboost"},
/* fr */ {IDCLS_RESID_ENGINE_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_RESID_ENGINE_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_RESID_ENGINE_MODEL_IT, "256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digiboost"},
/* ko */ {IDCLS_RESID_ENGINE_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_RESID_ENGINE_MODEL_NL, "256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digiboost"},
/* pl */ {IDCLS_RESID_ENGINE_MODEL_PL, "256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digiboost"},
/* ru */ {IDCLS_RESID_ENGINE_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RESID_ENGINE_MODEL_SV, "256: ReSID 6581, 257: ReSID 8580, 258: ReSID 8580 + digiforstarkning"},
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
/* pl */ {IDCLS_RESIDDTV_ENGINE_MODEL_PL, "260: DTVSID"},
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
/* pl */ {IDCLS_CATWEASELMKIII_ENGINE_MODEL_PL, "512: Catweasel"},
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
/* pl */ {IDCLS_HARDSID_ENGINE_MODEL_PL, "768: HardSID"},
/* ru */ {IDCLS_HARDSID_ENGINE_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_HARDSID_ENGINE_MODEL_SV, "768: HardSID"},
/* tr */ {IDCLS_HARDSID_ENGINE_MODEL_TR, "768: HardSID"},
#endif
#endif

#ifdef HAVE_PARSID
/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_PARSID_ENGINE_MODEL,    N_("1024: ParSID in par port 1, 1280: ParSID in par port 2, 1536: ParSID in par port 3")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PARSID_ENGINE_MODEL_DA, "1024: ParSID pa port 1, 1280: ParSID pa port 2, 1536: ParSID pa port 3"},
/* de */ {IDCLS_PARSID_ENGINE_MODEL_DE, "1024: ParSID in par port 1, 1280: ParSID in par port 2, 1536: ParSID in par port 3"},
/* fr */ {IDCLS_PARSID_ENGINE_MODEL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_PARSID_ENGINE_MODEL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_PARSID_ENGINE_MODEL_IT, "1024: ParSID in par port 1, 1280: ParSID in par port 2, 1536: ParSID in par port 3"},
/* ko */ {IDCLS_PARSID_ENGINE_MODEL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PARSID_ENGINE_MODEL_NL, "1024: ParSID in par port 1, 1280: ParSID in par port 2, 1536: ParSID in par port 3"},
/* pl */ {IDCLS_PARSID_ENGINE_MODEL_PL, "1024: ParSID in porcie par 1, 1280: ParSID w porcie par 2, 1536: ParSID in porcie par 3"},
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
/* pl */ {IDCLS_RESIDFP_ENGINE_MODEL_PL, "1800: ReSID-FP 6581R3 4885, 1801: ReSID-FP 6581R3 0486S, 1802: ReSID-FP 6581R3 3984, 1803: ReSID-FP 6581R4 AR 3789, 1804: ReSID-FP 6581R3 4485, 1805: ReSID-FP 6581R4 1986S, 1808: ReSID-FP 8580R5 3691, 1809: ReSID-FP 8580R5 3691 + digiboost, 1810: ReSID-FP 8580R5 1489, 1811: ReSID-FP 8580R5 1489D"},
/* ru */ {IDCLS_RESIDFP_ENGINE_MODEL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RESIDFP_ENGINE_MODEL_SV, "1800: ReSID-FP 6581R3 4885, 1801: ReSID-FP 6581R3 0486S, 1802: ReSID-FP 6581R3 3984, 1803: ReSID-FP 6581R4 AR 3789, 1804: ReSID-FP 6581R3 4485, 1805: ReSID-FP 6581R4 1986S, 1808: ReSID-FP 8580R5 3691, 1809: ReSID-FP 8580R5 3691 + digiforstarkning, 1810: ReSID-FP 8580R5 1489, 1811: ReSID-FP 8580R5 1489 + digiforstarkning"},
/* tr */ {IDCLS_RESIDFP_ENGINE_MODEL_TR, "1800: ReSID-FP 6581R3 4885, 1801: ReSID-FP 6581R3 0486S, 1802: ReSID-FP 6581R3 3984, 1803: ReSID-FP 6581R4 AR 3789, 1804: ReSID-FP 6581R3 4485, 1805: ReSID-FP 6581R4 1986S, 1808: ReSID-FP 8580R5 3691, 1809: ReSID-FP 8580R5 3691 + digiboost, 1810: ReSID-FP 8580R5 1489, 1811: ReSID-FP 8580R5 1489D"},
#endif
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_ENABLE_SECOND_SID,    N_("Enable second SID")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SECOND_SID_DA, "Aktiver sekundar SID"},
/* de */ {IDCLS_ENABLE_SECOND_SID_DE, "Zweiten SID aktivieren"},
/* fr */ {IDCLS_ENABLE_SECOND_SID_FR, "Activer le second SID"},
/* hu */ {IDCLS_ENABLE_SECOND_SID_HU, "Masodik SID engedelyezese"},
/* it */ {IDCLS_ENABLE_SECOND_SID_IT, "Attiva secondo SID"},
/* ko */ {IDCLS_ENABLE_SECOND_SID_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SECOND_SID_NL, "Activeer stereo SID"},
/* pl */ {IDCLS_ENABLE_SECOND_SID_PL, "W3�}cz drugi SID"},
/* ru */ {IDCLS_ENABLE_SECOND_SID_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SECOND_SID_SV, "Aktivera andra SID"},
/* tr */ {IDCLS_ENABLE_SECOND_SID_TR, "Ykinci SID'i aktif et"},
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
/* pl */ {IDCLS_ENABLE_SIDCART_PL, "W3�}cz kartrid? SID"},
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
/* pl */ {IDCLS_DISABLE_SIDCART_PL, "Wy3�}cz kartrid? SID"},
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
/* ko */ {IDCLS_P_BASE_ADDRESS_KO, "<o��AI?o AO?O>"},
/* nl */ {IDCLS_P_BASE_ADDRESS_NL, "<Basisadres>"},
/* pl */ {IDCLS_P_BASE_ADDRESS_PL, "<Adres bazowy>"},
/* ru */ {IDCLS_P_BASE_ADDRESS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_BASE_ADDRESS_SV, "<Basadress>"},
/* tr */ {IDCLS_P_BASE_ADDRESS_TR, "<Taban adresi>"},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_SID_2_ADDRESS,    N_("Specify base address for 2nd SID")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SID_2_ADDRESS_DA, "Angiv baseadresse for sekundar SID"},
/* de */ {IDCLS_SPECIFY_SID_2_ADDRESS_DE, "Basis Adresse fur zweiten SID definieren"},
/* fr */ {IDCLS_SPECIFY_SID_2_ADDRESS_FR, "Specifier l'adresse de base pour le second SID"},
/* hu */ {IDCLS_SPECIFY_SID_2_ADDRESS_HU, "Adja meg a baziscimet a masodik SID-nek"},
/* it */ {IDCLS_SPECIFY_SID_2_ADDRESS_IT, "Specifica l'indirizzo di base per il secondo SID"},
/* ko */ {IDCLS_SPECIFY_SID_2_ADDRESS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SID_2_ADDRESS_NL, "Geef het basisadres van de 2e SID"},
/* pl */ {IDCLS_SPECIFY_SID_2_ADDRESS_PL, "Okre��l adres bazowy drugiego SID-a"},
/* ru */ {IDCLS_SPECIFY_SID_2_ADDRESS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SID_2_ADDRESS_SV, "Ange basadress for andra SID"},
/* tr */ {IDCLS_SPECIFY_SID_2_ADDRESS_TR, "2nci SID icin taban adresini belirt"},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_ENABLE_SID_FILTERS,    N_("Emulate SID filters")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SID_FILTERS_DA, "Emuler SID-filtre"},
/* de */ {IDCLS_ENABLE_SID_FILTERS_DE, "SID Filter Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_SID_FILTERS_FR, "Emuler les filtres SID"},
/* hu */ {IDCLS_ENABLE_SID_FILTERS_HU, "SID szurok emulacioja"},
/* it */ {IDCLS_ENABLE_SID_FILTERS_IT, "Emula i filtri del SID"},
/* ko */ {IDCLS_ENABLE_SID_FILTERS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SID_FILTERS_NL, "Emuleer SID filters"},
/* pl */ {IDCLS_ENABLE_SID_FILTERS_PL, "Emuluj filtry SID"},
/* ru */ {IDCLS_ENABLE_SID_FILTERS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SID_FILTERS_SV, "Emulera SID-filter"},
/* tr */ {IDCLS_ENABLE_SID_FILTERS_TR, "SID filtrelerini emule et"},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_DISABLE_SID_FILTERS,    N_("Do not emulate SID filters")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SID_FILTERS_DA, "Emuler ikke SID-filtre"},
/* de */ {IDCLS_DISABLE_SID_FILTERS_DE, "SID Filter Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_SID_FILTERS_FR, "Ne pas emuler les filtres SID"},
/* hu */ {IDCLS_DISABLE_SID_FILTERS_HU, "Nem emulalja a SID szuroket"},
/* it */ {IDCLS_DISABLE_SID_FILTERS_IT, "Non emulare i filtri del SID"},
/* ko */ {IDCLS_DISABLE_SID_FILTERS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SID_FILTERS_NL, "SID filters niet emuleren"},
/* pl */ {IDCLS_DISABLE_SID_FILTERS_PL, "Nie emuluj filtrow SID"},
/* ru */ {IDCLS_DISABLE_SID_FILTERS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SID_FILTERS_SV, "Emulera inte SID-filter"},
/* tr */ {IDCLS_DISABLE_SID_FILTERS_TR, "SID filtrelerini emule etme"},
#endif

#ifdef HAVE_RESID
/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_RESID_SAMPLING_METHOD,    N_("reSID sampling method (0: fast, 1: interpolating, 2: resampling, 3: fast resampling)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RESID_SAMPLING_METHOD_DA, "reSID-samplingmetode (0: hurtig, 1: interpolerende, 2: omsampling, 3: hurtig omsampling)"},
/* de */ {IDCLS_RESID_SAMPLING_METHOD_DE, "reSID Sample Methode (0: schnell, 1: interpolierend, 2: resampling, 3: schnelles resampling)"},
/* fr */ {IDCLS_RESID_SAMPLING_METHOD_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_RESID_SAMPLING_METHOD_HU, "reSID mintavetelezesi mod (0: gyors, 1: interpolalo, 2: ujramintavetelezo, 3: gyors ujramintavetelezo)"},
/* it */ {IDCLS_RESID_SAMPLING_METHOD_IT, "Metodo di campionamento del reSID (0: veloce, 1: interpolato, 2: ricampionato 3: ricampionamento veloce)"},
/* ko */ {IDCLS_RESID_SAMPLING_METHOD_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_RESID_SAMPLING_METHOD_NL, "reSID sampling methode (0: snel, 1: interpoleren, 2: resampling, 3: snelle resampling)"},
/* pl */ {IDCLS_RESID_SAMPLING_METHOD_PL, "Metoda samplowania reSID (0: szybkie, 1: z przeplotem, 2: resamplowanie, 3: szybkie resamplowanie)"},
/* ru */ {IDCLS_RESID_SAMPLING_METHOD_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RESID_SAMPLING_METHOD_SV, "reSID-samplingsmetod (0: snabb, 1: interpolerande, 2: omsampling, 3: snabb omsampling)"},
/* tr */ {IDCLS_RESID_SAMPLING_METHOD_TR, "reSID ornekleme metodu (0: hyzly, 1: ara deder bulma, 2: yeniden ornekleme, 3: hyzly yeniden ornekleme)"},
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
/* pl */ {IDCLS_P_PERCENT_PL, "<percent>"},
/* ru */ {IDCLS_P_PERCENT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_PERCENT_SV, "<procent>"},
/* tr */ {IDCLS_P_PERCENT_TR, "<yuzde>"},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_PASSBAND_PERCENTAGE,    N_("reSID resampling passband in percentage of total bandwidth (0 - 90)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PASSBAND_PERCENTAGE_DA, "Pasband for reSID-resampling i procent af total bandbredde (0 - 90)"},
/* de */ {IDCLS_PASSBAND_PERCENTAGE_DE, "reSID Resampling Passband Prozentwert der gesamte Bandbreite (0 - 90)\n(0 - 90, niedrig ist schneller, hoher ist besser)"},
/* fr */ {IDCLS_PASSBAND_PERCENTAGE_FR, "Bande passante pour le resampling reSID en pourcentage de la bande totale (0 - 90)"},
/* hu */ {IDCLS_PASSBAND_PERCENTAGE_HU, "reSID ujramintavetelezesi savnak a teljes savszelessegre vonatkoztatott aranya (0 - 90)"},
/* it */ {IDCLS_PASSBAND_PERCENTAGE_IT, "Banda passante di ricampionamento del reSID in percentuale di quella totale (0 - 90)"},
/* ko */ {IDCLS_PASSBAND_PERCENTAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PASSBAND_PERCENTAGE_NL, "reSID resampling passband in percentage van de totale bandbreedte (0 - 90)"},
/* pl */ {IDCLS_PASSBAND_PERCENTAGE_PL, "Pasmo resamplowania reSID w procentach ca3kowitej przepustowo��ai (0 - 90)"},
/* ru */ {IDCLS_PASSBAND_PERCENTAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PASSBAND_PERCENTAGE_SV, "Passband for reSID-resampling i procent av total bandbredd (0 - 90)"},
/* tr */ {IDCLS_PASSBAND_PERCENTAGE_TR, "reSID yeniden ornekleme passband'inin toplam bant genitlidine yuzdesel orany (0 - 90)"},
#endif

/* sid/sid-cmdline-options.c, vsync.c */
/* en */ {IDCLS_RESID_FILTER_BIAS,    N_("reSID filter bias setting, which can be used to adjust DAC bias in millivolts.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RESID_FILTER_BIAS_DA, "reSID filter biasindstilling, som kan bruges til at justere DAC bias i millivolt."},
/* de */ {IDCLS_RESID_FILTER_BIAS_DE, "reSID Filter Vorspannungseinstellung, welche fur die Anpassung der DAC\nVorspannung in Millivolt benutzt werden kann"},
/* fr */ {IDCLS_RESID_FILTER_BIAS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_RESID_FILTER_BIAS_HU, ""},  /* fuzzy */
/* it */ {IDCLS_RESID_FILTER_BIAS_IT, "Impostazione del bias del filtro del reSID, che puo essere usato per correggere il bias del DAC in millivolt."},
/* ko */ {IDCLS_RESID_FILTER_BIAS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_RESID_FILTER_BIAS_NL, "reSID filter bias instelling, dit kan gebruikt worden om de DAC bias in millivolts aan te passen."},
/* pl */ {IDCLS_RESID_FILTER_BIAS_PL, "Ustawienie filtra reSID, u?ywane do regulacji nastawienia DAC w miliwoltach."},
/* ru */ {IDCLS_RESID_FILTER_BIAS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RESID_FILTER_BIAS_SV, "Bias-installning for reSID-filter, vilket kan anvandas for att justera D/A-bias i millivolt."},
/* tr */ {IDCLS_RESID_FILTER_BIAS_TR, "Millivolt cinsinden DAC meyilini ayarlamak icin kullanylabilen reSID filtresi meyil ayary."},
#endif

/* sid/sid-cmdline-options.c */
/* en */ {IDCLS_RESID_GAIN_PERCENTAGE,    N_("reSID gain in percent (90 - 100)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RESID_GAIN_PERCENTAGE_DA, "Gain for reSID i procent (90 - 100)"},
/* de */ {IDCLS_RESID_GAIN_PERCENTAGE_DE, "reSID Gain in Prozent (90 - 100)"},
/* fr */ {IDCLS_RESID_GAIN_PERCENTAGE_FR, "Gain reSID en pourcent (90 - 100)"},
/* hu */ {IDCLS_RESID_GAIN_PERCENTAGE_HU, "reSID szazalekos erosites (90 - 100)"},
/* it */ {IDCLS_RESID_GAIN_PERCENTAGE_IT, "Guadagno del reSID in percentuale (90 - 100)"},
/* ko */ {IDCLS_RESID_GAIN_PERCENTAGE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_RESID_GAIN_PERCENTAGE_NL, "reSID versterking procent (90 - 100)"},
/* pl */ {IDCLS_RESID_GAIN_PERCENTAGE_PL, "Wzmocnienie reSID-a w procentach (90 - 100)"},
/* ru */ {IDCLS_RESID_GAIN_PERCENTAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RESID_GAIN_PERCENTAGE_SV, "Gain for reSID i procent (90 - 100)"},
/* tr */ {IDCLS_RESID_GAIN_PERCENTAGE_TR, "reSID gain yuzdesi (90 - 100)"},
#endif
#endif

/* vdc/vdc-cmdline-options.c, crtc/crtc-cmdline-options.c */
/* en */ {IDCLS_ENABLE_STRETCH_VERTICAL,    N_("Enable additional vertical stretching.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_STRETCH_VERTICAL_DA, ""},  /* fuzzy */
/* de */ {IDCLS_ENABLE_STRETCH_VERTICAL_DE, "Aktiviere zusatzliche Vertikalstreckung."},
/* fr */ {IDCLS_ENABLE_STRETCH_VERTICAL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_STRETCH_VERTICAL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_STRETCH_VERTICAL_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_ENABLE_STRETCH_VERTICAL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_STRETCH_VERTICAL_NL, ""},  /* fuzzy */
/* pl */ {IDCLS_ENABLE_STRETCH_VERTICAL_PL, "W3�}cz dodatkowe rozci�}ganie w pionie"},
/* ru */ {IDCLS_ENABLE_STRETCH_VERTICAL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_STRETCH_VERTICAL_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_ENABLE_STRETCH_VERTICAL_TR, ""},  /* fuzzy */
#endif

/* vdc/vdc-cmdline-options.c, crtc/crtc-cmdline-options.c */
/* en */ {IDCLS_DISABLE_STRETCH_VERTICAL,    N_("Disable additional vertical stretching.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_STRETCH_VERTICAL_DA, ""},  /* fuzzy */
/* de */ {IDCLS_DISABLE_STRETCH_VERTICAL_DE, "Deaktiviere zusatzliche Vertikalstreckung."},
/* fr */ {IDCLS_DISABLE_STRETCH_VERTICAL_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_STRETCH_VERTICAL_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_STRETCH_VERTICAL_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_DISABLE_STRETCH_VERTICAL_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_STRETCH_VERTICAL_NL, ""},  /* fuzzy */
/* pl */ {IDCLS_DISABLE_STRETCH_VERTICAL_PL, "Wy3�}cz dodatkowe rozci�}ganie w pionie"},
/* ru */ {IDCLS_DISABLE_STRETCH_VERTICAL_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_STRETCH_VERTICAL_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_DISABLE_STRETCH_VERTICAL_TR, ""},  /* fuzzy */
#endif

/* vdc/vdc-cmdline-options.c */
/* en */ {IDCLS_SET_VDC_MEMORY_16KB,    N_("Set the VDC memory size to 16KB")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_VDC_MEMORY_16KB_DA, "Sat VDC-hukommelsesstorrelse til 16KB"},
/* de */ {IDCLS_SET_VDC_MEMORY_16KB_DE, "VDC Speichgrose auf 16KB setzen"},
/* fr */ {IDCLS_SET_VDC_MEMORY_16KB_FR, "Regler la taille de la memoire VDC a 16KO"},
/* hu */ {IDCLS_SET_VDC_MEMORY_16KB_HU, "VDC memoria meret beallitasa 16KB-ra"},
/* it */ {IDCLS_SET_VDC_MEMORY_16KB_IT, "Imposta la dimensione della memoria del VDC a 16KB"},
/* ko */ {IDCLS_SET_VDC_MEMORY_16KB_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_VDC_MEMORY_16KB_NL, "Zet de VDC geheugengrootte als 16KB"},
/* pl */ {IDCLS_SET_VDC_MEMORY_16KB_PL, "Ustaw rozmiar pamieci VDC na 16 KB"},
/* ru */ {IDCLS_SET_VDC_MEMORY_16KB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_VDC_MEMORY_16KB_SV, "Satt VDC-minnesstorlek till 16KB"},
/* tr */ {IDCLS_SET_VDC_MEMORY_16KB_TR, "VDC bellek boyutunu 16KB'a ayarla"},
#endif

/* vdc/vdc-cmdline-options.c */
/* en */ {IDCLS_SET_VDC_MEMORY_64KB,    N_("Set the VDC memory size to 64KB")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_VDC_MEMORY_64KB_DA, "Sat VDC-hukommelsesstorrelse til 64KB"},
/* de */ {IDCLS_SET_VDC_MEMORY_64KB_DE, "VDC Speichgrose auf 64KB setzen"},
/* fr */ {IDCLS_SET_VDC_MEMORY_64KB_FR, "Regler la taille de la memoire VDC a 64KO"},
/* hu */ {IDCLS_SET_VDC_MEMORY_64KB_HU, "VDC memoria meret beallitasa 64KB-ra"},
/* it */ {IDCLS_SET_VDC_MEMORY_64KB_IT, "Imposta la dimensione della memoria del VDC a 64KB"},
/* ko */ {IDCLS_SET_VDC_MEMORY_64KB_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_VDC_MEMORY_64KB_NL, "Zet de VDC geheugengrootte als 64KB"},
/* pl */ {IDCLS_SET_VDC_MEMORY_64KB_PL, "Ustaw rozmiar pamieci VDC na 64 KB"},
/* ru */ {IDCLS_SET_VDC_MEMORY_64KB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_VDC_MEMORY_64KB_SV, "Satt VDC-minnesstorlek till 64KB"},
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
/* pl */ {IDCLS_SET_VDC_REVISION_PL, "Okre��l wersje VDC (0..2)"},
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
/* pl */ {IDCLS_P_SPEC_PL, "<spec>"},
/* ru */ {IDCLS_P_SPEC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_SPEC_SV, "<spec>"},
/* tr */ {IDCLS_P_SPEC_TR, "<tart>"},
#endif

/* vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_MEMORY_CONFIG,    N_("Specify memory configuration")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_MEMORY_CONFIG_DA, "Angiv hukommelseskonfiguration"},
/* de */ {IDCLS_SPECIFY_MEMORY_CONFIG_DE, "Speicher Konfiguration definieren"},
/* fr */ {IDCLS_SPECIFY_MEMORY_CONFIG_FR, "Specifier la configuration de la memoire"},
/* hu */ {IDCLS_SPECIFY_MEMORY_CONFIG_HU, "Adja meg a memoria konfiguraciot"},
/* it */ {IDCLS_SPECIFY_MEMORY_CONFIG_IT, "Specifica la configurazione della memoria"},
/* ko */ {IDCLS_SPECIFY_MEMORY_CONFIG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_MEMORY_CONFIG_NL, "Geef geheugenconfiguratie"},
/* pl */ {IDCLS_SPECIFY_MEMORY_CONFIG_PL, "Okre��l konfiguracje pamieci"},
/* ru */ {IDCLS_SPECIFY_MEMORY_CONFIG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_MEMORY_CONFIG_SV, "Ange minneskonfiguration"},
/* tr */ {IDCLS_SPECIFY_MEMORY_CONFIG_TR, "Bellek konfigurasyonunu ayarlayyn"},
#endif

/* vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_ENABLE_VIC1112_IEEE488,    N_("Enable VIC-1112 IEEE488 interface")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_VIC1112_IEEE488_DA, "Aktiver VIC-1112-IEEE488-interface"},
/* de */ {IDCLS_ENABLE_VIC1112_IEEE488_DE, "VIC-1112 IEEE488 Schnittstelle aktivieren"},
/* fr */ {IDCLS_ENABLE_VIC1112_IEEE488_FR, "Activer l'interface VIC-1112 IEEE488"},
/* hu */ {IDCLS_ENABLE_VIC1112_IEEE488_HU, "VIC-1112 IEEE488 interfesz engedelyezese"},
/* it */ {IDCLS_ENABLE_VIC1112_IEEE488_IT, "Attiva interfaccia IEEE488 VIC-1112"},
/* ko */ {IDCLS_ENABLE_VIC1112_IEEE488_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_VIC1112_IEEE488_NL, "Activeer VIC-1112 IEEE488 interface"},
/* pl */ {IDCLS_ENABLE_VIC1112_IEEE488_PL, "W3�}cz interfejs IEEE488 VIC-1112"},
/* ru */ {IDCLS_ENABLE_VIC1112_IEEE488_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_VIC1112_IEEE488_SV, "Aktivera VIC-1112-IEEE488-granssnitt"},
/* tr */ {IDCLS_ENABLE_VIC1112_IEEE488_TR, "VIC-1112 IEEE488 arabirimini aktif et"},
#endif

/* vic20/vic20-cmdline-options.c */
/* en */ {IDCLS_DISABLE_VIC1112_IEEE488,    N_("Disable VIC-1112 IEEE488 interface")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_VIC1112_IEEE488_DA, "Deaktiver VIC-1112-IEEE488-interface"},
/* de */ {IDCLS_DISABLE_VIC1112_IEEE488_DE, "VIC-1112 IEEE488 Schnittstelle deaktivieren"},
/* fr */ {IDCLS_DISABLE_VIC1112_IEEE488_FR, "Desactiver l'interface VIC-1112 IEEE488"},
/* hu */ {IDCLS_DISABLE_VIC1112_IEEE488_HU, "VIC-1112 IEEE488 interfesz tiltasa"},
/* it */ {IDCLS_DISABLE_VIC1112_IEEE488_IT, "Disattiva interfaccia IEEE488 VIC-1112"},
/* ko */ {IDCLS_DISABLE_VIC1112_IEEE488_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_VIC1112_IEEE488_NL, "VIC-1112 IEEE488 interface uitschakelen"},
/* pl */ {IDCLS_DISABLE_VIC1112_IEEE488_PL, "Wy3�}cz interfejs IEEE488 VIC-1112"},
/* ru */ {IDCLS_DISABLE_VIC1112_IEEE488_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_VIC1112_IEEE488_SV, "Inaktivera VIC-1112-IEEE488-granssnitt"},
/* tr */ {IDCLS_DISABLE_VIC1112_IEEE488_TR, "VIC-1112 IEEE488 arabirimini pasiflettir"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME,    N_("Specify 4/8/16K extension ROM name at $2000")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_DA, "Angiv navn for 4/8/16K-udviddelses-ROM pa $2000"},
/* de */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_DE, "4/8/16K Erweiterungs ROM Datei Name fur $2000 definieren"},
/* fr */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_FR, "Specifier le nom de l'extension ROM 4/8/16K a $2000"},
/* hu */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_HU, "Adja meg a $2000 cimu 4/8/16K ROM kiterjesztes nevet"},
/* it */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_IT, "Specifica il nome della ROM di estensione di 4/8/16K a $2000"},
/* ko */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_NL, "Geef de naam van het bestand voor de 4/8/16K ROM op $2000"},
/* pl */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_PL, "Okre��l nazwe ROM rozszerzenia 4/8/16K w $2000"},
/* ru */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_SV, "Ange namn for 4/8/16K-utoknings-ROM pa $2000"},
/* tr */ {IDCLS_SPECIFY_EXT_ROM_2000_NAME_TR, "$2000 adresindeki 4/8/16K uzantysy ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME,    N_("Specify 4/8/16K extension ROM name at $4000")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_DA, "Angiv navn for 4/8/16K-udviddelses-ROM pa $4000"},
/* de */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_DE, "4/8/16K Erweiterungs ROM Datei Name fur $4000 definieren"},
/* fr */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_FR, "Specifier le nom de l'extension ROM 4/8/16K a $4000"},
/* hu */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_HU, "Adja meg a $4000 cimu 4/8/16K ROM kiterjesztes nevet"},
/* it */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_IT, "Specifica il nome della ROM di estensione di 4/8/16K a $4000"},
/* ko */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_NL, "Geef de naam van het bestand voor de 4/8/16K ROM op $4000"},
/* pl */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_PL, "Okre��l nazwe ROM rozszerzenia 4/8/16K w $4000"},
/* ru */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_SV, "Ange namn for 4/8/16K-utoknings-ROM pa $4000"},
/* tr */ {IDCLS_SPECIFY_EXT_ROM_4000_NAME_TR, "$4000 adresindeki 4/8/16K uzantysy ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME,    N_("Specify 4/8/16K extension ROM name at $6000")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_DA, "Angiv navn for 4/8/16K-udviddelses-ROM pa $6000"},
/* de */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_DE, "4/8/16K Erweiterungs ROM Datei Name fur $6000 definieren"},
/* fr */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_FR, "Specifier le nom de l'extension ROM 4/8/16K a $6000"},
/* hu */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_HU, "Adja meg a $6000 cimu 4/8/16K ROM kiterjesztes nevet"},
/* it */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_IT, "Specifica il nome della ROM di estensione di 4/8/16K a $6000"},
/* ko */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_NL, "Geef de naam van het bestand voor de 4/8/16K ROM op $6000"},
/* pl */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_PL, "Okre��l nazwe ROM rozszerzenia 4/8/16K w $6000"},
/* ru */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_SV, "Ange namn for 4/8/16K-utoknings-ROM pa $6000"},
/* tr */ {IDCLS_SPECIFY_EXT_ROM_6000_NAME_TR, "$6000 adresindeki 4/8/16K uzantysy ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME,    N_("Specify 4/8K extension ROM name at $A000")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_DA, "Angiv navn for 4/8K-udviddelses-ROM pa $A000"},
/* de */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_DE, "4/8/16K Erweiterungs ROM Datei Name fur $A000 definieren"},
/* fr */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_FR, "Specifier le nom de l'extension ROM 4/8K a $A000"},
/* hu */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_HU, "Adja meg a $A000 cimu 4/8K ROM kiterjesztes nevet"},
/* it */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_IT, "Specifica il nome della ROM di estensione di 4/8K a $A000"},
/* ko */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_NL, "Geef de naam van het bestand voor de 4/8K ROM op $A000"},
/* pl */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_PL, "Okre��l nazwe ROM rozszerzenia 4/8/16K w $A000"},
/* ru */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_SV, "Ange namn for 4/8K-utoknings-ROM pa $A000"},
/* tr */ {IDCLS_SPECIFY_EXT_ROM_A000_NAME_TR, "$A000 adresindeki 4/8K uzantysy ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME,    N_("Specify 4K extension ROM name at $B000")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_DA, "Angiv navn for 4K-udviddelses-ROM pa $B000"},
/* de */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_DE, "4/8/16K Erweiterungs ROM Datei Name fur $B000 definieren"},
/* fr */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_FR, "Specifier le nom de l'extension ROM 4K a $B000"},
/* hu */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_HU, "Adja meg a $B000 cimu 4K ROM kiterjesztes nevet"},
/* it */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_IT, "Specifica il nome della ROM di estensione di 4 a $B000"},
/* ko */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_NL, "Geef de naam van het bestand voor de 4K ROM op $B000"},
/* pl */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_PL, "Okre��l nazwe ROM rozszerzenia 4/8/16K w $B000"},
/* ru */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_SV, "Ange namn for 4K-utoknings-ROM pa $B000"},
/* tr */ {IDCLS_SPECIFY_EXT_ROM_B000_NAME_TR, "$B000 adresindeki 4K uzantysy ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_GENERIC_ROM_NAME,    N_("Specify generic extension ROM name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_DA, "Angiv navn pa standard-udviddelses-ROM"},
/* de */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_DE, "Generisches Erweiterungs ROM definieren"},
/* fr */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_HU, "Adja meg az altalanos ROM kiterjesztes nevet"},
/* it */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_IT, "Specifica il nome dell'estensione ROM generica"},
/* ko */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_NL, "Geef de naam van het bestand voor de algemene ROM"},
/* pl */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_PL, "Okre��l nazwe typowego ROM-u rozszerzen"},
/* ru */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_SV, "Ange namn pa generiskt utoknings-ROM"},
/* tr */ {IDCLS_SPECIFY_GENERIC_ROM_NAME_TR, "Jenerik uzanty ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME,    N_("Specify Mega-Cart extension ROM name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_DA, "Angiv navn pa MegaCart-udviddelses-ROM"},
/* de */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_DE, "Mega-Cart Erweiterungs ROM definieren"},
/* fr */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_HU, "Adja meg a Mega-Cart ROM kiterjesztes nevet"},
/* it */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_IT, "Specifica il nome dell'estensione ROM Mega-Cart"},
/* ko */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_NL, "Geef de naam van het bestand voor de Mega-Cart ROM"},
/* pl */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_PL, "Okre��l nazwe ROM rozszerzenia Mega-Cart"},
/* ru */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_SV, "Ange namn pa Mega-Cart-utoknings-ROM"},
/* tr */ {IDCLS_SPECIFY_MEGA_CART_ROM_NAME_TR, "Mega-Cart uzantysy ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME,    N_("Specify Final Expansion extension ROM name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_DA, "Angiv navn pa Final Expansion udviddelses-ROM"},
/* de */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_DE, "Name fur Final Expansion Erweiterungs ROM definieren"},
/* fr */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_HU, "Adja meg a Final Expansion ROM kiterjesztes nevet"},
/* it */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_IT, "Specifica il nome dell'estensione ROM Final Expansion"},
/* ko */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_NL, "Geef de naam van het bestand voor de Final Expansion ROM"},
/* pl */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_PL, "Okre��l nazwe rozszerzenia ROM Final Expansion"},
/* ru */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_SV, "Ange namn pa Final Expansion utoknings-ROM"},
/* tr */ {IDCLS_SPECIFY_FINAL_EXPANSION_ROM_NAME_TR, "Final Expansion uzantysy ROM ismini belirt"},
#endif

/* vic20/cart/vic20cart.c */
/* en */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME,    N_("Specify Vic Flash Plugin extension ROM name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_DA, "Angiv navn pa Vic Flash Plugin udviddelses-ROM"},
/* de */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_DE, "Name fur Vic Flash Plugin Erweiterungs ROM definieren"},
/* fr */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_IT, "Specifica il nome dell'estensione ROM Vic Flash Plugin"},
/* ko */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_NL, "Geef de naam van het bestand voor de Vic Flash Plugin ROM"},
/* pl */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_PL, "Okre��l nazwe rozszerzenia ROM Vic Flash Plugin"},
/* ru */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_SV, "Ange namn pa Vic Flash-insticksmodulutoknings-ROM"},
/* tr */ {IDCLS_SPECIFY_VIC_FP_ROM_NAME_TR, "Vic Flash Plugin uzantysy ROM ismini belirt"},
#endif

/* vic20/cart/finalexpansion.c */
/* en */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK,    N_("Enable Final Expansion write back to ROM file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_DA, "Aktiver Final Expansion tilbageskrivning til ROM-fil"},
/* de */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_DE, "Final Expansion ROM Schreibzugriff aktivieren"},
/* fr */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_HU, "Final Expansion ROM fajlba visszairas engedelyezese"},
/* it */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_IT, "Attiva write back per Final Expansion su file ROM"},
/* ko */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_NL, "Activeer terug schrijven naar ROM bestand voor Final Expansion"},
/* pl */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_PL, "W3�}cz zapis do pliku ROM Final Expansion"},
/* ru */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_SV, "Aktivera aterskrivning till ROM-fil for Final Expansion"},
/* tr */ {IDCLS_ENABLE_FINALEXPANSION_WRITEBACK_TR, "Final Expansion ROM dosyasyna geri yazmayy aktif et"},
#endif

/* vic20/cart/finalexpansion.c */
/* en */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK,    N_("Disable Final Expansion write back to ROM file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_DA, "Deaktiver Final Expansion tilbageskrivning til ROM-fil"},
/* de */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_DE, "Final Expansion ROM Schreibzugriff deaktivieren"},
/* fr */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_HU, "Final Expansion ROM fajlba visszairas tiltasa"},
/* it */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_IT, "Disattiva write back per Final Expansion su file ROM"},
/* ko */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_NL, "Terug schrijven naar ROM bestand voor Final Expansion uitschakelen"},
/* pl */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_PL, "Wy3�}cz zapis do pliku ROM Final Expansion"},
/* ru */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_SV, "Inaktivera aterskrivning till ROM-fil for Final Expansion"},
/* tr */ {IDCLS_DISABLE_FINALEXPANSION_WRITEBACK_TR, "Final Expansion ROM dosyasyna geri yazmayy pasiflettir"},
#endif

/* vic20/cart/megacart.c */
/* en */ {IDCLS_SET_MEGACART_NVRAM_NAME,    N_("Set Mega-Cart NvRAM filename")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_MEGACART_NVRAM_NAME_DA, "Valg Mega-Cart NvRAM filnavn"},
/* de */ {IDCLS_SET_MEGACART_NVRAM_NAME_DE, "Mega-Cart NvRAM Imagename definieren"},
/* fr */ {IDCLS_SET_MEGACART_NVRAM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_MEGACART_NVRAM_NAME_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_MEGACART_NVRAM_NAME_IT, "Imposta nome file NvRAM Mega-Cart"},
/* ko */ {IDCLS_SET_MEGACART_NVRAM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_MEGACART_NVRAM_NAME_NL, "Zet Mega-Cart NvRAM bestandsnaam"},
/* pl */ {IDCLS_SET_MEGACART_NVRAM_NAME_PL, "Okre��l nazwe pliku NvRAM Mega-Cart"},
/* ru */ {IDCLS_SET_MEGACART_NVRAM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_MEGACART_NVRAM_NAME_SV, "Valj  Mega-Cart NvRAM-filnamn"},
/* tr */ {IDCLS_SET_MEGACART_NVRAM_NAME_TR, "Mega-Cart NvRAM dosyaismini gir"},
#endif

/* vic20/cart/megacart.c */
/* en */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE,    N_("Enable Mega-Cart NvRAM writeback")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_DA, "Aktiver Mega-Cart NvRAM tilbageskrivning"},
/* de */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_DE, "Mega-Cart NvRAM Ruckschreiben aktivieren"},
/* fr */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_IT, "Write back NvRAM Mega-Cart"},
/* ko */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_NL, "Activeer Mega-Cart NvRAM terug schrijven"},
/* pl */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_PL, "W3�}cz zapis do NvRAM Mega-Cart"},
/* ru */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_SV, "Aktivera Mega-Cart NvRAM-aterskrivning"},
/* tr */ {IDCLS_ENABLE_MEGACART_NVRAM_WRITE_TR, "Mega-Cart NvRAM geri yazmayy aktif et"},
#endif

/* vic20/cart/megacart.c */
/* en */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE,    N_("Disable Mega-Cart NvRAM writeback")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_DA, "Deaktiver Mega-Cart NvRAM tilbageskrivning"},
/* de */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_DE, "Mega-Cart NvRAM Ruckschreiben deaktivieren"},
/* fr */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_IT, "Disattiva write back su NvRAM Mega-Cart"},
/* ko */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_NL, "Mega-Cart NvRAM terug schrijven uitschakelen"},
/* pl */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_PL, "Wy3�}cz zapis do NvRAM Mega-Cart"},
/* ru */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_SV, "Inaktivera Mega-Cart NvRAM-aterskrivning"},
/* tr */ {IDCLS_DISABLE_MEGACART_NVRAM_WRITE_TR, "Mega-Cart NvRAM geri yazmayy pasiflettir"},
#endif

/* vic20/cart/vic-fp.c */
/* en */ {IDCLS_ENABLE_VICFP_ROM_WRITE,    N_("Enable Vic Flash Plugin write back to ROM file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_VICFP_ROM_WRITE_DA, "Aktiver Vic Flash Plugin tilbageskrivning til ROM-fil"},
/* de */ {IDCLS_ENABLE_VICFP_ROM_WRITE_DE, "Vic Flash Plugin Ruckschreiben auf ROM Datei aktivieren"},
/* fr */ {IDCLS_ENABLE_VICFP_ROM_WRITE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_VICFP_ROM_WRITE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_VICFP_ROM_WRITE_IT, "Attiva write back per Vic Flash Plugin su file ROM"},
/* ko */ {IDCLS_ENABLE_VICFP_ROM_WRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_VICFP_ROM_WRITE_NL, "Activeer terug schrijven naar ROM bestand voor Vic Flash Plugin"},
/* pl */ {IDCLS_ENABLE_VICFP_ROM_WRITE_PL, "W3�}cz zapis do pliku ROM Vic Flash Plugin"},
/* ru */ {IDCLS_ENABLE_VICFP_ROM_WRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_VICFP_ROM_WRITE_SV, "Aktivera aterskrivning till ROM-fil for Vic Flash-insticksmodul"},
/* tr */ {IDCLS_ENABLE_VICFP_ROM_WRITE_TR, "Flash Plugin ROM dosyasyna geri yazmayy aktif et"},
#endif

/* vic20/cart/vic-fp.c */
/* en */ {IDCLS_DISABLE_VICFP_ROM_WRITE,    N_("Disable Vic Flash Plugin write back to ROM file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_VICFP_ROM_WRITE_DA, "Deaktiver Vic Flash Plugin tilbageskrivning til ROM-fil"},
/* de */ {IDCLS_DISABLE_VICFP_ROM_WRITE_DE, "Vic Flash Plugin Ruckschreiben auf ROM Datei deaktivieren"},
/* fr */ {IDCLS_DISABLE_VICFP_ROM_WRITE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_VICFP_ROM_WRITE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_VICFP_ROM_WRITE_IT, "Disattiva write back per Vic Flash Plugin su file ROM"},
/* ko */ {IDCLS_DISABLE_VICFP_ROM_WRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_VICFP_ROM_WRITE_NL, "Terug schrijven naar ROM bestand voor Vic Flash Plugin uitschakelen"},
/* pl */ {IDCLS_DISABLE_VICFP_ROM_WRITE_PL, "Wy3�}cz zapis do pliku ROM Vic Flash Plugin"},
/* ru */ {IDCLS_DISABLE_VICFP_ROM_WRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_VICFP_ROM_WRITE_SV, "Inaktivera aterskrivning till ROM-fil for Vic Flash-insticksmodul"},
/* tr */ {IDCLS_DISABLE_VICFP_ROM_WRITE_TR, "Flash Plugin ROM dosyasyna geri yazmayy pasiflettir"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_SET_BORDER_MODE,    N_("Set VIC-II border display mode (0: normal, 1: full, 2: debug)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_BORDER_MODE_DA, "Valg VIC-II-rammevisningstilstand (0: normal, 1: fuld, 2: fejlsogning)"},
/* de */ {IDCLS_SET_BORDER_MODE_DE, "VIC-II Rahmen Darstellung Modus (0: normal, 1: full, 2: debug)"},
/* fr */ {IDCLS_SET_BORDER_MODE_FR, "Regler le mode de bordure VIC-II (0: normal, 1: complet, 2: debug)"},
/* hu */ {IDCLS_SET_BORDER_MODE_HU, "VIC-II keret megjelenitesi mod (0: normal, 1: teljes, 2: hibakereses)"},
/* it */ {IDCLS_SET_BORDER_MODE_IT, "Imposta la modalita di visualizzazione del bordo del VIC-II (0: normale, 1: intero, 2: debug)"},
/* ko */ {IDCLS_SET_BORDER_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_BORDER_MODE_NL, "Zet VIC-II border weergavemodus (0: normaal, 1: volledig, 2: debug)"},
/* pl */ {IDCLS_SET_BORDER_MODE_PL, "Okre��l tryb wy��wietlania ramki VIC-II (0: zwyk3a, 1: pe3na, 2: debug)"},
/* ru */ {IDCLS_SET_BORDER_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_BORDER_MODE_SV, "Valj VIC II-ramvisningslage (0: normal, 1: full, 2: felsokning)"},
/* tr */ {IDCLS_SET_BORDER_MODE_TR, "VIC-II cerceve gosterim modunu ayarlayyn (0: normal, 1: tam, 2: hata ayyklama)"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_ENABLE_SPRITE_BACKGROUND,    N_("Enable sprite-background collision registers")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SPRITE_BACKGROUND_DA, "Aktiver sprite-til-baggrunds-kollisionsregistre"},
/* de */ {IDCLS_ENABLE_SPRITE_BACKGROUND_DE, "Sprite-Hintergrund Kollisionen aktivieren"},
/* fr */ {IDCLS_ENABLE_SPRITE_BACKGROUND_FR, "Activer les registres de collisions de sprite avec arriere-plan"},
/* hu */ {IDCLS_ENABLE_SPRITE_BACKGROUND_HU, "Sprite-hatter utkozesi regiszterek engedelyezese"},
/* it */ {IDCLS_ENABLE_SPRITE_BACKGROUND_IT, "Attiva registri di collisione sprite-sfondo"},
/* ko */ {IDCLS_ENABLE_SPRITE_BACKGROUND_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SPRITE_BACKGROUND_NL, "Activeer sprite-achtergrond botsing registers"},
/* pl */ {IDCLS_ENABLE_SPRITE_BACKGROUND_PL, "W3�}cz rejestry kolizji duszkow z t3em"},
/* ru */ {IDCLS_ENABLE_SPRITE_BACKGROUND_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SPRITE_BACKGROUND_SV, "Aktivera sprite-till-bakgrund-kollisionsregister"},
/* tr */ {IDCLS_ENABLE_SPRITE_BACKGROUND_TR, "Yaratyk-arka plan carpytma registerlaryny aktif et"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_DISABLE_SPRITE_BACKGROUND,    N_("Disable sprite-background collision registers")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SPRITE_BACKGROUND_DA, "Deaktiver sprite-til-baggrunds-kollisionsregistre"},
/* de */ {IDCLS_DISABLE_SPRITE_BACKGROUND_DE, "Sprite-Hintergrund Kollisionen deaktivieren"},
/* fr */ {IDCLS_DISABLE_SPRITE_BACKGROUND_FR, "Desactiver les registres de collisions de sprite avec arriere-plan"},
/* hu */ {IDCLS_DISABLE_SPRITE_BACKGROUND_HU, "Sprite-hatter utkozesi regiszterek tiltasa"},
/* it */ {IDCLS_DISABLE_SPRITE_BACKGROUND_IT, "Disattiva registri di collisione sprite-sfondo"},
/* ko */ {IDCLS_DISABLE_SPRITE_BACKGROUND_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SPRITE_BACKGROUND_NL, "Sprite-achtergrond botsing registers uitschakelen"},
/* pl */ {IDCLS_DISABLE_SPRITE_BACKGROUND_PL, "Wy3�}cz rejestry kolizji duszkow z t3em"},
/* ru */ {IDCLS_DISABLE_SPRITE_BACKGROUND_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SPRITE_BACKGROUND_SV, "Inaktivera sprite-till-bakgrund-kollisionsregister"},
/* tr */ {IDCLS_DISABLE_SPRITE_BACKGROUND_TR, "Yaratyk-arka plan carpytma registerlaryny pasiflettir"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_ENABLE_SPRITE_SPRITE,    N_("Enable sprite-sprite collision registers")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SPRITE_SPRITE_DA, "Aktiver sprite-til-sprite-kollisionsregistre"},
/* de */ {IDCLS_ENABLE_SPRITE_SPRITE_DE, "Sprite-Sprite Kollisionen aktivieren"},
/* fr */ {IDCLS_ENABLE_SPRITE_SPRITE_FR, "Activer les registres de collisions de sprite avec sprite"},
/* hu */ {IDCLS_ENABLE_SPRITE_SPRITE_HU, "Sprite-sprite utkozesi regiszterek engedelyezese"},
/* it */ {IDCLS_ENABLE_SPRITE_SPRITE_IT, "Attiva registri di collisione sprite-sprite"},
/* ko */ {IDCLS_ENABLE_SPRITE_SPRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SPRITE_SPRITE_NL, "Activeer sprite-sprite botsing registers"},
/* pl */ {IDCLS_ENABLE_SPRITE_SPRITE_PL, "W3�}cz rejestry kolizji duszkow"},
/* ru */ {IDCLS_ENABLE_SPRITE_SPRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SPRITE_SPRITE_SV, "Aktivera sprite-till-sprite-kollisionsregister"},
/* tr */ {IDCLS_ENABLE_SPRITE_SPRITE_TR, "Yaratyk-yaratyk carpytma registerlaryny aktif et"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_DISABLE_SPRITE_SPRITE,    N_("Disable sprite-sprite collision registers")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SPRITE_SPRITE_DA, "Deaktiver sprite-til-sprite-kollisionsregistre"},
/* de */ {IDCLS_DISABLE_SPRITE_SPRITE_DE, "Sprite-Sprite Kollisionen deaktivieren"},
/* fr */ {IDCLS_DISABLE_SPRITE_SPRITE_FR, "Desactiver les registres de collisions de sprite avec sprite"},
/* hu */ {IDCLS_DISABLE_SPRITE_SPRITE_HU, "Sprite-sprite utkozesi regiszterek tiltasa"},
/* it */ {IDCLS_DISABLE_SPRITE_SPRITE_IT, "Disattiva registri di collisione sprite-sprite"},
/* ko */ {IDCLS_DISABLE_SPRITE_SPRITE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SPRITE_SPRITE_NL, "Sprite-sprite botsing registers uitschakelen"},
/* pl */ {IDCLS_DISABLE_SPRITE_SPRITE_PL, "Wy3�}cz rejestry kolizji duszkow"},
/* ru */ {IDCLS_DISABLE_SPRITE_SPRITE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SPRITE_SPRITE_SV, "Inaktivera sprite-till-sprite-kollisionsregister"},
/* tr */ {IDCLS_DISABLE_SPRITE_SPRITE_TR, "Yaratyk-yaratyk carpytma registerlaryny pasiflettir"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_USE_NEW_LUMINANCES,    N_("Use new luminances")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_NEW_LUMINANCES_DA, "Brug nye lysstyrker"},
/* de */ {IDCLS_USE_NEW_LUMINANCES_DE, "Neue Helligkeitsemulation"},
/* fr */ {IDCLS_USE_NEW_LUMINANCES_FR, "Utiliser les nouvelles luminescences"},
/* hu */ {IDCLS_USE_NEW_LUMINANCES_HU, "Az uj fenyeroket hasznalja"},
/* it */ {IDCLS_USE_NEW_LUMINANCES_IT, "Usa nuove luminanze"},
/* ko */ {IDCLS_USE_NEW_LUMINANCES_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_NEW_LUMINANCES_NL, "Gebruik nieuwe kleuren"},
/* pl */ {IDCLS_USE_NEW_LUMINANCES_PL, "U?yj nowego typu jaskrawo��ci"},
/* ru */ {IDCLS_USE_NEW_LUMINANCES_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_NEW_LUMINANCES_SV, "Anvand nya ljusstyrkor"},
/* tr */ {IDCLS_USE_NEW_LUMINANCES_TR, "Yeni parlaklyklary kullan"},
#endif

/* vicii/vicii-cmdline-options.c */
/* en */ {IDCLS_USE_OLD_LUMINANCES,    N_("Use old luminances")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_OLD_LUMINANCES_DA, "Brug gamle lysstyrker"},
/* de */ {IDCLS_USE_OLD_LUMINANCES_DE, "Alte Helligkeitsemulation"},
/* fr */ {IDCLS_USE_OLD_LUMINANCES_FR, "Utiliser les anciennes luminescences"},
/* hu */ {IDCLS_USE_OLD_LUMINANCES_HU, "A regi fenyeroket hasznalja"},
/* it */ {IDCLS_USE_OLD_LUMINANCES_IT, "Usa vecchie luminanze"},
/* ko */ {IDCLS_USE_OLD_LUMINANCES_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_OLD_LUMINANCES_NL, "Gebruik oude kleuren"},
/* pl */ {IDCLS_USE_OLD_LUMINANCES_PL, "U?yj starego typu jaskrawo��ci"},
/* ru */ {IDCLS_USE_OLD_LUMINANCES_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_OLD_LUMINANCES_SV, "Anvand gamla ljusstyrkor"},
/* tr */ {IDCLS_USE_OLD_LUMINANCES_TR, "Eski parlaklyklary kullan"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DOUBLE_SIZE,    N_("Enable double size")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DOUBLE_SIZE_DA, "Aktiver dobbelt storrelse"},
/* de */ {IDCLS_ENABLE_DOUBLE_SIZE_DE, "Doppelte Grose aktivieren"},
/* fr */ {IDCLS_ENABLE_DOUBLE_SIZE_FR, "Taille double"},
/* hu */ {IDCLS_ENABLE_DOUBLE_SIZE_HU, "Dupla meret engedelyezese"},
/* it */ {IDCLS_ENABLE_DOUBLE_SIZE_IT, "Attiva dimensione doppia"},
/* ko */ {IDCLS_ENABLE_DOUBLE_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DOUBLE_SIZE_NL, "Activeer dubbele grootte"},
/* pl */ {IDCLS_ENABLE_DOUBLE_SIZE_PL, "W3�}cz podwojny rozmiar"},
/* ru */ {IDCLS_ENABLE_DOUBLE_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DOUBLE_SIZE_SV, "Aktivera dubbel storlek"},
/* tr */ {IDCLS_ENABLE_DOUBLE_SIZE_TR, "Cift boyutu aktif et"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DOUBLE_SIZE,    N_("Disable double size")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DOUBLE_SIZE_DA, "Deaktiver dobbelt storrelse"},
/* de */ {IDCLS_DISABLE_DOUBLE_SIZE_DE, "Doppelte Grose deaktivieren"},
/* fr */ {IDCLS_DISABLE_DOUBLE_SIZE_FR, "Taille normale"},
/* hu */ {IDCLS_DISABLE_DOUBLE_SIZE_HU, "Dupla meret tiltasa"},
/* it */ {IDCLS_DISABLE_DOUBLE_SIZE_IT, "Disattiva dimensione doppia"},
/* ko */ {IDCLS_DISABLE_DOUBLE_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DOUBLE_SIZE_NL, "Dubbele grootte uitschakelen"},
/* pl */ {IDCLS_DISABLE_DOUBLE_SIZE_PL, "Wy3�}cz podwojny rozmiar"},
/* ru */ {IDCLS_DISABLE_DOUBLE_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DOUBLE_SIZE_SV, "Inaktivera dubbel storlek"},
/* tr */ {IDCLS_DISABLE_DOUBLE_SIZE_TR, "Cift boyutu pasiflettir"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_ENABLE_DOUBLE_SCAN,    N_("Enable double scan")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DOUBLE_SCAN_DA, "Aktiver dobbelt-skan"},
/* de */ {IDCLS_ENABLE_DOUBLE_SCAN_DE, "Doppelt Scan aktivieren"},
/* fr */ {IDCLS_ENABLE_DOUBLE_SCAN_FR, "Activer le mode double scan"},
/* hu */ {IDCLS_ENABLE_DOUBLE_SCAN_HU, "Dupla pasztazas engedelyezese"},
/* it */ {IDCLS_ENABLE_DOUBLE_SCAN_IT, "Attiva scansione doppia"},
/* ko */ {IDCLS_ENABLE_DOUBLE_SCAN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DOUBLE_SCAN_NL, "Activeer dubbele scan"},
/* pl */ {IDCLS_ENABLE_DOUBLE_SCAN_PL, "W3�}cz podwojne skanowanie"},
/* ru */ {IDCLS_ENABLE_DOUBLE_SCAN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DOUBLE_SCAN_SV, "Aktivera dubbelskanning"},
/* tr */ {IDCLS_ENABLE_DOUBLE_SCAN_TR, "Cift taramayy aktif et"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_DISABLE_DOUBLE_SCAN,    N_("Disable double scan")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DOUBLE_SCAN_DA, "Deaktiver dobbelt-skan"},
/* de */ {IDCLS_DISABLE_DOUBLE_SCAN_DE, "Doppelt Scan deaktivieren"},
/* fr */ {IDCLS_DISABLE_DOUBLE_SCAN_FR, "Desactiver le mode double scan"},
/* hu */ {IDCLS_DISABLE_DOUBLE_SCAN_HU, "Dupla pasztazas tiltasa"},
/* it */ {IDCLS_DISABLE_DOUBLE_SCAN_IT, "Disattiva scansione doppia"},
/* ko */ {IDCLS_DISABLE_DOUBLE_SCAN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DOUBLE_SCAN_NL, "Dubbele scan uitschakelen"},
/* pl */ {IDCLS_DISABLE_DOUBLE_SCAN_PL, "Wy3�}cz podwojne skanowanie"},
/* ru */ {IDCLS_DISABLE_DOUBLE_SCAN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DOUBLE_SCAN_SV, "Inaktivera dubbelskanning"},
/* tr */ {IDCLS_DISABLE_DOUBLE_SCAN_TR, "Cift taramayy pasiflettir"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_ENABLE_HARDWARE_SCALING,    N_("Enable hardware scaling")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_HARDWARE_SCALING_DA, "Aktiver hardware-skalering"},
/* de */ {IDCLS_ENABLE_HARDWARE_SCALING_DE, "Hardwareunterstutzung fur Skalierung aktivieren"},
/* fr */ {IDCLS_ENABLE_HARDWARE_SCALING_FR, "Activer le \"scaling\" materiel"},
/* hu */ {IDCLS_ENABLE_HARDWARE_SCALING_HU, "Hardver atmeretezes engedelyezese"},
/* it */ {IDCLS_ENABLE_HARDWARE_SCALING_IT, "Attiva hardware scaling"},
/* ko */ {IDCLS_ENABLE_HARDWARE_SCALING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_HARDWARE_SCALING_NL, "Activeer hardwareschaling"},
/* pl */ {IDCLS_ENABLE_HARDWARE_SCALING_PL, "y3�}cz skalowanie sprzetowe"},
/* ru */ {IDCLS_ENABLE_HARDWARE_SCALING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_HARDWARE_SCALING_SV, "Aktivera maskinvaruskalning"},
/* tr */ {IDCLS_ENABLE_HARDWARE_SCALING_TR, "Donanym destekli olceklendirmeyi aktif et"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_DISABLE_HARDWARE_SCALING,    N_("Disable hardware scaling")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_HARDWARE_SCALING_DA, "Deaktiver hardware-skalering"},
/* de */ {IDCLS_DISABLE_HARDWARE_SCALING_DE, "Hardwareunterstutzung fur Skalierung deaktivieren"},
/* fr */ {IDCLS_DISABLE_HARDWARE_SCALING_FR, "Desactiver le \"scaling\" materiel"},
/* hu */ {IDCLS_DISABLE_HARDWARE_SCALING_HU, "Hardver atmeretezes tiltasa"},
/* it */ {IDCLS_DISABLE_HARDWARE_SCALING_IT, "Disattiva hardware scaling"},
/* ko */ {IDCLS_DISABLE_HARDWARE_SCALING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_HARDWARE_SCALING_NL, "Hardwareschaling uitschakelen"},
/* pl */ {IDCLS_DISABLE_HARDWARE_SCALING_PL, "Wy3�}cz skalowanie sprzetowe"},
/* ru */ {IDCLS_DISABLE_HARDWARE_SCALING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_HARDWARE_SCALING_SV, "Inaktivera maskinvaruskalning"},
/* tr */ {IDCLS_DISABLE_HARDWARE_SCALING_TR, "Donanym destekli olceklendirmeyi pasiflettir"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_SET_VIDEO_FILTER,    N_("Select rendering filter, 0:none, 1:CRT emulation, 2: scale2x")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_VIDEO_FILTER_DA, ""},  /* fuzzy */
/* de */ {IDCLS_SET_VIDEO_FILTER_DE, "Wahle Rendering Filter, 0:kein, 1:CRT Emulation, 2: Scale2x"},
/* fr */ {IDCLS_SET_VIDEO_FILTER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_VIDEO_FILTER_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_VIDEO_FILTER_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_SET_VIDEO_FILTER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_VIDEO_FILTER_NL, ""},  /* fuzzy */
/* pl */ {IDCLS_SET_VIDEO_FILTER_PL, "Wybierz filtr renderera, 0:brak, 1: emulacja CRT, 2: skalowanie2x"},
/* ru */ {IDCLS_SET_VIDEO_FILTER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_VIDEO_FILTER_SV, ""},  /* fuzzy */
/* tr */ {IDCLS_SET_VIDEO_FILTER_TR, ""},  /* fuzzy */
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_USE_INTERNAL_CALC_PALETTE,    N_("Use an internal calculated palette")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_INTERNAL_CALC_PALETTE_DA, "Brug en internt beregnet palette"},
/* de */ {IDCLS_USE_INTERNAL_CALC_PALETTE_DE, "Benutze intern berechnete Palette"},
/* fr */ {IDCLS_USE_INTERNAL_CALC_PALETTE_FR, "Utiliser une palette interne calculee"},
/* hu */ {IDCLS_USE_INTERNAL_CALC_PALETTE_HU, "Belsoleg szamitott paletta hasznalata"},
/* it */ {IDCLS_USE_INTERNAL_CALC_PALETTE_IT, "Usa una palette interna calcolata"},
/* ko */ {IDCLS_USE_INTERNAL_CALC_PALETTE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_INTERNAL_CALC_PALETTE_NL, "Gebruik een intern berekend kleurenpalet"},
/* pl */ {IDCLS_USE_INTERNAL_CALC_PALETTE_PL, "U?ywaj wewnetrznej obliczonej palety kolorystycznej"},
/* ru */ {IDCLS_USE_INTERNAL_CALC_PALETTE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_INTERNAL_CALC_PALETTE_SV, "Anvand en internt beraknad palett"},
/* tr */ {IDCLS_USE_INTERNAL_CALC_PALETTE_TR, "Dahili hesaplanmyt bir palet kullan"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_USE_EXTERNAL_FILE_PALETTE,    N_("Use an external palette (file)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_DA, "Brug en ekstern palette (fil)"},
/* de */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_DE, "Benutze externe Palette (Datei)"},
/* fr */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_FR, "Utiliser une palette externe (fichier)"},
/* hu */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_HU, "Kulso paletta hasznalata (fajl)"},
/* it */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_IT, "Usa una palette esterna (file)"},
/* ko */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_NL, "Gebruik een extern kleurenpalet (bestand)"},
/* pl */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_PL, "U?ywaj zewnetrznej palety kolorystycznej (z pliku)"},
/* ru */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_SV, "Anvand en extern palett (fil)"},
/* tr */ {IDCLS_USE_EXTERNAL_FILE_PALETTE_TR, "Harici bir palet (dosyadan) kullan"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME,    N_("Specify name of file of external palette")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_DA, "Angiv filnavn for ekstern palette"},
/* de */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_DE, "Dateiname fur externe Palette definieren"},
/* fr */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_FR, "Specifier le nom du fichier de la palette externe"},
/* hu */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_HU, "Adja meg a kulso paletta nevet"},
/* it */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_IT, "Specifica il nome del file della palette esterna"},
/* ko */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_NL, "Geef de naam van het extern kleurenpaletbestand"},
/* pl */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_PL, "Okre��l nazwe pliku zewnetrznej palety barw"},
/* ru */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_SV, "Ange namn pa fil for extern palett"},
/* tr */ {IDCLS_SPECIFY_EXTERNAL_PALETTE_NAME_TR, "Harici palet dosyasynyn ismini belirt"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_P_DEVICE,    N_("<device>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_DEVICE_DA, "<enhed>"},
/* de */ {IDCLS_P_DEVICE_DE, "<Gerat>"},
/* fr */ {IDCLS_P_DEVICE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_DEVICE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_DEVICE_IT, "<dispositivo>"},
/* ko */ {IDCLS_P_DEVICE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_P_DEVICE_NL, "<apparaat>"},
/* pl */ {IDCLS_P_DEVICE_PL, "<device>"},
/* ru */ {IDCLS_P_DEVICE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_DEVICE_SV, "<enhet>"},
/* tr */ {IDCLS_P_DEVICE_TR, "<aygyt>"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_SELECT_FULLSCREEN_DEVICE,    N_("Select fullscreen device")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SELECT_FULLSCREEN_DEVICE_DA, "Angiv fuldskarmsenhed"},
/* de */ {IDCLS_SELECT_FULLSCREEN_DEVICE_DE, "Vollbild Gerat auswahlen"},
/* fr */ {IDCLS_SELECT_FULLSCREEN_DEVICE_FR, "Selectionner le peripherique plein ecran"},
/* hu */ {IDCLS_SELECT_FULLSCREEN_DEVICE_HU, "Teljeskepernyos eszkoz kivalasztasa"},
/* it */ {IDCLS_SELECT_FULLSCREEN_DEVICE_IT, "Seleziona il dispositivo per la visualizzazione a schermo intero"},
/* ko */ {IDCLS_SELECT_FULLSCREEN_DEVICE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SELECT_FULLSCREEN_DEVICE_NL, "Selecteer volschermapparaat"},
/* pl */ {IDCLS_SELECT_FULLSCREEN_DEVICE_PL, "Wybierz urz�}dzenie pe3nego ekranu"},
/* ru */ {IDCLS_SELECT_FULLSCREEN_DEVICE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SELECT_FULLSCREEN_DEVICE_SV, "Ange fullskarmsenhet"},
/* tr */ {IDCLS_SELECT_FULLSCREEN_DEVICE_TR, "Tam ekran aygyty sec"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_P_MODE,    N_("<Mode>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_MODE_DA, "<Tilstand>"},
/* de */ {IDCLS_P_MODE_DE, "<Modus>"},
/* fr */ {IDCLS_P_MODE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_MODE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_MODE_IT, "<Modalita>"},
/* ko */ {IDCLS_P_MODE_KO, "<�Cd��a>"},
/* nl */ {IDCLS_P_MODE_NL, "<Modus>"},
/* pl */ {IDCLS_P_MODE_PL, "<Tryb>"},
/* ru */ {IDCLS_P_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_MODE_SV, "<Lage>"},
/* tr */ {IDCLS_P_MODE_TR, "<Mod>"},
#endif

/* video/video-cmdline-options.c */
/* en */ {IDCLS_SELECT_FULLSCREEN_MODE,    N_("Select fullscreen mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SELECT_FULLSCREEN_MODE_DA, "Aktiver fuldskarms-tilstand"},
/* de */ {IDCLS_SELECT_FULLSCREEN_MODE_DE, "Vollbild Modus wahlen"},
/* fr */ {IDCLS_SELECT_FULLSCREEN_MODE_FR, "Selectionner le mode plein ecran"},
/* hu */ {IDCLS_SELECT_FULLSCREEN_MODE_HU, "Teljes kepernyos mod kivalasztasa"},
/* it */ {IDCLS_SELECT_FULLSCREEN_MODE_IT, "Seleziona modalita a schermo intero"},
/* ko */ {IDCLS_SELECT_FULLSCREEN_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SELECT_FULLSCREEN_MODE_NL, "Activeer volschermmodus"},
/* pl */ {IDCLS_SELECT_FULLSCREEN_MODE_PL, "Wybierz tryb pe3nego ekranu"},
/* ru */ {IDCLS_SELECT_FULLSCREEN_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SELECT_FULLSCREEN_MODE_SV, "Aktivera fullskarmslage"},
/* tr */ {IDCLS_SELECT_FULLSCREEN_MODE_TR, "Tam ekran modu sec"},
#endif

/* aciacore.c */
/* en */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE,    N_("Specify RS232 device this ACIA should work on")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_DA, "Angiv RS232-enhed denne ACIA skal bruge"},
/* de */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_DE, "RS232 Gerat fur welches ACIA funktionieren soll ist zu spezifizieren"},
/* fr */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_FR, "Specifier le peripherique RS232 sur lequel cet ACIA doit fonctionner"},
/* hu */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_HU, "Adja meg az RS232-es egyseget, amivel az ACIA mukodni fog"},
/* it */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_IT, "Specifica il dispositivo RS232 con il quale questa ACIA dovrebbe funzionare"},
/* ko */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_NL, "Geef het RS232 apparaat waarmee deze ACIA moet werken"},
/* pl */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_PL, "Okre��l urz�}dzenie RS232, na ktorym ma dzia3aa ACIA"},
/* ru */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_SV, "Ange RS232-enhet denna ACIA skall arbeta pa"},
/* tr */ {IDCLS_SPECIFY_ACIA_RS232_DEVICE_TR, "Bu ACIA'in calytmasy gereken RS232 aygytyny belirt"},
#endif

/* attach.c */
/* en */ {IDCLS_SET_DEVICE_TYPE_8,    N_("Set device type for device #8 (0: NONE, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK DEVICE)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DEVICE_TYPE_8_DA, "Valg type for enhed #8 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOKENHED)"},
/* de */ {IDCLS_SET_DEVICE_TYPE_8_DE, "Gerate Typ fur Gerat #8 (0: Kein, 1: Dateisystem, 2: OpenCBM, 3: Block Gerat)"},
/* fr */ {IDCLS_SET_DEVICE_TYPE_8_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_DEVICE_TYPE_8_HU, "Adja meg a #8-es egyseg tipusat (0: Nincs, 1: fajlrendszer, 2: OPENCBM, 3 blokk eszkoz)"},
/* it */ {IDCLS_SET_DEVICE_TYPE_8_IT, "Imposta il tipo di periferica #8 (0 NESSUNA, 1: FILESYSTEM, 2: OPENCBM, 3: DISPOSITIVO A BLOCCHI)"},
/* ko */ {IDCLS_SET_DEVICE_TYPE_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DEVICE_TYPE_8_NL, "Zet het apparaatsoort voor apparaat #8 (0: GEEN, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK APPARAAT)"},
/* pl */ {IDCLS_SET_DEVICE_TYPE_8_PL, "Okre��l typ urz�}dzenia #8 (0: NONE, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK DEVICE)"},
/* ru */ {IDCLS_SET_DEVICE_TYPE_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DEVICE_TYPE_8_SV, "Stall in enhetstyp for enhet 8 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOCKENHET)"},
/* tr */ {IDCLS_SET_DEVICE_TYPE_8_TR, "Aygyt #8 icin aygyt tipini belirt (0: YOK, 1: DOSYASYSTEMY, 2: OPENCBM, 3: BLOK AYIGTI)"},
#endif

/* attach.c */
/* en */ {IDCLS_SET_DEVICE_TYPE_9,    N_("Set device type for device #9 (0: NONE, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK DEVICE)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DEVICE_TYPE_9_DA, "Valg type for enhed #9 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOKENHED)"},
/* de */ {IDCLS_SET_DEVICE_TYPE_9_DE, "Gerate Typ fur Gerat #9 (0: Kein, 1: Dateisystem, 2: OpenCBM, 3: Block Gerat)"},
/* fr */ {IDCLS_SET_DEVICE_TYPE_9_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_DEVICE_TYPE_9_HU, "Adja meg a #9-es egyseg tipusat (0: Nincs, 1: fajlrendszer, 2: OPENCBM, 3: blokk eszkoz)"},
/* it */ {IDCLS_SET_DEVICE_TYPE_9_IT, "Imposta il tipo di periferica #9 (0 NESSUNA, 1: FILESYSTEM, 2: OPENCBM, 3: DISPOSITIVO A BLOCCHI)"},
/* ko */ {IDCLS_SET_DEVICE_TYPE_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DEVICE_TYPE_9_NL, "Zet het apparaatsoort voor apparaat #9 (0: GEEN, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK APPARAAT)"},
/* pl */ {IDCLS_SET_DEVICE_TYPE_9_PL, "Okre��l typ urz�}dzenia #8 (0: NONE, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK DEVICE)"},
/* ru */ {IDCLS_SET_DEVICE_TYPE_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DEVICE_TYPE_9_SV, "Stall in enhetstyp for enhet 9 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOCKENHET)"},
/* tr */ {IDCLS_SET_DEVICE_TYPE_9_TR, "Aygyt #9 icin aygyt tipini belirt (0: YOK, 1: DOSYASYSTEMY, 2: OPENCBM, 3: BLOK AYIGTI)"},
#endif

/* attach.c */
/* en */ {IDCLS_SET_DEVICE_TYPE_10,    N_("Set device type for device #10 (0: NONE, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK DEVICE)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DEVICE_TYPE_10_DA, "Valg type for enhed #10 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOKENHED)"},
/* de */ {IDCLS_SET_DEVICE_TYPE_10_DE, "Gerate Typ fur Gerat #10 (0: Kein, 1: Dateisystem, 2: OpenCBM, 3: Block Gerat)"},
/* fr */ {IDCLS_SET_DEVICE_TYPE_10_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_DEVICE_TYPE_10_HU, "Adja meg a #10-es egyseg tipusat (0: Nincs, 1: fajlrendszer, 2: OPENVMB, 3: blokk eszkoz)"},
/* it */ {IDCLS_SET_DEVICE_TYPE_10_IT, "Imposta il tipo di periferica #10 (0 NESSUNA, 1: FILESYSTEM, 2: OPENCBM, 3: DISPOSITIVO A BLOCCHI)"},
/* ko */ {IDCLS_SET_DEVICE_TYPE_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DEVICE_TYPE_10_NL, "Zet het apparaatsoort voor apparaat #10 (0: GEEN, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK APPARAAT)"},
/* pl */ {IDCLS_SET_DEVICE_TYPE_10_PL, "Okre��l typ urz�}dzenia #8 (0: NONE, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK DEVICE)"},
/* ru */ {IDCLS_SET_DEVICE_TYPE_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DEVICE_TYPE_10_SV, "Stall in enhetstyp for enhet 10 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOCKENHET)"},
/* tr */ {IDCLS_SET_DEVICE_TYPE_10_TR, "Aygyt #10 icin aygyt tipini belirt (0: YOK, 1: DOSYASYSTEMY, 2: OPENCBM, 3: BLOK AYIGTI)"},
#endif

/* attach.c */
/* en */ {IDCLS_SET_DEVICE_TYPE_11,    N_("Set device type for device #11 (0: NONE, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK DEVICE)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_DEVICE_TYPE_11_DA, "Valg type for enhed #11 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOKENHED)"},
/* de */ {IDCLS_SET_DEVICE_TYPE_11_DE, "Gerate Typ fur Gerat #11 (0: Kein, 1: Dateisystem, 2: OpenCBM, 3: Block Gerat)"},
/* fr */ {IDCLS_SET_DEVICE_TYPE_11_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_DEVICE_TYPE_11_HU, "Adja meg a #11-es egyseg tipusat (0: Nincs, 1: fajlrendszer, 2: OPENCBM, 3: blokk eszkoz)"},
/* it */ {IDCLS_SET_DEVICE_TYPE_11_IT, "Imposta il tipo di periferica #11 (0 NESSUNA, 1: FILESYSTEM, 2: OPENCBM, 3: DISPOSITIVO A BLOCCHI)"},
/* ko */ {IDCLS_SET_DEVICE_TYPE_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_DEVICE_TYPE_11_NL, "Zet het apparaatsoort voor apparaat #11 (0: GEEN, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK APPARAAT)"},
/* pl */ {IDCLS_SET_DEVICE_TYPE_11_PL, "Okre��l typ urz�}dzenia #8 (0: NONE, 1: FILESYSTEM, 2: OPENCBM, 3: BLOCK DEVICE)"},
/* ru */ {IDCLS_SET_DEVICE_TYPE_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_DEVICE_TYPE_11_SV, "Stall in enhetstyp for enhet 11 (0: INGEN, 1: FILSYSTEM, 2: OPENCBM, 3: BLOCKENHET)"},
/* tr */ {IDCLS_SET_DEVICE_TYPE_11_TR, "Aygyt #11 icin aygyt tipini belirt (0: YOK, 1: DOSYASYSTEMY, 2: OPENCBM, 3: BLOK AYIGTI)"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_ONLY_8,    N_("Attach disk image for drive #8 read only")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_ONLY_8_DA, "Tilslut disk-image til drev #8 skrivebeskyttet"},
/* de */ {IDCLS_ATTACH_READ_ONLY_8_DE, "Disk Image als Laufwerk #8 benutzen (schreibgeschutzt)"},
/* fr */ {IDCLS_ATTACH_READ_ONLY_8_FR, "Charger une image de disque pour le lecteur #8 en lecture seule"},
/* hu */ {IDCLS_ATTACH_READ_ONLY_8_HU, "Csak olvashato kepmas csatolasa a #8-as lemezegyseghez"},
/* it */ {IDCLS_ATTACH_READ_ONLY_8_IT, "Seleziona immagine del disco per il drive #8 in sola lettura"},
/* ko */ {IDCLS_ATTACH_READ_ONLY_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_ONLY_8_NL, "Koppel schijfbestand voor drive #8 als alleen-lezen"},
/* pl */ {IDCLS_ATTACH_READ_ONLY_8_PL, "Zamontuj obraz dysku w stacji #8 tylko do odczytu"},
/* ru */ {IDCLS_ATTACH_READ_ONLY_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_ONLY_8_SV, "Anslut diskettavbildningsfil for enhet 8 med skrivskydd"},
/* tr */ {IDCLS_ATTACH_READ_ONLY_8_TR, "Surucu #8 icin disk imajyny salt okunur olarak yerlettir"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_WRITE_8,    N_("Attach disk image for drive #8 read write (if possible)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_WRITE_8_DA, "Tilslut disk-image til drev #8 skrivbar (hvis muligt)"},
/* de */ {IDCLS_ATTACH_READ_WRITE_8_DE, "Disk Image als Laufwerk #8 benutzen (Schreibzugriff, wenn moglich)"},
/* fr */ {IDCLS_ATTACH_READ_WRITE_8_FR, "Charger une image de disque pour le lecteur #8 en lecture-ecriture (si possible)"},
/* hu */ {IDCLS_ATTACH_READ_WRITE_8_HU, "Irhato-olvashato kepmas csatolasa a #8-as lemezegyseghez"},
/* it */ {IDCLS_ATTACH_READ_WRITE_8_IT, "Seleziona immagine del disco per il drive #8 in lettura/scrittura (se possibile)"},
/* ko */ {IDCLS_ATTACH_READ_WRITE_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_WRITE_8_NL, "Koppel schijfbestand voor drive #8 als schrijfbaar (indien mogelijk)"},
/* pl */ {IDCLS_ATTACH_READ_WRITE_8_PL, "Zamontuj obraz dyskietki w stacji #8 w trybie zapisu i odczytu (o ile to mo?liwe)"},
/* ru */ {IDCLS_ATTACH_READ_WRITE_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_WRITE_8_SV, "Anslut diskettavbildningsfil for enhet 8 skrivbar (om mojligt)"},
/* tr */ {IDCLS_ATTACH_READ_WRITE_8_TR, "Surucu #8 icin disk imajyny okunur/yazylyr olarak yerlettir (mumkunse)"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_ONLY_9,    N_("Attach disk image for drive #9 read only")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_ONLY_9_DA, "Tilslut disk-image til drev #9 skrivebeskyttet"},
/* de */ {IDCLS_ATTACH_READ_ONLY_9_DE, "Disk Image als Laufwerk #9 benutzen (schreibgeschutzt)"},
/* fr */ {IDCLS_ATTACH_READ_ONLY_9_FR, "Charger une image de disque pour le lecteur #9 en lecture seule"},
/* hu */ {IDCLS_ATTACH_READ_ONLY_9_HU, "Csak olvashato kepmas csatolasa a #9-es lemezegyseghez"},
/* it */ {IDCLS_ATTACH_READ_ONLY_9_IT, "Seleziona immagine del disco per il drive #9 in sola lettura"},
/* ko */ {IDCLS_ATTACH_READ_ONLY_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_ONLY_9_NL, "Koppel schijfbestand voor drive #9 als alleen-lezen"},
/* pl */ {IDCLS_ATTACH_READ_ONLY_9_PL, "Zamontuj obraz dysku w stacji #9 tylko do odczytu"},
/* ru */ {IDCLS_ATTACH_READ_ONLY_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_ONLY_9_SV, "Anslut diskettavbildningsfil for enhet 9 med skrivskydd"},
/* tr */ {IDCLS_ATTACH_READ_ONLY_9_TR, "Surucu #9 icin disk imajyny salt okunur olarak yerlettir"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_WRITE_9,    N_("Attach disk image for drive #9 read write (if possible)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_WRITE_9_DA, "Tilslut disk-image til drev #9 skrivbar (hvis muligt)"},
/* de */ {IDCLS_ATTACH_READ_WRITE_9_DE, "Disk Image als Laufwerk #9 benutzen (Schreibzugriff, wenn moglich)"},
/* fr */ {IDCLS_ATTACH_READ_WRITE_9_FR, "Charger une image de disque pour le lecteur #9 en lecture-ecriture (si possible)"},
/* hu */ {IDCLS_ATTACH_READ_WRITE_9_HU, "Irhato-olvashato kepmas csatolasa a #9-es lemezegyseghez"},
/* it */ {IDCLS_ATTACH_READ_WRITE_9_IT, "Seleziona immagine del disco per il drive #9 in lettura/scrittura (se possibile)"},
/* ko */ {IDCLS_ATTACH_READ_WRITE_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_WRITE_9_NL, "Koppel schijfbestand voor drive #9 als schrijfbaar (indien mogelijk)"},
/* pl */ {IDCLS_ATTACH_READ_WRITE_9_PL, "Zamontuj obraz dyskietki w stacji #9 w trybie zapisu i odczytu (o ile to mo?liwe)"},
/* ru */ {IDCLS_ATTACH_READ_WRITE_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_WRITE_9_SV, "Anslut diskettavbildningsfil for enhet 9 skrivbar (om mojligt)"},
/* tr */ {IDCLS_ATTACH_READ_WRITE_9_TR, "Surucu #9 icin disk imajyny okunur/yazylyr olarak yerlettir (mumkunse)"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_ONLY_10,    N_("Attach disk image for drive #10 read only")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_ONLY_10_DA, "Tilslut disk-image til drev #10 skrivebeskyttet"},
/* de */ {IDCLS_ATTACH_READ_ONLY_10_DE, "Disk Image als Laufwerk #10 benutzen (schreibgeschutzt)"},
/* fr */ {IDCLS_ATTACH_READ_ONLY_10_FR, "Charger une image de disque pour le lecteur #10 en lecture seule"},
/* hu */ {IDCLS_ATTACH_READ_ONLY_10_HU, "Csak olvashato kepmas csatolasa a #10-es lemezegyseghez"},
/* it */ {IDCLS_ATTACH_READ_ONLY_10_IT, "Seleziona immagine del disco per il drive #10 in sola lettura"},
/* ko */ {IDCLS_ATTACH_READ_ONLY_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_ONLY_10_NL, "Koppel schijfbestand voor drive #10 als alleen-lezen"},
/* pl */ {IDCLS_ATTACH_READ_ONLY_10_PL, "Zamontuj obraz dysku w stacji #10 tylko do odczytu"},
/* ru */ {IDCLS_ATTACH_READ_ONLY_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_ONLY_10_SV, "Anslut diskettavbildningsfil for enhet 10 med skrivskydd"},
/* tr */ {IDCLS_ATTACH_READ_ONLY_10_TR, "Surucu #10 icin disk imajyny salt okunur olarak yerlettir"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_WRITE_10,    N_("Attach disk image for drive #10 read write (if possible)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_WRITE_10_DA, "Tilslut disk-image til drev #10 skrivbar (hvis muligt)"},
/* de */ {IDCLS_ATTACH_READ_WRITE_10_DE, "Disk Image als Laufwerk #10 benutzen (Schreibzugriff, wenn moglich)"},
/* fr */ {IDCLS_ATTACH_READ_WRITE_10_FR, "Charger une image de disque pour le lecteur #10 en lecture-ecriture (si possible)"},
/* hu */ {IDCLS_ATTACH_READ_WRITE_10_HU, "Irhato-olvashato kepmas csatolasa a #10-es lemezegyseghez"},
/* it */ {IDCLS_ATTACH_READ_WRITE_10_IT, "Seleziona immagine del disco per il drive #10 in lettura/scrittura (se possibile)"},
/* ko */ {IDCLS_ATTACH_READ_WRITE_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_WRITE_10_NL, "Koppel schijfbestand voor drive #10 als schrijfbaar (indien mogelijk)"},
/* pl */ {IDCLS_ATTACH_READ_WRITE_10_PL, "Zamontuj obraz dyskietki w stacji #10 w trybie zapisu i odczytu (o ile to mo?liwe)"},
/* ru */ {IDCLS_ATTACH_READ_WRITE_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_WRITE_10_SV, "Anslut diskettavbildningsfil for enhet 10 skrivbar (om mojligt)"},
/* tr */ {IDCLS_ATTACH_READ_WRITE_10_TR, "Surucu #10 icin disk imajyny okunur/yazylyr olarak yerlettir (mumkunse)"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_ONLY_11,    N_("Attach disk image for drive #11 read only")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_ONLY_11_DA, "Tilslut disk-image til drev #11 skrivebeskyttet"},
/* de */ {IDCLS_ATTACH_READ_ONLY_11_DE, "Disk Image als Laufwerk #11 benutzen (schreibgeschutzt)"},
/* fr */ {IDCLS_ATTACH_READ_ONLY_11_FR, "Charger une image de disque pour le lecteur #11 en lecture seule"},
/* hu */ {IDCLS_ATTACH_READ_ONLY_11_HU, "Csak olvashato kepmas csatolasa a #11-es lemezegyseghez"},
/* it */ {IDCLS_ATTACH_READ_ONLY_11_IT, "Seleziona immagine del disco per il drive #11 in sola lettura"},
/* ko */ {IDCLS_ATTACH_READ_ONLY_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_ONLY_11_NL, "Koppel schijfbestand voor drive #11 als alleen-lezen"},
/* pl */ {IDCLS_ATTACH_READ_ONLY_11_PL, "Zamontuj obraz dysku w stacji #11 tylko do odczytu"},
/* ru */ {IDCLS_ATTACH_READ_ONLY_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_ONLY_11_SV, "Anslut diskettavbildningsfil for enhet 11 med skrivskydd"},
/* tr */ {IDCLS_ATTACH_READ_ONLY_11_TR, "Surucu #11 icin disk imajyny salt okunur olarak yerlettir"},
#endif

/* attach.c */
/* en */ {IDCLS_ATTACH_READ_WRITE_11,    N_("Attach disk image for drive #11 read write (if possible)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_READ_WRITE_11_DA, "Tilslut disk-image til drev #11 skrivbar (hvis muligt)"},
/* de */ {IDCLS_ATTACH_READ_WRITE_11_DE, "Disk Image als Laufwerk #11 benutzen (Schreibzugriff, wenn moglich)"},
/* fr */ {IDCLS_ATTACH_READ_WRITE_11_FR, "Charger une image de disque pour le lecteur #11 en lecture-ecriture (si possible)"},
/* hu */ {IDCLS_ATTACH_READ_WRITE_11_HU, "Irhato-olvashato kepmas csatolasa a #11-es lemezegyseghez"},
/* it */ {IDCLS_ATTACH_READ_WRITE_11_IT, "Seleziona immagine del disco per il drive #11 in lettura/scrittura (se possibile)"},
/* ko */ {IDCLS_ATTACH_READ_WRITE_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_READ_WRITE_11_NL, "Koppel schijfbestand voor drive #11 als schrijfbaar (indien mogelijk)"},
/* pl */ {IDCLS_ATTACH_READ_WRITE_11_PL, "Zamontuj obraz dyskietki w stacji #11 w trybie zapisu i odczytu (o ile to mo?liwe)"},
/* ru */ {IDCLS_ATTACH_READ_WRITE_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_READ_WRITE_11_SV, "Anslut diskettavbildningsfil for enhet 11 skrivbar (om mojligt)"},
/* tr */ {IDCLS_ATTACH_READ_WRITE_11_TR, "Surucu #11 icin disk imajyny okunur/yazylyr olarak yerlettir (mumkunse)"},
#endif

/* datasette.c */
/* en */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET,    N_("Enable automatic Datasette-Reset")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_DA, "Aktiver automatisk Datasette-reset"},
/* de */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_DE, "Automatisches Datasette-Reset aktivieren"},
/* fr */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_FR, "Activer le redemarrage automatique du Datasette"},
/* hu */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_HU, "Automatikus magno Reset engedelyezese"},
/* it */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_IT, "Attiva reset automatico del registratore"},
/* ko */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_NL, "Activeer automatische Datasette-Reset"},
/* pl */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_PL, "W3�}cz automatyczny reset magnetofonu"},
/* ru */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_SV, "Aktivera automatisk Datasetteaterstallning"},
/* tr */ {IDCLS_ENABLE_AUTO_DATASETTE_RESET_TR, "Otomatik Teyp-Reset'i aktif et"},
#endif

/* datasette.c */
/* en */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET,    N_("Disable automatic Datasette-Reset")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_DA, "Deaktiver automatisk Datasette-reset"},
/* de */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_DE, "Automatisches Datasette-Reset deaktivieren"},
/* fr */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_FR, "Desactiver le redemarrage automatique du Datasette"},
/* hu */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_HU, "Automatikus magno Reset tiltasa"},
/* it */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_IT, "Disattiva reset automatico del registratore"},
/* ko */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_NL, "Automatische Datasette-Reset uitschakelen"},
/* pl */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_PL, "Wy3�}cz automatyczny reset magnetofonu"},
/* ru */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_SV, "Inaktivera automatisk Datasetteaterstallning"},
/* tr */ {IDCLS_DISABLE_AUTO_DATASETTE_RESET_TR, "Otomatik Teyp-Reset'i pasiflettir"},
#endif

/* datasette.c */
/* en */ {IDCLS_SET_ZERO_TAP_DELAY,    N_("Set delay in cycles for a zero in the tap")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_ZERO_TAP_DELAY_DA, "Angiv forsinkelse i cykler for et nul i tap-filen"},
/* de */ {IDCLS_SET_ZERO_TAP_DELAY_DE, "Verzogerung fur Zero in Zyklen im Tap"},
/* fr */ {IDCLS_SET_ZERO_TAP_DELAY_FR, "Specifier le delai en cycles pour un zero sur le ruban"},
/* hu */ {IDCLS_SET_ZERO_TAP_DELAY_HU, "Adja meg ciklusokban a legelso szalagres hosszat"},
/* it */ {IDCLS_SET_ZERO_TAP_DELAY_IT, "Imposta il ritardo in cicli per uno zero nel tap"},
/* ko */ {IDCLS_SET_ZERO_TAP_DELAY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_ZERO_TAP_DELAY_NL, "Zet de vertraging in cycli voor een nul in de tap"},
/* pl */ {IDCLS_SET_ZERO_TAP_DELAY_PL, "Okre��l opo?nienie cyklow dla pocz�}tku ta��my"},
/* ru */ {IDCLS_SET_ZERO_TAP_DELAY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_ZERO_TAP_DELAY_SV, "Ange vantecykler for nolla i tap-filen"},
/* tr */ {IDCLS_SET_ZERO_TAP_DELAY_TR, "Badlanty anynda cycle tipinden bekleme suresini ayarla"},
#endif

/* datasette.c */
/* en */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP,    N_("Set number of cycles added to each gap in the tap")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_DA, "Angiv antal cykler der lagges til hvert hul i tap-filen"},
/* de */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_DE, "Setze Anzahl der Zyklen fur jedes Loch im Tap"},
/* fr */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_FR, "Specifier le nombre de cycles ajoute a chaque raccord du ruban"},
/* hu */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_HU, "Adja meg ciklusokban a szalagfajlok kozti ures res hosszat"},
/* it */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_IT, "Imposta il numero di cicli aggiunti ad ogni gap nel tap"},
/* ko */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_NL, "Zet aantal extra cycli voor elk gat in de tap"},
/* pl */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_PL, "Okre��l liczbe cyklow dodanych do ka?dej przerwy w ta��mie"},
/* ru */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_SV, "Ange cykler som laggs till varje gap i tap-filen"},
/* tr */ {IDCLS_SET_CYCLES_ADDED_GAP_TAP_TR, "Badlanty anynda her botluk icin eklenecek cycle sayysyny ayarla"},
#endif

#ifdef DEBUG
/* debug.c */
/* en */ {IDCLS_TRACE_MAIN_CPU,    N_("Trace the main CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TRACE_MAIN_CPU_DA, "Trace hovedprocessoren"},
/* de */ {IDCLS_TRACE_MAIN_CPU_DE, "Haupt CPU verfolgen"},
/* fr */ {IDCLS_TRACE_MAIN_CPU_FR, "Tracer l'UCT principal"},
/* hu */ {IDCLS_TRACE_MAIN_CPU_HU, "Fo CPU nyomkovetese"},
/* it */ {IDCLS_TRACE_MAIN_CPU_IT, "Traccia la CPU principale"},
/* ko */ {IDCLS_TRACE_MAIN_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TRACE_MAIN_CPU_NL, "Traceer de hoofd CPU"},
/* pl */ {IDCLS_TRACE_MAIN_CPU_PL, "|ledzenie g3ownego CPU"},
/* ru */ {IDCLS_TRACE_MAIN_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TRACE_MAIN_CPU_SV, "Spara huvudprocessorn"},
/* tr */ {IDCLS_TRACE_MAIN_CPU_TR, "Ana CPU'yu izle"},
#endif

/* debug.c */
/* en */ {IDCLS_DONT_TRACE_MAIN_CPU,    N_("Do not trace the main CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_TRACE_MAIN_CPU_DA, "Trace ikke hovedprocessoren"},
/* de */ {IDCLS_DONT_TRACE_MAIN_CPU_DE, "Haupt CPU nicht verfolgen"},
/* fr */ {IDCLS_DONT_TRACE_MAIN_CPU_FR, "Ne pas tracer l'UCT principal"},
/* hu */ {IDCLS_DONT_TRACE_MAIN_CPU_HU, "Fo CPU nyomkovetesenek tiltasa"},
/* it */ {IDCLS_DONT_TRACE_MAIN_CPU_IT, "Non tracciare la CPU principale"},
/* ko */ {IDCLS_DONT_TRACE_MAIN_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_TRACE_MAIN_CPU_NL, "Traceer de hoofd CPU niet"},
/* pl */ {IDCLS_DONT_TRACE_MAIN_CPU_PL, "Bez ��ledzenia g3ownego CPU"},
/* ru */ {IDCLS_DONT_TRACE_MAIN_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_TRACE_MAIN_CPU_SV, "Spara inte huvudprocessorn"},
/* tr */ {IDCLS_DONT_TRACE_MAIN_CPU_TR, "Ana CPU'yu izleme"},
#endif

/* debug.c */
/* en */ {IDCLS_TRACE_DRIVE0_CPU,    N_("Trace the drive0 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TRACE_DRIVE0_CPU_DA, "Trace processor i drev 0"},
/* de */ {IDCLS_TRACE_DRIVE0_CPU_DE, "Laufwerk0 CPU verfolgen"},
/* fr */ {IDCLS_TRACE_DRIVE0_CPU_FR, "Tracer l'UCT du drive0"},
/* hu */ {IDCLS_TRACE_DRIVE0_CPU_HU, "A 0-s lemezegyseg CPU-janak nyomkovetese"},
/* it */ {IDCLS_TRACE_DRIVE0_CPU_IT, "Traccia la CPU del drive0"},
/* ko */ {IDCLS_TRACE_DRIVE0_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TRACE_DRIVE0_CPU_NL, "Traceer de CPU van drive 0/8"},
/* pl */ {IDCLS_TRACE_DRIVE0_CPU_PL, "|ledzenie CPU stacji0"},
/* ru */ {IDCLS_TRACE_DRIVE0_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TRACE_DRIVE0_CPU_SV, "Spara processor i diskettstation 0"},
/* tr */ {IDCLS_TRACE_DRIVE0_CPU_TR, "Surucu0 CPU'sunu izle"},
#endif

/* debug.c */
/* en */ {IDCLS_DONT_TRACE_DRIVE0_CPU,    N_("Do not trace the drive0 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_TRACE_DRIVE0_CPU_DA, "Trace ikke processor i drev 0"},
/* de */ {IDCLS_DONT_TRACE_DRIVE0_CPU_DE, "Laufwerk0 CPU nicht verfolgen"},
/* fr */ {IDCLS_DONT_TRACE_DRIVE0_CPU_FR, "Ne pas tracer l'UCT du drive0"},
/* hu */ {IDCLS_DONT_TRACE_DRIVE0_CPU_HU, "A 0-s lemezegyseg CPU-ja nyomkovetesenek tiltasa"},
/* it */ {IDCLS_DONT_TRACE_DRIVE0_CPU_IT, "Non tracciare la CPU del drive0"},
/* ko */ {IDCLS_DONT_TRACE_DRIVE0_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_TRACE_DRIVE0_CPU_NL, "Traceer de CPU van drive 0/8 niet"},
/* pl */ {IDCLS_DONT_TRACE_DRIVE0_CPU_PL, "Bez ��ledzenia CPU stacji0"},
/* ru */ {IDCLS_DONT_TRACE_DRIVE0_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_TRACE_DRIVE0_CPU_SV, "Spara inte processor i diskettstation 0"},
/* tr */ {IDCLS_DONT_TRACE_DRIVE0_CPU_TR, "Surucu0 CPU'sunu izleme"},
#endif

/* debug.c */
/* en */ {IDCLS_TRACE_DRIVE1_CPU,    N_("Trace the drive1 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TRACE_DRIVE1_CPU_DA, "Trace processor i drev 1"},
/* de */ {IDCLS_TRACE_DRIVE1_CPU_DE, "Laufwerk1 CPU verfolgen"},
/* fr */ {IDCLS_TRACE_DRIVE1_CPU_FR, "Tracer l'UCT du drive1"},
/* hu */ {IDCLS_TRACE_DRIVE1_CPU_HU, "Az 1-es lemezegyseg CPU-janak nyomkovetese"},
/* it */ {IDCLS_TRACE_DRIVE1_CPU_IT, "Traccia la CPU del drive1"},
/* ko */ {IDCLS_TRACE_DRIVE1_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TRACE_DRIVE1_CPU_NL, "Traceer de CPU van drive 1/9"},
/* pl */ {IDCLS_TRACE_DRIVE1_CPU_PL, "|ledzenie CPU stacji1"},
/* ru */ {IDCLS_TRACE_DRIVE1_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TRACE_DRIVE1_CPU_SV, "Spara processor i diskettstation 1"},
/* tr */ {IDCLS_TRACE_DRIVE1_CPU_TR, "Surucu1 CPU'sunu izle"},
#endif

/* debug.c */
/* en */ {IDCLS_DONT_TRACE_DRIVE1_CPU,    N_("Do not trace the drive1 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_TRACE_DRIVE1_CPU_DA, "Trace ikke processor i drev 1"},
/* de */ {IDCLS_DONT_TRACE_DRIVE1_CPU_DE, "Laufwerk1 CPU nicht verfolgen"},
/* fr */ {IDCLS_DONT_TRACE_DRIVE1_CPU_FR, "Ne pas tracer l'UCT du drive1"},
/* hu */ {IDCLS_DONT_TRACE_DRIVE1_CPU_HU, "Az 1-es lemezegyseg CPU-ja nyomkovetesenek tiltasa"},
/* it */ {IDCLS_DONT_TRACE_DRIVE1_CPU_IT, "Non tracciare la CPU del drive1"},
/* ko */ {IDCLS_DONT_TRACE_DRIVE1_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_TRACE_DRIVE1_CPU_NL, "Traceer de CPU van drive 1/9 niet"},
/* pl */ {IDCLS_DONT_TRACE_DRIVE1_CPU_PL, "Bez ��ledzenia CPU stacji1"},
/* ru */ {IDCLS_DONT_TRACE_DRIVE1_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_TRACE_DRIVE1_CPU_SV, "Spara inte processor i diskettstation 1"},
/* tr */ {IDCLS_DONT_TRACE_DRIVE1_CPU_TR, "Surucu1 CPU'sunu izleme"},
#endif

#if DRIVE_NUM > 2
/* debug.c */
/* en */ {IDCLS_TRACE_DRIVE2_CPU,    N_("Trace the drive2 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TRACE_DRIVE2_CPU_DA, "Trace processor i drev 2"},
/* de */ {IDCLS_TRACE_DRIVE2_CPU_DE, "Laufwerk2 CPU verfolgen"},
/* fr */ {IDCLS_TRACE_DRIVE2_CPU_FR, "Tracer l'UCT du drive2"},
/* hu */ {IDCLS_TRACE_DRIVE2_CPU_HU, "A 2-es lemezegyseg CPU-janak nyomkovetese"},
/* it */ {IDCLS_TRACE_DRIVE2_CPU_IT, "Traccia la CPU del drive2"},
/* ko */ {IDCLS_TRACE_DRIVE2_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TRACE_DRIVE2_CPU_NL, "Traceer de CPU van drive 2/10"},
/* pl */ {IDCLS_TRACE_DRIVE2_CPU_PL, "|ledzenie CPU stacji2"},
/* ru */ {IDCLS_TRACE_DRIVE2_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TRACE_DRIVE2_CPU_SV, "Spara processor i diskettstation 2"},
/* tr */ {IDCLS_TRACE_DRIVE2_CPU_TR, "Surucu2 CPU'sunu izle"},
#endif

/* debug.c */
/* en */ {IDCLS_DONT_TRACE_DRIVE2_CPU,    N_("Do not trace the drive2 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_TRACE_DRIVE2_CPU_DA, "Trace ikke processor i drev 2"},
/* de */ {IDCLS_DONT_TRACE_DRIVE2_CPU_DE, "Laufwerk2 CPU nicht verfolgen"},
/* fr */ {IDCLS_DONT_TRACE_DRIVE2_CPU_FR, "Ne pas tracer l'UCT du drive2"},
/* hu */ {IDCLS_DONT_TRACE_DRIVE2_CPU_HU, "A 2-es lemezegyseg CPU-ja nyomkovetesenek tiltasa"},
/* it */ {IDCLS_DONT_TRACE_DRIVE2_CPU_IT, "Non tracciare la CPU del drive2"},
/* ko */ {IDCLS_DONT_TRACE_DRIVE2_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_TRACE_DRIVE2_CPU_NL, "Traceer de CPU van drive 2/10 niet"},
/* pl */ {IDCLS_DONT_TRACE_DRIVE2_CPU_PL, "Bez ��ledzenia CPU stacji2"},
/* ru */ {IDCLS_DONT_TRACE_DRIVE2_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_TRACE_DRIVE2_CPU_SV, "Spara inte processor i diskettstation 2"},
/* tr */ {IDCLS_DONT_TRACE_DRIVE2_CPU_TR, "Surucu2 CPU'sunu izleme"},
#endif
#endif

#if DRIVE_NUM > 3
/* debug.c */
/* en */ {IDCLS_TRACE_DRIVE3_CPU,    N_("Trace the drive3 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TRACE_DRIVE3_CPU_DA, "Trace processor i drev 3"},
/* de */ {IDCLS_TRACE_DRIVE3_CPU_DE, "Laufwerk3 CPU verfolgen"},
/* fr */ {IDCLS_TRACE_DRIVE3_CPU_FR, "Tracer l'UCT du drive3"},
/* hu */ {IDCLS_TRACE_DRIVE3_CPU_HU, "A 3-as lemezegyseg CPU-janak nyomkovetese"},
/* it */ {IDCLS_TRACE_DRIVE3_CPU_IT, "Traccia la CPU del drive3"},
/* ko */ {IDCLS_TRACE_DRIVE3_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TRACE_DRIVE3_CPU_NL, "Traceer de CPU van drive 3/11"},
/* pl */ {IDCLS_TRACE_DRIVE3_CPU_PL, "|ledzenie CPU stacji3"},
/* ru */ {IDCLS_TRACE_DRIVE3_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TRACE_DRIVE3_CPU_SV, "Spara processor i diskettstation 3"},
/* tr */ {IDCLS_TRACE_DRIVE3_CPU_TR, "Surucu3 CPU'sunu izle"},
#endif

/* debug.c */
/* en */ {IDCLS_DONT_TRACE_DRIVE3_CPU,    N_("Do not trace the drive3 CPU")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_TRACE_DRIVE3_CPU_DA, "Trace ikke processor i drev 3"},
/* de */ {IDCLS_DONT_TRACE_DRIVE3_CPU_DE, "Laufwerk3 CPU nicht verfolgen"},
/* fr */ {IDCLS_DONT_TRACE_DRIVE3_CPU_FR, "Ne pas tracer l'UCT du drive3"},
/* hu */ {IDCLS_DONT_TRACE_DRIVE3_CPU_HU, "A 3-as lemezegyseg CPU-ja nyomkovetesenek tiltasa"},
/* it */ {IDCLS_DONT_TRACE_DRIVE3_CPU_IT, "Non tracciare la CPU del drive3"},
/* ko */ {IDCLS_DONT_TRACE_DRIVE3_CPU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_TRACE_DRIVE3_CPU_NL, "Traceer de CPU van drive 3/11 niet"},
/* pl */ {IDCLS_DONT_TRACE_DRIVE3_CPU_PL, "Bez ��ledzenia CPU stacji3"},
/* ru */ {IDCLS_DONT_TRACE_DRIVE3_CPU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_TRACE_DRIVE3_CPU_SV, "Spara inte processor i diskettstation 3"},
/* tr */ {IDCLS_DONT_TRACE_DRIVE3_CPU_TR, "Surucu3 CPU'sunu izleme"},
#endif
#endif

/* debug.c */
/* en */ {IDCLS_TRACE_MODE,    N_("Trace mode (0=normal 1=small 2=history)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_TRACE_MODE_DA, "Trace-tilstand (0=normal 1=lille 2=historik)"},
/* de */ {IDCLS_TRACE_MODE_DE, "Verfolgung Modus (0=normal 1=klein 2=Geschichte)"},
/* fr */ {IDCLS_TRACE_MODE_FR, "Mode de trace (0=normal 1=petit 2=historique)"},
/* hu */ {IDCLS_TRACE_MODE_HU, "Nyomkovetesi mod (0=normal 1=kicsi 2=elozmenyek)"},
/* it */ {IDCLS_TRACE_MODE_IT, "Modalita di tracciamento (0=normale 1=piccola 2=storica)"},
/* ko */ {IDCLS_TRACE_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_TRACE_MODE_NL, "Traceermodus (0=normaal 1=klein 2=geschiedenis"},
/* pl */ {IDCLS_TRACE_MODE_PL, "Tryb ��ledzenia (0=zwyk3e 1=ma3e 2=w historii)"},
/* ru */ {IDCLS_TRACE_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_TRACE_MODE_SV, "Sparningslage (0=normal 1=liten 2=historik)"},
/* tr */ {IDCLS_TRACE_MODE_TR, "Yzleme modu (0=normal 1=kucuk 2=tarihce)"},
#endif
#endif

/* event.c */
/* en */ {IDCLS_PLAYBACK_RECORDED_EVENTS,    N_("Playback recorded events")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PLAYBACK_RECORDED_EVENTS_DA, "Afspil handelsesoptagelse"},
/* de */ {IDCLS_PLAYBACK_RECORDED_EVENTS_DE, "Wiedergabe von aufgenommener Ereignisse"},
/* fr */ {IDCLS_PLAYBACK_RECORDED_EVENTS_FR, "Lire les evenements enregistres"},
/* hu */ {IDCLS_PLAYBACK_RECORDED_EVENTS_HU, "A felvett esemenyek visszajatszasa"},
/* it */ {IDCLS_PLAYBACK_RECORDED_EVENTS_IT, "Riproduzione eventi registrati"},
/* ko */ {IDCLS_PLAYBACK_RECORDED_EVENTS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PLAYBACK_RECORDED_EVENTS_NL, "Afspelen opgenomen gebeurtenissen"},
/* pl */ {IDCLS_PLAYBACK_RECORDED_EVENTS_PL, "Odtworz zapisane zdarzenia"},
/* ru */ {IDCLS_PLAYBACK_RECORDED_EVENTS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PLAYBACK_RECORDED_EVENTS_SV, "Spela upp inspelade handelser"},
/* tr */ {IDCLS_PLAYBACK_RECORDED_EVENTS_TR, "Kayyttan yurutme kaydedilmit olaylary"},
#endif

/* monitor.c */
/* en */ {IDCLS_EXECUTE_MONITOR_FROM_FILE,    N_("Execute monitor commands from file")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_DA, "Udfor monitorkommandoer fra fil"},
/* de */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_DE, "Monitor Kommandos aus Datei ausfuhren"},
/* fr */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_FR, "Executer des commandes moniteur depuis un fichier"},
/* hu */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_HU, "Monitorprogram parancsok futtatasa fajlbol"},
/* it */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_IT, "Esegui i comandi del monitor da un file"},
/* ko */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_NL, "Uitvoeren van commandos uit bestand"},
/* pl */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_PL, "Wykonaj polecenia monitora z pliku"},
/* ru */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_SV, "Exekvera monitorkommandon fran fil"},
/* tr */ {IDCLS_EXECUTE_MONITOR_FROM_FILE_TR, "Dosyadan monitor komutlary calyttyr"},
#endif

/* monitor.c */
/* en */ {IDCLS_SET_INITIAL_BREAKPOINT,    N_("Set an initial breakpoint for the monitor")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_INITIAL_BREAKPOINT_DA, "Sat et initielt breakpoint for monitoren"},
/* de */ {IDCLS_SET_INITIAL_BREAKPOINT_DE, "Setze initialen Breakpoint fur Monitor"},
/* fr */ {IDCLS_SET_INITIAL_BREAKPOINT_FR, "Regler un point d�farret initial pour le moniteur"},
/* hu */ {IDCLS_SET_INITIAL_BREAKPOINT_HU, "Kezdeti torespont megadasa a monitorprogramnak"},
/* it */ {IDCLS_SET_INITIAL_BREAKPOINT_IT, "Imposta un breakpoint iniziale per il monitor"},
/* ko */ {IDCLS_SET_INITIAL_BREAKPOINT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_INITIAL_BREAKPOINT_NL, "Zet een beginnende breakpunt voor de monitor"},
/* pl */ {IDCLS_SET_INITIAL_BREAKPOINT_PL, "Okre��l pocz�}tkowy punkt wstrzymania w monitorze"},
/* ru */ {IDCLS_SET_INITIAL_BREAKPOINT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_INITIAL_BREAKPOINT_SV, "Satt en ursprunglig brytpunkt for monitorn"},
/* tr */ {IDCLS_SET_INITIAL_BREAKPOINT_TR, "Monitor icin dahili bir kesme noktasy ayarla"},
#endif

/* monitor_network.c */
/* en */ {IDCLS_ENABLE_REMOTE_MONITOR,    N_("Enable remote monitor")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_REMOTE_MONITOR_DA, "Aktiver fjern-monitor"},
/* de */ {IDCLS_ENABLE_REMOTE_MONITOR_DE, "Monitor Fernsteuerung aktivieren"},
/* fr */ {IDCLS_ENABLE_REMOTE_MONITOR_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_REMOTE_MONITOR_HU, "Tavoli monitor engedelyezese"},
/* it */ {IDCLS_ENABLE_REMOTE_MONITOR_IT, "Attiva monitor remoto"},
/* ko */ {IDCLS_ENABLE_REMOTE_MONITOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_REMOTE_MONITOR_NL, "Activeer monitor afstandsbediening"},
/* pl */ {IDCLS_ENABLE_REMOTE_MONITOR_PL, "W3�}cz zdalny monitor"},
/* ru */ {IDCLS_ENABLE_REMOTE_MONITOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_REMOTE_MONITOR_SV, "Aktivera fjarrmonitor"},
/* tr */ {IDCLS_ENABLE_REMOTE_MONITOR_TR, "Uzak monitoru aktif et"},
#endif

/* monitor_network.c */
/* en */ {IDCLS_DISABLE_REMOTE_MONITOR,    N_("Disable remote monitor")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_REMOTE_MONITOR_DA, "Deaktiver fjern-monitor"},
/* de */ {IDCLS_DISABLE_REMOTE_MONITOR_DE, "Monitor Fernsteuerung deaktivieren"},
/* fr */ {IDCLS_DISABLE_REMOTE_MONITOR_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_REMOTE_MONITOR_HU, "Tavoli monitor tiltasa"},
/* it */ {IDCLS_DISABLE_REMOTE_MONITOR_IT, "Disattiva monitor remoto"},
/* ko */ {IDCLS_DISABLE_REMOTE_MONITOR_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_REMOTE_MONITOR_NL, "afstandsbediening monitor uitschakelen"},
/* pl */ {IDCLS_DISABLE_REMOTE_MONITOR_PL, "Wy3�}cz zdalny monitor"},
/* ru */ {IDCLS_DISABLE_REMOTE_MONITOR_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_REMOTE_MONITOR_SV, "Inaktivera fjarrmonitor"},
/* tr */ {IDCLS_DISABLE_REMOTE_MONITOR_TR, "Uzak monitoru pasiflettir"},
#endif

/* monitor_network.c */
/* en */ {IDCLS_REMOTE_MONITOR_ADDRESS,    N_("The local address the remote monitor should bind to")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_REMOTE_MONITOR_ADDRESS_DA, "Lokal adresse fjern-monitoren skal binde til"},
/* de */ {IDCLS_REMOTE_MONITOR_ADDRESS_DE, "Lokale Adresse fur die Monitorfernsteuerung"},
/* fr */ {IDCLS_REMOTE_MONITOR_ADDRESS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_REMOTE_MONITOR_ADDRESS_HU, "A helyi cim, amelyet a monitorprogram lefoglal"},
/* it */ {IDCLS_REMOTE_MONITOR_ADDRESS_IT, "Indirizzo locale a cui il monitor remoto dovrebbe collegarsi"},
/* ko */ {IDCLS_REMOTE_MONITOR_ADDRESS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_REMOTE_MONITOR_ADDRESS_NL, "Lokaal adres waar de afstandsbediening voor de monitor aan gebonden moet worden"},
/* pl */ {IDCLS_REMOTE_MONITOR_ADDRESS_PL, "Lokalny adres, z ktorym ma sie po3�}czya zdalny monitor"},
/* ru */ {IDCLS_REMOTE_MONITOR_ADDRESS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_REMOTE_MONITOR_ADDRESS_SV, "Lokal adress for fjarrmonitor att ansluta till"},
/* tr */ {IDCLS_REMOTE_MONITOR_ADDRESS_TR, "Uzak monitorun badlanmasy gereken lokal adres"},
#endif

/* fliplist.c */
/* en */ {IDCLS_SPECIFY_FLIP_LIST_NAME,    N_("Specify name of the flip list file image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_FLIP_LIST_NAME_DA, "Angiv navn pa bladreliste"},
/* de */ {IDCLS_SPECIFY_FLIP_LIST_NAME_DE, "Namen fur Fliplist Datei definieren"},
/* fr */ {IDCLS_SPECIFY_FLIP_LIST_NAME_FR, "Specifier le nom de l'image du fichier de groupement de disques"},
/* hu */ {IDCLS_SPECIFY_FLIP_LIST_NAME_HU, "Adja meg a lemezlista fajl nevet"},
/* it */ {IDCLS_SPECIFY_FLIP_LIST_NAME_IT, "Specifica il nome immagine del file della flip list"},
/* ko */ {IDCLS_SPECIFY_FLIP_LIST_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_FLIP_LIST_NAME_NL, "Geef de naam van het fliplijstbestand"},
/* pl */ {IDCLS_SPECIFY_FLIP_LIST_NAME_PL, "Okre��l nazwe pliku obrazu listy podmiany no��nikow"},
/* ru */ {IDCLS_SPECIFY_FLIP_LIST_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_FLIP_LIST_NAME_SV, "Ange namn pa vallistefilavbildningen"},
/* tr */ {IDCLS_SPECIFY_FLIP_LIST_NAME_TR, "Syralama listesi dosya imajy ismi belirt"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS,    N_("Show a list of the available options and exit normally")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_DA, "Vis en liste over tilgangelige parametre og afslut"},
/* de */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_DE, "Liste von verfugbaren Optionen zeigen und beenden"},
/* fr */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_FR, "Montrer une liste des options disponibles et terminer normalement"},
/* hu */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_HU, "Kilistazza a lehetseges opciokat es kilep"},
/* it */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_IT, "Mostra la lista delle opzioni disponibili ed esce"},
/* ko */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_NL, "Toon een lijst van de beschikbare opties en exit zoals normaal"},
/* pl */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_PL, "Poka? liste dostepnych polecen i normalnie wyjd?"},
/* ru */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_SV, "Visa lista over tillgangliga flaggor och avsluta normalt"},
/* tr */ {IDCLS_SHOW_COMMAND_LINE_OPTIONS_TR, "Mevcut seceneklerin listesini goster ve normal cyk"},
#endif

#if (!defined  __OS2__ && !defined __BEOS__)
/* initcmdline.c */
/* en */ {IDCLS_CONSOLE_MODE,    N_("Console mode (for music playback)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_CONSOLE_MODE_DA, "Konsoltilstand (for musikafspilning)"},
/* de */ {IDCLS_CONSOLE_MODE_DE, "Konsolenmodus (fur Musikwiedergabe)"},
/* fr */ {IDCLS_CONSOLE_MODE_FR, "Mode console (pour l'ecoute de musique)"},
/* hu */ {IDCLS_CONSOLE_MODE_HU, "Konzol mod (zene lejatszashoz)"},
/* it */ {IDCLS_CONSOLE_MODE_IT, "Modalita console (per la riproduzione musicale)"},
/* ko */ {IDCLS_CONSOLE_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_CONSOLE_MODE_NL, "Consolemodus (voor afspelen voor muziek)"},
/* pl */ {IDCLS_CONSOLE_MODE_PL, "Tryb konsolowy (do odtwarzania muzyki)"},
/* ru */ {IDCLS_CONSOLE_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_CONSOLE_MODE_SV, "Konsollage (for musikspelning)"},
/* tr */ {IDCLS_CONSOLE_MODE_TR, "Konsol modu (muzik calmak icin)"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ALLOW_CORE_DUMPS,    N_("Allow production of core dumps")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ALLOW_CORE_DUMPS_DA, "Tillad generering af core-dumps"},
/* de */ {IDCLS_ALLOW_CORE_DUMPS_DE, "Core Dumps ermoglichen"},
/* fr */ {IDCLS_ALLOW_CORE_DUMPS_FR, "Permettre la production de \"core dumps\""},
/* hu */ {IDCLS_ALLOW_CORE_DUMPS_HU, "Core dump keszites engedelyezese"},
/* it */ {IDCLS_ALLOW_CORE_DUMPS_IT, "Consente la produzione di core dump"},
/* ko */ {IDCLS_ALLOW_CORE_DUMPS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ALLOW_CORE_DUMPS_NL, "Maken van core dumps toestaan"},
/* pl */ {IDCLS_ALLOW_CORE_DUMPS_PL, "Pozwol tworzya zrzuty rdzenia"},
/* ru */ {IDCLS_ALLOW_CORE_DUMPS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ALLOW_CORE_DUMPS_SV, "Tillat skapa minnesutskrift"},
/* tr */ {IDCLS_ALLOW_CORE_DUMPS_TR, "Bellek durumunun kayytlarynyn uretilmesine izin ver"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_DONT_ALLOW_CORE_DUMPS,    N_("Do not produce core dumps")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_ALLOW_CORE_DUMPS_DA, "Lav ikke core-dumps"},
/* de */ {IDCLS_DONT_ALLOW_CORE_DUMPS_DE, "Core Dumps verhindern"},
/* fr */ {IDCLS_DONT_ALLOW_CORE_DUMPS_FR, "Ne pas produire de \"core dumps\""},
/* hu */ {IDCLS_DONT_ALLOW_CORE_DUMPS_HU, "Core dump keszites tiltasa"},
/* it */ {IDCLS_DONT_ALLOW_CORE_DUMPS_IT, "Non produce core dump"},
/* ko */ {IDCLS_DONT_ALLOW_CORE_DUMPS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_ALLOW_CORE_DUMPS_NL, "Maken van core dumps niet toestaan"},
/* pl */ {IDCLS_DONT_ALLOW_CORE_DUMPS_PL, "Nie tworz zrzutow rdzenia"},
/* ru */ {IDCLS_DONT_ALLOW_CORE_DUMPS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_ALLOW_CORE_DUMPS_SV, "Skapa inte minnesutskrift"},
/* tr */ {IDCLS_DONT_ALLOW_CORE_DUMPS_TR, "Bellek durumunun kayytlaryny uretme"},
#endif

#else

/* initcmdline.c */
/* en */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER,    N_("Don't call exception handler")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_DA, "Kald ikke exception-handler"},
/* de */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_DE, "Ausnahmebehandlung vermeiden"},
/* fr */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_FR, "Ne pas utiliser l'assistant d'exception"},
/* hu */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_HU, "Ne hivja a kivetel kezelot"},
/* it */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_IT, "Richiama il gestore delle eccezioni"},
/* ko */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_NL, "Geen gebruik maken van de exception handler"},
/* pl */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_PL, "Nie zajmuj sie wyj�}tkami"},
/* ru */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_SV, "Anropa inte undantagshanterare"},
/* tr */ {IDCLS_DONT_CALL_EXCEPTION_HANDLER_TR, "Kural dyty itleyiciyi cadyrma"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_CALL_EXCEPTION_HANDLER,    N_("Call exception handler (default)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_CALL_EXCEPTION_HANDLER_DA, "Kald exception-handler (standard)"},
/* de */ {IDCLS_CALL_EXCEPTION_HANDLER_DE, "Ausnahmebehandlung aktivieren (Default)"},
/* fr */ {IDCLS_CALL_EXCEPTION_HANDLER_FR, "Utiliser l'assistant d'exception (par defaut)"},
/* hu */ {IDCLS_CALL_EXCEPTION_HANDLER_HU, "Kivetel kezelo hivasa (alapertelmezes)"},
/* it */ {IDCLS_CALL_EXCEPTION_HANDLER_IT, "Richiama il gestore delle eccezioni (predefinito)"},
/* ko */ {IDCLS_CALL_EXCEPTION_HANDLER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_CALL_EXCEPTION_HANDLER_NL, "Gebruik maken van de exception handler (standaard)"},
/* pl */ {IDCLS_CALL_EXCEPTION_HANDLER_PL, "Zajmij sie wyj�}tkami (domy��lnie)"},
/* ru */ {IDCLS_CALL_EXCEPTION_HANDLER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_CALL_EXCEPTION_HANDLER_SV, "Anropa undantagshanterare (standard)"},
/* tr */ {IDCLS_CALL_EXCEPTION_HANDLER_TR, "Kural dyty itleyiciyi cadyr (varsayylan)"},
#endif
#endif

/* initcmdline.c */
/* en */ {IDCLS_RESTORE_DEFAULT_SETTINGS,    N_("Restore default settings")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_RESTORE_DEFAULT_SETTINGS_DA, "Gendan standardindstillinger"},
/* de */ {IDCLS_RESTORE_DEFAULT_SETTINGS_DE, "Standard Einstellungen wiederherstellen"},
/* fr */ {IDCLS_RESTORE_DEFAULT_SETTINGS_FR, "Retablir les parametres par defaut"},
/* hu */ {IDCLS_RESTORE_DEFAULT_SETTINGS_HU, "Alapertelmezes visszaallitasa"},
/* it */ {IDCLS_RESTORE_DEFAULT_SETTINGS_IT, "Ripristina impostazioni predefinite"},
/* ko */ {IDCLS_RESTORE_DEFAULT_SETTINGS_KO, "��dAuAR ?3A? o1?o?AA���}a"},
/* nl */ {IDCLS_RESTORE_DEFAULT_SETTINGS_NL, "Herstel standaard instellingen"},
/* pl */ {IDCLS_RESTORE_DEFAULT_SETTINGS_PL, "Przywroa domy��lne ustawienia"},
/* ru */ {IDCLS_RESTORE_DEFAULT_SETTINGS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_RESTORE_DEFAULT_SETTINGS_SV, "Aterstall forvalda installningar"},
/* tr */ {IDCLS_RESTORE_DEFAULT_SETTINGS_TR, "Varsayylan ayarlary geri yukle"},
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
/* pl */ {IDCLS_P_FILE_PL, "<filename>"},
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
/* hu */ {IDCLS_SPECIFY_CONFIG_FILE_HU, "Adja meg a konfiguracios fajl nevet"},
/* it */ {IDCLS_SPECIFY_CONFIG_FILE_IT, "Specifica il nome del file di configurazione"},
/* ko */ {IDCLS_SPECIFY_CONFIG_FILE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_CONFIG_FILE_NL, "Geef configuratie bestandsnaam"},
/* pl */ {IDCLS_SPECIFY_CONFIG_FILE_PL, "Okre��l plik konfiguracji"},
/* ru */ {IDCLS_SPECIFY_CONFIG_FILE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_CONFIG_FILE_SV, "Ange installningsfil"},
/* tr */ {IDCLS_SPECIFY_CONFIG_FILE_TR, "Konfigurasyon dosyasyny belirt"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AND_AUTOSTART,    N_("Attach and autostart tape/disk image <name>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AND_AUTOSTART_DA, "Tilslut og autostart band-/disk-image <navn>"},
/* de */ {IDCLS_ATTACH_AND_AUTOSTART_DE, "Einlegen und Autostart Disk/Band Image Datei <Name>"},
/* fr */ {IDCLS_ATTACH_AND_AUTOSTART_FR, "Inserer et demarrer l'image de disque/datassette <nom>"},
/* hu */ {IDCLS_ATTACH_AND_AUTOSTART_HU, "<nev> lemez/szalag kepmas csatolasa es automatikus elinditasa"},
/* it */ {IDCLS_ATTACH_AND_AUTOSTART_IT, "Seleziona ed avvia l'immagine di una cassetta/disco <nome>"},
/* ko */ {IDCLS_ATTACH_AND_AUTOSTART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AND_AUTOSTART_NL, "Koppel en autostart een tape/diskbestand <naam>"},
/* pl */ {IDCLS_ATTACH_AND_AUTOSTART_PL, "Zamontuj i automatycznie uruchom obraz ta��my lub dysku <nazwa>"},
/* ru */ {IDCLS_ATTACH_AND_AUTOSTART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AND_AUTOSTART_SV, "Anslut och starta band-/diskettavbildning <namn>"},
/* tr */ {IDCLS_ATTACH_AND_AUTOSTART_TR, "Teyp/Disk imajy <isim> yerlettir ve otomatik batlat"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AND_AUTOLOAD,    N_("Attach and autoload tape/disk image <name>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AND_AUTOLOAD_DA, "Tilslut og las band-/disk-image <navn>"},
/* de */ {IDCLS_ATTACH_AND_AUTOLOAD_DE, "Einlegen und Autoload Disk/Band Image Datei <Name>"},
/* fr */ {IDCLS_ATTACH_AND_AUTOLOAD_FR, "Inserer et charger l'image de disque/datassette <nom>"},
/* hu */ {IDCLS_ATTACH_AND_AUTOLOAD_HU, "<nev> lemez/szalag kepmas csatolasa es automatikus betoltese"},
/* it */ {IDCLS_ATTACH_AND_AUTOLOAD_IT, "Seleziona e carica l'immagine di una cassetta/disco <nome>"},
/* ko */ {IDCLS_ATTACH_AND_AUTOLOAD_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AND_AUTOLOAD_NL, "Koppel en autolaad een tape-/diskbestand <naam>"},
/* pl */ {IDCLS_ATTACH_AND_AUTOLOAD_PL, "Zamontuj i automatycznie wczytaj obraz ta��my lub dysku <nazwa>"},
/* ru */ {IDCLS_ATTACH_AND_AUTOLOAD_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AND_AUTOLOAD_SV, "Anslut och las in band-/diskettavbildning <namn>"},
/* tr */ {IDCLS_ATTACH_AND_AUTOLOAD_TR, "Teyp/Disk imajy <isim> yerlettir ve otomatik yukle"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AS_TAPE,    N_("Attach <name> as a tape image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AS_TAPE_DA, "Tilslut <navn> som band-image"},
/* de */ {IDCLS_ATTACH_AS_TAPE_DE, "Image Datei <Name> einlegen"},
/* fr */ {IDCLS_ATTACH_AS_TAPE_FR, "Inserer <nom> comme image de datassette"},
/* hu */ {IDCLS_ATTACH_AS_TAPE_HU, "<nev> szalag kepmas csatolasa"},
/* it */ {IDCLS_ATTACH_AS_TAPE_IT, "Seleziona <nome> come un'immagine di una cassetta"},
/* ko */ {IDCLS_ATTACH_AS_TAPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AS_TAPE_NL, "Koppel <naam> als een tapebestand"},
/* pl */ {IDCLS_ATTACH_AS_TAPE_PL, "Zamontuj <nazwa> jako obraz ta��my"},
/* ru */ {IDCLS_ATTACH_AS_TAPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AS_TAPE_SV, "Anslut <namn> som bandavbildning"},
/* tr */ {IDCLS_ATTACH_AS_TAPE_TR, "Teyp imajy olarak <isim> yerlettir"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AS_DISK_8,    N_("Attach <name> as a disk image in drive #8")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AS_DISK_8_DA, "Tilslut <navn> som disk-image i enhed #8"},
/* de */ {IDCLS_ATTACH_AS_DISK_8_DE, "Image Datei <Name> im Laufwerk #8 einlegen"},
/* fr */ {IDCLS_ATTACH_AS_DISK_8_FR, "Inserer <nom> comme image de disque dans le lecteur #8"},
/* hu */ {IDCLS_ATTACH_AS_DISK_8_HU, "<nev> lemezkepmas csatolasa #8-as egysegkent"},
/* it */ {IDCLS_ATTACH_AS_DISK_8_IT, "Seleziona <nome> come un'immagine di un disco nel drive #8"},
/* ko */ {IDCLS_ATTACH_AS_DISK_8_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AS_DISK_8_NL, "Koppel <naam> aan als een schijfbestand in drive #8"},
/* pl */ {IDCLS_ATTACH_AS_DISK_8_PL, "Zamontuj <nazwa> jako obraz dyskietki w stacji #8"},
/* ru */ {IDCLS_ATTACH_AS_DISK_8_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AS_DISK_8_SV, "Anslut <namn> som diskettavbildning i enhet 8"},
/* tr */ {IDCLS_ATTACH_AS_DISK_8_TR, "Surucu #8 disk imajy olarak <isim> yerlettir"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AS_DISK_9,    N_("Attach <name> as a disk image in drive #9")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AS_DISK_9_DA, "Tilslut <navn> som disk-image i enhed #9"},
/* de */ {IDCLS_ATTACH_AS_DISK_9_DE, "Image Datei <Name> im Laufwerk #9 einlegen"},
/* fr */ {IDCLS_ATTACH_AS_DISK_9_FR, "Inserer <nom> comme image de disque dans le lecteur #9"},
/* hu */ {IDCLS_ATTACH_AS_DISK_9_HU, "<nev> lemezkepmas csatolasa #9-es egysegkent"},
/* it */ {IDCLS_ATTACH_AS_DISK_9_IT, "Seleziona <nome> come un'immagine di un disco nel drive #9"},
/* ko */ {IDCLS_ATTACH_AS_DISK_9_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AS_DISK_9_NL, "Koppel <naam> aan als een schijfbestand in drive #9"},
/* pl */ {IDCLS_ATTACH_AS_DISK_9_PL, "Zamontuj <nazwa> jako obraz dyskietki w stacji #9"},
/* ru */ {IDCLS_ATTACH_AS_DISK_9_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AS_DISK_9_SV, "Anslut <namn> som diskettavbildning i enhet 9"},
/* tr */ {IDCLS_ATTACH_AS_DISK_9_TR, "Surucu #9 disk imajy olarak <isim> yerlettir"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AS_DISK_10,    N_("Attach <name> as a disk image in drive #10")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AS_DISK_10_DA, "Tilslut <navn> som disk-image i enhed #10"},
/* de */ {IDCLS_ATTACH_AS_DISK_10_DE, "Image Datei <Name> im Laufwerk #10 einlegen"},
/* fr */ {IDCLS_ATTACH_AS_DISK_10_FR, "Inserer <nom> comme image de disque dans le lecteur #10"},
/* hu */ {IDCLS_ATTACH_AS_DISK_10_HU, "<nev> lemezkepmas csatolasa #10-es egysegkent"},
/* it */ {IDCLS_ATTACH_AS_DISK_10_IT, "Seleziona <nome> come un'immagine di un disco nel drive #10"},
/* ko */ {IDCLS_ATTACH_AS_DISK_10_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AS_DISK_10_NL, "Koppel <naam> aan als een schijfbestand in drive #10"},
/* pl */ {IDCLS_ATTACH_AS_DISK_10_PL, "Zamontuj <nazwa> jako obraz dyskietki w stacji #10"},
/* ru */ {IDCLS_ATTACH_AS_DISK_10_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AS_DISK_10_SV, "Anslut <namn> som diskettavbildning i enhet 10"},
/* tr */ {IDCLS_ATTACH_AS_DISK_10_TR, "Surucu #10 disk imajy olarak <isim> yerlettir"},
#endif

/* initcmdline.c */
/* en */ {IDCLS_ATTACH_AS_DISK_11,    N_("Attach <name> as a disk image in drive #11")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_AS_DISK_11_DA, "Tilslut <navn> som disk-image i enhed #11"},
/* de */ {IDCLS_ATTACH_AS_DISK_11_DE, "Image Datei <Name> im Laufwerk #11 einlegen"},
/* fr */ {IDCLS_ATTACH_AS_DISK_11_FR, "Inserer <nom> comme image de disque dans le lecteur #11"},
/* hu */ {IDCLS_ATTACH_AS_DISK_11_HU, "<nev> lemezkepmas csatolasa #11-es egysegkent"},
/* it */ {IDCLS_ATTACH_AS_DISK_11_IT, "Seleziona <nome> come un'immagine di un disco nel drive #11"},
/* ko */ {IDCLS_ATTACH_AS_DISK_11_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_AS_DISK_11_NL, "Koppel <naam> aan als een schijfbestand in drive #11"},
/* pl */ {IDCLS_ATTACH_AS_DISK_11_PL, "Zamontuj <nazwa> jako obraz dyskietki w stacji #11"},
/* ru */ {IDCLS_ATTACH_AS_DISK_11_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_AS_DISK_11_SV, "Anslut <namn> som diskettavbildning i enhet 11"},
/* tr */ {IDCLS_ATTACH_AS_DISK_11_TR, "Surucu #11 disk imajy olarak <isim> yerlettir"},
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
/* pl */ {IDCLS_P_STRING_PL, "<string>"},
/* ru */ {IDCLS_P_STRING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_STRING_SV, "<strang>"},
/* tr */ {IDCLS_P_STRING_TR, "<yazy>"},
#endif

/* kbdbuf.c */
/* en */ {IDCLS_PUT_STRING_INTO_KEYBUF,    N_("Put the specified string into the keyboard buffer.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PUT_STRING_INTO_KEYBUF_DA, "Indsat den angivne streng i tastatur-bufferen."},
/* de */ {IDCLS_PUT_STRING_INTO_KEYBUF_DE, "Definierte Eingabe in Tastaturpuffer bereitstellen."},
/* fr */ {IDCLS_PUT_STRING_INTO_KEYBUF_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_PUT_STRING_INTO_KEYBUF_HU, "A megadott sztring elhelyezese a billentyuzet pufferben."},
/* it */ {IDCLS_PUT_STRING_INTO_KEYBUF_IT, "Metti la stringa specificata nel buffer di tastiera."},
/* ko */ {IDCLS_PUT_STRING_INTO_KEYBUF_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PUT_STRING_INTO_KEYBUF_NL, "Plaats de opgegeven string in de toetsenbordbuffer."},
/* pl */ {IDCLS_PUT_STRING_INTO_KEYBUF_PL, "Umie��a dany ci�}g znakow w buforze klawiatury."},
/* ru */ {IDCLS_PUT_STRING_INTO_KEYBUF_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PUT_STRING_INTO_KEYBUF_SV, "Lagg den angivna strangen i tangentbordsbufferten."},
/* tr */ {IDCLS_PUT_STRING_INTO_KEYBUF_TR, "Klavye arabelledine belirtilen yazyyy koy."},
#endif

/* log.c */
/* en */ {IDCLS_SPECIFY_LOG_FILE_NAME,    N_("Specify log file name")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_LOG_FILE_NAME_DA, "Angiv navn pa logfil"},
/* de */ {IDCLS_SPECIFY_LOG_FILE_NAME_DE, "Logdateiname definieren"},
/* fr */ {IDCLS_SPECIFY_LOG_FILE_NAME_FR, "Specifier le nom du fichier log"},
/* hu */ {IDCLS_SPECIFY_LOG_FILE_NAME_HU, "Adja meg a naplofajl nevet"},
/* it */ {IDCLS_SPECIFY_LOG_FILE_NAME_IT, "Specifica il nome del file di log"},
/* ko */ {IDCLS_SPECIFY_LOG_FILE_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_LOG_FILE_NAME_NL, "Geef de naam van het logbestand"},
/* pl */ {IDCLS_SPECIFY_LOG_FILE_NAME_PL, "Okre��l nazwe pliku z logiem"},
/* ru */ {IDCLS_SPECIFY_LOG_FILE_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_LOG_FILE_NAME_SV, "Ange namn pa loggfil"},
/* tr */ {IDCLS_SPECIFY_LOG_FILE_NAME_TR, "Log dosyasy ismini belirt"},
#endif

/* log.c */
/* en */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT,    N_("Enable verbose log output.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_DA, "Aktiver omstandeligt log-output"},
/* de */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_DE, "Ausfuhrliche Diagnose aktivieren."},
/* fr */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_IT, "Attiva output dei log verboso."},
/* ko */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_NL, "Activeer verbose log uitvoer."},
/* pl */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_PL, "W3�}cz drobiazgowy zapis do loga."},
/* ru */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_SV, "Aktivera pratsam loggutdata."},
/* tr */ {IDCLS_ENABLE_VERBOSE_LOG_OUTPUT_TR, "Verbose log cyktysyny aktif et."},
#endif

/* mouse.c */
/* en */ {IDCLS_ENABLE_MOUSE_GRAB,    N_("Enable mouse grab")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_MOUSE_GRAB_DA, "Aktiver overtagelse af mus"},
/* de */ {IDCLS_ENABLE_MOUSE_GRAB_DE, "Maus aktivieren"},
/* fr */ {IDCLS_ENABLE_MOUSE_GRAB_FR, "Saisir la souris"},
/* hu */ {IDCLS_ENABLE_MOUSE_GRAB_HU, "Eger elkapas engedelyezese"},
/* it */ {IDCLS_ENABLE_MOUSE_GRAB_IT, "Attiva cattura mouse"},
/* ko */ {IDCLS_ENABLE_MOUSE_GRAB_KO, "�C��?i?o �}�~�E| ��!�LECI��O CI�}a"},
/* nl */ {IDCLS_ENABLE_MOUSE_GRAB_NL, "Gebruiken van de muis inschakelen"},
/* pl */ {IDCLS_ENABLE_MOUSE_GRAB_PL, "W3�}cz przechwytywanie myszy"},
/* ru */ {IDCLS_ENABLE_MOUSE_GRAB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_MOUSE_GRAB_SV, "Aktivera fangande av mus"},
/* tr */ {IDCLS_ENABLE_MOUSE_GRAB_TR, "Mouse yakalamayy aktif et"},
#endif

/* mouse.c */
/* en */ {IDCLS_DISABLE_MOUSE_GRAB,    N_("Disable mouse grab")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_MOUSE_GRAB_DA, "Deaktiver overtagelse af mus"},
/* de */ {IDCLS_DISABLE_MOUSE_GRAB_DE, "Maus deaktivieren"},
/* fr */ {IDCLS_DISABLE_MOUSE_GRAB_FR, "Ne pas saisir la souris"},
/* hu */ {IDCLS_DISABLE_MOUSE_GRAB_HU, "Eger elkapas tiltasa"},
/* it */ {IDCLS_DISABLE_MOUSE_GRAB_IT, "Disattiva cattura mouse"},
/* ko */ {IDCLS_DISABLE_MOUSE_GRAB_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_MOUSE_GRAB_NL, "Gebruiken van de muis uitschakelen"},
/* pl */ {IDCLS_DISABLE_MOUSE_GRAB_PL, "Wy3�}cz przechwytywanie myszy"},
/* ru */ {IDCLS_DISABLE_MOUSE_GRAB_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_MOUSE_GRAB_SV, "Inaktivera fangande av mus"},
/* tr */ {IDCLS_DISABLE_MOUSE_GRAB_TR, "Mouse yakalamayy pasiflettir"},
#endif

/* mouse.c */
/* en */ {IDCLS_SELECT_MOUSE_JOY_PORT,    N_("Select the joystick port the mouse is attached to")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SELECT_MOUSE_JOY_PORT_DA, "Valg hvilken joystickport musen er tilsluttet"},
/* de */ {IDCLS_SELECT_MOUSE_JOY_PORT_DE, "Joystickport fur Maus auswahlen"},
/* fr */ {IDCLS_SELECT_MOUSE_JOY_PORT_FR, "Selectionner le port sur lequel attacher la souris"},
/* hu */ {IDCLS_SELECT_MOUSE_JOY_PORT_HU, "Valassza ki a joystick portot, ahova az eger csatolva van"},
/* it */ {IDCLS_SELECT_MOUSE_JOY_PORT_IT, "Seleziona la porta joystick a cui e collegato il mouse"},
/* ko */ {IDCLS_SELECT_MOUSE_JOY_PORT_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SELECT_MOUSE_JOY_PORT_NL, "Selecteer de joystickpoort waar de muis aan gekoppelt is"},
/* pl */ {IDCLS_SELECT_MOUSE_JOY_PORT_PL, "Wybierz port joysticka, do ktorego pod3�}czona jest mysz"},
/* ru */ {IDCLS_SELECT_MOUSE_JOY_PORT_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SELECT_MOUSE_JOY_PORT_SV, "Ange vilken spelport musen ar ansluten till"},
/* tr */ {IDCLS_SELECT_MOUSE_JOY_PORT_TR, "Mouse'un badly oldudu joystick portunu secin"},
#endif

/* mouse.c */
/* en */ {IDCLS_SELECT_MOUSE_TYPE,    N_("Select the mouse type (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddles, 4 = CX-22, 5 = ST)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SELECT_MOUSE_TYPE_DA, "Valg mussetype (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddles, 4 = CX-22, 5 = ST)"},
/* de */ {IDCLS_SELECT_MOUSE_TYPE_DE, "Maus typ wahlen (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddles, 4 = CX-22, 5 = ST)"},
/* fr */ {IDCLS_SELECT_MOUSE_TYPE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SELECT_MOUSE_TYPE_HU, "Valassza ki az eger tipusat (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddle, 4 = CX-22, 5 = ST)"},
/* it */ {IDCLS_SELECT_MOUSE_TYPE_IT, "Seleziona il tipo di mouse (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddle, 4 = CX-22, 5 = ST)"},
/* ko */ {IDCLS_SELECT_MOUSE_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SELECT_MOUSE_TYPE_NL, "Selecteer de muis soort (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddles, 4 = CX-22, 5 = ST)"},
/* pl */ {IDCLS_SELECT_MOUSE_TYPE_PL, "Ustaw typ myszy (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = pokret3a)"},
/* ru */ {IDCLS_SELECT_MOUSE_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SELECT_MOUSE_TYPE_SV, "Valj mustyp (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = paddlar, 4 = CX-22, 5 = ST)"},
/* tr */ {IDCLS_SELECT_MOUSE_TYPE_TR, "Mouse tipini secin (0 = 1351, 1 = NEOS, 2 = Amiga, 3 = Paddle, 4 = CX-22, 5 = ST)"},
#endif

/* ps2mouse.c */
/* en */ {IDCLS_ENABLE_PS2MOUSE,    N_("Enable PS/2 mouse on userport")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PS2MOUSE_DA, "Aktiver PS/2-mus pa brugerporten"},
/* de */ {IDCLS_ENABLE_PS2MOUSE_DE, "PS/2 Userport Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_PS2MOUSE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_PS2MOUSE_HU, "PS/2 eger engedelyezese a userporton"},
/* it */ {IDCLS_ENABLE_PS2MOUSE_IT, "Attiva mouse PS/2 su userport"},
/* ko */ {IDCLS_ENABLE_PS2MOUSE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_PS2MOUSE_NL, "Aktiveer emulatie van een PS/2 muis op de userport"},
/* pl */ {IDCLS_ENABLE_PS2MOUSE_PL, "W3�}cz mysz PS/2 w userporcie"},
/* ru */ {IDCLS_ENABLE_PS2MOUSE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PS2MOUSE_SV, "Aktivera PS/2-mus pa anvandarport"},
/* tr */ {IDCLS_ENABLE_PS2MOUSE_TR, "Userport uzerinde PS/2 mouse'u aktif et"},
#endif

/* ps2mouse.c */
/* en */ {IDCLS_DISABLE_PS2MOUSE,    N_("Disable PS/2 mouse on userport")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PS2MOUSE_DA, "Deaktiver PS/2-mus pa brugerporten"},
/* de */ {IDCLS_DISABLE_PS2MOUSE_DE, "PS/2 Userport Emulation deaktivieren\""},
/* fr */ {IDCLS_DISABLE_PS2MOUSE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_PS2MOUSE_HU, "PS/2 eger tiltasa a userporton"},
/* it */ {IDCLS_DISABLE_PS2MOUSE_IT, "Disattiva mouse PS/2 su userport"},
/* ko */ {IDCLS_DISABLE_PS2MOUSE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PS2MOUSE_NL, "Emulatie van een PS/2 muis op de userport uitschakelen"},
/* pl */ {IDCLS_DISABLE_PS2MOUSE_PL, "Wy3�}cz mysz PS/2 w userporcie"},
/* ru */ {IDCLS_DISABLE_PS2MOUSE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PS2MOUSE_SV, "Inaktivera PS/2-mus pa anvandarport"},
/* tr */ {IDCLS_DISABLE_PS2MOUSE_TR, "Userport uzerinde PS/2 mouse'u pasiflettir"},
#endif

/* ram.c */
/* en */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE,    N_("Set the value for the very first RAM address after powerup")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_DA, "Angiv vardien for den allerforste RAM adresse efter power-up"},
/* de */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_DE, "Wert fur erstes Byte im RAM nach Kaltstart setzen"},
/* fr */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_FR, "Specifier la valeur de la premiere adresse RAM apres la mise sous tension"},
/* hu */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_HU, "Adja meg a legelso RAM cim erteket bekapcsolas utan"},
/* it */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_IT, "Imposta il valore del primissimo indirizzo della RAM dopo l'accensione"},
/* ko */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_NL, "Zet de waarde voor het allereerste RAM adres na koude start"},
/* pl */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_PL, "Okre��l warto��a pierwszego adresu RAM po uruchomieniu"},
/* ru */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_SV, "Ange vardet pa den allra forsta RAM-adressen efter strompaslag"},
/* tr */ {IDCLS_SET_FIRST_RAM_ADDRESS_VALUE_TR, "Guc verildidinde batlangyctaki RAM adreslerine atanacak dederi belirle"},
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
/* pl */ {IDCLS_P_NUM_OF_BYTES_PL, "<num of bytes>"},
/* ru */ {IDCLS_P_NUM_OF_BYTES_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_NUM_OF_BYTES_SV, "<antal byte>"},
/* tr */ {IDCLS_P_NUM_OF_BYTES_TR, "<byte sayysy>"},
#endif

/* ram.c */
/* en */ {IDCLS_LENGTH_BLOCK_SAME_VALUE,    N_("Length of memory block initialized with the same value")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_DA, "Langde pa hukommelsesblok som initialiseres med samme vardi"},
/* de */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_DE, "Lange des Speicherblocks der mit dem gleichen Wert initialisiert ist"},
/* fr */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_FR, "Longeur du premier bloc memoire initialise avec la meme valeur"},
/* hu */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_HU, "Azonos ertekkel feltoltott memoria blokkoknak a hossza"},
/* it */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_IT, "Lunghezza del blocco di memoria inizializzato con lo stesso valore"},
/* ko */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_NL, "Geheugenblokgrootte die dezelfde waarde krijgt bij initialisatie"},
/* pl */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_PL, "D3ugo��a bloku pamieci zainicjowanego z t�} sam�} warto��ci�}"},
/* ru */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_SV, "Langd pa minnesblock som initierats med samma varde"},
/* tr */ {IDCLS_LENGTH_BLOCK_SAME_VALUE_TR, "Ayny dederle balangyc ayarlary yapylan bellek blodu uzunludu"},
#endif

/* ram.c */
/* en */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN,    N_("Length of memory block initialized with the same pattern")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_DA, "Langde pa hukommelsesblok som initialiseres med samme monster"},
/* de */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_DE, "Lange des Speicherblocks der mit dem gleichen Muster initialisiert ist"},
/* fr */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_FR, "Longeur du premier bloc memoire initialise avec le meme pattern"},
/* hu */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_HU, "Azonos mintaval feltoltott memoria blokkoknak a hossza"},
/* it */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_IT, "Lunghezza del blocco di memoria inizializzato con lo stesso pattern"},
/* ko */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_NL, "Geheugenblokgrootte met hetzelfde patroon bij initialisatie"},
/* pl */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_PL, "D3ugo��a bloku pamieci zainicjowanego z tym samym wzorcem"},
/* ru */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_SV, "Langd pa minnesblock som initierats med samma monster"},
/* tr */ {IDCLS_LENGTH_BLOCK_SAME_PATTERN_TR, "Ayny desenle balangyc ayarlary yapylan bellek blodu uzunludu"},
#endif

/* sound.c */
/* en */ {IDCLS_ENABLE_SOUND_PLAYBACK,    N_("Enable sound playback")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SOUND_PLAYBACK_DA, "Sla lydemulering til"},
/* de */ {IDCLS_ENABLE_SOUND_PLAYBACK_DE, "Sound Wiedergabe einschalten"},
/* fr */ {IDCLS_ENABLE_SOUND_PLAYBACK_FR, "Activer le son"},
/* hu */ {IDCLS_ENABLE_SOUND_PLAYBACK_HU, "Hangok engedelyezese"},
/* it */ {IDCLS_ENABLE_SOUND_PLAYBACK_IT, "Attiva riproduzione audio"},
/* ko */ {IDCLS_ENABLE_SOUND_PLAYBACK_KO, "��c?i��a CA�E1AI1e A�� ��c?e��!�LECI��O CI�}a"},
/* nl */ {IDCLS_ENABLE_SOUND_PLAYBACK_NL, "Activeer geluidsweergave"},
/* pl */ {IDCLS_ENABLE_SOUND_PLAYBACK_PL, "W3�}cz d?wiek"},
/* ru */ {IDCLS_ENABLE_SOUND_PLAYBACK_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SOUND_PLAYBACK_SV, "Aktivera ljudatergivning"},
/* tr */ {IDCLS_ENABLE_SOUND_PLAYBACK_TR, "Sesi aktif et"},
#endif

/* sound.c */
/* en */ {IDCLS_DISABLE_SOUND_PLAYBACK,    N_("Disable sound playback")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SOUND_PLAYBACK_DA, "Sla lydemulering fra"},
/* de */ {IDCLS_DISABLE_SOUND_PLAYBACK_DE, "Sound Wiedergabe ausschalten"},
/* fr */ {IDCLS_DISABLE_SOUND_PLAYBACK_FR, "Desactiver le son"},
/* hu */ {IDCLS_DISABLE_SOUND_PLAYBACK_HU, "Hangok tiltasa"},
/* it */ {IDCLS_DISABLE_SOUND_PLAYBACK_IT, "Disattiva riproduzione audio"},
/* ko */ {IDCLS_DISABLE_SOUND_PLAYBACK_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SOUND_PLAYBACK_NL, "Geluid uitschakelen"},
/* pl */ {IDCLS_DISABLE_SOUND_PLAYBACK_PL, "Wy3�}cz odtwarzanie d?wieku"},
/* ru */ {IDCLS_DISABLE_SOUND_PLAYBACK_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SOUND_PLAYBACK_SV, "Inaktivera ljudatergivning"},
/* tr */ {IDCLS_DISABLE_SOUND_PLAYBACK_TR, "Sesi pasiflettir"},
#endif

/* sound.c */
/* en */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ,    N_("Set sound sample rate to <value> Hz")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_DA, "Sat lydsamplefrekvens til <vardi> Hz"},
/* de */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_DE, "Setze Sound Sample Rate zu <Wert> Hz"},
/* fr */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_FR, "Regler le taux d'echantillonage a <valeur> Hz"},
/* hu */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_HU, "Hang mintavetelezesi rata beallitasa <ertek> Hz-re"},
/* it */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_IT, "Imposta la velocita di campionamento audio a <valore> Hz"},
/* ko */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_NL, "Zet de geluid sample rate naar <waarde> Hz"},
/* pl */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_PL, "Ustaw probkowanie sampli na <warto��a> Hz"},
/* ru */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_SV, "Satt ljudsamplingshastighet till <varde> Hz"},
/* tr */ {IDCLS_SET_SAMPLE_RATE_VALUE_HZ_TR, "Ses ornekleme hyzyny <deder> Hz olarak ayarla"},
#endif

/* sound.c */
/* en */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC,    N_("Set sound buffer size to <value> msec")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_DA, "Sat lydbufferstorrelse til <vardi> ms"},
/* de */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_DE, "Setze Source Buffer Grose zu <Wert> msek"},
/* fr */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_FR, "Regler la taille du tampon son a <valeur> ms"},
/* hu */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_HU, "A hangpuffer meretet <ertek> mp-re allitja"},
/* it */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_IT, "Imposta la dimensione del buffer audio a <valore> msec"},
/* ko */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_NL, "Zet de geluidsbuffergrootte naar <waarde> msec"},
/* pl */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_PL, "Ustaw rozmiar bufora d?wieku na <warto��a> ms"},
/* ru */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_SV, "Satt ljudbuffertstorlek till <varde> ms"},
/* tr */ {IDCLS_SET_SOUND_BUFFER_SIZE_MSEC_TR, "Ses arabellek boyutunu <deder> milisaniye olarak ayarla"},
#endif

/* sound.c */
/* en */ {IDCLS_SET_SOUND_FRAGMENT_SIZE,    N_("Set sound fragment size (0 = small, 1 = medium, 2 = large)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_DA, "Sat storrelse pa lydfragmenter (0 = lille, 1 = medium, 2 = stor)"},
/* de */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_DE, "Setze Sound Fragmentgrose (0 = klein, 1 = mittel, 2 = gros)"},
/* fr */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_IT, "Imposta la dimensione dei frammenti audio (0 = piccola, 1 = media, 2 = grande)"},
/* ko */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_NL, "Zet geluidsfragment grootte (0 = klein, 1 = matig, 2 = groot)"},
/* pl */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_PL, "Ustaw rozmiar fragmentu d?wieku (0 = ma3y, 1 = ��redni, 2 = du?y)"},
/* ru */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_SV, "Valj storlek for ljudfragment (0 = liten, 1= medium, 2 = stor)"},
/* tr */ {IDCLS_SET_SOUND_FRAGMENT_SIZE_TR, "Ses parca boyutunu ayarla (0 = kucuk, 1 = orta, 2 = buyuk)"},
#endif

/* sound.c */
/* en */ {IDCLS_SPECIFY_SOUND_DRIVER,    N_("Specify sound driver")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SOUND_DRIVER_DA, "Angiv lyddriver"},
/* de */ {IDCLS_SPECIFY_SOUND_DRIVER_DE, "Sound Treiber spezifieren"},
/* fr */ {IDCLS_SPECIFY_SOUND_DRIVER_FR, "Specifier le pilote de son"},
/* hu */ {IDCLS_SPECIFY_SOUND_DRIVER_HU, "Adja meg a hangmodul nevet"},
/* it */ {IDCLS_SPECIFY_SOUND_DRIVER_IT, "Specifica il driver audio"},
/* ko */ {IDCLS_SPECIFY_SOUND_DRIVER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SOUND_DRIVER_NL, "Geef geluidsstuurprogramma"},
/* pl */ {IDCLS_SPECIFY_SOUND_DRIVER_PL, "Okre��l sterownik d?wieku"},
/* ru */ {IDCLS_SPECIFY_SOUND_DRIVER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SOUND_DRIVER_SV, "Ange ljuddrivrutin"},
/* tr */ {IDCLS_SPECIFY_SOUND_DRIVER_TR, "Ses surucusu belirt"},
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
/* pl */ {IDCLS_P_ARGS_PL, "<args>"},
/* ru */ {IDCLS_P_ARGS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_ARGS_SV, "<flaggor>"},
/* tr */ {IDCLS_P_ARGS_TR, "<argumanlar>"},
#endif

/* sound.c */
/* en */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM,    N_("Specify initialization parameters for sound driver")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_DA, "Angiv initialiseringsparametre for lyddriver"},
/* de */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_DE, "Initialisierungsparameter des Sound Treibers spezifizieren"},
/* fr */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_FR, "Specifier les parametres d'initialisation pour le pilote son"},
/* hu */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_HU, "Adja meg a hangmodul indulasi parametereit"},
/* it */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_IT, "Specifica i parametri di inizializzazione del driver audio"},
/* ko */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_NL, "Geef de initialisatieparameters voor het geluidsstuurprogramma"},
/* pl */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_PL, "Okre��l parametry inicjalizacji sterownika d?wieku"},
/* ru */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_SV, "Ange initieringsflaggor for ljuddrivrutin"},
/* tr */ {IDCLS_SPECIFY_SOUND_DRIVER_PARAM_TR, "Ses surucusu icin batlangyc parametrelerini belirt"},
#endif

/* sound.c */
/* en */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER,    N_("Specify recording sound driver")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_DA, "Angiv driver til lydoptagelse"},
/* de */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_DE, "Sound Treiber fur Aufnahme spezifizieren"},
/* fr */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_FR, "Specifier le pilote d'enregistrement"},
/* hu */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_HU, "Adja meg a felvetelhez hasznalt hangmodult"},
/* it */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_IT, "Specifica il driver audio di registrazione"},
/* ko */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_NL, "Geef geluidsstuurprogramma voor opname"},
/* pl */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_PL, "Okre��l sterownik zapisu d?wieku"},
/* ru */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_SV, "Ange ljuddrivrutin for inspelning"},
/* tr */ {IDCLS_SPECIFY_RECORDING_SOUND_DRIVER_TR, "Ses kayyt surucusunu belirt"},
#endif

/* sound.c */
/* en */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM,    N_("Specify initialization parameters for recording sound driver")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_DA, "Angiv initialiseringsparametre for driver til lydoptagelse"},
/* de */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_DE, "Initialisierungsparameter fur Aufnahme Sound Treiber spezifieren"},
/* fr */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_FR, "Specifier les parametres d'initialisation pour le pilote d'enregistrement"},
/* hu */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_HU, "Adja meg a felvetelhez hasznalt hangmodul indulasi parametereit"},
/* it */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_IT, "Specifica i parametri di inizializzazione per il driver audio di registrazione"},
/* ko */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_NL, "Geef initialisatieparameters voor het geluidsstuurprogramma voor opname"},
/* pl */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_PL, "Okre��l parametry inicjalizacji sterownika zapisu d?wieku"},
/* ru */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_SV, "Ange initieringsflaggor for ljuddrivrutin for inspelning"},
/* tr */ {IDCLS_SPECIFY_REC_SOUND_DRIVER_PARAM_TR, "Ses kayyt surucusu icin batlangyc parametrelerini belirt"},
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
/* pl */ {IDCLS_P_SYNC_PL, "<sync>"},
/* ru */ {IDCLS_P_SYNC_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_SYNC_SV, "<synk>"},
/* tr */ {IDCLS_P_SYNC_TR, "<senkron>"},
#endif

/* sound.c */
/* en */ {IDCLS_SET_SOUND_SPEED_ADJUST,    N_("Set sound speed adjustment (0: flexible, 1: adjusting, 2: exact)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_SOUND_SPEED_ADJUST_DA, "Indstil lydjusteringshastighed (0: fleksibel, 1: justerende, 2: nojagtig)"},
/* de */ {IDCLS_SET_SOUND_SPEED_ADJUST_DE, "Setze Sound Geschwindigkeit Anpassung (0: flexibel, 1: anpassend, 2: exakt)"},
/* fr */ {IDCLS_SET_SOUND_SPEED_ADJUST_FR, "Choisir la methode d'ajustement du son (0: flexible, 1: ajuste 2: exact)"},
/* hu */ {IDCLS_SET_SOUND_SPEED_ADJUST_HU, "Adja meg a zene sebesseg igazitasat (0: rugalmas. 1: igazodo, 2: pontos)"},
/* it */ {IDCLS_SET_SOUND_SPEED_ADJUST_IT, "Imposta il tipo di adattamento della velocita audio (0: flessibile, 1: adattabile, 2: esatta)"},
/* ko */ {IDCLS_SET_SOUND_SPEED_ADJUST_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_SOUND_SPEED_ADJUST_NL, "Zet geluidssnelheid aanpassing (0: flexibel, 1: aanpassend, 2: exact)"},
/* pl */ {IDCLS_SET_SOUND_SPEED_ADJUST_PL, "Ustaw dopasowanie predko��ci d?wieku (0: elastyczne, 1: dopasowane, 2: dok3adne)"},
/* ru */ {IDCLS_SET_SOUND_SPEED_ADJUST_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_SOUND_SPEED_ADJUST_SV, "Stall in ljudhastighetsjustering (0: flexibel, 1: justerande, 2: exakt)"},
/* tr */ {IDCLS_SET_SOUND_SPEED_ADJUST_TR, "Ses hyzy ayarlamasyny yapyn (0: esnek, 1: duzeltme, 2: aynen)"},
#endif

/* sysfile.c */
/* en */ {IDCLS_P_PATH,    N_("<Path>")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_P_PATH_DA, ""},  /* fuzzy */
/* de */ {IDCLS_P_PATH_DE, "<Pfad>"},
/* fr */ {IDCLS_P_PATH_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_P_PATH_HU, ""},  /* fuzzy */
/* it */ {IDCLS_P_PATH_IT, ""},  /* fuzzy */
/* ko */ {IDCLS_P_PATH_KO, "<�}a>"},
/* nl */ {IDCLS_P_PATH_NL, "<Pad>"},
/* pl */ {IDCLS_P_PATH_PL, "<|cie?ka>"},
/* ru */ {IDCLS_P_PATH_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_PATH_SV, "<Sokvag>"},
/* tr */ {IDCLS_P_PATH_TR, ""},  /* fuzzy */
#endif

/* sysfile.c */
/* en */ {IDCLS_DEFINE_SYSTEM_FILES_PATH,    N_("Define search path to locate system files")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_DA, "Angiv sti til systemfiler"},
/* de */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_DE, "Suchpfad fur Systemdateien definieren"},
/* fr */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_FR, "Definir le chemin de recherche pour trouver les fichiers systemes"},
/* hu */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_HU, "Keresesi utvonal megadasa a rendszerfajlok megtalalasara"},
/* it */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_IT, "Definisci il path di ricerca per cercare i file di sistema"},
/* ko */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_NL, "Geef het zoek pad waar de systeem bestanden te vinden zijn"},
/* pl */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_PL, "Definiuj ��cie?ke wyszukiwania plikow systemowych"},
/* ru */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_SV, "Ange sokvag for att hitta systemfiler"},
/* tr */ {IDCLS_DEFINE_SYSTEM_FILES_PATH_TR, "Sistem dosyalarynyn konumunu belirlemek icin arama yolu tanymlayyn"},
#endif

/* traps.c */
/* en */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION,    N_("Enable general mechanisms for fast disk/tape emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_DA, "Aktiver generelle mekanismer for hurtig disk-/bandemulering"},
/* de */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_DE, "Allgemeine Mechanismen fur schnelle Disk/Band Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_FR, "Activer les mechanismes generaux pour l'emulation disque/datassette rapide"},
/* hu */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_HU, "A lemez/szalag emulaciot gyorsito mechanizmusok engedelyezese"},
/* it */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_IT, "Attiva meccanismo generale per l'emulazione veloce del disco/cassetta"},
/* ko */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_NL, "Activeer algemene methoden voor snelle disk/tape emulatie"},
/* pl */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_PL, "W3�}cz mechanizm szybkiej emulacji dysku i ta��my"},
/* ru */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_SV, "Aktivera generella mekanismer for snabb disk-/bandemulering"},
/* tr */ {IDCLS_ENABLE_TRAPS_FAST_EMULATION_TR, "Hyzly disk/teyp emulasyonu icin genel mekanizmayy aktif et"},
#endif

/* traps.c */
/* en */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION,    N_("Disable general mechanisms for fast disk/tape emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_DA, "Deaktiver generelle mekanismer for hurtig disk-/bandemulering"},
/* de */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_DE, "Allgemeine Mechanismen fur schnelle Disk/Band Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_FR, "Desactiver les mechanismes generaux pour l'emulation disque/datassette rapide"},
/* hu */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_HU, "A lemez/szalag emulaciot gyorsito mechanizmusok tiltasa"},
/* it */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_IT, "Disattiva meccanismo generale per l'emulazione veloce del disco/cassetta"},
/* ko */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_NL, "Algemene methoden voor snelle disk/tape emulatie uitschakelen"},
/* pl */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_PL, "Wy3�}cz mechanizm szybkiej emulacji dysku i ta��my"},
/* ru */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_SV, "Inaktivera generella mekanismer for snabb disk-/bandemulering"},
/* tr */ {IDCLS_DISABLE_TRAPS_FAST_EMULATION_TR, "Hyzly disk/teyp emulasyonu icin genel mekanizmayy pasiflettir"},
#endif

/* vsync.c */
/* en */ {IDCLS_LIMIT_SPEED_TO_VALUE,    N_("Limit emulation speed to specified value")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_LIMIT_SPEED_TO_VALUE_DA, "Begrans emuleringshastighed til angiven vardi"},
/* de */ {IDCLS_LIMIT_SPEED_TO_VALUE_DE, "Emulationsgeschwindigkeit auf Wert beschranken."},
/* fr */ {IDCLS_LIMIT_SPEED_TO_VALUE_FR, "Limiter la vitesse d'emulation a une valeur specifiee"},
/* hu */ {IDCLS_LIMIT_SPEED_TO_VALUE_HU, "Emulacios sebesseg lehatarolasa adott ertekre"},
/* it */ {IDCLS_LIMIT_SPEED_TO_VALUE_IT, "Limita la velocita di emulazione al valore specificato"},
/* ko */ {IDCLS_LIMIT_SPEED_TO_VALUE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_LIMIT_SPEED_TO_VALUE_NL, "Beperk emulatiesnelheid tot de opgegeven waarde"},
/* pl */ {IDCLS_LIMIT_SPEED_TO_VALUE_PL, "Ograniczaj predko��a emulacji do podanej warto��ci"},
/* ru */ {IDCLS_LIMIT_SPEED_TO_VALUE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_LIMIT_SPEED_TO_VALUE_SV, "Begransa emuleringshastighet till angivet varde"},
/* tr */ {IDCLS_LIMIT_SPEED_TO_VALUE_TR, "Emulasyon hyzyny belirtilmit deder ile limitle"},
#endif

/* vsync.c */
/* en */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES,    N_("Update every <value> frames (`0' for automatic)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_DA, "Opdater for hver <vardi> billeder (\"0\" for automatisk)"},
/* de */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_DE, "Jedes <Wert> Bild aktualisieren (`0' fur Automatik)"},
/* fr */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_FR, "Mise a jour toutes les <valeur> images (`0' pour auto.)"},
/* hu */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_HU, "Frissitsen minden <ertek> kepkocka elteltevel (0 automatikust jelent)"},
/* it */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_IT, "Aggiorna ogni <valore> frame (`0' per automatico)"},
/* ko */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_NL, "Elke <waarde> beeld vernieuwen (`0' voor automatisch)"},
/* pl */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_PL, "Aktualizuj co <warto��a> klatek (`0' - automatycznie)"},
/* ru */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_SV, "Uppdatera varje <varde> ramar (\"0\" for automatiskt)"},
/* tr */ {IDCLS_UPDATE_EVERY_VALUE_FRAMES_TR, "Her <deder> framede bir guncelle (otomatik icin `0')"},
#endif

/* vsync.c */
/* en */ {IDCLS_ENABLE_WARP_MODE,    N_("Enable warp mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_WARP_MODE_DA, "Aktiver warp-tilstand"},
/* de */ {IDCLS_ENABLE_WARP_MODE_DE, "Warp Mode aktivieren"},
/* fr */ {IDCLS_ENABLE_WARP_MODE_FR, "Activer Turbo"},
/* hu */ {IDCLS_ENABLE_WARP_MODE_HU, "Hipergyors mod engedelyezese"},
/* it */ {IDCLS_ENABLE_WARP_MODE_IT, "Attiva modalita turbo"},
/* ko */ {IDCLS_ENABLE_WARP_MODE_KO, "?uCA �Cd��a ��c?e��!�LECI��O CI�}a"},
/* nl */ {IDCLS_ENABLE_WARP_MODE_NL, "Activeer warpmodus"},
/* pl */ {IDCLS_ENABLE_WARP_MODE_PL, "W3�}cz tryb przy��pieszony (Turbo)"},
/* ru */ {IDCLS_ENABLE_WARP_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_WARP_MODE_SV, "Aktivera warplage"},
/* tr */ {IDCLS_ENABLE_WARP_MODE_TR, "Warp modu aktif et"},
#endif

/* vsync.c */
/* en */ {IDCLS_DISABLE_WARP_MODE,    N_("Disable warp mode")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_WARP_MODE_DA, "Deaktiver warp-tilstand"},
/* de */ {IDCLS_DISABLE_WARP_MODE_DE, "Warp Mode deaktivieren"},
/* fr */ {IDCLS_DISABLE_WARP_MODE_FR, "Desactiver Turbo"},
/* hu */ {IDCLS_DISABLE_WARP_MODE_HU, "Hipergyors mod tiltasa"},
/* it */ {IDCLS_DISABLE_WARP_MODE_IT, "Disattiva modalita turbo"},
/* ko */ {IDCLS_DISABLE_WARP_MODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_WARP_MODE_NL, "Warpmodus uitschakelen"},
/* pl */ {IDCLS_DISABLE_WARP_MODE_PL, "Wy3�}cz tryb przyspieszony"},
/* ru */ {IDCLS_DISABLE_WARP_MODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_WARP_MODE_SV, "Inaktivera warplage"},
/* tr */ {IDCLS_DISABLE_WARP_MODE_TR, "Warp modu pasiflettir"},
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
/* pl */ {IDCLS_P_ISO_LANGUAGE_CODE_PL, "<kod jezykowy iso>"},
/* ru */ {IDCLS_P_ISO_LANGUAGE_CODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_P_ISO_LANGUAGE_CODE_SV, "<iso-sprakkod>"},
/* tr */ {IDCLS_P_ISO_LANGUAGE_CODE_TR, "<iso dil kodu>"},
#endif

/* translate.c */
/* en */ {IDCLS_SPECIFY_ISO_LANG_CODE,    N_("Specify the iso code of the language")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_ISO_LANG_CODE_DA, "Angiv ISO-koden for sproget"},
/* de */ {IDCLS_SPECIFY_ISO_LANG_CODE_DE, "Iso Sprachcode spezifizieren"},
/* fr */ {IDCLS_SPECIFY_ISO_LANG_CODE_FR, "Specifier le code iso du langage"},
/* hu */ {IDCLS_SPECIFY_ISO_LANG_CODE_HU, "Adja meg a nyelv iso kodjat"},
/* it */ {IDCLS_SPECIFY_ISO_LANG_CODE_IT, "Specifica il codice ISO della lingua"},
/* ko */ {IDCLS_SPECIFY_ISO_LANG_CODE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_ISO_LANG_CODE_NL, "Geef de isocode van de taal"},
/* pl */ {IDCLS_SPECIFY_ISO_LANG_CODE_PL, "Okre��l kod iso jezyka"},
/* ru */ {IDCLS_SPECIFY_ISO_LANG_CODE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_ISO_LANG_CODE_SV, "Ange ISO-koden for spraket"},
/* tr */ {IDCLS_SPECIFY_ISO_LANG_CODE_TR, "Dil icin iso kodu belirt"},
#endif

/* c64/plus256k.c */
/* en */ {IDCLS_ENABLE_PLUS256K_EXPANSION,    N_("Enable the PLUS256K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PLUS256K_EXPANSION_DA, "Aktiver PLUS256K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_PLUS256K_EXPANSION_DE, "PLUS256K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_PLUS256K_EXPANSION_FR, "Activer l'expansion PLUS256K RAM"},
/* hu */ {IDCLS_ENABLE_PLUS256K_EXPANSION_HU, "PLUS256K RAM kiterjesztes engedelyezese"},
/* it */ {IDCLS_ENABLE_PLUS256K_EXPANSION_IT, "Attiva espansione RAM PLUS256K"},
/* ko */ {IDCLS_ENABLE_PLUS256K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_PLUS256K_EXPANSION_NL, "Activeer de PLUS256K geheugenuitbreiding"},
/* pl */ {IDCLS_ENABLE_PLUS256K_EXPANSION_PL, "W3�}cz rozszerzenie PLUS256K RAM"},
/* ru */ {IDCLS_ENABLE_PLUS256K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PLUS256K_EXPANSION_SV, "Aktivera PLUS256K RAM-expansion"},
/* tr */ {IDCLS_ENABLE_PLUS256K_EXPANSION_TR, "PLUS256K RAM genitletmesini aktif et"},
#endif

/* c64/plus256k.c */
/* en */ {IDCLS_DISABLE_PLUS256K_EXPANSION,    N_("Disable the PLUS256K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PLUS256K_EXPANSION_DA, "Deaktiver PLUS256K RAM-udviddelse"},
/* de */ {IDCLS_DISABLE_PLUS256K_EXPANSION_DE, "PLUS256K RAM Erweiterung deaktivieren"},
/* fr */ {IDCLS_DISABLE_PLUS256K_EXPANSION_FR, "Desactiver l'expansion PLUS256K RAM"},
/* hu */ {IDCLS_DISABLE_PLUS256K_EXPANSION_HU, "PLUS256K RAM kiterjesztes tiltasa"},
/* it */ {IDCLS_DISABLE_PLUS256K_EXPANSION_IT, "Disattiva espansione RAM PLUS256K"},
/* ko */ {IDCLS_DISABLE_PLUS256K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PLUS256K_EXPANSION_NL, "De PLUS256K geheugenuitbreiding uitschakelen"},
/* pl */ {IDCLS_DISABLE_PLUS256K_EXPANSION_PL, "Wy3�}cz rozszerzenie PLUS256K RAM"},
/* ru */ {IDCLS_DISABLE_PLUS256K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PLUS256K_EXPANSION_SV, "Inaktivera PLUS256K RAM-expansion"},
/* tr */ {IDCLS_DISABLE_PLUS256K_EXPANSION_TR, "PLUS256K RAM genitletmesini pasiflettir"},
#endif

/* c64/plus256k.c */
/* en */ {IDCLS_SPECIFY_PLUS256K_NAME,    N_("Specify name of PLUS256K image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PLUS256K_NAME_DA, "Angiv navn pa PLUS256K-image"},
/* de */ {IDCLS_SPECIFY_PLUS256K_NAME_DE, "Name der PLUS256K Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_PLUS256K_NAME_FR, "Specifier le nom de l'image PLUS256K RAM"},
/* hu */ {IDCLS_SPECIFY_PLUS256K_NAME_HU, "Adja meg a PLUS256K-s kepmas nevet"},
/* it */ {IDCLS_SPECIFY_PLUS256K_NAME_IT, "Specifica il nome immagine PLUS256K"},
/* ko */ {IDCLS_SPECIFY_PLUS256K_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PLUS256K_NAME_NL, "Geef de naam van het PLUS256K bestand"},
/* pl */ {IDCLS_SPECIFY_PLUS256K_NAME_PL, "Okre��l nazwe obrazu PLUS256K"},
/* ru */ {IDCLS_SPECIFY_PLUS256K_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PLUS256K_NAME_SV, "Ange namn pa PLUS256K-avbildning"},
/* tr */ {IDCLS_SPECIFY_PLUS256K_NAME_TR, "PLUS256K imajynyn ismini belirt"},
#endif

/* c64/plus60k.c */
/* en */ {IDCLS_ENABLE_PLUS60K_EXPANSION,    N_("Enable the PLUS60K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PLUS60K_EXPANSION_DA, "Aktiver PLUS60K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_PLUS60K_EXPANSION_DE, "PLUS60K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_PLUS60K_EXPANSION_FR, "Activer l'expansion PLUS60K RAM"},
/* hu */ {IDCLS_ENABLE_PLUS60K_EXPANSION_HU, "PLUS60K RAM bovites engedelyezese"},
/* it */ {IDCLS_ENABLE_PLUS60K_EXPANSION_IT, "Attiva espansione RAM PLUS60K"},
/* ko */ {IDCLS_ENABLE_PLUS60K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_PLUS60K_EXPANSION_NL, "Activeer de PLUS60K geheugenuitbreiding"},
/* pl */ {IDCLS_ENABLE_PLUS60K_EXPANSION_PL, "W3�}cz rozszerzenie RAM PLUS60K"},
/* ru */ {IDCLS_ENABLE_PLUS60K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PLUS60K_EXPANSION_SV, "Aktivera PLUS60K RAM-expansionen"},
/* tr */ {IDCLS_ENABLE_PLUS60K_EXPANSION_TR, "PLUS60K RAM genitletmesini aktif et"},
#endif

/* c64/plus60k.c */
/* en */ {IDCLS_DISABLE_PLUS60K_EXPANSION,    N_("Disable the PLUS60K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PLUS60K_EXPANSION_DA, "Deaktiver PLUS60K RAM-udviddelse"},
/* de */ {IDCLS_DISABLE_PLUS60K_EXPANSION_DE, "PLUS60K RAM Erweiterung deaktivieren"},
/* fr */ {IDCLS_DISABLE_PLUS60K_EXPANSION_FR, "Desactiver l'expansion PLUS60K RAM"},
/* hu */ {IDCLS_DISABLE_PLUS60K_EXPANSION_HU, "PLUS60K RAM bovites tiltasa"},
/* it */ {IDCLS_DISABLE_PLUS60K_EXPANSION_IT, "Disattiva espansione RAM PLUS60K"},
/* ko */ {IDCLS_DISABLE_PLUS60K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PLUS60K_EXPANSION_NL, "De PLUS60K geheugenuitbreiding uitschakelen"},
/* pl */ {IDCLS_DISABLE_PLUS60K_EXPANSION_PL, "Wy3�}cz rozszerzenie PLUS60K RAM"},
/* ru */ {IDCLS_DISABLE_PLUS60K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PLUS60K_EXPANSION_SV, "Inaktivera PLUS60K RAM-expansion"},
/* tr */ {IDCLS_DISABLE_PLUS60K_EXPANSION_TR, "PLUS60K RAM genitletmesini pasiflettir"},
#endif

/* c64/plus60k.c */
/* en */ {IDCLS_SPECIFY_PLUS60K_NAME,    N_("Specify name of PLUS60K image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_PLUS60K_NAME_DA, "Angiv navn pa PLUS60K-image"},
/* de */ {IDCLS_SPECIFY_PLUS60K_NAME_DE, "Name der PLUS60K Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_PLUS60K_NAME_FR, "Specifier le nom de l'image PLUS60K RAM"},
/* hu */ {IDCLS_SPECIFY_PLUS60K_NAME_HU, "Adja meg a nevet a PLUS60K kepmasnak"},
/* it */ {IDCLS_SPECIFY_PLUS60K_NAME_IT, "Specifica il nome immagine PLUS60K"},
/* ko */ {IDCLS_SPECIFY_PLUS60K_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_PLUS60K_NAME_NL, "Geef de naam van het PLUS60K bestand"},
/* pl */ {IDCLS_SPECIFY_PLUS60K_NAME_PL, "Okre��l nazwe obrazu PLUS60K"},
/* ru */ {IDCLS_SPECIFY_PLUS60K_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_PLUS60K_NAME_SV, "Ange namn pa plUS60K-avbildning"},
/* tr */ {IDCLS_SPECIFY_PLUS60K_NAME_TR, "PLUS60K imajynyn ismini belirt"},
#endif

/* c64/plus60k.c */
/* en */ {IDCLS_PLUS60K_BASE,    N_("Base address of the PLUS60K expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_PLUS60K_BASE_DA, "Baseadresse for PLUS60K-udviddelse"},
/* de */ {IDCLS_PLUS60K_BASE_DE, "Basis Adresse fur PLUS60K Erweiterung"},
/* fr */ {IDCLS_PLUS60K_BASE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_PLUS60K_BASE_HU, "A PLUS60K bovites baziscime"},
/* it */ {IDCLS_PLUS60K_BASE_IT, "Indirizzo base espansione PLUS60K"},
/* ko */ {IDCLS_PLUS60K_BASE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_PLUS60K_BASE_NL, "Basisadres van de PLUS60K geheugenuitbreiding"},
/* pl */ {IDCLS_PLUS60K_BASE_PL, "Adres bazowy rozszerzenia PLUS60K"},
/* ru */ {IDCLS_PLUS60K_BASE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_PLUS60K_BASE_SV, "Basadress for PLUS60K-expansion"},
/* tr */ {IDCLS_PLUS60K_BASE_TR, "PLUS60K genitletmesinin taban adresi"},
#endif

/* c64/c64_256k.c */
/* en */ {IDCLS_ENABLE_C64_256K_EXPANSION,    N_("Enable the 256K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_C64_256K_EXPANSION_DA, "Aktiver 256K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_C64_256K_EXPANSION_DE, "256K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_C64_256K_EXPANSION_FR, "Activer l'expansion RAM 256K"},
/* hu */ {IDCLS_ENABLE_C64_256K_EXPANSION_HU, "256K RAM kiterjesztes engedelyezese"},
/* it */ {IDCLS_ENABLE_C64_256K_EXPANSION_IT, "Attiva espansione 256K RAM"},
/* ko */ {IDCLS_ENABLE_C64_256K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_C64_256K_EXPANSION_NL, "Activeer de 256K geheugenuitbreiding"},
/* pl */ {IDCLS_ENABLE_C64_256K_EXPANSION_PL, "W3�}cz rozszerzenie 256K RAM"},
/* ru */ {IDCLS_ENABLE_C64_256K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_C64_256K_EXPANSION_SV, "Aktivera 256K RAM-expansion"},
/* tr */ {IDCLS_ENABLE_C64_256K_EXPANSION_TR, "256K RAM genitletmesini aktif et"},
#endif

/* c64/c64_256k.c */
/* en */ {IDCLS_DISABLE_C64_256K_EXPANSION,    N_("Disable the 256K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_C64_256K_EXPANSION_DA, "Deaktiver 256K RAM-udviddelse"},
/* de */ {IDCLS_DISABLE_C64_256K_EXPANSION_DE, "256K RAM Erweiterung deaktivieren"},
/* fr */ {IDCLS_DISABLE_C64_256K_EXPANSION_FR, "Desactiver l'expansion RAM 256K"},
/* hu */ {IDCLS_DISABLE_C64_256K_EXPANSION_HU, "256K RAM kiterjesztes tiltasa"},
/* it */ {IDCLS_DISABLE_C64_256K_EXPANSION_IT, "Disattiva espansione 256K RAM"},
/* ko */ {IDCLS_DISABLE_C64_256K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_C64_256K_EXPANSION_NL, "De 256K geheugenuitbreiding uitschakelen"},
/* pl */ {IDCLS_DISABLE_C64_256K_EXPANSION_PL, "Wy3�}cz rozszerzenie 256K RAM"},
/* ru */ {IDCLS_DISABLE_C64_256K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_C64_256K_EXPANSION_SV, "Inaktivera 256K RAM-expansion"},
/* tr */ {IDCLS_DISABLE_C64_256K_EXPANSION_TR, "256K RAM genitletmesini pasiflettir"},
#endif

/* c64/c64_256k.c */
/* en */ {IDCLS_SPECIFY_C64_256K_NAME,    N_("Specify name of 256K image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_C64_256K_NAME_DA, "Angiv navn pa 256K-image"},
/* de */ {IDCLS_SPECIFY_C64_256K_NAME_DE, "Name der 256K Image Datei definieren"},
/* fr */ {IDCLS_SPECIFY_C64_256K_NAME_FR, "Specifier le nom de l'image 256K"},
/* hu */ {IDCLS_SPECIFY_C64_256K_NAME_HU, "Adja meg a 256K-s kepmas nevet"},
/* it */ {IDCLS_SPECIFY_C64_256K_NAME_IT, "Specifica il nome immagine 256K"},
/* ko */ {IDCLS_SPECIFY_C64_256K_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_C64_256K_NAME_NL, "Geef de naam van het 256K bestand"},
/* pl */ {IDCLS_SPECIFY_C64_256K_NAME_PL, "Okre��l nazwe obrazu 256K"},
/* ru */ {IDCLS_SPECIFY_C64_256K_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_C64_256K_NAME_SV, "Ange namn pa 256K-avbildning"},
/* tr */ {IDCLS_SPECIFY_C64_256K_NAME_TR, "256K imajynyn ismini belirt"},
#endif

/* c64/c64_256k.c */
/* en */ {IDCLS_C64_256K_BASE,    N_("Base address of the 256K expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_C64_256K_BASE_DA, "Baseadresse for 256K-udviddelse"},
/* de */ {IDCLS_C64_256K_BASE_DE, "Basis Adresse fur 256K RAM Erweiterung"},
/* fr */ {IDCLS_C64_256K_BASE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_C64_256K_BASE_HU, "A 256K-s RAM kiterjesztes baziscime"},
/* it */ {IDCLS_C64_256K_BASE_IT, "Indirizzo base dell'espansione 256K"},
/* ko */ {IDCLS_C64_256K_BASE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_C64_256K_BASE_NL, "Basisadres van de 256K geheugenuitbreiding"},
/* pl */ {IDCLS_C64_256K_BASE_PL, "Adres bazowy rozszerzenia 256K"},
/* ru */ {IDCLS_C64_256K_BASE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_C64_256K_BASE_SV, "Basadress for 256K-expansionen"},
/* tr */ {IDCLS_C64_256K_BASE_TR, "256K genitletmesinin taban adresi"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_STB_CART,    N_("Attach raw Structured Basic cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_STB_CART_DA, "Tilslut ra Strucured BASIC-cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_STB_CART_DE, "Erweiterungsmodul Structured Basic (raw) Image einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_STB_CART_FR, "Inserer une cartouche Raw Structured Basic"},
/* hu */ {IDCLS_ATTACH_RAW_STB_CART_HU, "Structured Basic cartridge kepmas csatolasa"},
/* it */ {IDCLS_ATTACH_RAW_STB_CART_IT, "Seleziona immagine cartuccia Structured Basic"},
/* ko */ {IDCLS_ATTACH_RAW_STB_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_STB_CART_NL, "Koppel binair Structured Basic cartridge bestand aan"},
/* pl */ {IDCLS_ATTACH_RAW_STB_CART_PL, "Zamontuj surowy obraz kartrid?a Structured Basic"},
/* ru */ {IDCLS_ATTACH_RAW_STB_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_STB_CART_SV, "Anslut ra Strucured Basic-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_STB_CART_TR, "Duz yapylandyrylmyt Basic kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_SE5_CART,    N_("Attach raw 16kB Super Explode V5 cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_SE5_CART_DA, "Tilslut rat 16KB Super Explode V5 cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_SE5_CART_DE, "16kB Super Explode V5 Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_SE5_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_SE5_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_SE5_CART_IT, "Seleziona immagine cartuccia Super Explode V5 di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_SE5_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_SE5_CART_NL, "Koppel binair 16kB Super Snapshot V5 cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_SE5_CART_PL, "Zamontuj surowy obraz kartrid?a 16kB Super Explode V5"},
/* ru */ {IDCLS_ATTACH_RAW_SE5_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_SE5_CART_SV, "Anslut ra 16kB Super Explode V5-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_SE5_CART_TR, "Duz 16kB Super Explode V5 kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART,    N_("Attach raw 64kB Super Games cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_DA, "Tilslut rat 64KB Super Games cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_DE, "64kB Super Games Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_IT, "Seleziona immagine cartuccia Super Games di 64kB"},
/* ko */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_NL, "Koppel binair 64kB Super Games cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_PL, "Zamontuj surowy obraz kartrid?a 64kB Super Games"},
/* ru */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_SV, "Anslut ra 64kB-Super Games-insticksmodulfil"},
/* tr */ {IDCLS_ATTACH_RAW_SUPER_GAMES_CART_TR, "Duz 64kB Super Games kartut imajy yerlettir"},
#endif

/* c64/cart/c64cart.c */
/* en */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART,    N_("Attach raw 16kB Simons Basic cartridge image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_DA, "Tilslut rat 16KB Simons Basic cartridge image"},
/* de */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_DE, "16kB Simons Basic Image (raw) einlegen"},
/* fr */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_IT, "Seleziona immagine cartuccia Simons Basic di 16kB"},
/* ko */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_NL, "Koppel binair 16kB Simons Basic cartridge bestand"},
/* pl */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_PL, "Zamontuj surowy obraz kartrid?a 16kB Simons Basic"},
/* ru */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_SV, "Anslut ra 16kB Simons Basic-insticksmodulavbilding"},
/* tr */ {IDCLS_ATTACH_RAW_SIMONS_BASIC_CART_TR, "Duz 16kB Simons Basic kartut imajy yerlettir"},
#endif

/* plus4/plus4memcsory256k.c */
/* en */ {IDCLS_ENABLE_CS256K_EXPANSION,    N_("Enable the CSORY 256K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_CS256K_EXPANSION_DA, "Aktiver CSORY 256K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_CS256K_EXPANSION_DE, "CSORY 256K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_CS256K_EXPANSION_FR, "Activer l'expansion RAM 256K CSORY"},
/* hu */ {IDCLS_ENABLE_CS256K_EXPANSION_HU, "CSORY 256K RAM kiterjesztes engedelyezese"},
/* it */ {IDCLS_ENABLE_CS256K_EXPANSION_IT, "Attiva espansione RAM CSORY 256K"},
/* ko */ {IDCLS_ENABLE_CS256K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_CS256K_EXPANSION_NL, "Activeer de CSORY 256K geheugenuitbreiding"},
/* pl */ {IDCLS_ENABLE_CS256K_EXPANSION_PL, "W3�}cz rozszerzenie CSORY 256K RAM"},
/* ru */ {IDCLS_ENABLE_CS256K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_CS256K_EXPANSION_SV, "Aktivera CSORY 256K RAM-expansion"},
/* tr */ {IDCLS_ENABLE_CS256K_EXPANSION_TR, "CSORY 256K RAM genitletmesini aktif et"},
#endif

/* plus4/plus4memhannes256k.c */
/* en */ {IDCLS_ENABLE_H256K_EXPANSION,    N_("Enable the HANNES 256K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_H256K_EXPANSION_DA, "Aktiver HANNES 256K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_H256K_EXPANSION_DE, "HANNES 256K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_H256K_EXPANSION_FR, "Activer l'expansion RAM 256K HANNES"},
/* hu */ {IDCLS_ENABLE_H256K_EXPANSION_HU, "HANNES 256K RAM kiterjesztes engedelyezese"},
/* it */ {IDCLS_ENABLE_H256K_EXPANSION_IT, "Attiva espansione RAM HANNES 256K"},
/* ko */ {IDCLS_ENABLE_H256K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_H256K_EXPANSION_NL, "Activeer de HANNES 256K geheugenuitbreiding"},
/* pl */ {IDCLS_ENABLE_H256K_EXPANSION_PL, "W3�}cz rozszerzenie HANNES 256K RAM"},
/* ru */ {IDCLS_ENABLE_H256K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_H256K_EXPANSION_SV, "Aktivera HANNES 256K RAM-expansion"},
/* tr */ {IDCLS_ENABLE_H256K_EXPANSION_TR, "HANNES 256K RAM genitletmesini aktif et"},
#endif

/* plus4/plus4memhannes256k.c */
/* en */ {IDCLS_ENABLE_H1024K_EXPANSION,    N_("Enable the HANNES 1024K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_H1024K_EXPANSION_DA, "Aktiver HANNES 1024K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_H1024K_EXPANSION_DE, "HANNES 1024K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_H1024K_EXPANSION_FR, "Activer l'expansion RAM 1024K HANNES"},
/* hu */ {IDCLS_ENABLE_H1024K_EXPANSION_HU, "HANNES 1024K RAM kiterjesztes engedelyezese"},
/* it */ {IDCLS_ENABLE_H1024K_EXPANSION_IT, "Attiva espansione RAM HANNES 1024K"},
/* ko */ {IDCLS_ENABLE_H1024K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_H1024K_EXPANSION_NL, "Activeer de HANNES 1024K geheugenuitbreiding"},
/* pl */ {IDCLS_ENABLE_H1024K_EXPANSION_PL, "W3�}cz rozszerzenie HANNES 1024K RAM"},
/* ru */ {IDCLS_ENABLE_H1024K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_H1024K_EXPANSION_SV, "Aktivera HANNES 1024K RAM-expansion"},
/* tr */ {IDCLS_ENABLE_H1024K_EXPANSION_TR, "HANNES 1024K RAM genitletmesini aktif et"},
#endif

/* plus4/plus4memhannes256k.c */
/* en */ {IDCLS_ENABLE_H4096K_EXPANSION,    N_("Enable the HANNES 4096K RAM expansion")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_H4096K_EXPANSION_DA, "Aktiver HANNES 4096K RAM-udviddelse"},
/* de */ {IDCLS_ENABLE_H4096K_EXPANSION_DE, "HANNES 4096K RAM Erweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_H4096K_EXPANSION_FR, "Activer l'expansion RAM 4096K HANNES"},
/* hu */ {IDCLS_ENABLE_H4096K_EXPANSION_HU, "HANNES 4096K RAM kiterjesztes engedelyezese"},
/* it */ {IDCLS_ENABLE_H4096K_EXPANSION_IT, "Attiva espansione RAM HANNES 4096K"},
/* ko */ {IDCLS_ENABLE_H4096K_EXPANSION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_H4096K_EXPANSION_NL, "Activeer de HANNES 4096K geheugenuitbreiding"},
/* pl */ {IDCLS_ENABLE_H4096K_EXPANSION_PL, "W3�}cz rozszerzenie HANNES 4096K RAM"},
/* ru */ {IDCLS_ENABLE_H4096K_EXPANSION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_H4096K_EXPANSION_SV, "Aktivera HANNES 4096K RAM-expansion"},
/* tr */ {IDCLS_ENABLE_H4096K_EXPANSION_TR, "HANNES 4096K RAM genitletmesini aktif et"},
#endif

/* c64dtv/c64dtvblitter.c */
/* en */ {IDCLS_SPECIFY_DTV_REVISION,    N_("Specify DTV Revision (2: DTV2, 3: DTV3)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_DTV_REVISION_DA, "Angiv DTV-revision (2: DTV2, 3: DTV3)"},
/* de */ {IDCLS_SPECIFY_DTV_REVISION_DE, "DTV Revision definieren (2: DTV2, 3: DTV3)"},
/* fr */ {IDCLS_SPECIFY_DTV_REVISION_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_DTV_REVISION_HU, "Adja meg a DTV verziojat (2: DTV2, 3: DTV3)"},
/* it */ {IDCLS_SPECIFY_DTV_REVISION_IT, "Specifica la revisione DTV (2: DTV2, 3: DTV3)"},
/* ko */ {IDCLS_SPECIFY_DTV_REVISION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_DTV_REVISION_NL, "Geef de DTV revisie (2: DTV2, 3: DTV3)"},
/* pl */ {IDCLS_SPECIFY_DTV_REVISION_PL, "Okre��l wersje DTV (2: DTV2, 3: DTV3)"},
/* ru */ {IDCLS_SPECIFY_DTV_REVISION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_DTV_REVISION_SV, "Ange DTV-revision (2: DTV2, 3: DTV3)"},
/* tr */ {IDCLS_SPECIFY_DTV_REVISION_TR, "DTV Revizyonunu belirt (2: DTV2, 3: DTV3)"},
#endif

/* c64dtv/c64dtvblitter.c */
/* en */ {IDCLS_ENABLE_DTV_BLITTER_LOG,    N_("Enable DTV blitter logs.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DTV_BLITTER_LOG_DA, "Aktiver DTV-blitterlog."},
/* de */ {IDCLS_ENABLE_DTV_BLITTER_LOG_DE, "DTV Blitter Log aktivieren."},
/* fr */ {IDCLS_ENABLE_DTV_BLITTER_LOG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_DTV_BLITTER_LOG_HU, "DTV blit naplok engedelyezese."},
/* it */ {IDCLS_ENABLE_DTV_BLITTER_LOG_IT, "Attiva log del blitter DTV."},
/* ko */ {IDCLS_ENABLE_DTV_BLITTER_LOG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DTV_BLITTER_LOG_NL, "Aktiveer DTV blitter logs."},
/* pl */ {IDCLS_ENABLE_DTV_BLITTER_LOG_PL, "W3�}cz logi blittera DTV."},
/* ru */ {IDCLS_ENABLE_DTV_BLITTER_LOG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DTV_BLITTER_LOG_SV, "Aktivera DTV-blitterloggar."},
/* tr */ {IDCLS_ENABLE_DTV_BLITTER_LOG_TR, "DTV blitter loglaryny aktif et"},
#endif

/* c64dtv/c64dtvblitter.c */
/* en */ {IDCLS_DISABLE_DTV_BLITTER_LOG,    N_("Disable DTV blitter logs.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DTV_BLITTER_LOG_DA, "Deaktiver DTV-blitterlog."},
/* de */ {IDCLS_DISABLE_DTV_BLITTER_LOG_DE, "DTV Blitter Log deaktivieren."},
/* fr */ {IDCLS_DISABLE_DTV_BLITTER_LOG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_DTV_BLITTER_LOG_HU, "DTV blit naplok tiltasa."},
/* it */ {IDCLS_DISABLE_DTV_BLITTER_LOG_IT, "Disattiva log del blitter DTV."},
/* ko */ {IDCLS_DISABLE_DTV_BLITTER_LOG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DTV_BLITTER_LOG_NL, "DTV Blitter logs uitschakelen."},
/* pl */ {IDCLS_DISABLE_DTV_BLITTER_LOG_PL, "Wy3�}cz logi blittera DTV."},
/* ru */ {IDCLS_DISABLE_DTV_BLITTER_LOG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DTV_BLITTER_LOG_SV, "Inaktivera DTV-blitterloggar."},
/* tr */ {IDCLS_DISABLE_DTV_BLITTER_LOG_TR, "DTV blitter loglaryny pasiflettir"},
#endif

/* c64dtv/c64dtvdma.c */
/* en */ {IDCLS_ENABLE_DTV_DMA_LOG,    N_("Enable DTV DMA logs.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DTV_DMA_LOG_DA, "Aktiver DTV DMA-log."},
/* de */ {IDCLS_ENABLE_DTV_DMA_LOG_DE, "DTV DMA Logs aktivieren."},
/* fr */ {IDCLS_ENABLE_DTV_DMA_LOG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_DTV_DMA_LOG_HU, "DTV DMA naplok engedelyezese."},
/* it */ {IDCLS_ENABLE_DTV_DMA_LOG_IT, "Attiva log DMA DTV."},
/* ko */ {IDCLS_ENABLE_DTV_DMA_LOG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DTV_DMA_LOG_NL, "Aktiveer DTV DMA logs."},
/* pl */ {IDCLS_ENABLE_DTV_DMA_LOG_PL, "W3�}cz logowanie DTV DMA"},
/* ru */ {IDCLS_ENABLE_DTV_DMA_LOG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DTV_DMA_LOG_SV, "Aktivera DTV DMA-loggning."},
/* tr */ {IDCLS_ENABLE_DTV_DMA_LOG_TR, "DTV DMA loglaryny aktif et"},
#endif

/* c64dtv/c64dtvdma.c */
/* en */ {IDCLS_DISABLE_DTV_DMA_LOG,    N_("Disable DTV DMA logs.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DTV_DMA_LOG_DA, "Deaktiver DTV DMA-log."},
/* de */ {IDCLS_DISABLE_DTV_DMA_LOG_DE, "DTV DMA Logs deaktivieren."},
/* fr */ {IDCLS_DISABLE_DTV_DMA_LOG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_DTV_DMA_LOG_HU, "DTV DMA naplok tiltasa."},
/* it */ {IDCLS_DISABLE_DTV_DMA_LOG_IT, "Disattiva log DMA DTV."},
/* ko */ {IDCLS_DISABLE_DTV_DMA_LOG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DTV_DMA_LOG_NL, "DTV DMA logs uitschakelen."},
/* pl */ {IDCLS_DISABLE_DTV_DMA_LOG_PL, "Wy3�}cz logowanie DTV DMA"},
/* ru */ {IDCLS_DISABLE_DTV_DMA_LOG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DTV_DMA_LOG_SV, "Inaktivera DTV DMA-loggning."},
/* tr */ {IDCLS_DISABLE_DTV_DMA_LOG_TR, "DTV DMA loglaryny pasiflettir"},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDCLS_SPECIFY_C64DTVROM_NAME,    N_("Specify name of C64DTV ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_C64DTVROM_NAME_DA, "Angiv navn pa C64DTV-ROM-image"},
/* de */ {IDCLS_SPECIFY_C64DTVROM_NAME_DE, "Name von C64DTV ROM Datei definieren"},
/* fr */ {IDCLS_SPECIFY_C64DTVROM_NAME_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_C64DTVROM_NAME_HU, "Adja meg a C64DTV ROM kepmas nevet"},
/* it */ {IDCLS_SPECIFY_C64DTVROM_NAME_IT, "Specifica il nome immagine ROM DTV"},
/* ko */ {IDCLS_SPECIFY_C64DTVROM_NAME_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_C64DTVROM_NAME_NL, "Geef de naam van her C64DTV ROM bestand"},
/* pl */ {IDCLS_SPECIFY_C64DTVROM_NAME_PL, "Okre��l nazwe obrazu ROM C64DTV"},
/* ru */ {IDCLS_SPECIFY_C64DTVROM_NAME_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_C64DTVROM_NAME_SV, "Ange namn pa C64DTV-ROM-avbildning"},
/* tr */ {IDCLS_SPECIFY_C64DTVROM_NAME_TR, "C64DTV ROM imajynyn ismini belirt"},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDCLS_ENABLE_C64DTVROM_RW,    N_("Enable writes to C64DTV ROM image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_C64DTVROM_RW_DA, "Tillad skrivning til DTV-ROM-image"},
/* de */ {IDCLS_ENABLE_C64DTVROM_RW_DE, "Erlaube Schreibzugriff auf DTV ROM Datei"},
/* fr */ {IDCLS_ENABLE_C64DTVROM_RW_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_C64DTVROM_RW_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_C64DTVROM_RW_IT, "Attiva scrittura su immagini ROM C64DTV"},
/* ko */ {IDCLS_ENABLE_C64DTVROM_RW_KO, "C64DTV ROM AI1IAo?! ?2�}a ��!�LECI��O CI�}a"},
/* nl */ {IDCLS_ENABLE_C64DTVROM_RW_NL, "Aktiveer schrijven naar DTV ROM bestand"},
/* pl */ {IDCLS_ENABLE_C64DTVROM_RW_PL, "W3�}cz zapis do obrazu ROM C64DTV"},
/* ru */ {IDCLS_ENABLE_C64DTVROM_RW_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_C64DTVROM_RW_SV, "Aktivera skrivning till C64DTV-ROM-avbildning"},
/* tr */ {IDCLS_ENABLE_C64DTVROM_RW_TR, "C64DTV ROM imajynda yazmalary aktif et"},
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
/* pl */ {IDCLS_DISABLE_C64DTVROM_RW_PL, "Wy3�}cz zapis do obrazu ROM C64DTV"},
/* ru */ {IDCLS_DISABLE_C64DTVROM_RW_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_C64DTVROM_RW_SV, "Inaktivera skrivning till C64DTV-ROM-avbildning"},
/* tr */ {IDCLS_DISABLE_C64DTVROM_RW_TR, ""},  /* fuzzy */
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDCLS_ENABLE_DTV_FLASH_LOG,    N_("Enable DTV flash chip logs.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DTV_FLASH_LOG_DA, "Aktiver logs for DTV-flashkreds."},
/* de */ {IDCLS_ENABLE_DTV_FLASH_LOG_DE, "DTV Flashchip Log aktivieren."},
/* fr */ {IDCLS_ENABLE_DTV_FLASH_LOG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_DTV_FLASH_LOG_HU, "DTV flash chip naplok engedelyezese."},
/* it */ {IDCLS_ENABLE_DTV_FLASH_LOG_IT, "Attiva log del chip flash DTV."},
/* ko */ {IDCLS_ENABLE_DTV_FLASH_LOG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DTV_FLASH_LOG_NL, "Aktiveer DTV flash chip logs."},
/* pl */ {IDCLS_ENABLE_DTV_FLASH_LOG_PL, "W3�}cz logi uk3adu flash DTV."},
/* ru */ {IDCLS_ENABLE_DTV_FLASH_LOG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DTV_FLASH_LOG_SV, "Aktivera loggar for DTV-flashkrets."},
/* tr */ {IDCLS_ENABLE_DTV_FLASH_LOG_TR, "DTV flash cip loglaryny aktif et."},
#endif

/* c64dtv/c64dtvflash.c */
/* en */ {IDCLS_DISABLE_DTV_FLASH_LOG,    N_("Disable DTV flash chip logs.")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DTV_FLASH_LOG_DA, "Deaktiver logs for DTV-flashkreds."},
/* de */ {IDCLS_DISABLE_DTV_FLASH_LOG_DE, "DTV Flashchip Log deaktivieren."},
/* fr */ {IDCLS_DISABLE_DTV_FLASH_LOG_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_DTV_FLASH_LOG_HU, "DTV flash chip naplok tiltasa."},
/* it */ {IDCLS_DISABLE_DTV_FLASH_LOG_IT, "Disattiva log del chip flash DTV."},
/* ko */ {IDCLS_DISABLE_DTV_FLASH_LOG_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DTV_FLASH_LOG_NL, "DTV flash chip logs uitschakelen."},
/* pl */ {IDCLS_DISABLE_DTV_FLASH_LOG_PL, "Wy3�}cz logi uk3adu flash DTV."},
/* ru */ {IDCLS_DISABLE_DTV_FLASH_LOG_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DTV_FLASH_LOG_SV, "Inaktivera loggar for DTV-flashkrets."},
/* tr */ {IDCLS_DISABLE_DTV_FLASH_LOG_TR, "DTV flash cip loglaryny pasiflettir."},
#endif

/* c64dtv/flash-trap.c */
/* en */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS,    N_("Use <name> as directory for flash file system device")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_DA, "Brug <navn> som katalog for filsystembaseret flashenhed"},
/* de */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_DE, "Benutze <Name> fur Verzeichnis Gerat Flash Dateisystem"},
/* fr */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_HU, "<nev> konyvtar hasznalata a flash fajlrendszer eszkozhoz"},
/* it */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_IT, "Una <nome> come directory per il file system flash"},
/* ko */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_NL, "Gebruik <naam> als directory voor het flash bestandssysteem apparaat"},
/* pl */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_PL, "U?yj <nazwa> jako katalogu urz�}dzenia systemu plikow flash"},
/* ru */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_SV, "Ange <namn> som katalog for filsystemsbaserad flashenhet"},
/* tr */ {IDCLS_USE_AS_DIRECTORY_FLASH_FS_TR, "Flash dosya sistem aygyty icin <isim>'i dizin olarak kullan"},
#endif

/* c64dtv/flash-trap.c */
/* en */ {IDCLS_ENABLE_TRUE_FLASH_FS,    N_("Enable true hardware flash file system")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_TRUE_FLASH_FS_DA, "Aktiver agte hardwareemulering af flashfilsystem"},
/* de */ {IDCLS_ENABLE_TRUE_FLASH_FS_DE, "Prazises Hardware Flashdateisystem aktivieren"},
/* fr */ {IDCLS_ENABLE_TRUE_FLASH_FS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_TRUE_FLASH_FS_HU, "Igazi hardver flash fajlrendszer engedelyezese"},
/* it */ {IDCLS_ENABLE_TRUE_FLASH_FS_IT, "Attiva emulazione hardware del file system flash"},
/* ko */ {IDCLS_ENABLE_TRUE_FLASH_FS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_TRUE_FLASH_FS_NL, "Activeer hardwarmatige flash bestandssysteem"},
/* pl */ {IDCLS_ENABLE_TRUE_FLASH_FS_PL, "W3�}cz prawdziwy sprzetowy system plikow flash"},
/* ru */ {IDCLS_ENABLE_TRUE_FLASH_FS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_TRUE_FLASH_FS_SV, "Aktivera akta maskinvaru-flashfilsystem"},
/* tr */ {IDCLS_ENABLE_TRUE_FLASH_FS_TR, "Gercek donanym flash dosya sistemini aktif et"},
#endif

/* c64dtv/flash-trap.c */
/* en */ {IDCLS_DISABLE_TRUE_FLASH_FS,    N_("Disable true hardware flash file system")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_TRUE_FLASH_FS_DA, "Deaktiver agte hardwareemulering af flashfilsystem"},
/* de */ {IDCLS_DISABLE_TRUE_FLASH_FS_DE, "Prazises Hardware Flashdateisystem deaktivieren"},
/* fr */ {IDCLS_DISABLE_TRUE_FLASH_FS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_TRUE_FLASH_FS_HU, "Igazi hardver flash fajlrendszer tiltasa"},
/* it */ {IDCLS_DISABLE_TRUE_FLASH_FS_IT, "Disattiva emulazione hardware del file system flash"},
/* ko */ {IDCLS_DISABLE_TRUE_FLASH_FS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_TRUE_FLASH_FS_NL, "Hardwatematig flash bestandssysteem uitschakelen"},
/* pl */ {IDCLS_DISABLE_TRUE_FLASH_FS_PL, "Wy3�}cz prawdziwy system plikow flash"},
/* ru */ {IDCLS_DISABLE_TRUE_FLASH_FS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_TRUE_FLASH_FS_SV, "Inaktivera maskinvaruemelring for flashfilsystem"},
/* tr */ {IDCLS_DISABLE_TRUE_FLASH_FS_TR, "Gercek donanym flash dosya sistemini pasiflettir"},
#endif

#ifdef HAVE_MIDI
/* midi.c */
/* en */ {IDCLS_ENABLE_MIDI_EMU,    N_("Enable MIDI emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_MIDI_EMU_DA, "Aktiver MIDI-emulering"},
/* de */ {IDCLS_ENABLE_MIDI_EMU_DE, "MIDI Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_MIDI_EMU_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_MIDI_EMU_HU, "MIDI emulacio engedelyezese"},
/* it */ {IDCLS_ENABLE_MIDI_EMU_IT, "Attiva emulazione MIDI"},
/* ko */ {IDCLS_ENABLE_MIDI_EMU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_MIDI_EMU_NL, "Activeer MIDI emulatie"},
/* pl */ {IDCLS_ENABLE_MIDI_EMU_PL, "W3�}cz emulacje MIDI"},
/* ru */ {IDCLS_ENABLE_MIDI_EMU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_MIDI_EMU_SV, "Aktivera MIDI-emulering"},
/* tr */ {IDCLS_ENABLE_MIDI_EMU_TR, "MIDI emulasyonunu aktif et"},
#endif

/* midi.c */
/* en */ {IDCLS_DISABLE_MIDI_EMU,    N_("Disable MIDI emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_MIDI_EMU_DA, "Deaktiver MIDI-emulering"},
/* de */ {IDCLS_DISABLE_MIDI_EMU_DE, "MIDI Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_MIDI_EMU_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_MIDI_EMU_HU, "MIDI emulacio tiltasa"},
/* it */ {IDCLS_DISABLE_MIDI_EMU_IT, "Disattiva emulazione MIDI"},
/* ko */ {IDCLS_DISABLE_MIDI_EMU_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_MIDI_EMU_NL, "MIDI emulatie uitschakelen"},
/* pl */ {IDCLS_DISABLE_MIDI_EMU_PL, "Wy3�}cz emulacje MIDI"},
/* ru */ {IDCLS_DISABLE_MIDI_EMU_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_MIDI_EMU_SV, "Inaktivera MIDI-emulering"},
/* tr */ {IDCLS_DISABLE_MIDI_EMU_TR, "MIDI emulasyonunu pasiflettir"},
#endif

/* c64/cart/c64-midi.c */
/* en */ {IDCLS_SPECIFY_C64_MIDI_TYPE,    N_("MIDI interface type (0: Sequential, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SPECIFY_C64_MIDI_TYPE_DA, "MIDI-interfacetype (0: Sekventiel, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
/* de */ {IDCLS_SPECIFY_C64_MIDI_TYPE_DE, "MIDI Interface Typ (0: Sequential, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
/* fr */ {IDCLS_SPECIFY_C64_MIDI_TYPE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SPECIFY_C64_MIDI_TYPE_HU, "MIDI interfesz tipus (0: soros, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
/* it */ {IDCLS_SPECIFY_C64_MIDI_TYPE_IT, "Tipo interfaccia MIDI (0: Sequential, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
/* ko */ {IDCLS_SPECIFY_C64_MIDI_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SPECIFY_C64_MIDI_TYPE_NL, "MIDI interface soort (0: Sequential, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
/* pl */ {IDCLS_SPECIFY_C64_MIDI_TYPE_PL, "Typ interfejsu MIDI (0: Sequential, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
/* ru */ {IDCLS_SPECIFY_C64_MIDI_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SPECIFY_C64_MIDI_TYPE_SV, "Typ av MIDI-granssnitt (0: sekventiell, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
/* tr */ {IDCLS_SPECIFY_C64_MIDI_TYPE_TR, "MIDI arabirim tipi (0: Sequential, 1: Passport, 2: DATEL, 3: Namesoft, 4: Maplin)"},
#endif
#endif

/* plus4/digiblaster.c */
/* en */ {IDCLS_ENABLE_DIGIBLASTER,    N_("Enable the digiblaster add-on")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DIGIBLASTER_DA, "Aktiver digiblaster-tilfojelse"},
/* de */ {IDCLS_ENABLE_DIGIBLASTER_DE, "Digiblaster add-on aktivieren"},
/* fr */ {IDCLS_ENABLE_DIGIBLASTER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_DIGIBLASTER_HU, "Digiblaster engedelyezese"},
/* it */ {IDCLS_ENABLE_DIGIBLASTER_IT, "Attiva l'estensione digiblaster"},
/* ko */ {IDCLS_ENABLE_DIGIBLASTER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DIGIBLASTER_NL, "Activeer de digiblaster add-on"},
/* pl */ {IDCLS_ENABLE_DIGIBLASTER_PL, "W3�}cz dodatek digiblaster"},
/* ru */ {IDCLS_ENABLE_DIGIBLASTER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DIGIBLASTER_SV, "Aktivera digiblaster-tillagg"},
/* tr */ {IDCLS_ENABLE_DIGIBLASTER_TR, "Digiblaster eklentisini aktif et"},
#endif

/* plus4/digiblaster.c */
/* en */ {IDCLS_DISABLE_DIGIBLASTER,    N_("Disable the digiblaster add-on")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DIGIBLASTER_DA, "Deaktiver digiblaster-tilfojelse"},
/* de */ {IDCLS_DISABLE_DIGIBLASTER_DE, "Digiblaster add-on deaktivieren"},
/* fr */ {IDCLS_DISABLE_DIGIBLASTER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_DIGIBLASTER_HU, "Digiblaster tiltasa"},
/* it */ {IDCLS_DISABLE_DIGIBLASTER_IT, "Disattiva l'estensione digiblaster"},
/* ko */ {IDCLS_DISABLE_DIGIBLASTER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DIGIBLASTER_NL, "De digiblaster add-on uitschakelen"},
/* pl */ {IDCLS_DISABLE_DIGIBLASTER_PL, "Wy3�}cz dodatek digiblaster"},
/* ru */ {IDCLS_DISABLE_DIGIBLASTER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DIGIBLASTER_SV, "Inaktivera digiblaster-tillagg"},
/* tr */ {IDCLS_DISABLE_DIGIBLASTER_TR, "Digiblaster eklentisini pasiflettir"},
#endif

/* plus4/plus4speech.c */
/* en */ {IDCLS_ENABLE_PLUS4SPEECH,    N_("Enable the v364 speech add-on")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_PLUS4SPEECH_DA, "Aktiver v364 Speech-tilfojelse"},
/* de */ {IDCLS_ENABLE_PLUS4SPEECH_DE, "v364 Spracherweiterung aktivieren"},
/* fr */ {IDCLS_ENABLE_PLUS4SPEECH_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_PLUS4SPEECH_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_PLUS4SPEECH_IT, "Attiva l'estensione v364 speech"},
/* ko */ {IDCLS_ENABLE_PLUS4SPEECH_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_PLUS4SPEECH_NL, "Activeer de v364 spraak add-on"},
/* pl */ {IDCLS_ENABLE_PLUS4SPEECH_PL, "W3�}cz rozszerzenie mowy v364"},
/* ru */ {IDCLS_ENABLE_PLUS4SPEECH_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_PLUS4SPEECH_SV, "Aktivera v364-rosttillagg"},
/* tr */ {IDCLS_ENABLE_PLUS4SPEECH_TR, "V364 speech eklentisini aktif et"},
#endif

/* plus4/plus4speech.c */
/* en */ {IDCLS_DISABLE_PLUS4SPEECH,    N_("Disable the v364 speech add-on")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_PLUS4SPEECH_DA, "Deaktiver v364 Speech-tilfojelse"},
/* de */ {IDCLS_DISABLE_PLUS4SPEECH_DE, "v364 Spracherweiterung deaktivieren"},
/* fr */ {IDCLS_DISABLE_PLUS4SPEECH_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_PLUS4SPEECH_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_PLUS4SPEECH_IT, "Disattiva l'estensione v364 speech"},
/* ko */ {IDCLS_DISABLE_PLUS4SPEECH_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_PLUS4SPEECH_NL, "De v364 spraak add-on uitschakelen"},
/* pl */ {IDCLS_DISABLE_PLUS4SPEECH_PL, "Wy3�}cz rozszerzenie mowy v364"},
/* ru */ {IDCLS_DISABLE_PLUS4SPEECH_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_PLUS4SPEECH_SV, "Inaktivera v364-rosttillagg"},
/* tr */ {IDCLS_DISABLE_PLUS4SPEECH_TR, "V364 speech eklentisini pasiflettir"},
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
/* pl */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_PL, "Zamontuj obraz Speech ROM"},
/* ru */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_SV, "Anslut rost-ROM-avbildning"},
/* tr */ {IDCLS_ATTACH_SPEECH_ROM_IMAGE_TR, "Speech ROM imajyny yerlettir"},
#endif

/* plus4/sidcartjoy.c */
/* en */ {IDCLS_ENABLE_SIDCARTJOY,    N_("Enable SID cartridge joystick")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SIDCARTJOY_DA, "Aktiver SID-cartridge joystick"},
/* de */ {IDCLS_ENABLE_SIDCARTJOY_DE, "SIDcart Modul aktivieren"},
/* fr */ {IDCLS_ENABLE_SIDCARTJOY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_SIDCARTJOY_HU, "SID cartridge botkormany engedelyezese"},
/* it */ {IDCLS_ENABLE_SIDCARTJOY_IT, "Attiva joystick su cartuccia SID"},
/* ko */ {IDCLS_ENABLE_SIDCARTJOY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SIDCARTJOY_NL, "Activeer SID cartridge joystick"},
/* pl */ {IDCLS_ENABLE_SIDCARTJOY_PL, "W3�}cz joystick kartrid?a SID"},
/* ru */ {IDCLS_ENABLE_SIDCARTJOY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SIDCARTJOY_SV, "Aktivera SID-insticksmodul-styrspak"},
/* tr */ {IDCLS_ENABLE_SIDCARTJOY_TR, "SID kartutu joystick'ini aktif et"},
#endif

/* plus4/sidcartjoy.c */
/* en */ {IDCLS_DISABLE_SIDCARTJOY,    N_("Disable SID cartridge joystick")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SIDCARTJOY_DA, "Deaktiver SID-cartridge joystick"},
/* de */ {IDCLS_DISABLE_SIDCARTJOY_DE, "SIDcart Modul deaktivieren"},
/* fr */ {IDCLS_DISABLE_SIDCARTJOY_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_SIDCARTJOY_HU, "SID cartridge botkormany tiltasa"},
/* it */ {IDCLS_DISABLE_SIDCARTJOY_IT, "Disattiva joystick su cartuccia SID"},
/* ko */ {IDCLS_DISABLE_SIDCARTJOY_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SIDCARTJOY_NL, "De SID cartridge joystick uitschakelen"},
/* pl */ {IDCLS_DISABLE_SIDCARTJOY_PL, "Wy3�}cz joystick kartrid?a SID"},
/* ru */ {IDCLS_DISABLE_SIDCARTJOY_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SIDCARTJOY_SV, "Inaktivera SID-insticksmodul-styrspak"},
/* tr */ {IDCLS_DISABLE_SIDCARTJOY_TR, "SID kartutu joystick'ini pasiflettir"},
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
/* pl */ {IDCLS_ENABLE_SFX_SE_PL, "W3�}cz kartrid? SFX Sound Expander"},
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
/* pl */ {IDCLS_DISABLE_SFX_SE_PL, "Wy3�}cz kartrid? SFX Sound Expander"},
/* ru */ {IDCLS_DISABLE_SFX_SE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SFX_SE_SV, "Inaktivera SFX Sound Expander-insticksmodul"},
/* tr */ {IDCLS_DISABLE_SFX_SE_TR, ""},  /* fuzzy */
#endif

/* c64/cart/sfx_soundexpander.c */
/* en */ {IDCLS_SET_YM_CHIP_TYPE,    N_("Set YM chip type (3526 / 3812)")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_YM_CHIP_TYPE_DA, "Valg YM chiptype"},
/* de */ {IDCLS_SET_YM_CHIP_TYPE_DE, "YM Chip Typ (3526 / 3812) bestimmen"},
/* fr */ {IDCLS_SET_YM_CHIP_TYPE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_YM_CHIP_TYPE_HU, "YM csip tipus megadasa (3526 / 3812)"},
/* it */ {IDCLS_SET_YM_CHIP_TYPE_IT, "Imposta tipo chip YM (3526 / 3812)"},
/* ko */ {IDCLS_SET_YM_CHIP_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_YM_CHIP_TYPE_NL, "Kies de YM chip soort (3526 / 3812)"},
/* pl */ {IDCLS_SET_YM_CHIP_TYPE_PL, "Okre��l typ uk3adu YM (3526 / 3812)"},
/* ru */ {IDCLS_SET_YM_CHIP_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_YM_CHIP_TYPE_SV, "Valj YM-kretstyp (3526 / 3812)"},
/* tr */ {IDCLS_SET_YM_CHIP_TYPE_TR, "YM cip tipini ayarla (3526 / 3812)"},
#endif

/* c64/cart/sfx_soundsampler.c */
/* en */ {IDCLS_ENABLE_SFX_SS,    N_("Enable the SFX Sound Sampler cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_SFX_SS_DA, "Aktiver SFX Sound Sampler cartridge"},
/* de */ {IDCLS_ENABLE_SFX_SS_DE, "SFX Sound Sampler Modul aktivieren"},
/* fr */ {IDCLS_ENABLE_SFX_SS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_SFX_SS_HU, "SFX Sound Sampler engedelyezese"},
/* it */ {IDCLS_ENABLE_SFX_SS_IT, "Attiva cartuccia SFX Sound Sampler"},
/* ko */ {IDCLS_ENABLE_SFX_SS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_SFX_SS_NL, "Activeer de SFX Sound Sampler cartridge"},
/* pl */ {IDCLS_ENABLE_SFX_SS_PL, "W3�}cz kartrid? SFX Sound Sampler"},
/* ru */ {IDCLS_ENABLE_SFX_SS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_SFX_SS_SV, "Aktivera SFX Sound Sampler-insticksmodul"},
/* tr */ {IDCLS_ENABLE_SFX_SS_TR, "SFX Sound Sampler kartutunu aktif et"},
#endif

/* c64/cart/sfx_soundsampler.c */
/* en */ {IDCLS_DISABLE_SFX_SS,    N_("Disable the SFX Sound Sampler cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_SFX_SS_DA, "Deaktiver SFX Sound Sampler cartridge"},
/* de */ {IDCLS_DISABLE_SFX_SS_DE, "SFX Sound Sampler Modul  deaktivieren"},
/* fr */ {IDCLS_DISABLE_SFX_SS_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_SFX_SS_HU, "SFX Sound Sampler tiltasa"},
/* it */ {IDCLS_DISABLE_SFX_SS_IT, "Disattiva cartuccia SFX Sound Sampler"},
/* ko */ {IDCLS_DISABLE_SFX_SS_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_SFX_SS_NL, "De SFX Sound Sampler cartridge uitschakelen"},
/* pl */ {IDCLS_DISABLE_SFX_SS_PL, "Wy3�}cz kartrid? SFX Sound Sampler"},
/* ru */ {IDCLS_DISABLE_SFX_SS_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_SFX_SS_SV, "Inaktivera SFX Sound Sampler-insticksmodul"},
/* tr */ {IDCLS_DISABLE_SFX_SS_TR, "SFX Sound Sampler kartutunu pasiflettir"},
#endif

/* lightpen.c */
/* en */ {IDCLS_ENABLE_LIGHTPEN_EMULATION,    N_("Enable lightpen emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_DA, "Aktiver lyspen-emulering"},
/* de */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_DE, "Lichtgriffel Emulation aktivieren"},
/* fr */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_HU, "Fenyceruza emulacio engedelyezese"},
/* it */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_IT, "Attiva emulazione della penna ottica"},
/* ko */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_KO, "��oAIARAa ?!1���E1?iAI ��c?e��!�LEAE CI�}a"},
/* nl */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_NL, "Activeer de lichtpen emulatie"},
/* pl */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_PL, "W3�}cz emulacje piora ��wietlnego"},
/* ru */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_SV, "Aktivera emulering av ljuspenna"},
/* tr */ {IDCLS_ENABLE_LIGHTPEN_EMULATION_TR, "Itykly Kalem emulasyonunu aktif et"},
#endif

/* lightpen.c */
/* en */ {IDCLS_DISABLE_LIGHTPEN_EMULATION,    N_("Disable lightpen emulation")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_DA, "Deaktiver lyspen-emulering"},
/* de */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_DE, "Lichtgriffel Emulation deaktivieren"},
/* fr */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_HU, "Fenyceruza emulacio tiltasa"},
/* it */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_IT, "Disattiva emulazione della penna ottica"},
/* ko */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_NL, "De lichtpen emulatie uitschakelen"},
/* pl */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_PL, "Wy3�}cz emulacje piora ��wietlnego"},
/* ru */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_SV, "Inaktivera emulering ljuspenna"},
/* tr */ {IDCLS_DISABLE_LIGHTPEN_EMULATION_TR, "Itykly Kalem emulasyonunu pasiflettir"},
#endif

/* lightpen.c */
/* en */ {IDCLS_SET_LIGHTPEN_TYPE,    N_("Set lightpen type")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_SET_LIGHTPEN_TYPE_DA, "Angiv lyspen-type"},
/* de */ {IDCLS_SET_LIGHTPEN_TYPE_DE, "Lichtgriffel Type bestimmen"},
/* fr */ {IDCLS_SET_LIGHTPEN_TYPE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_SET_LIGHTPEN_TYPE_HU, "Fenyceruza tipusanak megadasa"},
/* it */ {IDCLS_SET_LIGHTPEN_TYPE_IT, "Imposta tipo penna ottica"},
/* ko */ {IDCLS_SET_LIGHTPEN_TYPE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_SET_LIGHTPEN_TYPE_NL, "Geef de lichtpen soort op"},
/* pl */ {IDCLS_SET_LIGHTPEN_TYPE_PL, "Okre��l typ piora ��wietlnego"},
/* ru */ {IDCLS_SET_LIGHTPEN_TYPE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_SET_LIGHTPEN_TYPE_SV, "Valj typ av ljuspenna"},
/* tr */ {IDCLS_SET_LIGHTPEN_TYPE_TR, "Itykly Kalem tipini ayarla"},
#endif

/* c64/cart/easyflash.c */
/* en */ {IDCLS_ENABLE_EASYFLASH_JUMPER,    N_("Enable EasyFlash jumper")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_EASYFLASH_JUMPER_DA, "Aktiver EasyFlash-jumper"},
/* de */ {IDCLS_ENABLE_EASYFLASH_JUMPER_DE, "EasyFlash Jumper aktivieren"},
/* fr */ {IDCLS_ENABLE_EASYFLASH_JUMPER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_EASYFLASH_JUMPER_HU, "EasyFlash Jumper engedelyezese"},
/* it */ {IDCLS_ENABLE_EASYFLASH_JUMPER_IT, "Attiva ponticello EasyFlash"},
/* ko */ {IDCLS_ENABLE_EASYFLASH_JUMPER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_EASYFLASH_JUMPER_NL, "Activeer de EasyFlash jumper"},
/* pl */ {IDCLS_ENABLE_EASYFLASH_JUMPER_PL, "W3�}cz prze3�}cznik EasyFlash"},
/* ru */ {IDCLS_ENABLE_EASYFLASH_JUMPER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_EASYFLASH_JUMPER_SV, "Aktivera EasyFlash-bygel"},
/* tr */ {IDCLS_ENABLE_EASYFLASH_JUMPER_TR, "EasyFlash jumper'y aktif et"},
#endif

/* c64/cart/easyflash.c */
/* en */ {IDCLS_DISABLE_EASYFLASH_JUMPER,    N_("Disable EasyFlash jumper")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_EASYFLASH_JUMPER_DA, "Deaktiver EasyFlash-jumper"},
/* de */ {IDCLS_DISABLE_EASYFLASH_JUMPER_DE, "EasyFlash Jumer deaktivieren"},
/* fr */ {IDCLS_DISABLE_EASYFLASH_JUMPER_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_EASYFLASH_JUMPER_HU, "EasyFlash Jumper tiltasa"},
/* it */ {IDCLS_DISABLE_EASYFLASH_JUMPER_IT, "Disattiva ponticello EasyFlash"},
/* ko */ {IDCLS_DISABLE_EASYFLASH_JUMPER_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_EASYFLASH_JUMPER_NL, "De EasyFlash jumper uitschakelen"},
/* pl */ {IDCLS_DISABLE_EASYFLASH_JUMPER_PL, "Wy3�}cz prze3�}cznik EasyFlash"},
/* ru */ {IDCLS_DISABLE_EASYFLASH_JUMPER_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_EASYFLASH_JUMPER_SV, "Inaktivera EasyFlash-bygel"},
/* tr */ {IDCLS_DISABLE_EASYFLASH_JUMPER_TR, "EasyFlash jumper'y pasiflettir"},
#endif

/* c64/cart/easyflash.c */
/* en */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING,    N_("Enable writing to EasyFlash .crt image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_DA, "Tillad skrivning til EasyFlash CRT-image"},
/* de */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_DE, "Schreibzugriff auf EasyFlash CRT Image erlauben"},
/* fr */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_HU, "EasyFlash .crt kepmasba iras engedelyezese"},
/* it */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_IT, "Attiva scrittura sull'immagine .crt EasyFlash"},
/* ko */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_NL, "Activeer schrijven naar het EasyFlash .crt bestand"},
/* pl */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_PL, "W3�}cz zapis do obrazu .crt EasyFlash"},
/* ru */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_SV, "Aktivera skrivning till EasyFlash-.crt-avbildning."},
/* tr */ {IDCLS_ENABLE_EASYFLASH_CRT_WRITING_TR, "EasyFlash .crt imajyna yazmayy aktif et"},
#endif

/* c64/cart/easyflash.c */
/* en */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING,    N_("Disable writing to EasyFlash .crt image")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_DA, "Forbyd skrivning til EasyFlash CRT-image"},
/* de */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_DE, "Schreibzugriff auf EasyFlash ROM Image verhindern"},
/* fr */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_HU, "EasyFlash .crt kepmasba iras tiltasa"},
/* it */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_IT, "Disattiva scrittura sull'immagine .crt EasyFlash"},
/* ko */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_NL, "Schrijven naar het EasyFlash .crt bestand uitschakelen"},
/* pl */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_PL, "Wy3�}cz zapis do obrazu .crt EasyFlash"},
/* ru */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_SV, "Inaktivera skrivning till EasyFlash-.crt-avbildning."},
/* tr */ {IDCLS_DISABLE_EASYFLASH_CRT_WRITING_TR, "EasyFlash .crt imajyna yazmayy pasiflettir"},
#endif

/* c64/cart/digimax.c */
/* en */ {IDCLS_ENABLE_DIGIMAX,    N_("Enable the DigiMAX cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_ENABLE_DIGIMAX_DA, "Aktiver DigiMAX cartridge"},
/* de */ {IDCLS_ENABLE_DIGIMAX_DE, "DigiMAX Cartridge aktivieren"},
/* fr */ {IDCLS_ENABLE_DIGIMAX_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_ENABLE_DIGIMAX_HU, ""},  /* fuzzy */
/* it */ {IDCLS_ENABLE_DIGIMAX_IT, "Attiva la cartuccia DigiMAX"},
/* ko */ {IDCLS_ENABLE_DIGIMAX_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_ENABLE_DIGIMAX_NL, "Activeer de DigiMAX cartridge"},
/* pl */ {IDCLS_ENABLE_DIGIMAX_PL, "W3�}cz kartrid? DigiMAX"},
/* ru */ {IDCLS_ENABLE_DIGIMAX_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_ENABLE_DIGIMAX_SV, "Aktivera DigiMAX-insticksmodul"},
/* tr */ {IDCLS_ENABLE_DIGIMAX_TR, "DigiMAX kartutunu aktif et"},
#endif

/* c64/cart/digimax.c */
/* en */ {IDCLS_DISABLE_DIGIMAX,    N_("Disable the DigiMAX cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DISABLE_DIGIMAX_DA, "Deaktiver DigiMAX cartridge"},
/* de */ {IDCLS_DISABLE_DIGIMAX_DE, "DigiMAX Cartridge deaktivieren"},
/* fr */ {IDCLS_DISABLE_DIGIMAX_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DISABLE_DIGIMAX_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DISABLE_DIGIMAX_IT, "Disattiva la cartuccia DigiMAX"},
/* ko */ {IDCLS_DISABLE_DIGIMAX_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DISABLE_DIGIMAX_NL, "De DigiMAX cartridge uitschakelen"},
/* pl */ {IDCLS_DISABLE_DIGIMAX_PL, "Wy3�}cz kartrid? DigiMAX"},
/* ru */ {IDCLS_DISABLE_DIGIMAX_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DISABLE_DIGIMAX_SV, "Inaktivera DigiMAX-insticksmodul"},
/* tr */ {IDCLS_DISABLE_DIGIMAX_TR, "DigiMAX kartutunu pasiflettir"},
#endif

/* c64/cart/digimax.c */
/* en */ {IDCLS_DIGIMAX_BASE,    N_("Base address of the DigiMAX cartridge")},
#ifdef HAS_TRANSLATION
/* da */ {IDCLS_DIGIMAX_BASE_DA, "Baseadresse for DigiMAX cartridge"},
/* de */ {IDCLS_DIGIMAX_BASE_DE, "Basis Adresse fur DigiMAX Erweiterung"},
/* fr */ {IDCLS_DIGIMAX_BASE_FR, ""},  /* fuzzy */
/* hu */ {IDCLS_DIGIMAX_BASE_HU, ""},  /* fuzzy */
/* it */ {IDCLS_DIGIMAX_BASE_IT, "Indirizzo base della cartuccia DigiMAX"},
/* ko */ {IDCLS_DIGIMAX_BASE_KO, ""},  /* fuzzy */
/* nl */ {IDCLS_DIGIMAX_BASE_NL, "Basisadres van de DigiMAX cartridge"},
/* pl */ {IDCLS_DIGIMAX_BASE_PL, "Adres bazowy kartrid?a DigiMAX"},
/* ru */ {IDCLS_DIGIMAX_BASE_RU, ""},  /* fuzzy */
/* sv */ {IDCLS_DIGIMAX_BASE_SV, "Basadress for DigiMAC-insticksmodulen"},
/* tr */ {IDCLS_DIGIMAX_BASE_TR, "DigiMAX kartutunun taban adresi"},
#endif

};