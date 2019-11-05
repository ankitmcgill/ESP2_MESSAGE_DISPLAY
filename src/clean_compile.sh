######################################################
# ESP32 MESSAGE DISPLAY
# 
# Script To Clean Compile ESP32 Code With ESP-IDF
# 
# RODA AWANA SDN BHD
# OCTOBER 25 2019
######################################################

#!/bin/bash

echo "Clean Compiling ..."
rm -rf build
idf.py reconfigure build
