# Edit following two lines to set component requirements (see docs)

idf_component_register(SRCS 
                            "main.c" 
                        INCLUDE_DIRS 
                            "."
                        REQUIRES
                            internal_flash
                            internal_wifi
                            internal_webserver
                            internal_spiffs
                            external_led
                            external_lcd
                            internal_spiffs
                            external_button
                            internal_time
                            ESP32_UTIL
                        ) 

# Build spiff image from the media folder + burn on device as part of Flash process
spiffs_create_partition_image(media ../media FLASH_IN_PROJECT)