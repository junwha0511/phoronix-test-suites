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
CMAKE_SOURCE_DIR = /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release

# Include any dependencies generated for this target.
include third_party/fastfeat/CMakeFiles/FASTFEAT.dir/depend.make

# Include the progress variables for this target.
include third_party/fastfeat/CMakeFiles/FASTFEAT.dir/progress.make

# Include the compile flags for this target's objects.
include third_party/fastfeat/CMakeFiles/FASTFEAT.dir/flags.make

third_party/fastfeat/CMakeFiles/FASTFEAT.dir/fast.c.o: third_party/fastfeat/CMakeFiles/FASTFEAT.dir/flags.make
third_party/fastfeat/CMakeFiles/FASTFEAT.dir/fast.c.o: ../../../third_party/fastfeat/fast.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object third_party/fastfeat/CMakeFiles/FASTFEAT.dir/fast.c.o"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/third_party/fastfeat && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FASTFEAT.dir/fast.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/third_party/fastfeat/fast.c

third_party/fastfeat/CMakeFiles/FASTFEAT.dir/fast.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FASTFEAT.dir/fast.c.i"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/third_party/fastfeat && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/third_party/fastfeat/fast.c > CMakeFiles/FASTFEAT.dir/fast.c.i

third_party/fastfeat/CMakeFiles/FASTFEAT.dir/fast.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FASTFEAT.dir/fast.c.s"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/third_party/fastfeat && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/third_party/fastfeat/fast.c -o CMakeFiles/FASTFEAT.dir/fast.c.s

third_party/fastfeat/CMakeFiles/FASTFEAT.dir/fast_9.c.o: third_party/fastfeat/CMakeFiles/FASTFEAT.dir/flags.make
third_party/fastfeat/CMakeFiles/FASTFEAT.dir/fast_9.c.o: ../../../third_party/fastfeat/fast_9.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object third_party/fastfeat/CMakeFiles/FASTFEAT.dir/fast_9.c.o"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/third_party/fastfeat && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FASTFEAT.dir/fast_9.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/third_party/fastfeat/fast_9.c

third_party/fastfeat/CMakeFiles/FASTFEAT.dir/fast_9.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FASTFEAT.dir/fast_9.c.i"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/third_party/fastfeat && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/third_party/fastfeat/fast_9.c > CMakeFiles/FASTFEAT.dir/fast_9.c.i

third_party/fastfeat/CMakeFiles/FASTFEAT.dir/fast_9.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FASTFEAT.dir/fast_9.c.s"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/third_party/fastfeat && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/third_party/fastfeat/fast_9.c -o CMakeFiles/FASTFEAT.dir/fast_9.c.s

third_party/fastfeat/CMakeFiles/FASTFEAT.dir/nonmax.c.o: third_party/fastfeat/CMakeFiles/FASTFEAT.dir/flags.make
third_party/fastfeat/CMakeFiles/FASTFEAT.dir/nonmax.c.o: ../../../third_party/fastfeat/nonmax.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object third_party/fastfeat/CMakeFiles/FASTFEAT.dir/nonmax.c.o"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/third_party/fastfeat && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FASTFEAT.dir/nonmax.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/third_party/fastfeat/nonmax.c

third_party/fastfeat/CMakeFiles/FASTFEAT.dir/nonmax.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FASTFEAT.dir/nonmax.c.i"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/third_party/fastfeat && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/third_party/fastfeat/nonmax.c > CMakeFiles/FASTFEAT.dir/nonmax.c.i

third_party/fastfeat/CMakeFiles/FASTFEAT.dir/nonmax.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FASTFEAT.dir/nonmax.c.s"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/third_party/fastfeat && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/third_party/fastfeat/nonmax.c -o CMakeFiles/FASTFEAT.dir/nonmax.c.s

FASTFEAT: third_party/fastfeat/CMakeFiles/FASTFEAT.dir/fast.c.o
FASTFEAT: third_party/fastfeat/CMakeFiles/FASTFEAT.dir/fast_9.c.o
FASTFEAT: third_party/fastfeat/CMakeFiles/FASTFEAT.dir/nonmax.c.o
FASTFEAT: third_party/fastfeat/CMakeFiles/FASTFEAT.dir/build.make

.PHONY : FASTFEAT

# Rule to build all files generated by this target.
third_party/fastfeat/CMakeFiles/FASTFEAT.dir/build: FASTFEAT

.PHONY : third_party/fastfeat/CMakeFiles/FASTFEAT.dir/build

third_party/fastfeat/CMakeFiles/FASTFEAT.dir/clean:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/third_party/fastfeat && $(CMAKE_COMMAND) -P CMakeFiles/FASTFEAT.dir/cmake_clean.cmake
.PHONY : third_party/fastfeat/CMakeFiles/FASTFEAT.dir/clean

third_party/fastfeat/CMakeFiles/FASTFEAT.dir/depend:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0 /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/third_party/fastfeat /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/third_party/fastfeat /var/lib/phoronix-test-suite/installed-tests/pts/svt-av1-2.4.0/SVT-AV1-v0.9.0/Build/linux/Release/third_party/fastfeat/CMakeFiles/FASTFEAT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third_party/fastfeat/CMakeFiles/FASTFEAT.dir/depend

