#ifndef __main_h__
#define __main_h__
#include <iostream>
#include <vector>
using namespace std; 
template <typename T>
const T&Max(const T &a, const T &b) { 
  return a<b?b:a; 
} 
template <typename T>
void printMax(const T &a, const T &b){
  cout << Max(a,b) << endl;
}
#endif /*__main_h__*/
