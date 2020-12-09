#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int gLevel=0; 

#define TRACELOG "trace.log"
FILE *fp=NULL; 

typedef struct tracetab {
  void *ptr; 
  const char *name; 
} tracetab; 

tracetab functracetab[];

#define DUMP(func, call) \
        printf("%s: func = %p, called by = %p\n", __FUNCTION__, func, call)

void __attribute__((__no_instrument_function__))
__cyg_profile_func_enter(void *this_func, void *call_site){
  const char *this_name=NULL;
  for(tracetab *p=functracetab; p->ptr; p++){
    if((unsigned long long)p->ptr==(unsigned long long)this_func){
      this_name=p->name; 
    }
  }
  DUMP(this_func, call_site);
  if(!fp) fp=fopen(TRACELOG, "a+");
  for(int i=0; i<gLevel; i++){ 
    if(fp) fprintf(fp, "  "); 
  }
  if(fp) fprintf(fp, "%s%s%s", this_name?"Enter ":"", this_name?this_name:"", this_name?"\n":"");
  gLevel++; 
}

void __attribute__((__no_instrument_function__))
__cyg_profile_func_exit(void *this_func, void *call_site){
  const char *this_name=NULL;
  gLevel--; 
  for(tracetab *p=functracetab; p->ptr; p++){
    if((unsigned long long)p->ptr==(unsigned long long)this_func){
      this_name=p->name; 
    }
  }
  DUMP(this_func, call_site);
  if(!fp) fp=fopen(TRACELOG, "a+");
  for(int i=0; i<gLevel; i++){ 
    if(fp) fprintf(fp, "  "); 
  }
  if(fp) fprintf(fp, "%s%s%s", this_name?"Exit ":"", this_name?this_name:"", this_name?"\n":"");
  if(fp){ 
    fclose(fp);
    fp=NULL; 
  }
}

typedef struct functab {
  void (*func)(void);
} functab; 

void test(void){
  printf("  %s, %d: \n", __FUNCTION__, __LINE__);
}

functab testFuncTab[]={
  {test}, 
  {NULL}
};

int main(int argc, char *argv[]){
//  if(!access(TRACELOG, F_OK)) remove(TRACELOG);
  for(functab *p=testFuncTab; p->func; p++){
    p->func();
  }
  return 0; 
}

tracetab functracetab[]={
  {(void *)test, "test"}, 
  {(void *)main, "main"}, 
  {NULL, NULL}
}; 

