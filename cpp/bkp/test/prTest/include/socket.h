#ifndef __socket_h__
#define __socket_h__
#include "basic.h"
#include "args.h"
typedef enum FdType {
  File=0,
  Tcp=1,
  Udp=2,
  FdTypeEnd
} FdType;
typedef struct FD {
  int fd; 
  FdType type; 
} FD; 
class Sockets {
  int fd;
  vector<FD> svr;
  vector<FD> cli;
  vector<fd_set> rset; 
  int max;
  timeval tv; 
  Timestamp ts; 
public:
  Sockets(void){
    CLASSINFO
    max=-1; 
    tv.tv_sec=0; tv.tv_usec=0;
    ts.Dump();
    rset.resize(2);
    FD_ZERO(&rset[0]);
    FD_ZERO(&rset[1]);
    AddCli(0, File);
  }
  ~Sockets(void){
    CLASSINFO
  }
  vector<FD>::iterator SvrBegin(void){
    return svr.begin();
  }
  vector<FD>::iterator SvrEnd(void){
    return svr.end();
  }
  vector<FD>::iterator CliBegin(void){
    return cli.begin();
  }
  vector<FD>::iterator CliEnd(void){
    return cli.end();
  }
  virtual int Select(void){
    timeval _tv=tv;
    rset[1]=rset[0];
    //FUNCPRINTF("sec: %d, usec: %lu\n", (int)tv.tv_sec, tv.tv_usec);
    return select(max+1, &rset[1], NULL, NULL, (_tv.tv_sec==0&&_tv.tv_usec==0)?NULL:&_tv);
  }
  virtual void Add(int _fd, FdType _type){
    FD _id; 
    _id.fd=_fd; 
    _id.type=_type;
    svr.push_back(_id);
    Set(_fd);
    for(vector<FD>::iterator it=svr.begin();it!=svr.end();it++){
      if((*it).fd>max) max=(*it).fd; 
    }
  }
  virtual void Del(int _fd){
    close(_fd);
    Clr(_fd);
    for(vector<FD>::iterator it=svr.begin();it!=svr.end();){
      if((*it).fd==_fd)
        it=cli.erase(it);
      else it++;
    }
  }
  virtual void AddCli(int _fd, FdType _type){
    FD _id; 
    _id.fd=_fd; 
    _id.type=_type;
    cli.push_back(_id);
    Set(_fd);
    for(vector<FD>::iterator it=cli.begin();it!=cli.end();it++){
      if((*it).fd>max) max=(*it).fd; 
    }
  }
  virtual void DelCli(int _fd){
    close(_fd);
    Clr(_fd);
    for(vector<FD>::iterator it=cli.begin();it!=cli.end();){
      if((*it).fd==_fd)
        it=cli.erase(it);
      else it++;
    }
  }
  virtual void Set(int _fd){
    FD_SET(_fd, &rset[0]);
    rset[1]=rset[0];
  }
  virtual int Isset(int _fd){
    return FD_ISSET(_fd, &rset[1]);
  }
  virtual void Clr(int _fd){
    FD_CLR(_fd,&rset[0]);
    rset[1]=rset[0];
  }
  virtual void AddUDP(int _port){
    fd=socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in sin;
    int reuse=1;
    bzero(&sin,sizeof(sin));
    sin.sin_family=PF_INET;
    sin.sin_addr.s_addr=INADDR_ANY;
    sin.sin_port=htons(_port);
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int));
    bind(fd,(struct sockaddr *)&sin,sizeof(sin));
    Add(fd, Udp);
  }
  virtual void AddTCP(int _port){
    fd=socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sin;
    int reuse=1;
    bzero(&sin,sizeof(sin));
    sin.sin_family=PF_INET;
    sin.sin_addr.s_addr=INADDR_ANY;
    sin.sin_port=htons(_port);
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int));
    bind(fd,(struct sockaddr *)&sin,sizeof(sin));
    listen(fd, 5);
    Add(fd, Tcp);
  }
  virtual void parseArgs(char *_buf){
    Args a(_buf, " \t\n\0"); 
    //a.Info();
    if(a.argv[0]){
      if(!strcmp(a.argv[0], "timer")){
        cout << "timer command!!" << endl; 
      }else{
        cout << "Usage: timer ..." << endl; 
      }
    }
  }
  virtual void Run(int _port=8700){
    cout << "listen port " << _port << "..." << endl;
    AddTCP(_port);
    AddUDP(_port);
    Expire();
    while(1){
      switch(Select()){
        case 0:
          FUNCPRINTF("%s, %s\n", "timeout!!", ts.NowStr(1));
	  Info();
          break;
        case -1:
          FUNCPRINTF("%s, %s\n", "select error!!", ts.NowStr(1));
	  exit(-1);
          break;
	default:
#define MAXSOCKETREADBUFFERSIZE 128
          int nbytes=0; 
	  char _buf[MAXSOCKETREADBUFFERSIZE+1]={0};
	  int _ret=0; 
	  for(vector<FD>::iterator it=svr.begin();it!=svr.end();it++){
            if(Isset((*it).fd)){
              struct sockaddr_storage remoteaddr; // client address
              socklen_t addrlen;
              sockaddr_in sin;
	      if((*it).type==Tcp){
                int _fd=0;
		_fd=accept((*it).fd, (struct sockaddr *)&remoteaddr, &addrlen);
		AddCli(_fd, Tcp);
                memcpy(&sin, &remoteaddr, sizeof(sin));
		cout << "new client: " << inet_ntoa(sin.sin_addr) << ":" << sin.sin_port << endl; 
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
		parseArgs(_buf);
		break;
	      }
	    }
	  }
	  if(_ret) continue;
	  for(vector<FD>::iterator it=cli.begin();it!=cli.end();it++){
            if(Isset((*it).fd)){
              //cout << "Isset: " << (*it).fd << endl; 
	      if((*it).type==File){
                nbytes=read((*it).fd, _buf, MAXSOCKETREADBUFFERSIZE);
	      }
	      if((*it).type==Tcp){
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
		parseArgs(_buf);
	      }
	      break;
	    }
	  }
	  break;
      }
      fflush(stdout);
      usleep(1000);
    }
  }
  virtual void Expire(int _sec=2, int _usec=500000){
    tv.tv_sec=_sec; 
    tv.tv_usec=_usec;
  }
  virtual void Info(void){
    cout << "====================" << endl;
    cout << "Sockets Info.: " << endl; 
    cout << "  " << ts.NowStr() << endl;
    cout << "  max: " << max << endl;
    cout << "  rset size: " << rset.size() << endl; 
    cout << "  svr size: " << svr.size() << endl;
    for(vector<FD>::iterator it=svr.begin(); it!=svr.end(); it++){
      cout << "    svr(" << (it-svr.begin()) << "): " ;
      cout << "fd: " << (*it).fd << ", type: ";
      switch((int)(*it).type){
        case File:
          cout << "File";
          break;
	case Tcp:
          cout << "Tcp";
          break;
	case Udp:
          cout << "Udp";
          break;
      }
      cout << endl;
    }
    cout << "  cli size: " << cli.size() << endl;
    for(vector<FD>::iterator it=cli.begin(); it!=cli.end(); it++){
      cout << "    cli(" << (it-cli.begin()) << "): " ;
      cout << "fd: " << (*it).fd << ", type: ";
      switch((int)(*it).type){
        case File:
          cout << "File";
          break;
	case Tcp:
          cout << "Tcp";
          break;
	case Udp:
          cout << "Udp";
          break;
      }
      cout << endl;
    }
    cout << "  Expire: sec: " << tv.tv_sec << ", usec: " << tv.tv_usec << endl; 
    cout << "====================" << endl;
  }
};
#endif /*__socket_h__*/
