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

  sem_t *mutex1 = sem_open(mutex_name1, O_CREAT, 0644, 0);
  sem_t *mutex2 = sem_open(mutex_name2, O_CREAT, 0644, 0);

  for (int i = 0; i < 5; i++) {
    sem_post(mutex2);
    sem_wait(mutex1);
    FILE *fp = fopen(file_name, "a+");
    fprintf(fp, "(%d).semshare1  pid = %d\n", i,getpid());
    fclose(fp);
  }
  sleep(3);
  sem_close(mutex1);
  sem_close(mutex2);
  sem_unlink(mutex_name1);
  sem_unlink(mutex_name2);
  return 0;
}

