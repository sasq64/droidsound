#!/bin/sh
# make-bindist.sh for the QNX 6.x SDL port
#
# written by Marco van den Heuvel <blackystardust68@yahoo.com>
#
# make-bindist.sh <strip> <vice-version> <prefix> <cross> <zip|nozip> <x64sc-included> <topsrcdir> <make-command> <cpu>
#                 $1      $2             $3       $4      $5          $6               $7          $8             $9

STRIP=$1
VICEVERSION=$2
PREFIX=$3
CROSS=$4
ZIPKIND=$5
X64SC=$6
TOPSRCDIR=$7
MAKECOMMAND=$8
CPU=$9

if test x"$X64SC" = "xyes"; then
  SCFILE="x64sc"
else
  SCFILE=""
fi

EMULATORS="x64 x64dtv $SCFILE x128 xcbm2 xcbm5x0 xpet xplus4 xvic vsid"
CONSOLE_TOOLS="c1541 cartconv petcat"
EXECUTABLES="$EMULATORS $CONSOLE_TOOLS"

if test x"$PREFIX" != "x/opt"; then
  echo Error: installation path is not /opt
  exit 1
fi

for i in $EXECUTABLES
do
  if [ ! -e src/$i ]
  then
    echo Error: \"make\" needs to be done first
    exit 1
  fi
done

VICECPU=""

if test x"$CPU" = "xarm"; then
  VICECPU="armle"
fi

if test x"$CPU" = "xmips"; then
  VICECPU="mipsle"
fi

if test x"$CPU" = "xppc" -o x"$CPU" = "xpowerpc"; then
  VICECPU="ppcbe"
fi

if test x"$CPU" = "xsh"; then
  VICECPU="shle"
fi

if test x"$VICECPU" = "x"; then
  VICECPU="x86"
fi

echo Generating $VICECPU QNX 6 SDL port binary distribution.
rm -f -r SDLVICE-$VICEVERSION
curdir=`pwd`
$MAKECOMMAND prefix=$curdir/SDLVICE-$VICEVERSION/opt VICEDIR=$curdir/SDLVICE-$VICEVERSION/opt/lib/vice install
for i in $EXECUTABLES
do
  $STRIP SDLVICE-$VICEVERSION/opt/bin/$i
done
if test x"$ZIPKIND" = "xzip"; then
  gcc $TOPSRCDIR/src/arch/unix/qnx6/getsize.c -o ./getsize
  gcc $TOPSRCDIR/src/arch/unix/qnx6/getlibs.c -o ./getlibs
  mkdir -p public/SDLVICE/core-$VICEVERSION/$VICECPU/opt/bin
  mv SDLVICE-$VICEVERSION/opt/bin/x* public/SDLVICE/core-$VICEVERSION/$VICECPU/opt/bin
  mv SDLVICE-$VICEVERSION/opt/bin/c1541 public/SDLVICE/core-$VICEVERSION/$VICECPU/opt/bin
  mv SDLVICE-$VICEVERSION/opt/bin/cartconv public/SDLVICE/core-$VICEVERSION/$VICECPU/opt/bin
  mv SDLVICE-$VICEVERSION/opt/bin/petcat public/SDLVICE/core-$VICEVERSION/$VICECPU/opt/bin

  current_date=`date +%Y/%m/%d`

cat >manifest.01 <<_END
<?xml version="1.0"?>
<RDF:RDF xmlns:RDF="http://www.w3.org" xmlns:QPM="http://www.qnx.com">
   <RDF:Description about="http://www.qnx.com">
      <QPM:PackageManifest>
         <QPM:PackageDescription>
            <QPM:PackageType>Application</QPM:PackageType>
            <QPM:PackageName>SDLVICE-$VICEVERSION-$VICECPU-public</QPM:PackageName>
_END

echo >manifest.02 "            <QPM:PackageSize/>"

