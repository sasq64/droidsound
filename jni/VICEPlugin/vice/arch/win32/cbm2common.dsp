# Microsoft Developer Studio Project File - Name="cbm2common" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=cbm2common - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "cbm2common.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cbm2common.mak" CFG="cbm2common - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cbm2common - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "cbm2common - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "cbm2common - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "libs\cbm2common\Release"
# PROP Intermediate_Dir "libs\cbm2common\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I ".\msvc" /I ".\\" /I "..\..\\" /I "..\..\drive" /I "..\..\userport" /I "..\..\tape" /I "..\..\sid" /I "..\..\crtc" /I "..\..\vicii" /I "..\..\raster" /I "..\..\monitor" /D "WIN32" /D "IDE_COMPILE" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "cbm2common - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "libs\cbm2common\Debug"
# PROP Intermediate_Dir "libs\cbm2common\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MTd /W3 /GX /Z7 /Od /I ".\msvc" /I ".\\" /I "..\..\\" /I "..\..\drive" /I "..\..\userport" /I "..\..\tape" /I "..\..\sid" /I "..\..\crtc" /I "..\..\vicii" /I "..\..\raster" /I "..\..\monitor" /D "WIN32" /D "IDE_COMPILE" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
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

# Name "cbm2common - Win32 Release"
# Name "cbm2common - Win32 Debug"
# Begin Source File

SOURCE="..\..\cbm2\cbm2-cmdline-options.c"
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2acia1.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2bus.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2cart.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2cia1.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2cpu.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2datasette.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2drive.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2iec.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2memsnapshot.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2model.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2printer.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2romset.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2sound.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2tpi1.c
# End Source File
# Begin Source File

SOURCE=..\..\cbm2\cbm2tpi2.c
# End Source File
# End Target
# End Project
