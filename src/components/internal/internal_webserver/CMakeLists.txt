# Minimum CMakeList File For ESP32 Component

idf_component_register(SRCS 
                            "internal_webserver.c" 
                        INCLUDE_DIRS 
                            "include"
                        PRIV_REQUIRES
                            main
                            internal_mdns
                            internal_spiffs
                            esp_http_server
                            global
                        ) 

