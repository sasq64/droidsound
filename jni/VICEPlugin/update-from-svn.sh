#!/bin/bash -e

MYDIR="$(dirname $0)"
TARGET="$MYDIR/vice"

if [[ $# -ne 1 ]]; then
        echo "Give path to VICE source tree svn checkout"
        exit 1;
fi
VICEDIR="$1"

if [[ ! -e "$VICEDIR/INSTALL" ]]; then
        echo "The given VICE source directory '$VICEDIR' must have the 'INSTALL' file.";
        exit 1;
fi

# ok. Now we're in business
echo "Removing old $TARGET..."
git rm -rf "$TARGET"
rm -rf "$TARGET"

echo "Copying SVN checkout..."
cp -a "$VICEDIR/src" vice
echo "Removing SVN and autotools specific files..."
find "$TARGET" -name '.svn' -type d -exec rm -rf '{}' ';'
find "$TARGET" -name '*.in' -type f -exec rm -rf '{}' ';'
find "$TARGET" -name '*.am' -type f -exec rm -rf '{}' ';'
find "$TARGET" -name 'configure' -type f -exec rm -rf '{}' ';'
echo "Removing arch files"
rm -rf "$TARGET/arch"
echo "Changing suffix of C++ source files..."
for i in $TARGET/sid/resid $TARGET/resid/{dac,envelope,extfilt,filter,pot,sid,version,voice,wave}; do
        echo "  $i.cc -> $i.cpp"
        mv "$i.cc" "$i.cpp"
done
echo "Adding new file set to git..."
git add "$TARGET"

echo "You may still have to let VICE's build system generate a translate.h, and copy it to $MYDIR."
