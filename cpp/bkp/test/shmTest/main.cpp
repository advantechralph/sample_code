#include <iostream>
#include "main.h"
using namespace std;
typedef struct Data {
  unsigned long timestamp; 
  float temperature; 
} Data; 
class Channel {
  vector<Data *> vPD; 
public: 
  Channel(){
  }
  ~Channel(){
  }
}; 
int main(int argc, char *argv[]){
  Shm m(3333, 50);
  char *s=NULL;
  m.Attach();
  s=(char *)m.Data();
  strcpy(s, "yaya");
  s[4]='\0';
  m.Detach();
  return 0; 
}
