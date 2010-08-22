#!/bin/sh
#
#     __  ___          __      __   
#    /  |/  /___  ____/ /_  __/ /__ 
#   / /|_/ / __ \/ __  / / / / / _ \
#  / /  / / /_/ / /_/ / /_/ / /  __/
# /_/  /_/\____/\__,_/\__,_/_/\___/ 
#     ______                           __           
#    / ____/___  ____ _   _____  _____/ /____  _____
#   / /   / __ \/ __ \ | / / _ \/ ___/ __/ _ \/ ___/
#  / /___/ /_/ / / / / |/ /  __/ /  / /_/  __/ /    
#  \____/\____/_/ /_/|___/\___/_/   \__/\___/_/     
#
VERSION="V 2.0"
RELEASEDATE="09 Sept 2005"
#
# A simple way to encode a module to a sampled audio file format
#
# This program is free software, released under GPL;
# see http://www.gnu.org to read the license (GPL)
#
# No warranty
#
# Thanks to :
#  Heikki Orsila and Michael Doering for the UADE program and for help
#  Ralf Hoffmann for his precious suggestions about shell-scripting
#  Juergen Mueller for the soxexam man page
#  Matley for help
#  Bartosz Taudul for posix compliance
#
# Changelog:
#
# 1.0
# * Initial Release
# -- 26 August 2004
#
# 1.1
# * It should be now posix compliant
# -- 10 November 2004
#
# 1.2
# * Fade effect works fine with multiple files/subsongs
# -- 17 December 2004
#
# 1.3
# * If bc is installed, it's used to use better fade time detection
#   ( 4 digits after the point instead of fixed arithmetic )
# * Removed a duplicated call to a function
# -- 06 January 2005
#
# 1.4
# * If normalize isn't on the system, normalizing is done with sox.
#   Anyway using normalize is generally safer, since sox clips the sound
#   often ( even if from the man page it's said that sox stat -v should return a right value
#   that will not clip the sound, in the output i often see n samples clipped using the value
#   returned from sox stat -v )
# -- 10 April 2005
#
# 1.5
# * Removes whitespaces from output file name, some players could have troubles with them.
# -- 17 May 2005
#
# 1.6
# * uade options within command line with --uadeoptions list of uade options  --
#   Should still work with UADEEXTRAOPTIONS defined
# * Added new option --soxeffect list of sox effect --
# -- 25 Jun 2005
#
# 2.0
# * Ported to uade version 2
# * Removes silence at the end if detected by uade
#
# BUGS:
# - Panning is taken only from the config file uade.conf, not with --panning 0.8
# like in the old version of uade. This seems an uade 2 problem
#
# Contact:
# giuliogiuseppecarlo (/AT\) interfree.it

UADECOMMAND="uade123"
COMMENT="UADE using ModuleConverter"
UADEOPTIONS="--one --silence-timeout 7 --panning 0.8"


if [ -n "$UADEEXTRAOPTIONS" ]; then
    UADEOPTIONS=" $UADEOPTIONS $UADEEXTRAOPTIONS "
    echo "Adding $UADEEXTRAOPTIONS to UADEOPTIONS"
fi

uade_convert ()
{
    create_wavetmp
	create_infotmp
    
    if [ "$MULTI" = false ]; then
        "$UADECOMMAND" $UADEOPTIONS "$MODULE" -f "$TF" 2>"$TMPINFO"
    fi

    if [ "$MULTI" = true ]; then
        "$UADECOMMAND" $UADEOPTIONS "$MODULE" --subsong $SUBSONGNUMBER  -f "$TF" 2>"$TMPINFO"
    fi
    
	check_silence
	
    if [ "$FADEOUT" = true ]; then
        effect_fade_out
    fi
    
    if [ "$FADE" = true ]; then
        effect_fade
    fi
    
	if [ "$FADEOUT" = "true" ] || [ "$FADE" = "true" ] || [ "$EFFECT" != "" ]; then
		create_soxtmp
	    sox_convert
		rm -f "$TF"
	else
		WAVE="$TF"
	fi
    
    if [ -z "$NORMALIZE" ]; then
        option_norm
    fi
	
    if [ "$NORMALIZE" = true ]; then
		if [ -z `which normalize 2>/dev/null` ]; then
    		TEMPNORMALIZED=$TMP/output-`basename "$WAVE"`
			NORMALIZEFACTOR=`sox "$WAVE" -e stat -v 2>&1`
			sox -V -v "$NORMALIZEFACTOR" "$WAVE" "$TEMPNORMALIZED"
			mv -f "$TEMPNORMALIZED" "$WAVE"
    	else
			normalize "$WAVE"
    	fi
        
    fi
}

