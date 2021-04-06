// compile with: /W4 /EHsc
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int globalvar = 20;
int& foo(){
  return globalvar;
}
void test1(void){
  int x=5, y=6; 
  auto &&z=x+y; 
  cout << "z: " << z << endl; 
  x=6;
  cout << "z: " << z << endl; 
}
int main(void){
  int i=5, j=6; 
  int m=2, n=3; 
  int f=[&,n](int &x, int y){m+=n; x++; y++; return x;}(i, j);
  auto func=[&,n](int &x, int y){m+=n; x++; y++; return x;};
  cout << "f: " << f << endl; // 6
  printf("m: %d, n: %d, i: %d, j: %d\n", m, n, i, j); // 5, 3, 6, 6
  cout << "func(m,n): " << func(m,n) << endl; // 9
  printf("m: %d, n: %d, i: %d, j: %d\n", m, n, i, j); // 9, 3, 6, 6
  test1();
  return 0;
}
