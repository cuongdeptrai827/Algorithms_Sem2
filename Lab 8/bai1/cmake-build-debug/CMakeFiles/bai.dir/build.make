# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\nguye\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\nguye\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Lab 1\bai1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Lab 1\bai1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/bai.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bai.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bai.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bai.dir/flags.make

CMakeFiles/bai.dir/bai1.cpp.obj: CMakeFiles/bai.dir/flags.make
CMakeFiles/bai.dir/bai1.cpp.obj: C:/Coding/Môn\ Algorithms/Semester\ 2/Algorithms_Sem2/Lab\ 1/bai1/bai1.cpp
CMakeFiles/bai.dir/bai1.cpp.obj: CMakeFiles/bai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Lab 1\bai1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bai.dir/bai1.cpp.obj"
	C:\Users\nguye\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bai.dir/bai1.cpp.obj -MF CMakeFiles\bai.dir\bai1.cpp.obj.d -o CMakeFiles\bai.dir\bai1.cpp.obj -c "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Lab 1\bai1\bai1.cpp"

CMakeFiles/bai.dir/bai1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/bai.dir/bai1.cpp.i"
	C:\Users\nguye\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Lab 1\bai1\bai1.cpp" > CMakeFiles\bai.dir\bai1.cpp.i

CMakeFiles/bai.dir/bai1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/bai.dir/bai1.cpp.s"
	C:\Users\nguye\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Lab 1\bai1\bai1.cpp" -o CMakeFiles\bai.dir\bai1.cpp.s

# Object files for target bai
bai_OBJECTS = \
"CMakeFiles/bai.dir/bai1.cpp.obj"

# External object files for target bai
bai_EXTERNAL_OBJECTS =

bai.exe: CMakeFiles/bai.dir/bai1.cpp.obj
bai.exe: CMakeFiles/bai.dir/build.make
bai.exe: CMakeFiles/bai.dir/linkLibs.rsp
bai.exe: CMakeFiles/bai.dir/objects1.rsp
bai.exe: CMakeFiles/bai.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Lab 1\bai1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bai.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bai.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bai.dir/build: bai.exe
.PHONY : CMakeFiles/bai.dir/build

CMakeFiles/bai.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bai.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bai.dir/clean

CMakeFiles/bai.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Lab 1\bai1" "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Lab 1\bai1" "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Lab 1\bai1\cmake-build-debug" "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Lab 1\bai1\cmake-build-debug" "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Lab 1\bai1\cmake-build-debug\CMakeFiles\bai.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/bai.dir/depend
