///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//INTERNAL - WEBSERVER
//
//RODA AWANA SDN BHD
//NOVEMBER 4 2019
///////////////////////////////////////////////////////////////

#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_event.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "internal_webserver.h"
#include "global.h"
#include "bsp.h"

//Internal Variables

//Internal Functions

void INTERNAL_WEBSERVER_Init(void)
{
    //Initialize INTERNAL WEBSERVER


    ESP_LOGD(INTERNAL_WEBSERVER_TAG, "%s OK", __FUNCTION__);
}