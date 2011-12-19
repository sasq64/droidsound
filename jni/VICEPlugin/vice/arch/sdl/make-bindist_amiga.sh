#!/bin/sh
# make-bindist.sh for the AmigaOS SDL ports
#
# written by Marco van den Heuvel <blackystardust68@yahoo.com>
#
# make-bindist.sh <strip> <vice-version> <host-cpu> <host-system> <zip|nozip> <x64sc-included> <top-srcdir> <exe-ext>
#                 $1      $2             $3         $4            $5          $6               $7           $8

STRIP=$1
VICEVERSION=$2
HOSTCPU=$3
HOSTSYSTEM=$4
ZIPKIND=$5
X64SC=$6
TOPSCRDIR=$7
EXEEXT=$8

if test x"$X64SC" = "xyes"; then
  SCFILE="x64sc"
else
  SCFILE=""
fi

EMULATORS="x64 x64dtv $SCFILE x128 xcbm2 xcbm5x0 xpet xplus4 xvic vsid"
CONSOLE_TOOLS="c1541 cartconv petcat"
EXECUTABLES="$EMULATORS $CONSOLE_TOOLS"

for i in $EXECUTABLES
do
  if [ ! -e src/$i$EXEEXT ]
  then
    echo Error: executable file\(s\) not found, do a \"make all\" first
    exit 1
  fi
done

if test x"$HOSTSYSTEM" = "xaros"; then
  AMIGAFLAVOR=$HOSTCPU-AROS-$VICEVERSION
  echo Generating AROS SDL port binary distribution.
else
  if test x"$HOSTSYSTEM" = "xmorphos"; then
    AMIGAFLAVOR=MorphOS-$VICEVERSION
    echo Generating MorphOS SDL port binary distribution.
  else
    if test x"$HOSTSYSTEM" = "xwarpos"; then
      AMIGAFLAVOR=WarpOS-$VICEVERSION
      echo Generating WarpOS SDL port binary distribution.
    else
      if test x"$HOSTSYSTEM" = "xpowerup"; then
        AMIGAFLAVOR=PowerUP-$VICEVERSION
        echo Generating PowerUP SDL port binary distribution.
      else
        if test x"$HOSTCPU" = "xm68k"; then
          AMIGAFLAVOR=AmigaOS3-$VICEVERSION
          echo Generating AmigaOS3 SDL port binary distribution.
        else
          AMIGAFLAVOR=AmigaOS4-$VICEVERSION
          echo Generating AmigaOS4 SDL port binary distribution.
        fi
      fi
    fi
  fi
fi

rm -f -r SDLVICE-$AMIGAFLAVOR SDLVICE-$AMIGAFLAVOR.info
mkdir SDLVICE-$AMIGAFLAVOR
if test x"$HOSTSYSTEM" != "xaros"; then
  for i in $EXECUTABLES
  do
    $STRIP src/$i$EXEEXT
  done
else
  for i in $EXECUTABLES
  do
    $STRIP --strip-unneeded --remove-section .comment src/$i$EXEEXT
  done
fi
if test x"$HOSTSYSTEM" = "xmorphos"; then
  for i in $EXECUTABLES
  do
    cp src/$i$EXEEXT SDLVICE-$AMIGAFLAVOR/$i
  done
else
  for i in $EXECUTABLES
  do
    cp src/$i$EXEEXT SDLVICE-$AMIGAFLAVOR/$i.exe
  done
