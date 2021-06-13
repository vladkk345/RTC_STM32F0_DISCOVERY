#ifndef LCD_H_
#define LCD_H_

#include "stm32f0xx_hal.h"
#include "stm32f0xx.h"

void LCD_ini(void);
void delay(void);
void LCD_WriteData(uint8_t dt);
void LCD_Command(uint8_t dt);
void LCD_Data(uint8_t dt);
void LCD_SendChar(char ch);
void LCD_String(char* st);
void LCD_SetPos(uint8_t x, uint8_t y);
void LCD_Clear(void);
void LCD_StringRunR(void);
void LCD_StringRunL(void);
void LCD_LedOnOff(uint8_t status);

#define B4_SET() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET)
#define B5_SET() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET)
#define B6_SET() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET)
#define B7_SET() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET)

#define B4_RESET() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET)
#define B5_RESET() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET)
#define B6_RESET() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET)
#define B7_RESET() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET)

#define E_SET()    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET)
#define E_RESET()  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET)

#define R_SET()    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET)
#define R_RESET()  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET)

#endif /* LCD_H_ */
