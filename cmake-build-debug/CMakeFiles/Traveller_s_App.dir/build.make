# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\FMI\OOP\Traveller's_App"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\FMI\OOP\Traveller's_App\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Traveller_s_App.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Traveller_s_App.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Traveller_s_App.dir/flags.make

CMakeFiles/Traveller_s_App.dir/main.cpp.obj: CMakeFiles/Traveller_s_App.dir/flags.make
CMakeFiles/Traveller_s_App.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\FMI\OOP\Traveller's_App\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Traveller_s_App.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Traveller_s_App.dir\main.cpp.obj -c "E:\FMI\OOP\Traveller's_App\main.cpp"

CMakeFiles/Traveller_s_App.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Traveller_s_App.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\FMI\OOP\Traveller's_App\main.cpp" > CMakeFiles\Traveller_s_App.dir\main.cpp.i

CMakeFiles/Traveller_s_App.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Traveller_s_App.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\FMI\OOP\Traveller's_App\main.cpp" -o CMakeFiles\Traveller_s_App.dir\main.cpp.s

# Object files for target Traveller_s_App
Traveller_s_App_OBJECTS = \
"CMakeFiles/Traveller_s_App.dir/main.cpp.obj"

# External object files for target Traveller_s_App
Traveller_s_App_EXTERNAL_OBJECTS =

Traveller_s_App.exe: CMakeFiles/Traveller_s_App.dir/main.cpp.obj
Traveller_s_App.exe: CMakeFiles/Traveller_s_App.dir/build.make
Traveller_s_App.exe: CMakeFiles/Traveller_s_App.dir/linklibs.rsp
Traveller_s_App.exe: CMakeFiles/Traveller_s_App.dir/objects1.rsp
Traveller_s_App.exe: CMakeFiles/Traveller_s_App.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\FMI\OOP\Traveller's_App\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Traveller_s_App.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Traveller_s_App.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Traveller_s_App.dir/build: Traveller_s_App.exe

.PHONY : CMakeFiles/Traveller_s_App.dir/build

CMakeFiles/Traveller_s_App.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Traveller_s_App.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Traveller_s_App.dir/clean

CMakeFiles/Traveller_s_App.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\FMI\OOP\Traveller's_App" "E:\FMI\OOP\Traveller's_App" "E:\FMI\OOP\Traveller's_App\cmake-build-debug" "E:\FMI\OOP\Traveller's_App\cmake-build-debug" "E:\FMI\OOP\Traveller's_App\cmake-build-debug\CMakeFiles\Traveller_s_App.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Traveller_s_App.dir/depend

