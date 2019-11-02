######################################################
# ELTS - ESP32 LASER TAG SYSTEM
# 
# Script To Flash ESP32 Firmware
# 
# RODA AWANA SDN BHD
# OCTOBER 25 2019
######################################################

#!/bin/bash

echo "Erasing flashing ..."
idf.py erase_flash
