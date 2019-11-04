///////////////////////////////////////////////////////////////
//ELTS - ESP32 LASER TAG SYSTEM
//
//EXTERNAL - BUTTON
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

#include "external_button.h"
#include "global.h"
#include "bsp.h"

//Internal Variables

//Internal Functions
static void IRAM_ATTR s_external_button_isr(void* arg);

void EXTERNAL_BUTTON_Init(void)
{
    //Initialize EXTERNAL BUTTON

    gpio_config_t config;

    config.pin_bit_mask = (1 << BSP_BUTTON_SCROLL) |
                            (1 << BSP_BUTTON_ACK);
    config.mode = GPIO_MODE_INPUT;
    config.intr_type = GPIO_PIN_INTR_NEGEDGE;
    
    ESP_ERROR_CHECK(gpio_config(&config));

    //Install GPIO ISR Service
    gpio_install_isr_service(0);
    gpio_isr_handler_add(BSP_BUTTON_SCROLL,s_external_button_isr, (void*)BSP_BUTTON_SCROLL);
    gpio_isr_handler_add(BSP_BUTTON_ACK,s_external_button_isr, (void*)BSP_BUTTON_ACK);

    ESP_LOGD(EXTERNAL_BUTTON_TAG, "%s OK", __FUNCTION__);
}

static void IRAM_ATTR s_external_button_isr(void* arg)
{
    //External Button ISR
}