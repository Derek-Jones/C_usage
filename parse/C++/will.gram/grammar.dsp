# Microsoft Developer Studio Project File - Name="grammar" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Generic Project" 0x010a

CFG=grammar - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "grammar.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "grammar.mak" CFG="grammar - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "grammar - Win32 Release" (based on "Win32 (x86) Generic Project")
!MESSAGE "grammar - Win32 Debug" (based on "Win32 (x86) Generic Project")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/root/grammar", BXCAAAAA"
# PROP Scc_LocalPath "."
MTL=midl.exe

!IF  "$(CFG)" == "grammar - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "grammar - Win32 Release"
# Name "grammar - Win32 Debug"
# Begin Group "Targets"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Targets\backup

!IF  "$(CFG)" == "grammar - Win32 Release"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Release
OutDir=.\Release
InputPath=.\Targets\backup
InputName=backup

"$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(InputName) INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\Targets\backup
InputName=backup

"$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(InputName) INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Targets\clean

!IF  "$(CFG)" == "grammar - Win32 Release"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Release
OutDir=.\Release
InputPath=.\Targets\clean
InputName=clean

"$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(InputName) INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\Targets\clean
InputName=clean

"$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(InputName) INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Targets\executable

!IF  "$(CFG)" == "grammar - Win32 Release"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Release
OutDir=.\Release
InputPath=.\Targets\executable
InputName=executable

"$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(InputName) INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\Targets\executable
InputName=executable

"$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(InputName) INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Targets\realclean

!IF  "$(CFG)" == "grammar - Win32 Release"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Release
OutDir=.\Release
InputPath=.\Targets\realclean
InputName=realclean

"$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(InputName) INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\Targets\realclean
InputName=realclean

"$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(InputName) INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Targets\source_kit

!IF  "$(CFG)" == "grammar - Win32 Release"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Release
OutDir=.\Release
InputPath=.\Targets\source_kit
InputName=source_kit

"$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(InputName) INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\Targets\source_kit
InputName=source_kit

"$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(InputName) INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Targets\tar_delta

!IF  "$(CFG)" == "grammar - Win32 Release"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Release
OutDir=.\Release
InputPath=.\Targets\tar_delta
InputName=tar_delta

"$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(InputName) INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\Targets\tar_delta
InputName=tar_delta

"$(InputName)" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(InputName) INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Make Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\makefile
# End Source File
# Begin Source File

SOURCE=.\makefile.gmake
# End Source File
# Begin Source File

SOURCE=.\makefile.macros
# End Source File
# Begin Source File

SOURCE=.\makefile.unix
# End Source File
# End Group
# Begin Group "Listings"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Listings\CxxLexer.list

!IF  "$(CFG)" == "grammar - Win32 Release"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Release
OutDir=.\Release
InputPath=.\Listings\CxxLexer.list
InputName=CxxLexer

"$(InputName).tmp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake Listings/$(InputName).list  INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\Listings\CxxLexer.list
InputName=CxxLexer

"$(InputName).tmp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake Listings/$(InputName).list  INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Listings\CxxMake.list

!IF  "$(CFG)" == "grammar - Win32 Release"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Release
OutDir=.\Release
InputPath=.\Listings\CxxMake.list
InputName=CxxMake

"$(InputName).tmp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake Listings/$(InputName).list  INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\Listings\CxxMake.list
InputName=CxxMake

"$(InputName).tmp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake Listings/$(InputName).list  INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Listings\CxxParser.list

!IF  "$(CFG)" == "grammar - Win32 Release"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Release
OutDir=.\Release
InputPath=.\Listings\CxxParser.list
InputName=CxxParser

"$(InputName).tmp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake Listings/$(InputName).list  INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\Listings\CxxParser.list
InputName=CxxParser

"$(InputName).tmp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake Listings/$(InputName).list  INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Listings\CxxToken.list

!IF  "$(CFG)" == "grammar - Win32 Release"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Release
OutDir=.\Release
InputPath=.\Listings\CxxToken.list
InputName=CxxToken

"$(InputName).tmp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake Listings/$(InputName).list  INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# Begin Custom Build - Make $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\Listings\CxxToken.list
InputName=CxxToken

"$(InputName).tmp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake Listings/$(InputName).list  INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "cpp Files"

# PROP Default_Filter "cpp"
# Begin Source File

SOURCE=.\CxxLexer.cpp

!IF  "$(CFG)" == "grammar - Win32 Release"

# Begin Custom Build - $(InputPath)
IntDir=.\Release
OutDir=.\Release
InputPath=.\CxxLexer.cpp
InputName=CxxLexer

"$(INTDIR)/$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(INTDIR)/$(InputName).obj INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# Begin Custom Build - $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\CxxLexer.cpp
InputName=CxxLexer

"$(INTDIR)/$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(INTDIR)/$(InputName).obj INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CxxParser.cpp

!IF  "$(CFG)" == "grammar - Win32 Release"

# Begin Custom Build - $(InputPath)
IntDir=.\Release
OutDir=.\Release
InputPath=.\CxxParser.cpp
InputName=CxxParser

"$(INTDIR)/$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(INTDIR)/$(InputName).obj INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# Begin Custom Build - $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\CxxParser.cpp
InputName=CxxParser

"$(INTDIR)/$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(INTDIR)/$(InputName).obj INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\CxxToken.cpp

!IF  "$(CFG)" == "grammar - Win32 Release"

# Begin Custom Build - $(InputPath)
IntDir=.\Release
OutDir=.\Release
InputPath=.\CxxToken.cpp
InputName=CxxToken

"$(INTDIR)/$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(INTDIR)/$(InputName).obj INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ELSEIF  "$(CFG)" == "grammar - Win32 Debug"

# Begin Custom Build - $(InputPath)
IntDir=.\Debug
OutDir=.\Debug
InputPath=.\CxxToken.cpp
InputName=CxxToken

"$(INTDIR)/$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	make --unix  -f makefile.gmake $(INTDIR)/$(InputName).obj INTDIR=$(IntDir) OUTDIR=$(OutDir) MSINCDIR="$(MSDEVDIR)/../../VC98/Include"

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Documentation Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\index.html
# End Source File
# Begin Source File

SOURCE=.\README
# End Source File
# End Group
# Begin Group "Source Files"

# PROP Default_Filter "cxx;hxx;l;y"
# Begin Source File

SOURCE=.\CxxLexer.l
# End Source File
# Begin Source File

SOURCE=.\CxxLexing.cxx
# End Source File
# Begin Source File

SOURCE=.\CxxLexing.hxx
# End Source File
# Begin Source File

SOURCE=.\CxxParser.y
# End Source File
# Begin Source File

SOURCE=.\CxxParsing.cxx
# End Source File
# Begin Source File

SOURCE=.\CxxParsing.hxx
# End Source File
# Begin Source File

SOURCE=.\CxxToken.cxx
# End Source File
# Begin Source File

SOURCE=.\CxxToken.hxx
# End Source File
# End Group
# End Target
# End Project
