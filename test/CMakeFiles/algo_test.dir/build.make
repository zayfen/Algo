# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/zayafa/workspace/Algo/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zayafa/workspace/Algo/test

# Include any dependencies generated for this target.
include CMakeFiles/algo_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/algo_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algo_test.dir/flags.make

CMakeFiles/algo_test.dir/search/test_search.cpp.o: CMakeFiles/algo_test.dir/flags.make
CMakeFiles/algo_test.dir/search/test_search.cpp.o: search/test_search.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zayafa/workspace/Algo/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algo_test.dir/search/test_search.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/algo_test.dir/search/test_search.cpp.o -c /home/zayafa/workspace/Algo/test/search/test_search.cpp

CMakeFiles/algo_test.dir/search/test_search.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algo_test.dir/search/test_search.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zayafa/workspace/Algo/test/search/test_search.cpp > CMakeFiles/algo_test.dir/search/test_search.cpp.i

CMakeFiles/algo_test.dir/search/test_search.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algo_test.dir/search/test_search.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zayafa/workspace/Algo/test/search/test_search.cpp -o CMakeFiles/algo_test.dir/search/test_search.cpp.s

CMakeFiles/algo_test.dir/search/test_search.cpp.o.requires:

.PHONY : CMakeFiles/algo_test.dir/search/test_search.cpp.o.requires

CMakeFiles/algo_test.dir/search/test_search.cpp.o.provides: CMakeFiles/algo_test.dir/search/test_search.cpp.o.requires
	$(MAKE) -f CMakeFiles/algo_test.dir/build.make CMakeFiles/algo_test.dir/search/test_search.cpp.o.provides.build
.PHONY : CMakeFiles/algo_test.dir/search/test_search.cpp.o.provides

CMakeFiles/algo_test.dir/search/test_search.cpp.o.provides.build: CMakeFiles/algo_test.dir/search/test_search.cpp.o


# Object files for target algo_test
algo_test_OBJECTS = \
"CMakeFiles/algo_test.dir/search/test_search.cpp.o"

# External object files for target algo_test
algo_test_EXTERNAL_OBJECTS =

algo_test: CMakeFiles/algo_test.dir/search/test_search.cpp.o
algo_test: CMakeFiles/algo_test.dir/build.make
algo_test: CMakeFiles/algo_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zayafa/workspace/Algo/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable algo_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/algo_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algo_test.dir/build: algo_test

.PHONY : CMakeFiles/algo_test.dir/build

CMakeFiles/algo_test.dir/requires: CMakeFiles/algo_test.dir/search/test_search.cpp.o.requires

.PHONY : CMakeFiles/algo_test.dir/requires

CMakeFiles/algo_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/algo_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/algo_test.dir/clean

CMakeFiles/algo_test.dir/depend:
	cd /home/zayafa/workspace/Algo/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zayafa/workspace/Algo/test /home/zayafa/workspace/Algo/test /home/zayafa/workspace/Algo/test /home/zayafa/workspace/Algo/test /home/zayafa/workspace/Algo/test/CMakeFiles/algo_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/algo_test.dir/depend
