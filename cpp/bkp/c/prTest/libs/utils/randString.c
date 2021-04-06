#include "utils.h"
char *randString(char *str, size_t size){
  const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  struct timeval now; 
  gettimeofday(&now, NULL);
  srand(now.tv_usec); 
  if(size){
    --size;
    for(size_t n=0;n<size;n++){
      int key=rand()%(int)(sizeof(charset)-1);
      str[n]=charset[key];
    }
    str[size]='\0';
  }
  return str;
}

char* randStringAlloc(size_t size){
  char *s=malloc(size+1);
   if(s){
     randString(s, size);
   }
   return s;
}

