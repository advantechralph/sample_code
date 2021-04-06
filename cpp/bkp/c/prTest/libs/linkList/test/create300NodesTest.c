#include "linkList.h"
void create300NodesTest(void){
  node *ph=NULL, *pcurr=NULL;
  int i=0, n=300; 
  unsigned long start=0, end=0; 
  start=getNow();
  dumpNow();
  for(i=0; i<n; i++){
    node *pn=NULL;
    pn=_createNewNodeWithRandKey();
    if(!pn) goto err;
//    printf("id: %d, key: %s\n", i, (char *)pn->key);
    if(!pcurr){
      pcurr=pn;
      ph=pcurr;
    }else{
      pcurr->next=pn; 
      pn->prev=pcurr; 
      pcurr=pn;
    }
  }
  end=getNow();
  printf("create 300 nodes time: %lu\n", end-start);
  i=0;
  // scan
  start=getNow();
  for(pcurr=ph; pcurr; pcurr=pcurr->next){
    //printf("id: %d, key: %s\n", i, (char *)pcurr->key);
    i++;
  }
  end=getNow();
  printf("scan time: %lu\n", end-start);
  return; 
err:
  printf("%s, %d: err\n", __FUNCTION__, __LINE__);
}