cat >manifest.03 <<_END
            <QPM:PackageReleaseNumber>1</QPM:PackageReleaseNumber>
            <QPM:PackageReleaseDate>$current_date</QPM:PackageReleaseDate>
            <QPM:PackageRepository/>
            <QPM:FileVersion>2.0</QPM:FileVersion>
         </QPM:PackageDescription>

         <QPM:ProductDescription>
            <QPM:ProductName>SDLVICE for $VICECPU</QPM:ProductName>
_END

  ls -l -R public/SDLVICE/core-$VICEVERSION/$VICECPU/opt >size.tmp
  manifest_size=`./getsize size.tmp`
  rm -f -r size.tmp
  echo >manifest.04 "            <QPM:ProductSize>$manifest_size</QPM:ProductSize>"

  echo >manifest.05 "            <QPM:ProductIdentifier>SDLVICE-host_$VICECPU</QPM:ProductIdentifier>"

  cat >manifest.06 <<_END
            <QPM:ProductEmail>vice-emu-mail@lists.sourceforge.net</QPM:ProductEmail>
            <QPM:VendorName>Public</QPM:VendorName>
            <QPM:VendorInstallName>public</QPM:VendorInstallName>
            <QPM:VendorURL>http://vice-emu.sourceforge.net</QPM:VendorURL>
            <QPM:VendorEmbedURL/>
            <QPM:VendorEmail>vice-emu-mail@lists.sourceforge.net</QPM:VendorEmail>
            <QPM:AuthorName>The VICE Team</QPM:AuthorName>
            <QPM:AuthorURL>http://vice-emu.sourceforge.net</QPM:AuthorURL>
            <QPM:AuthorEmbedURL/>
            <QPM:AuthorEmail>vice-emu-mail@lists.sourceforge.net</QPM:AuthorEmail>
            <QPM:ProductIconSmall>http://www.trikaliotis.net/vicekb/common/vice-logo.png</QPM:ProductIconSmall>
            <QPM:ProductIconLarge>http://www.viceteam.org/images/vice-logo.jpg</QPM:ProductIconLarge>
            <QPM:ProductDescriptionShort>The Versatile Commodore Emulator</QPM:ProductDescriptionShort>
            <QPM:ProductDescriptionLong>VICE is a program that runs on a Unix, MS-DOS, Win32, OS/2, Acorn RISC OS, QNX 6.x, AmigaOS or BeOS machine and executes programs intended for the old 8-bit computers. The current version emulates the C64, the C128, the VIC20, all the PET models (except the SuperPET 9000, which is out of line anyway), the PLUS4 and the CBM-II (aka C610).</QPM:ProductDescriptionLong>
            <QPM:ProductDescriptionURL>http://vice-emu.sourceforge.net</QPM:ProductDescriptionURL>
            <QPM:ProductDescriptionEmbedURL/>
_END

echo >manifest.07 "            <QPM:InstallPath>public/SDLVICE/core-$VICEVERSION/$VICECPU</QPM:InstallPath>"

cat >manifest.08 <<_END
         </QPM:ProductDescription>

         <QPM:ReleaseDescription>
            <QPM:ReleaseDate>$current_date</QPM:ReleaseDate>
            <QPM:ReleaseVersion>$VICEVERSION</QPM:ReleaseVersion>
            <QPM:ReleaseUrgency>High</QPM:ReleaseUrgency>
            <QPM:ReleaseStability>Stable</QPM:ReleaseStability>
            <QPM:ReleaseNoteMinor/>
            <QPM:ReleaseNoteMajor/>
            <QPM:ReleaseBuild>1</QPM:ReleaseBuild>
            <QPM:ExcludeCountries>
               <QPM:Country/>
            </QPM:ExcludeCountries>

            <QPM:ReleaseCopyright>GNU General Public License</QPM:ReleaseCopyright>
         </QPM:ReleaseDescription>

         <QPM:LicenseUrl>rep://SDLVICE-$VICEVERSION-public.repdata/LicenseUrl/COPYING</QPM:LicenseUrl>
         <QPM:ProductKeyUrl/>
         <QPM:RelationshipDescription>
_END

