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
CMAKE_COMMAND = /home/linuxbrew/.linuxbrew/Cellar/cmake/3.27.5/bin/cmake

# The command to remove a file.
RM = /home/linuxbrew/.linuxbrew/Cellar/cmake/3.27.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspace/ChadC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspace/ChadC

# Include any dependencies generated for this target.
include CMakeFiles/chad_compiler.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chad_compiler.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chad_compiler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chad_compiler.dir/flags.make

CMakeFiles/chad_compiler.dir/main.cpp.o: CMakeFiles/chad_compiler.dir/flags.make
CMakeFiles/chad_compiler.dir/main.cpp.o: main.cpp
CMakeFiles/chad_compiler.dir/main.cpp.o: CMakeFiles/chad_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspace/ChadC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chad_compiler.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chad_compiler.dir/main.cpp.o -MF CMakeFiles/chad_compiler.dir/main.cpp.o.d -o CMakeFiles/chad_compiler.dir/main.cpp.o -c /workspace/ChadC/main.cpp

CMakeFiles/chad_compiler.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chad_compiler.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspace/ChadC/main.cpp > CMakeFiles/chad_compiler.dir/main.cpp.i

CMakeFiles/chad_compiler.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chad_compiler.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspace/ChadC/main.cpp -o CMakeFiles/chad_compiler.dir/main.cpp.s

# Object files for target chad_compiler
chad_compiler_OBJECTS = \
"CMakeFiles/chad_compiler.dir/main.cpp.o"

# External object files for target chad_compiler
chad_compiler_EXTERNAL_OBJECTS =

chad_compiler: CMakeFiles/chad_compiler.dir/main.cpp.o
chad_compiler: CMakeFiles/chad_compiler.dir/build.make
chad_compiler: CMakeFiles/chad_compiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/workspace/ChadC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chad_compiler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chad_compiler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chad_compiler.dir/build: chad_compiler
.PHONY : CMakeFiles/chad_compiler.dir/build

CMakeFiles/chad_compiler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chad_compiler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chad_compiler.dir/clean

CMakeFiles/chad_compiler.dir/depend:
	cd /workspace/ChadC && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspace/ChadC /workspace/ChadC /workspace/ChadC /workspace/ChadC /workspace/ChadC/CMakeFiles/chad_compiler.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/chad_compiler.dir/depend
