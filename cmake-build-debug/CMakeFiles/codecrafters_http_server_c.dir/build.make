# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/Downloads/Projects/codecrafters-http-server-c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Downloads/Projects/codecrafters-http-server-c/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/codecrafters_http_server_c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/codecrafters_http_server_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/codecrafters_http_server_c.dir/flags.make

CMakeFiles/codecrafters_http_server_c.dir/app/server.c.o: CMakeFiles/codecrafters_http_server_c.dir/flags.make
CMakeFiles/codecrafters_http_server_c.dir/app/server.c.o: ../app/server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Downloads/Projects/codecrafters-http-server-c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/codecrafters_http_server_c.dir/app/server.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/codecrafters_http_server_c.dir/app/server.c.o -c /mnt/d/Downloads/Projects/codecrafters-http-server-c/app/server.c

CMakeFiles/codecrafters_http_server_c.dir/app/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/codecrafters_http_server_c.dir/app/server.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/Downloads/Projects/codecrafters-http-server-c/app/server.c > CMakeFiles/codecrafters_http_server_c.dir/app/server.c.i

CMakeFiles/codecrafters_http_server_c.dir/app/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/codecrafters_http_server_c.dir/app/server.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/Downloads/Projects/codecrafters-http-server-c/app/server.c -o CMakeFiles/codecrafters_http_server_c.dir/app/server.c.s

# Object files for target codecrafters_http_server_c
codecrafters_http_server_c_OBJECTS = \
"CMakeFiles/codecrafters_http_server_c.dir/app/server.c.o"

# External object files for target codecrafters_http_server_c
codecrafters_http_server_c_EXTERNAL_OBJECTS =

codecrafters_http_server_c: CMakeFiles/codecrafters_http_server_c.dir/app/server.c.o
codecrafters_http_server_c: CMakeFiles/codecrafters_http_server_c.dir/build.make
codecrafters_http_server_c: CMakeFiles/codecrafters_http_server_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Downloads/Projects/codecrafters-http-server-c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable codecrafters_http_server_c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/codecrafters_http_server_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/codecrafters_http_server_c.dir/build: codecrafters_http_server_c

.PHONY : CMakeFiles/codecrafters_http_server_c.dir/build

CMakeFiles/codecrafters_http_server_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/codecrafters_http_server_c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/codecrafters_http_server_c.dir/clean

CMakeFiles/codecrafters_http_server_c.dir/depend:
	cd /mnt/d/Downloads/Projects/codecrafters-http-server-c/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Downloads/Projects/codecrafters-http-server-c /mnt/d/Downloads/Projects/codecrafters-http-server-c /mnt/d/Downloads/Projects/codecrafters-http-server-c/cmake-build-debug /mnt/d/Downloads/Projects/codecrafters-http-server-c/cmake-build-debug /mnt/d/Downloads/Projects/codecrafters-http-server-c/cmake-build-debug/CMakeFiles/codecrafters_http_server_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/codecrafters_http_server_c.dir/depend
