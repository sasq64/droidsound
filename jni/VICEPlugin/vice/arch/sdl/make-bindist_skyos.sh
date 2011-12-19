#!/bin/sh
# make-bindist.sh for the SkyOS SDL port
#
# written by Marco van den Heuvel <blackystardust68@yahoo.com>
#
# make-bindist.sh <strip> <vice-version> <prefix> <zip|nozip> <x64sc-included> <topsrcdir>
#                 $1      $2             $3       $4          $5               $6

STRIP=$1
VERSION=$2
PREFIX=$3
ZIPKIND=$4
X64SC=$5
TOPSRCDIR=$6

if test x"$PREFIX" != "x/boot/programs/SDLVICE"; then
  echo Error: installation path is not /boot/programs/SDLVICE
  exit 1
fi

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
  if [ ! -e /boot/programs/SDLVICE/bin/$i ]
  then
    echo Error: \"make install\" needs to be done first
    exit 1
  fi
done

echo Generating SkyOS SDL port binary distribution.
rm -f -r SDLVICE-$VERSION
mkdir -p SDLVICE-$VERSION/programs/SDLVICE
mkdir SDLVICE-$VERSION/programs/SDLVICE/bin
mv /boot/programs/SDLVICE/bin/vsid SDLVICE-$VERSION/programs/SDLVICE/bin
for i in $EXECUTABLES
do
  mv /boot/programs/SDLVICE/bin/$i SDLVICE-$VERSION/programs/SDLVICE/bin/$i.app
  $STRIP SDLVICE-$VERSION/programs/SDLVICE/bin/$i.app
