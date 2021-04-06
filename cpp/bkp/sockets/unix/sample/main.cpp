#include "basic.h"
#include "args.h"
#include "timestamp.h"
#include "thread.h"
#include "socket.h"
#include "timer.h"
using namespace std;
class SvrThread:public Args, public Timestamp, public Socket, public Timer, public Thread{
public:
  SvrThread():Socket(), Timer(SIGRTMIN, TimerCb, 10, 0), Thread(ThreadCb,(void *)this){}
  static void *ThreadCb(void*);
  static void TimerCb(int, siginfo_t*, void*);
  void Info(void){
    cout << "SvrThread Info: " << endl; 
    cout << " Time:" << NowStr() << endl; 
  }
  void Main(int); 
}; 
void SvrThread::TimerCb(int, siginfo_t*, void*){
  cout << "SvrThread::TimerCb..." << endl;  
}
void SvrThread::Main(int _port=8700){
  cout << "listen port " << _port << "..." << endl;
  AddTCP(_port);
  AddUDP(_port);
  AddUnix("./unix");
  Expire(5,0);
  while(1){
    switch(Select()){
      case 0:
        FUNCPRINTF("%s, %s\n", "timeout!!", NowStr(1));
	((Socket *)this)->Info();
        break;
      case -1:
        FUNCPRINTF("%s, %s\n", "select error!!", NowStr(1));
	exit(-1);
        break;
      default:{
#define MAXSOCKETREADBUFFERSIZE 128
        int nbytes=0; 
        char _buf[MAXSOCKETREADBUFFERSIZE+1]={0};
        int _ret=0; 
        for(vector<FD>::iterator it=SvrBegin();it!=SvrEnd();it++){
          if(Isset((*it).fd)){
            if((*it).type==Tcp){
              //struct sockaddr_storage remoteaddr; // client address
              struct sockaddr_in remoteaddr;
              socklen_t addrlen=sizeof(remoteaddr);
              sockaddr_in sin;
              int _fd=0;
              _fd=accept((*it).fd, (struct sockaddr *)&remoteaddr, &addrlen);
              AddCli(_fd, Tcp);
              memcpy(&sin, &remoteaddr, sizeof(sin));
              cout << "new TCP client: " << inet_ntoa(sin.sin_addr) << ":" << sin.sin_port << endl; 
	      _ret=1; 
	      break;
  	    }
            if((*it).type==Unix){
              struct sockaddr_un remoteaddr;
              socklen_t addrlen=sizeof(remoteaddr);
              int _fd=0;
              _fd=accept((*it).fd, (struct sockaddr *)&remoteaddr, &addrlen);
              AddCli(_fd, Unix);
	      cout << "new Unix client: " << endl; 
              //memcpy(&sun, &remoteaddr, sizeof(sun));
              //cout << "new client: " << inet_ntoa(sin.sin_addr) << ":" << sin.sin_port << endl; 
	      _ret=1; 
	      break;
  	    }
	    if((*it).type==Udp){
	      socklen_t _len;
	      struct sockaddr_storage _addr;
	      nbytes=recvfrom((*it).fd, _buf, MAXSOCKETREADBUFFERSIZE, 0, (sockaddr*)&_addr, &_len);
	      _buf[nbytes]='\0';
	      cout << "fd(" << (*it).fd << "): ";
	      cout << "read/recv msg: " << _buf;
	      _ret=1; 
	      Parse(_buf);
	      ((Args *)this)->Info();
	      break;
	    }
	  }
        }
        if(_ret) continue;
        for(vector<FD>::iterator it=CliBegin();it!=CliEnd();it++){
          if(Isset((*it).fd)){
            //cout << "Isset: " << (*it).fd << endl; 
            if((*it).type==File){
              nbytes=read((*it).fd, _buf, MAXSOCKETREADBUFFERSIZE);
            }
            if((*it).type==Tcp){
              nbytes=recv((*it).fd, _buf, MAXSOCKETREADBUFFERSIZE, 0);
            }
            if((*it).type==Unix){
              nbytes=recv((*it).fd, _buf, MAXSOCKETREADBUFFERSIZE, 0);
            }
            cout << "fd(" << (*it).fd << "): ";
            int _num=0;
            ioctl((*it).fd, FIONREAD, &_num);
            if(_num>0){
              cout << _num << " bytes need to read..."; 
            }
            if(nbytes<=0){
              if(nbytes==0){
                cout << "hang up!!" << endl;
              }else{
                cout << "recv error!!" << endl;
              }
              DelCli((*it).fd);
            }else{
              _buf[nbytes]='\0';
              cout << "read/recv msg: " << _buf;
	      Parse(_buf);
	      ((Args *)this)->Info();
            }
            break;
          }
        }
      }break; //default: 
    }
    fflush(stdout);
    usleep(1000);
  }
}
void *SvrThread::ThreadCb(void *_D){
  pthread_detach(pthread_self());
  ((SvrThread *)_D)->Main();
  pthread_exit(NULL);
}
int main(int argc, char *argv[]){
  SvrThread sT; 
  while(1){
    sleep(1);
  }
  return 0; 
}

