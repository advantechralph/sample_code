#ifndef PC_SIM
#include "board.h"
#else
#include <stdio.h>
#include <stdint.h>
#endif
#include "lcd.h"
#include "gpio.h"

// x=2000, ms=1000, 250ms, 250000us 
// x=8000, ms=1000, 1s
void LCD_Delay(int ms)
{
	volatile static int x,y;
	while (ms)
	{
		for (x=0; x<=8000; x++)
		{
			y++;
		}
		ms--;
	}
}

void LCD_SetGpioDB0(uint8_t data){
#if 0
        void (*f)(uint8_t)=(data?gpio_set:gpio_clear); 
	f(LCM_DB0);
#endif
	//NXP set GPIO DB0 pin
	if(data){
		gpio_set(LCM_DB0);
	}else{
		gpio_clear(LCM_DB0);
	}
}

void LCD_SetGpioDB1(uint8_t data){
	//NXP set GPIO DB1 pin
	if(data){
		gpio_set(LCM_DB1);
	}else{
		gpio_clear(LCM_DB1);
	}
}

void LCD_SetGpioDB2(uint8_t data){
	//NXP set GPIO DB2 pin
	if(data){
		gpio_set(LCM_DB2);
	}else{
		gpio_clear(LCM_DB2);
	}
}

void LCD_SetGpioDB3(uint8_t data){
	//NXP set GPIO DB3 pin
	if(data){
		gpio_set(LCM_DB3);
	}else{
		gpio_clear(LCM_DB3);
	}
}

void LCD_SetGpioDB4(uint8_t data){
	//NXP set GPIO DB4 pin
	if(data){
		gpio_set(LCM_DB4);
	}else{
		gpio_clear(LCM_DB4);
	}
}

void LCD_SetGpioDB5(uint8_t data){
	//NXP set GPIO DB5 pin
	if(data){
		gpio_set(LCM_DB5);
	}else{
		gpio_clear(LCM_DB5);
	}
}

void LCD_SetGpioDB6(uint8_t data){
	//NXP set GPIO DB6 pin
	if(data){
		gpio_set(LCM_DB6);
	}else{
		gpio_clear(LCM_DB6);
	}
}

void LCD_SetGpioDB7(uint8_t data){
	//NXP set GPIO DB7 pin
	if(data){
		gpio_set(LCM_DB7);
	}else{
		gpio_clear(LCM_DB7);
	}
}

void LCD_SetDataBus(uint8_t data){
	LCD_SetGpioDB7(DB7(data));
	LCD_SetGpioDB6(DB6(data));
	LCD_SetGpioDB5(DB5(data));
	LCD_SetGpioDB4(DB4(data));
	LCD_SetGpioDB3(DB3(data));
	LCD_SetGpioDB2(DB2(data));
	LCD_SetGpioDB1(DB1(data));
	LCD_SetGpioDB0(DB0(data));

}
void LCD_ResetPinRS(void){
	gpio_clear(LCM_RS); //LOW
}
void LCD_SetPinRS(void){
	gpio_set(LCM_RS); //HIGH
}
void LCD_ResetPinRW(void){
	gpio_clear(LCM_RW); //LOW
}
void LCD_SetPinRW(void){
	gpio_set(LCM_RW); //HIGH
}
void LCD_ResetPinE(void){
#ifdef PC_SIM
	printf("%s, %d: \n", __FUNCTION__, __LINE__);
#endif
	gpio_clear(LCM_E); //LOW
}
void LCD_SetPinE(void){
	gpio_set(LCM_E); //HIGH
}

//advantech
/* Initalize LCD Display */
/* GPIO Pins are configured in gpio.c */
void LCD_init(void) {
#ifdef PC_SIM
	printf("%s, %d: \n", __FUNCTION__, __LINE__);
#endif
	LCD_ResetPinE();
	LCD_Delay(50);
	LCD_command(LCD_ST7920_BASIC_CMD_Basic_Func);
	LCD_Delay(100);
	LCD_command(LCD_ST7920_BASIC_CMD_Basic_Func);
	LCD_Delay(100);
	LCD_command(LCD_ST7920_BASIC_CMD_Basic_Func);
	LCD_Delay(100);
	LCD_command(LCD_ST7920_BASIC_CMD_Basic_Func);
	// Start from left
	LCD_command(0x10);
	// Disaly: ON, Cursor: OFF, Blink: OFF
	LCD_command(0x0c);
	LCD_command(0x06);
	// Display Clear
	LCD_command(LCD_ST7920_BASIC_CMD_Clear);
}

//advantech
/*  Write buffer to LCD display starting at offset with length characters. */
/*  Offset for LCD Display is 0-31 with 0-15 for top line and 16-32 for bottom line. */
void LCD_update_display(char *buffer, uint8_t offset, uint8_t length) {
        int pos=0x80+(offset/16)*0x10+(offset%16);
	LCD_command(pos);
	for(int i=(pos&0xF); (i<((pos&0xF)+length))&&(i<16); i++){
		LCD_data(buffer[i-(pos&0xF)]);
	}
}

/* put the LCD display in wake or sleep mode */
void LCD_set_display_mode(uint8_t mode) {
	//TODO: NEED GPIO to Turn off LCD Display
}

//advantech
/* Clear the LCD Display */
void LCD_clear(void){
	LCD_command(LCD_ST7920_BASIC_CMD_Clear);		//LCD Display clear
	LCD_Delay(250);
}

void LCD_Display(LCD_MODE_T mode){
	if(mode==LCD_DISPLAY_SLEEP){
		// standby mode
		LCD_command(LCD_ST7920_BASIC_CMD_Ext_Func);
		LCD_command(LCD_ST7920_EXT_CMD_Standby);
	}else{
		// normal mode
		LCD_command(LCD_ST7920_BASIC_CMD_Basic_Func);
	}
	LCD_Delay(250);
}

void LCD_command(char c){
	LCD_SetDataBus(c);
	LCD_ResetPinRS();
	LCD_ResetPinRW();
	LCD_SetPinE();
	LCD_Delay(100);
	LCD_ResetPinE();
}

void LCD_data(char c){
	LCD_SetDataBus(c);
	LCD_SetPinRS();
	LCD_ResetPinRW();
	LCD_SetPinE();
	LCD_Delay(100);
	LCD_ResetPinE();
}

//advantech
/* write char c starting at offset for length positions on display */
/*  Offset for LCD Display is 0-31 with 0-15 for top line and 16-31 for bottom line. */
void LCD_write_pattern(char c, uint8_t offset, uint8_t length) {
        int pos=0x80+(offset/16)*0x10+(offset%16);
	LCD_command(pos);
	for(int i=(pos&0xF); (i<((pos&0xF)+length))&&(i<16); i++){
		LCD_data(c);
	}
}

