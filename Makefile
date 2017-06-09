# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.8.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.8.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vic/Dev/Alg/InfomationTheory/MemSteve

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vic/Dev/Alg/InfomationTheory/MemSteve

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.8.0/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/local/Cellar/cmake/3.8.0/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/vic/Dev/Alg/InfomationTheory/MemSteve/CMakeFiles /Users/vic/Dev/Alg/InfomationTheory/MemSteve/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/vic/Dev/Alg/InfomationTheory/MemSteve/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named MemSteve

# Build rule for target.
MemSteve: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 MemSteve
.PHONY : MemSteve

# fast build rule for target.
MemSteve/fast:
	$(MAKE) -f CMakeFiles/MemSteve.dir/build.make CMakeFiles/MemSteve.dir/build
.PHONY : MemSteve/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/MemSteve.dir/build.make CMakeFiles/MemSteve.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/MemSteve.dir/build.make CMakeFiles/MemSteve.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/MemSteve.dir/build.make CMakeFiles/MemSteve.dir/main.cpp.s
.PHONY : main.cpp.s

src/Common.o: src/Common.cpp.o

.PHONY : src/Common.o

# target to build an object file
src/Common.cpp.o:
	$(MAKE) -f CMakeFiles/MemSteve.dir/build.make CMakeFiles/MemSteve.dir/src/Common.cpp.o
.PHONY : src/Common.cpp.o

src/Common.i: src/Common.cpp.i

.PHONY : src/Common.i

# target to preprocess a source file
src/Common.cpp.i:
	$(MAKE) -f CMakeFiles/MemSteve.dir/build.make CMakeFiles/MemSteve.dir/src/Common.cpp.i
.PHONY : src/Common.cpp.i

src/Common.s: src/Common.cpp.s

.PHONY : src/Common.s

# target to generate assembly for a file
src/Common.cpp.s:
	$(MAKE) -f CMakeFiles/MemSteve.dir/build.make CMakeFiles/MemSteve.dir/src/Common.cpp.s
.PHONY : src/Common.cpp.s

src/Counter.o: src/Counter.cpp.o

.PHONY : src/Counter.o

# target to build an object file
src/Counter.cpp.o:
	$(MAKE) -f CMakeFiles/MemSteve.dir/build.make CMakeFiles/MemSteve.dir/src/Counter.cpp.o
.PHONY : src/Counter.cpp.o

src/Counter.i: src/Counter.cpp.i

.PHONY : src/Counter.i

# target to preprocess a source file
src/Counter.cpp.i:
	$(MAKE) -f CMakeFiles/MemSteve.dir/build.make CMakeFiles/MemSteve.dir/src/Counter.cpp.i
.PHONY : src/Counter.cpp.i

src/Counter.s: src/Counter.cpp.s

.PHONY : src/Counter.s

# target to generate assembly for a file
src/Counter.cpp.s:
	$(MAKE) -f CMakeFiles/MemSteve.dir/build.make CMakeFiles/MemSteve.dir/src/Counter.cpp.s
.PHONY : src/Counter.cpp.s

src/Encoding.o: src/Encoding.cpp.o

.PHONY : src/Encoding.o

# target to build an object file
src/Encoding.cpp.o:
	$(MAKE) -f CMakeFiles/MemSteve.dir/build.make CMakeFiles/MemSteve.dir/src/Encoding.cpp.o
.PHONY : src/Encoding.cpp.o

src/Encoding.i: src/Encoding.cpp.i

.PHONY : src/Encoding.i

# target to preprocess a source file
src/Encoding.cpp.i:
	$(MAKE) -f CMakeFiles/MemSteve.dir/build.make CMakeFiles/MemSteve.dir/src/Encoding.cpp.i
.PHONY : src/Encoding.cpp.i

src/Encoding.s: src/Encoding.cpp.s

.PHONY : src/Encoding.s

# target to generate assembly for a file
src/Encoding.cpp.s:
	$(MAKE) -f CMakeFiles/MemSteve.dir/build.make CMakeFiles/MemSteve.dir/src/Encoding.cpp.s
.PHONY : src/Encoding.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... MemSteve"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/Common.o"
	@echo "... src/Common.i"
	@echo "... src/Common.s"
	@echo "... src/Counter.o"
	@echo "... src/Counter.i"
	@echo "... src/Counter.s"
	@echo "... src/Encoding.o"
	@echo "... src/Encoding.i"
	@echo "... src/Encoding.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

