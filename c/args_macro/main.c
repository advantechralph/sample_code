#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void test(int argc, char *argv[]){
  printf("%s\n", argv[1]);
}

int main(int argc, char *argv[]){
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  char *a[]={"oooxxx", "236t164t6", NULL}; 
  test(2, a);
  return 0; 
}

