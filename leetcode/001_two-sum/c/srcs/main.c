#include "main.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
  int *p=NULL; 
  *returnSize=0; 
  for(int i=0; i<numsSize-1; i++){
    for(int j=i+1; j<numsSize; j++){
      if(target==(nums[i]+nums[j])){
	*returnSize=2; 
        p=malloc(sizeof(int)*(*returnSize));
        p[0]=i; 
	p[1]=j; 
        return p; 
      }
    }
  }
  return p; 
}

int main(int argc, char *argv[]){
  int nums[]={2, 7, 11, 15};
  int returnSize=0; 
  int *returnNums=NULL; 
  returnNums=twoSum(nums, (sizeof(nums)/sizeof(int)), 9, &returnSize);
  printf("[");
  for(int i=0; i<returnSize; i++){
    printf("%d", returnNums[i]);
    if(i!=returnSize-1){
      printf(", ");
    }
  }
  printf("]\n");
  return 0; 
}
