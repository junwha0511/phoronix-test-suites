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
include CMakeFiles/gav1_decode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gav1_decode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gav1_decode.dir/flags.make

CMakeFiles/gav1_decode.dir/examples/gav1_decode.cc.o: CMakeFiles/gav1_decode.dir/flags.make
CMakeFiles/gav1_decode.dir/examples/gav1_decode.cc.o: ../examples/gav1_decode.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gav1_decode.dir/examples/gav1_decode.cc.o"
	/tmp/pts-compiler-mask-libgav11.2.1/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gav1_decode.dir/examples/gav1_decode.cc.o -c /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/examples/gav1_decode.cc

CMakeFiles/gav1_decode.dir/examples/gav1_decode.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gav1_decode.dir/examples/gav1_decode.cc.i"
	/tmp/pts-compiler-mask-libgav11.2.1/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/examples/gav1_decode.cc > CMakeFiles/gav1_decode.dir/examples/gav1_decode.cc.i

CMakeFiles/gav1_decode.dir/examples/gav1_decode.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gav1_decode.dir/examples/gav1_decode.cc.s"
	/tmp/pts-compiler-mask-libgav11.2.1/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/examples/gav1_decode.cc -o CMakeFiles/gav1_decode.dir/examples/gav1_decode.cc.s

# Object files for target gav1_decode
gav1_decode_OBJECTS = \
"CMakeFiles/gav1_decode.dir/examples/gav1_decode.cc.o"

# External object files for target gav1_decode
gav1_decode_EXTERNAL_OBJECTS = \
"/var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/CMakeFiles/libgav1_file_reader.dir/examples/file_reader.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/CMakeFiles/libgav1_file_reader.dir/examples/file_reader_constants.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/CMakeFiles/libgav1_file_reader.dir/examples/file_reader_factory.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/CMakeFiles/libgav1_file_reader.dir/examples/ivf_parser.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/CMakeFiles/libgav1_file_writer.dir/examples/file_writer.cc.o"

gav1_decode: CMakeFiles/gav1_decode.dir/examples/gav1_decode.cc.o
gav1_decode: CMakeFiles/libgav1_file_reader.dir/examples/file_reader.cc.o
gav1_decode: CMakeFiles/libgav1_file_reader.dir/examples/file_reader_constants.cc.o
gav1_decode: CMakeFiles/libgav1_file_reader.dir/examples/file_reader_factory.cc.o
gav1_decode: CMakeFiles/libgav1_file_reader.dir/examples/ivf_parser.cc.o
gav1_decode: CMakeFiles/libgav1_file_writer.dir/examples/file_writer.cc.o
gav1_decode: CMakeFiles/gav1_decode.dir/build.make
gav1_decode: abseil/absl/strings/libabsl_strings.a
gav1_decode: abseil/absl/strings/libabsl_str_format_internal.a
gav1_decode: abseil/absl/time/libabsl_time.a
gav1_decode: libgav1.a
gav1_decode: abseil/absl/synchronization/libabsl_synchronization.a
gav1_decode: abseil/absl/synchronization/libabsl_graphcycles_internal.a
gav1_decode: abseil/absl/time/libabsl_time.a
gav1_decode: abseil/absl/time/libabsl_civil_time.a
gav1_decode: abseil/absl/time/libabsl_time_zone.a
gav1_decode: abseil/absl/debugging/libabsl_stacktrace.a
gav1_decode: abseil/absl/debugging/libabsl_symbolize.a
gav1_decode: abseil/absl/strings/libabsl_strings.a
gav1_decode: abseil/absl/strings/libabsl_strings_internal.a
gav1_decode: abseil/absl/numeric/libabsl_int128.a
gav1_decode: abseil/absl/base/libabsl_throw_delegate.a
gav1_decode: abseil/absl/base/libabsl_malloc_internal.a
gav1_decode: abseil/absl/debugging/libabsl_debugging_internal.a
gav1_decode: abseil/absl/debugging/libabsl_demangle_internal.a
gav1_decode: abseil/absl/base/libabsl_base.a
gav1_decode: abseil/absl/base/libabsl_raw_logging_internal.a
gav1_decode: abseil/absl/base/libabsl_log_severity.a
gav1_decode: abseil/absl/base/libabsl_spinlock_wait.a
gav1_decode: CMakeFiles/gav1_decode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gav1_decode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gav1_decode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gav1_decode.dir/build: gav1_decode

.PHONY : CMakeFiles/gav1_decode.dir/build

CMakeFiles/gav1_decode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gav1_decode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gav1_decode.dir/clean

CMakeFiles/gav1_decode.dir/depend:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1 /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1 /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build /var/lib/phoronix-test-suite/installed-tests/pts/libgav1-1.2.1/build/CMakeFiles/gav1_decode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gav1_decode.dir/depend

