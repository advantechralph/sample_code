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
  cout << __FUNCTION__ << ", " << __LINE__ << ": " << endl;
  vector<int> vA; 
  cout << "vA size: " << vA.size() << endl;
  vA.assign(5,1);
  cout << "vA size: " << vA.size() << endl;
  cout << "vA.at(3): " << vA.at(3) << endl; 
  vector<int> vB={0,1,2,3,4,5,6}; 
  cout << "vB size: " << vB.size() << endl;
  cout << "vB.at(3): " << vB.at(3) << endl; 
  return 0; 
}
