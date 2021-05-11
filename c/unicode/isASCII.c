
#include "isASCII.h"

#if 0
int isASCII(const char *data, size_t size)
{
    const unsigned char *str = (const unsigned char*)data;
    const unsigned char *end = str + size;
    for (; str != end; str++) {
        if (*str & 0x80)
            return 0;
    }
    return 1;
}
#else
int isASCII(const char *data, size_t size)
{
    int  i;
    for(i=0; i<size; i++){
        if(data[i]<0x20||data[i]>0x7E){
            return 0; 
        }
    }
    return 1;
}
#endif

