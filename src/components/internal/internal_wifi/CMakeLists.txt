# Minimum CMakeList File For ESP32 Component

idf_component_register(SRCS 
                            "internal_wifi.c" 
                        INCLUDE_DIRS 
                            "include"
                        PRIV_REQUIRES
                            main
                            global
                        ) 

