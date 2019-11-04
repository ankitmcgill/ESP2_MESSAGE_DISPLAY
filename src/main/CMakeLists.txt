# Edit following two lines to set component requirements (see docs)

idf_component_register(SRCS 
                            "main.c" 
                        INCLUDE_DIRS 
                            "."
                        REQUIRES
                            internal_flash
                            internal_wifi
                            external_led
                            external_lcd
                            external_button
                            ESP32_UTIL
                        ) 