encode_file ()
{
    if [ "$MULTI" = false ]; then
        OUTPUT=`basename "$MODULE" | tr ' ' '_'`
    fi
    if [ "$MULTI" = true ]; then
        OUTPUT=`basename "$MODULE" | tr ' ' '_'`-sub$SUBSONGNUMBER
    fi
    
    case "$MODE" in
        flac)
            if [ ! -e "Track-$OUTPUT.flac" ]; then
                flac --best -T title="$MODULENAME" -T tracknumber="$SUBSONGNUMBER" "$WAVE" -o "Track-$OUTPUT.flac"
            else
                flac --best -T title="$MODULENAME" -T tracknumber="$SUBSONGNUMBER" "$WAVE" -o "Track-$OUTPUT-$$-$RANDOM.flac"
            fi
            ;;
        mp3)
            if [ ! -e "Track-$OUTPUT.mp3" ]; then
                lame -b 192 --tt "$MODULENAME" --tc "$COMMENT" --tn "$SUBSONGNUMBER" "$WAVE" "Track-$OUTPUT.mp3"
            else
                lame -b 192 --tt "$MODULENAME" --tc "$COMMENT" --tn "$SUBSONGNUMBER" "$WAVE" "Track-$OUTPUT-$$-$RANDOM.mp3"
            fi
            ;;
        ogg)
            if [ ! -e "Track-$OUTPUT.ogg" ]; then
                oggenc -q 6 "$WAVE" -t "$MODULENAME" -N "$SUBSONGNUMBER" -o "Track-$OUTPUT.ogg"
                # how does -c "$COMMENT" work?
            else
                oggenc -q 6 "$WAVE" -t "$MODULENAME" -N "$SUBSONGNUMBER" -o "Track-$OUTPUT-$$-$RANDOM.ogg"
            fi
            ;;
        cdr)
            if [ ! -e "Track-$OUTPUT.cdr" ]; then
                sox "$WAVE" "Track-$OUTPUT.cdr"
            else
                sox "$WAVE" "Track-$OUTPUT-$$-$RANDOM.cdr"
            fi
            ;;
        wave)
            if [ ! -e "Track-$OUTPUT.wav" ]; then
                mv "$WAVE" "Track-$OUTPUT.wav"
            else
                mv "$WAVE" "Track-$OUTPUT-$$-$RANDOM.wav"
            fi
            ;;
    esac
    
    delete_wavetmp
}

sox_convert ()
{
	sox  "$TF" "$WAVE" $EFFECT $FADEEFFECT
}

delete_old_tmp ()
{
	if [ "$( ls $TMP/ModuleConverter-* 2>/dev/null )" != "" ]; then
		rm -f $TMP/ModuleConverter-*
	fi
}

usage ()
{
    echo "Usage: `basename $0` [OPTIONS] [FILE1] [FILE2] ..."
    echo "Options:"
    echo "--help        Display this help text and exit"
    echo "--version     Display version info and exit."
    echo
    echo "--ogg         Use ogg as file output [ default ]."
    echo "--mp3         Use mp3 as file output."
    echo "--flac        Use flac as file output."
    echo "--wave        Use wave as file output."
    echo "--cdr         Use cdr as file output."
    echo
    echo "--norm        File will be normalized [ default ]."
    echo "--no-norm     File won't be normalized."
    echo
    echo "--mountains   Adds a mountains effect."
    echo "--hall        Adds a hall effect."
    echo "--garage      Adds a garage effect."
    echo "--chorus      Adds a chorus effect."
    echo
    echo "--fade-in     Adds a fade-in effect."
    echo "--fade-out    Adds a fade-out effect."
    echo "--fade        Adds a fade (in&out) effect."
    echo
    echo "--sox-effect  Insert here your favourite sox effect (end it with -- )"
    echo "--uadeoptions Insert here uade options (end them with -- )"
    echo "              See man uade for uade extra options"
    echo "              Default values are -pan 0.8 -sit 7 and are overridden"
    echo ""
    echo "Examples:"
    echo "`basename $0` --flac --mountains --no-norm\\"
    echo "--uadeoptions -P /usr/local/share/uade/players/PTK-Prowiz -y 60  -- \\"
    echo "Statix/p6x.trsi_statix_intro"
    echo ""
    echo "Some influential environment variables:"
    echo "UADEEXTRAOPTIONS      See man uade for uade extra options"
    echo
    echo "Examples:"
    echo "export UADEEXTRAOPTIONS=\"-P /usr/local/share/uade/players/PTK-Prowiz -y 60 \""
    echo "`basename $0` --flac --mountains --no-norm Statix/p6x.trsi_statix_intro"
    echo "To reset UADEEXTRAOPTIONS : export UADEEXTRAOPTIONS=\"\""
}

