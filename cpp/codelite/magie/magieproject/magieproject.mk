##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            =magieproject
ConfigurationName      =Debug
WorkspaceConfiguration =Debug
WorkspacePath          =C:\Users\lucas\Documents\GitHub\cpp\cpp\codelite\magie
ProjectPath            =C:\Users\lucas\Documents\GitHub\cpp\cpp\codelite\magie\magieproject
IntermediateDirectory  =$(ConfigurationName)
OutDir                 =$(IntermediateDirectory)
CurrentFileName        =
CurrentFilePath        =
CurrentFileFullPath    =
User                   =lucas
Date                   =21/11/2022
CodeLitePath           ="C:\Program Files\CodeLite"
LinkerName             =C:\MinGW\bin\g++.exe 
SharedObjectLinkerName =C:\MinGW\bin\g++.exe -shared -fPIC
ObjectSuffix           =.o
DependSuffix           =.o.d
PreprocessSuffix       =.i
DebugSwitch            =-g 
IncludeSwitch          =-I
LibrarySwitch          =-l
OutputSwitch           =-o 
LibraryPathSwitch      =-L
PreprocessorSwitch     =-D
SourceSwitch           =-c 
OutputDirectory        =C:\Users\lucas\Documents\GitHub\cpp\cpp\codelite\magie\$(WorkspaceConfiguration)
OutputFile             =..\$(WorkspaceConfiguration)\$(ProjectName).exe
Preprocessors          =
ObjectSwitch           =-o 
ArchiveOutputSwitch    = 
PreprocessOnlySwitch   =-E
ObjectsFileList        ="magieproject.txt"
MakeDirCommand         =makedir
RcCmpOptions           = 
RcCompilerName         =C:\MinGW\bin\windres.exe
LinkOptions            =  
PCHCreateFlags         =
PCHUseFlags            =
IncludePath            =  $(IncludeSwitch). $(IncludeSwitch). 
RcIncludePath          = 
Libs                   = 
ArLibs                 =  
LibPath                = $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       = C:\MinGW\bin\ar.exe rcu
CXX      = C:\MinGW\bin\g++.exe 
CC       = C:\MinGW\bin\gcc.exe 
CXXFLAGS =  -g -O0 -Wall $(Preprocessors)
CFLAGS   =  -g -O0 -Wall $(Preprocessors)
ASFLAGS  = 
AS       = C:\MinGW\bin\as.exe 


##
## User defined environment variables
##
CodeLiteDir=C:\Program Files\CodeLite


##
## Object Targets Lists 
##
Objects0=$(IntermediateDirectory)\main.cpp$(ObjectSuffix) $(IntermediateDirectory)\Personne.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)\.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)\.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
.PHONY: clean PrePreBuild PreBuild MakeIntermediateDirs all PostBuild 

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"


$(IntermediateDirectory)\.d:
	@echo Creating Intermediate Directory
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo Intermediate directories created
PreBuild:


##
## Objects
##
$(IntermediateDirectory)\main.cpp$(ObjectSuffix): main.cpp 
	$(CXX) $(PCHUseFlags) $(SourceSwitch) "C:\Users\lucas\Documents\GitHub\cpp\cpp\codelite\magie\magieproject\main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)\main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(PCHUseFlags) $(IncludePath) $(PreprocessOnlySwitch) $(IntermediateDirectory)\main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)\Personne.cpp$(ObjectSuffix): Personne.cpp 
	$(CXX) $(PCHUseFlags) $(SourceSwitch) "C:\Users\lucas\Documents\GitHub\cpp\cpp\codelite\magie\magieproject\Personne.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Personne.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)\Personne.cpp$(PreprocessSuffix): Personne.cpp
	$(CXX) $(CXXFLAGS) $(PCHUseFlags) $(IncludePath) $(PreprocessOnlySwitch) $(IntermediateDirectory)\Personne.cpp$(PreprocessSuffix) "Personne.cpp"

##
## Clean
##
clean:
	@if exist "$(IntermediateDirectory)" rmdir /S /Q "$(IntermediateDirectory)"


