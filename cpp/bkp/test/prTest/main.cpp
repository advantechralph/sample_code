#include <iostream>
#include "main.h"
using namespace std;
Timestamp ts; 
Rand r; 
void loop(void){
  while(1){
//    FUNCPRINTF("%s\n", ts.NowStr());
    fflush(stdout);
    sleep(1);
  }
}
static int shmid=0; 
static key_t shmKey=7788; 
sem_t TimerTestSem; 
sem_t PoolDebugSem; 
sem_t ShmTestSem; 
sem_t VectorTestSem; 
void clearSem(sem_t *_sem){
  while(sem_trywait(_sem)){
    cout << "Semaphore is full you must wait!" << endl; 
  }
}
static pthread_mutex_t mutex;
typedef struct Data {
  unsigned long timestamp; 
  float temperature; 
} Data; 
Data *pDataPool=NULL; 
#define DataPoolSize 300
#define DataPoolMemSize (300*sizeof(Data))
static int TimerTestCount=0; 
#define TimerTestCountMax 10
void *TimerTestThread(void *data){
  clearSem(&TimerTestSem);
  pthread_detach(pthread_self());
  while(1){
    sem_wait(&TimerTestSem);
    pthread_mutex_lock(&mutex);
    if((TimerTestCount%TimerTestCountMax)==(TimerTestCountMax-1)){
      cout << "TimerTestThread: "; 
      ts.Dump(1);
      TimerTestCount=0; 
    }else{
      TimerTestCount++; 
    }
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}
static int PoolDebugCount=0; 
#define PoolDebugCountMax 10
void *PoolDebugThread(void *data){
  clearSem(&PoolDebugSem);
  pthread_detach(pthread_self());
  while(1){
    sem_wait(&PoolDebugSem);
    pthread_mutex_lock(&mutex);
    if((PoolDebugCount%PoolDebugCountMax)==(PoolDebugCountMax-1)){
      cout << "PoolDebugThread: "; 
      ts.Dump(1);
      PoolDebugCount=0; 
      for(int i=0; i< 10; i++){
        cout << "CH" << i << "(" << pDataPool[i].temperature; 
	cout << "," << pDataPool[i].timestamp << ") "; 
      }
      cout << endl; 
    }else{
      PoolDebugCount++; 
    }
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}
static int ShmTestCount=0; 
static unsigned long ShmAvg=0; 
#define ShmTestCountMax 10
void *ShmTestThread(void *data){
  clearSem(&ShmTestSem);
  pthread_detach(pthread_self());
  while(1){
    sem_wait(&ShmTestSem);
    ts.Begin();
    for(int i=0; i<DataPoolSize; i++){
      pDataPool[i].timestamp=ts.Now();
      pDataPool[i].temperature=r.Float(0, 100, 2);
    }
    ts.End();
    ShmAvg+=ts.getDiff();
    pthread_mutex_lock(&mutex);
    if((ShmTestCount%ShmTestCountMax)==(ShmTestCountMax-1)){
      cout << "ShmTestThread: "; 
      cout << "average: " << static_cast<float>(ShmAvg/ShmTestCount) << "(us) "; 
      ts.Dump(1);
      ShmTestCount=0; 
      ShmAvg=0; 
    }else{
      ShmTestCount++; 
    }
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}
static int VectorTestCount=0; 
static unsigned long VectorAvg=0; 
#define VectorTestCountMax 10
vector<Data> DataPoolVector[DataPoolSize]; 
void *VectorTestThread(void *data){
  clearSem(&VectorTestSem);
  pthread_detach(pthread_self());
  while(1){
    sem_wait(&VectorTestSem);
    ts.Begin();
    for(int i=0; i<DataPoolSize; i++){
      int size=DataPoolVector[i].size(); 
      if(size==0){
        DataPoolVector[i].push_back(pDataPool[i]);
      }else{
        vector<Data>::iterator end=DataPoolVector[i].end(); 
	if((*(end-1)).timestamp!=pDataPool[i].timestamp){
          cout << "channel: " << i << ": update!!" << endl; 
	  DataPoolVector[i].push_back(pDataPool[i]);
	}
      }
    }
    ts.End();
    VectorAvg+=ts.getDiff();
    pthread_mutex_lock(&mutex);
    if((VectorTestCount%VectorTestCountMax)==(VectorTestCountMax-1)){
      cout << "VectorTestThread: "; 
      cout << "average: " << static_cast<float>(VectorAvg/VectorTestCount) << "(us) "; 
      ts.Dump(1);
      VectorTestCount=0; 
      VectorAvg=0; 
      for(int i=0; i<DataPoolSize; i++){
        int size=DataPoolVector[i].size();
        if(size>1){
          cout << "channel: " << i << ": size=" << size << endl; 
	}
      }
    }else{
      VectorTestCount++; 
    }
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}
static int RTCount=0; 
#define RTCountMax 10
void RTFunc(int, siginfo_t*, void*){
  sem_post(&TimerTestSem);
  sem_post(&PoolDebugSem);
  sem_post(&ShmTestSem);
  sem_post(&VectorTestSem);
  if((RTCount%RTCountMax)==(RTCountMax-1)){
    //ts.Dump(1);
    RTCount=0; 
  }else{
    RTCount++; 
  }
}
void DataPoolInit(void){
  if(pDataPool){
    memset(pDataPool, 0, DataPoolMemSize);
  }
}
void SemInit(void){
  sem_init(&TimerTestSem, 0, 0);
  sem_init(&PoolDebugSem, 0, 0);
  sem_init(&ShmTestSem, 0, 0);
  sem_init(&VectorTestSem, 0, 0);
}
void MutexInit(void){
  pthread_mutex_init(&mutex, NULL);
}
void timerTest(int channel, char *action, char *data){
  DataPoolInit();
  MutexInit();
  Thread TimerTest("TimerTest", TimerTestThread, (void *)"TimerTestThread"); 
  Thread PoolDebug("PoolDebug", PoolDebugThread, (void *)"PoolDebugThread"); 
  if(action){
    if(!strcmp(action, "rand")){
      Thread ShmTest("ShmTest", ShmTestThread, (void *)"ShmTestThread"); 
    }
    if(!strcmp(action, "vector")){
      //Thread ShmTest("ShmTest", ShmTestThread, (void *)"ShmTestThread"); 
      Thread VectorTest("VectorTest", VectorTestThread, (void *)"VectorTestThread"); 
    }
  }
  Timer RT(SIGRTMIN, RTFunc, 0, 100000000); //100ms
}
void shmTest(int channel, char *action, char *data){
#if 0
  cout << __FUNCTION__ << "("; 
  cout << "channel="  << channel; 
  if(action) cout << ", action='"  << action << "'"; 
  if(data) cout << ", data='"  << data << "'"; 
  cout << ")" << endl; 
#endif
  if(action){
    if(!strcmp(action, "get")){
      cout << string(action) << " channel " << channel << ": ";  
      cout << "("  << pDataPool[channel].timestamp << ", " << pDataPool[channel].temperature << ")" << endl;
    }
    if(!strcmp(action, "set")){
      if(data){
        float temperature=0; 
	unsigned long timestamp=0; 
        sscanf(data, "%lu %f", &timestamp, &temperature);
        cout << string(action) << " channel " << channel << ": ";  
	cout << "("  << timestamp << ", " << temperature << ")" << endl;
	pDataPool[channel].temperature=temperature; 
	pDataPool[channel].timestamp=timestamp; 
      }
    }
    if(!strcmp(action, "init")){
      cout << "Data Pool Init!!" << endl;
      DataPoolInit();
    }
    if(!strcmp(action, "rand")){
      cout << string(action) << " channel " << channel << endl;  
      pDataPool[channel].temperature=r.Float(0,100, 2); 
      pDataPool[channel].timestamp=ts.Now(); 
    }
  }
}
class PRSockets:public Sockets {
  Timestamp ts; 
  int timer; 
public:
  virtual void parseArgs(char *_buf){
    Args a(_buf, " \t\n\0"); 
    //a.Info();
    if(a.argv[0]){
      if(!strcmp(a.argv[0], "timer")){
        if(!timer){
          Thread TimerTest("TimerTest", TimerTestThread, (void *)"TimerTestThread"); 
          timer=1;
	}
      }
    }
  }
  void initRun(void){
    cout << "listen port 5566..." << endl;
    AddTCP(5566);
    AddUDP(5566);
    Expire(0, 0);
    timer=0; 
  }
  virtual void Run(void){
    initRun();
    while(1){
      switch(Select()){
        case 0:
          FUNCPRINTF("%s, %s\n", "timeout!!", ts.NowStr(1));
	  Info();
          break;
        case -1:
          FUNCPRINTF("%s, %s\n", "select error!!", ts.NowStr(1));
	  exit(1);
          break;
	default:{
#define MAXSOCKETREADBUFFERSIZE 128
          int nbytes=0; 
	  char _buf[MAXSOCKETREADBUFFERSIZE+1]={0};
	  int _ret=0; 
	  for(vector<FD>::iterator it=SvrBegin();it!=SvrEnd();it++){
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
	  for(vector<FD>::iterator it=CliBegin();it!=CliEnd();it++){
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
	}break;
      }
      fflush(stdout);
      usleep(1000);
    }
  }
};
void *SocketsTestThread(void *data){
  PRSockets s; 
  pthread_detach(pthread_self());
  s.Run();
  pthread_exit(NULL);
}
void socketTest(void){
  DataPoolInit();
  MutexInit();
  Thread SocketsTest("SocketsTest", SocketsTestThread, (void *)"SocketsTestThread"); 
  Timer RT(SIGRTMIN, RTFunc, 0, 100000000); //100ms
  loop();
}
void usage(char *name){
  cout << "Usage: " << endl;
  cout << "  " << name << " --timer" << endl; 
  cout << "  " << name << " --timer --action rand" << endl; 
  cout << "  " << name << " --timer --action vector" << endl; 
  cout << "  " << name << " --shm --channel <0~299> --action <get|set|rand> --data <'timestamp temperature'> (--data only if action is set) " << endl; 
  cout << endl; 
}
void init(void){
#if 0
  pDataPool=(Data *)malloc(DataPoolMemSize);
#else
  if((shmid=shmget(shmKey, DataPoolMemSize, IPC_CREAT|0666))<0){
    perror("shmget");
    exit(1);
  }
  if((pDataPool=(Data *)shmat(shmid, NULL, 0))==NULL){
    perror("shmat");
    exit(1);
  }
#endif
  if(!pDataPool){
    perror("Data Pool error!!");
    exit(1);
  }
}
void deinit(void){
  shmdt(pDataPool);
  //shmctl(shmid , IPC_RMID , NULL);
}
int main(int argc, char *argv[]){
  int f=0, channel=0;
  char *p[3]={NULL, NULL, NULL}; 
  char *action=NULL; 
  char *data=NULL;
  while(1){
    int longindex=0; 
    char short_options[]="0:1:2:h?";
    struct option long_options[]={
      {"socket", 0, 0, 'S'},
      {"timer", 0, 0, 't'},
      {"shm", 0, 0, 's'},
      {"channel", 1, 0, 0},
      {"action", 1, 0, 0},
      {"data", 1, 0, 0},
      {"help", 0, 0, 'h'},
      {0, 0, 0, 0}
    };
    char c=getopt_long(argc, argv, short_options, long_options, &longindex);
    cout << "c(" << static_cast<int>(c) << ")=" << c ; 
    cout << ", longindex(" << longindex << ")"; 
    cout << endl; 
    if(c==-1) break;
    if(optarg) printf("optarg: %s\n", optarg);
    switch(c){
      case 0:
        if(!strcmp(long_options[longindex].name, "channel")){
          if(optarg) channel=atoi(optarg);
	}
        if(!strcmp(long_options[longindex].name, "action")){
          if(optarg) action=optarg; 
	}
        if(!strcmp(long_options[longindex].name, "data")){
          if(optarg) data=optarg; 
	}
        break;
      case '0':
      case '1':
      case '2':
        if(optarg) p[(c-0x30)]=optarg; 
        break;
      case 't':
      case 's':
      case 'S':
	f=c;
        break;
      case '?':
      case 'h':
	usage(argv[0]);
	exit(0);
        break;
      default:
        break;
    }
  }
  if(optind<argc){
    cout << "opt<argc" << endl; 
  }
  for(int i=0; i<3; i++){
    if(p[i]!=NULL){ 
      cout << "p[" << i << "]: " << static_cast<void *>(p[i]);
      cout << ", " << string(p[i]) << endl; 
    }
  }
  init();
  switch(f){
    case 't':
      timerTest(channel, action, data);
      loop();
      break;
    case 's':
      shmTest(channel, action, data);
      break;
    case 'S':
      socketTest();
      break;
    default:
      timerTest(channel, (char *)"rand", data);
      loop();
      break;
  }
  deinit();
  return 0; 
}

