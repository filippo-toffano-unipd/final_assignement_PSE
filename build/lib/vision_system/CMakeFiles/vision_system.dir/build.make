# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/filippo-toffano/embedded_system_programming/final_assignement

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/filippo-toffano/embedded_system_programming/final_assignement/build

# Include any dependencies generated for this target.
include lib/vision_system/CMakeFiles/vision_system.dir/depend.make

# Include the progress variables for this target.
include lib/vision_system/CMakeFiles/vision_system.dir/progress.make

# Include the compile flags for this target's objects.
include lib/vision_system/CMakeFiles/vision_system.dir/flags.make

lib/vision_system/CMakeFiles/vision_system.dir/src/vision_system.cpp.o: lib/vision_system/CMakeFiles/vision_system.dir/flags.make
lib/vision_system/CMakeFiles/vision_system.dir/src/vision_system.cpp.o: ../lib/vision_system/src/vision_system.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/filippo-toffano/embedded_system_programming/final_assignement/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/vision_system/CMakeFiles/vision_system.dir/src/vision_system.cpp.o"
	cd /home/filippo-toffano/embedded_system_programming/final_assignement/build/lib/vision_system && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vision_system.dir/src/vision_system.cpp.o -c /home/filippo-toffano/embedded_system_programming/final_assignement/lib/vision_system/src/vision_system.cpp

lib/vision_system/CMakeFiles/vision_system.dir/src/vision_system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vision_system.dir/src/vision_system.cpp.i"
	cd /home/filippo-toffano/embedded_system_programming/final_assignement/build/lib/vision_system && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filippo-toffano/embedded_system_programming/final_assignement/lib/vision_system/src/vision_system.cpp > CMakeFiles/vision_system.dir/src/vision_system.cpp.i

lib/vision_system/CMakeFiles/vision_system.dir/src/vision_system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vision_system.dir/src/vision_system.cpp.s"
	cd /home/filippo-toffano/embedded_system_programming/final_assignement/build/lib/vision_system && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filippo-toffano/embedded_system_programming/final_assignement/lib/vision_system/src/vision_system.cpp -o CMakeFiles/vision_system.dir/src/vision_system.cpp.s

# Object files for target vision_system
vision_system_OBJECTS = \
"CMakeFiles/vision_system.dir/src/vision_system.cpp.o"

# External object files for target vision_system
vision_system_EXTERNAL_OBJECTS =

lib/vision_system/libvision_system.a: lib/vision_system/CMakeFiles/vision_system.dir/src/vision_system.cpp.o
lib/vision_system/libvision_system.a: lib/vision_system/CMakeFiles/vision_system.dir/build.make
lib/vision_system/libvision_system.a: lib/vision_system/CMakeFiles/vision_system.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/filippo-toffano/embedded_system_programming/final_assignement/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libvision_system.a"
	cd /home/filippo-toffano/embedded_system_programming/final_assignement/build/lib/vision_system && $(CMAKE_COMMAND) -P CMakeFiles/vision_system.dir/cmake_clean_target.cmake
	cd /home/filippo-toffano/embedded_system_programming/final_assignement/build/lib/vision_system && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vision_system.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/vision_system/CMakeFiles/vision_system.dir/build: lib/vision_system/libvision_system.a

.PHONY : lib/vision_system/CMakeFiles/vision_system.dir/build

lib/vision_system/CMakeFiles/vision_system.dir/clean:
	cd /home/filippo-toffano/embedded_system_programming/final_assignement/build/lib/vision_system && $(CMAKE_COMMAND) -P CMakeFiles/vision_system.dir/cmake_clean.cmake
.PHONY : lib/vision_system/CMakeFiles/vision_system.dir/clean

lib/vision_system/CMakeFiles/vision_system.dir/depend:
	cd /home/filippo-toffano/embedded_system_programming/final_assignement/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filippo-toffano/embedded_system_programming/final_assignement /home/filippo-toffano/embedded_system_programming/final_assignement/lib/vision_system /home/filippo-toffano/embedded_system_programming/final_assignement/build /home/filippo-toffano/embedded_system_programming/final_assignement/build/lib/vision_system /home/filippo-toffano/embedded_system_programming/final_assignement/build/lib/vision_system/CMakeFiles/vision_system.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/vision_system/CMakeFiles/vision_system.dir/depend

