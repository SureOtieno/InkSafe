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
CMAKE_BINARY_DIR = /home/suleiman/InkSafe/build/Desktop-Debug

# Utility rule file for InkSafe_autogen_timestamp_deps.

# Include any custom commands dependencies for this target.
include CMakeFiles/InkSafe_autogen_timestamp_deps.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/InkSafe_autogen_timestamp_deps.dir/progress.make

CMakeFiles/InkSafe_autogen_timestamp_deps: /usr/lib/qt6/libexec/moc
CMakeFiles/InkSafe_autogen_timestamp_deps: /usr/lib/x86_64-linux-gnu/libQt6Gui.so.6.4.2
CMakeFiles/InkSafe_autogen_timestamp_deps: /usr/lib/x86_64-linux-gnu/libQt6MultimediaWidgets.so.6.4.2
CMakeFiles/InkSafe_autogen_timestamp_deps: /usr/lib/x86_64-linux-gnu/libQt6Widgets.so.6.4.2
CMakeFiles/InkSafe_autogen_timestamp_deps: /usr/lib/qt6/libexec/uic
CMakeFiles/InkSafe_autogen_timestamp_deps: /usr/lib/x86_64-linux-gnu/libQt6Sql.so.6.4.2
CMakeFiles/InkSafe_autogen_timestamp_deps: /usr/lib/x86_64-linux-gnu/libQt6Multimedia.so.6.4.2

InkSafe_autogen_timestamp_deps: CMakeFiles/InkSafe_autogen_timestamp_deps
InkSafe_autogen_timestamp_deps: CMakeFiles/InkSafe_autogen_timestamp_deps.dir/build.make
.PHONY : InkSafe_autogen_timestamp_deps

# Rule to build all files generated by this target.
CMakeFiles/InkSafe_autogen_timestamp_deps.dir/build: InkSafe_autogen_timestamp_deps
.PHONY : CMakeFiles/InkSafe_autogen_timestamp_deps.dir/build

CMakeFiles/InkSafe_autogen_timestamp_deps.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/InkSafe_autogen_timestamp_deps.dir/cmake_clean.cmake
.PHONY : CMakeFiles/InkSafe_autogen_timestamp_deps.dir/clean

CMakeFiles/InkSafe_autogen_timestamp_deps.dir/depend:
	cd /home/suleiman/InkSafe/build/Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suleiman/InkSafe /home/suleiman/InkSafe /home/suleiman/InkSafe/build/Desktop-Debug /home/suleiman/InkSafe/build/Desktop-Debug /home/suleiman/InkSafe/build/Desktop-Debug/CMakeFiles/InkSafe_autogen_timestamp_deps.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/InkSafe_autogen_timestamp_deps.dir/depend

