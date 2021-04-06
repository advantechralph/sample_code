#include "main.h"
#include "timer.h"
static sem_t test3Sem; 
//static char semname[]="semTest1"; 
void *createNodesThread(void* data) {
  char *str = (char*) data; 
  for(int i=0; i<10; i++) {
    int sem_count=0; 
    sem_getvalue(&test3Sem, &sem_count);
    printf("befor: sem_wait, sem_count: %d\n", sem_count); 
    sem_wait(&test3Sem);
    printf("%s: %d\n", str, i); 
    sleep(2);
  }
  pthread_exit(NULL); 
}
void test3(void){
  pthread_t t; 
  sem_init(&test3Sem, 0, 0);
  //sem_t *sem=sem_open(semname, O_CREAT, 0644, 0);
  pthread_create(&t, NULL, createNodesThread, "createNodesThread"); 
  for(int i=0; i<10; i++) {
    printf("Master: %d\n", i); 
    sem_post(&test3Sem);
    sleep(1);
  }
  //sem_close(sem);
  //sem_unlink(semname);
  pthread_join(t, NULL); 
}
