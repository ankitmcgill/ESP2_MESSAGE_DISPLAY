file(REMOVE_RECURSE
  "config/sdkconfig.h"
  "config/sdkconfig.cmake"
  "bootloader/bootloader.elf"
  "bootloader/bootloader.bin"
  "bootloader/bootloader.map"
  "esp32-message-display.bin"
  "esp32-message-display.map"
  "project_elf_src.c"
  "CMakeFiles/___idf_app_update"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/___idf_app_update.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
