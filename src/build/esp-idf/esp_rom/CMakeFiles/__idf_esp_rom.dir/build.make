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
CMAKE_SOURCE_DIR = /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build

# Include any dependencies generated for this target.
include esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/depend.make

# Include the progress variables for this target.
include esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/flags.make

esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj: esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/flags.make
esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj: /media/ankit/mydev/toolchains/esp32/esp-idf/components/esp_rom/esp_rom.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/esp-idf/esp_rom && /media/ankit/mydev/toolchains/esp32/idf-tools/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj   -c /media/ankit/mydev/toolchains/esp32/esp-idf/components/esp_rom/esp_rom.c

esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_esp_rom.dir/esp_rom.c.i"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/esp-idf/esp_rom && /media/ankit/mydev/toolchains/esp32/idf-tools/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/ankit/mydev/toolchains/esp32/esp-idf/components/esp_rom/esp_rom.c > CMakeFiles/__idf_esp_rom.dir/esp_rom.c.i

esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_esp_rom.dir/esp_rom.c.s"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/esp-idf/esp_rom && /media/ankit/mydev/toolchains/esp32/idf-tools/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/ankit/mydev/toolchains/esp32/esp-idf/components/esp_rom/esp_rom.c -o CMakeFiles/__idf_esp_rom.dir/esp_rom.c.s

esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj.requires:

.PHONY : esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj.requires

esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj.provides: esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj.requires
	$(MAKE) -f esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/build.make esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj.provides.build
.PHONY : esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj.provides

esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj.provides.build: esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj


# Object files for target __idf_esp_rom
__idf_esp_rom_OBJECTS = \
"CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj"

# External object files for target __idf_esp_rom
__idf_esp_rom_EXTERNAL_OBJECTS =

esp-idf/esp_rom/libesp_rom.a: esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj
esp-idf/esp_rom/libesp_rom.a: esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/build.make
esp-idf/esp_rom/libesp_rom.a: esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libesp_rom.a"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/esp-idf/esp_rom && $(CMAKE_COMMAND) -P CMakeFiles/__idf_esp_rom.dir/cmake_clean_target.cmake
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/esp-idf/esp_rom && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_esp_rom.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/build: esp-idf/esp_rom/libesp_rom.a

.PHONY : esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/build

esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/requires: esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/esp_rom.c.obj.requires

.PHONY : esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/requires

esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/clean:
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/esp-idf/esp_rom && $(CMAKE_COMMAND) -P CMakeFiles/__idf_esp_rom.dir/cmake_clean.cmake
.PHONY : esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/clean

esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/depend:
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src /media/ankit/mydev/toolchains/esp32/esp-idf/components/esp_rom /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/esp-idf/esp_rom /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/esp_rom/CMakeFiles/__idf_esp_rom.dir/depend

