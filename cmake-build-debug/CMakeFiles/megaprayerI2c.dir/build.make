# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mark/CLionProjects/megaprayerI2c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mark/CLionProjects/megaprayerI2c/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/megaprayerI2c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/megaprayerI2c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/megaprayerI2c.dir/flags.make

CMakeFiles/megaprayerI2c.dir/main.cpp.o: CMakeFiles/megaprayerI2c.dir/flags.make
CMakeFiles/megaprayerI2c.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mark/CLionProjects/megaprayerI2c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/megaprayerI2c.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/megaprayerI2c.dir/main.cpp.o -c /Users/mark/CLionProjects/megaprayerI2c/main.cpp

CMakeFiles/megaprayerI2c.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/megaprayerI2c.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mark/CLionProjects/megaprayerI2c/main.cpp > CMakeFiles/megaprayerI2c.dir/main.cpp.i

CMakeFiles/megaprayerI2c.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/megaprayerI2c.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mark/CLionProjects/megaprayerI2c/main.cpp -o CMakeFiles/megaprayerI2c.dir/main.cpp.s

CMakeFiles/megaprayerI2c.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/megaprayerI2c.dir/main.cpp.o.requires

CMakeFiles/megaprayerI2c.dir/main.cpp.o.provides: CMakeFiles/megaprayerI2c.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/megaprayerI2c.dir/build.make CMakeFiles/megaprayerI2c.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/megaprayerI2c.dir/main.cpp.o.provides

CMakeFiles/megaprayerI2c.dir/main.cpp.o.provides.build: CMakeFiles/megaprayerI2c.dir/main.cpp.o


CMakeFiles/megaprayerI2c.dir/i2c.cpp.o: CMakeFiles/megaprayerI2c.dir/flags.make
CMakeFiles/megaprayerI2c.dir/i2c.cpp.o: ../i2c.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mark/CLionProjects/megaprayerI2c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/megaprayerI2c.dir/i2c.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/megaprayerI2c.dir/i2c.cpp.o -c /Users/mark/CLionProjects/megaprayerI2c/i2c.cpp

CMakeFiles/megaprayerI2c.dir/i2c.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/megaprayerI2c.dir/i2c.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mark/CLionProjects/megaprayerI2c/i2c.cpp > CMakeFiles/megaprayerI2c.dir/i2c.cpp.i

CMakeFiles/megaprayerI2c.dir/i2c.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/megaprayerI2c.dir/i2c.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mark/CLionProjects/megaprayerI2c/i2c.cpp -o CMakeFiles/megaprayerI2c.dir/i2c.cpp.s

CMakeFiles/megaprayerI2c.dir/i2c.cpp.o.requires:

.PHONY : CMakeFiles/megaprayerI2c.dir/i2c.cpp.o.requires

CMakeFiles/megaprayerI2c.dir/i2c.cpp.o.provides: CMakeFiles/megaprayerI2c.dir/i2c.cpp.o.requires
	$(MAKE) -f CMakeFiles/megaprayerI2c.dir/build.make CMakeFiles/megaprayerI2c.dir/i2c.cpp.o.provides.build
.PHONY : CMakeFiles/megaprayerI2c.dir/i2c.cpp.o.provides

CMakeFiles/megaprayerI2c.dir/i2c.cpp.o.provides.build: CMakeFiles/megaprayerI2c.dir/i2c.cpp.o


CMakeFiles/megaprayerI2c.dir/common.c.o: CMakeFiles/megaprayerI2c.dir/flags.make
CMakeFiles/megaprayerI2c.dir/common.c.o: ../common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mark/CLionProjects/megaprayerI2c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/megaprayerI2c.dir/common.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/megaprayerI2c.dir/common.c.o   -c /Users/mark/CLionProjects/megaprayerI2c/common.c

CMakeFiles/megaprayerI2c.dir/common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/megaprayerI2c.dir/common.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mark/CLionProjects/megaprayerI2c/common.c > CMakeFiles/megaprayerI2c.dir/common.c.i

CMakeFiles/megaprayerI2c.dir/common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/megaprayerI2c.dir/common.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mark/CLionProjects/megaprayerI2c/common.c -o CMakeFiles/megaprayerI2c.dir/common.c.s

CMakeFiles/megaprayerI2c.dir/common.c.o.requires:

.PHONY : CMakeFiles/megaprayerI2c.dir/common.c.o.requires

CMakeFiles/megaprayerI2c.dir/common.c.o.provides: CMakeFiles/megaprayerI2c.dir/common.c.o.requires
	$(MAKE) -f CMakeFiles/megaprayerI2c.dir/build.make CMakeFiles/megaprayerI2c.dir/common.c.o.provides.build
.PHONY : CMakeFiles/megaprayerI2c.dir/common.c.o.provides

CMakeFiles/megaprayerI2c.dir/common.c.o.provides.build: CMakeFiles/megaprayerI2c.dir/common.c.o


CMakeFiles/megaprayerI2c.dir/event_gpio.c.o: CMakeFiles/megaprayerI2c.dir/flags.make
CMakeFiles/megaprayerI2c.dir/event_gpio.c.o: ../event_gpio.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mark/CLionProjects/megaprayerI2c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/megaprayerI2c.dir/event_gpio.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/megaprayerI2c.dir/event_gpio.c.o   -c /Users/mark/CLionProjects/megaprayerI2c/event_gpio.c

