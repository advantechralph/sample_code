#include "main.h"
typedef struct Data {
  int a;
  int b; 
} Data; 
int main(int argc, char *argv[]){
  vector<Data> vD, vE; 
  int size=1000; 
  cout << "capacity: " << vD.capacity() << endl;
  cout << "reserve " << size << "..." << endl;
  vD.reserve(size);
  cout << "capacity: " << vD.capacity() << endl;
  cout << "swap empty..." << endl;
  //vector<Data> ().swap(vD);
  vD.swap(vE);
  cout << "capacity: " << vD.capacity() << endl;
  return 0; 
}
