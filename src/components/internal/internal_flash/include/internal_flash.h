///////////////////////////////////////////////////////////////
//ELTS - ESP32 LASER TAG SYSTEM
//
//DRIVER - FLASH
//
//RODA AWANA SDN BHD
//SEPTEMBER 13 2019
///////////////////////////////////////////////////////////////

#ifndef _INTERNAL_FLASH_
#define _INTERNAL_FLASH_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define INTERNAL_FLASH_TAG          "D:FLASH"

bool INTERNAL_FLASH_Init(void);

bool INTERNAL_FLASH_DataReadUint32(char* key, void* retval);
bool INTERNAL_FLASH_DataWriteUint32(char* key, void* data);

bool INTERNAL_FLASH_DataReadString(char* key, void* retval, size_t* size);
bool INTERNAL_FLASH_DataWriteString(char* key, void* data);

bool INTERNAL_FLASH_DataReadBlob(char* key, void* retval, size_t* size);
bool INTERNAL_FLASH_DataWriteBlob(char* key, void* data, size_t size);

#endif