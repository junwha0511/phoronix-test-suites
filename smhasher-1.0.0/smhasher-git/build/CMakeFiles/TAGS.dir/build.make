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
CMAKE_SOURCE_DIR = /var/lib/phoronix-test-suite/installed-tests/pts/smhasher-1.0.0/smhasher-git

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /var/lib/phoronix-test-suite/installed-tests/pts/smhasher-1.0.0/smhasher-git/build

# Utility rule file for TAGS.

# Include the progress variables for this target.
include CMakeFiles/TAGS.dir/progress.make

CMakeFiles/TAGS:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/smhasher-1.0.0/smhasher-git && etags --language=c++ *.cpp *.cc *.h

TAGS: CMakeFiles/TAGS
TAGS: CMakeFiles/TAGS.dir/build.make

.PHONY : TAGS

# Rule to build all files generated by this target.
CMakeFiles/TAGS.dir/build: TAGS

.PHONY : CMakeFiles/TAGS.dir/build

CMakeFiles/TAGS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TAGS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TAGS.dir/clean

CMakeFiles/TAGS.dir/depend:
	cd /var/lib/phoronix-test-suite/installed-tests/pts/smhasher-1.0.0/smhasher-git/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /var/lib/phoronix-test-suite/installed-tests/pts/smhasher-1.0.0/smhasher-git /var/lib/phoronix-test-suite/installed-tests/pts/smhasher-1.0.0/smhasher-git /var/lib/phoronix-test-suite/installed-tests/pts/smhasher-1.0.0/smhasher-git/build /var/lib/phoronix-test-suite/installed-tests/pts/smhasher-1.0.0/smhasher-git/build /var/lib/phoronix-test-suite/installed-tests/pts/smhasher-1.0.0/smhasher-git/build/CMakeFiles/TAGS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TAGS.dir/depend

