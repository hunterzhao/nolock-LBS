# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /mnt/hgfs/workstation/nolock-LBS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/workstation/nolock-LBS/build

# Include any dependencies generated for this target.
include src/CMakeFiles/lbs_so.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/lbs_so.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/lbs_so.dir/flags.make

src/CMakeFiles/lbs_so.dir/databuffer.cc.o: src/CMakeFiles/lbs_so.dir/flags.make
src/CMakeFiles/lbs_so.dir/databuffer.cc.o: ../src/databuffer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/workstation/nolock-LBS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/lbs_so.dir/databuffer.cc.o"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lbs_so.dir/databuffer.cc.o -c /mnt/hgfs/workstation/nolock-LBS/src/databuffer.cc

src/CMakeFiles/lbs_so.dir/databuffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lbs_so.dir/databuffer.cc.i"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/workstation/nolock-LBS/src/databuffer.cc > CMakeFiles/lbs_so.dir/databuffer.cc.i

src/CMakeFiles/lbs_so.dir/databuffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lbs_so.dir/databuffer.cc.s"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/workstation/nolock-LBS/src/databuffer.cc -o CMakeFiles/lbs_so.dir/databuffer.cc.s

src/CMakeFiles/lbs_so.dir/databuffer.cc.o.requires:

.PHONY : src/CMakeFiles/lbs_so.dir/databuffer.cc.o.requires

src/CMakeFiles/lbs_so.dir/databuffer.cc.o.provides: src/CMakeFiles/lbs_so.dir/databuffer.cc.o.requires
	$(MAKE) -f src/CMakeFiles/lbs_so.dir/build.make src/CMakeFiles/lbs_so.dir/databuffer.cc.o.provides.build
.PHONY : src/CMakeFiles/lbs_so.dir/databuffer.cc.o.provides

src/CMakeFiles/lbs_so.dir/databuffer.cc.o.provides.build: src/CMakeFiles/lbs_so.dir/databuffer.cc.o


src/CMakeFiles/lbs_so.dir/event_poll.cc.o: src/CMakeFiles/lbs_so.dir/flags.make
src/CMakeFiles/lbs_so.dir/event_poll.cc.o: ../src/event_poll.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/workstation/nolock-LBS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/lbs_so.dir/event_poll.cc.o"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lbs_so.dir/event_poll.cc.o -c /mnt/hgfs/workstation/nolock-LBS/src/event_poll.cc

src/CMakeFiles/lbs_so.dir/event_poll.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lbs_so.dir/event_poll.cc.i"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/workstation/nolock-LBS/src/event_poll.cc > CMakeFiles/lbs_so.dir/event_poll.cc.i

src/CMakeFiles/lbs_so.dir/event_poll.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lbs_so.dir/event_poll.cc.s"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/workstation/nolock-LBS/src/event_poll.cc -o CMakeFiles/lbs_so.dir/event_poll.cc.s

src/CMakeFiles/lbs_so.dir/event_poll.cc.o.requires:

.PHONY : src/CMakeFiles/lbs_so.dir/event_poll.cc.o.requires

src/CMakeFiles/lbs_so.dir/event_poll.cc.o.provides: src/CMakeFiles/lbs_so.dir/event_poll.cc.o.requires
	$(MAKE) -f src/CMakeFiles/lbs_so.dir/build.make src/CMakeFiles/lbs_so.dir/event_poll.cc.o.provides.build
.PHONY : src/CMakeFiles/lbs_so.dir/event_poll.cc.o.provides

src/CMakeFiles/lbs_so.dir/event_poll.cc.o.provides.build: src/CMakeFiles/lbs_so.dir/event_poll.cc.o


src/CMakeFiles/lbs_so.dir/lbs_server.cc.o: src/CMakeFiles/lbs_so.dir/flags.make
src/CMakeFiles/lbs_so.dir/lbs_server.cc.o: ../src/lbs_server.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/workstation/nolock-LBS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/lbs_so.dir/lbs_server.cc.o"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lbs_so.dir/lbs_server.cc.o -c /mnt/hgfs/workstation/nolock-LBS/src/lbs_server.cc

src/CMakeFiles/lbs_so.dir/lbs_server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lbs_so.dir/lbs_server.cc.i"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/workstation/nolock-LBS/src/lbs_server.cc > CMakeFiles/lbs_so.dir/lbs_server.cc.i

src/CMakeFiles/lbs_so.dir/lbs_server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lbs_so.dir/lbs_server.cc.s"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/workstation/nolock-LBS/src/lbs_server.cc -o CMakeFiles/lbs_so.dir/lbs_server.cc.s

src/CMakeFiles/lbs_so.dir/lbs_server.cc.o.requires:

