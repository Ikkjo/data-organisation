# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Ilija\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.5981.166\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Ilija\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.5981.166\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Ilija\Git Repos\GitHub\data-organisation\#645_deo3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Ilija\Git Repos\GitHub\data-organisation\#645_deo3\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/rasuta.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rasuta.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rasuta.dir/flags.make

CMakeFiles/rasuta.dir/main.c.obj: CMakeFiles/rasuta.dir/flags.make
CMakeFiles/rasuta.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Ilija\Git Repos\GitHub\data-organisation\#645_deo3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rasuta.dir/main.c.obj"
	C:\Programming\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\rasuta.dir\main.c.obj   -c "C:\Users\Ilija\Git Repos\GitHub\data-organisation\#645_deo3\main.c"

CMakeFiles/rasuta.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rasuta.dir/main.c.i"
	C:\Programming\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Ilija\Git Repos\GitHub\data-organisation\#645_deo3\main.c" > CMakeFiles\rasuta.dir\main.c.i

CMakeFiles/rasuta.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rasuta.dir/main.c.s"
	C:\Programming\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Ilija\Git Repos\GitHub\data-organisation\#645_deo3\main.c" -o CMakeFiles\rasuta.dir\main.c.s

# Object files for target rasuta
rasuta_OBJECTS = \
"CMakeFiles/rasuta.dir/main.c.obj"

# External object files for target rasuta
rasuta_EXTERNAL_OBJECTS =

rasuta.exe: CMakeFiles/rasuta.dir/main.c.obj
rasuta.exe: CMakeFiles/rasuta.dir/build.make
rasuta.exe: CMakeFiles/rasuta.dir/linklibs.rsp
rasuta.exe: CMakeFiles/rasuta.dir/objects1.rsp
rasuta.exe: CMakeFiles/rasuta.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Ilija\Git Repos\GitHub\data-organisation\#645_deo3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable rasuta.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\rasuta.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rasuta.dir/build: rasuta.exe

.PHONY : CMakeFiles/rasuta.dir/build

CMakeFiles/rasuta.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\rasuta.dir\cmake_clean.cmake
.PHONY : CMakeFiles/rasuta.dir/clean

CMakeFiles/rasuta.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Ilija\Git Repos\GitHub\data-organisation\#645_deo3" "C:\Users\Ilija\Git Repos\GitHub\data-organisation\#645_deo3" "C:\Users\Ilija\Git Repos\GitHub\data-organisation\#645_deo3\cmake-build-debug" "C:\Users\Ilija\Git Repos\GitHub\data-organisation\#645_deo3\cmake-build-debug" "C:\Users\Ilija\Git Repos\GitHub\data-organisation\#645_deo3\cmake-build-debug\CMakeFiles\rasuta.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/rasuta.dir/depend

