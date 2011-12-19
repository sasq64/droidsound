# Microsoft Developer Studio Project File - Name="vic20" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=vic20 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "vic20.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "vic20.mak" CFG="vic20 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "vic20 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "vic20 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "vic20 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "libs\vic20\Release"
# PROP Intermediate_Dir "libs\vic20\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I ".\msvc" /I ".\\" /I "..\..\\" /I "..\..\drive" /I "..\..\userport" /I "..\..\tape" /I "..\..\raster" /I "..\..\monitor" /I "..\..\sid" /I "..\..\vic20\cart" /D "WIN32" /D "IDE_COMPILE" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "vic20 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "libs\vic20\Debug"
# PROP Intermediate_Dir "libs\vic20\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MTd /W3 /GX /Z7 /Od /I ".\msvc" /I ".\\" /I "..\..\\" /I "..\..\drive" /I "..\..\userport" /I "..\..\tape" /I "..\..\raster" /I "..\..\monitor" /I "..\..\sid" /I "..\..\vic20\cart" /D "WIN32" /D "IDE_COMPILE" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
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

# Name "vic20 - Win32 Release"
# Name "vic20 - Win32 Debug"
# Begin Source File

SOURCE="..\..\vic20\vic-cmdline-options.c"
# End Source File
# Begin Source File

SOURCE="..\..\vic20\vic-color.c"
# End Source File
# Begin Source File

SOURCE="..\..\vic20\vic-cycle.c"
# End Source File
# Begin Source File

SOURCE="..\..\vic20\vic-draw.c"
# End Source File
# Begin Source File

SOURCE="..\..\vic20\vic-mem.c"
# End Source File
# Begin Source File

SOURCE="..\..\vic20\vic-resources.c"
# End Source File
# Begin Source File

SOURCE="..\..\vic20\vic-snapshot.c"
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic.c
# End Source File
# Begin Source File

SOURCE="..\..\vic20\vic20-cmdline-options.c"
# End Source File
# Begin Source File

SOURCE="..\..\vic20\vic20-resources.c"
# End Source File
# Begin Source File

SOURCE="..\..\vic20\vic20-snapshot.c"
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20bus.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20cpu.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20datasette.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20drive.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20iec.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20ieeevia1.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20ieeevia2.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20io.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20mem.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20memrom.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20memsnapshot.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20printer.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20rom.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20romset.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20rsuser.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20sound.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20via1.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20via2.c
# End Source File
# Begin Source File

SOURCE=..\..\vic20\vic20video.c
# End Source File
# End Target
# End Project
