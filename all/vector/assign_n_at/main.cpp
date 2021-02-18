// vector assign
#include <iostream>
#include <vector>
using namespace std; 

void test1(void){
  cout << __FUNCTION__ << ", " << __LINE__ << " : "; 
  cout << "start"; 
  cout << endl; 
  cout.flush();

  vector<int> first;
  vector<int> second;
  vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  cout << "Size of first: " << int (first.size()) << '\n';
  cout << "Size of second: " << int (second.size()) << '\n';
  cout << "Size of third: " << int (third.size()) << '\n';

  cout << __FUNCTION__ << ", " << __LINE__ << " : "; 
  cout << "end"; 
  cout << endl; 
  cout.flush();
}

void test2(void){
  cout << __FUNCTION__ << ", " << __LINE__ << " : "; 
  cout << "start"; 
  cout << endl; 
  cout.flush();

  vector<int> iv; 

  iv.assign(10, 0);

  for(int i=0; i<10; i++){
    iv.at(i)=i;
  }

  vector<int>::iterator it; 

  for(it=iv.begin(); it!=iv.end(); it++){
    cout << "*it: " << *it << endl; 
  }

  it=iv.begin(); 

  cout << "it[2]: " << it[2] << endl; 

  cout << __FUNCTION__ << ", " << __LINE__ << " : "; 
  cout << "end"; 
  cout << endl; 
  cout.flush();
}

#if 0
void testTemplate(void){
  cout << __FUNCTION__ << ", " << __LINE__ << " : "; 
  cout << "start"; 
  cout << endl; 
  cout.flush();


  cout << __FUNCTION__ << ", " << __LINE__ << " : "; 
  cout << "end"; 
  cout << endl; 
  cout.flush();
}
#endif

int main (void){
  test1();
  test2();
  return 0;
}
