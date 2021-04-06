#include <iostream>
#include "main.h"
using namespace std;
typedef struct Data {
  int a;
  int b; 
} Data; 
int main(int argc, char *argv[]){
  vector<Data> vD; 
  int size=10; 
  cout << "capacity: " << vD.capacity() << endl;
  vD.reserve(size);
  cout << "push_back 10 elements..."  << endl;
  for(int i=0; i<size; i++){
    int a=i+1, b=i+2; 
    vD.push_back((Data) {a,b});
  }
  cout << "capacity: " << vD.capacity() << endl;
  cout << "size: " << vD.size() << endl;
  for(int i=0; i<(int)vD.size(); i++){
    cout << "vD[" << i << "](" << vD[i].a << ", " << vD[i].b << ") ";
  }
  cout << endl; 
  cout << "swap empty..." << endl;
  vector<Data> ().swap(vD);
  cout << "capacity: " << vD.capacity() << endl;
  return 0; 
}

