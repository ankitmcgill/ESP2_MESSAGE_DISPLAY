# Minimum CMakeList File For ESP32 Component

idf_component_register(SRCS 
                            "internal_flash.c" 
                        INCLUDE_DIRS 
                            "include"
                        REQUIRES
                            driver
                            nvs_flash
                        ) 

