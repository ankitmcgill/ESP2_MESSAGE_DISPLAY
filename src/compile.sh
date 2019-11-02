######################################################
# ELTS - ESP32 LASER TAG SYSTEM
# 
# Script To Compile ESP32 Code With ESP-IDF
# 
# RODA AWANA SDN BHD
# OCTOBER 25 2019
######################################################

#!/bin/bash

echo "Compiling ..."
idf.py reconfigure build
