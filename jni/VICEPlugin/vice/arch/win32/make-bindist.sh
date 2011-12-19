#!/bin/sh
# make-bindist.sh for the windows ports
#
# written by Marco van den Heuvel <blackystardust68@yahoo.com>
#
# make-bindist.sh <strip> <vice-version> <zip|nozip> <x64sc-included> <top-srcdir> <cpu> <owcc>
#                 $1      $2             $3          $4               $5           $6    $7

STRIP=$1
VICEVERSION=$2
ZIPKIND=$3
X64SC=$4
TOPSRCDIR=$5
CPU=$6
OWCC=$7

if test x"$OWCC" = "xyes"; then
  EXTOW="ow"
else
  EXTOW=""
fi

if test x"$X64SC" = "xyes"; then
  SCFILE="x64sc"
else
  SCFILE=""
fi

EMULATORS="vsid x64 x64dtv $SCFILE x128 xcbm2 xcbm5x0 xpet xplus4 xvic"
CONSOLE_TOOLS="c1541 cartconv petcat"
EXECUTABLES="$EMULATORS $CONSOLE_TOOLS"

for i in $EMULATORS
do
  if [ ! -e src/$i$EXTOW.exe ]
  then
    echo Error: executable file\(s\) not found, do a \"make\" first
    exit 1
  fi
done

for i in $CONSOLE_TOOLS
do
  if [ ! -e src/$i.exe ]
  then
    echo Error: executable file\(s\) not found, do a \"make\" first
    exit 1
  fi
done

if test x"$CPU" = "xx86_64" -o x"$CPU" = "xamd64"; then
  WINXX="Win64"
  WINVICE="WinVICE-$VICEVERSION-x64"
else
  if test x"$CPU" = "xia64"; then
    WINXX="Win64 ia64"
    WINVICE="WinVICE-$VICEVERSION-ia64"
  else
    WINXX="Win32"
    WINVICE="WinVICE-$VICEVERSION-x86"
  fi
fi

echo Generating $WINXX port binary distribution.
rm -f -r $WINVICE
mkdir $WINVICE
for i in $EMULATORS
do
  $STRIP src/$i$EXTOW.exe
  cp src/$i$EXTOW.exe $WINVICE/$i.exe
done

for i in $CONSOLE_TOOLS
do
  $STRIP src/$i$EXT.exe
  cp src/$i$EXT.exe $WINVICE/$i.exe
done
cp -a $TOPSRCDIR/data/C128 $TOPSRCDIR/data/C64 $TOPSRCDIR/data/C64DTV $WINVICE
cp -a $TOPSRCDIR/data/CBM-II $TOPSRCDIR/data/DRIVES $TOPSRCDIR/data/PET $WINVICE
cp -a $TOPSRCDIR/data/PLUS4 $TOPSRCDIR/data/PRINTER $WINVICE
cp -a $TOPSRCDIR/data/VIC20 $TOPSRCDIR/data/fonts $TOPSRCDIR/doc/html $WINVICE
cp $TOPSRCDIR/FEEDBACK $TOPSRCDIR/README $WINVICE
rm -f `find $WINVICE -name "Makefile*"`
rm `find $WINVICE -name "amiga_*.vkm"`
rm `find $WINVICE -name "dos_*.vkm"`
rm `find $WINVICE -name "gp2x*.vkm"`
rm `find $WINVICE -name "os2*.vkm"`
rm `find $WINVICE -name "osx*.vkm"`
rm `find $WINVICE -name "beos_*.vkm"`
rm `find $WINVICE -name "sdl*.vkm"`
rm `find $WINVICE -name "x11_*.vkm"`
rm `find $WINVICE -name "RO*.vkm"`
rm $WINVICE/html/texi2html
if test x"$ZIPKIND" = "xzip"; then
  if test x"$ZIP" = "x"; then
    zip -r -9 -q $WINVICE.zip $WINVICE
  else
    $ZIP $WINVICE.zip $WINVICE
  fi
  rm -f -r $WINVICE
  echo $WINXX port binary distribution archive generated as $WINVICE.zip
else
  echo $WINXX port binary distribution directory generated as $WINVICE
fi
