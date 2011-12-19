#!/bin/sh
# make-bindist.sh for the QNX 4.x port
#
# written by Marco van den Heuvel <blackystardust68@yahoo.com>
#
# make-bindist.sh <vice-version> <prefix> <zip|nozip> <x64sc-include> <topsrcdir>
#                 $1             $2       $3          $4              $5

VICEVERSION=$1
PREFIX=$2
ZIPKIND=$3
X64SC=$4
TOPSRCDIR=$5

if test x"$PREFIX" != "x/usr/local"; then
  echo Error: installation path is not /usr/local
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
  if [ ! -e /usr/local/bin/$i ]
  then
    echo Error: \"make install\" needs to be done first
    exit 1
  fi
done

if test x"$ZIPKIND" = "xnozip"; then
  echo Error: This port only supports \"make bindistzip\"
  exit 1
fi

echo Generating QNX 4 port binary distribution.
for i in $EXECUTABLES
do
  wstrip /usr/local/bin/$i
done
cp $TOPSRCDIR/src/arch/unix/qnx4/install_msg ./
TARFILES=""
for i in $EXECUTABLES
do
TARFILES="$TARFILES /usr/local/bin/$i"
done
tar cf vice-$VICEVERSION-qnx4.tar install_msg /usr/local/bin/vsid $TARFILES /usr/local/lib/vice /usr/local/man/man1/c1541.1 /usr/local/man/man1/petcat.1 /usr/local/man/man1/vice.1 /usr/local/info/vice.info*
freeze vice-$VICEVERSION-qnx4.tar
rm -f install_msg
echo QNX 4 port binary distribution directory generated as vice-$VICEVERSION-qnx4.tar.F
