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
include Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/depend.make

# Include the progress variables for this target.
include Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/progress.make

# Include the compile flags for this target's objects.
include Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/flags.make

Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/MultiMaterialDemo.o: Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/flags.make
Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/MultiMaterialDemo.o: Demos/MultiMaterialDemo/MultiMaterialDemo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/MultiMaterialDemo.o"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppMultiMaterialDemo.dir/MultiMaterialDemo.o -c /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo/MultiMaterialDemo.cpp

Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/MultiMaterialDemo.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppMultiMaterialDemo.dir/MultiMaterialDemo.i"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo/MultiMaterialDemo.cpp > CMakeFiles/AppMultiMaterialDemo.dir/MultiMaterialDemo.i

Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/MultiMaterialDemo.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppMultiMaterialDemo.dir/MultiMaterialDemo.s"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo/MultiMaterialDemo.cpp -o CMakeFiles/AppMultiMaterialDemo.dir/MultiMaterialDemo.s

Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/main.o: Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/flags.make
Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/main.o: Demos/MultiMaterialDemo/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/main.o"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppMultiMaterialDemo.dir/main.o -c /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo/main.cpp

Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppMultiMaterialDemo.dir/main.i"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo/main.cpp > CMakeFiles/AppMultiMaterialDemo.dir/main.i

Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppMultiMaterialDemo.dir/main.s"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo && /tmp/pts-compiler-mask-bullet1.2.2/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo/main.cpp -o CMakeFiles/AppMultiMaterialDemo.dir/main.s

# Object files for target AppMultiMaterialDemo
AppMultiMaterialDemo_OBJECTS = \
"CMakeFiles/AppMultiMaterialDemo.dir/MultiMaterialDemo.o" \
"CMakeFiles/AppMultiMaterialDemo.dir/main.o"

# External object files for target AppMultiMaterialDemo
AppMultiMaterialDemo_EXTERNAL_OBJECTS =

Demos/MultiMaterialDemo/AppMultiMaterialDemo: Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/MultiMaterialDemo.o
Demos/MultiMaterialDemo/AppMultiMaterialDemo: Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/main.o
Demos/MultiMaterialDemo/AppMultiMaterialDemo: Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/build.make
Demos/MultiMaterialDemo/AppMultiMaterialDemo: Demos/OpenGL/libOpenGLSupport.a
Demos/MultiMaterialDemo/AppMultiMaterialDemo: src/BulletDynamics/libBulletDynamics.a
Demos/MultiMaterialDemo/AppMultiMaterialDemo: src/BulletCollision/libBulletCollision.a
Demos/MultiMaterialDemo/AppMultiMaterialDemo: src/LinearMath/libLinearMath.a
Demos/MultiMaterialDemo/AppMultiMaterialDemo: /usr/lib/x86_64-linux-gnu/libglut.so
Demos/MultiMaterialDemo/AppMultiMaterialDemo: /usr/lib/x86_64-linux-gnu/libGL.so
Demos/MultiMaterialDemo/AppMultiMaterialDemo: /usr/lib/x86_64-linux-gnu/libGLU.so
Demos/MultiMaterialDemo/AppMultiMaterialDemo: Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable AppMultiMaterialDemo"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AppMultiMaterialDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/build: Demos/MultiMaterialDemo/AppMultiMaterialDemo

.PHONY : Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/build

Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/clean:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo && $(CMAKE_COMMAND) -P CMakeFiles/AppMultiMaterialDemo.dir/cmake_clean.cmake
.PHONY : Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/clean

Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/depend:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613 /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo /var/lib/phoronix-test-suite/installed-tests/pts/bullet-1.2.2/bullet-2.81-rev2613/Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Demos/MultiMaterialDemo/CMakeFiles/AppMultiMaterialDemo.dir/depend

