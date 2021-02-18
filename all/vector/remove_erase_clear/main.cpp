// vector assign
#include <iostream>
#include <vector>
using namespace std; 

void test1(void){
  cout << __FUNCTION__ << ", " << __LINE__ << " : "; 
  cout << "start"; 
  cout << endl; 
  cout.flush();

  vector<int> iv; 
  vector<int>::iterator it; 

  cout << "iv.assign(10, 100);" << endl;
  iv.assign(10, 100);

  cout << "iv.size() : " << iv.size() << endl; 
  cout << "iv : "; 
  for(it=iv.begin();it!=iv.end();it++){
    cout << *it << ' '; 
  }
  cout << endl; 

  iv.clear();

  cout << "iv.clear();" << endl; 
  cout << "iv.size() : " << iv.size() << endl; 
  cout << "iv.empty() : " << iv.empty() << endl; 

  vector<int> iv2(5, 10);

  cout << "iv2.size() : " << iv2.size() << endl; 
  cout << "iv2 : "; 
  for(it=iv2.begin();it!=iv2.end();it++){
    cout << *it << ' '; 
  }
  cout << endl; 

  // -std=c++11 or -std=gnu++11
  // iv={10,20,30,20,10,40,10}; 

  int iv3[]={10,20,30,10,40,20,10,30,10,10,20}; 
  iv.assign(iv3, iv3+(sizeof(iv3)/sizeof(int)));
  cout << "iv.size() : " << iv.size() << endl; 
  cout << "iv : "; 
  for(it=iv.begin();it!=iv.end();it++){
    cout << *it << ' '; 
  }
  cout << endl; 

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
  return 0;
}
