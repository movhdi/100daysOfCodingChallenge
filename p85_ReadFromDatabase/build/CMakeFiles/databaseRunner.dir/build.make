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
CMAKE_SOURCE_DIR = /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/build

# Include any dependencies generated for this target.
include CMakeFiles/databaseRunner.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/databaseRunner.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/databaseRunner.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/databaseRunner.dir/flags.make

CMakeFiles/databaseRunner.dir/main.cpp.o: CMakeFiles/databaseRunner.dir/flags.make
CMakeFiles/databaseRunner.dir/main.cpp.o: /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/main.cpp
CMakeFiles/databaseRunner.dir/main.cpp.o: CMakeFiles/databaseRunner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/databaseRunner.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/databaseRunner.dir/main.cpp.o -MF CMakeFiles/databaseRunner.dir/main.cpp.o.d -o CMakeFiles/databaseRunner.dir/main.cpp.o -c /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/main.cpp

CMakeFiles/databaseRunner.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/databaseRunner.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/main.cpp > CMakeFiles/databaseRunner.dir/main.cpp.i

CMakeFiles/databaseRunner.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/databaseRunner.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/main.cpp -o CMakeFiles/databaseRunner.dir/main.cpp.s

CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.o: CMakeFiles/databaseRunner.dir/flags.make
CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.o: /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/lib/databasehandler.cpp
CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.o: CMakeFiles/databaseRunner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.o -MF CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.o.d -o CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.o -c /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/lib/databasehandler.cpp

CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/lib/databasehandler.cpp > CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.i

CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/lib/databasehandler.cpp -o CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.s

CMakeFiles/databaseRunner.dir/lib/logging.cpp.o: CMakeFiles/databaseRunner.dir/flags.make
CMakeFiles/databaseRunner.dir/lib/logging.cpp.o: /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/lib/logging.cpp
CMakeFiles/databaseRunner.dir/lib/logging.cpp.o: CMakeFiles/databaseRunner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/databaseRunner.dir/lib/logging.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/databaseRunner.dir/lib/logging.cpp.o -MF CMakeFiles/databaseRunner.dir/lib/logging.cpp.o.d -o CMakeFiles/databaseRunner.dir/lib/logging.cpp.o -c /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/lib/logging.cpp

CMakeFiles/databaseRunner.dir/lib/logging.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/databaseRunner.dir/lib/logging.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/lib/logging.cpp > CMakeFiles/databaseRunner.dir/lib/logging.cpp.i

CMakeFiles/databaseRunner.dir/lib/logging.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/databaseRunner.dir/lib/logging.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/lib/logging.cpp -o CMakeFiles/databaseRunner.dir/lib/logging.cpp.s

CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.o: CMakeFiles/databaseRunner.dir/flags.make
CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.o: /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/lib/SystemInit.cpp
CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.o: CMakeFiles/databaseRunner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.o -MF CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.o.d -o CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.o -c /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/lib/SystemInit.cpp

CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/lib/SystemInit.cpp > CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.i

CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/lib/SystemInit.cpp -o CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.s

# Object files for target databaseRunner
databaseRunner_OBJECTS = \
"CMakeFiles/databaseRunner.dir/main.cpp.o" \
"CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.o" \
"CMakeFiles/databaseRunner.dir/lib/logging.cpp.o" \
"CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.o"

# External object files for target databaseRunner
databaseRunner_EXTERNAL_OBJECTS =

databaseRunner: CMakeFiles/databaseRunner.dir/main.cpp.o
databaseRunner: CMakeFiles/databaseRunner.dir/lib/databasehandler.cpp.o
databaseRunner: CMakeFiles/databaseRunner.dir/lib/logging.cpp.o
databaseRunner: CMakeFiles/databaseRunner.dir/lib/SystemInit.cpp.o
databaseRunner: CMakeFiles/databaseRunner.dir/build.make
databaseRunner: lib/libperformanceEval.a
databaseRunner: /usr/lib/x86_64-linux-gnu/libboost_log_setup.so.1.71.0
databaseRunner: /usr/lib/x86_64-linux-gnu/libboost_log.so.1.71.0
databaseRunner: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
databaseRunner: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
databaseRunner: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
databaseRunner: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
databaseRunner: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
databaseRunner: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.71.0
databaseRunner: CMakeFiles/databaseRunner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable databaseRunner"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/databaseRunner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/databaseRunner.dir/build: databaseRunner
.PHONY : CMakeFiles/databaseRunner.dir/build

CMakeFiles/databaseRunner.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/databaseRunner.dir/cmake_clean.cmake
.PHONY : CMakeFiles/databaseRunner.dir/clean

CMakeFiles/databaseRunner.dir/depend:
	cd /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/build /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/build /home/med/100daysOfCodingChallenge/p85_ReadFromDatabase/build/CMakeFiles/databaseRunner.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/databaseRunner.dir/depend

