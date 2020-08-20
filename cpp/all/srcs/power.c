#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int power(int input, int base, int n){
  printf("%s, %d: n: %d, input: %d\n", __FUNCTION__, __LINE__, n, input);
  if(n>0){
    power(input*base, base, n-1); 
  }else{
    return input; 
  }
  return 0; 
}

int main(int argc, char *argv[]){
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  power(1, 10, 5);
  return 0; 
}

