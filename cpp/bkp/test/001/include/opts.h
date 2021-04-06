#ifndef __opts_h__
#define __opts_h__
#include "basic.h"
class Opts {
public:
  Opts(){
    //printf("Opts(%p)\n", this);
    cout << "Opts(" << static_cast<void *>(this)<< ")" << endl;
  }
  Opts(const char *_s){
    //printf("Opts(%p)\n", this);
    cout << "Opts(" << static_cast<void *>(this)<< ")" << endl;
    struct option _long_options[]={
      {"add", 1, 0, 0},
      {"append", 0, 0, 'p'},
      {"create", 1, 0, 'c'},
      {"delete", 0, 0, 0},
      {"verbose", 0, 0, 'v'},
      {"test", 1, 0, 0},
      {0, 0, 0, 0}
    };
    Init(_s, "a:t", _long_options);
  }
  Opts(const char *_s, const char *_short_options, const struct option *_long_options){
    Init(_s, _short_options, _long_options);
  }
  void Init(const char *_s, const char *_short_options, const struct option *_long_options){
    //printf("Opts(%p)\n", this);
    cout << "Opts(" << static_cast<void *>(this)<< ")" << endl;
    cout << _s << endl;
    s=string(_s); 
    int _len=strlen(_short_options);
    short_options=(char *)malloc(_len+1);
    strcpy((char *)short_options, (char *)_short_options);
    short_options[_len]='\0';
    struct option *_p=NULL; 
    int _size=0;
    for(_p=(struct option*)_long_options; _p->name; _p++){
      _size++;
    }
    _size++;
    long_options=(struct option *)malloc(_size*sizeof(struct option));
    memcpy(long_options, _long_options, _size*sizeof(struct option));
    Args();
  }
  ~Opts(){
    cout << "~Opts(" << static_cast<void *>(this)<< ")" << endl;
  }
  void Args(void){
    char *saveptr=NULL;
    argc=0; 
    memset(argv, 0, sizeof(argv));
    for(char *p=(char *)s.c_str();;p=NULL){
      char *q=strtok_r(p, " \t", &saveptr);
      if(!q) break;
      argv[argc]=q;
      argc++;
    }
  }
  virtual void Usage(void){
    printf("Usage: \n");
  }
  virtual void Parse(void){
    while(1){
      char c=0; 
      int option_index=0;
#if 0
      struct option long_options[]={
        {"add", 1, 0, 0},
        {"append", 0, 0, 'p'},
        {"create", 1, 0, 'c'},
        {"delete", 0, 0, 0},
        {"verbose", 0, 0, 'v'},
        {"test", 1, 0, 0},
        {0, 0, 0, 0}
      };
      c=getParse(argc, argv, "a:", long_options, &option_index);
#else
      c=getopt_long(argc, argv, short_options, long_options, &option_index);
#endif
      if(c==-1) break;
      //printf("c='%c', optarg='%s', option_index: %d\n", (c?c:' '), (optarg?optarg:""), option_index);
      switch(c){
        case 0:
          printf("case 0: %s, optarg: '%s'\n", long_options[option_index].name, (optarg?optarg:""));
          break;
        case 'a':
	  printf("case 'a': optarg: '%s'\n", (optarg?optarg:""));
          break;
	case '?':
	  Usage();
	  return; 
          break;
	default:
	  printf("default case: '%c', optarg='%s'\n", c, (optarg?optarg:""));
	  break;
      }
    }
    if(optind<argc){
      while(optind<argc){
        printf("unknown argv: %s\n", argv[optind++]);
      }
      //Dump();
    }
  }
  virtual void Dump(void){
#if 0
    cout << "s(" << static_cast<void *>((void *)s.c_str()) << ")";
    cout << ": '" << s << "'" << endl; 
    cout << "s.size(): " << s.size() << endl; 
#endif
    for(int i=0; i<argc; i++){
      if(!argv[i]) continue; 
      cout << "argv[" << i << "]";
      cout << "(" << static_cast<void *>(argv[i]) << ")"; 
      cout << "=" << string(argv[i]) << endl; 
    }
  }
private:
  string s;
  int argc;
  char *argv[20];
  char *short_options; 
  struct option *long_options; 
};
#endif /*__opts_h__*/
