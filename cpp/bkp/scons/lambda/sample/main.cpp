#include <iostream>
#include <algorithm>
#include <vector>
#include "main.h"
using namespace std;
int main() {
  auto lambda = []() { cout << "Hello, Lambda" << endl; };
  lambda();
  vector <int> v = {1,2,3,4,5,6,7}; 
  //printMax(1,2);
  cout << "Max(1,2): " << Max(1,2) << endl;
  cout << "count if > 3: " << count_if(v.begin(),v.end(),[](int x){return (x>3);}) << endl; 
  return 0; 
}
