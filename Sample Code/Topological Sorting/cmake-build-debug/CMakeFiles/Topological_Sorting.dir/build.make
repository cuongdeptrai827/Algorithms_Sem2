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
CMAKE_SOURCE_DIR = "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Sample Code\Topological Sorting"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Sample Code\Topological Sorting\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Topological_Sorting.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Topological_Sorting.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Topological_Sorting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Topological_Sorting.dir/flags.make

CMakeFiles/Topological_Sorting.dir/main.cpp.obj: CMakeFiles/Topological_Sorting.dir/flags.make
CMakeFiles/Topological_Sorting.dir/main.cpp.obj: C:/Coding/Môn\ Algorithms/Semester\ 2/Algorithms_Sem2/Sample\ Code/Topological\ Sorting/main.cpp
CMakeFiles/Topological_Sorting.dir/main.cpp.obj: CMakeFiles/Topological_Sorting.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Sample Code\Topological Sorting\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Topological_Sorting.dir/main.cpp.obj"
	C:\Users\nguye\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Topological_Sorting.dir/main.cpp.obj -MF CMakeFiles\Topological_Sorting.dir\main.cpp.obj.d -o CMakeFiles\Topological_Sorting.dir\main.cpp.obj -c "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Sample Code\Topological Sorting\main.cpp"

CMakeFiles/Topological_Sorting.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Topological_Sorting.dir/main.cpp.i"
	C:\Users\nguye\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Sample Code\Topological Sorting\main.cpp" > CMakeFiles\Topological_Sorting.dir\main.cpp.i

CMakeFiles/Topological_Sorting.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Topological_Sorting.dir/main.cpp.s"
	C:\Users\nguye\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Sample Code\Topological Sorting\main.cpp" -o CMakeFiles\Topological_Sorting.dir\main.cpp.s

# Object files for target Topological_Sorting
Topological_Sorting_OBJECTS = \
"CMakeFiles/Topological_Sorting.dir/main.cpp.obj"

# External object files for target Topological_Sorting
Topological_Sorting_EXTERNAL_OBJECTS =

Topological_Sorting.exe: CMakeFiles/Topological_Sorting.dir/main.cpp.obj
Topological_Sorting.exe: CMakeFiles/Topological_Sorting.dir/build.make
Topological_Sorting.exe: CMakeFiles/Topological_Sorting.dir/linkLibs.rsp
Topological_Sorting.exe: CMakeFiles/Topological_Sorting.dir/objects1.rsp
Topological_Sorting.exe: CMakeFiles/Topological_Sorting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Sample Code\Topological Sorting\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Topological_Sorting.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Topological_Sorting.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Topological_Sorting.dir/build: Topological_Sorting.exe
.PHONY : CMakeFiles/Topological_Sorting.dir/build

CMakeFiles/Topological_Sorting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Topological_Sorting.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Topological_Sorting.dir/clean

CMakeFiles/Topological_Sorting.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Sample Code\Topological Sorting" "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Sample Code\Topological Sorting" "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Sample Code\Topological Sorting\cmake-build-debug" "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Sample Code\Topological Sorting\cmake-build-debug" "C:\Coding\Môn Algorithms\Semester 2\Algorithms_Sem2\Sample Code\Topological Sorting\cmake-build-debug\CMakeFiles\Topological_Sorting.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Topological_Sorting.dir/depend