print_version ()
{
    echo "Module Converter $VERSION"
    echo "$RELEASEDATE Giulio Canevari"
}

check_programs ()
{
    for p in $PROGS; do
        if [ -z "`which $p 2>/dev/null`" ]; then
            echo "You need $p to run this script!"
            exit 5
        fi
    done
}

mode_flac ()
{
    MODE="flac"
    PROGS=""$UADECOMMAND" sox flac"
    check_programs
}

mode_mp3 ()
{
    MODE="mp3"
    PROGS=""$UADECOMMAND" sox lame"
    check_programs
}

mode_wave ()
{
    MODE="wave"
    PROGS=""$UADECOMMAND" sox"
    check_programs
}

mode_ogg ()
{
    MODE="ogg"
    PROGS=""$UADECOMMAND" sox oggenc"
    check_programs
}

mode_cdr ()
{
    MODE="cdr"
    PROGS=""$UADECOMMAND" sox"
    check_programs
}

option_norm ()
{
    NORMALIZE="true"
}

option_nonorm ()
{
    NORMALIZE="false"
}

effect_mountains ()
{
    EFFECT="$EFFECT echo 0.8 0.9 1000.0 0.3"
}

effect_hall ()
{
    EFFECT="$EFFECT reverb 1.0 600.0 180.0 200.0 220.0 240.0"
}

effect_garage ()
{
    EFFECT="$EFFECT echos 0.8 0.7 40.0 0.25 63.0 0.3"
}

effect_chorus ()
{
    EFFECT="$EFFECT chorus 0.7 0.9 55.0 0.4 0.25 2.0 -t"
}

effect_fade_in ()
{
    FADEEFFECT="fade t 2"
}

