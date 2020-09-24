#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bits.h"

typedef struct functab {
  void (*func)(void);
} functab; 

void test1(void){
    uint8 reg=0, reg_org=0; 
    printf("%s, %d: \n", __FUNCTION__, __LINE__);
    SET(reg, BIT1);
    reg_org=reg; 
    printf("%s, %d: reg: %02X, BIT1: %02X\n", __FUNCTION__, __LINE__, reg, BIT1);
    printf("reg: "); 
    printbits(reg); 
    printf("\n"); 
    printf("reg is %s!!\n", (reg ^ reg_org )?"changed":"not changed");
    printf("set bit3...\n");
    SET(reg, BIT3);
    printf("reg: "); 
    printbits(reg); 
    printf("\n"); 
    printf("reg is %s!!\n", (reg ^ reg_org )?"changed":"not changed");
}

functab testFuncTab[]={
  {test1}, 
  {NULL}
};

int main(int argc, char *argv[]){
  for(functab *p=testFuncTab; p->func; p++){
    p->func();
  }
  return 0; 
}

