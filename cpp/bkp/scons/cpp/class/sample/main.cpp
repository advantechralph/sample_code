#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "class.h"
int main(void){
  SubClass *s1=new SubClass(1,2);
  s1->dump();
  delete s1;
  return 0; 
}
