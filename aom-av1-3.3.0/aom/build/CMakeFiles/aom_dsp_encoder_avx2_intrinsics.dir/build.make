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
include CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/masked_sad_intrin_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/masked_sad_intrin_avx2.c.o: ../aom_dsp/x86/masked_sad_intrin_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/masked_sad_intrin_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/masked_sad_intrin_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/masked_sad_intrin_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/masked_sad_intrin_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/masked_sad_intrin_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/masked_sad_intrin_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/masked_sad_intrin_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/masked_sad_intrin_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/masked_sad_intrin_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/masked_sad_intrin_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/masked_sad_intrin_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/subtract_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/subtract_avx2.c.o: ../aom_dsp/x86/subtract_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/subtract_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/subtract_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/subtract_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/subtract_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/subtract_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/subtract_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/subtract_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/subtract_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/subtract_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/subtract_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/subtract_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_quantize_intrin_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_quantize_intrin_avx2.c.o: ../aom_dsp/x86/highbd_quantize_intrin_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_quantize_intrin_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_quantize_intrin_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/highbd_quantize_intrin_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_quantize_intrin_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_quantize_intrin_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/highbd_quantize_intrin_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_quantize_intrin_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_quantize_intrin_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_quantize_intrin_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/highbd_quantize_intrin_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_quantize_intrin_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/adaptive_quantize_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/adaptive_quantize_avx2.c.o: ../aom_dsp/x86/adaptive_quantize_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/adaptive_quantize_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/adaptive_quantize_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/adaptive_quantize_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/adaptive_quantize_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/adaptive_quantize_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/adaptive_quantize_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/adaptive_quantize_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/adaptive_quantize_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/adaptive_quantize_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/adaptive_quantize_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/adaptive_quantize_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_adaptive_quantize_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_adaptive_quantize_avx2.c.o: ../aom_dsp/x86/highbd_adaptive_quantize_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_adaptive_quantize_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_adaptive_quantize_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/highbd_adaptive_quantize_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_adaptive_quantize_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_adaptive_quantize_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/highbd_adaptive_quantize_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_adaptive_quantize_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_adaptive_quantize_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_adaptive_quantize_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/highbd_adaptive_quantize_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_adaptive_quantize_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad4d_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad4d_avx2.c.o: ../aom_dsp/x86/sad4d_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad4d_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad4d_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sad4d_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad4d_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad4d_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sad4d_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad4d_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad4d_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad4d_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sad4d_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad4d_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_avx2.c.o: ../aom_dsp/x86/sad_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sad_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sad_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sad_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_highbd_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_highbd_avx2.c.o: ../aom_dsp/x86/sad_highbd_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_highbd_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_highbd_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sad_highbd_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_highbd_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_highbd_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sad_highbd_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_highbd_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_highbd_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_highbd_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sad_highbd_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_highbd_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_impl_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_impl_avx2.c.o: ../aom_dsp/x86/sad_impl_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_impl_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_impl_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sad_impl_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_impl_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_impl_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sad_impl_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_impl_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_impl_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_impl_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sad_impl_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_impl_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_avx2.c.o: ../aom_dsp/x86/variance_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/variance_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/variance_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/variance_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_variance_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_variance_avx2.c.o: ../aom_dsp/x86/highbd_variance_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_variance_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_variance_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/highbd_variance_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_variance_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_variance_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/highbd_variance_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_variance_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_variance_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_variance_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/highbd_variance_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_variance_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sse_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sse_avx2.c.o: ../aom_dsp/x86/sse_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sse_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sse_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sse_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sse_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sse_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sse_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sse_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sse_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sse_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sse_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sse_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_impl_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_impl_avx2.c.o: ../aom_dsp/x86/variance_impl_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_impl_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_impl_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/variance_impl_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_impl_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_impl_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/variance_impl_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_impl_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_impl_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_impl_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/variance_impl_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_impl_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_sad_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_sad_avx2.c.o: ../aom_dsp/x86/obmc_sad_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_sad_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_sad_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/obmc_sad_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_sad_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_sad_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/obmc_sad_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_sad_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_sad_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_sad_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/obmc_sad_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_sad_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_variance_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_variance_avx2.c.o: ../aom_dsp/x86/obmc_variance_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_variance_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_variance_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/obmc_variance_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_variance_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_variance_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/obmc_variance_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_variance_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_variance_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_variance_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/obmc_variance_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_variance_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/blk_sse_sum_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/blk_sse_sum_avx2.c.o: ../aom_dsp/x86/blk_sse_sum_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/blk_sse_sum_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/blk_sse_sum_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/blk_sse_sum_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/blk_sse_sum_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/blk_sse_sum_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/blk_sse_sum_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/blk_sse_sum_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/blk_sse_sum_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/blk_sse_sum_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/blk_sse_sum_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/blk_sse_sum_avx2.c.s

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sum_squares_avx2.c.o: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/flags.make
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sum_squares_avx2.c.o: ../aom_dsp/x86/sum_squares_avx2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sum_squares_avx2.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sum_squares_avx2.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sum_squares_avx2.c

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sum_squares_avx2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sum_squares_avx2.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sum_squares_avx2.c > CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sum_squares_avx2.c.i

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sum_squares_avx2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sum_squares_avx2.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/aom_dsp/x86/sum_squares_avx2.c -o CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sum_squares_avx2.c.s

aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/masked_sad_intrin_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/subtract_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_quantize_intrin_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/adaptive_quantize_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_adaptive_quantize_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad4d_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_highbd_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sad_impl_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/highbd_variance_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sse_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/variance_impl_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_sad_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/obmc_variance_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/blk_sse_sum_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/aom_dsp/x86/sum_squares_avx2.c.o
aom_dsp_encoder_avx2_intrinsics: CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/build.make

.PHONY : aom_dsp_encoder_avx2_intrinsics

# Rule to build all files generated by this target.
CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/build: aom_dsp_encoder_avx2_intrinsics

.PHONY : CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/build

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/clean

CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/depend:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aom_dsp_encoder_avx2_intrinsics.dir/depend

