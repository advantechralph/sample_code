#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
class Node {
public:
  Node(void); 
  Node(float);
  Node(float,unsigned long);
  int isInit(void);
  int isLast(void);
  int canAdd(void);
  void dump(void);
  void dumpNodes(void);
  void dumpNodes(Node *);
  void addNode(void);
  void addNode(float);
  void addNode(float,unsigned long);
  void reverseNodes(void);
  void reverseNodes(Node *,Node *);
  void deleteNodes(void);
  void deleteNodes(Node *);
protected:
  Node *head; 
  Node *next; 
  Node *last; 
  float temp;
  unsigned long timestamp; 
  int init; 
  void info(void);
private:
};
void Node::info(void){
  printf("Node(%p)\n", this);
}
Node::Node(void):init(1){
  info();
  temp=0; 
  timestamp=0; 
  head=this;
  next=NULL; last=NULL;
}
Node::Node(float _temp):init(1){
  info();
  temp=_temp; 
  timestamp=0; 
  head=this;
  next=NULL; last=NULL;
}
Node::Node(float _temp, unsigned long _timestamp):init(1){
  info();
  temp=_temp; 
  timestamp=_timestamp; 
  head=this;
  next=NULL; last=NULL;
}
int Node::isInit(void){
  return init; 
}
int Node::isLast(void){
  return ((next==NULL)&&(last==NULL))?1:0; 
}
int Node::canAdd(void){
// next: non-NULL, last: NULL, it means the middle nodes, and can NOT add...
  return ((next!=NULL)&&(last==NULL))?0:1;
}
void Node::dump(void){
  printf("Node(%p): temp(%.3f), timestamp(%lu), head(%p), last(%p)\n", 
    this, temp, timestamp, head, last);
}
void Node::dumpNodes(void){
  dumpNodes(this->head);
}
void Node::dumpNodes(Node *pN){
  Node *pTmp=NULL; 
  if(pN){
    pN->dump();
    pTmp=pN->next;
  }else{
    this->dump();
    pTmp=this->next; 
  }
  if(pTmp) dumpNodes(pTmp);
}
void Node::addNode(void){
  if(!canAdd()) return; 
  Node *pn=new Node();
  pn->head=this->head;
  if(last){
    last->next=pn; 
    last=pn; 
  }else{
    next=pn; 
    last=pn; 
  }
}
void Node::addNode(float _temp){
  if(!canAdd()) return; 
  Node *pn=new Node();
  pn->head=this->head;
  pn->temp=_temp;
  if(last){
    last->next=pn; 
    last=pn; 
  }else{
    next=pn; 
    last=pn; 
  }
}
void Node::addNode(float _temp, unsigned long _timestamp){
  if(!canAdd()) return; 
  Node *pn=new Node();
  pn->head=this->head;
  pn->temp=_temp;
  pn->timestamp=_timestamp;
  if(last){
    last->next=pn; 
    last=pn; 
  }else{
    next=pn; 
    last=pn; 
  }
}
void Node::reverseNodes(void){
  reverseNodes(NULL, this->head);
}
void Node::reverseNodes(Node *pPrev, Node *pCurr){
  if(!pCurr) return;
  Node *pTmp=pCurr->next;
  pCurr->next=pPrev; 
  if(pPrev){
    pCurr->head=pPrev->head;
    pCurr->last=pPrev->last;
    pPrev->last=NULL;
  }else{
    pCurr->head=pCurr->last; 
    pCurr->last=pCurr; 
  }
  if(pTmp) reverseNodes(pCurr, pTmp);
}
void Node::deleteNodes(void){
  deleteNodes(this->head);
}
void Node::deleteNodes(Node *pN){
  Node *pTmp=NULL; 
  if(pN){
    printf("Delete Node(%p), temp: %.3f\n", pN, pN->temp);
    pTmp=pN->next; 
    delete pN; 
  }else{
    printf("Delete Node(%p), temp: %.3f\n", this, this->temp);
    pTmp=this->next; 
    delete this; 
  }
  if(pTmp) deleteNodes(pTmp);
}
int main(void){
  Node *pn[3]; 
  for(int i=0; i<3; i++){
    printf("pn%d Create Node...\n", i);
    if(i==0){
      pn[i]=new Node();
    }else if(i==1){
      pn[i]=new Node((float)0.25);
    }else if(i==2){
      pn[i]=new Node((float)0.39, (unsigned long)1122334455);
    }
  }
  for(int i=0; i<3; i++){
    printf("pn%d Dump Nodes...\n", i);
    pn[i]->dumpNodes();
  }
  printf("pn%d Add Nodes...\n", 2);
  pn[2]->addNode(0.41, 2233445566);
  pn[2]->addNode(0.98, 3344556677);
  printf("pn%d Dump Nodes...\n", 2);
  pn[2]->dumpNodes();
  printf("pn%d Reverse Nodes...\n", 2);
  pn[2]->reverseNodes(NULL, pn[2]);
  printf("pn%d Dump Nodes...\n", 2);
  pn[2]->dumpNodes();
  for(int i=0; i<3; i++){
    printf("pn%d Delete Nodes...\n", i);
    pn[i]->deleteNodes();
  }
  return 0; 
}

