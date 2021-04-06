#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
using namespace std; 
#ifdef  __cplusplus
extern  "C" {
#endif 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef  __cplusplus
}
#endif 

typedef struct funcTab {
  void (*func)(void); 
} funcTab; 

void find(void){
  cout << "=========================================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  string str="xxxabcabc"; 
  string substr="abc"; 
  cout << "str: " << str << endl; 
  cout << "substr: " << substr << endl; 
  cout << str.find(substr) << endl;
  cout << "=========================================" << endl; 
}

void erase(void){
  cout << "=========================================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  string str="xxxabcabc"; 
  string substr="abc"; 
  cout << "str: " << str << endl; 
  cout << "erase substr: " << substr << endl; 
  cout << str.find(substr) << endl;
  str.erase(str.find(substr), substr.length());
  cout << "str: " << str << endl; 
  cout << "=========================================" << endl; 
}

void replaceTest(void){
  std::string base="this is a test string.";
  std::string str2="n example";
  std::string str3="sample phrase";
  std::string str4="useful.";

  // replace signatures used in the same order as described above:

  // Using positions:                 0123456789*123456789*12345
  std::string str=base;           // "this is a test string."
  str.replace(9,5,str2);          // "this is an example string." (1)
  str.replace(19,6,str3,7,6);     // "this is an example phrase." (2)
  str.replace(8,10,"just a");     // "this is just a phrase."     (3)
  str.replace(8,6,"a shorty",7);  // "this is a short phrase."    (4)
  str.replace(22,1,3,'!');        // "this is a short phrase!!!"  (5)

  // Using iterators:                                               0123456789*123456789*
  str.replace(str.begin(),str.end()-3,str3);                    // "sample phrase!!!"      (1)
  str.replace(str.begin(),str.begin()+6,"replace");             // "replace phrase!!!"     (3)
  str.replace(str.begin()+8,str.begin()+14,"is coolness",7);    // "replace is cool!!!"    (4)
  str.replace(str.begin()+12,str.end()-4,4,'o');                // "replace is cooool!!!"  (5)
  str.replace(str.begin()+11,str.end(),str4.begin(),str4.end());// "replace is useful."    (6)
  std::cout << str << '\n';
}

void replaceTest2(void){
#if 0
  list<string> l; 
  l.push_back(string("ooxx1"));
  l.push_back(string("fbhsbhfbdlooxx2bhbfhfb"));
  l.push_back(string("ooxx3"));
  l.push_back(string("ooxx4"));
  list<string>::iterator begin=l.begin(); 
  list<string>::iterator it=l.begin(); 
  begin=l.begin();
  it=l.begin();
  cout << static_cast<void *>(&(*begin)) << endl; 
  list<string>::iterator end=l.end(); 
  it=end; 
  cout << "distance: " << distance(begin, it) << endl; 
  advance(it, -1); 
  cout << *it << endl; 
#endif
  string s1("gfsgbgnbjooxxgmnsjgnjfgj");
  cout << s1.find("ooxx") << endl;
}

void c_str(void){
  cout << "=========================================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  string str="xxxabcabc"; 
  cout << "str: " << str << endl; 
  char *p=(char *)str.c_str();
  p[1]='y'; 
  p[2]='z'; 
  cout << "str: " << str << endl; 
  cout << "=========================================" << endl; 
}

void iteratorTest(void){
  cout << "=========================================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  string str="xxxabcabc"; 
  cout << "str: " << str << endl; 
  for(string::iterator it=str.begin(); it!=str.end(); it++){
    cout << *it ;
    if(it!=(str.end()-1)) cout << ' '; 
    else cout << endl; 
  }
  cout << "=========================================" << endl; 
}

funcTab testFuncTab[]={
#if 0
  {find}, 
  {erase}, 
  {c_str}, 
  {iteratorTest}, 
  {replaceTest},
#endif
  {replaceTest2}, 
  {NULL}
}; 

int main(int argc, char *argv[]){
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  for(funcTab *p=testFuncTab; p->func; p++){
    p->func();
  }
  return 0; 
}

