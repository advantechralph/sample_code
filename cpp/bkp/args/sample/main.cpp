#include "main.h"
#define ArgsArgvMaxSize 20
class Args {
public:
  static char *argv[]; 
  static int argc;
  string str; 
  string sep; 
  void Init(const char *_str=NULL){
    for(int i=0; i<ArgsArgvMaxSize; i++) argv[i]=NULL; 
    argc=0; 
    sep=string(" \t\n\0");
    str=string(_str==NULL?"":_str);
  }
  Args(){
    cout << "Args()" << endl; 
    Init();
  };
  Args(const char *_str){
    cout << "Args('" << _str << "')" << endl; 
    Parse((char *)_str);
  }
  ~Args(){
  };
  void Parse(char *_str){
    char *saveptr=NULL; 
    Init(_str);
    for(char *p=(char *)str.c_str();;p=NULL){
      char *token=strtok_r(p, sep.c_str(), &saveptr);
      if(!token) break; 
      argv[argc++]=token; 
    }
  }
  void Info(void){
    cout << "Info()" << endl; 
    cout << " Args:" << endl; 
    cout << "  argc: " << argc << endl;
    for(int i=0; i<argc; i++){
      cout << "  argv[" << i << "]: " << argv[i] << endl; 
    }
  }
}; 
char *Args::argv[ArgsArgvMaxSize]={0}; 
int Args::argc=0; 
class Opts:public Args {
public:
  Opts(){
    cout << "Opts()" << endl; 
  };
  Opts(const char* _str):Args(_str){
    cout << "Opts('" << _str << "')" << endl; 
    Info();
    if(argc>0) cout << "argv[0]: " << argv[0] << endl;
    Parse();
  };
  ~Opts(){};
  static void Parse(void);
  static char short_options[];
  static struct option long_options[]; 
}; 
void usage(char *name){
  cout << "Usage: " << name << endl;
  cout << "  -c <value>" << endl; 
  cout << "  -v" << endl; 
  cout << "  --create <value>" << endl; 
  cout << "  --add <value>" << endl; 
}
char Opts::short_options[]="c:v"; 
struct option Opts::long_options[]={
  {"create", 1, 0, 'C'},
  {"add", 1, 0, 0},
  {0, 0, 0, 0}
};
void Opts::Parse(void){
  while(1){
    char c=0; 
    int option_index=0; 
    c=getopt_long(argc, argv, (const char *)short_options, (const struct option*) long_options, &option_index);
    cout << "c('" << static_cast<char>(c) << "'," << static_cast<int>(c) << ")" << endl;  
    if(c==-1) break; 
    if(c==0){
      cout << long_options[option_index].name; 
      if(optarg){
        cout << "=\"" << optarg<< "\"";
      }
      cout << endl; 
    }
    switch(c){
      case 0:
        break;
      case 'c':
	if(optarg){
	}
        break;
      case 'C':
	if(optarg){
	}
        break;
      case '?':
	usage(argv[0]);
        break;
      default: 
	cout << "default" << endl; 
        break;
    }
  }
  cout << "optind=" << optind << endl; 
  if(optind<argc){
    cout << "unknown argv:"; 
    while(optind<argc){
      cout << " " << argv[optind++]; 
    }
    cout << endl; 
  }
};
int main(int argc, char *argv[]){
  if(argv[1]){
    Args a(argv[1]);
    a.Info();
    if(a.argc>0){
      cout << "argv[0]: " << a.argv[0] << endl; 
    }
    Opts o(argv[1]);
  }
  return 0; 
}
