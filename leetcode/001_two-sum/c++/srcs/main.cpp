#include "main.h"

class Solution {
public:
  void test(void){
    cout << "test" << endl; 
  }
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> _x;
    int _s=nums.size();
#if 0
    for(vector<int>::iterator it=nums.begin(); it != nums.end(); it++){
      cout << *it << endl; 
    }
#else
    for(int i=0; i<_s-1; i++){
      for(int j=i+1; j<_s; j++){
        if(target==(nums[i]+nums[j])){
          _x.push_pack(i);
          _x.push_pack(j);
	  return _x; 
	}
      }
    }
#endif
    return _x;
  }
};

int main(int argc, char *argv[]){
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
#if 0
  vector<int> vect={2, 7, 11, 15}; 
#else
  int array[4]={2, 7, 11, 15}; 
  vector<int> vect(array, array+4); 
#endif
  vector<int> x=Solution().twoSum(vect, 9);
  cout << "[" << x[0] << "," << x[1] << "]" << endl; 
  return 0; 
}
