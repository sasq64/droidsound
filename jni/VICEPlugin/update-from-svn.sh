#!/bin/bash

MYDIR=$(dirname $0)
echo "Updating VICE copy at $MYDIR/vice..."

if [[ $# -ne 1 ]]; then
        echo "Give path to VICE source tree"
        exit 1;
fi

VICEDIR="$1"

if [[ ! -e "$1/INSTALL" ]]; then
        echo "The given VICE directory '$VICEDIR' must have the 'INSTALL' file.";
        exit 1;
fi

TARGET="$MYDIR/vice"

# ok. Now we're in business
echo "Removing old $TARGET"
git rm -rf "$TARGET"
rm -rf "$TARGET"

echo "Copying SVN checkout..."
cp -ra "$VICEDIR/src" vice
echo "Removing SVN and autotools specific files"
find "$TARGET" -name '.svn' -type d -exec rm -rf '{}' ';'
find "$TARGET" -name '*.in' -type f -exec rm -rf '{}' ';'
find "$TARGET" -name '*.am' -type f -exec rm -rf '{}' ';'
find "$TARGET" -name 'configure' -type f -exec rm -rf '{}' ';'
echo "Removing arch files"
rm -rf "$TARGET/arch"
echo "Adding new file set"
git add "$TARGET"
