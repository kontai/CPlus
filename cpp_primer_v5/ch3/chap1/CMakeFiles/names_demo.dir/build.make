# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kontai/workspace/CPlus/cpp_primer_v5/ch3/chap1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kontai/workspace/CPlus/cpp_primer_v5/ch3/chap1

# Include any dependencies generated for this target.
include CMakeFiles/names_demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/names_demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/names_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/names_demo.dir/flags.make

CMakeFiles/names_demo.dir/names_demo.cpp.o: CMakeFiles/names_demo.dir/flags.make
CMakeFiles/names_demo.dir/names_demo.cpp.o: names_demo.cpp
CMakeFiles/names_demo.dir/names_demo.cpp.o: CMakeFiles/names_demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kontai/workspace/CPlus/cpp_primer_v5/ch3/chap1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/names_demo.dir/names_demo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/names_demo.dir/names_demo.cpp.o -MF CMakeFiles/names_demo.dir/names_demo.cpp.o.d -o CMakeFiles/names_demo.dir/names_demo.cpp.o -c /home/kontai/workspace/CPlus/cpp_primer_v5/ch3/chap1/names_demo.cpp

CMakeFiles/names_demo.dir/names_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/names_demo.dir/names_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kontai/workspace/CPlus/cpp_primer_v5/ch3/chap1/names_demo.cpp > CMakeFiles/names_demo.dir/names_demo.cpp.i

CMakeFiles/names_demo.dir/names_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/names_demo.dir/names_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kontai/workspace/CPlus/cpp_primer_v5/ch3/chap1/names_demo.cpp -o CMakeFiles/names_demo.dir/names_demo.cpp.s

# Object files for target names_demo
names_demo_OBJECTS = \
"CMakeFiles/names_demo.dir/names_demo.cpp.o"

# External object files for target names_demo
names_demo_EXTERNAL_OBJECTS =

names_demo: CMakeFiles/names_demo.dir/names_demo.cpp.o
names_demo: CMakeFiles/names_demo.dir/build.make
names_demo: CMakeFiles/names_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/kontai/workspace/CPlus/cpp_primer_v5/ch3/chap1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable names_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/names_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/names_demo.dir/build: names_demo
.PHONY : CMakeFiles/names_demo.dir/build

CMakeFiles/names_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/names_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/names_demo.dir/clean

CMakeFiles/names_demo.dir/depend:
	cd /home/kontai/workspace/CPlus/cpp_primer_v5/ch3/chap1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kontai/workspace/CPlus/cpp_primer_v5/ch3/chap1 /home/kontai/workspace/CPlus/cpp_primer_v5/ch3/chap1 /home/kontai/workspace/CPlus/cpp_primer_v5/ch3/chap1 /home/kontai/workspace/CPlus/cpp_primer_v5/ch3/chap1 /home/kontai/workspace/CPlus/cpp_primer_v5/ch3/chap1/CMakeFiles/names_demo.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/names_demo.dir/depend

