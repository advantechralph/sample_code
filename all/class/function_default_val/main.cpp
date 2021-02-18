#include <iostream>
using namespace std;
#ifdef  __cplusplus
extern  "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef  __cplusplus
}
#endif
void testcase1(int a=5){
  printf("%s, %d: a=%d\n", __FUNCTION__, __LINE__, a);
}
int main(void){
  printf("%s, %d\n", __FUNCTION__, __LINE__);
  testcase1();
  printf("%s, %d: end\n", __FUNCTION__, __LINE__);
  return 0; 
}
