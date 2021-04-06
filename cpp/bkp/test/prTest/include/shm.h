#ifndef __shm_h__
#define __shm_h__
#include "basic.h"
class Shm {
  key_t key; 
  int id; 
  void *data; 
  int size; 
public:
  void Init(key_t _k, size_t _s){
    key=_k; 
    size=_s; 
    id=shmget(_k, _s, IPC_CREAT | 0666);
    if(id<0){
      perror("shmget");
      exit(1);
    }
  }
  void Attach(void){ data=shmat(id, NULL, 0); }
  void *Data(void){return data; }
  void Detach(void){shmdt(data);}
  void Remove(void){shmctl(id, IPC_RMID, NULL);}
  Shm(key_t _k=7788, size_t _s=30){
    Init(_k, _s);
  }
}; 
#endif /*__shm_h__*/
