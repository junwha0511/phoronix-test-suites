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
CMAKE_SOURCE_DIR = /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613

# Include any dependencies generated for this target.
include Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/depend.make

# Include the progress variables for this target.
include Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/progress.make

# Include the compile flags for this target's objects.
include Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/flags.make

Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/LinearConvexCastDemo.o: Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/flags.make
Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/LinearConvexCastDemo.o: Demos/GjkConvexCastDemo/LinearConvexCastDemo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/LinearConvexCastDemo.o"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppLinearConvexCastDemo.dir/LinearConvexCastDemo.o -c /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo/LinearConvexCastDemo.cpp

Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/LinearConvexCastDemo.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppLinearConvexCastDemo.dir/LinearConvexCastDemo.i"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo/LinearConvexCastDemo.cpp > CMakeFiles/AppLinearConvexCastDemo.dir/LinearConvexCastDemo.i

Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/LinearConvexCastDemo.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppLinearConvexCastDemo.dir/LinearConvexCastDemo.s"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo/LinearConvexCastDemo.cpp -o CMakeFiles/AppLinearConvexCastDemo.dir/LinearConvexCastDemo.s

Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/main.o: Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/flags.make
Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/main.o: Demos/GjkConvexCastDemo/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/main.o"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppLinearConvexCastDemo.dir/main.o -c /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo/main.cpp

Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppLinearConvexCastDemo.dir/main.i"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo/main.cpp > CMakeFiles/AppLinearConvexCastDemo.dir/main.i

Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppLinearConvexCastDemo.dir/main.s"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo/main.cpp -o CMakeFiles/AppLinearConvexCastDemo.dir/main.s

# Object files for target AppLinearConvexCastDemo
AppLinearConvexCastDemo_OBJECTS = \
"CMakeFiles/AppLinearConvexCastDemo.dir/LinearConvexCastDemo.o" \
"CMakeFiles/AppLinearConvexCastDemo.dir/main.o"

# External object files for target AppLinearConvexCastDemo
AppLinearConvexCastDemo_EXTERNAL_OBJECTS =

Demos/GjkConvexCastDemo/AppLinearConvexCastDemo: Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/LinearConvexCastDemo.o
Demos/GjkConvexCastDemo/AppLinearConvexCastDemo: Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/main.o
Demos/GjkConvexCastDemo/AppLinearConvexCastDemo: Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/build.make
Demos/GjkConvexCastDemo/AppLinearConvexCastDemo: Demos/OpenGL/libOpenGLSupport.a
Demos/GjkConvexCastDemo/AppLinearConvexCastDemo: src/BulletDynamics/libBulletDynamics.a
Demos/GjkConvexCastDemo/AppLinearConvexCastDemo: src/BulletCollision/libBulletCollision.a
Demos/GjkConvexCastDemo/AppLinearConvexCastDemo: src/LinearMath/libLinearMath.a
Demos/GjkConvexCastDemo/AppLinearConvexCastDemo: /usr/lib/x86_64-linux-gnu/libglut.so
Demos/GjkConvexCastDemo/AppLinearConvexCastDemo: /usr/lib/x86_64-linux-gnu/libGL.so
Demos/GjkConvexCastDemo/AppLinearConvexCastDemo: /usr/lib/x86_64-linux-gnu/libGLU.so
Demos/GjkConvexCastDemo/AppLinearConvexCastDemo: Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable AppLinearConvexCastDemo"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AppLinearConvexCastDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/build: Demos/GjkConvexCastDemo/AppLinearConvexCastDemo

.PHONY : Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/build

Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/clean:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo && $(CMAKE_COMMAND) -P CMakeFiles/AppLinearConvexCastDemo.dir/cmake_clean.cmake
.PHONY : Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/clean

Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/depend:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Demos/GjkConvexCastDemo/CMakeFiles/AppLinearConvexCastDemo.dir/depend

