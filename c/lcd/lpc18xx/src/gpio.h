#ifndef GPIO_H_
#define GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

void gpio_set(uint8_t output_num);
void gpio_clear(uint8_t output_num);

#define LCM_DB0                 16 //0:11  Display Panel
#define LCM_DB1                 17 //0:2
#define LCM_DB2                 18 //0:3
#define LCM_DB3                 19 //0:13
#define NXP_HWM_RST             20 //5:2   NTC7904 Reset
#define LCM_DB4                 21 //5:5
#define LCM_DB5                 22 //5:6
#define LCM_DB6                 23 //1:10
#define LCM_DB7                 24 //5:8
#define LCM_RS                  25 //5:9
#define LCM_RW                  26 //1:15
#define LCM_E                   27 //2:6
#define LCM_A                   28 //2:15


#ifdef __cplusplus
}
#endif

#endif /* GPIO_H_ */

