#ifndef LCD_H_
#define LCD_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LCD_BUFFER {
	char line1[16];
	char line2[16];
} LCD_BUFFER_T;

typedef enum {
    LCD_DISPLAY_SLEEP = 0,
    LCD_DISPLAY_WAKE  = 1,
} LCD_MODE_T;

/* Basic instruction */
#define LCD_ST7920_BASIC_CMD_Clear                               0x01
#define LCD_ST7920_BASIC_CMD_Home                                0x02
#define LCD_ST7920_BASIC_CMD_EntryModeSet                        0x06
/* Display Control */
#define LCD_ST7920_BASIC_CMD_OFF                                 0x08
#define LCD_ST7920_BASIC_CMD_ON                                  0x0C
/* Function Set */
#define LCD_ST7920_BASIC_CMD_Basic_Func                          0x38       // Back to normal mode
#define LCD_ST7920_BASIC_CMD_Ext_Func                            0x34
/* Basic instruction End */

/* Extended instruction */
#define LCD_ST7920_EXT_CMD_Standby                               0x01

/* Extended instruction End */


#define DB(x,i) ((x>>i)&1)
#define DB0(x)  DB(x,0)
#define DB1(x)  DB(x,1)
#define DB2(x)  DB(x,2)
#define DB3(x)  DB(x,3)
#define DB4(x)  DB(x,4)
#define DB5(x)  DB(x,5)
#define DB6(x)  DB(x,6)
#define DB7(x)  DB(x,7)

void LCD_init(void);
void LCD_update_display(char *buffer, uint8_t offset, uint8_t length);
void LCD_set_display_mode(uint8_t mode);
void LCD_clear(void);
void LCD_write_pattern(char c, uint8_t offset, uint8_t length);

void LCD_Delay(int ms);
void LCD_command(char c);
void LCD_data(char c);

void LCD_Display(LCD_MODE_T mode);

void LCD_SetDataBus(uint8_t data);
void LCD_ResetPinRS(void);
void LCD_SetPinRS(void);
void LCD_ResetPinRW(void);
void LCD_SetPinRW(void);
void LCD_ResetPinE(void);
void LCD_SetPinE(void);

void LCD_SetGpioDB0(uint8_t data);
void LCD_SetGpioDB1(uint8_t data);
void LCD_SetGpioDB2(uint8_t data);
void LCD_SetGpioDB3(uint8_t data);
void LCD_SetGpioDB4(uint8_t data);
void LCD_SetGpioDB5(uint8_t data);
void LCD_SetGpioDB6(uint8_t data);
void LCD_SetGpioDB7(uint8_t data);

#ifdef __cplusplus
}
#endif

#endif /* LCD_H_ */