check_silence ()
{
	SILENCE=""
	SILENCE=$( cat $TMPINFO | grep 'silence detected' |awk '{print $3 }' |sed s/\(// )
	
	rm -f $TMPINFO

	if [ -n "$SILENCE" ]; then
		get_raw_length
		calculate_cut_time
		create_soxtmp
		sox  "$TF" "$WAVE" fade t 0 $CUTTIME 0
		rm -f "$TF"
		TF="$WAVE"
		WAVE=""
	fi
}

calculate_cut_time ()
{
    if [ -z `which bc 2>/dev/null` ]; then
    	CUTTIME=$(( $STOPTIME -2))
    else
    	CUTTIME=`echo "scale=4 ; $STOPTIME - $SILENCE" | bc`
    fi
}

effect_fade_out ()
{
    get_raw_length
    FADEEFFECT="fade t 0 $STOPTIME 2"
}

effect_fade ()
{
    get_raw_length
    FADEEFFECT="fade t 2 $STOPTIME 2"
}

get_raw_length ()
{
    RAWTMPFILENAME=`basename $TF`
    TMPFILESIZE=`ls -l "$TMP" |grep $RAWTMPFILENAME |awk '{ print $5 }' `
    if [ -z `which bc 2>/dev/null` ]; then
    	STOPTIME=$(( $TMPFILESIZE / 176400))
    else
    	STOPTIME=`echo "scale=4 ; $TMPFILESIZE / 176400" | bc`
    fi
}

check_tmp ()
{
    if [ -z "$TMP" ]; then
        TMP=/tmp
    fi
}

create_wavetmp ()
{
    TF="$TMP/ModuleConverter-$$-$RANDOM.wav"
    if [ ! -e "$TF" ]; then
        touch "$TF"
        chmod 0600 "$TF"
    fi
}

create_soxtmp ()
{
    WAVE="$TMP/ModuleConverter-$$-$RANDOM.wav"
    touch "$WAVE"
    chmod 0600 "$WAVE"
}

create_infotmp ()
{
    TMPINFO="$TMP/ModuleConverter-$$-$RANDOM.txt"
    if [ ! -e "$TMPINFO" ]; then
        touch "$TMPINFO"
        chmod 0600 "$TMPINFO"
    fi
}

delete_wavetmp ()
{
    if [ -e "$WAVE" ]; then
        rm -f "$WAVE"
    fi
}

get_module_info ()
{
    create_infotmp

    extract_player_name
    
    if [ "$PLAYERNAME" ]; then
        "$UADECOMMAND" -P "$PLAYERNAME" -g "$MODULE" >"$TMPINFO" 2>/dev/null
    else
        "$UADECOMMAND" -g "$MODULE" >"$TMPINFO" 2>/dev/null
    fi
    
	cat $TMPINFO
	
    MINSUBSONG=`cat $TMPINFO |grep 'subsong_info:' |awk '{print $3}'`
    MAXSUBSONG=`cat $TMPINFO |grep 'subsong_info:' |awk '{print $4}'`
    MODULENAME=`cat $TMPINFO |grep "modulename:"| sed 's/.*modulename: //'`
    
    rm $TMPINFO
    
    if [ -z "$MODULENAME" ]; then
        MODULENAME="`basename $MODULE`"
    fi
    
    NUMBEROFSUBSONGS=$(( $MAXSUBSONG - $MINSUBSONG + 1 ))
}

extract_player_name ()
{
    PLAYERNAME=`echo $UADEOPTIONS |grep "\-P" |sed 's/.*-P //' |awk '{ print $1}'`
}

if [ "$#" -lt "1" ]; then
    print_version
    echo
    usage
    exit 1
fi

check_tmp
delete_old_tmp

while [ "$1" != "" ] ; do
	case $1 in
        --help|-h)
            usage
            exit 0
        ;;
        --version|-v)
            print_version
            exit 0
        ;;
        --flac)
            mode_flac
        ;;
        --mp3)
            mode_mp3
        ;;
        --wave)
            mode_wave
        ;;
        --ogg)
            mode_ogg
        ;;
        --cdr)
            mode_cdr
        ;;
        --norm)
            option_norm
        ;;
        --no-norm)
            option_nonorm
        ;;
        --hall)
            effect_hall
        ;;
        --mountains)
            effect_mountains
        ;;
        --garage)
            effect_garage
        ;;
        --chorus)
            effect_chorus
        ;;
        --fade-in)
            effect_fade_in
        ;;
        --fade-out)
            FADEOUT="true"
        ;;
        --fade)
            FADE="true"
        ;;
        --uadeoptions)
            UADEOPTIONS="--one"
            shift
            while [ "$1" != "--" ] ; do
                echo "Adding $1 to UADEOPTIONS"
                UADEOPTIONS=`echo "$UADEOPTIONS" $1`
                shift
            done
        ;;
        --sox-effect)
            shift
            while [ "$1" != "--" ] ; do
                echo "Adding $1 to EFFECT"
                EFFECT=`echo "$EFFECT" $1`
                shift
            done
        ;;
        *)
        
            if [ -e "$1" ]; then

                if [ -z "$MODE" ]; then
                    mode_ogg
                fi  
                
                MODULE="$1"
                SUBSONGNUMBER="1"
				
                get_module_info
				
                if [ "$NUMBEROFSUBSONGS" -lt "2" ]; then
                    MULTI="false"
                    uade_convert
                    encode_file
                else
                    MULTI="true"
                    for SUBSONGNUMBER in `seq "$MINSUBSONG" "$MAXSUBSONG" `
                        do
                            uade_convert
                            encode_file
                    done
                fi
            
            else
                echo $i : File not found!
            fi
        ;;
    esac
    shift
done
