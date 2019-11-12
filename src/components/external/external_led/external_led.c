///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//INTERNAL - LED
//LED CONTROL BASED ON ESP32 LEDC PERIPHERAL
//

//NOVEMBER 3 2019
///////////////////////////////////////////////////////////////

#include "esp_system.h"
#include "driver/ledc.h"
#include "esp_event.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "external_led.h"
#include "global.h"
#include "bsp.h"

#define LED_CHANNEL_RED         (LEDC_CHANNEL_0)
#define LED_CHANNEL_GREEN       (LEDC_CHANNEL_1)
#define LED_CHANNEL_BLUE        (LEDC_CHANNEL_2)

//Internal Variables
static TaskHandle_t s_task_handle;
static uint8_t s_external_led_effect_color_r;
static uint8_t s_external_led_effect_color_g;
static uint8_t s_external_led_effect_color_b;

//Internal Functions
static void s_external_led_task(void* pvParameter);

void EXTERNAL_LED_Init(void)
{
    //Initialize EXTERNAL LED

    //Setup Ledc High Speed Timer
    ledc_timer_config_t timer_config = {
                                            .duty_resolution = LEDC_TIMER_8_BIT,
                                            .freq_hz = 5000,
                                            .speed_mode = LEDC_HIGH_SPEED_MODE,
                                            .timer_num = LEDC_TIMER_0,
                                            .clk_cfg = LEDC_AUTO_CLK
                                        };
    ESP_ERROR_CHECK(ledc_timer_config(&timer_config));

    //Setup Ledc Channels
    ledc_channel_config_t channel_config_1 = {
                                                .channel = LEDC_CHANNEL_0,
                                                .duty = 0,
                                                .gpio_num = BSP_LED_RED,
                                                .speed_mode = LEDC_HIGH_SPEED_MODE,
                                                .hpoint = 0,
                                                .timer_sel = LEDC_TIMER_0
                                            };
    ledc_channel_config_t channel_config_2 = {
                                                .channel = LEDC_CHANNEL_1,
                                                .duty = 0,
                                                .gpio_num = BSP_LED_GREEN,
                                                .speed_mode = LEDC_HIGH_SPEED_MODE,
                                                .hpoint = 0,
                                                .timer_sel = LEDC_TIMER_0
                                            };
    ledc_channel_config_t channel_config_3 = {
                                                .channel = LEDC_CHANNEL_2,
                                                .duty = 0,
                                                .gpio_num = BSP_LED_BLUE,
                                                .speed_mode = LEDC_HIGH_SPEED_MODE,
                                                .hpoint = 0,
                                                .timer_sel = LEDC_TIMER_0
                                            };
    ESP_ERROR_CHECK(ledc_channel_config(&channel_config_1));
    ESP_ERROR_CHECK(ledc_channel_config(&channel_config_2));
    ESP_ERROR_CHECK(ledc_channel_config(&channel_config_3));

    //Initialize Fade Service
    ledc_fade_func_install(0);

    s_task_handle = NULL;

    ESP_LOGD(EXTERNAL_LED_TAG, "%s OK", __FUNCTION__);
}

void EXTERNAL_LED_ShowNotification(uint8_t r, uint8_t g, uint8_t b)
{
    //Run Fade In Out Notification With Specified Color

    //Cancell Already Running Effect
    if(s_task_handle != NULL)
    {
        EXTERNAL_LED_StopNotification();
    }

    s_external_led_effect_color_r = r;
    s_external_led_effect_color_g = g;
    s_external_led_effect_color_b = b;

    //Start Effect Task
    xTaskCreate(&s_external_led_task, 
                    "manager_led", 
                    2048, 
                    NULL, 
                    TASK_PRIORITY_EXTERNAL_LED, 
                    &s_task_handle);
}

void EXTERNAL_LED_StopNotification(void)
{
    //Stop Notification

    vTaskDelete(s_task_handle);
    s_task_handle = NULL;
}

static void s_external_led_task(void* pvParameter)
{
    //External LED Task

    ESP_LOGD(EXTERNAL_LED_TAG, "starting led effect");

    ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, 0);
    ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_1, 0);
    ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_2, 0);

    while(true)
    {
        ledc_set_fade_with_time(LEDC_HIGH_SPEED_MODE, 
                                LEDC_CHANNEL_0,
                                s_external_led_effect_color_r,
                                1000);
        ledc_set_fade_with_time(LEDC_HIGH_SPEED_MODE, 
                                LEDC_CHANNEL_1,
                                s_external_led_effect_color_g,
                                1000);
        ledc_set_fade_with_time(LEDC_HIGH_SPEED_MODE, 
                                LEDC_CHANNEL_2,
                                s_external_led_effect_color_b,
                                1000);

        //Ledc Module Does Not Provide A Status Function To Check When The Fade Is Done
        //So We Use Non Blocking Fade And Do A Delay For 1020ms As We Know Fade Will
        //Finish In 1000ms + 20ms Buffer        
        ledc_fade_start(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, LEDC_FADE_NO_WAIT);
        ledc_fade_start(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_1, LEDC_FADE_NO_WAIT);
        ledc_fade_start(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_2, LEDC_FADE_NO_WAIT);

        vTaskDelay(1020 / portTICK_PERIOD_MS);

        ledc_set_fade_with_time(LEDC_HIGH_SPEED_MODE, 
                                LEDC_CHANNEL_0,
                                0,
                                1000);
        ledc_set_fade_with_time(LEDC_HIGH_SPEED_MODE, 
                                LEDC_CHANNEL_1,
                                0,
                                1000);
        ledc_set_fade_with_time(LEDC_HIGH_SPEED_MODE, 
                                LEDC_CHANNEL_2,
                                0,
                                1000);

        ledc_fade_start(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, LEDC_FADE_NO_WAIT);
        ledc_fade_start(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_1, LEDC_FADE_NO_WAIT);
        ledc_fade_start(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_2, LEDC_FADE_NO_WAIT);

        //Ledc Module Does Not Provide A Status Function To Check When The Fade Is Done
        //So We Use Non Blocking Fade And Do A Delay For 1020ms As We Know Fade Will
        //Finish In 1000ms + 20ms Buffer
        vTaskDelay(1020 / portTICK_PERIOD_MS);
    }

    vTaskDelete(NULL);
}