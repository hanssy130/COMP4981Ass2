# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/billy/Downloads/clion-2020.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/billy/Downloads/clion-2020.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/billy/Desktop/COMP4981/COMP4981Ass2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/COMP4981Ass2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/COMP4981Ass2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/COMP4981Ass2.dir/flags.make

CMakeFiles/COMP4981Ass2.dir/bit_masking.c.o: CMakeFiles/COMP4981Ass2.dir/flags.make
CMakeFiles/COMP4981Ass2.dir/bit_masking.c.o: ../bit_masking.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/COMP4981Ass2.dir/bit_masking.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/COMP4981Ass2.dir/bit_masking.c.o   -c /home/billy/Desktop/COMP4981/COMP4981Ass2/bit_masking.c

CMakeFiles/COMP4981Ass2.dir/bit_masking.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/COMP4981Ass2.dir/bit_masking.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/billy/Desktop/COMP4981/COMP4981Ass2/bit_masking.c > CMakeFiles/COMP4981Ass2.dir/bit_masking.c.i

CMakeFiles/COMP4981Ass2.dir/bit_masking.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/COMP4981Ass2.dir/bit_masking.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/billy/Desktop/COMP4981/COMP4981Ass2/bit_masking.c -o CMakeFiles/COMP4981Ass2.dir/bit_masking.c.s

# Object files for target COMP4981Ass2
COMP4981Ass2_OBJECTS = \
"CMakeFiles/COMP4981Ass2.dir/bit_masking.c.o"

# External object files for target COMP4981Ass2
COMP4981Ass2_EXTERNAL_OBJECTS =

COMP4981Ass2: CMakeFiles/COMP4981Ass2.dir/bit_masking.c.o
COMP4981Ass2: CMakeFiles/COMP4981Ass2.dir/build.make
COMP4981Ass2: CMakeFiles/COMP4981Ass2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable COMP4981Ass2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/COMP4981Ass2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/COMP4981Ass2.dir/build: COMP4981Ass2

.PHONY : CMakeFiles/COMP4981Ass2.dir/build

CMakeFiles/COMP4981Ass2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/COMP4981Ass2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/COMP4981Ass2.dir/clean

CMakeFiles/COMP4981Ass2.dir/depend:
	cd /home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/billy/Desktop/COMP4981/COMP4981Ass2 /home/billy/Desktop/COMP4981/COMP4981Ass2 /home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug /home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug /home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug/CMakeFiles/COMP4981Ass2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/COMP4981Ass2.dir/depend

