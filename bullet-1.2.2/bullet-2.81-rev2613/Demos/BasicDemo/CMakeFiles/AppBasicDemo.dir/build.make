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
include Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/depend.make

# Include the progress variables for this target.
include Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/progress.make

# Include the compile flags for this target's objects.
include Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/flags.make

Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/main.o: Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/flags.make
Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/main.o: Demos/BasicDemo/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/main.o"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppBasicDemo.dir/main.o -c /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo/main.cpp

Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppBasicDemo.dir/main.i"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo/main.cpp > CMakeFiles/AppBasicDemo.dir/main.i

Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppBasicDemo.dir/main.s"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo/main.cpp -o CMakeFiles/AppBasicDemo.dir/main.s

Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/BasicDemo.o: Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/flags.make
Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/BasicDemo.o: Demos/BasicDemo/BasicDemo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/BasicDemo.o"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppBasicDemo.dir/BasicDemo.o -c /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo/BasicDemo.cpp

Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/BasicDemo.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppBasicDemo.dir/BasicDemo.i"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo/BasicDemo.cpp > CMakeFiles/AppBasicDemo.dir/BasicDemo.i

Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/BasicDemo.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppBasicDemo.dir/BasicDemo.s"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo/BasicDemo.cpp -o CMakeFiles/AppBasicDemo.dir/BasicDemo.s

# Object files for target AppBasicDemo
AppBasicDemo_OBJECTS = \
"CMakeFiles/AppBasicDemo.dir/main.o" \
"CMakeFiles/AppBasicDemo.dir/BasicDemo.o"

# External object files for target AppBasicDemo
AppBasicDemo_EXTERNAL_OBJECTS =

Demos/BasicDemo/AppBasicDemo: Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/main.o
Demos/BasicDemo/AppBasicDemo: Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/BasicDemo.o
Demos/BasicDemo/AppBasicDemo: Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/build.make
Demos/BasicDemo/AppBasicDemo: Demos/OpenGL/libOpenGLSupport.a
Demos/BasicDemo/AppBasicDemo: src/BulletDynamics/libBulletDynamics.a
Demos/BasicDemo/AppBasicDemo: src/BulletCollision/libBulletCollision.a
Demos/BasicDemo/AppBasicDemo: src/LinearMath/libLinearMath.a
Demos/BasicDemo/AppBasicDemo: /usr/lib/x86_64-linux-gnu/libglut.so
Demos/BasicDemo/AppBasicDemo: /usr/lib/x86_64-linux-gnu/libGL.so
Demos/BasicDemo/AppBasicDemo: /usr/lib/x86_64-linux-gnu/libGLU.so
Demos/BasicDemo/AppBasicDemo: Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable AppBasicDemo"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AppBasicDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/build: Demos/BasicDemo/AppBasicDemo

.PHONY : Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/build

Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/clean:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo && $(CMAKE_COMMAND) -P CMakeFiles/AppBasicDemo.dir/cmake_clean.cmake
.PHONY : Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/clean

Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/depend:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Demos/BasicDemo/CMakeFiles/AppBasicDemo.dir/depend

