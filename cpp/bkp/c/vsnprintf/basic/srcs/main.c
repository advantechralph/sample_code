#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int Report(const char *pcFormat, ...){
  int iRet = 0;
  char    *pcBuff;
  char    *pcTemp;
  int iSize = 256;
  va_list list;

  pcBuff = (char*)malloc(iSize);
  if(pcBuff == NULL)
  {
    return(-1);
  }
  while(1)
  {
    va_start(list,pcFormat);
    iRet = vsnprintf(pcBuff, iSize, pcFormat, list);
    va_end(list);
    if((iRet > -1) && (iRet < iSize))
    {
      break;
    }
    else
    {
      printf("%s, %d: iSize: %d\n", __FUNCTION__, __LINE__, iSize);
      iSize *= 2;
      printf("%s, %d: iSize: %d\n", __FUNCTION__, __LINE__, iSize);
      if((pcTemp = realloc(pcBuff, iSize)) == NULL)
      {
        printf("Could not reallocate memory\n\r");
        iRet = -1;
        break;
      }
      else
      {
        pcBuff = pcTemp;
      }
    }
  }
  printf("%s", pcBuff);
  free(pcBuff);
  return(iRet);
}

int main(void){
  Report("%s, %d: %-20s\n", __FUNCTION__, __LINE__, "test1");
  Report("%s, %d: %-256s\n", __FUNCTION__, __LINE__, "test2");
  return 0; 
}

