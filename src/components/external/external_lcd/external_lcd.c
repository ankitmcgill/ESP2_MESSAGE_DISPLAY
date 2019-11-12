///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//EXTERNAL - LCD
//LED CONTROL BASED ON ESP32 LEDC PERIPHERAL
//

//NOVEMBER 3 2019
///////////////////////////////////////////////////////////////

#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_event.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "external_lcd.h"
#include "global.h"
#include "bsp.h"

//Internal Variables

//Internal Functions
static void s_external_led_initialize_hardware(void);
static void s_external_lcd_send_command(uint8_t command);
static void s_external_lcd_send_data(uint8_t data);
static void s_external_lcd_set_data_lines(uint8_t data);

void EXTERNAL_LCD_Init(void)
{
    //Initialize EXTERNAL LCD

    gpio_config_t config;

    config.pin_bit_mask = (1 << BSP_LCD_RS) |
                            (1 << BSP_LCD_EN) |
                            (1 << BSP_LCD_D0) |
                            (1 << BSP_LCD_D1) |
                            (1 << BSP_LCD_D2) |
                            (1 << BSP_LCD_D3) |
                            (1 << BSP_LCD_D4) |
                            (1 << BSP_LCD_D5) |
                            (1 << BSP_LCD_D6) |
                            (1 << BSP_LCD_D7);
    config.mode = GPIO_MODE_OUTPUT;
    config.intr_type = GPIO_INTR_DISABLE;
    ESP_ERROR_CHECK(gpio_config(&config));

    //Initialize Hardware
    s_external_led_initialize_hardware();

    ESP_LOGD(EXTERNAL_LCD_TAG, "%s OK", __FUNCTION__);
}

void EXTERNAL_LCD_Clear(void)
{
    //Clear Lcd

    s_external_lcd_send_command(EXTERNAL_LCD_COMMAND_DISPLAY_ON_NO_CURSOR);
    s_external_lcd_send_command(EXTERNAL_LCD_COMMAND_CLEAR_DISPLAY);
    s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_1);
}

void EXTERNAL_LCD_PutStringLeftInLine(char* str, uint8_t line_num)
{
    //Display String Left Justified In Specified Line

    if(strlen(str) > EXTERNAL_LCD_WIDTH_LINE)
    {
        //Too Big To Fit

        return;
    }

    switch(line_num)
    {
        case 1:
            s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_1);
            break;

        case 2:
            s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_2);
            break;

        case 3:
            s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_3);
            break;

        case 4:
            s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_4);
            break;

        default:
            return;
    }

    for(uint8_t i = 0; i < strlen(str); i++)
    {
        s_external_lcd_send_data(str[i]);
    }
}

void EXTERNAL_LCD_PutStringRightInLine(char* str, uint8_t line_num)
{
    //Display String Right Justified In Specified Line

    if(strlen(str) > EXTERNAL_LCD_WIDTH_LINE)
    {
        //Too Big To Fit

        return;
    }

    switch(line_num)
    {
        case 1:
            s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_1);
            break;

        case 2:
            s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_2);
            break;

        case 3:
            s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_3);
            break;

        case 4:
            s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_4);
            break;

        default:
            return;
    }

    for(uint8_t i = 0; i < EXTERNAL_LCD_WIDTH_LINE - strlen(str); i++)
    {
        s_external_lcd_send_data(' ');
    }

    for(uint8_t i = 0; i < strlen(str); i++)
    {
        s_external_lcd_send_data(str[i]);
    }
}

void EXTERNAL_LCD_PutStringCenteredInLine(char* str, uint8_t line_num)
{
    //Display String Center Justified In Specified Line

    uint8_t string_len = strlen(str);
    uint8_t padding_left;

    if(string_len > EXTERNAL_LCD_WIDTH_LINE)
    {
        //Too Big To Fit

        return;
    }

    switch(line_num)
    {
        case 1:
            s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_1);
            break;

        case 2:
            s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_2);
            break;

        case 3:
            s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_3);
            break;

        case 4:
            s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_4);
            break;

        default:
            return;
    }

    padding_left = (EXTERNAL_LCD_WIDTH_LINE - string_len ) / 2;

    for(uint8_t i = 0; i < padding_left; i++)
    {
        s_external_lcd_send_data(' ');
    }

    for(uint8_t i = 0; i < string_len; i++)
    {
        s_external_lcd_send_data(str[i]);
    }
}
static void s_external_led_initialize_hardware(void)
{
    //Initialize External LCD Hardware

    s_external_lcd_send_command(0x38); // Enable 5x7 Mode For Chars 
    s_external_lcd_send_command(EXTERNAL_LCD_COMMAND_DISPLAY_ON_NO_CURSOR);
    s_external_lcd_send_command(EXTERNAL_LCD_COMMAND_CLEAR_DISPLAY);
    s_external_lcd_send_command(EXTERNAL_LCD_ADDRESS_LINE_1); 
}

static void s_external_lcd_send_command(uint8_t command)
{
    //Send Lcd Command

    s_external_lcd_set_data_lines(command);
    gpio_set_level(BSP_LCD_RS, 0);
    gpio_set_level(BSP_LCD_EN, 1);
    vTaskDelay(10 / portTICK_PERIOD_MS);
    gpio_set_level(BSP_LCD_EN, 0);
    vTaskDelay(10 / portTICK_PERIOD_MS);
}

static void s_external_lcd_send_data(uint8_t data)
{
    //Send Lcd Data

    s_external_lcd_set_data_lines(data);
    gpio_set_level(BSP_LCD_RS, 1);
    gpio_set_level(BSP_LCD_EN, 1);
    vTaskDelay(10 / portTICK_PERIOD_MS);
    gpio_set_level(BSP_LCD_EN, 0);
    vTaskDelay(10 / portTICK_PERIOD_MS);
}

static void s_external_lcd_set_data_lines(uint8_t data)
{
    //Set Data GPIO Lines As Per Data Bits

    (data & 0x80) ? gpio_set_level(BSP_LCD_D7, 1) : gpio_set_level(BSP_LCD_D7, 0);
    (data & 0x40) ? gpio_set_level(BSP_LCD_D6, 1) : gpio_set_level(BSP_LCD_D6, 0);
    (data & 0x20) ? gpio_set_level(BSP_LCD_D5, 1) : gpio_set_level(BSP_LCD_D5, 0);
    (data & 0x10) ? gpio_set_level(BSP_LCD_D4, 1) : gpio_set_level(BSP_LCD_D4, 0);
    (data & 0x08) ? gpio_set_level(BSP_LCD_D3, 1) : gpio_set_level(BSP_LCD_D3, 0);
    (data & 0x04) ? gpio_set_level(BSP_LCD_D2, 1) : gpio_set_level(BSP_LCD_D2, 0);
    (data & 0x02) ? gpio_set_level(BSP_LCD_D1, 1) : gpio_set_level(BSP_LCD_D1, 0);
    (data & 0x01) ? gpio_set_level(BSP_LCD_D0, 1) : gpio_set_level(BSP_LCD_D0, 0);
}