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
include src/symbol/CMakeFiles/h2sl-number-demo.dir/depend.make

# Include the progress variables for this target.
include src/symbol/CMakeFiles/h2sl-number-demo.dir/progress.make

# Include the compile flags for this target's objects.
include src/symbol/CMakeFiles/h2sl-number-demo.dir/flags.make

src/symbol/number_demo_cmdline.c: ../src/symbol/number_demo.ggo
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/derya/Desktop/codes/h2sl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating number_demo_cmdline.c, number_demo_cmdline.h"
	cd /Users/derya/Desktop/codes/h2sl/build/src/symbol && /usr/local/bin/gengetopt -i /Users/derya/Desktop/codes/h2sl/src/symbol/number_demo.ggo --file-name number_demo_cmdline --output-dir=/Users/derya/Desktop/codes/h2sl/build/src/symbol --unamed-opts

src/symbol/number_demo_cmdline.h: src/symbol/number_demo_cmdline.c
	@$(CMAKE_COMMAND) -E touch_nocreate src/symbol/number_demo_cmdline.h

src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o: src/symbol/CMakeFiles/h2sl-number-demo.dir/flags.make
src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o: ../src/symbol/number_demo.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/derya/Desktop/codes/h2sl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o"
	cd /Users/derya/Desktop/codes/h2sl/build/src/symbol && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o -c /Users/derya/Desktop/codes/h2sl/src/symbol/number_demo.cc

src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/h2sl-number-demo.dir/number_demo.cc.i"
	cd /Users/derya/Desktop/codes/h2sl/build/src/symbol && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/derya/Desktop/codes/h2sl/src/symbol/number_demo.cc > CMakeFiles/h2sl-number-demo.dir/number_demo.cc.i

src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/h2sl-number-demo.dir/number_demo.cc.s"
	cd /Users/derya/Desktop/codes/h2sl/build/src/symbol && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/derya/Desktop/codes/h2sl/src/symbol/number_demo.cc -o CMakeFiles/h2sl-number-demo.dir/number_demo.cc.s

src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o.requires:

.PHONY : src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o.requires

src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o.provides: src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o.requires
	$(MAKE) -f src/symbol/CMakeFiles/h2sl-number-demo.dir/build.make src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o.provides.build
.PHONY : src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o.provides

src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o.provides.build: src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o


src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o: src/symbol/CMakeFiles/h2sl-number-demo.dir/flags.make
src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o: src/symbol/number_demo_cmdline.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/derya/Desktop/codes/h2sl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o"
	cd /Users/derya/Desktop/codes/h2sl/build/src/symbol && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o   -c /Users/derya/Desktop/codes/h2sl/build/src/symbol/number_demo_cmdline.c

src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.i"
	cd /Users/derya/Desktop/codes/h2sl/build/src/symbol && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/derya/Desktop/codes/h2sl/build/src/symbol/number_demo_cmdline.c > CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.i

src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.s"
	cd /Users/derya/Desktop/codes/h2sl/build/src/symbol && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/derya/Desktop/codes/h2sl/build/src/symbol/number_demo_cmdline.c -o CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.s

src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o.requires:

.PHONY : src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o.requires

src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o.provides: src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o.requires
	$(MAKE) -f src/symbol/CMakeFiles/h2sl-number-demo.dir/build.make src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o.provides.build
.PHONY : src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o.provides

src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o.provides.build: src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o


# Object files for target h2sl-number-demo
h2sl__number__demo_OBJECTS = \
"CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o" \
"CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o"

# External object files for target h2sl-number-demo
h2sl__number__demo_EXTERNAL_OBJECTS =

bin/h2sl-number-demo: src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o
bin/h2sl-number-demo: src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o
bin/h2sl-number-demo: src/symbol/CMakeFiles/h2sl-number-demo.dir/build.make
bin/h2sl-number-demo: lib/libh2sl-symbol.a
bin/h2sl-number-demo: lib/libh2sl-common.a
bin/h2sl-number-demo: /usr/lib/libxml2.dylib
bin/h2sl-number-demo: src/symbol/CMakeFiles/h2sl-number-demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/derya/Desktop/codes/h2sl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../bin/h2sl-number-demo"
	cd /Users/derya/Desktop/codes/h2sl/build/src/symbol && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/h2sl-number-demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/symbol/CMakeFiles/h2sl-number-demo.dir/build: bin/h2sl-number-demo

.PHONY : src/symbol/CMakeFiles/h2sl-number-demo.dir/build

src/symbol/CMakeFiles/h2sl-number-demo.dir/requires: src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo.cc.o.requires
src/symbol/CMakeFiles/h2sl-number-demo.dir/requires: src/symbol/CMakeFiles/h2sl-number-demo.dir/number_demo_cmdline.c.o.requires

.PHONY : src/symbol/CMakeFiles/h2sl-number-demo.dir/requires

src/symbol/CMakeFiles/h2sl-number-demo.dir/clean:
	cd /Users/derya/Desktop/codes/h2sl/build/src/symbol && $(CMAKE_COMMAND) -P CMakeFiles/h2sl-number-demo.dir/cmake_clean.cmake
.PHONY : src/symbol/CMakeFiles/h2sl-number-demo.dir/clean

src/symbol/CMakeFiles/h2sl-number-demo.dir/depend: src/symbol/number_demo_cmdline.c
src/symbol/CMakeFiles/h2sl-number-demo.dir/depend: src/symbol/number_demo_cmdline.h
	cd /Users/derya/Desktop/codes/h2sl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/derya/Desktop/codes/h2sl /Users/derya/Desktop/codes/h2sl/src/symbol /Users/derya/Desktop/codes/h2sl/build /Users/derya/Desktop/codes/h2sl/build/src/symbol /Users/derya/Desktop/codes/h2sl/build/src/symbol/CMakeFiles/h2sl-number-demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/symbol/CMakeFiles/h2sl-number-demo.dir/depend

