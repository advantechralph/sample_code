#ifndef __timestamp_h__
#define __timestamp_h__
#include "basic.h"
class Timestamp {
  char str[128];
  unsigned long begin; 
  unsigned long end; 
  unsigned long diff;
public:
  Timestamp(){
    printf("Timestamp(%p): '%s'@%d\n", this, __FILENAME__, __LINE__);
    begin=0; end=0, diff=0;
    str[0]='\0';
  }
  ~Timestamp(){
    printf("~Timestamp(%p): '%s'@%d\n", this, __FILENAME__, __LINE__);
  }
  unsigned long Now(void){
    struct timeval now; 
    gettimeofday(&now, NULL);
    return now.tv_sec*1000000+now.tv_usec;
  }
  const char *NowStr(int mode=0){
    struct timeval now;
    gettimeofday(&now, NULL);
    struct tm *ptm=localtime(&now.tv_sec);
    string fmt("%04d-%02d-%02d %02d:%02d:%02d");
    fmt+=(mode?":%06ld":"%.ld");
    sprintf(str, fmt.c_str(), ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, mode?now.tv_usec:0);
    return str;
  }
  void Dump(int mode=2){
    if(mode==2){
      cout << "Now: " << Now() << endl; 
    }else{
      cout << "Now: " << NowStr(mode) << endl; 
    }
  }
  void DumpDiff(void){
    cout << "Diff: " << getDiff() << "(us)" << endl; 
  }
  void Begin(void){begin=Now(); }
  void End(void){end=Now(); diff=(end-begin); }
  unsigned long getBegin(void){return begin; }
  unsigned long getEnd(void){return end; }
  unsigned long getDiff(void){return diff; }
};
#endif /*__timestamp_h__*/