.PHONY : src/CMakeFiles/lbs_so.dir/lbs_server.cc.o.requires

src/CMakeFiles/lbs_so.dir/lbs_server.cc.o.provides: src/CMakeFiles/lbs_so.dir/lbs_server.cc.o.requires
	$(MAKE) -f src/CMakeFiles/lbs_so.dir/build.make src/CMakeFiles/lbs_so.dir/lbs_server.cc.o.provides.build
.PHONY : src/CMakeFiles/lbs_so.dir/lbs_server.cc.o.provides

src/CMakeFiles/lbs_so.dir/lbs_server.cc.o.provides.build: src/CMakeFiles/lbs_so.dir/lbs_server.cc.o


src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o: src/CMakeFiles/lbs_so.dir/flags.make
src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o: ../src/lbs_socket_event.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/workstation/nolock-LBS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o -c /mnt/hgfs/workstation/nolock-LBS/src/lbs_socket_event.cc

src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lbs_so.dir/lbs_socket_event.cc.i"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/workstation/nolock-LBS/src/lbs_socket_event.cc > CMakeFiles/lbs_so.dir/lbs_socket_event.cc.i

src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lbs_so.dir/lbs_socket_event.cc.s"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/workstation/nolock-LBS/src/lbs_socket_event.cc -o CMakeFiles/lbs_so.dir/lbs_socket_event.cc.s

src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o.requires:

.PHONY : src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o.requires

src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o.provides: src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o.requires
	$(MAKE) -f src/CMakeFiles/lbs_so.dir/build.make src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o.provides.build
.PHONY : src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o.provides

src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o.provides.build: src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o


src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.o: src/CMakeFiles/lbs_so.dir/flags.make
src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.o: ../src/listen_socket_event.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/workstation/nolock-LBS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.o"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lbs_so.dir/listen_socket_event.cc.o -c /mnt/hgfs/workstation/nolock-LBS/src/listen_socket_event.cc

src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lbs_so.dir/listen_socket_event.cc.i"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/workstation/nolock-LBS/src/listen_socket_event.cc > CMakeFiles/lbs_so.dir/listen_socket_event.cc.i

src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lbs_so.dir/listen_socket_event.cc.s"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/workstation/nolock-LBS/src/listen_socket_event.cc -o CMakeFiles/lbs_so.dir/listen_socket_event.cc.s

src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.o.requires:

.PHONY : src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.o.requires

src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.o.provides: src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.o.requires
	$(MAKE) -f src/CMakeFiles/lbs_so.dir/build.make src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.o.provides.build
.PHONY : src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.o.provides

src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.o.provides.build: src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.o


src/CMakeFiles/lbs_so.dir/notify_event.cc.o: src/CMakeFiles/lbs_so.dir/flags.make
src/CMakeFiles/lbs_so.dir/notify_event.cc.o: ../src/notify_event.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/workstation/nolock-LBS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/lbs_so.dir/notify_event.cc.o"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lbs_so.dir/notify_event.cc.o -c /mnt/hgfs/workstation/nolock-LBS/src/notify_event.cc

src/CMakeFiles/lbs_so.dir/notify_event.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lbs_so.dir/notify_event.cc.i"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/workstation/nolock-LBS/src/notify_event.cc > CMakeFiles/lbs_so.dir/notify_event.cc.i

src/CMakeFiles/lbs_so.dir/notify_event.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lbs_so.dir/notify_event.cc.s"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/workstation/nolock-LBS/src/notify_event.cc -o CMakeFiles/lbs_so.dir/notify_event.cc.s

src/CMakeFiles/lbs_so.dir/notify_event.cc.o.requires:

.PHONY : src/CMakeFiles/lbs_so.dir/notify_event.cc.o.requires

src/CMakeFiles/lbs_so.dir/notify_event.cc.o.provides: src/CMakeFiles/lbs_so.dir/notify_event.cc.o.requires
	$(MAKE) -f src/CMakeFiles/lbs_so.dir/build.make src/CMakeFiles/lbs_so.dir/notify_event.cc.o.provides.build
.PHONY : src/CMakeFiles/lbs_so.dir/notify_event.cc.o.provides

src/CMakeFiles/lbs_so.dir/notify_event.cc.o.provides.build: src/CMakeFiles/lbs_so.dir/notify_event.cc.o


src/CMakeFiles/lbs_so.dir/reactor.cc.o: src/CMakeFiles/lbs_so.dir/flags.make
src/CMakeFiles/lbs_so.dir/reactor.cc.o: ../src/reactor.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/workstation/nolock-LBS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/lbs_so.dir/reactor.cc.o"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lbs_so.dir/reactor.cc.o -c /mnt/hgfs/workstation/nolock-LBS/src/reactor.cc

