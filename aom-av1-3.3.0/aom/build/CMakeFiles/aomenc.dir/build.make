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
include CMakeFiles/aomenc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aomenc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aomenc.dir/flags.make

CMakeFiles/aomenc.dir/apps/aomenc.c.o: CMakeFiles/aomenc.dir/flags.make
CMakeFiles/aomenc.dir/apps/aomenc.c.o: ../apps/aomenc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/aomenc.dir/apps/aomenc.c.o"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/aomenc.dir/apps/aomenc.c.o   -c /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/apps/aomenc.c

CMakeFiles/aomenc.dir/apps/aomenc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/aomenc.dir/apps/aomenc.c.i"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/apps/aomenc.c > CMakeFiles/aomenc.dir/apps/aomenc.c.i

CMakeFiles/aomenc.dir/apps/aomenc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/aomenc.dir/apps/aomenc.c.s"
	/tmp/pts-compiler-mask-aom-av13.3.0/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/apps/aomenc.c -o CMakeFiles/aomenc.dir/apps/aomenc.c.s

# Object files for target aomenc
aomenc_OBJECTS = \
"CMakeFiles/aomenc.dir/apps/aomenc.c.o"

# External object files for target aomenc
aomenc_EXTERNAL_OBJECTS = \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_common_app_util.dir/av1/arg_defs.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_common_app_util.dir/common/args_helper.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_common_app_util.dir/common/args.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_common_app_util.dir/common/av1_config.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_common_app_util.dir/common/md5_utils.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_common_app_util.dir/common/tools_common.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_common_app_util.dir/common/rawenc.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_common_app_util.dir/common/y4menc.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_common_app_util.dir/common/ivfdec.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_encoder_app_util.dir/common/ivfenc.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_encoder_app_util.dir/common/video_writer.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_encoder_app_util.dir/common/warnings.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_encoder_app_util.dir/common/y4minput.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_encoder_app_util.dir/examples/encoder_util.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_encoder_app_util.dir/common/webmenc.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_encoder_stats.dir/stats/aomstats.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aom_encoder_stats.dir/stats/rate_hist.c.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/convert_argb.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/cpu_id.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/planar_functions.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/row_any.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/row_common.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/row_gcc.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/row_mips.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/row_neon.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/row_neon64.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/row_win.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/scale.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/scale_any.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/scale_common.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/scale_gcc.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/scale_mips.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/scale_neon.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/scale_neon64.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/scale_win.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/yuv.dir/third_party/libyuv/source/scale_uv.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/webm.dir/third_party/libwebm/common/hdr_util.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/webm.dir/third_party/libwebm/mkvmuxer/mkvmuxer.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/webm.dir/third_party/libwebm/mkvmuxer/mkvmuxerutil.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/webm.dir/third_party/libwebm/mkvmuxer/mkvwriter.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/webm.dir/third_party/libwebm/mkvparser/mkvparser.cc.o" \
"/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/webm.dir/third_party/libwebm/mkvparser/mkvreader.cc.o"

aomenc: CMakeFiles/aomenc.dir/apps/aomenc.c.o
aomenc: CMakeFiles/aom_common_app_util.dir/av1/arg_defs.c.o
aomenc: CMakeFiles/aom_common_app_util.dir/common/args_helper.c.o
aomenc: CMakeFiles/aom_common_app_util.dir/common/args.c.o
aomenc: CMakeFiles/aom_common_app_util.dir/common/av1_config.c.o
aomenc: CMakeFiles/aom_common_app_util.dir/common/md5_utils.c.o
aomenc: CMakeFiles/aom_common_app_util.dir/common/tools_common.c.o
aomenc: CMakeFiles/aom_common_app_util.dir/common/rawenc.c.o
aomenc: CMakeFiles/aom_common_app_util.dir/common/y4menc.c.o
aomenc: CMakeFiles/aom_common_app_util.dir/common/ivfdec.c.o
aomenc: CMakeFiles/aom_encoder_app_util.dir/common/ivfenc.c.o
aomenc: CMakeFiles/aom_encoder_app_util.dir/common/video_writer.c.o
aomenc: CMakeFiles/aom_encoder_app_util.dir/common/warnings.c.o
aomenc: CMakeFiles/aom_encoder_app_util.dir/common/y4minput.c.o
aomenc: CMakeFiles/aom_encoder_app_util.dir/examples/encoder_util.c.o
aomenc: CMakeFiles/aom_encoder_app_util.dir/common/webmenc.cc.o
aomenc: CMakeFiles/aom_encoder_stats.dir/stats/aomstats.c.o
aomenc: CMakeFiles/aom_encoder_stats.dir/stats/rate_hist.c.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/convert_argb.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/cpu_id.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/planar_functions.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/row_any.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/row_common.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/row_gcc.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/row_mips.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/row_neon.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/row_neon64.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/row_win.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/scale.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/scale_any.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/scale_common.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/scale_gcc.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/scale_mips.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/scale_neon.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/scale_neon64.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/scale_win.cc.o
aomenc: CMakeFiles/yuv.dir/third_party/libyuv/source/scale_uv.cc.o
aomenc: CMakeFiles/webm.dir/third_party/libwebm/common/hdr_util.cc.o
aomenc: CMakeFiles/webm.dir/third_party/libwebm/mkvmuxer/mkvmuxer.cc.o
aomenc: CMakeFiles/webm.dir/third_party/libwebm/mkvmuxer/mkvmuxerutil.cc.o
aomenc: CMakeFiles/webm.dir/third_party/libwebm/mkvmuxer/mkvwriter.cc.o
aomenc: CMakeFiles/webm.dir/third_party/libwebm/mkvparser/mkvparser.cc.o
aomenc: CMakeFiles/webm.dir/third_party/libwebm/mkvparser/mkvreader.cc.o
aomenc: CMakeFiles/aomenc.dir/build.make
aomenc: libaom.a
aomenc: CMakeFiles/aomenc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable aomenc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aomenc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aomenc.dir/build: aomenc

.PHONY : CMakeFiles/aomenc.dir/build

CMakeFiles/aomenc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aomenc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aomenc.dir/clean

CMakeFiles/aomenc.dir/depend:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build /var/lib/phoronix-test-suite/installed-tests/pts/aom-av1-3.3.0/aom/build/CMakeFiles/aomenc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aomenc.dir/depend
