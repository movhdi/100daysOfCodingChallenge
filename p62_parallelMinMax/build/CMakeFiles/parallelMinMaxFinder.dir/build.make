# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/med/100daysOfCodingChallenge/p62_parallelMinMax

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/med/100daysOfCodingChallenge/p62_parallelMinMax/build

# Include any dependencies generated for this target.
include CMakeFiles/parallelMinMaxFinder.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/parallelMinMaxFinder.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/parallelMinMaxFinder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parallelMinMaxFinder.dir/flags.make

CMakeFiles/parallelMinMaxFinder.dir/main.cpp.o: CMakeFiles/parallelMinMaxFinder.dir/flags.make
CMakeFiles/parallelMinMaxFinder.dir/main.cpp.o: /home/med/100daysOfCodingChallenge/p62_parallelMinMax/main.cpp
CMakeFiles/parallelMinMaxFinder.dir/main.cpp.o: CMakeFiles/parallelMinMaxFinder.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/med/100daysOfCodingChallenge/p62_parallelMinMax/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/parallelMinMaxFinder.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parallelMinMaxFinder.dir/main.cpp.o -MF CMakeFiles/parallelMinMaxFinder.dir/main.cpp.o.d -o CMakeFiles/parallelMinMaxFinder.dir/main.cpp.o -c /home/med/100daysOfCodingChallenge/p62_parallelMinMax/main.cpp

CMakeFiles/parallelMinMaxFinder.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parallelMinMaxFinder.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/med/100daysOfCodingChallenge/p62_parallelMinMax/main.cpp > CMakeFiles/parallelMinMaxFinder.dir/main.cpp.i

CMakeFiles/parallelMinMaxFinder.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parallelMinMaxFinder.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/med/100daysOfCodingChallenge/p62_parallelMinMax/main.cpp -o CMakeFiles/parallelMinMaxFinder.dir/main.cpp.s

CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.o: CMakeFiles/parallelMinMaxFinder.dir/flags.make
CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.o: /home/med/100daysOfCodingChallenge/p62_parallelMinMax/src/parallelAlg.cpp
CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.o: CMakeFiles/parallelMinMaxFinder.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/med/100daysOfCodingChallenge/p62_parallelMinMax/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.o -MF CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.o.d -o CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.o -c /home/med/100daysOfCodingChallenge/p62_parallelMinMax/src/parallelAlg.cpp

CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/med/100daysOfCodingChallenge/p62_parallelMinMax/src/parallelAlg.cpp > CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.i

CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/med/100daysOfCodingChallenge/p62_parallelMinMax/src/parallelAlg.cpp -o CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.s

# Object files for target parallelMinMaxFinder
parallelMinMaxFinder_OBJECTS = \
"CMakeFiles/parallelMinMaxFinder.dir/main.cpp.o" \
"CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.o"

# External object files for target parallelMinMaxFinder
parallelMinMaxFinder_EXTERNAL_OBJECTS =

parallelMinMaxFinder: CMakeFiles/parallelMinMaxFinder.dir/main.cpp.o
parallelMinMaxFinder: CMakeFiles/parallelMinMaxFinder.dir/src/parallelAlg.cpp.o
parallelMinMaxFinder: CMakeFiles/parallelMinMaxFinder.dir/build.make
parallelMinMaxFinder: src/libparallelAlg.a
parallelMinMaxFinder: CMakeFiles/parallelMinMaxFinder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/med/100daysOfCodingChallenge/p62_parallelMinMax/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable parallelMinMaxFinder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parallelMinMaxFinder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parallelMinMaxFinder.dir/build: parallelMinMaxFinder
.PHONY : CMakeFiles/parallelMinMaxFinder.dir/build

CMakeFiles/parallelMinMaxFinder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parallelMinMaxFinder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parallelMinMaxFinder.dir/clean

CMakeFiles/parallelMinMaxFinder.dir/depend:
	cd /home/med/100daysOfCodingChallenge/p62_parallelMinMax/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/med/100daysOfCodingChallenge/p62_parallelMinMax /home/med/100daysOfCodingChallenge/p62_parallelMinMax /home/med/100daysOfCodingChallenge/p62_parallelMinMax/build /home/med/100daysOfCodingChallenge/p62_parallelMinMax/build /home/med/100daysOfCodingChallenge/p62_parallelMinMax/build/CMakeFiles/parallelMinMaxFinder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parallelMinMaxFinder.dir/depend

