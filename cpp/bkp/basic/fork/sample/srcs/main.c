#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void parent_trap(int sig) {fprintf(stderr, "They got back together!\n");}
void child_trap(int sig) {fprintf(stderr, "Caught 'INT' signal in CHILD.\n");}
int main(void){
  pid_t pid; 
  int status;
  pid=fork();
  if(pid==0){
    signal(SIGINT, &child_trap);
    printf("child: before sleep 5s...\n");
    sleep(5);
    printf("child: after sleep 5s\n");
    printf("child: before exit 0x12345678...\n");
    exit(0x12345678);
  }else{
    signal(SIGINT, &parent_trap);
    //wait(NULL);
    waitpid((pid_t)pid, &status, 0);
    printf("parent: wait: status: 0x%x\n", status);
    printf("parent: getpid : %d  getppid : %d \n",getpid(),getppid());
    //waitpid((pid_t)pid, &status, 0);
  }
  return 0;
}

