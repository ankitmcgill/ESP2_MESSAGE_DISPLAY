///////////////////////////////////////////////////////////////
//ELTS - ESP32 LASER TAG SYSTEM
//
//DRIVER - SPIFFS
//

//OCTOBER 2 2019
///////////////////////////////////////////////////////////////

#ifndef _DRIVER_SPIFFS_
#define _DRIVER_SPIFFS_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define DRIVER_SPIFFS_TAG       "I:SPIFFS"

void INTERNAL_SPIFFS_Init(void);

bool INTERNAL_SPIFFS_CheckFileExists(char* filename);
FILE* INTERNAL_SPIFFS_FileOpen(char* filename);
bool INTERNAL_SPIFFS_FileGetNextByte(FILE* handle, char* byte);
void INTERNAL_SPIFFS_FileClose(FILE* handle);

#endif