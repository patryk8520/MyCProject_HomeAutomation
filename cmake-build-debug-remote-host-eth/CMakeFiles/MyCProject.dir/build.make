# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/pi/Public/MyCProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Public/MyCProject/cmake-build-debug-remote-host-eth

# Include any dependencies generated for this target.
include CMakeFiles/MyCProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyCProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyCProject.dir/flags.make

CMakeFiles/MyCProject.dir/main.c.o: CMakeFiles/MyCProject.dir/flags.make
CMakeFiles/MyCProject.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Public/MyCProject/cmake-build-debug-remote-host-eth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MyCProject.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyCProject.dir/main.c.o   -c /home/pi/Public/MyCProject/main.c

CMakeFiles/MyCProject.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyCProject.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Public/MyCProject/main.c > CMakeFiles/MyCProject.dir/main.c.i

CMakeFiles/MyCProject.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyCProject.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Public/MyCProject/main.c -o CMakeFiles/MyCProject.dir/main.c.s

CMakeFiles/MyCProject.dir/main.c.o.requires:

.PHONY : CMakeFiles/MyCProject.dir/main.c.o.requires

CMakeFiles/MyCProject.dir/main.c.o.provides: CMakeFiles/MyCProject.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/MyCProject.dir/build.make CMakeFiles/MyCProject.dir/main.c.o.provides.build
.PHONY : CMakeFiles/MyCProject.dir/main.c.o.provides

CMakeFiles/MyCProject.dir/main.c.o.provides.build: CMakeFiles/MyCProject.dir/main.c.o


CMakeFiles/MyCProject.dir/ModbusRtu.c.o: CMakeFiles/MyCProject.dir/flags.make
CMakeFiles/MyCProject.dir/ModbusRtu.c.o: ../ModbusRtu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Public/MyCProject/cmake-build-debug-remote-host-eth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MyCProject.dir/ModbusRtu.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyCProject.dir/ModbusRtu.c.o   -c /home/pi/Public/MyCProject/ModbusRtu.c

CMakeFiles/MyCProject.dir/ModbusRtu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyCProject.dir/ModbusRtu.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Public/MyCProject/ModbusRtu.c > CMakeFiles/MyCProject.dir/ModbusRtu.c.i

CMakeFiles/MyCProject.dir/ModbusRtu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyCProject.dir/ModbusRtu.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Public/MyCProject/ModbusRtu.c -o CMakeFiles/MyCProject.dir/ModbusRtu.c.s

CMakeFiles/MyCProject.dir/ModbusRtu.c.o.requires:

.PHONY : CMakeFiles/MyCProject.dir/ModbusRtu.c.o.requires

CMakeFiles/MyCProject.dir/ModbusRtu.c.o.provides: CMakeFiles/MyCProject.dir/ModbusRtu.c.o.requires
	$(MAKE) -f CMakeFiles/MyCProject.dir/build.make CMakeFiles/MyCProject.dir/ModbusRtu.c.o.provides.build
.PHONY : CMakeFiles/MyCProject.dir/ModbusRtu.c.o.provides

CMakeFiles/MyCProject.dir/ModbusRtu.c.o.provides.build: CMakeFiles/MyCProject.dir/ModbusRtu.c.o


CMakeFiles/MyCProject.dir/dht11.c.o: CMakeFiles/MyCProject.dir/flags.make
CMakeFiles/MyCProject.dir/dht11.c.o: ../dht11.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Public/MyCProject/cmake-build-debug-remote-host-eth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/MyCProject.dir/dht11.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyCProject.dir/dht11.c.o   -c /home/pi/Public/MyCProject/dht11.c

CMakeFiles/MyCProject.dir/dht11.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyCProject.dir/dht11.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Public/MyCProject/dht11.c > CMakeFiles/MyCProject.dir/dht11.c.i

CMakeFiles/MyCProject.dir/dht11.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyCProject.dir/dht11.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Public/MyCProject/dht11.c -o CMakeFiles/MyCProject.dir/dht11.c.s

