######################################################
# ESP32 MESSAGE DISPLAY
# 
# Script To Flash ESP32 Firmware
# 
# RODA AWANA SDN BHD
# OCTOBER 25 2019
######################################################

#!/bin/bash

echo "Flashing ..."
idf.py flash monitor
