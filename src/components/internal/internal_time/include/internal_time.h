///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//INTERNAL - TIME
//

//NOVEMBER 17 2019
///////////////////////////////////////////////////////////////

#ifndef _INTERNAL_TIME_
#define _INTERNAL_TIME_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define INTERNAL_TIME_TAG   "I:TIME"

void INTERNAL_TIME_Init(void);

void INTERNAL_TIME_GetCurrentDayString(char* retval);
void INTERNAL_TIME_GetCurrentTimeString(char* retval);

#endif