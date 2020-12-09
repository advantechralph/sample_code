#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct functab {
  void (*func)(void);
} functab; 

void fileappendtest(void){
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  FILE *fp=NULL; 
  fp=fopen("append.log", "a+");
  if(!fp) goto err; 
  fprintf(fp, "%s, %d: \n", __FUNCTION__, __LINE__);
err:
  if(fp) fclose(fp); 
}

void filereadtest1(void){
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  FILE *fp=NULL; 
  fp=fopen("append.log", "a");
  printf("%s, %d: ftell(fp): %ld\n", __FUNCTION__, __LINE__, ftell(fp));
  printf("%s, %d: fseek(fp, 0L, SEEK_SET): %d\n", __FUNCTION__, __LINE__, fseek(fp, 0L, SEEK_SET));
  printf("%s, %d: ftell(fp): %ld\n", __FUNCTION__, __LINE__, ftell(fp));
  printf("%s, %d: fseek(fp, 0L, SEEK_END): %d\n", __FUNCTION__, __LINE__, fseek(fp, 0L, SEEK_END));
  printf("%s, %d: ftell(fp): %ld\n", __FUNCTION__, __LINE__, ftell(fp));
  if(!fp) goto err; 
err:
  if(fp) fclose(fp); 
}

functab testFuncTab[]={
  {fileappendtest}, 
  {filereadtest1}, 
  {NULL}
};

int main(int argc, char *argv[]){
  for(functab *p=testFuncTab; p->func; p++){
    p->func();
  }
  return 0; 
}

