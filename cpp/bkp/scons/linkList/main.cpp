#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
class Node {
public:
  Node(); 
protected:
  Node *next; 
private:
};

typedef struct node node; 
struct node {
  float a;
  struct node *next;
};
static void generateNodes(node **, int num);
static void addNode(node **);
static void displayNodes(node *);
static void deleteNodes(node **);
static void displayLastNode(node *);
static void lastNode(node *, node **);
static float genRand(float, float);
static void reverseNodes(node **);
int main(void){
  node *head = NULL;
  generateNodes(&head, 10);
  displayNodes(head);
  displayLastNode(head);
  addNode(&head);
  displayNodes(head);
  displayLastNode(head);
  reverseNodes(&head);
  deleteNodes(&head);
  return 0; 
}
static void reverseNodes(node **head){
}
static void generateNodes(node **head, int num){
  node *temp;
  for (int i = 0; i < num; i++){
    temp = (node *)malloc(sizeof(node));
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
static void addNode(node **head){
  node *n;
  if (*head == NULL){
    n = (node *)malloc(sizeof(node));
    memset(n, 0, sizeof(node));
    n->a = genRand(0, 100);
    *head = n; 
    return; 
  }else{
    if((*head)->next == NULL){
      n = (node *)malloc(sizeof(node));
      memset(n, 0, sizeof(node));
      n->a = genRand(0, 100);
      (*head)->next = n;
      return; 
    }
  }
  addNode(&((*head)->next));
}
static void displayNodes(node *head){
  printf("%f  ", head->a);
  if (head->next == NULL){
    return;
  }
  displayNodes(head->next);
}
static void lastNode(node *head, node **last){
  if (head->next == NULL){
    *last = head; 
  }else{
    lastNode(head->next, last);
  }
}
static void deleteNodes(node **head){
  node *temp;
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
static void displayLastNode(node *head){
  node *end = NULL; 
  lastNode(head, &end);
  if(end){
    printf("\nend: %f\n", end->a);
  }
}
