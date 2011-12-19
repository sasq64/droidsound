# Microsoft Developer Studio Project File - Name="c64dtv" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=c64dtv - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "c64dtv.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "c64dtv.mak" CFG="c64dtv - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "c64dtv - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "c64dtv - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "c64dtv - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "libs\c64dtv\Release"
# PROP Intermediate_Dir "libs\c64dtv\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\\" /I "..\..\..\drive" /I "..\..\..\userport" /I "..\..\..\tape" /I "..\..\..\sid" /I "..\..\..\vicii" /I "..\..\..\c64" /I "..\..\..\raster" /D "WIN32" /D "IDE_COMPILE" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "c64dtv - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "libs\c64dtv\Debug"
# PROP Intermediate_Dir "libs\c64dtv\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /GX /Z7 /Od /I ".\\" /I "..\\" /I "..\..\..\\" /I "..\..\..\drive" /I "..\..\..\userport" /I "..\..\..\tape" /I "..\..\..\sid" /I "..\..\..\vicii" /I "..\..\..\c64" /I "..\..\..\raster" /D "WIN32" /D "IDE_COMPILE" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "c64dtv - Win32 Release"
# Name "c64dtv - Win32 Debug"
# Begin Source File

SOURCE="..\..\..\c64dtv\c64dtv-cmdline-options.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\c64dtv\c64dtv-resources.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\c64dtv\c64dtv-snapshot.c"
# End Source File
# Begin Source File

SOURCE=..\..\..\c64dtv\c64dtv.c
# End Source File
# Begin Source File

SOURCE=..\..\..\c64dtv\c64dtvblitter.c
# End Source File
# Begin Source File

SOURCE=..\..\..\c64dtv\c64dtvcia1.c
# End Source File
# Begin Source File

SOURCE=..\..\..\c64dtv\c64dtvcia2.c
# End Source File
# Begin Source File

SOURCE="..\..\..\c64dtv\c64dtvcpu.c"
# End Source File
# Begin Source File

SOURCE=..\..\..\c64dtv\c64dtvdma.c
# End Source File
# Begin Source File

SOURCE=..\..\..\c64dtv\c64dtvflash.c
# End Source File
# Begin Source File

SOURCE=..\..\..\c64dtv\c64dtviec.c
# End Source File
# Begin Source File

SOURCE="..\..\..\c64dtv\c64dtvmem.c"
# End Source File
# Begin Source File

SOURCE=..\..\..\c64dtv\c64dtvmeminit.c
# End Source File
# Begin Source File

SOURCE="..\..\..\c64dtv\c64dtvmemrom.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\c64dtv\c64dtvmemsnapshot.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\c64dtv\c64dtvmodel.c"
# End Source File
# Begin Source File

SOURCE=..\..\..\c64dtv\c64dtvpla.c
# End Source File
# Begin Source File

SOURCE=..\..\..\c64dtv\c64dtvsound.c
# End Source File
# Begin Source File

SOURCE="..\..\..\c64dtv\flash-trap.c"
# End Source File
# Begin Source File

SOURCE=..\..\..\c64dtv\hummeradc.c
# End Source File
# End Target
# End Project
