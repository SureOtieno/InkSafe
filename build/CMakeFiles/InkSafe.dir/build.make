# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/suleiman/InkSafe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/suleiman/InkSafe/build

# Include any dependencies generated for this target.
include CMakeFiles/InkSafe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/InkSafe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/InkSafe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/InkSafe.dir/flags.make

InkSafe_autogen/timestamp: /usr/lib/qt6/libexec/moc
InkSafe_autogen/timestamp: /usr/lib/qt6/libexec/uic
InkSafe_autogen/timestamp: CMakeFiles/InkSafe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/suleiman/InkSafe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target InkSafe"
	/usr/bin/cmake -E cmake_autogen /home/suleiman/InkSafe/build/CMakeFiles/InkSafe_autogen.dir/AutogenInfo.json ""
	/usr/bin/cmake -E touch /home/suleiman/InkSafe/build/InkSafe_autogen/timestamp

CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.o: CMakeFiles/InkSafe.dir/flags.make
CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.o: InkSafe_autogen/mocs_compilation.cpp
CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.o: CMakeFiles/InkSafe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/suleiman/InkSafe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.o -MF CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.o -c /home/suleiman/InkSafe/build/InkSafe_autogen/mocs_compilation.cpp

CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suleiman/InkSafe/build/InkSafe_autogen/mocs_compilation.cpp > CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.i

CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suleiman/InkSafe/build/InkSafe_autogen/mocs_compilation.cpp -o CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.s

CMakeFiles/InkSafe.dir/main.cpp.o: CMakeFiles/InkSafe.dir/flags.make
CMakeFiles/InkSafe.dir/main.cpp.o: /home/suleiman/InkSafe/main.cpp
CMakeFiles/InkSafe.dir/main.cpp.o: CMakeFiles/InkSafe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/suleiman/InkSafe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/InkSafe.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/InkSafe.dir/main.cpp.o -MF CMakeFiles/InkSafe.dir/main.cpp.o.d -o CMakeFiles/InkSafe.dir/main.cpp.o -c /home/suleiman/InkSafe/main.cpp

CMakeFiles/InkSafe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/InkSafe.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suleiman/InkSafe/main.cpp > CMakeFiles/InkSafe.dir/main.cpp.i

CMakeFiles/InkSafe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/InkSafe.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suleiman/InkSafe/main.cpp -o CMakeFiles/InkSafe.dir/main.cpp.s

CMakeFiles/InkSafe.dir/mainwindow.cpp.o: CMakeFiles/InkSafe.dir/flags.make
CMakeFiles/InkSafe.dir/mainwindow.cpp.o: /home/suleiman/InkSafe/mainwindow.cpp
CMakeFiles/InkSafe.dir/mainwindow.cpp.o: CMakeFiles/InkSafe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/suleiman/InkSafe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/InkSafe.dir/mainwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/InkSafe.dir/mainwindow.cpp.o -MF CMakeFiles/InkSafe.dir/mainwindow.cpp.o.d -o CMakeFiles/InkSafe.dir/mainwindow.cpp.o -c /home/suleiman/InkSafe/mainwindow.cpp

CMakeFiles/InkSafe.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/InkSafe.dir/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suleiman/InkSafe/mainwindow.cpp > CMakeFiles/InkSafe.dir/mainwindow.cpp.i

CMakeFiles/InkSafe.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/InkSafe.dir/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suleiman/InkSafe/mainwindow.cpp -o CMakeFiles/InkSafe.dir/mainwindow.cpp.s

# Object files for target InkSafe
InkSafe_OBJECTS = \
"CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/InkSafe.dir/main.cpp.o" \
"CMakeFiles/InkSafe.dir/mainwindow.cpp.o"

# External object files for target InkSafe
InkSafe_EXTERNAL_OBJECTS =

InkSafe: CMakeFiles/InkSafe.dir/InkSafe_autogen/mocs_compilation.cpp.o
InkSafe: CMakeFiles/InkSafe.dir/main.cpp.o
InkSafe: CMakeFiles/InkSafe.dir/mainwindow.cpp.o
InkSafe: CMakeFiles/InkSafe.dir/build.make
InkSafe: /usr/lib/x86_64-linux-gnu/libQt6Widgets.so.6.4.2
InkSafe: /usr/lib/x86_64-linux-gnu/libQt6Gui.so.6.4.2
InkSafe: /usr/lib/x86_64-linux-gnu/libQt6Sql.so.6.4.2
InkSafe: /usr/lib/x86_64-linux-gnu/libGLX.so
InkSafe: /usr/lib/x86_64-linux-gnu/libOpenGL.so
InkSafe: /usr/lib/x86_64-linux-gnu/libQt6Core.so.6.4.2
InkSafe: CMakeFiles/InkSafe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/suleiman/InkSafe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable InkSafe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/InkSafe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/InkSafe.dir/build: InkSafe
.PHONY : CMakeFiles/InkSafe.dir/build

CMakeFiles/InkSafe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/InkSafe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/InkSafe.dir/clean

CMakeFiles/InkSafe.dir/depend: InkSafe_autogen/timestamp
	cd /home/suleiman/InkSafe/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suleiman/InkSafe /home/suleiman/InkSafe /home/suleiman/InkSafe/build /home/suleiman/InkSafe/build /home/suleiman/InkSafe/build/CMakeFiles/InkSafe.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/InkSafe.dir/depend

