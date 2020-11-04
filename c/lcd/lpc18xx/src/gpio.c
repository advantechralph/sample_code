#include <stdio.h>
#include <stdint.h>
void gpio_set(uint8_t output_num){
	printf("%s, %d: output_num: %d\n", __FUNCTION__, __LINE__, output_num);
}
void gpio_clear(uint8_t output_num){
	printf("%s, %d: output_num: %d\n", __FUNCTION__, __LINE__, output_num);
}
