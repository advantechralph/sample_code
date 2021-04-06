#include "basic.h"
#include "timer.h"
typedef struct Node Node; 
struct Node {
  float a;
  struct Node *next;
};
static void generateNodes(Node **, int num);
static void displayNodes(Node *);
static void deleteNodes(Node **);
static void lastNode(Node *, Node **);
static float genRand(float, float);
static sem_t sem1; 
static pthread_t t1; 
static void *child1(void *);
static void timer1(int);
void test6(void){
  Node *head = NULL;
  sem_init(&sem1, 0, 0);
  pthread_create(&t1, NULL, (void *)child1, "child1"); 
  installRTHandler(SIGRTMIN, timer1);
  //createRTTimer(SIGRTMIN, 0, 500*1000*1000);
  createRTTimer(SIGRTMIN, 5, 0);
  generateNodes(&head, 10);
  displayNodes(head);
  Node *end = NULL; 
  lastNode(head, &end);
  if(end){
    printf("\nend: %f\n", end->a);
  }else{
    printf("\nend: null!!!\n");
  }
  deleteNodes(&head);
  while(1){
    sleep(1);
  }
}
static void *child1(void *data){
  //char *str = (char *)data; 
  while(1){
    sem_wait(&sem1);
    dumpNow();
  }
  pthread_exit(NULL); 
}
static void timer1(int s){
  sem_post(&sem1);
}
static void generateNodes(Node **head, int num){
  Node *temp;
  for (int i = 0; i < num; i++){
    temp = (Node *)malloc(sizeof(Node));
    temp->a = genRand(0, 100);
    if (*head == NULL){
      *head = temp;
      (*head)->next = NULL;
    }else{
      temp->next = *head;
      *head = temp;
    }
  }
}
static void displayNodes(Node *head){
  printf("%f  ", head->a);
  if (head->next == NULL){
    return;
  }
  displayNodes(head->next);
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
float genRand(float min, float max){
  struct timeval now; 
  gettimeofday(&now, NULL);
  srand(now.tv_usec); 
  return ((float)((float)rand()/(float)(RAND_MAX))*(max-min)+min);
}
