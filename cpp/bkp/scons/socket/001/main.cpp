#include "main.h"
using namespace std;
#define LogFile "log.run"
void socketTest(void);
void threadTest(void);
int main(int argc, char *argv[]) {
  if(argc>1){
    remove(LogFile);
    int fd=open(LogFile, O_RDWR|O_CREAT, 0666);
    dup2(fd, STDOUT_FILENO);
    close(fd);
  }
  socketTest();
  //threadTest();
  while(1){
    fflush(stdout);
    sleep(1);
  }
  return 0; 
}
