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
CMAKE_SOURCE_DIR = /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build

# Include any dependencies generated for this target.
include CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/flags.make

CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/av1/encoder/x86/reconinter_enc_ssse3.c.o: CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/flags.make
CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/av1/encoder/x86/reconinter_enc_ssse3.c.o: ../av1/encoder/x86/reconinter_enc_ssse3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/av1/encoder/x86/reconinter_enc_ssse3.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/av1/encoder/x86/reconinter_enc_ssse3.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/av1/encoder/x86/reconinter_enc_ssse3.c

CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/av1/encoder/x86/reconinter_enc_ssse3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/av1/encoder/x86/reconinter_enc_ssse3.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/av1/encoder/x86/reconinter_enc_ssse3.c > CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/av1/encoder/x86/reconinter_enc_ssse3.c.i

CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/av1/encoder/x86/reconinter_enc_ssse3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/av1/encoder/x86/reconinter_enc_ssse3.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/av1/encoder/x86/reconinter_enc_ssse3.c -o CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/av1/encoder/x86/reconinter_enc_ssse3.c.s

aom_av1_encoder_ssse3_intrinsics: CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/av1/encoder/x86/reconinter_enc_ssse3.c.o
aom_av1_encoder_ssse3_intrinsics: CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/build.make

.PHONY : aom_av1_encoder_ssse3_intrinsics

# Rule to build all files generated by this target.
CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/build: aom_av1_encoder_ssse3_intrinsics

.PHONY : CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/build

CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/clean

CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/depend:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aom_av1_encoder_ssse3_intrinsics.dir/depend

