# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /work/gaohui/lookcar/EasyPR-master-arm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/gaohui/lookcar/EasyPR-master-arm

# Include any dependencies generated for this target.
include CMakeFiles/demo_arm_linux.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo_arm_linux.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo_arm_linux.dir/flags.make

CMakeFiles/demo_arm_linux.dir/test/main.cpp.o: CMakeFiles/demo_arm_linux.dir/flags.make
CMakeFiles/demo_arm_linux.dir/test/main.cpp.o: test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/gaohui/lookcar/EasyPR-master-arm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo_arm_linux.dir/test/main.cpp.o"
	/opt/hisi-linux/x86-arm/arm-histbv310-linux/bin/arm-histbv310-linux-g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo_arm_linux.dir/test/main.cpp.o -c /work/gaohui/lookcar/EasyPR-master-arm/test/main.cpp

CMakeFiles/demo_arm_linux.dir/test/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_arm_linux.dir/test/main.cpp.i"
	/opt/hisi-linux/x86-arm/arm-histbv310-linux/bin/arm-histbv310-linux-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/gaohui/lookcar/EasyPR-master-arm/test/main.cpp > CMakeFiles/demo_arm_linux.dir/test/main.cpp.i

CMakeFiles/demo_arm_linux.dir/test/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_arm_linux.dir/test/main.cpp.s"
	/opt/hisi-linux/x86-arm/arm-histbv310-linux/bin/arm-histbv310-linux-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/gaohui/lookcar/EasyPR-master-arm/test/main.cpp -o CMakeFiles/demo_arm_linux.dir/test/main.cpp.s

CMakeFiles/demo_arm_linux.dir/test/main.cpp.o.requires:

.PHONY : CMakeFiles/demo_arm_linux.dir/test/main.cpp.o.requires

CMakeFiles/demo_arm_linux.dir/test/main.cpp.o.provides: CMakeFiles/demo_arm_linux.dir/test/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/demo_arm_linux.dir/build.make CMakeFiles/demo_arm_linux.dir/test/main.cpp.o.provides.build
.PHONY : CMakeFiles/demo_arm_linux.dir/test/main.cpp.o.provides

CMakeFiles/demo_arm_linux.dir/test/main.cpp.o.provides.build: CMakeFiles/demo_arm_linux.dir/test/main.cpp.o


# Object files for target demo_arm_linux
demo_arm_linux_OBJECTS = \
"CMakeFiles/demo_arm_linux.dir/test/main.cpp.o"

# External object files for target demo_arm_linux
demo_arm_linux_EXTERNAL_OBJECTS =

/work/gaohui/lookcar/demo_arm_linux: CMakeFiles/demo_arm_linux.dir/test/main.cpp.o
/work/gaohui/lookcar/demo_arm_linux: CMakeFiles/demo_arm_linux.dir/build.make
/work/gaohui/lookcar/demo_arm_linux: libeasypr.a
/work/gaohui/lookcar/demo_arm_linux: thirdparty/libthirdparty_arm.a
/work/gaohui/lookcar/demo_arm_linux: CMakeFiles/demo_arm_linux.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/work/gaohui/lookcar/EasyPR-master-arm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /work/gaohui/lookcar/demo_arm_linux"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo_arm_linux.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo_arm_linux.dir/build: /work/gaohui/lookcar/demo_arm_linux

.PHONY : CMakeFiles/demo_arm_linux.dir/build

CMakeFiles/demo_arm_linux.dir/requires: CMakeFiles/demo_arm_linux.dir/test/main.cpp.o.requires

.PHONY : CMakeFiles/demo_arm_linux.dir/requires

CMakeFiles/demo_arm_linux.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo_arm_linux.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo_arm_linux.dir/clean

CMakeFiles/demo_arm_linux.dir/depend:
	cd /work/gaohui/lookcar/EasyPR-master-arm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/gaohui/lookcar/EasyPR-master-arm /work/gaohui/lookcar/EasyPR-master-arm /work/gaohui/lookcar/EasyPR-master-arm /work/gaohui/lookcar/EasyPR-master-arm /work/gaohui/lookcar/EasyPR-master-arm/CMakeFiles/demo_arm_linux.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo_arm_linux.dir/depend
