# Microsoft Developer Studio Project File - Name="pet" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=pet - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "pet.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "pet.mak" CFG="pet - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "pet - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "pet - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "pet - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "libs\pet\Release"
# PROP Intermediate_Dir "libs\pet\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\\" /I "..\..\..\drive" /I "..\..\..\userport" /I "..\..\..\tape" /I "..\..\..\crtc" /I "..\..\..\raster" /I "..\..\..\monitor" /I "..\..\..\sid" /D "WIN32" /D "IDE_COMPILE" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "pet - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "libs\pet\Debug"
# PROP Intermediate_Dir "libs\pet\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /GX /Z7 /Od /I ".\\" /I "..\\" /I "..\..\..\\" /I "..\..\..\drive" /I "..\..\..\userport" /I "..\..\..\tape" /I "..\..\..\crtc" /I "..\..\..\raster" /I "..\..\..\monitor" /I "..\..\..\sid" /D "WIN32" /D "IDE_COMPILE" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
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

# Name "pet - Win32 Release"
# Name "pet - Win32 Debug"
# Begin Source File

SOURCE="..\..\..\pet\pet-cmdline-options.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\pet\pet-resources.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\pet\pet-sidcart.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\pet\pet-snapshot.c"
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\pet.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petacia1.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petbus.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petdatasette.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petdrive.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petdww.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petiec.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petmem.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petmemsnapshot.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petpia1.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petpia2.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petprinter.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petreu.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petrom.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petromset.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petsound.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petvia.c
# End Source File
# Begin Source File

SOURCE=..\..\..\pet\petvideo.c
# End Source File
# End Target
# End Project
