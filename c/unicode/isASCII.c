
#include "isASCII.h"

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

