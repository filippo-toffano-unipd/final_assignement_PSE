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
include app/CMakeFiles/application.dir/depend.make

# Include the progress variables for this target.
include app/CMakeFiles/application.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/application.dir/flags.make

app/CMakeFiles/application.dir/src/main.cpp.o: app/CMakeFiles/application.dir/flags.make
app/CMakeFiles/application.dir/src/main.cpp.o: ../app/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/filippo-toffano/embedded_system_programming/final_assignement/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/CMakeFiles/application.dir/src/main.cpp.o"
	cd /home/filippo-toffano/embedded_system_programming/final_assignement/build/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/application.dir/src/main.cpp.o -c /home/filippo-toffano/embedded_system_programming/final_assignement/app/src/main.cpp

app/CMakeFiles/application.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/application.dir/src/main.cpp.i"
	cd /home/filippo-toffano/embedded_system_programming/final_assignement/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filippo-toffano/embedded_system_programming/final_assignement/app/src/main.cpp > CMakeFiles/application.dir/src/main.cpp.i

app/CMakeFiles/application.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/application.dir/src/main.cpp.s"
	cd /home/filippo-toffano/embedded_system_programming/final_assignement/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filippo-toffano/embedded_system_programming/final_assignement/app/src/main.cpp -o CMakeFiles/application.dir/src/main.cpp.s

# Object files for target application
application_OBJECTS = \
"CMakeFiles/application.dir/src/main.cpp.o"

# External object files for target application
application_EXTERNAL_OBJECTS =

app/application: app/CMakeFiles/application.dir/src/main.cpp.o
app/application: app/CMakeFiles/application.dir/build.make
app/application: lib/piece/libpiece.a
app/application: lib/box/libbox.a
app/application: lib/store/libstore.a
app/application: lib/vision_system/libvision_system.a
app/application: lib/box/libbox.a
app/application: lib/piece/libpiece.a
app/application: app/CMakeFiles/application.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/filippo-toffano/embedded_system_programming/final_assignement/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable application"
	cd /home/filippo-toffano/embedded_system_programming/final_assignement/build/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/application.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/application.dir/build: app/application

.PHONY : app/CMakeFiles/application.dir/build

app/CMakeFiles/application.dir/clean:
	cd /home/filippo-toffano/embedded_system_programming/final_assignement/build/app && $(CMAKE_COMMAND) -P CMakeFiles/application.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/application.dir/clean

app/CMakeFiles/application.dir/depend:
	cd /home/filippo-toffano/embedded_system_programming/final_assignement/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filippo-toffano/embedded_system_programming/final_assignement /home/filippo-toffano/embedded_system_programming/final_assignement/app /home/filippo-toffano/embedded_system_programming/final_assignement/build /home/filippo-toffano/embedded_system_programming/final_assignement/build/app /home/filippo-toffano/embedded_system_programming/final_assignement/build/app/CMakeFiles/application.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/application.dir/depend

