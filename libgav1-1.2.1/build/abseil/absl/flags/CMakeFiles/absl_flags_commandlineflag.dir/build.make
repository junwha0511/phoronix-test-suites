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
CMAKE_SOURCE_DIR = /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build

# Include any dependencies generated for this target.
include abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/depend.make

# Include the progress variables for this target.
include abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/progress.make

# Include the compile flags for this target's objects.
include abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/flags.make

abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/commandlineflag.cc.o: abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/flags.make
abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/commandlineflag.cc.o: ../third_party/abseil-cpp/absl/flags/commandlineflag.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/commandlineflag.cc.o"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/abseil/absl/flags && /tmp/pts-compiler-mask-libgav11.2.1/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/absl_flags_commandlineflag.dir/commandlineflag.cc.o -c /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/third_party/abseil-cpp/absl/flags/commandlineflag.cc

abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/commandlineflag.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/absl_flags_commandlineflag.dir/commandlineflag.cc.i"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/abseil/absl/flags && /tmp/pts-compiler-mask-libgav11.2.1/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/third_party/abseil-cpp/absl/flags/commandlineflag.cc > CMakeFiles/absl_flags_commandlineflag.dir/commandlineflag.cc.i

abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/commandlineflag.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/absl_flags_commandlineflag.dir/commandlineflag.cc.s"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/abseil/absl/flags && /tmp/pts-compiler-mask-libgav11.2.1/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/third_party/abseil-cpp/absl/flags/commandlineflag.cc -o CMakeFiles/absl_flags_commandlineflag.dir/commandlineflag.cc.s

# Object files for target absl_flags_commandlineflag
absl_flags_commandlineflag_OBJECTS = \
"CMakeFiles/absl_flags_commandlineflag.dir/commandlineflag.cc.o"

# External object files for target absl_flags_commandlineflag
absl_flags_commandlineflag_EXTERNAL_OBJECTS =

abseil/absl/flags/libabsl_flags_commandlineflag.a: abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/commandlineflag.cc.o
abseil/absl/flags/libabsl_flags_commandlineflag.a: abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/build.make
abseil/absl/flags/libabsl_flags_commandlineflag.a: abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libabsl_flags_commandlineflag.a"
	cd /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/abseil/absl/flags && $(CMAKE_COMMAND) -P CMakeFiles/absl_flags_commandlineflag.dir/cmake_clean_target.cmake
	cd /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/abseil/absl/flags && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/absl_flags_commandlineflag.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/build: abseil/absl/flags/libabsl_flags_commandlineflag.a

.PHONY : abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/build

abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/clean:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/abseil/absl/flags && $(CMAKE_COMMAND) -P CMakeFiles/absl_flags_commandlineflag.dir/cmake_clean.cmake
.PHONY : abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/clean

abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/depend:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1 /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/third_party/abseil-cpp/absl/flags /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/abseil/absl/flags /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : abseil/absl/flags/CMakeFiles/absl_flags_commandlineflag.dir/depend

