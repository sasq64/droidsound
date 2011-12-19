#!/bin/sh
# make-bindist.sh for the MSDOS port
#
# written by Marco van den Heuvel <blackystardust68@yahoo.com>
#
# make-bindist.sh <strip> <vice-ver-major> <vice-ver-minor> <zip|nozip> <x64sc-included> <top-srcdir>
#                 $1      $2               $3               $4          $5               $6

STRIP=$1
VICEVERMAJOR=$2
VICEVERMINOR=$3
ZIPKIND=$4
X64SC=$5
TOPSRCDIR=$6

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
  if [ ! -e src/$i.exe ]
  then
    echo Error: executable file\(s\) not found, do a \"make\" first
    exit 1
  fi
done

echo Generating MSDOS port binary distribution.
rm -f -r dosvice
mkdir dosvice
for i in $EXECUTABLES
do
  $STRIP src/$i.exe
  cp src/$i.exe dosvice
done
cp -a $TOPSRCDIR/data/C128 $TOPSRCDIR/data/C64 $TOPSRCDIR/data/C64DTV $TOPSRCDIR/data/CBM-II $TOPSRCDIR/data/DRIVES dosvice
cp -a $TOPSRCDIR/data/PET $TOPSRCDIR/data/PLUS4 $TOPSRCDIR/data/PRINTER $TOPSRCDIR/data/VIC20 dosvice
cp -a $TOPSRCDIR/data/fonts dosvice
cp -a $TOPSRCDIR/doc/html dosvice
cp $TOPSRCDIR/FEEDBACK $TOPSRCDIR/README dosvice
cp $TOPSRCDIR/doc/Readme.dos dosvice
rm `find dosvice -name "Makefile*"`
rm `find dosvice -name "amiga_*.vkm"`
rm `find dosvice -name "os2*.vkm"`
rm `find dosvice -name "osx*.vkm"`
rm `find dosvice -name "beos_*.vkm"`
rm `find dosvice -name "win_*.v*"`
rm `find dosvice -name "x11_*.vkm"`
rm `find dosvice -name "RO*.vkm"`
rm `find dosvice -name "sdl*.vkm"`
rm `find dosvice -name "*.vsc"`
rm dosvice/html/texi2html
if test x"$ZIPKIND" = "xzip"; then
  if test x"$ZIP" = "x"; then
    zip -r -9 -q vice$VICEVERMAJOR$VICEVERMINOR.zip dosvice
  else
    $ZIP vice$VICEVERMAJOR$VICEVERMINOR.zip dosvice
  fi
  rm -f -r dosvice
  echo MSDOS port binary distribution archive generated as vice$VICEVERMAJOR$VICEVERMINOR.zip
else
  echo MSDOS port binary distribution directory generated as dosvice
fi
