#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h> //O_CREATE O_EXCL
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>

int main() {
  char semname[] = "psmutex1";
  sem_t *sem = sem_open(semname, O_CREAT, 0644, 0);
  printf("%s, %d: before wait...\n", __FUNCTION__, __LINE__);
  sem_wait(sem);
  printf("%s, %d: after wait...\n", __FUNCTION__, __LINE__);
  printf("%s, %d: sleep 5...\n", __FUNCTION__, __LINE__);
  sleep(5);
  sem_close(sem);
  sem_unlink(semname);
  return 0;
}