CMakeFiles/MyCProject.dir/dht11.c.o.requires:

.PHONY : CMakeFiles/MyCProject.dir/dht11.c.o.requires

CMakeFiles/MyCProject.dir/dht11.c.o.provides: CMakeFiles/MyCProject.dir/dht11.c.o.requires
	$(MAKE) -f CMakeFiles/MyCProject.dir/build.make CMakeFiles/MyCProject.dir/dht11.c.o.provides.build
.PHONY : CMakeFiles/MyCProject.dir/dht11.c.o.provides

CMakeFiles/MyCProject.dir/dht11.c.o.provides.build: CMakeFiles/MyCProject.dir/dht11.c.o


CMakeFiles/MyCProject.dir/Socket.c.o: CMakeFiles/MyCProject.dir/flags.make
CMakeFiles/MyCProject.dir/Socket.c.o: ../Socket.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Public/MyCProject/cmake-build-debug-remote-host-eth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/MyCProject.dir/Socket.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyCProject.dir/Socket.c.o   -c /home/pi/Public/MyCProject/Socket.c

CMakeFiles/MyCProject.dir/Socket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyCProject.dir/Socket.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Public/MyCProject/Socket.c > CMakeFiles/MyCProject.dir/Socket.c.i

CMakeFiles/MyCProject.dir/Socket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyCProject.dir/Socket.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Public/MyCProject/Socket.c -o CMakeFiles/MyCProject.dir/Socket.c.s

CMakeFiles/MyCProject.dir/Socket.c.o.requires:

.PHONY : CMakeFiles/MyCProject.dir/Socket.c.o.requires

CMakeFiles/MyCProject.dir/Socket.c.o.provides: CMakeFiles/MyCProject.dir/Socket.c.o.requires
	$(MAKE) -f CMakeFiles/MyCProject.dir/build.make CMakeFiles/MyCProject.dir/Socket.c.o.provides.build
.PHONY : CMakeFiles/MyCProject.dir/Socket.c.o.provides

CMakeFiles/MyCProject.dir/Socket.c.o.provides.build: CMakeFiles/MyCProject.dir/Socket.c.o


CMakeFiles/MyCProject.dir/Button.c.o: CMakeFiles/MyCProject.dir/flags.make
CMakeFiles/MyCProject.dir/Button.c.o: ../Button.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Public/MyCProject/cmake-build-debug-remote-host-eth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/MyCProject.dir/Button.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyCProject.dir/Button.c.o   -c /home/pi/Public/MyCProject/Button.c

CMakeFiles/MyCProject.dir/Button.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyCProject.dir/Button.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Public/MyCProject/Button.c > CMakeFiles/MyCProject.dir/Button.c.i

CMakeFiles/MyCProject.dir/Button.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyCProject.dir/Button.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Public/MyCProject/Button.c -o CMakeFiles/MyCProject.dir/Button.c.s

CMakeFiles/MyCProject.dir/Button.c.o.requires:

.PHONY : CMakeFiles/MyCProject.dir/Button.c.o.requires

CMakeFiles/MyCProject.dir/Button.c.o.provides: CMakeFiles/MyCProject.dir/Button.c.o.requires
	$(MAKE) -f CMakeFiles/MyCProject.dir/build.make CMakeFiles/MyCProject.dir/Button.c.o.provides.build
.PHONY : CMakeFiles/MyCProject.dir/Button.c.o.provides

CMakeFiles/MyCProject.dir/Button.c.o.provides.build: CMakeFiles/MyCProject.dir/Button.c.o


CMakeFiles/MyCProject.dir/Database.c.o: CMakeFiles/MyCProject.dir/flags.make
CMakeFiles/MyCProject.dir/Database.c.o: ../Database.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Public/MyCProject/cmake-build-debug-remote-host-eth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/MyCProject.dir/Database.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyCProject.dir/Database.c.o   -c /home/pi/Public/MyCProject/Database.c

