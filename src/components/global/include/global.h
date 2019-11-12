///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//GLOBAL
//
//CONTAINTS DEFINITIONS & DECLARATIONS OF GLOBAL (EXTERN)
//VARIABLES FOR THE MODULE LAYER IN ONE PLACE FOR SANITY
//

//NOVEMBER 2 2019
///////////////////////////////////////////////////////////////

#ifndef _GLOBAL_
#define _GLOBAL_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "freertos/event_groups.h"

//Task Priorities
#define TASK_PRIORITY_INTERNAL_WIFI             (7)
#define TASK_PRIORITY_EXTERNAL_LED              (7)

//General
extern EventGroupHandle_t CONNECTION_STATUS_EVENTGROUP_HANDLE;
extern uint8_t CONNECTION_STATUS_EVENTGROUP_BIT_WIFI_CONNECTED;
extern uint8_t CONNECTION_STATUS_EVENTGROUP_BIT_WIFI_DISCONNECTED;

//Module Wifi

//Module TCPIP

//Module Registration

//Module Ota

//Game Logic

#endif