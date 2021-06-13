#include "LCD.h"

uint8_t portLcd = 0;
//-------------------------------------------------------------------------------

void LCD_WriteData(uint8_t dt)
{
	  if(((dt >> 3)&0x01) == 1) {B7_SET();} else {B7_RESET();}
      if(((dt >> 2)&0x01) == 1) {B6_SET();} else {B6_RESET();}
      if(((dt >> 1)&0x01) == 1) {B5_SET();} else {B5_RESET();}
      if((dt&0x01) == 1) {B4_SET();} else {B4_RESET();}
}

//-------------------------------------------------------------------------------

void delay(void)
{
    uint16_t i;
    for (i = 0;i < 1000;i++)
	{

	}
}

//-------------------------------------------------------------------------------

void LCD_Command(uint8_t dt)
{
     R_RESET();
     LCD_WriteData(dt >> 4);
     E_SET();
     delay();
     E_RESET();
     LCD_WriteData(dt);
     E_SET();
     delay();
     E_RESET();
}

//-------------------------------------------------------------------------------

void LCD_Data(uint8_t dt)
{
     R_SET();
     LCD_WriteData(dt >> 4);
     E_SET();
     delay();
     E_RESET();
     LCD_WriteData(dt);
     E_SET();
     delay();
     E_RESET();
}

//-------------------------------------------------------------------------------

void LCD_Clear(void)
{
    LCD_Command(0x01);
    HAL_Delay(2);
}

//-------------------------------------------------------------------------------

void LCD_StringRunR(void)
{
	 LCD_Command(0x1C);
}

//-------------------------------------------------------------------------------

void LCD_StringRunL(void)
{
	 LCD_Command(0x18);
}

//-------------------------------------------------------------------------------

void LCD_SendChar(char ch)
{
    LCD_Data((uint8_t) ch);
    HAL_Delay(2);
}

//-------------------------------------------------------------------------------

void LCD_String(char* str)
{
    for (uint8_t i = 0; str[i] != 0; i++)
	{
		LCD_Data(str[i]);
		HAL_Delay(2);
	}
}

//-------------------------------------------------------------------------------

void LCD_SetPos(uint8_t x, uint8_t y)
{
      switch(y)
      {
          case 0:
              LCD_Command(x|0x80);
              HAL_Delay(1);
              break;
          case 1:
              LCD_Command((0x40+x)|0x80);
              HAL_Delay(1);
              break;
          default:
			  break;
      }
}

//-------------------------------------------------------------------------------

void LCD_LedOnOff(uint8_t status)
{
	if(status == 0)
	{
		R_RESET();
		  E_SET();
		     delay();
		     E_RESET();
		     E_SET();
		     delay();
		     E_RESET();
	}
	else
	{
		LCD_Command(0x08); // Включаем подсветку
	}
}

//-------------------------------------------------------------------------------

void LCD_ini(void)
{
    HAL_Delay(40);
	R_RESET();
    LCD_WriteData(3);
    E_SET();
    delay();
    E_RESET();
    HAL_Delay(1);
    LCD_WriteData(3);
    E_SET();
	delay();
    E_RESET();
    HAL_Delay(1);
    LCD_WriteData(3);
    E_SET();
    delay();
    E_RESET();
    HAL_Delay(1);
        LCD_Command(0x28);
    HAL_Delay(1);
        LCD_Command(0x28);
    HAL_Delay(1);
        LCD_Command(0x0C);
    HAL_Delay(1);
        LCD_Command(0x01);
    HAL_Delay(2);
        LCD_Command(0x06);
    HAL_Delay(1);
        LCD_Command(0x02);
    HAL_Delay(2);


}


