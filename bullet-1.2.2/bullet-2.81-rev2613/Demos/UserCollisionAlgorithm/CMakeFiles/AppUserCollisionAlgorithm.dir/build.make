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
include Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/depend.make

# Include the progress variables for this target.
include Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/progress.make

# Include the compile flags for this target's objects.
include Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/flags.make

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.o: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/flags.make
Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.o: Demos/UserCollisionAlgorithm/UserCollisionAlgorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.o"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/UserCollisionAlgorithm && /tmp/pts-compiler-mask-bullet1.2.2/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.o -c /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/UserCollisionAlgorithm/UserCollisionAlgorithm.cpp

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.i"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/UserCollisionAlgorithm && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/UserCollisionAlgorithm/UserCollisionAlgorithm.cpp > CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.i

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.s"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/UserCollisionAlgorithm && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/UserCollisionAlgorithm/UserCollisionAlgorithm.cpp -o CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.s

# Object files for target AppUserCollisionAlgorithm
AppUserCollisionAlgorithm_OBJECTS = \
"CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.o"

# External object files for target AppUserCollisionAlgorithm
AppUserCollisionAlgorithm_EXTERNAL_OBJECTS =

Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.o
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/build.make
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm: Demos/OpenGL/libOpenGLSupport.a
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm: src/BulletDynamics/libBulletDynamics.a
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm: src/BulletCollision/libBulletCollision.a
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm: src/LinearMath/libLinearMath.a
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm: /usr/lib/x86_64-linux-gnu/libglut.so
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm: /usr/lib/x86_64-linux-gnu/libGL.so
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm: /usr/lib/x86_64-linux-gnu/libGLU.so
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AppUserCollisionAlgorithm"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/UserCollisionAlgorithm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AppUserCollisionAlgorithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/build: Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm

.PHONY : Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/build

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/clean:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/UserCollisionAlgorithm && $(CMAKE_COMMAND) -P CMakeFiles/AppUserCollisionAlgorithm.dir/cmake_clean.cmake
.PHONY : Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/clean

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/depend:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/UserCollisionAlgorithm /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/UserCollisionAlgorithm /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/depend

