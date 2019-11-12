///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//INTERNAL - MDNS
//

//NOVEMBER 11 2019
///////////////////////////////////////////////////////////////

#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "mdns.h"

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

    esp_err_t err;

    err = mdns_init();
    if(err != ESP_OK)
    {
        ESP_LOGE(INTERNAL_MDNS_TAG, "%s FAIL", __FUNCTION__);
        return;
    }

    //Set Hostname
    mdns_hostname_set(INTERNAL_MDNS_HOSTNAME);

    //Advertise Device Services Through MDNS
    mdns_service_add(NULL, "_http", "_tcp", 80, NULL, 0);

    ESP_LOGD(INTERNAL_MDNS_TAG, "%s OK", __FUNCTION__);
}