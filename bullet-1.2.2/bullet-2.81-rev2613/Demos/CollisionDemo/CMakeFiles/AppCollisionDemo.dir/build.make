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
include Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/depend.make

# Include the progress variables for this target.
include Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/progress.make

# Include the compile flags for this target's objects.
include Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/flags.make

Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/CollisionDemo.o: Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/flags.make
Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/CollisionDemo.o: Demos/CollisionDemo/CollisionDemo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/CollisionDemo.o"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/CollisionDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppCollisionDemo.dir/CollisionDemo.o -c /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/CollisionDemo/CollisionDemo.cpp

Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/CollisionDemo.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppCollisionDemo.dir/CollisionDemo.i"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/CollisionDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/CollisionDemo/CollisionDemo.cpp > CMakeFiles/AppCollisionDemo.dir/CollisionDemo.i

Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/CollisionDemo.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppCollisionDemo.dir/CollisionDemo.s"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/CollisionDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/CollisionDemo/CollisionDemo.cpp -o CMakeFiles/AppCollisionDemo.dir/CollisionDemo.s

# Object files for target AppCollisionDemo
AppCollisionDemo_OBJECTS = \
"CMakeFiles/AppCollisionDemo.dir/CollisionDemo.o"

# External object files for target AppCollisionDemo
AppCollisionDemo_EXTERNAL_OBJECTS =

Demos/CollisionDemo/AppCollisionDemo: Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/CollisionDemo.o
Demos/CollisionDemo/AppCollisionDemo: Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/build.make
Demos/CollisionDemo/AppCollisionDemo: Demos/OpenGL/libOpenGLSupport.a
Demos/CollisionDemo/AppCollisionDemo: src/BulletDynamics/libBulletDynamics.a
Demos/CollisionDemo/AppCollisionDemo: src/BulletCollision/libBulletCollision.a
Demos/CollisionDemo/AppCollisionDemo: src/LinearMath/libLinearMath.a
Demos/CollisionDemo/AppCollisionDemo: /usr/lib/x86_64-linux-gnu/libglut.so
Demos/CollisionDemo/AppCollisionDemo: /usr/lib/x86_64-linux-gnu/libGL.so
Demos/CollisionDemo/AppCollisionDemo: /usr/lib/x86_64-linux-gnu/libGLU.so
Demos/CollisionDemo/AppCollisionDemo: Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AppCollisionDemo"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/CollisionDemo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AppCollisionDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/build: Demos/CollisionDemo/AppCollisionDemo

.PHONY : Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/build

Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/clean:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/CollisionDemo && $(CMAKE_COMMAND) -P CMakeFiles/AppCollisionDemo.dir/cmake_clean.cmake
.PHONY : Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/clean

Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/depend:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/CollisionDemo /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/CollisionDemo /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Demos/CollisionDemo/CMakeFiles/AppCollisionDemo.dir/depend

