# Minimum CMakeList File For ESP32 Component

idf_component_register(SRCS 
                            "internal_webserver.c" 
                        INCLUDE_DIRS 
                            "include"
                        PRIV_REQUIRES
                            main
                            esp_http_server
                            global
                            bsp
                        ) 

