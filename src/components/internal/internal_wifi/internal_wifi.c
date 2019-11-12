///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//INTERNAL - WIFI
//

//SEPTEMBER 14 2019
///////////////////////////////////////////////////////////////

#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "internal_wifi.h"
#include "default_provisioning.h"
#include "global.h"

//Internal Variables
static bool s_initialized = false;
static volatile bool s_internal_wifi_connected;

//Internal Functions
static void s_internal_wifi_task(void* pvParameter);
static void s_internal_wifi_event_handler(void* arg, esp_event_base_t event_base, 
                                            int32_t event_id, void* event_data);

void INTERNAL_WIFI_Init(void)
{
    //Initialize INTERNAL_WIFI

    if(s_initialized)
    {
        //Already Initialized
        return;
    }

    CONNECTION_STATUS_EVENTGROUP_HANDLE = xEventGroupCreate();
    wifi_init_config_t wifi_init_cfg = WIFI_INIT_CONFIG_DEFAULT();

    //Initialize Wifi
    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    ESP_ERROR_CHECK(esp_wifi_init(&wifi_init_cfg));

    //Register Event Handlers
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, 
                                                ESP_EVENT_ANY_ID, 
                                                &s_internal_wifi_event_handler, 
                                                NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, 
                                                IP_EVENT_STA_GOT_IP, 
                                                &s_internal_wifi_event_handler, 
                                                NULL));

    s_internal_wifi_connected = false;
    s_initialized = true;
    
    //Start Module_Wifi Task
    xTaskCreate(&s_internal_wifi_task, 
                    "task_wifi", 
                    4096, 
                    NULL, 
                    TASK_PRIORITY_INTERNAL_WIFI, 
                    NULL);

    xEventGroupSetBits(CONNECTION_STATUS_EVENTGROUP_HANDLE, 
                        CONNECTION_STATUS_EVENTGROUP_BIT_WIFI_DISCONNECTED);
                        
    ESP_LOGD(INTERNAL_WIFI_TAG, "%s OK", __FUNCTION__);
}

bool INTERNAL_WIFI_IsConnected(void)
{
    //Return Wifi Connected Status

    return s_internal_wifi_connected;
}

bool INTERNAL_WIFI_GetSignalRssi(int8_t* retval)
{
    //Return Wifi Signal Rssi Value
    //Only Works When Connected To AP

    if(!s_internal_wifi_connected)
    {
        return false;
    }

    wifi_ap_record_t data;

    if(esp_wifi_sta_get_ap_info(&data) == 0)
    {
        *retval = data.rssi;
        return true;
    }

    return false;
}

static void s_internal_wifi_task(void* pvParameter)
{
    //INTERNAL_WIFI Task

    //Get Wifi Details From Provisioning
    //Initiate Connection To Wifi
    wifi_config_t wifi_config = {0};
    strcpy((char*)wifi_config.sta.ssid, DEFUALT_WIRELESS_SSID);
    strcpy((char*)wifi_config.sta.password, DEFUALT_WIRELESS_PASSWORD);

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGD(INTERNAL_WIFI_TAG, "connecting to wifi...");

    while(1)
    {
        //Only Run When CONNECTION_STATUS_EVENTGROUP_BIT_WIFI_DISCONNECTED Bit Set

        xEventGroupWaitBits(CONNECTION_STATUS_EVENTGROUP_HANDLE, 
                                CONNECTION_STATUS_EVENTGROUP_BIT_WIFI_DISCONNECTED, 
                                false,  //Dont Clear Bits On Exit
                                false,  //Either Bit Setting Will Do
                                portMAX_DELAY);

        vTaskDelay(1000 / portTICK_RATE_MS);
    }

    vTaskDelete(NULL);
}

static void s_internal_wifi_event_handler(void* arg, esp_event_base_t event_base, 
                                            int32_t event_id, void* event_data)
{
    //WIFI Event Handler

    if(event_base == WIFI_EVENT)
    {
        //WIFI Event

        switch(event_id)
        {
            case WIFI_EVENT_WIFI_READY:
                break;
            
            case WIFI_EVENT_STA_START:
                //Start Task Timer
                s_internal_wifi_connected = false;
                //Connect To Wifi
                ESP_ERROR_CHECK(esp_wifi_connect());
                break;
            
            case WIFI_EVENT_STA_CONNECTED:
                break;

            case WIFI_EVENT_STA_DISCONNECTED:
                xEventGroupSetBits(CONNECTION_STATUS_EVENTGROUP_HANDLE, 
                                    CONNECTION_STATUS_EVENTGROUP_BIT_WIFI_DISCONNECTED);
                xEventGroupClearBits(CONNECTION_STATUS_EVENTGROUP_HANDLE, 
                                        CONNECTION_STATUS_EVENTGROUP_BIT_WIFI_CONNECTED);

                s_internal_wifi_connected = false;
                //Re-Initiate Connections
                ESP_ERROR_CHECK(esp_wifi_connect());
                ESP_LOGD(INTERNAL_WIFI_TAG, "disconnected. reconnecting ...");
                break;

            default:
                break;
        }     
    }
    else if(event_base == IP_EVENT)
    {
        //IP Eevent

        ip_event_got_ip_t*  ip_event;

        switch(event_id)
        {
            case IP_EVENT_STA_GOT_IP:
                xEventGroupSetBits(CONNECTION_STATUS_EVENTGROUP_HANDLE, 
                                    CONNECTION_STATUS_EVENTGROUP_BIT_WIFI_CONNECTED);
                xEventGroupClearBits(CONNECTION_STATUS_EVENTGROUP_HANDLE, 
                                        CONNECTION_STATUS_EVENTGROUP_BIT_WIFI_DISCONNECTED);
                ip_event = (ip_event_got_ip_t*)event_data;
                s_internal_wifi_connected = true;
                ESP_LOGD(INTERNAL_WIFI_TAG, "got ip : %s", ip4addr_ntoa(&ip_event->ip_info.ip));
                break;
            
            default:
                break;
        }
    }
}