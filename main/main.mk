##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=main
ConfigurationName      :=Debug
WorkspacePath          := "C:\Repositories\cpp-regex-golf"
ProjectPath            := "C:\Repositories\cpp-regex-golf\main"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=akos
Date                   :=04/19/15
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe 
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="main.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)./include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe 
CC       := C:/TDM-GCC-64/bin/gcc.exe 
CXXFLAGS :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/FileHandler.cpp$(ObjectSuffix) $(IntermediateDirectory)/JsonParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/DirRaii.cpp$(ObjectSuffix) $(IntermediateDirectory)/FileRaii.cpp$(ObjectSuffix) $(IntermediateDirectory)/RegexTester.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/Level.cpp$(ObjectSuffix) $(IntermediateDirectory)/Util.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Repositories/cpp-regex-golf/main/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/FileHandler.cpp$(ObjectSuffix): FileHandler.cpp $(IntermediateDirectory)/FileHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Repositories/cpp-regex-golf/main/FileHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FileHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FileHandler.cpp$(DependSuffix): FileHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FileHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/FileHandler.cpp$(DependSuffix) -MM "FileHandler.cpp"

$(IntermediateDirectory)/FileHandler.cpp$(PreprocessSuffix): FileHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FileHandler.cpp$(PreprocessSuffix) "FileHandler.cpp"

$(IntermediateDirectory)/JsonParser.cpp$(ObjectSuffix): JsonParser.cpp $(IntermediateDirectory)/JsonParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Repositories/cpp-regex-golf/main/JsonParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/JsonParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/JsonParser.cpp$(DependSuffix): JsonParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/JsonParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/JsonParser.cpp$(DependSuffix) -MM "JsonParser.cpp"

$(IntermediateDirectory)/JsonParser.cpp$(PreprocessSuffix): JsonParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/JsonParser.cpp$(PreprocessSuffix) "JsonParser.cpp"

$(IntermediateDirectory)/DirRaii.cpp$(ObjectSuffix): DirRaii.cpp $(IntermediateDirectory)/DirRaii.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Repositories/cpp-regex-golf/main/DirRaii.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DirRaii.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DirRaii.cpp$(DependSuffix): DirRaii.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DirRaii.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DirRaii.cpp$(DependSuffix) -MM "DirRaii.cpp"

$(IntermediateDirectory)/DirRaii.cpp$(PreprocessSuffix): DirRaii.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DirRaii.cpp$(PreprocessSuffix) "DirRaii.cpp"

$(IntermediateDirectory)/FileRaii.cpp$(ObjectSuffix): FileRaii.cpp $(IntermediateDirectory)/FileRaii.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Repositories/cpp-regex-golf/main/FileRaii.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FileRaii.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FileRaii.cpp$(DependSuffix): FileRaii.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FileRaii.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/FileRaii.cpp$(DependSuffix) -MM "FileRaii.cpp"

$(IntermediateDirectory)/FileRaii.cpp$(PreprocessSuffix): FileRaii.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FileRaii.cpp$(PreprocessSuffix) "FileRaii.cpp"

$(IntermediateDirectory)/RegexTester.cpp$(ObjectSuffix): RegexTester.cpp $(IntermediateDirectory)/RegexTester.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Repositories/cpp-regex-golf/main/RegexTester.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RegexTester.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RegexTester.cpp$(DependSuffix): RegexTester.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RegexTester.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RegexTester.cpp$(DependSuffix) -MM "RegexTester.cpp"

$(IntermediateDirectory)/RegexTester.cpp$(PreprocessSuffix): RegexTester.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RegexTester.cpp$(PreprocessSuffix) "RegexTester.cpp"

$(IntermediateDirectory)/Game.cpp$(ObjectSuffix): Game.cpp $(IntermediateDirectory)/Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Repositories/cpp-regex-golf/main/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game.cpp$(DependSuffix): Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game.cpp$(DependSuffix) -MM "Game.cpp"

$(IntermediateDirectory)/Game.cpp$(PreprocessSuffix): Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game.cpp$(PreprocessSuffix) "Game.cpp"

$(IntermediateDirectory)/Level.cpp$(ObjectSuffix): Level.cpp $(IntermediateDirectory)/Level.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Repositories/cpp-regex-golf/main/Level.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Level.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Level.cpp$(DependSuffix): Level.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Level.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Level.cpp$(DependSuffix) -MM "Level.cpp"

$(IntermediateDirectory)/Level.cpp$(PreprocessSuffix): Level.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Level.cpp$(PreprocessSuffix) "Level.cpp"

$(IntermediateDirectory)/Util.cpp$(ObjectSuffix): Util.cpp $(IntermediateDirectory)/Util.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Repositories/cpp-regex-golf/main/Util.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Util.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Util.cpp$(DependSuffix): Util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Util.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Util.cpp$(DependSuffix) -MM "Util.cpp"

$(IntermediateDirectory)/Util.cpp$(PreprocessSuffix): Util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Util.cpp$(PreprocessSuffix) "Util.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