cat >manifest.09 <<_END
            <QPM:RelationshipType>component</QPM:RelationshipType>
            <QPM:ComponentType>Required</QPM:ComponentType>
            <QPM:ComponentParent>SDLVICE</QPM:ComponentParent>
_END

cat >manifest.10 <<_END
            <QPM:ComponentFilter/>
         </QPM:RelationshipDescription>

         <QPM:ContentDescription>
            <QPM:ContentTopic>Games and Diversions/Game Emulatiors</QPM:ContentTopic>
            <QPM:ContentKeyword>c64,c128,vic20,plus4,c16,cbm510,cbm610,c510,c610,cbm,commodore,emulator,pet</QPM:ContentKeyword>
_END

echo >manifest.11 "            <QPM:Processor>$VICECPU</QPM:Processor>"

cat >manifest.12 <<_END
            <QPM:TargetProcessor/>
            <QPM:TargetOS>qnx6</QPM:TargetOS>
            <QPM:HostOS>none</QPM:HostOS>
            <QPM:DisplayEnvironment>SDL</QPM:DisplayEnvironment>
            <QPM:TargetAudience>User</QPM:TargetAudience>
_END

  ./getlibs public/SDLVICE/core-$VICEVERSION/$VICECPU/opt/bin/x64 >manifest.13

cat >manifest.14 <<_END
         </QPM:ContentDescription>

         <QPM:ProductInstallationDependencies>
            <QPM:ProductRequirements>This package requires the following libraries to operate correctly : libintl, libSDL, libpng.</QPM:ProductRequirements>
         </QPM:ProductInstallationDependencies>
_END

cat >manifest.15 <<_END
         <QPM:QNXLicenseDescription/>
      </QPM:PackageManifest>

      <QPM:FileManifest>
         <QPM:Listing>
            <QPM:Dir name="">
               <QPM:Dir name="opt">
                  <QPM:Dir name="bin">
                     <QPM:File>c1541</QPM:File>
                     <QPM:File>petcat</QPM:File>
                     <QPM:File>cartconv</QPM:File>
                     <QPM:File>vsid</QPM:File>
                     <QPM:File>x128</QPM:File>
                     <QPM:File>x64</QPM:File>
                     <QPM:File>x64dtv</QPM:File>
_END

if test x"$X64SC" = "xyes"; then
  cat >>manifest.15 <<_END
                     <QPM:File>x64sc</QPM:File>
_END
fi

cat >>manifest.15 <<_END
                     <QPM:File>xcbm2</QPM:File>
                     <QPM:File>xcbm5x0</QPM:File>
                     <QPM:File>xpet</QPM:File>
                     <QPM:File>xplus4</QPM:File>
                     <QPM:File>xvic</QPM:File>
                  </QPM:Dir>
               </QPM:Dir>
            </QPM:Dir>
         </QPM:Listing>
      </QPM:FileManifest>
   </RDF:Description>
