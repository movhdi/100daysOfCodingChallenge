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
CMAKE_SOURCE_DIR = /home/med/100daysOfCodingChallenge/p90_base64

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/med/100daysOfCodingChallenge/p90_base64/build

# Include any dependencies generated for this target.
include CMakeFiles/boostLog.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/boostLog.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/boostLog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boostLog.dir/flags.make

CMakeFiles/boostLog.dir/main.cpp.o: CMakeFiles/boostLog.dir/flags.make
CMakeFiles/boostLog.dir/main.cpp.o: /home/med/100daysOfCodingChallenge/p90_base64/main.cpp
CMakeFiles/boostLog.dir/main.cpp.o: CMakeFiles/boostLog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/med/100daysOfCodingChallenge/p90_base64/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/boostLog.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/boostLog.dir/main.cpp.o -MF CMakeFiles/boostLog.dir/main.cpp.o.d -o CMakeFiles/boostLog.dir/main.cpp.o -c /home/med/100daysOfCodingChallenge/p90_base64/main.cpp

CMakeFiles/boostLog.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boostLog.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/med/100daysOfCodingChallenge/p90_base64/main.cpp > CMakeFiles/boostLog.dir/main.cpp.i

CMakeFiles/boostLog.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boostLog.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/med/100daysOfCodingChallenge/p90_base64/main.cpp -o CMakeFiles/boostLog.dir/main.cpp.s

# Object files for target boostLog
boostLog_OBJECTS = \
"CMakeFiles/boostLog.dir/main.cpp.o"

# External object files for target boostLog
boostLog_EXTERNAL_OBJECTS =

boostLog: CMakeFiles/boostLog.dir/main.cpp.o
boostLog: CMakeFiles/boostLog.dir/build.make
boostLog: /usr/lib/x86_64-linux-gnu/libboost_log.so.1.71.0
boostLog: /usr/lib/x86_64-linux-gnu/libboost_log_setup.so.1.71.0
boostLog: /usr/lib/x86_64-linux-gnu/libboost_log.so.1.71.0
boostLog: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
boostLog: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
boostLog: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
boostLog: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
boostLog: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
boostLog: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.71.0
boostLog: CMakeFiles/boostLog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/med/100daysOfCodingChallenge/p90_base64/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable boostLog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boostLog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/boostLog.dir/build: boostLog
.PHONY : CMakeFiles/boostLog.dir/build

CMakeFiles/boostLog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/boostLog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/boostLog.dir/clean

CMakeFiles/boostLog.dir/depend:
	cd /home/med/100daysOfCodingChallenge/p90_base64/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/med/100daysOfCodingChallenge/p90_base64 /home/med/100daysOfCodingChallenge/p90_base64 /home/med/100daysOfCodingChallenge/p90_base64/build /home/med/100daysOfCodingChallenge/p90_base64/build /home/med/100daysOfCodingChallenge/p90_base64/build/CMakeFiles/boostLog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/boostLog.dir/depend

