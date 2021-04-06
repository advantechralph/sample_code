#include "main.h"
using namespace std;
#define LogFile "log.run"
#if 0
void socketTest(void);

class st {
  fd_set fds;
  int max;
  timeval tv;
  char buf[128];
public:
  st(){
    printf("st(%p): construct\n", this);
    zero();
    set(0);
    max=1;
    expire(2, 500000);
  }
  ~st(){
    printf("st(%p): destruct\n", this);
  }
  void zero(void){FD_ZERO(&fds);}
  void set(int _fd){FD_SET(_fd, &fds);}
  int isset(int _fd){return FD_ISSET(_fd, &fds);}
  void expire(int _sec, unsigned long _usec){
    tv.tv_sec=_sec; 
    tv.tv_usec=_usec; 
  }
  void testcmd(int _argc, char *_argv[]){
    int c;
    int digit_optind = 0;
    while(1){
      int this_option_optind = optind ? optind : 1;
      int option_index = 0;
      static struct option long_options[] = {
        {"add",     required_argument, 0, 'a'},
        {"append",  no_argument,       0,  0 },
        {"delete",  required_argument, 0, 'd'},
        {"verbose", no_argument,       0, 'v'},
        {"create",  required_argument, 0, 'c'},
        {"file",    required_argument, 0, 'f'},
        {0,         0,                 0,  0 }
      };
      c = getopt_long(_argc, _argv, "abc:d:012",
        long_options, &option_index);
      //printf("c='%c'\n", c);
      if (c == -1)
        break;
      switch (c) {
        case 0:
          printf("option %s", long_options[option_index].name);
          if (optarg)
            printf(" with arg %s", optarg);
          printf("\n");
          break;
        case '0':
        case '1':
        case '2':
          if (digit_optind != 0 && digit_optind != this_option_optind)
            printf("digits occur in two different argv-elements.\n");
          digit_optind = this_option_optind;
          printf("option %c\n", c);
          break;
        case 'a':
          printf("option a\n");
          break;
        case 'b':
          printf("option b\n");
          break;
        case 'c':
          printf("option c with value '%s'\n", optarg);
          break;
        case 'd':
          printf("option d with value '%s'\n", optarg);
          break;
        case '?':
          break;
        default:
          printf("?? getopt returned character code 0%o ??\n", c);
      }
    }
#if 0
    if (optind < _argc) {
      printf("non-option ARGV-elements: ");
      while (optind < _argc){
        printf("%s ", _argv[optind++]);
      }
      printf("\n");
    }
#endif
  }
  void parse(void){
    char *_argv[10];
    int _argc=0; 
    memset(_argv, 0, sizeof(_argv));
    //for(int i=0; i<10; i++) _argv[i]=NULL;
    for(char *p=buf; ;p=NULL){
      char *q=strtok(p, " \t");
      if(!q) break; 
      _argv[_argc]=q; 
      _argc++; 
    }
    if(_argc>0&&!strcmp(_argv[0], "test")){
      testcmd(_argc, _argv);
    }
  }
  void run(void){
    while(1){
      int ret=0; 
      expire(2, 500000);
      set(0);
      switch(ret=select(max, &fds, NULL, NULL, &tv)){
        case 0:
          //printf("select: expired!!\n");
          break;
        case -1:
          break;
        default:
	  //printf("select: ret: %d\n", ret);
	  for(int i=0; i<max; i++){
            if(isset(i)){
              if(i==0){ //stdin
                ssize_t len=0; 
		if((len=read(i, buf, sizeof(buf)-1))<=0){
		  if(len==0){
                    printf("read: hang up!!\n");
                  }else{
                    printf("read: error!!\n");
		  }
		}else{
		  buf[len]='\0';
                  printf("buf: %s\n", buf);
		  parse();
		}
	      }
	    }
	  }
          break;
      }
    }
  }
}; 
#endif

class opts {
public:
  opts(){
    //printf("opts(%p)\n", this);
    cout << "opts(" << static_cast<void *>(this)<< ")" << endl;
  }
  opts(const char *_s){
    //printf("opts(%p)\n", this);
    cout << "opts(" << static_cast<void *>(this)<< ")" << endl;
    s=string(_s); 
  }
  ~opts(){
    cout << "~opts(" << static_cast<void *>(this)<< ")" << endl;
  }
  void parse(void){
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
  void usage(void){
    printf("usage: \n");
  }
  void opt_long(void){
    while(1){
      char c=0; 
      int option_index=0;
      static struct option long_options[]={
        {"add", 1, 0, 0},
        {"append", 0, 0, 'p'},
        {"create", 1, 0, 'c'},
        {"delete", 0, 0, 0},
        {"verbose", 0, 0, 'v'},
        {"test", 1, 0, 0},
        {0, 0, 0, 0}
      };
      c=getopt_long(argc, argv, "a:", long_options, &option_index);
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
	  usage();
	  return; 
          break;
	default:
	  printf("default case: c='%c'\n", c);
	  break;
      }
    }
    if(optind<argc){
      while(optind<argc){
        printf("unknown argv: %s\n", argv[optind++]);
      }
      //dump();
    }
  }
  void dump(void){
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
};

int main(int argc, char *argv[]) {
  opts o1((const char *)(argv[1]?argv[1]:"")); 
  o1.parse();
  o1.dump();
  o1.opt_long();
#if 0
  if(argc>1){
    remove(LogFile);
    int fd=open(LogFile, O_RDWR|O_CREAT, 0666);
    dup2(fd, STDOUT_FILENO);
    close(fd);
  }
  st s1=st();
  s1.run();
  while(1){
    fflush(stdout);
    sleep(1);
  }
#endif
  return 0; 
}
