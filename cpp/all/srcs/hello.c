#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  printf("%s, %d: hello\n", __FUNCTION__, __LINE__);
  return 0; 
}

