#include "main.h"
using namespace std;
class Timestamp {
public:
  Timestamp(){}
  ~Timestamp(){}
  unsigned long now(void){
    struct timeval _now;
    gettimeofday(&_now, NULL);
    return _now.tv_sec*1000000+_now.tv_usec;
  }
  char *now(char *_buf, int flag){
    struct timeval _now;
    gettimeofday(&_now, NULL);
    struct tm *ptm=localtime(&_now.tv_sec);
    if(flag==1)
      sprintf((_buf==NULL?_str:_buf), "%04d-%02d-%02d %02d:%02d:%02d:%06ld", ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, _now.tv_usec);
    else
      sprintf((_buf==NULL?_str:_buf), "%04d-%02d-%02d %02d:%02d:%02d", ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
    return (_buf==NULL?_str:_buf); 
  }
  void dump(int flag=0){
    cout << "now: " << now(NULL, flag) << endl; 
  }
  void test1(void){
    dump(0);
    dump(1);
    cout << "now: " << now() << endl; 
  }
private:
  char _str[128]; 
};
void socketCliTest(void){
  int sockfd = 0;
  sockfd = socket(AF_INET , SOCK_STREAM , 0);
  if (sockfd == -1){
    printf("Fail to create a socket.");
  }
  struct sockaddr_in info;
  bzero(&info,sizeof(info));
  info.sin_family = PF_INET;
  info.sin_addr.s_addr = inet_addr("127.0.0.1");
  info.sin_port = htons(8700);
  int err = connect(sockfd,(struct sockaddr *)&info,sizeof(info));
  if(err==-1){
    printf("Connection error");
  }
  char message[] = {"Hi there"};
  char receiveMessage[100] = {};
  send(sockfd,message,sizeof(message),0);
  recv(sockfd,receiveMessage,sizeof(receiveMessage),0);
  printf("%s",receiveMessage);
  printf("close Socket\n");
  close(sockfd);
}
void socketSvrTest(void){
  //socket的建立
  char inputBuffer[256] = {};
  char message[] = {"Hi,this is server.\n"};
  int sockfd = 0,forClientSockfd = 0;
  sockfd = socket(AF_INET , SOCK_STREAM , 0);

  if (sockfd == -1){
    printf("Fail to create a socket.");
  }

  //socket的連線
  struct sockaddr_in serverInfo;
  struct sockaddr_in clientInfo;
  socklen_t addrlen = sizeof(clientInfo);
  bzero(&serverInfo,sizeof(serverInfo));

  serverInfo.sin_family = PF_INET;
  serverInfo.sin_addr.s_addr = INADDR_ANY;
  serverInfo.sin_port = htons(8700);
  bind(sockfd,(struct sockaddr *)&serverInfo,sizeof(serverInfo));
  listen(sockfd,5);

  while(1){
    forClientSockfd = accept(sockfd,(struct sockaddr*) &clientInfo, &addrlen);
    send(forClientSockfd,message,sizeof(message),0);
    recv(forClientSockfd,inputBuffer,sizeof(inputBuffer),0);
    printf("Get:%s\n",inputBuffer);
  }
}
class Thread {
  pthread_t id; 
  void *(*func)(void *);
  void *data;
  string name;
public:
  void init(const char *_n, void *(*_f)(void *), void *_d){
    name=string(_n?_n:"noname");
    func=_f;
    data=_d;
  }
  Thread(void){init(NULL, NULL, NULL);}
  Thread(const char *_n, void *(*_f)(void *), void *_d){ 
    init(_n, _f, _d);
  }
  Thread(void *(*_f)(void *), void *_d){ 
    init(NULL, _f, _d);
  }
  virtual ~Thread(void){
  }
  virtual void info(void){
    cout << "Child(" << static_cast<void *>(this) <<  ")" << endl; 
    cout << "  name(" << name << ")" << endl; 
    cout << "  func(" << static_cast<void *>((void *)func) << ")" << endl; 
    cout << "  data(" << static_cast<void *>((void *)data) << ")" << endl; 
  }
  void create(void){
    pthread_create(&id, NULL, func, data);
  }
  void cancel(void){
    pthread_cancel(id);
  }
};
class Client:public Thread {
  int fd; 
  string name;
public:
  Client(){}
  Client(int _fd):fd(_fd){
    name=string("");
    name+="cli("; 
    name+=fd; 
    name+=")"; 
    init(name.c_str(), Handler, (void *)this);
    create();
  }
  ~Client(){
    cout << "Client(" << fd << "): destructor!!" << endl; 
  }
  static void *Handler(void *);
  virtual void info(void){
    cout << name << endl; 
  }
  int getfd(void){
    return fd;
  }
}; 
void *Client::Handler(void *data){
  pthread_detach(pthread_self());
  Client *pC=(Client *)data;
  while(1){
    pC->info();
    sleep(3);
  }
  pthread_exit(NULL);
}
class Server {
public:
  Server(int _port=8700):port(_port){
    cli_fd.assign(128,0);
    fd=socket(AF_INET, SOCK_STREAM, 0);
    bzero(&info,sizeof(info));
    info.sin_family=PF_INET;
    info.sin_addr.s_addr=INADDR_ANY;
    info.sin_port=htons(port);
    cout << "listen port " << port << "..." << endl; 
    int reuse=1; 
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int));
    bind(fd,(struct sockaddr *)&info,sizeof(info));
    listen(fd,5);
    FD_ZERO(&fds1);
    FD_ZERO(&fds2);
    Set(fd);
    Set(0);
    cli_fd.push_back(0);
    fds2=fds1;
    max=fd; 
    Expire(2,5);
  }
  ~Server(){}
  void Set(int _fd){
    FD_SET(_fd,&fds1);
  }
  void Clr(int _fd){
    FD_CLR(_fd,&fds1);
  }
  int Isset(int _fd){
    return FD_ISSET(_fd, &fds2); 
  }
  void Expire(int sec, int msec){
    e.tv_sec=sec; 
    e.tv_usec=msec*100000; 
  }
  int Select(void){
    struct timeval tv;
    tv=e;
    fds2=fds1;
    return select(max+1, &fds2, NULL, NULL, &tv); 
  }
  void Run(void){
    while(1){
      int ret=0; 
      switch((ret=Select())){
        case 0: 
          //printf("%s, %d: ret: %d, timeout!!\n", __FUNCTION__, __LINE__, ret);
	  //t.dump(1);
	  dump();
          break;
        case -1: 
          printf("%s, %d: ret: %d, error!!\n", __FUNCTION__, __LINE__, ret);
          break;
        default: 
          //printf("%s, %d: ret: %d\n", __FUNCTION__, __LINE__, ret);
          for(int i=0; i<=max; i++){
            if(Isset(i)){
              //printf("FD_ISSET: %d\n", i);
              if(i==0){ //stdin
  	        if((nbytes=read(i, recvbuf, sizeof(recvbuf)))<=0){
                  if(nbytes==0){
                    printf("read %d: hang up\n", i);
  		  }else{
                    printf("read %d: error!!\n", i);
  		  }
    	  	  close(i);
  		  Clr(i);
  	        }else{
                  printf("read: %d: %s\n", i, recvbuf);
  	        }
	      }else if(i==fd){ //new connection!!
                int newfd=0; 
                struct sockaddr_storage remoteaddr; // client address
                socklen_t addrlen;
	        t.dump();
                // handle new connections
                addrlen = sizeof remoteaddr;
                newfd = accept(fd,
                  (struct sockaddr *)&remoteaddr,
                  &addrlen);
	        if(newfd>max) max=newfd; 
		cli.push_back(new Client(newfd));
	        Set(newfd);
                cli_fd.push_back(newfd);
	      }else{  //recv
  	        if((nbytes=recv(i, recvbuf, sizeof(recvbuf), 0))<=0){
                  if(nbytes==0){
                    printf("read %d: hang up\n", i);
		    Close(i);
  		  }else{
                    printf("read %d: error!!\n", i);
  		  }
    	  	  close(i);
  		  Clr(i);
  	        }else{
                  printf("read: %d: %s\n", i, recvbuf);
  	        }
	      }
	    }
	  }
          break;
      }
      usleep(1000);
    }
  }
  void Close(int _fd){
    vector <Client *>::iterator it=find_if(cli.begin(),cli.end(),[=](Client *c)->bool{
      return (c->getfd()==_fd);
    });
    cout << "Close(" << (*it)->getfd() << ")" << endl; 
    (*it)->cancel(); 
    delete static_cast <Client *>(*it); 
    cli.erase(it);
  }
  char *cliAddr(int _fd) {
    struct sockaddr_in addr;
    socklen_t addr_size = sizeof(struct sockaddr_in);
    getpeername(_fd, (struct sockaddr *)&addr, &addr_size);
    char *clientip = new char[20];
    strcpy(clientip, inet_ntoa(addr.sin_addr));
    return clientip; 
  }
  void dump(void){
#if 0
    for(vector <int>::iterator it=cli_fd.begin(); it!=cli_fd.end(); it++){
    }
#endif
    for(vector <Client *>::iterator it=cli.begin(); it!=cli.end(); it++){
      cout << "clifd: " << (*it)->getfd() << endl; 
    }
  }
private:
  int fd; 
  vector <int>cli_fd; 
  vector <Client *>cli;
  int port; 
  struct sockaddr_in info;
  fd_set fds1;
  fd_set fds2;
  int max;
  ssize_t nbytes; 
  char recvbuf[128];
  timeval e;
  Timestamp t; 
};

void socketTest(void){
  Server s; 
  s.Run();
}
