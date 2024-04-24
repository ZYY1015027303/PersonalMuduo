# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/yy/muduoFile

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yy/muduoFile

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/yy/muduoFile/CMakeFiles /home/yy/muduoFile//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/yy/muduoFile/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named mymuduo

# Build rule for target.
mymuduo: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mymuduo
.PHONY : mymuduo

# fast build rule for target.
mymuduo/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/build
.PHONY : mymuduo/fast

# target to build an object file
Channel.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/Channel.o
.PHONY : Channel.o

# target to preprocess a source file
Channel.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/Channel.i
.PHONY : Channel.i

# target to generate assembly for a file
Channel.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/Channel.s
.PHONY : Channel.s

# target to build an object file
DefaultPoller.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/DefaultPoller.o
.PHONY : DefaultPoller.o

# target to preprocess a source file
DefaultPoller.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/DefaultPoller.i
.PHONY : DefaultPoller.i

# target to generate assembly for a file
DefaultPoller.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/DefaultPoller.s
.PHONY : DefaultPoller.s

# target to build an object file
EPollPoller.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/EPollPoller.o
.PHONY : EPollPoller.o

# target to preprocess a source file
EPollPoller.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/EPollPoller.i
.PHONY : EPollPoller.i

# target to generate assembly for a file
EPollPoller.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/EPollPoller.s
.PHONY : EPollPoller.s

# target to build an object file
EventLoop.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/EventLoop.o
.PHONY : EventLoop.o

# target to preprocess a source file
EventLoop.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/EventLoop.i
.PHONY : EventLoop.i

# target to generate assembly for a file
EventLoop.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/EventLoop.s
.PHONY : EventLoop.s

# target to build an object file
InetAddress.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/InetAddress.o
.PHONY : InetAddress.o

# target to preprocess a source file
InetAddress.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/InetAddress.i
.PHONY : InetAddress.i

# target to generate assembly for a file
InetAddress.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/InetAddress.s
.PHONY : InetAddress.s

# target to build an object file
Poller.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/Poller.o
.PHONY : Poller.o

# target to preprocess a source file
Poller.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/Poller.i
.PHONY : Poller.i

# target to generate assembly for a file
Poller.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/Poller.s
.PHONY : Poller.s

# target to build an object file
TcpServer.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/TcpServer.o
.PHONY : TcpServer.o

# target to preprocess a source file
TcpServer.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/TcpServer.i
.PHONY : TcpServer.i

# target to generate assembly for a file
TcpServer.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/TcpServer.s
.PHONY : TcpServer.s

# target to build an object file
Timestamp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/Timestamp.o
.PHONY : Timestamp.o

# target to preprocess a source file
Timestamp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/Timestamp.i
.PHONY : Timestamp.i

# target to generate assembly for a file
Timestamp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/Timestamp.s
.PHONY : Timestamp.s

# target to build an object file
logger.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/logger.o
.PHONY : logger.o

# target to preprocess a source file
logger.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/logger.i
.PHONY : logger.i

# target to generate assembly for a file
logger.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mymuduo.dir/build.make CMakeFiles/mymuduo.dir/logger.s
.PHONY : logger.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... mymuduo"
	@echo "... Channel.o"
	@echo "... Channel.i"
	@echo "... Channel.s"
	@echo "... DefaultPoller.o"
	@echo "... DefaultPoller.i"
	@echo "... DefaultPoller.s"
	@echo "... EPollPoller.o"
	@echo "... EPollPoller.i"
	@echo "... EPollPoller.s"
	@echo "... EventLoop.o"
	@echo "... EventLoop.i"
	@echo "... EventLoop.s"
	@echo "... InetAddress.o"
	@echo "... InetAddress.i"
	@echo "... InetAddress.s"
	@echo "... Poller.o"
	@echo "... Poller.i"
	@echo "... Poller.s"
	@echo "... TcpServer.o"
	@echo "... TcpServer.i"
	@echo "... TcpServer.s"
	@echo "... Timestamp.o"
	@echo "... Timestamp.i"
	@echo "... Timestamp.s"
	@echo "... logger.o"
	@echo "... logger.i"
	@echo "... logger.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

