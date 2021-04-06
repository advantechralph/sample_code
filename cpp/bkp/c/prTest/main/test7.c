#include "basic.h"
#include "timer.h"
typedef struct Node Node; 
struct Node {
  unsigned long timestamp; 
  float temp;
  struct Node *next;
};
typedef struct List List; 
struct List {
  Node *head; 
  Node *curr; 
}; 
typedef struct Pool Pool; 
struct Pool {
  unsigned long timestamp; 
  float temp; 
}; 
static Node *allocNode(void); 
static void generateNodes(Node **, int num);
static void addNode(Node **);
static void dumpNodes(Node *);
static void dumpNodesFull(Node *);
static void deleteNodes(Node **);
static void lastNode(Node *, Node **);
static void addNodeTest(int num);
static float genRandFloat(float, float);
static int genRandInt(int, int);
static void genRandIntTest(void);
static void timer1(int);
static void timer2(int);
static pthread_t t[5]; 
static sem_t sem[5]; 
static pthread_mutex_t mutex[5]; 
// threads
static void *PoolChild(void *);
static void *ListChild(void *);
static void *SwitchChild(void *);
static void *DebugChild(void *);
// threads end
static Pool *pPoolTab=NULL;
#define PoolTabSize 2
void test7_1(void){
  Node *head = NULL;
  sem_init(&sem[0], 0, 0);
  sem_init(&sem[1], 0, 0);
  sem_init(&sem[2], 0, 0);
  sem_init(&sem[3], 0, 0);
  pthread_mutex_init(&mutex[0], NULL); 
  pthread_mutex_init(&mutex[1], NULL); 
  pthread_create(&t[0], NULL, (void *)PoolChild, "PoolChild"); 
  pthread_create(&t[1], NULL, (void *)ListChild, "ListChild"); 
  pthread_create(&t[2], NULL, (void *)SwitchChild, "SwitchChild"); 
  pthread_create(&t[3], NULL, (void *)DebugChild, "DebugChild"); 
  installRTHandler(SIGRTMIN, timer1);
  installRTHandler(SIGRTMIN+1, timer2);
  //createRTTimer(SIGRTMIN, 0, 100*1000000);
  createRTTimer(SIGRTMIN, 1, 0);
  createRTTimer(SIGRTMIN+1, 6, 0);
  char c=0; 
  while(1){
    c=getchar();
    if(c=='d'){
      printf("debug!!!\n");
    }
    sleep(1);
  }
}
void test7_2(void){
  Node *head=NULL; 
  for(int i=0; i<20; i++){
    Node *last=NULL; 
    addNode(&head);
    lastNode(head, &last);
    if(last){
      last->timestamp=getNow();
      last->temp=genRandInt(0,100);
    }
  }
  dumpNodesFull(head);
  deleteNodes(&head);
}
void test7(void){
  test7_2();
}
static void *PoolChild(void *data){
  pPoolTab=malloc(sizeof(Pool)*PoolTabSize);
  memset(pPoolTab, 0, sizeof(Pool)*PoolTabSize);
  while(1){
    unsigned long start=0, end=0; 
    sem_wait(&sem[0]);
    start=getNow();
#if 0
    for(int i=0; i<genRandInt(1,PoolTabSize); i++){
#else
    for(int i=0; i<PoolTabSize; i++){
#endif
      unsigned long timestamp=getNow();
      Pool *pP=&pPoolTab[i]; 
      pP->timestamp=timestamp; 
      pP->temp=genRandFloat(0,100);
    }
    end=getNow();
    printf("PoolChild start: %lu, spent %lu (μs)\n", start, (end-start));
  }
  pthread_exit(NULL); 
}
static List *pListTab = NULL; 
static List *pListTab2 = NULL; 
#define ListTabSize PoolTabSize
static void *ListChild(void *data){
  pListTab = malloc(sizeof(List)*ListTabSize);
  pListTab2 = malloc(sizeof(List)*ListTabSize);
  memset(pListTab, 0, sizeof(List)*ListTabSize);
  memset(pListTab2, 0, sizeof(List)*ListTabSize);
  while(1){
    unsigned long start=0, end=0; 
    sem_wait(&sem[1]);
    start=getNow();
    pthread_mutex_lock(&mutex[0]);
    for(int i=0; i<ListTabSize; i++){
      Pool *pP=&pPoolTab[i]; 
      List *pL=&pListTab[i]; 
      Node *pN=allocNode();
      if(pN){
        pN->timestamp=pP->timestamp; 
	pN->temp=pP->temp; 
        if(!pL->head){
          pL->curr=pN; 
	  pL->head=pN; 
        }else{
          pL->curr->next=pN; 
	  pL->curr=pN; 
        }
      }
    }
    pthread_mutex_unlock(&mutex[0]);
    end=getNow();
    printf("ListChild start: %lu, spent %lu (μs)\n", start, (end-start));
  }
  pthread_exit(NULL); 
}
static void *SwitchChild(void *data){
  while(1){
    unsigned long start=0, end=0; 
    sem_wait(&sem[2]);
    pthread_mutex_lock(&mutex[0]);
    start=getNow();
    for(int i=0; i<ListTabSize; i++){
      List *pL=&pListTab[i]; 
      List *pL2=&pListTab2[i]; 
      Node *pN=pL->head; 
      pL2->head=pL->head; 
      pL2->curr=pL->curr; 
      pL->head=NULL; 
      pL->curr=NULL; 
    }
    pthread_mutex_unlock(&mutex[0]);
    end=getNow();
    printf("SwitchChild start: %lu, spent %lu (μs)\n", start, (end-start));
  }
  pthread_exit(NULL); 
}
static void *DebugChild(void *data){
  while(1){
    unsigned long start=0, end=0; 
    int empty=1; 
    sem_wait(&sem[3]);
    pthread_mutex_lock(&mutex[0]);
    start=getNow();
    for(int i=0; i<ListTabSize; i++){
      List *pL2=&pListTab2[i]; 
      if(pL2->head){
        empty=0; 
        Node *pN=pL2->head; 
        printf("\nList %d: ", i);
        dumpNodes(pN);
        deleteNodes(&pN);
        pL2->head=NULL; 
        pL2->curr=NULL; 
      }
    }
    if(!empty) printf("\n");
    pthread_mutex_unlock(&mutex[0]);
    end=getNow();
    printf("DebugChild start: %lu, spent %lu (μs)\n", start, (end-start));
  }
  pthread_exit(NULL); 
}
static int sem2Count=0; 
#define sem2Mod 10
static void timer1(int s){
  sem_post(&sem[0]);
  sem_post(&sem[1]);
  if((sem2Count%sem2Mod)==(sem2Mod-1)){
    sem_post(&sem[2]);
    sem2Count=0; 
  }else{
    sem2Count++; 
  }
  sem_post(&sem[3]);
}
static void timer2(int s){
}
static float genRandFloat(float min, float max){
  struct timeval now; 
  gettimeofday(&now, NULL);
  srand(now.tv_usec); 
  return ((float)((float)rand()/(float)(RAND_MAX))*(max-min)+min);
}
static int genRandInt(int min, int max){
  return ((genRandFloat(min, max+1)*10)/10);
}
static void genRandIntTest(void){
  int min=0, max=5, num=2000;
  for(int i=0; i<num; i++){
    int n = genRandInt(min,max);
    printf("%d  ", n);
    if(n>5||n<0){
      printf("num: %d, error, n is %d!!", num, n);
      break;
    }
  }
}
static void generateNodes(Node **head, int num){
  Node *temp;
  for (int i = 0; i < num; i++){
    temp = (Node *)malloc(sizeof(Node));
    temp->temp = genRandFloat(0, 100);
    if (*head == NULL){
      *head = temp;
      (*head)->next = NULL;
    }else{
      temp->next = *head;
      *head = temp;
    }
  }
}
static Node *allocNode(void){
  Node *pN=malloc(sizeof(Node));
  memset(pN, 0, sizeof(Node));
  return pN; 
} 
static void addNode(Node **head){
  Node *n;
  if (*head == NULL){
    n = (Node *)malloc(sizeof(Node));
    memset(n, 0, sizeof(Node));
//    n->temp = genRandFloat(0, 100);
    *head = n; 
    return; 
  }else{
    if((*head)->next == NULL){
      n = (Node *)malloc(sizeof(Node));
      memset(n, 0, sizeof(Node));
//      n->temp = genRandFloat(0, 100);
      (*head)->next = n;
      return; 
    }
  }
  addNode(&((*head)->next));
}
static void dumpNodesFull(Node *head){
  printf("{temp:%.3f,timestamp:%lu}\n", head->temp, head->timestamp);
  if (head->next == NULL){
    return;
  }
  dumpNodesFull(head->next);
}
static void dumpNodes(Node *head){
  printf("%.3f  ", head->temp);
  if (head->next == NULL){
    return;
  }
  dumpNodes(head->next);
}
static void lastNode(Node *head, Node **last){
  if (head->next == NULL){
    *last = head; 
  }else{
    lastNode(head->next, last);
  }
}
static void deleteNodes(Node **head){
  Node *temp;
  while (*head != NULL){
    temp = *head;
    *head = (*head)->next;
    free(temp);
  }
}
static void addNodeTest(int num){
  Node *head=NULL; 
  unsigned long start=0, end=0; 
  start=getNow();
  for(int i=0; i<num; i++)
    addNode(&head);
  end=getNow();
  printf("addNodeTest start: %lu, spent %lu (μs)\n", start, (end-start));
  start=getNow();
  addNode(&head);
  end=getNow();
  printf("addNodeTest start: %lu, spent %lu (μs)\n", start, (end-start));
  deleteNodes(&head);
  //dumpNodes(head);
}