src/CMakeFiles/lbs_so.dir/reactor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lbs_so.dir/reactor.cc.i"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/workstation/nolock-LBS/src/reactor.cc > CMakeFiles/lbs_so.dir/reactor.cc.i

src/CMakeFiles/lbs_so.dir/reactor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lbs_so.dir/reactor.cc.s"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/workstation/nolock-LBS/src/reactor.cc -o CMakeFiles/lbs_so.dir/reactor.cc.s

src/CMakeFiles/lbs_so.dir/reactor.cc.o.requires:

.PHONY : src/CMakeFiles/lbs_so.dir/reactor.cc.o.requires

src/CMakeFiles/lbs_so.dir/reactor.cc.o.provides: src/CMakeFiles/lbs_so.dir/reactor.cc.o.requires
	$(MAKE) -f src/CMakeFiles/lbs_so.dir/build.make src/CMakeFiles/lbs_so.dir/reactor.cc.o.provides.build
.PHONY : src/CMakeFiles/lbs_so.dir/reactor.cc.o.provides

src/CMakeFiles/lbs_so.dir/reactor.cc.o.provides.build: src/CMakeFiles/lbs_so.dir/reactor.cc.o


src/CMakeFiles/lbs_so.dir/socket_event.cc.o: src/CMakeFiles/lbs_so.dir/flags.make
src/CMakeFiles/lbs_so.dir/socket_event.cc.o: ../src/socket_event.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/workstation/nolock-LBS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/lbs_so.dir/socket_event.cc.o"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lbs_so.dir/socket_event.cc.o -c /mnt/hgfs/workstation/nolock-LBS/src/socket_event.cc

src/CMakeFiles/lbs_so.dir/socket_event.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lbs_so.dir/socket_event.cc.i"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/workstation/nolock-LBS/src/socket_event.cc > CMakeFiles/lbs_so.dir/socket_event.cc.i

src/CMakeFiles/lbs_so.dir/socket_event.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lbs_so.dir/socket_event.cc.s"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/workstation/nolock-LBS/src/socket_event.cc -o CMakeFiles/lbs_so.dir/socket_event.cc.s

src/CMakeFiles/lbs_so.dir/socket_event.cc.o.requires:

.PHONY : src/CMakeFiles/lbs_so.dir/socket_event.cc.o.requires

src/CMakeFiles/lbs_so.dir/socket_event.cc.o.provides: src/CMakeFiles/lbs_so.dir/socket_event.cc.o.requires
	$(MAKE) -f src/CMakeFiles/lbs_so.dir/build.make src/CMakeFiles/lbs_so.dir/socket_event.cc.o.provides.build
.PHONY : src/CMakeFiles/lbs_so.dir/socket_event.cc.o.provides

src/CMakeFiles/lbs_so.dir/socket_event.cc.o.provides.build: src/CMakeFiles/lbs_so.dir/socket_event.cc.o


src/CMakeFiles/lbs_so.dir/log.cc.o: src/CMakeFiles/lbs_so.dir/flags.make
src/CMakeFiles/lbs_so.dir/log.cc.o: ../src/log.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/workstation/nolock-LBS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/lbs_so.dir/log.cc.o"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lbs_so.dir/log.cc.o -c /mnt/hgfs/workstation/nolock-LBS/src/log.cc

src/CMakeFiles/lbs_so.dir/log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lbs_so.dir/log.cc.i"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/workstation/nolock-LBS/src/log.cc > CMakeFiles/lbs_so.dir/log.cc.i

src/CMakeFiles/lbs_so.dir/log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lbs_so.dir/log.cc.s"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/workstation/nolock-LBS/src/log.cc -o CMakeFiles/lbs_so.dir/log.cc.s

src/CMakeFiles/lbs_so.dir/log.cc.o.requires:

.PHONY : src/CMakeFiles/lbs_so.dir/log.cc.o.requires

src/CMakeFiles/lbs_so.dir/log.cc.o.provides: src/CMakeFiles/lbs_so.dir/log.cc.o.requires
	$(MAKE) -f src/CMakeFiles/lbs_so.dir/build.make src/CMakeFiles/lbs_so.dir/log.cc.o.provides.build
.PHONY : src/CMakeFiles/lbs_so.dir/log.cc.o.provides

src/CMakeFiles/lbs_so.dir/log.cc.o.provides.build: src/CMakeFiles/lbs_so.dir/log.cc.o


src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o: src/CMakeFiles/lbs_so.dir/flags.make
src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o: ../src/parse_redis_proto.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/workstation/nolock-LBS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o -c /mnt/hgfs/workstation/nolock-LBS/src/parse_redis_proto.cc

