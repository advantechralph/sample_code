#include "main.h"
#if 0
#ifdef  __cplusplus
extern  "C" {
#endif 
#include <stdio.h>
#include <stdlib.h>
#ifdef  __cplusplus
}
#endif 
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef struct ListNode ListNode; 

class Solution {
public:
  void dump(ListNode *pl){ ListNode *p=NULL; cout << "("; for(p=pl; p; p=p->next){ cout << p->val; if(p->next) cout << " -> "; } cout << ")" << endl; }
  void dump(const char *prefix, ListNode *pl){ ListNode *p=NULL; cout << prefix << "("; for(p=pl; p; p=p->next){ cout << p->val; if(p->next) cout << " -> "; } cout << ")" << endl; }
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int ret=0; 
    ListNode *pSum=NULL;
    int carry=0, sum=0, digit=0; 
    dump("l1: ", l1);
    dump("l2: ", l2);
    for(ListNode *p=l1, **pps=&pSum;;digit++){
      sum=carry+((*pps)?(*pps)->val:0)+(p?p->val:0); 
      carry=sum/10; 
      if(sum>0||digit==0||(p&&p->next)){
        if(!*pps){ 
          *pps=new ListNode();
	  if(!pSum) pSum=*pps;
	}
	(*pps)->val=(sum%10); 
      }else break;  
      if(p) p=p->next; 
      if(*pps) pps=&((*pps)->next); 
    }
    sum=0; carry=0; digit=0;  
    for(ListNode *p=l2, **pps=&pSum;;digit++){
      sum=carry+((*pps)?(*pps)->val:0)+(p?p->val:0); 
      carry=sum/10; 
      if(sum>0||digit==0||(p&&p->next)){
        if(!*pps){ 
          *pps=new ListNode();
	  if(!pSum) pSum=*pps;
	}
	(*pps)->val=(sum%10); 
      }else break; 
      if(p) p=p->next; 
      if(*pps) pps=&((*pps)->next); 
    }
    sum=0; carry=0; digit=0;  
    dump("sum: ", pSum);
    return pSum;  
  }
};

int main(int argc, char *argv[]){
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  Solution().addTwoNumbers(
    new ListNode(0),  
    new ListNode(7, new ListNode(3))
    ); 
  Solution().addTwoNumbers(
    new ListNode(5), 
    new ListNode(5)
    );
  Solution().addTwoNumbers(
    new ListNode(2, new ListNode(4, new ListNode(3))), 
    new ListNode(5, new ListNode(6, new ListNode(4)))
    );
  Solution().addTwoNumbers(
    NULL, 
    new ListNode(2, new ListNode(4))
    );
  Solution().addTwoNumbers(
    new ListNode(9, new ListNode(8)),
    new ListNode(1)
    );
  Solution().addTwoNumbers(
    new ListNode(9),
    new ListNode(9, new ListNode(9))
    );
  Solution().addTwoNumbers(
    new ListNode(9, new ListNode(9)), 
    new ListNode(9)
    );
  Solution().addTwoNumbers(
    new ListNode(8, new ListNode(9, new ListNode(9))), 
    new ListNode(2)
    );
  Solution().addTwoNumbers(
    new ListNode(1, new ListNode(0, new ListNode(9))), 
    new ListNode(5, new ListNode(7, new ListNode(8)))
    );
  return 0; 
}

