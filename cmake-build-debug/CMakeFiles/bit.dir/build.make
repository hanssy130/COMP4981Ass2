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
include CMakeFiles/bit.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bit.dir/flags.make

CMakeFiles/bit.dir/bit_masking.c.o: CMakeFiles/bit.dir/flags.make
CMakeFiles/bit.dir/bit_masking.c.o: ../bit_masking.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bit.dir/bit_masking.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bit.dir/bit_masking.c.o   -c /home/billy/Desktop/COMP4981/COMP4981Ass2/bit_masking.c

CMakeFiles/bit.dir/bit_masking.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bit.dir/bit_masking.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/billy/Desktop/COMP4981/COMP4981Ass2/bit_masking.c > CMakeFiles/bit.dir/bit_masking.c.i

CMakeFiles/bit.dir/bit_masking.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bit.dir/bit_masking.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/billy/Desktop/COMP4981/COMP4981Ass2/bit_masking.c -o CMakeFiles/bit.dir/bit_masking.c.s

# Object files for target bit
bit_OBJECTS = \
"CMakeFiles/bit.dir/bit_masking.c.o"

# External object files for target bit
bit_EXTERNAL_OBJECTS =

libbit.a: CMakeFiles/bit.dir/bit_masking.c.o
libbit.a: CMakeFiles/bit.dir/build.make
libbit.a: CMakeFiles/bit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libbit.a"
	$(CMAKE_COMMAND) -P CMakeFiles/bit.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bit.dir/build: libbit.a

.PHONY : CMakeFiles/bit.dir/build

CMakeFiles/bit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bit.dir/clean

CMakeFiles/bit.dir/depend:
	cd /home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/billy/Desktop/COMP4981/COMP4981Ass2 /home/billy/Desktop/COMP4981/COMP4981Ass2 /home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug /home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug /home/billy/Desktop/COMP4981/COMP4981Ass2/cmake-build-debug/CMakeFiles/bit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bit.dir/depend

