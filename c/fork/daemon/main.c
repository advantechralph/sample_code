#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/time.h>

int main(int argc, char *argv[]){
  pid_t fid=0; 
  if((fid=fork())==0){
    while(1){
      printf("%s, %d: child...\n", __FUNCTION__, __LINE__);
      sleep(10);
    }
  }else{
    printf("%s, %d: parent...\n", __FUNCTION__, __LINE__);
  }
  return 0; 
}

