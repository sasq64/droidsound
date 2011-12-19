# Microsoft Developer Studio Project File - Name="serial" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=serial - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "serial.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "serial.mak" CFG="serial - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "serial - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "serial - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "serial - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "libs\serial\Release"
# PROP Intermediate_Dir "libs\serial\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\\" /I "..\..\..\vdrive" /I "..\..\..\drive" /D "WIN32" /D "IDE_COMPILE" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "serial - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "libs\serial\Debug"
# PROP Intermediate_Dir "libs\serial\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /GX /Z7 /Od /I ".\\" /I "..\\" /I "..\..\..\\" /I "..\..\..\vdrive" /I "..\..\..\drive" /D "WIN32" /D "IDE_COMPILE" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
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

# Name "serial - Win32 Release"
# Name "serial - Win32 Debug"
# Begin Source File

SOURCE="..\..\..\serial\fsdrive.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\serial\realdevice.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\serial\serial-device.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\serial\serial-iec-bus.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\serial\serial-iec-device.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\serial\serial-iec-lib.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\serial\serial-iec.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\serial\serial-realdevice.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\serial\serial-trap.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\serial\serial.c"
# End Source File
# End Target
# End Project
