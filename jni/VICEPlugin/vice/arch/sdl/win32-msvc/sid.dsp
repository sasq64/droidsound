# Microsoft Developer Studio Project File - Name="sid" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=sid - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "sid.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "sid.mak" CFG="sid - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "sid - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "sid - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "sid - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "libs\sid\Release"
# PROP Intermediate_Dir "libs\sid\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\\" /I "..\..\..\\" /I "..\..\..\resid" /D "WIN32" /D "IDE_COMPILE" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "sid - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "libs\sid\Debug"
# PROP Intermediate_Dir "libs\sid\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /GX /Z7 /Od /I ".\\" /I "..\\" /I "..\..\..\\" /I "..\..\..\resid" /D "WIN32" /D "IDE_COMPILE" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
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

# Name "sid - Win32 Release"
# Name "sid - Win32 Debug"
# Begin Source File

SOURCE=..\..\..\sid\fastsid.c
# End Source File
# Begin Source File

SOURCE="..\..\..\sid\resid-fp.cc"

!IF  "$(CFG)" == "sid - Win32 Release"

# Begin Custom Build
InputPath="..\..\..\sid\resid-fp.cc"
InputName=resid-fp

"libs\sid\Release/$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /MD /W3 /EHsc /I ".\\" /D "NDEBUG" /I "..\\" /I "..\..\..\\" /I "..\..\..\resid-fp" /D "WIN32" /D "IDE_COMPILE" /D "_WINDOWS" /Fp"libs\sid\Release/sid.pch" /Fo"libs\sid\Release/" /Fd"libs\sid\Release/" /FD /TP /c "$(InputPath)"

# End Custom Build

!ELSEIF  "$(CFG)" == "sid - Win32 Debug"

# Begin Custom Build
InputPath="..\..\..\sid\resid-fp.cc"
InputName=resid-fp

"libs\sid\Debug/$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /MDd /W3 /EHsc /Z7 /Od /I ".\\" /I "..\\" /I "..\..\..\\" /I "..\..\..\resid-fp" /D "WIN32" /D "IDE_COMPILE" /D "_DEBUG" /D "_WINDOWS" /Fp"libs\sid\Debug/sid.pch" /Fo"libs\sid\Debug/" /Fd"libs\sid\Debug/" /FD /TP /c "$(InputPath)"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\sid\resid.cc

!IF  "$(CFG)" == "sid - Win32 Release"

# Begin Custom Build
InputPath=..\..\..\sid\resid.cc
InputName=resid

"libs\sid\Release/$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /MD /W3 /EHsc /I ".\\" /D "NDEBUG" /I "..\\" /I "..\..\..\\" /I "..\..\..\resid" /D "WIN32" /D "IDE_COMPILE" /D "_WINDOWS" /Fp"libs\sid\Release/sid.pch" /Fo"libs\sid\Release/" /Fd"libs\sid\Release/" /FD /TP /c "$(InputPath)"

# End Custom Build

!ELSEIF  "$(CFG)" == "sid - Win32 Debug"

# Begin Custom Build
InputPath=..\..\..\sid\resid.cc
InputName=resid

"libs\sid\Debug/$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	cl /nologo /MDd /W3 /EHsc /Z7 /Od /I ".\\" /I "..\\" /I "..\..\..\\" /I "..\..\..\resid" /D "WIN32" /D "IDE_COMPILE" /D "_DEBUG" /D "_WINDOWS" /Fp"libs\sid\Debug/sid.pch" /Fo"libs\sid\Debug/" /Fd"libs\sid\Debug/" /FD /TP /c "$(InputPath)"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\sid\sid-cmdline-options.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\sid\sid-resources.c"
# End Source File
# Begin Source File

SOURCE="..\..\..\sid\sid-snapshot.c"
# End Source File
# Begin Source File

SOURCE=..\..\..\sid\sid.c
# End Source File
# End Target
# End Project
