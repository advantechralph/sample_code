#include "main.h"

class Sample {
public: 
  Sample(){
    printf("%s(%p)\n", __FUNCTION__, this);
  }
  ~Sample(){
    printf("%s(%p)\n", __FUNCTION__, this);
  }
}; 
int main(int argc, char *argv[]){
  return 0; 
}
