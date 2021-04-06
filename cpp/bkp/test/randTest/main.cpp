#include <iostream>
#include "main.h"
int main(int argc, char *argv[]){
  Rand r; 
  cout << r.Float() << endl; 
  cout << r.Float(2) << endl; 
  for(int i=0; i<1000; i++){
    if(r.Float(2)==0) cout << "Hunt 0!!" << endl; 
    if(r.Float(2)==1) cout << "Hunt 1!!" << endl; 
    if(r.Float(2)>1) cout << "> 1!!" << endl; 
  }
  for(int i=0; i<1000; i++){
    if(r.Float(0,100)==0) cout << "Hunt 0!!" << endl; 
    if(r.Float(0,100)==1) cout << "Hunt 100!!" << endl; 
    if(r.Float(0,100)>100) cout << "> 100!!" << endl; 
  }
  for(int i=0; i<1000; i++){
    if(r.Float(0,100,2)==0) cout << "Hunt 0!!" << endl; 
    if(r.Float(0,100,2)==100) cout << "Hunt 100!!" << endl; 
    if(r.Float(0,100,2)>100) cout << "> 100!!" << endl; 
    //cout << r.Float(0,100,2) << " "; 
  }
  cout << endl; 
  return 0; 
}
