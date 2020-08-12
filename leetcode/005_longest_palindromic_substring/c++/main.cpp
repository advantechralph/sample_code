#include <cstdio>
#include <iostream>
#include <vector>
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
  int check(string s){
    int halfLens=s.size()/2; 
    int match=1; 
    cout << "s: " << s << endl; 
    string::iterator it_s=s.begin(), it_e=s.end()-1; 
    if(s.size()<2) return 0; 
    for(int i=0; i<halfLens; i++){
      cout << "it_s, it_e: " << *it_s << "," << *it_e << endl;
      if(*it_s!=*it_e){
        match=0; break; 
      }
      ++it_s;
      --it_e;
    }
    return match; 
  }
  string longestPalindrome(string s) {
    string r; 
    if(s.size()==0) ;
    for(string::iterator it=(s.end()-1);;it--){
      cout << "*it: " << *it << endl; 
      cout << "begin: " << *(s.begin()) << endl; 
      printf("%lu, %lu\n", it, s.begin());
//      cout << static_cast<void *>(it) << "," << static_cast<void *>(s.begin()) << endl; 
      if(it==s.begin()) break;
    }
    return r;
  }
};

int main(int argc, char *argv[]){
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  cout << Solution().check("") << endl; 
  cout << Solution().check("aba") << endl; 
  cout << Solution().check("x") << endl; 
  cout << Solution().check("xxyyxx") << endl; 
  Solution().longestPalindrome("xyx");
  return 0; 
}