fi
cp -a $TOPSCRDIR/data/C128 $TOPSCRDIR/data/C64 SDLVICE-$AMIGAFLAVOR
cp -a $TOPSCRDIR/data/C64DTV $TOPSCRDIR/data/CBM-II SDLVICE-$AMIGAFLAVOR
cp -a $TOPSCRDIR/data/DRIVES $TOPSCRDIR/data/PET SDLVICE-$AMIGAFLAVOR
cp -a $TOPSCRDIR/data/PLUS4 $TOPSCRDIR/data/PRINTER SDLVICE-$AMIGAFLAVOR
cp -a $TOPSCRDIR/data/VIC20 $TOPSCRDIR/data/fonts SDLVICE-$AMIGAFLAVOR
cp -a $TOPSCRDIR/doc/html SDLVICE-$AMIGAFLAVOR
cp $TOPSCRDIR/FEEDBACK $TOPSCRDIR/README SDLVICE-$AMIGAFLAVOR
cp $TOPSCRDIR/doc/readmes/Readme-SDL.txt SDLVICE-$AMIGAFLAVOR
if test x"$HOSTSYSTEM" = "xwarpos"; then
  for i in $EXECUTABLES
  do
    elf2exe SDLVICE-$AMIGAFLAVOR/$i.exe SDLVICE-$AMIGAFLAVOR/$i.new
    mv -f SDLVICE-$AMIGAFLAVOR/$i.new SDLVICE-$AMIGAFLAVOR/$i.exe
  done
fi
if test x"$HOSTSYSTEM" = "xmorphos"; then
  cp $TOPSCRDIR/src/arch/amigaos/info-files/morphos/VICE.info SDLVICE-$AMIGAFLAVOR.info
  cp $TOPSCRDIR/src/arch/amigaos/info-files/morphos/x*.info SDLVICE-$AMIGAFLAVOR
  cp SDLVICE-$AMIGAFLAVOR/x64.info SDLVICE-$AMIGAFLAVOR/x64dtv.info
  if test x"$X64SC" = "xyes"; then
    cp SDLVICE-$AMIGAFLAVOR/x64.info SDLVICE-$AMIGAFLAVOR/x64sc.info
  fi
else
  cp $TOPSCRDIR/src/arch/amigaos/info-files/VICE.info SDLVICE-$AMIGAFLAVOR.info
  cp $TOPSCRDIR/src/arch/amigaos/info-files/*.exe.info SDLVICE-$AMIGAFLAVOR
  cp SDLVICE-$AMIGAFLAVOR/x64.exe.info SDLVICE-$AMIGAFLAVOR/x64dtv.exe.info
  if test x"$X64SC" = "xyes"; then
    cp SDLVICE-$AMIGAFLAVOR/x64.exe.info SDLVICE-$AMIGAFLAVOR/x64sc.exe.info
  fi
fi
rm `find SDLVICE-$AMIGAFLAVOR -name "Makefile*"`
rm `find SDLVICE-$AMIGAFLAVOR -name "dos_*.vkm"`
rm `find SDLVICE-$AMIGAFLAVOR -name "os2*.vkm"`
rm `find SDLVICE-$AMIGAFLAVOR -name "osx*.vkm"`
rm `find SDLVICE-$AMIGAFLAVOR -name "beos_*.vkm"`
rm `find SDLVICE-$AMIGAFLAVOR -name "win_*.v*"`
rm `find SDLVICE-$AMIGAFLAVOR -name "x11_*.vkm"`
rm `find SDLVICE-$AMIGAFLAVOR -name "RO*.vkm"`
rm `find SDLVICE-$AMIGAFLAVOR -name "amiga*.vkm"`
rm `find SDLVICE-$AMIGAFLAVOR -name "*.vsc"`
rm SDLVICE-$AMIGAFLAVOR/html/texi2html
if test x"$ZIPKIND" = "xzip"; then
  tar cf SDLVICE-$AMIGAFLAVOR.tar SDLVICE-$AMIGAFLAVOR SDLVICE-$AMIGAFLAVOR.info
  gzip SDLVICE-$AMIGAFLAVOR.tar
  rm -f -r SDLVICE-$AMIGAFLAVOR SDLVICE-$AMIGAFLAVOR.info
  echo AMIGA SDL port binary distribution archive generated as SDLVICE-$AMIGAFLAVOR.tar.gz
else
  echo AMIGA SDL port binary destribution directory generated as SDLVICE-$AMIGAFLAVOR
fi
