#ifndef __args_h__
#define __args_h__
#include "basic.h"
class Args {
public:
  char *argv[10];
  int argc;
  void Init(void){
    argc=0; 
    //memset(argv, 0, sizeof(argv));
    for(int _i=0; _i<(int)(sizeof(argv)/sizeof(char *)); _i++) argv[_i]=NULL;
  }
  Args(){
    Init();
  }
  Args(char *_s, const char *_sep){
    char *_token=NULL, *_save=NULL;
    Init();
    argc=0;
    for(char *p=_s;;p=NULL){
      _token=strtok_r(p, _sep, &_save);
      if(!_token) break;
      argv[argc]=_token;
      argc++;
    }
  }
  ~Args(){}
  void Info(void){
    for(int _i=0; _i<argc; _i++){
      cout << "argv[" << _i << "]: " << argv[_i] << endl; 
    }
  }
};
#endif /*__args_h__*/
