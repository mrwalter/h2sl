# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.5.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.5.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/derya/Desktop/codes/h2sl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/derya/Desktop/codes/h2sl/build

# Include any dependencies generated for this target.
include src/dcg/CMakeFiles/h2sl-dcg-test.dir/depend.make

# Include the progress variables for this target.
include src/dcg/CMakeFiles/h2sl-dcg-test.dir/progress.make

# Include the compile flags for this target's objects.
include src/dcg/CMakeFiles/h2sl-dcg-test.dir/flags.make

src/dcg/dcg_test_cmdline.c: ../src/dcg/dcg_test.ggo
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/derya/Desktop/codes/h2sl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating dcg_test_cmdline.c, dcg_test_cmdline.h"
	cd /Users/derya/Desktop/codes/h2sl/build/src/dcg && /usr/local/bin/gengetopt -i /Users/derya/Desktop/codes/h2sl/src/dcg/dcg_test.ggo --file-name dcg_test_cmdline --output-dir=/Users/derya/Desktop/codes/h2sl/build/src/dcg --unamed-opts

src/dcg/dcg_test_cmdline.h: src/dcg/dcg_test_cmdline.c
	@$(CMAKE_COMMAND) -E touch_nocreate src/dcg/dcg_test_cmdline.h

src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o: src/dcg/CMakeFiles/h2sl-dcg-test.dir/flags.make
src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o: ../src/dcg/dcg_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/derya/Desktop/codes/h2sl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o"
	cd /Users/derya/Desktop/codes/h2sl/build/src/dcg && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o -c /Users/derya/Desktop/codes/h2sl/src/dcg/dcg_test.cc

src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.i"
	cd /Users/derya/Desktop/codes/h2sl/build/src/dcg && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/derya/Desktop/codes/h2sl/src/dcg/dcg_test.cc > CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.i

src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.s"
	cd /Users/derya/Desktop/codes/h2sl/build/src/dcg && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/derya/Desktop/codes/h2sl/src/dcg/dcg_test.cc -o CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.s

src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o.requires:

.PHONY : src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o.requires

src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o.provides: src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o.requires
	$(MAKE) -f src/dcg/CMakeFiles/h2sl-dcg-test.dir/build.make src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o.provides.build
.PHONY : src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o.provides

src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o.provides.build: src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o


src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o: src/dcg/CMakeFiles/h2sl-dcg-test.dir/flags.make
src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o: src/dcg/dcg_test_cmdline.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/derya/Desktop/codes/h2sl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o"
	cd /Users/derya/Desktop/codes/h2sl/build/src/dcg && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o   -c /Users/derya/Desktop/codes/h2sl/build/src/dcg/dcg_test_cmdline.c

src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.i"
	cd /Users/derya/Desktop/codes/h2sl/build/src/dcg && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/derya/Desktop/codes/h2sl/build/src/dcg/dcg_test_cmdline.c > CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.i

src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.s"
	cd /Users/derya/Desktop/codes/h2sl/build/src/dcg && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/derya/Desktop/codes/h2sl/build/src/dcg/dcg_test_cmdline.c -o CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.s

src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o.requires:

.PHONY : src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o.requires

src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o.provides: src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o.requires
	$(MAKE) -f src/dcg/CMakeFiles/h2sl-dcg-test.dir/build.make src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o.provides.build
.PHONY : src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o.provides

src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o.provides.build: src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o


# Object files for target h2sl-dcg-test
h2sl__dcg__test_OBJECTS = \
"CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o" \
"CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o"

# External object files for target h2sl-dcg-test
h2sl__dcg__test_EXTERNAL_OBJECTS =

bin/h2sl-dcg-test: src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o
bin/h2sl-dcg-test: src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o
bin/h2sl-dcg-test: src/dcg/CMakeFiles/h2sl-dcg-test.dir/build.make
bin/h2sl-dcg-test: lib/libh2sl-dcg.a
bin/h2sl-dcg-test: lib/libh2sl-llm.a
bin/h2sl-dcg-test: lib/libh2sl-parser.a
bin/h2sl-dcg-test: lib/libh2sl-language.a
bin/h2sl-dcg-test: lib/libh2sl-symbol.a
bin/h2sl-dcg-test: lib/libh2sl-common.a
bin/h2sl-dcg-test: /usr/local/lib/liblbfgs.dylib
bin/h2sl-dcg-test: /usr/local/lib/libboost_system.dylib
bin/h2sl-dcg-test: /usr/local/lib/libboost_thread.dylib
bin/h2sl-dcg-test: /usr/local/lib/libboost_filesystem.dylib
bin/h2sl-dcg-test: /usr/local/lib/libboost_chrono.dylib
bin/h2sl-dcg-test: /usr/local/lib/libboost_date_time.dylib
bin/h2sl-dcg-test: /usr/local/lib/libboost_atomic.dylib
bin/h2sl-dcg-test: /usr/lib/libxml2.dylib
bin/h2sl-dcg-test: src/dcg/CMakeFiles/h2sl-dcg-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/derya/Desktop/codes/h2sl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../bin/h2sl-dcg-test"
	cd /Users/derya/Desktop/codes/h2sl/build/src/dcg && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/h2sl-dcg-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/dcg/CMakeFiles/h2sl-dcg-test.dir/build: bin/h2sl-dcg-test

.PHONY : src/dcg/CMakeFiles/h2sl-dcg-test.dir/build

src/dcg/CMakeFiles/h2sl-dcg-test.dir/requires: src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test.cc.o.requires
src/dcg/CMakeFiles/h2sl-dcg-test.dir/requires: src/dcg/CMakeFiles/h2sl-dcg-test.dir/dcg_test_cmdline.c.o.requires

.PHONY : src/dcg/CMakeFiles/h2sl-dcg-test.dir/requires

src/dcg/CMakeFiles/h2sl-dcg-test.dir/clean:
	cd /Users/derya/Desktop/codes/h2sl/build/src/dcg && $(CMAKE_COMMAND) -P CMakeFiles/h2sl-dcg-test.dir/cmake_clean.cmake
.PHONY : src/dcg/CMakeFiles/h2sl-dcg-test.dir/clean

src/dcg/CMakeFiles/h2sl-dcg-test.dir/depend: src/dcg/dcg_test_cmdline.c
src/dcg/CMakeFiles/h2sl-dcg-test.dir/depend: src/dcg/dcg_test_cmdline.h
	cd /Users/derya/Desktop/codes/h2sl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/derya/Desktop/codes/h2sl /Users/derya/Desktop/codes/h2sl/src/dcg /Users/derya/Desktop/codes/h2sl/build /Users/derya/Desktop/codes/h2sl/build/src/dcg /Users/derya/Desktop/codes/h2sl/build/src/dcg/CMakeFiles/h2sl-dcg-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/dcg/CMakeFiles/h2sl-dcg-test.dir/depend

