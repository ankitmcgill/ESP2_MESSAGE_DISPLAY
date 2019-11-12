///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//INTERNAL - LED
//LED CONTROL BASED ON ESP32 LEDC PERIPHERAL
//

//NOVEMBER 3 2019
///////////////////////////////////////////////////////////////

#ifndef _EXTERNAL_LED_
#define _EXTERNAL_LED_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define EXTERNAL_LED_TAG                    "E:LED"

void EXTERNAL_LED_Init(void);

void EXTERNAL_LED_ShowNotification(uint8_t r, uint8_t g, uint8_t b);
void EXTERNAL_LED_StopNotification(void);

#endif