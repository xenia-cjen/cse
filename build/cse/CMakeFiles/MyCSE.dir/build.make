# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xeniacjen/Documents/compiler/PA2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xeniacjen/Documents/compiler/PA2/build

# Include any dependencies generated for this target.
include cse/CMakeFiles/MyCSE.dir/depend.make

# Include the progress variables for this target.
include cse/CMakeFiles/MyCSE.dir/progress.make

# Include the compile flags for this target's objects.
include cse/CMakeFiles/MyCSE.dir/flags.make

cse/CMakeFiles/MyCSE.dir/cse.cpp.o: cse/CMakeFiles/MyCSE.dir/flags.make
cse/CMakeFiles/MyCSE.dir/cse.cpp.o: ../cse/cse.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xeniacjen/Documents/compiler/PA2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object cse/CMakeFiles/MyCSE.dir/cse.cpp.o"
	cd /home/xeniacjen/Documents/compiler/PA2/build/cse && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MyCSE.dir/cse.cpp.o -c /home/xeniacjen/Documents/compiler/PA2/cse/cse.cpp

cse/CMakeFiles/MyCSE.dir/cse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyCSE.dir/cse.cpp.i"
	cd /home/xeniacjen/Documents/compiler/PA2/build/cse && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xeniacjen/Documents/compiler/PA2/cse/cse.cpp > CMakeFiles/MyCSE.dir/cse.cpp.i

cse/CMakeFiles/MyCSE.dir/cse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyCSE.dir/cse.cpp.s"
	cd /home/xeniacjen/Documents/compiler/PA2/build/cse && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xeniacjen/Documents/compiler/PA2/cse/cse.cpp -o CMakeFiles/MyCSE.dir/cse.cpp.s

cse/CMakeFiles/MyCSE.dir/cse.cpp.o.requires:
.PHONY : cse/CMakeFiles/MyCSE.dir/cse.cpp.o.requires

cse/CMakeFiles/MyCSE.dir/cse.cpp.o.provides: cse/CMakeFiles/MyCSE.dir/cse.cpp.o.requires
	$(MAKE) -f cse/CMakeFiles/MyCSE.dir/build.make cse/CMakeFiles/MyCSE.dir/cse.cpp.o.provides.build
.PHONY : cse/CMakeFiles/MyCSE.dir/cse.cpp.o.provides

cse/CMakeFiles/MyCSE.dir/cse.cpp.o.provides.build: cse/CMakeFiles/MyCSE.dir/cse.cpp.o

# Object files for target MyCSE
MyCSE_OBJECTS = \
"CMakeFiles/MyCSE.dir/cse.cpp.o"

# External object files for target MyCSE
MyCSE_EXTERNAL_OBJECTS =

cse/libMyCSE.so: cse/CMakeFiles/MyCSE.dir/cse.cpp.o
cse/libMyCSE.so: cse/CMakeFiles/MyCSE.dir/build.make
cse/libMyCSE.so: cse/CMakeFiles/MyCSE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module libMyCSE.so"
	cd /home/xeniacjen/Documents/compiler/PA2/build/cse && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyCSE.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cse/CMakeFiles/MyCSE.dir/build: cse/libMyCSE.so
.PHONY : cse/CMakeFiles/MyCSE.dir/build

cse/CMakeFiles/MyCSE.dir/requires: cse/CMakeFiles/MyCSE.dir/cse.cpp.o.requires
.PHONY : cse/CMakeFiles/MyCSE.dir/requires

cse/CMakeFiles/MyCSE.dir/clean:
	cd /home/xeniacjen/Documents/compiler/PA2/build/cse && $(CMAKE_COMMAND) -P CMakeFiles/MyCSE.dir/cmake_clean.cmake
.PHONY : cse/CMakeFiles/MyCSE.dir/clean

cse/CMakeFiles/MyCSE.dir/depend:
	cd /home/xeniacjen/Documents/compiler/PA2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xeniacjen/Documents/compiler/PA2 /home/xeniacjen/Documents/compiler/PA2/cse /home/xeniacjen/Documents/compiler/PA2/build /home/xeniacjen/Documents/compiler/PA2/build/cse /home/xeniacjen/Documents/compiler/PA2/build/cse/CMakeFiles/MyCSE.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cse/CMakeFiles/MyCSE.dir/depend