CMakeFiles/megaprayerI2c.dir/event_gpio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/megaprayerI2c.dir/event_gpio.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mark/CLionProjects/megaprayerI2c/event_gpio.c > CMakeFiles/megaprayerI2c.dir/event_gpio.c.i

CMakeFiles/megaprayerI2c.dir/event_gpio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/megaprayerI2c.dir/event_gpio.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mark/CLionProjects/megaprayerI2c/event_gpio.c -o CMakeFiles/megaprayerI2c.dir/event_gpio.c.s

CMakeFiles/megaprayerI2c.dir/event_gpio.c.o.requires:

.PHONY : CMakeFiles/megaprayerI2c.dir/event_gpio.c.o.requires

CMakeFiles/megaprayerI2c.dir/event_gpio.c.o.provides: CMakeFiles/megaprayerI2c.dir/event_gpio.c.o.requires
	$(MAKE) -f CMakeFiles/megaprayerI2c.dir/build.make CMakeFiles/megaprayerI2c.dir/event_gpio.c.o.provides.build
.PHONY : CMakeFiles/megaprayerI2c.dir/event_gpio.c.o.provides

CMakeFiles/megaprayerI2c.dir/event_gpio.c.o.provides.build: CMakeFiles/megaprayerI2c.dir/event_gpio.c.o


CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o: CMakeFiles/megaprayerI2c.dir/flags.make
CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o: ../gpio_lib.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mark/CLionProjects/megaprayerI2c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o   -c /Users/mark/CLionProjects/megaprayerI2c/gpio_lib.c

CMakeFiles/megaprayerI2c.dir/gpio_lib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/megaprayerI2c.dir/gpio_lib.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mark/CLionProjects/megaprayerI2c/gpio_lib.c > CMakeFiles/megaprayerI2c.dir/gpio_lib.c.i

CMakeFiles/megaprayerI2c.dir/gpio_lib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/megaprayerI2c.dir/gpio_lib.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mark/CLionProjects/megaprayerI2c/gpio_lib.c -o CMakeFiles/megaprayerI2c.dir/gpio_lib.c.s

CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o.requires:

.PHONY : CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o.requires

CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o.provides: CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o.requires
	$(MAKE) -f CMakeFiles/megaprayerI2c.dir/build.make CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o.provides.build
.PHONY : CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o.provides

CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o.provides.build: CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o


# Object files for target megaprayerI2c
megaprayerI2c_OBJECTS = \
"CMakeFiles/megaprayerI2c.dir/main.cpp.o" \
"CMakeFiles/megaprayerI2c.dir/i2c.cpp.o" \
"CMakeFiles/megaprayerI2c.dir/common.c.o" \
"CMakeFiles/megaprayerI2c.dir/event_gpio.c.o" \
"CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o"

# External object files for target megaprayerI2c
megaprayerI2c_EXTERNAL_OBJECTS =

megaprayerI2c: CMakeFiles/megaprayerI2c.dir/main.cpp.o
megaprayerI2c: CMakeFiles/megaprayerI2c.dir/i2c.cpp.o
megaprayerI2c: CMakeFiles/megaprayerI2c.dir/common.c.o
megaprayerI2c: CMakeFiles/megaprayerI2c.dir/event_gpio.c.o
megaprayerI2c: CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o
megaprayerI2c: CMakeFiles/megaprayerI2c.dir/build.make
megaprayerI2c: /usr/local/lib/libboost_program_options.dylib
megaprayerI2c: CMakeFiles/megaprayerI2c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mark/CLionProjects/megaprayerI2c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable megaprayerI2c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/megaprayerI2c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/megaprayerI2c.dir/build: megaprayerI2c

.PHONY : CMakeFiles/megaprayerI2c.dir/build

CMakeFiles/megaprayerI2c.dir/requires: CMakeFiles/megaprayerI2c.dir/main.cpp.o.requires
CMakeFiles/megaprayerI2c.dir/requires: CMakeFiles/megaprayerI2c.dir/i2c.cpp.o.requires
CMakeFiles/megaprayerI2c.dir/requires: CMakeFiles/megaprayerI2c.dir/common.c.o.requires
CMakeFiles/megaprayerI2c.dir/requires: CMakeFiles/megaprayerI2c.dir/event_gpio.c.o.requires
CMakeFiles/megaprayerI2c.dir/requires: CMakeFiles/megaprayerI2c.dir/gpio_lib.c.o.requires

.PHONY : CMakeFiles/megaprayerI2c.dir/requires

CMakeFiles/megaprayerI2c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/megaprayerI2c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/megaprayerI2c.dir/clean

CMakeFiles/megaprayerI2c.dir/depend:
	cd /Users/mark/CLionProjects/megaprayerI2c/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mark/CLionProjects/megaprayerI2c /Users/mark/CLionProjects/megaprayerI2c /Users/mark/CLionProjects/megaprayerI2c/cmake-build-debug /Users/mark/CLionProjects/megaprayerI2c/cmake-build-debug /Users/mark/CLionProjects/megaprayerI2c/cmake-build-debug/CMakeFiles/megaprayerI2c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/megaprayerI2c.dir/depend

