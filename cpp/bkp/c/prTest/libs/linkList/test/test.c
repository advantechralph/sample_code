#include "linkList.h"
void test(void){
  node *pn=NULL;
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  linkListDummy();
  dumpNow();
  pn=_createNewNodeWithRandKey();
  if(pn){
    printf("new node key: %s\n", (char *)pn->key);
    _freeNode(pn);
  }
  dumpNow();
}
