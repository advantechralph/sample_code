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
  sem_t *sem;
  sem = sem_open("shmname", O_CREAT|O_EXCL, 0666, 1234);
  sem_unlink ("shmname");     
  return 0;
}
