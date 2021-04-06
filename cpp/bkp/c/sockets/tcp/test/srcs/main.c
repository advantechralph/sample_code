#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc , char *argv[]){
  int sockfd=0;
  int yes=1;

  fd_set fds;
  FD_ZERO(&fds);

  sockfd=socket(AF_INET, SOCK_STREAM , 0);

  if(sockfd==-1){
    printf("Fail to create a socket.");
  }

  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

  printf("%s, %d: sockfd: %d\n", __FUNCTION__, __LINE__, sockfd);
  FD_SET(sockfd, &fds);

  int fdmax;
  fdmax=sockfd; 
  printf("%s, %d: fdmax: %d\n", __FUNCTION__, __LINE__, fdmax);

  struct sockaddr_in serveraddr;
  bzero(&serveraddr, sizeof(serveraddr));

  serveraddr.sin_family = PF_INET;
  serveraddr.sin_addr.s_addr = INADDR_ANY;
  serveraddr.sin_port = htons(8700);
  bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
  listen(sockfd,5);

  while(1){
    int i = 0;
    fd_set fds_sel;
    fds_sel=fds;
    printf("%s, %d: before select!!\n", __FUNCTION__, __LINE__);
    if(select(fdmax+1, &fds_sel, NULL, NULL, NULL) == -1) {
      printf("%s, %d: select error!!\n", __FUNCTION__, __LINE__);
      exit(4);
    }
    printf("%s, %d: after select!!\n", __FUNCTION__, __LINE__);
    for(i=0; i<fdmax+1; i++){
      if(FD_ISSET(i, &fds_sel)){
        printf("%s, %d: select fd: %d!!\n", __FUNCTION__, __LINE__, i);
        if(i==sockfd){
	  int newfd=0;
          struct sockaddr_in cliaddr;
	  char msg[]="Welcome!!\n";
	  socklen_t addrlen;
          addrlen=sizeof(cliaddr);
	  newfd=accept(sockfd, (struct sockaddr *)&cliaddr, &addrlen);
	  FD_SET(newfd, &fds);
          if(newfd>fdmax){
            fdmax=newfd;
          }
          printf("%s, %d: accept newfd: %d!!\n", __FUNCTION__, __LINE__, newfd);
          send(newfd, msg, sizeof(msg), 0);
	}else{
          char buf[128]={0};
	  int nbytes=0;
          if((nbytes=recv(i, buf, sizeof buf, 0)) <= 0){
            if(nbytes==0){
              printf("%s, %d: socket %d hang up\n", __FUNCTION__, __LINE__, i);
	    }else{
              printf("%s, %d: socket %d recv error\n", __FUNCTION__, __LINE__, i);
	    }
            close(i);
	    FD_CLR(i, &fds);
	  }else{
            printf("%s, %d: recv: %s", __FUNCTION__, __LINE__, buf);
            int j=0; 
	    for(j=0;j<fdmax+1;j++){
              if(FD_ISSET(j,&fds)){
                if(j!=sockfd&&j!=i){
                  if (send(j, buf, nbytes, 0) == -1) {
                    printf("%s, %d: socket %d send error\n", __FUNCTION__, __LINE__, j);
                  }
		}
	      }
	    }
	  }
	}
      }
    }
    //exit(0);
  }
#if 0
  while(1){
    forClientSockfd = accept(sockfd, 
		        (struct sockaddr*) &clientInfo, 
			(socklen_t *)&addrlen);
    send(forClientSockfd,message,sizeof(message),0);
    recv(forClientSockfd,inputBuffer,sizeof(inputBuffer),0);
    printf("Get:%s\n",inputBuffer);
  }
#endif
  return 0;
}
