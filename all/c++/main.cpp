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

void testSize(void){
  cout << "===============================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << " : "; 
  cout << "start"; 
  cout << endl; 
  cout.flush();

  {
    vector<int> iv1(5); 
    cout << "vector<int> iv1(5); " << endl; 
    cout << "iv1.size() : " << iv1.size() << endl; 
  }

  {
    vector<int> iv1; 
    cout << "vector<int> iv1; " << endl; 
    cout << "iv1.size() : " << iv1.size() << endl; 
    iv1.resize(10);
    cout << "iv1.resize(10); " << endl; 
    cout << "iv1.size() : " << iv1.size() << endl; 
  }

  {
    vector<int> iv1; 
    cout << "vector<int> iv1; " << endl; 
    cout << "iv1.size() : " << iv1.size() << endl; 
    iv1.assign(3, 100);
    cout << "iv1.assign(3, 100); " << endl; 
    cout << "iv1.size() : " << iv1.size() << endl; 
  }

  cout << __FUNCTION__ << ", " << __LINE__ << " : "; 
  cout << "end"; 
  cout << endl; 
  cout.flush();
}

void testInitValue(void){
  cout << "===============================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << " : "; 
  cout << "start"; 
  cout << endl; 
  cout.flush();
  {
    vector<int> iv1(5, 10); 
    vector<int>::iterator it; 
    cout << "vector<int> iv1(5, 10); " << endl; 
    cout << "iv1.size() : " << iv1.size() << endl; 
    cout << "iv1 : "; 
    for(it=iv1.begin(); it!=iv1.end(); it++){
      cout << *it << ' '; 
    }
    cout << endl; 
  }
  cout << "-------------------------------" << endl; 
  {
    vector<int> iv1; 
    vector<int>::iterator it; 
    cout << "vector<int> iv1; " << endl; 
    cout << "iv1.size() : " << iv1.size() << endl; 
    iv1.resize(5);
    cout << "iv1.resize(5);" << endl; 
    cout << "iv1.size() : " << iv1.size() << endl; 
    cout << "for(int i=0; i<iv1.size(); i++)" << endl; 
    cout << "  iv1.at(i)=(i+1)*10; " << endl; 
    for(int i=0; i<(int)(iv1.size()); i++)
      iv1.at(i)=(i+1)*10; 
    cout << "iv1 : "; 
    for(it=iv1.begin(); it!=iv1.end(); it++){
      cout << *it << ' '; 
    }
    cout << endl; 
  }
  cout << "-------------------------------" << endl; 
  {
    int arr1[]={10, 20, 30, 10, 20, 30, 40}; 
    cout << "vector<int> iv1; " << endl; 
    cout << "int arr1[]={10, 20, 30, 10, 20, 30, 40};" << endl; 
    vector<int> iv1(arr1, arr1+(sizeof(arr1)/sizeof(int))); 
    vector<int>::iterator it; 
    cout << "vector<int> iv1(arr1, arr1+(sizeof(arr1)/sizeof(int)));" << endl; 
    cout << "iv1.size() : " << iv1.size() << endl; 
    cout << "iv1 : "; 
    for(it=iv1.begin(); it!=iv1.end(); it++){
      cout << *it << ' '; 
    }
    cout << endl; 
  }
  cout << "-------------------------------" << endl; 
  {
    vector<int>::iterator it; 
    int *arr1=new int[7];
    cout << "vector<int> iv1; " << endl; 
    cout << "int *arr1[]=new int(7); " << endl; 
    cout << "arr1[i]=(i+1)*10;" << endl; 
    for(int i=0; i<7; i++)
      arr1[i]=(i+1)*10; 
    vector<int> iv1(arr1, arr1+7);
    cout << "vector<int> iv1(arr1, arr1+7);" << endl; 
    cout << "iv1.size() : " << iv1.size() << endl; 
    cout << "iv1 : "; 
    for(it=iv1.begin(); it!=iv1.end(); it++){
      cout << *it << ' '; 
    }
    cout << endl; 
  }
  cout << __FUNCTION__ << ", " << __LINE__ << " : "; 
  cout << "end"; 
  cout << endl; 
  cout.flush();
}

#if 0
void testTemplate(void){
  cout << "===============================" << endl; 
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
  testSize();
  testInitValue();
  return 0;
}

