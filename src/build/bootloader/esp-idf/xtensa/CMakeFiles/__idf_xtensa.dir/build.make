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
CMAKE_SOURCE_DIR = /media/ankit/mydev/toolchains/esp32/esp-idf/components/bootloader/subproject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader

# Include any dependencies generated for this target.
include esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/depend.make

# Include the progress variables for this target.
include esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/flags.make

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/flags.make
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj: /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/debug_helpers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa && /media/ankit/mydev/toolchains/esp32/idf-tools/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj   -c /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/debug_helpers.c

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_xtensa.dir/debug_helpers.c.i"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa && /media/ankit/mydev/toolchains/esp32/idf-tools/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/debug_helpers.c > CMakeFiles/__idf_xtensa.dir/debug_helpers.c.i

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_xtensa.dir/debug_helpers.c.s"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa && /media/ankit/mydev/toolchains/esp32/idf-tools/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/debug_helpers.c -o CMakeFiles/__idf_xtensa.dir/debug_helpers.c.s

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj.requires:

.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj.requires

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj.provides: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj.requires
	$(MAKE) -f esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build.make esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj.provides.build
.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj.provides

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj.provides.build: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj


esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/flags.make
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj: /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/debug_helpers_asm.S
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building ASM object esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa && /media/ankit/mydev/toolchains/esp32/idf-tools/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj -c /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/debug_helpers_asm.S

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj.requires:

.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj.requires

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj.provides: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj.requires
	$(MAKE) -f esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build.make esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj.provides.build
.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj.provides

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj.provides.build: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj


esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/flags.make
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj: /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/eri.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa && /media/ankit/mydev/toolchains/esp32/idf-tools/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_xtensa.dir/eri.c.obj   -c /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/eri.c

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_xtensa.dir/eri.c.i"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa && /media/ankit/mydev/toolchains/esp32/idf-tools/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/eri.c > CMakeFiles/__idf_xtensa.dir/eri.c.i

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_xtensa.dir/eri.c.s"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa && /media/ankit/mydev/toolchains/esp32/idf-tools/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/eri.c -o CMakeFiles/__idf_xtensa.dir/eri.c.s

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.requires:

.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.requires

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.provides: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.requires
	$(MAKE) -f esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build.make esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.provides.build
.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.provides

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.provides.build: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj


esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.obj: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/flags.make
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.obj: /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/trax.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.obj"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa && /media/ankit/mydev/toolchains/esp32/idf-tools/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_xtensa.dir/trax.c.obj   -c /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/trax.c

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_xtensa.dir/trax.c.i"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa && /media/ankit/mydev/toolchains/esp32/idf-tools/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/trax.c > CMakeFiles/__idf_xtensa.dir/trax.c.i

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_xtensa.dir/trax.c.s"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa && /media/ankit/mydev/toolchains/esp32/idf-tools/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa/trax.c -o CMakeFiles/__idf_xtensa.dir/trax.c.s

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.obj.requires:

.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.obj.requires

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.obj.provides: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.obj.requires
	$(MAKE) -f esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build.make esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.obj.provides.build
.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.obj.provides

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.obj.provides.build: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.obj


# Object files for target __idf_xtensa
__idf_xtensa_OBJECTS = \
"CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj" \
"CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj" \
"CMakeFiles/__idf_xtensa.dir/eri.c.obj" \
"CMakeFiles/__idf_xtensa.dir/trax.c.obj"

# External object files for target __idf_xtensa
__idf_xtensa_EXTERNAL_OBJECTS =

esp-idf/xtensa/libxtensa.a: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj
esp-idf/xtensa/libxtensa.a: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj
esp-idf/xtensa/libxtensa.a: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj
esp-idf/xtensa/libxtensa.a: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.obj
esp-idf/xtensa/libxtensa.a: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build.make
esp-idf/xtensa/libxtensa.a: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library libxtensa.a"
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa && $(CMAKE_COMMAND) -P CMakeFiles/__idf_xtensa.dir/cmake_clean_target.cmake
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_xtensa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build: esp-idf/xtensa/libxtensa.a

.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/requires: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers.c.obj.requires
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/requires: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/debug_helpers_asm.S.obj.requires
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/requires: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.requires
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/requires: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/trax.c.obj.requires

.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/requires

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/clean:
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa && $(CMAKE_COMMAND) -P CMakeFiles/__idf_xtensa.dir/cmake_clean.cmake
.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/clean

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/depend:
	cd /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/ankit/mydev/toolchains/esp32/esp-idf/components/bootloader/subproject /media/ankit/mydev/toolchains/esp32/esp-idf/components/xtensa /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa /home/ankit/Sandbox/ESP32_MESSAGE_DISPLAY/src/build/bootloader/esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/depend

