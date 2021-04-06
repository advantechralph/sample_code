#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
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

class Solution {
public: 
  string find(string s, const char c){
    string ans=""; 
    for(string::iterator it=s.begin(); it!=s.end(); ++it){
      ans.insert(0, 1, *it);
    }
    return ans; 
  }
}; 


int main(int argc, char *argv[]){
  string testCase[]={
    "ooxxooxx",
    "test", 
    "abcxyz",
    "qooqoo"
  }; 
  cout << testCase[0].find('x') << endl;
  cout << testCase[0].npos << endl; 
  cout << testCase[0].replace(0, 1, "") << endl;
#if 0
  cout << testCase[0].find('x') << endl;
  cout << testCase[0].substr(testCase[0].find('x')).find('x') << endl; 
  cout << testCase[0].substr(testCase[0].find('x')) << endl; 
#endif
#if 0
  for(int i=0; i<(int)(sizeof(testCase)/sizeof(string)); i++){
    cout <<  "[" <<  i << "]: " << testCase[i] << ", find: " << Solution().find(testCase[i], 'x') << endl; 
  }
#endif
  return 0; 
}