done
mv /boot/programs/SDLVICE/lib/vice SDLVICE-$VERSION/programs/SDLVICE/lib
mkdir -p SDLVICE-$VERSION/programs/SDLVICE/share/man/man1
mv /boot/programs/SDLVICE/share/man/man1/* SDLVICE-$VERSION/programs/SDLVICE/share/man/man1/
mkdir -p SDLVICE-$VERSION/programs/SDLVICE/info
mv /boot/programs/SDLVICE/share/info/vice.info* SDLVICE-$VERSION/programs/SDLVICE/share/info
cp -r $TOPSRCDIR/src/arch/unix/skyos/icons SDLVICE-$VERSION/programs/SDLVICE/
rm -f -r /boot/programs/SDLVICE
if test x"$ZIPKIND" = "xzip"; then
  THEDATE=`date +%d-%b-%Y`
  cat >SDLVICE-$VERSION/install.sif <<_END
[GENERAL]
Magic=SkyOS Installation file

[DESCRIPTION]
Product=SDLVICE $VERSION
Detail=VICE, the Versatile Commodore Emulator 
Copyright=The VICE Team
Version=$VERSION
Date=$THEDATE
License=GPL
Category=Emulators

[PACKAGE]
DefaultPath=

[PANELMENU]
/menu="Emulators/SDLVICE"	/name="vsid"	/link="/boot/programs/SDLVICE/bin/vsid.app"	/icon="/boot/programs/SDLVICE/icons/vsid.ico"
/menu="Emulators/SDLVICE"	/name="x64"	/link="/boot/programs/SDLVICE/bin/x64.app"		/icon="/boot/programs/SDLVICE/icons/x64.ico"   
/menu="Emulators/SDLVICE"	/name="x64dtv"	/link="/boot/programs/SDLVICE/bin/x64dtv.app"		/icon="/boot/programs/SDLVICE/icons/x64dtv.ico"   
_end

if test x"$X64SC" = "xyes"; then
  cat >>SDLVICE-$VERSION/install.sif <<_END
/menu="Emulators/SDLVICE"	/name="x64sc"	/link="/boot/programs/SDLVICE/bin/x64sc.app"		/icon="/boot/programs/SDLVICE/icons/x64sc.ico"   
_END
fi

cat >>SDLVICE-$VERSION/install.sif <<_END
/menu="Emulators/SDLVICE"	/name="x128"	/link="/boot/programs/SDLVICE/bin/x128.app"	/icon="/boot/programs/SDLVICE/icons/x128.ico"   
/menu="Emulators/SDLVICE"	/name="xcbm2"	/link="/boot/programs/SDLVICE/bin/xcbm2.app"	/icon="/boot/programs/SDLVICE/icons/xcbm2.ico"   
/menu="Emulators/SDLVICE"	/name="xcbm5x0"	/link="/boot/programs/SDLVICE/bin/xcbm5x0.app"	/icon="/boot/programs/SDLVICE/icons/xcbm5x0.ico"
/menu="Emulators/SDLVICE"	/name="xpet"	/link="/boot/programs/SDLVICE/bin/xpet.app"	/icon="/boot/programs/SDLVICE/icons/xpet.ico"   
/menu="Emulators/SDLVICE"	/name="xplus4"	/link="/boot/programs/SDLVICE/bin/xplus4.app"	/icon="/boot/programs/SDLVICE/icons/xplus4.ico"   
/menu="Emulators/SDLVICE"	/name="xvic"	/link="/boot/programs/SDLVICE/bin/xvic.app"	/icon="/boot/programs/SDLVICE/icons/xvic.ico"   

[FILEICONS]
/file="\$INSTALL_ROOT/programs/SDLVICE/bin/vsid.app"	/icon="/boot/programs/SDLVICE/icons/vsid.ico"
/file="\$INSTALL_ROOT/programs/SDLVICE/bin/x64.app"	/icon="/boot/programs/SDLVICE/icons/x64.ico"
/file="\$INSTALL_ROOT/programs/SDLVICE/bin/x64dtv.app"	/icon="/boot/programs/SDLVICE/icons/x64dtv.ico"
_END

if test x"$X64SC" = "xyes"; then
  cat >>SDLVICE-$VERSION/install.sif <<_END
/file="\$INSTALL_ROOT/programs/SDLVICE/bin/x64sc.app"	/icon="/boot/programs/SDLVICE/icons/x64sc.ico"
_END
fi

cat >>SDLVICE-$VERSION/install.sif <<_END
/file="\$INSTALL_ROOT/programs/SDLVICE/bin/x128.app"	/icon="/boot/programs/SDLVICE/icons/x128.ico"
/file="\$INSTALL_ROOT/programs/SDLVICE/bin/xcbm2.app"	/icon="/boot/programs/SDLVICE/icons/xcbm2.ico"
/file="\$INSTALL_ROOT/programs/SDLVICE/bin/xcbm5x0.app"	/icon="/boot/programs/SDLVICE/icons/xcbm5x0.ico"
/file="\$INSTALL_ROOT/programs/SDLVICE/bin/xpet.app"	/icon="/boot/programs/SDLVICE/icons/xpet.ico"
/file="\$INSTALL_ROOT/programs/SDLVICE/bin/xplus4.app"	/icon="/boot/programs/SDLVICE/icons/xplus4.ico"
/file="\$INSTALL_ROOT/programs/SDLVICE/bin/xvic.app"	/icon="/boot/programs/SDLVICE/icons/xvic.ico"

[SS_DESCRIPTION]
VICE is a program that runs on a Unix, MS-DOS, Win32, OS/2, Acorn RISC OS, BeOS, QNX, SkyOS, Amiga, GP2X or Mac OS X machine and executes programs intended for the old 8-bit computers. The current version emulates the C64, the C128, the VIC20, almost all PET models, the PLUS4 and the CBM-II (aka C610).
[/SS_DESCRIPTION]

[END]
_END

  cd SDLVICE-$VERSION
  tar cf ../SDLVICE-$VERSION.tar *
  cd ..
  gzip SDLVICE-$VERSION.tar
  mv SDLVICE-$VERSION.tar.gz SDLVICE-$VERSION.pkg
  rm -f -r SDLVICE-$VERSION
  echo SkyOS SDL port binary package generated as SDLVICE-$VERSION.pkg
else
  echo SkyOS SDL port binary distribution directory generated as SDLVICE-$VERSION
fi
