#include <stdio.h>
#include <assert.h>
int main(void){
  char *p=NULL; 
  assert(p&&"p is null");
  return 0; 
}
