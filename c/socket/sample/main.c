#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ioctl.h>

int main(int argc, char *argv[]){
  pid_t fid=0; 
  if((fid=fork())==0){
    printf("%s, %d: \n", __FUNCTION__, __LINE__);
    const char unix_fd_path[]="unix"; 
    int unix_fd=socket(PF_UNIX, SOCK_STREAM, 0);
    int max_fd=-1, cli_fd=-1; 
    struct sockaddr_un sun;
    fd_set set;
    FD_ZERO(&set);
    struct timeval expire, now;
    bzero(&sun,sizeof(sun));
    sun.sun_family=AF_UNIX;
    strcpy(sun.sun_path, unix_fd_path);
    unlink(unix_fd_path);
    bind(unix_fd, (struct sockaddr *)&sun, sizeof(sun));
    listen(unix_fd, 5);
    expire.tv_sec=10; 
    expire.tv_usec=0; 
    printf("%s, %d: child...\n", __FUNCTION__, __LINE__);
    gettimeofday(&now, NULL);
    printf("sec: %ld, usec: %ld\n", now.tv_sec, now.tv_usec);
    max_fd=unix_fd; 
    printf("max_fd: %d\n", max_fd);
    FD_SET(unix_fd, &set);
    while(1){
      fd_set set_bkp;
      set_bkp=set; 
      switch(select(max_fd+1, &set, NULL, NULL, (expire.tv_sec==0&&expire.tv_usec==0)?NULL:&expire)){
        case 0: 
          expire.tv_sec=10; 
          expire.tv_usec=0; 
          printf("%s, %d: socket timeout!!\n", __FUNCTION__, __LINE__);
          gettimeofday(&now, NULL);
          printf("sec: %ld, usec: %ld\n", now.tv_sec, now.tv_usec);
	  set=set_bkp; 
          break; 
        case -1: 
          printf("%s, %d: socket error!!\n", __FUNCTION__, __LINE__);
          break; 
        default: 
          printf("%s, %d: check isset...\n", __FUNCTION__, __LINE__);
	  if(FD_ISSET(unix_fd, &set)){
            struct sockaddr_un remoteaddr;
            socklen_t addrlen=sizeof(remoteaddr);
            cli_fd=accept(unix_fd, (struct sockaddr *)&remoteaddr, &addrlen);
	    max_fd=cli_fd; 
            printf("new Unix client: \n");
	    FD_SET(cli_fd, &set);
#if 0
	    sleep(5);
	    FD_CLR(cli_fd, &set);
	    close(cli_fd); 
#endif
	    continue; 
	  }
	  if(FD_ISSET(cli_fd, &set)){
            int count=0; 
	    ioctl(cli_fd, FIONREAD, &count);
            printf("Unix client: data coming, size: %d\n", count);
	    unsigned char *p=malloc(count+1);
	    if(p>0){
	      read(cli_fd, p, count);
	      p[count]='\0'; 
	      printf("recv: '%s'\n", p);
	      if(p>0) free(p);
	    }else{
	      printf("recv: '");
              for(int i=0; i<count; i++){
                char c=0; 
                read(cli_fd, &c, 1);
		printf("%c", c);
	      }
	      printf("'\n");
	    }
	  }
          break; 
      }
      usleep(50);
    }
    if(unix_fd>0) close(unix_fd);
    if(cli_fd>0) close(cli_fd);
  }else{
    printf("%s, %d: parent...\n", __FUNCTION__, __LINE__);
  }
  return 0; 
}

