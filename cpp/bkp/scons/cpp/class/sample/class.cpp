#include <iostream>
#include <stdio.h>
#include "class.h"
using namespace std; 
SuperClass::SuperClass(int input):param1(input+1){
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
}
void SuperClass::dump(void){
  printf("%s, %d: param1: %d\n", __FUNCTION__, __LINE__, param1);
}
SubClass::SubClass(int input1, int input2):SuperClass(input1), param1(input1), param2(input2){
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
}
void SubClass::dump(void){
  printf("%s, %d: param1: %d\n", __FUNCTION__, __LINE__, param1);
  printf("%s, %d: param2: %d\n", __FUNCTION__, __LINE__, param2);
}
