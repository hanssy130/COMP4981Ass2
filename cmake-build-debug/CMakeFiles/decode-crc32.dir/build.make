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
include CMakeFiles/decode-crc32.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/decode-crc32.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/decode-crc32.dir/flags.make

CMakeFiles/decode-crc32.dir/decode-crc32.c.o: CMakeFiles/decode-crc32.dir/flags.make
CMakeFiles/decode-crc32.dir/decode-crc32.c.o: ../decode-crc32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/decode-crc32.dir/decode-crc32.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/decode-crc32.dir/decode-crc32.c.o   -c /home/billy/Desktop/COMP4981/COMP4981Ass2/decode-crc32.c

CMakeFiles/decode-crc32.dir/decode-crc32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/decode-crc32.dir/decode-crc32.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/billy/Desktop/COMP4981/COMP4981Ass2/decode-crc32.c > CMakeFiles/decode-crc32.dir/decode-crc32.c.i

CMakeFiles/decode-crc32.dir/decode-crc32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/decode-crc32.dir/decode-crc32.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/billy/Desktop/COMP4981/COMP4981Ass2/decode-crc32.c -o CMakeFiles/decode-crc32.dir/decode-crc32.c.s

# Object files for target decode-crc32
decode__crc32_OBJECTS = \
"CMakeFiles/decode-crc32.dir/decode-crc32.c.o"

# External object files for target decode-crc32
decode__crc32_EXTERNAL_OBJECTS =

decode-crc32: CMakeFiles/decode-crc32.dir/decode-crc32.c.o
decode-crc32: CMakeFiles/decode-crc32.dir/build.make
decode-crc32: libbit.a
decode-crc32: CMakeFiles/decode-crc32.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable decode-crc32"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/decode-crc32.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/decode-crc32.dir/build: decode-crc32

.PHONY : CMakeFiles/decode-crc32.dir/build

CMakeFiles/decode-crc32.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/decode-crc32.dir/cmake_clean.cmake
.PHONY : CMakeFiles/decode-crc32.dir/clean

CMakeFiles/decode-crc32.dir/depend:
	cd /home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/billy/Desktop/COMP4981/COMP4981Ass2 /home/billy/Desktop/COMP4981/COMP4981Ass2 /home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug /home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug /home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug/CMakeFiles/decode-crc32.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/decode-crc32.dir/depend

