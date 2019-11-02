//ESP32 UTIL
//ESP32 UTILITY ROUTINES
//
//APRIL 17 2018
//ankit.bhatnagarindia@gmail.com

#ifndef _ESP32_UTIL_
#define _ESP32_UTIL_

#include <stdio.h>
#include <stdbool.h>

#define ESP32_UTIL_TAG          "ESP32:UTIL"

void ESP32_UTIL_PrintChipInfo(void);

void ESP32_UTIL_DelayBlockingMs(uint32_t ms);

#endif
