#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int foo(int *a, int *b)
{
    *a = 5;
    *b = 6;
    return *a + *b;
}
 
int rfoo(int *restrict a, int *restrict b)
{
    *a = 5;
    *b = 6;
    return *a + *b;
}

int main(int argc, char *argv[]){
#if 1
  const int local_int=10; 
  const int local_int2=20; 
  int *restrict rpI=(int *)&local_int; 
  int *pI=(int *)rpI; 
  int *restrict rpI2=(int *)&local_int2; 
  *rpI=30; 
  printf("%s, %d: local_int: %d\n", __FUNCTION__, __LINE__, local_int);
  printf("%s, %d: *pI: %d\n", __FUNCTION__, __LINE__, *pI);
  printf("%s, %d: *rpI+*rpI2: %d\n", __FUNCTION__, __LINE__, *rpI+*rpI2);
  *rpI=*rpI2; 
  printf("%s, %d: *rpI: %d\n", __FUNCTION__, __LINE__, *rpI);
  printf("%s, %d: *rpI2: %d\n", __FUNCTION__, __LINE__, *rpI2);
#else
  int a=10, b=20; 
  printf("%s, %d: foo: %d\n", __FUNCTION__, __LINE__, foo(&a, &b));
  printf("%s, %d: rfoo: %d\n", __FUNCTION__, __LINE__, rfoo(&a, &b));
#endif
  return 0; 
}