</RDF:RDF>
_END

  cat >public/SDLVICE/core-$VICEVERSION/$VICECPU/MANIFEST manifest.01 manifest.02 \
      manifest.03 manifest.04 manifest.05 manifest.06 manifest.07 manifest.08 \
      manifest.09 manifest.10 manifest.11 manifest.12 manifest.13 manifest.14 \
      manifest.15

  tar cf SDLVICE-$VICECPU.tar public
  gzip SDLVICE-$VICECPU.tar
  mv SDLVICE-$VICECPU.tar.gz SDLVICE-$VICEVERSION-$VICECPU-public.qpk

  ls -l -R SDLVICE-$VICEVERSION-$VICECPU-public.qpk >size.tmp
  manifest_size=`./getsize size.tmp` 
  rm -f -r size.tmp

  echo >manifest.04 "            <QPM:PackageSize>$manifest_size</QPM:PackageSize>"

  cat >SDLVICE-$VICEVERSION-$VICECPU-public.qpm manifest.01 manifest.02 manifest.03 manifest.04 \
      manifest.05 manifest.06 manifest.07 manifest.08 manifest.09 manifest.10 \
      manifest.11 manifest.12 manifest.13 manifest.14 manifest.15

  rm -f -r public

  mkdir -p public/SDLVICE/core-$VICEVERSION
  mv SDLVICE-$VICEVERSION/opt public/SDLVICE/core-$VICEVERSION

  mkdir -p SDLVICE-$VICEVERSION-public.repdata/LicenseUrl
  cp public/SDLVICE/core-$VICEVERSION/opt/lib/vice/doc/COPYING SDLVICE-$VICEVERSION-public.repdata/LicenseUrl

  echo >manifest.02 "            <QPM:PackageSize/>"

  ls -l -R public/SDLVICE/core-$VICEVERSION/opt >size.tmp
  manifest_size=`./getsize size.tmp`
  rm -f -r size.tmp
  echo >manifest.04 "            <QPM:ProductSize>$manifest_size</QPM:ProductSize>"

  echo >manifest.05 "            <QPM:ProductIdentifier>SDLVICE</QPM:ProductIdentifier>"

  echo >manifest.07 "            <QPM:InstallPath>public/SDLVICE/core-$VICEVERSION</QPM:InstallPath>"

  cat >manifest.09 <<_END
            <QPM:RelationshipType>core</QPM:RelationshipType>
            <QPM:ComponentType>Required</QPM:ComponentType>
            <QPM:ComponentParent/>
