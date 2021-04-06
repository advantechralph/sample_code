#ifndef __inherit_h__
#define __inherit_h__
#include <iostream>
#include <cstdio>
using namespace std; 
class SuperClass
{
  public:
    SuperClass(int foo)
    {
      printf("%s, %d: \n", __FUNCTION__, __LINE__);
      // do something with foo
    }
    void test(void){
      printf("%s, %d: \n", __FUNCTION__, __LINE__);
    }
};

class SubClass : public SuperClass
{
  public:
    SubClass(int foo, int bar)
    : SuperClass(foo)  // Call the superclass constructor in the subclass' initialization list.
    {
      // do something with bar
    }
    void test(void){
      printf("%s, %d: \n", __FUNCTION__, __LINE__);
    }
};
#endif
