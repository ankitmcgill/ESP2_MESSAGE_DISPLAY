///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//INTERNAL - MDNS
//
//RODA AWANA SDN BHD
//NOVEMBER 11 2019
///////////////////////////////////////////////////////////////

#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "internal_mdns.h"
#include "global.h"

//Internal Variables

//Internal Functions

void INTERNAL_MDNS_Init(void)
{
    //Initialize INTERNAL MDNS

    ESP_LOGD(INTERNAL_MDNS_TAG, "%s OK", __FUNCTION__);
}