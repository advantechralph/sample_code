#include "main.h"
#include <iostream>
#include <iomanip>
using namespace std;
template <class T>
class Set
{
  T t;
public:
  Set(T st) : t(st) {}

  void display() {
    cout << t << endl;
  }
};


class Set_int
{
  int t;
public:
  Set_int(int st): t(st) {}

  void display() {
    cout << setw(10) << setfill('0')
      << t << endl;
  }
};

// Specialized class template
template <> class Set<int>
{
  int t;
public:
  Set(int st): t(st) {}

  void display() {
    cout << setw(10) << setfill('o')
      << t << endl;
  }
};

typedef Set<int> NewSet; 

// Normal class, Not-template class
void templateTest(void){
  Set<string> a("hello");
  Set_int b(2); // User needs to know there is a non-template class.
  Set<int> c(2); // User doesn't need to know there is a non-template class.
  NewSet d(5); 

  a.display();
  b.display();
  c.display();
  d.display();
}
