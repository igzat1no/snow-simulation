# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/igzatino/simulation/project/snow/SnowSim/glfw-3.4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/igzatino/simulation/project/snow/SnowSim/glfw3

# Include any dependencies generated for this target.
include tests/CMakeFiles/clipboard.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/clipboard.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/clipboard.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/clipboard.dir/flags.make

tests/CMakeFiles/clipboard.dir/clipboard.c.o: tests/CMakeFiles/clipboard.dir/flags.make
tests/CMakeFiles/clipboard.dir/clipboard.c.o: /home/igzatino/simulation/project/snow/SnowSim/glfw-3.4/tests/clipboard.c
tests/CMakeFiles/clipboard.dir/clipboard.c.o: tests/CMakeFiles/clipboard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/igzatino/simulation/project/snow/SnowSim/glfw3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/clipboard.dir/clipboard.c.o"
	cd /home/igzatino/simulation/project/snow/SnowSim/glfw3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/clipboard.dir/clipboard.c.o -MF CMakeFiles/clipboard.dir/clipboard.c.o.d -o CMakeFiles/clipboard.dir/clipboard.c.o -c /home/igzatino/simulation/project/snow/SnowSim/glfw-3.4/tests/clipboard.c

tests/CMakeFiles/clipboard.dir/clipboard.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/clipboard.dir/clipboard.c.i"
	cd /home/igzatino/simulation/project/snow/SnowSim/glfw3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/igzatino/simulation/project/snow/SnowSim/glfw-3.4/tests/clipboard.c > CMakeFiles/clipboard.dir/clipboard.c.i

tests/CMakeFiles/clipboard.dir/clipboard.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/clipboard.dir/clipboard.c.s"
	cd /home/igzatino/simulation/project/snow/SnowSim/glfw3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/igzatino/simulation/project/snow/SnowSim/glfw-3.4/tests/clipboard.c -o CMakeFiles/clipboard.dir/clipboard.c.s

tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o: tests/CMakeFiles/clipboard.dir/flags.make
tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o: /home/igzatino/simulation/project/snow/SnowSim/glfw-3.4/deps/getopt.c
tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o: tests/CMakeFiles/clipboard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/igzatino/simulation/project/snow/SnowSim/glfw3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o"
	cd /home/igzatino/simulation/project/snow/SnowSim/glfw3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o -MF CMakeFiles/clipboard.dir/__/deps/getopt.c.o.d -o CMakeFiles/clipboard.dir/__/deps/getopt.c.o -c /home/igzatino/simulation/project/snow/SnowSim/glfw-3.4/deps/getopt.c

tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/clipboard.dir/__/deps/getopt.c.i"
	cd /home/igzatino/simulation/project/snow/SnowSim/glfw3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/igzatino/simulation/project/snow/SnowSim/glfw-3.4/deps/getopt.c > CMakeFiles/clipboard.dir/__/deps/getopt.c.i

tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/clipboard.dir/__/deps/getopt.c.s"
	cd /home/igzatino/simulation/project/snow/SnowSim/glfw3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/igzatino/simulation/project/snow/SnowSim/glfw-3.4/deps/getopt.c -o CMakeFiles/clipboard.dir/__/deps/getopt.c.s

# Object files for target clipboard
clipboard_OBJECTS = \
"CMakeFiles/clipboard.dir/clipboard.c.o" \
"CMakeFiles/clipboard.dir/__/deps/getopt.c.o"

# External object files for target clipboard
clipboard_EXTERNAL_OBJECTS =

tests/clipboard: tests/CMakeFiles/clipboard.dir/clipboard.c.o
tests/clipboard: tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o
tests/clipboard: tests/CMakeFiles/clipboard.dir/build.make
tests/clipboard: src/libglfw3.a
tests/clipboard: /usr/lib/x86_64-linux-gnu/libm.so
tests/clipboard: /usr/lib/x86_64-linux-gnu/librt.a
tests/clipboard: /usr/lib/x86_64-linux-gnu/libm.so
tests/clipboard: tests/CMakeFiles/clipboard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/igzatino/simulation/project/snow/SnowSim/glfw3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable clipboard"
	cd /home/igzatino/simulation/project/snow/SnowSim/glfw3/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clipboard.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/clipboard.dir/build: tests/clipboard
.PHONY : tests/CMakeFiles/clipboard.dir/build

tests/CMakeFiles/clipboard.dir/clean:
	cd /home/igzatino/simulation/project/snow/SnowSim/glfw3/tests && $(CMAKE_COMMAND) -P CMakeFiles/clipboard.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/clipboard.dir/clean

tests/CMakeFiles/clipboard.dir/depend:
	cd /home/igzatino/simulation/project/snow/SnowSim/glfw3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/igzatino/simulation/project/snow/SnowSim/glfw-3.4 /home/igzatino/simulation/project/snow/SnowSim/glfw-3.4/tests /home/igzatino/simulation/project/snow/SnowSim/glfw3 /home/igzatino/simulation/project/snow/SnowSim/glfw3/tests /home/igzatino/simulation/project/snow/SnowSim/glfw3/tests/CMakeFiles/clipboard.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/clipboard.dir/depend

