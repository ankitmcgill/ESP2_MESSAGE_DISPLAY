///////////////////////////////////////////////////////////////
//ESP32 MESSAGE DISPLAY
//
//EXTERNAL - LCD
//LED CONTROL BASED ON ESP32 LEDC PERIPHERAL
//

//NOVEMBER 3 2019
///////////////////////////////////////////////////////////////

#ifndef _EXTERNAL_LCD_
#define _EXTERNAL_LCD_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define EXTERNAL_LCD_TAG                    "E:LCD"

#define EXTERNAL_LCD_COUNT_LINES            (4)
#define EXTERNAL_LCD_WIDTH_LINE             (20)
#define EXTERNAL_LCD_ADDRESS_LINE_1         (0x80)
#define EXTERNAL_LCD_ADDRESS_LINE_2         (0xC0)
#define EXTERNAL_LCD_ADDRESS_LINE_3         (0x94)
#define EXTERNAL_LCD_ADDRESS_LINE_4         (0xD4)

#define EXTERNAL_LCD_COMMAND_DISPLAY_ON_NO_CURSOR   (0x0C)
#define EXTERNAL_LCD_COMMAND_CLEAR_DISPLAY          (0x01)

void EXTERNAL_LCD_Init(void);

void EXTERNAL_LCD_Clear(void);

void EXTERNAL_LCD_PutStringLeftInLine(char* str, uint8_t line_num);
void EXTERNAL_LCD_PutStringRightInLine(char* str, uint8_t line_num);
void EXTERNAL_LCD_PutStringCenteredInLine(char* str, uint8_t line_num);

#endif