CMakeFiles/MyCProject.dir/Database.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyCProject.dir/Database.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Public/MyCProject/Database.c > CMakeFiles/MyCProject.dir/Database.c.i

CMakeFiles/MyCProject.dir/Database.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyCProject.dir/Database.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Public/MyCProject/Database.c -o CMakeFiles/MyCProject.dir/Database.c.s

CMakeFiles/MyCProject.dir/Database.c.o.requires:

.PHONY : CMakeFiles/MyCProject.dir/Database.c.o.requires

CMakeFiles/MyCProject.dir/Database.c.o.provides: CMakeFiles/MyCProject.dir/Database.c.o.requires
	$(MAKE) -f CMakeFiles/MyCProject.dir/build.make CMakeFiles/MyCProject.dir/Database.c.o.provides.build
.PHONY : CMakeFiles/MyCProject.dir/Database.c.o.provides

CMakeFiles/MyCProject.dir/Database.c.o.provides.build: CMakeFiles/MyCProject.dir/Database.c.o


# Object files for target MyCProject
MyCProject_OBJECTS = \
"CMakeFiles/MyCProject.dir/main.c.o" \
"CMakeFiles/MyCProject.dir/ModbusRtu.c.o" \
"CMakeFiles/MyCProject.dir/dht11.c.o" \
"CMakeFiles/MyCProject.dir/Socket.c.o" \
"CMakeFiles/MyCProject.dir/Button.c.o" \
"CMakeFiles/MyCProject.dir/Database.c.o"

# External object files for target MyCProject
MyCProject_EXTERNAL_OBJECTS =

MyCProject: CMakeFiles/MyCProject.dir/main.c.o
MyCProject: CMakeFiles/MyCProject.dir/ModbusRtu.c.o
MyCProject: CMakeFiles/MyCProject.dir/dht11.c.o
MyCProject: CMakeFiles/MyCProject.dir/Socket.c.o
MyCProject: CMakeFiles/MyCProject.dir/Button.c.o
MyCProject: CMakeFiles/MyCProject.dir/Database.c.o
MyCProject: CMakeFiles/MyCProject.dir/build.make
MyCProject: /usr/local/lib/libmodbus.so
MyCProject: /usr/local/lib/libbcm2835.a
MyCProject: CMakeFiles/MyCProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Public/MyCProject/cmake-build-debug-remote-host-eth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable MyCProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyCProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyCProject.dir/build: MyCProject

.PHONY : CMakeFiles/MyCProject.dir/build

CMakeFiles/MyCProject.dir/requires: CMakeFiles/MyCProject.dir/main.c.o.requires
CMakeFiles/MyCProject.dir/requires: CMakeFiles/MyCProject.dir/ModbusRtu.c.o.requires
CMakeFiles/MyCProject.dir/requires: CMakeFiles/MyCProject.dir/dht11.c.o.requires
CMakeFiles/MyCProject.dir/requires: CMakeFiles/MyCProject.dir/Socket.c.o.requires
CMakeFiles/MyCProject.dir/requires: CMakeFiles/MyCProject.dir/Button.c.o.requires
CMakeFiles/MyCProject.dir/requires: CMakeFiles/MyCProject.dir/Database.c.o.requires

.PHONY : CMakeFiles/MyCProject.dir/requires

CMakeFiles/MyCProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyCProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyCProject.dir/clean

CMakeFiles/MyCProject.dir/depend:
	cd /home/pi/Public/MyCProject/cmake-build-debug-remote-host-eth && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Public/MyCProject /home/pi/Public/MyCProject /home/pi/Public/MyCProject/cmake-build-debug-remote-host-eth /home/pi/Public/MyCProject/cmake-build-debug-remote-host-eth /home/pi/Public/MyCProject/cmake-build-debug-remote-host-eth/CMakeFiles/MyCProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyCProject.dir/depend

