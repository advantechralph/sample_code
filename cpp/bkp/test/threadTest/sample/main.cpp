#include <iostream>
#include "main.h"
using namespace std;
void *t1func(void *data){
  pthread_detach(pthread_self());
  for(int i=0; i<5; i++){
    printf("%s(%p): loop\n", __FUNCTION__, (void *)t1func);
    sleep(1);
  }
  pthread_exit(NULL);
}
int main(int argc, char *argv[]){
  cout << __FILE__ << ", " ; 
  cout << __FUNCTION__ << ", ";
  cout << __LINE__ << ": ";
  cout << endl; 
  Thread t1("t1task", t1func, (void *)"t1data");
  printf("before join...\n");
  pthread_join(t1.Id(), NULL);
  printf("t1 create again...\n");
  t1.Create();
  printf("before join...\n");
  pthread_join(t1.Id(), NULL);
  printf("t1 create again...\n");
  t1.Create();
  for(int i=0; i<3; i++) sleep(1);
  printf("cancel t1...\n");
  t1.Cancel();
  return 0; 
}

