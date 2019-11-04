# Minimum CMakeList File For ESP32 Component

idf_component_register(SRCS 
                            "external_lcd.c" 
                        INCLUDE_DIRS 
                            "include"
                        PRIV_REQUIRES
                            main
                            driver
                            global
                            bsp
                        ) 

