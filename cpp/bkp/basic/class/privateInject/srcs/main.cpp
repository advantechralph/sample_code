#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std; 

class test {
public: 
  test(int a, int b);
  void dump(void);
private:
  int _c;
  int _d;
}; 

test::test(int a, int b) : _c(b), _d(a){
}

void test::dump(void){
  cout << "_c: " << _c << endl;
  cout << "_d: " << _d << endl;
}

void pause(void){
  printf("pause, please enter any key...");
  getchar();
}

int main() { 
  cout << "t1(3,4)" << endl;
  test t1(3,4); 
  t1.dump();
  pause();
  return 0; 
} 

