#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h> //O_CREATE O_EXCL
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>

int main() {
  char file_name[] = "share_file";
  char mutex_name1[] = "psmutex1";
  char mutex_name2[] = "psmutex2";
  sem_t *mutex1 = sem_open(mutex_name1, O_EXCL);
  sem_t *mutex2 = sem_open(mutex_name2, O_EXCL);

  for (int i = 0; i < 5; i++) {
    sem_wait(mutex2);
    //printf("semshare2  pid = %d\n", getpid());
    FILE *fp = fopen(file_name, "a+");
    fprintf(fp, "(%d).semshare2  pid = %d\n", i,getpid());
    fclose(fp);
    sem_post(mutex1);
  }
  return 0;
}

