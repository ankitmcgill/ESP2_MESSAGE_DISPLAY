///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//INTERNAL - MDNS
//

//NOVEMBER 11 2019
///////////////////////////////////////////////////////////////

#ifndef _INTERNAL_MDNS_
#define _INTERNAL_MDNS_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define INTERNAL_MDNS_TAG       "I:MDNS"
#define INTERNAL_MDNS_HOSTNAME  "message"

void INTERNAL_MDNS_Init(void);

#endif