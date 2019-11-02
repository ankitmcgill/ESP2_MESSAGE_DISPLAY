# Minimum CMakeList File For ESP32 Component

idf_component_register(SRCS 
                        "ESP32_UTIL.c" 
                        INCLUDE_DIRS 
                        "include"
                        REQUIRES
                        spi_flash) 

