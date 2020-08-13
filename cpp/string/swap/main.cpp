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
  string swap(string s){
    string ans=""; 
    for(string::iterator it=s.begin(); it!=s.end(); ++it){
      ans.insert(0, 1, *it);
    }
    return ans; 
  }
}; 


int main(int argc, char *argv[]){
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  cout << "ans: '" << Solution().swap(string("ooxx")) << "" << endl; 
  cout << "ans: '" << Solution().swap(string("abcxyz")) << "'" << endl; 
  cout << "ans: '" << Solution().swap(string("")) << "'" << endl; 
  return 0; 
}