src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lbs_so.dir/parse_redis_proto.cc.i"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/workstation/nolock-LBS/src/parse_redis_proto.cc > CMakeFiles/lbs_so.dir/parse_redis_proto.cc.i

src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lbs_so.dir/parse_redis_proto.cc.s"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/workstation/nolock-LBS/src/parse_redis_proto.cc -o CMakeFiles/lbs_so.dir/parse_redis_proto.cc.s

src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o.requires:

.PHONY : src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o.requires

src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o.provides: src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o.requires
	$(MAKE) -f src/CMakeFiles/lbs_so.dir/build.make src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o.provides.build
.PHONY : src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o.provides

src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o.provides.build: src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o


# Object files for target lbs_so
lbs_so_OBJECTS = \
"CMakeFiles/lbs_so.dir/databuffer.cc.o" \
"CMakeFiles/lbs_so.dir/event_poll.cc.o" \
"CMakeFiles/lbs_so.dir/lbs_server.cc.o" \
"CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o" \
"CMakeFiles/lbs_so.dir/listen_socket_event.cc.o" \
"CMakeFiles/lbs_so.dir/notify_event.cc.o" \
"CMakeFiles/lbs_so.dir/reactor.cc.o" \
"CMakeFiles/lbs_so.dir/socket_event.cc.o" \
"CMakeFiles/lbs_so.dir/log.cc.o" \
"CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o"

# External object files for target lbs_so
lbs_so_EXTERNAL_OBJECTS =

src/liblbs.so: src/CMakeFiles/lbs_so.dir/databuffer.cc.o
src/liblbs.so: src/CMakeFiles/lbs_so.dir/event_poll.cc.o
src/liblbs.so: src/CMakeFiles/lbs_so.dir/lbs_server.cc.o
src/liblbs.so: src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o
src/liblbs.so: src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.o
src/liblbs.so: src/CMakeFiles/lbs_so.dir/notify_event.cc.o
src/liblbs.so: src/CMakeFiles/lbs_so.dir/reactor.cc.o
src/liblbs.so: src/CMakeFiles/lbs_so.dir/socket_event.cc.o
src/liblbs.so: src/CMakeFiles/lbs_so.dir/log.cc.o
src/liblbs.so: src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o
src/liblbs.so: src/CMakeFiles/lbs_so.dir/build.make
src/liblbs.so: src/CMakeFiles/lbs_so.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/workstation/nolock-LBS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX shared library liblbs.so"
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lbs_so.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/lbs_so.dir/build: src/liblbs.so

.PHONY : src/CMakeFiles/lbs_so.dir/build

src/CMakeFiles/lbs_so.dir/requires: src/CMakeFiles/lbs_so.dir/databuffer.cc.o.requires
src/CMakeFiles/lbs_so.dir/requires: src/CMakeFiles/lbs_so.dir/event_poll.cc.o.requires
src/CMakeFiles/lbs_so.dir/requires: src/CMakeFiles/lbs_so.dir/lbs_server.cc.o.requires
src/CMakeFiles/lbs_so.dir/requires: src/CMakeFiles/lbs_so.dir/lbs_socket_event.cc.o.requires
src/CMakeFiles/lbs_so.dir/requires: src/CMakeFiles/lbs_so.dir/listen_socket_event.cc.o.requires
src/CMakeFiles/lbs_so.dir/requires: src/CMakeFiles/lbs_so.dir/notify_event.cc.o.requires
src/CMakeFiles/lbs_so.dir/requires: src/CMakeFiles/lbs_so.dir/reactor.cc.o.requires
src/CMakeFiles/lbs_so.dir/requires: src/CMakeFiles/lbs_so.dir/socket_event.cc.o.requires
src/CMakeFiles/lbs_so.dir/requires: src/CMakeFiles/lbs_so.dir/log.cc.o.requires
src/CMakeFiles/lbs_so.dir/requires: src/CMakeFiles/lbs_so.dir/parse_redis_proto.cc.o.requires

.PHONY : src/CMakeFiles/lbs_so.dir/requires

src/CMakeFiles/lbs_so.dir/clean:
	cd /mnt/hgfs/workstation/nolock-LBS/build/src && $(CMAKE_COMMAND) -P CMakeFiles/lbs_so.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/lbs_so.dir/clean

src/CMakeFiles/lbs_so.dir/depend:
	cd /mnt/hgfs/workstation/nolock-LBS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/workstation/nolock-LBS /mnt/hgfs/workstation/nolock-LBS/src /mnt/hgfs/workstation/nolock-LBS/build /mnt/hgfs/workstation/nolock-LBS/build/src /mnt/hgfs/workstation/nolock-LBS/build/src/CMakeFiles/lbs_so.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/lbs_so.dir/depend
