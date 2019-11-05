######################################################
# ESP32 MESSAGE DISPLAY
# 
# Script To Compile ESP32 Code With ESP-IDF
# 
# RODA AWANA SDN BHD
# OCTOBER 25 2019
######################################################

#!/bin/bash

echo "Compiling ..."
idf.py reconfigure build
