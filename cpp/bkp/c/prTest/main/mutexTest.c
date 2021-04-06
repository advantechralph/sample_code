#include "basic.h"
#include "timer.h"
static pthread_t t[5];
static pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;  
static void *child(void *data);
void mutexTest(void){
  char c=0; 
  pthread_mutex_init(&mutex,NULL); 
  pthread_create(&t[0], NULL, (void *)child, "child");
  while(1){
    printf("\nplease enter your key...\n");
    c=getchar();
    printf("key is '%c'\n", c);
    if(c=='m'){
      printf("mutex command!!!\n");
      pthread_mutex_lock(&mutex);
      printf("%s, %d: mutex enter!!\n", __FUNCTION__, __LINE__);
      sleep(3);
      printf("%s, %d: mutex exit!!\n", __FUNCTION__, __LINE__);
      pthread_mutex_unlock(&mutex);
      usleep(1);
    }
  }
}
static void *child(void *data){
  while(1){
    pthread_mutex_lock(&mutex);
    printf("%s, %d: mutex enter!!\n", __FUNCTION__, __LINE__);
    sleep(5); 
    printf("%s, %d: mutex exit!!\n", __FUNCTION__, __LINE__);
    pthread_mutex_unlock(&mutex);
    usleep(1);
  }
  pthread_exit(NULL); 
}