_END

  echo >manifest.11 "            <QPM:Processor/>"

  cat >manifest.15 <<_END
         <QPM:ProductInstallationProcedure>
            <QPM:Script>
               <QPM:ScriptName>/usr/photon/bin/launchmenu_notify</QPM:ScriptName>
               <QPM:ScriptTiming>Post</QPM:ScriptTiming>
               <QPM:ScriptType>Use</QPM:ScriptType>
            </QPM:Script>

            <QPM:Script>
               <QPM:ScriptName>/usr/photon/bin/launchmenu_notify</QPM:ScriptName>
               <QPM:ScriptTiming>Post</QPM:ScriptTiming>
               <QPM:ScriptType>Unuse</QPM:ScriptType>
            </QPM:Script>
         </QPM:ProductInstallationProcedure>

         <QPM:QNXLicenseDescription/>
      </QPM:PackageManifest>

      <QPM:FileManifest>
         <QPM:PkgInclude>
            <QPM:Item>\$(PROCESSOR)/MANIFEST</QPM:Item>
         </QPM:PkgInclude>

         <QPM:Listing>
            <QPM:Dir name="">
               <QPM:Dir name="opt">
                  <QPM:Union link="../\$(PROCESSOR)/opt/bin">bin</QPM:Union>
                  <QPM:Dir name="bin">
                     <QPM:File>vsid</QPM:File>
                  </QPM:Dir>

                  <QPM:Dir name="info">
                     <QPM:File>vice.info</QPM:File>
                     <QPM:File>vice.info-1</QPM:File>
                     <QPM:File>vice.info-2</QPM:File>
                     <QPM:File>vice.info-3</QPM:File>
                     <QPM:File>vice.info-4</QPM:File>
                     <QPM:File>vice.info-5</QPM:File>
                     <QPM:File>vice.info-6</QPM:File>
                  </QPM:Dir>

                  <QPM:Dir name="lib">
                     <QPM:Dir name="vice">
                        <QPM:Dir name="C128">
                           <QPM:File>basic64</QPM:File>
                           <QPM:File>basichi</QPM:File>
                           <QPM:File>basiclo</QPM:File>
                           <QPM:File>c64hq.vpl</QPM:File>
                           <QPM:File>c64s.vpl</QPM:File>
                           <QPM:File>ccs64.vpl</QPM:File>
                           <QPM:File>chargde</QPM:File>
                           <QPM:File>chargen</QPM:File>
                           <QPM:File>chargfr</QPM:File>
                           <QPM:File>chargse</QPM:File>
                           <QPM:File>default.vpl</QPM:File>
                           <QPM:File>default.vrs</QPM:File>
                           <QPM:File>frodo.vpl</QPM:File>
                           <QPM:File>godot.vpl</QPM:File>
                           <QPM:File>kernal</QPM:File>
                           <QPM:File>kernal64</QPM:File>
                           <QPM:File>kernalde</QPM:File>
                           <QPM:File>kernalfi</QPM:File>
                           <QPM:File>kernalfr</QPM:File>
                           <QPM:File>kernalit</QPM:File>
                           <QPM:File>kernalno</QPM:File>
                           <QPM:File>kernalse</QPM:File>
                           <QPM:File>pc64.vpl</QPM:File>
                           <QPM:File>vdc_deft.vpl</QPM:File>
                           <QPM:File>vdc_comp.vpl</QPM:File>
                           <QPM:File>vice.vpl</QPM:File>
                           <QPM:File>x11_pos.vkm</QPM:File>
                           <QPM:File>x11_sym.vkm</QPM:File>
                        </QPM:Dir>

                        <QPM:Dir name="C64">
                           <QPM:File>basic</QPM:File>
                           <QPM:File>c64hq.vpl</QPM:File>
                           <QPM:File>c64mem.sym</QPM:File>
                           <QPM:File>c64s.vpl</QPM:File>
                           <QPM:File>ccs64.vpl</QPM:File>
                           <QPM:File>chargen</QPM:File>
                           <QPM:File>default.vpl</QPM:File>
                           <QPM:File>default.vrs</QPM:File>
                           <QPM:File>frodo.vpl</QPM:File>
                           <QPM:File>godot.vpl</QPM:File>
                           <QPM:File>kernal</QPM:File>
                           <QPM:File>pc64.vpl</QPM:File>
                           <QPM:File>vice.vpl</QPM:File>
                           <QPM:File>sdl_sym.vkm</QPM:File>
                        </QPM:Dir>

                        <QPM:Dir name="C64DTV">
                           <QPM:File>basic</QPM:File>
                           <QPM:File>c64hq.vpl</QPM:File>
                           <QPM:File>c64mem.sym</QPM:File>
                           <QPM:File>c64s.vpl</QPM:File>
                           <QPM:File>ccs64.vpl</QPM:File>
                           <QPM:File>chargen</QPM:File>
                           <QPM:File>default.vpl</QPM:File>
                           <QPM:File>default.vrs</QPM:File>
                           <QPM:File>frodo.vpl</QPM:File>
                           <QPM:File>godot.vpl</QPM:File>
                           <QPM:File>kernal</QPM:File>
                           <QPM:File>pc64.vpl</QPM:File>
                           <QPM:File>vice.vpl</QPM:File>
                           <QPM:File>x11_pos.vkm</QPM:File>
                           <QPM:File>x11_sym.vkm</QPM:File>
                        </QPM:Dir>

                        <QPM:Dir name="CBM-II">
                           <QPM:File>amber.vpl</QPM:File>
                           <QPM:File>basic.128</QPM:File>
                           <QPM:File>basic.256</QPM:File>
                           <QPM:File>basic.500</QPM:File>
                           <QPM:File>c64hq.vpl</QPM:File>
                           <QPM:File>c64s.vpl</QPM:File>
                           <QPM:File>ccs64.vpl</QPM:File>
                           <QPM:File>chargen.500</QPM:File>
                           <QPM:File>chargen.600</QPM:File>
                           <QPM:File>chargen.700</QPM:File>
                           <QPM:File>default.vpl</QPM:File>
                           <QPM:File>frodo.vpl</QPM:File>
                           <QPM:File>godot.vpl</QPM:File>
                           <QPM:File>green.vpl</QPM:File>
                           <QPM:File>kernal</QPM:File>
                           <QPM:File>kernal.500</QPM:File>
                           <QPM:File>pc64.vpl</QPM:File>
                           <QPM:File>rom128h.vrs</QPM:File>
                           <QPM:File>rom128l.vrs</QPM:File>
                           <QPM:File>rom256h.vrs</QPM:File>
                           <QPM:File>rom256l.vrs</QPM:File>
                           <QPM:File>rom500.vrs</QPM:File>
                           <QPM:File>white.vpl</QPM:File>
                           <QPM:File>x11_buks.vkm</QPM:File>
                        </QPM:Dir>

                        <QPM:Dir name="DRIVES">
                           <QPM:File>d1541II</QPM:File>
                           <QPM:File>d1571cr</QPM:File>
                           <QPM:File>dos1001</QPM:File>
                           <QPM:File>dos1541</QPM:File>
                           <QPM:File>dos1551</QPM:File>
                           <QPM:File>dos1570</QPM:File>
                           <QPM:File>dos1571</QPM:File>
                           <QPM:File>dos1581</QPM:File>
                           <QPM:File>dos2031</QPM:File>
                           <QPM:File>dos2040</QPM:File>
                           <QPM:File>dos3040</QPM:File>
                           <QPM:File>dos4040</QPM:File>
                        </QPM:Dir>

                        <QPM:Dir name="PET">
                           <QPM:File>amber.vpl</QPM:File>
                           <QPM:File>basic1</QPM:File>
                           <QPM:File>basic2</QPM:File>
                           <QPM:File>basic4</QPM:File>
                           <QPM:File>chargen</QPM:File>
                           <QPM:File>chargen.de</QPM:File>
                           <QPM:File>edit1g</QPM:File>
                           <QPM:File>edit2b</QPM:File>
                           <QPM:File>edit2g</QPM:File>
                           <QPM:File>edit4b40</QPM:File>
                           <QPM:File>edit4b80</QPM:File>
                           <QPM:File>edit4g40</QPM:File>
                           <QPM:File>green.vpl</QPM:File>
                           <QPM:File>kernal1</QPM:File>
                           <QPM:File>kernal2</QPM:File>
                           <QPM:File>kernal4</QPM:File>
                           <QPM:File>rom1g.vrs</QPM:File>
                           <QPM:File>rom2b.vrs</QPM:File>
                           <QPM:File>rom2g.vrs</QPM:File>
                           <QPM:File>rom4b40.vrs</QPM:File>
                           <QPM:File>rom4b80.vrs</QPM:File>
                           <QPM:File>rom4g40.vrs</QPM:File>
                           <QPM:File>white.vpl</QPM:File>
                           <QPM:File>x11_bdep.vkm</QPM:File>
                           <QPM:File>x11_bdes.vkm</QPM:File>
                           <QPM:File>x11_bgrs.vkm</QPM:File>
                           <QPM:File>x11_buks.vkm</QPM:File>
                        </QPM:Dir>

                        <QPM:Dir name="PLUS4">
                           <QPM:File>3plus1hi</QPM:File>
                           <QPM:File>3plus1lo</QPM:File>
                           <QPM:File>basic</QPM:File>
                           <QPM:File>default.vpl</QPM:File>
                           <QPM:File>default.vrs</QPM:File>
                           <QPM:File>kernal</QPM:File>
                           <QPM:File>vice.vpl</QPM:File>
                           <QPM:File>x11_pos.vkm</QPM:File>
                           <QPM:File>x11_sym.vkm</QPM:File>
                        </QPM:Dir>

                        <QPM:Dir name="PRINTER">
                           <QPM:File>cbm1526</QPM:File>
                           <QPM:File>mps801</QPM:File>
                           <QPM:File>mps803</QPM:File>
                           <QPM:File>mps803.vpl</QPM:File>
                           <QPM:File>nl10-cbm</QPM:File>
                        </QPM:Dir>

                        <QPM:Dir name="VIC20">
                           <QPM:File>basic</QPM:File>
                           <QPM:File>chargen</QPM:File>
                           <QPM:File>default.vpl</QPM:File>
                           <QPM:File>default.vrs</QPM:File>
                           <QPM:File>kernal</QPM:File>
                           <QPM:File>x11_pos.vkm</QPM:File>
                           <QPM:File>x11_sym.vkm</QPM:File>
                        </QPM:Dir>

                        <QPM:Dir name="doc">
                           <QPM:File>64doc.txt</QPM:File>
                           <QPM:File>BUGS</QPM:File>
                           <QPM:File>COPYING</QPM:File>
                           <QPM:File>MSDOS-Ethernet-Howto.txt</QPM:File>
                           <QPM:File>MSDOS-Howto.txt</QPM:File>
                           <QPM:File>MinixVmd-Howto.txt</QPM:File>
                           <QPM:File>NEWS</QPM:File>
                           <QPM:File>NLS-Howto.txt</QPM:File>
                           <QPM:File>PETdoc.txt</QPM:File>
                           <QPM:File>Readme.beos</QPM:File>
                           <QPM:File>Readme.dos</QPM:File>
                           <QPM:File>ReadmeMacOSX.txt</QPM:File>
                           <QPM:File>ReadmeSDL.txt</QPM:File>
                           <QPM:File>TODO</QPM:File>
                           <QPM:File>Walkthrough-Howto.txt</QPM:File>
                           <QPM:File>Win32-Howto.txt</QPM:File>
                           <QPM:File>cbm_basic_tokens.txt</QPM:File>
                           <QPM:File>drive_info.txt</QPM:File>
                           <QPM:File>iec-bus.txt</QPM:File>
                           <QPM:File>index.html</QPM:File>
                           <QPM:File>mon.txt</QPM:File>
                           <QPM:File>new.gif</QPM:File>
                           <QPM:File>serial.txt</QPM:File>
                           <QPM:File>vice-logo.jpg</QPM:File>
                           <QPM:File>vice_1.html</QPM:File>
                           <QPM:File>vice_10.html</QPM:File>
                           <QPM:File>vice_11.html</QPM:File>
                           <QPM:File>vice_12.html</QPM:File>
                           <QPM:File>vice_13.html</QPM:File>
                           <QPM:File>vice_14.html</QPM:File>
                           <QPM:File>vice_15.html</QPM:File>
                           <QPM:File>vice_16.html</QPM:File>
                           <QPM:File>vice_2.html</QPM:File>
                           <QPM:File>vice_3.html</QPM:File>
                           <QPM:File>vice_4.html</QPM:File>
                           <QPM:File>vice_5.html</QPM:File>
                           <QPM:File>vice_6.html</QPM:File>
                           <QPM:File>vice_7.html</QPM:File>
                           <QPM:File>vice_8.html</QPM:File>
                           <QPM:File>vice_9.html</QPM:File>
                           <QPM:File>vice_toc.html</QPM:File>
                        </QPM:Dir>
                     </QPM:Dir>
                  </QPM:Dir>

                  <QPM:Dir name="man">
                     <QPM:Dir name="man1">
                        <QPM:File>c1541.1</QPM:File>
                        <QPM:File>petcat.1</QPM:File>
                        <QPM:File>vice.1</QPM:File>
                     </QPM:Dir>
                  </QPM:Dir>
               </QPM:Dir>

               <QPM:Dir name="usr">
                  <QPM:Union link="../opt/info">info</QPM:Union>
                  <QPM:Union link="../opt/bin">bin</QPM:Union>
                  <QPM:Union link="../\$(PROCESSOR)/opt/bin">bin</QPM:Union>
                  <QPM:Dir name="lib">
                     <QPM:Dir name="vice">
                        <QPM:Union link="../../../opt/lib/vice/fonts">fonts</QPM:Union>
                        <QPM:Union link="../../../opt/lib/vice/doc">doc</QPM:Union>
                        <QPM:Union link="../../../opt/lib/vice/VIC20">VIC20</QPM:Union>
                        <QPM:Union link="../../../opt/lib/vice/PRINTER">PRINTER</QPM:Union>
                        <QPM:Union link="../../../opt/lib/vice/PLUS4">PLUS4</QPM:Union>
                        <QPM:Union link="../../../opt/lib/vice/PET">PET</QPM:Union>
                        <QPM:Union link="../../../opt/lib/vice/DRIVES">DRIVES</QPM:Union>
                        <QPM:Union link="../../../opt/lib/vice/CBM-II">CBM-II</QPM:Union>
                        <QPM:Union link="../../../opt/lib/vice/C64">C64</QPM:Union>
                        <QPM:Union link="../../../opt/lib/vice/C64DTV">C64DTV</QPM:Union>
                        <QPM:Union link="../../../opt/lib/vice/C128">C128</QPM:Union>
                     </QPM:Dir>
                  </QPM:Dir>

                  <QPM:Dir name="man">
                     <QPM:Union link="../../opt/man/man1">man1</QPM:Union>
                  </QPM:Dir>
               </QPM:Dir>
            </QPM:Dir>
         </QPM:Listing>
      </QPM:FileManifest>

      <QPM:Launch name="x64">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/x64"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="x64 (no sound)">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/x64 -sounddev dummy"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="x64dtv">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/x64dtv"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="x64dtv (no sound)">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/x64dtv -sounddev dummy"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

