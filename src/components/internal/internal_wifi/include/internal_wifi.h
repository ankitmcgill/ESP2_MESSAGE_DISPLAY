///////////////////////////////////////////////////////////////
//ELTS - ESP32 LASER TAG SYSTEM
//
//INTERNAL - WIFI
//
//RODA AWANA SDN BHD
//SEPTEMBER 14 2019
///////////////////////////////////////////////////////////////

#ifndef _INTERNAL_WIFI_
#define _INTERNAL_WIFI_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define INTERNAL_WIFI_TAG                       "M:WIFI"

#define INTERNAL_WIFI_WIFI_SSID_MAXLEN          (32)
#define INTERNAL_WIFI_WIFI_PWD_MAXLEN           (64)

void INTERNAL_WIFI_Init(void);

bool INTERNAL_WIFI_IsConnected(void);
bool INTERNAL_WIFI_GetSignalRssi(int8_t* retval);

#endif