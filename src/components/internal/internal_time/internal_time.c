///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//INTERNAL - TIME
//

//NOVEMBER 17 2019
///////////////////////////////////////////////////////////////

#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_sntp.h"
#include "sys/param.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "internal_time.h"

//Internal Variables
static void s_internal_time_initialize_sntp(void);
static void s_internal_time_sync_time(void);
static void s_internal_time_timesync_cb(struct timeval *tv);

//Internal Functions

void INTERNAL_TIME_Init(void)
{
    //Initialize INTERNAL TIME

    time_t now;
    char buffer[50] = {0};
    struct tm timeinfo;

    //Check If Time Synced
    time(&now);
    localtime_r(&now, &timeinfo);

    if(timeinfo.tm_year < (2017 - 1900))
    {
        //Time Not Sync
        ESP_LOGD(INTERNAL_TIME_TAG, "Time is not set yet. setting through NTP");
        s_internal_time_sync_time();
    }

    //Set India Timezone
    //Print IST Time
    time(&now);
    setenv("TZ", "GMT+5:30", 1);
    tzset();
    localtime_r(&now, &timeinfo);

    strftime(buffer, sizeof(buffer), "%c", &timeinfo);
    ESP_LOGI(INTERNAL_TIME_TAG, "The current time is: %s", buffer);
}

void INTERNAL_TIME_GetCurrentDayString(char* retval)
{
    //Get Current Day String


}

void INTERNAL_TIME_GetCurrentTimeString(char* retval)
{
    //Get Current Time String

    
}

static void s_internal_time_initialize_sntp(void)
{
    //Initialize SNTP

    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "pool.ntp.org");
    sntp_set_time_sync_notification_cb(s_internal_time_timesync_cb);
    sntp_init();

    ESP_LOGD(INTERNAL_TIME_TAG, "SNTP initialized");
}

static void s_internal_time_sync_time(void)
{
    //Sync Time Using NTP

    time_t now = {0};
    uint8_t retry = 0;
    uint8_t retry_count = 25;
    struct tm timeinfo = {0};

    s_internal_time_initialize_sntp();

    //Wait For Time To Be Synced
    while(sntp_get_sync_status() == SNTP_SYNC_STATUS_RESET && retry < retry_count)
    {
        ESP_LOGD(INTERNAL_TIME_TAG, "waiting for system time to be set... (%u/%u)", 
                                        retry, 
                                        retry_count);
        
        retry += 1;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }

    if(retry == retry_count)
    {
        //Retry Expired. Time Not Synced
        ESP_LOGE(INTERNAL_TIME_TAG, "time sync error");
        return;
    }

    //Time Synced
    time(&now);
    localtime_r(&now, &timeinfo);
    ESP_LOGI(INTERNAL_TIME_TAG, "time synced");
}

static void s_internal_time_timesync_cb(struct timeval *tv)
{
    //SNTP Timesync Cb


}