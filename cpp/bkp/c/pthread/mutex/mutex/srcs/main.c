#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 計數器
int counter = 0;

// 加入 Mutex
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// 子執行緒函數
void* child(void *arg) {
  int id=*(int *)arg; 
  for(int i = 0;i < 3;++i) {
    //printf("id: %d, before pthread_mutex_lock\n", id);
    pthread_mutex_lock( &mutex1 ); // 上鎖
    int tmp = counter;
    sleep(1);
    counter = tmp + 1;
    printf("id: %d, Counter = %d\n", id, counter);
    pthread_mutex_unlock( &mutex1 ); // 解鎖
  }
  pthread_exit(NULL);
}

// 主程式
int main() {
  pthread_t t1, t2;
  int id[]={1,2}; 
  pthread_create(&t1, NULL, child, (void *)&id[0]);
  pthread_create(&t2, NULL, child, (void *)&id[1]);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}