_END

if test x"$X64SC" = "xyes"; then
  cat >>manifest.15 <<_END
      <QPM:Launch name="x64sc">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/x64sc"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="x64sc (no sound)">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/x64sc -sounddev dummy"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

_END
fi

cat >>manifest.15 <<_END
      <QPM:Launch name="vsid2">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/vsid"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="x128">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/x128"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="x128 (no sound)">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/x128 -sounddev dummy"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="xvic">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/xvic"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="xvic (no sound)">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/xvic -sounddev dummy"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="xpet">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/xpet"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="xpet (no sound)">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/xpet -sounddev dummy"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="xplus4">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/xplus4"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="xplus4 (no sound)">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/xplus4 -sounddev dummy"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="xcbm2">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/xcbm2"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="xcbm2 (no sound)">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/xcbm2 -sounddev dummy"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="xcbm5x0">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/xcbm5x0"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>

      <QPM:Launch name="xcbm5x0 (no sound)">
         <QPM:String name="Topic" value="Applications/Emulators"/>
         <QPM:String name="Command" value="/opt/bin/xcbm5x0 -sounddev dummy"/>
         <QPM:String name="Icon" value="/usr/share/icons/topics/chameleon.gif"/>
      </QPM:Launch>
   </RDF:Description>
</RDF:RDF>
_END

  cat >public/SDLVICE/core-$VICEVERSION/MANIFEST manifest.01 manifest.02 manifest.03 \
      manifest.04 manifest.05 manifest.06 manifest.07 manifest.08 manifest.09 \
      manifest.10 manifest.11 manifest.12 manifest.14 manifest.15

  tar cf SDLVICE-core.tar public
  gzip SDLVICE-core.tar
  mv SDLVICE-core.tar.gz SDLVICE-$VICEVERSION-public.qpk

  ls -l -R SDLVICE-$VICEVERSION-public.qpk >size.tmp
  manifest_size=`./getsize size.tmp` 
  rm -f -r size.tmp

  echo >manifest.04 "            <QPM:PackageSize>$manifest_size</QPM:PackageSize>"

  cat >SDLVICE-$VICEVERSION-public.qpm manifest.01 manifest.02 manifest.03 manifest.04 \
      manifest.05 manifest.06 manifest.07 manifest.08 manifest.09 manifest.10 \
      manifest.11 manifest.12 manifest.14 manifest.15

  rm -f -r public

  tar cf SDLVICE-$VICECPU.tar SDLVICE-$VICEVERSION-public.qp? SDLVICE-$VICEVERSION-public.repdata SDLVICE-$VICEVERSION-$VICECPU-public.qp?
  gzip SDLVICE-$VICECPU.tar
  mv SDLVICE-$VICECPU.tar.gz SDLVICE-$VICEVERSION-$VICECPU-public.qpr

  rm -f -r *.qpk *.qpm *.repdata manifest.* SDLVICE-$VICEVERSION

  echo QNX 6 SDL port binary package part generated as SDLVICE-$VICEVERSION-$VICECPU-public.qpr
else
  echo QNX 6 SDL port binary distribution directory generated as SDLVICE-$VICEVERSION
fi
