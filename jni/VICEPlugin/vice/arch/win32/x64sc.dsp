# Microsoft Developer Studio Project File - Name="x64sc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=x64sc - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "x64sc.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "x64sc.mak" CFG="x64sc - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "x64sc - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "x64sc - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "x64sc - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\data"
# PROP Intermediate_Dir "libs\x64sc\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I ".\msvc" /I ".\\" /I "..\\" /I "..\..\\" /I "..\..\drive" /I "..\..\vdrive" /I "..\..\monitor" /D "WIN32" /D "IDE_COMPILE" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /i ".\MSVC" /i ".\\" /i "..\..\\" /d "NDEBUG" /d "WIN32" /d "IDE_COMPILE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib comctl32.lib winmm.lib ddraw.lib dsound.lib ole32.lib dxguid.lib wsock32.lib version.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "x64sc - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\data"
# PROP Intermediate_Dir "libs\x64sc\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MTd /W3 /GX /Z7 /Od /I ".\msvc" /I ".\\" /I "..\\" /I "..\..\\" /I "..\..\drive" /I "..\..\vdrive" /I "..\..\monitor" /D "WIN32" /D "IDE_COMPILE" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /i ".\MSVC" /i ".\\" /i "..\..\\" /d "_DEBUG" /d "WIN32" /d "IDE_COMPILE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 dxguid.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib comctl32.lib winmm.lib ddraw.lib dsound.lib ole32.lib wsock32.lib version.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "x64sc - Win32 Release"
# Name "x64sc - Win32 Debug"
# Begin Source File

SOURCE=..\..\main.c
# End Source File
# Begin Source File

SOURCE=.\resc64.rc

!IF  "$(CFG)" == "x64sc - Win32 Release"

# PROP Ignore_Default_Tool 1
USERDEP__RESC6="..\..\debug.h"	"resc64.rc"	"res.rc"	"resacia.rc"	"resdrivec64.rc"	"reside64.rc"	"resreu.rc"	"resgeoram.rc"	"resramcart.rc"	"resplus256k.rc"	"resplus60k.rc"	"resc64_256k.rc"	"resmmc64.rc"	"resmmcreplay.rc"	"resrs232user.rc"	"ressid.rc"	"resvicii.rc"	"resdigimax.rc"	"resmouse.rc"	"resmidi.rc"	"resdqbb.rc"	"resisepic.rc"	"reslightpen.rc"	"ressoundexpander.rc"	"reseasyflash.rc"	"resautostart.rc"	"resmagicvoice.rc"	"resexpert.rc"	"restfe.rc"	
# Begin Custom Build
InputPath=.\resc64.rc

"resc64cat.rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy /b resc64.rc + res.rc + resacia.rc + resdrivec64.rc + reside64.rc + resreu.rc + resgeoram.rc + resramcart.rc + resplus256k.rc + resplus60k.rc + resc64_256k.rc + resmmc64.rc + resmmcreplay.rc + resrs232user.rc + ressid.rc + resvicii.rc + resdigimax.rc + resmouse.rc + resmidi.rc + resdqbb.rc + resisepic.rc + reslightpen.rc + ressoundexpander.rc + reseasyflash.rc + resautostart.rc + resmagicvoice.rc + resexpert.rc + restfe.rc resc64cat.rc /b

# End Custom Build

!ELSEIF  "$(CFG)" == "x64sc - Win32 Debug"

# PROP Ignore_Default_Tool 1
USERDEP__RESC6="..\..\debug.h"	"resc64.rc"	"res.rc"	"resacia.rc"	"resdrivec64.rc"	"reside64.rc"	"resreu.rc"	"resgeoram.rc"	"resramcart.rc"	"resplus256k.rc"	"resplus60k.rc"	"resc64_256k.rc"	"resmmc64.rc"	"resmmcreplay.rc"	"resrs232user.rc"	"ressid.rc"	"resvicii.rc"	"resdigimax.rc"	"resmouse.rc"	"resmidi.rc"	"resdqbb.rc"	"resisepic.rc"	"reslightpen.rc"	"ressoundexpander.rc"	"reseasyflash.rc"	"resautostart.rc"	"resmagicvoice.rc"	"resexpert.rc"	"restfe.rc"	
# Begin Custom Build
InputPath=.\resc64.rc

"resc64cat.rc" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy /b resc64.rc + res.rc + resacia.rc + resdrivec64.rc + reside64.rc + resreu.rc + resgeoram.rc + resramcart.rc + resplus256k.rc + resplus60k.rc + resc64_256k.rc + resmmc64.rc + resmmcreplay.rc + resrs232user.rc + ressid.rc + resvicii.rc + resdigimax.rc + resmouse.rc + resmidi.rc + resdqbb.rc + resisepic.rc + reslightpen.rc + ressoundexpander.rc + reseasyflash.rc + resautostart.rc + resmagicvoice.rc + resexpert.rc + restfe.rc resc64cat.rc /b

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\resc64cat.rc
# End Source File
# Begin Source File

SOURCE=.\vice.manifest
# End Source File
# End Target
# End Project
