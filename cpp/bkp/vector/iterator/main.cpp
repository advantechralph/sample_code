#include <iostream>
#include "main.h"
using namespace std;
template <typename T1, typename T2>
struct tData {
  T1 a; 
  T2 b; 
}; 
typedef struct tData<int,int> Data; 
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
#if 0
  for(int i=0; i<(int)vD.size(); i++){
    cout << "vD[" << i << "](" << vD[i].a << ", " << vD[i].b << ") ";
  }
  cout << endl; 
#endif
  for(vector<Data>::iterator it=vD.begin(); it!=vD.end(); it++){
    cout << "vD[" << (it-vD.begin()) << "](" << (*it).a << ", " << (*it).b << ") ";
  }
  cout << endl; 
  cout << "last one: "; 
  cout << "vD[" << (vD.end()-vD.begin()-1) << "](" << (*(vD.end()-1)).a << ", " << (*(vD.end()-1)).b << ") " << endl;
  cout << "swap empty..." << endl;
  vector<Data> ().swap(vD);
  cout << "capacity: " << vD.capacity() << endl;
  return 0; 
}

