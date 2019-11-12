# Minimum CMakeList File For ESP32 Component

idf_component_register(SRCS 
                            "internal_spiffs.c" 
                        INCLUDE_DIRS 
                            "include"
                        REQUIRES
                            driver
                            spiffs
                        ) 

