#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */

int main(int argc, char *argv[]){
  int fd = shm_open("shmname", O_CREAT, O_RDWR);
#if 0
  ftruncate(fd, sizeof(sem_t));
  sem_t *sem = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE,
    MAP_SHARED, fd, 0);
  sem_init(sem, 1, 1);
#endif
  return 0;
}
